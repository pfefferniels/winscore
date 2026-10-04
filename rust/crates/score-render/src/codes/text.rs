//! Code 16: text, drawn by the engine's text routine ([`crate::text`]).
//!
//! P3/P4 position, P5 spread, P6/P7 size, P8 font override, P9 rotation,
//! P10 space size, P11 shift, P12 character count; P14 = -1 takes the colour
//! from P16. The engine loads only P1–P12 of a text item (P1–P18 when
//! P14 = -1), so P13 and P26 play no part in drawing.

use std::borrow::Cow;

use crate::canvas::Canvas;
use crate::codes;
use crate::display::Colour;
use crate::document::{Document, ItemRef};
use crate::codes::meter;
use crate::text::{draw_text, font_loaded, Font, TextCall};
use crate::units::trunc;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    canvas.colour = Colour::BLACK;
    let text = characters(item);
    draw_text(doc, item, canvas, &text_call(doc, item, &text, font_before(doc, item)));
}

/// Words before the characters: P1–P13, or P1–P16 when P14 = -1.
const PARAMETERS: usize = 13;
const COLOUR_PARAMETERS: usize = 16;

/// The characters as the engine reads them (draw_text 0x569AF0): P12 of
/// them from the word after P13, or after P16 when P14 = -1, whatever the
/// item stores there. Past the item's blank-padded characters the engine
/// finds zeros in the cases checked.
fn characters(item: ItemRef<'_>) -> Cow<'_, [u8]> {
    let first = if item.p(14) == -1.0 { COLOUR_PARAMETERS } else { PARAMETERS };
    let params = item.item.params();
    let text = item.item.text();
    if params.len() == first {
        return Cow::Borrowed(text);
    }
    let count = item.p(12).max(0.0) as usize;
    let padding = (4 - text.len() % 4) % 4;
    let stored = params.get(first..).unwrap_or_default().iter().flat_map(|w| w.to_le_bytes());
    let skipped = 4 * first.saturating_sub(params.len());
    let bytes = stored
        .chain(text.iter().copied())
        .chain(std::iter::repeat_n(b' ', padding))
        .chain(std::iter::repeat(0))
        .skip(skipped)
        .take(count);
    Cow::Owned(bytes.collect())
}

/// Word `n` of the item as the engine loads it into P(n): past the stored
/// parameters it reads the characters.
fn stored_word(item: ItemRef<'_>, n: usize) -> f32 {
    let params = item.item.params().len();
    if n <= params {
        return item.p(n);
    }
    let at = 4 * (n - params - 1);
    let bytes: Vec<u8> = item.item.text().iter().copied().chain(std::iter::repeat(b' ')).skip(at).take(4).collect();
    f32::from_le_bytes([bytes[0], bytes[1], bytes[2], bytes[3]])
}

/// The draw_text call for a text item with its characters, given the font
/// current before it.
pub fn text_call<'a>(doc: &Document<'_>, item: ItemRef<'_>, text: &'a [u8], current_font: Font) -> TextCall<'a> {
    TextCall {
        text,
        origin: doc.position(item),
        p3: item.p(3),
        item_code: codes::TEXT,
        staff: item.staff(),
        spread: item.p(5),
        width: item.p(6),
        height: item.p(7),
        font_override: trunc(f64::from(item.p(8))),
        rotation: item.p(9),
        space: item.p(10),
        shift: item.p(11),
        colour: (item.p(14) == -1.0).then(|| stored_word(item, 16)),
        current_font,
    }
}

/// The engine's current font when it reaches `item`: draw_item sets it to
/// the font whose metrics were loaded last (0x547358). Items are drawn in
/// file order, several passes in a row, so that is the font loaded by the
/// nearest item before it, or failing that after it, that loads one.
pub fn font_before(doc: &Document<'_>, item: ItemRef<'_>) -> Font {
    let items: Vec<ItemRef<'_>> = doc.items().collect();
    let at = (item.id.0 as usize).min(items.len());
    let (before, after) = items.split_at(at);
    let after = after.get(1..).unwrap_or_default();
    before.iter().rev().chain(after.iter().rev()).find_map(|&other| font_loaded_by(doc, other)).unwrap_or(Font::TIMES)
}

/// The font an item leaves loaded, if it loads one.
fn font_loaded_by(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    match item.code() {
        codes::TEXT => font_loaded(doc, &text_call(doc, item, &characters(item), Font::TIMES)),
        codes::STAFF if shows_staff_number(doc, item) => Some(Font::STAFF_NUMBER),
        codes::METER => meter::font_loaded(doc, item),
        _ => None,
    }
}

/// codes::staff draws the number left of the staff on the screen (0x545DE0).
fn shows_staff_number(doc: &Document<'_>, item: ItemRef<'_>) -> bool {
    doc.screen()
        && doc.options.staff_numbers
        && item.p(12) != 1.0
        && doc.staves.staff_for(item).is_some_and(|staff| staff.number >= 1)
}
