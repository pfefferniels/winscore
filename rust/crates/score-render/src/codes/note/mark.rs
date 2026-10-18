//! Marks attached to a note, P11, moved by P13 (P3 units) and
//! P14 (scale steps; P11's decimals × 10 when P14 is 0), sized by P18.
//!
//! Most marks sit on the head side, two scale steps from the head; a
//! negative P11 puts them on the stem side, beyond the stem's end. Marks of
//! the "above" class (fermata, bowings, ornaments …) stay above the staff,
//! or below it for a negative P11. Staccato, tenuto and their combinations
//! move off a staff line into the space.

use super::glyph;
use crate::codes::line::Params;
use crate::codes::beam::{draw_note_tremolo, NoteTremolo};
use crate::codes::number::{draw_number, number_text, number_text_call, NumberCall};
use crate::text::{font_loaded as text_font_loaded, Font};
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
/// Marks draw_code7 draws as a trill with IP8 = mark - 20 (24–28 are other marks).
const TRILLS: [i32; 5] = [20, 21, 22, 23, 29];
const FIRST_FINGERING: i32 = 30;
/// 41–44: tremolo beams across the stem, drawn by draw_beam.
const TREMOLO: std::ops::RangeInclusive<i32> = 41..=44;

/// Symbol numbers: marks 4–19 are symbols 21–36, ficta the accidentals 6–8.
const MARK_SYMBOLS: i32 = 17;
const FICTA_SYMBOLS: i32 = 5;
const ACCENT_TENUTO_SYMBOL: i32 = 119;
const PLUS_AS_MARK: i32 = 21;

/// Where a mark goes (from a table for marks 0–25; 0 beyond).
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
    if TREMOLO.contains(&mark) {
        tremolo(doc, item, note, mark, canvas);
        return;
    }
    let Some(placed) = place(doc, item, note, p11, stem_length) else { return };
    if TRILLS.contains(&mark) {
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
        glyph::mark(doc, item, canvas, placed.symbol, at, (placed.size, placed.size_y), note.unit);
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
            // fcomp: an unordered (NaN) length keeps the mark where it is.
            dy = if dy > limit { limit } else { dy };
        } else {
            if stem == Stem::Up {
                dy = real(dy + stem_length - s7);
            }
            let limit = real(s7 * 13.0 + (level0 - note.origin.y));
            stem = Stem::Up;
            dy = if dy >= limit { dy } else { limit };
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
        m if TRILLS.contains(&m) || (m >= FIRST_FINGERING && !TREMOLO.contains(&m)) => {
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

/// Marks 20–23 and 29: draw_code7's trill with the note's parameters, except
/// IP7 = 0 (trill), IP8 = mark - 20 (accidental 0–3, or 9), IP6 = 0 (no wave) and
/// P5 = the mark size; Y_POS is the mark's level less a staff scale step,
/// STEP the note's unit.
fn trill(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, placed: &Placed, accidental: i32, canvas: &mut Canvas<'_>) {
    let params = Params::of(item).with(5, placed.size as f32).with(6, 0.0).with(7, 0.0).with(8, accidental as f32);
    let at = Pos::new(placed.at.x, real(placed.at.y - note.scale_step));
    let globals = trill::Globals { context: ItemContext::of(item), at, step: note.unit };
    trill::draw(doc, item, canvas, &globals, &params);
}

/// Marks 30 and up (but the tremolos): the number mark - 30 by draw_number
/// at P6 = 0.7 (× P18), font 0, 4 units right of the mark position and
/// half a scale step lower (1.5 below a stem-up note). The note's other
/// parameters reach draw_number as they are.
fn fingering(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, placed: &Placed, value: i32, canvas: &mut Canvas<'_>) {
    let s7 = note.scale_step;
    let drop = real(s7 * 0.5);
    let drop = if note.implied_stem() == Stem::Up { real(s7 + drop) } else { drop };
    let at = Pos::new(real(note.unit * 4.0 + placed.at.x), real(placed.at.y - drop));
    draw_number(doc, item, canvas, at, &fingering_call(item, note, value));
}

fn fingering_call(item: ItemRef<'_>, note: &Note, value: i32) -> NumberCall {
    let size = match item.p(18) {
        0.0 => constant(0.7),
        p18 => real(f64::from(p18) * constant(0.7)),
    };
    NumberCall {
        value,
        p5: value as f32,
        size: size as f32,
        font: 0,
        frame: 0,
        frame_thickness: 0,
        step: Some(note.step),
        ..NumberCall::of(item)
    }
}

/// The font a fingering mark leaves loaded; its position does not matter.
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>, note: &Note) -> Option<Font> {
    let mark = trunc(f64::from(item.p(11))).abs();
    if mark < FIRST_FINGERING || TREMOLO.contains(&mark) || mark == HEAVY_LINE {
        return None;
    }
    let call = fingering_call(item, note, mark - FIRST_FINGERING);
    let text = number_text(call.value, call.p5, call.p17, call.p18);
    text_font_loaded(doc, &number_text_call(&call, Pos::default(), &text, Font::TIMES))
}

/// Marks 41–44: mark - 40 tremolo beams across the stem, drawn by
/// draw_beam as a beam item at the note (P3 + P13), five scale steps
/// (six for two or more beams) beyond its level (+ P14).
fn tremolo(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, mark: i32, canvas: &mut Canvas<'_>) {
    let stems_down = item.p(5) > 19.0;
    let reach = if mark > *TREMOLO.start() { 6.0 } else { 5.0 };
    let reach = if stems_down { -reach } else { reach };
    let level = real(f64::from(item.p(14)) + f64::from(item.p(4)));
    let tremolo = NoteTremolo {
        p3: real(note.origin.x / P3_UNIT + f64::from(item.p(13))) as f32,
        p4: real(reach + level) as f32,
        stems_down,
        beams: mark - FIRST_FINGERING,
        step: note.step,
    };
    draw_note_tremolo(doc, item, canvas, &tremolo);
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
