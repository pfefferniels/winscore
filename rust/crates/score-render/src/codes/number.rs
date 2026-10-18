//! Code 10: numbers and rehearsal letters (draw_number 0x4F65A8).
//!
//! draw_number writes the number as a string ([`number_text`]), hands it to
//! the text routine draw_text 0x569AF0 and, for P8 = 1 or 2, draws a circle
//! or box round it through draw_box and the text once more. Clefs (octave
//! numbers), meters, staff numbers, tuplet and rest numbers call it with
//! parameters of their own: [`draw_number`] takes them as a [`NumberCall`].
//!
//! P5 number (-999.999 to 999.999), 1001… letters A…, 2001… a…; P6 size;
//! P7 font; P8 circle (1) or box (2), P10 its thickness, P11/P12 its size,
//! P13/P14 its displacement; P17 a letter after a number; P18 numbers from
//! 1000 on, or letters after a rehearsal letter; P19 rotation; P20 spread.

use crate::canvas::Canvas;
use crate::codes::boxes::{draw_styled_box, BoxCall};
use crate::codes::text::font_before;
use crate::document::{Document, ItemRef};
use crate::text::{self, draw_text, Font, TextCall};
use crate::units::{amod, real, trunc, Pos};

/// What draw_number reads from P() and IP() besides the position: the
/// item's parameters for a code-10 item, the caller's settings otherwise.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct NumberCall {
    /// The integer passed by reference (IP5 for a code-10 item).
    pub value: i32,
    /// P5.
    pub p5: f32,
    /// P6: size; the hundreds are part-extraction flags, 0 reads as 1.
    pub size: f32,
    /// IP7: 0-10 the fonts of the help text (6 the meter font), from 90 on
    /// a font code as draw_text takes it (1000 + n = font n).
    pub font: i32,
    /// IP8: 1 circle, 2 box round the number.
    pub frame: i32,
    /// IP10: thickness of the circle or box (0 reads as 1).
    pub frame_thickness: i32,
    /// P11 and its integer part: the frame's width (0: from the text length).
    pub p11: f32,
    pub ip11: i32,
    /// P12: the frame's height.
    pub p12: f32,
    /// P13, P14: vertical and horizontal displacement of the frame.
    pub p13: f32,
    pub p14: f32,
    /// IP17, P18: letters and extended numbers, see [`number_text`].
    pub p17: i32,
    pub p18: f32,
    /// P19: rotation in degrees.
    pub rotation: f32,
    /// P20: spread of the digits.
    pub spread: f32,
    /// P26: the colour, given to draw_text as P14 = -1, P16 = P26.
    pub p26: f32,
    /// P1, P2, P3, P4 of the item being drawn.
    pub item_code: i32,
    pub staff: i32,
    pub p3: f32,
    pub p4: f32,
    /// STEP when the caller scales it (rests: staff step × P15); `None` is
    /// the staff's. Applies to the frame and to draw_text.
    pub step: Option<f64>,
}

impl NumberCall {
    /// The parameters of a code-10 item.
    pub fn of(item: ItemRef<'_>) -> Self {
        let p = |n: usize| item.p(n);
        let ip = |n: usize| trunc(f64::from(item.p(n)));
        Self {
            value: ip(5),
            p5: p(5),
            size: p(6),
            font: ip(7),
            frame: ip(8),
            frame_thickness: ip(10),
            p11: p(11),
            ip11: ip(11),
            p12: p(12),
            p13: p(13),
            p14: p(14),
            p17: ip(17),
            p18: p(18),
            rotation: p(19),
            spread: p(20),
            p26: p(26),
            item_code: item.code(),
            staff: item.staff(),
            p3: p(3),
            p4: p(4),
            step: None,
        }
    }

    /// The font code draw_text receives (IP8): IP7 through the table at
    /// 0x794FF4, from 90 on as given.
    fn font_override(&self) -> i32 {
        match self.font.max(0) {
            f if f >= DIRECT_FONTS => f,
            f => {
                let f = if f > 10 { f - 1 } else { f };
                FONTS[if f > 10 { 0 } else { f as usize }]
            }
        }
    }

    /// P6 after AMOD 100, 0 read as 1.
    fn size(&self) -> f32 {
        match real(amod(f64::from(self.size), SIZE_FLAGS)) as f32 {
            0.0 => 1.0,
            s => s,
        }
    }
}

