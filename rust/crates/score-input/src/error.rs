use std::fmt;

/// The five passes of SCORE's input procedure, in the order they are typed.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, PartialOrd, Ord)]
pub enum Pass {
    Notes,
    Rhythms,
    Marks,
    Beams,
    Slurs,
}

impl Pass {
    pub const ALL: [Pass; 5] = [Pass::Notes, Pass::Rhythms, Pass::Marks, Pass::Beams, Pass::Slurs];

    pub fn number(self) -> usize {
        self as usize + 1
    }

    pub fn name(self) -> &'static str {
        match self {
            Pass::Notes => "notes",
            Pass::Rhythms => "rhythms",
            Pass::Marks => "marks",
            Pass::Beams => "beams",
            Pass::Slurs => "slurs",
        }
    }
}

/// Byte range in the text of one pass.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash, Default)]
pub struct Span {
    pub start: usize,
    pub end: usize,
}

impl Span {
    pub fn new(start: usize, end: usize) -> Self {
        Self { start, end }
    }

    pub fn at(pos: usize) -> Self {
        Self::new(pos, pos + 1)
    }
}

#[derive(Debug, Clone, PartialEq)]
pub enum ErrorKind {
    /// A character or word that does not start any entry of this pass.
    Unexpected(String),
    /// The pass text does not end with a semicolon.
    MissingSemicolon,
    /// A number was expected, e.g. after `K` or `X`.
    ExpectedNumber,
    /// A value outside what the entry allows (octave 0-8, key 0-7, ...).
    OutOfRange(String),
    /// A repeat (`/` alone, `X`, `Z`) with nothing before it to repeat.
    NothingToRepeat,
    /// `@x` names a motive that was never defined.
    UnknownMotive(char),
    /// Pass 2 has a different number of rhythms than pass 1 has notes and rests.
    RhythmCount { found: usize, needed: usize },
    /// Pass 3-5 refers to a note number that does not exist.
    NoSuchNote(f32),
}

impl fmt::Display for ErrorKind {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            ErrorKind::Unexpected(text) => write!(f, "unexpected {text:?}"),
            ErrorKind::MissingSemicolon => write!(f, "the pass must end with ';'"),
            ErrorKind::ExpectedNumber => write!(f, "expected a number"),
            ErrorKind::OutOfRange(what) => write!(f, "{what} out of range"),
            ErrorKind::NothingToRepeat => write!(f, "nothing to repeat"),
            ErrorKind::UnknownMotive(name) => write!(f, "motive {name} is not defined"),
            ErrorKind::RhythmCount { found, needed } => {
                write!(f, "{found} rhythms, {needed} needed")
            }
            ErrorKind::NoSuchNote(n) => write!(f, "there is no note {n}"),
        }
    }
}

#[derive(Debug, Clone, PartialEq)]
pub struct InputError {
    pub pass: Pass,
    pub span: Span,
    pub kind: ErrorKind,
}

impl InputError {
    pub fn new(pass: Pass, span: Span, kind: ErrorKind) -> Self {
        Self { pass, span, kind }
    }
}

impl fmt::Display for InputError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(
            f,
            "pass {} ({}), column {}: {}",
            self.pass.number(),
            self.pass.name(),
            self.span.start + 1,
            self.kind
        )
    }
}

impl std::error::Error for InputError {}
