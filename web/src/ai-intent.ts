// What a command means, in a few fields, and the edit script for it. The
// word rules (ai-words.ts) and Jev's choices (ai-models.ts) both fill in an
// Intent; Claude writes scripts directly. Each intent leaves open what the
// words do not say (how much bigger, how many notes per beam) as knobs.
import type { Filter, Knob, Script, Step } from './ai-script';

/** What the command is about, by the side panel's names. */
export interface Target {
  id: string;
  /** What the word picks; all items when empty. */
  codes: number[];
  /** A setting of the items rather than items: stems are a note's Stem setting. */
  aspect?: string;
  /** Its option meaning "none", for removing it. */
  off?: string;
  where?: string;
  /** Words for it, multi-word ones first in matching. */
  words: string[];
  /** As said in a summary. */
  noun: string;
}

export const TARGETS: Target[] = [
  { id: 'grace', codes: [1], where: 'p7 >= 64', words: ['grace notes', 'grace note', 'appoggiaturas', 'acciaccaturas'], noun: 'grace notes' },
  { id: 'stems', codes: [1], aspect: 'Stem', off: 'None', words: ['stems', 'stem', 'stalks'], noun: 'stems' },
  { id: 'accidentals', codes: [1], aspect: 'Accidental', off: 'None', words: ['accidentals', 'accidental'], noun: 'accidentals' },
  { id: 'marks', codes: [1], aspect: 'Mark', off: 'None', words: ['articulations', 'articulation', 'marks', 'mark', 'ornaments'], noun: 'marks' },
  { id: 'dots', codes: [1, 2], aspect: 'Dots', off: 'None', words: ['augmentation dots', 'dots', 'dot'], noun: 'dots' },
  { id: 'heads', codes: [1], aspect: 'Head', off: 'None', words: ['noteheads', 'notehead', 'note heads', 'note head', 'heads', 'head'], noun: 'note heads' },
  { id: 'ties', codes: [5], words: ['ties', 'tie'], noun: 'ties' },
  { id: 'slurs', codes: [5], words: ['phrase marks', 'phrasing slurs', 'slurs', 'slur', 'phrasing'], noun: 'slurs' },
  { id: 'endings', codes: [5], words: ['endings', 'ending', 'voltas', 'volta'], noun: 'endings' },
  { id: 'beams', codes: [6], words: ['beams', 'beam', 'beaming'], noun: 'beams' },
  { id: 'hairpins', codes: [4], words: ['hairpins', 'hairpin', 'crescendos', 'crescendo', 'decrescendos', 'decrescendo', 'diminuendos', 'diminuendo', 'wedges', 'wedge'], noun: 'hairpins' },
  { id: 'lines', codes: [4], words: ['lines', 'line'], noun: 'lines' },
  { id: 'trills', codes: [7], words: ['trills', 'trill', 'ottavas', 'ottava', '8va', 'pedal marks', 'pedals', 'pedal'], noun: 'trills and ottavas' },
  { id: 'staves', codes: [8], words: ['staves', 'staffs', 'staff', 'systems'], noun: 'staves' },
  { id: 'dynamics', codes: [9], words: ['dynamics', 'dynamic marks', 'dynamic'], noun: 'dynamics' },
  { id: 'symbols', codes: [9], words: ['symbols', 'symbol', 'signs', 'sign'], noun: 'symbols' },
  { id: 'numbers', codes: [10], words: ['rehearsal letters', 'rehearsal marks', 'measure numbers', 'bar numbers', 'numbers', 'number'], noun: 'numbers' },
  { id: 'boxes', codes: [12], words: ['boxes', 'box', 'circles', 'circle', 'frames'], noun: 'boxes' },
  { id: 'barlines', codes: [14], words: ['barlines', 'barline', 'bar lines', 'bar line', 'measure lines', 'braces', 'brace', 'brackets'], noun: 'barlines' },
  { id: 'text', codes: [16], words: ['lyrics', 'lyric', 'syllables', 'text', 'texts', 'words', 'titles', 'title', 'labels', 'captions'], noun: 'texts' },
  { id: 'keys', codes: [17], words: ['key signatures', 'key signature', 'keys', 'key'], noun: 'key signatures' },
  { id: 'meters', codes: [18], words: ['time signatures', 'time signature', 'meters', 'meter'], noun: 'meters' },
  { id: 'clefs', codes: [3], words: ['clefs', 'clef'], noun: 'clefs' },
  { id: 'rests', codes: [2], words: ['rests', 'rest', 'pauses'], noun: 'rests' },
  { id: 'chords', codes: [1], words: ['chords', 'chord'], noun: 'notes' },
  { id: 'notes', codes: [1], words: ['notes', 'note', 'pitches', 'pitch'], noun: 'notes' },
  { id: 'all', codes: [], words: ['everything', 'all', 'items', 'them', 'these', 'those', 'this', 'it', 'selection', 'selected', 'objects', 'things'], noun: 'items' },
];

