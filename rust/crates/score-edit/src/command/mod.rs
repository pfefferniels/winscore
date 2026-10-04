//! SCORE command lines as WinScore's menus and command bar send them.
//!
//! With items selected (WinScore's edit mode), numbers change parameters and
//! words such as `R 5`, `FLI`, `DE` or `C` act on the selection. Without a
//! selection, numbers create an item from its parameters and shortcut words
//! (`NOTE`, `TREB`, `METER34`) create one with the engine's defaults; the new
//! item is selected, as the engine puts new items straight into edit mode.

pub mod create;
pub mod item;
pub mod line;
pub mod moves;
pub mod note;
pub mod numeric;
pub mod parse;

use score_render::Document as RenderDocument;

use crate::document::{ItemId, Transaction};
use crate::drag::Ends;
use crate::error::EditError;
use crate::params::Draft;
use crate::session::{Deleted, Session};
use create::{StaffChoice, Template};
use moves::Move;
use numeric::ParamOp;
use parse::Token;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Direction {
    Forward,
    Back,
}

/// Where edit mode goes after the selected items are deleted or left.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) struct Next {
    direction: Direction,
    same_code: bool,
}

const FORWARD: Next = Next { direction: Direction::Forward, same_code: false };
const BACK: Next = Next { direction: Direction::Back, same_code: false };
const FORWARD_SAME: Next = Next { direction: Direction::Forward, same_code: true };
const BACK_SAME: Next = Next { direction: Direction::Back, same_code: true };

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum CopyMode {
    /// C: keep the edited version as a copy, restore the original, leave edit mode.
    Exit,
    /// CC: the same, then edit the copy.
    Continue,
    /// CX: the same, then edit the item after the original.
    NextItem,
}

/// Words about edit mode itself rather than about an item's parameters.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum SessionWord {
    /// X, or `X n` to go on with item n.
    Leave,
    Abort { exit: bool },
    Copy(CopyMode),
    Delete(Next),
    Step(Next),
    /// `I n`, `I`.
    Edit,
    /// II.
    EditLast,
    Undelete,
    /// LFT, RGT: drags move only that end of a line, slur, beam or trill.
    DragEnd(Ends),
}

impl SessionWord {
    fn parse(word: &str) -> Option<Self> {
        let parsed = match word {
            "X" => Self::Leave,
            "AB" => Self::Abort { exit: false },
            "ABX" => Self::Abort { exit: true },
            "C" => Self::Copy(CopyMode::Exit),
            "CC" => Self::Copy(CopyMode::Continue),
            "CX" => Self::Copy(CopyMode::NextItem),
            "DE" => Self::Delete(FORWARD),
            "DEN" => Self::Delete(FORWARD_SAME),
            "DEB" => Self::Delete(BACK_SAME),
            "NEX" => Self::Step(FORWARD),
            "B" => Self::Step(BACK),
            "NZ" => Self::Step(FORWARD_SAME),
            "BZ" => Self::Step(BACK_SAME),
            "I" => Self::Edit,
            "II" => Self::EditLast,
            "UND" => Self::Undelete,
            "LFT" => Self::DragEnd(Ends::Left),
            "RGT" => Self::DragEnd(Ends::Right),
            _ => return None,
        };
        Some(parsed)
    }
}

/// Whether the editor knows the command of `line` in some context; menus
/// can grey out the entries it does not.
pub fn is_supported(line: &str) -> bool {
    let tokens = parse::tokens(line);
    match tokens.first() {
        None => false,
        Some(Token::Word(w)) => {
            let word = w.to_ascii_uppercase();
            SessionWord::parse(&word).is_some()
                || Move::parse(&word, first_number(&tokens[1..])).is_some_and(Move::is_complete)
                || item::is_edit_word(&word)
                || create::template(&word).is_some()
        }
        Some(_) => numeric::param_ops(&tokens).is_some_and(|ops| ops.is_ok()),
    }
}

pub(crate) struct Run<'a, 'd> {
    pub session: &'a mut Session,
    pub tx: &'a mut Transaction<'d>,
}

