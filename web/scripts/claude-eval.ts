// Commands Jev leaves to Claude, through the real Claude API on mozart.mus:
// each script Claude writes is run on the score and its effect checked, then
// undone. Needs CLAUDE_API_KEY (or ANTHROPIC_API_KEY).
//
// usage: npm run wasm && npm run eval:claude    (CLAUDE_MODEL=claude-opus-5-5 CLAUDE_EFFORT=medium)
import { readFileSync } from 'node:fs';
import { codeName, editWords, groupCommand, initSync, InputLine, Score } from '../src/wasm/score_web.js';
import { scoreEditor } from '../src/editor';
import { askClaude, type About, type Catalog, type Failed, type Sampled, type Writer } from '../src/ai-models';
import { barlines, run, type Access, type Region, type Scope, type Script } from '../src/ai-script';

initSync({ module: readFileSync(process.env.SCORE_WASM!) });
const key = process.env.CLAUDE_API_KEY || process.env.ANTHROPIC_API_KEY;
if (!key) throw new Error('CLAUDE_API_KEY is not set');
const writer: Writer = { model: process.env.CLAUDE_MODEL ?? 'claude-sonnet-5-5', effort: (process.env.CLAUDE_EFFORT as Writer['effort']) ?? 'low' };
const connection = { key, baseURL: undefined, model: writer.model, complexModel: writer.model };
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
  /** Music put on the empty score first (passes 1 and 2), whose notes the command is then about. */
  music?: [string, string];
  /** Lyrics under that music: a syllable centred under each note, a "-" between the syllables around it. */
  lyrics?: string;
  /** The check sees every item of the score, not only those the command is about. */
  all?: boolean;
  /** What must hold of the items before and after, and of the selection after, by identity; a message when it does not. */
  check(before: Params, after: Params, selected: number[], text: (key: number) => string | null): string | null;
  /** The command cannot be done: it must fail with this message, changing nothing. */
  refused?: RegExp;
}

