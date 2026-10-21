// Checks of the AI command's parts that need no browser: expressions, the
// values lifted from a command, the scripts intents make, and scripts run on
// a score through score-web. Run by scripts/ai-check.mjs.
import assert from 'node:assert/strict';
import { readFileSync } from 'node:fs';
import { groupCommand, initSync, InputLine, Score } from '../src/wasm/score_web.js';
import { scoreEditor } from '../src/editor';
import { compile } from '../src/ai-expr';
import { barsIn, fingeringsIn, halfStepsIn, intervalHalfSteps, keyTonic, meterIn, musicIn, namesCount, numbersIn, numberWords, octavesIn, pitchesIn, quartersFor, quotedIn, recipeNotes, sequenceIn, tonicIn, tonicOctave, type Recipe } from '../src/ai-values';
import { scriptFor, type Intent } from '../src/ai-intent';
import { run, syllables, type Access, type Scope, type Script } from '../src/ai-script';
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
// Values typed with the notes: after them all, after each, one for all; else none.
assert.deepEqual(['add c e g 4 8 8', 'add c e g as 4 8. 16', 'add c 4 d 8 e 8', 'add c e g 8', 'add c d | e f 2 4 4 1', 'add c e g as eighths', 'add c e g and move up 2', 'add c5 e g c6 4 8 8 2 | d5 f a d6 8 8 4 2', 'add c d 8 | e f'].map((t) => musicIn(t)?.rhythms), ['4/8/8', '4/8./16', '4/8/8', '8/8/8', '2/4/4/1', undefined, undefined, '4/8/8/2/8/8/4/2', '8/8/4/4']);
assert.equal(musicIn('add c5 e g c6 4 8 8 2 | d5 f a d6 8 8 4 2')?.notes, 'C5/E/G/C6/M/D5/F/A/D6');
assert.equal(musicIn('add c 4 d 8 e 8')?.notes, 'PC5/D/E');
assert.equal(musicIn('add c e g 4 8 8')?.typed, 'c e g 4 8 8');
assert.equal(musicIn('add c4 e4 g4')?.rhythms, undefined, 'octaves are not values');
assert.deepEqual(numbersIn('move up two steps, every other one'), [2], 'spelt numbers, not "one"');
assert.deepEqual(numbersIn('repeat twice, then thrice'), [2, 3]);
assert.deepEqual(numberWords('add 3/4 time'), [], 'a meter is no amount');
assert.deepEqual(meterIn('add 3/4 time'), [3, 4]);
assert.deepEqual(['accent bar 3', 'stems up in bars 2 to 4', 'delete measures 5-3', 'the second bar', 'the 3rd measure', 'the first two bars', 'the last bar', 'the last 3 bars', 'add a barline', 'beam in pairs'].map((t) => barsIn(t) && { ...barsIn(t), phrase: undefined }), [
  { from: 3, to: 3, end: false, phrase: undefined }, { from: 2, to: 4, end: false, phrase: undefined }, { from: 3, to: 5, end: false, phrase: undefined }, { from: 2, to: 2, end: false, phrase: undefined }, { from: 3, to: 3, end: false, phrase: undefined },
  { from: 1, to: 2, end: false, phrase: undefined }, { from: 1, to: 1, end: true, phrase: undefined }, { from: 1, to: 3, end: true, phrase: undefined }, null, null,
]);
assert.deepEqual(meterIn('make it 12 / 8'), [12, 8]);
assert.equal(meterIn('add notes c/e g'), null);
assert.equal(quotedIn('add the text "Allegro"'), 'Allegro');
assert.equal(quotedIn('write “dolce” here'), 'dolce');
assert.equal(quotedIn('add a fermata'), null);
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
  text: () => null,
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
// Without a staff and without a place, the music makes staff 1.
const blank = Score.empty();
const blankAccess: Access = { ...access, editor: scoreEditor(blank), params: (index) => {
  const info = blank.item(index);
  if (!info) return null;
  const params = info.params;
  info.free();
  return params;
}, staves: () => blank.staffGeometry(), summaries: () => blank.itemSummaries() };
const written = run(scriptFor({ action: 'insert', target: 'all', notes: 'PC5/E/G', rhythms: '4/8/8' }), blankAccess, { keys: null, region: null }, '“add c e g 4 8 8”');
assert.equal(written.touched.length, 4, 'a staff and three notes');
assert.deepEqual(Array.from({ length: blank.itemCount() }, (_, i) => blankAccess.params(i)!).filter((q) => q[0] === 1).map((q) => q[6]), [1, 0.5, 0.5], 'a quarter and two eighths');

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

