//! Running group edits: the dialogue of area, destination or changes, then
//! the change to every item of the area as one undo step.

use score_format::Item;
use score_layout::{self as layout, Options, StaffRange};
use score_render::page::{page_offset, P3_UNIT};

use crate::command::moves::{shift, Axis};
use crate::command::numeric;
use crate::command::parse::{self, Token};
use crate::command::Run;
use crate::conditional::Statement;
use crate::document::ItemId;
use crate::error::EditError;
use crate::group::{Destination, GroupCommand, LayoutCommand, Order, Pending, Region, FIXED_BY_MUD, NARROW_BOX};
use crate::params::Draft;
use crate::session::Deleted;
use crate::transpose::{self, Transposition};

/// Staff numbers of the recto page start above this; PGR adds this many.
const RECTO_FROM: f32 = 200.0;
const RECTO_STAVES: f32 = 200.0;

impl Run<'_, '_> {
    /// Starts a group command; numbers typed after the word give the area at once.
    pub fn start_group(&mut self, command: GroupCommand, args: &[Token]) -> Result<(), EditError> {
        let numbers: Vec<f32> = args.iter().filter_map(Token::number).collect();
        if command == GroupCommand::Transpose && !numbers.is_empty() {
            return match Transposition::typed(&numbers) {
                Some((region, how)) => self.transpose(&region, &how),
                None => Ok(()),
            };
        }
        self.session.pending = Some(Pending::Area(command));
        if numbers.is_empty() {
            Ok(())
        } else {
            self.answer_numbers(&numbers)
        }
    }

    /// Starts a layout command; `lowest count` typed after the word answer it at once.
    pub fn start_layout(&mut self, command: LayoutCommand, args: &[Token]) -> Result<(), EditError> {
        let LayoutCommand::System(command) = command else {
            self.lay_out_all();
            return Ok(());
        };
        self.session.pending = Some(Pending::System(command));
        let numbers: Vec<f32> = args.iter().filter_map(Token::number).collect();
        if numbers.is_empty() {
            Ok(())
        } else {
            self.answer_numbers(&numbers)
        }
    }

    /// Runs a layout command on the system `range`.
    pub fn lay_out(&mut self, command: layout::Command, range: StaffRange, options: &Options) {
        let outcome = layout::layout(&self.tx.doc().file().items, command, range, options);
        self.take_layout(outcome);
    }

    /// LJA: LJ on all staves with notes or rests.
    pub fn lay_out_all(&mut self) {
        let outcome = layout::line_up_and_justify_all(&self.tx.doc().file().items, &Options::default());
        self.take_layout(outcome);
    }

    /// Makes the file what a layout command left. When the engine gives up
    /// midway, the items stay as it leaves them and its message is reported.
    fn take_layout(&mut self, outcome: Result<layout::Layout, layout::LayoutError>) {
        let (layout, failure) = match outcome {
            Ok(layout) => (layout, None),
            Err(error) => (error.layout, Some(error.kind)),
        };
        self.rearrange(layout.source.into_iter().map(Some).zip(layout.items).collect());
        self.session.message = failure.map(|kind| format!("*** ERROR: {kind}"));
        self.session.clear();
    }

    /// A line typed while a group command waits: numbers answer it, anything
    /// else ends the group edit without a change.
    pub fn answer_group(&mut self, line: &str) -> Result<(), EditError> {
        if let Some(Pending::Transposition(region)) = &self.session.pending {
            let region = region.clone();
            self.session.pending = None;
            let how = Transposition::parse(line).ok_or_else(|| EditError::BadArgument(format!("TR values {line:?}")))?;
            return self.transpose(&region, &how);
        }
        let tokens = parse::tokens(line);
        let numbers: Option<Vec<f32>> = tokens.iter().map(Token::number).collect();
        match (self.session.pending.take(), numbers) {
            (Some(Pending::AlterPairs { region, code }), _) if !tokens.is_empty() => self.alter(&region, code, &tokens),
            (pending, Some(numbers)) if !numbers.is_empty() => {
                self.session.pending = pending;
                self.answer_numbers(&numbers)
            }
            _ => Ok(()),
        }
    }

