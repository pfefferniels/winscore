//! TR: transposition as WinScore does it (routine 0x55B1F8 and the routines it
//! calls), reimplemented from the decompilation and checked against the engine.
//!
//! The engine first sorts the file (0x4F7808). Then, staff by staff, it
//! collects the notes and rests of the area and the key signatures up to its
//! right edge (0x4EBD10), changes the clefs if asked (0x5611DA), adds a key
//! signature if asked (0x4EC885), moves every note by the scale steps between
//! the old and the new key and respells it from key tables (0x561B90), drops
//! accidentals a note now inherits within its bar or across a tie, renames
//! guitar chords, moves the beams, and refits the slurs to the moved notes
//! (0x55C373 and 0x55CB57). Key signatures left without accidentals are removed.
//!
//! With the stem option the notes go through the refit (0x47C3E8,
//! score-input) before the slurs are refitted. Last, it justifies every
//! staff of the area (J, score-layout). Not done here: the enharmonic
//! change (±99 half steps).

use std::cmp::Ordering;

use score_format::Item;
use score_input::RefitMode;
use score_layout::{self as layout, Layout, LayoutErrorKind, Options, StaffRange};

use crate::group::Region;
use crate::params::Draft;

const NOTE: i32 = 1;
const REST: i32 = 2;
const CLEF: i32 = 3;
const SLUR: i32 = 5;
const BEAM: i32 = 6;
const GUITAR: i32 = 12;
const BARLINE: i32 = 14;
const KEY: i32 = 17;
/// P1 of an item the engine has marked for deletion (0x55E50B removes them).
const DELETED: f32 = 13.0;
/// Cue notes carry 100 in P4.
const CUE: f32 = 100.0;
/// P7 of the grace notes that are transposed even when cue notes are not.
const GRACE_P7: f32 = 65.0;
/// The engine rewrites only items with 0 <= P3 <= this (0x562FBD with IP2).
const RIGHT_END: f32 = 200.0;
/// The dialog's enharmonic change, not ported.
const ENHARMONIC: i32 = 99;
/// Intervals whose key the engine's table 0x79F26C covers.
const MAX_HALF_STEPS: i32 = 30;

/// Scale steps notes move for an interval of n half steps (table 0x79F240).
const STEPS_BY_HALF_STEPS: [i32; 12] = [0, 1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6];
/// The key C major moves to, for -6..=6 half steps (table 0x79F26C).
const KEY_FROM_C: [i32; 13] = [-6, 1, -4, 3, -2, 5, 0, -5, 2, -3, 4, -1, 6];
/// Letters (C = 0) a key signature alters, in the order sharps and flats are added.
const SHARP_ORDER: [i32; 7] = [3, 0, 4, 1, 5, 2, 6];
const FLAT_ORDER: [i32; 7] = [6, 2, 5, 1, 4, 0, 3];
/// Alteration of an accidental digit (P5 mod 10; table 0x794CBC); 3 is the natural.
const DIGIT_ALTERATION: [i32; 10] = [0, -1, 1, 3, -2, 2, 0, 0, 0, 0];
const NATURAL: i32 = 3;
/// Accidental digit for an alteration of -2..=2 (table 0x79F5B8).
const ALTERATION_DIGIT: [i32; 5] = [4, 1, 0, 2, 5];
/// Scale steps from treble to a clef's middle C, by clef type (table 0x79F5C8).
const CLEF_OFFSET: [i32; 5] = [0, -12, -6, -8, -7];
/// P4 change when a clef changes, at old * 4 + new (table 0x79F504).
const CLEF_SHIFT: [i32; 20] = [0, 12, 6, 8, -12, 0, -6, -4, -6, 6, 0, 2, -8, 4, -2, 0, 0, 0, 0, 0];
/// Guitar chord names in P7 (tens the letter, units 1 flat, 2 sharp): semitone of
/// each letter (table 0x79F1E0) and the name of each semitone (table 0x79F1B0).
const GUITAR_SEMITONE: [i32; 12] = [70, 1, 3, 5, 6, 8, 10, 12, -8, -5, -4, -3];
const GUITAR_NAME: [i32; 13] = [0, 10, 21, 20, 31, 30, 40, 42, 50, 61, 60, 71, 70];

/// The values of WinScore's Transpose Setup dialog.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub struct Transposition {
    /// The interval in half steps, + up, - down.
    pub half_steps: i32,
    /// Change every clef of the staff to this type (0 treble, 1 bass, 2 alto,
    /// 3 tenor), notes kept at their pitch; the first clef stays, others go.
    pub clef: Option<i32>,
    /// Add the new key signature to staves that have none before their first note.
    pub add_key_signature: bool,
    /// Stems up below the middle line, down from it, beams refitted.
    pub normalize_stems: bool,
    /// Transpose cue-size notes too.
    pub cue_notes: bool,
}

impl Transposition {
    /// The dialog's values as a line `half=2 clef=1 key=1 stems=1 cue=1`:
    /// fields left out are 0, a clef of -1 is no clef change.
    pub fn parse(line: &str) -> Option<Self> {
        line.split_whitespace().try_fold(Transposition::default(), |how, field| {
            let (name, value) = field.split_once('=')?;
            let value: i32 = value.parse().ok()?;
            Some(match name.to_ascii_lowercase().as_str() {
                "half" => Transposition { half_steps: value, ..how },
                "clef" => Transposition { clef: (value >= 0).then_some(value), ..how },
                "key" => Transposition { add_key_signature: value != 0, ..how },
                "stems" => Transposition { normalize_stems: value != 0, ..how },
                "cue" => Transposition { cue_notes: value != 0, ..how },
                _ => return None,
            })
        })
    }

