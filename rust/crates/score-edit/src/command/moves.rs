//! Moving items: R, L, U, D (WinScore help, "Editing the Music").
//!
//! `R 5` moves five horizontal spaces (P3 units) to the right, `U 7` seven
//! scale steps up. The letter alone repeats the axis' last increment; a
//! doubled letter moves .5, a tripled one .2, and both set the increment.
//! I or C after the letter gives the count in inches or centimetres.

use crate::command::parse::split_count;
use crate::params::Draft;

const P3_PER_INCH: f64 = 200.0 / 7.5;
/// Engine units per inch as the engine has them, the reciprocal of the f32
/// 0.00025: this reproduces its UI and DC results to the last bit, where an
/// exact 4000 is one ulp off (inferred from three measurements).
const UNITS_PER_INCH: f64 = 1.0 / 0.00025_f32 as f64;
const CM_PER_INCH: f64 = 2.54;
/// Engine units per scale step on a staff of size 1 (7 × the step unit 25).
const UNITS_PER_STEP: f64 = 175.0;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Axis {
    Horizontal,
    Vertical,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Unit {
    Steps,
    Inches,
    Centimetres,
}

/// The increments a letter alone repeats, one per axis.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Increments {
    pub horizontal: f64,
    pub vertical: f64,
}

impl Default for Increments {
    fn default() -> Self {
        Self { horizontal: 1.0, vertical: 1.0 }
    }
}

impl Increments {
    fn get_mut(&mut self, axis: Axis) -> &mut f64 {
        match axis {
            Axis::Horizontal => &mut self.horizontal,
            Axis::Vertical => &mut self.vertical,
        }
    }
}

/// A parsed move word.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Move {
    pub axis: Axis,
    pub sign: f64,
    /// How often the letter was typed: 1, 2 (.5) or 3 (.2).
    pub repeats: usize,
    pub unit: Unit,
    pub count: Option<f32>,
}

impl Move {
    /// `R`, `LL`, `UUU`, `RI`, `DC`, `R10`, with an optional count from the next token.
    pub fn parse(word: &str, next: Option<f32>) -> Option<Self> {
        let (letters, attached) = split_count(word);
        let first = letters.chars().next()?;
        let (axis, sign) = match first {
            'R' => (Axis::Horizontal, 1.0),
            'L' => (Axis::Horizontal, -1.0),
            'U' => (Axis::Vertical, 1.0),
            'D' => (Axis::Vertical, -1.0),
            _ => return None,
        };
        let repeats = letters.chars().take_while(|&c| c == first).count();
        let unit = match &letters[repeats..] {
            "" => Unit::Steps,
            "I" => Unit::Inches,
            "C" => Unit::Centimetres,
            _ => return None,
        };
        if repeats > 3 || (repeats > 1 && unit != Unit::Steps) {
            return None;
        }
        Some(Self { axis, sign, repeats, unit, count: attached.or(next) })
    }

    /// Whether the word says how far: `LI` alone moves by the increment like `L`,
    /// but on WinScore's menus it is the line-up command.
    pub fn is_complete(self) -> bool {
        self.unit == Unit::Steps || self.count.is_some()
    }

    /// The signed distance in P3 units or scale steps, updating the axis' increment.
    /// `staff_size` scales inches and centimetres to steps.
    pub fn distance(&self, increments: &mut Increments, staff_size: f64) -> f64 {
        let increment = increments.get_mut(self.axis);
        let steps = match (self.count, self.repeats) {
            (Some(count), _) => self.in_steps(f64::from(count), staff_size),
            (None, 2) => 0.5,
            (None, 3) => f64::from(0.2_f32),
            (None, _) => *increment,
        };
        *increment = steps;
        self.sign * steps
    }

