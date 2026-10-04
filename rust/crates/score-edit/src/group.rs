//! Group edits (WinScore help, groupedit.txt): commands that act on every
//! item of an area of the page. The area is typed as `staff left right
//! [top] [codes…]` (or drawn as a box in WinScore); the command then asks
//! for what it needs, one line at a time.

use crate::params::Draft;

/// P3 of the right edge when none is typed.
const FULL_WIDTH: f32 = 200.0;

/// An area of the page: staves `bottom..=top`, P3 from `left` to `right`,
/// optionally only some codes.
#[derive(Debug, Clone, PartialEq)]
pub struct Region {
    pub bottom: f32,
    pub top: f32,
    pub left: f32,
    pub right: f32,
    pub codes: Vec<i32>,
}

impl Region {
    /// `staff left right top code code …` as typed: a right edge of 0 means
    /// 200, a top staff of 0 the bottom staff, no codes every code.
    pub fn parse(numbers: &[f32]) -> Option<Self> {
        let bottom = *numbers.first()?;
        let get = |i: usize| numbers.get(i).copied().unwrap_or(0.0);
        let right = if get(2) == 0.0 { FULL_WIDTH } else { get(2) };
        let top = if get(3) == 0.0 { bottom } else { get(3) };
        let codes = numbers.iter().skip(4).map(|&c| c as i32).collect();
        Some(Self { bottom, top, left: get(1), right, codes })
    }

    pub fn contains_x(&self, x: f32) -> bool {
        (self.left..=self.right).contains(&x)
    }

    /// Whether the item lies in the area: its staff, its P3 and its code.
    pub fn contains(&self, draft: &Draft) -> bool {
        (self.bottom..=self.top).contains(&draft.get(2))
            && self.contains_x(draft.get(3))
            && (self.codes.is_empty() || self.codes.contains(&draft.code()))
    }
}

/// Where a group move or copy puts the area: typed as `staff`, `staff steps`
/// or `staff left right` (the area scaled to the new width).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Destination {
    pub bottom: f32,
    pub placement: Placement,
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Placement {
    Shift(f32),
    Span { left: f32, right: f32 },
}

impl Destination {
    pub fn parse(numbers: &[f32]) -> Option<Self> {
        let bottom = *numbers.first()?;
        let placement = match numbers[1..] {
            [] => Placement::Shift(0.0),
            [steps] => Placement::Shift(steps),
            [left, right, ..] => Placement::Span { left, right },
        };
        Some(Self { bottom, placement })
    }

    /// `draft` moved from `region` to here: its staff by the difference of
    /// the bottom staves, and each horizontal position inside the area
    /// (P3, a right end in P6) shifted or scaled.
    pub fn moved(&self, region: &Region, draft: &Draft) -> Draft {
        let mut moved = draft.clone();
        moved.add(2, self.bottom - region.bottom);
        let x_params: &[usize] = if RIGHT_END_X.contains(&draft.code()) && draft.get(6) != 0.0 { &[3, 6] } else { &[3] };
        x_params.iter().filter(|&&n| region.contains_x(draft.get(n))).for_each(|&n| {
            moved.set(n, self.x(region, draft.get(n)));
        });
        moved
    }

    fn x(&self, region: &Region, x: f32) -> f32 {
        match self.placement {
            Placement::Shift(steps) => x + steps,
            Placement::Span { left, right } => {
                let scale = (f64::from(right) - f64::from(left)) / (f64::from(region.right) - f64::from(region.left));
                (f64::from(left) + (f64::from(x) - f64::from(region.left)) * scale) as f32
            }
        }
    }
}

/// Codes whose P6 is a right end.
const RIGHT_END_X: [i32; 4] = [4, 5, 6, 7];

/// Codes MUD leaves where they are: clefs, staves, barlines, keys, meters.
pub const FIXED_BY_MUD: [i32; 5] = [3, 8, 14, 17, 18];

