//! Pass 3: marks on numbered notes.
//!
//! An entry is a mark word, optionally preceded by `-` (opposite side of the note), and the
//! notes it applies to: `S 2`, `S 2:5` (notes 2 to 5), or for lines two positions that may be
//! fractional, `C 4.6 7`. Most marks go into the note's P11; `AO PZ RI AC CR DI` become code-9
//! symbols, `TM..` code-6 tremolo beams, `TRW O OB` code-7 lines and `C C-` code-4 hairpins.
//! Placement rules are read from the engine's output (marks routine 0x4D8460).

use crate::error::{ErrorKind, InputError, Pass};
use crate::line::{item, Line, Note, STEM};
use crate::scan::{entries, Cursor, Entry};

const PASS: Pass = Pass::Marks;

/// How a P11 mark keeps clear of the staff when it sits on the note-head side.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Clearance {
    None,
    /// Moved outside the staff: wedges and combinations with them, heavy wedge.
    Staff,
    /// As `Staff`, plus half a step: the accent.
    Accent,
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum MarkKind {
    /// Stored in the note's P11.
    Head { code: i32, clearance: Clearance },
    /// A code-9 library symbol above or below the staff.
    Symbol { library: i32, above: bool },
    /// A code-6 tremolo beam on the stem.
    Tremolo { beams: i32, offset: i32 },
    /// A code-7 wavy trill line, P8 = accidental.
    Trill { accidental: i32 },
    /// A code-7 octave line (8va above, 8ba below).
    Ottava { below: bool },
    /// A code-4 hairpin.
    Hairpin { closing: bool },
}

impl MarkKind {
    fn is_line(self) -> bool {
        matches!(self, MarkKind::Trill { .. } | MarkKind::Ottava { .. } | MarkKind::Hairpin { .. })
    }
}

/// Mark words, longest first where one is a prefix of another.
const WORDS: [(&str, MarkKind); 47] = {
    use Clearance::{Accent, None as Plain, Staff};
    use MarkKind::*;
    [
        ("TRFW", Trill { accidental: 1 }),
        ("TRSW", Trill { accidental: 2 }),
        ("TRNW", Trill { accidental: 3 }),
        ("TRW", Trill { accidental: 0 }),
        ("TRF", Head { code: 21, clearance: Plain }),
        ("TRS", Head { code: 22, clearance: Plain }),
        ("TRN", Head { code: 23, clearance: Plain }),
        ("TR", Head { code: 20, clearance: Plain }),
        ("TME", Tremolo { beams: 1, offset: 2 }),
        ("TMS", Tremolo { beams: 2, offset: 1 }),
        ("TMT", Tremolo { beams: 3, offset: 1 }),
        ("TM", Tremolo { beams: 3, offset: 1 }),
        ("TS", Head { code: 10, clearance: Staff }),
        ("T", Head { code: 6, clearance: Plain }),
        ("ACT", Head { code: 25, clearance: Plain }),
        ("AC", Symbol { library: 68, above: false }),
        ("AO", Symbol { library: 67, above: true }),
        ("AS", Head { code: 9, clearance: Staff }),
        ("A", Head { code: 5, clearance: Accent }),
        ("WS", Head { code: 8, clearance: Staff }),
        ("W", Head { code: 4, clearance: Staff }),
        ("S", Head { code: 7, clearance: Plain }),
        ("D", Head { code: 11, clearance: Plain }),
        ("DI", Symbol { library: 64, above: false }),
        ("U", Head { code: 12, clearance: Plain }),
        ("HW", Head { code: 19, clearance: Staff }),
        ("H", Head { code: 13, clearance: Plain }),
        ("FE", Head { code: 14, clearance: Plain }),
        ("FIF", Head { code: 1, clearance: Plain }),
        ("FIS", Head { code: 2, clearance: Plain }),
        ("FIN", Head { code: 3, clearance: Plain }),
        ("F0", Head { code: 30, clearance: Plain }),
        ("F1", Head { code: 31, clearance: Plain }),
        ("F2", Head { code: 32, clearance: Plain }),
        ("F3", Head { code: 33, clearance: Plain }),
        ("F4", Head { code: 34, clearance: Plain }),
        ("F5", Head { code: 35, clearance: Plain }),
        ("F6", Head { code: 36, clearance: Plain }),
        ("PL", Head { code: 24, clearance: Plain }),
        ("PZ", Symbol { library: 66, above: true }),
        ("M", Head { code: 17, clearance: Plain }),
        ("I", Head { code: 18, clearance: Plain }),
        ("RI", Symbol { library: 65, above: false }),
        ("CR", Symbol { library: 63, above: false }),
        ("C-", Hairpin { closing: true }),
        ("C", Hairpin { closing: false }),
        ("OB", Ottava { below: true }),
    ]
};

