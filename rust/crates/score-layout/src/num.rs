//! The engine's arithmetic: expressions evaluated in extended precision, results stored as
//! f32. A single operation on two f32 values rounds the same in f32 and in f64, so only
//! compound expressions and comparisons go through f64 explicitly.

/// Truncation toward zero, as the engine's integer conversions do.
pub fn trunc(x: f32) -> i32 {
    x as i32
}

/// ANINT (0x5FF381): x plus or minus 0.5, truncated.
pub fn nint(x: f64) -> i64 {
    if x >= 0.0 {
        (x + 0.5) as i64
    } else {
        (x - 0.5) as i64
    }
}

/// An f32 value or constant widened for an extended-precision expression.
pub fn wide(x: f32) -> f64 {
    f64::from(x)
}

/// The engine's AMOD (0x54AABA): x minus y times the truncated quotient, stored as f32.
pub fn amod(x: f32, y: f32) -> f32 {
    let quotient = (wide(x) / wide(y)) as i64;
    (wide(x) - quotient as f64 * wide(y)) as f32
}

/// The runtime's exact remainder (0x5FF874), stored as f32.
pub fn fmod(x: f32, y: f32) -> f32 {
    (wide(x) % wide(y)) as f32
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn nint_rounds_half_away_from_zero() {
        assert_eq!(nint(2.5), 3);
        assert_eq!(nint(-2.5), -3);
        assert_eq!(nint(2.4999), 2);
    }
}
