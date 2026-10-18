//! Code 12: boxes, circles, guitar grids, accordion symbols.
//!
//! draw_item sends P5 = 0 (box), 1 (circle) and 3 (dashed box) to draw_box
//! 0x433530, which other codes call too (numbers in boxes, repeat dots,
//! harp pedal boxes): [`draw_box`] takes the parameters it reads as a
//! [`BoxCall`]. P5 = 10 (guitar grid, 0x433EEE), P5 < 0 (accordion,
//! 0x49EAE0) and the other values (arrows and arcs, 0x432E80) are not drawn
//! yet.
//!
//! On the screen the engine thickens outlines with rings 25 units apart; in
//! print it draws one outline with a wider PostScript pen and circles as
//! PostScript arcs. The refined style ([`draw_styled_box`]) does as print.

mod guitar;

use crate::canvas::{Canvas, Pen};
use crate::colour;
use crate::document::{Document, ItemRef};
use crate::codes::line;
use crate::geometry::{print_width, rotate_points, HAIRLINE};
use crate::trig::CIRCLE;
use crate::units::{real, trunc, Pos};


pub const BOX: i32 = 0;
pub const CIRCLE_SHAPE: i32 = 1;
pub const DASHED_BOX: i32 = 3;

/// The parameters draw_box reads from P() and IP() (REAL*4 and integer
/// copies, which callers sometimes set differently).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct BoxCall {
    /// IP5: 0 box, 1 circle, 3 dashed box; negative draws one circle
    /// outline and stops.
    pub kind: i32,
    /// P6, P7: half width and height in scale steps (P7 = 0 is P6).
    pub width: f64,
    pub height: f64,
    /// P8, IP8: added thickness, as rings 25 units apart (boxes) or
    /// 7.1429 / STEP apart in size (circles).
    pub p8: f64,
    pub ip8: i32,
    /// P9, IP9: clockwise rotation in degrees, applied when IP9 != 0.
    pub p9: f64,
    pub ip9: i32,
    /// P10, IP10: boxes: slant of the top edge in scale steps (IP10 != 0),
    /// dashed boxes: dash size (0 = 1); circles: first degree of an arc.
    pub p10: f64,
    pub ip10: i32,
    /// IP11: circles: last degree of an arc (0 = 360).
    pub ip11: i32,
    /// IP12: circles: degrees per polygon side (0 = 1); negative: dashes.
    pub ip12: i32,
    /// P13 != 0 fills.
    pub fill: bool,
    /// P16 = 1: sizes in units of 22.857 scale steps.
    pub p16: f64,
}

impl BoxCall {
    /// The parameters of a code-12 item.
    pub fn of(item: ItemRef<'_>) -> Self {
        let p = |n: usize| f64::from(item.p(n));
        let ip = |n: usize| trunc(p(n));
        Self {
            kind: ip(5),
            width: p(6),
            height: p(7),
            p8: p(8),
            ip8: ip(8),
            p9: p(9),
            ip9: ip(9),
            p10: p(10),
            ip10: ip(10),
            ip11: ip(11),
            ip12: ip(12),
            fill: item.p(13) != 0.0,
            p16: p(16),
        }
    }
}

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let call = BoxCall::of(item);
    let marked = trunc(f64::from(item.p(26))) == MARKED;
    let call = if marked {
        canvas.colour = colour::of(MARKED_COLOUR, doc.options);
        BoxCall { p8: f64::from(MARKED_THICKNESS), ip8: MARKED_THICKNESS, ..call }
    } else {
        call
    };
    if marked && doc.refined() && !doc.screen() {
        return;
    }
    let (at, step) = (doc.position(item), doc.staff_of(item).step);
    match call.kind {
        BOX | CIRCLE_SHAPE | DASHED_BOX => {
            let thickness = Thickness::of_marked(doc, marked);
            draw_box_as(canvas, at, step, &call, thickness);
        }
        REGISTER => draw_register(doc, item, canvas, at, &call),
        k if k < 0 => guitar::draw_guitar_grid(doc, item, canvas, at, &call),
        _ => draw_arrow(doc, item, canvas, at, &call, marked),
    }
}

const REGISTER: i32 = 10;
const REGISTER_ROWS: i32 = 3;
const REGISTER_RADIUS: f32 = 8.0;
const REGISTER_DOT: f32 = 1.4;

