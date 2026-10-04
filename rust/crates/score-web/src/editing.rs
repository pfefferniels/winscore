//! Selection, edits, drags and undo through `score-edit`.
//!
//! Items are named by their index in file order on this side of the API.
//! Every action returns the name of the undo step it made ("Move", "R 5"),
//! or an empty string when it changed nothing; call [`Score::render`] to see
//! the result.

use score_edit::{Change, EditError};
use score_render::ItemId;
use wasm_bindgen::prelude::*;

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
        let items = line_items(self.0.file(), &line.texts(), &line.options()).map_err(|err| JsError::new(&err.message))?;
        let result = self.0.editor_mut().insert_items(items);
        self.finish(result)
    }

    /// Starts dragging the selection.
    #[wasm_bindgen(js_name = dragBegin)]
    pub fn drag_begin(&mut self) {
        self.0.editor_mut().drag_begin();
    }

    /// Shows the selection moved by (`dx`, `dy`) page units since
    /// [`Score::drag_begin`], without an undo step.
    #[wasm_bindgen(js_name = dragTo)]
    pub fn drag_to(&mut self, dx: f64, dy: f64) {
        self.0.editor_mut().drag_to(dx, dy);
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
