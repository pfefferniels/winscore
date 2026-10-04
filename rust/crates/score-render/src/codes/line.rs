//! Code 4: lines, dashes, dots, wavy lines, hairpins and multipoint lines
//! (draw_line 0x439963).
//!
//! P3/P4 left end, P6/P5 right end (P5 = 999 makes a hairpin, P7 its
//! spread); P7 type: 0 line, 1..99 dashes (P8 length, P9 space), -1 heavy
//! and -2 thin wavy line, -3 sawtooth, -4 dots, -5 vertical line (+ P15),
//! 100 multipoint line (P8..P17 points, P18/P19 scale, P20 rotation, P21
//! thickness). P10 thickness, P11/P12 bracket or arrow at the left/right end
//! (P11 = 1 on a hairpin: dashed), P13 rotation (P9 on lines and hairpins),
//! P14/P15 partial hairpins, P16 = 1 with P17/P18 end offsets. Wavy lines
//! and P7 = -5 with P6 = 0 (or P6 = P3) run upward from P4 to P5.
//!
//! The engine's screen branches are ported (OUTPUT_MODE 1); its PostScript
//! line widths for print are not part of the display list.

use std::iter::{once, successors};

use crate::canvas::{BufferPoint, Canvas, Pen};
use crate::display::Point;
use crate::document::{Document, ItemRef};
use crate::geometry::rotate_points;
use crate::page::P3_UNIT;
use crate::staff::{Staff, UNITS_PER_SCALE_STEP};
use crate::units::{real, trunc, Pos};

const PARAMS: usize = 50;

/// P1…P50 as draw_line reads them. Other routines (dashed barlines, code 7)
/// call [`draw`] with parameters of their own.
#[derive(Debug, Clone, PartialEq)]
pub struct Params([f32; PARAMS]);

impl Default for Params {
    fn default() -> Self {
        Self([0.0; PARAMS])
    }
}

impl Params {
    pub fn of(item: ItemRef<'_>) -> Self {
        Self(std::array::from_fn(|i| item.p(i + 1)))
    }

    /// Parameter `n`, 1-based.
    pub fn p(&self, n: usize) -> f32 {
        self.0[n - 1]
    }

    pub fn set(&mut self, n: usize, value: f32) {
        self.0[n - 1] = value;
    }

    pub fn with(mut self, n: usize, value: f32) -> Self {
        self.set(n, value);
        self
    }

    /// IP(n) = INT(P(n)), as draw_item 0x547210 prepares it.
    fn ip(&self, n: usize) -> i32 {
        trunc(f64::from(self.p(n)))
    }
}

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    draw(&Params::of(item), doc.position(item), &doc.staff_of(item), canvas);
}

/// P5 at or above this makes a hairpin.
const HAIRPIN: i32 = 999;
const QUICK_VERTICAL: i32 = -5;
const DOTS: i32 = -4;
const SAWTOOTH: i32 = -3;
const HEAVY_WAVE: i32 = -1;
const MULTIPOINT: i32 = 100;

/// Draws a code-4 item with parameters `params` whose P3/P4 point is
/// `origin` (X_POS, Y_POS) on `staff`.
pub fn draw(params: &Params, origin: Pos, staff: &Staff, canvas: &mut Canvas<'_>) {
    let mut line = Line::new(params, origin, staff, canvas.buffer_mut().len());
    if line.ip5 >= HAIRPIN {
        hairpin(&mut line, canvas);
        return;
    }
    let right = Pos::new(line.right_x, staff.y(f64::from(line.p.p(5))));
    match line.ip7 {
        0 => straight(&line, right, canvas),
        QUICK_VERTICAL => {
            line.left.x = line.offset_by_p15(line.left.x);
            let right = Pos::new(line.left.x, right.y);
            straight(&line, right, canvas);
        }
        k if k >= MULTIPOINT => multipoint(&line, right, canvas),
        k if k > 0 => dashes(&line, right.y, canvas),
        DOTS => dots(&line, canvas),
        _ => wavy(&mut line, canvas),
    }
}

