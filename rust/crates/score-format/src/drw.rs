//! Symbol library files (`LBnnn0.DRW`), ten Code 9 symbols per file.
//!
//! Float variant, as used by most WinScore 5 library files:
//! * 11 little-endian i16 offsets, 1-based (FORTRAN) point indices: symbol k
//!   uses points `off[k] ..< off[k+1]`, with `off[0] = 0` read as 1;
//!   `off[10] - 1` is the point count;
//! * 10 names of 24 blank-padded characters. The engine ignores the names:
//!   a slot with a blank name is drawn from its offsets like any other (e.g.
//!   LB1300 slot 0); only offsets outside the point table leave it empty;
//! * N x-coordinates (f32), N y-coordinates (f32), N pen codes (i16), with
//!   N = `off[10] - 1`. Pen 1 starts a stroked line, 2 a filled polygon,
//!   3 a further path of the same filled object, 0 continues the current
//!   path. Negative pens (-1, -2, -3) occur too; the engine draws them as
//!   continuation points. [`Symbol::records`] keeps every point with its pen.
//!
//! The engine draws one library unit as 25 engine units (1/160 inch) at
//! normal size; checked against WScore.exe output for symbols 20-29.
//!
//! Compact variant (all SCORE 4 libraries, WinScore's `KBRHY.DRW` and
//! `FAULT.DRW`, user symbols of code 11), as the engine reads it (0x432998):
//! an MS Fortran unformatted sequential file (first byte `K`, sub-records of
//! up to 128 bytes framed by length bytes, 0x81 for a full one that
//! continues, 0x82 at the end). The first record holds 11 i16 offsets in
//! i16 words (from the second on converted to points as offset/3 + 1) and
//! 10 names of 5 characters; the rest is i16 triples x, y, pen in library
//! units. Checked against the float variant: SCORE 4's `LIBRB.DRW` decodes to
//! the points of WinScore's `LB0010.DRW`.

const SYMBOLS: usize = 10;
const NAME_LEN: usize = 24;
const OFFSETS_LEN: usize = 2 * (SYMBOLS + 1);
const HEADER_LEN: usize = OFFSETS_LEN + SYMBOLS * NAME_LEN;
const COMPACT_MAGIC: &[u8; 2] = b"KH";
const COMPACT_NAME_LEN: usize = 5;
const COMPACT_HEADER_LEN: usize = OFFSETS_LEN + SYMBOLS * COMPACT_NAME_LEN;
/// MS Fortran sub-record framing: a full 128-byte sub-record that continues, the end of the file.
const SUBRECORD_CONTINUES: u8 = 0x81;
const FULL_SUBRECORD: usize = 128;
const END_OF_FILE: u8 = 0x82;

/// Engine units per library unit at size factor 1.
pub const ENGINE_UNITS_PER_DRW_UNIT: f32 = 25.0;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum PathKind {
    Stroke,
    Fill,
}

#[derive(Debug, Clone, PartialEq)]
pub struct SymbolPath {
    pub kind: PathKind,
    pub points: Vec<(f32, f32)>,
}

/// One point of a symbol as stored: coordinates in library units and the pen code.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct DrwRecord {
    pub x: f32,
    pub y: f32,
    pub pen: i16,
}

#[derive(Debug, Clone, PartialEq)]
pub struct Symbol {
    pub name: String,
    /// Paths split at pens 1 and 2 only, a simplified view of `records`.
    pub paths: Vec<SymbolPath>,
    /// Every point in file order, the form the engine draws from.
    pub records: Vec<DrwRecord>,
}

#[derive(Debug, Clone, PartialEq)]
pub struct DrwLibrary {
    pub symbols: Vec<Symbol>,
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum DrwError {
    TooShort,
    /// A compact library whose record framing is broken.
    BadRecords,
    BadOffsets,
    SizeMismatch { points: usize, file_len: usize },
}

impl std::fmt::Display for DrwError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            DrwError::TooShort => write!(f, "file shorter than the library header"),
            DrwError::BadRecords => write!(f, "compact library records are cut short"),
            DrwError::BadOffsets => write!(f, "offsets of a named symbol fall outside the point table"),
            DrwError::SizeMismatch { points, file_len } => {
                write!(f, "{points} points do not fit a file of {file_len} bytes")
            }
        }
    }
}

impl std::error::Error for DrwError {}

fn i16_at(bytes: &[u8], i: usize) -> i16 {
    i16::from_le_bytes([bytes[2 * i], bytes[2 * i + 1]])
}

fn f32_at(bytes: &[u8], i: usize) -> f32 {
    f32::from_le_bytes([bytes[4 * i], bytes[4 * i + 1], bytes[4 * i + 2], bytes[4 * i + 3]])
}

fn pen_kind(pen: i16) -> Option<PathKind> {
    match pen {
        1 => Some(PathKind::Stroke),
        2 => Some(PathKind::Fill),
        _ => None,
    }
}

