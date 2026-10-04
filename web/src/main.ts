import './style.css';
import init, { commandSupported, paramName, Reference as EngineList, Score, type EncodedList } from './wasm/score_web.js';
import { createPageView, type Scene } from './canvas';
import { bindCommandBar } from './command-bar';
import { bounds, decode, elementsOf, EMPTY, union, type Box, type DisplayList } from './display';
import { scoreEditor, type Change, type Editor } from './editor';
import { loadFaces } from './fonts';
import { createInputDialog } from './input-dialog';
import { bindInteraction } from './interaction';
import { formatParam, markSelected, renderItem, renderItemList, type ItemDetails, type ItemSummary, type PanelHandlers } from './panel';
import type { Layer } from './paint';
import { createPalette } from './palette';
import { stepZoom, ZOOM_LEVELS } from './view';

type Mode = 'rust' | 'engine' | 'overlay';

interface ReferenceInfo {
  url: string;
  paper: string | null;
  pageSize: [number, number] | null;
  valid: boolean;
  invalidReasons: string[];
}

interface Sample {
  title: string;
  /** The `.mus` bytes as base64 text. */
  url: string;
  case: string;
  reference: ReferenceInfo | null;
}

interface Reference {
  /** Owns the list on the wasm side, for hit-testing. */
  engine: EngineList;
  list: DisplayList;
  pageSize: [number, number] | null;
  note: string | null;
}

interface State {
  score: Score | null;
  editor: Editor | null;
  fileName: string;
  rust: DisplayList;
  reference: Reference | null;
  mode: Mode;
  modified: boolean;
}

const MARGIN = 1000;
const CLICK_TOLERANCE_PX = 4;
const ENGINE_TINT = '#06b6d4';
const RUST_TINT = '#e11d74';

const $ = <T extends HTMLElement>(id: string) => document.getElementById(id) as T;

const ui = {
  app: $<HTMLDivElement>('app'),
  open: $<HTMLButtonElement>('open'),
  file: $<HTMLInputElement>('file'),
  sample: $<HTMLSelectElement>('sample'),
  save: $<HTMLButtonElement>('save'),
  undo: $<HTMLButtonElement>('undo'),
  redo: $<HTMLButtonElement>('redo'),
  input: $<HTMLButtonElement>('input'),
  inputDialog: $<HTMLDialogElement>('input-dialog'),
  command: $<HTMLInputElement>('command'),
  zoomOut: $<HTMLButtonElement>('zoom-out'),
  zoomIn: $<HTMLButtonElement>('zoom-in'),
  zoom: $<HTMLSelectElement>('zoom'),
  fit: $<HTMLButtonElement>('fit'),
  mode: $<HTMLDivElement>('mode'),
  legend: $<HTMLSpanElement>('legend'),
  status: $<HTMLSpanElement>('status'),
  stage: $<HTMLDivElement>('stage'),
  viewport: $<HTMLDivElement>('viewport'),
  content: $<HTMLDivElement>('content'),
  canvas: $<HTMLCanvasElement>('canvas'),
  dropHint: $<HTMLDivElement>('drop-hint'),
  item: $<HTMLElement>('item'),
  items: $<HTMLOListElement>('items'),
  itemCount: $<HTMLSpanElement>('item-count'),
  cursor: $<HTMLSpanElement>('cursor'),
  message: $<HTMLSpanElement>('message'),
  palette: $<HTMLElement>('palette'),
};

const state: State = { score: null, editor: null, fileName: '', rust: EMPTY, reference: null, mode: 'rust', modified: false };

const view = createPageView(ui, showZoom);
const inputDialog = createInputDialog(ui.inputDialog);
const palette = createPalette(ui.palette, { run: runCommand, supported: commandSupported });

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

/** The command bar's answer: what just happened, then the item in edit mode. */
function report(label: string | null) {
  message([label, itemLine()].filter(Boolean).join(' · '));
}

function decodeAndFree(encoded: EncodedList): DisplayList {
  try {
    return decode(encoded);
  } finally {
    encoded.free();
  }
}

function paperBox(): Box {
  const size = state.reference?.pageSize;
  const width = size?.[0] ?? state.score?.paperWidth() ?? 34000;
  const height = size?.[1] ?? state.score?.paperHeight() ?? 56000;
  return { x0: 0, y0: 0, x1: width, y1: height };
}

