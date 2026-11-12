import './style.css';
import init, { codeName, commandSupported, creationParams, librarySymbols, paramName, Score, type EncodedList } from './wasm/score_web.js';
import { createPageView, type Scene } from './canvas';
import { baseName, desktop } from './desktop';
import { bindClipboard } from './clipboard';
import { bounds, decode, elementsOf, EMPTY, itemBoxes, union, type Box, type DisplayList } from './display';
import { fontCodes, fontPrefix } from './commands';
import type { Point } from './view';
import { scoreEditor, type Change, type Editor, type Place } from './editor';
import { loadFaces } from './fonts';
import { buildField, codeOf, moveProbes, paintGuides, snap, wantsForHandle, wantsForMove, type Field, type Guide, type Probes, type ScoreFacts } from './guides';
import { cursorFor, decodeHandles, devicePoint, handleAt as handleUnder, paintHandles, paintPill, visibleHandles, type Handle, type HandleSet } from './handles';
import type { Context } from './item-fields';
import { bindInteraction, type Client } from './interaction';
import { labelOf, MOD, type Action, type Menu } from './menu';
import { appMenus, type DialogKind } from './menus';
import { bindPanelGrip, formatParam, renderSelection, type ItemDetails, type ItemSummary, type PanelHandlers } from './panel';
import type { Layer, Overlay } from './paint';
import { createPreview, type Sketch } from './preview';
import { download, printPage } from './print';
import { createQuestion } from './question';
import { embedFonts } from './svg-fonts';
import { createSymbolDialog } from './symbol-dialog';
import { createTextDialog, editInPlace, withFont } from './text-dialog';
import { createToolbar } from './toolbar';
import { createTools, type Facts, type Tool } from './tools';
import { stepZoom, toDevice, ZOOM_LEVELS } from './view';

interface Sample {
  title: string;
  /** The `.mus` bytes as base64 text. */
  url: string;
  case: string;
}

interface State {
  score: Score | null;
  editor: Editor | null;
  fileName: string;
  /** Where the score's file is on disk, in the desktop app; null for a new score or a sample. */
  path: string | null;
  rust: DisplayList;
  modified: boolean;
  /** The last click on empty paper, where new items go when nothing is selected. */
  lastPaper: Point | null;
  /** Where pastes go: the last click on the page since the copy, if any. */
  pasteAt: Point | null;
  /** The scrollable page area; kept while a drag is in progress. */
  extent: Box | null;
  /** Whether the side panel (selected item, item list) is shown. */
  panel: boolean;
  /** The handles of the selected item while it is the only one selected. */
  handles: HandleSet | null;
  /** The handle under the mouse. */
  hover: number | null;
  /** A move or handle drag in progress, with its guides. */
  drag: Drag | null;
}

/** A move of the selection or a drag of one of its handles. */
interface Drag {
  /** The handle held; null when the items themselves move. */
  handle: Handle | null;
  /** Where the drag took hold, page coordinates. */
  from: Point;
  field: Field;
  probes: Probes;
  /** The dragged thing's extent when the drag began. */
  span: Box;
  /** The axes guides may snap. */
  axes: { x: boolean; y: boolean };
  guides: Guide[];
  /** What the values are now, shown by the cursor. */
  readout: string;
  /** The held handle's place now, and the cursor's (page coordinates). */
  at: Point;
  cursor: Point;
}

const MARGIN = 1000;
const CLICK_TOLERANCE_PX = 4;
/** Without an outline under the pointer, WinScore's nearest-reference-point rule applies within this radius. */
const PICK_RADIUS_PX = 12;
/** A finger covers more than a mouse pointer: it picks from further away. */
const TOUCH_TOLERANCE_PX = 10;
const TOUCH_PICK_RADIUS_PX = 24;
/** Guides pull a dragged thing from this far, in CSS pixels (a finger from further). */
const SNAP_PX = 6;
const TOUCH_SNAP_PX = 10;
/** A handle is taken from this far, in CSS pixels. */
const HANDLE_PX = 8;
const TOUCH_HANDLE_PX = 22;

const $ = <T extends HTMLElement>(id: string) => document.getElementById(id) as T;

const ui = {
  app: $<HTMLDivElement>('app'),
  file: $<HTMLInputElement>('file'),
  doc: $<HTMLSpanElement>('doc'),
  docState: $<HTMLSpanElement>('doc-state'),
  undo: $<HTMLButtonElement>('undo'),
  redo: $<HTMLButtonElement>('redo'),
  symbolDialog: $<HTMLDialogElement>('symbol-dialog'),
  textDialog: $<HTMLDialogElement>('text-dialog'),
  band: $<HTMLDivElement>('band'),
  zoomOut: $<HTMLButtonElement>('zoom-out'),
  zoomIn: $<HTMLButtonElement>('zoom-in'),
  zoom: $<HTMLSelectElement>('zoom'),
  fit: $<HTMLButtonElement>('fit'),
  togglePanel: $<HTMLButtonElement>('toggle-panel'),
  help: $<HTMLButtonElement>('help'),
  palette: $<HTMLElement>('palette'),
  toolOptions: $<HTMLDivElement>('tool-options'),
  shortcuts: $<HTMLDialogElement>('shortcuts-dialog'),
  commandList: $<HTMLElement>('command-list'),
  status: $<HTMLSpanElement>('status'),
  stage: $<HTMLDivElement>('stage'),
  viewport: $<HTMLDivElement>('viewport'),
  content: $<HTMLDivElement>('content'),
  canvas: $<HTMLCanvasElement>('canvas'),
  dropHint: $<HTMLDivElement>('drop-hint'),
  emptyHint: $<HTMLDivElement>('empty-hint'),
  start: $<HTMLElement>('start'),
  startNew: $<HTMLButtonElement>('start-new'),
  startOpen: $<HTMLButtonElement>('start-open'),
  startSamples: $<HTMLDivElement>('start-samples'),
  panel: $<HTMLElement>('panel'),
  panelGrip: $<HTMLDivElement>('panel-grip'),
  item: $<HTMLElement>('item'),
  cursor: $<HTMLSpanElement>('cursor'),
  message: $<HTMLSpanElement>('message'),
};

const PANEL_KEY = 'winscore.panel';
/** The width below which the stylesheet lays the app out for a phone: the panel goes under the page. */
const NARROW = '(max-width: 640px)';
/** A touch screen. */
const COARSE = '(pointer: coarse)';

/** The remembered side panel setting; storage may be unavailable. A phone starts without it, to leave the page room. */
function storedPanel(): boolean {
  const fallback = !matchMedia(NARROW).matches;
  try {
    const stored = localStorage.getItem(PANEL_KEY);
    return stored === null ? fallback : stored !== 'hidden';
  } catch {
    return fallback;
  }
}

const state: State = {
  score: null,
  editor: null,
  fileName: '',
  path: null,
  rust: EMPTY,
  modified: false,
  lastPaper: null,
  pasteAt: null,
  extent: null,
  panel: storedPanel(),
  handles: null,
  hover: null,
  drag: null,
};

const view = createPageView(ui, showZoom);
/** Names of the item codes P1 takes, looked up once each. */
const codeNames = new Map<number, string>();

