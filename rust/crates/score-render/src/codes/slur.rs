//! Code 5: slurs, ties, tuplet brackets and endings (draw_slur 0x538550).
//!
//! P3/P6 left and right end (P6 = 0: P3 + 20, curvature 3), P4/P5 their
//! levels, P7 curvature in scale steps, P8 where the ends sit on the notes
//! (1–9: brackets and endings instead), P9 flattening (99: triangle), P10
//! centre of the curve, P11 dashes or dots, P12 half slurs (1, 2) or a
//! change of direction (-1), P13 thickness, P14/P15 the visible part, P16 = 1
//! end offsets P17/P18, P19 where the thickness is reached, P20 note width,
//! P27–P29 a slash. The slur is built level from its left end and then
//! turned through the angle of P4–P5. A slur reads no other item.
//!
//! The curve is sampled as the engine samples it, at two points per 200
//! units, and followed between the samples, thickened along its normal
//! ([`Smooth`]); the engine draws only the samples, which leaves short slurs
//! and ties with visible corners and a flat top, and thickens them upright,
//! which leaves steep ends thin.

use crate::canvas::{BufferPoint, Canvas, Pen};
use crate::codes::number::{draw_number, number_font_loaded, NumberCall};
use crate::display::Point;
use crate::document::{Document, ItemRef};
use crate::geometry::{rotate_points_radians, turned};
use crate::page::P3_UNIT;
use crate::symbols::{draw_clef, ItemContext};
use crate::text::Font;
use crate::units::{constant, nint, real, trunc, Pos};

use std::f64::consts::FRAC_PI_2;

/// The engine's point buffer holds this many points; longer slurs are not drawn.
const BUFFER_POINTS: usize = 50_000;

/// Slur thickness P13 = 0 stands for (PREF.DAT, global 0x78B48C).
const DEFAULT_THICKNESS: f32 = 0.75;

/// Where the slur ends sit, in step units right of P3 and P6, by P8
/// (tables at 0x7973D0 and 0x797400, indexed as `end_table_index` says).
const LEFT_END: [f32; 12] = [0.0, 9.0, 27.0, 36.0, 18.0, 9.0, 18.0, 9.0, 0.0, 0.0, 17.7, 12.6];
const RIGHT_END: [f32; 12] = [0.0, 9.0, -6.0, -6.0, 14.0, 14.0, 9.0, 0.0, 9.0, 14.0, -4.0, -4.0];

/// The octagon a dot is drawn as, in multiples of P13 × STEP (0x7973A4):
/// x offsets are entries 0–8, y offsets entries 2–10.
const DOT: [f32; 11] = [-1.6, -1.6, -0.6, 0.6, 1.6, 1.6, 0.6, -0.6, -1.6, -1.6, -0.6];

/// P9 that turns the slur into a triangle.
const TRIANGLE: i32 = 99;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let params = Params::new(doc, item);
    match params.p8_int {
        TUPLET => tuplet_bracket(doc, item, &params, canvas),
        1..=9 => ending(doc, item, &params, canvas),
        _ => slur(doc, item, &params, canvas),
    }
}

/// Where the parts of a code-5 item lie (internal coordinates), for an
/// editor's handles on them: the ends of its chord and the point its P7
/// raises, the peak of a slur or the middle of a bracket's line. Half and
/// partial slurs are taken whole.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Shape {
    pub left: Pos,
    pub right: Pos,
    pub peak: Pos,
}

pub fn shape(doc: &Document<'_>, item: ItemRef<'_>) -> Shape {
    let params = Params::new(doc, item);
    if (1..=9).contains(&params.p8_int) {
        let staff = doc.staff_of(item);
        let bottom = doc.position(item).y;
        let top = real(bottom + real(staff.step * params.p7 * constant(7.0)));
        let right = real(params.p6 * P3_UNIT);
        let dy = real(staff.y(f64::from(item.p(5))) - bottom);
        return Shape {
            left: Pos::new(params.x, bottom),
            right: Pos::new(right, bottom + dy),
            peak: Pos::new((params.x + right) / 2.0, top + dy / 2.0),
        };
    }
    let slur = Slur::new(doc, item, &params);
    let pivot = Pos::new(slur.xl, slur.y0);
    // The curve is built level and turned counter-clockwise through this angle.
    let angle = if slur.dy == 0.0 { 0.0 } else { real(slur.dy.atan2(slur.length0)) };
    let at = |along: f64, up: f64| turned(Pos::new(slur.xl + along, slur.y0 + up), pivot, -angle.to_degrees());
    Shape { left: pivot, right: at(slur.length, 0.0), peak: at(slur.centre * slur.length, slur.height) }
}

/// P8 = 3: a tuplet bracket; every other P8 from 1 to 9 is an ending.
const TUPLET: i32 = 3;

/// draw_number's font codes: 1000 + n is font n; P14 = 34 stands for font 0.
const FIRST_FONT: i32 = 1000;
const FONT_00: i32 = 34;
/// IP7 of brackets, slur numbers and beams: Times-Italic.
const TUPLET_FONT: i32 = 1;
/// IP7 of endings: Times-Roman.
const ENDING_FONT: i32 = 0;
const TUPLET_SIZE: f32 = 0.875;
/// draw_slur sets P19 to this before the curve; draw_number then turns the number by it.
const DEFAULT_P19: f32 = 0.85;

/// A number 0x53BFC6 draws for beams, tuplet brackets, endings and slurs.
#[derive(Debug, Clone, Copy, PartialEq)]
pub(super) struct BracketNumber {
    pub value: i32,
    /// P6 for draw_number.
    pub size: f32,
    /// IP7 for draw_number unless `font_p14` is set.
    pub font: i32,
    /// IP14: a font as P14 gives it, 0 for none.
    pub font_p14: i32,
    /// IP17: a letter after the number.
    pub letter: i32,
    /// P19, which draw_number takes as its rotation.
    pub rotation: f32,
}

impl BracketNumber {
    fn font(&self) -> i32 {
        match self.font_p14.abs() {
            0 => self.font,
            n => {
                let n = if n >= FIRST_FONT { n - FIRST_FONT } else { n };
                if n == FONT_00 {
                    FIRST_FONT
                } else {
                    FIRST_FONT + n
                }
            }
        }
    }

    /// Step units the number moves left of its point, by its digits.
    fn indent(&self) -> f32 {
        match self.value {
            v if v < 10 => 7.1,
            11 => 12.0,
            v if v < 20 => 13.5,
            _ => 14.5,
        }
    }

    /// 0x53BFC6: draw_number at `at`, moved left by the indent; `at.x` is
    /// the caller's sum of two REAL*4 values, not yet stored. `step` is
    /// STEP, which draw_number uses as well (a beam's P18 scales it).
    pub(super) fn draw(&self, doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, at: Pos, step: f64) {
        let at = Pos::new(real(at.x - step * constant(self.indent())), at.y);
        draw_number(doc, item, canvas, at, &self.call(item, step));
    }

    /// The font draw_number leaves loaded for this number.
    pub(super) fn font_loaded(&self, doc: &Document<'_>, item: ItemRef<'_>, step: f64) -> Option<Font> {
        number_font_loaded(doc, Pos::default(), &self.call(item, step))
    }

    /// The parameters 0x53BFC6 sets before calling draw_number.
    fn call(&self, item: ItemRef<'_>, step: f64) -> NumberCall {
        NumberCall {
            value: self.value,
            p5: self.value as f32,
            size: self.size,
            font: self.font(),
            frame: 0,
            p14: 0.0,
            p17: self.letter,
            p18: 0.0,
            rotation: self.rotation,
            step: Some(step),
            ..NumberCall::of(item)
        }
    }
}

