//! Pass 2: one rhythm for every note, chord and rest of pass 1.
//!
//! A value is a number n (4/n quarters: `4` quarter, `6` triplet quarter, `.5` breve), a
//! ratio `n:d` (d quarters in n parts), a letter `W H Q E S D`, a triplet `T` + letter (`T`
//! alone is a triplet eighth) or `G` for a grace note, each followed by dots. Values in one
//! item add up (`QE`, `4 8`). `Xn` makes n copies, `X n m` or `REP n m` repeats the last n
//! values to m copies in all, and an empty item repeats the previous value.
//!
//! The engine turns each item into a token, the duration in quarters plus 1000 per dot
//! (parser 0x4D9EA0), and reads the token back with 0x51C64F. Grammar and probes:
//! analysis/engine/input.md, "Pass 2: rhythms".

use crate::error::{ErrorKind, InputError, Pass};
use crate::motives::Motives;
use crate::num::{amod, trunc};
use crate::scan::{entries, Cursor, Entry};

const PASS: Pass = Pass::Rhythms;

/// P7 of a grace note: not a duration, a marker the spacing and LJ commands recognise.
pub const GRACE_P7: f32 = 65.0;
/// Values per whole note of `G`. The engine also gives this token (64 quarters) to the notes
/// pass 2 leaves without a value.
const GRACE_PER_WHOLE: f32 = 0.0625;
const DOT_TOKEN: f32 = 1000.0;

#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Rhythm {
    /// `quarters` (P7) includes the dots.
    Value { quarters: f32, dots: u8 },
    Grace,
}

impl Rhythm {
    /// 0x51C64F's reading of a token. An infinite duration (the value `0`) is a grace note:
    /// the engine's x87 comparison with 1/16 takes an unordered result for equal.
    pub fn from_token(token: f32) -> Self {
        let quarters = amod(token, DOT_TOKEN);
        if !quarters.is_finite() {
            return Rhythm::Grace;
        }
        let dots = (trunc(token / 100.0) / 10).clamp(0, i32::from(u8::MAX)) as u8;
        let rhythm = Rhythm::Value { quarters, dots };
        if rhythm.per_whole() == GRACE_PER_WHOLE {
            Rhythm::Grace
        } else {
            rhythm
        }
    }

    /// Duration in quarter notes, as stored in P7.
    pub fn quarters(self) -> f32 {
        match self {
            Rhythm::Value { quarters, .. } => quarters,
            Rhythm::Grace => GRACE_P7,
        }
    }

    pub fn dots(self) -> u8 {
        match self {
            Rhythm::Value { dots, .. } => dots,
            Rhythm::Grace => 0,
        }
    }

    /// Values of this length without its dots in a whole note ("type" in 0x51C64F).
    fn per_whole(self) -> f32 {
        match self {
            Rhythm::Value { quarters, .. } if quarters <= 0.0 => 0.0,
            Rhythm::Value { quarters, dots } => 4.0 / undotted(quarters, dots),
            Rhythm::Grace => GRACE_PER_WHOLE,
        }
    }

    /// Note head (P6, 0x51C5DB): 0 black, 1 half, 2 whole, 3 breve.
    pub fn head(self) -> i32 {
        let per_whole = self.per_whole();
        match self {
            Rhythm::Value { .. } if per_whole < 4.0 => match 3 - trunc(per_whole) {
                0 => 1,
                head => head,
            },
            _ => 0,
        }
    }

    /// Number of flags (tails) on an unbeamed stem: one from 8 values per whole note on,
    /// one more at each doubling, at most 10 (0x51C64F).
    pub fn tails(self) -> i32 {
        match self {
            Rhythm::Value { .. } => {
                let count = (f64::from(self.per_whole()) + f64::from(0.001f32)).trunc();
                (0..10).take_while(|k| count >= f64::from(8 << k)).count() as i32
            }
            Rhythm::Grace => 1,
        }
    }
}

/// The duration without its dots.
fn undotted(quarters: f32, dots: u8) -> f32 {
    if dots == 0 {
        return quarters;
    }
    let scale = f64::from(2.0f32.powi(i32::from(dots)));
    (scale * f64::from(quarters) / (scale * 2.0 - 1.0)) as f32
}

#[derive(Debug, Clone, Copy, PartialEq)]
enum Item {
    Value { token: f32, copies: u32 },
    /// `X n m`: the last `items` values repeated to `times` copies in all.
    Repeat { items: u32, times: u32 },
    RepeatPrevious,
}