/// The routine's working state: the parameters after its own adjustments,
/// the left end (X0, Y0), the right end's x (X1) and the thickness IP10.
struct Line<'a> {
    p: Params,
    ip4: i32,
    ip5: i32,
    ip7: i32,
    staff: &'a Staff,
    left: Pos,
    right_x: f64,
    thickness: i32,
    /// The buffer index of the line's first point (NPT0).
    start: usize,
}

impl<'a> Line<'a> {
    fn new(params: &Params, origin: Pos, staff: &'a Staff, start: usize) -> Self {
        let mut p = params.clone();
        let mut thickness = params.ip(10);
        if p.p(5) == 0.0 && p.p(6) == 0.0 {
            // The engine also reports "*** Code 4 needs value in P5 or P6 ***".
            p.set(6, real(f64::from(p.p(3)) + 20.0) as f32);
            thickness = 4;
        }
        let mut x = origin.x;
        if p.p(16) == 1.0 {
            // 0x53C1F1
            x = real(f64::from(p.p(17)) * P3_UNIT + x);
            p.set(6, real(f64::from(p.p(18)) + f64::from(p.p(6))) as f32);
        }
        if p.p(7) >= MULTIPOINT as f32 {
            scale_multipoint_ends(&mut p);
        }
        let (ip5, ip7) = (params.ip(5), params.ip(7));
        if ip7 == HEAVY_WAVE && ip5 != HAIRPIN {
            thickness = 0;
        }
        Self {
            right_x: real(f64::from(p.p(6)) * P3_UNIT),
            p,
            ip4: params.ip(4),
            ip5,
            ip7,
            staff,
            left: Pos::new(x, origin.y),
            thickness,
            start,
        }
    }

    fn step(&self) -> f64 {
        self.staff.step
    }

    fn scale_step(&self) -> f64 {
        real(UNITS_PER_SCALE_STEP * self.step())
    }

    fn offset_by_p15(&self, x: f64) -> f64 {
        match self.p.p(15) {
            0.0 => x,
            p15 => real(f64::from(p15) * P3_UNIT + x),
        }
    }

    /// Lines and hairpins take their rotation from P9 when IP9 is set.
    fn rotation(&self) -> f32 {
        if self.p.ip(9) != 0 {
            self.p.p(9)
        } else {
            self.p.p(13)
        }
    }

    fn rotate(&self, canvas: &mut Canvas<'_>, degrees: f32) {
        if degrees != 0.0 {
            let centre = self.left.to_point();
            rotate_points(&mut canvas.buffer_mut()[self.start..], centre, degrees);
        }
    }
}

/// P18 and P19 stretch a multipoint line horizontally and vertically.
fn scale_multipoint_ends(p: &mut Params) {
    let scaled = |end: f32, from: f32, factor: f32| {
        real((f64::from(end) - f64::from(from)) * f64::from(factor) + f64::from(from)) as f32
    };
    let fx = p.p(18);
    if fx != 0.0 && fx != 1.0 {
        p.set(6, scaled(p.p(6), p.p(3), fx));
    }
    if p.p(19) == 0.0 {
        p.set(19, fx);
    }
    let fy = p.p(19);
    if fy != 0.0 && fy != 1.0 {
        p.set(5, scaled(p.p(5), p.p(4), fy));
    }
}

fn straight(line: &Line<'_>, right: Pos, canvas: &mut Canvas<'_>) {
    let across = line.ip7 == QUICK_VERTICAL;
    let scale_step = line.scale_step();
    let pen = match line.p.p(11) {
        0.0 => Pen::Stroke,
        v => end_mark(canvas, line.left, v, End::Start, across, scale_step),
    };
    canvas.point(line.left, pen);
    canvas.point(right, Pen::Continue);
    if line.p.p(12) != 0.0 {
        end_mark(canvas, right, line.p.p(12), End::Finish, across, scale_step);
    }
    if line.thickness != 0 {
        // 0x43C0EA: the copies go up and down unless the line is steeper than 45°.
        let flat = (right.x - line.left.x).abs() - (right.y - line.left.y).abs() >= 0.0;
        thicken(canvas, line.start, if flat { line.thickness * 100 } else { line.thickness });
    }
    line.rotate(canvas, line.rotation());
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) enum End {
    Start,
    Finish,
}

