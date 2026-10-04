//! Cross-checks the editor against disasm-expert's catalogue of every menu
//! command run through the emulated engine (analysis/engine/data/commands.tsv):
//! each supported command, with nothing selected ("new") and with the note
//! item 4 selected ("note"), must add the same items and leave item 4 as the
//! engine did. Deliberate differences are listed in `common`.

mod common;

use common::{deviates, numbers, rows, Row};
use score_edit::command::is_supported;
use score_edit::{Draft, Editor};
use score_format::{CountWidth, Item, MusFile, Word};

/// cmdlab.py's base score: staves 1–2, a treble clef, a note, a rest, a barline.
const BASE: [&[f32]; 6] = [
    &[8.0, 1.0, 0.0, 0.0, 1.0],
    &[8.0, 2.0, 0.0, 0.0, 1.0],
    &[3.0, 1.0, 2.0, 0.0, 0.0],
    &[1.0, 1.0, 30.0, 5.0, 10.0, 0.0, 1.0],
    &[2.0, 1.0, 50.0, 0.0, 0.0, 0.0, 1.0],
    &[14.0, 1.0, 70.0, 1.0],
];
const ITEM4: usize = 3;

fn base() -> Editor {
    let words: [f32; 6] = [0.0, 0.0, 6.0, 0.0, 5.0, -9999.0];
    let mut bytes = (words.len() as u16).to_le_bytes().to_vec();
    bytes.extend(words.iter().flat_map(|w| w.to_le_bytes()));
    let trailer = MusFile::parse(&bytes).unwrap().trailer;
    let items = BASE.iter().map(|p| Item::new(p.iter().copied().map(Word::from_f32).collect())).collect();
    Editor::new(MusFile { width: CountWidth::Short, items, trailer })
}

fn params(item: &Item) -> Vec<f32> {
    let draft = Draft::of(item);
    numbers(&(1..=draft.len()).map(|n| draft.get(n).to_string()).collect::<Vec<_>>().join(" "))
}

/// Items of `after` that are not in `before`, counting duplicates.
fn added(before: Vec<Vec<f32>>, after: &[Vec<f32>]) -> Vec<Vec<f32>> {
    after
        .iter()
        .fold((Vec::new(), before), |(mut added, mut left), p| {
            match left.iter().position(|q| q == p) {
                Some(i) => {
                    left.remove(i);
                }
                None => added.push(p.clone()),
            }
            (added, left)
        })
        .0
}

/// What the editor does with the row's command: items added and item 4 after.
fn replay(row: &Row) -> (Vec<Vec<f32>>, Vec<f32>) {
    let mut editor = base();
    let before: Vec<Vec<f32>> = editor.file().items.iter().map(params).collect();
    if row.note_context {
        editor.execute("I 4").unwrap();
    }
    let _ = editor.execute(&row.command);
    let _ = editor.execute("X");
    let after: Vec<Vec<f32>> = editor.file().items.iter().map(params).collect();
    (added(before, &after), after.get(ITEM4).cloned().unwrap_or_default())
}

/// The catalogue prints values with about four decimals.
fn same(a: &[f32], b: &[f32]) -> bool {
    a.len() == b.len() && a.iter().zip(b).all(|(x, y)| (x - y).abs() <= 1e-4 * x.abs().max(1.0))
}

fn same_items(a: &[Vec<f32>], b: &[Vec<f32>]) -> bool {
    a.len() == b.len() && a.iter().zip(b).all(|(x, y)| same(x, y))
}

#[test]
fn supported_commands_match_the_catalogue() {
    let unchanged = numbers(&BASE[ITEM4].iter().map(f32::to_string).collect::<Vec<_>>().join(" "));
    let mismatches: Vec<String> = rows()
        .iter()
        .filter(|row| is_supported(&row.command) && !deviates(row))
        .filter_map(|row| {
            let (added, item4) = replay(row);
            let want_item4 = row.item4_after.as_ref().unwrap_or(&unchanged);
            (!(same(want_item4, &item4) && same_items(&added, &row.added))).then(|| {
                format!(
                    "[{}] {}: engine added {:?} item4 {:?}; ours added {:?} item4 {:?}",
                    row.command.trim(),
                    if row.note_context { "note" } else { "new" },
                    row.added,
                    want_item4,
                    added,
                    item4
                )
            })
        })
        .collect();
    assert!(mismatches.is_empty(), "{} mismatches:\n{}", mismatches.len(), mismatches.join("\n"));
}
