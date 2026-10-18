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

// A failing step leaves nothing changed.
const before = score.save().join();
const depth = editor.mark();
assert.throws(() => run({ summary: 'bad', knobs: [], steps: [{ do: 'setting', items: null, setting: 'Size', value: 2 }, { do: 'setting', items: null, setting: 'Nonsense', value: 1 }] }, access, notes, '“bad”'), /No setting/);
assert.equal(score.save().join(), before);
assert.equal(editor.mark(), depth);

// "Bigger" reaches every kind: notes by their Size, slurs by their
// curvature, hairpins by their opening, lines by their thickness, boxes in
// width and height.
for (const name of ['mozart.mus', '000.mus']) {
  const sample = new Score(readFileSync(`${process.env.SCORE_SAMPLES}/${name}`));
  const sampleAccess: Access = { ...access, editor: scoreEditor(sample), params(index) {
    const info = sample.item(index);
    if (!info) return null;
    const params = info.params;
    info.free();
    return params;
  } };
  const all = Array.from({ length: sample.itemCount() }, (_, i) => sampleAccess.params(i)!);
  const first = (test: (q: Float32Array | number[]) => boolean) => all.findIndex(test);
  const picked = [
    first((q) => q[0] === 1),
    first((q) => q[0] === 5 && (q[7] ?? 0) === 0 && (q[6] ?? 0) !== 0),
    first((q) => q[0] === 4 && q[4] === 999 && ![0, -1].includes(q[6] ?? 0)),
    first((q) => q[0] === 4 && q[4] !== 999),
    first((q) => q[0] === 12 && [0, 1, 3].includes(q[4] ?? 0) && (q[5] ?? 0) !== 0 && (q[6] ?? 0) !== 0),
  ].filter((i) => i >= 0);
  const keys = sampleAccess.editor.keys();
  const q = (i: number, n: number) => Math.round((sampleAccess.params(i)![n - 1] ?? 0) * 100) / 100;
  const before = picked.map((i) => [all[i]![0], q(i, 5), q(i, 6), q(i, 7), q(i, 10), q(i, 15)]);
  run(scriptFor({ action: 'bigger', target: 'all', amount: 2 }), sampleAccess, { keys: picked.map((i) => keys[i]!), region }, '“bigger”');
  for (const [k, i] of picked.entries()) {
    const [code, p5, p6, p7, p10, p15] = before[k]!;
    const was = (v: number) => Math.round((v === 0 ? 1 : v) * 2 * 100) / 100;
    if (code === 1) assert.equal(q(i, 15), was(p15!), `${name}: a note's size`);
    if (code === 5) assert.equal(q(i, 7), was(p7!), `${name}: a slur's curvature`);
    if (code === 4 && p5 === 999) assert.equal(q(i, 7), Math.sign(p7!) * was(Math.abs(p7!)), `${name}: a hairpin's opening`);
    if (code === 4 && p5 !== 999) assert.equal(q(i, 10), was(p10!), `${name}: a line's thickness`);
    if (code === 12) assert.deepEqual([q(i, 6), q(i, 7)], [was(p6!), was(p7!)], `${name}: a box's width and height`);
  }
  sample.free();
}

console.log('ai checks: ok');
