// Smart guides: while items or a handle are dragged, lines appear to what
// the dragged thing lines up with, and the drag snaps onto them, as in a
// drawing program. The targets read the music rather than the page alone:
//
// - the staff's lines and spaces (named: "middle line", "1 ledger line above");
// - like items on the same staff at the same level (a row of dynamics), and
//   the same level as like items on other staves, which in SCORE's terms is
//   the same distance from their staff;
// - the columns of the music: notes, rests and barlines on nearby staves,
//   note heads by their middle;
// - the middle of a bar, for rests, numbers and text centred in it;
// - for an end of a line, slur or beam, the level of its other end;
// - for a staff's place, the spacing of the staves next to it;
// - and, as anywhere, the edges and middles of like items.
//
// Edges align with edges, middles with middles, and an item's reference
// point (where SCORE places it: P3, P4) with others' reference points, the
// staff's lines and levels. A handle's point aligns with all of them.
import type { Box } from './display';
import { paintPill } from './handles';
import { staffPlace } from './item-fields';
import { toDevice, type Point, type Transform } from './view';

export type TargetKind = 'edge' | 'centre' | 'ref' | 'line' | 'level' | 'column' | 'bar' | 'end' | 'spacing';
export type ProbeKind = 'edge' | 'centre' | 'ref' | 'point';

interface Target {
  value: number;
  kind: TargetKind;
  /** Where the target lies along the other axis; from > to when only the dragged thing gives the guide its length. */
  from: number;
  to: number;
  label?: string;
  /** The item it comes from, outlined while the guide shows. */
  box?: Box;
}

export interface Probe {
  value: number;
  kind: ProbeKind;
}

export interface Probes {
  x: Probe[];
  y: Probe[];
}

/** The targets of one drag, by the axis they fix. */
export interface Field {
  x: Target[];
  y: Target[];
}

export interface Guide {
  axis: 'x' | 'y';
  value: number;
  from: number;
  to: number;
  label?: string;
  music: boolean;
  boxes: Box[];
  /** Only the dragged thing gives it its length (a staff line, a level on another staff). */
  short: boolean;
}

/** What the guides read from the score: score-web's anchors and staves, and the box of every item. */
export interface ScoreFacts {
  anchors: Float32Array;
  staves: Float32Array;
  boxes: (Box | null)[];
}

const ANCHOR_WORDS = 6;
const STAFF_WORDS = 7;

interface Anchor {
  code: number;
  staff: number;
  x: number;
  y: number;
  level: number;
  centre: number;
}

function anchorOf(f: ScoreFacts, i: number): Anchor {
  const [code = 0, staff = 0, x = 0, y = 0, level = 0, centre = 0] = f.anchors.subarray(i * ANCHOR_WORDS, (i + 1) * ANCHOR_WORDS);
  return { code, staff, x, y, level, centre };
}

interface StaffFacts {
  number: number;
  x0: number;
  x1: number;
  /** Page y of level 0. */
  y0: number;
  step: number;
  /** Level of the lowest line; the lines lie two levels apart. */
  first: number;
  count: number;
}

function stavesOf(f: ScoreFacts): StaffFacts[] {
  return Array.from({ length: f.staves.length / STAFF_WORDS }, (_, i) => {
    const [number = 0, x0 = 0, x1 = 0, y0 = 0, step = 1, first = 3, count = 5] = f.staves.subarray(i * STAFF_WORDS, (i + 1) * STAFF_WORDS);
    return { number, x0, x1, y0, step, first, count };
  });
}

const bottomOf = (s: StaffFacts) => s.y0 + s.first * s.step;
const topOf = (s: StaffFacts) => s.y0 + (s.first + 2 * (s.count - 1)) * s.step;

/** Kinds of item that line up with each other. */
function family(code: number): string {
  if (code === 1 || code === 2) return 'notes';
  if (code === 4 || code === 5 || code === 6) return 'lines';
  if (code === 3 || code === 14 || code === 17 || code === 18) return 'signs';
  if (code === 8) return 'staves';
  return 'marks';
}

