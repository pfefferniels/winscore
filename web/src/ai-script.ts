// Edit scripts: what an AI command becomes, however it was read (the local
// word rules, Jev's choices, or Claude). A script is a list of steps on the
// items the command is about, with knobs for what the words leave open ("how
// much bigger?"). It runs on the real score as one undo step; while a knob's
// slider is dragged, that step is taken back and the script runs again with
// the new value.
import type { Editor } from './editor';
import type { InputLine } from './wasm/score_web.js';
import { sectionsFor, type Change, type Context, type NumberSetting, type P, type Setting } from './item-fields';
import { valueOf, type Compiled, type Vars } from './ai-expr';
import { quartersFor } from './ai-values';

/** A number a step leaves open, set with a slider. */
export interface Knob {
  id: string;
  label: string;
  min: number;
  max: number;
  step: number;
  value: number;
}

/** A number, or an expression over the item (p1 … p45, t, i, n …) and the knobs. */
export type Value = number | string;

/**
 * Which of the command's items a step acts on: of these codes (all when
 * empty), for which `where` holds, and whose setting `setting` reads `is`
 * (an option's name, e.g. Mark is Staccato).
 */
export interface Filter {
  codes?: number[] | null;
  where?: string | null;
  setting?: string | null;
  is?: string | null;
}

export type Step =
  /** Parameter `param` of each item becomes `value`. */
  | { do: 'set'; items?: Filter | null; param: number; value: Value }
  /**
   * A setting by the side panel's name ("Stem", "Mark", "Size", "Start level") becomes an option's name, a number or on/off.
   * Names joined by "|" are alternatives: each item takes the first one it shows.
   */
  | { do: 'setting'; items?: Filter | null; setting: string; value: Value | boolean }
  /** WinScore's arrow keys: P3 spaces right, scale steps up. */
  | { do: 'move'; items?: Filter | null; right?: Value | null; up?: Value | null }
  | { do: 'delete'; items?: Filter | null }
  /** A SCORE edit command on the items (FLI, NST, R 5 …); a group command (FLN …) is given their area. */
  | { do: 'command'; items?: Filter | null; line: string }
  /** A line of music input on a staff between two positions (the region's when left out). */
  | { do: 'insert'; staff?: number | null; from?: number | null; to?: number | null; notes: string; rhythms?: string | null; marks?: string | null; beams?: string | null; slurs?: string | null }
  /** The notes under beams, `size` notes or chords each (0: all up to the next barline). */
  | { do: 'beam'; items?: Filter | null; size: Value }
  /** The items picked become the selection, and what the steps after it act on; nothing is edited. */
  | { do: 'select'; items?: Filter | null }
  /**
   * For each item picked, a new item with P1 … Pn from these values (over the item it is made for); none where P1 comes to 0.
   * A text (P1 16) has `text` as its characters and is made as quick entry makes it: P2 … P11 from the values, P3 + 1000 centred on P3.
   */
  | { do: 'add'; items?: Filter | null; params: Value[]; text?: string | null };

export interface Script {
  /** What it does, in a few words. */
  summary: string;
  knobs: Knob[];
  steps: Step[];
}

/** Where new things go: a staff and a stretch of it in P3, by the selection. */
export interface Region {
  /** The staff where music goes. */
  staff: number;
  /** The lowest and highest staff the selection reaches. */
  bottom: number;
  top: number;
  from: number;
  to: number;
}

/** What a command is about: items by identity (null: the whole score), and where music it adds goes. */
export interface Scope {
  keys: number[] | null;
  region: Region | null;
}

/** What the script needs of the score besides the editor. */
export interface Access {
  editor: Editor;
  /** P1 … Pn of item `index`. */
  params(index: number): Float32Array | null;
  context(index: number): Context;
  /** Seven numbers per staff: number, left and right x, y of level 0, scale step, lowest line's level, lines. */
  staves(): Float32Array;
  /** Code, staff and P3 of every item, three numbers each. */
  summaries(): Float32Array;
  /** Whether a command line is a group command only (FLN …), which starts with nothing selected. */
  groupCommand(line: string): boolean;
  inputLine(passes: string[], staff: number, from: number, to: number): InputLine;
}

