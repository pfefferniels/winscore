//! Code 11: user symbols from SCORE 3/4 `.DRW` files (draw_symbol 0x4293F0
//! with IP1 = 11, file reader 0x432998).
//!
//! P5 symbol 0–9 of the file, P6/P7 size, P8 thickness, P9 rotation, P10
//! pixel thickness; the file name is stored as characters from P14 on (128
//! of them). The engine reads the file in the compact `KH` format, from the
//! current directory or `scorlib`; without a file system the files are
//! looked up by name among the compact libraries shipped with WinScore
//! (`KBRHY.DRW`, `FAULT.DRW`). Symbols are drawn at full library size, like
//! code 9's below 50, and P15 does not move them. Where the file or the
//! symbol is not there, the refined style shows a placeholder on the
//! screen ([`draw_missing_symbol`]).

use std::sync::OnceLock;

use score_format::DrwLibrary;

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::library::{library_unit, shows_missing};
use crate::symbols::{draw_missing_symbol, draw_scaled_symbol, ItemContext, SymbolCall};
use crate::units::trunc;

const NAME_FROM: usize = 14;
const NAME_LENGTH: usize = 128;
const SYMBOLS_PER_FILE: i32 = 10;
/// P13 = 99 suppresses the drawing (0x42A347).
const SUPPRESSED: i32 = 99;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let number = trunc(f64::from(item.p(5)));
    if trunc(f64::from(item.p(13))) == SUPPRESSED {
        return;
    }
    let call = SymbolCall {
        number,
        size_x: f64::from(item.p(6)),
        size_y: f64::from(item.p(7)),
        thickness: trunc(f64::from(item.p(8))),
        rotation: f64::from(item.p(9)),
    };
    let name = file_name(item);
    let symbol = name
        .as_deref()
        .and_then(user_library)
        .and_then(|library| library.symbols.get(usize::try_from(number).ok()?))
        .filter(|s| (0..SYMBOLS_PER_FILE).contains(&number) && !s.records.is_empty());
    let (at, step) = (doc.position(item), doc.staff_of(item).step);
    match symbol {
        Some(symbol) => draw_scaled_symbol(doc, canvas, symbol, at, step, &call, 1.0, ItemContext::of(item).pixels),
        None if shows_missing(doc) => {
            // The file name without its extension, and the symbol's number in it.
            let stem = name.as_deref().map_or("?", |n| n.split('.').next().unwrap_or(n));
            draw_missing_symbol(canvas, item.staff(), at, library_unit(step, &call, 1.0), &format!("{stem} {number}"));
        }
        None => {}
    }
}

/// The file name the item stores from P14 on, without path and trailing
/// blanks, upper case, with `.DRW` added when it has no extension.
fn file_name(item: ItemRef<'_>) -> Option<String> {
    let params = item.item.params();
    let bytes: Vec<u8> = params.get(NAME_FROM - 1..)?.iter().flat_map(|w| w.to_le_bytes()).take(NAME_LENGTH).collect();
    let text = String::from_utf8_lossy(&bytes);
    let name = text.split('\0').next()?.trim_end();
    let name = name.rsplit(['\\', '/']).next()?.trim().to_ascii_uppercase();
    match name.as_str() {
        "" => None,
        n if n.contains('.') => Some(name),
        _ => Some(format!("{name}.DRW")),
    }
}

/// The compact libraries shipped in `scorlib`, by file name.
fn user_library(name: &str) -> Option<&'static DrwLibrary> {
    static LIBRARIES: OnceLock<Vec<(&'static str, DrwLibrary)>> = OnceLock::new();
    let libraries = LIBRARIES.get_or_init(|| {
        SHIPPED
            .iter()
            .filter_map(|&(name, bytes)| Some((name, DrwLibrary::parse(bytes).ok()?)))
            .collect()
    });
    libraries.iter().find(|(n, _)| *n == name).map(|(_, library)| library)
}

macro_rules! scorlib {
    ($($file:literal),*) => {
        &[$(($file, include_bytes!(concat!(env!("CARGO_MANIFEST_DIR"), "/../../../WINSCORE 5.01/winscore/scorlib/", $file)))),*]
    };
}

const SHIPPED: &[(&str, &[u8])] = scorlib!("KBRHY.DRW", "FAULT.DRW");

#[cfg(test)]
mod tests {
    use crate::display::ItemId;
    use crate::document::{Document, Medium, Options};
    use score_format::{Item, MusFile, Word};

    /// A code-11 item for symbol `number` of file `name`, and what it draws:
    /// shapes and the strings of its texts.
    fn draw(number: f32, name: &str, options: Options) -> (usize, Vec<String>) {
        let mut params: Vec<Word> = [11.0, 1.0, 20.0, 4.0, number].into_iter().map(Word::from_f32).collect();
        params.resize(13, Word::from_f32(0.0));
        let mut bytes = name.as_bytes().to_vec();
        bytes.resize(bytes.len().div_ceil(4) * 4 + 4, 0);
        params.extend(bytes.chunks(4).map(|c| Word::from_bits(u32::from_le_bytes([c[0], c[1], c[2], c[3]]))));
        let staff = Item::new([8.0, 1.0, 0.0, 0.0, 1.0].into_iter().map(Word::from_f32).collect());
        let mut file = MusFile::empty();
        file.items = vec![staff, Item::new(params)];
        let list = crate::render(&Document::with_options(&file, options));
        let shapes = list.shapes.iter().filter(|s| s.source == Some(ItemId(1))).count();
        let texts = list.texts.iter().filter(|t| t.source == Some(ItemId(1)));
        (shapes, texts.flat_map(|t| t.strings.iter().map(|s| s.text.clone())).collect())
    }

    #[test]
    fn a_file_that_is_not_there_shows_a_placeholder_on_the_screen() {
        assert_eq!(draw(3.0, "MYSYMS.DRW", Options::REFINED), (1, vec!["MYSYMS 3".to_string()]));
        assert_eq!(draw(3.0, "MYSYMS.DRW", Options::ENGINE), (0, vec![]));
        assert_eq!(draw(3.0, "MYSYMS.DRW", Options { medium: Medium::Print, ..Options::REFINED }), (0, vec![]));
        let (shapes, texts) = draw(1.0, "KBRHY.DRW", Options::REFINED);
        assert!(shapes > 1 && texts.is_empty());
    }
}
