//! The item sort the layout commands start with.

use std::cmp::Ordering;

use crate::num::{nint, wide};
use crate::rows::{Row, REST};
use crate::LayoutErrorKind;

/// Rounds every P3 to hundredths, then orders the items stably by staff and P3, notes and
/// rests before the other codes at the same P3, then by P4 (a rest's P4 counted 5 higher).
pub fn sort_rows(rows: &mut [Row]) -> Result<(), LayoutErrorKind> {
    for row in rows.iter_mut().filter(|r| r.len() > 2) {
        let hundredths = nint(wide(row.x()) * 100.0) as f32;
        row.set_x(hundredths / 100.0);
    }
    if rows.iter().any(|r| secondary(r) >= 900.0) {
        // The engine's selection sort would then repeat the last item.
        return Err(LayoutErrorKind::P4TooLarge);
    }
    rows.sort_by(|a, b| primary(a).cmp(&primary(b)).then(secondary(a).partial_cmp(&secondary(b)).unwrap_or(Ordering::Equal)));
    Ok(())
}

fn primary(row: &Row) -> i64 {
    let key = (f64::from(row.staff()) * 1e6 + wide(row.x()) * 1000.0) as i64;
    key + i64::from(row.par(1) > 2.0)
}

fn secondary(row: &Row) -> f32 {
    match row.len() {
        0..=3 => 0.0,
        _ if row.par(1) == REST as f32 => row.par(4) + 5.0,
        _ => row.par(4),
    }
}
