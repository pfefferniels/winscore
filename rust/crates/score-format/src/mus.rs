//! The binary `.mus` file: a word count, a sequence of items, and a trailer.
//!
//! Layout (WinScore help, "Saved File Structure"):
//! * word count, normally a 16-bit integer; files above about 31000 words use
//!   a 32-bit integer and cannot be read by the DOS versions;
//! * items, each a float parameter count followed by that many words;
//! * a trailer whose last word is -9999.0 and whose second-to-last word gives
//!   the number of trailer words before it (currently 5: undefined, serial
//!   number as integer bits, program version, measurement code, the count).
//!
//! Text items (code 16) store P12 = character count; the characters follow the
//! parameters, padded with blanks to whole words, and are included in the
//! item's word count.

use crate::word::Word;

const END_MARKER: f32 = -9999.0;
const TEXT_CODE: i32 = 16;
const TEXT_LENGTH_PARAM: usize = 12;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum CountWidth {
    Short,
    Long,
}

impl CountWidth {
    fn bytes(self) -> usize {
        match self {
            CountWidth::Short => 2,
            CountWidth::Long => 4,
        }
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Item {
    /// The stored length word. Some files carry stray low mantissa bits here
    /// (carmen.mus has 5.0000153); the engine truncates, and so do we.
    length: Word,
    params: Vec<Word>,
    text: Vec<u8>,
}

impl Item {
    pub fn new(params: Vec<Word>) -> Self {
        Self::with_text(params, Vec::new())
    }

    /// A code-16 item; `text` is stored with blank padding to whole words.
    pub fn with_text(params: Vec<Word>, text: Vec<u8>) -> Self {
        let length = Word::from_f32((params.len() + text.len() / 4) as f32);
        Self { length, params, text }
    }

    /// P1, the item type (1 note, 2 rest, 3 clef, ... 18 meter).
    pub fn code(&self) -> i32 {
        self.param(1) as i32
    }

    /// Parameter `n` (1-based) as a float; parameters not stored are zero.
    pub fn param(&self, n: usize) -> f32 {
        n.checked_sub(1)
            .and_then(|i| self.params.get(i))
            .map_or(0.0, |w| w.as_f32())
    }

    pub fn params(&self) -> &[Word] {
        &self.params
    }

    /// The characters of a text item, without padding (P12 gives the length).
    pub fn text(&self) -> &[u8] {
        let len = (self.param(TEXT_LENGTH_PARAM).max(0.0) as usize).min(self.text.len());
        &self.text[..len]
    }

    fn word_count(&self) -> usize {
        self.params.len() + self.text.len() / 4
    }

    /// The stored length word if it still describes the item, else a fresh one.
    fn length_word(&self) -> Word {
        if self.length.as_f32() as usize == self.word_count() {
            self.length
        } else {
            Word::from_f32(self.word_count() as f32)
        }
    }

    fn write_to(&self, out: &mut Vec<u8>) {
        out.extend_from_slice(&self.length_word().to_le_bytes());
        out.extend(self.params.iter().flat_map(|w| w.to_le_bytes()));
        out.extend_from_slice(&self.text);
    }
}

/// The trailer words before the -9999.0 end marker, kept verbatim.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Trailer {
    words: Vec<Word>,
}

impl Trailer {
    pub fn words(&self) -> &[Word] {
        &self.words
    }

    fn field(&self, index_from_count: usize) -> Option<Word> {
        let count_index = self.words.len().checked_sub(1)?;
        count_index.checked_sub(index_from_count).map(|i| self.words[i])
    }

    /// Serial number of the program copy that saved the file.
    pub fn serial(&self) -> Option<u32> {
        self.field(3).map(Word::bits)
    }

    /// Program (file format) version: 3.0 for SCORE 4 era files, 6.0 for WinScore 5.
    pub fn version(&self) -> Option<f32> {
        self.field(2).map(Word::as_f32)
    }

    /// 0 = inches, 1 = metric.
    pub fn measurement(&self) -> Option<f32> {
        self.field(1).map(Word::as_f32)
    }
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct MusFile {
    pub width: CountWidth,
    pub items: Vec<Item>,
    pub trailer: Trailer,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum MusError {
    SizeMismatch { file_len: usize },
    MissingEndMarker,
    BadTrailerLength(Word),
    BadItemLength { word: usize, count: Word },
    ItemOverrun { word: usize },
}

impl std::fmt::Display for MusError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            MusError::SizeMismatch { file_len } => {
                write!(f, "word count matches neither a 16- nor a 32-bit header for {file_len} bytes")
            }
            MusError::MissingEndMarker => write!(f, "last word is not -9999.0"),
            MusError::BadTrailerLength(n) => write!(f, "implausible trailer length {n:?}"),
            MusError::BadItemLength { word, count } => write!(f, "item at word {word} has length {count:?}"),
            MusError::ItemOverrun { word } => write!(f, "item at word {word} runs into the trailer"),
        }
    }
}

impl std::error::Error for MusError {}

