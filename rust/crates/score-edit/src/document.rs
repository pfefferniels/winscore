//! The edited score: the `.mus` file with a stable id for every item, and
//! the three invertible edits that change it.

use score_format::{Item, MusFile};

/// Identifies an item for the lifetime of a [`Document`], whatever happens
/// to the items before it. Ids are never reused.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub struct ItemId(pub u64);

/// One change to the item list. Every edit carries what is needed to undo it.
#[derive(Debug, Clone, PartialEq)]
pub enum Edit {
    Insert { index: usize, id: ItemId, item: Item },
    Remove { index: usize, id: ItemId, item: Item },
    Replace { index: usize, id: ItemId, before: Item, after: Item },
}

impl Edit {
    pub fn id(&self) -> ItemId {
        match self {
            Edit::Insert { id, .. } | Edit::Remove { id, .. } | Edit::Replace { id, .. } => *id,
        }
    }

    pub fn inverse(&self) -> Edit {
        match self.clone() {
            Edit::Insert { index, id, item } => Edit::Remove { index, id, item },
            Edit::Remove { index, id, item } => Edit::Insert { index, id, item },
            Edit::Replace { index, id, before, after } => Edit::Replace { index, id, before: after, after: before },
        }
    }
}

#[derive(Debug, Clone, PartialEq)]
pub struct Document {
    file: MusFile,
    ids: Vec<ItemId>,
    next_id: u64,
}

impl Document {
    pub fn new(file: MusFile) -> Self {
        let ids = (0..file.items.len() as u64).map(ItemId).collect();
        let next_id = file.items.len() as u64;
        Self { file, ids, next_id }
    }

    /// The items in file order, ready for rendering or saving.
    pub fn file(&self) -> &MusFile {
        &self.file
    }

    pub fn len(&self) -> usize {
        self.ids.len()
    }

    pub fn is_empty(&self) -> bool {
        self.ids.is_empty()
    }

    pub fn ids(&self) -> &[ItemId] {
        &self.ids
    }

    pub fn id_at(&self, index: usize) -> Option<ItemId> {
        self.ids.get(index).copied()
    }

    pub fn index_of(&self, id: ItemId) -> Option<usize> {
        self.ids.iter().position(|&i| i == id)
    }

    pub fn item(&self, id: ItemId) -> Option<&Item> {
        self.index_of(id).map(|i| &self.file.items[i])
    }

    pub fn contains(&self, id: ItemId) -> bool {
        self.index_of(id).is_some()
    }

    /// Items with their ids, in file order.
    pub fn entries(&self) -> impl Iterator<Item = (ItemId, &Item)> + '_ {
        self.ids.iter().copied().zip(&self.file.items)
    }

    pub(crate) fn fresh_id(&mut self) -> ItemId {
        let id = ItemId(self.next_id);
        self.next_id += 1;
        id
    }

    /// Applies an edit produced for this document (by a transaction or as an inverse).
    pub(crate) fn apply(&mut self, edit: &Edit) {
        match edit {
            Edit::Insert { index, id, item } => {
                self.ids.insert(*index, *id);
                self.file.items.insert(*index, item.clone());
            }
            Edit::Remove { index, id, .. } => {
                debug_assert_eq!(self.ids[*index], *id);
                self.ids.remove(*index);
                self.file.items.remove(*index);
            }
            Edit::Replace { index, id, after, .. } => {
                debug_assert_eq!(self.ids[*index], *id);
                self.file.items[*index] = after.clone();
            }
        }
    }

    pub(crate) fn apply_all(&mut self, edits: &[Edit]) {
        edits.iter().for_each(|e| self.apply(e));
    }

    pub(crate) fn revert_all(&mut self, edits: &[Edit]) {
        edits.iter().rev().for_each(|e| self.apply(&e.inverse()));
    }
}

/// Edits applied to a document as they are made, so later steps see earlier
/// ones; dropped without [`Transaction::commit`], they are reverted.
pub(crate) struct Transaction<'a> {
    doc: &'a mut Document,
    edits: Vec<Edit>,
}

impl<'a> Transaction<'a> {
    pub fn new(doc: &'a mut Document) -> Self {
        Self { doc, edits: Vec::new() }
    }

