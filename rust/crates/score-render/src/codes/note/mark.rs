//! Marks attached to a note, P11 (0x4F2279), moved by P13 (P3 units) and
//! P14 (scale steps; P11's decimals × 10 when P14 is 0), sized by P18.
//!
//! Most marks sit on the head side, two scale steps from the head; a
//! negative P11 puts them on the stem side, beyond the stem's end. Marks of
//! the "above" class (fermata, bowings, ornaments …) stay above the staff,
//! or below it for a negative P11. Staccato, tenuto and their combinations
//! move off a staff line into the space.

use super::glyph;
use crate::codes::line::Params;
use crate::codes::number::{draw_number, NumberCall};
use crate::codes::trill;
use crate::symbols::ItemContext;
use super::{Note, Stem};
use crate::canvas::{Canvas, Pen};
use crate::document::{Document, ItemRef};
use crate::page::P3_UNIT;
use crate::units::{constant, real, trunc, Pos};

/// The heavy line to the right of the head (contemporary notation).
const HEAVY_LINE: i32 = 99;

/// P13 = 99 is documented to centre the mark on the stem.
const CENTRE_ON_STEM: f32 = 99.0;

const STACCATO: i32 = 7;
const TENUTO: i32 = 6;
const ACCENT_TENUTO: i32 = 25;
const PLUS: i32 = 24;
/// Musica ficta flat, sharp, natural: small accidentals above the note.
const LAST_FICTA: i32 = 3;
/// 26–28: two, three, four staccato dots side by side.
const MULTIPLE_STACCATO: std::ops::RangeInclusive<i32> = 26..=28;
const FIRST_TRILL: i32 = 20;
const FIRST_FINGERING: i32 = 30;
/// 41–44: tremolo beams across the stem, drawn by draw_beam (not yet).
const TREMOLO: std::ops::RangeInclusive<i32> = 41..=44;

/// Symbol numbers: marks 4–19 are symbols 21–36, ficta the accidentals 6–8.
const MARK_SYMBOLS: i32 = 17;
const FICTA_SYMBOLS: i32 = 5;
const ACCENT_TENUTO_SYMBOL: i32 = 119;
const PLUS_AS_MARK: i32 = 21;

/// Where a mark goes (table at 0x794EA8 for marks 0–25; 0 beyond).
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Class {
    /// Above the staff (below for a negative P11): fermata, bowings, ornaments.
    AboveStaff,
    /// At the head, and mirrored below it: accent, tenuto, staccato.
    AtHead,
    /// At the head, and mirrored below it: wedges and combinations.
    Wedge,
}

const CLASSES: [i32; 26] = [0, 1, 1, 1, -1, 0, 0, 0, -1, -1, -1, 1, 1, 1, 1, 1, 1, 1, 1, -1, 1, 1, 1, 1, 1, -1];

impl Class {
    fn of(mark: i32) -> Self {
        match CLASSES.get(mark as usize) {
            Some(1) => Class::AboveStaff,
            Some(-1) => Class::Wedge,
            _ => Class::AtHead,
        }
    }
}

/// A mark ready to draw: library symbol, position, sizes, repeats.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Placed {
    symbol: i32,
    at: Pos,
    size: f64,
    /// The vertical size, negative when the mark is mirrored below the note.
    size_y: f64,
    /// Further copies, 8.6 units apart (multiple staccato).
    repeats: i32,
}

pub fn draw(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, stem_length: f64, canvas: &mut Canvas<'_>) {
    let p11 = trunc(f64::from(item.p(11)));
    let mark = p11.abs();
    if mark == HEAVY_LINE {
        heavy_line(item, note, canvas);
        return;
    }
    let Some(placed) = place(doc, item, note, p11, stem_length) else { return };
    if (FIRST_TRILL..FIRST_TRILL + 4).contains(&mark) {
        trill(doc, item, note, &placed, mark - FIRST_TRILL, canvas);
        return;
    }
    if mark >= FIRST_FINGERING {
        fingering(doc, item, note, &placed, mark - FIRST_FINGERING, canvas);
        return;
    }
    let x = real((note.width * constant(8.5) - constant(8.5)) * note.unit + placed.at.x);
    (0..=placed.repeats.max(0)).fold(x, |x, _| {
        let at = Pos::new(x, placed.at.y);
        glyph::clef(doc, item, canvas, placed.symbol, at, (placed.size, placed.size_y), note.unit);
        real(note.unit * constant(8.6) + x)
    });
}

