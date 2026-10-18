//! draw_symbol 0x4293F0 for symbols drawn from the library: size factors,
//! the normal size of the symbol, rotation and thickening around the
//! common core [`draw_symbol`].
//!
//! In [`crate::Style::Refined`] the outlines are smoothed ([`Outline`]),
//! thickness is a wider pen instead of shifted copies, and an item whose
//! symbol is missing shows a placeholder on the screen.

use std::f32::consts::PI;

use crate::canvas::{Canvas, TextString, TextStyle, TEXT_BASELINE};
use crate::codes;
use crate::display::{print_pen, Colour, Point, PEN};
use crate::document::{Document, ItemRef};
use crate::geometry::{rotate_points, thicken};
use crate::page::{is_recto, RECTO_SHIFT};
use score_format::Symbol;
use crate::staff::STEP_UNIT;
use crate::symbols::smooth::Outline;
use crate::symbols::{draw_symbol, Scale};
use crate::units::{amod, nint, real, trunc, Pos};

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
    let pixels = if number >= FIRST_THIN_SYMBOL { context.pixels - 1 } else { context.pixels };
    let call = SymbolCall { size_x, ..*call };
    draw_scaled_symbol(doc, canvas, symbol, at, step, &call, normal_size(number), pixels);
}

/// The size draw_symbol draws library symbol `number` at, before the size
/// factors: 0.3 of the library size for 50-4999 (0x42A1A2).
pub fn normal_size(number: i32) -> f64 {
    if SMALL_SYMBOLS.contains(&number) {
        f64::from(SMALL_SYMBOL_SIZE)
    } else {
        1.0
    }
}

/// The drawing common to library and user symbols (draw_symbol after it
/// has found the points): sizes (AMOD 100, 0 read as 1, the vertical size
/// 0 read as the horizontal) times `normal_size` and STEP, then rotation
/// and thickening (`pixels` > 0 thickens on the screen like P8 = 101 ×
/// pixels). The refined style draws as [`draw_refined`] describes.
#[allow(clippy::too_many_arguments)]
pub fn draw_scaled_symbol(
    doc: &Document<'_>,
    canvas: &mut Canvas<'_>,
    symbol: &Symbol,
    at: Pos,
    step: f64,
    call: &SymbolCall,
    normal_size: f64,
    pixels: i32,
) {
    let scale = library_unit(step, call, normal_size);
    if doc.refined() {
        draw_refined(canvas, symbol, at, scale, call, pixels);
        return;
    }
    let start = canvas.buffer_mut().len();
    draw_symbol(canvas, symbol, at, scale);
    if trunc(call.rotation) != 0 {
        rotate_points(&mut canvas.buffer_mut()[start..], at.to_point(), call.rotation as f32);
    }
    let thickness = match call.thickness {
        0 if doc.screen() && pixels > 0 => pixels * PIXELS_TO_THICKNESS,
        t => t,
    };
    if thickness != 0 {
        thicken(canvas.buffer_mut(), start, thickness);
    }
}

/// Engine units per library unit for `call` on a staff with step unit
/// `step`: the size factors (AMOD 100, 0 read as 1, the vertical size 0
/// read as the horizontal) times `normal_size` and STEP, as REAL*4.
pub fn library_unit(step: f64, call: &SymbolCall, normal_size: f64) -> Scale {
    let size_x = match real(amod(call.size_x, SIZE_FLAGS)) {
        0.0 => 1.0,
        s => s,
    };
    let size_y = if call.size_y == 0.0 { size_x } else { call.size_y };
    let (size_x, size_y) =
        if normal_size == 1.0 { (size_x, size_y) } else { (real(size_x * normal_size), real(size_y * normal_size)) };
    Scale { x: real(step * size_x), y: real(step * size_y) }
}

/// Distance between the copies thicken 0x42A8AE adds, in engine units.
const COPY_STEP: f32 = 14.0;
/// The narrowest pen of the refined style: the engine's own one-unit pen.
const MIN_PEN: f32 = 1.0;