export interface Ran {
  /** The history mark before the run, for rolling it back. */
  mark: number;
  /** Whether it changed the score (and made an undo step). */
  changed: boolean;
  /** Items it changed or made, by identity. */
  touched: number[];
}

const NOTE = 1;
const BEAM = 6;
const BARLINE = 14;
const TEXT = 16;
/** Quick text entry takes P2 … P11. */
const TEXT_PARAMS = 11;
const MAX_PARAM = 45;
/** Notes this long or longer (and grace notes, from 64) are not beamed, as the engine's refit has it. */
const BEAMABLE = 0.99;
const GRACE = 64;
/** Notes closer than this in P3 form one chord. */
const CHORD = 0.05;

/**
 * Runs a line on the editor. The engine's message is a failure it reports
 * rather than throws (a refit it gave up on, for one): thrown here, under
 * `what`, so the script's steps go back.
 */
function execute(editor: Editor, line: string, what = line) {
  const message = editor.execute(line)?.message;
  if (message) throw new Error(`${what} (${message.replace(/^\*+ ?/, '')})`);
}

/** A note a beam can go over: shorter than a quarter, not a grace note. */
const beamable = (t: Target) => t.params[0] === NOTE && t.params[6]! > 0 && t.params[6]! < BEAMABLE && t.params[6]! < GRACE;

/** P4 without the hundred of cue size. */
const level = (p4: number) => (Math.abs(p4) >= 100 ? p4 - 100 * Math.sign(p4) : p4);

/** Lower case letters and digits only, for comparing names. */
export const plain = (s: string) => s.toLowerCase().replace(/[^a-z0-9]/g, '');

/** One target: its index now, identity and parameters. */
interface Target {
  index: number;
  key: number;
  params: Float32Array;
}

function keyIndex(editor: Editor): Map<number, number> {
  const keys = editor.keys();
  const map = new Map<number, number>();
  keys.forEach((key, index) => map.set(key, index));
  return map;
}

/** The items of the scope that pass the filter, in file order. */
function targets(access: Access, scope: Scope, filter: Filter | null | undefined, knobs: Vars): Target[] {
  return filter?.where ? picked(access, scope, filter, knobs).list : found(access, scope, filter);
}

/**
 * The items that pass the filter with their variables as the filter saw
 * them: their place among all the items of the codes and setting asked for,
 * so the last one picked still has a next one.
 */
function picked(access: Access, scope: Scope, filter: Filter | null | undefined, knobs: Vars): { list: Target[]; vars: Vars[] } {
  const all = found(access, scope, filter);
  const vars = placeVars(access, all);
  if (!filter?.where) return { list: all, vars };
  const where = valueOf(filter.where);
  const keep = vars.map((v) => where({ ...knobs, ...v }) !== 0);
  return { list: all.filter((_, k) => keep[k]), vars: vars.filter((_, k) => keep[k]) };
}

/** The items of the scope of the codes and setting value asked for, in file order. */
function found(access: Access, scope: Scope, filter: Filter | null | undefined): Target[] {
  const keys = access.editor.keys();
  let indices: number[];
  if (scope.keys === null) indices = keys.map((_, i) => i);
  else {
    const at = keyIndex(access.editor);
    indices = scope.keys.flatMap((key) => at.get(key) ?? []).sort((a, b) => a - b);
  }
  const codes = filter?.codes?.length ? new Set(filter.codes) : null;
  const list: Target[] = [];
  for (const index of indices) {
    const params = access.params(index);
    if (!params) continue;
    if (codes && !codes.has(params[0]!)) continue;
    if (filter?.setting && filter.is != null && !reads(params, filter.setting, filter.is, access.context(index))) continue;
    list.push({ index, key: keys[index]!, params });
  }
  return list;
}

