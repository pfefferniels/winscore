//! J, the justification: every staff of the system gets columns with the room their items
//! need on either side, the staves' columns are merged, and gaps that are too narrow widen
//! at the expense of gaps with room to spare.
//!
//! The engine keeps some of the column pass's values in globals from one item and one
//! staff to the next (and mixes item store offsets with list indices in one of them);
//! `State` holds those, starting from zero as in a fresh engine.

use std::collections::BTreeMap;

use crate::events::p14_or_p15;
use crate::num::{amod, fmod, trunc, wide};
use crate::rows::{Row, BARLINE, BEAM, CLEF, KEY, METER, NOTE, REST, STAFF};

/// The engine's f32 table, indexed from -5: shifted head, wide head, head, then the
/// accidental widths by P5 mod 10 (9 more above P5 = 100).
const TABLE: [f32; 24] = [
    0.0, 0.0, 0.0, 2.833, 5.0, 4.5, 2.0, 2.4, 2.1, 4.0, 2.5, 2.0, 3.4, 2.0, 2.8, 4.1, 4.6, 4.1, 6.2, 4.5, 0.0, 0.0, 0.0, 0.0,
];
const HEAD: f32 = 4.5;
const WIDE_HEAD: f32 = 5.0;
const SHIFTED_HEAD: f32 = 2.833;
/// Left room after a clef, barline, key or meter on small staves.
const AFTER_CLEF: f32 = 1.8;
const AFTER_BARLINE: f32 = 1.5;
const AFTER_KEY: f32 = 2.8;
const AFTER_METER: f32 = 0.9;
const NUMBER: i32 = 10;
const LINE: i32 = 4;

fn table(index: i32) -> f32 {
    usize::try_from(index + 5).ok().and_then(|i| TABLE.get(i)).copied().unwrap_or(0.0)
}

/// Fractions of P5 or P9 above 0.9 count downwards from 0.9.
fn tenths(value: f32) -> f32 {
    let fraction = amod(value, 1.0);
    if fraction > 0.9 {
        0.9 - fraction
    } else {
        fraction
    }
}

/// The parameters J may move, as (1-based item, parameter); `None` once a stretch has
/// handled it.
struct Selection {
    refs: Vec<Option<(usize, usize)>>,
}

fn select_box(rows: &mut [Row], (lo, hi): (i32, i32), (x0, x1): (f32, f32), right: f32) -> Selection {
    let low = x0 - 0.001;
    let high = (if x1 != 0.0 { x1 } else { 200.0 }) + 0.001;
    let mut refs = Vec::new();
    for (index, row) in rows.iter_mut().enumerate() {
        let i = index + 1;
        let (staff, code) = (row.staff(), row.code());
        if !(lo..=hi).contains(&staff) {
            continue;
        }
        let mut maybe = |row: &Row, k: usize| {
            if k <= row.len() && low <= row.par(k) && row.par(k) <= high {
                refs.push(Some((i, k)));
            }
        };
        maybe(row, 3);
        let n = row.len();
        if !(n > 5 && 3 < code && code < 9) {
            continue;
        }
        if code == STAFF && row.par(6) == 0.0 {
            row.set(6, right);
        }
        if code == LINE && n >= 7 && row.par(7) < 0.0 && row.par(6) == 0.0 {
            continue;
        }
        maybe(row, 6);
        if n <= 7 {
            continue;
        }
        if code == LINE {
            if row.par(7) == 100.0 {
                maybe(row, 8);
                for k in (10..=n.min(16)).step_by(2) {
                    maybe(row, k);
                }
            }
        } else if code == BEAM {
            if n > 10 {
                if row.par(11) > 0.0 {
                    maybe(row, 11);
                }
                if row.par(7) >= 0.0 && n > 11 {
                    if row.par(12) > 0.0 {
                        maybe(row, 12);
                    }
                    if n > 13 && row.par(13) != 0.0 {
                        if row.par(14) > 0.0 {
                            maybe(row, 14);
                        }
                        if n > 14 && row.par(15) > 0.0 {
                            maybe(row, 15);
                        }
                    }
                }
            }
        } else if (code == 7 || code == STAFF) && trunc(row.par(7)) > 19 && row.par(8) > 0.0 {
            maybe(row, 8);
        }
    }
    Selection { refs }
}

