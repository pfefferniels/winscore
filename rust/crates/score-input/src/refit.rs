//! The refit of one staff's stems, beams and slurs (0x47C3E8), which the group commands
//! FLI, FLN, FLU and FLD run on each staff of their area, and TR with its stem option.
//!
//! The engine turns the notes in the area back into input: a pitch stream for pass 1 with
//! stem codes for the chosen directions and cue toggles, one rhythm per chord, the stored
//! marks, and beams and slurs as pairs of note numbers (found by position, 0x47DC96). It
//! runs passes 1 to 5 on that and writes P4, P5 and P8 to P11 back into the same notes,
//! P4, P5 and P7 into the beams and slurs it could match (0x47E0A9). Here the same input
//! goes through score-input's passes.
//!
//! Like the engine, `refit` expects the items sorted (0x4F7808, which the commands run
//! first) and changes no item's place in the list.

use score_format::{Item, Word};

use crate::connect::{ConnectEntry, Connection};
use crate::events::{Event, Head};
use crate::line::{Line, Timed};
use crate::notes::{Accidental, Clef, StemMode};
use crate::num::{amod, par, trunc};
use crate::rhythm::Rhythm;
use crate::{beams, marks, slurs, stems, Options};

const NOTE: i32 = 1;
const SLUR: i32 = 5;
const BEAM: i32 = 6;
const STAFF: i32 = 8;
const TEXT: i32 = 16;
/// The refit gives up at the note after this many.
const MAX_NOTES: usize = 100;
/// P7 from here on is a grace note; the rhythm sent for it is clamped to this.
const GRACE: f32 = 64.0;
/// A beam end this close to a note's P3 is moved onto it.
const SNAP: f32 = 0.01;
/// Notes this long or longer (up to grace notes) cannot be under a beam.
const BEAMABLE: f32 = 0.99;
/// Marks from this code on are not P11 marks for the marks pass.
const FIRST_SYMBOL_MARK: i32 = 45;
/// P1 to P11 are stored for every refitted note (0x5239C9 lengthens shorter items).
const NOTE_WORDS: usize = 11;
const WRITTEN: [usize; 6] = [4, 5, 8, 9, 10, 11];

/// The stem directions a refit sets.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum RefitMode {
    /// FLI: every stem the other way.
    Invert,
    /// FLN, and TR's stem option: the directions pass 1 gives.
    Normal,
    /// FLD
    Down,
    /// FLU
    Up,
}

/// Why the engine gives up on a staff; `item` is an index into the input.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum RefitErrorKind {
    /// A beam with P7 < 0 (a tremolo); the engine reports it.
    TremoloBeam { item: usize },
    /// A beam ending right of the area; the engine reports it.
    BeamPastArea { item: usize },
    /// A note of a quarter or longer at a beam's end.
    LongNoteUnderBeam { item: usize },
    /// More than 100 notes.
    TooManyNotes,
    /// A chord whose first note has no stem and none of whose notes has one.
    NoStem { item: usize },
    /// A chord whose first note has P7 = 0.
    NoDuration { item: usize },
    /// A chord whose second and third notes both have stems.
    TwoStems { item: usize },
    /// Input this port does not handle (the engine may do something with it).
    Unsupported(&'static str),
}

impl std::fmt::Display for RefitErrorKind {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            RefitErrorKind::TremoloBeam { item } => write!(f, "item {item}: a tremolo cannot be refitted"),
            RefitErrorKind::BeamPastArea { item } => write!(f, "item {item}: the beam ends outside the area"),
            RefitErrorKind::LongNoteUnderBeam { item } => write!(f, "item {item}: a beamed note is a quarter or longer"),
            RefitErrorKind::TooManyNotes => write!(f, "more than {MAX_NOTES} notes"),
            RefitErrorKind::NoStem { item } => write!(f, "item {item}: the chord has no stem"),
            RefitErrorKind::NoDuration { item } => write!(f, "item {item}: the note has no duration"),
            RefitErrorKind::TwoStems { item } => write!(f, "item {item}: the chord has two stems"),
            RefitErrorKind::Unsupported(what) => write!(f, "{what} is not supported"),
        }
    }
}

/// A refit the engine gave up on; `items` are as the engine leaves them (beam ends it had
/// already moved onto their notes stay moved).
#[derive(Debug, Clone, PartialEq)]
pub struct RefitError {
    pub kind: RefitErrorKind,
    pub items: Vec<Item>,
}