/// The rhythms of `needed` notes and rests. A pass of one value written in at most two
/// characters (`4`, `8.`, `T16` read as `TS`) sets all of them; notes left without a value
/// become grace notes; values beyond the last note are not used, as the engine ends the
/// pass by itself after the last note's value.
pub fn parse(text: &str, needed: usize, motives: &mut Motives) -> Result<Vec<Rhythm>, InputError> {
    let entries = entries(text, PASS, motives)?;
    let items = entries.iter().map(parse_item).collect::<Result<Vec<_>, _>>()?;
    let tokens = expand(&entries, &items)?;
    let tokens = match tokens.as_slice() {
        [single] if fills_all(text) => vec![*single; needed],
        _ => tokens,
    };
    let grace = 4.0 / GRACE_PER_WHOLE;
    Ok(tokens.into_iter().chain(std::iter::repeat(grace)).take(needed).map(Rhythm::from_token).collect())
}

/// The reader (0x422D98) appends `X<notes>` when the pass ends after one or two characters.
fn fills_all(text: &str) -> bool {
    let body: String = text.split(';').next().unwrap_or("").chars().filter(|c| !matches!(c, '\r' | '\n')).collect();
    let body = body.to_ascii_uppercase();
    let typed = body.len() - body.matches("T16").count() - body.matches("T32").count();
    (1..=2).contains(&typed) && !body.starts_with('@') && !body.contains('/')
}

/// The tokens of the items, repeats applied (0x4AF456).
fn expand(entries: &[Entry], items: &[Item]) -> Result<Vec<f32>, InputError> {
    let mut tokens: Vec<f32> = Vec::new();
    for (entry, item) in entries.iter().zip(items) {
        match *item {
            Item::Value { token, copies } => tokens.extend(std::iter::repeat_n(token, copies as usize)),
            Item::RepeatPrevious => {
                let previous = *tokens.last().ok_or_else(|| entry.error(PASS, ErrorKind::NothingToRepeat))?;
                tokens.push(previous);
            }
            Item::Repeat { items, times } => {
                let items = items as usize;
                if items == 0 || items > tokens.len() {
                    return Err(entry.error(PASS, ErrorKind::NothingToRepeat));
                }
                let group = tokens[tokens.len() - items..].to_vec();
                tokens.extend(std::iter::repeat_n(group, times.saturating_sub(1) as usize).flatten());
            }
        }
    }
    Ok(tokens)
}

fn parse_item(entry: &Entry) -> Result<Item, InputError> {
    let mut c = entry.cursor(PASS);
    c.skip_spaces();
    if c.at_end() {
        return Ok(Item::RepeatPrevious);
    }
    if c.eat(b'X') {
        return group_repeat(&mut c);
    }
    if c.peek() == Some(b'R') {
        // `R?P n m`: the engine checks only the R and the P.
        c.skip(2);
        if !c.eat(b'P') {
            return Err(c.unexpected());
        }
        c.skip_spaces();
        return group_repeat(&mut c);
    }
    let token = token(&mut c)?;
    let copies = if c.eat(b'X') { count(&mut c)? } else { 1 };
    c.skip_spaces();
    c.finish()?;
    Ok(Item::Value { token, copies })
}

fn group_repeat(c: &mut Cursor) -> Result<Item, InputError> {
    let items = count(c)?;
    c.skip_spaces();
    let times = count(c)?;
    c.skip_spaces();
    c.finish()?;
    Ok(Item::Repeat { items, times })
}

/// A repeat count. The tokenizer (0x524C4A) wants a digit 1-9 right after `X`; a group
/// repeat without its second number would use a stale count in the engine.
fn count(c: &mut Cursor) -> Result<u32, InputError> {
    match c.peek() {
        Some(b'1'..=b'9') => c.integer().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber)),
        _ => Err(c.error_here(ErrorKind::ExpectedNumber)),
    }
}

/// Characters 0x4D9EA0 scans as one run before reading a value.
fn in_run(byte: u8) -> bool {
    byte.is_ascii_digit() || matches!(byte, b'.' | b':' | b'\'' | b'G' | b'S' | b'T' | b'E' | b'Q' | b'H' | b'W' | b'D')
}

/// Characters after which the value goes on (after spaces, too).
fn continues(byte: u8) -> bool {
    byte.is_ascii_digit() || matches!(byte, b'.' | b'S' | b'T' | b'E' | b'Q' | b'H' | b'W' | b'D')
}