/// end_mark 0x43C11A: what P11 (at the start) or P12 (at the finish) adds.
/// Up to 100: a bracket of that many scale steps, from which the line
/// continues; below 200: an arrow head of spread P - 100, pointing outward;
/// from 200: a bracket of P - 200 steps downward. `across`: the line is a
/// P7 = -5 vertical line, and the marks lie horizontally (the last kind
/// both ways). Returns the pen for the line's next point.
pub(crate) fn end_mark(canvas: &mut Canvas<'_>, at: Pos, value: f32, end: End, across: bool, scale_step: f64) -> Pen {
    let incoming = match end {
        End::Start => Pen::Stroke,
        End::Finish => Pen::Continue,
    };
    let v = f64::from(value);
    let shifted = |length: f64| {
        if across {
            Pos::new(real(length + at.x), at.y)
        } else {
            Pos::new(at.x, real(length + at.y))
        }
    };
    if value <= 100.0 {
        canvas.point(shifted(scale_step * v), incoming);
        return Pen::Continue;
    }
    if value < 200.0 {
        let length = real((v - 100.0) * scale_step);
        let length = if end == End::Finish { -length } else { length };
        let spread = real(length * f64::from(0.375_f32));
        let barbs = if across {
            let y = real(length + at.y);
            [Pos::new(real(at.x - spread), y), Pos::new(real(spread + at.x), y)]
        } else {
            let x = real(length + at.x);
            [Pos::new(x, real(spread + at.y)), Pos::new(x, real(at.y - spread))]
        };
        canvas.stroke([barbs[0], at, barbs[1]]);
        return incoming;
    }
    let length = scale_step * real(v - 200.0);
    if across {
        canvas.stroke([Pos::new(real(at.x - length), at.y), Pos::new(real(length + at.x), at.y)]);
        incoming
    } else {
        canvas.point(Pos::new(at.x, real(at.y - length)), Pen::Stroke);
        Pen::Continue
    }
}

/// Distance between the copies thicken adds.
const THICKEN_STEP: i32 = 14;

/// thicken 0x42A8AE: n = 100·h + v. On screen, 2h copies of the points
/// from `start` moved up and down by 14, 28, … units, then 2v copies of the
/// same points moved right and left. n <= 0 turns filled objects into
/// polylines.
fn thicken(canvas: &mut Canvas<'_>, start: usize, n: i32) {
    let buffer = canvas.buffer_mut();
    if n <= 0 {
        buffer[start..]
            .iter_mut()
            .filter(|p| matches!(p.pen, Pen::Fill | Pen::SubPath))
            .for_each(|p| p.pen = Pen::Stroke);
        return;
    }
    let original = buffer[start..].to_vec();
    let moved = |dx: i32, dy: i32| {
        original.iter().map(move |p| BufferPoint { at: Point::new(p.at.x + dx, p.at.y + dy), pen: p.pen })
    };
    let vertical: Vec<BufferPoint> = copy_offsets(2 * (n / 100)).flat_map(|d| moved(0, d)).collect();
    let horizontal: Vec<BufferPoint> = copy_offsets(2 * (n % 100)).flat_map(|d| moved(d, 0)).collect();
    buffer.extend(vertical);
    buffer.extend(horizontal);
}

/// 14, -14, 28, -28, … (`count` of them).
fn copy_offsets(count: i32) -> impl Iterator<Item = i32> {
    (0..count).map(|i| THICKEN_STEP * (i / 2 + 1) * if i % 2 == 0 { 1 } else { -1 })
}

/// The engine's do-while loops never stop when the step does not advance;
/// this bounds them.
const MAX_REPEATS: usize = 100_000;

/// `first`, then `next` of each value while `more` holds for the new one:
/// the engine tests after each repetition, so the first always counts.
fn repeated(first: f64, next: impl Fn(f64) -> f64, more: impl Fn(f64) -> bool) -> Vec<f64> {
    let rest = successors(Some(next(first)), |&x| Some(next(x))).take_while(|&x| more(x));
    once(first).chain(rest).take(MAX_REPEATS).collect()
}

/// The dash and space lengths of P8 and P9 (scale steps; P9 = 0: as long as the dash).
fn dash_lengths(p: &Params, scale_step: f64) -> (f64, f64) {
    let p8 = if p.p(8) <= 0.0 { 1.0 } else { f64::from(p.p(8)) };
    let dash = real(scale_step * p8);
    let space = real(scale_step * f64::from(p.p(9)));
    (dash, if space <= 0.0 { dash } else { space })
}

