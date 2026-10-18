//! The line-up proper: the staves' events merged into one master
//! list, spaced anew, and every staff mapped onto the new positions segment by segment;
//! afterwards clefs inside the line and the items that hang between others (codes 4-7,
//! 9-13, 15, 16) are placed again.

use std::collections::{BTreeMap, BTreeSet};

use crate::events::{staff_events, StaffEvents, BARLINE_P12};
use crate::grace::GracePass;
use crate::merge::{drop_repeated_barlines, merge_durations, merge_markers, BARLINE};
use crate::num::{trunc, wide};
use crate::rows::{Row, BEAM, CLEF, STAFF};
use crate::spacing::{positions, START_CLEF};
use crate::LayoutErrorKind;

const CLEF_MARKER: f32 = -3.0;
const LOOP_LIMIT: usize = 100_000;

/// An item whose position the interpolated items follow.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Anchor {
    staff: i32,
    x: f32,
    code: i32,
    /// 1-based item number; `None` for the anchor at the right limit.
    item: Option<usize>,
}

/// A staff's events matched against the master list, from master index `start` (1-based).
struct Aligned {
    start: usize,
    entries: Vec<f32>,
    positions: Vec<f32>,
}

fn is_segment_code(code: i32) -> bool {
    !(3 < code && code < 17 && code != 14)
}

fn at(values: &[f32], k: usize) -> f32 {
    k.checked_sub(1).and_then(|i| values.get(i)).copied().unwrap_or(0.0)
}

fn is_barline(e: f32) -> bool {
    e == BARLINE || e == BARLINE_P12
}

pub struct Lineup<'a> {
    rows: &'a mut [Row],
    lo: i32,
    hi: i32,
    right: f32,
    steps: BTreeMap<i32, f32>,
    anchors: Vec<Anchor>,
    /// Every staff's entries and positions one after the other.
    saved_e: Vec<f32>,
    saved_x: Vec<f32>,
    /// Staff -> its start in `saved_e` and `saved_x`.
    offset: BTreeMap<i32, usize>,
    master: Vec<f32>,
    new_x: Vec<f32>,
    x_left: f32,
    x_right: f32,
    saw_long: bool,
}

impl<'a> Lineup<'a> {
    pub fn new(rows: &'a mut [Row], lo: i32, hi: i32, right: f32, steps: BTreeMap<i32, f32>) -> Self {
        Lineup {
            rows,
            lo,
            hi,
            right,
            steps,
            anchors: Vec::new(),
            saved_e: Vec::new(),
            saved_x: Vec::new(),
            offset: BTreeMap::new(),
            master: Vec::new(),
            new_x: Vec::new(),
            x_left: 9999.0,
            x_right: right,
            saw_long: false,
        }
    }

    fn row(&self, i: usize) -> &Row {
        &self.rows[(i + self.rows.len() - 1) % self.rows.len()]
    }

    fn step(&self, staff: i32) -> f32 {
        self.steps.get(&staff).copied().unwrap_or(25.0)
    }

    fn near_right(&self, x: f32) -> bool {
        wide(x) <= wide(self.right) + wide(0.05)
    }

    fn collect_anchors(&mut self) {
        let mut raw: Vec<Anchor> = Vec::new();
        let mut current = 0;
        let right_anchor = |staff| Anchor { staff, x: self.right, code: -14, item: None };
        let far_from_right = |a: &Anchor| (wide(a.x) - wide(self.right)).abs() >= wide(0.01);
        for (i, row) in self.rows.iter().enumerate().map(|(i, r)| (i + 1, r)) {
            let (staff, code, x) = (row.staff(), row.code(), row.x());
            if staff > self.hi {
                break;
            }
            if !(self.near_right(x) && self.lo <= staff && (code > 16 || code == 14 || code < 4)) {
                continue;
            }
            if raw.last().is_some_and(|a| a.staff == staff && a.x == x) {
                continue;
            }
            if staff != current {
                if current != 0 && raw.last().is_some_and(far_from_right) {
                    raw.push(right_anchor(current));
                }
                current = staff;
            }
            raw.push(Anchor { staff, x, code, item: Some(i) });
            if code == 14 && row.len() > 3 {
                let spanned = trunc(row.par(4) - 1.0);
                raw.extend((staff + 1..=staff + spanned).map(|t| Anchor { staff: t, x, code, item: Some(i) }));
            }
        }
        if raw.last().is_some_and(far_from_right) {
            raw.push(right_anchor(current));
        }
        raw.sort_by(|a, b| anchor_key(a).partial_cmp(&anchor_key(b)).unwrap_or(std::cmp::Ordering::Equal));
        self.anchors = raw;
    }

