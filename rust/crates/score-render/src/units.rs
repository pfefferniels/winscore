//! The engine's numbers: internal coordinates, REAL*4 storage, truncation.
//!
//! Item modules compute in the engine's internal coordinates (1/4000 inch,
//! y up, x = 0 at P3 = 0, staff 1's bottom line at y = -24000). The engine
//! evaluates expressions on the x87 at 53-bit precision, stores intermediate
//! results as REAL*4, and converts to integers by truncation toward zero when
//! a point is added to the vector stream (add_point 0x44B820). [`real`] and
//! [`Pos::to_point`] reproduce those two steps; the canvas then moves the
//! integer points onto the page.

use crate::display::Point;

/// A value stored in a REAL*4 variable.
pub fn real(value: f64) -> f64 {
    f64::from(value as f32)
}

/// A REAL*4 constant of the engine, e.g. `constant(13.8)` is 13.8000002.
pub fn constant(value: f32) -> f64 {
    f64::from(value)
}

/// Fortran AMOD (amod 0x54AABA): x - trunc(x / y)·y, with the quotient truncated.
pub fn amod(x: f64, y: f64) -> f64 {
    // 0x54AABA: the quotient goes through FISTP into a 32-bit integer, the
    // result through FSTP into a REAL*4.
    real(x - f64::from(trunc(x / y)) * y)
}

/// The engine's float-to-integer conversion for points: truncation toward
/// zero. Like the x87 FISTP it gives i32::MIN, the "integer indefinite",
/// for NaN and for values outside the i32 range.
pub fn trunc(value: f64) -> i32 {
    if value > -2_147_483_649.0 && value < 2_147_483_648.0 {
        value as i32
    } else {
        i32::MIN
    }
}

/// FORTRAN's NINT through ANINT 0x5FF381: trunc(x ± 0.5) in f64, so halves
/// go away from zero. Text positions use it.
pub fn nint(value: f64) -> i32 {
    trunc(value + 0.5_f64.copysign(value))
}

/// A position in internal coordinates, before truncation.
#[derive(Debug, Clone, Copy, PartialEq, Default)]
pub struct Pos {
    pub x: f64,
    pub y: f64,
}

impl Pos {
    pub const fn new(x: f64, y: f64) -> Self {
        Self { x, y }
    }

    /// The integer point the engine adds to its vector stream.
    pub fn to_point(self) -> Point {
        Point::new(trunc(self.x), trunc(self.y))
    }
}

impl From<Point> for Pos {
    fn from(p: Point) -> Self {
        Pos::new(f64::from(p.x), f64::from(p.y))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn truncates_toward_zero() {
        assert_eq!(trunc(37.5), 37);
        assert_eq!(trunc(-37.5), -37);
        assert_eq!(trunc(-23692.91), -23692);
    }

    #[test]
    fn truncates_out_of_range_to_integer_indefinite() {
        assert_eq!(trunc(f64::NAN), i32::MIN);
        assert_eq!(trunc(3.0e9), i32::MIN);
        assert_eq!(trunc(-3.0e9), i32::MIN);
    }

    #[test]
    fn nint_adds_a_half_and_truncates() {
        assert_eq!(nint(2.5), 3);
        assert_eq!(nint(-2.5), -3);
        assert_eq!(nint(0.499_999_999_999_999_94), 1);
        assert_eq!(nint(-0.4), 0);
    }

    #[test]
    fn amod_keeps_the_sign() {
        assert_eq!(amod(101.5, 100.0), 1.5);
        assert_eq!(amod(-250.0, 100.0), -50.0);
    }

    #[test]
    fn amod_rounds_to_real_and_uses_the_integer_quotient() {
        assert_eq!(amod(100.1, 100.0), real(100.1 - 100.0));
        assert_eq!(amod(3.0e11, 1.0), real(3.0e11 + 2_147_483_648.0));
    }

    #[test]
    fn real_rounds_to_single_precision() {
        assert_eq!(real(0.1), f64::from(0.1_f32));
        assert_eq!(real(150.0 * f64::from(0.25_f32)), 37.5);
    }
}
