// Copies the bundled sample scores into public/, writes
// public/samples/index.json describing them, and src/generated/commands.json
// from WinScore's command table.
//
// Samples are stored as base64 text (<file>.b64.txt) so that every file of
// the built site has a type static hosts serve.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const web = path.dirname(path.dirname(fileURLToPath(import.meta.url)));
const repo = path.join(web, '..');
const publicDir = path.join(web, 'public');

const sources = [
  ...['000.mus', 'carmen.mus', 'mozart.mus', 'sonlcs.mus'].map((f) => path.join('WINSCORE 5.01', 'winscore', f)),
  ...['NEWLINE.MUS', 'NEWLIB.MUS'].map((f) => path.join('SCORE 4', 'SCORE', f)),
];

const caseName = (file) => `sample-${path.parse(file).name.toLowerCase()}`;

// public/reference/ held engine display lists in earlier versions of this script.
for (const dir of ['samples', 'reference']) fs.rmSync(path.join(publicDir, dir), { recursive: true, force: true });
fs.mkdirSync(path.join(publicDir, 'samples'), { recursive: true });

const index = sources.map((source) => {
  const file = path.basename(source);
  const encoded = `${file}.b64.txt`;
  fs.writeFileSync(path.join(publicDir, 'samples', encoded), fs.readFileSync(path.join(repo, source)).toString('base64'));
  return { title: file, url: `samples/${encoded}`, case: caseName(file) };
});

fs.writeFileSync(path.join(publicDir, 'samples', 'index.json'), JSON.stringify(index, null, 2));

// WinScore's menu and toolbar commands (analysis/data/command_map.tsv): id → SCORE command and tooltip.
const commandRows = fs
  .readFileSync(path.join(repo, 'analysis', 'data', 'command_map.tsv'), 'utf8')
  .split('\n')
  .slice(1)
  .map((line) => line.split('\t'))
  .filter(([id, , command]) => id && command?.trim());
const commands = Object.fromEntries(commandRows.map(([id, , command, tooltip]) => [id, { command: command.trim(), tooltip: tooltip?.trim() ?? '' }]));
fs.mkdirSync(path.join(web, 'src', 'generated'), { recursive: true });
fs.writeFileSync(path.join(web, 'src', 'generated', 'commands.json'), JSON.stringify(commands));
console.log(`assets: ${index.length} samples`);