/// The font an item of code 5 leaves loaded: that of its number, if it
/// draws one (see [`crate::text::font_loaded`]).
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    let params = Params::new(doc, item);
    let number = match params.p8_int {
        TUPLET => tuplet_number(item, &params),
        1..=9 => ending_number(item, &params),
        _ if params.number() == 0 => None,
        _ => slur_number(item, &params, Slur::new(doc, item, &params).dy != 0.0),
    };
    number?.font_loaded(doc, item, doc.staff_of(item).step)
}

/// The number of a tuplet bracket: P9 when positive, else P8, in
/// Times-Italic or the font P14; P9 <= -2 or P11 = 3 leave it out.
fn tuplet_number(item: ItemRef<'_>, params: &Params) -> Option<BracketNumber> {
    let (ip9, ip11) = (trunc(f64::from(item.p(9))), trunc(f64::from(item.p(11))));
    (ip9 >= -1 && ip11 != NO_NUMBER).then(|| BracketNumber {
        value: bracket_value(item, params),
        size: tuplet_size(item),
        font: TUPLET_FONT,
        font_p14: trunc(f64::from(item.p(14))),
        letter: 0,
        rotation: item.p(19),
    })
}

/// The number of an ending in Times-Roman (or P14), with the letter IP17
/// unless P16 = 1 has made P17 an end offset (0x53C1F1); P9 < 0 or P12 < 0
/// leave it out.
fn ending_number(item: ItemRef<'_>, params: &Params) -> Option<BracketNumber> {
    let letter = if item.p(16) == 1.0 { 0 } else { trunc(f64::from(item.p(17))) };
    (trunc(f64::from(item.p(9))) >= 0 && trunc(f64::from(item.p(12))) >= 0).then(|| BracketNumber {
        value: bracket_value(item, params),
        size: 1.0,
        font: ENDING_FONT,
        font_p14: trunc(f64::from(item.p(14))),
        letter,
        rotation: item.p(19),
    })
}

fn bracket_value(item: ItemRef<'_>, params: &Params) -> i32 {
    match trunc(f64::from(item.p(9))) {
        ip9 if ip9 > 0 => ip9,
        _ => params.p8_int,
    }
}

/// The number P16 of a slur, turned by P19 (default 0.85, but 0 on
/// triangles); on a level slur P11 = 3 leaves it out.
fn slur_number(item: ItemRef<'_>, params: &Params, sloped: bool) -> Option<BracketNumber> {
    let triangle = trunc(f64::from(item.p(9))) == TRIANGLE;
    let ip11 = if triangle { trunc(f64::from(item.p(11))) } else { ip11_after_curve(item) };
    if !sloped && ip11 == NO_NUMBER {
        return None;
    }
    let rotation = match item.p(19) {
        0.0 if !triangle => DEFAULT_P19,
        p19 => p19,
    };
    Some(BracketNumber {
        value: params.number().abs(),
        size: tuplet_size(item),
        font: TUPLET_FONT,
        font_p14: trunc(f64::from(item.p(14))),
        letter: 0,
        rotation,
    })
}

/// Moves a number by P17 (6 steps) and P18 (a scale step), as the
/// brackets and slurs do (0x53B421); P16 = 1 has used them as end offsets.
fn moved_by_p17_p18(item: ItemRef<'_>, at: Pos, step: f64) -> Pos {
    let p = |n| f64::from(item.p(n));
    if item.p(16) == 1.0 {
        return at;
    }
    Pos::new(real(p(17) * constant(6.0) * step + at.x), real(p(18) * constant(7.0) * step + at.y))
}

/// The ending's number is followed by this library symbol, a full stop.
const ENDING_DOT: i32 = 24;

/// What brackets and endings share (draw_slur from 0x53ABAA): the left
/// hook and the bracket's corners.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Bracket {
    step: f64,
    left: f64,
    right: f64,
    /// The level of P4, where the hooks end.
    bottom: f64,
    /// P4 raised by the curvature P7.
    top: f64,
    height: f64,
    dy: f64,
    /// Room left in the line for the number.
    gap: f64,
}

impl Bracket {
    /// Starts the polyline with the left hook unless P9 = -1 (but for the
    /// second ending) or P13 = 1 or 3 leave it open.
    fn new(doc: &Document<'_>, item: ItemRef<'_>, params: &Params, canvas: &mut Canvas<'_>) -> Self {
        let p = |n| f64::from(item.p(n));
        let staff = doc.staff_of(item);
        let step = staff.step;
        let bottom = doc.position(item).y;
        let height = real(step * params.p7 * constant(7.0));
        let top = real(bottom + height);
        let (ip9, ip13) = (trunc(p(9)), trunc(p(13)));
        let open = (ip9 == -1 && params.p8_int != 2) || ip13 == 1 || ip13 == 3;
        if open {
            canvas.point(Pos::new(params.x, top), Pen::Stroke);
        } else {
            canvas.point(Pos::new(params.x, bottom), Pen::Stroke);
            canvas.point(Pos::new(params.x, top), Pen::Continue);
        }
        let gap = real(step * constant(13.0));
        let gap = if bracket_value(item, params) > 9 { real(gap * constant(1.5)) } else { gap };
        Self {
            step,
            left: params.x,
            right: real(params.p6 * P3_UNIT),
            bottom,
            top,
            height,
            dy: real(staff.y(p(5)) - bottom),
            gap,
        }
    }
}

/// Endings: a line at P4 + P7 from P3 to P6, hooks down at the ends (the
/// right one on first endings only), and the number with its full stop.
fn ending(doc: &Document<'_>, item: ItemRef<'_>, params: &Params, canvas: &mut Canvas<'_>) {
    let p = |n| f64::from(item.p(n));
    let bracket = Bracket::new(doc, item, params, canvas);
    let ip13 = trunc(p(13));
    let first = params.p8_int == 1;
    canvas.point(Pos::new(bracket.right, bracket.top), Pen::Continue);
    if ip13 < 2 && first {
        canvas.point(Pos::new(bracket.right, bracket.bottom), Pen::Continue);
    }
    let Some(number) = ending_number(item, params) else {
        return;
    };
    let step = bracket.step;
    let number_y = real(bracket.top - step * constant(28.0));
    // Where print places the number; the engine's screen puts it a step further right.
    let number_x = real(step * constant(13.5));
    // P13 from 0.01 to 0.99 moves the stop right; P13 >= 1 only opens the bracket.
    let p13 = if ip13 > 0 { 0.0 } else { p(13) };
    let (shift, lift) = match p(12) {
        0.0 => (p13, real(step * constant(2.0))),
        p12 => (real(p13 - (p12 - 1.0) * constant(1.3)), real(real(step * constant(2.0)) * p12 * constant(0.8))),
    };
    let after_number = real(shift * constant(3750.0) / step + number_x);
    let size = match p(12) {
        0.0 => 1.0,
        p12 => p12,
    };
    let stop_shift = if first { constant(2.0) } else { constant(5.0) };
    let at = Pos::new(real(after_number + bracket.left + step * stop_shift), real(lift + number_y));
    draw_clef(doc, &ItemContext::of(item), canvas, at, step, ENDING_DOT, (size, size));
    number.draw(doc, item, canvas, Pos::new(bracket.left + number_x, number_y), step);
}

