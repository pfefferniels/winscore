//! Grace notes in the line-up (0x4C5AD8 with 0x4C78F8, 0x4C795B, 0x4C7374): the line-up
//! leaves notes and rests with P7 >= 64 out of its events; this pass places every group of
//! them in front of the note it ornaments. It collects the item before the group (the
//! "before" anchor), the group, and the item at the next x (the "after" anchor), gives each
//! a left and a right width, shrinks a group that does not fit between its anchors, and
//! writes the grace notes' P3 from the after anchor leftwards.
//!
//! After disasm-expert's reference model `analysis/engine/experiments/grace.py`. Lists are
//! 1-based as in the engine; index 0 holds the zero a fresh engine has there.

use std::collections::BTreeMap;

use crate::events::LONG_VALUE;
use crate::num::{amod, wide};
use crate::rows::{Row, BARLINE, METER};

/// Accidental widths by P5 mod 10 (0x792638).
const ACCIDENTAL: [f32; 12] = [0.0, 1.0, 4.2, 4.6, 4.2, 5.7, 4.6, 0.0, 0.0, 0.0, 0.0, 0.0];
/// The kind of an anchor that stands for the start or end of the staff.
const VIRTUAL: i32 = -99;

fn is_grace(row: &Row) -> bool {
    row.code() < 3 && row.par(7) >= LONG_VALUE
}

fn plain_meter(row: &Row) -> bool {
    let n = row.len();
    (n < 15 || row.par(15) == 0.0) && row.par(4) == 0.0 && (n < 14 || row.par(14) == 0.0)
}

/// Items the scans pass over: codes 4..16 except barlines, and displaced meters.
fn is_spacer(row: &Row) -> bool {
    let code = row.code();
    (3 < code && code < 17 && code != BARLINE) || (code == METER && !plain_meter(row))
}

#[derive(Debug, Clone, Copy, PartialEq)]
struct Entry {
    x: f32,
    /// The 1-based item whose P3 the entry stands for; `None` for a virtual anchor.
    item: Option<usize>,
    staff: i32,
    /// The item number, negated by the sort and set to 1 when its group is done.
    mark: i64,
    /// > 0 a grace note (its code), -code an after anchor, -100-code a before anchor.
    kind: i32,
    left: f32,
    right: f32,
}

pub struct GracePass<'a> {
    rows: &'a mut [Row],
    lo: i32,
    hi: i32,
    right_limit: f32,
    steps: &'a BTreeMap<i32, f32>,
    e: Vec<Entry>,
    bars: Vec<(f32, usize)>,
    /// 0x89FBF0: 0x4C7374 sets no right width for keys, so a key keeps the last one.
    last_right: f32,
}

impl<'a> GracePass<'a> {
    pub fn new(rows: &'a mut [Row], (lo, hi): (i32, i32), right_limit: f32, steps: &'a BTreeMap<i32, f32>) -> Self {
        GracePass { rows, lo, hi, right_limit, steps, e: Vec::new(), bars: Vec::new(), last_right: 0.0 }
    }

    fn item(&self, i: usize) -> &Row {
        &self.rows[i - 1]
    }

    fn add(&mut self, item: Option<usize>, kind: i32, at: Option<(f32, i32)>) {
        let (x, staff) = match (item, at) {
            (_, Some(at)) => at,
            (Some(i), None) => (self.item(i).x(), self.item(i).staff()),
            (None, None) => (0.0, 0),
        };
        let mark = item.map_or(1, |i| i as i64);
        self.e.push(Entry { x, item, staff, mark, kind, left: 0.0, right: 0.0 });
    }

    pub fn run(&mut self) {
        self.e = vec![Entry { x: 0.0, item: None, staff: 0, mark: 0, kind: 0, left: 0.0, right: 0.0 }];
        self.collect_bars();
        self.collect_groups();
        self.snap();
        self.provisional();
        self.barlines_between();
        self.widths();
        let mut order = self.sort();
        self.group_widths(&order);
        self.join_before_anchors(&mut order);
        self.shrink_groups();
        self.place();
    }

    fn collect_bars(&mut self) {
        for i in 1..=self.rows.len() {
            let row = self.item(i);
            if (self.lo..=self.hi).contains(&row.staff()) && row.code() == BARLINE {
                let x = row.x();
                if !self.bars.iter().any(|(b, _)| (wide(x) - wide(*b)).abs() < wide(0.005)) {
                    self.bars.push((x, i));
                }
            }
        }
    }

