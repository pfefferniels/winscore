//! Pass 1: notes, rests, barlines, clefs, key signatures, meters and the switches between them.
//!
//! Syntax as documented in WinScore's help ("Computer Keyboard Input") and observed in the
//! engine: entries are separated by `/`, chord notes by `:` or `'`; an empty entry repeats
//! the previous note, chord or rest (without accidentals).

use crate::error::{ErrorKind, InputError, Pass};
use crate::motives::Motives;
use crate::scan::{entries, recall_parts, Cursor, Entry};

const PASS: Pass = Pass::Notes;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Letter {
    C,
    D,
    E,
    F,
    G,
    A,
    B,
}

impl Letter {
    fn from_byte(byte: u8) -> Option<Self> {
        Some(match byte {
            b'C' => Letter::C,
            b'D' => Letter::D,
            b'E' => Letter::E,
            b'F' => Letter::F,
            b'G' => Letter::G,
            b'A' => Letter::A,
            b'B' => Letter::B,
            _ => return None,
        })
    }

    /// Diatonic step within the octave, C = 0.
    pub fn step(self) -> i32 {
        self as i32
    }

    pub fn from_step(step: i32) -> Self {
        [Letter::C, Letter::D, Letter::E, Letter::F, Letter::G, Letter::A, Letter::B][step.rem_euclid(7) as usize]
    }
}

/// Accidentals, numbered as in the right digit of a note's P5.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Accidental {
    Flat = 1,
    Sharp = 2,
    Natural = 3,
    DoubleFlat = 4,
    DoubleSharp = 5,
}

impl Accidental {
    pub fn code(self) -> i32 {
        self as i32
    }
}

/// How a note without an octave number finds its octave.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum OctaveMode {
    /// `O`: keep the current octave.
    Ordinary,
    /// `P`: take the octave that gives the smallest step from the previous note.
    Proximity,
}

