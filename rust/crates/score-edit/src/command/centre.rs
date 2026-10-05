//! CN on items with two ends, lines, slurs, beams and trills (codes 4–7),
//! and CV, CNL, CNR on slurs: a reimplementation of the engine's 0x42C9B0
//! with its note search 0x42DAF8, retry 0x42D9F9 and the slur routines
//! 0x42E11C/0x42E437 (end levels), 0x42C60E, 0x42D887, 0x42E94D (CNL) and
//! 0x42E6AB (CNR), after disasm-expert's `slur_center.py` for the latter.
//! Ending brackets (slurs with P8 = 1 or 2) go to the barlines instead.
//!
//! The engine collects parameter changes as (parameter, value) pairs in
//! slots and applies every pair written: the left end goes to the nearest
//! note or rest, the right end to the one nearest to it, searching 2 units
//! further right while it would land where the left end did.

use score_render::staff::StaffTable;

use crate::params::Draft;

const NOTE: i32 = 1;
const LINE: i32 = 4;
const SLUR: i32 = 5;
const BEAM: i32 = 6;
const TRILL: i32 = 7;
const BARLINE: i32 = 14;
/// The page's right limit (RIGHT, 0x1FBB8B8) for the default page.
const RIGHT: f32 = 200.0;
/// How far right the search for an end moves on.
const RETRY_STEP: f32 = 2.0;
/// A slur ending at the staff's first note starts this far before it (ties further).
const LEAD: f32 = 4.0;
const TIE_LEAD: f32 = 5.0;
/// Note width unit of beams' width compensation (f32 2.8333, not 2.83333).
const WIDTH_UNIT: f32 = 2.8333;
/// Points of multi-point lines and secondary beams that CN also moves.
const EXTRA_POINTS: [usize; 4] = [11, 12, 14, 15];
/// Of those, the ones searched again when they land where the point before did.
const RETRIED_POINTS: [usize; 2] = [12, 15];
/// A point landing where a P6 or P12 pair did is not searched again.
const SETTLED_BEFORE: [usize; 2] = [6, 12];
/// Tremolo beams over half and whole notes: the offset P14, and the note's
/// own offset codes 10 / 20 in steps.
const TREMOLO_OFFSET: f32 = 1.6;
const SHORT_TREMOLO_OFFSET: f32 = -1.23;
const NOTE_OFFSET: f32 = 3.26;
/// An ending bracket's right end stops this many units (of the barline's
/// staff, first and second ending) before the barline.
const ENDING_GAPS: [f32; 2] = [2.3, 1.0];
/// Barline type P5 = 3, at which endings keep or shorten their ends.
const DOUBLE_BAR: f32 = 3.0;
/// CV: a slur clears a stem this far (times 0.6 at cue size), a head by 2.
const STEM_CLEARANCE: f32 = 8.4;
const HEAD_CLEARANCE: f32 = 2.0;
/// A stemless note's stem length for CV.
const NO_STEM: f32 = -6.0;
/// CNL: the left end this much of a STEP before the first note (ties more, at least 6).
const CNL_GAP: f32 = 0.2;
const CNL_TIE_GAP: f32 = 0.38;
const CNL_TIE_MIN: f32 = 6.0;
/// CNR for slurs with P8 = -1: the right end this much before the barline.
const CNR_GAP: f32 = 0.6;
const CNR_STEP_GAP: f32 = 0.056;

/// A note, rest or barline an end can go to.
#[derive(Debug, Clone, PartialEq)]
pub struct Target(pub Draft);

/// The ending number of an ending bracket (a slur with P8 = 1 or 2).
pub fn ending(item: &Draft) -> Option<usize> {
    (item.code() == SLUR && matches!(item.get(8), 1.0 | 2.0)).then(|| item.get(8) as usize)
}

