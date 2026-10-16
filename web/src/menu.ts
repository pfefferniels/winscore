// The menu bar: drop-down menus opened by a click, or from the keyboard with
// Enter, Space or ↓ on a title. In an open menu ↑ and ↓ move between lines,
// ← and → between the buttons of a row and otherwise to the next menu, a
// letter to the next entry starting with it, Enter runs an entry, Escape or a
// click elsewhere closes. Entries are read again each time their menu opens,
// so labels and enabled states follow the app.

export interface Action {
  label: string | (() => string);
  /** Shown on the right: a shortcut, or the SCORE command the entry sends. */
  hint?: string;
  title?: string;
  /** Marks the button as `data-action`, for scripts and tests. */
  id?: string;
  run(): void;
  enabled?: () => boolean;
  /** Makes the entry a check box. */
  checked?: () => boolean;
}

export type Entry = Action | { row: string; actions: Action[] } | { heading: string } | 'separator';

export interface Menu {
  id: string;
  label: string;
  entries(): Entry[];
}

export interface MenuBar {
  readonly isOpen: boolean;
  close(): void;
}

const MENUBAR = 'data-menubar';

/** Whether a key or pointer event happened in a menu bar, which handles its own keys. */
export function inMenuBar(target: EventTarget | null): boolean {
  return target instanceof Element && target.closest(`[${MENUBAR}]`) !== null;
}

/** ⌘ on Apple systems, Ctrl elsewhere, as shortcuts are written. */
export const MOD = /Mac|iPhone|iPad/.test(navigator.platform) ? '⌘' : 'Ctrl+';

const labelOf = (action: Action) => (typeof action.label === 'function' ? action.label() : action.label);

function span(className: string, text: string): HTMLSpanElement {
  return Object.assign(document.createElement('span'), { className, textContent: text });
}

/**
 * Builds the menus into `bar`. `ran` is called after an entry's action, to
 * give the keyboard back to the page when the action left it nowhere.
 */
