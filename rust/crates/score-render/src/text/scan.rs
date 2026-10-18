//! Reading a string into glyphs, font changes and tab stops with their
//! advances, as the engine's text parser does (0x42FA58).

use super::fonts::{Font, FontLibrary};
use super::glyphs::{
    self, bang_escape, char_code, query_escape, starts_tab, takes_tilde, DOUBLE_QUOTE, EXCLAMATION, QUESTION,
    SLASH, SPACE, TILDE, UNDERSCORE,
};
use crate::units::real;

/// One element of a string, in the order of the engine's code array.
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Code {
    /// A font change (`_nn`); the engine stores 1000 + font.
    Font(Font),
    /// A tab stop `~n~` at n P3 units, in tenths.
    Tab(i32),
    /// A glyph code below 1000.
    Glyph(i32),
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Entry {
    pub code: Code,
    /// In P3 units; zero for font changes, tabs and accents.
    pub advance: f32,
    /// The byte from 128 up that the glyph was read from, see [`Token::High`].
    pub byte: Option<u8>,
}

/// What the parser reads, before widths: the syntax of a string.
#[derive(Debug, Clone, Copy, PartialEq)]
enum Token {
    Glyph(i32),
    /// A byte from 128 up, read as whatever follows the character table
    /// (é as glyph 0, "0"); the refined style draws its cp1252 character.
    High { glyph: i32, byte: u8 },
    /// `""`: a glyph that depends on the font.
    DoubleQuote,
    /// `_nn` or `__nn`; `digits` are the two characters after the underscores.
    Font { outline: bool, digits: [u8; 2] },
    /// `~a`, `~n`, ...: a tilde over the next glyph.
    TildeAccent,
    /// `~n~`, the number as written.
    Tab(f32),
}

/// The tokens of a string. The engine reads one character past the end,
/// where it has put a blank.
struct Tokens<'t> {
    text: &'t [u8],
    at: usize,
}

impl Tokens<'_> {
    fn byte(&self, i: usize) -> u8 {
        self.text.get(i).copied().unwrap_or(b' ')
    }

    fn next_byte(&self) -> u8 {
        self.byte(self.at + 1)
    }

    /// `\\nnn` (or `//nnn`): three digits read as a decimal number of at
    /// least 129 and then as octal; the character, or `O` if it lies outside
    /// 32–125.
    fn octal(&self) -> Option<u8> {
        let digits: Vec<u8> = (self.at + 2..self.at + 5).map(|i| self.byte(i)).collect();
        let text = std::str::from_utf8(&digits).ok()?;
        if !digits.iter().all(u8::is_ascii_digit) || text.parse::<u32>().ok()? < 129 {
            return None;
        }
        let value = u32::from_str_radix(text, 8).ok()?;
        Some(match u8::try_from(value) {
            Ok(b'^') => b'@',
            Ok(c @ 32..=125) => c,
            _ => b'O',
        })
    }

    /// A character that does not repeat (and repeated ones the doubled
    /// rules leave alone).
    fn single(&mut self, code: i32) -> Option<Token> {
        let next = self.next_byte();
        let token = match code {
            QUESTION => match query_escape(next) {
                Some(escaped) => {
                    self.at += 1;
                    Token::Glyph(escaped)
                }
                None => Token::Glyph(code),
            },
            EXCLAMATION => match bang_escape(next) {
                Some(escaped) => {
                    self.at += 1;
                    // The screen shows glyph 126 as 167.
                    Token::Glyph(if escaped == TILDE { 167 } else { escaped })
                }
                None => Token::Glyph(code),
            },
            UNDERSCORE => self.font(false),
            TILDE if takes_tilde(next) => Token::TildeAccent,
            TILDE if starts_tab(next) => return self.tab(),
            _ => Token::Glyph(code),
        };
        Some(token)
    }

    /// A character followed by the same character.
    fn doubled(&mut self, code: i32) -> Option<Token> {
        let token = match code {
            ..DOUBLE_QUOTE | 79..=84 | SPACE => Token::Glyph(code),
            DOUBLE_QUOTE => {
                self.at += 1;
                Token::DoubleQuote
            }
            85 | 86 => {
                self.at += 1;
                Token::Glyph(code)
            }
            // `##` cedilla, `%%` dieresis, `<<` acute, `>>` grave.
            132 | 134 | 138 | 139 => {
                self.at += 1;
                Token::Glyph(match code {
                    132 => 87,
                    134 => 86,
                    _ => code - 55,
                })
            }
            UNDERSCORE => {
                self.at += 1;
                self.font(true)
            }
            _ => return self.single(code),
        };
        Some(token)
    }

    fn font(&mut self, outline: bool) -> Token {
        let digits = [self.byte(self.at + 1), self.byte(self.at + 2)];
        self.at += 2;
        Token::Font { outline, digits }
    }

    /// `~n~`: the number up to the next `~`; without one the `~` is dropped.
    fn tab(&mut self) -> Option<Token> {
        let start = self.at + 1;
        let close = (start..self.text.len()).find(|&i| self.text[i] == b'~')?;
        self.at = close;
        let value = std::str::from_utf8(&self.text[start..close]).ok().and_then(|s| s.trim().parse::<f32>().ok());
        Some(Token::Tab(value.unwrap_or(0.0)))
    }
}