/// Tuplet brackets: a line at P4 + P7 with a gap for the number at P10
/// (P11 = 1, 2 close it, P23 widens it, P9 <= -2 sets it), sloping to P5;
/// hooks at both ends (P13 = 1, 2, 3 leave them out, P12 lengthens the
/// right one).
fn tuplet_bracket(doc: &Document<'_>, item: ItemRef<'_>, params: &Params, canvas: &mut Canvas<'_>) {
    let p = |n| f64::from(item.p(n));
    let mut bracket = Bracket::new(doc, item, params, canvas);
    let step = bracket.step;
    let (ip9, ip11, ip13) = (trunc(p(9)), trunc(p(11)), trunc(p(13)));
    let width = match p(20) {
        0.0 => 1.0,
        p20 => p20,
    };
    let right = real(step * constant(17.5) * width + bracket.right);
    let length = real(right - bracket.left);
    let centre = match p(10) {
        0.0 => constant(0.5),
        p10 => p10,
    };
    if ip9 < -1 {
        bracket.gap = real(-(p(9) * constant(75.0)));
    }
    let gap = bracket.gap;
    let middle = real(real(centre * length) + bracket.left - gap);
    let half_gap = real(step * p(23) * constant(6.0));
    let mut top = bracket.top;
    let mut bottom = bracket.bottom;
    // Where the number sits, at P10 along the bracket.
    let level = if bracket.dy == 0.0 {
        if ip11 == 0 {
            canvas.point(Pos::new(real(middle - half_gap), top), Pen::Continue);
            canvas.point(Pos::new(real(half_gap + middle + gap + gap), top), Pen::Stroke);
        }
        top
    } else {
        bottom = real(bracket.dy + bottom);
        let slope = real(bracket.dy / length);
        // 0x53C14E: a point on the line through the left top corner.
        let along = |x: f64| Pos::new(x, real((x - params.x) * slope + top));
        if ip11 == 0 {
            canvas.point(along(real(half_gap + middle)), Pen::Continue);
            canvas.point(along(real(real(gap + middle + gap) - half_gap)), Pen::Stroke);
        }
        top = real(bracket.dy + top);
        real((bracket.height + bottom) - (1.0 - centre) * bracket.dy)
    };
    canvas.point(Pos::new(right, top), Pen::Continue);
    if p(12) != 0.0 {
        let extra = if params.p7 < 0.0 { -p(12).abs() } else { p(12).abs() };
        bottom = doc.staff_of(item).y(real(p(5) + extra + params.p7));
    }
    if ip13 < 2 {
        canvas.point(Pos::new(right, bottom), Pen::Continue);
    }
    let Some(number) = tuplet_number(item, params) else {
        return;
    };
    let y = real(number_level(ip11, ip7(item), level, step) - step * constant(9.0));
    let base = moved_by_p17_p18(item, Pos::new(bracket.left, y), step);
    number.draw(doc, item, canvas, Pos::new(base.x + real(centre * length), base.y), step);
}

/// P11 = 3 draws a bracket without its number.
const NO_NUMBER: i32 = 3;

/// The size of bracket and slur numbers: P21, default 0.875.
fn tuplet_size(item: ItemRef<'_>) -> f32 {
    match item.p(21) {
        0.0 => TUPLET_SIZE,
        p21 => p21,
    }
}

/// P11 = 1 puts the number 14 steps inside the bracket (towards the
/// notes), P11 = 2 as far outside.
fn number_level(ip11: i32, ip7: i32, level: f64, step: f64) -> f64 {
    if ip11 == 0 {
        return level;
    }
    let ip7 = if ip11 == 2 { -ip7 } else { ip7 };
    let away = real(-(step * constant(14.0)));
    let away = if ip7 < 0 { -away } else { away };
    real(away + level)
}

/// Slurs and ties: the curve and everything P9–P29 do to it.
fn slur(doc: &Document<'_>, item: ItemRef<'_>, params: &Params, canvas: &mut Canvas<'_>) {
    let slur = Slur::new(doc, item, params);
    let mut buffer = Buffer::new(slur.outline(item));
    buffer.fallback = slur.cut_fallback(item);
    slur.cut(item, &mut buffer);
    if slur.has_number_gap(item, params) {
        number_gap(&mut buffer, item, slur.step, slur.dx);
    }
    let slash = (item.p(27) != 0.0).then(|| slur.slash(item, buffer.slots.first().map_or(0, |p| p.at.y)));
    let mut points: Vec<BufferPoint> = match Smooth::of(&slur, item) {
        // The slash is drawn whole, as its own object.
        Some(smooth) if buffer.len() < BUFFER_POINTS => {
            smooth.follow(buffer.points()).into_iter().chain(slash.iter().flatten().map(Slot::point)).collect()
        }
        Some(_) => Vec::new(),
        // Triangles, and curves whose peak is not between their ends, as the engine draws them.
        None => {
            if let Some(slash) = slash {
                buffer.append_keeping_pens(&slash);
            }
            if buffer.len() < BUFFER_POINTS {
                buffer.points().iter().map(Slot::point).collect()
            } else {
                Vec::new()
            }
        }
    };
    if slur.dy != 0.0 {
        let angle = real(slur.dy.atan2(slur.length0));
        rotate_points_radians(&mut points, Pos::new(slur.xl, slur.y0).to_point(), angle as f32);
    }
    canvas.buffer_mut().extend(points);
    if params.number() != 0 {
        if let Some(number) = slur_number(item, params, slur.dy != 0.0) {
            slur.draw_number(doc, item, params, canvas, &number);
        }
    }
}

/// A point of the slur in draw_slur's buffer and the sample of the curve it
/// stands for, if any.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Slot {
    at: Point,
    pen: Pen,
    sample: Option<Sample>,
}

/// The `index`th point of the curve (from the left end), or the point of
/// the outline's way back (`back`) over it.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct Sample {
    index: usize,
    back: bool,
}

/// What the buffer holds where nothing was written.
const EMPTY: Slot = Slot { at: Point { x: 0, y: 0 }, pen: Pen::Continue, sample: None };

impl Slot {
    fn new(at: Point, pen: Pen) -> Self {
        Self { at, pen, sample: None }
    }

    fn point(&self) -> BufferPoint {
        BufferPoint { at: self.at, pen: self.pen }
    }
}

/// The engine's point buffer while draw_slur rearranges it, indexed from 0
/// for the engine's point 1. Slots past the drawn points keep what earlier
/// steps wrote: steps that only set coordinates there inherit those pens.
#[derive(Debug, Clone, PartialEq)]
struct Buffer {
    slots: Vec<Slot>,
    /// The engine's NPT, the next free point: points 1 to npt - 1 are drawn.
    npt: isize,
    /// The NPT a cut that finds no place to cut leaves (the counter
    /// 0x1C585D0, last set by the curve or an earlier cut); `None` where the
    /// engine's value is stale from other work, and the port draws nothing.
    fallback: Option<isize>,
}

impl Buffer {
    fn new(points: Vec<Slot>) -> Self {
        let npt = points.len() as isize + 1;
        Self { slots: points, npt, fallback: None }
    }

    fn fall_back(&mut self) {
        self.npt = self.fallback.unwrap_or(1);
    }

    fn len(&self) -> usize {
        (self.npt - 1).max(0) as usize
    }

    fn points(&self) -> &[Slot] {
        &self.slots[..self.len()]
    }

    /// Writes the point of `slot` into slot `k`, keeping the pen already there.
    fn set_at(&mut self, k: usize, slot: Slot) {
        if k >= self.slots.len() {
            self.slots.resize(k + 1, EMPTY);
        }
        self.slots[k] = Slot { pen: self.slots[k].pen, ..slot };
    }

    fn set(&mut self, k: usize, slot: Slot) {
        self.set_at(k, slot);
        self.slots[k].pen = slot.pen;
    }

    /// Points from point NPT on, of which only the first sets its pen.
    /// Points that land before point 1 (NPT < 1) are lost.
    fn append_keeping_pens(&mut self, points: &[Slot]) {
        let first = self.npt - 1;
        points.iter().enumerate().for_each(|(m, &p)| match usize::try_from(first + m as isize) {
            Ok(k) if m == 0 => self.set(k, p),
            Ok(k) => self.set_at(k, p),
            Err(_) => {}
        });
        self.npt += points.len() as isize;
    }
}
/// The parameters draw_slur works with after its defaults and rewrites.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Params {
    /// X_POS, moved by P17 when P16 = 1.
    x: f64,
    p6: f64,
    p7: f64,
    p8: f64,
    p8_int: i32,
    p16: f64,
}

