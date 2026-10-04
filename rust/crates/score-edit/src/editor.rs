//! The editing API for the browser shell: an open score, its selection,
//! commands, drags and undo.

use score_format::{Item, MusError, MusFile};
use score_render::staff::Staff;
use score_render::Document as RenderDocument;

use crate::command::moves::{shift, Axis};
use crate::command::Run;
use crate::document::{Document, Edit, ItemId, Transaction};
use crate::drag::{self, Axes, Constraint, Ends, PagePoint};
use crate::error::EditError;
use crate::group::{Pending, Region};
use crate::history::{History, Step};
use crate::params::{Draft, MAX_PARAM};
use crate::pick;
use crate::session::Session;

/// P1 of library symbols.
const SYMBOL_CODE: f32 = 9.0;

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

/// One dragged item as it was when the drag began, with its staff.
#[derive(Debug, Clone, PartialEq)]
struct Dragged {
    id: ItemId,
    start: Item,
    staff: Staff,
}

/// A drag in progress.
#[derive(Debug, Clone, PartialEq)]
struct Drag {
    items: Vec<Dragged>,
    /// Where the cursor took hold of the selection.
    grab: PagePoint,
    ends: Ends,
    constraint: Constraint,
}

#[derive(Debug, Clone)]
pub struct Editor {
    doc: Document,
    session: Session,
    history: History,
    drag: Option<Drag>,
}

impl Editor {
    /// Opens `file`. Text items get the lengths (P13) the engine measures when
    /// it first draws the page; scores saved by WinScore already have them.
    pub fn new(file: MusFile) -> Self {
        let mut doc = Document::new(file);
        let mut session = Session::default();
        let mut tx = Transaction::new(&mut doc);
        Run { session: &mut session, tx: &mut tx }.refresh_text_lengths();
        tx.commit();
        Self { doc, session, history: History::default(), drag: None }
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

    /// Selects every item of an area (a box drawn on the page): staves
    /// `region.bottom..=region.top`, P3 between `left` and `right`, the given codes.
    pub fn select_region(&mut self, region: &Region) {
        self.cancel_drag();
        let mut tx = Transaction::new(&mut self.doc);
        Run { session: &mut self.session, tx: &mut tx }.select_region(region);
    }

    /// The question a group command is waiting to have answered by the next
    /// line given to [`Editor::execute`], if any.
    pub fn prompt(&self) -> Option<&'static str> {
        self.session.pending.as_ref().map(Pending::prompt)
    }

    /// The item WinScore's click at page point (`x`, `y`) would select: the
    /// one whose reference point (P3, P4 and a per-code offset) is nearest,
    /// within `radius` page units if given.
    pub fn pick_at(&self, x: f64, y: f64, radius: Option<f64>) -> Option<ItemId> {
        let staves = RenderDocument::new(self.doc.file()).staves;
        let items = self.doc.file().items.iter().map(|item| (item, staves.get(item.param(2) as i32)));
        pick::nearest(items, PagePoint { x, y }, radius).and_then(|i| self.doc.id_at(i))
    }

    /// Selects what a click at (`x`, `y`) means (decision D8): the item whose
    /// drawn outline the shell found under the cursor, or else the nearest
    /// reference point within `radius`; nothing found clears the selection.
    pub fn select_at(&mut self, x: f64, y: f64, outline_hit: Option<ItemId>, radius: f64) -> Option<ItemId> {
        let picked = outline_hit.filter(|&id| self.doc.contains(id)).or_else(|| self.pick_at(x, y, Some(radius)));
        self.select(picked.as_slice());
        picked
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
        let mut run = Run { session: &mut session, tx: &mut tx };
        action(&mut run)?;
        run.refresh_text_lengths();
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

    /// New characters for text item `id` (WinScore's Edit Text). Without a
    /// font code of their own they keep the item's font; P12 and P13 follow.
    pub fn set_text(&mut self, id: ItemId, text: &str) -> Result<Change, EditError> {
        self.act("Edit text", |run| run.set_text(id, &crate::text::encode(text)))
    }

    /// New text items as quick entry `"text" p2 p3 …` makes them: `params`
    /// are P2, P3, … (0 keeps the default), `/` divides the text into items.
    pub fn insert_text(&mut self, text: &str, params: &[f32]) -> Result<Change, EditError> {
        let rest: Vec<String> = params.iter().map(f32::to_string).collect();
        self.act("Text", |run| {
            run.session.clear();
            run.enter_text(&crate::text::encode(text), &rest.join(" "))
        })
    }

    /// A code-9 item showing library symbol `number` (see
    /// [`crate::symbols::library_symbols`]) on `staff` at P3, P4, selected.
    pub fn insert_symbol(&mut self, number: i32, staff: f32, p3: f32, p4: f32) -> Result<Change, EditError> {
        let item = Draft::new(&[SYMBOL_CODE, staff, p3, p4, number as f32]).to_item();
        self.act("Symbol", |run| {
            run.session.clear();
            run.append_items(vec![item])
        })
    }

    /// Appends items (from the music input passes, say) and selects them.
    pub fn insert_items(&mut self, items: Vec<Item>) -> Result<Change, EditError> {
        self.act("Insert", |run| run.append_items(items))
    }

    // -- dragging -------------------------------------------------------------

    /// Starts dragging the selection, taken hold of at page point (`x`, `y`)
    /// (engine units, origin at the paper's bottom-left corner, y up). LFT or
    /// RGT before it make the drag move only that end of a two-point item.
    pub fn drag_begin_at(&mut self, x: f64, y: f64) {
        let staves = RenderDocument::new(self.doc.file()).staves;
        let items = self
            .selection()
            .iter()
            .filter_map(|&id| {
                let start = self.doc.item(id)?.clone();
                let staff = staves.get(start.param(2) as i32);
                Some(Dragged { id, start, staff })
            })
            .collect();
        let grab = PagePoint { x, y };
        self.drag = Some(Drag { items, grab, ends: self.session.drag_ends(), constraint: Constraint::default() });
    }

    /// Moves the selection with the cursor at page point (`x`, `y`), keeping
    /// the grab offset; P3 and P4 come out as the engine computes them (P4 in
    /// whole steps for notes, rests, clefs, keys and meters, right ends along).
    /// `constrain` (Shift) locks the move to the first dominant axis after
    /// WinScore's rule. No undo step until [`Editor::drag_end`].
    pub fn drag_to_point(&mut self, x: f64, y: f64, constrain: bool) -> Change {
        let Some(drag) = &mut self.drag else { return Change::default() };
        let point = PagePoint { x, y };
        let axes = if constrain { drag.constraint.admit(point) } else { Some(Axes::Both) };
        let Some(axes) = axes else { return Change::default() };
        let (dx, dy) = (point.x - drag.grab.x, point.y - drag.grab.y);
        let edits: Vec<Edit> = drag
            .items
            .iter()
            .filter_map(|item| {
                let moved = drag::dragged(&Draft::of(&item.start), &item.staff, drag.ends, dx, dy, axes);
                replacement(&self.doc, item.id, moved.to_item())
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
            drag.items.iter().filter_map(|d| Some((d.id, self.doc.item(d.id)?.clone()))).collect();
        let back: Vec<Edit> =
            drag.items.iter().filter_map(|d| replacement(&self.doc, d.id, d.start.clone())).collect();
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


/// The edit that gives item `id` the content `after`, if that changes anything.
fn replacement(doc: &Document, id: ItemId, after: Item) -> Option<Edit> {
    let index = doc.index_of(id)?;
    let before = doc.file().items[index].clone();
    (before != after).then_some(Edit::Replace { index, id, before, after })
}
