//! Pass 1 entries resolved into a flat sequence of events: octaves and proximity applied,
//! levels computed for the current clef, repeats expanded.

use crate::error::{ErrorKind, InputError, Pass};
use crate::motives::{transpose, Motives};
use crate::notes::{
    Accidental, BarStyle, Clef, Direction, KeySignature, Meter, NoteEntry, NoteName, OctaveMode, RestKind, Spanned, StaffShift,
    StemMode,
};

const MIDDLE_C_OCTAVE: i32 = 4;

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
    Rest(RestKind),
    /// `staves` is negative for an invisible barline, as P4 stores it.
    Bar { staves: i32, style: BarStyle },
    Clef(Clef),
    /// The key signature and the clef it is drawn for: the one notes are read in.
    Key(KeySignature, Clef),
    Meter(Meter),
    Stems(StemMode),
    Staff(StaffShift),
    /// Cue-size notes from here on (true) or normal ones again (false); pass 1 codes 8001
    /// and 8000, which the refit (0x47C3E8) sends for notes with |P4| >= 100.
    Cue(bool),
}

impl Event {
    /// Chords and rests take a rhythm in pass 2 and a note number in passes 3-5.
    pub fn is_rhythmic(&self) -> bool {
        matches!(self, Event::Chord(_) | Event::Rest(_))
    }

    fn without_accidentals(&self) -> Event {
        match self {
            Event::Chord(heads) => Event::Chord(heads.iter().map(|h| Head { accidental: None, cautionary: false, ..*h }).collect()),
            other => other.clone(),
        }
    }
}

/// Octave state while reading pass 1.
#[derive(Debug, Clone, Copy)]
struct Pitches {
    octave: i32,
    proximity: bool,
    previous: Option<i32>,
    /// The clef levels are computed for: the staff's, or an input clef (`-TR`).
    clef: Clef,
    staves: u8,
}

impl Default for Pitches {
    fn default() -> Self {
        Self { octave: MIDDLE_C_OCTAVE, proximity: false, previous: None, clef: Clef::Treble, staves: 1 }
    }
}

impl Pitches {
    /// Diatonic number of the note (C4 = 28) after applying octave, proximity and jump rules.
    fn resolve(&mut self, name: &NoteName) -> i32 {
        match name.mode {
            Some(OctaveMode::Proximity) => self.proximity = true,
            Some(OctaveMode::Ordinary) => self.proximity = false,
            None => {}
        }
        let step = name.letter.step();
        let diatonic = match (name.octave, self.previous, name.jump) {
            (Some(octave), _, _) => 7 * i32::from(octave) + step,
            (None, Some(previous), Some(direction)) => jump(previous, step, direction),
            (None, Some(previous), None) if self.proximity => nearest(previous, step),
            _ => 7 * self.octave + step,
        };
        self.octave = diatonic.div_euclid(7);
        self.previous = Some(diatonic);
        diatonic
    }

    fn level(&self, diatonic: i32) -> i32 {
        diatonic - 7 * MIDDLE_C_OCTAVE + 1 + self.clef.level_offset()
    }

    /// The heads for a note name (two for a dyad), and the name with its octave made explicit.
    fn heads(&mut self, name: &NoteName) -> (Vec<Head>, NoteName) {
        let diatonic = self.resolve(name);
        let head = Head { level: self.level(diatonic), accidental: name.accidental, cautionary: name.cautionary };
        let octave = match name.dyad {
            Some(Direction::Up) => Some(7),
            Some(Direction::Down) => Some(-7),
            None => None,
        };
        let heads = std::iter::once(head).chain(octave.map(|o| Head { level: head.level + o, ..head })).collect();
        let explicit = NoteName { octave: Some(diatonic.div_euclid(7).clamp(0, 9) as u8), jump: None, ..*name };
        (heads, explicit)
    }
}

/// The note with diatonic step `step` closest to `previous` (a fourth rather than a fifth).
fn nearest(previous: i32, step: i32) -> i32 {
    let up = (step - previous).rem_euclid(7);
    if up <= 3 {
        previous + up
    } else {
        previous + up - 7
    }
}

/// The nearest note with diatonic step `step` above or below `previous`: an octave away for
/// the same letter.
fn jump(previous: i32, step: i32, direction: Direction) -> i32 {
    match direction {
        Direction::Up => previous + 1 + (step - previous - 1).rem_euclid(7),
        Direction::Down => previous - 1 - (previous - 1 - step).rem_euclid(7),
    }
}

