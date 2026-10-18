//! Text items (code 16): their characters, character count (P12) and
//! measured length (P13), and SCORE's quick text entry `"text" p2 p3 …`
//! (WinScore help, code16.txt "Entering Text").

use score_format::{Item, MusFile};
use score_render::codes::text::{font_before, text_call};
use score_render::text::width;
use score_render::{Document as RenderDocument, ItemId as RenderId};

use crate::params::{Draft, TEXT_CODE};

const COUNT: usize = 12;
pub const LENGTH: usize = 13;
/// A font code: an underscore and two digits, `_00` Times-Roman … `_94` meter digits.
const FONT_CODE_LEN: usize = 3;
/// Divides quick text entry into separate items.
const DIVIDER: u8 = b'/';
/// Added to P3 in quick text entry, it centres the text on P3.
pub const CENTRED: f32 = 1000.0;
/// P3 units between items divided by `/` in quick text entry.
pub const DIVIDED_GAP: f32 = 2.0;
/// Characters CTX leaves out when centring (help: ? ! ¿ ¡ . , : ; ").
const PUNCTUATION: &[u8] = b"?!\xbf\xa1.,:;\"";
/// ¡ and ¿ as [`encode`] spells them; CTX leaves them out as well.
const SPELLED_PUNCTUATION: [&[u8]; 2] = [b"!3", b"!q"];
/// Unicode of Windows-1252 bytes 0x80–0x9F; the other bytes are Latin-1.
const HIGH: [char; 32] = [
    '€', '\u{81}', '‚', 'ƒ', '„', '…', '†', '‡', 'ˆ', '‰', 'Š', '‹', 'Œ', '\u{8d}', 'Ž', '\u{8f}', '\u{90}', '‘', '’',
    '“', '”', '•', '–', '—', '˜', '™', 'š', '›', 'œ', '\u{9d}', 'ž', 'Ÿ',
];

/// Characters SCORE spells with escapes (help, "Inputting Special Text
/// Characters"): an accent before the letter (`<<` acute, `>>` grave, `^^`
/// circumflex, `%%` dieresis, `##` cedilla, `~` tilde), and `?x`, `!x` for
/// the extended characters, as SCORE prints them (`?i` prints ¹).
#[rustfmt::skip]
const SPELLINGS: &[(char, &str)] = &[
    ('Á', "<<A"), ('á', "<<a"), ('É', "<<E"), ('é', "<<e"), ('Í', "<<I"), ('í', "<<i"),
    ('Ó', "<<O"), ('ó', "<<o"), ('Ú', "<<U"), ('ú', "<<u"), ('Ý', "<<Y"), ('ý', "<<y"),
    ('À', ">>A"), ('à', ">>a"), ('È', ">>E"), ('è', ">>e"), ('Ì', ">>I"), ('ì', ">>i"),
    ('Ò', ">>O"), ('ò', ">>o"), ('Ù', ">>U"), ('ù', ">>u"),
    ('Â', "^^A"), ('â', "^^a"), ('Ê', "^^E"), ('ê', "^^e"), ('Î', "^^I"), ('î', "^^i"),
    ('Ô', "^^O"), ('ô', "^^o"), ('Û', "^^U"), ('û', "^^u"),
    ('Ä', "%%A"), ('ä', "%%a"), ('Ë', "%%E"), ('ë', "%%e"), ('Ï', "%%I"), ('ï', "%%i"),
    ('Ö', "%%O"), ('ö', "%%o"), ('Ü', "%%U"), ('ü', "%%u"), ('Ÿ', "%%Y"), ('ÿ', "%%y"),
    ('Ç', "##C"), ('ç', "##c"),
    ('Ã', "~A"), ('ã', "~a"), ('Ñ', "~N"), ('ñ', "~n"), ('Õ', "~O"), ('õ', "~o"),
    ('−', "?-"), ('Æ', "?A"), ('Œ', "?E"), ('Ł', "?L"), ('Ø', "?O"), ('æ', "?a"), ('©', "?c"),
    ('œ', "?e"), ('ª', "?f"), ('¹', "?i"), ('ł', "?l"), ('º', "?m"), ('ø', "?o"), ('®', "?r"),
    ('ß', "?s"), ('™', "?t"),
    ('•', "!0"), ('„', "!1"), ('”', "!2"), ('¡', "!3"), ('¢', "!4"), ('£', "!5"), ('§', "!6"),
    ('¤', "!7"), ('“', "!9"), ('Å', "!A"), ('‡', "!D"), ('Š', "!S"), ('Ž', "!Z"), ('å', "!a"),
    ('†', "!d"), ('…', "!e"), ('ƒ', "!f"), ('«', "!g"), ('»', "!h"), ('ﬁ', "!i"), ('‹', "!j"),
    ('›', "!k"), ('ﬂ', "!l"), ('—', "!m"), ('–', "!n"), ('¶', "!p"), ('¿', "!q"), ('š', "!s"),
    ('¥', "!y"), ('ž', "!z"),
];

