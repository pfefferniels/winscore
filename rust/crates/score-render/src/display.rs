//! The display list: what a rendered page consists of.
//!
//! Mirrors the output of WinScore's FORTRAN engine (see
//! `analysis/ARCHITECTURE.md`, "Engine output"): filled polygon sets and
//! one-unit polylines in engine units of 1/4000 inch with the y axis pointing
//! up, plus positioned text runs. Every element remembers the item it came
//! from so the editor can hit-test.

/// Engine units per inch.
pub const UNITS_PER_INCH: i32 = 4000;

/// The pen that draws polylines and outlines filled shapes whose
/// [`Shape::width`] is 0, in engine units: 1/150 inch, the width SCORE's
/// PostScript prologue sets with `wdl lw` (two dots at 300 dpi). Outputs
/// draw it at least one device pixel wide.
pub const PEN: f32 = 4000.0 / 150.0;

/// The pen SCORE's PostScript output draws with after a print-width marker
/// (0x4D4ED2, called by the drawing routines when printing) of `w`: `w` is
/// in 1/600 inch and adds to the default pen (0x4CF0D3), which it can also
/// narrow down to PostScript's `0 setlinewidth`, the thinnest line a device
/// draws; that is kept as a hundredth of a unit, since a [`Shape::width`]
/// of 0 means the default pen. The engine's screen output has no such
/// widths; the port draws them on every medium.
pub fn print_pen(w: f32) -> f32 {
    (PEN + w * UNITS_PER_INCH as f32 / 600.0).max(THINNEST)
}

/// The width [`print_pen`] gives a pen narrowed to nothing.
const THINNEST: f32 = 0.01;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, Default)]
pub struct Point {
    pub x: i32,
    pub y: i32,
}

impl Point {
    pub const fn new(x: i32, y: i32) -> Self {
        Self { x, y }
    }

    /// The point moved by `dx`, `dy` with the engine's 32-bit integer adds,
    /// which wrap; a coordinate truncated from NaN is i32::MIN.
    pub const fn shifted(self, dx: i32, dy: i32) -> Self {
        Self { x: self.x.wrapping_add(dx), y: self.y.wrapping_add(dy) }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, Default)]
pub struct Colour {
    pub r: u8,
    pub g: u8,
    pub b: u8,
}

impl Colour {
    pub const BLACK: Colour = Colour { r: 0, g: 0, b: 0 };

    /// From a Windows COLORREF (0x00BBGGRR), the engine's colour encoding.
    pub const fn from_colorref(value: u32) -> Self {
        Self { r: value as u8, g: (value >> 8) as u8, b: (value >> 16) as u8 }
    }
}

/// Index of the source item in the document, for hit-testing.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct ItemId(pub u32);

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum ShapeKind {
    /// Open polylines drawn with a one-unit pen.
    Stroke,
    /// Closed paths filled with the even-odd rule (GDI ALTERNATE).
    Fill,
}

#[derive(Debug, Clone, PartialEq)]
pub struct Shape {
    pub kind: ShapeKind,
    pub colour: Colour,
    pub paths: Vec<Vec<Point>>,
    /// Width in engine units of the pen that draws a polyline or outlines a
    /// filled shape; 0 is the output's default pen ([`PEN`]). The engine's
    /// own output always has 0: it draws with a one-unit pen.
    pub width: f32,
    pub source: Option<ItemId>,
}

#[derive(Debug, Clone, PartialEq)]
pub struct PlacedText {
    /// The text baseline's start: the engine's y + 96. OnDraw passes it to
    /// TextOut with TA_TOP after adding the font's ascent, which in the
    /// view's y-up mapping puts the baseline here (analysis/engine/display.md).
    pub origin: Point,
    pub text: String,
}

#[derive(Debug, Clone, PartialEq)]
pub struct TextRun {
    pub font: String,
    /// Character height in engine units.
    pub height: f32,
    /// Average character width in engine units (0 = font default).
    pub width: f32,
    /// Angle in tenths of a degree; the engine lays the characters of a
    /// positive angle along a clockwise line (analysis/engine/display.md §3.4).
    pub escapement: i32,
    pub colour: Colour,
    pub weight: i32,
    pub italic: bool,
    pub underline: bool,
    /// Outlined letters (SCORE's `__nn` fonts): stroked with the pen, not filled.
    pub outline: bool,
    pub strings: Vec<PlacedText>,
    pub source: Option<ItemId>,
}

#[derive(Debug, Clone, PartialEq, Default)]
pub struct DisplayList {
    pub shapes: Vec<Shape>,
    pub texts: Vec<TextRun>,
}

impl DisplayList {
    pub fn extend(&mut self, other: DisplayList) {
        self.shapes.extend(other.shapes);
        self.texts.extend(other.texts);
    }
}