/// Globals of the column pass that carry over between items and staves.
#[derive(Default)]
struct State {
    /// The P array (P3..P14 of the item loaded last).
    p: [f32; 15],
    p_staff: i32,
    /// Items before it are ignored (except barlines); set from a column index.
    start: usize,
    ledger_cur: i32,
    small_clef: bool,
    g938: f32,
    chord_first: usize,
    chord_scan: usize,
    prev_p4m: f32,
    prev_p5: f32,
    prev_p9m: f32,
}

impl State {
    /// P3..P14 into the P array (zeros beyond the item); returns the length.
    fn load(&mut self, row: &Row) -> usize {
        for k in 3..=14 {
            self.p[k] = if k <= row.len().min(14) { row.par(k) } else { 0.0 };
        }
        self.p_staff = row.staff();
        if self.p[6] <= -4.0 && row.par(1) == 1.0 {
            self.p[5] = 0.0;
            self.p[9] = 0.0;
        }
        row.len()
    }
}

/// Left and right need of a barline; `p[8]` holds the size factor.
fn barline_widths(p: &[f32; 15], length: usize, prev: i32) -> (f32, f32) {
    let mut right = 2.5f32;
    let mut left = 1.0f32;
    let kind = trunc(p[5]);
    if length >= 5 && (1..=6).contains(&kind) {
        let (f, p13, p14) = (wide(p[8]), wide(p[13]), wide(p[14]));
        let at = |a: f32| (f * wide(a)) as f32;
        match kind {
            4 => {
                left = at(2.0);
                right = (f * 6.0 + p13 + p14) as f32;
            }
            5 => {
                left = (f * wide(5.4) + p13 + p14) as f32;
                right = (f * 6.0 + p13 + p14) as f32;
            }
            6 => {
                left = (f * wide(4.3) + p14) as f32;
                right = (f * 7.0 + p13 + p14) as f32;
            }
            _ => {
                let base = match kind {
                    1 => at(2.2),
                    2 => at(3.3),
                    _ => (f * wide(5.4) + p14) as f32,
                };
                left = p[13] + base;
            }
        }
    }
    if prev == CLEF || prev == KEY {
        left -= 1.0;
    }
    if p[7] != 0.0 {
        left -= p[7];
        right += p[7];
    }
    (left, right)
}

fn rest_widths(row: &Row, p: &mut [f32; 15]) -> (f32, f32) {
    let mut left = 0.0f32;
    let mut right = 4.5f32;
    let mut p5 = p[5];
    if p5.abs() >= 100.0 {
        p5 = fmod(p5, 100.0);
        p[5] = p5;
        right = 5.0;
    }
    if p5 >= 0.0 {
        if p5 > 1.0 {
            right = ((wide(p5) - 1.0) * wide(0.5) + wide(right)) as f32;
        }
    } else {
        right = if p5 == -4.0 { 9.5 } else { 6.0 };
        if row.len() > 8 && row.par(9) != 0.0 {
            right = 1.0;
        }
    }
    if p[6] != 0.0 {
        right = (wide(p[6]) * wide(1.75) + wide(right)) as f32;
    }
    if row.len() > 9 && row.par(10) != 0.0 {
        left = -row.par(10);
        right += row.par(10);
    }
    (left, right)
}

fn key_widths(p: &[f32; 15], prev: i32) -> (f32, f32) {
    let left = if prev == NOTE { 2.0 } else { 0.0 };
    let count = (wide(p[5]) - (wide(p[5]) / 100.0).trunc() * 100.0).abs() as f32;
    let right = if prev == CLEF { 5.5 } else { 4.5 };
    let scale = if p[7] != 0.0 { p[7] } else { 1.0 };
    (left, ((wide(count) - 1.0) * wide(2.8) * wide(scale) + wide(right)) as f32)
}

