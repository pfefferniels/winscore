// The Model Context Protocol (MCP) server of the desktop app: what an AI
// assistant such as Claude Code may read and change of the score open in
// the window. The app (desktop/src-tauri/src/mcp.rs) takes JSON-RPC messages
// on http://127.0.0.1:7341/mcp (or through `--mcp-stdio`) and hands them to
// this page, which answers them here with the editor itself: every change is
// one undo step, and the window shows it at once.
//
// Items are named by `id`, score-web's identity of an item, which stays with
// it through edits, sorting and undo. Their settings are the side panel's
// (item-fields.ts), read and written by name, so packed parameters (a note's
// accidental and stem in P5, its tails and dots in P9) are written as the
// panel writes them.
import type { Editor } from './editor';
import { pitchLevel, sameValue, sectionsFor, VALUES, type Change as ParamChange, type Context, type P, type Setting } from './item-fields';
import { withFont } from './text-dialog';
import { noteParams, restParams, type Facts, type NoteSpec } from './tools';
import { creationWords, editWords, groupCommand, type Score } from './wasm/score_web.js';

/** What the server needs of the app. */
export interface McpHost {
  score(): Score | null;
  editor(): Editor | null;
  file(): { name: string; path: string | null; modified: boolean };
  /** Whether the person at the window is in the middle of a gesture (a drag), which an edit must not cut into. */
  busy(): boolean;
  /** Runs `action` as one undo step `label`, then shows the score; undone if it throws. The step's name, or null if nothing changed. */
  batch(label: string, action: (editor: Editor, score: Score) => void): string | null;
  /** Selects items by file index in the window, scrolled into view. */
  select(indices: number[]): void;
  undo(): string | null;
  redo(): string | null;
  facts: Facts;
  /** What the panel's settings of item `index` read from the rest of the score (the clef in force at a note). */
  context(index: number): Context;
  nameOf(code: number): string;
  /** The help's labels of P1 … Pn of an item code. */
  paramNames(code: number): (string | null)[];
  /** The staves with their lines' heights on the page (engine units, y up). */
  staves(): { number: number; lines: number; bottom: number; top: number }[];
  paper(): { width: number; height: number };
  /** The page (or the staves `staves` of it) as a PNG at `zoom` percent (100: 96 dpi), base64. */
  render(zoom: number, staves: [number, number] | null, selection: boolean): Promise<{ data: string; width: number; height: number }>;
  open(path: string): Promise<void>;
  newScore(): void;
  /** Saves to `path`, else to the score's file; the path written. */
  save(path: string | null): Promise<string>;
  exportSvg(path: string): Promise<void>;
  /** Shows in the status line what an assistant did. */
  notify(text: string): void;
}

interface JsonRpc {
  jsonrpc?: string;
  id?: string | number | null;
  method?: string;
  params?: Record<string, unknown>;
}

type Args = Record<string, unknown>;

interface ToolResult {
  content: ({ type: 'text'; text: string } | { type: 'image'; data: string; mimeType: string })[];
  isError?: boolean;
}

interface Tool {
  name: string;
  title: string;
  description: string;
  inputSchema: Record<string, unknown>;
  annotations?: Record<string, boolean>;
  run(args: Args): ToolResult | Promise<ToolResult>;
}

const PROTOCOL_VERSIONS = ['2025-11-25', '2025-06-18', '2025-03-26', '2024-11-05'];
const SERVER = { name: 'winscore', title: 'WinScore', version: '0.1.0' };

const INSTRUCTIONS = `WinScore edits the score open in its window: a file of Leland Smith's music engraving program SCORE (.mus). Changes appear in the window at once, and each tool call that changes the score is one undo step there.

How SCORE places things: staves are numbered from the bottom of the page up (staff 1 lowest). On a staff, P3 is the horizontal position, 0 at its left end to 200 at its right end; P4 is the vertical position in scale steps from the staff's reference level, whatever the clef: on a five-line staff 3 is the bottom line, 7 the middle line, 11 the top line, 1 the first ledger line below. Every item is a list of numbers P1 … Pn: P1 its code (1 note, 2 rest, 3 clef, 4 line or hairpin, 5 slur, tie or ending, 6 beam, 7 trill, ottava or pedal line, 8 staff, 9 symbol, 10 number, 12 box or circle, 14 barline, 16 text, 17 key signature, 18 meter), P2 its staff, P3 and P4 its place. Notes of a chord share a P3. SCORE draws what the numbers say: it does not respace music or add accidentals by itself.

Items are named by "id", which stays with an item through edits and undo. Start with get_document and render_page (an image of the page) to see the score; list_items and get_items read items, with their settings: the side panel's named values (Pitch "F#4", Value "Eighth", Stem "Up" …). set_settings changes items by those names; set_parameters by raw P numbers. add_notes writes notes and rests by pitch name and duration; insert_items makes any item from a SCORE creation word (list_words) or raw parameters; insert_text adds text. run_command runs SCORE's edit commands on items (list_commands), and group and layout commands such as LJ (line up and justify a system), answering their questions. describe_kind explains the parameters of an item code.`;

const NO_SCORE = 'No score is open: open_file opens one, new_score starts an empty one.';

// ---------------------------------------------------------------------------
// Reading items

/** Parameters without the zeros at the end, P1 … P4 at least. */
function trimmed(params: number[]): number[] {
  const list = params.map((v) => Math.round(v * 10000) / 10000);
  while (list.length > 4 && list.at(-1) === 0) list.pop();
  return list;
}