export const targetById = (id: string) => TARGETS.find((t) => t.id === id) ?? TARGETS.at(-1)!;

/** Items of a code, counted: "1 note", "3 barlines". */
const NOUNS: Record<number, [string, string]> = {
  1: ['note', 'notes'],
  2: ['rest', 'rests'],
  3: ['clef', 'clefs'],
  4: ['line', 'lines'],
  5: ['slur', 'slurs'],
  6: ['beam', 'beams'],
  7: ['trill or ottava', 'trills and ottavas'],
  8: ['staff', 'staves'],
  9: ['symbol', 'symbols'],
  10: ['number', 'numbers'],
  11: ['drawing', 'drawings'],
  12: ['box', 'boxes'],
  14: ['barline', 'barlines'],
  15: ['picture', 'pictures'],
  16: ['text', 'texts'],
  17: ['key signature', 'key signatures'],
  18: ['meter', 'meters'],
};

export function counted(code: number, n: number): string {
  const [one, many] = NOUNS[code] ?? [`code ${code} item`, `code ${code} items`];
  return `${n} ${n === 1 ? one : many}`;
}

export type Action =
  | 'insert'
  | 'beam'
  | 'unbeam'
  | 'delete'
  | 'flip'
  | 'stems-up'
  | 'stems-down'
  | 'stems-auto'
  | 'option'
  | 'bigger'
  | 'smaller'
  | 'grow'
  | 'shrink'
  | 'move'
  | 'align'
  | 'number'
  | 'command';

/** A number setting that "bigger", "longer" … change, and how. */
export interface Measure {
  setting: string;
  /** Multiplies (sizes, where 0 means 1) or adds (stem lengths, in steps). */
  scale: 'times' | 'plus';
  /** As said in a summary. */
  noun: string;
  more: string;
  less: string;
}

export const MEASURES: Record<string, Measure> = {
  // What makes each kind bigger: its Size, else a slur's curvature or a
  // bracket's height, a hairpin's opening, a box's width (SIZE_EXTRA adds
  // its height), a line's, beam's or barline's thickness.
  size: { setting: 'Size | Curvature | Height | Opening | Size width | Thickness', scale: 'times', noun: 'size', more: 'Bigger', less: 'Smaller' },
  'stem length': { setting: 'Stem length', scale: 'plus', noun: 'stem length', more: 'Longer stems', less: 'Shorter stems' },
  thickness: { setting: 'Thickness', scale: 'times', noun: 'thickness', more: 'Thicker', less: 'Thinner' },
  width: { setting: 'Width', scale: 'times', noun: 'width', more: 'Wider', less: 'Narrower' },
  height: { setting: 'Height', scale: 'times', noun: 'height', more: 'Taller', less: 'Lower' },
  spacing: { setting: 'Spacing', scale: 'times', noun: 'spacing', more: 'Wider spacing', less: 'Tighter spacing' },
  'mark size': { setting: 'Mark size', scale: 'times', noun: 'mark size', more: 'Bigger marks', less: 'Smaller marks' },
};

export interface Intent {
  action: Action;
  target: string;
  /** option: the setting and the option's name; delete: only items whose setting reads it. */
  setting?: string;
  option?: string;
  /** bigger, smaller, grow, shrink: which measure (MEASURES), size by default. */
  measure?: string;
  direction?: 'up' | 'down' | 'left' | 'right';
  /** move: steps or spaces; bigger: the factor; beam: notes per beam. */
  amount?: number;
  /** grow, shrink: from and to. */
  from?: number;
  to?: number;
  /** insert: SCORE input passes 1 and 2, and the notes as typed. */
  notes?: string;
  typed?: string;
  rhythms?: string;
  /** number: the value; command: the line. */
  value?: number;
  line?: string;
  /** A second action the command asks for ("staccato and stems up"). */
  then?: Intent;
}

/** Where an action goes when two are chained: values first (beams need short notes), then beams, sizes, stems (a beam refits them), places. */
const CHAIN_ORDER: Partial<Record<Action, number>> = {
  option: 0,
  number: 0,
  unbeam: 1,
  beam: 1,
  bigger: 2,
  smaller: 2,
  grow: 2,
  shrink: 2,
  'stems-auto': 3,
  'stems-up': 3,
  'stems-down': 3,
  flip: 3,
  move: 4,
  align: 4,
};

