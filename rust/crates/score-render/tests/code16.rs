//! Codes 16 (text) and 18 (meters) against the engine, comparing only what
//! items of the code drew. Reports every case; the ratchet in
//! tests/fixtures.rs enforces the matching ones.
//!
//! `CODE16_FIXTURES=<dir>` adds the cases of another fixture directory;
//! `CODE16_ACTUAL=<dir>` writes every rendering there as `<case>.json`, for
//! `score-compare --actual <dir> --images ...`.

use std::path::PathBuf;

use score_render::{render, Document, ItemId};
use score_testkit::{compare, display_to_json, fixtures_dir, load_all, restrict, CompareOptions, Fixture, Report};

fn fixtures(prefixes: &[&str]) -> Vec<Fixture> {
    let extra = std::env::var_os("CODE16_FIXTURES").map(PathBuf::from);
    [Some(fixtures_dir()), extra]
        .into_iter()
        .flatten()
        .flat_map(|dir| load_all(&dir).expect("fixtures load"))
        .filter(|f| prefixes.iter().any(|p| f.name.starts_with(p)) && f.meta.valid)
        .collect()
}

fn report(fixture: &Fixture, code: i32) -> Report {
    let file = fixture.input().expect("fixture input parses");
    let rendered = render(&Document::new(&file));
    if let Some(dir) = std::env::var_os("CODE16_ACTUAL").map(PathBuf::from) {
        std::fs::write(dir.join(format!("{}.json", fixture.name)), display_to_json(&rendered)).expect("writes");
    }
    let of_code = |id: ItemId| file.items.get(id.0 as usize).is_some_and(|i| i.code() == code);
    compare(&restrict(&fixture.display, of_code), &restrict(&rendered, of_code), &CompareOptions::default())
}

fn print_reports(prefixes: &[&str], code: i32) {
    let results: Vec<(String, Report)> = fixtures(prefixes).iter().map(|f| (f.name.clone(), report(f, code))).collect();
    let open: Vec<&(String, Report)> = results.iter().filter(|(_, r)| !r.is_match()).collect();
    println!("{} of {} fixtures match in their code-{code} items", results.len() - open.len(), results.len());
    open.iter().for_each(|(name, r)| println!("--- {name}\n{r}"));
}

#[test]
fn text_items_match_the_engine() {
    print_reports(&["code16-", "sample-"], 16);
}

#[test]
fn meters_match_the_engine() {
    print_reports(&["code18-", "sample-"], 18);
}
