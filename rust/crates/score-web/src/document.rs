//! An open score: the `.mus` file, its last rendering, and parameter edits.

use score_format::{Item, MusError, MusFile, Word};
use score_render::{DisplayList, ItemId};

use crate::hit::{hit_test, At};

/// P1 of text items, whose characters follow the parameters.
pub const TEXT_CODE: i32 = 16;

/// Paper size in engine units.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Paper {
    pub width: f64,
    pub height: f64,
}

impl Paper {
    /// `PAPER 2` in the bundled `PREF.DAT`, WinScore's default.
    pub const LEGAL: Paper = Paper { width: 34000.0, height: 56000.0 };
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum EditError {
    NoSuchItem(ItemId),
    /// Parameters are numbered from 1.
    NoSuchParam(usize),
}

impl std::fmt::Display for EditError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            EditError::NoSuchItem(id) => write!(f, "no item {}", id.0),
            EditError::NoSuchParam(n) => write!(f, "no parameter P{n}"),
        }
    }
}

impl std::error::Error for EditError {}

/// The renderer the editor shows. `score_render` has no entry point yet, so
/// the page stays empty until it lands.
fn render_page(_file: &MusFile) -> DisplayList {
    DisplayList::default()
}

/// Blank padding to whole words, as text items store their characters.
fn padded(text: &[u8]) -> Vec<u8> {
    let mut bytes = text.to_vec();
    bytes.resize(text.len().div_ceil(4) * 4, b' ');
    bytes
}

/// `item` with parameter `n` (1-based) set to `value`; missing parameters
/// below `n` become zero.
fn with_param(item: &Item, n: usize, value: f32) -> Item {
    let mut params = item.params().to_vec();
    if params.len() < n {
        params.resize(n, Word::from_f32(0.0));
    }
    params[n - 1] = Word::from_f32(value);
    let still_text = params[0].as_f32() as i32 == TEXT_CODE;
    if still_text {
        Item::with_text(params, padded(item.text()))
    } else {
        Item::new(params)
    }
}

/// Characters of a text item as WinScore shows them (Windows-1252).
pub fn decode_text(bytes: &[u8]) -> String {
    const HIGH: [char; 32] = [
        '€', '\u{81}', '‚', 'ƒ', '„', '…', '†', '‡', 'ˆ', '‰', 'Š', '‹', 'Œ', '\u{8d}', 'Ž', '\u{8f}', '\u{90}', '‘',
        '’', '“', '”', '•', '–', '—', '˜', '™', 'š', '›', 'œ', '\u{9d}', 'ž', 'Ÿ',
    ];
    bytes
        .iter()
        .map(|&b| match b {
            0x80..=0x9F => HIGH[usize::from(b - 0x80)],
            _ => char::from(b),
        })
        .collect()
}

#[derive(Debug, Clone)]
pub struct Document {
    file: MusFile,
    page: DisplayList,
}

impl Document {
    pub fn open(bytes: &[u8]) -> Result<Self, MusError> {
        let file = MusFile::parse(bytes)?;
        let page = render_page(&file);
        Ok(Self { file, page })
    }

    pub fn items(&self) -> &[Item] {
        &self.file.items
    }

    pub fn item(&self, id: ItemId) -> Option<&Item> {
        self.file.items.get(id.0 as usize)
    }

    pub fn paper(&self) -> Paper {
        Paper::LEGAL
    }

    /// The last rendering.
    pub fn page(&self) -> &DisplayList {
        &self.page
    }

    pub fn render(&mut self) -> &DisplayList {
        self.page = render_page(&self.file);
        &self.page
    }

    /// Sets parameter `n` (1-based) of an item. The page is re-rendered on
    /// the next call to [`Document::render`].
    pub fn set_param(&mut self, id: ItemId, n: usize, value: f32) -> Result<(), EditError> {
        if n == 0 {
            return Err(EditError::NoSuchParam(n));
        }
        let item = self.file.items.get_mut(id.0 as usize).ok_or(EditError::NoSuchItem(id))?;
        *item = with_param(item, n, value);
        Ok(())
    }

    pub fn hit(&self, at: At, tolerance: f64) -> Option<ItemId> {
        hit_test(&self.page, at, tolerance)
    }

    pub fn save(&self) -> Vec<u8> {
        self.file.to_bytes()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::PathBuf;

    fn sample(name: &str) -> Vec<u8> {
        let root = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../..");
        std::fs::read(root.join("WINSCORE 5.01/winscore").join(name)).unwrap()
    }

    #[test]
    fn unchanged_document_saves_identically() {
        let bytes = sample("carmen.mus");
        assert_eq!(Document::open(&bytes).unwrap().save(), bytes);
    }

    #[test]
    fn set_param_changes_one_word() {
        let mut doc = Document::open(&sample("mozart.mus")).unwrap();
        let id = ItemId(3);
        let before = doc.item(id).unwrap().clone();
        doc.set_param(id, 3, 42.5).unwrap();
        let after = doc.item(id).unwrap();
        assert_eq!(after.param(3), 42.5);
        assert_eq!(after.params().len(), before.params().len());
        assert_eq!(after.code(), before.code());
        let reopened = Document::open(&doc.save()).unwrap();
        assert_eq!(reopened.item(id).unwrap().param(3), 42.5);
    }

    #[test]
    fn set_param_extends_short_items() {
        let mut doc = Document::open(&sample("mozart.mus")).unwrap();
        let id = ItemId(0);
        let len = doc.item(id).unwrap().params().len();
        doc.set_param(id, len + 3, 7.0).unwrap();
        let item = doc.item(id).unwrap();
        assert_eq!(item.params().len(), len + 3);
        assert_eq!(item.param(len + 1), 0.0);
        assert_eq!(item.param(len + 3), 7.0);
    }

    #[test]
    fn text_items_keep_their_text() {
        let mut doc = Document::open(&sample("carmen.mus")).unwrap();
        let (index, text) = doc
            .items()
            .iter()
            .enumerate()
            .find(|(_, item)| item.code() == TEXT_CODE && !item.text().is_empty())
            .map(|(i, item)| (i, item.text().to_vec()))
            .unwrap();
        let id = ItemId(index as u32);
        doc.set_param(id, 4, 3.0).unwrap();
        assert_eq!(doc.item(id).unwrap().text(), text.as_slice());
        let reopened = Document::open(&doc.save()).unwrap();
        assert_eq!(reopened.item(id).unwrap().text(), text.as_slice());
    }

    #[test]
    fn rejects_bad_targets() {
        let mut doc = Document::open(&sample("mozart.mus")).unwrap();
        assert_eq!(doc.set_param(ItemId(0), 0, 1.0), Err(EditError::NoSuchParam(0)));
        let missing = ItemId(doc.items().len() as u32);
        assert_eq!(doc.set_param(missing, 1, 1.0), Err(EditError::NoSuchItem(missing)));
    }

    #[test]
    fn decodes_windows_1252() {
        assert_eq!(decode_text(b"\xa9 B. \x96 x"), "© B. – x");
    }
}