function nameOf(code: number): string {
  if (!codeNames.has(code)) codeNames.set(code, codeName(code) ?? `Code ${code}`);
  return codeNames.get(code)!;
}
view.onPaint(describeSelection);
const symbolDialog = createSymbolDialog(ui.symbolDialog);
const textDialog = createTextDialog(ui.textDialog);
/** A group command's question, answered by drawing on the page or in its field. */
const question = createQuestion(ui.stage, {
  answer: (line) => void runCommand(line),
  cancel: () => void runCommand('X'),
  left: () => ui.viewport.focus(),
});
/** Where an insertion mode's new item would go, over the page. */
const preview = createPreview(ui.stage, ui.canvas, () => view.transform());
view.onPaint(() => preview.repaint());
let samples: Sample[] = [];

function showZoom(zoom: number) {
  const rounded = Math.round(zoom);
  const options = [...new Set([...ZOOM_LEVELS, rounded])].sort((a, b) => a - b);
  ui.zoom.replaceChildren(...options.map((z) => new Option(`${z} %`, String(z), false, z === rounded)));
}

function message(text: string, error = false) {
  ui.message.textContent = text;
  ui.message.classList.toggle('error', error);
}

/** The primary selected item as WinScore's edit mode lists it: number, kind and P1…Pn. */
function itemLine(): string {
  const index = primary();
  const info = index === null ? undefined : state.score?.item(index);
  if (!info) return '';
  try {
    return `Item ${index} ${info.name ?? ''}: ${Array.from(info.params, formatParam).join(' ')}`;
  } finally {
    info.free();
  }
}

/** The status line: what just happened, then the item in edit mode; the engine's own message instead when it has one. */
function report(change: Change | null) {
  if (change?.message) message(change.message, true);
  else message([change?.label, itemLine()].filter(Boolean).join(' · '));
  // A group command's question shows over the page, where the mouse answers it; an insertion mode gives way to it.
  // A touch screen would bring up its keyboard over the page the box is drawn on.
  const asked = state.editor?.prompt() ?? null;
  if (asked !== null && toolbar.tool) toolbar.choose(null);
  question.ask(asked, !touchScreen());
}

function decodeAndFree(encoded: EncodedList): DisplayList {
  try {
    return decode(encoded);
  } finally {
    encoded.free();
  }
}

function paperBox(): Box {
  const width = state.score?.paperWidth() ?? 34000;
  const height = state.score?.paperHeight() ?? 56000;
  return { x0: 0, y0: 0, x1: width, y1: height };
}

function extent(paper: Box): Box {
  const content = union(bounds(state.rust), paper) ?? paper;
  return { x0: content.x0 - MARGIN, y0: content.y0 - MARGIN, x1: content.x1 + MARGIN, y1: content.y1 + MARGIN };
}

function layers(): Layer[] {
  return [{ list: state.rust }];
}

function selection(): number[] {
  return state.editor?.selection() ?? [];
}

/** The primary item of the selection: the last one selected. */
function primary(): number | null {
  return selection().at(-1) ?? null;
}

const touchScreen = () => matchMedia(COARSE).matches;
const dpr = () => window.devicePixelRatio || 1;

/** Handles, guides and the readout over the page. */
function overlays(): Overlay[] {
  const drawn: Overlay[] = [];
  // In an insertion mode a press puts a new item down, so the selection's handles are not offered.
  const shown = state.handles && state.editor?.prompt() == null && !toolbar.tool;
  if (shown && (!state.drag || state.drag.handle)) {
    drawn.push((ctx, t) => {
      const drag = state.drag;
      const active = drag?.handle ? { index: drag.handle.index, at: drag.at } : null;
      if (state.handles) paintHandles(ctx, t, { set: state.handles, hover: drag ? null : state.hover, active, coarse: touchScreen(), dpr: dpr() });
    });
  }
  if (state.drag) {
    drawn.push((ctx, t) => {
      const drag = state.drag;
      if (!drag) return;
      paintGuides(ctx, t, drag.guides, dpr());
      if (drag.readout) {
        const p = toDevice(t, drag.cursor.x, drag.cursor.y);
        const away = (touchScreen() ? 40 : 16) * dpr();
        paintPill(ctx, drag.readout, { x: p.x + away, y: p.y + away }, dpr());
      }
    });
  }
  return drawn;
}

/** What the page view shows; `live` (a drag in progress) keeps the scrollable area as it was. */
function scene(live = false): Scene {
  const paper = paperBox();
  if (!live || !state.extent) state.extent = extent(paper);
  return {
    layers: layers(),
    paper,
    extent: state.extent,
    highlights: selection().map((item) => ({ list: state.rust, item })),
    overlays: overlays(),
  };
}

/** The handles of the selected item when it is the only one. */
function refreshHandles() {
  const items = selection();
  const editor = state.editor;
  state.handles = editor && items.length === 1 ? decodeHandles(items[0]!, editor.handles(items[0]!)) : null;
  if (state.hover !== null && !state.handles?.handles[state.hover]) state.hover = null;
}

const REDO_KEYS = MOD === '⌘' ? '⇧⌘Z' : 'Ctrl+Y';

let shownTitle = '';

function refreshStatus() {
  const open = state.score !== null;
  const title = open ? `${state.fileName}${state.modified ? ' — Edited' : ''}` : 'WinScore';
  if (desktop && title !== shownTitle) desktop.setTitle(title);
  shownTitle = title;
  ui.doc.hidden = !open;
  ui.status.textContent = state.fileName;
  ui.docState.textContent = state.modified ? 'Unsaved changes' : '';
  ui.doc.title = state.modified ? `${state.fileName}: changed since it was opened or saved` : state.fileName;
  const undo = state.editor?.undoLabel() ?? null;
  const redo = state.editor?.redoLabel() ?? null;
  ui.undo.disabled = undo === null;
  ui.redo.disabled = redo === null;
  ui.undo.title = undo === null ? 'Nothing to undo' : `Undo ${undo} (${MOD}Z)`;
  ui.redo.title = redo === null ? 'Nothing to redo' : `Redo ${redo} (${REDO_KEYS})`;
  [ui.zoomIn, ui.zoomOut, ui.zoom, ui.fit].forEach((control) => (control.disabled = !open));
  ui.start.hidden = open;
  toolbar.setVisible(open);
  ui.panel.hidden = !open || !state.panel;
  ui.togglePanel.disabled = !open;
  ui.emptyHint.hidden = !open || state.score!.itemCount() > 0;
  // How many items there are, as `data-items` of the page: for tests and the browser's inspector.
  ui.app.dataset.items = open ? String(state.score!.itemCount()) : '';
}

/** Highest parameter number an edit may set. */
const MAX_PARAM = 45;

/** The help's labels by item code, looked up once each. */
const paramLabels = new Map<number, (string | null)[]>();

/** The help's labels of P1 … up to the last one it describes for `code`. */
function paramNames(code: number): (string | null)[] {
  if (!paramLabels.has(code)) {
    const names = Array.from({ length: MAX_PARAM }, (_, i) => paramName(code, i + 1) ?? null);
    while (names.length > 0 && names.at(-1) === null) names.pop();
    paramLabels.set(code, names);
  }
  return paramLabels.get(code)!;
}

let symbolNames: Map<number, string> | null = null;

function symbolName(n: number): string | null {
  symbolNames ??= new Map(JSON.parse(librarySymbols()) as [number, string][]);
  return symbolNames.get(n)?.trim() || null;
}