/// An accordion register symbol, draw_box_grid 0x433EEE: a circle of
/// radius 8 × P6 half-steps (thickness P10 + 1 rings), P7 = 2, 3 (0) or 4
/// rows divided by horizontal lines, and filled dots chosen by the digits of
/// P8 (rows, top to bottom) and P9 (centre row: right, middle, left).
fn draw_register(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, at: Pos, call: &BoxCall) {
    let staff = doc.staff_of(item);
    let step = staff.step;
    let rows = match trunc(f64::from(item.p(7))) {
        0 => REGISTER_ROWS,
        r => r,
    };
    let factor = if item.p(6) == 0.0 { 1.0 } else { f64::from(item.p(6)) };
    let rings = f64::from(real(f64::from(item.p(10)) + 1.0) as f32);
    let circle = BoxCall {
        kind: CIRCLE_SHAPE,
        width: real(factor * f64::from(REGISTER_RADIUS)),
        height: 0.0,
        p8: rings,
        ip8: 1,
        ip9: 0,
        ip10: 0,
        ip11: 0,
        ..*call
    };
    let p4 = f64::from(item.p(4));
    draw_styled_box(doc, canvas, Pos::new(at.x, staff.y(p4)), step, &circle);
    let size = real(step * factor / 25.0);
    register_lines(doc, item, canvas, &staff, at.x, rows, size, factor);
    let dot = BoxCall {
        kind: CIRCLE_SHAPE,
        width: real(factor * f64::from(REGISTER_DOT)),
        height: 0.0,
        p8: 0.0,
        ip8: 1,
        ip9: 0,
        ip10: 0,
        ip11: 0,
        fill: true,
        ..*call
    };
    let digits = (trunc(f64::from(item.p(8))), trunc(f64::from(item.p(9))));
    register_dots(doc, canvas, &staff, at.x, rows, size, factor, digits, p4, &dot);
}

/// The dividing lines through draw_line (0x4345EE): one through the centre
/// (2 rows), two at ±1.35 × P6 steps (3 rows), or the centre line and two
/// at ±1.95 × P6 (4 rows); half lengths 4.66, 4.4 and 4.08 × the size.
#[allow(clippy::too_many_arguments)]
fn register_lines(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    staff: &crate::staff::Staff,
    x: f64,
    rows: i32,
    size: f64,
    factor: f64,
) {
    let left_p3 = real(f64::from(item.p(15)) + f64::from(item.p(3)));
    let line = |canvas: &mut Canvas<'_>, half: f32, lift: f64| {
        let half = real(size * f64::from(half));
        let start = real(x - half * 150.0);
        let level = real(lift + f64::from(item.p(4)));
        let params = line::Params::of(item)
            .with(5, level as f32)
            .with(6, real(half + left_p3) as f32)
            .with(7, 0.0)
            .with(8, 0.0)
            .with(9, 0.0)
            .with(10, 0.0)
            .with(11, 0.0)
            .with(12, 0.0)
            .with(13, 0.0)
            .with(18, factor as f32);
        line::draw(doc, &params, Pos::new(start, staff.y(level)), staff, canvas);
    };
    let pair = |canvas: &mut Canvas<'_>, half: f32, lift: f32| {
        let lift = real(factor * f64::from(lift));
        // The engine negates the stored f32, so the lower line is the exact mirror.
        line(canvas, half, lift);
        line(canvas, half, -lift);
    };
    match rows {
        3 => pair(canvas, 4.4, 1.35),
        4 => {
            line(canvas, 4.66, 0.0);
            pair(canvas, 4.08, 1.95);
        }
        _ => line(canvas, 4.66, 0.0),
    }
}

