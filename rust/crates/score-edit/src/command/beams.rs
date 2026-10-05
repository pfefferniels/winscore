//! Commands that fit notes to the beams and chords around them (WinScore
//! help, code1.txt "Stems", code6.txt "Stem Adjustments").

use score_render::staff::StaffTable;
use score_render::Document as RenderDocument;

use crate::command::Run;
use crate::document::ItemId;
use crate::error::EditError;
use crate::params::Draft;

const NOTE: i32 = 1;
const BEAM: i32 = 6;
const STEM: usize = 5;
const DURATION: usize = 7;
const STEM_LENGTH: usize = 8;
const DOTS_TAILS: usize = 9;
const SIZE_FACTOR: usize = 15;
const BEAM_SIZE_FACTOR: usize = 18;
/// Head width in step units (f32 2.83333, 0x40C1C0).
const HEAD_WIDTH: f32 = 2.83333;
/// Cue beams and their notes are drawn at this size, their beams this thick.
const CUE_SIZE: f32 = 0.6;
const CUE_THICKNESS: f32 = 0.8;
/// Steps between beam levels.
const BEAM_SPACING: f32 = 1.5;
/// How far a note may lie beyond the beam's ends and still belong to it.
const REACH: f32 = 0.1;
/// An opposite stem's P8 counts from 14 steps.
const OPPOSITE_BASE: f64 = 14.0;

/// What the AD… words change: ADX/ADJX/ADFX also fit stems going against
/// the beam's direction, ADF/ADFX shorten inner stems in the French manner.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct StemFit {
    pub opposite: bool,
    pub french: bool,
}

/// The engine keeps these intermediates as REAL*4.
fn f(x: f64) -> f64 {
    f64::from(x as f32)
}

fn c(x: f32) -> f64 {
    f64::from(x)
}

fn trunc(x: f64) -> i64 {
    x.trunc() as i64
}

/// The engine's AMOD (0x54AABA).
fn amod(x: f64, y: f64) -> f64 {
    f(x - trunc(x / y) as f64 * y)
}

/// The stem direction digit of a note's P5: 1 up, 2 down, 0 none.
fn stem(draft: &Draft) -> i64 {
    trunc(amod(c(draft.get(STEM)), 100.0) / 10.0)
}

fn cue_hundreds(p4: f32) -> i64 {
    trunc(c(p4) / 100.0).abs()
}

/// A beam line from x to x (0 for none).
type Span = (f64, f64);

/// The ends of the beam and of its second and third beams, as 0x40C1C0
/// moves them before it measures.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Lines {
    main: Span,
    second: Span,
    third: Span,
}

