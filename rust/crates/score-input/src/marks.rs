//! Pass 3: marks on numbered notes.
//!
//! An item is a mark name, optionally preceded by `-` (the other side of the note), and note
//! numbers: `S 2`, `S 1 3 4`, `S 2:5` (notes 2 to 5); the two-point marks take pairs, `C 1 3`.
//! Notes and chords are numbered from 1, numbers beyond the last note mean the last note, and
//! a fraction rounds to the nearest note for note marks but places symbols and lines between
//! notes. Most marks go into the note's P11; dynamics, words and `Nk` become code-9 symbols,
//! `TM…` code-6 tremolo beams, `TRW…`, `O`, `OB` code-7 lines and `C`, `C-` code-4 hairpins.
//! Grammar and probes: analysis/engine/input.md, "Pass 3: marks" (reader 0x426950, parser
//! 0x4DAEB2, builder 0x4D8460).

use crate::error::{ErrorKind, InputError, Pass, Span};
use crate::line::{item, Line, Note, STEM};
use crate::motives::Motives;
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
    /// A code-9 library symbol above or below the staff; `numbered` for `Nk`.
    Symbol { library: i32, above: bool, numbered: bool },
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
    /// The kind of mark number m (0x4D8460); `Nk` gives m = -k.
    fn of(m: i32) -> Option<Self> {
        let above = |library: i32| matches!(library, 66 | 67);
        Some(match m {
            m if m < 0 => MarkKind::Symbol { library: -m, above: above(-m), numbered: true },
            1..=44 => MarkKind::Head { code: m, clearance: clearance_of(m) },
            45..=70 => MarkKind::Symbol { library: m, above: above(m), numbered: false },
            91..=94 => MarkKind::Tremolo { beams: m - 90, offset: if m == 91 { 2 } else { 1 } },
            95 | 96 => MarkKind::Ottava { below: m == 95 },
            97 | 98 => MarkKind::Hairpin { closing: m == 98 },
            120..=123 => MarkKind::Trill { accidental: m - 120 },
            _ => return None,
        })
    }

    fn is_line(self) -> bool {
        matches!(self, MarkKind::Trill { .. } | MarkKind::Ottava { .. } | MarkKind::Hairpin { .. })
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Target {
    /// One number: the nearest note for note marks, a place between notes for symbols.
    At(f32),
    /// Notes `first..=last` (`a:b`).
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

/// A note number as the parser leaves it in the token list; `a:` starts a range.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Number {
    value: f32,
    range_start: bool,
}

/// One item: a mark and its numbers.
#[derive(Debug, Clone, PartialEq)]
struct MarkItem {
    kind: MarkKind,
    flipped: bool,
    numbers: Vec<Number>,
    entry: Entry,
}

pub fn parse(text: &str, motives: &mut Motives) -> Result<Vec<Mark>, InputError> {
    let pieces: Vec<Entry> = entries(text, PASS, motives)?.iter().flat_map(reader_items).collect();
    let mut items: Vec<MarkItem> = Vec::new();
    for piece in &pieces {
        match parse_item(piece)? {
            Some(item) => items.push(item),
            None => repeat_last_number(&mut items),
        }
    }
    let marks = items.iter().map(targets).collect::<Result<Vec<_>, _>>()?;
    Ok(marks.into_iter().flatten().collect())
}

/// An empty item repeats the last token of the list, the previous item's last number.
fn repeat_last_number(items: &mut [MarkItem]) {
    if let Some(last) = items.last_mut() {
        if let Some(&number) = last.numbers.last() {
            last.numbers.push(Number { range_start: false, ..number });
        }
    }
}

/// The items of an entry as the reader (0x426950) leaves them: a letter or `-` typed after a
/// digit or a space starts a new item, a `+` before a letter is cut off from it, `~` is a
/// space and `%`, `&`, `(` are not stored.
fn reader_items(entry: &Entry) -> Vec<Entry> {
    let bytes = entry.text.as_bytes();
    let starts_item = |i: usize| {
        let (before, here) = (bytes[i - 1], bytes[i]);
        let letter = here > b'@';
        ((letter || here == b'-') && (before.is_ascii_digit() || before == b' ')) || (letter && before == b'+')
    };
    let cuts: Vec<usize> = std::iter::once(0)
        .chain((1..bytes.len()).filter(|&i| starts_item(i)))
        .chain(std::iter::once(bytes.len()))
        .collect();
    let pieces: Vec<Entry> = cuts
        .windows(2)
        .map(|w| Entry {
            text: entry.text[w[0]..w[1]]
                .chars()
                .filter(|c| !matches!(c, '%' | '&' | '('))
                .map(|c| if c == '~' { ' ' } else { c })
                .collect(),
            start: entry.start + w[0],
            motive: entry.motive,
        })
        .collect();
    // The blank left before a slash the reader put in is not an item of its own.
    match pieces.len() {
        1 => pieces,
        _ => pieces.into_iter().filter(|p| !p.text.trim().is_empty()).collect(),
    }
}

fn parse_item(entry: &Entry) -> Result<Option<MarkItem>, InputError> {
    let mut c = entry.cursor(PASS);
    c.skip_spaces();
    if c.at_end() {
        return Ok(None);
    }
    let flipped = c.eat(b'-') || c.eat(b'+');
    let word = Entry { text: spelled_short(c.rest()), start: c.position(), motive: None };
    let mut c = word.cursor(PASS);
    let m = mark_number(&mut c)?;
    let kind = MarkKind::of(m).ok_or_else(|| word.error(PASS, ErrorKind::Unexpected(word.text.clone())))?;
    let numbers = numbers(&mut c)?;
    if numbers.is_empty() {
        return Err(c.error_here(ErrorKind::ExpectedNumber));
    }
    Ok(Some(MarkItem { kind, flipped, numbers, entry: entry.clone() }))
}

/// Longer spellings 0x4DAEB2 rewrites before parsing (loop at 0x4DAF60). `TRE` also takes an
/// `M` after it, `TRI` the `L`s.
const SPELLINGS: [(&str, &str); 14] = [
    ("TRE", "TM"),
    ("TRI", "TR"),
    ("ACCS", "AS"),
    ("ACC", "A"),
    ("DIM", "DI"),
    ("RIT", "R"),
    ("WES", "W"),
    ("DC", "C-"),
    ("HA", "H"),
    ("HV", "HW"),
    ("PI", "PZ"),
    ("AR", "AO"),
    ("DN", "D"),
    ("UP", "U"),
];

/// The text of an item from its mark name on, with a longer spelling replaced.
fn spelled_short(text: &str) -> String {
    let found = SPELLINGS.iter().filter(|(long, _)| text.starts_with(long)).max_by_key(|(long, _)| long.len());
    let Some(&(long, short)) = found else {
        return text.to_string();
    };
    let rest = &text[long.len()..];
    let rest = match long {
        "TRE" => rest.strip_prefix('M').unwrap_or(rest),
        "TRI" => rest.trim_start_matches('L'),
        _ => rest,
    };
    format!("{short}{rest}")
}

/// The mark number of a mark name (0x4DAEB2): its first letter and the characters right
/// after it, as far as they count. The parser takes any character there, digits included.
fn mark_number(c: &mut Cursor) -> Result<i32, InputError> {
    let reject = c.error_here(ErrorKind::Unexpected("mark name".into()));
    let first = c.bump().ok_or_else(|| reject.clone())?;
    let m = match first {
        b'A' => match adjacent(c) {
            Some(b'C') if c.eat(b'T') => 25,
            Some(b'C') => 68,
            Some(b'S') => 9,
            Some(b'O') => 67,
            Some(b'R') => 15,
            _ => 5,
        },
        b'C' => match adjacent(c) {
            Some(b'R') => 63,
            Some(b'-') => 98,
            _ => 97,
        },
        b'D' => match adjacent(c) {
            Some(b'I') => 64,
            _ => 11,
        },
        b'F' => dynamic_f(c).ok_or(reject)?,
        b'H' => match adjacent(c) {
            Some(_) => 19,
            None => 13,
        },
        b'I' => {
            adjacent(c);
            18
        }
        b'M' => match adjacent(c) {
            Some(b'F') => 55,
            Some(b'P') => 54,
            _ => 17,
        },
        b'N' => match c.number().map(f32::round) {
            Some(k) if k >= 1.0 => -(k as i32),
            _ => return Err(reject),
        },
        b'O' => match adjacent(c) {
            Some(b'B') => 95,
            _ => 96,
        },
        b'P' => match adjacent(c) {
            None => 53,
            Some(b'P') => match adjacent(c) {
                Some(_) => 51,
                None => 52,
            },
            Some(b'Z') => 66,
            Some(_) => 24,
        },
        b'R' => {
            adjacent(c);
            65
        }
        b'S' => match adjacent(c) {
            None => 7,
            Some(second) => match (second, adjacent(c)) {
                (_, Some(_)) => 62,
                (b'2'..=b'4', None) => 26 + i32::from(second - b'2'),
                _ => 61,
            },
        },
        b'T' => match adjacent(c) {
            None => 6,
            Some(b'S') => 10,
            Some(b'H') => 16,
            Some(b'R') => trill(c),
            Some(_) => match adjacent(c) {
                Some(b'E') => 91,
                Some(b'S') => 92,
                Some(digit @ b'1'..=b'4') => 90 + i32::from(digit - b'0'),
                _ => 93,
            },
        },
        // The rewrite loop blanks the character after a U.
        b'U' => {
            adjacent(c);
            12
        }
        b'W' => match adjacent(c) {
            Some(_) => 8,
            None => 4,
        },
        _ => return Err(reject),
    };
    Ok(m)
}

/// The character right after the mark letters read so far, taken; None at a space or the end.
fn adjacent(c: &mut Cursor) -> Option<u8> {
    c.peek().filter(|b| *b != b' ')?;
    c.bump()
}

/// After an `F`: `FP`, `FE` (fermata), `FI` + F/S/N (musica ficta), `F0`…`F9` (fingering),
/// `FF`, `FFF`; anything else right after it is refused.
fn dynamic_f(c: &mut Cursor) -> Option<i32> {
    let Some(second) = adjacent(c) else {
        return Some(56);
    };
    Some(match second {
        b'P' => 60,
        b'E' => 14,
        b'I' => match adjacent(c) {
            Some(b'S') => 2,
            Some(b'N') => 3,
            _ => 1,
        },
        b'0'..=b'9' => 30 + i32::from(second - b'0'),
        b'F' => match adjacent(c) {
            None => 57,
            Some(b'F') => 58,
            Some(_) => return None,
        },
        _ => return None,
    })
}

/// After `TR`: an accidental letter (`TRS`, `TRN`, any other letter is `TRF`), then `W` for
/// the wavy line.
fn trill(c: &mut Cursor) -> i32 {
    let mut m = 20;
    while let Some(letter) = adjacent(c) {
        if letter == b'W' {
            return m + 100;
        }
        m = match letter {
            b'S' => 22,
            b'N' => 23,
            _ => 21,
        };
    }
    m
}

/// The note numbers after the mark name, each with an optional sign; `a:b` is a range.
fn numbers(c: &mut Cursor) -> Result<Vec<Number>, InputError> {
    let mut out = Vec::new();
    loop {
        c.skip_spaces();
        if c.at_end() {
            return Ok(out);
        }
        c.eat(b'+');
        let negative = c.eat(b'-');
        let value = c.number().ok_or_else(|| c.unexpected())?;
        c.skip_spaces();
        let range_start = c.eat(b':') || c.eat(b'\'');
        out.push(Number { value: if negative { -value } else { value }, range_start });
    }
}

/// The marks of one item: pairs for the two-point marks (`:` only separates there), ranges
/// and single numbers for the others.
fn targets(item: &MarkItem) -> Result<Vec<Mark>, InputError> {
    let mark = |target| Mark { kind: item.kind, flipped: item.flipped, target };
    let unpaired = || item.entry.error(PASS, ErrorKind::ExpectedNumber);
    if item.kind.is_line() {
        return item
            .numbers
            .chunks(2)
            .map(|pair| match pair {
                [start, end] => Ok(mark(Target::Span { start: start.value, end: end.value })),
                _ => Err(unpaired()),
            })
            .collect();
    }
    let mut numbers = item.numbers.iter();
    let mut marks = Vec::new();
    while let Some(number) = numbers.next() {
        let target = if number.range_start {
            let end = numbers.next().ok_or_else(unpaired)?;
            // 0x4D8460 truncates both ends of a range.
            Target::Notes { first: end_of_range(number.value), last: end_of_range(end.value) }
        } else {
            Target::At(number.value)
        };
        marks.push(mark(target));
    }
    Ok(marks)
}

fn end_of_range(value: f32) -> u32 {
    value.max(0.0) as u32
}

/// The clearance a P11 mark code gets (codes of the table at 0x7946E4).
fn clearance_of(code: i32) -> Clearance {
    match code {
        5 => Clearance::Accent,
        4 | 8 | 9 | 10 | 19 => Clearance::Staff,
        _ => Clearance::None,
    }
}

/// The P11 mark `code` (negative: on the other side) on note `number`, as the refit
/// (0x47C3E8) sends a note's stored mark to the marks pass.
pub(crate) fn stored(code: i32, number: u32) -> Mark {
    let kind = MarkKind::Head { code: code.abs(), clearance: clearance_of(code.abs()) };
    Mark { kind, flipped: code < 0, target: Target::Notes { first: number, last: number } }
}

/// 0x4D9475 as the beam pass uses it: a note whose stem was turned by a beam gets the
/// clearance of its mark computed again for the new stem side.
pub(crate) fn recompute_clearance(note: &mut Note) {
    let code = note.mark as i32;
    if code > 0 {
        note.mark = code as f32 + clearance(note, clearance_of(code)) / 10.0;
    }
}

/// Steps a mark on the note-head side must move to clear the staff, in tenths of P11.
fn clearance(note: &Note, clearance: Clearance) -> f32 {
    let steps = if note.down { 10 - note.stem_level() } else { note.stem_level() - 4 };
    let base = steps.clamp(0, 9) as f32;
    match clearance {
        Clearance::None => 0.0,
        Clearance::Staff => base,
        Clearance::Accent => (base + 0.5).min(9.0),
    }
}

/// Highest point of a note as line marks see it: the stem head, an octave higher for an
/// up stem (stem extensions are not counted).
fn top(note: &Note) -> i32 {
    note.stem_level() + if note.down { 0 } else { STEM }
}

/// Lowest point of a note as line marks see it, the counterpart of `top`.
fn bottom(note: &Note) -> i32 {
    note.stem_level() - if note.down { STEM } else { 0 }
}

/// The notes a line mark keeps clear of (0x4D8460): from the start rounded to the nearest
/// note number up to the end cut down to one.
fn covered(line: &Line, start: f32, end: f32) -> Vec<&Note> {
    let count = line.note_count() as i64;
    let first = (start.round() as i64).min(count).max(1);
    let last = (end.trunc() as i64).min(count);
    (first..=last).filter_map(|n| line.note(n as usize)).collect()
}

/// The staff's left and right ends (0x547AE0), where positions before the first and after
/// the last note lie.
pub(crate) type Edges = (f32, f32);

/// P3 of a position given in note numbers (0x4D8460); a fraction interpolates towards the
/// next note, or the staff's right end after the last note.
fn position(line: &Line, at: f32, (left, right): Edges) -> f32 {
    let whole = at.trunc();
    let x_of = |n: f32| if n < 1.0 { left } else { line.note(n as usize).map_or(right, |note| note.x) };
    let x = x_of(whole);
    let fraction = at - whole;
    if fraction == 0.0 {
        x
    } else {
        (x_of(whole + 1.0) - x) * fraction + x
    }
}

/// The note a number stands for: the nearest one, at least the first, at most the last.
fn nearest_note(line: &Line, at: f32) -> usize {
    (at.round() as i64).clamp(1, line.note_count().max(1) as i64) as usize
}

fn no_such_note(at: f32) -> InputError {
    InputError::new(PASS, Span::default(), ErrorKind::NoSuchNote(at))
}

/// Code-7 lines end this far right of the note they end on.
const LINE_END_OVERHANG: f32 = 25.0 / 6.0;

fn line_item(line: &Line, kind: MarkKind, flipped: bool, (start, end): (f32, f32), edges: Edges) -> score_format::Item {
    let x1 = position(line, start, edges);
    let x2 = position(line, end, edges);
    let covered = covered(line, start, end);
    let highest = covered.iter().map(|n| top(n)).max();
    let lowest = covered.iter().map(|n| bottom(n)).min();
    // Above the staff a line clears notes reaching above the top line, below it notes
    // reaching under the bottom line.
    let above = |clear: f32, default: f32| highest.filter(|h| *h > 10).map_or(default, |h| h as f32 + clear);
    let below = |clear: f32, default: f32| lowest.filter(|l| *l < 4).map_or(default, |l| l as f32 - clear);
    let staff = line.staff;
    match kind {
        MarkKind::Trill { accidental } => {
            item(&[7.0, staff, x1, above(2.0, 12.5), 1.0, x2 + LINE_END_OVERHANG, 0.0, accidental as f32])
        }
        MarkKind::Ottava { below: false } => item(&[
            7.0,
            staff,
            x1,
            above(2.0, 12.5),
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
            below(5.0, -1.5),
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
            let level = if flipped { above(3.5, 14.0) } else { below(3.5, 0.0) };
            item(&[4.0, staff, x1, level, 999.0, x2, if closing { -1.0 } else { 0.0 }])
        }
        _ => unreachable!("not a line mark"),
    }
}

/// P4 of a code-9 symbol (0x4D8460 with 0x4D9475): -2 below or 14 above the staff, moved
/// clear of a stem head below or above the staff. Symbols from `Nk` with k below 50 get the
/// clearance of the P11 marks instead, on either side.
fn symbol_level(note: &Note, library: i32, above: bool) -> f32 {
    let base = if above { 14.0 } else { -2.0 };
    let level = note.stem_level();
    if library > 49 {
        let shift = match (note.down, above) {
            (false, false) if level <= 2 => level - 3,
            (true, true) if level >= 12 => level - 11,
            _ => 0,
        };
        return base + shift as f32;
    }
    let kind = if library == 5 { Clearance::Accent } else { Clearance::Staff };
    base + clearance(note, kind) / 10.0
}

/// P15 of the symbols named by letters (not of `Nk`).
const NAMED_SYMBOL_P15: f32 = -0.5;

fn symbol_item(note: &Note, x: f32, staff: f32, library: i32, above: bool, numbered: bool) -> score_format::Item {
    let mut params = [0.0; 15];
    params[..6].copy_from_slice(&[9.0, staff, x, symbol_level(note, library, above), library as f32, 1.0]);
    if !numbered {
        params[14] = NAMED_SYMBOL_P15;
    }
    item(&params)
}

/// 0x4D8460: P7 is the negated P5 of the stem head (stem plus accidental), and a flagged
/// note gets half a step more stem with the tremolo moved clear of the flags.
fn tremolo_item(note: &mut Note, staff: f32, beams: i32, offset: i32) -> score_format::Item {
    let stem = note.p5s()[0] % 100.0;
    let up = stem < 20.0;
    let flagged = note.tails > 0;
    let reach = offset as f32 - note.extension + if flagged && up { 1.0 } else { 0.0 };
    if flagged {
        note.extension += 0.5;
        note.table_extension += 0.5;
    }
    let level = note.stem_level() as f32;
    let position = if up { level - reach } else { level + reach };
    let whole_or_breve = matches!(note.rhythm.head(), 2 | 3);
    let shift = match (whole_or_breve, stem <= 10.0) {
        (false, _) => 0.0,
        (true, true) => -1.23,
        (true, false) => 1.6,
    };
    let mut params = [0.0; 14];
    params[..10].copy_from_slice(&[6.0, staff, note.x, position, 0.0, 0.0, -stem, 0.0, 0.0, (10 + beams) as f32]);
    params[13] = shift;
    item(&params)
}

pub(crate) fn apply(line: &mut Line, marks: &[Mark], edges: Edges) -> Result<(), InputError> {
    if line.note_count() == 0 && !marks.is_empty() {
        return Err(no_such_note(1.0));
    }
    for mark in marks {
        match mark.target {
            Target::Span { start, end } => {
                let made = line_item(line, mark.kind, mark.flipped, (start, end), edges);
                line.attachments.push(made);
            }
            Target::Notes { first, last } => {
                let count = line.note_count();
                let first = (first as usize).clamp(1, count);
                for number in first..=(last as usize).clamp(first, count) {
                    apply_to_note(line, mark, number, None)?;
                }
            }
            Target::At(at) => {
                let x = position(line, at, edges);
                apply_to_note(line, mark, nearest_note(line, at), Some(x))?;
            }
        }
    }
    Ok(())
}

/// A mark on note `number`; a symbol given by a single number stands at its position `x`,
/// which can lie between notes.
fn apply_to_note(line: &mut Line, mark: &Mark, number: usize, x: Option<f32>) -> Result<(), InputError> {
    let staff = line.staff;
    let note = line.note_mut(number).ok_or_else(|| no_such_note(number as f32))?;
    match mark.kind {
        MarkKind::Head { code, clearance: kind } => {
            note.mark = if mark.flipped { -code as f32 } else { code as f32 + clearance(note, kind) / 10.0 };
        }
        MarkKind::Symbol { library, above, numbered } => {
            let made = symbol_item(note, x.unwrap_or(note.x), staff, library, above != mark.flipped, numbered);
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

    fn parsed(text: &str) -> Vec<Mark> {
        parse(text, &mut Motives::new()).unwrap()
    }

    fn kind(text: &str) -> MarkKind {
        parsed(text)[0].kind
    }

    #[test]
    fn words_targets_and_flips() {
        let marks = parsed("A 1/S 2:4/-T 5/TRW 1 2.7/C- 2 3/O 5 7/OB 7 8/F3 2/TMS 8;");
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

    #[test]
    fn letters_after_the_first_count_as_far_as_the_parser_reads_them() {
        let symbol = |library| MarkKind::Symbol { library, above: false, numbered: false };
        assert_eq!(["PPP 1;", "PP 1;", "P 1;", "MP 1;", "MF 1;", "F 1;", "FF 1;", "FFF 1;", "FP 1;", "SF 1;", "SFZ 1;"].map(kind), [
            51, 52, 53, 54, 55, 56, 57, 58, 60, 61, 62
        ]
        .map(symbol));
        assert_eq!(kind("IM 1;"), kind("I 1;"));
        assert_eq!(kind("TEN 1;"), MarkKind::Tremolo { beams: 3, offset: 1 });
        assert_eq!(kind("TRILLW 1 2;"), MarkKind::Trill { accidental: 0 });
        assert_eq!(kind("N45 1;"), MarkKind::Symbol { library: 45, above: false, numbered: true });
        assert_eq!(kind("AR 1;"), MarkKind::Symbol { library: 67, above: true, numbered: false });
    }

    #[test]
    fn numbers_lists_ranges_and_pairs() {
        let targets = |text| parsed(text).iter().map(|m| m.target).collect::<Vec<_>>();
        assert_eq!(targets("S 1:2 4;"), [Target::Notes { first: 1, last: 2 }, Target::At(4.0)]);
        assert_eq!(targets("C 1 2 3 4;"), [Target::Span { start: 1.0, end: 2.0 }, Target::Span { start: 3.0, end: 4.0 }]);
        assert_eq!(targets("C 1:3;"), [Target::Span { start: 1.0, end: 3.0 }]);
        assert_eq!(parsed("S 1A 2;").len(), 2);
    }

    #[test]
    fn engine_rejections() {
        let rejects = |text| parse(text, &mut Motives::new()).is_err();
        assert!(["O 2;", "C 1;", "+S 2;", "=S 2;", "A -1.5;", "ARCO 2;", "TENUTO 2;", "WEDGE 2;", "8VA 1 3;", "S 1-3;"]
            .iter()
            .all(|t| rejects(t)));
    }
}