/** What a drag lines up with. */
export interface Wants {
  /** Notes, rests and barlines on nearby staves (x). */
  columns: boolean;
  /** The middle of the bar (x). */
  bars: boolean;
  /** The own staff's lines and spaces (y). */
  lines: boolean;
  /** Like items at the same level, on this staff and others (y). */
  levels: boolean;
  /** Like items' edges and middles. */
  likes: boolean;
  /** Other ends of the dragged item, to level with (y). */
  ends: Point[];
  /** Spacing of the staff as the page spaces its staves; `y` is the dragged point's page y. */
  spacing: { y: number } | null;
  /** Other staves' ends (x). */
  staffEnds: boolean;
}

const NOTHING: Wants = { columns: false, bars: false, lines: false, levels: false, likes: false, ends: [], spacing: null, staffEnds: false };

/** What moving whole items of code `code` lines up with. */
export function wantsForMove(code: number): Wants {
  switch (family(code)) {
    case 'notes':
      return { ...NOTHING, columns: true, lines: true };
    case 'lines':
      return { ...NOTHING, columns: true, lines: true, levels: true, likes: true };
    case 'signs':
      return { ...NOTHING, columns: true, likes: true };
    case 'staves':
      return { ...NOTHING, staffEnds: true };
    default:
      return { ...NOTHING, columns: true, bars: true, lines: code === 9 || code === 7, levels: true, likes: true };
  }
}

/** What dragging a handle lines up with; `others` are the item's other end handles. */
export function wantsForHandle(code: number, kind: string, label: string, others: Point[], y: number): Wants {
  if (code === 8) return label === 'Place' ? { ...NOTHING, spacing: { y } } : label.endsWith('end') ? { ...NOTHING, staffEnds: true } : NOTHING;
  if (kind === 'end') return { ...NOTHING, columns: true, lines: true, levels: true, likes: true, ends: code === 7 ? [] : others };
  if (kind === 'scale') return { ...NOTHING, likes: true, columns: true };
  if (kind === 'adjust') return { ...NOTHING, lines: label !== 'Spacing' && label !== 'Opening', likes: label === 'Spacing' };
  return NOTHING;
}

/** Staves within this many units above or below the dragged thing give it columns. */
const COLUMN_REACH = 2.5 * 3150;
/** Like items within this many units across give it levels and edges. */
const ROW_REACH = 9000;
/** Barlines closer than this are one (a double barline). */
const BARLINE_MERGE = 300;

const overlaps = (a: Box, b: Box) => a.x1 >= b.x0 && a.x0 <= b.x1 && a.y1 >= b.y0 && a.y0 <= b.y1;
const fmt = (v: number) => String(Math.round(v * 100) / 100);
const UNBOUNDED = { from: Infinity, to: -Infinity };

/** The dragged item, what moves with it and its extent when the drag began. */
export interface Dragged {
  item: number;
  moving: Set<number>;
  span: Box;
}

