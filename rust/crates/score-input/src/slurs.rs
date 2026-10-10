//! Pass 5: slurs, ties and tuplet brackets as code-5 items, ported from the engine's slur
//! routine 0x53D1E0 and its helpers 0x53DE20 (end levels), 0x53DF2A (tie levels),
//! 0x42C60E (off the staff lines), 0x53E094 (marks) and 0x53E32F (inner notes).

use crate::connect::{ConnectEntry, Connection, Side};
use crate::error::{ErrorKind, InputError, Pass, Span};
use crate::line::{item, Line, Reached};

/// Directions as the engine codes them (also a note's stem direction).
const ABOVE: i32 = 10;
const BELOW: i32 = 20;
/// Note numbers with a meaning of their own: from before the first note, to after the last.
const BEFORE_FIRST: usize = 0;
const PAST_LAST: usize = 99;
/// Marks a slur end has to clear (0x797454): wedge, accent, tenuto, staccato, their
/// combinations, heavy wedge, fingerings 0-5.
const MARKS_TO_CLEAR: [i32; 14] = [4, 5, 6, 7, 8, 9, 10, 19, 30, 31, 32, 33, 34, 35];
/// The page's right limit (0x1FBB8B8), where a staff without P6 ends.
pub(crate) const STAFF_END: f32 = 200.0;

/// One entry of the engine's work table as the slur routine reads it.
#[derive(Debug, Clone, Copy, PartialEq)]
pub(crate) struct WorkEntry {
    pub code: i32,
    pub x: f32,
    /// P4 without the grace-note hundreds.
    pub level: i32,
    /// Tens of P5: 10 stem up, 20 stem down, 0 no stem (chord members).
    pub stem: i32,
    pub accidental: i32,
    /// P8 without the grace-note hundreds.
    pub extension: f32,
    pub dotted: bool,
    pub mark: f32,
    pub grace: bool,
    /// 1-based note number, for the entry carrying a note's stem.
    pub note: Option<usize>,
    /// Steps from the IN staff to the staff the note is placed on (S+/S-).
    pub staff_steps: f32,
}

impl WorkEntry {
    /// An entry that is not a note (rest, barline, clef, key, meter).
    pub fn other(code: i32, x: f32, level: i32) -> Self {
        WorkEntry {
            code,
            x,
            level,
            stem: 0,
            accidental: 0,
            extension: 0.0,
            dotted: false,
            mark: 0.0,
            grace: false,
            note: None,
            staff_steps: 0.0,
        }
    }

    /// 0x53DFD6: the stem direction, or for a stemless head the side it would have.
    fn stem_direction(&self) -> i32 {
        match self.stem {
            0 if self.level > 6 => BELOW,
            0 => ABOVE,
            s => s,
        }
    }
}

/// 0x53DE20: level of a slur end at this note.
fn end_level(entry: &WorkEntry, direction: i32, level: f32, stem: i32) -> f32 {
    let stem_side = if entry.stem == 0 { 2.0 } else { entry.extension + 8.0 };
    match (stem < BELOW, direction == BELOW) {
        (true, true) => level - 2.0,
        (true, false) => stem_side + level,
        (false, true) => level - stem_side,
        (false, false) => level + 2.0,
    }
}

/// 0x42C60E: an end on a staff line moves into the space outside it.
fn off_line(level: f32, direction: i32) -> f32 {
    let on_line = (level % 2.0) == 1.0;
    match (on_line, direction) {
        (true, ABOVE) if (level as i32) < 12 => level + 1.0,
        (true, BELOW) if (level as i32) > 2 => level - 1.0,
        _ => level,
    }
}

/// 0x53DF2A: a tie end half a step from a head in a space, 1.2 steps from one on a line.
fn tie_level(level: f32, direction: i32) -> f32 {
    let offset = if (level as i32) % 2 != 0 { 1.2 } else { 0.5 };
    level + if direction == BELOW { -offset } else { offset }
}

/// What decides where the two ends of a slur (not a tie) go.
struct SlurEnds {
    direction: i32,
    levels: (f32, f32),
    stems: (i32, i32),
}

