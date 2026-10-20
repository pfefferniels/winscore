// The two models an AI command can go to, and what they are told.
//
// Jev (TypeSafe's System One model) reads what a command means: one request
// of typed questions (which action, which items, which property, which of the
// command's numbers …), answered with probabilities in about a tenth of a
// second, so it is asked while the command is still being typed. Its answers
// fill an Intent (ai-intent.ts), turned into an edit script in code.
//
// Claude writes the edit script itself, for commands Jev is not sure of or
// that need more than its fixed choices. It is asked when Enter is pressed.
//
// Both are reached through the dev or preview server (ai-proxy.ts, keys from
// the environment) or directly from the page with keys kept in this browser.
import type Anthropic from '@anthropic-ai/sdk';
import { chainable, CREATIONS, MEASURES, PICKS, TARGETS, scriptFor, type Action, type Intent } from './ai-intent';
import { namedSettings, plain, type Filter, type Region, type Script, type Step } from './ai-script';
import { INTERVALS, RHYTHMS, meterIn, musicIn, namesCount, namesOption, numberOf, numberWords, quotedIn, rhythmsFor } from './ai-values';

// ---------------------------------------------------------------------------
// Settings and connections

export interface AiSettings {
  /** TypeSafe key, or an AI gateway's key for `jevUrl`; empty: the dev server's. */
  jevKey: string;
  jevUrl: string;
  /** Anthropic key; empty: the dev server's. */
  claudeKey: string;
  claudeModel: string;
  /** The model for commands Jev finds complex. */
  claudeComplexModel: string;
}

export const TYPESAFE_URL = 'https://api.typesafe.ai/v1/systemone';
/** Vercel's AI Gateway serves Jev to pages of any site (CORS), with a Vercel key. */
export const GATEWAY_URL = 'https://ai-gateway.vercel.sh/typesafe/v1/systemone';
export const CLAUDE_MODELS = [
  { id: 'claude-sonnet-5-5', label: 'Claude Sonnet 5.5 (fastest)', short: 'Sonnet' },
  { id: 'claude-haiku-5-5', label: 'Claude Haiku 5.5', short: 'Haiku' },
  { id: 'claude-opus-5-5', label: 'Claude Opus 5.5 (most capable)', short: 'Opus' },
];

const SETTINGS_KEY = 'winscore.ai';
const DEFAULTS: AiSettings = { jevKey: '', jevUrl: TYPESAFE_URL, claudeKey: '', claudeModel: 'claude-sonnet-5-5', claudeComplexModel: 'claude-opus-5-5' };

export function loadSettings(): AiSettings {
  try {
    return { ...DEFAULTS, ...(JSON.parse(localStorage.getItem(SETTINGS_KEY) ?? '{}') as Partial<AiSettings>) };
  } catch {
    return { ...DEFAULTS };
  }
}

export function saveSettings(settings: AiSettings) {
  try {
    localStorage.setItem(SETTINGS_KEY, JSON.stringify(settings));
  } catch {
    // Without storage the keys last until the page is left.
  }
}

/** Which keys the server the page came from holds (the dev or preview server); none for a static site. */
export async function serverKeys(): Promise<{ jev: boolean; claude: boolean }> {
  try {
    const response = await fetch(new URL('ai/status', document.baseURI));
    if (!response.ok || !response.headers.get('content-type')?.includes('json')) return { jev: false, claude: false };
    const status = (await response.json()) as { jev?: boolean; claude?: boolean };
    return { jev: Boolean(status.jev), claude: Boolean(status.claude) };
  } catch {
    return { jev: false, claude: false };
  }
}

export interface Connections {
  /** The gateway knows Jev as typesafe-ai/jev. */
  jev: { url: string; key: string | null; model: string } | null;
  /** `model` writes most commands, `complexModel` those Jev finds complex. */
  claude: { key: string | null; baseURL: string | undefined; model: string; complexModel: string } | null;
}

export function connections(settings: AiSettings, server: { jev: boolean; claude: boolean }): Connections {
  const local = (path: string) => new URL(path, document.baseURI).href;
  return {
    jev: settings.jevKey
      ? { url: settings.jevUrl || TYPESAFE_URL, key: settings.jevKey, model: settings.jevUrl === GATEWAY_URL ? 'typesafe-ai/jev' : 'jev-latest' }
      : server.jev
        ? { url: local('ai/jev'), key: null, model: 'jev-latest' }
        : null,
    claude: settings.claudeKey
      ? { key: settings.claudeKey, baseURL: undefined, model: settings.claudeModel, complexModel: settings.claudeComplexModel }
      : server.claude
        ? { key: null, baseURL: local('ai/anthropic'), model: settings.claudeModel, complexModel: settings.claudeComplexModel }
        : null,
  };
}

// ---------------------------------------------------------------------------
// What the models are told about the command

/** The command and the items it is about. */
export interface About {
  text: string;
  /** How many items of each code the command is about. */
  counts: Map<number, number>;
  /** Whether it is about the whole score (nothing was selected). */
  whole: boolean;
  region: Region | null;
  /** The middle line of the region's staff as a diatonic step from C0 (B4 = 34 for a treble clef), where typed notes start. */
  middle: number;
  /** Some of the items, every text among them, for Claude. */
  sample: Sampled[];
  /** Where the barlines are (P3) on the staves of the items, by staff, for Claude: where bars begin. */
  bars: Map<number, number[]>;
  /** The editor's own commands that can run now, which the command may ask for. */
  commands: AppCommand[];
  /** Names of item codes. */
  codeName(code: number): string;
}

/** One of the editor's own commands, an entry of its menus: "Save", "Zoom in", "Line up…". */
export interface AppCommand {
  id: string;
  /** As the menus show it: "File ▸ Save". */
  label: string;
  title: string;
}

/** One item as Claude is shown it: its identity (the scripts' `id`), P1 … Pn, and a text's characters. */
export interface Sampled {
  id: number;
  params: number[];
  text: string | null;
}

function selectionWords(about: About): string {
  const parts = [...about.counts].map(([code, n]) => `${n} × ${about.codeName(code)}`);
  return `${parts.join(', ') || 'nothing'}${about.whole ? ' (the whole score)' : ''}`;
}

