//! draw_clef 0x431AE0: the entry most item codes use to draw a library symbol.
//!
//! The placement ([`clef_placement`]) and drawing ([`draw_clef_symbol`])
//! serve every caller; [`draw_clef`] combines them. What draw_clef does only
//! for code-3 items (octave numbers, tablature clefs) is in `codes::clef`.
//! The routine's table-driven path for OUTPUT_MODE 0 (before a score is
//! loaded) and its P7 = 99 picture are not ported.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::library::{draw_library_symbol, SymbolCall};
use crate::units::{real, trunc, Pos};

/// Step units (7 per scale step) draw_clef adds to the P4 = 0 level of
/// clef types 0-5: they hang on the bottom line.
const CLEF_LIFT: f32 = 21.0;
/// The tenor clef is the alto clef two scale steps higher.
const TENOR_LIFT: f32 = 14.0;
const ALTO: i32 = 2;
const TENOR: i32 = 3;
/// Clef types 0-5 are placed by draw_clef; higher numbers are other symbols.
const LAST_CLEF_TYPE: i32 = 5;
/// Mini clefs (|IP4| >= 100): size factor and extra lift by clef type (table 0x78F30C).
const MINI_P4: i32 = 100;
const MINI_SIZE: f32 = 0.8;
const MINI_LIFT: [f32; 6] = [0.35, 8.75, 5.6, 5.6, 5.6, 0.35];
/// Symbols below this number are drawn at a quarter of their library size.
pub const FIRST_FULL_SIZE_SYMBOL: i32 = 45;
const QUARTER: f32 = 0.25;

/// Where draw_clef puts a symbol, and at which size (REAL*4 factors).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct ClefPlacement {
    /// The library symbol: the tenor clef becomes the alto clef.
    pub number: i32,
    pub at: Pos,
    pub size_x: f64,
    pub size_y: f64,
}

/// draw_clef's placement of symbol `number` (the clef type for code 3) at
/// the item's reference point `at` on a staff with step unit `step`: sizes
/// default to 1 and to each other; types 0-5 hang on the bottom line, mini
/// clefs (|IP4| >= 100) are smaller and lifted per type, the tenor clef is
/// the alto clef two steps up.
pub fn clef_placement(item: ItemRef<'_>, at: Pos, step: f64, number: i32, size_x: f64, size_y: f64) -> ClefPlacement {
    let size_x = if size_x == 0.0 { 1.0 } else { size_x };
    let size_y = if size_y == 0.0 { size_x } else { size_y };
    if number > LAST_CLEF_TYPE {
        return ClefPlacement { number, at, size_x, size_y };
    }
    let mini = trunc(f64::from(item.p(4))).abs() >= MINI_P4;
    let (size_x, size_y, lift) = if mini {
        let size = real(size_x * f64::from(MINI_SIZE));
        let kind = number.max(0) as usize;
        (size, size, real(f64::from(CLEF_LIFT) + f64::from(MINI_LIFT[kind])))
    } else {
        (size_x, size_y, f64::from(CLEF_LIFT))
    };
    let (number, lift) = match number {
        TENOR => (ALTO, real(lift + f64::from(TENOR_LIFT))),
        n => (n, lift),
    };
    ClefPlacement { number, at: Pos::new(at.x, real(step * lift + at.y)), size_x, size_y }
}

/// draw_clef's drawing of a placed symbol through draw_symbol: below symbol
/// 45 at a quarter of the size, from 45 on at the size given.
pub fn draw_clef_symbol(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    placement: &ClefPlacement,
    step: f64,
) {
    let (size_x, size_y) = if placement.number >= FIRST_FULL_SIZE_SYMBOL {
        (placement.size_x, placement.size_y)
    } else {
        let quarter = f64::from(QUARTER);
        let size_x = match real(placement.size_x * quarter) {
            0.0 => quarter,
            s => s,
        };
        (size_x, real(placement.size_y * quarter))
    };
    let call = SymbolCall::sized(placement.number, size_x, size_y, item);
    draw_library_symbol(doc, item, canvas, placement.at, step, &call);
}

/// draw_clef for symbol `number` at `at` with size factors `size` (P6, P7
/// style: 0 reads as 1, and the second 0 as the first), on a staff with step
/// unit `step`. `item` is the item being drawn: draw_clef and draw_symbol
/// read its P4 (mini clefs) and pixel thickness.
pub fn draw_clef(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    at: Pos,
    step: f64,
    number: i32,
    size: (f64, f64),
) {
    let placement = clef_placement(item, at, step, number, size.0, size.1);
    draw_clef_symbol(doc, item, canvas, &placement, step);
}