/// The position and symbol of a mark drawn as a library symbol; None for
/// trills, fingerings and tremolo beams, which other item codes draw.
fn place(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, p11: i32, stem_length: f64) -> Option<Placed> {
    let unit = note.unit;
    let s7 = note.scale_step;
    let mut mark = p11.abs();
    let class = Class::of(mark);
    let p13 = item.p(13);
    let shift = if p13 == CENTRE_ON_STEM { centre_on_stem(note) } else { real(f64::from(p13) * P3_UNIT) };
    let mut x = real(shift + note.origin.x);
    let mut size = 1.0;
    let mut repeats = 0;
    let p18 = f64::from(item.p(18));
    if mark == STACCATO || MULTIPLE_STACCATO.contains(&mark) {
        let (count, offset) = match mark - 25 {
            1 => (1, constant(-2.3)),
            2 => (2, constant(-6.6)),
            3 => (3, constant(-10.9)),
            _ => (0, constant(2.0)),
        };
        repeats = count;
        mark = STACCATO;
        x = real(unit * offset + x);
        size = constant(0.72);
        if p18 != 0.0 {
            x = real(x - (p18 - 1.0) * 180.0 * unit / 25.0);
        }
    }
    if p18 != 0.0 {
        size = real(p18 * size);
    }
    let mut size_y = size;
    let mut stem = note.implied_stem();
    let mut dy = real(s7 + s7);
    if class == Class::AboveStaff {
        dy = real(s7 + dy);
        let staff = match note.borrowed_staff {
            0 => item.staff(),
            p12 => item.staff() - 2 * p12 + 3,
        };
        let level0 = f64::from(doc.staves.get(staff).level0);
        if p11 < 0 {
            dy = real(dy - s7 * 6.0);
            if stem == Stem::Down {
                dy = real(stem_length + dy + s7);
            }
            let limit = real(s7 + (level0 - note.origin.y));
            stem = Stem::Down;
            if p11 == -14 {
                size_y = -size;
            }
            dy = dy.min(limit);
        } else {
            if stem == Stem::Up {
                dy = real(dy + stem_length - s7);
            }
            let limit = real(s7 * 13.0 + (level0 - note.origin.y));
            stem = Stem::Up;
            dy = dy.max(limit);
        }
    } else {
        if stem == Stem::Up {
            dy = -dy;
        }
        if p11 < 1 {
            if mark < FIRST_FINGERING {
                let room = real(s7 * 0.5 * note.step / unit);
                let room = if stem == Stem::Up { -room } else { room };
                dy = real(dy - room);
            }
            dy = real(stem_length - dy);
        }
        let below = (stem == Stem::Up && p11 > 0) || (stem == Stem::Down && p11 <= 0);
        if below {
            size_y = -size;
        }
        let into_space = matches!(mark, ACCENT_TENUTO | STACCATO | TENUTO) && p11 >= 0;
        if into_space && note.level.abs() % 2 == 1 {
            let level = note.level;
            let adjust = match stem {
                Stem::Up if level > 4 => -s7,
                Stem::Down if level < 10 => s7,
                _ => 0.0,
            };
            dy = real(adjust + dy);
        }
    }
    let lift = match item.p(14) {
        0.0 => {
            let p11 = f64::from(item.p(11));
            let decimals = real(p11 - f64::from(trunc(p11)));
            match decimals {
                0.0 => None,
                d if stem == Stem::Up && class != Class::AboveStaff => Some(-real(d * 10.0)),
                d => Some(real(d * 10.0)),
            }
        }
        p14 => Some(f64::from(p14)),
    };
    if let Some(lift) = lift {
        dy = real(s7 * lift + dy);
    }
    let y = real(dy + note.origin.y);
    let symbol = match mark {
        m if m < FIRST_TRILL => m,
        ACCENT_TENUTO => ACCENT_TENUTO_SYMBOL - MARK_SYMBOLS,
        PLUS => PLUS_AS_MARK,
        m if m < FIRST_TRILL + 4 || (m >= FIRST_FINGERING && !TREMOLO.contains(&m)) => {
            return Some(Placed { symbol: m, at: Pos::new(x, y), size, size_y, repeats })
        }
        _ => return None,
    };
    let (symbol, x, size, size_y) = if symbol <= LAST_FICTA {
        let small = real(size * constant(0.65));
        (symbol + FICTA_SYMBOLS, real(note.unit * 18.0 + x), small, small)
    } else {
        (symbol + MARK_SYMBOLS, x, size, size_y)
    };
    Some(Placed { symbol, at: Pos::new(x, y), size, size_y, repeats })
}

