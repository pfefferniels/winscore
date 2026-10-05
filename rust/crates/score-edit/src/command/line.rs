//! Edit-mode transformations of lines and hairpins (code 4), slurs and
//! brackets (code 5) and beams (code 6), after code4.txt–code6.txt, checked
//! against the engine.

use crate::params::Draft;

const OFFSET_FLAG: usize = 16;
const LEFT_OFFSET: usize = 17;
const RIGHT_OFFSET: usize = 18;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum End {
    Left,
    Right,
}

impl End {
    fn param(self) -> usize {
        match self {
            End::Left => LEFT_OFFSET,
            End::Right => RIGHT_OFFSET,
        }
    }

    fn other(self) -> End {
        match self {
            End::Left => End::Right,
            End::Right => End::Left,
        }
    }
}

/// LOFFP, ROFFM, …: shift one end by `delta`, switching end offsets on in P16;
/// LOFF0, ROFF0: zero it, and P16 too once neither end is offset.
pub fn offset_end(draft: &mut Draft, end: End, delta: Option<f32>) {
    match delta {
        Some(delta) => {
            if draft.get(OFFSET_FLAG) == 0.0 {
                draft.set(OFFSET_FLAG, 1.0);
            }
            draft.add(end.param(), delta);
        }
        None => {
            draft.set(end.param(), 0.0);
            if draft.get(end.other().param()) == 0.0 {
                draft.set(OFFSET_FLAG, 0.0);
            }
        }
    }
}

/// Code 7 offsets its right end by P18, switched on with P16 = 1 (ROFFP, ROFF n);
/// its left end by P15 alone.
pub fn offset_trill_right(draft: &mut Draft, to: Offset) {
    draft.set(OFFSET_FLAG, 1.0);
    match to {
        Offset::By(delta) => draft.add(RIGHT_OFFSET, delta),
        Offset::To(value) => draft.set(RIGHT_OFFSET, value),
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Offset {
    By(f32),
    To(f32),
}

/// SPD+1, SPD-: hairpin spread in P7, whose sign gives the direction; up to
/// 1 counts as the default 2.3.
pub fn spread_hairpin(draft: &mut Draft, delta: f32) {
    let p7 = draft.get(7);
    let spread = if p7.abs() <= 1.0 { DEFAULT_SPREAD } else { p7.abs() };
    let sign = if p7 < 0.0 { -1.0 } else { 1.0 };
    draft.set(7, sign * (spread + delta));
}

const DEFAULT_SPREAD: f32 = 2.3;

/// VERT: a vertical line of ten steps up from the left end.
pub fn make_vertical(draft: &mut Draft) {
    draft.set(6, draft.get(3));
    draft.set(5, draft.get(4) + 10.0);
}

/// SLTRIP: a triplet number on the slur (P16 = 3), or off again together with
/// the tuplet number, its offset and its font (P8, P9, P14).
pub fn toggle_triplet(draft: &mut Draft) {
    if draft.get(16) == 0.0 {
        draft.set(16, 3.0);
    } else {
        [8, 9, 14, 16].into_iter().for_each(|n| draft.set(n, 0.0));
    }
}

/// NUML, NUMR, NUMU, NUMD: the tuplet number's offset (P17, P18), only on
/// slurs that carry a number in P8.
pub fn move_number(draft: &mut Draft, dx: f32, dy: f32) {
    if draft.get(8) != 0.0 {
        draft.add(17, dx);
        draft.add(18, dy);
    }
}

/// TRMn on a beam: a tremolo of n strokes (P7 = -10, P10 = 10 + n).
pub fn beam_tremolo(draft: &mut Draft, strokes: f32) {
    draft.set(7, -10.0);
    draft.set(10, 10.0 + strokes);
}

/// Slurs whose P8 is 1 or more (endings, tuplet brackets) keep their P7 under CR.
const BRACKETS_FROM: f32 = 1.0;

/// CR on a slur (0x42C51C): 0.9 plus a twentieth of its length (ties a
/// little shorter) plus a tenth of its rise, downwards for a slur below.
pub fn default_curve(draft: &mut Draft) {
    let e = |k: usize| draft.get(k);
    if e(8) >= BRACKETS_FROM {
        return;
    }
    let length = e(6) - e(3);
    let length = if -4.0 < e(8) && e(8) < -1.0 { e(8) * 2.0 + length } else { length };
    let base = f64::from(length) / 20.0 + f64::from(0.9_f32);
    let curve = (f64::from((e(5) - e(4)).abs()) * f64::from(0.1_f32) + base) as f32;
    draft.set(7, if e(7) < 0.0 { -curve } else { curve });
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn end_offsets_switch_p16() {
        let mut line = Draft::new(&[4.0, 1.0, 50.0, 5.0, 10.0, 120.0]);
        offset_end(&mut line, End::Left, Some(0.5));
        offset_end(&mut line, End::Right, Some(-0.5));
        assert_eq!((line.get(16), line.get(17), line.get(18)), (1.0, 0.5, -0.5));
        offset_end(&mut line, End::Left, None);
        assert_eq!(line.get(16), 1.0);
        offset_end(&mut line, End::Right, None);
        assert_eq!(line.get(16), 0.0);
    }

    #[test]
    fn triplet_toggles_with_its_number() {
        let mut slur = Draft::new(&[5.0, 1.0, 50.0, 5.0, 10.0, 120.0, 2.0, 3.0, 0.5, 0.0, 0.0, 0.0, 0.0, 4.0, 0.0, 3.0]);
        toggle_triplet(&mut slur);
        assert_eq!((slur.get(7), slur.get(8), slur.get(14), slur.get(16)), (2.0, 0.0, 0.0, 0.0));
        toggle_triplet(&mut slur);
        assert_eq!(slur.get(16), 3.0);
    }
}
