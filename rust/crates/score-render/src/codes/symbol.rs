//! Code 9: library symbols (draw_item 0x547210 calls draw_symbol 0x4293F0
//! with X_POS, Y_POS, IP5, P6, P7, IP8, P9, IP9).
//!
//! P5 symbol number (`scorlib/symblist.txt`; negative reads as 0), P6
//! size (0 = 1; the hundreds are part-extractor flags; negative mirrors),
//! P7 vertical size (0 = P6), P8 thickening `X0Y` (-1 outline), P9
//! clockwise rotation in degrees (when trunc(P9) != 0), P10 pixel
//! thickness, P15 horizontal offset (applied by item_position). Outline
//! symbols are drawn by the shared [`symbols::draw_library_symbol`], the
//! symbols the engine writes as text (8va, cresc., G.P., …) by
//! [`symbols::draw_text_symbol`], and the terms 3000-3099 from the term
//! library (`scorlib/CODE9.DAT`) through draw_text. A symbol or term that
//! is not there shows a placeholder on the screen
//! ([`symbols::draw_missing_symbol`]); the engine draws nothing.

use std::sync::OnceLock;

use crate::canvas::Canvas;
use crate::codes::text::font_before;
use crate::document::{Document, ItemRef};
use crate::symbols::library::{is_missing, is_text_symbol, library_unit, normal_size, shows_missing};
use crate::symbols::{self, ItemContext, SymbolCall, TextSymbolCall};
use crate::text::{self, draw_text, Font, TextCall};
use crate::units::{amod, constant, real, trunc};

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let ip = |n: usize| trunc(f64::from(item.p(n)));
    let number = ip(5).max(0);
    let call = SymbolCall {
        number,
        size_x: f64::from(item.p(6)),
        size_y: f64::from(item.p(7)),
        thickness: ip(8),
        rotation: f64::from(item.p(9)),
    };
    let step = doc.staff_of(item).step;
    if shows_missing(doc) && missing(doc, number) {
        let unit = library_unit(step, &call, normal_size(number));
        symbols::draw_missing_symbol(canvas, item.staff(), doc.position(item), unit, &number.to_string());
    } else if TERMS.contains(&number) {
        draw_term(doc, item, canvas, number);
    } else if is_text_symbol(number) {
        symbols::draw_text_symbol(doc, item, canvas, &TextSymbolCall::of(doc, item, number));
    } else {
        symbols::draw_library_symbol(doc, &ItemContext::of(item), canvas, doc.position(item), step, &call);
    }
}

/// Whether the item draws nothing for want of its symbol: a term past the
/// end of the term library, or a symbol no library has.
fn missing(doc: &Document<'_>, number: i32) -> bool {
    if TERMS.contains(&number) {
        TermLibrary::bundled().term(number).is_none()
    } else {
        is_missing(doc, number)
    }
}

/// Symbol numbers of the term library.
const TERMS: std::ops::RangeInclusive<i32> = 3000..=3099;

/// The term library draw_symbol reads once from its file (0x4295B7): the
/// text of each line after the four-digit number and a space, in line
/// order (comment lines start with `%` or a space); term 3000 + k is the
/// line k. The engine stops after 70 terms or 700 characters.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct TermLibrary {
    terms: Vec<Vec<u8>>,
}

const MAX_TERMS: usize = 70;
const MAX_CHARACTERS: usize = 700;
/// The text starts after `nnnn `.
const TEXT_COLUMN: usize = 5;
/// The engine reads lines of up to 160 characters.
const LINE_LENGTH: usize = 160;

impl TermLibrary {
    pub fn parse(bytes: &[u8]) -> Self {
        let lines = bytes
            .split(|&b| b == b'\n')
            .map(|line| trimmed(&line[..line.len().min(LINE_LENGTH)]))
            .filter(|line| !matches!(line.first(), None | Some(b'%' | b' ')));
        let mut used = 0;
        let terms = lines
            .map(|line| line.get(TEXT_COLUMN..).unwrap_or_default().to_vec())
            .take(MAX_TERMS)
            .take_while(|text| {
                used += text.len();
                used <= MAX_CHARACTERS
            })
            .collect();
        Self { terms }
    }

    /// WinScore's own `scorlib/CODE9.DAT`, embedded at build time.
    pub fn bundled() -> &'static TermLibrary {
        static BUNDLED: OnceLock<TermLibrary> = OnceLock::new();
        BUNDLED.get_or_init(|| TermLibrary::parse(BUNDLED_TERMS))
    }

    /// The text of term `number` (3000-3099), in SCORE's text coding.
    pub fn term(&self, number: i32) -> Option<&[u8]> {
        let index = usize::try_from(number - TERMS.start()).ok()?;
        self.terms.get(index).map(Vec::as_slice)
    }
}

