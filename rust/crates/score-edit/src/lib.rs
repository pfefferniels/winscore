//! Editing model of the SCORE editor.
//!
//! An [`Editor`] holds an open `.mus` file. Every item gets an [`ItemId`]
//! that stays valid while items before it come and go; the renderer's
//! `score_render::ItemId` is the item's index, see [`Editor::index_of`].
//! The selection plays the part of WinScore's edit mode: SCORE command lines
//! given to [`Editor::execute`] act on it as the engine acts on the item in
//! edit mode, and every action is one undo step.
//!
//! The commands follow Leland Smith's WinScore help and are checked against
//! WinScore's own engine run under emulation (`oracle/edit_driver.py`, cases
//! in `tests/engine_cases.txt`); `COMMANDS.md` lists what is covered.

pub mod command;
pub mod conditional;
pub mod document;
pub mod drag;
pub mod editor;
pub mod error;
pub mod group;
pub mod history;
pub mod params;
pub mod pick;
mod session;
pub mod symbols;
pub mod text;
pub mod transpose;

pub use document::{Document, Edit, ItemId};
pub use editor::{Change, Editor};
pub use error::EditError;
pub use params::Draft;
/// The layout commands' types, for [`Editor::lay_out`].
pub use score_layout;
