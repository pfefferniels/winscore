//! Code 8: staves (draw_staff 0x545140).
//!
//! P3/P6 left and right end (P6 = 0 is 200), P4 displacement in scale steps,
//! P5 size (or P14 = staff height in cm), P7 lines, P8 an extra line P8
//! inches above the bottom line (undocumented), P10 height above a reference
//! staff, P12 = 1 hides the staff number. P11 (thickness) only acts in print.
//! Every line is its own one-unit segment, drawn bottom to top.

use std::iter::successors;

use crate::canvas::{Canvas, TextString, TextStyle};
use crate::colour::SCREEN_INVISIBLE;
use crate::display::{Colour, Point, UNITS_PER_INCH};
use crate::document::{Document, ItemRef};
use crate::page::{self, RECTO_SHIFT};
use crate::staff::Staff;
use crate::units::{nint, real, Pos};

/// Which lines of a normal staff are drawn (P7).
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct Lines {
    /// The lowest drawn line, counted from the bottom line (0).
    first: i32,
    count: i32,
}

impl Lines {
    const NORMAL: Lines = Lines { first: 0, count: 5 };

    /// 0 = five lines; n < 100 = n lines up from the bottom line; XYZ = YZ
    /// lines from line X of a normal staff.
    fn from_p7(p7: f32) -> Self {
        match p7 as i32 {
            n if n <= 0 => Lines::NORMAL,
            n if n < 100 => Lines { first: 0, count: n },
            n => Lines { first: (n / 100 - 1).max(0), count: n % 100 },
        }
    }
}

/// Staff 0 exists in the table but is never drawn.
const FIRST_DRAWN_STAFF: i32 = 1;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let Some(staff) = doc.staves.staff_for(item).filter(|s| s.number >= FIRST_DRAWN_STAFF) else {
        return;
    };
    let lines = if item.p(7) < 0.0 {
        if !doc.screen() {
            return;
        }
        canvas.colour = SCREEN_INVISIBLE;
        Lines::NORMAL
    } else {
        Lines::from_p7(item.p(7))
    };
    let left = page::x(item.p(3));
    let right = match item.p(6) {
        0.0 => page::x(200.0),
        p6 => page::x(p6),
    };
    if item.p(8) != 0.0 {
        let y = real(staff.bottom + f64::from(UNITS_PER_INCH) * f64::from(item.p(8)));
        segment(canvas, left, page::x(200.0), y);
    }
    let space = 2.0 * staff.scale_step();
    let first = real(staff.bottom + f64::from(lines.first) * space);
    successors(Some(first), |y| Some(real(y + space)))
        .take(lines.count.max(0) as usize)
        .for_each(|y| segment(canvas, left, right, y));
    if doc.screen() && doc.options.staff_numbers && item.p(12) != 1.0 {
        draw_number(&staff, left, canvas);
    }
}

fn segment(canvas: &mut Canvas<'_>, x0: f64, x1: f64, y: f64) {
    canvas.stroke([Pos::new(x0, y).to_point(), Pos::new(x1, y).to_point()]);
}

/// Staff numbers: Helvetica-Narrow in dark green, independent of staff size.
const NUMBER_COLOUR: Colour = Colour { r: 0x00, g: 0x73, b: 0x33 };
const NUMBER_HEIGHT: f32 = 12.10625 * 64.0;
const NUMBER_WIDTH: f32 = 4.993_828_3 * 64.0;
/// Left of the staff's start, or of P3 = 0 for staves starting further right.
const NUMBER_X: f64 = -1200.0;
const NUMBER_X_WIDE: f64 = -1700.0;
const DIGIT_ADVANCE: i32 = 352;
/// The staff number moves to the recto page only above staff 200, unlike the lines.
const FIRST_RECTO_NUMBER: i32 = 201;

/// The staff number left of the staff, one string per digit; its baseline
/// level is scale step 6 less 100 units. Fitted to oracle output for sizes
/// -1 to 1.429 and P3 down to -20.
fn draw_number(staff: &Staff, left: f64, canvas: &mut Canvas<'_>) {
    let digits = staff.number.to_string();
    let recto = if staff.number >= FIRST_RECTO_NUMBER { RECTO_SHIFT } else { 0 };
    let indent = if digits.len() > 2 { NUMBER_X_WIDE } else { NUMBER_X };
    let x = recto + nint(left.min(0.0) + indent);
    let y = nint(staff.y(6.0) - 100.0);
    let strings = digits.chars().zip((0..).map(|i| x + i * DIGIT_ADVANCE)).map(|(digit, x)| TextString {
        at: Point::new(x, y),
        text: digit.to_string(),
    });
    let item_colour = std::mem::replace(&mut canvas.colour, NUMBER_COLOUR);
    canvas.text(&number_style(), strings);
    canvas.colour = item_colour;
}

fn number_style() -> TextStyle {
    TextStyle {
        font: "Helvetica-Narrow".to_string(),
        height: NUMBER_HEIGHT,
        width: NUMBER_WIDTH,
        escapement: 0,
        weight: 400,
        italic: false,
        underline: false,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn p7_variants() {
        assert_eq!(Lines::from_p7(0.0), Lines::NORMAL);
        assert_eq!(Lines::from_p7(0.5), Lines::NORMAL);
        assert_eq!(Lines::from_p7(3.0), Lines { first: 0, count: 3 });
        assert_eq!(Lines::from_p7(203.0), Lines { first: 1, count: 3 });
        assert_eq!(Lines::from_p7(105.0), Lines::NORMAL);
    }
}
