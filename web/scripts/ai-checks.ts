// Checks of the AI command's parts that need no browser: expressions, the
// values lifted from a command, the scripts intents make, and scripts run on
// a score through score-web. Run by scripts/ai-check.mjs.
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { initSync, InputLine, Score } from '../src/wasm/score_web.js';
import { scoreEditor } from '../src/editor';
import { compile } from '../src/ai-expr';
import { musicIn, numbersIn, quartersFor } from '../src/ai-values';
import { scriptFor } from '../src/ai-intent';
import { run, type Access, type Scope, type Script } from '../src/ai-script';
import { SCRIPT_SCHEMA } from '../src/ai-models';

initSync({ module: readFileSync(process.env.SCORE_WASM!) });

// Expressions.
assert.equal(compile('1 + (to - 1) * t ^ curve')({ to: 3, t: 0.5, curve: 2 }), 1.5);
assert.equal(compile('-2^2')({}), -4);
assert.equal(compile('value == 0 ? 1 : value')({ value: 0 }), 1);
assert.equal(compile('clamp(lerp(0, 10, t), 2, 8)')({ t: 0.95 }), 8);
assert.equal(compile('t == 1 && p2 >= 1')({ t: 1, p2: 1 }), 1);
assert.throws(() => compile('1 +')({}), /ends too early/);
assert.throws(() => compile('nope + 1')({}), /Unknown name nope/);
assert.equal(compile('false || TRUE')({}), 1);

// Values lifted from commands.
assert.deepEqual(numbersIn('size 1.5, move up 2 steps, 50%'), [1.5, 2, 0.5]);
assert.equal(musicIn('add notes c g d/f/a')?.notes, 'PC5/G/D:F:A');
assert.equal(musicIn('add notes c g d/f/a')?.typed, 'c g d/f/a');
assert.equal(musicIn('put f#4 bb4 r e4')?.notes, 'FS4/BF4/R/E4');
assert.equal(musicIn('add c e g', 22)?.notes, 'PC3/E/G', 'a bass staff starts low');
assert.equal(musicIn('add a fermata'), null);
assert.equal(musicIn('add c e g as eighths')?.notes, 'PC5/E/G', '"as" is a word');
assert.equal(musicIn('add fis4 bes gn4')?.notes, 'FS4/BF/GN4');
assert.equal(musicIn('remove the stems'), null);
assert.equal(quartersFor('PC5/G/M/D:F:A;'), '4/4/4');

// Claude's schema: structured output allows few union-typed fields (16) and
// wants every object closed with all its fields required.
function schemaFaults(node: unknown, path = '$'): string[] {
  if (!node || typeof node !== 'object') return [];
  const o = node as Record<string, unknown>;
  const faults: string[] = [];
  if ('anyOf' in o || Array.isArray(o.type)) faults.push(`${path}: a union`);
  if (o.type === 'object') {
    const keys = Object.keys((o.properties ?? {}) as object).sort();
    if (o.additionalProperties !== false) faults.push(`${path}: open`);
    if (JSON.stringify([...((o.required ?? []) as string[])].sort()) !== JSON.stringify(keys)) faults.push(`${path}: not all required`);
  }
  for (const [k, v] of Object.entries(o)) faults.push(...schemaFaults(v, `${path}.${k}`));
  return faults;
}
assert.deepEqual(schemaFaults(SCRIPT_SCHEMA), []);

// Intents as scripts.
assert.deepEqual(scriptFor({ action: 'delete', target: 'stems' }).steps, [{ do: 'setting', items: { codes: [1], where: null }, setting: 'Stem', value: 'None' }]);
const staccatos = scriptFor({ action: 'delete', target: 'notes', setting: 'Mark', option: 'Staccato' });
assert.equal(staccatos.steps[0]!.do, 'setting', 'the mark goes, not the notes');
assert.equal(scriptFor({ action: 'delete', target: 'notes', setting: 'Value', option: 'Eighth' }).steps[0]!.do, 'delete');
assert.deepEqual(scriptFor({ action: 'beam', target: 'notes', amount: 2 }).knobs.map((k) => [k.id, k.value]), [['size', 2]]);
assert.deepEqual(scriptFor({ action: 'grow', target: 'notes' }).knobs.map((k) => k.id), ['from', 'to', 'curve']);
assert.equal(scriptFor({ action: 'move', target: 'notes', direction: 'down', amount: 7 }).knobs[0]!.value, -7);

// Scripts on a score: eight eighths C5 … C6 on staff 1.
const score = Score.empty();
const editor = scoreEditor(score);
const access: Access = {
  editor,
  params(index) {
    const info = score.item(index);
    if (!info) return null;
    const params = info.params;
    info.free();
    return params;
  },
  context: () => ({ clef: null, symbolName: () => null }),
  staves: () => score.staffGeometry(),
  summaries: () => score.itemSummaries(),
  inputLine: (passes, staff, from, to) => new InputLine(passes, staff, from, to),
};
/** Parameter n of an item, to four places (they are single precision). */
const p = (index: number, n: number) => Math.round((access.params(index)![n - 1] ?? 0) * 1e4) / 1e4;
const region = { staff: 1, bottom: 1, top: 1, from: 10, to: 190 };
const added = run({ summary: 'add', knobs: [], steps: [{ do: 'insert', notes: 'C5/D/E/F/G/A/B/C6', rhythms: '8/8/8/8/8/8/8/8' }] }, access, { keys: [], region }, '“add”');
assert.equal(score.itemCount(), 9);
assert.equal(added.touched.length, 9, 'the staff and the notes are new');
const notes: Scope = { keys: editor.keys().slice(1), region };