/// The refined drawing of a symbol: the smoothed outline, drawn once. Where
/// the engine thickens by copies, the outline gets a wider pen
/// ([`refined_pen`]) on every medium, as SCORE's print output does; P8 < 0
/// still turns filled parts into outlines (0x42A8AE). A symbol without a
/// pen of its own takes the caller's; one with a pen of its own gives the
/// caller's back afterwards (0x4D4F3F returns SCORE's print pen to the
/// default instead, losing a pen the caller had set).
fn draw_refined(canvas: &mut Canvas<'_>, symbol: &Symbol, at: Pos, scale: Scale, call: &SymbolCall, pixels: i32) {
    let start = canvas.buffer_mut().len();
    let width = refined_pen(call.thickness, pixels);
    let caller = canvas.width();
    if let Some(width) = width {
        canvas.set_width(width);
    }
    Outline::cached(symbol).draw(canvas, at, scale);
    if trunc(call.rotation) != 0 {
        rotate_points(&mut canvas.buffer_mut()[start..], at.to_point(), call.rotation as f32);
    }
    if call.thickness < 0 {
        thicken(canvas.buffer_mut(), start, call.thickness);
    }
    if width.is_some() {
        canvas.set_width(caller);
    }
}

/// The pen of a symbol in the refined style, `None` for the default one.
///
/// When printing, draw_symbol hands its pixel thickness to the print-width
/// marker 0x4D4ED2 instead of thickening (0x42A1E3 for library symbols,
/// after taking one off from symbol 45 on; 0x42A382 for user symbols): the
/// symbol is outlined with [`print_pen`]`(pixels)`, which is narrower than
/// the default for negative values, so symbols from 45 on with IP10 = 0
/// print with the pen of a marker of -1. P8 = 100·v + h > 0 copies the
/// points 2v times up and down and 2h times sideways, 14, 28, … units
/// apart, on every medium; a round pen cannot reach further one way than
/// the other, so it takes their reach averaged over all directions,
/// 14·(2/π)·√(v² + h²) on each side, which adds as much ink round a curve
/// as the copies do.
pub fn refined_pen(thickness: i32, pixels: i32) -> Option<f32> {
    let reach = if thickness > 0 {
        let (v, h) = ((thickness / 100) as f32, (thickness % 100) as f32);
        COPY_STEP * 2.0 / PI * v.hypot(h)
    } else {
        0.0
    };
    if pixels == 0 && reach == 0.0 {
        return None;
    }
    let pen = if pixels == 0 { PEN } else { print_pen(pixels as f32) };
    Some((pen + 2.0 * reach).max(MIN_PEN))
}

/// Whether the refined style shows placeholders for missing symbols: on
/// the screen only.
pub fn shows_missing(doc: &Document<'_>) -> bool {
    doc.refined() && doc.screen()
}

/// Whether draw_symbol has nothing to draw for symbol `number`: it is
/// neither in the libraries nor one of the words it writes as text.
pub fn is_missing(doc: &Document<'_>, number: i32) -> bool {
    !is_text_symbol(number) && doc.symbols().symbol(number.max(0)).is_none()
}

/// The placeholder's box, light grey, and the grey of its label.
const MISSING_BOX: Colour = Colour { r: 0xE4, g: 0xE4, b: 0xE4 };
const MISSING_LABEL: Colour = Colour { r: 0x80, g: 0x80, b: 0x80 };
/// Side of the box in library units, about the size of a symbol.
const MISSING_SIZE: f64 = 60.0;
/// Label height as a part of the box, at most this part of the box's
/// width, a character's width as a part of the height (generous for
/// Helvetica), and the baseline below the middle as a part of the height.
const LABEL_HEIGHT: f64 = 0.36;
const LABEL_WIDTH: f64 = 0.8;
const LABEL_ADVANCE: f64 = 0.64;
const LABEL_DROP: f64 = 0.36;

