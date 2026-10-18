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
import { chainable, MEASURES, TARGETS, scriptFor, type Action, type Intent } from './ai-intent';
import { namedSettings, plain, type Filter, type Region, type Script, type Step } from './ai-script';
import { INTERVALS, RHYTHMS, musicIn, namesCount, namesOption, numberOf, numberWords, rhythmsFor } from './ai-values';

// ---------------------------------------------------------------------------
// Settings and connections

export interface AiSettings {
  /** TypeSafe key, or an AI gateway's key for `jevUrl`; empty: the dev server's. */
  jevKey: string;
  jevUrl: string;
  /** Anthropic key; empty: the dev server's. */
  claudeKey: string;
  claudeModel: string;
}

export const TYPESAFE_URL = 'https://api.typesafe.ai/v1/systemone';
/** Vercel's AI Gateway serves Jev to pages of any site (CORS), with a Vercel key. */
export const GATEWAY_URL = 'https://ai-gateway.vercel.sh/typesafe/v1/systemone';
export const CLAUDE_MODELS = [
  { id: 'claude-sonnet-5-5', label: 'Claude Sonnet 5.5 (fastest)' },
  { id: 'claude-haiku-5-5', label: 'Claude Haiku 5.5' },
  { id: 'claude-opus-5-5', label: 'Claude Opus 5.5' },
];

const SETTINGS_KEY = 'winscore.ai';
const DEFAULTS: AiSettings = { jevKey: '', jevUrl: TYPESAFE_URL, claudeKey: '', claudeModel: 'claude-sonnet-5-5' };

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
  claude: { key: string | null; baseURL: string | undefined; model: string } | null;
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
      ? { key: settings.claudeKey, baseURL: undefined, model: settings.claudeModel }
      : server.claude
        ? { key: null, baseURL: local('ai/anthropic'), model: settings.claudeModel }
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
  /** Some of the items, P1 … Pn each, for Claude. */
  sample: number[][];
  /** Where the barlines are (P3) on the staves of the items, by staff, for Claude: where bars begin. */
  bars: Map<number, number[]>;
  /** Names of item codes. */
  codeName(code: number): string;
}

function selectionWords(about: About): string {
  const parts = [...about.counts].map(([code, n]) => `${n} × ${about.codeName(code)}`);
  return `${parts.join(', ') || 'nothing'}${about.whole ? ' (the whole score)' : ''}`;
}

// ---------------------------------------------------------------------------
// Jev

const ACTIONS: Record<Action | 'other', string> = {
  insert: 'Write new notes, chords or rests into the score, named by their pitches such as c, f#, bb4 or chords such as d/f/a, perhaps with their note value (add c e g as eighths)',
  beam: 'Join notes with beams, or beam them in groups such as pairs',
  unbeam: 'Take the beams away so the notes are no longer beamed',
  delete: 'Remove, delete, erase, clear, take away or hide something: items such as rests, slurs or dynamics, or a part of notes such as their stems, accidentals, articulation marks or dots',
  flip: 'Flip, invert or turn over stems, slurs or symbols to the other side',
  'stems-up': 'Make the stems point up',
  'stems-down': 'Make the stems point down',
  'stems-auto': 'Give the notes their normal stem directions, or give them stems again',
  option:
    'Give the items a named property: add or change an articulation or mark (accent them, add staccatos, a fermata), an accidental (sharpen them, flatten them, make them natural), a note value (make them eighths, half notes), a note head shape, cue size, a clef type or a line style (dashed, dotted)',
  bigger: 'Make them all larger, longer, thicker or wider by the same amount',
  smaller: 'Make them all smaller, shorter, thinner or narrower by the same amount',
  grow: 'Make a size increase gradually across the items, each a little bigger than the one before, or from one value to a larger one (sizes from 1 to 3)',
  shrink: 'Make a size decrease gradually across the items, each a little smaller than the one before, or from one value to a smaller one (sizes from 2 to 1)',
  move: 'Move, shift, raise, lower or transpose the items',
  align: 'Put the items at one height, in a straight row',
  layout:
    'Lay out a system as SCORE’s LJ, LI and J commands do: line up the beats of its staves one above the other, or justify the line, spacing the music left to right',
  number: 'Set a named property to a number the command gives, such as size 1.5 or stem length 3',
  command: 'A command in the SCORE program’s own language, short upper-case words and numbers such as FLI or R 5',
  other: 'Something else',
};

// Jev leans to the first option: LJ goes first, the command for laying out.
const LAYOUT = {
  LJ: 'line up and justify (LJ): lay out, space, respace or justify the music',
  LI: 'only line up (LI): the beats of the staves aligned by the notes’ durations, without justifying',
  J: 'only justify (J): room made for accidentals, dots and flags, without lining up the beats again',
  LJA: 'line up and justify all the staves of the page at once, as one single system (LJA)',
};

