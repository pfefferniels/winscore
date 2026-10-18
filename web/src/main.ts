import './style.css';
import init, { codeName, commandSupported, editWords, InputLine, librarySymbols, paramName, Score, type EncodedList } from './wasm/score_web.js';
import { createAiPrompt } from './ai-prompt';
import { boundsOf, lassoItems, paintLasso } from './ai-lasso';
import type { About, Catalog } from './ai-models';
import type { Access, Region, Scope } from './ai-script';
import { createPageView, type Scene } from './canvas';
import { bindClipboard } from './clipboard';
import { bindCommandBar } from './command-bar';
import { bounds, decode, elementsOf, EMPTY, itemBoxes, union, type Box, type DisplayList } from './display';
import { fontPrefix } from './commands';
import type { Point } from './view';
import { scoreEditor, type Change, type Editor, type Place } from './editor';
import { loadFaces } from './fonts';
import { buildField, codeOf, moveProbes, paintGuides, snap, wantsForHandle, wantsForMove, type Field, type Guide, type Probes, type ScoreFacts } from './guides';
import { cursorFor, decodeHandles, devicePoint, handleAt as handleUnder, paintHandles, paintPill, visibleHandles, type Handle, type HandleSet } from './handles';
import type { Context } from './item-fields';
import { createInputMode, type Shown } from './input-mode';
import { bindInteraction } from './interaction';
import { createMenuBar, inMenuBar, MOD } from './menu';
import { appMenus, type DialogKind } from './menus';
import { bindPanelGrip, filterItemList, formatParam, markSelected, renderItemList, renderSelection, shownItems, type ItemDetails, type ItemSummary, type PanelHandlers } from './panel';
import type { Layer, Overlay } from './paint';
import { download, printPage } from './print';
import { createSymbolDialog } from './symbol-dialog';
import { createTextDialog, editInPlace } from './text-dialog';
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
  rust: DisplayList;
  modified: boolean;
  /** The last click on empty paper, where new items go when nothing is selected. */
  lastPaper: Point | null;
  /** Where pastes go: the last click on the page since the copy, if any. */
  pasteAt: Point | null;
  /** The scrollable page area; kept while a drag is in progress. */
  extent: Box | null;
  /** The line of music input being typed, drawn over the page. */
  preview: Shown | null;
  /** Whether the side panel (selected item, item list) is shown. */
  panel: boolean;
  /** The handles of the selected item while it is the only one selected. */
  handles: HandleSet | null;
  /** The handle under the mouse. */
  hover: number | null;
  /** A move or handle drag in progress, with its guides. */
  drag: Drag | null;
  /** The lasso being drawn, page coordinates. */
  lasso: Point[] | null;
  /** Whether the next drag draws a lasso (the Ask button). */
  lassoArmed: boolean;
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
/** Without an outline under the pointer, WinScore's nearest-reference-point rule applies within this radius (D8). */
const PICK_RADIUS_PX = 12;
/** A finger covers more than a mouse pointer: it picks from further away. */
const TOUCH_TOLERANCE_PX = 10;
const TOUCH_PICK_RADIUS_PX = 24;
/** The line being typed, and in it the item at the caret. */
const PREVIEW_TINT = '#7c3aed';
const FOCUS_TINT = '#ea580c';
/** Guides pull a dragged thing from this far, in CSS pixels (a finger from further). */
const SNAP_PX = 6;
const TOUCH_SNAP_PX = 10;
/** A handle is taken from this far, in CSS pixels. */
const HANDLE_PX = 8;
const TOUCH_HANDLE_PX = 22;

const $ = <T extends HTMLElement>(id: string) => document.getElementById(id) as T;

