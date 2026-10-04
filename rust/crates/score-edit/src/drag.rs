//! Dragging items with the mouse.
//!
//! The engine (0x48F663, analysis/engine/editing.md) sets the dragged item's
//! position from the cursor on every mouse move: P3 = x / 150, P4 = (y -
//! level of P4 = 0) / scale step plus a per-item constant, with P4 snapped
//! to whole steps (halves away from zero) for notes, rests, clefs, keys and
//! meters. Here the item keeps the offset at which it was grabbed (decision
//! D8/D9), so the per-item constant cancels: P3 = (150 P3₀ + dx) / 150,
//! P4 = P4₀ + dy / step, rounded as the engine rounds.

use score_render::page::P3_UNIT;
use score_render::staff::Staff;

use crate::command::moves::{shift, Axis};
use crate::params::Draft;

/// Cursor travel a Shift-drag needs before it moves the item again.
const CONSTRAINED_STEP: f64 = 50.0;

/// A point of the page in engine units (origin at the paper's bottom-left corner, y up).
#[derive(Debug, Clone, Copy, PartialEq, Default)]
pub struct PagePoint {
    pub x: f64,
    pub y: f64,
}

/// Which part of a two-point item a drag moves: the engine's move mode
/// (int 0x78DC30), set by ALL, LFT and RGT.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub enum Ends {
    #[default]
    All,
    Left,
    Right,
}

/// Which coordinates a drag move may change.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Axes {
    Both,
    Only(Axis),
}

/// Whether the drag routine moves the item vertically: staves and barlines only move sideways.
fn moves_vertically(code: i32) -> bool {
    !matches!(code, 8 | 14)
}

/// Codes whose dragged level snaps to whole steps.
fn snaps(code: i32) -> bool {
    !(4..=16).contains(&code)
}

/// Codes with a right end in P6 (and, for 4–6, P5) that LFT and RGT can move alone.
fn has_right_end(code: i32) -> bool {
    (4..=7).contains(&code)
}

/// The engine's horizontal result for a cursor at internal x: f32(x / 150).
fn dragged_p3(p3: f32, dx: f64) -> f32 {
    ((P3_UNIT * f64::from(p3) + dx) / P3_UNIT) as f32
}

fn dragged_level(code: i32, p4: f32, dy: f64, staff: &Staff) -> f32 {
    let level = f64::from(p4) + dy / staff.scale_step();
    (if snaps(code) { level.round() } else { level }) as f32
}

/// `start` dragged by (`dx`, `dy`) page units on `staff`.
pub fn dragged(start: &Draft, staff: &Staff, ends: Ends, dx: f64, dy: f64, axes: Axes) -> Draft {
    let code = start.code();
    let horizontal = axes != Axes::Only(Axis::Vertical);
    let vertical = axes != Axes::Only(Axis::Horizontal) && moves_vertically(code);
    let mut draft = start.clone();
    match ends {
        Ends::Right if has_right_end(code) => {
            if horizontal {
                draft.set(6, dragged_p3(start.get(6), dx));
            }
            if vertical && code != 7 {
                draft.set(5, dragged_level(code, start.get(5), dy, staff));
            }
        }
        Ends::Left if has_right_end(code) => {
            if horizontal {
                draft.set(3, dragged_p3(start.get(3), dx));
            }
            if vertical {
                draft.set(4, dragged_level(code, start.get(4), dy, staff));
            }
        }
        _ => {
            if horizontal {
                let p3 = dragged_p3(start.get(3), dx);
                shift(&mut draft, Axis::Horizontal, f64::from(p3) - f64::from(start.get(3)));
                draft.set(3, p3);
            }
            if vertical {
                let p4 = dragged_level(code, start.get(4), dy, staff);
                shift(&mut draft, Axis::Vertical, f64::from(p4) - f64::from(start.get(4)));
                draft.set(4, p4);
            }
        }
    }
    draft
}

/// Shift-drag: the first move only records the cursor, the second picks the
/// dominant axis, later ones count only after [`CONSTRAINED_STEP`] of travel.
#[derive(Debug, Clone, Copy, PartialEq, Default)]
pub struct Constraint {
    first: Option<PagePoint>,
    axis: Option<Axis>,
    last: Option<PagePoint>,
}

impl Constraint {
    /// The axes this move may change, or `None` if it is to be ignored.
    pub fn admit(&mut self, point: PagePoint) -> Option<Axes> {
        let Some(first) = self.first else {
            self.first = Some(point);
            return None;
        };
        let axis = *self.axis.get_or_insert_with(|| {
            if (point.y - first.y).abs() > (point.x - first.x).abs() {
                Axis::Vertical
            } else {
                Axis::Horizontal
            }
        });
        let travelled = self.last.map_or(f64::INFINITY, |last| match axis {
            Axis::Horizontal => (point.x - last.x).abs(),
            Axis::Vertical => (point.y - last.y).abs(),
        });
        (travelled >= CONSTRAINED_STEP).then(|| {
            self.last = Some(point);
            Axes::Only(axis)
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn staff() -> Staff {
        Staff::default_for(1)
    }

    #[test]
    fn notes_snap_and_lines_do_not() {
        let note = Draft::new(&[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.0]);
        let moved = dragged(&note, &staff(), Ends::All, 37.0, 77.0, Axes::Both);
        assert_eq!((moved.get(3), moved.get(4)), ((15037.0_f64 / 150.0) as f32, 6.0));
        let line = Draft::new(&[4.0, 1.0, 50.0, 5.0, 10.0, 120.0]);
        let moved = dragged(&line, &staff(), Ends::All, 137.0, 87.0, Axes::Both);
        assert!((moved.get(4) - 5.497_143).abs() < 1e-5);
        assert!((moved.get(5) - 10.497_143).abs() < 1e-5);
        assert!((moved.get(6) - 120.913_33).abs() < 1e-4);
    }

    #[test]
    fn barlines_only_move_sideways() {
        let bar = Draft::new(&[14.0, 1.0, 100.0, 1.0]);
        let moved = dragged(&bar, &staff(), Ends::All, 300.0, 500.0, Axes::Both);
        assert_eq!((moved.get(3), moved.get(4)), (102.0, 1.0));
    }

    #[test]
    fn ends_move_alone() {
        let line = Draft::new(&[4.0, 1.0, 50.0, 5.0, 10.0, 120.0]);
        let right = dragged(&line, &staff(), Ends::Right, 150.0, 175.0, Axes::Both);
        assert_eq!((right.get(3), right.get(4), right.get(5), right.get(6)), (50.0, 5.0, 11.0, 121.0));
        let left = dragged(&line, &staff(), Ends::Left, 150.0, 175.0, Axes::Both);
        assert_eq!((left.get(3), left.get(4), left.get(5), left.get(6)), (51.0, 6.0, 10.0, 120.0));
    }

    #[test]
    fn shift_drags_lock_to_the_first_dominant_axis() {
        let mut c = Constraint::default();
        let p = |x, y| PagePoint { x, y };
        assert_eq!(c.admit(p(0.0, 0.0)), None);
        assert_eq!(c.admit(p(10.0, 30.0)), Some(Axes::Only(Axis::Vertical)));
        assert_eq!(c.admit(p(200.0, 60.0)), None);
        assert_eq!(c.admit(p(0.0, 81.0)), Some(Axes::Only(Axis::Vertical)));
    }
}