/// What a group command still needs to hear.
#[derive(Debug, Clone, PartialEq)]
pub enum Pending {
    /// The area, for the command.
    Area(GroupCommand),
    /// Where to move or copy the area.
    Destination { region: Region, copy: bool },
    /// Which code a group alter changes.
    AlterCode(Region),
    /// The parameter changes of a group alter.
    AlterPairs { region: Region, code: i32 },
    /// How many steps MUD moves.
    Steps(Region),
    /// The staves CPX copies to.
    Staves(Region),
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum GroupCommand {
    Delete,
    Move,
    Copy,
    Alter,
    MoveUpDown,
    CopyToStaves,
}

impl GroupCommand {
    pub fn word(word: &str) -> Option<Self> {
        let command = match word {
            "D" | "DE" | "DG" => Self::Delete,
            "M" => Self::Move,
            "C" | "CO" => Self::Copy,
            "A" => Self::Alter,
            "MUD" | "MU" => Self::MoveUpDown,
            "CPX" => Self::CopyToStaves,
            _ => return None,
        };
        Some(command)
    }
}

impl Pending {
    /// The question the editor is waiting to have answered.
    pub fn prompt(&self) -> &'static str {
        match self {
            Pending::Area(_) => "Enter staff, left position, right position, [upper staff], [codes]",
            Pending::Destination { .. } => "Enter destination staff, [steps] or [left position, right position]",
            Pending::AlterCode(_) => "Enter the code number of the items to change",
            Pending::AlterPairs { .. } => "Type P#, change, P#, change, ...",
            Pending::Steps(_) => "Enter the number of steps to move, plus or minus",
            Pending::Staves(_) => "Enter the staff numbers to copy to",
        }
    }
}

/// Reordering (OS, OH, OT): the sort key of an item.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Order {
    /// OS: staff by staff from staff 1, left to right on each.
    Staff,
    /// OH: left to right whatever the staff.
    Horizontal,
    /// OT: text items first, from the highest staff down, then as OS.
    Text,
}

impl Order {
    pub fn word(word: &str) -> Option<Self> {
        match word {
            "OS" => Some(Self::Staff),
            "OH" => Some(Self::Horizontal),
            "OT" => Some(Self::Text),
            _ => None,
        }
    }

    /// Compares two items for this order; equal positions sort by P4.
    pub fn compare(self, a: &Draft, b: &Draft) -> std::cmp::Ordering {
        let staff_then_x = |d: &Draft| (d.get(2), d.get(3), d.get(4));
        let key = |d: &Draft| match self {
            Order::Staff => (0.0, staff_then_x(d)),
            Order::Horizontal => (0.0, (d.get(3), d.get(2), d.get(4))),
            Order::Text if d.code() == crate::params::TEXT_CODE => (0.0, (-d.get(2), d.get(3), d.get(4))),
            Order::Text => (1.0, staff_then_x(d)),
        };
        key(a).partial_cmp(&key(b)).unwrap_or(std::cmp::Ordering::Equal)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn regions_as_typed() {
        let r = Region::parse(&[1.0, 0.0, 0.0, 0.0]).unwrap();
        assert_eq!((r.bottom, r.top, r.left, r.right), (1.0, 1.0, 0.0, 200.0));
        let r = Region::parse(&[1.0, 90.0, 120.0, 2.0, 1.0, 2.0]).unwrap();
        assert_eq!((r.top, r.codes.clone()), (2.0, vec![1, 2]));
        assert!(r.contains(&Draft::new(&[1.0, 2.0, 120.0])));
        assert!(!r.contains(&Draft::new(&[9.0, 2.0, 100.0])));
    }

    #[test]
    fn destinations_shift_or_scale() {
        let region = Region::parse(&[1.0, 100.0, 120.0]).unwrap();
        let line = Draft::new(&[4.0, 1.0, 100.0, 5.0, 5.0, 120.0]);
        let scaled = Destination::parse(&[2.0, 50.0, 90.0]).unwrap().moved(&region, &line);
        assert_eq!((scaled.get(2), scaled.get(3), scaled.get(6)), (2.0, 50.0, 90.0));
        let narrow = Region::parse(&[1.0, 90.0, 110.0]).unwrap();
        let shifted = Destination::parse(&[1.0, 5.0]).unwrap().moved(&narrow, &line);
        assert_eq!((shifted.get(3), shifted.get(6)), (105.0, 120.0));
    }
}
