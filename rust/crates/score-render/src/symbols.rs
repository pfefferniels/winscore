//! The symbol library and the drawing of library symbols.
//!
//! Code-9 symbol n is slot n % 10 of `LB{n / 10 * 10:04}.DRW` (`scorlib/symblist.txt`).
//! Clefs, accidentals, note heads, flags, rests, articulations and the brace
//! are all library symbols, drawn by draw_symbol 0x4293F0 (via draw_clef
//! 0x431AE0 for most item codes). [`draw_symbol`] is the common core: every
//! record of the symbol becomes one buffer point.

use std::collections::BTreeMap;
use std::sync::OnceLock;

use score_format::{DrwError, DrwLibrary, Symbol};

use crate::canvas::{BufferPoint, Canvas, Pen};
use crate::codes;
use crate::display::Point;
use crate::document::{Document, ItemRef};
use crate::geometry::rotate_points;
use crate::staff::STEP_UNIT;
use crate::units::{real, trunc, Pos};

include!(concat!(env!("OUT_DIR"), "/bundled_symbols.rs"));

const SYMBOLS_PER_FILE: i32 = 10;

#[derive(Debug, Clone, PartialEq, Default)]
pub struct SymbolLibrary {
    /// Libraries by the number of their first symbol.
    files: BTreeMap<i32, DrwLibrary>,
}

impl SymbolLibrary {
    /// Libraries from `(first symbol number, file contents)` pairs.
    pub fn from_files<'b>(files: impl IntoIterator<Item = (i32, &'b [u8])>) -> Result<Self, DrwError> {
        let files = files
            .into_iter()
            .map(|(first, bytes)| Ok((first, DrwLibrary::parse(bytes)?)))
            .collect::<Result<_, DrwError>>()?;
        Ok(Self { files })
    }

    /// The libraries shipped with WinScore 5.01, embedded at build time
    /// (empty without the `bundled-symbols` feature).
    pub fn bundled() -> &'static SymbolLibrary {
        static BUNDLED_LIBRARY: OnceLock<SymbolLibrary> = OnceLock::new();
        BUNDLED_LIBRARY.get_or_init(|| {
            SymbolLibrary::from_files(BUNDLED.iter().copied()).expect("the bundled symbol libraries parse")
        })
    }

    /// Symbol `number`, if its file exists and its slot has a name.
    pub fn symbol(&self, number: i32) -> Option<&Symbol> {
        let file = self.files.get(&(number - number.rem_euclid(SYMBOLS_PER_FILE)))?;
        let symbol = file.symbols.get(number.rem_euclid(SYMBOLS_PER_FILE) as usize)?;
        (!symbol.name.is_empty()).then_some(symbol)
    }
}

/// Engine units per library unit, per axis; negative values mirror.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Scale {
    pub x: f64,
    pub y: f64,
}

impl Scale {
    pub const fn uniform(factor: f64) -> Self {
        Self { x: factor, y: factor }
    }
}

/// The buffer pen for a library pen code: 1, 2, 3 start a polyline, a filled
/// object and a further path of it; 0 and the negative codes continue.
fn pen(code: i16) -> Pen {
    match code {
        1 => Pen::Stroke,
        2 => Pen::Fill,
        3 => Pen::SubPath,
        _ => Pen::Continue,
    }
}

/// Adds every record of `symbol` to the buffer in file order, at
/// f32(origin + scale × coordinate) per axis (truncated by add_point).
pub fn draw_symbol(canvas: &mut Canvas<'_>, symbol: &Symbol, origin: Pos, scale: Scale) {
    symbol.records.iter().for_each(|r| {
        let at = Pos::new(real(origin.x + f64::from(r.x) * scale.x), real(origin.y + f64::from(r.y) * scale.y));
        canvas.point(at, pen(r.pen));
    });
}

/// What draw_symbol 0x4293F0 is called with besides the position. Sizes
/// are REAL*4 values.
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
    /// Pixel thickness, see [`pixels`].
    pub pixels: i32,
}

impl SymbolCall {
    /// Symbol `number` at a size, neither rotated nor thickened, as the
    /// routines drawing symbols for other codes call draw_symbol.
    pub fn sized(number: i32, size_x: f64, size_y: f64, item: ItemRef<'_>) -> Self {
        Self { number, size_x, size_y, thickness: 0, rotation: 0.0, pixels: pixels(item) }
    }
}

/// The pixel thickness draw_symbol reads from the current item: IP10, or
/// trunc(P16) for numbers and meters.
pub fn pixels(item: ItemRef<'_>) -> i32 {
    match item.code() {
        codes::NUMBER | codes::METER => trunc(f64::from(item.p(16))),
        _ => trunc(f64::from(item.p(10))),
    }
}

/// Symbols from this number on are drawn at [`SMALL_SYMBOL_SIZE`] (up to [`LAST_SMALL_SYMBOL`]).
const FIRST_SMALL_SYMBOL: i32 = 50;
const LAST_SMALL_SYMBOL: i32 = 4999;
const SMALL_SYMBOL_SIZE: f32 = 0.3;
/// From this symbol on the pixel thickness counts one less.
const FIRST_THIN_SYMBOL: i32 = 45;
/// Symbols drawn at the size of a size-1 staff whatever their staff.
const STAFF_INDEPENDENT_SYMBOLS: std::ops::RangeInclusive<i32> = 1300..=1304;
/// draw_symbol's size factors drop their hundreds (part-extractor flags).
const SIZE_FLAGS: f64 = 100.0;

