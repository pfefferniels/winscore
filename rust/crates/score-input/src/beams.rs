//! Pass 4: beams as code-6 items, and the stems of the beamed notes.
//!
//! Ported from the engine's beam routine 0x413CA8, its beam-line routine 0x559F38 and the
//! stem adjustment 0x40CDE4/0x40C1C0 that runs when the work table is written back.

use crate::connect::{ConnectEntry, Connection, Side};
use crate::error::InputError;
use crate::line::{item, Element, Line, Note};
use crate::marks::recompute_clearance;
use crate::notes::{StaffShift, StemMode};

const UP: i32 = 10;
const DOWN: i32 = 20;
/// Steepest beam slope in steps per P3 unit (0x78B470, a preference, 0.1 by default).
const MAX_SLOPE: f32 = 0.1;

/// A note, chord or rest as the automatic beaming sees it.
#[derive(Debug, Clone, Copy, PartialEq)]
enum Slot {
    Note { quarters: f32, flagged: bool, grace: bool },
    Rest { quarters: f32 },
}

fn slots(line: &Line) -> Vec<Slot> {
    line.elements
        .iter()
        .filter_map(|e| match e {
            Element::Note(n) => Some(Slot::Note { quarters: n.rhythm.quarters(), flagged: n.rhythm.tails() > 0, grace: n.is_grace() }),
            Element::Rest { rhythm, .. } => Some(Slot::Rest { quarters: rhythm.quarters() }),
            _ => None,
        })
        .collect()
}

fn is_grace(slot: &Slot) -> bool {
    matches!(slot, Slot::Note { grace: true, .. })
}

/// Runs of two or more grace notes, with note numbers counted over the whole line.
fn grace_runs(slots: &[Slot]) -> Vec<Connection> {
    let numbered: Vec<(usize, bool)> = slots
        .iter()
        .scan(0, |number, slot| {
            if matches!(slot, Slot::Note { .. }) {
                *number += 1;
            }
            Some((*number, is_grace(slot)))
        })
        .collect();
    numbered
        .chunk_by(|a, b| a.1 == b.1)
        .filter(|run| run[0].1 && run.len() >= 2)
        .map(|run| Connection::new(run[0].0, run[run.len() - 1].0))
        .collect()
}

/// 0x410FD8: the groups of `xB`/`xBy`. Grace-note runs are beamed first. Then, after
/// `pickup` notes or rests, flagged notes are collected until a note without flags, or
/// until the time reaches the next multiple of `eighths` eighths; a rest after a flagged
/// note does not end a group. Grace notes in the pickup are skipped without being counted,
/// which shifts the note numbers after it, as in the engine.
fn every_eighths(line: &Line, eighths: u32, pickup: u32) -> Vec<Connection> {
    let slots = slots(line);
    let pickup = pickup as usize;
    let counted: Vec<usize> = slots.iter().enumerate().filter(|(_, s)| !is_grace(s)).map(|(i, _)| i).collect();
    let start = match pickup {
        0 => 0,
        n if n > counted.len() => return Vec::new(),
        n => counted[n - 1] + 1,
    };
    let numbered_in_pickup = slots[..start].iter().filter(|s| matches!(s, Slot::Note { grace: false, .. })).count();

    // The engine treats 9 as a dotted quarter.
    let window = if eighths == 9 { 1.5f32 } else { eighths as f32 } / 2.0;
    let full = window - 0.001;
    let mut groups = grace_runs(&slots);
    let mut close = |group: &mut Option<(usize, usize)>| {
        if let Some((first, last)) = group.take().filter(|(first, last)| first < last) {
            groups.push(Connection::new(first, last));
        }
    };
    let mut number = numbered_in_pickup;
    let mut flagged = true;
    let mut time = 0.0f32;
    let mut group = None;
    for slot in &slots[start..] {
        match *slot {
            Slot::Note { grace: true, .. } => {
                number += 1;
                continue;
            }
            Slot::Note { quarters, flagged: f, .. } => {
                number += 1;
                flagged = f;
                if f {
                    group = Some((group.map_or(number, |(first, _)| first), number));
                }
                time += quarters;
            }
            Slot::Rest { quarters } => time += quarters,
        }
        if !flagged || time >= full {
            close(&mut group);
        }
        if time >= full {
            time -= window;
            while full < time {
                time -= window;
            }
            if time.abs() <= 0.001 {
                time = 0.0;
            }
        }
    }
    close(&mut group);
    groups
}