    fn answer_numbers(&mut self, numbers: &[f32]) -> Result<(), EditError> {
        let Some(pending) = self.session.pending.take() else { return Ok(()) };
        let region = |numbers: &[f32]| Region::parse(numbers).ok_or_else(|| EditError::BadArgument("area".into()));
        match pending {
            Pending::Area(GroupCommand::Delete) => self.delete_region(&region(numbers)?),
            Pending::Area(GroupCommand::Move) => self.wait(Pending::Destination { region: region(numbers)?, copy: false }),
            Pending::Area(GroupCommand::Copy) => self.wait(Pending::Destination { region: region(numbers)?, copy: true }),
            Pending::Area(GroupCommand::Alter) => self.wait(Pending::AlterCode(region(numbers)?)),
            Pending::Area(GroupCommand::MoveUpDown) => self.wait(Pending::Steps(region(numbers)?)),
            Pending::Area(GroupCommand::CopyToStaves) => self.wait(Pending::Staves(region(numbers)?)),
            Pending::Area(GroupCommand::Transpose) => self.wait(Pending::Transposition(region(numbers)?)),
            Pending::Area(GroupCommand::Refit(mode)) => {
                self.refit(&region(numbers)?, mode);
                Ok(())
            }
            Pending::Transposition(_) => Ok(()),
            Pending::System(command) => {
                let range = StaffRange::from_answer(numbers[0] as i32, numbers.get(1).map_or(0, |&n| n as i32));
                self.lay_out(command, range, &Options::default());
                Ok(())
            }
            Pending::Destination { region, copy } => {
                let destination = Destination::parse(numbers).ok_or_else(|| EditError::BadArgument("destination".into()))?;
                self.move_region(&region, &destination, copy)
            }
            Pending::AlterCode(region) => self.wait(Pending::AlterPairs { region, code: numbers[0] as i32 }),
            Pending::AlterPairs { .. } => Ok(()),
            Pending::Steps(region) => self.move_region_up(&region, numbers[0]),
            Pending::Staves(region) => self.copy_to_staves(&region, numbers),
        }
    }

    /// A box drawn on the page: it answers a group command waiting for its
    /// area or destination, and otherwise selects what it holds. As a
    /// destination, a click keeps the area's place on the clicked staff, a
    /// thin line moves the area's left edge to the line, a box rescales it.
    pub fn draw_box(&mut self, corner: (f64, f64), other: (f64, f64)) -> Result<(), EditError> {
        let drawn = Region::from_page_box(self.tx.doc().file(), corner, other);
        match self.session.pending.clone() {
            Some(Pending::Area(_)) => self.answer_numbers(&[drawn.bottom, drawn.left, drawn.right, drawn.top]),
            Some(Pending::System(command)) => {
                self.session.pending = None;
                let range = StaffRange { first: drawn.bottom as i32, last: drawn.top as i32 };
                let options = Options { source_box: (drawn.left, drawn.right), ..Options::default() };
                self.lay_out(command, range, &options);
                Ok(())
            }
            Some(Pending::Destination { region, .. }) => {
                let narrow = (corner.0 - other.0).abs() < NARROW_BOX;
                let answer = if narrow && corner.1 == other.1 {
                    vec![drawn.bottom]
                } else if narrow {
                    let line = ((corner.0.min(other.0) - f64::from(page_offset(1).x)) / P3_UNIT) as f32;
                    vec![drawn.bottom, line - region.left]
                } else {
                    vec![drawn.bottom, drawn.left, drawn.right]
                };
                self.answer_numbers(&answer)
            }
            _ => {
                self.select_region(&drawn);
                Ok(())
            }
        }
    }

    fn wait(&mut self, pending: Pending) -> Result<(), EditError> {
        self.session.pending = Some(pending);
        Ok(())
    }

    /// Items in `region`, in file order.
    fn in_region(&self, region: &Region) -> Vec<(ItemId, Draft)> {
        self.tx
            .doc()
            .entries()
            .map(|(id, item)| (id, Draft::of(item)))
            .filter(|(_, draft)| region.contains(draft))
            .collect()
    }

