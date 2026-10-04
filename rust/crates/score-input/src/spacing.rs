//! Horizontal positions (P3) of the items of an input line.
//!
//! Rhythmic items share the input range in proportion to their durations; clefs, key
//! signatures, meters, barlines and grace notes take fixed widths.

use crate::notes::{KeySignature, Meter};

/// What the spacing needs to know about one event of the line.
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Slot {
    /// A note, chord or rest lasting this many quarter notes.
    Timed(f32),
    Grace,
    Bar,
    Clef { first: bool },
    Key(KeySignature),
    Meter(Meter),
    /// Takes no space (stem and staff switches).
    None,
}

const GRACE_WIDTH: f32 = 9.0;
const BAR_GAP: f32 = 3.5;
const FIRST_CLEF_WIDTH: f32 = 9.0;
const CLEF_WIDTH: f32 = 7.0;

impl Slot {
    fn width(self, last: bool) -> f32 {
        match self {
            Slot::Timed(_) | Slot::None => 0.0,
            Slot::Grace => GRACE_WIDTH,
            Slot::Bar if last => 0.0,
            Slot::Bar => BAR_GAP,
            Slot::Clef { first: true } => FIRST_CLEF_WIDTH,
            Slot::Clef { first: false } => CLEF_WIDTH,
            Slot::Key(key) => 2.0 + 2.8 * f32::from(key.count),
            Slot::Meter(Meter::Fraction(top, bottom)) if top < 10 && bottom < 10 => 7.0,
            Slot::Meter(_) => 9.0,
        }
    }

    fn duration(self) -> f32 {
        match self {
            Slot::Timed(quarters) => quarters,
            _ => 0.0,
        }
    }
}

/// P3 of every slot for the input range `begin..end`.
pub fn positions(slots: &[Slot], begin: f32, end: f32) -> Vec<f32> {
    let last = slots.len().saturating_sub(1);
    let fixed: f32 = slots.iter().enumerate().map(|(i, s)| s.width(i == last)).sum();
    let total: f32 = slots.iter().map(|s| s.duration()).sum();
    let per_quarter = if total > 0.0 { (end - begin - fixed) / total } else { 0.0 };
    slots
        .iter()
        .enumerate()
        .scan(begin, |x, (i, slot)| {
            let here = *x;
            *x += slot.width(i == last) + slot.duration() * per_quarter;
            Some(here)
        })
        .collect()
}