/// The filled dots: P8's digits pick rows (4 rows: thousands to units from
/// the bottom row up; 2 rows: tens below, units above; otherwise hundreds
/// below, units above, tens in the centre), P9's units and hundreds add
/// dots right and left of the centre (P9's tens too for a centre dot).
#[allow(clippy::too_many_arguments)]
fn register_dots(
    doc: &Document<'_>,
    canvas: &mut Canvas<'_>,
    staff: &crate::staff::Staff,
    x: f64,
    rows: i32,
    size: f64,
    factor: f64,
    (p8, p9): (i32, i32),
    p4: f64,
    dot: &BoxCall,
) {
    let step = staff.step;
    // Each circle leaves IP12 doubled and the dots do not reset it, so every
    // further dot has twice the degrees per side; draw_line leaves 0. The
    // refined style draws every dot round.
    let mut ip12 = 0;
    let mut draw = |canvas: &mut Canvas<'_>, x: f64, level: f64, dot: &BoxCall| {
        ip12 = draw_styled_box(doc, canvas, Pos::new(x, staff.y(level)), step, &BoxCall { ip12, ..*dot });
        if doc.refined() {
            ip12 = 0;
        }
    };
    let times = |c: f32| real(factor * f64::from(c));
    let tens = |n: i32| (n % 100) / 10 != 0;
    match rows {
        4 => {
            let gap = times(1.98);
            let levels = std::iter::successors(Some(real(p4 - times(2.95))), |l| Some(real(gap + l)));
            let digits = [p8 / 1000, (p8 % 1000) / 100, (p8 % 100) / 10, p8 % 10];
            digits.into_iter().zip(levels).filter(|&(d, _)| d != 0).for_each(|(_, level)| draw(canvas, x, level, dot));
            if p9 == 0 {
                return;
            }
        }
        2 => {
            let dot = BoxCall { width: times(1.8), ..*dot };
            let offset = times(2.0);
            if p8 / 10 != 0 {
                draw(canvas, x, real(p4 - offset), &dot);
            }
            if p8 % 10 != 0 {
                draw(canvas, x, real(offset + p4), &dot);
            }
            return;
        }
        _ => {
            let offset = times(2.55);
            if p8 / 100 != 0 {
                draw(canvas, x, real(p4 - offset), dot);
            }
            if p8 % 10 != 0 {
                draw(canvas, x, real(offset + p4), dot);
            }
            if tens(p8) || tens(p9) {
                draw(canvas, x, p4, dot);
            }
        }
    }
    let reach: f32 = if rows == 4 || (!tens(p8) && rows == 3) { 2.45 } else { 2.875 };
    let reach = real(size * f64::from(reach) * 150.0);
    if p9 % 10 != 0 {
        draw(canvas, real(reach + x), p4, dot);
    }
    if p9 / 100 != 0 {
        draw(canvas, real(x - reach), p4, dot);
    }
}

/// Arrows, draw_box_other 0x432E80: with P10 = 1 a straight arrow of P6
/// times 5 scale steps with a head P13 (or P12) long and P12 wide; otherwise
/// a circular arc from 90° to 180° − P11 whose end lies on the item's
/// point, with a filled triangle as its head. P9 turns the whole arrow.
fn draw_arrow(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, at: Pos, call: &BoxCall, marked: bool) {
    let staff = doc.staff_of(item);
    let step = staff.step;
    let start = canvas.buffer_mut().len();
    let or_one = |v: f32| if v == 0.0 { 1.0 } else { f64::from(v) };
    let width = or_one(item.p(6));
    let height = if item.p(7) == 0.0 { width } else { f64::from(item.p(7)) };
    let head_width = or_one(item.p(12));
    let head_length = if item.p(13) == 0.0 { head_width } else { f64::from(item.p(13)) };
    let p9 = item.p(9);
    let centre = if call.ip10 == STRAIGHT {
        // draw_box_other 0x432E80 sets the print width IP8 for the whole arrow.
        let pen = (doc.refined() && call.ip8 > 0).then(|| print_width(call.ip8 as f32));
        if let Some(pen) = pen {
            canvas.set_width(pen);
        }
        draw_straight_arrow(canvas, at, step, call, (width, head_width, head_length));
        if pen.is_some() {
            canvas.set_width(0.0);
        }
        if call.ip12 >= 0 {
            if p9 != 0.0 {
                rotate_points(&mut canvas.buffer_mut()[start..], at.to_point(), p9);
            }
            return;
        }
        at
    } else {
        draw_arc_arrow(doc, item, canvas, at, call, marked, (width, height, head_width, head_length))
    };
    if doc.screen() && p9 != 0.0 {
        rotate_points(&mut canvas.buffer_mut()[start..], centre.to_point(), p9);
    }
}

const STRAIGHT: i32 = 1;
const ARROW_UNIT: f32 = 6.9996;
const STRAIGHT_UNIT: f32 = 6.0;
const STRAIGHT_LENGTH: f32 = 35.0;
const HEAD_HALF_WIDTH: f32 = 0.555;

/// The shaft from the item's point to the right, then the head as a filled
/// triangle (a negative IP12 leaves it out).
fn draw_straight_arrow(canvas: &mut Canvas<'_>, at: Pos, step: f64, call: &BoxCall, sizes: (f64, f64, f64)) {
    let (width, head_width, head_length) = sizes;
    let unit = real(step * f64::from(STRAIGHT_UNIT));
    canvas.point(at, Pen::Stroke);
    let end = real(step * f64::from(STRAIGHT_LENGTH) * width + at.x);
    canvas.point(Pos::new(end, at.y), Pen::Continue);
    if call.ip12 < 0 {
        return;
    }
    let length = real(unit * head_length);
    let length = if width < 0.0 { -length } else { length };
    let half = real(head_width * f64::from(HEAD_HALF_WIDTH) * unit);
    let tip = Pos::new(real(length + end), at.y);
    canvas.point(tip, Pen::Fill);
    canvas.point(Pos::new(end, real(half + at.y)), Pen::Continue);
    canvas.point(Pos::new(end, real(at.y - half)), Pen::Continue);
    canvas.point(tip, Pen::Continue);
}

