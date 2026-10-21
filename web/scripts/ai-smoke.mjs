// End-to-end check of the command field in the built app (dist/), with Jev
// and Claude answered by canned replies at the network: a selection brings
// the field, typing on the page goes into it, what Jev reads is shown and
// tried on the score while typing, Enter keeps it as one undo step, a slider re-does it, a
// command Jev cannot read goes to Claude (a complex one to Opus), while Claude
// writes other commands run on other items, and a click on empty paper opens
// the field where music it adds then goes.
//
// usage: npm run build && node scripts/ai-smoke.mjs
// CHROMIUM=/path/to/chrome uses that browser instead of Playwright's own.
import { chromium } from 'playwright';
import { preview } from 'vite';
import assert from 'node:assert/strict';

const PORT = 4179;
const server = await preview({ preview: { port: PORT, strictPort: true } });
const browser = await chromium.launch({ executablePath: process.env.CHROMIUM || undefined });

/** What Jev picks for each command; questions not named here get "none" or their first option. */
const JEV = {
  'remove the stems': { action: 'delete', target: 'stems' },
  'remove the stem': { action: 'delete', target: 'stems' },
  'add staff': { action: 'create', item: 'staff' },
  'zoom in': { action: 'app', menu: 'zoom-in' },
  'repeat it twice': { action: 'repeat', amount: 'twice' },
  'do that again': { action: 'again' },
  'beam always 2 notes': { action: 'beam', target: 'notes', group: '2', amount: '2' },
  'make note size gradually bigger': { action: 'grow', target: 'notes', measure: 'size' },
  'make the last note an x head': { action: 'other', target: 'notes' },
  'make the bottom notes of the chords smaller': { action: 'other', target: 'notes' },
  'add notes c g d/f/a': { action: 'insert', target: 'all' },
  'add c5 d e f g a b c6 8': { action: 'insert', target: 'all' },
  'double the melody a third below': { action: 'other', target: 'notes', complexity: 'complex' },
  'could you make it smaller on screen': { action: 'other' },
};

/** A step as Claude writes it, every field given. */
const step = (fields) => ({
  do: 'setting', codes: [], where: '', where_setting: '', where_is: '', setting: '', param: 0, value: '',
  right: '', up: '', line: '', staff: 0, from: 0, to: 0, notes: '', rhythms: '', marks: '', beams: '', slurs: '', size: '', params: [],
  ...fields,
});

/** Claude's scripts for the commands Jev gives up on: its first try, and its second when the first fails to run. */
const CLAUDE = {
  'make the last note an x head': [{ summary: 'Last note with an X head', knobs: [], steps: [step({ codes: [1], where: 't == 1', setting: 'Head', value: 'X' })] }],
  'make the bottom notes of the chords smaller': [
    { summary: 'Smaller bottom notes', knobs: [], steps: [step({ codes: [1], where: 'level < mean', setting: 'Size', value: '0.8' })] },
    { summary: 'Smaller bottom notes', knobs: [], steps: [step({ codes: [1], where: 'level == chord_low', setting: 'Size', value: '0.8' })] },
  ],
  'double the melody a third below': [{ summary: 'A third below', knobs: [], steps: [step({ do: 'add', codes: [1], params: ['1', 'staff', 'x', 'level - 2', 'p5', 'p6', 'p7'] })] }],
  'could you make it smaller on screen': [{ summary: 'Zoom out', command: 'zoom-out', knobs: [], steps: [] }],
};

/** Claude's (and Jev's) replies held back until the check lets them go, by command. */
const held = new Map();
const heldJev = new Map();
const hold = (text, replies = held) => {
  let release;
  replies.set(text, new Promise((resolve) => (release = resolve)));
  return release;
};

const cors = { 'access-control-allow-origin': '*', 'access-control-allow-headers': '*', 'access-control-allow-methods': 'POST, OPTIONS' };
const jevRequests = [];
let warmUps = 0;