const DIRECTIONS = { none: 'no direction is given', up: 'up, higher, raise', down: 'down, lower', left: 'left, earlier, backwards', right: 'right, later, forwards' };

const WHICH = {
  all: 'all of them, or all of one kind or with one property, such as all the stems or all the staccatos',
  some: 'only some, picked out by their place or order, such as the first, the last, every other one, the top notes or the second bar',
};

/** Below this, a reading goes to Claude instead. */
const SURE = 0.5;
/** Answers that only narrow a reading (a note value for new notes, a property for removing) need more. */
const QUITE_SURE = 0.75;

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
    which: { type: 'choice', instructions: 'Does the `command` act on all the selected items it names, or only on some of them it picks out?', criteria: WHICH },
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
    layout: { type: 'choice', instructions: 'Which of SCORE’s layout commands does the `command` ask for?', criteria: LAYOUT },
    then: {
      type: 'choice',
      instructions: 'Besides its main action, does the `command` ask for a second, different thing? Which?',
      criteria: { none: 'only one thing is asked', ...Object.fromEntries(Object.entries(ACTIONS).filter(([id]) => id !== 'other')) },
    },
  };
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
export type Unread = 'unsure' | 'other' | 'some' | 'nothing' | 'detail';

export const UNREAD: Record<Unread, string> = {
  unsure: 'Jev is not sure what this asks',
  other: 'This is not one of Jev’s actions',
  some: 'This picks out some of the items',
  nothing: 'There is nothing selected for this',
  detail: 'Jev misses a detail of this',
};

