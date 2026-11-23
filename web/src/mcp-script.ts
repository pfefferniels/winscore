// run_script, the MCP tool with which an assistant writes code instead of
// calling the other tools one at a time: a function body of JavaScript, run
// in the page against `score`, an API over the page shown, as one undo step.
// It is for edits that are worked out (transpose a passage, a mark under
// every first beat, respacing) and for reading and analysing the whole page,
// where single tool calls would carry every item through the assistant.
//
// The code runs synchronously in the page, with the page's rights: no
// sandbox, which is why the desktop app's MCP dialog has a switch for it.
// Every read goes to the score as it is at that moment (an item is its id,
// read afresh), so reads follow the script's own edits; whatever throws undoes
// all of it.
import type { Change } from './editor';
import type { McpHost } from './mcp';
import { withFont } from './text-dialog';
import type { Facts } from './tools';
import type { Score } from './wasm/score_web.js';

/** What the script tool needs of the MCP server. */
export interface ScriptKit {
  host: McpHost;
  /** Item `index` as get_items shows it (`full`), or list_items. */
  read(score: Score, ids: number[], index: number, full: boolean): Record<string, unknown> | null;
  /** The parameter changes that give item `index` the panel's settings `wanted`. */
  settingChanges(score: Score, index: number, wanted: [string, unknown][]): [number, number][];
  /** P1 … of a note or rest as add_notes takes it, null if it cannot be made. */
  noteFrom(facts: Facts, staff: number, note: unknown, where: string): number[] | null;
  /** P1 … of an item as insert_items takes it. */
  itemFrom(item: unknown, where: string): { params: number[]; label: string };
  /** The edit commands that run on no selection (LJ, M …). */
  groupCommand(line: string): boolean;
}

/** How long a script may keep calling the API, in milliseconds. */
const TIME_LIMIT = 20_000;
/** At most this many characters of the result and the log go back. */
const MAX_OUTPUT = 100_000;
const MAX_LOG_LINES = 500;

const CLEFS = ['treble', 'bass', 'alto', 'tenor', 'percussion'];

export const SCRIPT_DESCRIPTION = `Runs JavaScript in WinScore against the page shown, as one undo step: for edits that are worked out or touch many items (transpose a passage, a mark under every first beat, respacing) and for reading or analysing the whole page, instead of many single tool calls. code is the body of a function, run synchronously (no await) with score and console; what it returns comes back as JSON, with what console.log wrote. If it throws, everything it changed is undone; the window shows the result at once.

score:
- items({staff, code, from, to}) → items in file order (code: 1 note, 2 rest, 3 clef, 5 slur/tie, 6 beam, 9 symbol, 14 barline, 16 text, 17 key signature, 18 meter …, or a list of codes; from/to: a P3 range); item(id); selection()
- staves() → [{staff, lines, clef}]; clefAt(staff, position) → "treble", "bass", "alto", "tenor" or "percussion"
- addNote({staff, position, pitch, duration, dots, accidental, stem, size}) → item, as add_notes takes a note (pitch "F#4" or "rest", read in the clef there)
- insert({word, staff, position, level, set} or {params}) → item, as insert_items; insertText({text, staff, position, level, font}) → items
- command(line, {items, answers}) → {messages, question}, as run_command (an edit word on items, or LJ, M … answered in turn)
- delete(items); select(items): what the window selects afterwards
An item has id, code, kind, staff, p3, p4, params ([P1, P2 …]), p(n) (Pn), settings (the panel's, as get_items: {Pitch: "F♯4", Value: "Eighth", Stem: "Up" …}), text, summary; and set({Pitch: "G4", Value: "Half"}), setParams({5: 20}), move(dx, dy, staves), setText(text), delete(). Its fields are read afresh each time, so they follow edits; items and ids may be given alike wherever items are taken.

Example, a third up on staff 2 (accidentals as they were): for (const n of score.items({staff: 2, code: 1})) n.move(0, 2); return score.items({staff: 2, code: 1}).map((n) => n.summary);
Scripts must finish quickly; one that loops without calling score cannot be stopped.`;

export const SCRIPT_SCHEMA = {
  type: 'object',
  properties: {
    code: { type: 'string', description: 'The body of a function of score and console; may return a value' },
    label: { type: 'string', description: 'The undo step\'s name in the window (default "Script")' },
  },
  required: ['code'],
};

