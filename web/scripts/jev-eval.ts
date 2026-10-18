// Commands through the real Jev, with the intent each should give: how well
// the questions read commands, and how fast. Needs TYPESAFE_API_KEY.
//
// usage: npm run wasm && npm run eval:jev    (JEV_MODEL=jev-preview, LIMIT=3 requests at a time)
import { askJev, TYPESAFE_URL, type About } from '../src/ai-models';
import { counted, scriptFor } from '../src/ai-intent';

/** Selections the commands are about: item counts by code. */
const SCOPES: Record<string, Map<number, number>> = {
  notes: new Map([[1, 8]]),
  mixed: new Map([[1, 14], [5, 2], [9, 2], [16, 1], [6, 2]]),
  empty: new Map(),
};

/** [selection, command, what the intent must hold]; action "(none)": Claude's to write. */
const CASES: [string, string, Record<string, unknown>][] = [
  ["notes", "remove the stems", {"action": "delete", "target": "stems"}],
  ["notes", "get rid of the stems", {"action": "delete", "target": "stems"}],
  ["notes", "no stems", {"action": "delete", "target": "stems"}],
  ["notes", "beam always 2 notes", {"action": "beam", "amount": 2}],
  ["notes", "beam in pairs", {"action": "beam", "amount": 2}],
  ["notes", "beam them in groups of four", {"action": "beam", "amount": 4}],
  ["notes", "beam them", {"action": "beam", "amount": undefined}],
  ["notes", "beam", {"action": "beam", "amount": undefined}],
  ["notes", "beam those", {"action": "beam", "amount": undefined}],
  ["notes", "beam in eights", {"action": "beam", "amount": 8}],
  ["notes", "break the beams", {"action": "unbeam"}],
  ["notes", "make note size gradually bigger", {"action": "grow", "measure": "size"}],
  ["notes", "notes growing from small to big", {"action": "grow"}],
  ["notes", "make them smaller", {"action": "smaller"}],
  ["notes", "make them 50% bigger", {"action": "bigger", "amount": 1.5}],
  ["notes", "add staccatos", {"action": "option", "setting": "Mark", "option": "Staccato"}],
  ["notes", "make them eighth notes", {"action": "option", "setting": "Value", "option": "Eighth"}],
  ["notes", "stems up", {"action": "stems-up"}],
  ["notes", "flip the stems", {"action": "flip"}],
  ["notes", "move up a third", {"action": "move", "direction": "up", "amount": 2}],
  ["notes", "transpose down an octave", {"action": "move", "direction": "down", "amount": 7}],
  ["notes", "move them 5 to the right", {"action": "move", "direction": "right", "amount": 5}],
  ["empty", "add notes c g d/f/a", {"action": "insert", "notes": "PC5/G/D:F:A"}],
  ["empty", "put e f# g here", {"action": "insert"}],
  ["notes", "sharpen them", {"action": "option", "setting": "Accidental", "option": "♯ Sharp"}],
  ["notes", "remove the accidentals", {"action": "delete", "target": "accidentals"}],
  ["notes", "remove the staccatos", {"action": "delete", "option": "Staccato"}],
  ["notes", "make them cue size", {"action": "option", "setting": "Cue size", "option": "on"}],
  ["notes", "x noteheads", {"action": "option", "setting": "Head", "option": "X"}],
  ["notes", "size 1.5", {"action": "number", "setting": "Size", "value": 1.5}],
  ["notes", "stem length 3", {"action": "number", "setting": "Stem length", "value": 3}],
  ["notes", "make the stems longer", {"action": "bigger", "measure": "stem length"}],
  ["mixed", "delete everything", {"action": "delete", "target": "all"}],
  ["mixed", "align the dynamics", {"action": "align", "target": "dynamics"}],
  ["mixed", "make the slurs dashed", {"action": "option", "setting": "Line", "option": "Dashed"}],
  ["mixed", "delete the slurs", {"action": "delete", "target": "slurs"}],
  ["mixed", "remove the stems", {"action": "delete", "target": "stems"}],
  ["notes", "make the last note an x head", {"action": "(none)"}],
  ["notes", "accent every other note", {"action": "(none)"}],
  ["notes", "lose the accidentals", {"action": "delete", "target": "accidentals"}],
  ["notes", "staccato everything", {"action": "option", "setting": "Mark", "option": "Staccato"}],
  ["notes", "put accents on them", {"action": "option", "setting": "Mark", "option": "Accent"}],
  ["mixed", "make the beams thicker", {"action": "bigger", "target": "beams", "measure": "thickness"}],
  ["notes", "transpose up a fifth", {"action": "move", "direction": "up", "amount": 4}],
  ["notes", "move down 2 steps", {"action": "move", "direction": "down", "amount": 2}],
  ["notes", "half notes please", {"action": "option", "setting": "Value", "option": "Half"}],
  ["notes", "make them grace notes", {"action": "option", "setting": "Value", "option": "Grace note"}],
  ["notes", "dot them", {"action": "option", "setting": "Dots", "option": "1"}],
  ["mixed", "remove all dynamics", {"action": "delete", "target": "dynamics"}],
  ["mixed", "make the text bigger", {"action": "bigger", "target": "text"}],
  ["notes", "shrink the notes gradually", {"action": "shrink"}],
  ["notes", "notes get smaller and smaller", {"action": "shrink"}],
  ["notes", "sizes from 1 to 3", {"action": "grow", "from": 1, "to": 3}],
  ["notes", "make the sizes go from 0.8 to 2", {"action": "grow", "from": 0.8, "to": 2}],
  ["notes", "beam in threes", {"action": "beam", "amount": 3}],
  ["notes", "stems down", {"action": "stems-down"}],
  ["notes", "automatic stems", {"action": "stems-auto"}],
  ["empty", "add c e g as eighths", {"action": "insert", "notes": "PC5/E/G", "rhythms": "8/8/8"}],
  ["notes", "double sharp", {"action": "option", "setting": "Accidental", "option": "♯♯ Double sharp"}],
  ["mixed", "make the slurs flatter", {"action": "(none)"}],
  ["notes", "delete the eighth notes", {"action": "(none)"}],
  ["notes", "make the first three notes red", {"action": "(none)"}],
  // Two actions at once, or a value given alongside a beam; the unsafe ones are Claude's.
  ["notes", "staccato and stems up", {"action": "option", "option": "Staccato", "then": {"action": "stems-up"}}],
  ["notes", "accent them and move up a step", {"then": {"action": "move"}}],
  ["notes", "make them eighths, then beam in pairs", {"then": {"action": "beam"}}],
  ["notes", "8th beam", {"action": "beam", "then": {"action": "option", "target": "notes", "setting": "Value", "option": "Eighth"}}],
  ["notes", "sixteenths beamed in fours", {"action": "beam", "amount": 4, "then": {"action": "option", "target": "notes", "setting": "Value", "option": "16th"}}],
  ["notes", "beam the eighths", {"then": undefined}],
  ["notes", "add staccatos and remove the stems", {"action": "(none)"}],
  // SCORE's layout commands in words.
  ["notes", "justify this system", {"action": "layout", "line": "LJ"}],
  ["notes", "line up and justify", {"action": "layout", "line": "LJ"}],
  ["notes", "space the notes properly", {"action": "layout", "line": "LJ"}],
  ["notes", "lay out the music", {"action": "layout", "line": "LJ"}],
  ["notes", "only line up the beats, don't justify", {"action": "layout", "line": "LI"}],
  ["notes", "just justify, without lining up", {"action": "layout", "line": "J"}],
  ["mixed", "line up and justify all staves at once", {"action": "layout", "line": "LJA"}],
];

