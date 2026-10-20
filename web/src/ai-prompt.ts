// The command field: it stands by the selection while there is one, or where
// the empty paper was clicked, and what is typed on the page goes into it
// (opening it if need be). A command in words goes to Jev at every keystroke,
// and the newest reading shows while typing goes on; Enter edits the score at
// once with what Jev read, or runs the editor's command it read (an entry of
// the `?` list, which its name typed runs without a model). When Jev is not
// sure, Enter sends the command off to Claude (one Jev finds complex to the
// model for those) and the field takes the next command at once, for these
// items or others: the edit lands on the command's own items when it is
// written, and a badge by them says how it goes. A SCORE command runs as on
// WinScore's command bar, on the selection if there is one. Numbers the
// command leaves open appear as sliders under the field; dragging one re-does
// the edit with the new value, live, as the same undo step. While a group
// command asks for its area, the field shows the question and takes the
// answer. Up and Down recall earlier lines.
import type { Box } from './display';
import type { Change, Editor } from './editor';
import { onlyParams, plain, reach, run, selects, type Access, type Knob, type Scope, type Script } from './ai-script';
import {
  askClaude,
  askJev,
  CLAUDE_MODELS,
  connections,
  GATEWAY_URL,
  jevCommand,
  jevScript,
  loadSettings,
  modelName,
  readingKey,
  saveSettings,
  serverKeys,
  TYPESAFE_URL,
  UNREAD,
  warmJev,
  writerFor,
  type About,
  type AppCommand,
  type Catalog,
  type Connections,
  type Failed,
} from './ai-models';

export interface PromptHooks {
  editor(): Editor | null;
  access(): Access | null;
  /** What the models are told about `text` and the scope. */
  about(text: string, scope: Scope): About | null;
  catalog(): Catalog;
  /** Whether SCORE's editor knows a command line. */
  supported(line: string): boolean;
  /** Runs a SCORE command line on the selection, as WinScore's command bar does (answers to a question too). */
  run(line: string): Change | null;
  /** Typing began, or a question came, with the field closed: it is to stand somewhere with nothing selected. */
  open(): void;
  /** Where a box of the page lies on screen. */
  clientRect(box: Box): DOMRect;
  /** After an edit; `live` while a slider moves, `params` when it only changed parameters of the selected items. */
  edited(live: boolean, params: boolean): void;
  /** Undoes (or redoes) the last edit of the score. */
  undo(redo: boolean): void;
  /** The field gave the keyboard back to the page. */
  left(): void;
  /** Whether the page can take an edit of a command sent off: not during a drag or a group command's question. */
  ready(): boolean;
  /** Selects items by identity and brings them into view. */
  select(keys: number[]): void;
  /** Runs one of the editor's own commands (About.commands) by its id; false if it cannot run now. */
  app(id: string): boolean;
}

/** A reading of the typed command as an edit script, ready to run. */
interface ScriptReading {
  script: Script;
  /** Where it came from, as shown: "Jev 93 % · 120 ms". */
  source: string;
}

/** A reading of the typed command: an edit script, or one of the editor's own commands ("save", "zoom in"). */
type Reading = ScriptReading | { command: AppCommand; source: string };

/** A request to Jev for the words typed, with what it will give. */
interface Pending {
  text: string;
  controller: AbortController;
  done: Promise<Asked | null>;
}

/** What Jev made of a command: its reading, if it has one, and whether the command takes thought. */
interface Asked {
  reading: Reading | null;
  complex: boolean;
}

/** The last command run, while its sliders can still re-do it. */
interface Applied {
  script: Script;
  scope: Scope;
  label: string;
  mark: number;
  /** The history depth after it: the sliders are stale once that changes. */
  depth: number;
  values: Record<string, number>;
}

/** A reading run on the score. */
interface Performed {
  applied: Applied;
  /** Whether it changed something (or picked a selection). */
  done: boolean;
  /** What it changed or made, by identity. */
  touched: number[];
}

/** A command sent off with Enter: it is read or written while the field takes other commands, and edits its own items. */
interface Job {
  text: string;
  scope: Scope;
  anchor: Box;
  /** The editor of its score: another score drops it. */
  editor: Editor;
  controller: AbortController;
  badge: HTMLElement;
  /** Once it ran: what ran, and what it changed. */
  reading?: ScriptReading;
  performed?: Performed;
  /** The command could not be done: why. */
  error?: string;
}

