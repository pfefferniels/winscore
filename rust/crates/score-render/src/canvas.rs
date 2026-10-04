//! The drawing surface handed to an item module.
//!
//! A canvas belongs to one item. Modules draw integer points in internal
//! coordinates (see [`crate::units`]); the canvas moves them onto the page,
//! tags everything with the item's id, and uses the item's colour unless the
//! module changes it.

use crate::display::{Colour, DisplayList, ItemId, PlacedText, Point, Shape, ShapeKind, TextRun};
use crate::page::{page_offset, PAPER_ORIGIN};

/// OnDraw (0x5E5910) draws a text record at y + 96, the top of its character cell.
pub const TEXT_TOP: i32 = 96;

/// Font attributes of a text run, everything but its strings and colour.
#[derive(Debug, Clone, PartialEq)]
pub struct TextStyle {
    pub font: String,
    /// Character height in engine units.
    pub height: f32,
    /// Average character width in engine units (0 = font default).
    pub width: f32,
    /// Angle in tenths of a degree, counter-clockwise.
    pub escapement: i32,
    pub weight: i32,
    pub italic: bool,
    pub underline: bool,
}

/// One string of a text record, at the engine's internal text position.
#[derive(Debug, Clone, PartialEq)]
pub struct TextString {
    pub at: Point,
    pub text: String,
}

pub struct Canvas<'a> {
    list: &'a mut DisplayList,
    source: ItemId,
    offset: Point,
    pub colour: Colour,
}

impl<'a> Canvas<'a> {
    /// A canvas for an item on staff `staff`; shapes of items on the recto
    /// page are shifted right when they are flushed (emit_points 0x54A69C).
    pub fn new(list: &'a mut DisplayList, source: ItemId, staff: i32, colour: Colour) -> Self {
        Self { list, source, offset: page_offset(staff), colour }
    }

    pub fn source(&self) -> ItemId {
        self.source
    }

    /// An open polyline drawn with a one-unit pen.
    pub fn stroke(&mut self, points: impl IntoIterator<Item = Point>) {
        let path = self.place(points);
        self.shape(ShapeKind::Stroke, vec![path]);
    }

    /// One filled object of one or more closed paths (even-odd rule).
    pub fn fill<P: IntoIterator<Item = Point>>(&mut self, paths: impl IntoIterator<Item = P>) {
        let paths = paths.into_iter().map(|p| self.place(p)).collect();
        self.shape(ShapeKind::Fill, paths);
    }

    /// A text record. Text positions get no recto shift from the canvas: the
    /// module adds it where the engine does.
    pub fn text(&mut self, style: &TextStyle, strings: impl IntoIterator<Item = TextString>) {
        let strings = strings
            .into_iter()
            .map(|s| PlacedText {
                origin: Point::new(s.at.x - PAPER_ORIGIN.x, s.at.y + TEXT_TOP - PAPER_ORIGIN.y),
                text: s.text,
            })
            .collect();
        self.list.texts.push(TextRun {
            font: style.font.clone(),
            height: style.height,
            width: style.width,
            escapement: style.escapement,
            colour: self.colour,
            weight: style.weight,
            italic: style.italic,
            underline: style.underline,
            strings,
            source: Some(self.source),
        });
    }

    fn place(&self, points: impl IntoIterator<Item = Point>) -> Vec<Point> {
        points.into_iter().map(|p| Point::new(p.x + self.offset.x, p.y + self.offset.y)).collect()
    }

    fn shape(&mut self, kind: ShapeKind, paths: Vec<Vec<Point>>) {
        self.list.shapes.push(Shape { kind, colour: self.colour, paths, source: Some(self.source) });
    }
}
