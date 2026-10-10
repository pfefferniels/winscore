//! Pass 1 items turned into the engine's token list R, then into events.
//!
//! The item parser 0x4E2CC8 resolves octaves as it goes (its state is [`Octaves`]); 0x4AF456
//! applies repeats to R; the builder 0x4ECDF8 reads R with the clef in force, so a repeated
//! note is placed for the clef where the copy stands (analysis/engine/input.md, "Pass 1").

use crate::error::{ErrorKind, InputError, Pass};
use crate::motives::{transpose, Carried, Motives};
use crate::notes::{
    Accidental, BarStyle, Clef, Direction, Join, KeySignature, Meter, NoteEntry, NoteName, OctaveMark, OctaveMode, Rest,
    Spanned, StaffShift, StemMode,
};

/// The parser's octave register c0 at the start of a line: octave 4.
const START_BASE: i32 = 28;
/// A note's step s is 7 * octave + letter (C = 1); P4 = s - 28 on a treble staff.
const MIDDLE_C_BASE: i32 = 28;

/// A note head: its staff level (P4, 1 = middle C on a treble staff) and accidental.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct Head {
    pub level: i32,
    pub accidental: Option<Accidental>,
    /// The accidental is drawn in parentheses.
    pub cautionary: bool,
}

impl Head {
    pub fn new(level: i32, accidental: Option<Accidental>) -> Self {
        Head { level, accidental, cautionary: false }
    }
}

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub enum Event {
    /// One or more note heads sounding together, sorted from the lowest level up.
    Chord(Vec<Head>),
    Rest(Rest),
    /// `staves` is negative for an invisible barline, as P4 stores it.
    Bar { staves: i32, style: BarStyle },
    Clef(Clef),
    /// The key signature and the clef it is drawn for: the one notes are read in.
    Key(KeySignature, Clef),
    Meter(Meter),
    /// A token below 1000 (a note far below the staff, `X` without its count): the builder
    /// makes a meter of it, but pass 2 gives it a rhythm, which counts in the spacing.
    MisreadMeter(Meter),
    Stems(StemMode),
    Staff(StaffShift),
    /// Cue-size notes from here on (true) or normal ones again (false); pass 1 codes 8001
    /// and 8000, which the refit (0x47C3E8) sends for notes with |P4| >= 100.
    Cue(bool),
}

impl Event {
    /// Chords and rests take a rhythm in pass 2, and so does a misread meter; chords take a
    /// note number in passes 3-5.
    pub fn is_rhythmic(&self) -> bool {
        matches!(self, Event::Chord(_) | Event::Rest(_) | Event::MisreadMeter(_))
    }
}

/// A note as R holds it: its step s (7 * octave + letter, C = 1), accidental and parentheses.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Pitch {
    step: i32,
    accidental: Option<Accidental>,
    cautionary: bool,
}

impl Pitch {
    /// The size of its token: 1000 + s + 100 * accidental, 6000 more in parentheses.
    fn value(self) -> i32 {
        1000 + self.step + 100 * self.accidental.map_or(0, Accidental::code) + if self.cautionary { 6000 } else { 0 }
    }
}

/// One entry of R.
#[derive(Debug, Clone, PartialEq)]
enum Token {
    /// `member`: a further note of a chord (a negative token).
    Note { pitch: Pitch, member: bool },
    Rest(Rest),
    Bar { style: BarStyle, span: u8 },
    Clef(Clef),
    InputClef(Clef),
    Key(KeySignature),
    Meter(Meter),
    Stems(StemMode),
    Staff(StaffShift),
    Cue(bool),
    /// A token below 1000, which the builder reads as a meter.
    Misread(i32),
}

impl Token {
    /// Whether 0x4AF456 counts the token as an item when it counts back for a repeat: a
    /// chord's further notes do not, unless their token rounds to -2 or -8 (an accidental
    /// code of 5 and up; an engine quirk).
    fn counts(&self) -> bool {
        match self {
            Token::Note { pitch, member: true } => !matches!((pitch.value() as f32 / 1000.0).round() as i32, 1 | 7),
            _ => true,
        }
    }

