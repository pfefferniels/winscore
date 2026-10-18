// The AI command: a small field by the music a lasso (or the selection) took
// in. What is typed goes to Jev while it is typed; Enter edits the score at
// once with what Jev read, or asks Claude when Jev is not sure. Numbers the
// command leaves open appear as sliders under the field; dragging one
// re-does the edit with the new value, live, as the same undo step.
import type { Box } from './display';
import type { Editor } from './editor';
import { onlyParams, reach, run, type Access, type Knob, type Scope, type Script } from './ai-script';
import { counted as countedItems } from './ai-intent';
import {
  askClaude,
  askJev,
  CLAUDE_MODELS,
  connections,
  GATEWAY_URL,
  jevScript,
  loadSettings,
  readingKey,
  saveSettings,
  serverKeys,
  TYPESAFE_URL,
  UNREAD,
  warmJev,
  type About,
  type Catalog,
  type Connections,
} from './ai-models';

export interface PromptHooks {
  editor(): Editor | null;
  access(): Access | null;
  /** What the models are told about `text` and the scope. */
  about(text: string, scope: Scope): About | null;
  catalog(): Catalog;
  /** Whether SCORE's editor knows a command line. */
  supported(line: string): boolean;
  /** Where a box of the page lies on screen. */
  clientRect(box: Box): DOMRect;
  /** After an edit; `live` while a slider moves, `params` when it only changed parameters of the selected items. */
  edited(live: boolean, params: boolean): void;
  /** Undoes (or redoes) the last edit of the score. */
  undo(redo: boolean): void;
  /** The prompt closed. */
  closed(): void;
}

