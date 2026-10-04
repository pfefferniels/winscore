//! Text fonts: the metric files of `fontlib/`, embedded, and what the
//! engine derives from them.

use std::sync::OnceLock;

use score_format::FontMetrics;

macro_rules! fontlib {
    ($($number:literal => $file:literal),* $(,)?) => {
        &[$(($number, include_bytes!(concat!(
            env!("CARGO_MANIFEST_DIR"), "/../../../WINSCORE 5.01/winscore/fontlib/", $file
        )))),*]
    };
}

/// The metric files shipped with WinScore 5.01 by font number.
const FILES: &[(usize, &[u8])] = fontlib! {
    0 => "FM00.FMT", 1 => "FM01.FMT", 2 => "FM02.FMT", 3 => "FM03.FMT", 4 => "FM04.FMT",
    5 => "FM05.FMT", 6 => "FM06.FMT", 7 => "FM07.FMT", 8 => "FM08.FMT", 9 => "FM09.FMT",
    10 => "FM10.FMT", 11 => "FM11.FMT", 12 => "FM12.FMT", 13 => "FM13.FMT", 14 => "FM14.FMT",
    15 => "FM15.FMT", 16 => "FM16.FMT", 17 => "FM17.FMT", 18 => "FM18.FMT", 19 => "FM19.FMT",
    20 => "FM20.FMT", 21 => "FM21.FMT", 22 => "FM22.FMT", 23 => "FM23.FMT", 24 => "FM24.FMT",
    25 => "FM25.FMT", 26 => "FM26.FMT", 27 => "FM27.FMT", 28 => "FM28.FMT", 29 => "FM29.FMT",
    30 => "FM30.FMT", 31 => "FM31.FMT", 32 => "FM32.FMT", 33 => "FM33.FMT", 34 => "FM34.FMT",
    35 => "FM35.FMT", 36 => "FM36.FMT", 37 => "FM37.FMT", 38 => "fm38.fmt", 39 => "fm39.fmt",
    40 => "fm40.fmt", 41 => "fm41.fmt", 42 => "fm42.fmt", 43 => "fm43.fmt", 44 => "fm44.fmt",
    45 => "fm45.fmt", 46 => "fm46.fmt", 47 => "fm47.fmt", 48 => "fm48.fmt", 49 => "fm49.fmt",
    50 => "FM50.FMT", 51 => "FM51.FMT", 52 => "FM52.FMT", 53 => "FM53.FMT", 54 => "fm54.fmt",
    55 => "fm55.fmt", 56 => "fm56.fmt", 57 => "fm57.fmt", 58 => "fm58.fmt", 59 => "fm59.fmt",
    60 => "FM60.FMT", 61 => "fm61.fmt", 62 => "fm62.fmt", 63 => "fm63.fmt", 64 => "fm64.fmt",
    65 => "fm65.fmt", 66 => "fm66.fmt", 67 => "fm67.fmt", 68 => "fm68.fmt", 69 => "fm69.fmt",
    70 => "fm70.fmt", 71 => "fm71.fmt",
};

/// Font numbers run from 0 to 99 (`_nn`).
const FONT_NUMBERS: usize = 100;

/// The engine substitutes Times-Roman for a font without a metric file
/// (0x56B845, with a message).
const SUBSTITUTE: usize = 0;

/// Metric files by font number.
#[derive(Debug, Clone, PartialEq)]
pub struct FontLibrary {
    fonts: Vec<Option<FontMetrics>>,
}

impl FontLibrary {
    /// Libraries from `(font number, file contents)` pairs.
    pub fn from_files<'b>(
        files: impl IntoIterator<Item = (usize, &'b [u8])>,
    ) -> Result<Self, score_format::FmtError> {
        let mut fonts = vec![None; FONT_NUMBERS];
        files.into_iter().filter(|&(n, _)| n < FONT_NUMBERS).try_for_each(|(n, bytes)| {
            fonts[n] = Some(FontMetrics::parse(bytes)?);
            Ok(())
        })?;
        Ok(Self { fonts })
    }

    /// The metric files shipped with WinScore 5.01.
    pub fn bundled() -> &'static FontLibrary {
        static BUNDLED: OnceLock<FontLibrary> = OnceLock::new();
        BUNDLED.get_or_init(|| FontLibrary::from_files(FILES.iter().copied()).expect("the bundled font metrics parse"))
    }

    /// The metrics the engine uses for font `number` (0–99).
    pub fn metrics(&self, number: i32) -> Option<&FontMetrics> {
        let get = |n: usize| self.fonts.get(n).and_then(Option::as_ref);
        usize::try_from(number).ok().and_then(get).or_else(|| get(SUBSTITUTE))
    }
}

/// A font as the engine keeps it in 0x78B6A0: the nn of `_nn`, plus 100 for
/// an outline font (`__nn`).
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub struct Font(pub i32);

impl Font {
    pub const TIMES: Font = Font(0);
    /// Staff numbers are set in Helvetica-Narrow.
    pub const STAFF_NUMBER: Font = Font(8);
    /// The shapes of meter numbers, drawn as library symbols.
    pub const METER: Font = Font(94);

    /// The metric file number.
    pub fn number(self) -> i32 {
        self.0 % 100
    }

    pub fn outline(self) -> bool {
        self.0 >= 100
    }

    /// Fonts 90 and up have no metric file; their glyphs take the widths of
    /// the library symbols.
    pub fn uses_symbol_widths(self) -> bool {
        self.number() >= 90
    }
}

/// Weight and slant as the text record header gives them (0x56CAF0): bold
/// for DEMI or BOLD in the PostScript name, italic for OBLI or ITAL. The
/// engine looks at every four letters but those starting at the first.
pub fn weight_and_italic(postscript_name: &str) -> (i32, bool) {
    let name = postscript_name.to_ascii_uppercase();
    let has = |word: &str| name.as_bytes().windows(4).skip(1).any(|w| w == word.as_bytes());
    let weight = if has("DEMI") || has("BOLD") { 700 } else { 400 };
    (weight, has("OBLI") || has("ITAL"))
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn bundled_fonts() {
        let fonts = FontLibrary::bundled();
        assert_eq!(fonts.metrics(28).map(|m| m.family.as_str()), Some("ZapfChancery"));
        assert_eq!(fonts.metrics(80).map(|m| m.postscript_name.as_str()), Some("Times-Roman"));
    }

    #[test]
    fn styles() {
        assert_eq!(weight_and_italic("Times-Roman"), (400, false));
        assert_eq!(weight_and_italic("Helvetica-BoldOblique"), (700, true));
        assert_eq!(weight_and_italic("ACaslon-SemiboldItalic"), (700, true));
        assert_eq!(weight_and_italic("AvantGarde-Demi"), (700, false));
        assert_eq!(weight_and_italic("ZapfChancery-MediumItalic"), (400, true));
    }
}
