// Pointer and keyboard gestures on the page, turned into editor calls:
// click and shift-click select, dragging a selected item moves it (Shift
// keeps one axis, Escape cancels), dragging over empty paper draws a box
// (WinScore's mouse-drawn area), Ctrl/⌘-drag or the middle button pans, a
// double click opens an item, and WinScore's edit-mode keys move or delete
// the selection.
//
// Touch: a tap selects, a finger dragged pans (and glides on), except from
// an item already selected, which it moves; two fingers pinch to zoom; a
// long press adds or removes an item, and dragging on from it draws a box;
// a double tap opens an item. While a group command waits for its area, one
// finger draws the box and a tap answers it.
import type { Change, Editor } from './editor';
import type { Point } from './view';

export interface Hooks {
  editor(): Editor | null;
  /** The item under a client position, if any; `coarse` for a finger, which picks from further away. */
  itemAt(clientX: number, clientY: number, coarse?: boolean): number | null;
  pageAt(clientX: number, clientY: number): Point;
  zoom(): number;
  /** Zooms so that page point `at` lies under the client position (a pinch). */
  zoomAt(zoom: number, at: Point, clientX: number, clientY: number): void;
  /** A tap with the music input open: true when it moved the input's cursor. */
  inputTap(clientX: number, clientY: number): boolean;
  /** Whether a touch on the page leaves the keyboard focus where it is (the music input's typing field). */
  holdsKeyboard(): boolean;
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
/** A finger moves this far before a touch becomes a pan, drag or box. */
const TOUCH_SLOP_PX = 8;
const LONG_PRESS_MS = 450;
const DOUBLE_TAP_MS = 350;
/** A pan glides on after the finger lifts, slowing with this time constant (as a native scroll does). */
const GLIDE_MS = 325;

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

/** A finger's position at a time, for the speed a pan glides on with. */
interface Sample {
  x: number;
  y: number;
  t: number;
}

type Gesture =
  | { kind: 'press'; x: number; y: number; onItem: boolean }
  | { kind: 'drag' }
  | { kind: 'box'; x: number; y: number; drawn: boolean }
  | { kind: 'pan'; x: number; y: number; left: number; top: number; samples?: Sample[] }
  /** A finger down that has not moved yet; `held` after a long press. */
  | { kind: 'touch'; x: number; y: number; hit: number | null; onSelected: boolean; held: boolean; timer: number }
  | { kind: 'pinch'; distance: number; zoom: number; at: Point };

type Touch = Extract<Gesture, { kind: 'touch' }>;
type BoxGesture = Extract<Gesture, { kind: 'box' }>;

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
  /** Fingers on the page, by pointer id. */
  const touches = new Map<number, { x: number; y: number }>();
  /** The finger a one-finger touch gesture follows. */
  let finger = -1;
  let lastPointer = '';
  let lastTap: Sample | null = null;
  let glide = 0;
  let pinchFrame = 0;

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

  /** Moves the dragged selection to a client position at the next frame. */
  const dragTo = (clientX: number, clientY: number, constrain: boolean) => {
    const scheduled = pending !== null;
    pending = { at: hooks.pageAt(clientX, clientY), constrain };
    if (!scheduled) requestAnimationFrame(flushDrag);
  };

  const select = (editor: Editor, items: number[]) => {
    editor.select(items);
    hooks.selected();
    return items;
  };

  /** Selects `hit` as a plain click does: alone, or as the primary item if it is already selected. */
  const pick = (editor: Editor, hit: number) => {
    const current = editor.selection();
    return select(editor, current.includes(hit) ? [...current.filter((i) => i !== hit), hit] : [hit]);
  };

  /** Shift-click: adds `hit` to the selection or takes it out. */
  const toggle = (editor: Editor, hit: number) => {
    const current = editor.selection();
    return select(editor, current.includes(hit) ? current.filter((i) => i !== hit) : [...current, hit]);
  };

  /** A box drawn with the mouse or a finger is finished; a click answers a waiting group command too (WinScore reads it as a thin box). */
  const endBox = (box: BoxGesture, clientX: number, clientY: number) => {
    showBand(band, box, null);
    if (box.drawn || hooks.editor()?.prompt() != null) hooks.box(hooks.pageAt(box.x, box.y), hooks.pageAt(clientX, clientY));
  };