// ---------------------------------------------------------------------------
// Jev

const ACTIONS: Record<Action | 'other', string> = {
  insert: 'Write or put new notes, chords or rests into the score, named by their pitches such as c, f#, bb4 or chords such as d/f/a, perhaps with their note value (add c e g as eighths, put e f# g here)',
  beam: 'Join notes with beams, or beam them in groups such as pairs',
  unbeam: 'Take the beams away so the notes are no longer beamed',
  delete: 'Remove, delete, erase, clear, take away or hide something: items such as rests, slurs or dynamics, or a part of notes such as their stems, accidentals, articulation marks or dots',
  flip: 'Flip, invert or turn over stems, slurs or symbols to the other side',
  'stems-up': 'Make the stems point up',
  'stems-down': 'Make the stems point down',
  'stems-auto': 'Give the notes their normal stem directions, or give them stems again',
  option:
    'Give the selected items themselves a named property: add or change an articulation or mark on them (accent them, add staccatos, fermatas on the notes), an accidental (sharpen them, flatten them, make them natural), a note value (make them eighths, half notes), a note head shape, cue size, the type of the clefs selected or a line style (dashed, dotted)',
  bigger: 'Make them all larger, longer, thicker or wider by the same amount',
  smaller: 'Make them all smaller, shorter, thinner or narrower by the same amount',
  grow: 'Make a size increase gradually across the items, each a little bigger than the one before, or from one value to a larger one (sizes from 1 to 3)',
  shrink: 'Make a size decrease gradually across the items, each a little smaller than the one before, or from one value to a smaller one (sizes from 2 to 1)',
  move: 'Move, shift, raise, lower or transpose the items',
  align: 'Put the items at one height, in a straight row',
  number: 'Set a named property to a number the command gives, such as size 1.5 or stem length 3',
  command: 'A command in the SCORE program’s own language, short upper-case words and numbers such as FLI or R 5',
  create:
    'Add one new item of its own, not notes and not a mark on them: a staff, a barline, a repeat, a new clef, a key or time signature such as 3/4 or common time, a slur or tie over the notes (slur them, tie them), a hairpin, a trill, an 8va, a pedal mark, an ending, a dynamic such as mf, a fermata, a box, a number or a text in quotes',
  select: 'Select, pick out or keep only some of the items, so that the next command acts on them; nothing is changed (select the bottom notes, select the beams, keep only the accented notes)',
  app: 'A command of the editor rather than an edit of the music: undo, redo, copy, cut, paste, duplicate, select everything, save, open, print, export, a new score, zoom, show or hide the side panel, line up or justify, help',
  other: 'Something else',
};

const DIRECTIONS = { none: 'no direction is given', up: 'up, higher, raise', down: 'down, lower', left: 'left, earlier, backwards', right: 'right, later, forwards' };

// Jev leans to the first option: "all" goes first, so a command must pick some out to be read so.
const PICK = {
  all: 'all of them, or all of one kind or with one property, such as all the stems or all the staccatos',
  ...Object.fromEntries(Object.entries(PICKS).map(([id, p]) => [id, p.words])),
  other: 'some picked out in another way, by their place or order, such as the second bar or the notes on the beat',
};

/** Key signatures by sharps (positive) or flats, with their keys. */
const KEYS: Record<string, string> = {
  none: 'no key and no number of sharps or flats is named',
  ...Object.fromEntries(
    ['C major, A minor', 'G major, E minor', 'D major, B minor', 'A major, F sharp minor', 'E major, C sharp minor', 'B major, G sharp minor', 'F sharp major, D sharp minor', 'C sharp major, A sharp minor'].map((keys, n) => [String(n), n === 0 ? `no sharps or flats: ${keys}` : `${numberName(n)} sharp${n > 1 ? 's' : ''}: ${keys}`]),
  ),
  ...Object.fromEntries(
    ['F major, D minor', 'B flat major, G minor', 'E flat major, C minor', 'A flat major, F minor', 'D flat major, B flat minor', 'G flat major, E flat minor', 'C flat major, A flat minor'].map((keys, i) => [String(-i - 1), `${numberName(i + 1)} flat${i ? 's' : ''}: ${keys}`]),
  ),
};

function numberName(n: number): string {
  return ['no', 'one', 'two', 'three', 'four', 'five', 'six', 'seven'][n] ?? String(n);
}

/** KSIG's letter for the clef in force, by the staff's middle line (ai-values' steps from C0): bass, alto, tenor. */
const KEY_CLEFS: Record<number, string> = { 22: 'B', 28: 'A', 26: 'T' };

/** A request Jev takes longer for than this goes unanswered: Enter has Claude write the command. */
const JEV_TIMEOUT_MS = 3000;

/** Below this, a reading goes to Claude instead. */
const SURE = 0.5;
/** Answers that only narrow a reading (a note value for new notes, a property for removing) need more. */
const QUITE_SURE = 0.75;

// Jev leans to the first option: "simple" goes first, so a command must clearly ask for thought to be complex.
const COMPLEXITY = {
  simple:
    'One plain edit: a property, size, place or value given to the items, or to some of them picked out by place or kind, one new item, or a command of the editor (accent the last note, remove the stems, make the slurs flatter, stems down on the bottom notes of the chords, add a staff, a slur over these notes, save)',
  complex:
    'Work that takes thought: new music worked out from a description or from the music there (an arpeggio, a scale, a second voice, a bass line, the melody backwards or upside down), several edits that depend on one another, or items and values worked out for each item from others (a pattern, a rule over the music, lines connecting the notes, a hairpin under each slur)',
};

// Jev leans to the first option: "no number" goes first, so a number must be named to be chosen.
const GROUPS = {
  runs: 'no number of notes per beam is given: every run of notes up to the next barline',
  '2': 'pairs, twos, two notes per beam',
  '3': 'threes, three notes per beam',
  '4': 'fours, four notes per beam',
  '6': 'sixes, six notes per beam',
  '8': 'eights, eight notes per beam',
};

type Question = { type: 'choice'; instructions: string; criteria: Record<string, string | null> } | { type: 'noul'; instructions: string };

