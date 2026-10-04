// Copies the bundled sample scores and their engine reference display lists
// into public/, and writes public/samples/index.json describing them.
//
// References are read from REFERENCE_DIR (default rust/fixtures), one
// directory per case as verifier writes them: <case>/engine.json, meta.json.
import fs from 'node:fs';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

const web = path.dirname(path.dirname(fileURLToPath(import.meta.url)));
const repo = path.join(web, '..');
const referenceDir = process.env.REFERENCE_DIR ?? path.join(repo, 'rust', 'fixtures');
const publicDir = path.join(web, 'public');

const sources = [
  ...['000.mus', 'carmen.mus', 'mozart.mus', 'sonlcs.mus'].map((f) => path.join('WINSCORE 5.01', 'winscore', f)),
  ...['NEWLINE.MUS', 'NEWLIB.MUS'].map((f) => path.join('SCORE 4', 'SCORE', f)),
];

const caseName = (file) => `sample-${path.parse(file).name.toLowerCase()}`;

const readJson = (file) => (fs.existsSync(file) ? JSON.parse(fs.readFileSync(file, 'utf8')) : null);

function copyReference(name) {
  const engine = path.join(referenceDir, name, 'engine.json');
  if (!fs.existsSync(engine)) return null;
  fs.copyFileSync(engine, path.join(publicDir, 'reference', `${name}.json`));
  const meta = readJson(path.join(referenceDir, name, 'meta.json')) ?? {};
  return { url: `reference/${name}.json`, paper: meta.paper ?? null };
}

for (const dir of ['samples', 'reference']) {
  fs.rmSync(path.join(publicDir, dir), { recursive: true, force: true });
  fs.mkdirSync(path.join(publicDir, dir), { recursive: true });
}

const index = sources.map((source) => {
  const file = path.basename(source);
  fs.copyFileSync(path.join(repo, source), path.join(publicDir, 'samples', file));
  const name = caseName(file);
  return { title: file, url: `samples/${file}`, case: name, reference: copyReference(name) };
});

fs.writeFileSync(path.join(publicDir, 'samples', 'index.json'), JSON.stringify(index, null, 2));
const withReference = index.filter((s) => s.reference).length;
console.log(`assets: ${index.length} samples, ${withReference} with engine reference (from ${referenceDir})`);