function jevAnswers(body) {
  const picks = JEV[body.state.command] ?? { action: 'other' };
  const answers = {};
  for (const [id, q] of Object.entries(body.questions)) {
    if (q.type === 'noul') {
      answers[id] = { type: 'noul', noul: 0.9 };
      continue;
    }
    const keys = Object.keys(q.criteria);
    const choice = picks[id] ?? (keys.includes('none') ? 'none' : keys[0]);
    assert.ok(keys.includes(choice), `${id}: ${choice} is among ${keys.join(', ')}`);
    answers[id] = { type: 'choice', choice, probabilities: { [choice]: 0.94 }, confidence: 0.9 };
  }
  return { model: 'jev-1.13.0', answers, usage: { input_tokens: 300, output_tokens: 20 } };
}

function claudeMessage(body) {
  const tries = CLAUDE[/^Command: (.*)$/m.exec(body.messages[0].content)[1]];
  const script = tries[Math.min((body.messages.length - 1) / 2, tries.length - 1)];
  return {
    id: 'msg_test',
    type: 'message',
    role: 'assistant',
    model: 'claude-sonnet-5-5',
    content: [{ type: 'text', text: JSON.stringify(script) }],
    stop_reason: 'end_turn',
    stop_details: null,
    usage: { input_tokens: 4000, output_tokens: 120 },
  };
}