/// A meter after a barline shortens the barline's right need.
fn meter_widths(row: &Row, prev: i32, rights: &mut [f32]) -> (f32, f32) {
    let mut left = 0.0f32;
    let mut right = 7.5f32;
    if prev == BARLINE {
        if let Some(last) = rights.last_mut() {
            *last -= 1.5;
        }
        left = 0.5;
    }
    if prev == NOTE {
        left = 2.0;
    }
    if prev == KEY {
        left = -1.5;
    }
    let p = |k: usize| row.par(k);
    if (p(5) >= 10.0 || p(6) >= 10.0) && p(5) <= 90.0 {
        right += 2.5;
    }
    let last = (1..=row.len()).rev().find(|&k| p(k) != 0.0).unwrap_or(0);
    if last > 7 {
        let mut extra = 0.0f32;
        if last < 12 || p(12) == 0.0 {
            extra = 4.5;
            if last > 9 && p(10) != 0.0 {
                extra = 4.5 + p(10);
            }
        }
        if last > 10 && p(11) != 0.0 {
            extra += p(11);
        }
        let gap: f32 = if p(8) > 10.0 || p(9) > 10.0 { 6.0 } else { 3.5 };
        right = (wide(extra) + wide(right) + wide(gap)) as f32;
    }
    (left, right)
}

/// Column positions and the need of the gap after each.
struct Columns {
    x: Vec<f32>,
    need: Vec<f32>,
}

/// The column pass for one staff.
struct StaffColumns<'a, 'b> {
    rows: &'a mut [Row],
    st: &'b mut State,
    /// Item store offset of every item (1-based, index 0 unused).
    words: &'b [usize],
    lo: i32,
    step: f32,
    staff: i32,
    x_left: f32,
    x_right: f32,
    /// 1-based x and item of the collected items, with zeros around them.
    xs: Vec<f32>,
    who: Vec<usize>,
    n: usize,
    scale: f32,
    cols: Vec<f32>,
    rights: Vec<f32>,
    lefts: Vec<f32>,
    prev_code: i32,
    prev_p12: f32,
    ledger: i32,
}

impl StaffColumns<'_, '_> {
    /// Item `i` (1-based); 0 reads the last item, as the engine's table lookups do.
    fn item(&self, i: usize) -> &Row {
        &self.rows[(i + self.rows.len() - 1) % self.rows.len()]
    }

    fn collected(&self, j: usize) -> &Row {
        self.item(self.who[j])
    }

    fn w_of(&self, j: usize) -> usize {
        match self.who.get(j) {
            Some(&w) if j > 0 && j <= self.n + 1 && w != 0 => self.words[w],
            _ => 0,
        }
    }

    fn collect(&mut self) {
        let x0 = self.x_left - 0.001;
        let x1 = self.x_right + 0.001;
        let mut picked: Vec<(f32, usize)> = Vec::new();
        for i in 1..=self.rows.len() {
            let row = &self.rows[i - 1];
            let code = row.code();
            let numbered = code == NUMBER && row.len() > 15 && row.par(16) != 0.0;
            if !(code < 5 || code == BARLINE || numbered || (code > 16 && !p14_or_p15(row))) {
                continue;
            }
            let length = self.st.load(row);
            let p = self.st.p;
            if self.staff < self.st.p_staff {
                break;
            }
            if !(x0 <= p[3] && p[3] <= x1) {
                continue;
            }
            if code == BARLINE {
                if self.lo <= self.st.p_staff && p[4] >= 0.0 && p[5] <= 7.0 {
                    let span = if p[4] != 0.0 { p[4] } else { 1.0 };
                    if f64::from(self.staff) < f64::from(self.st.p_staff) + wide(span) {
                        picked.push((p[3], i));
                    }
                }
                continue;
            }
            if !(self.st.start <= i && self.staff == self.st.p_staff) {
                continue;
            }
            let skip = match code {
                NOTE => p[7] < 0.0,
                REST => p[6] < 0.0 || p[7] < 0.0,
                CLEF => p[5] > 5.0,
                LINE => row.par(6) != 0.0 || length < 7 || row.par(7) > -1.0,
                METER => (wide(if p[7] != 0.0 { p[7] } else { 1.0 }) * wide(p[4])).abs() > 2.0,
                _ => false,
            };
            if !skip {
                picked.push((p[3], i));
            }
        }
        picked.sort_by(|a, b| a.0.partial_cmp(&b.0).unwrap_or(std::cmp::Ordering::Equal));
        self.n = picked.len();
        self.xs = std::iter::once(0.0).chain(picked.iter().map(|e| e.0)).chain(std::iter::once(0.0)).collect();
        self.who = std::iter::once(0).chain(picked.iter().map(|e| e.1)).chain(std::iter::once(0)).collect();
    }

