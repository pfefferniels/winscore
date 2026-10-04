//! Rendering of SCORE items into display lists that match WinScore's engine.

pub mod display;

pub use display::{Colour, DisplayList, ItemId, PlacedText, Point, Shape, ShapeKind, TextRun, UNITS_PER_INCH};
