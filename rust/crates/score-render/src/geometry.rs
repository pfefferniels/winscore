//! Geometry the engine applies to buffered points, shared by several codes.

use crate::canvas::BufferPoint;
use crate::display::Point;
use crate::units::{real, trunc};

/// rotate_points 0x42A5F4: turns buffered points clockwise by `degrees`
/// about `centre`. The angle, its sine and cosine are REAL*4; each point is
/// truncated again after the turn. Called by draw_symbol, boxes, lines,
/// slurs, EPS and text with the points added since a given buffer index.
pub fn rotate_points(points: &mut [BufferPoint], centre: Point, degrees: f32) {
    let angle = real(f64::from(degrees) / f64::from(57.2958_f32));
    let (sin, cos) = (real(angle.sin()), real(angle.cos()));
    let (cx, cy) = (f64::from(centre.x), f64::from(centre.y));
    points.iter_mut().for_each(|p| {
        let dx = f64::from(p.at.x) - cx;
        let dy = f64::from(p.at.y) - cy;
        p.at = Point::new(trunc(cos * dx + sin * dy + cx), trunc(cos * dy - sin * dx + cy));
    });
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::canvas::Pen;

    #[test]
    fn quarter_turn_is_clockwise() {
        let mut points = [BufferPoint { at: Point::new(110, 100), pen: Pen::Stroke }];
        rotate_points(&mut points, Point::new(100, 100), 90.0);
        assert_eq!(points[0].at, Point::new(100, 90));
    }
}