/// Pass-1 state while the entries are read in order.
struct Resolver<'a> {
    pitches: Pitches,
    events: Vec<Event>,
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

    /// Resolves one entry; returns it with explicit octaves, as a motive stores it.
    fn entry(&mut self, value: &NoteEntry, span: crate::Span) -> Result<NoteEntry, InputError> {
        let error = |kind| InputError::new(Pass::Notes, span, kind);
        match value {
            NoteEntry::Chord(names) => {
                let (heads, explicit): (Vec<Vec<Head>>, Vec<NoteName>) = names.iter().map(|n| self.pitches.heads(n)).unzip();
                let mut heads: Vec<Head> = heads.into_iter().flatten().collect();
                heads.sort_by_key(|h| h.level);
                self.events.push(Event::Chord(heads));
                return Ok(NoteEntry::Chord(explicit));
            }
            NoteEntry::Rest { kind, count } => {
                self.events.extend(std::iter::repeat_n(Event::Rest(*kind), *count as usize));
            }
            NoteEntry::Bar(bar) => {
                self.pitches.staves = bar.staves.unwrap_or(self.pitches.staves);
                let staves = i32::from(self.pitches.staves);
                self.events.push(Event::Bar { staves: if bar.invisible { -staves } else { staves }, style: bar.style });
            }
            NoteEntry::Clef(clef) => {
                self.pitches.clef = *clef;
                self.events.push(Event::Clef(*clef));
            }
            NoteEntry::InputClef(clef) => self.pitches.clef = *clef,
            NoteEntry::Cue(on) => self.events.push(Event::Cue(*on)),
            NoteEntry::Key(key) => self.events.push(Event::Key(*key, self.pitches.clef)),
            NoteEntry::Meter(meter) => self.events.push(Event::Meter(*meter)),
            NoteEntry::Stems(mode) => self.events.push(Event::Stems(*mode)),
            NoteEntry::Staff(shift) => self.events.push(Event::Staff(*shift)),
            NoteEntry::RepeatPrevious => {
                let previous =
                    self.events.iter().rev().find(|e| e.is_rhythmic()).ok_or_else(|| error(ErrorKind::NothingToRepeat))?;
                self.events.push(previous.without_accidentals());
            }
            NoteEntry::RepeatChord { keep_accidentals } => {
                let chord = self
                    .events
                    .iter()
                    .rev()
                    .find(|e| matches!(e, Event::Chord(_)))
                    .ok_or_else(|| error(ErrorKind::NothingToRepeat))?;
                self.events.push(if *keep_accidentals { chord.clone() } else { chord.without_accidentals() });
            }
            NoteEntry::Repeat { items, times, keep_accidentals } => {
                let items = *items as usize;
                if items == 0 || items > self.events.len() {
                    return Err(error(ErrorKind::NothingToRepeat));
                }
                let group: Vec<Event> = self.events[self.events.len() - items..]
                    .iter()
                    .map(|e| if *keep_accidentals { e.clone() } else { e.without_accidentals() })
                    .collect();
                let copies = times.saturating_sub(1) as usize;
                self.events.extend(std::iter::repeat_n(group, copies).flatten());
            }
            NoteEntry::Recall { name, steps } => {
                let stored = self.motives.notes(*name).ok_or_else(|| error(ErrorKind::UnknownMotive(*name)))?.to_vec();
                for entry in stored {
                    let moved = match entry {
                        NoteEntry::Chord(names) => NoteEntry::Chord(names.iter().map(|n| transpose(n, *steps)).collect()),
                        other => other,
                    };
                    self.entry(&moved, span)?;
                }
            }
        }
        Ok(value.clone())
    }
}

pub fn resolve(entries: &[Spanned<NoteEntry>], clef: Clef, motives: &mut Motives) -> Result<Vec<Event>, InputError> {
    let pitches = Pitches { clef, ..Pitches::default() };
    let mut resolver = Resolver { pitches, events: Vec::new(), motives, defining: None };
    for spanned in entries {
        resolver.spanned(spanned)?;
    }
    resolver.finish_definition();
    Ok(resolver.events)
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
    fn chords_are_sorted_and_clefs_shift_levels() {
        assert_eq!(levels("E4:C/BA/C4/AL/C/TE/C;"), [vec![1, 3], vec![13], vec![7], vec![9]]);
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
}