interface ChoiceAnswer {
  type: 'choice';
  choice: string;
  probabilities: Record<string, number>;
  confidence: number;
}

/** Choice criteria with at most 255 options. */
const capped = (criteria: Record<string, string | null>) => Object.fromEntries(Object.entries(criteria).slice(0, 255));

/** The properties items of `code` can be given, as "Setting: Option" (toggles on and off). */
function optionCriteria(code: number): Record<string, string | null> {
  const criteria: Record<string, string | null> = {};
  for (const [, entries] of namedSettings(code)) {
    for (const { name, setting } of entries) {
      if (name === 'Staff' || name === 'Position') continue;
      if (setting.kind === 'choice') for (const o of setting.options) criteria[`${name}: ${o.label}`] = null;
      if (setting.kind === 'toggle') {
        criteria[`${name}: on`] = setting.help ?? null;
        criteria[`${name}: off`] = null;
      }
    }
  }
  // Jev leans to the first option: "none" goes first, so a property must be named to be chosen.
  return { none: 'No property from this list is named', ...criteria };
}

function numberSettings(codes: number[]): string[] {
  const names = new Set<string>();
  for (const code of codes) for (const [, entries] of namedSettings(code)) for (const { name, setting } of entries) if (setting.kind === 'number') names.add(name);
  return [...names];
}

/** Every question for one command, asked at once: the answers that matter are picked afterwards. */
function jevQuestions(about: About): Record<string, Question> {
  const codes = [...about.counts.keys()];
  const present = (target: (typeof TARGETS)[number]) => target.codes.length === 0 || target.codes.some((c) => about.counts.has(c));
  const questions: Record<string, Question> = {
    action: { type: 'choice', instructions: 'What does the `command` ask to do with the selected items of the music score?', criteria: ACTIONS },
    pick: { type: 'choice', instructions: 'Does the `command` act on all the selected items it names, or only on some of them it picks out? Which?', criteria: PICK },
    target: {
      type: 'choice',
      instructions: 'Which items or which part of them does the `command` act on? Choose "all" when it names none and means the selection.',
      criteria: Object.fromEntries(TARGETS.filter(present).map((t) => [t.id, `${t.noun}: ${t.words.join(', ')}`])),
    },
    measure: {
      type: 'choice',
      instructions: 'Which measure of the items does the `command` change?',
      criteria: Object.fromEntries(Object.entries(MEASURES).map(([id, m]) => [id, m.noun])),
    },
    direction: { type: 'choice', instructions: 'Which way does the `command` move the items?', criteria: DIRECTIONS },
    interval: {
      type: 'choice',
      instructions: 'Which musical interval does the `command` name for moving or transposing?',
      criteria: { none: 'none is named', ...Object.fromEntries(Object.keys(INTERVALS).map((k) => [k, `a ${k}`])) },
    },
    group: { type: 'choice', instructions: 'How many notes does the `command` want under each beam?', criteria: GROUPS },
    then: {
      type: 'choice',
      instructions: 'Besides its main action, does the `command` ask for a second, different thing? Which?',
      criteria: { none: 'only one thing is asked', ...Object.fromEntries(Object.entries(ACTIONS).filter(([id]) => id !== 'other')) },
    },
    complexity: { type: 'choice', instructions: 'How much thought does carrying out the `command` on the score take?', criteria: COMPLEXITY },
    item: {
      type: 'choice',
      instructions: 'Which new item does the `command` ask to add?',
      criteria: { none: 'no new item, or new notes', ...Object.fromEntries(Object.entries(CREATIONS).map(([id, c]) => [id, c.words])) },
    },
  };
  if (about.commands.length > 0) {
    questions.menu = {
      type: 'choice',
      instructions: 'Which of the editor’s commands does the `command` ask for?',
      criteria: capped({ none: 'none of these', ...Object.fromEntries(about.commands.map((c) => [c.id, c.title ? `${c.label}: ${c.title}` : c.label])) }),
    };
  }
  if (/\bkey\b|major|minor|sharps|flats/i.test(about.text)) {
    questions.key = { type: 'choice', instructions: 'Which key signature does the `command` name?', criteria: KEYS };
  }
  if (about.counts.has(1)) {
    questions.also = {
      type: 'choice',
      instructions:
        'Does the `command` give the notes a new property alongside its main action, such as a note value in "8th beam" or "sixteenths beamed in fours"? Which? Choose none when it only names which notes it acts on, as in "beam the eighths".',
      criteria: capped(optionCriteria(1)),
    };
  }
  for (const code of codes) {
    const criteria = optionCriteria(code);
    if (Object.keys(criteria).length > 1) {
      questions[`option.${code}`] = { type: 'choice', instructions: `Which property does the \`command\` give the ${about.codeName(code).toLowerCase()} items, or take from them?`, criteria: capped(criteria) };
    }
  }
  const numbers = numberWords(about.text);
  if (numbers.length > 0) {
    const options = { none: 'the command gives no such number', ...Object.fromEntries(numbers.map((n) => [n, null])) };
    questions.amount = { type: 'choice', instructions: 'Which number in the `command` says how much: a distance, a factor, a size or a count?', criteria: options };
    questions.setting = {
      type: 'choice',
      instructions: 'Which property does the `command` set to a number?',
      criteria: capped({ none: 'no property is named', ...Object.fromEntries(numberSettings(codes).map((n) => [n, null])) }),
    };
    questions.count = { type: 'choice', instructions: 'Which number in the `command` says how many of the items it picks out, as in "the first three notes"?', criteria: options };
    if (numbers.length > 1) {
      questions.from = { type: 'choice', instructions: 'Which number in the `command` is the starting value?', criteria: options };
      questions.to = { type: 'choice', instructions: 'Which number in the `command` is the final value?', criteria: options };
    }
  }
  if (musicIn(about.text)) {
    questions.rhythm = {
      type: 'choice',
      instructions: 'Which note value does the `command` give the new notes?',
      criteria: { none: 'none is given', ...Object.fromEntries(Object.keys(RHYTHMS).map((k) => [k, null])) },
    };
  }
  return questions;
}

