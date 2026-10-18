//! Tablature: P6 = -n (n strings) turns a note into a fret number on a
//! string line. The help text says no more than that; this
//! follows the engine.
//!
//! P6 = -(10·s + n): s chooses the tuning (0 guitar, 1 lute, 2, 3; 8, 9
//! and 15 transpose the note an octave or two first). From the note's
//! level and accidental (P5's units) the routine computes a pitch, takes
//! the first string, from the top, tuned at or below it (or P8's string
//! if lower), and writes pitch - string as the fret number, in Helvetica
//! bold (font 1005, or 1000 + P12) on that string's line. For other s the
//! string is P8 and the fret P9. P16–P19 retune strings, P12 + 100 puts
//! the number in parentheses, P20 = 1 clears the line behind it.

use super::head::white_box;
use super::ip;
use crate::canvas::Canvas;
use crate::codes::text::font_before;
use crate::document::{Document, ItemRef};
use crate::page::P3_UNIT;
use crate::staff::Staff;
use crate::text::{draw_text, font_loaded as text_font_loaded, Font, TextCall};
use crate::units::{amod, constant, real, trunc, Pos};

/// String pitches by tuning (from index `first + 1`).
const STRING_PITCHES: [i32; 20] = [-8, 76, 71, 67, 62, 57, 52, 47, 47, 74, 71, 67, 62, 79, 0, 0, 0, 0, 0, 0];
/// P6 = -5: five strings.
const FIVE_STRINGS: [i32; 5] = [74, 71, 67, 62, 79];
/// P6 = -4 with the guitar tuning.
const FOUR_STRINGS: [i32; 4] = [76, 69, 62, 55];
/// The top string of a six-string lute.
const LUTE_TOP: i32 = 72;
/// Semitones of the scale degrees C … B.
const DEGREES: [i32; 7] = [0, 2, 4, 5, 7, 9, 11];
/// Semitones by P5's units digit.
const ACCIDENTALS: [i32; 10] = [0, -1, 1, 0, -2, 2, 4, 1, 0, 2];
/// Level offsets of tunings 0–3.
const TUNING_LEVELS: [i32; 4] = [0, -12, -6, -8];

const LUTE: i32 = 1;
const GUITAR: i32 = 0;
const DEFAULT_FONT: f32 = 1005.0;
const SIZE: f32 = 0.55;
const GRACE_SIZE: f32 = 0.818;
const SPREAD: f32 = 0.95;

/// Strings 1 … 8 (from the top) as pitch numbers.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
struct Strings([i32; 8]);

impl Strings {
    fn tuned(item: ItemRef<'_>, tuning: i32, count: i32) -> Self {
        let mut strings = Strings::default();
        if item.p(6) == -5.0 {
            strings.0[..5].copy_from_slice(&FIVE_STRINGS);
        } else {
            let first = if tuning == LUTE { (7 - count) / 2 + 1 } else { 6 - count }.max(0);
            (0..count.min(8) as usize).for_each(|n| strings.0[n] = STRING_PITCHES[first as usize + n + 1]);
        }
        if tuning == LUTE && count == 6 {
            strings.0[0] = LUTE_TOP;
        }
        if tuning == GUITAR && count == 4 {
            strings.0[..4].copy_from_slice(&FOUR_STRINGS);
        }
        let retune = |strings: &mut Strings, pair: usize, p: f32| {
            let v = trunc(f64::from(p));
            strings.retune(2 * pair, v / 100);
            strings.retune(2 * pair + 1, v % 100);
        };
        [(0, 16), (1, 17), (2, 18)].into_iter().filter(|&(_, n)| item.p(n) != 0.0).for_each(|(pair, n)| retune(&mut strings, pair, item.p(n)));
        if item.p(19) >= 100.0 {
            retune(&mut strings, 3, item.p(18));
        }
        strings
    }

