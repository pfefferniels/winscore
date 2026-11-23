// The pages of a score: SCORE keeps each page in a .mus file of its own,
// numbered by name (SONATA01.MUS, SONATA02.MUS …). The window holds the
// pages opened together, shows and edits one of them at a time, and lists
// them in the page bar (in the app bar, after undo and redo) while there is more than one. Each
// page keeps its own undo history, selection and file; the clipboard is
// shared, so items copied on one page paste onto another.

/** Names in the order of their numbers: page2 before page10. */
export function byName(a: string, b: string): number {
  return a.localeCompare(b, undefined, { numeric: true, sensitivity: 'base' });
}

/**
 * The name of a new page after `name`: its number at the end counted on,
 * keeping its digits (sonata01.mus → sonata02.mus), or 2 put after a name
 * without one; on again past the names in `taken` (compared ignoring case).
 */
export function nextName(name: string, taken: Iterable<string>): string {
  const used = new Set([...taken].map((n) => n.toLowerCase()));
  const [, stem = name, extension = ''] = /^(.*?)(\.[^.]*)?$/.exec(name) ?? [];
  const [, base = stem, digits = ''] = /^(.*?)(\d*)$/.exec(stem) ?? [];
  let number = digits ? Number(digits) : 1;
  for (;;) {
    number += 1;
    const candidate = `${base}${String(number).padStart(digits.length, '0')}${extension || '.mus'}`;
    if (!used.has(candidate.toLowerCase())) return candidate;
  }
}

/** Names as a sentence lists them: "a", "a and b", "a, b and c". */
export function listed(names: string[]): string {
  return names.length < 2 ? (names[0] ?? '') : `${names.slice(0, -1).join(', ')} and ${names.at(-1)}`;
}

/** The folder of a file's path, either kind of slash; null for a name alone. */
export function folderOf(path: string | null): string | null {
  const cut = path ? Math.max(path.lastIndexOf('/'), path.lastIndexOf('\\')) : -1;
  return cut > 0 ? path!.slice(0, cut) : cut === 0 ? path!.slice(0, 1) : null;
}

/** What the page bar shows of a page. */
export interface PageTab {
  name: string;
  /** Where its file is (the desktop app), for the tab's tooltip. */
  path: string | null;
  modified: boolean;
}

export interface PageBarHooks {
  show(index: number): void;
  close(index: number): void;
  newPage(): void;
  addPages(): void;
}

export interface PageBar {
  /** Shows the tabs of `pages`, `current` as the one shown; the bar hides with fewer than two. */
  render(pages: PageTab[], current: number): void;
}

const CLOSE_ICON = '<svg viewBox="0 0 24 24" aria-hidden="true"><path d="M7 7l10 10M17 7 7 17" /></svg>';

export function createPageBar(bar: HTMLElement, tabs: HTMLElement, hooks: PageBarHooks): PageBar {
  // A tab is a pair of buttons: its name shows the page, the cross closes it.
  tabs.addEventListener('click', (e) => {
    const target = e.target instanceof Element ? e.target.closest<HTMLButtonElement>('button[data-page]') : null;
    if (!target) return;
    const index = Number(target.dataset.page);
    if (target.classList.contains('page-close')) hooks.close(index);
    else hooks.show(index);
  });
  // A middle click closes a tab, as in browsers.
  tabs.addEventListener('auxclick', (e) => {
    const target = e.target instanceof Element ? e.target.closest<HTMLButtonElement>('button[data-page]') : null;
    if (target && e.button === 1) {
      e.preventDefault();
      hooks.close(Number(target.dataset.page));
    }
  });
  bar.querySelector('#page-new')?.addEventListener('click', hooks.newPage);
  bar.querySelector('#page-add')?.addEventListener('click', hooks.addPages);

  let shown = '';
  return {
    render(pages, current) {
      bar.hidden = pages.length < 2;
      const key = JSON.stringify([pages, current]);
      if (bar.hidden || key === shown) return;
      shown = key;
      tabs.replaceChildren(
        ...pages.map((page, index) => {
          const tab = Object.assign(document.createElement('span'), { className: 'page-tab' });
          const where = page.path ?? page.name;
          const name = Object.assign(document.createElement('button'), {
            type: 'button',
            className: 'page-name',
            title: `Page ${index + 1} of ${pages.length}: ${where}${page.modified ? ' (unsaved changes)' : ''}`,
          });
          name.dataset.page = String(index);
          name.append(Object.assign(document.createElement('span'), { className: 'page-label', textContent: page.name }));
          if (page.modified) name.append(Object.assign(document.createElement('span'), { className: 'page-dot' }));
          if (index === current) {
            tab.classList.add('current');
            name.setAttribute('aria-current', 'page');
          }
          const close = Object.assign(document.createElement('button'), {
            type: 'button',
            className: 'page-close icon',
            title: `Close ${page.name}`,
            innerHTML: CLOSE_ICON,
          });
          close.dataset.page = String(index);
          close.setAttribute('aria-label', `Close ${page.name}`);
          tab.append(name, close);
          return tab;
        }),
      );
      tabs.querySelector('.page-tab.current')?.scrollIntoView({ block: 'nearest', inline: 'nearest' });
    },
  };
}