fn header_width(bytes: &[u8]) -> Result<(CountWidth, usize), MusError> {
    let short = bytes.get(..2).map(|b| u16::from_le_bytes([b[0], b[1]]) as usize);
    let long = bytes.get(..4).map(|b| u32::from_le_bytes([b[0], b[1], b[2], b[3]]) as usize);
    let fits = |width: CountWidth, n: usize| width.bytes() + 4 * n == bytes.len();
    match (short, long) {
        (Some(n), _) if fits(CountWidth::Short, n) => Ok((CountWidth::Short, n)),
        (_, Some(n)) if fits(CountWidth::Long, n) => Ok((CountWidth::Long, n)),
        _ => Err(MusError::SizeMismatch { file_len: bytes.len() }),
    }
}

fn words(bytes: &[u8]) -> Vec<Word> {
    bytes
        .chunks_exact(4)
        .map(|c| Word::from_bits(u32::from_le_bytes([c[0], c[1], c[2], c[3]])))
        .collect()
}

fn split_trailer(words: &[Word]) -> Result<(&[Word], Trailer), MusError> {
    let (end, rest) = words.split_last().ok_or(MusError::MissingEndMarker)?;
    if end.as_f32() != END_MARKER {
        return Err(MusError::MissingEndMarker);
    }
    let count_word = *rest.last().ok_or(MusError::MissingEndMarker)?;
    let count = count_word.as_f32();
    let len = count as usize;
    if count < 1.0 || count.fract() != 0.0 || len > rest.len() {
        return Err(MusError::BadTrailerLength(count_word));
    }
    let (items, trailer) = rest.split_at(rest.len() - len);
    Ok((items, Trailer { words: trailer.to_vec() }))
}

/// Number of words of an item body that hold text rather than parameters.
fn text_words(body: &[Word]) -> usize {
    let is_text = body.first().is_some_and(|w| w.as_f32() as i32 == TEXT_CODE);
    match body.get(TEXT_LENGTH_PARAM - 1) {
        Some(len) if is_text => (len.as_f32().max(0.0) as usize).div_ceil(4),
        _ => 0,
    }
}

fn parse_item(words: &[Word], start: usize) -> Result<(Item, usize), MusError> {
    let length = words[start];
    let count = length.as_f32();
    if !(1.0..=f32::from(u16::MAX)).contains(&count) {
        return Err(MusError::BadItemLength { word: start, count: length });
    }
    let end = start + 1 + count as usize;
    let body = words.get(start + 1..end).ok_or(MusError::ItemOverrun { word: start })?;
    let split = body.len() - text_words(body).min(body.len());
    let text = body[split..].iter().flat_map(|w| w.to_le_bytes()).collect();
    Ok((Item { length, params: body[..split].to_vec(), text }, end))
}

/// Walks the item region, yielding one item per length-prefixed record.
struct Items<'a> {
    words: &'a [Word],
    pos: usize,
}

impl Iterator for Items<'_> {
    type Item = Result<Item, MusError>;

    fn next(&mut self) -> Option<Self::Item> {
        if self.pos >= self.words.len() {
            return None;
        }
        let parsed = parse_item(self.words, self.pos);
        self.pos = parsed.as_ref().map_or(self.words.len(), |(_, next)| *next);
        Some(parsed.map(|(item, _)| item))
    }
}

/// Program version WinScore 5 writes into the trailer.
const WINSCORE_VERSION: f32 = 6.0;
/// Trailer words before the end marker, the count itself included.
const TRAILER_WORDS: f32 = 5.0;

impl MusFile {
    /// A file without items, for a new score: the trailer of SCORE 4's empty
    /// `SCORE.MUS` with WinScore 5's program version, inches, and no serial.
    pub fn empty() -> Self {
        let words = [0.0, 0.0, WINSCORE_VERSION, 0.0, TRAILER_WORDS].map(Word::from_f32).to_vec();
        Self { width: CountWidth::Short, items: Vec::new(), trailer: Trailer { words } }
    }

    pub fn parse(bytes: &[u8]) -> Result<Self, MusError> {
        let (width, count) = header_width(bytes)?;
        let all = words(&bytes[width.bytes()..width.bytes() + 4 * count]);
        let (item_words, trailer) = split_trailer(&all)?;
        let items = Items { words: item_words, pos: 0 }.collect::<Result<_, _>>()?;
        Ok(Self { width, items, trailer })
    }

    pub fn to_bytes(&self) -> Vec<u8> {
        let mut body = Vec::new();
        self.items.iter().for_each(|item| item.write_to(&mut body));
        body.extend(self.trailer.words.iter().flat_map(|w| w.to_le_bytes()));
        body.extend_from_slice(&Word::from_f32(END_MARKER).to_le_bytes());
        let count = body.len() / 4;
        let header = match self.width {
            CountWidth::Short => (count as u16).to_le_bytes().to_vec(),
            CountWidth::Long => (count as u32).to_le_bytes().to_vec(),
        };
        [header, body].concat()
    }
}