    /// Up to 20 semitones up, 21–32 down, from 33 a pitch.
    fn retune(&mut self, string: usize, change: i32) {
        if change == 0 {
            return;
        }
        self.0[string] = match change {
            c if c > 32 => c,
            c if c > 20 => self.0[string] + 20 - c,
            c => self.0[string] + c,
        };
    }

    /// The first string tuned at or below `pitch`, or the last.
    fn for_pitch(&self, pitch: i32, count: i32) -> i32 {
        (1..=count).find(|&n| pitch >= self.0[n as usize - 1]).unwrap_or(count)
    }
}

/// Fret and string to write, from the note.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct Fingering {
    string: i32,
    fret: i32,
    count: i32,
}

fn fingering(item: ItemRef<'_>) -> Option<Fingering> {
    let p6 = ip(item, 6);
    let mut tuning = -p6 / 10;
    let count = -p6 % 10;
    let mut level = ip(item, 4) % 100;
    if let Some(shift) = match tuning {
        8 => Some(7),
        9 => Some(-7),
        15 => Some(14),
        _ => None,
    } {
        level += shift;
        tuning = GUITAR;
    }
    let forced = ip(item, 8);
    if tuning >= 4 {
        return (forced != 0).then_some(Fingering { string: forced, fret: ip(item, 9), count });
    }
    let pitch = pitch(level, ip(item, 5) % 10, tuning);
    let offset = if item.p(19) < 100.0 { ip(item, 19) } else { 0 };
    let offset = if tuning == LUTE { offset - 12 } else { offset };
    let mut strings = Strings::tuned(item, tuning, count);
    strings.0.iter_mut().take(count.clamp(0, 8) as usize).for_each(|s| *s += offset);
    let string = strings.for_pitch(pitch, count).max(forced % 100);
    let fret = if ip(item, 9) >= 0 { pitch - strings.0[(string - 1).clamp(0, 7) as usize] } else { ip(item, 9) };
    if ip(item, 10) == 999 {
        return None;
    }
    let string = if forced > 100 { string * 6 % 7 } else { string };
    Some(Fingering { string, fret, count })
}

/// The pitch of a level (P4 on the tuning's staff) with an accidental.
fn pitch(level: i32, accidental: i32, tuning: i32) -> i32 {
    let step = TUNING_LEVELS[tuning.clamp(0, 3) as usize] + level;
    let degree = (step + 6) % 7;
    let degree = if degree < 0 { degree + 7 } else { degree };
    ACCIDENTALS[accidental.clamp(0, 9) as usize] + (step + 34) / 7 * 12 + DEGREES[degree as usize]
}

/// The string drawn: the fret's digits, "X" for -1, a letter from 1001,
/// in parentheses (or "(Tie)" for fret 99) when P12 >= 100.
fn label(fret: i32, parenthesised: bool) -> (Vec<u8>, bool) {
    let mut text = Vec::new();
    if parenthesised {
        text.push(b'(');
    }
    let lettered = fret >= 1001;
    let last = if lettered {
        fret % 1000 + 16 + if fret >= 2000 { 32 } else { 0 }
    } else {
        if fret / 10 != 0 {
            text.push((b'0' as i32 + fret / 10) as u8);
        }
        match fret % 10 {
            -1 => 40,
            d => d,
        }
    };
    text.push((b'0' as i32 + last) as u8);
    if parenthesised {
        if !lettered && fret == 99 {
            let n = text.len();
            text.truncate(n - 2);
            text.extend_from_slice(b"Tie");
        }
        text.push(b')');
    }
    (text, lettered)
}

/// STEP while a note is drawn: the staff's step times P15.
fn step(doc: &Document<'_>, item: ItemRef<'_>) -> f64 {
    let staff_step = doc.staff_of(item).step;
    match item.p(15) {
        0.0 => staff_step,
        p15 => real(f64::from(p15) * staff_step),
    }
}

