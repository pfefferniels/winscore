//! Code 14: barlines, braces and brackets (draw_barline 0x4117B0).
//!
//! P2 lowest staff, P3 position (+ P7 unless P15 is set), P4 staves spanned
//! (999 = up to the highest staff, negative = invisible), P5 type, P6
//! thickness, P8 bracket ends, P10/P11 bottom and top level in scale steps,
//! P12 dot size, P13/P14 extra spacing, P16 dot levels, P17 spacing as on a
//! staff of that size, P18/P19 gap. The construction follows
//! `analysis/engine/barlines.md`; constants are REAL*4 as in the engine. The
//! bars have the widths of SCORE's print output on every medium, where the
//! engine's screen draws every bar one unit wide.

use crate::canvas::{Canvas, Pen};
use crate::codes::boxes::{draw_box, BoxCall, CIRCLE_SHAPE};
use crate::codes::line::{self, Params};
use crate::codes::rest;
use crate::document::{Document, ItemRef};
use crate::geometry::{print_width, spline_through, PRINT_PIXEL};
use crate::page::P3_UNIT;
use crate::staff::{Staff, STEP_UNIT, UNITS_PER_SCALE_STEP};
use crate::symbols::{draw_clef, ItemContext};
use crate::text::Font;
use score_format::Item;
use crate::units::{constant, real, trunc, Pos};

/// The highest staff number a barline may reach.
const LAST_STAFF: i32 = 256;

/// P5 = -44: a barline followed by a two-bar repeat sign (drawn by the rest routine).
const TWO_BAR_REPEAT: i32 = -44;

const DOUBLE: i32 = 1;
const FINAL: i32 = 2;
const REPEAT_LEFT: i32 = 3;
const REPEAT_RIGHT: i32 = 4;
const REPEAT_BOTH: i32 = 5;
const REPEAT_HEAVY: i32 = 6;
const DASHED: i32 = 7;
const BRACE: i32 = 8;
const BRACKET: i32 = 9;
const SQUARE_BRACKET: i32 = 10;

/// The brace in the symbol library (LB0000.DRW slot 5).
const BRACE_SYMBOL: i32 = 5;

/// The state draw_barline works on: positions in internal coordinates and
/// the parameters it changes while drawing.
struct Barline {
    kind: i32,
    /// The bar's x (0x1F95D58).
    xb: f64,
    /// The item's x as the dot routine sees it (X_POS).
    x_pos: f64,
    bottom: f64,
    top: f64,
    /// The spacing unit: the step unit of staff P2, or 25 × P17 (0x2052C08).
    unit: f64,
    /// Staves spanned.
    span: i32,
    low: Staff,
    /// trunc(P8), which the dot and bracket routines overwrite.
    ip8: i32,
    /// P4 as draw_line later reads it: the span, recomputed for 999.
    p4: f32,
    /// Dash and space length (P8, P9); an invisible bar sets 0.3 and 1.5.
    dash: (f32, f32),
}

/// barline_stroke 0x412699 adds a second stroke a print pixel (0x78B480)
/// right of the first when printing: the bar is that much wider than the
/// default pen, drawn as one stroke.
const STROKE_PIXELS: f32 = 1.0;

/// The rest item draw_barline draws after a two-bar-repeat bar (P5 = -44):
/// the barline with P4 = 0 and P5 = -44, drawn by draw_rest at the bar's
/// X_POS. Only a plain visible bar (P4 >= 0, P6 = 0) reaches that call.
fn two_bar_sign(item: ItemRef<'_>) -> Option<Item> {
    let plain = item.ip(5) == TWO_BAR_REPEAT && item.ip(4) >= 0 && item.p(6) == 0.0;
    plain.then(|| item.with_params(&[(4, 0.0), (5, TWO_BAR_REPEAT as f32)]))
}

/// The font a barline leaves loaded for the next item: that of the number
/// over a two-bar repeat (see [`crate::text::font_loaded`]).
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    let sign = two_bar_sign(item)?;
    rest::font_loaded(doc, item.changed(&sign))
}

