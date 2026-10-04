//! The staff table: where each staff number sits (draw_staff 0x545140).
//!
//! Every item hangs on a staff (its P2) and is placed through that staff's
//! table entry: the level of P4 = 0 and the step unit. A staff number without
//! a code-8 item keeps its default entry, a size-1 staff on the default grid.
//! Neighbouring staff numbers are 3150 units (18 scale steps at size 1)
//! apart whatever their sizes; staves above 199 lie on the recto page and
//! repeat the grid from staff 0 on.

use std::collections::BTreeMap;

use crate::display::{ItemId, UNITS_PER_INCH};
use crate::document::ItemRef;
use crate::page::{is_recto, LAST_VERSO_STAFF};
use crate::units::{real, trunc};

/// The engine's step unit at size 1; one scale step is 7 of them.
pub const STEP_UNIT: f64 = 25.0;

/// Step units per scale step (half a staff space).
pub const UNITS_PER_SCALE_STEP: f64 = 7.0;

/// Default distance between neighbouring staves.
pub const STAFF_SPACING: i32 = 3150;

/// Scale steps from the P4 = 0 level up to the bottom line of a five-line staff.
const BOTTOM_LINE_STEPS: f64 = 3.0;

/// Height of a size-1 staff in centimetres, for code 8's P14.
const NORMAL_STAFF_CM: f32 = 0.889;

/// Code 8's P4 must stay below this; larger values are rejected with a message.
const MAX_P4: f32 = 1000.0;