/** Why a reading has no intent, said to the user: what Claude would be asked to do. */
export type Unread = 'unsure' | 'other' | 'some' | 'nothing' | 'detail' | 'complex';

export const UNREAD: Record<Unread, string> = {
  unsure: 'Jev is not sure what this asks',
  other: 'This is not one of Jev’s actions',
  some: 'This picks out some of the items',
  nothing: 'There is nothing selected for this',
  detail: 'Jev misses a detail of this',
  complex: 'This takes thought',
};

/** Jev's reading: the intent, or why there is none; the action's probability either way. */
export interface JevReading {
  intent: Intent | null;
  why: Unread | null;
  action: string;
  confidence: number;
  /** Whether the command takes thought: Claude's model for complex commands writes it. */
  complex: boolean;
  ms: number;
  /** Jev's answers, for seeing why. */
  answers: Record<string, { choice: string; confidence: number }>;
}

/** What each chainable action reads from answers the two actions of a chain would share. */
const READS: Partial<Record<Action, string[]>> = {
  beam: ['amount'],
  option: ['property'],
  number: ['amount'],
  bigger: ['measure', 'amount'],
  smaller: ['measure', 'amount'],
  grow: ['measure', 'amount'],
  shrink: ['measure', 'amount'],
  move: ['direction', 'amount'],
};

/** Actions a property given alongside ("8th beam") goes with. */
const ALONGSIDE = new Set<Action>(['beam']);

/**
 * The command's intent: its action, and a second one when Jev hears one
 * that can safely run with it (else Claude writes it), or a property given
 * alongside ("8th beam") when the command names it.
 */
function readAnswers(about: About, answers: Record<string, ChoiceAnswer>): Intent | Unread {
  const action = answers.action?.choice as Action | 'other' | undefined;
  const first = readAction(about, answers, action);
  if (typeof first === 'string') return first;
  const then = answers.then;
  const second = then && then.choice !== 'none' && then.confidence >= QUITE_SURE ? (then.choice as Action) : null;
  if (second && second !== first.action) {
    // Both read the same answers: only actions that take different ones, on the notes or everything, go together.
    const shared = (READS[first.action] ?? []).some((r) => (READS[second] ?? []).includes(r));
    if (!chainable(first.action) || !chainable(second) || shared || !['all', 'notes'].includes(first.target)) return 'detail';
    const other = readAction(about, answers, second);
    if (typeof other === 'string') return other;
    const ids = new Set(scriptFor(first).knobs.map((k) => k.id));
    if (scriptFor(other).knobs.some((k) => ids.has(k.id))) return 'detail';
    return { ...first, then: other };
  }
  const also = answers.also;
  if (ALONGSIDE.has(first.action) && also && also.choice !== 'none' && also.confidence >= QUITE_SURE) {
    const [setting, option] = also.choice.split(': ');
    if (setting && option && namesOption(about.text, option)) return { ...first, then: { action: 'option', target: 'notes', setting, option } };
  }
  return first;
}

/** The intent of one action the command asks for, from the answers. */
function readAction(about: About, answers: Record<string, ChoiceAnswer>, action: Action | 'other' | undefined): Intent | Unread {
  const choice = (id: string) => answers[id]?.choice;
  /** An answer Jev is sure of, other than none. */
  const sure = (id: string, enough = SURE) => {
    const a = answers[id];
    return a && a.choice !== 'none' && a.confidence >= enough ? a.choice : undefined;
  };
  if (!action || action === 'other') return 'other';
  // Everything but new music, new items and the editor's commands acts on items: with none, the reading is wrong.
  if (!['insert', 'create', 'app'].includes(action) && about.counts.size === 0) return 'nothing';
  const target = choice('target') ?? 'all';
  /** The number a question picked, as written ("50%" stays a percentage). */
  const picked = (id: string) => {
    const c = choice(id);
    return c === undefined || c === 'none' ? undefined : c;
  };
  const number = (id: string) => {
    const word = picked(id);
    return word === undefined ? undefined : numberOf(word);
  };
  const intent: Intent = { action, target };
  const targetCodes = TARGETS.find((t) => t.id === target)?.codes ?? [];
  // The property: for the target's kind, else the surest one any kind gave.
  const options = Object.entries(answers)
    .filter(([id, a]) => id.startsWith('option.') && a.choice !== 'none')
    .sort((a, b) => b[1].confidence - a[1].confidence);
  const option = options.find(([id]) => targetCodes.includes(Number(id.slice(7)))) ?? options[0];
  if (option) {
    const [setting, value] = option[1].choice.split(': ');
    intent.setting = setting;
    intent.option = value;
  }
  // No property to give, but a new item Jev is quite sure of: that is meant ("add mf" to notes, which have no such mark).
  if (action === 'option' && !option && sure('item', QUITE_SURE)) intent.action = action = 'create';
  // Some items picked out by place ("the last note", "every other one"); picked some other way, Claude
  // writes it. New music and items where nothing is selected, and the editor's commands, pick none.
  const pick = sure('pick');
  const picks = !['insert', 'app'].includes(action) && !(action === 'create' && about.whole);
  if (picks && pick === 'other') return 'some';
  if (picks && pick && PICKS[pick]) {
    intent.pick = pick;
    if (pick.endsWith('few')) intent.many = number('count');
  }
  switch (action) {
    case 'insert': {
      const music = musicIn(about.text, about.middle);
      if (!music) return 'detail';
      intent.notes = music.notes;
      intent.typed = music.typed;
      const rhythm = answers.rhythm && answers.rhythm.confidence >= QUITE_SURE ? choice('rhythm') : undefined;
      // Values typed with the notes win over one Jev reads ("c e g 4 8 8").
      intent.rhythms = music.rhythms ?? rhythmsFor(rhythm, music.count);
      return intent;
    }
    case 'beam': {
      // Without a count in the command Jev takes the selection's size ("beam them", 8 notes selected: eights).
      const group = namesCount(about.text) ? choice('group') : undefined;
      intent.amount = group && group !== 'runs' ? Number(group) : number('amount');
      return intent;
    }
    case 'option':
      return intent.setting && intent.option ? intent : 'detail';
    case 'create':
      return createIntent(about, intent, sure, number);
    case 'app': {
      const command = about.commands.find((c) => c.id === sure('menu'));
      return command ? { ...intent, command: command.id, label: command.label } : 'detail';
    }
    case 'delete':
    case 'select':
      // "the eighth notes": only those. Half sure of a property is not enough to delete
      // (or select) all of them instead, nor only some: Claude decides.
      if (option && option[1].confidence < QUITE_SURE) {
        if (option[1].confidence >= 0.4) return 'detail';
        delete intent.setting;
        delete intent.option;
      }
      return intent;
    case 'number': {
      const setting = choice('setting');
      const value = number('amount');
      if (!setting || setting === 'none' || value === undefined) return 'detail';
      return { ...intent, setting, value };
    }
    case 'bigger':
    case 'smaller':
    case 'grow':
    case 'shrink':
      intent.measure = choice('measure');
      intent.from = number('from');
      intent.to = number('to');
      if (action === 'grow' || action === 'shrink') intent.to ??= number('amount');
      else {
        // "50% bigger" multiplies by 1.5, "20% smaller" by 0.8; "bigger by 2" by 2.
        const word = picked('amount');
        intent.amount = word === undefined ? undefined : word.endsWith('%') ? 1 + (action === 'bigger' ? 1 : -1) * numberOf(word) : numberOf(word);
      }
      return intent;
    case 'move': {
      const direction = choice('direction');
      if (!direction || direction === 'none') return 'detail';
      intent.direction = direction as Intent['direction'];
      // A number given wins over an interval read into it ("5 to the right" is not a fifth).
      const interval = choice('interval');
      intent.amount = number('amount') ?? (interval && interval !== 'none' ? INTERVALS[interval] : undefined);
      return intent;
    }
    case 'command':
      return { ...intent, line: about.text.trim() };
    default:
      return intent;
  }
}