/// What the refined style draws on the screen for an item on `staff` whose
/// symbol is missing (a library or user symbol file that is not there), so
/// that it can be seen and picked: a light grey box of about a symbol's
/// size, `unit` engine units per library unit, from `at` to the right and
/// centred on its level, with `label` (the symbol's number) in it. The box
/// takes the canvas colour: callers draw nothing else for the item.
pub fn draw_missing_symbol(canvas: &mut Canvas<'_>, staff: i32, at: Pos, unit: Scale, label: &str) {
    let (width, height) = (MISSING_SIZE * unit.x.abs(), MISSING_SIZE * unit.y.abs());
    let (left, right, bottom, top) = (at.x, at.x + width, at.y - height / 2.0, at.y + height / 2.0);
    canvas.colour = MISSING_BOX;
    canvas.fill([[Pos::new(left, bottom), Pos::new(right, bottom), Pos::new(right, top), Pos::new(left, top)]]);
    let characters = label.chars().count().max(1) as f64;
    let size = (height * LABEL_HEIGHT).min(LABEL_WIDTH * width / (characters * LABEL_ADVANCE));
    // Text positions get the recto shift from their module, not from the canvas.
    let recto = if is_recto(staff) { RECTO_SHIFT } else { 0 };
    let x = recto + nint(left + (width - characters * LABEL_ADVANCE * size) / 2.0);
    let baseline = nint(at.y - LABEL_DROP * size);
    let style = TextStyle {
        font: "Helvetica".to_string(),
        height: size as f32,
        width: 0.0,
        escapement: 0,
        weight: 400,
        italic: false,
        underline: false,
        outline: false,
    };
    let box_colour = std::mem::replace(&mut canvas.colour, MISSING_LABEL);
    canvas.text(&style, [TextString { at: Point::new(x, baseline - TEXT_BASELINE), text: label.to_string() }]);
    canvas.colour = box_colour;
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

/// Whether draw_symbol writes symbol `number` as text: its text path is not
/// ported yet, so nothing is drawn for these.
pub fn is_text_symbol(number: i32) -> bool {
    TEXT_SYMBOLS.iter().any(|&(n, _)| n == number)
}

/// The text draw_symbol writes for symbol `number`, in SCORE's text coding.
pub fn symbol_text(number: i32) -> Option<&'static str> {
    TEXT_SYMBOLS.iter().find(|&&(n, _)| n == number).map(|&(_, text)| text)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::canvas::Stream;
    use crate::display::{ItemId, Shape, ShapeKind};
    use crate::document::{Medium, Options};
    use score_format::{Item, MusFile, Word};

    /// A size-1 staff 1 and a code-9 item with parameters `symbol`.
    fn file(symbol: &[f32]) -> MusFile {
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        let mut file = MusFile::empty();
        file.items = vec![words(&[8.0, 1.0, 0.0, 0.0, 1.0]), words(symbol)];
        file
    }

    fn shapes(file: &MusFile, options: Options) -> Vec<Shape> {
        let list = crate::render(&Document::with_options(file, options));
        list.shapes.into_iter().filter(|s| s.source == Some(ItemId(1))).collect()
    }

    fn points(shapes: &[Shape]) -> usize {
        shapes.iter().flat_map(|s| &s.paths).map(Vec::len).sum()
    }

    /// The fermata (31, below 45) with P10 = 1: five copies on the engine's
    /// screen, one outline with the print pen of a marker of 1 in the refined style.
    #[test]
    fn pixel_thickness_is_a_pen_not_copies() {
        let fermata = file(&[9.0, 1.0, 20.0, 4.0, 31.0, 0.0, 0.0, 0.0, 0.0, 1.0]);
        let engine = shapes(&fermata, Options::ENGINE);
        assert_eq!(engine.len(), 10);
        assert!(engine.iter().all(|s| s.width == 0.0));
        for medium in [Medium::Screen, Medium::Print] {
            let refined = shapes(&fermata, Options { medium, ..Options::REFINED });
            assert_eq!(refined.len(), 2, "{medium:?}");
            assert!(refined.iter().all(|s| s.width == print_pen(1.0)), "{refined:?}");
            assert!(points(&refined) > points(&engine[..2]), "smoothed outlines have more points");
        }
    }

    #[test]
    fn copies_become_a_round_pen_and_outlines_stay_outlines() {
        let thick = shapes(&file(&[9.0, 1.0, 20.0, 4.0, 31.0, 0.0, 0.0, 101.0]), Options::REFINED);
        assert_eq!(thick.len(), 2);
        let reach = COPY_STEP * 2.0 / PI * 2.0_f32.sqrt();
        assert!(thick.iter().all(|s| (s.width - (PEN + 2.0 * reach)).abs() < 1e-3), "{}", thick[0].width);
        let outline = shapes(&file(&[9.0, 1.0, 20.0, 4.0, 31.0, 0.0, 0.0, -1.0]), Options::REFINED);
        assert!(outline.iter().all(|s| s.kind == ShapeKind::Stroke && s.width == 0.0));
        assert!(outline.iter().flat_map(|s| &s.paths).all(|p| p.first() == p.last()), "closed outlines");
    }

    /// From symbol 45 on, draw_symbol prints with the marker one below IP10.
    #[test]
    fn symbols_from_45_on_print_one_pen_step_thinner() {
        assert_eq!(refined_pen(0, 0), None);
        assert_eq!(refined_pen(0, -1), Some(print_pen(-1.0)));
        assert_eq!(refined_pen(0, -9), Some(MIN_PEN));
        let forte = shapes(&file(&[9.0, 1.0, 20.0, 4.0, 56.0]), Options::REFINED);
        assert!(forte.iter().all(|s| s.width == print_pen(-1.0)));
        let dot = shapes(&file(&[9.0, 1.0, 20.0, 4.0, 24.0]), Options::REFINED);
        assert!(dot.iter().all(|s| s.width == 0.0));
    }

    /// A symbol with a pen of its own gives the caller's pen back; one
    /// without draws with it.
    #[test]
    fn the_callers_pen_comes_back() {
        let f = file(&[9.0, 1.0, 20.0, 4.0, 56.0]);
        let doc = Document::with_options(&f, Options::REFINED);
        let item = doc.item(ItemId(1)).expect("the symbol");
        let mut stream = Stream::default();
        let mut canvas = Canvas::new(&mut stream, item.id, 1, Colour::BLACK);
        canvas.set_width(40.0);
        let context = ItemContext::of(item);
        let origin = Pos::new(0.0, 0.0);
        draw_library_symbol(&doc, &context, &mut canvas, origin, STEP_UNIT, &SymbolCall::sized(56, 0.0, 0.0));
        draw_library_symbol(&doc, &context, &mut canvas, origin, STEP_UNIT, &SymbolCall::sized(24, 0.0, 0.0));
        canvas.segment(origin, Pos::new(100.0, 0.0));
        canvas.flush();
        let widths: Vec<f32> = stream.list.shapes.iter().map(|s| s.width).collect();
        assert_eq!(widths, [print_pen(-1.0), 40.0, 40.0]);
    }

    #[test]
    fn missing_symbols_show_a_box_on_the_screen_only() {
        let missing = file(&[9.0, 1.0, 20.0, 4.0, 710.0]);
        let list = crate::render(&Document::with_options(&missing, Options::REFINED));
        let shapes: Vec<&Shape> = list.shapes.iter().filter(|s| s.source == Some(ItemId(1))).collect();
        assert_eq!(shapes.len(), 1);
        assert_eq!((shapes[0].kind, shapes[0].colour), (ShapeKind::Fill, MISSING_BOX));
        let label = list.texts.iter().find(|t| t.source == Some(ItemId(1))).expect("a label");
        assert_eq!(label.strings[0].text, "710");
        for options in [Options::ENGINE, Options { medium: Medium::Print, ..Options::REFINED }] {
            let list = crate::render(&Document::with_options(&missing, options));
            assert!(list.shapes.iter().all(|s| s.source != Some(ItemId(1))), "{options:?}");
            assert!(list.texts.iter().all(|t| t.source != Some(ItemId(1))), "{options:?}");
        }
    }
}