impl Params {
    fn new(doc: &Document<'_>, item: ItemRef<'_>) -> Self {
        let p = |n| f64::from(item.p(n));
        let (mut p6, mut p7) = (p(6), p(7));
        if p6 == 0.0 {
            p6 = real(p(3) + constant(20.0));
            if p7 == 0.0 {
                p7 = constant(3.0);
            }
        }
        let mut params = Self { x: doc.position(item).x, p6, p7, p8: p(8), p8_int: trunc(p(8)), p16: p(16) };
        // 0x53C1F1: P16 = 1 makes P17/P18 offsets of the ends and drops P8's placement.
        if p(16) == 1.0 {
            params.x = real(p(17) * P3_UNIT + params.x);
            params.p6 = real(p(18) + params.p6);
            params.p16 = 0.0;
            if params.p8_int <= 0 {
                params.p8 = 0.0;
                params.p8_int = 0;
            }
        }
        params
    }

    /// P16 as an integer; values from 1000 on leave it unset.
    fn number(&self) -> i32 {
        match trunc(self.p16) {
            n if n < 1000 => n,
            _ => 0,
        }
    }
}

/// IP11 as the curve leaves it: halved below -3, then without its sign.
fn ip11_after_curve(item: ItemRef<'_>) -> i32 {
    match trunc(f64::from(item.p(11))) {
        n if n < -3 => (n / 2).abs(),
        n => n.abs(),
    }
}

/// IP7: P7 as stored, truncated before draw_slur gives P7 its default, so
/// the default curvature adds no points and no direction.
fn ip7(item: ItemRef<'_>) -> i32 {
    trunc(f64::from(item.p(7)))
}

/// The table row of P8: 0 and 10 at the note fronts, -1 and 11 over the
/// centres, ... -9 and 19; 98 and 99 for two further pairs.
fn end_table_index(p8: i32) -> usize {
    let j = if p8 > 0 { p8 } else { 10 - p8 } - 9;
    let j = if j > 10 { 1 } else { j };
    let j = if p8 >= 98 { p8 - 87 } else { j };
    if (1..=12).contains(&j) {
        j as usize - 1
    } else {
        0
    }
}

/// What draw_slur derives before it builds the outline.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Slur {
    step: f64,
    /// P10: where the curve peaks, as a fraction of the length.
    centre: f64,
    /// The left end, and the level the slur is built at.
    xl: f64,
    y0: f64,
    /// Rise from the left to the right end.
    dy: f64,
    /// Horizontal length before a half slur doubles it, for the angle.
    length0: f64,
    /// Length along the slope.
    length: f64,
    /// Peak height, signed.
    height: f64,
    /// Where the visible part starts and ends (fractions; 0 = whole).
    start: f64,
    end: f64,
    /// P12 after half slurs have been resolved: -1 reverses at the centre.
    shape: i32,
    /// Point spacing along the slur.
    dx: f64,
    points: usize,
}

impl Slur {
    fn new(doc: &Document<'_>, item: ItemRef<'_>, params: &Params) -> Self {
        let p = |n| f64::from(item.p(n));
        let staff = doc.staff_of(item);
        let step = staff.step;
        let centre = match p(10) {
            0.0 => constant(0.5),
            p10 => p10,
        };
        let y0 = doc.position(item).y;
        let height = real(step * params.p7 * constant(7.0));
        let dy = real(staff.y(p(5)) - y0);
        let (left_end, right_end) = if params.p8_int == 0 && params.p8 != 0.0 {
            let left = real(params.p8 * constant(36.0));
            (left, real(constant(18.0) - left))
        } else {
            let j = end_table_index(params.p8_int);
            let scale = |v: f32| match p(20) {
                0.0 => constant(v),
                p20 => real(p20 * constant(v)),
            };
            (scale(LEFT_END[j]), scale(RIGHT_END[j]))
        };
        let mut xl = real(step * left_end + params.x);
        let p6 = if params.p6 < p(3) { real(p(3) + constant(3.0)) } else { params.p6 };
        let right_end = real(step * right_end);
        let p12 = trunc(p(12));
        let (mut start, mut end) = if p12 > 0 { (0.0, 0.0) } else { (p(14), p(15)) };
        let length0 = real(real(p6 * P3_UNIT + right_end) - xl);
        let triangle = trunc(p(9)) == TRIANGLE;
        let mut shape = if triangle { 0 } else { p12 };
        if triangle {
            (start, end) = (0.0, 0.0);
        }
        if start >= 1.0 {
            start = 0.0;
        }
        // Half slurs (P12 = 1, 2) are the visible half of a slur twice as long.
        let (mut length, mut dy, mut y0) = (length0, dy, y0);
        if start == 0.0 && end == 0.0 {
            if shape > 0 {
                if shape == 1 {
                    end = constant(0.5);
                } else {
                    xl = real(xl - length);
                    start = constant(0.5);
                    y0 = real(y0 - dy);
                }
                length = real(length * 2.0);
                dy = real(dy * 2.0);
            }
        } else if shape > 0 {
            shape = 0;
        }
        if p(5) != p(4) {
            length = real((dy * dy + length * length).sqrt());
        }
        let points = point_count(item, length, shape);
        let dx = real(length / f64::from(points as i32 - 1));
        Self { step, centre, xl, y0, dy, length0, length, height, start, end, shape, dx, points }
    }

    /// The closed outline: along the curve from the left end and back with
    /// the thickness added; dots, dashes or a triangle instead when asked.
    fn outline(&self, item: ItemRef<'_>) -> Vec<Slot> {
        if trunc(f64::from(item.p(9))) == TRIANGLE {
            return self.triangle();
        }
        let curve = self.curve(item);
        let mut points = self.with_thickness(item, &curve);
        if self.shape < 0 {
            self.reverse_second_half(&mut points);
        }
        match (trunc(f64::from(item.p(11))), item.p(11)) {
            (0, p11) if p11 <= 0.0 => points,
            (_, p11) if p11 <= 0.0 => self.dots(item, &points[..curve.len()]),
            _ => dashes(&points, trunc(f64::from(item.p(12)))),
        }
    }

    /// The curve's points from left to right: x stepping by 2·P10·dx up to
    /// the peak and (2 - 2·P10)·dx after it, y = top - H·|t|^(2.5 + P9).
    fn curve(&self, item: ItemRef<'_>) -> Vec<Point> {
        let n = self.points;
        let peak = n / 2;
        let twice_centre = real(self.centre + self.centre);
        let mut x = self.xl;
        let mut advance = real(twice_centre * self.dx);
        let xs: Vec<i32> = (1..=n)
            .map(|k| {
                let at = trunc(x);
                x = real(advance + x);
                if k == peak {
                    advance = real((constant(2.0) - twice_centre) * self.dx);
                }
                at
            })
            .collect();

        let exponent = exponent(item);
        let half = n / 2 - 1;
        let top = f64::from(trunc(self.height + self.y0)) as f32;
        let y_at = |i: usize| {
            let t = f64::from(i as f32) / f64::from(half as f32);
            trunc(f64::from(top) - t.powf(exponent) * self.height)
        };
        let mut ys = vec![0; n];
        (0..=half).for_each(|m| {
            let y = y_at(half - m);
            ys[m] = y;
            ys[n - 1 - m] = y;
        });
        xs.into_iter().zip(ys).map(|(x, y)| Point::new(x, y)).collect()
    }