const ARC_SCALE: f32 = 10.0;
const ARC_TABLE_DIVISOR: f32 = 20.0;
const ARC_START: i32 = 90;
const LAST_ARC_P11: i32 = 360;
const ARROWHEAD_SIZE: f32 = 1.2;
const ARROWHEAD_LIFT: f32 = 0.28;
const ARROWHEAD_REACH: f32 = 5.0;
const ARROWHEAD_SIDES: i32 = 120;

/// The arc and its head (both through draw_box); returns the arc's centre.
/// For P11 above 180 the engine reads its circle table below its start,
/// where it finds zeros (verified with P11 = 270 and 405): the arc is then
/// centred on the item's point.
fn draw_arc_arrow(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    at: Pos,
    call: &BoxCall,
    marked: bool,
    sizes: (f64, f64, f64, f64),
) -> Pos {
    let (width, height, head_width, head_length) = sizes;
    let staff = doc.staff_of(item);
    let step = staff.step;
    let unit = real(step * f64::from(ARROW_UNIT));
    let end = HALF_TURN - call.ip11.min(LAST_ARC_P11);
    let (sin, cos) = usize::try_from(end % FULL_TURN).map_or((0.0, 0.0), |degree| CIRCLE[degree]);
    let a = real(width * f64::from(sin) / f64::from(ARC_TABLE_DIVISOR));
    let b = real(height * f64::from(cos) / f64::from(ARC_TABLE_DIVISOR));
    let (dx, dy) = if call.ip9 == 0 {
        (a, b)
    } else {
        let radians = real(call.p9 / f64::from(DEGREES_PER_RADIAN));
        let (s, c) = (real(radians.sin()), real(radians.cos()));
        (real(b * s + a * c), real(b * c - a * s))
    };
    let level = real(f64::from(item.p(4)) - dy);
    let centre = Pos::new(real(at.x - unit * dx), staff.y(level));
    let scale = f64::from(ARC_SCALE);
    let arc = BoxCall {
        kind: CIRCLE_SHAPE,
        width: real(width * scale),
        height: real(height * scale),
        ip9: 0,
        ip10: ARC_START,
        ip11: end,
        ip12: 0,
        fill: false,
        ..*call
    };
    let thickness = Thickness::of_marked(doc, marked);
    draw_box_as(canvas, centre, step, &arc, thickness);
    if head_width >= 0.0 {
        let head_length = if height < 0.0 { -head_length } else { head_length };
        let size = f64::from(ARROWHEAD_SIZE);
        let head_p8 = if marked { f64::from(MARKED_THICKNESS) } else { -1.0 };
        let head = BoxCall {
            kind: CIRCLE_SHAPE,
            width: real(head_width * size),
            height: real(head_length * size),
            p8: head_p8,
            ip9: 0,
            ip10: 0,
            ip11: 0,
            ip12: ARROWHEAD_SIDES,
            fill: true,
            ..*call
        };
        let lift = real(head_length * f64::from(ARROWHEAD_LIFT));
        let head_at = Pos::new(
            real(unit * f64::from(ARROWHEAD_REACH) * width + centre.x),
            staff.y(real(lift + level)),
        );
        draw_box_as(canvas, head_at, step, &head, thickness);
    }
    centre
}

const DEGREES_PER_RADIAN: f32 = 57.295_776;

/// IP26 = -1 marks a box: blue (P26 = 99) and three rings thick on the
/// screen. In print it is not drawn; the engine style does not model that,
/// the refined style does.
const MARKED: i32 = -1;
const MARKED_COLOUR: f32 = 99.0;
const MARKED_THICKNESS: i32 = 3;

/// Size unit for P16 = 1.
const P16_UNIT: f32 = 22.857;
/// Half a box side per unit of P6/P7 and step unit: 3.5 = half a scale step.
const HALF_SIDE: f32 = 3.5;
/// Ring spacing of thick boxes (25 × the global size factor 0x1C589F8, 1).
const BOX_RING: f64 = 25.0;
/// Size added per ring of a thick circle, divided by STEP.
const CIRCLE_RING: f32 = 7.1429;
/// The circle table holds 100 × sin/cos; this brings it to half scale steps.
const CIRCLE_UNIT: f32 = 0.035;
const SLANT_UNIT: f32 = 7.0;
/// Dashed boxes: dash length per unit of P10.
const DASH: f32 = 175.0;

