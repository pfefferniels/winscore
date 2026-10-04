//! An open score: the editor that owns it (`score-edit`) and its last
//! rendering. The browser names items by their index in file order, which
//! is also what the display list's sources hold; the editor's stable ids
//! stay on this side.

use score_edit::{Change, EditError, Editor};
use score_format::{Item, MusError, MusFile};
use score_render::page::Paper;
use score_render::{render, DisplayList, ItemId};

use crate::hit::{hit_test, At};

/// P1 of text items, whose characters follow the parameters.
pub const TEXT_CODE: i32 = 16;

fn render_page(file: &MusFile) -> DisplayList {
    render(&score_render::Document::new(file))
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
    editor: Editor,
    page: DisplayList,
}

impl Document {
    pub fn open(bytes: &[u8]) -> Result<Self, MusError> {
        let editor = Editor::open(bytes)?;
        let page = render_page(editor.file());
        Ok(Self { editor, page })
    }

    pub fn file(&self) -> &MusFile {
        self.editor.file()
    }

    pub fn items(&self) -> &[Item] {
        &self.file().items
    }

    pub fn item(&self, index: ItemId) -> Option<&Item> {
        self.items().get(index.0 as usize)
    }

    pub fn paper(&self) -> Paper {
        score_render::Document::new(self.file()).page.paper
    }

    /// The last rendering.
    pub fn page(&self) -> &DisplayList {
        &self.page
    }

    pub fn render(&mut self) -> &DisplayList {
        self.page = render_page(self.editor.file());
        &self.page
    }

    pub fn hit(&self, at: At, tolerance: f64) -> Option<ItemId> {
        hit_test(&self.page, at, tolerance)
    }

    pub fn save(&self) -> Vec<u8> {
        self.editor.save()
    }

    pub fn editor(&self) -> &Editor {
        &self.editor
    }

    pub fn editor_mut(&mut self) -> &mut Editor {
        &mut self.editor
    }

    /// The editor's id of the item at file position `index`.
    pub fn id(&self, index: ItemId) -> Result<score_edit::ItemId, EditError> {
        self.editor.id_at(index.0 as usize).ok_or(EditError::NoSuchItem(index.0 as f32))
    }

    pub fn select(&mut self, indices: &[ItemId]) {
        let ids: Vec<score_edit::ItemId> = indices.iter().filter_map(|&i| self.editor.id_at(i.0 as usize)).collect();
        self.editor.select(&ids);
    }

    /// The selection as file positions, in selection order.
    pub fn selection(&self) -> Vec<ItemId> {
        self.editor
            .selection()
            .iter()
            .filter_map(|&id| self.editor.index_of(id))
            .map(|i| ItemId(i as u32))
            .collect()
    }

    /// What a finished action is called in the undo history, or `None` if it
    /// changed nothing.
    pub fn label(&self, change: &Change) -> Option<String> {
        (!change.is_empty()).then(|| self.editor.undo_label().unwrap_or_default().to_owned())
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
    fn clicks_find_rendered_staves() {
        let doc = Document::open(&sample("carmen.mus")).unwrap();
        let staff = doc.page().shapes.iter().find(|s| s.source.is_some()).expect("carmen renders staves");
        let index = doc.hit(At::from(staff.paths[0][0]), 2.0).unwrap();
        assert_eq!(doc.item(index).unwrap().code(), 8);
    }

    #[test]
    fn selection_round_trips_through_file_positions() {
        let mut doc = Document::open(&sample("mozart.mus")).unwrap();
        doc.select(&[ItemId(7), ItemId(2)]);
        assert_eq!(doc.selection(), vec![ItemId(7), ItemId(2)]);
        let change = doc.editor_mut().move_selection(1.0, 0.0).unwrap();
        assert_eq!(doc.label(&change).as_deref(), Some("Move"));
        assert_eq!(doc.item(ItemId(2)).unwrap().param(3), 1.0);
        doc.editor_mut().undo().unwrap();
        assert_eq!(doc.item(ItemId(2)).unwrap().param(3), 0.0);
    }

    #[test]
    fn decodes_windows_1252() {
        assert_eq!(decode_text(b"\xa9 B. \x96 x"), "© B. – x");
    }
}
