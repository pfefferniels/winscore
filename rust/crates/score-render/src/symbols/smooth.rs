//! Smooth outlines for library symbols.
//!
//! The libraries store every outline as polygons on an integer grid of
//! library units, so curves show facets and steps when a symbol is drawn
//! large: dots are octagons, the balls of f and 3 have corners. An
//! [`Outline`] redraws each path as cubic curves through its points and
//! keeps the corners and straight runs the designer drew. The points first
//! move by at most [`SLACK`] towards an even curvature, so that the steps
//! of the grid do not show as bumps; nothing moves further, and the curve
//! between two points bulges from their chord about as far as the arc of
//! a circle through them, so the glyph keeps its design and its extent.

use std::collections::HashMap;
use std::f64::consts::PI;
use std::ops::{Add, Mul, Sub};
use std::sync::{Arc, Mutex, OnceLock, PoisonError};

use score_format::{DrwRecord, Symbol};

use crate::canvas::{Canvas, Pen};
use crate::symbols::{pen, Scale};
use crate::units::{real, Pos};

/// How far a point of the library grid may move, in library units.
pub const SLACK: f64 = 0.4;
/// A turn of at least this many radians is always a corner (60°).
const SHARP: f64 = PI / 3.0;
/// A turn of at least this is a corner unless it is part of a tight curve (35°).
const CORNER: f64 = 35.0 * PI / 180.0;
/// How far rounding a point may bend an edge next to it, in library units:
/// a little more than the 0.56 by which a circle bulges from the octagon of a dot.
const BOW: f64 = 0.6;
/// An edge this many times longer than its neighbours is a straight run.
const STRAIGHT: f64 = 3.0;
/// Rounds of Taubin smoothing (a shrinking step, then an inflating one).
const ROUNDS: usize = 4;
const SHRINK: f64 = 0.5;
const INFLATE: f64 = -0.53;
/// Tangents closer than this cosine to a right angle with the chord would
/// make the curve loop; such an edge stays straight.
const MIN_COSINE: f64 = 0.2;
/// Largest distance in engine units between a curve and the polyline that
/// draws it: a third of a pixel at 1600 %.
const FLATNESS: f64 = 1.0;
const MAX_PIECES: usize = 32;

#[derive(Debug, Clone, Copy, PartialEq, Default)]
struct V {
    x: f64,
    y: f64,
}

impl V {
    const fn new(x: f64, y: f64) -> Self {
        Self { x, y }
    }

    fn dot(self, other: V) -> f64 {
        self.x * other.x + self.y * other.y
    }

    fn cross(self, other: V) -> f64 {
        self.x * other.y - self.y * other.x
    }

    fn len(self) -> f64 {
        self.x.hypot(self.y)
    }

    fn unit(self) -> V {
        self * (1.0 / self.len())
    }

    /// Turned a quarter counter-clockwise.
    fn perp(self) -> V {
        V::new(-self.y, self.x)
    }
}

impl Add for V {
    type Output = V;
    fn add(self, other: V) -> V {
        V::new(self.x + other.x, self.y + other.y)
    }
}

impl Sub for V {
    type Output = V;
    fn sub(self, other: V) -> V {
        V::new(self.x - other.x, self.y - other.y)
    }
}

impl Mul<f64> for V {
    type Output = V;
    fn mul(self, factor: f64) -> V {
        V::new(self.x * factor, self.y * factor)
    }
}

/// Signed angle from direction `a` to direction `b`, counter-clockwise positive.
fn angle(a: V, b: V) -> f64 {
    a.cross(b).atan2(a.dot(b))
}

#[derive(Debug, Clone, Copy, PartialEq)]
enum Segment {
    Line(V),
    /// A cubic Bézier curve: two control points and the end.
    Curve(V, V, V),
}

/// One path of a symbol: the pen of its first record, where it starts and
/// how it goes on.
#[derive(Debug, Clone, PartialEq)]
struct Path {
    pen: Pen,
    start: V,
    segments: Vec<Segment>,
}

/// A symbol's paths as lines and cubic curves, in library units.
#[derive(Debug, Clone, PartialEq)]
pub struct Outline {
    paths: Vec<Path>,
}

