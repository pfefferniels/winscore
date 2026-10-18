//! The engine's character tables for text, copied from WScore.exe.
//!
//! Glyph codes are the engine's: 0–161 index the width tables of the font
//! metric files (`score_format::fmt`), 80–82 and 88–92 are drawn as library
//! symbols, 83–87 and 126 are accents that combine with the next glyph, 94
//! is the space, and codes from 162 up are further symbols.

/// Glyph code of every byte of a string (0x78F164). Bytes from 128 up read
/// whatever follows the 128-entry table, as the engine does; `_` is 1100.
#[rustfmt::skip]
const CHAR_CODES: [i16; 256] = [
    100, 0, 101, 0, 102, 0, 103, 0, 104, 0, 105, 0, 106, 0, 107, 0, 108, 0, 109, 0, 110, 0, 112, 0,
    113, 0, 115, 0, 121, 0, 122, 0, 94, 69, 78, 132, 133, 134, 135, 76, 38, 39, 72, 70, 37, 71, 36, 73,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 66, 67, 138, 74, 139, 68, 140, 10, 11, 12, 13, 14, 15, 16,
    17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 88, 73, 89, 85, 1100,
    75, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62,
    63, 64, 65, 90, 92, 91, 126, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 54, 0, 29, 0, 160, 0, 1, 0, 55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 13107, 16051, 0, 16652,
    13107, 16563, 13107, 16563, 13107, 16563, 13107, 16051, 0, 0, 0, 0, 0, 0, 54, 0, 29, 0, 1, 0, 128, 0,
    55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 16904, 0, 17159, 0, 17159, 0, 16904,
];

pub fn char_code(byte: u8) -> i32 {
    i32::from(CHAR_CODES[usize::from(byte)])
}

pub const SPACE: i32 = 94;
pub const QUESTION: i32 = 68;
pub const EXCLAMATION: i32 = 69;
pub const SLASH: i32 = 73;
pub const DOUBLE_QUOTE: i32 = 78;
pub const TILDE: i32 = 126;
pub const UNDERSCORE: i32 = 1100;

/// `?x`: the characters after `?` that name a glyph, and their glyphs
/// (0x78F0B4, 0x78F03C).
const QUERY_ESCAPES: [(u8, i32); 29] = [
    (b'-', 137), (b'0', 163), (b'1', 80), (b'2', 81), (b'3', 82), (b'9', 164), (b'A', 141), (b'E', 142),
    (b'L', 143), (b'O', 144), (b'[', 145), (b'\\', 146), (b']', 147), (b'a', 148), (b'c', 149), (b'd', 162),
    (b'e', 150), (b'i', 151), (b'l', 152), (b'o', 153), (b'r', 154), (b's', 155), (b't', 156), (b'{', 157),
    (b'|', 158), (b'}', 159), (b'f', 160), (b'm', 161), (b'8', 166),
];

pub fn query_escape(next: u8) -> Option<i32> {
    QUERY_ESCAPES.iter().find(|&&(c, _)| c == next).map(|&(_, code)| code)
}

/// `!x`: the k-th character of this list (from 1) names glyph 100 + k (0x78F128).
const BANG_ESCAPES: &[u8; 31] = b"0123456789ADSZadefghijklmnpqsyz";

pub fn bang_escape(next: u8) -> Option<i32> {
    BANG_ESCAPES.iter().position(|&c| c == next).map(|k| k as i32 + 101)
}

/// `~x` with one of these letters puts a tilde accent on it (0x78F028).
pub fn takes_tilde(next: u8) -> bool {
    b"aAnNoO".contains(&next)
}

/// `~n~` starts a tab stop when the character after the first `~` lies in
/// this range (0x75FF48, 0x75FF44).
pub fn starts_tab(next: u8) -> bool {
    (b'.'..=b'9').contains(&next)
}

/// The character the shell draws for glyphs 0–94 (0x7A0008).
const GLYPH_CHARS: &[u8] =
    b"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ.,()abcdefghijklmnopqrstuvwxyz:;?!+-*/=`'\"\"&#$%&[]<>@      ";

/// The cp1252 character of an ordinary glyph.
pub fn glyph_char(code: i32) -> u8 {
    usize::try_from(code).ok().and_then(|i| GLYPH_CHARS.get(i)).copied().unwrap_or(0)
}

