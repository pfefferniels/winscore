//! The two ways a note draws a library symbol, with the engine's STEP
//! passed in: notes change STEP to their own unit around each call.
//!
//! Local stand-ins for the shared ports of draw_clef and draw_symbol, for
//! what notes and rests ask of them on the screen.

use crate::canvas::Canvas;
use crate::symbols::{draw_symbol, Scale, SymbolLibrary};
use crate::units::{real, Pos};

/// draw_clef keeps symbols up to this number in a table prescaled by 1/4.
const LAST_TABLE_SYMBOL: i32 = 44;

/// draw_symbol shrinks symbols from 50 on by this factor (0x42A1A2).
const SMALL_FROM: i32 = 50;
const SMALL_UNTIL: i32 = 5000;
const SMALL_FACTOR: f32 = 0.3;

/// draw_clef 0x431AE0 for a symbol that is not a clef (n > 5), as called
/// by code 1 and 2 items: `sx` 0 is read as 1, `sy` 0 as `sx`.
pub fn clef_symbol(canvas: &mut Canvas<'_>, library: &SymbolLibrary, n: i32, origin: Pos, sx: f64, sy: f64, step: f64) {
    let sx = if sx == 0.0 { 1.0 } else { sx };
    let sy = if sy == 0.0 { sx } else { sy };
    if n <= LAST_TABLE_SYMBOL {
        let scale = Scale { x: real(step * sx) / 4.0, y: real(step * sy) / 4.0 };
        draw(canvas, library, n, origin, scale);
    } else {
        library_symbol(canvas, library, n, origin, sx, sy, step);
    }
}

/// draw_symbol 0x4293F0 on the screen, with P8, P9 (rotation) and IP9 zero.
pub fn library_symbol(canvas: &mut Canvas<'_>, library: &SymbolLibrary, n: i32, origin: Pos, sx: f64, sy: f64, step: f64) {
    let shrink = |s: f64| if (SMALL_FROM..SMALL_UNTIL).contains(&n) { real(s * f64::from(SMALL_FACTOR)) } else { s };
    let scale = Scale { x: real(step * shrink(sx)), y: real(step * shrink(sy)) };
    draw(canvas, library, n, origin, scale);
}

fn draw(canvas: &mut Canvas<'_>, library: &SymbolLibrary, n: i32, origin: Pos, scale: Scale) {
    if let Some(symbol) = library.symbol(n) {
        draw_symbol(canvas, symbol, origin, scale);
    }
}
