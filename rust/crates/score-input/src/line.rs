//! One line of input as the engine holds it between passes: notes, rests and the other
//! elements with their positions, plus the items passes 3-5 attach to them.

use score_format::{Item, Word};

use crate::chords::{accidental_offsets, dot_offsets, ChordHead};
use crate::events::{Event, Head};
use crate::num::amod;
use crate::notes::{BarStyle, Clef, Direction, KeySignature, Meter, Rest, RestKind, StaffShift, StemMode};
use crate::rhythm::Rhythm;
use crate::slurs::WorkEntry;
use crate::spacing::{positions, Entry, GRACE_DURATION};
use crate::{Neighbours, Options, Outline};

/// Middle staff line: notes from here up take a down stem, and a stem reaches at least here.
pub(crate) const MIDDLE_LINE: i32 = 7;
/// A normal stem is one octave long.
pub(crate) const STEM: i32 = 7;
const STEM_UP: i32 = 10;
const STEM_DOWN: i32 = 20;
/// P10 of a chord note moved one head width to the right (stem up) or left (stem down).
const SHIFT_RIGHT: f32 = 10.0;
const SHIFT_LEFT: f32 = 20.0;
/// Added to P4 (away from 0) for grace and cue notes.
const SMALL_LEVEL: i32 = 100;
/// Added to P5 for an accidental in parentheses.
const CAUTIONARY: i32 = 100;
/// P7 of the further heads of a grace chord (the stem head has 65).
const GRACE_CHORD_MEMBER: f32 = 64.0;

/// Builds an item; trailing zero parameters are dropped as the engine does.
pub(crate) fn item(params: &[f32]) -> Item {
    let used = params.iter().rposition(|p| *p != 0.0).map_or(0, |i| i + 1);
    Item::new(params[..used].iter().copied().map(Word::from_f32).collect())
}

/// A note or chord.
#[derive(Debug, Clone, PartialEq)]
pub(crate) struct Note {
    pub x: f32,
    /// In item order: the head carrying the stem first (lowest first for an up stem).
    pub heads: Vec<Head>,
    pub rhythm: Rhythm,
    pub down: bool,
    /// The stem direction the heads are laid out for (seconds, accidentals, dots); differs
    /// from `down` only after `turn_heads`.
    pub heads_down: bool,
    /// P8 of the head that carries the stem.
    pub extension: f32,
    /// P8 as the engine's work table keeps it for pass 5: the pass-2 value, not updated when a
    /// beam fits the stem (that happens in the item store), 0 after a beam turned a chord.
    pub table_extension: f32,
    /// Flags drawn on the stem; removed when the note is beamed.
    pub tails: i32,
    /// P11 of the head that carries the stem (marks from pass 3).
    pub mark: f32,
    pub shift: StaffShift,
    /// SU/SD/SO in force when the note was typed.
    pub stem_mode: StemMode,
    /// Heads whose dots were laid out again after a beam turned the chord.
    pub redotted: Option<usize>,
    /// Heads, from the stem head on, that the chord layout lays out (seconds and accidentals).
    pub laid_out_heads: usize,
    /// An entry left at another x than the chord (position in item order, x): the
    /// minimum-gap pass never moves the last entry of the line, which can be the last
    /// member of a chord. Positions stay when a beam reverses the heads.
    pub stray_head: Option<(usize, f32)>,
    /// The layout a stray head kept when a beam turned the rest of the chord.
    kept_layout: Option<HeadLayout>,
    /// A grace chord that pass 1 sorted from the top and pass 2 spaced in that order.
    spaced_from_top: bool,
    /// Cue size: P4 is stored 100 further from 0, as for grace notes.
    pub cue: bool,
    /// The head (in item order) whose placement on another staff was dropped because that
    /// staff cannot exist; the other heads keep theirs.
    pub placement_dropped: Option<usize>,
    /// P5, P10 and dots of every head when they do not follow from the heads (a grace
    /// chord in the refit).
    explicit_layout: Option<Vec<HeadLayout>>,
}

/// What the chord layout gives a head: P5 with the accidental's offset, P10, and the dot
/// additions to P9.
#[derive(Debug, Clone, Copy, PartialEq)]
struct HeadLayout {
    p5: f32,
    shift: f32,
    dots: i32,
}

