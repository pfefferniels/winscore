// Screenshots of the built app (dist/) via headless Chromium.
//
// usage: node scripts/screenshots.mjs OUT_DIR [name=query ...]
// Each shot opens index.html?<query> and waits until the page sets
// #app[data-ready]. Without shots, a default set is taken.
import { chromium } from 'playwright';
import { preview } from 'vite';
import fs from 'node:fs';
import path from 'node:path';

const [outDir = 'screenshots', ...args] = process.argv.slice(2);

const DEFAULT_SHOTS = {
  start: '',
  carmen: 'sample=carmen.mus',
  'mozart-200': 'sample=mozart.mus&zoom=200',
  new: 'new',
};

const shots = args.length ? Object.fromEntries(args.map((a) => a.split(/=(.*)/s).slice(0, 2))) : DEFAULT_SHOTS;

fs.mkdirSync(outDir, { recursive: true });
const server = await preview({ preview: { port: 4179, strictPort: true } });
const browser = await chromium.launch();
try {
  const page = await browser.newPage({ viewport: { width: 1600, height: 1000 }, deviceScaleFactor: 2 });
  page.on('console', (msg) => msg.type() === 'error' && console.error('page:', msg.text()));
  for (const [name, query] of Object.entries(shots)) {
    await page.goto(`http://localhost:4179/?${query}`);
    await page.waitForSelector('#app[data-ready="true"]', { timeout: 30000 });
    await page.waitForTimeout(300);
    const file = path.join(outDir, `${name}.png`);
    await page.screenshot({ path: file });
    console.log(file);
  }
} finally {
  await browser.close();
  server.httpServer.close();
}
