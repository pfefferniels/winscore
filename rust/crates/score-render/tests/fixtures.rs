//! Comparison with the engine fixtures in `rust/fixtures` (score-testkit).
//!
//! A ratchet: the cases named in `expected_matching.txt` must match, every
//! other valid case is compared and reported without failing. When a case
//! starts to match, add it to the list.

use std::collections::BTreeSet;

use score_render::{render, Document};
use score_testkit::{compare, fixtures_dir, load_all, CompareOptions, Fixture, Report};

const EXPECTED: &str = include_str!("expected_matching.txt");

fn expected() -> BTreeSet<&'static str> {
    EXPECTED.lines().map(str::trim).filter(|l| !l.is_empty() && !l.starts_with('#')).collect()
}

fn report(fixture: &Fixture) -> Report {
    let file = fixture.input().expect("fixture input parses");
    compare(&fixture.display, &render(&Document::new(&file)), &CompareOptions::default())
}

#[test]
fn fixtures_match_the_engine() {
    let fixtures = load_all(&fixtures_dir()).expect("fixtures load");
    let expected = expected();
    let known: BTreeSet<&str> = fixtures.iter().filter(|f| f.meta.valid).map(|f| f.name.as_str()).collect();
    let unknown: Vec<&&str> = expected.difference(&known).collect();
    assert!(unknown.is_empty(), "expected_matching.txt names cases that are missing or invalid: {unknown:?}");

    let results: Vec<(&Fixture, Report)> =
        fixtures.iter().filter(|f| f.meta.valid).map(|f| (f, report(f))).collect();
    let regressions: Vec<String> = results
        .iter()
        .filter(|(f, r)| expected.contains(f.name.as_str()) && !r.is_match())
        .map(|(f, r)| format!("{} ({}):\n{r}", f.name, f.meta.description))
        .collect();
    let newly_matching: Vec<&str> = results
        .iter()
        .filter(|(f, r)| !expected.contains(f.name.as_str()) && r.is_match())
        .map(|(f, _)| f.name.as_str())
        .collect();
    let open: Vec<&str> = results.iter().filter(|(_, r)| !r.is_match()).map(|(f, _)| f.name.as_str()).collect();

    println!("{} of {} valid fixtures match", results.len() - open.len(), results.len());
    println!("not matching yet ({}): {}", open.len(), open.join(" "));
    if !newly_matching.is_empty() {
        println!("matching but not in expected_matching.txt: {}", newly_matching.join(" "));
    }
    assert!(regressions.is_empty(), "{} expected cases differ:\n{}", regressions.len(), regressions.join("\n"));
}