/// Where a barline runs (internal coordinates), from the bottom of its own
/// staff to the top of the highest staff it spans, and that span, as
/// [`render`] places it, for an editor's handle on its top.
pub fn reach(doc: &Document<'_>, item: ItemRef<'_>) -> (Pos, Pos, i32) {
    let low = doc.staff_of(item);
    let span = match trunc(f64::from(item.p(4))) {
        999 => doc.staves.highest().unwrap_or(item.staff()) - item.staff() + 1,
        span => span.abs(),
    };
    let span = span.min(LAST_STAFF - low.number + 1).max(1);
    let kind = if item.p(4) < 0.0 { DASHED } else { trunc(f64::from(item.p(5))) };
    let (bottom_level, top_level) = match kind {
        SQUARE_BRACKET => (7.0, 7.0),
        k if k >= BRACKET => (1.0, 13.0),
        _ => (3.0, 11.0),
    };
    let level = |n: usize, default: f64| match item.p(n) {
        _ if item.ip(4) == 999 => default,
        0.0 => default,
        p => f64::from(p),
    };
    let x = doc.position(item).x;
    let x = match (item.p(7), item.p(15)) {
        (p7, p15) if p7 != 0.0 && p15 == 0.0 => real(f64::from(p7) * P3_UNIT + x),
        _ => x,
    };
    let high = doc.staves.get(low.number + span - 1);
    (Pos::new(x, low.y(level(10, bottom_level))), Pos::new(x, high.y(level(11, top_level))), span)
}

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let mut kind = trunc(f64::from(item.p(5)));
    if kind == TWO_BAR_REPEAT {
        kind = 0;
    }
    let mut span = trunc(f64::from(item.p(4)));
    let mut p4 = item.p(4);
    let (mut p10, mut p11) = (item.p(10), item.p(11));
    if span == 999 {
        span = doc.staves.highest().unwrap_or(item.staff()) - item.staff() + 1;
        p4 = span as f32;
        (p10, p11) = (0.0, 0.0);
    }
    let mut gap_p5 = item.p(5);
    let mut dash = (item.p(8), item.p(9));
    if span < 0 {
        if !doc.screen() {
            return;
        }
        span = -span;
        kind = DASHED;
        gap_p5 = DASHED as f32;
        dash = (0.3, 1.5);
    }
    let low = doc.staff_of(item);
    span = span.min(LAST_STAFF - low.number + 1).max(1);
    let (bottom_level, top_level) = match kind {
        SQUARE_BRACKET => (7.0, 7.0),
        k if k >= BRACKET => (1.0, 13.0),
        _ => (3.0, 11.0),
    };
    let level = |p: f32, default: f64| if p == 0.0 { default } else { f64::from(p) };
    let high = doc.staves.get(low.number + span - 1);
    let x = doc.position(item).x;
    let x_pos = match (item.p(7), item.p(15)) {
        (p7, p15) if p7 != 0.0 && p15 == 0.0 => real(f64::from(p7) * P3_UNIT + x),
        _ => x,
    };
    let unit = match item.p(17) {
        0.0 => low.step,
        p17 => real(f64::from(p17) * STEP_UNIT),
    };
    let mut bar = Barline {
        kind,
        xb: x_pos,
        x_pos,
        bottom: low.y(level(p10, bottom_level)),
        top: high.y(level(p11, top_level)),
        unit,
        span,
        low,
        ip8: trunc(f64::from(item.p(8))),
        p4,
        dash,
    };
    bar.draw(doc, item, canvas);
    if let Some(sign) = two_bar_sign(item) {
        rest::draw(doc, item.changed(&sign), bar.x_pos, canvas);
    }
    if item.p(18) != 0.0 && gap_p5 < 2.0 {
        gap(item, &bar, canvas);
    }
}