/// SCORE prints ` and ' as curly quotes.
const QUOTES: [(char, u8); 2] = [('‘', b'`'), ('’', b'\'')];

/// Characters as WinScore stores them: SCORE's spelling where it has one,
/// so that WinScore draws and measures the character, otherwise
/// Windows-1252, whose bytes from 128 up WinScore cannot draw (é is "0");
/// others become `?`.
pub fn encode(text: &str) -> Vec<u8> {
    text.chars()
        .flat_map(|c| {
            if let Some(&(_, spelling)) = SPELLINGS.iter().find(|&&(s, _)| s == c) {
                return spelling.as_bytes().to_vec();
            }
            let byte = match u32::from(c) {
                code @ (0..=0x7F | 0xA0..=0xFF) => code as u8,
                _ => QUOTES
                    .iter()
                    .find(|&&(q, _)| q == c)
                    .map(|&(_, b)| b)
                    .or_else(|| HIGH.iter().position(|&h| h == c).map(|i| 0x80 + i as u8))
                    .unwrap_or(b'?'),
            };
            vec![byte]
        })
        .collect()
}

/// The characters of a text item for editing: Windows-1252, with the
/// spellings [`encode`] writes read back as their characters.
pub fn decode(bytes: &[u8]) -> String {
    let mut text = String::new();
    let mut rest = bytes;
    while let Some(&byte) = rest.first() {
        match SPELLINGS.iter().find(|&&(_, s)| rest.starts_with(s.as_bytes())) {
            Some(&(c, spelling)) => {
                text.push(c);
                rest = &rest[spelling.len()..];
            }
            None => {
                text.push(match byte {
                    0x80..=0x9F => HIGH[usize::from(byte - 0x80)],
                    _ => char::from(byte),
                });
                rest = &rest[1..];
            }
        }
    }
    text
}

/// The font number of a font code at the start of `text`, such as `_15`.
pub fn font_code(text: &[u8]) -> Option<u8> {
    match text {
        [b'_', a, b, ..] if a.is_ascii_digit() && b.is_ascii_digit() => Some((a - b'0') * 10 + (b - b'0')),
        _ => None,
    }
}

/// `text` with the code of `font` in front if it has no font code.
pub fn with_font_code(text: &[u8], font: u8) -> Vec<u8> {
    if font_code(text).is_some() {
        text.to_vec()
    } else {
        let mut coded = format!("_{font:02}").into_bytes();
        coded.extend_from_slice(text);
        coded
    }
}

/// The font in effect at the end of `text`: its last font code, if any.
pub fn last_font_code(text: &[u8]) -> Option<u8> {
    text.windows(FONT_CODE_LEN).filter_map(font_code).next_back()
}

/// Quick text entry divided at `/` into items, each starting with the font in
/// effect, which begins as `font` (the font of the text entered last).
pub fn divided(text: &[u8], font: u8) -> Vec<Vec<u8>> {
    let mut current = font;
    text.split(|&b| b == DIVIDER)
        .map(|part| {
            let coded = with_font_code(part, current);
            current = last_font_code(&coded).unwrap_or(current);
            coded
        })
        .filter(|coded| coded.len() > FONT_CODE_LEN)
        .collect()
}

/// The text without the punctuation CTX ignores at either end, as
/// (characters before, the rest up to the end of the core), font code kept.
pub fn core(text: &[u8]) -> (Vec<u8>, Vec<u8>) {
    let code_len = if font_code(text).is_some() { FONT_CODE_LEN } else { 0 };
    let (code, body) = text.split_at(code_len);
    let mut start = 0;
    while let Some(len) = punctuation_at(&body[start..]) {
        start += len;
    }
    let mut end = body.len();
    while end > start {
        match SPELLED_PUNCTUATION.iter().find(|s| body[start..end].ends_with(s)) {
            Some(spelled) => end -= spelled.len(),
            None if PUNCTUATION.contains(&body[end - 1]) => end -= 1,
            None => break,
        }
    }
    ([code, &body[..start]].concat(), [code, &body[..end]].concat())
}

/// The length of the punctuation CTX leaves out at the start of `text`, if any.
fn punctuation_at(text: &[u8]) -> Option<usize> {
    match SPELLED_PUNCTUATION.iter().find(|s| text.starts_with(s)) {
        Some(spelled) => Some(spelled.len()),
        None => text.first().filter(|b| PUNCTUATION.contains(b)).map(|_| 1),
    }
}