    /// TR typed with its parameters, `TR p2 … p10`: the interval, staff,
    /// left, right, upper staff, add key (≠ 0), clef (0 none), stems kept
    /// (≠ 0; 0 normalizes them), cue notes (≠ 0). `None` for an interval of 0.
    pub fn typed(numbers: &[f32]) -> Option<(Region, Self)> {
        let p = |n: usize| numbers.get(n - 2).copied().unwrap_or(0.0);
        let half_steps = p(2).round_ties_even() as i32;
        if half_steps == 0 {
            return None;
        }
        let region = Region::parse(&[p(3), p(4), p(5), p(6)])?;
        let how = Transposition {
            half_steps,
            clef: (p(8) != 0.0).then(|| p(8).round_ties_even() as i32),
            add_key_signature: p(7) != 0.0,
            normalize_stems: p(9) == 0.0,
            cue_notes: p(10) != 0.0,
        };
        Some((region, how))
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Unsupported {
    Enharmonic,
    /// Beyond the ±30 half steps the engine's key table covers.
    Interval(i32),
    /// The engine's sort would garble the file.
    Layout(LayoutErrorKind),
}

impl std::fmt::Display for Unsupported {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            Unsupported::Enharmonic => write!(f, "the enharmonic change is not implemented"),
            Unsupported::Interval(h) => write!(f, "{h} half steps is beyond ±{MAX_HALF_STEPS}"),
            Unsupported::Layout(kind) => kind.fmt(f),
        }
    }
}

/// Engine state one TR leaves for the next.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub struct Leftover {
    /// The clef type of the last clef change. With a clef change asked for,
    /// the engine writes it into each staff's first clef, also on staves whose
    /// notes all had the wanted clef already (0 before any change).
    pub last_clef: i32,
}

/// The file after a transposition, in its new order: `source[i]` is the
/// index in the input of `items[i]`, `None` for an added key signature.
#[derive(Debug, Clone, PartialEq)]
pub struct Arranged {
    pub items: Vec<Item>,
    pub source: Vec<Option<usize>>,
    pub leftover: Leftover,
}

/// Transposes the staves `region.bottom..=region.top`: notes with P3 from
/// `region.left` to `region.right` (and the key signatures up to there).
pub fn transpose(
    items: &[Item],
    region: &Region,
    how: &Transposition,
    mut leftover: Leftover,
) -> Result<Arranged, Unsupported> {
    if how.half_steps.abs() == ENHARMONIC {
        return Err(Unsupported::Enharmonic);
    }
    if how.half_steps.abs() > MAX_HALF_STEPS {
        return Err(Unsupported::Interval(how.half_steps));
    }
    let mut rows = sorted(items)?;
    let area = Area { left: region.left, right: region.right };
    let first = region.bottom.round() as i32;
    let last = region.top.round() as i32;
    (first..=last).for_each(|staff| transpose_staff(&mut rows, staff, area, how, &mut leftover));
    let rows = justify_staves(rows, first, last);
    let (items, source) = rows
        .into_iter()
        .filter(|row| row.draft.get(1) != DELETED)
        .map(|row| (row.draft.to_item(), row.source))
        .unzip();
    Ok(Arranged { items, source, leftover })
}

#[derive(Debug, Clone, PartialEq)]
struct Row {
    draft: Draft,
    source: Option<usize>,
}

impl Row {
    fn staff(&self) -> i32 {
        self.draft.get(2) as i32
    }

    fn code(&self) -> i32 {
        self.draft.code()
    }

