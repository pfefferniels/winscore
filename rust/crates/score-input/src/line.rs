//! One line of input as the engine holds it between passes: notes, rests and the other
//! elements with their positions, plus the items passes 3-5 attach to them.

use score_format::{Item, Word};

use crate::chords::{accidental_offsets, dot_offsets, ChordHead};
use crate::events::{Event, Head};
use crate::notes::{Clef, KeySignature, Meter, RestKind, StaffShift, StemMode};
use crate::rhythm::Rhythm;
use crate::slurs::WorkEntry;
use crate::spacing::{positions, Entry, GRACE_DURATION};
use crate::Options;

/// Middle staff line: notes from here up take a down stem, and a stem reaches at least here.
pub(crate) const MIDDLE_LINE: i32 = 7;
/// A normal stem is one octave long.
pub(crate) const STEM: i32 = 7;
const STEM_UP: i32 = 10;
const STEM_DOWN: i32 = 20;
/// P10 of a chord note moved one head width to the right (stem up) or left (stem down).
const SHIFT_RIGHT: f32 = 10.0;
const SHIFT_LEFT: f32 = 20.0;
const GRACE_LEVEL: i32 = 100;
/// P7 of the further heads of a grace chord (the stem head has 65).
const GRACE_CHORD_MEMBER: f32 = 64.0;

/// Builds an item; trailing zero parameters are dropped as the engine does (0x5253FD).
pub(crate) fn item(params: &[f32]) -> Item {
    let used = params.iter().rposition(|p| *p != 0.0).map_or(0, |i| i + 1);
    Item::new(params[..used].iter().copied().map(Word::from_f32).collect())
}

/// A note or chord.
#[derive(Debug, Clone, PartialEq)]
pub(crate) struct Note {
    pub x: f32,
    /// Sorted from the lowest level up.
    pub heads: Vec<Head>,
    pub rhythm: Rhythm,
    pub down: bool,
    /// P8 of the head that carries the stem.
    pub extension: f32,
    /// Flags drawn on the stem; removed when the note is beamed.
    pub tails: i32,
    /// P11 of the head that carries the stem (marks from pass 3).
    pub mark: f32,
    pub shift: StaffShift,
    /// A head left at another x than the chord (level, x): the minimum-gap pass never moves
    /// the last entry of the line, which can be the last member of a chord.
    pub stray_head: Option<(i32, f32)>,
}

impl Note {
    fn new(x: f32, heads: Vec<Head>, rhythm: Rhythm, stems: StemMode, shift: StaffShift) -> Self {
        let mut note =
            Note { x, heads, rhythm, down: false, extension: 0.0, tails: rhythm.tails(), mark: 0.0, shift, stray_head: None };
        let down = match stems {
            StemMode::Up => false,
            StemMode::Down => true,
            StemMode::Ordinary => note.lowest() + note.highest() >= 2 * MIDDLE_LINE,
        };
        note.set_stem(down);
        if note.is_grace() {
            note.extension = note.grace_extension(down);
            note.down = false;
        }
        note
    }