/** A command that lands away from the field says so by its items this long. */
const DONE_SHOWN_MS = 8000;
/** A command waiting for the page to take its edit looks again this often. */
const READY_POLL_MS = 150;

function el<K extends keyof HTMLElementTagNameMap>(tag: K, props: Record<string, unknown> = {}, ...children: (Node | string)[]): HTMLElementTagNameMap[K] {
  const node = document.createElement(tag);
  Object.assign(node, props);
  node.append(...children);
  return node;
}

const format = (v: number) => (Math.abs(v) >= 10 ? v.toFixed(0) : String(Math.round(v * 100) / 100));

/**
 * A SCORE command typed as such: upper-case words and numbers (R 5, FLI,
 * 600 5), a conditional edit (IF … THEN …) or a text's quick entry ("Allegro" 1 50).
 */
const looksLikeScore = (text: string) => /^[A-Z][A-Z0-9]*(\s+[-+]?[\d.]+)*$|^[-+]?[\d.]+(\s+[-+]?[\d.]+)+$|^IF\s|^"/.test(text.trim());

/**
 * The editor's command a line names, as its entry is called or its id
 * reads ("save", "zoom in", "export svg", "undo"), whatever the case and
 * punctuation; ids that are SCORE's words run as SCORE commands.
 */
function namedCommand(commands: AppCommand[], text: string): AppCommand | null {
  const wanted = plain(text);
  return commands.find((c) => plain(c.label.split(' ▸ ').at(-1)!) === wanted || (/[a-z]/.test(c.id) && plain(c.id) === wanted)) ?? null;
}

/** Whether two scopes are about the same items, and at a place the same place. */
const sameScope = (a: Scope, b: Scope) => {
  const sorted = (s: Scope) => String([...(s.keys ?? [])].sort((x, y) => x - y));
  return sorted(a) === sorted(b) && (a.keys !== null || JSON.stringify(a.region) === JSON.stringify(b.region));
};

/** Keys the page keeps for itself even though they print a character ([ and ] move staves, + and _ zoom). */
const PAGE_KEYS = new Set(['[', ']', '+', '=', '_']);

const isFormField = (target: EventTarget | null) => target instanceof HTMLInputElement || target instanceof HTMLTextAreaElement || target instanceof HTMLSelectElement;

/** A key typed on the page that starts a command. */
const startsCommand = (e: KeyboardEvent) => e.key.length === 1 && e.key !== ' ' && !PAGE_KEYS.has(e.key) && !e.ctrlKey && !e.metaKey && !e.altKey;

const PLACEHOLDER = { selection: 'Command, e.g. stems up', place: 'Command, e.g. add c e g', answer: 'Type the answer, or draw a box' };

