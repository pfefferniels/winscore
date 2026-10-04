//! The command catalogue (analysis/engine/data/commands.tsv: every menu
//! command run through the emulated engine, with nothing selected and with
//! a note selected) and the commands where the editor deliberately differs.

#![allow(dead_code)]

use std::path::PathBuf;

/// Commands the editor handles differently on purpose. Typed "16" makes the
/// engine create a text item without characters. The engine matches some
/// words by their first letters, so in edit mode DBRS+ acts as DBF, LOFF0 and
/// ROT0 as offsets, PLUS1 as the plus mark, UND as U, and with nothing
/// selected NUML creates a number, L1 a note, THE or TN a text through the
/// text dialog; the editor knows these words only in their own sense. The
/// catalogue reads the engine's item store, which OS, OH and OT leave in
/// place while reordering only its index (saving writes the new order).
pub const DEVIATIONS: &[(&str, bool)] = &[
    ("16", false),
    ("OS", false),
    ("OH", false),
    ("OT", false),
    ("BEAM+", false),
    ("DBRS+", true),
    ("DBRS0", true),
    ("DBRW+", true),
    ("DBRW0", true),
    ("DC-", true),
    ("LOFF0", true),
    ("LOFFM", true),
    ("LOFFP", true),
    ("NOS", true),
    ("NUMD", false),
    ("NUMH0", false),
    ("NUML", false),
    ("NUMR", false),
    ("NUMU", false),
    ("NUMV0", false),
    ("L1", false),
    ("PDSZ+", true),
    ("PDSZ-", true),
    ("PLUS1", false),
    ("PLUS1", true),
    ("PLUS10", false),
    ("PLUS10", true),
    ("PLUS100", false),
    ("PLUS100", true),
    ("ROFF0", true),
    ("ROFFM", true),
    ("ROFFP", true),
    ("ROT+", true),
    ("ROT-", true),
    ("ROT0", true),
    ("SPA-", true),
    ("SPD+1", true),
    ("SPD0", true),
    ("TB4", false),
    ("TB5", false),
    ("THE", false),
    ("THK", false),
    ("THK0", false),
    ("THM", false),
    ("TM+", false),
    ("TM1", false),
    ("TN", false),
    ("TNS", false),
    ("UND", true),
];

#[derive(Debug)]
pub struct Row {
    pub command: String,
    pub note_context: bool,
    pub added: Vec<Vec<f32>>,
    pub item4_after: Option<Vec<f32>>,
}

impl Row {
    /// Whether the engine did anything visible.
    pub fn has_effect(&self) -> bool {
        !self.added.is_empty() || self.item4_after.is_some()
    }
}

/// A creation word typed while the note is in edit mode: the engine refuses
/// it (or, matching by first letters, applies an edit word); the editor ends
/// edit mode and creates the item.
fn creates_in_edit_mode(row: &Row) -> bool {
    let word = row.command.split_whitespace().next().unwrap_or("").to_ascii_uppercase();
    row.note_context && score_edit::command::create::template(&word).is_some()
}

pub fn deviates(row: &Row) -> bool {
    DEVIATIONS.contains(&(row.command.trim(), row.note_context)) || creates_in_edit_mode(row)
}

/// Numbers of a parameter list, trailing zeros dropped.
pub fn numbers(text: &str) -> Vec<f32> {
    let mut values: Vec<f32> = text.split_whitespace().filter_map(|v| v.parse().ok()).collect();
    let kept = values.iter().rposition(|&p| p != 0.0).map_or(0, |i| i + 1);
    values.truncate(kept);
    values
}

pub fn rows() -> Vec<Row> {
    let path = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../analysis/engine/data/commands.tsv");
    let table = std::fs::read_to_string(path).expect("analysis/engine/data/commands.tsv");
    table
        .lines()
        .skip(1)
        .filter_map(|line| {
            let cols: Vec<&str> = line.split('\t').collect();
            let [command, context, _status, added, item4, ..] = cols[..] else { return None };
            Some(Row {
                command: command.to_owned(),
                note_context: context == "note",
                added: added.split(';').filter(|s| !s.trim().is_empty()).map(numbers).collect(),
                item4_after: item4.split_once("->").map(|(_, after)| numbers(after)),
            })
        })
        .collect()
}
