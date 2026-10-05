// Pointer and keyboard gestures on the page, turned into editor calls:
// click and shift-click select, dragging a selected item moves it (Shift
// keeps one axis, Escape cancels), dragging over empty paper draws a box
// (WinScore's mouse-drawn area), Ctrl/⌘-drag or the middle button pans, a
// double click opens an item, and WinScore's edit-mode keys move or delete
// the selection.
import type { Change, Editor } from './editor';
import type { Point } from './view';

export interface Hooks {
  editor(): Editor | null;
  /** The item under a client position, if any. */
  itemAt(clientX: number, clientY: number): number | null;
  pageAt(clientX: number, clientY: number): Point;
  /** After a selection change. */
  selected(): void;
  /** After an edit; `live` while a drag is still in progress. */
  edited(change: Change | null, live: boolean): void;
  failed(err: unknown): void;
  /** Runs a SCORE command line on the selection. */
  command(line: string): void;
  /** A box drawn over the page, corners in page coordinates. */
  box(from: Point, to: Point): void;
  /** A click on empty paper, for placing new items. */
  clickedPaper(at: Point): void;
  /** A double click; `item` is what lies under it. */
  open(item: number | null, clientX: number, clientY: number): void;
}

const DRAG_THRESHOLD_PX = 4;

/** WinScore's edit-mode keys (edit.txt): steps in P3 spaces and P4 scale steps. */
const MOVES: Record<string, [number, number]> = {
  ArrowLeft: [-1, 0],
  ArrowRight: [1, 0],
  ArrowUp: [0, 1],
  ArrowDown: [0, -1],
  PageUp: [0, 4],
  PageDown: [0, -4],
  Home: [-10, 0],
  End: [10, 0],
};

type Gesture =
  | { kind: 'press'; x: number; y: number; onItem: boolean }
  | { kind: 'drag' }
  | { kind: 'box'; x: number; y: number; drawn: boolean }
  | { kind: 'pan'; x: number; y: number; left: number; top: number };

function isTyping(target: EventTarget | null): boolean {
  return target instanceof HTMLInputElement || target instanceof HTMLTextAreaElement || target instanceof HTMLSelectElement;
}

/** Shows the box being drawn, in client coordinates, over `band`'s offset parent. */
function showBand(band: HTMLElement, from: { x: number; y: number }, to: { x: number; y: number } | null) {
  band.hidden = to === null;
  if (!to) return;
  const origin = (band.offsetParent ?? document.body).getBoundingClientRect();
  Object.assign(band.style, {
    left: `${Math.min(from.x, to.x) - origin.left}px`,
    top: `${Math.min(from.y, to.y) - origin.top}px`,
    width: `${Math.abs(to.x - from.x)}px`,
    height: `${Math.abs(to.y - from.y)}px`,
  });
}

