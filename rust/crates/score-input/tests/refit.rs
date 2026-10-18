//! Replays tests/refit_cases.txt (group FLI/FLN/FLU/FLD on one staff) and compares with
//! the expected items in tests/refit_expected.txt. The commands sort the items first, then
//! refit each staff of the area.

use std::collections::BTreeMap;
use std::fs;
use std::path::Path;

use score_format::{Item, Word};
use score_input::{refit_staves, RefitMode};

const TOLERANCE: f32 = 1e-4;

struct Case {
    name: String,
    base: Vec<Item>,
    commands: Vec<String>,
}

fn item(text: &str) -> Item {
    Item::new(text.split_whitespace().map(|v| Word::from_f32(v.parse().expect("number"))).collect())
}

fn blocks(text: &str) -> Vec<(String, Vec<&str>)> {
    text.split("\n== ")
        .skip(1)
        .map(|block| {
            let mut lines = block.lines();
            let name = lines.next().unwrap_or_default().trim().to_string();
            (name, lines.filter(|l| !l.starts_with('#') && !l.trim().is_empty()).collect())
        })
        .collect()
}

fn cases(text: &str) -> Vec<Case> {
    blocks(&format!("\n{text}"))
        .into_iter()
        .map(|(name, lines)| {
            let base = lines.iter().find_map(|l| l.strip_prefix("base:")).expect("base line");
            Case {
                name,
                base: base.split(';').map(item).collect(),
                commands: lines.iter().filter(|l| !l.starts_with("base:")).map(|l| l.trim().to_string()).collect(),
            }
        })
        .collect()
}

/// The command with the area answer "staff left right [last staff]".
fn run(case: &Case) -> Vec<Item> {
    let mode = match case.commands[0].as_str() {
        "FLI" => RefitMode::Invert,
        "FLN" => RefitMode::Normal,
        "FLD" => RefitMode::Down,
        "FLU" => RefitMode::Up,
        other => panic!("{}: unknown command {other}", case.name),
    };
    let answer: Vec<f32> = case.commands[1].split_whitespace().map(|v| v.parse().expect("number")).collect();
    let get = |k: usize| answer.get(k).copied().unwrap_or(0.0);
    let right = if get(2) == 0.0 { 200.0 } else { get(2) };
    let first = get(0) as i32;
    let last = (get(3) as i32).max(first);
    let sorted = score_layout::sort(&case.base).map_or_else(|err| err.layout.items, |layout| layout.items);
    refit_staves(&sorted, (first, last), (get(1), right), mode).items
}

fn params(item: &Item) -> Vec<f32> {
    item.params().iter().map(|w| w.as_f32()).collect()
}

fn difference(ours: &Item, expected: &Item) -> Option<String> {
    let (a, b) = (params(ours), params(expected));
    let n = a.len().max(b.len());
    let get = |v: &[f32], k: usize| v.get(k).copied().unwrap_or(0.0);
    (0..n).find(|&k| (get(&a, k) - get(&b, k)).abs() > TOLERANCE).map(|k| format!("P{}: ours {:?} expected {:?}", k + 1, a, b))
}

#[test]
fn refit_gives_the_expected_items() {
    let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("tests");
    let cases = cases(&fs::read_to_string(dir.join("refit_cases.txt")).expect("cases"));
    let expected_text = fs::read_to_string(dir.join("refit_expected.txt")).expect("expected");
    let expected: BTreeMap<String, Vec<Item>> =
        blocks(&format!("\n{expected_text}")).into_iter().map(|(name, lines)| (name, lines.into_iter().map(item).collect())).collect();

    let mut failures = Vec::new();
    for case in &cases {
        let Some(want) = expected.get(&case.name) else {
            failures.push(format!("{}: no expected result in refit_expected.txt", case.name));
            continue;
        };
        let ours = run(case);
        let problem = if ours.len() != want.len() {
            Some(format!("{} items, expected {}", ours.len(), want.len()))
        } else {
            ours.iter().zip(want).enumerate().find_map(|(i, (a, b))| difference(a, b).map(|d| format!("item {}: {d}", i + 1)))
        };
        if let Some(p) = problem {
            failures.push(format!("{}: {p}", case.name));
        }
    }
    assert!(failures.is_empty(), "{}", failures.join("\n"));
}
