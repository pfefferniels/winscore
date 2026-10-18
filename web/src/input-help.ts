// Contextual help for the five-pass input: what the text before the caret
// means so far and which keys can follow, after Smith's "Computer Keyboard
// Input". The help only reads the text; score-input decides what is valid.

export interface Hint {
  /** Keys as shown, each in its own key cap, e.g. ['S', 'F', 'N']. */
  keys: string[];
  text: string;
}

export interface Help {
  title: string;
  detail?: string;
  hints: Hint[];
}

/** What the preview knows about the line, for counting notes and values. */
export interface Facts {
  /** Notes and chords, as passes 3-5 number them. */
  notes: number;
  /** Notes, chords and rests that take a value in pass 2 (-1 unknown). */
  needed: number;
  /** Values pass 2 gives: -1 when one value sets all of them, -2 unknown. */
  given: number;
}

const hint = (keys: string | string[], text: string): Hint => ({ keys: typeof keys === 'string' ? [keys] : keys, text });

const NEXT_ITEM = hint('/', 'next item');
const PASS_NAMES = ['notes', 'rhythms', 'marks', 'beams', 'slurs'];
const finishPass = (pass: number): Hint => hint('↵', pass < 5 ? `${PASS_NAMES[pass]} (pass ${pass + 1})` : 'insert the line');

/** The item the caret is in, up to the caret: after the last separator, upper-cased, leading spaces dropped. */
function currentItem(text: string, caret: number, separators = /[/,]/): { item: string; before: string; ended: boolean } {
  const before = text.slice(0, caret).toUpperCase();
  let start = 0;
  for (let i = before.length - 1; i >= 0; i--) {
    if (separators.test(before[i]!)) {
      start = i + 1;
      break;
    }
  }
  return { item: before.slice(start).replace(/^\s+/, ''), before, ended: before.includes(';') };
}

function ordinal(n: number): string {
  return `${n}${n % 10 === 1 && n % 100 !== 11 ? 'st' : n % 10 === 2 && n % 100 !== 12 ? 'nd' : n % 10 === 3 && n % 100 !== 13 ? 'rd' : 'th'}`;
}

// ---- pass 1: notes ---------------------------------------------------------

const ACCIDENTALS: Record<string, string> = { F: 'flat', S: 'sharp', N: 'natural', FF: 'double flat', SS: 'double sharp', NN: 'quarter-tone flat' };
const CLEFS: Record<string, string> = { TR: 'treble clef', BA: 'bass clef', AL: 'alto clef', TE: 'tenor clef', PR: 'percussion clef' };
const BAR_LETTERS: Record<string, string> = { D: 'double', M: 'double', H: 'heavy', L: 'start repeat', R: 'end repeat', S: 'dashed', I: 'invisible' };

const START_HINTS: Hint[] = [
  hint(['A', '…', 'G'], 'note (C4 = middle C)'),
  hint('R', 'rest'),
  hint('M', 'barline'),
  hint(['TR', 'BA', 'AL', 'TE'], 'clef'),
  hint('K', 'key signature, e.g. K2S, K3F'),
  hint(['3 4', 'COM', 'CUT'], 'meter'),
  hint(['SU', 'SD', 'SO'], 'stems up, down, normal'),
  hint(['S+', 'S-', 'S0'], 'notes on the staff above, below, back'),
  hint(['P', 'O'], 'nearest octave (proximity) / plain octaves'),
  hint('.', 'repeat the chord before last'),
  hint('X 2 3', 'repeat the last 2 items, 3 copies in all'),
  hint(['Z[', '@Z'], 'store a motive as Z, recall it'),
];

interface NoteState {
  letter: string;
  accidental: string;
  cautionary: boolean;
  octave: string;
  dyad: string;
  jumps: string;
  repeat: boolean;
  /** Repeated note letters, each a quarter tone up (BB = B quarter-sharp). */
  repeats: number;
}

/** Reads a note as the engine's suffix loop does; null if the text is not a note. */
function readNote(text: string): NoteState | null {
  const m = /^[OP]?([A-G])(.*)$/.exec(text.replace(/\s+/g, ''));
  if (!m) return null;
  const letter = m[1]!;
  const state: NoteState = { letter, accidental: '', cautionary: false, octave: '', dyad: '', jumps: '', repeat: false, repeats: 0 };
  let rest = m[2]!;
  while (rest.startsWith(letter)) {
    state.repeats++;
    rest = rest.slice(1);
  }
  for (const c of rest) {
    if (state.repeat) {
      if (!/\d/.test(c)) return null;
    } else if (c === '(') state.cautionary = true;
    else if ('FSN'.includes(c) && !state.octave && !state.dyad && state.accidental.length < 2) state.accidental += c;
    else if (/\d/.test(c)) state.octave = c;
    else if (c === '+' || c === '-' || c === '.' || c === '=') state.dyad = c === '-' ? '-' : '+';
    else if (c === 'U' || c === 'J') state.jumps += c;
    else if (c === 'X' || c === 'Z') state.repeat = true;
    else return null;
  }
  return state;
}

