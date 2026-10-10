//! Splitting a pass into its entries, and a cursor for reading one entry: the tokenizer
//! 0x524C4A as analysis/engine/input.md ("Tokenizer") describes it.
//!
//! The engine upper-cases what is typed, ignores line breaks (a long pass continues on the
//! next line) and stops at the first semicolon. Entries are separated by `/` or `,`; a
//! leading `/` is skipped.

use crate::error::{ErrorKind, InputError, Pass, Span};
use crate::motives::{augment, renumber, Motives};

/// One slash-separated entry: its upper-cased text and where it starts in the pass text.
#[derive(Debug, Clone, PartialEq, Eq)]
pub(crate) struct Entry {
    pub text: String,
    pub start: usize,
    /// The motive being defined, for entries between `X[` and `]`.
    pub motive: Option<char>,
}

impl Entry {
    pub fn span(&self) -> Span {
        Span::new(self.start, self.start + self.text.len().max(1))
    }

    pub fn cursor(&self, pass: Pass) -> Cursor<'_> {
        Cursor { bytes: self.text.as_bytes(), pos: 0, origin: self.start, pass, skip_spaces: false }
    }

    /// A cursor that passes over spaces as the item parsers do (0x526EC4); a number still
    /// ends at a space, so `3 4` is two numbers.
    pub fn spaced_cursor(&self, pass: Pass) -> Cursor<'_> {
        Cursor { skip_spaces: true, ..self.cursor(pass) }
    }

    pub fn error(&self, pass: Pass, kind: ErrorKind) -> InputError {
        InputError::new(pass, self.span(), kind)
    }
}

/// The entries of a pass, up to its terminating semicolon. An empty pass (`;`) has none;
/// otherwise every separator separates two entries, so `A/;` ends with an empty entry. Motive
/// definitions are entered in place and stored; recalls in passes 2-5 are replaced by the
/// stored entries (pass 1 resolves them itself, see events.rs).
pub(crate) fn entries(text: &str, pass: Pass, motives: &mut Motives) -> Result<Vec<Entry>, InputError> {
    let end = text.find(';').ok_or_else(|| InputError::new(pass, Span::at(text.len()), ErrorKind::MissingSemicolon))?;
    let body = &text[..end];
    if body.trim().is_empty() {
        return Ok(Vec::new());
    }
    let mut out = Vec::new();
    let mut at = body.find(|c: char| c != ' ').filter(|&i| body[i..].starts_with('/')).map_or(0, |i| i + 1);
    loop {
        let rest = &body[at..];
        let upper: Vec<u8> = rest.bytes().take(2).map(|b| b.to_ascii_uppercase()).collect();
        if upper.len() == 2 && upper[0].is_ascii_alphabetic() && upper[1] == b'[' {
            let close = rest.find(']').ok_or_else(|| InputError::new(pass, Span::at(at), ErrorKind::Unexpected("[".into())))?;
            let name = upper[0] as char;
            let inner = &rest[2..close];
            if pass != Pass::Notes {
                motives.store_text(pass, name, &joined_upper(inner));
            }
            out.extend(split(inner, at + 2, Some(name)));
            at += close + 1;
            match body[at..].chars().next() {
                Some('/' | ',') => at += 1,
                None => break,
                Some(_) => {}
            }
            continue;
        }
        let piece_len = rest.find(is_separator).unwrap_or(rest.len());
        let piece = &rest[..piece_len];
        if pass != Pass::Notes && piece.trim_start().starts_with('@') {
            out.extend(recall(piece, at, pass, motives)?);
        } else {
            out.push(Entry { text: joined_upper(piece), start: at, motive: None });
        }
        if piece_len == rest.len() {
            break;
        }
        at += piece_len + 1;
    }
    // 0x524C4A: in passes 3-5 "=" is typed for "+" (same key without shift).
    if pass > Pass::Rhythms {
        out.iter_mut().for_each(|e| e.text = e.text.replace('=', "+"));
    }
    Ok(out)
}

fn is_separator(c: char) -> bool {
    matches!(c, '/' | ',')
}

fn split(text: &str, origin: usize, motive: Option<char>) -> Vec<Entry> {
    let mut start = origin;
    text.split(is_separator)
        .map(|piece| {
            let entry = Entry { text: joined_upper(piece), start, motive };
            start += piece.len() + 1;
            entry
        })
        .collect()
}

/// `@X` or `@Xn` in passes 2-5: the stored entries, changed by n.
fn recall(piece: &str, at: usize, pass: Pass, motives: &Motives) -> Result<Vec<Entry>, InputError> {
    let (name, number) = recall_parts(piece).ok_or_else(|| InputError::new(pass, Span::at(at), ErrorKind::Unexpected(piece.into())))?;
    let stored = motives.text(pass, name).ok_or_else(|| InputError::new(pass, Span::at(at), ErrorKind::UnknownMotive(name)))?;
    let text = match number {
        0 => stored.to_string(),
        n if pass == Pass::Rhythms => augment(stored, n),
        n => renumber(stored, n, pass, at)?,
    };
    Ok(split(&text, at, None).into_iter().map(|e| Entry { start: at, ..e }).collect())
}

