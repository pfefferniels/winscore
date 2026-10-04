//! File formats of Leland Smith's SCORE (DOS) and WinScore.
//!
//! The `.mus` layout follows Smith's own description in the WinScore help
//! ("Saved File Structure") and has been checked against files re-saved by
//! the original engine running under emulation.

pub mod drw;
pub mod mus;
pub mod word;

pub use drw::{DrwError, DrwLibrary, PathKind, Symbol, SymbolPath};
pub use mus::{CountWidth, Item, MusError, MusFile, Trailer};
pub use word::Word;
