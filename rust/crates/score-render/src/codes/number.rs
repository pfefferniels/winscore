//! Code 10: numbers and rehearsal letters (draw_number 0x4F65A8).
//!
//! draw_number writes the number as a string and hands it to the text
//! routine draw_text 0x569AF0, then draws a circle or box round it (P8)
//! through draw_box. Clefs (octave numbers), meters, staff numbers, tuplet
//! and rest numbers call it too. The drawing waits on the shared text
//! module; [`number_text`] is the string.
//!
//! P5 number (-999.999 to 999.999), 1001… letters A…, 2001… a…; P17 a
//! letter after a number; P18 numbers from 1000 on, or letters after a
//! rehearsal letter.

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};

pub fn render(_doc: &Document<'_>, _item: ItemRef<'_>, _canvas: &mut Canvas<'_>) {}

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
