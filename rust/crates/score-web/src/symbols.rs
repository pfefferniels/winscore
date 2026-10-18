//! The library symbols for the symbol picker, each drawn by the renderer.

use score_edit::symbols::library_symbols;
use score_format::{Item, MusFile, Word};
use score_render::render;
use wasm_bindgen::prelude::*;

use crate::EncodedList;

const SYMBOL_CODE: f32 = 9.0;

/// A score with no items: word count, the trailer's three undefined words
/// and its length, and the end marker.
fn empty_file() -> MusFile {
    let words = [0.0f32, 0.0, 0.0, 4.0, -9999.0];
    let bytes: Vec<u8> = (words.len() as u16).to_le_bytes().into_iter().chain(words.iter().flat_map(|w| w.to_le_bytes())).collect();
    MusFile::parse(&bytes).expect("the empty score is well formed")
}

/// A code-9 item showing symbol `number` on staff 1, alone on the page.
fn preview_file(number: i32) -> MusFile {
    let mut file = empty_file();
    let params = [SYMBOL_CODE, 1.0, 100.0, 0.0, number as f32];
    file.items = vec![Item::new(params.map(Word::from).to_vec())];
    file
}

/// Every symbol of the bundled libraries as JSON `[[number, "name"], …]`.
#[wasm_bindgen(js_name = librarySymbols)]
pub fn library_symbols_json() -> String {
    let rows: Vec<(i32, String)> = library_symbols().into_iter().map(|symbol| (symbol.number, symbol.name)).collect();
    serde_json::to_string(&rows).expect("numbers and strings serialise")
}

/// The display list of library symbol `number` as a code-9 item draws it.
#[wasm_bindgen(js_name = symbolPreview)]
pub fn symbol_preview(number: i32) -> EncodedList {
    let file = preview_file(number);
    EncodedList::from(&render(&crate::drawn(&file)))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn previews_draw_something() {
        let first = library_symbols().into_iter().next().expect("the bundled library has symbols");
        let list = render(&crate::drawn(&preview_file(first.number)));
        assert!(!list.shapes.is_empty() || !list.texts.is_empty());
    }

    #[test]
    fn the_catalogue_is_json() {
        let rows: Vec<(i32, String)> = serde_json::from_str(&library_symbols_json()).unwrap();
        assert_eq!(rows.len(), library_symbols().len());
    }
}