// Picks by place, selections, and new items placed by the notes: C5 D5 E5 F5 quarters on staff 1, stems down.
const fresh = () => {
  const score = Score.empty();
  const ed = scoreEditor(score);
  const acc: Access = { ...access, editor: ed, params: (index) => {
    const info = score.item(index);
    if (!info) return null;
    const params = info.params;
    info.free();
    return params;
  }, staves: () => score.staffGeometry(), summaries: () => score.itemSummaries() };
  run({ summary: 'add', knobs: [], steps: [{ do: 'insert', notes: 'C5/D/E/F', rhythms: '4/4/4/4' }] }, acc, { keys: [], region }, '“add”');
  const rows = () => ed.keys().map((_, i) => acc.params(i)!);
  const notes = () => rows().filter((q) => q[0] === 1).sort((a, b) => a[2]! - b[2]!);
  const keysOf = (n: number[]) => n.map((k) => ed.keys().find((_, i) => rows()[i]![0] === 1 && rows()[i]![2] === notes()[k]![2])!);
  return { score, ed, acc, rows, notes, scope: (...k: number[]): Scope => ({ keys: keysOf(k.length ? k : [0, 1, 2, 3]), region }) };
};
const four = fresh();
const xs = four.notes().map((q) => q[2]!);
const accentsOf = () => four.notes().map((q) => Math.trunc(Math.abs(q[10] ?? 0)) === 5);
let ran = run(scriptFor({ action: 'option', target: 'notes', setting: 'Mark', option: 'Accent', pick: 'every other' }), four.acc, four.scope(), '“accent every other note”');
assert.deepEqual(accentsOf(), [true, false, true, false]);
four.ed.rollback(ran.mark);
const firstFew = scriptFor({ action: 'option', target: 'notes', setting: 'Mark', option: 'Accent', pick: 'first few', many: 3 });
assert.deepEqual(firstFew.knobs.map((k) => [k.id, k.value]), [['many', 3]]);
ran = run(firstFew, four.acc, four.scope(), '“accent the first three”');
assert.deepEqual(accentsOf(), [true, true, true, false]);
const selected = run(scriptFor({ action: 'select', target: 'notes', setting: 'Mark', option: 'Accent' }), four.acc, four.scope(), '“select the accented notes”');
assert.equal(selected.touched.length, 3, 'the accented notes are selected');
assert.equal(selected.changed, false);
four.ed.rollback(ran.mark);
ran = run(scriptFor({ action: 'option', target: 'notes', setting: 'Mark', option: 'Accent', pick: 'highest' }), four.acc, four.scope(), '“accent the highest”');
assert.deepEqual(accentsOf(), [false, false, false, true]);
four.ed.rollback(ran.mark);