/** Whether an action can be chained with another: never one that deletes, adds or runs a SCORE line. */
export const chainable = (action: Action) => CHAIN_ORDER[action] !== undefined;

const lowerFirst = (text: string) => text.charAt(0).toLowerCase() + text.slice(1);

/** Settings "bigger" changes along with a measure's own: a box grows in height as in width. */
const SIZE_EXTRA: Record<string, { codes: number[]; setting: string }[]> = {
  size: [{ codes: [12], setting: 'Size height' }],
};

/** `step` for the measure's setting, then for the settings that go with it on the items `scope` reaches. */
function measureSteps(measureId: string, scope: Filter | null, value: string): Step[] {
  const measure = MEASURES[measureId] ?? MEASURES.size!;
  const extra = (SIZE_EXTRA[measureId] ?? [])
    .filter(({ codes }) => {
      const reach = scope?.codes ?? [];
      return reach.length === 0 || codes.some((c) => reach.includes(c));
    })
    .map(({ codes, setting }): Step => ({ do: 'setting', items: { ...scope, codes, where: scope?.where ?? null }, setting, value }));
  return [{ do: 'setting', items: scope, setting: measure.setting, value }, ...extra];
}

function filterOf(target: Target, extra: Partial<Filter> = {}): Filter {
  return { codes: target.codes, where: target.where ?? null, ...extra };
}

const knob = (id: string, label: string, value: number, min: number, max: number, step: number): Knob => ({ id, label, value, min, max, step });

const round = (v: number) => Math.round(v * 100) / 100;

/** The edit script for an intent, and for its second action after or before it. */
export function scriptFor(intent: Intent): Script {
  if (!intent.then) return scriptForOne(intent);
  const [a, b] = [{ ...intent, then: undefined }, intent.then].sort((x, y) => CHAIN_ORDER[x.action]! - CHAIN_ORDER[y.action]!).map(scriptForOne);
  return { summary: `${a!.summary}, ${lowerFirst(b!.summary)}`, knobs: [...a!.knobs, ...b!.knobs], steps: [...a!.steps, ...b!.steps] };
}

