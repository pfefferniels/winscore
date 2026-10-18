// Paints display lists on a canvas the way SCORE draws them on paper, after
// the prologue of WinScore's PostScript output: polylines with a pen of
// physical width, the shape's own or 1/150 inch (`wdl lw`), round joins
// (`1 setlinejoin`) and butt caps; filled objects with the even-odd rule and
// then outlined with that same pen (`gsave eofill grestore stroke`); text on
// its baseline at the engine's y + 96, stretched to the run's average width
// as GDI does. Pens scale with the zoom. Drawing happens in device pixels;
// horizontal and vertical shapes are snapped to them as the prologue's stroke
// adjustment snaps them, so staff lines, stems and barlines stay crisp, and
// curved and slanted outlines are antialiased.
import { elementsOf, type Box, type DisplayList, type Shape, type TextRun } from './display';
import { ascent, cssFont, stretch } from './fonts';
import { toDevice, UNITS_PER_INCH, type Transform } from './view';

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
  /** Default: the selection's colour. */
  colour?: string;
}

/** Drawn over the page in device pixels, after the highlights: handles, guides, readouts. */
export type Overlay = (ctx: CanvasRenderingContext2D, t: Transform) => void;

export interface Scene {
  transform: Transform;
  paper: Box;
  layers: Layer[];
  highlights: Highlight[];
  overlays?: Overlay[];
}

/** The default pen in engine units, score_render::PEN: 1/150 inch, SCORE's PostScript `wdl lw`. */
const PEN = UNITS_PER_INCH / 150;
/** Around the paper: a quiet grey a step darker than the app's chrome (style.css `--chrome`, `--border`). */
const DESK = '#eceef2';
const PAPER = '#ffffff';
/** The paper's edge and shadow on the desk; sizes in CSS pixels. */
const PAPER_EDGE = 'rgb(15 23 42 / 0.14)';
const PAPER_SHADOW = 'rgb(15 23 42 / 0.12)';
const SHADOW_BLUR = 6;
const SHADOW_DROP = 1;
const HIGHLIGHT = '#2563eb';

function hex(colour: number): string {
  return `#${colour.toString(16).padStart(6, '0')}`;
}

function rgb([r, g, b]: [number, number, number]): string {
  return `rgb(${r} ${g} ${b})`;
}

/** Whether every segment of `path` (with its closing one) is horizontal or vertical. */
function isRectilinear(path: Int32Array, close: boolean): boolean {
  for (let i = 2; i + 1 < path.length; i += 2) {
    if (path[i] !== path[i - 2] && path[i + 1] !== path[i - 1]) return false;
  }
  const last = path.length - 2;
  return !close || path[0] === path[last] || path[1] === path[last + 1];
}

/** A distance in whole device pixels, at least one where there is any, so thin bars do not vanish. */
function whole(d: number): number {
  return d === 0 ? 0 : Math.sign(d) * Math.max(1, Math.round(Math.abs(d)));
}

/** Device pixels of page coordinates, an axis at a time. */
interface Placement {
  x: (x: number) => number;
  y: (y: number) => number;
}

/**
 * Where `shape`'s points go on the device. Horizontal and vertical shapes
 * (staff lines, stems, barlines, flat beams, rests) are snapped as PostScript's
 * stroke adjustment snaps them, which SCORE's prologue turns on: drawn with a
 * whole number of pixels `pen`, they run along pixel centres for an odd pen
 * and along pixel edges for an even one (or none), so both edges are crisp,
 * and every point lies a whole number of pixels from the shape's first, so
 * equal barlines and beams come out equally wide wherever they lie. Curved and
 * slanted outlines keep their exact positions (`pen` null) and are
 * antialiased: snapped, noteheads, dots and slurs would turn into steps.
 * Snapping moves a line by half a pixel at most, which matters less the wider
 * it is, so it applies at every width.
 */