impl Iterator for Tokens<'_> {
    type Item = Token;

    fn next(&mut self) -> Option<Token> {
        while self.at < self.text.len() {
            let token = self.token();
            self.at += 1;
            if token.is_some() {
                return token;
            }
        }
        None
    }
}

impl Tokens<'_> {
    /// The token starting at the current character; `None` for an unclosed tab.
    fn token(&mut self) -> Option<Token> {
        let mut char = self.byte(self.at);
        // No code past the table is an escape, an accent, a font change or
        // a doubled character: such a byte is always one glyph.
        if char >= FIRST_HIGH_BYTE {
            return Some(Token::High { glyph: char_code(char), byte: char });
        }
        loop {
            let code = char_code(char);
            if self.next_byte() != char {
                return self.single(code);
            }
            match self.octal().filter(|_| code == SLASH) {
                Some(replacement) => {
                    char = replacement;
                    self.at += 4;
                }
                None => return self.doubled(code),
            }
        }
    }
}

/// The result of reading a string.
#[derive(Debug, Clone, PartialEq)]
pub struct Scan {
    pub entries: Vec<Entry>,
    /// The font in effect after the string (0x78B6A0).
    pub font: Font,
    /// P13: the string length in P3 units, times the spread P5.
    pub length: f32,
}

/// What the parser needs besides the string.
#[derive(Debug, Clone, Copy)]
pub struct ScanSettings<'f> {
    pub fonts: &'f FontLibrary,
    pub font: Font,
    /// IP8: from 90 up the string's own font changes are not read.
    pub font_override: i32,
    /// STEP of the staff times P6, over 25.
    pub size: f32,
    /// P10.
    pub space: f32,
    /// P5, 0 read as 1.
    pub spread: f32,
}

/// Bytes from here on lie past the engine's 128-entry character table.
const FIRST_HIGH_BYTE: u8 = 0x80;

/// The engine's ratio between its text scale and the metric units.
const METRIC_UNITS: f32 = 638.0;
/// P3 units per unit of size and width (0x78F024).
const ADVANCE_SCALE: f32 = 3.2833;

/// The parser's main loop (0x42FA58).
pub fn scan(text: &[u8], settings: &ScanSettings<'_>) -> Scan {
    let size = settings.size;
    let mut state = Scanner {
        fonts: settings.fonts,
        font: settings.font,
        font_override: settings.font_override,
        scale: real(f64::from(size) * f64::from(ADVANCE_SCALE)) as f32,
        space: real(f64::from(settings.space) * f64::from(size)) as f32,
        entries: Vec::new(),
        length: 0.0,
    };
    Tokens { text, at: 0 }.for_each(|token| state.push(token));
    let Scanner { mut entries, font, length, .. } = state;
    if matches!(entries.last(), Some(Entry { code: Code::Font(_) | Code::Tab(_), .. })) {
        entries.pop();
    }
    Scan { entries, font, length: real(f64::from(settings.spread) * f64::from(length)) as f32 }
}

struct Scanner<'f> {
    fonts: &'f FontLibrary,
    font: Font,
    font_override: i32,
    scale: f32,
    space: f32,
    entries: Vec<Entry>,
    length: f32,
}

/// The font override from which `_nn` is skipped.
const FIRST_OVERRIDE_FONT: i32 = 90;