impl std::fmt::Display for RefitError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        self.kind.fmt(f)
    }
}

impl std::error::Error for RefitError {}

/// Refits stems, beams and slurs of the notes on `staff` with P3 in `area`; returns the
/// items in the same order.
pub fn refit(items: &[Item], staff: i32, area: (f32, f32), mode: RefitMode) -> Result<Vec<Item>, RefitError> {
    let mut rows: Vec<Vec<f32>> = items.iter().map(|item| item.params().iter().map(|w| w.as_f32()).collect()).collect();
    let outcome = Refit { rows: &mut rows, staff, left: area.0, right: area.1, mode }.run();
    let refitted: Vec<Item> = items.iter().zip(&rows).map(|(item, row)| rebuilt(item, row)).collect();
    match outcome {
        Ok(()) => Ok(refitted),
        Err(kind) => Err(RefitError { kind, items: refitted }),
    }
}

fn rebuilt(item: &Item, row: &[f32]) -> Item {
    let params: Vec<Word> = row.iter().copied().map(Word::from_f32).collect();
    if params == item.params() {
        item.clone()
    } else {
        Item::new(params)
    }
}

fn set(row: &mut Vec<f32>, k: usize, value: f32) {
    if row.len() < k {
        row.resize(k, 0.0);
    }
    row[k - 1] = value;
}

fn near(a: f32, b: f32, within: f32) -> bool {
    (f64::from(a) - f64::from(b)).abs() <= f64::from(within)
}

/// A beam taken into the refit.
struct BeamItem {
    row: usize,
    /// It continues the previous beam (same P3): a further item of one group.
    segment: bool,
    /// Its parameters before the refit; segments are put back from them.
    saved: Vec<f32>,
}

/// What the scan of the staff found.
#[derive(Default)]
struct Found {
    /// (P3, row) of every note, in item order.
    notes: Vec<(f32, usize)>,
    beams: Vec<BeamItem>,
    slurs: Vec<usize>,
}

struct Refit<'a> {
    rows: &'a mut [Vec<f32>],
    staff: i32,
    left: f32,
    right: f32,
    mode: RefitMode,
}