/** The targets of a drag among the items in `view`. */
export function buildField(f: ScoreFacts, dragged: Dragged, wants: Wants, view: Box): Field {
  const own = anchorOf(f, dragged.item);
  const staves = stavesOf(f);
  const ownStaff = staves.find((s) => s.number === own.staff) ?? null;
  const kind = family(own.code);
  const span = dragged.span;
  const x: Target[] = [];
  const y: Target[] = [];
  for (let i = 0; i < f.boxes.length; i++) {
    const b = f.boxes[i];
    if (!b || dragged.moving.has(i) || !overlaps(b, view)) continue;
    const a = anchorOf(f, i);
    if (a.code === 8) continue;
    const like = family(a.code) === kind;
    const inColumn = b.y1 >= span.y0 - COLUMN_REACH && b.y0 <= span.y1 + COLUMN_REACH;
    const inRow = b.x1 >= span.x0 - ROW_REACH && b.x0 <= span.x1 + ROW_REACH;
    if (inColumn && wants.columns && (a.code === 1 || a.code === 2 || a.code === 14)) {
      x.push({ value: a.x, kind: 'ref', from: b.y0, to: b.y1, box: b });
      if (a.code === 1) x.push({ value: a.centre, kind: 'column', from: b.y0, to: b.y1, box: b });
    }
    if (wants.likes && like) {
      if (inColumn) {
        x.push({ value: b.x0, kind: 'edge', from: b.y0, to: b.y1, box: b });
        x.push({ value: b.x1, kind: 'edge', from: b.y0, to: b.y1, box: b });
        x.push({ value: (b.x0 + b.x1) / 2, kind: 'centre', from: b.y0, to: b.y1, box: b });
        x.push({ value: a.x, kind: 'ref', from: b.y0, to: b.y1, box: b });
      }
      if (inRow) {
        y.push({ value: b.y0, kind: 'edge', from: b.x0, to: b.x1, box: b });
        y.push({ value: b.y1, kind: 'edge', from: b.x0, to: b.x1, box: b });
        y.push({ value: (b.y0 + b.y1) / 2, kind: 'centre', from: b.x0, to: b.x1, box: b });
      }
    }
    if (wants.levels && like && ownStaff) {
      if (a.staff === own.staff) y.push({ value: a.y, kind: 'ref', from: b.x0, to: b.x1, label: `level ${fmt(a.level)}`, box: b });
      else y.push({ value: ownStaff.y0 + a.level * ownStaff.step, kind: 'level', ...UNBOUNDED, label: `level ${fmt(a.level)}, as on staff ${a.staff}`, box: b });
    }
  }
  if (wants.bars && ownStaff) x.push(...barCentres(f, ownStaff, view));
  if (wants.lines && ownStaff) y.push(...staffLines(ownStaff));
  wants.ends.forEach((p) => y.push({ value: p.y, kind: 'end', from: p.x, to: p.x, label: 'level with the other end' }));
  if (wants.spacing && ownStaff) y.push(...evenSpacing(staves, ownStaff, wants.spacing.y - bottomOf(ownStaff)));
  if (wants.staffEnds) {
    staves
      .filter((s) => s.number !== own.staff)
      .forEach((s) => {
        x.push({ value: s.x0, kind: 'edge', from: bottomOf(s), to: topOf(s), label: `start of staff ${s.number}` });
        x.push({ value: s.x1, kind: 'edge', from: bottomOf(s), to: topOf(s), label: `end of staff ${s.number}` });
      });
  }
  return { x, y };
}

/** The middles between the barlines that cross the staff's middle line. */
function barCentres(f: ScoreFacts, staff: StaffFacts, view: Box): Target[] {
  const middle = staff.y0 + (staff.first + staff.count - 1) * staff.step;
  const xs = f.boxes
    .map((b, i) => ({ b, a: anchorOf(f, i) }))
    .filter(({ b, a }) => b && a.code === 14 && b.y0 <= middle && b.y1 >= middle && b.x1 >= view.x0 - 20000 && b.x0 <= view.x1 + 20000)
    .map(({ a }) => a.x)
    .sort((p, q) => p - q)
    .filter((v, i, all) => i === 0 || v - all[i - 1]! > BARLINE_MERGE);
  const label = 'middle of the bar';
  return xs.slice(1).map((right, i) => ({ value: (xs[i]! + right) / 2, kind: 'bar', from: bottomOf(staff), to: topOf(staff), label }));
}

/** The lines and spaces of a staff and three ledger lines past it either way. */
function staffLines(staff: StaffFacts): Target[] {
  const highest = 2 * (staff.count - 1);
  return Array.from({ length: highest + 13 }, (_, i) => {
    const k = i - 6;
    const name = staff.count === 5 ? staffPlace(3 + k) : k >= 0 && k <= highest ? (k % 2 === 0 ? 'staff line' : 'staff space') : 'beyond the staff';
    return { value: staff.y0 + (staff.first + k) * staff.step, kind: 'line' as const, ...UNBOUNDED, label: name };
  });
}

/**
 * Where a staff's bottom line goes for its spacing to match the page's:
 * halfway between its neighbours, or as far from the staff below or above
 * as any two other neighbouring staves are apart (the staves of a grand
 * staff, the systems). `lift` is the dragged point's height above the
 * bottom line.
 */
