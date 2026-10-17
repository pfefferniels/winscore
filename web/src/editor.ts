// What the UI asks of the editing model, and its implementation by
// score-edit through score-web. Items are named by file index; every action
// returns the name of the undo step it made.
import type { InputLine, Outcome, Score } from './wasm/score_web.js';
import type { Point } from './view';

/** Where an item goes in SCORE's terms. */
export interface Place {
  staff: number;
  p3: number;
  p4: number;
}

/** One finished action, as the UI names it, and what the engine would have reported. */
export interface Change {
  label: string;
  message: string | null;
}

export interface Editor {
  /** Selected item indices, the primary (last clicked) one last. */
  selection(): number[];
  select(items: number[]): void;
  /** Sets parameters [n, value] of items, each with values of its own, as one undo step. */
  setParamsOf(edits: [item: number, changes: [n: number, value: number][]][]): Change | null;
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
  /** The selected items in file order as a `.mus` file of their own, for the clipboard; empty without a selection. */
  copySelection(): Uint8Array;
  /** Deletes the selection; take it for the clipboard with `copySelection` first. */
  cutSelection(): Change | null;
  /** Copies of items from `copySelection` (of any score) where they were copied from, selected; ten P3 spaces on while they would lie exactly on the same items. */
  pasteInPlace(items: Uint8Array): Change | null;
  /** The same with their lowest staff on the place's staff and their left edge at its P3. */
  pasteAt(items: Uint8Array, place: Place): Change | null;
  /** Copies of the selection ten P3 spaces to the right (further past earlier copies), selected. */
  duplicateSelection(): Change | null;
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
  /** The handles of an item as score-web describes them (JSON, see handles.ts). */
  handles(item: number): string;
  /** Takes hold of handle `handle` of `item` at a page point; false if it has none such. */
  handleBegin(item: number, handle: number, at: Point): boolean;
  /** Drags it, setting what it changes live; returns the words for the values. */
  handleTo(at: Point, constrain: boolean, tolerance: number): string;
  handleEnd(commit: boolean): Change | null;
  /** Six numbers per item for guides: code, staff, reference x and y, level, centre x. */
  anchors(): Float32Array;
  /** Seven numbers per staff: number, left and right x, y of level 0, scale step, lowest line's level, lines. */
  staves(): Float32Array;
  undo(): Change | null;
  redo(): Change | null;
  undoLabel(): string | null;
  redoLabel(): string | null;
}

/** The UI's view of an outcome; null when nothing changed and nothing was reported. */
function change(outcome: Outcome): Change | null {
  const result = outcome.label || outcome.message ? { label: outcome.label, message: outcome.message ?? null } : null;
  outcome.free();
  return result;
}

const stepped = (label: string | null): Change | null => (label ? { label, message: null } : null);

export function scoreEditor(score: Score): Editor {
  return {
    selection: () => Array.from(score.selection()),
    select: (items) => score.select(Uint32Array.from(items)),
    setParamsOf(edits) {
      const flat = edits.flatMap(([item, changes]) => changes.map(([n, value]) => [item, n, value] as const));
      return change(
        score.setParamsOf(
          Uint32Array.from(flat, ([item]) => item),
          Uint32Array.from(flat, ([, n]) => n),
          Float32Array.from(flat, ([, , value]) => value),
        ),
      );
    },
    moveSelection: (dp3, dp4) => change(score.moveSelection(dp3, dp4)),
    moveStaff: (step) => change(score.moveStaff(step)),
    deleteSelection: () => change(score.deleteSelection()),
    execute: (command) => change(score.execute(command)),
    insertInput: (line) => change(score.insertInput(line)),
    insertText: (text, params) => change(score.insertText(text, Float32Array.from(params))),
    setText: (item, text) => change(score.setText(item, text)),
    insertSymbol: (symbol, place) => change(score.insertSymbol(symbol, place.staff, place.p3, place.p4)),
    copySelection: () => score.copySelection(),
    cutSelection: () => change(score.cutSelection()),
    pasteInPlace: (items) => change(score.pasteInPlace(items)),
    pasteAt: (items, place) => change(score.pasteAt(items, place.staff, place.p3)),
    duplicateSelection: () => change(score.duplicateSelection()),
    drawBox: (from, to) => change(score.drawBox(from.x, from.y, to.x, to.y)),
    prompt: () => score.prompt() ?? null,
    placeAt(at) {
      const found = score.placeAt(at.x, at.y);
      return found ? { staff: found[0]!, p3: found[1]!, p4: found[2]! } : null;
    },
    dragBegin: (at) => score.dragBeginAt(at.x, at.y),
    dragTo: (at, constrain) => score.dragToPoint(at.x, at.y, constrain),
    dragEnd: (commit) => change(score.dragEnd(commit)),
    handles: (item) => score.handles(item),
    handleBegin: (item, handle, at) => score.handleBegin(item, handle, at.x, at.y),
    handleTo: (at, constrain, tolerance) => score.handleTo(at.x, at.y, constrain, tolerance),
    handleEnd: (commit) => change(score.handleEnd(commit)),
    anchors: () => score.guideAnchors(),
    staves: () => score.staffGeometry(),
    undo: () => stepped(score.undo() ? `Undo ${score.redoLabel()}` : null),
    redo: () => stepped(score.redo() ? `Redo ${score.undoLabel()}` : null),
    undoLabel: () => score.undoLabel() ?? null,
    redoLabel: () => score.redoLabel() ?? null,
  };
}
