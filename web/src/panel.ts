// The side panel: the selected item, with buttons for what can be done to
// it, its settings (item-fields.ts) and all its parameters, and below it the
// list of all items.
import { fillFontMenu } from './text-dialog';
import { sameValue, sectionsFor } from './item-fields';
import type { Change, ChoiceSetting, Context, NumberSetting, P, PairSetting, Setting } from './item-fields';

export interface ItemSummary {
  index: number;
  code: number;
  name: string;
  staff: number;
  p3: number;
}

export interface ItemDetails extends ItemSummary {
  params: Float32Array;
  /** What parameters P1, P2, … mean, from the WinScore help; null where it says nothing. */
  paramNames: (string | null)[];
  /** What its settings read from the rest of the score. */
  context: Context;
  text: string | null;
  /** Whether the Rust renderer drew anything for this item. */
  drawn: boolean;
  /** How many other items are selected with it. */
  others: number;
}

export interface PanelHandlers {
  select(index: number): void;
  /** Runs a SCORE command on the selection. */
  run(command: string): void;
  /** Sets parameters of item `index` as one undo step. */
  setParams(index: number, changes: Change[]): void;
  /** Picks a library symbol for a code-9 item in the symbol dialog. */
  pickSymbol(index: number): void;
  /** Replaces a text item's characters. */
  setText(index: number, text: string): void;
  /** Gives a text item one of WinScore's fonts (`_NN`). */
  setFont(index: number, code: number): void;
}

/** A float parameter as SCORE shows it: up to seven significant digits. */
export function formatParam(value: number): string {
  return String(Number.parseFloat(value.toPrecision(7)));
}

function element<K extends keyof HTMLElementTagNameMap>(
  tag: K,
  props: Record<string, string | number | boolean> = {},
  children: (Node | string)[] = [],
): HTMLElementTagNameMap[K] {
  const node = document.createElement(tag);
  Object.assign(node, props);
  node.append(...children);
  return node;
}

/** What a row shows; rows whose key is unchanged are kept as they are. */
function rowKey(item: ItemSummary): string {
  return `${item.index} ${item.code} ${item.staff} ${item.p3}`;
}

function itemRow(item: ItemSummary, handlers: PanelHandlers): HTMLLIElement {
  const row = element('li', { title: `Item ${item.index}: ${item.name}` }, [
    element('span', { className: 'index' }, [String(item.index)]),
    element('span', {}, [`${item.code} ${item.name}`]),
    element('span', { className: 'where' }, [`${formatParam(item.staff)} · ${formatParam(item.p3)}`]),
  ]);
  row.dataset.index = String(item.index);
  row.dataset.code = String(item.code);
  row.dataset.name = item.name;
  row.dataset.key = rowKey(item);
  row.addEventListener('click', () => handlers.select(item.index));
  return row;
}

/**
 * Whether a row matches the filter: a number matches the item's code or
 * index, a word the name of its kind.
 */
function matches(row: HTMLLIElement, query: string): boolean {
  if (!query) return true;
  if (/^\d+$/.test(query)) return row.dataset.code === query || row.dataset.index === query;
  return (row.dataset.name ?? '').toLowerCase().includes(query.toLowerCase());
}

/** Shows only the rows that match `query`; returns how many do. */
export function filterItemList(list: HTMLOListElement, query: string): number {
  let shown = 0;
  for (const row of list.children as HTMLCollectionOf<HTMLLIElement>) {
    row.hidden = !matches(row, query.trim());
    if (!row.hidden) shown++;
  }
  return shown;
}

/** Brings the list up to date, rebuilding only the rows that changed (a page has a thousand items or more). */
export function renderItemList(list: HTMLOListElement, items: ItemSummary[], handlers: PanelHandlers) {
  const rows = list.children as HTMLCollectionOf<HTMLLIElement>;
  items.forEach((item, i) => {
    const row = rows[i];
    if (row?.dataset.key === rowKey(item)) return;
    const fresh = itemRow(item, handlers);
    if (row) row.replaceWith(fresh);
    else list.append(fresh);
  });
  while (rows.length > items.length) rows[rows.length - 1]!.remove();
}