/// Font codes for P7 = 0-10 (table 0x794FF4).
const FONTS: [i32; 11] = [1000, 1002, 1004, 1024, 1026, 1006, 94, 1025, 1027, 1001, 1003];
/// P7 from this value on reaches draw_text unchanged.
const DIRECT_FONTS: i32 = 90;
const SIZE_FLAGS: f64 = 100.0;
/// The meter font gets no colour override.
const METER_FONT: i32 = 94;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    draw_number(doc, item, canvas, doc.position(item), &NumberCall::of(item));
}

/// The string draw_number writes for a code-10 item.
pub fn item_text(item: ItemRef<'_>) -> Vec<u8> {
    let call = NumberCall::of(item);
    number_text(call.value, call.p5, call.p17, call.p18)
}

/// The draw_text call draw_number makes for a code-10 item, given its
/// string from [`item_text`].
pub fn text_call<'t>(doc: &Document<'_>, item: ItemRef<'_>, text: &'t [u8]) -> TextCall<'t> {
    number_text_call(&NumberCall::of(item), doc.position(item), text, font_before(doc, item))
}

/// The font a code-10 item leaves loaded (see [`text::font_loaded`]).
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    number_font_loaded(doc, doc.position(item), &NumberCall::of(item))
}

/// The font draw_number leaves loaded for `call` at `at`; the frame's
/// second drawing of the text loads the same.
pub fn number_font_loaded(doc: &Document<'_>, at: Pos, call: &NumberCall) -> Option<Font> {
    let text = number_text(call.value, call.p5, call.p17, call.p18);
    text::font_loaded(doc, &number_text_call(call, at, &text, Font::TIMES))
}

/// The draw_text call draw_number makes for `call` with its string `text`
/// at X_POS, Y_POS = `at`.
pub fn number_text_call<'t>(call: &NumberCall, at: Pos, text: &'t [u8], current_font: Font) -> TextCall<'t> {
    let font_override = call.font_override();
    TextCall {
        text,
        origin: at,
        p3: call.p3,
        item_code: call.item_code,
        staff: call.staff,
        spread: call.spread,
        width: call.size(),
        height: 0.0,
        font_override,
        rotation: call.rotation,
        space: 0.0,
        shift: 0.0,
        colour: (call.p26 != 0.0 && font_override != METER_FONT).then_some(call.p26),
        step: call.step,
        current_font,
    }
}

/// draw_number 0x4F65A8 at X_POS, Y_POS = `at`, for the item being drawn.
/// The engine draws a framed number's text again after the frame; the
/// refined style draws it once.
pub fn draw_number(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, at: Pos, call: &NumberCall) {
    let text = number_text(call.value, call.p5, call.p17, call.p18);
    let text_call = number_text_call(call, at, &text, font_before(doc, item));
    draw_text(doc, item, canvas, &text_call);
    if call.frame != 0 {
        let step = call.step.unwrap_or_else(|| doc.staves.get(call.staff).step);
        let width = text::width(doc, &text_call);
        let (centre, frame) = frame(doc, call, at, step, (text.len(), width), text_call.font_override);
        draw_styled_box(doc, canvas, centre, step, &frame);
        if !doc.refined() {
            draw_text(doc, item, canvas, &text_call);
        }
    }
}

/// Frame position and size factors (0x4F70C1–0x4F73B1).
const FRAME_X_UNIT: f32 = 75.0;
const MUSIC_FONT_SHIFT: f32 = 1.2;
const FRAME_LIFT: f32 = 1.55;
const SINGLE_WIDTH: f32 = 5.0;
const WIDE_SPREAD: f32 = 1000.0;
const WIDE_EXTRA: f32 = 1.5;
const THICK_FRAME_HEIGHT: f32 = 6.0;
const BOX_HEIGHT: f32 = 5.0;
/// Degrees per side of a number's circle on the screen.
const CIRCLE_SIDES: i32 = 4;

