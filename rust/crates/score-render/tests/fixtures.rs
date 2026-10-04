//! Comparison with the engine fixtures in `rust/fixtures` (score-testkit).

use score_render::{render, Document};
use score_testkit::{compare, fixtures_dir, load_all, CompareOptions};

/// The report of every valid fixture named `prefix*` that does not match.
fn mismatches(prefix: &str) -> Vec<String> {
    let fixtures = load_all(&fixtures_dir()).expect("fixtures load");
    let checked: Vec<_> = fixtures.iter().filter(|f| f.name.starts_with(prefix) && f.meta.valid).collect();
    assert!(!checked.is_empty(), "no valid fixtures named {prefix}*");
    checked
        .iter()
        .filter_map(|fixture| {
            let file = fixture.input().expect("fixture input parses");
            let report = compare(&fixture.display, &render(&Document::new(&file)), &CompareOptions::default());
            (!report.is_match()).then(|| format!("{} ({}):\n{report}", fixture.name, fixture.meta.description))
        })
        .collect()
}

fn assert_all_match(prefix: &str) {
    let failed = mismatches(prefix);
    assert!(failed.is_empty(), "{} fixtures differ:\n{}", failed.len(), failed.join("\n"));
}

#[test]
fn staves_match_the_engine() {
    assert_all_match("code08-");
}

#[test]
fn barlines_match_the_engine() {
    assert_all_match("code14-");
}
