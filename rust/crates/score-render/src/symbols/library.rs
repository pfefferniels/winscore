//! draw_symbol 0x4293F0 for symbols drawn from the library: size factors,
//! the normal size of the symbol, rotation and thickening around the
//! common core [`draw_symbol`].

use crate::canvas::{BufferPoint, Canvas, Pen};
use crate::codes;
use crate::display::Point;
use crate::document::{Document, ItemRef};
use crate::geometry::rotate_points;
use crate::staff::STEP_UNIT;
use crate::symbols::{draw_symbol, Scale};
use crate::units::{real, trunc, Pos};

/// What draw_symbol is called with besides the position. Sizes are REAL*4
/// values.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct SymbolCall {
    pub number: i32,
    /// Horizontal size factor (P6): 0 reads as 1, the hundreds carry
    /// part-extractor flags, negative mirrors.
    pub size_x: f64,
    /// Vertical size factor (P7): 0 reads as the horizontal one.
    pub size_y: f64,
    /// `X0Y` (P8): X vertical and Y horizontal thickening steps; negative
    /// draws outlines only.
    pub thickness: i32,
    /// Clockwise rotation in degrees (P9), applied when its integer part is not zero.
    pub rotation: f64,
}

impl SymbolCall {
    /// Symbol `number` at a size, neither rotated nor thickened, as the
    /// routines drawing symbols for other codes call draw_symbol.
    pub fn sized(number: i32, size_x: f64, size_y: f64) -> Self {
        Self { number, size_x, size_y, thickness: 0, rotation: 0.0 }
    }
}

/// What draw_symbol and draw_clef read from the engine's current-item
/// globals rather than from their arguments. [`ItemContext::of`] gives the
/// item's own values; callers that rewrite those globals before drawing
/// change the fields accordingly.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct ItemContext {
    /// IP1.
    pub code: i32,
    /// IP2.
    pub staff: i32,
    /// IP4: |IP4| >= 100 makes clef types 0-5 mini clefs.
    pub ip4: i32,
    /// IP10, or trunc(P16) for numbers and meters: a positive pixel
    /// thickness thickens on the screen.
    pub pixels: i32,
    /// IP11: hides symbols 1300-1304 in print.
    pub ip11: i32,
}

impl ItemContext {
    pub fn of(item: ItemRef<'_>) -> Self {
        let ip = |n: usize| trunc(f64::from(item.p(n)));
        let pixels = match item.code() {
            codes::NUMBER | codes::METER => ip(16),
            _ => ip(10),
        };
        Self { code: item.code(), staff: item.staff(), ip4: ip(4), pixels, ip11: ip(11) }
    }
}

/// Symbols 50-4999 are drawn at 0.3 of their library size (0x42A1A2).
const SMALL_SYMBOLS: std::ops::RangeInclusive<i32> = 50..=4999;
const SMALL_SYMBOL_SIZE: f32 = 0.3;
/// From this symbol on the pixel thickness counts one less.
const FIRST_THIN_SYMBOL: i32 = 45;
/// Symbols drawn at the size of a size-1 staff whatever their staff.
const STAFF_INDEPENDENT_SYMBOLS: std::ops::RangeInclusive<i32> = 1300..=1304;
/// draw_symbol's size factors drop their hundreds (part-extractor flags).
const SIZE_FLAGS: f64 = 100.0;
/// A positive pixel thickness thickens like P8 = `pixels` × 101 on the screen.
const PIXELS_TO_THICKNESS: i32 = 101;

/// draw_symbol 0x4293F0 for a symbol drawn from the library, at `at` on a
/// staff whose step unit is `step` (the engine's STEP). Text symbols and the
/// code-9 term library (3000-3099) are not drawn here; neither is the
/// rotation centre code 16 uses.
pub fn draw_library_symbol(
    doc: &Document<'_>,
    context: &ItemContext,
    canvas: &mut Canvas<'_>,
    at: Pos,
    step: f64,
    call: &SymbolCall,
) {
    let number = call.number.max(0);
    let size_x = if STAFF_INDEPENDENT_SYMBOLS.contains(&number) {
        let hidden = context.code == codes::NOTE || (context.ip11 != 0 && !doc.screen());
        if hidden {
            return;
        }
        match context.staff {
            0 => call.size_x,
            staff => real(STEP_UNIT / doc.staves.get(staff).step),
        }
    } else {
        call.size_x
    };
    if is_text_symbol(number) {
        return;
    }
    let Some(symbol) = doc.symbols().symbol(number) else {
        return;
    };
    let size_x = match real(amod(size_x, SIZE_FLAGS)) {
        0.0 => 1.0,
        s => s,
    };
    let size_y = if call.size_y == 0.0 { size_x } else { call.size_y };
    let (size_x, size_y) = if SMALL_SYMBOLS.contains(&number) {
        let small = f64::from(SMALL_SYMBOL_SIZE);
        (real(size_x * small), real(size_y * small))
    } else {
        (size_x, size_y)
    };
    let pixels = if number >= FIRST_THIN_SYMBOL { context.pixels - 1 } else { context.pixels };

    let start = canvas.buffer_mut().len();
    draw_symbol(canvas, symbol, at, Scale { x: real(step * size_x), y: real(step * size_y) });
    if trunc(call.rotation) != 0 {
        rotate_points(&mut canvas.buffer_mut()[start..], at.to_point(), call.rotation as f32);
    }
    let thickness = match call.thickness {
        0 if doc.screen() && pixels > 0 => pixels * PIXELS_TO_THICKNESS,
        t => t,
    };
    thicken(canvas.buffer_mut(), start, thickness);
}