/// Whether `other` is something CN can put an end of `item` at: notes and
/// rests, or barlines for an ending bracket.
pub fn is_target(item: &Draft, other: &Draft) -> bool {
    match ending(item) {
        Some(_) => other.code() == BARLINE,
        None => matches!(other.code(), 1 | 2),
    }
}

/// The item's parameter changes for CN, in the order the engine makes them.
/// `targets` are the items of the staff CN works on that [`is_target`]
/// accepts, in file order, without the item.
pub fn centred(item: &Draft, targets: &[Target], staves: &StaffTable) -> Vec<(usize, f32)> {
    let mut search = Search::new(item, targets, staves);
    let Some(ends) = search.ends() else { return search.pairs };
    let e = |k: usize| item.get(k);
    if item.code() == SLUR {
        if ends.right == Some(ends.first) {
            search.same_note_levels(ends.first);
        }
        return search.pairs;
    }
    if ends.two && (amod(e(7), 10.0) != 0.0 || e(11) != 0.0) {
        let last = if e(7) < 0.0 { 11 } else { 15 };
        EXTRA_POINTS.iter().filter(|&&k| k <= last && k <= item.len() && e(k) > 0.0).for_each(|&k| {
            if RETRIED_POINTS.contains(&k) {
                search.retried_pair(k, e(k));
            } else {
                search.pair(k, e(k));
            }
        });
    }
    search.pairs
}

/// CV on a slur: CN's ends, then levels just clear of the end notes. `None`
/// where the engine's result is undefined (no note, or an ending bracket
/// without barlines); the slur then stays as it is.
pub fn vertically_centred(slur: &Draft, targets: &[Target], staves: &StaffTable) -> Option<Vec<(usize, f32)>> {
    let mut search = Search::new(slur, targets, staves);
    let ends = search.ends()?;
    if ends.two && !ends.before_start && ends.right.is_none() {
        return None;
    }
    if ends.right == Some(ends.first) {
        search.same_note_levels(ends.first);
        return Some(search.pairs);
    }
    search.end_levels(ends.first, ends.right);
    if matches!(slur.get(8), -2.0 | -3.0) {
        let level = tie_level(search.chord_step(ends.first), slur.get(7));
        search.pairs.iter_mut().skip(2).take(2).for_each(|pair| pair.1 = level);
    }
    Some(search.pairs)
}

/// CNL: the slur's left end before the staff's first note, its right end at
/// the note nearest to it. `notes` are the staff's notes in file order.
pub fn to_line_start(slur: &Draft, notes: &[Draft], step: f32) -> Vec<(usize, f32)> {
    let Some(first) = notes.iter().map(|n| n.get(3)).reduce(f32::min) else { return Vec::new() };
    let gap = if slur.get(8) < -1.0 { (step * CNL_TIE_GAP).max(CNL_TIE_MIN) } else { step * CNL_GAP };
    let mut pairs = vec![(3, first - gap)];
    pairs.extend(last_nearest(notes, slur.get(6)).map(|x| (6, x)));
    pairs
}

/// CNR: the slur's right end at the staff's last barline (or one spanning
/// it), its left end at the note nearest to it; nothing without a barline.
pub fn to_line_end(slur: &Draft, barlines: &[Draft], notes: &[Draft], step: f32) -> Vec<(usize, f32)> {
    let staff = slur.get(2).trunc();
    let reaching = |bar: &&Draft| {
        let s = bar.get(2).trunc();
        staff == s || (bar.len() > 3 && s <= staff && staff <= s + bar.get(4) - 1.0)
    };
    let Some(last) = barlines.iter().filter(reaching).map(|b| b.get(3)).reduce(f32::max) else { return Vec::new() };
    let at = if slur.get(8) == -1.0 {
        ((f64::from(last) - f64::from(CNR_GAP)) - f64::from(step) * f64::from(CNR_STEP_GAP)) as f32
    } else {
        last
    };
    let mut pairs = vec![(6, at)];
    pairs.extend(last_nearest(notes, slur.get(3)).map(|x| (3, x)));
    pairs
}

