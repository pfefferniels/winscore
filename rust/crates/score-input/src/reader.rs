//! What WinScore's pass-1 reader (0x41C3B8) does to the text while it is typed, before the
//! tokenizer sees it (analysis/engine/input.md, "Pass 1: notes", "Reader"):
//!
//! - letters are upper-cased, `'` becomes `:`;
//! - `.` and `=` become `=` after `/` or `=` (the chord repeat), `+` elsewhere (the dyad);
//! - `#`, `%` and `^` are dropped, `$` too unless it follows `@` or `-`;
//! - a leading `/` is dropped;
//! - every item closed by `/` passes the item check 0x4C2912 on its first two characters,
//!   and an item that fails is erased (the last item, closed by `;`, is not checked); so is
//!   a group repeat `Xn m` reaching back further than the items typed so far (0x421651);
//! - `;` after a final barline `M/` or `M?/` replaces that `/`, so the barline is not repeated.

use crate::error::Span;

/// The pass-1 text as the reader leaves it.
#[derive(Debug, Clone, PartialEq, Eq)]
pub(crate) struct ReadText {
    /// Up to and including the `;` (no `;` if none was typed).
    pub text: String,
    /// For each byte of `text`, its position in the typed text.
    origins: Vec<usize>,
    /// The items the item check erased, in the typed text.
    pub erased: Vec<Span>,
}

impl ReadText {
    /// The position in the typed text of position `pos` of the read text.
    pub fn origin(&self, pos: usize) -> usize {
        match self.origins.get(pos) {
            Some(&origin) => origin,
            None => self.origins.last().map_or(pos, |last| last + 1 + (pos - self.origins.len())),
        }
    }

    pub fn origin_span(&self, span: Span) -> Span {
        let start = self.origin(span.start);
        Span::new(start, self.origin(span.end.max(span.start + 1) - 1).max(start) + 1)
    }
}

/// The reader's text being built: characters with their typed positions.
#[derive(Default)]
struct Typed {
    chars: Vec<(u8, usize)>,
    erased: Vec<Span>,
}

impl Typed {
    fn last(&self) -> Option<u8> {
        self.chars.last().map(|(c, _)| *c)
    }

    fn push(&mut self, c: u8, at: usize) {
        self.chars.push((c, at));
    }

    /// Where the current (unclosed) item starts.
    fn item_start(&self) -> usize {
        self.chars.iter().rposition(|(c, _)| *c == b'/').map_or(0, |i| i + 1)
    }

    fn item(&self) -> Vec<u8> {
        self.chars[self.item_start()..].iter().map(|(c, _)| *c).collect()
    }

    /// Items closed so far.
    fn closed_items(&self) -> usize {
        self.chars.iter().filter(|(c, _)| *c == b'/').count()
    }

    /// `/` typed: the item is kept or erased.
    fn close_item(&mut self, at: usize) {
        if self.chars.is_empty() {
            return;
        }
        let item = self.item();
        if item_passes(&item) && !repeats_too_far(&item, self.closed_items()) {
            self.push(b'/', at);
            return;
        }
        let start = self.item_start();
        let from = self.chars.get(start).map_or(at, |(_, origin)| *origin);
        self.erased.push(Span::new(from, at + 1));
        self.chars.truncate(start);
    }

    fn finish(self) -> ReadText {
        let (bytes, origins): (Vec<u8>, Vec<usize>) = self.chars.into_iter().unzip();
        ReadText { text: String::from_utf8_lossy(&bytes).into_owned(), origins, erased: self.erased }
    }

    /// `;` typed: a final `M/` or `M?/` loses its `/`.
    fn end(&mut self, at: usize) {
        let n = self.chars.len();
        let barline_before = |back: usize| n > back && self.chars[n - 1 - back].0 == b'M';
        if self.last() == Some(b'/') && (barline_before(1) || barline_before(2)) {
            self.chars.pop();
        }
        self.push(b';', at);
    }
}

pub(crate) fn read(typed: &str) -> ReadText {
    let mut text = Typed::default();
    for (at, byte) in typed.bytes().enumerate() {
        match byte.to_ascii_uppercase() {
            b';' => {
                text.end(at);
                break;
            }
            b'\r' | b'\n' | b'#' | b'%' | b'^' => {}
            b'$' if !matches!(text.last(), Some(b'@' | b'-')) => {}
            b'/' => text.close_item(at),
            b'\'' => text.push(b':', at),
            b'.' | b'=' => {
                let repeat = matches!(text.last(), Some(b'/' | b'='));
                text.push(if repeat { b'=' } else { b'+' }, at);
            }
            other => text.push(other, at),
        }
    }
    text.finish()
}

