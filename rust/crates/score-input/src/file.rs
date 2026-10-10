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
//! A file may hold several such blocks, entered one after the other into the same score, and
//! between them lines starting with `!` that stand for other commands (used by the test
//! corpus; `!SP n`, the spacing staff, is not supported yet).

use std::collections::HashMap;
use std::fmt;

use score_format::{Item, Word};

use crate::notes::Clef;
use crate::{run_with_motives, ErrorKind, InputError, Motives, Neighbours, Options, Pass, Passes, Span};

const PASS_COUNT: usize = 5;

/// `IN a b c d e`: staff number, left end, vertical offset, size factor, right end (P2-P6 of the staff).
/// Zeros mean the defaults (left end 0, no offset, size 1, right end 200).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct StaffArgs {
    pub number: u8,
    pub left: f32,
    pub offset: f32,
    pub size: f32,
    pub right: f32,
}

impl StaffArgs {
    /// `IN n` with all other values left at 0.
    pub fn on(number: u8) -> Self {
        Self { number, left: 0.0, offset: 0.0, size: 0.0, right: 0.0 }
    }

    /// The code-8 staff item IN creates when staff `number` does not exist yet; the engine
    /// stores the values as typed, zeros included.
    pub fn staff_item(&self) -> Item {
        Item::new([8.0, f32::from(self.number), self.left, self.offset, self.size, self.right].map(Word::from_f32).to_vec())
    }
}

/// One `IN` block.
#[derive(Debug, Clone, PartialEq)]
pub struct InputLine {
    pub staff: StaffArgs,
    pub range: Option<(f32, f32)>,
    pub passes: [String; PASS_COUNT],
}

#[derive(Debug, Clone, PartialEq)]
pub enum Step {
    Line(InputLine),
    /// A command between blocks, without its `!`.
    Command(String),
}

#[derive(Debug, Clone, PartialEq)]
pub struct InputFile {
    pub steps: Vec<Step>,
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

impl InputLine {
    /// One block from the start of `text`; returns it and the text after its fifth pass.
    fn parse(text: &str) -> Result<(Self, &str), FileError> {
        let mut lines = text.splitn(3, '\n');
        let staff = staff_args(lines.next().unwrap_or(""))?;
        let range = input_range(lines.next().unwrap_or(""))?;
        let mut rest = lines.next().unwrap_or("");
        let mut passes = Vec::with_capacity(PASS_COUNT);
        for n in 1..=PASS_COUNT {
            let end = rest.find(';').ok_or(FileError::MissingPass(n))?;
            passes.push(rest[..=end].trim().to_string());
            rest = &rest[end + 1..];
        }
        let passes = passes.try_into().map_err(|_| FileError::MissingPass(PASS_COUNT))?;
        Ok((Self { staff, range, passes }, rest))
    }

    pub fn passes(&self) -> Passes<'_> {
        let [notes, rhythms, marks, beams, slurs] = &self.passes;
        Passes { notes, rhythms, marks, beams, slurs }
    }

    /// Staff, size and range for [`crate::run`] on a staff created by these IN arguments; the
    /// range ends at the staff's right end if that is shorter.
    pub fn options(&self) -> Options {
        self.options_on(&self.staff, Clef::Treble)
    }

    fn options_on(&self, staff: &StaffArgs, clef: Clef) -> Options {
        let default = Options::default();
        let (begin, mut end) = self.range.unwrap_or((default.begin, default.end));
        if staff.right > 0.0 {
            end = end.min(staff.right);
        }
        let size = if staff.size == 0.0 { 1.0 } else { staff.size };
        let staff_end = if staff.right > 0.0 { staff.right } else { default.staff_end };
        Options { staff: self.staff.number, size, begin, end, clef, staff_end, neighbours: Neighbours::defaults(self.staff.number) }
    }
}

impl InputFile {
    pub fn parse(text: &str) -> Result<Self, FileError> {
        let text = text.replace("\r\n", "\n");
        let mut rest = text.trim_start_matches('\n');
        let mut steps = Vec::new();
        while !rest.trim().is_empty() {
            if let Some(command) = rest.strip_prefix('!') {
                let (line, tail) = command.split_once('\n').unwrap_or((command, ""));
                steps.push(Step::Command(line.trim().to_string()));
                rest = tail;
                continue;
            }
            let (line, tail) = InputLine::parse(rest)?;
            steps.push(Step::Line(line));
            rest = tail.trim_start_matches(['\n', ' ']);
        }
        if steps.is_empty() {
            return Err(FileError::NoInCommand);
        }
        Ok(Self { steps })
    }

    /// The items of all blocks, as the engine leaves them: a staff item where IN creates a
    /// staff, then the line's items. A later line on the same staff starts in the clef the
    /// staff's last clef item set, and motives carry over.
    pub fn items(&self) -> Result<Vec<Item>, InputError> {
        let mut items: Vec<Item> = Vec::new();
        let mut staves: HashMap<u8, StaffArgs> = HashMap::new();
        let mut motives = Motives::new();
        for step in &self.steps {
            let line = match step {
                Step::Line(line) => line,
                Step::Command(command) => {
                    return Err(InputError::new(Pass::Notes, Span::default(), ErrorKind::Unsupported(command.clone())));
                }
            };
            let number = line.staff.number;
            if let std::collections::hash_map::Entry::Vacant(slot) = staves.entry(number) {
                slot.insert(line.staff);
                items.push(line.staff.staff_item());
            }
            let clef = current_clef(&items, number);
            let options = Options { neighbours: Neighbours::from_items(&items, number), ..line.options_on(&staves[&number], clef) };
            items.extend(run_with_motives(&line.passes(), &options, &mut motives)?);
        }
        Ok(items)
    }
}

/// The clef of the staff's last clef item (treble if it has none).
fn current_clef(items: &[Item], staff: u8) -> Clef {
    items
        .iter()
        .rev()
        .find(|item| item.code() == 3 && item.param(2) as u8 == staff)
        .map_or(Clef::Treble, |item| Clef::from_code(item.param(5) as i32))
}