/// Level of the head a beam is measured from (0x41A4F9): the last in item order, which is
/// the head nearest the beam.
fn beam_side_level(note: &Note) -> f32 {
    note.heads.last().map_or(0.0, |h| h.level as f32)
}

/// 0x559F38: the levels of the beam's ends (in note-level terms), and the direction when
/// none was decided yet. `levels` and `xs` hold the beamed notes in order.
fn beam_line(levels: &[f32], xs: &[f32], (x1, x2): (f32, f32), direction: i32) -> (f32, f32, i32) {
    let n = levels.len();
    let mut end = levels[n - 1];
    let mut start = levels[0];
    let highest = levels.iter().copied().fold(levels[0], f32::max);
    let lowest = levels.iter().copied().fold(levels[0], f32::min);
    let direction = if direction != 0 {
        direction
    } else {
        let above = highest - 7.0;
        let below = 7.0 - lowest;
        if above == below {
            let over = levels.iter().filter(|l| **l > 7.0).count();
            let under = levels.iter().filter(|l| **l < 7.0).count();
            if over < under {
                UP
            } else {
                DOWN
            }
        } else if above < below {
            UP
        } else {
            DOWN
        }
    };
    let extreme = if direction == UP { highest } else { lowest };
    let mut span = 0.0f32;
    let flat = if start == end {
        start != extreme
    } else if levels.iter().filter(|l| **l == extreme).count() >= 2 {
        true
    } else {
        span = x2 - x1;
        match inner_extreme(levels, xs, x1, start, end, direction, span) {
            None => false,
            Some(_) if start != extreme && end != extreme => true,
            Some((x, level)) => {
                // The beam passes a step clear of the inner note, pivoting on the extreme end.
                let through = if direction == DOWN { level + 1.0 } else { level - 1.0 };
                let (fixed_y, moving_y) = if direction == DOWN { (end, start) } else { (start, end) };
                if fixed_y <= moving_y {
                    start = pivot(x2, x, x1, end, through);
                } else {
                    end = pivot(x1, x, x2, start, through);
                }
                false
            }
        }
    };
    if flat {
        start = extreme;
        end = extreme;
    }

    let rising;
    if direction == DOWN {
        start = start.min(14.0);
        end = end.min(14.0);
        rising = start < end;
    } else {
        start = start.max(0.0);
        end = end.max(0.0);
        rising = end < start;
    }
    let mut difference = (start - end).abs();
    if difference > 1.5 && MAX_SLOPE < difference / span {
        if difference >= 3.0 {
            difference -= 1.0;
            let step = if direction == DOWN { 1.0 } else { -1.0 };
            if rising {
                start += step;
            } else {
                end += step;
            }
        }
        let (fixed_start, fixed_end) = (start, end);
        let mut slope = MAX_SLOPE;
        while slope < difference / span {
            let mut excess = difference - span * slope;
            if direction == DOWN {
                excess = -excess;
            }
            if rising {
                end = excess + fixed_end;
            } else {
                start = excess + fixed_start;
            }
            if (end - start).abs() >= 1.0 {
                break;
            }
            slope += 0.01;
        }
    }
    let (start, end) = half_steps(start, end, direction);
    (start, end, direction)
}

/// The inner note sticking out furthest beyond the straight line between the ends, if it
/// does so by more than a step: (x, level).
fn inner_extreme(levels: &[f32], xs: &[f32], x1: f32, start: f32, end: f32, direction: i32, span: f32) -> Option<(f32, f32)> {
    let slope = (end - start) / span;
    let worst = levels.iter().zip(xs).skip(1).take(levels.len().saturating_sub(2)).fold(
        None::<(f32, f32, f32)>,
        |worst, (&level, &x)| {
            let line = (x - x1) * slope + start;
            let off = level - line;
            let beyond = if direction == DOWN { off < 0.0 } else { off > 0.0 };
            let worse = match worst {
                None => true,
                Some((_, _, w)) => (direction == DOWN && off < w) || (direction == UP && off > w),
            };
            if beyond && worse {
                Some((x, level, off))
            } else {
                worst
            }
        },
    );
    worst.filter(|(_, _, off)| if direction == DOWN { *off < -1.0 } else { *off > 1.0 }).map(|(x, level, _)| (x, level))
}

