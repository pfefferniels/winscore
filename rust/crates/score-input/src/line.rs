//! One line of input as the engine holds it between passes: notes, rests and the other
//! elements with their positions, plus the items passes 3-5 attach to them.

use score_format::{Item, Word};

use crate::events::{Event, Head};
use crate::notes::{Clef, KeySignature, Meter, RestKind, StaffShift, StemMode};
use crate::rhythm::Rhythm;
use crate::spacing::{positions, Slot};

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
const GRACE_SLASH: f32 = 101.0;

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
}

impl Note {
    fn new(x: f32, heads: Vec<Head>, rhythm: Rhythm, stems: StemMode, shift: StaffShift) -> Self {
        let mut note = Note { x, heads, rhythm, down: false, extension: 0.0, tails: rhythm.tails(), mark: 0.0, shift };
        let down = match stems {
            StemMode::Up => false,
            StemMode::Down => true,
            StemMode::Ordinary => note.lowest() + note.highest() >= 2 * MIDDLE_LINE,
        };
        note.set_stem(down);
        note
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
        self.extension = if self.is_grace() { GRACE_SLASH } else { (high - low).max(to_middle).max(0) as f32 };
    }

    fn items(&self, staff: f32) -> Vec<Item> {
        let ordered: Vec<&Head> = if self.down { self.heads.iter().rev().collect() } else { self.heads.iter().collect() };
        let levels: Vec<i32> = ordered.iter().map(|h| h.level).collect();
        let shifts = second_shifts(&levels, self.down);
        let dots = 10 * i32::from(self.rhythm.dots());
        let shift = match self.shift {
            StaffShift::Main => 0.0,
            StaffShift::Above => 1.0,
            StaffShift::Below => 2.0,
        };
        ordered
            .iter()
            .zip(shifts)
            .enumerate()
            .map(|(i, (head, offset))| {
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
                item(&[
                    1.0,
                    staff,
                    self.x,
                    level as f32,
                    (stem + accidental) as f32,
                    self.rhythm.head() as f32,
                    self.rhythm.quarters(),
                    extension,
                    (dots + tails) as f32,
                    offset,
                    mark,
                    shift,
                ])
            })
            .collect()
    }
}

/// P10 of each head (in the order given, stem end first): a head a second away from the
/// previous unshifted head moves to the other side of the stem.
fn second_shifts(levels: &[i32], down: bool) -> Vec<f32> {
    let shift = if down { SHIFT_LEFT } else { SHIFT_RIGHT };
    levels
        .iter()
        .scan(None::<(i32, bool)>, |previous, &level| {
            let shifted = matches!(*previous, Some((p, false)) if (level - p).abs() == 1);
            *previous = Some((level, shifted));
            Some(if shifted { shift } else { 0.0 })
        })
        .collect()
}

#[derive(Debug, Clone, PartialEq)]
pub(crate) enum Element {
    Note(Note),
    Rest { x: f32, kind: RestKind, rhythm: Rhythm },
    Bar { x: f32, staves: u8 },
    Clef { x: f32, clef: Clef, first: bool },
    Key { x: f32, key: KeySignature },
    Meter { x: f32, meter: Meter },
}

impl Element {
    fn items(&self, staff: f32) -> Vec<Item> {
        match self {
            Element::Note(note) => note.items(staff),
            Element::Rest { x, kind, rhythm } => vec![rest_item(*kind, *rhythm, *x, staff)],
            Element::Bar { x, staves } => vec![item(&[14.0, staff, *x, f32::from(*staves)])],
            Element::Clef { x, clef, first } => {
                let small = if *first { 0.0 } else { 100.0 };
                vec![item(&[3.0, staff, *x, small, clef.code() as f32])]
            }
            Element::Key { x, key } => {
                let count = f32::from(key.count) * if key.sharps { 1.0 } else { -1.0 };
                let naturals = if key.naturals { 100.0 * count.signum() } else { 0.0 };
                vec![item(&[17.0, staff, *x, 0.0, count + naturals])]
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

fn rest_item(kind: RestKind, rhythm: Rhythm, x: f32, staff: f32) -> Item {
    let level = match kind {
        RestKind::Up => 6.0,
        RestKind::Down => -6.0,
        _ => 0.0,
    };
    // P5: flags for short rests, 0 quarter, -1 half, -2 whole, -3 breve.
    let symbol = match (kind, rhythm.head()) {
        (RestKind::Whole, _) => -2.0,
        (_, 0) => rhythm.tails() as f32,
        (_, head) => -head as f32,
    };
    let dots = if kind == RestKind::Invisible { -1.0 } else { f32::from(rhythm.dots()) };
    let centering = if kind == RestKind::Whole { -1.0 } else { 0.0 };
    item(&[2.0, staff, x, level, symbol, dots, rhythm.quarters(), 0.0, centering])
}

/// A pass-1 event with the rhythm pass 2 gave it (chords and rests only).
#[derive(Debug, Clone, PartialEq)]
pub(crate) struct Timed<'a> {
    pub event: &'a Event,
    pub rhythm: Option<Rhythm>,
}

impl Timed<'_> {
    fn slot(&self, first_clef: bool) -> Slot {
        match (self.event, self.rhythm) {
            (_, Some(Rhythm::Grace)) => Slot::Grace,
            (_, Some(rhythm)) => Slot::Timed(rhythm.quarters()),
            (Event::Bar { .. }, _) => Slot::Bar,
            (Event::Clef(_), _) => Slot::Clef { first: first_clef },
            (Event::Key(key), _) => Slot::Key(*key),
            (Event::Meter(meter), _) => Slot::Meter(*meter),
            _ => Slot::None,
        }
    }
}

#[derive(Debug, Clone, PartialEq)]
pub(crate) struct Line {
    pub staff: f32,
    pub elements: Vec<Element>,
    /// Items created by passes 3-5 (marks, beams, slurs), in creation order.
    pub attachments: Vec<Item>,
}

impl Line {
    pub fn new(timed: &[Timed], staff: u8, begin: f32, end: f32) -> Self {
        let leading_clefs = timed.iter().take_while(|t| matches!(t.event, Event::Clef(_))).count();
        let slots: Vec<Slot> = timed.iter().enumerate().map(|(i, t)| t.slot(i < leading_clefs)).collect();
        let xs = positions(&slots, begin, end);
        let mut stems = StemMode::Ordinary;
        let mut shift = StaffShift::Main;
        let elements = timed
            .iter()
            .zip(xs)
            .enumerate()
            .filter_map(|(i, (t, x))| match (t.event, t.rhythm) {
                (Event::Chord(heads), Some(rhythm)) => Some(Element::Note(Note::new(x, heads.clone(), rhythm, stems, shift))),
                (Event::Rest(kind), Some(rhythm)) => Some(Element::Rest { x, kind: *kind, rhythm }),
                (Event::Bar { staves }, _) => Some(Element::Bar { x, staves: *staves }),
                (Event::Clef(clef), _) => Some(Element::Clef { x, clef: *clef, first: i < leading_clefs }),
                (Event::Key(key), _) => Some(Element::Key { x, key: *key }),
                (Event::Meter(meter), _) => Some(Element::Meter { x, meter: *meter }),
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
        Line { staff: f32::from(staff), elements, attachments: Vec::new() }
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

    pub fn items(&self) -> Vec<Item> {
        self.elements.iter().flat_map(|e| e.items(self.staff)).chain(self.attachments.iter().cloned()).collect()
    }
}