/// A text item's draft with new characters and their count in P12.
pub fn set_characters(draft: &mut Draft, text: &[u8]) {
    draft.set_text(text);
    draft.set(COUNT, text.len() as f32);
}

/// P13 of the text item at `index` of `file`: the string's length in P3
/// units as the engine measures it after drawing, with the font
/// that is current when the item is drawn.
pub fn measured_length(file: &MusFile, index: usize) -> f32 {
    let doc = RenderDocument::new(file);
    let Some(item) = doc.item(RenderId(index as u32)) else { return 0.0 };
    width(&doc, &text_call(&doc, item, item.item.text(), font_before(&doc, item)))
}

/// P13 of every text item of `file`, by index, as the engine measures them
/// whenever it draws the page.
pub fn measured_lengths(file: &MusFile) -> Vec<(usize, f32)> {
    let doc = RenderDocument::new(file);
    doc.items()
        .filter(|item| item.code() == TEXT_CODE)
        .map(|item| {
            let length = width(&doc, &text_call(&doc, item, item.item.text(), font_before(&doc, item)));
            (item.id.0 as usize, length)
        })
        .collect()
}

/// What JR leaves out of the text item's length at its right end (the last
/// glyph's bearing), or `None` when the engine does not right-justify it.
pub fn right_bearing(file: &MusFile, index: usize) -> Option<f32> {
    let doc = RenderDocument::new(file);
    let item = doc.item(RenderId(index as u32))?;
    score_render::text::right_bearing(&doc, &text_call(&doc, item, item.item.text(), font_before(&doc, item)))
}

/// The length the text item at `index` would have with `text` as its characters.
pub fn length_with(file: &MusFile, index: usize, text: &[u8]) -> f32 {
    let Some(item) = file.items.get(index) else { return 0.0 };
    let mut draft = Draft::of(item);
    set_characters(&mut draft, text);
    let mut probe = file.clone();
    probe.items[index] = draft.to_item();
    measured_length(&probe, index)
}

/// `item` with P13 set to `length`.
pub fn with_length(item: &Item, length: f32) -> Item {
    let mut draft = Draft::of(item);
    draft.set(LENGTH, length);
    draft.to_item()
}

/// A text item on `staff` at P3 100 with spread and size 1, as quick entry makes them.
pub fn new_item(staff: f32, text: &[u8]) -> Draft {
    let mut draft = Draft::new(&[TEXT_CODE as f32, staff, 100.0, 0.0, 1.0, 1.0]);
    set_characters(&mut draft, text);
    draft
}

#[cfg(test)]
mod tests {
    use super::*;
    use score_format::{CountWidth, Word};