/**
 * A new item's intent: its creation word, with the key, meter, number or
 * text the command gives; a key signature or text without one is Claude's.
 */
function createIntent(about: About, intent: Intent, sure: (id: string) => string | undefined, number: (id: string) => number | undefined): Intent | Unread {
  const item = sure('item');
  if (!item || !CREATIONS[item]) return 'detail';
  const made: Intent = { ...intent, item };
  switch (item) {
    case 'key signature': {
      const key = sure('key');
      if (key === undefined) return 'detail';
      const n = Number(key);
      return { ...made, word: `KSIG${n < 0 ? '' : '+'}${n}${KEY_CLEFS[about.middle] ?? ''}`, label: `Add a key signature: ${KEYS[key]!.split(':')[0]}` };
    }
    case 'meter': {
      const meter = meterIn(about.text);
      return meter ? { ...made, word: `METER${meter[0]}${meter[1]}`, label: `Add a ${meter.join('/')} meter` } : made;
    }
    case 'number': {
      const value = number('amount');
      return value === undefined ? made : { ...made, more: [0, value], label: `Add the number ${value}` };
    }
    case 'text': {
      const text = quotedIn(about.text);
      return text ? { ...made, text, label: `Add “${text}”` } : 'detail';
    }
    default:
      return made;
  }
}

async function systemOne(connection: NonNullable<Connections['jev']>, body: unknown, signal: AbortSignal): Promise<Record<string, ChoiceAnswer>> {
  const headers: Record<string, string> = { 'content-type': 'application/json' };
  if (connection.key) headers.authorization = `Bearer ${connection.key}`;
  let response: Response;
  const timeout = AbortSignal.timeout(JEV_TIMEOUT_MS);
  try {
    // Without AbortSignal.any (Safari before 17.4) the request waits as long as it takes.
    response = await fetch(connection.url, { method: 'POST', headers, body: JSON.stringify(body), signal: 'any' in AbortSignal ? AbortSignal.any([signal, timeout]) : signal });
  } catch (err) {
    if (timeout.aborted && !signal.aborted) throw new Error('Jev did not answer in time');
    if (signal.aborted || connection.url !== TYPESAFE_URL) throw err;
    throw new Error('Jev: TypeSafe does not answer this page directly; use the dev server or the AI Gateway (⚙)');
  }
  if (!response.ok) {
    const text = await response.text();
    throw new Error(`Jev: ${response.status} ${text.slice(0, 200)}`);
  }
  return ((await response.json()) as { answers: Record<string, ChoiceAnswer> }).answers;
}

/** What Jev makes of a command. */
export async function askJev(about: About, connection: NonNullable<Connections['jev']>, signal: AbortSignal): Promise<JevReading> {
  const started = performance.now();
  const state = { command: about.text, selected: selectionWords(about) };
  const answers = await systemOne(connection, { model: connection.model, state, questions: jevQuestions(about) }, signal);
  const action = answers.action;
  const complex = answers.complexity?.choice === 'complex' && answers.complexity.confidence >= SURE;
  // At a place on the paper (the whole score), a new item Jev is quite sure of is meant rather than a mark on every
  // note of the score, however sure it is that a property is asked for ("add a fermata", "put "dolce" here"), unless
  // the command names the items it gives it ("make all the clefs bass clefs").
  const [item, target] = [answers.item, answers.target];
  const names = target !== undefined && target.choice !== 'all' && target.confidence >= SURE;
  const placed = about.whole && item !== undefined && item.choice !== 'none' && item.confidence >= QUITE_SURE && (action?.choice === 'create' || (action?.choice === 'option' && !names));
  const read = !action || (action.confidence < SURE && !placed) ? 'unsure' : complex ? 'complex' : readAnswers(about, placed ? { ...answers, action: { ...action, choice: 'create' } } : answers);
  const [intent, why] = typeof read === 'string' ? [null, read] : [read, null];
  return { intent, why, action: action?.choice ?? 'other', confidence: action?.confidence ?? 0, complex, ms: performance.now() - started, answers };
}

let warmed = 0;

/**
 * A one-question request when the field opens, at most once a minute: the
 * connection is open and the first command read as fast as the next.
 */