try {
  const page = await browser.newPage({ viewport: { width: 1400, height: 900 } });
  const errors = [];
  page.on('pageerror', (err) => errors.push(err.message));
  await page.addInitScript(() => {
    localStorage.setItem('winscore.ai', JSON.stringify({ jevKey: 'test', jevUrl: 'https://api.typesafe.ai/v1/systemone', claudeKey: 'test' }));
  });
  await page.route('https://api.typesafe.ai/v1/systemone', async (route) => {
    if (route.request().method() === 'OPTIONS') return route.fulfill({ status: 204, headers: cors });
    const body = route.request().postDataJSON();
    if (body.state === 'warm-up') warmUps++;
    else jevRequests.push(body);
    await heldJev.get(body.state.command);
    await route.fulfill({ status: 200, headers: { ...cors, 'content-type': 'application/json' }, body: JSON.stringify(jevAnswers(body)) });
  });
  let claudeRequest = null;
  const claudeRequests = [];
  await page.route('https://api.anthropic.com/**', async (route) => {
    if (route.request().method() === 'OPTIONS') return route.fulfill({ status: 204, headers: cors });
    const request = route.request().postDataJSON();
    claudeRequest = request;
    claudeRequests.push(request);
    await held.get(/^Command: (.*)$/m.exec(request.messages[0].content)[1]);
    // A cancelled command's request is gone by now.
    await route.fulfill({ status: 200, headers: { ...cors, 'content-type': 'application/json' }, body: JSON.stringify(claudeMessage(request)) }).catch(() => {});
  });

  // Eight eighth notes on a new score, typed in the command field at a click on its paper: they make staff 1.
  await page.goto(`http://localhost:${PORT}/?new`);
  await page.waitForSelector('#app[data-ready="true"]');
  const paper = await page.locator('#viewport').boundingBox();
  await page.mouse.click(paper.x + paper.width / 2, paper.y + 160);
  await page.waitForSelector('.ai-prompt:not([hidden])');
  await page.fill('.ai-input', 'add c5 d e f g a b c6 8');
  await page.waitForFunction(() => /→ Add c5 d e f g a b c6 8/.test(document.querySelector('.ai-status').textContent) && !document.querySelector('.ai-status.busy'));
  await page.press('.ai-input', 'Enter');
  await page.waitForFunction(() => document.getElementById('app').dataset.items === '9');

  /** Two frames: a paint already asked for (an undo's, say) has then happened. */
  const painted = () => page.evaluate(() => new Promise((done) => requestAnimationFrame(() => requestAnimationFrame(done))));
  /** The selection's box on screen once the page has painted it after `act` (it is written on paint). */
  const selectedBox = async (act) => {
    await painted();
    const before = await page.getAttribute('#viewport', 'data-selection');
    await act();
    await page.waitForFunction((b) => {
      const now = document.getElementById('viewport').dataset.selection;
      return now && now !== b;
    }, before);
    await painted();
    return JSON.parse(await page.getAttribute('#viewport', 'data-selection'));
  };
  /** The selection's box on screen after `act`, which may leave it as it was (a command tried while typed has selected what it changes already). */
  const boxAfter = async (act) => {
    await act();
    await painted();
    return JSON.parse(await page.getAttribute('#viewport', 'data-selection'));
  };

  /** Runs a SCORE command line typed on the page, as `I n` to select item n (from 1), and gives the keyboard back to the page. */
  const run = async (line) => {
    await page.focus('#viewport');
    await page.keyboard.type(line);
    await page.keyboard.press('Enter');
    await page.keyboard.press('Escape');
  };

  // The box of the notes (items 1 to 8), around the first and the last; Escape on the page deselects them, and the field goes.
  const first = await selectedBox(() => run('I 2'));
  const eighth = await selectedBox(() => run('I 9'));
  const [left, top] = [Math.min(first.x, eighth.x), Math.min(first.y, eighth.y)];
  const right = Math.max(first.x + first.width, eighth.x + eighth.width);
  const bottom = Math.max(first.y + first.height, eighth.y + eighth.height);
  const box = { x: left, y: top, width: right - left, height: bottom - top };
  await page.waitForSelector('.ai-prompt:not([hidden])');
  await page.focus('#viewport');
  await page.keyboard.press('Escape');
  assert.ok(await page.isHidden('.ai-prompt'), 'no selection, no field');

  // A box drawn around the notes selects them, and the field stands by them without taking the keyboard.
  const [x0, y0, x1, y1] = [box.x - 30, box.y - 30, box.x + box.width + 30, box.y + box.height + 30];
  await page.mouse.move(x0, y0);
  await page.mouse.down();
  await page.mouse.move(x1, y1, { steps: 6 });
  await page.mouse.up();
  await page.waitForSelector('.ai-prompt:not([hidden])');
  assert.notEqual(await page.evaluate(() => document.activeElement?.className), 'ai-input');
  assert.equal(await page.textContent('.ai-status'), '', 'the field says nothing before a command');
  for (let i = 0; i < 100 && warmUps === 0; i++) await page.waitForTimeout(20);
  assert.equal(warmUps, 1, 'the field opens the connection to Jev');

  /** A reading of the words in the field, not one of words before them shown while these are read. */
  const read = () => page.waitForFunction(() => /→|Claude( \w+)? write/.test(document.querySelector('.ai-status').textContent) && !document.querySelector('.ai-status.busy'));
  const command = async (text) => {
    await page.fill('.ai-input', text);
    await read();
  };
  const enter = async () => {
    await page.press('.ai-input', 'Enter');
    await page.waitForFunction(() => /✓|nothing changed/.test(document.querySelector('.ai-status').textContent) || document.querySelector('.ai-status.error'));
  };
  /** P1 … Pn of the selected item the status line shows, by number. */
  const shownParams = async () => {
    const line = await page.textContent('#message');
    const params = line.split(': ').at(-1).trim().split(/\s+/).map(Number);
    return (n) => params[n - 1] ?? 0;
  };

  // Typed on the page, the command goes into the field, every keystroke read at once: while the words typed last
  // are read, the reading of those before shows with the spinner. What Jev read shows before Enter, and Enter
  // edits the score as one undo step.
  const letJevGo = hold('remove the stems', heldJev);
  const typedFrom = jevRequests.length;
  await page.keyboard.type('remove the stems');
  assert.equal(await page.inputValue('.ai-input'), 'remove the stems');
  await page.waitForFunction(() => /Remove stems/.test(document.querySelector('.ai-status.busy .ai-reading')?.textContent ?? ''));
  assert.equal(jevRequests.length - typedFrom, 'remove the stems'.length, 'one request for each keystroke');
  // The reading of the words before is tried on the score already.
  await page.waitForSelector('.ai-prompt[data-tried="Remove stems"]');
  letJevGo();
  await read();
  assert.match(await page.textContent('.ai-reading'), /Remove stems · 8 items/);
  assert.match(await page.textContent('.ai-source'), /^Jev 90 %/);
  assert.equal(jevRequests.at(-1).model, 'jev-latest');
  assert.ok(jevRequests.at(-1).questions['option.1'], 'a property question for notes');
  await enter();
  assert.match(await page.textContent('.ai-status'), /✓ Remove stems/);
  assert.equal(await page.getAttribute('#undo', 'title'), 'Undo “remove the stems” (⌘Z)'.replace('⌘', (await page.evaluate(() => navigator.platform.startsWith('Mac'))) ? '⌘' : 'Ctrl+'));
  assert.equal(Math.floor((await shownParams())(5) / 10) % 10, 0, 'no stem');
  assert.equal(await page.inputValue('.ai-input'), '');

  // Beams in pairs, then fours with the slider: still one undo step.
  await command('beam always 2 notes');
  await enter();
  assert.equal(await page.getAttribute('#app', 'data-items'), '13');
  const size = page.locator('.ai-knob input[aria-label="Notes per beam"]');
  assert.equal(await size.inputValue(), '2');
  await size.fill('4');
  await page.waitForFunction(() => document.getElementById('app').dataset.items === '11');
  assert.match(await page.getAttribute('#undo', 'title'), /“beam always 2 notes”/);

  // Sizes growing from left to right, with three sliders.
  await command('make note size gradually bigger');
  assert.match(await page.textContent('.ai-reading'), /Size grows/);
  await enter();
  assert.equal(await page.locator('.ai-knob').count(), 3);
  const to = page.locator('.ai-knob input[aria-label="To"]');
  await to.fill('3');
  await page.waitForFunction(() => document.getElementById('message').textContent.includes('3'));
  const grown = await shownParams();
  assert.equal(grown(15), 3, 'the last note reaches the final size');

  // Jev is not sure: Enter has Claude write the edit, which runs the same way.
  await command('make the last note an x head');
  assert.match(await page.textContent('.ai-reading'), /not one of Jev’s actions: ↵ has Claude write it/);
  await enter();
  assert.match(await page.textContent('.ai-status'), /✓ Last note with an X head/);
  assert.match(await page.textContent('.ai-source'), /^Claude Sonnet/);
  assert.equal(claudeRequest.model, 'claude-sonnet-5-5', 'Sonnet 5.5 unless another model is picked');
  assert.equal(claudeRequest.output_config.effort, 'low');
  assert.equal(claudeRequest.output_config.format.type, 'json_schema');
  assert.match(claudeRequest.messages[0].content, /Command: make the last note an x head/);

  // A script of Claude's that fails to run goes back to it once, with why.
  await command('make the bottom notes of the chords smaller');
  await enter();
  assert.match(await page.textContent('.ai-status'), /✓ Smaller bottom notes/);
  assert.equal(claudeRequest.messages.length, 3);
  assert.match(claudeRequest.messages[2].content, /Unknown name mean/);

  // A SCORE command needs no model.
  const before = jevRequests.length;
  await command('FLI');
  assert.match(await page.textContent('.ai-reading'), /→ FLI/);
  assert.equal(jevRequests.length, before);

  // Escape gives the keyboard back to the page, the field staying by the selection; undo takes back one command at a time.
  await page.press('.ai-input', 'Escape');
  assert.equal(await page.inputValue('.ai-input'), '');
  assert.equal(await page.evaluate(() => document.activeElement?.id), 'viewport');
  assert.ok(await page.isVisible('.ai-prompt'));
  for (let i = 0; i < 4; i++) await page.keyboard.press('Control+z');
  assert.equal(await page.getAttribute('#app', 'data-items'), '9');
  assert.match(await page.getAttribute('#undo', 'title'), /“remove the stems”/);

  // A click on empty paper above the staff, nothing selected, opens the field there; music it adds starts at the click.
  const staff = await selectedBox(() => run('I 1'));
  await page.keyboard.press('Escape');
  const above = { x: staff.x + staff.width * 0.8, y: staff.y - staff.height / 2 };
  await page.mouse.click(above.x, above.y);
  assert.equal(await page.textContent('#item h2'), 'Nothing selected');
  const field = await page.locator('.ai-prompt').boundingBox();
  assert.ok(Math.abs(field.x - above.x) < 2 && field.y > above.y, `the field (${JSON.stringify(field)}) by the click (${JSON.stringify(above)})`);
  await command('add notes c g d/f/a');
  assert.match(await page.textContent('.ai-reading'), /Add c g d\/f\/a/);
  const placed = await boxAfter(enter);
  assert.equal(await page.getAttribute('#app', 'data-items'), '14');
  assert.match(await page.textContent('#item h2'), /^5 items · Note/);
  assert.ok(Math.abs(placed.x - above.x) < staff.width * 0.05, `the new notes (from x ${placed.x}) start at the click (x ${above.x})`);
  await page.press('.ai-input', 'Control+z');
  assert.equal(await page.getAttribute('#app', 'data-items'), '9');

  // A new item where the field stands: a staff, above the highest as Insert ▸ Staff makes it. And the editor's own
  // commands, the menus' entries: zoom in.
  // What Jev reads is tried on the score at once: Escape takes it back, Enter keeps it.
  await page.mouse.click(above.x, above.y);
  await command('add staff');
  assert.match(await page.textContent('.ai-reading'), /→ Add a staff/);
  await page.waitForSelector('.ai-prompt[data-tried="Add a staff"]');
  await page.press('.ai-input', 'Escape');
  assert.equal(await page.getAttribute('.ai-prompt', 'data-tried'), null);
  await command('add staff');
  await page.waitForSelector('.ai-prompt[data-tried="Add a staff"]');
  await enter();
  assert.equal(await page.getAttribute('.ai-prompt', 'data-tried'), null);
  assert.equal(await page.getAttribute('#app', 'data-items'), '10');
  assert.ok(jevRequests.at(-1).questions.menu.criteria['zoom-in'], 'the menus’ entries are among the answers');
  const zoom = await page.inputValue('#zoom');
  await command('zoom in');
  assert.match(await page.textContent('.ai-reading'), /→ View ▸ Zoom in/);
  await enter();
  assert.match(await page.textContent('.ai-status'), /✓ View ▸ Zoom in/);
  assert.notEqual(await page.inputValue('#zoom'), zoom);
  // Claude may answer with one of them too, which the field runs: it is told those there are.
  const zoomed = await page.inputValue('#zoom');
  await page.fill('.ai-input', 'could you make it smaller on screen');
  await read();
  await page.press('.ai-input', 'Enter');
  await page.waitForFunction(() => /✓ View ▸ Zoom out/.test(document.querySelector('.ai-status').textContent));
  assert.ok(parseFloat(await page.inputValue('#zoom')) < parseFloat(zoomed), 'zoomed out');
  assert.match(claudeRequest.messages[0].content, /zoom-out: View ▸ Zoom out/);
  await page.press('.ai-input', 'Control+z');
  assert.equal(await page.getAttribute('#app', 'data-items'), '9');

  // With the staff selected, music goes after the music on it: right of the last note, on the screen.
  await run('I 1');
  await page.waitForSelector('.ai-prompt:not([hidden])');
  await command('add notes c g d/f/a');
  assert.match(await page.textContent('.ai-reading'), /Add c g d\/f\/a/);
  const added = await boxAfter(enter);
  assert.equal(await page.getAttribute('#app', 'data-items'), '14');
  assert.match(await page.textContent('#item h2'), /^5 items · Note/);
  const last = await selectedBox(() => run('I 9'));
  assert.ok(added.x > last.x + last.width, `the new notes (from x ${added.x}) come after the last one (to x ${last.x + last.width})`);

  // A complex command goes to Opus, and Enter sends it off: the field is free at once.
  const undoTitle = () => page.getAttribute('#undo', 'title');
  /** Waits until the side panel names the selection so: "Item 2 · Note", "14 items". */
  const selection = (pattern) => page.waitForFunction((source) => new RegExp(source).test(document.querySelector('#item h2')?.textContent ?? ''), pattern.source);
  const letGo = hold('double the melody a third below');
  await run('I 2');
  await selection(/^Item \d+ · Note/);
  await command('double the melody a third below');
  assert.match(await page.textContent('.ai-reading'), /↵ has Claude Opus write it/);
  const asked = claudeRequests.length;
  await page.press('.ai-input', 'Enter');
  assert.equal(await page.inputValue('.ai-input'), '');
  await page.waitForSelector('.ai-job.busy .ai-job-source:text("Claude Opus")');
  for (let i = 0; i < 100 && claudeRequests.length === asked; i++) await page.waitForTimeout(20);
  assert.equal(claudeRequest.model, 'claude-opus-5-5');
  assert.equal(claudeRequest.output_config.effort, 'medium');

  // Meanwhile another command runs on other items: everything, the staff and its 13 notes.
  await page.focus('#viewport');
  await page.keyboard.press('Control+a');
  await selection(/^14 items/);
  await page.waitForFunction(() => document.querySelector('.ai-status').textContent === '');
  await command('remove the stems');
  await enter();
  assert.match(await page.textContent('.ai-status'), /✓ Remove stems/);
  assert.equal(await page.locator('.ai-job.busy').count(), 1, 'the first command is still being written');

  // The first lands on its own note; the selection stays with what the second changed.
  const kept = await page.textContent('#item h2');
  assert.match(kept, /^13 items · Note/);
  letGo();
  await page.waitForSelector('.ai-job.done');
  assert.match(await page.textContent('.ai-job.done .ai-job-text'), /✓ A third below/);
  assert.equal(await page.getAttribute('#app', 'data-items'), '15');
  assert.equal(await page.textContent('#item h2'), kept);
  assert.match(await undoTitle(), /“double the melody a third below”/);

  // Its badge selects what it made, with the field saying what it did.
  await page.click('.ai-job.done .ai-job-text');
  await selection(/^Item \d+ · Note/);
  assert.match(await page.textContent('.ai-status'), /✓ A third below/);
  assert.equal(await page.locator('.ai-job').count(), 0);

  // A command sent off can be cancelled: nothing changes.
  hold('make the last note an x head');
  await run('I 2');
  await selection(/^Item \d+ · Note/);
  await command('make the last note an x head');
  await page.press('.ai-input', 'Enter');
  await page.click('.ai-job.busy .ai-job-close');
  assert.equal(await page.locator('.ai-job').count(), 0);
  assert.match(await undoTitle(), /“double the melody a third below”/);

  // A note repeated twice after itself, then three times with the slider: still one undo step.
  await run('I 2');
  await selection(/^Item \d+ · Note/);
  const count = Number(await page.getAttribute('#app', 'data-items'));
  await command('repeat it twice');
  await enter();
  assert.equal(Number(await page.getAttribute('#app', 'data-items')), count + 2);
  await page.locator('.ai-knob input[aria-label="Times"]').fill('3');
  await page.waitForFunction((n) => Number(document.getElementById('app').dataset.items) === n, count + 3);
  assert.match(await undoTitle(), /“repeat it twice”/);
  // Again: the last command as it was left (three copies) on what is selected now, the note and its copies.
  await command('do that again');
  assert.match(await page.textContent('.ai-reading'), /→ Repeat again/);
  await enter();
  assert.equal(Number(await page.getAttribute('#app', 'data-items')), count + 3 + 12);

  assert.deepEqual(errors, []);
  console.log('ai smoke: ok');
} finally {
  await browser.close();
  await new Promise((resolve) => server.httpServer.close(resolve));
}