impl Scanner<'_> {
    fn push(&mut self, token: Token) {
        let code = match token {
            Token::Glyph(code) | Token::High { glyph: code, .. } => Code::Glyph(code),
            Token::DoubleQuote => Code::Glyph(if self.font.outline() { 110 } else { 77 }),
            Token::TildeAccent => Code::Glyph(TILDE),
            Token::Tab(n) => Code::Tab((f64::from(n) * 10.0) as i32),
            Token::Font { .. } if self.font_override >= FIRST_OVERRIDE_FONT => Code::Font(Font(UNDERSCORE % 1000)),
            Token::Font { outline, digits } => {
                self.font = Font(i32::from(outline) * 100 + font_number(digits));
                Code::Font(self.font)
            }
        };
        let advance = match (token, code) {
            (Token::TildeAccent, _) => 0.0,
            (_, Code::Glyph(glyph)) if !(83..=87).contains(&glyph) => self.advance(glyph),
            _ => 0.0,
        };
        if self.entries.is_empty() && !matches!(code, Code::Font(_)) {
            self.entries.push(Entry { code: Code::Font(self.font), advance: 0.0, byte: None });
        }
        let byte = match token {
            Token::High { byte, .. } => Some(byte),
            _ => None,
        };
        self.entries.push(Entry { code, advance, byte });
    }

    /// The glyph's advance in P3 units; P13 grows by it.
    fn advance(&mut self, glyph: i32) -> f32 {
        let width = self.unit_width(glyph);
        let advance = real(f64::from(self.scale) * f64::from(width));
        let advance = if glyph == SPACE { real(f64::from(self.space) + advance) } else { advance };
        self.length = real(advance + f64::from(self.length)) as f32;
        advance as f32
    }

    /// Width in metric units / 638 (0x42FA58 from 0x43066D on). The engine
    /// counts glyphs from 1 here.
    fn unit_width(&self, glyph: i32) -> f32 {
        let index = if glyph == 167 { 127 } else { glyph + 1 };
        match index {
            81..=83 | 89..=93 => glyphs::symbol_width(index),
            ..=162 => self.font_width(index),
            167 => 0.95,
            164.. => 0.8,
            _ => 0.5,
        }
    }

    fn font_width(&self, index: i32) -> f32 {
        if self.font.uses_symbol_widths() {
            let index = match index {
                150 => 94,
                146 | 148 => (index - 146) / 2 + 101,
                133..=141 => index - 36,
                _ => index,
            };
            return glyphs::symbol_width(index);
        }
        let width = self
            .fonts
            .metrics(self.font.number())
            .and_then(|m| m.width(usize::try_from(index - 1).ok()?))
            .unwrap_or(0);
        (f64::from(width) / f64::from(METRIC_UNITS)) as f32
    }
}

/// The font number of `_nn`: 90–93 are 24–27, 98 is Courier (29), 99 is
/// Helvetica on the screen, anything that is not a number 0–99 is 29.
fn font_number(digits: [u8; 2]) -> i32 {
    let n = (i32::from(digits[0]) - 48) * 10 + i32::from(digits[1]) - 48;
    match n {
        90..=93 => n - 66,
        98 => 29,
        99 => 4,
        0..=97 => n,
        _ => 29,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn tokens(text: &str) -> Vec<Token> {
        Tokens { text: text.as_bytes(), at: 0 }.collect()
    }

    #[test]
    fn escapes_and_fonts() {
        assert_eq!(tokens("_02A"), [Token::Font { outline: false, digits: *b"02" }, Token::Glyph(10)]);
        assert_eq!(tokens("__05"), [Token::Font { outline: true, digits: *b"05" }]);
        assert_eq!(tokens("?c!a"), [Token::Glyph(149), Token::Glyph(115)]);
        assert_eq!(tokens("%%o"), [Token::Glyph(86), Token::Glyph(54)]);
        assert_eq!(tokens("~nB"), [Token::TildeAccent, Token::Glyph(53), Token::Glyph(11)]);
        assert_eq!(tokens("A~50~B"), [Token::Glyph(10), Token::Tab(50.0), Token::Glyph(11)]);
        assert_eq!(tokens("\\\\351B"), [Token::Glyph(24), Token::Glyph(11)]);
        assert_eq!(tokens("\\\\101"), [Token::Glyph(73), Token::Glyph(73), Token::Glyph(1), Token::Glyph(0), Token::Glyph(1)]);
    }

    /// The early return for bytes from 128 up gives what the general rules would.
    #[test]
    fn high_bytes_are_single_glyphs() {
        (FIRST_HIGH_BYTE..=u8::MAX).for_each(|byte| {
            let code = char_code(byte);
            let pair = [byte, byte];
            let mut doubled = Tokens { text: &pair, at: 0 };
            assert_eq!((doubled.doubled(code), doubled.at), (Some(Token::Glyph(code)), 0), "{byte:#x}");
            let pair = [byte, b'a'];
            let mut single = Tokens { text: &pair, at: 0 };
            assert_eq!((single.single(code), single.at), (Some(Token::Glyph(code)), 0), "{byte:#x}");
        });
        let tokens: Vec<Token> = Tokens { text: b"\xe9\xeca", at: 0 }.collect();
        assert_eq!(tokens, [Token::High { glyph: 0, byte: 0xE9 }, Token::High { glyph: 128, byte: 0xEC }, Token::Glyph(40)]);
    }

    #[test]
    fn font_numbers() {
        assert_eq!([*b"00", *b"28", *b"90", *b"93", *b"98", *b"99", *b"x1"].map(font_number), [0, 28, 24, 27, 29, 4, 29]);
    }
}