/// 0x55ADF4: the level at `x_at` of the line through (`x_from`, `y_from`) and (`x_to`, `y_to`).
fn pivot(x_from: f32, x_to: f32, x_at: f32, y_from: f32, y_to: f32) -> f32 {
    let slope = ((y_to as f64 - y_from as f64) / (x_to as f64 - x_from as f64)) as f32;
    (x_at - x_from) * slope + y_from
}

/// Ends rounded down to half steps; a level beam on an odd step moves half a step off it
/// when it lies within the staff.
fn half_steps(start: f32, end: f32, direction: i32) -> (f32, f32) {
    let a = (start * 2.0) as i32;
    let b = (end * 2.0) as i32;
    let mut shift = 0.0;
    if a == b && (a / 2) % 2 != 0 {
        if direction == DOWN && a > 13 {
            shift = 0.5;
        } else if direction == UP && a < 15 {
            shift = -0.5;
        }
    }
    (a as f32 / 2.0 + shift, b as f32 / 2.0 + shift)
}

/// 0x413CA8: offset of both ends for groups with three or more beams, or level beams
/// far from the middle.
fn end_offset(direction: i32, start: f32, end: f32, most_tails: i32) -> f32 {
    let start_step = start as i32;
    let mut offset = 0;
    if most_tails > 2 {
        let lift = if (direction >= DOWN && start_step > 13) || (start_step < 1 && direction < DOWN) { 4 } else { 2 };
        offset = most_tails * 3 + lift - 9;
    }
    if direction < DOWN {
        if start_step >= 10 && end as i32 == start_step {
            offset -= 2;
        }
    } else {
        offset = -offset;
        if start_step < 5 && end as i32 == start_step {
            offset += 2;
        }
    }
    offset as f32 / 2.0
}

/// Which way a one-note secondary beam points: -1 left, 1 right, 0 by position (0x413CA8).
fn stub_directions(tails: &[i32], fewest: i32) -> Vec<i32> {
    let n = tails.len();
    (0..n)
        .map(|i| {
            let here = tails[i];
            let before = if i == 0 { 0 } else { tails[i - 1] };
            let after = tails.get(i + 1).copied().unwrap_or(0);
            if here == fewest {
                0
            } else if i == n - 1 {
                if before < here {
                    -1
                } else {
                    0
                }
            } else if after != here && after < here && before < here {
                if before < after {
                    1
                } else {
                    -1
                }
            } else {
                0
            }
        })
        .collect()
}

/// Secondary beams in slots of three parameters (code, left x, right x; 0 marks the open
/// side of a stub), consumed level by level as in 0x413CA8.
fn secondary_beams(tails: &[i32], xs: &[f32], fewest: i32) -> Vec<[f32; 3]> {
    let n = tails.len();
    let stubs = stub_directions(tails, fewest);
    let mut tails = tails.to_vec();
    let mut segments = Vec::new();
    let mut above = fewest;
    let mut i = 0;
    while i < n {
        let here = tails[i];
        if here == 0 || here == fewest {
            if here == fewest {
                above = fewest;
            }
            i += 1;
            continue;
        }
        let mut level = here;
        let mut deepest_end = i;
        let mut j = i;
        let mut stopped = false;
        while j + 1 < n {
            j += 1;
            let t = tails[j];
            if t == 0 {
                continue;
            }
            if t <= fewest {
                stopped = true;
                break;
            }
            deepest_end = j;
            level = level.min(t);
        }
        let last = if stopped { deepest_end } else { j };
        let (left, right) = if last == i {
            if stubs[i] >= 0 {
                (xs[i], 0.0)
            } else {
                (0.0, xs[i])
            }
        } else {
            (xs[i], xs[last])
        };
        segments.push([(above * 9 + level) as f32, left, right]);
        for t in tails[i..=last].iter_mut().filter(|t| **t == level) {
            *t = fewest;
        }
        above = level;
        i = (i..=last).find(|&k| tails[k] > level).unwrap_or(last + 1);
    }
    segments
}

struct Beamer<'a> {
    line: &'a mut Line,
    /// Stem direction a note got from its first beam (0x1F9929C), by note number.
    beamed: Vec<i32>,
}