impl Barline {
    fn draw(&mut self, doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
        let u = self.unit;
        let d13 = real(u * 6.0 * f64::from(item.p(13)));
        let d14 = real(u * 6.0 * f64::from(item.p(14)));
        match self.kind {
            0 if item.p(6) != 0.0 => self.thick(canvas, self.p6_left(item), self.xb),
            0 => self.stroke(canvas, self.xb),
            DOUBLE => {
                self.stroke(canvas, self.xb);
                self.stroke(canvas, real(self.xb - u * constant(7.5) - d13));
            }
            FINAL => self.final_bar(canvas, d13),
            REPEAT_LEFT => {
                self.x_pos = real(self.x_pos - d13 - d14);
                self.dots(doc, item, canvas, constant(-25.5));
                self.final_bar(canvas, d13);
            }
            REPEAT_RIGHT | REPEAT_BOTH => {
                self.stroke(canvas, real(u * constant(7.8) + self.xb + d13));
                self.x_pos = real(d13 + self.x_pos + d14);
                self.dots(doc, item, canvas, constant(19.5));
                if self.kind == REPEAT_BOTH {
                    self.x_pos = real(self.x_pos - d13 - d14);
                    self.x_pos = real(self.x_pos - d13 - d14);
                    self.dots(doc, item, canvas, constant(-25.5));
                    self.stroke(canvas, real(self.xb - u * constant(13.8) - d13));
                }
                self.heavy(canvas);
            }
            REPEAT_HEAVY => {
                self.x_pos = real(self.x_pos - d14);
                self.dots(doc, item, canvas, constant(-18.36));
                self.x_pos = real(d13 + self.x_pos + d14 + d14);
                self.dots(doc, item, canvas, constant(25.2));
                self.heavy(canvas);
                self.xb = real(u * 13.0 + self.xb + d13);
                self.heavy(canvas);
            }
            BRACE => self.brace(doc, item, canvas),
            BRACKET => {
                if self.ip8 != 3 {
                    self.bracket_ends(canvas);
                }
                let a = real(self.xb - u * constant(9.6));
                self.thick(canvas, a, real(a - u * constant(4.5)));
            }
            SQUARE_BRACKET => self.square_bracket(canvas),
            k if k > REPEAT_HEAVY => self.dashed(item, canvas),
            _ => self.heavy(canvas),
        }
    }

    /// Types 7 and above other than 8–10, and invisible bars on the screen:
    /// a vertical dashed line drawn by the code-4 routine (draw_line
    /// 0x439963) with P5 = the top as a level of staff P2, P6 = P3, IP7 = 1,
    /// IP10 = IP6 or (OUTPUT_MODE != 0), which is 1 on the screen and in
    /// print, P8 dash (default 1), P9 space (default 2).
    fn dashed(&self, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
        let staff = &self.low;
        let top_level = real((self.top - f64::from(staff.level0)) / (staff.step * 7.0));
        let default = |p: f32, value: f32| if p == 0.0 { value } else { p };
        let thickness = match trunc(f64::from(item.p(6))) {
            0 => 1,
            ip6 => ip6,
        };
        let params = Params::of(item)
            .with(4, self.p4)
            .with(5, top_level as f32)
            .with(6, item.p(3))
            .with(7, 1.0)
            .with(8, default(self.dash.0, 1.0))
            .with(9, default(self.dash.1, 2.0))
            .with(10, thickness as f32);
        line::draw(&params, Pos::new(self.x_pos, self.bottom), staff, canvas);
    }

    /// barline_stroke 0x412699.
    fn stroke(&self, canvas: &mut Canvas<'_>, x: f64) {
        canvas.set_width(print_width(STROKE_PIXELS));
        canvas.segment(Pos::new(x, self.bottom), Pos::new(x, self.top));
        canvas.set_width(0.0);
    }

    /// The left edge of a P6 bar (0x411F7C): P6 + 1 print pixels left of
    /// the bar's x (on the engine's screen no width at all).
    fn p6_left(&self, item: ItemRef<'_>) -> f64 {
        real(self.xb - (f64::from(item.p(6)) + 1.0) * PRINT_PIXEL)
    }

    fn final_bar(&self, canvas: &mut Canvas<'_>, d13: f64) {
        let u = self.unit;
        self.stroke(canvas, real(self.xb - u * constant(13.8) - d13));
        self.heavy(canvas);
    }

    /// The thick bar of width 6 units ending at the bar's x.
    fn heavy(&self, canvas: &mut Canvas<'_>) {
        self.thick(canvas, real(self.xb - self.unit * 6.0), self.xb);
    }

