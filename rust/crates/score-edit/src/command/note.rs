//! Edit-mode transformations of notes (code 1) and rests (code 2), after
//! the WinScore help pages code1.txt and code2.txt, checked against the engine.
//!
//! Code 1's P5 packs `[100 parentheses] + 10 × stem + accidental`, with the
//! accidental's offset after the decimal point; P9 packs `10 × dots + tails`.

use crate::params::Draft;

const STEM: usize = 5;
const HEAD: usize = 6;
const DURATION: usize = 7;
const STEM_LENGTH: usize = 8;
const DOTS_TAILS: usize = 9;
const LEVEL: usize = 4;
const MARK: usize = 11;
const DOT_LEVEL: usize = 19;

/// P11 values above this are tremolo strokes.
const TREMOLO: f32 = 40.0;

/// Cue-size notes and rests carry 100 in P4.
const CUE: f32 = 100.0;

/// The digits of a note's P5 that the edit commands look at.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct StemDigits {
    parentheses: bool,
    stem: u32,
    accidental: u32,
}

impl StemDigits {
    fn of(p5: f32) -> Self {
        let whole = p5.abs() as u32;
        Self { parentheses: whole / 100 % 10 == 1, stem: whole / 10 % 10, accidental: whole % 10 }
    }
}

pub const STEM_UP: u32 = 1;
pub const STEM_DOWN: u32 = 2;

/// FLI: stem up becomes stem down and back; stemless notes stay as they are.
pub fn flip_stem(draft: &mut Draft) {
    match StemDigits::of(draft.get(STEM)).stem {
        STEM_UP => draft.add(STEM, 10.0),
        STEM_DOWN => draft.add(STEM, -10.0),
        _ => {}
    }
}

/// NST: drops the stem digit, keeping accidental and parentheses.
pub fn remove_stem(draft: &mut Draft) {
    let stem = StemDigits::of(draft.get(STEM)).stem;
    draft.add(STEM, -10.0 * stem as f32);
}

