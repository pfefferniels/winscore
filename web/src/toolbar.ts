// The palette beside the page, with the select tool and the insertion modes
// (tools.ts), each with its key, and the bar under the app bar with the
// options of the mode in force.
// Keys on the page choose a mode (N a note, S a slur …); the mode's own key
// again, V or Escape go back to selecting. In a mode, 1 … 9 pick from its
// first row of options (for notes and rests the value, from the 64th to the
// breve) and . sets a dot or takes it off.
import { SELECT, type Group, type Tool } from './tools';

export interface ToolbarHooks {
  /** Whether a score is open, so a mode can be chosen. */
  ready(): boolean;
  /** Whether a gesture on the page is in progress, which keeps its keys (Escape cancels it). */
  busy(): boolean;
  /** The mode changed; null is selecting. */
  changed(tool: Tool | null): void;
  /** An option of the mode changed. */
  optionChanged(tool: Tool): void;
  /** Opens the chooser of a `choose` option (the symbol library); resolves with the value and its name. */
  choose(group: Group): Promise<{ value: string; label: string } | null>;
  /** A control of the toolbar was used: the keyboard goes back to the page. */
  done(): void;
}

export interface Toolbar {
  /** The insertion mode in force; null while selecting. */
  readonly tool: Tool | null;
  /** Chooses a mode by its id; null or `select` goes back to selecting. */
  choose(id: string | null): void;
  /** Shows the toolbar for a score, or hides it. */
  setVisible(shown: boolean): void;
}

function el<K extends keyof HTMLElementTagNameMap>(tag: K, props: Record<string, string> = {}, ...children: (Node | string)[]): HTMLElementTagNameMap[K] {
  const node = document.createElement(tag);
  Object.assign(node, props);
  node.append(...children);
  return node;
}

function isField(target: EventTarget | null): boolean {
  return target instanceof HTMLInputElement || target instanceof HTMLTextAreaElement || target instanceof HTMLSelectElement || (target instanceof HTMLElement && target.isContentEditable);
}

/** The key as the button shows it. */
const keyName = (key: string) => key.toUpperCase();