/// P8 of one note under `beam` (0x40C1C0) before the division by the note's
/// size factor; reimplemented after disasm-expert's `beam_stems.py`.
/// `staff_offset` converts a cross-staff note's P4 to the beam's staff.
fn stem_length(beam: &Draft, note: &Draft, note_stem: i64, fit: StemFit, step: f64, staff_offset: f64) -> f64 {
    let b = |k: usize| c(beam.get(k));
    let ip7 = trunc(b(7));
    let up_beam = ip7 / 10 == 1;
    let cue = cue_hundreds(note.get(4)) > 0;
    let note_level = f(staff_offset + amod(c(note.get(4)), 100.0));
    let size = if cue { c(CUE_SIZE) } else { 1.0 };
    let h = f(size * c(HEAD_WIDTH) * step / 25.0);
    let beams = ip7 % 10;
    let thickness = if b(17) == 0.0 { 1.0 } else { b(17) };
    let thickness = if cue { f(thickness * c(CUE_THICKNESS)) } else { thickness };
    let (ip10, ip13) = (trunc(b(10)), trunc(b(13)));
    let extra = f((beams - 1) as f64 * c(BEAM_SPACING));
    let or_end = |v: f64, end: f64| if v == -1.0 { end } else { v };
    let nudge = |v: f64| if v != 0.0 && up_beam { f(h + v) } else { v };
    let shift = |v: f64| match v {
        10.0 => h,
        20.0 => -h,
        v => v,
    };
    let gap = |ip: i64, (from, to): Span| -> f64 {
        match ip {
            ip if ip < 0 && from != 0.0 && to != 0.0 => f(-((ip / 10) as f64 * c(BEAM_SPACING))),
            ip if ip < 0 => 0.0,
            ip => {
                let unit = if ip % 10 == 0 { 1 } else { ip % 10 };
                f((ip / 10 + unit - beams) as f64 * c(BEAM_SPACING))
            }
        }
    };
    let main = if up_beam { (f(h + b(3)), f(h + b(6))) } else { (b(3), b(6)) };
    let mut lines = Lines { main, second: (or_end(b(11), b(3)), or_end(b(12), b(6))), third: (or_end(b(14), b(3)), or_end(b(15), b(6))) };
    let mut second = 0.0;
    if ip10 != 0 {
        lines.second = (nudge(lines.second.0), nudge(lines.second.1));
        second = gap(ip10, lines.second);
    }
    let mut third = 0.0;
    if ip13 == 0 {
        lines.main = (f(shift(lines.third.0) + lines.main.0), f(shift(lines.third.1) + lines.main.1));
    } else {
        lines.third = (nudge(lines.third.0), nudge(lines.third.1));
        third = gap(ip13, lines.third);
    }
    let x = if note_stem == 1 { f(h + c(note.get(3))) } else { c(note.get(3)) };
    let x = if note.get(10) != 0.0 { f(shift(c(note.get(10))) + x) } else { x };
    let ip9 = trunc(b(9));
    let towards = if up_beam { -h } else { h };
    let moved = |digit: i64, (from, to): Span| {
        let from = if digit == 1 || digit == 3 { f(towards + from) } else { from };
        let to = if digit == 2 || digit == 3 { f(towards + to) } else { to };
        (from, to)
    };
    lines = Lines { main: moved(ip9 / 100, lines.main), second: moved(ip9 % 100 / 10, lines.second), third: moved(ip9 % 10, lines.third) };
    let span = f(lines.main.1 - lines.main.0);
    let (left, right) = (f(amod(b(4), 100.0) - note_level), f(b(5) - note_level));
    let (left, right) = if note_stem == 1 { (left, right) } else { (f(-left), f(-right)) };
    let level = f(((x - lines.main.0) / span) * (right - left) + left);
    let reach = c(REACH);
    let under = |(from, to): Span| x < to + reach && from - reach < x;
    let same = ip7 / 10 == note_stem;
    let counts = |ip: i64| if same { ip < 0 } else { ip > 0 };
    let add = if under(lines.second) && counts(ip10) { second } else { 0.0 };
    let add = if add < third && under(lines.third) && counts(ip13) { third } else { add };
    let length = if same {
        f(add + f(level / size))
    } else {
        f(add + ((extra + f(level / size)) - OPPOSITE_BASE) + thickness)
    };
    let inner = (lines.main.0 - x).abs() > reach && (lines.main.1 - x).abs() > reach;
    if !(fit.french && inner) {
        return length;
    }
    let within = |(from, to): Span, ip: i64| to != 0.0 && ip != 0 && from != 0.0 && from + reach <= x && x <= to - reach;
    let cut = if within(lines.second, ip10) { second } else { 0.0 };
    let cut = if within(lines.third, ip13) && cut < third { third } else { cut };
    f((length - extra) - cut)
}

/// Whether `note` takes part in the stem pass for `beam` (0x40CDE4).
fn under_beam(beam: &Draft, note: &Draft, opposite: bool) -> bool {
    let reach = c(REACH);
    let note_stem = stem(note);
    note.code() == NOTE
        && trunc(c(note.get(2))) == trunc(c(beam.get(2)))
        && (c(beam.get(3)) - reach..=c(beam.get(6)) + reach).contains(&c(note.get(3)))
        && note_stem != 0
        && note.get(6) != 1.0
        && (trunc(c(beam.get(DURATION))) / 10 == note_stem || opposite)
        && cue_hundreds(beam.get(4)) == cue_hundreds(note.get(4))
}

fn is_fitting_beam(draft: &Draft) -> bool {
    draft.code() == BEAM && draft.get(DURATION) >= 0.0
}

