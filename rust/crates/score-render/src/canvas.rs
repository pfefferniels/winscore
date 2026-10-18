//! The drawing surface handed to an item module: the engine's point buffer.
//!
//! Drawing routines in the engine append points with a pen code to a buffer,
//! which is flushed into the vector stream once per item; the C++ shell then
//! cuts the stream into objects. A canvas reproduces this chain for one item:
//! modules add points in internal coordinates (see [`crate::units`]), and on
//! flush the canvas moves them onto the page and appends them to the display
//! list as the shell would decode them. Everything is tagged with the item's id and
//! drawn in the canvas colour current at flush time.

use crate::display::{Colour, DisplayList, ItemId, PlacedText, Point, Shape, ShapeKind, TextRun};
use crate::page::{page_offset, PAPER_ORIGIN};
use crate::units::Pos;

/// OnDraw puts a text record's baseline at its y + 96.
pub const TEXT_BASELINE: i32 = 96;

/// The pen code stored with each point.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Pen {
    /// 0: continues the current path.
    Continue,
    /// 1: starts a polyline drawn with a one-unit pen.
    Stroke,
    /// 2: starts a filled object (even-odd rule).
    Fill,
    /// 3: starts a further closed path of the current filled object.
    SubPath,
}

/// A point in the item's buffer: truncated internal coordinates and a pen.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct BufferPoint {
    pub at: Point,
    pub pen: Pen,
}

/// The vector stream being built: the display list plus the pen of the last
/// point written, which emit_points keeps across items.
#[derive(Debug, Default)]
pub struct Stream {
    pub list: DisplayList,
    last_pen: Option<Pen>,
}

impl Stream {
    pub fn new(list: DisplayList) -> Self {
        Self { list, last_pen: None }
    }

    /// As in the engine's flush, a start right after a start replaces it.
    /// `width` is the pen width of a shape this point starts.
    fn write(&mut self, at: Point, pen: Pen, colour: Colour, width: f32, source: ItemId) {
        let previous_started = self.last_pen.is_some_and(|p| p != Pen::Continue);
        if pen != Pen::Continue && previous_started {
            self.drop_last_point();
        }
        let shapes = &mut self.list.shapes;
        let start = |kind| Shape { kind, colour, paths: vec![vec![at]], width, source: Some(source) };
        match (pen, shapes.last_mut()) {
            (Pen::Continue, Some(open)) => open.paths.last_mut().expect("shapes have paths").push(at),
            (Pen::SubPath, Some(open)) => open.paths.push(vec![at]),
            (Pen::Stroke, _) => shapes.push(start(ShapeKind::Stroke)),
            // A stream that starts without an object start: the shell treats
            // any first tag other than a polyline start as a filled object.
            (Pen::Fill | Pen::Continue | Pen::SubPath, _) => shapes.push(start(ShapeKind::Fill)),
        }
        self.last_pen = Some(pen);
    }

    /// Removes the last point written, a start that is alone in its path.
    fn drop_last_point(&mut self) {
        let shapes = &mut self.list.shapes;
        if let Some(last) = shapes.last_mut() {
            last.paths.pop();
            if last.paths.is_empty() {
                shapes.pop();
            }
        }
    }
}

/// Font attributes of a text run, everything but its strings and colour.
#[derive(Debug, Clone, PartialEq)]
pub struct TextStyle {
    pub font: String,
    /// Character height in engine units.
    pub height: f32,
    /// Average character width in engine units (0 = font default).
    pub width: f32,
    /// Angle in tenths of a degree; the engine lays the characters of a
    /// positive angle along a clockwise line.
    pub escapement: i32,
    pub weight: i32,
    pub italic: bool,
    pub underline: bool,
    /// Outlined letters, see [`TextRun::outline`].
    pub outline: bool,
}

/// One string of a text record, at the engine's internal text position.
#[derive(Debug, Clone, PartialEq)]
pub struct TextString {
    pub at: Point,
    pub text: String,
}

pub struct Canvas<'a> {
    stream: &'a mut Stream,
    source: ItemId,
    offset: Point,
    buffer: Vec<BufferPoint>,
    /// Pen widths set with [`Canvas::set_width`]: (buffer index, width).
    widths: Vec<(usize, f32)>,
    pub colour: Colour,
}

impl<'a> Canvas<'a> {
    /// A canvas for an item on staff `staff`; points of items on the recto
    /// page are shifted right when they are flushed.
    pub fn new(stream: &'a mut Stream, source: ItemId, staff: i32, colour: Colour) -> Self {
        Self { stream, source, offset: page_offset(staff), buffer: Vec::new(), widths: Vec::new(), colour }
    }

    /// The pen width, in engine units, of the shapes started from here on
    /// (0, the default, is the output's pen, [`crate::display::PEN`]).
    pub fn set_width(&mut self, width: f32) {
        let at = self.buffer.len();
        self.widths.retain(|&(i, _)| i < at);
        self.widths.push((at, width));
    }

    /// The pen width the next shape started gets, for a routine that sets
    /// its own and then restores it.
    pub fn width(&self) -> f32 {
        self.widths.last().map_or(0.0, |&(_, width)| width)
    }

    pub fn source(&self) -> ItemId {
        self.source
    }

    /// Truncates the position (a [`Pos`], or a [`Point`]
    /// already truncated) and appends it.
    pub fn point(&mut self, at: impl Into<Pos>, pen: Pen) {
        self.buffer.push(BufferPoint { at: at.into().to_point(), pen });
    }