/// draw_box 0x433530 at the centre `at` on a staff with step unit `step`,
/// as the engine draws on the screen ([`draw_styled_box`] for the
/// document's style).
///
/// Returns the IP12 the routine leaves in the engine's globals: circles
/// double it (see [`draw_circles`]), which changes the next circle of a
/// caller that does not reset it.
pub fn draw_box(canvas: &mut Canvas<'_>, at: Pos, step: f64, call: &BoxCall) -> i32 {
    draw_box_as(canvas, at, step, call, Thickness::Rings)
}

/// [`draw_box`] in the document's style: the refined style draws a thick
/// outline with SCORE's print width ([`print_pen_of`]) instead of rings,
/// and the circles print draws as PostScript arcs round.
pub fn draw_styled_box(doc: &Document<'_>, canvas: &mut Canvas<'_>, at: Pos, step: f64, call: &BoxCall) -> i32 {
    draw_box_as(canvas, at, step, call, Thickness::of(doc))
}

/// How draw_box draws P8's thickness.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Thickness {
    /// One more outline per ring, as on the screen.
    Rings,
    /// One outline with SCORE's print width (the refined style).
    Pen,
    /// The rings' extent as one band: the refined style's marked frames,
    /// which only the screen shows.
    Band,
}

impl Thickness {
    fn of(doc: &Document<'_>) -> Self {
        if doc.refined() {
            Thickness::Pen
        } else {
            Thickness::Rings
        }
    }

    /// For a code-12 item, which the refined style draws as a band when it
    /// is marked (IP26 = -1).
    fn of_marked(doc: &Document<'_>, marked: bool) -> Self {
        match Self::of(doc) {
            Thickness::Pen if marked => Thickness::Band,
            thickness => thickness,
        }
    }
}

fn draw_box_as(canvas: &mut Canvas<'_>, at: Pos, step: f64, call: &BoxCall, thickness: Thickness) -> i32 {
    let start = canvas.buffer_mut().len();
    let height = if call.height == 0.0 { call.width } else { call.height };
    let (width, height) = if call.p16 == 1.0 && matches!(call.kind, BOX | CIRCLE_SHAPE | DASHED_BOX) {
        let unit = f64::from(P16_UNIT);
        (real(unit * call.width), real(unit * height))
    } else {
        (call.width, height)
    };
    let pen = if call.fill { Pen::Fill } else { Pen::Stroke };
    let print_pen = (thickness == Thickness::Pen).then(|| print_pen_of(call)).flatten();
    if let Some(width) = print_pen {
        canvas.set_width(width);
    }
    let ip12 = match call.kind {
        BOX | DASHED_BOX => {
            draw_rectangles(canvas, at, step, call, (width, height), pen, thickness);
            call.ip12
        }
        _ => draw_circles(canvas, at, step, call, (width, height), pen, thickness),
    };
    if print_pen.is_some() {
        canvas.set_width(0.0);
    }
    if call.ip9 != 0 && call.kind >= 0 {
        rotate_points(&mut canvas.buffer_mut()[start..], at.to_point(), call.p9 as f32);
    }
    ip12
}

/// The pen SCORE's print output outlines a box or circle with (draw_box
/// 0x433530): with P8 set, 0x50E203 asks for 2·P8 print pixels (through the
/// print-width marker for boxes, directly for circles); boxes without P8
/// and dashed circles (IP12 < 0) pass IP8 to the marker. Filled circles
/// that print draws as arcs (0x50E352) are filled without an outline.
fn print_pen_of(call: &BoxCall) -> Option<f32> {
    if call.fill && print_arc(call) {
        return Some(HAIRLINE);
    }
    let pixels = match call.kind {
        BOX | DASHED_BOX if call.p8 != 0.0 => trunc(2.0 * call.p8),
        BOX | DASHED_BOX => call.ip8,
        _ if call.ip12 < 0 => call.ip8.max(0),
        _ if call.p8 != 0.0 => trunc(2.0 * call.p8),
        _ => 0,
    };
    (pixels != 0).then(|| print_width(pixels as f32))
}

/// Whether print draws a circle as a PostScript arc (0x50E352): with up to
/// five degrees per side.
fn print_arc(call: &BoxCall) -> bool {
    let sides = if call.ip12 == 0 { 1 } else { call.ip12 };
    !matches!(call.kind, BOX | DASHED_BOX) && (1..=MAX_ARC_SIDES).contains(&sides)
}

