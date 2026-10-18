//! Code 4: lines, dashes, dots, wavy lines, hairpins and multipoint lines.
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
//! The engine's screen branches are ported (OUTPUT_MODE 1), with the line
//! widths of SCORE's print output on every medium: the engine's screen
//! thickens lines by drawing copies 14 units apart instead.

use std::iter::{once, successors};

use crate::canvas::{BufferPoint, Canvas, Pen};
use crate::document::{Document, ItemRef};
use crate::geometry::{print_width, rotate_points};
use crate::page::P3_UNIT;
use crate::staff::{Staff, UNITS_PER_SCALE_STEP};
use crate::units::{constant, real, trunc, Pos};

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

    /// IP(n) = INT(P(n)), as draw_item prepares it.
    fn ip(&self, n: usize) -> i32 {
        trunc(f64::from(self.p(n)))
    }
}

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    draw(&Params::of(item), doc.position(item), &doc.staff_of(item), canvas);
}

/// Where the parts of a code-4 item lie before its rotation (internal
/// coordinates), for an editor's handles on them.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Shape {
    pub left: Pos,
    pub right: Pos,
    /// Whether the right end's level is P5; dotted and wavy lines and
    /// hairpins stay at the level of P4.
    pub right_level: bool,
    /// Half the spread at a hairpin's open end, and whether it opens to the right.
    pub hairpin: Option<(f64, bool)>,
    /// Degrees clockwise about the left end.
    pub rotation: f32,
}

