//! Pass 2: one rhythm for every note, chord and rest of pass 1.
//!
//! A rhythm number says how many such values fill a whole note (4 = quarter, 12 = triplet
//! eighth); letters name the common ones; dots and `Xn` (n copies) may follow; an empty entry
//! repeats the previous rhythm; `Xn m` repeats the last n rhythms so that they occur m times.

use crate::error::{ErrorKind, InputError, Pass};
use crate::motives::Motives;
use crate::scan::{entries, Cursor, Entry};

const PASS: Pass = Pass::Rhythms;

/// P7 of a grace note: not a duration, a marker the spacing and LJ commands recognise.
pub const GRACE_P7: f32 = 65.0;

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Rhythm {
    /// `per_whole` values fill a whole note; each dot adds half of the previous addition.
    Value { per_whole: f32, dots: u8 },
    Grace,
}

impl Rhythm {
    /// Duration in quarter notes, as stored in P7.
    pub fn quarters(self) -> f32 {
        match self {
            Rhythm::Value { per_whole, dots } => {
                let plain = 4.0 / per_whole;
                plain * (2.0 - 0.5f32.powi(i32::from(dots)))
            }
            Rhythm::Grace => GRACE_P7,
        }
    }

    pub fn dots(self) -> u8 {
        match self {
            Rhythm::Value { dots, .. } => dots,
            Rhythm::Grace => 0,
        }
    }

    /// Note head (P6): 0 black, 1 half, 2 whole, 3 breve.
    pub fn head(self) -> i32 {
        match self {
            Rhythm::Value { per_whole, .. } if per_whole < 1.0 => 3,
            Rhythm::Value { per_whole, .. } if per_whole < 2.0 => 2,
            Rhythm::Value { per_whole, .. } if per_whole < 4.0 => 1,
            _ => 0,
        }
    }

    /// Number of flags (tails) on an unbeamed stem.
    pub fn tails(self) -> i32 {
        match self {
            Rhythm::Value { per_whole, .. } if per_whole >= 8.0 => per_whole.log2().floor() as i32 - 2,
            Rhythm::Value { .. } => 0,
            Rhythm::Grace => 1,
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
enum RhythmEntry {
    Values { rhythm: Rhythm, copies: u32 },
    Repeat { items: u32, times: u32 },
    RepeatPrevious,
}

pub fn parse(text: &str, motives: &mut Motives) -> Result<Vec<Rhythm>, InputError> {
    let parsed: Vec<(Entry, RhythmEntry)> =
        entries(text, PASS, motives)?.into_iter().map(|e| parse_entry(&e).map(|r| (e, r))).collect::<Result<_, _>>()?;
    let mut rhythms: Vec<Rhythm> = Vec::new();
    for (entry, parsed) in parsed {
        match parsed {
            RhythmEntry::Values { rhythm, copies } => rhythms.extend(std::iter::repeat_n(rhythm, copies as usize)),
            RhythmEntry::RepeatPrevious => {
                let previous = *rhythms.last().ok_or_else(|| entry.error(PASS, ErrorKind::NothingToRepeat))?;
                rhythms.push(previous);
            }
            RhythmEntry::Repeat { items, times } => {
                let items = items as usize;
                if items == 0 || items > rhythms.len() {
                    return Err(entry.error(PASS, ErrorKind::NothingToRepeat));
                }
                let group = rhythms[rhythms.len() - items..].to_vec();
                rhythms.extend(std::iter::repeat_n(group, times.saturating_sub(1) as usize).flatten());
            }
        }
    }
    Ok(rhythms)
}

fn parse_entry(entry: &Entry) -> Result<RhythmEntry, InputError> {
    let mut c = entry.cursor(PASS);
    if c.at_end() {
        return Ok(RhythmEntry::RepeatPrevious);
    }
    if c.peek() == Some(b'X') {
        c.bump();
        let items = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
        c.skip_spaces();
        let times = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
        c.finish()?;
        return Ok(RhythmEntry::Repeat { items, times });
    }
    let rhythm = value(&mut c)?;
    let copies = if c.eat(b'X') { c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))? } else { 1 };
    c.finish()?;
    Ok(RhythmEntry::Values { rhythm, copies })
}

fn value(c: &mut Cursor) -> Result<Rhythm, InputError> {
    if c.eat(b'G') {
        return Ok(Rhythm::Grace);
    }
    let per_whole = per_whole(c)?;
    if per_whole <= 0.0 {
        return Err(c.error_here(ErrorKind::OutOfRange("rhythm".into())));
    }
    let dots = std::iter::from_fn(|| c.eat(b'.').then_some(())).count() as u8;
    Ok(Rhythm::Value { per_whole, dots })
}

/// The rhythm number a piece of pass-2 text starts with, and the rest of the piece
/// (dots, copies); None for a grace note or text that is not a rhythm.
pub(crate) fn leading_value(piece: &str) -> Option<(f32, String)> {
    let entry = Entry { text: piece.to_ascii_uppercase(), start: 0, motive: None };
    let mut c = entry.cursor(PASS);
    if c.peek() == Some(b'G') {
        return None;
    }
    let value = per_whole(&mut c).ok()?;
    Some((value, c.rest().to_string()))
}

fn per_whole(c: &mut Cursor) -> Result<f32, InputError> {
    if let Some(n) = c.number() {
        return Ok(n);
    }
    const TRIPLETS: [(&str, f32); 9] = [
        ("T32", 48.0),
        ("T16", 24.0),
        ("TH", 3.0),
        ("T2", 3.0),
        ("TQ", 6.0),
        ("T4", 6.0),
        ("TE", 12.0),
        ("T8", 12.0),
        ("TS", 24.0),
    ];
    if let Some((_, n)) = TRIPLETS.iter().find(|(word, _)| c.eat_word(word)) {
        return Ok(*n);
    }
    let letter = c.peek().ok_or_else(|| c.unexpected())?;
    let n = match letter {
        b'T' => 12.0,
        b'D' => 0.5,
        b'W' => 1.0,
        b'H' => 2.0,
        b'Q' => 4.0,
        b'E' => 8.0,
        b'S' => 16.0,
        _ => return Err(c.unexpected()),
    };
    c.bump();
    Ok(n)
}

#[cfg(test)]
mod tests {
    use super::*;

    fn quarters(text: &str) -> Vec<f32> {
        parse(text, &mut Motives::new()).unwrap().into_iter().map(Rhythm::quarters).collect()
    }

    #[test]
    fn numbers_letters_triplets_and_dots() {
        assert_eq!(quarters("4/8/.5/H./2../S;"), [1.0, 0.5, 8.0, 3.0, 3.5, 0.25]);
        assert_eq!(quarters("T/TQ/T16/G;"), [4.0 / 12.0, 4.0 / 6.0, 4.0 / 24.0, GRACE_P7]);
    }

    #[test]
    fn copies_and_repeats() {
        assert_eq!(quarters("SX3/8//;").len(), 6);
        assert_eq!(quarters("8/16/16/X3 2/4;").len(), 7);
    }

    #[test]
    fn heads_and_tails() {
        let r = |per_whole| Rhythm::Value { per_whole, dots: 0 };
        assert_eq!([0.5, 1.0, 3.0, 4.0].map(|n| r(n).head()), [3, 2, 1, 0]);
        assert_eq!([4.0, 6.0, 8.0, 10.0, 12.0, 20.0, 48.0, 64.0].map(|n| r(n).tails()), [0, 0, 1, 1, 1, 2, 3, 4]);
    }
}