    fn run(mut self) -> Option<Columns> {
        self.collect();
        let n = self.n;
        if n <= 1 {
            return None;
        }
        self.scale = self.step * 0.04;
        self.cols = vec![self.x_left - 0.001];
        self.rights = vec![0.0];
        self.lefts = vec![0.0];
        self.prev_p12 = 0.0;
        self.ledger = 0;
        let mut k = 0;
        loop {
            k = self.one_item(k + 1);
            if k >= n {
                break;
            }
        }
        self.st.start = k;
        let rights = if self.cols.len() != 1 {
            let lefts = self.lefts.iter().skip(1).copied().chain(std::iter::once(0.0));
            self.rights.iter().zip(lefts).map(|(r, l)| ((wide(*r) + wide(l)) * wide(self.scale)) as f32).collect()
        } else {
            self.rights.clone()
        };
        Some(Columns { x: self.cols, need: rights })
    }

    fn one_item(&mut self, k: usize) -> usize {
        let w = self.who[k];
        let row = self.item(w).clone();
        let code = trunc(row.par(1));
        let length = self.st.load(&row);
        let p4m = amod(self.st.p[4], 100.0);
        let (k, left, right) = if code < 2 {
            match self.note(k, w, length, p4m) {
                None => return k,
                Some(found) => found,
            }
        } else {
            self.ledger = 0;
            let (left, right) = self.other(k, &row, code, length);
            (k, left, right)
        };
        self.add_to_column(code, left, right);
        k
    }

    fn note(&mut self, k: usize, w: usize, length: usize, p4m: f32) -> Option<(usize, f32, f32)> {
        let n = self.n;
        let p6i = trunc(self.st.p[6]);
        let mut head = if p6i < 20 && matches!(p6i % 10, 2 | 3) { WIDE_HEAD } else { HEAD };
        let mut j = k;
        if trunc(self.st.p[5]) > 100 {
            self.st.p[5] = amod(self.st.p[5], 100.0);
        }
        let mut stem = (wide(self.st.p[5]) / 10.0) as i32;
        let mut broke = false;
        while stem != 1 {
            if stem != 0 || n <= j {
                broke = true;
                break;
            }
            j += 1;
            self.st.chord_scan = self.w_of(j);
            let other = self.collected(j);
            if other.par(1) != 1.0 || self.st.p[3] != other.x() {
                broke = true;
                break;
            }
            stem = (trunc(other.par(5)) % 100) / 10;
        }
        if !broke {
            if j >= n {
                return None;
            }
            head = self.flag_room(j, head);
        }
        Some(self.chord(k, w, length, head, p4m, p6i))
    }

    /// Room for the flag of an up-stem note unless the next item at its x continues the
    /// chord with a stem.
    fn flag_room(&mut self, mut j: usize, head: f32) -> f32 {
        let n = self.n;
        self.st.chord_scan = self.w_of(j + 1);
        let mut other = self.collected(j + 1).clone();
        let mut c2 = trunc(other.par(1));
        let mut jump = c2 == BARLINE;
        if !jump {
            self.st.g938 = other.x();
            while c2 == NOTE {
                let tail = trunc(other.par(5)) % 100;
                if tail > 19 {
                    jump = true;
                    break;
                }
                if tail > 9 || self.st.g938 != other.x() || n <= j {
                    break;
                }
                j += 1;
                self.st.chord_scan = self.w_of(j);
                other = self.collected(j).clone();
                c2 = trunc(other.par(1));
            }
            if !jump {
                return head;
            }
        }
        loop {
            j += 1;
            if n <= j {
                break;
            }
            self.st.chord_scan = self.w_of(j + 1);
            let other = self.collected(j + 1);
            if trunc(other.par(1)) != NOTE || self.st.g938 != other.x() {
                break;
            }
            let tail = trunc(other.par(5)) % 100;
            if tail >= 10 {
                if tail <= 19 {
                    return head;
                }
                break;
            }
        }
        self.st.g938 = if self.st.p[9] != 0.0 { 0.5 } else { 1.5 };
        self.st.g938 + head
    }