impl Note {
    fn new(x: f32, heads: Vec<Head>, rhythm: Rhythm, stems: StemMode, shift: StaffShift) -> Self {
        let mut note = Note {
            x,
            heads,
            rhythm,
            down: false,
            heads_down: false,
            extension: 0.0,
            table_extension: 0.0,
            tails: rhythm.tails(),
            mark: 0.0,
            shift,
            stem_mode: stems,
            redotted: None,
            laid_out_heads: 0,
            stray_head: None,
            kept_layout: None,
            spaced_from_top: false,
            cue: false,
            placement_dropped: None,
            explicit_layout: None,
        };
        note.laid_out_heads = note.heads.len();
        let down = match stems {
            StemMode::Up => false,
            StemMode::Down => true,
            StemMode::Ordinary => note.lowest() + note.highest() >= 2 * MIDDLE_LINE,
        };
        // Pass 2 turns grace stems up unless SD fixed them, after spacing the heads in the
        // order pass 1 sorted them.
        note.spaced_from_top = down && note.is_grace() && stems != StemMode::Down;
        if down && (!note.is_grace() || stems == StemMode::Down) {
            // From the top, but heads on the same level keep the order they were typed in.
            note.heads = note.heads.chunk_by(|a, b| a.level == b.level).rev().flatten().copied().collect();
            note.down = true;
            note.heads_down = true;
        }
        note.fit_stem();
        // The builder settles a chord's stem by comparing its last head with the stem head,
        // taking the stem direction from the head before the last when they are level. With
        // three or more heads on one level that head has no stem, so the stem turns up, and
        // the accidental layout is handed only the first two heads.
        if note.heads.len() >= 3 && note.lowest() == note.highest() {
            note.down = false;
            note.heads_down = false;
            note.laid_out_heads = 2;
        }
        if note.is_grace() {
            note.extension = note.grace_extension(down);
        }
        note.table_extension = note.extension;
        note
    }

    /// A chord whose notes reach pass 1 in two runs (the refit sends a stem code before a
    /// stem head that is not the chord's first note). The builder sorts only the first run
    /// and appends the rest; the stem then goes up when the last note is above the first,
    /// down when below, and for a unison by the stem of the note before it; P8 spans from
    /// the first note; the chord layout lays out the heads up to that last comparison.
    pub fn set_pass1_chord(&mut self, run: &[Head], rest: &[Head]) {
        let mut sorted = run.to_vec();
        sorted.sort_by_key(|h| h.level);
        let (low, high) = (sorted.first().map_or(0, |h| h.level), sorted.last().map_or(0, |h| h.level));
        let ascending = match self.stem_mode {
            StemMode::Up => true,
            StemMode::Down => false,
            StemMode::Ordinary => 2 * MIDDLE_LINE - (low + high) > 0,
        };
        if !ascending {
            sorted = sorted.chunk_by(|a, b| a.level == b.level).rev().flatten().copied().collect();
        }
        let heads: Vec<Head> = sorted.into_iter().chain(rest.iter().copied()).collect();
        let first = heads[0].level;
        let first_down = match self.stem_mode {
            StemMode::Up => false,
            StemMode::Down => true,
            StemMode::Ordinary => first >= MIDDLE_LINE,
        };
        // (sign, distance) of the last comparison with the first note.
        let last = heads.iter().enumerate().skip(1).fold((if first_down { -1 } else { 1 }, 0usize), |_, (j, h)| {
            let previous_down = j == 1 && first_down;
            match h.level.cmp(&first) {
                std::cmp::Ordering::Greater => (1, j),
                std::cmp::Ordering::Less => (-1, j),
                std::cmp::Ordering::Equal => (if previous_down { -1 } else { 1 }, 1),
            }
        });
        let down = if heads.len() > 1 { last.0 < 0 } else { first_down };
        let span = heads.iter().map(|h| (h.level - first).abs()).max().unwrap_or(0);
        let to_middle = if down { first - STEM - MIDDLE_LINE } else { MIDDLE_LINE - STEM - first };
        self.laid_out_heads = (last.1 + 1).max(1);
        self.heads = heads;
        self.down = down;
        self.heads_down = down;
        let normal = span.max(to_middle).max(0) as f32;
        self.extension = if self.cue { self.cue_extension(normal) } else { normal };
        self.table_extension = self.extension;
    }

    /// A grace chord as pass 2 leaves it inside the refit. The chord layout skips the
    /// part that only runs in the IN pass 2 (sorting the heads, clearing P10, rounding P5),
    /// so: the heads keep pass 1's order, the lowest swapped to the front when the stem is
    /// free; P10 values stay at their places while P4 and P5 move; the
    /// accidental offsets of pass 1 and pass 2 add up; P8 comes from a value the engine left
    /// at 0 for the grace note.
    fn lay_out_grace_chord_for_refit(&mut self) {
        if !self.is_grace() || self.heads.len() < 2 {
            return;
        }
        let side = |down: bool| if down { SHIFT_LEFT } else { SHIFT_RIGHT };
        let pass1_down = match self.stem_mode {
            StemMode::Up => false,
            StemMode::Down => true,
            StemMode::Ordinary => self.lowest() + self.highest() >= 2 * MIDDLE_LINE,
        };
        let mut heads = self.heads.clone();
        heads.sort_by_key(|h| h.level);
        if pass1_down {
            heads = heads.chunk_by(|a, b| a.level == b.level).rev().flatten().copied().collect();
        }
        let stem = if pass1_down { STEM_DOWN } else { STEM_UP };
        let (shifts, offsets) = Self::refit_layout_pass(&heads, &[], pass1_down, side(pass1_down));
        let mut slots: Vec<(Head, f32)> = heads
            .iter()
            .zip(offsets)
            .enumerate()
            .map(|(k, (h, o))| {
                let base = h.accidental.map_or(0, |a| a.code()) + if k == 0 { stem } else { 0 };
                (*h, (f64::from(o) / 1000.0 + f64::from(base)) as f32)
            })
            .collect();
        if self.stem_mode == StemMode::Ordinary {
            slots[0].1 = amod(slots[0].1, 10.0);
            for m in 1..slots.len() {
                if slots[m].0.level <= slots[0].0.level {
                    slots.swap(0, m);
                }
            }
            slots[0].1 += STEM_UP as f32;
        }
        let down = amod(slots[0].1, 100.0) >= STEM_DOWN as f32;
        let placed: Vec<Head> = slots.iter().map(|s| s.0).collect();
        let (shifts, offsets) = Self::refit_layout_pass(&placed, &shifts, down, side(down));
        self.explicit_layout = Some(
            slots
                .iter()
                .zip(offsets)
                .zip(shifts)
                .map(|((slot, offset), shift)| HeadLayout { p5: (f64::from(offset) / 1000.0 + f64::from(slot.1)) as f32, shift, dots: 0 })
                .collect(),
        );
        self.heads = placed;
        self.down = down;
        self.heads_down = down;
        self.extension = (f64::from(0.0f32) * f64::from(1.6666f32) - f64::from(0.3333f32)) as f32;
        self.table_extension = self.extension;
    }