    /// P8 of a grace note (0x51CF40): 100 (the slash) plus a stem length that grows for notes
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
        length + GRACE_LEVEL as f32
    }

    pub fn lowest(&self) -> i32 {
        self.heads.first().map_or(0, |h| h.level)
    }

    pub fn highest(&self) -> i32 {
        self.heads.last().map_or(0, |h| h.level)
    }

    /// The level of the head the stem starts from.
    pub fn stem_level(&self) -> i32 {
        if self.down {
            self.highest()
        } else {
            self.lowest()
        }
    }

    pub fn is_grace(&self) -> bool {
        self.rhythm == Rhythm::Grace
    }

    /// Sets the stem direction and the P8 that spans the chord and reaches the middle line.
    pub fn set_stem(&mut self, down: bool) {
        self.down = down;
        let (low, high) = (self.lowest(), self.highest());
        let to_middle = if down { high - STEM - MIDDLE_LINE } else { MIDDLE_LINE - STEM - low };
        self.extension = (high - low).max(to_middle).max(0) as f32;
    }

    /// The heads in item order: the head carrying the stem first.
    pub fn ordered_heads(&self) -> Vec<&Head> {
        if self.down {
            self.heads.iter().rev().collect()
        } else {
            self.heads.iter().collect()
        }
    }

    fn work_entries(&self, number: usize) -> Vec<WorkEntry> {
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
                    extension: if stem_head { self.extension % 100.0 } else { 0.0 },
                    dotted: stem_head && self.rhythm.dots() > 0,
                    mark: if stem_head { self.mark } else { 0.0 },
                    grace: self.is_grace(),
                    note: stem_head.then_some(number),
                }
            })
            .collect()
    }

    fn spacing_entries(&self) -> Vec<Entry> {
        let quarters = if self.is_grace() { GRACE_DURATION } else { self.rhythm.quarters() };
        self.ordered_heads()
            .iter()
            .enumerate()
            .map(|(i, head)| Entry::Note { quarters, accidental: head.accidental.is_some(), first: i == 0 })
            .collect()
    }

    fn items(&self, staff: f32) -> Vec<Item> {
        let ordered = self.ordered_heads();
        let levels: Vec<i32> = ordered.iter().map(|h| h.level).collect();
        let shifted = second_shifts(&levels);
        let accidental_offsets = self.accidental_offsets(&ordered, &shifted);
        let dot_offsets = if self.rhythm.dots() > 0 { dot_offsets(&levels, &shifted, self.down) } else { vec![0; levels.len()] };
        let dots = 10 * i32::from(self.rhythm.dots());
        let side = if self.down { SHIFT_LEFT } else { SHIFT_RIGHT };
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
                let accidental = head.accidental.map_or(0, |a| a.code());
                let stem = match (stem_head, self.down) {
                    (false, _) => 0,
                    (true, true) => STEM_DOWN,
                    (true, false) => STEM_UP,
                };
                let level = match (self.is_grace(), head.level < 0) {
                    (false, _) => head.level,
                    (true, false) => head.level + GRACE_LEVEL,
                    (true, true) => head.level - GRACE_LEVEL,
                };
                let (extension, tails, mark) =
                    if stem_head { (self.extension, self.tails, self.mark) } else { (0.0, 0, 0.0) };
                let x = match self.stray_head {
                    Some((stray, x)) if stray == head.level => x,
                    _ => self.x,
                };
                let p5 = accidental_offsets[i] as f32 / 1000.0 + (stem + accidental) as f32;
                item(&[
                    1.0,
                    staff,
                    x,
                    level as f32,
                    p5,
                    self.rhythm.head() as f32,
                    if self.is_grace() && !stem_head { GRACE_CHORD_MEMBER } else { self.rhythm.quarters() },
                    extension,
                    (dots + tails + dot_offsets[i]) as f32,
                    if shifted[i] { side } else { 0.0 },
                    mark,
                    staff_shift,
                ])
            })
            .collect()
    }

    /// Accidental offsets (thousandths of P5) in item order; the layout works from the top.
    fn accidental_offsets(&self, ordered: &[&Head], shifted: &[bool]) -> Vec<i32> {
        let mut top_down: Vec<ChordHead> = ordered
            .iter()
            .zip(shifted)
            .map(|(h, s)| ChordHead {
                level: h.level,
                accidental: h.accidental.map_or(0, |a| a.code()),
                left_of_stem: *s && self.down,
            })
            .collect();
        if !self.down {
            top_down.reverse();
        }
        let mut offsets = accidental_offsets(&top_down);
        if !self.down {
            offsets.reverse();
        }
        offsets
    }
}

/// Which heads (in item order, stem head first) sit on the other side of the stem: a head
/// within a step of the previous head moves over unless that one moved (0x4EE442).
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
    Rest { x: f32, kind: RestKind, rhythm: Rhythm },
    Bar { x: f32, staves: u8 },
    /// `small`: a clef change within the line (P4 = 100).
    Clef { x: f32, clef: Clef, small: bool },
    Key { x: f32, key: KeySignature, clef: Clef },
    Meter { x: f32, meter: Meter },
}

impl Element {
    fn spacing_entries(&self) -> Vec<Entry> {
        match self {
            Element::Note(note) => note.spacing_entries(),
            Element::Rest { rhythm, .. } => vec![Entry::Rest { quarters: rhythm.quarters() }],
            Element::Bar { .. } => vec![Entry::Bar],
            Element::Clef { .. } => vec![Entry::Clef],
            Element::Key { key, .. } => vec![Entry::Key(*key)],
            Element::Meter { meter, .. } => vec![Entry::Meter(*meter)],
        }
    }

    /// Takes the positions of this element's entries (one per chord member).
    fn place(&mut self, member_xs: &[f32]) {
        let first = member_xs.first().copied().unwrap_or(0.0);
        match self {
            Element::Note(note) => {
                note.x = first;
                let ordered_levels: Vec<i32> = note.ordered_heads().iter().map(|h| h.level).collect();
                note.stray_head = ordered_levels.iter().zip(member_xs).find(|(_, x)| **x != first).map(|(l, x)| (*l, *x));
            }
            Element::Rest { x, .. } | Element::Bar { x, .. } | Element::Clef { x, .. } | Element::Key { x, .. } | Element::Meter { x, .. } => {
                *x = first;
            }
        }
    }

    fn items(&self, staff: f32) -> Vec<Item> {
        match self {
            Element::Note(note) => note.items(staff),
            Element::Rest { x, kind, rhythm } => vec![rest_item(*kind, *rhythm, *x, staff)],
            Element::Bar { x, staves } => vec![item(&[14.0, staff, *x, f32::from(*staves)])],
            Element::Clef { x, clef, small } => {
                let size = if *small { 100.0 } else { 0.0 };
                vec![item(&[3.0, staff, *x, size, clef.code() as f32])]
            }
            Element::Key { x, key, clef } => {
                let count = f32::from(key.count) * if key.sharps { 1.0 } else { -1.0 };
                let naturals = if key.naturals { 100.0 * count.signum() } else { 0.0 };
                vec![item(&[17.0, staff, *x, 0.0, count + naturals, clef.code() as f32])]
            }
            Element::Meter { x, meter } => {
                let (top, bottom) = match meter {
                    Meter::Common => (99.0, 1.0),
                    Meter::Cut => (98.0, 1.0),
                    Meter::Fraction(top, bottom) => (f32::from(*top), f32::from(*bottom)),
                };
                vec![item(&[18.0, staff, *x, 0.0, top, bottom])]
            }
        }
    }
}