function noteTitle(n: NoteState): string {
  const accidental = ACCIDENTALS[n.accidental];
  const parts = [`Note ${n.letter}`];
  if (accidental) parts.push(n.cautionary ? `(${accidental}, in parentheses)` : accidental);
  else if (n.cautionary) parts.push('(cautionary accidental to follow)');
  if (n.repeats > 0) parts.push(`${n.repeats} quarter tone${n.repeats > 1 ? 's' : ''} up`);
  if (n.octave) parts.push(`octave ${n.octave}`);
  if (n.jumps) parts.push(n.jumps.split('').map((j) => (j === 'U' ? 'up' : 'down')).join(', '));
  if (n.dyad) parts.push(`with the octave ${n.dyad === '+' ? 'above' : 'below'}`);
  return parts.join(' · ');
}

function noteHelp(n: NoteState, inChord: boolean): Help {
  const hints: Hint[] = [];
  if (n.repeat) {
    return { title: `${noteTitle(n)} · repeated`, detail: 'X3 makes 3 copies in all; Z3 keeps the accidentals.', hints: [hint(['1', '…', '9'], 'number of copies'), NEXT_ITEM] };
  }
  const beforeOctave = !n.octave && !n.dyad;
  if (beforeOctave) hints.push(hint(['1', '…', '8'], 'octave (4 = middle C, carries on)'));
  if (beforeOctave && !n.accidental) {
    hints.push(hint(['S', 'F', 'N'], 'sharp, flat, natural'));
    hints.push(hint(['SS', 'FF'], 'double sharp, double flat'));
    if (!n.cautionary) hints.push(hint('(', 'accidental in parentheses'));
  } else if (beforeOctave && n.accidental.length === 1 && n.accidental !== 'N') {
    hints.push(hint(n.accidental, `double ${ACCIDENTALS[n.accidental]}`));
  }
  if (n.letter === 'C' && !n.accidental && !n.octave && n.jumps === 'U' && !n.dyad) hints.push(hint('T', 'CUT: cut time'));
  hints.push(hint(['U', 'J'], 'an octave up / down from the last note'));
  if (!n.dyad) hints.push(hint(['+', '-'], 'add the octave above / below'));
  hints.push(hint(':', inChord ? 'another chord note' : 'make a chord: next note'));
  hints.push(hint('X3', 'three of this note'));
  hints.push(NEXT_ITEM);
  const detail = n.octave || n.jumps
    ? undefined
    : inChord
      ? 'Without a number the note takes the octave of the note before.'
      : 'Without a number the note keeps the octave of the last note (P before the letter takes the nearest one).';
  return { title: noteTitle(n), detail, hints };
}

function restHelp(item: string): Help {
  const rest = item.slice(1).trim();
  if (rest === '') {
    return {
      title: 'Rest',
      detail: 'Its length comes in pass 2.',
      hints: [
        NEXT_ITEM,
        hint(['U', 'D'], 'above / below the middle'),
        hint('W', 'whole-measure rest symbol'),
        hint('I', 'invisible rest'),
        hint('F', 'with a fermata'),
        hint('P', 'measure-repeat sign'),
        hint(['1', '…', '9'], 'rest over that many measures'),
        hint('X3', 'three rests'),
      ],
    };
  }
  if (/^EP?/.test(rest)) return { title: 'REP n m: repeat items', detail: 'The last n items, m copies in all.', hints: [hint('P', 'REP'), hint('2 3', 'n and m'), NEXT_ITEM] };
  if (/^\d/.test(rest)) return { title: `Rest of ${parseInt(rest, 10)} measure${parseInt(rest, 10) === 1 ? '' : 's'}`, detail: 'Centred in its measure, the number above it.', hints: [hint(['0', '…', '9'], 'more digits'), NEXT_ITEM] };
  const kinds: Record<string, string> = { U: 'Rest above the middle', D: 'Rest below the middle', W: 'Whole-measure rest', I: 'Invisible rest', F: 'Rest with fermata', P: 'Measure-repeat sign' };
  const title = kinds[rest[0]!] ?? 'Rest';
  const hints: Hint[] = [];
  if (rest.length === 1 && (rest === 'W' || rest === 'F')) hints.push(hint(['U', 'D'], 'above / below'));
  hints.push(hint('X3', 'three of them'), NEXT_ITEM);
  return { title, hints };
}

function barHelp(item: string): Help {
  const letters = item.slice(1).replace(/\s+/g, '');
  const span = /\d+/.exec(letters)?.[0];
  const style = [...letters.replace(/\d.*/, '')].map((c) => BAR_LETTERS[c]).filter(Boolean);
  const kind = letters.startsWith('DD') || letters.startsWith('MM') ? 'heavy' : style.at(-1);
  const title = `${kind ? `${kind[0]!.toUpperCase()}${kind.slice(1)} barline` : 'Barline'}${span ? ` over ${span} staves` : ''}`;
  if (span) return { title, hints: [NEXT_ITEM] };
  return {
    title,
    detail: 'A number of staves carries on to the following barlines.',
    hints: [
      ...(style.length === 0
        ? [hint('D', 'double'), hint('H', 'heavy'), hint('L', 'start repeat'), hint('R', 'end repeat'), hint('S', 'dashed'), hint('I', 'invisible')]
        : []),
      hint(['1', '…', '9'], 'staves it reaches up'),
      NEXT_ITEM,
    ],
  };
}