const stems = run(scriptFor({ action: 'delete', target: 'stems' }), access, notes, '“remove the stems”');
assert.ok(stems.changed);
assert.equal(editor.undoLabel(), '“remove the stems”');
for (let i = 1; i <= 8; i++) assert.equal(Math.floor(p(i, 5) / 10) % 10, 0, `note ${i} has no stem`);

// A knob re-does the same step: rolled back and run again.
const grow = scriptFor({ action: 'grow', target: 'notes' });
const grown = run(grow, access, notes, '“grow”');
assert.deepEqual([p(1, 15), p(8, 15)], [1, 1.8]);
editor.rollback(grown.mark);
run(grow, access, notes, '“grow”', { from: 1, to: 3, curve: 1 });
assert.deepEqual([p(1, 15), p(8, 15)], [1, 3]);
assert.equal(editor.undoLabel(), '“grow”');
assert.equal(editor.mark(), grown.mark + 1, 'one undo step');

// Beams in pairs give the stemless notes stems again and take their flags.
run(scriptFor({ action: 'beam', target: 'notes', amount: 2 }), access, notes, '“beam”');
const items = () => editor.keys().map((_, i) => access.params(i)!);
assert.equal(items().filter((q) => q[0] === 6).length, 4);
for (const q of items().filter((q) => q[0] === 1)) {
  assert.notEqual(Math.floor(q[4]! / 10) % 10, 0, 'a stem');
  assert.equal(q[8]! % 10, 0, 'no flag under a beam');
}

// Where filters see an item's place: the last note only.
const last: Script = { summary: 'x head', knobs: [], steps: [{ do: 'setting', items: { codes: [1], where: 't == 1' }, setting: 'Head', value: 'X' }] };
run(last, access, notes, '“x head”');
const heads = items().filter((q) => q[0] === 1).map((q) => q[5]);
assert.deepEqual(heads, [0, 0, 0, 0, 0, 0, 0, 6]);

// Extremes over the items: the highest note only, an octave up.
const levels = () => items().filter((q) => q[0] === 1).map((q) => q[3]);
const top = Math.max(...levels());
run({ summary: 'raise', knobs: [], steps: [{ do: 'move', items: { codes: [1], where: 'level == max_level' }, up: 7 }] }, access, notes, '“raise”');
assert.deepEqual(levels().filter((l) => l !== undefined && l > top), [top + 7]);

// A selection: nothing changes, and the steps after it act on what it picked.
const unchanged = score.save().join();
const picked = run({ summary: 'pick', knobs: [], steps: [{ do: 'select', items: { codes: [1], where: 'level == max_level' } }] }, access, notes, '“pick”');
assert.equal(picked.changed, false);
assert.equal(score.save().join(), unchanged);
assert.deepEqual(editor.selection().map((i) => p(i, 4)), [top + 7]);
run({ summary: 'pick and accent', knobs: [], steps: [{ do: 'select', items: { codes: [1], where: 'i < 2' } }, { do: 'setting', items: null, setting: 'Mark', value: 'Accent' }] }, access, notes, '“accent”');
assert.equal(editor.selection().length, 2);
assert.equal(items().filter((q) => q[0] === 1 && Math.trunc(Math.abs(q[10] ?? 0)) === 5).length, 2, 'only the two picked are accented');

// Chords: the notes at one place on a staff; and means over the items.
const dyads = Score.empty();
const dyadEditor = scoreEditor(dyads);
const dyadAccess: Access = { ...access, editor: dyadEditor, params: (index) => {
  const info = dyads.item(index);
  if (!info) return null;
  const params = info.params;
  info.free();
  return params;
}, staves: () => dyads.staffGeometry(), summaries: () => dyads.itemSummaries() };
run({ summary: 'add', knobs: [], steps: [{ do: 'insert', notes: 'C4:E/D:F/E', rhythms: '4/4/4' }] }, dyadAccess, { keys: [], region }, '“add”');
const all: Scope = { keys: dyadEditor.keys().slice(1), region };
const bottoms = run({ summary: 'bottoms', knobs: [], steps: [{ do: 'select', items: { codes: [1], where: 'level == chord_low && chord_size > 1' } }] }, dyadAccess, all, '“bottoms”');
assert.equal(bottoms.touched.length, 2, 'the bottom notes of the two chords, not the lone E');
const low = run({ summary: 'low', knobs: [], steps: [{ do: 'select', items: { codes: [1], where: 'level < mean_level' } }] }, dyadAccess, all, '“low”');
assert.equal(low.touched.length, 2, 'C and D are below the mean');

// A failing step leaves nothing changed.
const before = score.save().join();
const depth = editor.mark();
assert.throws(() => run({ summary: 'bad', knobs: [], steps: [{ do: 'setting', items: null, setting: 'Size', value: 2 }, { do: 'setting', items: null, setting: 'Nonsense', value: 1 }] }, access, notes, '“bad”'), /No setting/);
assert.equal(score.save().join(), before);
assert.equal(editor.mark(), depth);

console.log('ai checks: ok');
