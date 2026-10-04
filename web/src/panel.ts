// The side panel: the item list and the parameters of the selected item.

export interface ItemSummary {
  index: number;
  code: number;
  name: string;
  staff: number;
  p3: number;
}

export interface ItemDetails extends ItemSummary {
  params: Float32Array;
  text: string | null;
  /** Whether the Rust renderer drew anything for this item. */
  drawn: boolean;
}

export interface PanelHandlers {
  select(index: number): void;
  setParam(index: number, n: number, value: number): void;
}

/** A float parameter as SCORE shows it: up to seven significant digits. */
export function formatParam(value: number): string {
  return String(Number.parseFloat(value.toPrecision(7)));
}

function element<K extends keyof HTMLElementTagNameMap>(tag: K, props: Partial<HTMLElementTagNameMap[K]> = {}, children: (Node | string)[] = []) {
  const node = Object.assign(document.createElement(tag), props);
  node.append(...children);
  return node;
}

function itemRow(item: ItemSummary, handlers: PanelHandlers): HTMLLIElement {
  const row = element('li', { title: `Item ${item.index}: ${item.name}` }, [
    element('span', { className: 'index' }, [String(item.index)]),
    element('span', {}, [`${item.code} ${item.name}`]),
    element('span', { className: 'where' }, [`${formatParam(item.staff)} · ${formatParam(item.p3)}`]),
  ]);
  row.dataset.index = String(item.index);
  row.addEventListener('click', () => handlers.select(item.index));
  return row;
}

export function renderItemList(list: HTMLOListElement, items: ItemSummary[], handlers: PanelHandlers) {
  list.replaceChildren(...items.map((item) => itemRow(item, handlers)));
}

export function markSelected(list: HTMLOListElement, index: number | null) {
  list.querySelectorAll('li.selected').forEach((li) => li.classList.remove('selected'));
  if (index === null) return;
  const row = list.querySelector<HTMLLIElement>(`li[data-index="${index}"]`);
  row?.classList.add('selected');
  row?.scrollIntoView({ block: 'nearest' });
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

export function renderItem(section: HTMLElement, item: ItemDetails | null, handlers: PanelHandlers) {
  if (!item) {
    section.replaceChildren(
      element('h2', {}, ['No item selected']),
      element('p', { className: 'muted' }, ['Click an item on the page or in the list below.']),
    );
    return;
  }
  const grid = element(
    'div',
    { className: 'params' },
    Array.from(item.params, (value, i) => [element('label', { htmlFor: `p${i + 1}` }, [`P${i + 1}`]), paramInput(item, i + 1, value, handlers)]).flat(),
  );
  const notes = [
    item.text !== null ? element('div', { className: 'text-value', title: 'Text (P12 characters)' }, [item.text]) : null,
    item.drawn ? null : element('p', { className: 'muted' }, ['The Rust renderer does not draw this item yet.']),
  ].filter((node): node is HTMLElement => node !== null);
  section.replaceChildren(
    element('h2', {}, [`Item ${item.index} · ${item.name}`]),
    grid,
    ...notes,
    addParamRow(item, handlers),
  );
}