/// The line the number sits on: two levels per string from the bottom.
fn level(item: ItemRef<'_>, fingering: &Fingering, lettered: bool) -> f64 {
    let level = real(f64::from((fingering.count - fingering.string) * 2) + constant(2.2) + f64::from(item.p(14)));
    if lettered {
        real(level + constant(0.2))
    } else {
        level
    }
}

pub fn draw(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let Some(fingering) = fingering(item) else { return };
    let (text, lettered) = label(fingering.fret, ip(item, 12) >= 100);
    let level = level(item, &fingering, lettered);
    let step = step(doc, item);
    if item.p(20) == 1.0 {
        clear_behind(item, &doc.staff_of(item), step, level, fingering.fret, canvas);
    }
    let call = text_call(doc, item, step, &text, &fingering, level, lettered, font_before(doc, item));
    draw_text(doc, item, canvas, &call);
}

/// The font the fret number leaves loaded.
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    let fingering = fingering(item)?;
    let (text, lettered) = label(fingering.fret, ip(item, 12) >= 100);
    let level = level(item, &fingering, lettered);
    text_font_loaded(doc, &text_call(doc, item, step(doc, item), &text, &fingering, level, lettered, Font::TIMES))
}

/// What the tablature routine hands draw_text: X_POS moved left for two digits and a
/// parenthesis, Y_POS on the string's line, P5 = 0.95, P6 = 0.55 × P15
/// (× 0.818 grace), P9 = P13, P11 = P10, the colour as P14 = -1, P16 = P26.
#[allow(clippy::too_many_arguments)]
fn text_call<'t>(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    step: f64,
    text: &'t [u8],
    fingering: &Fingering,
    level: f64,
    lettered: bool,
    current_font: Font,
) -> TextCall<'t> {
    let parenthesised = ip(item, 12) >= 100;
    let indent = match (fingering.fret > 9 && !lettered, parenthesised) {
        (true, true) => -8.0,
        (true, false) | (false, true) => -4.0,
        (false, false) => 0.0,
    };
    let x = real(step * indent + doc.position(item).x);
    let font = match amod(f64::from(item.p(12)), 100.0) {
        0.0 => DEFAULT_FONT,
        p => trunc(p + 1000.0) as f32,
    };
    let size = match item.p(15) {
        0.0 => constant(SIZE),
        p15 => real(f64::from(p15) * constant(SIZE)),
    };
    let size = if ip(item, 4).abs() > 99 { real(size * constant(GRACE_SIZE)) } else { size };
    // draw_note reads P10 = 110 as 10 before anything else.
    let p10 = if ip(item, 10) == 110 { 10.0 } else { item.p(10) };
    let colour = if item.p(26) != 0.0 || item.p(25) != 0.0 {
        Some(item.p(26))
    } else {
        (item.p(14) == -1.0).then(|| item.p(16))
    };
    TextCall {
        text,
        origin: Pos::new(x, doc.staff_of(item).y(level)),
        p3: item.p(3),
        item_code: item.code(),
        step: Some(step),
        staff: item.staff(),
        spread: SPREAD,
        width: size as f32,
        height: 0.0,
        font_override: font as i32,
        rotation: item.p(13),
        space: p10,
        shift: p10,
        colour,
        current_font,
    }
}

/// P20 = 1: a white box over the string line behind the number.
fn clear_behind(item: ItemRef<'_>, staff: &Staff, step: f64, level: f64, fret: i32, canvas: &mut Canvas<'_>) {
    let mut width = match fret {
        -1 => constant(2.3),
        f if f > 9 => constant(3.35),
        _ => constant(2.2),
    };
    let mut p3 = f64::from(item.p(3));
    if item.p(12) >= 100.0 {
        p3 = real(p3 + constant(0.25));
        width = real(width + constant(0.16));
        if fret == -1 {
            p3 = real(p3 + constant(0.2));
        }
    }
    let y = staff.y(f64::from(trunc(level + 1.0)));
    let x = real(staff.step / 35.0 * 160.0 + p3 * P3_UNIT);
    white_box(canvas, Pos::new(x, y), step, (width, 1.0));
}