/// Dashes along y = `from.y` from `from.x` until `until` (0x439598); the
/// last dash may pass it. Returns the x after the last space.
fn dash_row(canvas: &mut Canvas<'_>, from: Pos, until: f64, dash: f64, space: f64) -> f64 {
    let next = |x: f64| real(space + real(dash + x));
    let starts = repeated(from.x, next, |x| x < until);
    starts.iter().for_each(|&x| canvas.segment(Pos::new(x, from.y), Pos::new(real(dash + x), from.y)));
    next(*starts.last().expect("a dash row has a first dash"))
}

/// Moves each point after the first up by `slope` times its distance in x
/// from the first, as 0x439598 and draw_line tilt rows of dashes.
fn shear(points: &mut [BufferPoint], slope: f64) {
    let Some((first, rest)) = points.split_first_mut() else { return };
    let x0 = first.at.x;
    rest.iter_mut().for_each(|p| p.at.y = trunc(f64::from(p.at.y) + f64::from(p.at.x - x0) * slope));
}

fn dashes(line: &Line<'_>, right_y: f64, canvas: &mut Canvas<'_>) {
    let p = &line.p;
    let scale_step = line.scale_step();
    if p.p(6) == 0.0 || p.p(6) == p.p(3) {
        vertical_dashes(line, right_y, scale_step, canvas);
        return;
    }
    let (dash, space) = dash_lengths(p, scale_step);
    let end = dash_row(canvas, line.left, line.right_x, dash, space);
    let last_dash_end = real(end - space);
    if p.p(12) != 0.0 {
        end_mark(canvas, Pos::new(last_dash_end, line.left.y), p.p(12), End::Finish, false, scale_step);
    }
    if line.thickness != 0 {
        thicken(canvas, line.start, line.thickness * 100);
    }
    if p.p(13) != 0.0 {
        line.rotate(canvas, p.p(13));
    } else if line.ip5 != line.ip4 {
        let slope = real((right_y - line.left.y) / (end - space - line.left.x));
        shear(&mut canvas.buffer_mut()[line.start..], slope);
    }
}

/// P6 = 0 or P6 = P3: as many whole dash periods as fit between P4 and P5,
/// with dash and space stretched so that dashes start and end the line.
fn vertical_dashes(line: &Line<'_>, top: f64, scale_step: f64, canvas: &mut Canvas<'_>) {
    let (dash, space) = dash_lengths(&line.p, scale_step);
    let height = real(top - line.left.y);
    let periods = trunc(real(height / real(space + dash)));
    if periods <= 0 {
        return;
    }
    let n = f64::from(periods);
    let ratio = real((n + 1.0) * dash / space);
    let dashes_total = real(ratio * height / (n + ratio));
    let dash = real(dashes_total / (n + 1.0));
    let space = real((height - dashes_total) / n);
    let x = line.left.x;
    let next = |y: f64| real(space + real(dash + y));
    repeated(line.left.y, next, |y| y < top)
        .into_iter()
        .for_each(|y| canvas.segment(Pos::new(x, y), Pos::new(x, real(dash + y))));
    if line.thickness != 0 {
        thicken(canvas, line.start, line.thickness);
    }
}

/// Library units of the dot outline (0x78F6DC, 0x78F6AC), after a first
/// point 55.3 above the centre.
const DOT_OUTLINE: [(f32, f32); 12] = [
    (0.0, 101.2),
    (19.8, 136.67),
    (55.3, 156.5),
    (101.2, 156.5),
    (136.67, 136.67),
    (156.5, 101.2),
    (156.5, 55.3),
    (136.67, 19.8),
    (101.2, 0.0),
    (55.3, 0.0),
    (19.8, 19.8),
    (0.0, 55.3),
];

/// dot 0x43C415: a filled 13-point dot of size `r` at `at`.
fn dot(canvas: &mut Canvas<'_>, at: Pos, r: f64) {
    canvas.point(Pos::new(at.x, real(r * f64::from(55.3_f32) + at.y)), Pen::Fill);
    DOT_OUTLINE.iter().for_each(|&(dx, dy)| {
        canvas.point(Pos::new(real(f64::from(dx) * r + at.x), real(f64::from(dy) * r + at.y)), Pen::Continue);
    });
}