    /// The copy `=` makes: notes lose their accidental and its parentheses.
    fn plain(&self) -> Token {
        match self {
            Token::Note { pitch, member } => Token::Note { pitch: Pitch { accidental: None, cautionary: false, ..*pitch }, member: *member },
            other => other.clone(),
        }
    }

    /// The copy an `X` repeat makes: notes lose their accidental, keep their parentheses.
    fn without_accidental(&self) -> Token {
        match self {
            Token::Note { pitch, member } => Token::Note { pitch: Pitch { accidental: None, ..*pitch }, member: *member },
            other => other.clone(),
        }
    }
}

/// The parser's octave state: the octave register c0 (0x78DEC0), the mode with the
/// proximity reference (0x78DEC4: none for ordinary), the step and letter of the previous
/// note (0x78DEC8, 0x78DECC).
#[derive(Debug, Clone, Copy)]
struct Octaves {
    base: i32,
    proximity: Option<i32>,
    last_step: i32,
    /// C = 1 ... B = 7; carried over from earlier lines.
    last_letter: i32,
}

impl Octaves {
    /// A line starts in ordinary mode. (The engine starts it in the mode its typing-time parse
    /// left, so a `P` item late in the line can change earlier notes; not imitated, D12.)
    fn new(carried: &Carried) -> Self {
        Octaves { base: START_BASE, proximity: None, last_step: carried.last_step, last_letter: carried.last_letter }
    }

    fn set_mode(&mut self, mode: Option<OctaveMode>) {
        match mode {
            Some(OctaveMode::Ordinary) => self.proximity = None,
            Some(OctaveMode::Proximity) => self.proximity = Some(self.last_step),
            None => {}
        }
    }

    /// Ends a note on `letter`: its step becomes the previous one, and the reference in
    /// proximity mode.
    fn finish(&mut self, letter: i32) -> i32 {
        let step = self.base + letter;
        self.last_step = step;
        self.last_letter = letter;
        self.proximity = self.proximity.map(|_| step);
        step
    }

    /// The step of a note (0x4E2CC8, finished by 0x4E33A4).
    fn step(&mut self, name: &NoteName) -> i32 {
        self.set_mode(name.mode);
        let letter = name.letter.step() + 1;
        name.octave.iter().for_each(|mark| match mark {
            OctaveMark::Digit(d) => self.base = 7 * i32::from(*d),
            OctaveMark::Jump(Direction::Up) if letter <= self.last_letter => self.base += 7,
            OctaveMark::Jump(Direction::Down) if self.last_letter <= letter => self.base -= 7,
            OctaveMark::Jump(_) => {}
        });
        // A digit also moves the proximity reference to the note; a jump skips the step.
        if let (Some(reference), true) = (self.proximity, name.octave.is_empty()) {
            let distance = reference - (letter + self.base);
            if distance > 3 {
                self.base += 7;
            } else if distance < -3 {
                self.base -= 7;
            }
        }
        self.finish(letter)
    }

    /// The reader's tracking of a note with an octave number or a jump: the number, then
    /// one jump at most.
    fn track(&mut self, name: &NoteName) {
        self.set_mode(name.mode);
        let letter = name.letter.step() + 1;
        if let Some(digit) = name.octave.iter().rev().find_map(|m| if let OctaveMark::Digit(d) = m { Some(*d) } else { None }) {
            self.base = 7 * i32::from(digit);
        }
        match name.octave.iter().find(|m| matches!(m, OctaveMark::Jump(_))) {
            Some(OctaveMark::Jump(Direction::Up)) if letter <= self.last_letter => self.base += 7,
            Some(OctaveMark::Jump(Direction::Down)) if self.last_letter <= letter => self.base -= 7,
            _ => {}
        }
        self.finish(letter);
    }
}

/// Pass-1 state while the items are read in order.
struct Resolver<'a> {
    octaves: Octaves,
    /// The reader's own octave state (0x41FAB5), which gives the notes of a motive
    /// definition their octave numbers; outside definitions it follows the parser's.
    reader: Octaves,
    /// The barline span, remembered from barline to barline.
    span: u8,
    tokens: Vec<Token>,
    motives: &'a mut Motives,
    /// The motive being defined and its entries so far (octaves made explicit).
    defining: Option<(char, Vec<NoteEntry>)>,
}

