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

  // SCORE commands from the command bar act on the selection.
  await page.fill('#command', 'R 5');
  await page.press('#command', 'Enter');
  assert.equal(await page.inputValue('#p3'), '5');
  assert.match(await page.textContent('#message'), /^R 5 · Item 2 Staff: 8 1 5 24/);
  await page.fill('#command', 'XYZZY');
  await page.press('#command', 'Enter');
  assert.match(await page.textContent('#message'), /unknown word/);
  await page.click('#undo');
  assert.equal(await page.inputValue('#p3'), '0');

  // Typing on the page goes to the command bar; Up recalls the previous line; Escape returns to the page.
  await page.focus('#viewport');
  await page.keyboard.type('U 2');
  assert.equal(await page.inputValue('#command'), 'U 2');
  await page.keyboard.press('Enter');
  assert.equal(await page.inputValue('#p4'), '26');
  await page.keyboard.press('ArrowUp');
  assert.equal(await page.inputValue('#command'), 'U 2');
  await page.keyboard.press('ArrowUp');
  assert.equal(await page.inputValue('#command'), 'XYZZY');
  await page.keyboard.press('Escape');
  assert.equal(await page.evaluate(() => document.activeElement.id), 'viewport');
  await page.keyboard.press('Control+z');
  assert.equal(await page.inputValue('#p4'), '24');

  // Enter on the page moves edit mode to the next item, as in WinScore.
  await page.keyboard.press('Enter');
  assert.equal(await page.textContent('#item h2'), 'Item 3 · Clef');
  await page.click('#items li[data-index="2"]');

  // The palette sends WinScore's toolbar commands; TREB appends a treble clef and selects it.
  await page.click('#palette button:text-is("Treble")');
  assert.equal(await page.textContent('#item-count'), '(345)');
  assert.match(await page.textContent('#item h2'), /^Item 344 · Clef/);
  await page.keyboard.press('Control+z');
  assert.equal(await page.textContent('#item-count'), '(344)');
  await page.click('#items li[data-index="2"]');

  // Delete and undo it.
  await page.click('#items li[data-index="3"]');
  assert.equal(await page.textContent('#item h2'), 'Item 3 · Clef');
  await page.keyboard.press('Delete');
  assert.equal(await page.textContent('#item-count'), '(343)');
  await page.keyboard.press('Control+z');
  assert.equal(await page.textContent('#item-count'), '(344)');
  assert.equal(await page.textContent('#item h2'), 'Item 3 · Clef');

  await page.click('#items li[data-index="2"]');
  await page.fill('#p5', '1.2');
  await page.press('#p5', 'Enter');
  assert.match(await page.textContent('#status'), /modified/);
  assert.equal(await page.inputValue('#p5'), '1.2');

  const [download] = await Promise.all([page.waitForEvent('download'), page.click('#save')]);
  const saved = fs.readFileSync(await download.path());
  const original = fs.readFileSync('../WINSCORE 5.01/winscore/mozart.mus');
  assert.equal(saved.length, original.length);
  assert.notDeepEqual(saved, original);

  // SVG export downloads the printed page; Print paints it alone for the print stylesheet.
  const [svgDownload] = await Promise.all([page.waitForEvent('download'), page.click('#export-svg')]);
  assert.equal(svgDownload.suggestedFilename(), 'mozart.svg');
  const svg = fs.readFileSync(await svgDownload.path(), 'utf8');
  assert.match(svg, /^<svg[^>]*width="8.5in"/);
  await page.evaluate(() => (window.print = () => (document.body.dataset.printed = 'yes')));
  await page.click('#print');
  await page.waitForSelector('body[data-printed="yes"]', { state: 'attached' });
  assert.deepEqual(await page.evaluate(() => [...document.querySelectorAll('#print-page canvas')].map((c) => [c.width, c.height])), [[2550, 4200]]);
  await page.emulateMedia({ media: 'print' });
  assert.ok(await page.isHidden('#app'));
  assert.ok(await page.isVisible('#print-page canvas'));
  await page.emulateMedia({ media: 'screen' });

  // Music input: the line shows on the page as it is typed and the help follows the caret;
  // a bad rhythm is marked in its pass; Ctrl+Enter inserts a staff and four notes.
  await page.click('#input');
  assert.ok(await page.isVisible('#input-panel'));
  assert.equal(await page.inputValue('#input-staff'), '9');
  await page.keyboard.type('G');
  await page.waitForFunction(() => document.querySelector('#input-help .help-shown')?.textContent.includes('G4, quarter'));
  assert.match(await page.textContent('#input-help h3'), /^Note G/);
  assert.match(await page.textContent('#input-help .help-keys'), /octave/);
  await page.keyboard.type('5/K2');
  await page.waitForFunction(() => document.querySelector('#input-help h3')?.textContent === 'Key signature, 2 accidentals');
  assert.match(await page.textContent('#input-help .help-status'), /^Not finished/);
  assert.equal(await page.textContent('#pass-error-1'), '');
  await page.fill('#pass-1', 'C4/D/E/F');
  await page.fill('#pass-2', '4/Y');
  await page.waitForFunction(() => document.getElementById('pass-error-2').textContent !== '');
  assert.ok(await page.isDisabled('#input-insert'));
  await page.fill('#pass-2', '4');
  await page.waitForFunction(() => document.getElementById('input-status').textContent === 'Adds 5 items');
  await page.keyboard.press('Control+Enter');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '(349)');
  assert.match(await page.textContent('#item h2'), /^Item 348 · Note \(\+4 selected\)/);
  assert.equal(await page.inputValue('#pass-1'), '');
  assert.equal(await page.inputValue('#input-staff'), '10');
  await page.keyboard.press('Escape');
  assert.ok(await page.isHidden('#input-panel'));
  await page.click('#undo');
  assert.equal(await page.textContent('#item-count'), '(344)');
  // IN n on the command bar opens the input on staff n.
  await page.fill('#command', 'IN 3');
  await page.press('#command', 'Enter');
  assert.ok(await page.isVisible('#input-panel'));
  assert.equal(await page.inputValue('#input-staff'), '3');
  await page.click('#input-close');
  assert.ok(await page.isHidden('#input-panel'));

  // Text: the palette's Text button opens the dialog; the font goes in front as _NN.
  await page.click('#items li[data-index="2"]');
  await page.click('#palette button:text-is("Text")');
  await page.fill('#text-value', 'Allegro');
  await page.selectOption('#text-font', '1');
  await page.click('#text-insert');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '(345)');
  assert.match(await page.textContent('#item h2'), /^Item 344 · Text/);
  assert.equal(await page.inputValue('#item-text'), '_01Allegro');
  await page.fill('#item-text', '_01Allegro vivace');
  await page.press('#item-text', 'Enter');
  assert.match(await page.textContent('#message'), /^Edit text/);
  assert.equal(await page.inputValue('#item-text'), '_01Allegro vivace');
  await page.click('#undo');
  await page.click('#undo');
  assert.equal(await page.textContent('#item-count'), '(344)');

  // Symbol picker: a searchable grid of library symbols drawn by the renderer.
  await page.click('#items li[data-index="2"]');
  await page.click('#palette button:text-is("Symbol")');
  await page.waitForSelector('#symbol-grid .symbol-cell');
  const symbol = await page.getAttribute('#symbol-grid .symbol-cell:nth-child(2)', 'data-number');
  await page.fill('#symbol-search', 'no symbol is called this');
  assert.equal(await page.textContent('#symbol-count'), '0 symbols');
  await page.fill('#symbol-search', '');
  await page.click('#symbol-grid .symbol-cell:nth-child(2)');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '(345)');
  assert.match(await page.textContent('#item h2'), /^Item 344 · Symbol/);
  assert.equal(await page.inputValue('#p5'), symbol);
  await page.click('#undo');

  // Group edit: the command asks for the area, then the destination; Cancel ends it.
  await page.click('#palette button:text-is("Move area")');
  assert.match(await page.textContent('#prompt'), /^Enter staff, left position/);
  await page.keyboard.type('1 0 200 2');
  await page.keyboard.press('Enter');
  assert.match(await page.textContent('#prompt'), /^Enter destination staff/);
  await page.click('#prompt-cancel');
  assert.ok(await page.isHidden('#prompt'));
  assert.equal(await page.textContent('#item-count'), '(344)');

  // Layout: LJ asks for the system, answered on the command bar; the result is one undo step.
  await page.click('#palette button:text-is("LJ")');
  assert.match(await page.textContent('#prompt'), /Lowest Staff/);
  await page.keyboard.type('1 2');
  await page.keyboard.press('Enter');
  assert.ok(await page.isHidden('#prompt'));
  assert.ok(await page.isEnabled('#undo'));
  await page.click('#undo');
  await page.focus('#viewport');
  await page.keyboard.type('LJA');
  await page.keyboard.press('Enter');
  assert.ok(await page.isHidden('#prompt'));
  await page.click('#undo');

  // A box drawn over empty paper selects the items inside it (fresh view: scrolled to the music).
  await page.goto('http://localhost:4178/?sample=mozart.mus&mode=rust');
  await page.waitForSelector('#app[data-ready="true"]');
  const area = await page.evaluate(() => {
    const r = document.getElementById('viewport').getBoundingClientRect();
    return { x0: r.left + 6, y0: r.top + 6, x1: r.left + r.width * 0.6, y1: r.top + r.height * 0.95 };
  });
  const drawBox = async () => {
    await page.mouse.move(area.x0, area.y0);
    await page.mouse.down();
    await page.mouse.move(area.x1, area.y1, { steps: 5 });
    await page.mouse.up();
  };
  await drawBox();
  assert.match(await page.textContent('#item h2'), /\(\+\d+ selected\)/);
  await page.keyboard.press('Escape');

  // While a group command waits for its area, the box answers it (editor-core's draw_box).
  await page.click('#palette button:text-is("Move area")');
  await drawBox();
  assert.match(await page.textContent('#prompt'), /^Enter destination staff/);
  await page.click('#prompt-cancel');
  assert.ok(await page.isHidden('#prompt'));

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