    /// Selects every item of `region` (a box drawn in the browser).
    pub fn select_region(&mut self, region: &Region) {
        let ids: Vec<ItemId> = self.in_region(region).into_iter().map(|(id, _)| id).collect();
        self.session.select(self.tx.doc(), &ids);
    }

    fn delete_region(&mut self, region: &Region) -> Result<(), EditError> {
        let removed: Vec<Deleted> = self
            .in_region(region)
            .into_iter()
            .filter_map(|(id, _)| self.tx.remove(id).map(|(index, item)| Deleted { index, id, item }))
            .collect();
        self.session.remember_deleted(removed);
        self.session.clear();
        Ok(())
    }

    fn move_region(&mut self, region: &Region, destination: &Destination, copy: bool) -> Result<(), EditError> {
        self.in_region(region).into_iter().for_each(|(id, draft)| {
            let moved = destination.moved(region, &draft).to_item();
            if copy {
                self.tx.append(moved);
            } else {
                self.tx.replace(id, moved);
            }
        });
        self.session.clear();
        Ok(())
    }

    /// A: the items of one code in the area get the typed parameter changes
    /// (pairs and `p00 change`; the engine stops at a `/p` form).
    fn alter(&mut self, region: &Region, code: i32, tokens: &[Token]) -> Result<(), EditError> {
        let numbers: Vec<Token> = tokens.iter().take_while(|t| matches!(t, Token::Number(_))).cloned().collect();
        let ops = numeric::param_ops(&numbers).unwrap_or(Ok(Vec::new()))?;
        self.in_region(region).into_iter().filter(|(_, d)| d.code() == code).for_each(|(id, mut draft)| {
            ops.iter().for_each(|op| op.apply(&mut draft));
            self.tx.replace(id, draft.to_item());
        });
        self.session.clear();
        Ok(())
    }

    /// MUD: everything in the area but staves, clefs, barlines, keys and meters, `steps` up.
    fn move_region_up(&mut self, region: &Region, steps: f32) -> Result<(), EditError> {
        self.in_region(region).into_iter().filter(|(_, d)| !FIXED_BY_MUD.contains(&d.code())).for_each(|(id, mut draft)| {
            shift(&mut draft, Axis::Vertical, f64::from(steps));
            self.tx.replace(id, draft.to_item());
        });
        self.session.clear();
        Ok(())
    }

    /// CPX: copies of the area on each of `staves`, staff by staff.
    fn copy_to_staves(&mut self, region: &Region, staves: &[f32]) -> Result<(), EditError> {
        let items = self.in_region(region);
        staves.iter().for_each(|&staff| {
            items.iter().for_each(|(_, draft)| {
                let mut copy = draft.clone();
                copy.add(2, staff - region.bottom);
                self.tx.append(copy.to_item());
            });
        });
        self.session.clear();
        Ok(())
    }

    /// IF … THEN …: every item for which the condition holds is changed,
    /// deleted (UND brings them back) or cut for pasting.
    pub fn conditional(&mut self, statement: &Statement) -> Result<(), EditError> {
        let matching: Vec<(ItemId, Draft)> = self
            .tx
            .doc()
            .entries()
            .map(|(id, item)| (id, Draft::of(item)))
            .filter(|(_, draft)| statement.condition.holds(draft))
            .collect();
        if statement.cuts() {
            self.session.clipboard = matching.iter().map(|(_, d)| d.to_item()).collect();
        }
        if statement.deletes() {
            let removed: Vec<Deleted> = matching
                .into_iter()
                .filter_map(|(id, _)| self.tx.remove(id).map(|(index, item)| Deleted { index, id, item }))
                .collect();
            self.session.remember_deleted(removed);
            return Ok(());
        }
        matching.into_iter().for_each(|(id, mut draft)| {
            statement.apply(&mut draft);
            self.tx.replace(id, draft.to_item());
        });
        Ok(())
    }