    /// The curve and its way back, thickened from both ends up to P13 × 3.5
    /// steps (scaled down for short slurs), reached after a fraction P19 of
    /// each half.
    fn with_thickness(&self, item: ItemRef<'_>, curve: &[Point]) -> Vec<Slot> {
        let n = curve.len();
        let half = n / 2 - 1;
        let Profile { thickness, full, reach, sign } = Profile::of(self, item);
        let increment = real(thickness / (reach * f64::from(half as f32)));

        // The way back is written into the buffer in the engine's order:
        // forwards from the right end and, mirrored, backwards from the end.
        let mut back = vec![Point::default(); n - 1];
        let (mut grown, mut reached, mut offset) = (0.0, 0, 2);
        (1..n).for_each(|m| {
            let source = curve[n - 1 - m];
            back[m - 1].x = source.x;
            if m <= half + 1 {
                if reached < full {
                    grown = real(increment + grown);
                    reached = trunc(grown);
                    offset = sign * reached;
                }
                let y = source.y + offset;
                back[m - 1].y = y;
                back[n - 2 - m].y = y;
            }
        });
        back[n - 2].y = curve[0].y;
        let along = curve.iter().enumerate().map(|(index, &at)| (at, Sample { index, back: false }));
        // The way back's point m lies over the curve's point n - 2 - m.
        let back = back.iter().enumerate().map(|(m, &at)| (at, Sample { index: n - 2 - m, back: true }));
        along
            .chain(back)
            .enumerate()
            .map(|(k, (at, sample))| Slot { at, pen: if k == 0 { Pen::Fill } else { Pen::Continue }, sample: Some(sample) })
            .collect()
    }

    /// P13 (default 0.75, at most 0.6 of it on slurs shorter than 600 units,
    /// rising to all of it at 3000).
    fn thickness_factor(&self, item: ItemRef<'_>) -> f64 {
        let p13 = match item.p(13) {
            0.0 => constant(DEFAULT_THICKNESS),
            p13 if p13 <= 0.0 => 1.0,
            p13 => f64::from(p13),
        };
        let length = trunc(self.length);
        let scale = match length {
            l if l >= 3000 => return p13,
            l if l > 600 => real(1.0 - f64::from(3000 - l) * constant(0.4) / constant(2400.0)),
            _ => constant(0.6),
        };
        real(p13 * scale)
    }

    /// P12 = -1: the curve's second half is mirrored about the peak level.
    fn reverse_second_half(&self, points: &mut [Slot]) {
        let n = self.points;
        let top = trunc(self.height + self.y0);
        let last = n - 1;
        (n / 2..=last).for_each(|k| {
            let y = points[k].at.y;
            let shift = (top - y) * 2;
            points[k].at.y = shift + y;
            if k != last {
                let mirror = 2 * last - k;
                points[mirror].at.y += shift;
            }
        });
    }

    /// P11 < 0: an octagonal dot on every curve point.
    fn dots(&self, item: ItemRef<'_>, curve: &[Slot]) -> Vec<Slot> {
        let radius = real(self.thickness_factor(item) * self.step);
        let offsets: Vec<i32> = DOT.iter().map(|&d| nint(radius * constant(d))).collect();
        curve
            .iter()
            .flat_map(|centre| {
                let (offsets, centre) = (&offsets, centre.at);
                (0..9).map(move |m| {
                    let at = Point::new(centre.x + offsets[m], centre.y + offsets[m + 2]);
                    Slot::new(at, if m == 0 { Pen::Fill } else { Pen::Continue })
                })
            })
            .collect()
    }

    /// P9 = 99: two strokes from the ends up to the peak at P10, drawn once
    /// as print draws them (the engine's screen repeats them trunc(P13)
    /// times seven units higher).
    fn triangle(&self) -> Vec<Slot> {
        let y = trunc(self.y0);
        let left = trunc(self.xl);
        let peak = trunc(self.centre * self.length + self.xl);
        let right = trunc(self.length + self.xl);
        vec![
            Slot::new(Point::new(left, y), Pen::Stroke),
            Slot::new(Point::new(peak, trunc(f64::from(y) + self.height)), Pen::Continue),
            Slot::new(Point::new(right, y), Pen::Continue),
        ]
    }

    /// After building the curve the counter stands at half its points; the
    /// triangle and the dots leave unrelated values.
    fn cut_fallback(&self, item: ItemRef<'_>) -> Option<isize> {
        let triangle = trunc(f64::from(item.p(9))) == TRIANGLE;
        let dots = item.p(11) < 0.0;
        (!triangle && !dots).then_some((self.points / 2) as isize)
    }

    /// P14/P15: only the part from P14 to P15 (fractions of the length)
    /// stays; on dashed slurs whole dashes.
    fn cut(&self, item: ItemRef<'_>, buffer: &mut Buffer) {
        let dashed = trunc(f64::from(item.p(11))) != 0;
        match self.start {
            s if s <= 0.0 => {}
            s if s > constant(0.94) => buffer.npt = 0,
            s => cut_before(buffer, trunc(s * self.length + self.xl + self.dx / 2.0), dashed),
        }
        if self.end != 0.0 {
            cut_after(buffer, trunc(self.end * self.length + self.xl - self.dx / 2.0), dashed);
        }
    }

    /// Draws the number P16 (draw_slur from 0x53AA73): in the slur's gap, or
    /// for negative P16 inside an unbroken slur; at P10 of a level slur, at
    /// the middle of a sloped one, turned with it. A sloped slur of dashes
    /// or dots has no gap, so its number goes inside as for negative P16
    /// (0x538D0B).
    fn draw_number(
        &self,
        doc: &Document<'_>,
        item: ItemRef<'_>,
        params: &Params,
        canvas: &mut Canvas<'_>,
        number: &BracketNumber,
    ) {
        let sloped = self.dy != 0.0;
        let down = params.p7 < 0.0;
        let broken = trunc(f64::from(item.p(11))) != 0 && trunc(f64::from(item.p(9))) != TRIANGLE;
        let inside = params.number() < 0 || (sloped && broken);
        let drop: f32 = match (inside, sloped) {
            (true, true) => {
                if down {
                    -5.0
                } else {
                    23.0
                }
            }
            (true, false) => {
                if down {
                    -14.0
                } else {
                    14.0
                }
            }
            (false, true) => 9.0,
            (false, false) => 0.0,
        };
        let height = real(self.height - self.step * constant(drop));
        let (at, along) = if sloped {
            let angle = real(self.dy.atan2(self.length0));
            let (sin, cos) = (real(angle.sin()), real(angle.cos()));
            let half = real(self.length0 * constant(0.5));
            let x = real((cos * half - sin * height) + self.xl);
            let y = real((cos * height + sin * half) + self.y0);
            (Pos::new(x, y), 0.0)
        } else {
            let triangle = trunc(f64::from(item.p(9))) == TRIANGLE;
            let ip11 = if triangle { trunc(f64::from(item.p(11))) } else { ip11_after_curve(item) };
            let level = number_level(ip11, ip7(item), real(self.y0 + height), self.step);
            (Pos::new(self.xl, real(level - self.step * constant(9.0))), real(self.centre * self.length))
        };
        let base = moved_by_p17_p18(item, at, self.step);
        number.draw(doc, item, canvas, Pos::new(base.x + along, base.y), self.step);
    }

    /// A gap in the middle for the number P16 (0x53BE1D). The engine also
    /// cuts triangles, with the point spacing of whatever slur it drew
    /// before; the port leaves them whole.
    fn has_number_gap(&self, item: ItemRef<'_>, params: &Params) -> bool {
        let triangle = trunc(f64::from(item.p(9))) == TRIANGLE;
        let plain = trunc(f64::from(item.p(11))) == 0 && !triangle;
        plain && params.number() > 0 && self.start <= 0.0 && self.end == 0.0
    }

    /// P27: a vertical bar P27 scale steps high across the slur at P29 (0.5)
    /// of its length, raised by P28 scale steps.
    fn slash(&self, item: ItemRef<'_>, first_y: i32) -> [Slot; 5] {
        let p = |n| f64::from(item.p(n));
        let along = match p(29) {
            0.0 => constant(0.5),
            p29 => p29,
        };
        let x = trunc(real(along * self.length + self.xl));
        let height = real(p(27) * constant(7.0) * self.step);
        let lift = if p(7) < 0.0 { constant(-35.0) } else { constant(35.0) };
        let mut bottom = real(f64::from(first_y) + self.height - height / 2.0 + lift);
        if p(28) != 0.0 {
            bottom = real(p(28) * constant(7.0) * self.step + bottom);
        }
        let (low, high) = (trunc(bottom), trunc(height + bottom));
        const HALF_WIDTH: i32 = 24;
        let corner = |x, y, pen| Slot::new(Point::new(x, y), pen);
        [
            corner(x - HALF_WIDTH, low, Pen::Fill),
            corner(x - HALF_WIDTH, high, Pen::Continue),
            corner(x + HALF_WIDTH, high, Pen::Continue),
            corner(x + HALF_WIDTH, low, Pen::Continue),
            corner(x - HALF_WIDTH, low, Pen::Continue),
        ]
    }
}