    pub fn run(&mut self) -> Result<(), LayoutErrorKind> {
        self.collect_anchors();
        let (lo, hi, right) = (self.lo, self.hi, self.right);
        for row in self.rows.iter_mut() {
            if row.code() == STAFF && (lo..=hi).contains(&row.staff()) && row.len() > 5 && row.par(6) > right {
                row.set(6, right);
            }
        }
        self.x_left = 9999.0;
        self.x_right = self.right;
        let mut start = 1;
        let mut total_before: Option<f32> = None;
        for staff in lo..=hi {
            let (next, events) = staff_events(self.rows, start, staff);
            start = next;
            self.saw_long |= events.saw_long;
            self.offset.insert(staff, self.saved_x.len());
            if events.total == 0.0 {
                if staff == self.lo {
                    self.lo += 1;
                    if self.lo > self.hi {
                        return Err(LayoutErrorKind::NoNotes);
                    }
                }
                continue;
            }
            let (entries, positions) = self.normalize(&events);
            let off = self.saved_x.len();
            self.saved_e.truncate(off);
            self.saved_e.extend(&entries);
            self.saved_e.push(0.0);
            self.saved_x.extend(&positions);
            let Some(before) = total_before else {
                total_before = Some(events.total);
                self.master = drop_repeated_barlines(&entries);
                self.x_left = positions[0];
                self.x_right = positions[positions.len() - 1];
                continue;
            };
            self.x_left = self.x_left.min(positions[0]);
            if entries.last() == Some(&BARLINE) && self.x_right < positions[positions.len() - 1] {
                self.x_right = positions[positions.len() - 1];
            }
            if (wide(events.total) - wide(before)).abs() > wide(0.007) {
                return Err(LayoutErrorKind::UnequalStaves { staff, beats: events.total, before });
            }
            let merged = merge_markers(&self.master, &entries)?;
            let durations: Vec<f32> = entries.iter().copied().filter(|e| *e > 0.0).collect();
            self.master = merge_durations(&merged, &durations)?;
        }
        self.offset.insert(hi + 1, self.saved_x.len());
        let size = self.step(self.lo) / 25.0;
        self.new_x = positions(&self.master, size, self.x_left, self.x_right);
        self.apply()?;
        if self.saw_long {
            GracePass::new(self.rows, (self.lo, self.hi), self.right, &self.steps).run();
        }
        self.interpolate_others();
        Ok(())
    }

    /// The x range J works on after the line-up, and the lowest staff with events.
    pub fn extent(&self) -> ((f32, f32), i32) {
        ((self.x_left, self.x_right), self.lo)
    }

    /// Barlines with P12 count as plain ones, a missing closing barline is added, durations
    /// are counted in sixteenths, the first clef becomes the start clef and later ones go.
    fn normalize(&self, events: &StaffEvents) -> (Vec<f32>, Vec<f32>) {
        let mut entries: Vec<f32> = events.entries.iter().map(|&e| if e == BARLINE_P12 { BARLINE } else { e }).collect();
        let mut positions = events.positions.clone();
        let last = entries.last().copied().unwrap_or(0.0);
        if trunc(last) != -14 {
            let mut end = self.x_right;
            if last < 0.0 {
                let staff_item = self.rows.iter().find(|r| r.code() == STAFF && r.staff() == self.lo);
                if let Some(item) = staff_item.filter(|r| r.len() > 5) {
                    end = item.par(6);
                }
                if staff_item.is_none() || end == 0.0 {
                    end = self.right;
                }
            }
            entries.push(BARLINE);
            positions.push(end);
        }
        let mut seen = false;
        entries
            .into_iter()
            .zip(positions)
            .filter_map(|(e, x)| {
                if e > 0.0 {
                    seen = true;
                    Some((e * 4.0, x))
                } else if e == CLEF_MARKER {
                    if seen {
                        return None;
                    }
                    seen = true;
                    Some((START_CLEF, x))
                } else {
                    if e != BARLINE {
                        seen = true;
                    }
                    Some((e, x))
                }
            })
            .unzip()
    }

