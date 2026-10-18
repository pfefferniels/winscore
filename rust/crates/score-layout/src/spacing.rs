//! New positions for the master event list: every duration d gets d^log2(1.5)
//! of a common unit, so each doubling of a value gets 1.5 times the space; markers get
//! fixed widths in staff-size units.

use crate::num::wide;

/// The engine's f32 constant log2(1.5).
#[allow(clippy::excessive_precision)]
const EXPONENT: f32 = 0.584_962_487_220_764_2;

pub const BARLINE: f32 = -14.0;
pub const BARLINE_P12: f32 = -140.0;
pub const START_CLEF: f32 = -15.0;
const METER: f32 = -18.0;

/// Fixed width of a marker followed by `next` (0 past the end), in staff-size units.
fn marker_width(marker: f32, next: f32) -> f64 {
    let next = next as i32;
    if marker == BARLINE || marker == BARLINE_P12 {
        return match next {
            -15 | -17 => 1.5,
            -18 => 1.0,
            _ => 3.5,
        };
    }
    if marker == START_CLEF {
        return match next {
            -18 => 6.0,
            n if n < -16 => 8.0,
            _ => 10.0,
        };
    }
    if marker == METER && next == -14 {
        return 4.6;
    }
    3.5
}

/// The positions of the entries from `left` to `right` (one more than there are entries:
/// the end of the last).
pub fn positions(entries: &[f32], size: f32, left: f32, right: f32) -> Vec<f32> {
    let n = entries.len();
    let mut fixed = 0.0f32;
    let mut total = 0.0f32;
    let widths: Vec<f64> = entries
        .iter()
        .enumerate()
        .map(|(k, &e)| {
            if e > 0.0 {
                let width = wide(e).powf(wide(EXPONENT)) as f32;
                total += width;
                wide(width)
            } else if k == n - 1 {
                0.0
            } else {
                let width = marker_width(e, entries[k + 1]);
                fixed = (width + wide(fixed)) as f32;
                width
            }
        })
        .collect();
    // The width is stored as f32 before the rest of the expression.
    let width = right - left;
    let unit = ((wide(width) - wide(size) * wide(fixed)) / wide(total)) as f32;
    let mut x = left;
    let mut out: Vec<f32> = entries
        .iter()
        .zip(&widths)
        .map(|(&e, &width)| {
            let at = x;
            let scale = if e <= 0.0 { size } else { unit };
            let step = (wide(scale) * width) as f32;
            x += step;
            at
        })
        .collect();
    out.push(x);
    out
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn quarters_and_eighths_after_a_clef() {
        // Clef at 2, notes 1, .5, .5, 2, 1, 1, 4 quarters (P7 times 4), barline at 200.
        let entries = [START_CLEF, 4.0, 2.0, 2.0, 8.0, 4.0, 4.0, 16.0, BARLINE];
        let x = positions(&entries, 1.0, 2.0, 200.0);
        let expected = [2.0, 12.0, 35.2578, 50.7628, 66.2681, 101.1547, 124.4125, 147.67];
        assert!(x.iter().zip(expected).all(|(a, b)| (a - b).abs() < 1e-3), "{x:?}");
    }
}