impl Resolver<'_> {
    fn finish_definition(&mut self) {
        if let Some((name, entries)) = self.defining.take() {
            self.motives.store_notes(name, entries);
        }
    }

    fn spanned(&mut self, spanned: &Spanned<NoteEntry>) -> Result<(), InputError> {
        if self.defining.as_ref().map(|(name, _)| *name) != spanned.motive {
            self.finish_definition();
            self.defining = spanned.motive.map(|name| (name, Vec::new()));
        }
        let explicit = self.entry(&spanned.value, spanned.span)?;
        if let Some((_, entries)) = self.defining.as_mut() {
            entries.push(explicit);
        }
        Ok(())
    }

    /// Reads one item into R; returns it with explicit octaves, as a motive stores it.
    fn entry(&mut self, value: &NoteEntry, span: crate::Span) -> Result<NoteEntry, InputError> {
        let error = |kind| InputError::new(Pass::Notes, span, kind);
        match value {
            NoteEntry::Chord(names) => return Ok(NoteEntry::Chord(self.chord(names, false))),
            NoteEntry::Rest(rest) => self.tokens.push(Token::Rest(*rest)),
            NoteEntry::Bar(bar) => {
                self.span = bar.span.unwrap_or(self.span);
                self.tokens.push(Token::Bar { style: bar.style, span: self.span });
            }
            NoteEntry::Clef(clef) => self.tokens.push(Token::Clef(*clef)),
            NoteEntry::InputClef(clef) => self.tokens.push(Token::InputClef(*clef)),
            NoteEntry::Key(key) => self.tokens.push(Token::Key(*key)),
            NoteEntry::Meter(meter) => {
                self.motives.carried.last_meter = Some(*meter);
                self.tokens.push(Token::Meter(*meter));
            }
            NoteEntry::LastMeter => self.tokens.extend(self.motives.carried.last_meter.map(Token::Meter)),
            NoteEntry::Stems(mode) => self.tokens.push(Token::Stems(*mode)),
            NoteEntry::Staff(shift) => self.tokens.push(Token::Staff(*shift)),
            NoteEntry::Cue(on) => self.tokens.push(Token::Cue(*on)),
            NoteEntry::ZeroToken => self.tokens.push(Token::Misread(0)),
            NoteEntry::Repeat { items, times, keep_accidentals } => {
                let start = self.unit_start(*items as usize).ok_or_else(|| error(ErrorKind::NothingToRepeat))?;
                let block = copied(&self.tokens[start..], *keep_accidentals);
                let copies = times.saturating_sub(1) as usize;
                self.tokens.extend(std::iter::repeat_n(block, copies).flatten());
            }
            NoteEntry::RepeatChord { keep_accidentals } => {
                let (from, to) = self.chord_before_last_item().ok_or_else(|| error(ErrorKind::NothingToRepeat))?;
                let block: Vec<Token> = self.tokens[from..to]
                    .iter()
                    .map(|t| if *keep_accidentals { t.clone() } else { t.plain() })
                    .collect();
                self.tokens.extend(block);
            }
            NoteEntry::Recall { name, steps, joins } => {
                let stored = self.motives.notes(*name).ok_or_else(|| error(ErrorKind::UnknownMotive(*name)))?.to_vec();
                let mut member = match joins {
                    Join::Separate => false,
                    Join::ChordMember => true,
                    Join::LastNote => self.drop_last_note(),
                };
                for entry in stored {
                    match entry {
                        NoteEntry::Chord(names) => {
                            let moved: Vec<NoteName> = names.iter().map(|n| transpose(n, *steps)).collect();
                            self.chord(&moved, std::mem::take(&mut member));
                        }
                        other => {
                            self.entry(&other, span)?;
                        }
                    }
                }
            }
        }
        Ok(value.clone())
    }

    /// The notes of a chord, the first a positive token (unless `continues` an earlier
    /// chord), the others members; a dyad adds a member an octave away (0x4AF456). Returns
    /// the names as a motive definition stores them.
    fn chord(&mut self, names: &[NoteName], continues: bool) -> Vec<NoteName> {
        names
            .iter()
            .enumerate()
            .map(|(i, name)| {
                let (step, written) = self.step(name);
                let pitch = Pitch { step, accidental: name.accidental, cautionary: name.cautionary };
                let member = i > 0 || continues;
                self.tokens.push(if !member && pitch.value() < 1000 { Token::Misread(pitch.value()) } else { Token::Note { pitch, member } });
                let octave = match name.dyad {
                    Some(Direction::Up) => Some(7),
                    Some(Direction::Down) => Some(-7),
                    None => None,
                };
                self.tokens.extend(octave.map(|o| Token::Note { pitch: Pitch { step: step + o, ..pitch }, member: true }));
                written
            })
            .collect()
    }

    /// The step of a note, and the name as a motive stores it (with the octave it was read
    /// in). In a definition the reader (0x41FAB5) gives a note without octave number or
    /// jump the octave its own state tracks, which counts one jump per earlier note. Notes
    /// with a jump are read as written: the engine appends a stale digit there and loses
    /// characters after `]`, which is not imitated (decision D12).
    fn step(&mut self, name: &NoteName) -> (i32, NoteName) {
        let letter = name.letter.step() + 1;
        if self.defining.is_none() {
            let step = self.octaves.step(name);
            self.reader = self.octaves;
            return (step, name.clone());
        }
        let read = if name.has_digit() || name.has_jump() {
            self.reader.track(name);
            name.clone()
        } else {
            let octave = (self.reader.step(name) - letter).div_euclid(7);
            NoteName { octave: vec![OctaveMark::Digit(octave.clamp(0, 9) as u8)], ..name.clone() }
        };
        let step = self.octaves.step(&read);
        let octave = (step - letter).div_euclid(7).clamp(0, 9) as u8;
        (step, NoteName { octave: vec![OctaveMark::Digit(octave)], ..name.clone() })
    }

    /// `]@X`: the definition's last note is lost; returns whether it continued a chord.
    fn drop_last_note(&mut self) -> bool {
        match self.tokens.iter().rposition(|t| matches!(t, Token::Note { .. })) {
            Some(i) => matches!(self.tokens.remove(i), Token::Note { member: true, .. }),
            None => false,
        }
    }

    /// `=`: past the last item of R (a whole chord), the nearest note or chord before it
    /// (its tokens).
    fn chord_before_last_item(&self) -> Option<(usize, usize)> {
        let is_head = |t: &Token| matches!(t, Token::Note { member: false, .. });
        let last = match self.tokens.last()? {
            Token::Note { .. } => self.tokens.iter().rposition(is_head)?,
            _ => self.tokens.len() - 1,
        };
        let from = self.tokens[..last].iter().rposition(is_head)?;
        let members = self.tokens[from + 1..].iter().take_while(|t| matches!(t, Token::Note { member: true, .. })).count();
        Some((from, from + 1 + members))
    }

    /// Where the last `units` items of R start, counting as 0x4AF456 does.
    fn unit_start(&self, units: usize) -> Option<usize> {
        let back = units.checked_sub(1)?;
        self.tokens.iter().enumerate().rev().filter(|(_, t)| t.counts()).nth(back).map(|(i, _)| i)
    }
}

