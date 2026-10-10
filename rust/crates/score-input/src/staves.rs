//! Where staves stand (analysis/engine/staves.md), as far as input needs it: a note moved
//! to the staff above or below (S+/S-, P12) is measured from the IN staff in beams and slurs
//! (0x41A776).

use score_format::Item;

const STAFF_CODE: i32 = 8;
/// The highest staff number (MAX_STAFF).
const LAST_STAFF: u16 = 256;

/// A staff's place: STAFF_Y, the level of its P4 = 0, and its step.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct StaffPlace {
    pub y: f32,
    pub step: f32,
}

impl StaffPlace {
    /// A staff from its code-8 item: vertical offset P4 in its own scale steps, size P5
    /// (0 for 1).
    pub fn new(number: u16, offset: f32, size: f32) -> Self {
        let step = 25.0 * if size == 0.0 { 1.0 } else { size };
        let bottom = base(number) as f32 + offset * 7.0 * step;
        StaffPlace { y: (bottom - 21.0 * step).trunc(), step }
    }

    /// A staff without a code-8 item keeps its start-up place.
    pub fn default_for(number: u16) -> Self {
        StaffPlace { y: (base(number) - 525) as f32, step: 25.0 }
    }

    /// Staff `number` as the items place it.
    fn of(items: &[Item], number: u16) -> Self {
        items
            .iter()
            .find(|item| item.code() == STAFF_CODE && item.param(2) == f32::from(number))
            .map_or(Self::default_for(number), |staff| Self::new(number, staff.param(4), staff.param(5)))
    }
}

/// Bottom line of a size-1 staff at its default place: 18 scale steps per staff; staff 201
/// sits where staff 1 does.
fn base(number: u16) -> i32 {
    let n = i32::from(number);
    if n <= 199 {
        (n + 1) * 3150 - 30300
    } else {
        (n - 199) * 3150 - 30300
    }
}

/// Scale steps from the IN staff to the staff above and the staff below it; None where no
/// staff can be (below staff 1, above the last).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Neighbours {
    pub above: Option<f32>,
    pub below: Option<f32>,
}

impl Neighbours {
    fn between(this: StaffPlace, above: Option<StaffPlace>, below: Option<StaffPlace>) -> Self {
        let steps = |other: StaffPlace| (other.y - this.y) / (7.0 * this.step);
        Neighbours { above: above.map(steps), below: below.map(steps) }
    }

    /// The neighbours of staff `number` as the score's staff items place them.
    pub fn from_items(items: &[Item], number: u8) -> Self {
        let number = u16::from(number);
        let near = |n: u16| (1..=LAST_STAFF).contains(&n).then(|| StaffPlace::of(items, n));
        Self::between(StaffPlace::of(items, number), near(number + 1), number.checked_sub(1).and_then(near))
    }

    /// Staff `number` and its neighbours at their default places.
    pub fn defaults(number: u8) -> Self {
        Self::from_items(&[], number)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn default_staves_are_18_steps_apart() {
        assert_eq!(Neighbours::defaults(1), Neighbours { above: Some(18.0), below: None });
        assert_eq!(Neighbours::defaults(2), Neighbours { above: Some(18.0), below: Some(-18.0) });
    }
}