export function bindInteraction(viewport: HTMLElement, band: HTMLElement, hooks: Hooks) {
  let gesture: Gesture | null = null;
  let pending: { at: Point; constrain: boolean } | null = null;

  const run = (action: (editor: Editor) => Change | null) => {
    const editor = hooks.editor();
    if (!editor) return;
    try {
      hooks.edited(action(editor), false);
    } catch (err) {
      hooks.failed(err);
    }
  };

  const flushDrag = () => {
    const editor = hooks.editor();
    if (!pending || !editor) return;
    editor.dragTo(pending.at, pending.constrain);
    pending = null;
    hooks.edited(null, true);
  };

  const endDrag = (commit: boolean) => {
    if (gesture?.kind !== 'drag') return;
    flushDrag();
    gesture = null;
    run((editor) => editor.dragEnd(commit));
  };

  viewport.addEventListener('pointerdown', (e) => {
    const editor = hooks.editor();
    const panning = e.button === 1 || (e.button === 0 && (e.ctrlKey || e.metaKey));
    if (panning) {
      e.preventDefault();
      gesture = { kind: 'pan', x: e.clientX, y: e.clientY, left: viewport.scrollLeft, top: viewport.scrollTop };
      viewport.setPointerCapture(e.pointerId);
      return;
    }
    if (e.button !== 0 || !editor) return;
    const hit = editor.prompt() === null ? hooks.itemAt(e.clientX, e.clientY) : null;
    const current = editor.selection();
    if (hit === null) {
      if (!e.shiftKey && current.length > 0 && editor.prompt() === null) {
        editor.select([]);
        hooks.selected();
      }
      hooks.clickedPaper(hooks.pageAt(e.clientX, e.clientY));
      gesture = { kind: 'box', x: e.clientX, y: e.clientY, drawn: false };
    } else {
      const toggled = current.includes(hit) ? current.filter((i) => i !== hit) : [...current, hit];
      const next = e.shiftKey ? toggled : current.includes(hit) ? [...current.filter((i) => i !== hit), hit] : [hit];
      editor.select(next);
      hooks.selected();
      gesture = { kind: 'press', x: e.clientX, y: e.clientY, onItem: next.includes(hit) };
    }
    viewport.setPointerCapture(e.pointerId);
  });

  viewport.addEventListener('pointermove', (e) => {
    if (!gesture) return;
    if (gesture.kind === 'pan') {
      viewport.scrollLeft = gesture.left - (e.clientX - gesture.x);
      viewport.scrollTop = gesture.top - (e.clientY - gesture.y);
      return;
    }
    if (gesture.kind === 'box') {
      gesture.drawn ||= Math.hypot(e.clientX - gesture.x, e.clientY - gesture.y) >= DRAG_THRESHOLD_PX;
      if (gesture.drawn) showBand(band, gesture, { x: e.clientX, y: e.clientY });
      return;
    }
    if (gesture.kind === 'press') {
      if (!gesture.onItem || Math.hypot(e.clientX - gesture.x, e.clientY - gesture.y) < DRAG_THRESHOLD_PX) return;
      hooks.editor()?.dragBegin(hooks.pageAt(gesture.x, gesture.y));
      gesture = { kind: 'drag' };
    }
    const scheduled = pending !== null;
    pending = { at: hooks.pageAt(e.clientX, e.clientY), constrain: e.shiftKey };
    if (!scheduled) requestAnimationFrame(flushDrag);
  });

  const release = (e: PointerEvent) => {
    if (gesture?.kind === 'drag') endDrag(true);
    if (gesture?.kind === 'box') {
      showBand(band, gesture, null);
      // A click answers a waiting group command too (WinScore reads it as a thin box).
      if (gesture.drawn || hooks.editor()?.prompt() != null) {
        hooks.box(hooks.pageAt(gesture.x, gesture.y), hooks.pageAt(e.clientX, e.clientY));
      }
    }
    gesture = null;
  };
  viewport.addEventListener('pointerup', release);
  viewport.addEventListener('pointercancel', () => {
    if (gesture?.kind === 'box') showBand(band, gesture, null);
    endDrag(false);
    gesture = null;
  });
  viewport.addEventListener('dblclick', (e) => hooks.open(hooks.itemAt(e.clientX, e.clientY), e.clientX, e.clientY));

  window.addEventListener('keydown', (e) => {
    if (isTyping(e.target)) return;
    const command = e.metaKey || e.ctrlKey;
    if (e.key === 'Escape' && gesture?.kind === 'drag') {
      endDrag(false);
      return;
    }
    if (e.key === 'Escape' && gesture?.kind === 'box') {
      showBand(band, gesture, null);
      gesture = null;
      return;
    }
    if (command && e.key.toLowerCase() === 'z') {
      e.preventDefault();
      run((editor) => (e.shiftKey ? editor.redo() : editor.undo()));
      return;
    }
    if (command && e.key.toLowerCase() === 'y') {
      e.preventDefault();
      run((editor) => editor.redo());
      return;
    }
    const editor = hooks.editor();
    if (!editor || editor.selection().length === 0 || command) return;
    const move = MOVES[e.key];
    if (move) {
      e.preventDefault();
      run((ed) => ed.moveSelection(move[0], move[1]));
    } else if (e.key === 'Delete' || e.key === 'Backspace') {
      e.preventDefault();
      run((ed) => ed.deleteSelection());
    } else if (e.key === '[' || e.key === ']') {
      run((ed) => ed.moveStaff(e.key === '[' ? 1 : -1));
    } else if (e.key === 'Enter') {
      // WinScore: Enter ends the edit and moves on to the next item.
      e.preventDefault();
      hooks.command(e.shiftKey ? 'B' : 'NEX');
    } else if (e.key === 'Escape') {
      editor.select([]);
      hooks.selected();
    }
  });
}
