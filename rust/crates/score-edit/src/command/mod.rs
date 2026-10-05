//! SCORE command lines as WinScore's menus and command bar send them.
//!
//! With items selected (WinScore's edit mode), numbers change parameters and
//! words such as `R 5`, `FLI`, `DE` or `C` act on the selection. Without a
//! selection, numbers create an item from its parameters and shortcut words
//! (`NOTE`, `TREB`, `METER34`) create one with the engine's defaults; the new
//! item is selected, as the engine puts new items straight into edit mode.

pub mod beams;
pub mod create;
mod drawn;
pub mod groups;
pub mod item;
pub mod line;
pub mod moves;
pub mod note;
pub mod numeric;
pub mod parse;
pub mod signs;
pub mod text;

use score_render::Document as RenderDocument;

use crate::conditional;
use crate::document::{ItemId, Transaction};
use crate::drag::Ends;
use crate::group::{GroupCommand, LayoutCommand, Order};
use crate::error::EditError;
use crate::params::Draft;
use crate::session::{Deleted, Session};
use beams::StemFit;
use create::{StaffChoice, Template};
use moves::{Axis, Move};
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
#[derive(Debug, Clone, Copy, PartialEq)]
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
    /// CN [staff]: P3 of the nearest note or rest.
    Center,
    /// PSn: remember Pn of the item in edit mode.
    SaveParam(Option<f32>),
    /// PG, PGn: give the item the last remembered parameter (or the one remembered for Pn).
    RecallParam(Option<f32>),
    /// PT n: text size in points.
    PointSize,
    /// CT [x]: centre text on x.
    CentreText,
    /// CTN, CTX [staff]: centre text on the nearest note, CTX without punctuation.
    CentreTextOnNote { skip_punctuation: bool },
    /// JR [x]: text right-justified to x.
    JustifyRight,
    /// J [left right]: text justified between two positions.
    Justify,
    /// ADJ, ADJX, ADX, ADF, ADFX: stems reach their beam.
    AdjustStems(StemFit),
    /// CH [value]: one duration for the whole chord.
    ChordRhythm,
    /// PST: the items cut last, added again.
    Paste,
    /// QPn: the parameter the slider buttons change.
    SliderParam(usize),
    /// PCHNGn: a slider button, adding to the slider's parameter (or zeroing it).
    Slider(Option<f32>),
    /// The arrow keys (~~037x left … ~~040x down): one step.
    Arrow(Axis, f64),
    /// PGR: the page to the recto side and back (P2 ± 200).
    PageRight,
}

/// Edit words that take their number attached as well as after a blank (WB3, EU5).
const NUMBERED_WORDS: [&str; 2] = ["WB", "EU"];

/// PCHNG0 … PCHNG14: what each slider button adds (PCHNG0 zeroes).
const SLIDER_STEPS: [Option<f32>; 15] = [
    None,
    Some(-0.1),
    Some(-0.5),
    Some(-1.0),
    Some(-5.0),
    Some(-10.0),
    Some(-20.0),
    Some(0.1),
    Some(0.5),
    Some(1.0),
    Some(5.0),
    Some(10.0),
    Some(20.0),
    Some(0.05),
    Some(-0.05),
];
/// QP2 … QP21 choose the slider's parameter.
const SLIDER_PARAMS: std::ops::RangeInclusive<usize> = 2..=21;

impl SessionWord {
    fn parse(word: &str) -> Option<Self> {
        match parse::split_count(word) {
            ("PS", n) => return Some(Self::SaveParam(n)),
            ("PG", n) => return Some(Self::RecallParam(n)),
            ("PCHNG", Some(n)) if n >= 0.0 && n.fract() == 0.0 => {
                return SLIDER_STEPS.get(n as usize).map(|&step| Self::Slider(step));
            }
            ("QP", Some(n)) if SLIDER_PARAMS.contains(&(n as usize)) && n.fract() == 0.0 => {
                return Some(Self::SliderParam(n as usize));
            }
            _ => {}
        }
        let arrow = match word {
            "~~037X" => Some((Axis::Horizontal, -1.0)),
            "~~038X" => Some((Axis::Vertical, 1.0)),
            "~~039X" => Some((Axis::Horizontal, 1.0)),
            "~~040X" => Some((Axis::Vertical, -1.0)),
            _ => None,
        };
        if let Some((axis, distance)) = arrow {
            return Some(Self::Arrow(axis, distance));
        }
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
            "CN" => Self::Center,
            "PT" => Self::PointSize,
            "CT" => Self::CentreText,
            "CTN" => Self::CentreTextOnNote { skip_punctuation: false },
            "CTX" => Self::CentreTextOnNote { skip_punctuation: true },
            "JR" => Self::JustifyRight,
            "J" => Self::Justify,
            "ADJ" => Self::AdjustStems(StemFit { opposite: false, french: false }),
            "ADJX" | "ADX" => Self::AdjustStems(StemFit { opposite: true, french: false }),
            "ADF" => Self::AdjustStems(StemFit { opposite: false, french: true }),
            "ADFX" => Self::AdjustStems(StemFit { opposite: true, french: true }),
            "CH" => Self::ChordRhythm,
            "PST" => Self::Paste,
            "PGR" => Self::PageRight,
            _ => return None,
        };
        Some(parsed)
    }
}