impl SlurEnds {
    /// End levels and P8 (0x53D1E0): with equal stems each end is placed at its own note;
    /// otherwise the end on the stem side follows the other end. Both move off staff lines
    /// unless the slur began as a tie.
    fn levels_at(&self, a: &WorkEntry, b: &WorkEntry, off_lines: bool) -> (f32, f32, f32) {
        let d = self.direction;
        let (level1, level2) = self.levels;
        let (stem1, stem2) = self.stems;
        let mut kind = -1.0;
        let (y1, y2) = if stem1 == stem2 {
            if d == stem1 {
                kind = if d == ABOVE { -4.0 } else { 0.0 };
            }
            (end_level(a, d, level1, stem1), end_level(b, d, level2, stem2))
        } else {
            let rise = level1 - level2;
            if stem1 == d {
                let y2 = end_level(b, d, level2, stem2);
                let y1 = match d {
                    ABOVE if rise > 0.0 => level1 + 2.0,
                    BELOW if rise < 0.0 => level1 - 2.0,
                    _ => y2,
                };
                (y1, y2)
            } else {
                let y1 = end_level(a, d, level1, stem1);
                let y2 = match d {
                    BELOW if rise > 0.0 => level2 - 2.0,
                    ABOVE if rise < 0.0 => level2 + 2.0,
                    _ => y1,
                };
                (y1, y2)
            }
        };
        if off_lines {
            (off_line(y1, d), off_line(y2, d), kind)
        } else {
            (y1, y2, kind)
        }
    }
}

/// The slur being built (P3..P9 of the item).
#[derive(Debug, Clone, Copy, PartialEq)]
struct Shape {
    x1: f32,
    y1: f32,
    y2: f32,
    x2: f32,
    bend: f32,
    kind: f32,
    tuplet: f32,
}

/// 0x53E094: an end at a note with a mark on the slur's side moves past the mark; for
/// other marks on the note-head side it is the mark that moves (its P11 grows by 0.18).
fn clear_mark(end: &mut f32, entry: &mut WorkEntry, stem: i32, direction: i32, tuplet: bool) {
    let mark = entry.mark;
    let whole = mark as i32;
    if whole == 0 || (mark - whole as f32).abs() > 0.1 || !MARKS_TO_CLEAR.contains(&whole.abs()) {
        return;
    }
    let mut amount = 1.5f32;
    if whole < 1 {
        if stem != direction {
            return;
        }
    } else {
        if stem == direction {
            return;
        }
        if !tuplet {
            let code = whole.abs();
            if code != 6 && code != 7 {
                if mark % 1.0 <= 0.2 {
                    entry.mark = mark + 0.18;
                }
                return;
            }
            let level = entry.level;
            if level % 2 == 1 && ((level < 9 && stem == BELOW) || (level > 5 && stem == ABOVE)) {
                amount = 2.5;
            }
        }
    }
    *end += if direction == BELOW { -amount } else { amount };
}

/// 0x53E32F: inner notes reaching the slur deepen its curve (or, for a tuplet bracket,
/// move both ends).
fn clear_inner_notes(shape: &mut Shape, entries: &[WorkEntry], first: usize, last: usize, direction: i32) {
    let margin = if direction == BELOW { -2.5f32 } else { 2.5 };
    let mut start = first;
    'restart: loop {
        let slope = (shape.y2 - shape.y1) / (shape.x2 - shape.x1);
        let base = shape.y1 - margin;
        for (k, e) in entries.iter().enumerate().take(last).skip(start + 1) {
            if e.code != 1 || e.stem == direction {
                continue;
            }
            let curve = ((e.x - shape.x1) as f64 * slope as f64 + (shape.bend as f64 + base as f64)) as f32;
            let mut reach = 0.0f32;
            if e.mark > 0.0 {
                reach = (e.mark % 1.0) * 10.0;
                reach = if e.stem == ABOVE { -reach - 2.0 } else { reach + 2.0 };
            }
            let reach = reach + e.level as f32;
            let collides = if direction == BELOW { reach < curve } else { curve < reach };
            if !collides {
                continue;
            }
            let depth = reach - curve;
            if shape.tuplet == 0.0 {
                shape.bend += depth;
                continue;
            }
            let lift = depth + 0.5 - if direction == BELOW { 1.0 } else { 0.0 };
            shape.y1 += lift;
            shape.y2 += lift;
            start = k;
            continue 'restart;
        }
        return;
    }
}

