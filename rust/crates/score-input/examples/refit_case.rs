//! Prints one refit case of tests/refit_cases.txt: the sorted input, score-input's refit and
//! the engine's result, item by item, marking the items that differ.
//!
//!     cargo run -p score-input --example refit_case -- NAME

use std::fs;
use std::path::Path;

use score_format::{Item, Word};
use score_input::{refit, RefitMode};

fn item(text: &str) -> Item {
    Item::new(text.split_whitespace().map(|v| Word::from_f32(v.parse().expect("number"))).collect())
}

fn block<'a>(text: &'a str, name: &str) -> Vec<&'a str> {
    let start = text.find(&format!("== {name}\n")).unwrap_or_else(|| panic!("no case {name}"));
    text[start..].lines().skip(1).take_while(|l| !l.starts_with("== ")).filter(|l| !l.starts_with('#') && !l.trim().is_empty()).collect()
}

fn show(item: Option<&Item>) -> String {
    item.map_or_else(String::new, |it| it.params().iter().map(|w| format!("{}", w.as_f32())).collect::<Vec<_>>().join(" "))
}

fn main() {
    let name = std::env::args().nth(1).expect("case name");
    let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("tests");
    let cases = fs::read_to_string(dir.join("refit_cases.txt")).expect("cases");
    let expected = fs::read_to_string(dir.join("refit_expected.txt")).expect("expected");
    let lines = block(&cases, &name);
    let base: Vec<Item> = lines[0].strip_prefix("base:").expect("base").split(';').map(item).collect();
    let mode = match lines[1] {
        "FLI" => RefitMode::Invert,
        "FLN" => RefitMode::Normal,
        "FLD" => RefitMode::Down,
        _ => RefitMode::Up,
    };
    let answer: Vec<f32> = lines[2].split_whitespace().map(|v| v.parse().expect("number")).collect();
    let right = if answer[2] == 0.0 { 200.0 } else { answer[2] };
    let sorted = score_layout::sort(&base).map_or_else(|e| e.layout.items, |l| l.items);
    let ours = match refit(&sorted, answer[0] as i32, (answer[1], right), mode) {
        Ok(items) => items,
        Err(err) => {
            println!("refit error: {err}");
            err.items
        }
    };
    let engine: Vec<Item> = block(&expected, &name).into_iter().map(item).collect();
    println!("{} {}", lines[1], lines[2]);
    for i in 0..ours.len().max(engine.len()) {
        let (a, b) = (show(ours.get(i)), show(engine.get(i)));
        println!("{:3} in     {}", i + 1, show(sorted.get(i)));
        if a == b {
            println!("    same   {a}");
        } else {
            println!("    ours   {a}\n    engine {b}");
        }
    }
}