impl Refit<'_> {
    fn run(&mut self) -> Result<(), RefitErrorKind> {
        let found = self.scan()?;
        if found.notes.is_empty() {
            return Ok(());
        }
        let stream = Stream::build(self.rows, &found.notes, self.mode)?;
        let mut line = stream.line(self.staff, (self.left, self.right));
        let unsupported = |_| RefitErrorKind::Unsupported("a stored mark");
        let chords = stream.chord_xs.len() as u32;
        let stored: Vec<_> = stream.marks.iter().map(|&(code, number)| marks::stored(code, (number as u32).min(chords))).collect();
        marks::apply(&mut line, &stored).map_err(unsupported)?;
        let beam_rows: Vec<usize> = found.beams.iter().map(|b| b.row).collect();
        let beam_pairs = note_pairs(self.rows, &beam_rows, &stream.chord_xs, Pass::Beams);
        beams::apply(&mut line, &beam_pairs).map_err(|_| RefitErrorKind::Unsupported("a beam"))?;
        // Mode 2 (FLN, TR) leaves the slurs as they are.
        let slur_rows = if self.mode == RefitMode::Normal { Vec::new() } else { found.slurs.clone() };
        let slur_pairs = note_pairs(self.rows, &slur_rows, &stream.chord_xs, Pass::Slurs);
        slurs::apply(&mut line, &slur_pairs, (self.left, self.right)).map_err(|_| RefitErrorKind::Unsupported("a slur"))?;
        self.write_back(&line, &stream.order, &found.beams, &slur_rows)
    }

    /// The notes, beams and slurs of the staff within the area, in item order; the scan
    /// stops at the first item right of the area.
    fn scan(&mut self) -> Result<Found, RefitErrorKind> {
        let mut found = Found::default();
        let mut previous_beam_x: Option<f32> = None;
        for i in 0..self.rows.len() {
            let row = &self.rows[i];
            let x = if row.len() > 2 { row[2] } else { 0.0 };
            let code = trunc(par(row, 1));
            if trunc(par(row, 2)) != self.staff || x < self.left || code == TEXT {
                continue;
            }
            if x > self.right {
                break;
            }
            match code {
                BEAM if row.len() > 6 => {
                    let segment = previous_beam_x == Some(x);
                    previous_beam_x = Some(x);
                    self.take_beam(i, segment, &mut found)?;
                }
                SLUR if slur_counts(row) => found.slurs.push(i),
                NOTE => {
                    if found.notes.len() >= MAX_NOTES {
                        return Err(RefitErrorKind::TooManyNotes);
                    }
                    // Notes moved sideways by a P10 that is not 10 or 20 stay out.
                    if row.len() <= 9 || amod(par(row, 10), 10.0) == 0.0 {
                        found.notes.push((x, i));
                    }
                }
                _ => {}
            }
        }
        Ok(found)
    }

    /// Checks a beam and moves its ends onto the notes they are at.
    fn take_beam(&mut self, i: usize, segment: bool, found: &mut Found) -> Result<(), RefitErrorKind> {
        let saved = self.rows[i].clone();
        let (x, end) = (par(&saved, 3), par(&saved, 6));
        if par(&saved, 7) < 0.0 {
            return Err(RefitErrorKind::TremoloBeam { item: i });
        }
        if end > self.right {
            return Err(RefitErrorKind::BeamPastArea { item: i });
        }
        // Counts found ends: 1 per note at the start, 50 for the end; both found at 51.
        let mut ends = 0;
        for j in 0..self.rows.len() {
            let note = &self.rows[j];
            if par(note, 1) != 1.0 || trunc(par(note, 2)) != trunc(par(&saved, 2)) {
                continue;
            }
            let note_x = if note.len() >= 3 { note[2] } else { 0.0 };
            let value = par(note, 7);
            if near(note_x, x, SNAP) {
                set(&mut self.rows[i], 3, note_x);
                ends = (ends + 1).min(51);
            } else if near(note_x, end, SNAP) {
                set(&mut self.rows[i], 6, note_x);
                if ends < 50 {
                    ends += 50;
                }
            } else {
                continue;
            }
            if (BEAMABLE..GRACE).contains(&value) {
                return Err(RefitErrorKind::LongNoteUnderBeam { item: j });
            }
            if ends > 50 {
                break;
            }
        }
        found.beams.push(BeamItem { row: i, segment, saved });
        Ok(())
    }

    /// 0x47C3E8's write-back: every note takes the P4, P5 and P8 to P11 of the entry at its
    /// place, the beams and slurs those of the new item with their P3.
    fn write_back(&mut self, line: &Line, order: &[usize], beams: &[BeamItem], slurs: &[usize]) -> Result<(), RefitErrorKind> {
        let produced = line.items();
        if produced.len() < order.len() || produced[..order.len()].iter().any(|it| it.code() != NOTE) {
            return Err(RefitErrorKind::Unsupported("a chord the line model splits"));
        }
        let (notes, attached) = produced.split_at(order.len());
        for (&row, made) in order.iter().zip(notes) {
            let row = &mut self.rows[row];
            if row.len() < NOTE_WORDS {
                row.resize(NOTE_WORDS, 0.0);
            }
            for k in WRITTEN {
                row[k - 1] = made.param(k);
            }
        }
        let beam_rows: Vec<usize> = beams.iter().map(|b| b.row).collect();
        let made_beams: Vec<&Item> = attached.iter().filter(|it| it.code() == BEAM).collect();
        self.take_over(&beam_rows, &made_beams, |row, made| {
            let direction = trunc(made.param(7) / 10.0) * 10;
            set(row, 7, (f64::from(amod(par(row, 7), 10.0)) + f64::from(direction)) as f32);
        });
        let made_slurs: Vec<&Item> = attached.iter().filter(|it| it.code() == SLUR).collect();
        self.take_over(slurs, &made_slurs, |row, made| set(row, 7, made.param(7)));
        // The engine's counter for this is the number of new beams, plus the number of notes
        // when it refitted slurs.
        if !made_beams.is_empty() || !slurs.is_empty() {
            self.restore_segments(beams);
            // 0x40CDE4, over every beam of the staff, also those outside the area.
            stems::fit(self.rows, self.staff, self.staff_step());
        }
        Ok(())
    }

    /// 0x47E0A9: the items in `rows` take P4 and P5 (and P7 through `seventh`) of the new
    /// items in turn, each from the next new item that starts at their P3.
    fn take_over(&mut self, rows: &[usize], made: &[&Item], seventh: impl Fn(&mut Vec<f32>, &Item)) {
        let mut made = made.iter().peekable();
        for &i in rows {
            let Some(item) = made.next_if(|item| item.param(3) == par(&self.rows[i], 3)) else {
                continue;
            };
            let row = &mut self.rows[i];
            set(row, 5, item.param(5));
            set(row, 4, item.param(4));
            seventh(row, item);
        }
    }

    /// The further items of a beam group get back their own parameters with the group's
    /// new P4, P5 and direction; so does the first, whose ends move back where they were.
    /// The engine reads one entry past its list there, which holds 0 in a fresh engine, so
    /// a last beam reached right after a group is put back too.
    fn restore_segments(&mut self, beams: &[BeamItem]) {
        let n = beams.len();
        let continued = |e: usize| e + 1 > n || beams[e].segment;
        let mut e = 0;
        loop {
            e += 1;
            if e >= n {
                return;
            }
            while continued(e) {
                let head = beams[e - 1].row;
                let direction = trunc(par(&self.rows[head], 7) / 10.0);
                let (p4, p5) = (par(&self.rows[head], 4), par(&self.rows[head], 5));
                if direction >= 0 {
                    self.restore(&beams[e - 1], direction, (p4, p5));
                }
                loop {
                    e += 1;
                    if e > n {
                        return;
                    }
                    if !beams[e - 1].segment {
                        break;
                    }
                    if direction >= 0 {
                        self.restore(&beams[e - 1], direction, (p4, p5));
                    }
                }
            }
        }
    }

    /// The staff step (25 for a staff of normal size) from the staff item.
    fn staff_step(&self) -> f32 {
        let staff_item = self.rows.iter().find(|r| trunc(par(r, 1)) == STAFF && trunc(par(r, 2)) == self.staff);
        let size = staff_item.map_or(0.0, |r| if par(r, 14) != 0.0 { par(r, 14) / 0.889 } else { par(r, 5) });
        25.0 * if size != 0.0 { size } else { 1.0 }
    }

    fn restore(&mut self, beam: &BeamItem, direction: i32, (p4, p5): (f32, f32)) {
        let row = &mut self.rows[beam.row];
        *row = beam.saved.clone();
        set(row, 7, (trunc(par(&beam.saved, 7)) % 10 + direction * 10) as f32);
        set(row, 4, p4);
        set(row, 5, p5);
    }
}