/** Whether setting `name` of an item reads `wanted`: an option's name, a number, on/off or text. */
function reads(params: Float32Array, name: string, wanted: string, ctx: Context): boolean {
  const p: P = (n) => params[n - 1] ?? 0;
  const named = applicable(params[0]!, name, p);
  if (!named) return false;
  const { setting } = named;
  switch (setting.kind) {
    case 'choice': {
      const option = optionNamed(setting.options, wanted);
      return option !== null && Math.abs(setting.get(p) - option) < 1e-4;
    }
    case 'toggle':
      return setting.get(p) === ON.has(wanted.toLowerCase());
    case 'number':
      return Math.abs(setting.get(p) - Number(wanted)) < 1e-4;
    case 'text':
      return plain(setting.show(p, ctx)) === plain(wanted);
  }
}

function paramVars(params: Float32Array): Vars {
  const vars: Vars = {};
  for (let n = 1; n <= MAX_PARAM; n++) vars[`p${n}`] = params[n - 1] ?? 0;
  vars.code = vars.p1!;
  vars.staff = vars.p2!;
  vars.x = vars.p3!;
  vars.level = level(vars.p4!);
  return vars;
}

/** Staves grouped into systems top to bottom: a gap well over the usual one between staves starts a new system. */
function systemOrder(staves: Float32Array): Map<number, number> {
  const rows = Array.from({ length: staves.length / 7 }, (_, i) => ({ number: staves[7 * i]!, y: staves[7 * i + 3]! }));
  rows.sort((a, b) => b.y - a.y);
  const gaps = rows.slice(1).map((r, i) => rows[i]!.y - r.y).sort((a, b) => a - b);
  const usual = gaps[Math.floor(gaps.length / 2)] ?? 0;
  const order = new Map<number, number>();
  let system = 0;
  rows.forEach((row, i) => {
    if (i > 0 && rows[i - 1]!.y - row.y > 1.6 * usual) system++;
    order.set(row.number, system);
  });
  return order;
}

/**
 * Where the barlines are (P3, in order) on each staff they cross: a barline
 * on staff s with P4 k crosses staves s … s + k − 1, as a system's barlines
 * stand on its lowest staff and cross the rest.
 */
export function barlines(access: Access): Map<number, number[]> {
  const summaries = access.summaries();
  const byStaff = new Map<number, number[]>();
  for (let index = 0; 3 * index < summaries.length; index++) {
    if (summaries[3 * index] !== BARLINE) continue;
    const [, staff = 0, x = 0, crosses = 1] = access.params(index) ?? [];
    for (let s = staff; s < staff + Math.max(1, crosses); s++) byStaff.set(s, [...(byStaff.get(s) ?? []), x]);
  }
  byStaff.forEach((xs, s) => byStaff.set(s, [...new Set(xs)].sort((a, b) => a - b)));
  return byStaff;
}

/** The smallest, largest and mean value of every parameter over the targets: max_p4, min_p7, mean_level … */
function extremes(list: Target[]): Vars {
  const vars: Vars = {};
  const spread = (name: string, values: number[]) => {
    vars[`min_${name}`] = Math.min(...values);
    vars[`max_${name}`] = Math.max(...values);
    vars[`mean_${name}`] = values.reduce((a, b) => a + b, 0) / (values.length || 1);
  };
  for (let n = 1; n <= MAX_PARAM; n++) spread(`p${n}`, list.map((t) => t.params[n - 1] ?? 0));
  spread('level', list.map((t) => level(t.params[3] ?? 0)));
  return vars;
}

/**
 * Each target's variables: its parameters, its identity (id, as Claude is
 * shown it), its place in reading order (i of n, t from 0 to 1; chords count
 * once), the same on its own staff (si, sn, st) and in its bar (bar, bi, bn,
 * bt: "bi == 0" is the first of each bar), where the next column on its
 * staff is (a text's: the next text on its line), the targets' leftmost and
 * rightmost P3 on its staff, the lowest and highest level of its chord
 * ("level == chord_low" is each chord's bottom note) and the extremes and
 * means of every parameter over the targets ("level == max_level" is the
 * highest).
 */