struct SlurInput<'a> {
    entries: &'a mut [WorkEntry],
    /// Work-table index of each note's stem entry, by note number.
    note_entry: Vec<usize>,
    staff: f32,
    /// The input range, where slurs from before the first or past the last note end.
    begin: f32,
    end: f32,
    /// The staff's right end (0x547AE0: P6 of the staff item, else the page's limit), where
    /// a slur to after the last note ends.
    staff_end: f32,
}

impl SlurInput<'_> {
    fn note_count(&self) -> usize {
        self.note_entry.len()
    }

    fn note_x(&self, number: usize) -> Option<f32> {
        number.checked_sub(1).and_then(|i| self.note_entry.get(i)).map(|&e| self.entries[e].x)
    }

    fn items(&mut self, connection: &Connection) -> Vec<score_format::Item> {
        let count = self.note_count() + 1;
        // 0x41A14C: note numbers as the engine adjusts them.
        let mut typed_first = connection.first;
        let mut first = typed_first;
        let mut second = connection.last.max(1);
        let mut typed_second = connection.last;
        if first == BEFORE_FIRST || first == PAST_LAST {
            first = 1;
        } else if second <= first {
            second = first + 1;
            typed_second = second;
        }
        let second_entry_number = second.min(count - 1);
        if first > self.note_count() || second_entry_number == 0 {
            return Vec::new();
        }
        let a = self.note_entry[first - 1];
        let b = self.note_entry[second_entry_number - 1];
        let tuplet = connection.tuplet as i32;
        let mut direction = match connection.side() {
            Some(Side::Above) => ABOVE,
            Some(Side::Below) => BELOW,
            None => 0,
        };
        let typed_direction = direction;
        let mut x1 = self.entries[a].x;
        let mut x2 = self.entries[b].x;
        // 0x41A14C, pass 5: fractional note numbers place the ends between notes; the
        // engine then treats the numbers as 1 and 1, so such a slur is never a tie.
        let [f1, f2] = connection.fractions.map(f32::abs);
        let mut anchor = first;
        if f1 != 0.0 {
            anchor = connection.first;
            if count <= anchor {
                return Vec::new();
            }
            let (from, to) = if anchor == 0 { (self.begin, x1) } else { (x1, self.note_x(anchor + 1).unwrap_or(x1)) };
            x1 = (to - from) * f1 + from;
            typed_first = 1;
            typed_second = 1;
        }
        if f2 != 0.0 {
            let next = (connection.last + 1).max(anchor + 1);
            let from = if connection.last <= anchor { self.entries[a].x } else { x2 };
            let to = if next < count { self.note_x(next).unwrap_or(self.end) } else { self.end };
            x2 = (to - from) * f2 + from;
            typed_first = 1;
            typed_second = 1;
        }
        // 0x41A4F9: the end notes' levels count from the staff they are placed on.
        let mut level1 = self.entries[a].level as f32 + self.entries[a].staff_steps;
        let mut level2 = self.entries[b].level as f32 + self.entries[b].staff_steps;
        let chord_start = self.entries.get(a + 1).is_some_and(|n| n.x == self.entries[a].x);
        let tie_mode = if chord_start { -1 } else { 0 };

        let stem1 = if typed_first == PAST_LAST {
            level1 = level2;
            self.entries[b].stem_direction()
        } else {
            self.entries[a].stem_direction()
        };
        let stem2 = if typed_second == PAST_LAST {
            level2 = level1;
            self.entries[a].stem_direction()
        } else {
            self.entries[b].stem_direction()
        };

        if !self.entries[a].grace {
            if direction == 0 {
                direction = BELOW;
                for e in self.entries[a..=b].iter().filter(|e| e.code == 1) {
                    let stemless = e.stem < 10;
                    if e.level > 6 && stemless {
                        break;
                    }
                    if e.stem > 19 {
                        direction = ABOVE;
                        break;
                    }
                }
            }
        } else if direction == 0 {
            direction = 30 - stem1;
        }

        if count <= typed_second {
            x2 = self.staff_end;
        }
        let try_tie = if typed_first == BEFORE_FIRST {
            x1 = self.entries[a].x - 8.0;
            true
        } else if typed_first == PAST_LAST {
            x1 = self.entries[a].x - 5.0;
            false
        } else {
            typed_second != PAST_LAST
                && (count <= typed_second || (tuplet == 0 && level2 == level1 && typed_second == typed_first + 1))
        };
        let short = tie_mode == 0 && typed_first != BEFORE_FIRST && x2 - x1 < 10.0;
        let tie = try_tie && !short && self.entries[b].accidental == 0;
        let (y1, y2, kind) = if tie {
            let level = tie_level(level1, direction);
            (level, level, if self.entries[a].dotted { -3.0 } else { -2.0 })
        } else {
            if count <= typed_second {
                x2 -= 1.5;
            }
            let ends = SlurEnds { direction, levels: (level1, level2), stems: (stem1, stem2) };
            ends.levels_at(&self.entries[a], &self.entries[b], !try_tie)
        };

        let mut shape = Shape { x1, y1, y2, x2, bend: 0.0, kind, tuplet: tuplet as f32 };
        if tuplet != 0 && !tie {
            shape.kind = 3.0;
            shape.bend = 2.0;
        } else {
            let mut length = shape.x2 - shape.x1;
            if shape.kind < -1.0 && shape.kind > -4.0 {
                length += shape.kind * 2.0;
            }
            // One extended-precision expression with the engine's f32 constants (0x53D1E0).
            let base = f64::from(length) / f64::from(20.0f32) + f64::from(0.9f32);
            let rise = (f64::from(shape.y2) - f64::from(shape.y1)).abs();
            shape.bend = (rise * f64::from(0.1f32) + base) as f32;
        }
        if direction == BELOW {
            shape.bend = -shape.bend;
        }
        // A tie the engine had to give up (too short, or an accidental at its end) stays a
        // slur that neither clears marks nor counts as a tie for the rest.
        if !try_tie {
            clear_mark(&mut shape.y1, &mut self.entries[a], stem1, direction, tuplet != 0);
            clear_mark(&mut shape.y2, &mut self.entries[b], stem2, direction, tuplet != 0);
            if typed_second as i64 - typed_first as i64 > 1 {
                clear_inner_notes(&mut shape, self.entries, a, b, direction);
            }
        }

        let make = |s: &Shape| item(&[5.0, self.staff, s.x1, s.y1, s.y2, s.x2, s.bend, s.kind, s.tuplet]);
        let mut made = vec![make(&shape)];
        if try_tie {
            // Further heads of a chord get ties of their own; from the middle up they curve
            // the other way unless the direction was typed.
            let members = self.entries[a..].iter().take_while(|e| e.code == 1 && e.x == self.entries[a].x).count();
            if members > 1 {
                let flip_at = members / 2 + 1;
                let mut remaining = members;
                for member in self.entries[a + 1..a + members].iter() {
                    if typed_direction < 10 && flip_at == remaining {
                        shape.bend = -shape.bend;
                        direction = 30 - direction;
                    }
                    remaining -= 1;
                    let level = tie_level(member.level as f32, direction);
                    shape.y1 = level;
                    shape.y2 = level;
                    made.push(make(&shape));
                }
            }
        }
        made
    }
}

