// Handles on the selected item as score-web works them out
// (rust/crates/score-web/src/handles.rs): where they stand on the screen,
// which one lies under the pointer, the cursor it shows and how it is
// drawn. Four looks, one per kind: round ends (of lines, slurs, beams,
// staves, a barline's top), square size handles on the item's frame, the
// rotation handle on a stalk above it, and amber diamonds for shapes of
// the item's own (curvature, opening, hook, stem, a staff's place, spacing).
import { toDevice, type Point, type Transform } from './view';

export type HandleKind = 'end' | 'scale' | 'rotate' | 'adjust';
export type Axis = 'both' | 'x' | 'y';

export interface Handle {
  /** Its number for the editor's handleBegin. */
  index: number;
  kind: HandleKind;
  /** Page point (for the rotation handle, the top of the frame it stands above). */
  at: Point;
  /** Which way it moves in the item's frame. */
  axis: Axis;
  /** The item's frame, degrees clockwise. */
  turn: number;
  label: string;
  /** Whether it follows the cursor, so that guides may snap it. */
  follows: boolean;
}

export interface HandleSet {
  item: number;
  /** Corners of the item's frame, turned with it. */
  frame: Point[] | null;
  handles: Handle[];
}

interface Encoded {
  frame: [number, number][] | null;
  handles: { kind: HandleKind; x: number; y: number; axis: Axis; turn: number; label: string; follows: boolean }[];
}

export function decodeHandles(item: number, json: string): HandleSet {
  const encoded = JSON.parse(json) as Encoded;
  return {
    item,
    frame: encoded.frame?.map(([x, y]) => ({ x, y })) ?? null,
    handles: encoded.handles.map((h, index) => ({ index, kind: h.kind, at: { x: h.x, y: h.y }, axis: h.axis, turn: h.turn, label: h.label, follows: h.follows })),
  };
}

const ACCENT = '#2563eb';
const ADJUST = '#f59e0b';
const FRAME = 'rgb(37 99 235 / 0.55)';
const PILL = '#111827';
/** CSS pixels from the frame's top to the rotation handle. */
const STALK_PX = 24;
/** Half the size of a handle in CSS pixels, for a mouse and for a finger. */
const SIZE_PX = 4.5;
const COARSE_SIZE_PX = 7;

/** The frame's up direction on the screen (y down) for a frame turned `turn` degrees clockwise. */
function up(turn: number): Point {
  const a = (turn * Math.PI) / 180;
  return { x: Math.sin(a), y: -Math.cos(a) };
}

/** Where a handle is drawn, in device pixels; the rotation handle stands off the frame. */
export function devicePoint(h: Handle, t: Transform, dpr: number): Point {
  const p = toDevice(t, h.at.x, h.at.y);
  if (h.kind !== 'rotate') return p;
  const u = up(h.turn);
  return { x: p.x + u.x * STALK_PX * dpr, y: p.y + u.y * STALK_PX * dpr };
}

/** Side handles sit between the corners; on a frame shorter than this (CSS pixels) along the side they crowd it and are left out. */
const SIDE_ROOM_PX = 40;

/** The handles shown at transform `t`: all but the side handles of a small frame. */
export function visibleHandles(set: HandleSet, t: Transform, dpr: number): Handle[] {
  const corners = set.frame?.map((c) => toDevice(t, c.x, c.y));
  if (!corners) return set.handles;
  const [a, b, c] = corners as [Point, Point, Point];
  const width = Math.hypot(b.x - a.x, b.y - a.y) / dpr;
  const height = Math.hypot(c.x - b.x, c.y - b.y) / dpr;
  return set.handles.filter((h) => h.kind !== 'scale' || h.axis === 'both' || (h.axis === 'x' ? height : width) >= SIDE_ROOM_PX || set.handles.every((o) => o.kind !== 'scale' || o.axis !== 'both'));
}

