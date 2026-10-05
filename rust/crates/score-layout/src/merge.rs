//! Merging the event lists of the staves of a system into one master list (0x4C9510):
//! first the markers of both lists, then the durations split wherever either staff has an
//! onset.

use crate::LayoutErrorKind;

pub const BARLINE: f32 = -14.0;
const KEY: f32 = -17.0;
/// Guard against the merges running forever on lists the engine would loop on.
const LOOP_LIMIT: usize = 100_000;

/// 1-based read; past the end the engine finds the zero it wrote after the list.
fn at(values: &[f32], k: usize) -> f32 {
    k.checked_sub(1).and_then(|i| values.get(i)).copied().unwrap_or(0.0)
}

/// 0x4CB518: a barline directly after another is dropped.
pub fn drop_repeated_barlines(entries: &[f32]) -> Vec<f32> {
    entries.iter().fold(Vec::new(), |mut out, &e| {
        if e != BARLINE || out.last() != Some(&e) {
            out.push(e);
        }
        out
    })
}

/// The marker merge's output with its rule for what may follow what (0x4CB5F5).
struct Emitter {
    out: Vec<f32>,
    last: f32,
}

impl Emitter {
    fn emit(&mut self, v: f32) {
        if v != 0.0 && (v > 0.0 || self.last <= 0.0 || v == BARLINE) {
            self.out.push(v);
            self.last = v;
        }
    }

    fn finish(&self) -> Vec<f32> {
        drop_repeated_barlines(&self.out)
    }
}

/// First merge of 0x4C9510: the markers of both lists in order, the master's durations
/// kept, the staff's durations walked alongside.
pub fn merge_markers(master: &[f32], staff: &[f32]) -> Result<Vec<f32>, LayoutErrorKind> {
    let (m_len, s_len) = (master.len(), staff.len());
    let mut e = Emitter { out: Vec::new(), last: 0.0 };
    let (mut i, mut j) = (1, 1);
    for _ in 0..LOOP_LIMIT {
        let mut v = at(master, i);
        let mut s = at(staff, j);
        let mut lookahead = false;
        if s == BARLINE && !(m_len == i || v >= 0.0 || v == BARLINE) {
            // A staff barline facing master markers: emit now if the master has a barline
            // among the markers ahead.
            for k in i + 1..=m_len {
                let ahead = at(master, k);
                if ahead >= 0.0 {
                    break;
                }
                if ahead == BARLINE {
                    e.last = 0.0;
                    lookahead = true;
                    break;
                }
            }
        }
        if !lookahead {
            if v == 0.0 {
                v = s;
            }
            if v == KEY && i < m_len && at(master, i + 1) == BARLINE {
                e.last = v;
            }
        }
        if lookahead || s == 0.0 || v == s {
            e.emit(v);
        } else if v <= 0.0 {
            let take_staff = s <= 0.0 && ((v < s && !(s == BARLINE && e.last < 0.0)) || (v >= s && v == BARLINE && e.last < 0.0));
            if take_staff {
                i -= 1;
                v = s;
            } else {
                j -= 1;
            }
            e.emit(v);
        } else if s < 0.0 {
            i -= 1;
            e.emit(s);
        } else {
            // Durations on both sides: walk both until their sums meet.
            let mut acc_s = s;
            let mut acc_m = 0.0f32;
            loop {
                acc_m += v;
                e.emit(v);
                let mut d = acc_m - acc_s;
                let mut done = false;
                while d > 0.001 {
                    let j2 = loop {
                        let j2 = j + 1;
                        if s_len < j2 {
                            return Ok(e.finish());
                        }
                        s = at(staff, j2);
                        if s > 0.0 {
                            break j2;
                        }
                        if d <= 0.02 {
                            done = true;
                            break j2;
                        }
                        v = s;
                        j = j2;
                        e.emit(v);
                    };
                    if done {
                        break;
                    }
                    acc_s += s;
                    j = j2;
                    d = acc_m - acc_s;
                }
                if done || -0.001 <= d {
                    break;
                }
                let i2 = loop {
                    let i2 = i + 1;
                    if m_len < i2 {
                        return Ok(e.finish());
                    }
                    v = at(master, i2);
                    if v > 0.0 {
                        break i2;
                    }
                    if -0.02 <= d {
                        done = true;
                        break i2;
                    }
                    i = i2;
                    e.emit(v);
                };
                if done {
                    break;
                }
                i = i2;
            }
        }
        if s_len <= j && m_len <= i {
            return Ok(e.finish());
        }
        if i < m_len {
            i += 1;
        }
        if j < s_len {
            j += 1;
        }
    }
    Err(LayoutErrorKind::NoEnd)
}