    /// The left and right needs of the chord that starts at collected item k.
    fn chord(&mut self, k: usize, w: usize, length: usize, head: f32, p4m: f32, p6i: i32) -> (usize, f32, f32) {
        let n = self.n;
        if self.ledger != self.st.ledger_cur {
            self.ledger = 0;
        }
        self.st.ledger_cur = 0;
        let first = k;
        let mut m = k + 1;
        let mut count = n as i64 - k as i64 + 1;
        let mut k = k;
        let p5_first = self.st.p[5];
        while count > 0 {
            k = m;
            let joins = m <= n && self.collected(m).par(1) == 1.0 && self.xs[m] - self.xs[m - 1] < 0.1;
            if !joins {
                break;
            }
            self.xs[m] = self.xs[m - 1];
            m += 1;
            count -= 1;
        }
        k -= 1;
        let mut size: f32 = if self.st.p[4].abs() >= 100.0 { 0.7 } else { 1.0 };
        if length > 14 && self.item(w).par(15) != 0.0 {
            size *= self.item(w).par(15);
        }
        let mut left_max = 0.0f32;
        self.st.g938 = 0.0;
        for m in first..=k {
            let row = self.collected(m).clone();
            if row.par(1) != 1.0 {
                continue;
            }
            let (left, right) = self.note_extent(&row, head, p4m, p6i, p5_first, size);
            left_max = left_max.max(left);
            self.st.g938 = self.st.g938.max(right);
        }
        let left = size * left_max;
        let right = ((wide(head) + wide(self.st.g938)) * wide(size)) as f32;
        self.st.chord_first = first;
        self.st.chord_scan = k;
        self.st.prev_p4m = p4m;
        self.st.prev_p5 = p5_first;
        self.st.prev_p9m = if length > 8 { amod(self.item(w).par(9), 10.0) } else { 0.0 };
        self.prev_p12 = self.st.p[12];
        (k, left, right)
    }

    fn note_extent(&mut self, row: &Row, head: f32, p4m: f32, p6i: i32, p5_first: f32, size: f32) -> (f32, f32) {
        let mut left_acc = 0.0f32;
        let mut right_acc = 0.0f32;
        let mut extra = 0.0f32;
        let mut n3 = self.st.load(row) as i64;
        if n3 > 8 && self.st.p[9] != 0.0 {
            let dots = self.st.p[9];
            let units = trunc(dots) % 10;
            let tens = (trunc(dots) % 100) / 10;
            if units != 0 && amod(self.st.p[5], 100.0) < 20.0 {
                extra = size * 2.3;
            }
            let fraction = ((wide(tenths(dots)) * wide(10.0)) + f64::from(tens) * wide(1.7)) as f32;
            if extra < fraction {
                extra = fraction;
            }
        }
        let mut shift = 0.0f32;
        if n3 > 9 && row.par(10) != 0.0 {
            shift = row.par(10);
            if shift == 110.0 {
                shift = 10.0;
            }
            if shift == 10.0 || shift == 20.0 {
                let width = if head == WIDE_HEAD { HEAD } else { SHIFTED_HEAD };
                if shift < 20.0 {
                    right_acc = width;
                } else {
                    right_acc = -right_acc;
                    self.ledger = 0;
                    left_acc = width;
                }
            } else if shift >= 0.0 {
                n3 = -1;
                right_acc = shift;
            } else {
                left_acc = -shift;
            }
        }
        right_acc += extra;
        let p5i = trunc(self.st.p[5]);
        let mut accidental = p5i % 10;
        if accidental != 0 {
            self.ledger = 0;
            if p5i > 100 {
                accidental += 9;
            }
            let mut width = table(accidental);
            let p12 = self.st.p[12];
            let mut skip = false;
            if self.prev_code == NOTE && self.st.chord_scan == self.st.chord_first {
                if self.prev_p12 != p12 {
                    skip = true;
                    if self.st.prev_p5 < 20.0 && p5_first < 20.0 {
                        let t = if p12 == 1.0 { -1.0 } else { p12 };
                        if self.prev_p12 == 1.0 {
                            self.prev_p12 = -1.0;
                        }
                        skip = t >= self.prev_p12;
                    }
                } else if (wide(self.st.prev_p4m) - wide(p4m)).abs() >= 4.0 {
                    if self.st.prev_p5 < 20.0 {
                        if p4m < self.st.prev_p4m {
                            width -= 1.5;
                        }
                    } else if self.st.prev_p4m < p4m || self.st.prev_p9m == 0.0 {
                        width -= 1.5;
                    }
                }
            }
            if !skip {
                left_acc = (wide(tenths(self.st.p[5])) * wide(10.0) + (wide(width) + wide(left_acc))) as f32;
                if n3 < 0 {
                    left_acc -= shift;
                }
            }
        }
        self.st.p[4] = amod(self.st.p[4], 100.0);
        self.st.ledger_cur = i32::from(self.st.p[4] > 12.0);
        if self.st.p[4] < 2.0 {
            self.st.ledger_cur = -1;
        }
        if self.st.ledger_cur == 0 || self.st.ledger_cur != self.ledger {
            self.ledger = self.st.ledger_cur;
        } else if left_acc < 1.3 {
            left_acc = 1.3;
        }
        if 9 < p6i && p6i < 20 {
            left_acc += 1.7;
            right_acc += 1.8;
        }
        (left_acc, right_acc)
    }