const notes = (m: Params) => [...m].filter(([, p]) => p[0] === 1).sort((a, b) => a[1][2]! - b[1][2]!);
const mark = (p: Float32Array) => Math.trunc(Math.abs(p[10] ?? 0) + 1e-6);
const beams = (m: Params) => [...m.values()].filter((p) => p[0] === 6).length;
/** The texts of the items, left to right: their characters, where they begin and end. */
const texts = (m: Params, text: (key: number) => string | null) =>
  [...m].filter(([, p]) => p[0] === 16).map(([k, p]) => ({ k, text: text(k) ?? '', x: p[2]!, end: p[2]! + p[12]! })).sort((a, b) => a.x - b.x);

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
    text: 'make lower notes start big and gradually get smaller',
    items: null,
    music: ['C4:E/D:F/E:G/F:A', '4/4/4/4'],
    check(before, after) {
      const chords = new Map<number, [number, Float32Array][]>();
      for (const [k, p] of notes(before)) chords.set(Math.round(p[2]!), [...(chords.get(Math.round(p[2]!)) ?? []), [k, p]]);
      const columns = [...chords.values()].map((c) => c.sort((a, b) => a[1][3]! - b[1][3]!));
      const size = (k: number) => after.get(k)![14] || 1;
      const lower = columns.map((c) => size(c[0]![0]));
      const upper = columns.map((c) => size(c[1]![0]));
      const shrinking = lower.every((s, i) => i === 0 || s < lower[i - 1]!) && lower[0]! > 1;
      return shrinking && upper.every((s) => s === 1) ? null : `lower ${lower.join(' ')}, upper ${upper.join(' ')}`;
    },
  },
  {
    text: 'select only lower voice',
    items: null,
    music: ['C4:E/D:F/E:G/F:A', '4/4/4/4'],
    check(before, after, selected) {
      const columns = new Map<number, [number, Float32Array][]>();
      for (const [k, p] of notes(before)) columns.set(Math.round(p[2]!), [...(columns.get(Math.round(p[2]!)) ?? []), [k, p]]);
      const lower = [...columns.values()].map((c) => c.sort((a, b) => a[1][3]! - b[1][3]!)[0]![0]).sort();
      const changed = [...before].filter(([k, p]) => after.get(k)?.join() !== p.join()).length;
      const picked = [...selected].sort();
      return picked.join() === lower.join() && !changed ? null : `selected ${picked.length} (${picked.filter((k) => !lower.includes(k)).length} not lower), ${changed} changed`;
    },
  },
  {
    text: 'beam',
    items: null,
    music: ['C4:E/D:F/E:G/F:A', '8/8/8/8'],
    check: (before, after) => (beams(after) - beams(before) >= 1 ? null : 'no beam'),
  },
  {
    text: 'beam those',
    items: null,
    music: ['C5/D/E/F/G/A/B/C', '8/8/8/8/8/8/8/8'],
    check: (before, after) => (beams(after) - beams(before) >= 1 ? null : 'no beam'),
  },
  {
    text: 'beam them',
    items: null,
    music: ['C4:E/D:F/E:G/F:A', '4/4/4/4'],
    check: () => null,
    refused: /quarter/i,
  },
  {
    text: 'add lines from note head to note head',
    items: null,
    music: ['C5/E/G/B4/D5', '8/8/8/8/8'],
    check(before, after) {
      const heads = notes(before).map(([, p]) => p);
      const lines = [...after].filter(([k, p]) => !before.has(k) && p[0] === 4).map(([, p]) => p).sort((a, b) => a[2]! - b[2]!);
      if (lines.length !== heads.length - 1) return `${lines.length} lines for ${heads.length} notes`;
      const off = lines.filter((l, i) => l[3] !== heads[i]![3] || l[4] !== heads[i + 1]![3]);
      return off.length ? `${off.length} lines miss their notes: ${lines.map((l) => Array.from(l.slice(0, 6)).join(' ')).join('; ')}` : null;
    },
  },
  {
    text: 'add staff above',
    items: [312],
    all: true,
    check(before, after) {
      const staves = [...after].filter(([k, p]) => !before.has(k) && p[0] === 8).map(([, p]) => p[1]);
      return staves.length === 1 && staves[0] === 9 ? null : `new staves: ${staves.join(', ') || 'none'}`;
    },
  },
  {
    text: 'add missing "-" for lyrics',
    items: null,
    music: ['A4/G/A/C5/B4/A/G/A', '4/4/4/4/4/4/4/4'],
    lyrics: 'O splen - di dis si ma gem - ma',
    check(before, after, _selected, text) {
      const made = texts(after, text).filter((t) => !before.has(t.k));
      if (made.some((t) => t.text !== '_00-')) return `made ${made.map((t) => JSON.stringify(t.text)).join(' ')}`;
      const syllables = texts(after, text).filter((t) => !t.text.endsWith('-'));
      const between = made.map((h) => {
        const [last, next] = [syllables.filter((s) => s.end <= h.x + 0.5).at(-1), syllables.find((s) => s.x >= h.end - 0.5)];
        const centred = last && next && Math.abs((h.x + h.end) / 2 - (last.end + next.x) / 2) < 1;
        return `${last?.text.slice(3)}-${next?.text.slice(3)}${centred ? '' : ' (off centre)'}`;
      });
      return between.join(' ') === 'di-dis dis-si si-ma' ? null : `hyphens ${between.join(' ') || 'none'}`;
    },
  },
  // Complex: what Jev sends to the model for complex commands.
  {
    text: 'double the melody a third below',
    items: MELODY,
    all: true,
    check(before, after) {
      // The melody's notes: those on its staff before its barline.
      const melody = notes(before).filter(([, p]) => p[1] === 8 && p[2]! < 90);
      const added = notes(after).filter(([k]) => !before.has(k));
      if (added.length !== melody.length) return `${added.length} notes added for ${melody.length}`;
      const off = melody.filter(([, p]) => !added.some(([, q]) => q[1] === p[1] && Math.abs(q[2]! - p[2]!) < 0.6 && q[3] === p[3]! - 2));
      return off.length ? `${off.length} notes without a third below` : null;
    },
  },
  {
    text: 'retrograde the melody',
    items: MELODY,
    check(before, after) {
      const levels = (m: Params) => notes(m).map(([, p]) => p[3]);
      const want = levels(before).reverse().join(' ');
      return levels(after).join(' ') === want ? null : `levels ${levels(after).join(' ')}, expected ${want}`;
    },
  },
  {
    text: 'invert the melody around its first note',
    items: MELODY,
    check(before, after) {
      const all = notes(before);
      const axis = all[0]![1][3]!;
      const want = all.map(([, p]) => 2 * axis - p[3]!).join(' ');
      const got = all.map(([k]) => after.get(k)?.[3]).join(' ');
      return got === want ? null : `levels ${got}, expected ${want}`;
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

function setUp(items: number[] | null, music?: [string, string], lyrics?: string, all = false) {
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
    summaries: () => score.itemSummaries(),
    groupCommand,
    inputLine: (passes, staff, from, to) => new InputLine(passes, staff, from, to),
  };
  const region: Region = { staff: 1, bottom: 1, top: 1, from: 20, to: 180 };
  if (music) run({ summary: 'music', knobs: [], steps: [{ do: 'insert', notes: music[0], rhythms: music[1] }] }, access, { keys: [], region }, 'music');
  /** Characters of the text item `key`. */
  const text = (key: number) => {
    const info = score.item(editor.keys().indexOf(key));
    const characters = info?.text ?? null;
    info?.free();
    return characters;
  };
  if (lyrics) {
    const heads = editor.keys().flatMap((_, i) => (access.params(i)![0] === 1 ? [access.params(i)![2]!] : [])).sort((a, b) => a - b);
    const words = lyrics.split(' ');
    // Half a note head right of P3, as CTN centres text on a note.
    words.filter((w) => w !== '-').forEach((w, i) => editor.insertText(w, [1, 1000 + heads[i]! + 1.6, -5]));
    const sung = texts(new Map(editor.keys().map((k, i) => [k, access.params(i)!])), text);
    words.forEach((w, i) => {
      if (w !== '-') return;
      const syllable = words.slice(0, i).filter((v) => v !== '-').length;
      editor.insertText('-', [1, 1000 + (sung[syllable - 1]!.end + sung[syllable]!.x) / 2, -5]);
    });
  }
  const keys = editor.keys();
  const scope: Scope = items ? { keys: items.map((i) => keys[i]!), region: null } : music ? { keys: keys.slice(1), region } : { keys: [], region };
  /** The scope's items (or, for an empty score, every item), by identity; every item for a check that sees `all`. */
  const itemsOf = (whole: boolean): Params => {
    const now = editor.keys();
    const wanted = items && !whole ? new Set(scope.keys) : null;
    return new Map(now.flatMap((k, i) => (!wanted || wanted.has(k) ? [[k, access.params(i)!] as const] : [])));
  };
  const inScope = () => itemsOf(false);
  const snapshot = () => itemsOf(all);
  const selected = () => editor.selection().map((i) => editor.keys()[i]!);
  return { score, editor, access, scope, inScope, snapshot, selected, text };
}

/** One case's line of the report. */
async function evaluate(c: Case): Promise<string> {
  const { access, scope, inScope, snapshot, selected, text } = setUp(c.items, c.music, c.lyrics, c.all);
  const counts = new Map<number, number>();
  const sample: Sampled[] = [];
  for (const [id, p] of inScope()) {
    counts.set(p[0]!, (counts.get(p[0]!) ?? 0) + 1);
    sample.push({ id, params: Array.from(p), text: text(id) });
  }
  const staves = new Set(sample.map(({ params }) => params[1]!));
  const bars = new Map([...barlines(access)].filter(([staff]) => staves.has(staff)));
  const about: About = { text: c.text, counts, whole: false, region: scope.region, middle: 34, sample, bars, codeName: (code) => codeName(code) ?? `Code ${code}` };
  let written: Script | null = null;
  const before = snapshot();
  try {
    // As the app does: a script that fails to run goes back to Claude once, with why.
    let failed: Failed | undefined;
    let asked = await askClaude(about, catalog, connection, writer, new AbortController().signal);
    written = asked.script;
    try {
      run(asked.script, access, scope, `“${c.text}”`);
    } catch (err) {
      failed = { answer: asked.answer, error: err instanceof Error ? err.message : String(err) };
      asked = await askClaude(about, catalog, connection, writer, new AbortController().signal, failed);
      written = asked.script;
      run(asked.script, access, scope, `“${c.text}”`);
    }
    const { script, ms } = asked;
    if (c.refused) return `FAIL "${c.text}" was not refused → ${JSON.stringify(script.steps)}`;
    const problem = c.check(before, snapshot(), selected(), text);
    return `${problem ? 'FAIL' : 'ok  '} ${(ms / 1000).toFixed(1)} s "${c.text}" → ${script.summary} ${JSON.stringify(script.steps)}${script.knobs.length ? ` knobs ${script.knobs.map((k) => `${k.id}=${k.value}`).join(', ')}` : ''}${problem ? `\n       ${problem}` : ''}`;
  } catch (err) {
    const message = err instanceof Error ? err.message : String(err);
    const unchanged = [...before].every(([k, p]) => snapshot().get(k)?.join() === p.join());
    if (c.refused?.test(message) && unchanged) return `ok   "${c.text}" refused: ${message}`;
    return `ERR  "${c.text}": ${message}${written ? ` in ${JSON.stringify(written.steps)}` : ''}`;
  }
}

// CLAUDE_LIMIT=1 asks one at a time, as the app does: the system prompt is then cached after the first.
// CLAUDE_CASES=lower,arpeggio runs only the cases whose command has one of these words.
const only = process.env.CLAUDE_CASES?.split(',');
const CHOSEN = only ? CASES.filter((c) => only.some((w) => c.text.includes(w))) : CASES;
const limit = Number(process.env.CLAUDE_LIMIT ?? CHOSEN.length);
const results: string[] = [];
let next = 0;
await Promise.all(Array.from({ length: limit }, async () => {
  while (next < CHOSEN.length) {
    const i = next++;
    results[i] = await evaluate(CHOSEN[i]!);
  }
}));
console.log(results.join('\n'));
console.log(`claude eval: ${results.filter((r) => r.startsWith('ok')).length}/${CHOSEN.length} with ${writer.model} at ${writer.effort} effort`);
