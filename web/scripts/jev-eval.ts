// Commands through the real Jev, with the intent each should give: how well
// the questions read commands, and how fast. Needs TYPESAFE_API_KEY.
//
// usage: npm run wasm && npm run eval:jev    (JEV_MODEL=jev-preview, LIMIT=3 requests at a time)
import { readFileSync } from 'node:fs';
import { askJev, TYPESAFE_URL, type About } from '../src/ai-models';
import { counted, scriptFor } from '../src/ai-intent';
import { appMenus, wordCommands, type MenuHooks } from '../src/menus';
import { commandSupported, initSync } from '../src/wasm/score_web.js';

initSync({ module: readFileSync(process.env.SCORE_WASM!) });

/** The editor's commands as the app offers them, a score open and items selected. */
const noop = () => {};
const hooks: MenuHooks = new Proxy({} as MenuHooks, {
  get: (_, name) =>
    ({ hasScore: () => true, hasSelection: () => true, supported: commandSupported, samples: () => [{ title: 'Mozart', open: noop }], canPaste: () => true, undoLabel: () => '“remove the stems”', redoLabel: () => null, panelShown: () => true })[name as string] ?? noop,
});
const COMMANDS = wordCommands(appMenus(hooks)).map(({ id, label, title }) => ({ id, label, title }));

/** Selections the commands are about: item counts by code; "place", a click on the paper with nothing selected, is about a whole score. */
const SCOPES: Record<string, Map<number, number>> = {
  notes: new Map([[1, 8]]),
  mixed: new Map([[1, 14], [5, 2], [9, 2], [16, 1], [6, 2]]),
  place: new Map([[1, 420], [2, 35], [3, 12], [4, 6], [5, 40], [6, 60], [8, 12], [9, 25], [10, 4], [14, 48], [16, 30], [17, 12], [18, 2]]),
};

