// Copy, cut, paste and duplicate: ⌘C, ⌘X, ⌘V and ⌘D (Ctrl elsewhere) and
// the Edit commands. Copied items travel as a .mus file of their own: kept here
// for Edit ▸ Paste, and on the system clipboard as text, so that ⌘V in another
// tab's score pastes them too. Form fields, dialogs and text selected on the
// page keep the browser's own copy and paste.

/** How copied items start on the system clipboard, before the base64 of their .mus file. */
const MARKER = 'winscore-items:';

export interface ClipboardHooks {
  /** Whether a score is open to copy from and paste into. */
  ready(): boolean;
  /** The selected items as `.mus` bytes; empty without a selection. */
  copy(): Uint8Array;
  /** The same, the selection then deleted. */
  cut(): Uint8Array;
  paste(items: Uint8Array): void;
  duplicate(): void;
}

export interface Clipboard {
  copy(): void;
  cut(): void;
  /** Pastes what was copied last in this tab (Edit ▸ Paste cannot read the system clipboard without asking). */
  paste(): void;
  readonly full: boolean;
}

function toBase64(bytes: Uint8Array): string {
  let binary = '';
  for (let i = 0; i < bytes.length; i += 0x8000) binary += String.fromCharCode(...bytes.subarray(i, i + 0x8000));
  return btoa(binary);
}

/** Items copied in this app, possibly in another tab; null for any other text. */
function itemsIn(text: string): Uint8Array | null {
  if (!text.startsWith(MARKER)) return null;
  try {
    return Uint8Array.from(atob(text.slice(MARKER.length).trim()), (c) => c.charCodeAt(0));
  } catch {
    return null;
  }
}

/** Whether the keys and the clipboard belong to the page rather than a field, a dialog or selected text. */
function pageHasKeys(target: EventTarget | null): boolean {
  const field = target instanceof HTMLInputElement || target instanceof HTMLTextAreaElement || target instanceof HTMLSelectElement;
  const editable = target instanceof HTMLElement && target.isContentEditable;
  const selectedText = document.getSelection()?.toString() ?? '';
  return !field && !editable && selectedText === '' && document.querySelector('dialog[open]') === null;
}

export function bindClipboard(hooks: ClipboardHooks): Clipboard {
  let copied: Uint8Array | null = null;

  /** Keeps `items` for Edit ▸ Paste and puts them on the system clipboard; false when nothing was selected. */
  const keep = (items: Uint8Array): boolean => {
    if (items.length === 0) return false;
    copied = items;
    navigator.clipboard?.writeText(MARKER + toBase64(items)).catch(() => {
      // Without the system clipboard the items can still be pasted in this tab.
    });
    return true;
  };

  window.addEventListener('keydown', (e) => {
    if (!(e.metaKey || e.ctrlKey) || e.altKey || e.shiftKey || !pageHasKeys(e.target) || !hooks.ready()) return;
    const key = e.key.toLowerCase();
    if ((key === 'c' && keep(hooks.copy())) || (key === 'x' && keep(hooks.cut()))) e.preventDefault();
    else if (key === 'd') {
      e.preventDefault();
      hooks.duplicate();
    }
    // ⌘V goes on to the browser's paste event, which can read the system clipboard.
  });

  document.addEventListener('paste', (e) => {
    if (!pageHasKeys(e.target) || !hooks.ready()) return;
    const items = itemsIn(e.clipboardData?.getData('text/plain') ?? '') ?? copied;
    if (!items) return;
    e.preventDefault();
    hooks.paste(items);
  });

  return {
    copy: () => void keep(hooks.copy()),
    cut: () => void keep(hooks.cut()),
    paste: () => {
      if (copied && hooks.ready()) hooks.paste(copied);
    },
    get full() {
      return copied !== null;
    },
  };
}
