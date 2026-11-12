// The editor's commands as menus of entries: File, Edit, Insert, Layout,
// View (menus.ts). There is no menu bar: the `?` dialog lists every entry as a
// button. Entries are read again each time they are listed, so labels and
// enabled states follow the app.

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