/// Group consecutive points into paths; a point with pen 1 or 2 opens a new one.
fn paths(points: impl Iterator<Item = ((f32, f32), i16)>) -> Vec<SymbolPath> {
    points.fold(Vec::new(), |mut acc: Vec<SymbolPath>, (point, pen)| {
        match (pen_kind(pen), acc.last_mut()) {
            (None, Some(open)) => open.points.push(point),
            (kind, _) => acc.push(SymbolPath { kind: kind.unwrap_or(PathKind::Fill), points: vec![point] }),
        }
        acc
    })
}

impl DrwLibrary {
    pub fn parse(bytes: &[u8]) -> Result<Self, DrwError> {
        if bytes.starts_with(COMPACT_MAGIC) {
            return Self::parse_compact(bytes);
        }
        if bytes.len() < HEADER_LEN {
            return Err(DrwError::TooShort);
        }
        let offsets: Vec<usize> = (0..=SYMBOLS).map(|i| (i16_at(bytes, i).max(1) - 1) as usize).collect();
        let n = offsets[SYMBOLS];
        if HEADER_LEN + 10 * n != bytes.len() {
            return Err(DrwError::SizeMismatch { points: n, file_len: bytes.len() });
        }
        let data = &bytes[HEADER_LEN..];
        let xs = &data[..4 * n];
        let ys = &data[4 * n..8 * n];
        let pens = &data[8 * n..];
        let point = |i: usize| ((f32_at(xs, i), f32_at(ys, i)), i16_at(pens, i));
        let name = |k: usize| {
            let raw = &bytes[OFFSETS_LEN + k * NAME_LEN..OFFSETS_LEN + (k + 1) * NAME_LEN];
            String::from_utf8_lossy(raw).trim_end_matches([' ', '\0']).to_string()
        };
        let symbol = |k: usize| -> Result<Symbol, DrwError> {
            let name = name(k);
            let (start, end) = (offsets[k], offsets[k + 1]);
            if start > end || end > n {
                if name.is_empty() {
                    return Ok(Symbol { name, paths: Vec::new(), records: Vec::new() });
                }
                return Err(DrwError::BadOffsets);
            }
            let records = (start..end).map(point).map(|((x, y), pen)| DrwRecord { x, y, pen }).collect();
            Ok(Symbol { name, paths: paths((start..end).map(point)), records })
        };
        let symbols = (0..SYMBOLS).map(symbol).collect::<Result<_, _>>()?;
        Ok(Self { symbols })
    }

    fn parse_compact(bytes: &[u8]) -> Result<Self, DrwError> {
        let records = fortran_records(&bytes[1..])?;
        let header = records.first().filter(|h| h.len() >= COMPACT_HEADER_LEN).ok_or(DrwError::TooShort)?;
        let raw: Vec<i16> = (0..=SYMBOLS).map(|i| i16_at(header, i)).collect();
        let first_points: Vec<i32> = raw
            .iter()
            .enumerate()
            .map(|(k, &o)| if k > 0 && o > 1 { i32::from(o) / 3 + 1 } else { i32::from(o) })
            .collect();
        let data: Vec<u8> = records[1..].concat();
        let words: Vec<i16> = (0..data.len() / 2).map(|i| i16_at(&data, i)).collect();
        let count = (i32::from(raw[SYMBOLS]) + 1).max(0) as usize / 3;
        if words.len() < 3 * count {
            return Err(DrwError::SizeMismatch { points: count, file_len: bytes.len() });
        }
        let record = |i: usize| DrwRecord { x: f32::from(words[3 * i]), y: f32::from(words[3 * i + 1]), pen: words[3 * i + 2] };
        let symbol = |k: usize| {
            let raw_name = &header[OFFSETS_LEN + k * COMPACT_NAME_LEN..OFFSETS_LEN + (k + 1) * COMPACT_NAME_LEN];
            let name = String::from_utf8_lossy(raw_name).trim_end_matches([' ', '\0']).to_string();
            let (start, end) = (first_points[k], first_points[k + 1]);
            let range = if start >= 1 && start <= end && end as usize <= count + 1 {
                (start as usize - 1)..(end as usize - 1)
            } else {
                0..0
            };
            let records: Vec<DrwRecord> = range.map(record).collect();
            let paths = paths(records.iter().map(|r| ((r.x, r.y), r.pen)));
            Symbol { name, paths, records }
        };
        Ok(Self { symbols: (0..SYMBOLS).map(symbol).collect() })
    }
}

/// The records of an MS Fortran unformatted sequential file after its
/// first byte: each a run of sub-records, a length byte before and after.
fn fortran_records(mut bytes: &[u8]) -> Result<Vec<Vec<u8>>, DrwError> {
    let mut records = Vec::new();
    let mut current = Vec::new();
    while let Some((&length, rest)) = bytes.split_first() {
        if length == END_OF_FILE {
            break;
        }
        let size = if length == SUBRECORD_CONTINUES { FULL_SUBRECORD } else { usize::from(length) };
        let chunk = rest.get(..size).ok_or(DrwError::BadRecords)?;
        current.extend_from_slice(chunk);
        bytes = rest.get(size + 1..).ok_or(DrwError::BadRecords)?;
        if length != SUBRECORD_CONTINUES {
            records.push(std::mem::take(&mut current));
        }
    }
    if !current.is_empty() {
        records.push(current);
    }
    Ok(records)
}
