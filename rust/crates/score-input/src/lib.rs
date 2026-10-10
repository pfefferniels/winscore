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

/// The items for one line of input, in the order the engine creates them (staff item not included).
pub fn run(passes: &Passes, options: &Options) -> Result<Vec<Item>, InputError> {
    run_with_motives(passes, options, &mut Motives::new())
}

/// As [`run`], with motives kept from earlier lines and stored for later ones.
pub fn run_with_motives(passes: &Passes, options: &Options, motives: &mut Motives) -> Result<Vec<Item>, InputError> {
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
    Ok(stems::fit_items(&line.items(), i32::from(options.staff), 25.0 * options.size, options.neighbours))
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
