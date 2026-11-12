// The desktop app (desktop/, built with Tauri): this same page in the
// system's web view, with a native menu bar, file dialogs and files on disk.
// Save writes the file that was opened, Save As and Export SVG ask where,
// questions are the system's alerts, and Finder opens .mus files with it.
// Printing is the page's window.print(), which Tauri hands to the system's
// print panel.
// In a browser `desktop` is null, and the page downloads and asks as before.

interface Tauri {
  core: {
    invoke<T>(command: string, args?: unknown, options?: { headers: Record<string, string> }): Promise<T>;
  };
  event: {
    listen<T>(event: string, handler: (event: { payload: T }) => void): Promise<() => void>;
  };
}

export interface Desktop {
  /** Asks for a .mus file to open; its path, or null when cancelled. */
  pickOpen(): Promise<string | null>;
  /** Asks where to save a file named `name` with `extension` (a `kind` of file); its path, or null. */
  pickSave(name: string, extension: string, kind: string): Promise<string | null>;
  read(path: string): Promise<Uint8Array>;
  write(path: string, bytes: Uint8Array): Promise<void>;
  /** The system's alert with `message`, the default button `ok` and Cancel; whether `ok` was chosen. */
  confirm(message: string, ok: string): Promise<boolean>;
  setTitle(title: string): void;
  /** Files the system asked the app to open (Finder, Open With, a drop on the Dock icon or the window) not yet taken. */
  openedFiles(): Promise<string[]>;
  /** A command of the menu bar, by its id: new, open, save, save-as, export-svg, print, undo, redo, zoom-in … */
  onMenu(handler: (id: string) => void): void;
  /** Files were opened from outside the page: take them with `openedFiles`. */
  onOpened(handler: () => void): void;
  /** A file is dragged over the window (true) or no longer (false). */
  onDragging(handler: (over: boolean) => void): void;
  /** The window or the app is to close: call `close` to let it. */
  onCloseRequested(handler: () => void): void;
  close(): void;
  /** The page listens: closing asks it from now on. */
  ready(): void;
}

function bridge(tauri: Tauri): Desktop {
  const invoke = tauri.core.invoke;
  const listen = <T>(event: string, handler: (payload: T) => void) => void tauri.event.listen<T>(event, (e) => handler(e.payload));
  return {
    pickOpen: () => invoke<string | null>('pick_open'),
    pickSave: (name, extension, kind) => invoke<string | null>('pick_save', { name, extension, kind }),
    read: async (path) => new Uint8Array(await invoke<ArrayBuffer>('read_file', { path })),
    // The bytes go as the request's body, the path (any characters) in a header.
    write: (path, bytes) => invoke<void>('write_file', bytes, { headers: { path: encodeURIComponent(path) } }),
    confirm: (message, ok) => invoke<boolean>('confirm', { message, ok }),
    setTitle: (title) => void invoke('set_title', { title }).catch(() => {}),
    openedFiles: () => invoke<string[]>('opened_files'),
    onMenu: (handler) => listen<string>('menu', handler),
    onOpened: (handler) => listen<null>('opened', () => handler()),
    onDragging: (handler) => listen<boolean>('dragging', handler),
    onCloseRequested: (handler) => listen<null>('close-requested', () => handler()),
    close: () => void invoke('close_window'),
    ready: () => void invoke('page_ready'),
  };
}

const tauri = (window as unknown as { __TAURI__?: Tauri }).__TAURI__;

export const desktop: Desktop | null = tauri ? bridge(tauri) : null;

/** The file name of a path, either kind of slash. */
export function baseName(path: string): string {
  return path.split(/[\\/]/).pop() || path;
}