export function warmJev(connection: NonNullable<Connections['jev']>) {
  if (performance.now() - warmed < 60_000 && warmed) return;
  warmed = performance.now();
  const body = { model: connection.model, state: 'warm-up', questions: { ready: { type: 'noul', instructions: 'Is this a warm-up?' } } };
  systemOne(connection, body, new AbortController().signal).catch(() => (warmed = 0));
}

/** Jev's reading as an edit script, if it has one (the editor's own commands have none). */
export function jevScript(reading: JevReading): Script | null {
  return reading.intent && reading.intent.action !== 'app' ? scriptFor(reading.intent) : null;
}

/** The editor's command Jev read, if it read one. */
export function jevCommand(reading: JevReading): AppCommand | null {
  const intent = reading.intent;
  return intent?.action === 'app' && intent.command ? { id: intent.command, label: intent.label ?? intent.command, title: '' } : null;
}

// ---------------------------------------------------------------------------
// Claude

/** What the page knows that Claude should: the settings of each code and SCORE's edit words. */
export interface Catalog {
  codes: { code: number; name: string }[];
  /** WinScore's edit words, [word, codes, meaning]. */
  words: [string, number[], string][];
}

function settingLines(code: number): string {
  const lines: string[] = [];
  for (const [, entries] of namedSettings(code)) {
    for (const { name, setting } of entries) {
      const p = 'id' in setting && /^p\d+$/.test(setting.id) ? ` (${setting.id.toUpperCase()})` : '';
      if (setting.kind === 'choice') lines.push(`  - ${name}: ${setting.options.map((o) => o.label).join(' | ')}`);
      else if (setting.kind === 'toggle') lines.push(`  - ${name}: on | off`);
      else if (setting.kind === 'text') lines.push(`  - ${name}: text, e.g. ${setting.placeholder ?? ''}`);
      else lines.push(`  - ${name}${p}: number${setting.help ? ` — ${setting.help}` : ''}`);
    }
  }
  return [...new Set(lines)].join('\n');
}

/** The system prompt: the same for every command, so it is cached. */
function systemPrompt(catalog: Catalog): string {
  const settings = catalog.codes.map(({ code, name }) => `Code ${code}, ${name}:\n${settingLines(code)}`).join('\n');
  const words = catalog.words.map(([word, codes, meaning]) => `${word} [${codes.join(',')}] ${meaning}`).join('\n');
  return `You turn an engraver's command, typed while editing a score in WinScore (Leland Smith's SCORE), into an edit script that the editor runs at once on the real score. Answer with the script only.

# The score
A score is a list of items, each a row of numbers P1 … Pn. P1 is the item's code (what it is), P2 its staff number (staff 1 is the lowest on the page), P3 its horizontal position on the staff (0 at the left edge, 200 at the right), P4 its vertical level in scale steps (half the distance between staff lines; on a treble staff level 1 is middle C, level 3 the bottom line, level 11 the top line). The other parameters depend on the code; the settings below name them. A text (code 16) also has characters, shown after its numbers (a leading _NN is its font); it begins at P3 and is P13 long. Lyrics are a text for each syllable, with a "-" text centred between the syllables of a word.

# The script
{"summary": a few words on what it does, "knobs": [...], "steps": [...]}

Steps run in order, each on the items the command is about (the selection, or the whole score when nothing is selected). Every step has all of these fields; give the ones its kind uses and leave the others empty ("", 0 or []):
- "do": what it does:
  - "setting": the setting named "setting" becomes "value" (an option's name, on or off, a number or an expression). Prefer this: the editor packs the parameters itself.
  - "set": parameter P"param" becomes "value" (a number or an expression).
  - "move": move by "right" P3 spaces and "up" scale steps, as the arrow keys move items, ends of lines and slurs included. Notes move by whole steps (diatonic transposition).
  - "delete": the items go.
  - "command": the SCORE edit word in "line" on the items, such as "NST" or "FLI" (below), or a group command (FLN, FLU, FLD refit stems, beams and slurs over the items' area), or "STAFF", which makes a new staff above the highest.
  - "insert": a line of music input on "staff" between P3 "from" and "to" (0 for all three: where new music goes, given below), from the five passes "notes", "rhythms", "marks", "beams", "slurs". Pass 1: notes C D E F G A B with accidentals F (flat), S (sharp), N, FF, SS and octave 0–8 (C4 is middle C, the octave persists), items separated by /, chord notes by : (C4:E:G), R a rest, M a barline; a P before the first note gives each note the octave nearest the one before (PC4/E/G). Pass 2: one value per note, chord or rest: 1 whole, 2 half, 4 quarter, 8 eighth, 16, 32; a dot after it dots it (4.); always give it, as notes without a value become grace notes. Passes 3–5 may stay empty.
  - "beam": beams over "size" notes or chords each ("0" for every run up to a barline); the engine refits stems and flags.
  - "select": the items it picks become the selection, and the steps after it act on them only; nothing is edited. A command to select, keep only or pick out items is this, never a delete.
  - "add": for each item it picks, a new item whose P1, P2, P3 … are "params" (numbers or expressions over the item it is made for; the settings below give each code's parameter numbers); an item whose P1 comes to 0 is not made. Lines (code 4) and slurs (code 5) run from P3, P4 to P6, P5. A text (code 16) has the characters in "text" and is made as SCORE's quick entry makes it: P2 … P11 from "params" (0 keeps the default), P3 plus 1000 centres it on P3.
- Which items a step acts on: "codes" (empty for all), "where" (an expression that must hold, or ""), and "where_setting" with "where_is" (only the items whose setting reads that option, e.g. "Mark" and "Staccato", or "" and "").
- "value", "right", "up", "size": text holding a number, an expression or an option's name.
- "text": the characters of the texts an "add" makes.

Values may be expressions: numbers, + - * / % ^, comparisons, && || !, a ? b : c, functions min max abs round floor ceil sqrt pow lerp(a,b,t) clamp(x,lo,hi) snap(x,step), and these names for each item: p1 … p45 (its parameters), id (its identity, as the items are listed: "id == 412 || id == 415" picks those two), staff, x (P3), level (P4 without the cue-size hundred), value (the setting's current value; 0 often means the default, e.g. size 0 is size 1), mean (the mean of that parameter over the items, in set steps), t (0 for the first column of items from left to right, 1 for the last; the notes of a chord share one), i and n (that column's number from 0, and how many there are), st, si, sn (the same on the item's own staff), next_x and next_level (the position of the next note or chord, or item of the step's codes, on its staff, for a text the next text on its line (within a step of its level), and its level nearest this item's; the item's own for the last), bar, bi, bn, bt (its bar on its staff from 0, by the barlines, and the same as i, n, t within that bar: "bi == 0" is the first note or chord of each bar, "bi == bn - 1" the last), left and right (the leftmost and rightmost P3 of the items on its staff), count, chord_low and chord_high (the lowest and highest level among the notes of its chord, its notes at the same place on its staff, a lone note being its own chord: "level == chord_low" is the bottom note of each chord), chord_size (how many notes that chord has), min_p1 … min_p45, max_p1 … max_p45 and mean_p1 … mean_p45 (a parameter's smallest, largest and mean value over the items; min_level, max_level and mean_level the same for level, so "level == max_level" is the single highest note), and the knobs by id. There are no functions over the items: max(p4) is just p4.

Knobs are numbers the command leaves open — how much bigger, how fast something grows, how far to move. Give each a slider: {"id": a name used in expressions, "label": two or three words, "min", "max", "step", "value": a sensible default}. The user drags the slider and the script runs again at once. A command that says everything needs no knobs ([]).

# Settings by code
${settings}

# Edit words ([codes] they apply to)
${words}

# Examples
A step leaves out its unused fields here for brevity; give every field ("params" [] when unused).
"remove the stems" → {"summary": "Remove stems", "knobs": [], "steps": [{"do": "setting", "codes": [1], "setting": "Stem", "value": "None"}]}
"remove the staccatos" → {"summary": "Remove staccatos", "knobs": [], "steps": [{"do": "setting", "codes": [1], "where_setting": "Mark", "where_is": "Staccato", "setting": "Mark", "value": "None"}]}
"make the notes gradually bigger" → {"summary": "Notes grow", "knobs": [{"id": "to", "label": "Final size", "min": 0.5, "max": 4, "step": 0.05, "value": 1.8}, {"id": "curve", "label": "Curve", "min": 0.25, "max": 4, "step": 0.05, "value": 1}], "steps": [{"do": "setting", "codes": [1], "setting": "Size", "value": "round((1 + (to - 1) * t ^ curve) * 100) / 100"}]}
"make the slurs flatter" → {"summary": "Flatter slurs", "knobs": [{"id": "k", "label": "Curvature ×", "min": 0, "max": 1, "step": 0.05, "value": 0.5}], "steps": [{"do": "setting", "codes": [5], "setting": "Curvature", "value": "round(value * k * 100) / 100"}]}
"accent the last note" → {"summary": "Accent the last note", "knobs": [], "steps": [{"do": "setting", "codes": [1], "where": "t == 1", "setting": "Mark", "value": "Accent"}]}
"stems down on the bottom notes of the chords" → {"summary": "Bottom notes stem down", "knobs": [], "steps": [{"do": "setting", "codes": [1], "where": "level == chord_low && chord_size > 1", "setting": "Stem", "value": "Down"}]}
"select only the top notes" → {"summary": "Select the top notes", "knobs": [], "steps": [{"do": "select", "codes": [1], "where": "level == chord_high"}]}
"connect the notes with lines" → {"summary": "Lines from note to note", "knobs": [], "steps": [{"do": "add", "codes": [1], "where": "si < sn - 1", "params": ["4", "staff", "x + 1.5", "level", "next_level", "next_x"]}]}
"add c e g" → {"summary": "Add C E G", "knobs": [], "steps": [{"do": "insert", "staff": 0, "from": 0, "to": 0, "notes": "PC5/E/G", "rhythms": "4/4/4"}]}
"add the missing hyphens to the lyrics" (412 and 415 are syllables a word goes on from) → {"summary": "Hyphens between syllables", "knobs": [], "steps": [{"do": "add", "codes": [16], "where": "id == 412 || id == 415", "params": ["16", "staff", "1000 + (x + p13 + next_x) / 2", "p4", "p5", "p6"], "text": "-"}]}`;
}