    /// Left and right need of anything but a note.
    fn other(&mut self, k: usize, row: &Row, code: i32, length: usize) -> (f32, f32) {
        match code {
            BARLINE => {
                self.st.p[8] = if length > 16 { row.par(17) / self.scale } else { 1.0 };
                barline_widths(&self.st.p, length, self.prev_code)
            }
            REST => rest_widths(row, &mut self.st.p),
            CLEF => self.clef_widths(k),
            LINE => {
                let left = match self.prev_code {
                    c if c == CLEF || c > 16 => 0.0,
                    BARLINE => 0.2,
                    _ => 1.3,
                };
                if length >= 15 {
                    self.p15_shift(row, left, 1.8)
                } else {
                    (left, 1.8)
                }
            }
            NUMBER => {
                let width = if self.st.p[6] != 0.0 { self.st.p[6] * 4.0 } else { 4.0 };
                self.p15_shift(row, 0.2, width)
            }
            KEY => key_widths(&self.st.p, self.prev_code),
            _ => {
                let (left, right) = meter_widths(row, self.prev_code, &mut self.rights);
                if self.n == k {
                    return (left, right - 2.5);
                }
                let f = if self.scale < 1.0 { ((1.0 - wide(self.scale)) / 2.0 + wide(self.scale)) as f32 } else { self.scale };
                (left, if f < 1.0 { right * f } else { right })
            }
        }
    }

    fn clef_widths(&mut self, k: usize) -> (f32, f32) {
        let right = if self.st.p[4] >= 100.0 { 6.5 } else { 7.5 };
        self.st.small_clef = self.st.p[4] >= 100.0;
        if self.prev_code == BARLINE {
            self.shorten_right();
            return (0.0, right);
        }
        let left = if self.prev_code == NOTE { 1.0 } else { 0.0 };
        if self.n != k {
            if self.cols.len() == 1 {
                self.shorten_right();
            } else {
                self.move_clef_clear(k, right);
            }
        }
        (left, right)
    }

    /// A clef too close to the column before moves right, when there is room before the
    /// next item; its P3 is written.
    fn move_clef_clear(&mut self, k: usize, right: f32) {
        let x = self.st.p[3];
        if wide(self.scale) * wide(right) <= wide(self.xs[k + 1]) - wide(x) {
            let mut t = self.rights[self.rights.len() - 1];
            if wide(x) - wide(self.xs[k - 1]) < wide(t) {
                t += self.xs[k - 1];
                if wide(t) < wide(self.xs[k + 1]) - wide(0.2) {
                    self.st.p[3] = t;
                    let i = self.who[k];
                    let len = self.rows.len();
                    self.rows[(i + len - 1) % len].set_x(t);
                }
            }
        }
    }

    fn shorten_right(&mut self) {
        if let Some(last) = self.rights.last_mut() {
            let mut t = *last;
            if t >= 3.0 {
                t -= 1.0;
            }
            if t < 3.0 {
                t = 2.0;
            }
            *last = t;
        }
    }

    fn p15_shift(&self, row: &Row, left: f32, right: f32) -> (f32, f32) {
        let t = row.par(15) / self.scale;
        (left - t, t + right)
    }