/** P4 and P5 of the clef in force at item `index`. */
function clefAt(score: Score, index: number): Context['clef'] {
  const clef = score.clefAt(index);
  const info = clef === undefined ? undefined : score.item(clef);
  if (!info) return null;
  const params = info.params;
  info.free();
  return { p4: params[3] ?? 0, p5: params[4] ?? 0 };
}

/** What the panel shows of item `index`; whether it is drawn only when it is `alone` in the selection. */
function details(score: Score, index: number, alone: boolean): ItemDetails | null {
  const info = score.item(index);
  if (!info) return null;
  try {
    const params = info.params;
    return {
      index,
      code: info.code,
      name: info.name ?? `Code ${info.code}`,
      staff: params[1] ?? 0,
      p3: params[2] ?? 0,
      params,
      paramNames: paramNames(info.code),
      context: { clef: info.code === 1 ? clefAt(score, index) : null, symbolName },
      text: info.text ?? null,
      drawn: alone ? bounds(elementsOf(state.rust, index)) !== null : undefined,
    };
  } finally {
    info.free();
  }
}

function itemSummaries(score: Score): ItemSummary[] {
  const numbers = score.itemSummaries();
  return Array.from({ length: numbers.length / 3 }, (_, index) => {
    const [code = 0, staff = 0, p3 = 0] = numbers.subarray(3 * index, 3 * index + 3);
    return { index, code, name: nameOf(code), staff, p3 };
  });
}

/** Re-renders the parameter panel, keeping the keyboard in the field it was in. */
function refreshPanel() {
  const score = state.score;
  const items = selection();
  const shown = score ? items.flatMap((index) => details(score, index, items.length === 1) ?? []) : [];
  const focused = ui.item.contains(document.activeElement) ? document.activeElement?.id : undefined;
  renderSelection(ui.item, shown, handlers, score !== null);
  const field = focused ? ui.item.querySelector<HTMLElement>(`#${focused}`) : null;
  field?.focus();
  if (field instanceof HTMLInputElement && field.type === 'text') field.select();
}

function redraw(live = false) {
  view.setScene(scene(live));
  if (!live) refreshStatus();
}

async function loadFontsAndRepaint() {
  await loadFaces(state.rust.texts);
  view.repaint();
}

function selectionChanged() {
  refreshHandles();
  refreshPanel();
  redraw();
  report(null);
}

/** Scrolls the selected items into view unless they are visible. */
function revealSelection() {
  const box = selection()
    .map((item) => bounds(elementsOf(state.rust, item)))
    .reduce(union, null);
  if (box) view.reveal(box);
}

function select(items: number[], reveal = false) {
  state.editor?.select(items);
  selectionChanged();
  if (reveal) revealSelection();
}

/** ⌘A, Edit ▸ Select all: every item of the score. */
function selectAll() {
  const score = state.score;
  if (score) select(Array.from({ length: score.itemCount() }, (_, i) => i));
}

/** Re-renders after an edit; the panel follows once a drag is over. */
function edited(change: Change | null, live: boolean) {
  const score = state.score;
  if (!score) return;
  state.rust = decodeAndFree(live ? score.renderSelection() : score.render());
  if (live && state.drag && !state.drag.handle) state.drag.readout = moveReadout();
  if (!live) {
    refreshHandles();
    state.modified ||= change !== null;
    refreshPanel();
    void loadFontsAndRepaint();
    report(change);
  }
  redraw(live);
}

function failed(err: unknown) {
  message(err instanceof Error ? err.message : String(err), true);
}

/** Runs an edit and shows its outcome; what it did, with a failure as its message. */
function edit(action: (editor: Editor) => Change | null): Change | null {
  const editor = state.editor;
  if (!editor) return null;
  try {
    const change = action(editor);
    edited(change, false);
    return change;
  } catch (err) {
    failed(err);
    return { label: '', message: err instanceof Error ? err.message : String(err) };
  }
}

/** A SCORE command line from a menu, the panel, a key or a group command's answer; the result is scrolled into view. */
function runCommand(line: string): Change | null {
  const change = edit((editor) => editor.execute(line));
  revealSelection();
  return change;
}

/** Group edits (M, CO, DG, A, CPX) start outside edit mode and ask for the area; a drawn box answers. */
function runArea(line: string) {
  state.editor?.select([]);
  selectionChanged();
  runCommand(line);
}

/** Where a new item goes: at the selected item, else at the last click on the paper, else on the top staff at P3 100. */
function placeForNew(): Place {
  const index = primary();
  const info = index === null ? undefined : state.score?.item(index);
  if (info) {
    const [, staff = 1, p3 = 100, p4 = 0] = info.params;
    info.free();
    return { staff, p3, p4 };
  }
  const clicked = state.lastPaper ? state.editor?.placeAt(state.lastPaper) : null;
  return clicked ?? { staff: state.score?.highestStaff() ?? 1, p3: 100, p4: 0 };
}

/** ⌘C, ⌘X: the selected items for the clipboard; a cut deletes them too. Pastes then go to their own place until the next click. */
function copySelection(cut: boolean): Uint8Array {
  const editor = state.editor;
  const count = selection().length;
  if (!editor || count === 0) return new Uint8Array();
  const items = editor.copySelection();
  state.pasteAt = null;
  if (cut) edit((ed) => ed.cutSelection());
  else message(`Copied ${count} ${count === 1 ? 'item' : 'items'}`);
  return items;
}

/** ⌘V: copies where the page was last clicked since the copy, else where they were copied from (beside the originals if they are still there). */
function paste(items: Uint8Array) {
  const place = state.pasteAt ? state.editor?.placeAt(state.pasteAt) : null;
  edit((editor) => (place ? editor.pasteAt(items, place) : editor.pasteInPlace(items)));
  revealSelection();
}

function duplicate() {
  edit((editor) => editor.duplicateSelection());
  revealSelection();
}

const clipboard = bindClipboard(
  {
  ready: () => state.editor !== null,
  hasSelection: () => selection().length > 0,
  copy: () => copySelection(false),
  cut: () => copySelection(true),
  paste,
  duplicate,
  },
  desktop !== null,
);

async function openDialog(kind: DialogKind) {
  if (!state.editor) return;
  const place = placeForNew();
  if (kind === 'symbol') {
    const symbol = await symbolDialog.choose();
    if (symbol !== null) edit((editor) => editor.insertSymbol(symbol, place));
  } else {
    const text = await textDialog.create(place);
    if (text) edit((editor) => editor.insertText(text.text, text.params));
  }
  revealSelection();
  ui.viewport.focus();
}

/** Double click on a text item: edit its characters where they stand. */
async function openItem(item: number | null) {
  const info = item === null ? undefined : state.score?.item(item);
  const text = info?.text ?? null;
  info?.free();
  if (item === null || text === null) return;
  const box = bounds(elementsOf(state.rust, item));
  if (!box) {
    ui.item.querySelector<HTMLInputElement>('#item-text')?.focus();
    return;
  }
  const edited = await editInPlace(ui.stage, view.clientRect(box), text);
  if (edited !== null && edited !== text) edit((editor) => editor.setText(item, edited));
  ui.viewport.focus();
}