/// P7 = -4: dots of size P8/2 every P9 scale steps (default 2) from P3 to P6.
fn dots(line: &Line<'_>, canvas: &mut Canvas<'_>) {
    let p = &line.p;
    let size = real(if p.p(8) <= 0.0 { 0.5 } else { f64::from(p.p(8)) / 2.0 });
    let spacing = real(line.scale_step() * if p.p(9) == 0.0 { 2.0 } else { f64::from(p.p(9)) });
    let y = line.left.y;
    repeated(line.left.x, |x| real(spacing + x), |x| x <= line.right_x)
        .into_iter()
        .for_each(|x| dot(canvas, Pos::new(x, y), size));
    line.rotate(canvas, p.p(13));
}

/// One wave unit in library units (0x78F5B4, 0x78F4BC), indexed from 1 as
/// in the engine: 1..=9 the thin wave (2..=9 after the first unit, 10 its
/// end, 10..=14 its end with an arrow), 15..=49 the heavy wave, 50..=62 the
/// heavy wave's arrow.
const WAVE: [(f32, f32); 62] = [
    (-9.125, 0.0),
    (0.0, 0.0),
    (16.59, 9.678),
    (33.181, 29.034),
    (49.772, 38.712),
    (66.363, 38.712),
    (82.954, 29.034),
    (99.544, 9.678),
    (116.136, 0.0),
    (151.261, 0.0),
    (261.261, 0.0),
    (151.261, 58.0),
    (261.261, 0.0),
    (151.261, -58.0),
    (13.0, 24.0),
    (7.0, 18.5),
    (-1.0, 26.0),
    (30.0, 57.0),
    (39.0, 64.0),
    (46.0, 67.0),
    (52.0, 68.0),
    (59.0, 68.0),
    (65.0, 67.0),
    (74.0, 63.0),
    (87.0, 54.0),
    (116.0, 29.0),
    (125.0, 22.0),
    (127.0, 21.0),
    (131.0, 20.0),
    (134.0, 20.0),
    (138.0, 21.0),
    (143.0, 25.0),
    (148.0, 30.0),
    (156.0, 22.0),
    (124.0, -10.0),
    (117.0, -16.0),
    (110.0, -19.0),
    (104.0, -20.0),
    (97.0, -20.0),
    (90.0, -19.0),
    (83.0, -16.0),
    (72.0, -8.0),
    (40.0, 21.0),
    (32.0, 27.0),
    (27.0, 29.0),
    (23.0, 29.0),
    (19.0, 28.0),
    (17.0, 27.0),
    (13.0, 24.0),
    (148.0, 29.0),
    (152.0, 32.0),
    (154.0, 33.0),
    (159.0, 34.0),
    (201.0, 34.0),
    (148.0, 106.0),
    (268.0, 29.0),
    (148.0, -47.0),
    (201.0, 25.0),
    (163.0, 25.0),
    (158.0, 24.0),
    (155.0, 22.0),
    (148.0, 29.0),
];

/// Wave table entries `first..=last` scaled by `size` and placed at `at`.
fn wave_points(size: Pos, at: Pos, first: usize, last: usize) -> impl Iterator<Item = Pos> {
    WAVE[first - 1..last].iter().map(move |&(x, y)| {
        Pos::new(real(size.x * f64::from(x) + at.x), real(size.y * f64::from(y) + at.y))
    })
}

