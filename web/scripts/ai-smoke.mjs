// End-to-end check of the AI command in the built app (dist/), with Jev and
// Claude answered by canned replies at the network: a lasso opens the
// field, what Jev reads is shown while typing, Enter edits the score as one
// undo step, a slider re-does it, and a command Jev cannot read goes to Claude.
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
  'beam always 2 notes': { action: 'beam', target: 'notes', group: '2', amount: '2' },
  'make note size gradually bigger': { action: 'grow', target: 'notes', measure: 'size' },
  'make the last note an x head': { action: 'other', target: 'notes' },
  'add notes c g d/f/a': { action: 'insert', target: 'all' },
};

/** Claude's script for the command Jev gives up on. */
const CLAUDE = {
  summary: 'Last note with an X head',
  knobs: [],
  steps: [
    {
      do: 'setting', codes: [1], where: 't == 1', where_setting: '', where_is: '', setting: 'Head', param: 0, value: 'X',
      right: '', up: '', line: '', staff: 0, from: 0, to: 0, notes: '', rhythms: '', marks: '', beams: '', slurs: '', size: '',
    },
  ],
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

function claudeMessage() {
  return {
    id: 'msg_test',
    type: 'message',
    role: 'assistant',
    model: 'claude-sonnet-5-5',
    content: [{ type: 'text', text: JSON.stringify(CLAUDE) }],
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
    await route.fulfill({ status: 200, headers: { ...cors, 'content-type': 'application/json' }, body: JSON.stringify(jevAnswers(body)) });
  });
  let claudeRequest = null;
  await page.route('https://api.anthropic.com/**', async (route) => {
    if (route.request().method() === 'OPTIONS') return route.fulfill({ status: 204, headers: cors });
    claudeRequest = route.request().postDataJSON();
    await route.fulfill({ status: 200, headers: { ...cors, 'content-type': 'application/json' }, body: JSON.stringify(claudeMessage()) });
  });

  // Eight eighth notes on the left half of a new staff.
  await page.goto(`http://localhost:${PORT}/?new`);
  await page.waitForSelector('#app[data-ready="true"]');
  await page.click('#empty-input');
  await page.fill('#input-end', '100');
  await page.focus('#viewport');
  await page.keyboard.type('C5/D/E/F/G/A/B/C');
  await page.keyboard.press('Enter');
  await page.keyboard.type('8/8/8/8/8/8/8/8');
  await page.keyboard.press('Control+Enter');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '9');
  await page.click('#input');

  // The box of the notes, then a lasso around it.
  await page.fill('#item-filter', 'note');
  await page.click('#items-select');
  const box = JSON.parse(await page.getAttribute('#viewport', 'data-selection'));
  await page.keyboard.press('Escape');
  await page.fill('#item-filter', '');
  const [x0, y0, x1, y1] = [box.x - 30, box.y - 30, box.x + box.width + 30, box.y + box.height + 30];
  await page.keyboard.down('Alt');
  await page.mouse.move(x0, y0);
  await page.mouse.down();
  for (const [x, y] of [[x1, y0], [x1, y1], [x0, y1], [x0, y0 + 5]]) await page.mouse.move(x, y, { steps: 6 });
  await page.mouse.up();
  await page.keyboard.up('Alt');
  await page.waitForSelector('.ai-prompt:not([hidden])');
  assert.match(await page.textContent('.ai-status'), /8 notes/);
  assert.equal(await page.evaluate(() => document.activeElement?.className), 'ai-input');
  for (let i = 0; i < 100 && warmUps === 0; i++) await page.waitForTimeout(20);
  assert.equal(warmUps, 1, 'the field opens the connection to Jev');

  const ask = async (text) => {
    await page.fill('.ai-input', text);
    await page.waitForFunction(() => /→|asks Claude/.test(document.querySelector('.ai-status').textContent));
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

  // What Jev read shows before Enter; Enter edits the score as one undo step.
  await ask('remove the stems');
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
  await ask('beam always 2 notes');
  await enter();
  assert.equal(await page.textContent('#item-count'), '13');
  const size = page.locator('.ai-knob input[aria-label="Notes per beam"]');
  assert.equal(await size.inputValue(), '2');
  await size.fill('4');
  await page.waitForFunction(() => document.getElementById('item-count').textContent === '11');
  assert.match(await page.getAttribute('#undo', 'title'), /“beam always 2 notes”/);

  // Sizes growing from left to right, with three sliders.
  await ask('make note size gradually bigger');
  assert.match(await page.textContent('.ai-reading'), /Size grows/);
  await enter();
  assert.equal(await page.locator('.ai-knob').count(), 3);
  const to = page.locator('.ai-knob input[aria-label="To"]');
  await to.fill('3');
  await page.waitForFunction(() => document.getElementById('message').textContent.includes('3'));
  const grown = await shownParams();
  assert.equal(grown(15), 3, 'the last note reaches the final size');

  // Jev is not sure: Enter asks Claude, whose script runs the same way.
  await ask('make the last note an x head');
  assert.match(await page.textContent('.ai-reading'), /not one of Jev’s actions: ↵ asks Claude/);
  await enter();
  assert.match(await page.textContent('.ai-status'), /✓ Last note with an X head/);
  assert.match(await page.textContent('.ai-source'), /^Claude/);
  assert.equal(claudeRequest.model, 'claude-sonnet-5-5', 'Sonnet 5.5 unless another model is picked');
  assert.equal(claudeRequest.output_config.format.type, 'json_schema');
  assert.match(claudeRequest.messages[0].content, /Command: make the last note an x head/);

  // A SCORE command needs no model.
  const before = jevRequests.length;
  await ask('FLI');
  assert.match(await page.textContent('.ai-reading'), /SCORE: FLI/);
  assert.equal(jevRequests.length, before);

  // Escape closes the field; undo takes back one command at a time.
  await page.press('.ai-input', 'Escape');
  assert.ok(await page.isHidden('.ai-prompt'));
  await page.keyboard.press('Control+z');
  await page.keyboard.press('Control+z');
  await page.keyboard.press('Control+z');
  assert.equal(await page.textContent('#item-count'), '9');
  assert.match(await page.getAttribute('#undo', 'title'), /“remove the stems”/);

  // A lasso around empty space on the staff, reaching past the paper's edge: the notes typed go there.
  const [r0, r1] = [box.x + box.width + 40, box.x + box.width + 700];
  await page.keyboard.down('Alt');
  await page.mouse.move(r0, y0);
  await page.mouse.down();
  for (const [x, y] of [[r1, y0], [r1, y1], [r0, y1]]) await page.mouse.move(x, y, { steps: 4 });
  await page.mouse.up();
  await page.keyboard.up('Alt');
  await page.waitForSelector('.ai-prompt:not([hidden])');
  assert.match(await page.textContent('.ai-status'), /Empty space on staff 1/);
  await ask('add notes c g d/f/a');
  assert.match(await page.textContent('.ai-reading'), /Add c g d\/f\/a/);
  await enter();
  assert.equal(await page.textContent('#item-count'), '14');
  await page.press('.ai-input', 'Escape');

  // The Ask button arms the lasso for one drag.
  await page.click('#ask');
  assert.equal(await page.getAttribute('#ask', 'aria-pressed'), 'true');
  await page.mouse.move(x0, y0);
  await page.mouse.down();
  for (const [x, y] of [[x1, y0], [x1, y1], [x0, y1]]) await page.mouse.move(x, y, { steps: 4 });
  await page.mouse.up();
  await page.waitForSelector('.ai-prompt:not([hidden])');
  assert.equal(await page.getAttribute('#ask', 'aria-pressed'), 'false');

  assert.deepEqual(errors, []);
  console.log('ai smoke: ok');
} finally {
  await browser.close();
  await new Promise((resolve) => server.httpServer.close(resolve));
}