const handlers: PanelHandlers = {
  selectItems: (items) => select(items),
  run: (command) => {
    runCommand(command);
    ui.viewport.focus();
  },
  setParams: (edits) => edit((editor) => editor.setParamsOf(edits)),
  async pickSymbol(items) {
    const symbol = await symbolDialog.choose();
    if (symbol !== null) edit((editor) => editor.setParamsOf(items.map((index) => [index, [[5, symbol]]])));
  },
  setText: (index, text) => edit((editor) => editor.setText(index, text)),
  setFont(items, code) {
    state.editor?.select(items);
    runCommand(`FNT${fontPrefix(code).slice(1)}`);
  },
};

/** Asks before changes that were not saved are thrown away. */
async function mayDiscard(): Promise<boolean> {
  if (!state.modified) return true;
  const question = `Discard the unsaved changes to ${state.fileName}?`;
  return desktop ? desktop.confirm(question, 'Discard') : window.confirm(question);
}

function openScore(score: Score, name: string) {
  preview.show(null);
  state.score?.free();
  state.score = score;
  state.editor = scoreEditor(score);
  state.fileName = name;
  state.path = null;
  state.rust = decodeAndFree(score.render());
  state.modified = false;
  state.lastPaper = null;
  state.pasteAt = null;
  state.handles = null;
  state.drag = null;
  refreshPanel();
  redraw();
  view.fitWidth();
  const content = bounds(state.rust);
  if (content) view.scrollToTop(content.y1 + MARGIN);
  void loadFontsAndRepaint();
  report(null);
}

async function newScore() {
  if (!(await mayDiscard())) return;
  openScore(Score.empty(), 'untitled.mus');
}

async function openSample(sample: Sample) {
  if (!(await mayDiscard())) return;
  try {
    const base64 = (await (await fetch(sample.url)).text()).trim();
    const bytes = Uint8Array.from(atob(base64), (c) => c.charCodeAt(0));
    openScore(new Score(bytes), sample.title);
  } catch (err) {
    message(`Cannot open ${sample.title}: ${String(err)}`, true);
  }
}

async function chooseFile() {
  if (!(await mayDiscard())) return;
  if (!desktop) {
    ui.file.click();
    return;
  }
  const path = await desktop.pickOpen();
  if (path) await openPath(path);
}

/** The desktop app: the score in the file at `path`, which Save then writes. */
async function openPath(path: string) {
  if (!desktop) return;
  try {
    openScore(new Score(await desktop.read(path)), baseName(path));
    state.path = path;
    refreshStatus();
  } catch (err) {
    message(`Cannot open ${baseName(path)}: ${String(err)}`, true);
  }
}

async function openFile(file: File) {
  try {
    openScore(new Score(new Uint8Array(await file.arrayBuffer())), file.name);
  } catch (err) {
    message(`Cannot open ${file.name}: ${String(err)}`, true);
  }
}

/** Saves the score: in a browser as a download, in the desktop app to its file (`as`, or without one: where the save panel says). */
async function save(as = false) {
  if (!state.score) return;
  const bytes = state.score.save() as Uint8Array<ArrayBuffer>;
  if (!desktop) {
    download(bytes, state.fileName || 'score.mus', 'application/octet-stream');
    state.modified = false;
    refreshStatus();
    return;
  }
  const path = !as && state.path ? state.path : await desktop.pickSave(state.fileName || 'untitled.mus', 'mus', 'SCORE file');
  if (!path) return;
  try {
    await desktop.write(path, bytes);
  } catch (err) {
    failed(err);
    return;
  }
  state.path = path;
  state.fileName = baseName(path);
  state.modified = false;
  refreshStatus();
  message(`Saved ${path}`);
}

/** The score's file name with another extension. */
function exportName(extension: string): string {
  return `${(state.fileName || 'score').replace(/\.[^.]*$/, '')}.${extension}`;
}

/** The printed page as an SVG file, with the faces of its text embedded. */
async function exportSvg() {
  if (!state.score) return;
  try {
    const svg = await embedFonts(state.score.exportSvg());
    if (!desktop) {
      download(svg, exportName('svg'), 'image/svg+xml');
      return;
    }
    const path = await desktop.pickSave(exportName('svg'), 'svg', 'SVG image');
    if (path) {
      await desktop.write(path, new TextEncoder().encode(svg));
      message(`Exported ${path}`);
    }
  } catch (err) {
    failed(err);
  }
}

async function print() {
  if (!state.score) return;
  try {
    await printPage(state.score.exportSvg(), paperBox());
  } catch (err) {
    failed(err);
  }
}

function setPanel(shown: boolean) {
  state.panel = shown;
  ui.panel.hidden = !shown || !state.score;
  ui.togglePanel.setAttribute('aria-pressed', String(shown));
  try {
    localStorage.setItem(PANEL_KEY, shown ? 'shown' : 'hidden');
  } catch {
    // Without storage the setting lasts until the page is left.
  }
}

/** What the guides read from the score now. */
function scoreFacts(editor: Editor): ScoreFacts {
  return { anchors: editor.anchors(), staves: editor.staves(), boxes: itemBoxes(state.rust, state.score?.itemCount() ?? 0) };
}

/** How near (page units) a guide pulls. */
function snapTolerance(): number {
  return view.unitsPerCss(touchScreen() ? TOUCH_SNAP_PX : SNAP_PX);
}

/** The handle of the selected item under a client position. */
function handleAt(clientX: number, clientY: number, finger = false): Handle | null {
  if (!state.handles || state.editor?.prompt() != null || toolbar.tool) return null;
  const radius = (finger || touchScreen() ? TOUCH_HANDLE_PX : HANDLE_PX) * dpr();
  return handleUnder(state.handles, view.transform(), dpr(), view.deviceAt(clientX, clientY), radius);
}

/** The primary item's place while it moves: P3 and P4. */
function moveReadout(): string {
  const index = primary();
  const info = index === null ? undefined : state.score?.item(index);
  if (!info) return '';
  const [, , p3 = 0, p4 = 0] = info.params;
  info.free();
  const shown = (v: number) => formatParam(Math.round(v * 100) / 100);
  return `P3 ${shown(p3)} · P4 ${shown(p4)}`;
}

/** The axes along which guides may pull a handle: those it moves on, unless its frame is turned. */
function handleAxes(h: Handle): { x: boolean; y: boolean } {
  if (!h.follows) return { x: false, y: false };
  if (h.axis === 'both') return { x: true, y: true };
  const square = Math.abs(h.turn % 360) < 1e-6;
  return { x: square && h.axis === 'x', y: square && h.axis === 'y' };
}

function beginHandle(index: number, clientX: number, clientY: number): boolean {
  const set = state.handles;
  const editor = state.editor;
  const h = set?.handles[index];
  if (!set || !editor || !h) return false;
  const at = view.pageAt(clientX, clientY);
  try {
    if (!editor.handleBegin(set.item, index, at)) return false;
  } catch (err) {
    failed(err);
    return false;
  }
  const facts = scoreFacts(editor);
  const code = codeOf(facts, set.item);
  const others = set.handles.filter((o) => o.kind === 'end' && o !== h).map((o) => o.at);
  const span = { x0: h.at.x, x1: h.at.x, y0: h.at.y, y1: h.at.y };
  const wants = wantsForHandle(code, h.kind, h.label, others, h.at.y);
  const field = buildField(facts, { item: set.item, moving: new Set([set.item]), span }, wants, view.visibleBox());
  const point = (value: number) => [{ value, kind: 'point' as const }];
  state.drag = { handle: h, from: at, field, probes: { x: point(h.at.x), y: point(h.at.y) }, span, axes: handleAxes(h), guides: [], readout: h.label, at: h.at, cursor: at };
  state.hover = null;
  redraw(true);
  return true;
}