/// P7 = -1, -2, -3 and other negative types: wavy lines from P3 to P6, or
/// from P4 up to P5 when P6 = 0 or P6 = P3.
fn wavy(line: &mut Line<'_>, canvas: &mut Canvas<'_>) {
    let p = line.p.clone();
    let p8 = if p.p(8) <= 0.0 { 1.0 } else { f64::from(p.p(8)) };
    let p9 = if p.p(9) == 0.0 { p8 } else { f64::from(p.p(9)) };
    let unit = real(line.step() * f64::from(0.0825_f32));
    let size = Pos::new(real(unit * p8), real(unit * p9));
    let heavy = line.ip7 == HEAVY_WAVE;
    let arrow = p.ip(12) != 0;
    let mut rotation = p.p(13);
    if p.p(6) == 0.0 || p.p(6) == p.p(3) {
        rotation = upright(line, heavy);
    }
    if line.right_x <= line.left.x {
        return;
    }
    match line.ip7 {
        HEAVY_WAVE => heavy_wave(line, size, arrow, canvas),
        SAWTOOTH => sawtooth(line, size, canvas),
        _ => thin_wave(line, size, arrow, canvas),
    }
    if !heavy && line.thickness != 0 {
        thicken(canvas, line.start, line.thickness * 100);
    }
    line.rotate(canvas, rotation);
}

/// Sets up a vertical wavy line as a horizontal one turned by the returned
/// angle: upward from P4 to P5 (+ P15), or downward from two steps above P5
/// when P12 < 0 puts the arrow at the bottom.
fn upright(line: &mut Line<'_>, heavy: bool) -> f32 {
    let step = line.step();
    line.left.x = line.offset_by_p15(line.left.x);
    if heavy {
        line.left.y = real(line.left.y - step * f64::from(0.8_f32));
    }
    let mut levels = real(f64::from(line.p.p(5)) - f64::from(line.p.p(4)));
    if line.p.ip(12) < 0 {
        levels = -levels;
        line.left.y = real(line.staff.y(f64::from(line.p.p(5))) + step * 14.0);
    }
    let length = real(levels * UNITS_PER_SCALE_STEP * step);
    let (rotation, length) = if length <= 0.0 { (90.0, -length) } else { (-90.0, length) };
    line.right_x = real(line.left.x + length);
    rotation
}

/// P7 = -1 on screen: one filled unit every 146 table units, each its own object.
fn heavy_wave(line: &Line<'_>, size: Pos, arrow: bool, canvas: &mut Canvas<'_>) {
    let advance = real(size.x * 146.0);
    let next = |x: f64| real(advance + x);
    let y = line.left.y;
    let unit = |canvas: &mut Canvas<'_>, x: f64, first: usize, last: usize| {
        canvas.fill([wave_points(size, Pos::new(x, y), first, last)]);
    };
    let units = repeated(line.left.x, next, |x| x < line.right_x);
    units.iter().for_each(|&x| unit(canvas, x, 15, 49));
    if arrow {
        let end = next(*units.last().expect("a wave has a first unit"));
        repeated(real(end - advance), next, |x| x < 0.0).into_iter().for_each(|x| unit(canvas, x, 50, 62));
    }
}

/// P7 = -2: one polyline of units 146 table units apart; the last unit ends
/// the line (with an arrow head for P12).
fn thin_wave(line: &Line<'_>, size: Pos, arrow: bool, canvas: &mut Canvas<'_>) {
    let advance = real(size.x * 160.0 * f64::from(0.9125_f32));
    let y = line.left.y;
    let until = line.right_x;
    let units = repeated(line.left.x, |x| real(advance + x), |x| x < until);
    let end = if arrow { 14 } else { 10 };
    let points: Vec<Pos> = units
        .iter()
        .enumerate()
        .flat_map(|(i, &x)| {
            let first = if i == 0 { 1 } else { 2 };
            let last = if i > 0 && advance + x >= until { end } else { 9 };
            wave_points(size, Pos::new(x, y), first, last)
        })
        .collect();
    canvas.stroke(points);
}

