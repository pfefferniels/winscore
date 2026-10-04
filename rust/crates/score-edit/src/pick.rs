//! Which item a click selects, by WinScore's rule (0x498BF0, analysis/engine/editing.md):
//! the item whose reference point is nearest to the cursor. The reference
//! point is P3 across and P4 plus a per-code offset up; it is not the drawn
//! outline, so a click always finds something unless a radius limits it.

use score_format::Item;
use score_render::page::{is_recto, page_offset, P3_UNIT};
use score_render::staff::Staff;

use crate::drag::PagePoint;

/// P3 units the click rule adds for staves on the recto page.
const RECTO_P3: f32 = 227.0;
/// Any staff of the verso page, for the page origin without the recto shift.
const VERSO_STAFF: i32 = 1;
/// Rest symbols (P5 = -3 double whole … 3 thirty-second) are found this many
/// steps above P4 (table 0x78DD8C; the eighth rest's 1 is checked in the oracle).
const REST_LEVELS: [f32; 7] = [4.0, 4.0, 2.0, 2.0, 1.0, 1.0, 1.0];
const REST_SYMBOL_BASE: i32 = 3;
/// Staves and barlines are found at the bottom line (level 3), whatever P4 says.
const FIXED_LEVEL: f32 = 3.0;

/// P4 without the hundreds that mark cue size, for the codes that use them.
fn level(item: &Item) -> f32 {
    let p4 = item.param(4);
    if matches!(item.code(), 1 | 2 | 3 | 6) {
        p4 - (p4 / 100.0).trunc() * 100.0
    } else {
        p4
    }
}

/// The reference point's level in steps and its extra P3 offset.
fn reference(item: &Item) -> (f32, f32) {
    let code = item.code();
    match code {
        2 => {
            let symbol = item.param(5) - (item.param(5) / 100.0).trunc() * 100.0;
            let index = (symbol as i32 + REST_SYMBOL_BASE).clamp(0, REST_LEVELS.len() as i32 - 1) as usize;
            (level(item) + REST_LEVELS[index], 0.0)
        }
        8 | 14 => (FIXED_LEVEL, 0.0),
        6 if item.param(7).abs() < 20.0 => (level(item) + 6.0, 2.0),
        6 => (level(item) - 8.0, 0.0),
        5 => {
            let kind = item.param(8);
            let dx = if kind == -1.0 {
                1.0
            } else if kind == -2.0 || kind == -3.0 {
                3.0
            } else {
                0.0
            };
            (level(item), dx)
        }
        3 => (level(item), 0.0),
        17 => (level(item) + 4.0, 0.0),
        18 => (level(item) + 3.0, 0.0),
        _ => (level(item) - 1.0, 0.0),
    }
}

/// The reference point of `item` on `staff`, in the engine's internal integers
/// with the recto page to the right of the verso.
fn anchor(item: &Item, staff: &Staff) -> (i64, i64) {
    let (steps, dx) = reference(item);
    let recto = if is_recto(staff.number) { RECTO_P3 } else { 0.0 };
    let x = (f64::from(item.param(3) + recto + dx) * P3_UNIT).trunc() as i64;
    let y = (f64::from(staff.level0) + f64::from(steps) * staff.scale_step()).trunc() as i64;
    (x, y)
}

/// The cursor in the same integers.
fn cursor(point: PagePoint) -> (i64, i64) {
    let origin = page_offset(VERSO_STAFF);
    ((point.x - f64::from(origin.x)).round() as i64, (point.y - f64::from(origin.y)).round() as i64)
}

/// Engine distance: the truncated Euclidean distance.
fn distance(a: (i64, i64), b: (i64, i64)) -> i64 {
    (((a.0 - b.0).pow(2) + (a.1 - b.1).pow(2)) as f64).sqrt() as i64
}

/// Index of the item nearest to `point` (the first of equals), within `radius` page units if given.
pub fn nearest<'a>(
    items: impl IntoIterator<Item = (&'a Item, Staff)>,
    point: PagePoint,
    radius: Option<f64>,
) -> Option<usize> {
    let at = cursor(point);
    let (index, d) = items
        .into_iter()
        .enumerate()
        .map(|(i, (item, staff))| (i, distance(anchor(item, &staff), at)))
        .fold(None, |best: Option<(usize, i64)>, (i, d)| match best {
            Some((_, best_d)) if best_d <= d => best,
            _ => Some((i, d)),
        })?;
    radius.is_none_or(|r| d as f64 <= r).then_some(index)
}

#[cfg(test)]
mod tests {
    use super::*;
    use score_format::Word;

    fn item(params: &[f32]) -> Item {
        Item::new(params.iter().copied().map(Word::from_f32).collect())
    }

    #[test]
    fn notes_are_found_a_step_below_p4() {
        let staff = Staff::default_for(1);
        let note = item(&[1.0, 1.0, 120.0, 8.0, 10.0]);
        assert_eq!(anchor(&note, &staff), (18000, -24525 + 7 * 175));
    }

    #[test]
    fn the_nearest_reference_point_wins() {
        let staff = Staff::default_for(1);
        let items = [item(&[8.0, 1.0, 0.0]), item(&[1.0, 1.0, 100.0, 6.0, 10.0]), item(&[1.0, 1.0, 120.0, 8.0, 10.0])];
        let pick = |x, y, r| nearest(items.iter().map(|i| (i, staff)), PagePoint { x, y }, r);
        assert_eq!(pick(19900.0, 3600.0, None), Some(2));
        assert_eq!(pick(2100.0, 2950.0, None), Some(0));
        assert_eq!(pick(30000.0, 9000.0, Some(500.0)), None);
    }
}