function extent(paper: Box): Box {
  const content = [bounds(state.rust), state.reference ? bounds(state.reference.list) : null].reduce(union, paper) ?? paper;
  return { x0: content.x0 - MARGIN, y0: content.y0 - MARGIN, x1: content.x1 + MARGIN, y1: content.y1 + MARGIN };
}

function layers(): Layer[] {
  const engine = state.reference?.list;
  switch (state.mode) {
    case 'rust':
      return [{ list: state.rust }];
    case 'engine':
      return engine ? [{ list: engine }] : [];
    case 'overlay':
      return [
        ...(engine ? [{ list: engine, tint: ENGINE_TINT, composite: 'multiply' as const }] : []),
        { list: state.rust, tint: RUST_TINT, composite: 'multiply' as const },
      ];
  }
}

function selection(): number[] {
  return state.editor?.selection() ?? [];
}

/** The item whose parameters the panel shows: the last one selected. */
function primary(): number | null {
  return selection().at(-1) ?? null;
}

function scene(): Scene {
  const paper = paperBox();
  return {
    layers: layers(),
    paper,
    extent: extent(paper),
    highlights: selection().flatMap((item) => shownLists().map((list) => ({ list, item }))),
  };
}

function refreshStatus() {
  const items = state.score?.itemCount() ?? 0;
  ui.status.textContent = state.score ? `${state.fileName}${state.modified ? ' (modified)' : ''} · ${items} items` : '';
  ui.save.disabled = !state.score;
  const undo = state.editor?.undoLabel() ?? null;
  const redo = state.editor?.redoLabel() ?? null;
  ui.undo.disabled = undo === null;
  ui.redo.disabled = redo === null;
  ui.undo.title = undo === null ? 'Nothing to undo' : `Undo ${undo} (⌘Z / Ctrl+Z)`;
  ui.redo.title = redo === null ? 'Nothing to redo' : `Redo ${redo} (⇧⌘Z / Ctrl+Y)`;
  ui.command.disabled = !state.editor;
  ui.input.disabled = !state.editor;
  palette.refresh(selection().length > 0);
  ui.mode.querySelectorAll<HTMLButtonElement>('button').forEach((button) => {
    const mode = button.dataset.mode as Mode;
    button.setAttribute('aria-checked', String(mode === state.mode));
    button.disabled = mode !== 'rust' && !state.reference;
  });
  ui.legend.hidden = state.mode !== 'overlay';
}

function summary(score: Score, index: number): ItemSummary | null {
  const info = score.item(index);
  if (!info) return null;
  try {
    const params = info.params;
    return { index, code: info.code, name: info.name ?? `Code ${info.code}`, staff: params[1] ?? 0, p3: params[2] ?? 0 };
  } finally {
    info.free();
  }
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
      paramNames: Array.from(params, (_, i) => paramName(info.code, i + 1) ?? null),
      text: info.text ?? null,
      drawn: bounds(elementsOf(state.rust, index)) !== null,
      others: selection().filter((i) => i !== index).length,
    };
  } finally {
    info.free();
  }
}

function refreshItemList() {
  const score = state.score;
  const items = score
    ? Array.from({ length: score.itemCount() }, (_, i) => summary(score, i)).filter((s): s is ItemSummary => s !== null)
    : [];
  renderItemList(ui.items, items, handlers);
  ui.itemCount.textContent = score ? `(${items.length})` : '';
}

/** Re-renders the parameter panel, keeping the keyboard in the field it was in. */
function refreshPanel() {
  const shown = primary();
  const focused = ui.item.contains(document.activeElement) ? document.activeElement?.id : undefined;
  renderItem(ui.item, state.score && shown !== null ? details(state.score, shown) : null, handlers);
  markSelected(ui.items, selection());
  const field = focused ? ui.item.querySelector<HTMLInputElement>(`#${focused}`) : null;
  field?.focus();
  field?.select();
}

function redraw() {
  view.setScene(scene());
  refreshStatus();
}

async function loadFontsAndRepaint() {
  const runs = [...state.rust.texts, ...(state.reference?.list.texts ?? [])];
  await loadFaces(runs);
  view.repaint();
}