/// Internal y of the bottom line of staff `number` on the default grid.
pub fn default_bottom(number: i32) -> i32 {
    let row = if is_recto(number) { number - LAST_VERSO_STAFF } else { number + 1 };
    row * STAFF_SPACING - 30300
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Staff {
    /// P2.
    pub number: i32,
    /// The code-8 item, or `None` for a staff that only exists by default.
    pub source: Option<ItemId>,
    /// P5 (0 read as 1), or P14/0.889 when P14 is set. Negative turns the staff over.
    pub size: f64,
    /// The engine's step unit, 25 × size; one scale step is 7 of them.
    pub step: f64,
    /// y of the bottom line of a normal five-line staff in this position.
    pub bottom: f64,
    /// y of P4 = 0 (STAFF_Y), truncated.
    pub level0: i32,
    /// y of the middle line (STAFF_MID), truncated.
    pub mid: i32,
}

impl Staff {
    /// The entry of a staff number without a code-8 item.
    pub fn default_for(number: i32) -> Self {
        Self::at(number, None, 1.0, f64::from(default_bottom(number)))
    }

    fn at(number: i32, source: Option<ItemId>, size: f64, bottom: f64) -> Self {
        let step = real(STEP_UNIT * size);
        let level0 = trunc(bottom - BOTTOM_LINE_STEPS * UNITS_PER_SCALE_STEP * step);
        let mid = trunc(f64::from(level0) + 1225.0 * size);
        Self { number, source, size, step, bottom, level0, mid }
    }

    /// Height of one scale step.
    pub fn scale_step(&self) -> f64 {
        UNITS_PER_SCALE_STEP * self.step
    }

    /// y of scale step `p4` (0 = the level below middle C on a treble staff,
    /// 3 = bottom line), as item_position 0x5479AB computes it.
    pub fn y(&self, p4: f64) -> f64 {
        real(f64::from(self.level0) + p4 * self.scale_step())
    }
}

/// Staff size from code 8's P5 and P14.
fn size(item: ItemRef<'_>) -> f64 {
    match (item.p(5), item.p(14)) {
        (_, cm) if cm != 0.0 => f64::from(cm / NORMAL_STAFF_CM),
        (0.0, _) => 1.0,
        (p5, _) => f64::from(p5),
    }
}

/// Code 8's P10: a height above a reference staff, `RRR.ii` = staff RRR
/// (0 = staff 1) plus ii inches (centimetres in metric mode).
#[derive(Debug, Clone, Copy, PartialEq)]
struct Lift {
    reference: i32,
    units: f64,
}

impl Lift {
    fn from_p10(p10: f32, metric: bool) -> Option<Self> {
        if p10 == 0.0 {
            return None;
        }
        let reference = match p10 as i32 / 100 {
            0 => 1,
            r => r,
        };
        let length = f64::from(p10) - f64::from(trunc(f64::from(p10) / 100.0) * 100);
        let inch = f64::from(UNITS_PER_INCH);
        let units = if metric { length * inch / 2.54 } else { length * inch };
        Some(Self { reference, units })
    }
}

/// Staff positions by number, from the document's code-8 items.
///
/// Two passes: first every staff placed by P4, then those placed by P10
/// relative to a reference staff's first-pass position, so that a reference
/// may come later in the file.
#[derive(Debug, Clone, PartialEq, Default)]
pub struct StaffTable {
    staves: BTreeMap<i32, Staff>,
    metric: bool,
}

impl StaffTable {
    pub fn from_items<'a>(items: impl IntoIterator<Item = ItemRef<'a>>, metric: bool) -> Self {
        let staff_items: Vec<ItemRef<'a>> =
            items.into_iter().filter(|item| item.code() == crate::codes::STAFF).collect();
        let first_pass = Self {
            staves: staff_items
                .iter()
                .filter_map(|&item| Some((item.staff(), placed_by_p4(item)?)))
                .collect(),
            metric,
        };
        let staves = staff_items
            .iter()
            .filter_map(|&item| Some((item.staff(), first_pass.staff_for(item)?)))
            .collect();
        Self { staves, metric }
    }

    /// The table entry for a staff number, defined or default.
    pub fn get(&self, number: i32) -> Staff {
        self.staves.get(&number).copied().unwrap_or_else(|| Staff::default_for(number))
    }

    /// The staff a code-8 item draws, or `None` if the engine rejects it.
    pub fn staff_for(&self, item: ItemRef<'_>) -> Option<Staff> {
        match Lift::from_p10(item.p(10), self.metric) {
            None => placed_by_p4(item),
            Some(lift) => {
                let bottom = real(self.get(lift.reference).bottom + lift.units);
                Some(Staff::at(item.staff(), Some(item.id), size(item), bottom))
            }
        }
    }

    /// Staves defined by code-8 items, by ascending number.
    pub fn defined(&self) -> impl Iterator<Item = &Staff> {
        self.staves.values()
    }

    /// The highest staff number defined by a code-8 item.
    pub fn highest(&self) -> Option<i32> {
        self.staves.keys().next_back().copied()
    }
}

fn placed_by_p4(item: ItemRef<'_>) -> Option<Staff> {
    let p4 = item.p(4);
    if p4 >= MAX_P4 {
        return None;
    }
    let size = size(item);
    let step = real(STEP_UNIT * size);
    let bottom = real(f64::from(default_bottom(item.staff())) + f64::from(p4) * UNITS_PER_SCALE_STEP * step);
    Some(Staff::at(item.staff(), Some(item.id), size, bottom))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn default_grid() {
        assert_eq!(default_bottom(1), -24000);
        assert_eq!(default_bottom(2), -24000 + 3150);
        assert_eq!(default_bottom(201), -24000);
        assert_eq!(default_bottom(200), default_bottom(0));
        let staff = Staff::default_for(1);
        assert_eq!((staff.level0, staff.mid), (-24525, -23300));
        assert_eq!(staff.y(3.0), -24000.0);
    }

    #[test]
    fn p10_reference_and_length() {
        assert_eq!(Lift::from_p10(1.5, false), Some(Lift { reference: 1, units: 6000.0 }));
        assert_eq!(Lift::from_p10(101.5, false), Some(Lift { reference: 1, units: 6000.0 }));
        assert_eq!(Lift::from_p10(201.5, false), Some(Lift { reference: 2, units: 6000.0 }));
        assert_eq!(Lift::from_p10(0.0, false), None);
    }
}