/** Snaps the travel from the drag's grab to page point `to` onto its guides, unless `free`. */
function snapped(drag: Drag, to: Point, free: boolean): Point {
  let travel = { x: to.x - drag.from.x, y: to.y - drag.from.y };
  drag.guides = [];
  if (!free) {
    const pulled = snap(drag.field, drag.probes, travel, snapTolerance(), drag.axes, drag.span);
    travel = pulled.travel;
    drag.guides = pulled.guides;
  }
  drag.cursor = to;
  return travel;
}

function dragHandle(clientX: number, clientY: number, constrain: boolean, free: boolean) {
  const drag = state.drag;
  const editor = state.editor;
  if (!drag?.handle || !editor) return;
  const travel = snapped(drag, view.pageAt(clientX, clientY), free);
  drag.readout = editor.handleTo({ x: drag.from.x + travel.x, y: drag.from.y + travel.y }, constrain, snapTolerance());
  drag.at = { x: drag.handle.at.x + travel.x, y: drag.handle.at.y + travel.y };
  edited(null, true);
}

function endHandle(commit: boolean) {
  const editor = state.editor;
  state.drag = null;
  if (editor) edit((ed) => ed.handleEnd(commit));
}

function beginMove(at: Point) {
  const editor = state.editor;
  const item = primary();
  if (!editor || item === null) return;
  const facts = scoreFacts(editor);
  const items = selection();
  const span = items.map((i) => facts.boxes[i] ?? null).reduce(union, null);
  if (!span) return;
  const code = codeOf(facts, item);
  const field = buildField(facts, { item, moving: new Set(items), span }, wantsForMove(code), view.visibleBox());
  const vertical = code !== 8 && code !== 14;
  state.drag = { handle: null, from: at, field, probes: moveProbes(facts, item, span), span, axes: { x: true, y: vertical }, guides: [], readout: '', at, cursor: at };
}

function moveTo(at: Point, free: boolean): Point {
  const drag = state.drag;
  if (!drag || drag.handle) return at;
  const travel = snapped(drag, at, free);
  return { x: drag.from.x + travel.x, y: drag.from.y + travel.y };
}

let described: { list: DisplayList; items: string; box: Box | null } | null = null;

/** The box around the selected items, worked out once per rendering and selection. */
function selectionBox(): Box | null {
  const items = selection();
  const key = items.join(',');
  if (described?.list !== state.rust || described.items !== key) {
    const wanted = new Set(items);
    const mine = (source: number | null) => source !== null && wanted.has(source);
    const box = bounds({ shapes: state.rust.shapes.filter((s) => mine(s.source)), texts: state.rust.texts.filter((r) => mine(r.source)) });
    described = { list: state.rust, items: key, box };
  }
  return described.box;
}

/**
 * Where the selection and its handles are on the screen, as data attributes
 * of the page (client pixels): `data-selection` its box, `data-handles` the
 * handles with their kind and label, `data-guides` the guides of a drag in
 * progress. For tests and the browser's inspector.
 */
function describeSelection() {
  const box = selectionBox();
  const rect = box ? view.clientRect(box) : null;
  ui.viewport.dataset.selection = rect ? JSON.stringify({ x: rect.x, y: rect.y, width: rect.width, height: rect.height }) : '';
  const set = state.handles;
  const t = view.transform();
  const shown = set ? visibleHandles(set, t, dpr()) : [];
  const origin = ui.viewport.getBoundingClientRect();
  ui.viewport.dataset.handles = JSON.stringify(
    shown.map((h) => {
      const p = devicePoint(h, t, dpr());
      return { kind: h.kind, label: h.label, x: origin.left + p.x / dpr(), y: origin.top + p.y / dpr() };
    }),
  );
  ui.viewport.dataset.guides = JSON.stringify(state.drag?.guides.map((g) => ({ axis: g.axis, label: g.label ?? null, music: g.music })) ?? []);
}

/** Over a handle the cursor says what it does and the handle names itself. */
function hover(clientX: number, clientY: number) {
  const h = handleAt(clientX, clientY);
  const index = h?.index ?? null;
  ui.viewport.style.cursor = h && state.handles ? cursorFor(h, state.handles) : '';
  if (index === state.hover) return;
  state.hover = index;
  view.repaint();
}

/** The item under the pointer: a drawn outline, else the nearest reference point. */
function itemAt(clientX: number, clientY: number, coarse = false): number | null {
  const p = view.pageAt(clientX, clientY);
  const drawn = state.score?.itemAt(p.x, p.y, view.unitsPerCss(coarse ? TOUCH_TOLERANCE_PX : CLICK_TOLERANCE_PX), 0);
  return drawn ?? state.score?.itemAt(p.x, p.y, 0, view.unitsPerCss(coarse ? TOUCH_PICK_RADIUS_PX : PICK_RADIUS_PX)) ?? null;
}

// ---------------------------------------------------------------------------
// Insertion modes

/** A staff's lines as score-web gives them (page units): its ends, level 0, one scale step, the lowest line's level and the number of lines. */
interface StaffLines {
  left: number;
  right: number;
  y0: number;
  step: number;
  lowest: number;
  lines: number;
}

/** A normal staff's scale step, for a staff not made yet. */
const NORMAL_STEP = 175;
/** A clef's own P3 at the start of the line: clefs at or before it are in force from the start. */
const CLEF_CODE = 3;

let layoutKnown: { list: DisplayList; staves: Map<number, StaffLines>; clefs: Map<number, { p3: number; index: number }[]> } | null = null;

/** The staves' lines and the clefs on them, read once per rendering. */
function scoreLayout() {
  if (layoutKnown?.list === state.rust) return layoutKnown;
  const staves = new Map<number, StaffLines>();
  const numbers = state.editor?.staves() ?? new Float32Array();
  for (let i = 0; i + 7 <= numbers.length; i += 7) {
    const [number = 0, left = 0, right = 0, y0 = 0, step = NORMAL_STEP, lowest = 3, lines = 5] = numbers.subarray(i, i + 7);
    staves.set(number, { left, right, y0, step, lowest: Math.round(lowest), lines });
  }
  const clefs = new Map<number, { p3: number; index: number }[]>();
  if (state.score) {
    for (const { code, staff, p3, index } of itemSummaries(state.score)) {
      if (code !== CLEF_CODE) continue;
      clefs.set(staff, [...(clefs.get(staff) ?? []), { p3, index }].sort((a, b) => a.p3 - b.p3));
    }
  }
  layoutKnown = { list: state.rust, staves, clefs };
  return layoutKnown;
}

/** Page y of scale step `level` on a staff. */
function levelY(staff: number, level: number): number {
  const lines = scoreLayout().staves.get(staff);
  return lines ? lines.y0 + level * lines.step : 0;
}

