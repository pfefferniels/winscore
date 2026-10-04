import './style.css';
import init, { parseReference, Score, type EncodedList } from './wasm/score_web.js';
import { createPageView, type Scene } from './canvas';
import { bounds, decode, EMPTY, union, type Box, type DisplayList } from './display';
import { loadFaces } from './fonts';
import { markSelected, renderItem, renderItemList, type ItemDetails, type ItemSummary, type PanelHandlers } from './panel';
import type { Layer } from './paint';
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
  url: string;
  case: string;
  reference: ReferenceInfo | null;
}

interface Reference {
  list: DisplayList;
  pageSize: [number, number] | null;
  note: string | null;
}

interface State {
  score: Score | null;
  fileName: string;
  rust: DisplayList;
  reference: Reference | null;
  mode: Mode;
  selected: number | null;
  modified: boolean;
}

const MARGIN = 1000;
const CLICK_TOLERANCE_PX = 4;
const ENGINE_TINT = '#06b6d4';
const RUST_TINT = '#e11d74';

const $ = <T extends HTMLElement>(id: string) => document.getElementById(id) as T;

const ui = {
  open: $<HTMLButtonElement>('open'),
  file: $<HTMLInputElement>('file'),
  sample: $<HTMLSelectElement>('sample'),
  save: $<HTMLButtonElement>('save'),
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
};

const state: State = { score: null, fileName: '', rust: EMPTY, reference: null, mode: 'rust', selected: null, modified: false };

const view = createPageView(ui, showZoom);

function showZoom(zoom: number) {
  const rounded = Math.round(zoom);
  const options = [...new Set([...ZOOM_LEVELS, rounded])].sort((a, b) => a - b);
  ui.zoom.replaceChildren(...options.map((z) => new Option(`${z} %`, String(z), false, z === rounded)));
}

function message(text: string, error = false) {
  ui.message.textContent = text;
  ui.message.classList.toggle('error', error);
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

function scene(): Scene {
  const paper = paperBox();
  const showsRust = state.mode !== 'engine';
  return {
    layers: layers(),
    paper,
    extent: extent(paper),
    highlight: showsRust && state.selected !== null ? { list: state.rust, item: state.selected } : null,
  };
}

function refreshStatus() {
  const items = state.score?.itemCount() ?? 0;
  ui.status.textContent = state.score ? `${state.fileName}${state.modified ? ' (modified)' : ''} · ${items} items` : '';
  ui.save.disabled = !state.score;
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
      text: info.text ?? null,
      drawn: state.rust.shapes.some((s) => s.source === index) || state.rust.texts.some((t) => t.source === index),
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

function refreshPanel() {
  renderItem(ui.item, state.score && state.selected !== null ? details(state.score, state.selected) : null, handlers);
  markSelected(ui.items, state.selected);
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

function select(index: number | null) {
  state.selected = index;
  refreshPanel();
  redraw();
}

function setParam(index: number, n: number, value: number) {
  const score = state.score;
  if (!score) return;
  try {
    score.setParam(index, n, value);
  } catch (err) {
    message(String(err), true);
    return;
  }
  state.rust = decodeAndFree(score.render());
  state.modified = true;
  refreshItemList();
  refreshPanel();
  redraw();
  void loadFontsAndRepaint();
  message(`Item ${index}: P${n} = ${value}`);
}

const handlers: PanelHandlers = { select, setParam };

async function fetchReference(info: ReferenceInfo): Promise<Reference> {
  const json = await (await fetch(info.url)).text();
  const note = info.valid ? null : `engine reference marked invalid: ${info.invalidReasons.join('; ')}`;
  return { list: decodeAndFree(parseReference(json)), pageSize: info.pageSize, note };
}

function openScore(bytes: Uint8Array, name: string, reference: Reference | null) {
  const score = new Score(bytes);
  state.score?.free();
  state.score = score;
  state.fileName = name;
  state.rust = decodeAndFree(score.render());
  state.reference = reference;
  state.selected = null;
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
    const bytes = new Uint8Array(await (await fetch(sample.url)).arrayBuffer());
    const reference = sample.reference ? await fetchReference(sample.reference) : null;
    openScore(bytes, sample.title, reference);
  } catch (err) {
    message(`Cannot open ${sample.title}: ${String(err)}`, true);
  }
}

async function openFile(file: File) {
  try {
    if (file.name.toLowerCase().endsWith('.json')) {
      const list = decodeAndFree(parseReference(await file.text()));
      state.reference = { list, pageSize: null, note: null };
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

function clickTarget(e: MouseEvent): number | null {
  if (!state.score || state.mode === 'engine') return null;
  const p = view.pageAt(e.clientX, e.clientY);
  return state.score.hitTest(p.x, p.y, view.unitsPerCss(CLICK_TOLERANCE_PX)) ?? null;
}

function bindPointer() {
  let down: { x: number; y: number } | null = null;
  ui.viewport.addEventListener('pointerdown', (e) => {
    down = { x: e.clientX, y: e.clientY };
  });
  ui.viewport.addEventListener('pointerup', (e) => {
    const moved = down ? Math.hypot(e.clientX - down.x, e.clientY - down.y) : Infinity;
    down = null;
    if (moved <= 4 && e.button === 0) select(clickTarget(e));
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
  window.addEventListener('keydown', (e) => {
    if (e.target instanceof HTMLInputElement) return;
    if (e.key === '+' || e.key === '=') view.setZoom(stepZoom(view.zoom, 1));
    if (e.key === '-') view.setZoom(stepZoom(view.zoom, -1));
    if (e.key === 'Escape') select(null);
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
  if (selected !== null) select(Number(selected));
  await loadFontsAndRepaint();
  document.body.dataset.ready = 'true';
}

async function main() {
  await init();
  showZoom(view.zoom);
  const samples = (await (await fetch('samples/index.json')).json()) as Sample[];
  ui.sample.replaceChildren(new Option('Samples…', ''), ...samples.map((s) => new Option(s.title, s.url)));
  bindControls(samples);
  refreshStatus();
  renderItem(ui.item, null, handlers);
  await applyQuery(samples);
}

main().catch((err) => message(String(err), true));
