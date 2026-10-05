//! Comparison of `score_layout` with the engine for fixtures that ran a layout command:
//! `input.mus` laid out by the port against the engine's `result.mus`, item by item.

use std::fs;
use std::path::Path;

use score_format::{Item, MusFile};
use score_layout::{layout, line_up_and_justify_all, Command, Options, StaffRange};

use crate::fixture::Fixture;

/// Parameters agree when they differ by at most this much (as in score-layout's own tests).
pub const PARAM_TOLERANCE: f32 = 1e-4;

/// A layout command as a fixture ran it.
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum LayoutRun {
    /// LI, J or LJ, answered with "lowest count".
    System(Command, StaffRange),
    /// LJA, which answers its own question.
    All,
}

impl LayoutRun {
    /// The first layout command among the fixture's commands, with its answer.
    pub fn of(commands: &[&str]) -> Option<LayoutRun> {
        let position = commands
            .iter()
            .position(|c| matches!(word(c), "LI" | "LJ" | "J" | "LJA"))?;
        let command = match word(commands[position]) {
            "LJA" => return Some(LayoutRun::All),
            "LI" => Command::LineUp,
            "J" => Command::Justify,
            _ => Command::LineUpAndJustify,
        };
        let answer: Vec<i32> = commands
            .get(position + 1)?
            .split_whitespace()
            .map(|n| n.parse().ok())
            .collect::<Option<_>>()?;
        match answer.as_slice() {
            [lowest, count] => Some(LayoutRun::System(
                command,
                StaffRange::from_answer(*lowest, *count),
            )),
            _ => None,
        }
    }

    fn apply(self, items: &[Item]) -> Vec<Item> {
        let options = Options::default();
        let outcome = match self {
            LayoutRun::System(command, range) => layout(items, command, range, &options),
            LayoutRun::All => line_up_and_justify_all(items, &options),
        };
        outcome.unwrap_or_else(|error| error.layout).items
    }
}

fn word(command: &str) -> &str {
    command.split_whitespace().next().unwrap_or("")
}

/// One item where the port's layout and the engine's differ.
#[derive(Debug, Clone, PartialEq)]
pub struct LayoutDifference {
    /// 0-based index in the engine's result.
    pub item: usize,
    /// P1 of the engine's item.
    pub code: i32,
    pub detail: String,
}

fn params(item: &Item) -> Vec<f32> {
    item.params().iter().map(|w| w.as_f32()).collect()
}

/// P9 of a rest: -1 asks for centring between the barlines (CW).
const CENTRE_PARAM: usize = 9;
const CENTRE_REQUEST: f32 = -1.0;

/// The engine's result.mus is saved after the redraw that follows the command, and drawing
/// a rest with P9 = -1 writes the centred position back into P9 (impl-notes' CW deviation).
fn centred_by_redraw(code: i32, k: usize, ours: f32, engine: f32) -> bool {
    code == 2 && k + 1 == CENTRE_PARAM && ours == CENTRE_REQUEST && engine > 0.0
}

fn first_differing_param(code: i32, ours: &[f32], engine: &[f32]) -> Option<usize> {
    let get = |v: &[f32], k: usize| v.get(k).copied().unwrap_or(0.0);
    (0..ours.len().max(engine.len())).find(|&k| {
        let (a, b) = (get(ours, k), get(engine, k));
        (a - b).abs() > PARAM_TOLERANCE && !centred_by_redraw(code, k, a, b)
    })
}

fn read(path: &Path) -> Option<MusFile> {
    MusFile::parse(&fs::read(path).ok()?).ok()
}

/// None when the fixture ran no layout command; otherwise the differing items (empty when all agree).
pub fn compare_layout(fixture: &Fixture) -> Option<Vec<LayoutDifference>> {
    let commands: Vec<&str> = fixture
        .meta
        .commands
        .iter()
        .map(|c| c.command.as_str())
        .collect();
    let run = LayoutRun::of(&commands)?;
    let input = read(&fixture.input_path())?;
    let engine = read(&fixture.dir.join("result.mus"))?;
    let ours = run.apply(&input.items);
    if ours.len() != engine.items.len() {
        let detail = format!(
            "{} items instead of the engine's {}",
            ours.len(),
            engine.items.len()
        );
        return Some(vec![LayoutDifference {
            item: 0,
            code: 0,
            detail,
        }]);
    }
    let differences = ours
        .iter()
        .zip(&engine.items)
        .enumerate()
        .filter_map(|(i, (a, b))| {
            let (pa, pb) = (params(a), params(b));
            first_differing_param(b.code(), &pa, &pb).map(|k| LayoutDifference {
                item: i,
                code: b.code(),
                detail: format!(
                    "item {i} P{}: ours {} engine {} (ours {:?}, engine {:?})",
                    k + 1,
                    pa.get(k).copied().unwrap_or(0.0),
                    pb.get(k).copied().unwrap_or(0.0),
                    pa,
                    pb
                ),
            })
        })
        .collect();
    Some(differences)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn reads_the_command_and_its_answer() {
        assert_eq!(
            LayoutRun::of(&["G case.mus", "LJ", "1 2"]),
            Some(LayoutRun::System(
                Command::LineUpAndJustify,
                StaffRange::from_answer(1, 2)
            ))
        );
        assert_eq!(
            LayoutRun::of(&["G case.mus", "LI", "2 3"]),
            Some(LayoutRun::System(
                Command::LineUp,
                StaffRange::from_answer(2, 3)
            ))
        );
        assert_eq!(LayoutRun::of(&["G case.mus", "LJA"]), Some(LayoutRun::All));
        assert_eq!(LayoutRun::of(&["G case.mus"]), None);
        assert_eq!(LayoutRun::of(&["G case.mus", "LJ"]), None);
    }
}
