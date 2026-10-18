// Checks of the AI command's parts that need no browser: expressions, the
// values lifted from a command, the scripts intents make, and scripts run on
// a score through score-web. Run by scripts/ai-check.mjs.
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { groupCommand, initSync, InputLine, Score } from '../src/wasm/score_web.js';
import { scoreEditor } from '../src/editor';
import { compile } from '../src/ai-expr';
import { musicIn, namesCount, numbersIn, quartersFor } from '../src/ai-values';
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
assert.deepEqual(numbersIn('8th beam in 4s, size 2.'), [2], 'ordinals and plurals are not numbers');
assert.equal(musicIn('add notes c g d/f/a')?.notes, 'PC5/G/D:F:A');
assert.equal(musicIn('add notes c g d/f/a')?.typed, 'c g d/f/a');
assert.equal(musicIn('put f#4 bb4 r e4')?.notes, 'FS4/BF4/R/E4');
assert.equal(musicIn('add c e g', 22)?.notes, 'PC3/E/G', 'a bass staff starts low');
assert.equal(musicIn('add a fermata'), null);
assert.equal(musicIn('add c e g as eighths')?.notes, 'PC5/E/G', '"as" is a word');
assert.equal(musicIn('add fis4 bes gn4')?.notes, 'FS4/BF/GN4');
assert.equal(musicIn('remove the stems'), null);
assert.equal(quartersFor('PC5/G/M/D:F:A;'), '4/4/4');
assert.deepEqual(['beam them', '8th beam', 'beam the eighths', 'beam in pairs', 'beam always 2 notes', 'groups of four', 'beam in eights', 'beam in 4s'].map(namesCount), [false, false, false, true, true, true, true, true]);

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
  groupCommand,
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

// A group command (FLN) on the selected notes: run with nothing selected, given their area.
const auto = run(scriptFor({ action: 'stems-auto', target: 'notes' }), access, notes, '“add stems”');
for (let i = 1; i <= 8; i++) assert.notEqual(Math.floor(p(i, 5) / 10) % 10, 0, `note ${i} has a stem again`);
editor.rollback(auto.mark);

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

// New items made from each picked one: a line from each note to the next, none after the last.
const lines = run({ summary: 'lines', knobs: [], steps: [{ do: 'add', items: { codes: [1], where: 'si < sn - 1' }, params: ['4', 'staff', 'x + 1.5', 'level', 'next_level', 'next_x'] }] }, access, notes, '“lines”');
const made = items().filter((q) => q[0] === 4);
assert.equal(made.length, 7);
assert.equal(lines.touched.length, 7);
const noteRows = items().filter((q) => q[0] === 1).sort((a, b) => a[2]! - b[2]!);
assert.deepEqual([made[0]![3], made[0]![4], made[0]![5]], [noteRows[0]![3], noteRows[1]![3], noteRows[1]![2]], 'from the first note to the second');
editor.rollback(lines.mark);

// New texts: a hyphen centred between a syllable picked by its identity and the next one on its
// line, past a text above the staff.
const sung = Score.empty();
const sungEditor = scoreEditor(sung);
const sungAccess: Access = { ...access, editor: sungEditor, params: (index) => {
  const info = sung.item(index);
  if (!info) return null;
  const params = info.params;
  info.free();
  return params;
}, staves: () => sung.staffGeometry(), summaries: () => sung.itemSummaries() };
run({ summary: 'add', knobs: [], steps: [{ do: 'insert', notes: 'C5/D/E', rhythms: '4/4/4' }] }, sungAccess, { keys: [], region }, '“add”');
for (const [syllable, x, level] of [['splen', 40, -5], ['di', 80, -5], ['dolce', 100, 13], ['dis', 120, -5]] as const) sungEditor.insertText(syllable, [1, 1000 + x, level]);
const texts = () => sungEditor.keys().flatMap((key, i) => {
  const info = sung.item(i)!;
  const [code, , x = 0, level = 0] = info.params;
  const text = { key, text: info.text ?? '', x, end: x + (info.params[12] ?? 0), level };
  info.free();
  return code === 16 ? [text] : [];
});
const syllable = (s: string) => texts().find((t) => t.text === `_00${s}`)!;
const hyphens: Script = { summary: 'hyphens', knobs: [], steps: [{ do: 'add', items: { codes: [16], where: `id == ${syllable('di').key}` }, params: ['16', 'staff', '1000 + (x + p13 + next_x) / 2', 'p4'], text: '-' }] };
const hyphened = run(hyphens, sungAccess, { keys: sungEditor.keys(), region }, '“hyphens”');
assert.equal(hyphened.touched.length, 1, 'one hyphen, after di only');
const hyphen = texts().find((t) => t.key === hyphened.touched[0])!;
assert.equal(hyphen.text, '_00-');
assert.equal(hyphen.level, -5);
const gap = (syllable('di').end + syllable('dis').x) / 2;
assert.ok(Math.abs((hyphen.x + hyphen.end) / 2 - gap) < 0.01, `the hyphen is centred on ${gap}, not ${(hyphen.x + hyphen.end) / 2}`);
sungEditor.rollback(hyphened.mark);
assert.throws(() => run({ ...hyphens, steps: [{ ...hyphens.steps[0]!, text: null } as Script['steps'][number]] }, sungAccess, { keys: sungEditor.keys(), region }, '“hyphens”'), /needs its characters/);
assert.equal(texts().length, 4, 'nothing made');

// A refit the engine gives up on (chords with two stems) leaves no half-made beam: the step fails, nothing changes.
const twoStems = Score.empty();
const twoEditor = scoreEditor(twoStems);
const twoAccess: Access = { ...access, editor: twoEditor, params: (index) => {
  const info = twoStems.item(index);
  if (!info) return null;
  const params = info.params;
  info.free();
  return params;
}, staves: () => twoStems.staffGeometry(), summaries: () => twoStems.itemSummaries() };
run({ summary: 'add', knobs: [], steps: [{ do: 'insert', notes: 'C4:E:G/D:F:A', rhythms: '8/8' }] }, twoAccess, { keys: [], region }, '“add”');
const chordNotes: Scope = { keys: twoEditor.keys().slice(1), region };
run({ summary: 'stems', knobs: [], steps: [{ do: 'setting', items: { codes: [1] }, setting: 'Stem', value: 'Up' }] }, twoAccess, chordNotes, '“stems”');
const unbeamed = twoStems.save().join();
assert.throws(() => run(scriptFor({ action: 'beam', target: 'notes' }), twoAccess, chordNotes, '“beam”'), /Beams cannot be fitted here \(staff 1: .*two stems/);
assert.equal(twoStems.save().join(), unbeamed);

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

// Two actions chained ("8th beam"): the value first, so the beam finds short notes.
const chain = scriptFor({ action: 'beam', target: 'notes', amount: 2, then: { action: 'option', target: 'notes', setting: 'Value', option: 'Eighth' } });
assert.deepEqual(chain.steps.map((step) => step.do), ['setting', 'beam']);
const chained = run(chain, dyadAccess, all, '“8th beam”');
const dyadItems = () => dyadEditor.keys().map((_, i) => dyadAccess.params(i)!);
assert.equal(dyadItems().filter((q) => q[0] === 6).length, 1, 'one beam over the first two chords');
assert.ok(dyadItems().filter((q) => q[0] === 1).every((q) => q[6] === 0.5), 'all eighths');
dyadEditor.rollback(chained.mark);
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
