// What the UI asks of the editing model. The model belongs in Rust
// (editor-core's score-edit crate, wrapped by score-web); until that lands,
// `interimEditor` provides the same operations with plain parameter edits so
// the interaction layer can be built and tried.
import type { Score } from './wasm/score_web.js';

/** One undoable step, as the UI names it. */
export interface Change {
  label: string;
}

export interface Editor {
  /** Selected item indices, the primary (last clicked) one last. */
  selection(): number[];
  select(items: number[]): void;
  setParam(item: number, n: number, value: number): Change;
  /** Moves the selection by P3 spaces and P4 scale steps. */
  moveSelection(dp3: number, dp4: number): Change | null;
  /** [ and ]: the selection one staff up (+1) or down (−1). */
  moveStaff(step: 1 | -1): Change | null;
  deleteSelection(): Change | null;
  /** A SCORE edit-mode command line, e.g. "R 5" or "600 5". */
  execute(command: string): Change;
  dragBegin(): void;
  /** Total pointer travel since `dragBegin`, in page units; `constrain` keeps one axis. */
  dragTo(dx: number, dy: number, constrain: boolean): void;
  dragEnd(commit: boolean): Change | null;
  undo(): Change | null;
  redo(): Change | null;
  canUndo(): boolean;
  canRedo(): boolean;
}

interface ParamEdit {
  item: number;
  n: number;
  before: number;
  after: number;
}

interface Step {
  label: string;
  edits: ParamEdit[];
}

/** P3 units per page unit and page units per scale step at staff size 1 (score-render's page and staff modules). */
const P3_UNIT = 150;
const SCALE_STEP = 175;

/**
 * Parameter-level stand-in for the Rust editor: moves change P3 and P4
 * only, drags assume staff size 1, and delete and commands are not
 * available.
 */
export function interimEditor(score: Score): Editor {
  let selected: number[] = [];
  const done: Step[] = [];
  const undone: Step[] = [];
  let drag: { origin: Map<number, [number, number]>; current: ParamEdit[] } | null = null;

  const param = (item: number, n: number) => {
    const info = score.item(item);
    try {
      return info?.params[n - 1] ?? 0;
    } finally {
      info?.free();
    }
  };
  const write = (edits: ParamEdit[], value: (e: ParamEdit) => number) => edits.forEach((e) => score.setParam(e.item, e.n, value(e)));
  const commit = (label: string, edits: ParamEdit[]): Change | null => {
    if (edits.length === 0) return null;
    write(edits, (e) => e.after);
    done.push({ label, edits });
    undone.length = 0;
    return { label };
  };
  const shifted = (dp3: number, dp4: number) =>
    selected.flatMap((item) => [
      { item, n: 3, before: param(item, 3), after: param(item, 3) + dp3 },
      { item, n: 4, before: param(item, 4), after: param(item, 4) + dp4 },
    ]);

  return {
    selection: () => [...selected],
    select(items) {
      selected = [...new Set(items)];
    },
    setParam(item, n, value) {
      return commit(`Set P${n}`, [{ item, n, before: param(item, n), after: value }]) ?? { label: `Set P${n}` };
    },
    moveSelection: (dp3, dp4) => commit('Move', shifted(dp3, dp4)),
    moveStaff: (step) => commit(step > 0 ? 'Staff up' : 'Staff down', selected.map((item) => ({ item, n: 2, before: param(item, 2), after: param(item, 2) + step }))),
    deleteSelection() {
      throw new Error('Deleting items needs the Rust editor, which is not wired yet.');
    },
    execute() {
      throw new Error('Edit commands need the Rust editor, which is not wired yet.');
    },
    dragBegin() {
      drag = { origin: new Map(selected.map((item) => [item, [param(item, 3), param(item, 4)]])), current: [] };
    },
    dragTo(dx, dy, constrain) {
      if (!drag) return;
      const horizontal = !constrain || Math.abs(dx) >= Math.abs(dy);
      const dp3 = horizontal ? Math.round((dx / P3_UNIT) * 100) / 100 : 0;
      const dp4 = !constrain || !horizontal ? Math.round(dy / SCALE_STEP) : 0;
      drag.current = [...drag.origin].flatMap(([item, [p3, p4]]) => [
        { item, n: 3, before: p3, after: p3 + dp3 },
        { item, n: 4, before: p4, after: p4 + dp4 },
      ]);
      write(drag.current, (e) => e.after);
    },
    dragEnd(keep) {
      const edits = drag?.current.filter((e) => e.before !== e.after) ?? [];
      drag = null;
      if (keep) return commit('Drag', edits);
      write(edits, (e) => e.before);
      return null;
    },
    undo() {
      const step = done.pop();
      if (!step) return null;
      write([...step.edits].reverse(), (e) => e.before);
      undone.push(step);
      return { label: step.label };
    },
    redo() {
      const step = undone.pop();
      if (!step) return null;
      write(step.edits, (e) => e.after);
      done.push(step);
      return { label: step.label };
    },
    canUndo: () => done.length > 0,
    canRedo: () => undone.length > 0,
  };
}