/// Degrees per side up to which print draws arcs.
const MAX_ARC_SIDES: i32 = 5;
/// The circle table holds 100 × sin/cos.
const TABLE_RADIUS: f64 = 100.0;
/// Degrees per side of the refined style's arcs, at most.
const ROUND_SIDES: i32 = 10;

/// Degrees per side for an arc print draws exactly: at most
/// [`ROUND_SIDES`], fewer on large circles so that no side strays more than
/// a unit from the circle, and a divisor of the arc's `span` so that it
/// ends where it should. `asked` is the arc's own (at most 5).
fn arc_sides(span: i32, radius: f64, asked: i32) -> i32 {
    let fine = (2.0 * (1.0 - 1.0 / radius.max(1.0)).acos()).to_degrees() as i32;
    let target = fine.clamp(asked, ROUND_SIDES);
    (asked..=target).rev().find(|d| span % d == 0).unwrap_or(asked)
}

/// The corners of one box outline: bottom left, bottom right, top right
/// and top left, the top shifted by the slant.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Outline {
    left: f64,
    right: f64,
    bottom: f64,
    top: f64,
    slant: f64,
}

impl Outline {
    fn corners(&self) -> [Pos; 4] {
        [
            Pos::new(self.left, self.bottom),
            Pos::new(self.right, self.bottom),
            Pos::new(real(self.slant + self.right), self.top),
            Pos::new(real(self.slant + self.left), self.top),
        ]
    }

    fn grown(&self, by: f64) -> Self {
        Self {
            left: real(self.left - by),
            right: real(by + self.right),
            bottom: real(self.bottom - by),
            top: real(by + self.top),
            ..*self
        }
    }
}

/// Boxes: the outline, then one more outline 25 units further out per
/// thickness ring. Solid outlines continue one path (0x4A060D clears the
/// pen after the first point); a dashed box draws at most two outlines.
/// With [`Thickness::Pen`] only the first outline, with [`Thickness::Band`]
/// a solid box's rings as one band.
fn draw_rectangles(
    canvas: &mut Canvas<'_>,
    at: Pos,
    step: f64,
    call: &BoxCall,
    (width, height): (f64, f64),
    pen: Pen,
    thickness: Thickness,
) {
    let rings = if call.ip8 == 0 { 0 } else { trunc(step * call.p8 / BOX_RING) };
    let rings = if call.kind == DASHED_BOX { rings.min(1) } else { rings };
    let rings = if thickness == Thickness::Pen { 0 } else { rings };
    let half_step = real(step * f64::from(HALF_SIDE));
    let (half_x, half_y) = (real(half_step * width), real(half_step * height));
    let slant = if call.ip10 != 0 { real(step * f64::from(SLANT_UNIT) * call.p10) } else { 0.0 };
    let first = Outline {
        left: real(at.x - half_x),
        right: real(half_x + at.x),
        bottom: real(at.y - half_y),
        top: real(half_y + at.y),
        slant,
    };
    let outlines = std::iter::successors(Some(first), |o| Some(o.grown(BOX_RING))).take(rings.max(0) as usize + 1);
    if thickness == Thickness::Band && call.kind == BOX && rings > 0 {
        let outer = outlines.last().unwrap_or(first);
        let paths = if call.fill { vec![outer.corners()] } else { vec![first.corners(), outer.corners()] };
        canvas.fill(paths);
        return;
    }
    outlines.enumerate().for_each(|(i, outline)| {
        if call.kind == DASHED_BOX {
            draw_dashed(canvas, &outline, call.p10);
        } else {
            let [a, b, c, d] = outline.corners();
            let first_pen = if i == 0 { pen } else { Pen::Continue };
            canvas.point(a, first_pen);
            [b, c, d, a].into_iter().for_each(|p| canvas.point(p, Pen::Continue));
        }
    });
}

