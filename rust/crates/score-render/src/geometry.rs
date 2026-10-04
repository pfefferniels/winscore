//! Geometry the engine applies to buffered points, shared by several codes.

use crate::canvas::{BufferPoint, Pen};
use crate::display::Point;
use crate::trig::CIRCLE;
use crate::units::{real, trunc, Pos};

/// Degrees per radian as the REAL*4 constant at 0x75FC6C.
const DEGREES_PER_RADIAN: f32 = 57.295_776;

/// rotate_points 0x42A5F4: turns buffered points clockwise by `degrees`
/// about `centre`. The angle, its sine and cosine are REAL*4; each point is
/// truncated again after the turn. Called by draw_symbol, boxes, lines,
/// slurs, EPS and text with the points added since a given buffer index.
pub fn rotate_points(points: &mut [BufferPoint], centre: Point, degrees: f32) {
    turn(points, centre, real(f64::from(degrees) / f64::from(DEGREES_PER_RADIAN)));
}

/// rotate_points 0x42A5F4 called with a start index of 0 or below (as
/// draw_slur does): the angle is taken in radians and negated, so the points
/// turn counter-clockwise by `radians` (0x42A62B).
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

/// The ellipse points of draw_box 0x433530 (IP5 = 1): for every angle,
/// clockwise in whole degrees from twelve o'clock, the point
/// (f32(rx·S + x), f32(ry·C + y)) with S, C from the engine's circle table
/// (about 100·sin, 100·cos), so `rx`, `ry` are in hundredths of the radius.
pub fn ellipse(centre: Pos, rx: f64, ry: f64, degrees: impl IntoIterator<Item = usize>) -> impl Iterator<Item = Pos> {
    degrees.into_iter().map(move |a| {
        let (s, c) = CIRCLE[a % CIRCLE.len()];
        Pos::new(real(rx * f64::from(s) + centre.x), real(ry * f64::from(c) + centre.y))
    })
}

/// Distance between the copies [`thicken`] adds.
const THICKEN_STEP: i32 = 14;

/// Points left of this x keep their place in horizontal copies (0x42AAFF).
const UNMOVED_X: i32 = -192_600;

/// thicken 0x42A8AE on the points from `start` on, with n = 100·v + h:
/// 2v copies moved up and down by 14, 28, … units, then 2h copies moved
/// right and left, each a copy of the original points. n <= 0 turns filled
/// objects into polylines instead. The engine doubles the counts and does
/// the outlining only while the flag at 0x78B6A4 is set, as it is on the
/// screen; callers guard the call where the engine does.
pub fn thicken(points: &mut Vec<BufferPoint>, start: usize, n: i32) {
    if n <= 0 {
        points[start..]
            .iter_mut()
            .filter(|p| matches!(p.pen, Pen::Fill | Pen::SubPath))
            .for_each(|p| p.pen = Pen::Stroke);
        return;
    }
    let original = points[start..].to_vec();
    let moved = |dx: i32, dy: i32| {
        original.iter().map(move |p| {
            let x = if p.at.x >= UNMOVED_X { p.at.x + dx } else { p.at.x };
            BufferPoint { at: Point::new(x, p.at.y + dy), pen: p.pen }
        })
    };
    let vertical: Vec<BufferPoint> = copy_offsets(2 * (n / 100)).flat_map(|d| moved(0, d)).collect();
    let horizontal: Vec<BufferPoint> = copy_offsets(2 * (n % 100)).flat_map(|d| moved(d, 0)).collect();
    points.extend(vertical);
    points.extend(horizontal);
}

/// 14, -14, 28, -28, … (`count` of them).
fn copy_offsets(count: i32) -> impl Iterator<Item = i32> {
    (0..count).map(|i| THICKEN_STEP * (i / 2 + 1) * if i % 2 == 0 { 1 } else { -1 })
}

#[cfg(test)]
mod tests {
    use super::*;

    fn at(points: &[BufferPoint]) -> Vec<(i32, i32)> {
        points.iter().map(|p| (p.at.x, p.at.y)).collect()
    }

    #[test]
    fn thickening_alternates_sides_and_copies_the_originals() {
        let mut points = vec![BufferPoint { at: Point::new(0, 0), pen: Pen::Fill }];
        thicken(&mut points, 0, 102);
        assert_eq!(at(&points), [(0, 0), (0, 14), (0, -14), (14, 0), (-14, 0), (28, 0), (-28, 0)]);
    }

    #[test]
    fn far_left_points_stay_in_horizontal_copies() {
        let mut points = vec![BufferPoint { at: Point::new(-192_601, 0), pen: Pen::Stroke }];
        thicken(&mut points, 0, 1);
        assert_eq!(at(&points), [(-192_601, 0), (-192_601, 0), (-192_601, 0)]);
    }

    #[test]
    fn zero_or_negative_outlines_fills() {
        let mut points = vec![
            BufferPoint { at: Point::new(0, 0), pen: Pen::Fill },
            BufferPoint { at: Point::new(1, 0), pen: Pen::SubPath },
        ];
        thicken(&mut points, 0, 0);
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
}
