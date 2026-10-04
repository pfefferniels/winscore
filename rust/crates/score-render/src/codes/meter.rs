//! Code 18: meters (draw_meter 0x4BFA59).
//!
//! P5/P6 top and bottom number, P7 size, P8/P9 a second meter joined by a
//! plus (P10 its position, P11 the space, P12 suppresses it), P13 font,
//! P15 offset, P16 pixel thickness. P5 from 91 on draws library symbol
//! 117 − P5 (99 common time, 98 alla breve) at 0.75 × P7. Numeric meters
//! go through draw_number and draw_text and are not drawn yet.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::{draw_library_symbol, ItemContext, SymbolCall};
use crate::units::{real, trunc};

/// P5 from this value on selects a symbol instead of a number.
const FIRST_SYMBOL_P5: i32 = 91;
const SYMBOL_BASE: i32 = 117;
const SYMBOL_SIZE: f32 = 0.75;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let p5 = trunc(f64::from(item.p(5)));
    if p5 >= FIRST_SYMBOL_P5 {
        draw_meter_symbol(doc, item, canvas, p5);
    }
}

fn draw_meter_symbol(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, p5: i32) {
    let p7 = match item.p(7) {
        0.0 => 1.0,
        p7 => f64::from(p7),
    };
    let size = real(p7 * f64::from(SYMBOL_SIZE));
    let call = SymbolCall::sized(SYMBOL_BASE - p5, size, size);
    let context = ItemContext { code: crate::codes::CLEF, ..ItemContext::of(item) };
    draw_library_symbol(doc, &context, canvas, doc.position(item), doc.staff_of(item).step, &call);
}
