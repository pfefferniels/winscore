//! Layout inside a chord: accidentals moved left so they do not collide (0x4EE442) and
//! augmentation dots moved down or right next to seconds (0x51C824).

/// Clearance in thousandths of P5 (i.e. hundredths of a step) that an accidental needs
/// to the left of the accidental above it: `[gap][other][this]`, where gap is the
/// distance in steps minus one (at least 1), `other` the accidental below (double flat
/// counted as flat, double sharp as the fourth column) and `this` the accidental above.
/// Table at 0x794D04 (Fortran order T(this, other, gap)).
const CLEARANCE: [[[i32; 5]; 4]; 6] = [
    [[240, 250, 215, 440, 250], [240, 290, 240, 440, 300], [240, 255, 220, 430, 280], [250, 280, 240, 500, 330]],
    [[155, 250, 180, 380, 200], [240, 290, 230, 440, 250], [200, 250, 160, 420, 180], [0, 280, 160, 0, 0]],
    [[155, 200, 120, 360, 180], [180, 220, 110, 400, 0], [130, 200, 120, 320, 140], [0, 0, 0, 0, 0]],
    [[120, 180, 120, 350, 160], [0, 200, 110, 0, 0], [0, 120, 0, 0, 0], [0, 0, 0, 0, 0]],
    [[0, 110, 0, 0, 0], [0; 5], [0; 5], [0; 5]],
    [[0; 5]; 4],
];
/// Steps an accidental reaches above and below its note (0x794CF3, 0x794CFB), by P5 code 1-5.
const REACH_ABOVE: [i32; 5] = [5, 4, 4, 5, 1];
const REACH_BELOW: [i32; 5] = [1, 3, 3, 1, 1];
/// Offset of the accidental of a head moved to the left of the stem.
const LEFT_HEAD_OFFSET: i32 = 283;
const DOUBLE_FLAT: i32 = 4;
const MAX_OFFSET: i32 = 899;

/// One head as the accidental layout sees it.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct ChordHead {
    pub level: i32,
    /// P5 accidental code, 0 for none.
    pub accidental: i32,
    /// Moved to the left of a down stem (P10 = 20).
    pub left_of_stem: bool,
}

/// Width of an accidental in the stacking sequence (0x4EE442, 240 or 440 for a double flat).
fn width(accidental: i32) -> i32 {
    if accidental == DOUBLE_FLAT {
        440
    } else {
        240
    }
}

fn clearance(this: i32, other: i32, gap: i32) -> i32 {
    let row = (gap - 1).max(1) as usize - 1;
    let column = match other {
        4 => 1,
        5 => 4,
        a => a,
    } as usize
        - 1;
    CLEARANCE[row][column][this as usize - 1]
}

/// Leftward offset of each head's accidental in thousandths of P5, heads given from the top.
pub fn accidental_offsets(heads: &[ChordHead]) -> Vec<i32> {
    let n = heads.len();
    let acc = |i: usize| heads[i].accidental;
    let low = |i: usize| heads[i].level - REACH_BELOW[(acc(i) - 1) as usize];
    let high = |i: usize| heads[i].level + REACH_ABOVE[(acc(i) - 1) as usize];
    let base: Vec<i32> = heads.iter().map(|h| if h.left_of_stem { LEFT_HEAD_OFFSET } else { 0 }).collect();
    let mut offset = base.clone();

    // An accidental reaching a head left of the stem must clear that head.
    for i in (0..n).filter(|&i| acc(i) != 0 && base[i] == 0) {
        let blocked = (0..n).any(|j| j != i && base[j] != 0 && (low(i)..=high(i)).contains(&heads[j].level));
        if blocked {
            offset[i] = LEFT_HEAD_OFFSET;
        }
    }

    // From the top: each accidental pushes the closest-fitting accidental below it.
    let mut i = 0;
    while i < n {
        if acc(i) != 0 {
            let candidate = (i + 1..n).filter(|&j| acc(j) > 0).fold(None::<(usize, i32)>, |best, j| {
                let gap = heads[i].level - heads[j].level;
                let value = if gap < 7 { clearance(acc(i), acc(j), gap) } else { 0 };
                match best {
                    Some((_, b)) if b <= value => best,
                    _ => Some((j, value)),
                }
            });
            if let Some((j, value)) = candidate {
                let pushed = value + offset[i];
                offset[j] = offset[j].max(pushed);
                let mut run = pushed;
                for k in (i + 1..j).filter(|&k| acc(k) != 0) {
                    run += width(acc(k));
                    offset[k] = offset[k].max(run);
                }
                i = j;
                continue;
            }
        }
        i += 1;
    }

    // Overlapping accidentals that ended up too close are spread further.
    for i in 0..n {
        let own = offset[i];
        if acc(i) == 0 || own == 0 {
            continue;
        }
        for j in (i + 1..n).filter(|&j| acc(j) != 0) {
            if high(j) <= low(i) {
                break;
            }
            let other = offset[j];
            let mut difference = own - other;
            if acc(j) == DOUBLE_FLAT {
                difference -= 200;
            }
            if difference.abs() >= width(1) {
                continue;
            }
            let value = clearance(acc(i), acc(j), heads[i].level - heads[j].level);
            if difference <= 0 {
                offset[j] = value + own;
                continue;
            }
            let limit = if acc(j) == DOUBLE_FLAT { 0 } else { 200 };
            if other == 0 || limit < own - other || value > 200 {
                let spread = width(acc(j)) - (own - other);
                if spread > 0 {
                    for k in (i..j).filter(|&k| acc(k) != 0) {
                        if offset[k] != 0 {
                            offset[k] += spread;
                        }
                    }
                }
            } else {
                offset[j] = value + own;
            }
            break;
        }
    }

    offset.iter().zip(&base).map(|(o, b)| (o - b).clamp(0, MAX_OFFSET)).collect()
}

