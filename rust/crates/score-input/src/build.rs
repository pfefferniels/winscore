//! Turning the resolved events of pass 1 and the rhythms of pass 2 into items.

use score_format::{Item, Word};

use crate::events::{Event, Head};
use crate::notes::{Clef, Meter, RestKind, StaffShift, StemMode};
use crate::rhythm::Rhythm;
use crate::spacing::{positions, Slot};

/// Middle staff line: notes from here up take a down stem, and a stem reaches at least here.
const MIDDLE_LINE: i32 = 7;
/// A normal stem is one octave long.
const STEM: i32 = 7;
const STEM_UP: i32 = 10;
const STEM_DOWN: i32 = 20;
/// P10 of a chord note moved one head width to the right (stem up) or left (stem down).
const SHIFT_RIGHT: f32 = 10.0;
const SHIFT_LEFT: f32 = 20.0;
const GRACE_LEVEL: i32 = 100;
const GRACE_SLASH: f32 = 101.0;

/// A rhythmic event with the rhythm pass 2 gave it.
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

/// Builds item parameter lists; trailing zero parameters are dropped as the engine does.
fn item(params: &[f32]) -> Item {
    let used = params.iter().rposition(|p| *p != 0.0).map_or(0, |i| i + 1);
    Item::new(params[..used].iter().copied().map(Word::from_f32).collect())
}

#[derive(Debug, Clone, Copy)]
struct Voice {
    staff: f32,
    stems: StemMode,
    shift: StaffShift,
}

impl Voice {
    fn stem_down(&self, heads: &[Head]) -> bool {
        match self.stems {
            StemMode::Up => false,
            StemMode::Down => true,
            StemMode::Ordinary => {
                let (low, high) = extremes(heads);
                low + high >= 2 * MIDDLE_LINE
            }
        }
    }

    fn shift_param(&self) -> f32 {
        match self.shift {
            StaffShift::Main => 0.0,
            StaffShift::Above => 1.0,
            StaffShift::Below => 2.0,
        }
    }
}

fn extremes(heads: &[Head]) -> (i32, i32) {
    let low = heads.first().map_or(0, |h| h.level);
    let high = heads.last().map_or(0, |h| h.level);
    (low, high)
}

/// P8: how much longer than an octave the stem must be to span the chord and reach the middle line.
fn stem_extension(heads: &[Head], down: bool) -> i32 {
    let (low, high) = extremes(heads);
    let to_middle = if down { high - STEM - MIDDLE_LINE } else { MIDDLE_LINE - STEM - low };
    (high - low).max(to_middle).max(0)
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

fn chord_items(heads: &[Head], rhythm: Rhythm, x: f32, voice: &Voice) -> Vec<Item> {
    let down = voice.stem_down(heads);
    let ordered: Vec<&Head> = if down { heads.iter().rev().collect() } else { heads.iter().collect() };
    let levels: Vec<i32> = ordered.iter().map(|h| h.level).collect();
    let shifts = second_shifts(&levels, down);
    let grace = rhythm == Rhythm::Grace;
    let dots = 10 * i32::from(rhythm.dots());
    ordered
        .iter()
        .zip(shifts)
        .enumerate()
        .map(|(i, (head, shift))| {
            let stem_head = i == 0;
            let accidental = head.accidental.map_or(0, |a| a.code());
            let stem = if !stem_head {
                0
            } else if down {
                STEM_DOWN
            } else {
                STEM_UP
            };
            let level = match (grace, head.level < 0) {
                (false, _) => head.level,
                (true, false) => head.level + GRACE_LEVEL,
                (true, true) => head.level - GRACE_LEVEL,
            };
            let extension = if !stem_head {
                0.0
            } else if grace {
                GRACE_SLASH
            } else {
                stem_extension(heads, down) as f32
            };
            let tails = if stem_head { rhythm.tails() } else { 0 };
            item(&[
                1.0,
                voice.staff,
                x,
                level as f32,
                (stem + accidental) as f32,
                rhythm.head() as f32,
                rhythm.quarters(),
                extension,
                (dots + tails) as f32,
                shift,
                0.0,
                voice.shift_param(),
            ])
        })
        .collect()
}

fn rest_item(kind: RestKind, rhythm: Rhythm, x: f32, voice: &Voice) -> Item {
    let level = match kind {
        RestKind::Up => 6.0,
        RestKind::Down => -6.0,
        _ => 0.0,
    };
    let symbol = match kind {
        RestKind::Whole => -2.0,
        _ => rest_symbol(rhythm),
    };
    let dots = if kind == RestKind::Invisible { -1.0 } else { f32::from(rhythm.dots()) };
    let centering = if kind == RestKind::Whole { -1.0 } else { 0.0 };
    item(&[2.0, voice.staff, x, level, symbol, dots, rhythm.quarters(), 0.0, centering])
}

/// P5 of a rest: number of flags for short rests, 0 quarter, -1 half, -2 whole, -3 breve.
fn rest_symbol(rhythm: Rhythm) -> f32 {
    match rhythm.head() {
        0 => rhythm.tails() as f32,
        head => -head as f32,
    }
}

fn clef_item(clef: Clef, first: bool, x: f32, voice: &Voice) -> Item {
    let small = if first { 0.0 } else { 100.0 };
    item(&[3.0, voice.staff, x, small, clef.code() as f32])
}

fn meter_item(meter: Meter, x: f32, voice: &Voice) -> Item {
    let (top, bottom) = match meter {
        Meter::Common => (99.0, 1.0),
        Meter::Cut => (98.0, 1.0),
        Meter::Fraction(top, bottom) => (f32::from(top), f32::from(bottom)),
    };
    item(&[18.0, voice.staff, x, 0.0, top, bottom])
}

/// The items of one input line, in the order the engine writes them.
pub(crate) fn line_items(timed: &[Timed], staff: u8, begin: f32, end: f32) -> Vec<Item> {
    let first_clef_index = timed.iter().position(|t| !matches!(t.event, Event::Clef(_)));
    let slots: Vec<Slot> =
        timed.iter().enumerate().map(|(i, t)| t.slot(first_clef_index.is_none_or(|f| i < f))).collect();
    let xs = positions(&slots, begin, end);
    let mut voice = Voice { staff: f32::from(staff), stems: StemMode::Ordinary, shift: StaffShift::Main };
    timed
        .iter()
        .zip(xs)
        .enumerate()
        .flat_map(|(i, (t, x))| match (t.event, t.rhythm) {
            (Event::Chord(heads), Some(rhythm)) => chord_items(heads, rhythm, x, &voice),
            (Event::Rest(kind), Some(rhythm)) => vec![rest_item(*kind, rhythm, x, &voice)],
            (Event::Bar { staves }, _) => vec![item(&[14.0, voice.staff, x, f32::from(*staves)])],
            (Event::Clef(clef), _) => vec![clef_item(*clef, matches!(slots[i], Slot::Clef { first: true }), x, &voice)],
            (Event::Key(key), _) => {
                let count = f32::from(key.count) * if key.sharps { 1.0 } else { -1.0 };
                let naturals = if key.naturals { 100.0 * count.signum() } else { 0.0 };
                vec![item(&[17.0, voice.staff, x, 0.0, count + naturals])]
            }
            (Event::Meter(meter), _) => vec![meter_item(*meter, x, &voice)],
            (Event::Stems(mode), _) => {
                voice.stems = *mode;
                Vec::new()
            }
            (Event::Staff(shift), _) => {
                voice.shift = *shift;
                Vec::new()
            }
            (Event::Chord(_) | Event::Rest(_), None) => Vec::new(),
        })
        .collect()
}
