// What the UI asks of the editing model, and its implementation by
// score-edit through score-web. Items are named by file index; every action
// returns the name of the undo step it made.
import type { InputLine, Score } from './wasm/score_web.js';

/** One finished action, as the UI names it; null when nothing changed. */
export interface Change {
  label: string;
}

export interface Editor {
  /** Selected item indices, the primary (last clicked) one last. */
  selection(): number[];
  select(items: number[]): void;
  setParam(item: number, n: number, value: number): Change | null;
  /** Moves the selection by P3 spaces and P4 scale steps. */
  moveSelection(dp3: number, dp4: number): Change | null;
  /** [ and ]: the selection one staff up (+1) or down (−1). */
  moveStaff(step: 1 | -1): Change | null;
  deleteSelection(): Change | null;
  /** A SCORE edit-mode command line, e.g. "R 5" or "600 5". */
  execute(command: string): Change | null;
  /** Adds one line of five-pass input; the new items become the selection. */
  insertInput(line: InputLine): Change | null;
  dragBegin(): void;
  /** Total pointer travel since `dragBegin`, in page units; `constrain` (Shift) keeps the first dominant axis. */
  dragTo(dx: number, dy: number, constrain: boolean): void;
  dragEnd(commit: boolean): Change | null;
  undo(): Change | null;
  redo(): Change | null;
  undoLabel(): string | null;
  redoLabel(): string | null;
}

const change = (label: string | undefined): Change | null => (label ? { label } : null);

/** WinScore locks a Shift-drag to the first axis whose travel exceeds this many engine units (analysis/engine/editing.md). */
const AXIS_LOCK_UNITS = 50;

type Axis = 'x' | 'y';

function lockedAxis(dx: number, dy: number): Axis | null {
  if (Math.max(Math.abs(dx), Math.abs(dy)) <= AXIS_LOCK_UNITS) return null;
  return Math.abs(dx) >= Math.abs(dy) ? 'x' : 'y';
}

export function scoreEditor(score: Score): Editor {
  let axis: Axis | null = null;
  return {
    selection: () => Array.from(score.selection()),
    select: (items) => score.select(Uint32Array.from(items)),
    setParam: (item, n, value) => change(score.setParam(item, n, value)),
    moveSelection: (dp3, dp4) => change(score.moveSelection(dp3, dp4)),
    moveStaff: (step) => change(score.moveStaff(step)),
    deleteSelection: () => change(score.deleteSelection()),
    execute: (command) => change(score.execute(command)),
    insertInput: (line) => change(score.insertInput(line)),
    dragBegin() {
      axis = null;
      score.dragBegin();
    },
    dragTo(dx, dy, constrain) {
      axis ??= lockedAxis(dx, dy);
      const keep = (a: Axis) => !constrain || axis === null || axis === a;
      score.dragTo(keep('x') ? dx : 0, keep('y') ? dy : 0);
    },
    dragEnd: (commit) => change(score.dragEnd(commit)),
    undo: () => change(score.undo() && `Undo ${score.redoLabel()}`),
    redo: () => change(score.redo() && `Redo ${score.undoLabel()}`),
    undoLabel: () => score.undoLabel() ?? null,
    redoLabel: () => score.redoLabel() ?? null,
  };
}
