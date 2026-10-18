// Crops of the painted page at several zooms and pixel ratios, for judging
// the painter by eye (pen widths, snapping, text). Needs a build (dist/).
//
// usage: node scripts/zoom-shots.mjs OUT_DIR [sample=mozart.mus] [at=X,Y]
//          [size=W,H] [zooms=50,100,400] [dprs=1,2] [name=PREFIX] [dist=DIR]
// `at` is the page point (engine units, y up) at the crop's top-left corner,
// `size` the crop in CSS pixels; `dist` another build to compare with.
// Writes PREFIX-<zoom>-<dpr>x.png.
import { chromium } from 'playwright';
import { preview } from 'vite';
import fs from 'node:fs';
import path from 'node:path';

const [outDir = 'zoom-shots', ...args] = process.argv.slice(2);
const option = Object.fromEntries(args.map((a) => a.split(/=(.*)/s).slice(0, 2)));
const numbers = (text) => text.split(',').map(Number);
const sample = option.sample ?? 'mozart.mus';
const [atX, atY] = numbers(option.at ?? '3000,40000');
const [width, height] = numbers(option.size ?? '480,320');
const zooms = numbers(option.zooms ?? '50,100,400');
const dprs = numbers(option.dprs ?? '1,2');
const prefix = option.name ?? path.parse(sample).name;

const CSS_PER_UNIT = 96 / 4000;

fs.mkdirSync(outDir, { recursive: true });
const server = await preview({ build: { outDir: option.dist ?? 'dist' }, preview: { port: 4177, strictPort: true } });
const browser = await chromium.launch();
try {
  for (const dpr of dprs) {
    const page = await browser.newPage({ viewport: { width: 1400, height: 900 }, deviceScaleFactor: dpr });
    page.on('pageerror', (err) => console.error('page:', err.message));
    for (const zoom of zooms) {
      await page.goto(`http://localhost:4177/?sample=${encodeURIComponent(sample)}&zoom=${zoom}`);
      await page.waitForSelector('#app[data-ready="true"]', { timeout: 30000 });
      // The status bar reads the page point under the mouse: scroll by the
      // difference, as far as the page scrolls, and crop where the point lies then.
      const box = await page.locator('#viewport').boundingBox();
      const s = (zoom / 100) * CSS_PER_UNIT;
      const offset = async () => {
        await page.mouse.move(box.x + 1, box.y + 1);
        const [x, y] = (await page.textContent('#cursor')).match(/-?\d+/g).map(Number);
        return { dx: (atX - x) * s, dy: (y - atY) * s };
      };
      const wanted = await offset();
      await page.evaluate(({ dx, dy }) => {
        const viewport = document.getElementById('viewport');
        viewport.scrollLeft += dx;
        viewport.scrollTop += dy;
      }, wanted);
      await page.waitForTimeout(200);
      const left = await offset();
      await page.mouse.move(box.x + box.width - 2, box.y + box.height - 2);
      await page.waitForTimeout(100);
      const file = path.join(outDir, `${prefix}-${zoom}-${dpr}x.png`);
      const x = Math.max(box.x, Math.min(box.x + box.width - width, box.x + 1 + Math.round(left.dx)));
      const y = Math.max(box.y, Math.min(box.y + box.height - height, box.y + 1 + Math.round(left.dy)));
      await page.screenshot({ path: file, clip: { x, y, width, height } });
      console.log(file);
    }
    await page.close();
  }
} finally {
  await browser.close();
  server.httpServer.close();
}