impl Outline {
    /// The outline of `symbol`, smoothed once per symbol and kept: a page
    /// draws the same few symbols many times.
    pub fn cached(symbol: &Symbol) -> Arc<Outline> {
        type Cache = HashMap<usize, (Vec<DrwRecord>, Arc<Outline>)>;
        static CACHE: OnceLock<Mutex<Cache>> = OnceLock::new();
        let mut cache = CACHE.get_or_init(Default::default).lock().unwrap_or_else(PoisonError::into_inner);
        // Keyed by address, checked by content: a library may be dropped
        // and another one take its place.
        let key = std::ptr::from_ref(symbol) as usize;
        match cache.get(&key) {
            Some((records, outline)) if *records == symbol.records => Arc::clone(outline),
            _ => {
                let outline = Arc::new(Outline::of(&symbol.records));
                cache.insert(key, (symbol.records.clone(), Arc::clone(&outline)));
                outline
            }
        }
    }

    /// The smoothed paths of the records of a symbol. Every record that
    /// starts a path (pen 1, 2, 3) still starts one, so the shapes the
    /// stream decodes are the engine's; filled paths are closed explicitly.
    pub fn of(records: &[DrwRecord]) -> Self {
        let mut runs: Vec<(Pen, Vec<V>)> = Vec::new();
        records.iter().for_each(|r| {
            let at = V::new(f64::from(r.x), f64::from(r.y));
            match (pen(r.pen), runs.last_mut()) {
                (Pen::Continue, Some((_, points))) => points.push(at),
                (pen, _) => runs.push((pen, vec![at])),
            }
        });
        Self { paths: runs.into_iter().map(|(pen, points)| smoothed(pen, points)).collect() }
    }

    /// Adds the outline to the buffer at f32(origin + scale × coordinate)
    /// per axis, where draw_symbol puts the records, each curve in
    /// pieces short enough to look round at any zoom.
    pub fn draw(&self, canvas: &mut Canvas<'_>, origin: Pos, scale: Scale) {
        let place = |v: V| Pos::new(real(origin.x + v.x * scale.x), real(origin.y + v.y * scale.y));
        self.paths.iter().for_each(|path| {
            canvas.point(place(path.start), path.pen);
            path.segments.iter().fold(path.start, |from, segment| match *segment {
                Segment::Line(to) => {
                    canvas.point(place(to), Pen::Continue);
                    to
                }
                Segment::Curve(c1, c2, to) => {
                    let n = pieces([from, c1, c2, to], scale);
                    (1..=n).for_each(|k| {
                        canvas.point(place(bezier([from, c1, c2, to], k as f64 / n as f64)), Pen::Continue)
                    });
                    to
                }
            });
        });
    }

    /// Every point the outline passes through or bends towards, for tests.
    #[cfg(test)]
    fn polyline(&self, pieces: usize) -> Vec<Vec<(f64, f64)>> {
        self.paths
            .iter()
            .map(|path| {
                let mut points = vec![path.start];
                path.segments.iter().for_each(|segment| match *segment {
                    Segment::Line(to) => points.push(to),
                    Segment::Curve(c1, c2, to) => {
                        let from = *points.last().expect("paths start somewhere");
                        points.extend((1..=pieces).map(|k| bezier([from, c1, c2, to], k as f64 / pieces as f64)));
                    }
                });
                points.into_iter().map(|v| (v.x, v.y)).collect()
            })
            .collect()
    }
}

fn bezier([p0, p1, p2, p3]: [V; 4], t: f64) -> V {
    let s = 1.0 - t;
    p0 * (s * s * s) + p1 * (3.0 * s * s * t) + p2 * (3.0 * s * t * t) + p3 * (t * t * t)
}

/// Pieces for a curve so that none strays more than [`FLATNESS`] engine
/// units from its chord (Wang's formula on the scaled control points).
fn pieces(points: [V; 4], scale: Scale) -> usize {
    let [p0, p1, p2, p3] = points.map(|v| V::new(v.x * scale.x, v.y * scale.y));
    let bend = (p0 - p1 * 2.0 + p2).len().max((p1 - p2 * 2.0 + p3).len());
    ((0.75 * bend / FLATNESS).sqrt().ceil() as usize).clamp(1, MAX_PIECES)
}

/// A path as lines through its records, unchanged.
fn unchanged(pen: Pen, points: &[V]) -> Path {
    Path { pen, start: points[0], segments: points[1..].iter().map(|&p| Segment::Line(p)).collect() }
}