    /// A two-point polyline.
    pub fn segment(&mut self, from: impl Into<Pos>, to: impl Into<Pos>) {
        self.point(from, Pen::Stroke);
        self.point(to, Pen::Continue);
    }

    /// An open polyline drawn with a one-unit pen.
    pub fn stroke<P: Into<Pos>>(&mut self, points: impl IntoIterator<Item = P>) {
        self.path(Pen::Stroke, points);
    }

    /// One filled object of one or more closed paths (even-odd rule).
    pub fn fill<P: Into<Pos>, Path: IntoIterator<Item = P>>(&mut self, paths: impl IntoIterator<Item = Path>) {
        paths
            .into_iter()
            .enumerate()
            .for_each(|(i, path)| self.path(if i == 0 { Pen::Fill } else { Pen::SubPath }, path));
    }

    fn path<P: Into<Pos>>(&mut self, start: Pen, points: impl IntoIterator<Item = P>) {
        points
            .into_iter()
            .enumerate()
            .for_each(|(i, at)| self.point(at, if i == 0 { start } else { Pen::Continue }));
    }

    /// The points added since the last flush, for routines that rewrite them.
    pub fn buffer_mut(&mut self) -> &mut Vec<BufferPoint> {
        &mut self.buffer
    }

    /// Writes the buffered points to the stream, as the engine does after each item.
    pub fn flush(&mut self) {
        let (offset, colour, source) = (self.offset, self.colour, self.source);
        let mut widths = self.widths.drain(..).peekable();
        let mut width = 0.0;
        self.buffer.drain(..).enumerate().for_each(|(i, p)| {
            while let Some((_, w)) = widths.next_if(|&(at, _)| at <= i) {
                width = w;
            }
            self.stream.write(p.at.shifted(offset.x, offset.y), p.pen, colour, width, source);
        });
    }

    /// A text record. Text positions get no recto shift from the canvas: the
    /// module adds it where the engine does.
    pub fn text(&mut self, style: &TextStyle, strings: impl IntoIterator<Item = TextString>) {
        let strings = strings
            .into_iter()
            .map(|s| PlacedText {
                origin: s.at.shifted(-PAPER_ORIGIN.x, TEXT_BASELINE - PAPER_ORIGIN.y),
                text: s.text,
            })
            .collect();
        self.stream.list.texts.push(TextRun {
            font: style.font.clone(),
            height: style.height,
            width: style.width,
            escapement: style.escapement,
            colour: self.colour,
            weight: style.weight,
            italic: style.italic,
            underline: style.underline,
            outline: style.outline,
            strings,
            source: Some(self.source),
        });
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn draw(stream: &mut Stream, id: u32, points: &[(f64, f64, Pen)]) {
        let mut canvas = Canvas::new(stream, ItemId(id), 1, Colour::BLACK);
        points.iter().for_each(|&(x, y, pen)| canvas.point(Pos::new(x, y), pen));
        canvas.flush();
    }

    #[test]
    fn decodes_objects_and_subpaths() {
        let mut stream = Stream::default();
        draw(
            &mut stream,
            0,
            &[
                (0.0, 0.0, Pen::Stroke),
                (10.0, 0.0, Pen::Continue),
                (0.0, 0.0, Pen::Fill),
                (5.0, 5.0, Pen::Continue),
                (1.0, 1.0, Pen::SubPath),
                (2.0, 2.0, Pen::Continue),
            ],
        );
        let shapes = &stream.list.shapes;
        assert_eq!(shapes.len(), 2);
        assert_eq!(shapes[0].kind, ShapeKind::Stroke);
        assert_eq!(shapes[1].kind, ShapeKind::Fill);
        assert_eq!(shapes[1].paths.len(), 2);
        assert_eq!(shapes[1].paths[1][0], Point::new(2001, 26949));
    }

    #[test]
    fn widths_apply_to_the_shapes_started_after_them() {
        let mut stream = Stream::default();
        let mut canvas = Canvas::new(&mut stream, ItemId(0), 1, Colour::BLACK);
        canvas.segment(Pos::new(0.0, 0.0), Pos::new(1.0, 0.0));
        canvas.set_width(40.0);
        canvas.segment(Pos::new(0.0, 1.0), Pos::new(1.0, 1.0));
        canvas.set_width(0.0);
        canvas.fill([[Pos::new(0.0, 2.0), Pos::new(1.0, 2.0), Pos::new(1.0, 3.0)]]);
        canvas.flush();
        let widths: Vec<f32> = stream.list.shapes.iter().map(|s| s.width).collect();
        assert_eq!(widths, [0.0, 40.0, 0.0]);
    }

    #[test]
    fn a_start_after_a_start_replaces_it_across_items() {
        let mut stream = Stream::default();
        draw(&mut stream, 0, &[(0.0, 0.0, Pen::Stroke), (1.0, 0.0, Pen::Continue), (7.0, 7.0, Pen::Stroke)]);
        draw(&mut stream, 1, &[(3.0, 3.0, Pen::Fill), (4.0, 4.0, Pen::Continue)]);
        let shapes = &stream.list.shapes;
        assert_eq!(shapes.len(), 2);
        assert_eq!(shapes[1].source, Some(ItemId(1)));
        assert_eq!(shapes[1].paths, vec![vec![Point::new(2003, 26951), Point::new(2004, 26952)]]);
    }
}