/// P7 = -3: a sawtooth with teeth 72 × 84 table units; P11 fills each down
/// slope as a band P11 × 50 steps wide.
fn sawtooth(line: &Line<'_>, size: Pos, canvas: &mut Canvas<'_>) {
    let p11 = line.p.p(11);
    let band = (p11 != 0.0).then(|| {
        let width = real(f64::from(p11) * 50.0 * real(line.step() / 25.0));
        let angle = real((size.y / size.x).atan());
        let dx = real(width / angle.sin());
        Pos::new(dx, real(angle.tan() * dx * 7.0 / 6.0))
    });
    let tooth = Pos::new(real(size.x * 72.0), real(size.y * 84.0));
    let (y0, until) = (line.left.y, line.right_x);
    let top = real(tooth.y + y0);
    let corners = successors(Some(line.left.x), |&x| (x < until).then(|| real(tooth.x + x))).take(MAX_REPEATS);
    corners.enumerate().for_each(|(i, x)| match (i, band) {
        (0, _) => canvas.point(Pos::new(x, y0), Pen::Stroke),
        (i, _) if i % 2 == 1 => canvas.point(Pos::new(x, top), Pen::Continue),
        (_, None) => canvas.point(Pos::new(x, y0), Pen::Continue),
        (_, Some(band)) => {
            let inner = real(x - band.x);
            canvas.fill([[
                Pos::new(x, y0),
                Pos::new(inner, real(y0 - band.y)),
                Pos::new(real(inner - tooth.x), real(top - band.y)),
                Pos::new(real(x - tooth.x), top),
                Pos::new(x, y0),
            ]]);
            canvas.point(Pos::new(x, y0), Pen::Stroke);
        }
    });
}

/// P7 = 100: a polyline from P3/P4 through up to five points P8/P9 …
/// P16/P17 to P6/P5, the inner points scaled about P3/P4 by P18 and P19.
fn multipoint(line: &Line<'_>, right: Pos, canvas: &mut Canvas<'_>) {
    let p = &line.p;
    let fx = if p.p(18) == 0.0 { 1.0 } else { f64::from(p.p(18)) };
    let fy = if p.p(19) == 0.0 { fx } else { f64::from(p.p(19)) };
    let (p3, p4) = (f64::from(p.p(3)), f64::from(p.p(4)));
    let inner = (8..=16).step_by(2).map(|k| (p.p(k), p.p(k + 1))).take_while(|&(x, _)| x != 0.0).map(|(x, y)| {
        let x = real(((f64::from(x) - p3) * fx + p3) * P3_UNIT);
        Pos::new(x, line.staff.y(real((f64::from(y) - p4) * fy + p4)))
    });
    let points: Vec<Pos> = once(line.left).chain(inner).chain(once(right)).collect();
    canvas.stroke(points);
    if p.p(21) != 0.0 {
        thicken(canvas, line.start, p.ip(21));
    }
    line.rotate(canvas, p.p(20));
}

/// P5 = 999: a hairpin from P3 to P6 around P4, opening to the right for
/// P7 >= 0 (0 = default spread 2.3 scale steps; -1 = -2.3).
fn hairpin(line: &mut Line<'_>, canvas: &mut Canvas<'_>) {
    let p7 = match line.p.p(7) {
        0.0 => 2.3_f32,
        -1.0 => -2.3_f32,
        v => v,
    };
    let half = real(f64::from(p7.abs()) * line.step() * 3.5);
    let (apex, open) = if p7 > 0.0 { (line.left.x, line.right_x) } else { (line.right_x, line.left.x) };
    if line.p.p(11) == 1.0 {
        dashed_hairpin(line, canvas);
        line.p.set(9, 0.0);
        line.start = 0;
    } else {
        let wedge = Wedge { apex, open, half, y: line.left.y };
        match (line.p.p(14), line.p.p(15)) {
            (0.0, 0.0) => wedge.draw(canvas),
            (p14, p15) => wedge.partial(f64::from(p14), f64::from(p15), p7 < 0.0, canvas),
        }
    }
    if line.thickness != 0 {
        thicken(canvas, line.start, line.thickness * 100);
    }
    line.rotate(canvas, line.rotation());
}

#[derive(Debug, Clone, Copy, PartialEq)]
struct Wedge {
    apex: f64,
    open: f64,
    /// Half the spread at the open end.
    half: f64,
    y: f64,
}

impl Wedge {
    fn draw(&self, canvas: &mut Canvas<'_>) {
        canvas.stroke([
            Pos::new(self.open, real(self.half + self.y)),
            Pos::new(self.apex, self.y),
            Pos::new(self.open, real(self.y - self.half)),
        ]);
    }