    /// One run of the chord layout without its IN-pass-2 part on heads in place order: P10 set
    /// for seconds (other places keep `previous`), and the accidental offsets.
    fn refit_layout_pass(heads: &[Head], previous: &[f32], down: bool, side: f32) -> (Vec<f32>, Vec<i32>) {
        let levels: Vec<i32> = heads.iter().map(|h| h.level).collect();
        let shifts: Vec<f32> = second_shifts(&levels)
            .into_iter()
            .enumerate()
            .map(|(k, s)| if s { side } else { previous.get(k).copied().unwrap_or(0.0) })
            .collect();
        let left: Vec<bool> = shifts.iter().map(|s| *s == SHIFT_LEFT).collect();
        let refs: Vec<&Head> = heads.iter().collect();
        let offsets = positional_accidental_offsets(&refs, &left, down);
        (shifts, offsets)
    }

    /// P8 of a grace note: 100 (the slash) plus a stem length that grows for notes
    /// below the staff; a grace chord encodes its span. `down` is the stem pass 1 gave the
    /// note before pass 2 turned every grace stem up.
    fn grace_extension(&self, down: bool) -> f32 {
        if self.heads.len() >= 2 {
            let span = self.highest().max(0) - self.lowest() + 61;
            return (span as f64 * 1.6666f32 as f64 - 0.3333f32 as f64) as f32;
        }
        let level = self.lowest();
        let length = if !down && level < 1 { ((2 - level) as f64 * 1.66666f32 as f64 - 2.0) as f32 } else { 0.0 };
        let length = if length == 0.0 { 1.0 } else { length };
        length + SMALL_LEVEL as f32
    }

    pub fn lowest(&self) -> i32 {
        self.heads.iter().map(|h| h.level).min().unwrap_or(0)
    }

    pub fn highest(&self) -> i32 {
        self.heads.iter().map(|h| h.level).max().unwrap_or(0)
    }

    /// The level of the head the stem starts from, the first in item order.
    pub fn stem_level(&self) -> i32 {
        self.heads.first().map_or(0, |h| h.level)
    }

    pub fn is_grace(&self) -> bool {
        self.rhythm == Rhythm::Grace
    }

    /// Makes the note cue size. Pass 2 gives cue notes their own P8: from a head below
    /// the staff (stem up) or above it (stem down), and for a chord at least twice the
    /// normal P8.
    pub fn set_cue(&mut self) {
        self.cue = true;
        self.extension = self.cue_extension(self.extension);
        self.table_extension = self.extension;
    }

    /// P8 of a cue note or chord whose P8 at normal size would be `normal`.
    fn cue_extension(&self, normal: f32) -> f32 {
        let from_head = |steps: i32| (f64::from(steps as f32) * f64::from(1.66666f32) - 2.0) as f32;
        let by_level = match (self.down, self.stem_level()) {
            (true, l) if l > 13 => from_head(l - 12),
            (false, l) if l < 1 => from_head(2 - l),
            _ => 0.0,
        };
        let doubled = amod(normal, 100.0) * 2.0;
        if self.heads.len() > 1 && by_level < doubled {
            doubled
        } else {
            by_level
        }
    }

    /// Grace or cue size: the notes whose P4 is stored with 100 added (|P4| >= 100).
    pub fn is_small(&self) -> bool {
        self.is_grace() || self.cue
    }

    /// The heads the beam routine turns with the chord: those at the chord's x, which leaves
    /// out a stray last head.
    fn run_len(&self) -> usize {
        match self.stray_head {
            Some((i, _)) if i + 1 == self.heads.len() => i,
            _ => self.heads.len(),
        }
    }

    /// Reverses the heads at the chord's x and lays them out for `down`; a stray head
    /// keeps the layout it had.
    fn reverse_run(&mut self, down: bool) {
        let run = self.run_len();
        if run < self.heads.len() {
            self.kept_layout = self.head_layouts().get(run).copied();
        }
        self.heads[..run].reverse();
        self.heads_down = down;
        self.laid_out_heads = run;
    }