const ui = {
  app: $<HTMLDivElement>('app'),
  menubar: $<HTMLElement>('menubar'),
  file: $<HTMLInputElement>('file'),
  doc: $<HTMLSpanElement>('doc'),
  docState: $<HTMLSpanElement>('doc-state'),
  undo: $<HTMLButtonElement>('undo'),
  redo: $<HTMLButtonElement>('redo'),
  input: $<HTMLButtonElement>('input'),
  ask: $<HTMLButtonElement>('ask'),
  inputPanel: $<HTMLElement>('input-panel'),
  symbolDialog: $<HTMLDialogElement>('symbol-dialog'),
  textDialog: $<HTMLDialogElement>('text-dialog'),
  band: $<HTMLDivElement>('band'),
  prompt: $<HTMLSpanElement>('prompt'),
  promptCancel: $<HTMLButtonElement>('prompt-cancel'),
  command: $<HTMLInputElement>('command'),
  zoomOut: $<HTMLButtonElement>('zoom-out'),
  zoomIn: $<HTMLButtonElement>('zoom-in'),
  zoom: $<HTMLSelectElement>('zoom'),
  fit: $<HTMLButtonElement>('fit'),
  togglePanel: $<HTMLButtonElement>('toggle-panel'),
  help: $<HTMLButtonElement>('help'),
  shortcuts: $<HTMLDialogElement>('shortcuts-dialog'),
  status: $<HTMLSpanElement>('status'),
  stage: $<HTMLDivElement>('stage'),
  viewport: $<HTMLDivElement>('viewport'),
  content: $<HTMLDivElement>('content'),
  canvas: $<HTMLCanvasElement>('canvas'),
  dropHint: $<HTMLDivElement>('drop-hint'),
  emptyHint: $<HTMLDivElement>('empty-hint'),
  emptyInput: $<HTMLButtonElement>('empty-input'),
  start: $<HTMLElement>('start'),
  startNew: $<HTMLButtonElement>('start-new'),
  startOpen: $<HTMLButtonElement>('start-open'),
  startSamples: $<HTMLDivElement>('start-samples'),
  panel: $<HTMLElement>('panel'),
  panelGrip: $<HTMLDivElement>('panel-grip'),
  item: $<HTMLElement>('item'),
  items: $<HTMLOListElement>('items'),
  itemCount: $<HTMLSpanElement>('item-count'),
  itemFilter: $<HTMLInputElement>('item-filter'),
  selectShown: $<HTMLButtonElement>('items-select'),
  footer: $<HTMLElement>('footer'),
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
  rust: EMPTY,
  modified: false,
  lastPaper: null,
  pasteAt: null,
  extent: null,
  preview: null,
  panel: storedPanel(),
  handles: null,
  hover: null,
  drag: null,
  lasso: null,
  lassoArmed: false,
};

const view = createPageView(ui, showZoom);
/** Names of the item codes P1 takes, looked up once each. */
const codeNames = new Map<number, string>();

function nameOf(code: number): string {
  if (!codeNames.has(code)) codeNames.set(code, codeName(code) ?? `Code ${code}`);
  return codeNames.get(code)!;
}
const inputMode = createInputMode(ui.inputPanel, ui.stage, {
  score: () => state.score,
  show: showInput,
  insert: insertInput,
  focusPage: () => ui.viewport.focus(),
  clientRect: (box) => view.clientRect(box),
});
view.onPaint(() => inputMode.layout());
view.onPaint(describeSelection);
const symbolDialog = createSymbolDialog(ui.symbolDialog);
const textDialog = createTextDialog(ui.textDialog);
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

/** The command bar's answer: what just happened, then the item in edit mode; the engine's own message instead when it has one. */
function report(change: Change | null) {
  if (change?.message) message(change.message, true);
  else message([change?.label, itemLine()].filter(Boolean).join(' · '));
  showPrompt();
}

/** A group command's question, shown before the command bar, which then takes the answer. */
function showPrompt() {
  const question = state.editor?.prompt() ?? null;
  ui.prompt.hidden = question === null;
  ui.promptCancel.hidden = question === null;
  ui.footer.classList.toggle('asking', question !== null);
  ui.prompt.textContent = question ?? '';
  ui.command.placeholder = question ? 'Type the answer, or draw a box' : 'e.g. R 5, NOTE, DE: just type';
  // A touch screen would bring up its keyboard over the page the box is drawn on.
  if (question !== null && document.activeElement !== ui.command && !matchMedia(COARSE).matches) ui.command.focus();
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
  const shown = [bounds(state.rust), state.preview ? bounds(state.preview.list) : null];
  const content = shown.reduce(union, paper) ?? paper;
  return { x0: content.x0 - MARGIN, y0: content.y0 - MARGIN, x1: content.x1 + MARGIN, y1: content.y1 + MARGIN };
}