const OTTAVA_ABOVE: (&str, MarkKind) = ("O", MarkKind::Ottava { below: false });

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Target {
    /// Notes `first..=last`.
    Notes { first: u32, last: u32 },
    /// A line from position `start` to `end` in note numbers, fractions in between.
    Span { start: f32, end: f32 },
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Mark {
    pub kind: MarkKind,
    pub flipped: bool,
    pub target: Target,
}

pub fn parse(text: &str) -> Result<Vec<Mark>, InputError> {
    entries(text, PASS)?.iter().filter(|e| !e.text.trim().is_empty()).map(parse_entry).collect()
}

fn word(c: &mut Cursor) -> Option<MarkKind> {
    WORDS
        .iter()
        .chain(std::iter::once(&OTTAVA_ABOVE))
        .filter(|(w, _)| c.rest().starts_with(w))
        .max_by_key(|(w, _)| w.len())
        .map(|(w, kind)| {
            c.eat_word(w);
            *kind
        })
}

fn parse_entry(entry: &Entry) -> Result<Mark, InputError> {
    let mut c = entry.cursor(PASS);
    c.skip_spaces();
    let flipped = c.eat(b'-');
    let kind = word(&mut c).ok_or_else(|| c.unexpected())?;
    c.skip_spaces();
    let first = c.number().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    let target = if kind.is_line() {
        c.skip_spaces();
        let end = c.number().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
        Target::Span { start: first, end }
    } else if c.eat(b':') {
        let last = c.number().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
        Target::Notes { first: first as u32, last: last as u32 }
    } else {
        Target::Notes { first: first as u32, last: first as u32 }
    };
    c.skip_spaces();
    c.finish()?;
    Ok(Mark { kind, flipped, target })
}

/// Steps a mark on the note-head side must move to clear the staff, in tenths of P11.
/// The clearance a P11 mark code gets (codes of the table at 0x7946E4).
fn clearance_of(code: i32) -> Clearance {
    match code {
        5 => Clearance::Accent,
        4 | 8 | 9 | 10 | 19 => Clearance::Staff,
        _ => Clearance::None,
    }
}

/// 0x4D9475 as the beam pass uses it: a note whose stem was turned by a beam gets the
/// clearance of its mark computed again for the new stem side.
pub(crate) fn recompute_clearance(note: &mut Note) {
    let code = note.mark as i32;
    if code > 0 {
        note.mark = code as f32 + clearance(note, clearance_of(code)) / 10.0;
    }
}

fn clearance(note: &Note, clearance: Clearance) -> f32 {
    let steps = if note.down { 10 - note.stem_level() } else { note.stem_level() - 4 };
    let base = steps.clamp(0, 9) as f32;
    match clearance {
        Clearance::None => 0.0,
        Clearance::Staff => base,
        Clearance::Accent => (base + 0.5).min(9.0),
    }
}

/// Highest point of a note: the stem end for an up stem, else the top head.
fn top(note: &Note) -> f32 {
    if note.down {
        note.highest() as f32
    } else {
        (note.lowest() + STEM) as f32 + note.extension
    }
}

/// Lowest point of a note: the stem end for a down stem, else the bottom head.
fn bottom(note: &Note) -> f32 {
    if note.down {
        (note.highest() - STEM) as f32 - note.extension
    } else {
        note.lowest() as f32
    }
}

/// P3 of a position given in note numbers; fractions interpolate to the next note.
fn position(line: &Line, at: f32) -> Option<f32> {
    let whole = at.floor() as usize;
    let x = line.note(whole)?.x;
    let fraction = at - at.floor();
    if fraction == 0.0 {
        return Some(x);
    }
    let next = line.note(whole + 1).map_or(x, |n| n.x);
    Some(x + fraction * (next - x))
}

fn no_such_note(at: f32) -> InputError {
    InputError::new(PASS, crate::Span::default(), ErrorKind::NoSuchNote(at))
}

/// Code-7 lines end this far right of the note they end on.
const LINE_END_OVERHANG: f32 = 25.0 / 6.0;

fn line_item(line: &Line, kind: MarkKind, start: f32, end: f32) -> Result<score_format::Item, InputError> {
    let x1 = position(line, start).ok_or_else(|| no_such_note(start))?;
    let x2 = position(line, end).ok_or_else(|| no_such_note(end))?;
    let covered: Vec<&Note> = line.notes().filter(|n| n.x >= x1 && n.x <= x2).collect();
    let highest = covered.iter().map(|n| top(n)).fold(f32::MIN, f32::max);
    let lowest = covered.iter().map(|n| bottom(n)).fold(f32::MAX, f32::min);
    let staff = line.staff;
    Ok(match kind {
        MarkKind::Trill { accidental } => {
            item(&[7.0, staff, x1, (highest + 2.0).max(12.5), 1.0, x2 + LINE_END_OVERHANG, 0.0, accidental as f32])
        }
        MarkKind::Ottava { below: false } => item(&[
            7.0,
            staff,
            x1,
            (highest + 2.0).max(12.5),
            1.0,
            x2 + LINE_END_OVERHANG,
            8.0,
            0.0,
            0.0,
            0.0,
            0.0,
            -1.0,
        ]),
        MarkKind::Ottava { below: true } => item(&[
            7.0,
            staff,
            x1,
            (lowest - 5.0).min(-1.5),
            1.0,
            x2 + LINE_END_OVERHANG,
            -8.0,
            0.0,
            0.0,
            0.0,
            0.0,
            1.0,
        ]),
        MarkKind::Hairpin { closing } => {
            item(&[4.0, staff, x1, (lowest - 3.5).min(0.0), 999.0, x2, if closing { -1.0 } else { 0.0 }])
        }
        _ => unreachable!("not a line mark"),
    })
}

fn symbol_item(note: &Note, staff: f32, library: i32, above: bool) -> score_format::Item {
    let level = match (above, note.down) {
        (true, true) => (note.highest() + 3).max(14),
        (true, false) => 14,
        (false, false) => (note.lowest() - 5).min(-2),
        (false, true) => -2,
    };
    let mut params = [0.0; 15];
    params[..6].copy_from_slice(&[9.0, staff, note.x, level as f32, library as f32, 1.0]);
    params[14] = -0.5;
    item(&params)
}

fn tremolo_item(note: &Note, staff: f32, beams: i32, offset: i32) -> score_format::Item {
    let level = note.stem_level() as f32;
    let (position, direction) = if note.down {
        (level + offset as f32 - note.extension, -20.0)
    } else {
        (level - offset as f32 + note.extension, -10.0)
    };
    item(&[6.0, staff, note.x, position, 0.0, 0.0, direction, 0.0, 0.0, (10 + beams) as f32])
}

pub(crate) fn apply(line: &mut Line, marks: &[Mark]) -> Result<(), InputError> {
    for mark in marks {
        match (mark.kind, mark.target) {
            (kind, Target::Span { start, end }) => {
                let made = line_item(line, kind, start, end)?;
                line.attachments.push(made);
            }
            (kind, Target::Notes { first, last }) => {
                for number in first..=last {
                    apply_to_note(line, kind, mark.flipped, number as usize)?;
                }
            }
        }
    }
    Ok(())
}

fn apply_to_note(line: &mut Line, kind: MarkKind, flipped: bool, number: usize) -> Result<(), InputError> {
    let staff = line.staff;
    let note = line.note_mut(number).ok_or_else(|| no_such_note(number as f32))?;
    match kind {
        MarkKind::Head { code, clearance: kind } => {
            note.mark = if flipped { -code as f32 } else { code as f32 + clearance(note, kind) / 10.0 };
        }
        MarkKind::Symbol { library, above } => {
            let made = symbol_item(note, staff, library, above != flipped);
            line.attachments.push(made);
        }
        MarkKind::Tremolo { beams, offset } => {
            let made = tremolo_item(note, staff, beams, offset);
            line.attachments.push(made);
        }
        _ => unreachable!("line marks take a span"),
    }
    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn words_targets_and_flips() {
        let marks = parse("A 1/S 2:4/-T 5/TRW 1 2.7/C- 2 3/O 5 7/OB 7 8/F3 2/TMS 8;").unwrap();
        assert_eq!(marks.len(), 9);
        assert_eq!(marks[1].target, Target::Notes { first: 2, last: 4 });
        assert!(marks[2].flipped);
        assert_eq!(marks[3].kind, MarkKind::Trill { accidental: 0 });
        assert_eq!(marks[3].target, Target::Span { start: 1.0, end: 2.7 });
        assert_eq!(marks[4].kind, MarkKind::Hairpin { closing: true });
        assert_eq!(marks[5].kind, MarkKind::Ottava { below: false });
        assert_eq!(marks[6].kind, MarkKind::Ottava { below: true });
        assert_eq!(marks[7].kind, MarkKind::Head { code: 33, clearance: Clearance::None });
        assert_eq!(marks[8].kind, MarkKind::Tremolo { beams: 2, offset: 1 });
    }
}