/// Slurs with P8 = 1 or 2 (dashed, dotted) and slurs with P7 = 0 are left alone.
fn slur_counts(row: &[f32]) -> bool {
    let kind = trunc(par(row, 8));
    !(row.len() < 7 || (row.len() != 7 && (kind == 1 || kind == 2)) || par(row, 7) == 0.0)
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Pass {
    Beams,
    Slurs,
}

/// 0x47DC96: the note numbers of each beam or slur, found by truncated position: the last
/// chord within 2 of the start, and the last other chord within 2 of the end. A beam
/// whose ends are not both found is reported and left out; for a slur the missing numbers
/// (0, or one past the last chord) go to the slur pass. Further beam items with the same
/// start are skipped, and a pair equal to the one before is sent once.
fn note_pairs(rows: &[Vec<f32>], items: &[usize], chord_xs: &[f32], pass: Pass) -> Vec<ConnectEntry> {
    let past_last = chord_xs.len() + 1;
    let mut pairs = Vec::new();
    let mut last_pair = None;
    let mut previous_start = -1;
    for &i in items {
        let start = trunc(par(&rows[i], 3));
        if pass == Pass::Beams && start == previous_start {
            continue;
        }
        previous_start = start;
        let end = trunc(par(&rows[i], 6));
        let (mut first, mut second) = (0, past_last);
        for (j, &x) in chord_xs.iter().enumerate() {
            let at = trunc(x);
            if (start - at).abs() < 2 {
                first = j + 1;
            } else if (end - at).abs() < 2 {
                second = j + 1;
            }
        }
        if last_pair == Some((first, second)) {
            continue;
        }
        if pass == Pass::Beams && (first == 0 || second == past_last) {
            continue;
        }
        pairs.push(ConnectEntry::Pair(Connection::new(first, second)));
        last_pair = Some((first, second));
    }
    pairs
}

/// The input the refit sends to passes 1 to 3.
struct Stream {
    events: Vec<Event>,
    /// One rhythm per chord.
    rhythms: Vec<Rhythm>,
    /// (P11 code, note number) of the stored marks.
    marks: Vec<(i32, usize)>,
    /// P3 of every chord.
    chord_xs: Vec<f32>,
    /// The note rows in stream order: the stem head of a chord moved first when needed.
    order: Vec<usize>,
    /// Chords with a stem code between their notes: (chord number from 0, notes before the
    /// code, all notes in stream order).
    interrupted: Vec<(usize, usize, Vec<Head>)>,
}

impl Stream {
    /// The stream 0x47C3E8 builds from the notes (P3, row) in item order.
    fn build(rows: &[Vec<f32>], notes: &[(f32, usize)], mode: RefitMode) -> Result<Stream, RefitErrorKind> {
        let mut stream = Stream {
            events: Vec::new(),
            rhythms: Vec::new(),
            marks: Vec::new(),
            chord_xs: Vec::new(),
            order: notes.iter().map(|n| n.1).collect(),
            interrupted: Vec::new(),
        };
        let mut chord_event = 0;
        let mut previous_x = 0.0f32;
        let mut stem_seen = false;
        let mut chord_number = 1;
        let mut cue = false;
        for (k, &(x, _)) in notes.iter().enumerate() {
            let p5 = loop {
                let row = &rows[stream.order[k]];
                if row.len() < 5 {
                    break 0;
                }
                let p5 = trunc(par(row, 5));
                if p5 > 100 {
                    return Err(RefitErrorKind::Unsupported("P5 above 100"));
                }
                let member = previous_x == x;
                if p5 % 100 > 9 {
                    if stem_seen && member {
                        return Err(RefitErrorKind::TwoStems { item: stream.order[k] });
                    }
                    stem_seen = true;
                    if let Some(stems) = stem_code(mode, p5 % 100) {
                        if member {
                            stream.interrupt(chord_event);
                        }
                        stream.events.push(Event::Stems(stems));
                    }
                    stream.take_mark(row, chord_number)?;
                    break p5 % 100;
                }
                let head = trunc(par(row, 6));
                let open_head = row.len() > 5 && head > 1 && (head < 4 || (head != 95 && head != 139 && head > 10));
                if member || open_head {
                    stream.take_mark(row, chord_number)?;
                    break p5 % 100;
                }
                // A chord starting with a stemless note: its stem head comes first.
                let stem_head = (k + 1..notes.len())
                    .map(|m| (m, &rows[stream.order[m]]))
                    .take_while(|(_, other)| par(other, 3) == x)
                    .find(|(_, other)| other.len() >= 5 && amod(par(other, 5), 100.0) >= 10.0)
                    .map(|(m, _)| m);
                let Some(m) = stem_head else {
                    return Err(RefitErrorKind::NoStem { item: stream.order[k] });
                };
                stream.order.swap(k, m);
                previous_x = 0.0;
            };
            let row = &rows[stream.order[k]];
            let value = if row.len() > 6 { par(row, 7) } else { 0.0 };
            let level = trunc(par(row, 4));
            let member = previous_x == x;
            if value < GRACE {
                let small = level.abs() >= 100;
                if small != cue {
                    if member {
                        return Err(RefitErrorKind::Unsupported("a chord of cue and normal notes"));
                    }
                    stream.events.push(Event::Cue(small));
                    cue = small;
                }
            }
            let head = Head { level: level % 100, accidental: accidental(p5 % 10)? };
            if !(-27..=71).contains(&head.level) {
                return Err(RefitErrorKind::Unsupported("a note this far from the staff"));
            }
            if member {
                match stream.events.get_mut(chord_event) {
                    Some(Event::Chord(heads)) => heads.push(head),
                    _ => return Err(RefitErrorKind::Unsupported("a chord interrupted by a cue code")),
                }
            } else {
                chord_event = stream.events.len();
                stem_seen = false;
                let dots = if row.len() > 8 { (trunc(par(row, 9)) % 100) / 10 } else { 0 };
                if value == 0.0 {
                    return Err(RefitErrorKind::NoDuration { item: stream.order[k] });
                }
                if value < 0.0 {
                    return Err(RefitErrorKind::Unsupported("a negative duration"));
                }
                stream.events.push(Event::Chord(vec![head]));
                stream.rhythms.push(rhythm_of(value, dots));
                stream.chord_xs.push(x);
                chord_number += 1;
            }
            previous_x = x;
        }
        stream.record_interrupted();
        // Pass 1 sorts every chord from its lowest note up, keeping unisons in stream order.
        for event in &mut stream.events {
            if let Event::Chord(heads) = event {
                heads.sort_by_key(|h| h.level);
            }
        }
        Ok(stream)
    }

    /// Notes the place of a stem code inside the chord at `chord_event` (the first only).
    fn interrupt(&mut self, chord_event: usize) {
        let chord = self.events[..chord_event].iter().filter(|e| matches!(e, Event::Chord(_))).count();
        if let Some(Event::Chord(heads)) = self.events.get(chord_event) {
            if !self.interrupted.iter().any(|(c, _, _)| *c == chord) {
                self.interrupted.push((chord, heads.len(), Vec::new()));
            }
        }
    }

    /// The heads of every interrupted chord in stream order, before the sort.
    fn record_interrupted(&mut self) {
        let chords: Vec<&Vec<Head>> = self.events.iter().filter_map(|e| if let Event::Chord(h) = e { Some(h) } else { None }).collect();
        for (chord, _, heads) in &mut self.interrupted {
            heads.clone_from(chords[*chord]);
        }
    }

    /// A stored mark goes to the chord being numbered: for a chord's further notes that
    /// is already the next chord, as in the engine.
    fn take_mark(&mut self, row: &[f32], chord_number: usize) -> Result<(), RefitErrorKind> {
        let code = if row.len() > 10 { trunc(par(row, 11)) } else { 0 };
        if code.abs() >= FIRST_SYMBOL_MARK {
            return Err(RefitErrorKind::Unsupported("a P11 mark from code 45 on"));
        }
        if code != 0 {
            self.marks.push((code, chord_number));
        }
        Ok(())
    }

    fn line(&self, staff: i32, (left, right): (f32, f32)) -> Line {
        let mut rhythms = self.rhythms.iter().copied();
        let timed: Vec<Timed> = self
            .events
            .iter()
            .map(|event| Timed { event, rhythm: if event.is_rhythmic() { rhythms.next() } else { None } })
            .collect();
        let options = Options { staff: staff.clamp(0, 255) as u8, size: 1.0, begin: left, end: right, clef: Clef::Treble };
        let mut line = Line::new(&timed, &options);
        for (chord, run, heads) in &self.interrupted {
            if let Some(note) = line.note_mut(chord + 1) {
                note.set_pass1_chord(&heads[..*run], &heads[*run..]);
            }
        }
        line.lay_out_grace_chords_for_refit();
        line.place_notes(&self.chord_xs);
        line
    }
}

/// The stem code (5010 up, 5020 down) sent before a note with a stem, if any.
fn stem_code(mode: RefitMode, stem: i32) -> Option<StemMode> {
    match mode {
        RefitMode::Normal => None,
        RefitMode::Down => Some(StemMode::Down),
        RefitMode::Up => Some(StemMode::Up),
        RefitMode::Invert if stem < 20 => Some(StemMode::Down),
        RefitMode::Invert => Some(StemMode::Up),
    }
}

fn accidental(code: i32) -> Result<Option<Accidental>, RefitErrorKind> {
    Ok(match code {
        0 => None,
        1 => Some(Accidental::Flat),
        2 => Some(Accidental::Sharp),
        3 => Some(Accidental::Natural),
        4 => Some(Accidental::DoubleFlat),
        5 => Some(Accidental::DoubleSharp),
        _ => return Err(RefitErrorKind::Unsupported("an accidental code above 5")),
    })
}

/// The rhythm 0x51C64F reads from the value `dots * 1000 + P7` the refit sends.
fn rhythm_of(value: f32, dots: i32) -> Rhythm {
    if value >= GRACE {
        return Rhythm::Grace;
    }
    let sent = (dots * 1000) as f32 + value;
    let duration = amod(sent, 1000.0);
    let dots = trunc(sent / 100.0) / 10;
    let plain = if dots == 0 {
        duration
    } else {
        let scale = f64::from(2.0f32.powi(dots));
        (scale * f64::from(duration) / (scale * 2.0 - 1.0)) as f32
    };
    Rhythm::Value { per_whole: 4.0 / plain, dots: dots.clamp(0, 255) as u8 }
}