/** A reading of the typed command, ready to run. */
interface Reading {
  script: Script;
  /** Where it came from, as shown: "Jev 93 % · 120 ms". */
  source: string;
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

/** Jev is asked once typing pauses this long. */
const TYPING_PAUSE_MS = 120;

function el<K extends keyof HTMLElementTagNameMap>(tag: K, props: Record<string, unknown> = {}, ...children: (Node | string)[]): HTMLElementTagNameMap[K] {
  const node = document.createElement(tag);
  Object.assign(node, props);
  node.append(...children);
  return node;
}

const format = (v: number) => (Math.abs(v) >= 10 ? v.toFixed(0) : String(Math.round(v * 100) / 100));

/** A SCORE command typed as such: upper-case words and numbers (R 5, FLI, 600 5). */
const looksLikeScore = (text: string) => /^[A-Z][A-Z0-9]*(\s+[-+]?[\d.]+)*$|^[-+]?[\d.]+(\s+[-+]?[\d.]+)+$/.test(text.trim());

export function createAiPrompt(host: HTMLElement, hooks: PromptHooks) {
  const input = el('input', { className: 'ai-input', type: 'text', placeholder: 'Tell the music what to do…', autocomplete: 'off', spellcheck: false });
  input.setAttribute('aria-label', 'AI command');
  const gear = el('button', { className: 'ai-gear', type: 'button', title: 'Models and keys', textContent: '⚙' });
  gear.setAttribute('aria-label', 'Models and keys');
  const status = el('div', { className: 'ai-status' });
  const knobs = el('div', { className: 'ai-knobs' });
  const settings = el('form', { className: 'ai-settings', hidden: true });
  const box = el('div', { className: 'ai-prompt', hidden: true }, el('div', { className: 'ai-row' }, el('span', { className: 'ai-mark', textContent: '✦' }), input, gear), status, knobs, settings);
  box.setAttribute('role', 'dialog');
  box.setAttribute('aria-label', 'AI command');
  host.append(box);

  let scope: Scope | null = null;
  let anchor: Box | null = null;
  let reading: Reading | null = null;
  /** The request in flight for the text typed, with what it will give. */
  let pending: { text: string; controller: AbortController; done: Promise<Reading | null> } | null = null;
  let typingTimer = 0;
  let applied: Applied | null = null;
  let frame = 0;
  let server = { jev: false, claude: false };
  let links: Connections = connections(loadSettings(), server);
  /** Readings of earlier commands: Jev's by their words and the kinds of items, Claude's by the very items too (its scripts may name places). */
  const memo = new Map<string, Reading>();
  const claudeKey = (about: About) => `${readingKey(about)}|${scope?.keys?.join(',') ?? 'all'}|${JSON.stringify(scope?.region ?? null)}`;
  /** The command Claude is writing an edit for. */
  let writing: string | null = null;

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

  /** What the field says before anything is typed: what the command is about. */
  function idle() {
    const about = scope && hooks.about('', scope);
    const what = about ? [...about.counts].sort((a, b) => b[1] - a[1]).map(([code, n]) => countedItems(code, n)).join(', ') : '';
    const region = scope?.region ? `Empty space on staff ${scope.region.staff}` : 'Nothing';
    const models = links.jev || links.claude ? '' : ' · set up a model with ⚙';
    show(`${what || (scope?.keys === null ? 'The whole score' : region)}${models}`);
  }

  function place() {
    if (box.hidden || !anchor) return;
    const rect = hooks.clientRect(anchor);
    const origin = host.getBoundingClientRect();
    const width = box.offsetWidth;
    const height = box.offsetHeight;
    let left = Math.min(Math.max(8, rect.left - origin.left), origin.width - width - 8);
    let top = rect.bottom - origin.top + 8;
    if (top + height > origin.height - 8) top = rect.top - origin.top - height - 8;
    if (top < 8) top = Math.min(origin.height - height - 8, Math.max(8, rect.bottom - origin.top + 8));
    left = Math.max(8, left);
    box.style.left = `${left}px`;
    box.style.top = `${Math.max(8, top)}px`;
  }

  function counted(script: Script): string {
    const access = hooks.access();
    if (!access || !scope) return '';
    if (script.steps.every((s) => s.do === 'insert')) return '';
    const { count } = reach(script, access, scope);
    return count === 0 ? ' · nothing here it applies to' : ` · ${count} item${count === 1 ? '' : 's'}`;
  }

  function showReading(r: Reading) {
    reading = r;
    show(`→ ${r.script.summary}${counted(r.script)}`, '', r.source);
  }

  /** Asks Jev about the text typed; the answer becomes the reading if the text is still the same. */
  function askAbout(text: string): Promise<Reading | null> | null {
    const about = scope && hooks.about(text, scope);
    if (!about || !links.jev) return null;
    pending?.controller.abort();
    const controller = new AbortController();
    const done = askJev(about, links.jev, controller.signal)
      .then((jev) => {
        const script = jevScript(jev);
        const result = script ? { script, source: `Jev ${Math.round(jev.confidence * 100)} % · ${Math.round(jev.ms)} ms` } : null;
        if (result) memo.set(readingKey(about), result);
        if (input.value.trim() === text) {
          if (result) showReading(result);
          else show(`${UNREAD[jev.why ?? 'unsure']}${links.claude ? ': ↵ asks Claude' : '; Claude could write it (⚙)'}`, '', `Jev · ${Math.round(jev.ms)} ms`);
        }
        return result;
      })
      .catch((err: unknown) => {
        if (controller.signal.aborted) return null;
        if (input.value.trim() === text) show(err instanceof Error ? err.message : String(err), 'error');
        return null;
      });
    pending = { text, controller, done };
    return done;
  }

  function typed() {
    clearTimeout(typingTimer);
    reading = null;
    const text = input.value.trim();
    if (!text) {
      pending?.controller.abort();
      pending = null;
      idle();
      return;
    }
    if (looksLikeScore(text) && hooks.supported(text)) {
      showReading({ script: { summary: `SCORE: ${text}`, knobs: [], steps: [{ do: 'command', items: null, line: text }] }, source: 'SCORE command' });
      return;
    }
    const about = scope && hooks.about(text, scope);
    const known = about && (memo.get(readingKey(about)) ?? memo.get(claudeKey(about)));
    if (known) {
      showReading(known);
      return;
    }
    if (!links.jev) {
      show(links.claude ? '↵ asks Claude' : 'No model to ask: set one up with ⚙', links.claude ? '' : 'error');
      return;
    }
    show('…', 'busy');
    typingTimer = window.setTimeout(() => askAbout(text), TYPING_PAUSE_MS);
  }

  /** Runs a reading on the score, as one undo step named after the command. */
  function apply(r: Reading, text: string) {
    const editor = hooks.editor();
    const access = hooks.access();
    if (!editor || !access || !scope) return;
    const label = `“${text}”`;
    const values = Object.fromEntries(r.script.knobs.map((k) => [k.id, k.value]));
    try {
      const ran = run(r.script, access, scope, label, values);
      applied = { script: r.script, scope, label, mark: ran.mark, depth: editor.mark(), values };
      hooks.edited(false, false);
      show(ran.changed ? `✓ ${r.script.summary}` : `${r.script.summary}: nothing changed`, ran.changed ? 'done' : 'error', r.source);
      // The next command is about what this one changed, or what it was about.
      if (ran.touched.length) scope = { ...scope, keys: ran.touched };
      input.value = '';
      reading = null;
      showKnobs(r.script.knobs);
    } catch (err) {
      hooks.edited(false, false);
      show(err instanceof Error ? err.message : String(err), 'error', r.source);
    }
    place();
  }

  async function enter() {
    const text = input.value.trim();
    if (!text || !scope) return;
    clearTimeout(typingTimer);
    if (reading) return apply(reading, text);
    const asked = pending?.text === text ? pending.done : askAbout(text);
    if (asked) {
      show('…', 'busy');
      const result = await asked;
      if (input.value.trim() !== text) return;
      if (result) return apply(result, text);
    }
    const about = hooks.about(text, scope);
    if (writing === text) return;
    if (!about || !links.claude) {
      show(links.jev ? 'Jev could not read this, and no Claude key is set (⚙)' : 'No model to ask: set one up with ⚙', 'error');
      return;
    }
    show('Claude is writing the edit…', 'busy');
    const controller = new AbortController();
    pending = { text, controller, done: Promise.resolve(null) };
    writing = text;
    try {
      const { script, ms } = await askClaude(about, hooks.catalog(), links.claude, controller.signal);
      const result = { script, source: `Claude · ${(ms / 1000).toFixed(1)} s` };
      memo.set(claudeKey(about), result);
      if (input.value.trim() === text) apply(result, text);
    } catch (err) {
      if (!controller.signal.aborted && input.value.trim() === text) show(err instanceof Error ? err.message : String(err), 'error', 'Claude');
    } finally {
      writing = null;
    }
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
    hooks.edited(live, onlyParams(applied.script));
  }

  function showKnobs(list: Knob[]) {
    knobs.replaceChildren(
      ...list.map((knob) => {
        const slider = el('input', { type: 'range', min: String(knob.min), max: String(knob.max), step: String(knob.step || 'any'), value: String(knob.value) });
        const value = el('output', { textContent: format(knob.value) });
        slider.setAttribute('aria-label', knob.label);
        slider.addEventListener('input', () => {
          if (!applied) return;
          applied.values[knob.id] = Number(slider.value);
          value.textContent = format(Number(slider.value));
          if (!frame) frame = requestAnimationFrame(() => redo(true));
        });
        slider.addEventListener('change', () => {
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
    const save = el('button', { type: 'submit', className: 'primary', textContent: 'Save' });
    settings.replaceChildren(
      field('Jev key', jevKey),
      field('Jev through', jevUrl, 'TypeSafe answers pages of its own site only: from here Jev needs the dev server (npm run dev with TYPESAFE_API_KEY) or the AI Gateway.'),
      field('Claude key', claudeKey),
      field('Claude model', model),
      el('div', { className: 'ai-settings-actions' }, el('small', { textContent: 'Keys stay in this browser.' }), save),
    );
    settings.onsubmit = (e) => {
      e.preventDefault();
      const next = { jevKey: jevKey.value.trim(), jevUrl: jevUrl.value, claudeKey: claudeKey.value.trim(), claudeModel: model.value };
      saveSettings(next);
      links = connections(next, server);
      memo.clear();
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
      void enter();
    } else if (e.key === 'Escape') {
      e.preventDefault();
      close();
    }
  });
  box.addEventListener('keydown', (e) => {
    if (e.key === 'Escape') close();
    e.stopPropagation();
  });
  gear.addEventListener('click', () => (settings.hidden ? showSettings() : ((settings.hidden = true), place())));

  function open(next: Scope, around: Box | null) {
    pending?.controller.abort();
    pending = null;
    scope = next;
    anchor = around;
    applied = null;
    reading = null;
    input.value = '';
    settings.hidden = true;
    showKnobs([]);
    box.hidden = false;
    idle();
    place();
    input.focus();
    if (links.jev) warmJev(links.jev);
  }

  function close() {
    if (box.hidden) return;
    pending?.controller.abort();
    pending = null;
    clearTimeout(typingTimer);
    box.hidden = true;
    applied = null;
    scope = null;
    hooks.closed();
  }

  return {
    open,
    close,
    get isOpen() {
      return !box.hidden;
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