/// FLT, SHP, NAT, DBF, DBS, NAC: the accidental digit, without parentheses.
pub fn set_accidental(draft: &mut Draft, accidental: Accidental) {
    let digits = StemDigits::of(draft.get(STEM));
    let parentheses = if digits.parentheses { 100.0 } else { 0.0 };
    draft.add(STEM, accidental.digit() as f32 - digits.accidental as f32 - parentheses);
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Accidental {
    None,
    Flat,
    Sharp,
    Natural,
    DoubleFlat,
    DoubleSharp,
}

impl Accidental {
    fn digit(self) -> u32 {
        self as u32
    }

    fn from_digit(digit: u32) -> Option<Self> {
        [Self::None, Self::Flat, Self::Sharp, Self::Natural, Self::DoubleFlat, Self::DoubleSharp]
            .get(digit as usize)
            .copied()
    }

    /// Semitones up from the plain letter.
    fn alteration(self) -> i32 {
        match self {
            Self::None | Self::Natural => 0,
            Self::Flat => -1,
            Self::Sharp => 1,
            Self::DoubleFlat => -2,
            Self::DoubleSharp => 2,
        }
    }

    /// The written accidental for an alteration; 0 is written as a natural.
    fn for_alteration(semitones: i32) -> Option<Self> {
        match semitones {
            -2 => Some(Self::DoubleFlat),
            -1 => Some(Self::Flat),
            0 => Some(Self::Natural),
            1 => Some(Self::Sharp),
            2 => Some(Self::DoubleSharp),
            _ => None,
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Spelling {
    /// ENH: sharps move up a letter, everything else down.
    Logical,
    Up,
    Down,
}

/// Semitones from the letter of scale step `step` to the letter above it (E–F and B–C are 1).
fn letter_gap_above(step: i32) -> i32 {
    match step.rem_euclid(7) {
        2 | 6 => 1,
        _ => 2,
    }
}

/// ENH, ENHU, ENHD: the same pitch spelled with the neighbouring letter.
/// Quarter-tone accidentals and spellings beyond double flat or sharp are left alone.
pub fn respell(draft: &mut Draft, spelling: Spelling) {
    let p5 = draft.get(STEM);
    let digits = StemDigits::of(p5);
    let Some(accidental) = Accidental::from_digit(digits.accidental) else { return };
    let up = match spelling {
        Spelling::Logical => accidental.alteration() > 0,
        Spelling::Up => true,
        Spelling::Down => false,
    };
    let level = draft.get(LEVEL);
    let step = level_within_hundred(level) as i32 - 1;
    let (shift, alteration) = if up {
        (1.0, accidental.alteration() - letter_gap_above(step))
    } else {
        (-1.0, accidental.alteration() + letter_gap_above(step - 1))
    };
    let Some(respelled) = Accidental::for_alteration(alteration) else { return };
    draft.set(LEVEL, level + shift);
    draft.add(STEM, respelled.digit() as f32 - digits.accidental as f32);
}

/// P4 without the hundreds that mark cue size (amod, as item_position 0x5479AB).
fn level_within_hundred(level: f32) -> f32 {
    level - (level / CUE).trunc() * CUE
}

/// STM, STP: half a step shorter or longer.
pub fn lengthen_stem(draft: &mut Draft, steps: f32) {
    draft.add(STEM_LENGTH, steps);
}

pub fn normal_stem(draft: &mut Draft) {
    draft.set(STEM_LENGTH, 0.0);
}

/// A plain note value: P6 head, P7 duration in quarters, number of tails (notes)
/// or P5 rest symbol (rests).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Rhythm {
    pub head: f32,
    pub duration: f32,
    pub tails: f32,
    pub rest_symbol: f32,
}

pub const DOUBLE_WHOLE: Rhythm = Rhythm { head: 3.0, duration: 8.0, tails: 0.0, rest_symbol: -3.0 };
pub const WHOLE: Rhythm = Rhythm { head: 2.0, duration: 4.0, tails: 0.0, rest_symbol: -2.0 };
pub const HALF: Rhythm = Rhythm { head: 1.0, duration: 2.0, tails: 0.0, rest_symbol: -1.0 };
pub const QUARTER: Rhythm = Rhythm { head: 0.0, duration: 1.0, tails: 0.0, rest_symbol: 0.0 };
pub const EIGHTH: Rhythm = Rhythm { head: 0.0, duration: 0.5, tails: 1.0, rest_symbol: 1.0 };
pub const SIXTEENTH: Rhythm = Rhythm { head: 0.0, duration: 0.25, tails: 2.0, rest_symbol: 2.0 };
pub const THIRTY_SECOND: Rhythm = Rhythm { head: 0.0, duration: 0.125, tails: 3.0, rest_symbol: 3.0 };
pub const SIXTY_FOURTH: Rhythm = Rhythm { head: 0.0, duration: 0.0625, tails: 4.0, rest_symbol: 4.0 };

/// RHW, RHQ, RHE, …: head, duration and tails; dots are dropped.
pub fn set_note_rhythm(draft: &mut Draft, rhythm: Rhythm) {
    draft.set(HEAD, rhythm.head);
    draft.set(DURATION, rhythm.duration);
    draft.set(DOTS_TAILS, rhythm.tails);
}

pub fn set_rest_rhythm(draft: &mut Draft, rhythm: Rhythm) {
    draft.set(STEM, rhythm.rest_symbol);
    draft.set(DURATION, rhythm.duration);
}

fn dots(draft: &Draft) -> u32 {
    draft.get(DOTS_TAILS).abs() as u32 / 10 % 10
}

/// The duration factor of `dots` augmentation dots.
fn dot_factor(dots: u32) -> f32 {
    match dots {
        2 => 1.75,
        _ => 1.5,
    }
}

/// The duration with `wanted` dots instead of `had`. The engine undoes the
/// other kind of dotting first, but not its own: DOT on a dotted value
/// multiplies by 1.5 again.
fn dotted(duration: f32, had: u32, wanted: u32) -> f32 {
    let undotted = if had != 0 && had != wanted { duration / dot_factor(had) } else { duration };
    undotted * dot_factor(wanted)
}

/// DOT, DDT on a note: P7 becomes the dotted value, P9's dot digit the number of dots.
pub fn set_dots(draft: &mut Draft, wanted: u32) {
    let had = dots(draft);
    draft.set(DURATION, dotted(draft.get(DURATION), had, wanted));
    draft.add(DOTS_TAILS, 10.0 * (wanted as f32 - had as f32));
}

/// DOT, DDT on a rest, which keeps the number of dots in P6.
pub fn set_rest_dots(draft: &mut Draft, wanted: u32) {
    let had = draft.get(HEAD).abs() as u32;
    draft.set(DURATION, dotted(draft.get(DURATION), had, wanted));
    draft.set(HEAD, wanted as f32);
}

/// NOD: no dots; the duration stays, and so does the dot spacing.
pub fn remove_dots(draft: &mut Draft) {
    draft.add(DOTS_TAILS, -10.0 * dots(draft) as f32);
    draft.set(DOT_LEVEL, 0.0);
}

/// SPA: accidentals only.
pub fn space_accidental(draft: &mut Draft, delta: f32) {
    if StemDigits::of(draft.get(STEM)).accidental != 0 {
        draft.add(STEM, delta);
    }
}

/// NOS: the accidental back at its normal place.
pub fn unspace_accidental(draft: &mut Draft) {
    let p5 = draft.get(STEM);
    if StemDigits::of(p5).accidental != 0 {
        draft.set(STEM, p5.trunc());
    }
}

/// TM1, TRMn: a tremolo of `beams` strokes in P11 (40 + n); TM+ adds one.
pub fn tremolo(draft: &mut Draft, beams: Option<f32>) {
    let current = draft.get(MARK);
    let value = match beams {
        Some(n) => TREMOLO + n,
        None if (TREMOLO + 1.0..TREMOLO + 9.0).contains(&current) => current + 1.0,
        None => TREMOLO + 1.0,
    };
    draft.set(MARK, value);
}

/// RH3, RH5, RH6, RH10, RH12, …: the duration of an n-tuplet note (4/n quarters),
/// with the head and tails of the plain value it replaces.
pub fn set_tuplet_rhythm(draft: &mut Draft, per_whole: f32) {
    let plain = [DOUBLE_WHOLE, WHOLE, HALF, QUARTER, EIGHTH, SIXTEENTH, THIRTY_SECOND, SIXTY_FOURTH]
        .into_iter()
        .rev()
        .find(|r| 4.0 / r.duration <= per_whole)
        .unwrap_or(DOUBLE_WHOLE);
    set_note_rhythm(draft, Rhythm { duration: 4.0 / per_whole, ..plain });
}

/// Durations that TRP and RHU accept: whole powers of two of a quarter.
fn is_plain_duration(duration: f32) -> bool {
    duration > 0.0 && duration.log2().fract() == 0.0
}

/// TRP (2/3) and RHU (4/5): tuplet durations, only from a plain value.
pub fn tuplet(draft: &mut Draft, numerator: f32, denominator: f32) {
    let duration = draft.get(DURATION);
    if is_plain_duration(duration) {
        draft.set(DURATION, duration * numerator / denominator);
    }
}

/// ADT, NTA: one more tail, or none; the duration stays.
pub fn add_tail(draft: &mut Draft) {
    draft.add(DOTS_TAILS, 1.0);
}

pub fn remove_tails(draft: &mut Draft) {
    let tails = draft.get(DOTS_TAILS).abs() as u32 % 10;
    draft.add(DOTS_TAILS, -(tails as f32));
}

/// CUE, CUX: 100 added to or taken from P4 (away from zero for negative levels).
pub fn set_cue(draft: &mut Draft, cue: bool) {
    let level = draft.get(LEVEL);
    if (level.abs() >= CUE) == cue {
        return;
    }
    let direction = if level < 0.0 { -1.0 } else { 1.0 };
    let change = if cue { CUE } else { -CUE };
    draft.set(LEVEL, level + change * direction);
}

/// RHG: a grace note of the engine's default shape.
pub fn make_grace(draft: &mut Draft) {
    set_cue(draft, true);
    draft.set(DURATION, 65.0);
    draft.set(STEM_LENGTH, 101.0);
    draft.set(DOTS_TAILS, 1.0);
}

#[cfg(test)]
mod tests {
    use super::*;

    fn note(p5: f32, p4: f32) -> Draft {
        Draft::new(&[1.0, 1.0, 100.0, p4, p5, 0.0, 1.0])
    }

    #[test]
    fn flip_keeps_accidental_and_offset() {
        let mut d = note(12.25, 6.0);
        flip_stem(&mut d);
        assert_eq!(d.get(5), 22.25);
        let mut stemless = note(2.0, 6.0);
        flip_stem(&mut stemless);
        assert_eq!(stemless.get(5), 2.0);
    }

    #[test]
    fn accidentals_drop_parentheses_but_keep_the_offset() {
        let mut d = note(111.3, 6.0);
        set_accidental(&mut d, Accidental::Sharp);
        assert_eq!(d.get(5), 12.300_003, "f32 arithmetic, as the engine's 12.3000031");
        let mut e = note(112.25, 6.0);
        set_accidental(&mut e, Accidental::None);
        assert_eq!(e.get(5), 10.25);
    }

    fn respelled(p4: f32, p5: f32, spelling: Spelling) -> (f32, f32) {
        let mut d = note(p5, p4);
        respell(&mut d, spelling);
        (d.get(4), d.get(5))
    }

    #[test]
    fn enharmonics_as_the_engine_spells_them() {
        assert_eq!(respelled(6.0, 12.0, Spelling::Logical), (7.0, 11.0)); // A# -> Bb
        assert_eq!(respelled(6.0, 11.0, Spelling::Logical), (5.0, 12.0)); // Ab -> G#
        assert_eq!(respelled(6.0, 10.0, Spelling::Logical), (5.0, 15.0)); // A -> G##
        assert_eq!(respelled(3.0, 12.0, Spelling::Logical), (4.0, 13.0)); // E# -> F natural
        assert_eq!(respelled(1.0, 10.0, Spelling::Logical), (0.0, 12.0)); // C -> B#
        assert_eq!(respelled(104.0, 12.0, Spelling::Logical), (105.0, 11.0));
        assert_eq!(respelled(6.0, 11.0, Spelling::Up), (6.0, 11.0)); // Ab has no upper spelling
        assert_eq!(respelled(6.0, 10.0, Spelling::Up), (7.0, 14.0)); // A -> Bbb
    }

    #[test]
    fn dots_follow_the_engine() {
        let mut d = note(10.0, 6.0);
        set_dots(&mut d, 1);
        assert_eq!((d.get(7), d.get(9)), (1.5, 10.0));
        set_dots(&mut d, 1);
        assert_eq!((d.get(7), d.get(9)), (2.25, 10.0));
        let mut dd = Draft::new(&[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.75, 0.0, 20.0]);
        set_dots(&mut dd, 1);
        assert_eq!((dd.get(7), dd.get(9)), (1.5, 10.0));
    }

    #[test]
    fn tuplets_only_from_plain_values() {
        let mut d = Draft::new(&[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 0.75]);
        tuplet(&mut d, 2.0, 3.0);
        assert_eq!(d.get(7), 0.75);
        let mut e = Draft::new(&[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 0.25]);
        tuplet(&mut e, 2.0, 3.0);
        assert_eq!(e.get(7), 1.0 / 6.0);
    }

    #[test]
    fn cue_size_toggles_the_hundreds() {
        let mut d = note(10.0, 6.0);
        set_cue(&mut d, true);
        assert_eq!(d.get(4), 106.0);
        set_cue(&mut d, true);
        assert_eq!(d.get(4), 106.0);
        set_cue(&mut d, false);
        assert_eq!(d.get(4), 6.0);
        let mut low = note(10.0, -3.0);
        set_cue(&mut low, true);
        assert_eq!(low.get(4), -103.0);
    }
}