/** Marks the rows of `items` and scrolls the last one into view. */
export function markSelected(list: HTMLOListElement, items: number[]) {
  list.querySelectorAll('li.selected').forEach((li) => li.classList.remove('selected'));
  const rows = items.map((index) => list.querySelector<HTMLLIElement>(`li[data-index="${index}"]`));
  rows.forEach((row) => row?.classList.add('selected'));
  rows.at(-1)?.scrollIntoView({ block: 'nearest' });
}

/**
 * An item's parameters as SCORE shows them, to seven significant digits, so
 * that what settings derive from them (201.31 less its hundreds) has no
 * single-precision noise; unset ones are 0.
 */
function reader(params: Float32Array): P {
  return (n) => Number(formatParam(params[n - 1] ?? 0));
}

/** Sends the changes that change something. */
function apply(item: ItemDetails, p: P, changes: Change[], handlers: PanelHandlers) {
  const real = changes.filter(([n, v]) => Number.isFinite(v) && Math.fround(v) !== Math.fround(p(n)));
  if (real.length > 0) handlers.setParams(item.index, real);
}

/** Rounds away the binary noise of stepping by tenths. */
const tidy = (v: number) => Math.round(v * 1e6) / 1e6;

/**
 * A text field that sets something on Enter or when left, steps with ↑/↓
 * (Shift: ten steps) and goes back to what it showed on Escape. Leaving it
 * sets the value after the keyboard has moved on, so the panel drawn anew
 * puts it in the next field.
 */
function editField(id: string, shown: string, set: (text: string) => boolean, step?: (delta: number) => void): HTMLInputElement {
  const input = element('input', { type: 'text', value: shown, id, spellcheck: false, autocomplete: 'off' });
  // The panel is drawn anew after a change; a blur of this field on its way out must not set it twice.
  let done = false;
  const commit = () => {
    if (done || input.value === shown) return;
    if (set(input.value)) done = true;
    else input.classList.add('invalid');
  };
  input.addEventListener('input', () => {
    input.classList.toggle('changed', input.value !== shown);
    input.classList.remove('invalid');
  });
  input.addEventListener('blur', () => setTimeout(commit));
  input.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') commit();
    else if (e.key === 'Escape') {
      input.value = shown;
      input.classList.remove('changed', 'invalid');
      input.blur();
    } else if (step && (e.key === 'ArrowUp' || e.key === 'ArrowDown')) {
      e.preventDefault();
      step((e.key === 'ArrowUp' ? 1 : -1) * (e.shiftKey ? 10 : 1));
    } else return;
    e.stopPropagation();
  });
  return input;
}

function numberInput(s: NumberSetting, item: ItemDetails, p: P, handlers: PanelHandlers): HTMLInputElement {
  const value = s.get(p);
  const input = editField(
    s.id,
    formatParam(value),
    (text) => {
      const parsed = Number.parseFloat(text);
      if (!Number.isFinite(parsed)) return false;
      apply(item, p, s.set(parsed, p), handlers);
      return true;
    },
    (delta) => apply(item, p, s.set(tidy(value + delta * s.step), p), handlers),
  );
  input.inputMode = 'decimal';
  return input;
}

function note(text: string | null | undefined): HTMLElement[] {
  return text ? [element('span', { className: 'setting-note' }, [text])] : [];
}

