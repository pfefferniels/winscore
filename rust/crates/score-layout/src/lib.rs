//! SCORE's layout commands on an item list: LI lines up the notes of a system, spacing
//! them by duration across all its staves. J (justify) and LJ (both) follow.
//!
//! This is a reimplementation of WinScore's routines 0x4B80B7 (the command's main pass),
//! 0x4F7808 (sort), 0x534C40 (events), 0x4C9510 (merge), 0x4CC470 (spacing) and 0x4C8290
//! (mapping), after disasm-expert's reference model `analysis/engine/experiments/lineup.py`
//! and its notes in `analysis/engine/layout.md`. Results are compared with the engine
//! item by item (`tests/engine.rs`).
//!
//! The engine sorts the whole file before it lines up, so the result is a reordered list:
//! [`Layout::source`] tells which input item each output item is.

mod events;
mod lineup;
mod merge;
mod num;
mod prepare;
mod rows;
mod sort;
mod spacing;

use std::fmt;

use score_format::Item;

use crate::lineup::Lineup;
use crate::prepare::{prepare, staff_steps};
use crate::rows::{Row, REST};

/// The system a layout command works on: staves `first..=last`, as answered to the
/// engine's question "Enter Lowest Staff# of system and how many staves".
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct StaffRange {
    pub first: i32,
    pub last: i32,
}

impl StaffRange {
    /// The answer "lowest count": `lowest` and the `count - 1` staves above it.
    pub fn from_answer(lowest: i32, count: i32) -> Self {
        StaffRange { first: lowest, last: lowest + count.max(1) - 1 }
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Options {
    /// The right limit of the line (P3 units).
    pub right: f32,
    /// The x range of the source box; answering with staff numbers gives the whole width.
    pub source_box: (f32, f32),
}

impl Default for Options {
    fn default() -> Self {
        Options { right: 200.0, source_box: (0.0, 200.0) }
    }
}

/// The items after a layout command, in their new order.
#[derive(Debug, Clone, PartialEq)]
pub struct Layout {
    pub items: Vec<Item>,
    /// `source[i]` is the index in the input of `items[i]`; a permutation, since items
    /// are neither created nor removed.
    pub source: Vec<usize>,
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum LayoutErrorKind {
    /// The staves of the system do not last equally long (the engine's message "Staff n
    /// has x beats").
    UnequalStaves { staff: i32, beats: f32, before: f32 },
    /// No staff of the system has notes or rests.
    NoNotes,
    /// A staff's rhythm cannot be matched with the others'.
    Unalignable { staff: i32 },
    /// A P4 of 900 or more, which makes the engine's sort repeat items.
    P4TooLarge,
    /// Notes or rests with P7 >= 64 (the engine hands them to 0x4C5AD8, not ported yet).
    LongValues,
    /// One of the engine's loops would not end.
    NoEnd,
}

impl fmt::Display for LayoutErrorKind {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            LayoutErrorKind::UnequalStaves { staff, beats, before } => {
                write!(f, "staff {staff} has {beats:.3} beats, the staff before {before:.3}")
            }
            LayoutErrorKind::NoNotes => write!(f, "no staff of the system has notes"),
            LayoutErrorKind::Unalignable { staff } => write!(f, "the rhythm of staff {staff} cannot be aligned"),
            LayoutErrorKind::P4TooLarge => write!(f, "an item has P4 >= 900"),
            LayoutErrorKind::LongValues => write!(f, "values with P7 >= 64 are not supported yet"),
            LayoutErrorKind::NoEnd => write!(f, "the layout does not terminate"),
        }
    }
}

/// A layout command the engine gave up on. `layout` holds the items as the engine leaves
/// them: sorted, and possibly partly moved.
#[derive(Debug, Clone, PartialEq)]
pub struct LayoutError {
    pub kind: LayoutErrorKind,
    pub layout: Layout,
}

impl fmt::Display for LayoutError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        self.kind.fmt(f)
    }
}

impl std::error::Error for LayoutError {}

/// LI: lines up the system `range`, as the engine does after the answer and "yes" to
/// "Source Box O.K.?".
pub fn line_up(items: &[Item], range: StaffRange, options: &Options) -> Result<Layout, LayoutError> {
    let mut rows: Vec<Row> = items.iter().enumerate().map(|(i, item)| Row::of(item, i)).collect();
    let outcome = line_up_rows(&mut rows, range, options);
    let layout = Layout {
        items: rows.iter().map(|row| row.to_item(&items[row.source])).collect(),
        source: rows.iter().map(|row| row.source).collect(),
    };
    match outcome {
        Ok(()) => Ok(layout),
        Err(kind) => Err(LayoutError { kind, layout }),
    }
}

fn line_up_rows(rows: &mut [Row], range: StaffRange, options: &Options) -> Result<(), LayoutErrorKind> {
    let StaffRange { first: lo, last: hi } = range;
    let Some(hi) = prepare(rows, lo, hi, options.right, options.source_box)? else {
        return Ok(());
    };
    let steps = staff_steps(rows);
    let mut lineup = Lineup::new(rows, lo, hi, options.right, steps);
    lineup.run()?;
    let x_left = lineup.x_left;
    mark_whole_rests_for_centring(rows, lo, hi, x_left, options.source_box.1);
    Ok(())
}

/// Whole-measure rests in the lined-up area get P9 = -1, so they are centred in their
/// measures when drawn.
fn mark_whole_rests_for_centring(rows: &mut [Row], lo: i32, hi: i32, x_left: f32, box_right: f32) {
    for row in rows.iter_mut() {
        if (lo..=hi).contains(&row.staff()) && row.code() == REST && row.par(5) <= -2.0 && x_left <= row.x() && row.x() <= box_right {
            row.set(9, -1.0);
        }
    }
}
