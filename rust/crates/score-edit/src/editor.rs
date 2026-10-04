//! The editing API for the browser shell: an open score, its selection,
//! commands, drags and undo.

use score_format::{Item, MusError, MusFile};
use score_render::page::P3_UNIT;
use score_render::Document as RenderDocument;

use crate::command::moves::{shift, Axis};
use crate::command::Run;
use crate::document::{Document, Edit, ItemId, Transaction};
use crate::error::EditError;
use crate::history::{History, Step};
use crate::params::{Draft, MAX_PARAM};
use crate::session::Session;

/// Drag offsets are kept to this fraction of a P3 unit or scale step.
const DRAG_GRID: f32 = 0.01;

/// What an action did to the items, by id, and the selection after it.
#[derive(Debug, Clone, PartialEq, Default)]
pub struct Change {
    pub inserted: Vec<ItemId>,
    pub removed: Vec<ItemId>,
    pub modified: Vec<ItemId>,
    pub selection: Vec<ItemId>,
}

impl Change {
    /// Classifies every touched id by whether it existed before the edits and after them.
    fn new(edits: &[Edit], selection: &[ItemId]) -> Self {
        let mut ids: Vec<ItemId> = edits.iter().map(Edit::id).collect();
        ids.sort_unstable();
        ids.dedup();
        let mut change = Change { selection: selection.to_vec(), ..Change::default() };
        ids.into_iter().for_each(|id| {
            let touching = || edits.iter().filter(move |e| e.id() == id);
            let existed = !matches!(touching().next(), Some(Edit::Insert { .. }));
            let exists = !matches!(touching().next_back(), Some(Edit::Remove { .. }));
            match (existed, exists) {
                (false, true) => change.inserted.push(id),
                (true, false) => change.removed.push(id),
                (true, true) => change.modified.push(id),
                (false, false) => {}
            }
        });
        change
    }

    pub fn is_empty(&self) -> bool {
        self.inserted.is_empty() && self.removed.is_empty() && self.modified.is_empty()
    }
}

/// A drag in progress: the dragged items as they were when it began, and
/// the size of a scale step on each one's staff.
#[derive(Debug, Clone, PartialEq)]
struct Drag {
    start: Vec<(ItemId, Item, f64)>,
}

#[derive(Debug, Clone)]
pub struct Editor {
    doc: Document,
    session: Session,
    history: History,
    drag: Option<Drag>,
}

impl Editor {
    pub fn new(file: MusFile) -> Self {
        Self { doc: Document::new(file), session: Session::default(), history: History::default(), drag: None }
    }

    pub fn open(bytes: &[u8]) -> Result<Self, MusError> {
        MusFile::parse(bytes).map(Self::new)
    }

    pub fn save(&self) -> Vec<u8> {
        self.doc.file().to_bytes()
    }

    /// The items in file order; `score_render::ItemId(i)` is the item at index i.
    pub fn file(&self) -> &MusFile {
        self.doc.file()
    }

    pub fn document(&self) -> &Document {
        &self.doc
    }

    pub fn id_at(&self, index: usize) -> Option<ItemId> {
        self.doc.id_at(index)
    }

    pub fn index_of(&self, id: ItemId) -> Option<usize> {
        self.doc.index_of(id)
    }

    pub fn item(&self, id: ItemId) -> Option<&Item> {
        self.doc.item(id)
    }

    // -- selection ----------------------------------------------------------

    pub fn selection(&self) -> &[ItemId] {
        self.session.selection()
    }

    /// Selects `ids`, as clicking an item puts it into edit mode. Unknown ids are ignored.
    pub fn select(&mut self, ids: &[ItemId]) {
        self.cancel_drag();
        self.session.select(&self.doc, ids);
    }

    pub fn add_to_selection(&mut self, id: ItemId) {
        let mut ids = self.selection().to_vec();
        ids.push(id);
        self.select(&ids);
    }

    pub fn clear_selection(&mut self) {
        self.cancel_drag();
        self.session.clear();
    }

    // -- actions, one undo step each -----------------------------------------

    /// Runs `action` as one undoable step; on error nothing changes.
    fn act(
        &mut self,
        label: &str,
        action: impl FnOnce(&mut Run<'_, '_>) -> Result<(), EditError>,
    ) -> Result<Change, EditError> {
        self.cancel_drag();
        let mut session = self.session.clone();
        let mut tx = Transaction::new(&mut self.doc);
        action(&mut Run { session: &mut session, tx: &mut tx })?;
        let edits = tx.commit();
        let before = std::mem::replace(&mut self.session, session);
        let change = Change::new(&edits, self.session.selection());
        if !edits.is_empty() {
            self.history.record(Step {
                label: label.to_owned(),
                edits,
                selection_before: before.selection().to_vec(),
                selection_after: self.session.selection().to_vec(),
            });
        }
        Ok(change)
    }

    /// Executes a SCORE command line as typed or sent by a WinScore menu, e.g.
    /// `R 5`, `600 5`, `FLI`, `DE`, `NOTE 1 50`, `TREB`.
    pub fn execute(&mut self, line: &str) -> Result<Change, EditError> {
        self.act(line.trim(), |run| run.line(line))
    }

