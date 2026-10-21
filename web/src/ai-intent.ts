// What a command means, in a few fields, and the edit script for it. The
// word rules (ai-words.ts) and Jev's choices (ai-models.ts) both fill in an
// Intent; Claude writes scripts directly. Each intent leaves open what the
// words do not say (how much bigger, how many notes per beam) as knobs.
import type { Filter, Knob, Script, Step } from './ai-script';
import { chordOf, type Bars, type Recipe, type Tonic } from './ai-values';

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
  | 'command'
  | 'create'
  | 'select'
  | 'repeat'
  | 'transpose'
  | 'scale'
  | 'arpeggiate'
  | 'spread'
  | 'closer'
  | 'evenly'
  | 'change'
  | 'again'
  | 'app';

/**
 * Some of the items picked out by their place, as a filter over the
 * variables of edit scripts (ai-script.ts): the first, every other one, the
 * top notes. `many` is a knob, for the first or last few.
 */
export const PICKS: Record<string, { words: string; noun: string; where: string; codes?: number[] }> = {
  first: { words: 'only the first one', noun: 'the first', where: 'i == 0' },
  last: { words: 'only the last one', noun: 'the last', where: 'i == n - 1' },
  'every other': { words: 'every other one, from the first: the first, third, fifth …', noun: 'every other one', where: 'i % 2 == 0' },
  'every second': { words: 'every second one: the second, fourth, sixth …', noun: 'every second one', where: 'i % 2 == 1' },
  top: { words: 'the top note of each chord, the upper voice', noun: 'the top notes', where: 'level == chord_high', codes: [1] },
  bottom: { words: 'the bottom note of each chord, the lower voice', noun: 'the bottom notes', where: 'level == chord_low', codes: [1] },
  highest: { words: 'the single highest note', noun: 'the highest note', where: 'level == max_level', codes: [1] },
  lowest: { words: 'the single lowest note', noun: 'the lowest note', where: 'level == min_level', codes: [1] },
  downbeats: { words: 'the first of each bar, the downbeats', noun: 'the first of each bar', where: 'bi == 0' },
  'bar ends': { words: 'the last of each bar', noun: 'the last of each bar', where: 'bi == bn - 1' },
  bars: { words: 'certain bars named by number or place, such as bar 3, bars 2 to 4, the second bar, the last bar', noun: 'the bars', where: '' },
  'first few': { words: 'the first few, a number of them from the start', noun: 'the first few', where: 'i < many' },
  'last few': { words: 'the last few, a number of them up to the end', noun: 'the last few', where: 'i >= n - many' },
};

/** Where a new item goes by the items: between them and the one before, at the first, between them and the next, from the first to the last; or where the engine puts it. */
export type Place = 'before' | 'at' | 'after' | 'over' | 'page';