pub(crate) fn apply(line: &mut Line, entries: &[ConnectEntry], (begin, end): (f32, f32), staff_end: f32) -> Result<(), InputError> {
    let pairs: Vec<Connection> = entries
        .iter()
        .filter_map(|entry| match entry {
            ConnectEntry::Pair(c) => Some(*c),
            ConnectEntry::EveryEighths { .. } => None,
        })
        .collect();
    // A start past the last note is invalid input: 0x41A14C reads the empty slot before note 1.
    if let Some(bad) = pairs.iter().find(|c| c.first > line.note_count() && c.first != PAST_LAST) {
        return Err(InputError::new(Pass::Slurs, Span::default(), ErrorKind::NoSuchNote(bad.first as f32)));
    }
    pairs.iter().flat_map(|c| [c.first, if c.last <= c.first { c.first + 1 } else { c.last }]).for_each(|n| {
        line.placement_steps(n, Reached::StemHead);
    });
    let mut work = line.work_entries();
    let note_entry: Vec<usize> = work.iter().enumerate().filter(|(_, e)| e.note.is_some()).map(|(i, _)| i).collect();
    let staff = line.staff;
    let mut input = SlurInput { entries: &mut work, note_entry, staff, begin, end, staff_end };
    let made: Vec<score_format::Item> = pairs.iter().flat_map(|c| input.items(c)).collect();
    line.take_marks(&work);
    line.attachments.extend(made);
    Ok(())
}