    /// Turns the stem; the engine reverses the chord's heads, so the head that
    /// carried the stem ends up last.
    pub fn set_stem(&mut self, down: bool) {
        if self.down != down {
            self.reverse_run(down);
            self.down = down;
        }
        self.fit_stem();
    }

    /// The beam routine reverses the heads of every chord in a beam group that goes the other
    /// way, also when SU/SD or an earlier beam fixed its stem. Such a chord keeps its stem
    /// direction and flags but lays out its heads for the beam's direction and loses its
    /// stem extension. Grace chords are left alone.
    pub fn turn_heads(&mut self, down: bool, first_entry: usize) {
        if self.heads.len() > 1 && !self.is_grace() && self.heads_down != down {
            self.reverse_run(down);
            self.extension = 0.0;
            self.table_extension = 0.0;
            self.redot_after_turn(first_entry);
        }
    }

    /// P8 that spans the chord and reaches the middle line.
    fn fit_stem(&mut self) {
        let (low, high) = (self.lowest(), self.highest());
        let to_middle = if self.down { high - STEM - MIDDLE_LINE } else { MIDDLE_LINE - STEM - low };
        self.extension = (high - low).max(to_middle).max(0) as f32;
    }

    /// The heads in item order: the head carrying the stem first.
    pub fn ordered_heads(&self) -> Vec<&Head> {
        self.heads.iter().collect()
    }

    fn work_entries(&self, number: usize, staff_steps: f32) -> Vec<WorkEntry> {
        self.ordered_heads()
            .iter()
            .enumerate()
            .map(|(i, head)| {
                let stem_head = i == 0;
                WorkEntry {
                    code: 1,
                    x: self.x,
                    level: head.level,
                    stem: match (stem_head, self.down) {
                        (false, _) => 0,
                        (true, true) => STEM_DOWN,
                        (true, false) => STEM_UP,
                    },
                    accidental: head.accidental.map_or(0, |a| a.code()),
                    extension: if stem_head { self.table_extension % 100.0 } else { 0.0 },
                    dotted: stem_head && self.rhythm.dots() > 0,
                    mark: if stem_head { self.mark } else { 0.0 },
                    grace: self.is_grace(),
                    note: stem_head.then_some(number),
                    staff_steps,
                }
            })
            .collect()
    }

    fn spacing_entries(&self) -> Vec<Entry> {
        let quarters = if self.is_grace() { GRACE_DURATION } else { self.rhythm.quarters() };
        let mut heads = self.ordered_heads();
        if self.spaced_from_top {
            heads.reverse();
        }
        heads
            .iter()
            .enumerate()
            .map(|(i, head)| Entry::Note { quarters, accidental: head.accidental.is_some(), first: i == 0 })
            .collect()
    }

    /// P5 of each head in item order: the stem on the stem head, the accidental, and the
    /// accidental's offset to the left in thousandths.
    pub fn p5s(&self) -> Vec<f32> {
        self.head_layouts().iter().map(|layout| layout.p5).collect()
    }

    /// Which heads, in item order, sit on the other side of the stem.
    fn shifted(&self) -> Vec<bool> {
        let covered = self.laid_out_heads.min(self.heads.len());
        let levels: Vec<i32> = self.heads[..covered].iter().map(|h| h.level).collect();
        let mut shifted = second_shifts(&levels);
        shifted.resize(self.heads.len(), false);
        shifted
    }

    /// P5, P10 and the dot additions to P9 of each head in item order.
    fn head_layouts(&self) -> Vec<HeadLayout> {
        if let Some(layout) = &self.explicit_layout {
            return layout.clone();
        }
        let ordered = self.ordered_heads();
        let levels: Vec<i32> = ordered.iter().map(|h| h.level).collect();
        let shifted = self.shifted();
        let covered = self.laid_out_heads.min(ordered.len());
        let mut offsets = self.accidental_offsets(&ordered[..covered], &shifted[..covered]);
        offsets.resize(ordered.len(), 0);
        let dots = self.dot_offsets(&levels, &shifted);
        let side = if self.heads_down { SHIFT_LEFT } else { SHIFT_RIGHT };
        let mut layouts: Vec<HeadLayout> = ordered
            .iter()
            .enumerate()
            .map(|(i, head)| {
                let stem = match (i == 0, self.down) {
                    (false, _) => 0,
                    (true, true) => STEM_DOWN,
                    (true, false) => STEM_UP,
                };
                // The head carrying a grace note's stem drops the parentheses.
                let parentheses = if head.cautionary && !(self.is_grace() && i == 0) { CAUTIONARY } else { 0 };
                HeadLayout {
                    p5: (f64::from(offsets[i]) / 1000.0 + f64::from(stem + parentheses + head.accidental.map_or(0, |a| a.code())))
                        as f32,
                    shift: if shifted[i] { side } else { 0.0 },
                    dots: dots[i],
                }
            })
            .collect();
        if let (Some(kept), Some(last)) = (self.kept_layout, layouts.last_mut()) {
            *last = kept;
        }
        layouts
    }