/// The circle or box round a number: its centre and draw_box's parameters.
/// `text` is the string's length in characters and its width in P3 units
/// (the P13 draw_text leaves), which centres the frame: x = X_POS + 75 ×
/// (P14 + width).
fn frame(doc: &Document<'_>, call: &NumberCall, at: Pos, step: f64, text: (usize, f32), font: i32) -> (Pos, BoxCall) {
    let (length, text_width) = text;
    let size = f64::from(call.size());
    let shift = real(f64::from(call.p14) + f64::from(text_width));
    let x = real(shift * f64::from(FRAME_X_UNIT) + at.x);
    let x = if font % 100 > 89 { real(x - step * f64::from(MUSIC_FONT_SHIFT) * size) } else { x };
    let thickness = if call.frame_thickness == 0 { 1 } else { call.frame_thickness };
    let kind = 2 - call.frame;
    let level = real(size * f64::from(FRAME_LIFT) + f64::from(call.p4) + f64::from(call.p13));
    let y = doc.staves.get(call.staff).y(level);
    let (width, height, ip12) = if call.ip11 == 0 {
        let wide = match length {
            0 | 1 => f64::from(SINGLE_WIDTH),
            n => {
                let w = (n * 2 + 2) as f64;
                if call.spread > WIDE_SPREAD { w + f64::from(WIDE_EXTRA) } else { w }
            }
        };
        let tall = match (call.p12, thickness) {
            (p12, _) if p12 != 0.0 => f64::from(p12),
            (_, 2) => f64::from(THICK_FRAME_HEIGHT),
            _ => wide,
        };
        if kind == 0 {
            (real(wide * size), real(size * f64::from(BOX_HEIGHT)), 0)
        } else {
            (real(size * tall), 0.0, CIRCLE_SIDES)
        }
    } else {
        let p12 = if call.p12 == 0.0 { call.p11 } else { call.p12 };
        let ip12 = if kind != 0 { CIRCLE_SIDES } else { 0 };
        (real(size * f64::from(call.p11)), real(size * f64::from(p12)), ip12)
    };
    let frame = BoxCall {
        kind,
        width,
        height,
        p8: f64::from(thickness),
        ip8: thickness,
        p9: f64::from(call.rotation),
        ip9: 0,
        p10: 0.0,
        ip10: 0,
        ip11: 0,
        ip12,
        fill: false,
        p16: 0.0,
    };
    (Pos::new(x, y), frame)
}

/// Rehearsal letters start above this P5.
const LAST_NUMBER: i32 = 1000;
/// Lower-case letters start above this P5; 2001 maps onto `a`.
const LAST_UPPER: i32 = 2000;
const UPPER_TO_LOWER: i32 = 968;
/// P5 1001 is `A`: the character is P5 − 936.
const LETTER_BASE: i32 = 936;
/// P17 1–26 is `A`–`Z`, 101–126 `a`–`z`.
const P17_UPPER_BASE: i32 = 64;
const P17_LOWER_OFFSET: i32 = 4;
/// Added before the fraction is taken to three decimals.
const FRACTION_BIAS: f32 = 0.0003;

/// The string draw_number writes into the text buffer (0x20B8EA0): the
/// integer part of `p5` (`value` is the integer the caller passes, IP5 for a
/// code-10 item) with up to three decimals, a following letter (`p17`), or
/// a rehearsal letter with what `p18` adds. Formats as the engine's
/// internal writes do, overflow stars included.
pub fn number_text(value: i32, p5: f32, p17: i32, p18: f32) -> Vec<u8> {
    let negative = p5 < 0.0;
    let whole = if negative { -value } else { value };
    let magnitude = if negative { -p5 } else { p5 };
    let (text, thousandths) = if whole > LAST_NUMBER {
        (rehearsal_letter(whole, p18), fraction_digits(magnitude, whole))
    } else if p18.abs() >= 1000.0 {
        let extended = p18 as i32;
        let text = fortran_int(extended, if extended < 0 { 5 } else { 4 });
        (text, fraction_digits(p18.abs(), extended.abs()))
    } else {
        (whole_number(whole, negative, p17), fraction_digits(magnitude, whole))
    };
    with_decimals(trim_end(text), thousandths)
}

/// The integer part, a letter after it (P17) and the sign.
fn whole_number(whole: i32, negative: bool, p17: i32) -> Vec<u8> {
    let mut text = match whole {
        w if w < 10 => vec![b'0' + w as u8],
        w if w < 100 => fortran_int(w, 2),
        w => fortran_int(w, 3),
    };
    if p17 != 0 {
        let letter = if p17 > 100 { p17 - P17_LOWER_OFFSET } else { p17 + P17_UPPER_BASE };
        text.push(letter as u8);
    }
    if negative {
        text.insert(0, b'-');
    }
    text
}

/// A rehearsal letter (P5 > 1000) and what P18 adds to it.
fn rehearsal_letter(whole: i32, p18: f32) -> Vec<u8> {
    let letter = if whole > LAST_UPPER { whole - UPPER_TO_LOWER } else { whole };
    let mut text = vec![(letter - LETTER_BASE) as u8];
    if p18 != 0.0 {
        text.extend(rehearsal_suffix(p18 as i32));
    }
    text
}

