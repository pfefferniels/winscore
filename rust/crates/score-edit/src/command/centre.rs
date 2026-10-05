//! CN on items with two ends, lines, slurs, beams and trills (codes 4–7):
//! a reimplementation of the engine's 0x42C9B0 with its note search 0x42DAF8
//! and retry 0x42D9F9. Ending brackets (slurs with P8 = 1 or 2) go to the
//! barlines instead.
//!
//! The engine collects parameter changes as (parameter, value) pairs and
//! applies them in order: the left end goes to the nearest note or rest,
//! the right end to the note nearest to it, searching 2 units further right
//! while it would land where the left end did.

use score_render::staff::StaffTable;

use crate::params::Draft;

const NOTE: i32 = 1;
const LINE: i32 = 4;
const SLUR: i32 = 5;
const BEAM: i32 = 6;
const TRILL: i32 = 7;
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
const BARLINE: i32 = 14;

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
    let code = item.code();
    let mut search = Search { item, targets, staves, pairs: Vec::new(), width: width_unit(item, staves) };
    let Some(first) = search.pair(3, item.get(3)) else { return Vec::new() };
    let left = search.pairs[0].1;
    let e = |k: usize| item.get(k);
    let two_ends = (LINE..=TRILL).contains(&code)
        && (e(7) >= 0.0 || code != LINE || e(6) != 0.0)
        && (e(11) != 0.0 || code != BEAM || e(7) >= 0.0);
    if !two_ends {
        return search.pairs;
    }
    let right = if left < e(6) {
        search.retried_pair(6, e(6))
    } else {
        let lead = if e(8) <= -2.0 { LEAD + TIE_LEAD } else { LEAD };
        search.pairs = vec![(6, left), (3, left - lead)];
        None
    };
    if code == SLUR {
        if right == Some(first) {
            let level = amod(targets[first].0.get(4), 100.0) + if e(7) < 0.0 { -1.0 } else { 1.0 };
            search.pairs.extend([(4, level), (5, level)]);
        }
        return search.pairs;
    }
    if amod(e(7), 10.0) != 0.0 || e(11) != 0.0 {
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

struct Search<'a> {
    item: &'a Draft,
    targets: &'a [Target],
    staves: &'a StaffTable,
    pairs: Vec<(usize, f32)>,
    width: f32,
}

impl Search<'_> {
    /// 0x42DAF8: parameter `param` to the target nearest `x` (the first of
    /// equals); returns the target's index.
    fn pair(&mut self, param: usize, x: f32) -> Option<usize> {
        if let Some(number) = ending(self.item) {
            return self.ending_pair(param, x, number);
        }
        let found = self.nearest(x)?;
        let Target(target) = &self.targets[found];
        self.pairs.push((param, self.value(target)));
        if let Some(offset) = self.tremolo_offset(target) {
            self.pairs.push((14, offset));
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
    /// bar and its right end needs a barline more than 4 units on. A right end
    /// at the left end's barline searches 2 units further right, up to the
    /// page's right limit.
    fn ending_pair(&mut self, param: usize, mut x: f32, number: usize) -> Option<usize> {
        loop {
            let found = self.nearest(x)?;
            let Target(bar) = &self.targets[found];
            let at = if bar.len() > 2 { bar.get(3) } else { 0.0 };
            let double = bar.len() > 4 && bar.get(5) == DOUBLE_BAR;
            let short = || at - ENDING_GAPS[number - 1] * self.staves.get(bar.get(2) as i32).step as f32 / 25.0;
            let value = match (self.pairs.first(), number) {
                (None, 1) => Some(if double { self.item.get(3) } else { at }),
                (None, _) => Some(if double { short() } else { self.item.get(3) }),
                (Some(&(_, left)), 1) => (at != left).then(short),
                (Some(&(_, left)), _) => (at - left > 4.0).then_some(at),
            };
            if let Some(value) = value {
                self.pairs.push((param, value));
                return Some(found);
            }
            x += RETRY_STEP;
            if x > RIGHT {
                self.pairs.push((param, self.item.get(6).min(RIGHT)));
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
            let n = self.pairs.len();
            let Some(&(before, previous)) = n.checked_sub(2).and_then(|i| self.pairs.get(i)) else { return Some(found) };
            if self.pairs[n - 1].1 != previous || SETTLED_BEFORE.contains(&before) {
                return Some(found);
            }
            if x + RETRY_STEP >= RIGHT - 0.5 {
                self.pairs[n - 1].1 = RIGHT;
                return Some(found);
            }
            x += RETRY_STEP;
            self.pairs.pop();
        }
    }
}
