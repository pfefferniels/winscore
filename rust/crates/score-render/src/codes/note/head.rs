//! Note heads and their parentheses (0x4F14B0).
//!
//! Heads 0–6 are symbols 11–17 drawn through draw_clef at the note's unit
//! (P20 widens them), 8 and 9 the library symbols 95 and 139, 7 nothing;
//! any other P6 is a library symbol drawn by draw_symbol at 0.833. P6 + 10
//! adds parentheses (symbol 208), moved out for an accidental and for dots.

use super::glyph::{clef_symbol, library_symbol};
use super::{c, Note};
use crate::canvas::Canvas;
use crate::display::Colour;
use crate::page::P3_UNIT;
use crate::document::{Document, ItemRef};
use crate::units::{real, trunc, Pos};

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
    let library = doc.symbols();
    let p6 = trunc(f64::from(item.p(6)));
    if note.alpha {
        alpha_head(doc, item, note, canvas);
        return;
    }
    let clef_head = |canvas: &mut Canvas<'_>, h: i32| {
        clef_symbol(canvas, library, h + FIRST_HEAD_SYMBOL, note.origin, note.width, 1.0, note.unit);
    };
    let library_head = |canvas: &mut Canvas<'_>, n: i32| {
        let size = c(LIBRARY_HEAD_SIZE);
        library_symbol(canvas, library, n, note.origin, size, size, note.unit);
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
    let size = match item.p(15) {
        0.0 => 1.0,
        p15 => f64::from(p15),
    };
    let p3 = real(note.unit * c(1.45) / 25.0 + real(note.origin.x / P3_UNIT));
    let p4 = real(f64::from(item.p(4)) - c(1.68));
    let at = Pos::new(real(p3 * P3_UNIT), staff.y(p4));
    let symbol = if hollow { HOLLOW_ALPHA_HEAD } else { ALPHA_HEAD };
    library_symbol(canvas, doc.symbols(), symbol, at, real(size * c(0.58)), real(size * c(0.475)), staff.step);
}

/// draw_box type 0, filled, 2.4 by 0.35 half-widths of 3.5 steps, centred
/// 210 units (at size 1) right of the note, emitted at once in white.
fn staff_line_mask(note: &Note, staff_step: f64, canvas: &mut Canvas<'_>) {
    let centre = Pos::new(real(staff_step / 25.0 * 210.0 + note.origin.x), note.origin.y);
    let half_width = real(note.step * 3.5 * c(2.4));
    let half_height = real(note.step * 3.5 * c(0.35));
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

/// The colour 0x4F1F69 emits the mask in (COLORREF 0xFDFDFD).
const MASK_COLOUR: Colour = Colour { r: 253, g: 253, b: 253 };

fn parentheses(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let left = match trunc(f64::from(item.p(5))) % 10 {
        0 => c(LEFT_PARENTHESIS),
        DOUBLE_FLAT => real(real(c(LEFT_PARENTHESIS) - c(ACCIDENTAL_ROOM)) - c(DOUBLE_FLAT_ROOM)),
        _ => real(c(LEFT_PARENTHESIS) - c(ACCIDENTAL_ROOM)),
    };
    let p9 = trunc(f64::from(item.p(9)));
    let right = match (p9 >= 10, p9 % 100 >= 20) {
        (_, true) => c(RIGHT_PARENTHESIS_DOTS),
        (true, false) => c(RIGHT_PARENTHESIS_DOT),
        (false, false) => c(RIGHT_PARENTHESIS),
    };
    let right = if note.width == 1.0 { right } else { real(note.width * c(NORMAL_WIDTH) + (right - c(NORMAL_WIDTH))) };
    let size = c(PARENTHESIS_SIZE);
    [(left, size), (right, -size)].into_iter().for_each(|(offset, sx)| {
        let at = Pos::new(real(note.unit * offset + note.origin.x), note.origin.y);
        library_symbol(canvas, doc.symbols(), PARENTHESIS_SYMBOL, at, sx, size, note.unit);
    });
}