    /// Sets parameter `n` (1-based) of any item, selected or not.
    pub fn set_param(&mut self, id: ItemId, n: usize, value: f32) -> Result<Change, EditError> {
        if !(1..=MAX_PARAM).contains(&n) {
            return Err(EditError::NoSuchParam(n as f32));
        }
        let item = self.doc.item(id).ok_or(EditError::NoSuchId(id))?;
        let mut draft = Draft::of(item);
        draft.set(n, value);
        let stored = draft.to_item();
        self.act(&format!("Set P{n}"), |run| {
            run.tx.replace(id, stored);
            Ok(())
        })
    }

    /// Moves the selection by `dp3` horizontal spaces and `dp4` scale steps,
    /// right ends included (arrow keys: 1; Page Up/Down: 4; Home/End: 10).
    pub fn move_selection(&mut self, dp3: f32, dp4: f32) -> Result<Change, EditError> {
        self.act("Move", |run| {
            run.rewrite_selected(|draft| {
                shift(draft, Axis::Horizontal, f64::from(dp3));
                shift(draft, Axis::Vertical, f64::from(dp4));
            });
            Ok(())
        })
    }

    /// Moves the selection `delta` staves up (WinScore's `[` and `]`: P2 ± 1).
    pub fn move_staff(&mut self, delta: i32) -> Result<Change, EditError> {
        self.act("Move to staff", |run| {
            run.rewrite_selected(|draft| draft.add(2, delta as f32));
            Ok(())
        })
    }

    /// Deletes the selection and leaves edit mode (UND brings it back).
    pub fn delete_selection(&mut self) -> Result<Change, EditError> {
        self.act("Delete", |run| run.delete_selected(None))
    }

    /// Appends items (from the music input passes, say) and selects them.
    pub fn insert_items(&mut self, items: Vec<Item>) -> Result<Change, EditError> {
        self.act("Insert", |run| run.append_items(items))
    }

    // -- dragging -------------------------------------------------------------

    /// Starts dragging the selection.
    pub fn drag_begin(&mut self) {
        let staves = RenderDocument::new(self.doc.file()).staves;
        let start = self
            .selection()
            .iter()
            .filter_map(|&id| {
                let item = self.doc.item(id)?.clone();
                let step = staves.get(item.param(2) as i32).scale_step();
                Some((id, item, step))
            })
            .collect();
        self.drag = Some(Drag { start });
    }

    /// Shows the selection moved by (`dx`, `dy`) page units since [`Editor::drag_begin`],
    /// without an undo step.
    pub fn drag_to(&mut self, dx: f64, dy: f64) -> Change {
        let Some(drag) = &self.drag else { return Change::default() };
        let edits: Vec<Edit> = drag
            .start
            .iter()
            .filter_map(|(id, start, step)| {
                let mut draft = Draft::of(start);
                shift(&mut draft, Axis::Horizontal, on_grid(dx / P3_UNIT));
                shift(&mut draft, Axis::Vertical, on_grid(dy / step));
                replacement(&self.doc, *id, draft.to_item())
            })
            .collect();
        self.doc.apply_all(&edits);
        Change::new(&edits, self.selection())
    }

    /// Ends a drag: `commit` keeps the new positions as one undo step, otherwise
    /// the items return to where they were.
    pub fn drag_end(&mut self, commit: bool) -> Change {
        let Some(drag) = self.drag.take() else { return Change::default() };
        let moved: Vec<(ItemId, Item)> =
            drag.start.iter().filter_map(|(id, ..)| Some((*id, self.doc.item(*id)?.clone()))).collect();
        let back: Vec<Edit> =
            drag.start.iter().filter_map(|(id, start, _)| replacement(&self.doc, *id, start.clone())).collect();
        self.doc.apply_all(&back);
        if !commit {
            return Change::new(&back, self.selection());
        }
        self.act("Drag", |run| {
            moved.into_iter().for_each(|(id, item)| {
                run.tx.replace(id, item);
            });
            Ok(())
        })
        .unwrap_or_default()
    }

    fn cancel_drag(&mut self) {
        if self.drag.is_some() {
            self.drag_end(false);
        }
    }

    // -- undo -----------------------------------------------------------------

    pub fn undo(&mut self) -> Option<Change> {
        self.cancel_drag();
        let step = self.history.undo()?.clone();
        self.doc.revert_all(&step.edits);
        self.session.select(&self.doc, &step.selection_before);
        let inverse: Vec<Edit> = step.edits.iter().rev().map(Edit::inverse).collect();
        Some(Change::new(&inverse, self.selection()))
    }

    pub fn redo(&mut self) -> Option<Change> {
        self.cancel_drag();
        let step = self.history.redo()?.clone();
        self.doc.apply_all(&step.edits);
        self.session.select(&self.doc, &step.selection_after);
        Some(Change::new(&step.edits, self.selection()))
    }

    pub fn can_undo(&self) -> bool {
        self.history.undo_label().is_some()
    }

    pub fn can_redo(&self) -> bool {
        self.history.redo_label().is_some()
    }

    /// The command or action the next undo reverts, e.g. "R 5" or "Drag".
    pub fn undo_label(&self) -> Option<&str> {
        self.history.undo_label()
    }

    pub fn redo_label(&self) -> Option<&str> {
        self.history.redo_label()
    }
}

fn on_grid(offset: f64) -> f64 {
    f64::from(((offset as f32) / DRAG_GRID).round() * DRAG_GRID)
}

/// The edit that gives item `id` the content `after`, if that changes anything.
fn replacement(doc: &Document, id: ItemId, after: Item) -> Option<Edit> {
    let index = doc.index_of(id)?;
    let before = doc.file().items[index].clone();
    (before != after).then_some(Edit::Replace { index, id, before, after })
}