/// P9 addition that puts a dot below its line.
pub const DOT_BELOW: i32 = 100;
/// P9 addition that moves a dot one head width to the right.
const DOT_RIGHT: i32 = 1000;

fn below(add: i32) -> i32 {
    if add >= DOT_BELOW {
        add
    } else {
        add + DOT_BELOW
    }
}

/// P9 additions for the dots of a dotted chord (0x51C824). Heads in item order (stem head
/// first), with `shifted` telling which heads sit on the other side of the stem; a lower
/// voice (SD) starts with every dot below its line. Only chords with seconds are laid out.
pub fn dot_offsets(levels: &[i32], shifted: &[bool], down: bool, lower_voice: bool) -> Vec<i32> {
    let n = levels.len();
    let mut add = vec![if lower_voice { DOT_BELOW } else { 0 }; n];
    let Some(first_shifted) = shifted.iter().position(|s| *s).filter(|_| n >= 2) else {
        return add;
    };
    let mut stacked = false;
    if down {
        if first_shifted > 0 {
            add[first_shifted - 1] = 0;
        }
        for k in 1..n {
            if shifted[k] {
                add[k] = below(add[k]) + DOT_RIGHT;
                stacked = true;
            } else if levels[k - 1] - levels[k] > 2 {
                stacked = false;
            } else if stacked {
                add[k] = below(add[k]);
            }
        }
    } else {
        for k in (0..n).rev() {
            if shifted[k] {
                stacked = true;
                continue;
            }
            let mut lowered = false;
            if k != n - 1 {
                if levels[k + 1] - levels[k] <= 2 {
                    lowered = stacked;
                } else {
                    stacked = false;
                }
            }
            add[k] = if lowered { below(add[k]) } else { add[k] } + DOT_RIGHT;
        }
    }
    add
}

#[cfg(test)]
mod tests {
    use super::*;

    fn head(level: i32, accidental: i32) -> ChordHead {
        ChordHead { level, accidental, left_of_stem: false }
    }

    #[test]
    fn accidental_stacking_matches_the_engine() {
        // C#4:Eb4:G4 -> 12.24 on C#; C#4:D#4 -> 12.29; Eb3:G3:Bb3 in bass -> 1.155 on Eb.
        assert_eq!(accidental_offsets(&[head(5, 0), head(3, 1), head(1, 2)]), [0, 0, 240]);
        assert_eq!(accidental_offsets(&[head(2, 2), head(1, 2)]), [0, 290]);
        assert_eq!(accidental_offsets(&[head(12, 1), head(10, 0), head(8, 1)]), [0, 0, 155]);
    }

    #[test]
    fn dots_next_to_seconds() {
        // C4:D:E up: C4 1110 (dot below, right), D 10, E 1010.
        assert_eq!(dot_offsets(&[1, 2, 3], &[false, true, false], false, false), [1100, 0, 1000]);
        // E5:D5:C5 down: E5 10, D5 1110, C5 110.
        assert_eq!(dot_offsets(&[10, 9, 8], &[false, true, false], true, false), [0, 1100, 100]);
        // SD/C4:F:G:A: the head after the gap keeps the lower voice's dot.
        assert_eq!(dot_offsets(&[6, 5, 4, 1], &[false, true, false, false], true, true), [0, 1100, 100, 100]);
    }
}