    /// The thick bar between `a` and `b` (block 0x411FAD), emitted as the
    /// engine does: a diagonal hairline, then the filled rectangle, with a
    /// doubled last point while IP8 is 0 or 1.
    fn thick(&self, canvas: &mut Canvas<'_>, a: f64, b: f64) {
        let (bottom, top) = (self.bottom, self.top);
        canvas.point(Pos::new(a, bottom), Pen::Stroke);
        canvas.point(Pos::new(b, top), Pen::Continue);
        canvas.point(Pos::new(b, top), Pen::Fill);
        [(b, bottom), (a, bottom), (a, top), (b, top)]
            .into_iter()
            .for_each(|(x, y)| canvas.point(Pos::new(x, y), Pen::Continue));
        self.close(canvas, b);
    }

    fn close(&self, canvas: &mut Canvas<'_>, b: f64) {
        if matches!(self.ip8, 0 | 1) {
            canvas.point(Pos::new(b, self.top), Pen::Continue);
        }
    }

    /// barline_brace 0x412B93: draw_clef with symbol 5 at 21 steps below the
    /// bar's bottom, stretched to its height and widened with it unless P6
    /// gives the width factor.
    fn brace(&self, doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
        let step = self.low.step;
        let height = real((self.top - self.bottom) * constant(0.0054945) / step);
        let width = match item.p(6) {
            0.0 => real((height - 1.0) / 2.0 + 1.0),
            p6 => f64::from(p6),
        };
        let at = Pos::new(self.x_pos, real(self.bottom - step * 21.0));
        // draw_clef reads IP4 (mini clefs) and IP10 (pixels); the brace routine sets IP10 = 0.
        let context = ItemContext { ip4: trunc(f64::from(self.p4)), pixels: 0, ..ItemContext::of(item) };
        draw_clef(doc, &context, canvas, at, step, BRACE_SYMBOL, (width, height));
    }

    /// Type 10: an open bracket left of the bar on the middle lines.
    fn square_bracket(&self, canvas: &mut Canvas<'_>) {
        let u = self.unit;
        let b = real(self.xb - u * 21.0);
        let a = real(b - u * 15.0);
        let (bottom, top) = (self.bottom, self.top);
        if matches!(self.ip8, 0 | 2) {
            canvas.point(Pos::new(b, bottom), Pen::Stroke);
            canvas.point(Pos::new(a, bottom), Pen::Continue);
        } else {
            canvas.point(Pos::new(a, bottom), Pen::Stroke);
        }
        canvas.point(Pos::new(a, top), Pen::Continue);
        if matches!(self.ip8, 0 | 1) {
            canvas.point(Pos::new(b, top), Pen::Continue);
        }
        self.close(canvas, b);
    }

    /// barline_bracket 0x412A20: the curved ends of a bracket, filled; P8 = 1
    /// draws only the top end, 2 only the bottom end. Leaves IP8 = 1.
    fn bracket_ends(&mut self, canvas: &mut Canvas<'_>) {
        let step = real(self.unit * constant(0.15));
        let x0 = real(self.x_pos - self.unit * 12.0);
        let ends = match self.ip8 {
            1 => vec![(self.top, step)],
            2 => vec![(self.bottom, -step)],
            _ => vec![(self.top, step), (self.bottom, -step)],
        };
        ends.into_iter().for_each(|(y, sign)| {
            canvas.point(Pos::new(x0, real(-(sign * 33.0) + y)), Pen::Fill);
            let place = |(tx, ty): (f32, f32)| Pos::new(real(step * f64::from(tx) + x0), real(sign * f64::from(ty) + y));
            smooth_bracket_end().into_iter().for_each(|t| canvas.point(place(t), Pen::Continue));
        });
        self.ip8 = 1;
    }

    /// barline_dots 0x412749: two repeat dots on every spanned staff, `f`
    /// spacing units right of X_POS, at levels 6 and 8 or as P16 = xyz says
    /// (x lower, yz upper). Leaves IP8 = 0.
    fn dots(&mut self, doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, f: f64) {
        let x = real(self.unit * f + self.x_pos);
        let (lower, rise) = match trunc(f64::from(item.p(16))) {
            0 => (6, 2),
            xyz => (xyz / 100, xyz % 100 - xyz / 100),
        };
        let rise = if rise == 0 { 2 } else { rise };
        let size = real(constant(0.58) * if item.p(12) == 0.0 { 1.0 } else { f64::from(item.p(12)) });
        let call = dot_call(item, size);
        let last = (self.low.number + self.span - 1).min(LAST_STAFF);
        (self.low.number..=last).for_each(|number| {
            let staff = doc.staves.get(number);
            let first = real(f64::from(staff.level0) + staff.step * f64::from(lower) * UNITS_PER_SCALE_STEP);
            let second = real(staff.step * f64::from(rise) * UNITS_PER_SCALE_STEP + first);
            [first, second].into_iter().for_each(|y| draw_box(canvas, Pos::new(x, y), staff.step, &call));
        });
        self.ip8 = 0;
    }
}