    fn x(&self) -> f32 {
        self.draft.get(3)
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
struct Area {
    left: f32,
    right: f32,
}

/// The file as the engine's sort 0x4F7808 leaves it, which TR starts with.
fn sorted(items: &[Item]) -> Result<Vec<Row>, Unsupported> {
    let layout = layout::sort(items).map_err(|error| Unsupported::Layout(error.kind))?;
    Ok(rows_of(layout, Some))
}

/// The rows of a layout, each with the source `source_of` gives its input index.
fn rows_of(layout: Layout, source_of: impl Fn(usize) -> Option<usize>) -> Vec<Row> {
    layout.source.into_iter().zip(layout.items).map(|(i, item)| Row { draft: Draft::of(&item), source: source_of(i) }).collect()
}

/// J on each staff `first..=last` over the whole width, as TR ends (0x4B80B7
/// called once per staff). A staff J gives up on stays as J leaves it.
fn justify_staves(rows: Vec<Row>, first: i32, last: i32) -> Vec<Row> {
    (first..=last).fold(rows, |rows, staff| {
        let items: Vec<Item> = rows.iter().map(|row| row.draft.to_item()).collect();
        let range = StaffRange { first: staff, last: staff };
        let layout = layout::justify(&items, range, &Options::default()).unwrap_or_else(|error| error.layout);
        rows_of(layout, |i| rows[i].source)
    })
}

fn round_even(x: f32) -> i32 {
    x.round_ties_even() as i32
}

fn writable(x: f32) -> bool {
    (0.0..=RIGHT_END).contains(&x)
}

/// Alteration (-1, 0, 1) the key signature `key` gives letter `letter` (1 = C … 7 = B).
fn key_alteration(key: i32, letter: i32) -> i32 {
    let count = key.unsigned_abs().min(7) as usize;
    let letter = letter - 1;
    match key.signum() {
        1 if SHARP_ORDER[..count].contains(&letter) => 1,
        -1 if FLAT_ORDER[..count].contains(&letter) => -1,
        _ => 0,
    }
}

/// The key C major moves to by `half_steps` (in -30..=30).
fn key_from_c(half_steps: i32) -> i32 {
    let index = match half_steps + 7 {
        i if i > 13 && half_steps - 5 > 13 => half_steps - 17,
        i if i > 13 => half_steps - 5,
        i if i < 1 && i + 12 < 1 => i + 24,
        i if i < 1 => i + 12,
        i => i,
    };
    KEY_FROM_C[(index - 1) as usize]
}

/// Scale steps for an interval when no key signature says otherwise.
fn interval_steps(half_steps: i32) -> i32 {
    let size = half_steps.abs();
    let steps = STEPS_BY_HALF_STEPS[(size % 12) as usize] + 7 * i32::from(size > 11) + 7 * i32::from(size > 23);
    if half_steps < 0 {
        -steps
    } else {
        steps
    }
}

/// The tonic's letter of a key as 0x562F53 counts it (C = 0, but C# major = 7).
fn tonic_letter(key: i32) -> i32 {
    let k = if key < 0 { key + 7 } else { key };
    let k = if k % 2 != 0 { k + 7 } else { k };
    k / 2
}

/// The key `half_steps` from `old`, and the scale steps notes move (0x562CC6).
fn moved_key(old: i32, half_steps: i32) -> (i32, i32) {
    let h = half_steps;
    if h.abs() == 12 {
        return (old, 7 * h.signum());
    }
    let new = match (old - 5 * h) % 12 {
        k if k < -6 => k + 12,
        k if k > 6 => k - 12,
        k => k,
    };
    let new = if new.abs() == 6 { if old < 0 { -6 } else { 6 } } else { new };
    let d = tonic_letter(old) - tonic_letter(new);
    let steps = if h < 0 {
        let s = match d {
            d if d < 0 => -7 - d,
            d => -d,
        };
        let s = match s {
            s if h < -10 && s > -6 && -d - 7 > -6 => -d - 14,
            s if h < -10 && s > -6 => -d - 7,
            s => s,
        };
        if h < -21 { s - 7 } else { s }
    } else {
        let s = match d {
            d if d > 0 => 7 - d,
            d => -d,
        };
        let s = match s {
            s if h > 10 && s < 6 && 7 - d < 6 => 14 - d,
            s if h > 10 && s < 6 => 7 - d,
            s => s,
        };
        if h > 21 { s + 7 } else { s }
    };
    (new, steps)
}

/// One of the items 0x4EBD10 lists for a staff.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Entry {
    row: usize,
    x: f32,
    /// The clef type in effect.
    clef: i32,
    kind: Kind,
}

#[derive(Debug, Clone, Copy, PartialEq)]
enum Kind {
    Rest,
    Key,
    Note {
        /// P4 rounded, without the hundreds of cue notes.
        level: i32,
        /// From the accidental digit; 0 none, ±1, ±2, 3 natural.
        accidental: i32,
        /// The first note after a barline (or of the staff), and its chord.
        bar_start: bool,
    },
}

impl Kind {
    fn note_level(self) -> Option<i32> {
        match self {
            Kind::Note { level, .. } => Some(level),
            _ => None,
        }
    }
}

/// What 0x4EBD10 gathers on one staff.
#[derive(Debug, Clone, PartialEq, Default)]
struct StaffItems {
    entries: Vec<Entry>,
    /// Slurs with P4 = P5 (ties), as rows.
    ties: Vec<usize>,
    beams: bool,
}

/// The notes, rests and keys of `staff` the engine transposes; `None` when it
/// leaves the staff alone (nothing there, or a note or rest without a duration).
fn staff_items(rows: &[Row], staff: i32, area: Area) -> Option<StaffItems> {
    let low = area.left - 0.001;
    let high = area.right + 0.001;
    let mut found = StaffItems::default();
    let mut clef = 0;
    let on_staff = rows.iter().enumerate().filter(|(_, row)| row.staff() == staff);
    for (i, row) in on_staff.take_while(|(_, row)| row.x() <= high) {
        let d = &row.draft;
        match row.code() {
            code if code < CLEF && row.x() >= low => {
                if d.len() < 7 || d.get(7) == 0.0 {
                    return None;
                }
                if d.get(7) < 0.0 {
                    continue;
                }
                let kind = if code == REST {
                    Kind::Rest
                } else {
                    let digit = if d.len() < 5 { 0 } else { round_even(d.get(5)) % 10 };
                    let accidental = usize::try_from(digit).map_or(0, |n| DIGIT_ALTERATION[n]);
                    let level = if d.len() > 3 { round_even(d.get(4)) % 100 } else { 0 };
                    Kind::Note { level, accidental, bar_start: false }
                };
                found.entries.push(Entry { row: i, x: row.x(), clef, kind });
            }
            SLUR if d.len() >= 7 && (d.len() < 8 || d.get(8) <= 0.0) && d.get(4) == d.get(5) => found.ties.push(i),
            CLEF => clef = if d.len() > 4 { round_even(d.get(5)) } else { 0 },
            KEY => found.entries.push(Entry { row: i, x: row.x(), clef, kind: Kind::Key }),
            BEAM if d.len() > 6 => found.beams = true,
            _ => {}
        }
    }
    if found.entries.is_empty() {
        return None;
    }
    mark_bar_starts(rows, staff, high, &mut found.entries);
    Some(found)
}

/// Marks the first note after each barline that reaches `staff` (and the
/// notes of its chord), and the staff's first note.
fn mark_bar_starts(rows: &[Row], staff: i32, high: f32, entries: &mut [Entry]) {
    let first_note = entries.iter().find(|e| e.kind != Kind::Key).map_or(0.0, |e| e.x);
    let mut bars: Vec<f32> = Vec::new();
    rows.iter()
        .take_while(|row| row.staff() <= staff)
        .filter(|row| row.code() == BARLINE && row.x() <= high && row.x() >= first_note)
        .filter(|row| {
            let span = if row.draft.len() > 3 { round_even(row.draft.get(4)) } else { 1 };
            staff - row.staff() < if span == 0 { 1 } else { span }
        })
        .for_each(|row| {
            if !bars.contains(&row.x()) {
                bars.push(row.x());
            }
        });
    if bars.is_empty() {
        return;
    }
    bars.sort_by(|a, b| a.partial_cmp(b).unwrap_or(Ordering::Equal));
    let set_start = |entry: &mut Entry| {
        if let Kind::Note { bar_start, .. } = &mut entry.kind {
            *bar_start = true;
        }
    };
    set_start(&mut entries[0]);
    let mut bar = 0;
    let mut next_bar = bars[0];
    (0..entries.len()).for_each(|i| {
        if next_bar > entries[i].x || entries[i].kind == Kind::Rest {
            return;
        }
        if matches!(entries[i].kind, Kind::Note { bar_start: false, .. }) {
            let x = entries[i].x;
            entries[i..]
                .iter_mut()
                .take_while(|e| e.x == x && matches!(e.kind, Kind::Note { bar_start: false, .. }))
                .for_each(set_start);
        }
        while bar < bars.len() {
            bar += 1;
            next_bar = bars.get(bar).copied().unwrap_or(f32::INFINITY);
            if next_bar >= entries[i].x {
                break;
            }
        }
    });
}

/// The shape 0x55C373 records of a note for the slur refit.
#[derive(Debug, Clone, Copy, PartialEq)]
struct NoteShape {
    x: f32,
    level: i32,
    /// 0 none, 1 up, 2 down.
    stem: i32,
    /// The level of the stem's end (the head's level without a stem).
    stem_end: f32,
}

impl NoteShape {
    fn of(draft: &Draft) -> Self {
        let raw = draft.get(4).trunc() as i32;
        let cue = raw.abs() > 99;
        let level = if cue { raw % 100 } else { raw };
        let stem = (draft.get(5) / 10.0) as i32;
        let length = if draft.len() >= 8 { draft.get(8) % 100.0 + 7.0 } else { 7.0 };
        let length = match stem {
            0 => 0.0,
            2 => -length,
            _ => length,
        };
        let length = if cue { length * 0.6 } else { length };
        NoteShape { x: draft.get(3), level, stem, stem_end: level as f32 + length }
    }
}

fn note_shapes(rows: &[Row], entries: &[Entry]) -> Vec<NoteShape> {
    entries
        .iter()
        .map(|e| &rows[e.row].draft)
        .filter(|d| d.code() == NOTE)
        .map(NoteShape::of)
        .collect()
}

/// A slur as 0x55C373 records it before the transposition.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Slur {
    row: usize,
    x: f32,
    right_x: f32,
    curve: f32,
}