/** New items a command can make, by SCORE's creation words; TEXT is a text of the characters the command quotes. */
export const CREATIONS: Record<string, { word: string; at: Place; words: string }> = {
  staff: { word: 'STAFF', at: 'page', words: 'a new staff, five lines for music' },
  barline: { word: 'BAR', at: 'after', words: 'a barline' },
  'double barline': { word: 'BARD', at: 'after', words: 'a double barline' },
  'final barline': { word: 'BARH', at: 'after', words: 'a final barline, thin and heavy, at the end of a piece' },
  'start repeat': { word: 'BARR', at: 'before', words: 'a repeat barline where a repeated passage begins, its dots to the right' },
  'end repeat': { word: 'BARL', at: 'after', words: 'a repeat barline where a repeated passage ends, its dots to the left' },
  'treble clef': { word: 'TREB', at: 'before', words: 'a treble clef, G clef' },
  'bass clef': { word: 'BASS', at: 'before', words: 'a bass clef, F clef' },
  'alto clef': { word: 'ALTO', at: 'before', words: 'an alto clef, C clef' },
  'tenor clef': { word: 'TENOR', at: 'before', words: 'a tenor clef' },
  'percussion clef': { word: 'PERC', at: 'before', words: 'a percussion clef' },
  'key signature': { word: 'KSIG', at: 'before', words: 'a key signature, sharps or flats for a key' },
  meter: { word: 'METER', at: 'before', words: 'a time signature or meter, such as 3/4 or 6/8' },
  'common time': { word: 'COMM', at: 'before', words: 'the common time signature, C' },
  'cut time': { word: 'CUT', at: 'before', words: 'the cut time signature, alla breve' },
  slur: { word: 'SLUR', at: 'over', words: 'a slur or phrase mark over the notes' },
  tie: { word: 'TIE', at: 'over', words: 'a tie between notes of the same pitch' },
  crescendo: { word: 'CRH', at: 'over', words: 'a crescendo hairpin, an opening wedge' },
  diminuendo: { word: 'DCH', at: 'over', words: 'a diminuendo or decrescendo hairpin, a closing wedge' },
  line: { word: 'LINE', at: 'over', words: 'a straight line' },
  'dashed line': { word: 'DASH', at: 'over', words: 'a dashed line' },
  trill: { word: 'TRILL', at: 'over', words: 'a trill sign with its wavy line' },
  ottava: { word: 'OVA', at: 'over', words: 'an 8va line, an octave higher' },
  'ottava bassa': { word: 'OBA', at: 'over', words: 'an 8vb line, ottava bassa, an octave lower' },
  quindicesima: { word: 'OMA', at: 'over', words: 'a 15ma line, two octaves higher' },
  pedal: { word: 'PEDA', at: 'over', words: 'a piano pedal mark with its line' },
  'first ending': { word: 'END1', at: 'over', words: 'a first ending, a volta bracket marked 1' },
  'second ending': { word: 'END2', at: 'over', words: 'a second ending, a volta bracket marked 2' },
  arpeggio: { word: 'ARP', at: 'at', words: 'an arpeggio sign, a wavy line before a chord' },
  fermata: { word: 'FER', at: 'at', words: 'a fermata symbol of its own' },
  ...Object.fromEntries(['pp', 'p', 'mp', 'mf', 'f', 'ff', 'sf', 'sfz'].map((d) => [d, { word: d.toUpperCase(), at: 'at' as Place, words: `the dynamic mark ${d}` }])),
  'cresc.': { word: 'CRS', at: 'at', words: 'the word cresc.' },
  'dim.': { word: 'DIM', at: 'at', words: 'the word dim.' },
  'a tempo': { word: 'ATM', at: 'at', words: 'the words a tempo' },
  'accel.': { word: 'ACL', at: 'at', words: 'the word accel.' },
  'espr.': { word: 'ESP', at: 'at', words: 'the word espr., espressivo' },
  'pizz.': { word: 'PIZ', at: 'at', words: 'the word pizz., pizzicato' },
  arco: { word: 'ARC', at: 'at', words: 'the word arco' },
  'gliss.': { word: 'GLI', at: 'at', words: 'the word gliss.' },
  box: { word: 'BOX', at: 'at', words: 'a box' },
  circle: { word: 'CIRCLE', at: 'at', words: 'a circle' },
  number: { word: 'NUMB', at: 'at', words: 'a number, such as a bar number or rehearsal number' },
  text: { word: 'TEXT', at: 'at', words: 'a text, words given in quotes such as "Allegro"' },
  lyrics: { word: 'LYRICS', at: 'at', words: 'lyrics, words sung under the notes, given in quotes, with hyphens between syllables' },
};

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
  /** move: steps or spaces; bigger: the factor; beam: notes per beam; repeat: how many copies. */
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
  /** Some of the items by their place (PICKS), how many of the first or last few, which bars. */
  pick?: string;
  many?: number;
  bars?: Bars;
  /** Only the items whose setting already reads this: "accent the eighth notes" (Value: Eighth). */
  only?: { setting: string; option: string };
  /** option: one option for each column in turn, again from the first after the last ("staccato, accent"). */
  sequence?: string[];
  /** change: pitches for the notes, column by column in turn ("c e g"). */
  pitches?: string[];
  /** transpose: to this key (sharps, flats negative), else by `amount` half steps; `up` false for down, unset the nearer way. */
  key?: number;
  up?: boolean;
  /** scale: a scale or arpeggio, from its key note (none: the key in force's) and kind, up, down or both, over octaves, of a note value (pass 2: "8"). */
  scale?: { tonic?: Tonic; kind: string; arpeggio: boolean; way: Recipe['way']; octaves: number; value?: string; middle: number };
  /** create: the item (CREATIONS), its creation word with what the command gives (KSIG-3B, METER68), the numbers after its P3 (0 keeps the default), a text's characters. */
  item?: string;
  word?: string;
  more?: number[];
  text?: string;
  /** app: the editor's command (an entry of its menus) and its name. */
  command?: string;
  label?: string;
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
  spread: 4,
  closer: 4,
  evenly: 4,
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