/// The draw_box call barline_dots makes in print: a filled circle of `size`,
/// round, the integer parameters cleared, the barline's own P8, P9, P10 and
/// P16 left in place (P16 = 1 is draw_box's inch flag, so it enlarges the
/// dots). On the screen the engine draws hexagons (IP12 = 60).
fn dot_call(item: ItemRef<'_>, size: f64) -> BoxCall {
    BoxCall {
        kind: CIRCLE_SHAPE,
        width: size,
        height: size,
        p8: f64::from(item.p(8)),
        ip8: 0,
        p9: f64::from(item.p(9)),
        ip9: 0,
        p10: f64::from(item.p(10)),
        ip10: 0,
        ip11: 0,
        ip12: 0,
        fill: true,
        p16: f64::from(item.p(16)),
    }
}

/// The bracket end outline, in 0.15 spacing units (f32 tables at 0x78B264 and 0x78B234).
const BRACKET_CURVE: [(f32, f32); 12] = [
    (60.0, -33.0),
    (92.0, -29.0),
    (122.0, -18.0),
    (148.0, 0.0),
    (169.0, 24.0),
    (192.0, 60.0),
    (162.0, 28.0),
    (143.0, 15.0),
    (117.0, 5.0),
    (79.0, 0.0),
    (0.0, 0.0),
    (0.0, -33.0),
];

/// The outline of a bracket end: [`BRACKET_CURVE`] with its two curves (up
/// to the tip and back) drawn as splines through the engine's points,
/// meeting the straight edges smoothly.
fn smooth_bracket_end() -> Vec<(f32, f32)> {
    let at = |k: usize| Pos::new(f64::from(BRACKET_CURVE[k].0), f64::from(BRACKET_CURVE[k].1));
    let points = |range: std::ops::RangeInclusive<usize>| range.map(at).collect::<Vec<_>>();
    // Points 0..=5 run from the bottom edge up to the tip, 5..=9 back down
    // to the top edge; the start and points 10 and 11 close it straight.
    let start = Pos::new(0.0, -33.0);
    let outer = spline_through(Some(start), &points(0..=5), None, BRACKET_STEPS);
    let inner = spline_through(None, &points(5..=9), Some(at(10)), BRACKET_STEPS);
    let outline = outer.into_iter().chain(inner.into_iter().skip(1)).chain(points(10..=11));
    outline.map(|p| (p.x as f32, p.y as f32)).collect()
}

/// Segments of a bracket end's curves per point of the engine's.
const BRACKET_STEPS: usize = 8;

/// The gap barline_gap 0x412353 leaves between y0 and y1 (the bottom and
/// top of the first stroke): P19 scale steps centred P18 (a fraction, or a
/// percentage above 1) of the way up.
fn gap_span(item: ItemRef<'_>, bar: &Barline, y0: f64, y1: f64) -> (f64, f64) {
    let height = real(y1 - y0);
    let p18 = item.p(18);
    let fraction = f64::from(if p18 > 1.0 { p18 / 100.0 } else { p18 });
    let centre = real(fraction * height + y0);
    let size = real(bar.low.step * f64::from(item.p(19)) * 7.0);
    let lo = real(centre - size / 2.0);
    (lo, real(size + lo))
}