/// Glyphs 95–161 and 167 as cp1252 characters (0x7970A4, 0x79706B); the
/// emitter falls back to bytes before 0x7A0008 for codes missing here.
#[rustfmt::skip]
const EXTENDED_CHARS: [(i32, u8); 63] = [
    (145, b'['), (146, b'\\'), (147, b']'), (157, b'{'), (158, b'|'), (159, b'}'), (137, b'-'), (149, 0xA9),
    (148, 0xE6), (141, 0xC6), (115, 0xE5), (111, 0xC5), (121, b'X'), (150, 0x9C), (142, 0x8C), (117, 0x85),
    (153, b'x'), (144, b'X'), (130, 0xA5), (160, 0xAA), (152, b'l'), (143, b'L'), (161, 0xBA), (154, 0xAE),
    (155, 0xDF), (156, 0x99), (101, b'X'), (102, 0x84), (103, 0x94), (104, 0xA1), (105, 0xA2), (106, b'L'),
    (107, 0xA7), (108, b'X'), (109, b'\''), (110, 0x93), (116, 0x86), (112, 0x87), (118, 0x83), (119, 0xAB),
    (120, 0xBB), (122, 0x8B), (123, 0x9B), (124, b'X'), (125, 0x97), (167, b'X'), (127, 0xB6), (128, 0xBF),
    (129, 0x9A), (113, 0x8A), (131, b'z'), (114, b'Z'), (140, b'@'), (132, b'#'), (133, b'$'), (134, b'%'),
    (135, b'&'), (138, b'<'), (139, b'>'),
    (96, b'L'), (100, b'J'), (136, b'!'), (151, 0x01),
];

pub fn extended_char(code: i32) -> u8 {
    EXTENDED_CHARS.iter().find(|&&(c, _)| c == code).map_or(0, |&(_, ch)| ch)
}

/// The characters SCORE prints where the screen shows a stand-in (help:
/// "Some characters will only appear as an X"): glyphs below 95 print as
/// the bytes of 0x7A0008 in Adobe's standard encoding (` and ' are curly
/// quotes), the others as the octal codes of table 0x79FD7C (0x56DAA0) in
/// fonts re-encoded with FMFONTINIT.PSC's `acc`, where 365 is onesuperior.
/// Glyph 167 is the screen's code for 126 (`!n`), an en dash. The `""`
/// glyph 77 prints as the straight quote the screen shows.
#[rustfmt::skip]
const PRINTED_CHARS: [(i32, char); 16] = [
    (75, '‘'), (76, '’'), (101, '•'), (106, '£'), (108, '¤'), (114, 'Ž'), (121, 'ﬁ'), (124, 'ﬂ'),
    (131, 'ž'), (137, '−'), (143, 'Ł'), (144, 'Ø'), (151, '¹'), (152, 'ł'), (153, 'ø'), (167, '–'),
];

/// The printed character of a glyph the screen draws with a stand-in.
pub fn printed_char(code: i32) -> Option<char> {
    PRINTED_CHARS.iter().find(|&&(c, _)| c == code).map(|&(_, ch)| ch)
}

/// The accented cp1252 character, or the base character if the accent does
/// not apply to it. Accents combine with the following glyph (0x532EC0): 83
/// acute, 84 grave, 85 circumflex, 86 dieresis, 87 cedilla, 126 tilde.
pub fn accented(accent: i32, base: u8) -> u8 {
    let table: &[(u8, u8)] = match accent {
        83 => &ACUTE,
        84 => &GRAVE,
        85 => &CIRCUMFLEX,
        86 => &DIERESIS,
        87 => &CEDILLA,
        _ => &TILDE_LETTERS,
    };
    table.iter().find(|&&(b, _)| b == base).map_or(base, |&(_, a)| a)
}

/// [`accented`] as SCORE prints it: `%%Y` is Ÿ there too (0x56EBB4).
pub fn printed_accented(accent: i32, base: u8) -> u8 {
    match (accent, base) {
        (86, b'Y') => 0x9F,
        _ => accented(accent, base),
    }
}

