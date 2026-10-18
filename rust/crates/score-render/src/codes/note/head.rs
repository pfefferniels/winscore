//! Note heads and their parentheses (0x4F14B0).
//!
//! Heads 0–6 are symbols 11–17 drawn through draw_clef at the note's unit
//! (P20 widens them), 8 and 9 the library symbols 95 and 139, 7 nothing;
//! any other P6 is a library symbol drawn by draw_symbol at 0.833. P6 + 10
//! adds parentheses (symbol 208), moved out for an accidental and for dots.

use super::glyph;
use super::Note;
use crate::canvas::Canvas;
use crate::codes::number::{draw_number, number_text, number_text_call, NumberCall};
use crate::display::Colour;
use crate::text::{font_loaded as text_font_loaded, Font};
use score_format::Item;
use crate::page::P3_UNIT;
use crate::document::{Document, ItemRef};
use crate::units::{constant, real, trunc, Pos};

const FIRST_HEAD_SYMBOL: i32 = 11;
const HEADLESS: i32 = 7;
const DIAMOND_X: i32 = 8;
const OVAL_X: i32 = 9;
const DIAMOND_X_SYMBOL: i32 = 95;
const OVAL_X_SYMBOL: i32 = 139;
const LIBRARY_HEAD_SIZE: f32 = 0.833;

const PARENTHESIS_SYMBOL: i32 = 208;
const PARENTHESIS_SIZE: f32 = 1.4;
/// The left parenthesis's offset in units, further left for an accidental
/// and again for a double flat.
const LEFT_PARENTHESIS: f32 = -13.8;
const ACCIDENTAL_ROOM: f32 = 14.4;
const DOUBLE_FLAT_ROOM: f32 = 12.6;
/// The right parenthesis's offset: plain, after a dot, after two or more.
const RIGHT_PARENTHESIS: f32 = 31.2;
const RIGHT_PARENTHESIS_DOT: f32 = 39.2;
const RIGHT_PARENTHESIS_DOTS: f32 = 51.2;
/// The head width in units the right offset assumes.
const NORMAL_WIDTH: f32 = 17.0;
const DOUBLE_FLAT: i32 = 4;

/// AlphaNotes (P6 20 … 25, negative for hollow heads): a round library
/// head, 1.45 units right and 1.68 scale steps down, drawn as a code-9
/// symbol (0x4F1BD4), with the letter name inside (0x4F1D5E, P21–P24).
const ALPHA_NOTES: std::ops::RangeInclusive<i32> = 20..=25;
const ALPHA_HEAD: i32 = 89;
const HOLLOW_ALPHA_HEAD: i32 = 88;
/// The head width the routine leaves for the stem and tails, in units.
pub const ALPHA_WIDTH: f32 = 17.1;

pub fn is_alpha(p6: i32) -> bool {
    ALPHA_NOTES.contains(&unparenthesised(p6).abs())
}

/// The head type the stem routine sees: P6 without the parentheses' 10.
pub fn unparenthesised(p6: i32) -> i32 {
    if super::PARENTHESISED.contains(&p6) {
        p6 - 10
    } else {
        p6
    }
}

/// Whether draw_note draws a head for P6 (it skips -1 … -19).
pub fn drawn(note: &Note) -> bool {
    note.head >= 0 || note.head <= -20
}

pub fn draw(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let p6 = trunc(f64::from(item.p(6)));
    if note.alpha {
        alpha_head(doc, item, note, canvas);
        return;
    }
    let clef_head = |canvas: &mut Canvas<'_>, h: i32| {
        glyph::clef(doc, item, canvas, h + FIRST_HEAD_SYMBOL, note.origin, (note.width, 1.0), note.unit);
    };
    let library_head = |canvas: &mut Canvas<'_>, n: i32| {
        let size = constant(LIBRARY_HEAD_SIZE);
        glyph::library(doc, item, canvas, n, note.origin, (size, size), note.unit);
    };
    match unparenthesised(p6) {
        HEADLESS => {}
        -3 => clef_head(canvas, super::BREVE),
        h if h < HEADLESS => clef_head(canvas, h),
        DIAMOND_X => library_head(canvas, DIAMOND_X_SYMBOL),
        OVAL_X => library_head(canvas, OVAL_X_SYMBOL),
        n => library_head(canvas, n),
    }
    if super::PARENTHESISED.contains(&p6) {
        parentheses(doc, item, note, canvas);
    }
}