/** [selection, command, what the intent must hold]; action "(none)": Claude's to write, `complex` with the model for complex commands. */
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
  ["place", "add notes c g d/f/a", {"action": "insert", "notes": "PC5/G/D:F:A"}],
  ["place", "put e f# g here", {"action": "insert"}],
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
  ["notes", "make the last note an x head", {"action": "option", "setting": "Head", "option": "X", "pick": "last"}],
  ["notes", "accent every other note", {"action": "option", "option": "Accent", "pick": "every other"}],
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
  ["place", "add c e g as eighths", {"action": "insert", "notes": "PC5/E/G", "rhythms": "8/8/8"}],
  ["notes", "double sharp", {"action": "option", "setting": "Accidental", "option": "♯♯ Double sharp"}],
  ["mixed", "make the slurs flatter", {"action": "(none)", "complex": false}],
  ["notes", "delete the eighth notes", {"action": "delete", "option": "Eighth"}],
  ["notes", "make the first three notes red", {"action": "(none)", "complex": false}],
  // Two actions at once, or a value given alongside a beam; the unsafe ones are Claude's.
  ["notes", "staccato and stems up", {"action": "option", "option": "Staccato", "then": {"action": "stems-up"}}],
  ["notes", "accent them and move up a step", {"then": {"action": "move"}}],
  ["notes", "make them eighths, then beam in pairs", {"then": {"action": "beam"}}],
  ["notes", "8th beam", {"action": "beam", "then": {"action": "option", "target": "notes", "setting": "Value", "option": "Eighth"}}],
  ["notes", "sixteenths beamed in fours", {"action": "beam", "amount": 4, "then": {"action": "option", "target": "notes", "setting": "Value", "option": "16th"}}],
  ["notes", "beam the eighths", {"then": undefined}],
  ["notes", "add staccatos and remove the stems", {"action": "(none)", "complex": false}],
  // Commands that take thought, for the model for complex commands.
  ["notes", "double the melody a third below", {"complex": true}],
  ["notes", "harmonize the melody in four parts", {"complex": true}],
  ["notes", "retrograde the melody", {"complex": true}],
  ["notes", "invert the melody around the first note", {"complex": true}],
  ["notes", "turn the chords into broken chords in sixteenths", {"complex": true}],
  ["notes", "write a walking bass under these notes", {"complex": true}],
  ["notes", "add lines from note head to note head", {"complex": true}],
  ["mixed", "add a crescendo hairpin under each slur", {"complex": true}],
  ["place", "add a c major arpeggio in eighths, up and back down", {"action": "(none)", "complex": true}],
  // Some of the items, picked out by place.
  ["notes", "accent the first note", {"action": "option", "option": "Accent", "pick": "first"}],
  ["notes", "stems down on the bottom notes of the chords", {"action": "stems-down", "pick": "bottom"}],
  ["notes", "make the top notes bigger", {"action": "bigger", "pick": "top"}],
  ["notes", "staccato on the first three notes", {"action": "option", "option": "Staccato", "pick": "first few", "many": 3}],
  ["notes", "move the highest note up an octave", {"action": "move", "direction": "up", "amount": 7, "pick": "highest"}],
  ["notes", "accent the first note of each bar", {"action": "option", "option": "Accent", "pick": "downbeats"}],
  ["notes", "move up two steps", {"action": "move", "direction": "up", "amount": 2, "pick": undefined}],
  // Selecting.
  ["notes", "select the top notes", {"action": "select", "pick": "top"}],
  ["mixed", "select the slurs", {"action": "select", "target": "slurs"}],
  ["notes", "select only the staccato notes", {"action": "select", "option": "Staccato"}],
  // New items.
  ["place", "add staff", {"action": "create", "item": "staff"}],
  ["place", "add a new staff", {"action": "create", "item": "staff"}],
  ["notes", "add a barline after these", {"action": "create", "item": "barline"}],
  ["place", "add a double bar", {"action": "create", "item": "double barline"}],
  ["place", "add a final barline", {"action": "create", "item": "final barline"}],
  ["notes", "add an end repeat", {"action": "create", "item": "end repeat"}],
  ["place", "add a bass clef", {"action": "create", "item": "bass clef"}],
  ["place", "add a key signature with three flats", {"action": "create", "item": "key signature", "word": "KSIG-3"}],
  ["place", "add a key signature for D major", {"action": "create", "item": "key signature", "word": "KSIG+2"}],
  ["place", "add 3/4 time", {"action": "create", "item": "meter", "word": "METER34"}],
  ["place", "common time", {"action": "create", "item": "common time"}],
  ["notes", "slur these notes", {"action": "create", "item": "slur"}],
  ["notes", "add a slur", {"action": "create", "item": "slur"}],
  ["notes", "tie them", {"action": "create", "item": "tie"}],
  ["notes", "add a crescendo", {"action": "create", "item": "crescendo"}],
  ["notes", "diminuendo hairpin under these notes", {"action": "create", "item": "diminuendo"}],
  ["notes", "8va over these", {"action": "create", "item": "ottava"}],
  ["notes", "add a pedal mark", {"action": "create", "item": "pedal"}],
  ["notes", "first ending over these bars", {"action": "create", "item": "first ending"}],
  ["notes", "add mf", {"action": "create", "item": "mf"}],
  ["place", "put a forte here", {"action": "create", "item": "f"}],
  ["place", "add a fermata", {"action": "create", "item": "fermata"}],
  ["notes", "add fermatas", {"action": "option", "option": "Fermata"}],
  ["place", "add the text \"Allegro\"", {"action": "create", "item": "text", "text": "Allegro"}],
  ["place", "write “dolce” here", {"action": "create", "item": "text", "text": "dolce"}],
  ["place", "put \"dolce\" here", {"action": "create", "item": "text", "text": "dolce"}],
  ["place", "add rehearsal number 12", {"action": "create", "item": "number", "more": [0, 12]}],
  ["notes", "add a slur over the first three notes", {"action": "create", "item": "slur", "pick": "first few", "many": 3}],
  // Bars by number.
  ["notes", "accent bar 2", {"action": "option", "option": "Accent", "bars": {"from": 2, "to": 2, "end": false}}],
  ["notes", "stems up in bars 1 to 2", {"action": "stems-up", "bars": {"from": 1, "to": 2, "end": false}}],
  ["mixed", "delete the second bar", {"action": "delete", "bars": {"from": 2, "to": 2, "end": false}}],
  ["notes", "select the last bar", {"action": "select", "bars": {"from": 1, "to": 1, "end": true}}],
  ["notes", "accent the last note of bar 2", {"action": "option", "option": "Accent", "pick": "last", "bars": {"from": 2, "to": 2, "end": false}}],
  ["notes", "make the first two bars staccato", {"action": "option", "option": "Staccato", "bars": {"from": 1, "to": 2, "end": false}}],
  // Only the notes with a property.
  ["notes", "accent the eighth notes", {"action": "option", "option": "Accent", "only": {"setting": "Value", "option": "Eighth"}}],
  ["notes", "stems up on the half notes", {"action": "stems-up", "only": {"setting": "Value", "option": "Half"}}],
  ["notes", "make the staccato notes bigger", {"action": "bigger", "only": {"setting": "Mark", "option": "Staccato"}}],
  ["notes", "make them eighth notes", {"action": "option", "option": "Eighth", "only": undefined}],
  ["notes", "accent the first note", {"action": "option", "option": "Accent", "only": undefined}],
  // Marks in turn, pitches and texts changed, lyrics, commands more than once.
  ["notes", "staccato, accent, staccato", {"action": "option", "sequence": ["Staccato", "Accent", "Staccato"]}],
  ["notes", "fingering 1 2 3 1", {"action": "option", "sequence": ["Fingering 1", "Fingering 2", "Fingering 3", "Fingering 1"]}],
  ["notes", "make it an f#", {"action": "change", "pitches": ["F#"]}],
  ["notes", "change them to c e g", {"action": "change", "pitches": ["C", "E", "G"]}],
  ["mixed", "change the text to \"Andante\"", {"action": "change", "text": "Andante"}],
  ["notes", "add lyrics \"Ky-ri-e e-le-i-son\"", {"action": "create", "item": "lyrics", "text": "Ky-ri-e e-le-i-son"}],
  ["notes", "undo 3 times", {"action": "app", "command": "undo", "amount": 3}],
  ["place", "zoom in twice", {"action": "app", "command": "zoom-in", "amount": 2}],
  ["notes", "do that again", {"action": "again", "amount": 1}],
  ["notes", "again, 3 times", {"action": "again", "amount": 3}],
  // Horizontal spacing.
  ["notes", "spread them out", {"action": "spread"}],
  ["notes", "more space between the notes", {"action": "spread"}],
  ["notes", "50% wider apart", {"action": "spread", "amount": 1.5}],
  ["notes", "move them closer together", {"action": "closer"}],
  ["notes", "tighter spacing", {"action": "closer"}],
  ["notes", "space them evenly", {"action": "evenly"}],
  ["notes", "distribute them evenly", {"action": "evenly"}],
  // Repeated after themselves.
  ["notes", "repeat 3 times", {"action": "repeat", "amount": 3}],
  ["notes", "repeat these notes twice", {"action": "repeat", "amount": 2}],
  ["mixed", "repeat this bar four times", {"action": "repeat", "amount": 4}],
  ["notes", "repeat it", {"action": "repeat", "amount": undefined}],
  ["notes", "repeat the last note 5 times", {"action": "repeat", "amount": 5, "pick": "last"}],
  ["notes", "play this twice", {"action": "repeat", "amount": 2}],
  // Properties of the whole score's items, at a place: no new item.
  ["place", "make all the slurs dashed", {"action": "option", "setting": "Line", "option": "Dashed"}],
  ["place", "add staccatos to all notes", {"action": "option", "option": "Staccato"}],
  ["place", "make every note an eighth", {"action": "option", "option": "Eighth"}],
  ["place", "accent all the notes", {"action": "option", "option": "Accent"}],
  ["place", "make all the clefs bass clefs", {"action": "option", "option": "Bass"}],
  // The editor's own commands.
  ["notes", "undo", {"action": "app", "command": "undo"}],
  ["notes", "copy these", {"action": "app", "command": "copy"}],
  ["place", "save the score", {"action": "app", "command": "save"}],
  ["place", "zoom in", {"action": "app", "command": "zoom-in"}],
  ["place", "fit the page to the width", {"action": "app", "command": "fit"}],
  ["place", "hide the side panel", {"action": "app", "command": "panel"}],
  ["place", "export as svg", {"action": "app", "command": "export-svg"}],
  ["notes", "duplicate them", {"action": "app", "command": "duplicate"}],
  ["place", "print it", {"action": "app", "command": "print"}],
  ["place", "show the keyboard shortcuts", {"action": "app", "command": "shortcuts"}],
];