/** What a script hands back: the batch's step, its value and its log. */
export interface ScriptOutcome {
  step: string | null;
  value: unknown;
  log: string[];
  engine: string[];
}

/** A value for the log, as console.log would show it. */
function logText(value: unknown): string {
  if (typeof value === 'string') return value;
  try {
    return JSON.stringify(value) ?? String(value);
  } catch {
    return String(value);
  }
}

/** The line in the script where `err` was thrown, where the engine says it (V8: "<anonymous>:LINE:COL", two lines below the body's start). */
function lineOf(err: unknown): number | null {
  const stack = err instanceof Error ? (err.stack ?? '') : '';
  const match = /<anonymous>:(\d+):\d+/.exec(stack);
  return match ? Number(match[1]) - 2 : null;
}

/** Text of at most MAX_OUTPUT characters. */
export function clipped(text: string): string {
  return text.length <= MAX_OUTPUT ? text : `${text.slice(0, MAX_OUTPUT)}\n… (${text.length - MAX_OUTPUT} more characters: return less)`;
}

/** Runs `code` as one undo step `label`; throws (with everything undone) what the script throws, its log with it. */
export function runScript(kit: ScriptKit, code: string, label: string): ScriptOutcome {
  const { host } = kit;
  let body: (score: unknown, console: unknown) => unknown;
  try {
    body = new Function('score', 'console', `"use strict"; ${code}`) as typeof body;
  } catch (err) {
    throw new Error(`The script does not parse: ${err instanceof Error ? err.message : String(err)}`);
  }

  const log: string[] = [];
  const engine: string[] = [];
  const write = (...values: unknown[]) => {
    if (log.length < MAX_LOG_LINES) log.push(values.map(logText).join(' '));
    else if (log.length === MAX_LOG_LINES) log.push('… (more lines left out)');
  };
  const console = { log: write, info: write, warn: write, error: write, debug: write };
  let value: unknown;
  let live = true;
  const deadline = performance.now() + TIME_LIMIT;

  try {
    const step = host.batch(label, (editor, score) => {
      // Ids in file order and their indices, worked out again after each edit.
      let ids: number[] | null = null;
      let at: Map<number, number> | null = null;
      const known = () => {
        if (!ids || !at) {
          ids = Array.from(score.keys());
          at = new Map(ids.map((id, index) => [id, index]));
        }
        return { ids, at };
      };
      const check = () => {
        if (!live) throw new Error('This score object belongs to a script that has finished');
        if (performance.now() > deadline) throw new Error(`The script ran longer than ${TIME_LIMIT / 1000} s`);
      };
      const edit = (action: () => Change | null) => {
        check();
        const change = action();
        ids = at = null;
        if (change?.message) engine.push(change.message);
        return change;
      };
      const idOf = (x: unknown): number => {
        const id = typeof x === 'object' && x !== null && 'id' in x ? Number((x as { id: unknown }).id) : Number(x);
        if (!Number.isFinite(id)) throw new Error(`${logText(x)} is not an item or an id`);
        return id;
      };
      const indexOf = (x: unknown): number => {
        check();
        const id = idOf(x);
        const index = known().at.get(id);
        if (index === undefined) throw new Error(`No item has the id ${id} (deleted?)`);
        return index;
      };
      const indicesOf = (xs: unknown): number[] => {
        const list = Array.isArray(xs) ? xs : [xs];
        return list.map(indexOf);
      };
      const paramsOf = (index: number): number[] => {
        const info = score.item(index);
        if (!info) return [];
        // f32 in the file: to 4 decimals, as the other tools give them.
        const params = Array.from(info.params, (v) => Math.round(v * 10000) / 10000);
        info.free();
        return params;
      };
      const readItem = (x: unknown, full: boolean) => kit.read(score, known().ids, indexOf(x), full) ?? {};

      // What noteFrom needs, read from the score as it is now (the window's are as it was last drawn).
      const staffLines = () => {
        const numbers = editor.staves();
        const staves: { staff: number; lowest: number; lines: number }[] = [];
        for (let i = 0; i + 7 <= numbers.length; i += 7) staves.push({ staff: numbers[i]!, lowest: Math.round(numbers[i + 5]!), lines: numbers[i + 6]! });
        return staves.sort((a, b) => a.staff - b.staff);
      };
      const clefParams = (staff: number, p3: number): { p4: number; p5: number } | null => {
        const numbers = score.itemSummaries();
        let found: { index: number; p3: number } | null = null;
        for (let i = 0; i < numbers.length / 3; i++) {
          if (numbers[3 * i] !== 3 || numbers[3 * i + 1] !== staff || numbers[3 * i + 2]! > p3 + 0.5) continue;
          if (!found || numbers[3 * i + 2]! >= found.p3) found = { index: i, p3: numbers[3 * i + 2]! };
        }
        if (!found) return null;
        const params = paramsOf(found.index);
        return { p4: params[3] ?? 0, p5: params[4] ?? 0 };
      };
      const facts: Facts = {
        creation: (word) => host.facts.creation(word),
        clefAt: clefParams,
        middle(staff) {
          const lines = staffLines().find((s) => s.staff === staff);
          return lines ? lines.lowest + lines.lines - 1 : 7;
        },
      };
      const clefName = (staff: number, p3: number) => {
        const clef = clefParams(staff, p3);
        return CLEFS[Math.trunc(Math.abs(clef?.p5 ?? 0))] ?? `type ${clef?.p5}`;
      };

      /** The items an edit adds, made by `action`. */
      const adding = (action: () => Change | null): ScriptItem[] => {
        const before = new Set(known().ids);
        edit(action);
        return known()
          .ids.filter((id) => !before.has(id))
          .map(item);
      };

      type ScriptItem = ReturnType<typeof item>;
      function item(id: number) {
        return {
          id,
          get code() {
            return paramsOf(indexOf(id))[0] ?? 0;
          },
          get kind() {
            return host.nameOf(this.code);
          },
          get staff() {
            return paramsOf(indexOf(id))[1] ?? 0;
          },
          get p3() {
            return paramsOf(indexOf(id))[2] ?? 0;
          },
          get p4() {
            return paramsOf(indexOf(id))[3] ?? 0;
          },
          get params() {
            return paramsOf(indexOf(id));
          },
          p(n: number) {
            return paramsOf(indexOf(id))[n - 1] ?? 0;
          },
          get settings() {
            return readItem(id, true).settings as Record<string, unknown>;
          },
          get text() {
            return (readItem(id, true).text as string | undefined) ?? null;
          },
          get summary() {
            return readItem(id, false).summary as string;
          },
          set(settings: Record<string, unknown>) {
            const index = indexOf(id);
            const wanted = Object.entries(settings ?? {});
            const changes = kit.settingChanges(score, index, wanted);
            edit(() => editor.setParamsOf([[index, changes]]));
            return this;
          },
          setParams(params: Record<string, number>) {
            const index = indexOf(id);
            const changes = Object.entries(params ?? {}).map(([n, v]): [number, number] => {
              const k = Number(String(n).replace(/^p/i, ''));
              if (!Number.isInteger(k) || k < 2 || k > 45) throw new Error(`P${n}: parameters 2 to 45 can be set`);
              if (!Number.isFinite(Number(v))) throw new Error(`P${k} must be a number`);
              return [k, Number(v)];
            });
            edit(() => editor.setParamsOf([[index, changes]]));
            return this;
          },
          move(dx = 0, dy = 0, staves = 0) {
            const index = indexOf(id);
            edit(() => {
              editor.select([index]);
              const moved = dx || dy ? editor.moveSelection(dx, dy) : null;
              for (let i = 0; i < Math.abs(Math.trunc(staves)); i++) editor.moveStaff(staves > 0 ? 1 : -1);
              return moved;
            });
            return this;
          },
          setText(text: string) {
            const index = indexOf(id);
            edit(() => editor.setText(index, String(text)));
            return this;
          },
          delete() {
            const index = indexOf(id);
            edit(() => {
              editor.select([index]);
              return editor.deleteSelection();
            });
          },
          toJSON() {
            return readItem(id, true);
          },
        };
      }

      const api = {
        items(filter: { staff?: number; code?: number | number[]; from?: number; to?: number } = {}) {
          check();
          const codes = filter.code === undefined ? null : new Set(Array.isArray(filter.code) ? filter.code : [filter.code]);
          const from = filter.from ?? -Infinity;
          const to = filter.to ?? Infinity;
          const numbers = score.itemSummaries();
          const { ids } = known();
          const found: ScriptItem[] = [];
          for (let i = 0; i < numbers.length / 3; i++) {
            const [c, s, p3] = [numbers[3 * i]!, numbers[3 * i + 1]!, numbers[3 * i + 2]!];
            if ((codes === null || codes.has(c)) && (filter.staff === undefined || s === filter.staff) && p3 >= from && p3 <= to) found.push(item(ids[i]!));
          }
          return found;
        },
        item(id: unknown) {
          indexOf(id);
          return item(idOf(id));
        },
        selection() {
          check();
          const { ids } = known();
          return Array.from(score.selection(), (i) => item(ids[i]!));
        },
        staves() {
          check();
          return staffLines().map((s) => ({ staff: s.staff, lines: s.lines, clef: clefName(s.staff, 6) }));
        },
        clefAt(staff: number, position: number) {
          check();
          return clefName(Number(staff), Number(position));
        },
        addNote(note: { staff?: number } & Record<string, unknown>) {
          check();
          const staff = Number(note?.staff);
          if (!staffLines().some((s) => s.staff === staff)) throw new Error(`addNote: there is no staff ${String(note?.staff)}`);
          const params = kit.noteFrom(facts, staff, note, 'addNote');
          if (!params) throw new Error('addNote: the note cannot be made');
          return adding(() => editor.insertItem(params, 'Note'))[0] ?? null;
        },
        insert(spec: Record<string, unknown>) {
          check();
          const { params, label: name } = kit.itemFrom(spec, 'insert');
          return adding(() => editor.insertItem(params, name))[0] ?? null;
        },
        insertText(spec: { text?: unknown; staff?: unknown; position?: unknown; level?: unknown; font?: unknown }) {
          check();
          const characters = String(spec?.text ?? '');
          if (!characters) throw new Error('insertText: text is empty');
          const font = spec.font === undefined ? -1 : Number(spec.font);
          const params = [Number(spec.staff), Number(spec.position), Number(spec.level ?? 0)];
          if (!params.every(Number.isFinite)) throw new Error('insertText: give staff and position as numbers');
          return adding(() => editor.insertText(withFont(characters, font), params));
        },
        command(line: string, options: { items?: unknown[]; answers?: string[] } = {}) {
          check();
          const command = String(line).trim();
          const indices = options.items === undefined ? [] : indicesOf(options.items);
          const before = engine.length;
          let question: string | null = null;
          edit(() => {
            editor.select(kit.groupCommand(command) ? [] : indices);
            const first = editor.execute(command);
            if (first?.message) engine.push(first.message);
            for (const answer of options.answers ?? []) {
              if (editor.prompt() === null) break;
              const next = editor.execute(String(answer));
              if (next?.message) engine.push(next.message);
            }
            question = editor.prompt();
            if (question !== null) editor.execute('X');
            return null;
          });
          return { messages: engine.slice(before), question };
        },
        delete(items: unknown) {
          const indices = indicesOf(items);
          if (indices.length === 0) return;
          edit(() => {
            editor.select(indices);
            return editor.deleteSelection();
          });
        },
        select(items: unknown) {
          const indices = indicesOf(items ?? []);
          editor.select(indices);
        },
      };

      try {
        value = body(Object.freeze(api), Object.freeze(console));
        if (value !== null && typeof value === 'object' && typeof (value as { then?: unknown }).then === 'function') {
          throw new Error('run_script runs synchronously: the code may not use async or await');
        }
        // Into plain data while the items can still be read.
        value = value === undefined ? null : JSON.parse(JSON.stringify(value, (_, v: unknown) => (typeof v === 'bigint' ? Number(v) : v)) ?? 'null');
      } finally {
        live = false;
      }
    });
    return { step, value, log, engine };
  } catch (err) {
    const line = lineOf(err);
    const message = err instanceof Error ? err.message : String(err);
    const failure = new Error(`${message}${line !== null && line > 0 ? ` (line ${line})` : ''}. Nothing was changed.`);
    (failure as Error & { log?: string[] }).log = log;
    throw failure;
  }
}
