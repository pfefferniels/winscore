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

