//! File formats of Leland Smith's SCORE (DOS) and WinScore.
//!
//! The `.mus` layout follows Smith's own description in the WinScore help
//! ("Saved File Structure").

pub mod drw;
pub mod fmt;
pub mod mus;
pub mod word;

pub use drw::{DrwError, DrwLibrary, DrwRecord, PathKind, Symbol, SymbolPath};
pub use fmt::{FmtError, FontMetrics};
pub use mus::{CountWidth, Item, MusError, MusFile, Trailer};
pub use word::Word;