/// The slurs of `staff` in the area that the refit treats: not those with
/// P8 = 2 or 4 or (with 8 parameters or more) 1.
fn refit_slurs(rows: &[Row], staff: i32, area: Area) -> Vec<Slur> {
    rows.iter()
        .enumerate()
        .filter(|(_, row)| row.staff() == staff && row.code() == SLUR)
        .filter(|(_, row)| (area.left..=area.right).contains(&row.x()))
        .filter(|&(i, row)| {
            let p8 = stored_word(rows, i, 8);
            !(p8 == 4.0 || p8 == 2.0 || (row.draft.len() > 7 && p8 == 1.0))
        })
        .map(|(i, row)| Slur { row: i, x: row.x(), right_x: row.draft.get(6), curve: row.draft.get(7) })
        .collect()
}

/// Parameter `n` of row `i` as the engine reads it from its item store, where
/// each item is its word count followed by its parameters: past the item's
/// own parameters it reads the next item's words.
fn stored_word(rows: &[Row], i: usize, n: usize) -> f32 {
    let len = rows[i].draft.len();
    if n <= len {
        return rows[i].draft.get(n);
    }
    match (rows.get(i + 1), n - len - 1) {
        (None, _) => 0.0,
        (Some(next), 0) => next.draft.len() as f32,
        (Some(next), k) => next.draft.get(k),
    }
}