function evenSpacing(staves: StaffFacts[], own: StaffFacts, lift: number): Target[] {
  const sorted = [...staves].sort((a, b) => bottomOf(b) - bottomOf(a));
  const at = sorted.indexOf(own);
  const [above, below] = [sorted[at - 1], sorted[at + 1]];
  const height = topOf(own) - bottomOf(own);
  const others = sorted.filter((s) => s !== own);
  const gaps: { gap: number; upper: StaffFacts; lower: StaffFacts }[] = [];
  others.slice(1).forEach((lower, i) => {
    const upper = others[i]!;
    const gap = bottomOf(upper) - topOf(lower);
    if (upper === above && lower === below) return;
    // Gaps within a scale step of each other are one spacing set by hand; the highest pair names it.
    if (gap > 0 && !gaps.some((g) => Math.abs(g.gap - gap) < own.step)) gaps.push({ gap, upper, lower });
  });
  const targets: Target[] = [];
  const put = (bottom: number, label: string) => targets.push({ value: bottom + lift, kind: 'spacing', ...UNBOUNDED, label });
  if (above && below) put((bottomOf(above) + topOf(below) - height) / 2, `halfway between staves ${above.number} and ${below.number}`);
  gaps.forEach(({ gap, upper, lower }) => {
    const as = `as between staves ${upper.number} and ${lower.number}`;
    if (below) put(topOf(below) + gap, as);
    if (above) put(bottomOf(above) - gap - height, as);
  });
  return targets;
}

/** Which targets a probe may snap to. */
const ACCEPTS: Record<TargetKind, ProbeKind[]> = {
  edge: ['edge', 'point'],
  centre: ['centre', 'point'],
  ref: ['ref', 'point'],
  line: ['ref', 'point'],
  level: ['ref', 'point'],
  column: ['centre', 'point'],
  bar: ['centre', 'point'],
  end: ['point'],
  spacing: ['point'],
};

/** Musical targets win over plain geometry when about as near. */
const PRIORITY: Record<TargetKind, number> = { end: 0, spacing: 0, line: 1, level: 1, bar: 1, column: 2, ref: 2, centre: 3, edge: 4 };
const MUSIC = new Set<TargetKind>(['line', 'level', 'column', 'bar', 'end', 'spacing']);

interface Hit {
  probe: Probe;
  target: Target;
}

function snapAxis(targets: Target[], probes: Probe[], offset: number, tolerance: number): { offset: number; hits: Hit[] } {
  let best: { d: number; score: number } | null = null;
  for (const probe of probes) {
    const at = probe.value + offset;
    for (const target of targets) {
      const d = target.value - at;
      if (Math.abs(d) > tolerance || !ACCEPTS[target.kind].includes(probe.kind)) continue;
      const score = Math.abs(d) + PRIORITY[target.kind] * tolerance * 0.15;
      if (!best || score < best.score) best = { d, score };
    }
  }
  if (!best) return { offset, hits: [] };
  const snapped = offset + best.d;
  const eps = Math.max(0.5, tolerance * 0.04);
  const hits: Hit[] = [];
  for (const probe of probes) {
    for (const target of targets) {
      if (ACCEPTS[target.kind].includes(probe.kind) && Math.abs(target.value - (probe.value + snapped)) <= eps) hits.push({ probe, target });
    }
  }
  return { offset: snapped, hits };
}

/** Guides closer than this (units) are drawn as one. */
const SAME_GUIDE = 2;

/** The guides through what the hits line up with, merged where they coincide. */
function guidesOf(axis: 'x' | 'y', hits: Hit[], span: [number, number]): Guide[] {
  const merged: (Guide & { rank: number })[] = [];
  for (const { target } of hits) {
    let guide = merged.find((g) => Math.abs(g.value - target.value) <= SAME_GUIDE);
    if (!guide) {
      guide = { axis, value: target.value, from: span[0], to: span[1], music: false, boxes: [], short: true, rank: 99 };
      merged.push(guide);
    }
    if (target.from <= target.to) {
      guide.from = Math.min(guide.from, target.from);
      guide.to = Math.max(guide.to, target.to);
      guide.short = false;
    }
    if (target.box && !guide.boxes.includes(target.box)) guide.boxes.push(target.box);
    guide.music ||= MUSIC.has(target.kind);
    if (target.label && PRIORITY[target.kind] < guide.rank) {
      guide.label = target.label;
      guide.rank = PRIORITY[target.kind];
    }
  }
  return merged.map(({ rank: _rank, ...guide }) => guide);
}

/**
 * Snaps the travel of a drag: each probe moved by `travel` that comes
 * within `tolerance` of a target it accepts pulls the travel onto it, along
 * the axes that are free. `span` is the dragged thing's extent before the
 * travel, for the guides' length.
 */
