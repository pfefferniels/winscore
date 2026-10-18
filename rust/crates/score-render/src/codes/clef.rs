//! Code 3: clefs (draw_clef 0x431AE0).
//!
//! P5 type: 0 treble, 1 bass, 2 alto, 3 tenor, 4 percussion (5-9 and 45 on
//! draw library symbols), 0.8/0.88/0.15 treble and 1.8 bass with an octave
//! number, 44/55/66 tablature clefs for 4, 5 and 6 lines. P4 vertical
//! position, |P4| >= 100 a mini clef; P6/P7 size; P15 offset. The clef
//! itself is the shared [`clef_placement`] and
//! [`draw_clef_symbol`]; this module adds what draw_clef does only
//! for code-3 items.

use crate::canvas::Canvas;
use crate::codes::number::{draw_number, number_font_loaded, NumberCall};
use crate::document::{Document, ItemRef};
use crate::page;
use crate::symbols::clef::{clef_placement, clef_symbol_call, draw_clef_symbol, ClefPlacement};
use crate::symbols::library::{is_missing, is_text_symbol, library_unit, normal_size, shows_missing};
use crate::symbols::{
    draw_library_symbol, draw_missing_symbol, draw_text_symbol, text_symbol_font_loaded, ItemContext, SymbolCall,
    TextSymbolCall,
};
use crate::text::Font;
use crate::units::{self, real, trunc, Pos};

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
    let clef = Clef::of(doc, item);
    // draw_number clears IP10 and does not restore it, so a clef drawn
    // after its octave number has no pixel thickness.
    let context = match clef.number {
        Some(_) => ItemContext { pixels: 0, ..ItemContext::of(item) },
        None => ItemContext::of(item),
    };
    if let Some((at, call)) = clef.number {
        draw_number(doc, item, canvas, at, &call);
    }
    match (clef.tablature, clef.text) {
        (Some(tablature), _) => draw_tablature(doc, item, canvas, &clef.placement, tablature),
        (None, Some(call)) => draw_text_symbol(doc, item, canvas, &call),
        // A symbol no library has: a placeholder on the screen in the refined style.
        (None, None) if shows_missing(doc) && is_missing(doc, clef.placement.number) => {
            let call = clef_symbol_call(&clef.placement);
            let unit = library_unit(step, &call, normal_size(call.number));
            draw_missing_symbol(canvas, item.staff(), clef.placement.at, unit, &call.number.to_string());
        }
        (None, None) => draw_clef_symbol(doc, &context, canvas, &clef.placement, step),
    }
}

/// The font a clef leaves loaded: that of its octave number, or of a text
/// symbol drawn in its place (see [`crate::text::font_loaded`]).
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    let clef = Clef::of(doc, item);
    let number = clef.number.and_then(|(at, call)| number_font_loaded(doc, at, &call));
    let text = clef.text.and_then(|call| text_symbol_font_loaded(doc, &call));
    text.or(number)
}

/// What a code-3 item draws: the placed symbol, and the octave number,
/// tablature form or text-symbol call that replace or accompany it.
struct Clef {
    placement: ClefPlacement,
    number: Option<(Pos, NumberCall)>,
    tablature: Option<&'static Tablature>,
    text: Option<TextSymbolCall>,
}

impl Clef {
    fn of(doc: &Document<'_>, item: ItemRef<'_>) -> Self {
        let step = doc.staff_of(item).step;
        let kind = trunc(f64::from(item.p(5)));
        let context = ItemContext::of(item);
        let placement =
            clef_placement(&context, doc.position(item), step, kind, f64::from(item.p(6)), f64::from(item.p(7)));
        let octave = Octave::of(item.p(5));
        let number = octave.map(|octave| octave_number(doc, item, &octave, placement.size_x, step));
        let placement = match octave {
            Some(octave) => ClefPlacement { number: octave.clef, ..placement },
            None => placement,
        };
        let tablature = TABLATURE.iter().find(|t| t.p5 == kind);
        let text = (tablature.is_none() && is_text_symbol(placement.number)).then(|| TextSymbolCall {
            size_x: placement.size_x,
            size_y: placement.size_y,
            ..TextSymbolCall::of(doc, item, placement.number)
        });
        Self { placement, number, tablature, text }
    }
}

/// An octave number above or below a clef (P5 = 0.8, 0.88, 0.15, 1.8, and
/// any |P5| × 100 from 1 to 99): the number, its height above the clef's
/// P4 in scale steps and its x offset in step units, both times the size.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Octave {
    number: i32,
    /// The clef symbol drawn with it: bass for 1.8, treble otherwise.
    clef: i32,
    lift: f32,
    shift: f32,
}

/// |P5| × 100 of the bass clef with an 8 below; it draws as type 80.
const BASS_OCTAVE: i32 = 180;
const BASS_AS: i32 = 80;
const OCTAVE_ABOVE: i32 = 88;
const TWO_OCTAVES: i32 = 15;
/// Clef P4 = 3 is the bottom line.
const OCTAVE_BASE_LEVEL: f32 = 3.0;
const OCTAVE_SIZE: f32 = 0.7;
/// Font Times-BoldItalic (P7 = 11 maps onto table entry 10).
const OCTAVE_FONT: i32 = 11;

impl Octave {
    /// draw_clef 0x431DB6: whether P5 asks for a number, and which.
    fn of(p5: f32) -> Option<Self> {
        let hundredths = crate::units::nint(f64::from(p5) * 100.0).abs();
        if hundredths != BASS_OCTAVE && !(1..100).contains(&hundredths) {
            return None;
        }
        let (code, clef, lift, shift) = match hundredths {
            BASS_OCTAVE => (BASS_AS, 1, 0.0, 0.06),
            OCTAVE_ABOVE => (OCTAVE_ABOVE, 0, 10.95, 0.12),
            TWO_OCTAVES => (TWO_OCTAVES, 0, 10.95, 0.085),
            h => (h, 0, -5.25, 0.08),
        };
        let number = match code / 10 {
            1 => TWO_OCTAVES,
            n => n,
        };
        Some(Self { number, clef, lift, shift })
    }
}

/// The octave number's draw_number call, placed by item_position from
/// P3' = P3 + P15 + STEP × shift × size and P4' = AMOD(P4, 100) + 3 +
/// size × lift, at 0.7 of the clef's size.
fn octave_number(doc: &Document<'_>, item: ItemRef<'_>, octave: &Octave, size: f64, step: f64) -> (Pos, NumberCall) {
    let p3 = real(step * f64::from(octave.shift) * size + (f64::from(item.p(15)) + f64::from(item.p(3))));
    let p4 = real((units::amod(f64::from(item.p(4)), 100.0) + f64::from(OCTAVE_BASE_LEVEL)) + size * f64::from(octave.lift));
    let at = Pos::new(page::x(p3 as f32), doc.staff_of(item).y(units::amod(p4, 100.0)));
    let call = NumberCall {
        value: octave.number,
        p5: octave.number as f32,
        size: real(size * f64::from(OCTAVE_SIZE)) as f32,
        font: OCTAVE_FONT,
        p3: p3 as f32,
        p4: p4 as f32,
        ..NumberCall::of(item)
    };
    (at, call)
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
    let call = SymbolCall::sized(TABLATURE_SYMBOL, size_x, size_y);
    draw_library_symbol(doc, &ItemContext::of(item), canvas, Pos::new(placement.at.x, y), staff.step, &call);
}
