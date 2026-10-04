//! Code 14: barlines, braces and brackets (draw_barline 0x4117B0).
//!
//! P2 lowest staff, P3 position (+ P7, or + P15), P4 staves spanned (999 =
//! up to the highest staff, negative = invisible), P5 type, P6 thickness,
//! P10/P11 bottom and top in scale steps of the end staves, P13 extra space
//! between double bars, P17 spacing as on a staff of that size.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::page::P3_UNIT;
use crate::staff::{Staff, STEP_UNIT};
use crate::units::{real, trunc, Pos};

/// The highest staff number a barline may reach.
const LAST_STAFF: i32 = 256;

const SINGLE: i32 = 0;
const DOUBLE: i32 = 1;
const FINAL: i32 = 2;
const BRACKET: i32 = 9;
const SQUARE_BRACKET: i32 = 10;

/// Where a barline starts and ends, and the width unit of its parts.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Bar {
    x: f64,
    bottom: f64,
    top: f64,
    /// The step unit of staff P2, or 25 × P17.
    unit: f64,
}

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let kind = item.p(5) as i32;
    let bar = bar(doc, item, kind);
    match kind {
        SINGLE if item.p(6) != 0.0 => thick(canvas, &bar, bar.x, item),
        SINGLE => thin(canvas, &bar, bar.x),
        DOUBLE => {
            thin(canvas, &bar, bar.x);
            thin(canvas, &bar, real(bar.x - 7.5 * bar.unit - 6.0 * bar.unit * f64::from(item.p(13))));
        }
        FINAL => {
            thin(canvas, &bar, real(bar.x - 13.8 * bar.unit - 6.0 * bar.unit * f64::from(item.p(13))));
            thick(canvas, &bar, real(bar.x - 6.0 * bar.unit), item);
        }
        _ => {}
    }
}

fn bar(doc: &Document<'_>, item: ItemRef<'_>, kind: i32) -> Bar {
    let low = doc.staff_of(item);
    let high = doc.staves.get(top_staff(doc, item));
    let x = doc.position(item).x;
    let x = match (item.p(7), item.p(15)) {
        (p7, p15) if p7 != 0.0 && p15 == 0.0 => real(x + P3_UNIT * f64::from(p7)),
        _ => x,
    };
    let (default_bottom, default_top) = match kind {
        SQUARE_BRACKET => (7.0, 7.0),
        k if k >= BRACKET => (1.0, 13.0),
        _ => (3.0, 11.0),
    };
    let level = |staff: &Staff, p: f32, default: f64| staff.y(if p == 0.0 { default } else { f64::from(p) });
    let unit = match item.p(17) {
        0.0 => low.step,
        p17 => real(STEP_UNIT * f64::from(p17)),
    };
    Bar { x, bottom: level(&low, item.p(10), default_bottom), top: level(&high, item.p(11), default_top), unit }
}

/// The highest staff spanned: P4 staves up from P2, or the highest staff for 999.
fn top_staff(doc: &Document<'_>, item: ItemRef<'_>) -> i32 {
    let low = item.staff();
    let span = trunc(f64::from(item.p(4))).abs();
    let top = match span {
        999 => doc.staves.highest().unwrap_or(low),
        k => low + k - 1,
    };
    top.min(LAST_STAFF)
}

fn thin(canvas: &mut Canvas<'_>, bar: &Bar, x: f64) {
    canvas.stroke([Pos::new(x, bar.bottom).to_point(), Pos::new(x, bar.top).to_point()]);
}

/// A thick bar from `left` to the barline's x, emitted as the engine does:
/// a diagonal hairline, then the filled rectangle with a doubled last point
/// unless trunc(P8) is 2 or more.
fn thick(canvas: &mut Canvas<'_>, bar: &Bar, left: f64, item: ItemRef<'_>) {
    let point = |x: f64, y: f64| Pos::new(x, y).to_point();
    let (xl, xr) = (left, bar.x);
    canvas.stroke([point(xl, bar.bottom), point(xr, bar.top)]);
    let mut outline = vec![
        point(xr, bar.top),
        point(xr, bar.bottom),
        point(xl, bar.bottom),
        point(xl, bar.top),
        point(xr, bar.top),
    ];
    if matches!(trunc(f64::from(item.p(8))), 0 | 1) {
        outline.push(point(xr, bar.top));
    }
    canvas.fill([outline]);
}
