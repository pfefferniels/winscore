//! SCORE's staged music input: a line of music typed in five passes and turned into items.
//!
//! WinScore's `IN` command asks for a staff and an input range, then for five texts
//! (documented in Smith's help, "Computer Keyboard Input"):
//!
//! 1. notes, rests, barlines, clefs, key signatures, meters: `C4/D/E:G/R/M/BA/K2S/3 4;`
//! 2. rhythms, one per note, chord or rest: `4/8/8./12;`
//! 3. marks (accents, staccato, dynamics) on numbered notes: `A 1/S 2:4;`
//! 4. beams between numbered notes: `1 2/3 6;`
//! 5. slurs and ties between numbered notes: `1 4;`
//!
//! [`run`] converts them into the items the engine would create; the aim is the same items
//! with the same parameter values as WinScore 5.01, checked against the emulated engine.
//!
//! ```
//! use score_input::{run, Options, Passes};
//! let passes = Passes { notes: "C4/D/E/F;", rhythms: "4/4/4/4;", ..Passes::default() };
//! let items = run(&passes, &Options::default()).unwrap();
//! assert_eq!(items.len(), 4);
//! assert_eq!(items[1].param(3), 51.5);
//! ```

mod beams;
mod chords;
pub mod connect;
mod error;
mod events;
pub mod file;
mod line;
pub mod marks;
mod motives;
pub mod notes;
mod num;
mod reader;
mod refit;
pub mod rhythm;
mod scan;
mod slurs;
mod spacing;
mod staves;
mod stems;

use std::ops::Range;

use score_format::Item;

pub use error::{ErrorKind, InputError, Pass, Span};
pub use file::{InputFile, InputLine, StaffArgs, Step};
pub use motives::Motives;
pub use refit::{refit, refit_staves, RefitError, RefitErrorKind, RefitMode, StavesRefit};
pub use staves::{Neighbours, StaffPlace};

/// The texts of the five passes, each ending with `;`.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Passes<'a> {
    pub notes: &'a str,
    pub rhythms: &'a str,
    pub marks: &'a str,
    pub beams: &'a str,
    pub slurs: &'a str,
}

impl Default for Passes<'_> {
    fn default() -> Self {
        Self { notes: ";", rhythms: ";", marks: ";", beams: ";", slurs: ";" }
    }
}

/// Where the line goes: the staff (P2 of every item), its size factor (P5 of the staff
/// item, 1 for a normal staff), the input range in P3 units, the clef in force on the
/// staff when the line starts (the engine keeps the last clef of each staff), the staff's
/// right end (P6 of the staff item, 200 when 0), where slurs past the last note end, and the
/// distances to the staves above and below, for notes moved there (S+/S-).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Options {
    pub staff: u8,
    pub size: f32,
    pub begin: f32,
    pub end: f32,
    pub clef: notes::Clef,
    pub staff_end: f32,
    pub neighbours: Neighbours,
}

impl Default for Options {
    /// Staff 1 of normal size and full length in treble clef, and the range WinScore's input
    /// dialog proposes, 2 to 200.
    fn default() -> Self {
        Self {
            staff: 1,
            size: 1.0,
            begin: 2.0,
            end: 200.0,
            clef: notes::Clef::Treble,
            staff_end: slurs::STAFF_END,
            neighbours: Neighbours::defaults(1),
        }
    }
}

/// What one element of a line (a note or chord, rest, barline, clef, key signature or meter)
/// became, for showing a line while it is typed.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Outline {
    /// The element's items among those of the line.
    pub items: Range<usize>,
    /// Its number among the values of pass 2 (from 1), if it takes one.
    pub slot: Option<usize>,
    /// Its number in passes 3-5 (from 1), if it is a note or chord.
    pub note: Option<usize>,
}

/// How far pass 2 has got: the values it gives (`None` when its one value sets all notes)
/// and the notes, chords and rests of pass 1 that take one.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct RhythmCount {
    pub given: Option<usize>,
    pub needed: usize,
}

/// The items for one line of input, in the order the engine creates them (staff item not included).
pub fn run(passes: &Passes, options: &Options) -> Result<Vec<Item>, InputError> {
    run_with_motives(passes, options, &mut Motives::new())
}

/// As [`run`], with motives kept from earlier lines and stored for later ones.
pub fn run_with_motives(passes: &Passes, options: &Options, motives: &mut Motives) -> Result<Vec<Item>, InputError> {
    run_outlined(passes, options, motives).map(|(items, _)| items)
}