function placement(t: Transform, shape: Shape, pen: number | null): Placement {
  const x = (x: number) => x * t.k + t.ox;
  const y = (y: number) => t.oy - y * t.k;
  const first = shape.paths[0];
  if (pen === null || !first || first.length < 2) return { x, y };
  const centre = pen % 2 === 1 ? 0.5 : 0;
  const snap = (to: (v: number) => number, origin: number) => {
    const from = to(origin);
    const at = Math.round(from - centre) + centre;
    return (v: number) => at + whole(to(v) - from);
  };
  return { x: snap(x, first[0]!), y: snap(y, first[1]!) };
}

function tracePaths(ctx: CanvasRenderingContext2D, shape: Shape, at: Placement) {
  shape.paths.forEach((path) => {
    if (path.length < 2) return;
    ctx.moveTo(at.x(path[0]!), at.y(path[1]!));
    for (let i = 2; i + 1 < path.length; i += 2) ctx.lineTo(at.x(path[i]!), at.y(path[i + 1]!));
    if (shape.fill) ctx.closePath();
  });
}

/** Page boxes of the shapes, measured once per decoded shape. */
const boxes = new WeakMap<Shape, Box | null>();

function boxOf(shape: Shape): Box | null {
  let [x0, y0, x1, y1] = [Infinity, Infinity, -Infinity, -Infinity];
  for (const path of shape.paths) {
    for (let i = 0; i + 1 < path.length; i += 2) {
      x0 = Math.min(x0, path[i]!);
      x1 = Math.max(x1, path[i]!);
      y0 = Math.min(y0, path[i + 1]!);
      y1 = Math.max(y1, path[i + 1]!);
    }
  }
  return x0 <= x1 ? { x0, y0, x1, y1 } : null;
}

/**
 * Whether `shape`, drawn with a pen `pen` pixels wide, reaches into the
 * canvas. Shapes outside it are not traced at all, which matters when zoomed
 * in: wider pens make every traced outline dearer.
 */
function onCanvas(ctx: CanvasRenderingContext2D, t: Transform, shape: Shape, pen: number): boolean {
  let box = boxes.get(shape);
  if (box === undefined) {
    box = boxOf(shape);
    boxes.set(shape, box);
  }
  if (!box) return false;
  const margin = pen + 2;
  const { width, height } = ctx.canvas;
  return box.x1 * t.k + t.ox > -margin && box.x0 * t.k + t.ox < width + margin && t.oy - box.y0 * t.k > -margin && t.oy - box.y1 * t.k < height + margin;
}

/**
 * The pen of a shape in device pixels, 0 for none. Lines are at least a pixel
 * wide. Fill outlines go down to half a pixel: a whole one closes the gaps
 * between beams at 75 % and less on a 1× screen, while much thinner slurs and
 * the thin strokes of glyphs fade to grey. Pens under one and a half pixels
 * are drawn at most a pixel wide: canvases draw such pens as hairlines, several
 * times faster than wider ones, and the quarter pixel or less this takes off
 * each side does not show. Snapped shapes take whole pixels, as stroke
 * adjustment rounds them, a fill none below half a pixel.
 */
function shapePen(t: Transform, shape: Shape, snapped: boolean): number {
  const pen = (shape.width || PEN) * t.k;
  if (snapped) return Math.max(shape.fill ? 0 : 1, Math.round(pen));
  const drawn = Math.max(shape.fill ? 0.5 : 1, pen);
  return drawn < 1.5 ? Math.min(drawn, 1) : drawn;
}

/** Outward corners that turn further are rounded with several points; smaller turns get a mitre. */
const ARC_STEP = Math.PI / 8;