/** The scale step of page height `y` on a staff, which need not be the nearest one. */
function levelOn(staff: number, y: number): number {
  const lines = scoreLayout().staves.get(staff);
  return lines ? Math.round((y - lines.y0) / lines.step) : 0;
}

/** The levels of a staff's bottom and top lines. */
function outerLines(staff: number): [number, number] {
  const lines = scoreLayout().staves.get(staff);
  return lines ? [lines.lowest, lines.lowest + 2 * (lines.lines - 1)] : [3, 11];
}

/** What an insertion mode reads of the score. */
const facts: Facts = {
  creation(word) {
    const params = creationParams(word);
    return params ? Array.from(params) : null;
  },
  clefAt(staff, p3) {
    const found = (scoreLayout().clefs.get(staff) ?? []).filter((c) => c.p3 <= p3 + 0.5).at(-1);
    const info = found ? state.score?.item(found.index) : undefined;
    if (!info) return null;
    const params = info.params;
    info.free();
    return { p4: params[3] ?? 0, p5: params[4] ?? 0 };
  },
  middle(staff) {
    const [bottom, top] = outerLines(staff);
    return (bottom + top) / 2;
  },
};

const tools = createTools();
const fonts = tools.find((t) => t.id === 'text')?.groups.find((g) => g.id === 'font');
if (fonts) fonts.options = [{ value: '-1', label: 'Default font' }, ...fontCodes().map((f) => ({ value: String(f.code), label: `${fontPrefix(f.code)} ${f.name}` }))];

/** The pointer over the page (client), for the preview when the mode or an option changes. */
let pointer: Client | null = null;
let interaction: { busy(): boolean } | null = null;

const toolbar = createToolbar(ui.palette, ui.toolOptions, tools, {
  ready: () => state.score !== null,
  busy: () => interaction?.busy() ?? false,
  changed(tool) {
    ui.viewport.classList.toggle('inserting', tool !== null);
    ui.viewport.dataset.tool = tool?.id ?? '';
    ui.viewport.style.cursor = '';
    state.hover = null;
    showPreview(pointer, null);
    redraw();
  },
  optionChanged: () => showPreview(pointer, null),
  async choose() {
    const symbol = await symbolDialog.choose();
    return symbol === null ? null : { value: String(symbol), label: `${symbol} ${symbolName(symbol) ?? ''}`.trim() };
  },
  done: () => ui.viewport.focus(),
});

/** The ledger lines a note at `level` needs on a staff, as page y. */
function ledgersAt(staff: number, level: number): number[] {
  const [bottom, top] = outerLines(staff);
  const ys: number[] = [];
  for (let l = bottom - 2; l >= level; l -= 2) ys.push(levelY(staff, l));
  for (let l = top + 2; l <= level; l += 2) ys.push(levelY(staff, l));
  return ys;
}

/** What the preview draws for `tool` with the pointer at page point `at`, pressed at `from`. */
function sketchFor(tool: Tool, at: Point, from: Point | null): Sketch | null {
  const editor = state.editor;
  if (!editor) return null;
  const sketch = (more: Partial<Sketch> & Pick<Sketch, 'look' | 'from' | 'label'>): Sketch => ({ to: null, step: NORMAL_STEP, ledgers: [], lines: [], x0: 0, x1: 0, cursor: at, ...more });
  if (tool.shape === 'staff') {
    const { staff, p4 } = editor.newStaffAt(at);
    const near = editor.placeAt(at);
    const like = near ? scoreLayout().staves.get(near.staff) : undefined;
    const lines = [-2, -1, 0, 1, 2].map((i) => at.y + 2 * i * NORMAL_STEP);
    return sketch({ look: 'staff', from: at, lines, x0: like?.left ?? 2000, x1: like?.right ?? 32000, label: tool.describe({ staff, p3: 0, p4 }, facts) });
  }
  const here = editor.placeAt(at);
  if (!here) return sketch({ look: 'mark', from: at, label: 'No staff here: add one first (F)' });
  const step = scoreLayout().staves.get(here.staff)?.step ?? NORMAL_STEP;
  const pressed = from ? editor.placeAt(from) : null;
  if (tool.shape === 'span') {
    const start = pressed ?? here;
    const startAt = { x: (pressed ? from! : at).x, y: levelY(start.staff, start.p4) };
    const end = pressed ? { x: at.x, y: levelY(start.staff, tool.level === 'both' ? levelOn(start.staff, at.y) : start.p4) } : null;
    return sketch({ look: tool.look(), from: startAt, to: end, step, label: tool.describe(start, facts) });
  }
  if (tool.shape === 'reach') {
    const start = pressed ?? here;
    const [low, high] = [Math.min(start.staff, here.staff), Math.max(start.staff, here.staff)];
    const x = (pressed ? from! : at).x;
    const label = `${tool.describe({ ...start, staff: low }, facts)}${high > low ? ` to ${high}` : ''}`;
    return sketch({ look: 'barline', from: { x, y: levelY(low, outerLines(low)[0]) }, to: { x, y: levelY(high, outerLines(high)[1]) }, step, label });
  }
  const level = tool.level === 'none' ? facts.middle(here.staff) : here.p4;
  const ledgers = tool.look() === 'head' ? ledgersAt(here.staff, here.p4) : [];
  return sketch({ look: tool.look(), from: { x: at.x, y: levelY(here.staff, level) }, step, ledgers, label: tool.describe(here, facts) });
}

/** The preview of the mode in force for the pointer at client point `at` (none: away), pressed at `from`. */
function showPreview(at: Client | null, from: Client | null) {
  const tool = toolbar.tool;
  if (!at || !tool || !state.score || state.editor?.prompt() != null) {
    preview.show(null);
    return;
  }
  preview.show(sketchFor(tool, view.pageAt(at.x, at.y), from ? view.pageAt(from.x, from.y) : null));
}

/** Puts the mode's new item on the page: pressed at client point `from`, released at `to`. */
function insert(from: Client, to: Client, dragged: boolean) {
  const tool = toolbar.tool;
  const editor = state.editor;
  if (!tool || !editor) return;
  const down = view.pageAt(from.x, from.y);
  const up = view.pageAt(to.x, to.y);
  state.lastPaper = up;
  let params: number[] | null;
  if (tool.shape === 'staff') {
    const { staff, p4 } = editor.newStaffAt(up);
    params = tool.make({ staff, p3: 0, p4 }, null, facts);
  } else {
    // A span starts where the button went down; anything else goes where it came up.
    const start = editor.placeAt(tool.shape === 'span' || tool.shape === 'reach' ? down : up);
    if (!start) {
      message('There is no staff to put it on: add one first (F, then click the paper)', true);
      return;
    }
    if (tool.shape === 'text') {
      void typeText(tool, start, to);
      return;
    }
    let end: Place | null = null;
    if (dragged && tool.shape === 'span') {
      const across = editor.placeAt(up);
      end = { staff: start.staff, p3: across?.p3 ?? start.p3, p4: tool.level === 'both' ? levelOn(start.staff, up.y) : start.p4 };
    } else if (dragged && tool.shape === 'reach') end = editor.placeAt(up);
    params = tool.make(start, end, facts);
  }
  if (!params) return;
  const made = params;
  const change = edit((ed) => ed.insertItem(made, `Insert ${tool.noun()}`));
  if (change?.label) {
    tool.placed?.();
    showPreview(to, null);
  }
}

