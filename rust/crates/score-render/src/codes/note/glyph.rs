//! Library symbols as notes and rests draw them: through the shared
//! draw_clef and draw_symbol ports, with the STEP the caller has set and
//! IP10 = 0, which draw_note and draw_rest leave before drawing (the item's
//! own P10 is an offset there, not a pixel thickness).

use std::f64::consts::TAU;

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::{self, draw_library_symbol, ItemContext, SymbolCall};
use crate::units::{constant, real, Pos};

/// Symbol 24 (LB0020.DRW slot 4), the rhythm and staccato dot: in the
/// library an octagon 13 library units across, about (38.5, 0.5), 7 units
/// to its corners and 6.4 to 6.5 to its sides.
const DOT: i32 = 24;
const DOT_CENTRE: (f32, f32) = (38.5, 0.5);
/// The round dot drawn in its place: the octagon's mean radius (over all
/// directions), with as many sides as a circle needs at large zooms.
const DOT_RADIUS: f32 = 6.6;
const DOT_SIDES: i32 = 32;
/// draw_clef draws symbols below 45 at a quarter of their size.
const QUARTER: f32 = 0.25;

fn context(item: ItemRef<'_>) -> ItemContext {
    ItemContext { pixels: 0, ..ItemContext::of(item) }
}

/// draw_clef 0x431AE0 for symbol `n` at sizes `(sx, sy)`; the dot is drawn
/// round.
pub fn clef(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, n: i32, at: Pos, size: (f64, f64), step: f64) {
    if n == DOT {
        round_dot(canvas, at, size, step);
        return;
    }
    symbols::draw_clef(doc, &context(item), canvas, at, step, n, size);
}

/// [`clef`] for a mark. When printing, draw_note hands note_marks P28 as
/// IP10, the pixel thickness draw_symbol gives its print pen; that pen is
/// drawn on every medium.
pub fn mark(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, n: i32, at: Pos, size: (f64, f64), step: f64) {
    if n == DOT {
        round_dot(canvas, at, size, step);
        return;
    }
    symbols::draw_clef(doc, &ItemContext { pixels: item.ip(28), ..context(item) }, canvas, at, step, n, size);
}

/// draw_symbol 0x4293F0 for symbol `n` at sizes `(sx, sy)`, unrotated.
pub fn library(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, n: i32, at: Pos, size: (f64, f64), step: f64) {
    draw_library_symbol(doc, &context(item), canvas, at, step, &SymbolCall::sized(n, size.0, size.1));
}

/// The dot as a circle (an ellipse for unequal sizes) in place of the
/// library's octagon, about the same centre: the octagon is some 3 units
/// off a circle at size 1, which shows from about 800 %.
fn round_dot(canvas: &mut Canvas<'_>, at: Pos, size: (f64, f64), step: f64) {
    // draw_clef's sizes (0 read as 1, the second 0 as the first), at a
    // quarter, times STEP, as draw_symbol scales the octagon's points.
    let size_x = if size.0 == 0.0 { 1.0 } else { size.0 };
    let size_y = if size.1 == 0.0 { size_x } else { size.1 };
    let scale = |size: f64| real(step * real(size * constant(QUARTER)));
    let (scale_x, scale_y) = (scale(size_x), scale(size_y));
    let centre = Pos::new(at.x + constant(DOT_CENTRE.0) * scale_x, at.y + constant(DOT_CENTRE.1) * scale_y);
    let radius = constant(DOT_RADIUS);
    let circle = (0..=DOT_SIDES).map(|i| {
        let angle = TAU * f64::from(i) / f64::from(DOT_SIDES);
        Pos::new(centre.x + radius * scale_x * angle.cos(), centre.y + radius * scale_y * angle.sin())
    });
    canvas.fill([circle]);
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::canvas::Stream;
    use crate::codes::note::tests::{centre, file, points, shapes};
    use crate::display::{Colour, ItemId, Shape};
    use crate::symbols::SymbolLibrary;

    #[test]
    fn the_library_dot_is_the_octagon_the_round_dot_replaces() {
        let dot = SymbolLibrary::bundled().symbol(DOT).expect("symbol 24");
        let distance = |r: &score_format::DrwRecord| (r.x - DOT_CENTRE.0).hypot(r.y - DOT_CENTRE.1);
        assert_eq!(dot.records.len(), 10, "eight corners, the first two again");
        assert!(dot.records.iter().all(|r| (distance(r) - 6.96).abs() < 0.01));
        // Its sides lie 6.36 (diagonal) and 6.5 (straight) from the centre.
        assert!((6.36..6.96).contains(&DOT_RADIUS));
    }

    #[test]
    fn dots_are_round() {
        // A dotted quarter in a space, a staccato quarter (P11 = 7), a dotted quarter rest.
        let file = file(&[
            &[1.0, 1.0, 20.0, 6.0, 10.0, 0.0, 0.0, 0.0, 10.0],
            &[1.0, 1.0, 40.0, 6.0, 10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 7.0],
            &[2.0, 1.0, 60.0, 0.0, 0.0, 1.0],
        ]);
        for n in [1, 2, 3] {
            assert!(shapes(&file, n).iter().any(|s| points(s).count() == 33), "item {n} has a round dot");
        }
    }

    /// The round dot against the library's octagon placed as draw_clef
    /// places symbol 24: its records at a quarter of the size, times STEP.
    #[test]
    fn the_round_dot_covers_the_library_octagon() {
        let file = file(&[&[1.0, 1.0, 20.0, 6.0]]);
        let doc = Document::new(&file);
        let item = doc.item(ItemId(1)).expect("the note");
        let records = &SymbolLibrary::bundled().symbol(DOT).expect("symbol 24").records;
        let at = Pos::new(5000.0, 3000.0);
        let width = |shape: &Shape| {
            let xs: Vec<i32> = points(shape).map(|p| p.x).collect();
            xs.iter().max().unwrap() - xs.iter().min().unwrap()
        };
        // A rhythm dot, a staccato dot, a grace note's dot, a size 0 (read as 1).
        for (size, step) in [(1.0, 25.0), (0.72, 25.0), (0.6, 15.0), (0.0, 25.0)] {
            let mut stream = Stream::default();
            let mut canvas = Canvas::new(&mut stream, item.id, 1, Colour::BLACK);
            clef(&doc, item, &mut canvas, DOT, at, (size, size), step);
            canvas.flush();
            let scale = step * if size == 0.0 { 1.0 } else { size } * f64::from(QUARTER);
            let corner = |r: &score_format::DrwRecord| Pos::new(at.x + f64::from(r.x) * scale, at.y + f64::from(r.y) * scale);
            canvas.fill([records.iter().map(corner)]);
            canvas.flush();
            let [round, octagon] = &stream.list.shapes[..] else { panic!("two dots") };
            assert_eq!(points(round).count(), 33);
            let (a, b) = (centre(octagon), centre(round));
            assert!((a.0 - b.0).abs() <= 1 && (a.1 - b.1).abs() <= 1, "same centre: {a:?} {b:?}");
            assert!((width(octagon) - width(round)).abs() <= 2, "about the same size");
        }
    }
}
