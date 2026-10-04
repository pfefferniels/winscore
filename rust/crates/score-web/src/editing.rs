//! Selection, edits, drags and undo through `score-edit`.
//!
//! Items are named by their index in file order on this side of the API.
//! Every action returns the name of the undo step it made ("Move", "R 5"),
//! or an empty string when it changed nothing; call [`Score::render`] to see
//! the result.

use score_edit::{Change, EditError};
use score_render::ItemId;
use wasm_bindgen::prelude::*;

use crate::hit::At;
use crate::input::{line_items, InputLine};
use crate::Score;

fn indices(items: &[ItemId]) -> Vec<u32> {
    items.iter().map(|id| id.0).collect()
}

impl Score {
    fn finish(&self, result: Result<Change, EditError>) -> Result<String, JsError> {
        let change = result?;
        Ok(self.0.label(&change).unwrap_or_default())
    }
}

#[wasm_bindgen]
impl Score {
    /// Selects items by index, the primary one last.
    pub fn select(&mut self, items: Vec<u32>) {
        let items: Vec<ItemId> = items.into_iter().map(ItemId).collect();
        self.0.select(&items);
    }

    /// The selected item indices, in selection order.
    pub fn selection(&self) -> Vec<u32> {
        indices(&self.0.selection())
    }

    /// Sets parameter `n` (1-based) of item `index`, selected or not.
    #[wasm_bindgen(js_name = setParam)]
    pub fn set_param(&mut self, index: u32, n: usize, value: f32) -> Result<String, JsError> {
        let id = self.0.id(ItemId(index))?;
        let result = self.0.editor_mut().set_param(id, n, value);
        self.finish(result)
    }

    /// Moves the selection by `dp3` P3 spaces and `dp4` scale steps.
    #[wasm_bindgen(js_name = moveSelection)]
    pub fn move_selection(&mut self, dp3: f32, dp4: f32) -> Result<String, JsError> {
        let result = self.0.editor_mut().move_selection(dp3, dp4);
        self.finish(result)
    }

    /// Moves the selection `delta` staves up (WinScore's `[` and `]`).
    #[wasm_bindgen(js_name = moveStaff)]
    pub fn move_staff(&mut self, delta: i32) -> Result<String, JsError> {
        let result = self.0.editor_mut().move_staff(delta);
        self.finish(result)
    }

    #[wasm_bindgen(js_name = deleteSelection)]
    pub fn delete_selection(&mut self) -> Result<String, JsError> {
        let result = self.0.editor_mut().delete_selection();
        self.finish(result)
    }

    /// A SCORE command line as typed in WinScore, e.g. `R 5`, `600 5`, `DE`, `TREB`.
    pub fn execute(&mut self, line: &str) -> Result<String, JsError> {
        let result = self.0.editor_mut().execute(line);
        self.finish(result)
    }

    /// Appends one line of five-pass input (and its staff, when missing) as
    /// one undo step; the new items become the selection.
    #[wasm_bindgen(js_name = insertInput)]
    pub fn insert_input(&mut self, line: &InputLine) -> Result<String, JsError> {
        let mut motives = self.0.motives().clone();
        let items = line_items(self.0.file(), line, &mut motives).map_err(|err| JsError::new(&err.message))?;
        let result = self.0.editor_mut().insert_items(items);
        if result.is_ok() {
            self.0.set_motives(motives);
        }
        self.finish(result)
    }

    /// Starts dragging the selection, taken hold of at page point (`x`, `y`).
    #[wasm_bindgen(js_name = dragBeginAt)]
    pub fn drag_begin_at(&mut self, x: f64, y: f64) {
        self.0.editor_mut().drag_begin_at(x, y);
    }

    /// Moves the dragged selection with the cursor at page point (`x`, `y`),
    /// keeping the grab offset, without an undo step. `constrain` is
    /// WinScore's Shift rule: the move locks to the first dominant axis.
    #[wasm_bindgen(js_name = dragToPoint)]
    pub fn drag_to_point(&mut self, x: f64, y: f64, constrain: bool) {
        self.0.editor_mut().drag_to_point(x, y, constrain);
    }

    /// Ends a drag; `commit` keeps the new positions as one undo step.
    #[wasm_bindgen(js_name = dragEnd)]
    pub fn drag_end(&mut self, commit: bool) -> String {
        let change = self.0.editor_mut().drag_end(commit);
        if commit {
            self.0.label(&change).unwrap_or_default()
        } else {
            String::new()
        }
    }

    /// The item a click at page point (`x`, `y`) means (decision D8): the one
    /// whose drawn outline lies within `tolerance` units, else the one whose
    /// reference point WinScore would pick within `radius` units.
    #[wasm_bindgen(js_name = itemAt)]
    pub fn item_at(&self, x: f64, y: f64, tolerance: f64, radius: f64) -> Option<u32> {
        let outline = self.0.hit(At::new(x, y), tolerance);
        let nearest = || {
            let editor = self.0.editor();
            editor.pick_at(x, y, Some(radius)).and_then(|id| editor.index_of(id)).map(|i| ItemId(i as u32))
        };
        outline.or_else(nearest).map(|id| id.0)
    }

    /// Reverts the last step; returns its name, or `None` if there is none.
    pub fn undo(&mut self) -> Option<String> {
        self.0.editor_mut().undo()?;
        self.redo_label()
    }

    pub fn redo(&mut self) -> Option<String> {
        self.0.editor_mut().redo()?;
        self.undo_label()
    }

    #[wasm_bindgen(js_name = undoLabel)]
    pub fn undo_label(&self) -> Option<String> {
        self.0.editor().undo_label().map(str::to_owned)
    }

    #[wasm_bindgen(js_name = redoLabel)]
    pub fn redo_label(&self) -> Option<String> {
        self.0.editor().redo_label().map(str::to_owned)
    }
}

/// Whether `score-edit` handles a command line yet.
#[wasm_bindgen(js_name = commandSupported)]
pub fn command_supported(line: &str) -> bool {
    score_edit::command::is_supported(line)
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::PathBuf;

    fn mozart() -> Score {
        let path = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../WINSCORE 5.01/winscore/mozart.mus");
        Score::new(&std::fs::read(path).unwrap()).unwrap_or_else(|_| panic!("mozart.mus opens"))
    }

    #[test]
    fn clicks_fall_back_to_the_nearest_reference_point() {
        let score = mozart();
        let far_from_ink = (33500.0, 28000.0);
        assert_eq!(score.item_at(far_from_ink.0, far_from_ink.1, 10.0, 100.0), None);
        assert!(score.item_at(far_from_ink.0, far_from_ink.1, 10.0, 60000.0).is_some());
    }

    #[test]
    fn drags_follow_the_cursor_and_undo_in_one_step() {
        let mut score = mozart();
        score.select(vec![12]);
        let p3 = score.0.item(ItemId(12)).unwrap().param(3);
        score.drag_begin_at(5000.0, 5000.0);
        score.drag_to_point(5150.0, 5000.0, false);
        score.drag_to_point(5300.0, 5000.0, false);
        assert_eq!(score.drag_end(true), "Drag");
        assert!((score.0.item(ItemId(12)).unwrap().param(3) - (p3 + 2.0)).abs() < 0.01);
        assert_eq!(score.undo().as_deref(), Some("Drag"));
        assert_eq!(score.0.item(ItemId(12)).unwrap().param(3), p3);
    }
}
