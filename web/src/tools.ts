// Insertion modes: one tool for each kind of item SCORE draws (its code,
// P1), chosen in the toolbar or with a key (N a note, S a slur or tie, T a
// text …). While one is chosen, a click on the page puts a new item there,
// on the staff nearest the pointer: P3 from where it is across, P4 from its
// height in scale steps, the other parameters from SCORE's defaults for its
// creation word (score-web's `creationParams`) and the options chosen in
// the toolbar. Slurs, ties, endings, lines, hairpins, beams, trills, ottavas
// and pedal lines are drawn from where the button went down to where it came
// up; a barline, brace or bracket from the staff it starts on to the one it
// ends on. The new item is selected, so the side panel shows every parameter
// it has, to be changed there.
import type { Place } from './editor';
import { DOT_FACTOR, noteName, VALUES } from './item-fields';

export interface Option {
  value: string;
  label: string;
  title?: string;
  /** SVG markup shown in place of the label. */
  icon?: string;
}

/** A choice a tool offers in the toolbar; `value` is the one in force. */
export interface Group {
  id: string;
  label: string;
  /** Buttons side by side, a list, a number field, or a button that opens a chooser (the symbol library). */
  kind: 'buttons' | 'select' | 'number' | 'choose';
  options: Option[];
  value: string;
}

/** What a tool reads of the score where it puts an item. */
export interface Facts {
  /** P1, P2 (0), P3, … that SCORE gives a new item of a creation word. */
  creation(word: string): number[] | null;
  /** P4 and P5 of the clef in force on a staff at a position, null for none (treble). */
  clefAt(staff: number, p3: number): { p4: number; p5: number } | null;
  /** The level of a staff's middle line: 7 on five lines. */
  middle(staff: number): number;
}

/**
 * How a tool takes a press on the page: at a point (where the button comes
 * up), along a span (from where it went down to where it came up, on the
 * staff it went down on), reaching from staff to staff, as text typed
 * where it was clicked, or as a new staff at that height.
 */
export type Shape = 'point' | 'span' | 'reach' | 'text' | 'staff';

/** What the preview draws under the pointer. */
export type Look = 'head' | 'mark' | 'arc-up' | 'arc-down' | 'bracket' | 'line' | 'dashed' | 'wedge-open' | 'wedge-close' | 'beam' | 'barline' | 'text' | 'staff';

export interface Tool {
  id: string;
  /** The key that chooses it (lower case, or a sign). */
  key: string;
  label: string;
  title: string;
  /** SVG markup of its toolbar button, drawn in a 24 × 24 box. */
  icon: string;
  /** P1 of what it makes. */
  code: number;
  shape: Shape;
  /** Which of its levels the pointer's height gives: P4 (and P5 at a span's end), P4 alone, or none (it sits at its usual height). */
  level: 'both' | 'start' | 'none';
  groups: Group[];
  /** What one is called in the undo step: "Insert tie". */
  noun(): string;
  /**
   * P1, P2, … of a new item at `from`; for a span its other end `to`, on
   * `from`'s staff (null for a click: SCORE's default length), for a reach
   * the place on the staff it reaches. Null when it cannot make one.
   */
  make(from: Place, to: Place | null, facts: Facts): number[] | null;
  /** Words for the preview, e.g. "F♯4 · quarter · staff 2". */
  describe(at: Place, facts: Facts): string;
  look(): Look;
  /** After an item is made: a number counts on. */
  placed?(): void;
}

/** A click shorter than this many P3 spaces makes a span of SCORE's default length. */
const MIN_SPAN = 1;
/** Clefs before this position stand at the start of the line (P3 2), others are small clef changes. */
const LINE_START = 6;

function group(id: string, label: string, options: [value: string, label: string, title?: string][], value?: string, kind: Group['kind'] = 'buttons'): Group {
  return { id, label, kind, options: options.map(([v, l, title]) => ({ value: v, label: l, title })), value: value ?? options[0]?.[0] ?? '' };
}

function padded(params: number[], length: number): number[] {
  const p = [...params];
  while (p.length < length) p.push(0);
  return p;
}

