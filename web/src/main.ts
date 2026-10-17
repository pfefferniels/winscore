import './style.css';
import init, { codeName, commandSupported, librarySymbols, paramName, Score, type EncodedList, type InputLine } from './wasm/score_web.js';
import { createPageView, type Scene } from './canvas';
import { bindCommandBar } from './command-bar';
import { bounds, decode, elementsOf, EMPTY, union, type Box, type DisplayList } from './display';
import { fontPrefix } from './commands';
import type { Point } from './view';
import { scoreEditor, type Change, type Editor, type Place } from './editor';
import { loadFaces } from './fonts';
import type { Context } from './item-fields';
import { createInputMode, type Shown } from './input-mode';
import { bindInteraction } from './interaction';
import { createMenuBar, inMenuBar, MOD } from './menu';
import { appMenus, type DialogKind } from './menus';
import { filterItemList, formatParam, markSelected, renderItem, renderItemList, type ItemDetails, type ItemSummary, type PanelHandlers } from './panel';
import type { Layer } from './paint';
import { download, printPage } from './print';
import { createSymbolDialog } from './symbol-dialog';
import { createTextDialog, editInPlace } from './text-dialog';
import { stepZoom, ZOOM_LEVELS } from './view';

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
  /** The scrollable page area; kept while a drag is in progress. */
  extent: Box | null;
  /** The line of music input being typed, drawn over the page. */
  preview: Shown | null;
  /** Whether the side panel (selected item, item list) is shown. */
  panel: boolean;
}

const MARGIN = 1000;
const CLICK_TOLERANCE_PX = 4;
/** Without an outline under the pointer, WinScore's nearest-reference-point rule applies within this radius (D8). */
const PICK_RADIUS_PX = 12;
/** The line being typed, and in it the item at the caret. */
const PREVIEW_TINT = '#7c3aed';
const FOCUS_TINT = '#ea580c';

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
  item: $<HTMLElement>('item'),
  items: $<HTMLOListElement>('items'),
  itemCount: $<HTMLSpanElement>('item-count'),
  itemFilter: $<HTMLInputElement>('item-filter'),
  footer: $<HTMLElement>('footer'),
  cursor: $<HTMLSpanElement>('cursor'),
  message: $<HTMLSpanElement>('message'),
};

const PANEL_KEY = 'winscore.panel';

/** The remembered side panel setting; storage may be unavailable. */
function storedPanel(): boolean {
  try {
    return localStorage.getItem(PANEL_KEY) !== 'hidden';
  } catch {
    return true;
  }
}

const state: State = {
  score: null,
  editor: null,
  fileName: '',
  rust: EMPTY,
  modified: false,
  lastPaper: null,
  extent: null,
  preview: null,
  panel: storedPanel(),
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
  if (question !== null && document.activeElement !== ui.command) ui.command.focus();
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

/** The item whose parameters the panel shows: the last one selected. */
function primary(): number | null {
  return selection().at(-1) ?? null;
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
  };
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
  ui.input.setAttribute('aria-pressed', String(inputMode.isOpen));
  [ui.zoomIn, ui.zoomOut, ui.zoom, ui.fit].forEach((control) => (control.disabled = !open));
  ui.start.hidden = open;
  ui.panel.hidden = !open || !state.panel;
  ui.togglePanel.disabled = !open;
  ui.emptyHint.hidden = !open || state.score!.itemCount() > 0 || inputMode.isOpen;
}

/** Highest parameter number an edit may set. */
const MAX_PARAM = 45;

/** The help's labels of P1 … up to the last one it describes for `code`. */
function paramNames(code: number): (string | null)[] {
  const names = Array.from({ length: MAX_PARAM }, (_, i) => paramName(code, i + 1) ?? null);
  while (names.length > 0 && names.at(-1) === null) names.pop();
  return names;
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

function details(score: Score, index: number): ItemDetails | null {
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
      drawn: bounds(elementsOf(state.rust, index)) !== null,
      others: selection().filter((i) => i !== index).length,
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
  const shown = primary();
  const focused = ui.item.contains(document.activeElement) ? document.activeElement?.id : undefined;
  renderItem(ui.item, state.score && shown !== null ? details(state.score, shown) : null, handlers, state.score !== null);
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
  if (!live) {
    state.modified ||= change !== null;
    refreshItemList();
    refreshPanel();
    void loadFontsAndRepaint();
    report(change);
    inputMode.refresh();
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
  run: (command) => {
    runCommand(command);
    ui.viewport.focus();
  },
  setParams: (index, changes) => edit((editor) => editor.setParams(index, changes)),
  async pickSymbol(index) {
    const symbol = await symbolDialog.choose();
    if (symbol !== null) edit((editor) => editor.setParams(index, [[5, symbol]]));
  },
  setText: (index, text) => edit((editor) => editor.setText(index, text)),
  setFont(index, code) {
    state.editor?.select([index]);
    runCommand(`FNT${fontPrefix(code).slice(1)}`);
  },
};

/** Asks before changes that were not saved are thrown away. */
function mayDiscard(): boolean {
  return !state.modified || window.confirm(`Discard the unsaved changes to ${state.fileName}?`);
}

function openScore(score: Score, name: string) {
  inputMode.close();
  state.score?.free();
  state.score = score;
  state.editor = scoreEditor(score);
  state.fileName = name;
  state.rust = decodeAndFree(score.render());
  state.modified = false;
  state.lastPaper = null;
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

/** The item under the pointer: a drawn outline, else the nearest reference point. */
function itemAt(clientX: number, clientY: number): number | null {
  const p = view.pageAt(clientX, clientY);
  const drawn = state.score?.itemAt(p.x, p.y, view.unitsPerCss(CLICK_TOLERANCE_PX), 0);
  return drawn ?? state.score?.itemAt(p.x, p.y, 0, view.unitsPerCss(PICK_RADIUS_PX)) ?? null;
}

function bindPointer() {
  // With the input open, a click on its staff puts the cursor there.
  ui.viewport.addEventListener(
    'pointerdown',
    (e) => {
      if (e.button !== 0 || e.ctrlKey || e.metaKey || !inputMode.isOpen) return;
      if (inputMode.click(view.pageAt(e.clientX, e.clientY), e.shiftKey)) {
        e.preventDefault();
        e.stopImmediatePropagation();
      }
    },
    { capture: true },
  );
  bindInteraction(ui.viewport, ui.band, {
    editor: () => state.editor,
    itemAt,
    pageAt: (x, y) => view.pageAt(x, y),
    selected: selectionChanged,
    edited,
    failed,
    command: runCommand,
    box(from, to) {
      edit((editor) => editor.drawBox(from, to));
      selectionChanged();
    },
    clickedPaper: (at) => (state.lastPaper = at),
    open: (item) => void openItem(item),
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
    }),
    settleFocus,
  );
}

function showShortcuts() {
  if (!ui.shortcuts.open) ui.shortcuts.showModal();
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
  ui.emptyInput.addEventListener('click', () => enterInput());
  ui.togglePanel.addEventListener('click', () => setPanel(!state.panel));
  ui.help.addEventListener('click', showShortcuts);
  ui.itemFilter.addEventListener('input', refreshItemList);
  ui.itemFilter.addEventListener('keydown', (e) => {
    if (e.key !== 'Escape') return;
    ui.itemFilter.value = '';
    refreshItemList();
  });
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
  renderItem(ui.item, null, handlers, false);
  await applyQuery();
}

main().catch((err) => fatal('The app failed to start.', err));