/** The display lists on screen in the current mode. */
function shownLists(): DisplayList[] {
  const engine = state.reference ? [state.reference.list] : [];
  return { rust: [state.rust], engine, overlay: [state.rust, ...engine] }[state.mode];
}

function selectionChanged() {
  refreshPanel();
  redraw();
  report(null);
}

/** Scrolls the selected items into view unless they are visible. */
function revealSelection() {
  const box = selection()
    .flatMap((item) => shownLists().map((list) => bounds(elementsOf(list, item))))
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
  state.rust = decodeAndFree(score.render());
  if (!live) {
    state.modified ||= change !== null;
    refreshItemList();
    refreshPanel();
    void loadFontsAndRepaint();
    report(change?.label ?? null);
  }
  redraw();
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

/** A SCORE command line from the command bar, the palette or a key; the result is scrolled into view. */
function runCommand(line: string) {
  edit((editor) => editor.execute(line));
  revealSelection();
}

async function enterInput() {
  if (!state.score) return;
  const line = await inputDialog.ask(state.score);
  if (!line) return;
  try {
    edit((editor) => editor.insertInput(line));
  } finally {
    line.free();
  }
  revealSelection();
  ui.viewport.focus();
}

const handlers: PanelHandlers = {
  select: (index) => select([index], true),
  setParam: (index, n, value) => edit((editor) => editor.setParam(index, n, value)),
};

function readReference(json: string, pageSize: [number, number] | null, note: string | null): Reference {
  const engine = new EngineList(json);
  return { engine, list: decodeAndFree(engine.list()), pageSize, note };
}

function setReference(reference: Reference | null) {
  state.reference?.engine.free();
  state.reference = reference;
}

async function fetchReference(info: ReferenceInfo): Promise<Reference> {
  const json = await (await fetch(info.url)).text();
  const note = info.valid ? null : `engine reference marked invalid: ${info.invalidReasons.join('; ')}`;
  return readReference(json, info.pageSize, note);
}

function openScore(bytes: Uint8Array, name: string, reference: Reference | null) {
  const score = new Score(bytes);
  state.score?.free();
  state.score = score;
  state.editor = scoreEditor(score);
  state.fileName = name;
  state.rust = decodeAndFree(score.render());
  setReference(reference);
  state.modified = false;
  const rustDraws = state.rust.shapes.length > 0;
  state.mode = rustDraws || !reference ? 'rust' : 'engine';
  refreshItemList();
  refreshPanel();
  redraw();
  view.fitWidth();
  const content = [bounds(state.rust), reference ? bounds(reference.list) : null].reduce(union, null);
  if (content) view.scrollToTop(content.y1 + MARGIN);
  void loadFontsAndRepaint();
  message(reference?.note ?? '');
}

async function openSample(sample: Sample) {
  try {
    const base64 = (await (await fetch(sample.url)).text()).trim();
    const bytes = Uint8Array.from(atob(base64), (c) => c.charCodeAt(0));
    const reference = sample.reference ? await fetchReference(sample.reference) : null;
    openScore(bytes, sample.title, reference);
  } catch (err) {
    message(`Cannot open ${sample.title}: ${String(err)}`, true);
  }
}

async function openFile(file: File) {
  try {
    if (file.name.toLowerCase().endsWith('.json')) {
      setReference(readReference(await file.text(), null, null));
      state.mode = 'overlay';
      redraw();
      void loadFontsAndRepaint();
      message(`Reference ${file.name} loaded`);
      return;
    }
    openScore(new Uint8Array(await file.arrayBuffer()), file.name, null);
    ui.sample.value = '';
  } catch (err) {
    message(`Cannot open ${file.name}: ${String(err)}`, true);
  }
}

function save() {
  if (!state.score) return;
  const blob = new Blob([state.score.save() as Uint8Array<ArrayBuffer>], { type: 'application/octet-stream' });
  const link = Object.assign(document.createElement('a'), { href: URL.createObjectURL(blob), download: state.fileName || 'score.mus' });
  link.click();
  URL.revokeObjectURL(link.href);
  state.modified = false;
  refreshStatus();
}

function setMode(mode: Mode) {
  state.mode = mode;
  redraw();
}

/** The item under the pointer in the Rust list, else in the engine list (when the fixture attributes items). */
function itemAt(clientX: number, clientY: number): number | null {
  const p = view.pageAt(clientX, clientY);
  const tolerance = view.unitsPerCss(CLICK_TOLERANCE_PX);
  const rust = state.mode !== 'engine' ? state.score?.hitTest(p.x, p.y, tolerance) : undefined;
  const engine = state.mode !== 'rust' ? state.reference?.engine.hitTest(p.x, p.y, tolerance) : undefined;
  return rust ?? engine ?? null;
}

function bindPointer() {
  bindInteraction(ui.viewport, {
    editor: () => state.editor,
    itemAt,
    pageAt: (x, y) => view.pageAt(x, y),
    selected: selectionChanged,
    edited,
    failed,
    command: runCommand,
  });
  ui.viewport.addEventListener('pointermove', (e) => {
    const p = view.pageAt(e.clientX, e.clientY);
    ui.cursor.textContent = `x ${Math.round(p.x)}  y ${Math.round(p.y)}  (${(p.x / 4000).toFixed(3)} in, ${(p.y / 4000).toFixed(3)} in)`;
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
    if (file) void openFile(file);
  });
}

function bindControls(samples: Sample[]) {
  ui.open.addEventListener('click', () => ui.file.click());
  ui.file.addEventListener('change', () => {
    const file = ui.file.files?.[0];
    if (file) void openFile(file);
    ui.file.value = '';
  });
  ui.sample.addEventListener('change', () => {
    const sample = samples.find((s) => s.url === ui.sample.value);
    if (sample) void openSample(sample);
  });
  ui.save.addEventListener('click', save);
  ui.zoomIn.addEventListener('click', () => view.setZoom(stepZoom(view.zoom, 1)));
  ui.zoomOut.addEventListener('click', () => view.setZoom(stepZoom(view.zoom, -1)));
  ui.zoom.addEventListener('change', () => view.setZoom(Number(ui.zoom.value)));
  ui.fit.addEventListener('click', () => view.fitWidth());
  ui.mode.addEventListener('click', (e) => {
    const mode = (e.target as HTMLElement).closest<HTMLButtonElement>('button')?.dataset.mode as Mode | undefined;
    if (mode) setMode(mode);
  });
  ui.undo.addEventListener('click', () => edit((editor) => editor.undo()));
  ui.input.addEventListener('click', () => void enterInput());
  ui.redo.addEventListener('click', () => edit((editor) => editor.redo()));
  bindCommandBar(ui.command, { run: runCommand, page: ui.viewport });
  ui.palette.addEventListener('click', () => ui.viewport.focus());
  window.addEventListener('keydown', (e) => {
    if (e.target instanceof HTMLInputElement || e.metaKey || e.ctrlKey) return;
    if (e.key === '+' || e.key === '=') view.setZoom(stepZoom(view.zoom, 1));
    if (e.key === '_') view.setZoom(stepZoom(view.zoom, -1));
  });
  bindPointer();
  bindDrop();
}

/** URL parameters for direct links and screenshots: sample, mode, zoom, select. */
async function applyQuery(samples: Sample[]) {
  const query = new URLSearchParams(location.search);
  const wanted = query.get('sample');
  const sample = samples.find((s) => s.title === wanted || s.case === wanted) ?? samples.find((s) => s.title === 'carmen.mus') ?? samples[0];
  if (sample) {
    ui.sample.value = sample.url;
    await openSample(sample);
  }
  const mode = query.get('mode') as Mode | null;
  if (mode === 'rust' || mode === 'engine' || mode === 'overlay') setMode(mode);
  const zoom = Number(query.get('zoom'));
  if (zoom > 0) view.setZoom(zoom);
  const selected = query.get('select');
  if (selected !== null) select(selected.split(',').map(Number), true);
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
  const samples = await loadSamples();
  ui.sample.replaceChildren(new Option('Samples…', ''), ...samples.map((s) => new Option(s.title, s.url)));
  bindControls(samples);
  refreshStatus();
  renderItem(ui.item, null, handlers);
  await applyQuery(samples);
}

main().catch((err) => fatal('The app failed to start.', err));