/// 0x4CB78B: the master durations split wherever the staff (its durations only) has an
/// onset.
struct DurationMerge<'a> {
    master: &'a [f32],
    staff: &'a [f32],
    out: Vec<f32>,
    i: usize,
    j: usize,
    m: f32,
    s: f32,
    acc_m: f32,
    acc_s: f32,
}

const ALIGNED: f32 = 0.01;
const TOLERANCE: f32 = 0.004;

impl DurationMerge<'_> {
    /// 0x4CB6BF: the next master duration, copying the markers before it.
    fn next_master(&mut self, stop_at_marker: bool) {
        loop {
            self.i += 1;
            self.m = at(self.master, self.i);
            if self.m > 0.0 {
                self.acc_m += self.m;
                return;
            }
            self.out.push(self.m);
            if stop_at_marker {
                return;
            }
        }
    }

    /// 0x4CB74B
    fn next_staff(&mut self) {
        self.j += 1;
        self.s = at(self.staff, self.j);
        self.acc_s += self.s;
    }

    fn apart(&self) -> bool {
        (f64::from(self.acc_m) - f64::from(self.acc_s)).abs() >= f64::from(ALIGNED)
    }

    fn run(mut self) -> Result<Vec<f32>, LayoutErrorKind> {
        for _ in 0..LOOP_LIMIT {
            self.acc_m = 0.0;
            self.acc_s = 0.0;
            self.next_master(true);
            if self.m >= 0.0 {
                self.next_staff();
                let mut finished = false;
                while (f64::from(self.acc_m) - f64::from(self.acc_s)).abs() > f64::from(ALIGNED) {
                    let mut aligned = false;
                    if self.s <= self.m {
                        loop {
                            self.out.push(self.s);
                            if !self.apart() {
                                finished = true;
                                break;
                            }
                            if self.acc_s <= self.acc_m {
                                self.next_staff();
                                if f64::from(self.m) <= f64::from(self.s) + f64::from(TOLERANCE) {
                                    self.m = (f64::from(self.acc_m) - f64::from(self.acc_s) + f64::from(self.s)) as f32;
                                    aligned = true;
                                    break;
                                }
                            }
                            if f64::from(self.acc_s) - f64::from(TOLERANCE) <= f64::from(self.acc_m) {
                                continue;
                            }
                            self.next_master(false);
                            if f64::from(self.s) + f64::from(TOLERANCE) >= f64::from(self.m) {
                                break;
                            }
                        }
                        if finished {
                            break;
                        }
                        if !aligned {
                            self.i -= 1;
                            self.m = ((f64::from(self.acc_m) - f64::from(self.m)) - f64::from(self.acc_s) + f64::from(self.s)) as f32;
                        }
                    } else {
                        loop {
                            self.out.push(self.m);
                            if !self.apart() {
                                finished = true;
                                break;
                            }
                            if self.acc_m <= self.acc_s {
                                self.next_master(false);
                                if f64::from(self.s) <= f64::from(self.m) + f64::from(TOLERANCE) {
                                    self.s = (f64::from(self.acc_s) - f64::from(self.acc_m) + f64::from(self.m)) as f32;
                                    aligned = true;
                                    break;
                                }
                            }
                            if f64::from(self.acc_m) - f64::from(TOLERANCE) <= f64::from(self.acc_s) {
                                continue;
                            }
                            self.next_staff();
                            if f64::from(self.m) + f64::from(TOLERANCE) >= f64::from(self.s) {
                                break;
                            }
                        }
                        if finished {
                            break;
                        }
                        if !aligned {
                            self.j -= 1;
                            self.s = ((f64::from(self.acc_s) - f64::from(self.s)) - f64::from(self.acc_m) + f64::from(self.m)) as f32;
                        }
                    }
                    self.acc_s = self.s;
                    self.acc_m = self.m;
                }
                if !finished {
                    self.out.push(self.m);
                }
            }
            if self.master.len() <= self.i {
                return Ok(self.out);
            }
        }
        Err(LayoutErrorKind::NoEnd)
    }
}

/// The master list with its durations split at the staff's onsets.
pub fn merge_durations(master: &[f32], staff_durations: &[f32]) -> Result<Vec<f32>, LayoutErrorKind> {
    DurationMerge { master, staff: staff_durations, out: Vec::new(), i: 0, j: 0, m: 0.0, s: 0.0, acc_m: 0.0, acc_s: 0.0 }.run()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn repeated_barlines_go() {
        assert_eq!(drop_repeated_barlines(&[4.0, BARLINE, BARLINE, 4.0, BARLINE]), [4.0, BARLINE, 4.0, BARLINE]);
    }

    #[test]
    fn durations_split_at_the_other_staffs_onsets() {
        let merged = merge_durations(&[4.0, BARLINE], &[2.0, 2.0]).unwrap();
        assert_eq!(merged, [2.0, 2.0, BARLINE]);
    }
}
