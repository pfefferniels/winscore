// Replays display lists on a canvas the way WinScore's CWScoreView::OnDraw
// (0x5E5910) replays them with GDI (analysis/engine/display.md): polylines
// with a pen one device pixel wide; filled objects with the even-odd rule
// (PolyPolygon, ALTERNATE) and outlined with that same pen; text on the
// baseline at the engine's y + 96, stretched to the run's average width.
// Drawing happens in device pixels so lines stay crisp at any
// devicePixelRatio.
import { elementsOf, type Box, type DisplayList, type Shape, type TextRun } from './display';
import { ascent, cssFont, stretch } from './fonts';
import { toDevice, type Transform } from './view';

export interface Layer {
  list: DisplayList;
  /** Paint every element in this colour instead of its own. */
  tint?: string;
  composite?: GlobalCompositeOperation;
}

/** An item whose elements in `list` are drawn highlighted. */
export interface Highlight {
  list: DisplayList;
  item: number;
}

export interface Scene {
  transform: Transform;
  paper: Box;
  layers: Layer[];
  highlights: Highlight[];
}

const BACKGROUND = '#ffffff';
/** The engine's page frame colour (COLORREF 0x00FD00). */
const FRAME = 'rgb(0 253 0)';
/** The engine's three nested frame rectangles, inset from the paper edge. */
const FRAME_INSETS = [1, -24, -49];
const HIGHLIGHT = '#2563eb';

function hex(colour: number): string {
  return `#${colour.toString(16).padStart(6, '0')}`;
}

function rgb([r, g, b]: [number, number, number]): string {
  return `rgb(${r} ${g} ${b})`;
}

/** Points snapped to device pixel centres, where a one-pixel pen is crisp. */
function tracePath(ctx: CanvasRenderingContext2D, t: Transform, path: Int32Array, close: boolean) {
  const at = (i: number) => toDevice(t, path[i]!, path[i + 1]!);
  const snap = (v: number) => Math.round(v - 0.5) + 0.5;
  const first = at(0);
  ctx.moveTo(snap(first.x), snap(first.y));
  for (let i = 2; i + 1 < path.length; i += 2) {
    const p = at(i);
    ctx.lineTo(snap(p.x), snap(p.y));
  }
  if (close) ctx.closePath();
}

function paintShape(ctx: CanvasRenderingContext2D, t: Transform, shape: Shape, colour: string) {
  ctx.beginPath();
  shape.paths.forEach((path) => tracePath(ctx, t, path, shape.fill));
  if (shape.fill) {
    ctx.fillStyle = colour;
    ctx.fill('evenodd');
  }
  ctx.strokeStyle = colour;
  ctx.stroke();
}

/**
 * Rotation of a run's glyphs: clockwise by escapement/10 degrees, following
 * the clockwise line on which the engine places the characters
 * (escapement = 10 × P9, analysis/engine/display.md §3.4). How GDI turns
 * glyphs in a y-up mapping is inferred, not observed on Windows.
 */
function glyphAngle(run: TextRun): number {
  return (run.escapement / 10) * (Math.PI / 180);
}

function paintText(ctx: CanvasRenderingContext2D, t: Transform, run: TextRun, colour: string) {
  const size = run.height * t.k;
  if (size < 0.5) return;
  const angle = glyphAngle(run);
  const scaleX = stretch(run);
  // GDI turns text about the cell's top-left corner, one ascent above the baseline.
  const drop = ascent(run) * t.k;
  ctx.font = cssFont(run, size);
  ctx.fillStyle = colour;
  run.strings.forEach((s) => {
    const origin = toDevice(t, s.x, s.y);
    ctx.save();
    ctx.translate(Math.round(origin.x), Math.round(origin.y) - drop);
    if (angle !== 0) ctx.rotate(angle);
    ctx.translate(0, drop);
    ctx.scale(scaleX, 1);
    ctx.fillText(s.text, 0, 0);
    if (run.underline) {
      ctx.fillRect(0, size / 10, ctx.measureText(s.text).width, Math.max(1, size / 20));
    }
    ctx.restore();
  });
}

function paintList(ctx: CanvasRenderingContext2D, t: Transform, list: DisplayList, tint: string | null) {
  list.shapes.forEach((shape) => paintShape(ctx, t, shape, tint ?? hex(shape.colour)));
  list.texts.forEach((run) => paintText(ctx, t, run, tint ?? rgb(run.colour)));
}

/** WinScore's page frame: three green rectangles around the paper edge, drawn by the engine. */
function paintFrame(ctx: CanvasRenderingContext2D, t: Transform, paper: Box) {
  ctx.beginPath();
  FRAME_INSETS.forEach((d) => {
    const rect = [paper.x0 + d, paper.y0 + d, paper.x1 - d, paper.y0 + d, paper.x1 - d, paper.y1 - d, paper.x0 + d, paper.y1 - d];
    tracePath(ctx, t, Int32Array.from(rect), true);
  });
  ctx.strokeStyle = FRAME;
  ctx.stroke();
}

/** Paints the page for print: white paper filling the canvas, no screen aids. */
export function paintPrint(ctx: CanvasRenderingContext2D, list: DisplayList, paper: Box) {
  const { width, height } = ctx.canvas;
  const k = width / (paper.x1 - paper.x0);
  const t: Transform = { k, ox: -paper.x0 * k, oy: height + paper.y0 * k };
  ctx.setTransform(1, 0, 0, 1, 0, 0);
  ctx.fillStyle = BACKGROUND;
  ctx.fillRect(0, 0, width, height);
  // A one-logical-unit pen under MM_HIENGLISH: 0.001 in, at least a device pixel.
  ctx.lineWidth = Math.max(1, k * 4);
  ctx.textBaseline = 'alphabetic';
  paintList(ctx, t, list, null);
}

/** Paints `list` scaled to fit the canvas with a margin, for previews. */
export function paintThumbnail(ctx: CanvasRenderingContext2D, list: DisplayList, box: Box) {
  const { width, height } = ctx.canvas;
  const margin = 0.15;
  const k = Math.min(width / (box.x1 - box.x0 || 1), height / (box.y1 - box.y0 || 1)) * (1 - 2 * margin);
  const t: Transform = {
    k,
    ox: (width - (box.x1 - box.x0) * k) / 2 - box.x0 * k,
    oy: (height + (box.y1 - box.y0) * k) / 2 + box.y0 * k,
  };
  ctx.setTransform(1, 0, 0, 1, 0, 0);
  ctx.clearRect(0, 0, width, height);
  ctx.lineWidth = 1;
  ctx.textBaseline = 'alphabetic';
  paintList(ctx, t, list, null);
}

export function paint(ctx: CanvasRenderingContext2D, scene: Scene) {
  const { width, height } = ctx.canvas;
  const t = scene.transform;
  ctx.setTransform(1, 0, 0, 1, 0, 0);
  ctx.globalCompositeOperation = 'source-over';
  ctx.fillStyle = BACKGROUND;
  ctx.fillRect(0, 0, width, height);
  ctx.lineWidth = 1;
  ctx.lineJoin = 'miter';
  ctx.lineCap = 'butt';
  ctx.textBaseline = 'alphabetic';
  paintFrame(ctx, t, scene.paper);
  scene.layers.forEach((layer) => {
    ctx.globalCompositeOperation = layer.composite ?? 'source-over';
    paintList(ctx, t, layer.list, layer.tint ?? null);
  });
  ctx.globalCompositeOperation = 'source-over';
  scene.highlights.forEach(({ list, item }) => paintList(ctx, t, elementsOf(list, item), HIGHLIGHT));
}