// Repeated: copies after the notes, a period on each (the stretch and the mean gap), pitches kept; drawn
// closer, alike, where they would run past the staff's end.
const period = ((xs[3]! - xs[0]!) * 4) / 3;
const near = (list: number[]) => list.map((x) => Math.round(x * 100) / 100);
// Added music takes the room its values take (four quarters, 44 spaces), not the rest of the staff.
assert.ok(xs[3]! - xs[0]! < 44, `four quarters from ${xs[0]} to ${xs[3]}`);
// Spread out about the first, then evenly from the first to the last.
ran = run(scriptFor({ action: 'spread', target: 'all', amount: 2 }), four.acc, four.scope(), '“spread out”');
assert.deepEqual(near(four.notes().map((q) => q[2]!)), near(xs.map((x) => xs[0]! + (x - xs[0]!) * 2)));
four.ed.rollback(ran.mark);
const uneven = run({ summary: 'move', knobs: [], steps: [{ do: 'move', items: { codes: [1], where: 'i == 1' }, right: 5 }] }, four.acc, four.scope(), '“move”');
ran = run(scriptFor({ action: 'evenly', target: 'all' }), four.acc, four.scope(), '“space evenly”');
assert.deepEqual(near(four.notes().map((q) => q[2]!)), near([0, 1, 2, 3].map((k) => xs[0]! + ((xs[3]! - xs[0]!) * k) / 3)));
four.ed.rollback(uneven.mark);
assert.throws(() => run(scriptFor({ action: 'spread', target: 'all', amount: 9 }), four.acc, four.scope(), '“spread”'), /no room on the staff to spread these so far/);
// The first two notes drawn apart: the two after them go along, as far as the stretch grew.
ran = run(scriptFor({ action: 'spread', target: 'all', amount: 2 }), four.acc, four.scope(0, 1), '“spread”');
const grew = xs[1]! - xs[0]!;
assert.deepEqual(near(four.notes().map((q) => q[2]!)), near([xs[0]!, xs[1]! + grew, xs[2]! + grew, xs[3]! + grew]));
four.ed.rollback(ran.mark);
for (const times of [2, 5]) {
  const reach = xs[3]! + times * period;
  const factor = reach > 198 ? (198 - xs[0]!) / (reach - xs[0]!) : 1;
  ran = run(scriptFor({ action: 'repeat', target: 'all', amount: times }), four.acc, four.scope(), '“repeat”');
  assert.deepEqual(near(four.notes().map((q) => q[2]!)), near(Array.from({ length: times + 1 }, (_, k) => xs.map((x) => xs[0]! + (x + k * period - xs[0]!) * factor)).flat()), `${times} times${factor < 1 ? ', drawn closer' : ''}`);
  assert.deepEqual(four.notes().map((q) => q[3]), Array.from({ length: times + 1 }, () => [8, 9, 10, 11]).flat(), 'C5 D5 E5 F5 again and again');
  assert.equal(ran.touched.length, 4 * (times + 1), 'the notes and their copies');
  four.ed.rollback(ran.mark);
}
// With room after them, as they were: the first two notes once more after the second.
ran = run(scriptFor({ action: 'repeat', target: 'all', amount: 1 }), four.acc, four.scope(0, 1), '“repeat”');
assert.deepEqual(near(four.notes().map((q) => q[2]!)).sort((a, b) => a - b), near([...xs, xs[0]! + 2 * (xs[1]! - xs[0]!), xs[1]! + 2 * (xs[1]! - xs[0]!)]).sort((a, b) => a - b));
four.ed.rollback(ran.mark);

// Bars by number: C5 D5 | E5 F5 | G5, bar 2 is E and F; the last bar is G; only the notes with a property.
const barred = fresh();
barred.ed.rollback(0);
const line = run({ summary: 'add', knobs: [], steps: [{ do: 'insert', notes: 'C5/D/M/E/F/M/G', rhythms: '4/4/4/4/4' }] }, barred.acc, { keys: [], region: { ...region, from: 10, to: 190 } }, '“add”');
const barredNotes = (): Scope => ({ keys: line.touched.filter((key) => barred.acc.params(barred.ed.keys().indexOf(key))![0] === 1), region });
const levelsPicked = (intent: Intent) => {
  const r = run(scriptFor(intent), barred.acc, barredNotes(), '“pick”');
  const levels = [...new Set(r.touched)].map((key) => barred.acc.params(barred.ed.keys().indexOf(key))![3]).sort((a, b) => a! - b!);
  barred.ed.rollback(r.mark);
  return levels;
};
assert.deepEqual(levelsPicked({ action: 'select', target: 'notes', bars: { from: 2, to: 2, end: false } }), [10, 11], 'E5 and F5, the second bar');
assert.deepEqual(levelsPicked({ action: 'select', target: 'notes', bars: { from: 1, to: 1, end: true } }), [12], 'G5, the last bar');
assert.deepEqual(levelsPicked({ action: 'select', target: 'notes', bars: { from: 1, to: 2, end: false }, pick: 'last' }), [11], 'the last note of bars 1 to 2');
assert.equal(scriptFor({ action: 'option', target: 'notes', setting: 'Mark', option: 'Accent', bars: { from: 2, to: 4, end: false } }).summary, 'Mark: Accent (bars 2 to 4)');
const accented = run(scriptFor({ action: 'option', target: 'notes', setting: 'Mark', option: 'Accent', pick: 'first' }), barred.acc, barredNotes(), '“accent the first”');
assert.deepEqual(levelsPicked({ action: 'select', target: 'notes', only: { setting: 'Mark', option: 'Accent' } }), [8], 'only the accented C5');
barred.ed.rollback(accented.mark);