export function snap(field: Field, probes: Probes, travel: Point, tolerance: number, axes: { x: boolean; y: boolean }, span: Box): { travel: Point; guides: Guide[] } {
  const sx = axes.x ? snapAxis(field.x, probes.x, travel.x, tolerance) : { offset: travel.x, hits: [] };
  const sy = axes.y ? snapAxis(field.y, probes.y, travel.y, tolerance) : { offset: travel.y, hits: [] };
  const moved = { x0: span.x0 + sx.offset, x1: span.x1 + sx.offset, y0: span.y0 + sy.offset, y1: span.y1 + sy.offset };
  return {
    travel: { x: sx.offset, y: sy.offset },
    guides: [...guidesOf('x', sx.hits, [moved.y0, moved.y1]), ...guidesOf('y', sy.hits, [moved.x0, moved.x1])],
  };
}

/** The probes of items being moved: the edges and middle of their box, the primary item's reference point and centre. */
export function moveProbes(f: ScoreFacts, item: number, span: Box): Probes {
  const a = anchorOf(f, item);
  const centreX = a.code === 1 ? a.centre : (span.x0 + span.x1) / 2;
  return {
    x: [
      { value: span.x0, kind: 'edge' },
      { value: span.x1, kind: 'edge' },
      { value: centreX, kind: 'centre' },
      { value: a.x, kind: 'ref' },
    ],
    y: [
      { value: span.y0, kind: 'edge' },
      { value: span.y1, kind: 'edge' },
      { value: (span.y0 + span.y1) / 2, kind: 'centre' },
      { value: a.y, kind: 'ref' },
    ],
  };
}

/** The code (P1) of item `item`. */
export function codeOf(f: ScoreFacts, item: number): number {
  return anchorOf(f, item).code;
}

const GUIDE = '#db2777';

/** How far a guide runs past what it joins, and past the dragged thing alone, in CSS pixels. */
const OVERSHOOT_PX = 12;
const SHORT_OVERSHOOT_PX = 56;

export function paintGuides(ctx: CanvasRenderingContext2D, t: Transform, guides: Guide[], dpr: number) {
  ctx.lineWidth = Math.max(1, dpr);
  ctx.strokeStyle = GUIDE;
  for (const g of guides) {
    ctx.setLineDash([3 * dpr, 3 * dpr]);
    g.boxes.forEach((b) => {
      const a = toDevice(t, b.x0, b.y1);
      const c = toDevice(t, b.x1, b.y0);
      ctx.strokeRect(Math.round(a.x - 2 * dpr) + 0.5, Math.round(a.y - 2 * dpr) + 0.5, Math.round(c.x - a.x + 4 * dpr), Math.round(c.y - a.y + 4 * dpr));
    });
    ctx.setLineDash(g.music ? [6 * dpr, 3 * dpr] : []);
    const pad = (g.short ? SHORT_OVERSHOOT_PX : OVERSHOOT_PX) * dpr;
    const [p, q] = g.axis === 'x' ? [toDevice(t, g.value, g.to), toDevice(t, g.value, g.from)] : [toDevice(t, g.from, g.value), toDevice(t, g.to, g.value)];
    const snapPx = (v: number) => Math.round(v - 0.5) + 0.5;
    ctx.beginPath();
    if (g.axis === 'x') {
      ctx.moveTo(snapPx(p.x), p.y - pad);
      ctx.lineTo(snapPx(q.x), q.y + pad);
    } else {
      ctx.moveTo(p.x - pad, snapPx(p.y));
      ctx.lineTo(q.x + pad, snapPx(q.y));
    }
    ctx.stroke();
  }
  ctx.setLineDash([]);
  // Labels sit at the start of a level guide (left of it) and the foot of an upright one,
  // away from the readout by the cursor.
  let stack = 0;
  for (const g of guides) {
    if (!g.label) continue;
    const pad = (g.short ? SHORT_OVERSHOOT_PX : OVERSHOOT_PX) * dpr;
    if (g.axis === 'x') {
      const foot = toDevice(t, g.value, g.from);
      paintPill(ctx, g.label, { x: foot.x + 4 * dpr, y: foot.y + pad + 12 * dpr + stack }, dpr, GUIDE);
    } else {
      const start = toDevice(t, g.from, g.value);
      paintPill(ctx, g.label, { x: start.x - pad - 4 * dpr, y: start.y - stack }, dpr, GUIDE, 'end');
    }
    stack += 22 * dpr;
  }
}
