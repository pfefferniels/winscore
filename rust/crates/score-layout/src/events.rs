//! One staff's events for the line-up: the positions where something starts,
//! each with a duration (the shortest value still sounding, in P7 units) or a marker (the
//! negated code of a clef, barline, key or meter).

use crate::num::{trunc, wide};
use crate::rows::{Row, BARLINE, CLEF, KEY, METER, REST};

/// Notes and rests with a P7 from here on are left to the grace-note pass.
pub const LONG_VALUE: f32 = 64.0;
/// Right edge of the area the line-up looks at.
const AREA_RIGHT: f32 = 200.05;

/// A marker for a barline with P12 > 0.
pub const BARLINE_P12: f32 = -140.0;

#[derive(Debug, Clone, Default, PartialEq)]
pub struct StaffEvents {
    pub positions: Vec<f32>,
    /// Durations (> 0) and markers (< 0), one per position.
    pub entries: Vec<f32>,
    pub total: f32,
    /// A note or rest with P7 >= 64 was seen.
    pub saw_long: bool,
}

/// An event lasts as long as its shortest open value; the others carry over,
/// reduced by it.
fn shortest_open_value(values: &[f32]) -> (f32, Vec<f32>) {
    let Some((&first, rest)) = values.split_first() else {
        return (0.0, Vec::new());
    };
    if rest.is_empty() {
        return (first, Vec::new());
    }
    let at = (1..values.len()).fold(0, |at, k| if values[k] <= values[at] { k } else { at });
    let least = values[at];
    let mut others = values.to_vec();
    others[at] = first;
    others[0] = least;
    let carried = others[1..].iter().map(|v| v - least).filter(|r| *r > 0.001).collect();
    (least, carried)
}

pub fn p14_or_p15(row: &Row) -> bool {
    row.len() >= 14 && (row.par(14) != 0.0 || (row.len() >= 15 && row.par(15) != 0.0))
}

/// A meter shifted by more than 2 (P4 times P7) is no event.
fn meter_off_staff(row: &Row) -> bool {
    if row.code() != METER || row.len() <= 3 {
        return false;
    }
    let scale = if row.len() > 6 && row.par(7) != 0.0 { row.par(7) } else { 1.0 };
    (wide(scale) * wide(row.par(4))).abs() > 2.0
}

fn moved_by_interpolation(code: i32) -> bool {
    3 < code && code < 17 && code != BARLINE
}

/// Where the scan for staff `staff` stopped, in 1-based item numbers.
struct Scan {
    first: usize,
    next_start: usize,
    end: usize,
}

/// Phase 1 of the event scan: the first item of the staff that starts an event, the
/// first item of the next staff, and where the scan ended.
fn first_event_item(rows: &mut [Row], start: usize, staff: i32) -> Scan {
    let n = rows.len();
    let mut i = start - 1;
    let mut first = 0;
    let next_start = start;
    if i >= n {
        return Scan { first: 0, next_start, end: i };
    }
    loop {
        i += 1;
        let row = &mut rows[i - 1];
        if first == 0 {
            let mut x = row.x();
            if !(wide(x) > wide(AREA_RIGHT) || row.staff() < staff) {
                if wide(x).abs() <= wide(0.01) {
                    if row.len() > 2 {
                        row.set_x(0.0);
                    }
                    x = 0.0;
                }
                let code = row.code();
                if !(moved_by_interpolation(code) || x < 0.0) {
                    if row.staff() != staff {
                        return Scan { first: 0, next_start, end: i };
                    }
                    let ending_bar = code == BARLINE && row.len() > 4 && (8..=10).contains(&trunc(row.par(5)));
                    let off_staff = code > 16 && ((code == METER && meter_off_staff(row)) || p14_or_p15(row));
                    if !(ending_bar || off_staff) {
                        first = i;
                    }
                }
            }
            if first == 0 {
                if i < n {
                    continue;
                }
                return Scan { first: 0, next_start, end: i };
            }
        } else if staff < row.staff() {
            return Scan { first, next_start: i, end: i };
        }
        if n <= i {
            return Scan { first, next_start, end: i + 1 };
        }
    }
}