    /// Every staff mapped onto the new positions, then the clefs inside the line.
    fn apply(&mut self) -> Result<(), LayoutErrorKind> {
        let (lo, hi) = (self.lo, self.hi);
        for row in self.rows.iter_mut() {
            if row.code() == STAFF && (lo..=hi).contains(&row.staff()) {
                row.set(2, -row.par(2));
            }
        }
        let threshold = self
            .rows
            .iter()
            .find(|r| (lo..=hi).contains(&r.staff()) && r.code() <= CLEF)
            .map(|r| if r.code() < CLEF { r.x() - 2.0 } else { r.x() + 2.0 });
        let Some(threshold) = threshold else {
            return Ok(());
        };
        for staff in lo..=hi {
            if self.offset.get(&staff) == self.offset.get(&(staff + 1)) {
                continue;
            }
            if !self.map_staff(staff)? {
                return Ok(());
            }
        }
        self.place_clefs(threshold);
        Ok(())
    }

    /// The staff's events against the master list; master markers the staff
    /// lacks get the midpoint of the staff's neighbouring positions. Returns the master
    /// index the staff starts at.
    fn align(&self, staff: i32) -> Result<Option<Aligned>, LayoutErrorKind> {
        let off = self.offset[&staff];
        let master = &self.master;
        let m_len = master.len();
        let s_at = |j: usize| (off + j).checked_sub(1).and_then(|k| self.saved_e.get(k)).copied().unwrap_or(0.0);
        let x_at = |j: usize| (off + j).checked_sub(1).and_then(|k| self.saved_x.get(k)).copied().unwrap_or(0.0);
        let first = s_at(1);
        let Some(start) = (1..=m_len).find(|&k| master[k - 1] > 0.0 || master[k - 1] == first) else {
            return Ok(None);
        };
        let mut out_e = Vec::new();
        let mut out_x = Vec::new();
        let (mut mi, mut j) = (start - 1, 1);
        let mut s_cur = s_at(1);
        let mut acc_m = 0.0f32;
        let mut acc_s = 0.0f32;
        let done = |entries: Vec<f32>, positions: Vec<f32>| Ok(Some(Aligned { start, entries, positions }));
        for _ in 0..LOOP_LIMIT {
            if mi == m_len {
                return done(out_e, out_x);
            }
            mi += 1;
            let mut m = master[mi - 1];
            if m >= 0.0 {
                acc_m += m;
                loop {
                    if s_cur > 0.0 {
                        acc_s += s_cur;
                        out_e.push(s_cur);
                        out_x.push(x_at(j));
                        let mut d = acc_m - acc_s;
                        while !(wide(d).abs() <= wide(0.002) || d > 0.0) {
                            loop {
                                if mi == m_len {
                                    return done(out_e, out_x);
                                }
                                mi += 1;
                                m = master[mi - 1];
                                if m >= 0.0 {
                                    break;
                                }
                            }
                            acc_m += m;
                            d = acc_m - acc_s;
                        }
                        if wide(d).abs() <= wide(0.002) {
                            break;
                        }
                    }
                    j += 1;
                    s_cur = s_at(j);
                    if j > self.saved_e.len() + 2 {
                        return Err(LayoutErrorKind::Unalignable { staff });
                    }
                }
                acc_m = 0.0;
                acc_s = 0.0;
                j += 1;
                s_cur = s_at(j);
            } else {
                while s_cur != m && s_cur <= 0.0 && s_cur == START_CLEF {
                    j += 1;
                    s_cur = s_at(j);
                }
                if s_cur == m {
                    out_e.push(s_cur);
                    out_x.push(x_at(j));
                    acc_m = 0.0;
                    acc_s = 0.0;
                    j += 1;
                    s_cur = s_at(j);
                } else {
                    out_e.push(m);
                    let (a, b) = (x_at(j - 1), x_at(j));
                    out_x.push(((wide(b) - wide(a)) / 2.0 + wide(a)) as f32);
                }
            }
        }
        Err(LayoutErrorKind::NoEnd)
    }

