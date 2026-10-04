//! Code 15: imported EPS files as WinScore's screen shows them (draw_eps
//! 0x50A650).
//!
//! P3/P4 the lower left corner, P5 horizontal size (0 = 1), P6 vertical size
//! (0 = P5), P7-P10 the file's bounding box in points, P11 = -9999 once it
//! has been read, P12 clockwise rotation in degrees, P14… the file name.
//! The screen shows the bounding box with its diagonals; before the box is
//! read, a placeholder square of P5 × P6 scale steps (default 3). Printing
//! embeds the file instead.
//!
//! The engine draws nothing when it cannot find the file; the port has no
//! file system and assumes the file is there.

use crate::canvas::{Canvas, Pen};
use crate::document::{Document, ItemRef};
use crate::geometry::rotate_points;
use crate::staff::UNITS_PER_SCALE_STEP;
use crate::units::{constant, real, trunc, Pos};

/// P11 once the bounding box has been read from the file.
const BOUNDING_BOX_READ: i32 = -9999;
/// Scale steps of the placeholder when P5 is 0.
const PLACEHOLDER_SIZE: f64 = 3.0;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let at = doc.position(item);
    let step = doc.staff_of(item).step;
    if trunc(f64::from(item.p(11))) == BOUNDING_BOX_READ {
        bounding_box(item, at, step, canvas);
    } else {
        placeholder(item, at, step, canvas);
    }
}

/// The bounding box in points (1/72 inch, STEP / 0.45 engine units at size
/// 1 on a size-1 staff), scaled by P5 and P6, with both diagonals.
fn bounding_box(item: ItemRef<'_>, at: Pos, step: f64, canvas: &mut Canvas<'_>) {
    let p = |n: usize| f64::from(item.p(n));
    let size_x = match p(5) {
        0.0 => 1.0,
        s => s,
    };
    let size_y = match p(6) {
        0.0 => size_x,
        s => s,
    };
    let unit = real(step / constant(0.45));
    let right = real((p(9) - p(7)) * unit * size_x + at.x);
    let top = real((p(10) - p(8)) * unit * size_y + at.y);
    let corner = |x: f64, y: f64| Pos::new(x, y);
    canvas.stroke([
        at,
        corner(at.x, top),
        corner(right, top),
        corner(right, at.y),
        at,
        corner(right, top),
    ]);
    canvas.stroke([corner(at.x, top), corner(right, at.y)]);
    let rotation = item.p(12);
    if trunc(f64::from(rotation)) != 0 {
        rotate_points(canvas.buffer_mut(), at.to_point(), rotation);
    }
}

/// P5 × P6 scale steps (default 3) from P3/P4.
fn placeholder(item: ItemRef<'_>, at: Pos, step: f64, canvas: &mut Canvas<'_>) {
    let scale_step = real(step * UNITS_PER_SCALE_STEP);
    let width = match item.p(5) {
        0.0 => PLACEHOLDER_SIZE,
        s => f64::from(s),
    };
    let height = match item.p(6) {
        0.0 => width,
        s => f64::from(s),
    };
    let right = real(scale_step * width + at.x);
    let top = real(scale_step * height + at.y);
    canvas.point(at, Pen::Stroke);
    [Pos::new(right, at.y), Pos::new(right, top), Pos::new(at.x, top), at]
        .into_iter()
        .for_each(|p| canvas.point(p, Pen::Continue));
}
