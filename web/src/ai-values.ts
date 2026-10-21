// The literal values in a command, which a decision model cannot write
// itself: its numbers, and note names typed as music ("c g d/f/a",
// "f#4 bb e"). They become candidates the models choose between, as Jev's
// pre-parsed extraction pattern has it; what the command means is left to
// the models.

/** Numbers spelt out, and twice and thrice; not "one", as likely a pronoun ("every other one"). */
const SPELT: Record<string, number> = { two: 2, three: 3, four: 4, five: 5, six: 6, seven: 7, eight: 8, nine: 9, ten: 10, eleven: 11, twelve: 12, twice: 2, thrice: 3 };

/** The numbers in the text as written: "1.5", "-2", "50%", "three", "twice"; not ordinals ("8th") or a meter's ("3/4"). */
export function numberWords(text: string): string[] {
  return Array.from(text.matchAll(/(^|[^\w./])(-?\d+(?:\.\d+)?%?)(?![\w/])|\b(two|three|four|five|six|seven|eight|nine|ten|eleven|twelve|twice|thrice)\b/gi), (m) => m[2] ?? m[3]!.toLowerCase());
}

/** A count: a whole number that is not an ordinal ("4", "4s"; not "8th"), or a count's word ("pairs", "fours"; not "eighth"). */
const COUNT = /(^|[^\w.])\d+s?(?![\w.])|\b(pairs?|two|twos|three|threes|four|fours|six|sixes|eight|eights)\b/i;

/** Whether the text names a count of something. */
export const namesCount = (text: string) => COUNT.test(text);

/** Note values spelt as words and as numbers. */
const VALUE_WORDS: Record<string, string[]> = { eighth: ['8th', 'eighth'], '16th': ['16th', 'sixteenth'], '32nd': ['32nd', 'thirty-second'], '64th': ['64th', 'sixty-fourth'] };

/** Whether the text names an option by its first word ("staccatos" names Staccato, "8th" Eighth, "sharpen" ♯ Sharp). */
export function namesOption(text: string, label: string): boolean {
  const lower = text.toLowerCase();
  const word = label.toLowerCase().split(/[^\p{L}\p{N}-]+/u).find((w) => w.length >= 3);
  return word !== undefined && (VALUE_WORDS[word] ?? [word.slice(0, 6)]).some((s) => lower.includes(s));
}

/** A number as written, a percentage as a fraction ("50%" is 0.5), a spelt one as its value. */
export const numberOf = (word: string) => SPELT[word] ?? (word.endsWith('%') ? Number(word.slice(0, -1)) / 100 : Number(word));

/** A meter written as a fraction ("3/4", "6 / 8"): its numbers. */
export function meterIn(text: string): [number, number] | null {
  const m = /(?:^|[^\w./])(\d{1,2})\s*\/\s*(\d{1,2})(?![\w./])/.exec(text);
  return m ? [Number(m[1]), Number(m[2])] : null;
}

/** The characters given in double quotes ("Allegro", “dolce”). */
export function quotedIn(text: string): string | null {
  const m = /["“”„]([^"“”„]+)["“”]/.exec(text);
  return m ? m[1]!.trim() || null : null;
}

/** The numbers in the text ("50%" as 0.5). */
export function numbersIn(text: string): number[] {
  return numberWords(text).map(numberOf);
}

/**
 * A note name as typed: letter, accidental (#, b, x, is, es, ♯, ♭, ♮; n only
 * before an octave), octave. A lone s or n would read English words ("as",
 * "an") as notes.
 */