/// draw_symbol 0x4293F0 for a symbol drawn from the library: size factors,
/// the normal size 0.3 of symbols 50-4999, the staff's step unit `step`
/// (the engine's STEP), rotation and thickening. Text symbols and the
/// code-9 term library (3000-3099) are not drawn here; neither is the
/// rotation centre code 16 uses.
pub fn draw_library_symbol(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    at: Pos,
    step: f64,
    call: &SymbolCall,
) {
    let number = call.number.max(0);
    let size_x = if STAFF_INDEPENDENT_SYMBOLS.contains(&number) {
        let hidden = item.code() == codes::NOTE || (item.p(11) as i32 != 0 && !doc.screen());
        if hidden {
            return;
        }
        match item.staff() {
            0 => call.size_x,
            staff => real(STEP_UNIT / doc.staves.get(staff).step),
        }
    } else {
        call.size_x
    };
    let Some(symbol) = doc.symbols().symbol(number) else {
        return;
    };
    let size_x = match real(amod(size_x, SIZE_FLAGS)) {
        0.0 => 1.0,
        s => s,
    };
    let size_y = if call.size_y == 0.0 { size_x } else { call.size_y };
    let (size_x, size_y) = if (FIRST_SMALL_SYMBOL..=LAST_SMALL_SYMBOL).contains(&number) {
        let small = f64::from(SMALL_SYMBOL_SIZE);
        (real(size_x * small), real(size_y * small))
    } else {
        (size_x, size_y)
    };
    let pixels = if number >= FIRST_THIN_SYMBOL { call.pixels - 1 } else { call.pixels };

    let start = canvas.buffer_mut().len();
    draw_symbol(canvas, symbol, at, Scale { x: real(step * size_x), y: real(step * size_y) });
    if trunc(call.rotation) != 0 {
        rotate_points(&mut canvas.buffer_mut()[start..], at.to_point(), call.rotation as f32);
    }
    let thickness = match call.thickness {
        0 if doc.screen() && pixels > 0 => pixels * 101,
        t => t,
    };
    thicken(canvas.buffer_mut(), start, thickness);
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
        buffer[start..].iter_mut().filter(|p| matches!(p.pen, Pen::Fill | Pen::SubPath)).for_each(|p| p.pen = Pen::Stroke);
        return;
    }
    let original = buffer[start..].to_vec();
    let offsets = |copies: i32| {
        (0..copies).map(|i| THICKENING_STEP * (i / 2 + 1) * if i % 2 == 0 { 1 } else { -1 })
    };
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

/// Scale steps (in step units, 7 per step) draw_clef adds to the P4 = 0
/// level of clef types 0-5: the clef's reference is the bottom line.
const CLEF_LIFT: f32 = 21.0;
/// The tenor clef is the alto clef two scale steps higher.
const TENOR_LIFT: f32 = 14.0;
const ALTO: i32 = 2;
const TENOR: i32 = 3;
/// Clef types 0-5 are placed by draw_clef; higher numbers are other symbols.
const LAST_CLEF_TYPE: i32 = 5;
/// Mini clefs (|P4| >= 100): size factor and extra lift by clef type (table 0x78F30C).
const MINI_P4: i32 = 100;
const MINI_SIZE: f32 = 0.8;
const MINI_LIFT: [f32; 6] = [0.35, 8.75, 5.6, 5.6, 5.6, 0.35];
/// draw_clef draws symbols below this number at a quarter of their library size.
const FIRST_FULL_SIZE_CLEF_SYMBOL: i32 = 45;
const CLEF_SYMBOL_SIZE: f32 = 0.25;

/// Where draw_clef 0x431AE0 puts a clef-like symbol, and at which size.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct ClefPlacement {
    /// The library symbol: the tenor clef becomes the alto clef.
    pub number: i32,
    pub at: Pos,
    pub size_x: f64,
    pub size_y: f64,
}

/// draw_clef's placement of symbol `number` (the clef type for code 3) at
/// the item's reference point `at`: sizes default to 1 and to each other;
/// types 0-5 hang on the bottom line, mini clefs (|IP4| >= 100) are smaller
/// and lifted per type, the tenor clef is the alto clef two steps up.
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

/// draw_clef's drawing of a placed symbol: below symbol 45 at a quarter of
/// the library size, from 45 on at the size given.
pub fn draw_clef_symbol(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    placement: &ClefPlacement,
    step: f64,
) {
    let (size_x, size_y) = if placement.number >= FIRST_FULL_SIZE_CLEF_SYMBOL {
        (placement.size_x, placement.size_y)
    } else {
        let quarter = f64::from(CLEF_SYMBOL_SIZE);
        let size_x = match real(placement.size_x * quarter) {
            0.0 => quarter,
            s => s,
        };
        (size_x, real(placement.size_y * quarter))
    };
    let call = SymbolCall::sized(placement.number, size_x, size_y, item);
    draw_library_symbol(doc, item, canvas, placement.at, step, &call);
}

/// draw_clef 0x431AE0 as other codes use it (accidentals, the brace, …):
/// symbol `number` placed by [`clef_placement`] and drawn by
/// [`draw_clef_symbol`]. Code 3's octave numbers and tablature clefs are
/// in `codes::clef`.
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

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bundled_libraries_cover_the_symbol_list() {
        let library = SymbolLibrary::bundled();
        assert_eq!(library.symbol(5).map(|s| s.name.as_str()), Some("brace"));
        assert_eq!(library.symbol(11).map(|s| s.name.as_str()), Some("noir"));
        assert_eq!(library.symbol(21).map(|s| s.name.as_str()), Some("wedge"));
        assert!(library.symbol(-1).is_none());
    }
}