/**
 * Traces `path`, a closed outline that does not cross itself, placed by `at`
 * and grown by `r` pixels, to be filled with the nonzero rule: what
 * filling the outline and stroking it with a pen 2r wide and round joins
 * covers. Canvases fill that as fast as the outline alone, and several times
 * faster than they stroke with a pen wider than a pixel. Outward corners are
 * rounded; inward ones take the mitre, which is exact there. Where an inward
 * corner needs more of its edges than they have (a notch or a curve narrower
 * than the pen), or the outline does not go round once, it traces nothing and
 * returns false.
 */
function traceGrown(ctx: CanvasRenderingContext2D, path: Int32Array, at: Placement, r: number): boolean {
  const points: number[] = [];
  for (let i = 0; i + 1 < path.length; i += 2) {
    const x = at.x(path[i]!);
    const y = at.y(path[i + 1]!);
    if (points.length === 0 || x !== points[points.length - 2] || y !== points[points.length - 1]) points.push(x, y);
  }
  if (points[0] === points[points.length - 2] && points[1] === points[points.length - 1]) points.length -= 2;
  const n = points.length / 2;
  if (n < 3) return false;
  // The edges as unit vectors, and which way round the outline goes.
  const ux: number[] = [];
  const uy: number[] = [];
  const length: number[] = [];
  let area = 0;
  for (let i = 0; i < n; i++) {
    const j = (i + 1) % n;
    const dx = points[2 * j]! - points[2 * i]!;
    const dy = points[2 * j + 1]! - points[2 * i + 1]!;
    length.push(Math.hypot(dx, dy));
    ux.push(dx / length[i]!);
    uy.push(dy / length[i]!);
    area += points[2 * i]! * points[2 * j + 1]! - points[2 * j]! * points[2 * i + 1]!;
  }
  const sense = Math.sign(area);
  if (sense === 0) return false;
  // How far each corner turns, outward positive, and how much of its edges an inward one takes.
  const sin: number[] = [];
  const cos: number[] = [];
  const taken: number[] = new Array<number>(n).fill(0);
  let turning = 0;
  for (let i = 0; i < n; i++) {
    const h = (i + n - 1) % n;
    sin.push(sense * (ux[h]! * uy[i]! - uy[h]! * ux[i]!));
    cos.push(ux[h]! * ux[i]! + uy[h]! * uy[i]!);
    turning += Math.atan2(sin[i]!, cos[i]!);
    if (sin[i]! < 0) {
      if (cos[i]! < -0.99) return false;
      const cut = (-r * sin[i]!) / (1 + cos[i]!);
      taken[h] = taken[h]! + cut;
      taken[i] = taken[i]! + cut;
    }
  }
  if (Math.abs(turning - 2 * Math.PI) > 0.1 || taken.some((cut, i) => cut >= length[i]!)) return false;
  let started = false;
  const to = (x: number, y: number) => {
    if (started) ctx.lineTo(x, y);
    else ctx.moveTo(x, y);
    started = true;
  };
  for (let i = 0; i < n; i++) {
    const h = (i + n - 1) % n;
    const x = points[2 * i]!;
    const y = points[2 * i + 1]!;
    // Outward normals of the edges before and after the corner.
    const ax = sense * uy[h]!;
    const ay = -sense * ux[h]!;
    const bx = sense * uy[i]!;
    const by = -sense * ux[i]!;
    const turn = Math.atan2(sin[i]!, cos[i]!);
    if (turn <= ARC_STEP) {
      const m = r / (1 + cos[i]!);
      to(x + m * (ax + bx), y + m * (ay + by));
      continue;
    }
    const steps = Math.ceil(turn / ARC_STEP);
    for (let k = 0; k <= steps; k++) {
      const a = (sense * turn * k) / steps;
      to(x + r * (ax * Math.cos(a) - ay * Math.sin(a)), y + r * (ax * Math.sin(a) + ay * Math.cos(a)));
    }
  }
  ctx.closePath();
  return true;
}