fn transpose_staff(rows: &mut Vec<Row>, staff: i32, area: Area, how: &Transposition, leftover: &mut Leftover) {
    let Some(mut found) = staff_items(rows, staff, area) else { return };
    let before = note_shapes(rows, &found.entries);
    let slurs = refit_slurs(rows, staff, area);
    if let Some(clef) = how.clef {
        change_clef(rows, &mut found.entries, staff, clef, leftover);
    }
    let mut keys = KeyState::new(how.half_steps);
    if how.add_key_signature && how.half_steps % 12 != 0 && !has_leading_key(rows, staff) {
        let (key, steps) = moved_key(0, how.half_steps);
        let clef = found.entries[0].clef;
        add_key_signature(rows, staff, key, clef);
        keys = KeyState { steps, written: key, reference: key, ..keys };
    }
    let beam_steps = keys.steps;
    transpose_entries(rows, &found.entries, keys, how);
    drop_inherited_accidentals(rows, &found.entries, &found.ties, how);
    if how.half_steps % 12 != 0 {
        rename_guitar_chords(rows, staff, how.half_steps % 12);
    }
    if found.beams || !found.ties.is_empty() {
        move_beams(rows, staff, area, beam_steps);
    }
    if how.normalize_stems {
        refit_stems(rows, staff, area);
    }
    let after = note_shapes(rows, &found.entries);
    refit(rows, &slurs, &before, &after);
}

/// The stem option: the staff's notes in the area through the refit
/// (0x47C3E8 in mode 2, score-input), which the engine runs between moving
/// the beams and refitting the slurs. Where the refit gives up, the items
/// stay as it leaves them.
fn refit_stems(rows: &mut [Row], staff: i32, area: Area) {
    let items: Vec<Item> = rows.iter().map(|row| row.draft.to_item()).collect();
    let refitted = score_input::refit(&items, staff, (area.left, area.right), RefitMode::Normal).unwrap_or_else(|error| error.items);
    rows.iter_mut().zip(refitted).for_each(|(row, item)| row.draft = Draft::of(&item));
}

/// Changes the clef of every entry to `new` (0x5611DA): notes keep their
/// pitch, beams near them move along, keys learn the clef in P6. The staff's
/// first clef item becomes the clef of the last change made (see
/// [`Leftover`]), its other clefs are deleted.
fn change_clef(rows: &mut [Row], entries: &mut [Entry], staff: i32, new: i32, leftover: &mut Leftover) {
    let mut start = 0;
    let mut beams_from_row = 0;
    while start < entries.len() {
        let old = entries[start].clef;
        if old == new {
            start += 1;
            continue;
        }
        leftover.last_clef = new;
        let shift = usize::try_from(old * 4 + new).ok().and_then(|i| CLEF_SHIFT.get(i)).copied().unwrap_or(0);
        let end = start + entries[start..].iter().take_while(|e| e.clef == old).count();
        entries[start..end].iter_mut().for_each(|entry| {
            if let Kind::Note { level, .. } = &mut entry.kind {
                *level += shift;
                let draft = &mut rows[entry.row].draft;
                let p4 = round_even(draft.get(4));
                let hundreds = match p4 {
                    p if p.abs() <= 99 => 0,
                    p if p < 0 => -100,
                    _ => 100,
                };
                draft.set(4, (*level + hundreds) as f32);
            }
            entry.clef = new;
        });
        let last_row = entries[end - 1].row;
        let low = rows[beams_from_row].x() - 4.0;
        let high = rows[last_row].x() + 4.0;
        rows.iter_mut()
            .filter(|row| row.staff() == staff && row.code() == BEAM && row.draft.len() > 4)
            .filter(|row| (low..=high).contains(&row.x()))
            .for_each(|row| shift_beam(&mut row.draft, shift as f32));
        rows.iter_mut().filter(|row| row.staff() == staff && row.code() == KEY).for_each(|row| row.draft.set(6, new as f32));
        beams_from_row = last_row + 1;
        start = end;
    }
    let written = leftover.last_clef;
    let mut clefs = rows.iter_mut().filter(|row| row.staff() == staff && row.code() == CLEF);
    if let Some(first) = clefs.next() {
        if first.draft.len() >= 5 || written != 0 {
            first.draft.set(5, written as f32);
        }
    }
    clefs.for_each(|row| row.draft.set(1, DELETED));
}

/// P4 and P5 of a beam moved by `steps`, keeping the hundreds of a cue beam.
fn shift_beam(draft: &mut Draft, steps: f32) {
    let p4 = draft.get(4);
    let moved = if p4.abs() >= CUE {
        let within = p4 % CUE + steps;
        within + if within < 0.0 { -CUE } else { CUE }
    } else {
        p4 + steps
    };
    draft.set(4, moved);
    draft.add(5, steps);
}

/// Whether a key signature comes before the staff's first note or rest.
fn has_leading_key(rows: &[Row], staff: i32) -> bool {
    rows.iter()
        .filter(|row| row.staff() == staff)
        .find(|row| row.code() < CLEF || row.code() == KEY)
        .is_some_and(|row| row.code() == KEY)
}