export function createMenuBar(bar: HTMLElement, menus: Menu[], ran: () => void): MenuBar {
  bar.setAttribute(MENUBAR, '');
  bar.setAttribute('role', 'menubar');
  let current: { index: number; popup: HTMLElement } | null = null;

  const titles = menus.map((menu, index) => {
    const wrapper = Object.assign(document.createElement('div'), { className: 'menu' });
    const title = Object.assign(document.createElement('button'), { type: 'button', className: 'menu-title', id: `menu-${menu.id}`, textContent: menu.label });
    title.setAttribute('role', 'menuitem');
    title.setAttribute('aria-haspopup', 'menu');
    title.setAttribute('aria-expanded', 'false');
    // detail 0: a click made with Enter or Space, which moves into the menu.
    title.addEventListener('click', (e) => (current?.index === index ? close(true) : open(index, e.detail === 0)));
    title.addEventListener('pointerenter', () => {
      if (current && current.index !== index) open(index, false);
    });
    title.addEventListener('keydown', (e) => {
      const step = { ArrowLeft: -1, ArrowRight: 1 }[e.key];
      if (step) {
        const next = (index + step + menus.length) % menus.length;
        if (current) open(next, true);
        else titles[next]!.focus();
      } else if (e.key === 'ArrowDown') open(index, true);
      else if (e.key === 'Escape' && current) close(true);
      else return;
      e.preventDefault();
      e.stopPropagation();
    });
    wrapper.append(title);
    bar.append(wrapper);
    return title;
  });

  /** The enabled buttons of an open menu, one array per line (a row's buttons share a line). */
  const lines = (popup: HTMLElement): HTMLButtonElement[][] =>
    Array.from(popup.querySelectorAll<HTMLElement>(':scope > .menu-item, :scope > .menu-row'))
      .map((line) => (line.matches('.menu-row') ? Array.from(line.querySelectorAll<HTMLButtonElement>('button')) : [line as HTMLButtonElement]))
      .map((buttons) => buttons.filter((b) => !b.disabled))
      .filter((buttons) => buttons.length > 0);

  function close(refocus: boolean) {
    if (!current) return;
    const { index, popup } = current;
    current = null;
    popup.remove();
    titles[index]!.setAttribute('aria-expanded', 'false');
    titles[index]!.classList.remove('open');
    if (refocus) titles[index]!.focus();
  }

  function actionButton(action: Action, chip: boolean): HTMLButtonElement {
    const button = Object.assign(document.createElement('button'), { type: 'button', className: chip ? 'menu-chip' : 'menu-item' });
    const label = labelOf(action);
    if (action.checked) {
      button.setAttribute('role', 'menuitemcheckbox');
      button.setAttribute('aria-checked', String(action.checked()));
    } else button.setAttribute('role', 'menuitem');
    if (chip) button.textContent = label;
    else button.append(span('menu-check', action.checked?.() ? '✓' : ''), span('menu-label', label), span('menu-hint', action.hint ?? ''));
    if (action.title) button.title = action.title;
    if (action.id) button.dataset.action = action.id;
    button.disabled = action.enabled ? !action.enabled() : false;
    button.addEventListener('click', () => {
      close(false);
      action.run();
      ran();
    });
    return button;
  }

  function entry(item: Entry): HTMLElement {
    if (item === 'separator') return Object.assign(document.createElement('div'), { className: 'menu-sep', role: 'separator' });
    if ('heading' in item) return span('menu-heading', item.heading);
    if ('row' in item) {
      const row = Object.assign(document.createElement('div'), { className: 'menu-row', role: 'group' });
      row.setAttribute('aria-label', item.row);
      const chips = Object.assign(document.createElement('div'), { className: 'menu-chips' });
      chips.append(...item.actions.map((a) => actionButton(a, true)));
      row.append(span('menu-row-label', item.row), chips);
      return row;
    }
    return actionButton(item, false);
  }

  function onKey(e: KeyboardEvent, popup: HTMLElement) {
    if (e.metaKey || e.ctrlKey || e.altKey) {
      close(false);
      return;
    }
    const all = lines(popup);
    const active = document.activeElement as HTMLButtonElement;
    const line = all.findIndex((buttons) => buttons.includes(active));
    const column = line < 0 ? -1 : all[line]!.indexOf(active);
    const focusLine = (n: number) => all[(n + all.length) % all.length]?.[0]?.focus();
    const index = current!.index;
    switch (e.key) {
      case 'ArrowDown':
        focusLine(line + 1);
        break;
      case 'ArrowUp':
        focusLine(line < 0 ? -1 : line - 1);
        break;
      case 'ArrowRight':
      case 'ArrowLeft': {
        const step = e.key === 'ArrowRight' ? 1 : -1;
        const neighbour = line < 0 ? undefined : all[line]![column + step];
        if (neighbour) neighbour.focus();
        else open((index + step + menus.length) % menus.length, true);
        break;
      }
      case 'Home':
        focusLine(0);
        break;
      case 'End':
        focusLine(-1);
        break;
      case 'Escape':
        close(true);
        break;
      case 'Tab':
        close(false);
        return;
      case 'Enter':
      case ' ':
        // The focused button runs on its own click; the popup itself has nothing to run.
        if (line >= 0) return;
        break;
      default: {
        if (e.key.length !== 1) return;
        const flat = all.flat();
        const start = flat.indexOf(active);
        const key = e.key.toLowerCase();
        const match = [...flat.slice(start + 1), ...flat.slice(0, start + 1)].find((b) =>
          (b.querySelector('.menu-label')?.textContent ?? b.textContent ?? '').toLowerCase().startsWith(key),
        );
        match?.focus();
      }
    }
    e.preventDefault();
    e.stopPropagation();
  }

  function open(index: number, focusFirst: boolean) {
    close(false);
    const title = titles[index]!;
    const popup = Object.assign(document.createElement('div'), { className: 'menu-popup', tabIndex: -1 });
    popup.setAttribute('role', 'menu');
    popup.setAttribute('aria-labelledby', title.id);
    popup.append(...menus[index]!.entries().map(entry));
    popup.addEventListener('keydown', (e) => onKey(e, popup));
    title.after(popup);
    // Keep the menu on screen when its title is near the right edge.
    const overflow = popup.getBoundingClientRect().right - (window.innerWidth - 8);
    if (overflow > 0) popup.style.left = `${-overflow}px`;
    title.setAttribute('aria-expanded', 'true');
    title.classList.add('open');
    current = { index, popup };
    if (focusFirst) lines(popup)[0]?.[0]?.focus();
    else popup.focus();
  }

  document.addEventListener(
    'pointerdown',
    (e) => {
      if (current && !bar.contains(e.target as Node)) close(false);
    },
    true,
  );
  window.addEventListener('resize', () => close(false));
  window.addEventListener('blur', () => close(false));

  return {
    get isOpen() {
      return current !== null;
    },
    close: () => close(false),
  };
}
