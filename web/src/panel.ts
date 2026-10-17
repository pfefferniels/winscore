// The side panel: the selection, with buttons for what can be done to it,
// its settings (item-fields.ts) and all its parameters, and below it the
// list of all items. Several selected items are edited together: a setting
// shows their value where they agree and "Mixed" where they do not, and a
// change sets it in every one of them as one undo step.
import { fillFontMenu } from './text-dialog';
import { sameValue, sharedSections } from './item-fields';
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
  /** Whether the Rust renderer drew anything for this item; asked only when it is selected alone. */
  drawn?: boolean;
}

/** The changes to one item, by index. */
export type ItemChanges = [index: number, changes: Change[]];

export interface PanelHandlers {
  select(index: number): void;
  /** Adds an item to the selection or takes it out. */
  toggle(index: number): void;
  /** Selects these items, the last one primary. */
  selectItems(items: number[]): void;
  /** Runs a SCORE command on the selection. */
  run(command: string): void;
  /** Sets parameters of items, each with changes of its own, as one undo step. */
  setParams(edits: ItemChanges[]): void;
  /** Picks a library symbol for code-9 items in the symbol dialog. */
  pickSymbol(items: number[]): void;
  /** Replaces a text item's characters. */
  setText(index: number, text: string): void;
  /** Gives text items one of WinScore's fonts (`_NN`). */
  setFont(items: number[], code: number): void;
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
  row.addEventListener('click', (e) => (e.shiftKey || e.metaKey || e.ctrlKey ? handlers.toggle(item.index) : handlers.select(item.index)));
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

/** The items whose rows the filter shows. */
export function shownItems(list: HTMLOListElement): number[] {
  return [...(list.children as HTMLCollectionOf<HTMLLIElement>)].filter((row) => !row.hidden).map((row) => Number(row.dataset.index));
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

/** A selected item with its parameters as the settings read them. */
interface Member {
  item: ItemDetails;
  p: P;
}

/** What all `values` are, or null where they differ. */
function common<T>(values: T[], same: (a: T, b: T) => boolean = (a, b) => a === b): T | null {
  const [first] = values;
  return first !== undefined && values.every((v) => same(v, first)) ? first : null;
}

/** Equal values of a setting; one that cannot read an item gives NaN, equal to NaN. */
const sameNumber = (a: number, b: number) => sameValue(a, b) || (Number.isNaN(a) && Number.isNaN(b));

/** How a field shows a setting whose value differs between the selected items. */
function showMixed(input: HTMLInputElement) {
  input.placeholder = 'Mixed';
  input.classList.add('mixed');
}

/**
 * Sends, as one step, what `edit` changes in each item that changes
 * something; false, sending nothing, when it cannot be read for one of them.
 */
function apply(members: Member[], edit: (p: P, ctx: Context) => Change[] | null, handlers: PanelHandlers): boolean {
  const edits: ItemChanges[] = [];
  for (const { item, p } of members) {
    const changes = edit(p, item.context);
    if (!changes) return false;
    const real = changes.filter(([n, v]) => Number.isFinite(v) && Math.fround(v) !== Math.fround(p(n)));
    if (real.length > 0) edits.push([item.index, real]);
  }
  if (edits.length > 0) handlers.setParams(edits);
  return true;
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

/** A typed value goes to every item; ↑/↓ step each from its own. */
function numberInput(s: NumberSetting, members: Member[], handlers: PanelHandlers): HTMLInputElement {
  const value = common(members.map(({ p }) => s.get(p)), sameNumber);
  const input = editField(
    s.id,
    value === null ? '' : formatParam(value),
    (text) => {
      const parsed = Number.parseFloat(text);
      return Number.isFinite(parsed) && apply(members, (p) => s.set(parsed, p), handlers);
    },
    (delta) => apply(members, (p) => s.set(tidy(s.get(p) + delta * s.step), p), handlers),
  );
  input.inputMode = 'decimal';
  if (value === null) showMixed(input);
  return input;
}

/** The reading under a number field, where the items agree on it. */
function numberNote(s: NumberSetting, members: Member[]): string | null {
  return common(members.map(({ item, p }) => s.note?.(s.get(p), p, item.context) ?? null));
}

function note(text: string | null | undefined): HTMLElement[] {
  return text ? [element('span', { className: 'setting-note' }, [text])] : [];
}

function choiceControl(s: ChoiceSetting, members: Member[], handlers: PanelHandlers): HTMLElement {
  const current = common(members.map(({ p }) => s.get(p)), sameNumber);
  const chosen = current === null ? -1 : s.options.findIndex((o) => sameValue(o.value, current));
  // What a value that is none of the options reads as, where the items agree on it.
  const other = current === null ? null : common(members.map(({ p }) => s.other?.(p) ?? null));
  const pick = (i: number) => apply(members, (p) => s.set(s.options[i]!.value, p), handlers);
  if (s.buttons) {
    const buttons = s.options.map((o, i) => {
      const button = element('button', { type: 'button', id: `${s.id}-${i}`, textContent: o.label, className: i === chosen ? 'on' : '' });
      button.setAttribute('aria-pressed', String(i === chosen));
      button.addEventListener('click', () => pick(i));
      return button;
    });
    const group = element('div', { className: 'segmented' }, buttons);
    group.setAttribute('role', 'group');
    return element('div', { className: 'setting-control' }, [group, ...note(chosen >= 0 ? null : current === null ? 'Mixed' : other)]);
  }
  const select = element('select', { id: s.id });
  if (chosen < 0) {
    const shown = current === null ? 'Mixed' : (other ?? (s.other ? 'Mixed' : `Other (${formatParam(current)})`));
    select.append(new Option(shown, '', true, true));
  }
  select.append(...s.options.map((o, i) => new Option(o.label, String(i), false, i === chosen)));
  if (chosen < 0) select.options[0]!.disabled = true;
  select.addEventListener('change', () => pick(Number(select.value)));
  return select;
}

/** The control of one setting, and the element its label points at. */
function control(s: Exclude<Setting, PairSetting>, members: Member[], handlers: PanelHandlers): HTMLElement {
  switch (s.kind) {
    case 'number': {
      const input = numberInput(s, members, handlers);
      const pick = s.pick === 'symbol' ? [chooseButton(members, handlers)] : [];
      const row = pick.length ? [element('div', { className: 'with-button' }, [input, ...pick])] : [input];
      return element('div', { className: 'setting-control' }, [...row, ...note(numberNote(s, members))]);
    }
    case 'choice':
      return choiceControl(s, members, handlers);
    case 'toggle': {
      const on = common(members.map(({ p }) => s.get(p)));
      const box = element('input', { type: 'checkbox', id: s.id, checked: on === true, indeterminate: on === null });
      box.addEventListener('change', () => apply(members, (p) => s.set(box.checked, p), handlers));
      return element('div', { className: 'setting-control toggle' }, [box]);
    }
    case 'text': {
      const shown = common(members.map(({ item, p }) => s.show(p, item.context)));
      const input = editField(
        s.id,
        shown ?? '',
        (text) => apply(members, (p, ctx) => s.parse(text, p, ctx), handlers),
        (delta) => apply(members, (p, ctx) => s.step(delta, p, ctx), handlers),
      );
      if (shown === null) showMixed(input);
      else if (s.placeholder) input.placeholder = s.placeholder;
      const reading = common(members.map(({ item, p }) => s.note?.(p, item.context) ?? null));
      return element('div', { className: 'setting-control' }, [input, ...note(reading)]);
    }
  }
}

function chooseButton(members: Member[], handlers: PanelHandlers): HTMLButtonElement {
  const button = element('button', { type: 'button', textContent: 'Choose…', title: 'Pick the symbol from the libraries' });
  button.addEventListener('click', () => handlers.pickSymbol(members.map(({ item }) => item.index)));
  return button;
}

function pairControl(s: PairSetting, members: Member[], handlers: PanelHandlers): HTMLElement {
  const halves = s.fields.map((f) =>
    element('div', { className: 'pair-half' }, [
      numberInput(f, members, handlers),
      element('label', { htmlFor: f.id, className: 'setting-note' }, [[f.label, numberNote(f, members)].filter(Boolean).join(' · ')]),
    ]),
  );
  return element('div', { className: 'setting-control pair' }, halves);
}

/**
 * Label and control of one setting: a row of the settings grid. `of` is how
 * many items are selected; under the label, how many of them the setting
 * fits when not all.
 */
function settingRow(s: Setting, members: Member[], of: number, handlers: PanelHandlers): HTMLElement[] {
  const target = s.kind === 'pair' ? s.fields[0].id : s.kind === 'choice' && s.buttons ? '' : s.id;
  const some = members.length < of;
  const title = [s.help ?? s.label, some ? `Applies to the ${members.length} of the ${of} selected items it fits.` : ''].filter(Boolean).join(' ');
  const label = element('label', { className: 'setting-label', title }, [
    s.label,
    ...(some ? [element('span', { className: 'setting-some' }, [`${members.length} of ${of}`])] : []),
  ]);
  if (target) label.htmlFor = target;
  const body = s.kind === 'pair' ? pairControl(s, members, handlers) : control(s, members, handlers);
  if (s.help) body.title = s.help;
  return [label, body];
}

/** The settings the selected items share, each for the items it fits. */
function sections(members: Member[], handlers: PanelHandlers): HTMLElement[] {
  const codes = [...new Set(members.map(({ item }) => item.code))];
  return sharedSections(codes).flatMap((section) => {
    const rows = section.settings.flatMap((s) => {
      const fit = members.filter(({ p }) => s.when?.(p) ?? true);
      return fit.length > 0 ? settingRow(s, fit, members.length, handlers) : [];
    });
    if (rows.length === 0) return [];
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
 * parameter by number. For several items, a value set here goes to each, and
 * a label shows where their kinds agree on it.
 */
function allParams(members: Member[], handlers: PanelHandlers): HTMLDetailsElement {
  const count = Math.max(...members.map(({ item }) => Math.max(item.params.length, item.paramNames.length)));
  const rows = Array.from({ length: count }, (_, i) => {
    const n = i + 1;
    const stored = members.some(({ item }) => n <= item.params.length);
    const value = common(members.map(({ p }) => p(n)));
    const input = editField(`all-p${n}`, stored && value !== null ? formatParam(value) : '', (text) => {
      const parsed = Number.parseFloat(text);
      return Number.isFinite(parsed) && apply(members, () => [[n, parsed]], handlers);
    });
    input.inputMode = 'decimal';
    if (!stored) input.placeholder = '0';
    else if (value === null) showMixed(input);
    const name = common(members.map(({ item }) => item.paramNames[i] ?? null));
    const cell = element('div', { className: 'param' }, [input, ...(name ? [element('span', { className: 'param-name' }, [name])] : [])]);
    return [element('label', { htmlFor: input.id }, [`P${n}`]), cell];
  });
  const number = element('input', { type: 'number', min: '1', max: String(MAX_PARAM), step: '1', placeholder: 'P', id: 'all-other-n' });
  const value = element('input', { type: 'text', inputMode: 'decimal', placeholder: 'value', id: 'all-other-v' });
  const set = element('button', { type: 'button' }, ['Set']);
  set.addEventListener('click', () => {
    const n = Number.parseInt(number.value, 10);
    const v = Number.parseFloat(value.value);
    if (n >= 1 && n <= MAX_PARAM && Number.isFinite(v)) apply(members, () => [[n, v]], handlers);
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

/** WinScore's font menu, for text items. */
function fontMenu(items: number[], handlers: PanelHandlers): HTMLSelectElement {
  const font = element('select', { id: 'item-font', title: "WinScore's font menu (FNTnn)" });
  fillFontMenu(font, 'Font…');
  font.addEventListener('change', () => {
    if (Number(font.value) >= 0) handlers.setFont(items, Number(font.value));
  });
  return font;
}

/** The characters of a text item, editable, and a font menu for it. */
function textEditor(item: ItemDetails, text: string, handlers: PanelHandlers): HTMLElement {
  const input = element('input', { type: 'text', value: text, id: 'item-text', spellcheck: false, title: 'Text (P12 characters); Enter sets it' });
  input.addEventListener('keydown', (e) => {
    if (e.key === 'Enter' && input.value !== text) handlers.setText(item.index, input.value);
    if (e.key === 'Escape') input.value = text;
  });
  return element('div', { className: 'text-editor' }, [input, fontMenu([item.index], handlers)]);
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

/**
 * What a selection of several items says of itself: how many, and when they
 * are of different kinds, a button per kind that selects only those.
 */
function selectionHead(members: Member[], step: HTMLElement, handlers: PanelHandlers): HTMLElement[] {
  const kinds = new Map<number, ItemDetails[]>();
  for (const { item } of members) kinds.set(item.code, [...(kinds.get(item.code) ?? []), item]);
  const only = kinds.size === 1 ? [element('span', { className: 'muted' }, [` · ${members[0]!.item.name}`])] : [];
  const head = element('header', { className: 'item-head' }, [element('h2', {}, [`${members.length} items`, ...only]), step]);
  if (kinds.size === 1) return [head];
  const chips = [...kinds.values()].map((items) => {
    const { name } = items[0]!;
    const button = element('button', { type: 'button', title: `Select only the ${items.length} of kind ${name}` }, [
      element('span', {}, [name]),
      element('span', { className: 'count' }, [String(items.length)]),
    ]);
    button.addEventListener('click', () => handlers.selectItems(items.map((item) => item.index)));
    return button;
  });
  const row = element('div', { className: 'item-kinds' }, chips);
  row.setAttribute('role', 'group');
  row.setAttribute('aria-label', 'Select only one kind');
  return [head, row];
}

/** The panel for the selected items, the primary one last. */
export function renderSelection(section: HTMLElement, items: ItemDetails[], handlers: PanelHandlers, hasScore = true) {
  if (!hasScore) {
    section.replaceChildren(...emptyState('No score open', 'Start a new score or open one from the File menu.'));
    return;
  }
  const members = items.map((item) => ({ item, p: reader(item.params) }));
  const item = members.length === 1 ? members[0]!.item : null;
  if (members.length === 0) {
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
  const notes: HTMLElement[] = item
    ? [
        ...(item.text !== null ? [textEditor(item, item.text, handlers)] : []),
        ...(item.drawn === false ? [element('p', { className: 'muted' }, ['The Rust renderer does not draw this item yet.'])] : []),
      ]
    : [
        element('p', { className: 'muted hint batch-hint' }, ['A setting changed here changes in all of them; ↑/↓ step each from its own value.']),
        ...(items.every((i) => i.text !== null) ? [element('div', { className: 'text-editor' }, [fontMenu(items.map((i) => i.index), handlers)])] : []),
      ];
  const remove = commandButton('', 'DE', 'Delete, also Del', handlers, 'danger');
  remove.innerHTML = TRASH;
  remove.setAttribute('aria-label', 'Delete');
  const step = element('div', { className: 'item-step' }, [
    remove,
    commandButton('‹', 'B', 'Previous item, also Shift+Enter', handlers),
    commandButton('›', 'NEX', 'Next item, also Enter', handlers),
  ]);
  const head = item
    ? [element('header', { className: 'item-head' }, [element('h2', {}, [`Item ${item.index} · ${item.name}`]), step])]
    : selectionHead(members, step, handlers);
  section.replaceChildren(...head, actions(handlers), ...notes, ...sections(members, handlers), allParams(members, handlers));
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