/// The reader of passes 4 and 5 (0x427C68): upper case, a `/` before a typed `X`, and a
/// typed `X1 ` dropped altogether.
pub(crate) fn read_connections(typed: &str) -> ReadText {
    let mut text = Typed::default();
    let bytes = typed.as_bytes();
    let mut at = 0;
    while let Some(&byte) = bytes.get(at) {
        match byte.to_ascii_uppercase() {
            b';' => {
                text.push(b';', at);
                break;
            }
            b'X' if bytes.get(at + 1) == Some(&b'1') && bytes.get(at + 2) == Some(&b' ') => at += 2,
            b'X' => {
                if !matches!(text.last(), Some(b'/' | b',') | None) {
                    text.push(b'/', at);
                }
                text.push(b'X', at);
            }
            other => text.push(other, at),
        }
        at += 1;
    }
    text.finish()
}

/// The item check 0x4C2912 on an item closed by `/`.
fn item_passes(item: &[u8]) -> bool {
    let item = skip_input_clef(item);
    if let [name, b'[', inner @ ..] = item {
        return name.is_ascii_uppercase() && item_passes(inner);
    }
    let c1 = item.first().copied().unwrap_or(b'/');
    let c2 = item.get(1).copied().unwrap_or(b'/');
    let note_suffix = |c: u8| {
        c == c1
            || matches!(c, b'\'' | b':' | b'+' | b'-' | b'U' | b'J' | b'N' | b'F' | b'S' | b'(' | b'1'..=b'8' | b'.' | b'=' | b']' | b'X' | b'/' | b';')
    };
    match c1 {
        b'A' => c2 == b'L' || note_suffix(c2),
        b'B' => c2 == b'A' || note_suffix(c2),
        b'C' => matches!(c2, b'U' | b'O') || note_suffix(c2),
        b'D'..=b'G' => note_suffix(c2),
        b'K' => matches!(c2, b'1'..=b'7'),
        b'M' => true,
        b'O' => matches!(c2, b'A'..=b'G'),
        b'P' => matches!(c2, b'R' | b'A'..=b'G'),
        b'Q' => matches!(c2, b'0' | b'+' | b'-' | b'='),
        b'R' => matches!(c2, b'F' | b'I' | b'W' | b'P' | b'1'..=b'9' | b']' | b'D' | b'U' | b'/' | b';' | b'X'),
        b'S' => matches!(c2, b'O' | b'U' | b'D' | b'0' | b'+' | b'-'),
        b'T' => matches!(c2, b'R' | b'E'),
        b'X' | b'Z' => c2.is_ascii_digit(),
        b'@' => match c2 {
            b'-' | b'$' => item.get(2).is_some_and(u8::is_ascii_uppercase),
            c => c.is_ascii_uppercase(),
        },
        b'0'..=b'9' | b'=' | b'.' | b']' | b'/' | b';' => true,
        _ => false,
    }
}

/// The `-` of an input clef (`-TR`, `-BA`, ...) is passed over by the check, which then
/// looks at the clef's letters: `-BE` fails.
fn skip_input_clef(item: &[u8]) -> &[u8] {
    match item {
        [b'-', b'T' | b'A' | b'B', b'R' | b'E' | b'L' | b'A', ..] => &item[1..],
        _ => item,
    }
}

/// `Xn m` (or `Zn m`) with n larger than the number of items before it.
fn repeats_too_far(item: &[u8], items_before: usize) -> bool {
    let [b'X' | b'Z', rest @ ..] = item else { return false };
    let digits: String = rest.iter().take_while(|c| c.is_ascii_digit()).map(|&c| char::from(c)).collect();
    let is_group = rest.get(digits.len()) == Some(&b' ');
    is_group && digits.parse::<usize>().is_ok_and(|n| n > items_before)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn rewrites_and_drops() {
        assert_eq!(read("c4'e./d/.;").text, "C4:E+/D/=;");
        assert_eq!(read("/C4#/D..;").text, "C4/D++;");
        assert_eq!(read(".;").text, "+;");
        assert_eq!(read("C4/M/;").text, "C4/M;");
        assert_eq!(read("C4/MRD/;").text, "C4/MRD/;");
    }

    #[test]
    fn erases_items_that_fail_the_check() {
        let read = read("C4/C0/K0S/D F/E;");
        assert_eq!(read.text, "C4/E;");
        assert_eq!(read.erased, [Span::new(3, 6), Span::new(6, 10), Span::new(10, 14)]);
        assert_eq!(read.origin(3), 14);
    }

    #[test]
    fn connections_split_at_x_and_drop_x1() {
        assert_eq!(read_connections("1 2 x3 4;").text, "1 2 /X3 4;");
        assert_eq!(read_connections("X1 1 3;").text, "1 3;");
    }

    #[test]
    fn group_repeat_must_find_its_items() {
        assert_eq!(super::read("C4/D/X5 2/E;").text, "C4/D/E;");
        assert_eq!(super::read("C4/D/X2 2/E;").text, "C4/D/X2 2/E;");
    }
}