#[cfg(feature = "bundled-symbols")]
const BUNDLED_TERMS: &[u8] = include_bytes!("../../../../../WINSCORE 5.01/winscore/scorlib/CODE9.DAT");
#[cfg(not(feature = "bundled-symbols"))]
const BUNDLED_TERMS: &[u8] = b"";

/// A line up to its last character above a space (0x54C8E5).
fn trimmed(line: &[u8]) -> &[u8] {
    let end = line.iter().rposition(|&b| b > b' ').map_or(0, |i| i + 1);
    &line[..end]
}

/// Terms are spread and sized 1.05 times the symbol size, like the text
/// symbols from 50 on (draw_symbol 0x42987C).
const TERM_SCALE: f32 = 1.05;

/// A term: the item's own P3, P8 (font override), P9, P10 (space, or P17
/// when set), P16 (spread when set) and P26 as the text's colour.
fn draw_term(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, number: i32) {
    if let Some(text) = TermLibrary::bundled().term(number) {
        draw_text(doc, item, canvas, &term_call(doc, item, text, font_before(doc, item)));
    }
}

/// The draw_text call for term `text` of `item`, given the font current before it.
fn term_call<'t>(doc: &Document<'_>, item: ItemRef<'_>, text: &'t [u8], current_font: Font) -> TextCall<'t> {
    let p = |n: usize| item.p(n);
    let size_x = match real(amod(f64::from(p(6)), 100.0)) {
        0.0 => 1.0,
        s => s,
    };
    let size_y = if p(7) == 0.0 { size_x } else { f64::from(p(7)) };
    let scaled = |s: f64| real(s * constant(TERM_SCALE)) as f32;
    let colour = match (p(26), p(14)) {
        (0.0, -1.0) => Some(p(16)),
        (0.0, _) => None,
        (p26, _) => Some(p26),
    };
    TextCall {
        text,
        origin: doc.position(item),
        p3: p(3),
        item_code: item.code(),
        step: None,
        staff: item.staff(),
        spread: if p(16) != 0.0 { p(16) } else { TERM_SCALE },
        width: scaled(size_x),
        height: scaled(size_y),
        font_override: trunc(f64::from(p(8))),
        rotation: p(9),
        space: if p(17) != 0.0 { p(17) } else { p(10) },
        shift: 0.0,
        colour,
        current_font,
    }
}

/// The font a code-9 item leaves loaded (draw_item 0x547358 makes it the
/// current font): that of the last text record a term or text symbol draws.
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    let number = trunc(f64::from(item.p(5))).max(0);
    if TERMS.contains(&number) {
        let text = TermLibrary::bundled().term(number)?;
        text::font_loaded(doc, &term_call(doc, item, text, Font::TIMES))
    } else if is_text_symbol(number) {
        symbols::text_symbol_font_loaded(doc, &TextSymbolCall::of(doc, item, number))
    } else {
        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn terms_follow_line_order() {
        let library = TermLibrary::parse(b"% comment\r\n3000 _00>>a2\r\n 3001 skipped\r\n3007 _00Trgl.  \r\n");
        assert_eq!(library.term(3000), Some(&b"_00>>a2"[..]));
        assert_eq!(library.term(3001), Some(&b"_00Trgl."[..]));
        assert_eq!(library.term(3002), None);
        assert_eq!(library.term(2999), None);
    }

    #[test]
    fn bundled_terms() {
        assert_eq!(TermLibrary::bundled().term(3004), Some(&b"_02l<<eger"[..]));
    }

    fn loaded(fixture: &[u8]) -> Option<Font> {
        let file = score_format::MusFile::parse(fixture).expect("fixture parses");
        let doc = Document::new(&file);
        let item = doc.items().find(|i| i.code() == crate::codes::SYMBOL).expect("a code-9 item");
        font_loaded(&doc, item)
    }

    #[test]
    fn fonts_loaded_by_terms_and_text_symbols() {
        assert_eq!(loaded(include_bytes!("../../../../fixtures/code09-p5-text-3004/input.mus")), Some(Font(2)));
        assert_eq!(loaded(include_bytes!("../../../../fixtures/code09-p5-text-66/input.mus")), Some(Font(0)));
        assert_eq!(loaded(include_bytes!("../../../../fixtures/code09-p5-symbol-31/input.mus")), None);
    }
}