/// 0x42E82D: x of the note nearest `x` (the last of equal distances); a note
/// at 0 counts as none.
fn last_nearest(notes: &[Draft], x: f32) -> Option<f32> {
    let nearest = notes.iter().fold(None, |best: Option<(f32, f32)>, n| {
        let d = (x - n.get(3)).abs();
        match best {
            Some((bd, _)) if bd < d => best,
            _ => Some((d, n.get(3))),
        }
    });
    nearest.map(|(_, at)| at).filter(|&at| at != 0.0)
}

/// 0x42D887's use: the level of both tie ends from the chord step `d`.
fn tie_level(d: i32, curve: f32) -> f32 {
    let above = curve > 0.0;
    let level = if d % 2 == 0 {
        d as f32 - 0.45 + if above { 0.9 } else { 0.0 }
    } else if above {
        (d + 1) as f32
    } else {
        (d - 1) as f32
    };
    match d {
        d if d > 10 && above => (d + 1) as f32,
        d if d < 4 && curve < 0.0 => (d - 1) as f32,
        _ => level,
    }
}

/// STEP * 2.8333 / 25, with the STEP drawing the beam leaves (staff step
/// times the beam's size factor P18).
fn width_unit(item: &Draft, staves: &StaffTable) -> f32 {
    let size = if item.get(18) == 0.0 { 1.0 } else { item.get(18) };
    let step = (staves.get(item.get(2) as i32).step * f64::from(size)) as f32;
    step * WIDTH_UNIT / 25.0
}

fn amod(x: f32, y: f32) -> f32 {
    x - (x / y).trunc() * y
}

/// 0x42C60E: an end exactly on an odd step inside the staff moves one step out.
fn off_line(level: f32, below: bool) -> f32 {
    if amod(level, 2.0) != 1.0 {
        return level;
    }
    match below {
        false if (level.trunc() as i32) < 12 => level + 1.0,
        true if (level.trunc() as i32) > 2 => level - 1.0,
        _ => level,
    }
}

/// 0x42E437: how high (above) or low (below) a slur end clears `note`.
fn clearing_level(note: &Draft, below: bool) -> f32 {
    let n = note.len();
    let v = if n > 3 { amod(note.get(4), 100.0) } else { 0.0 };
    let stem = if n > 4 { note.get(5).trunc() as i32 % 100 } else { 0 };
    let length = if stem < 10 { NO_STEM } else if n > 7 { amod(note.get(8), 100.0) } else { 0.0 };
    let flags = if n > 8 { amod(note.get(9), 10.0).trunc() as i32 - 1 } else { 0 };
    let length = if flags > 0 { (flags * 2) as f32 + length } else { length };
    let off = match below {
        true if stem < 20 => return -HEAD_CLEARANCE + v,
        false if stem > 19 => return HEAD_CLEARANCE + v,
        true => -STEM_CLEARANCE - length,
        false => length + STEM_CLEARANCE,
    };
    let off = if note.get(4).abs() >= 100.0 { off * 0.6 } else { off };
    off + v
}

/// The ends 0x42C9B0 found: the targets of the left and the right end,
/// whether the item has two ends at all, and whether the right end went to
/// the left end's note with the left end before it.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Ends {
    first: usize,
    right: Option<usize>,
    two: bool,
    before_start: bool,
}

struct Search<'a> {
    item: &'a Draft,
    targets: &'a [Target],
    staves: &'a StaffTable,
    pairs: Vec<(usize, f32)>,
    /// The slot the next pair goes into.
    cursor: usize,
    width: f32,
}

impl<'a> Search<'a> {
    fn new(item: &'a Draft, targets: &'a [Target], staves: &'a StaffTable) -> Self {
        Search { item, targets, staves, pairs: Vec::new(), cursor: 0, width: width_unit(item, staves) }
    }

