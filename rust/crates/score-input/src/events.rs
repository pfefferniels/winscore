//! Pass 1 entries resolved into a flat sequence of events: octaves and proximity applied,
//! levels computed for the current clef, repeats expanded.

use crate::error::{ErrorKind, InputError, Pass};
use crate::notes::{Accidental, Clef, KeySignature, Meter, NoteEntry, NoteName, OctaveMode, RestKind, Spanned, StaffShift, StemMode};

const MIDDLE_C_OCTAVE: i32 = 4;

/// A note head: its staff level (P4, 1 = middle C on a treble staff) and accidental.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
pub struct Head {
    pub level: i32,
    pub accidental: Option<Accidental>,
}

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
pub enum Event {
    /// One or more note heads sounding together, sorted from the lowest level up.
    Chord(Vec<Head>),
    Rest(RestKind),
    Bar { staves: u8 },
    Clef(Clef),
    Key(KeySignature),
    Meter(Meter),
    Stems(StemMode),
    Staff(StaffShift),
}

impl Event {
    /// Chords and rests take a rhythm in pass 2 and a note number in passes 3-5.
    pub fn is_rhythmic(&self) -> bool {
        matches!(self, Event::Chord(_) | Event::Rest(_))
    }

    fn without_accidentals(&self) -> Event {
        match self {
            Event::Chord(heads) => Event::Chord(heads.iter().map(|h| Head { accidental: None, ..*h }).collect()),
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
    clef: Clef,
    staves: u8,
}

impl Default for Pitches {
    fn default() -> Self {
        Self { octave: MIDDLE_C_OCTAVE, proximity: false, previous: None, clef: Clef::Treble, staves: 1 }
    }
}

impl Pitches {
    /// Diatonic number of the note (C4 = 28) after applying octave and proximity rules.
    fn resolve(&mut self, name: &NoteName) -> i32 {
        match name.mode {
            Some(OctaveMode::Proximity) => self.proximity = true,
            Some(OctaveMode::Ordinary) => self.proximity = false,
            None => {}
        }
        let step = name.letter.step();
        let diatonic = match (name.octave, self.previous) {
            (Some(octave), _) => 7 * i32::from(octave) + step,
            (None, Some(previous)) if self.proximity => nearest(previous, step),
            _ => 7 * self.octave + step,
        };
        self.octave = diatonic.div_euclid(7);
        self.previous = Some(diatonic);
        diatonic
    }

    fn head(&mut self, name: &NoteName) -> Head {
        let level = self.resolve(name) - 7 * MIDDLE_C_OCTAVE + 1 + self.clef.level_offset();
        Head { level, accidental: name.accidental }
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

pub fn resolve(entries: &[Spanned<NoteEntry>]) -> Result<Vec<Event>, InputError> {
    let mut pitches = Pitches::default();
    let mut events: Vec<Event> = Vec::new();
    for spanned in entries {
        let error = |kind| InputError::new(Pass::Notes, spanned.span, kind);
        match &spanned.value {
            NoteEntry::Chord(names) => {
                let mut heads: Vec<Head> = names.iter().map(|n| pitches.head(n)).collect();
                heads.sort_by_key(|h| h.level);
                events.push(Event::Chord(heads));
            }
            NoteEntry::Rest { kind, count } => {
                events.extend(std::iter::repeat_n(Event::Rest(*kind), *count as usize));
            }
            NoteEntry::Bar { staves } => {
                pitches.staves = staves.unwrap_or(pitches.staves);
                events.push(Event::Bar { staves: pitches.staves });
            }
            NoteEntry::Clef(clef) => {
                pitches.clef = *clef;
                events.push(Event::Clef(*clef));
            }
            NoteEntry::Key(key) => events.push(Event::Key(*key)),
            NoteEntry::Meter(meter) => events.push(Event::Meter(*meter)),
            NoteEntry::Stems(mode) => events.push(Event::Stems(*mode)),
            NoteEntry::Staff(shift) => events.push(Event::Staff(*shift)),
            NoteEntry::RepeatPrevious => {
                let previous = events.iter().rev().find(|e| e.is_rhythmic()).ok_or_else(|| error(ErrorKind::NothingToRepeat))?;
                events.push(previous.without_accidentals());
            }
            NoteEntry::Repeat { items, times, keep_accidentals } => {
                let items = *items as usize;
                if items == 0 || items > events.len() {
                    return Err(error(ErrorKind::NothingToRepeat));
                }
                let group: Vec<Event> = events[events.len() - items..]
                    .iter()
                    .map(|e| if *keep_accidentals { e.clone() } else { e.without_accidentals() })
                    .collect();
                let copies = times.saturating_sub(1) as usize;
                events.extend(std::iter::repeat_n(group, copies).flatten());
            }
        }
    }
    Ok(events)
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::notes::parse;

    fn levels(text: &str) -> Vec<Vec<i32>> {
        resolve(&parse(text).unwrap())
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
        let events = resolve(&parse("CS4/X1 2/Z1 2/;").unwrap()).unwrap();
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
