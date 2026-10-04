//! Code 16 against the engine: every `code16-*` and `sample-*` fixture,
//! comparing only what the text items drew. `CODE16_FIXTURES=<dir>` adds
//! the cases of another fixture directory.

use std::path::PathBuf;

use score_render::{render, Document};
use score_testkit::{compare, display_to_json, fixtures_dir, load_all, restrict, CompareOptions, Fixture, Report};

const TEXT: i32 = 16;

fn fixtures() -> Vec<Fixture> {
    let extra = std::env::var_os("CODE16_FIXTURES").map(PathBuf::from);
    [Some(fixtures_dir()), extra]
        .into_iter()
        .flatten()
        .flat_map(|dir| load_all(&dir).expect("fixtures load"))
        .filter(|f| (f.name.starts_with("code16-") || f.name.starts_with("sample-")) && f.meta.valid)
        .collect()
}

/// With `CODE16_ACTUAL=<dir>` every rendering is also written there as
/// `<case>.json`, for `score-compare --actual <dir> --images ...`.
fn report(fixture: &Fixture) -> Report {
    let file = fixture.input().expect("fixture input parses");
    let rendered = render(&Document::new(&file));
    if let Some(dir) = std::env::var_os("CODE16_ACTUAL").map(PathBuf::from) {
        std::fs::write(dir.join(format!("{}.json", fixture.name)), display_to_json(&rendered)).expect("writes");
    }
    let is_text = |id: score_render::ItemId| file.items.get(id.0 as usize).is_some_and(|i| i.code() == TEXT);
    compare(&restrict(&fixture.display, is_text), &restrict(&rendered, is_text), &CompareOptions::default())
}

/// Reports every case; the ratchet in tests/fixtures.rs enforces the
/// matching ones.
#[test]
fn text_items_match_the_engine() {
    let results: Vec<(String, Report)> = fixtures().iter().map(|f| (f.name.clone(), report(f))).collect();
    let open: Vec<&(String, Report)> = results.iter().filter(|(_, r)| !r.is_match()).collect();
    println!("{} of {} fixtures match in their text items", results.len() - open.len(), results.len());
    open.iter().for_each(|(name, r)| println!("--- {name}\n{r}"));
}
