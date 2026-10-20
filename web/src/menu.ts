// The editor's commands as menus of entries: File, Edit, Insert, Layout,
// View (menus.ts). There is no menu bar: the `?` dialog lists every entry as a
// button, and commands in words reach them by their names or through Jev.
// Entries are read again each time they are listed, so labels and enabled
// states follow the app.

export interface Action {
  label: string | (() => string);
  /** Shown beside it: a shortcut, or the SCORE command the entry sends. */
  hint?: string;
  title?: string;
  /** Marks its button as `data-action`, for scripts and tests. */
  id?: string;
  run(): void;
  enabled?: () => boolean;
  /** Makes the entry a switch. */
  checked?: () => boolean;
}

export type Entry = Action | { row: string; actions: Action[] } | { heading: string } | 'separator';

export interface Menu {
  id: string;
  label: string;
  entries(): Entry[];
}

/** ⌘ on Apple systems, Ctrl elsewhere, as shortcuts are written. */
export const MOD = /Mac|iPhone|iPad/.test(navigator.platform) ? '⌘' : 'Ctrl+';

export const labelOf = (action: Action) => (typeof action.label === 'function' ? action.label() : action.label);

/** Every action of the menus with the menu's id and where it is: "Edit ▸ Copy", "Insert ▸ Note ▸ Half". */
export function menuActions(menus: Menu[]): { menu: string; path: string; action: Action }[] {
  return menus.flatMap((menu) =>
    menu.entries().flatMap((entry) => {
      if (typeof entry !== 'object') return [];
      if ('row' in entry) return entry.actions.map((action) => ({ menu: menu.id, path: `${menu.label} ▸ ${entry.row} ▸ ${labelOf(action)}`, action }));
      return 'run' in entry ? [{ menu: menu.id, path: `${menu.label} ▸ ${labelOf(entry)}`, action: entry }] : [];
    }),
  );
}