impl Beamer<'_> {
    fn set_direction(&mut self, number: usize, direction: i32) {
        let first_entry = self.line.first_entry(number).unwrap_or(1);
        if let Some(note) = self.line.note_mut(number) {
            let down = direction == DOWN;
            if note.down != down {
                note.set_stem(down);
                if note.heads.len() > 1 {
                    note.table_extension = 0.0;
                    note.redot_after_turn(first_entry);
                }
                recompute_clearance(note);
            }
        }
    }

    fn beam(&mut self, group: Connection) -> Vec<score_format::Item> {
        let count = self.line.note_count() + 1;
        let first = if group.first == 0 || group.first == 99 { 1 } else { group.first };
        let last = if group.last <= first { first + 1 } else { group.last };
        if first == 0 || last >= count {
            return Vec::new();
        }
        let grace = |n: usize| self.line.note(n).is_some_and(Note::is_grace);
        if grace(first) != grace(last) {
            return Vec::new();
        }
        let first_grace = grace(first);
        // 0x41A4F9: a note that already has a beam direction keeps it, whatever the sign says.
        let typed = |side: Option<Side>| match side {
            Some(Side::Above) => UP,
            Some(Side::Below) => DOWN,
            None => 0,
        };
        let known = |n: usize, side: Option<Side>| if self.beamed[n] != 0 { self.beamed[n] } else { typed(side) };
        let mut direction = match known(first, group.sides[0]) {
            0 => known(last, group.sides[1]),
            d => d,
        };

        if self.beamed[first] == 0 {
            let stem_levels: Vec<i32> = (first..=last)
                .filter_map(|n| self.line.note(n))
                .filter(|n| !n.is_grace())
                .map(|n| n.stem_level())
                .collect();
            let lowest = stem_levels.iter().copied().min().unwrap_or(99);
            let highest = stem_levels.iter().copied().max().unwrap_or(-99);
            if direction == 0 {
                direction = if 7 - lowest <= highest - 7 { DOWN } else { UP };
            }
            for n in first..=last {
                if self.beamed[n] == 0 {
                    self.beamed[n] = direction;
                    self.set_direction(n, direction);
                } else {
                    let first_entry = self.line.first_entry(n).unwrap_or(1);
                    if let Some(note) = self.line.note_mut(n) {
                        note.turn_heads(direction == DOWN, first_entry);
                    }
                }
            }
        }

        let mut tails = Vec::new();
        let mut levels = Vec::new();
        let mut xs = Vec::new();
        let mut fewest = 99;
        let mut most = 0;
        for n in first..=last {
            let note = match self.line.note(n) {
                Some(note) => note,
                None => return Vec::new(),
            };
            let own = if note.is_grace() { 1 } else { note.rhythm.tails() };
            if own == 0 {
                return Vec::new();
            }
            let counted = if note.is_grace() { 0 } else { own };
            if counted != 0 {
                fewest = fewest.min(counted);
                most = most.max(counted);
            }
            if first_grace || counted != 0 {
                levels.push(beam_side_level(note));
                xs.push(note.x);
            }
            tails.push(counted);
        }
        if levels.len() < 2 {
            return Vec::new();
        }
        let note_xs: Vec<f32> = (first..=last).filter_map(|n| self.line.note(n)).map(|n| n.x).collect();
        let (start, end, direction) = beam_line(&levels, &xs, (note_xs[0], note_xs[note_xs.len() - 1]), direction);

        let (y1, y2, fewest) = if first_grace {
            let size = if (start as i32) < 0 { -100.0 } else { 100.0 };
            let offset = if direction >= DOWN { -0.8 } else { 0.8 };
            let mut y1 = offset + start + size;
            if y1 > 90.0 && y1 < 100.0 {
                y1 = -100.0 - (100.0 - y1);
            }
            (y1, offset + end, 2)
        } else {
            let offset = end_offset(direction, start, end, most);
            (offset + start, offset + end, fewest)
        };

        let head =[6.0, self.line.staff, note_xs[0], y1, y2, note_xs[note_xs.len() - 1], (fewest + direction) as f32, group.tuplet as f32, 0.0];
        let segments = if tails.iter().any(|t| *t != 0 && *t != tails[0]) { secondary_beams(&tails, &note_xs, fewest) } else { Vec::new() };
        self.point_unclaimed_stems(first..=last, direction);
        self.attach_tremolos(first..=last, &head, direction);
        if segments.is_empty() {
            return vec![item(&head)];
        }
        segments
            .chunks(2)
            .map(|pair| {
                let mut params = head.to_vec();
                params.extend(pair.iter().flatten());
                item(&params)
            })
            .collect()
    }

    /// 0x4156EC: notes of the group that no beam has claimed yet (possible when the group's
    /// first note had its direction already) point their stems the beam's way, or away
    /// from the staff they were moved to. Only the stem changes; heads and marks stay.
    fn point_unclaimed_stems(&mut self, numbers: std::ops::RangeInclusive<usize>, direction: i32) {
        let unclaimed: Vec<usize> = numbers.filter(|n| self.beamed[*n] == 0).collect();
        for n in unclaimed {
            if let Some(note) = self.line.note_mut(n) {
                note.down = match note.shift {
                    StaffShift::Main => direction == DOWN,
                    StaffShift::Above => true,
                    StaffShift::Below => false,
                };
            }
        }
    }

    /// 0x4156EC: a tremolo of pass 3 on a beamed note takes the beam's ends and direction.
    fn attach_tremolos(&mut self, numbers: std::ops::RangeInclusive<usize>, beam: &[f32; 9], direction: i32) {
        let notes: Vec<(f32, i32)> = numbers.filter_map(|n| self.line.note(n)).map(|n| (n.x, n.rhythm.tails())).collect();
        for tremolo in self.line.attachments.iter_mut() {
            let p: Vec<f32> = tremolo.params().iter().map(|w| w.as_f32()).collect();
            let is_tremolo = p.first() == Some(&6.0) && p.get(6).is_some_and(|v| *v < 0.0);
            let Some(&(x, tails)) = notes.iter().find(|(x, _)| is_tremolo && p.get(2) == Some(x)) else {
                continue;
            };
            let mut q = p.clone();
            q.resize(q.len().max(11), 0.0);
            q[2..6].copy_from_slice(&beam[2..6]);
            q[6] = -(direction as f32);
            q[9] = (tails * 10) as f32 + q[9] - 10.0;
            q[10] = x;
            *tremolo = item(&q);
        }
    }
}