function choiceControl(s: ChoiceSetting, item: ItemDetails, p: P, handlers: PanelHandlers): HTMLElement {
  const current = s.get(p);
  const chosen = s.options.findIndex((o) => sameValue(o.value, current));
  const pick = (i: number) => apply(item, p, s.set(s.options[i]!.value, p), handlers);
  if (s.buttons) {
    const buttons = s.options.map((o, i) => {
      const button = element('button', { type: 'button', id: `${s.id}-${i}`, textContent: o.label, className: i === chosen ? 'on' : '' });
      button.setAttribute('aria-pressed', String(i === chosen));
      button.addEventListener('click', () => pick(i));
      return button;
    });
    const group = element('div', { className: 'segmented' }, buttons);
    group.setAttribute('role', 'group');
    return element('div', { className: 'setting-control' }, [group, ...note(chosen < 0 ? s.other?.(p) : null)]);
  }
  const select = element('select', { id: s.id });
  if (chosen < 0) select.append(new Option(s.other?.(p) ?? `Other (${formatParam(current)})`, '', true, true));
  select.append(...s.options.map((o, i) => new Option(o.label, String(i), false, i === chosen)));
  if (chosen < 0) select.options[0]!.disabled = true;
  select.addEventListener('change', () => pick(Number(select.value)));
  return select;
}

/** The control of one setting, and the element its label points at. */
function control(s: Exclude<Setting, PairSetting>, item: ItemDetails, p: P, handlers: PanelHandlers): HTMLElement {
  switch (s.kind) {
    case 'number': {
      const input = numberInput(s, item, p, handlers);
      const pick = s.pick === 'symbol' ? [chooseButton(item, handlers)] : [];
      const row = pick.length ? [element('div', { className: 'with-button' }, [input, ...pick])] : [input];
      return element('div', { className: 'setting-control' }, [...row, ...note(s.note?.(s.get(p), p, item.context))]);
    }
    case 'choice':
      return choiceControl(s, item, p, handlers);
    case 'toggle': {
      const box = element('input', { type: 'checkbox', id: s.id, checked: s.get(p) });
      box.addEventListener('change', () => apply(item, p, s.set(box.checked, p), handlers));
      return element('div', { className: 'setting-control toggle' }, [box]);
    }
    case 'text': {
      const ctx = item.context;
      const input = editField(
        s.id,
        s.show(p, ctx),
        (text) => {
          const changes = s.parse(text, p, ctx);
          if (changes) apply(item, p, changes, handlers);
          return changes !== null;
        },
        (delta) => apply(item, p, s.step(delta, p, ctx), handlers),
      );
      if (s.placeholder) input.placeholder = s.placeholder;
      return element('div', { className: 'setting-control' }, [input, ...note(s.note?.(p, ctx))]);
    }
  }
}

function chooseButton(item: ItemDetails, handlers: PanelHandlers): HTMLButtonElement {
  const button = element('button', { type: 'button', textContent: 'Choose…', title: 'Pick the symbol from the libraries' });
  button.addEventListener('click', () => handlers.pickSymbol(item.index));
  return button;
}

function pairControl(s: PairSetting, item: ItemDetails, p: P, handlers: PanelHandlers): HTMLElement {
  const halves = s.fields.map((f) =>
    element('div', { className: 'pair-half' }, [
      numberInput(f, item, p, handlers),
      element('label', { htmlFor: f.id, className: 'setting-note' }, [[f.label, f.note?.(f.get(p), p, item.context)].filter(Boolean).join(' · ')]),
    ]),
  );
  return element('div', { className: 'setting-control pair' }, halves);
}

/** Label and control of one setting: a row of the settings grid. */
function settingRow(s: Setting, item: ItemDetails, p: P, handlers: PanelHandlers): HTMLElement[] {
  const target = s.kind === 'pair' ? s.fields[0].id : s.kind === 'choice' && s.buttons ? '' : s.id;
  const label = element('label', { className: 'setting-label', title: s.help ?? s.label }, [s.label]);
  if (target) label.htmlFor = target;
  const body = s.kind === 'pair' ? pairControl(s, item, p, handlers) : control(s, item, p, handlers);
  if (s.help) body.title = s.help;
  return [label, body];
}

function sections(item: ItemDetails, handlers: PanelHandlers): HTMLElement[] {
  const p = reader(item.params);
  return sectionsFor(item.code).flatMap((section) => {
    const shown = section.settings.filter((s) => s.when?.(p) ?? true);
    if (shown.length === 0) return [];
    const rows = shown.flatMap((s) => settingRow(s, item, p, handlers));
    return [element('section', { className: 'settings' }, [element('h3', {}, [section.title]), element('div', { className: 'settings-grid' }, rows)])];
  });
}