/// One path smoothed: filled paths (and polylines that end where they
/// start) as closed curves, other polylines as open ones from end to end.
/// A path that continues the previous item's shape, or has fewer than
/// three distinct points, stays as it is.
fn smoothed(pen: Pen, points: Vec<V>) -> Path {
    let mut distinct = points.clone();
    distinct.dedup();
    let closed = match pen {
        Pen::Fill | Pen::SubPath => true,
        Pen::Stroke => distinct.len() > 3 && distinct.first() == distinct.last(),
        Pen::Continue => return unchanged(pen, &points),
    };
    let distinct = if closed { cycle(distinct) } else { distinct };
    if distinct.len() < 3 {
        return unchanged(pen, &points);
    }
    let curve = Curve::new(distinct, closed);
    Path { pen, start: curve.points[0], segments: curve.segments() }
}

/// A closed path's points without the closing repeat of its first ones
/// (most library paths end on their first point, some on the first two).
fn cycle(mut points: Vec<V>) -> Vec<V> {
    let n = points.len();
    let repeat = (1..=n / 2).rev().find(|&k| points[n - k..] == points[..k]).unwrap_or(0);
    points.truncate(n - repeat);
    points
}

/// The points of one path with what is known about them: which are
/// corners, which edges are straight runs.
struct Curve {
    points: Vec<V>,
    closed: bool,
    /// By point; the ends of an open path count as corners.
    corner: Vec<bool>,
    /// By edge, edge `i` running from point `i` to the next.
    straight: Vec<bool>,
}

impl Curve {
    fn new(points: Vec<V>, closed: bool) -> Self {
        let n = points.len();
        let edges = if closed { n } else { n - 1 };
        let length: Vec<f64> = (0..edges).map(|i| (points[(i + 1) % n] - points[i]).len()).collect();
        let mut curve = Self { points, closed, corner: Vec::new(), straight: Vec::new() };
        let turns: Vec<Option<f64>> = (0..n)
            .map(|i| {
                let (before, after) = (curve.edge_before(i)?, curve.edge_after(i)?);
                let p = &curve.points;
                Some(angle(p[i] - p[before], p[(after + 1) % n] - p[i]))
            })
            .collect();
        curve.corner = (0..n)
            .map(|i| match (turns[i], curve.edge_before(i), curve.edge_after(i)) {
                (Some(turn), Some(before), Some(after)) => {
                    let neighbour = |j: Option<usize>| j.and_then(|j| turns[j]);
                    is_corner(
                        turn,
                        [neighbour(curve.previous(i)), neighbour(curve.next(i))],
                        [length[before], length[after]],
                    )
                }
                _ => true,
            })
            .collect();
        curve.straight = (0..edges)
            .map(|i| {
                let j = (i + 1) % n;
                let neighbours = [curve.edge_before(i), curve.edge_after(j)];
                let long = neighbours.iter().flatten().all(|&e| length[i] >= STRAIGHT * length[e]);
                // How far the edge leans from its chord at each end: the
                // part of the turn a parabola through the end and its
                // neighbours gives it; a corner end mirrors the other end.
                let lean = |at: usize, other: Option<usize>| {
                    let turn = turns[at].filter(|_| !curve.corner[at])?;
                    let other = other.map_or(0.0, |e| length[e]);
                    Some(turn * length[i] / (length[i] + other))
                };
                let bend = match (lean(i, curve.edge_before(i)), lean(j, curve.edge_after(j))) {
                    (None, None) => return true,
                    (Some(a), Some(b)) => (a, b),
                    (Some(a), None) | (None, Some(a)) => (a, a),
                };
                long || length[i] * (bend.0.abs().sin() + bend.1.abs().sin()) / 8.0 > BOW
            })
            .collect();
        let fixed: Vec<bool> = (0..n)
            .map(|i| {
                let straight = |e: Option<usize>| e.is_some_and(|e| curve.straight[e]);
                curve.corner[i] || straight(curve.edge_before(i)) || straight(curve.edge_after(i))
            })
            .collect();
        curve.relax(&fixed);
        curve
    }

    fn previous(&self, i: usize) -> Option<usize> {
        match i {
            0 if self.closed => Some(self.points.len() - 1),
            0 => None,
            i => Some(i - 1),
        }
    }

    fn next(&self, i: usize) -> Option<usize> {
        let n = self.points.len();
        match i + 1 {
            j if j < n => Some(j),
            _ if self.closed => Some(0),
            _ => None,
        }
    }