/// The events of staff `staff`, scanning from item `start` (1-based); also returns the
/// first item of the next staff.
pub fn staff_events(rows: &mut [Row], start: usize, staff: i32) -> (usize, StaffEvents) {
    let scan = first_event_item(rows, start, staff);
    if scan.first == 0 {
        return (scan.next_start, StaffEvents::default());
    }
    let last = (scan.first..scan.end).rev().find(|&i| {
        let code = rows[i - 1].code();
        !(CLEF..=16).contains(&code) || code == BARLINE
    });
    let Some(last) = last else {
        return (scan.next_start, StaffEvents::default());
    };
    if (wide(200.0) - wide(rows[last - 1].x())).abs() <= wide(0.01) {
        rows[last - 1].set_x(200.0);
    }

    let mut collect = Collector::default();
    for row in &rows[scan.first - 1..last] {
        collect.add(row);
    }
    let (mut entries, positions, saw_long) = collect.finish();
    let total = round_to_beats(&mut entries);
    if total == 0.0 {
        return (scan.next_start, StaffEvents { saw_long, ..StaffEvents::default() });
    }
    (scan.next_start, StaffEvents { positions, entries, total, saw_long })
}

#[derive(Default)]
struct Collector {
    positions: Vec<f32>,
    entries: Vec<f32>,
    open: Vec<f32>,
    last_x: Option<f32>,
    saw_long: bool,
}

impl Collector {
    fn last_x(&self) -> f64 {
        self.last_x.map_or(-990.0, wide)
    }

    fn new_event(&mut self, x: f32) {
        if !self.positions.is_empty() {
            let (duration, carried) = shortest_open_value(&self.open);
            self.entries.push(duration);
            self.open = carried;
        }
        self.positions.push(x);
        self.last_x = Some(x);
    }

    fn add(&mut self, row: &Row) {
        let x = row.x();
        if wide(x) > wide(AREA_RIGHT) {
            return;
        }
        let code = row.code();
        if code <= REST {
            let value = row.par(7);
            if row.len() > 6 && value > 0.0 {
                if value >= LONG_VALUE {
                    self.saw_long = true;
                    return;
                }
                if (wide(x) - self.last_x()).abs() > wide(0.1) {
                    self.new_event(x);
                }
                self.open.push(value);
            }
        } else if (code > 16 || code == BARLINE || code == CLEF) && self.last_x() != wide(x) {
            if (code == METER && meter_off_staff(row)) || (code >= KEY && p14_or_p15(row)) {
                return;
            }
            let marker = if code == BARLINE && row.len() > 11 && row.par(12) > 0.0 { BARLINE_P12 } else { -(code as f32) };
            if code != CLEF || row.len() < 5 || row.par(5) < 44.0 {
                self.new_event(x);
                self.open.push(marker);
            }
        }
    }

    fn finish(mut self) -> (Vec<f32>, Vec<f32>, bool) {
        if !self.positions.is_empty() {
            let (duration, _) = shortest_open_value(&self.open);
            self.entries.push(duration);
        }
        (self.entries, self.positions, self.saw_long)
    }
}

/// Snaps running totals within 0.005 of a whole beat onto it (adjusting the duration that
/// got there) and returns the staff's total duration.
fn round_to_beats(entries: &mut [f32]) -> f32 {
    let mut running = 0.0f32;
    let mut total = 0.0f32;
    for entry in entries.iter_mut() {
        let mut d = *entry;
        if d > 0.0 {
            running += d;
            let fraction = (wide(running) - f64::from(trunc(running))) as f32;
            let missing = 1.0 - fraction;
            if fraction != 0.0 && (fraction <= 0.005 || missing <= 0.005) {
                if fraction <= 0.005 {
                    running -= fraction;
                    d -= fraction;
                } else {
                    running += missing;
                    d += missing;
                }
                *entry = d;
            }
        }
        if d > 0.0 {
            total += d;
        }
    }
    total
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn shortest_value_carries_the_rest() {
        assert_eq!(shortest_open_value(&[1.0, 0.5, 2.0]), (0.5, vec![0.5, 1.5]));
        assert_eq!(shortest_open_value(&[1.0]), (1.0, vec![]));
    }

    #[test]
    fn totals_snap_to_beats() {
        let mut entries = [0.333, 0.333, 0.336, -14.0];
        assert!((round_to_beats(&mut entries) - 1.0).abs() < 1e-6);
        assert!((entries[2] - 0.334).abs() < 1e-6);
    }
}