const ALL_PARAMS_KEY = 'winscore.allParams';

function allParamsOpen(): boolean {
  try {
    return localStorage.getItem(ALL_PARAMS_KEY) === 'open';
  } catch {
    return false;
  }
}

function rememberAllParams(open: boolean) {
  try {
    localStorage.setItem(ALL_PARAMS_KEY, open ? 'open' : 'closed');
  } catch {
    // The setting is a convenience; without storage it is not kept.
  }
}

/** Highest parameter number an edit may set; the engine ignores `46 v` and above. */
const MAX_PARAM = 45;

/**
 * Every parameter P1…Pn as SCORE stores it, with the help's label, and those
 * the help describes but the item does not store; below them any other
 * parameter by number.
 */
function allParams(item: ItemDetails, handlers: PanelHandlers): HTMLDetailsElement {
  const p = reader(item.params);
  const count = Math.max(item.params.length, item.paramNames.length);
  const rows = Array.from({ length: count }, (_, i) => {
    const n = i + 1;
    const stored = n <= item.params.length;
    const input = editField(`all-p${n}`, stored ? formatParam(p(n)) : '', (text) => {
      const parsed = Number.parseFloat(text);
      if (!Number.isFinite(parsed)) return false;
      apply(item, p, [[n, parsed]], handlers);
      return true;
    });
    input.inputMode = 'decimal';
    if (!stored) input.placeholder = '0';
    const name = item.paramNames[i];
    const cell = element('div', { className: 'param' }, [input, ...(name ? [element('span', { className: 'param-name' }, [name])] : [])]);
    return [element('label', { htmlFor: input.id }, [`P${n}`]), cell];
  });
  const number = element('input', { type: 'number', min: '1', max: String(MAX_PARAM), step: '1', placeholder: 'P', id: 'all-other-n' });
  const value = element('input', { type: 'text', inputMode: 'decimal', placeholder: 'value', id: 'all-other-v' });
  const set = element('button', { type: 'button' }, ['Set']);
  set.addEventListener('click', () => {
    const n = Number.parseInt(number.value, 10);
    const v = Number.parseFloat(value.value);
    if (n >= 1 && n <= MAX_PARAM && Number.isFinite(v)) apply(item, p, [[n, v]], handlers);
  });
  const other = element('div', { className: 'add-param', title: 'Any other parameter, by number' }, [number, value, set]);
  const details = element('details', { className: 'all-params', open: allParamsOpen() }, [
    element('summary', {}, ['All parameters']),
    element('div', { className: 'params' }, rows.flat()),
    other,
  ]);
  details.addEventListener('toggle', () => rememberAllParams(details.open));
  return details;
}

/** The characters of a text item, editable, and a font menu for it. */
function textEditor(item: ItemDetails, text: string, handlers: PanelHandlers): HTMLElement {
  const input = element('input', { type: 'text', value: text, id: 'item-text', spellcheck: false, title: 'Text (P12 characters); Enter sets it' });
  input.addEventListener('keydown', (e) => {
    if (e.key === 'Enter' && input.value !== text) handlers.setText(item.index, input.value);
    if (e.key === 'Escape') input.value = text;
  });
  const font = element('select', { id: 'item-font', title: "WinScore's font menu (FNTnn)" });
  fillFontMenu(font, 'Font…');
  font.addEventListener('change', () => {
    if (Number(font.value) >= 0) handlers.setFont(item.index, Number(font.value));
  });
  return element('div', { className: 'text-editor' }, [input, font]);
}

/** A button that sends `command` to the selection. */
function commandButton(label: string, command: string, title: string, handlers: PanelHandlers, className = ''): HTMLButtonElement {
  const button = element('button', { type: 'button', textContent: label, title: `${title} (${command})`, className });
  button.dataset.command = command;
  button.addEventListener('click', () => handlers.run(command));
  return button;
}

