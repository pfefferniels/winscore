// Commands Jev leaves to Claude, through the real Claude API on mozart.mus:
// each script Claude writes is run on the score and its effect checked, then
// undone. Needs CLAUDE_API_KEY (or ANTHROPIC_API_KEY).
//
// usage: npm run wasm && npm run eval:claude    (CLAUDE_MODEL=claude-haiku-5-5)
import { readFileSync } from 'node:fs';
import { codeName, editWords, initSync, InputLine, Score } from '../src/wasm/score_web.js';
import { scoreEditor } from '../src/editor';
import { askClaude, type About, type Catalog } from '../src/ai-models';
import { run, type Access, type Region, type Scope } from '../src/ai-script';

initSync({ module: readFileSync(process.env.SCORE_WASM!) });
const key = process.env.CLAUDE_API_KEY || process.env.ANTHROPIC_API_KEY;
if (!key) throw new Error('CLAUDE_API_KEY is not set');
const connection = { key, baseURL: undefined, model: process.env.CLAUDE_MODEL ?? 'claude-opus-5-5' };
const catalog: Catalog = {
  codes: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 17, 18].map((code) => ({ code, name: codeName(code) ?? `Code ${code}` })),
  words: JSON.parse(editWords()) as Catalog['words'],
};

/** Items of mozart.mus by index: the melody (staff 8) and the bass (staff 7) of the first bars. */
const MELODY = [317, 318, 320, 321, 322, 324, 325, 326, 327, 329];
const BASS = [266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276];

type Params = Map<number, Float32Array>;
interface Case {
  text: string;
  /** Item indices in mozart.mus, or null for an empty score with a region on staff 1. */
  items: number[] | null;
  /** What must hold of the items before and after, by identity; a message when it does not. */
  check(before: Params, after: Params): string | null;
}

const notes = (m: Params) => [...m].filter(([, p]) => p[0] === 1).sort((a, b) => a[1][2]! - b[1][2]!);
const mark = (p: Float32Array) => Math.trunc(Math.abs(p[10] ?? 0) + 1e-6);

const CASES: Case[] = [
  {
    text: 'make the last note an x head',
    items: MELODY,
    check(before, after) {
      const all = notes(before);
      const [lastKey] = all.at(-1)!;
      if (after.get(lastKey)?.[5] !== 6) return 'the last note has no X head';
      const others = all.slice(0, -1).filter(([k, p]) => after.get(k)?.[5] !== p[5]);
      return others.length ? `${others.length} other notes changed head` : null;
    },
  },
  {
    text: 'accent every other note',
    items: MELODY,
    check(before, after) {
      const pattern = notes(before).map(([k]) => (mark(after.get(k)!) === 5 ? 'A' : '.')).join('');
      return /^(A\.)+A?$|^(\.A)+\.?$/.test(pattern) ? null : `accents ${pattern}`;
    },
  },
  {
    text: 'raise the highest note by an octave',
    items: MELODY,
    check(before, after) {
      const all = notes(before);
      const top = all.reduce((a, b) => (b[1][3]! > a[1][3]! ? b : a));
      if (after.get(top[0])![3] !== top[1][3]! + 7) return `the highest note went from ${top[1][3]} to ${after.get(top[0])![3]}`;
      const moved = all.filter(([k, p]) => k !== top[0] && after.get(k)![3] !== p[3]);
      return moved.length ? `${moved.length} other notes moved` : null;
    },
  },
  {
    text: 'delete the eighth notes',
    items: [...MELODY, ...BASS],
    check(before, after) {
      const eighths = notes(before).filter(([, p]) => Math.abs(p[6]! - 0.5) < 1e-4);
      const kept = eighths.filter(([k]) => after.has(k));
      const others = notes(before).filter(([, p]) => Math.abs(p[6]! - 0.5) >= 1e-4 && p[6]! < 64);
      const lost = others.filter(([k]) => !after.has(k));
      return kept.length || lost.length ? `${kept.length} eighths kept, ${lost.length} other notes deleted` : null;
    },
  },
  {
    text: 'make the slur flatter',
    items: MELODY,
    check(before, after) {
      const [k, p] = [...before].find(([, q]) => q[0] === 5)!;
      const q = after.get(k)!;
      const flatter = Math.abs(q[6]!) < Math.abs(p[6]!) || (q[8] ?? 0) !== (p[8] ?? 0);
      return flatter ? null : `curvature ${p[6]} → ${q[6]}, flattening ${p[8] ?? 0} → ${q[8] ?? 0}`;
    },
  },
  {
    text: 'make the first note of the bar bigger',
    items: BASS,
    check(before, after) {
      const all = notes(before);
      const [firstKey] = all[0]!;
      const size = after.get(firstKey)![14] ?? 0;
      if (!(size > 1)) return `the first note's size is ${size}`;
      const others = all.slice(1).filter(([k, p]) => (after.get(k)![14] ?? 0) !== (p[14] ?? 0));
      return others.length ? `${others.length} other notes changed size` : null;
    },
  },
  {
    text: 'add a c major arpeggio in eighths, up and back down',
    items: null,
    check(before, after) {
      const added = notes(after).filter(([k]) => !before.has(k));
      if (added.length < 5) return `${added.length} notes added`;
      const values = new Set(added.map(([, p]) => p[6]));
      return values.size === 1 && values.has(0.5) ? null : `values ${[...values].join(', ')}`;
    },
  },
];

