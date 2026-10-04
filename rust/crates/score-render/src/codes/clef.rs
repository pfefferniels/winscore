//! Code 3: clefs (draw_clef 0x431AE0).
//!
//! P5 type: 0 treble, 1 bass, 2 alto, 3 tenor, 4 percussion (5-9 and 45 on
//! draw library symbols), 0.8/0.88/0.15 treble and 1.8 bass with an octave
//! number, 44/55/66 tablature clefs for 4, 5 and 6 lines. P4 vertical
//! position, |P4| >= 100 a mini clef; P6/P7 size; P15 offset. The clef
//! itself is the shared [`symbols::clef_placement`] and
//! [`symbols::draw_clef_symbol`]; this module adds what draw_clef does only
//! for code-3 items.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::{self, ClefPlacement, SymbolCall};
use crate::units::{real, trunc, Pos};

/// A tablature clef: its P5, size factor and lift in scale steps above P4.
struct Tablature {
    p5: i32,
    size: Option<f32>,
    lift: Option<f32>,
}

const TABLATURE: [Tablature; 3] = [
    Tablature { p5: 44, size: Some(0.6), lift: Some(1.2) },
    Tablature { p5: 55, size: Some(0.83), lift: Some(0.35) },
    Tablature { p5: 66, size: None, lift: None },
];
const TABLATURE_SYMBOL: i32 = 3;
const TABLATURE_SIZE: f32 = 0.1;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let step = doc.staff_of(item).step;
    let kind = trunc(f64::from(item.p(5)));
    let placement =
        symbols::clef_placement(item, doc.position(item), step, kind, f64::from(item.p(6)), f64::from(item.p(7)));
    match TABLATURE.iter().find(|t| t.p5 == kind) {
        Some(tablature) => draw_tablature(doc, item, canvas, &placement, tablature),
        None => symbols::draw_clef_symbol(doc, item, canvas, &placement, step),
    }
}

/// Tablature clefs: library symbol 3 at a tenth of the size (times the
/// clef's own factor), lifted from P4 for 4 and 5 lines.
fn draw_tablature(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    placement: &ClefPlacement,
    tablature: &Tablature,
) {
    let staff = doc.staff_of(item);
    let tenth = |size: f64| real(size * f64::from(TABLATURE_SIZE));
    let factor = |size: f64| tablature.size.map_or(size, |f| real(size * f64::from(f)));
    let (size_x, size_y) = (factor(tenth(placement.size_x)), factor(tenth(placement.size_y)));
    let y = tablature
        .lift
        .map_or(placement.at.y, |lift| staff.y(real(f64::from(item.p(4)) + f64::from(lift))));
    let call = SymbolCall::sized(TABLATURE_SYMBOL, size_x, size_y, item);
    symbols::draw_library_symbol(doc, item, canvas, Pos::new(placement.at.x, y), staff.step, &call);
}
