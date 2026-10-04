//! Symbol library files (`LBnnn0.DRW`), ten Code 9 symbols per file.
//!
//! Float variant, as used by most WinScore 5 library files:
//! * 11 little-endian i16 offsets, 1-based (FORTRAN) point indices: symbol k
//!   uses points `off[k] ..< off[k+1]`, with `off[0] = 0` read as 1;
//!   `off[10] - 1` is the point count;
//! * 10 names of 24 blank-padded characters; a blank name marks an unused
//!   slot, whose offsets are leftovers and are ignored;
//! * N x-coordinates (f32), N y-coordinates (f32), N pen codes (i16), with
//!   N = `off[10] - 1`. Pen 1 starts a stroked line, 2 a filled polygon,
//!   3 a further path of the same filled object, 0 continues the current
//!   path. Negative pens (-1, -2, -3) occur too; the engine draws them as
//!   continuation points. [`Symbol::records`] keeps every point with its pen.
//!
//! The engine draws one library unit as 25 engine units (1/160 inch) at
//! normal size; checked against WScore.exe output for symbols 20-29.
//!
//! An older compact variant starting with the bytes `KH` (all SCORE 4 files,
//! some WinScore files) is recognised but not decoded yet.

const SYMBOLS: usize = 10;
const NAME_LEN: usize = 24;
const OFFSETS_LEN: usize = 2 * (SYMBOLS + 1);
const HEADER_LEN: usize = OFFSETS_LEN + SYMBOLS * NAME_LEN;
const COMPACT_MAGIC: &[u8; 2] = b"KH";

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
    CompactVariantUnsupported,
    BadOffsets,
    SizeMismatch { points: usize, file_len: usize },
}

impl std::fmt::Display for DrwError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            DrwError::TooShort => write!(f, "file shorter than the library header"),
            DrwError::CompactVariantUnsupported => write!(f, "compact \"KH\" library variant is not decoded yet"),
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
            return Err(DrwError::CompactVariantUnsupported);
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
            if name.is_empty() {
                return Ok(Symbol { name, paths: Vec::new(), records: Vec::new() });
            }
            let (start, end) = (offsets[k], offsets[k + 1]);
            if start > end || end > n {
                return Err(DrwError::BadOffsets);
            }
            let records = (start..end).map(point).map(|((x, y), pen)| DrwRecord { x, y, pen }).collect();
            Ok(Symbol { name, paths: paths((start..end).map(point)), records })
        };
        let symbols = (0..SYMBOLS).map(symbol).collect::<Result<_, _>>()?;
        Ok(Self { symbols })
    }
}