/// The curve's exponent: P9 + 2.5, at least 0.1.
fn exponent(item: ItemRef<'_>) -> f64 {
    real(f64::from(item.p(9)) + constant(2.5)).max(constant(0.1))
}

/// The thickness with_thickness adds: up to P13 × 3.5 steps (`thickness`),
/// growing until it rounds to `full`, reached after a fraction `reach` (P19)
/// of each half from its end, upward or (`sign` -1, for P7 < 0) downward.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Profile {
    thickness: f64,
    full: i32,
    reach: f64,
    sign: i32,
}

impl Profile {
    fn of(slur: &Slur, item: ItemRef<'_>) -> Self {
        let thickness = real(slur.thickness_factor(item) * real(slur.step * constant(3.5)));
        let reach = match item.p(19) {
            0.0 => constant(0.85),
            p19 => f64::from(p19),
        };
        let sign = if ip7(item) < 0 { -1 } else { 1 };
        Self { thickness, full: trunc(thickness + constant(0.5)), reach, sign }
    }

    /// The offset of the way back at `u`, the fraction of a half from its
    /// end, as with_thickness's steps give it when they become small; a
    /// thickness that rounds to nothing leaves its first offset, 2 up.
    fn offset(&self, u: f64) -> f64 {
        match self.full {
            _ if u <= 0.0 => 0.0,
            full if full <= 0 => 2.0,
            full => f64::from(self.sign) * (u * self.thickness / self.reach).min(f64::from(full)),
        }
    }
}

/// Units a point of the drawn curve keeps from the engine's samples.
const MIN_SEGMENT: f64 = 3.0;

/// Turn of the drawn curve per segment, at most.
const MAX_TURN_DEGREES: f64 = 3.0;

/// The curve draw_slur samples, followed between its samples: the slur as
/// drawn. It is [`Slur::curve`]'s power curve with the same ends, peak and
/// exponent, but without the flat top an even number of samples leaves at
/// the peak, and its way back is offset along the normal with
/// [`Profile::offset`]. Coordinates are level, as before the turn.
#[derive(Debug, Clone, PartialEq)]
struct Smooth {
    /// The x of the engine's samples, which place them on this curve.
    xs: Vec<f64>,
    left: f64,
    peak: f64,
    right: f64,
    top: f64,
    /// Rise from the ends to the peak (negative for a curve downward).
    height: f64,
    exponent: f64,
    /// P12 = -1: the right half mirrored about the peak's level.
    reversed: bool,
    profile: Profile,
    /// Where the curve is sampled, left to right.
    dense: Vec<f64>,
}

impl Smooth {
    /// The curve of a slur (not a triangle) whose samples run left to right.
    fn of(slur: &Slur, item: ItemRef<'_>) -> Option<Self> {
        if trunc(f64::from(item.p(9))) == TRIANGLE {
            return None;
        }
        let curve = slur.curve(item);
        let n = curve.len();
        if n < 4 {
            return None;
        }
        let half = n / 2 - 1;
        let xs: Vec<f64> = curve.iter().map(|p| f64::from(p.x)).collect();
        // The peak lies in the middle of the flat top.
        let (left, peak, right) = (xs[0], (xs[half] + xs[half + 1]) / 2.0, xs[n - 1]);
        if !(left < peak && peak < right) {
            return None;
        }
        let top = f64::from(curve[half].y);
        let mut smooth = Self {
            xs,
            left,
            peak,
            right,
            top,
            height: top - f64::from(curve[0].y),
            exponent: exponent(item),
            reversed: slur.shape < 0,
            profile: Profile::of(slur, item),
            dense: Vec::new(),
        };
        smooth.dense = smooth.samples();
        Some(smooth)
    }

    /// The x where to sample: on each half at most [`MAX_TURN_DEGREES`]
    /// apart in direction, the peak, and where the thickness stops growing.
    fn samples(&self) -> Vec<f64> {
        let halves = [(self.peak - self.left, -1.0), (self.right - self.peak, 1.0)];
        let mut xs: Vec<f64> = halves
            .into_iter()
            .flat_map(|(width, direction)| self.half_samples(width).into_iter().map(move |s| (width, direction, s)))
            .map(|(width, direction, s)| self.peak + direction * s * width)
            .collect();
        xs.sort_by(f64::total_cmp);
        xs.dedup();
        xs
    }

    /// The parameters s (0 at the peak, 1 at the end) to sample a half
    /// `width` long at: the slope is tan θ = k·s^(e-1), taken in equal steps
    /// of θ.
    fn half_samples(&self, width: f64) -> Vec<f64> {
        let e = self.exponent;
        let k = self.height.abs() * e / width;
        let mut s = vec![0.0, 1.0];
        if k > 0.0 && (e - 1.0).abs() > f64::EPSILON {
            let at_end = k.atan();
            let at_peak = if e > 1.0 { 0.0 } else { FRAC_PI_2 };
            let steps = ((at_peak - at_end).abs() / MAX_TURN_DEGREES.to_radians()).ceil() as usize;
            s.extend((1..steps).map(|i| {
                let theta = at_end + (at_peak - at_end) * i as f64 / steps as f64;
                (theta.tan() / k).powf(1.0 / (e - 1.0))
            }));
        }
        let profile = &self.profile;
        s.push(1.0 - f64::from(profile.full) * profile.reach / profile.thickness);
        s.retain(|v| (0.0..=1.0).contains(v));
        s
    }

    /// The half `x` lies on (true for the right one) and its parameter s.
    fn parameter(&self, x: f64) -> (bool, f64) {
        if x <= self.peak {
            (false, ((self.peak - x) / (self.peak - self.left)).clamp(0.0, 1.0))
        } else {
            (true, ((x - self.peak) / (self.right - self.peak)).clamp(0.0, 1.0))
        }
    }

    fn point(&self, x: f64) -> Pos {
        let (right, s) = self.parameter(x);
        let drop = self.height * s.powf(self.exponent);
        Pos::new(x, if right && self.reversed { self.top + drop } else { self.top - drop })
    }

    /// The unit normal at `x` to the left of the way from left to right; at
    /// the peak between those of the two halves.
    fn normal(&self, x: f64) -> (f64, f64) {
        let (right, s) = self.parameter(x);
        let on = |right: bool| {
            let width = if right { self.right - self.peak } else { self.peak - self.left };
            let rate = match self.height {
                0.0 => 0.0,
                h => h * self.exponent * s.powf(self.exponent - 1.0) / width,
            };
            let slope = if right && !self.reversed { -rate } else { rate };
            if slope.is_finite() {
                let length = slope.hypot(1.0);
                (-slope / length, 1.0 / length)
            } else {
                (-slope.signum(), 0.0)
            }
        };
        if s > 0.0 {
            return on(right);
        }
        let ((ax, ay), (bx, by)) = (on(false), on(true));
        match (ax + bx).hypot(ay + by) {
            length if length > 1e-9 => ((ax + bx) / length, (ay + by) / length),
            _ => (0.0, 1.0),
        }
    }

    /// The way back over the curve's point at `x`.
    fn back(&self, x: f64) -> Pos {
        let (_, s) = self.parameter(x);
        let offset = self.profile.offset(1.0 - s);
        let ((nx, ny), p) = (self.normal(x), self.point(x));
        Pos::new(p.x + offset * nx, p.y + offset * ny)
    }