function placeVars(access: Access, list: Target[]): Vars[] {
  const systems = systemOrder(access.staves());
  // A column: a system and a position in it; the notes of a chord share one.
  const column = (t: Target): [number, number] => [systems.get(t.params[1]!) ?? 0, Math.round(t.params[2]! / CHORD)];
  const name = ([system, x]: [number, number]) => `${system}:${x}`;
  const columns = [...new Map(list.map((t) => [name(column(t)), column(t)])).values()].sort((a, b) => a[0] - b[0] || a[1] - b[1]);
  const rank = new Map(columns.map((c, i) => [name(c), i]));
  const perStaff = new Map<number, number[]>();
  list.forEach((t) => {
    const xs = perStaff.get(t.params[1]!) ?? [];
    xs.push(Math.round(t.params[2]! / CHORD));
    perStaff.set(t.params[1]!, xs);
  });
  const staffRanks = new Map([...perStaff].map(([staff, xs]) => [staff, [...new Set(xs)].sort((a, b) => a - b)]));
  // A bar: the barlines before an item on its staff (a system's opening line, at 0, is none).
  const bars = barlines(access);
  const barOf = (t: Target) => (bars.get(t.params[1]!) ?? []).filter((x) => x > 0 && x < t.params[2]!).length;
  const inBar = new Map<string, number[]>();
  list.forEach((t) => {
    const key = `${t.params[1]}:${barOf(t)}`;
    inBar.set(key, [...(inBar.get(key) ?? []), Math.round(t.params[2]! / CHORD)]);
  });
  inBar.forEach((xs, key) => inBar.set(key, [...new Set(xs)].sort((a, b) => a - b)));
  // The next column on each staff, for items made from one to the next.
  const levelsAt = new Map<string, number[]>();
  list.forEach((t) => {
    const key = `${t.params[1]}:${Math.round(t.params[2]! / CHORD)}`;
    levelsAt.set(key, [...(levelsAt.get(key) ?? []), level(t.params[3]!)]);
  });
  // A text's next one is on its line, as a verse of lyrics goes on: on its staff, within a step of its level.
  const texts = list.filter((t) => t.params[0] === TEXT);
  const nextOnLine = (t: Target) =>
    texts
      .filter((u) => u.params[1] === t.params[1] && Math.round(u.params[2]! / CHORD) > Math.round(t.params[2]! / CHORD) && Math.abs(level(u.params[3]!) - level(t.params[3]!)) < 1)
      .reduce<Target | undefined>((a, u) => (a && a.params[2]! <= u.params[2]! ? a : u), undefined);
  // A chord: the targeted notes at one place on a staff (a lone note is its own).
  const chordOf = (t: Target) => `${t.params[1]}:${Math.round(t.params[2]! / CHORD)}`;
  const chords = new Map<string, number[]>();
  list.forEach((t) => {
    if (t.params[0] === NOTE) chords.set(chordOf(t), [...(chords.get(chordOf(t)) ?? []), level(t.params[3]!)]);
  });
  const n = columns.length;
  const spread = extremes(list);
  return list.map((t) => {
    const i = rank.get(name(column(t))) ?? 0;
    const xs = staffRanks.get(t.params[1]!) ?? [];
    const si = xs.indexOf(Math.round(t.params[2]! / CHORD));
    const sn = xs.length;
    const chord = (t.params[0] === NOTE && chords.get(chordOf(t))) || [level(t.params[3]!)];
    const bar = barOf(t);
    const barXs = inBar.get(`${t.params[1]}:${bar}`) ?? [];
    const bi = barXs.indexOf(Math.round(t.params[2]! / CHORD));
    const bn = barXs.length;
    const next = xs[si + 1];
    const own = level(t.params[3]!);
    // The next column's level nearest this item's, as a line from note to note would go.
    const nextLevels = next === undefined ? [own] : (levelsAt.get(`${t.params[1]}:${next}`) ?? [own]);
    const nextLevel = nextLevels.reduce((a, b) => (Math.abs(b - own) < Math.abs(a - own) ? b : a));
    const line = t.params[0] === TEXT ? (nextOnLine(t) ?? t) : null;
    return {
      ...spread,
      ...paramVars(t.params),
      id: t.key,
      i,
      n,
      t: n > 1 ? i / (n - 1) : 0,
      si,
      sn,
      st: sn > 1 ? si / (sn - 1) : 0,
      bar,
      bi,
      bn,
      bt: bn > 1 ? bi / (bn - 1) : 0,
      next_x: line ? line.params[2]! : next === undefined ? t.params[2]! : next * CHORD,
      next_level: line ? level(line.params[3]!) : nextLevel,
      left: (xs[0] ?? 0) * CHORD,
      right: (xs.at(-1) ?? 0) * CHORD,
      chord_low: Math.min(...chord),
      chord_high: Math.max(...chord),
      chord_size: chord.length,
      count: list.length,
    };
  });
}