// Marks in turn, pitches in turn, a text's new characters in its own font, lyrics under the notes.
assert.deepEqual(sequenceIn('staccato, accent, staccato', ['None', 'Accent', 'Staccato', 'Accent + staccato']), ['Staccato', 'Accent', 'Staccato']);
assert.equal(sequenceIn('accent and staccato', ['Accent', 'Staccato']), null, '"and" may mean both at once');
assert.deepEqual(fingeringsIn('fingering 1 2 3 1'), [1, 2, 3, 1]);
assert.deepEqual(pitchesIn('make them f# bb4 e'), ['F#', 'Bb4', 'E']);
assert.deepEqual(syllables('Ky-ri-e e-le-i-son'), [{ text: 'Ky', hyphen: true }, { text: 'ri', hyphen: true }, { text: 'e', hyphen: false }, { text: 'e', hyphen: true }, { text: 'le', hyphen: true }, { text: 'i', hyphen: true }, { text: 'son', hyphen: false }]);
ran = run(scriptFor({ action: 'option', target: 'notes', setting: 'Mark', option: 'Staccato', sequence: ['Staccato', 'Accent'] }), four.acc, four.scope(), '“staccato, accent”');
assert.deepEqual(four.notes().map((q) => Math.trunc(Math.abs(q[10] ?? 0))), [7, 5, 7, 5]);
four.ed.rollback(ran.mark);
ran = run(scriptFor({ action: 'change', target: 'notes', pitches: ['G4', 'A4'] }), four.acc, four.scope(), '“make them g4 a4”');
assert.deepEqual(four.notes().map((q) => q[3]), [5, 6, 5, 6], 'G4 A4 G4 A4');
four.ed.rollback(ran.mark);
const sungFour = run(scriptFor({ action: 'create', target: 'all', item: 'lyrics', text: 'Ky-ri-e e' }), four.acc, four.scope(), '“lyrics”');
const sungTexts = four.rows().filter((q) => q[0] === 16);
assert.equal(sungTexts.length, 6, 'four syllables and two hyphens');
assert.ok(sungTexts.every((q) => q[3] === -5), 'on the lyric line');
four.ed.rollback(sungFour.mark);
const titled = Score.empty();
const titledEditor = scoreEditor(titled);
titledEditor.insertText('_02dolce', [1, 50, 12]);
const titledAccess: Access = { ...access, editor: titledEditor, params: (i) => { const info = titled.item(i); const q = info?.params ?? null; info?.free(); return q; }, text: (i) => { const info = titled.item(i); const t = info?.text ?? null; info?.free(); return t; }, staves: () => titled.staffGeometry(), summaries: () => titled.itemSummaries() };
run(scriptFor({ action: 'change', target: 'text', text: 'espr.' }), titledAccess, { keys: titledEditor.keys(), region }, '“change the text”');
assert.equal(titledAccess.text(0), '_02espr.', 'in its own font');