    fn at(&self, x: f64, back: bool) -> Point {
        if back { self.back(x) } else { self.point(x) }.to_point()
    }

    /// The engine's outline with its samples moved onto this curve, and
    /// edges between neighbouring samples following it.
    fn follow(&self, slots: &[Slot]) -> Vec<BufferPoint> {
        let mut out = Vec::with_capacity(slots.len());
        let mut start = 0;
        slots.iter().enumerate().for_each(|(k, slot)| {
            if k > 0 && slot.pen == Pen::Continue {
                self.between(&slots[k - 1], slot, &mut out);
            } else {
                self.close(&slots[start..k], &mut out);
                start = k;
            }
            let at = slot.sample.map_or(slot.at, |s| self.at(self.xs[s.index], s.back));
            out.push(BufferPoint { at, pen: slot.pen });
        });
        self.close(&slots[start..], &mut out);
        out
    }

    /// A filled path closes back to its first point, along the curve too.
    fn close(&self, path: &[Slot], out: &mut Vec<BufferPoint>) {
        if let (Some(first), Some(last)) = (path.first(), path.last()) {
            if path.len() > 2 && matches!(first.pen, Pen::Fill | Pen::SubPath) {
                self.between(last, first, out);
            }
        }
    }

    /// The points of the curve or the way back between two neighbouring
    /// samples; nothing for an edge across.
    fn between(&self, from: &Slot, to: &Slot, out: &mut Vec<BufferPoint>) {
        let (Some(a), Some(b)) = (from.sample, to.sample) else { return };
        let Some(back) = self.side(a, b) else { return };
        let (xa, xb) = (self.xs[a.index], self.xs[b.index]);
        let (low, high) = (xa.min(xb) + MIN_SEGMENT, xa.max(xb) - MIN_SEGMENT);
        let inner = self.dense.iter().copied().filter(|&x| x > low && x < high);
        let point = |x| BufferPoint { at: self.at(x, back), pen: Pen::Continue };
        if xa < xb {
            out.extend(inner.map(point));
        } else {
            out.extend(inner.rev().map(point));
        }
    }

    /// Whether an edge between samples `a` and `b` follows the way back
    /// (`Some(true)`) or the curve: neighbouring samples on the same side;
    /// the ends, without thickness, belong to both.
    fn side(&self, a: Sample, b: Sample) -> Option<bool> {
        let end = |s: Sample| s.index == 0 || s.index == self.xs.len() - 1;
        match (a.index.abs_diff(b.index) == 1, a.back == b.back, end(a), end(b)) {
            (false, ..) => None,
            (true, true, ..) => Some(a.back),
            (true, false, true, false) => Some(b.back),
            (true, false, false, true) => Some(a.back),
            _ => None,
        }
    }
}

/// Points along the slur: two per 200 units (500 for dashed and dotted
/// slurs) and two per scale step of curvature, at least eight; P11 sets the
/// number of dashes or dots.
fn point_count(item: ItemRef<'_>, length: f64, shape: i32) -> usize {
    let p11 = trunc(f64::from(item.p(11)));
    let per = if p11 != 0 { 500 } else { 200 };
    let mut n = ((trunc(length) / per) * 2).max(8) + ip7(item).abs() * 2;
    if p11 != 0 {
        let pieces = if p11 < -3 { p11 / 2 } else { p11 }.abs();
        if pieces < 2 {
            n -= 2;
            if n > 8 && item.p(11) <= 0.0 && pieces == 1 {
                n = n / 2 - 2;
                if n % 2 != 0 {
                    n -= 1;
                }
                if n < 5 {
                    n = 6;
                }
            }
        } else {
            n = pieces * 2;
            if shape > 0 {
                n *= 2;
            }
        }
    }
    n.max(2) as usize
}

/// P11 > 0: every other segment of the outline as a quadrilateral, the
/// first and last as the outline's ends (P12 = 1, 2 leave out one of them).
fn dashes(points: &[Slot], p12: i32) -> Vec<Slot> {
    let at = |k: usize| points.get(k.wrapping_sub(1)).copied().unwrap_or(EMPTY);
    let piece = |corners: &[Slot]| -> Vec<Slot> {
        corners
            .iter()
            .enumerate()
            .map(|(i, &corner)| Slot { pen: if i == 0 { Pen::Fill } else { Pen::Continue }, ..corner })
            .collect()
    };
    let last = points.len();
    let mut out = Vec::new();
    let (mut i, mut j) = if p12 == 2 {
        (1, last)
    } else {
        out.extend(piece(&[at(1), at(2), at(last - 1), at(last)]));
        (3, last - 2)
    };
    loop {
        let start = at(i);
        out.extend(piece(&[start, at(i + 1), at(j - 1), at(j), start]));
        i += 2;
        j -= 2;
        if i + 1 >= j - 1 {
            break;
        }
    }
    if p12 == 1 {
        out.pop();
    } else {
        out.extend(piece(&[at(i), at(i + 1), at(j), at(i)]));
    }
    out
}

/// Keeps the outline from its first curve point at or right of `from` (on
/// dashed slurs: the first dash starting there) round to the matching point
/// of the way back, moved to the front of the buffer with their pens.
fn cut_before(buffer: &mut Buffer, from: i32, dashed: bool) {
    let points = buffer.points();
    let Some(first) = points.iter().position(|p| p.at.x >= from && (!dashed || p.pen != Pen::Continue)) else {
        buffer.fall_back();
        return;
    };
    let x = points[first].at.x;
    let end = if dashed {
        points.len()
    } else {
        points[first + 1..].iter().position(|p| p.at.x == x).map_or(points.len(), |k| first + 2 + k)
    };
    // A dashed slur is moved together with the slot after its last point.
    let moved_end = if dashed { (end + 1).min(buffer.slots.len()) } else { end };
    let moved: Vec<Slot> = buffer.slots[first..moved_end].to_vec();
    moved.iter().enumerate().for_each(|(k, &p)| buffer.set(k, p));
    buffer.fallback = Some(moved.len() as isize);
    buffer.npt = (end - first + 1) as isize;
    if !dashed {
        buffer.slots[0].pen = Pen::Fill;
        let closing = buffer.slots[0];
        buffer.set_at(buffer.len(), closing);
    }
}

/// Keeps the outline up to its last curve point left of `to` and from the
/// matching point of the way back on (coordinates only); on dashed slurs
/// the dashes that end before.
fn cut_after(buffer: &mut Buffer, to: i32, dashed: bool) {
    let points = buffer.points().to_vec();
    let candidates = points.iter().enumerate().filter(|(_, p)| p.at.x >= to && (!dashed || p.pen != Pen::Continue));
    for (i, _) in candidates {
        buffer.fallback = Some(i as isize);
        if dashed {
            break;
        }
        let Some(before) = i.checked_sub(1).map(|k| points[k].at.x) else {
            continue;
        };
        if let Some(k) = points[i + 1..].iter().position(|p| p.at.x == before) {
            let tail = &points[i + 1 + k..];
            tail.iter().enumerate().for_each(|(m, &p)| buffer.set_at(i + m, p));
            buffer.npt = (i + tail.len() + 1) as isize;
            return;
        }
    }
    buffer.fall_back();
}

