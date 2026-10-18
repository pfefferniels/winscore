//! Undo and redo: one step per user action.

use crate::document::{Edit, ItemId};

/// What one user action did: its edits, and the selection before and after.
#[derive(Debug, Clone, PartialEq)]
pub struct Step {
    pub label: String,
    pub edits: Vec<Edit>,
    pub selection_before: Vec<ItemId>,
    pub selection_after: Vec<ItemId>,
}

#[derive(Debug, Clone, PartialEq, Default)]
pub struct History {
    done: Vec<Step>,
    undone: Vec<Step>,
}

impl History {
    /// Records a new step; whatever was undone can no longer be redone.
    pub fn record(&mut self, step: Step) {
        self.done.push(step);
        self.undone.clear();
    }

    /// The step to revert, moved to the redo side.
    pub fn undo(&mut self) -> Option<&Step> {
        let step = self.done.pop()?;
        self.undone.push(step);
        self.undone.last()
    }

    /// The step to apply again, moved back to the undo side.
    pub fn redo(&mut self) -> Option<&Step> {
        let step = self.undone.pop()?;
        self.done.push(step);
        self.done.last()
    }

    /// How many steps there are to undo.
    pub fn depth(&self) -> usize {
        self.done.len()
    }

    /// The last step, taken off without moving it to the redo side.
    pub fn discard(&mut self) -> Option<Step> {
        self.done.pop()
    }

    /// Makes the steps after the first `depth` one step called `label`:
    /// their edits in order, the selection before the first and after the
    /// last. False when there are none.
    pub fn combine(&mut self, depth: usize, label: &str) -> bool {
        if self.done.len() <= depth {
            return false;
        }
        let mut steps = self.done.split_off(depth).into_iter();
        let mut combined = steps.next().unwrap_or_else(|| unreachable!("at least one step after depth"));
        for step in steps {
            combined.edits.extend(step.edits);
            combined.selection_after = step.selection_after;
        }
        combined.label = label.to_owned();
        self.done.push(combined);
        true
    }

    pub fn undo_label(&self) -> Option<&str> {
        self.done.last().map(|s| s.label.as_str())
    }

    pub fn redo_label(&self) -> Option<&str> {
        self.undone.last().map(|s| s.label.as_str())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn step(label: &str) -> Step {
        Step { label: label.into(), edits: Vec::new(), selection_before: Vec::new(), selection_after: Vec::new() }
    }

    #[test]
    fn undo_and_redo_walk_the_steps() {
        let mut h = History::default();
        h.record(step("a"));
        h.record(step("b"));
        assert_eq!(h.undo().map(|s| s.label.clone()), Some("b".into()));
        assert_eq!(h.undo_label(), Some("a"));
        assert_eq!(h.redo_label(), Some("b"));
        assert_eq!(h.redo().map(|s| s.label.clone()), Some("b".into()));
        assert_eq!(h.redo_label(), None);
    }

    #[test]
    fn steps_after_a_depth_combine_into_one() {
        let mut h = History::default();
        h.record(step("a"));
        let depth = h.depth();
        h.record(Step { selection_before: vec![ItemId(1)], ..step("b") });
        h.record(Step { selection_after: vec![ItemId(2)], ..step("c") });
        assert!(h.combine(depth, "b and c"));
        assert_eq!(h.depth(), 2);
        let last = h.discard().unwrap();
        assert_eq!((last.label.as_str(), last.selection_before, last.selection_after), ("b and c", vec![ItemId(1)], vec![ItemId(2)]));
        assert!(!h.combine(1, "nothing after a"));
        assert_eq!(h.redo_label(), None);
    }

    #[test]
    fn a_new_step_drops_the_redo_side() {
        let mut h = History::default();
        h.record(step("a"));
        h.undo();
        h.record(step("c"));
        assert!(h.redo().is_none());
        assert_eq!(h.undo_label(), Some("c"));
    }
}
