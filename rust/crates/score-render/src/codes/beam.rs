//! Code 6: beams (draw_beam 0x416168).
//!
//! P3/P6 left and right end, P4/P5 the note levels at the ends (the beam's
//! stem-side edge lies seven scale steps beyond them), P7 = XY stem direction
//! and number of full beams (negative: tremolo beams, P10 of them, P11 their
//! position, P12 their width), P9 = abc end offsets onto the other stem side,
//! P10 and P13 partial groups (XY: displacement, count) with ends P11/P12 and
//! P14/P15, P14/P15 note offsets when P13 = 0, P17 thickness, P18 size, P20
//! note width, P21 spacing. A beam reads no other item.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::page::P3_UNIT;
use crate::units::{constant, real, trunc, Pos};

/// Note-head width in step units: the stem of an up-stem note stands this
/// far right of its P3 (global 0x78B34C, 17 after start-up).
const NOTE_WIDTH: f32 = 17.0;

const STEMS_UP: i32 = 1;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let beam = Beam::new(doc, item);
    let plan = beam.plan(item);
    let main = plan.main.map_or(beam.main.edge, |count| beam.group(canvas, beam.main.edge, count));
    let partials = plan.first.iter().chain(plan.second.iter());
    partials.fold(main, |last, partial| beam.partial(canvas, last, partial));
}

/// The stem-side edge of one beam.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Edge {
    left: Pos,
    right: Pos,
}

impl Edge {
    /// The edge of the next beam, `spacing` further towards the notes.
    fn next(self, spacing: f64) -> Edge {
        let shift = |p: Pos| Pos::new(p.x, real(p.y - spacing));
        Edge { left: shift(self.left), right: shift(self.right) }
    }
}

/// The main beam's edge as the line y = slope·x + intercept.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Line {
    edge: Edge,
    dx: f64,
    dy: f64,
    slope: f64,
    intercept: f64,
}

impl Line {
    fn through(edge: Edge) -> Self {
        let dx = match real(edge.right.x - edge.left.x) {
            0.0 => constant(100.0),
            dx => dx,
        };
        let dy = real(edge.right.y - edge.left.y);
        let slope = real(dy / dx);
        Self { edge, dx, dy, slope, intercept: real(edge.left.y - edge.left.x * slope) }
    }

    fn y(&self, x: f64, drop: f64) -> f64 {
        real(x * self.slope + self.intercept - drop)
    }
}

/// One end of a partial beam.
#[derive(Debug, Clone, Copy, PartialEq)]
enum End {
    /// 16.2 units from the other end.
    Free,
    /// At a position in P3 units.
    At(f64),
}

impl End {
    /// A partial end parameter and its truncation: 0 = free, -1 = the main
    /// beam's end, otherwise the position itself.
    fn from_param(value: f32, main_end: f64) -> Self {
        match trunc(f64::from(value)) {
            0 => End::Free,
            -1 => End::At(main_end),
            _ => End::At(f64::from(value)),
        }
    }
}

/// A group of partial or tremolo beams.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Partial {
    /// P10 or P13: tens = displacement in beam spacings, units = number of beams.
    code: i32,
    left: End,
    right: End,
    /// One digit of P9: 1 left, 2 right, 3 both ends shifted to the other stem side.
    flags: i32,
    /// A tremolo across a single stem: drawn at the main edge's own height
    /// instead of along its line.
    across_stem: bool,
}

/// Which beams draw_beam draws: full beams, then up to two partial groups.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Plan {
    main: Option<i32>,
    first: Option<Partial>,
    second: Option<Partial>,
}

/// What draw_beam derives from the parameters before it draws.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Beam {
    /// The beam unit: the staff's step unit (× P18), × 0.6 for cue beams.
    unit: f64,
    /// Moves partial ends from note positions onto up-stems; 0 for down-stems.
    stem_shift: f64,
    /// Moves an end flagged in P9 onto the other side of its note.
    flag_shift: f64,
    /// From one beam to the next, signed towards the notes.
    spacing: f64,
    /// Signed away from the edge, into the beam.
    thickness: f64,
    /// P3 and P6 after note offsets, in P3 units.
    left: f64,
    right: f64,
    /// P9.
    flags: i32,
    main: Line,
    /// Print output closes each beam with one more point (0x4A060D).
    print: bool,
}