function keyHelp(item: string): Help {
  const m = /^K\s*(\d*)\s*([SF]?)\s*(N?)/.exec(item);
  const [, count = '', kind = '', naturals = ''] = m ?? [];
  if (!count) return { title: 'Key signature', detail: 'K2S is two sharps, K3F three flats.', hints: [hint(['1', '…', '7'], 'number of sharps or flats')] };
  if (!kind) return { title: `Key signature, ${count} accidental${count === '1' ? '' : 's'}`, hints: [hint('S', 'sharps'), hint('F', 'flats')] };
  const what = `${count} ${kind === 'S' ? 'sharp' : 'flat'}${count === '1' ? '' : 's'}`;
  if (naturals) return { title: `Key signature: ${what} cancelled by naturals`, hints: [NEXT_ITEM] };
  return { title: `Key signature: ${what}`, hints: [hint('N', 'naturals that cancel it'), NEXT_ITEM] };
}

function meterHelp(item: string): Help {
  const [top = '', bottom] = item.trimStart().split(/\s+/);
  if (bottom === undefined) {
    return { title: `Meter ${top}/…`, detail: 'Upper and lower number with a space between: 3 4, 6 8.', hints: [hint('␣', 'then the lower number'), hint(['0', '…', '9'], 'more digits')] };
  }
  return { title: `Meter ${top}/${bottom || '…'}`, hints: bottom ? [NEXT_ITEM] : [hint(['2', '4', '8'], 'lower number')] };
}