/** A creation word's defaults on `place`'s staff at its P3, at its level unless `level` is false. */
function at(facts: Facts, word: string, place: Place, level: boolean, length = 4): number[] | null {
  const base = facts.creation(word);
  if (!base) return null;
  const p = padded(base, length);
  p[1] = place.staff;
  p[2] = place.p3;
  if (level) p[3] = place.p4;
  return p;
}

/**
 * A creation word's defaults from `from` to `to` (or SCORE's default length):
 * P3 and P6 the ends left to right, P4 and P5 their levels (`levels`
 * 'both'), only P4 ('start'), or neither.
 */
function spanned(facts: Facts, word: string, from: Place, to: Place | null, levels: 'both' | 'start' | 'none', length = 6): number[] | null {
  const base = facts.creation(word);
  if (!base) return null;
  const p = padded(base, length);
  const usual = p[5]! > p[2]! ? p[5]! - p[2]! : 20;
  let [a, b] = to && Math.abs(to.p3 - from.p3) >= MIN_SPAN ? [from, to] : [from, { ...from, p3: from.p3 + usual }];
  if (b.p3 < a.p3) [a, b] = [b, a];
  p[1] = from.staff;
  p[2] = a.p3;
  p[5] = Math.round(b.p3 * 100) / 100;
  if (levels !== 'none') p[3] = a.p4;
  if (levels === 'both') p[4] = b.p4;
  return p;
}

const optionLabel = (g: Group) => g.options.find((o) => o.value === g.value)?.label ?? g.value;
const optionTitle = (g: Group) => {
  const o = g.options.find((o) => o.value === g.value);
  return o?.title ?? o?.label ?? g.value;
};

/** A level as P4 of a cue-size note ("add 100, or -100 if P4 is negative"). */
const small = (lvl: number) => lvl + (lvl < 0 ? -100 : 100);

// ---------------------------------------------------------------------------
// Icons

const svg = (body: string) => `<svg viewBox="0 0 24 24" aria-hidden="true">${body}</svg>`;
const glyph = (text: string, size = 13, style = '') => svg(`<text x="12" y="16.5" text-anchor="middle" font-size="${size}" ${style} fill="currentColor" stroke="none">${text}</text>`);

/** A note of a value as a small picture: its head, stem and flags. */
function valueIcon(head: number, tails: number): string {
  if (head >= 2) {
    const bars = head === 3 ? '<path d="M5.4 13.5v8M18.6 13.5v8" />' : '';
    return svg(`<ellipse cx="12" cy="17.5" rx="4.4" ry="2.8" />${bars}`);
  }
  const fill = head === 1 ? '' : ' fill="currentColor"';
  const flags = Array.from({ length: tails }, (_, i) => `<path d="M12.4 ${3 + i * 2.6}c.4 2.6 3.6 3 3.2 6" />`).join('');
  return svg(`<ellipse cx="9" cy="17.5" rx="3.6" ry="2.5" transform="rotate(-20 9 17.5)"${fill} /><path d="M12.4 16.6V3" />${flags}`);
}