    /// P14/P15 with the new slur features (int 0x78B4B8 = 1): each, when
    /// set, cuts the hairpin at that fraction of its length from the open
    /// end (decrescendo) or from the apex (crescendo); with both, the legs
    /// are drawn between the two cuts.
    fn partial(self, p14: f64, p15: f64, decrescendo: bool, canvas: &mut Canvas<'_>) {
        let span = self.apex - self.open;
        let cut = |fraction: f64| (fraction != 0.0).then(|| (real(span * fraction), real(fraction * self.half)));
        let (cut14, cut15) = (cut(p14), cut(p15));
        let legs = if decrescendo {
            match (cut14, cut15) {
                (Some((dx, dh)), None) => {
                    return Wedge { open: real(dx + self.open), half: real(self.half - dh), ..self }.draw(canvas);
                }
                (inner, Some((dx15, dh15))) => {
                    let start = Pos::new(real(dx15 + self.open), real(self.half + self.y - dh15));
                    let (far_x, far_half) = match inner {
                        None => (self.open, self.half),
                        Some((dx, dh)) => (real(dx + self.open), real(self.half - dh)),
                    };
                    Legs { start, far_x, far_half, near_x: real(dx15 + self.open), near_half: real(self.half - dh15) }
                }
                (None, None) => return self.draw(canvas),
            }
        } else {
            match (cut14, cut15) {
                (None, Some((dx, dh))) => {
                    return Wedge { open: real(self.apex - dx), half: dh, ..self }.draw(canvas);
                }
                (Some((dx14, dh14)), outer) => {
                    let start = Pos::new(real(self.apex - dx14), real(dh14 + self.y));
                    let (far_x, far_half) = match outer {
                        None => (self.open, self.half),
                        Some((dx, dh)) => (real(self.apex - dx), dh),
                    };
                    Legs { start, far_x, far_half, near_x: real(self.apex - dx14), near_half: dh14 }
                }
                (None, None) => return self.draw(canvas),
            }
        };
        legs.draw(self.y, canvas);
    }
}

/// The two separate legs of a partial hairpin (draw_line 0x43A085): the
/// upper from `start` to the far end, the lower from the near to the far end.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Legs {
    start: Pos,
    far_x: f64,
    far_half: f64,
    near_x: f64,
    near_half: f64,
}

impl Legs {
    fn draw(&self, y: f64, canvas: &mut Canvas<'_>) {
        canvas.stroke([self.start, Pos::new(self.far_x, real(self.far_half + y))]);
        canvas.stroke([Pos::new(self.near_x, real(y - self.near_half)), Pos::new(self.far_x, real(y - self.far_half))]);
    }
}

/// P11 = 1 (0x439598): two rows of dashes from P3 to P6, tilted from P4 to
/// P4 ∓ P7/2 (default 1.1 scale steps). For a decrescendo the y values of
/// all points are reversed, which mirrors the dashes only approximately.
fn dashed_hairpin(line: &Line<'_>, canvas: &mut Canvas<'_>) {
    let p = &line.p;
    let scale_step = line.scale_step();
    let (dash, space) = dash_lengths(p, scale_step);
    let p7 = p.p(7);
    let spread = if p7 != 0.0 && p7 != -1.0 { real(f64::from(p7.abs()) / 2.0) } else { f64::from(1.1_f32) };
    [spread, -spread].into_iter().for_each(|spread| {
        let first = canvas.buffer_mut().len();
        let end = dash_row(canvas, line.left, line.right_x, dash, space);
        let level = real(f64::from(p.p(4)) - spread);
        let slope = real((line.staff.y(level) - line.left.y) / (end - space - line.left.x));
        shear(&mut canvas.buffer_mut()[first..], slope);
    });
    if p7 < 0.0 {
        let buffer = canvas.buffer_mut();
        let ys: Vec<i32> = buffer.iter().rev().map(|p| p.at.y).collect();
        buffer.iter_mut().zip(ys).for_each(|(p, y)| p.at.y = y);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn copies_alternate_outward() {
        assert_eq!(copy_offsets(5).collect::<Vec<_>>(), vec![14, -14, 28, -28, 42]);
        assert_eq!(copy_offsets(0).count(), 0);
    }

    #[test]
    fn repeated_counts_the_first_and_tests_after() {
        assert_eq!(repeated(0.0, |x| x + 3.0, |x| x < 10.0), vec![0.0, 3.0, 6.0, 9.0]);
        assert_eq!(repeated(20.0, |x| x + 3.0, |x| x < 10.0), vec![20.0]);
    }
}
