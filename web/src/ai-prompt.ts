// The command field: it stands by the selection while there is one, or where
// the empty paper was clicked, and what is typed on the page goes into it
// (opening it if need be). A command in words goes to Jev while it is typed;
// Enter edits the score at once with what Jev read, or has Claude write the
// edit when Jev is not sure. A SCORE command runs as on WinScore's command
// bar, on the selection if there is one. Numbers the
// command leaves open appear as sliders under the field; dragging one re-does
// the edit with the new value, live, as the same undo step. While a group
// command asks for its area, the field shows the question and takes the
// answer. Up and Down recall earlier lines.
import type { Box } from './display';
import type { Change, Editor } from './editor';
import { onlyParams, reach, run, selects, type Access, type Knob, type Scope, type Script } from './ai-script';
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
  /** Runs a SCORE command line on the selection, as WinScore's command bar does (IN n, answers to a question too). */
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

/**
 * A SCORE command typed as such: upper-case words and numbers (R 5, FLI,
 * 600 5), a conditional edit (IF … THEN …) or a text's quick entry ("Allegro" 1 50).
 */
const looksLikeScore = (text: string) => /^[A-Z][A-Z0-9]*(\s+[-+]?[\d.]+)*$|^[-+]?[\d.]+(\s+[-+]?[\d.]+)+$|^IF\s|^"/.test(text.trim());

/** IN, IN n: music input, which the page opens. */
const opensInput = (text: string) => /^IN(\s+\d+)?$/.test(text.trim());

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
  const cancel = el('button', { className: 'ai-cancel', type: 'button', title: 'End the group edit without a change', textContent: 'Cancel' });
  const asking = el('div', { className: 'ai-question', hidden: true }, questionText, cancel);
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
          else show(`${UNREAD[jev.why ?? 'unsure']}${links.claude ? ': ↵ has Claude write it' : '; Claude could write it (⚙)'}`, '', `Jev · ${Math.round(jev.ms)} ms`);
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

  /** Whether a line goes to the page as WinScore's command bar sends it: an answer to the question, IN, or a SCORE command. */
  function native(text: string): boolean {
    return question !== null || opensInput(text) || (looksLikeScore(text) && hooks.supported(text));
  }

  function typed() {
    clearTimeout(typingTimer);
    reading = null;
    const text = input.value.trim();
    if (!text || question !== null) {
      pending?.controller.abort();
      pending = null;
      idle();
      return;
    }
    if (native(text)) {
      show(`→ ${text}`, '', 'SCORE command');
      return;
    }
    const about = scope && hooks.about(text, scope);
    const known = about && (memo.get(readingKey(about)) ?? memo.get(claudeKey(about)));
    if (known) {
      showReading(known);
      return;
    }
    if (!links.jev) {
      show(links.claude ? '↵ has Claude write it' : 'Commands in words need a model: set one up with ⚙', links.claude ? '' : 'error');
      return;
    }
    show('…', 'busy');
    typingTimer = window.setTimeout(() => askAbout(text), TYPING_PAUSE_MS);
  }

  /** Runs a reading on the score, as one undo step named after the command; why it failed, if it did. */
  function apply(r: Reading, text: string): string | null {
    const editor = hooks.editor();
    const access = hooks.access();
    if (!editor || !access || !scope) return null;
    let error: string | null = null;
    const label = `“${text}”`;
    const values = Object.fromEntries(r.script.knobs.map((k) => [k.id, k.value]));
    try {
      const ran = run(r.script, access, scope, label, values);
      applied = { script: r.script, scope, label, mark: ran.mark, depth: editor.mark(), values };
      input.value = '';
      reading = null;
      const done = ran.changed || selects(r.script);
      show(done ? `✓ ${r.script.summary}` : `${r.script.summary}: nothing changed`, done ? 'done' : 'error', r.source);
      showKnobs(r.script.knobs);
    } catch (err) {
      error = err instanceof Error ? err.message : String(err);
      show(error, 'error', r.source);
    }
    // The command leaves what it changed selected, and the next one is about that.
    edited(false, false);
    place();
    return error;
  }

  /** Runs a line on the page as WinScore's command bar runs it; the text stays to be corrected when the engine objects. */
  function runLine(text: string) {
    pending?.controller.abort();
    pending = null;
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

  async function enter() {
    const text = input.value.trim();
    if (!text || !scope) return;
    clearTimeout(typingTimer);
    if (history.at(-1) !== text) history.push(text);
    recalled = 0;
    if (native(text)) return void runLine(text);
    if (reading) return void apply(reading, text);
    const asked = pending?.text === text ? pending.done : askAbout(text);
    if (asked) {
      show('…', 'busy');
      const result = await asked;
      if (input.value.trim() !== text) return;
      if (result) return void apply(result, text);
    }
    const about = hooks.about(text, scope);
    if (writing === text) return;
    const claude = links.claude;
    if (!about || !claude) {
      show(links.jev ? 'Jev could not read this, and no Claude key is set (⚙)' : 'Commands in words need a model: set one up with ⚙', 'error');
      return;
    }
    show('Claude is writing the edit…', 'busy');
    const controller = new AbortController();
    pending = { text, controller, done: Promise.resolve(null) };
    writing = text;
    try {
      // A script that fails to run goes back to Claude once, with the error.
      let failed: Failed | undefined;
      for (let tries = 2; tries > 0; tries--) {
        const { script, ms, answer } = await askClaude(about, hooks.catalog(), claude, controller.signal, failed);
        if (input.value.trim() !== text) return;
        const result = { script, source: `Claude · ${(ms / 1000).toFixed(1)} s` };
        const error = apply(result, text);
        if (error === null) {
          memo.set(claudeKey(about), result);
          return;
        }
        failed = { answer, error };
        if (tries > 1) show(`${error}: Claude is correcting the edit…`, 'busy', 'Claude');
      }
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
    edited(live, onlyParams(applied.script));
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
  cancel.addEventListener('click', () => {
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
    pending?.controller.abort();
    pending = null;
    clearTimeout(typingTimer);
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
      typed();
    }
    place();
  }

  /** The field goes, and what was typed in it. */
  function close() {
    if (box.hidden) return;
    const focused = box.contains(document.activeElement);
    pending?.controller.abort();
    pending = null;
    clearTimeout(typingTimer);
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