const ICONS = {
  select: svg('<path d="M6 3.5v15l4-4 2.6 6 2.4-1-2.6-6H18z" fill="currentColor" stroke="none" />'),
  note: svg('<ellipse cx="9.5" cy="17.5" rx="4" ry="2.8" transform="rotate(-20 9.5 17.5)" fill="currentColor" /><path d="M13.3 16.5V3.5" />'),
  rest: svg('<path d="M9.5 3.5 14 8.5l-3.5 3.5 4 4.5c-3-1-5-.3-4 3.3-2.6-2.3-1.6-6 1.8-4.6L8.5 10.6l3-3.3z" fill="currentColor" stroke-width="1" />'),
  clef: glyph('𝄞', 21, 'font-family="serif"'),
  key: glyph('♯♭', 13, 'font-family="serif"'),
  meter: svg('<text x="12" y="11" text-anchor="middle" font-size="10" font-weight="700" font-family="serif" fill="currentColor" stroke="none">4</text><text x="12" y="21" text-anchor="middle" font-size="10" font-weight="700" font-family="serif" fill="currentColor" stroke="none">4</text>'),
  barline: svg('<path d="M4 6h16M4 9.5h16M4 13h16M4 16.5h16" stroke-width="1" opacity="0.45" /><path d="M12 5v13" stroke-width="2.2" />'),
  slur: svg('<path d="M3.5 16c4-8 13-8 17 0" stroke-width="2.2" />'),
  beam: svg('<path d="M5 6.5l14-2.5v3L5 9.5z" fill="currentColor" stroke-width="1" /><path d="M5.6 8v10.5M18.4 6v10.5" /><ellipse cx="3.4" cy="18.6" rx="2.4" ry="1.6" fill="currentColor" /><ellipse cx="16.2" cy="16.6" rx="2.4" ry="1.6" fill="currentColor" />'),
  line: svg('<path d="M4 17 20 7" stroke-width="2" />'),
  hairpin: svg('<path d="M20 6 4 12l16 6" stroke-width="1.8" />'),
  ottava: glyph('8<tspan font-size="8" dy="-4">va</tspan>', 13, 'font-family="serif" font-style="italic" font-weight="700"'),
  dynamic: glyph('mf', 14, 'font-family="serif" font-style="italic" font-weight="700"'),
  articulation: svg('<path d="M6 7l12 3.5L6 14" stroke-width="2" /><circle cx="12" cy="19" r="1.6" fill="currentColor" stroke="none" />'),
  symbol: svg('<path d="M12 3.5l2.5 5.4 5.9.7-4.4 4 1.2 5.8-5.2-2.9-5.2 2.9 1.2-5.8-4.4-4 5.9-.7z" />'),
  number: glyph('12', 13, 'font-weight="700"'),
  box: svg('<rect x="4" y="5" width="16" height="14" rx="1.5" />'),
  text: glyph('T', 17, 'font-family="serif"'),
  staff: svg('<path d="M3 6h18M3 9.5h18M3 13h18M3 16.5h18M3 20h18" stroke-width="1.4" />'),
};

// ---------------------------------------------------------------------------
// The tools

/** Note and rest values from the shortest, so the keys 1 … 8 go from 64th notes to breves. */
const VALUE_ORDER = [7, 6, 5, 4, 3, 2, 1, 0];

function valueGroup(): Group {
  const g = group(
    'value',
    'Value',
    VALUE_ORDER.map((i) => [String(i), VALUES[i]!.name]),
    '3',
  );
  g.options.forEach((o) => (o.icon = valueIcon(VALUES[Number(o.value)]!.head, VALUES[Number(o.value)]!.tails)));
  return g;
}

const valueName = (g: Group) => VALUES[Number(g.value)]!.name.toLowerCase();