/// The cross-staff shift of a note with P12 set, in steps of `step` (0x40C1C0).
fn cross_staff_offset(note: &Draft, staves: &StaffTable) -> f64 {
    if note.get(12) == 0.0 {
        return 0.0;
    }
    let s = trunc(c(note.get(2))) as i32;
    let other = s + trunc(3.0 - c(note.get(12)) * 2.0) as i32;
    let d = trunc(f64::from(staves.get(s).level0) - f64::from(staves.get(other).level0));
    f(-(d as f64 / (staves.get(s).step * 7.0)))
}

/// `note` with P8 = `length` (divided by its size factor) and P9 without flags.
fn with_stem(note: &Draft, length: f64) -> Draft {
    let length = if note.get(SIZE_FACTOR) == 0.0 { length } else { f(length / c(note.get(SIZE_FACTOR))) };
    let mut out = note.clone();
    out.set(STEM_LENGTH, length as f32);
    let tails = c(note.get(DOTS_TAILS));
    if tails != 0.0 {
        out.set(DOTS_TAILS, f(tails - trunc(amod(tails, 10.0)) as f64) as f32);
    }
    out
}

/// The STEP global drawing `item` leaves: its staff's step times its size
/// factor (P15 of notes, P18 of beams), which the stem pass measures with.
fn drawn_step(item: &Draft, staves: &StaffTable, size_param: usize) -> f64 {
    let size = if item.get(size_param) == 0.0 { 1.0 } else { c(item.get(size_param)) };
    f(staves.get(item.get(2) as i32).step * size)
}

/// A note of the selected beam, fitted to it (0x40CDE4).
fn fitted(beam: &Draft, note: &Draft, fit: StemFit, staves: &StaffTable) -> Draft {
    let step = drawn_step(beam, staves, BEAM_SIZE_FACTOR);
    with_stem(note, stem_length(beam, note, stem(note), fit, step, cross_staff_offset(note, staves)))
}

/// Why a selected note keeps its stem.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Unfitted {
    /// The engine fits only notes shorter than a quarter.
    TooLong,
    NoBeam,
}

/// ADJ on a note in edit mode (0x40BC18): the longest stem any beam of
/// staff `on` over the note asks for. The engine compares the note's cue
/// hundreds with the beam's P1 / 100, which is always 0, so cue notes find
/// no beam; and it measures with the STEP that drawing the note left.
fn note_fitted(note: &Draft, beams: &[&Draft], on: f32, fit: StemFit, staves: &StaffTable) -> Result<Draft, Unfitted> {
    if note.get(DURATION) >= 1.0 {
        return Err(Unfitted::TooLong);
    }
    let note_stem = stem(note);
    if note_stem == 0 || note.get(6) == 1.0 || cue_hundreds(note.get(4)) != 0 {
        return Err(Unfitted::NoBeam);
    }
    let reach = c(REACH);
    let own = staves.get(note.get(2) as i32);
    let step = drawn_step(note, staves, SIZE_FACTOR);
    let same_staff = on == note.get(2);
    let longest = beams
        .iter()
        .filter(|b| b.get(2) == on && (c(b.get(3)) - reach..=c(b.get(6)) + reach).contains(&c(note.get(3))))
        .filter(|b| trunc(c(b.get(DURATION))) >= 1)
        .filter(|b| !same_staff || trunc(c(b.get(DURATION))) / 10 == note_stem || fit.opposite)
        .map(|b| stem_length(b, note, note_stem, fit, step, cross_staff_offset(note, staves)))
        .fold(None, |longest: Option<f64>, length| Some(longest.map_or(length, |l| l.max(length))))
        .ok_or(Unfitted::NoBeam)?;
    let offset = if same_staff {
        0.0
    } else {
        let d = staves.get(on as i32).level0 - own.level0;
        let shift = f(f64::from(d) / (step * 7.0));
        if note.get(STEM) >= 20.0 { -shift } else { shift }
    };
    Ok(with_stem(note, f(offset + longest)))
}

impl Run<'_, '_> {
    fn drafts(&self) -> Vec<(ItemId, Draft)> {
        self.tx.doc().entries().map(|(id, item)| (id, Draft::of(item))).collect()
    }