fn word_and_args(tokens: &[Token]) -> Result<(String, &[Token]), EditError> {
    match tokens.split_first() {
        Some((Token::Word(w), args)) => Ok((w.to_ascii_uppercase(), args)),
        Some((other, _)) => Err(EditError::UnknownCommand(format!("{other:?}"))),
        None => Err(EditError::UnknownCommand(String::new())),
    }
}

fn first_number(args: &[Token]) -> Option<f32> {
    args.first().and_then(Token::number)
}

/// An all-number line outside edit mode: the parameters of a new item.
fn plain_numbers(tokens: &[Token]) -> Option<Vec<f32>> {
    tokens.iter().map(Token::number).collect()
}

/// Item number `n` (1-based) clamped to the last item, as `I 99` edits the last one.
fn clamp_item(n: f32, len: usize) -> Option<usize> {
    (len > 0).then(|| (n.max(1.0) as usize).min(len) - 1)
}

impl Run<'_, '_> {
    /// Executes one command line.
    pub fn line(&mut self, line: &str) -> Result<(), EditError> {
        let tokens = parse::tokens(line);
        if tokens.is_empty() {
            Ok(())
        } else if self.session.in_edit_mode() {
            self.in_edit_mode(&tokens)
        } else {
            self.outside_edit_mode(&tokens)
        }
    }

    fn in_edit_mode(&mut self, tokens: &[Token]) -> Result<(), EditError> {
        if let Some(ops) = numeric::param_ops(tokens) {
            return self.change_params(&ops?);
        }
        let (word, args) = word_and_args(tokens)?;
        let number = first_number(args);
        match SessionWord::parse(&word) {
            Some(SessionWord::Leave) => self.leave(number),
            Some(SessionWord::Abort { exit }) => {
                self.abort();
                if exit {
                    self.session.clear();
                }
                Ok(())
            }
            Some(SessionWord::Copy(mode)) => self.copy(mode),
            Some(SessionWord::Delete(next)) => self.delete_selected(Some(next)),
            Some(SessionWord::Step(next)) => self.step(next),
            Some(SessionWord::Edit) => self.edit_item(number),
            Some(SessionWord::EditLast) => self.edit_last(),
            Some(SessionWord::Undelete) => Err(EditError::InEditMode(word)),
            Some(SessionWord::DragEnd(end)) => {
                self.session.toggle_drag_end(end);
                Ok(())
            }
            None => self.edit_word(&word, args),
        }
    }

    fn outside_edit_mode(&mut self, tokens: &[Token]) -> Result<(), EditError> {
        if let Some(values) = plain_numbers(tokens) {
            return self.create_item(Draft::new(&values));
        }
        let (word, args) = word_and_args(tokens)?;
        let number = first_number(args);
        match SessionWord::parse(&word) {
            Some(SessionWord::Leave) => self.leave(number),
            Some(SessionWord::Edit) => self.edit_item(number),
            Some(SessionWord::EditLast) => self.edit_last(),
            Some(SessionWord::Undelete) => self.undelete(),
            Some(_) => Err(EditError::NoSelection(word)),
            None => match create::template(&word) {
                Some(template) => self.create(&template, args),
                None if item::is_edit_word(&word) || Move::parse(&word, None).is_some() => {
                    Err(EditError::NoSelection(word))
                }
                None => Err(EditError::UnknownCommand(word)),
            },
        }
    }

    fn edit_word(&mut self, word: &str, args: &[Token]) -> Result<(), EditError> {
        if let Some(mv) = Move::parse(word, first_number(args)) {
            return self.move_by(mv);
        }
        let fits_selection = self.selected_codes().iter().any(|&code| item::lookup(word, code).is_some());
        match create::template(word) {
            Some(template) if !fits_selection => {
                self.session.clear();
                self.create(&template, args)
            }
            _ if item::is_edit_word(word) => self.rewrite(word, first_number(args)),
            _ => Err(EditError::UnknownCommand(word.to_owned())),
        }
    }

    fn selected_codes(&self) -> Vec<i32> {
        self.selection().iter().filter_map(|&id| self.tx.doc().item(id)).map(|i| i.code()).collect()
    }

    fn selection(&self) -> Vec<ItemId> {
        self.session.selection().to_vec()
    }

