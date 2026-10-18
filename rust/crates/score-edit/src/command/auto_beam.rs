//! AUTO, AUTOX and SPLn on a beam in edit mode: the secondary beams from
//! the notes' durations, then the stem pass.
//!
//! The smallest beam count of the notes becomes the beam's P7 units digit;
//! the next level's first run goes into P10..P12, the run after it into
//! P13..P15, and further runs into copies of the beam inserted after it.
//! SPLn breaks the inner beams after given notes.

use crate::params::Draft;

const NOTE: i32 = 1;
/// The edit buffer the engine works in holds this many parameters.
const BUFFER: usize = 30;
/// The highest parameter a stored beam keeps.
const LAST_KEPT: usize = 21;
/// A note's position may lie this far outside the beam's ends.
const REACH: f32 = 0.04;
/// Longer notes end the scan (an eighth and a little).
const LONGEST: f32 = 0.5001;
/// Beam counts by duration: below each limit the count given, else 1.
const COUNTS: [(f32, f32); 5] = [(0.0157, 6.0), (0.0313, 5.0), (0.0626, 4.0), (0.1251, 3.0), (0.2501, 2.0)];
/// Grace notes (P7 >= 64) count as sixteenths.
const GRACE_VALUE: f32 = 0.25;
/// A beam with fewer than two notes flips its direction by this many steps once.
const FLIP: f32 = 13.0;
/// Added to a level once its run is written.
const DONE: f32 = 100.0;
/// No level.
const NONE: f32 = 99.0;
/// The x of the break SPL inserts after a note.
const BREAK_GAP: f32 = 0.2;
/// Copies of the beam have at least this many parameters.
const COPY_MIN: usize = 12;

/// The word that ran.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Word {
    Auto,
    /// Notes with stems against the beam take part too.
    AutoX,
    Split(u32),
}

impl Word {
    pub fn parse(word: &str) -> Option<Self> {
        match word {
            "AUTO" => Some(Word::Auto),
            "AUTOX" => Some(Word::AutoX),
            _ => word.strip_prefix("SPL")?.parse().ok().map(Word::Split),
        }
    }
}

/// The file after the word: `items` with the beam (at its old index) and
/// its notes' levels rewritten, the copies of the beam to insert after it,
/// and the beam the stem pass then fits the notes to.
#[derive(Debug, Clone, PartialEq)]
pub struct Outcome {
    pub items: Vec<Draft>,
    pub inserted: Vec<Draft>,
    pub stem_beam: Option<Draft>,
}

/// SPL n: the rows after which a break goes (0 for none), or `None` when the
/// number asks for no change. A two-digit n is read as n * 10 + 9.
fn split_points(n: u32) -> Option<[usize; 4]> {
    let n = if (10..100).contains(&n) { n * 10 + 9 } else { n };
    if n < 100 {
        return Some([0, 0, 0, n as usize]);
    }
    let (a, t, t2, u) = (n / 1000, n % 1000 / 100, n % 100 / 10, n % 10);
    if t == 0 || t2 == 0 || u == 0 {
        return None;
    }
    let b = t + a + u32::from(a > 0);
    let c = t2 + b + 1;
    Some([a, b, c, c + u + 1].map(|v| v as usize))
}

fn beam_count(duration: f32) -> f32 {
    COUNTS.iter().find(|&&(limit, _)| duration < limit).map_or(1.0, |&(_, n)| n)
}

fn amod(x: f32, y: f32) -> f32 {
    x - (x / y).trunc() * y
}

fn away_from_zero(v: f32, by: f32) -> f32 {
    (if v < 0.0 { -by } else { by }) + v
}

fn stem_digit(note: &Draft) -> i32 {
    (note.get(5).trunc() as i32 % 100) / 10
}

/// A note as the beam sees it: x, level and its beam count.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Row {
    x: f32,
    level: f32,
    count: f32,
}

/// Where a stored beam goes: the beam itself or one of the copies.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Target {
    Edit,
    Copy(usize),
}

struct AutoBeam {
    items: Vec<Draft>,
    edit: usize,
    /// The edit buffer, 1-based.
    e: Vec<f32>,
    inserted: Vec<Draft>,
}