    fn add_to_column(&mut self, code: i32, left: f32, right: f32) {
        let x = self.st.p[3];
        let last_col = self.cols[self.cols.len() - 1];
        if (wide(x) - wide(last_col)).abs() >= wide(0.03) {
            self.cols.push(x);
            self.rights.push(0.0);
            self.lefts.push(0.0);
        }
        let last = self.lefts.len() - 1;
        if code == METER || self.lefts[last] < left {
            self.lefts[last] = left;
        }
        if self.rights[last] < right {
            self.rights[last] = right;
        }
        if code < 3 || code == LINE {
            let scale = self.scale;
            let mut extra = 0.0f32;
            if self.prev_code == BARLINE {
                extra = AFTER_BARLINE / scale - 2.5;
            }
            if self.prev_code == KEY {
                extra = AFTER_KEY / scale - 2.8;
            }
            if self.prev_code == METER {
                extra = AFTER_METER / scale - 3.7;
            }
            if self.prev_code == CLEF && !self.st.small_clef {
                extra = AFTER_CLEF / scale - 1.8;
            }
            if extra > 0.0 {
                self.lefts[last] += extra;
            }
        }
        self.prev_code = code;
    }
}

/// The part of a gap's need up to `cut`, proportional, at least `least`.
fn split_gap(out: &mut Columns, cut: f32, other: f32, widths: &mut [f32], index: usize, least: f32) {
    let prev = out.x[out.x.len() - 1];
    let mut part = (((wide(cut) - wide(prev)) * wide(widths[index])) / (wide(other) - wide(prev))) as f32;
    if part < least {
        part = least;
    }
    out.need.push(part);
    widths[index] -= part;
    out.x.push(cut);
}

/// The two-pointer merge of J; lists start with the box start.
fn merge_columns(master: Columns, staff: Columns, x_left: f32, x_right: f32) -> Columns {
    let (mx, mut mw) = (master.x, master.need);
    let (cx, mut cw) = (staff.x, staff.need);
    let mut out = Columns { x: vec![x_left], need: Vec::new() };
    let stop = x_right - 0.2;
    let (mut i, mut j) = (0, 0);
    loop {
        let (Some(&c_next), Some(_)) = (cx.get(i + 1), cw.get(i)) else {
            return out;
        };
        let mut ac = c_next;
        let mut advanced_staff = false;
        let mut a8;
        loop {
            let (Some(&m_next), Some(_)) = (mx.get(j + 1), mw.get(j)) else {
                return out;
            };
            a8 = m_next;
            if (wide(ac) - wide(a8)).abs() <= wide(0.1) {
                break;
            }
            if ac < a8 {
                split_gap(&mut out, ac, a8, &mut mw, j, cw[i]);
                advanced_staff = true;
                break;
            }
            split_gap(&mut out, a8, ac, &mut cw, i, mw[j]);
            j += 1;
        }
        if !advanced_staff {
            if a8 < ac {
                ac = a8;
            }
            let need = if mw[j] < cw[i] { cw[i] } else { mw[j] };
            out.need.push(need);
            out.x.push(ac);
            if stop <= ac {
                return out;
            }
            j += 1;
        }
        i += 1;
    }
}

/// The gap widening, with the stretch inside a gap and the shift from x.
struct Distributor<'a> {
    rows: &'a mut [Row],
    selection: Selection,
    right_limit: f32,
    floor: f32,
    amount: f32,
}