const key = process.env.TYPESAFE_API_KEY;
if (!key) throw new Error('TYPESAFE_API_KEY is not set');
const connection = { url: TYPESAFE_URL, key, model: process.env.JEV_MODEL ?? 'jev-latest' };
const rows: string[] = [];
const times: number[] = [];
let passed = 0;
let next = 0;
// JEV_CASES=beam,stems runs only the cases whose command has one of these words; JEV_ANSWERS=1 shows Jev's answers to each.
const only = process.env.JEV_CASES?.split(',');
const CHOSEN = only ? CASES.filter(([, text]) => only.some((w) => text.includes(w))) : CASES;

/** Whether `got` has every field `expect` gives, objects field by field. */
function holds(got: unknown, expect: unknown): boolean {
  if (expect && typeof expect === 'object') {
    return !!got && typeof got === 'object' && Object.entries(expect).every(([k, v]) => holds((got as Record<string, unknown>)[k], v));
  }
  return JSON.stringify(got) === JSON.stringify(expect);
}

/** Jev's answers that were not none, as "action delete 98 %". */
function answered(answers: Record<string, { choice: string; confidence: number }>): string {
  return Object.entries(answers)
    .filter(([, a]) => a.choice !== 'none')
    .map(([id, a]) => `${id} ${a.choice} ${Math.round(a.confidence * 100)} %`)
    .join(', ');
}

