//! Passes 4 and 5: beams and slurs between numbered notes, read by the item parser 0x4DA9C3
//! (analysis/engine/input.md, "Passes 4 and 5").
//!
//! Both passes share a syntax: pairs of note numbers (`1 4`), separated by `/` or `,`; a
//! third number is ignored, and a single number or an end not after the start means the
//! next note. A sign in front of either number puts the beam or slur above (`+`) or below
//! (`-`). Written without a space after the first number, `1+4` is only a separator (as in
//! SCORE 4's own files), while `1-2` is the number -12. Adding 100 times k to a note number
//! puts the number k over the beam, or a tuplet bracket numbered k over the slur. `Xk a b c`
//! makes the pairs (a, a + k - 1), (b, b + k - 1), ... (0x4E4D40). Pass 4 also has automatic
//! beams: `nB` or `nBp` (every n eighths, after p notes) and `B` or `A` alone (by the last
//! meter).

use crate::error::{ErrorKind, InputError, Pass};
use crate::motives::Motives;
use crate::notes::Meter;
use crate::reader;
use crate::scan::{entries, Cursor, Entry};

/// Where a beam or slur goes relative to the notes, if the input says so.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Side {
    Above,
    Below,
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Connection {
    pub first: usize,
    pub last: usize,
    /// Signs typed with the first and with the second number.
    pub sides: [Option<Side>; 2],
    /// Tuplet number written over a beam (100s of a note number).
    pub tuplet: u32,
    /// Fractions of the way to the next note (slurs only: `1.5 3`).
    pub fractions: [f32; 2],
}

impl Connection {
    pub fn new(first: usize, last: usize) -> Self {
        Connection { first, last, sides: [None, None], tuplet: 0, fractions: [0.0, 0.0] }
    }

    /// The typed side: the first number's sign, else the second's.
    pub fn side(&self) -> Option<Side> {
        self.sides[0].or(self.sides[1])
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum ConnectEntry {
    Pair(Connection),
    /// `xB` / `xBy`: beam every `eighths` eighth notes, starting after `pickup` notes.
    EveryEighths { eighths: u32, pickup: u32 },
}

/// A note number as typed: sign, tuplet hundreds and the number itself.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Endpoint {
    side: Option<Side>,
    note: usize,
    tuplet: u32,
    fraction: f32,
}

impl Endpoint {
    fn from_value(side: Option<Side>, value: f32) -> Self {
        let whole = value.trunc() as u32;
        Endpoint { side, note: (whole % 100) as usize, tuplet: whole / 100 % 100, fraction: value.fract() }
    }
}

fn endpoint(c: &mut Cursor, pass: Pass) -> Option<Endpoint> {
    let side = if c.eat(b'+') {
        Some(Side::Above)
    } else if c.eat(b'-') {
        Some(Side::Below)
    } else {
        None
    };
    let value = c.number()?;
    // 0x5194D5 reads on through a `-` between digits: `1-2` is -12.
    let (side, value) = if c.peek_raw() == Some(b'-') && c.peek_raw_at(1).is_some_and(|b| b.is_ascii_digit()) {
        c.bump();
        let rest = c.integer().unwrap_or(0);
        let digits = format!("{}{rest}", value.trunc() as u32);
        (Some(Side::Below), digits.parse().unwrap_or(0.0))
    } else {
        (side, value)
    };
    // Beams take whole note numbers.
    let value = if pass == Pass::Beams { value.trunc() } else { value };
    Some(Endpoint::from_value(side, value))
}

/// An end 0: the builders take the next note.
const NEXT_NOTE: Endpoint = Endpoint { side: None, note: 0, tuplet: 0, fraction: 0.0 };

fn connection(a: Endpoint, b: Endpoint) -> Connection {
    let tuplet = if b.tuplet != 0 { b.tuplet } else { a.tuplet };
    Connection { first: a.note, last: b.note, sides: [a.side, b.side], tuplet, fractions: [a.fraction, b.fraction] }
}

/// An item of pass 4 or 5 before its partner is known.
enum Parsed {
    /// `a b` (a third number ignored), or `a` alone, whose end is the first number of the
    /// next item (0, the next note, in the last item).
    Pair(Endpoint, Option<Endpoint>),
    Groups(Vec<Connection>),
}

impl Parsed {
    fn first(&self) -> Option<Endpoint> {
        match self {
            Parsed::Pair(a, _) => Some(*a),
            Parsed::Groups(_) => None,
        }
    }
}

fn pair(c: &mut Cursor, pass: Pass) -> Result<Option<Parsed>, InputError> {
    let Some(a) = endpoint(c, pass) else {
        return if c.at_end() { Ok(None) } else { Err(c.error_here(ErrorKind::ExpectedNumber)) };
    };
    let tight_plus = c.peek_raw() == Some(b'+');
    let b = endpoint(c, pass).map(|b| if tight_plus { Endpoint { side: None, ..b } } else { b });
    c.skip_rest();
    Ok(Some(Parsed::Pair(a, b)))
}

/// `Xk a b c`: the pairs (a, a + k - 1), (b, b + k - 1), ...
fn groups(c: &mut Cursor, pass: Pass) -> Result<Vec<Connection>, InputError> {
    c.bump();
    let size = c.digit().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))? as usize;
    let starts: Vec<Endpoint> = std::iter::from_fn(|| endpoint(c, pass)).collect();
    if !c.at_end() {
        return Err(c.unexpected());
    }
    Ok(starts
        .into_iter()
        .map(|s| Connection { sides: [s.side, None], tuplet: s.tuplet, ..Connection::new(s.note, s.note + size - 1) })
        .collect())
}

