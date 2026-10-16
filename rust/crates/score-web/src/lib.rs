//! WebAssembly API of the SCORE editor.
//!
//! The browser shell opens `.mus` bytes as a [`Score`], asks it for the
//! rendered page as an [`EncodedList`] (layout documented in [`encode`]),
//! paints that, and sends clicks and edits back. All coordinates are page
//! coordinates in engine units: 1/4000 inch, origin at the paper's
//! bottom-left corner, y up.

pub mod codes;
pub mod document;
pub mod editing;
pub mod encode;
pub mod hit;
pub mod input;
pub mod live;
pub mod output;
pub mod param_names;
pub mod placing;
pub mod preview;
pub mod symbols;

use score_render::{DisplayList, ItemId};
use wasm_bindgen::prelude::*;

pub use codes::code_name;
pub use document::{decode_text, Document, TEXT_CODE};
pub use input::{InputCheck, InputLine};
pub use preview::{InputPreview, Preview};
pub use encode::{encode, Encoded};
pub use hit::At;

/// A display list in the flat encoding of [`encode`].
#[wasm_bindgen]
pub struct EncodedList(Encoded);

#[wasm_bindgen]
impl EncodedList {
    /// Shape records (`Uint32Array`).
    #[wasm_bindgen(getter)]
    pub fn shapes(&self) -> Vec<u32> {
        self.0.shapes.clone()
    }

    /// Point coordinates `x, y, …` (`Int32Array`).
    #[wasm_bindgen(getter)]
    pub fn coords(&self) -> Vec<i32> {
        self.0.coords.clone()
    }

    /// Text runs as an `engine.json` document without shapes.
    #[wasm_bindgen(getter)]
    pub fn texts(&self) -> String {
        self.0.texts.clone()
    }
}

impl From<&DisplayList> for EncodedList {
    fn from(list: &DisplayList) -> Self {
        EncodedList(encode(list))
    }
}

/// Code, parameters and text of one item.
#[wasm_bindgen]
pub struct ItemInfo {
    code: i32,
    params: Vec<f32>,
    text: Option<String>,
}

#[wasm_bindgen]
impl ItemInfo {
    /// P1.
    #[wasm_bindgen(getter)]
    pub fn code(&self) -> i32 {
        self.code
    }

    /// What kind of item the code stands for, e.g. "Note".
    #[wasm_bindgen(getter)]
    pub fn name(&self) -> Option<String> {
        code_name(self.code).map(str::to_owned)
    }

    /// The stored parameters P1…Pn (`Float32Array`).
    #[wasm_bindgen(getter)]
    pub fn params(&self) -> Vec<f32> {
        self.params.clone()
    }

    /// The characters of a text item (code 16).
    #[wasm_bindgen(getter)]
    pub fn text(&self) -> Option<String> {
        self.text.clone()
    }
}

#[wasm_bindgen]
pub struct Score(pub(crate) Document);

#[wasm_bindgen]
impl Score {
    /// Opens the bytes of a `.mus` file.
    #[wasm_bindgen(constructor)]
    pub fn new(bytes: &[u8]) -> Result<Score, JsError> {
        Ok(Score(Document::open(bytes)?))
    }

    #[wasm_bindgen(js_name = itemCount)]
    pub fn item_count(&self) -> usize {
        self.0.items().len()
    }

    #[wasm_bindgen(js_name = paperWidth)]
    pub fn paper_width(&self) -> f64 {
        self.0.paper().width
    }

    #[wasm_bindgen(js_name = paperHeight)]
    pub fn paper_height(&self) -> f64 {
        self.0.paper().height
    }

    /// Renders the page and returns its display list.
    pub fn render(&mut self) -> EncodedList {
        EncodedList::from(self.0.render())
    }

    /// The page with only the selected items drawn again: the preview while
    /// they are dragged. [`Score::render`] after the drag gives the exact page.
    #[wasm_bindgen(js_name = renderSelection)]
    pub fn render_selection(&mut self) -> EncodedList {
        EncodedList::from(self.0.render_selection())
    }

    /// Code, P2 and P3 of every item, three numbers per item in file order
    /// (`Float32Array`), for the item list.
    #[wasm_bindgen(js_name = itemSummaries)]
    pub fn item_summaries(&self) -> Vec<f32> {
        self.0.items().iter().flat_map(|item| [item.code() as f32, item.param(2), item.param(3)]).collect()
    }

    pub fn item(&self, index: u32) -> Option<ItemInfo> {
        self.0.item(ItemId(index)).map(|item| ItemInfo {
            code: item.code(),
            params: item.params().iter().map(|w| w.as_f32()).collect(),
            text: (item.code() == TEXT_CODE).then(|| decode_text(item.text())),
        })
    }

    /// The `.mus` file bytes.
    pub fn save(&self) -> Vec<u8> {
        self.0.save()
    }
}

/// What kind of item code `code` (P1) stands for, e.g. "Note".
#[wasm_bindgen(js_name = codeName)]
pub fn code_name_js(code: i32) -> Option<String> {
    code_name(code).map(str::to_owned)
}

/// What parameter `n` of items with code `code` means, in the words of the
/// WinScore help.
#[wasm_bindgen(js_name = paramName)]
pub fn param_name(code: i32, n: usize) -> Option<String> {
    param_names::param_name(code, n).map(str::to_owned)
}

/// An engine reference display list, read from `engine.json`
/// (`rust/fixtures/README.md`).
#[wasm_bindgen]
pub struct Reference(DisplayList);

#[wasm_bindgen]
impl Reference {
    #[wasm_bindgen(constructor)]
    pub fn new(json: &str) -> Result<Reference, JsError> {
        Ok(Reference(score_testkit::display_from_json(json)?))
    }

    pub fn list(&self) -> EncodedList {
        EncodedList::from(&self.0)
    }

    /// The item whose elements the fixture attributes lie nearest to page
    /// point (`x`, `y`), within `tolerance` engine units.
    #[wasm_bindgen(js_name = hitTest)]
    pub fn hit_test(&self, x: f64, y: f64, tolerance: f64) -> Option<u32> {
        hit::hit_test(&self.0, At::new(x, y), tolerance).map(|id| id.0)
    }
}