/** Help in pass 1 for the item at the caret. */
function notesHelp(text: string, caret: number): Help {
  const { item: whole, before, ended } = currentItem(text, caret);
  if (ended) return { title: 'End of the notes', detail: 'Nothing after the ; is read.', hints: [finishPass(1)] };
  const defining = before.lastIndexOf('[') > before.lastIndexOf(']');
  const motiveEnd = defining ? [hint(']', 'end of the motive')] : [];
  const item = whole.replace(/^[A-Z]\[/, '');
  if (item !== whole && item === '') {
    return { title: `Motive ${whole[0]}`, detail: `Items up to ] are entered and stored; @${whole[0]} brings them back.`, hints: START_HINTS.slice(0, 4) };
  }
  const parts = item.split(/[:']/);
  const inChord = parts.length > 1;
  const part = parts.at(-1)!.trimStart();

  if (text.trim() === '' && caret === 0) {
    return {
      title: 'Type the notes',
      detail: 'Items are separated by /, the notes of a chord by :. Lengths come in pass 2.',
      hints: [...START_HINTS, finishPass(1)],
    };
  }
  if (part === '') {
    if (inChord) return { title: 'Next note of the chord', detail: 'The octave carries on from the note before.', hints: [hint(['A', '…', 'G'], 'note letter'), ...motiveEnd] };
    return { title: 'New item', hints: [...START_HINTS, hint('/', 'repeat the item before'), ...motiveEnd, finishPass(1)] };
  }

  const c0 = part[0]!;
  const extra = [...motiveEnd];
  if (part === 'B') return withExtra(noteHelp(readNote(part)!, inChord), [hint('A', 'BA: bass clef')], extra);
  if (part === 'A') return withExtra(noteHelp(readNote(part)!, inChord), [hint('L', 'AL: alto clef')], extra);
  if (part === 'C') return withExtra(noteHelp(readNote(part)!, inChord), [hint(['OM', 'UT'], 'COM, CUT: common, cut time')], extra);
  if (part === 'CO') return { title: 'COM: common time', hints: [hint('M', 'COM')] };
  if (/^C.M/.test(part)) return { title: 'Common time', hints: [NEXT_ITEM, ...extra] };
  if (/^C.T/.test(part)) return { title: 'Cut time', hints: [NEXT_ITEM, ...extra] };
  const clef = CLEFS[part.slice(0, 2)];
  if (clef && !inChord) return { title: clef[0]!.toUpperCase() + clef.slice(1), detail: 'A clef within the line is drawn small.', hints: [NEXT_ITEM, ...extra] };

  const note = readNote(part);
  if (note && !(c0 === 'P' && part === 'PR')) {
    const help = noteHelp(note, inChord);
    if (c0 === 'P') help.detail = 'Proximity mode: each note without a number takes the octave nearest the note before, until O.';
    if (c0 === 'O') help.detail = 'Plain octaves again: a note without a number keeps the octave of the last one.';
    return withExtra(help, [], extra);
  }
  if (inChord) return { title: 'Chord notes are note letters', hints: [hint(['A', '…', 'G'], 'note letter')] };

  switch (c0) {
    case 'R':
      return withExtra(restHelp(part), [], extra);
    case 'M':
      return withExtra(barHelp(part), [], extra);
    case 'K':
      return withExtra(keyHelp(part), [], extra);
    case 'T':
      return part === 'T'
        ? { title: 'Clef or meter', detail: 'T alone, as the last item, repeats the last meter.', hints: [hint('R', 'TR: treble clef'), hint('E', 'TE: tenor clef')] }
        : { title: 'Not an item', detail: 'TR is the treble clef, TE the tenor clef.', hints: [] };
    case 'P':
      return part === 'P'
        ? { title: 'Proximity mode', detail: 'Each note takes the octave nearest the note before.', hints: [hint(['A', '…', 'G'], 'note'), hint('R', 'PR: percussion clef')] }
        : { title: 'Percussion clef', hints: [NEXT_ITEM, ...extra] };
    case 'O':
      return { title: 'Plain octaves', detail: 'Notes keep the octave of the last one; ends proximity mode.', hints: [hint(['A', '…', 'G'], 'note')] };
    case 'S':
      if (part.length === 1) return { title: 'Stems or staff', hints: [hint(['U', 'D', 'O'], 'stems up, down, normal'), hint(['+', '-', '0'], 'notes on the staff above, below, this one')] };
      return { title: switchName(part[1]!), detail: 'Holds for the following notes.', hints: [NEXT_ITEM, ...extra] };
    case 'Q':
      return part.length === 1
        ? { title: 'Cue-size notes', hints: [hint('+', 'small notes from here'), hint('-', 'normal size again')] }
        : { title: part[1] === '+' ? 'Cue-size notes on' : 'Cue-size notes off', hints: [NEXT_ITEM, ...extra] };
    case '-': {
      const name = CLEFS[part.slice(1, 3)];
      return name
        ? { title: `Read as ${name}`, detail: 'The following notes are placed as if the staff had this clef; the staff keeps its own.', hints: [NEXT_ITEM, ...extra] }
        : { title: 'Read the notes in another clef', hints: [hint(['TR', 'BA', 'AL', 'TE'], 'as treble, bass, alto, tenor clef')] };
    }
    case '.':
    case '=':
      return {
        title: part.length > 1 ? 'Repeat the chord before last, with accidentals' : 'Repeat the chord before last',
        detail: 'Copies the note or chord before the previous one.',
        hints: [...(part.length === 1 ? [hint('.', 'keep its accidentals')] : []), NEXT_ITEM, ...extra],
      };
    case 'X':
    case 'Z':
      return repeatHelp(part, c0 === 'Z' ? ' (accidentals kept)' : '', extra);
    case '@':
      return motiveHelp(part, 'transposed by that many steps, e.g. @Z2, @Z-1', extra);
    default:
      if (/\d/.test(c0)) return withExtra(meterHelp(part), [], extra);
      return { title: 'Not an item', detail: `No item starts with ${c0}.`, hints: [] };
  }
}

function switchName(c: string): string {
  return { U: 'Stems up', D: 'Stems down', O: 'Stems normal', '+': 'Notes on the staff above', '-': 'Notes on the staff below', '0': 'Notes on this staff' }[c] ?? 'Not a switch';
}

function repeatHelp(part: string, keeps: string, extra: Hint[]): Help {
  const [n, m] = part.slice(1).trim().split(/\s+/);
  if (!n) return { title: `Repeat items${keeps}`, detail: 'X n m: the last n items, m copies in all.', hints: [hint(['1', '…', '9'], 'how many items')] };
  if (m === undefined) return { title: `Repeat the last ${n} item${n === '1' ? '' : 's'}${keeps}`, hints: [hint('␣', 'then the number of copies')] };
  return { title: `Last ${n} item${n === '1' ? '' : 's'}, ${m || '…'} copies in all${keeps}`, hints: [NEXT_ITEM, ...extra] };
}

function motiveHelp(part: string, number: string, extra: Hint[]): Help {
  const name = part[1];
  if (!name) return { title: 'Recall a motive', detail: 'Motives are stored with Z[…] (any letter).', hints: [hint(['A', '…', 'Z'], 'its name')] };
  return { title: `Motive ${name}`, hints: [hint(['1', '…', '9'], number), NEXT_ITEM, ...extra] };
}

function withExtra(help: Help, first: Hint[], last: Hint[]): Help {
  return { ...help, hints: [...first, ...help.hints, ...last] };
}

// ---- pass 2: rhythms -------------------------------------------------------

const VALUE_NAMES: Record<string, string> = {
  '.5': 'breve',
  '0.5': 'breve',
  '1': 'whole',
  '2': 'half',
  '3': 'triplet half',
  '4': 'quarter',
  '6': 'triplet quarter',
  '8': 'eighth',
  '12': 'triplet eighth',
  '16': 'sixteenth',
  '20': 'quintuplet sixteenth',
  '24': 'triplet sixteenth',
  '32': 'thirty-second',
  '48': 'triplet thirty-second',
  '64': 'sixty-fourth',
};
const LETTER_VALUES: Record<string, string> = { D: 'breve', W: 'whole', H: 'half', Q: 'quarter', E: 'eighth', S: 'sixteenth', T: 'triplet eighth' };
const DOTS = ['', 'dotted ', 'double-dotted ', 'triple-dotted '];

/** One value in words: a number, a letter, T with a letter or number, or G, each with its dots. */
function oneValue(value: string, dots: string): string {
  if (value === 'G') return 'grace note';
  const triplet = /^T(.+)$/.exec(value)?.[1];
  const name = triplet ? `triplet ${LETTER_VALUES[triplet] ?? VALUE_NAMES[triplet] ?? `1/${triplet}`}` : LETTER_VALUES[value] ?? VALUE_NAMES[value];
  return `${DOTS[dots.length] ?? `${dots.length}-dotted `}${name ?? `1/${value} of a whole`}`;
}

/** A pass-2 item in words; several values in one item add up (QE, 4 8). */
function valueName(item: string): string | null {
  const text = item.replace(/\s+/g, ' ').trim();
  const value = /(T?[DWHQES]|T\d+|\d*\.?\d+|G|T)(\.*)\s*/gy;
  const parts: string[] = [];
  let m: RegExpExecArray | null;
  while (value.lastIndex < text.length && (m = value.exec(text))) parts.push(oneValue(m[1]!, m[2]!));
  if (parts.length === 0 || value.lastIndex < text.length) return null;
  return parts.join(' + ');
}

const RHYTHM_HINTS: Hint[] = [
  hint(['4', '8', '2', '1', '16'], 'quarter, eighth, half, whole, 16th'),
  hint(['Q', 'E', 'H', 'W', 'S'], 'the same as letters'),
  hint(['12', 'T'], 'triplet eighth (6 triplet quarter)'),
  hint('G', 'grace note'),
  hint('.', 'dot, after a value'),
];

/** Help in pass 2 for the value at the caret. */
function rhythmsHelp(text: string, caret: number, facts: Facts): Help {
  const { item, before, ended } = currentItem(text, caret);
  if (ended) return { title: 'End of the rhythms', hints: [finishPass(2)] };
  const values = facts.needed >= 0 ? facts.needed : null;
  const index = before.split(/[/,]/).length;
  const of = values !== null ? ` of ${values}` : '';
  if (text.trim() === '') {
    return {
      title: values !== null ? `Lengths for ${values} note${values === 1 ? '' : 's'}, chords and rests` : 'Lengths of the notes',
      detail: 'One value per note, chord and rest, separated by /. One value alone (8) sets them all.',
      hints: [...RHYTHM_HINTS, hint('X3', 'three of the value'), finishPass(2)],
    };
  }
  if (item === '') {
    return {
      title: `${ordinal(index)} value${of}`,
      detail: values !== null && index > values ? 'All notes have a value; more are not used.' : undefined,
      hints: [...RHYTHM_HINTS, hint('/', 'the value before again'), hint(['X 2 3'], 'repeat the last 2 values, 3 copies'), finishPass(2)],
    };
  }
  const clean = item.replace(/\s+/g, ' ').trim();
  if (clean.startsWith('@')) return motiveHelp(clean, 'lengths times that number, e.g. @Z2 doubles', []);
  if (/^(X|REP|RP)/.test(clean)) return repeatHelp(clean.replace(/^(REP|RP)/, 'X'), '', []);
  const repeat = /X\s*(\d*)$/.exec(clean);
  if (repeat) {
    const name = valueName(clean.slice(0, repeat.index).trim());
    return { title: `${name ?? 'Value'} × ${repeat[1] || '…'}`, hints: repeat[1] ? [NEXT_ITEM, finishPass(2)] : [hint(['2', '…', '9'], 'copies')] };
  }
  const name = valueName(clean);
  const hints: Hint[] = [];
  if (clean === 'T') {
    return {
      title: `${ordinal(index)} value${of}: triplet eighth`,
      detail: 'Or a triplet of another value:',
      hints: [hint(['Q', 'H', 'S', 'T'], 'triplet quarter, half, 16th, 32nd'), hint(['4', '2', '16'], 'the same as numbers (T4 …)'), NEXT_ITEM],
    };
  }
  if (/^\d+$/.test(clean)) {
    const more = ['12', '16', '24', '32', '64'].filter((v) => v.startsWith(clean) && v !== clean);
    if (more.length) hints.push(hint(more.map((v) => v.slice(clean.length)), more.map((v) => `${v} ${VALUE_NAMES[v]}`).join(', ')));
  }
  if (name && name !== 'grace note') hints.push(hint('.', /\.$/.test(clean) ? 'another dot' : 'dot'));
  if (name) hints.push(hint('X3', 'three of this value'));
  hints.push(NEXT_ITEM, finishPass(2));
  return {
    title: `${ordinal(index)} value${of}: ${name ?? clean}`,
    detail: name ? undefined : 'Values are numbers (4, 8, 16), letters (Q, E, S), T for triplets or G.',
    hints,
  };
}

// ---- pass 3: marks ---------------------------------------------------------

const MARKS: Record<string, string> = {
  S: 'staccato',
  A: 'accent',
  T: 'tenuto',
  W: 'wedge',
  WS: 'wedge and staccato',
  AS: 'accent and staccato',
  TS: 'tenuto and staccato',
  ACT: 'accent and tenuto',
  D: 'down bow',
  U: 'up bow',
  H: 'harmonic',
  HW: 'heavy wedge',
  FE: 'fermata',
  TH: 'thesis',
  M: 'mordent',
  I: 'inverted mordent',
  PL: 'plus',
  TR: 'trill',
  TRF: 'trill with flat',
  TRS: 'trill with sharp',
  TRN: 'trill with natural',
  TRW: 'trill line (from, to)',
  TRFW: 'trill line with flat (from, to)',
  TRSW: 'trill line with sharp (from, to)',
  TRNW: 'trill line with natural (from, to)',
  PPP: 'ppp',
  PP: 'pp',
  P: 'p',
  MP: 'mp',
  MF: 'mf',
  F: 'f',
  FF: 'ff',
  FFF: 'fff',
  FP: 'fp',
  SF: 'sf',
  SFZ: 'sfz',
  CR: 'cresc.',
  DI: 'dim.',
  R: 'rit.',
  AC: 'accel.',
  PZ: 'pizz.',
  AO: 'arco',
  C: 'crescendo hairpin (from, to)',
  'C-': 'decrescendo hairpin (from, to)',
  O: '8va line (from, to)',
  OB: '8va bassa line (from, to)',
  TM: 'tremolo, 3 strokes',
  TME: 'tremolo, 1 stroke',
  TMS: 'tremolo, 2 strokes',
  FIF: 'musica ficta flat',
  FIS: 'musica ficta sharp',
  FIN: 'musica ficta natural',
};
for (let i = 0; i <= 9; i++) MARKS[`F${i}`] = `fingering ${i}`;

const MARK_HINTS: Hint[] = [
  hint(['S', 'A', 'T', 'W'], 'staccato, accent, tenuto, wedge'),
  hint(['FE', 'TR', 'M'], 'fermata, trill, mordent'),
  hint(['P', 'MF', 'F', 'SF'], 'dynamics'),
  hint(['CR', 'DI'], 'cresc., dim.'),
  hint(['C', 'C-'], 'hairpin from one note to another'),
  hint(['F1', '…', 'F5'], 'fingering'),
  hint('-', 'before the mark: the other side'),
];

/** A mark's name as a title: dynamics and abbreviations as they are written. */
function capital(meaning: string): string {
  return /^[pmfsz]+$|\.$/.test(meaning) ? meaning : `${meaning[0]!.toUpperCase()}${meaning.slice(1)}`;
}

/** Note numbers as typed in pass 3 (`2 4:6`) in words: "notes 2, 4–6". */
function numberList(numbers: string): string {
  const parts = numbers.split(/\s+/).filter(Boolean).map((n) => n.replace(/[:']/, '–'));
  const several = parts.length > 1 || parts.some((p) => /–\d/.test(p));
  return `${several ? 'notes' : 'note'} ${parts.join(', ')}`;
}

function noteNumbers(facts: Facts): string {
  return facts.notes > 0 ? `1–${facts.notes}` : 'from 1';
}

/** Help in pass 3 for the mark at the caret. */
function marksHelp(text: string, caret: number, facts: Facts): Help {
  const { item, ended } = currentItem(text, caret);
  if (ended) return { title: 'End of the marks', hints: [finishPass(3)] };
  const numbered = `Notes are numbered ${noteNumbers(facts)}; a chord counts once, rests do not.`;
  if (item === '') {
    return {
      title: text.trim() === '' ? 'Marks: a mark, then note numbers' : 'Next mark',
      detail: `S 2:5 puts staccato dots on notes 2 to 5. ${numbered}`,
      hints: [...MARK_HINTS, finishPass(3)],
    };
  }
  const m = /^([-+=]?)([A-Z]+\d*)(.*)$/.exec(item.replace(/^\s+/, ''));
  if (!m) return { title: 'A mark starts with its letters', hints: MARK_HINTS };
  const [, side = '', rawName = '', rest = ''] = m;
  const name = rawName === 'C' && rest.startsWith('-') ? 'C-' : rawName;
  const after = name === 'C-' && rawName === 'C' ? rest.slice(1) : rest;
  const listed = MARKS[name] ?? (name.startsWith('N') && /^N\d+$/.test(name) ? `symbol ${name.slice(1)}` : null);
  const twoPoint = listed?.includes('(from, to)') ?? false;
  const meaning = listed?.replace(' (from, to)', '') ?? null;
  const other = side === '-' ? ', on the other side' : '';
  const longer = Object.keys(MARKS)
    .filter((k) => k.startsWith(name) && k !== name && k.length <= name.length + 2 && !/^F\d$/.test(k))
    .slice(0, 5);
  if (after.trim() === '') {
    return {
      title: meaning ? `${capital(meaning)}${other}` : `Mark ${name}?`,
      detail: meaning ? (twoPoint ? 'Give the first and the last note; fractions fall between notes (C 1 2.5).' : numbered) : 'Not a mark name yet.',
      hints: [
        ...(meaning ? [hint('␣', twoPoint ? `then two note numbers (${noteNumbers(facts)})` : `then note numbers (${noteNumbers(facts)})`)] : []),
        ...longer.map((k) => hint(k, MARKS[k]!)),
      ],
    };
  }
  const numbers = after.trim();
  const ends = numbers.split(/[\s:']+/).filter(Boolean);
  const where = twoPoint ? `from note ${ends[0]}${ends[1] ? ` to ${ends[1]}` : ''}` : `on ${numberList(numbers)}`;
  return {
    title: `${meaning ? capital(meaning) : name}${other} ${where}`,
    detail: facts.notes > 0 && Math.max(...(numbers.match(/\d+/g) ?? ['0']).map(Number)) > facts.notes ? `There are only ${facts.notes} notes.` : undefined,
    hints: [
      ...(twoPoint ? [] : [hint('␣', 'another note number'), hint(':', 'to: a range of notes (2:5)')]),
      hint('/', 'next mark'),
      finishPass(3),
    ],
  };
}

// ---- passes 4 and 5: beams and slurs ------------------------------------------

function connectHelp(text: string, caret: number, facts: Facts, pass: 4 | 5): Help {
  const { item, ended } = currentItem(text, caret);
  const what = pass === 4 ? 'beam' : 'slur';
  if (ended) return { title: `End of the ${what}s`, hints: [finishPass(pass)] };
  const numbered = `Notes are numbered ${noteNumbers(facts)}; a chord counts once, rests do not.`;
  const shared = [hint(['+', '-'], pass === 4 ? 'before a number: beam above / below' : 'before a number: curve up / down'), hint('X3 1 4', `${what}s over notes 1–3 and 4–6`)];
  const specific =
    pass === 4
      ? [hint('2B', 'beams over every 2 eighths (2B1: after 1 pickup note)'), hint('B', 'beams by the meter'), hint('301 3', 'a 3 over the beam from 1 to 3')]
      : [hint('0 3', 'from the left edge to note 3'), hint('6 99', 'from note 6 to the right edge'), hint('503 7', 'a 5 bracket over notes 3–7')];
  if (item === '') {
    return {
      title: text.trim() === '' ? `${pass === 4 ? 'Beams' : 'Slurs and ties'}: first and last note` : `Next ${what}`,
      detail: `1 4 draws a ${what} from note 1 to note 4. ${numbered}`,
      hints: [hint('1 4', `${what} from note 1 to 4`), ...shared, ...specific, finishPass(pass)],
    };
  }
  const clean = item.replace(/\s+/g, ' ');
  if (clean.startsWith('@')) return motiveHelp(clean, 'its note 1 on that note', []);
  if (pass === 4 && /^[+-]?\d*B/.test(clean)) {
    return { title: 'Automatic beams', detail: 'nB beams every n eighths; nBp starts after p notes. It must be the only item.', hints: [hint(['1', '…', '9'], 'pickup notes'), finishPass(4)] };
  }
  if (clean.startsWith('X')) {
    const [size, ...starts] = clean.slice(1).trim().split(' ');
    return {
      title: size ? `${what[0]!.toUpperCase()}${what.slice(1)}s over ${size} notes each` : `Groups of ${what}s`,
      detail: 'X then the group size, then the first note of each group.',
      hints: size ? [hint('␣', starts.length ? 'another first note' : 'first note of a group'), NEXT_ITEM, finishPass(pass)] : [hint(['2', '…', '9'], 'notes per group')],
    };
  }
  const numbers = clean.trim().split(' ').filter(Boolean);
  const plain = numbers.map((n) => Math.abs(parseFloat(n.replace(/^[+=]/, ''))) % 100);
  const sides = numbers.map((n) => (n.startsWith('-') ? (pass === 4 ? ' below' : ' down') : /^[+=]/.test(n) ? (pass === 4 ? ' above' : ' up') : '')).join('');
  if (numbers.length === 1 && !clean.endsWith(' ')) {
    return {
      title: `${what[0]!.toUpperCase()}${what.slice(1)} from note ${plain[0]}${sides}`,
      hints: [hint('␣', 'then the last note'), hint('/', 'alone: to the next note'), ...(pass === 4 ? [hint('B', `${plain[0]}B: automatic beams`)] : [])],
    };
  }
  if (numbers.length === 1) return { title: `${what[0]!.toUpperCase()}${what.slice(1)} from note ${plain[0]}${sides}`, hints: [hint(['1', '…', '9'], 'the last note')] };
  const tens = numbers.map((n) => Math.floor(Math.abs(parseFloat(n)) / 100) % 100).find((k) => k > 0);
  const label = tens ? (pass === 4 ? `, ${tens} over it` : `, bracket ${tens}`) : '';
  const from = pass === 5 && plain[0] === 0 ? 'the left edge' : `note ${plain[0]}`;
  const to = pass === 5 && plain[1] === 99 ? 'the right edge' : `note ${plain[1]}`;
  return {
    title: `${what[0]!.toUpperCase()}${what.slice(1)} from ${from} to ${to}${sides}${label}`,
    detail: facts.notes > 0 && Math.max(...plain) > facts.notes && plain[1] !== 99 ? `There are only ${facts.notes} notes.` : undefined,
    hints: [NEXT_ITEM, finishPass(pass)],
  };
}

/** Help for the caret at UTF-16 offset `caret` of `text`, the text of `pass` (1-5) as typed. */
export function helpFor(pass: number, text: string, caret: number, facts: Facts): Help {
  switch (pass) {
    case 1:
      return notesHelp(text, caret);
    case 2:
      return rhythmsHelp(text, caret, facts);
    case 3:
      return marksHelp(text, caret, facts);
    case 4:
    case 5:
      return connectHelp(text, caret, facts, pass);
    default:
      return { title: '', hints: [] };
  }
}

// ---- passes 3-5 with a cursor on the notes ------------------------------------

/** The notes a cursor in passes 3-5 has selected, and what `/` alone would place again. */
export interface Selected {
  from: number;
  to: number;
  repeat: string;
}

const MOVE_HINTS: Hint[] = [hint(['←', '→'], 'another note'), hint(['⇧←', '⇧→'], 'more notes')];

function notesWord({ from, to }: Selected): string {
  return from === to ? `note ${from}` : `notes ${from}–${to}`;
}

/** Help in pass 3 for a mark typed at the cursor. */
function markAtCursor(pending: string, at: Selected): Help {
  const name = pending.replace(/^[-+=]/, '');
  const other = pending.startsWith('-') ? ', on the other side' : '';
  if (name === '') {
    return {
      title: pending === '-' ? `A mark on the other side of ${notesWord(at)}` : `Marks on ${notesWord(at)}`,
      detail: 'Type the mark and / to place it; the note numbers come from the cursor.',
      hints: [
        ...MARK_HINTS.slice(0, pending === '-' ? -1 : undefined),
        ...(at.repeat ? [hint('/', `${at.repeat} here again`)] : []),
        ...MOVE_HINTS,
        hint('⌫', 'remove the last mark here'),
        finishPass(3),
      ],
    };
  }
  const listed = MARKS[name] ?? (/^N\d+$/.test(name) ? `symbol ${name.slice(1)}` : null);
  const twoPoint = listed?.includes('(from, to)') ?? false;
  const meaning = listed?.replace(' (from, to)', '') ?? null;
  const where = twoPoint ? `from note ${at.from} to ${at.to > at.from ? at.to : at.from + 1}` : `on ${notesWord(at)}`;
  const longer = Object.keys(MARKS)
    .filter((k) => k.startsWith(name) && k !== name && k.length <= name.length + 2 && !/^F\d$/.test(k))
    .slice(0, 5);
  return {
    title: meaning ? `${capital(meaning)}${other} ${where}` : `Mark ${name}?`,
    detail: meaning ? (twoPoint ? 'Shift+→ moves its end to a later note.' : undefined) : 'Not a mark name yet.',
    hints: [
      ...(meaning ? [hint('/', 'place it')] : []),
      ...longer.map((k) => hint(k.slice(name.length), `${k}: ${MARKS[k]!.replace(' (from, to)', '')}`)),
      ...MOVE_HINTS,
      hint('␣', 'type note numbers yourself (S 2:5)'),
    ],
  };
}

/** Help in passes 4 and 5 for a beam or slur at the cursor. */
function connectAtCursor(pending: string, at: Selected, facts: Facts, pass: 4 | 5): Help {
  const what = pass === 4 ? 'Beam' : 'Slur';
  const to = at.to > at.from ? at.to : at.from + 1;
  const m = /^([-+=]?)(\d*)$/.exec(pending)!;
  const side = m[1] === '-' ? (pass === 4 ? ' below' : ', curved down') : m[1] ? (pass === 4 ? ' above' : ', curved up') : '';
  const number = m[2] ? (pass === 4 ? `, ${m[2]} over it` : `, bracket ${m[2]}`) : '';
  const beyond = facts.notes > 0 && to > facts.notes ? (pass === 5 ? ' (to the right edge)' : '') : '';
  return {
    title: `${what} from note ${at.from} to ${to}${beyond}${side}${number}`,
    detail: at.to === at.from ? `Shift+→ takes in more notes; alone it reaches the next note${pass === 5 ? ' (a tie)' : ''}.` : undefined,
    hints: [
      hint('/', pass === 4 ? 'draw the beam' : 'draw the slur'),
      ...(m[1] ? [] : [hint(['+', '-'], pass === 4 ? 'above / below' : 'curved up / down')]),
      ...(m[2] ? [] : [hint(['3', '5'], pass === 4 ? 'a number over the beam' : 'a tuplet bracket with that number')]),
      ...(at.repeat && pending === '' ? [hint('/', `as the last one (${at.repeat || 'plain'})`)] : []),
      ...MOVE_HINTS,
      hint('⌫', `remove the last ${what.toLowerCase()} here`),
      ...(pass === 4 ? [hint('2B', 'automatic beams (type it alone)')] : [hint(['0 3', '6 99'], 'from the left edge, to the right edge')]),
      finishPass(pass),
    ],
  };
}

/**
 * Help in passes 3-5, where the cursor stands on notes: `pending` is what has been
 * typed there. Text with its own note numbers (`S 2:5`, `1 4`, `2B`) gets the help of
 * the typed item.
 */
export function cursorHelp(pass: number, pending: string, at: Selected, facts: Facts): Help {
  const text = pending.trim();
  if (facts.notes === 0) {
    return { title: 'No notes yet', detail: 'Marks, beams and slurs go on the notes of pass 1.', hints: [hint(['⇧↵'], 'back to the notes')] };
  }
  if (pass === 3) {
    if (/^[-+=]?[A-Z]+\d*[+-]?$/.test(text) || /^[-+=]?$/.test(text)) return markAtCursor(text, at);
    return helpFor(3, text, text.length, facts);
  }
  if (pass === 4 || pass === 5) {
    if (/^[-+=]?\d*$/.test(text)) return connectAtCursor(text, at, facts, pass);
    return helpFor(pass, text, text.length, facts);
  }
  return helpFor(pass, text, text.length, facts);
}
