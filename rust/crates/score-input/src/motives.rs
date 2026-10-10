//! Motives: `X[...]` stores the entries between the brackets under the letter X (and enters
//! them), `@X` enters them again, `@Xn` changed by n. The number transposes notes by n steps,
//! divides rhythm numbers by n, and in passes 3-5 renumbers the notes so that the first
//! number becomes n. The engine keeps motives in files (`!TMP\X.MOT`, `.MRH`, `.MRK`, `.MBM`,
//! `.MSL`), so they outlive a line; [`Motives`] plays that part, together with the rest of
//! what pass 1 carries from line to line (see [`Carried`]).
//!
//! The engine's recall (0x524C4A) substitutes text; its renumbering (0x4E5EA6) reads numbers of
//! at most two digits, and its augmentation (0x52789C) rounds to whole rhythm numbers.

use std::collections::HashMap;

use crate::error::{ErrorKind, InputError, Pass, Span};
use crate::notes::{Meter, NoteEntry, NoteName, OctaveMark};
use crate::rhythm::leading_value;

/// Stored motives, by pass and letter, and the pass-1 state that outlives a line.
#[derive(Debug, Clone, Default, PartialEq)]
pub struct Motives {
    texts: HashMap<(Pass, char), String>,
    notes: HashMap<char, Vec<NoteEntry>>,
    pub(crate) carried: Carried,
}

/// What the pass-1 parser keeps from earlier lines: the letter (C = 1 ... B = 7, 0 before
/// any note) and step of the last note, for `U`/`J` and `P` on a line's first note, and the
/// last meter, for `T`.
#[derive(Debug, Clone, Copy, Default, PartialEq)]
pub(crate) struct Carried {
    pub last_letter: i32,
    pub last_step: i32,
    pub last_meter: Option<Meter>,
}

impl Motives {
    pub fn new() -> Self {
        Self::default()
    }

    pub(crate) fn store_text(&mut self, pass: Pass, name: char, text: &str) {
        self.texts.insert((pass, name), text.to_string());
    }

    pub(crate) fn text(&self, pass: Pass, name: char) -> Option<&str> {
        self.texts.get(&(pass, name)).map(String::as_str)
    }

    /// Pass 1 keeps the entries with the octaves they resolved to, as the engine rewrites the
    /// definition with explicit octave numbers.
    pub(crate) fn store_notes(&mut self, name: char, entries: Vec<NoteEntry>) {
        self.notes.insert(name, entries);
    }

    pub(crate) fn notes(&self, name: char) -> Option<&[NoteEntry]> {
        self.notes.get(&name).map(Vec::as_slice)
    }
}

/// A stored note name moved by `steps` diatonic steps (stored names end with their octave).
pub(crate) fn transpose(name: &NoteName, steps: i32) -> NoteName {
    let octave = i32::from(name.final_digit().unwrap_or(4));
    let diatonic = 7 * octave + name.letter.step() + steps;
    NoteName {
        letter: crate::notes::Letter::from_step(diatonic.rem_euclid(7)),
        octave: vec![OctaveMark::Digit(diatonic.div_euclid(7).clamp(0, 9) as u8)],
        ..name.clone()
    }
}

/// `@Rn` in pass 2: every rhythm (letters as their numbers) divided by n and rounded to a
/// whole rhythm number; grace notes stay.
pub(crate) fn augment(text: &str, factor: i32) -> String {
    text.split('/')
        .map(|piece| match leading_value(piece) {
            Some((value, rest)) => {
                let scaled = value / factor as f32;
                let number = if scaled == 0.5 { ".5".to_string() } else { (scaled.abs() + 0.5).trunc().to_string() };
                format!("{number}{rest}")
            }
            None => piece.to_string(),
        })
        .collect::<Vec<_>>()
        .join("/")
}

/// `@Xn` in passes 3-5: the first note number becomes n and all others move with it.
pub(crate) fn renumber(text: &str, first: i32, pass: Pass, at: usize) -> Result<String, InputError> {
    let bytes = text.as_bytes();
    let mut out = String::with_capacity(text.len());
    let mut offset = None;
    let mut i = 0;
    while i < bytes.len() {
        if !bytes[i].is_ascii_digit() {
            out.push(bytes[i] as char);
            i += 1;
            continue;
        }
        let len = if bytes.get(i + 1).is_some_and(u8::is_ascii_digit) { 2 } else { 1 };
        let number: i32 = text[i..i + len].parse().unwrap_or(0);
        let shift = *offset.get_or_insert(number - first);
        let moved = number - shift;
        if !(0..100).contains(&moved) {
            return Err(InputError::new(pass, Span::at(at), ErrorKind::OutOfRange("motive note number".into())));
        }
        out.push_str(&moved.to_string());
        i += len;
    }
    Ok(out)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn renumbering_follows_the_first_number() {
        assert_eq!(renumber("S 5:8/A 11", 14, Pass::Marks, 0).unwrap(), "S 14:17/A 20");
        assert_eq!(renumber("A 6/S 7:9", 1, Pass::Marks, 0).unwrap(), "A 1/S 2:4");
        assert!(renumber("301 3", 4, Pass::Beams, 0).is_err());
    }

    #[test]
    fn augmentation_divides_rhythm_numbers() {
        assert_eq!(augment("8/8/4", 2), "4/4/2");
        assert_eq!(augment("8./Q/1", 2), "4./2/.5");
        assert_eq!(augment("T/E./TQ/G", 2), "6/4./3/G");
    }
}
