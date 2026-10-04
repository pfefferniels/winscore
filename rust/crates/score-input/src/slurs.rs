//! Pass 5: slurs and ties as code-5 items.
//!
//! Slur routine of the engine: 0x53D1E0. A connection between two neighbouring notes on the
//! same level, or two neighbouring chords with the same levels, is a tie (one per head);
//! anything else a slur.

use crate::connect::{ConnectEntry, Connection, Side};
use crate::error::InputError;
use crate::line::{item, Line, Note};

/// P8 of the slur item.
const AUTOMATIC_SLUR: f32 = -1.0;
const TIE: f32 = -2.0;
const FORCED_ABOVE: f32 = -4.0;
const FORCED_BELOW: f32 = 0.0;

/// Lines of the five-line staff, as levels.
fn on_staff_line(level: f32) -> bool {
    level.fract() == 0.0 && (3.0..=11.0).contains(&level) && (level as i32) % 2 == 1
}

/// A slur end next to a note head: two steps away, one more if that is a staff line.
fn head_side(level: i32, above: bool) -> f32 {
    let step = if above { 1.0 } else { -1.0 };
    let end = level as f32 + 2.0 * step;
    if on_staff_line(end) {
        end + step
    } else {
        end
    }
}

/// Curvature (P7) in steps: grows with length and with the difference of the end levels.
fn curvature(length: f32, rise: f32, tie: bool) -> f32 {
    let base = if tie { 0.7 } else { 0.9 + 0.1 * rise.abs() };
    0.05 * length + base
}

fn is_tie(a: &Note, b: &Note) -> bool {
    a.heads.len() == b.heads.len() && a.heads.iter().zip(&b.heads).all(|(p, q)| p.level == q.level)
}

fn ties(a: &Note, b: &Note, staff: f32) -> Vec<score_format::Item> {
    let length = b.x - a.x;
    let count = a.heads.len();
    a.heads
        .iter()
        .enumerate()
        .map(|(i, head)| {
            let above = if count == 1 { a.down } else { 2 * i >= count };
            let offset = match (count, above) {
                (1, true) => 0.5,
                (_, true) => 1.2,
                (_, false) => -1.2,
            };
            let level = head.level as f32 + offset;
            let bend = curvature(length, 0.0, true);
            item(&[5.0, staff, a.x, level, level, b.x, if above { bend } else { -bend }, TIE])
        })
        .collect()
}

fn slur(a: &Note, b: &Note, side: Option<Side>, staff: f32) -> score_format::Item {
    let above = match side {
        Some(Side::Above) => true,
        Some(Side::Below) => false,
        None => a.down || b.down,
    };
    let end = |note: &Note| {
        let head = if above { note.highest() } else { note.lowest() };
        head_side(head, above)
    };
    let (y1, y2) = (end(a), end(b));
    let bend = curvature(b.x - a.x, y2 - y1, false);
    let kind = match side {
        Some(Side::Above) => FORCED_ABOVE,
        Some(Side::Below) => FORCED_BELOW,
        None => AUTOMATIC_SLUR,
    };
    item(&[5.0, staff, a.x, y1, y2, b.x, if above { bend } else { -bend }, kind])
}

pub(crate) fn apply(line: &mut Line, entries: &[ConnectEntry]) -> Result<(), InputError> {
    let made: Vec<score_format::Item> = entries
        .iter()
        .filter_map(|entry| match *entry {
            ConnectEntry::Pair(c) => Some(c),
            ConnectEntry::EveryEighths { .. } => None,
        })
        .flat_map(|Connection { first, last, side, .. }| match (line.note(first), line.note(last)) {
            (Some(a), Some(b)) if last == first + 1 && side.is_none() && is_tie(a, b) => ties(a, b, line.staff),
            (Some(a), Some(b)) if first < last => vec![slur(a, b, side, line.staff)],
            _ => Vec::new(),
        })
        .collect();
    line.attachments.extend(made);
    Ok(())
}