function scriptForOne(intent: Intent): Script {
  const target = targetById(intent.target);
  const items = filterOf(target);
  const noun = target.noun;
  const one = (summary: string, ...steps: Step[]): Script => ({ summary, knobs: [], steps });
  switch (intent.action) {
    case 'insert':
      return one(`Add ${intent.typed ?? intent.notes ?? ''}`.trim(), { do: 'insert', notes: intent.notes ?? '', rhythms: intent.rhythms ?? '' });
    case 'beam': {
      const size = intent.amount ?? 0;
      const steps: Step[] = [{ do: 'beam', items: { codes: [1], where: target.where ?? null }, size: size > 0 ? 'size' : 0 }];
      if (size <= 0) return one('Beam each run up to the barline', ...steps);
      return { summary: 'Beam in groups', knobs: [knob('size', 'Notes per beam', size, 2, 8, 1)], steps };
    }
    case 'unbeam':
      return one('Remove beams', { do: 'delete', items: { codes: [6] } }, { do: 'command', items: { codes: [1] }, line: 'FLN' });
    case 'delete': {
      // A part of notes (a stem, a mark): its setting goes to "none"; "the staccatos" only where it reads that.
      const aspect = target.aspect ? target : TARGETS.find((t) => t.aspect && t.aspect === intent.setting && intent.option !== t.off);
      if (aspect?.aspect && aspect.off) {
        const only = intent.option && intent.setting === aspect.aspect && intent.option !== aspect.off ? { setting: aspect.aspect, is: intent.option } : {};
        const what = 'is' in only ? intent.option!.toLowerCase() : aspect.noun;
        return one(`Remove ${what}`, { do: 'setting', items: filterOf(aspect, only), setting: aspect.aspect, value: aspect.off });
      }
      if (target.id === 'beams') return scriptFor({ ...intent, action: 'unbeam' });
      // "the eighth notes": only the items whose setting reads that.
      const only = intent.setting && intent.option ? { setting: intent.setting, is: intent.option } : {};
      return one(`Delete ${'is' in only ? `${intent.option!.toLowerCase()} ` : ''}${noun}`, { do: 'delete', items: filterOf(target, only) });
    }
    case 'flip':
      return one(`Flip ${target.id === 'all' ? 'stems, slurs and symbols' : noun}`, { do: 'command', items: target.id === 'all' || target.id === 'stems' ? { codes: [1, 5, 9] } : items, line: 'FLI' });
    case 'stems-up':
    case 'stems-down': {
      const way = intent.action === 'stems-up' ? 'Up' : 'Down';
      return one(`Stems ${way.toLowerCase()}`, { do: 'setting', items: { codes: [1] }, setting: 'Stem', value: way }, { do: 'setting', items: { codes: [6] }, setting: 'Stems', value: way });
    }
    case 'stems-auto':
      // The refit (FLN) sets the stems' directions, but only of notes that have stems.
      return one(
        'Stems as the engine sets them',
        { do: 'setting', items: { codes: [1], setting: 'Stem', is: 'None' }, setting: 'Stem', value: 'Up' },
        { do: 'command', items: { codes: [1] }, line: 'FLN' },
      );
    case 'option':
      return one(`${intent.setting}: ${intent.option}`, { do: 'setting', items: target.id === 'all' ? null : items, setting: intent.setting ?? '', value: intent.option ?? '' });
    case 'number':
      return one(`${intent.setting} ${intent.value}`, { do: 'setting', items: target.id === 'all' ? null : items, setting: intent.setting ?? '', value: intent.value ?? 0 });
    case 'bigger':
    case 'smaller': {
      const measureId = MEASURES[intent.measure ?? 'size'] ? (intent.measure ?? 'size') : 'size';
      const measure = MEASURES[measureId]!;
      const up = intent.action === 'bigger';
      const scope = target.id === 'all' || target.aspect ? null : items;
      if (measure.scale === 'plus') {
        const by = intent.amount ?? (up ? 2 : -2);
        return {
          summary: up ? measure.more : measure.less,
          knobs: [knob('by', `Change in steps`, by, -10, 10, 0.5)],
          steps: [{ do: 'setting', items: scope, setting: measure.setting, value: 'value + by' }],
        };
      }
      const factor = intent.amount ?? (up ? 1.25 : 0.8);
      return {
        summary: up ? measure.more : measure.less,
        knobs: [knob('factor', `${capital(measure.noun)} ×`, factor, 0.1, 4, 0.05)],
        steps: measureSteps(measureId, scope, 'round((value == 0 ? 1 : value) * factor * 100) / 100'),
      };
    }
    case 'grow':
    case 'shrink': {
      const measureId = MEASURES[intent.measure ?? 'size'] ? (intent.measure ?? 'size') : 'size';
      const measure = MEASURES[measureId]!;
      const up = intent.action === 'grow';
      const scope = target.id === 'all' || target.aspect ? null : items;
      const plus = measure.scale === 'plus';
      const from = intent.from ?? (plus ? 0 : 1);
      const to = intent.to ?? (plus ? (up ? 4 : -4) : up ? 1.8 : 0.6);
      const [lo, hi] = plus ? [-10, 10] : [0.2, 4];
      return {
        summary: `${capital(measure.noun)} ${up ? 'grows' : 'shrinks'} from left to right`,
        knobs: [
          knob('from', 'From', from, lo, hi, plus ? 0.5 : 0.05),
          knob('to', 'To', round(to), lo, hi, plus ? 0.5 : 0.05),
          knob('curve', 'Curve', 1, 0.25, 4, 0.05),
        ],
        steps: measureSteps(measureId, scope, 'round((from + (to - from) * t ^ curve) * 100) / 100'),
      };
    }
    case 'move': {
      const direction = intent.direction ?? 'up';
      const amount = intent.amount ?? 1;
      const vertical = direction === 'up' || direction === 'down';
      const sign = direction === 'down' || direction === 'left' ? -1 : 1;
      return {
        summary: `Move ${direction}`,
        knobs: [knob('by', vertical ? 'Steps' : 'Spaces', sign * amount, vertical ? -14 : -40, vertical ? 14 : 40, vertical ? 1 : 0.5)],
        steps: [{ do: 'move', items: target.id === 'all' ? null : items, right: vertical ? 0 : 'by', up: vertical ? 'by' : 0 }],
      };
    }
    case 'align':
      return {
        summary: `Align ${noun} at one level`,
        knobs: [knob('shift', 'Level', 0, -12, 12, 0.5)],
        steps: [{ do: 'set', items: target.id === 'all' ? { codes: [9, 10, 16, 4, 7] } : items, param: 4, value: 'round(mean) + shift' }],
      };
    case 'command':
      return one(intent.line ?? '', { do: 'command', items: target.id === 'all' ? null : items, line: intent.line ?? '' });
  }
}

const capital = (s: string) => s.charAt(0).toUpperCase() + s.slice(1);