impl Distributor<'_> {
    fn value(&self, (i, k): (usize, usize)) -> f32 {
        self.rows[i - 1].par(k)
    }

    fn put(&mut self, (i, k): (usize, usize), v: f32) {
        self.rows[i - 1].set(k, v);
    }

    fn stretch(&mut self, a: f32, b: f32) {
        let span = b - a;
        if span == 0.0 {
            return;
        }
        // The numerator is stored as f32 before the division.
        let mut factor = (self.amount + span) / span;
        if factor <= 0.2 {
            factor = 1.0;
        }
        for n in 0..self.selection.refs.len() {
            let Some(r) = self.selection.refs[n] else {
                continue;
            };
            let value = self.value(r);
            if a <= value && value <= b {
                let v = ((wide(value) - wide(a)) * wide(factor) + wide(a)) as f32;
                self.put(r, if v < self.floor { self.floor } else { v });
                self.selection.refs[n] = None;
            }
        }
        self.floor = a + 0.2;
    }

    fn shift_from(&mut self, x: f32) {
        for n in 0..self.selection.refs.len() {
            if let Some(r) = self.selection.refs[n] {
                let value = self.value(r);
                if x <= value {
                    self.put(r, self.amount + value);
                }
            }
        }
    }

    fn run(&mut self, x_left: f32, x_right: f32, mut xs: Vec<f32>, mut needs: Vec<f32>) {
        let n = xs.len();
        let gaps = n.saturating_sub(1);
        needs.resize(needs.len().max(gaps), 0.0);
        let need = needs[..gaps].iter().fold(0.0f32, |sum, w| sum + w);
        let avail = x_right - x_left;
        if avail < need {
            let cut = ((wide(need) - wide(avail)) / gaps as f64) as f32;
            needs[..gaps].iter_mut().for_each(|w| *w -= cut);
        }
        let free: Vec<f32> = (0..gaps).map(|k| ((wide(xs[k + 1]) - wide(xs[k])) - wide(needs[k])) as f32).collect();
        let (plus, minus) = free.iter().fold((0.0f32, 0.0f32), |(plus, minus), &f| if f >= 0.0 { (f + plus, minus) } else { (plus, minus - f) });
        if minus == 0.0 || plus == 0.0 {
            return;
        }
        let ratio = minus / plus;
        self.floor = -9999.0;
        for i in 1..n {
            let mut amount = -free[i - 1];
            if amount < 0.0 {
                amount *= ratio;
            }
            self.amount = amount;
            if amount == 0.0 {
                continue;
            }
            if amount < 0.0 {
                self.stretch(xs[i - 1], xs[i]);
                self.shift_from(xs[i]);
                xs[i..n].iter_mut().for_each(|x| *x += amount);
            } else {
                let old = xs[i];
                self.shift_from(old);
                xs[i..n].iter_mut().for_each(|x| *x += amount);
                self.stretch(xs[i - 1], old);
            }
        }
        let right = self.right_limit;
        for row in self.rows.iter_mut().filter(|r| r.len() >= 3) {
            if wide(row.x()).abs() < wide(0.01) {
                row.set_x(0.0);
            }
            if (wide(right) - wide(row.x())).abs() < wide(0.01) {
                row.set_x(right);
            }
        }
    }
}

/// J on staves `lo..=hi` between `x_left` and `x_right`.
pub fn justify(rows: &mut [Row], (lo, hi): (i32, i32), (x_left, x_right): (f32, f32), right: f32, steps: &BTreeMap<i32, f32>) {
    let selection = select_box(rows, (lo, hi), (x_left, x_right), right);
    let words: Vec<usize> = std::iter::once(0)
        .chain(rows.iter().scan(1, |offset, row| {
            let at = *offset;
            *offset += row.store_words();
            Some(at)
        }))
        .collect();
    let mut state = State { start: 1, ..State::default() };
    let mut master: Option<Columns> = None;
    for staff in lo..=hi {
        let columns = StaffColumns {
            rows: &mut *rows,
            st: &mut state,
            words: &words,
            lo,
            step: steps.get(&staff).copied().unwrap_or(25.0),
            staff,
            x_left,
            x_right,
            xs: Vec::new(),
            who: Vec::new(),
            n: 0,
            scale: 1.0,
            cols: Vec::new(),
            rights: Vec::new(),
            lefts: Vec::new(),
            prev_code: 0,
            prev_p12: 0.0,
            ledger: 0,
        }
        .run();
        let Some(mut columns) = columns else {
            continue;
        };
        if 0.1 < wide(x_right) - wide(columns.x[columns.x.len() - 1]) {
            columns.x.push(x_right);
            columns.need.push(0.0);
        }
        master = Some(match master {
            None => columns,
            Some(m) => merge_columns(m, columns, x_left, x_right),
        });
    }
    let Some(master) = master else {
        return;
    };
    let start = usize::from(master.x.len() > 1 && wide(master.x[1]) - wide(master.x[0]) <= wide(0.1));
    let xs = master.x[start..].to_vec();
    let needs = master.need.get(start..).map(<[f32]>::to_vec).unwrap_or_default();
    Distributor { rows, selection, right_limit: right, floor: -9999.0, amount: 0.0 }.run(x_left, x_right, xs, needs);
}