    /// PGR: every item 200 staves up to the recto page, or back from it if
    /// anything is there already.
    pub fn page_right(&mut self) -> Result<(), EditError> {
        let entries: Vec<(ItemId, Draft)> =
            self.tx.doc().entries().map(|(id, item)| (id, Draft::of(item))).collect();
        let on_recto = entries.iter().any(|(_, d)| d.get(2) > RECTO_FROM);
        entries.into_iter().for_each(|(id, mut draft)| {
            let change = match (on_recto, draft.get(2) > RECTO_FROM) {
                (false, _) => RECTO_STAVES,
                (true, true) => -RECTO_STAVES,
                (true, false) => return,
            };
            draft.add(2, change);
            self.tx.replace(id, draft.to_item());
        });
        self.session.clear();
        Ok(())
    }

    /// PST: the items cut last, added again and selected.
    pub fn paste(&mut self) -> Result<(), EditError> {
        let items = self.session.clipboard.clone();
        self.append_items(items)
    }

    /// OS, OH, OT: the items put in a new order, ids kept.
    pub fn reorder(&mut self, order: Order) -> Result<(), EditError> {
        let mut wanted: Vec<(usize, Draft)> = self.tx.doc().entries().map(|(_, item)| Draft::of(item)).enumerate().collect();
        wanted.sort_by(|(_, a), (_, b)| order.compare(a, b));
        let items = self.tx.doc().file().items.clone();
        self.rearrange(wanted.into_iter().map(|(i, _)| (Some(i), items[i].clone())).collect());
        Ok(())
    }

    /// FLI/FLN/FLU/FLD on `region` (0x494302): the file sorted, then each
    /// staff's notes refitted (score-input); staves the engine gives up on
    /// stay as it leaves them and are reported.
    fn refit(&mut self, region: &Region, mode: score_input::RefitMode) {
        let items = &self.tx.doc().file().items;
        let sorted = layout::sort(items).unwrap_or_else(|error| error.layout);
        let staves = (region.bottom as i32, region.top as i32);
        let outcome = score_input::refit_staves(&sorted.items, staves, (region.left, region.right), mode);
        self.rearrange(sorted.source.into_iter().map(Some).zip(outcome.items).collect());
        let problems: Vec<String> = outcome.problems.iter().map(|(staff, kind)| format!("staff {staff}: {kind}")).collect();
        self.session.message = (!problems.is_empty()).then(|| problems.join("; "));
        self.session.clear();
    }

    /// TR on `region` with the dialog's values `how`, as one change of the file.
    pub fn transpose(&mut self, region: &Region, how: &Transposition) -> Result<(), EditError> {
        let arranged = transpose::transpose(&self.tx.doc().file().items, region, how, self.session.transposition)
            .map_err(|unsupported| EditError::NotImplemented(format!("TR: {unsupported}")))?;
        self.session.transposition = arranged.leftover;
        self.rearrange(arranged.source.into_iter().zip(arranged.items).collect());
        self.session.clear();
        Ok(())
    }

    /// Makes the file `wanted`: each entry the index of an item now in the
    /// file (`None` for a new one) and what it becomes; items not named go.
    fn rearrange(&mut self, wanted: Vec<(Option<usize>, Item)>) {
        let ids: Vec<ItemId> = self.tx.doc().ids().to_vec();
        let kept: Vec<usize> = wanted.iter().filter_map(|(source, _)| *source).collect();
        ids.iter().enumerate().filter(|(i, _)| !kept.contains(i)).for_each(|(_, &id)| {
            self.tx.remove(id);
        });
        wanted.into_iter().enumerate().for_each(|(index, (source, item))| match source.map(|i| ids[i]) {
            None => {
                self.tx.insert(index, item);
            }
            Some(id) => {
                if self.tx.doc().item(id) != Some(&item) {
                    self.tx.replace(id, item);
                }
                if self.tx.doc().id_at(index) != Some(id) {
                    if let Some((_, item)) = self.tx.remove(id) {
                        self.tx.restore(index, id, item);
                    }
                }
            }
        });
    }
}