/** One step as Claude writes it: every field there, none of them a union (the API allows few). */
interface Written {
  do: Exclude<Step['do'], 'create'>;
  codes: number[];
  where: string;
  where_setting: string;
  where_is: string;
  setting: string;
  param: number;
  value: string;
  right: string;
  up: string;
  line: string;
  staff: number;
  from: number;
  to: number;
  notes: string;
  rhythms: string;
  marks: string;
  beams: string;
  slurs: string;
  size: string;
  params: string[];
  text: string;
}

const STRING = { type: 'string' };
const NUMBER = { type: 'number' };

/** The script as a JSON schema for structured output: flat, every field required. */
export const SCRIPT_SCHEMA = {
  type: 'object',
  additionalProperties: false,
  required: ['summary', 'knobs', 'steps'],
  properties: {
    summary: STRING,
    knobs: {
      type: 'array',
      items: {
        type: 'object',
        additionalProperties: false,
        required: ['id', 'label', 'min', 'max', 'step', 'value'],
        properties: { id: STRING, label: STRING, min: NUMBER, max: NUMBER, step: NUMBER, value: NUMBER },
      },
    },
    steps: {
      type: 'array',
      items: {
        type: 'object',
        additionalProperties: false,
        required: ['do', 'codes', 'where', 'where_setting', 'where_is', 'setting', 'param', 'value', 'right', 'up', 'line', 'staff', 'from', 'to', 'notes', 'rhythms', 'marks', 'beams', 'slurs', 'size', 'params', 'text'],
        properties: {
          do: { type: 'string', enum: ['setting', 'set', 'move', 'delete', 'command', 'insert', 'beam', 'select', 'add'] },
          codes: { type: 'array', items: { type: 'integer' } },
          where: STRING,
          where_setting: STRING,
          where_is: STRING,
          setting: STRING,
          param: { type: 'integer' },
          value: STRING,
          right: STRING,
          up: STRING,
          line: STRING,
          staff: NUMBER,
          from: NUMBER,
          to: NUMBER,
          notes: STRING,
          rhythms: STRING,
          marks: STRING,
          beams: STRING,
          slurs: STRING,
          size: STRING,
          params: { type: 'array', items: STRING },
          text: STRING,
        },
      },
    },
  },
};

