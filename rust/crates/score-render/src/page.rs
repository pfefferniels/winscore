//! The page: paper size, the P3 axis, and the move from internal to page
//! coordinates.
//!
//! Page coordinates are engine units with the origin at the bottom-left
//! corner of the paper and y up. They
//! are internal coordinates (see [`crate::units`]) plus a fixed integer
//! offset, and plus [`RECTO_SHIFT`] for items on staves above 199. The
//! engine's screen output is the same picture shifted by the view's scroll
//! position (x + 2400, y - (top + 3000)).

use crate::display::Point;
use crate::units::real;

/// Paper size in engine units.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Paper {
    pub width: f64,
    pub height: f64,
}

impl Paper {
    pub const LETTER: Paper = Paper { width: 34000.0, height: 44000.0 };
    /// `PAPER 2`, WinScore's default preference.
    pub const LEGAL: Paper = Paper { width: 34000.0, height: 56000.0 };
    pub const TABLOID: Paper = Paper { width: 44000.0, height: 68000.0 };
}

impl Default for Paper {
    fn default() -> Self {
        Paper::LEGAL
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Default)]
pub struct Page {
    pub paper: Paper,
}

/// Internal units per P3 unit: P3 runs 0–200 over 7.5 inches.
pub const P3_UNIT: f64 = 150.0;

/// Internal coordinates of the paper's bottom-left corner, whatever the
/// paper size: half an inch left of P3 = 0, 2948 units below staff 1.
pub const PAPER_ORIGIN: Point = Point::new(-2000, -26948);

/// Added to x for items on the recto page.
pub const RECTO_SHIFT: i32 = 34050;

/// Staves above this number lie on the recto page.
pub const LAST_VERSO_STAFF: i32 = 199;

pub fn is_recto(staff: i32) -> bool {
    staff > LAST_VERSO_STAFF
}

/// Internal x of a horizontal position given in P3 units.
pub fn x(p3: f32) -> f64 {
    real(P3_UNIT * f64::from(p3))
}

/// What turns an internal point of an item on `staff` into a page point.
pub fn page_offset(staff: i32) -> Point {
    let recto = if is_recto(staff) { RECTO_SHIFT } else { 0 };
    Point::new(recto - PAPER_ORIGIN.x, -PAPER_ORIGIN.y)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn p3_axis() {
        assert_eq!(x(0.0), 0.0);
        assert_eq!(x(200.0), 30000.0);
        assert_eq!(page_offset(1), Point::new(2000, 26948));
        assert_eq!(page_offset(200), Point::new(36050, 26948));
    }
}