/// Symbols draw_symbol writes as text (table 0x78EAAC; strings at 0x78EA10).
const TEXT_SYMBOLS: [(i32, &str); 21] = [
    (66, "pizz."),
    (67, "arco"),
    (78, "a tempo"),
    (45, "8va"),
    (46, "8ba"),
    (47, "15ma"),
    (63, "cresc."),
    (64, "dim."),
    (65, "rit."),
    (68, "accel."),
    (72, "gliss."),
    (73, "molto"),
    (79, "espr."),
    (80, "meno"),
    (81, "pi>>u"),
    (85, "subito"),
    (86, "poco"),
    (111, "decresc."),
    (113, "rall."),
    (114, "mosso"),
    (276, "G.P."),
];

/// Whether draw_symbol writes symbol `number` as text: these go through
/// draw_text, which is not ported yet, so nothing is drawn for them.
pub fn is_text_symbol(number: i32) -> bool {
    TEXT_SYMBOLS.iter().any(|&(n, _)| n == number)
}

/// The text draw_symbol writes for symbol `number`, in SCORE's text coding.
pub fn symbol_text(number: i32) -> Option<&'static str> {
    TEXT_SYMBOLS.iter().find(|&&(n, _)| n == number).map(|&(_, text)| text)
}

/// Fortran AMOD (amod 0x54AABA): x - trunc(x / y) * y.
fn amod(x: f64, y: f64) -> f64 {
    x - f64::from(trunc(x / y)) * y
}

/// Distance between thickening copies (0x42A8AE).
const THICKENING_STEP: i32 = 14;
/// Points this far left are not moved by horizontal thickening.
const UNMOVED_X: i32 = -200_792;

/// Thickening (0x42A8AE) of the points from `start` on. `X0Y` adds 2X
/// copies shifted vertically by +14, -14, +28, -28, … and then 2Y shifted
/// horizontally, each a copy of the original points; a negative value
/// turns every filled path into an outline.
fn thicken(buffer: &mut Vec<BufferPoint>, start: usize, thickness: i32) {
    if thickness == 0 {
        return;
    }
    if thickness < 0 {
        buffer[start..]
            .iter_mut()
            .filter(|p| matches!(p.pen, Pen::Fill | Pen::SubPath))
            .for_each(|p| p.pen = Pen::Stroke);
        return;
    }
    let original = buffer[start..].to_vec();
    let offsets = |copies: i32| (0..copies).map(|i| THICKENING_STEP * (i / 2 + 1) * if i % 2 == 0 { 1 } else { -1 });
    let vertical: Vec<BufferPoint> = offsets(2 * (thickness / 100))
        .flat_map(|dy| original.iter().map(move |p| BufferPoint { at: Point::new(p.at.x, p.at.y + dy), ..*p }))
        .collect();
    let horizontal: Vec<BufferPoint> = offsets(2 * (thickness % 100))
        .flat_map(|dx| {
            original.iter().map(move |p| {
                let x = if p.at.x >= UNMOVED_X { p.at.x + dx } else { p.at.x };
                BufferPoint { at: Point::new(x, p.at.y), ..*p }
            })
        })
        .collect();
    buffer.extend(vertical);
    buffer.extend(horizontal);
}

#[cfg(test)]
mod tests {
    use super::*;

    fn points(xs: &[i32]) -> Vec<BufferPoint> {
        xs.iter().map(|&x| BufferPoint { at: Point::new(x, 0), pen: Pen::Fill }).collect()
    }

    #[test]
    fn thickening_alternates_sides_and_copies_the_originals() {
        let mut buffer = points(&[0]);
        thicken(&mut buffer, 0, 102);
        let at: Vec<(i32, i32)> = buffer.iter().map(|p| (p.at.x, p.at.y)).collect();
        assert_eq!(at, [(0, 0), (0, 14), (0, -14), (14, 0), (-14, 0), (28, 0), (-28, 0)]);
    }

    #[test]
    fn negative_thickness_outlines() {
        let mut buffer = points(&[0, 1]);
        thicken(&mut buffer, 1, -1);
        assert_eq!(buffer[0].pen, Pen::Fill);
        assert_eq!(buffer[1].pen, Pen::Stroke);
    }

    #[test]
    fn amod_keeps_the_sign() {
        assert_eq!(amod(101.5, 100.0), 1.5);
        assert_eq!(amod(-250.0, 100.0), -50.0);
    }
}