export function createAiPrompt(host: HTMLElement, hooks: PromptHooks) {
  const input = el('input', { className: 'ai-input', type: 'text', placeholder: PLACEHOLDER.selection, autocomplete: 'off', spellcheck: false });
  input.setAttribute('aria-label', 'Command');
  const gear = el('button', { className: 'ai-gear', type: 'button', title: 'Models and keys', textContent: '⚙' });
  gear.setAttribute('aria-label', 'Models and keys');
  const questionText = el('span', { className: 'ai-question-text' });
  const endQuestion = el('button', { className: 'ai-cancel', type: 'button', title: 'End the group edit without a change', textContent: 'Cancel' });
  const asking = el('div', { className: 'ai-question', hidden: true }, questionText, endQuestion);
  const status = el('div', { className: 'ai-status' });
  const knobs = el('div', { className: 'ai-knobs' });
  const settings = el('form', { className: 'ai-settings', hidden: true });
  const box = el('div', { className: 'ai-prompt', hidden: true }, asking, el('div', { className: 'ai-row' }, el('span', { className: 'ai-mark', textContent: '›' }), input, gear), status, knobs, settings);
  box.setAttribute('role', 'group');
  box.setAttribute('aria-label', 'Command');
  host.append(box);

  let scope: Scope | null = null;
  let anchor: Box | null = null;
  /** Whether the field stands at a place on the paper rather than by the selection. */
  let atPlace = false;
  /** The question of a group command waiting for its answer, which the field takes. */
  let question: string | null = null;
  /** Whether the field opened for the question, and goes when it is answered. */
  let forQuestion = false;
  /** Lines entered, for Up and Down; `recalled` steps back from the newest. */
  const history: string[] = [];
  let recalled = 0;
  let reading: Reading | null = null;
  /** Jev's requests in flight for the field, by when they were asked; `pending` is the newest, for the text typed last. */
  const requests = new Map<number, Pending>();
  let pending: Pending | null = null;
  let asked = 0;
  /** When the request whose answer the field shows was asked. */
  let answered = 0;
  let applied: Applied | null = null;
  let frame = 0;
  /** Set while a slider is held: commands sent off wait to land. */
  let sliding = false;
  let server = { jev: false, claude: false };
  let links: Connections = connections(loadSettings(), server);
  /** Readings of earlier commands: Jev's by their words and the kinds of items, Claude's by the very items too (its scripts may name places). */
  const memo = new Map<string, Reading>();
  const claudeKey = (about: About, items: Scope) => `${readingKey(about)}|${items.keys?.join(',') ?? 'all'}|${JSON.stringify(items.region ?? null)}`;
  /** Commands sent off, until they have landed (and been seen). */
  const jobs = new Set<Job>();
  /** Set while the page takes in an edit of this field: the selection it then follows is the command's. */
  let own = false;
  const edited = (live: boolean, params: boolean) => {
    own = true;
    try {
      hooks.edited(live, params);
    } finally {
      own = false;
    }
  };

  void serverKeys().then((keys) => {
    server = keys;
    links = connections(loadSettings(), server);
    if (!box.hidden && !input.value) idle();
    if (!box.hidden && links.jev) warmJev(links.jev);
  });

  const show = (text: string, kind: '' | 'busy' | 'done' | 'error' = '', source = '') => {
    status.className = `ai-status ${kind}`;
    status.replaceChildren(el('span', { className: 'ai-reading', textContent: text }), source ? el('span', { className: 'ai-source', textContent: source }) : '');
  };

  /** Before anything is typed the field says nothing. */
  function idle() {
    status.className = 'ai-status';
    status.replaceChildren();
  }

  function place() {
    const origin = host.getBoundingClientRect();
    /** Where the field and the badges placed so far lie, so that the next badge goes clear of them. */
    const taken: { left: number; top: number; right: number; bottom: number }[] = [];
    if (!box.hidden && anchor) {
      const rect = hooks.clientRect(anchor);
      const width = box.offsetWidth;
      const height = box.offsetHeight;
      let left = Math.min(Math.max(8, rect.left - origin.left), origin.width - width - 8);
      let top = rect.bottom - origin.top + 8;
      if (top + height > origin.height - 8) top = rect.top - origin.top - height - 8;
      if (top < 8) top = Math.min(origin.height - height - 8, Math.max(8, rect.bottom - origin.top + 8));
      left = Math.max(8, left);
      top = Math.max(8, top);
      box.style.left = `${left}px`;
      box.style.top = `${top}px`;
      taken.push({ left, top, right: left + width, bottom: top + height });
    }
    // Badges stand above their items, each clear of the others and of the field.
    for (const job of jobs) {
      if (job.editor !== hooks.editor()) {
        cancel(job);
        continue;
      }
      const rect = hooks.clientRect(job.anchor);
      const width = job.badge.offsetWidth;
      const height = job.badge.offsetHeight;
      const left = Math.min(Math.max(8, rect.left - origin.left), Math.max(8, origin.width - width - 8));
      let top = Math.min(Math.max(8, rect.top - origin.top - height - 6), origin.height - height - 8);
      const clashes = (t: number) => taken.filter((r) => left < r.right && left + width > r.left && t < r.bottom && t + height > r.top);
      for (let clash = clashes(top), tries = 0; clash.length > 0 && tries <= jobs.size; clash = clashes(top), tries++) {
        const above = Math.min(...clash.map((r) => r.top)) - height - 4;
        top = above >= 8 ? above : Math.max(...clash.map((r) => r.bottom)) + 4;
      }
      job.badge.style.left = `${left}px`;
      job.badge.style.top = `${top}px`;
      taken.push({ left, top, right: left + width, bottom: top + height });
    }
  }

  function counted(script: Script): string {
    const access = hooks.access();
    if (!access || !scope) return '';
    if (script.steps.every((s) => s.do === 'insert' || s.do === 'create')) return '';
    const { count } = reach(script, access, scope);
    return count === 0 ? ' · nothing here it applies to' : ` · ${count} item${count === 1 ? '' : 's'}`;
  }

  /** Shows a reading; one of words typed before the field's (`earlier`) shows with the spinner, while the request for these is on its way. */
  function showReading(r: Reading, earlier = false) {
    if (!earlier) reading = r;
    show('command' in r ? `→ ${r.command.label}` : `→ ${r.script.summary}${counted(r.script)}`, earlier ? 'busy' : '', r.source);
  }

  /**
   * Asks Jev about the text typed, at once at every keystroke. The newest
   * answer shows: as the reading if the text is still the same, else with
   * the spinner until the answer for the text now typed comes; requests
   * asked before the answer shown go.
   */
  function askAbout(text: string): Promise<Asked | null> | null {
    const about = scope && hooks.about(text, scope);
    if (!about || !links.jev) return null;
    const at = ++asked;
    const controller = new AbortController();
    const done = askJev(about, links.jev, controller.signal)
      .then((jev) => {
        const script = jevScript(jev);
        const command = jevCommand(jev);
        const source = `Jev ${Math.round(jev.confidence * 100)} % · ${Math.round(jev.ms)} ms`;
        const result: Reading | null = script ? { script, source } : command ? { command, source } : null;
        if (result) memo.set(readingKey(about), result);
        // Still asked for the field (not sent off with Enter), and newer than the answer shown.
        if (requests.delete(at) && at > answered) {
          answered = at;
          for (const [earlier, request] of requests) if (earlier < at) forget(earlier, request);
          const current = input.value.trim() === text;
          const claude = links.claude && `Claude${jev.complex ? ` ${modelName(writerFor(links.claude, true).model)}` : ''}`;
          if (result) showReading(result, !current);
          else show(`${UNREAD[jev.why ?? 'unsure']}${claude ? `: ↵ has ${claude} write it` : '; Claude could write it (⚙)'}`, current ? '' : 'busy', `Jev · ${Math.round(jev.ms)} ms`);
        }
        return { reading: result, complex: jev.complex };
      })
      .catch((err: unknown) => {
        requests.delete(at);
        if (controller.signal.aborted) return null;
        if (input.value.trim() === text) show(err instanceof Error ? err.message : String(err), 'error');
        return null;
      });
    pending = { text, controller, done };
    requests.set(at, pending);
    return done;
  }

  /** A request for the field is dropped. */
  function forget(at: number, request: Pending) {
    request.controller.abort();
    requests.delete(at);
    if (pending === request) pending = null;
  }

  /** Every request for the field is dropped: what was typed is settled, or the field is about other items. */
  function forgetAll() {
    for (const [at, request] of requests) forget(at, request);
    pending = null;
  }

  /** Whether a line goes to the page as WinScore's command bar sends it: an answer to the question, or a SCORE command. */
  function native(text: string): boolean {
    return question !== null || (looksLikeScore(text) && hooks.supported(text));
  }

  function typed() {
    reading = null;
    const text = input.value.trim();
    if (!text || question !== null) {
      forgetAll();
      idle();
      return;
    }
    if (native(text)) {
      forgetAll();
      show(`→ ${text}`, '', 'SCORE command');
      return;
    }
    const about = scope && hooks.about(text, scope);
    // An editor's command by its name needs no model.
    const command = about && namedCommand(about.commands, text);
    if (command) {
      forgetAll();
      showReading({ command, source: 'Editor command' });
      return;
    }
    const known = about && (memo.get(readingKey(about)) ?? memo.get(claudeKey(about, scope!)));
    if (known) {
      forgetAll();
      showReading(known);
      return;
    }
    if (!links.jev) {
      show(links.claude ? '↵ has Claude write it' : 'Commands in words need a model: set one up with ⚙', links.claude ? '' : 'error');
      return;
    }
    // The reading of the words before stays, with the spinner, until these are read; what a command did or why it failed goes.
    if (status.childElementCount > 0 && !status.classList.contains('error') && !status.classList.contains('done')) status.classList.add('busy');
    else show('…', 'busy');
    askAbout(text);
  }

  /** Runs a reading on `items` as one undo step named after the command: what it did, or why it failed. */
  function perform(r: ScriptReading, text: string, items: Scope): Performed | string {
    const editor = hooks.editor();
    const access = hooks.access();
    if (!editor || !access) return 'There is no score';
    const label = `“${text}”`;
    const values = Object.fromEntries(r.script.knobs.map((k) => [k.id, k.value]));
    try {
      const ran = run(r.script, access, items, label, values);
      return { applied: { script: r.script, scope: items, label, mark: ran.mark, depth: editor.mark(), values }, done: ran.changed || selects(r.script), touched: ran.touched };
    } catch (err) {
      return err instanceof Error ? err.message : String(err);
    }
  }

  /** What a command did, in the field, with its sliders. */
  function present(r: ScriptReading, performed: Performed) {
    applied = performed.applied;
    show(performed.done ? `✓ ${r.script.summary}` : `${r.script.summary}: nothing changed`, performed.done ? 'done' : 'error', r.source);
    showKnobs(r.script.knobs.map((k) => ({ ...k, value: performed.applied.values[k.id] ?? k.value })));
  }

  /** Runs one of the editor's own commands, as its entry in the `?` list does; the field says so if it is still there with nothing typed. */
  function runApp(command: AppCommand, source: string) {
    const ran = hooks.app(command.id);
    if (box.hidden || input.value.trim()) return;
    if (ran) show(`✓ ${command.label}`, 'done', source);
    else show(`${command.label} cannot be done now`, 'error', source);
    place();
  }

  /** Runs a reading on the selection at once. */
  function apply(r: Reading, text: string) {
    if (!scope) return;
    if ('command' in r) {
      input.value = '';
      reading = null;
      return runApp(r.command, r.source);
    }
    const performed = perform(r, text, scope);
    if (typeof performed === 'string') show(performed, 'error', r.source);
    else {
      input.value = '';
      reading = null;
      present(r, performed);
    }
    // The command leaves what it changed selected, and the next one is about that.
    edited(false, false);
    place();
  }

  /** Runs a line on the page as WinScore's command bar runs it; the text stays to be corrected when the engine objects. */
  function runLine(text: string) {
    forgetAll();
    reading = null;
    // Emptied first: while the line runs the field may follow a new selection or question, with nothing to read.
    input.value = '';
    const change = hooks.run(text);
    if (box.hidden) return;
    if (change?.message) {
      input.value = text;
      show(change.message.replace(/^\*+ ?/, ''), 'error', 'SCORE command');
      return;
    }
    if (question === null) show(`✓ ${text}`, 'done', 'SCORE command');
    else idle();
    place();
  }

  function enter() {
    const text = input.value.trim();
    const editor = hooks.editor();
    if (!text || !scope || !anchor || !editor) return;
    if (history.at(-1) !== text) history.push(text);
    recalled = 0;
    if (native(text)) return runLine(text);
    if (reading) return apply(reading, text);
    const about = hooks.about(text, scope);
    if (!about || (!links.jev && !links.claude)) {
      show('Commands in words need a model: set one up with ⚙', 'error');
      return;
    }
    // Jev's reading of these words, if it is under way, goes with the command, and the field asks no more about them.
    if (pending?.text !== text) askAbout(text);
    const request = pending?.text === text ? pending : null;
    for (const [at, r] of requests) if (r === request) requests.delete(at);
    forgetAll();
    const job: Job = { text, scope, anchor, editor, controller: request?.controller ?? new AbortController(), badge: badgeFor() };
    jobs.add(job);
    host.append(job.badge);
    showJob(job, text, 'busy');
    input.value = '';
    reading = null;
    idle();
    place();
    void work(job, about, request?.done ?? null);
  }

  /** A command sent off: Jev's reading runs on its items, or Claude writes the edit; a script that fails to run goes back to Claude once, with the error. */
  async function work(job: Job, about: About, asked: Promise<Asked | null> | null) {
    const { signal } = job.controller;
    try {
      const jev = asked && (await asked);
      if (signal.aborted) return;
      const read = jev?.reading;
      if (read && 'command' in read) {
        finish(job);
        return runApp(read.command, read.source);
      }
      if (read) return void (await land(job, read, false));
      const claude = links.claude;
      if (!claude) throw new Error(links.jev ? 'Jev could not read this, and no Claude key is set (⚙)' : 'Commands in words need a model: set one up with ⚙');
      const writer = writerFor(claude, jev?.complex ?? false);
      const name = `Claude ${modelName(writer.model)}`;
      showJob(job, job.text, 'busy', name);
      let failed: Failed | undefined;
      for (let tries = 2; tries > 0; tries--) {
        const { script, ms, answer } = await askClaude(about, hooks.catalog(), claude, writer, signal, failed);
        const result = { script, source: `${name} · ${(ms / 1000).toFixed(1)} s` };
        const error = await land(job, result, tries > 1);
        if (error === null) {
          memo.set(claudeKey(about, job.scope), result);
          return;
        }
        failed = { answer, error };
        showJob(job, `${error}: correcting the edit…`, 'busy', name);
      }
    } catch (err) {
      if (!signal.aborted) fail(job, err instanceof Error ? err.message : String(err));
    }
  }

  /** Whether the field stands by a command's items with nothing typed: what it does is then said there. */
  const atField = (job: Job) => !box.hidden && scope !== null && sameScope(scope, job.scope) && !input.value.trim();

  /**
   * Runs a command's reading on its items once the page can take it, as one
   * undo step. By the field, it leaves what it changed selected, as a command
   * run at once does; elsewhere the selection stays, and its badge says what
   * it did. Why it failed, if it did: said, unless Claude is to `retry`.
   */
  async function land(job: Job, r: ScriptReading, retry: boolean): Promise<string | null> {
    const { signal } = job.controller;
    while (!signal.aborted && (sliding || !hooks.ready())) await new Promise((wake) => setTimeout(wake, READY_POLL_MS));
    const editor = hooks.editor();
    if (editor !== job.editor) cancel(job);
    if (signal.aborted || !editor) throw new DOMException('The command was dropped', 'AbortError');
    const here = atField(job);
    const keys = editor.keys();
    const before = editor.selection().map((i) => keys[i]!);
    const performed = perform(r, job.text, job.scope);
    if (typeof performed === 'string') {
      if (!retry) fail(job, performed);
      return performed;
    }
    job.reading = r;
    job.performed = performed;
    if (here) {
      finish(job);
      present(r, performed);
    } else {
      const at = new Map(editor.keys().map((key, i) => [key, i]));
      editor.select(before.flatMap((key) => at.get(key) ?? []));
      showJob(job, performed.done ? `✓ ${r.script.summary}` : `${r.script.summary}: nothing changed`, performed.done ? 'done' : 'error', r.source);
      setTimeout(() => finish(job), DONE_SHOWN_MS);
    }
    edited(false, false);
    place();
    return null;
  }

  /** A command that could not be done: by the field, the command goes back into it with why; else its badge says why until it is seen. */
  function fail(job: Job, error: string) {
    job.error = error;
    if (atField(job)) {
      finish(job);
      input.value = job.text;
      show(error, 'error');
    } else showJob(job, error, 'error');
    place();
  }

  function badgeFor(): HTMLElement {
    const text = el('button', { type: 'button', className: 'ai-job-text' });
    const source = el('span', { className: 'ai-job-source' });
    const close = el('button', { type: 'button', className: 'ai-job-close', textContent: '×' });
    const badge = el('div', { className: 'ai-job' }, text, source, close);
    badge.setAttribute('role', 'status');
    // A click leaves the keyboard where it was: in the field, or with the page.
    badge.addEventListener('mousedown', (e) => e.preventDefault());
    return badge;
  }

  function showJob(job: Job, text: string, kind: 'busy' | 'done' | 'error', source = '') {
    const [label, from, close] = job.badge.children as unknown as [HTMLButtonElement, HTMLElement, HTMLButtonElement];
    job.badge.className = `ai-job ${kind}`;
    label.textContent = kind === 'busy' ? `“${job.text}”` : text;
    label.title = kind === 'busy' ? `${text === job.text ? 'Working on it' : text}: select its items` : kind === 'done' ? 'Select what it changed' : `“${job.text}”: select its items and put it back in the field`;
    from.textContent = source;
    from.hidden = !source;
    close.title = kind === 'busy' ? 'Cancel the command' : 'Dismiss';
    close.setAttribute('aria-label', close.title);
    label.onclick = () => open(job);
    close.onclick = () => cancel(job);
    place();
  }

  /** The command's badge goes; the command stops if it is still under way. */
  function cancel(job: Job) {
    job.controller.abort();
    finish(job);
  }

  function finish(job: Job) {
    jobs.delete(job);
    job.badge.remove();
  }

  /** A badge clicked: its items are selected (what it changed, once it ran), with its sliders if nothing came after; a failed command goes back into the field. */
  function open(job: Job) {
    const ran = job.performed;
    const keys = ran && ran.touched.length > 0 ? ran.touched : (job.scope.keys ?? []);
    if (ran || job.error) finish(job);
    hooks.select(keys);
    if (box.hidden) return;
    if (job.error) {
      input.value = job.text;
      show(job.error, 'error');
      input.focus();
    } else if (ran && job.reading && hooks.editor()?.mark() === ran.applied.depth) present(job.reading, ran);
    place();
  }

  /** Re-does the last command with the knobs' values now, live while a slider moves. */
  function redo(live: boolean) {
    frame = 0;
    const editor = hooks.editor();
    const access = hooks.access();
    if (!applied || !editor || !access) return;
    if (editor.mark() !== applied.depth) {
      // Undone or followed by another edit: the sliders no longer belong to the score.
      applied = null;
      showKnobs([]);
      return;
    }
    editor.rollback(applied.mark);
    try {
      run(applied.script, access, applied.scope, applied.label, applied.values);
    } catch (err) {
      show(err instanceof Error ? err.message : String(err), 'error');
    }
    applied.depth = editor.mark();
    edited(live, onlyParams(applied.script));
  }

  function showKnobs(list: Knob[]) {
    sliding = false;
    knobs.replaceChildren(
      ...list.map((knob) => {
        const slider = el('input', { type: 'range', min: String(knob.min), max: String(knob.max), step: String(knob.step || 'any'), value: String(knob.value) });
        const value = el('output', { textContent: format(knob.value) });
        slider.setAttribute('aria-label', knob.label);
        slider.addEventListener('input', () => {
          if (!applied) return;
          sliding = true;
          applied.values[knob.id] = Number(slider.value);
          value.textContent = format(Number(slider.value));
          if (!frame) frame = requestAnimationFrame(() => redo(true));
        });
        slider.addEventListener('change', () => {
          sliding = false;
          cancelAnimationFrame(frame);
          redo(false);
        });
        return el('label', { className: 'ai-knob' }, el('span', { textContent: knob.label }), slider, value);
      }),
    );
    knobs.hidden = list.length === 0;
  }

  function showSettings() {
    const current = loadSettings();
    const field = (label: string, control: HTMLElement, note = '') => el('label', {}, el('span', { textContent: label }), control, note ? el('small', { textContent: note }) : '');
    const jevKey = el('input', { type: 'password', value: current.jevKey, placeholder: server.jev ? 'the dev server’s TYPESAFE_API_KEY' : 'TypeSafe or AI Gateway key', autocomplete: 'off' });
    const jevUrl = el('select', {}, ...[[TYPESAFE_URL, 'TypeSafe (through a server)'], [GATEWAY_URL, 'Vercel AI Gateway (from any page)']].map(([v, l]) => new Option(l, v, false, v === current.jevUrl)));
    const claudeKey = el('input', { type: 'password', value: current.claudeKey, placeholder: server.claude ? 'the dev server’s ANTHROPIC_API_KEY' : 'Anthropic API key', autocomplete: 'off' });
    const model = el('select', {}, ...CLAUDE_MODELS.map((m) => new Option(m.label, m.id, false, m.id === current.claudeModel)));
    const complexModel = el('select', {}, ...CLAUDE_MODELS.map((m) => new Option(m.label, m.id, false, m.id === current.claudeComplexModel)));
    const save = el('button', { type: 'submit', className: 'primary', textContent: 'Save' });
    settings.replaceChildren(
      field('Jev key', jevKey),
      field('Jev through', jevUrl, 'TypeSafe answers pages of its own site only: from here Jev needs the dev server (npm run dev with TYPESAFE_API_KEY) or the AI Gateway.'),
      field('Claude key', claudeKey),
      field('Claude model', model),
      field('For complex commands', complexModel, 'Jev tells which commands take thought; they are written, at more effort, while you go on with others.'),
      el('div', { className: 'ai-settings-actions' }, el('small', { textContent: 'Keys stay in this browser.' }), save),
    );
    settings.onsubmit = (e) => {
      e.preventDefault();
      const next = { jevKey: jevKey.value.trim(), jevUrl: jevUrl.value, claudeKey: claudeKey.value.trim(), claudeModel: model.value, claudeComplexModel: complexModel.value };
      saveSettings(next);
      links = connections(next, server);
      memo.clear();
      forgetAll();
      settings.hidden = true;
      input.focus();
      typed();
    };
    settings.hidden = false;
    place();
  }

  input.addEventListener('input', typed);
  input.addEventListener('keydown', (e) => {
    e.stopPropagation();
    // With nothing typed, ⌘Z undoes the last command rather than the field's text.
    if ((e.metaKey || e.ctrlKey) && e.key.toLowerCase() === 'z' && !input.value) {
      e.preventDefault();
      hooks.undo(e.shiftKey);
      return;
    }
    if (e.key === 'Enter') {
      e.preventDefault();
      enter();
    } else if (e.key === 'Escape') {
      e.preventDefault();
      leave();
    } else if ((e.key === 'ArrowUp' || e.key === 'ArrowDown') && history.length > 0) {
      e.preventDefault();
      recalled = Math.min(history.length, Math.max(0, recalled + (e.key === 'ArrowUp' ? 1 : -1)));
      input.value = history[history.length - recalled] ?? '';
      input.setSelectionRange(input.value.length, input.value.length);
      typed();
    }
  });
  box.addEventListener('keydown', (e) => {
    if (e.key === 'Escape') leave();
    e.stopPropagation();
  });
  gear.addEventListener('click', () => (settings.hidden ? showSettings() : ((settings.hidden = true), place())));
  endQuestion.addEventListener('click', () => {
    hooks.run('X');
    hooks.left();
  });

  // Typing on the page outside a form field goes into the field, which opens if it is not there.
  window.addEventListener('keydown', (e) => {
    if (!hooks.editor() || isFormField(e.target) || document.querySelector('dialog[open]') || !startsCommand(e)) return;
    if (box.hidden) hooks.open();
    if (box.hidden) return;
    e.preventDefault();
    input.focus();
    input.value = e.key;
    recalled = 0;
    typed();
  });

  /** Escape: the text and the settings go, and the keyboard goes back to the page (where Escape then deselects). */
  function leave() {
    forgetAll();
    input.value = '';
    reading = null;
    settings.hidden = true;
    idle();
    place();
    hooks.left();
  }

  function showPlaceholder() {
    input.placeholder = question !== null ? PLACEHOLDER.answer : atPlace ? PLACEHOLDER.place : PLACEHOLDER.selection;
  }

  /**
   * Stands by `around`: the selection's box, or with `onPaper` a point on
   * the paper where nothing is selected. Other items or another place make a
   * new scope, and the last command's sliders go.
   */
  function follow(next: Scope, around: Box, onPaper = false) {
    const same = !box.hidden && (own || (scope !== null && sameScope(scope, next)));
    scope = next;
    anchor = around;
    atPlace = onPaper;
    showPlaceholder();
    if (box.hidden) {
      box.hidden = false;
      settings.hidden = true;
      if (links.jev) warmJev(links.jev);
    }
    if (!same) {
      applied = null;
      showKnobs([]);
      // Readings asked so far are about other items.
      forgetAll();
      typed();
    }
    place();
  }

  /** The field goes, and what was typed in it. */
  function close() {
    if (box.hidden) return;
    const focused = box.contains(document.activeElement);
    forgetAll();
    box.hidden = true;
    input.value = '';
    reading = null;
    applied = null;
    scope = null;
    atPlace = false;
    question = null;
    forQuestion = false;
    asking.hidden = true;
    showKnobs([]);
    idle();
    if (focused) hooks.left();
  }

  /**
   * A group command's question (null once it is answered or cancelled): the
   * field shows it and takes the answer, opening for it if it is not there,
   * and taking the keyboard with `focus`.
   */
  function ask(next: string | null, focus: boolean) {
    if (next === question) return;
    if (next !== null && box.hidden) {
      hooks.open();
      if (box.hidden) return;
      forQuestion = true;
    }
    question = next;
    asking.hidden = next === null;
    questionText.textContent = next ?? '';
    showPlaceholder();
    if (next === null && forQuestion) {
      close();
      return;
    }
    typed();
    place();
    if (next !== null && focus && document.activeElement !== input) input.focus();
  }

  return {
    follow,
    close,
    ask,
    /** Whether the field stays with nothing selected: it stands at a place, or takes a question's answer. */
    get standsAlone() {
      return !box.hidden && (atPlace || question !== null);
    },
    /** Keeps the field by its music while the page scrolls and zooms. */
    place,
    /** After an edit elsewhere: sliders of a command since undone go. */
    refresh() {
      const editor = hooks.editor();
      if (applied && editor && editor.mark() !== applied.depth) {
        applied = null;
        showKnobs([]);
      }
    },
  };
}
