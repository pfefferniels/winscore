//! Replays the music input of every case in tests/input_cases.txt and compares the items
//! with tests/input_expected.txt: the same items with parameters equal within 1e-4, or a
//! rejection where the expected result is "rejected".

use std::collections::BTreeMap;

use score_format::Item;
use score_input::InputFile;

const CASES: &str = include_str!("input_cases.txt");
const EXPECTED: &str = include_str!("input_expected.txt");
const TOLERANCE: f32 = 1e-4;

/// `name -> body` for every `== name` block, in file order; text before the first block
/// (the header comment) is left out.
fn blocks(text: &str) -> Vec<(&str, &str)> {
    text.split("\n== ")
        .skip(1)
        .map(|block| block.split_once('\n').map_or((block.trim(), ""), |(name, body)| (name.trim(), body)))
        .collect()
}

fn params(item: &Item) -> Vec<f32> {
    item.params().iter().map(|w| w.as_f32()).collect()
}

fn format(params: &[f32]) -> String {
    params.iter().map(|p| format!("{p}")).collect::<Vec<_>>().join(" ")
}

fn same(a: &[f32], b: &[f32]) -> bool {
    let len = a.len().max(b.len());
    let at = |v: &[f32], i: usize| v.get(i).copied().unwrap_or(0.0);
    (0..len).all(|i| (at(a, i) - at(b, i)).abs() <= TOLERANCE * at(b, i).abs().max(1.0))
}

/// None if score-input gives the expected items (or rejects the input when it should),
/// else a description of the first difference.
fn compare(input: &str, expected: &str) -> Option<String> {
    let ours = InputFile::parse(input).ok().and_then(|file| file.items().ok());
    let want: Vec<Vec<f32>> = match expected.trim() {
        "rejected" => return ours.map(|items| format!("accepted ({} items), expected a rejection", items.len())),
        lines => lines.lines().map(|l| l.split_whitespace().map(|v| v.parse().expect("number")).collect()).collect(),
    };
    let Some(ours) = ours else { return Some("rejected".into()) };
    let differing = ours.iter().zip(&want).position(|(a, b)| !same(&params(a), b));
    match differing {
        Some(i) => Some(format!("item {}: ours [{}] expected [{}]", i + 1, format(&params(&ours[i])), format(&want[i]))),
        None if ours.len() != want.len() => Some(format!("{} items, expected {}", ours.len(), want.len())),
        None => None,
    }
}

#[test]
fn input_gives_the_expected_items() {
    let expected: BTreeMap<&str, &str> = blocks(EXPECTED).into_iter().collect();
    let cases = blocks(CASES);
    let failures: Vec<String> = cases
        .iter()
        .filter_map(|&(name, input)| match expected.get(name) {
            None => Some(format!("{name}: no expected result in input_expected.txt")),
            Some(want) => compare(input, want).map(|diff| format!("{name}: {diff}")),
        })
        .collect();
    assert!(failures.is_empty(), "{} of {} cases differ:\n{}", failures.len(), cases.len(), failures.join("\n"));
}