/// A dashed box outline (0x434B6D): an odd number of dashes per side, each
/// side's dashes as long as the integer side length allows, continuing
/// round the corners. The vertical sides ignore the slant.
fn draw_dashed(canvas: &mut Canvas<'_>, outline: &Outline, p10: f64) {
    let dash = if p10 == 0.0 { 1.0 } else { p10 };
    let width = trunc(outline.right - outline.left);
    let height = trunc(outline.top - outline.bottom);
    let dashes = |length: i32| {
        let n = trunc(f64::from(length as f32) / (dash * f64::from(DASH)) + 0.5);
        if n % 2 == 0 { n - 1 } else { n }
    };
    let (across, up) = (dashes(width), dashes(height));
    let dx = f64::from(width / across);
    let dy = f64::from(height / up);
    let mut point = |x: f64, y: f64, pen: Pen| canvas.point(Pos::new(x, y), pen);

    let mut x = outline.left;
    (0..(across + 1) / 2).for_each(|_| {
        point(x, outline.bottom, Pen::Stroke);
        x = real(dx + x);
        point(x, outline.bottom, Pen::Continue);
        x = real(dx + x);
    });
    let mut y = real(dy + outline.bottom);
    (1..(up + 1) / 2).for_each(|_| {
        point(outline.right, y, Pen::Continue);
        y = real(dy + y);
        point(outline.right, y, Pen::Stroke);
        y = real(dy + y);
    });
    point(outline.right, y, Pen::Continue);
    let mut x = real(outline.right - dx);
    (1..(across + 1) / 2).for_each(|_| {
        point(x, outline.top, Pen::Continue);
        x = real(x - dx);
        point(x, outline.top, Pen::Stroke);
        x = real(x - dx);
    });
    point(x, outline.top, Pen::Continue);
    let mut y = real(outline.top - dy);
    (1..(up + 1) / 2).for_each(|_| {
        point(outline.left, y, Pen::Continue);
        y = real(y - dy);
        point(outline.left, y, Pen::Stroke);
        y = real(y - dy);
    });
    point(outline.left, y, Pen::Continue);
    point(real(dx + outline.left), outline.bottom, Pen::Continue);
}

/// Degrees in the circle table, and its last index pair.
const FULL_TURN: i32 = 360;
const HALF_TURN: i32 = 180;

/// Circles and arcs: points every IP12 degrees from IP10 to IP11 clockwise
/// from the top, as dashes when IP12 is negative; then one further outline
/// per thickness ring, each a new polyline. Returns the IP12 the engine
/// leaves behind: twice the degrees per side, or 2 after dashes. Except
/// with [`Thickness::Rings`], arcs print draws exactly are drawn round
/// ([`arc_sides`]) and without rings, or with [`Thickness::Band`] a solid
/// circle's rings as one band.
fn draw_circles(
    canvas: &mut Canvas<'_>,
    at: Pos,
    step: f64,
    call: &BoxCall,
    (width, height): (f64, f64),
    pen: Pen,
    thickness: Thickness,
) -> i32 {
    let rings = if call.ip8 >= 1 { trunc(step * call.p8 / BOX_RING) } else { 0 };
    let rings = if thickness == Thickness::Pen { 0 } else { rings };
    let growth = real(f64::from(CIRCLE_RING) / step);
    let from = if call.ip10 < 0 { call.ip10 + FULL_TURN } else { call.ip10 };
    let to = if call.ip11 == 0 { FULL_TURN } else { call.ip11 };
    let to = if to < from { to + FULL_TURN } else { to };
    let mut sides = if call.ip12 == 0 { 1 } else { call.ip12 };
    let unit = real(step * f64::from(CIRCLE_UNIT));
    let radius_of = |width: f64, height: f64| (real(unit * width), real(unit * height));
    let traced = if thickness != Thickness::Rings && print_arc(call) {
        let (rx, ry) = radius_of(width, height);
        arc_sides(to - from, rx.abs().max(ry.abs()) * TABLE_RADIUS, sides)
    } else {
        sides
    };
    let (mut width, mut height, mut pen) = (width, height, pen);
    let last_ring = if call.kind < 0 { 0 } else { rings.max(0) };
    if thickness == Thickness::Band && sides >= 1 && last_ring > 0 {
        let inner = radius_of(width, height);
        (0..last_ring).for_each(|_| {
            width = real(growth + width);
            height = real(growth + height);
        });
        let arc = |radius| {
            let mut points = Vec::new();
            trace_arc(&mut |p, _| points.push(p), at, radius, from, to, traced, None, Pen::Fill);
            points
        };
        let (inner, outer) = (arc(inner), arc(radius_of(width, height)));
        if call.fill {
            canvas.fill([outer]);
        } else if to - from >= FULL_TURN {
            canvas.fill([inner, outer]);
        } else {
            canvas.fill([outer.into_iter().chain(inner.into_iter().rev()).collect::<Vec<_>>()]);
        }
        return 2 * sides;
    }
    (0..=last_ring).for_each(|ring| {
        if ring > 0 {
            width = real(growth + width);
            height = real(growth + height);
        }
        let dashes = (sides < 1).then(|| {
            sides = divisor_of_half_turn(sides);
            -sides
        });
        let traced = if dashes.is_some() { sides } else { traced };
        trace_arc(&mut |p, pen| canvas.point(p, pen), at, radius_of(width, height), from, to, traced, dashes, pen);
        pen = Pen::Stroke;
    });
    if sides < 0 {
        2
    } else {
        2 * sides
    }
}

