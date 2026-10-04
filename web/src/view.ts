// The mapping from page coordinates (engine units, y up) to device pixels.
//
// Zoom is a percentage as in WinScore. 100 % shows the page at physical size
// on a 96-dpi screen: WinScore's view uses MM_HIENGLISH (0.001 in per logical
// unit) scaled by zoom/256, and its 100 % (zoom 64) maps 4 engine units to
// one logical unit, i.e. engine units to inches 1:4000. One CSS pixel is
// 1/96 in, so at 100 % one CSS pixel spans 4000/96 ≈ 41.7 engine units.
import type { Box } from './display';

export const UNITS_PER_INCH = 4000;
export const CSS_PX_PER_INCH = 96;
/** WinScore's zoom bar, then larger steps for inspecting details. */
export const ZOOM_LEVELS = [10, 25, 50, 75, 100, 125, 150, 200, 250, 300, 400, 500, 800, 1200, 1600];

/** WinScore keeps zoom as an integer with 64 = 100 %. */
const ZOOM_UNIT = 64;

export function cssPerUnit(zoom: number): number {
  return ((zoom / 100) * CSS_PX_PER_INCH) / UNITS_PER_INCH;
}

/** Device pixels = page units × k + offset, with y flipped. */
export interface Transform {
  k: number;
  ox: number;
  oy: number;
}

export interface Point {
  x: number;
  y: number;
}

export function toDevice(t: Transform, x: number, y: number): Point {
  return { x: x * t.k + t.ox, y: t.oy - y * t.k };
}

export function toPage(t: Transform, x: number, y: number): Point {
  return { x: (x - t.ox) / t.k, y: (t.oy - y) / t.k };
}

/** Where the extent's top-left corner sits in CSS pixels of the scrolled content. */
export interface Placement {
  zoom: number;
  extent: Box;
  /** Content offset (centering when the page is smaller than the viewport). */
  left: number;
  top: number;
  scrollLeft: number;
  scrollTop: number;
  dpr: number;
}

export function transform(p: Placement): Transform {
  const s = cssPerUnit(p.zoom);
  const k = s * p.dpr;
  return {
    k,
    ox: (p.left - p.scrollLeft - p.extent.x0 * s) * p.dpr,
    oy: (p.top - p.scrollTop + p.extent.y1 * s) * p.dpr,
  };
}

export function contentSize(zoom: number, extent: Box): { width: number; height: number } {
  const s = cssPerUnit(zoom);
  return { width: Math.ceil((extent.x1 - extent.x0) * s), height: Math.ceil((extent.y1 - extent.y0) * s) };
}

/**
 * WinScore's Zoom and Reduce: ± max(1, zoom/4) in its integer zoom units,
 * Reduce stopping at 1 (analysis/engine/display.md).
 */
export function stepZoom(zoom: number, step: 1 | -1): number {
  const units = Math.round((zoom * ZOOM_UNIT) / 100);
  const next = Math.max(1, units + step * Math.max(1, Math.trunc(units / 4)));
  return (next * 100) / ZOOM_UNIT;
}