/// 0x40CDE4 with 0x40C1C0: every note under a beam whose stem goes the beam's way gets
/// the stem length that reaches the beam, and loses its flags.
fn fit_stems(line: &mut Line, beams: &[score_format::Item]) {
    for beam in beams {
        let (x1, y1, y2, x2) = (beam.param(3), beam.param(4), beam.param(5), beam.param(6));
        let down = beam.param(7) as i32 / 10 == 2;
        let grace_beam = (y1 / 100.0) as i32 != 0;
        // Grace-note stems are drawn at 0.6 of the normal length.
        let scale = if grace_beam { 0.6f32 } else { 1.0 };
        let span = x2 - x1;
        let start = y1 % 100.0;
        for note in line.notes_mut() {
            let in_range = note.x >= x1 - 0.1 && note.x <= x2 + 0.1;
            if !in_range || note.down != down || note.rhythm.head() == 1 || note.is_grace() != grace_beam {
                continue;
            }
            let level = note.stem_level() as f32;
            let (mut a, mut b) = (start - level, y2 - level);
            if down {
                a = -a;
                b = -b;
            }
            let fraction = (note.x - x1) as f64 / span as f64;
            let reach = (fraction * (b as f64 - a as f64) + a as f64) as f32;
            note.extension = reach / scale;
            note.tails = 0;
        }
    }
}

/// A stem direction no beam can change: SU/SD fix the stems of the notes typed under them,
/// and pass 2 fixes the other grace stems upward (0x51CF40).
fn fixed_direction(note: &Note) -> i32 {
    match (note.stem_mode, note.is_grace()) {
        (StemMode::Up, _) | (StemMode::Ordinary, true) => UP,
        (StemMode::Down, _) => DOWN,
        (StemMode::Ordinary, false) => 0,
    }
}

pub(crate) fn apply(line: &mut Line, entries: &[ConnectEntry]) -> Result<(), InputError> {
    let groups: Vec<Connection> = entries
        .iter()
        .flat_map(|entry| match *entry {
            ConnectEntry::Pair(c) => vec![c],
            ConnectEntry::EveryEighths { eighths, pickup } => every_eighths(line, eighths, pickup),
        })
        .collect();
    let beamed: Vec<i32> = std::iter::once(0).chain(line.notes().map(fixed_direction)).chain(std::iter::once(0)).collect();
    let mut beamer = Beamer { line, beamed };
    let made: Vec<score_format::Item> = groups.into_iter().flat_map(|g| beamer.beam(g)).collect();
    fit_stems(line, &made);
    line.attachments.extend(made);
    Ok(())
}