    fn items(&self, staff: f32) -> Vec<Item> {
        let ordered = self.ordered_heads();
        let layouts = self.head_layouts();
        let dots = 10 * i32::from(self.rhythm.dots());
        let staff_shift = match self.shift {
            StaffShift::Main => 0.0,
            StaffShift::Above => 1.0,
            StaffShift::Below => 2.0,
        };
        ordered
            .iter()
            .enumerate()
            .map(|(i, head)| {
                let stem_head = i == 0;
                let level = match (self.is_small(), head.level < 0) {
                    (false, _) => head.level,
                    (true, false) => head.level + SMALL_LEVEL,
                    (true, true) => head.level - SMALL_LEVEL,
                };
                let (extension, tails, mark) =
                    if stem_head { (self.extension, self.tails, self.mark) } else { (0.0, 0, 0.0) };
                let x = match self.stray_head {
                    Some((stray, x)) if stray == i => x,
                    _ => self.x,
                };
                item(&[
                    1.0,
                    staff,
                    x,
                    level as f32,
                    layouts[i].p5,
                    self.rhythm.head() as f32,
                    if self.is_grace() && !stem_head { GRACE_CHORD_MEMBER } else { self.rhythm.quarters() },
                    extension,
                    (dots + tails + layouts[i].dots) as f32,
                    layouts[i].shift,
                    mark,
                    if self.placement_dropped == Some(i) { 0.0 } else { staff_shift },
                ])
            })
            .collect()
    }

    /// P9 additions for the dots; after a beam turned the chord only its first
    /// `redotted` heads are laid out again.
    fn dot_offsets(&self, levels: &[i32], shifted: &[bool]) -> Vec<i32> {
        if self.rhythm.dots() == 0 {
            return vec![0; levels.len()];
        }
        let laid_out = self.redotted.unwrap_or(levels.len()).min(levels.len());
        let lower_voice = self.stem_mode == StemMode::Down && self.redotted.is_none();
        let mut add = dot_offsets(&levels[..laid_out], &shifted[..laid_out], self.heads_down, lower_voice);
        add.resize(levels.len(), 0);
        add
    }

    /// The beam routine turns a chord for its beam and has the dots laid out again, but passes
    /// an end index that the chord layout has overwritten with the head count + 1, so a chord
    /// whose first work-table entry is `first_entry` gets only this many heads laid out.
    pub fn redot_after_turn(&mut self, first_entry: usize) {
        let heads = self.run_len();
        self.redotted = Some((heads + 2).saturating_sub(first_entry).clamp(2, heads.max(2)));
    }

    /// Accidental offsets (thousandths of P5) in item order.
    fn accidental_offsets(&self, ordered: &[&Head], shifted: &[bool]) -> Vec<i32> {
        let left: Vec<bool> = shifted.iter().map(|s| *s && self.heads_down).collect();
        positional_accidental_offsets(ordered, &left, self.heads_down)
    }
}

/// The accidental layout on heads in item order, `left` marking the heads with
/// P10 = 20: it works through them from the first for a down stem, from the last for an up
/// stem (from the top, when the heads are sorted).
fn positional_accidental_offsets(heads: &[&Head], left: &[bool], down: bool) -> Vec<i32> {
    let mut walk: Vec<ChordHead> = heads
        .iter()
        .zip(left)
        .map(|(h, l)| ChordHead { level: h.level, accidental: h.accidental.map_or(0, |a| a.code()), left_of_stem: *l })
        .collect();
    if !down {
        walk.reverse();
    }
    let mut offsets = accidental_offsets(&walk);
    if !down {
        offsets.reverse();
    }
    offsets
}

/// Which heads (in item order, stem head first) sit on the other side of the stem: a head
/// within a step of the previous head moves over unless that one moved.
fn second_shifts(levels: &[i32]) -> Vec<bool> {
    levels
        .iter()
        .scan(None::<(i32, bool)>, |previous, &level| {
            let shifted = matches!(*previous, Some((p, false)) if (level - p).abs() < 2);
            *previous = Some((level, shifted));
            Some(shifted)
        })
        .collect()
}

#[derive(Debug, Clone, PartialEq)]
pub(crate) enum Element {
    Note(Note),
    /// `cue`: P4 is stored 100 further from 0 (up from the middle).
    Rest { x: f32, rest: Rest, rhythm: Rhythm, cue: bool },
    /// `staves` negative for an invisible barline (P4).
    Bar { x: f32, staves: i32, style: BarStyle },
    /// `small`: a clef change within the line (P4 = 100).
    Clef { x: f32, clef: Clef, small: bool },
    Key { x: f32, key: KeySignature, clef: Clef },
    /// `quarters`: the duration a misread note token keeps in the spacing.
    Meter { x: f32, meter: Meter, quarters: f32 },
}

impl Element {
    /// Notes, chords and rests take a value in pass 2, and so does a misread meter.
    fn takes_rhythm(&self) -> bool {
        match self {
            Element::Note(_) | Element::Rest { .. } => true,
            Element::Meter { quarters, .. } => *quarters != 0.0,
            Element::Bar { .. } | Element::Clef { .. } | Element::Key { .. } => false,
        }
    }

