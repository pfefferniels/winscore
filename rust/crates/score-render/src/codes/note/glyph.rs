//! Library symbols as notes and rests draw them: through the shared
//! draw_clef and draw_symbol ports, with the STEP the caller has set and
//! IP10 = 0, which draw_note and draw_rest leave before drawing (the item's
//! own P10 is an offset there, not a pixel thickness).

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::{self, draw_library_symbol, ItemContext, SymbolCall};
use crate::units::Pos;

fn context(item: ItemRef<'_>) -> ItemContext {
    ItemContext { pixels: 0, ..ItemContext::of(item) }
}

/// draw_clef 0x431AE0 for symbol `n` at sizes `(sx, sy)`.
pub fn clef(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, n: i32, at: Pos, size: (f64, f64), step: f64) {
    symbols::draw_clef(doc, &context(item), canvas, at, step, n, size);
}

/// draw_symbol 0x4293F0 for symbol `n` at sizes `(sx, sy)`, unrotated.
pub fn library(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, n: i32, at: Pos, size: (f64, f64), step: f64) {
    draw_library_symbol(doc, &context(item), canvas, at, step, &SymbolCall::sized(n, size.0, size.1));
}