function readSetting(s: Setting, p: P, ctx: Context): unknown {
  switch (s.kind) {
    case 'number':
      return Math.round(s.get(p) * 10000) / 10000;
    case 'choice': {
      const v = s.get(p);
      return s.options.find((o) => sameValue(o.value, v))?.label ?? s.other?.(p) ?? v;
    }
    case 'toggle':
      return s.get(p);
    case 'text':
      return s.show(p, ctx);
    case 'pair':
      return [s.fields[0].get(p), s.fields[1].get(p)];
  }
}

/** The settings of an item that apply to it, by their names (the panel's labels; a repeated one with its section's title). */
function settingsOf(code: number, p: P): Map<string, Setting> {
  const named = new Map<string, Setting>();
  for (const section of sectionsFor(code)) {
    for (const setting of section.settings) {
      if (setting.when && !setting.when(p)) continue;
      const name = named.has(setting.label) ? `${section.title} ${setting.label}` : setting.label;
      named.set(name, setting);
    }
  }
  return named;
}

const plain = (text: string) => text.toLowerCase().replace(/[^a-z0-9♭♯♮#]+/g, ' ').trim();

/** The changes that give setting `s` the value `value`, as the panel would make them. */
function writeSetting(name: string, s: Setting, value: unknown, p: P, ctx: Context): ParamChange[] {
  const fail = (wanted: string): never => {
    throw new Error(`${name}: ${JSON.stringify(value)} is not ${wanted}`);
  };
  switch (s.kind) {
    case 'number': {
      const n = Number(value);
      return Number.isFinite(n) ? s.set(n, p) : fail('a number');
    }
    case 'choice': {
      const found =
        typeof value === 'number'
          ? s.options.find((o) => sameValue(o.value, value))
          : (s.options.find((o) => plain(o.label) === plain(String(value))) ?? s.options.find((o) => plain(o.label).startsWith(plain(String(value)))));
      return found ? s.set(found.value, p) : fail(`one of ${s.options.map((o) => `"${o.label}"`).join(', ')}`);
    }
    case 'toggle': {
      const on = value === true || value === 'true' || value === 'on' || value === 1;
      const off = value === false || value === 'false' || value === 'off' || value === 0;
      return on || off ? s.set(on, p) : fail('true or false');
    }
    case 'text':
      return s.parse(String(value), p, ctx) ?? fail(`readable (e.g. ${s.placeholder ?? 'a value'})`);
    case 'pair': {
      const pair = Array.isArray(value) ? value.map(Number) : [];
      return pair.length === 2 && pair.every(Number.isFinite) ? [...s.fields[0].set(pair[0]!, p), ...s.fields[1].set(pair[1]!, p)] : fail('two numbers');
    }
  }
}

/** One line of what an item is, for lists: "F#4 Quarter", the text of a text. */
function summary(code: number, settings: Record<string, unknown>, text: string | null): string {
  const pick = (...names: string[]) => names.map((n) => settings[n]).filter((v) => v !== undefined && v !== '').join(' ');
  if (text !== null) return text;
  const kinds: Record<number, () => string> = {
      1: () => pick('Pitch', 'Value'),
      2: () => pick('Rest'),
      3: () => pick('Clef'),
      14: () => pick('Type'),
      17: () => pick('Key'),
      18: () => pick('Meter', 'Shows'),
  };
  return kinds[code]?.() ?? '';
}

// ---------------------------------------------------------------------------
// Arguments

function text(value: unknown, name: string): string {
  if (typeof value !== 'string' || value === '') throw new Error(`${name} must be a non-empty string`);
  return value;
}

function num(value: unknown, name: string): number {
  const n = typeof value === 'string' ? Number(value) : value;
  if (typeof n !== 'number' || !Number.isFinite(n)) throw new Error(`${name} must be a number`);
  return n;
}

function optionalNum(value: unknown, name: string): number | undefined {
  return value === undefined || value === null ? undefined : num(value, name);
}

function list(value: unknown, name: string): unknown[] {
  if (!Array.isArray(value)) throw new Error(`${name} must be an array`);
  return value;
}

/** Note values by name or as the denominator of their fraction (4 a quarter), as indices of VALUES. */
function valueIndex(value: unknown): number {
  if (value === undefined || value === null) return VALUES.findIndex((v) => v.quarters === 1);
  const words: Record<string, number> = { breve: 8, whole: 4, half: 2, quarter: 1, crotchet: 1, minim: 2, semibreve: 4, quaver: 0.5, semiquaver: 0.25, eighth: 0.5, '8th': 0.5, sixteenth: 0.25, '16th': 0.25, '32nd': 0.125, thirtysecond: 0.125, '64th': 0.0625, '128th': 0.03125 };
  const fraction = typeof value === 'number' ? 4 / value : (words[plain(String(value)).replace(/ note$/, '')] ?? 4 / Number(value));
  const index = VALUES.findIndex((v) => sameValue(v.quarters, fraction));
  if (index < 0) throw new Error(`duration ${JSON.stringify(value)}: give whole, half, quarter, eighth, 16th, 32nd, 64th or breve (or 1, 2, 4, 8, 16, 32, 64)`);
  return index;
}

const ACCIDENTALS: Record<string, number> = { none: 0, flat: 1, sharp: 2, natural: 3, 'double flat': 4, 'double sharp': 5 };

const json = (value: unknown): ToolResult => ({ content: [{ type: 'text', text: JSON.stringify(value, null, 1) }] });

// ---------------------------------------------------------------------------
// The server

export function createMcpServer(host: McpHost) {
  /** The client's name from its `initialize`, shown with what it did. */
  let client = 'MCP client';

  const need = (): { score: Score; editor: Editor } => {
    const score = host.score();
    const editor = host.editor();
    if (!score || !editor) throw new Error(NO_SCORE);
    return { score, editor };
  };

  const keys = (score: Score): number[] => Array.from(score.keys());

  /** File indices of items by id; an unknown id is an error. */
  const indicesOf = (score: Score, ids: unknown, name = 'ids'): number[] => {
    const at = new Map(keys(score).map((key, index) => [key, index]));
    return list(ids, name).map((id) => {
      const index = at.get(Number(id));
      if (index === undefined) throw new Error(`No item has the id ${JSON.stringify(id)}: list_items gives the ids`);
      return index;
    });
  };

  /** Item `index` as the tools show it, `ids` being every item's id in file order. */
  const read = (score: Score, ids: number[], index: number, full: boolean) => {
    const info = score.item(index);
    if (!info) return null;
    const params = Array.from(info.params);
    const code = info.code;
    const characters = info.text ?? null;
    info.free();
    const p: P = (n) => params[n - 1] ?? 0;
    const ctx = host.context(index);
    const settings: Record<string, unknown> = {};
    for (const [name, setting] of settingsOf(code, p)) {
      if (name === 'Staff' || name === 'Position') continue;
      settings[name] = readSetting(setting, p, ctx);
    }
    const base = { id: ids[index]!, code, kind: host.nameOf(code), staff: p(2), p3: Math.round(p(3) * 100) / 100, p4: p(4) };
    if (!full) return { ...base, summary: summary(code, settings, characters) };
    const names = host.paramNames(code);
    const shown = trimmed(params);
    return {
      ...base,
      params: shown,
      paramNames: Object.fromEntries(shown.map((_, i) => [`P${i + 1}`, names[i] ?? null])),
      settings,
      ...(characters !== null ? { text: characters } : {}),
    };
  };

  /** Runs an edit as one undo step, tells the window who made it, and returns what it did. */
  const change = (label: string, action: (editor: Editor, score: Score) => void, extra: Record<string, unknown> = {}): ToolResult => {
    need();
    if (host.busy()) throw new Error('The score is being edited in the window right now (a drag is in progress); try again in a moment.');
    const messages: string[] = [];
    const step = host.batch(label, (editor, score) =>
      action(
        new Proxy(editor, {
          get(target, prop, receiver) {
            const value = Reflect.get(target, prop, receiver);
            if (typeof value !== 'function') return value;
            return (...args: unknown[]) => {
              const result = value.apply(target, args);
              const message = (result as { message?: string | null } | null)?.message;
              if (message) messages.push(message);
              return result;
            };
          },
        }),
        score,
      ),
    );
    if (step) host.notify(`${client}: ${step}`);
    const score = host.score()!;
    const ids = keys(score);
    const selected = Array.from(score.selection(), (i) => ids[i]);
    return json({ done: step ?? 'nothing changed', ...(messages.length ? { engine: messages } : {}), ...extra, selection: selected });
  };

  /** The items `action` adds, by their ids. */
  const added = (score: Score, before: Set<number>) => keys(score).filter((key) => !before.has(key));

  const tools: Tool[] = [
    {
      name: 'get_document',
      title: 'The open score',
      description: 'The score open in the window: its file, whether it has unsaved changes, the paper, its staves (bottom to top, with their clefs) and how many items each has, the selection and the undo history.',
      inputSchema: { type: 'object', properties: {} },
      annotations: { readOnlyHint: true },
      run() {
        const file = host.file();
        const score = host.score();
        if (!score) return json({ open: false, hint: NO_SCORE });
        const counts = new Map<number, number>();
        const numbers = score.itemSummaries();
        for (let i = 0; i < numbers.length; i += 3) counts.set(numbers[i + 1]!, (counts.get(numbers[i + 1]!) ?? 0) + 1);
        const paper = host.paper();
        const ids = keys(score);
        return json({
          file: file.name,
          path: file.path,
          unsavedChanges: file.modified,
          paperInches: [paper.width / 4000, paper.height / 4000],
          items: score.itemCount(),
          staves: host.staves().map((s) => {
            // The clef at the start of the line stands at P3 2 or so.
            const clef = host.facts.clefAt(s.number, 6);
            const type = Math.trunc(Math.abs(clef?.p5 ?? 0));
            return { staff: s.number, lines: s.lines, clefAtStart: ['treble', 'bass', 'alto', 'tenor', 'percussion'][type] ?? `type ${clef?.p5}`, items: counts.get(s.number) ?? 0 };
          }),
          selection: Array.from(score.selection(), (i) => ids[i]),
          undo: score.undoLabel() ?? null,
          redo: score.redoLabel() ?? null,
        });
      },
    },
    {
      name: 'list_items',
      title: 'List items',
      description: 'Items of the score in file order, each with its id, code, kind, staff, P3 (position), P4 (level) and a summary (a note\'s pitch and value, a text\'s characters). Filter by staff, code and a P3 range; page with offset and limit.',
      inputSchema: {
        type: 'object',
        properties: {
          staff: { type: 'number', description: 'Only items on this staff' },
          code: { type: 'number', description: 'Only items of this code (1 notes, 2 rests, 16 texts …)' },
          from: { type: 'number', description: 'Only items at P3 from this' },
          to: { type: 'number', description: 'Only items at P3 up to this' },
          offset: { type: 'number', description: 'Skip this many matches (default 0)' },
          limit: { type: 'number', description: 'At most this many (default 300)' },
        },
      },
      annotations: { readOnlyHint: true },
      run(args) {
        const { score } = need();
        const staff = optionalNum(args.staff, 'staff');
        const code = optionalNum(args.code, 'code');
        const from = optionalNum(args.from, 'from') ?? -Infinity;
        const to = optionalNum(args.to, 'to') ?? Infinity;
        const offset = optionalNum(args.offset, 'offset') ?? 0;
        const limit = optionalNum(args.limit, 'limit') ?? 300;
        const numbers = score.itemSummaries();
        const matches: number[] = [];
        for (let i = 0; i < numbers.length / 3; i++) {
          const [c, s, p3] = [numbers[3 * i]!, numbers[3 * i + 1]!, numbers[3 * i + 2]!];
          if ((code === undefined || c === code) && (staff === undefined || s === staff) && p3 >= from && p3 <= to) matches.push(i);
        }
        const ids = keys(score);
        const shown = matches.slice(offset, offset + limit).map((i) => read(score, ids, i, false));
        return json({ total: matches.length, offset, items: shown });
      },
    },
    {
      name: 'get_items',
      title: 'Read items',
      description: 'Everything about items by id: all parameters P1 … Pn with what the SCORE help calls each, the side panel\'s settings by name with their values (Pitch, Value, Stem, Accidental, Type …), and a text\'s characters.',
      inputSchema: { type: 'object', properties: { ids: { type: 'array', items: { type: 'number' } } }, required: ['ids'] },
      annotations: { readOnlyHint: true },
      run(args) {
        const { score } = need();
        const ids = keys(score);
        return json(indicesOf(score, args.ids).map((i) => read(score, ids, i, true)));
      },
    },
    {
      name: 'render_page',
      title: 'Look at the page',
      description: 'An image of the page as the window draws it (with staff numbers at the left), or of some staves of it. zoom 100 is 96 dots per inch; use a higher zoom with staves to read details.',
      inputSchema: {
        type: 'object',
        properties: {
          staves: { type: 'array', items: { type: 'number' }, minItems: 2, maxItems: 2, description: 'Only from the lower to the higher of these staff numbers, e.g. [3, 4]' },
          zoom: { type: 'number', description: 'Percent, default 100 (the whole page) or 200 (some staves)' },
          show_selection: { type: 'boolean', description: 'Draw the selected items in blue' },
        },
      },
      annotations: { readOnlyHint: true },
      async run(args) {
        need();
        const staves = args.staves === undefined ? null : (list(args.staves, 'staves').map((v) => num(v, 'staves')) as [number, number]);
        const zoom = Math.min(400, Math.max(25, optionalNum(args.zoom, 'zoom') ?? (staves ? 200 : 100)));
        const image = await host.render(zoom, staves, args.show_selection === true);
        return {
          content: [
            { type: 'image', data: image.data, mimeType: 'image/png' },
            { type: 'text', text: `${image.width} × ${image.height} px at ${zoom} %` },
          ],
        };
      },
    },
    {
      name: 'select',
      title: 'Select items',
      description: 'Selects items by id in the window, so the person at it sees them (and the side panel shows them); an empty list selects nothing.',
      inputSchema: { type: 'object', properties: { ids: { type: 'array', items: { type: 'number' } } }, required: ['ids'] },
      run(args) {
        const { score } = need();
        host.select(indicesOf(score, args.ids));
        return json({ selected: list(args.ids, 'ids').length });
      },
    },
    {
      name: 'set_settings',
      title: 'Change settings',
      description: 'Sets the side panel\'s settings of items by name, as the panel does, so packed parameters stay right: e.g. {"Pitch": "Bb4"}, {"Value": "Eighth", "Dots": "1"}, {"Stem": "Down"}, {"Accidental": "♯ Sharp"}, {"Type": "Double"}, {"Size": 1.5}. get_items shows the names and values an item has; describe_kind lists the choices. All of it is one undo step.',
      inputSchema: {
        type: 'object',
        properties: {
          ids: { type: 'array', items: { type: 'number' }, description: 'The items to change' },
          settings: { type: 'object', description: 'Setting name → value (a choice by its label, a number, true/false, or text such as a pitch)', additionalProperties: true },
        },
        required: ['ids', 'settings'],
      },
      run(args) {
        const { score } = need();
        const indices = indicesOf(score, args.ids);
        const wanted = Object.entries((args.settings ?? {}) as Record<string, unknown>);
        if (wanted.length === 0) throw new Error('settings is empty');
        const edits: [number, [number, number][]][] = indices.map((index) => {
          const info = score.item(index)!;
          const params = Array.from(info.params);
          const code = info.code;
          info.free();
          const p: P = (n) => params[n - 1] ?? 0;
          const named = settingsOf(code, p);
          const changed = new Map<number, number>();
          for (const [name, value] of wanted) {
            const key = [...named.keys()].find((k) => plain(k) === plain(name));
            if (!key) throw new Error(`A ${host.nameOf(code)} has no setting "${name}" (it has ${[...named.keys()].join(', ')})`);
            for (const [n, v] of writeSetting(key, named.get(key)!, value, (m) => changed.get(m) ?? p(m), host.context(index))) changed.set(n, v);
          }
          return [index, [...changed]];
        });
        return change(`Set ${wanted.map(([n]) => n).join(', ')}`, (editor) => {
          editor.setParamsOf(edits);
          editor.select(indices);
        });
      },
    },
    {
      name: 'set_parameters',
      title: 'Set parameters',
      description: 'Sets raw parameters of items: [{"id": 12, "params": {"5": 20, "8": 4}}] sets P5 and P8 of item 12. Prefer set_settings where a setting says what is meant. One undo step.',
      inputSchema: {
        type: 'object',
        properties: {
          changes: {
            type: 'array',
            items: { type: 'object', properties: { id: { type: 'number' }, params: { type: 'object', description: 'Parameter number → value', additionalProperties: { type: 'number' } } }, required: ['id', 'params'] },
          },
        },
        required: ['changes'],
      },
      run(args) {
        const { score } = need();
        const edits: [number, [number, number][]][] = list(args.changes, 'changes').map((entry) => {
          const { id, params } = entry as { id: unknown; params: Record<string, unknown> };
          const [index] = indicesOf(score, [id]);
          const set = Object.entries(params ?? {}).map(([n, v]): [number, number] => {
            const k = Number(String(n).replace(/^p/i, ''));
            if (!Number.isInteger(k) || k < 2 || k > 45) throw new Error(`P${n}: parameters 2 to 45 can be set`);
            return [k, num(v, `P${k}`)];
          });
          return [index!, set];
        });
        return change('Set parameters', (editor) => {
          editor.setParamsOf(edits);
          editor.select(edits.map(([index]) => index));
        });
      },
    },
    {
      name: 'add_notes',
      title: 'Add notes',
      description: 'Writes notes and rests on a staff by pitch name, each at its position (P3): pitch with octave ("C4" is middle C; "F#4", "Bb3"; read in the clef in force there) or "rest", duration (whole, half, quarter, eighth, 16th, 32nd, 64th, breve; default quarter), dots. Notes at the same position make a chord. The accidental drawn is the one in the pitch name unless accidental says otherwise (none, flat, sharp, natural, double flat, double sharp); SCORE does not add accidentals from the key signature. Stems point up below the middle line and down from it unless stem says up or down. One undo step; returns the new ids.',
      inputSchema: {
        type: 'object',
        properties: {
          staff: { type: 'number' },
          notes: {
            type: 'array',
            items: {
              type: 'object',
              properties: {
                position: { type: 'number', description: 'P3, 0 to 200 along the staff' },
                pitch: { type: 'string', description: '"C4", "F#5", "Bb3", or "rest"' },
                duration: { type: ['string', 'number'] },
                dots: { type: 'number' },
                accidental: { type: 'string', enum: ['none', 'flat', 'sharp', 'natural', 'double flat', 'double sharp'] },
                stem: { type: 'string', enum: ['auto', 'up', 'down'] },
                size: { type: 'string', enum: ['normal', 'cue', 'grace'] },
              },
              required: ['position', 'pitch'],
            },
          },
        },
        required: ['staff', 'notes'],
      },
      run(args) {
        const { score } = need();
        const staff = num(args.staff, 'staff');
        if (!host.staves().some((s) => s.number === staff)) throw new Error(`There is no staff ${staff}: get_document lists the staves (insert_items with the word STAFF makes one)`);
        const notes = list(args.notes, 'notes').map((entry, i) => {
          const note = entry as Args;
          const position = num(note.position, `notes[${i}].position`);
          const value = valueIndex(note.duration);
          const dots = optionalNum(note.dots, `notes[${i}].dots`) ?? 0;
          if (![0, 1, 2, 3].includes(dots)) throw new Error(`notes[${i}].dots must be 0 to 3`);
          const pitch = text(note.pitch, `notes[${i}].pitch`);
          const place = { staff, p3: position, p4: 0 };
          if (/^(r|rest)$/i.test(pitch.trim())) return restParams(host.facts, place, value, dots);
          const read = pitchLevel(pitch, host.facts.clefAt(staff, position));
          if (!read) throw new Error(`notes[${i}].pitch "${pitch}": give a letter, an accidental if any and the octave, e.g. "C4", "F#5", "Bb3"`);
          const accidental = note.accidental === undefined ? read.accidental : ACCIDENTALS[String(note.accidental)];
          if (accidental === undefined) throw new Error(`notes[${i}].accidental: ${Object.keys(ACCIDENTALS).join(', ')}`);
          const spec: NoteSpec = { value, dots, accidental, stem: (note.stem as NoteSpec['stem']) ?? 'auto', size: (note.size as NoteSpec['size']) ?? 'normal' };
          return noteParams(host.facts, { ...place, p4: read.level }, spec);
        });
        const before = new Set(keys(score));
        let ids: number[] = [];
        return change(
          `Add ${notes.length} note${notes.length === 1 ? '' : 's'}`,
          (editor, s) => {
            for (const params of notes) if (params) editor.insertItem(params, 'Note');
            ids = added(s, before);
            const at = new Map(keys(s).map((key, index) => [key, index]));
            editor.select(ids.map((id) => at.get(id)!));
          },
          {
            get ids() {
              return ids;
            },
          },
        );
      },
    },
    {
      name: 'insert_items',
      title: 'Insert items',
      description: 'Makes items: each from a SCORE creation word (list_words: "TREB", "BASS", "SLUR", "TIE", "BEAM", "CRH" crescendo hairpin, "DCH", "OVA", "MF", "FER", "STAC", "KSIG-3", "METER34", "BAR", "BARD", "NUMB", "BOX", "STAFF" …) with SCORE\'s defaults, placed on staff at position (P3) and level (P4, if given), any parameter then set by number ({"6": 140} sets P6, a slur\'s or line\'s right end); or from raw parameters [P1, P2, …]. One undo step; returns the new ids.',
      inputSchema: {
        type: 'object',
        properties: {
          items: {
            type: 'array',
            items: {
              type: 'object',
              properties: {
                word: { type: 'string', description: 'A SCORE creation word' },
                params: { type: 'array', items: { type: 'number' }, description: 'P1, P2, … instead of a word' },
                staff: { type: 'number', description: 'P2 (the new staff\'s number, for STAFF)' },
                position: { type: 'number', description: 'P3' },
                level: { type: 'number', description: 'P4' },
                set: { type: 'object', description: 'Parameter number → value', additionalProperties: { type: 'number' } },
              },
            },
          },
        },
        required: ['items'],
      },
      run(args) {
        const { score } = need();
        const made = list(args.items, 'items').map((entry, i) => {
          const item = entry as Args;
          let params: number[];
          if (item.params !== undefined) {
            params = list(item.params, `items[${i}].params`).map((v) => num(v, `items[${i}].params`));
            if (params.length < 4) throw new Error(`items[${i}].params needs P1 to P4 at least`);
          } else {
            const word = text(item.word, `items[${i}].word`).toUpperCase();
            const base = host.facts.creation(word);
            if (!base) throw new Error(`items[${i}]: "${word}" is not a SCORE creation word (list_words lists them)`);
            params = [...base];
            while (params.length < 4) params.push(0);
            params[1] = num(item.staff, `items[${i}].staff`);
            if (item.position !== undefined) params[2] = num(item.position, `items[${i}].position`);
            if (item.level !== undefined) params[3] = num(item.level, `items[${i}].level`);
          }
          for (const [n, v] of Object.entries((item.set ?? {}) as Record<string, unknown>)) {
            const k = Number(String(n).replace(/^p/i, ''));
            if (!Number.isInteger(k) || k < 2 || k > 45) throw new Error(`items[${i}].set: P${n} cannot be set`);
            while (params.length < k) params.push(0);
            params[k - 1] = num(v, `items[${i}].set P${k}`);
          }
          return { params, label: item.word ? String(item.word).toUpperCase() : host.nameOf(params[0]!) };
        });
        const before = new Set(keys(score));
        let ids: number[] = [];
        return change(
          made.length === 1 ? `Insert ${made[0]!.label}` : `Insert ${made.length} items`,
          (editor, s) => {
            for (const { params, label } of made) editor.insertItem(params, label);
            ids = added(s, before);
            const at = new Map(keys(s).map((key, index) => [key, index]));
            editor.select(ids.map((id) => at.get(id)!));
          },
          {
            get ids() {
              return ids;
            },
          },
        );
      },
    },
    {
      name: 'insert_text',
      title: 'Insert text',
      description: 'A text item (code 16) on staff at position (P3) and level (P4, default the usual height). font is WinScore\'s font number (_00 … _36; default the usual). "/" divides the text into several items, as SCORE\'s quick entry does. One undo step.',
      inputSchema: {
        type: 'object',
        properties: { text: { type: 'string' }, staff: { type: 'number' }, position: { type: 'number' }, level: { type: 'number' }, font: { type: 'number' } },
        required: ['text', 'staff', 'position'],
      },
      run(args) {
        const { score } = need();
        const characters = text(args.text, 'text');
        const params = [num(args.staff, 'staff'), num(args.position, 'position'), optionalNum(args.level, 'level') ?? 0];
        const font = optionalNum(args.font, 'font') ?? -1;
        const before = new Set(keys(score));
        let ids: number[] = [];
        return change(
          'Insert text',
          (editor, s) => {
            editor.insertText(withFont(characters, font), params);
            ids = added(s, before);
          },
          {
            get ids() {
              return ids;
            },
          },
        );
      },
    },
    {
      name: 'set_text',
      title: 'Change a text',
      description: 'Replaces the characters of a text item (keeping its font unless the new text starts with a font code _NN).',
      inputSchema: { type: 'object', properties: { id: { type: 'number' }, text: { type: 'string' } }, required: ['id', 'text'] },
      run(args) {
        const { score } = need();
        const [index] = indicesOf(score, [args.id], 'id');
        const characters = text(args.text, 'text');
        return change('Edit text', (editor) => {
          editor.setText(index!, characters);
        });
      },
    },
    {
      name: 'move_items',
      title: 'Move items',
      description: 'Moves items by dx P3 spaces along their staves and dy scale steps up (negative: down), and by staves (+1 one staff up, −1 down), as the arrow keys and [ ] do. One undo step.',
      inputSchema: {
        type: 'object',
        properties: { ids: { type: 'array', items: { type: 'number' } }, dx: { type: 'number' }, dy: { type: 'number' }, staves: { type: 'number' } },
        required: ['ids'],
      },
      run(args) {
        const { score } = need();
        const indices = indicesOf(score, args.ids);
        const dx = optionalNum(args.dx, 'dx') ?? 0;
        const dy = optionalNum(args.dy, 'dy') ?? 0;
        const staves = Math.trunc(optionalNum(args.staves, 'staves') ?? 0);
        return change('Move', (editor) => {
          editor.select(indices);
          if (dx || dy) editor.moveSelection(dx, dy);
          for (let i = 0; i < Math.abs(staves); i++) editor.moveStaff(staves > 0 ? 1 : -1);
        });
      },
    },
    {
      name: 'delete_items',
      title: 'Delete items',
      description: 'Deletes items by id. One undo step.',
      inputSchema: { type: 'object', properties: { ids: { type: 'array', items: { type: 'number' } } }, required: ['ids'] },
      annotations: { destructiveHint: true },
      run(args) {
        const { score } = need();
        const indices = indicesOf(score, args.ids);
        return change(`Delete ${indices.length} item${indices.length === 1 ? '' : 's'}`, (editor) => {
          editor.select(indices);
          editor.deleteSelection();
        });
      },
    },
    {
      name: 'run_command',
      title: 'Run a SCORE command',
      description: 'Runs a SCORE edit command line on items, as WinScore\'s command bar does: an edit word on the items given by id (list_commands: "FLI" flip, "NST" no stem, "R 5" right 5 spaces, "FLN" fit stems and beams …), or a group or layout command, run with nothing selected, whose questions are answered in turn by answers: "LJ" with answers ["1 2"] lines up and justifies the system of staves 1 and 2; "LJA" all systems; "M" (move area) with ["1 0 200", "2"]. The engine\'s messages come back; a question left unanswered ends the command unchanged. One undo step.',
      inputSchema: {
        type: 'object',
        properties: {
          command: { type: 'string' },
          ids: { type: 'array', items: { type: 'number' }, description: 'The items an edit word acts on' },
          answers: { type: 'array', items: { type: 'string' }, description: 'Answers to a group command\'s questions, in order' },
        },
        required: ['command'],
      },
      run(args) {
        const { score } = need();
        const line = text(args.command, 'command').trim();
        const indices = args.ids === undefined ? [] : indicesOf(score, args.ids);
        const answers = args.answers === undefined ? [] : list(args.answers, 'answers').map((a) => String(a));
        let unanswered: string | null = null;
        return change(
          line,
          (editor) => {
            editor.select(groupCommand(line) ? [] : indices);
            editor.execute(line);
            for (const answer of answers) {
              if (editor.prompt() === null) break;
              editor.execute(answer);
            }
            unanswered = editor.prompt();
            if (unanswered !== null) editor.execute('X');
          },
          {
            get question() {
              return unanswered ?? undefined;
            },
          },
        );
      },
    },
    {
      name: 'undo',
      title: 'Undo',
      description: 'Undoes the last steps in the window\'s history (default one), whoever made them.',
      inputSchema: { type: 'object', properties: { steps: { type: 'number' } } },
      run(args) {
        need();
        const done = Array.from({ length: Math.max(1, optionalNum(args.steps, 'steps') ?? 1) }, () => host.undo()).filter(Boolean);
        return json({ undone: done });
      },
    },
    {
      name: 'redo',
      title: 'Redo',
      description: 'Redoes steps undone (default one).',
      inputSchema: { type: 'object', properties: { steps: { type: 'number' } } },
      run(args) {
        need();
        const done = Array.from({ length: Math.max(1, optionalNum(args.steps, 'steps') ?? 1) }, () => host.redo()).filter(Boolean);
        return json({ redone: done });
      },
    },
    {
      name: 'describe_kind',
      title: 'What an item\'s numbers mean',
      description: 'For an item code: what each parameter P1 … Pn means (from the SCORE help), the side panel\'s settings with their choices, and the creation words that make one.',
      inputSchema: { type: 'object', properties: { code: { type: 'number' } }, required: ['code'] },
      annotations: { readOnlyHint: true },
      run(args) {
        const code = num(args.code, 'code');
        const names = host.paramNames(code);
        return json({
          code,
          kind: host.nameOf(code),
          parameters: Object.fromEntries(names.map((n, i) => [`P${i + 1}`, n])),
          settings: sectionsFor(code).flatMap((section) =>
            section.settings.map((s) => ({
              section: section.title,
              name: s.label,
              kind: s.kind,
              ...('help' in s && s.help ? { help: s.help } : {}),
              ...(s.kind === 'choice' ? { choices: s.options.map((o) => o.label) } : {}),
            })),
          ),
          words: (JSON.parse(creationWords()) as [string, number[]][]).filter(([, p]) => p[0] === code).map(([w]) => w),
        });
      },
    },
    {
      name: 'list_words',
      title: 'SCORE creation words',
      description: 'SCORE\'s creation words, which insert_items takes, with the parameters each gives a new item (P2, the staff, is the caller\'s). Numbered forms exist too: METER34 (3/4), METER68, KSIG+2 / KSIG-3 (sharps or flats, B, A or T after it for bass, alto or tenor clef), BAR2, BEAM2 (two beams), SLUR2, TREM2.',
      inputSchema: { type: 'object', properties: { code: { type: 'number', description: 'Only words making items of this code' } } },
      annotations: { readOnlyHint: true },
      run(args) {
        const code = optionalNum(args.code, 'code');
        const rows = (JSON.parse(creationWords()) as [string, number[]][]).filter(([, p]) => code === undefined || p[0] === code);
        return json(rows.map(([word, params]) => ({ word, kind: host.nameOf(params[0]!), params })));
      },
    },
    {
      name: 'list_commands',
      title: 'SCORE edit commands',
      description: 'SCORE\'s edit words for run_command, with the item codes each acts on and what it does; search narrows them (e.g. "stem", "beam", "slur").',
      inputSchema: { type: 'object', properties: { search: { type: 'string' } } },
      annotations: { readOnlyHint: true },
      run(args) {
        const search = typeof args.search === 'string' ? args.search.toLowerCase() : '';
        const rows = (JSON.parse(editWords()) as [string, number[], string][]).filter(([word, , meaning]) => !search || word.toLowerCase().includes(search) || meaning.toLowerCase().includes(search));
        return json({
          words: rows.map(([word, codes, meaning]) => ({ word, codes, meaning })),
          groupAndLayout: 'LI, J, LJ (line up, justify, both: a system, asked as "lowest staff, number of staves"), LJA (all systems), M (move area), CO (copy area), DG (delete area), A (alter area), CPX (copy to staves), UND (undelete), TR (transpose)',
        });
      },
    },
    {
      name: 'open_file',
      title: 'Open a file',
      description: 'Opens a .mus file by its absolute path (or ~/…) in the window, in place of the score there. Unsaved changes are only thrown away with discard_changes.',
      inputSchema: { type: 'object', properties: { path: { type: 'string' }, discard_changes: { type: 'boolean' } }, required: ['path'] },
      annotations: { destructiveHint: true },
      async run(args) {
        const path = text(args.path, 'path');
        if (host.file().modified && args.discard_changes !== true) throw new Error(`${host.file().name} has unsaved changes: save it first, or pass discard_changes`);
        await host.open(path);
        host.notify(`${client}: opened ${path}`);
        return json({ opened: path, items: host.score()?.itemCount() ?? 0 });
      },
    },
    {
      name: 'new_score',
      title: 'New score',
      description: 'An empty score in the window, in place of the one there (insert_items with STAFF makes its staves). Unsaved changes are only thrown away with discard_changes.',
      inputSchema: { type: 'object', properties: { discard_changes: { type: 'boolean' } } },
      annotations: { destructiveHint: true },
      run(args) {
        if (host.file().modified && args.discard_changes !== true) throw new Error(`${host.file().name} has unsaved changes: save it first, or pass discard_changes`);
        host.newScore();
        return json({ opened: 'untitled.mus' });
      },
    },
    {
      name: 'save',
      title: 'Save',
      description: 'Saves the score to its file, or to path (absolute, or ~/…), which then becomes its file.',
      inputSchema: { type: 'object', properties: { path: { type: 'string' } } },
      async run(args) {
        need();
        const path = args.path === undefined ? null : text(args.path, 'path');
        if (!path && !host.file().path) throw new Error(`${host.file().name} has no file yet: give a path`);
        const written = await host.save(path);
        host.notify(`${client}: saved ${written}`);
        return json({ saved: written });
      },
    },
    {
      name: 'export_svg',
      title: 'Export SVG',
      description: 'Writes the page as printed (without staff numbers) as an SVG file to path (absolute, or ~/…), with its fonts embedded.',
      inputSchema: { type: 'object', properties: { path: { type: 'string' } }, required: ['path'] },
      async run(args) {
        need();
        const path = text(args.path, 'path');
        await host.exportSvg(path);
        return json({ exported: path });
      },
    },
  ];

  /** Answers one JSON-RPC message; null for notifications and responses. */
  async function handle(message: unknown): Promise<unknown | null> {
    const m = (message ?? {}) as JsonRpc;
    const id = m.id;
    if (typeof m.method !== 'string') return null;
    const reply = (result: unknown) => (id === undefined ? null : { jsonrpc: '2.0', id, result });
    const fail = (code: number, text: string) => (id === undefined ? null : { jsonrpc: '2.0', id, error: { code, message: text } });
    const params = m.params ?? {};
    switch (m.method) {
      case 'initialize': {
        const info = params.clientInfo as { name?: string; title?: string } | undefined;
        client = info?.title || info?.name || client;
        const asked = String(params.protocolVersion ?? '');
        return reply({
          protocolVersion: PROTOCOL_VERSIONS.includes(asked) ? asked : PROTOCOL_VERSIONS[0],
          capabilities: { tools: { listChanged: false } },
          serverInfo: SERVER,
          instructions: INSTRUCTIONS,
        });
      }
      case 'ping':
        return reply({});
      case 'tools/list':
        return reply({ tools: tools.map(({ name, title, description, inputSchema, annotations }) => ({ name, title, description, inputSchema, ...(annotations ? { annotations } : {}) })) });
      case 'tools/call': {
        const tool = tools.find((t) => t.name === params.name);
        if (!tool) return fail(-32602, `Unknown tool: ${String(params.name)}`);
        try {
          return reply(await tool.run((params.arguments ?? {}) as Args));
        } catch (err) {
          return reply({ content: [{ type: 'text', text: err instanceof Error ? err.message : String(err) }], isError: true });
        }
      }
      default:
        return m.method.startsWith('notifications/') ? null : fail(-32601, `Method not found: ${m.method}`);
    }
  }

  return { handle, tools };
}