fn rest_level(kind: RestKind) -> f32 {
    match kind {
        RestKind::Up => 6.0,
        RestKind::Down => -6.0,
        _ => 0.0,
    }
}

fn rest_item(kind: RestKind, rhythm: Rhythm, x: f32, staff: f32) -> Item {
    let level = rest_level(kind);
    // P5: flags for short rests, 0 quarter, -1 half, -2 whole, -3 breve.
    let symbol = match (kind, rhythm.head()) {
        (RestKind::Whole, _) => -2.0,
        (_, 0) => rhythm.tails() as f32,
        (_, head) => -head as f32,
    };
    let dots = match kind {
        RestKind::Invisible => -1.0,
        RestKind::Whole => 0.0,
        _ => f32::from(rhythm.dots()),
    };
    // -1 asks for centring in the measure; the engine's draw_rest (0x519C38) replaces it
    // with the computed position when the rest is first drawn.
    let centering = if kind == RestKind::Whole { -1.0 } else { 0.0 };
    item(&[2.0, staff, x, level, symbol, dots, rhythm.quarters(), 0.0, centering])
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
}

impl Line {
    pub fn new(timed: &[Timed], options: &Options) -> Self {
        let mut stems = StemMode::Ordinary;
        let mut shift = StaffShift::Main;
        let mut clef = options.clef;
        let elements: Vec<Element> = timed
            .iter()
            .filter_map(|t| match (t.event, t.rhythm) {
                (Event::Chord(heads), Some(rhythm)) => Some(Element::Note(Note::new(0.0, heads.clone(), rhythm, stems, shift))),
                (Event::Rest(kind), Some(rhythm)) => Some(Element::Rest { x: 0.0, kind: *kind, rhythm }),
                (Event::Bar { staves }, _) => Some(Element::Bar { x: 0.0, staves: *staves }),
                (Event::Clef(c), _) => {
                    clef = *c;
                    Some(Element::Clef { x: 0.0, clef, small: false })
                }
                (Event::Key(key), _) => Some(Element::Key { x: 0.0, key: *key, clef }),
                (Event::Meter(meter), _) => Some(Element::Meter { x: 0.0, meter: *meter }),
                (Event::Stems(mode), _) => {
                    stems = *mode;
                    None
                }
                (Event::Staff(s), _) => {
                    shift = *s;
                    None
                }
                (Event::Chord(_) | Event::Rest(_), None) => None,
            })
            .collect();
        let mut line = Line { staff: f32::from(options.staff), size: options.size, elements, attachments: Vec::new() };
        line.mark_clef_changes();
        line.space(options.begin, options.end);
        line
    }

    /// 0x4ECDF8: a clef is drawn small unless it opens the line, or is the line's first
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

    /// The engine's work table as passes 4 and 5 read it: one entry per chord member.
    pub fn work_entries(&self) -> Vec<WorkEntry> {
        let mut number = 0;
        self.elements
            .iter()
            .flat_map(|element| match element {
                Element::Note(note) => {
                    number += 1;
                    note.work_entries(number)
                }
                Element::Rest { x, kind, .. } => vec![WorkEntry::other(2, *x, rest_level(*kind) as i32)],
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

    pub fn items(&self) -> Vec<Item> {
        let bars: Vec<f32> = self.elements.iter().filter_map(|e| if let Element::Bar { x, .. } = e { Some(*x) } else { None }).collect();
        self.elements
            .iter()
            .flat_map(|e| match e {
                Element::Rest { x, kind: RestKind::Whole, rhythm } => vec![whole_rest_item(*rhythm, *x, self.staff, self.size, &bars)],
                other => other.items(self.staff),
            })
            .chain(self.attachments.iter().cloned())
            .collect()
    }
}

/// A whole-measure rest; draw_rest (0x519C38) centres it in its measure the first time it is
/// drawn and stores the position in P9, which is what the saved item holds.
fn whole_rest_item(rhythm: Rhythm, x: f32, staff: f32, size: f32, bars: &[f32]) -> Item {
    let step = 25.0 * size;
    let right = bars.iter().copied().filter(|b| *b > x).fold(9999.0f32, f32::min);
    let mut left = bars.iter().copied().filter(|b| *b < x).fold(-9999.0f32, f32::max);
    let centre = if right == 9999.0 {
        -1.0
    } else {
        if x - left > size * 7.0 {
            left = x - size * 4.5;
        }
        let measure = right - left;
        ((measure as f64 * 0.5 + left as f64) - step as f64 * 0.056f32 as f64) as f32
    };
    item(&[2.0, staff, x, 0.0, -2.0, 0.0, rhythm.quarters(), 0.0, centre])
}
