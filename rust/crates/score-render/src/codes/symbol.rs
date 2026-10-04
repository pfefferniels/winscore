//! Code 9: library symbols (draw_item 0x547210 calls draw_symbol 0x4293F0
//! with X_POS, Y_POS, IP5, P6, P7, IP8, P9, IP9).
//!
//! P5 symbol number (`scorlib/symblist.txt`; negative reads as 0), P6
//! size (0 = 1; the hundreds are part-extractor flags; negative mirrors),
//! P7 vertical size (0 = P6), P8 thickening `X0Y` (-1 outline), P9
//! clockwise rotation in degrees (when trunc(P9) != 0), P10 pixel
//! thickness, P15 horizontal offset (applied by item_position). The symbol
//! itself is drawn by the shared [`symbols::draw_library_symbol`].
//!
//! Not drawn yet: the symbols the engine sets as text (8va, cresc., G.P., …)
//! and the CODE9.DAT terms 3000-3099, which wait for draw_text.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::{self, ItemContext, SymbolCall};
use crate::units::trunc;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let ip = |n: usize| trunc(f64::from(item.p(n)));
    let call = SymbolCall {
        number: ip(5),
        size_x: f64::from(item.p(6)),
        size_y: f64::from(item.p(7)),
        thickness: ip(8),
        rotation: f64::from(item.p(9)),
    };
    let step = doc.staff_of(item).step;
    symbols::draw_library_symbol(doc, &ItemContext::of(item), canvas, doc.position(item), step, &call);
}