/// Runs `word` on the beam at `edit` in `items`; `None` when the engine
/// refuses before touching anything.
pub fn run(items: &[Draft], edit: usize, word: Word) -> Option<Outcome> {
    let beam = &items[edit];
    let mut e = vec![0.0; BUFFER + 1];
    (1..=beam.len().min(BUFFER)).for_each(|k| e[k] = beam.get(k));
    let mut run = AutoBeam { items: items.to_vec(), edit, e, inserted: Vec::new() };
    let splits = match word {
        Word::Split(n) => {
            let e = &run.e;
            let blocked = e[13] == 0.0 && (e[14] != 0.0 || e[15] != 0.0);
            if blocked || run.same_as_neighbour() {
                return None;
            }
            split_points(n)?
        }
        _ => [0; 4],
    };
    let all_stems = word == Word::AutoX;
    let staff = run.e[2].trunc();
    let start = (run.e[7] / 10.0).trunc() as i32;
    let mut direction = start;
    let rows = loop {
        let rows = run.collect(staff, direction, all_stems, splits);
        if rows.len() >= 2 {
            break Some(rows);
        }
        if direction != start {
            break None;
        }
        let step = if direction == 1 { FLIP } else { -FLIP };
        direction = if direction == 1 { 2 } else { 1 };
        run.e[4] += step;
        run.e[5] += step;
    };
    let stem_beam = rows.map(|rows| run.secondary(rows, direction, all_stems));
    Some(Outcome { items: run.items, inserted: run.inserted, stem_beam })
}

/// The engine's selection sort: again and again the last row with the smallest x.
fn last_of_smallest_first(rows: &[Row]) -> Vec<Row> {
    let mut left: Vec<Row> = rows.to_vec();
    std::iter::from_fn(|| {
        let smallest = left.iter().map(|r| r.x).reduce(f32::min)?;
        let pick = left.iter().rposition(|r| r.x == smallest)?;
        Some(left.remove(pick))
    })
    .collect()
}

/// Marks the first run at level `next`, up to `end`, as written.
fn mark_run(level: &mut [f32], next: f32, end: usize) {
    let last = end.min(level.len() - 1);
    if let Some(k) = (1..=last).find(|&k| level[k] == next) {
        level[k..].iter_mut().take(end + 1 - k).take_while(|l| **l == next).for_each(|l| *l = next + DONE);
    }
}

impl AutoBeam {
    /// A second-level beam item: equal to the item before or after it in P1..P6.
    fn same_as_neighbour(&self) -> bool {
        let neighbours = [Some(self.edit + 1), self.edit.checked_sub(1)];
        neighbours
            .into_iter()
            .flatten()
            .filter_map(|j| self.items.get(j))
            .any(|other| (1..=6).all(|k| self.e[k] == other.get(k)))
    }

    fn collect(&mut self, staff: f32, direction: i32, all_stems: bool, splits: [usize; 4]) -> Vec<Row> {
        let mut rows: Vec<Row> = Vec::new();
        let mut cue = false;
        for i in 0..self.items.len() {
            let it = &self.items[i];
            let x = it.get(3);
            let in_beam = it.get(7) > 0.0
                && it.len() > 6
                && x <= self.e[6] + REACH
                && self.e[3] - REACH <= x
                && it.code() == NOTE
                && it.get(2).trunc() == staff;
            if !in_beam || !(all_stems || direction == stem_digit(it) || (it.len() > 11 && it.get(12) != 0.0)) {
                continue;
            }
            let size = it.get(4).abs();
            let (level, duration, dots) = (it.get(4), it.get(7), (it.len() > 8).then(|| (it.get(9) / 10.0).trunc() as i32 % 100));
            if rows.is_empty() {
                let beam_size = self.e[4].abs();
                cue = size >= 100.0;
                if !cue && beam_size >= 100.0 {
                    self.e[4] = amod(self.e[4], 100.0);
                    self.items[self.edit].set(4, self.e[4]);
                } else if cue && beam_size < 100.0 {
                    self.e[4] = away_from_zero(self.e[4], 100.0);
                    self.items[self.edit].set(4, self.e[4]);
                }
            }
            if cue != (size >= 100.0) {
                continue;
            }
            let d = if duration >= 64.0 { GRACE_VALUE } else { duration };
            let d = match dots {
                Some(1) => d / 1.5,
                Some(2) => d / 1.75,
                _ => d,
            };
            if d > LONGEST {
                break;
            }
            let row = Row { x, level, count: beam_count(d) };
            rows.push(row);
            if splits[3] != 0 && splits.contains(&rows.len()) && row.x < self.e[6] {
                rows.push(Row { x: row.x + BREAK_GAP, count: 1.0, ..row });
            }
        }
        rows
    }