async function one(i: number) {
  const [scope, text, expect] = CHOSEN[i]!;
  const counts = SCOPES[scope]!;
  const about: About = {
    text,
    counts,
    whole: scope === 'place',
    region: scope === 'place' ? { staff: 1, bottom: 1, top: 1, from: 100, to: 180 } : null,
    middle: 34,
    sample: [],
    bars: new Map(),
    commands: COMMANDS,
    codeName: (code) => counted(code, 2).replace(/^2 /, ''),
  };
  try {
    const reading = await askJev(about, connection, new AbortController().signal);
    times.push(reading.ms);
    const got: Record<string, unknown> = { ...(reading.intent ?? { action: '(none)', read: reading.action }), complex: reading.complex };
    const ok = holds(got, expect);
    if (ok) passed++;
    const summary = reading.intent ? ` | ${scriptFor(reading.intent).summary}` : '';
    rows[i] = `${ok ? 'ok  ' : 'FAIL'} ${String(Math.round(reading.ms)).padStart(4)} ms ${String(Math.round(reading.confidence * 100)).padStart(3)} % [${scope}] "${text}" → ${JSON.stringify(got)}${ok ? '' : `, expected ${JSON.stringify(expect)}`}${summary}${ok && !process.env.JEV_ANSWERS ? '' : `; ${answered(reading.answers)}`}`;
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