/** The edit script for an intent, and for its second action after or before it; on the items it picks by place, if it does. */
export function scriptFor(intent: Intent): Script {
  if (!intent.then) return picked(intent, scriptForOne(intent));
  const [a, b] = [{ ...intent, then: undefined }, intent.then].sort((x, y) => CHAIN_ORDER[x.action]! - CHAIN_ORDER[y.action]!).map(scriptForOne);
  return picked(intent, { summary: `${a!.summary}, ${lowerFirst(b!.summary)}`, knobs: [...a!.knobs, ...b!.knobs], steps: [...a!.steps, ...b!.steps] });
}

/** The filter of bars named by number, over the scripts' `measure` (and `measures`, to count back from the last). */
function barsWhere(bars: Bars): string {
  return bars.end ? `measure > measures - ${bars.to} && measure <= measures - ${bars.from - 1}` : `measure >= ${bars.from} && measure <= ${bars.to}`;
}

/** "bar 3", "bars 2 to 4", "the last two bars": as said in a summary. */
function barsNoun(bars: Bars): string {
  if (bars.end) return bars.to === 1 ? 'the last bar' : `the last ${bars.to} bars`;
  return bars.from === bars.to ? `bar ${bars.from}` : `bars ${bars.from} to ${bars.to}`;
}

/**
 * The script on the items an intent picks: those with the property it
 * names ("the eighth notes"), then by place, are selected first, and the
 * steps act on them.
 */
function picked(intent: Intent, script: Script): Script {
  if (intent.action === 'insert' || intent.action === 'scale' || intent.action === 'app') return script;
  const target = targetById(intent.target);
  const steps: Step[] = [];
  let { summary, knobs } = script;
  if (intent.only) {
    steps.push({ do: 'select', items: { codes: [1], where: null, setting: intent.only.setting, is: intent.only.option } });
    summary = `${summary} (${intent.only.option.toLowerCase()} notes)`;
  }
  // Bars hold all kinds of items: bars narrow by place only.
  if (intent.bars) {
    steps.push({ do: 'select', items: { codes: target.id === 'all' ? [] : target.codes, where: target.where ? `(${target.where}) && ${barsWhere(intent.bars)}` : barsWhere(intent.bars) } });
    summary = intent.action === 'select' && !intent.pick ? `Select ${barsNoun(intent.bars)}` : `${summary} (${barsNoun(intent.bars)})`;
  }
  const pick = intent.pick ? PICKS[intent.pick] : undefined;
  if (pick && pick.where) {
    const where = target.where ? `(${target.where}) && ${pick.where}` : pick.where;
    if (pick.where.includes('many')) knobs = [knob('many', 'How many', intent.many ?? 2, 1, 16, 1), ...knobs];
    summary = intent.action === 'select' ? `Select ${pick.noun}${pick.codes || target.id === 'all' ? '' : ` of the ${target.noun}`}` : `${summary} (${pick.noun})`;
    steps.push({ do: 'select', items: { codes: pick.codes ?? target.codes, where } });
  }
  return steps.length ? { summary, knobs, steps: [...steps, ...script.steps] } : script;
}