    fn spacing_entries(&self) -> Vec<Entry> {
        match self {
            Element::Note(note) => note.spacing_entries(),
            Element::Rest { rhythm, .. } => vec![Entry::Rest { quarters: rhythm.quarters() }],
            Element::Bar { .. } => vec![Entry::Bar],
            Element::Clef { .. } => vec![Entry::Clef],
            Element::Key { key, .. } => vec![Entry::Key(*key)],
            Element::Meter { meter, quarters, .. } => vec![Entry::Meter(*meter, *quarters)],
        }
    }

    /// Takes the positions of this element's entries (one per chord member).
    fn place(&mut self, member_xs: &[f32]) {
        let first = member_xs.first().copied().unwrap_or(0.0);
        match self {
            Element::Note(note) => {
                note.x = first;
                note.stray_head = member_xs.iter().copied().enumerate().find(|(_, x)| *x != first);
            }
            Element::Rest { x, .. } | Element::Bar { x, .. } | Element::Clef { x, .. } | Element::Key { x, .. } | Element::Meter { x, .. } => {
                *x = first;
            }
        }
    }

    fn items(&self, staff: f32) -> Vec<Item> {
        match self {
            Element::Note(note) => note.items(staff),
            Element::Rest { x, rest, rhythm, cue } => vec![rest_item(*rest, *rhythm, *x, staff, *cue, uncentred(rest.kind))],
            Element::Bar { x, staves, style } => {
                let p5 = if *style == BarStyle::Invisible { 0 } else { style.code() };
                vec![item(&[14.0, staff, *x, *staves as f32, p5 as f32])]
            }
            Element::Clef { x, clef, small } => {
                let size = if *small { 100.0 } else { 0.0 };
                vec![item(&[3.0, staff, *x, size, clef.code() as f32])]
            }
            Element::Key { x, key, clef } => {
                let count = f32::from(key.count) * if key.sharps { 1.0 } else { -1.0 };
                if count == 0.0 {
                    return Vec::new();
                }
                let naturals = if key.naturals { 100.0 * count.signum() } else { 0.0 };
                vec![item(&[17.0, staff, *x, 0.0, count + naturals, clef.code() as f32])]
            }
            Element::Meter { x, meter, .. } => {
                let (top, bottom) = match meter {
                    Meter::Common => (99.0, 1.0),
                    Meter::Cut => (98.0, 1.0),
                    Meter::Fraction(top, bottom) => (*top as f32, *bottom as f32),
                };
                vec![item(&[18.0, staff, *x, 0.0, top, bottom])]
            }
        }
    }
}

fn rest_level(rest: Rest) -> f32 {
    match rest.shift {
        Some(Direction::Up) => 6.0,
        Some(Direction::Down) => -6.0,
        None => 0.0,
    }
}

/// A rest item; `centre` is P9 (see [`centre`] for the rests centred in their measure).
fn rest_item(rest: Rest, rhythm: Rhythm, x: f32, staff: f32, cue: bool, centre: f32) -> Item {
    let level = rest_level(rest);
    let level = if cue { level + SMALL_LEVEL as f32 * if level < 0.0 { -1.0 } else { 1.0 } } else { level };
    let kind = rest.kind;
    // P5: flags for short rests, 0 quarter, -1 half, -2 whole, -3 breve, -4 repeat sign.
    let symbol = match (kind, rhythm.head()) {
        (RestKind::Measures(n), _) if n >= BAR_REST_MEASURES => -5.0,
        (RestKind::Whole | RestKind::Measures(_), _) => -2.0,
        (RestKind::RepeatSign, _) => -4.0,
        (_, 0) => rhythm.tails() as f32,
        (_, head) => -head as f32,
    };
    let dots = match kind {
        RestKind::Invisible => -1.0,
        RestKind::Whole | RestKind::RepeatSign | RestKind::Measures(_) => 0.0,
        _ => f32::from(rhythm.dots()),
    };
    // P8: the number above a rest, -1 for a fermata.
    let above = match kind {
        RestKind::Fermata => -1.0,
        RestKind::Measures(n) => f32::from(n),
        _ => 0.0,
    };
    item(&[2.0, staff, x, level, symbol, dots, rhythm.quarters(), above, centre])
}

/// From this many measures on, `Rn` is a bar rest (P5 = -5).
const BAR_REST_MEASURES: u8 = 4;

/// Rests draw_rest centres in their measure; a bar rest is spread over it on every draw
/// and keeps P9 = -1.
fn is_centred(kind: RestKind) -> bool {
    match kind {
        RestKind::Measures(n) => n < BAR_REST_MEASURES,
        RestKind::Whole | RestKind::RepeatSign => true,
        _ => false,
    }
}

/// P9 of a rest that is not centred: -1 for a rest over several measures, else none.
fn uncentred(kind: RestKind) -> f32 {
    if matches!(kind, RestKind::Measures(_)) {
        -1.0
    } else {
        0.0
    }
}

/// The head of a chord the staff placement is applied to: the beam builder steps to the
/// chord's last entry, the slur's end-note lookup stays on the stem head.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub(crate) enum Reached {
    StemHead,
    LastHead,
}