/// The letter and (possibly negative) number of a recall `@Xn`; 0 when no number follows.
pub(crate) fn recall_parts(piece: &str) -> Option<(char, i32)> {
    let text = piece.trim();
    let mut chars = text.strip_prefix('@')?.chars();
    let name = chars.next()?.to_ascii_uppercase();
    if !name.is_ascii_alphabetic() {
        return None;
    }
    // `@X-` without a number is the plain recall.
    let number = chars.as_str().trim().trim_end_matches('-');
    let value = if number.is_empty() { 0 } else { number.parse().ok()? };
    Some((name, value))
}

fn joined_upper(piece: &str) -> String {
    piece.chars().filter(|c| !matches!(c, '\r' | '\n')).map(|c| c.to_ascii_uppercase()).collect()
}

/// Reads the characters of one entry.
#[derive(Clone)]
pub(crate) struct Cursor<'a> {
    bytes: &'a [u8],
    pos: usize,
    origin: usize,
    pass: Pass,
    skip_spaces: bool,
}

impl Cursor<'_> {
    /// Moves over spaces, if this cursor skips them.
    fn pass_spaces(&mut self) {
        if self.skip_spaces {
            self.skip_spaces();
        }
    }

    pub fn peek(&self) -> Option<u8> {
        let mut ahead = self.clone();
        ahead.pass_spaces();
        ahead.bytes.get(ahead.pos).copied()
    }

    /// The character `ahead` places further on (spaces counted when they are skipped).
    pub fn peek_at(&self, ahead: usize) -> Option<u8> {
        let mut c = self.clone();
        (0..ahead).for_each(|_| {
            c.bump();
        });
        c.peek()
    }

    pub fn bump(&mut self) -> Option<u8> {
        self.pass_spaces();
        let byte = self.bytes.get(self.pos).copied()?;
        self.pos += 1;
        Some(byte)
    }

    /// Moves over `count` characters (spaces not counted when they are skipped).
    pub fn skip(&mut self, count: usize) {
        (0..count).for_each(|_| {
            self.bump();
        });
    }

    /// Moves to the end of the entry: the parser ignores what follows.
    pub fn skip_rest(&mut self) {
        self.pos = self.bytes.len();
    }

    pub fn eat(&mut self, byte: u8) -> bool {
        let found = self.peek() == Some(byte);
        if found {
            self.bump();
        }
        found
    }

    pub fn eat_word(&mut self, word: &str) -> bool {
        let mut ahead = self.clone();
        let found = word.bytes().all(|b| ahead.bump() == Some(b));
        if found {
            *self = ahead;
        }
        found
    }

    pub fn at_end(&self) -> bool {
        self.peek().is_none()
    }

    pub fn rest(&self) -> &str {
        std::str::from_utf8(&self.bytes[self.pos..]).unwrap_or("")
    }

    pub fn skip_spaces(&mut self) {
        while self.bytes.get(self.pos) == Some(&b' ') {
            self.pos += 1;
        }
    }

    pub fn position(&self) -> usize {
        self.origin + self.pos
    }

    /// A decimal digit, if one follows.
    pub fn digit(&mut self) -> Option<u8> {
        let digit = self.peek().filter(u8::is_ascii_digit)?;
        self.bump();
        Some(digit - b'0')
    }

    /// An unsigned integer, if one follows.
    pub fn integer(&mut self) -> Option<u32> {
        self.pass_spaces();
        let digits = self.take_while(|b| b.is_ascii_digit());
        digits.parse().ok()
    }

    /// A number such as `12`, `.5` or `2.7`, if one follows.
    pub fn number(&mut self) -> Option<f32> {
        self.pass_spaces();
        let start = self.pos;
        self.take_while(|b| b.is_ascii_digit());
        if self.peek() == Some(b'.') && self.peek_at(1).is_some_and(|b| b.is_ascii_digit()) {
            self.pos += 1;
            self.take_while(|b| b.is_ascii_digit());
        }
        let text = std::str::from_utf8(&self.bytes[start..self.pos]).unwrap_or("");
        text.parse().ok().or_else(|| {
            self.pos = start;
            None
        })
    }

    fn take_while(&mut self, keep: impl Fn(u8) -> bool) -> &str {
        let start = self.pos;
        while self.bytes.get(self.pos).is_some_and(|&b| keep(b)) {
            self.pos += 1;
        }
        std::str::from_utf8(&self.bytes[start..self.pos]).unwrap_or("")
    }

    pub fn error_here(&self, kind: ErrorKind) -> InputError {
        InputError::new(self.pass, Span::at(self.position()), kind)
    }

    pub fn unexpected(&self) -> InputError {
        let mut at = self.clone();
        at.pass_spaces();
        let text = at.rest().chars().next().map_or_else(|| "end of entry".to_string(), String::from);
        at.error_here(ErrorKind::Unexpected(text))
    }

    /// Fails unless the whole entry has been read.
    pub fn finish(&self) -> Result<(), InputError> {
        if self.at_end() {
            Ok(())
        } else {
            Err(self.unexpected())
        }
    }
}