/** "Add a staff", "Add an end repeat", "Add mf": a creation's name with the article its words give it. */
function creationSummary(id: string): string {
  const article = /^(a|an) /.test(CREATIONS[id]?.words ?? '') ? (/^[aeiou]/i.test(id) ? 'an ' : 'a ') : '';
  return `Add ${article}${id}`;
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
      if (intent.sequence) return inTurn(`${intent.setting}: ${intent.sequence.join(', ').toLowerCase()}`, intent.setting ?? '', intent.sequence);
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
    case 'create': {
      // By all the command's items, whatever it names: "add a clef" names what it makes.
      const creation = CREATIONS[intent.item ?? ''];
      if (!creation) return one('Nothing to add');
      if (intent.item === 'lyrics') return one(`Lyrics: “${intent.text ?? ''}”`, { do: 'lyrics', items: null, text: intent.text ?? '' });
      return one(intent.label ?? creationSummary(intent.item!), { do: 'create', items: null, word: intent.word ?? creation.word, at: creation.at, more: intent.more ?? null, text: intent.text ?? null });
    }
    case 'select': {
      // "the staccato notes": those whose setting reads it.
      const only = intent.setting && intent.option && intent.setting !== target.aspect ? { setting: intent.setting, is: intent.option } : {};
      return one(`Select ${'is' in only ? `${intent.option!.toLowerCase()} ` : ''}${noun}`, { do: 'select', items: filterOf(target, only) });
    }
    case 'repeat':
      // Everything selected, whatever it names: "this bar" is its notes as much as its barline.
      return {
        summary: 'Repeat',
        knobs: [knob('times', 'Times', Math.max(1, Math.round(intent.amount ?? 1)), 1, 16, 1)],
        steps: [{ do: 'repeat', items: null, times: 'times' }],
      };
    case 'transpose': {
      if (intent.key !== undefined) {
        const way = intent.up === undefined ? '' : intent.up ? ' up' : ' down';
        return one(`Transpose${way} to ${keyName(intent.key)}`, { do: 'transpose', items: null, key: intent.key, up: intent.up ?? null });
      }
      return {
        summary: 'Transpose',
        knobs: [knob('half', 'Half steps', intent.amount ?? 0, -24, 24, 1)],
        steps: [{ do: 'transpose', items: null, half: 'half' }],
      };
    }
    case 'scale': {
      const r = intent.scale ?? { kind: 'major', arpeggio: false, way: 'up', octaves: 1, middle: 34 };
      const tonic = r.tonic ? `${'CDEFGAB'[r.tonic.letter]}${{ 1: 'S', [-1]: 'F', 2: 'SS', [-2]: 'FF' }[r.tonic.accidental] ?? ''}` : null;
      const name = tonic ? tonic.replace(/SS$/, '𝄪').replace(/S$/, '♯').replace(/FF$/, '𝄫').replace(/F$/, '♭') : '';
      const ways = { up: '', down: ', down', both: ', up and down' };
      const kind = r.arpeggio ? chordOf(r.kind) : r.kind;
      // "a D major scale", "a chromatic scale from E", "a major scale in the key" (the key in force's).
      const head = r.kind === 'chromatic' || !tonic ? kind : `${name} ${kind}`;
      const tail = r.kind === 'chromatic' ? (tonic ? ` from ${name}` : '') : tonic ? '' : ' in the key';
      // "an F", "an E♭", "an augmented".
      const article = /^([AEF](?![a-z])|[aeiou])/.test(head) ? 'an' : 'a';
      return {
        summary: `Add ${article} ${head} ${r.arpeggio ? 'arpeggio' : 'scale'}${tail}${ways[r.way]}`,
        knobs: [knob('octaves', 'Octaves', r.octaves, 1, 4, 1)],
        steps: [
          { do: 'scale', tonic, octave: r.tonic?.octave ?? null, kind: r.kind, arpeggio: r.arpeggio, way: r.way, octaves: 'octaves', value: r.value ?? null, middle: r.middle },
        ],
      };
    }
    case 'arpeggiate':
      return one(intent.up === false ? 'Arpeggiate the chords from the top' : 'Arpeggiate the chords', { do: 'arpeggiate', items: { codes: [1], where: null }, down: intent.up === false });
    case 'spread':
    case 'closer': {
      const spread = intent.action === 'spread';
      return {
        summary: spread ? 'Spread out' : 'Closer together',
        knobs: [knob('factor', 'Spacing ×', round(intent.amount ?? (spread ? 1.25 : 0.8)), 0.3, 3, 0.05)],
        steps: [{ do: 'space', items: null, factor: 'factor' }],
      };
    }
    case 'evenly':
      return one('Spaced evenly', { do: 'space', items: null, even: true });
    case 'change':
      if (intent.text !== undefined) return one(`Text: “${intent.text}”`, { do: 'text', items: { codes: [16] }, text: intent.text });
      return inTurn(`Pitch: ${(intent.pitches ?? []).join(' ')}`, 'Pitch', intent.pitches ?? []);
    case 'again':
      // The last command once more, which the command field knows.
      return one('Again');
    case 'app':
      // The editor's own command, run by the command field rather than as steps.
      return one(intent.label ?? intent.command ?? '');
  }
}

const capital = (s: string) => s.charAt(0).toUpperCase() + s.slice(1);

/** A key by its signature, as a major key: 2 is D major, -3 E♭ major. */
function keyName(sharps: number): string {
  const sharpKeys = ['C', 'G', 'D', 'A', 'E', 'B', 'F♯', 'C♯'];
  const flatKeys = ['C', 'F', 'B♭', 'E♭', 'A♭', 'D♭', 'G♭', 'C♭'];
  return `${(sharps >= 0 ? sharpKeys[sharps] : flatKeys[-sharps]) ?? 'C'} major`;
}

/** A setting of the notes, column by column, from values in turn ("i % 3 == 1" takes the second of three). */
function inTurn(summary: string, setting: string, values: string[]): Script {
  const steps: Step[] = values.map((value, k) => ({ do: 'setting', items: { codes: [1], where: values.length > 1 ? `i % ${values.length} == ${k}` : null }, setting, value }));
  return { summary, knobs: [], steps };
}
