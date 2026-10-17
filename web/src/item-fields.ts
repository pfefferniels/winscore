// What the side panel offers for each kind of item: its parameters as named
// settings in groups, each with a control that fits what it holds (a list of
// clef types, stem up or down, a pitch), read from and written back into
// SCORE's packed numbers as the WinScore help (analysis/docs/text/winscore/
// code*.txt) and the renderer (rust/crates/score-render/src/codes) read them.
// Every parameter, with or without a setting here, is also in the panel's
// list of all parameters.

/** Parameter n (1-based) of the item; unset parameters read as 0. */
export type P = (n: number) => number;

/** Parameter n and its new value. */
export type Change = [n: number, value: number];

/** What a setting needs from the rest of the score. */
export interface Context {
  /** P4 and P5 of the clef in force at a note, null for none (treble). */
  clef: { p4: number; p5: number } | null;
  /** Name of library symbol `n`, if it has one. */
  symbolName(n: number): string | null;
}

interface Base {
  /** Element id, kept across re-renders so the keyboard stays in the control. */
  id: string;
  label: string;
  /** Explanation for the tooltip. */
  help?: string;
  /** Shown only when this holds. */
  when?: (p: P) => boolean;
}

export interface NumberSetting extends Base {
  kind: 'number';
  get(p: P): number;
  set(value: number, p: P): Change[];
  /** What ↑/↓ add (Shift: ten times as much). */
  step: number;
  /** A reading of the value or its unit, shown under the field. */
  note?(value: number, p: P, ctx: Context): string | null;
  /** A button next to the field that picks the value in a dialog. */
  pick?: 'symbol';
}

export interface ChoiceSetting extends Base {
  kind: 'choice';
  options: { value: number; label: string }[];
  get(p: P): number;
  set(value: number, p: P): Change[];
  /** Buttons side by side instead of a list. */
  buttons?: boolean;
  /** How a value that is not among the options reads. */
  other?(p: P): string;
}

export interface ToggleSetting extends Base {
  kind: 'toggle';
  get(p: P): boolean;
  set(on: boolean, p: P): Change[];
}

/** Typed text such as a pitch; ↑/↓ step it. */
export interface TextSetting extends Base {
  kind: 'text';
  show(p: P, ctx: Context): string;
  /** The changes for typed text, null when it cannot be read. */
  parse(text: string, p: P, ctx: Context): Change[] | null;
  step(delta: number, p: P, ctx: Context): Change[];
  note?(p: P, ctx: Context): string | null;
  placeholder?: string;
}

/** Two numbers on one row, such as the position and level of a line's end. */
export interface PairSetting extends Omit<Base, 'id'> {
  kind: 'pair';
  fields: [NumberSetting, NumberSetting];
}

export type Setting = NumberSetting | ChoiceSetting | ToggleSetting | TextSetting | PairSetting;

export interface Section {
  title: string;
  settings: Setting[];
}

// ---------------------------------------------------------------------------
// Building blocks

const near = (a: number, b: number) => Math.abs(a - b) <= 1e-4 + Math.abs(b) * 3e-3;

/** The decimal digit of |v| at `unit` (1, 10, 100 …). */
function digit(v: number, unit: number): number {
  return Math.floor(Math.abs(v) / unit + 1e-6) % 10;
}

/** `v` with that digit replaced; its sign and the other digits stay. */
function withDigit(v: number, unit: number, d: number): number {
  return v + (v < 0 ? -1 : 1) * (d - digit(v, unit)) * unit;
}

/** Notes, rests and clefs are cue size, or mini, with |P4| ≥ 100. */
const isSmall = (p4: number) => Math.abs(p4) >= 100;

/** P4 without the hundred of cue size. */
const level = (p4: number) => (isSmall(p4) ? p4 - 100 * Math.sign(p4) : p4);

/** A level as P4, cue size or not ("add 100, or -100 if P4 is negative"). */
const atLevel = (lvl: number, small: boolean) => (small ? lvl + (lvl < 0 ? -100 : 100) : lvl);

function number(n: number, label: string, more: Partial<NumberSetting> = {}): NumberSetting {
  return { kind: 'number', id: `p${n}`, label, step: 1, get: (p) => p(n), set: (v) => [[n, v]], ...more };
}

/** A number whose 0 stands for a default, said under the field. */
function defaulted(n: number, label: string, zero: string, more: Partial<NumberSetting> = {}): NumberSetting {
  return number(n, label, { step: 0.1, note: (v) => (v === 0 ? zero : null), ...more });
}

function choice(id: string, n: number, label: string, options: [number, string][], more: Partial<ChoiceSetting> = {}): ChoiceSetting {
  return {
    kind: 'choice',
    id,
    label,
    options: options.map(([value, label]) => ({ value, label })),
    get: (p) => p(n),
    set: (v) => [[n, v]],
    ...more,
  };
}

function toggle(id: string, n: number, label: string, on: number, more: Partial<ToggleSetting> = {}): ToggleSetting {
  return { kind: 'toggle', id, label, get: (p) => p(n) === on, set: (yes) => [[n, yes ? on : 0]], ...more };
}

/** The staff above or below the own one, in P12 (notes) or P17 (rests). */
function onStaff(n: number): ChoiceSetting {
  return choice(`f-on-staff`, n, 'Shown on', [[0, 'Own'], [1, 'Above'], [2, 'Below']], {
    buttons: true,
    help: 'Draws the item on the staff above or below the one it belongs to.',
  });
}

/** Cue or mini size: P4 ± 100. */
function smallSize(label: string, help: string): ToggleSetting {
  return {
    kind: 'toggle',
    id: 'f-small',
    label,
    help,
    get: (p) => isSmall(p(4)),
    set: (on, p) => [[4, atLevel(level(p(4)), on)]],
  };
}

/** P4 as a level on the staff, without the hundred of cue size. */
function levelSetting(label: string, more: Partial<NumberSetting> = {}): NumberSetting {
  return number(4, label, {
    help: 'Scale steps up from the staff’s reference level.',
    get: (p) => level(p(4)),
    set: (v, p) => [[4, atLevel(v, isSmall(p(4)))]],
    ...more,
  });
}

const STAFF = number(2, 'Staff', { help: 'The number of the staff the item belongs to.' });
const POSITION = number(3, 'Position', {
  help: 'Horizontal position: 0 at the left edge, 200 at the right edge of the staff.',
  step: 0.5,
});
const OFFSET = number(15, 'Offset', { help: 'Shifts the item horizontally without changing its position for Lineup and Justify.', step: 0.5 });

function placement(...more: Setting[]): Section {
  return { title: 'Placement', settings: [STAFF, POSITION, ...more] };
}

/** The ends of a line, slur or beam: position (P3, P6) and level (P4, P5). */
function ends(rightLevel = true): Setting[] {
  const end = number(6, 'position', { step: 0.5, help: 'Horizontal position of the right end.' });
  return [
    {
      kind: 'pair',
      label: 'Start',
      help: 'Horizontal position and level of the left end.',
      fields: [number(3, 'position', { step: 0.5 }), number(4, 'level')],
    },
    rightLevel
      ? { kind: 'pair', label: 'End', help: 'Horizontal position and level of the right end.', fields: [end, number(5, 'level')] }
      : { ...end, label: 'End' },
  ];
}