impl Beam {
    fn new(doc: &Document<'_>, item: ItemRef<'_>) -> Self {
        let staff = doc.staff_of(item);
        let width = match item.p(20) {
            0.0 => 1.0,
            p20 => f64::from(p20),
        };
        let (step, p4) = match item.p(18) {
            0.0 => (staff.step, trunc(f64::from(item.p(4)))),
            p18 => (real(f64::from(p18) * staff.step), 0),
        };
        let cue = p4.abs() >= 100;
        let unit = real(if cue { constant(0.6) } else { 1.0 } * step);
        let p17 = match item.p(17) {
            0.0 if cue => constant(0.8),
            p17 => f64::from(p17),
        };

        let offsets_from_p14 = trunc(f64::from(item.p(13))) == 0;
        let note_offset = |end: f64, p: f32| match p {
            p if offsets_from_p14 && p != 0.0 => real(note_offset(p, unit, width) + end),
            _ => end,
        };
        let left = note_offset(f64::from(item.p(3)), item.p(14));
        let right = note_offset(f64::from(item.p(6)), item.p(15));

        let p7 = trunc(f64::from(item.p(7))).abs();
        let up = p7 / 10 == STEMS_UP;
        let stem = real(unit * constant(49.0));
        let spacing = match item.p(21) {
            0.0 => real(unit * constant(10.5)),
            p21 => real(f64::from(p21) * real(unit * constant(10.5))),
        };
        let note_width = real(unit * constant(NOTE_WIDTH) * width);
        let thickness = match p17 {
            0.0 => real(unit * constant(7.0)),
            p17 => real(p17 * real(unit * constant(7.0))),
        };
        let (stem_shift, flag_shift, stem, spacing, thickness) = if up {
            (note_width, -note_width, stem, spacing, -thickness)
        } else {
            (0.0, note_width, -stem, -spacing, thickness)
        };

        let flags = trunc(f64::from(item.p(9)));
        let mut xl = real(P3_UNIT * left);
        let mut xr = real(P3_UNIT * right);
        if up {
            xl = real(stem_shift + xl);
            xr = real(stem_shift + xr);
        }
        let (shift_left, shift_right) = flagged(flags / 100);
        if shift_left {
            xl = real(flag_shift + xl);
        }
        if shift_right {
            xr = real(flag_shift + xr);
        }
        let yl = real(doc.position(item).y + stem);
        let yr = real(staff.y(f64::from(item.p(5))) + stem);
        let edge = Edge { left: Pos::new(xl, yl), right: Pos::new(xr, yr) };
        let main = Line::through(match trunc(f64::from(item.p(7))) {
            p7 if p7 <= 0 => tremolo_edge(edge, item, unit, cue),
            _ => edge,
        });
        Self { unit, stem_shift, flag_shift, spacing, thickness, left, right, flags, main, print: !doc.screen() }
    }

    fn plan(&self, item: ItemRef<'_>) -> Plan {
        let p7 = trunc(f64::from(item.p(7)));
        let p10 = trunc(f64::from(item.p(10)));
        let second = match trunc(f64::from(item.p(13))) {
            0 => None,
            code => Some(Partial {
                code,
                left: End::from_param(item.p(14), self.left),
                right: End::from_param(item.p(15), self.right),
                flags: self.flags % 10,
                across_stem: false,
            }),
        };
        let digit_b = self.flags % 100 / 10;
        let full = p7.abs() % 10;
        let (main, first) = if p7 < 0 {
            (None, Some(self.tremolo(item, p10)))
        } else if p10 == 0 {
            (Some(full), None)
        } else if full == 0 {
            (None, Some(self.floating(item, p10, digit_b)))
        } else if item.p(11) == 0.0 && item.p(12) == 0.0 {
            (Some(full), Some(Partial { flags: digit_b, ..self.floating_default(p10) }))
        } else {
            let left = End::from_param(item.p(11), self.left);
            let right = End::from_param(item.p(12), self.right);
            (Some(full), Some(Partial { code: p10, left, right, flags: digit_b, across_stem: false }))
        };
        Plan { main, first, second }
    }

    /// Tremolo beams (P7 < 0): P10 beams of width P12 (default 4) around
    /// P11, or across the stem at P3 when P11 = 0.
    fn tremolo(&self, item: ItemRef<'_>, code: i32) -> Partial {
        let half = real(self.unit * tremolo_half_width(item) / constant(25.0));
        let across_stem = trunc(f64::from(item.p(11))) == 0;
        let centre = if across_stem { self.left } else { f64::from(item.p(11)) };
        let left = match trunc(f64::from(item.p(11))) {
            -1 => self.left,
            _ => real(centre - half),
        };
        let flags = if self.flags / 100 != 0 { 1 } else { 0 };
        Partial { code, left: End::At(left), right: End::At(real(half + centre)), flags, across_stem }
    }

    /// Floating beams between the stems (P7 = 10 or 20), P11/P12 from the
    /// stems (default 3.5 and -3.5 at size 1).
    fn floating(&self, item: ItemRef<'_>, code: i32, flags: i32) -> Partial {
        let default = self.floating_default(code);
        let note = real(self.stem_shift / P3_UNIT);
        let left = match item.p(11) {
            0.0 => default.left,
            p11 => End::At(real(self.unit * constant(0.11333) + (f64::from(p11) + self.left - note))),
        };
        let right = match item.p(12) {
            0.0 => default.right,
            p12 => End::At(real(f64::from(p12) + self.right - note)),
        };
        Partial { code, left, right, flags, across_stem: false }
    }