    /// Writes the beam and its copies; returns the beam the stem pass uses.
    fn secondary(&mut self, rows: Vec<Row>, direction: i32, all_stems: bool) -> Draft {
        let sorted = last_of_smallest_first(&rows);
        let count = sorted.len();
        let mut level: Vec<f32> = std::iter::once(0.0).chain(sorted.iter().map(|r| r.count)).collect();
        if sorted[0].level.abs() >= 100.0 {
            if self.e[4].abs() < 100.0 {
                self.e[4] = amod(self.e[4], 100.0);
            }
        } else if self.e[4].abs() >= 100.0 {
            self.e[4] = away_from_zero(self.e[4], 100.0);
        }
        let differs = level[1..].iter().any(|&l| l != level[1]);
        let least = level[1..].iter().copied().fold(NONE, f32::min);
        level[1..].iter_mut().filter(|l| **l == least).for_each(|l| *l = least + DONE);
        self.e[7] = (direction * 10) as f32 + least;
        self.e[6] = sorted[count - 1].x;
        self.e[3] = sorted[0].x;
        let mut target = Target::Edit;
        if differs {
            loop {
                self.levels(&sorted, &mut level, least);
                let length = (1..=LAST_KEPT).rev().find(|&k| self.e[k] != 0.0).unwrap_or(0);
                self.store(target, length);
                if !level[1..].iter().any(|&l| l < NONE) {
                    break;
                }
                target = self.insert_copy(target);
            }
        } else {
            (8..=15).for_each(|k| self.e[k] = 0.0);
            self.store(target, self.item(target).len());
        }
        self.finish(all_stems, target)
    }

    fn item(&self, target: Target) -> &Draft {
        match target {
            Target::Edit => &self.items[self.edit],
            Target::Copy(i) => &self.inserted[i],
        }
    }

    fn item_mut(&mut self, target: Target) -> &mut Draft {
        match target {
            Target::Edit => &mut self.items[self.edit],
            Target::Copy(i) => &mut self.inserted[i],
        }
    }

    /// The first `length` parameters of the edit buffer become the item.
    fn store(&mut self, target: Target, length: usize) {
        let params = self.e[1..=length].to_vec();
        *self.item_mut(target) = Draft::new(&params);
    }

    /// A copy of `after` (at least 12 parameters) inserted after it.
    fn insert_copy(&mut self, after: Target) -> Target {
        let source = self.item(after);
        let n = source.len().max(COPY_MIN);
        let params: Vec<f32> = (1..=n).map(|k| source.get(k)).collect();
        self.inserted.push(Draft::new(&params));
        Target::Copy(self.inserted.len() - 1)
    }

    /// P10..P12 for the next level's first run, then P13..P15 for the one after.
    fn levels(&mut self, sorted: &[Row], level: &mut [f32], least: f32) {
        (10..=15).for_each(|k| self.e[k] = 0.0);
        for (code_slot, first_slot, last_slot) in [(10, 11, 12), (13, 14, 15)] {
            let next = level[1..].iter().copied().filter(|&l| l < DONE).fold(NONE, f32::min);
            self.e[code_slot] = (least * 10.0 + next) - least;
            let end = self.run_bounds(sorted, level, next, first_slot, last_slot);
            mark_run(level, next, end);
            if code_slot == 13 || !level[1..].iter().any(|&l| l < NONE) {
                return;
            }
        }
    }