    fn collect_groups(&mut self) {
        let n = self.rows.len();
        let mut i = 1;
        while i <= n {
            let row = self.item(i);
            if row.staff() > self.hi {
                return;
            }
            if row.staff() < self.lo || !is_grace(row) {
                i += 1;
                continue;
            }
            match self.group(i) {
                Some(next) => i = next,
                None => return,
            }
        }
    }

    /// One grace group starting at item i; returns the next item to look at.
    fn group(&mut self, mut i: usize) -> Option<usize> {
        let n = self.rows.len();
        let staff = self.item(i).staff();
        let mut j = i - 1;
        while j > 0 && self.item(j).staff() == staff && is_spacer(self.item(j)) {
            j -= 1;
        }
        if j == 0 || self.item(j).staff() != staff {
            self.add(None, VIRTUAL, Some((0.0, staff)));
        } else {
            loop {
                let code = self.item(j).code();
                self.add(Some(j), -100 - code, None);
                if code > 2 {
                    break;
                }
                j -= 1;
                if j < 1 {
                    break;
                }
                let prev = self.item(j);
                let last_x = self.e[self.e.len() - 1].x;
                if prev.staff() != staff || prev.x() != last_x || prev.code() > 2 {
                    break;
                }
            }
        }
        let code = self.item(i).code();
        self.add(Some(i), code, None);
        loop {
            i += 1;
            if i > n || self.item(i).staff() != staff {
                self.add(None, VIRTUAL, Some((self.right_limit, staff)));
                return Some(i + 1);
            }
            let row = self.item(i);
            if is_grace(row) {
                let code = row.code();
                self.add(Some(i), code, None);
                continue;
            }
            if !is_spacer(row) {
                break;
            }
        }
        let anchor_x = self.item(i).x();
        loop {
            let code = self.item(i).code();
            self.add(Some(i), -code, None);
            loop {
                i += 1;
                if i > n {
                    return None;
                }
                let row = self.item(i);
                if row.staff() != staff || row.x() != anchor_x {
                    return Some(i);
                }
                if row.code() < 3 {
                    break;
                }
            }
        }
    }

    fn snap(&mut self) {
        let len = self.e.len();
        for k in 1..len.saturating_sub(1) {
            let v = self.e[k].x;
            for m in k + 1..len {
                if (wide(self.e[m].x) - wide(v)).abs() < wide(0.01) {
                    self.e[m].x = v;
                }
            }
        }
    }

    /// Grace notes provisionally 0.11 apart in front of their after anchor.
    fn provisional(&mut self) {
        let mut c = self.e.len() - 1;
        let mut prev = 0.0f32;
        let mut cur = self.e[c].x;
        loop {
            c -= 1;
            if c == 0 {
                return;
            }
            if self.e[c].kind < 0 {
                prev = 0.0;
                cur = self.e[c].x;
                continue;
            }
            if prev != self.e[c].x {
                cur -= 0.11;
            }
            prev = self.e[c].x;
            self.e[c].x = cur;
        }
    }

    /// A barline of the system between an anchor and a grace note replaces the anchor.
    fn barlines_between(&mut self) {
        let n = self.e.len() - 1;
        for c in 2..n {
            if self.e[c].kind < 0 || self.e[c - 1].kind == -14 {
                continue;
            }
            let (to, from) = (self.e[c].x, self.e[c - 1].x);
            if let Some(&(b, w)) = self.bars.iter().rev().find(|(b, _)| *b <= to && from <= *b) {
                let anchor = &mut self.e[c - 1];
                (anchor.x, anchor.item, anchor.kind, anchor.mark) = (b, Some(w), -114, 1);
            }
        }
        for c in (2..n).rev() {
            if self.e[c].kind < 0 || self.e[c + 1].kind == -14 {
                continue;
            }
            let (from, to) = (self.e[c].x, self.e[c + 1].x);
            if let Some(&(b, w)) = self.bars.iter().rev().find(|(b, _)| from <= *b && *b <= to) {
                let anchor = &mut self.e[c + 1];
                (anchor.x, anchor.item, anchor.kind, anchor.mark) = (b, Some(w), -14, 1);
            }
        }
    }