/** Jev's reading: the intent, or why there is none; the action's probability either way. */
export interface JevReading {
  intent: Intent | null;
  why: Unread | null;
  action: string;
  confidence: number;
  ms: number;
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
  if (!action || action === 'other') return 'other';
  // Some items picked out by place ("the last note", "every other one"): Claude writes that.
  if (choice('which') === 'some' && answers.which!.confidence >= SURE) return 'some';
  // Everything but new music acts on items: with none, the reading is wrong.
  if (action !== 'insert' && about.counts.size === 0) return 'nothing';
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
  switch (action) {
    case 'insert': {
      const music = musicIn(about.text, about.middle);
      if (!music) return 'detail';
      intent.notes = music.notes;
      intent.typed = music.typed;
      const rhythm = answers.rhythm && answers.rhythm.confidence >= QUITE_SURE ? choice('rhythm') : undefined;
      intent.rhythms = rhythmsFor(rhythm, music.count);
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
    case 'delete':
      // "the eighth notes": only those. Half sure of a property is not enough to delete
      // all of them instead, nor only some: Claude decides.
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
    case 'layout': {
      const layout = answers.layout;
      return { ...intent, line: layout && layout.confidence >= QUITE_SURE ? layout.choice : 'LJ' };
    }
    default:
      return intent;
  }
}

async function systemOne(connection: NonNullable<Connections['jev']>, body: unknown, signal: AbortSignal): Promise<Record<string, ChoiceAnswer>> {
  const headers: Record<string, string> = { 'content-type': 'application/json' };
  if (connection.key) headers.authorization = `Bearer ${connection.key}`;
  let response: Response;
  try {
    response = await fetch(connection.url, { method: 'POST', headers, body: JSON.stringify(body), signal });
  } catch (err) {
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
  const read = action && action.confidence >= SURE ? readAnswers(about, answers) : 'unsure';
  const [intent, why] = typeof read === 'string' ? [null, read] : [read, null];
  return { intent, why, action: action?.choice ?? 'other', confidence: action?.confidence ?? 0, ms: performance.now() - started };
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

/** Jev's reading as an edit script, if it has one. */
export function jevScript(reading: JevReading): Script | null {
  return reading.intent ? scriptFor(reading.intent) : null;
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
A score is a list of items, each a row of numbers P1 … Pn. P1 is the item's code (what it is), P2 its staff number (staff 1 is the lowest on the page), P3 its horizontal position on the staff (0 at the left edge, 200 at the right), P4 its vertical level in scale steps (half the distance between staff lines; on a treble staff level 1 is middle C, level 3 the bottom line, level 11 the top line). The other parameters depend on the code; the settings below name them.

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
  - "layout": SCORE's layout command in "line" on each system the items are on (the staves its barlines join): "LJ" lines up the beats of the system's staves by the notes' durations and justifies the line (what laying out, spacing or justifying the music means), "LI" only lines up, "J" only justifies (makes room for accidentals, dots and flags); "LJA" does LJ on all staves of the page at once, as one system. LJ and LI need the staves of a system to last equally long.
  - "select": the items it picks become the selection, and the steps after it act on them only; nothing is edited. A command to select, keep only or pick out items is this, never a delete.
  - "add": for each item it picks, a new item whose P1, P2, P3 … are "params" (numbers or expressions over the item it is made for; the settings below give each code's parameter numbers); an item whose P1 comes to 0 is not made. Lines (code 4) and slurs (code 5) run from P3, P4 to P6, P5.
- Which items a step acts on: "codes" (empty for all), "where" (an expression that must hold, or ""), and "where_setting" with "where_is" (only the items whose setting reads that option, e.g. "Mark" and "Staccato", or "" and "").
- "value", "right", "up", "size": text holding a number, an expression or an option's name.

Values may be expressions: numbers, + - * / % ^, comparisons, && || !, a ? b : c, functions min max abs round floor ceil sqrt pow lerp(a,b,t) clamp(x,lo,hi) snap(x,step), and these names for each item: p1 … p45 (its parameters), staff, x (P3), level (P4 without the cue-size hundred), value (the setting's current value; 0 often means the default, e.g. size 0 is size 1), mean (the mean of that parameter over the items, in set steps), t (0 for the first column of items from left to right, 1 for the last; the notes of a chord share one), i and n (that column's number from 0, and how many there are), st, si, sn (the same on the item's own staff), next_x and next_level (the position of the next note or chord on its staff, and its level nearest this item's; the item's own for the last), bar, bi, bn, bt (its bar on its staff from 0, by the barlines, and the same as i, n, t within that bar: "bi == 0" is the first note or chord of each bar, "bi == bn - 1" the last), left and right (the leftmost and rightmost P3 of the items on its staff), count, chord_low and chord_high (the lowest and highest level among the notes of its chord, its notes at the same place on its staff, a lone note being its own chord: "level == chord_low" is the bottom note of each chord), chord_size (how many notes that chord has), min_p1 … min_p45, max_p1 … max_p45 and mean_p1 … mean_p45 (a parameter's smallest, largest and mean value over the items; min_level, max_level and mean_level the same for level, so "level == max_level" is the single highest note), and the knobs by id. There are no functions over the items: max(p4) is just p4.

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
"justify this system" → {"summary": "Line up and justify", "knobs": [], "steps": [{"do": "layout", "line": "LJ"}]}
"add c e g" → {"summary": "Add C E G", "knobs": [], "steps": [{"do": "insert", "staff": 0, "from": 0, "to": 0, "notes": "PC5/E/G", "rhythms": "4/4/4"}]}`;
}

/** One step as Claude writes it: every field there, none of them a union (the API allows few). */
interface Written {
  do: Step['do'];
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
        required: ['do', 'codes', 'where', 'where_setting', 'where_is', 'setting', 'param', 'value', 'right', 'up', 'line', 'staff', 'from', 'to', 'notes', 'rhythms', 'marks', 'beams', 'slurs', 'size', 'params'],
        properties: {
          do: { type: 'string', enum: ['setting', 'set', 'move', 'delete', 'command', 'layout', 'insert', 'beam', 'select', 'add'] },
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
    case 'layout':
      return { do: 'layout', items, line: w.line };
    case 'insert':
      return { do: 'insert', staff: w.staff || null, from: w.from || null, to: w.to || null, notes: w.notes, rhythms: w.rhythms, marks: w.marks, beams: w.beams, slurs: w.slurs };
    case 'beam':
      return { do: 'beam', items, size: text(w.size) || 0 };
    case 'select':
      return { do: 'select', items };
    case 'add':
      return { do: 'add', items, params: w.params ?? [] };
  }
}

function userMessage(about: About): string {
  const region = about.region ? `staff ${about.region.staff}${about.region.top !== about.region.staff ? `–${about.region.top}` : ''}, P3 ${Math.round(about.region.from)} to ${Math.round(about.region.to)}` : 'nowhere';
  const rows = about.sample.map((params) => params.map((v) => +v.toFixed(3)).join(' ')).join('\n');
  return `Command: ${about.text}
Selected: ${selectionWords(about)}
New music goes: ${region}
Barlines (P3) on these staves: ${[...about.bars].map(([staff, xs]) => `staff ${staff}: ${xs.map((x) => +x.toFixed(2)).join(', ') || 'none'}`).join('; ') || 'none'}
Items (P1 … Pn)${about.sample.length < [...about.counts.values()].reduce((a, b) => a + b, 0) ? ', the first of them' : ''}:
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

/** Claude's script for a command; after a `failed` one, its second try, told why. */
export async function askClaude(
  about: About,
  catalog: Catalog,
  connection: NonNullable<Connections['claude']>,
  signal: AbortSignal,
  failed?: Failed,
): Promise<{ script: Script; ms: number; answer: string }> {
  const started = performance.now();
  const claude = await anthropic(connection);
  const response = await claude.beta.messages.create(
    {
      model: connection.model,
      max_tokens: 4096,
      betas: ['server-side-fallback-2026-07-01'],
      fallbacks: 'default',
      output_config: { effort: 'low', format: { type: 'json_schema', schema: SCRIPT_SCHEMA } },
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
