//! Code 11: user symbols from SCORE 3/4 `.DRW` files (draw_symbol 0x4293F0
//! with IP1 = 11, file reader 0x432998).
//!
//! P5 symbol 0–9 of the file, P6/P7 size, P8 thickness, P9 rotation, P10
//! pixel thickness; the file name is stored as characters from P14 on (128
//! of them). The engine reads the file in the compact `KH` format, from the
//! current directory or `scorlib`; without a file system the files are
//! looked up by name among the compact libraries shipped with WinScore
//! (`KBRHY.DRW`, `FAULT.DRW`). Symbols are drawn at full library size, like
//! code 9's below 50, and P15 does not move them.

use std::sync::OnceLock;

use score_format::DrwLibrary;

use crate::canvas::Canvas;
use crate::document::{Document, ItemRef};
use crate::symbols::{draw_scaled_symbol, ItemContext, SymbolCall};
use crate::units::trunc;

const NAME_FROM: usize = 14;
const NAME_LENGTH: usize = 128;
const SYMBOLS_PER_FILE: i32 = 10;
/// P13 = 99 suppresses the drawing (0x42A347).
const SUPPRESSED: i32 = 99;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let number = trunc(f64::from(item.p(5)));
    if !(0..SYMBOLS_PER_FILE).contains(&number) || trunc(f64::from(item.p(13))) == SUPPRESSED {
        return;
    }
    let Some(library) = file_name(item).and_then(|name| user_library(&name)) else {
        return;
    };
    let Some(symbol) = library.symbols.get(number as usize).filter(|s| !s.records.is_empty()) else {
        return;
    };
    let call = SymbolCall {
        number,
        size_x: f64::from(item.p(6)),
        size_y: f64::from(item.p(7)),
        thickness: trunc(f64::from(item.p(8))),
        rotation: f64::from(item.p(9)),
    };
    let context = ItemContext::of(item);
    draw_scaled_symbol(doc, canvas, symbol, doc.position(item), doc.staff_of(item).step, &call, 1.0, context.pixels);
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