/// 0x53BE1D: the outline split into a left and a right piece, leaving a
/// gap of 400 units (600 for numbers from 10) at the middle.
fn number_gap(buffer: &mut Buffer, item: ItemRef<'_>, step: f64, dx: f64) {
    let points: Vec<Slot> = buffer.points().to_vec();
    let next = points.len() + 1;
    let width = if item.p(16) > 9.0 { constant(600.0) } else { constant(400.0) };
    let width = real(width / (constant(25.0) / step * dx));
    let g = trunc(f64::from(next as f32) / constant(4.0) - width / constant(2.0));
    // A gap as wide as the slur leaves nothing; NPT = 4G then drops below 1.
    if g < 1 {
        if g == 0 {
            // The right piece's first point lands in slot 1, where a slash takes its level from.
            let after_middle = points.get(next / 2).copied().unwrap_or(EMPTY);
            buffer.set(0, Slot { pen: Pen::Fill, ..after_middle });
        }
        buffer.npt = 4 * g as isize;
        return;
    }
    let g = g as usize;
    let range = |from: usize, count: usize| (from..from + count).filter_map(|k| points.get(k - 1).copied());
    let middle = next / 2;
    let left = range(1, g).chain(range(next - g, g));
    let right = range(middle, g).chain(range(middle + 1 - g, g - 1));
    let arranged: Vec<Slot> = left.chain(right).collect();
    arranged.iter().enumerate().for_each(|(k, &slot)| buffer.set_at(k, slot));
    buffer.slots[2 * g].pen = Pen::Fill;
    buffer.npt = arranged.len() as isize + 1;
}

#[cfg(test)]
mod tests {
    use score_format::{Item, MusFile, Word};

    use super::*;
    use crate::codes::beam;
    use crate::display::ItemId;

    /// A file of a size-1 staff 1 and `item`.
    fn file(item: &[f32]) -> MusFile {
        let trailer = [0.0_f32, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = (trailer.len() as u16).to_le_bytes().to_vec();
        bytes.extend(trailer.iter().flat_map(|w| w.to_le_bytes()));
        let mut file = MusFile::parse(&bytes).expect("an empty file parses");
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        file.items = vec![words(&[8.0, 1.0, 0.0, 0.0, 1.0]), words(item)];
        file
    }

    fn loaded(font_loaded: fn(&Document<'_>, ItemRef<'_>) -> Option<Font>, item: &[f32]) -> Option<Font> {
        let file = file(item);
        let doc = Document::new(&file);
        font_loaded(&doc, doc.item(ItemId(1)).expect("the item exists"))
    }

    #[test]
    fn only_items_with_numbers_load_a_font() {
        let times_italic = loaded(beam::font_loaded, &[6.0, 1.0, 100.0, 9.0, 9.0, 130.0, 11.0, 3.0]);
        assert!(times_italic.is_some());
        assert_eq!(loaded(beam::font_loaded, &[6.0, 1.0, 100.0, 9.0, 9.0, 130.0, 11.0]), None);
        assert_eq!(loaded(font_loaded, &[5.0, 1.0, 100.0, 9.0, 9.0, 130.0, 5.0, 3.0]), times_italic);
        assert_eq!(loaded(font_loaded, &[5.0, 1.0, 100.0, 9.0, 9.0, 130.0, 5.0, 3.0, 0.0, 0.0, 3.0]), None);
        assert_eq!(loaded(font_loaded, &[5.0, 1.0, 100.0, 10.0, 10.0, 130.0, 5.0, 1.0]), Some(Font::TIMES));
        assert_eq!(loaded(font_loaded, &[5.0, 1.0, 100.0, 9.0, 9.0, 130.0, 3.0]), None);
        let p16 = [5.0, 1.0, 100.0, 9.0, 9.0, 130.0, 3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.0];
        assert_eq!(loaded(font_loaded, &p16), times_italic);
    }

    /// The shapes of `item`.
    fn shapes(item: &[f32]) -> Vec<crate::Shape> {
        let file = file(item);
        let list = crate::render(&Document::new(&file));
        list.shapes.into_iter().filter(|s| s.source == Some(ItemId(1))).collect()
    }

    /// A tie over a scale step's curvature, 1200 units long.
    const TIE: [f32; 7] = [5.0, 1.0, 100.0, 9.0, 9.0, 108.0, 1.0];

    /// The curve of the slur `item` and the engine's outline of it.
    fn slur(item: &[f32]) -> (Option<Smooth>, Vec<Slot>) {
        let file = file(item);
        let doc = Document::new(&file);
        let item = doc.item(ItemId(1)).expect("the slur exists");
        let slur = Slur::new(&doc, item, &Params::new(&doc, item));
        (Smooth::of(&slur, item), slur.outline(item))
    }

    fn smooth(item: &[f32]) -> Smooth {
        slur(item).0.expect("a slur with a curve")
    }

    #[test]
    fn ties_follow_the_curve_with_the_peak_sampled() {
        let (smooth, outline) = slur(&TIE);
        let smooth = smooth.expect("a slur with a curve");
        assert!(smooth.dense.contains(&smooth.peak));
        let points: Vec<Pos> = smooth.dense.iter().map(|&x| smooth.point(x)).collect();
        let direction = |a: Pos, b: Pos| (b.y - a.y).atan2(b.x - a.x).to_degrees();
        let turns = points.windows(3).map(|w| (direction(w[1], w[2]) - direction(w[0], w[1])).abs());
        assert!(turns.fold(0.0, f64::max) <= MAX_TURN_DEGREES + 1e-9);
        let tie = shapes(&TIE);
        assert_eq!(tie.len(), 1);
        let path = &tie[0].paths[0];
        assert!(path.len() > 2 * outline.len());
        // The ends stay at the engine's samples, and the peak is a point.
        let start = outline[0].at;
        assert_eq!(smooth.point(smooth.left).to_point(), start);
        let placed = |p: Point| Point::new(p.x + path[0].x - start.x, p.y + path[0].y - start.y);
        let right = outline.iter().map(|s| s.at.x).max().expect("samples");
        assert_eq!(path.iter().map(|p| p.x).max(), Some(placed(Point::new(right, 0)).x));
        assert!(path.contains(&placed(smooth.point(smooth.peak).to_point())));
    }

    #[test]
    fn thickness_lies_along_the_normal() {
        let smooth = smooth(&TIE);
        let x = smooth.left + (smooth.peak - smooth.left) * 0.2;
        let (point, back) = (smooth.point(x), smooth.back(x));
        let (_, s) = smooth.parameter(x);
        let offset = smooth.profile.offset(1.0 - s);
        assert!(offset > 0.0);
        assert!(((back.x - point.x).hypot(back.y - point.y) - offset).abs() < 1e-9);
        let ahead = smooth.point(x + 1e-3);
        let tangent = (ahead.x - point.x, ahead.y - point.y);
        assert!(((back.x - point.x) * tangent.0 + (back.y - point.y) * tangent.1).abs() < 1e-6);
        assert!(back.x < point.x, "the way back leans outward at the rising end");
    }

    #[test]
    fn dashed_slurs_keep_their_dashes() {
        let dashed = [5.0, 1.0, 100.0, 9.0, 9.0, 130.0, 3.0, 0.0, 0.0, 0.0, 5.0];
        let (_, outline) = slur(&dashed);
        let starts: Vec<i32> = outline.iter().filter(|s| s.pen == Pen::Fill).map(|s| s.at.x).collect();
        let dashes = shapes(&dashed);
        let drawn: Vec<i32> = dashes.iter().map(|s| s.paths[0][0].x - dashes[0].paths[0][0].x).collect();
        assert_eq!(drawn, starts.iter().map(|x| x - starts[0]).collect::<Vec<_>>());
    }

    #[test]
    fn triangles_are_drawn_once_whatever_their_p13() {
        let triangle = [5.0, 1.0, 100.0, 9.0, 9.0, 130.0, 3.0, 0.0, 99.0, 0.0, 0.0, 0.0, 2.0];
        assert_eq!(shapes(&triangle).len(), 1);
    }

    #[test]
    fn p8_end_rows() {
        assert_eq!(end_table_index(0), 0);
        assert_eq!(end_table_index(-1), 1);
        assert_eq!(end_table_index(11), 1);
        assert_eq!(end_table_index(-9), 9);
        assert_eq!(end_table_index(19), 9);
        assert_eq!(end_table_index(20), 0);
        assert_eq!(end_table_index(98), 10);
        assert_eq!(end_table_index(99), 11);
        assert_eq!(end_table_index(-10), 0);
    }
}