    fn in_steps(&self, count: f64, staff_size: f64) -> f64 {
        let per_inch = match self.axis {
            Axis::Horizontal => P3_PER_INCH,
            Axis::Vertical => UNITS_PER_INCH / (UNITS_PER_STEP * staff_size),
        };
        match self.unit {
            Unit::Steps => count,
            Unit::Inches => count * per_inch,
            Unit::Centimetres => count * per_inch / CM_PER_INCH,
        }
    }
}

/// Codes whose P6 is a right end that moves with P3 (lines, slurs, beams, trills).
const RIGHT_END_X: [i32; 4] = [4, 5, 6, 7];
/// Codes whose P5 is a right end that moves with P4 (lines, slurs, beams).
const RIGHT_END_Y: [i32; 3] = [4, 5, 6];
/// Code 4's P5 = 999 keeps the right end level with the left; it is not moved.
const SAME_LEVEL: f32 = 999.0;

/// Adds `distance` to parameter `n`, rounding once to f32.
fn add(draft: &mut Draft, n: usize, distance: f64) {
    draft.set(n, (f64::from(draft.get(n)) + distance) as f32);
}

/// Moves an item by `distance` along `axis`, taking a right end along.
pub fn shift(draft: &mut Draft, axis: Axis, distance: f64) {
    let code = draft.code();
    match axis {
        Axis::Horizontal => {
            add(draft, 3, distance);
            if RIGHT_END_X.contains(&code) && draft.get(6) != 0.0 {
                add(draft, 6, distance);
            }
        }
        Axis::Vertical => {
            add(draft, 4, distance);
            if RIGHT_END_Y.contains(&code) && draft.get(5) != SAME_LEVEL {
                add(draft, 5, distance);
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn moved(word: &str, next: Option<f32>, increments: &mut Increments) -> f64 {
        Move::parse(word, next).unwrap().distance(increments, 1.0)
    }

    #[test]
    fn letters_counts_and_repeats() {
        let mut inc = Increments::default();
        assert_eq!(moved("R", None, &mut inc), 1.0);
        assert_eq!(moved("L10", None, &mut inc), -10.0);
        assert_eq!(moved("R", None, &mut inc), 10.0);
        assert_eq!(moved("RR", None, &mut inc), 0.5);
        assert_eq!(moved("L", None, &mut inc), -0.5);
        assert_eq!(moved("DDD", None, &mut inc) as f32, -0.2);
        assert_eq!(moved("U", Some(3.0), &mut inc), 3.0);
        assert_eq!(moved("D", None, &mut inc), -3.0);
    }

    #[test]
    fn inches_and_centimetres() {
        let mut inc = Increments::default();
        assert!((moved("RI", Some(1.0), &mut inc) - 26.666_666).abs() < 1e-4);
        let up = Move::parse("UI", Some(1.0)).unwrap().distance(&mut inc, 0.5);
        assert!((up - 45.714_286).abs() < 1e-4);
    }

    #[test]
    fn other_words_are_not_moves() {
        assert!(Move::parse("RHE", None).is_none());
        assert!(Move::parse("DE", None).is_none());
        assert!(Move::parse("RRRR", None).is_none());
        assert!(Move::parse("UND", None).is_none());
    }

    #[test]
    fn right_ends_move_with_the_item() {
        let mut line = Draft::new(&[4.0, 1.0, 50.0, 5.0, 10.0, 120.0]);
        shift(&mut line, Axis::Horizontal, 1.0);
        shift(&mut line, Axis::Vertical, 2.0);
        assert_eq!((line.get(3), line.get(4), line.get(5), line.get(6)), (51.0, 7.0, 12.0, 121.0));
        let mut hairpin = Draft::new(&[4.0, 1.0, 100.0, -1.0, 999.0, 120.0]);
        shift(&mut hairpin, Axis::Vertical, 2.0);
        assert_eq!(hairpin.get(5), 999.0);
        let mut note = Draft::new(&[1.0, 1.0, 100.0, 6.0, 10.0]);
        shift(&mut note, Axis::Vertical, 1.0);
        assert_eq!(note.get(5), 10.0);
    }
}
