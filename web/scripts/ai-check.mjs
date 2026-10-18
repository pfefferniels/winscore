// Bundles scripts/ai-checks.ts (or the script named) with Vite and runs it
// in Node: the AI command's parts that need no browser. Needs the wasm
// (npm run wasm).
import { build } from 'vite';
import { fileURLToPath, pathToFileURL } from 'node:url';
import path from 'node:path';
import fs from 'node:fs';

const web = path.dirname(path.dirname(fileURLToPath(import.meta.url)));
const entry = process.argv[2] ?? 'ai-checks.ts';
// Inside node_modules, so that packages the bundle leaves out (the Anthropic SDK) resolve.
const out = fs.mkdtempSync(path.join(web, 'node_modules', '.ai-check-'));
await build({
  root: web,
  configFile: false,
  logLevel: 'warn',
  build: { ssr: path.join(web, 'scripts', entry), outDir: out, emptyOutDir: true, rollupOptions: { output: { entryFileNames: 'entry.mjs' } } },
});
process.env.SCORE_WASM = path.join(web, 'src', 'wasm', 'score_web_bg.wasm');
process.env.SCORE_SAMPLES = path.join(web, '..', 'WINSCORE 5.01', 'winscore');
try {
  await import(pathToFileURL(path.join(out, 'entry.mjs')).href);
} finally {
  fs.rmSync(out, { recursive: true, force: true });
}