function layers(): Layer[] {
  const page: Layer = { list: state.rust };
  return state.preview ? [page, { list: state.preview.list, tint: PREVIEW_TINT }] : [page];
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
  const shown = state.handles && !inputMode.isOpen && state.editor?.prompt() == null;
  if (shown && (!state.drag || state.drag.handle)) {
    drawn.push((ctx, t) => {
      const drag = state.drag;
      const active = drag?.handle ? { index: drag.handle.index, at: drag.at } : null;
      if (state.handles) paintHandles(ctx, t, { set: state.handles, hover: drag ? null : state.hover, active, coarse: touchScreen(), dpr: dpr() });
    });
  }
  if (state.lasso) {
    drawn.push((ctx, t) => {
      if (state.lasso) paintLasso(ctx, t, state.lasso, dpr());
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
    highlights: [
      ...selection().map((item) => ({ list: state.rust, item })),
      ...(state.preview?.focus.map((item) => ({ list: state.preview!.list, item, colour: FOCUS_TINT })) ?? []),
    ],
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

function refreshStatus() {
  const open = state.score !== null;
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
  ui.command.disabled = !state.editor;
  ui.input.disabled = !state.editor;
  ui.ask.disabled = !state.editor;
  ui.input.setAttribute('aria-pressed', String(inputMode.isOpen));
  ui.app.classList.toggle('inputting', inputMode.isOpen);
  [ui.zoomIn, ui.zoomOut, ui.zoom, ui.fit].forEach((control) => (control.disabled = !open));
  ui.start.hidden = open;
  ui.panel.hidden = !open || !state.panel;
  ui.togglePanel.disabled = !open;
  ui.emptyHint.hidden = !open || state.score!.itemCount() > 0 || inputMode.isOpen;
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

function refreshItemList() {
  const items = state.score ? itemSummaries(state.score) : [];
  renderItemList(ui.items, items, handlers);
  const shown = filterItemList(ui.items, ui.itemFilter.value);
  ui.itemCount.textContent = !state.score ? '' : shown === items.length ? String(items.length) : `${shown} of ${items.length}`;
}

/** Re-renders the parameter panel, keeping the keyboard in the field it was in. */
function refreshPanel() {
  const score = state.score;
  const items = selection();
  const shown = score ? items.flatMap((index) => details(score, index, items.length === 1) ?? []) : [];
  const focused = ui.item.contains(document.activeElement) ? document.activeElement?.id : undefined;
  renderSelection(ui.item, shown, handlers, score !== null);
  markSelected(ui.items, selection());
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

/** Re-renders after an edit; the panel and list follow once a drag is over. */
function edited(change: Change | null, live: boolean) {
  const score = state.score;
  if (!score) return;
  state.rust = decodeAndFree(live ? score.renderSelection() : score.render());
  if (live && state.drag && !state.drag.handle) state.drag.readout = moveReadout();
  if (!live) {
    refreshHandles();
    state.modified ||= change !== null;
    refreshItemList();
    refreshPanel();
    void loadFontsAndRepaint();
    report(change);
    inputMode.refresh();
    aiPrompt.refresh();
  }
  redraw(live);
}

function failed(err: unknown) {
  message(err instanceof Error ? err.message : String(err), true);
}

function edit(action: (editor: Editor) => Change | null) {
  const editor = state.editor;
  if (!editor) return;
  try {
    edited(action(editor), false);
  } catch (err) {
    failed(err);
  }
}

/** A SCORE command line from the command bar, a menu, the panel or a key; the result is scrolled into view. */
function runCommand(line: string) {
  // IN n: music input on staff n, typed in the input panel.
  const input = /^IN(?:\s+(\d+))?$/i.exec(line.trim());
  if (input) {
    enterInput(input[1] === undefined ? undefined : Number(input[1]));
    return;
  }
  edit((editor) => editor.execute(line));
  revealSelection();
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

const clipboard = bindClipboard({
  ready: () => state.editor !== null,
  copy: () => copySelection(false),
  cut: () => copySelection(true),
  paste,
  duplicate,
});

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

function enterInput(staff?: number) {
  inputMode.open(staff);
  refreshStatus();
}

/** Draws the line being typed over the page and scrolls to the cursor when it moved. */
function showInput(shown: Shown | null) {
  state.preview = shown;
  redraw();
  if (shown?.reveal) view.reveal(shown.reveal);
}

function insertInput(line: InputLine): boolean {
  let inserted = false;
  edit((editor) => {
    const change = editor.insertInput(line);
    inserted = change !== null;
    return change;
  });
  revealSelection();
  return inserted;
}

const handlers: PanelHandlers = {
  select: (index) => select([index], true),
  selectItems: (items) => select(items),
  toggle(index) {
    const items = selection();
    select(items.includes(index) ? items.filter((i) => i !== index) : [...items, index]);
  },
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
function mayDiscard(): boolean {
  return !state.modified || window.confirm(`Discard the unsaved changes to ${state.fileName}?`);
}

function openScore(score: Score, name: string) {
  inputMode.close();
  aiPrompt.close();
  state.score?.free();
  state.score = score;
  state.editor = scoreEditor(score);
  state.fileName = name;
  state.rust = decodeAndFree(score.render());
  state.modified = false;
  state.lastPaper = null;
  state.pasteAt = null;
  state.handles = null;
  state.drag = null;
  refreshItemList();
  refreshPanel();
  inputMode.refresh();
  redraw();
  view.fitWidth();
  const content = bounds(state.rust);
  if (content) view.scrollToTop(content.y1 + MARGIN);
  void loadFontsAndRepaint();
  report(null);
}

function newScore() {
  if (!mayDiscard()) return;
  openScore(Score.empty(), 'untitled.mus');
}

async function openSample(sample: Sample) {
  if (!mayDiscard()) return;
  try {
    const base64 = (await (await fetch(sample.url)).text()).trim();
    const bytes = Uint8Array.from(atob(base64), (c) => c.charCodeAt(0));
    openScore(new Score(bytes), sample.title);
  } catch (err) {
    message(`Cannot open ${sample.title}: ${String(err)}`, true);
  }
}

function chooseFile() {
  if (mayDiscard()) ui.file.click();
}

async function openFile(file: File) {
  try {
    openScore(new Score(new Uint8Array(await file.arrayBuffer())), file.name);
  } catch (err) {
    message(`Cannot open ${file.name}: ${String(err)}`, true);
  }
}

function save() {
  if (!state.score) return;
  download(state.score.save() as Uint8Array<ArrayBuffer>, state.fileName || 'score.mus', 'application/octet-stream');
  state.modified = false;
  refreshStatus();
}

/** The score's file name with another extension. */
function exportName(extension: string): string {
  return `${(state.fileName || 'score').replace(/\.[^.]*$/, '')}.${extension}`;
}

function exportSvg() {
  if (state.score) download(state.score.exportSvg(), exportName('svg'), 'image/svg+xml');
}

async function print() {
  if (!state.score) return;
  try {
    await printPage(decodeAndFree(state.score.renderPrint()), paperBox());
  } catch (err) {
    failed(err);
  }
}

function setPanel(shown: boolean) {
  state.panel = shown;
  ui.panel.hidden = !shown || !state.score;
  ui.togglePanel.setAttribute('aria-pressed', String(shown));
  // The list could not scroll to the selection while it was hidden.
  if (shown) markSelected(ui.items, selection());
  try {
    localStorage.setItem(PANEL_KEY, shown ? 'shown' : 'hidden');
  } catch {
    // Without storage the setting lasts until the page is left.
  }
}

function toggleInput() {
  if (inputMode.isOpen) inputMode.close();
  else enterInput();
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
  if (!state.handles || inputMode.isOpen || state.editor?.prompt() != null) return null;
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
  const shown = set && !inputMode.isOpen ? visibleHandles(set, t, dpr()) : [];
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
// The AI command

/** The edit script's view of the score. */
function aiAccess(): Access | null {
  const { score, editor } = state;
  if (!score || !editor) return null;
  return {
    editor,
    params(index) {
      const info = score.item(index);
      if (!info) return null;
      try {
        return info.params;
      } finally {
        info.free();
      }
    },
    context: (index) => ({ clef: clefAt(score, index), symbolName }),
    staves: () => editor.staves(),
    inputLine: (passes, staff, from, to) => new InputLine(passes, staff, from, to),
  };
}

/** P1 … Pn without trailing zeros. */
function trimmed(params: Float32Array): number[] {
  const list = Array.from(params);
  while (list.length > 4 && list.at(-1) === 0) list.pop();
  return list;
}

/** The middle line of a staff by clef type, as a diatonic step from C0: B4, D3, C4, A3, B4. */
const CLEF_MIDDLES = [34, 22, 28, 26, 34];

/** The middle line of the region's staff for the clef in force there, where typed notes start. */
function middleAt(score: Score, region: Region | null): number {
  if (!region) return CLEF_MIDDLES[0]!;
  const clefs = itemSummaries(score)
    .filter(({ code, staff, p3 }) => code === 3 && staff === region.staff && p3 <= region.from + 1)
    .sort((a, b) => a.p3 - b.p3);
  const last = clefs.at(-1);
  const info = last ? score.item(last.index) : undefined;
  if (!info) return CLEF_MIDDLES[0]!;
  const type = Math.trunc(Math.abs(info.params[4] ?? 0));
  info.free();
  return CLEF_MIDDLES[type] ?? CLEF_MIDDLES[0]!;
}

const SAMPLE_ITEMS = 60;

/** What the models are told about a command and the items it is about. */
function aiAbout(text: string, scope: Scope): About | null {
  const score = state.score;
  const access = aiAccess();
  if (!score || !access) return null;
  const counts = new Map<number, number>();
  const sample: number[][] = [];
  let indices: number[];
  if (scope.keys === null) {
    const all = itemSummaries(score);
    all.forEach(({ code }) => counts.set(code, (counts.get(code) ?? 0) + 1));
    indices = all.slice(0, SAMPLE_ITEMS).map(({ index }) => index);
  } else {
    const keys = access.editor.keys();
    const at = new Map(keys.map((key, i) => [key, i]));
    indices = scope.keys.flatMap((key) => at.get(key) ?? []);
  }
  for (const index of indices) {
    const params = access.params(index);
    if (!params) continue;
    if (scope.keys !== null) counts.set(params[0]!, (counts.get(params[0]!) ?? 0) + 1);
    if (sample.length < SAMPLE_ITEMS) sample.push(trimmed(params));
  }
  const staves = new Set([...sample.map((p) => p[1]!), ...(scope.region ? [scope.region.staff] : [])]);
  const bars = new Map<number, number[]>();
  itemSummaries(score).forEach(({ code, staff, p3 }) => {
    if (code === 14 && staves.has(staff)) bars.set(staff, [...(bars.get(staff) ?? []), p3]);
  });
  bars.forEach((xs) => xs.sort((a, b) => a - b));
  return { text, counts, whole: scope.keys === null, region: scope.region, middle: middleAt(score, scope.region), sample, bars, codeName: nameOf };
}

let catalog: Catalog | null = null;

function aiCatalog(): Catalog {
  catalog ??= {
    codes: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 17, 18].map((code) => ({ code, name: nameOf(code) })),
    words: JSON.parse(editWords()) as Catalog['words'],
  };
  return catalog;
}

const aiPrompt = createAiPrompt(ui.stage, {
  editor: () => state.editor,
  access: aiAccess,
  about: aiAbout,
  catalog: aiCatalog,
  supported: commandSupported,
  clientRect: (box) => view.clientRect(box),
  edited(live, params) {
    const score = state.score;
    if (!score) return;
    if (live) {
      state.rust = decodeAndFree(params ? score.renderSelection() : score.render());
      state.modified = true;
      redraw(true);
    } else edited({ label: state.editor?.undoLabel() ?? '', message: null }, false);
  },
  undo: (redo) => edit((editor) => (redo ? editor.redo() : editor.undo())),
  closed: () => ui.viewport.focus(),
});
view.onPaint(() => aiPrompt.place());

function armLasso(on: boolean) {
  state.lassoArmed = on && state.editor !== null;
  ui.ask.setAttribute('aria-pressed', String(state.lassoArmed));
  ui.viewport.classList.toggle('lassoing', state.lassoArmed);
  if (state.lassoArmed) {
    aiPrompt.close();
    message('Draw a lasso around the music, then say what to do with it');
  } else report(null);
}

/** Staff and P3 span of page box `box`, for music added there. */
function regionOf(box: Box): Region | null {
  const editor = state.editor;
  if (!editor) return null;
  const middle = (box.y0 + box.y1) / 2;
  const centre = editor.placeAt({ x: (box.x0 + box.x1) / 2, y: middle });
  const left = editor.placeAt({ x: box.x0, y: middle });
  const right = editor.placeAt({ x: box.x1, y: middle });
  const top = editor.placeAt({ x: (box.x0 + box.x1) / 2, y: box.y1 });
  const bottom = editor.placeAt({ x: (box.x0 + box.x1) / 2, y: box.y0 });
  if (!centre) return null;
  // An edge past the paper has no staff on its side of the page: the staff's start or end.
  const [from, to] = [left?.p3 ?? 0, right?.p3 ?? 200];
  return {
    staff: centre.staff,
    bottom: Math.min(bottom?.staff ?? centre.staff, centre.staff),
    top: Math.max(top?.staff ?? centre.staff, centre.staff),
    from: Math.max(0, Math.min(from, to)),
    to: Math.min(200, Math.max(from, to)),
  };
}

/** A lasso was drawn: the items in it are selected and the AI command opens by it. */
function lassoed(points: Point[]) {
  state.lasso = null;
  armLasso(false);
  const { score, editor } = state;
  if (!score || !editor) return;
  const summaries = itemSummaries(score);
  const items = lassoItems(points, itemBoxes(state.rust, summaries.length), summaries.map((s) => s.code));
  editor.select(items);
  selectionChanged();
  const box = boundsOf(points);
  const keys = editor.keys();
  aiPrompt.open({ keys: items.map((i) => keys[i]!), region: regionOf(box) }, box);
}

/** ⌘K: the AI command for the selection, or for the whole score when nothing is selected. */
function askAboutSelection() {
  const editor = state.editor;
  if (!editor) return;
  const items = selection();
  const keys = editor.keys();
  const box = selectionBox();
  const shown = view.visibleBox();
  const around = box ?? { x0: (shown.x0 + shown.x1) / 2 - 2000, x1: (shown.x0 + shown.x1) / 2 + 2000, y0: (shown.y0 + shown.y1) / 2, y1: (shown.y0 + shown.y1) / 2 };
  aiPrompt.open({ keys: items.length ? items.map((i) => keys[i]!) : null, region: box ? regionOf(box) : null }, around);
}

function bindPointer() {
  // With the input open, a click on its staff puts the cursor there (a tap does, below, once it is not a scroll).
  ui.viewport.addEventListener(
    'pointerdown',
    (e) => {
      if (e.pointerType === 'touch' || e.button !== 0 || e.ctrlKey || e.metaKey || !inputMode.isOpen) return;
      if (inputMode.click(view.pageAt(e.clientX, e.clientY), e.shiftKey)) {
        e.preventDefault();
        e.stopImmediatePropagation();
      }
    },
    { capture: true },
  );
  // A press on the page outside a lasso closes the AI command.
  ui.viewport.addEventListener(
    'pointerdown',
    (e) => {
      if (aiPrompt.isOpen && !e.altKey && !state.lassoArmed) aiPrompt.close();
    },
    { capture: true },
  );
  bindInteraction(ui.viewport, ui.band, {
    editor: () => state.editor,
    itemAt,
    pageAt: (x, y) => view.pageAt(x, y),
    zoom: () => view.zoom,
    zoomAt: (zoom, at, clientX, clientY) => view.zoomAt(zoom, at, { clientX, clientY }),
    inputTap: (x, y) => inputMode.isOpen && inputMode.click(view.pageAt(x, y), false),
    holdsKeyboard: () => inputMode.holdsKeyboard,
    selected: selectionChanged,
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
    lassoArmed: () => state.lassoArmed,
    lassoDraw(points) {
      state.lasso = points;
      view.repaint();
    },
    lasso: lassoed,
  });
  ui.viewport.addEventListener('pointerleave', () => {
    if (state.hover === null) return;
    state.hover = null;
    view.repaint();
  });
  ui.promptCancel.addEventListener('click', () => {
    edit((editor) => editor.execute('X'));
    ui.viewport.focus();
  });
  ui.viewport.addEventListener('pointermove', (e) => {
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
    if (file && mayDiscard()) void openFile(file);
  });
}

/** Gives the keyboard back to the page when an action left it nowhere in particular. */
function settleFocus() {
  const active = document.activeElement;
  if (!active || active === document.body || inMenuBar(active) || ui.app.querySelector('.appbar')!.contains(active)) ui.viewport.focus();
}

function bindMenus() {
  createMenuBar(
    ui.menubar,
    appMenus({
      hasScore: () => state.score !== null,
      hasSelection: () => selection().length > 0,
      run: runCommand,
      runArea,
      supported: commandSupported,
      openDialog: (kind) => void openDialog(kind),
      newScore,
      open: chooseFile,
      samples: () => samples.map((s) => ({ title: s.title, open: () => void openSample(s) })),
      save,
      exportSvg,
      print: () => void print(),
      undo: () => edit((editor) => editor.undo()),
      redo: () => edit((editor) => editor.redo()),
      cut: clipboard.cut,
      copy: clipboard.copy,
      paste: clipboard.paste,
      canPaste: () => clipboard.full,
      duplicate,
      undoLabel: () => state.editor?.undoLabel() ?? null,
      redoLabel: () => state.editor?.redoLabel() ?? null,
      input: () => enterInput(),
      zoomIn: () => view.setZoom(stepZoom(view.zoom, 1)),
      zoomOut: () => view.setZoom(stepZoom(view.zoom, -1)),
      fitWidth: () => view.fitWidth(),
      actualSize: () => view.setZoom(100),
      panelShown: () => state.panel,
      togglePanel: () => setPanel(!state.panel),
      shortcuts: showShortcuts,
      ask: askAboutSelection,
      lasso: () => armLasso(true),
    }),
    settleFocus,
  );
}

function showShortcuts() {
  if (ui.shortcuts.open) return;
  ui.shortcuts.showModal();
  // Opened on its Close button, the dialog would start scrolled to the end on a small screen.
  ui.shortcuts.scrollTop = 0;
}

function bindStart() {
  ui.startNew.addEventListener('click', newScore);
  ui.startOpen.addEventListener('click', chooseFile);
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
  if (e.key.toLowerCase() === 'k' && !e.shiftKey) {
    e.preventDefault();
    askAboutSelection();
    return;
  }
  const action = { o: chooseFile, s: save, p: () => void print() }[e.key.toLowerCase()];
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
  ui.input.addEventListener('click', toggleInput);
  ui.ask.addEventListener('click', () => armLasso(!state.lassoArmed));
  ui.emptyInput.addEventListener('click', () => enterInput());
  ui.togglePanel.addEventListener('click', () => setPanel(!state.panel));
  ui.help.addEventListener('click', showShortcuts);
  ui.itemFilter.addEventListener('input', refreshItemList);
  ui.itemFilter.addEventListener('keydown', (e) => {
    if (e.key !== 'Escape') return;
    ui.itemFilter.value = '';
    refreshItemList();
  });
  ui.selectShown.addEventListener('click', () => select(shownItems(ui.items)));
  ui.app.querySelectorAll<HTMLButtonElement>('.appbar button').forEach((button) => button.addEventListener('click', settleFocus));
  if (MOD !== '⌘') ui.shortcuts.querySelectorAll('kbd.mod').forEach((k) => (k.textContent = 'Ctrl'));
  bindCommandBar(ui.command, {
    run: runCommand,
    page: ui.viewport,
  });
  window.addEventListener('keydown', onAppKey);
  window.addEventListener('keydown', (e) => {
    if (e.target instanceof HTMLInputElement || e.metaKey || e.ctrlKey || inMenuBar(e.target)) return;
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
  else if (query.has('new')) newScore();
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

async function main() {
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
  await applyQuery();
}

main().catch((err) => fatal('The app failed to start.', err));