// ---------------------------------------------------------------------------
// Notes (code 1)

const ACCIDENTALS: [number, string][] = [
  [0, 'None'],
  [1, '♭ Flat'],
  [2, '♯ Sharp'],
  [3, '♮ Natural'],
  [4, '♭♭ Double flat'],
  [5, '♯♯ Double sharp'],
  [6, '¼ tone flat'],
  [7, '¾ tone flat'],
  [8, '¼ tone sharp'],
  [9, '¾ tone sharp'],
];
const ACCIDENTAL_SIGNS = ['', '♭', '♯', '♮', '♭♭', '♯♯', '¼♭', '¾♭', '¼♯', '¾♯'];

/** Steps from treble levels to the clef's, by clef type (as score-web's preview counts them). */
const CLEF_SHIFT = [0, 12, 6, 8, 0];

/** How far a clef moves note levels: its type's shift and its own level (P4 -2 makes a baritone clef). */
function clefShift(ctx: Context): number {
  if (!ctx.clef) return 0;
  const type = Math.trunc(Math.abs(ctx.clef.p5));
  return (CLEF_SHIFT[type] ?? 0) + Math.round(level(ctx.clef.p4));
}

const LETTERS = 'CDEFGAB';

/** Diatonic steps from C0 of a note level; C4 is level 1 in the treble clef. */
const stepOf = (lvl: number, ctx: Context) => Math.round(lvl) - clefShift(ctx) + 27;

function pitchName(p: P, ctx: Context): string {
  const step = stepOf(level(p(4)), ctx);
  const letter = LETTERS[((step % 7) + 7) % 7];
  const sign = ACCIDENTAL_SIGNS[digit(p(5), 1)] ?? '';
  const shown = sign && digit(p(5), 100) === 1 ? `(${sign})` : sign;
  return `${letter}${shown}${Math.floor(step / 7)}`;
}

const ACCIDENTAL_WORDS: Record<string, number> = { '': 0, b: 1, '♭': 1, '#': 2, '♯': 2, s: 2, n: 3, '♮': 3, bb: 4, '♭♭': 4, '##': 5, x: 5, '♯♯': 5, ss: 5 };

