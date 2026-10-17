//! Code 14: barlines, braces and brackets (draw_barline 0x4117B0).
//!
//! P2 lowest staff, P3 position (+ P7 unless P15 is set), P4 staves spanned
//! (999 = up to the highest staff, negative = invisible), P5 type, P6
//! thickness (print only), P8 bracket ends, P10/P11 bottom and top level in
//! scale steps, P12 dot size, P13/P14 extra spacing, P16 dot levels, P17
//! spacing as on a staff of that size, P18/P19 gap. The construction follows
//! `analysis/engine/barlines.md`; constants are REAL*4 as in the engine.

use crate::canvas::{BufferPoint, Canvas, Pen};
use crate::codes::boxes::{draw_box, BoxCall, CIRCLE_SHAPE};
use crate::codes::line::{self, Params};
use crate::codes::rest;
use crate::display::Point;
use crate::document::{Document, ItemRef};
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
        gap(item, &bar, doc.screen(), canvas.buffer_mut());
    }
}

impl Barline {
    fn draw(&mut self, doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
        let u = self.unit;
        let d13 = real(u * 6.0 * f64::from(item.p(13)));
        let d14 = real(u * 6.0 * f64::from(item.p(14)));
        match self.kind {
            0 if item.p(6) != 0.0 => self.thick(canvas, self.xb, self.xb),
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

    /// barline_stroke 0x412699 (on screen: one segment).
    fn stroke(&self, canvas: &mut Canvas<'_>, x: f64) {
        canvas.segment(Pos::new(x, self.bottom), Pos::new(x, self.top));
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
            BRACKET_CURVE.iter().for_each(|&(tx, ty)| {
                let at = Pos::new(real(step * f64::from(tx) + x0), real(sign * f64::from(ty) + y));
                canvas.point(at, Pen::Continue);
            });
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
        let call = dot_call(item, size, doc.screen());
        let last = (self.low.number + self.span - 1).min(LAST_STAFF);
        (self.low.number..=last).for_each(|number| {
            let staff = doc.staves.get(number);
            let first = real(f64::from(staff.level0) + staff.step * f64::from(lower) * UNITS_PER_SCALE_STEP);
            let second = real(staff.step * f64::from(rise) * UNITS_PER_SCALE_STEP + first);
            // barline_dots sets IP12 afresh for every dot, so draw_box's doubled IP12 is not carried over.
            [first, second].into_iter().for_each(|y| {
                draw_box(canvas, Pos::new(x, y), staff.step, &call);
            });
        });
        self.ip8 = 0;
    }
}

/// Degrees per side of a dot on the screen; in print draw_box's default of 1.
const SCREEN_DOT_ANGLE: i32 = 60;

/// The draw_box call barline_dots makes: a filled circle of `size`, the
/// integer parameters cleared, the barline's own P8, P9, P10 and P16 left in
/// place (P16 = 1 is draw_box's inch flag, so it enlarges the dots).
fn dot_call(item: ItemRef<'_>, size: f64, screen: bool) -> BoxCall {
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
        ip12: if screen { SCREEN_DOT_ANGLE } else { 0 },
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

/// barline_gap 0x412353: replaces the bar's strokes in the point buffer by
/// two strokes each, below and above a gap of P19 scale steps centred P18
/// (a fraction, or a percentage above 1) of the way up.
fn gap(item: ItemRef<'_>, bar: &Barline, screen: bool, buffer: &mut Vec<BufferPoint>) {
    let (Some(first), Some(second)) = (buffer.first().copied(), buffer.get(1).copied()) else {
        return;
    };
    let y0 = f64::from(first.at.y);
    let y1 = f64::from(second.at.y);
    let height = real(y1 - y0);
    let p18 = item.p(18);
    let fraction = f64::from(if p18 > 1.0 { p18 / 100.0 } else { p18 });
    let centre = real(fraction * height + y0);
    let size = real(bar.low.step * f64::from(item.p(19)) * 7.0);
    let lo = real(centre - size / 2.0);
    let hi = real(size + lo);
    let lines = if item.p(5) == 1.0 { 2 } else { 1 } * if screen { 1 } else { 2 };
    let xs: Vec<i32> = buffer.iter().step_by(2).take(lines).map(|p| p.at.x).collect();
    let point = |x: i32, y: f64, pen: Pen| BufferPoint { at: Point::new(x, trunc(y)), pen };
    *buffer = xs
        .into_iter()
        .flat_map(|x| {
            [point(x, y0, Pen::Stroke), point(x, lo, Pen::Continue), point(x, hi, Pen::Stroke), point(x, y1, Pen::Continue)]
        })
        .collect();
}