/// The token of one value: runs of rhythm characters, separated by spaces. With one part
/// the token is its duration plus 1000 per dot; several parts add up and lose the dots'
/// thousands.
fn token(c: &mut Cursor) -> Result<f32, InputError> {
    let mut parts: Vec<f32> = Vec::new();
    let mut dots = 0;
    loop {
        let run = take_run(c);
        let (values, run_dots) = run_values(&run, parts.is_empty())?;
        if parts.is_empty() {
            dots = run_dots;
        }
        parts.extend(values);
        c.skip_spaces();
        if !c.peek().is_some_and(continues) {
            break;
        }
    }
    Ok(match parts.as_slice() {
        [single] => f32::from(dots) * DOT_TOKEN + single,
        _ => parts.iter().fold(0.0f32, |sum, part| sum + part),
    })
}

fn take_run(c: &mut Cursor) -> Entry {
    let start = c.position();
    let text: String = c.rest().bytes().take_while(|b| in_run(*b)).map(char::from).collect();
    c.skip(text.len());
    Entry { text, start, motive: None }
}

/// The durations in one run and the number of dots that end it. 0x4D9EA0 blanks those dots
/// out and gives them to the run's first value, so `QE.` is Q. + E.
fn run_values(run: &Entry, first_run: bool) -> Result<(Vec<f32>, u8), InputError> {
    let body_len = run.text.trim_end_matches('.').len();
    let dots = u8::try_from(run.text.len() - body_len).map_err(|_| run.error(PASS, ErrorKind::OutOfRange("dots".into())))?;
    let body = Entry { text: run.text[..body_len].to_string(), ..run.clone() };
    let mut c = body.cursor(PASS);
    let first = with_dots(part(&mut c, true, first_run)?.quarters(), dots);
    let rest: Vec<f32> = std::iter::from_fn(|| (!c.at_end()).then(|| part(&mut c, false, false).map(Length::quarters)))
        .collect::<Result<_, _>>()?;
    Ok((std::iter::once(first).chain(rest).collect(), dots))
}

/// Each dot adds half of what the previous one added.
fn with_dots(quarters: f32, dots: u8) -> f32 {
    (0..dots)
        .fold((quarters, quarters), |(total, added), _| {
            let half = added * 0.5;
            (total + half, half)
        })
        .0
}

/// The length of one part of a value.
#[derive(Debug, Clone, Copy, PartialEq)]
enum Length {
    PerWhole(f32),
    /// A ratio gives the quarters directly.
    Quarters(f32),
}

impl Length {
    fn quarters(self) -> f32 {
        match self {
            Length::PerWhole(n) => 4.0 / n,
            Length::Quarters(q) => q,
        }
    }
}

/// Values per whole note of the letters in the table at 0x794734 (0x794710).
fn letter_per_whole(letter: u8) -> Option<f32> {
    Some(match letter {
        b'S' => 16.0,
        b'E' => 8.0,
        b'Q' => 4.0,
        b'H' => 2.0,
        b'W' => 1.0,
        b'D' => 0.5,
        _ => return None,
    })
}

/// One number, ratio, letter or triplet. `T` alone may only start a run; `G` only a value.
fn part(c: &mut Cursor, run_start: bool, value_start: bool) -> Result<Length, InputError> {
    let at = c.position();
    match c.peek() {
        Some(b'0'..=b'9' | b'.') => {
            let n = c.number().ok_or_else(|| c.unexpected())?;
            // The reader stores `'` as `:`.
            if c.eat(b':') || c.eat(b'\'') {
                let quarters = c.number().ok_or_else(|| c.error_here(ErrorKind::ExpectedNumber))?;
                return Ok(Length::Quarters(quarters / n));
            }
            Ok(Length::PerWhole(n))
        }
        Some(b'G') if value_start => {
            c.bump();
            Ok(Length::PerWhole(GRACE_PER_WHOLE))
        }
        Some(b'T') => {
            c.bump();
            triplet(c, run_start).ok_or_else(|| InputError::new(PASS, crate::Span::at(at), ErrorKind::Unexpected("T".into())))
        }
        Some(letter) => {
            let n = letter_per_whole(letter).ok_or_else(|| c.unexpected())?;
            c.bump();
            Ok(Length::PerWhole(n))
        }
        None => Err(c.unexpected()),
    }
}