    fn edge_before(&self, i: usize) -> Option<usize> {
        self.previous(i)
    }

    fn edge_after(&self, i: usize) -> Option<usize> {
        self.next(i).map(|_| i)
    }

    /// Taubin smoothing of the points that are neither corners nor ends of
    /// straight runs: each moves along its normal towards the chord of its
    /// neighbours (weighted by closeness), alternately shrinking and
    /// inflating so that the shape keeps its size, and never further than
    /// [`SLACK`] from where it was.
    fn relax(&mut self, fixed: &[bool]) {
        let original = self.points.clone();
        [SHRINK, INFLATE].iter().cycle().take(2 * ROUNDS).for_each(|&factor| {
            let moved: Vec<V> = (0..self.points.len())
                .map(|i| match (fixed[i], self.previous(i), self.next(i)) {
                    (false, Some(a), Some(c)) => {
                        let (a, b, c) = (self.points[a], self.points[i], self.points[c]);
                        let (before, after) = ((b - a).len(), (c - b).len());
                        let target = (a * after + c * before) * (1.0 / (before + after));
                        let normal = (c - a).unit().perp();
                        let to = b + normal * (normal.dot(target - b) * factor);
                        let shift = to - original[i];
                        if shift.len() > SLACK {
                            original[i] + shift.unit() * SLACK
                        } else {
                            to
                        }
                    }
                    _ => self.points[i],
                })
                .collect();
            self.points = moved;
        });
    }

    /// The direction the curve passes point `i` in, or `None` at a corner:
    /// along a straight run next to it, otherwise that of the parabola
    /// through the point and its neighbours (Bessel's tangent).
    fn tangent(&self, i: usize) -> Option<V> {
        if self.corner[i] {
            return None;
        }
        let (before, after) = (self.edge_before(i)?, self.edge_after(i)?);
        let p = &self.points;
        let n = p.len();
        let (incoming, outgoing) = (p[i] - p[before], p[(after + 1) % n] - p[i]);
        match (self.straight[before], self.straight[after]) {
            (true, false) => Some(incoming.unit()),
            (false, true) => Some(outgoing.unit()),
            (true, true) => None,
            (false, false) => Some((incoming.unit() * outgoing.len() + outgoing.unit() * incoming.len()).unit()),
        }
    }

    fn segments(&self) -> Vec<Segment> {
        let n = self.points.len();
        let edges = if self.closed { n } else { n - 1 };
        (0..edges)
            .map(|i| {
                let (from, to) = (self.points[i], self.points[(i + 1) % n]);
                if self.straight[i] {
                    return Segment::Line(to);
                }
                let chord = to - from;
                let along = chord.unit();
                // A free end mirrors the other end's tangent about the chord.
                let mirror = |t: V| along * (2.0 * t.dot(along)) - t;
                let (start, end) = match (self.tangent(i), self.tangent((i + 1) % n)) {
                    (None, None) => return Segment::Line(to),
                    (Some(start), None) => (start, mirror(start)),
                    (None, Some(end)) => (mirror(end), end),
                    (Some(start), Some(end)) => (start, end),
                };
                if start.dot(along) < MIN_COSINE || end.dot(along) < MIN_COSINE {
                    return Segment::Line(to);
                }
                let handle = chord.len() * handle_factor(angle(start, along) + angle(along, end));
                Segment::Curve(from + start * handle, to - end * handle, to)
            })
            .collect()
    }
}

/// Whether a point turning by `turn` radians between edges of `lengths`
/// is a corner, given the turns at its neighbours. Turns of 60° and more
/// are; so are those of 35° and more unless the turn is spread over the
/// neighbours too (the point is on a tight curve, like those of dots and
/// balls) and rounding it would not bend the longer edge visibly. Smaller
/// turns between edges that must stay straight keep their kink as well
/// (see [`Curve::tangent`]).
fn is_corner(turn: f64, neighbours: [Option<f64>; 2], lengths: [f64; 2]) -> bool {
    let size = turn.abs();
    let spread = neighbours.iter().flatten().any(|&t| t * turn > 0.0 && t.abs() >= size / 3.0);
    let bow = lengths[0].max(lengths[1]) * (size / 2.0).sin() / 4.0;
    size >= SHARP || (size >= CORNER && !(spread && bow <= BOW))
}

