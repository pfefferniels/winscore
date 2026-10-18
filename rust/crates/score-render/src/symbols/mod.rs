//! The symbol library and the drawing of library symbols.
//!
//! Code-9 symbol n is slot n % 10 of `LB{n / 10 * 10:04}.DRW` (`scorlib/symblist.txt`).
//! Clefs, accidentals, note heads, flags, rests, articulations and the brace
//! are all library symbols, drawn by draw_symbol (via draw_clef for most
//! item codes). The engine turns every record of a symbol
//! into one buffer point; the port draws smoothed outlines through the
//! records ([`smooth::Outline`]).

use std::collections::BTreeMap;
use std::sync::OnceLock;

use score_format::{DrwError, DrwLibrary, Symbol};

use crate::canvas::Pen;

pub mod clef;
pub mod library;
pub mod smooth;
pub mod text_symbol;

pub use clef::draw_clef;
pub use library::{draw_library_symbol, draw_missing_symbol, draw_scaled_symbol, ItemContext, SymbolCall};
pub use text_symbol::{draw_text_symbol, text_symbol_call, text_symbol_font_loaded, TextSymbolCall};

include!(concat!(env!("OUT_DIR"), "/bundled_symbols.rs"));

const SYMBOLS_PER_FILE: i32 = 10;

#[derive(Debug, Clone, PartialEq, Default)]
pub struct SymbolLibrary {
    /// Libraries by the number of their first symbol.
    files: BTreeMap<i32, DrwLibrary>,
}

impl SymbolLibrary {
    /// Libraries from `(first symbol number, file contents)` pairs.
    pub fn from_files<'b>(files: impl IntoIterator<Item = (i32, &'b [u8])>) -> Result<Self, DrwError> {
        let files = files
            .into_iter()
            .map(|(first, bytes)| Ok((first, DrwLibrary::parse(bytes)?)))
            .collect::<Result<_, DrwError>>()?;
        Ok(Self { files })
    }

    /// The libraries shipped with WinScore 5.01, embedded at build time
    /// (empty without the `bundled-symbols` feature).
    pub fn bundled() -> &'static SymbolLibrary {
        static BUNDLED_LIBRARY: OnceLock<SymbolLibrary> = OnceLock::new();
        BUNDLED_LIBRARY.get_or_init(|| {
            SymbolLibrary::from_files(BUNDLED.iter().copied()).expect("the bundled symbol libraries parse")
        })
    }

    /// Symbol `number`, if its file exists and its slot has points; the engine ignores names.
    pub fn symbol(&self, number: i32) -> Option<&Symbol> {
        let file = self.files.get(&(number - number.rem_euclid(SYMBOLS_PER_FILE)))?;
        let symbol = file.symbols.get(number.rem_euclid(SYMBOLS_PER_FILE) as usize)?;
        (!symbol.records.is_empty()).then_some(symbol)
    }
}

/// Engine units per library unit, per axis; negative values mirror.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Scale {
    pub x: f64,
    pub y: f64,
}

impl Scale {
    pub const fn uniform(factor: f64) -> Self {
        Self { x: factor, y: factor }
    }
}

/// The buffer pen for a library pen code: 1, 2, 3 start a polyline, a filled
/// object and a further path of it; 0 and the negative codes continue.
fn pen(code: i16) -> Pen {
    match code {
        1 => Pen::Stroke,
        2 => Pen::Fill,
        3 => Pen::SubPath,
        _ => Pen::Continue,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bundled_libraries_cover_the_symbol_list() {
        let library = SymbolLibrary::bundled();
        assert_eq!(library.symbol(5).map(|s| s.name.as_str()), Some("brace"));
        assert_eq!(library.symbol(11).map(|s| s.name.as_str()), Some("noir"));
        assert_eq!(library.symbol(21).map(|s| s.name.as_str()), Some("wedge"));
        assert!(library.symbol(-1).is_none());
    }
}