/// barline_gap 0x412353: the bar drawn again below and above the gap, its
/// strokes as wide as before and a P6 bar as two rectangles (the engine
/// replaces the strokes in the point buffer by two each, keeping only a
/// rectangle's sides, or its diagonal on the screen).
fn gap(item: ItemRef<'_>, bar: &Barline, canvas: &mut Canvas<'_>) {
    let buffer = canvas.buffer_mut();
    let (Some(first), Some(second)) = (buffer.first().copied(), buffer.get(1).copied()) else {
        return;
    };
    let (y0, y1) = (f64::from(first.at.y), f64::from(second.at.y));
    let (lo, hi) = gap_span(item, bar, y0, y1);
    let lines = if item.p(5) == 1.0 { 2 } else { 1 };
    let xs: Vec<f64> = buffer.iter().step_by(2).take(lines).map(|p| f64::from(p.at.x)).collect();
    buffer.clear();
    canvas.set_width(0.0);
    let parts = [(y0, lo), (hi, y1)];
    if bar.kind == 0 && item.p(6) != 0.0 {
        let (a, b) = (f64::from(first.at.x), f64::from(second.at.x));
        parts.into_iter().for_each(|(from, to)| {
            canvas.fill([[Pos::new(b, from), Pos::new(a, from), Pos::new(a, to), Pos::new(b, to)]]);
        });
    } else {
        canvas.set_width(print_width(STROKE_PIXELS));
        xs.into_iter().for_each(|x| {
            parts.into_iter().for_each(|(from, to)| canvas.segment(Pos::new(x, from), Pos::new(x, to)));
        });
        canvas.set_width(0.0);
    }
}

#[cfg(test)]
mod tests {
    use score_format::{Item, MusFile, Word};

    use super::*;
    use crate::display::{print_pen, ItemId, Shape, ShapeKind};
    use crate::document::{Medium, Options};

    /// The shapes of `item` after a size-1 staff 1, drawn for `options`.
    fn shapes(item: &[f32], options: Options) -> Vec<Shape> {
        let trailer = [0.0_f32, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = (trailer.len() as u16).to_le_bytes().to_vec();
        bytes.extend(trailer.iter().flat_map(|w| w.to_le_bytes()));
        let mut file = MusFile::parse(&bytes).expect("an empty file parses");
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        file.items = vec![words(&[8.0, 1.0, 0.0, 0.0, 1.0]), words(item)];
        let list = crate::render(&Document::with_options(&file, options));
        list.shapes.into_iter().filter(|s| s.source == Some(ItemId(1))).collect()
    }

    #[test]
    fn bars_have_the_doubled_print_stroke_width() {
        let bar = shapes(&[14.0, 1.0, 100.0, 1.0], Options::default());
        assert_eq!((bar.len(), bar[0].paths.len()), (1, 1));
        assert_eq!(bar[0].width, print_pen(1.0));
        let stroke = &bar[0].paths[0];
        assert_eq!((stroke.len(), stroke[0].x), (2, stroke[1].x));
        assert!(stroke[1].y > stroke[0].y, "upward from the bottom line");
    }

    #[test]
    fn a_p6_bar_is_p6_plus_one_print_pixels_wide() {
        let bar = shapes(&[14.0, 1.0, 100.0, 1.0, 0.0, 3.0], Options::default());
        let fill = bar.iter().find(|s| s.kind == ShapeKind::Fill).expect("the thick bar");
        let xs = fill.paths[0].iter().map(|p| p.x);
        let width = xs.clone().max().expect("corners") - xs.min().expect("corners");
        assert!((f64::from(width) - 4.0 * PRINT_PIXEL).abs() <= 1.0);
    }

    #[test]
    fn repeat_dots_are_round_on_every_medium() {
        let print = Options { medium: Medium::Print, ..Options::default() };
        for options in [Options::default(), print] {
            let bar = shapes(&[14.0, 1.0, 100.0, 1.0, 4.0], options);
            let dots: Vec<Shape> = bar.into_iter().filter(|s| s.kind == ShapeKind::Fill && s.paths[0].len() != 6).collect();
            assert_eq!(dots.len(), 2);
            assert!(dots.iter().all(|d| d.paths[0].len() == 37 && d.width == crate::geometry::HAIRLINE));
        }
    }

    #[test]
    fn bracket_ends_follow_the_engine_points_smoothly() {
        let end = smooth_bracket_end();
        assert_eq!(end.len(), 5 * BRACKET_STEPS + 4 * BRACKET_STEPS + 1 + 2);
        BRACKET_CURVE.iter().take(10).for_each(|p| assert!(end.contains(p), "{p:?}"));
        assert_eq!(end[end.len() - 2..], BRACKET_CURVE[10..]);
    }
}