const ACUTE: [(u8, u8); 12] = [
    (b'A', 0xC1), (b'a', 0xE1), (b'E', 0xC9), (b'e', 0xE9), (b'I', 0xCD), (b'i', 0xED),
    (b'O', 0xD3), (b'o', 0xF3), (b'U', 0xDA), (b'u', 0xFA), (b'Y', 0xDD), (b'y', 0xFD),
];
const GRAVE: [(u8, u8); 10] = [
    (b'A', 0xC0), (b'a', 0xE0), (b'E', 0xC8), (b'e', 0xE8), (b'I', 0xCC), (b'i', 0xEC),
    (b'O', 0xD2), (b'o', 0xF2), (b'U', 0xD9), (b'u', 0xF9),
];
const CIRCUMFLEX: [(u8, u8); 10] = [
    (b'A', 0xC2), (b'a', 0xE2), (b'E', 0xCA), (b'e', 0xEA), (b'I', 0xCE), (b'i', 0xEE),
    (b'O', 0xD4), (b'o', 0xF4), (b'U', 0xDB), (b'u', 0xFB),
];
const DIERESIS: [(u8, u8); 11] = [
    (b'A', 0xC4), (b'a', 0xE4), (b'E', 0xCB), (b'e', 0xEB), (b'I', 0xCF), (b'i', 0xEF),
    (b'O', 0xD6), (b'o', 0xF6), (b'U', 0xDC), (b'u', 0xFC), (b'y', 0xFF),
];
const CEDILLA: [(u8, u8); 2] = [(b'C', 0xC7), (b'c', 0xE7)];
const TILDE_LETTERS: [(u8, u8); 6] = [(b'A', 0xC3), (b'a', 0xE3), (b'o', 0xF5), (b'O', 0xD5), (b'n', 0xF1), (b'N', 0xD1)];

/// Widths of the library-symbol glyphs, and of every glyph of the fonts
/// from 90 up, in the units of the metric tables (0x1C6DA5C, filled at
/// start-up), by glyph code + 1.
#[rustfmt::skip]
const SYMBOL_WIDTHS: [f32; 106] = [
    0.0, 0.8, 0.72, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 1.08, 1.08, 1.08, 1.08, 1.08,
    1.08, 1.08, 1.08, 0.735, 0.735, 1.08, 1.08, 1.2, 1.08, 1.08, 1.08, 1.08, 1.08, 1.08, 1.08, 1.08,
    1.08, 1.2, 1.08, 1.08, 1.08, 0.68, 0.68, 0.735, 0.735, 0.96, 0.96, 0.96, 0.96, 0.96, 0.65, 0.96,
    0.96, 0.65, 0.65, 0.96, 0.65, 1.075, 0.96, 0.96, 0.96, 0.96, 0.96, 0.96, 0.65, 0.96, 0.96, 1.075,
    0.96, 0.96, 0.96, 0.68, 0.68, 0.75, 0.75, 0.9, 0.9, 0.9, 1.0, 0.9, 0.68, 0.68, 0.85, 0.96,
    1.08, 0.9, 0.9, 0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 1.04, 1.04, 1.4, 1.4, 1.08, 1.4, 0.7,
    1.2, 0.9, 0.8, 1.08, 0.9, 0.7, 0.7, 0.9, 0.9, 1.08,
];

pub fn symbol_width(index: i32) -> f32 {
    usize::try_from(index).ok().and_then(|i| SYMBOL_WIDTHS.get(i)).copied().unwrap_or(0.0)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn ascii_codes_index_the_metric_tables() {
        assert_eq!([b'0', b'A', b'.', b'a', b' ', b'#', b'@'].map(char_code), [0, 10, 36, 40, 94, 132, 140]);
        assert_eq!(char_code(b'_'), UNDERSCORE);
        assert_eq!(glyph_char(char_code(b'z')), b'z');
    }

    #[test]
    fn escapes() {
        assert_eq!(query_escape(b'c').map(extended_char), Some(0xA9));
        assert_eq!(bang_escape(b'a').map(extended_char), Some(0xE5));
        assert_eq!(accented(86, b'o'), 0xF6);
        assert_eq!(accented(87, b'a'), b'a');
    }

    #[test]
    fn printed_characters_replace_the_stand_ins() {
        assert_eq!(bang_escape(b'5').and_then(printed_char), Some('£'));
        assert_eq!(query_escape(b'L').and_then(printed_char), Some('Ł'));
        assert_eq!(printed_char(char_code(b'\'')), Some('’'));
        assert_eq!(printed_char(char_code(b'"')), None);
        assert_eq!(printed_char(char_code(b'A')), None);
        assert_eq!((accented(86, b'Y'), printed_accented(86, b'Y')), (b'Y', 0x9F));
    }
}
