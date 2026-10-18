//! Geometry the engine applies to buffered points, shared by several codes,
//! and the pen widths of SCORE's print output that the refined style draws.

use crate::canvas::{BufferPoint, Pen};
use crate::display::{print_pen, Point, UNITS_PER_INCH};
use crate::units::{real, trunc, Pos};

/// One pixel of SCORE's print output in engine units, as the refined style
/// reads SCORE's print widths: at 600 dpi, where a print-width marker
/// counts pixels and the default pen ([`crate::PEN`]) is four
/// of them, so that `d` pixels more than the default is `print_pen(d)`.
/// The engine's own pixel follows the printer's resolution.
pub const PRINT_PIXEL: f64 = UNITS_PER_INCH as f64 / 600.0;

/// The thinnest pen, for outlines SCORE's print output leaves out (filled
/// arcs) or narrows to nothing: the one unit the engine draws everything
/// with, which outputs widen to a device pixel. (Width 0 is the default pen.)
pub const HAIRLINE: f32 = 1.0;

/// [`print_pen`]`(pixels)` as a width for [`crate::canvas::Canvas::set_width`]:
/// a pen narrowed to nothing is a [`HAIRLINE`], not the default pen.
pub fn print_width(pixels: f32) -> f32 {
    match print_pen(pixels) {
        w if w > 0.0 => w,
        _ => HAIRLINE,
    }
}

/// Degrees per radian as the engine's REAL*4 constant.
const DEGREES_PER_RADIAN: f32 = 57.295_776;

/// Turns buffered points clockwise by `degrees`
/// about `centre`. The angle, its sine and cosine are REAL*4; each point is
/// truncated again after the turn. Called by draw_symbol, boxes, lines,
/// slurs, EPS and text with the points added since a given buffer index.
pub fn rotate_points(points: &mut [BufferPoint], centre: Point, degrees: f32) {
    turn(points, centre, real(f64::from(degrees) / f64::from(DEGREES_PER_RADIAN)));
}

/// One point turned clockwise by `degrees` about `centre`, unrounded: where
/// [`rotate_points`] puts it, for code that asks where a part of an item lies.
pub fn turned(p: Pos, centre: Pos, degrees: f64) -> Pos {
    let (sin, cos) = degrees.to_radians().sin_cos();
    let (dx, dy) = (p.x - centre.x, p.y - centre.y);
    Pos::new(cos * dx + sin * dy + centre.x, cos * dy - sin * dx + centre.y)
}

/// The engine's rotation called with a start index of 0 or below (as
/// draw_slur does): the angle is taken in radians and negated, so the points
/// turn counter-clockwise by `radians`.
pub fn rotate_points_radians(points: &mut [BufferPoint], centre: Point, radians: f32) {
    turn(points, centre, f64::from(-radians));
}

/// The turn itself: clockwise by `angle` radians, a REAL*4 value.
fn turn(points: &mut [BufferPoint], centre: Point, angle: f64) {
    let (sin, cos) = (real(angle.sin()), real(angle.cos()));
    let (cx, cy) = (f64::from(centre.x), f64::from(centre.y));
    points.iter_mut().for_each(|p| {
        let dx = f64::from(p.at.x) - cx;
        let dy = f64::from(p.at.y) - cy;
        p.at = Point::new(trunc(cos * dx + sin * dy + cx), trunc(cos * dy - sin * dx + cy));
    });
}