/// As [`run_with_motives`], with the outline of the line's elements, in order. Their items
/// come first, then those of passes 3-5.
pub fn run_outlined(
    passes: &Passes,
    options: &Options,
    motives: &mut Motives,
) -> Result<(Vec<Item>, Vec<Outline>), InputError> {
    let events = pass_one(passes.notes, options, motives)?;
    let needed = events.iter().filter(|e| e.is_rhythmic()).count();
    let rhythms = rhythm::parse(passes.rhythms, needed, motives)?;
    let marks = marks::parse(passes.marks, motives)?;
    let beams = connect::parse(passes.beams, Pass::Beams, motives)?;
    let slurs = connect::parse(passes.slurs, Pass::Slurs, motives)?;

    let mut rhythm_iter = rhythms.into_iter();
    let timed: Vec<line::Timed> = events
        .iter()
        .map(|event| line::Timed { event, rhythm: if event.is_rhythmic() { rhythm_iter.next() } else { None } })
        .collect();
    let mut line = line::Line::new(&timed, options);
    marks::apply(&mut line, &marks, (0.0, options.staff_end))?;
    beams::apply(&mut line, &beams)?;
    slurs::apply(&mut line, &slurs, (options.begin, options.end), options.staff_end)?;
    // 0x5253FD stores the line, then fits the stems to the beams in the item store.
    let items = stems::fit_items(&line.items(), i32::from(options.staff), 25.0 * options.size, options.neighbours);
    Ok((items, line.outline()))
}

/// The values pass 2 gives and needs for these passes, motives as `motives` holds them.
pub fn count_rhythms(passes: &Passes, options: &Options, motives: &Motives) -> Result<RhythmCount, InputError> {
    let mut motives = motives.clone();
    let events = pass_one(passes.notes, options, &mut motives)?;
    let needed = events.iter().filter(|e| e.is_rhythmic()).count();
    let given = rhythm::given(passes.rhythms, &mut motives)?;
    Ok(RhythmCount { given, needed })
}

/// Pass 1 as the reader leaves it; errors point into the typed text.
fn pass_one(text: &str, options: &Options, motives: &mut Motives) -> Result<Vec<events::Event>, InputError> {
    let read = reader::read(text);
    let in_typed_text = |err: InputError| InputError { span: read.origin_span(err.span), ..err };
    let entries = notes::parse(&read.text, motives).map_err(in_typed_text)?;
    events::resolve(&entries, options.clef, motives).map_err(in_typed_text)
}

/// The items of a pass-1 text that WinScore's reader erases as they are typed (it shows
/// "Input error" and removes the item; [`run`] leaves them out the same way), in that text.
pub fn erased_items(notes: &str) -> Vec<Span> {
    reader::read(notes).erased
}

#[cfg(test)]
mod tests {
    use super::*;

    fn passes<'a>(notes: &'a str, rhythms: &'a str) -> Passes<'a> {
        Passes { notes, rhythms, ..Passes::default() }
    }

    #[test]
    fn the_outline_numbers_elements_as_passes_2_to_5_do() {
        let (items, outline) =
            run_outlined(&passes("BA/C4:E/R/M/D;", "4;"), &Options::default(), &mut Motives::new()).unwrap();
        assert_eq!(items.len(), 6);
        let ranges: Vec<_> = outline.iter().map(|o| o.items.clone()).collect();
        assert_eq!(ranges, [0..1, 1..3, 3..4, 4..5, 5..6]);
        let slots: Vec<_> = outline.iter().map(|o| o.slot).collect();
        assert_eq!(slots, [None, Some(1), Some(2), None, Some(3)]);
        let notes: Vec<_> = outline.iter().map(|o| o.note).collect();
        assert_eq!(notes, [None, Some(1), None, None, Some(2)]);
    }

    #[test]
    fn attachments_follow_the_elements() {
        let passes = Passes { notes: "C4/D/E;", rhythms: "8;", beams: "1 3;", ..Passes::default() };
        let (items, outline) = run_outlined(&passes, &Options::default(), &mut Motives::new()).unwrap();
        assert_eq!(outline.last().unwrap().items.end, 3);
        assert_eq!(items[3].code(), 6);
    }

    #[test]
    fn rhythm_counts_tell_a_filling_value_from_a_list() {
        let count = |notes, rhythms| count_rhythms(&passes(notes, rhythms), &Options::default(), &Motives::new()).unwrap();
        assert_eq!(count("C4/D/R/M/E;", "4/8;"), RhythmCount { given: Some(2), needed: 4 });
        assert_eq!(count("C4/D/E;", "4;"), RhythmCount { given: None, needed: 3 });
        assert_eq!(count("C4/D/E;", ";"), RhythmCount { given: Some(0), needed: 3 });
        assert_eq!(count("C4/D/E;", "4X2/8;"), RhythmCount { given: Some(3), needed: 3 });
    }
}