fn parse_entry(entry: &Entry, pass: Pass) -> Result<Option<Parsed>, InputError> {
    let mut c = entry.spaced_cursor(pass);
    if c.peek() == Some(b'X') {
        return groups(&mut c, pass).map(|g| Some(Parsed::Groups(g)));
    }
    pair(&mut c, pass)
}

pub fn parse(text: &str, pass: Pass, motives: &mut Motives) -> Result<Vec<ConnectEntry>, InputError> {
    if pass == Pass::Beams {
        if let Some(automatic) = automatic_beams(text, motives.carried.last_meter) {
            return Ok(automatic.into_iter().collect());
        }
    }
    let read = reader::read_connections(text);
    let in_typed_text = |err: InputError| InputError { span: read.origin_span(err.span), ..err };
    let parsed: Vec<Parsed> = entries(&read.text, pass, motives)
        .map_err(in_typed_text)?
        .iter()
        .filter(|e| !e.text.trim().is_empty())
        .map(|e| parse_entry(e, pass).map_err(in_typed_text))
        .collect::<Result<Vec<_>, _>>()?
        .into_iter()
        .flatten()
        .collect();
    // 0x4DA9C3 reads a single number's partner past the `/`.
    let next_firsts = parsed.iter().skip(1).map(Parsed::first).chain(std::iter::once(None));
    let connections = parsed.iter().zip(next_firsts).flat_map(|(item, next)| match item {
        Parsed::Pair(a, b) => vec![connection(*a, b.or(next).unwrap_or(NEXT_NOTE))],
        Parsed::Groups(groups) => groups.clone(),
    });
    Ok(connections.map(ConnectEntry::Pair).collect())
}

