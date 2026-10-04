//! The display list: what a rendered page consists of.
//!
//! Mirrors the output of WinScore's FORTRAN engine (see
//! `analysis/ARCHITECTURE.md`, "Engine output"): filled polygon sets and
//! one-unit polylines in engine units of 1/4000 inch with the y axis pointing
//! up, plus positioned text runs. Every element remembers the item it came
//! from so the editor can hit-test.

/// Engine units per inch.
pub const UNITS_PER_INCH: i32 = 4000;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, Default)]
pub struct Point {
    pub x: i32,
    pub y: i32,
}

impl Point {
    pub const fn new(x: i32, y: i32) -> Self {
        Self { x, y }
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

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Shape {
    pub kind: ShapeKind,
    pub colour: Colour,
    pub paths: Vec<Vec<Point>>,
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
    /// Angle in tenths of a degree, counter-clockwise.
    pub escapement: i32,
    pub colour: Colour,
    pub weight: i32,
    pub italic: bool,
    pub underline: bool,
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