    /// ADJ and its variants: the stems of the notes under each selected beam
    /// (0x40CDE4; tremolo beams with P7 < 0 are left alone), or of each
    /// selected note (0x40BC18; `staff` names the beam's staff if not its own).
    pub fn adjust_stems(&mut self, fit: StemFit, staff: Option<f32>) -> Result<(), EditError> {
        let all = self.drafts();
        let staves = RenderDocument::new(self.tx.doc().file()).staves;
        let beams: Vec<&Draft> = all.iter().map(|(_, d)| d).filter(|d| d.code() == BEAM).collect();
        let selected: Vec<&(ItemId, Draft)> =
            self.session.selection().iter().filter_map(|id| all.iter().find(|(i, _)| i == id)).collect();
        let mut too_long = false;
        let notes: Vec<(ItemId, Draft)> = selected
            .iter()
            .flat_map(|(id, chosen)| -> Vec<(ItemId, Draft)> {
                match chosen.code() {
                    BEAM if is_fitting_beam(chosen) => all
                        .iter()
                        .filter(|(_, d)| under_beam(chosen, d, fit.opposite))
                        .map(|(i, d)| (*i, fitted(chosen, d, fit, &staves)))
                        .collect(),
                    NOTE => match note_fitted(chosen, &beams, staff.unwrap_or(chosen.get(2)), fit, &staves) {
                        Ok(note) => vec![(*id, note)],
                        Err(why) => {
                            too_long |= why == Unfitted::TooLong;
                            Vec::new()
                        }
                    },
                    _ => Vec::new(),
                }
            })
            .collect();
        if too_long {
            self.session.message = Some("Adjust stems only for 1/8, 1/16, etc.".to_owned());
        }
        notes.into_iter().for_each(|(id, note)| {
            self.tx.replace(id, note.to_item());
        });
        Ok(())
    }

    /// CH [value]: on a stemmed note, every note of its chord (same staff and
    /// P3) takes its duration, or `value`. Stemless chord notes do nothing.
    pub fn chord_rhythm(&mut self, value: Option<f32>) -> Result<(), EditError> {
        let all = self.drafts();
        let chosen: Vec<Draft> = self
            .session
            .selection()
            .iter()
            .filter_map(|id| all.iter().find(|(i, _)| i == id).map(|(_, d)| d.clone()))
            .filter(|d| d.code() == NOTE && stem(d) != 0)
            .collect();
        let durations: Vec<(ItemId, f32)> = chosen
            .iter()
            .flat_map(|note| {
                let duration = value.unwrap_or(note.get(DURATION));
                all.iter()
                    .filter(|(_, d)| d.code() == NOTE && d.get(2) == note.get(2) && d.get(3) == note.get(3))
                    .map(move |(id, _)| (*id, duration))
            })
            .collect();
        durations.into_iter().for_each(|(id, duration)| {
            let Some(item) = self.tx.doc().item(id) else { return };
            let mut note = Draft::of(item);
            note.set(DURATION, duration);
            self.tx.replace(id, note.to_item());
        });
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    const ADJ: StemFit = StemFit { opposite: false, french: false };
    const ADX: StemFit = StemFit { opposite: true, french: false };

    #[test]
    fn stems_reach_the_beam_line() {
        let beam = Draft::new(&[6.0, 1.0, 100.0, 13.0, 15.0, 130.0, 11.0]);
        let note = Draft::new(&[1.0, 1.0, 110.0, 8.0, 10.0, 0.0, 0.5, 0.0, 11.0]);
        assert!(under_beam(&beam, &note, false));
        let length = stem_length(&beam, &note, 1, ADJ, 25.0, 0.0);
        assert!((length - 5.666_666).abs() < 1e-5, "{length}");
        let down = Draft::new(&[1.0, 1.0, 110.0, 8.0, 20.0, 0.0, 0.5, 0.0, 1.0]);
        assert!(!under_beam(&beam, &down, false) && under_beam(&beam, &down, true));
    }

    #[test]
    fn opposite_stems_count_from_fourteen_steps() {
        let beam = Draft::new(&[6.0, 1.0, 100.0, 13.0, 15.0, 120.0, 11.0]);
        let note = Draft::new(&[1.0, 1.0, 110.0, 8.0, 20.0, 0.0, 0.5]);
        let length = stem_length(&beam, &note, 2, ADX, 25.0, 0.0);
        assert!((length + 18.716_67).abs() < 1e-4, "{length}");
    }
}
