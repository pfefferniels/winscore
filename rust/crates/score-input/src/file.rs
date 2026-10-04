//! SCORE's input files: what WinScore saves as `INPUT.TMP` (and the SAVE choice at the end of
//! input) and reads back with READ. Example (`SCORE 4/SCORE/ADDA.MUS`):
//!
//! ```text
//! in 1
//! ;
//! G3/G4/D4/B3;
//! SX4;
//! ;
//! 2B;
//! 1+4;
//! ```
//!
//! Line 1 is the `IN` command, line 2 the input range (`begin end`, or `;` for the default),
//! then the five passes, each ending at its first `;` and possibly continued over lines.

use std::fmt;

use score_format::{Item, Word};

use crate::{run, InputError, Options, Passes};

const PASS_COUNT: usize = 5;

/// `IN a b c d e`: staff number, left end, vertical offset, size factor, right end (P2-P6 of the staff).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct StaffArgs {
    pub number: u8,
    pub left: f32,
    pub offset: f32,
    pub size: f32,
    pub right: f32,
}

#[derive(Debug, Clone, PartialEq)]
pub struct InputFile {
    pub staff: StaffArgs,
    pub range: Option<(f32, f32)>,
    pub passes: [String; PASS_COUNT],
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum FileError {
    NoInCommand,
    BadNumber(String),
    MissingPass(usize),
}

impl fmt::Display for FileError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            FileError::NoInCommand => write!(f, "the first line must be an IN command"),
            FileError::BadNumber(text) => write!(f, "not a number: {text:?}"),
            FileError::MissingPass(n) => write!(f, "pass {n} is missing or does not end with ';'"),
        }
    }
}

impl std::error::Error for FileError {}

fn number(text: &str) -> Result<f32, FileError> {
    text.parse().map_err(|_| FileError::BadNumber(text.to_string()))
}

fn staff_args(line: &str) -> Result<StaffArgs, FileError> {
    let mut words = line.split(|c: char| c.is_whitespace() || c == ',').filter(|w| !w.is_empty());
    if !words.next().is_some_and(|w| w.eq_ignore_ascii_case("IN")) {
        return Err(FileError::NoInCommand);
    }
    let values = words.map(number).collect::<Result<Vec<f32>, _>>()?;
    let value = |i: usize| values.get(i).copied().unwrap_or(0.0);
    Ok(StaffArgs { number: value(0).max(1.0) as u8, left: value(1), offset: value(2), size: value(3), right: value(4) })
}

fn input_range(line: &str) -> Result<Option<(f32, f32)>, FileError> {
    let values = line
        .split(|c: char| c.is_whitespace() || c == ',' || c == ';')
        .filter(|w| !w.is_empty())
        .map(number)
        .collect::<Result<Vec<f32>, _>>()?;
    Ok(match values[..] {
        [begin, end, ..] => Some((begin, end)),
        _ => None,
    })
}

impl InputFile {
    pub fn parse(text: &str) -> Result<Self, FileError> {
        let text = text.replace("\r\n", "\n");
        let mut lines = text.splitn(3, '\n');
        let staff = staff_args(lines.next().unwrap_or(""))?;
        let range = input_range(lines.next().unwrap_or(""))?;
        let rest = lines.next().unwrap_or("");
        let passes: Vec<String> = rest
            .split_inclusive(';')
            .take_while(|p| p.ends_with(';'))
            .take(PASS_COUNT)
            .map(|p| p.trim().to_string())
            .collect();
        let found = passes.len();
        let passes = passes.try_into().map_err(|_| FileError::MissingPass(found + 1))?;
        Ok(Self { staff, range, passes })
    }

    pub fn passes(&self) -> Passes<'_> {
        let [notes, rhythms, marks, beams, slurs] = &self.passes;
        Passes { notes, rhythms, marks, beams, slurs }
    }

    pub fn options(&self) -> Options {
        let default = Options::default();
        let (begin, end) = self.range.unwrap_or((default.begin, default.end));
        Options { staff: self.staff.number, begin, end }
    }

    /// The staff item IN creates when the staff does not exist yet.
    pub fn staff_item(&self) -> Item {
        let s = self.staff;
        Item::new([8.0, f32::from(s.number), s.left, s.offset, s.size, s.right].map(Word::from_f32).to_vec())
    }

    /// The staff item followed by the items of the line.
    pub fn items(&self) -> Result<Vec<Item>, InputError> {
        Ok(std::iter::once(self.staff_item()).chain(run(&self.passes(), &self.options())?).collect())
    }
}
