//! Pass 1: notes, rests, barlines, clefs, key signatures, meters and the switches between them.
//!
//! The item parser 0x4E2CC8 as analysis/engine/input.md ("Pass 1: notes") describes it. The
//! text has been through the reader (reader.rs), and scan.rs splits it into items; spaces
//! inside an item are passed over.

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

    fn byte(self) -> u8 {
        b"CDEFGAB"[self as usize]
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
    QuarterFlat = 6,
    ThreeQuarterFlat = 7,
    QuarterSharp = 8,
    ThreeQuarterSharp = 9,
}

impl Accidental {
    pub fn code(self) -> i32 {
        self as i32
    }

    pub fn from_code(code: i32) -> Option<Self> {
        use Accidental::*;
        [Flat, Sharp, Natural, DoubleFlat, DoubleSharp, QuarterFlat, ThreeQuarterFlat, QuarterSharp, ThreeQuarterSharp]
            .into_iter()
            .find(|a| a.code() == code)
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

/// Up or down: a jump (`U`/`J`), the octave added to a dyad (`+`/`-`), a rest moved off the
/// middle (`RU`/`RD`).
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum Direction {
    Up,
    Down,
}

/// An octave digit or a jump after the note letter; they act in the order typed, so `C4U`
/// is C5 and `CU4` is C4.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum OctaveMark {
    Digit(u8),
    Jump(Direction),
}

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub struct NoteName {
    pub mode: Option<OctaveMode>,
    pub letter: Letter,
    pub accidental: Option<Accidental>,
    /// `(`: the accidental is drawn in parentheses.
    pub cautionary: bool,
    pub octave: Vec<OctaveMark>,
    /// `+`/`-`: the note together with its octave above or below.
    pub dyad: Option<Direction>,
}

impl NoteName {
    pub fn new(letter: Letter) -> Self {
        NoteName { mode: None, letter, accidental: None, cautionary: false, octave: Vec::new(), dyad: None }
    }

