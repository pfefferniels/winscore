// The side panel: the selected item, with buttons for what can be done to
// it and its parameters, and below it the list of all items.
import { fillFontMenu } from './text-dialog';

export interface ItemSummary {
  index: number;
  code: number;
  name: string;
  staff: number;
  p3: number;
}

export interface ItemDetails extends ItemSummary {
  params: Float32Array;
  /** What each parameter means, from the WinScore help; null where it says nothing. */
  paramNames: (string | null)[];
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
  setParam(index: number, n: number, value: number): void;
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

function paramInput(item: ItemDetails, n: number, value: number, handlers: PanelHandlers): HTMLInputElement {
  const shown = formatParam(value);
  const input = element('input', { type: 'text', inputMode: 'decimal', value: shown, id: `p${n}` });
  const commit = () => {
    const parsed = Number.parseFloat(input.value);
    if (input.value === shown || !Number.isFinite(parsed)) {
      input.value = shown;
      return;
    }
    handlers.setParam(item.index, n, parsed);
  };
  input.addEventListener('input', () => input.classList.toggle('changed', input.value !== shown));
  input.addEventListener('blur', commit);
  input.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') commit();
    if (e.key === 'Escape') {
      input.value = shown;
      input.classList.remove('changed');
      input.blur();
    }
  });
  return input;
}

function addParamRow(item: ItemDetails, handlers: PanelHandlers): HTMLElement {
  const number = element('input', { type: 'number', min: '1', step: '1', placeholder: 'P', value: String(item.params.length + 1) });
  const value = element('input', { type: 'text', inputMode: 'decimal', placeholder: 'value' });
  const set = element('button', { type: 'button' }, ['Set']);
  set.addEventListener('click', () => {
    const n = Number.parseInt(number.value, 10);
    const v = Number.parseFloat(value.value);
    if (n >= 1 && Number.isFinite(v)) handlers.setParam(item.index, n, v);
  });
  return element('div', { className: 'add-param' }, [number, value, set]);
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
    section.replaceChildren(
      ...emptyState('Nothing selected', 'Click an item on the page or in the list below. Shift-click adds to the selection; dragging over empty paper selects what is inside.'),
    );
    return;
  }
  const row = (value: number, i: number) => {
    const name = item.paramNames[i];
    const cell = element('div', { className: 'param' }, [paramInput(item, i + 1, value, handlers)]);
    if (name) cell.append(element('span', { className: 'param-name' }, [name]));
    return [element('label', { htmlFor: `p${i + 1}` }, [`P${i + 1}`]), cell];
  };
  const grid = element('div', { className: 'params' }, Array.from(item.params, row).flat());
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
  section.replaceChildren(head, actions(handlers), ...notes, grid, addParamRow(item, handlers));
}
