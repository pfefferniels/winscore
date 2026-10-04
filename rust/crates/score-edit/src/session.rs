//! What the editor remembers between commands besides the items: the
//! selection (WinScore's edit mode), the selected items as they were when
//! selected (for AB and C), the item last edited or entered, the move
//! increments and the deleted items UND can bring back.

use score_format::Item;

use crate::command::moves::Increments;
use crate::document::{Document, ItemId};
use crate::drag::Ends;
use crate::group::Pending;

/// The ids in their first-seen order, without repeats.
fn unique(ids: impl Iterator<Item = ItemId>) -> Vec<ItemId> {
    ids.fold(Vec::new(), |mut seen, id| {
        if !seen.contains(&id) {
            seen.push(id);
        }
        seen
    })
}

/// An item removed by DE, with where it was.
#[derive(Debug, Clone, PartialEq)]
pub struct Deleted {
    pub index: usize,
    pub id: ItemId,
    pub item: Item,
}

#[derive(Debug, Clone, PartialEq)]
pub struct Session {
    selection: Vec<ItemId>,
    originals: Vec<(ItemId, Item)>,
    current: Option<ItemId>,
    pub increments: Increments,
    deleted: Vec<Vec<Deleted>>,
    /// What a drag moves (LFT, RGT); back to the whole item when edit mode ends.
    drag_ends: Ends,
    /// Parameters remembered by PS, latest last.
    saved: Vec<(usize, f32)>,
    /// The font in effect at the end of the text entered last.
    pub text_font: u8,
    /// The position CT centred on last (CT alone reuses it).
    pub centre_at: Option<f32>,
    /// The position JR justified to last.
    pub right_at: Option<f32>,
    /// The positions J justified between last.
    pub justify_between: Option<(f32, f32)>,
    /// A group command waiting for its next line.
    pub pending: Option<Pending>,
    /// Items cut for pasting (IF … THEN CUT), pasted by PST.
    pub clipboard: Vec<Item>,
    /// The parameter the slider buttons (PCHNGn) change; QPn chooses it.
    pub slider_param: usize,
}

/// The slider changes P2 until QPn chooses another parameter.
const DEFAULT_SLIDER_PARAM: usize = 2;

impl Default for Session {
    fn default() -> Self {
        Self {
            selection: Vec::new(),
            originals: Vec::new(),
            current: None,
            increments: Increments::default(),
            deleted: Vec::new(),
            drag_ends: Ends::default(),
            saved: Vec::new(),
            text_font: 0,
            centre_at: None,
            right_at: None,
            justify_between: None,
            pending: None,
            clipboard: Vec::new(),
            slider_param: DEFAULT_SLIDER_PARAM,
        }
    }
}

impl Session {
    pub fn selection(&self) -> &[ItemId] {
        &self.selection
    }

    pub fn in_edit_mode(&self) -> bool {
        !self.selection.is_empty()
    }

    /// Selects `ids` (duplicates and unknown ids dropped) and remembers their
    /// present state; the last one becomes the current item.
    pub fn select(&mut self, doc: &Document, ids: &[ItemId]) {
        let chosen = unique(ids.iter().copied().filter(|&id| doc.contains(id)));
        self.originals = chosen.iter().filter_map(|&id| doc.item(id).map(|item| (id, item.clone()))).collect();
        if let Some(&last) = chosen.last() {
            self.current = Some(last);
        }
        self.selection = chosen;
        self.drag_ends = Ends::All;
    }

    pub fn clear(&mut self) {
        self.selection.clear();
        self.originals.clear();
        self.drag_ends = Ends::All;
    }

    pub fn drag_ends(&self) -> Ends {
        self.drag_ends
    }

    /// LFT, RGT: drag only that end; the same word again drags the whole item.
    pub fn toggle_drag_end(&mut self, end: Ends) {
        self.drag_ends = if self.drag_ends == end { Ends::All } else { end };
    }

    /// The selected item as it was when it was selected.
    pub fn original(&self, id: ItemId) -> Option<&Item> {
        self.originals.iter().find(|(i, _)| *i == id).map(|(_, item)| item)
    }

    /// The item last edited or entered, if it still exists.
    pub fn current(&self, doc: &Document) -> Option<ItemId> {
        self.current.filter(|&id| doc.contains(id))
    }

    pub fn set_current(&mut self, id: ItemId) {
        self.current = Some(id);
    }

    pub fn save_param(&mut self, n: usize, value: f32) {
        self.saved.retain(|&(m, _)| m != n);
        self.saved.push((n, value));
    }

    /// The parameter PS remembered last, or the one remembered for `n`.
    pub fn saved_param(&self, n: Option<usize>) -> Option<(usize, f32)> {
        self.saved.iter().rev().find(|&&(m, _)| n.is_none_or(|n| n == m)).copied()
    }

    pub fn remember_deleted(&mut self, batch: Vec<Deleted>) {
        if !batch.is_empty() {
            self.deleted.push(batch);
        }
    }

    /// The last deleted batch whose items are all gone from `doc` (an undo may have restored them).
    pub fn take_deleted(&mut self, doc: &Document) -> Option<Vec<Deleted>> {
        while let Some(batch) = self.deleted.pop() {
            if batch.iter().all(|d| !doc.contains(d.id)) {
                return Some(batch);
            }
        }
        None
    }
}