// ---------------------------------------------------------------------------
// Settings by name

export interface Named {
  /** As the side panel shows it: "Stem", "Start level". */
  name: string;
  setting: Exclude<Setting, { kind: 'pair' }>;
  /** Shown only when this holds. */
  when?: (p: P) => boolean;
}

/**
 * The settings of a code under their names: pairs as "Start level", "Shift
 * up". A name can stand for several settings shown in turn (a slur's or a
 * bracket's Height).
 */
export function namedSettings(code: number): Map<string, Named[]> {
  const named = new Map<string, Named[]>();
  const add = (entry: Named) => named.set(plain(entry.name), [...(named.get(plain(entry.name)) ?? []), entry]);
  for (const section of sectionsFor(code)) {
    for (const setting of section.settings) {
      if (setting.kind === 'pair') {
        for (const field of setting.fields) add({ name: `${setting.label} ${field.label}`, setting: field, when: setting.when ?? field.when });
      } else add({ name: setting.label, setting, when: setting.when });
    }
  }
  return named;
}

const SETTINGS = new Map<number, Map<string, Named[]>>();

function settingsOf(code: number, name: string): Named[] {
  if (!SETTINGS.has(code)) SETTINGS.set(code, namedSettings(code));
  return SETTINGS.get(code)!.get(plain(name)) ?? [];
}

/** The setting called `name` that an item shows, if any; of alternatives "A | B", the first it shows. */
function applicable(code: number, name: string, p: P): Named | null {
  for (const alternative of alternatives(name)) {
    const found = settingsOf(code, alternative).find((n) => (!n.when || n.when(p)) && (!n.setting.when || n.setting.when(p)));
    if (found) return found;
  }
  return null;
}

const alternatives = (name: string) => name.split('|').map((n) => n.trim());

/** The option whose name is `wanted`, or begins with it, or contains it. */
export function optionNamed(options: { value: number; label: string }[], wanted: string): number | null {
  const w = plain(wanted);
  if (!w) return null;
  const found =
    options.find((o) => plain(o.label) === w) ??
    options.find((o) => plain(o.label).startsWith(w)) ??
    options.find((o) => plain(o.label).includes(w));
  return found?.value ?? null;
}

const ON = new Set(['on', 'yes', 'true', '1']);
const OFF = new Set(['off', 'no', 'false', '0', 'none']);

/** The changes a setting step makes to one item, or null where it does not apply. */
function settingChanges(named: Named, value: Value | boolean, p: P, ctx: Context, vars: Vars, compiled: () => Compiled): Change[] | null {
  const { setting } = named;
  switch (setting.kind) {
    case 'toggle': {
      const word = String(value).toLowerCase();
      const on = typeof value === 'boolean' ? value : ON.has(word) ? true : OFF.has(word) ? false : null;
      return on === null ? null : setting.set(on, p);
    }
    case 'choice': {
      const chosen = typeof value === 'string' ? optionNamed(setting.options, value) : null;
      const number = chosen ?? (typeof value === 'boolean' ? null : compiled()({ ...vars, value: setting.get(p) }));
      return number === null || !Number.isFinite(number) ? null : setting.set(number, p);
    }
    case 'number': {
      if (typeof value === 'boolean') return null;
      const number = compiled()({ ...vars, value: (setting as NumberSetting).get(p) });
      return Number.isFinite(number) ? (setting as NumberSetting).set(number, p) : null;
    }
    case 'text':
      return setting.parse(String(value), p, ctx);
  }
}

