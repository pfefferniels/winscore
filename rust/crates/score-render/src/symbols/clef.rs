//! draw_clef 0x431AE0: the entry most item codes use to draw a library symbol.
//!
//! Callers other than code 3 (IP1 != 3) on the screen take a fast path for
//! symbols 0–44: the symbol at the caller's point, scaled by STEP/4 times the
//! size factors. Read by impl-notes from the routine and verified point for
//! point on note heads. The code-3 branch (clefs, and the brace through
//! barline_brace) and symbols from 45 on, which go through draw_symbol
//! 0x4293F0 with the per-symbol size factors, are not ported here yet.

use crate::canvas::Canvas;
use crate::symbols::{draw_symbol, Scale, SymbolLibrary};
use crate::units::{real, Pos};

/// The last symbol drawn through the fast path.
pub const LAST_FAST_SYMBOL: i32 = 44;

/// Draws symbol `number` at `origin` with size factors `sx`, `sy` (0 read
/// as 1, and `sy` = 0 as `sx`) on a staff whose step unit is `step`.
/// Returns false, drawing nothing, for symbols the port does not cover yet
/// or that the library lacks.
pub fn draw_clef(
    canvas: &mut Canvas<'_>,
    library: &SymbolLibrary,
    origin: Pos,
    number: i32,
    sx: f64,
    sy: f64,
    step: f64,
) -> bool {
    let sx = if sx == 0.0 { 1.0 } else { sx };
    let sy = if sy == 0.0 { sx } else { sy };
    match library.symbol(number) {
        Some(symbol) if number <= LAST_FAST_SYMBOL => {
            let scale = Scale { x: real(step * sx) / 4.0, y: real(step * sy) / 4.0 };
            draw_symbol(canvas, symbol, origin, scale);
            true
        }
        _ => false,
    }
}
