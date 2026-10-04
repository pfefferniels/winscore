//! Running group edits: the dialogue of area, destination or changes, then
//! the change to every item of the area as one undo step.

use crate::command::moves::{shift, Axis};
use crate::command::numeric;
use crate::command::parse::{self, Token};
use crate::command::Run;
use crate::conditional::Statement;
use crate::document::ItemId;
use crate::error::EditError;
use crate::group::{Destination, GroupCommand, Order, Pending, Region, FIXED_BY_MUD};
use crate::params::Draft;
use crate::session::Deleted;

impl Run<'_, '_> {
    /// Starts a group command; numbers typed after the word give the area at once.
    pub fn start_group(&mut self, command: GroupCommand, args: &[Token]) -> Result<(), EditError> {
        self.session.pending = Some(Pending::Area(command));
        if args.is_empty() {
            Ok(())
        } else {
            self.answer_numbers(&args.iter().filter_map(Token::number).collect::<Vec<_>>())
        }
    }

    /// A line typed while a group command waits: numbers answer it, anything
    /// else ends the group edit without a change.
    pub fn answer_group(&mut self, line: &str) -> Result<(), EditError> {
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

    /// PST: the items cut last, added again and selected.
    pub fn paste(&mut self) -> Result<(), EditError> {
        let items = self.session.clipboard.clone();
        self.append_items(items)
    }

    /// OS, OH, OT: the items put in a new order, ids kept.
    pub fn reorder(&mut self, order: Order) -> Result<(), EditError> {
        let mut wanted: Vec<(ItemId, Draft)> = self.tx.doc().entries().map(|(id, item)| (id, Draft::of(item))).collect();
        wanted.sort_by(|(_, a), (_, b)| order.compare(a, b));
        wanted.into_iter().enumerate().for_each(|(index, (id, _))| {
            if self.tx.doc().id_at(index) != Some(id) {
                if let Some((_, item)) = self.tx.remove(id) {
                    self.tx.restore(index, id, item);
                }
            }
        });
        Ok(())
    }
}