fn copied(tokens: &[Token], keep_accidentals: bool) -> Vec<Token> {
    tokens.iter().map(|t| if keep_accidentals { t.clone() } else { t.without_accidental() }).collect()
}

/// The builder's reading of R: chords from a note and its members, levels for the clef in
/// force (a clef resets an input clef).
fn events(tokens: &[Token], staff_clef: Clef) -> Vec<Event> {
    let mut reading = staff_clef;
    let mut events: Vec<Event> = Vec::new();
    let mut after_note = false;
    for token in tokens {
        let was_note = std::mem::replace(&mut after_note, matches!(token, Token::Note { .. }));
        let event = match token {
            Token::Note { pitch, member } => {
                let head = Head { level: pitch.step - MIDDLE_C_BASE + reading.level_offset(), accidental: pitch.accidental, cautionary: pitch.cautionary };
                match events.last_mut() {
                    Some(Event::Chord(heads)) if *member && was_note => {
                        heads.push(head);
                        heads.sort_by_key(|h| h.level);
                        continue;
                    }
                    _ => Event::Chord(vec![head]),
                }
            }
            Token::Rest(rest) => Event::Rest(*rest),
            Token::Bar { style, span } => {
                let span = i32::from(*span);
                Event::Bar { staves: if *style == BarStyle::Invisible { -span } else { span }, style: *style }
            }
            Token::Clef(clef) => {
                reading = *clef;
                Event::Clef(*clef)
            }
            Token::InputClef(clef) => {
                reading = *clef;
                continue;
            }
            Token::Key(key) => Event::Key(*key, reading),
            Token::Meter(meter) => Event::Meter(*meter),
            Token::Stems(mode) => Event::Stems(*mode),
            Token::Staff(shift) => Event::Staff(*shift),
            Token::Cue(on) => Event::Cue(*on),
            Token::Misread(value) => Event::MisreadMeter(misread_meter(*value)),
        };
        events.push(event);
    }
    events
}

