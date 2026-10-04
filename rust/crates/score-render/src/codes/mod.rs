//! One module per item code. Each exposes
//!
//! ```ignore
//! pub fn render(doc: &Document, item: ItemRef, canvas: &mut Canvas)
//! ```
//!
//! and draws only its own item; the canvas tags every shape and text run with
//! the item's id. A module is owned by one implementer, and adding a code
//! touches no file but its own: the table below already names every module.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};

pub mod barline;
pub mod beam;
pub mod boxes;
pub mod clef;
pub mod eps;
pub mod key;
pub mod line;
pub mod meter;
pub mod note;
pub mod number;
pub mod rest;
pub mod slur;
pub mod staff;
pub mod symbol;
pub mod text;
pub mod trill;
pub mod user_symbol;

pub const NOTE: i32 = 1;
pub const REST: i32 = 2;
pub const CLEF: i32 = 3;
pub const LINE: i32 = 4;
pub const SLUR: i32 = 5;
pub const BEAM: i32 = 6;
pub const TRILL: i32 = 7;
pub const STAFF: i32 = 8;
pub const SYMBOL: i32 = 9;
pub const NUMBER: i32 = 10;
pub const USER_SYMBOL: i32 = 11;
pub const BOX: i32 = 12;
pub const BARLINE: i32 = 14;
pub const EPS: i32 = 15;
pub const TEXT: i32 = 16;
pub const KEY: i32 = 17;
pub const METER: i32 = 18;

pub type RenderFn = fn(&Document<'_>, ItemRef<'_>, &mut Canvas<'_>);

/// The module that draws items with code `code`; code 13 does not exist.
pub fn renderer(code: i32) -> Option<RenderFn> {
    let f: RenderFn = match code {
        NOTE => note::render,
        REST => rest::render,
        CLEF => clef::render,
        LINE => line::render,
        SLUR => slur::render,
        BEAM => beam::render,
        TRILL => trill::render,
        STAFF => staff::render,
        SYMBOL => symbol::render,
        NUMBER => number::render,
        USER_SYMBOL => user_symbol::render,
        BOX => boxes::render,
        BARLINE => barline::render,
        EPS => eps::render,
        TEXT => text::render,
        KEY => key::render,
        METER => meter::render,
        _ => return None,
    };
    Some(f)
}