// Transposed by SCORE's TR: up a major third, E F# G# A with E major's four sharps added; to D major from C, a whole step up.
assert.equal(intervalHalfSteps('third', 'minor'), 3);
assert.equal(intervalHalfSteps('fifth', 'diminished'), 6);
assert.deepEqual(['up a semitone', 'down 3 half steps', 'a whole step', 'move up 2 steps'].map(halfStepsIn), [1, 3, 2, null]);
ran = run(scriptFor({ action: 'transpose', target: 'all', amount: 4 }), four.acc, four.scope(), '“transpose up a major third”');
assert.deepEqual(four.notes().map((q) => q[3]), [10, 11, 12, 13], 'E5 F#5 G#5 A5');
assert.ok(four.rows().some((q) => q[0] === 17 && q[4] === 4), 'four sharps');
four.ed.rollback(ran.mark);
ran = run(scriptFor({ action: 'transpose', target: 'all', key: 2 }), four.acc, four.scope(), '“transpose to D major”');
assert.deepEqual(four.notes().map((q) => q[3]), [9, 10, 11, 12], 'D5 E5 F#5 G5');
four.ed.rollback(ran.mark);
ran = run(scriptFor({ action: 'transpose', target: 'all', key: 2, up: false }), four.acc, four.scope(), '“transpose down to D major”');
assert.deepEqual(four.notes().map((q) => q[3]), [2, 3, 4, 5], 'D4 E4 F#4 G4');
four.ed.rollback(ran.mark);

// A slur over the notes: from the first to the last, above the stems-down heads, each end off the lines.
const create = (intent: Omit<Intent, 'action' | 'target'>, scope: Scope, of = four) => run(scriptFor({ action: 'create', target: 'all', ...intent }), of.acc, scope, '“add”');
ran = create({ item: 'slur' }, four.scope());
const slur = four.rows().find((q) => q[0] === 5)!;
assert.deepEqual([slur[2], slur[5]], [xs[0], xs[3]], 'from the first note to the last');
assert.deepEqual([slur[3], slur[4], slur[6]], [10, 13, 3], 'C5 + 2, F5 + 2; curving up');
assert.equal(ran.touched.length, 1);
four.ed.rollback(ran.mark);
ran = create({ item: 'tie' }, four.scope(0));
const tie = four.rows().find((q) => q[0] === 5)!;
assert.deepEqual([tie[2], tie[5], tie[7]], [xs[0], xs[1], -2], 'one note: tied to the next');
four.ed.rollback(ran.mark);
// A barline between the second note and the third; a clef before the third, at its own place.
ran = create({ item: 'barline' }, four.scope(0, 1));
assert.equal(four.rows().find((q) => q[0] === 14)![2], (xs[1]! + xs[2]!) / 2);
four.ed.rollback(ran.mark);
ran = create({ item: 'bass clef' }, four.scope(2));
const clefs = four.rows().filter((q) => q[0] === 3);
assert.ok(clefs.some((q) => q[2] === (xs[1]! + xs[2]!) / 2 && q[4] === 1), 'a bass clef between the second note and the third');
four.ed.rollback(ran.mark);
// Over the notes on each staff, a hairpin; a key signature and a meter from their words; a number given.
ran = create({ item: 'crescendo' }, four.scope());
const hairpin = four.rows().find((q) => q[0] === 4)!;
assert.deepEqual([hairpin[2], hairpin[4], hairpin[5]], [xs[0], 999, xs[3]]);
four.ed.rollback(ran.mark);
ran = create({ item: 'key signature', word: 'KSIG-3' }, four.scope(0));
assert.equal(four.rows().find((q) => q[0] === 17 && q[4] === -3)?.[1], 1, 'three flats on staff 1');
four.ed.rollback(ran.mark);
ran = create({ item: 'meter', word: 'METER68' }, four.scope(0));
assert.deepEqual([...four.rows().find((q) => q[0] === 18 && q[4] === 6)!.slice(4, 6)], [6, 8]);
four.ed.rollback(ran.mark);
ran = create({ item: 'number', more: [0, 12] }, four.scope(1));
assert.deepEqual([four.rows().find((q) => q[0] === 10)![2], four.rows().find((q) => q[0] === 10)![4]], [xs[1], 12]);
four.ed.rollback(ran.mark);
// Where nothing is selected (the whole score), at the place clicked: a dynamic there; a text; a staff above the highest.
const place: Scope = { keys: null, region: { ...region, from: 150 } };
ran = create({ item: 'mf' }, place);
const mf = four.rows().filter((q) => q[0] === 9);
assert.deepEqual(mf.map((q) => [q[1], q[2], q[4]]), [[1, 150, 55]], 'one mf on staff 1 at 150');
four.ed.rollback(ran.mark);
ran = create({ item: 'text', text: 'Allegro' }, place);
assert.equal(four.rows().filter((q) => q[0] === 16).length, 1);
four.ed.rollback(ran.mark);
ran = create({ item: 'staff' }, place);
assert.deepEqual(four.rows().filter((q) => q[0] === 8).map((q) => q[1]), [1, 2]);
four.ed.rollback(ran.mark);
assert.throws(() => create({ item: 'barline' }, { keys: null, region: null }), /Click where it goes/);

