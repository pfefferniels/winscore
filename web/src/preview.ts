// The preview of an insertion mode, on a canvas of its own over the page,
// so that following the pointer repaints only it: where the new item would
// go (a note head with its ledger lines, a slur's arc from where the drag
// began, a new staff's lines …) in the accent colour, and what it would be.
import { paintPill } from './handles';
import type { Look } from './tools';
import { toDevice, type Point, type Transform } from './view';

export interface Sketch {
  look: Look;
  /** Where it starts, at its level (page coordinates). */
  from: Point;
  /** Where a span or reach ends; null for a point. */
  to: Point | null;
  /** One scale step on its staff, in page units. */
  step: number;
  /** Ledger lines a note needs, as page y. */
  ledgers: number[];
  /** A new staff's lines, as page y, from x0 to x1. */
  lines: number[];
  x0: number;
  x1: number;
  label: string;
  /** The pointer, where the label goes. */
  cursor: Point;
}

const INK = 'rgb(37 99 235 / 0.8)';
const FILL = 'rgb(37 99 235 / 0.55)';

export interface Preview {
  show(sketch: Sketch | null): void;
  /** Draws again after the page moved under it (scroll, zoom). */
  repaint(): void;
}

/** A canvas laid over `page` (the page's canvas) in `stage`, drawing with the page's transform. */
export function createPreview(stage: HTMLElement, page: HTMLCanvasElement, transform: () => Transform): Preview {
  const canvas = document.createElement('canvas');
  canvas.className = 'preview';
  canvas.setAttribute('aria-hidden', 'true');
  page.after(canvas);
  const ctx = canvas.getContext('2d')!;
  let sketch: Sketch | null = null;
  let frame = 0;

  const draw = () => {
    frame = 0;
    if (canvas.width !== page.width || canvas.height !== page.height) {
      canvas.width = page.width;
      canvas.height = page.height;
    }
    canvas.style.width = page.style.width;
    canvas.style.height = page.style.height;
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    if (sketch) paintSketch(ctx, transform(), sketch, window.devicePixelRatio || 1);
  };
  const repaint = () => {
    if (frame === 0) frame = requestAnimationFrame(draw);
  };
  stage.dataset.preview = '';
  return {
    show(next) {
      sketch = next;
      stage.dataset.preview = next?.label ?? '';
      repaint();
    },
    repaint,
  };
}

function paintSketch(ctx: CanvasRenderingContext2D, t: Transform, s: Sketch, dpr: number) {
  const p = (q: Point) => toDevice(t, q.x, q.y);
  const step = s.step * t.k;
  const from = p(s.from);
  const to = s.to ? p(s.to) : null;
  ctx.save();
  ctx.strokeStyle = INK;
  ctx.fillStyle = FILL;
  ctx.lineWidth = Math.max(1, 1.5 * dpr);
  ctx.lineCap = 'round';
  const line = (a: Point, b: Point) => {
    ctx.beginPath();
    ctx.moveTo(a.x, a.y);
    ctx.lineTo(b.x, b.y);
    ctx.stroke();
  };
  const mark = (at: Point) => {
    const r = 4 * dpr;
    ctx.beginPath();
    ctx.arc(at.x, at.y, r, 0, 2 * Math.PI);
    ctx.fill();
    line({ x: at.x - 3 * r, y: at.y }, { x: at.x - 1.6 * r, y: at.y });
    line({ x: at.x + 1.6 * r, y: at.y }, { x: at.x + 3 * r, y: at.y });
    line({ x: at.x, y: at.y - 3 * r }, { x: at.x, y: at.y - 1.6 * r });
    line({ x: at.x, y: at.y + 1.6 * r }, { x: at.x, y: at.y + 3 * r });
  };
  switch (s.look) {
    case 'head': {
      const rx = Math.max(3 * dpr, 1.3 * step);
      const ry = Math.max(2.2 * dpr, 0.92 * step);
      for (const y of s.ledgers) {
        const at = p({ x: s.from.x, y });
        line({ x: at.x - 1.9 * rx, y: at.y }, { x: at.x + 1.9 * rx, y: at.y });
      }
      ctx.beginPath();
      ctx.ellipse(from.x, from.y, rx, ry, (-20 * Math.PI) / 180, 0, 2 * Math.PI);
      ctx.fill();
      ctx.stroke();
      break;
    }
    case 'text': {
      const h = Math.max(10 * dpr, 3 * step);
      line({ x: from.x, y: from.y - h }, from);
      line({ x: from.x - h / 5, y: from.y - h }, { x: from.x + h / 5, y: from.y - h });
      line({ x: from.x - h / 5, y: from.y }, { x: from.x + h / 5, y: from.y });
      break;
    }
    case 'staff': {
      for (const y of s.lines) line(p({ x: s.x0, y }), p({ x: s.x1, y }));
      break;
    }
    case 'barline': {
      ctx.lineWidth = Math.max(2 * dpr, 0.35 * step);
      line(from, to ?? from);
      break;
    }
    default: {
      if (!to) {
        mark(from);
        break;
      }
      paintSpan(ctx, s.look, from, to, step, dpr, line);
    }
  }
  ctx.restore();
  if (s.label) {
    const c = p(s.cursor);
    paintPill(ctx, s.label, { x: c.x + 16 * dpr, y: c.y + 22 * dpr }, dpr, 'rgb(37 99 235)');
  }
}

function paintSpan(ctx: CanvasRenderingContext2D, look: Look, from: Point, to: Point, step: number, dpr: number, line: (a: Point, b: Point) => void) {
  const open = Math.max(4 * dpr, 1.6 * step);
  switch (look) {
    case 'arc-up':
    case 'arc-down': {
      const rise = Math.max(6 * dpr, Math.min(4 * step, 0.18 * Math.hypot(to.x - from.x, to.y - from.y)));
      const sign = look === 'arc-up' ? -1 : 1;
      ctx.beginPath();
      ctx.moveTo(from.x, from.y);
      ctx.quadraticCurveTo((from.x + to.x) / 2, (from.y + to.y) / 2 + sign * 2 * rise, to.x, to.y);
      ctx.lineWidth = Math.max(1.5 * dpr, 0.3 * step);
      ctx.stroke();
      break;
    }
    case 'bracket':
      ctx.beginPath();
      ctx.moveTo(from.x, from.y + 2 * open);
      ctx.lineTo(from.x, from.y);
      ctx.lineTo(to.x, to.y);
      ctx.stroke();
      break;
    case 'wedge-open':
      line(from, { x: to.x, y: to.y - open });
      line(from, { x: to.x, y: to.y + open });
      break;
    case 'wedge-close':
      line({ x: from.x, y: from.y - open }, to);
      line({ x: from.x, y: from.y + open }, to);
      break;
    case 'beam':
      ctx.lineWidth = Math.max(3 * dpr, step);
      ctx.lineCap = 'butt';
      line(from, to);
      break;
    case 'dashed':
      ctx.setLineDash([6 * dpr, 4 * dpr]);
      line(from, to);
      break;
    default:
      line(from, to);
  }
}