/** The text mode: the characters typed where the page was clicked, as a text item there in the font chosen. */
async function typeText(tool: Tool, place: Place, at: Client) {
  preview.show(null);
  const typed = await editInPlace(ui.stage, new DOMRect(at.x, at.y - 18, 0, 22), '');
  ui.viewport.focus();
  if (!typed?.trim()) return;
  const font = Number(tool.groups.find((g) => g.id === 'font')?.value ?? -1);
  edit((editor) => editor.insertText(withFont(typed, font), [place.staff, place.p3, place.p4]));
}

function bindPointer() {
  interaction = bindInteraction(ui.viewport, ui.band, {
    editor: () => state.editor,
    itemAt,
    pageAt: (x, y) => view.pageAt(x, y),
    zoom: () => view.zoom,
    zoomAt: (zoom, at, clientX, clientY) => view.zoomAt(zoom, at, { clientX, clientY }),
    selected: selectionChanged,
    selectAll,
    edited,
    failed,
    command: runCommand,
    box(from, to) {
      edit((editor) => editor.drawBox(from, to));
      selectionChanged();
    },
    clickedPaper: (at) => (state.lastPaper = at),
    clicked: (at) => (state.pasteAt = at),
    open: (item) => void openItem(item),
    handleAt: (x, y, finger) => handleAt(x, y, finger)?.index ?? null,
    handleBegin: beginHandle,
    handleTo: dragHandle,
    handleEnd: endHandle,
    moveBegin: beginMove,
    moveTo,
    moveEnd: () => (state.drag = null),
    hover,
    inserting: () => toolbar.tool !== null && state.score !== null,
    insertPreview: showPreview,
    insert,
  });
  ui.viewport.addEventListener('pointerleave', () => {
    pointer = null;
    if (!interaction?.busy()) preview.show(null);
    if (state.hover === null) return;
    state.hover = null;
    view.repaint();
  });
  ui.viewport.addEventListener('pointermove', (e) => {
    if (e.pointerType !== 'touch') pointer = { x: e.clientX, y: e.clientY };
    const p = view.pageAt(e.clientX, e.clientY);
    ui.cursor.textContent = state.score ? `x ${Math.round(p.x)}  y ${Math.round(p.y)}  (${(p.x / 4000).toFixed(2)} in, ${(p.y / 4000).toFixed(2)} in)` : '';
  });
}

/**
 * Keeps the app in the part of the window an on-screen keyboard leaves
 * visible: iOS lays the page out under the keyboard rather than resizing it.
 * A page the reader zoomed into is left as it is.
 */
function followVisualViewport() {
  const visible = window.visualViewport;
  if (!visible) return;
  const fit = () => {
    const covered = Math.abs(visible.scale - 1) < 0.01 && visible.height < document.documentElement.clientHeight - 1;
    ui.app.style.top = covered ? `${visible.offsetTop}px` : '';
    ui.app.style.height = covered ? `${visible.height}px` : '';
  };
  visible.addEventListener('resize', fit);
  visible.addEventListener('scroll', fit);
}

function bindDrop() {
  const hint = (show: boolean) => (ui.dropHint.hidden = !show);
  window.addEventListener('dragover', (e) => {
    e.preventDefault();
    hint(true);
  });
  window.addEventListener('dragleave', (e) => {
    if (e.relatedTarget === null) hint(false);
  });
  window.addEventListener('drop', (e) => {
    e.preventDefault();
    hint(false);
    const file = e.dataTransfer?.files[0];
    if (file) void mayDiscard().then(async (discard) => {
      if (discard) await openFile(file);
    });
  });
}

/** Gives the keyboard back to the page when an action left it nowhere in particular. */
function settleFocus() {
  const active = document.activeElement;
  if (!active || active === document.body || ui.app.querySelector('.appbar')!.contains(active)) ui.viewport.focus();
}

/** The editor's commands, as menus of entries: the `?` dialog lists them. */
let menus: Menu[] = [];

function bindMenus() {
  menus = appMenus({
    hasScore: () => state.score !== null,
    hasSelection: () => selection().length > 0,
    run: runCommand,
    runArea,
    supported: commandSupported,
    openDialog: (kind) => void openDialog(kind),
    newScore: () => void newScore(),
    open: () => void chooseFile(),
    samples: () => samples.map((s) => ({ title: s.title, open: () => void openSample(s) })),
    save: () => void save(),
    saveAs: desktop ? () => void save(true) : undefined,
    desktop: desktop !== null,
    exportSvg: () => void exportSvg(),
    print: () => void print(),
    undo: () => edit((editor) => editor.undo()),
    redo: () => edit((editor) => editor.redo()),
    cut: clipboard.cut,
    copy: clipboard.copy,
    paste: clipboard.paste,
    canPaste: () => clipboard.full,
    duplicate,
    selectAll,
    undoLabel: () => state.editor?.undoLabel() ?? null,
    redoLabel: () => state.editor?.redoLabel() ?? null,
    zoomIn: () => view.setZoom(stepZoom(view.zoom, 1)),
    zoomOut: () => view.setZoom(stepZoom(view.zoom, -1)),
    fitWidth: () => view.fitWidth(),
    actualSize: () => view.setZoom(100),
    panelShown: () => state.panel,
    togglePanel: () => setPanel(!state.panel),
    shortcuts: showShortcuts,
    tools: () => tools,
    tool: () => toolbar.tool?.id ?? null,
    chooseTool: (id) => toolbar.choose(id),
  });
}

/** The `?` dialog: every command of the menus as a button, as they are now, then keys and gestures. */
function showShortcuts() {
  if (ui.shortcuts.open) return;
  ui.commandList.replaceChildren(...menus.map(commandSection));
  ui.shortcuts.showModal();
  // Opened on its Close button, the dialog would start scrolled to the end on a small screen.
  ui.shortcuts.scrollTop = 0;
}

/** One menu's entries as buttons, which close the dialog and run them: a row of them as small ones after its name. */
function commandSection(menu: Menu): HTMLElement {
  const text = (className: string, textContent: string) => Object.assign(document.createElement('span'), { className, textContent });
  const button = (action: Action, small = false) => {
    const b = Object.assign(document.createElement('button'), { type: 'button', className: small ? 'command small' : 'command', title: action.title ?? '', disabled: !(action.enabled?.() ?? true) });
    if (action.id) b.dataset.action = action.id;
    if (action.checked) b.setAttribute('aria-pressed', String(action.checked()));
    b.append(text('command-label', labelOf(action)), ...(action.hint && !small ? [text('command-hint', action.hint)] : []));
    b.addEventListener('click', () => {
      ui.shortcuts.close();
      action.run();
      settleFocus();
    });
    return b;
  };
  const items = menu.entries().flatMap((entry): HTMLElement[] => {
    if (entry === 'separator') return [];
    if ('heading' in entry) return [text('command-heading', entry.heading)];
    if ('row' in entry) {
      const row = Object.assign(document.createElement('div'), { className: 'command-row' });
      row.append(text('command-row-label', entry.row), ...entry.actions.map((action) => button(action, true)));
      return [row];
    }
    return [button(entry)];
  });
  const section = document.createElement('section');
  section.append(Object.assign(document.createElement('h3'), { textContent: menu.label }), ...items);
  return section;
}