    fn widths(&mut self) {
        for c in 1..self.e.len() {
            let entry = self.e[c];
            let k = entry.kind % 100;
            if !(matches!(k, -18 | -17 | -14) || k > -4) {
                continue;
            }
            let row = entry.item.map(|i| self.item(i).clone()).unwrap_or(Row { p: Vec::new(), source: 0, text_words: 0 });
            let (left, right) = self.entry_widths(k.abs(), &row);
            let mut size = self.steps.get(&entry.staff).copied().unwrap_or(25.0) / 25.0;
            if entry.kind > 0 {
                size *= 0.6;
            }
            self.e[c].right = size * right;
            self.e[c].left = size * left;
        }
    }

    /// 0x4C7374
    fn entry_widths(&mut self, k: i32, row: &Row) -> (f32, f32) {
        let n = row.len();
        let mut left = 1.2f32;
        let mut right = self.last_right;
        match k {
            1 => {
                let mut least = 1.0f32;
                right = if n > 5 && row.par(6) == 2.0 { 4.6 } else { 4.1 };
                if n > 9 && row.par(10) != 0.0 {
                    let shift = row.par(10);
                    if shift.abs() < 10.0 {
                        right += shift;
                    }
                    if shift == 10.0 {
                        right += right;
                    }
                    if shift == 20.0 {
                        least += right;
                    }
                }
                let mut ledger = 0.0f32;
                let pitch = amod(row.par(4), 100.0);
                if pitch >= 13.0 || pitch <= 0.0 {
                    right += 0.5;
                    ledger = 1.0;
                }
                let accidental = if n > 4 { amod(row.par(5), 10.0) } else { 0.0 };
                let index = (wide(accidental) + 1.0) as i32;
                // A negative index reads from the end, as the model's list does.
                let width = ACCIDENTAL[usize::try_from(index.rem_euclid(ACCIDENTAL.len() as i32)).unwrap_or(0)];
                left = (wide(amod(accidental, 1.0)) * 10.0 + wide(width)) as f32;
                if left <= 1.0 {
                    least += ledger;
                }
                if left < least {
                    left = least;
                }
                if n > 8 {
                    let tens = (wide(row.par(9)) / 10.0).trunc() as f32;
                    let mut dots = (wide(amod(row.par(9), 1.0)) * 10.0 + wide(tens)) as f32;
                    let least_dots = if row.par(5) < 20.0 && amod(row.par(9), 10.0) >= 1.0 { 1.6 } else { 0.0 };
                    if dots < least_dots {
                        dots = least_dots;
                    }
                    right += dots;
                }
            }
            2 => right = 3.1,
            3 => right = if n > 3 && row.par(4) >= 100.0 { 5.6 } else { 7.0 },
            14 => {
                right = 1.5;
                left = 2.4;
                if n > 4 {
                    let kind = row.par(5);
                    left = match kind {
                        1.0 => 2.7,
                        2.0 => 3.7,
                        3.0 => 6.0,
                        _ => left,
                    };
                    if kind >= 4.0 {
                        right = 4.9;
                    }
                    if kind > 5.0 {
                        left = 5.0;
                    }
                }
            }
            17 => {}
            _ => {
                let two_digits = row.par(5) > 9.0 || (row.par(6) > 9.0 && row.par(5) < 90.0);
                right = if two_digits { 8.1 } else { 5.6 };
            }
        }
        self.last_right = right;
        (left, right)
    }

    /// Entry indices by x (the last of equal minima first); marks negated.
    fn sort(&mut self) -> Vec<usize> {
        let mut order = Vec::new();
        loop {
            let mut best = 9999.0f32;
            let mut at = 0;
            for c in 1..self.e.len() {
                if !(self.e[c].mark < 0 || best < self.e[c].x) {
                    best = self.e[c].x;
                    at = c;
                }
            }
            if at == 0 {
                return order;
            }
            order.push(at);
            self.e[at].mark = -self.e[at].mark;
        }
    }

    /// Entries at the same x share the largest widths.
    fn group_widths(&mut self, order: &[usize]) {
        let n = order.len();
        let mut c = 0;
        while c + 1 < n {
            if self.e[order[c]].x == self.e[order[c + 1]].x {
                let x = self.e[order[c]].x;
                let mut m = c;
                let mut left_max = -99.0f32;
                let mut right_max = -99.0f32;
                while m < n && x >= self.e[order[m]].x {
                    left_max = left_max.max(self.e[order[m]].left);
                    right_max = right_max.max(self.e[order[m]].right);
                    m += 1;
                }
                for &o in &order[c..m] {
                    self.e[o].left = left_max;
                    self.e[o].right = right_max;
                }
                c = m - 1;
            }
            c += 1;
        }
    }