/// Whether the editor knows the command of `line` in some context; menus
/// can grey out the entries it does not.
pub fn is_supported(line: &str) -> bool {
    if conditional::parse(line).is_some() {
        return true;
    }
    if let Some(entry) = text::quick_entry(line) {
        return entry.is_ok();
    }
    let tokens = parse::tokens(line);
    match tokens.first() {
        None => false,
        Some(Token::Word(w)) => {
            let word = w.to_ascii_uppercase();
            SessionWord::parse(&word).is_some()
                || GroupCommand::word(&word).is_some()
                || LayoutCommand::word(&word).is_some()
                || Order::word(&word).is_some()
                || Move::parse(&word, first_number(&tokens[1..])).is_some_and(Move::is_complete)
                || item::is_edit_word(&word)
                || create::template(&word).is_some()
                || drawn::centred_staves(&word, &numbers_after(&tokens)).is_some()
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

fn numbers_after(tokens: &[Token]) -> Vec<f32> {
    tokens.iter().skip(1).filter_map(Token::number).collect()
}

fn first_number(args: &[Token]) -> Option<f32> {
    args.first().and_then(Token::number)
}

/// An all-number line outside edit mode: the parameters of a new item.
fn plain_numbers(tokens: &[Token]) -> Option<Vec<f32>> {
    tokens.iter().map(Token::number).collect()
}

/// Codes an item can be typed in as numbers; 15 (EPS) and 16 (text) need a
/// file name or characters.
fn is_creatable_code(code: f32) -> bool {
    code.fract() == 0.0 && matches!(code as i32, 1..=14 | 17 | 18)
}

/// Item number `n` (1-based) clamped to the last item, as `I 99` edits the last one.
fn clamp_item(n: f32, len: usize) -> Option<usize> {
    (len > 0).then(|| (n.max(1.0) as usize).min(len) - 1)
}

impl Run<'_, '_> {
    /// Executes one command line.
    pub fn line(&mut self, line: &str) -> Result<(), EditError> {
        if self.session.pending.is_some() {
            return self.answer_group(line);
        }
        if let Some(statement) = conditional::parse(line) {
            self.session.clear();
            return self.conditional(&statement);
        }
        if let Some(entry) = text::quick_entry(line) {
            let (characters, rest) = entry?;
            self.session.clear();
            return self.enter_text(&characters, rest);
        }
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
            Some(SessionWord::Undelete | SessionWord::Paste | SessionWord::PageRight) => {
                Err(EditError::InEditMode(word))
            }
            Some(SessionWord::SliderParam(n)) => {
                self.session.slider_param = n;
                Ok(())
            }
            Some(SessionWord::Slider(step)) => {
                let n = self.session.slider_param;
                let op = step.map_or(ParamOp::Set { n, value: 0.0 }, |delta| ParamOp::Add { n, delta });
                self.change_params(&[op])
            }
            Some(SessionWord::Arrow(axis, distance)) => {
                self.rewrite_selected(|draft| moves::shift(draft, axis, distance));
                Ok(())
            }
            Some(SessionWord::DragEnd(end)) => {
                self.session.toggle_drag_end(end);
                Ok(())
            }
            Some(SessionWord::Center) => self.center(number),
            Some(SessionWord::SaveParam(n)) => self.save_param(n.or(number)),
            Some(SessionWord::RecallParam(n)) => self.recall_param(n.or(number)),
            Some(SessionWord::PointSize) => self.point_size(number),
            Some(SessionWord::CentreText) => self.centre_text(number),
            Some(SessionWord::CentreTextOnNote { skip_punctuation }) => {
                self.centre_text_on_note(&word, number, skip_punctuation)
            }
            Some(SessionWord::JustifyRight) => self.justify_right(number),
            Some(SessionWord::Justify) => self.justify(number, args.get(1).and_then(Token::number)),
            Some(SessionWord::AdjustStems(fit)) => self.adjust_stems(fit, number),
            Some(SessionWord::ChordRhythm) => self.chord_rhythm(number),
            None => self.edit_word(&word, args),
        }
    }

    fn outside_edit_mode(&mut self, tokens: &[Token]) -> Result<(), EditError> {
        if let Some(values) = plain_numbers(tokens) {
            let code = values.first().copied().unwrap_or(0.0);
            if !is_creatable_code(code) {
                return Err(EditError::NotForCode { command: "new item".into(), code: code as i32 });
            }
            return self.create_item(Draft::new(&values));
        }
        let (word, args) = word_and_args(tokens)?;
        let number = first_number(args);
        if let Some(command) = GroupCommand::word(&word) {
            return self.start_group(command, args);
        }
        if let Some(command) = LayoutCommand::word(&word) {
            return self.start_layout(command, args);
        }
        let numbers: Vec<f32> = args.iter().filter_map(Token::number).collect();
        if let Some(staff) = drawn::centred_staves(&word, &numbers) {
            self.centre_whole_rests(staff);
            return Ok(());
        }
        if let Some(order) = Order::word(&word) {
            return self.reorder(order);
        }
        match SessionWord::parse(&word) {
            Some(SessionWord::Leave) => self.leave(number),
            Some(SessionWord::Edit) => self.edit_item(number),
            Some(SessionWord::EditLast) => self.edit_last(),
            Some(SessionWord::Undelete) => self.undelete(),
            Some(SessionWord::Paste) => self.paste(),
            Some(SessionWord::PageRight) => self.page_right(),
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
            _ => match parse::split_count(word) {
                (stem, Some(n)) if NUMBERED_WORDS.contains(&stem) => self.rewrite(stem, Some(n)),
                _ => Err(EditError::UnknownCommand(word.to_owned())),
            },
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

    /// Parameter changes; the engine ignores a line that would leave the item
    /// without a valid code or staff.
    fn change_params(&mut self, ops: &[ParamOp]) -> Result<(), EditError> {
        self.rewrite_selected(|draft| {
            let mut changed = draft.clone();
            ops.iter().for_each(|op| op.apply(&mut changed));
            let code_ok = changed.code() == draft.code() || is_creatable_code(changed.get(1));
            let staff_ok = changed.get(2) == draft.get(2) || changed.get(2) > 0.0;
            if code_ok && staff_ok {
                *draft = changed;
            }
        });
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

    /// CN [staff]: the selected items moved to the P3 of the nearest note or
    /// rest on their staff (or on `staff`); a beam's ends each to their own nearest.
    fn center(&mut self, staff: Option<f32>) -> Result<(), EditError> {
        let targets: Vec<(ItemId, Draft)> = self
            .selection()
            .into_iter()
            .filter_map(|id| Some((id, Draft::of(self.tx.doc().item(id)?))))
            .collect();
        targets.into_iter().for_each(|(id, mut draft)| {
            let on = staff.unwrap_or(draft.get(2));
            let ends: &[usize] = match draft.code() {
                6 => &[3, 6],
                4 | 5 | 7 | 8 | 14 => &[],
                _ => &[3],
            };
            ends.iter().for_each(|&n| {
                if let Some(x) = self.nearest_note(on, draft.get(n)) {
                    draft.set(n, x);
                }
            });
            self.tx.replace(id, draft.to_item());
        });
        Ok(())
    }

    /// P3 of the note or rest on `staff` nearest to `p3` (the first of equals),
    /// selected items left out.
    pub fn nearest_note(&self, staff: f32, p3: f32) -> Option<f32> {
        let selected = self.session.selection();
        self.tx
            .doc()
            .entries()
            .filter(|(id, item)| matches!(item.code(), 1 | 2) && item.param(2) == staff && !selected.contains(id))
            .map(|(_, item)| item.param(3))
            .fold(None, |best: Option<f32>, x| match best {
                Some(b) if (b - p3).abs() <= (x - p3).abs() => Some(b),
                _ => Some(x),
            })
    }

    /// P1 of the first selected item, for error messages.
    pub fn first_selected_code(&self) -> i32 {
        self.selected_codes().first().copied().unwrap_or(0)
    }

    /// PSn: remembers Pn of the first selected item.
    fn save_param(&mut self, n: Option<f32>) -> Result<(), EditError> {
        let n = numeric::param_number(n.ok_or_else(|| EditError::BadArgument("PS".into()))?)?;
        let first = self.selection().first().and_then(|&id| self.tx.doc().item(id)).map(|item| item.param(n));
        if let Some(value) = first {
            self.session.save_param(n, value);
        }
        Ok(())
    }

    /// PG, PGn: sets the remembered parameter on the selection.
    fn recall_param(&mut self, n: Option<f32>) -> Result<(), EditError> {
        let wanted = n.map(numeric::param_number).transpose()?;
        let Some((n, value)) = self.session.saved_param(wanted) else { return Ok(()) };
        self.rewrite_selected(|draft| draft.set(n, value));
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

    /// C, CC, CX: an edited item becomes a copy and the original returns;
    /// an item left unchanged is not copied.
    fn copy(&mut self, mode: CopyMode) -> Result<(), EditError> {
        let originals = self.selection();
        let copies: Vec<ItemId> = originals
            .iter()
            .filter_map(|&id| {
                let edited = self.tx.doc().item(id)?.clone();
                let original = self.session.original(id).cloned().filter(|o| *o != edited)?;
                let copy = self.tx.append(edited);
                self.tx.replace(id, original);
                Some(copy)
            })
            .collect();
        let doc = self.tx.doc();
        let after_original = originals.last().and_then(|&id| doc.index_of(id)).and_then(|i| doc.id_at(i + 1));
        let next: Vec<ItemId> = match mode {
            CopyMode::Exit => Vec::new(),
            CopyMode::Continue if copies.is_empty() => originals.clone(),
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
