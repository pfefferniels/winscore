// End-to-end check of the built app (dist/) in headless Chromium: open a
// sample, click a staff line, edit a parameter, save.
import { chromium } from 'playwright';
import { preview } from 'vite';
import assert from 'node:assert/strict';
import fs from 'node:fs';

const server = await preview({ preview: { port: 4178, strictPort: true } });
const browser = await chromium.launch();
try {
  const page = await browser.newPage({ viewport: { width: 1400, height: 900 }, acceptDownloads: true });
  const errors = [];
  page.on('pageerror', (err) => errors.push(err.message));
  await page.goto('http://localhost:4178/?sample=mozart.mus&mode=rust&zoom=400');
  await page.waitForSelector('#app[data-ready="true"]');

  // At 400 % the staff does not fit, so selecting it from the list scrolls it
  // to the middle of the view. Clicks down the centre column then hit one of
  // its lines (spaced about 33 px at this zoom).
  await page.click('#items li[data-index="2"]');
  assert.equal(await page.textContent('#item h2'), 'Item 2 · Staff');
  await page.keyboard.press('Escape');
  assert.equal(await page.textContent('#item h2'), 'No item selected');
  const centre = await page.evaluate(() => {
    const r = document.getElementById('viewport').getBoundingClientRect();
    return { x: r.left + r.width / 2, y: r.top + r.height / 2 };
  });
  const offsets = Array.from({ length: 41 }, (_, i) => (i - 20) * 6);
  const titles = [];
  for (const dy of offsets) {
    await page.mouse.click(centre.x, centre.y + dy);
    titles.push(await page.textContent('#item h2'));
  }
  assert.ok(titles.includes('Item 2 · Staff'), `clicks selected ${[...new Set(titles)]}`);
  assert.ok(titles.includes('No item selected'));
  const onStaff = { x: centre.x, y: centre.y + offsets[titles.indexOf('Item 2 · Staff')] };
  await page.click('#items li[data-index="2"]');
  assert.match(await page.textContent('#cursor'), /^x \d+ {2}y \d+/);

  // Keyboard nudges, undo and redo.
  await page.keyboard.press('ArrowUp');
  assert.equal(await page.inputValue('#p4'), '25');
  await page.click('#undo');
  assert.equal(await page.inputValue('#p4'), '24');
  await page.keyboard.press('Control+y');
  assert.equal(await page.inputValue('#p4'), '25');
  await page.keyboard.press('Control+z');
  assert.equal(await page.inputValue('#p4'), '24');

  // Dragging the selected staff to the right changes P3; undo restores it.
  await page.mouse.move(onStaff.x, onStaff.y);
  await page.mouse.down();
  await page.mouse.move(onStaff.x + 60, onStaff.y, { steps: 6 });
  await page.mouse.up();
  const draggedP3 = Number(await page.inputValue('#p3'));
  assert.ok(draggedP3 > 3 && draggedP3 < 5, `P3 after drag: ${draggedP3}`);
  await page.keyboard.press('Control+z');
  assert.equal(await page.inputValue('#p3'), '0');
  await page.fill('#p5', '1.2');
  await page.press('#p5', 'Enter');
  assert.match(await page.textContent('#status'), /modified/);
  assert.equal(await page.inputValue('#p5'), '1.2');

  const [download] = await Promise.all([page.waitForEvent('download'), page.click('#save')]);
  const saved = fs.readFileSync(await download.path());
  const original = fs.readFileSync('../WINSCORE 5.01/winscore/mozart.mus');
  assert.equal(saved.length, original.length);
  assert.notDeepEqual(saved, original);

  // Five-pass input: errors are marked in their pass; a valid line adds a staff and four notes.
  await page.click('#input');
  assert.equal(await page.inputValue('#input-staff'), '9');
  await page.fill('#pass-1', 'C4/D/E/F;');
  await page.fill('#pass-2', '4/4;');
  assert.match(await page.textContent('#pass-error-2'), /rhythm/);
  assert.ok(await page.isDisabled('#input-insert'));
  await page.fill('#pass-2', '4/4/4/4;');
  assert.equal(await page.textContent('#input-status'), 'Adds 5 items');
  await page.click('#input-insert');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '(349)');
  assert.match(await page.textContent('#item h2'), /^Item 348 · Note \(\+4 selected\)/);
  assert.deepEqual(errors, []);

  // Without the wasm module the page says so instead of staying blank.
  const blocked = await browser.newPage();
  await blocked.route('**/*.wasm', (route) => route.abort());
  await blocked.goto('http://localhost:4178/');
  await blocked.waitForSelector('.fatal');
  assert.match(await blocked.textContent('.fatal strong'), /WebAssembly module could not be loaded/);
  console.log('smoke: ok');
} finally {
  await browser.close();
  server.httpServer.close();
}