  viewport.addEventListener('pointerdown', (e) => {
    lastPointer = e.pointerType;
    if (e.pointerType === 'touch') {
      touchDown(e);
      return;
    }
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
      const next = e.shiftKey ? toggle(editor, hit) : pick(editor, hit);
      gesture = { kind: 'press', x: e.clientX, y: e.clientY, onItem: next.includes(hit) };
    }
    viewport.setPointerCapture(e.pointerId);
  });

  viewport.addEventListener('pointermove', (e) => {
    if (e.pointerType === 'touch') {
      touchMove(e);
      return;
    }
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
    if (gesture.kind === 'drag') dragTo(e.clientX, e.clientY, e.shiftKey);
  });

  const release = (e: PointerEvent) => {
    if (e.pointerType === 'touch') {
      touchUp(e);
      return;
    }
    if (gesture?.kind === 'drag') endDrag(true);
    if (gesture?.kind === 'box') endBox(gesture, e.clientX, e.clientY);
    gesture = null;
  };
  viewport.addEventListener('pointerup', release);
  viewport.addEventListener('pointercancel', (e) => {
    // The browser took the touch over: every finger is gone as far as the page is concerned.
    if (e.pointerType === 'touch') touches.clear();
    if (gesture?.kind === 'touch') clearTimeout(gesture.timer);
    if (gesture?.kind === 'box') showBand(band, gesture, null);
    endDrag(false);
    gesture = null;
  });
  viewport.addEventListener('dblclick', (e) => {
    // A double tap is told apart from two taps by the touch code itself.
    if (lastPointer !== 'touch') hooks.open(hooks.itemAt(e.clientX, e.clientY), e.clientX, e.clientY);
  });
  // A long press is a gesture of its own, not the browser's context menu or text selection.
  viewport.addEventListener('contextmenu', (e) => {
    if (lastPointer === 'touch') e.preventDefault();
  });
  // The page scrolls itself; without this a quick drag still ends in a fling of the browser's,
  // which swallows the click of the next tap anywhere (a tap that stops a fling is not a click).
  viewport.addEventListener('touchmove', (e) => e.preventDefault(), { passive: false });

  const stopGlide = () => {
    cancelAnimationFrame(glide);
    glide = 0;
  };

  /** Lets a touch pan run on after the finger lifts, at the speed of its last tenth of a second. */
  const startGlide = (samples: Sample[], now: number) => {
    const last = samples.at(-1);
    const first = samples.find((s) => last && last.t - s.t <= 100);
    if (!first || !last || last.t - first.t < 10 || now - last.t > 60) return;
    let vx = (last.x - first.x) / (last.t - first.t);
    let vy = (last.y - first.y) / (last.t - first.t);
    if (Math.hypot(vx, vy) < 0.2) return;
    let time = performance.now();
    const step = (frame: number) => {
      const dt = Math.min(50, frame - time);
      time = frame;
      viewport.scrollLeft -= vx * dt;
      viewport.scrollTop -= vy * dt;
      const decay = Math.exp(-dt / GLIDE_MS);
      vx *= decay;
      vy *= decay;
      glide = Math.hypot(vx, vy) > 0.02 ? requestAnimationFrame(step) : 0;
    };
    glide = requestAnimationFrame(step);
  };

  const panFrom = (id: number, at: { x: number; y: number }, t: number): Gesture => {
    finger = id;
    return { kind: 'pan', x: at.x, y: at.y, left: viewport.scrollLeft, top: viewport.scrollTop, samples: [{ ...at, t }] };
  };

  /** The first two fingers: their distance and the point between them. */
  const twoFingers = () => {
    const [a, b] = Array.from(touches.values());
    return { distance: Math.max(1, Math.hypot(b!.x - a!.x, b!.y - a!.y)), x: (a!.x + b!.x) / 2, y: (a!.y + b!.y) / 2 };
  };

  /** Two fingers on the page: the page point between them stays between them as they move apart or together. */
  const startPinch = () => {
    const start = twoFingers();
    gesture = { kind: 'pinch', distance: start.distance, zoom: hooks.zoom(), at: hooks.pageAt(start.x, start.y) };
  };

  const pinchTo = () => {
    pinchFrame = 0;
    if (gesture?.kind !== 'pinch' || touches.size < 2) return;
    const now = twoFingers();
    hooks.zoomAt((gesture.zoom * now.distance) / gesture.distance, gesture.at, now.x, now.y);
  };

  /** Ends what one finger started, without its effect, when a second finger turns it into a pinch. */
  const abandon = () => {
    if (gesture?.kind === 'touch') clearTimeout(gesture.timer);
    if (gesture?.kind === 'box') showBand(band, gesture, null);
  };

  const touchDown = (e: PointerEvent) => {
    // A pen or mouse gesture in progress keeps the page to itself.
    if (gesture && touches.size === 0) return;
    stopGlide();
    if (hooks.holdsKeyboard()) e.preventDefault();
    touches.set(e.pointerId, { x: e.clientX, y: e.clientY });
    viewport.setPointerCapture(e.pointerId);
    if (touches.size === 2 && gesture?.kind !== 'drag') {
      abandon();
      startPinch();
      return;
    }
    if (touches.size > 1) return;
    finger = e.pointerId;
    const editor = hooks.editor();
    if (editor?.prompt() != null) {
      gesture = { kind: 'box', x: e.clientX, y: e.clientY, drawn: false };
      return;
    }
    const hit = editor ? hooks.itemAt(e.clientX, e.clientY, true) : null;
    const touch: Touch = { kind: 'touch', x: e.clientX, y: e.clientY, hit, onSelected: hit !== null && editor!.selection().includes(hit), held: false, timer: 0 };
    touch.timer = window.setTimeout(() => {
      if (gesture !== touch || !editor) return;
      touch.held = true;
      navigator.vibrate?.(10);
      if (hit !== null) toggle(editor, hit);
    }, LONG_PRESS_MS);
    gesture = touch;
  };

  const touchMove = (e: PointerEvent) => {
    const at = touches.get(e.pointerId);
    if (!at || !gesture) return;
    at.x = e.clientX;
    at.y = e.clientY;
    if (gesture.kind === 'pinch') {
      if (pinchFrame === 0) pinchFrame = requestAnimationFrame(pinchTo);
      return;
    }
    if (e.pointerId !== finger) return;
    if (gesture.kind === 'touch') {
      if (Math.hypot(e.clientX - gesture.x, e.clientY - gesture.y) < TOUCH_SLOP_PX) return;
      clearTimeout(gesture.timer);
      if (gesture.held) gesture = { kind: 'box', x: gesture.x, y: gesture.y, drawn: true };
      else if (gesture.onSelected) {
        hooks.editor()?.dragBegin(hooks.pageAt(gesture.x, gesture.y));
        gesture = { kind: 'drag' };
      } else gesture = panFrom(e.pointerId, { x: gesture.x, y: gesture.y }, e.timeStamp);
    }
    if (gesture.kind === 'pan') {
      viewport.scrollLeft = gesture.left - (e.clientX - gesture.x);
      viewport.scrollTop = gesture.top - (e.clientY - gesture.y);
      gesture.samples?.push({ x: e.clientX, y: e.clientY, t: e.timeStamp });
      if ((gesture.samples?.length ?? 0) > 8) gesture.samples!.shift();
    } else if (gesture.kind === 'box') {
      gesture.drawn ||= Math.hypot(e.clientX - gesture.x, e.clientY - gesture.y) >= TOUCH_SLOP_PX;
      if (gesture.drawn) showBand(band, gesture, { x: e.clientX, y: e.clientY });
    } else if (gesture.kind === 'drag') dragTo(e.clientX, e.clientY, false);
  };

  const tap = (touch: Touch, e: PointerEvent) => {
    const editor = hooks.editor();
    if (!editor || hooks.inputTap(e.clientX, e.clientY)) return;
    const previous = lastTap;
    lastTap = { x: e.clientX, y: e.clientY, t: e.timeStamp };
    if (touch.hit === null) {
      if (editor.selection().length > 0) {
        editor.select([]);
        hooks.selected();
      }
      hooks.clickedPaper(hooks.pageAt(e.clientX, e.clientY));
    } else pick(editor, touch.hit);
    if (previous && e.timeStamp - previous.t < DOUBLE_TAP_MS && Math.hypot(e.clientX - previous.x, e.clientY - previous.y) < 3 * TOUCH_SLOP_PX) {
      lastTap = null;
      hooks.open(touch.hit, e.clientX, e.clientY);
    }
  };

  const touchUp = (e: PointerEvent) => {
    if (!touches.delete(e.pointerId) || !gesture) return;
    if (gesture.kind === 'pinch') {
      if (touches.size >= 2) {
        startPinch();
        return;
      }
      const [rest] = Array.from(touches.entries());
      gesture = rest ? panFrom(rest[0], rest[1], e.timeStamp) : null;
      return;
    }
    if (e.pointerId !== finger) return;
    if (gesture.kind === 'touch') {
      clearTimeout(gesture.timer);
      if (!gesture.held) tap(gesture, e);
    } else if (gesture.kind === 'pan' && gesture.samples) startGlide(gesture.samples, e.timeStamp);
    else if (gesture.kind === 'box') endBox(gesture, e.clientX, e.clientY);
    else if (gesture.kind === 'drag') endDrag(true);
    gesture = null;
  };

  window.addEventListener('keydown', (e) => {
    if (isTyping(e.target) || document.querySelector('dialog[open]')) return;
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
