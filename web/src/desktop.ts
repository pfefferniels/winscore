// The desktop app (desktop/, built with Tauri): this same page in the
// system's web view, with a native menu bar, file dialogs and files on disk.
// Open takes several files at once (the pages of a score), Save writes the
// file a page was opened from, Save As and Export SVG ask where, questions
// are the system's alerts, and Finder opens .mus files with it.
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

/** The MCP endpoint (desktop/src-tauri/src/mcp.rs). */
export interface McpStatus {
  enabled: boolean;
  /** Where clients reach it, e.g. http://127.0.0.1:7341/mcp. */
  url: string;
  /** The app's executable, which `--mcp-stdio` makes a bridge for clients that run their servers. */
  executable: string;
  /** Why it is not listening, if it should be. */
  error: string | null;
  /** Whether assistants may run scripts in the page (run_script). */
  scripts: boolean;
}

export interface Desktop {
  /** Asks for .mus files to open, starting in `folder` if given; their paths, none when cancelled. */
  pickOpen(folder?: string | null): Promise<string[]>;
  /** Asks where to save a file named `name` with `extension` (a `kind` of file), starting in `folder` if given; its path, or null. */
  pickSave(name: string, extension: string, kind: string, folder?: string | null): Promise<string | null>;
  read(path: string): Promise<Uint8Array>;
  write(path: string, bytes: Uint8Array): Promise<void>;
  /** The system's alert with `message`, the default button `ok` and Cancel; whether `ok` was chosen. */
  confirm(message: string, ok: string): Promise<boolean>;
  setTitle(title: string): void;
  /** Files the system asked the app to open (Finder, Open With, a drop on the Dock icon or the window) not yet taken. */
  openedFiles(): Promise<string[]>;
  /** A command of the menu bar, by its id: new, open, new-page, next-page, save, save-as, save-all, export-svg, print, undo, redo, zoom-in … */
  onMenu(handler: (id: string) => void): void;
  /** Files were opened from outside the page: take them with `openedFiles`. */
  onOpened(handler: () => void): void;
  /** A file is dragged over the window (true) or no longer (false). */
  onDragging(handler: (over: boolean) => void): void;
  /** The window or the app is to close: call `close` to let it. */
  onCloseRequested(handler: () => void): void;
  close(): void;
  /** The page listens: closing asks it from now on, and MCP requests come to it. */
  ready(): void;
  /** A JSON-RPC message of an MCP client, to be answered with `mcpRespond` (null: no answer). */
  onMcpRequest(handler: (id: number, message: unknown) => void): void;
  mcpRespond(id: number, response: unknown): void;
  mcpStatus(): Promise<McpStatus>;
  setMcpEnabled(on: boolean): Promise<McpStatus>;
  /** Allows assistants to run scripts, or not, for this and later launches. */
  setMcpScripts(on: boolean): Promise<McpStatus>;
  /** Makes WinScore the app that opens .mus files (macOS); what it did. */
  makeDefault(): Promise<string>;
}

function bridge(tauri: Tauri): Desktop {
  const invoke = tauri.core.invoke;
  const listen = <T>(event: string, handler: (payload: T) => void) => void tauri.event.listen<T>(event, (e) => handler(e.payload));
  return {
    pickOpen: (folder) => invoke<string[]>('pick_open', { folder: folder ?? null }),
    pickSave: (name, extension, kind, folder) => invoke<string | null>('pick_save', { name, extension, kind, folder: folder ?? null }),
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
    onMcpRequest: (handler) => listen<{ id: number; message: unknown }>('mcp-request', ({ id, message }) => handler(id, message)),
    mcpRespond: (id, response) => void invoke('mcp_respond', { id, response }).catch(() => {}),
    mcpStatus: () => invoke<McpStatus>('mcp_status'),
    setMcpEnabled: (on) => invoke<McpStatus>('mcp_enable', { on }),
    setMcpScripts: (on) => invoke<McpStatus>('mcp_scripts', { on }),
    makeDefault: () => invoke<string>('make_default'),
  };
}

const tauri = (window as unknown as { __TAURI__?: Tauri }).__TAURI__;

export const desktop: Desktop | null = tauri ? bridge(tauri) : null;

/** The file name of a path, either kind of slash. */
export function baseName(path: string): string {
  return path.split(/[\\/]/).pop() || path;
}