const key = process.env.TYPESAFE_API_KEY;
if (!key) throw new Error('TYPESAFE_API_KEY is not set');
const connection = { url: TYPESAFE_URL, key, model: process.env.JEV_MODEL ?? 'jev-latest' };
const rows: string[] = [];
const times: number[] = [];
let passed = 0;
let next = 0;
// JEV_CASES=beam,stems runs only the cases whose command has one of these words.
const only = process.env.JEV_CASES?.split(',');
const CHOSEN = only ? CASES.filter(([, text]) => only.some((w) => text.includes(w))) : CASES;

/** Whether `got` has every field `expect` gives, objects field by field. */
function holds(got: unknown, expect: unknown): boolean {
  if (expect && typeof expect === 'object') {
    return !!got && typeof got === 'object' && Object.entries(expect).every(([k, v]) => holds((got as Record<string, unknown>)[k], v));
  }
  return JSON.stringify(got) === JSON.stringify(expect);
}

async function one(i: number) {
  const [scope, text, expect] = CHOSEN[i]!;
  const counts = SCOPES[scope]!;
  const about: About = {
    text,
    counts,
    whole: false,
    region: scope === 'empty' ? { staff: 1, bottom: 1, top: 1, from: 100, to: 180 } : null,
    middle: 34,
    sample: [],
    bars: new Map(),
    codeName: (code) => counted(code, 2).replace(/^2 /, ''),
  };
  try {
    const reading = await askJev(about, connection, new AbortController().signal);
    times.push(reading.ms);
    const got: Record<string, unknown> = reading.intent ? { ...reading.intent } : { action: '(none)', read: reading.action };
    const ok = holds(got, expect);
    if (ok) passed++;
    const summary = reading.intent ? ` | ${scriptFor(reading.intent).summary}` : '';
    rows[i] = `${ok ? 'ok  ' : 'FAIL'} ${String(Math.round(reading.ms)).padStart(4)} ms ${String(Math.round(reading.confidence * 100)).padStart(3)} % [${scope}] "${text}" → ${JSON.stringify(got)}${ok ? '' : `, expected ${JSON.stringify(expect)}`}${summary}`;
  } catch (err) {
    rows[i] = `ERR  [${scope}] "${text}": ${String(err)}`;
  }
}

await Promise.all(Array.from({ length: Number(process.env.LIMIT ?? 3) }, async () => {
  while (next < CHOSEN.length) await one(next++);
}));
times.sort((a, b) => a - b);
console.log(rows.join('\n'));
console.log(`jev eval: ${passed}/${CHOSEN.length}, median ${Math.round(times[times.length >> 1] ?? 0)} ms, p90 ${Math.round(times[Math.floor(times.length * 0.9)] ?? 0)} ms`);
