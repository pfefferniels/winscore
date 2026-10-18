//! Horizontal positions (P3) of the entries of an input line, as pass 2 computes them
//! (without a spacing staff) followed by the minimum-gap pass.
//!
//! Every chord member is an entry of its own, sharing the chord's position; that matters
//! for the minimum-gap pass, which never moves the very last entry.

use crate::notes::{KeySignature, Meter};

/// One entry of the engine's work table, as far as spacing is concerned.
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Entry {
    /// A note, or one member of a chord; `first` marks the first member.
    Note { quarters: f32, accidental: bool, first: bool },
    Rest { quarters: f32 },
    Clef,
    Bar,
    Key(KeySignature),
    /// A meter, and the duration it counts for: 0 unless it is a misread note token.
    Meter(Meter, f32),
}

/// Spacing units of a grace note in the duration sum.
pub const GRACE_DURATION: f32 = 0.1;

const MIN_GAP: f32 = 3.0;
const MIN_KEPT_GAP: f32 = 3.6;

impl Entry {
    /// The engine's item code (P1).
    fn code(self) -> i32 {
        match self {
            Entry::Note { .. } => 1,
            Entry::Rest { .. } => 2,
            Entry::Clef => 3,
            Entry::Bar => 14,
            Entry::Key(_) => 17,
            Entry::Meter(..) => 18,
        }
    }

    fn is_timed(self) -> bool {
        self.code() <= 2
    }

    /// Duration counted once per chord.
    fn duration(self) -> f32 {
        match self {
            Entry::Note { quarters, first: true, .. } | Entry::Rest { quarters } | Entry::Meter(_, quarters) => quarters,
            _ => 0.0,
        }
    }
}

/// Meters whose P5 or P6 has two digits; C and alla breve are stored as 99 and 98.
fn big_meter(meter: Meter) -> bool {
    match meter {
        Meter::Common | Meter::Cut => true,
        Meter::Fraction(top, bottom) => top >= 10 || bottom >= 10,
    }
}

fn key_count(key: KeySignature) -> f32 {
    f32::from(key.count)
}

/// Width of a non-note entry (before scaling by the staff size); pass 2's widths loop.
fn width(entries: &[Entry], j: usize, last: usize) -> f32 {
    let next = entries.get(j + 1).copied();
    let next_code = next.map_or(0, Entry::code);
    match entries[j] {
        Entry::Key(key) => {
            let narrower = if j < last && matches!(next, Some(Entry::Meter(..))) { 0.3 } else { 0.0 };
            key_count(key) * 2.8 + 2.0 - narrower
        }
        _ if j == last => 0.0,
        Entry::Bar => match next {
            Some(Entry::Note { accidental: true, .. }) => 4.5,
            _ if next_code == 3 || next_code > 16 => 1.5,
            _ => 3.5,
        },
        Entry::Meter(meter, _) => {
            if big_meter(meter) {
                9.0
            } else {
                7.0
            }
        }
        _ => {
            let base = if j < 2 { 9.0 } else { 8.0 };
            if next_code > 16 {
                base + (next_code - 19) as f32
            } else {
                base
            }
        }
    }
}

