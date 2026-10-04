use crate::document::ItemId;

#[derive(Debug, Clone, PartialEq)]
pub enum EditError {
    /// A word the command tables do not know in the current context.
    UnknownCommand(String),
    /// A command that works on the item in edit mode, with nothing selected.
    NoSelection(String),
    /// A known command that does not apply to the selected kind of item.
    NotForCode { command: String, code: i32 },
    /// Item numbers count from 1 in file order.
    NoSuchItem(usize),
    NoSuchId(ItemId),
    /// Parameter numbers run from 1 to [`crate::params::MAX_PARAM`].
    NoSuchParam(f32),
    NothingToUndelete,
    /// A command for when no item is in edit mode (UND).
    InEditMode(String),
    /// A command that needs a number, given none or a wrong one.
    BadArgument(String),
}

impl std::fmt::Display for EditError {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        match self {
            EditError::UnknownCommand(w) => write!(f, "unknown word in this context: {w}"),
            EditError::NoSelection(w) => write!(f, "{w} works on the item in edit mode; select an item first"),
            EditError::NotForCode { command, code } => write!(f, "{command} does not apply to code {code} items"),
            EditError::NoSuchItem(n) => write!(f, "there is no item {n}"),
            EditError::NoSuchId(id) => write!(f, "item id {} is not in the score", id.0),
            EditError::NoSuchParam(p) => write!(f, "there is no parameter P{p}"),
            EditError::NothingToUndelete => write!(f, "nothing to undelete"),
            EditError::InEditMode(w) => write!(f, "cannot do {w} while still in edit mode"),
            EditError::BadArgument(w) => write!(f, "{w} needs a number"),
        }
    }
}

impl std::error::Error for EditError {}