// Scales and arpeggios written out by code, accidentals as the key signature in force leaves them to be written.
const recipe = (r: Partial<Recipe> & { tonic: Recipe['tonic'] }, sharps = 0) => recipeNotes({ kind: 'major', arpeggio: false, way: 'up', octaves: 1, ...r }, sharps);
const D4 = { letter: 1, accidental: 0, octave: 4 };
assert.equal(recipe({ tonic: D4 }), 'D4/E4/FS4/G4/A4/B4/CS5/D5');
assert.equal(recipe({ tonic: D4 }, 2), 'D4/E4/F4/G4/A4/B4/C5/D5', 'in D major, no sharps shown');
assert.equal(recipe({ tonic: { letter: 5, accidental: 0, octave: 4 }, kind: 'melodic minor', way: 'both' }), 'A4/B4/C5/D5/E5/FS5/GS5/A5/GN5/FN5/E5/D5/C5/B4/A4', 'down as the natural minor');
assert.equal(recipe({ tonic: { letter: 0, accidental: 0, octave: 4 }, arpeggio: true, way: 'both' }), 'C4/E4/G4/C5/G4/E4/C4');
assert.equal(recipe({ tonic: { letter: 4, accidental: 0, octave: 3 }, kind: 'dominant seventh', arpeggio: true }), 'G3/B3/D4/F4/G4');
assert.equal(recipe({ tonic: { letter: 6, accidental: -1, octave: 4 }, way: 'down' }), 'BF4/A4/G4/F4/EF4/D4/C4/BF3', 'down from the key note');
assert.equal(recipe({ tonic: { letter: 0, accidental: 0, octave: 4 }, kind: 'chromatic', way: 'both' }).split('/').slice(11, 16).join('/'), 'B4/C5/B4/BF4/AN4', 'sharps up, flats down');
assert.equal(recipe({ tonic: { letter: 0, accidental: 0, octave: 4 }, kind: 'major pentatonic', octaves: 2 }), 'C4/D4/E4/G4/A4/C5/D5/E5/G5/A5/C6');
assert.deepEqual(['add a c major scale', 'add a minor scale', 'an a minor scale', 'add an e flat arpeggio', 'a chromatic scale from F#', 'add a G7 arpeggio', 'add a c4 major scale'].map(tonicIn), [
  { letter: 0, accidental: 0 }, null, { letter: 5, accidental: 0 }, { letter: 2, accidental: -1 }, { letter: 3, accidental: 1 }, { letter: 4, accidental: 0 }, { letter: 0, accidental: 0, octave: 4 },
]);
assert.deepEqual(['two octaves of a g major scale', 'a scale over 3 octaves', 'a scale'].map(octavesIn), [2, 3, null]);
assert.deepEqual([keyTonic(2, false), keyTonic(-3, true), keyTonic(0, true)], [{ letter: 1, accidental: 0 }, { letter: 0, accidental: 0 }, { letter: 5, accidental: 0 }]);
assert.deepEqual([tonicOctave(0, 34, 'up', 1), tonicOctave(6, 34, 'up', 1), tonicOctave(0, 34, 'down', 1), tonicOctave(0, 22, 'up', 1)], [4, 3, 5, 3], 'below the middle line up, above it down');
const scaled = fresh();
const scale = scriptFor({ action: 'scale', target: 'all', scale: { tonic: { letter: 1, accidental: 0 }, kind: 'major', arpeggio: false, way: 'up', octaves: 1, value: '8', middle: 34 } });
assert.equal(scale.summary, 'Add a D major scale');
assert.deepEqual(scale.knobs.map((k) => [k.id, k.value]), [['octaves', 1]]);
ran = run(scale, scaled.acc, { keys: null, region: { ...region, from: 120, to: 190 } }, '“add a D major scale”');
const scaleNotes = scaled.notes().filter((q) => q[2]! >= 120);
assert.deepEqual(scaleNotes.map((q) => q[3]), [2, 3, 4, 5, 6, 7, 8, 9], 'D4 up to D5');
assert.deepEqual(scaleNotes.map((q) => q[6]), Array(8).fill(0.5), 'eighths');
assert.deepEqual(scaleNotes.map((q) => Math.abs(q[4]!) % 10), [0, 0, 2, 0, 0, 0, 2, 0], 'F♯ and C♯');
scaled.ed.rollback(ran.mark);
ran = run(scale, scaled.acc, { keys: null, region: { ...region, from: 100, to: 190 } }, '“add a D major scale”', { octaves: 2 });
assert.equal(scaled.notes().filter((q) => q[2]! >= 100).length, 15, 'two octaves');
scaled.ed.rollback(ran.mark);
assert.equal(scriptFor({ action: 'scale', target: 'all', scale: { kind: 'minor', arpeggio: true, way: 'both', octaves: 1, middle: 34 } }).summary, 'Add a minor arpeggio in the key, up and down');
// Without a key note, the key's: in a score with three flats, a minor scale is C minor, its flats not shown.
const flat = fresh();
flat.ed.select([]);
flat.ed.execute('KSIG-3');
ran = run(scriptFor({ action: 'scale', target: 'all', scale: { kind: 'minor', arpeggio: false, way: 'up', octaves: 1, middle: 34 } }), flat.acc, { keys: null, region: { ...region, from: 120 } }, '“add a minor scale”');
const cMinor = flat.notes().filter((q) => q[2]! >= 120);
assert.deepEqual(cMinor.map((q) => q[3]), [1, 2, 3, 4, 5, 6, 7, 8], 'C4 up to C5');
assert.ok(cMinor.every((q) => Math.abs(q[4]!) % 10 === 0), 'E♭, A♭ and B♭ from the key signature');