/// P3 of every entry for the input range `begin..end` on a staff of size factor `size`.
pub fn positions(entries: &[Entry], begin: f32, end: f32, size: f32) -> Vec<f32> {
    let mut x = vec![0.0f32; entries.len()];

    // Trailing key signatures and meters are set from the right end.
    let mut end = end;
    let mut extra = 0.0f32;
    let mut n = entries.len();
    while let Some(entry @ (Entry::Key(_) | Entry::Meter(..))) = n.checked_sub(1).map(|i| entries[i]) {
        let (w, e) = match entry {
            Entry::Meter(meter, _) if big_meter(meter) => (7.0, 1.5),
            Entry::Meter(..) => (4.0, 1.5),
            Entry::Key(key) => (key_count(key) * 2.8 + 0.5, 2.5),
            _ => unreachable!(),
        };
        end -= size * w;
        x[n - 1] = end;
        extra = e;
        n -= 1;
    }
    end -= size * extra;
    if n == 0 {
        return x;
    }
    let body = &entries[..n];
    let last = n - 1;

    let total: f32 = entries.iter().map(|e| e.duration()).sum();
    let mut widths = vec![0.0f32; n];
    let mut avail = end - begin;
    for j in 0..n {
        if body[j].is_timed() {
            continue;
        }
        if matches!(body[j], Entry::Key(_)) && j > 0 && !body[j - 1].is_timed() {
            widths[j - 1] += size;
        }
        let w = size * width(body, j, last);
        avail -= w;
        widths[j] = w;
    }

    let mut cursor = begin;
    for j in 0..n {
        let entry = body[j];
        if let Entry::Note { first: false, .. } = entry {
            x[j] = x[j - 1];
            continue;
        }
        if entry.is_timed() {
            x[j] = cursor;
            if total > 0.0 {
                cursor += (entry.duration() / total) * avail;
            }
            continue;
        }
        let w = widths[j];
        if j == last {
            cursor = end;
        }
        if j > 0 && body[j - 1].is_timed() && entry != Entry::Bar {
            let share = w / 3.0;
            avail += share;
            cursor -= share;
        }
        x[j] = cursor;
        cursor += w;
    }

    // A clef after notes sits seven steps before the next entry when there is room.
    for j in 1..last {
        if body[j] == Entry::Clef && body[j - 1] != Entry::Bar {
            let room = x[j + 1] - x[j - 1];
            if size * 7.0 + 0.625 <= room {
                x[j] = x[j + 1] - size * 7.0;
            }
        }
    }

    enforce_minimum_gaps(&mut x, begin);
    x
}

/// Gaps below 3 become 3 at the expense of the wide gaps. The last entry is never
/// moved (the engine's copy loop stops one short), so the gap before it may stay small.
fn enforce_minimum_gaps(x: &mut [f32], begin: f32) {
    let gaps: Vec<f32> = x.windows(2).map(|w| w[1] - w[0]).collect();
    let ok: f32 = gaps.iter().filter(|g| **g >= MIN_GAP || **g == 0.0).sum();
    let deficit: f32 = gaps.iter().filter(|g| !(**g >= MIN_GAP || **g == 0.0)).map(|g| MIN_GAP - g).sum();
    if deficit == 0.0 {
        return;
    }
    let factor = (ok - deficit) / ok;
    if factor <= 0.0 {
        return;
    }
    let rebuilt: Vec<f32> = gaps
        .iter()
        .scan(begin, |at, &g| {
            *at += if g >= MIN_KEPT_GAP {
                factor * g
            } else if g == 0.0 {
                0.0
            } else {
                MIN_GAP
            };
            Some(*at)
        })
        .collect();
    let moved = x.len().saturating_sub(2);
    x[1..=moved].copy_from_slice(&rebuilt[..moved]);
}

#[cfg(test)]
mod tests {
    use super::*;

    fn quarter() -> Entry {
        Entry::Note { quarters: 1.0, accidental: false, first: true }
    }

    #[test]
    fn mid_line_clef_shares_the_space_of_the_note_before() {
        let entries = [quarter(), quarter(), Entry::Clef, quarter(), quarter()];
        let x = positions(&entries, 2.0, 200.0, 1.0);
        let expected = [2.0, 49.5, 95.333, 102.333, 150.5];
        assert!(x.iter().zip(expected).all(|(a, b)| (a - b).abs() < 1e-3), "{x:?}");
    }

    #[test]
    fn short_notes_get_three_units_but_the_last_entry_stays() {
        let entries: Vec<Entry> = [4.0, 2.0, 1.0, 0.5, 0.25, 0.125, 0.0625, 8.0]
            .map(|q| Entry::Note { quarters: q, accidental: false, first: true })
            .to_vec();
        let x = positions(&entries, 2.0, 200.0, 1.0);
        let expected = [2.0, 49.7996, 73.6994, 85.6493, 91.6243, 94.6243, 97.6243, 100.6118];
        assert!(x.iter().zip(expected).all(|(a, b)| (a - b).abs() < 1e-3), "{x:?}");
    }
}