/// Control points of a curve turning by `turn` lie this many chords from
/// its ends: exact for an arc of a circle, a third for a flat curve.
fn handle_factor(turn: f64) -> f64 {
    let turn = turn.abs().min(PI);
    if turn < 1e-6 {
        1.0 / 3.0
    } else {
        2.0 / 3.0 * (turn / 4.0).tan() / (turn / 2.0).sin()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::symbols::SymbolLibrary;

    fn record(x: f32, y: f32, pen: i16) -> DrwRecord {
        DrwRecord { x, y, pen }
    }

    /// Distance from `p` to the polyline `line`.
    fn distance(p: (f64, f64), line: &[(f64, f64)]) -> f64 {
        line.windows(2)
            .map(|w| {
                let (a, b) = (V::new(w[0].0, w[0].1), V::new(w[1].0, w[1].1));
                let (ab, ap) = (b - a, V::new(p.0, p.1) - a);
                let t = if ab.len() == 0.0 { 0.0 } else { (ap.dot(ab) / ab.dot(ab)).clamp(0.0, 1.0) };
                (ap - ab * t).len()
            })
            .fold(f64::INFINITY, f64::min)
    }

    #[test]
    fn the_octagon_of_a_dot_becomes_round() {
        // LB0020 slot 4, the dot, ends on its first two points.
        let dot: Vec<DrwRecord> =
            [(32, -2), (32, 3), (36, 7), (41, 7), (45, 3), (45, -2), (41, -6), (36, -6), (32, -2), (32, 3)]
                .iter()
                .enumerate()
                .map(|(i, &(x, y))| record(x as f32, y as f32, if i == 0 { 2 } else { 0 }))
                .collect();
        let outline = Outline::of(&dot);
        assert!(matches!(outline.paths[0].segments[..], [Segment::Curve(..), ..]));
        assert_eq!(outline.paths[0].segments.len(), 8);
        let line = &outline.polyline(16)[0];
        let centre = (38.5, 0.5);
        let radii: Vec<f64> = line.iter().map(|&(x, y)| (x - centre.0).hypot(y - centre.1)).collect();
        let (min, max) = radii.iter().fold((f64::INFINITY, 0.0_f64), |(lo, hi), &r| (lo.min(r), hi.max(r)));
        assert!(max - min < 0.5, "radii {min}..{max}");
    }

    #[test]
    fn corners_and_straight_runs_stay() {
        // A flag-like shape: a long straight edge, a sharp corner, a curve.
        let shape: Vec<DrwRecord> = [(0, 0), (0, 100), (4, 98), (8, 95), (11, 91), (13, 86), (14, 80), (0, 0)]
            .iter()
            .enumerate()
            .map(|(i, &(x, y))| record(x as f32, y as f32, if i == 0 { 2 } else { 0 }))
            .collect();
        let outline = Outline::of(&shape);
        let segments = &outline.paths[0].segments;
        assert_eq!(segments[0], Segment::Line(V::new(0.0, 100.0)), "the stem stays straight");
        assert!(matches!(segments[2], Segment::Curve(..)));
        assert!(matches!(segments.last(), Some(Segment::Line(_))), "{segments:?}");
    }

    #[test]
    fn library_outlines_stay_near_their_points_and_gain_points() {
        let library = SymbolLibrary::bundled();
        let (mut before, mut after) = (0, 0);
        (0..2400).filter_map(|n| library.symbol(n)).for_each(|symbol| {
            let outline = Outline::of(&symbol.records);
            let lines = outline.polyline(8);
            let mut runs: Vec<Vec<(f64, f64)>> = Vec::new();
            symbol.records.iter().for_each(|r| match (pen(r.pen), runs.last_mut()) {
                (Pen::Continue, Some(run)) => run.push((f64::from(r.x), f64::from(r.y))),
                _ => runs.push(vec![(f64::from(r.x), f64::from(r.y))]),
            });
            assert_eq!(runs.len(), lines.len(), "{}", symbol.name);
            runs.iter().zip(&lines).for_each(|(run, line)| {
                before += run.len();
                after += line.len();
                let line = [line.as_slice(), &line[..1]].concat();
                run.iter().for_each(|&p| {
                    let d = distance(p, &line);
                    assert!(d <= 0.5, "{} point {p:?} is {d} from its curve", symbol.name);
                });
            });
        });
        assert!(after > 3 * before, "{before} points became {after}");
    }
}