/// Appends a key signature (0x4EC885): halfway between the staff's first clef
/// and the item after it, else just right of the staff's leftmost item.
fn add_key_signature(rows: &mut Vec<Row>, staff: i32, key: i32, clef: i32) {
    let scanned = &rows[..rows.len().saturating_sub(1)];
    let clef_at = scanned.iter().position(|row| row.staff() == staff && row.code() == CLEF);
    let x = match clef_at {
        Some(i) => {
            let clef_x = rows[i].x();
            match rows.get(i + 1) {
                Some(next) if next.draft.len() >= 3 => ((f64::from(next.x()) - f64::from(clef_x)) / 2.0 + f64::from(clef_x)) as f32,
                _ => clef_x,
            }
        }
        None => scanned.iter().filter(|row| row.staff() == staff).map(Row::x).fold(999.0, f32::min) + 1.0,
    };
    let draft = Draft::new(&[KEY as f32, staff as f32, x, 0.0, key as f32, clef as f32]);
    rows.push(Row { draft, source: None });
}

/// The key context 0x561B90 carries along a staff.
#[derive(Debug, Clone, Copy, PartialEq)]
struct KeyState {
    half_steps: i32,
    /// Scale steps notes move.
    steps: i32,
    /// The key signature in effect before the transposition.
    old: i32,
    /// The transposed key signature in effect; 0 also when there is none.
    written: i32,
    /// The key whose accidentals notes take, C major transposed while there
    /// is no key signature.
    reference: i32,
}

impl KeyState {
    fn new(half_steps: i32) -> Self {
        KeyState {
            half_steps,
            steps: interval_steps(half_steps),
            old: 0,
            written: 0,
            reference: key_from_c(half_steps),
        }
    }
}

fn transpose_entries(rows: &mut [Row], entries: &[Entry], mut keys: KeyState, how: &Transposition) {
    entries.iter().enumerate().for_each(|(position, entry)| match entry.kind {
        Kind::Key => keys = transpose_key(&mut rows[entry.row].draft, entry, position, keys),
        Kind::Rest => {}
        Kind::Note { level, accidental, .. } => {
            let draft = &mut rows[entry.row].draft;
            if is_transposed(draft, how) {
                transpose_note(draft, entry.clef, level, accidental, keys);
            }
        }
    });
}

/// Whether a note moves: cue notes only when asked, grace notes always.
fn is_transposed(note: &Draft, how: &Transposition) -> bool {
    note.get(4).abs() < CUE || how.cue_notes || note.get(7) == GRACE_P7
}

/// A key signature transposed; one left without accidentals is deleted, or
/// after a key with accidentals becomes their cancellation (±100 + that key).
fn transpose_key(draft: &mut Draft, entry: &Entry, position: usize, keys: KeyState) -> KeyState {
    let old = round_even(draft.get(5));
    let old = if old.abs() > 99 { 0 } else { old };
    let (new, steps) = moved_key(old, keys.half_steps);
    let in_reach = writable(entry.x);
    let value = match new {
        0 if position != 0 && keys.written != 0 => Some(keys.written + if keys.written < 0 { -100 } else { 100 }),
        0 => None,
        k => Some(k),
    };
    match value {
        None if in_reach => draft.set(1, DELETED),
        None => {}
        Some(value) => {
            if draft.len() > 4 && in_reach {
                draft.set(5, value as f32);
            }
            if (draft.len() >= 6 || entry.clef != 0) && in_reach {
                draft.set(6, entry.clef as f32);
            }
        }
    }
    KeyState { steps, old, written: new, reference: new, ..keys }
}

fn transpose_note(draft: &mut Draft, clef: i32, level: i32, accidental: i32, keys: KeyState) {
    let offset = usize::try_from(clef).ok().and_then(|c| CLEF_OFFSET.get(c)).copied().unwrap_or(0);
    let letter = (offset + level + 6).rem_euclid(7) + 1;
    let new_letter = (keys.steps + 6 + letter).rem_euclid(7) + 1;
    let new_alteration = key_alteration(keys.reference, new_letter);
    let mut level = level;
    let digit = match accidental {
        0 if keys.written == 0 => Some(alteration_digit(new_alteration)),
        0 => None,
        a => {
            let a = if a == NATURAL { 0 } else { a };
            match a - key_alteration(keys.old, letter) + new_alteration {
                0 => Some(NATURAL),
                d if d < -2 => {
                    level += 1;
                    Some(alteration_digit(-2))
                }
                d if d > 2 => {
                    level -= 1;
                    Some(alteration_digit(2))
                }
                d => Some(alteration_digit(d)),
            }
        }
    };
    if !writable(draft.get(3)) {
        return;
    }
    if let Some(digit) = digit {
        let p5 = draft.get(5);
        draft.set(5, (round_even(p5) / 10 * 10 + digit) as f32 + p5 % 1.0);
    }
    let moved = keys.steps + level;
    let moved = match draft.get(4).abs() >= CUE {
        true if moved < 0 => moved - 100,
        true => moved + 100,
        false => moved,
    };
    draft.set(4, moved as f32);
}

fn alteration_digit(alteration: i32) -> i32 {
    ALTERATION_DIGIT[(alteration + 2) as usize]
}

/// The accidental digit of P5 removed.
fn drop_accidental(draft: &mut Draft) {
    if writable(draft.get(3)) {
        draft.set(5, (round_even(draft.get(5)) / 10 * 10) as f32);
    }
}

/// The ties 0x557EDE walks through: windows of ±3 around each end.
#[derive(Debug, Clone, Copy, PartialEq)]
struct TieWindow {
    start: (f32, f32),
    end: (f32, f32),
}