    /// Rewrites every selected item with `change`; unchanged items record nothing.
    pub fn rewrite_selected(&mut self, mut change: impl FnMut(&mut Draft)) {
        self.selection().into_iter().for_each(|id| {
            let Some(item) = self.tx.doc().item(id) else { return };
            let mut draft = Draft::of(item);
            change(&mut draft);
            if !draft.describes(item) {
                self.tx.replace(id, draft.to_item());
            }
        });
    }

    fn change_params(&mut self, ops: &[ParamOp]) -> Result<(), EditError> {
        self.rewrite_selected(|draft| ops.iter().for_each(|op| op.apply(draft)));
        Ok(())
    }

    fn move_by(&mut self, mv: Move) -> Result<(), EditError> {
        let staves = RenderDocument::new(self.tx.doc().file()).staves;
        let start = self.session.increments;
        let mut increments = start;
        self.rewrite_selected(|draft| {
            increments = start;
            let size = staves.get(draft.get(2) as i32).size;
            let distance = mv.distance(&mut increments, size);
            moves::shift(draft, mv.axis, distance);
        });
        self.session.increments = increments;
        Ok(())
    }

    fn rewrite(&mut self, word: &str, arg: Option<f32>) -> Result<(), EditError> {
        let codes = self.selected_codes();
        if !codes.iter().any(|&code| item::lookup(word, code).is_some()) {
            let code = codes.first().copied().unwrap_or(0);
            return Err(EditError::NotForCode { command: word.to_owned(), code });
        }
        self.rewrite_selected(|draft| {
            if let Some(entry) = item::lookup(word, draft.code()) {
                entry.op.apply(draft, arg);
            }
        });
        Ok(())
    }

    /// X, or `X n` to go on with item n.
    fn leave(&mut self, item: Option<f32>) -> Result<(), EditError> {
        self.session.clear();
        match item {
            Some(n) => self.edit_item(Some(n)),
            None => Ok(()),
        }
    }

    fn edit_index(&mut self, index: Option<usize>, asked: Option<f32>) -> Result<(), EditError> {
        let doc = self.tx.doc();
        let id = index.and_then(|i| doc.id_at(i)).ok_or(EditError::NoSuchItem(asked.unwrap_or(0.0) as usize))?;
        self.session.select(doc, &[id]);
        Ok(())
    }

    /// `I n` edits item n; `I` alone (or `I 0`) the item last edited or entered.
    fn edit_item(&mut self, number: Option<f32>) -> Result<(), EditError> {
        let doc = self.tx.doc();
        let index = match number {
            Some(n) if n > 0.0 => clamp_item(n, doc.len()),
            _ => self.session.current(doc).and_then(|id| doc.index_of(id)).or(doc.len().checked_sub(1)),
        };
        self.edit_index(index, number)
    }

    /// II: the last item.
    fn edit_last(&mut self) -> Result<(), EditError> {
        let last = self.tx.doc().len().checked_sub(1);
        self.edit_index(last, None)
    }

    /// AB: the selected items as they were when selected.
    fn abort(&mut self) {
        self.selection().into_iter().for_each(|id| {
            if let Some(original) = self.session.original(id).cloned() {
                self.tx.replace(id, original);
            }
        });
    }

    fn copy(&mut self, mode: CopyMode) -> Result<(), EditError> {
        let originals = self.selection();
        let copies: Vec<ItemId> = originals
            .iter()
            .filter_map(|&id| {
                let edited = self.tx.doc().item(id)?.clone();
                let copy = self.tx.append(edited);
                if let Some(original) = self.session.original(id).cloned() {
                    self.tx.replace(id, original);
                }
                Some(copy)
            })
            .collect();
        let doc = self.tx.doc();
        let after_original = originals.last().and_then(|&id| doc.index_of(id)).and_then(|i| doc.id_at(i + 1));
        let next: Vec<ItemId> = match mode {
            CopyMode::Exit => Vec::new(),
            CopyMode::Continue => copies.clone(),
            CopyMode::NextItem => after_original.into_iter().collect(),
        };
        self.session.select(doc, &next);
        if let Some(&last) = copies.last().filter(|_| mode == CopyMode::Exit) {
            self.session.set_current(last);
        }
        Ok(())
    }

