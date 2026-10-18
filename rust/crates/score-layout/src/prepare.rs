//! The adjustments the command's main pass makes before the line-up proper, and the staff
//! sizes it uses.

use std::collections::BTreeMap;

use crate::num::wide;
use crate::rows::{Row, BEAM, CLEF, NOTE, STAFF};
use crate::sort::sort_rows;
use crate::LayoutErrorKind;

/// The staff step (25 times the size) of every staff that has a staff item.
pub fn staff_steps(rows: &[Row]) -> BTreeMap<i32, f32> {
    rows.iter()
        .filter(|r| r.code() == STAFF)
        .map(|r| {
            let size = if r.par(14) != 0.0 { r.par(14) / 0.889 } else { r.par(5) };
            (r.staff(), 25.0 * if size != 0.0 { size } else { 1.0 })
        })
        .collect()
}

/// Sorts the items and nudges a few of them; returns the last staff that exists within
/// `lo..=hi`, or `None` when none does.
pub fn prepare(rows: &mut [Row], lo: i32, hi: i32, right: f32, source_box: (f32, f32)) -> Result<Option<i32>, LayoutErrorKind> {
    sort_rows(rows)?;
    pull_hairpins_onto_notes(rows, lo, hi);
    sort_rows(rows)?;
    let Some(top) = rows.last().map(Row::staff) else {
        return Ok(None);
    };
    if top < lo {
        return Ok(None);
    }
    let hi = hi.min(top);
    move_clefs_off_staff_starts(rows, lo, hi, source_box);
    sort_rows(rows)?;
    keep_clear_of_right_edge(rows, lo, hi, right);
    Ok(Some(hi))
}

/// A hairpin (code 4 with P7 < 0 and P6 = 0) at a note's position moves just before it.
fn pull_hairpins_onto_notes(rows: &mut [Row], lo: i32, hi: i32) {
    let mut last_note = -9999.0f32;
    for row in rows.iter_mut().filter(|r| (lo..=hi).contains(&r.staff())) {
        if row.code() == NOTE {
            last_note = row.x();
            continue;
        }
        if (wide(last_note) - wide(row.x())).abs() < wide(0.1) && row.par(7) < 0.0 && row.code() == 4 && row.len() > 6 && row.par(6) == 0.0 {
            row.set_x(last_note - 0.001);
        }
        last_note = -9999.0;
    }
}

/// A clef at the very start of its staff (inside the source box) moves 1.5 to the right.
fn move_clefs_off_staff_starts(rows: &mut [Row], lo: i32, hi: i32, (box_left, box_right): (f32, f32)) {
    let mut start = 0;
    for staff in lo..=hi {
        let mut staff_x = -9999.0f32;
        let mut clef: Option<usize> = None;
        for k in start..rows.len() {
            let row = &rows[k];
            if row.staff() != staff || (row.code() != STAFF && row.code() != CLEF) {
                continue;
            }
            if row.code() == CLEF {
                clef = Some(k);
                if staff_x == -9999.0 {
                    continue;
                }
            } else {
                staff_x = row.x();
                if clef.is_none() {
                    continue;
                }
            }
            if let Some(c) = clef {
                let clef_x = rows[c].x();
                if clef_x < box_right && staff_x == clef_x && box_left <= clef_x {
                    rows[c].set_x(staff_x + 1.5);
                }
            }
            start = k + 1;
            break;
        }
    }
}

/// Notes, beams and ending slurs within one unit of the right edge move to one unit
/// before it.
fn keep_clear_of_right_edge(rows: &mut [Row], lo: i32, hi: i32, right: f32) {
    let near = |x: f32| (wide(right) - wide(x)).abs() < 1.0;
    for row in rows.iter_mut().filter(|r| (lo..=hi).contains(&r.staff())) {
        match row.code() {
            NOTE if near(row.x()) => row.set_x(right - 1.0),
            BEAM if near(row.par(6)) => row.set(6, right - 1.0),
            5 if row.par(8) == -1.0 && near(row.par(6)) => row.set(6, right - 1.0),
            _ => {}
        }
    }
}