    fn join_before_anchors(&mut self, order: &mut [usize]) {
        for c in 0..order.len().saturating_sub(1) {
            let (a, b) = (self.e[order[c]], self.e[order[c + 1]]);
            if a.staff == b.staff || a.x == b.x {
                continue;
            }
            if a.kind < -99 && b.kind < -99 {
                let staff = a.staff;
                self.e[order[c]] = Entry { staff, ..b };
                order[c] = order[c + 1];
            }
        }
    }

    /// 0x4C795B: how much of its width the group before entry c may keep (at most 1), and
    /// its before anchor.
    fn fit(&self, c: usize) -> (f32, usize) {
        let mut previous_x = 0.0f32;
        let mut total = self.e[c].left;
        let mut j = c - 1;
        while j > 0 && self.e[j].kind > -101 {
            if self.e[j].kind >= 0 && self.e[j].x != previous_x {
                previous_x = self.e[j].x;
                total = (wide(total) + wide(self.e[j].right) + wide(self.e[j].left)) as f32;
            }
            j -= 1;
        }
        total += self.e[j].right;
        let room = self.e[c].x - self.e[j].x;
        let ratio = room / total;
        (if ratio > 1.0 { 1.0 } else { ratio }, j)
    }

    fn shrink_groups(&mut self) {
        let len = self.e.len();
        for c in (2..len).rev() {
            let entry = self.e[c];
            if !(-100 < entry.kind && entry.kind < 0 && entry.mark < 1) {
                continue;
            }
            let x = entry.x;
            self.e[c].mark = 1;
            let (mut ratio, mut j) = self.fit(c);
            while let Some(m) = (1..j).rev().find(|&m| self.e[m].x == x) {
                let (r, before) = self.fit(m);
                j = before;
                self.e[m].mark = 1;
                ratio = ratio.min(r);
            }
            if ratio == 1.0 || ratio <= 0.0 {
                continue;
            }
            let mut m = len - 1;
            while m >= 3 {
                if self.e[m].x == x {
                    let mut k = m;
                    while k > 0 {
                        self.e[k].left *= ratio;
                        self.e[k].right *= ratio;
                        if self.e[k].kind < -100 {
                            break;
                        }
                        k -= 1;
                    }
                    m = k;
                }
                if m == 0 {
                    break;
                }
                m -= 1;
            }
        }
    }

    /// The gap before every entry: the right width of the entry before (of the last at
    /// another x) plus its own left width; each grace note's pass overwrites those after it.
    fn distances(&self) -> Vec<f32> {
        let e = &self.e;
        let n = e.len() - 1;
        let mut dist = vec![0.0f32; n + 2];
        for c in (1..n).filter(|&c| e[c].kind >= 0) {
            dist[c] = e[c - 1].right + e[c].left;
            let mut carry = e[c].right;
            for (d, slot) in dist.iter_mut().enumerate().take(n + 1).skip(c + 1) {
                *slot = carry + e[d].left;
                if e[d].x != e[d - 1].x {
                    carry = e[d].right;
                }
                if e[d].kind < 0 {
                    break;
                }
            }
        }
        dist
    }

    /// From each after anchor leftwards, every grace note (chord) one gap further left,
    /// never closer than 0.1 to the before anchor.
    fn place(&mut self) {
        let n = self.e.len() - 1;
        let dist = self.distances();
        let mut c = n;
        loop {
            let mut cur = self.e[c].x;
            let mut prev = 0.0f32;
            loop {
                c -= 1;
                if c < 2 {
                    return;
                }
                if self.e[c].kind < 0 {
                    break;
                }
                if prev != self.e[c].x {
                    cur -= dist[c + 1];
                }
                prev = self.e[c].x;
                let before = self.e[c - 1];
                if before.kind < 0 && wide(cur) < wide(before.x) + wide(0.1) {
                    cur = before.x + 0.1;
                }
                self.e[c].x = cur;
                if let Some(i) = self.e[c].item {
                    self.rows[i - 1].set_x(cur);
                }
            }
        }
    }
}