    /// Maps staff `staff` onto the new positions, segment by segment between its events.
    fn map_staff(&mut self, staff: i32) -> Result<bool, LayoutErrorKind> {
        let Some(Aligned { start: mut ms, entries: al_e, positions: al_x }) = self.align(staff)? else {
            return Ok(false);
        };
        let m_len = self.master.len();
        let mut new_prev = self.new_x[ms - 1];
        let mut master_prev = self.master[ms - 1];
        let park = new_prev + 800.0;
        let mut staff_prev = al_e[0];
        let mut old_prev = al_x[0];
        let mut proportional = false;
        let mut k = 1;
        let mut moved = BTreeSet::new();
        let mut m_cur = 0.0f32;
        let mut new_master = 0.0f32;
        loop {
            if !proportional {
                if m_len < ms {
                    break;
                }
                ms += 1;
                m_cur = at(&self.master, ms);
                new_master = at(&self.new_x, ms);
            }
            if al_e.len() <= k {
                break;
            }
            k += 1;
            let mut s_cur = al_e[k - 1];
            let mut old_cur = al_x[k - 1];
            let mut equal = staff_prev == master_prev;
            let mut new_cur = 0.0f32;
            let mut carry = 0.0f32;
            if !equal {
                let mut d = master_prev - staff_prev;
                equal = wide(d).abs() <= wide(0.005);
                if !equal && d < 0.0 {
                    loop {
                        while m_cur <= 0.0 {
                            ms += 1;
                            m_cur = at(&self.master, ms);
                        }
                        master_prev += m_cur;
                        d = master_prev - staff_prev;
                        ms += 1;
                        m_cur = at(&self.master, ms);
                        new_master = at(&self.new_x, ms);
                        if wide(d).abs() <= wide(0.005) {
                            equal = true;
                            break;
                        }
                        if m_cur <= 0.0 {
                            return Err(LayoutErrorKind::Unalignable { staff });
                        }
                        if d >= 0.0 {
                            break;
                        }
                    }
                }
                if !equal {
                    proportional = true;
                    new_cur = ((wide(new_master) - wide(new_prev)) * wide(staff_prev) / wide(master_prev) + wide(new_prev)) as f32;
                    carry = d;
                }
            }
            if equal {
                proportional = false;
                new_cur = new_master;
                carry = m_cur;
                // A barline on one side only: the other side's segment ends halfway.
                if m_cur != s_cur && is_barline(s_cur) {
                    new_cur = ((wide(new_master) - wide(new_prev)) / 2.0 + wide(new_prev)) as f32;
                    carry = s_cur;
                    ms -= 1;
                } else if m_cur != s_cur && is_barline(m_cur) {
                    old_cur = ((wide(old_cur) - wide(old_prev)) / 2.0 + wide(old_prev)) as f32;
                    s_cur = m_cur;
                    k -= 1;
                }
            }
            if old_prev < old_cur {
                self.move_segment(staff, (old_prev, old_cur), (new_prev, new_cur), &mut moved);
                new_prev = new_cur;
                master_prev = carry;
                staff_prev = s_cur;
                old_prev = old_cur;
            }
        }
        for i in moved {
            let row = &mut self.rows[i - 1];
            if row.x() >= park {
                row.set_x(row.x() - 1000.0);
            }
        }
        Ok(true)
    }

    /// P3 in [old0, old1] maps linearly onto
    /// [new0, new1]; moved values are parked 1000 higher until the staff is done.
    fn move_segment(&mut self, staff: i32, (old0, old1): (f32, f32), (new0, new1): (f32, f32), moved: &mut BTreeSet<usize>) {
        let low = old0 - 0.001;
        let high = (if old1 != 0.0 { old1 } else { 200.0 }) + 0.001;
        let factor = ((wide(new1) - wide(new0)) / (wide(old1) - wide(old0))) as f32;
        let offset = (wide(new0 + 1000.0) - wide(factor) * wide(old0)) as f32;
        for (i, row) in self.rows.iter_mut().enumerate() {
            if row.staff() == staff && is_segment_code(row.code()) && low <= row.x() && row.x() <= high {
                let v = (wide(factor) * wide(row.x()) + wide(offset)) as f32;
                row.set_x(if wide(v).abs() < wide(0.005) { 0.0 } else { v });
                moved.insert(i + 1);
            }
        }
    }