/// Pass 4's automatic beams (0x4DA9C3): `B` or `A` as the first character beams by the last
/// meter; otherwise a digit followed by `B` in the first 10 characters (not `B[`, not after
/// `@`) makes the first item `n B p`, its first two numbers, signs ignored. Any further item
/// leaves no beams at all. None when the pass is not automatic; Some(None) for no beams.
fn automatic_beams(text: &str, meter: Option<Meter>) -> Option<Option<ConnectEntry>> {
    let body: String = text.split(';').next().unwrap_or("").to_ascii_uppercase();
    match body.trim_start().bytes().next() {
        Some(b'B' | b'A') => {
            let eighths = meter.map_or(Some(2), eighths_for_meter);
            return Some(eighths.map(|eighths| ConnectEntry::EveryEighths { eighths, pickup: 0 }));
        }
        None => return None,
        Some(_) => {}
    }
    let head: Vec<u8> = body.bytes().take(10).collect();
    let digit = head.iter().position(u8::is_ascii_digit)?;
    let b = head.iter().enumerate().skip(digit + 1).position(|(i, &c)| c == b'B' && head.get(i + 1) != Some(&b'['))? + digit + 1;
    if head[..b].contains(&b'@') {
        return None;
    }
    let mut items = body.split(['/', ',']).filter(|item| !item.trim().is_empty());
    let first = items.next().unwrap_or("");
    if items.next().is_some() {
        return Some(None);
    }
    let mut numbers = first.split(|c: char| !c.is_ascii_digit()).filter(|n| !n.is_empty()).map(|n| n.parse::<u32>().unwrap_or(0));
    let eighths = numbers.next().unwrap_or(0);
    let pickup = numbers.next().unwrap_or(0);
    Some(Some(ConnectEntry::EveryEighths { eighths, pickup }))
}

/// `B`/`A`: groups by the meter (0x78D918): 2 eighths in x/4 and common time, 4 in x/2 and
/// cut time, 8 in x/1; in x/8, 2 for x = 2, 4, 8 and 3 for x = 3, 6, 9, 12. None: no beams.
fn eighths_for_meter(meter: Meter) -> Option<u32> {
    match meter {
        Meter::Common => Some(2),
        Meter::Cut => Some(4),
        Meter::Fraction(_, 4) => Some(2),
        Meter::Fraction(_, 2) => Some(4),
        Meter::Fraction(_, 1) => Some(8),
        Meter::Fraction(2 | 4 | 8, 8) => Some(2),
        Meter::Fraction(3 | 6 | 9 | 12, 8) => Some(3),
        Meter::Fraction(..) => None,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn pairs(text: &str, pass: Pass) -> Vec<(usize, usize, Option<Side>, u32)> {
        parse(text, pass, &mut Motives::new())
            .unwrap()
            .into_iter()
            .filter_map(|e| match e {
                ConnectEntry::Pair(c) => Some((c.first, c.last, c.side(), c.tuplet)),
                _ => None,
            })
            .collect()
    }

    #[test]
    fn pairs_signs_and_tuplets() {
        assert_eq!(
            pairs("1 2/-4 306/7 +309/1+4;", Pass::Beams),
            [(1, 2, None, 0), (4, 6, Some(Side::Below), 3), (7, 9, Some(Side::Above), 3), (1, 4, None, 0)]
        );
        assert_eq!(pairs("1 2 3/5/1.5 3;", Pass::Beams), [(1, 2, None, 0), (5, 1, None, 0), (1, 3, None, 0)]);
        assert_eq!(pairs("1/-4 7/3;", Pass::Beams), [(1, 4, Some(Side::Below), 0), (4, 7, Some(Side::Below), 0), (3, 0, None, 0)]);
        assert_eq!(pairs("1-2;", Pass::Slurs), [(12, 0, Some(Side::Below), 0)]);
        assert_eq!(pairs("X3 1 4 7;", Pass::Slurs), [(1, 3, None, 0), (4, 6, None, 0), (7, 9, None, 0)]);
    }

    #[test]
    fn automatic_beams() {
        let auto = |text: &str| parse(text, Pass::Beams, &mut Motives::new()).unwrap();
        assert_eq!(auto("2B2;"), [ConnectEntry::EveryEighths { eighths: 2, pickup: 2 }]);
        assert_eq!(auto("+2B;"), [ConnectEntry::EveryEighths { eighths: 2, pickup: 0 }]);
        assert_eq!(auto("B;"), [ConnectEntry::EveryEighths { eighths: 2, pickup: 0 }]);
        assert!(auto("2B/1 2;").is_empty());
    }
}
