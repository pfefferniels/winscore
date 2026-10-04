//! Passes 4 and 5: beams and slurs between numbered notes.
//!
//! Both passes share a syntax: pairs of note numbers (`1 4`), separated by `/`. A sign in
//! front of either number puts the beam or slur above (`+`) or below (`-`). Written without
//! a space after the first number, `1+4` is only a separator (as in SCORE 4's own files);
//! the engine misreads `1-4`, which is therefore an error here. Adding 100 times n to a
//! note number puts the tuplet number n over the beam. `Xn a b c` makes groups of n notes starting at a, b, c.
//! Pass 4 also has `xB` (beam every x eighths) and `xBy` (after y pickup notes).

use crate::error::{ErrorKind, InputError, Pass};
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

fn endpoint(c: &mut Cursor, pass: Pass) -> Result<Endpoint, InputError> {
    c.skip_spaces();
    let side = if c.eat(b'+') {
        Some(Side::Above)
    } else if c.eat(b'-') {
        Some(Side::Below)
    } else {
        None
    };
    let value = if pass == Pass::Slurs { c.number() } else { c.integer().map(|n| n as f32) };
    let value = value.ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
    let whole = value.trunc() as u32;
    Ok(Endpoint { side, note: (whole % 100) as usize, tuplet: whole / 100, fraction: value.fract() })
}

fn pair(c: &mut Cursor, pass: Pass) -> Result<Connection, InputError> {
    let a = endpoint(c, pass)?;
    let tight_plus = c.peek() == Some(b'+');
    if c.peek() == Some(b'-') {
        return Err(c.unexpected());
    }
    let mut b = endpoint(c, pass)?;
    if tight_plus {
        b.side = None;
    }
    let tuplet = if b.tuplet != 0 { b.tuplet } else { a.tuplet };
    Ok(Connection { first: a.note, last: b.note, sides: [a.side, b.side], tuplet, fractions: [a.fraction, b.fraction] })
}

fn groups(c: &mut Cursor, pass: Pass) -> Result<Vec<Connection>, InputError> {
    c.bump();
    let size = c.digit().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))? as usize;
    let starts: Vec<Endpoint> = std::iter::from_fn(|| {
        c.skip_spaces();
        (!c.at_end()).then(|| endpoint(c, pass))
    })
    .collect::<Result<_, _>>()?;
    Ok(starts
        .into_iter()
        .map(|s| Connection { sides: [s.side, None], tuplet: s.tuplet, ..Connection::new(s.note, s.note + size - 1) })
        .collect())
}

fn parse_entry(entry: &Entry, pass: Pass) -> Result<Vec<ConnectEntry>, InputError> {
    let mut c = entry.cursor(pass);
    c.skip_spaces();
    if c.peek() == Some(b'X') {
        return Ok(groups(&mut c, pass)?.into_iter().map(ConnectEntry::Pair).collect());
    }
    if pass == Pass::Beams && c.rest().contains('B') {
        let eighths = c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
        if !c.eat(b'B') {
            return Err(c.unexpected());
        }
        let pickup = c.integer().unwrap_or(0);
        c.finish()?;
        return Ok(vec![ConnectEntry::EveryEighths { eighths, pickup }]);
    }
    let made = pair(&mut c, pass)?;
    c.skip_spaces();
    c.finish()?;
    Ok(vec![ConnectEntry::Pair(made)])
}

pub fn parse(text: &str, pass: Pass) -> Result<Vec<ConnectEntry>, InputError> {
    let parsed: Vec<Vec<ConnectEntry>> = entries(text, pass)?
        .iter()
        .filter(|e| !e.text.trim().is_empty())
        .map(|e| parse_entry(e, pass))
        .collect::<Result<_, _>>()?;
    Ok(parsed.into_iter().flatten().collect())
}

#[cfg(test)]
mod tests {
    use super::*;

    fn pairs(text: &str, pass: Pass) -> Vec<(usize, usize, Option<Side>, u32)> {
        parse(text, pass)
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
    }

    #[test]
    fn groups_and_every_eighths() {
        assert_eq!(pairs("X3 1 4 7;", Pass::Slurs), [(1, 3, None, 0), (4, 6, None, 0), (7, 9, None, 0)]);
        assert_eq!(parse("2B2;", Pass::Beams).unwrap(), [ConnectEntry::EveryEighths { eighths: 2, pickup: 2 }]);
    }
}