/// A pass-1 event with the rhythm pass 2 gave it (chords and rests only).
#[derive(Debug, Clone, PartialEq)]
pub(crate) struct Timed<'a> {
    pub event: &'a Event,
    pub rhythm: Option<Rhythm>,
}

#[derive(Debug, Clone, PartialEq)]
pub(crate) struct Line {
    pub staff: f32,
    /// Size factor of the staff (STAFF_STEP / 25).
    pub size: f32,
    pub elements: Vec<Element>,
    /// Items created by passes 3-5 (marks, beams, slurs), in creation order.
    pub attachments: Vec<Item>,
    pub neighbours: Neighbours,
}

impl Line {
    pub fn new(timed: &[Timed], options: &Options) -> Self {
        let mut stems = StemMode::Ordinary;
        // Q+ turns automatic stems up, Q- goes back to the mode SU/SD/SO chose.
        let mut chosen = StemMode::Ordinary;
        let mut shift = StaffShift::Main;
        let mut clef = options.clef;
        let mut cue = false;
        let elements: Vec<Element> = timed
            .iter()
            .filter_map(|t| match (t.event, t.rhythm) {
                (Event::Chord(heads), Some(rhythm)) => {
                    let mut note = Note::new(0.0, heads.clone(), rhythm, stems, shift);
                    if cue {
                        note.set_cue();
                    }
                    Some(Element::Note(note))
                }
                (Event::Rest(rest), Some(rhythm)) => Some(Element::Rest { x: 0.0, rest: *rest, rhythm, cue }),
                (Event::Bar { staves, style }, _) => Some(Element::Bar { x: 0.0, staves: *staves, style: *style }),
                (Event::Clef(c), _) => {
                    clef = *c;
                    Some(Element::Clef { x: 0.0, clef, small: false })
                }
                (Event::Key(key, clef), _) => Some(Element::Key { x: 0.0, key: *key, clef: *clef }),
                (Event::Meter(meter), _) => Some(Element::Meter { x: 0.0, meter: *meter, quarters: 0.0 }),
                (Event::MisreadMeter(meter), rhythm) => {
                    Some(Element::Meter { x: 0.0, meter: *meter, quarters: rhythm.map_or(0.0, Rhythm::quarters) })
                }
                (Event::Stems(mode), _) => {
                    stems = *mode;
                    chosen = *mode;
                    None
                }
                (Event::Staff(s), _) => {
                    shift = *s;
                    None
                }
                (Event::Cue(true), _) => {
                    if stems == StemMode::Ordinary {
                        stems = StemMode::Up;
                    }
                    cue = true;
                    None
                }
                (Event::Cue(false), _) => {
                    stems = chosen;
                    cue = false;
                    None
                }
                (Event::Chord(_) | Event::Rest(_), None) => None,
            })
            .collect();
        let mut line = Line {
            staff: f32::from(options.staff),
            size: options.size,
            elements,
            attachments: Vec::new(),
            neighbours: options.neighbours,
        };
        line.mark_clef_changes();
        line.space(options.begin, options.end);
        line
    }

    /// A clef is drawn small unless it opens the line, or is the line's first
    /// clef and stands right after a barline.
    fn mark_clef_changes(&mut self) {
        let mut seen = false;
        let mut after_bar = false;
        for (i, element) in self.elements.iter_mut().enumerate() {
            if let Element::Clef { small, .. } = element {
                *small = i > 0 && (seen || !after_bar);
                seen = true;
            }
            after_bar = matches!(element, Element::Bar { .. });
        }
    }

    /// Sets every element's P3 from the engine's spacing of the work-table entries.
    fn space(&mut self, begin: f32, end: f32) {
        let entries: Vec<Vec<Entry>> = self.elements.iter().map(Element::spacing_entries).collect();
        let flat: Vec<Entry> = entries.iter().flatten().copied().collect();
        let xs = positions(&flat, begin, end, self.size);
        let mut next = xs.into_iter();
        for (element, count) in self.elements.iter_mut().zip(entries.iter().map(Vec::len)) {
            let member_xs: Vec<f32> = next.by_ref().take(count).collect();
            element.place(&member_xs);
        }
    }

    /// Grace chords as the refit's pass 2 leaves them.
    pub fn lay_out_grace_chords_for_refit(&mut self) {
        self.notes_mut().for_each(Note::lay_out_grace_chord_for_refit);
    }

    /// Puts the notes at the given positions, one per note: the refit keeps every P3.
    pub fn place_notes(&mut self, xs: &[f32]) {
        for (note, &x) in self.notes_mut().zip(xs) {
            note.x = x;
            note.stray_head = None;
        }
    }

    /// The notes and chords, numbered from 1 in passes 3-5 (rests are not counted).
    pub fn notes(&self) -> impl Iterator<Item = &Note> {
        self.elements.iter().filter_map(|e| match e {
            Element::Note(note) => Some(note),
            _ => None,
        })
    }

    pub fn notes_mut(&mut self) -> impl Iterator<Item = &mut Note> {
        self.elements.iter_mut().filter_map(|e| match e {
            Element::Note(note) => Some(note),
            _ => None,
        })
    }

    pub fn note_count(&self) -> usize {
        self.notes().count()
    }

