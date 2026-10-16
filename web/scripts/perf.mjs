// Frame times while dragging an item in the built app (dist/), headless Chromium.
//
// usage: node scripts/perf.mjs [FILE.mus ...]   (default: the largest bundled sample)
// For each score: open it at 300 %, select the middle note from the item
// list, drag it for about two seconds, and report the longest frame and the
// long tasks (> 50 ms) the browser saw.
import { chromium } from 'playwright';
import { preview } from 'vite';
import path from 'node:path';

const PORT = 4177;
const files = process.argv.slice(2);
const server = await preview({ preview: { port: PORT, strictPort: true } });
const browser = await chromium.launch();

/** Opens the bundled sample by URL, or a file through the file picker. */
async function open(page, file) {
  await page.goto(`http://localhost:${PORT}/${file ? '' : '?sample=carmen.mus'}`);
  await page.waitForSelector('#app[data-ready="true"]');
  if (file) {
    await page.setInputFiles('#file', file);
    await page.waitForFunction((name) => document.getElementById('status').textContent.startsWith(name), path.basename(file));
  }
  await page.selectOption('#zoom', '300');
}

/** Selects the middle note of the item list; the page scrolls it into view. */
async function selectMiddleNote(page) {
  const index = await page.evaluate(() => {
    const notes = [...document.querySelectorAll('#items li')].filter((li) => li.children[1].textContent.endsWith(' Note'));
    return Number(notes[Math.floor(notes.length / 2)].dataset.index);
  });
  await page.click(`#items li[data-index="${index}"]`);
  return index;
}

/** The client point at the centre of the highlighted (selected) pixels. */
async function highlightCentre(page) {
  return page.evaluate(() => {
    const canvas = document.getElementById('canvas');
    const { data, width, height } = canvas.getContext('2d').getImageData(0, 0, canvas.width, canvas.height);
    const hits = [];
    for (let i = 0; i < width * height; i++) {
      if (data[4 * i] === 0x25 && data[4 * i + 1] === 0x63 && data[4 * i + 2] === 0xeb) hits.push(i);
    }
    if (hits.length === 0) return null;
    const middle = hits[Math.floor(hits.length / 2)];
    const rect = canvas.getBoundingClientRect();
    const ratio = canvas.width / rect.width;
    return { x: rect.left + (middle % width) / ratio, y: rect.top + Math.floor(middle / width) / ratio };
  });
}

async function measure(label, file) {
  const page = await browser.newPage({ viewport: { width: 1400, height: 900 } });
  await open(page, file);
  const count = Number((await page.textContent('#item-count')).replace(/\D/g, ''));
  const index = await selectMiddleNote(page);
  await page.waitForTimeout(100);
  const at = await highlightCentre(page);
  if (!at) throw new Error(`${label}: item ${index} is not drawn on screen`);
  await page.evaluate(() => {
    window.perf = { frames: [], long: [] };
    new PerformanceObserver((list) => list.getEntries().forEach((e) => window.perf.long.push(e.duration))).observe({ type: 'longtask' });
    const tick = (t) => {
      window.perf.frames.push(t);
      requestAnimationFrame(tick);
    };
    requestAnimationFrame(tick);
  });
  await page.mouse.move(at.x, at.y);
  await page.evaluate(() => (window.perf.start = performance.now()));
  await page.mouse.down();
  const steps = 120;
  for (let i = 1; i <= steps; i++) {
    const phase = (i / steps) * Math.PI * 2;
    await page.mouse.move(at.x + 80 * Math.sin(phase), at.y - 40 * Math.sin(phase / 2));
    await page.waitForTimeout(16);
  }
  await page.evaluate(() => (window.perf.drop = performance.now()));
  await page.mouse.up();
  await page.waitForTimeout(300);
  const title = await page.textContent('#item h2');
  const result = await page.evaluate(() => {
    const { frames, start, drop } = window.perf;
    const gaps = frames.slice(1).map((t, i) => ({ end: t, length: t - frames[i] }));
    const longest = (keep) => Math.max(0, ...gaps.filter(keep).map((g) => g.length));
    return {
      frames: gaps.filter((g) => g.end > start && g.end <= drop).length,
      dragging: longest((g) => g.end > start && g.end <= drop),
      drop: longest((g) => g.end > drop),
      long: window.perf.long,
    };
  });
  const long = result.long.length ? `${result.long.map((d) => d.toFixed(0)).join(', ')} ms` : 'none';
  console.log(
    `${label}: ${count} items, dragged ${title}; ${result.frames} frames while dragging, longest ${result.dragging.toFixed(1)} ms; ` +
      `drop ${result.drop.toFixed(1)} ms; long tasks: ${long}`,
  );
  await page.close();
  return result.dragging;
}

try {
  const worst = [];
  if (files.length === 0) worst.push(await measure('carmen.mus', null));
  for (const file of files) worst.push(await measure(path.basename(file), file));
  process.exitCode = worst.some((ms) => ms > 50) ? 1 : 0;
} finally {
  await browser.close();
  server.httpServer.close();
}
