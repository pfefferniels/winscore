//! Font metric files (`fontlib/FMnn.FMT`), one per text font number nn.
//!
//! Each file has 708 bytes:
//! * the PostScript font name, 28 characters, padded with blanks or a NUL;
//! * the family name the screen uses for the font, 28 characters, padded the
//!   same way (the shell passes it to `CreateFontA`);
//! * 163 little-endian i16 character widths in 1/1000 em, the PostScript
//!   font's advance widths;
//! * another 163 i16 widths, apparently measured from screen fonts.
//!
//! Entry i is the width of the character with glyph index i in the engine's
//! character order: digits (0–9), capitals (10–35), `. , ( )`, small letters
//! (40–65), punctuation, the space (94), accented and special characters.
//! WScore.exe reads the files in its font loader (0x56B845): it computes
//! advances from the first table (width / 638 per unit of its text scale)
//! and keeps the second.

/// Number of width entries per table.
pub const GLYPHS: usize = 163;

const NAME_LEN: usize = 28;
const TABLE_LEN: usize = 2 * GLYPHS;
/// Size of every font metric file.
pub const FILE_LEN: usize = 2 * NAME_LEN + 2 * TABLE_LEN;

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct FontMetrics {
    /// e.g. `Times-Roman`.
    pub postscript_name: String,
    /// e.g. `Times`; empty in a few damaged files.
    pub family: String,
    /// PostScript advance widths by glyph index, 1/1000 em.
    pub widths: [i16; GLYPHS],
    /// The second table, by glyph index.
    pub screen_widths: [i16; GLYPHS],
}

#[derive(Debug, Clone, PartialEq, Eq)]
pub enum FmtError {
    WrongLength(usize),
}

impl std::fmt::Display for FmtError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            FmtError::WrongLength(len) => write!(f, "font metric file has {len} bytes, expected {FILE_LEN}"),
        }
    }
}

impl std::error::Error for FmtError {}

/// A padded name field: everything before the first NUL, without trailing blanks.
fn name(field: &[u8]) -> String {
    let text = field.split(|&b| b == 0).next().unwrap_or_default();
    String::from_utf8_lossy(text).trim_end().to_string()
}

fn table(bytes: &[u8]) -> [i16; GLYPHS] {
    std::array::from_fn(|i| i16::from_le_bytes([bytes[2 * i], bytes[2 * i + 1]]))
}

impl FontMetrics {
    pub fn parse(bytes: &[u8]) -> Result<Self, FmtError> {
        if bytes.len() != FILE_LEN {
            return Err(FmtError::WrongLength(bytes.len()));
        }
        let (names, tables) = bytes.split_at(2 * NAME_LEN);
        let (printer, screen) = tables.split_at(TABLE_LEN);
        Ok(Self {
            postscript_name: name(&names[..NAME_LEN]),
            family: name(&names[NAME_LEN..]),
            widths: table(printer),
            screen_widths: table(screen),
        })
    }

    /// The PostScript width of glyph `index` in 1/1000 em.
    pub fn width(&self, index: usize) -> Option<i16> {
        self.widths.get(index).copied()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn file(postscript: &[u8], family: &[u8]) -> Vec<u8> {
        let mut bytes = vec![b' '; FILE_LEN];
        bytes[..postscript.len()].copy_from_slice(postscript);
        bytes[NAME_LEN..NAME_LEN + family.len()].copy_from_slice(family);
        (0..2 * GLYPHS).for_each(|i| {
            let at = 2 * NAME_LEN + 2 * i;
            bytes[at..at + 2].copy_from_slice(&(i as i16).to_le_bytes());
        });
        bytes
    }

    #[test]
    fn names_and_tables() {
        let metrics = FontMetrics::parse(&file(b"Americana", b"Americana\0")).unwrap();
        assert_eq!(metrics.postscript_name, "Americana");
        assert_eq!(metrics.family, "Americana");
        assert_eq!(metrics.width(10), Some(10));
        assert_eq!(metrics.screen_widths[0], GLYPHS as i16);
        assert_eq!(metrics.width(GLYPHS), None);
    }

    #[test]
    fn a_name_may_fill_its_field() {
        let metrics = FontMetrics::parse(&file(b"Helvetica-Narrow-BoldOblique", b"Helvetica-Narrow")).unwrap();
        assert_eq!(metrics.postscript_name, "Helvetica-Narrow-BoldOblique");
        assert_eq!(metrics.family, "Helvetica-Narrow");
    }

    #[test]
    fn rejects_other_lengths() {
        assert_eq!(FontMetrics::parse(&[0; 10]), Err(FmtError::WrongLength(10)));
    }
}