// Chords arpeggiated: C E G and D F A quarters become triplet eighths in their time, from the bottom, or from the top.
const chorded = fresh();
const arpeggio = (down: boolean) => {
  const before = chorded.ed.keys().length;
  const add = run({ summary: 'add', knobs: [], steps: [{ do: 'insert', notes: 'C4:E:G/D:F:A', rhythms: '4/4' }] }, chorded.acc, { keys: [], region: { ...region, from: 120, to: 160 } }, '“add”');
  const keys = chorded.ed.keys().slice(before);
  const xs = chorded.notes().filter((q) => q[2]! >= 120).map((q) => q[2]!);
  const r = run(scriptFor({ action: 'arpeggiate', target: 'chords', ...(down ? { up: false } : {}) }), chorded.acc, { keys, region: null }, '“arpeggiate”');
  const broken = chorded.notes().filter((q) => q[2]! >= 120);
  return { r, xs, broken, mark: add.mark };
};
let arp = arpeggio(false);
assert.deepEqual(arp.broken.map((q) => q[3]), [1, 3, 5, 2, 4, 6], 'C E G, D F A one after another');
assert.ok(arp.broken.every((q) => Math.abs(q[6]! - 1 / 3) < 1e-3), 'triplet eighths');
assert.equal(arp.broken[0]![2], Math.min(...arp.xs), 'from where the first chord was');
assert.ok(arp.broken[3]![2]! >= Math.max(...arp.xs) - 0.01, 'the second from where it was');
assert.equal(arp.r.touched.length, 6);
chorded.ed.rollback(arp.mark);
arp = arpeggio(true);
assert.deepEqual(arp.broken.map((q) => q[3]), [5, 3, 1, 6, 4, 2], 'from the top');
assert.throws(() => run(scriptFor({ action: 'arpeggiate', target: 'chords' }), four.acc, four.scope(), '“arpeggiate”'), /no chords/);

console.log('ai checks: ok');