// ---------------------------------------------------------------------------
// Running

/** The P3 span and staves of some items, as group commands take an area: "bottom left right top". */
function area(list: Target[], region: Region | null): string | null {
  if (list.length === 0) {
    return region ? `${region.bottom} ${region.from} ${region.to} ${region.top}` : null;
  }
  const staves = list.map((t) => t.params[1]!);
  const xs = list.map((t) => t.params[2]!);
  const pad = 0.5;
  return `${Math.min(...staves)} ${Math.max(0, Math.min(...xs) - pad)} ${Math.min(200, Math.max(...xs) + pad)} ${Math.max(...staves)}`;
}

function ensureSemicolon(text: string | null | undefined): string {
  const t = (text ?? '').trim();
  return t.endsWith(';') ? t : `${t};`;
}

/** Runs one step; returns the identities of the items it changed or made. */
function runStep(step: Step, access: Access, scope: Scope, knobs: Vars): number[] {
  const editor = access.editor;
  const knobValue = (v: Value | null | undefined) => (v === null || v === undefined ? 0 : valueOf(v)(knobs));
  switch (step.do) {
    case 'set': {
      const list = targets(access, scope, step.items, knobs);
      const value = valueOf(step.value);
      const vars = placeVars(access, list);
      const mean = list.reduce((sum, t) => sum + (t.params[step.param - 1] ?? 0), 0) / (list.length || 1);
      const edits: [number, [number, number][]][] = [];
      list.forEach((t, k) => {
        const v = value({ ...knobs, ...vars[k]!, mean, value: t.params[step.param - 1] ?? 0 });
        if (Number.isFinite(v)) edits.push([t.index, [[step.param, v]]]);
      });
      if (edits.length) editor.setParamsOf(edits);
      return list.map((t) => t.key);
    }
    case 'setting': {
      const list = targets(access, scope, step.items, knobs);
      const vars = placeVars(access, list);
      let compiled: Compiled | null = null;
      const lazy = () => (compiled ??= valueOf(typeof step.value === 'boolean' ? Number(step.value) : step.value));
      const edits: [number, [number, number][]][] = [];
      const touched: number[] = [];
      list.forEach((t, k) => {
        const p: P = (n) => t.params[n - 1] ?? 0;
        const named = applicable(t.params[0]!, step.setting, p);
        if (!named) return;
        const changes = settingChanges(named, step.value, p, access.context(t.index), { ...knobs, ...vars[k]! }, lazy);
        if (!changes?.length) return;
        edits.push([t.index, changes]);
        touched.push(t.key);
      });
      if (edits.length === 0 && list.length > 0) {
        const codes = [...new Set(list.map((t) => t.params[0]!))];
        const names = alternatives(step.setting);
        if (!codes.some((code) => names.some((name) => settingsOf(code, name).length > 0))) throw new Error(`No setting “${names[0]}” for these items`);
      }
      if (edits.length) editor.setParamsOf(edits);
      return touched;
    }
    case 'move': {
      const list = targets(access, scope, step.items, knobs);
      const [right, up] = [knobValue(step.right), knobValue(step.up)];
      if (list.length === 0 || (!right && !up)) return [];
      editor.select(list.map((t) => t.index));
      editor.moveSelection(right, up);
      return list.map((t) => t.key);
    }
    case 'delete': {
      const list = targets(access, scope, step.items, knobs);
      if (list.length === 0) return [];
      editor.select(list.map((t) => t.index));
      editor.deleteSelection();
      return [];
    }
    case 'command': {
      const list = targets(access, scope, step.items, knobs);
      // A group command (FLN …) starts with nothing selected and is given the items' area.
      editor.select(access.groupCommand(step.line) ? [] : list.map((t) => t.index));
      execute(editor, step.line);
      if (editor.prompt() !== null) {
        const answer = area(list, scope.region);
        if (answer) execute(editor, answer, step.line);
        if (editor.prompt() !== null) {
          editor.execute('X');
          throw new Error(`${step.line} asks for more than the area`);
        }
      }
      return list.map((t) => t.key);
    }
    case 'insert': {
      const region = scope.region;
      const staff = step.staff ?? region?.staff;
      if (staff === undefined) throw new Error('Select the staff the music goes on');
      const from = step.from ?? region?.from ?? 10;
      const to = step.to ?? region?.to ?? 190;
      const rhythms = step.rhythms?.replace(/;$/, '').trim() ? step.rhythms : quartersFor(step.notes);
      const passes = [step.notes, rhythms, step.marks, step.beams, step.slurs].map(ensureSemicolon);
      const line = access.inputLine(passes, Math.round(staff), Math.min(from, to), Math.max(from, to));
      try {
        editor.select([]);
        editor.insertInput(line);
      } finally {
        line.free();
      }
      const keys = editor.keys();
      return editor.selection().map((i) => keys[i]!);
    }
    case 'beam':
      return beam(access, targets(access, scope, step.items, knobs), Math.round(knobValue(step.size)));
    case 'select':
      return targets(access, scope, step.items, knobs).map((t) => t.key);
    case 'add': {
      const { list, vars } = picked(access, scope, step.items, knobs);
      const values = step.params.map(valueOf);
      // Every new item's numbers first: making items sorts the file.
      const rows = list
        .map((_, k) => values.map((value) => Math.round(value({ ...knobs, ...vars[k]! }) * 1e4) / 1e4))
        .filter((params) => params[0] !== 0);
      const made: number[] = [];
      for (const params of rows) {
        // A new item comes selected, and numbers typed then would change it.
        editor.select([]);
        if (params[0] === TEXT) {
          if (!step.text) throw new Error('A new text needs its characters');
          editor.insertText(step.text, params.slice(1, TEXT_PARAMS));
        } else {
          const line = params.join(' ');
          editor.execute(line);
          if (editor.prompt() !== null) {
            editor.execute('X');
            throw new Error(`No item from ${line}`);
          }
        }
        const keys = editor.keys();
        made.push(...editor.selection().map((i) => keys[i]!));
      }
      return made;
    }
  }
}

