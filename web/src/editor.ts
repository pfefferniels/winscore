// What the UI asks of the editing model, and its implementation by
// score-edit through score-web. Items are named by file index; every action
// returns the name of the undo step it made.
import type { InputLine, Score } from './wasm/score_web.js';
import type { Point } from './view';

/** Where an item goes in SCORE's terms. */
export interface Place {
  staff: number;
  p3: number;
  p4: number;
}

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
  /** New text items as SCORE's quick entry makes them; `params` are P2, P3, … (0 = default). */
  insertText(text: string, params: number[]): Change | null;
  /** Replaces a text item's characters. */
  setText(item: number, text: string): Change | null;
  /** A code-9 item showing a library symbol, selected. */
  insertSymbol(symbol: number, place: Place): Change | null;
  /** A box drawn on the page: answers a waiting group command, or selects what is inside. */
  drawBox(from: Point, to: Point): Change | null;
  /** The question a group command waits to have answered on the command bar. */
  prompt(): string | null;
  /** Staff, P3 and P4 of a page point on the nearest staff. */
  placeAt(at: Point): Place | null;
  /** Takes hold of the selection at a page point. */
  dragBegin(at: Point): void;
  /** Moves it with the cursor, keeping the grab offset; `constrain` is WinScore's Shift rule. */
  dragTo(at: Point, constrain: boolean): void;
  dragEnd(commit: boolean): Change | null;
  undo(): Change | null;
  redo(): Change | null;
  undoLabel(): string | null;
  redoLabel(): string | null;
}

const change = (label: string | undefined): Change | null => (label ? { label } : null);

export function scoreEditor(score: Score): Editor {
  return {
    selection: () => Array.from(score.selection()),
    select: (items) => score.select(Uint32Array.from(items)),
    setParam: (item, n, value) => change(score.setParam(item, n, value)),
    moveSelection: (dp3, dp4) => change(score.moveSelection(dp3, dp4)),
    moveStaff: (step) => change(score.moveStaff(step)),
    deleteSelection: () => change(score.deleteSelection()),
    execute: (command) => change(score.execute(command)),
    insertInput: (line) => change(score.insertInput(line)),
    insertText: (text, params) => change(score.insertText(text, Float32Array.from(params))),
    setText: (item, text) => change(score.setText(item, text)),
    insertSymbol: (symbol, place) => change(score.insertSymbol(symbol, place.staff, place.p3, place.p4)),
    drawBox: (from, to) => change(score.drawBox(from.x, from.y, to.x, to.y)),
    prompt: () => score.prompt() ?? null,
    placeAt(at) {
      const found = score.placeAt(at.x, at.y);
      return found ? { staff: found[0]!, p3: found[1]!, p4: found[2]! } : null;
    },
    dragBegin: (at) => score.dragBeginAt(at.x, at.y),
    dragTo: (at, constrain) => score.dragToPoint(at.x, at.y, constrain),
    dragEnd: (commit) => change(score.dragEnd(commit)),
    undo: () => change(score.undo() && `Undo ${score.redoLabel()}`),
    redo: () => change(score.redo() && `Redo ${score.undoLabel()}`),
    undoLabel: () => score.undoLabel() ?? null,
    redoLabel: () => score.redoLabel() ?? null,
  };
}