/// The engine's search for a divisor of 180 near a negative `n`:
/// alternately one lower and one higher, lower first.
fn divisor_of_half_turn(n: i32) -> i32 {
    let mut up = n;
    let mut down = n;
    while HALF_TURN % up != 0 {
        down -= 1;
        if HALF_TURN % down == 0 {
            return down;
        }
        up += 1;
    }
    up
}

/// One outline through the circle table, `step` degrees apart, or dashes of
/// `dash` degrees with gaps as long, its points given to `emit`.
#[allow(clippy::too_many_arguments)]
fn trace_arc(
    emit: &mut dyn FnMut(Pos, Pen),
    centre: Pos,
    radius: (f64, f64),
    from: i32,
    to: i32,
    sides: i32,
    dash: Option<i32>,
    pen: Pen,
) {
    // Past the table the engine reads whatever static data follows it; the port draws zeros there.
    let table = |i: i32| usize::try_from((i - 1) / 2).ok().and_then(|k| CIRCLE.get(k)).copied().unwrap_or((0.0, 0.0));
    let mut index = 2 * from + 1;
    let mut end = 2 * to + 1 - i32::from(dash.is_some());
    let advance = if dash.is_some() { 2 } else { 2 * sides };
    let mut left_in_dash = dash.map_or(0, |d| d + 1);
    let mut pen = pen;
    loop {
        let (sin, cos) = table(index);
        let at = Pos::new(real(radius.0 * f64::from(sin) + centre.x), real(radius.1 * f64::from(cos) + centre.y));
        emit(at, pen);
        pen = Pen::Continue;
        let mut step = advance;
        if let Some(d) = dash {
            left_in_dash -= 1;
            if left_in_dash == 0 {
                left_in_dash = d + 1;
                pen = Pen::Stroke;
                step = 2 * d;
            }
        }
        index += step;
        if end < index {
            break;
        }
        if index > 2 * FULL_TURN + 1 {
            index = 1;
            end -= 2 * FULL_TURN + 2;
        }
    }
}

#[cfg(test)]
mod tests {
    use score_format::{Item, MusFile, Word};

    use super::*;
    use crate::display::{print_pen, ItemId, Point, Shape, ShapeKind};
    use crate::document::{Medium, Options};

    /// The shapes of `item` after a size-1 staff 1.
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
    fn refined_thick_boxes_have_one_outline_with_the_print_pen() {
        let box_p8 = [12.0, 1.0, 100.0, 5.0, 0.0, 2.0, 0.0, 2.0];
        let engine = shapes(&box_p8, Options::ENGINE);
        assert_eq!(engine[0].paths[0].len(), 15, "three outlines in one path");
        let refined = shapes(&box_p8, Options::REFINED);
        assert_eq!(refined.len(), 1);
        assert_eq!(refined[0].paths[0], engine[0].paths[0][..5]);
        assert_eq!(refined[0].width, print_pen(4.0));
        let circle = shapes(&[12.0, 1.0, 100.0, 5.0, 1.0, 2.0, 0.0, 2.0], Options::REFINED);
        assert_eq!(circle.len(), 1);
        assert_eq!(circle[0].width, print_pen(4.0));
    }

    #[test]
    fn refined_marked_boxes_are_one_band_on_the_screen_only() {
        let marked = [12.0, 1.0, 100.0, 5.0, 0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0];
        let band = shapes(&marked, Options::REFINED);
        assert_eq!(band.len(), 1);
        assert_eq!((band[0].kind, band[0].paths.len()), (ShapeKind::Fill, 2));
        let engine = shapes(&marked, Options::ENGINE);
        let xs = |paths: &[Vec<Point>]| paths.iter().flatten().map(|p| p.x).collect::<Vec<_>>();
        let extent = |xs: Vec<i32>| (xs.iter().min().copied(), xs.iter().max().copied());
        assert_eq!(extent(xs(&band[0].paths)), extent(xs(&engine[0].paths)));
        let print = Options { medium: Medium::Print, ..Options::REFINED };
        assert!(shapes(&marked, print).is_empty());
    }

    #[test]
    fn print_arcs_are_drawn_round_with_sides_that_fit() {
        assert_eq!(arc_sides(360, 50.0, 1), 10);
        assert_eq!(arc_sides(360, 900.0, 1), 5);
        assert_eq!(arc_sides(90, 50.0, 1), 10);
        assert_eq!(arc_sides(70, 50.0, 1), 10);
        assert_eq!(arc_sides(77, 50.0, 1), 7);
        assert_eq!(arc_sides(360, 20_000.0, 2), 2);
    }
}
