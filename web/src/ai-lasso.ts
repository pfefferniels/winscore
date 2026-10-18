// The lasso: a free shape drawn around music, the items it takes in, and its
// drawing over the page.
import type { Box } from './display';
import { toDevice, type Point, type Transform } from './view';

const STAFF = 8;

/** Whether `p` lies inside the closed shape `points` (even-odd rule). */
export function inside(p: Point, points: Point[]): boolean {
  let within = false;
  for (let i = 0, j = points.length - 1; i < points.length; j = i++) {
    const a = points[i]!;
    const b = points[j]!;
    if (a.y > p.y !== b.y > p.y && p.x < ((b.x - a.x) * (p.y - a.y)) / (b.y - a.y) + a.x) within = !within;
  }
  return within;
}

/**
 * The items a lasso takes in: those whose drawing has its middle inside it.
 * A staff only when the lasso goes around all of it, as the music on it is
 * meant more often than the staff.
 */
export function lassoItems(points: Point[], boxes: (Box | null)[], codes: number[]): number[] {
  const corners = (b: Box) => [
    { x: b.x0, y: b.y0 },
    { x: b.x1, y: b.y0 },
    { x: b.x0, y: b.y1 },
    { x: b.x1, y: b.y1 },
  ];
  return boxes.flatMap((box, i) => {
    if (!box) return [];
    if (codes[i] === STAFF) return corners(box).every((c) => inside(c, points)) ? [i] : [];
    return inside({ x: (box.x0 + box.x1) / 2, y: (box.y0 + box.y1) / 2 }, points) ? [i] : [];
  });
}

export function boundsOf(points: Point[]): Box {
  const xs = points.map((p) => p.x);
  const ys = points.map((p) => p.y);
  return { x0: Math.min(...xs), y0: Math.min(...ys), x1: Math.max(...xs), y1: Math.max(...ys) };
}

/** The lasso being drawn, closed back to its start. */
export function paintLasso(ctx: CanvasRenderingContext2D, t: Transform, points: Point[], dpr: number) {
  if (points.length < 2) return;
  ctx.save();
  ctx.beginPath();
  points.forEach((p, i) => {
    const d = toDevice(t, p.x, p.y);
    if (i === 0) ctx.moveTo(d.x, d.y);
    else ctx.lineTo(d.x, d.y);
  });
  ctx.closePath();
  ctx.fillStyle = 'rgb(124 58 237 / 0.07)';
  ctx.fill();
  ctx.setLineDash([5 * dpr, 4 * dpr]);
  ctx.lineWidth = 1.5 * dpr;
  ctx.strokeStyle = '#7c3aed';
  ctx.stroke();
  ctx.restore();
}