    fn file_with(items: Vec<Item>) -> MusFile {
        let trailer_words: [f32; 6] = [0.0, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = 6u16.to_le_bytes().to_vec();
        bytes.extend(trailer_words.iter().flat_map(|w| w.to_le_bytes()));
        let trailer = MusFile::parse(&bytes).unwrap().trailer;
        MusFile { width: CountWidth::Short, items, trailer }
    }

    fn staff() -> Item {
        Item::new([8.0, 1.0, 0.0].map(Word::from_f32).to_vec())
    }

    #[test]
    fn font_codes() {
        assert_eq!(font_code(b"_15A stitch"), Some(15));
        assert_eq!(font_code(b"A stitch"), None);
        assert_eq!(with_font_code(b"Hello", 2), b"_02Hello");
        assert_eq!(with_font_code(b"_04Hi", 2), b"_04Hi");
        assert_eq!(last_font_code(b"_00A _02in _16saves"), Some(16));
    }

    #[test]
    fn divided_parts_carry_the_font() {
        let parts = divided(b"_00a _02b/c//_04d/e", 0);
        assert_eq!(parts, [b"_00a _02b".to_vec(), b"_02c".to_vec(), b"_04d".to_vec(), b"_04e".to_vec()]);
        assert_eq!(divided(b"x", 16), [b"_16x".to_vec()]);
    }

    #[test]
    fn ctx_core_skips_punctuation_at_both_ends() {
        assert_eq!(core(b"_00Hello,"), (b"_00".to_vec(), b"_00Hello".to_vec()));
        assert_eq!(core(b"_00\"Hi!\""), (b"_00\"".to_vec(), b"_00\"Hi".to_vec()));
        assert_eq!(core(b"_00(Hello)"), (b"_00".to_vec(), b"_00(Hello)".to_vec()));
        assert_eq!(core(b"_00!qQue?"), (b"_00!q".to_vec(), b"_00!qQue".to_vec()));
        assert_eq!(core(b"!3Hola!"), (b"!3".to_vec(), b"!3Hola".to_vec()));
    }

    /// The sample scores, saved by WinScore, store exactly the lengths we measure.
    #[test]
    fn sample_scores_keep_their_lengths() {
        let root = std::path::PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../assets/samples");
        let differing: Vec<(&str, usize, f32, f32)> = ["carmen.mus", "mozart.mus", "sonlcs.mus", "000.mus"]
            .iter()
            .flat_map(|name| {
                let file = MusFile::parse(&std::fs::read(root.join(name)).unwrap()).unwrap();
                measured_lengths(&file)
                    .into_iter()
                    .filter(|&(i, l)| file.items[i].param(LENGTH) != l)
                    .map(|(i, l)| (*name, i, file.items[i].param(LENGTH), l))
                    .collect::<Vec<_>>()
            })
            .collect();
        assert!(differing.is_empty(), "{differing:?}");
    }

    #[test]
    fn windows_1252() {
        assert_eq!(encode("€ ‰ ×"), b"\x80 \x89 \xd7");
        assert_eq!(encode("✓"), b"?");
        assert_eq!(decode(b"\xa9 B. \x96 x"), "© B. – x");
    }

    #[test]
    fn spellings() {
        assert_eq!(encode("© B. – Café Söhne, l’été"), b"?c B. !n Caf<<e S%%ohne, l'<<et<<e");
        assert_eq!(encode("¿Año?"), b"!qA~no?");
        assert_eq!(decode(b"_00?c 1999 Caf<<e"), "_00© 1999 Café");
    }

    #[test]
    fn spellings_round_trip() {
        let all: String = SPELLINGS.iter().map(|&(c, _)| c).collect();
        assert_eq!(decode(&encode(&all)), all);
        let stored: &[&[u8]] = &[b"_00<<<e%%%u!!a??c~~n", b"<<b %%x ?x !o ~b", b"\x80\xd7"];
        stored.iter().for_each(|&bytes| assert_eq!(encode(&decode(bytes)), bytes, "{bytes:?}"));
        // Older files store é as a byte, which an edit spells.
        assert_eq!(encode(&decode(b"\xe9t\xe7")), b"<<et##c");
    }

    /// What the renderer draws for each spelling is its character, and what
    /// the engine measures is the letter's width.
    #[test]
    fn spellings_draw_their_characters() {
        let drawn = |text: &[u8]| {
            let file = file_with(vec![staff(), new_item(1.0, &with_font_code(text, 0)).to_item()]);
            let doc = RenderDocument::new(&file);
            let list = score_render::render(&doc);
            let strings = list.texts.iter().filter(|t| t.source == Some(RenderId(1))).flat_map(|t| &t.strings);
            strings.map(|s| s.text.as_str()).collect::<String>()
        };
        SPELLINGS.iter().for_each(|&(c, spelling)| assert_eq!(drawn(spelling.as_bytes()), c.to_string(), "{spelling}"));
        assert_eq!(drawn(&encode("‘quotes’")), "‘quotes’");
        let length = |text: &str| measured_length(&file_with(vec![staff(), new_item(1.0, &encode(text)).to_item()]), 1);
        assert_eq!(length("_00Café"), length("_00Cafe"));
    }

    /// Characters, parameter changes, and the engine's P13 for them.
    type LengthCase<'a> = (&'a [u8], &'a [(usize, f32)], f32);

    /// Engine values from quick text entry and edits.
    #[test]
    fn lengths_match_the_engine() {
        let cases: [LengthCase; 8] = [
            (b"_00Hello", &[], 11.434_941),
            (b"_15A stitch in time saves nine.", &[(6, 2.0)], 123.489_15),
            (b"_00Hello", &[(6, 2.0)], 22.869_883),
            (b"_00Hello", &[(5, 1.5)], 17.152_412),
            (b"_00Hello", &[(8, 1004.0)], 11.723_129),
            (b"_00Hello", &[(8, 1015.0)], 12.577_406),
            (b"_00Hello", &[(8, 1094.0)], 14.118_19),
            (b"_00A stitch _02in time _16saves _23nine.", &[(6, 2.0)], 123.190_66),
        ];
        let got: Vec<(f32, f32)> = cases
            .iter()
            .map(|(text, params, want)| {
                let mut draft = new_item(1.0, text);
                params.iter().for_each(|&(n, v)| draft.set(n, v));
                (measured_length(&file_with(vec![staff(), draft.to_item()]), 1), *want)
            })
            .collect();
        assert!(got.iter().all(|(g, w)| g == w), "{got:?}");
    }
}