    fn floating_default(&self, code: i32) -> Partial {
        let inset = real(self.unit * constant(0.14));
        Partial {
            code,
            left: End::At(real(inset + self.left)),
            right: End::At(real(self.right - inset)),
            flags: 0,
            across_stem: false,
        }
    }

    /// `count` beams (at least one) from `edge` on; returns the last edge.
    fn group(&self, canvas: &mut Canvas<'_>, edge: Edge, count: i32) -> Edge {
        let edges = std::iter::successors(Some(edge), |e| Some(e.next(self.spacing)));
        edges.take(count.max(1) as usize).inspect(|e| self.draw(canvas, *e)).last().unwrap_or(edge)
    }

    /// A partial group after `last`, the edge of the previous group's last beam.
    fn partial(&self, canvas: &mut Canvas<'_>, last: Edge, partial: &Partial) -> Edge {
        let count = (partial.code % 10).abs();
        let drop = real(f64::from(partial.code / 10) * self.spacing);
        let at = |end: End, current: f64| match end {
            End::At(p) => real(p * P3_UNIT + self.stem_shift),
            End::Free => current,
        };
        let mut xl = at(partial.left, self.main.edge.left.x);
        let mut xr = at(partial.right, self.main.edge.right.x);
        let (shift_left, shift_right) = flagged(partial.flags);
        if shift_left {
            xl = real(self.flag_shift + xl);
        }
        if shift_right {
            xr = real(self.flag_shift + xr);
        }
        let free_length = real(self.unit * constant(16.2));
        if partial.right == End::Free {
            xr = real(free_length + xl);
        }
        if partial.left == End::Free {
            xl = real(xr - free_length);
        }
        let main = &self.main.edge;
        let (yl, yr) = if last.left.y == last.right.y {
            (real(main.left.y - drop), real(main.right.y - drop))
        } else if partial.across_stem {
            (last.left.y, last.right.y)
        } else {
            (self.main.y(xl, drop), self.main.y(xr, drop))
        };
        self.group(canvas, Edge { left: Pos::new(xl, yl), right: Pos::new(xr, yr) }, count)
    }

    /// One beam as the quadrilateral of 0x4A060D, started at the right end.
    fn draw(&self, canvas: &mut Canvas<'_>, edge: Edge) {
        let inner = |p: Pos| Pos::new(p.x, real(self.thickness + p.y));
        let corners = [inner(edge.right), edge.right, edge.left, inner(edge.left), inner(edge.right)];
        let closing = self.print.then_some(edge.right);
        canvas.fill([corners.into_iter().chain(closing)]);
    }
}

/// Which ends a P9 digit shifts: 1 left, 2 right, 3 both; any other
/// non-zero digit the left end.
fn flagged(digit: i32) -> (bool, bool) {
    match digit {
        0 => (false, false),
        2 => (false, true),
        3 => (true, true),
        _ => (true, false),
    }
}

/// 0x417221: the shift in P3 units for a note offset (the note's P10) in
/// P14/P15; 10 and 20 stand for a head moved right or left of its stem.
fn note_offset(p: f32, unit: f64, width: f64) -> f64 {
    let head = || real(unit * width * constant(2.833_333_3) / constant(25.0));
    match p {
        10.0 => head(),
        20.0 => -head(),
        p => real(unit * f64::from(p) * constant(0.04)),
    }
}

/// Half the width of tremolo beams in P3 units at size 1: P12/2, default 2.
fn tremolo_half_width(item: ItemRef<'_>) -> f64 {
    match real(f64::from(item.p(12)) * constant(0.5)) {
        0.0 => constant(2.0),
        half => half,
    }
}

/// The main edge for P7 <= 0: a tremolo across one stem (P11 = 0) is a
/// short stroke rising through the stem end; otherwise the edge only gets
/// a length when its ends coincide.
fn tremolo_edge(edge: Edge, item: ItemRef<'_>, unit: f64, cue: bool) -> Edge {
    let scale = if cue { constant(0.6) } else { 1.0 };
    let length = real(scale * constant(1000.0) + edge.left.x);
    if trunc(f64::from(item.p(11))) == 0 {
        let rise = real(unit * constant(2.9166) * tremolo_half_width(item));
        let y = edge.left.y;
        Edge { left: Pos::new(edge.left.x, real(y - rise)), right: Pos::new(length, real(rise + y)) }
    } else if edge.left.x == edge.right.x {
        Edge { right: Pos::new(length, edge.right.y), ..edge }
    } else {
        edge
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn p9_digits() {
        assert_eq!(flagged(0), (false, false));
        assert_eq!(flagged(1), (true, false));
        assert_eq!(flagged(2), (false, true));
        assert_eq!(flagged(3), (true, true));
    }

    #[test]
    fn partial_end_parameters() {
        assert_eq!(End::from_param(0.0, 20.0), End::Free);
        assert_eq!(End::from_param(0.5, 20.0), End::Free);
        assert_eq!(End::from_param(-1.0, 20.0), End::At(20.0));
        assert_eq!(End::from_param(31.5, 20.0), End::At(31.5));
    }
}
