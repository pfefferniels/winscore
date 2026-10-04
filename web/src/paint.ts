// Replays display lists on a canvas the way WinScore's CWScoreView::OnDraw
// (0x5E5910) replays them with GDI: filled objects with the even-odd rule
// (PolyPolygon, ALTERNATE), polylines with a pen one device pixel wide, text
// placed by the top-left of its character cell. Drawing happens in device
// pixels so lines stay crisp at any devicePixelRatio.
import { elementsOf, type Box, type DisplayList, type Shape, type TextRun } from './display';
import { cssFont, face } from './fonts';
import { toDevice, type Transform } from './view';

export interface Layer {
  list: DisplayList;
  /** Paint every element in this colour instead of its own. */
  tint?: string;
  composite?: GlobalCompositeOperation;
}

export interface Scene {
  transform: Transform;
  paper: Box;
  layers: Layer[];
  /** Item whose elements in `list` are drawn highlighted. */
  highlight: { list: DisplayList; item: number } | null;
  /**
   * Also stroke the outline of filled objects with a one-pixel pen, as GDI's
   * Polygon does when a pen is selected. Keeps hairline fills visible.
   */
  outlineFills: boolean;
}

const BACKGROUND = '#f3f4f6';
const PAPER = '#ffffff';
const PAPER_EDGE = '#d1d5db';
const HIGHLIGHT = '#2563eb';

function hex(colour: number): string {
  return `#${colour.toString(16).padStart(6, '0')}`;
}

function rgb([r, g, b]: [number, number, number]): string {
  return `rgb(${r} ${g} ${b})`;
}

/** Points snapped to pixel centres (polylines) or pixel corners (fills). */
function tracePath(ctx: CanvasRenderingContext2D, t: Transform, path: Int32Array, centre: number, close: boolean) {
  const at = (i: number) => toDevice(t, path[i]!, path[i + 1]!);
  const snap = (v: number) => Math.round(v - centre) + centre;
  const first = at(0);
  ctx.moveTo(snap(first.x), snap(first.y));
  for (let i = 2; i + 1 < path.length; i += 2) {
    const p = at(i);
    ctx.lineTo(snap(p.x), snap(p.y));
  }
  if (close) ctx.closePath();
}

function paintShape(ctx: CanvasRenderingContext2D, t: Transform, shape: Shape, colour: string, outline: boolean) {
  ctx.beginPath();
  const centre = shape.fill && !outline ? 0 : 0.5;
  shape.paths.forEach((path) => tracePath(ctx, t, path, centre, shape.fill));
  if (shape.fill) {
    ctx.fillStyle = colour;
    ctx.fill('evenodd');
  }
  if (!shape.fill || outline) {
    ctx.strokeStyle = colour;
    ctx.stroke();
  }
}

function paintText(ctx: CanvasRenderingContext2D, t: Transform, run: TextRun, colour: string) {
  const size = run.height * t.k;
  if (size < 0.5) return;
  const ascent = face(run.font).ascent * size;
  const angle = (-run.escapement / 10) * (Math.PI / 180);
  ctx.font = cssFont(run, size);
  ctx.fillStyle = colour;
  run.strings.forEach((s) => {
    const origin = toDevice(t, s.x, s.y);
    ctx.save();
    ctx.translate(origin.x, origin.y);
    if (angle !== 0) ctx.rotate(angle);
    ctx.fillText(s.text, 0, ascent);
    if (run.underline) {
      const thickness = Math.max(1, size / 20);
      ctx.fillRect(0, ascent + size / 10, ctx.measureText(s.text).width, thickness);
    }
    ctx.restore();
  });
}

function paintList(ctx: CanvasRenderingContext2D, t: Transform, list: DisplayList, tint: string | null, outline: boolean) {
  list.shapes.forEach((shape) => paintShape(ctx, t, shape, tint ?? hex(shape.colour), outline));
  list.texts.forEach((run) => paintText(ctx, t, run, tint ?? rgb(run.colour)));
}

function paintPaper(ctx: CanvasRenderingContext2D, t: Transform, paper: Box) {
  const a = toDevice(t, paper.x0, paper.y1);
  const b = toDevice(t, paper.x1, paper.y0);
  const x = Math.round(a.x);
  const y = Math.round(a.y);
  const w = Math.round(b.x) - x;
  const h = Math.round(b.y) - y;
  ctx.fillStyle = PAPER;
  ctx.fillRect(x, y, w, h);
  ctx.strokeStyle = PAPER_EDGE;
  ctx.strokeRect(x - 0.5, y - 0.5, w + 1, h + 1);
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
  paintPaper(ctx, t, scene.paper);
  scene.layers.forEach((layer) => {
    ctx.globalCompositeOperation = layer.composite ?? 'source-over';
    paintList(ctx, t, layer.list, layer.tint ?? null, scene.outlineFills);
  });
  ctx.globalCompositeOperation = 'source-over';
  if (scene.highlight) {
    paintList(ctx, t, elementsOf(scene.highlight.list, scene.highlight.item), HIGHLIGHT, scene.outlineFills);
  }
}