    /// The octave number typed last, if the octave marks end with one.
    pub fn final_digit(&self) -> Option<u8> {
        match self.octave.last() {
            Some(OctaveMark::Digit(d)) => Some(*d),
            _ => None,
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub enum RestKind {
    Normal,
    /// `RW`: a whole rest centred in its measure.
    Whole,
    /// `RI`.
    Invisible,
    /// `RF`.
    Fermata,
    /// `RP`: a measure-repeat sign centred in its measure.
    RepeatSign,
    /// `Rn`: a rest for n measures with the number n above it: a whole rest centred in its
    /// measure, from four measures on a bar rest spread over the measure.
    Measures(u8),
}

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct Rest {
    pub kind: RestKind,
    /// `RU`, `RD`, `RFU`, `RFD`: six steps above or below the middle.
    pub shift: Option<Direction>,
}

impl Rest {
    pub fn new(kind: RestKind) -> Self {
        Rest { kind, shift: None }
    }
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
    /// Stored as a negative P4 and no P5.
    Invisible = 9,
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

/// `count` 0 (`K0S`) makes no item.
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
    /// P5 and P6 of the meter item; a single number n is stored as (0, n).
    Fraction(i32, i32),
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
    /// Staves spanned; the previous barline's number when none is typed.
    pub span: Option<u8>,
}

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub enum NoteEntry {
    Chord(Vec<NoteName>),
    Rest(Rest),
    Bar(Bar),
    Clef(Clef),
    /// `-TR`, `-BA`, ...: later notes are read in this clef; the staff's clef stays.
    InputClef(Clef),
    Key(KeySignature),
    Meter(Meter),
    /// `T`: the last meter typed (in this line or an earlier one) again.
    LastMeter,
    Stems(StemMode),
    Staff(StaffShift),
    /// `Q+` cue-size notes from here on, `Q-` or `Q0` normal ones again.
    Cue(bool),
    /// `Xn m`, `Zn m`, `REPn m`, or `Xn` after an item (n = 1): the last `items` items
    /// repeated so that there are `times` in all; `X` drops accidentals, `Z` keeps them.
    Repeat { items: u32, times: u32, keep_accidentals: bool },
    /// `=` (typed `.`, accidentals dropped) or `==` (typed `..`, kept): the item before the
    /// previous one again.
    RepeatChord { keep_accidentals: bool },
    /// `@Xn`: motive X again, transposed by n steps.
    Recall { name: char, steps: i32 },
    /// `Xn` without its count: the parser returns a token 0.
    ZeroToken,
}

#[derive(Debug, Clone, PartialEq)]
pub struct Spanned<T> {
    pub value: T,
    pub entry: usize,
    pub span: crate::Span,
    /// The motive this entry defines, if it stands between `X[` and `]`.
    pub motive: Option<char>,
}

/// The items of a pass-1 text as the reader leaves it (see reader.rs).
pub fn parse(text: &str, motives: &mut Motives) -> Result<Vec<Spanned<NoteEntry>>, InputError> {
    let parsed: Vec<Vec<Spanned<NoteEntry>>> = entries(text, PASS, motives)?
        .iter()
        .enumerate()
        .map(|(index, entry)| {
            let spanned = |value| Spanned { value, entry: index, span: entry.span(), motive: entry.motive };
            parse_entry(entry).map(|values| values.into_iter().map(spanned).collect())
        })
        .collect::<Result<_, _>>()?;
    Ok(parsed.into_iter().flatten().collect())
}

/// One item: usually one entry, two with a repeat suffix (`C4X3`).
fn parse_entry(entry: &Entry) -> Result<Vec<NoteEntry>, InputError> {
    if let Some((name, steps)) = recall_parts(&entry.text) {
        return Ok(vec![NoteEntry::Recall { name, steps: steps.round() as i32 }]);
    }
    check_repeat_letters(entry)?;
    let mut c = entry.spaced_cursor(PASS);
    if c.at_end() {
        return Ok(vec![NoteEntry::Repeat { items: 1, times: 2, keep_accidentals: false }]);
    }
    let first = c.peek().unwrap_or(b' ');
    let (value, suffix) = match first {
        b'A'..=b'G' => match note_word(&mut c) {
            Some(word) => (word, None),
            None => chord(&mut c)?,
        },
        b'O' => chord(&mut c)?,
        b'P' if c.peek_at(1) == Some(b'R') => (word(&mut c, 2, NoteEntry::Clef(Clef::Percussion)), None),
        b'P' => chord(&mut c)?,
        b'K' => (key(&mut c)?, None),
        b'M' => (NoteEntry::Bar(bar(&mut c)?), None),
        b'R' => rest(&mut c)?,
        b'S' => (switch(&mut c)?, None),
        b'T' => (t_item(&mut c)?, None),
        b'X' | b'Z' => (group_repeat(&mut c)?, None),
        b'-' => (input_clef(&mut c), None),
        b'=' | b'.' => (chord_repeat(&mut c)?, None),
        b'Q' => (cue(&mut c), None),
        b'0'..=b'9' => (meter(&mut c)?, None),
        _ => return Err(c.unexpected()),
    };
    c.finish()?;
    Ok(std::iter::once(value).chain(suffix).collect())
}

/// 0x524C4A: an `X` or `Z` must be followed by `[` or a digit 1-9.
fn check_repeat_letters(entry: &Entry) -> Result<(), InputError> {
    let bytes = entry.text.as_bytes();
    let bad = bytes
        .iter()
        .enumerate()
        .find(|&(i, &b)| matches!(b, b'X' | b'Z') && !matches!(bytes.get(i + 1), Some(b'[' | b'1'..=b'9')));
    match bad {
        Some((i, _)) => Err(InputError::new(PASS, crate::Span::at(entry.start + i), ErrorKind::Unexpected(char::from(bytes[i]).into()))),
        None => Ok(()),
    }
}

/// Consumes `len` characters and the rest of the item, which the parser ignores.
fn word(c: &mut Cursor, len: usize, entry: NoteEntry) -> NoteEntry {
    c.skip(len);
    c.skip_rest();
    entry
}

/// Items that start with a note letter: `BA`, `AL`, and `C?M`, `C?T` (common and cut time,
/// whatever the second character).
fn note_word(c: &mut Cursor) -> Option<NoteEntry> {
    let entry = match (c.peek(), c.peek_at(1), c.peek_at(2)) {
        (Some(b'B'), Some(b'A'), _) => NoteEntry::Clef(Clef::Bass),
        (Some(b'A'), Some(b'L'), _) => NoteEntry::Clef(Clef::Alto),
        (Some(b'C'), Some(_), Some(b'M')) => NoteEntry::Meter(Meter::Common),
        (Some(b'C'), Some(_), Some(b'T')) => NoteEntry::Meter(Meter::Cut),
        _ => return None,
    };
    Some(word(c, 0, entry))
}

/// A chord, notes separated by `:`; a repeat suffix on the last note repeats the chord.
fn chord(c: &mut Cursor) -> Result<(NoteEntry, Option<NoteEntry>), InputError> {
    let mut notes = Vec::new();
    loop {
        let (name, suffix) = note(c)?;
        notes.push(name);
        if suffix.is_some() || !c.eat(b':') {
            return Ok((NoteEntry::Chord(notes), suffix));
        }
    }
}

/// A note: `[O|P]letter`, then the suffix loop of 0x4E2CC8.
fn note(c: &mut Cursor) -> Result<(NoteName, Option<NoteEntry>), InputError> {
    let mut mode = None;
    while let Some(prefix) = octave_mode(c) {
        mode = Some(prefix);
    }
    let letter = c.peek().and_then(Letter::from_byte).ok_or_else(|| c.unexpected())?;
    c.bump();
    let mut name = NoteName { mode, ..NoteName::new(letter) };
    let mut accidental = 0;
    // Typing this letter again changes the accidental: the note letter, after an
    // accidental that accidental's letter.
    let mut repeated = letter.byte();
    loop {
        match c.peek() {
            None | Some(b':') => break,
            Some(next) if next == repeated => {
                c.bump();
                accidental += if repeated == letter.byte() { 1 } else { 3 };
                continue;
            }
            // Parentheses only before a letter accidental: `CF(` is rejected.
            Some(b'(') if repeated == letter.byte() => {
                c.bump();
                name.cautionary = true;
                continue;
            }
            Some(next @ (b'F' | b'S' | b'N')) => {
                c.bump();
                accidental = match next {
                    b'F' => 1,
                    b'S' => 2,
                    _ => 3,
                };
                repeated = next;
                continue;
            }
            Some(_) => {}
        }
        if let Some(digit) = c.digit() {
            name.octave.push(OctaveMark::Digit(digit));
        }
        if let Some(direction) = direction(c, b'+', b'-') {
            name.dyad = Some(direction);
        }
        if let Some(suffix) = repeat_suffix(c)? {
            name.accidental = accidental_code(c, accidental)?;
            return Ok((name, Some(suffix)));
        }
        match direction(c, b'U', b'J') {
            Some(jump) => name.octave.push(OctaveMark::Jump(jump)),
            None if c.at_end() || c.peek() == Some(b':') => break,
            None => return Err(c.unexpected()),
        }
    }
    name.accidental = accidental_code(c, accidental)?;
    Ok((name, None))
}

fn accidental_code(c: &Cursor, code: i32) -> Result<Option<Accidental>, InputError> {
    match code {
        0 => Ok(None),
        code => Accidental::from_code(code).map(Some).ok_or_else(|| c.error_here(ErrorKind::OutOfRange("accidental".into()))),
    }
}

fn octave_mode(c: &mut Cursor) -> Option<OctaveMode> {
    if c.eat(b'O') {
        Some(OctaveMode::Ordinary)
    } else if c.eat(b'P') {
        Some(OctaveMode::Proximity)
    } else {
        None
    }
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

/// `Xn` or `Zn` after an item: n of it in all.
fn repeat_suffix(c: &mut Cursor) -> Result<Option<NoteEntry>, InputError> {
    let keep_accidentals = match c.peek() {
        Some(b'X') => false,
        Some(b'Z') => true,
        _ => return Ok(None),
    };
    c.bump();
    let times = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    Ok(Some(NoteEntry::Repeat { items: 1, times, keep_accidentals }))
}

/// `Xn m`, `Zn m` (and `REPn m` after its `REP`).
fn group_repeat(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    let keep_accidentals = c.bump() == Some(b'Z');
    repeat_counts(c, keep_accidentals)
}

fn repeat_counts(c: &mut Cursor, keep_accidentals: bool) -> Result<NoteEntry, InputError> {
    let items = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    Ok(match c.integer() {
        Some(times) => NoteEntry::Repeat { items, times, keep_accidentals },
        None => NoteEntry::ZeroToken,
    })
}

/// `R` and its kinds (`W` and `F` take one more `U` or `D`), `Rn`, and `REPn m`; only a
/// repeat suffix may follow.
fn rest(c: &mut Cursor) -> Result<(NoteEntry, Option<NoteEntry>), InputError> {
    c.bump();
    if c.eat_word("EP") {
        return Ok((repeat_counts(c, false)?, None));
    }
    let shift = |c: &mut Cursor| direction(c, b'U', b'D');
    let kind = |c: &mut Cursor, kind| {
        c.bump();
        NoteEntry::Rest(Rest::new(kind))
    };
    let rest = match c.peek() {
        Some(b'I') => kind(c, RestKind::Invisible),
        Some(b'P') => kind(c, RestKind::RepeatSign),
        Some(b'W') => {
            c.bump();
            // `RWU` and `RWD` are plain `RW`.
            shift(c);
            NoteEntry::Rest(Rest::new(RestKind::Whole))
        }
        Some(b'F') => {
            c.bump();
            NoteEntry::Rest(Rest { kind: RestKind::Fermata, shift: shift(c) })
        }
        Some(b'U' | b'D') => NoteEntry::Rest(Rest { kind: RestKind::Normal, shift: shift(c) }),
        Some(b'0'..=b'9') => {
            let n = c.integer().unwrap_or(0);
            let n = u8::try_from(n).map_err(|_| c.error_here(ErrorKind::OutOfRange("measures".into())))?;
            NoteEntry::Rest(Rest::new(if n == 0 { RestKind::Whole } else { RestKind::Measures(n) }))
        }
        _ => NoteEntry::Rest(Rest::new(RestKind::Normal)),
    };
    Ok((rest, repeat_suffix(c)?))
}

/// `KnS`, `KnF`, `KnSN`, `KnFN`; `K` alone takes a key name that input never sets.
fn key(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    c.bump();
    let none = KeySignature { count: 0, sharps: true, naturals: false };
    let Some(count) = c.integer() else {
        return if c.at_end() { Ok(NoteEntry::Key(none)) } else { Err(c.unexpected()) };
    };
    let count = u8::try_from(count).map_err(|_| c.error_here(ErrorKind::OutOfRange("number of accidentals".into())))?;
    let sharps = match c.bump() {
        Some(b'S') => true,
        Some(b'F') => false,
        _ => return Err(c.unexpected()),
    };
    let naturals = c.eat(b'N');
    Ok(NoteEntry::Key(KeySignature { count, sharps, naturals }))
}

/// `M`, then type letters (`D`/`M` double, a second one heavy, after another type a double
/// repeat; `H` `L` `R` `S` `I`) and a span, which ends the item.
fn bar(c: &mut Cursor) -> Result<Bar, InputError> {
    c.bump();
    let mut style = BarStyle::Single;
    loop {
        style = match c.peek() {
            None => return Ok(Bar { style, span: None }),
            Some(b'0'..=b'9') => {
                let span = c.integer().map(|n| n.min(u32::from(u8::MAX)) as u8);
                c.skip_rest();
                return Ok(Bar { style, span });
            }
            Some(b'D' | b'M') => match style {
                BarStyle::Single => BarStyle::Double,
                BarStyle::Double => BarStyle::Heavy,
                _ => BarStyle::DoubleRepeat,
            },
            Some(b'H') => BarStyle::Heavy,
            Some(b'L') => BarStyle::LeftRepeat,
            Some(b'R') => BarStyle::RightRepeat,
            Some(b'S') => BarStyle::Dashed,
            Some(b'I') => BarStyle::Invisible,
            Some(_) => return Err(c.unexpected()),
        };
        c.bump();
    }
}

/// `SU`, `SD`, `SO` (stems) and `S+`, `S-`, `S0` (staff); later characters are ignored.
fn switch(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    let entry = match c.peek_at(1) {
        Some(b'U') => NoteEntry::Stems(StemMode::Up),
        Some(b'D') => NoteEntry::Stems(StemMode::Down),
        Some(b'O') => NoteEntry::Stems(StemMode::Ordinary),
        Some(b'+') => NoteEntry::Staff(StaffShift::Above),
        Some(b'-') => NoteEntry::Staff(StaffShift::Below),
        Some(b'0') => NoteEntry::Staff(StaffShift::Main),
        _ => {
            c.bump();
            return Err(c.unexpected());
        }
    };
    Ok(word(c, 2, entry))
}

/// `TR`, `TE`; `T` (the last meter) and `Tn m`.
fn t_item(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    match c.peek_at(1) {
        Some(b'R') => Ok(word(c, 2, NoteEntry::Clef(Clef::Treble))),
        Some(b'E') => Ok(word(c, 2, NoteEntry::Clef(Clef::Tenor))),
        None => Ok(word(c, 1, NoteEntry::LastMeter)),
        Some(b'0'..=b'9') => {
            c.bump();
            meter(c)
        }
        Some(_) => {
            c.bump();
            Err(c.unexpected())
        }
    }
}

/// `-` and a clef: only the second character counts (`B` bass, `A` alto, `TE` tenor,
/// anything else treble).
fn input_clef(c: &mut Cursor) -> NoteEntry {
    let clef = match (c.peek_at(1), c.peek_at(2)) {
        (Some(b'B'), _) => Clef::Bass,
        (Some(b'A'), _) => Clef::Alto,
        (Some(b'T'), Some(b'E')) => Clef::Tenor,
        _ => Clef::Treble,
    };
    word(c, 1, NoteEntry::InputClef(clef))
}

fn chord_repeat(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    let dots = std::iter::from_fn(|| (c.eat(b'=') || c.eat(b'.')).then_some(())).count();
    match dots {
        1 => Ok(NoteEntry::RepeatChord { keep_accidentals: false }),
        2 => Ok(NoteEntry::RepeatChord { keep_accidentals: true }),
        _ => Err(c.unexpected()),
    }
}

/// `Q+` cue size on; `Q` with anything else, off.
fn cue(c: &mut Cursor) -> NoteEntry {
    let on = c.peek_at(1) == Some(b'+');
    word(c, 1, NoteEntry::Cue(on))
}

/// `n m`; a single number n (or `n 0`) is stored as (0, n).
fn meter(c: &mut Cursor) -> Result<NoteEntry, InputError> {
    let fit = |c: &Cursor, n: u32| i32::try_from(n).map_err(|_| c.error_here(ErrorKind::OutOfRange("meter".into())));
    let top = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    let top = fit(c, top)?;
    let bottom = match c.integer() {
        Some(n) => fit(c, n)?,
        None => 0,
    };
    let meter = if bottom == 0 { Meter::Fraction(0, top) } else { Meter::Fraction(top, bottom) };
    Ok(NoteEntry::Meter(meter))
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
        assert_eq!(parsed.len(), 9);
        assert!(matches!(parsed[1], NoteEntry::Chord(ref notes) if notes.len() == 2
            && notes[0].accidental == Some(Accidental::Flat) && notes[0].final_digit() == Some(3)));
        assert_eq!(parsed[2], NoteEntry::Clef(Clef::Bass));
        assert_eq!(parsed[3], NoteEntry::Key(KeySignature { count: 2, sharps: true, naturals: false }));
        assert_eq!(parsed[4], NoteEntry::Meter(Meter::Fraction(3, 4)));
        assert_eq!(parsed[5], NoteEntry::Rest(Rest { kind: RestKind::Normal, shift: Some(Direction::Up) }));
        assert_eq!(parsed[6], NoteEntry::Repeat { items: 1, times: 3, keep_accidentals: false });
        assert_eq!(parsed[7], NoteEntry::Bar(Bar { style: BarStyle::Single, span: Some(2) }));
        assert_eq!(parsed[8], NoteEntry::Repeat { items: 1, times: 2, keep_accidentals: false });
    }

    #[test]
    fn accidentals_from_letters_and_repeats() {
        let accidental = |text: &str| match &values(text)[0] {
            NoteEntry::Chord(notes) => notes[0].accidental.map(Accidental::code),
            other => panic!("{other:?}"),
        };
        assert_eq!(accidental("BB4;"), Some(1));
        assert_eq!(accidental("FFF;"), Some(2));
        assert_eq!(accidental("AAS;"), Some(2));
        assert_eq!(accidental("GGFF;"), Some(4));
        assert_eq!(accidental("BNN;"), Some(6));
        assert_eq!(accidental("C S 4;"), Some(2));
    }

    #[test]
    fn octave_marks_keep_their_order() {
        let marks = |text: &str| match &values(text)[0] {
            NoteEntry::Chord(notes) => notes[0].octave.clone(),
            other => panic!("{other:?}"),
        };
        assert_eq!(marks("C4U;"), [OctaveMark::Digit(4), OctaveMark::Jump(Direction::Up)]);
        assert_eq!(marks("CU4;"), [OctaveMark::Jump(Direction::Up), OctaveMark::Digit(4)]);
        assert!(parse("C4S;", &mut Motives::new()).is_err());
    }

    #[test]
    fn barline_types() {
        let style = |text: &str| match values(text)[0] {
            NoteEntry::Bar(bar) => (bar.style, bar.span),
            ref other => panic!("{other:?}"),
        };
        assert_eq!(style("MRD;"), (BarStyle::DoubleRepeat, None));
        assert_eq!(style("MDD;"), (BarStyle::Heavy, None));
        assert_eq!(style("M2D;"), (BarStyle::Single, Some(2)));
        assert_eq!(style("MI3;"), (BarStyle::Invisible, Some(3)));
    }

    #[test]
    fn errors_point_at_the_entry() {
        let err = parse("C4/Y/D;", &mut Motives::new()).unwrap_err();
        assert_eq!(err.span.start, 3);
        assert!(parse("C4/D", &mut Motives::new()).is_err());
        assert!(parse("RX/C4;", &mut Motives::new()).is_err());
    }
}
