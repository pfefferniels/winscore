//! Note heads and their parentheses (0x4F14B0).
//!
//! Heads 0–6 are symbols 11–17 drawn through draw_clef at the note's unit
//! (P20 widens them), 8 and 9 the library symbols 95 and 139, 7 nothing;
//! any other P6 is a library symbol drawn by draw_symbol at 0.833. P6 + 10
//! adds parentheses (symbol 208), moved out for an accidental and for dots.

use super::glyph::{clef_symbol, library_symbol};
use super::{c, Note};
use crate::canvas::Canvas;
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
