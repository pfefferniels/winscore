// The literal values in a command, which a decision model cannot write
// itself: its numbers, and note names typed as music ("c g d/f/a",
// "f#4 bb e"). They become candidates the models choose between, as Jev's
// pre-parsed extraction pattern has it; what the command means is left to
// the models.

/** The numbers in the text, as written ("1.5", "-2", "50%" as 0.5). */
export function numbersIn(text: string): number[] {
  return Array.from(text.matchAll(/(^|[^\w.])(-?\d+(?:\.\d+)?)(%?)/g), (m) => Number(m[2]) / (m[3] ? 100 : 1));
}

/** A note name as typed: letter, accidental (#, b, x, s, n, is, es, ♯, ♭, ♮), octave. */
const PITCH = /^([a-g])(##|bb|is|es|#|b|x|s|n|♯♯|♭♭|♯|♭|♮)?(\d)?$/i;

const ACCIDENTALS: Record<string, string> = { '#': 'S', is: 'S', s: 'S', '♯': 'S', b: 'F', es: 'F', '♭': 'F', n: 'N', '♮': 'N', '##': 'SS', x: 'SS', '♯♯': 'SS', bb: 'FF', '♭♭': 'FF' };

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
}

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
  let best = { start: 0, end: 0 };
  let start = -1;
  for (let i = 0; i <= words.length; i++) {
    const element = i < words.length ? scoreElement(words[i]!) : null;
    if (element !== null && start < 0) start = i;
    if (element === null && start >= 0) {
      if (i - start > best.end - best.start) best = { start, end: i };
      start = -1;
    }
  }
  if (best.end === best.start) return null;
  const run = words.slice(best.start, best.end);
  // A lone "a" or "b" is as likely an article as a note.
  if (run.length === 1 && /^[ab]$/i.test(run[0]!)) return null;
  const elements = run.map((w) => scoreElement(w)!);
  const first = elements.findIndex((e) => /^[A-G]/.test(e));
  if (first >= 0 && !/\d/.test(elements[first]!.split(':')[0]!)) {
    const [head, ...rest] = elements[first]!.split(':');
    elements[first] = [`${head}${octaveNear(head!.charAt(0), middle)}`, ...rest].join(':');
  }
  // Octaves typed after the first note mean every octave is meant as typed.
  const explicit = run.slice(first + 1).some((w) => /\d/.test(w));
  if (first >= 0 && !explicit) elements[first] = `P${elements[first]}`;
  return { typed: run.join(' '), notes: elements.join('/'), count: elements.filter((e) => e !== 'M').length };
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