/** What can be done to the selection: WinScore's edit-mode buttons. */
function actions(handlers: PanelHandlers): HTMLElement {
  const nudge = element('div', { className: 'nudge' }, [
    commandButton('←', 'L1', 'Left one step, also ←', handlers),
    commandButton('→', 'R1', 'Right one step, also →', handlers),
    commandButton('↑', 'U1', 'Up one step, also ↑', handlers),
    commandButton('↓', 'D1', 'Down one step, also ↓', handlers),
  ]);
  nudge.setAttribute('role', 'group');
  nudge.setAttribute('aria-label', 'Move');
  return element('div', { className: 'item-actions' }, [
    nudge,
    commandButton('Flip', 'FLI', 'Flip the stem, curve or symbol', handlers),
    commandButton('Center', 'CN', 'Center on the nearest note or rest', handlers),
  ]);
}

const TRASH = '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="M4 7h16M10 11v6M14 11v6M6 7l1 12a2 2 0 0 0 2 2h6a2 2 0 0 0 2-2l1-12M9 7V4h6v3" /></svg>';

function emptyState(title: string, text: string): HTMLElement[] {
  return [element('h2', {}, [title]), element('p', { className: 'muted hint' }, [text])];
}

export function renderItem(section: HTMLElement, item: ItemDetails | null, handlers: PanelHandlers, hasScore = true) {
  if (!hasScore) {
    section.replaceChildren(...emptyState('No score open', 'Start a new score or open one from the File menu.'));
    return;
  }
  if (!item) {
    const touch = matchMedia('(pointer: coarse)').matches;
    section.replaceChildren(
      ...emptyState(
        'Nothing selected',
        touch
          ? 'Tap an item on the page or in the list below. A long press adds to the selection; a long press and a drag select what is inside a box.'
          : 'Click an item on the page or in the list below. Shift-click adds to the selection; dragging over empty paper selects what is inside.',
      ),
    );
    return;
  }
  const notes: HTMLElement[] = [
    ...(item.text !== null ? [textEditor(item, item.text, handlers)] : []),
    ...(item.drawn ? [] : [element('p', { className: 'muted' }, ['The Rust renderer does not draw this item yet.'])]),
  ];
  const others = item.others > 0 ? [element('span', { className: 'muted' }, [` (+${item.others} selected)`])] : [];
  const remove = commandButton('', 'DE', 'Delete, also Del', handlers, 'danger');
  remove.innerHTML = TRASH;
  remove.setAttribute('aria-label', 'Delete');
  const step = element('div', { className: 'item-step' }, [
    remove,
    commandButton('‹', 'B', 'Previous item, also Shift+Enter', handlers),
    commandButton('›', 'NEX', 'Next item, also Enter', handlers),
  ]);
  const head = element('header', { className: 'item-head' }, [element('h2', {}, [`Item ${item.index} · ${item.name}`, ...others]), step]);
  section.replaceChildren(head, actions(handlers), ...notes, ...sections(item, handlers), allParams(item, handlers));
}

/**
 * Under the page (a narrow screen), the panel's top edge is a grip: dragging
 * it sets how much of the height the panel takes, between a fifth and most.
 */
export function bindPanelGrip(panel: HTMLElement, grip: HTMLElement) {
  grip.addEventListener('pointerdown', (e) => {
    const area = panel.parentElement!.getBoundingClientRect();
    const offset = e.clientY - panel.getBoundingClientRect().top;
    grip.setPointerCapture(e.pointerId);
    const move = (m: PointerEvent) => {
      const share = (area.bottom - (m.clientY - offset)) / area.height;
      panel.style.setProperty('--panel-share', `${(Math.min(0.85, Math.max(0.2, share)) * 100).toFixed(1)}%`);
    };
    const end = () => {
      grip.removeEventListener('pointermove', move);
      grip.removeEventListener('pointerup', end);
      grip.removeEventListener('pointercancel', end);
    };
    grip.addEventListener('pointermove', move);
    grip.addEventListener('pointerup', end);
    grip.addEventListener('pointercancel', end);
    e.preventDefault();
  });
}
