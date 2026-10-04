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

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct NoteName {
    pub mode: Option<OctaveMode>,
    pub letter: Letter,
    pub accidental: Option<Accidental>,
    pub octave: Option<u8>,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum RestKind {
    Normal,
    Up,
    Down,
    Whole,
    Invisible,
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

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub enum NoteEntry {
    Chord(Vec<NoteName>),
    Rest { kind: RestKind, count: u32 },
    Bar { staves: Option<u8> },
    Clef(Clef),
    Key(KeySignature),
    Meter(Meter),
    Stems(StemMode),
    Staff(StaffShift),
    /// `Xn m` / `Zn m`: the last `items` entries are repeated so that they occur `times` times.
    Repeat { items: u32, times: u32, keep_accidentals: bool },
    /// An empty entry.
    RepeatPrevious,
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
    const CLEFS: [(&str, Clef); 5] = [
        ("TR", Clef::Treble),
        ("BA", Clef::Bass),
        ("AL", Clef::Alto),
        ("TE", Clef::Tenor),
        ("PR", Clef::Percussion),
    ];
    const WORDS: [(&str, NoteEntry); 8] = [
        ("COM", NoteEntry::Meter(Meter::Common)),
        ("CUT", NoteEntry::Meter(Meter::Cut)),
        ("SU", NoteEntry::Stems(StemMode::Up)),
        ("SD", NoteEntry::Stems(StemMode::Down)),
        ("SO", NoteEntry::Stems(StemMode::Ordinary)),
        ("S+", NoteEntry::Staff(StaffShift::Above)),
        ("S-", NoteEntry::Staff(StaffShift::Below)),
        ("S0", NoteEntry::Staff(StaffShift::Main)),
    ];
    if let Some((_, clef)) = CLEFS.iter().find(|(word, _)| c.eat_word(word)) {
        return Ok(Some(NoteEntry::Clef(*clef)));
    }
    if let Some((_, entry)) = WORDS.iter().find(|(word, _)| c.eat_word(word)) {
        return Ok(Some(entry.clone()));
    }
    match c.peek() {
        Some(b'R') => rest(c).map(Some),
        Some(b'M') => {
            c.bump();
            Ok(Some(NoteEntry::Bar { staves: c.integer().map(|n| n.min(u32::from(u8::MAX)) as u8) }))
        }
        Some(b'K') => key(c).map(Some),
        Some(b'X' | b'Z') => repeat(c).map(Some),
        Some(b'0'..=b'9') => meter(c).map(Some),
        _ => Ok(None),
    }
}

fn rest(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    c.bump();
    let kind = match c.peek() {
        Some(b'U') => RestKind::Up,
        Some(b'D') => RestKind::Down,
        Some(b'W') => RestKind::Whole,
        Some(b'I') => RestKind::Invisible,
        _ => RestKind::Normal,
    };
    if kind != RestKind::Normal {
        c.bump();
    }
    let count = if c.eat(b'X') { c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))? } else { 1 };
    Ok(NoteEntry::Rest { kind, count })
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
    let letter = c.peek().and_then(Letter::from_byte).ok_or_else(|| c.unexpected())?;
    c.bump();
    let accidental = accidental(c);
    let octave = c.digit();
    if octave.is_some_and(|o| o > 8) {
        return Err(c.error_here(ErrorKind::OutOfRange("octave".into())));
    }
    Ok(NoteName { mode, letter, accidental, octave })
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
        assert_eq!(parsed[6], NoteEntry::Bar { staves: Some(2) });
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