/** "F#4", "Bb3", "c5", or a letter alone for the nearest one: P4 and the accidental in P5. */
function parsePitch(text: string, p: P, ctx: Context): Change[] | null {
  const match = /^\s*([a-g])\s*(bb|b|♭♭|♭|##|#|♯♯|♯|x|ss|s|n|♮)?\s*(-?\d)?\s*$/i.exec(text);
  if (!match) return null;
  const accidental = ACCIDENTAL_WORDS[(match[2] ?? '').toLowerCase()] ?? 0;
  const letter = LETTERS.indexOf(match[1]!.toUpperCase());
  const current = stepOf(level(p(4)), ctx);
  let step: number;
  if (match[3] !== undefined) step = 7 * Number(match[3]) + letter;
  else {
    const below = current - (((current - letter) % 7) + 7) % 7;
    step = current - below <= 3 ? below : below + 7;
  }
  const lvl = step - 27 + clefShift(ctx);
  return [
    [4, atLevel(lvl, isSmall(p(4)))],
    [5, withDigit(p(5), 1, accidental)],
  ];
}

const ORDINALS = ['', '1st', '2nd', '3rd', '4th'];

/** Where a level lies on a five-line staff, e.g. "middle line", "2 ledger lines below". */
export function staffPlace(lvl: number): string {
  const l = Math.round(lvl);
  if (l === 3) return 'bottom line';
  if (l === 7) return 'middle line';
  if (l === 11) return 'top line';
  if (l > 3 && l < 11) return (l - 3) % 2 === 0 ? `${ORDINALS[(l - 3) / 2 + 1]} line` : `${ORDINALS[(l - 2) / 2]} space`;
  const beyond = l < 3 ? 3 - l : l - 11;
  const side = l < 3 ? 'below' : 'above';
  const lines = Math.floor(beyond / 2);
  const plural = lines === 1 ? '' : 's';
  if (beyond % 2 === 0) return `${lines} ledger line${plural} ${side}`;
  return lines === 0 ? `just ${side} the staff` : `${side} ${lines} ledger line${plural}`;
}

const PITCH: TextSetting = {
  kind: 'text',
  id: 'f-pitch',
  label: 'Pitch',
  placeholder: 'e.g. F#4',
  help: 'Type a note name such as F#4, Bb3 or C5 (a letter alone picks the nearest one); ↑/↓ move the note a step. Read in the clef in force.',
  show: pitchName,
  parse: parsePitch,
  step: (delta, p) => [[4, atLevel(level(p(4)) + delta, isSmall(p(4)))]],
  note: (p) => `${staffPlace(level(p(4)))} · level ${level(p(4))}`,
};

/** Note and rest values in quarters (P7), with what notes draw for them. */
const VALUES = [
  { quarters: 8, name: 'Breve', head: 3, tails: 0, rest: -3 },
  { quarters: 4, name: 'Whole', head: 2, tails: 0, rest: -2 },
  { quarters: 2, name: 'Half', head: 1, tails: 0, rest: -1 },
  { quarters: 1, name: 'Quarter', head: 0, tails: 0, rest: 0 },
  { quarters: 0.5, name: 'Eighth', head: 0, tails: 1, rest: 1 },
  { quarters: 0.25, name: '16th', head: 0, tails: 2, rest: 2 },
  { quarters: 0.125, name: '32nd', head: 0, tails: 3, rest: 3 },
  { quarters: 0.0625, name: '64th', head: 0, tails: 4, rest: 4 },
  { quarters: 0.03125, name: '128th', head: 0, tails: 5, rest: 5 },
];
const DOT_FACTOR = [1, 1.5, 1.75, 1.875];
const TUPLETS: [number, string][] = [
  [1, 'None'],
  [2 / 3, 'Triplet (3 in 2)'],
  [4 / 5, 'Quintuplet (5 in 4)'],
  [4 / 7, 'Septuplet (7 in 4)'],
  [3 / 2, 'Duplet (2 in 3)'],
];

/** P7 of 64 and more: a grace note (RHG writes 65). */
const GRACE = 64;
const GRACE_VALUE = -1;

interface Rhythm {
  value: number;
  tuplet: number;
}

/** The value and tuplet that make `quarters` with `dots` dots, if any do. */
function rhythmOf(quarters: number, dots: number): Rhythm | null {
  for (const [tuplet] of TUPLETS) {
    const value = VALUES.findIndex((v) => near(quarters, v.quarters * (DOT_FACTOR[dots] ?? 1) * tuplet));
    if (value >= 0) return { value, tuplet };
  }
  return null;
}

const noteDots = (p: P) => digit(p(9), 10);
const noteRhythm = (p: P) => rhythmOf(p(7), noteDots(p)) ?? rhythmOf(p(7), 0);

/** Duration in words, e.g. "dotted eighth", "triplet 16th". */
function durationWords(quarters: number, dots: number): string | null {
  const rhythm = rhythmOf(quarters, dots);
  if (!rhythm) return null;
  const tuplet = TUPLETS.find(([f]) => f === rhythm.tuplet)![1].split(' ')[0]!.toLowerCase();
  const dotted = ['', 'dotted ', 'double-dotted ', 'triple-dotted '][dots] ?? '';
  return `${dotted}${rhythm.tuplet === 1 ? '' : `${tuplet} `}${VALUES[rhythm.value]!.name.toLowerCase()}`;
}

/** P6 holds a plain head of a value (0–3, +10 in parentheses). */
const plainHead = (p6: number) => p6 >= 0 && p6 < 20 && p6 % 10 <= 3;

/**
 * A new value for a note: P7 keeps its dots and tuplet; a plain head follows
 * the value; tails follow it too, unless the note has none where its value
 * would (it is beamed).
 */
function setNoteValue(index: number, p: P): Change[] {
  if (index === GRACE_VALUE) {
    return [
      [4, atLevel(level(p(4)), true)],
      [7, 65],
      [8, 101],
      [9, 1],
    ];
  }
  const value = VALUES[index]!;
  const wasGrace = p(7) >= GRACE;
  const rhythm = wasGrace ? null : noteRhythm(p);
  const dots = wasGrace ? 0 : noteDots(p);
  const changes: Change[] = [[7, value.quarters * DOT_FACTOR[dots]! * (rhythm?.tuplet ?? 1)]];
  if (plainHead(p(6))) changes.push([6, (p(6) >= 10 ? 10 : 0) + value.head]);
  const beamed = rhythm !== null && VALUES[rhythm.value]!.tails > 0 && digit(p(9), 1) === 0;
  if (!beamed) changes.push([9, withDigit(wasGrace ? 0 : p(9), 1, value.tails)]);
  if (wasGrace) changes.push([4, level(p(4))], [8, 0]);
  return changes;
}

const NOTE_VALUE: ChoiceSetting = {
  kind: 'choice',
  id: 'f-value',
  label: 'Value',
  help: 'Sets the duration, the head and the tails together, as the RH commands do; dots and tuplet stay. Beamed notes get no tails.',
  options: [...VALUES.map((v, i) => ({ value: i, label: v.name })), { value: GRACE_VALUE, label: 'Grace note' }],
  get: (p) => (p(7) >= GRACE ? GRACE_VALUE : (noteRhythm(p)?.value ?? NaN)),
  set: setNoteValue,
  other: (p) => `Other (${p(7)} quarters)`,
};

const NOTE_DOTS: ChoiceSetting = {
  kind: 'choice',
  id: 'f-dots',
  label: 'Dots',
  buttons: true,
  help: 'Augmentation dots; the duration changes with them.',
  when: (p) => p(7) > 0 && p(7) < GRACE,
  options: [
    { value: 0, label: 'None' },
    { value: 1, label: '1' },
    { value: 2, label: '2' },
  ],
  get: noteDots,
  set: (dots, p) => [
    [7, (p(7) / DOT_FACTOR[noteDots(p)]!) * DOT_FACTOR[dots]!],
    [9, withDigit(p(9), 10, dots)],
  ],
};

function tupletSetting(dotsOf: (p: P) => number): ChoiceSetting {
  return {
    kind: 'choice',
    id: 'f-tuplet',
    label: 'Tuplet',
    help: 'Shortens or lengthens the duration as in a tuplet. The bracket or number is a slur or beam item of its own.',
    when: (p) => p(7) > 0 && p(7) < GRACE && rhythmOf(p(7), dotsOf(p)) !== null,
    options: TUPLETS.map(([value, label]) => ({ value, label })),
    get: (p) => rhythmOf(p(7), dotsOf(p))?.tuplet ?? NaN,
    set: (tuplet, p) => {
      const rhythm = rhythmOf(p(7), dotsOf(p))!;
      return [[7, VALUES[rhythm.value]!.quarters * DOT_FACTOR[dotsOf(p)]! * tuplet]];
    },
  };
}

function durationSetting(dotsOf: (p: P) => number): NumberSetting {
  return number(7, 'Duration', {
    step: 0.25,
    help: 'Rhythmic value in quarter notes (1 = quarter, 0.5 = eighth), used for spacing, Lineup and Justify. -1 leaves the item out of Justify.',
    note: (v, p) => {
      if (v >= GRACE) return 'quarters · grace note';
      if (v === -1) return 'ignored by Justify';
      if (v === -2) return 'no ledger lines';
      if (v === -3) return 'ignored by Justify, no ledger lines';
      const words = durationWords(v, dotsOf(p));
      return words ? `quarters · ${words}` : 'quarters';
    },
  });
}

const STEM_LENGTH = number(8, 'Stem length', {
  step: 0.5,
  help: 'Scale steps longer (+) or shorter (−) than the normal octave. ADJ fits it to a beam.',
  get: (p) => (Math.abs(p(8)) >= 100 ? p(8) - 100 * Math.sign(p(8)) : p(8)),
  set: (v, p) => [[8, Math.abs(p(8)) >= 100 ? v + (v < 0 ? -100 : 100) : v]],
  note: (v) => (v === 0 ? 'normal' : 'steps'),
});

const SLASHED: ToggleSetting = {
  kind: 'toggle',
  id: 'f-slash',
  label: 'Slashed',
  help: 'A slash through the tail of a grace note.',
  when: (p) => isSmall(p(4)),
  get: (p) => Math.abs(p(8)) >= 100,
  set: (on, p) => {
    const length = Math.abs(p(8)) >= 100 ? p(8) - 100 * Math.sign(p(8)) : p(8);
    return [[8, on ? length + (length < 0 ? -100 : 100) : length]];
  },
};

const HEADS: [number, string][] = [
  [0, 'Black'],
  [1, 'Half (white)'],
  [2, 'Whole'],
  [3, 'Breve'],
  [4, 'White diamond'],
  [5, 'Black diamond'],
  [6, 'X'],
  [7, 'None (headless)'],
  [8, 'Diamond / X'],
  [9, 'Oval / X'],
];

const NOTE_HEAD: ChoiceSetting = {
  kind: 'choice',
  id: 'f-head',
  label: 'Head',
  help: 'The note head’s shape. A library symbol number from 20 on draws that symbol; negative numbers are tablature.',
  options: HEADS.map(([value, label]) => ({ value, label })),
  get: (p) => (p(6) === -1 ? 7 : p(6) >= 0 && p(6) < 20 ? p(6) % 10 : NaN),
  set: (head, p) => [[6, (p(6) >= 10 && p(6) < 20 ? 10 : 0) + head]],
  other: (p) => (p(6) < 0 ? `Tablature (${-p(6)} strings)` : `Symbol ${p(6)}`),
};

const MARKS: [number, string][] = [
  [0, 'None'],
  [5, 'Accent'],
  [6, 'Tenuto'],
  [7, 'Staccato'],
  [4, 'Wedge'],
  [19, 'Heavy wedge'],
  [8, 'Wedge + staccato'],
  [9, 'Accent + staccato'],
  [10, 'Tenuto + staccato'],
  [25, 'Accent + tenuto'],
  [14, 'Fermata'],
  [11, 'Down bow'],
  [12, 'Up bow'],
  [13, 'Harmonic'],
  [17, 'Mordent'],
  [18, 'Inverted mordent'],
  [20, 'Trill'],
  [21, 'Trill with flat'],
  [22, 'Trill with sharp'],
  [23, 'Trill with natural'],
  [24, 'Plus'],
  [15, 'Arsis'],
  [16, 'Thesis'],
  [1, 'Ficta flat'],
  [2, 'Ficta sharp'],
  [3, 'Ficta natural'],
  ...Array.from({ length: 6 }, (_, i): [number, string] => [30 + i, `Fingering ${i}`]),
  ...Array.from({ length: 4 }, (_, i): [number, string] => [41 + i, `Tremolo, ${i + 1} stroke${i ? 's' : ''}`]),
  [99, 'Heavy line to the right'],
];

/** The mark number of P11, without the side (sign) and the shift (decimals). */
const markOf = (p: P) => Math.trunc(Math.abs(p(11)) + 1e-6);

const MARK: ChoiceSetting = {
  kind: 'choice',
  id: 'f-mark',
  label: 'Mark',
  help: 'A mark at the note: accent, staccato, fermata, fingering …',
  options: MARKS.map(([value, label]) => ({ value, label })),
  get: markOf,
  set: (mark, p) => {
    const rest = Math.abs(p(11)) - markOf(p);
    return [[11, mark === 0 ? 0 : (p(11) < 0 ? -1 : 1) * (mark + rest)]];
  },
  other: (p) => `Mark ${markOf(p)}`,
};

const hasMark = (p: P) => markOf(p) !== 0;

const NOTE_SECTIONS: Section[] = [
  {
    title: 'Note',
    settings: [
      PITCH,
      {
        kind: 'choice',
        id: 'f-accidental',
        label: 'Accidental',
        options: ACCIDENTALS.map(([value, label]) => ({ value, label })),
        get: (p) => digit(p(5), 1),
        set: (d, p) => [[5, withDigit(p(5), 1, d)]],
      },
      {
        kind: 'toggle',
        id: 'f-accidental-paren',
        label: 'Parenthesised',
        help: 'Parentheses around the accidental.',
        when: (p) => digit(p(5), 1) !== 0,
        get: (p) => digit(p(5), 100) === 1,
        set: (on, p) => [[5, withDigit(p(5), 100, on ? 1 : 0)]],
      },
      {
        kind: 'choice',
        id: 'f-stem',
        label: 'Stem',
        buttons: true,
        help: 'In a chord only the note at the stem’s end has a stem: the top note when it points down, the bottom one when up.',
        options: [
          { value: 0, label: 'None' },
          { value: 1, label: 'Up' },
          { value: 2, label: 'Down' },
        ],
        get: (p) => digit(p(5), 10),
        set: (d, p) => [[5, withDigit(p(5), 10, d)]],
      },
      { ...STEM_LENGTH, when: (p) => digit(p(5), 10) !== 0 },
      NOTE_HEAD,
      {
        kind: 'toggle',
        id: 'f-head-paren',
        label: 'Head in ( )',
        help: 'Parentheses around the note head.',
        when: (p) => p(6) >= 0 && p(6) < 20,
        get: (p) => p(6) >= 10,
        set: (on, p) => [[6, (p(6) % 10) + (on ? 10 : 0)]],
      },
    ],
  },
  {
    title: 'Rhythm',
    settings: [
      NOTE_VALUE,
      NOTE_DOTS,
      tupletSetting(noteDots),
      durationSetting(noteDots),
      smallSize('Cue size', 'Draws the note smaller; grace notes are cue size too.'),
      SLASHED,
    ],
  },
  {
    title: 'Mark',
    settings: [
      MARK,
      {
        kind: 'toggle',
        id: 'f-mark-side',
        label: 'On stem side',
        help: 'Puts the mark at the end of the stem instead of at the head.',
        when: hasMark,
        get: (p) => p(11) < 0,
        set: (on, p) => [[11, on ? -Math.abs(p(11)) : Math.abs(p(11))]],
      },
      {
        kind: 'pair',
        label: 'Shift',
        help: 'Moves the mark from its default place, in steps; right 99 centres it on the stem.',
        when: hasMark,
        fields: [number(13, 'right', { step: 0.5 }), number(14, 'up', { step: 0.5 })],
      },
      defaulted(18, 'Mark size', 'default', { when: hasMark }),
    ],
  },
  placement(
    number(10, 'Offset', {
      step: 0.5,
      help: 'Moves the head sideways without changing its position for Lineup and Justify, for seconds in chords and for voices: 10 one head width right, 20 left; −9.9 to 9.9 in steps.',
      note: (v) => (v === 10 ? 'one head width right' : v === 20 ? 'one head width left' : v === 110 ? 'right, with the accidental' : null),
    }),
    onStaff(12),
    defaulted(15, 'Size', 'normal (1)'),
    defaulted(20, 'Width', 'normal (1)'),
  ),
];

// ---------------------------------------------------------------------------
// Rests (code 2)

const REST_TYPES: [number, string][] = [
  ...VALUES.slice(0, 3).map((v): [number, string] => [v.rest, v.name]),
  ...VALUES.slice(3).map((v): [number, string] => [v.rest, v.name]),
  [6, '256th'],
  [-4, 'Repeat-bar sign'],
  [-44, 'Two-bar repeat'],
  [-5, 'Bar rest (stretched)'],
  [-6, 'Two-bar rest'],
  [-7, 'Four-bar rest'],
  ...Array.from({ length: 9 }, (_, i): [number, string] => [-11 - i, `Bar rest, ${i + 1} bar${i ? 's' : ''} (European)`]),
];

/** The rest type of P5, without the hundred of parentheses. */
const restType = (p: P) => (Math.abs(p(5)) >= 100 ? Math.trunc(p(5)) % 100 : Math.trunc(p(5)));
const restDots = (p: P) => (p(6) > 0 && p(6) <= 3 ? p(6) : 0);
const restValue = (p: P) => VALUES.find((v) => v.rest === restType(p)) ?? null;

const REST_SECTIONS: Section[] = [
  {
    title: 'Rest',
    settings: [
      {
        kind: 'choice',
        id: 'f-rest',
        label: 'Rest',
        help: 'The rest symbol. For note values the duration follows, keeping dots and tuplet; a whole rest for a full bar may need the bar’s length as its duration.',
        options: REST_TYPES.map(([value, label]) => ({ value, label })),
        get: restType,
        set: (type, p) => {
          const parens = Math.abs(p(5)) >= 100 ? (type < 0 ? -100 : 100) : 0;
          const changes: Change[] = [[5, type + parens]];
          const value = VALUES.find((v) => v.rest === type);
          if (value) {
            const tuplet = rhythmOf(p(7), restDots(p))?.tuplet ?? 1;
            changes.push([7, value.quarters * DOT_FACTOR[restDots(p)]! * tuplet]);
          }
          return changes;
        },
        other: (p) => `Type ${restType(p)}`,
      },
      {
        kind: 'choice',
        id: 'f-dots',
        label: 'Dots',
        buttons: true,
        when: (p) => p(6) >= 0 && p(6) <= 3 && restValue(p) !== null,
        options: [
          { value: 0, label: 'None' },
          { value: 1, label: '1' },
          { value: 2, label: '2' },
        ],
        get: restDots,
        set: (dots, p) => [
          [6, dots],
          [7, (p(7) / DOT_FACTOR[restDots(p)]!) * DOT_FACTOR[dots]!],
        ],
      },
      { ...tupletSetting(restDots), when: (p) => restValue(p) !== null && p(7) > 0 && rhythmOf(p(7), restDots(p)) !== null },
      durationSetting(restDots),
      toggle('f-invisible', 6, 'Invisible', -1, {
        help: 'Takes up its space but is not printed; grey on the screen.',
      }),
      {
        kind: 'toggle',
        id: 'f-rest-paren',
        label: 'Parenthesised',
        get: (p) => Math.abs(p(5)) >= 100,
        set: (on, p) => [[5, on ? restType(p) + (restType(p) < 0 ? -100 : 100) : restType(p)]],
      },
      {
        kind: 'toggle',
        id: 'f-centred',
        label: 'Centred in bar',
        help: 'Centres a whole rest or longer between its barlines (CW).',
        when: (p) => restType(p) <= -2 && restType(p) !== -5,
        get: (p) => p(9) !== 0,
        set: (on) => [[9, on ? -1 : 0]],
      },
      number(9, 'Right end', { step: 0.5, help: 'Where the stretched bar rest ends.', when: (p) => restType(p) === -5 }),
    ],
  },
  {
    title: 'Above the rest',
    settings: [
      {
        kind: 'choice',
        id: 'f-over',
        label: 'Shows',
        options: [
          { value: 0, label: 'Nothing' },
          { value: -1, label: 'Fermata' },
          { value: -2, label: 'Fermata below' },
          { value: 1, label: 'Number' },
        ],
        get: (p) => (p(8) > 0 ? 1 : p(8)),
        set: (v, p) => [[8, v === 1 ? Math.max(1, p(8)) : v]],
        other: (p) => `Other (${p(8)})`,
      },
      number(8, 'Number', { help: 'The number over a multi-bar rest.', when: (p) => p(8) > 0 }),
      number(11, 'Height', { step: 0.5, when: (p) => p(8) !== 0 }),
      defaulted(12, 'Size', 'default', { when: (p) => p(8) !== 0 }),
    ],
  },
  placement(
    levelSetting('Level', { note: (v) => (v === 0 ? 'default' : null) }),
    number(10, 'Offset', { step: 0.5, help: 'Moves the rest sideways without changing its position for Lineup and Justify, for several voices on a staff.' }),
    onStaff(17),
    smallSize('Cue size', 'Draws the rest smaller.'),
    defaulted(15, 'Size', 'normal (1)'),
  ),
];

// ---------------------------------------------------------------------------
// Clefs (code 3)

const CLEF_TYPES: [number, string][] = [
  [0, 'Treble'],
  [1, 'Bass'],
  [2, 'Alto'],
  [3, 'Tenor'],
  [4, 'Percussion'],
  [0.8, 'Treble, 8 below'],
  [0.88, 'Treble, 8 above'],
  [0.15, 'Treble, 15 above'],
  [1.8, 'Bass, 8 below'],
  [44, 'Tablature, 4 lines'],
  [55, 'Tablature, 5 lines'],
  [66, 'Tablature, 6 lines'],
];

const CLEF_SECTIONS: Section[] = [
  {
    title: 'Clef',
    settings: [
      choice('f-clef', 5, 'Clef', CLEF_TYPES, { other: (p) => `Type ${p(5)}` }),
      smallSize('Small', 'A smaller clef, as for a clef change within the line.'),
      levelSetting('Level', {
        help: 'Moves the clef up or down in scale steps: a bass clef at -2 is a baritone clef, an alto clef at -4 a soprano clef.',
        note: (v) => (v === 0 ? 'normal' : null),
      }),
      defaulted(6, 'Size', 'normal (1)'),
      defaulted(7, 'Height', 'as size'),
    ],
  },
  placement(OFFSET),
];

// ---------------------------------------------------------------------------
// Lines and hairpins (code 4)

const HAIRPIN = 999;
const CRESCENDO = 1000;
const DECRESCENDO = 1001;
const isHairpin = (p: P) => p(5) === HAIRPIN;
const isDashed = (p: P) => !isHairpin(p) && ((p(7) >= 1 && p(7) <= 99) || p(7) === -4);

const LINE_TYPES: [number, string][] = [
  [0, 'Line'],
  [1, 'Dashed'],
  [-4, 'Dotted'],
  [-1, 'Wavy, heavy'],
  [-2, 'Wavy, thin'],
  [-3, 'Sawtooth'],
  [-5, 'Vertical'],
  [CRESCENDO, 'Crescendo hairpin'],
  [DECRESCENDO, 'Decrescendo hairpin'],
];

/** The default opening of a hairpin, in scale steps (P7 = 0 or -1). */
const OPENING = 2.3;

/** Bracket (up to 100 steps, negative downward; from 200 downward) or arrow (100 + spread) at a line's end. */
const NO_MARK = 0;
const BRACKET_UP = 1;
const BRACKET_DOWN = 2;
const ARROW = 3;

function endMark(v: number): number {
  if (v === 0) return NO_MARK;
  if (v > 0 && v <= 100) return BRACKET_UP;
  if (v > 100 && v < 200) return ARROW;
  return BRACKET_DOWN;
}

function endMarkSize(v: number): number {
  switch (endMark(v)) {
    case BRACKET_UP:
      return v;
    case ARROW:
      return v - 100;
    case BRACKET_DOWN:
      return v < 0 ? -v : v - 200;
    default:
      return 0;
  }
}

function endMarkValue(mark: number, size: number): number {
  const s = Math.abs(size) || 2;
  return mark === BRACKET_UP ? s : mark === ARROW ? 100 + s : mark === BRACKET_DOWN ? -s : 0;
}

function endMarkSettings(n: number, label: string): Setting[] {
  return [
    {
      kind: 'choice',
      id: `f-mark-${n}`,
      label,
      when: (p) => !isHairpin(p),
      options: [
        { value: NO_MARK, label: 'Nothing' },
        { value: BRACKET_UP, label: 'Bracket up' },
        { value: BRACKET_DOWN, label: 'Bracket down' },
        { value: ARROW, label: 'Arrow' },
      ],
      get: (p) => endMark(p(n)),
      set: (mark, p) => [[n, endMarkValue(mark, endMarkSize(p(n)))]],
    },
    number(n, 'Length', {
      id: `f-mark-size-${n}`,
      step: 0.5,
      when: (p) => !isHairpin(p) && p(n) !== 0,
      get: (p) => endMarkSize(p(n)),
      set: (s, p) => [[n, endMarkValue(endMark(p(n)), s)]],
      note: () => 'steps',
    }),
  ];
}

const LINE_SECTIONS: Section[] = [
  {
    title: 'Line',
    settings: [
      {
        kind: 'choice',
        id: 'f-line',
        label: 'Type',
        options: LINE_TYPES.map(([value, label]) => ({ value, label })),
        get: (p) => {
          if (isHairpin(p)) return p(7) >= 0 ? CRESCENDO : DECRESCENDO;
          return isDashed(p) && p(7) !== -4 ? 1 : p(7);
        },
        set: (type, p) => {
          if (type === CRESCENDO || type === DECRESCENDO) {
            const open = isHairpin(p) ? (p(7) === 0 || p(7) === -1 ? OPENING : Math.abs(p(7))) : OPENING;
            const p7 = open === OPENING ? (type === CRESCENDO ? 0 : -1) : type === CRESCENDO ? open : -open;
            return [
              [5, HAIRPIN],
              [7, p7],
            ];
          }
          return [...(isHairpin(p) ? ([[5, p(4)]] as Change[]) : []), [7, type]];
        },
        other: (p) => (p(7) === 100 ? 'Multipoint line' : `Type ${p(7)}`),
      },
      number(7, 'Opening', {
        id: 'f-opening',
        step: 0.1,
        help: 'How far the hairpin opens, in scale steps.',
        when: isHairpin,
        get: (p) => (p(7) === 0 || p(7) === -1 ? OPENING : Math.abs(p(7))),
        set: (v, p) => {
          const crescendo = p(7) >= 0;
          if (near(v, OPENING)) return [[7, crescendo ? 0 : -1]];
          return [[7, crescendo ? v : -v]];
        },
        note: () => 'steps',
      }),
      toggle('f-hairpin-dashed', 11, 'Dashed', 1, { when: isHairpin }),
      {
        kind: 'pair',
        label: 'Dashes',
        help: 'Length of each dash (or dot size) and the space between them.',
        when: (p) => isDashed(p) || (isHairpin(p) && p(11) === 1),
        fields: [defaulted(8, 'length', 'default'), defaulted(9, 'space', 'default')],
      },
      defaulted(10, 'Thickness', 'normal'),
      number(13, 'Rotation', { help: 'Turns the line, in degrees (-90 makes a horizontal line vertical).', when: (p) => !isHairpin(p) }),
    ],
  },
  {
    title: 'Ends',
    settings: [
      {
        kind: 'pair',
        label: 'Start',
        help: 'Horizontal position and level of the left end.',
        fields: [number(3, 'position', { step: 0.5 }), number(4, 'level')],
      },
      {
        kind: 'pair',
        label: 'End',
        help: 'Horizontal position and level of the right end.',
        when: (p) => !isHairpin(p),
        fields: [number(6, 'position', { step: 0.5 }), number(5, 'level')],
      },
      number(6, 'End', { step: 0.5, help: 'Horizontal position of the right end.', when: isHairpin }),
      ...endMarkSettings(11, 'At start'),
      ...endMarkSettings(12, 'At end'),
    ],
  },
  { title: 'Placement', settings: [STAFF] },
];

// ---------------------------------------------------------------------------
// Slurs, ties, tuplet brackets and endings (code 5)

const SLUR = 0;
const TUPLET_BRACKET = 3;
const LATER_ENDING = 4;
const slurKind = (p: P) => {
  const p8 = Math.trunc(p(8));
  return p8 >= 1 && p8 <= 9 ? Math.min(p8, LATER_ENDING) : SLUR;
};
const isSlur = (p: P) => slurKind(p) === SLUR;

const SLUR_SECTIONS: Section[] = [
  {
    title: 'Curve',
    settings: [
      {
        kind: 'choice',
        id: 'f-slur',
        label: 'Type',
        options: [
          { value: SLUR, label: 'Slur or tie' },
          { value: TUPLET_BRACKET, label: 'Tuplet bracket' },
          { value: 1, label: '1st ending' },
          { value: 2, label: '2nd ending' },
          { value: LATER_ENDING, label: 'Later ending' },
        ],
        get: slurKind,
        set: (kind) => [[8, kind]],
      },
      number(7, 'Curvature', {
        step: 0.5,
        help: 'How high the curve rises, in scale steps; negative curves down. Flip turns it over.',
        when: isSlur,
        note: (v) => (v === 0 ? 'default' : v < 0 ? 'steps, curving down' : 'steps, curving up'),
      }),
      number(7, 'Height', { id: 'f-bracket-height', step: 0.5, help: 'Height of the bracket’s ends, in scale steps.', when: (p) => !isSlur(p) }),
      defaulted(9, 'Number', '3', { id: 'f-tuplet-number', step: 1, when: (p) => slurKind(p) === TUPLET_BRACKET, help: 'The tuplet number.' }),
      number(9, 'Number', { id: 'f-ending-number', help: 'The ending’s number.', when: (p) => slurKind(p) === LATER_ENDING }),
      {
        kind: 'choice',
        id: 'f-slur-line',
        label: 'Line',
        buttons: true,
        when: isSlur,
        options: [
          { value: 0, label: 'Solid' },
          { value: 1, label: 'Dashed' },
          { value: -1, label: 'Dotted' },
        ],
        get: (p) => Math.sign(p(11)),
        set: (v, p) => [[11, v * (Math.abs(p(11)) || 1)]],
      },
      number(11, 'Dashes', {
        id: 'f-slur-dashes',
        help: 'How many dashes or dots; 1 picks a number to suit the length.',
        when: (p) => isSlur(p) && p(11) !== 0,
        get: (p) => Math.abs(p(11)),
        set: (v, p) => [[11, Math.sign(p(11)) * Math.max(1, Math.abs(v))]],
        note: (v) => (v === 1 ? 'to suit the length' : null),
      }),
      defaulted(13, 'Thickness', 'default (0.75)', { when: isSlur }),
      defaulted(9, 'Flattening', 'none', { id: 'f-flatten', when: isSlur, help: 'Flattens long slurs; 99 makes a triangle.' }),
    ],
  },
  { title: 'Ends', settings: ends() },
  { title: 'Placement', settings: [STAFF] },
];

// ---------------------------------------------------------------------------
// Beams (code 6)

const isPlainBeam = (p: P) => p(7) > 0;

const BEAM_SECTIONS: Section[] = [
  {
    title: 'Beam',
    settings: [
      {
        kind: 'choice',
        id: 'f-stem',
        label: 'Stems',
        buttons: true,
        when: isPlainBeam,
        options: [
          { value: 1, label: 'Up' },
          { value: 2, label: 'Down' },
        ],
        get: (p) => digit(p(7), 10),
        set: (d, p) => [[7, withDigit(p(7), 10, d)]],
      },
      number(7, 'Beams', {
        id: 'f-beams',
        help: 'Number of full beams: 1 for eighths, 2 for 16ths …',
        when: isPlainBeam,
        get: (p) => digit(p(7), 1),
        set: (v, p) => [[7, withDigit(p(7), 1, Math.max(0, Math.min(9, Math.round(v))))]],
      }),
      number(8, 'Number', {
        id: 'f-beam-number',
        help: 'A tuplet number over the beam; 0 for none.',
        when: (p) => p(8) >= 0,
        get: (p) => p(8) % 1000,
        set: (v, p) => [[8, p(8) - (p(8) % 1000) + Math.max(0, Math.round(v))]],
        note: (v) => (v === 0 ? 'none' : null),
      }),
      defaulted(17, 'Thickness', 'normal'),
    ],
  },
  { title: 'Ends', settings: ends() },
  { title: 'Placement', settings: [STAFF] },
];

// ---------------------------------------------------------------------------
// Trills, ottavas and pedal marks (code 7)

const CODE7_TYPES: [number, string][] = [
  [0, 'Trill'],
  [8, '8va'],
  [-8, '8vb'],
  [15, '15ma'],
  [88, '8va with line'],
  [-88, '8vb with line'],
  [155, '15ma with line'],
  [21, 'Pedal line'],
  [22, 'Pedal line without dip'],
  [23, 'Ped.'],
  [24, 'Pedal release (✱)'],
  [25, 'Pedal (P)'],
  [1, 'Harp pedals'],
];

const CODE7_SECTIONS: Section[] = [
  {
    title: 'Mark',
    settings: [
      choice('f-code7', 7, 'Type', CODE7_TYPES, { other: () => 'Piano pedal diagram' }),
      choice('f-trill-accidental', 8, 'Accidental', ACCIDENTALS.slice(0, 6), {
        when: (p) => p(7) === 0,
        help: 'An accidental above the trill.',
      }),
      defaulted(5, 'Size', 'normal (1)'),
      defaulted(6, 'Line to', 'no line', { step: 0.5, help: 'Where the wavy, dashed or pedal line after the sign ends.' }),
    ],
  },
  placement(levelSetting('Level'), OFFSET),
];

// ---------------------------------------------------------------------------
// Staves (code 8)

const STAFF_SECTIONS: Section[] = [
  {
    title: 'Staff',
    settings: [
      number(2, 'Number', { help: 'The staff’s number; items name their staff by it.' }),
      defaulted(7, 'Lines', '5 lines', { step: 1 }),
      defaulted(5, 'Size', 'normal (1)', { help: 'Staff size; 1 is the normal size.' }),
      number(4, 'Vertical', { help: 'Moves the staff up or down, in scale steps.' }),
      toggle('f-staff-number', 12, 'Hide number', 1, { help: 'Hides the staff number shown on the screen next to the staff.' }),
    ],
  },
  {
    title: 'Extent',
    settings: [
      number(3, 'Left end', { step: 0.5 }),
      defaulted(6, 'Right end', 'full width (200)', { step: 0.5 }),
    ],
  },
  {
    title: 'Instrument',
    settings: [
      number(9, 'Instrument', { help: 'An ID used by part extraction and cueing.' }),
      number(13, 'Transposes', { help: 'Half steps the sound lies from the notes (for playback).', note: () => 'half steps' }),
    ],
  },
];

// ---------------------------------------------------------------------------
// Library symbols (code 9)

/** The hundreds of P6 of text and symbols: where part extraction puts the item. */
const partsOf = (p6: number) => Math.floor(Math.abs(p6) / 100 + 1e-6) * 100;

/** A size in P6 below its part-extraction hundreds; negative mirrors a symbol. */
function partSize(more: Partial<NumberSetting> = {}): NumberSetting {
  return defaulted(6, 'Size', 'normal (1)', {
    get: (p) => p(6) - Math.sign(p(6)) * partsOf(p(6)),
    set: (v, p) => [[6, (v < 0 ? -1 : 1) * (partsOf(p(6)) + Math.abs(v))]],
    ...more,
  });
}

const SYMBOL_SECTIONS: Section[] = [
  {
    title: 'Symbol',
    settings: [
      number(5, 'Symbol', {
        help: 'The symbol’s number in WinScore’s libraries; Choose shows them all.',
        pick: 'symbol',
        note: (v, _p, ctx) => ctx.symbolName(v),
      }),
      partSize({ help: 'Size factor; negative mirrors the symbol.' }),
      defaulted(7, 'Height', 'as size'),
      number(9, 'Rotation', { help: 'Clockwise, in degrees.', note: () => 'degrees' }),
    ],
  },
  placement(levelSetting('Level'), OFFSET),
];

// ---------------------------------------------------------------------------
// Numbers and rehearsal letters (code 10)

/** What a number item shows: 1001 is A, 2001 is a. */
function numberText(v: number): string {
  const letter = (from: number, base: string) => String.fromCharCode(base.charCodeAt(0) + Math.round(v) - from);
  if (v >= 1001 && v <= 1026) return `letter ${letter(1001, 'A')}`;
  if (v >= 2001 && v <= 2026) return `letter ${letter(2001, 'a')}`;
  return '';
}

const NUMBER_SECTIONS: Section[] = [
  {
    title: 'Number',
    settings: [
      number(5, 'Number', { help: 'The number; 1001… are the letters A…, 2001… a….', note: (v) => numberText(v) || null }),
      defaulted(6, 'Size', 'normal (1)'),
      choice('f-enclosure', 8, 'Enclosure', [
        [0, 'None'],
        [1, 'Circle'],
        [2, 'Box'],
      ], { buttons: true }),
      number(19, 'Rotation', { note: () => 'degrees' }),
    ],
  },
  placement(levelSetting('Level'), OFFSET),
];

// ---------------------------------------------------------------------------
// Boxes and circles (code 12)

/** Boxes, circles and dashed boxes; guitar grids and accordion symbols read their parameters otherwise. */
const isBox = (p: P) => [0, 1, 3].includes(p(5));

const BOX_SECTIONS: Section[] = [
  {
    title: 'Shape',
    settings: [
      choice('f-box', 5, 'Shape', [
        [0, 'Box'],
        [1, 'Circle'],
        [3, 'Dashed box'],
        [10, 'Guitar grid'],
      ], { other: (p) => (p(5) < 0 ? 'Accordion symbol' : `Shape ${p(5)}`) }),
      { kind: 'pair', label: 'Size', when: isBox, fields: [number(6, 'width', { step: 0.5 }), number(7, 'height', { step: 0.5 })] },
      defaulted(8, 'Thickness', 'normal', { when: isBox }),
      number(9, 'Rotation', { when: isBox, note: () => 'degrees' }),
      toggle('f-fill', 13, 'Filled', 1, { when: isBox }),
    ],
  },
  placement(levelSetting('Level'), OFFSET),
];

// ---------------------------------------------------------------------------
// Barlines, braces and brackets (code 14)

const BARLINE_TYPES: [number, string][] = [
  [0, 'Single'],
  [1, 'Double'],
  [2, 'Final'],
  [4, 'Start repeat'],
  [3, 'End repeat'],
  [5, 'End and start repeat'],
  [6, 'End and start repeat, two heavy'],
  [7, 'Dashed'],
  [-44, 'With two-bar repeat sign'],
  [8, 'Brace'],
  [9, 'Bracket'],
];

const BARLINE_SECTIONS: Section[] = [
  {
    title: 'Barline',
    settings: [
      choice('f-barline', 5, 'Type', BARLINE_TYPES, { other: (p) => `Type ${p(5)}` }),
      number(4, 'Staves', {
        help: 'How many staves it connects, from its own upward; 999 reaches the highest staff.',
        get: (p) => Math.abs(p(4)),
        set: (v, p) => [[4, p(4) < 0 ? -Math.abs(v) : Math.abs(v)]],
        note: (v) => (v === 999 ? 'up to the highest staff' : null),
      }),
      {
        kind: 'toggle',
        id: 'f-invisible',
        label: 'Invisible',
        help: 'Not printed, but still a barline for Lineup and Justify; dotted on the screen.',
        get: (p) => p(4) < 0,
        set: (on, p) => [[4, on ? -Math.abs(p(4)) : Math.abs(p(4))]],
      },
      defaulted(6, 'Thickness', 'normal', { help: 'Thicker lines show in print only.' }),
    ],
  },
  {
    title: 'Placement',
    settings: [
      number(2, 'Lowest staff', { help: 'The staff it starts from.' }),
      POSITION,
      number(7, 'Shift', { step: 0.5, help: 'Moves braces and brackets at the start of a system without changing their position for Lineup and Justify.' }),
    ],
  },
];

// ---------------------------------------------------------------------------
// Text (code 16)

const TEXT_SECTIONS: Section[] = [
  {
    title: 'Text',
    settings: [
      partSize({ help: 'Character size, relative to the staff’s size.' }),
      defaulted(7, 'Height', 'as size', { help: 'Vertical character size, for stretched letters.' }),
      {
        kind: 'choice',
        id: 'f-parts',
        label: 'In parts',
        help: 'Which parts the part extractor puts the text in, as for titles and tempo marks.',
        options: [
          { value: 0, label: 'Its staff’s part' },
          { value: 100, label: 'Every part' },
          { value: 200, label: 'No part' },
          { value: 300, label: 'Every part, size 1' },
        ],
        get: (p) => partsOf(p(6)),
        set: (parts, p) => [[6, p(6) - partsOf(p(6)) + parts]],
      },
      number(9, 'Rotation', { help: 'Clockwise, in degrees.', note: () => 'degrees' }),
      defaulted(5, 'Spacing', 'normal', { help: 'Spreads or tightens the characters.' }),
    ],
  },
  placement(levelSetting('Level')),
];

// ---------------------------------------------------------------------------
// Key signatures (code 17)

const MAJOR_SHARP = ['C', 'G', 'D', 'A', 'E', 'B', 'F♯', 'C♯'];
const MINOR_SHARP = ['A', 'E', 'B', 'F♯', 'C♯', 'G♯', 'D♯', 'A♯'];
const MAJOR_FLAT = ['C', 'F', 'B♭', 'E♭', 'A♭', 'D♭', 'G♭', 'C♭'];
const MINOR_FLAT = ['A', 'D', 'G', 'C', 'F', 'B♭', 'E♭', 'A♭'];

const KEYS: [number, string][] = Array.from({ length: 15 }, (_, i): [number, string] => {
  const k = 7 - i;
  const n = Math.abs(k);
  const [major, minor] = k >= 0 ? [MAJOR_SHARP[n], MINOR_SHARP[n]] : [MAJOR_FLAT[n], MINOR_FLAT[n]];
  const count = k === 0 ? 'None' : `${n} ${k > 0 ? '♯' : '♭'}`;
  return [k, `${count} · ${major} major / ${minor} minor`];
});

const keyCount = (p: P) => (Math.abs(p(5)) >= 100 ? Math.sign(p(5)) * (Math.abs(p(5)) - 100) : p(5));

const KEY_SECTIONS: Section[] = [
  {
    title: 'Key signature',
    settings: [
      {
        kind: 'choice',
        id: 'f-key',
        label: 'Key',
        help: 'Number of sharps (positive) or flats (negative).',
        options: KEYS.map(([value, label]) => ({ value, label })),
        get: keyCount,
        set: (k, p) => [[5, Math.abs(p(5)) >= 100 && k !== 0 ? k + 100 * Math.sign(k) : k]],
        other: (p) => `${keyCount(p)} accidentals`,
      },
      {
        kind: 'toggle',
        id: 'f-naturals',
        label: 'As naturals',
        help: 'Naturals in the places of these sharps or flats, to cancel a key.',
        when: (p) => keyCount(p) !== 0,
        get: (p) => Math.abs(p(5)) >= 100,
        set: (on, p) => {
          const k = keyCount(p);
          return [[5, on ? k + 100 * Math.sign(k) : k]];
        },
      },
      {
        kind: 'choice',
        id: 'f-key-clef',
        label: 'For clef',
        help: 'The clef whose lines the accidentals sit on.',
        options: CLEF_TYPES.slice(0, 4).map(([value, label]) => ({ value, label })),
        get: (p) => p(6) % 100,
        set: (c, p) => [[6, c + (p(6) >= 100 ? 100 : 0)]],
        other: (p) => `Clef ${p(6) % 100}`,
      },
      {
        kind: 'toggle',
        id: 'f-small',
        label: 'Cue size',
        get: (p) => p(6) >= 100,
        set: (on, p) => [[6, (p(6) % 100) + (on ? 100 : 0)]],
      },
      defaulted(7, 'Spacing', 'normal', { help: 'Space between the accidentals.' }),
    ],
  },
  placement(OFFSET),
];

// ---------------------------------------------------------------------------
// Meters (code 18)

const NUMBERS = 0;
const METER_SYMBOL = 91;
const meterKind = (p: P) => (p(5) === 99 || p(5) === 98 ? p(5) : p(5) >= METER_SYMBOL ? NaN : NUMBERS);
const hasNumbers = (p: P) => p(5) < METER_SYMBOL;

const METER_SECTIONS: Section[] = [
  {
    title: 'Meter',
    settings: [
      {
        kind: 'choice',
        id: 'f-meter',
        label: 'Shows',
        buttons: true,
        options: [
          { value: NUMBERS, label: 'Numbers' },
          { value: 99, label: 'C' },
          { value: 98, label: '¢' },
        ],
        get: meterKind,
        set: (kind) =>
          kind === NUMBERS
            ? [
                [5, 4],
                [6, 4],
              ]
            : [
                [5, kind],
                [6, 1],
              ],
        other: (p) => `Symbol ${p(5)}`,
      },
      { kind: 'pair', label: 'Meter', when: hasNumbers, help: 'Top and bottom number.', fields: [number(5, 'top'), number(6, 'bottom')] },
      {
        kind: 'pair',
        label: 'Added',
        when: hasNumbers,
        help: 'A second meter joined by a plus, as in 3/4 + 2/8; bottom 0 shares the first one’s.',
        fields: [number(8, 'top'), number(9, 'bottom')],
      },
      defaulted(7, 'Size', 'normal (1)'),
    ],
  },
  placement(OFFSET),
];

// ---------------------------------------------------------------------------

const BY_CODE: Record<number, Section[]> = {
  1: NOTE_SECTIONS,
  2: REST_SECTIONS,
  3: CLEF_SECTIONS,
  4: LINE_SECTIONS,
  5: SLUR_SECTIONS,
  6: BEAM_SECTIONS,
  7: CODE7_SECTIONS,
  8: STAFF_SECTIONS,
  9: SYMBOL_SECTIONS,
  10: NUMBER_SECTIONS,
  12: BOX_SECTIONS,
  14: BARLINE_SECTIONS,
  16: TEXT_SECTIONS,
  17: KEY_SECTIONS,
  18: METER_SECTIONS,
};

const GENERIC: Section[] = [placement(number(4, 'Level'))];

/** The settings of items with code `code`. */
export function sectionsFor(code: number): Section[] {
  return BY_CODE[code] ?? GENERIC;
}

/**
 * The settings that items of every one of `codes` have, the very same ones
 * (a staff, a position), in the first code's sections and order.
 */
export function sharedSections(codes: number[]): Section[] {
  const [first = GENERIC, ...rest] = codes.map(sectionsFor);
  const everywhere = (s: Setting) => rest.every((sections) => sections.some((section) => section.settings.includes(s)));
  return first
    .map((section) => ({ title: section.title, settings: section.settings.filter(everywhere) }))
    .filter((section) => section.settings.length > 0);
}

/** Whether a value matches an option, allowing for single precision (P5 = 0.88). */
export function sameValue(a: number, b: number): boolean {
  return a === b || Math.abs(a - b) < 1e-4;
}