export function createToolbar(toolRow: HTMLElement, options: HTMLElement, tools: Tool[], hooks: ToolbarHooks): Toolbar {
  let tool: Tool | null = null;
  toolRow.setAttribute('role', 'toolbar');
  toolRow.setAttribute('aria-label', 'Insertion modes');
  toolRow.setAttribute('aria-orientation', 'vertical');
  options.setAttribute('aria-label', 'Options of the mode');

  const toolButton = (id: string, key: string, label: string, title: string, icon: string) => {
    const button = el('button', { type: 'button', className: 'tool', title: `${title} (${keyName(key)})` });
    button.dataset.tool = id;
    button.setAttribute('aria-label', label);
    button.innerHTML = icon;
    button.append(el('kbd', { textContent: keyName(key) }));
    button.addEventListener('click', () => {
      choose(id === tool?.id ? null : id);
      hooks.done();
    });
    return button;
  };
  toolRow.append(toolButton(SELECT.id, SELECT.key, SELECT.label, SELECT.title, SELECT.icon), el('span', { className: 'tool-sep' }));
  tools.forEach((t) => toolRow.append(toolButton(t.id, t.key, t.label, t.title, t.icon)));

  /** The first row of buttons, which the keys 1 … 9 pick from. */
  const digitGroup = (t: Tool) => t.groups.find((g) => g.kind === 'buttons');

  const set = (t: Tool, g: Group, value: string) => {
    g.value = value;
    renderOptions();
    hooks.optionChanged(t);
  };

  function control(t: Tool, g: Group): HTMLElement {
    const first = g === digitGroup(t);
    if (g.kind === 'buttons') {
      const row = el('span', { className: 'segmented' });
      row.setAttribute('role', 'group');
      row.setAttribute('aria-label', g.label);
      g.options.forEach((o, i) => {
        const digit = first && i < 9 ? ` (${i + 1})` : '';
        const button = el('button', { type: 'button', title: `${o.title ?? o.label}${digit}` });
        button.dataset.option = `${g.id}:${o.value}`;
        if (o.icon) {
          button.innerHTML = o.icon;
          button.setAttribute('aria-label', o.label);
          button.classList.add('has-icon');
        } else button.textContent = o.label;
        button.setAttribute('aria-pressed', String(o.value === g.value));
        button.addEventListener('click', () => {
          set(t, g, o.value);
          hooks.done();
        });
        row.append(button);
      });
      return row;
    }
    if (g.kind === 'select') {
      const select = el('select', { title: g.label });
      select.dataset.option = g.id;
      select.append(...g.options.map((o) => new Option(o.label, o.value, false, o.value === g.value)));
      select.addEventListener('change', () => {
        set(t, g, select.value);
        hooks.done();
      });
      return select;
    }
    if (g.kind === 'number') {
      const input = el('input', { type: 'number', min: '1', step: '1', value: g.value, title: g.label });
      input.dataset.option = g.id;
      input.addEventListener('change', () => set(t, g, input.value));
      input.addEventListener('keydown', (e) => {
        e.stopPropagation();
        if (e.key === 'Enter' || e.key === 'Escape') hooks.done();
      });
      return input;
    }
    const button = el('button', { type: 'button', className: 'choose', textContent: g.options[0] ? `${g.options[0].label} · Choose…` : 'Choose…' });
    button.dataset.option = g.id;
    button.addEventListener('click', () => void pick(t, g));
    return button;
  }

  /** Opens a `choose` option's chooser and takes what is chosen. */
  async function pick(t: Tool, g: Group) {
    const chosen = await hooks.choose(g);
    if (chosen) {
      g.options = [{ value: chosen.value, label: chosen.label }];
      set(t, g, chosen.value);
    }
    hooks.done();
  }

  function renderOptions() {
    if (!tool) {
      options.replaceChildren(
        el('span', { className: 'tool-name', textContent: 'Select' }),
        el('span', { className: 'tool-hint', textContent: 'Click an item to edit it, drag a box for several. The buttons at the left, or their keys, choose what a click puts on the page.' }),
      );
      return;
    }
    const t = tool;
    options.replaceChildren(
      el('span', { className: 'tool-name', textContent: t.label }),
      ...t.groups.map((g) => el('span', { className: 'tool-group' }, el('span', { className: 'tool-group-label', textContent: g.label }), control(t, g))),
      el('span', { className: 'tool-hint', textContent: hintOf(t) }),
    );
  }

  const hintOf = (t: Tool) =>
    ({
      span: 'Drag from start to end',
      reach: 'Click a staff, or drag across the staves it joins',
      text: 'Click and type',
      staff: 'Click at its height',
      point: 'Click on a staff',
    })[t.shape] + ' · Esc ends';

  function choose(id: string | null) {
    const next = id === null || id === SELECT.id ? null : (tools.find((t) => t.id === id) ?? null);
    if (next === tool) return;
    tool = next;
    toolRow.querySelectorAll<HTMLButtonElement>('.tool').forEach((b) => b.setAttribute('aria-pressed', String(b.dataset.tool === (tool?.id ?? SELECT.id))));
    renderOptions();
    hooks.changed(tool);
    // A symbol tool without a symbol asks for one at once.
    const empty = tool?.groups.find((g) => g.kind === 'choose' && g.value === '');
    if (tool && empty) void pick(tool, empty);
  }

  // The mode's keys, before the page's own (Escape there deselects).
  window.addEventListener(
    'keydown',
    (e) => {
      if (!hooks.ready() || isField(e.target) || document.querySelector('dialog[open]') || e.metaKey || e.ctrlKey || e.altKey) return;
      if (hooks.busy()) return;
      const key = e.key.length === 1 ? e.key.toLowerCase() : e.key;
      if (key === 'Escape' && tool) {
        e.preventDefault();
        e.stopImmediatePropagation();
        choose(null);
        return;
      }
      if (key === SELECT.key) {
        e.preventDefault();
        choose(null);
        return;
      }
      const chosen = tools.find((t) => t.key === key);
      if (chosen) {
        e.preventDefault();
        choose(chosen === tool ? null : chosen.id);
        return;
      }
      if (!tool) return;
      const t = tool;
      if (/^[1-9]$/.test(key)) {
        const g = digitGroup(t);
        const option = g?.options[Number(key) - 1];
        if (g && option) {
          e.preventDefault();
          set(t, g, option.value);
        }
      } else if (key === '.') {
        const g = t.groups.find((x) => x.id === 'dots');
        if (g) {
          e.preventDefault();
          set(t, g, g.value === '0' ? '1' : '0');
        }
      }
    },
    true,
  );

  choose(null);
  return {
    get tool() {
      return tool;
    },
    choose,
    setVisible(shown) {
      toolRow.hidden = !shown;
      options.hidden = !shown;
      if (!shown) choose(null);
    },
  };
}
