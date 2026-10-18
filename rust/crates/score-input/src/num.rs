//! The engine's integer and remainder conversions, for the routines that work on stored
//! parameters.

/// Truncation toward zero, as the engine's conversions do.
pub(crate) fn trunc(x: f32) -> i32 {
    x as i32
}

/// The engine's AMOD: x minus y times the truncated quotient, stored as f32.
pub(crate) fn amod(x: f32, y: f32) -> f32 {
    let quotient = (f64::from(x) / f64::from(y)) as i64;
    (f64::from(x) - quotient as f64 * f64::from(y)) as f32
}

/// Parameter `k` (1-based) of a parameter row; parameters not stored are zero.
pub(crate) fn par(row: &[f32], k: usize) -> f32 {
    k.checked_sub(1).and_then(|i| row.get(i)).copied().unwrap_or(0.0)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn amod_keeps_the_sign_of_x() {
        assert_eq!(amod(22.5, 10.0), 2.5);
        assert_eq!(amod(-101.5, 100.0), -1.5);
    }
}