function bindStart() {
  ui.startNew.addEventListener('click', () => void newScore());
  ui.startOpen.addEventListener('click', () => void chooseFile());
  ui.startSamples.replaceChildren(
    ...samples.map((sample) => {
      const button = Object.assign(document.createElement('button'), { type: 'button', className: 'sample', textContent: sample.title });
      button.addEventListener('click', () => void openSample(sample));
      return button;
    }),
  );
  ui.startSamples.previousElementSibling!.toggleAttribute('hidden', samples.length === 0);
}

/** Shortcuts that act on the whole app: open, save, print, help. */
function onAppKey(e: KeyboardEvent) {
  if (document.querySelector('dialog[open]')) return;
  if (e.key === 'F1') {
    e.preventDefault();
    showShortcuts();
    return;
  }
  const command = e.metaKey || e.ctrlKey;
  if (!command || e.altKey) return;
  const action = { o: () => void chooseFile(), s: () => void save(), p: () => void print() }[e.key.toLowerCase()];
  if (!action || e.shiftKey) return;
  e.preventDefault();
  if (state.score || e.key.toLowerCase() === 'o') action();
}

function bindControls() {
  ui.file.addEventListener('change', () => {
    const file = ui.file.files?.[0];
    if (file) void openFile(file);
    ui.file.value = '';
  });
  ui.zoomIn.addEventListener('click', () => view.setZoom(stepZoom(view.zoom, 1)));
  ui.zoomOut.addEventListener('click', () => view.setZoom(stepZoom(view.zoom, -1)));
  ui.zoom.addEventListener('change', () => view.setZoom(Number(ui.zoom.value)));
  ui.fit.addEventListener('click', () => view.fitWidth());
  ui.undo.addEventListener('click', () => edit((editor) => editor.undo()));
  ui.redo.addEventListener('click', () => edit((editor) => editor.redo()));
  ui.togglePanel.addEventListener('click', () => setPanel(!state.panel));
  ui.help.addEventListener('click', showShortcuts);
  ui.app.querySelectorAll<HTMLButtonElement>('.appbar button').forEach((button) => button.addEventListener('click', settleFocus));
  if (MOD !== '⌘') ui.shortcuts.querySelectorAll('kbd.mod').forEach((k) => (k.textContent = 'Ctrl'));
  window.addEventListener('keydown', onAppKey);
  window.addEventListener('keydown', (e) => {
    if (e.target instanceof HTMLInputElement || e.metaKey || e.ctrlKey) return;
    if (e.key === '+' || e.key === '=') view.setZoom(stepZoom(view.zoom, 1));
    if (e.key === '_') view.setZoom(stepZoom(view.zoom, -1));
  });
  bindMenus();
  bindStart();
  bindPointer();
  bindDrop();
  bindPanelGrip(ui.panel, ui.panelGrip);
  followVisualViewport();
}

/** URL parameters for direct links and screenshots: sample (or new), zoom, select. Without one the start screen shows. */
async function applyQuery() {
  const query = new URLSearchParams(location.search);
  const wanted = query.get('sample');
  const sample = samples.find((s) => s.title === wanted || s.case === wanted);
  if (sample) await openSample(sample);
  else if (query.has('new')) await newScore();
  const zoom = Number(query.get('zoom'));
  if (zoom > 0 && state.score) view.setZoom(zoom);
  const selected = query.get('select');
  if (selected !== null && state.score) select(selected.split(',').map(Number), true);
  await loadFontsAndRepaint();
  ui.app.dataset.ready = 'true';
}

/** A failure that leaves the app unusable, shown over the page area. */
function fatal(title: string, err: unknown) {
  const box = document.createElement('div');
  box.className = 'fatal';
  const heading = Object.assign(document.createElement('strong'), { textContent: title });
  const detail = Object.assign(document.createElement('p'), { textContent: String(err) });
  box.append(heading, detail);
  ui.stage.append(box);
  message(`${title}: ${String(err)}`, true);
}

async function loadSamples(): Promise<Sample[]> {
  try {
    return (await (await fetch('samples/index.json')).json()) as Sample[];
  } catch (err) {
    message(`Samples are not available: ${String(err)}`, true);
    return [];
  }
}

// ---------------------------------------------------------------------------
// The desktop app

/** Whether the page has started, so files opened from outside can be taken. */
let started = false;

function textFocused(): boolean {
  const active = document.activeElement;
  return active instanceof HTMLInputElement || active instanceof HTMLTextAreaElement || (active instanceof HTMLElement && active.isContentEditable);
}

/** The file the system asked the desktop app to open last (Finder, a drop), unless unsaved changes are to stay. */
async function takeOpened() {
  if (!desktop || !started) return;
  const path = (await desktop.openedFiles()).at(-1);
  if (path && (await mayDiscard())) await openPath(path);
}

/** The menu bar's commands, files opened from outside and closing, in the desktop app. */
function bindDesktop(app: NonNullable<typeof desktop>) {
  document.title = 'WinScore';
  ui.start.querySelector('h1')!.textContent = 'WinScore';
  ui.start.querySelector('h1 + p')!.textContent = "Leland Smith's SCORE: open, engrave and save .mus files.";
  const zoom = (step: 1 | -1) => state.score && view.setZoom(stepZoom(view.zoom, step));
  const commands: Record<string, () => void> = {
    new: () => void newScore(),
    open: () => void chooseFile(),
    save: () => void save(),
    'save-as': () => void save(true),
    'export-svg': () => void exportSvg(),
    print: () => void print(),
    // In a text field Undo and Redo are its own.
    undo: () => (textFocused() ? document.execCommand('undo') : edit((editor) => editor.undo())),
    redo: () => (textFocused() ? document.execCommand('redo') : edit((editor) => editor.redo())),
    duplicate: () => !textFocused() && duplicate(),
    delete: () => !textFocused() && selection().length > 0 && edit((editor) => editor.deleteSelection()),
    'zoom-in': () => zoom(1),
    'zoom-out': () => zoom(-1),
    'actual-size': () => state.score && view.setZoom(100),
    fit: () => state.score && view.fitWidth(),
    panel: () => state.score && setPanel(!state.panel),
    shortcuts: showShortcuts,
  };
  app.onMenu((id) => {
    const modal = document.querySelector('dialog[open]');
    if (modal && id !== 'undo' && id !== 'redo') return;
    commands[id]?.();
    if (!modal) settleFocus();
  });
  app.onOpened(() => void takeOpened());
  app.onDragging((over) => (ui.dropHint.hidden = !over));
  app.onCloseRequested(() => void mayDiscard().then((close) => close && app.close()));
  app.ready();
}

async function main() {
  if (desktop) bindDesktop(desktop);
  try {
    await init();
  } catch (err) {
    fatal('The WebAssembly module could not be loaded, so scores cannot be opened. The browser or the hosting page may block WebAssembly.', err);
    return;
  }
  showZoom(view.zoom);
  samples = await loadSamples();
  setPanel(state.panel);
  bindControls();
  refreshStatus();
  renderSelection(ui.item, [], handlers, false);
  // For tests and the browser's console: items selected by number, as the panel numbers them.
  Object.assign(window, { winscore: { select: (items: number[]) => select(items, true) } });
  await applyQuery();
  started = true;
  await takeOpened();
}

main().catch((err) => fatal('The app failed to start.', err));