/// A token below 1000 read as a meter token 20000 + 100 n + m.
fn misread_meter(value: i32) -> Meter {
    Meter::Fraction((value - 20000) / 100, value.rem_euclid(100))
}

pub fn resolve(entries: &[Spanned<NoteEntry>], clef: Clef, motives: &mut Motives) -> Result<Vec<Event>, InputError> {
    let octaves = Octaves::new(&motives.carried);
    let mut resolver = Resolver { octaves, reader: octaves, span: 1, tokens: Vec::new(), motives, defining: None };
    entries.iter().try_for_each(|spanned| resolver.spanned(spanned))?;
    resolver.finish_definition();
    resolver.motives.carried.last_step = resolver.octaves.last_step;
    resolver.motives.carried.last_letter = resolver.octaves.last_letter;
    Ok(events(&resolver.tokens, clef))
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::notes::parse;

    fn levels(text: &str) -> Vec<Vec<i32>> {
        let mut motives = Motives::new();
        resolve(&parse(text, &mut motives).unwrap(), Clef::Treble, &mut motives)
            .unwrap()
            .into_iter()
            .filter_map(|e| match e {
                Event::Chord(heads) => Some(heads.iter().map(|h| h.level).collect()),
                _ => None,
            })
            .collect()
    }

    #[test]
    fn octaves_persist_and_proximity_follows_the_previous_note() {
        assert_eq!(levels("C4/B/C5/D3;"), [[1], [7], [8], [-5]]);
        assert_eq!(levels("PC4/B/G/C/F/E5/OB/C/D;"), [[1], [0], [-2], [1], [4], [10], [14], [8], [9]]);
        assert_eq!(levels("PC4/B/A/OG;"), [[1], [0], [-1], [-2]]);
    }

    #[test]
    fn jumps_compare_letters_with_the_previous_note() {
        assert_eq!(levels("C4/AU/A/GU/E/EU/BUU/C4U/CU4;"), [[1], [6], [6], [12], [10], [17], [21], [8], [1]]);
        assert_eq!(levels("OG4/AJ/A/BJ/C/CJ;"), [[5], [-1], [-1], [-7], [-13], [-20]]);
    }

    #[test]
    fn chords_are_sorted_and_clefs_shift_levels() {
        assert_eq!(levels("E4:C/BA/C4/AL/C/TE/C;"), [vec![1, 3], vec![13], vec![7], vec![9]]);
        assert_eq!(levels("C4+/E5-;"), [vec![1, 8], vec![3, 10]]);
    }

    #[test]
    fn repeats_drop_accidentals_unless_z() {
        let mut motives = Motives::new();
        let events = resolve(&parse("CS4/X1 2/Z1 2/;", &mut motives).unwrap(), Clef::Treble, &mut motives).unwrap();
        let accidentals: Vec<_> = events
            .iter()
            .map(|e| match e {
                Event::Chord(h) => h[0].accidental,
                _ => None,
            })
            .collect();
        assert_eq!(accidentals, [Some(Accidental::Sharp), None, None, None]);
    }

    #[test]
    fn chord_repeat_takes_the_item_before_the_previous_one() {
        assert_eq!(levels("C4:E/D:F/=/G;"), [vec![1, 3], vec![2, 4], vec![1, 3], vec![5]]);
    }

    #[test]
    fn repeated_notes_follow_the_clef_where_they_stand() {
        assert_eq!(levels("C4/BA/X2 2;"), [[1], [13]]);
    }
}