/** A step as the script runs it. */
function stepOf(w: Written): Step {
  const items: Filter = { codes: w.codes?.length ? w.codes : null, where: w.where || null, setting: (w.where_is && w.where_setting) || null, is: w.where_is || null };
  const text = (v: string | undefined) => (v ?? '').trim();
  switch (w.do) {
    case 'setting':
      return { do: 'setting', items, setting: w.setting, value: text(w.value) };
    case 'set':
      return { do: 'set', items, param: w.param, value: text(w.value) };
    case 'move':
      return { do: 'move', items, right: text(w.right) || 0, up: text(w.up) || 0 };
    case 'delete':
      return { do: 'delete', items };
    case 'command':
      return { do: 'command', items, line: w.line };
    case 'insert':
      return { do: 'insert', staff: w.staff || null, from: w.from || null, to: w.to || null, notes: w.notes, rhythms: w.rhythms, marks: w.marks, beams: w.beams, slurs: w.slurs };
    case 'beam':
      return { do: 'beam', items, size: text(w.size) || 0 };
    case 'select':
      return { do: 'select', items };
    case 'add':
      return { do: 'add', items, params: w.params ?? [], text: w.text || null };
  }
}

function userMessage(about: About): string {
  const region = about.region ? `staff ${about.region.staff}${about.region.top !== about.region.staff ? `–${about.region.top}` : ''}, P3 ${Math.round(about.region.from)} to ${Math.round(about.region.to)}` : 'nowhere';
  const rows = about.sample.map(({ id, params, text }) => `${params.map((v) => +v.toFixed(3)).join(' ')}${text === null ? '' : ` ${JSON.stringify(text)}`} (id ${id})`).join('\n');
  const some = about.sample.length < [...about.counts.values()].reduce((a, b) => a + b, 0);
  return `Command: ${about.text}
Selected: ${selectionWords(about)}
New music goes: ${region}
Barlines (P3) on these staves: ${[...about.bars].map(([staff, xs]) => `staff ${staff}: ${xs.map((x) => +x.toFixed(2)).join(', ') || 'none'}`).join('; ') || 'none'}
Items (P1 … Pn, a text's characters, the id)${some ? `, the first of them${about.counts.has(16) ? ' and the texts' : ''}` : ''}:
${rows}`;
}

let client: { key: string; instance: Anthropic } | null = null;

async function anthropic(connection: NonNullable<Connections['claude']>): Promise<Anthropic> {
  const id = `${connection.key ?? ''}|${connection.baseURL ?? ''}`;
  if (client?.key === id) return client.instance;
  const { default: Anthropic } = await import('@anthropic-ai/sdk');
  // The key stays in this browser (or on the dev server, which puts its own in).
  const instance = new Anthropic({ apiKey: connection.key ?? 'dev-server', baseURL: connection.baseURL, dangerouslyAllowBrowser: true, maxRetries: 1 });
  client = { key: id, instance };
  return instance;
}

/** A script of Claude's that failed: its answer as written, and why. */
export interface Failed {
  answer: string;
  error: string;
}

/** Which Claude writes a command, and how hard it thinks. */
export interface Writer {
  model: string;
  effort: 'low' | 'medium' | 'high';
}

/** How hard the model for complex commands thinks: they run while other commands are typed, so their time matters less. */
const COMPLEX_EFFORT: Writer['effort'] = 'medium';

/** The fast model at low effort for most commands; for those Jev finds complex, the model for them at more. */
export function writerFor(connection: NonNullable<Connections['claude']>, complex: boolean): Writer {
  return complex ? { model: connection.complexModel, effort: COMPLEX_EFFORT } : { model: connection.model, effort: 'low' };
}

/** A model's short name, as shown: "Opus". */
export function modelName(id: string): string {
  return CLAUDE_MODELS.find((m) => m.id === id)?.short ?? id;
}

/** Claude's script for a command; after a `failed` one, its second try, told why. */
export async function askClaude(
  about: About,
  catalog: Catalog,
  connection: NonNullable<Connections['claude']>,
  writer: Writer,
  signal: AbortSignal,
  failed?: Failed,
): Promise<{ script: Script; ms: number; answer: string }> {
  const started = performance.now();
  const claude = await anthropic(connection);
  const response = await claude.beta.messages.create(
    {
      model: writer.model,
      max_tokens: 16000,
      betas: ['server-side-fallback-2026-07-01'],
      fallbacks: 'default',
      output_config: { effort: writer.effort, format: { type: 'json_schema', schema: SCRIPT_SCHEMA } },
      system: [{ type: 'text', text: systemPrompt(catalog), cache_control: { type: 'ephemeral' } }],
      messages: [
        { role: 'user', content: userMessage(about) },
        ...(failed
          ? [
              { role: 'assistant' as const, content: failed.answer },
              {
                role: 'user' as const,
                content: `Running this script failed: ${failed.error}. If the script is at fault, write it again with only the names, settings and options described; if the command cannot be done on these items, answer with no steps and say why in the summary.`,
              },
            ]
          : []),
      ],
    },
    { signal },
  );
  if (response.stop_reason === 'refusal') throw new Error('Claude declined this command');
  const text = response.content.flatMap((block) => (block.type === 'text' ? [block.text] : [])).join('');
  const written = JSON.parse(text) as { summary: string; knobs: Script['knobs']; steps: Written[] };
  if (!Array.isArray(written.steps) || written.steps.length === 0) throw new Error(`Claude found nothing to do${written.summary ? `: ${written.summary}` : ''}`);
  const script: Script = { summary: written.summary, knobs: written.knobs ?? [], steps: written.steps.map(stepOf) };
  return { script, ms: performance.now() - started, answer: text };
}

/** A key for remembering readings: the same words about the same kinds of items. */
export function readingKey(about: About): string {
  return `${plain(about.text)}|${[...about.counts.keys()].sort((a, b) => a - b).join(',')}|${about.region ? 'r' : ''}`;
}
