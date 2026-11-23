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
import { createMcpServer, type McpHost } from './mcp';
import { byName, createPageBar, folderOf, listed, nextName } from './pages';
import { paint, type Layer, type Overlay } from './paint';
import { createPreview, type Sketch } from './preview';
import { download, printPages } from './print';
import { createQuestion } from './question';
import { embedFonts } from './svg-fonts';
import { createSymbolDialog } from './symbol-dialog';
import { createTextDialog, editInPlace, withFont } from './text-dialog';
import { createToolbar } from './toolbar';
import { createTools, type Facts, type Tool } from './tools';
import { cssPerUnit, stepZoom, toDevice, ZOOM_LEVELS } from './view';

interface Sample {
  title: string;
  /** The `.mus` bytes as base64 text. */
  url: string;
  case: string;
}

/** One page of the score: a .mus file of its own (pages.ts). */
interface Page {
  score: Score;
  editor: Editor;
  fileName: string;
  /** Where the page's file is on disk, in the desktop app; null for a new page or a sample. */
  path: string | null;
  modified: boolean;
  /** Where the view was when another page was shown: the zoom and the scroll offsets. */
  view: { zoom: number; left: number; top: number } | null;
}

interface State {
  /** The open pages in their order; the window shows and edits one of them. */
  pages: Page[];
  /** The index of the page shown. */
  current: number;
  /** The page shown, and its score and editor; null while no score is open. */
  readonly page: Page | null;
  readonly score: Score | null;
  readonly editor: Editor | null;
  /** The display list of the page shown. */
  rust: DisplayList;
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
  pagebar: $<HTMLElement>('pagebar'),
  pageTabs: $<HTMLDivElement>('page-tabs'),
  doc: $<HTMLSpanElement>('doc'),
  docState: $<HTMLSpanElement>('doc-state'),
  undo: $<HTMLButtonElement>('undo'),
  redo: $<HTMLButtonElement>('redo'),
  symbolDialog: $<HTMLDialogElement>('symbol-dialog'),
  mcpDialog: $<HTMLDialogElement>('mcp-dialog'),
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
  pages: [],
  current: 0,
  get page() {
    return this.pages[this.current] ?? null;
  },
  get score() {
    return this.page?.score ?? null;
  },
  get editor() {
    return this.page?.editor ?? null;
  },
  rust: EMPTY,
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
/** The tabs of the open pages, in the app bar after undo and redo while there are several. */
const pageBar = createPageBar(ui.pagebar, ui.pageTabs, {
  show: (index) => {
    goToPage(index);
    ui.viewport.focus();
  },
  close: (index) => void closePage(index),
  newPage: () => {
    newPage();
    ui.viewport.focus();
  },
  addPages: () => void chooseFiles(true),
});
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
  const page = state.page;
  const open = page !== null;
  const name = page?.fileName ?? '';
  const modified = page?.modified ?? false;
  const of = state.pages.length > 1 ? ` (page ${state.current + 1} of ${state.pages.length})` : '';
  const title = open ? `${name}${of}${modified ? ' — Edited' : ''}` : 'WinScore';
  if (desktop && title !== shownTitle) desktop.setTitle(title);
  shownTitle = title;
  ui.doc.hidden = !open;
  ui.status.textContent = name;
  ui.docState.textContent = modified ? 'Unsaved changes' : '';
  ui.doc.title = modified ? `${name}: changed since it was opened or saved` : name;
  pageBar.render(
    state.pages.map((p) => ({ name: p.fileName, path: p.path, modified: p.modified })),
    state.current,
  );
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
  ui.app.dataset.pages = String(state.pages.length);
  ui.app.dataset.open = String(open);
  ui.app.dataset.page = open ? String(state.current + 1) : '';
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
    if (state.page && change !== null) state.page.modified = true;
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

/** Asks before changes to `pages` (default all of them) that were not saved are thrown away. */
async function mayDiscard(pages: Page[] = state.pages): Promise<boolean> {
  const unsaved = pages.filter((page) => page.modified).map((page) => page.fileName);
  if (unsaved.length === 0) return true;
  const question = `Discard the unsaved changes to ${listed(unsaved)}?`;
  return desktop ? desktop.confirm(question, 'Discard') : window.confirm(question);
}

function makePage(score: Score, fileName: string, path: string | null = null): Page {
  return { score, editor: scoreEditor(score), fileName, path, modified: false, view: null };
}

/** Whether a drag, a box or an insertion is under way, which a change of page must not cut into. */
function busy(): boolean {
  return state.drag !== null || (interaction?.busy() ?? false);
}

/** Keeps where the view is on the page shown, for when it is shown again. */
function rememberView() {
  if (state.page) state.page.view = { zoom: view.zoom, left: ui.viewport.scrollLeft, top: ui.viewport.scrollTop };
}

/** Shows page `index` and edits it: the view as it was there, else the top of the page (`fit`: at the window's width). */
function showPage(index: number, fit = false) {
  const page = state.pages[index];
  if (!page) return;
  preview.show(null);
  state.current = index;
  state.rust = decodeAndFree(page.score.render());
  state.lastPaper = null;
  state.pasteAt = null;
  state.hover = null;
  state.drag = null;
  state.extent = null;
  refreshHandles();
  refreshPanel();
  redraw();
  if (fit) view.fitWidth();
  if (!fit && page.view && Math.abs(page.view.zoom - view.zoom) < 0.01) {
    ui.viewport.scrollLeft = page.view.left;
    ui.viewport.scrollTop = page.view.top;
  } else {
    const content = bounds(state.rust);
    if (content) view.scrollToTop(content.y1 + MARGIN);
  }
  view.repaint();
  void loadFontsAndRepaint();
  report(null);
}

/** Changes to page `index`, unless something is being dragged. */
function goToPage(index: number) {
  if (index === state.current || !state.pages[index] || busy()) return;
  rememberView();
  showPage(index);
}

/** F2 and F3: the page before or after the one shown. */
function stepPage(step: 1 | -1) {
  const index = state.current + step;
  if (state.pages[index]) goToPage(index);
  else if (state.pages.length > 0) message(step < 0 ? 'This is the first page' : 'This is the last page');
}

/** Puts `pages` in the window and shows the first: in place of the pages open, or (`add`) after the one shown. */
function openPages(pages: Page[], add = false) {
  if (pages.length === 0) return;
  if (add && state.pages.length > 0) {
    rememberView();
    const at = state.current + 1;
    state.pages.splice(at, 0, ...pages);
    showPage(at);
    return;
  }
  const closed = state.pages;
  state.pages = pages;
  closed.forEach((page) => page.score.free());
  showPage(0, true);
}

/** One page, the score of `score`, in place of the pages open. */
function openScore(score: Score, name: string) {
  openPages([makePage(score, name)]);
}

/** Closes page `index` (default the one shown), asking about its unsaved changes; the last page closed leaves the start screen. */
async function closePage(index = state.current): Promise<boolean> {
  const page = state.pages[index];
  if (!page || busy() || !(await mayDiscard([page]))) return false;
  removePage(page);
  return true;
}

/** Takes `page` out of the window without asking. */
function removePage(page: Page) {
  const at = state.pages.indexOf(page);
  if (at < 0) return;
  const shown = state.page;
  if (shown !== page) rememberView();
  state.pages.splice(at, 1);
  page.score.free();
  if (state.pages.length === 0) {
    closeAll();
    return;
  }
  showPage(shown === page ? Math.min(at, state.pages.length - 1) : state.pages.indexOf(shown!));
}

/** No score open: the start screen. */
function closeAll() {
  preview.show(null);
  state.pages.forEach((page) => page.score.free());
  state.pages = [];
  state.current = 0;
  state.rust = EMPTY;
  state.handles = null;
  state.hover = null;
  state.drag = null;
  refreshPanel();
  redraw();
  report(null);
}

async function newScore() {
  if (!(await mayDiscard())) return;
  openScore(Score.empty(), 'untitled.mus');
}

/** An empty page after the one shown, named by the next number (sonata01.mus → sonata02.mus); a new score when none is open. */
function newPage() {
  const page = state.page;
  if (!page) {
    void newScore();
    return;
  }
  if (busy()) return;
  const name = nextName(page.fileName || 'untitled.mus', state.pages.map((p) => p.fileName));
  openPages([makePage(page.score.blank(), name)], true);
  message(`New page ${name}: it is saved as a file of its own`);
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

/** Whether the browser's file chooser adds pages to the score open rather than opening files in its place. */
let chooserAdds = false;

/** Open… asks for .mus files (several chosen together are the pages of one score) to open in place of the pages open; `add` (Add pages…) puts them after the page shown. */
async function chooseFiles(add = false) {
  const adding = add && state.page !== null;
  if (!adding && !(await mayDiscard())) return;
  if (!desktop) {
    chooserAdds = adding;
    ui.file.click();
    return;
  }
  const paths = await desktop.pickOpen(folderOf(state.page?.path ?? null));
  if (paths.length > 0) await openPaths(paths, adding);
}

/** What could not be opened, in the status line. */
function cannotOpen(failures: string[]) {
  if (failures.length > 0) message(`Cannot open ${failures.join('; ')}`, true);
}

/** Opens `files` as pages, in the order of their names: in place of the pages open, or (`add`) after the page shown. */
async function openFiles(files: File[], add = false) {
  const pages: Page[] = [];
  const failures: string[] = [];
  for (const file of [...files].sort((a, b) => byName(a.name, b.name))) {
    try {
      pages.push(makePage(new Score(new Uint8Array(await file.arrayBuffer())), file.name));
    } catch (err) {
      failures.push(`${file.name}: ${String(err)}`);
    }
  }
  openPages(pages, add);
  if (pages.length > 1) message(`Opened ${pages.length} pages`);
  cannotOpen(failures);
}

/** The desktop app: the files at `paths` as pages in the order of their names, as `openFiles` puts them; a file open already is shown. How many were opened; a failure is thrown. */
async function readPaths(paths: string[], add = false): Promise<number> {
  if (!desktop) throw new Error('Files are opened by path only in the desktop app');
  const open = add ? new Map(state.pages.map((page) => [page.path, page])) : new Map<string | null, Page>();
  const wanted = [...new Set(paths)].sort((a, b) => byName(baseName(a), baseName(b)));
  const pages: Page[] = [];
  const failures: string[] = [];
  for (const path of wanted.filter((p) => !open.has(p))) {
    try {
      pages.push(makePage(new Score(await desktop.read(path)), baseName(path), path));
    } catch (err) {
      failures.push(`${baseName(path)}: ${String(err)}`);
    }
  }
  if (pages.length > 0) openPages(pages, add);
  else if (open.has(wanted[0]!)) goToPage(state.pages.indexOf(open.get(wanted[0]!)!));
  if (failures.length > 0) throw new Error(failures.join('; '));
  return pages.length;
}

/** The desktop app: the files at `paths`, which Save then writes; what fails is said in the status line. */
async function openPaths(paths: string[], add = false) {
  try {
    const opened = await readPaths(paths, add);
    if (opened > 1) message(`Opened ${opened} pages`);
  } catch (err) {
    message(`Cannot open ${err instanceof Error ? err.message : String(err)}`, true);
  }
}

/** The desktop app: writes `page` to `path`, which becomes its file. */
async function writePage(page: Page, path: string) {
  if (!desktop) throw new Error('No file to save to');
  await desktop.write(path, page.score.save() as Uint8Array<ArrayBuffer>);
  page.path = path;
  page.fileName = baseName(path);
  page.modified = false;
  refreshStatus();
}

/** Where a page without a file is saved first: the folder of the page shown or of another page with a file. */
function folderFor(page: Page): string | null {
  return folderOf(page.path ?? state.page?.path ?? state.pages.find((p) => p.path)?.path ?? null);
}

/** Saves `page`: in a browser as a download, in the desktop app to its file (`as`, or without one: where the save panel says). The path written (a name in a browser), or null. */
async function savePage(page: Page, as = false): Promise<string | null> {
  const bytes = page.score.save() as Uint8Array<ArrayBuffer>;
  if (!desktop) {
    download(bytes, page.fileName || 'score.mus', 'application/octet-stream');
    page.modified = false;
    refreshStatus();
    return page.fileName;
  }
  const path = !as && page.path ? page.path : await desktop.pickSave(page.fileName || 'untitled.mus', 'mus', 'SCORE file', folderFor(page));
  if (!path) return null;
  await writePage(page, path);
  return path;
}

/** Saves the page shown (Save, Save As). */
async function save(as = false) {
  const page = state.page;
  if (!page) return;
  try {
    const written = await savePage(page, as);
    if (written && desktop) message(`Saved ${written}`);
  } catch (err) {
    failed(err);
  }
}

/** Browsers drop downloads that start together: the pages go one after another. */
const DOWNLOAD_GAP_MS = 300;

/** Save all: every page with unsaved changes, each to its file (a page without one where the save panel says; Cancel stops), or as downloads. */
async function saveAll() {
  const unsaved = state.pages.filter((page) => page.modified);
  if (unsaved.length === 0) {
    message(state.pages.length > 1 ? 'Every page is saved' : 'The score is saved');
    return;
  }
  const saved: string[] = [];
  try {
    for (const page of unsaved) {
      if (!state.pages.includes(page)) continue;
      if (!desktop && saved.length > 0) await new Promise((done) => setTimeout(done, DOWNLOAD_GAP_MS));
      const written = await savePage(page);
      if (!written) break;
      saved.push(baseName(written));
    }
  } catch (err) {
    failed(err);
    return;
  }
  const left = state.pages.filter((page) => page.modified).length;
  message(`Saved ${saved.length ? listed(saved) : 'nothing'}${left ? `; ${left} ${left === 1 ? 'page has' : 'pages have'} unsaved changes still` : ''}`, left > 0);
}

/** The page's file name with another extension. */
function exportName(extension: string): string {
  return `${(state.page?.fileName || 'score').replace(/\.[^.]*$/, '')}.${extension}`;
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
    const path = await desktop.pickSave(exportName('svg'), 'svg', 'SVG image', folderFor(state.page!));
    if (path) {
      await desktop.write(path, new TextEncoder().encode(svg));
      message(`Exported ${path}`);
    }
  } catch (err) {
    failed(err);
  }
}

/** Prints every page, in their order, on paper of the page shown's size. */
async function print() {
  if (!state.score) return;
  try {
    await printPages(
      state.pages.map((page) => page.score.exportSvg()),
      paperBox(),
    );
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
    // Files dropped on an open score are pages added to it; without one, they are opened.
    const files = [...(e.dataTransfer?.files ?? [])].filter((file) => /\.mus$/i.test(file.name));
    if (files.length > 0) void openFiles(files, state.page !== null);
    else if ((e.dataTransfer?.files.length ?? 0) > 0) message('Only .mus files can be opened', true);
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
    open: () => void chooseFiles(),
    samples: () => samples.map((s) => ({ title: s.title, open: () => void openSample(s) })),
    save: () => void save(),
    saveAs: desktop ? () => void save(true) : undefined,
    saveAll: () => void saveAll(),
    pages: () => state.pages.map((page, index) => ({ name: page.fileName, modified: page.modified, current: index === state.current, show: () => goToPage(index) })),
    newPage,
    addPages: () => void chooseFiles(true),
    closePage: () => void closePage(),
    stepPage,
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
    mcp: desktop ? () => void showMcp(desktop!) : undefined,
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
  ui.startOpen.addEventListener('click', () => void chooseFiles());
  ui.startSamples.replaceChildren(
    ...samples.map((sample) => {
      const button = Object.assign(document.createElement('button'), { type: 'button', className: 'sample', textContent: sample.title });
      button.addEventListener('click', () => void openSample(sample));
      return button;
    }),
  );
  ui.startSamples.parentElement!.toggleAttribute('hidden', samples.length === 0);
}

/** Shortcuts that act on the whole app: open, save, print, help, the pages. */
function onAppKey(e: KeyboardEvent) {
  if (document.querySelector('dialog[open]')) return;
  if (e.key === 'F1') {
    e.preventDefault();
    showShortcuts();
    return;
  }
  // SCORE's NB and NX: the previous and the next page (not while a text is typed, which belongs to the page shown).
  if ((e.key === 'F2' || e.key === 'F3') && !e.metaKey && !e.ctrlKey && !e.altKey && !textFocused()) {
    e.preventDefault();
    stepPage(e.key === 'F2' ? -1 : 1);
    return;
  }
  const command = e.metaKey || e.ctrlKey;
  if (!command) return;
  if (e.altKey && !e.shiftKey && e.code === 'KeyS') {
    e.preventDefault();
    if (state.score) void saveAll();
    return;
  }
  if (e.altKey) return;
  const action = { o: () => void chooseFiles(), s: () => void save(), p: () => void print() }[e.key.toLowerCase()];
  if (!action || e.shiftKey) return;
  e.preventDefault();
  if (state.score || e.key.toLowerCase() === 'o') action();
}

function bindControls() {
  ui.file.addEventListener('change', () => {
    const files = [...(ui.file.files ?? [])];
    if (files.length > 0) void openFiles(files, chooserAdds);
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
// Assistants through MCP (mcp.ts), in the desktop app

/** The largest side of an image `render_page` makes, in pixels. */
const MAX_RENDER_PX = 4000;
/** Above and below the staves an image of some of them shows, in engine units (half an inch). */
const RENDER_MARGIN = 2000;

/** The staves with their bottom and top lines' heights on the page. */
function staffLines() {
  return [...scoreLayout().staves]
    .map(([number, s]) => ({ number, lines: s.lines, bottom: s.y0 + s.lowest * s.step, top: s.y0 + (s.lowest + 2 * (s.lines - 1)) * s.step }))
    .sort((a, b) => a.number - b.number);
}

/** The page, or staves `staves` of it, drawn as the window draws it, as a PNG (base64). */
async function renderPng(zoom: number, staves: [number, number] | null, withSelection: boolean) {
  await loadFaces(state.rust.texts);
  const paper = paperBox();
  let box = paper;
  if (staves) {
    const [low, high] = [Math.min(...staves), Math.max(...staves)];
    const shown = staffLines().filter((s) => s.number >= low && s.number <= high);
    if (shown.length === 0) throw new Error(`There are no staves from ${low} to ${high}`);
    const bottom = Math.min(...shown.map((s) => s.bottom));
    const top = Math.max(...shown.map((s) => s.top));
    box = { ...paper, y0: Math.max(paper.y0, bottom - RENDER_MARGIN), y1: Math.min(paper.y1, top + RENDER_MARGIN) };
  }
  let k = cssPerUnit(zoom);
  k = Math.min(k, MAX_RENDER_PX / (box.x1 - box.x0), MAX_RENDER_PX / (box.y1 - box.y0));
  const canvas = document.createElement('canvas');
  canvas.width = Math.max(1, Math.round((box.x1 - box.x0) * k));
  canvas.height = Math.max(1, Math.round((box.y1 - box.y0) * k));
  const ctx = canvas.getContext('2d')!;
  const highlights = withSelection ? selection().map((item) => ({ list: state.rust, item })) : [];
  paint(ctx, { transform: { k, ox: -box.x0 * k, oy: box.y1 * k }, paper, layers: layers(), highlights });
  return { data: canvas.toDataURL('image/png').replace(/^data:image\/png;base64,/, ''), width: canvas.width, height: canvas.height };
}

const mcpHost: McpHost = {
  score: () => state.score,
  editor: () => state.editor,
  file: () => ({ name: state.page?.fileName ?? '', path: state.page?.path ?? null, modified: state.page?.modified ?? false }),
  pages: () => state.pages.map((page) => ({ name: page.fileName, path: page.path, modified: page.modified })),
  current: () => state.current,
  showPage: goToPage,
  closePage(index) {
    const page = state.pages[index];
    if (page) removePage(page);
  },
  busy,
  batch(label, action) {
    const { score, editor } = state;
    if (!score || !editor) throw new Error('No score is open');
    const mark = score.mark();
    try {
      action(editor, score);
    } catch (err) {
      score.rollback(mark);
      edited(null, false);
      throw err;
    }
    const step = score.combine(mark, label) ? label : null;
    edited(step ? { label: step, message: null } : null, false);
    revealSelection();
    return step;
  },
  select: (indices) => select(indices, true),
  undo: () => edit((editor) => editor.undo())?.label || null,
  redo: () => edit((editor) => editor.redo())?.label || null,
  facts,
  context(index) {
    const score = state.score;
    const info = score?.item(index);
    const code = info?.code;
    info?.free();
    return { clef: score && code === 1 ? clefAt(score, index) : null, symbolName };
  },
  nameOf,
  paramNames,
  staves: staffLines,
  paper() {
    const box = paperBox();
    return { width: box.x1 - box.x0, height: box.y1 - box.y0 };
  },
  render: renderPng,
  open: async (path, add) => void (await readPaths([path], add)),
  newScore: (add) => (add && state.page ? newPage() : openScore(Score.empty(), 'untitled.mus')),
  async save(path) {
    const page = state.page;
    const target = path ?? page?.path;
    if (!page || !target) throw new Error('The page has no file yet: give a path');
    await writePage(page, target);
    return target;
  },
  async saveAll() {
    const saved: string[] = [];
    const withoutFile: string[] = [];
    for (const page of state.pages.filter((p) => p.modified)) {
      if (page.path) {
        await writePage(page, page.path);
        saved.push(page.path);
      } else withoutFile.push(page.fileName);
    }
    return { saved, withoutFile };
  },
  async exportSvg(path) {
    if (!desktop || !state.score) throw new Error('No score to export');
    await desktop.write(path, new TextEncoder().encode(await embedFonts(state.score.exportSvg())));
  },
  notify: (text) => message(text),
  scripts: () => scriptsAllowed,
};

/** Whether assistants may run scripts in the page (run_script): the desktop app's setting, else allowed (tests). */
let scriptsAllowed = true;

/** Answers MCP messages: the desktop app's clients, and tests through `window.winscore.mcp`. */
const mcp = createMcpServer(mcpHost);

/** The MCP dialog: whether assistants may control the window, and how to connect them. */
async function showMcp(app: NonNullable<typeof desktop>) {
  const dialog = ui.mcpDialog;
  const enabled = dialog.querySelector<HTMLInputElement>('#mcp-enabled')!;
  const scripts = dialog.querySelector<HTMLInputElement>('#mcp-scripts')!;
  const fill = (status: Awaited<ReturnType<typeof app.mcpStatus>>) => {
    enabled.checked = status.enabled;
    scripts.checked = scriptsAllowed = status.scripts;
    scripts.disabled = !status.enabled;
    dialog.querySelector('#mcp-state')!.textContent = status.error
      ? `Not available: ${status.error}`
      : status.enabled
        ? `Listening at ${status.url}`
        : 'Off: assistants cannot reach WinScore.';
    dialog.querySelector<HTMLInputElement>('#mcp-http')!.value = `claude mcp add --transport http --scope user winscore ${status.url}`;
    dialog.querySelector<HTMLInputElement>('#mcp-stdio')!.value = `"${status.executable}" --mcp-stdio`;
  };
  fill(await app.mcpStatus());
  enabled.onchange = async () => fill(await app.setMcpEnabled(enabled.checked));
  scripts.onchange = async () => fill(await app.setMcpScripts(scripts.checked));
  dialog.querySelectorAll<HTMLButtonElement>('[data-copy]').forEach((button) => {
    button.onclick = () => {
      const field = dialog.querySelector<HTMLInputElement>(`#${button.dataset.copy}`)!;
      field.select();
      document.execCommand('copy');
      void navigator.clipboard?.writeText(field.value).catch(() => {});
      button.textContent = 'Copied';
      setTimeout(() => (button.textContent = 'Copy'), 1500);
    };
  });
  if (!dialog.open) dialog.showModal();
}

// ---------------------------------------------------------------------------
// The desktop app

/** Whether the page has started, so files opened from outside can be taken. */
let started = false;

function textFocused(): boolean {
  const active = document.activeElement;
  return active instanceof HTMLInputElement || active instanceof HTMLTextAreaElement || (active instanceof HTMLElement && active.isContentEditable);
}

/** The files the system asked the desktop app to open (Finder, a drop): pages added to the score open, else opened together. */
async function takeOpened() {
  if (!desktop || !started) return;
  const paths = await desktop.openedFiles();
  if (paths.length > 0) await openPaths(paths, state.page !== null);
}

/** The menu bar's commands, files opened from outside and closing, in the desktop app. */
function bindDesktop(app: NonNullable<typeof desktop>) {
  document.title = 'WinScore';
  ui.start.querySelector('h1')!.textContent = 'WinScore';
  ui.start.querySelector('h1 + p')!.textContent = "Leland Smith's SCORE";
  const zoom = (step: 1 | -1) => state.score && view.setZoom(stepZoom(view.zoom, step));
  const commands: Record<string, () => void> = {
    new: () => void newScore(),
    open: () => void chooseFiles(),
    'new-page': newPage,
    'add-pages': () => void chooseFiles(true),
    'close-page': () => void closePage(),
    'previous-page': () => !textFocused() && stepPage(-1),
    'next-page': () => !textFocused() && stepPage(1),
    save: () => void save(),
    'save-as': () => void save(true),
    'save-all': () => void saveAll(),
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
    mcp: () => void showMcp(app),
    'default-app': () =>
      void app.makeDefault().then(
        (said) => message(said),
        (err) => failed(err),
      ),
  };
  app.onMenu((id) => {
    const modal = document.querySelector('dialog[open]');
    if (modal && id !== 'undo' && id !== 'redo' && id !== 'mcp') return;
    commands[id]?.();
    if (!modal) settleFocus();
  });
  app.onOpened(() => void takeOpened());
  app.onDragging((over) => (ui.dropHint.hidden = !over));
  app.onCloseRequested(() => void mayDiscard().then((close) => close && app.close()));
  // Requests wait for the app's settings: whether scripts are allowed.
  const settled = app
    .mcpStatus()
    .then((status) => void (scriptsAllowed = status.scripts))
    .catch(() => void (scriptsAllowed = false));
  app.onMcpRequest((id, request) => void settled.then(() => mcp.handle(request)).then((response) => app.mcpRespond(id, response)));
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
  Object.assign(window, { winscore: { select: (items: number[]) => select(items, true), mcp: (message: unknown) => mcp.handle(message) } });
  await applyQuery();
  started = true;
  await takeOpened();
}

main().catch((err) => fatal('The app failed to start.', err));
