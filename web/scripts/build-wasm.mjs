// Builds rust/crates/score-web for wasm32 and generates the JS bindings in src/wasm/.
import { execFileSync } from 'node:child_process';
import { fileURLToPath } from 'node:url';
import path from 'node:path';

const web = path.dirname(path.dirname(fileURLToPath(import.meta.url)));
const rust = path.join(web, '..', 'rust');
const targetDir = process.env.CARGO_TARGET_DIR ?? path.join(rust, 'target');
const profile = process.env.WASM_PROFILE ?? 'release';

const run = (command, args, options = {}) => execFileSync(command, args, { stdio: 'inherit', ...options });

run('cargo', ['build', '-p', 'score-web', '--target', 'wasm32-unknown-unknown', '--profile', profile], {
  cwd: rust,
  env: { ...process.env, CARGO_TARGET_DIR: targetDir },
});

const profileDir = profile === 'dev' ? 'debug' : profile;
const wasm = path.join(targetDir, 'wasm32-unknown-unknown', profileDir, 'score_web.wasm');
run('wasm-bindgen', ['--target', 'web', '--typescript', '--out-dir', path.join(web, 'src', 'wasm'), wasm]);