/** Ends and shapes win over the frame where they overlap; the frame's handles over the rotation. */
const PRECEDENCE: Record<HandleKind, number> = { adjust: 0, end: 1, scale: 2, rotate: 3 };

/** The handle nearest to device point `p` within `radius` device pixels. */
export function handleAt(set: HandleSet, t: Transform, dpr: number, p: Point, radius: number): Handle | null {
  let best: { h: Handle; d: number } | null = null;
  for (const h of visibleHandles(set, t, dpr)) {
    const q = devicePoint(h, t, dpr);
    const d = Math.hypot(q.x - p.x, q.y - p.y);
    if (d > radius) continue;
    const better = !best || d < best.d - dpr || (Math.abs(d - best.d) <= dpr && PRECEDENCE[h.kind] < PRECEDENCE[best.h.kind]);
    if (better) best = { h, d };
  }
  return best?.h ?? null;
}

/** A turning arrow, for the rotation handle. */
const ROTATE_CURSOR = `url("data:image/svg+xml,${encodeURIComponent(
  '<svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24"><g fill="none" stroke-linecap="round" stroke-linejoin="round"><path d="M19 12a7 7 0 1 1-2.05-4.95" stroke="#fff" stroke-width="4"/><path d="M17 3v4.5h-4.5" stroke="#fff" stroke-width="4"/><path d="M19 12a7 7 0 1 1-2.05-4.95" stroke="#111" stroke-width="2"/><path d="M17 3v4.5h-4.5" stroke="#111" stroke-width="2"/></g></svg>',
)}") 12 12, grab`;

const RESIZE = ['ew-resize', 'nwse-resize', 'ns-resize', 'nesw-resize'];

/** The resize cursor along a screen direction, degrees clockwise from the right (y down). */
function resizeCursor(degrees: number): string {
  const sector = Math.round((((degrees % 180) + 180) % 180) / 45) % 4;
  return RESIZE[sector]!;
}

/** The cursor over a handle. Corners point away from the frame's middle. */
export function cursorFor(h: Handle, set: HandleSet): string {
  if (h.kind === 'rotate') return ROTATE_CURSOR;
  if (h.axis === 'x') return resizeCursor(h.turn);
  if (h.axis === 'y') return resizeCursor(h.turn + 90);
  if (h.kind === 'scale' && set.frame) {
    const mid = set.frame.reduce((m, c) => ({ x: m.x + c.x / 4, y: m.y + c.y / 4 }), { x: 0, y: 0 });
    return resizeCursor((Math.atan2(-(h.at.y - mid.y), h.at.x - mid.x) * 180) / Math.PI);
  }
  return 'move';
}

export interface HandleLook {
  set: HandleSet;
  hover: number | null;
  /** The handle being dragged and where it is now (page point); only it is drawn. */
  active: { index: number; at: Point } | null;
  coarse: boolean;
  dpr: number;
}

function shapePath(ctx: CanvasRenderingContext2D, kind: HandleKind, p: Point, r: number) {
  ctx.beginPath();
  if (kind === 'scale') ctx.rect(Math.round(p.x - r) + 0.5, Math.round(p.y - r) + 0.5, Math.round(2 * r), Math.round(2 * r));
  else if (kind === 'adjust') {
    const d = r * 1.3;
    ctx.moveTo(p.x, p.y - d);
    ctx.lineTo(p.x + d, p.y);
    ctx.lineTo(p.x, p.y + d);
    ctx.lineTo(p.x - d, p.y);
    ctx.closePath();
  } else ctx.arc(p.x, p.y, kind === 'rotate' ? r * 1.15 : r, 0, 2 * Math.PI);
}

/** The small turning arrow drawn inside the rotation handle. */
function rotateGlyph(ctx: CanvasRenderingContext2D, p: Point, r: number) {
  ctx.beginPath();
  ctx.arc(p.x, p.y, r * 0.55, -Math.PI * 0.9, Math.PI * 0.45);
  ctx.stroke();
}