    /// The x range of the first run reaching level `next`, into slots `a` and
    /// `b` (exchanged when the run begins after a note of lower count).
    fn run_bounds(&mut self, sorted: &[Row], level: &[f32], next: f32, a: usize, b: usize) -> usize {
        let count = sorted.len();
        let mut k = 1;
        while k <= count {
            if level[k] >= NONE {
                k += 1;
                continue;
            }
            let stop = (k..=count).find(|&j| level[j] == next || level[j] >= NONE);
            if stop.is_some_and(|j| level[j] != next) {
                k += 1;
                continue;
            }
            if count <= k {
                self.e[a] = 0.0;
                self.e[b] = -1.0;
                return k;
            }
            let (a, b) = if k > 1 && amod(level[k - 1], 100.0) < level[k] { (b, a) } else { (a, b) };
            self.e[b] = 0.0;
            self.e[a] = sorted[k - 1].x;
            if level[k + 1] >= NONE {
                return k;
            }
            let end = (k + 1..=count).find(|&j| level[j] >= NONE).unwrap_or(count + 1);
            self.e[b] = sorted[end - 2].x;
            return end;
        }
        0
    }

    /// AUTOX's P9, written from the edit buffer, which holds the
    /// last item written; the stem pass works with that buffer too.
    fn finish(&mut self, all_stems: bool, target: Target) -> Draft {
        let mut length = self.item(target).len();
        if all_stems {
            let p9 = stem_side_flags(&Draft::new(&self.e[1..=length]), &self.items);
            if p9 != 0.0 {
                self.e[9] = p9;
                if length < 9 {
                    self.items[self.edit].set(9, p9);
                    length = 9;
                } else {
                    self.item_mut(target).set(9, p9);
                }
            }
        }
        Draft::new(&self.e[1..=length])
    }
}

/// Digits of P9 for the beam's ends (hundreds), second beam (tens)
/// and third beam (units) where a note with the opposite stem sits: 1 at the
/// start, 2 at the end, 3 when marked twice.
pub fn stem_side_flags(beam: &Draft, items: &[Draft]) -> f32 {
    let e = |k: usize| beam.get(k);
    let staff = e(2).trunc();
    let direction = (e(7).trunc() as i32 / 10).abs();
    let or_end = |v: f32, end: f32| if v == -1.0 { end } else { v };
    let starts = [e(3), or_end(e(11), e(3)), or_end(e(14), e(3))];
    let ends = [e(6), or_end(e(12), e(6)), or_end(e(15), e(6))];
    let mut digits = [0u32; 3];
    let mut last = -9999.0;
    for note in items {
        let x = note.get(3);
        let candidate = note.get(2).trunc() == staff && note.code() == NOTE && x <= e(6) && last != x && e(3) <= x && note.len() > 4;
        let stem = stem_digit(note);
        if !candidate || stem == 0 || stem == direction {
            continue;
        }
        let mut mark = |slot: usize, side: u32| digits[slot] = if digits[slot] != 0 { 3 } else { side };
        (0..3).filter(|&s| starts[s] == x).for_each(|s| mark(s, 1));
        (0..3).filter(|&s| ends[s] == x).for_each(|s| mark(s, 2));
        last = x;
    }
    (digits[0] * 100 + digits[1] * 10 + digits[2]) as f32
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn split_numbers_name_rows() {
        assert_eq!(split_points(2), Some([0, 0, 0, 2]));
        assert_eq!(split_points(222), Some([0, 2, 5, 8]));
        assert_eq!(split_points(22), Some([0, 2, 5, 15]));
        assert_eq!(split_points(202), None);
    }

    #[test]
    fn eighth_and_two_sixteenths() {
        let note = |x: f32, d: f32| Draft::new(&[1.0, 1.0, x, 6.0, 10.0, 0.0, d]);
        let items = vec![note(100.0, 0.5), note(110.0, 0.25), note(120.0, 0.25), Draft::new(&[6.0, 1.0, 100.0, 13.0, 13.0, 120.0, 11.0])];
        let out = run(&items, 3, Word::Auto).unwrap();
        let beam = &out.items[3];
        assert_eq!((beam.get(7), beam.get(10), beam.get(11), beam.get(12)), (11.0, 11.0, 120.0, 110.0));
    }
}