    /// The item to edit after leaving the item at `index` (which may be gone).
    fn neighbour(&self, index: usize, next: Next, code: i32, removed: bool) -> Option<ItemId> {
        let doc = self.tx.doc();
        let fits = |i: &usize| !next.same_code || doc.file().items[*i].code() == code;
        let found = match next.direction {
            Direction::Forward => (if removed { index } else { index + 1 }..doc.len()).find(fits),
            Direction::Back => (0..index).rev().find(fits),
        };
        found.and_then(|i| doc.id_at(i))
    }

    fn step(&mut self, next: Next) -> Result<(), EditError> {
        let doc = self.tx.doc();
        let Some(&last) = self.session.selection().last() else { return Ok(()) };
        let (Some(index), Some(item)) = (doc.index_of(last), doc.item(last)) else { return Ok(()) };
        let target = self.neighbour(index, next, item.code(), false);
        self.session.select(self.tx.doc(), target.as_slice());
        Ok(())
    }

    /// Deletes the selection, remembering it for UND; with `next`, edit mode
    /// moves on as after DE, otherwise it ends.
    pub fn delete_selected(&mut self, next: Option<Next>) -> Result<(), EditError> {
        let removed: Vec<Deleted> = self
            .selection()
            .into_iter()
            .filter_map(|id| self.tx.remove(id).map(|(index, item)| Deleted { index, id, item }))
            .collect();
        let target = next.zip(removed.first()).and_then(|(next, first)| self.neighbour(first.index, next, first.item.code(), true));
        self.session.remember_deleted(removed);
        self.session.select(self.tx.doc(), target.as_slice());
        Ok(())
    }

    fn undelete(&mut self) -> Result<(), EditError> {
        let batch = self.session.take_deleted(self.tx.doc()).ok_or(EditError::NothingToUndelete)?;
        batch.iter().rev().for_each(|d| self.tx.restore(d.index, d.id, d.item.clone()));
        let ids: Vec<ItemId> = batch.iter().map(|d| d.id).collect();
        self.session.select(self.tx.doc(), &ids);
        Ok(())
    }

    /// The staff for a new item.
    fn staff_for(&self, choice: StaffChoice) -> f32 {
        let doc = self.tx.doc();
        match choice {
            StaffChoice::Current => {
                let reference = self.session.current(doc).or(doc.ids().last().copied());
                reference.and_then(|id| doc.item(id)).map_or(1.0, |item| item.param(2))
            }
            StaffChoice::AboveHighest => {
                doc.file().items.iter().map(|item| item.param(2)).fold(0.0, f32::max).trunc() + 1.0
            }
        }
    }

    /// Appends a new item and puts it in edit mode.
    fn create_item(&mut self, draft: Draft) -> Result<(), EditError> {
        self.append_items(vec![draft.to_item()])
    }

    /// Appends items in order and selects them.
    pub fn append_items(&mut self, items: Vec<score_format::Item>) -> Result<(), EditError> {
        let ids: Vec<ItemId> = items.into_iter().map(|item| self.tx.append(item)).collect();
        self.session.select(self.tx.doc(), &ids);
        Ok(())
    }

    /// A shortcut word's item: leading numbers fill P2, P3, …; words after them
    /// are edit commands for the new item (`NOTE RHE`).
    fn create(&mut self, template: &Template, args: &[Token]) -> Result<(), EditError> {
        let count = args.iter().take_while(|t| t.number().is_some()).count();
        let numbers: Vec<f32> = args[..count].iter().filter_map(Token::number).collect();
        let staff = self.staff_for(template.staff);
        self.create_item(template.place(staff, &numbers))?;
        args[count..].iter().try_for_each(|word| self.in_edit_mode(std::slice::from_ref(word)))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn item_numbers_clamp_to_the_last_item() {
        assert_eq!(clamp_item(99.0, 3), Some(2));
        assert_eq!(clamp_item(2.0, 3), Some(1));
        assert_eq!(clamp_item(1.0, 0), None);
    }

    #[test]
    fn only_all_number_lines_create_items() {
        assert_eq!(plain_numbers(&parse::tokens("1 1 50 3 20")), Some(vec![1.0, 1.0, 50.0, 3.0, 20.0]));
        assert_eq!(plain_numbers(&parse::tokens("/2 1")), None);
    }
}
