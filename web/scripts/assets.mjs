// Copies the bundled sample scores into public/ and writes
// public/samples/index.json describing them.
//
// Samples are stored as base64 text (<file>.b64.txt) so that every file of
// the built site has a type static hosts serve.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const web = path.dirname(path.dirname(fileURLToPath(import.meta.url)));
const repo = path.join(web, '..');
const publicDir = path.join(web, 'public');

const sources = ['000.mus', 'carmen.mus', 'mozart.mus', 'sonlcs.mus', 'NEWLINE.MUS', 'NEWLIB.MUS'].map((f) => path.join('assets', 'samples', f));

const caseName = (file) => `sample-${path.parse(file).name.toLowerCase()}`;

fs.rmSync(path.join(publicDir, 'samples'), { recursive: true, force: true });
fs.mkdirSync(path.join(publicDir, 'samples'), { recursive: true });

const index = sources.map((source) => {
  const file = path.basename(source);
  const encoded = `${file}.b64.txt`;
  fs.writeFileSync(path.join(publicDir, 'samples', encoded), fs.readFileSync(path.join(repo, source)).toString('base64'));
  return { title: file, url: `samples/${encoded}`, case: caseName(file) };
});

fs.writeFileSync(path.join(publicDir, 'samples', 'index.json'), JSON.stringify(index, null, 2));

console.log(`assets: ${index.length} samples`);
