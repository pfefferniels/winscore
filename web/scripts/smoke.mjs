// End-to-end check of the built app (dist/) in headless Chromium: open a
// sample, click a staff line, edit a parameter, drag handles and guides,
// save; start a new score.
// Then the same app on a phone: its layout, touch gestures and music input
// from an on-screen keyboard.
import { chromium } from 'playwright';
import { preview } from 'vite';
import assert from 'node:assert/strict';
import fs from 'node:fs';

const server = await preview({ preview: { port: 4178, strictPort: true } });
const browser = await chromium.launch({ executablePath: process.env.CHROMIUM || undefined });
try {
  const page = await browser.newPage({ viewport: { width: 1400, height: 900 }, acceptDownloads: true });
  const errors = [];
  page.on('pageerror', (err) => errors.push(err.message));
  /** Runs the entry `action` (its `data-action`) of menu `menu`. */
  const menu = async (name, action) => {
    await page.click(`#menu-${name}`);
    await page.click(`.menu-popup [data-action="${action}"]`);
  };

  // Without a sample in the URL the start screen offers a new score, a file and the samples.
  await page.goto('http://localhost:4178/');
  await page.waitForSelector('#app[data-ready="true"]');
  assert.ok(await page.isVisible('#start'));
  assert.ok(await page.isHidden('#panel'));
  assert.ok(await page.isDisabled('#input'));
  assert.ok(await page.isVisible('.start-samples button:text-is("mozart.mus")'));

  // A new score is empty; music input on it creates staff 1 as the engine's IN 1 does.
  await page.click('#start-new');
  assert.ok(await page.isHidden('#start'));
  assert.equal(await page.textContent('#status'), 'untitled.mus');
  assert.equal(await page.textContent('#item-count'), '0');
  assert.ok(await page.isVisible('#empty-hint'));
  await page.click('#empty-input');
  assert.ok(await page.isHidden('#empty-hint'));
  assert.equal(await page.getAttribute('#input', 'aria-pressed'), 'true');
  assert.equal(await page.inputValue('#input-staff'), '1');
  await page.keyboard.type('C4/D/E/F');
  await page.waitForFunction(() => document.getElementById('input-status').textContent === 'Adds 5 items');
  await page.keyboard.press('Control+Enter');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '5');
  await page.click('#input');
  assert.ok(await page.isHidden('#input-panel'));
  assert.equal(await page.textContent('#doc-state'), 'Unsaved changes');
  const [fresh] = await Promise.all([page.waitForEvent('download'), menu('file', 'save')]);
  assert.equal(fresh.suggestedFilename(), 'untitled.mus');
  const freshBytes = fs.readFileSync(await fresh.path());
  assert.equal(freshBytes.readUInt16LE(0) * 4 + 2, freshBytes.length);
  assert.equal(await page.textContent('#doc-state'), '');

  // Opening another score asks before unsaved changes are thrown away.
  await page.click('#items li[data-index="1"]');
  await page.keyboard.press('Delete');
  assert.equal(await page.textContent('#item-count'), '4');
  page.once('dialog', (dialog) => dialog.dismiss());
  await menu('file', 'new');
  assert.equal(await page.textContent('#item-count'), '4');
  page.once('dialog', (dialog) => dialog.accept());
  await menu('file', 'new');
  assert.equal(await page.textContent('#item-count'), '0');

  // Menus work from the keyboard: ↓ opens, arrows move, Escape closes.
  await page.focus('#menu-file');
  await page.keyboard.press('ArrowDown');
  assert.equal(await page.evaluate(() => document.activeElement.dataset.action), 'new');
  await page.keyboard.press('ArrowDown');
  assert.equal(await page.evaluate(() => document.activeElement.dataset.action), 'open');
  await page.keyboard.press('ArrowRight');
  assert.equal(await page.getAttribute('#menu-edit', 'aria-expanded'), 'true');
  await page.keyboard.press('Escape');
  assert.equal(await page.locator('.menu-popup').count(), 0);
  assert.equal(await page.evaluate(() => document.activeElement.id), 'menu-edit');

  await page.goto('http://localhost:4178/?sample=mozart.mus&zoom=400');
  await page.waitForSelector('#app[data-ready="true"]');

  // At 400 % the staff does not fit, so selecting it from the list scrolls it
  // to the middle of the view. Clicks down the centre column then hit one of
  // its lines (spaced about 33 px at this zoom).
  await page.click('#items li[data-index="2"]');
  assert.equal(await page.textContent('#item h2'), 'Item 2 · Staff');
  await page.keyboard.press('Escape');
  assert.equal(await page.textContent('#item h2'), 'Nothing selected');
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
  assert.ok(titles.includes('Nothing selected'));
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

  // The panel's buttons send WinScore's edit-mode commands to the selection.
  await page.click('#item [data-command="U1"]');
  assert.equal(await page.inputValue('#p4'), '25');
  await page.click('#undo');
  assert.equal(await page.inputValue('#p4'), '24');

  // The panel's settings read and write a note's packed parameters: item 4 is
  // a beamed sixteenth G2 (P4 3), stem up (P5 10), after a bass clef.
  const params = (...ns) => Promise.all(ns.map(async (n) => (await page.inputValue(`#all-p${n}`)) || '0'));
  await page.click('#items li[data-index="4"]');
  assert.equal(await page.inputValue('#f-pitch'), 'G2');
  await page.fill('#f-pitch', 'F#3');
  await page.press('#f-pitch', 'Enter');
  assert.equal(await page.inputValue('#f-pitch'), 'F♯3');
  assert.deepEqual(await params(4, 5), ['9', '12']);
  assert.match(await page.getAttribute('#undo', 'title'), /^Undo Set P4, P5 /);
  await page.click('#f-stem-2');
  assert.deepEqual(await params(5), ['22']);
  await page.selectOption('#f-value', { label: 'Eighth' });
  assert.deepEqual(await params(6, 7, 9), ['0', '0.5', '0']);
  await page.click('#f-dots-1');
  assert.deepEqual(await params(7, 9), ['0.75', '10']);
  for (let i = 0; i < 4; i++) await page.click('#undo');
  assert.deepEqual(await params(4, 5, 7), ['3', '10', '0.25']);

  // Several selected items are edited together: shared settings show what they agree on, "Mixed"
  // where they differ, and a change goes to every one as one undo step; ↑/↓ step each on its own.
  await page.click('#items li[data-index="7"]', { modifiers: ['Shift'] });
  assert.match(await page.textContent('#item h2'), /^2 items/);
  assert.equal(await page.inputValue('#f-pitch'), '');
  assert.equal(await page.getAttribute('#f-pitch', 'placeholder'), 'Mixed');
  await page.selectOption('#f-value', { label: 'Eighth' });
  assert.equal(await page.inputValue('#all-p7'), '0.5');
  assert.match(await page.getAttribute('#undo', 'title'), /^Undo Set .* of 2 items /);
  await page.click('#undo');
  const before = await params(4);
  await page.focus('#f-pitch');
  await page.keyboard.press('ArrowUp');
  await page.click('#undo');
  assert.deepEqual(await params(4), before);
  // A mixed selection offers the kinds as buttons that narrow it to one.
  await page.click('#items li[data-index="3"]', { modifiers: ['Shift'] });
  assert.match(await page.textContent('#item h2'), /^3 items/);
  assert.equal(await page.locator('.item-kinds button').count(), 2);
  await page.click('.item-kinds button:has-text("Note")');
  assert.match(await page.textContent('#item h2'), /^2 items · Note/);
  await page.click('#items li[data-index="2"]');

  // The menus send WinScore's toolbar commands; TREB appends a treble clef and selects it.
  await menu('insert', 'TREB');
  assert.equal(await page.textContent('#item-count'), '345');
  assert.match(await page.textContent('#item h2'), /^Item 344 · Clef/);
  await page.keyboard.press('Control+z');
  assert.equal(await page.textContent('#item-count'), '344');
  await page.click('#items li[data-index="2"]');

  // The item list filters by kind or number.
  await page.fill('#item-filter', 'clef');
  assert.match(await page.textContent('#item-count'), /^\d+ of 344$/);
  assert.ok(await page.isHidden('#items li[data-index="2"]'));
  await page.fill('#item-filter', '8');
  assert.ok(await page.isVisible('#items li[data-index="2"]'));
  await page.press('#item-filter', 'Escape');
  assert.equal(await page.textContent('#item-count'), '344');

  // Delete and undo it.
  await page.click('#items li[data-index="3"]');
  assert.equal(await page.textContent('#item h2'), 'Item 3 · Clef');
  await page.keyboard.press('Delete');
  assert.equal(await page.textContent('#item-count'), '343');
  await page.keyboard.press('Control+z');
  assert.equal(await page.textContent('#item-count'), '344');
  assert.equal(await page.textContent('#item h2'), 'Item 3 · Clef');

  // Ctrl+C and Ctrl+V: the copy lands beside its original, selected, as one undo step; after a click
  // on the page it lands there. Edit ▸ Duplicate copies without the clipboard. Another tab pastes
  // from the system clipboard, in place.
  await page.context().grantPermissions(['clipboard-read', 'clipboard-write']);
  await page.click('#items li[data-index="4"]');
  const noteP3 = Number(await page.inputValue('#p3'));
  await page.keyboard.press('Control+c');
  assert.equal(await page.textContent('#message'), 'Copied 1 item');
  await page.keyboard.press('Control+v');
  assert.equal(await page.textContent('#item-count'), '345');
  assert.equal(await page.textContent('#item h2'), 'Item 344 · Note');
  assert.ok(Math.abs(Number(await page.inputValue('#p3')) - (noteP3 + 10)) < 1e-6);
  assert.match(await page.getAttribute('#undo', 'title'), /^Undo Paste /);
  await page.mouse.click(onStaff.x, onStaff.y);
  const clickedX = Number(/^x (\d+)/.exec(await page.textContent('#cursor'))[1]);
  await page.keyboard.press('Control+v');
  assert.equal(await page.textContent('#item h2'), 'Item 345 · Note');
  assert.ok(Math.abs(Number(await page.inputValue('#p3')) - (clickedX - 2000) / 150) < 0.02);
  await menu('edit', 'duplicate');
  assert.equal(await page.textContent('#item-count'), '347');
  const otherTab = await browser.newPage({ permissions: ['clipboard-read', 'clipboard-write'] });
  await otherTab.goto('http://localhost:4178/?new');
  await otherTab.waitForSelector('#app[data-ready="true"]');
  await otherTab.focus('#viewport');
  await otherTab.keyboard.press('Control+v');
  assert.equal(await otherTab.textContent('#item h2'), 'Item 0 · Note');
  assert.ok(Math.abs(Number(await otherTab.inputValue('#p3')) - noteP3) < 1e-6);
  await otherTab.close();
  await page.bringToFront();
  for (let i = 0; i < 3; i++) await page.keyboard.press('Control+z');
  assert.equal(await page.textContent('#item-count'), '344');

  await page.click('#items li[data-index="2"]');
  await page.fill('#p5', '1.2');
  await page.press('#p5', 'Enter');
  assert.equal(await page.textContent('#doc-state'), 'Unsaved changes');
  assert.equal(await page.inputValue('#p5'), '1.2');

  const [download] = await Promise.all([page.waitForEvent('download'), page.keyboard.press('Control+s')]);
  const saved = fs.readFileSync(await download.path());
  const original = fs.readFileSync('../WINSCORE 5.01/winscore/mozart.mus');
  assert.equal(saved.length, original.length);
  assert.notDeepEqual(saved, original);

  // SVG export downloads the printed page; Print paints it alone for the print stylesheet.
  const [svgDownload] = await Promise.all([page.waitForEvent('download'), menu('file', 'export-svg')]);
  assert.equal(svgDownload.suggestedFilename(), 'mozart.svg');
  const svg = fs.readFileSync(await svgDownload.path(), 'utf8');
  assert.match(svg, /^<svg[^>]*width="8.5in"/);
  await page.evaluate(() => (window.print = () => (document.body.dataset.printed = 'yes')));
  await menu('file', 'print');
  await page.waitForSelector('body[data-printed="yes"]', { state: 'attached' });
  assert.deepEqual(await page.evaluate(() => [...document.querySelectorAll('#print-page canvas')].map((c) => [c.width, c.height])), [[2550, 4200]]);
  await page.emulateMedia({ media: 'print' });
  assert.ok(await page.isHidden('#app'));
  assert.ok(await page.isVisible('#print-page canvas'));
  await page.emulateMedia({ media: 'screen' });

  // Music input at a cursor in the music: the line is drawn as it is typed, the bubble at the
  // cursor and the help say what the keys mean; passes 3-5 take note numbers from the cursor.
  await page.click('#input');
  assert.ok(await page.isVisible('#input-panel'));
  assert.equal(await page.inputValue('#input-staff'), '9');
  await page.keyboard.type('G');
  await page.waitForFunction(() => document.querySelector('.input-bubble .bubble-shown')?.textContent === 'G4, quarter');
  assert.match(await page.textContent('#input-help h3'), /^Note G/);
  assert.match(await page.textContent('#input-help .help-keys'), /octave/);
  await page.keyboard.type('5/K2');
  await page.waitForFunction(() => document.querySelector('#input-help h3')?.textContent === 'Key signature, 2 accidentals');
  assert.match(await page.textContent('#input-help .help-status'), /^Not finished/);
  assert.equal(await page.textContent('#pass-error-1'), '');
  await page.keyboard.press('Escape');
  await page.keyboard.press('Control+Backspace');
  await page.keyboard.type('C4/D/E/F');
  await page.waitForFunction(() => document.getElementById('pass-code-1').textContent === 'C4/D/E/F;');
  await page.keyboard.press('Enter');
  await page.keyboard.type('4/Y');
  await page.waitForFunction(() => document.getElementById('pass-error-2').textContent !== '');
  assert.ok(await page.isDisabled('#input-insert'));
  await page.keyboard.press('Backspace');
  await page.keyboard.press('Backspace');
  await page.waitForFunction(() => document.getElementById('input-status').textContent === 'Adds 5 items');
  await page.keyboard.press('Enter');
  await page.keyboard.press('ArrowRight');
  await page.keyboard.type('S/');
  await page.waitForFunction(() => document.getElementById('pass-code-3').textContent === 'S 2;');
  await page.keyboard.press('Control+Enter');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '349');
  assert.match(await page.textContent('#item h2'), /^5 items/);
  assert.equal(await page.textContent('#pass-code-1'), ';');
  assert.equal(await page.inputValue('#input-staff'), '10');
  await page.keyboard.press('Escape');
  assert.ok(await page.isHidden('#input-panel'));
  await page.click('#undo');
  assert.equal(await page.textContent('#item-count'), '344');
  // IN n on the command bar opens the input on staff n.
  await page.fill('#command', 'IN 3');
  await page.press('#command', 'Enter');
  assert.ok(await page.isVisible('#input-panel'));
  assert.equal(await page.inputValue('#input-staff'), '3');
  await page.click('#input-close');
  assert.ok(await page.isHidden('#input-panel'));

  // Text: Insert ▸ Text opens the dialog; the font goes in front as _NN.
  await page.click('#items li[data-index="2"]');
  await menu('insert', 'text');
  await page.fill('#text-value', 'Allegro');
  await page.selectOption('#text-font', '1');
  await page.click('#text-insert');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '345');
  assert.match(await page.textContent('#item h2'), /^Item 344 · Text/);
  assert.equal(await page.inputValue('#item-text'), '_01Allegro');
  await page.fill('#item-text', '_01Allegro vivace');
  await page.press('#item-text', 'Enter');
  assert.match(await page.textContent('#message'), /^Edit text/);
  assert.equal(await page.inputValue('#item-text'), '_01Allegro vivace');
  await page.click('#undo');
  await page.click('#undo');
  assert.equal(await page.textContent('#item-count'), '344');

  // Symbol picker: a searchable grid of library symbols drawn by the renderer.
  await page.click('#items li[data-index="2"]');
  await menu('insert', 'symbol');
  await page.waitForSelector('#symbol-grid .symbol-cell');
  const symbol = await page.getAttribute('#symbol-grid .symbol-cell:nth-child(2)', 'data-number');
  await page.fill('#symbol-search', 'no symbol is called this');
  assert.equal(await page.textContent('#symbol-count'), '0 symbols');
  await page.fill('#symbol-search', '');
  await page.click('#symbol-grid .symbol-cell:nth-child(2)');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '345');
  assert.match(await page.textContent('#item h2'), /^Item 344 · Symbol/);
  assert.equal(await page.inputValue('#p5'), symbol);
  await page.click('#undo');

  // Group edit: the command asks for the area, then the destination; Cancel ends it.
  await menu('edit', 'M');
  assert.match(await page.textContent('#prompt'), /^Enter staff, left position/);
  await page.keyboard.type('1 0 200 2');
  await page.keyboard.press('Enter');
  assert.match(await page.textContent('#prompt'), /^Enter destination staff/);
  await page.click('#prompt-cancel');
  assert.ok(await page.isHidden('#prompt'));
  assert.equal(await page.textContent('#item-count'), '344');

  // Layout: LJ asks for the system, answered on the command bar; the result is one undo step.
  await menu('layout', 'LJ');
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
  await page.goto('http://localhost:4178/?sample=mozart.mus');
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
  assert.match(await page.textContent('#item h2'), /^\d+ items/);
  await page.keyboard.press('Escape');

  // While a group command waits for its area, the box answers it (editor-core's draw_box).
  await menu('edit', 'M');
  await drawBox();
  assert.match(await page.textContent('#prompt'), /^Enter destination staff/);
  await page.click('#prompt-cancel');
  assert.ok(await page.isHidden('#prompt'));

  // Handles: the page lists the selected item's handles (data-handles, client pixels). A slur's
  // curve handle sets its curvature live and as one undo step; Escape cancels a handle drag.
  const viewportData = async (name) => JSON.parse((await page.getAttribute('#viewport', `data-${name}`)) || 'null');
  await page.goto('http://localhost:4178/?sample=mozart.mus&zoom=300&select=38');
  await page.waitForSelector('#app[data-ready="true"]');
  const slurHandles = await viewportData('handles');
  assert.deepEqual(slurHandles.map((h) => h.label), ['Start', 'End', 'Curve']);
  const curve = slurHandles.find((h) => h.label === 'Curve');
  assert.equal(await page.inputValue('#p7'), '4');
  await page.mouse.move(curve.x, curve.y);
  await page.mouse.down();
  await page.mouse.move(curve.x, curve.y - 30, { steps: 6 });
  await page.keyboard.press('Escape');
  await page.mouse.up();
  assert.equal(await page.inputValue('#p7'), '4');
  assert.ok(await page.isDisabled('#undo'));
  await page.mouse.move(curve.x, curve.y);
  await page.mouse.down();
  await page.mouse.move(curve.x, curve.y - 30, { steps: 6 });
  await page.mouse.up();
  assert.match(await page.textContent('#message'), /^Curve · Item 38 /);
  assert.ok(Number(await page.inputValue('#p7')) > 5, 'the curve rose');
  assert.match(await page.getAttribute('#undo', 'title'), /^Undo Curve /);
  await page.click('#undo');
  assert.equal(await page.inputValue('#p7'), '4');

  // Guides: the p on staff 2 dragged down snaps to the level of the cresc. on staff 4 and says so;
  // with Ctrl held while dragging nothing snaps.
  await page.goto('http://localhost:4178/?sample=mozart.mus&zoom=200&select=78');
  await page.waitForSelector('#app[data-ready="true"]');
  const dynamic = await viewportData('selection');
  const grab = { x: dynamic.x + dynamic.width / 2, y: dynamic.y + dynamic.height / 2 };
  await page.mouse.move(grab.x, grab.y);
  await page.mouse.down();
  await page.mouse.move(grab.x, grab.y + 10, { steps: 4 });
  await page.mouse.move(grab.x + 2, grab.y + 24, { steps: 4 });
  const guides = await viewportData('guides');
  assert.ok(guides.some((g) => g.axis === 'y' && g.music && /as on staff 4/.test(g.label)), JSON.stringify(guides));
  await page.mouse.up();
  assert.equal(await page.inputValue('#p4'), '-5');
  await page.click('#undo');
  await page.mouse.move(grab.x, grab.y);
  await page.mouse.down();
  await page.keyboard.down('Control');
  await page.mouse.move(grab.x, grab.y + 10, { steps: 4 });
  await page.mouse.move(grab.x + 2, grab.y + 24, { steps: 4 });
  assert.deepEqual(await viewportData('guides'), []);
  await page.mouse.up();
  await page.keyboard.up('Control');
  assert.notEqual(await page.inputValue('#p4'), '-5');
  await page.click('#undo');

  assert.deepEqual(errors, []);

  // On a phone: one Menu button for the menus, the panel hidden until asked for.
  const phone = await browser.newContext({ viewport: { width: 390, height: 844 }, isMobile: true, hasTouch: true });
  const mobile = await phone.newPage();
  mobile.on('pageerror', (err) => errors.push(err.message));
  const cdp = await phone.newCDPSession(mobile);
  /** One finger (or two) at client points, as the touch screen reports them. */
  const touch = (type, points) => cdp.send('Input.dispatchTouchEvent', { type, touchPoints: points.map(([x, y], id) => ({ x, y, id })) });
  const swipe = async (from, to, hold = 0) => {
    await touch('touchStart', [from]);
    if (hold) await mobile.waitForTimeout(hold);
    for (let i = 1; i <= 6; i++) await touch('touchMove', [[from[0] + ((to[0] - from[0]) * i) / 6, from[1] + ((to[1] - from[1]) * i) / 6]]);
    await touch('touchEnd', []);
  };
  const scrolled = () => mobile.evaluate(() => document.getElementById('viewport').scrollTop);
  await mobile.goto('http://localhost:4178/?sample=mozart.mus&zoom=400&select=2');
  await mobile.waitForSelector('#app[data-ready="true"]');
  assert.ok(await mobile.evaluate(() => document.querySelector('.appbar').scrollWidth <= innerWidth));
  assert.ok(await mobile.isHidden('#panel'));
  assert.ok(await mobile.isHidden('#menu-file'));
  assert.match(await mobile.textContent('#message'), /^Item 2 Staff/);

  // A tap selects; taps down the centre column find the staff, as the clicks above did.
  const middle = await mobile.evaluate(() => {
    const r = document.getElementById('viewport').getBoundingClientRect();
    return [r.left + r.width / 2, r.top + r.height / 2];
  });
  let staffAt = null;
  for (let dy = -120; dy <= 120 && staffAt === null; dy += 12) {
    await touch('touchStart', [[middle[0], middle[1] + dy]]);
    await touch('touchEnd', []);
    if ((await mobile.textContent('#message')).startsWith('Item 2 Staff')) staffAt = [middle[0], middle[1] + dy];
  }
  assert.ok(staffAt, 'a tap selects the staff');

  // A finger dragged from the selected staff moves it; undo puts it back.
  await swipe(staffAt, [staffAt[0] + 60, staffAt[1]]);
  assert.match(await mobile.textContent('#message'), /^Drag · Item 2 Staff: 8 1 [1-9]/);
  await mobile.locator('#undo').tap();
  assert.match(await mobile.textContent('#message'), /^Undo Drag · Item 2 Staff: 8 1 0 /);

  // Elsewhere it pans, and the selection stays; two fingers pinch the zoom.
  const top = await scrolled();
  await swipe([middle[0], middle[1] + 150], [middle[0], middle[1] + 30]);
  assert.ok((await scrolled()) >= top + 100, 'a drag on the paper pans');
  assert.match(await mobile.textContent('#message'), /Item 2 Staff/);
  await touch('touchStart', [[middle[0] - 80, middle[1]], [middle[0] + 80, middle[1]]]);
  for (let i = 1; i <= 6; i++) await touch('touchMove', [[middle[0] - 80 + 10 * i, middle[1]], [middle[0] + 80 - 10 * i, middle[1]]]);
  await touch('touchEnd', []);
  await mobile.waitForFunction(() => document.getElementById('zoom').value === '100');

  // A long press and a drag select a box; a quick drag leaves the next tap a click.
  await mobile.goto('http://localhost:4178/?sample=mozart.mus');
  await mobile.waitForSelector('#app[data-ready="true"]');
  const sheet = await mobile.evaluate(() => {
    const r = document.getElementById('viewport').getBoundingClientRect();
    return [r.left + 8, r.top + 8, r.left + r.width * 0.8, r.top + r.height * 0.9];
  });
  await swipe([sheet[0], sheet[1]], [sheet[2], sheet[3]], 600);
  assert.match(await mobile.textContent('#item h2'), /^\d+ items/);

  // The Menu button opens the menus across the screen, their titles as tabs.
  await mobile.locator('#menu-compact').tap();
  assert.deepEqual(await mobile.evaluate(() => [document.querySelector('.menu-popup').getBoundingClientRect().left, innerWidth - document.querySelector('.menu-popup').getBoundingClientRect().right]), [8, 8]);
  await mobile.locator('.menu-tab[data-menu="insert"]').tap();
  await mobile.locator('.menu-popup [data-action="input"]').tap();

  // Music input takes the on-screen keyboard's text through its typing field, and the keys it lacks from buttons.
  assert.ok(await mobile.isHidden('#footer'));
  assert.equal(await mobile.evaluate(() => document.activeElement.id), 'input-typing');
  await mobile.keyboard.insertText('c4');
  await mobile.locator('.touch-keys [data-key="/"]').tap();
  await mobile.keyboard.insertText('d/e/f');
  await mobile.waitForFunction(() => document.getElementById('input-status').textContent === 'Adds 5 items');
  await mobile.keyboard.press('Backspace');
  await mobile.waitForFunction(() => document.getElementById('input-status').textContent === 'Adds 4 items');
  assert.equal(await mobile.evaluate(() => document.activeElement.id), 'input-typing', 'the keys leave the keyboard up');
  await mobile.locator('.touch-keys [data-key="Enter"]').tap();
  await mobile.waitForSelector('#pass-2.active');
  await mobile.locator('#input-shift').tap();
  await mobile.locator('.touch-keys [data-key="Enter"]').tap();
  await mobile.waitForSelector('#pass-1.active');
  assert.equal(await mobile.getAttribute('#input-shift', 'aria-pressed'), 'false');
  await mobile.locator('#pass-2').tap();
  await mobile.waitForSelector('#pass-2.active');
  await mobile.locator('#input-insert').tap();
  await mobile.waitForFunction(() => document.getElementById('item-count').textContent === '348');
  assert.equal(await mobile.evaluate(() => document.activeElement.id), 'input-typing', 'a tap on the panel leaves the keyboard up');
  await phone.close();
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
