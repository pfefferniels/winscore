//! Code 17: key signatures.
//!
//! P5 number of accidentals (positive sharps, negative flats, ±100 naturals
//! in the sharp or flat pattern), P6 clef (0 treble, 1 bass, 2 alto, 3 tenor;
//! +100 cue size), P7 spacing factor, P8–P13 and P16 an irregular key
//! signature (`XYY` = accidental X at scale step YY), P15 offset. Every
//! accidental is a library symbol drawn through draw_clef.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::{draw_clef, ItemContext};
use crate::units::{real, trunc, Pos};

const FLAT: i32 = 6;
const SHARP: i32 = 7;
const NATURAL: i32 = 8;
/// |P5| above this draws naturals.
const NATURALS: i32 = 99;
/// P6 above this draws cue-size accidentals.
const CUE: i32 = 99;
const CUE_SIZE: f32 = 0.8;

/// Step units (7 per scale step) from the item's x to the first accidental,
/// and between accidentals.
const INDENT: f32 = 15.0;
const SPACING: f32 = 16.8;
/// Step units above P4 = 0 of the first sharp and the first flat, by clef.
const FIRST_SHARP: [f32; 4] = [77.0, 63.0, 70.0, 35.0];
const FIRST_FLAT: [f32; 4] = [49.0, 35.0, 42.0, 56.0];
const TENOR: usize = 3;
/// Highest accidental position by clef before the pattern drops an octave.
const CEILING: [f32; 4] = [84.5, 70.5, 77.5, 77.5];
const FOURTH: f32 = 28.0;
const FIFTH_DOWN: f32 = 21.0;
const OCTAVE: f32 = 49.0;

/// Irregular key signatures: the parameters holding accidentals, in order.
const IRREGULAR: [usize; 7] = [8, 9, 10, 11, 12, 13, 16];
/// `XYY`: accidental symbol X + 5 at YY scale steps.
const IRREGULAR_SYMBOL_BASE: i32 = 5;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let step = doc.staff_of(item).step;
    let at = doc.position(item);
    let p5 = trunc(f64::from(item.p(5)));
    let p6 = trunc(f64::from(item.p(6)));
    let (size, clef) = if p6 > CUE { (f64::from(CUE_SIZE), p6 - 100) } else { (1.0, p6) };
    let spacing = real(step * f64::from(SPACING));
    let spacing = if item.p(7) != 0.0 { real(f64::from(item.p(7)) * spacing) } else { spacing };
    let spacing = if p6 > CUE { real(f64::from(CUE_SIZE) * spacing) } else { spacing };
    let first_x = real(step * f64::from(INDENT) + at.x);
    let xs = std::iter::successors(Some(first_x), move |x| Some(real(spacing + x)));
    let item_context = ItemContext::of(item);
    // The irregular pattern clears IP8-IP13 after reading them, the pixel thickness IP10 with them.
    let (accidentals, context) = if trunc(f64::from(item.p(8))) != 0 {
        (irregular(item, step, at.y), ItemContext { pixels: 0, ..item_context })
    } else {
        (regular(p5, clef, step, at.y), item_context)
    };
    xs.zip(accidentals).for_each(|(x, (symbol, y))| {
        draw_clef(doc, &context, canvas, Pos::new(x, y), step, symbol, (size, size));
    });
}

/// The circle-of-fifths pattern as (symbol, y): sharps from F a fourth up
/// and a fifth down, flats from B the other way, dropping an octave when a
/// step would rise above the clef's ceiling; tenor-clef sharps start
/// upwards. P5 = 0 and ±100 draw none (the engine always draws the first
/// accidental, a sharp or a natural).
fn regular(p5: i32, clef: i32, step: f64, y0: f64) -> Vec<(i32, f64)> {
    let count = match p5.abs() {
        n if n > NATURALS => n % 100,
        n => n,
    };
    let symbol = match p5 {
        n if n.abs() > NATURALS => NATURAL,
        n if n < 0 => FLAT,
        _ => SHARP,
    };
    let clef = if (0..=3).contains(&clef) { clef as usize } else { 0 };
    let flats = p5 < 0;
    let first = if flats { FIRST_FLAT[clef] } else { FIRST_SHARP[clef] };
    let unit = if flats { -step } else { step };
    let up = real(unit * f64::from(FOURTH));
    let down = real(-(unit * f64::from(FIFTH_DOWN)));
    let octave = real(step * f64::from(OCTAVE));
    let ceiling = real(step * f64::from(CEILING[clef]) + y0);
    let starts_up = !flats && clef == TENOR;
    let first_y = real(step * f64::from(first) + y0);
    std::iter::successors(Some((first_y, starts_up)), |&(y, rising)| {
        let next = real(if rising { up } else { down } + y);
        Some(if ceiling < next { (real(next - octave), rising) } else { (next, !rising) })
    })
    .take(count as usize)
    .map(|(y, _)| (symbol, y))
    .collect()
}

/// P8–P13, P16 as `XYY` = symbol X + 5 at YY scale steps, up to the first zero.
fn irregular(item: ItemRef<'_>, step: f64, y0: f64) -> Vec<(i32, f64)> {
    IRREGULAR
        .iter()
        .map(|&p| trunc(f64::from(item.p(p))))
        .take_while(|&v| v != 0)
        .map(|v| (v / 100 + IRREGULAR_SYMBOL_BASE, real(step * f64::from((v % 100) * 7) + y0)))
        .collect()
}

#[cfg(test)]
mod tests {
    use crate::display::ItemId;
    use crate::document::Document;
    use score_format::{Item, MusFile, Word};

    /// Shapes a key signature with P5 = `p5` on a treble staff draws.
    fn shapes(p5: f32) -> usize {
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        let mut file = MusFile::empty();
        file.items = vec![words(&[8.0, 1.0, 0.0, 0.0, 1.0]), words(&[17.0, 1.0, 20.0, 0.0, p5])];
        let list = crate::render(&Document::new(&file));
        list.shapes.iter().filter(|s| s.source == Some(ItemId(1))).count()
    }

    #[test]
    fn no_accidentals_draw_nothing() {
        for p5 in [0.0, 100.0, -100.0] {
            assert_eq!(shapes(p5), 0, "P5 = {p5}");
        }
        assert!(shapes(1.0) > 0);
        assert_eq!(shapes(2.0), 2 * shapes(1.0));
    }
}