    /// End of the mapping: a clef after the start of the line goes 0.3 staff steps (plus
    /// one) before the note or barline it precedes, or halfway when there is no room.
    fn place_clefs(&mut self, threshold: f32) {
        let (lo, hi) = (self.lo, self.hi);
        let mut clefs = Vec::new();
        let mut bars = Vec::new();
        let mut last_bar = 0.0f32;
        for (i, row) in self.rows.iter().enumerate() {
            if self.near_right(row.x()) && (lo..=hi).contains(&row.staff()) && threshold <= row.x() {
                match row.code() {
                    CLEF => clefs.push(i + 1),
                    14 => {
                        bars.push(row.x());
                        last_bar = last_bar.max(row.x());
                    }
                    _ => {}
                }
            }
        }
        for row in self.rows.iter_mut().filter(|r| r.staff() < 0) {
            row.set(2, -row.par(2));
        }
        for i in clefs {
            let (x, staff) = (self.row(i).x(), self.row(i).staff());
            let gap = (wide(self.step(staff)) * wide(0.3) + 1.0) as f32;
            let target = self.clef_target(i, x, staff, &bars, last_bar);
            let mut k = i;
            let new = loop {
                k -= 1;
                let previous = self.row(k);
                let prev = previous.x();
                if wide(target) - wide(prev) > wide(gap) {
                    break (wide(target) - wide(gap) + 1.0) as f32;
                }
                if !(2 < previous.code() && previous.code() < 17) {
                    break ((wide(target) - wide(prev)) / 2.0 + wide(prev)) as f32;
                }
            };
            self.rows[i - 1].set_x(new);
        }
    }

    /// The position a clef inside the line is placed before.
    fn clef_target(&self, i: usize, x: f32, staff: i32, bars: &[f32], last_bar: f32) -> f32 {
        let next = (i + 1..=self.rows.len()).map(|k| self.row(k)).take_while(|r| r.staff() == staff).find(|r| r.par(1) == 14.0 || r.par(1) <= 2.0);
        match next {
            None => last_bar,
            Some(r) if r.par(1) == 14.0 => r.x(),
            Some(note) => {
                let note_x = note.x();
                bars.iter().copied().find(|&b| x <= b).filter(|&b| b <= note_x).unwrap_or(note_x)
            }
        }
    }

    /// The x parameters of codes 4-7, 9-13, 15 and 16 follow their anchors.
    fn interpolate_others(&mut self) {
        let (lo, hi) = (self.lo, self.hi);
        for i in 0..self.rows.len() {
            let (staff, code, n) = (self.rows[i].staff(), self.rows[i].code(), self.rows[i].len());
            if staff > hi {
                break;
            }
            if !(3 < code && code < 17 && code != STAFF && code != 14 && lo <= staff) {
                continue;
            }
            self.interpolate(i, 3);
            let p = |k: usize, rows: &[Row]| rows[i].par(k);
            if code < 8 && n > 5 && (code != BEAM || p(7, self.rows) >= 0.0) {
                self.interpolate(i, 6);
            }
            if code == BEAM && n > 10 {
                if p(11, self.rows) > 0.0 {
                    self.interpolate(i, 11);
                }
                if n > 11 && p(7, self.rows) > 0.0 {
                    if p(12, self.rows) > 0.0 {
                        self.interpolate(i, 12);
                    }
                    if n > 13 && p(13, self.rows) != 0.0 {
                        if p(14, self.rows) > 0.0 {
                            self.interpolate(i, 14);
                        }
                        if n > 14 && p(15, self.rows) > 0.0 {
                            self.interpolate(i, 15);
                        }
                    }
                }
            }
        }
    }

    /// Parameter `k` of row `i` moves with the anchors around it, proportionally.
    fn interpolate(&mut self, i: usize, k: usize) {
        let x = self.rows[i].par(k);
        let staff = self.rows[i].staff();
        let position = |anchor: &Anchor, rows: &[Row], right: f32| anchor.item.map_or(right, |n| rows[n - 1].x());
        for j in 0..self.anchors.len().saturating_sub(1) {
            let (a, b) = (self.anchors[j], self.anchors[j + 1]);
            if a.staff > staff {
                break;
            }
            if a.staff != staff {
                continue;
            }
            if x < a.x {
                break;
            }
            if x <= b.x {
                let mut part = x - a.x;
                if wide(part).abs() < wide(0.01) {
                    part = 0.0;
                }
                let span = b.x - a.x;
                if span >= 0.01 {
                    let mut fraction = part / span;
                    if (wide(fraction) - 1.0).abs() < wide(0.01) {
                        fraction = 1.0;
                    }
                    let na = position(&a, self.rows, self.right);
                    let nb = if b.code >= 0 { position(&b, self.rows, self.right) } else { self.right };
                    let moved = ((wide(nb) - wide(na)) * wide(fraction) + wide(na)) as f32;
                    self.rows[i].set(k, moved);
                }
            }
        }
    }
}

fn anchor_key(a: &Anchor) -> f32 {
    (a.staff * 1000) as f32 + a.x
}