/// An AlphaNote head: for a hollow head on a line first a white box that
/// hides the staff line (0x4F1F69), then symbol 89 (88 hollow) through the
/// code-9 path, which places it from P3/P4 on the staff's own step. The
/// letter needs draw_number and is not drawn yet.
fn alpha_head(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let staff = doc.staff_of(item);
    let hollow = trunc(f64::from(item.p(6))) < 0;
    if hollow && note.level % 2 != 0 {
        staff_line_mask(note, staff.step, canvas);
    }
    let size = alpha_size(item);
    let p3 = real(note.unit * constant(1.45) / 25.0 + real(note.origin.x / P3_UNIT));
    let p4 = real(f64::from(item.p(4)) - constant(1.68));
    let at = Pos::new(real(p3 * P3_UNIT), staff.y(p4));
    let symbol = if hollow { HOLLOW_ALPHA_HEAD } else { ALPHA_HEAD };
    glyph::library(doc, item, canvas, symbol, at, (real(size * constant(0.58)), real(size * constant(0.475))), staff.step);
    if doc.screen() {
        alpha_letter(doc, item, note, size, canvas);
    }
}

/// The letter name in an AlphaNote (0x4F1D5E, screen only, P6 ±20 … ±23
/// for treble, bass, alto, tenor clef names): a code-10 number item with
/// P5 = 1001 + the letter, at P22/P23 from its default place, size P24,
/// font P21 (default 5, bold), white in a black head.
fn alpha_letter(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, size: f64, canvas: &mut Canvas<'_>) {
    let Some(changed) = letter_item(item, note, size) else { return };
    let letter_item = item.changed(&changed);
    // The letter's P26 is pushed and popped around it in the engine; the
    // note's points are flushed in the note's own colour.
    let own = canvas.colour;
    draw_number(doc, letter_item, canvas, doc.position(letter_item), &NumberCall::of(letter_item));
    canvas.colour = own;
}

/// The font an AlphaNote's letter leaves loaded.
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>, note: &Note) -> Option<Font> {
    if !note.alpha || !doc.screen() {
        return None;
    }
    let changed = letter_item(item, note, alpha_size(item))?;
    let letter_item = item.changed(&changed);
    let call = NumberCall::of(letter_item);
    let text = number_text(call.value, call.p5, call.p17, call.p18);
    text_font_loaded(doc, &number_text_call(&call, Pos::default(), &text, Font::TIMES))
}

/// P15 as the AlphaNote routines use it (0 read as 1).
fn alpha_size(item: ItemRef<'_>) -> f64 {
    match item.p(15) {
        0.0 => 1.0,
        p15 => f64::from(p15),
    }
}

/// The code-10 item 0x4F1D5E draws as the letter; None from P6 ±24 on.
fn letter_item(item: ItemRef<'_>, note: &Note, size: f64) -> Option<Item> {
    let kind = unparenthesised(trunc(f64::from(item.p(6)))).abs();
    let clef_shift = match kind {
        21 => -5,
        22 => 1,
        23 => -1,
        24.. => return None,
        _ => 0,
    };
    let letter = (note.level + clef_shift + 71) % 7 + 1001;
    let p = |n: usize| f64::from(item.p(n));
    let p24 = if item.p(24) == 0.0 { 1.0 } else { p(24) };
    let x150 = real(note.origin.x / P3_UNIT);
    let mut changes = vec![
        (1, 10.0),
        (3, real(note.unit * constant(0.022) + x150 + p(22)) as f32),
        (4, real(p(4) - size * constant(0.72) + p(23)) as f32),
        (5, letter as f32),
        (6, real(size * constant(0.45) * p24) as f32),
        (7, if item.p(21) == 0.0 { 1005.0 } else { item.p(21) + 1000.0 }),
        (8, 0.0),
        (24, p24 as f32),
    ];
    if trunc(p(6)) > 0 {
        changes.push((26, 0.99));
    }
    Some(item.with_params(&changes))
}