/**
 * Beams over runs of `size` chords on each staff (0: every run up to a
 * barline): the beams there go, new ones are made over the runs, and the
 * engine's refit (FLN) fits stems, beams and flags to them.
 */
function beam(access: Access, list: Target[], size: number): number[] {
  const editor = access.editor;
  const notes = list.filter(beamable);
  if (notes.length === 0 && list.some((t) => t.params[0] === NOTE)) throw new Error('Only notes shorter than a quarter take beams');
  const byStaff = new Map<number, Target[]>();
  notes.forEach((t) => byStaff.set(t.params[1]!, [...(byStaff.get(t.params[1]!) ?? []), t]));
  const made: number[] = [];
  for (const [staff, staffNotes] of byStaff) {
    const xs = staffNotes.map((t) => t.params[2]!);
    const [left, right] = [Math.min(...xs), Math.max(...xs)];
    // Chords left to right; a barline between two of them ends a run.
    const chords: Target[][] = [];
    [...staffNotes].sort((a, b) => a.params[2]! - b.params[2]!).forEach((t) => {
      const last = chords.at(-1);
      if (last && Math.abs(last[0]!.params[2]! - t.params[2]!) < CHORD) last.push(t);
      else chords.push([t]);
    });
    const all = editor.keys().map((_, i) => access.params(i));
    const bars = all.flatMap((p) => (p && p[0] === BARLINE && p[1] === staff ? [p[2]!] : []));
    const runs: Target[][][] = [[]];
    chords.forEach((chord, k) => {
      const previous = chords[k - 1];
      const barred = previous && bars.some((x) => x > previous[0]!.params[2]! + CHORD && x < chord[0]!.params[2]! - CHORD);
      if (barred) runs.push([]);
      runs.at(-1)!.push(chord);
    });
    const groups = runs.flatMap((run) => {
      if (size <= 0) return [run];
      const cut: Target[][][] = [];
      for (let k = 0; k < run.length; k += size) cut.push(run.slice(k, k + size));
      return cut;
    });
    // Beams already over these notes go.
    const old = all.flatMap((p, i) => (p && p[0] === BEAM && p[1] === staff && p[5]! >= left - CHORD && p[2]! <= right + CHORD ? [i] : []));
    if (old.length) {
      editor.select(old);
      editor.deleteSelection();
    }
    // Beamed notes need stems: stemless ones get one, and the refit turns it the normal way.
    const stemless = groups
      .filter((g) => g.length > 1)
      .flat(2)
      .filter((t) => Math.floor(Math.abs(t.params[4]!) / 10 + 1e-6) % 10 === 0);
    if (stemless.length) {
      // Indices as they are now: deletions and an earlier staff's refit (which sorts the file) move items.
      const at = keyIndex(editor);
      editor.setParamsOf(stemless.flatMap((t) => (at.has(t.key) ? [[at.get(t.key)!, [[5, t.params[4]! + (t.params[4]! < 0 ? -10 : 10)]]] as [number, [number, number][]]] : [])));
    }
    for (const group of groups) {
      if (group.length < 2) continue;
      const first = group[0]![0]!.params;
      const last = group.at(-1)![0]!.params;
      editor.select([]);
      editor.execute(`6 ${staff} ${first[2]} ${level(first[3]!)} ${level(last[3]!)} ${last[2]} 1`);
      const keys = editor.keys();
      made.push(...editor.selection().map((i) => keys[i]!));
    }
    editor.select([]);
    editor.execute('FLN');
    if (editor.prompt() !== null) execute(editor, `${staff} ${Math.max(0, left - 0.5)} ${Math.min(200, right + 0.5)} ${staff}`, 'Beams cannot be fitted here');
    if (editor.prompt() !== null) editor.execute('X');
  }
  return [...notes.map((t) => t.key), ...made];
}