export function paintHandles(ctx: CanvasRenderingContext2D, t: Transform, look: HandleLook) {
  const { set, dpr } = look;
  const r = (look.coarse ? COARSE_SIZE_PX : SIZE_PX) * dpr;
  ctx.lineWidth = Math.max(1, 1.5 * dpr);
  if (look.active) {
    const h = set.handles[look.active.index];
    if (!h || h.kind === 'rotate') return;
    const p = toDevice(t, look.active.at.x, look.active.at.y);
    shapePath(ctx, h.kind, p, r);
    ctx.fillStyle = h.kind === 'adjust' ? ADJUST : ACCENT;
    ctx.fill();
    ctx.strokeStyle = '#fff';
    ctx.stroke();
    return;
  }
  if (set.frame) {
    ctx.beginPath();
    set.frame.forEach((c, i) => {
      const p = toDevice(t, c.x, c.y);
      if (i === 0) ctx.moveTo(p.x, p.y);
      else ctx.lineTo(p.x, p.y);
    });
    ctx.closePath();
    ctx.strokeStyle = FRAME;
    ctx.lineWidth = Math.max(1, dpr);
    ctx.stroke();
    ctx.lineWidth = Math.max(1, 1.5 * dpr);
  }
  for (const h of visibleHandles(set, t, dpr)) {
    const p = devicePoint(h, t, dpr);
    if (h.kind === 'rotate') {
      const foot = toDevice(t, h.at.x, h.at.y);
      ctx.beginPath();
      ctx.moveTo(foot.x, foot.y);
      ctx.lineTo(p.x, p.y);
      ctx.strokeStyle = FRAME;
      ctx.stroke();
    }
    const hovered = look.hover === h.index;
    shapePath(ctx, h.kind, p, r);
    if (h.kind === 'adjust') {
      ctx.fillStyle = hovered ? '#d97706' : ADJUST;
      ctx.strokeStyle = '#fff';
    } else {
      ctx.fillStyle = hovered ? ACCENT : '#fff';
      ctx.strokeStyle = hovered ? '#fff' : ACCENT;
    }
    ctx.fill();
    ctx.stroke();
    if (h.kind === 'rotate') {
      ctx.strokeStyle = hovered ? '#fff' : ACCENT;
      rotateGlyph(ctx, p, r);
    }
  }
  const hovered = look.hover === null ? null : set.handles[look.hover];
  if (hovered) {
    const p = devicePoint(hovered, t, dpr);
    paintPill(ctx, hovered.label, { x: p.x + r + 6 * dpr, y: p.y - r - 6 * dpr }, dpr);
  }
}

/** A short label on a rounded pill, the middle of its `side` end at device point `at`, kept on the canvas. */
export function paintPill(ctx: CanvasRenderingContext2D, text: string, at: Point, dpr: number, background = PILL, side: 'start' | 'end' = 'start') {
  ctx.save();
  ctx.font = `${Math.round(11.5 * dpr)}px system-ui, -apple-system, "Segoe UI", sans-serif`;
  ctx.textBaseline = 'middle';
  const width = ctx.measureText(text).width;
  const pad = 6 * dpr;
  const height = 19 * dpr;
  const wanted = side === 'start' ? at.x : at.x - width - 2 * pad;
  const left = Math.max(2 * dpr, Math.min(wanted, ctx.canvas.width - width - 2 * pad - 2 * dpr));
  const top = Math.max(2 * dpr, at.y - height / 2);
  ctx.beginPath();
  ctx.roundRect(left, top, width + 2 * pad, height, height / 2);
  ctx.fillStyle = background;
  ctx.globalAlpha = 0.92;
  ctx.fill();
  ctx.globalAlpha = 1;
  ctx.fillStyle = '#fff';
  ctx.fillText(text, left + pad, top + height / 2 + 0.5 * dpr);
  ctx.restore();
}
