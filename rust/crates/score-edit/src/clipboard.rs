//! Copies of items put somewhere else: pasting and duplicating move the
//! group as a whole, staves by one difference and horizontal positions by
//! another, as a group move does; P4 stays, so notes keep their pitch.

use score_format::Item;

use crate::command::moves::{shift, Axis};
use crate::params::Draft;

/// Copies that would lie exactly on the items they were copied from (or on
/// earlier copies) move this many P3 spaces to the right, as often as
/// needed: WinScore's End step, so Home puts a copy back over its original.
pub const STEP: f32 = 10.0;

/// Where pasted items go.
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Placement {
    /// Where they were copied from.
    InPlace,
    /// Their lowest staff on `staff`, their leftmost P3 at `p3`.
    At { staff: f32, p3: f32 },
}

/// `items` moved together to `place`, right ends (P6 of lines, slurs,
/// beams and trills) along, then [`STEP`] by [`STEP`] to the right until
/// they no longer all coincide with items of `existing`.
pub fn placed(items: &[Item], place: Placement, existing: &[Item]) -> Vec<Item> {
    let drafts: Vec<Draft> = items.iter().map(Draft::of).collect();
    let lowest = |n: usize| drafts.iter().map(|d| d.get(n)).fold(f32::INFINITY, f32::min);
    let (staves, steps) = match place {
        Placement::InPlace => (0.0, 0.0),
        Placement::At { staff, p3 } => (staff - lowest(2), p3 - lowest(3)),
    };
    let existing: Vec<Draft> = existing.iter().map(normalized).collect();
    let moved = |tries: u16| -> Vec<Item> {
        let distance = f64::from(steps) + f64::from(tries) * f64::from(STEP);
        drafts
            .iter()
            .map(|draft| {
                let mut draft = draft.clone();
                draft.add(2, staves);
                shift(&mut draft, Axis::Horizontal, distance);
                draft.to_item()
            })
            .collect()
    };
    let covers = |copies: &[Item]| copies.iter().all(|copy| existing.contains(&normalized(copy)));
    (0..=u16::MAX).map(moved).find(|copies| copies.is_empty() || !covers(copies)).unwrap_or_default()
}

/// The parameters as the engine would store them, for comparing items.
fn normalized(item: &Item) -> Draft {
    Draft::of(&Draft::of(item).to_item())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn params(items: &[Item], ns: &[usize]) -> Vec<Vec<f32>> {
        items.iter().map(|item| ns.iter().map(|&n| item.param(n)).collect()).collect()
    }

    fn group() -> Vec<Item> {
        let note = Draft::new(&[1.0, 2.0, 100.0, 6.0, 10.0]).to_item();
        let slur = Draft::new(&[5.0, 3.0, 102.0, 8.0, 9.0, 130.0]).to_item();
        vec![note, slur]
    }

    #[test]
    fn copies_step_aside_from_what_they_would_cover() {
        let alone = placed(&group(), Placement::InPlace, &[]);
        assert_eq!(alone, group());
        let beside = placed(&group(), Placement::InPlace, &group());
        assert_eq!(params(&beside, &[2, 3, 4, 6]), [[2.0, 110.0, 6.0, 0.0], [3.0, 112.0, 8.0, 140.0]]);
        let next = placed(&group(), Placement::InPlace, &[group(), beside].concat());
        assert_eq!(params(&next, &[3]), [[120.0], [122.0]]);
        let partly = placed(&group(), Placement::InPlace, &group()[..1]);
        assert_eq!(partly, group());
    }

    #[test]
    fn at_puts_the_lowest_staff_and_left_edge_there() {
        let moved = placed(&group(), Placement::At { staff: 5.0, p3: 40.0 }, &group());
        assert_eq!(params(&moved, &[2, 3, 4, 6]), [[5.0, 40.0, 6.0, 0.0], [6.0, 42.0, 8.0, 70.0]]);
    }
}