/// Up or down from the previous note (`U`/`J`), or the octave added to a dyad (`+`/`-`).
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Direction {
    Up,
    Down,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct NoteName {
    pub mode: Option<OctaveMode>,
    pub letter: Letter,
    pub accidental: Option<Accidental>,
    /// `(` before the accidental: drawn in parentheses.
    pub cautionary: bool,
    pub octave: Option<u8>,
    /// `U`/`J`: the nearest note of this letter above or below the previous note.
    pub jump: Option<Direction>,
    /// `+`/`-`: the note together with its octave above or below.
    pub dyad: Option<Direction>,
}

impl NoteName {
    pub fn new(letter: Letter, accidental: Option<Accidental>, octave: Option<u8>) -> Self {
        NoteName { mode: None, letter, accidental, cautionary: false, octave, jump: None, dyad: None }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum RestKind {
    Normal,
    Up,
    Down,
    /// `RW`: a whole rest centred in its measure.
    Whole,
    Invisible,
    /// `RF`: with a fermata.
    Fermata,
    /// `RP`: a measure-repeat sign centred in its measure.
    RepeatSign,
    /// `Rn`: a whole rest centred in its measure with the number n above it.
    Measures(u8),
}

/// Barline types, numbered as in a barline's P5.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum BarStyle {
    Single = 0,
    Double = 1,
    Heavy = 2,
    LeftRepeat = 3,
    RightRepeat = 4,
    DoubleRepeat = 5,
    Dashed = 7,
}

impl BarStyle {
    pub fn code(self) -> i32 {
        self as i32
    }
}

/// Clefs, numbered as in a clef's P5.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Clef {
    Treble = 0,
    Bass = 1,
    Alto = 2,
    Tenor = 3,
    Percussion = 4,
}

impl Clef {
    pub fn code(self) -> i32 {
        self as i32
    }

    /// The clef of a clef item's P5 (treble for codes it does not know).
    pub fn from_code(code: i32) -> Self {
        match code {
            1 => Clef::Bass,
            2 => Clef::Alto,
            3 => Clef::Tenor,
            4 => Clef::Percussion,
            _ => Clef::Treble,
        }
    }

    /// Scale steps from a pitch's treble-clef level to its level on this clef's staff.
    pub fn level_offset(self) -> i32 {
        match self {
            Clef::Treble | Clef::Percussion => 0,
            Clef::Bass => 12,
            Clef::Alto => 6,
            Clef::Tenor => 8,
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct KeySignature {
    pub count: u8,
    pub sharps: bool,
    pub naturals: bool,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Meter {
    Common,
    Cut,
    Fraction(u16, u16),
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum StemMode {
    Up,
    Down,
    Ordinary,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum StaffShift {
    Main,
    Above,
    Below,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct Bar {
    pub style: BarStyle,
    pub invisible: bool,
    /// Staves spanned; the previous barline's number when none is typed.
    pub staves: Option<u8>,
}

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub enum NoteEntry {
    Chord(Vec<NoteName>),
    Rest { kind: RestKind, count: u32 },
    Bar(Bar),
    Clef(Clef),
    /// `-TR`, `-BA`, ...: later notes are read in this clef; the staff's clef stays.
    InputClef(Clef),
    Key(KeySignature),
    Meter(Meter),
    Stems(StemMode),
    Staff(StaffShift),
    /// `Q+` cue-size notes from here on, `Q-` or `Q0` normal ones again.
    Cue(bool),
    /// `Xn m` / `Zn m`: the last `items` entries are repeated so that they occur `times` times.
    Repeat { items: u32, times: u32, keep_accidentals: bool },
    /// An empty entry.
    RepeatPrevious,
    /// `.` (accidentals dropped) or `..` (kept): the last chord again, across rests and barlines.
    RepeatChord { keep_accidentals: bool },
    /// `@Xn`: motive X again, transposed by n steps.
    Recall { name: char, steps: i32 },
}

#[derive(Debug, Clone, PartialEq)]
pub struct Spanned<T> {
    pub value: T,
    pub entry: usize,
    pub span: crate::Span,
    /// The motive this entry defines, if it stands between `X[` and `]`.
    pub motive: Option<char>,
}

pub fn parse(text: &str, motives: &mut Motives) -> Result<Vec<Spanned<NoteEntry>>, InputError> {
    entries(text, PASS, motives)?
        .iter()
        .enumerate()
        .map(|(index, entry)| Ok(Spanned { value: parse_entry(entry)?, entry: index, span: entry.span(), motive: entry.motive }))
        .collect()
}

fn parse_entry(entry: &Entry) -> Result<NoteEntry, InputError> {
    let mut c = entry.cursor(PASS);
    if c.at_end() {
        return Ok(NoteEntry::RepeatPrevious);
    }
    if let Some((name, steps)) = recall_parts(&entry.text) {
        return Ok(NoteEntry::Recall { name, steps });
    }
    let parsed = word_entry(&mut c).transpose().unwrap_or_else(|| chord(&mut c))?;
    c.finish()?;
    Ok(parsed)
}

/// Entries introduced by a fixed word; checked before note letters because `BA`, `AL`, `CUT`
/// and `COM` start with one.
fn word_entry(c: &mut Cursor) -> Result<Option<NoteEntry>, InputError> {
    const WORDS: [(&str, NoteEntry); 13] = [
        ("COM", NoteEntry::Meter(Meter::Common)),
        ("CUT", NoteEntry::Meter(Meter::Cut)),
        ("SU", NoteEntry::Stems(StemMode::Up)),
        ("SD", NoteEntry::Stems(StemMode::Down)),
        ("SO", NoteEntry::Stems(StemMode::Ordinary)),
        ("S+", NoteEntry::Staff(StaffShift::Above)),
        ("S-", NoteEntry::Staff(StaffShift::Below)),
        ("S0", NoteEntry::Staff(StaffShift::Main)),
        ("Q+", NoteEntry::Cue(true)),
        ("Q-", NoteEntry::Cue(false)),
        ("Q0", NoteEntry::Cue(false)),
        ("..", NoteEntry::RepeatChord { keep_accidentals: true }),
        (".", NoteEntry::RepeatChord { keep_accidentals: false }),
    ];
    if let Some(clef) = clef(c) {
        return Ok(Some(NoteEntry::Clef(clef)));
    }
    if c.eat(b'-') {
        return clef(c).map(|clef| Some(NoteEntry::InputClef(clef))).ok_or_else(|| c.unexpected());
    }
    if let Some((_, entry)) = WORDS.iter().find(|(word, _)| c.eat_word(word)) {
        return Ok(Some(entry.clone()));
    }
    match c.peek() {
        Some(b'R') => rest(c).map(Some),
        Some(b'M') => Ok(Some(NoteEntry::Bar(bar(c)))),
        Some(b'K') => key(c).map(Some),
        Some(b'X' | b'Z') => repeat(c).map(Some),
        Some(b'0'..=b'9') => meter(c).map(Some),
        _ => Ok(None),
    }
}

fn clef(c: &mut Cursor) -> Option<Clef> {
    const CLEFS: [(&str, Clef); 5] = [
        ("TR", Clef::Treble),
        ("BA", Clef::Bass),
        ("AL", Clef::Alto),
        ("TE", Clef::Tenor),
        ("PR", Clef::Percussion),
    ];
    CLEFS.iter().find(|(word, _)| c.eat_word(word)).map(|(_, clef)| *clef)
}

fn rest(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    c.bump();
    const KINDS: [(u8, RestKind); 6] = [
        (b'U', RestKind::Up),
        (b'D', RestKind::Down),
        (b'W', RestKind::Whole),
        (b'I', RestKind::Invisible),
        (b'F', RestKind::Fermata),
        (b'P', RestKind::RepeatSign),
    ];
    let kind = match KINDS.iter().find(|(letter, _)| c.eat(*letter)) {
        Some((_, kind)) => *kind,
        None => match c.integer() {
            Some(n) => RestKind::Measures(u8::try_from(n).map_err(|_| c.error_here(ErrorKind::OutOfRange("measures".into())))?),
            None => RestKind::Normal,
        },
    };
    let count = if c.eat(b'X') { c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))? } else { 1 };
    Ok(NoteEntry::Rest { kind, count })
}

fn bar(c: &mut Cursor) -> Bar {
    c.bump();
    const STYLES: [(&str, BarStyle); 6] = [
        ("RD", BarStyle::DoubleRepeat),
        ("D", BarStyle::Double),
        ("H", BarStyle::Heavy),
        ("L", BarStyle::LeftRepeat),
        ("R", BarStyle::RightRepeat),
        ("S", BarStyle::Dashed),
    ];
    let invisible = c.eat(b'I');
    let style = STYLES.iter().find(|(word, _)| c.eat_word(word)).map_or(BarStyle::Single, |(_, style)| *style);
    let staves = c.integer().map(|n| n.min(u32::from(u8::MAX)) as u8);
    Bar { style, invisible, staves }
}

fn key(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    c.bump();
    let count = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    if !(1..=7).contains(&count) {
        return Err(c.error_here(ErrorKind::OutOfRange("number of accidentals".into())));
    }
    let sharps = match c.bump() {
        Some(b'S') => true,
        Some(b'F') => false,
        _ => return Err(c.unexpected()),
    };
    let naturals = c.eat(b'N');
    Ok(NoteEntry::Key(KeySignature { count: count as u8, sharps, naturals }))
}

fn meter(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    let top = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    c.skip_spaces();
    let bottom = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    let fit = |n: u32| u16::try_from(n).map_err(|_| c.error_here(ErrorKind::OutOfRange("meter".into())));
    Ok(NoteEntry::Meter(Meter::Fraction(fit(top)?, fit(bottom)?)))
}

fn repeat(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    let keep_accidentals = c.bump() == Some(b'Z');
    let items = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    c.skip_spaces();
    let times = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    Ok(NoteEntry::Repeat { items, times, keep_accidentals })
}

fn chord(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    let mut notes = vec![note(c)?];
    while c.eat(b':') || c.eat(b'\'') {
        notes.push(note(c)?);
    }
    Ok(NoteEntry::Chord(notes))
}

fn note(c: &mut Cursor) -> Result<NoteName, InputError> {
    let mode = if c.eat(b'P') {
        Some(OctaveMode::Proximity)
    } else if c.eat(b'O') {
        Some(OctaveMode::Ordinary)
    } else {
        None
    };
    let byte = c.peek().ok_or_else(|| c.unexpected())?;
    let letter = Letter::from_byte(byte).ok_or_else(|| c.unexpected())?;
    c.bump();
    let cautionary = c.eat(b'(');
    let accidental = if cautionary { accidental(c) } else { repeated_letter(c, byte).or_else(|| accidental(c)) };
    let octave = c.digit();
    if octave.is_some_and(|o| o > 8) {
        return Err(c.error_here(ErrorKind::OutOfRange("octave".into())));
    }
    let jump = direction(c, b'U', b'J');
    let dyad = direction(c, b'+', b'-');
    Ok(NoteName { mode, letter, accidental, cautionary, octave, jump, dyad })
}

fn direction(c: &mut Cursor, up: u8, down: u8) -> Option<Direction> {
    if c.eat(up) {
        Some(Direction::Up)
    } else if c.eat(down) {
        Some(Direction::Down)
    } else {
        None
    }
}

/// The letter typed again: twice a flat, three times a sharp, four times a natural.
fn repeated_letter(c: &mut Cursor, letter: u8) -> Option<Accidental> {
    let repeats = (0..3).take_while(|&ahead| c.peek_at(ahead) == Some(letter)).count();
    let accidental = match repeats {
        1 => Accidental::Flat,
        2 => Accidental::Sharp,
        3 => Accidental::Natural,
        _ => return None,
    };
    c.skip(repeats);
    Some(accidental)
}

fn accidental(c: &mut Cursor) -> Option<Accidental> {
    if c.eat_word("FF") {
        Some(Accidental::DoubleFlat)
    } else if c.eat_word("SS") {
        Some(Accidental::DoubleSharp)
    } else if c.eat(b'F') {
        Some(Accidental::Flat)
    } else if c.eat(b'S') {
        Some(Accidental::Sharp)
    } else if c.eat(b'N') {
        Some(Accidental::Natural)
    } else {
        None
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn values(text: &str) -> Vec<NoteEntry> {
        parse(text, &mut Motives::new()).unwrap().into_iter().map(|s| s.value).collect()
    }

    #[test]
    fn notes_chords_and_words() {
        let parsed = values("C4/BF3:D/BA/K2S/3 4/RUX3/M2/;");
        assert_eq!(parsed.len(), 8);
        assert!(matches!(parsed[1], NoteEntry::Chord(ref notes) if notes.len() == 2
            && notes[0].accidental == Some(Accidental::Flat) && notes[0].octave == Some(3)));
        assert_eq!(parsed[2], NoteEntry::Clef(Clef::Bass));
        assert_eq!(parsed[3], NoteEntry::Key(KeySignature { count: 2, sharps: true, naturals: false }));
        assert_eq!(parsed[4], NoteEntry::Meter(Meter::Fraction(3, 4)));
        assert_eq!(parsed[5], NoteEntry::Rest { kind: RestKind::Up, count: 3 });
        assert_eq!(parsed[6], NoteEntry::Bar(Bar { style: BarStyle::Single, invisible: false, staves: Some(2) }));
        assert_eq!(parsed[7], NoteEntry::RepeatPrevious);
    }

    #[test]
    fn empty_pass_has_no_entries() {
        assert!(values(";").is_empty());
    }

    #[test]
    fn errors_point_at_the_entry() {
        let err = parse("C4/Q/D;", &mut Motives::new()).unwrap_err();
        assert_eq!(err.span.start, 3);
        assert!(parse("C4/D", &mut Motives::new()).is_err());
    }
}
