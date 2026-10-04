//! Splitting a pass into its slash-separated entries, and a cursor for reading one entry.
//!
//! The engine upper-cases what is typed, ignores line breaks (a long pass continues on the
//! next line) and stops at the first semicolon.

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
        Cursor { bytes: self.text.as_bytes(), pos: 0, origin: self.start, pass }
    }

    pub fn error(&self, pass: Pass, kind: ErrorKind) -> InputError {
        InputError::new(pass, self.span(), kind)
    }
}

/// The entries of a pass, up to its terminating semicolon. An empty pass (`;`) has none;
/// otherwise every slash separates two entries, so `A/;` ends with an empty entry. Motive
/// definitions are entered in place and stored; recalls in passes 2-5 are replaced by the
/// stored entries (pass 1 resolves them itself, see events.rs).
pub(crate) fn entries(text: &str, pass: Pass, motives: &mut Motives) -> Result<Vec<Entry>, InputError> {
    let end = text.find(';').ok_or_else(|| InputError::new(pass, Span::at(text.len()), ErrorKind::MissingSemicolon))?;
    let body = &text[..end];
    if body.trim().is_empty() {
        return Ok(Vec::new());
    }
    let mut out = Vec::new();
    let mut at = 0;
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
                Some('/') => at += 1,
                None => break,
                Some(_) => {}
            }
            continue;
        }
        let piece_len = rest.find('/').unwrap_or(rest.len());
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
    Ok(out)
}

fn split(text: &str, origin: usize, motive: Option<char>) -> Vec<Entry> {
    let mut start = origin;
    text.split('/')
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
    let number = chars.as_str().trim();
    let value = if number.is_empty() { 0 } else { number.parse().ok()? };
    Some((name, value))
}

fn joined_upper(piece: &str) -> String {
    piece.chars().filter(|c| !matches!(c, '\r' | '\n')).map(|c| c.to_ascii_uppercase()).collect()
}

/// Reads the characters of one entry.
pub(crate) struct Cursor<'a> {
    bytes: &'a [u8],
    pos: usize,
    origin: usize,
    pass: Pass,
}

impl Cursor<'_> {
    pub fn peek(&self) -> Option<u8> {
        self.bytes.get(self.pos).copied()
    }

    pub fn peek_at(&self, ahead: usize) -> Option<u8> {
        self.bytes.get(self.pos + ahead).copied()
    }

    pub fn bump(&mut self) -> Option<u8> {
        let byte = self.peek()?;
        self.pos += 1;
        Some(byte)
    }

    pub fn eat(&mut self, byte: u8) -> bool {
        let found = self.peek() == Some(byte);
        if found {
            self.pos += 1;
        }
        found
    }

    pub fn eat_word(&mut self, word: &str) -> bool {
        let found = self.bytes[self.pos..].starts_with(word.as_bytes());
        if found {
            self.pos += word.len();
        }
        found
    }

    pub fn at_end(&self) -> bool {
        self.pos >= self.bytes.len()
    }

    pub fn rest(&self) -> &str {
        std::str::from_utf8(&self.bytes[self.pos..]).unwrap_or("")
    }

    pub fn skip_spaces(&mut self) {
        while self.peek() == Some(b' ') {
            self.pos += 1;
        }
    }

    pub fn position(&self) -> usize {
        self.origin + self.pos
    }

    /// A decimal digit, if one follows.
    pub fn digit(&mut self) -> Option<u8> {
        let digit = self.peek().filter(u8::is_ascii_digit)?;
        self.pos += 1;
        Some(digit - b'0')
    }

    /// An unsigned integer, if one follows.
    pub fn integer(&mut self) -> Option<u32> {
        let digits = self.take_while(|b| b.is_ascii_digit());
        digits.parse().ok()
    }

    /// A number such as `12`, `.5` or `2.7`, if one follows.
    pub fn number(&mut self) -> Option<f32> {
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
        while self.peek().is_some_and(&keep) {
            self.pos += 1;
        }
        std::str::from_utf8(&self.bytes[start..self.pos]).unwrap_or("")
    }

    pub fn error_here(&self, kind: ErrorKind) -> InputError {
        InputError::new(self.pass, Span::at(self.position()), kind)
    }

    pub fn unexpected(&self) -> InputError {
        let text = self.rest().chars().next().map_or_else(|| "end of entry".to_string(), String::from);
        self.error_here(ErrorKind::Unexpected(text))
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