    fn put(&mut self, pair: (usize, f32)) {
        match self.pairs.get_mut(self.cursor) {
            Some(slot) => *slot = pair,
            None => self.pairs.push(pair),
        }
        self.cursor += 1;
    }

    /// Both ends: P3 to the nearest target; P6 to the target nearest to it,
    /// or, when the left end lands at or after P6 on the staff's notes, P6 to
    /// that note and P3 a little before it.
    fn ends(&mut self) -> Option<Ends> {
        let item = self.item;
        let e = |k: usize| item.get(k);
        let code = item.code();
        let first = self.pair(3, e(3))?;
        let left = self.pairs[0].1;
        let two = (LINE..=TRILL).contains(&code)
            && (e(7) >= 0.0 || code != LINE || e(6) != 0.0)
            && (e(11) != 0.0 || code != BEAM || e(7) >= 0.0);
        if !two {
            return Some(Ends { first, right: None, two, before_start: false });
        }
        if ending(item).is_some() || left < e(6) {
            let right = self.retried_pair(6, e(6));
            return Some(Ends { first, right, two, before_start: false });
        }
        let lead = if e(8) <= -2.0 { LEAD + TIE_LEAD } else { LEAD };
        self.pairs = vec![(6, left), (3, left - lead)];
        Some(Ends { first, right: None, two, before_start: true })
    }

    /// Both ends of a slur on one note: P4 = P5 = that note's level ± 1.
    fn same_note_levels(&mut self, note: usize) {
        let level = (self.targets[note].0.get(4) % 100.0) + if self.item.get(7) < 0.0 { -1.0 } else { 1.0 };
        self.pairs.truncate(2);
        self.pairs.extend([(4, level), (5, level)]);
    }

    /// 0x42E11C: P4 and P5 clear of the end notes and their chords, the
    /// highest note above, the lowest below.
    fn end_levels(&mut self, first: usize, right: Option<usize>) {
        let below = self.item.get(7) < 0.0;
        let staff = self.item.get(2).trunc();
        for (param, end) in [(4, Some(first)), (5, right)] {
            let Some(end) = end else { break };
            let Target(note) = &self.targets[end];
            if note.code() != NOTE {
                continue;
            }
            let x = note.get(3);
            let chord = self.targets.iter().enumerate().filter(|&(j, Target(other))| {
                j != end && other.code() == NOTE && other.get(3) == x && other.get(2).trunc() == staff
            });
            let level = chord.fold(clearing_level(note, below), |level, (_, Target(other))| {
                let v = clearing_level(other, below);
                if below { level.min(v) } else { level.max(v) }
            });
            self.put((param, off_line(level, below)));
        }
    }

    /// 0x42D887: of the notes at the first end's x, the step nearest to P4
    /// (the last of equals).
    fn chord_step(&self, first: usize) -> i32 {
        let Target(note) = &self.targets[first];
        let (x, staff) = (note.get(3), note.get(2).trunc());
        let chord = self.targets.iter().filter(|Target(o)| o.code() == NOTE && o.get(2).trunc() == staff && o.get(3) == x);
        chord
            .fold((f32::MAX, 0), |(best, step), Target(o)| {
                let v = o.get(4) % 100.0;
                let d = (v - self.item.get(4)).abs();
                if d <= best { (d, v.trunc() as i32) } else { (best, step) }
            })
            .1
    }

    /// 0x42DAF8: parameter `param` to the target nearest `x` (the first of
    /// equals); returns the target's index.
    fn pair(&mut self, param: usize, x: f32) -> Option<usize> {
        if let Some(number) = ending(self.item) {
            return self.ending_pair(param, x, number);
        }
        let found = self.nearest(x)?;
        let Target(target) = &self.targets[found];
        let value = self.value(target);
        let tremolo = self.tremolo_offset(target);
        self.put((param, value));
        if let Some(offset) = tremolo {
            self.put((14, offset));
        }
        Some(found)
    }