function setUp(items: number[] | null) {
  const score = items ? new Score(readFileSync(`${process.env.SCORE_SAMPLES}/mozart.mus`)) : Score.empty();
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
  const keys = editor.keys();
  const region: Region = { staff: 1, bottom: 1, top: 1, from: 20, to: 180 };
  const scope: Scope = items ? { keys: items.map((i) => keys[i]!), region: null } : { keys: [], region };
  /** The scope's items (or, for an empty score, every item), by identity. */
  const snapshot = (): Params => {
    const now = editor.keys();
    const wanted = items ? new Set(scope.keys) : null;
    return new Map(now.flatMap((k, i) => (!wanted || wanted.has(k) ? [[k, access.params(i)!] as const] : [])));
  };
  return { score, editor, access, scope, snapshot };
}

/** One case's line of the report. */
async function evaluate(c: Case): Promise<string> {
  const { access, scope, snapshot } = setUp(c.items);
  const counts = new Map<number, number>();
  const sample: number[][] = [];
  for (const p of snapshot().values()) {
    counts.set(p[0]!, (counts.get(p[0]!) ?? 0) + 1);
    sample.push(Array.from(p));
  }
  const bars = new Map<number, number[]>();
  const staves = new Set(sample.map((p) => p[1]!));
  for (let i = 0; i < access.editor.keys().length; i++) {
    const p = access.params(i)!;
    if (p[0] === 14 && staves.has(p[1]!)) bars.set(p[1]!, [...(bars.get(p[1]!) ?? []), p[2]!].sort((a, b) => a - b));
  }
  const about: About = { text: c.text, counts, whole: false, region: scope.region, middle: 34, sample, bars, codeName: (code) => codeName(code) ?? `Code ${code}` };
  try {
    const { script, ms } = await askClaude(about, catalog, connection, new AbortController().signal);
    const before = snapshot();
    run(script, access, scope, `“${c.text}”`);
    const problem = c.check(before, snapshot());
    return `${problem ? 'FAIL' : 'ok  '} ${(ms / 1000).toFixed(1)} s "${c.text}" → ${script.summary} ${JSON.stringify(script.steps)}${script.knobs.length ? ` knobs ${script.knobs.map((k) => `${k.id}=${k.value}`).join(', ')}` : ''}${problem ? `\n       ${problem}` : ''}`;
  } catch (err) {
    return `ERR  "${c.text}": ${err instanceof Error ? err.message : String(err)}`;
  }
}

// CLAUDE_LIMIT=1 asks one at a time, as the app does: the system prompt is then cached after the first.
const limit = Number(process.env.CLAUDE_LIMIT ?? CASES.length);
const results: string[] = [];
let next = 0;
await Promise.all(Array.from({ length: limit }, async () => {
  while (next < CASES.length) {
    const i = next++;
    results[i] = await evaluate(CASES[i]!);
  }
}));
console.log(results.join('\n'));
console.log(`claude eval: ${results.filter((r) => r.startsWith('ok')).length}/${CASES.length} with ${connection.model}`);
