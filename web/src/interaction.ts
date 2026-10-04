// Pointer and keyboard gestures on the page, turned into editor calls:
// click and shift-click select, dragging a selected item moves it (Shift
// keeps one axis, Escape cancels), dragging empty paper pans the view, and
// WinScore's edit-mode keys move or delete the selection.
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
  | { kind: 'drag'; start: Point }
  | { kind: 'pan'; x: number; y: number; left: number; top: number };

function isTyping(target: EventTarget | null): boolean {
  return target instanceof HTMLInputElement || target instanceof HTMLTextAreaElement || target instanceof HTMLSelectElement;
}

export function bindInteraction(viewport: HTMLElement, hooks: Hooks) {
  let gesture: Gesture | null = null;
  let pending: { dx: number; dy: number; constrain: boolean } | null = null;

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
    editor.dragTo(pending.dx, pending.dy, pending.constrain);
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
    if (e.button !== 0 || !editor) return;
    const hit = hooks.itemAt(e.clientX, e.clientY);
    const current = editor.selection();
    if (hit === null) {
      if (!e.shiftKey && current.length > 0) {
        editor.select([]);
        hooks.selected();
      }
      gesture = { kind: 'pan', x: e.clientX, y: e.clientY, left: viewport.scrollLeft, top: viewport.scrollTop };
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
    if (gesture.kind === 'press') {
      if (!gesture.onItem || Math.hypot(e.clientX - gesture.x, e.clientY - gesture.y) < DRAG_THRESHOLD_PX) return;
      hooks.editor()?.dragBegin();
      gesture = { kind: 'drag', start: hooks.pageAt(gesture.x, gesture.y) };
    }
    const p = hooks.pageAt(e.clientX, e.clientY);
    const scheduled = pending !== null;
    pending = { dx: p.x - gesture.start.x, dy: p.y - gesture.start.y, constrain: e.shiftKey };
    if (!scheduled) requestAnimationFrame(flushDrag);
  });

  const release = () => {
    if (gesture?.kind === 'drag') endDrag(true);
    gesture = null;
  };
  viewport.addEventListener('pointerup', release);
  viewport.addEventListener('pointercancel', () => endDrag(false));

  window.addEventListener('keydown', (e) => {
    if (isTyping(e.target)) return;
    const command = e.metaKey || e.ctrlKey;
    if (e.key === 'Escape' && gesture?.kind === 'drag') {
      endDrag(false);
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