    fn nearest(&self, x: f32) -> Option<usize> {
        let nearest = self.targets.iter().enumerate().fold(None, |best: Option<(usize, f32)>, (i, Target(t))| {
            let distance = (t.get(3) - x).abs();
            match best {
                Some((_, d)) if d <= distance => best,
                _ => Some((i, distance)),
            }
        });
        nearest.map(|(i, _)| i)
    }

    /// An end of ending bracket `number` at a barline: the first ending's
    /// left end keeps its place at a double bar, its right end stops short of
    /// the barline; the second ending's left end stops short only at a double
    /// bar and its right end needs a barline more than 4 units on. Otherwise
    /// the search moves 2 units right, up to the page's right limit.
    fn ending_pair(&mut self, param: usize, mut x: f32, number: usize) -> Option<usize> {
        loop {
            let found = self.nearest(x)?;
            let Target(bar) = &self.targets[found];
            let at = if bar.len() > 2 { bar.get(3) } else { 0.0 };
            let double = bar.len() > 4 && bar.get(5) == DOUBLE_BAR;
            let step = self.staves.get(bar.get(2) as i32).step as f32;
            let short = || (f64::from(at) - f64::from(ENDING_GAPS[number - 1] * step) / 25.0) as f32;
            let value = match (self.cursor, number) {
                (0, 1) => Some(if double { self.item.get(3) } else { at }),
                (0, _) => Some(if double { short() } else { self.item.get(3) }),
                (_, 1) => (at != 0.0).then(short),
                (_, _) => (at - self.pairs[0].1 > 4.0).then_some(at),
            };
            if let Some(value) = value {
                self.put((param, value));
                return Some(found);
            }
            x += RETRY_STEP;
            if x > RIGHT {
                self.put((param, self.item.get(6).min(RIGHT)));
                return Some(found);
            }
        }
    }

    /// The x an end takes at `target`; beams make up for a note's width (P20).
    fn value(&self, target: &Draft) -> f32 {
        let x = if target.len() > 2 { target.get(3) } else { 0.0 };
        let compensated = self.item.code() == BEAM
            && self.item.get(20) == 0.0
            && target.get(7) < 20.0
            && target.len() >= 20
            && target.get(20) != 0.0;
        if compensated { (self.width * target.get(20) + x) - self.width } else { x }
    }

    /// A tremolo beam (P7 < 0) over a half or whole note also sets its P14.
    fn tremolo_offset(&self, target: &Draft) -> Option<f32> {
        let e7 = self.item.get(7);
        let head = target.get(6).round() as i32;
        if self.item.code() != BEAM || e7 >= 0.0 || target.len() <= 5 || target.code() != NOTE || !(2..4).contains(&head) {
            return None;
        }
        let base = if e7 >= -10.0 { SHORT_TREMOLO_OFFSET } else { TREMOLO_OFFSET };
        let own = match target.get(10) {
            10.0 => NOTE_OFFSET,
            20.0 => -NOTE_OFFSET,
            other if target.len() > 9 => other,
            _ => 0.0,
        };
        Some(own + base)
    }

    /// 0x42DAF8 then 0x42D9F9: while the new point lands where the point
    /// before did (unless that one was P6 or P12), search 2 units further
    /// right; past the page's right limit the point goes to the limit.
    fn retried_pair(&mut self, param: usize, mut x: f32) -> Option<usize> {
        loop {
            let found = self.pair(param, x)?;
            let n = self.cursor;
            let Some(&(before, previous)) = n.checked_sub(2).and_then(|i| self.pairs.get(i)) else { return Some(found) };
            if self.pairs[n - 1].1 != previous || SETTLED_BEFORE.contains(&before) {
                return Some(found);
            }
            if x + RETRY_STEP >= RIGHT - 0.5 {
                self.pairs[n - 1].1 = RIGHT;
                return Some(found);
            }
            x += RETRY_STEP;
            self.cursor -= 1;
        }
    }
}