/// What follows a `T`: a letter (`TT` is a triplet 32nd), the number forms the reader turns
/// into letters (`T8` = `TE`, `T16` = `TS`), or nothing for a triplet eighth. For `T1` and
/// `T3` the reader takes the next character as the second digit, whatever it is; those are
/// refused unless they are `T16` and `T32`.
fn triplet(c: &mut Cursor, alone_allowed: bool) -> Option<Length> {
    const TRIPLET_32ND: f32 = 48.0;
    const TRIPLET_EIGHTH: f32 = 12.0;
    let letter = match (c.peek(), c.peek_at(1)) {
        (Some(b'1'), Some(b'6')) => Some((b'S', 2)),
        (Some(b'3'), Some(b'2')) => Some((b'T', 2)),
        (Some(b'1' | b'3'), _) => return None,
        (Some(b'8'), _) => Some((b'E', 1)),
        (Some(b'4'), _) => Some((b'Q', 1)),
        (Some(b'2'), _) => Some((b'H', 1)),
        (Some(letter @ (b'T' | b'S' | b'E' | b'Q' | b'H' | b'W' | b'D')), _) => Some((letter, 1)),
        _ => None,
    };
    match letter {
        Some((b'T', len)) => {
            c.skip(len);
            Some(Length::PerWhole(TRIPLET_32ND))
        }
        Some((letter, len)) => {
            c.skip(len);
            letter_per_whole(letter).map(|n| Length::PerWhole(n * 1.5))
        }
        None => alone_allowed.then_some(Length::PerWhole(TRIPLET_EIGHTH)),
    }
}

/// The values per whole note a piece of pass-2 text starts with, and the rest of the piece
/// (dots, copies); None for a grace note, a ratio or text that is not a rhythm.
pub(crate) fn leading_value(piece: &str) -> Option<(f32, String)> {
    let entry = Entry { text: piece.to_ascii_uppercase(), start: 0, motive: None };
    let mut c = entry.cursor(PASS);
    match part(&mut c, true, false).ok()? {
        Length::PerWhole(n) => Some((n, c.rest().to_string())),
        Length::Quarters(_) => None,
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn quarters(text: &str, needed: usize) -> Vec<f32> {
        parse(text, needed, &mut Motives::new()).unwrap().into_iter().map(Rhythm::quarters).collect()
    }

    fn rejects(text: &str) -> bool {
        parse(text, 4, &mut Motives::new()).is_err()
    }

    #[test]
    fn numbers_letters_triplets_and_dots() {
        assert_eq!(quarters("4/8/.5/H./2../S;", 6), [1.0, 0.5, 8.0, 3.0, 3.5, 0.25]);
        assert_eq!(quarters("T/TQ/T16/G/TT/TD;", 6), [4.0 / 12.0, 4.0 / 6.0, 4.0 / 24.0, GRACE_P7, 4.0 / 48.0, 16.0 / 3.0]);
        assert_eq!(quarters("7:1.5/3:2./4.5/T6;", 4), [1.5 / 7.0, 1.0, 4.0 / 4.5, 1.0]);
    }

    #[test]
    fn parts_add_up_and_the_run_dots_go_to_the_first() {
        assert_eq!(quarters("QE/4 8/G4/QE./4. 8;", 5), [1.5, 1.5, 65.0, 2.0, 2.0]);
        let rhythms = parse("QE./4.;", 2, &mut Motives::new()).unwrap();
        assert_eq!(rhythms.iter().map(|r| r.dots()).collect::<Vec<_>>(), [0, 1]);
    }

    #[test]
    fn copies_repeats_and_fill() {
        assert_eq!(quarters("SX3/8//;", 6).len(), 6);
        assert_eq!(quarters("8/16/16/X3 2/4;", 7).len(), 7);
        assert_eq!(quarters("8.;", 3), [0.75; 3]);
        assert_eq!(quarters("T16;", 2), [4.0 / 24.0; 2]);
        assert_eq!(quarters("16.;", 2), [0.375, GRACE_P7]);
        assert_eq!(quarters("4/;", 3), [1.0, 1.0, GRACE_P7]);
        assert_eq!(quarters("4/8/8/2;", 3), [1.0, 0.5, 0.5]);
    }

    #[test]
    fn engine_rejections() {
        assert!(["Y/4;", "4T/4;", "QT/4;", "Q.E/4;", "8 ./4;", "4G/4;", "T3/4;", "4/8/X2/4;", "4X0;"].iter().all(|t| rejects(t)));
    }

    #[test]
    fn grace_from_zero_and_from_g() {
        assert_eq!(Rhythm::from_token(f32::INFINITY), Rhythm::Grace);
        assert_eq!(Rhythm::from_token(1096.0), Rhythm::Grace);
        assert_eq!(Rhythm::from_token(65.0).head(), 3);
    }

    #[test]
    fn heads_and_tails() {
        let r = |quarters| Rhythm::Value { quarters, dots: 0 };
        assert_eq!([8.0, 4.0, 4.0 / 3.0, 1.0, 1.6].map(|q| r(q).head()), [3, 2, 1, 0, 1]);
        assert_eq!([1.0, 0.8, 0.5, 0.4, 1.0 / 3.0, 0.2, 1.0 / 12.0, 1.0 / 16.0].map(|q| r(q).tails()), [0, 0, 1, 1, 1, 2, 3, 4]);
    }
}