/// draw_box type 0, filled, 2.4 by 0.35 half-widths of 3.5 steps, centred
/// 210 units (at size 1) right of the note, emitted at once in white.
fn staff_line_mask(note: &Note, staff_step: f64, canvas: &mut Canvas<'_>) {
    let centre = Pos::new(real(staff_step / 25.0 * 210.0 + note.origin.x), note.origin.y);
    white_box(canvas, centre, note.step, (constant(2.4), constant(0.35)));
}

/// draw_box type 0, filled, with half-widths of `size` × 3.5 steps,
/// emitted at once (as 0x4F1F69 and 0x559733 do) in white, to match the
/// paper; the engine uses the near-white 0xFDFDFD.
pub(super) fn white_box(canvas: &mut Canvas<'_>, centre: Pos, step: f64, size: (f64, f64)) {
    let half_width = real(step * 3.5 * size.0);
    let half_height = real(step * 3.5 * size.1);
    let (left, right) = (real(centre.x - half_width), real(half_width + centre.x));
    let (bottom, top) = (real(centre.y - half_height), real(half_height + centre.y));
    let own = canvas.colour;
    canvas.flush();
    canvas.colour = MASK_COLOUR;
    canvas.fill([[
        Pos::new(left, bottom),
        Pos::new(right, bottom),
        Pos::new(right, top),
        Pos::new(left, top),
        Pos::new(left, bottom),
    ]]);
    canvas.flush();
    canvas.colour = own;
}

const MASK_COLOUR: Colour = Colour { r: 255, g: 255, b: 255 };

fn parentheses(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let left = match trunc(f64::from(item.p(5))) % 10 {
        0 => constant(LEFT_PARENTHESIS),
        DOUBLE_FLAT => real(real(constant(LEFT_PARENTHESIS) - constant(ACCIDENTAL_ROOM)) - constant(DOUBLE_FLAT_ROOM)),
        _ => real(constant(LEFT_PARENTHESIS) - constant(ACCIDENTAL_ROOM)),
    };
    let p9 = trunc(f64::from(item.p(9)));
    let right = match (p9 >= 10, p9 % 100 >= 20) {
        (_, true) => constant(RIGHT_PARENTHESIS_DOTS),
        (true, false) => constant(RIGHT_PARENTHESIS_DOT),
        (false, false) => constant(RIGHT_PARENTHESIS),
    };
    let right = if note.width == 1.0 { right } else { real(note.width * constant(NORMAL_WIDTH) + (right - constant(NORMAL_WIDTH))) };
    let size = constant(PARENTHESIS_SIZE);
    [(left, size), (right, -size)].into_iter().for_each(|(offset, sx)| {
        let at = Pos::new(real(note.unit * offset + note.origin.x), note.origin.y);
        glyph::library(doc, item, canvas, PARENTHESIS_SYMBOL, at, (sx, size), note.unit);
    });
}

#[cfg(test)]
mod tests {
    use crate::codes::note::tests::{file, shapes};
    use crate::display::Colour;

    #[test]
    fn knockouts_are_white() {
        // Tablature (P6 = -6) with P20 = 1: a box behind the fret number.
        let mut params = [0.0_f32; 20];
        params[..6].copy_from_slice(&[1.0, 1.0, 20.0, 5.0, 0.0, -6.0]);
        params[19] = 1.0;
        let file = file(&[&params]);
        assert_eq!(shapes(&file, 1)[0].colour, Colour { r: 255, g: 255, b: 255 });
    }
}