/// Marks 20–23: draw_code7's trill with the note's parameters, except
/// IP7 = 0 (trill), IP8 = the accidental 0–3, IP6 = 0 (no wave) and
/// P5 = the mark size; Y_POS is the mark's level less a staff scale step,
/// STEP the note's unit (0x4F2279).
fn trill(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, placed: &Placed, accidental: i32, canvas: &mut Canvas<'_>) {
    let params = Params::of(item).with(5, placed.size as f32).with(6, 0.0).with(7, 0.0).with(8, accidental as f32);
    let at = Pos::new(placed.at.x, real(placed.at.y - note.scale_step));
    trill::draw(doc, canvas, ItemContext::of(item), at, note.unit, &params);
}

/// Marks 30 and up (but the tremolos): the number mark - 30 by draw_number
/// at P6 = 0.7 (× P18), font 0, 4 units right of the mark position and
/// half a scale step lower (1.5 below a stem-up note). The note's other
/// parameters reach draw_number as they are (0x4F2DD4).
fn fingering(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, placed: &Placed, value: i32, canvas: &mut Canvas<'_>) {
    let s7 = note.scale_step;
    let drop = real(s7 * 0.5);
    let drop = if note.implied_stem() == Stem::Up { real(s7 + drop) } else { drop };
    let at = Pos::new(real(note.unit * 4.0 + placed.at.x), real(placed.at.y - drop));
    let size = match item.p(18) {
        0.0 => constant(0.7),
        p18 => real(f64::from(p18) * constant(0.7)),
    };
    let call = NumberCall { value, p5: value as f32, size: size as f32, font: 0, frame: 0, frame_thickness: 0, step: Some(note.step), ..NumberCall::of(item) };
    draw_number(doc, item, canvas, at, &call);
}

/// The documented meaning of P13 = 99 (the engine moves the mark 99 P3
/// units right instead): from the head's centre to the stem.
fn centre_on_stem(note: &Note) -> f64 {
    let half = real(note.drawn_head_width() / 2.0);
    if note.implied_stem() == Stem::Down {
        -half
    } else {
        half
    }
}

/// P11 = 99: a filled bar 2.8 units either side of the note's level, from
/// P13 (default 13.8 units) to P14 P3 units (default 10) right of the note.
fn heavy_line(item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let x = note.origin.x;
    let left = match item.p(13) {
        0.0 => real(note.unit * constant(13.8)),
        p13 => real(f64::from(p13) * P3_UNIT),
    };
    let left = real(left + x);
    let reach = match item.p(14) {
        0.0 => 10.0,
        p14 => f64::from(p14),
    };
    let right = real(reach * P3_UNIT + x);
    let low = real(note.origin.y - note.unit * constant(2.8));
    let high = real(note.unit * constant(2.8) + note.origin.y);
    let corners = [(left, low), (right, low), (right, high), (left, high), (left, low)];
    corners.iter().enumerate().for_each(|(i, &(x, y))| {
        canvas.point(Pos::new(x, y), if i == 0 { Pen::Fill } else { Pen::Continue });
    });
}