export function knobValues(script: Script, overrides: Record<string, number> = {}): Vars {
  return Object.fromEntries(script.knobs.map((k) => [k.id, overrides[k.id] ?? k.value]));
}

/**
 * Runs `script` on the real score as one undo step called `label`. On an
 * error nothing stays changed and the error is thrown on.
 */
export function run(script: Script, access: Access, scope: Scope, label: string, knobs: Vars = knobValues(script)): Ran {
  const editor = access.editor;
  const mark = editor.mark();
  const before = editor.selection();
  const touched: number[] = [];
  let within = scope;
  try {
    for (const step of script.steps) {
      const keys = runStep(step, access, within, knobs);
      if (step.do === 'select') within = { ...within, keys };
      touched.push(...keys);
    }
  } catch (err) {
    editor.rollback(mark);
    editor.select(before);
    throw err;
  }
  const changed = editor.combine(mark, label);
  const at = keyIndex(editor);
  const still = [...new Set(touched)].filter((key) => at.has(key));
  editor.select(still.map((key) => at.get(key)!));
  return { mark, changed, touched: still };
}

/** How many of the command's items the first step that picks items would act on. */
export function reach(script: Script, access: Access, scope: Scope): { count: number; codes: number[] } {
  const knobs = knobValues(script);
  const step = script.steps.find((s): s is Exclude<Step, { do: 'insert' }> => s.do !== 'insert');
  if (!step) return { count: 0, codes: [] };
  const list = targets(access, scope, step.items, knobs).filter((t) => step.do !== 'beam' || beamable(t));
  return { count: list.length, codes: [...new Set(list.map((t) => t.params[0]!))] };
}

/** Whether a script picks a new selection, which is done even though nothing changed. */
export function selects(script: Script): boolean {
  return script.steps.some((s) => s.do === 'select');
}

/** Whether a script only changes parameters, so a slider can redraw just the items it changed. */
export function onlyParams(script: Script): boolean {
  return script.steps.every((s) => s.do === 'set' || s.do === 'setting' || s.do === 'move');
}
