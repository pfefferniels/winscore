//! Runs every menu command of tests/catalogue.tsv on a small score, with
//! nothing selected ("new") and with the note item 4 selected ("note"): each
//! must add the items of its row and leave item 4 as the row says (an empty
//! item4 column: unchanged).

use score_edit::{Draft, Editor};
use score_format::{CountWidth, Item, MusFile, Word};

const CATALOGUE: &str = include_str!("catalogue.tsv");

/// The base score: staves 1–2, a treble clef, a note, a rest, a barline.
const BASE: [&[f32]; 6] = [
    &[8.0, 1.0, 0.0, 0.0, 1.0],
    &[8.0, 2.0, 0.0, 0.0, 1.0],
    &[3.0, 1.0, 2.0, 0.0, 0.0],
    &[1.0, 1.0, 30.0, 5.0, 10.0, 0.0, 1.0],
    &[2.0, 1.0, 50.0, 0.0, 0.0, 0.0, 1.0],
    &[14.0, 1.0, 70.0, 1.0],
];
const ITEM4: usize = 3;

#[derive(Debug)]
struct Row {
    command: String,
    note_context: bool,
    added: Vec<Vec<f32>>,
    item4_after: Option<Vec<f32>>,
}

/// Numbers of a parameter list, trailing zeros dropped.
fn numbers(text: &str) -> Vec<f32> {
    let mut values: Vec<f32> = text.split_whitespace().filter_map(|v| v.parse().ok()).collect();
    let kept = values.iter().rposition(|&p| p != 0.0).map_or(0, |i| i + 1);
    values.truncate(kept);
    values
}

/// The rows of tests/catalogue.tsv: command, context, the added items separated
/// by `|`, and item 4 afterwards.
fn rows() -> Vec<Row> {
    CATALOGUE
        .lines()
        .skip(1)
        .filter_map(|line| {
            let cols: Vec<&str> = line.split('\t').collect();
            let [command, context, added, item4] = cols[..] else { return None };
            Some(Row {
                command: command.to_owned(),
                note_context: context == "note",
                added: added.split('|').filter(|s| !s.trim().is_empty()).map(numbers).collect(),
                item4_after: (!item4.trim().is_empty()).then(|| numbers(item4)),
            })
        })
        .collect()
}

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

fn same(a: &[f32], b: &[f32]) -> bool {
    a.len() == b.len() && a.iter().zip(b).all(|(x, y)| (x - y).abs() <= 1e-4 * x.abs().max(1.0))
}

fn same_items(a: &[Vec<f32>], b: &[Vec<f32>]) -> bool {
    a.len() == b.len() && a.iter().zip(b).all(|(x, y)| same(x, y))
}

#[test]
fn commands_give_the_catalogued_items() {
    let unchanged = numbers(&BASE[ITEM4].iter().map(f32::to_string).collect::<Vec<_>>().join(" "));
    let mismatches: Vec<String> = rows()
        .iter()
        .filter_map(|row| {
            let (added, item4) = replay(row);
            let want_item4 = row.item4_after.as_ref().unwrap_or(&unchanged);
            (!(same(want_item4, &item4) && same_items(&added, &row.added))).then(|| {
                format!(
                    "[{}] {}: expected added {:?} item4 {:?}; ours added {:?} item4 {:?}",
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
