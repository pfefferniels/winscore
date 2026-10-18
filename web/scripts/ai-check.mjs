// Bundles scripts/ai-checks.ts (or the script named) with Vite and runs it
// in Node: the AI command's parts that need no browser. Needs the wasm
// (npm run wasm).
import { build } from 'vite';
import { fileURLToPath, pathToFileURL } from 'node:url';
import path from 'node:path';
import os from 'node:os';
import fs from 'node:fs';

const web = path.dirname(path.dirname(fileURLToPath(import.meta.url)));
const entry = process.argv[2] ?? 'ai-checks.ts';
const out = fs.mkdtempSync(path.join(os.tmpdir(), 'ai-check-'));
await build({
  root: web,
  configFile: false,
  logLevel: 'warn',
  build: { ssr: path.join(web, 'scripts', entry), outDir: out, emptyOutDir: true, rollupOptions: { output: { entryFileNames: 'entry.mjs' } } },
});
process.env.SCORE_WASM = path.join(web, 'src', 'wasm', 'score_web_bg.wasm');
await import(pathToFileURL(path.join(out, 'entry.mjs')).href);
fs.rmSync(out, { recursive: true, force: true });