export function createTools(): Tool[] {
  // Note and rest share their value and dots, as the keys 1 … 8 and . set them.
  const value = valueGroup();
  const dots = group('dots', 'Dots', [
    ['0', '–', 'No dot (. toggles)'],
    ['1', '•', 'Dotted (. toggles)'],
    ['2', '••', 'Double-dotted'],
  ]);
  const quarters = () => VALUES[Number(value.value)]!.quarters * DOT_FACTOR[Number(dots.value)]!;
  const dotted = () => ['', 'dotted ', 'double-dotted '][Number(dots.value)] ?? '';

  const accidental = group('accidental', 'Accidental', [
    ['0', '–', 'No accidental'],
    ['1', '♭', 'Flat'],
    ['3', '♮', 'Natural'],
    ['2', '♯', 'Sharp'],
    ['4', '♭♭', 'Double flat'],
    ['5', '♯♯', 'Double sharp'],
  ]);
  const stem = group('stem', 'Stem', [
    ['auto', 'Auto', 'Up below the middle line, down from it'],
    ['up', '↑', 'Stem up'],
    ['down', '↓', 'Stem down'],
  ]);
  const size = group('size', 'Size', [
    ['normal', 'Normal'],
    ['cue', 'Cue', 'A cue-size note'],
    ['grace', 'Grace', 'A grace note, slashed'],
  ]);

  const note: Tool = {
    id: 'note',
    key: 'n',
    label: 'Note',
    title: 'Note: click on a staff at the pitch it is to have',
    icon: ICONS.note,
    code: 1,
    shape: 'point',
    level: 'start',
    groups: [value, dots, accidental, stem, size],
    noun: () => (size.value === 'grace' ? 'grace note' : 'note'),
    make(from, _to, facts) {
      const p = at(facts, 'NOTE', from, true, 9);
      if (!p) return null;
      const lvl = from.p4;
      const acc = Number(accidental.value);
      if (size.value === 'grace') {
        // As the panel's Value makes one: small, value 65, slashed stem up, one tail.
        Object.assign(p, { 3: small(lvl), 4: 10 + acc, 5: 0, 6: 65, 7: 101, 8: 1 });
        return p;
      }
      const up = stem.value === 'up' || (stem.value === 'auto' && lvl < facts.middle(from.staff));
      const v = VALUES[Number(value.value)]!;
      p[3] = size.value === 'cue' ? small(lvl) : lvl;
      p[4] = (up ? 10 : 20) + acc;
      p[5] = v.head;
      p[6] = quarters();
      p[8] = Number(dots.value) * 10 + v.tails;
      return p;
    },
    describe(place, facts) {
      const name = noteName(place.p4, Number(accidental.value), facts.clefAt(place.staff, place.p3));
      const kind = size.value === 'grace' ? 'grace note' : `${dotted()}${valueName(value)}`;
      return `${name} · ${kind} · staff ${place.staff}`;
    },
    look: () => 'head',
  };

  const rest: Tool = {
    id: 'rest',
    key: 'r',
    label: 'Rest',
    title: 'Rest: click on a staff where it goes; it sits at its usual height',
    icon: ICONS.rest,
    code: 2,
    shape: 'point',
    level: 'none',
    groups: [value, dots],
    noun: () => 'rest',
    make(from, _to, facts) {
      const p = at(facts, 'REST', from, false, 7);
      if (!p) return null;
      p[3] = 0;
      p[4] = VALUES[Number(value.value)]!.rest;
      p[5] = Number(dots.value);
      p[6] = quarters();
      return p;
    },
    describe: (place) => `${dotted()}${valueName(value)} rest · staff ${place.staff}`,
    look: () => 'mark',
  };

  const clefKind = group('clef', 'Clef', [
    ['0', 'Treble'],
    ['1', 'Bass'],
    ['2', 'Alto'],
    ['3', 'Tenor'],
    ['4', 'Percussion'],
    ['0.8', 'Treble 8vb', 'Treble clef, an octave below'],
  ]);
  const clefSize = group('size', 'Size', [
    ['auto', 'Auto', 'Full size at the start of the line, small elsewhere'],
    ['normal', 'Normal'],
    ['small', 'Small'],
  ]);
  const clef: Tool = {
    id: 'clef',
    key: 'c',
    label: 'Clef',
    title: 'Clef: click at the start of a staff, or where the clef changes',
    icon: ICONS.clef,
    code: 3,
    shape: 'point',
    level: 'none',
    groups: [clefKind, clefSize],
    noun: () => `${optionLabel(clefKind).toLowerCase()} clef`,
    make(from, _to, facts) {
      const p = at(facts, 'TREB', from, false, 5);
      if (!p) return null;
      const start = from.p3 < LINE_START;
      if (start) p[2] = facts.creation('TREB')?.[2] ?? 2;
      const smaller = clefSize.value === 'small' || (clefSize.value === 'auto' && !start);
      p[3] = smaller ? 100 : 0;
      p[4] = Number(clefKind.value);
      return p;
    },
    describe: (place) => `${optionLabel(clefKind)} clef · staff ${place.staff}`,
    look: () => 'mark',
  };

  const MAJOR = ['C♭', 'G♭', 'D♭', 'A♭', 'E♭', 'B♭', 'F', 'C', 'G', 'D', 'A', 'E', 'B', 'F♯', 'C♯'];
  const MINOR = ['a♭', 'e♭', 'b♭', 'f', 'c', 'g', 'd', 'a', 'e', 'b', 'f♯', 'c♯', 'g♯', 'd♯', 'a♯'];
  const keyCount = group(
    'key',
    'Key',
    Array.from({ length: 15 }, (_, i): [string, string] => {
      const n = i - 7;
      const signs = n === 0 ? 'no sharps or flats' : `${Math.abs(n)}${n > 0 ? '♯' : '♭'}`;
      return [String(n), `${signs} · ${MAJOR[i]} major / ${MINOR[i]} minor`];
    }),
    '1',
    'select',
  );
  const key: Tool = {
    id: 'key',
    key: 'k',
    label: 'Key signature',
    title: 'Key signature: click on a staff; its accidentals sit for the clef in force there',
    icon: ICONS.key,
    code: 17,
    shape: 'point',
    level: 'none',
    groups: [keyCount],
    noun: () => 'key signature',
    make(from, _to, facts) {
      const p = at(facts, 'KSIG+1', from, false, 6);
      if (!p) return null;
      p[3] = 0;
      p[4] = Number(keyCount.value);
      const clefType = Math.trunc(Math.abs(facts.clefAt(from.staff, from.p3)?.p5 ?? 0));
      p[5] = clefType <= 3 ? clefType : 0;
      return p;
    },
    describe: (place) => `Key signature ${optionLabel(keyCount).split(' · ')[0]} · staff ${place.staff}`,
    look: () => 'mark',
  };

  const meterKind = group('meter', 'Meter', [
    ['4/4', '4/4'],
    ['3/4', '3/4'],
    ['2/4', '2/4'],
    ['2/2', '2/2'],
    ['6/8', '6/8'],
    ['3/8', '3/8'],
    ['9/8', '9/8'],
    ['12/8', '12/8'],
    ['5/4', '5/4'],
    ['C', 'C', 'Common time'],
    ['¢', '¢', 'Cut time'],
  ]);
  const meter: Tool = {
    id: 'meter',
    key: 'm',
    label: 'Meter',
    title: 'Meter (time signature): click on a staff',
    icon: ICONS.meter,
    code: 18,
    shape: 'point',
    level: 'none',
    groups: [meterKind],
    noun: () => `meter ${meterKind.value}`,
    make(from, _to, facts) {
      const symbol = { C: 'COMM', '¢': 'CUT' }[meterKind.value];
      const p = at(facts, symbol ?? 'METER44', from, false, 6);
      if (!p) return null;
      p[3] = 0;
      if (!symbol) {
        const [top = 4, bottom = 4] = meterKind.value.split('/').map(Number);
        p[4] = top;
        p[5] = bottom;
      }
      return p;
    },
    describe: (place) => `Meter ${optionLabel(meterKind)} · staff ${place.staff}`,
    look: () => 'mark',
  };

  const barKind = group('barline', 'Type', [
    ['0', 'Single'],
    ['1', 'Double'],
    ['2', 'Final'],
    ['4', 'Start repeat'],
    ['3', 'End repeat'],
    ['5', 'End and start repeat'],
    ['7', 'Dashed'],
    ['8', 'Brace'],
    ['9', 'Bracket'],
  ]);
  const barline: Tool = {
    id: 'barline',
    key: 'b',
    label: 'Barline',
    title: 'Barline, brace or bracket: click on a staff, or drag from the lowest staff it joins to the highest',
    icon: ICONS.barline,
    code: 14,
    shape: 'reach',
    level: 'none',
    groups: [barKind],
    noun: () => (Number(barKind.value) >= 8 ? optionLabel(barKind).toLowerCase() : 'barline'),
    make(from, to, facts) {
      const p = at(facts, 'BAR', from, false, 5);
      if (!p) return null;
      const [low, high] = to ? [Math.min(from.staff, to.staff), Math.max(from.staff, to.staff)] : [from.staff, from.staff];
      p[1] = low;
      p[3] = high - low + 1;
      p[4] = Number(barKind.value);
      return p;
    },
    describe: (place) => `${optionLabel(barKind)} ${Number(barKind.value) >= 8 ? '' : 'barline '}· staff ${place.staff}`.replace('  ', ' '),
    look: () => 'barline',
  };

  const slurKind = group('slur', 'Kind', [
    ['SLUR', 'Slur ⌒', 'Slur, curving up'],
    ['SLURD', 'Slur ⌣', 'Slur, curving down'],
    ['TIE', 'Tie ⌒', 'Tie, curving up'],
    ['TIED', 'Tie ⌣', 'Tie, curving down'],
    ['END1', '1st ending'],
    ['END2', '2nd ending'],
  ]);
  const slur: Tool = {
    id: 'slur',
    key: 's',
    label: 'Slur, tie, ending',
    title: 'Slur, tie or ending: drag from where it starts to where it ends (a click makes one of the usual length)',
    icon: ICONS.slur,
    code: 5,
    shape: 'span',
    level: 'both',
    groups: [slurKind],
    noun: () => ({ SLUR: 'slur', SLURD: 'slur', TIE: 'tie', TIED: 'tie', END1: '1st ending', END2: '2nd ending' })[slurKind.value] ?? 'slur',
    make: (from, to, facts) => spanned(facts, slurKind.value, from, to, 'both'),
    describe: (place) => `${optionTitle(slurKind)} · staff ${place.staff}`,
    look: () => (slurKind.value.startsWith('END') ? 'bracket' : slurKind.value.endsWith('D') ? 'arc-down' : 'arc-up'),
  };

  const beams = group('beams', 'Beams', [
    ['1', '1', 'One beam: eighths'],
    ['2', '2', 'Two beams: 16ths'],
    ['3', '3', 'Three beams: 32nds'],
    ['4', '4', 'Four beams: 64ths'],
  ]);
  const beamStems = group('stems', 'Stems', [
    ['auto', 'Auto', 'Up for a beam from the middle line up, else down'],
    ['up', '↑', 'Stems up'],
    ['down', '↓', 'Stems down'],
  ]);
  const beam: Tool = {
    id: 'beam',
    key: 'g',
    label: 'Beam',
    title: 'Beam: drag from its left end to its right end, at the height it is to have',
    icon: ICONS.beam,
    code: 6,
    shape: 'span',
    level: 'both',
    groups: [beams, beamStems],
    noun: () => 'beam',
    make(from, to, facts) {
      const p = spanned(facts, 'BEAM', from, to, 'both', 7);
      if (!p) return null;
      const up = beamStems.value === 'up' || (beamStems.value === 'auto' && from.p4 >= facts.middle(from.staff));
      p[6] = (up ? 10 : 20) + Number(beams.value);
      return p;
    },
    describe: (place) => `Beam (${beams.value}) · staff ${place.staff}`,
    look: () => 'beam',
  };

  const LINE_STYLE: Record<string, [word: string, p7: number | null]> = {
    line: ['LINE', null],
    dashed: ['DASH', null],
    dotted: ['LINE', -4],
    wavy: ['LINE', -1],
    thin: ['LINE', -2],
    saw: ['LINE', -3],
  };
  const lineStyle = group('style', 'Style', [
    ['line', 'Line'],
    ['dashed', 'Dashed'],
    ['dotted', 'Dotted'],
    ['wavy', 'Wavy'],
    ['thin', 'Wavy, thin'],
    ['saw', 'Sawtooth'],
  ]);
  const line: Tool = {
    id: 'line',
    key: 'l',
    label: 'Line',
    title: 'Line: drag from one end to the other',
    icon: ICONS.line,
    code: 4,
    shape: 'span',
    level: 'both',
    groups: [lineStyle],
    noun: () => (lineStyle.value === 'line' ? 'line' : `${optionLabel(lineStyle).toLowerCase()} line`),
    make(from, to, facts) {
      const [word, p7] = LINE_STYLE[lineStyle.value] ?? LINE_STYLE.line!;
      const p = spanned(facts, word, from, to, 'both', 7);
      if (p && p7 !== null) p[6] = p7;
      return p;
    },
    describe: (place) => `${optionLabel(lineStyle)} · staff ${place.staff}`,
    look: () => (lineStyle.value === 'line' ? 'line' : 'dashed'),
  };

  const hairpinKind = group('hairpin', 'Kind', [
    ['CRH', 'Crescendo', 'Crescendo hairpin, opening'],
    ['DCH', 'Decrescendo', 'Decrescendo hairpin, closing'],
  ]);
  const hairpin: Tool = {
    id: 'hairpin',
    key: 'h',
    label: 'Hairpin',
    title: 'Hairpin: drag from where it starts to where it ends, at its height',
    icon: ICONS.hairpin,
    code: 4,
    shape: 'span',
    level: 'start',
    groups: [hairpinKind],
    noun: () => optionLabel(hairpinKind).toLowerCase(),
    make: (from, to, facts) => spanned(facts, hairpinKind.value, from, to, 'start'),
    describe: (place) => `${optionLabel(hairpinKind)} · staff ${place.staff}`,
    look: () => (hairpinKind.value === 'CRH' ? 'wedge-open' : 'wedge-close'),
  };

  const lineKind = group('kind', 'Kind', [
    ['TRILL', 'Trill', 'Trill with a wavy line'],
    ['OVA', '8va', 'An octave higher'],
    ['OBA', '8vb', 'An octave lower'],
    ['OMA', '15ma', 'Two octaves higher'],
    ['PEDA', 'Pedal', 'Pedal line'],
  ]);
  const ottava: Tool = {
    id: 'ottava',
    key: 'o',
    label: 'Trill, ottava, pedal',
    title: 'Trill, 8va, 8vb, 15ma or pedal line: drag from where it starts to where it ends, at its height',
    icon: ICONS.ottava,
    code: 7,
    shape: 'span',
    level: 'start',
    groups: [lineKind],
    noun: () => optionLabel(lineKind).toLowerCase().replace('pedal', 'pedal line'),
    make: (from, to, facts) => spanned(facts, lineKind.value, from, to, 'start'),
    describe: (place) => `${optionTitle(lineKind)} · staff ${place.staff}`,
    look: () => 'dashed',
  };

  /** A tool that puts one of SCORE's named library symbols at the point clicked. */
  function symbolWords(id: string, keyName: string, label: string, title: string, icon: string, words: [string, string, string?][]): Tool {
    const which = group('symbol', label, words);
    return {
      id,
      key: keyName,
      label,
      title,
      icon,
      code: 9,
      shape: 'point',
      level: 'start',
      groups: [which],
      noun: () => optionTitle(which).toLowerCase(),
      make: (from, _to, facts) => at(facts, which.value, from, true),
      describe: (place) => `${optionTitle(which)} · staff ${place.staff}`,
      look: () => 'mark',
    };
  }

  const dynamic = symbolWords('dynamic', 'd', 'Dynamics', 'Dynamics and expressions: click where it goes', ICONS.dynamic, [
    ['PP', 'pp'],
    ['P', 'p'],
    ['MP', 'mp'],
    ['MF', 'mf'],
    ['F', 'f'],
    ['FF', 'ff'],
    ['SF', 'sf'],
    ['SFZ', 'sfz'],
    ['CRS', 'cresc.'],
    ['DIM', 'dim.'],
    ['SUB', 'subito'],
    ['MOL', 'molto'],
    ['MEN', 'meno'],
    ['ESP', 'espr.'],
    ['ATM', 'a tempo'],
    ['ACL', 'accel.'],
    ['PIZ', 'pizz.'],
    ['ARC', 'arco'],
    ['GLI', 'gliss.'],
  ]);

  const articulation = symbolWords('articulation', 'a', 'Articulations', 'Articulations and ornaments: click above or below the note', ICONS.articulation, [
    ['STAC', '·', 'Staccato'],
    ['ACN', '>', 'Accent'],
    ['TENU', '–', 'Tenuto'],
    ['WED', '▼', 'Wedge'],
    ['WEDS', '▼·', 'Wedge and dot'],
    ['ACT', '>–', 'Accent and tenuto'],
    ['FER', '𝄐', 'Fermata'],
    ['UPB', 'V', 'Up-bow'],
    ['DNB', '⊓', 'Down-bow'],
    ['HAR', 'o', 'Harmonic'],
    ['PLU', '+', 'Plus (stopped)'],
    ['MOR', 'Mordent'],
    ['INV', 'Inv. mordent', 'Inverted mordent'],
    ['TUR', 'Turn'],
    ['PED', 'Ped.', 'Pedal down'],
    ['AST', '✱', 'Pedal up'],
  ]);

  const libraryChoice: Group = { id: 'symbol', label: 'Symbol', kind: 'choose', options: [], value: '' };
  const symbol: Tool = {
    id: 'symbol',
    key: 'y',
    label: 'Symbol',
    title: 'Any symbol of the libraries: choose it, then click where it goes',
    icon: ICONS.symbol,
    code: 9,
    shape: 'point',
    level: 'start',
    groups: [libraryChoice],
    noun: () => 'symbol',
    make: (from) => (libraryChoice.value === '' ? null : [9, from.staff, from.p3, from.p4, Number(libraryChoice.value)]),
    describe: (place) => `${libraryChoice.options[0]?.label ?? 'Symbol'} · staff ${place.staff}`,
    look: () => 'mark',
  };

  const numberKind = group('kind', 'Shows', [
    ['number', '1 2 3', 'A number'],
    ['letter', 'A B C', 'A rehearsal letter'],
  ]);
  const numberValue: Group = { id: 'value', label: 'Next', kind: 'number', options: [], value: '1' };
  const enclosure = group('enclosure', 'Enclosure', [
    ['0', 'None'],
    ['1', 'Circle'],
    ['2', 'Box'],
  ]);
  const shown = () => {
    const n = Math.max(1, Math.round(Number(numberValue.value) || 1));
    return numberKind.value === 'letter' ? String.fromCharCode(64 + Math.min(n, 26)) : String(n);
  };
  const number: Tool = {
    id: 'number',
    key: '#',
    label: 'Number, rehearsal letter',
    title: 'Number or rehearsal letter: click where it goes; the next one counts on',
    icon: ICONS.number,
    code: 10,
    shape: 'point',
    level: 'start',
    groups: [numberKind, numberValue, enclosure],
    noun: () => (numberKind.value === 'letter' ? 'rehearsal letter' : 'number'),
    make(from, _to, facts) {
      const p = at(facts, 'NUMB', from, true, 8);
      if (!p) return null;
      const n = Math.max(1, Math.round(Number(numberValue.value) || 1));
      p[4] = numberKind.value === 'letter' ? 1000 + Math.min(n, 26) : n;
      p[7] = Number(enclosure.value);
      return p;
    },
    describe: (place) => `${numberKind.value === 'letter' ? 'Letter' : 'Number'} ${shown()} · staff ${place.staff}`,
    look: () => 'mark',
    placed() {
      numberValue.value = String(Math.max(1, Math.round(Number(numberValue.value) || 1)) + 1);
    },
  };

  const shapeKind = group('shape', 'Shape', [
    ['BOX', 'Box'],
    ['CIRCLE', 'Circle'],
    ['DASHED', 'Dashed box'],
    ['GUIT', 'Guitar grid'],
  ]);
  const box: Tool = {
    id: 'box',
    key: 'x',
    label: 'Box, circle, grid',
    title: 'Box, circle or guitar grid: click where it goes, then size it with its handles',
    icon: ICONS.box,
    code: 12,
    shape: 'point',
    level: 'start',
    groups: [shapeKind],
    noun: () => optionLabel(shapeKind).toLowerCase(),
    make(from, _to, facts) {
      const dashed = shapeKind.value === 'DASHED';
      const p = at(facts, dashed ? 'BOX' : shapeKind.value, from, true, 5);
      if (p && dashed) p[4] = 3;
      return p;
    },
    describe: (place) => `${optionLabel(shapeKind)} · staff ${place.staff}`,
    look: () => 'mark',
  };

  const font: Group = { id: 'font', label: 'Font', kind: 'select', options: [], value: '-1' };
  const text: Tool = {
    id: 'text',
    key: 't',
    label: 'Text',
    title: 'Text: click where it begins and type it; Enter puts it there, Escape does not',
    icon: ICONS.text,
    code: 16,
    shape: 'text',
    level: 'start',
    groups: [font],
    noun: () => 'text',
    make: (from) => [16, from.staff, from.p3, from.p4],
    describe: (place) => `Text · staff ${place.staff}`,
    look: () => 'text',
  };

  const staff: Tool = {
    id: 'staff',
    key: 'f',
    label: 'Staff',
    title: 'Staff: click at the height it is to have; it is numbered above the highest one',
    icon: ICONS.staff,
    code: 8,
    shape: 'staff',
    level: 'none',
    groups: [],
    noun: () => 'staff',
    make: (from) => [8, from.staff, 0, from.p4],
    describe: (place) => `New staff ${place.staff}`,
    look: () => 'staff',
  };

  return [note, rest, clef, key, meter, barline, slur, beam, line, hairpin, ottava, dynamic, articulation, symbol, number, box, text, staff];
}

/** The select tool's button: no insertion mode. */
export const SELECT = { id: 'select', key: 'v', label: 'Select', title: 'Select and edit items (V, or Esc in an insertion mode)', icon: ICONS.select };