/// The [`Shape`] of a code-4 item; `None` for vertical, upward wavy and
/// multipoint lines, whose ends are not P3/P4 and P6/P5.
pub fn shape(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Shape> {
    let staff = doc.staff_of(item);
    let line = Line::new(&Params::of(item), doc.position(item), &staff, staff.step, 0);
    let p = &line.p;
    let flat = |right_level: bool, rotation: f32| {
        let right = Pos::new(line.right_x, if right_level { staff.y(f64::from(p.p(5))) } else { line.left.y });
        Some(Shape { left: line.left, right, right_level, hairpin: None, rotation })
    };
    if line.ip5 >= HAIRPIN {
        let p7 = match p.p(7) {
            0.0 => 2.3_f32,
            -1.0 => -2.3_f32,
            v => v,
        };
        let half = real(f64::from(p7.abs()) * line.step() * 3.5);
        return Some(Shape { hairpin: Some((half, p7 > 0.0)), ..flat(false, line.rotation())? });
    }
    let upward = p.p(6) == 0.0 || p.p(6) == p.p(3);
    match line.ip7 {
        0 => flat(true, line.rotation()),
        QUICK_VERTICAL => None,
        k if k >= MULTIPOINT => None,
        _ if upward => None,
        k if k > 0 => flat(p.p(13) == 0.0, p.p(13)),
        _ => flat(false, p.p(13)),
    }
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
    draw_with_step(params, origin, staff, staff.step, canvas);
}

/// [`draw`] with the engine's STEP set to `step` (callers that scale it,
/// e.g. for small notes); levels still come from the staff table.
pub fn draw_with_step(params: &Params, origin: Pos, staff: &Staff, step: f64, canvas: &mut Canvas<'_>) {
    let mut line = Line::new(params, origin, staff, step, canvas.buffer_mut().len());
    let width = line.print_width();
    if let Some(width) = width {
        canvas.set_width(width);
    }
    if line.ip5 >= HAIRPIN {
        hairpin(&mut line, canvas);
    } else {
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
    if width.is_some() {
        canvas.set_width(0.0);
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
    /// STEP: 25 × size, one scale step is 7 of them.
    step: f64,
    left: Pos,
    right_x: f64,
    thickness: i32,
    /// The buffer index of the line's first point (NPT0).
    start: usize,
}

impl<'a> Line<'a> {
    fn new(params: &Params, origin: Pos, staff: &'a Staff, step: f64, start: usize) -> Self {
        let mut p = params.clone();
        let mut thickness = params.ip(10);
        if p.p(5) == 0.0 && p.p(6) == 0.0 {
            // The engine also reports "*** Code 4 needs value in P5 or P6 ***".
            p.set(6, real(f64::from(p.p(3)) + 20.0) as f32);
            thickness = 4;
        }
        let mut x = origin.x;
        if p.p(16) == 1.0 {
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
            step,
            left: Pos::new(x, origin.y),
            thickness,
            start,
        }
    }

    /// The pen SCORE's print output draws the line with: draw_line passes
    /// 2·IP10 to the print-width marker below IP7 = 100, IP21 for multipoint
    /// lines, and -1 for heavy waves (which print also sets directly);
    /// `None` is the default pen.
    fn print_width(&self) -> Option<f32> {
        let pixels = match self.ip7 {
            k if k >= MULTIPOINT => self.p.ip(21),
            HEAVY_WAVE if self.ip5 < HAIRPIN => -1,
            _ => 2 * self.thickness,
        };
        (pixels != 0).then(|| print_width(pixels as f32))
    }

    fn step(&self) -> f64 {
        self.step
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
    line.rotate(canvas, line.rotation());
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) enum End {
    Start,
    Finish,
}

/// What P11 (at the start) or P12 (at the finish) adds.
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
        let spread = real(length * constant(0.375));
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

/// Dashes along y = `from.y` from `from.x` until `until` as the engine
/// draws them: the last dash may pass it. Returns the x after the
/// last space.
fn dash_row(canvas: &mut Canvas<'_>, from: Pos, until: f64, dash: f64, space: f64) -> f64 {
    let next = |x: f64| real(space + real(dash + x));
    let starts = repeated(from.x, next, |x| x < until);
    starts.iter().for_each(|&x| canvas.segment(Pos::new(x, from.y), Pos::new(real(dash + x), from.y)));
    next(*starts.last().expect("a dash row has a first dash"))
}

/// Moves each point after the first up by `slope` times its distance in x
/// from the first, as the engine's dash routine and draw_line tilt rows of dashes.
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
    let last_dash_end = fitted_dash_row(canvas, line.left, line.right_x, dash, space);
    let run = last_dash_end - line.left.x;
    if p.p(12) != 0.0 {
        end_mark(canvas, Pos::new(last_dash_end, line.left.y), p.p(12), End::Finish, false, scale_step);
    }
    if p.p(13) != 0.0 {
        line.rotate(canvas, p.p(13));
    } else if line.ip5 != line.ip4 {
        let slope = real((right_y - line.left.y) / run);
        shear(&mut canvas.buffer_mut()[line.start..], slope);
    }
}

/// Dashes along y = `from.y` that fill `from.x` to `until` exactly,
/// starting and ending with a dash, with as many dashes as come closest to
/// the asked lengths, both scaled alike, where the engine's [`dash_row`]
/// lets the last dash pass `until`; that row stands in where there is no
/// length to fill. Returns the end of the last dash.
fn fitted_dash_row(canvas: &mut Canvas<'_>, from: Pos, until: f64, dash: f64, space: f64) -> f64 {
    let length = until - from.x;
    if length <= 0.0 || dash <= 0.0 || space <= 0.0 {
        return real(dash_row(canvas, from, until, dash, space) - space);
    }
    let spaces = ((length - dash) / (dash + space)).round().clamp(0.0, MAX_REPEATS as f64);
    let scale = length / (dash + spaces * (dash + space));
    let (dash, period) = (dash * scale, (dash + space) * scale);
    (0..=spaces as usize).for_each(|k| {
        let x = from.x + k as f64 * period;
        canvas.segment(Pos::new(x, from.y), Pos::new(x + dash, from.y));
    });
    until
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
}

/// Library units of the dot outline, after a first
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

/// A filled 13-point dot of size `r` at `at`.
fn dot(canvas: &mut Canvas<'_>, at: Pos, r: f64) {
    canvas.point(Pos::new(at.x, real(r * constant(55.3) + at.y)), Pen::Fill);
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

/// One wave unit in library units, indexed from 1 as
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
    let unit = real(line.step() * constant(0.0825));
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
    line.rotate(canvas, rotation);
}

/// Sets up a vertical wavy line as a horizontal one turned by the returned
/// angle: upward from P4 to P5 (+ P15), or downward from two steps above P5
/// when P12 < 0 puts the arrow at the bottom.
fn upright(line: &mut Line<'_>, heavy: bool) -> f32 {
    let step = line.step();
    line.left.x = line.offset_by_p15(line.left.x);
    if heavy {
        line.left.y = real(line.left.y - step * constant(0.8));
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
    let advance = real(size.x * 160.0 * constant(0.9125));
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

    /// P14/P15 with the new slur features: each, when
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

/// The two separate legs of a partial hairpin: the
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

/// P11 = 1: two rows of dashes from P3 to P6, tilted from P4 to
/// P4 ∓ P7/2 (default 1.1 scale steps). For a decrescendo the y values of
/// all points are reversed, which mirrors the dashes only approximately.
fn dashed_hairpin(line: &Line<'_>, canvas: &mut Canvas<'_>) {
    let p = &line.p;
    let scale_step = line.scale_step();
    let (dash, space) = dash_lengths(p, scale_step);
    let p7 = p.p(7);
    let spread = if p7 != 0.0 && p7 != -1.0 { real(f64::from(p7.abs()) / 2.0) } else { constant(1.1) };
    [spread, -spread].into_iter().for_each(|spread| {
        let first = canvas.buffer_mut().len();
        let run = fitted_dash_row(canvas, line.left, line.right_x, dash, space) - line.left.x;
        let level = real(f64::from(p.p(4)) - spread);
        let slope = real((line.staff.y(level) - line.left.y) / run);
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
    use score_format::{Item, MusFile, Word};

    use super::*;
    use crate::display::{print_pen, ItemId, Shape, ShapeKind};

    #[test]
    fn repeated_counts_the_first_and_tests_after() {
        assert_eq!(repeated(0.0, |x| x + 3.0, |x| x < 10.0), vec![0.0, 3.0, 6.0, 9.0]);
        assert_eq!(repeated(20.0, |x| x + 3.0, |x| x < 10.0), vec![20.0]);
    }

    /// The shapes of a code-4 `item` after a size-1 staff 1.
    fn shapes(item: &[f32]) -> Vec<Shape> {
        let trailer = [0.0_f32, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = (trailer.len() as u16).to_le_bytes().to_vec();
        bytes.extend(trailer.iter().flat_map(|w| w.to_le_bytes()));
        let mut file = MusFile::parse(&bytes).expect("an empty file parses");
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        file.items = vec![words(&[8.0, 1.0, 0.0, 0.0, 1.0]), words(item)];
        let list = crate::render(&Document::new(&file));
        list.shapes.into_iter().filter(|s| s.source == Some(ItemId(1))).collect()
    }

    #[test]
    fn a_thick_line_is_one_stroke_with_the_print_pen() {
        let line = shapes(&[4.0, 1.0, 10.0, 9.0, 9.0, 30.0, 0.0, 0.0, 0.0, 3.0]);
        assert_eq!(line.len(), 1);
        assert_eq!(line[0].width, print_pen(6.0));
        let path = &line[0].paths[0];
        assert_eq!((line[0].paths.len(), path.len()), (1, 2));
        assert_eq!((path[1].x - path[0].x, path[1].y - path[0].y), (3000, 0));
    }

    #[test]
    fn heavy_waves_and_multipoint_lines_take_their_print_widths() {
        let wave = shapes(&[4.0, 1.0, 10.0, 9.0, 9.0, 30.0, -1.0]);
        assert!(wave.iter().all(|s| s.kind == ShapeKind::Fill && s.width == print_pen(-1.0)));
        let multipoint = [4.0, 1.0, 10.0, 9.0, 9.0, 30.0, 100.0, 15.0, 12.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 2.0];
        let multipoint = shapes(&multipoint);
        assert_eq!(multipoint.len(), 1);
        assert_eq!(multipoint[0].width, print_pen(2.0));
    }

    #[test]
    fn dashes_end_on_a_dash_at_p6() {
        let dashes = shapes(&[4.0, 1.0, 10.0, 9.0, 9.0, 31.5, 1.0]);
        let first = dashes.first().expect("dashes").paths[0][0].x;
        let last = dashes.last().expect("dashes").paths[0][1].x;
        assert_eq!(last - first, 3225);
    }
}