/// The second pass of 0x561B90: a note that had no accidental loses the one
/// the transposition gave it when an earlier note of the same bar, level and
/// clef sets it, or when it ends a tie from a note of its level.
fn drop_inherited_accidentals(rows: &mut [Row], entries: &[Entry], ties: &[usize], how: &Transposition) {
    let windows: Vec<TieWindow> = ties
        .iter()
        .map(|&t| {
            let d = &rows[t].draft;
            TieWindow { start: (d.get(3) - 3.0, d.get(3) + 3.0), end: (d.get(6) - 3.0, d.get(6) + 3.0) }
        })
        .collect();
    let first_x = entries
        .iter()
        .find(|e| matches!(e.kind, Kind::Note { .. }) && is_transposed(&rows[e.row].draft, how))
        .map(|e| e.x);
    let mut tie = 0;
    (0..entries.len()).for_each(|i| {
        let Kind::Note { level, accidental, bar_start } = entries[i].kind else { return };
        let x = entries[i].x;
        if accidental == 0 && tie < windows.len() {
            let ends_tie = if first_x.is_some_and(|first| x <= first) {
                tie_ending_at(&windows, &mut tie, x, |_| true)
            } else if bar_start {
                tie_ending_at(&windows, &mut tie, x, |w| x <= w.end.1 && tied_from(entries, i, level))
            } else {
                false
            };
            if ends_tie {
                drop_accidental(&mut rows[entries[i].row].draft);
                tie += 1;
                return;
            }
        }
        let clef = entries[i].clef;
        let same_bar = entries[i + 1..]
            .iter()
            .take_while(|e| e.clef == clef)
            .filter(|e| e.kind != Kind::Rest)
            .take_while(|e| !matches!(e.kind, Kind::Note { bar_start: true, .. }) || e.x == x)
            .filter(|e| e.kind.note_level() == Some(level));
        let inheriting: Vec<usize> = same_bar
            .take_while(|e| matches!(e.kind, Kind::Note { accidental: 0, .. }))
            .map(|e| e.row)
            .collect();
        inheriting.into_iter().for_each(|row| drop_accidental(&mut rows[row].draft));
    });
}

/// Walks the tie cursor past ties that start before `x` and reports whether
/// one of them ends at `x` (its end window reaches `x` and `confirm` agrees).
fn tie_ending_at(windows: &[TieWindow], tie: &mut usize, x: f32, confirm: impl Fn(&TieWindow) -> bool) -> bool {
    while let Some(window) = windows.get(*tie) {
        if x <= window.start.1 {
            return false;
        }
        if window.end.0 <= x && confirm(window) {
            return true;
        }
        *tie += 1;
    }
    false
}

/// Whether the chord before entry `i` (same clef, notes only) has a note of `level`.
fn tied_from(entries: &[Entry], i: usize, level: i32) -> bool {
    let x = entries[i].x;
    let earlier = entries[..i].iter().rev();
    let mut before = earlier.skip_while(|e| e.x == x && is_note_with_clef(e, entries[i].clef)).peekable();
    let Some(chord_x) = before.peek().filter(|e| is_note_with_clef(e, entries[i].clef)).map(|e| e.x) else {
        return false;
    };
    before.take_while(|e| e.x == chord_x).any(|e| e.kind.note_level() == Some(level))
}

fn is_note_with_clef(entry: &Entry, clef: i32) -> bool {
    matches!(entry.kind, Kind::Note { .. }) && entry.clef == clef
}

/// Guitar chord grids (code 12, P5 < 0) get the chord name in P7 transposed.
fn rename_guitar_chords(rows: &mut [Row], staff: i32, half_steps: i32) {
    rows.iter_mut()
        .filter(|row| row.staff() == staff && row.code() == GUITAR && row.draft.len() > 6)
        .filter(|row| row.draft.get(5) < 0.0 && row.draft.get(7) != 0.0)
        .for_each(|row| {
            let name = round_even(row.draft.get(7));
            let Some(&semitone) = usize::try_from(name / 10).ok().and_then(|i| GUITAR_SEMITONE.get(i)) else { return };
            let accidental = match name % 10 {
                2 => -1,
                a => a,
            };
            let moved = (semitone - accidental + half_steps) % 12;
            let moved = if moved < 1 { moved + 12 } else { moved };
            row.draft.set(7, GUITAR_NAME[moved as usize] as f32);
        });
}

/// Beams of the staff overlapping the area move by the interval's steps.
fn move_beams(rows: &mut [Row], staff: i32, area: Area, steps: i32) {
    let low = round_even(area.left - 0.5);
    let high = round_even(area.right + 0.5);
    rows.iter_mut()
        .filter(|row| row.staff() == staff && row.code() == BEAM && row.draft.len() > 5)
        .filter(|row| round_even(row.x()) <= high && round_even(row.draft.get(6)) >= low)
        .for_each(|row| shift_beam(&mut row.draft, steps as f32));
}

/// The note nearest to `x` (the first of equals).
fn nearest(notes: &[NoteShape], x: f32) -> usize {
    notes
        .iter()
        .enumerate()
        .fold((0, 999.0_f32), |(best, distance), (i, note)| {
            let d = (note.x - x).abs();
            if d < distance { (i, d) } else { (best, distance) }
        })
        .0
}