/// A centripetal Catmull–Rom spline through `points`, `steps` segments
/// from each point to the next, for the refined style's smoother outlines.
/// `before` and `after` are the neighbours that set the tangent at the
/// first and last point; without one that end runs straight to its
/// neighbour (the end point mirrored).
pub fn spline_through(before: Option<Pos>, points: &[Pos], after: Option<Pos>, steps: usize) -> Vec<Pos> {
    let [first, .., last] = points else {
        return points.to_vec();
    };
    let mirrored = |end: Pos, next: Pos| Pos::new(2.0 * end.x - next.x, 2.0 * end.y - next.y);
    let before = before.unwrap_or_else(|| mirrored(*first, points[1]));
    let after = after.unwrap_or_else(|| mirrored(*last, points[points.len() - 2]));
    let controls: Vec<Pos> = std::iter::once(before).chain(points.iter().copied()).chain([after]).collect();
    let steps = steps.max(1);
    let mut out = vec![*first];
    controls.windows(4).for_each(|w| {
        // Knots spaced by the square root of the chord lengths (alpha = 1/2).
        let knot = |a: Pos, b: Pos| (a.x - b.x).hypot(a.y - b.y).sqrt().max(1e-9);
        let t1 = knot(w[0], w[1]);
        let t2 = t1 + knot(w[1], w[2]);
        let t3 = t2 + knot(w[2], w[3]);
        let lerp = |a: Pos, b: Pos, ta: f64, tb: f64, t: f64| {
            let (u, v) = ((tb - t) / (tb - ta), (t - ta) / (tb - ta));
            Pos::new(u * a.x + v * b.x, u * a.y + v * b.y)
        };
        (1..=steps).for_each(|k| {
            let t = t1 + (t2 - t1) * k as f64 / steps as f64;
            let a1 = lerp(w[0], w[1], 0.0, t1, t);
            let a2 = lerp(w[1], w[2], t1, t2, t);
            let a3 = lerp(w[2], w[3], t2, t3, t);
            let b1 = lerp(a1, a2, 0.0, t2, t);
            let b2 = lerp(a2, a3, t1, t3, t);
            out.push(lerp(b1, b2, t1, t2, t));
        });
    });
    out
}

/// The engine's thickening with n <= 0, as P8 < 0 asks of a symbol: its filled
/// objects become polylines, so only their outlines are drawn. (A positive
/// n copies the points 14, 28, … units apart; the port draws such a
/// symbol once with a wider pen instead.)
pub fn outline_only(points: &mut [BufferPoint]) {
    points
        .iter_mut()
        .filter(|p| matches!(p.pen, Pen::Fill | Pen::SubPath))
        .for_each(|p| p.pen = Pen::Stroke);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn outlines_replace_fills() {
        let mut points = [
            BufferPoint { at: Point::new(0, 0), pen: Pen::Fill },
            BufferPoint { at: Point::new(1, 0), pen: Pen::SubPath },
        ];
        outline_only(&mut points);
        assert!(points.iter().all(|p| p.pen == Pen::Stroke));
    }

    /// The REAL*4 angle lies just past π/2, so the cosine is -4.4e-8 and
    /// truncation moves x from 100 to 99, as in the engine.
    #[test]
    fn radians_turn_counter_clockwise() {
        let mut points = [BufferPoint { at: Point::new(110, 100), pen: Pen::Stroke }];
        rotate_points_radians(&mut points, Point::new(100, 100), std::f32::consts::FRAC_PI_2);
        assert_eq!(points[0].at, Point::new(99, 110));
    }

    #[test]
    fn quarter_turn_is_clockwise() {
        let mut points = [BufferPoint { at: Point::new(110, 100), pen: Pen::Stroke }];
        rotate_points(&mut points, Point::new(100, 100), 90.0);
        assert_eq!(points[0].at, Point::new(99, 90));
    }

    #[test]
    fn splines_pass_through_their_points() {
        let points = [Pos::new(0.0, 0.0), Pos::new(100.0, 40.0), Pos::new(200.0, 0.0)];
        let spline = spline_through(None, &points, None, 4);
        assert_eq!(spline.len(), 9);
        assert_eq!((spline[0], spline[4], spline[8]), (points[0], points[1], points[2]));
        // Between the points the curve bulges past the polygon's chords.
        assert!(spline[2].y > 20.0 && spline[6].y > 20.0, "{spline:?}");
    }

    #[test]
    fn a_turned_point_lands_where_rotate_points_puts_it() {
        let p = turned(Pos::new(110.0, 100.0), Pos::new(100.0, 100.0), 90.0);
        assert!((p.x - 100.0).abs() < 1e-9 && (p.y - 90.0).abs() < 1e-9, "{p:?}");
    }
}