/// Appends `.ddd` without trailing zeros, first dropping a leading zero
/// (`0.5` is written `.5`).
fn with_decimals(mut text: Vec<u8>, thousandths: i32) -> Vec<u8> {
    if thousandths == 0 {
        return text;
    }
    match text.as_slice() {
        [b'0', ..] => {
            text.remove(0);
        }
        [b'-', b'0', ..] => {
            text.remove(1);
        }
        _ => {}
    }
    text.push(b'.');
    text.extend(format!("{thousandths:03}").bytes());
    while text.last() == Some(&b'0') {
        text.pop();
    }
    text
}

/// trunc(f32(magnitude − whole + 0.0003) × 1000).
fn fraction_digits(magnitude: f32, whole: i32) -> i32 {
    let fraction = (magnitude - whole as f32) + FRACTION_BIAS;
    (f64::from(fraction) * 1000.0) as i32
}

/// What P18 adds to a rehearsal letter: up to two digits, or `xxyy` = one
/// or two more letters (upper case, or lower case for negative P18).
fn rehearsal_suffix(p18: i32) -> Vec<u8> {
    if p18.abs() < 100 {
        let digits = p18 % 100;
        return fortran_int(digits, if digits < 10 { 1 } else { 2 });
    }
    let base = if p18 < 0 { 96 } else { 64 };
    let p18 = p18.abs();
    let second = (p18 / 100 + base) as u8;
    match p18 % 100 {
        0 => vec![second],
        third => vec![second, (third + base) as u8],
    }
}

/// Fortran `Iw`: right-justified in `width` characters, stars if it does not fit.
fn fortran_int(value: i32, width: usize) -> Vec<u8> {
    let digits = value.to_string();
    if digits.len() > width {
        vec![b'*'; width]
    } else {
        format!("{digits:>width$}").into_bytes()
    }
}

/// LEN_TRIM: the text without trailing blanks.
fn trim_end(mut text: Vec<u8>) -> Vec<u8> {
    while text.last() == Some(&b' ') {
        text.pop();
    }
    text
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::document::Options;
    use crate::render;
    use score_format::{Item, MusFile, Word};

    /// A size-1 staff 1 and `number`.
    fn file(number: &[f32]) -> MusFile {
        let trailer = [0.0_f32, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = (trailer.len() as u16).to_le_bytes().to_vec();
        bytes.extend(trailer.iter().flat_map(|w| w.to_le_bytes()));
        let mut file = MusFile::parse(&bytes).expect("an empty file parses");
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        file.items = vec![words(&[8.0, 1.0, 0.0, 0.0, 1.0]), words(number)];
        file
    }

    #[test]
    fn the_refined_style_draws_a_framed_number_once() {
        let boxed = file(&[10.0, 1.0, 50.0, 12.0, 7.0, 1.0, 0.0, 2.0]);
        let runs = |options: Options| {
            let list = render(&Document::with_options(&boxed, options));
            list.texts.iter().filter(|t| t.source == Some(crate::ItemId(1))).count()
        };
        assert_eq!((runs(Options::ENGINE), runs(Options::REFINED)), (2, 1));
    }

    fn text(p5: f32, p17: i32, p18: f32) -> String {
        String::from_utf8(number_text(p5 as i32, p5, p17, p18)).unwrap()
    }

    #[test]
    fn numbers() {
        assert_eq!(text(5.0, 0, 0.0), "5");
        assert_eq!(text(123.0, 0, 0.0), "123");
        assert_eq!(text(12.5, 0, 0.0), "12.5");
        assert_eq!(text(0.5, 0, 0.0), ".5");
        assert_eq!(text(-2.5, 0, 0.0), "-2.5");
        assert_eq!(text(-0.5, 0, 0.0), "-.5");
        assert_eq!(text(3.125, 0, 0.0), "3.125");
        assert_eq!(text(1000.0, 0, 0.0), "***");
    }

    #[test]
    fn letters() {
        assert_eq!(text(97.0, 102, 0.0), "97b");
        assert_eq!(text(5.0, 1, 0.0), "5A");
        assert_eq!(text(1001.0, 0, 0.0), "A");
        assert_eq!(text(2001.0, 0, 0.0), "a");
        assert_eq!(text(1002.0, 0, 12.0), "B12");
        assert_eq!(text(1001.0, 0, 100.0), "AA");
        assert_eq!(text(1003.0, 0, 226.0), "CBZ");
        assert_eq!(text(1004.0, 0, -100.0), "Da");
    }

    #[test]
    fn extended_numbers() {
        assert_eq!(text(0.0, 0, 1234.0), "1234");
        assert_eq!(text(7.0, 0, -1234.0), "-1234");
    }
}