    /// Note `number` (1-based), if it exists.
    pub fn note(&self, number: usize) -> Option<&Note> {
        number.checked_sub(1).and_then(|i| self.notes().nth(i))
    }

    pub fn note_mut(&mut self, number: usize) -> Option<&mut Note> {
        number.checked_sub(1).and_then(|i| self.notes_mut().nth(i))
    }

    /// 1-based work-table index of the first entry of note `number`.
    pub fn first_entry(&self, number: usize) -> Option<usize> {
        let mut notes = 0;
        let mut entries = 0;
        self.elements.iter().find_map(|element| {
            if let Element::Note(note) = element {
                notes += 1;
                if notes == number {
                    return Some(entries + 1);
                }
                entries += note.heads.len();
            } else {
                entries += 1;
            }
            None
        })
    }

    /// Scale steps a staff placement adds to a note's level in beams and slurs;
    /// None for a staff that cannot exist.
    fn staff_steps(&self, shift: StaffShift) -> Option<f32> {
        match shift {
            StaffShift::Main => Some(0.0),
            StaffShift::Above => self.neighbours.above,
            StaffShift::Below => self.neighbours.below,
        }
    }

    /// The staff placement on one head of note `number` as a beam or slur reaches it: the
    /// steps the note's placement adds to its level. A placement on a staff that cannot
    /// exist counts as none, and that head's P12 is dropped.
    pub fn placement_steps(&mut self, number: usize, head: Reached) -> f32 {
        let Some(shift) = self.note(number).map(|n| n.shift) else { return 0.0 };
        self.staff_steps(shift).unwrap_or_else(|| {
            if let Some(note) = self.note_mut(number) {
                note.placement_dropped = Some(match head {
                    Reached::StemHead => 0,
                    Reached::LastHead => note.heads.len() - 1,
                });
            }
            0.0
        })
    }

    /// The engine's work table as passes 4 and 5 read it: one entry per chord member.
    pub fn work_entries(&self) -> Vec<WorkEntry> {
        let mut number = 0;
        self.elements
            .iter()
            .flat_map(|element| match element {
                Element::Note(note) => {
                    number += 1;
                    note.work_entries(number, self.staff_steps(note.shift).unwrap_or(0.0))
                }
                Element::Rest { x, rest, .. } => vec![WorkEntry::other(2, *x, rest_level(*rest) as i32)],
                Element::Bar { x, .. } => vec![WorkEntry::other(14, *x, 0)],
                Element::Clef { x, .. } => vec![WorkEntry::other(3, *x, 0)],
                Element::Key { x, .. } => vec![WorkEntry::other(17, *x, 0)],
                Element::Meter { x, .. } => vec![WorkEntry::other(18, *x, 0)],
            })
            .collect()
    }

    /// Takes over the marks of the notes from a work table (the slur pass can move them).
    pub fn take_marks(&mut self, work: &[WorkEntry]) {
        let marks = work.iter().filter(|e| e.note.is_some()).map(|e| e.mark);
        for (note, mark) in self.notes_mut().zip(marks) {
            note.mark = mark;
        }
    }

    /// Where each element's items lie in [`Line::items`], with its numbers in passes 2-5.
    pub fn outline(&self) -> Vec<Outline> {
        let mut start = 0;
        let mut slots = 0;
        let mut notes = 0;
        self.elements
            .iter()
            .map(|element| {
                let items = start..start + element.items(self.staff).len();
                start = items.end;
                let slot = element.takes_rhythm().then(|| {
                    slots += 1;
                    slots
                });
                let note = matches!(element, Element::Note(_)).then(|| {
                    notes += 1;
                    notes
                });
                Outline { items, slot, note }
            })
            .collect()
    }

    pub fn items(&self) -> Vec<Item> {
        let bars: Vec<f32> = self.elements.iter().filter_map(|e| if let Element::Bar { x, .. } = e { Some(*x) } else { None }).collect();
        self.elements
            .iter()
            .flat_map(|e| match e {
                Element::Rest { x, rest, rhythm, cue } if is_centred(rest.kind) => {
                    vec![rest_item(*rest, *rhythm, *x, self.staff, *cue, centre(rest.kind, *x, self.size, &bars))]
                }
                other => other.items(self.staff),
            })
            .chain(self.attachments.iter().cloned())
            .collect()
    }
}

/// P9 of a rest centred in its measure. The input stores -1, and draw_rest
/// replaces it with the middle of the measure the first time the rest is drawn, which is
/// what the saved item holds; -1 stays when no barline follows.
fn centre(kind: RestKind, x: f32, size: f32, bars: &[f32]) -> f32 {
    let step = 25.0 * size;
    let right = bars.iter().copied().filter(|b| *b > x).fold(9999.0f32, f32::min);
    if right == 9999.0 {
        return -1.0;
    }
    let mut left = bars.iter().copied().filter(|b| *b < x).fold(-9999.0f32, f32::max);
    if x - left > size * 7.0 {
        left = x - size * 4.5;
    }
    let less = if kind == RestKind::RepeatSign { 0.137f32 } else { 0.056f32 };
    let measure = right - left;
    ((measure as f64 * 0.5 + left as f64) - step as f64 * less as f64) as f32
}
