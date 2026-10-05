//! Replays tests/engine_cases.txt and compares with the engine's results in
//! tests/engine_expected.txt (both written by oracle/layout_cases.py). Cases listed in
//! tests/known_mismatches.txt may differ; every other case must match within 1e-4.

use std::collections::BTreeMap;
use std::fs;
use std::path::Path;

use score_format::{Item, Word};
use score_layout::{layout, line_up_and_justify_all, Command, Options, StaffRange};

const TOLERANCE: f32 = 1e-4;

struct Case {
    name: String,
    base: Vec<Item>,
    commands: Vec<String>,
}

fn item(text: &str) -> Item {
    let (numbers, chars) = text.split_once('"').unwrap_or((text, ""));
    let params: Vec<Word> = numbers.split_whitespace().map(|v| Word::from_f32(v.parse().expect("number"))).collect();
    if chars.is_empty() {
        Item::new(params)
    } else {
        let mut bytes = chars.trim_end_matches('"').as_bytes().to_vec();
        bytes.resize(bytes.len().div_ceil(4) * 4, b' ');
        Item::with_text(params, bytes)
    }
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

fn run(case: &Case) -> Vec<Item> {
    let options = Options::default();
    let outcome = if case.commands[0] == "LJA" {
        line_up_and_justify_all(&case.base, &options)
    } else {
        let answer: Vec<i32> = case.commands[1].split_whitespace().map(|v| v.parse().expect("staff number")).collect();
        let range = StaffRange::from_answer(answer[0], answer.get(1).copied().unwrap_or(1));
        let command = match case.commands[0].as_str() {
            "LI" => Command::LineUp,
            "J" => Command::Justify,
            "LJ" => Command::LineUpAndJustify,
            other => panic!("{}: unknown command {other}", case.name),
        };
        layout(&case.base, command, range, &options)
    };
    match outcome {
        Ok(layout) => layout.items,
        Err(err) => err.layout.items,
    }
}

fn params(item: &Item) -> Vec<f32> {
    item.params().iter().map(|w| w.as_f32()).collect()
}

/// P9 of a whole-measure rest marked -1 for centring: the engine's draw_rest replaces it
/// with the centre when it draws the score after the command, which is not part of the
/// layout command itself.
fn drawn_centre(item: &Item, k: usize) -> bool {
    item.code() == 2 && k == 8 && item.param(9) == -1.0
}

/// The first parameter that differs by more than the tolerance (missing ones count as 0).
fn difference(ours: &Item, engine: &Item) -> Option<String> {
    let (a, b) = (params(ours), params(engine));
    let n = a.len().max(b.len());
    let get = |v: &[f32], k: usize| v.get(k).copied().unwrap_or(0.0);
    (0..n)
        .find(|&k| (get(&a, k) - get(&b, k)).abs() > TOLERANCE && !drawn_centre(ours, k))
        .map(|k| format!("P{}: ours {:?} engine {:?}", k + 1, a, b))
}

/// Replays `cases` and compares with `expected`; returns the failures outside the known
/// mismatches.
fn compare(cases_file: &str, expected_file: &str) -> Vec<String> {
    let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("tests");
    let cases = cases(&fs::read_to_string(dir.join(cases_file)).expect("cases"));
    let expected_text = fs::read_to_string(dir.join(expected_file)).expect("expected");
    let expected: BTreeMap<String, Vec<Item>> =
        blocks(&format!("\n{expected_text}")).into_iter().map(|(name, lines)| (name, lines.into_iter().map(item).collect())).collect();
    let known = fs::read_to_string(dir.join("known_mismatches.txt")).unwrap_or_default();
    let known: Vec<&str> = known.lines().filter(|l| !l.starts_with('#') && !l.trim().is_empty()).map(str::trim).collect();

    let mut failures = Vec::new();
    let mut matched = 0;
    for case in &cases {
        let Some(engine) = expected.get(&case.name) else {
            continue;
        };
        let ours = run(case);
        let problem = if ours.len() != engine.len() {
            Some(format!("{} items, engine {}", ours.len(), engine.len()))
        } else {
            ours.iter().zip(engine).enumerate().find_map(|(i, (a, b))| difference(a, b).map(|d| format!("item {}: {d}", i + 1)))
        };
        match problem {
            None => matched += 1,
            Some(p) if !known.contains(&case.name.as_str()) => failures.push(format!("{}: {p}", case.name)),
            Some(_) => {}
        }
    }
    println!("{matched} of {} cases in {cases_file} match the engine", expected.len());
    failures
}

#[test]
fn line_up_matches_the_engine() {
    let failures = compare("engine_cases.txt", "engine_expected.txt");
    assert!(failures.is_empty(), "{}", failures.join("\n"));
}

#[test]
fn justify_matches_the_engine() {
    let failures = compare("justify_cases.txt", "justify_expected.txt");
    assert!(failures.is_empty(), "{}", failures.join("\n"));
}
