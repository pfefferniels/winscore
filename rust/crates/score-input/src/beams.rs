//! Pass 4: beams as code-6 items, and the stems of the beamed notes.
//!
//! Ported from the engine's beam routine 0x413CA8, its beam-line routine 0x559F38 and the
//! stem adjustment 0x40CDE4/0x40C1C0 that runs when the work table is written back.

use crate::connect::{ConnectEntry, Connection, Side};
use crate::error::InputError;
use crate::line::{item, Line, Note};
use crate::marks::recompute_clearance;

const UP: i32 = 10;
const DOWN: i32 = 20;
/// Steepest beam slope in steps per P3 unit (0x78B470, a preference, 0.1 by default).
const MAX_SLOPE: f32 = 0.1;

/// The notes of `xB`/`xBy` groups: after `pickup` notes, windows of `eighths` eighth notes,
/// each beaming its runs of two or more notes shorter than a quarter.
fn every_eighths(line: &Line, eighths: u32, pickup: u32) -> Vec<Connection> {
    #[derive(Clone, Copy)]
    struct Slot {
        number: usize,
        window: i64,
        beamable: bool,
    }
    let window = eighths as f32 * 0.5;
    let slots: Vec<Slot> = line
        .notes()
        .enumerate()
        .skip(pickup as usize)
        .scan(0.0f32, |time, (i, note)| {
            let window_index = (*time / window).floor() as i64;
            *time += note.rhythm.quarters();
            Some(Slot { number: i + 1, window: window_index, beamable: note.rhythm.tails() > 0 && !note.is_grace() })
        })
        .collect();
    slots
        .chunk_by(|a, b| a.window == b.window && a.beamable && b.beamable)
        .filter(|run| run.len() >= 2)
        .map(|run| Connection { first: run[0].number, last: run[run.len() - 1].number, side: None, tuplet: 0 })
        .collect()
}

/// Level of the head a beam is measured from: the head nearest the beam.
fn beam_side_level(note: &Note) -> f32 {
    if note.down {
        note.lowest() as f32
    } else {
        note.highest() as f32
    }
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
        if let Some(note) = self.line.note_mut(number) {
            let down = direction == DOWN;
            if note.down != down {
                note.set_stem(down);
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
        let mut direction = match group.side {
            Some(Side::Above) => UP,
            Some(Side::Below) => DOWN,
            None => 0,
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
            let size = if start < 0.0 { -100.0 } else { 100.0 };
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

        for n in first..=last {
            if self.beamed[n] == 0 {
                self.set_direction(n, direction);
            }
        }

        let head = [6.0, self.line.staff, note_xs[0], y1, y2, note_xs[note_xs.len() - 1], (fewest + direction) as f32, group.tuplet as f32, 0.0];
        let segments = if tails.iter().any(|t| *t != 0 && *t != tails[0]) { secondary_beams(&tails, &note_xs, fewest) } else { Vec::new() };
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
}

/// 0x40CDE4 with 0x40C1C0: every note under a beam whose stem goes the beam's way gets
/// the stem length that reaches the beam, and loses its flags.
fn fit_stems(line: &mut Line, beams: &[score_format::Item]) {
    for beam in beams {
        let (x1, y1, y2, x2) = (beam.param(3), beam.param(4), beam.param(5), beam.param(6));
        let down = beam.param(7) as i32 / 10 == 2;
        let grace_beam = (y1 / 100.0) as i32 != 0;
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
            note.extension = (fraction * (b as f64 - a as f64) + a as f64) as f32;
            note.tails = 0;
        }
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
    let beamed = vec![0; line.note_count() + 2];
    let mut beamer = Beamer { line, beamed };
    let made: Vec<score_format::Item> = groups.into_iter().flat_map(|g| beamer.beam(g)).collect();
    fit_stems(line, &made);
    line.attachments.extend(made);
    Ok(())
}