function paintShape(ctx: CanvasRenderingContext2D, t: Transform, shape: Shape, colour: string) {
  const snapped = shape.paths.every((path) => isRectilinear(path, shape.fill));
  const pen = shapePen(t, shape, snapped);
  if (!onCanvas(ctx, t, shape, pen)) return;
  const at = placement(t, shape, snapped ? pen : null);
  ctx.beginPath();
  const [outline] = shape.paths;
  if (shape.fill && pen > 1 && shape.paths.length === 1 && outline && traceGrown(ctx, outline, at, pen / 2)) {
    ctx.fillStyle = colour;
    ctx.fill();
    return;
  }
  tracePaths(ctx, shape, at);
  if (shape.fill) {
    ctx.fillStyle = colour;
    ctx.fill('evenodd');
  }
  if (pen > 0) {
    ctx.lineWidth = pen;
    ctx.strokeStyle = colour;
    ctx.stroke();
  }
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

/** SCORE's line style: round joins (`1 setlinejoin`), PostScript's default butt caps. */
function setPen(ctx: CanvasRenderingContext2D) {
  ctx.lineJoin = 'round';
  ctx.lineCap = 'butt';
  ctx.textBaseline = 'alphabetic';
}

/** White paper on the desk, with a hairline edge and a soft shadow. */
function paintPaper(ctx: CanvasRenderingContext2D, t: Transform, paper: Box) {
  const dpr = globalThis.devicePixelRatio || 1;
  const a = toDevice(t, paper.x0, paper.y1);
  const b = toDevice(t, paper.x1, paper.y0);
  const x = Math.round(a.x);
  const y = Math.round(a.y);
  const width = Math.round(b.x) - x;
  const height = Math.round(b.y) - y;
  ctx.save();
  ctx.shadowColor = PAPER_SHADOW;
  ctx.shadowBlur = SHADOW_BLUR * dpr;
  ctx.shadowOffsetY = SHADOW_DROP * dpr;
  ctx.fillStyle = PAPER;
  ctx.fillRect(x, y, width, height);
  ctx.restore();
  const edge = Math.max(1, Math.round(dpr));
  ctx.lineWidth = edge;
  ctx.strokeStyle = PAPER_EDGE;
  ctx.strokeRect(x - edge / 2, y - edge / 2, width + edge, height + edge);
}

/** Paints the page for print: white paper filling the canvas, no screen aids. */
export function paintPrint(ctx: CanvasRenderingContext2D, list: DisplayList, paper: Box) {
  const { width, height } = ctx.canvas;
  const k = width / (paper.x1 - paper.x0);
  const t: Transform = { k, ox: -paper.x0 * k, oy: height + paper.y0 * k };
  ctx.setTransform(1, 0, 0, 1, 0, 0);
  ctx.fillStyle = PAPER;
  ctx.fillRect(0, 0, width, height);
  setPen(ctx);
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
  setPen(ctx);
  paintList(ctx, t, list, null);
}

export function paint(ctx: CanvasRenderingContext2D, scene: Scene) {
  const { width, height } = ctx.canvas;
  const t = scene.transform;
  ctx.setTransform(1, 0, 0, 1, 0, 0);
  ctx.globalCompositeOperation = 'source-over';
  ctx.fillStyle = DESK;
  ctx.fillRect(0, 0, width, height);
  paintPaper(ctx, t, scene.paper);
  setPen(ctx);
  scene.layers.forEach((layer) => {
    ctx.globalCompositeOperation = layer.composite ?? 'source-over';
    paintList(ctx, t, layer.list, layer.tint ?? null);
  });
  ctx.globalCompositeOperation = 'source-over';
  scene.highlights.forEach(({ list, item, colour }) => paintList(ctx, t, elementsOf(list, item), colour ?? HIGHLIGHT));
  // Overlays draw their own lines, with the canvas defaults.
  ctx.lineWidth = 1;
  ctx.lineJoin = 'miter';
  scene.overlays?.forEach((overlay) => {
    ctx.save();
    overlay(ctx, t);
    ctx.restore();
  });
}