    pub fn doc(&self) -> &Document {
        self.doc
    }

    fn push(&mut self, edit: Edit) {
        self.doc.apply(&edit);
        self.edits.push(edit);
    }

    pub fn insert(&mut self, index: usize, item: Item) -> ItemId {
        let id = self.doc.fresh_id();
        self.push(Edit::Insert { index, id, item });
        id
    }

    /// Re-inserts an item under its old id (undelete).
    pub fn restore(&mut self, index: usize, id: ItemId, item: Item) {
        self.push(Edit::Insert { index: index.min(self.doc.len()), id, item });
    }

    pub fn append(&mut self, item: Item) -> ItemId {
        self.insert(self.doc.len(), item)
    }

    /// Removes an item; returns where it was and what it held.
    pub fn remove(&mut self, id: ItemId) -> Option<(usize, Item)> {
        let index = self.doc.index_of(id)?;
        let item = self.doc.file.items[index].clone();
        self.push(Edit::Remove { index, id, item: item.clone() });
        Some((index, item))
    }

    /// Replaces an item's content; no edit is recorded if nothing changes.
    pub fn replace(&mut self, id: ItemId, after: Item) -> bool {
        let Some(index) = self.doc.index_of(id) else { return false };
        let before = self.doc.file.items[index].clone();
        if before == after {
            return true;
        }
        self.push(Edit::Replace { index, id, before, after });
        true
    }

    pub fn commit(mut self) -> Vec<Edit> {
        std::mem::take(&mut self.edits)
    }
}

impl Drop for Transaction<'_> {
    fn drop(&mut self) {
        self.doc.revert_all(&self.edits);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use score_format::{CountWidth, Word};

    fn item(params: &[f32]) -> Item {
        Item::new(params.iter().copied().map(Word::from_f32).collect())
    }

    fn doc() -> Document {
        let bytes = score_format::MusFile {
            width: CountWidth::Short,
            items: vec![item(&[8.0, 1.0, 0.0]), item(&[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.0])],
            trailer: score_format::MusFile::parse(&empty_file()).unwrap().trailer,
        };
        Document::new(bytes)
    }

    fn empty_file() -> Vec<u8> {
        let words: [f32; 6] = [0.0, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = 6u16.to_le_bytes().to_vec();
        bytes.extend(words.iter().flat_map(|w| w.to_le_bytes()));
        bytes
    }

    #[test]
    fn ids_follow_items_across_inserts_and_removals() {
        let mut d = doc();
        let note = d.id_at(1).unwrap();
        let mut t = Transaction::new(&mut d);
        let new = t.insert(0, item(&[3.0, 1.0, 2.0]));
        let edits = t.commit();
        assert_eq!(edits.len(), 1);
        assert_eq!(d.index_of(note), Some(2));
        assert_eq!(d.index_of(new), Some(0));
        assert_ne!(new, note);
    }

    #[test]
    fn uncommitted_transactions_roll_back() {
        let mut d = doc();
        let before = d.clone();
        {
            let mut t = Transaction::new(&mut d);
            let staff = t.doc().id_at(0).unwrap();
            t.remove(staff);
            t.append(item(&[2.0, 1.0, 50.0]));
        }
        assert_eq!(d.file(), before.file());
        assert_eq!(d.ids(), before.ids());
    }

    #[test]
    fn reverting_edits_restores_the_document() {
        let mut d = doc();
        let before = d.clone();
        let mut t = Transaction::new(&mut d);
        let note = t.doc().id_at(1).unwrap();
        t.replace(note, item(&[1.0, 1.0, 101.0]));
        t.remove(note);
        let edits = t.commit();
        d.revert_all(&edits);
        assert_eq!(d.file(), before.file());
        assert_eq!(d.ids(), before.ids());
    }

    #[test]
    fn identical_replacement_records_nothing() {
        let mut d = doc();
        let mut t = Transaction::new(&mut d);
        let staff = t.doc().id_at(0).unwrap();
        let same = t.doc().item(staff).unwrap().clone();
        assert!(t.replace(staff, same));
        assert!(t.commit().is_empty());
    }
}