const PITCH = /^([a-g])(##|bb|is|es|#|b|x|♯♯|♭♭|♯|♭|♮|n(?=\d))?(\d)?$/i;

const ACCIDENTALS: Record<string, string> = { '#': 'S', is: 'S', '♯': 'S', b: 'F', es: 'F', '♭': 'F', n: 'N', '♮': 'N', '##': 'SS', x: 'SS', '♯♯': 'SS', bb: 'FF', '♭♭': 'FF' };

/** One note name in SCORE's input language (F#4 → FS4), or null. */
function scoreNote(word: string): string | null {
  const m = PITCH.exec(word);
  if (!m) return null;
  return `${m[1]!.toUpperCase()}${m[2] ? ACCIDENTALS[m[2].toLowerCase()] ?? '' : ''}${m[3] ?? ''}`;
}

/** One element: a note, a chord of notes joined by / : + or ', a rest (r), or a barline (|). */
function scoreElement(word: string): string | null {
  if (/^r(est)?$/i.test(word)) return 'R';
  if (word === '|') return 'M';
  const notes = word.split(/[/:+']/);
  if (notes.some((n) => n === '')) return null;
  const converted = notes.map(scoreNote);
  return converted.every((n) => n !== null) ? converted.join(':') : null;
}

export interface Music {
  /** The words as typed. */
  typed: string;
  /** SCORE input, pass 1: proximity mode (each note nearest the one before) unless octaves are given. */
  notes: string;
  /** How many notes, chords and rests. */
  count: number;
  /** SCORE input, pass 2, when the values are typed with the notes ("c e g 4 8 8", "c 4 d 8 e 8", "c e g 8"). */
  rhythms?: string;
}

/** A note value as SCORE's pass 2 writes it: 4 a quarter, 8. a dotted eighth. */
const VALUE = /^\d{1,2}\.{0,3}$/;

/** Words that may stand between the notes and their values ("c e g as 4 8 8"). */
const BEFORE_VALUES = new Set(['as', 'in', ':']);

const LETTERS = 'CDEFGABC';

/** The octave that puts `letter` nearest diatonic step `middle` (C0 = 0; B4, a treble staff's middle line, is 34). */
function octaveNear(letter: string, middle: number): number {
  const step = LETTERS.indexOf(letter);
  return Math.round((middle - step) / 7);
}

/** B4: the middle line of a treble staff, as a diatonic step from C0. */
export const TREBLE_MIDDLE = 34;

/**
 * The longest run of words that read as notes, chords and rests, in SCORE's
 * input language. A first note typed without an octave goes nearest the
 * staff's middle line `middle` (a diatonic step from C0), and the notes
 * after it each nearest the one before. Null when there is none.
 */
export function musicIn(text: string, middle = TREBLE_MIDDLE): Music | null {
  const words = text.trim().split(/[\s,]+/).filter(Boolean);
  const isElement = (w: string | undefined) => w !== undefined && scoreElement(w) !== null;
  const isValue = (w: string | undefined) => w !== undefined && VALUE.test(w);
  // Runs of elements and values (a value only after an element or a value, "as" before values), the one with the most notes.
  let best = { start: 0, end: 0, notes: 0 };
  for (let i = 0; i < words.length; i++) {
    if (!isElement(words[i])) continue;
    let [end, notes] = [i, 0];
    for (; end < words.length; end++) {
      const w = words[end]!;
      if (isElement(w)) notes += scoreElement(w) === 'M' ? 0 : 1;
      else if (!(isValue(w) || (BEFORE_VALUES.has(w.toLowerCase()) && isValue(words[end + 1])))) break;
    }
    // A run does not end in "as".
    while (end > i && !isElement(words[end - 1]) && !isValue(words[end - 1])) end--;
    if (notes > best.notes || (best.notes === 0 && end > best.end)) best = { start: i, end, notes };
    i = end;
  }
  const span = words.slice(best.start, best.end).filter((w) => isElement(w) || isValue(w));
  const run = span.filter((w) => isElement(w));
  if (run.length === 0) return null;
  // A lone "a" or "b" is as likely an article as a note.
  if (run.length === 1 && /^[ab]$/i.test(run[0]!)) return null;
  const elements = run.map((w) => scoreElement(w)!);
  const count = elements.filter((e) => e !== 'M').length;
  // Each group of values goes to the notes just before it: one each, or one for all of them.
  const values: string[] = [];
  let [group, valued, fits] = [0, false, true];
  let k = 0;
  while (k <= span.length) {
    if (k < span.length && isElement(span[k])) {
      if (scoreElement(span[k]!) !== 'M') group++;
      k++;
      continue;
    }
    const after: string[] = [];
    while (k < span.length && isValue(span[k])) after.push(span[k++]!);
    if (after.length === 0) values.push(...Array.from({ length: group }, () => '4'));
    else if (after.length === group || after.length === 1) {
      values.push(...(after.length === group ? after : Array.from({ length: group }, () => after[0]!)));
      valued = true;
    } else fits = false;
    group = 0;
    if (after.length === 0) k++;
  }
  const first = elements.findIndex((e) => /^[A-G]/.test(e));
  if (first >= 0 && !/\d/.test(elements[first]!.split(':')[0]!)) {
    const [head, ...rest] = elements[first]!.split(':');
    elements[first] = [`${head}${octaveNear(head!.charAt(0), middle)}`, ...rest].join(':');
  }
  // Octaves typed after the first note mean every octave is meant as typed.
  const explicit = run.slice(first + 1).some((w) => /\d/.test(w));
  if (first >= 0 && !explicit) elements[first] = `P${elements[first]}`;
  const typed = words.slice(best.start, best.end).join(' ');
  return { typed, notes: elements.join('/'), count, ...(valued && fits && values.length === count ? { rhythms: values.join('/') } : {}) };
}

/** Note values by name, as SCORE's pass 2 writes them. */
export const RHYTHMS: Record<string, string> = {
  whole: '1',
  half: '2',
  quarter: '4',
  eighth: '8',
  sixteenth: '16',
  'thirty-second': '32',
  'dotted half': '2.',
  'dotted quarter': '4.',
  'dotted eighth': '8.',
  'triplet eighth': '12',
};

/** Pass 2 for `count` elements of one value ("8/8/8"), quarters when none is named. */
export function rhythmsFor(value: string | null | undefined, count: number): string {
  const code = (value && RHYTHMS[value]) || '4';
  return Array.from({ length: count }, () => code).join('/');
}

/** Quarters for every note, chord and rest of pass 1: an empty pass 2 would make them grace notes. */
export function quartersFor(notes: string): string {
  const elements = notes.replace(/;$/, '').split('/').filter((e) => /^(P|O)?[A-G]|^R/i.test(e.trim()));
  return elements.map(() => '4').join('/');
}

/** Diatonic steps of an interval named in a command ("a third" up is 2 steps). */
export const INTERVALS: Record<string, number> = { second: 1, third: 2, fourth: 3, fifth: 4, sixth: 5, seventh: 6, octave: 7, ninth: 8, tenth: 9, 'two octaves': 14 };

const ORDINALS: Record<string, number> = { first: 1, second: 2, third: 3, fourth: 4, fifth: 5, sixth: 6, seventh: 7, eighth: 8, ninth: 9, tenth: 10, eleventh: 11, twelfth: 12 };

/** Bars named by number: from and to (1 the first), counted back from the last with `end` (1 the last). */
export interface Bars {
  from: number;
  to: number;
  end: boolean;
  /** The words that name them ("the last bar"): a first or last outside them picks among their items. */
  phrase?: string;
}

const BAR = '(?:bars?|measures?)';
const BAR_COUNT = '(\\d+|two|three|four|five|six|seven|eight|nine|ten|eleven|twelve)';

/** The bars a command names: "bar 3", "bars 2 to 4", "the second bar", "the first two bars", "the last bar". */
export function barsIn(text: string): Bars | null {
  const t = text.toLowerCase();
  const found = (m: RegExpExecArray, bars: Omit<Bars, 'phrase'>): Bars => ({ ...bars, phrase: m[0] });
  let m = new RegExp(`\\b${BAR}\\s+(\\d+)(?:\\s*(?:-|–|to|through|until)\\s*(\\d+))?`).exec(t);
  if (m) {
    const [from, to] = [Number(m[1]), Number(m[2] ?? m[1])];
    return found(m, { from: Math.min(from, to), to: Math.max(from, to), end: false });
  }
  m = new RegExp(`\\b(first|last)\\s+${BAR_COUNT}\\s+${BAR}\\b`).exec(t);
  if (m) return found(m, { from: 1, to: numberOf(m[2]!), end: m[1] === 'last' });
  m = new RegExp(`\\blast\\s+${BAR}\\b`).exec(t);
  if (m) return found(m, { from: 1, to: 1, end: true });
  m = new RegExp(`\\b(${Object.keys(ORDINALS).join('|')}|\\d+(?:st|nd|rd|th))\\s+${BAR}\\b`).exec(t);
  if (m) {
    const n = ORDINALS[m[1]!] ?? parseInt(m[1]!, 10);
    return found(m, { from: n, to: n, end: false });
  }
  return null;
}

/**
 * Options named one after another ("staccato, accent, staccato"): the
 * longest run of words each naming one of `labels` by its whole name (or
 * plural), when there are two or more. "and" ends a run: "accent and
 * staccato" may mean both at once.
 */
export function sequenceIn(text: string, labels: string[]): string[] | null {
  const byWord = new Map(labels.filter((l) => /^\p{L}+$/u.test(l)).map((l) => [l.toLowerCase(), l]));
  const named = (w: string) => byWord.get(w) ?? byWord.get(w.replace(/e?s$/, ''));
  let [best, run] = [[] as string[], [] as string[]];
  for (const word of text.toLowerCase().split(/[\s,;]+/).filter(Boolean)) {
    const label = named(word);
    if (label) run.push(label);
    else [best, run] = [run.length > best.length ? run : best, []];
  }
  if (run.length > best.length) best = run;
  return best.length >= 2 ? best : null;
}

/** Fingerings typed after "fingering" ("fingering 1 2 3 1"): their numbers, 0 to 5. */
export function fingeringsIn(text: string): number[] | null {
  const m = /\bfinger(?:ing)?s?\b([\s,\d]+)/i.exec(text);
  const numbers = m ? m[1]!.split(/[\s,]+/).filter(Boolean).map(Number).filter((n) => n >= 0 && n <= 5) : [];
  return numbers.length ? numbers : null;
}

const SPELLINGS: Record<string, string> = { SS: '##', FF: 'bb', S: '#', F: 'b', N: 'n' };

/** Note names typed one after another ("f#", "c e g", "bb4"), as the side panel's Pitch reads them: F#, C, Bb4. Chords, rests and barlines aside. */
export function pitchesIn(text: string): string[] | null {
  const words = musicIn(text)?.typed.split(' ') ?? [];
  const names = words.flatMap((w) => {
    const m = /^([A-G])(SS|FF|S|F|N)?(\d)?$/.exec(scoreNote(w) ?? '');
    return m ? [`${m[1]}${SPELLINGS[m[2] ?? ''] ?? ''}${m[3] ?? ''}`] : [];
  });
  return names.length ? names : null;
}

/** Half steps of intervals named for a transposition, by size, major or perfect. */
export const HALF_STEPS: Record<string, number> = { second: 2, third: 4, fourth: 5, fifth: 7, sixth: 9, seventh: 11, octave: 12, ninth: 14, tenth: 16, 'two octaves': 24 };
const PERFECT = new Set(['fourth', 'fifth', 'octave', 'two octaves']);

/** The half steps of an interval of a size ("third") and quality ("minor"; none: major or perfect). */
export function intervalHalfSteps(size: string, quality: string | undefined): number | null {
  const base = HALF_STEPS[size];
  if (base === undefined) return null;
  const perfect = PERFECT.has(size);
  switch (quality) {
    case 'minor':
      return perfect ? null : base - 1;
    case 'diminished':
      return base - (perfect ? 1 : 2);
    case 'augmented':
      return base + 1;
    default:
      return base;
  }
}

/** Half steps a command names as such: "a semitone", "3 half steps", "a whole step", "two whole tones". */
export function halfStepsIn(text: string): number | null {
  const t = text.toLowerCase();
  const m = /\b(a|an|one|\d+|two|three|four|five|six|seven|eight|nine|ten|eleven|twelve)\s+(semitones?|half[ -]?steps?|half[ -]?tones?|whole[ -]?steps?|whole[ -]?tones?|tones?)\b/.exec(t);
  if (!m) return null;
  const n = ['a', 'an', 'one'].includes(m[1]!) ? 1 : numberOf(m[1]!);
  return /whole|^tones?$/.test(m[2]!) ? 2 * n : n;
}


/** A key note as typed: a letter (0 C … 6 B), an accidental in half steps (-2 … 2) and an octave, if given. */
export interface Tonic {
  letter: number;
  accidental: number;
  octave?: number;
}

const TONIC_ACCIDENTALS: Record<string, number> = { '#': 1, '♯': 1, sharp: 1, b: -1, '♭': -1, flat: -1 };

/** Words after a key note that say it is one ("C major", "d minor scale", "an F# arpeggio"). */
const KIND_WORDS =
  'major|minor|harmonic|melodic|natural|chromatic|pentatonic|dorian|phrygian|lydian|mixolydian|locrian|aeolian|ionian|whole[- ]tone|blues|dominant|diminished|augmented|half[- ]diminished|scales?|arpeggios?|triads?|seventh|7th|chords?|broken';

/**
 * The key note of a scale or chord the command names: the note name just
 * before what it is ("a C major scale", "an e flat arpeggio") or after
 * "from" or "on" ("a chromatic scale from E"). A lone "a" after anything
 * but "an", "the" or such words is the article ("add a minor scale").
 */
export function tonicIn(text: string): Tonic | null {
  // An octave (0–6) or a chord symbol's ending ("G7", "Dm", "Cmaj7"), which leaves the kind to the reading.
  const note = '([a-g])(?:\\s?-?\\s?(sharp|flat)|(#|♯|♭|b(?![a-z])))?(?:([0-6])|maj7|m7|7|m|dim|aug)?';
  const patterns = [new RegExp(`(^|\\S+\\s+)${note}\\s+(?:${KIND_WORDS})\\b`, 'gi'), new RegExp(`(\\b(?:from|on|starting at|in)\\s+)${note}(?![\\w#♯♭])`, 'gi')];
  for (const pattern of patterns) {
    for (const m of text.matchAll(pattern)) {
      const [, before, letter, word, sign, octave] = m;
      const bare = !word && !sign && !octave;
      if (bare && letter === 'a' && !/^(an|the|of|from|on|in|at)\s+$/i.test(before ?? '')) continue;
      const accidental = TONIC_ACCIDENTALS[(word ?? sign ?? '').toLowerCase()] ?? 0;
      return { letter: 'CDEFGAB'.indexOf(letter!.toUpperCase()), accidental, ...(octave ? { octave: Number(octave) } : {}) };
    }
  }
  return null;
}

/** How many octaves a scale or arpeggio spans: "two octaves", "over 3 octaves". */
export function octavesIn(text: string): number | null {
  const m = /\b(\d|two|three|four)\s+octaves?\b/i.exec(text);
  return m ? numberOf(m[1]!.toLowerCase()) : null;
}

/** Scales by the half steps of their degrees above the key note and the letters above its own. */
export const SCALES: Record<string, { half: number[]; letters: number[]; down?: string }> = {
  major: { half: [0, 2, 4, 5, 7, 9, 11], letters: [0, 1, 2, 3, 4, 5, 6] },
  minor: { half: [0, 2, 3, 5, 7, 8, 10], letters: [0, 1, 2, 3, 4, 5, 6] },
  'harmonic minor': { half: [0, 2, 3, 5, 7, 8, 11], letters: [0, 1, 2, 3, 4, 5, 6] },
  // Down, the melodic minor is the natural one.
  'melodic minor': { half: [0, 2, 3, 5, 7, 9, 11], letters: [0, 1, 2, 3, 4, 5, 6], down: 'minor' },
  'major pentatonic': { half: [0, 2, 4, 7, 9], letters: [0, 1, 2, 4, 5] },
  'minor pentatonic': { half: [0, 3, 5, 7, 10], letters: [0, 2, 3, 4, 6] },
  blues: { half: [0, 3, 5, 6, 7, 10], letters: [0, 2, 3, 3, 4, 6] },
  'whole tone': { half: [0, 2, 4, 6, 8, 10], letters: [0, 1, 2, 3, 4, 5] },
  dorian: { half: [0, 2, 3, 5, 7, 9, 10], letters: [0, 1, 2, 3, 4, 5, 6] },
  phrygian: { half: [0, 1, 3, 5, 7, 8, 10], letters: [0, 1, 2, 3, 4, 5, 6] },
  lydian: { half: [0, 2, 4, 6, 7, 9, 11], letters: [0, 1, 2, 3, 4, 5, 6] },
  mixolydian: { half: [0, 2, 4, 5, 7, 9, 10], letters: [0, 1, 2, 3, 4, 5, 6] },
  locrian: { half: [0, 1, 3, 5, 6, 8, 10], letters: [0, 1, 2, 3, 4, 5, 6] },
  chromatic: { half: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11], letters: [] },
};

/** Chords an arpeggio goes through, the same way. */
export const CHORDS: Record<string, { half: number[]; letters: number[] }> = {
  major: { half: [0, 4, 7], letters: [0, 2, 4] },
  minor: { half: [0, 3, 7], letters: [0, 2, 4] },
  diminished: { half: [0, 3, 6], letters: [0, 2, 4] },
  augmented: { half: [0, 4, 8], letters: [0, 2, 4] },
  'dominant seventh': { half: [0, 4, 7, 10], letters: [0, 2, 4, 6] },
  'major seventh': { half: [0, 4, 7, 11], letters: [0, 2, 4, 6] },
  'minor seventh': { half: [0, 3, 7, 10], letters: [0, 2, 4, 6] },
  'diminished seventh': { half: [0, 3, 6, 9], letters: [0, 2, 4, 6] },
  'half-diminished seventh': { half: [0, 3, 6, 10], letters: [0, 2, 4, 6] },
};

/** The chord of a kind named for a scale ("harmonic minor" arpeggios are minor ones). */
export const chordOf = (kind: string) => (CHORDS[kind] ? kind : /minor|dorian|phrygian|aeolian/.test(kind) ? 'minor' : /locrian/.test(kind) ? 'diminished' : 'major');

/** Half steps of the naturals above C. */
const NATURAL = [0, 2, 4, 5, 7, 9, 11];

/** The key note of a key signature (sharps, flats negative): its major key's, or its minor key's. */
export function keyTonic(sharps: number, minor: boolean): Tonic {
  // The major key's letter goes up a fifth (four letters) for each sharp; its minor key's two letters below.
  const letter = (((4 * sharps + (minor ? 5 : 0)) % 7) + 7) % 7;
  const half = (((7 * sharps + (minor ? 9 : 0)) % 12) + 12) % 12;
  let accidental = half - NATURAL[letter]!;
  if (accidental > 6) accidental -= 12;
  if (accidental < -6) accidental += 12;
  return { letter, accidental };
}

/** The alteration a key signature gives each letter (C … B): sharps on F C G D A E B, flats the other way. */
function signatureOf(sharps: number): number[] {
  const alter = [0, 0, 0, 0, 0, 0, 0];
  const order = sharps >= 0 ? [3, 0, 4, 1, 5, 2, 6] : [6, 2, 5, 1, 4, 0, 3];
  for (const letter of order.slice(0, Math.abs(sharps))) alter[letter] = Math.sign(sharps);
  return alter;
}

const SIGNS: Record<number, string> = { [-2]: 'FF', [-1]: 'F', 0: 'N', 1: 'S', 2: 'SS' };

export interface Recipe {
  tonic: Tonic;
  /** A scale (SCALES) or, for an arpeggio, a chord (CHORDS). */
  kind: string;
  arpeggio: boolean;
  way: 'up' | 'down' | 'both';
  octaves: number;
}

/**
 * A scale or arpeggio as SCORE's pass 1, every note with its octave, from
 * the key note up or down over the octaves and back, its accidentals as the
 * key signature in force (`sharps`) and the ones before them in the run
 * leave them to be written. Chromatic scales take sharps up and flats down.
 */
export function recipeNotes(recipe: Recipe, sharps: number): string {
  const { tonic, octaves } = recipe;
  // Down, the run goes from the key note as far below it.
  const octave = (tonic.octave ?? 4) - (recipe.way === 'down' ? octaves : 0);
  const root = { step: 7 * octave + tonic.letter, half: 12 * octave + NATURAL[tonic.letter]! + tonic.accidental };
  /** A note by its diatonic step and half step from C0. */
  type Note = { step: number; half: number };
  const run = (kind: string, down: boolean): Note[] => {
    const notes: Note[] = [];
    if (kind === 'chromatic') {
      for (let k = 0; k <= 12 * octaves; k++) {
        const half = root.half + k;
        const pc = ((half % 12) + 12) % 12;
        const natural = NATURAL.indexOf(pc);
        const letter = natural >= 0 ? natural : down ? NATURAL.indexOf(pc + 1) : NATURAL.indexOf(pc - 1);
        notes.push({ step: 7 * Math.floor(half / 12) + letter, half });
      }
      return notes;
    }
    const shape = recipe.arpeggio ? CHORDS[chordOf(kind)]! : SCALES[kind] ?? SCALES.major!;
    for (let o = 0; o < octaves; o++) shape.half.forEach((h, k) => notes.push({ step: root.step + 7 * o + shape.letters[k]!, half: root.half + 12 * o + h }));
    notes.push({ step: root.step + 7 * octaves, half: root.half + 12 * octaves });
    return notes;
  };
  const kind = recipe.arpeggio ? recipe.kind : SCALES[recipe.kind] ? recipe.kind : 'major';
  const up = run(kind, false);
  const downKind = (!recipe.arpeggio && SCALES[kind]?.down) || kind;
  const downward = run(downKind, true).reverse();
  const notes = recipe.way === 'up' ? up : recipe.way === 'down' ? downward : [...up, ...downward.slice(1)];
  // Accidentals as written: what the signature and the run so far leave a letter in its octave.
  const signature = signatureOf(sharps);
  const shown = new Map<number, number>();
  return notes
    .map(({ step, half }) => {
      const letter = ((step % 7) + 7) % 7;
      const octaveOf = Math.floor(step / 7);
      const accidental = half - (12 * octaveOf + NATURAL[letter]!);
      const current = shown.get(step) ?? signature[letter]!;
      shown.set(step, accidental);
      return `${'CDEFGAB'[letter]}${accidental === current ? '' : SIGNS[accidental] ?? ''}${octaveOf}`;
    })
    .join('/');
}

/**
 * The octave for a key note with none typed: up, the nearest below the
 * staff's middle line `middle` (a diatonic step from C0); down, the nearest
 * from it up; half an octave further for each octave more.
 */
export function tonicOctave(letter: number, middle: number, way: Recipe['way'], octaves: number): number {
  const shift = 3.5 * (octaves - 1);
  return way === 'down' ? Math.ceil((middle + shift - letter) / 7) : Math.ceil((middle - shift - letter) / 7) - 1;
}
