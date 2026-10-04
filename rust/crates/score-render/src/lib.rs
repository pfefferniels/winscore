//! Rendering of SCORE items into display lists that match WinScore's engine.
//!
//! ```no_run
//! # let bytes = std::fs::read("in.mus").unwrap();
//! let file = score_format::MusFile::parse(&bytes).unwrap();
//! let doc = score_render::Document::new(&file);
//! let list = score_render::render(&doc);
//! use score_render::svg::{to_svg, SvgOptions, Viewport};
//! let svg = to_svg(&list, &SvgOptions::new(Viewport::paper(doc.page.paper)));
//! ```
//!
//! # Coordinates
//!
//! The display list is in page coordinates: engine units of 1/4000 inch, y
//! up, origin at the bottom-left corner of the paper ([`page`]). Modules
//! compute in the engine's internal coordinates instead (x = 150·P3, staff 1's
//! bottom line at y = -24000), store intermediates as REAL*4 with
//! [`units::real`] and truncate to integer [`Point`]s with
//! [`units::Pos::to_point`], as the engine does; the [`canvas::Canvas`] then
//! moves the points onto the page. [`Document::position`] gives any item's
//! reference point from P3/P4 through its staff ([`staff::Staff::y`]).
//!
//! # Structure
//!
//! * [`document::Document`]: the items of a `.mus` file plus page, staff table
//!   and options. Items stay parametric ([`document::ItemRef::p`]).
//! * [`codes`]: one module per item code with
//!   `fn render(&Document, ItemRef, &mut Canvas)`, chosen by [`codes::renderer`].
//! * [`canvas::Canvas`]: the per-item drawing surface; every shape and text run
//!   it emits carries `source: Some(ItemId(index))`.
//! * [`display`]: the output types, mirroring the engine's vector and text streams.
//! * [`svg`]: an SVG writer for display lists.

pub mod canvas;
pub mod codes;
pub mod colour;
pub mod display;
pub mod document;
pub mod page;
pub mod staff;
pub mod svg;
pub mod symbols;
pub mod units;

pub use display::{Colour, DisplayList, ItemId, PlacedText, Point, Shape, ShapeKind, TextRun, UNITS_PER_INCH};
pub use document::{Document, ItemRef, Medium, Options};

use canvas::{Canvas, Stream};

/// Draws every item of the document, in file order.
pub fn render(doc: &Document<'_>) -> DisplayList {
    let mut stream = Stream::default();
    doc.items().for_each(|item| draw(doc, item, &mut stream));
    stream.list
}

/// Draws one item and appends it to `list`.
pub fn render_item(doc: &Document<'_>, item: ItemRef<'_>, list: &mut DisplayList) {
    let mut stream = Stream::new(std::mem::take(list));
    draw(doc, item, &mut stream);
    *list = stream.list;
}

fn draw(doc: &Document<'_>, item: ItemRef<'_>, stream: &mut Stream) {
    if let Some(render) = codes::renderer(item.code()) {
        let mut canvas = Canvas::new(stream, item.id, item.staff(), item.colour(doc.options.medium));
        render(doc, item, &mut canvas);
        canvas.flush();
    }
}