/// Slurs refitted to the transposed notes nearest their ends (0x55CB57).
fn refit(rows: &mut [Row], slurs: &[Slur], before: &[NoteShape], after: &[NoteShape]) {
    if before.is_empty() || before.len() != after.len() {
        return;
    }
    slurs.iter().enumerate().for_each(|(k, slur)| {
        let start = nearest(after, slur.x);
        let end = nearest(after, slur.right_x);
        let twin = |other: Option<&Slur>| other.is_some_and(|o| o.x == slur.x && o.right_x == slur.right_x);
        let doubled = twin(slurs.get(k + 1)) || twin(k.checked_sub(1).and_then(|p| slurs.get(p)));
        let draft = &mut rows[slur.row].draft;
        let flat_tie = draft.len() >= 8 && draft.get(4) == draft.get(5) && matches!(draft.get(8), -2.0 | -3.0);
        let chord_tie = doubled && draft.get(4) == draft.get(5);
        let curve = if chord_tie {
            let shift = (lowest_in_chord(after, start) - lowest_in_chord(before, start)) as f32;
            draft.add(4, shift);
            draft.add(5, shift);
            slur.curve
        } else {
            refit_ends(draft, slur.curve, flat_tie, (before[start], before[end]), (after[start], after[end]))
        };
        if curve != slur.curve {
            draft.set(7, curve);
        }
        let up = if curve < 0.0 { -1.0 } else { 1.0 };
        let up = if chord_tie && flat_tie { -up } else { up };
        [4, 5].into_iter().for_each(|n| {
            let level = draft.get(n).round() as i32;
            if level % 2 != 0 && (3..=11).contains(&level) {
                draft.add(n, up);
            }
        });
    });
}

/// Slots of the engine's note table (0x9A6864 and its companions).
const NOTE_SLOTS: usize = 200;

/// The lowest level of the chord at note `start`, scanning on while notes lie
/// no further right. The scan runs through the table's unused slots, which
/// hold x = 0 and level 0, unless a note further right stops it.
fn lowest_in_chord(notes: &[NoteShape], start: usize) -> i32 {
    let x = notes[start].x;
    let chord = notes[start..].iter().take_while(|n| n.x <= x);
    let reaches_free_slots = start + chord.clone().count() == notes.len() && notes.len() < NOTE_SLOTS;
    let lowest = chord.map(|n| n.level).min().unwrap_or(0);
    if reaches_free_slots && x >= 0.0 { lowest.min(0) } else { lowest }
}

/// The slur's ends placed by the stem directions of its notes; returns its
/// curve, turned up when the slur goes over stems down and down when stems
/// that were down now point up.
fn refit_ends(
    draft: &mut Draft,
    curve: f32,
    flat_tie: bool,
    (start_before, end_before): (NoteShape, NoteShape),
    (start, end): (NoteShape, NoteShape),
) -> f32 {
    let gap = if flat_tie { 0.0 } else { 2.0 };
    let turned_up = |curve: f32| if curve < 0.0 { -curve } else { curve };
    let was_down = start_before.stem == 2 || end_before.stem == 2;
    let (ends, curve) = match (start.stem, end.stem) {
        (2, 2) => (Some((start.level as f32 + gap, end.level as f32 + gap)), turned_up(curve)),
        (2, 1) => (Some((start.level as f32 + 2.0, end.stem_end + 1.0)), turned_up(curve)),
        (1, 2) => (Some((start.stem_end + 1.0, end.level as f32 + 2.0)), turned_up(curve)),
        (1, 1) if curve > 0.0 && was_down => (Some((start.level as f32 - gap, end.level as f32 - gap)), -curve),
        (s, e) if (s == 1 && e == 1 && curve < 0.0 && was_down) || (start_before.stem == end_before.stem && s == e) => {
            let shift = (start.level - start_before.level) as f32;
            let ends = if flat_tie {
                (start.level as f32, start.level as f32)
            } else {
                (draft.get(4) + shift, draft.get(5) + shift)
            };
            (Some(ends), curve)
        }
        _ => (None, curve),
    };
    if let Some((p4, p5)) = ends {
        draft.set(4, p4);
        draft.set(5, p5);
    }
    curve
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn keys_as_0x562cc6_moves_them() {
        let cases = [
            ((0, 1), (-5, 1)),
            ((0, 6), (6, 3)),
            ((1, 6), (-5, 4)),
            ((-1, 6), (5, 3)),
            ((7, -1), (0, -7)),
            ((7, 7), (-4, 5)),
            ((3, 12), (3, 7)),
            ((0, 14), (2, 8)),
            ((0, -21), (-3, -12)),
            ((-6, 6), (0, 3)),
        ];
        cases.iter().for_each(|&((old, h), want)| assert_eq!(moved_key(old, h), want, "{old} by {h}"));
    }

    #[test]
    fn c_major_and_interval_tables() {
        assert_eq!((key_from_c(1), key_from_c(-6), key_from_c(6), key_from_c(-7), key_from_c(19)), (-5, -6, 6, -1, 1));
        assert_eq!((interval_steps(6), interval_steps(-13), interval_steps(25)), (3, -8, 15));
    }

    #[test]
    fn key_signatures_alter_letters() {
        assert_eq!((key_alteration(1, 4), key_alteration(2, 1), key_alteration(-1, 7), key_alteration(-1, 3)), (1, 1, -1, 0));
    }
}
