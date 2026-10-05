//! Reference fixtures from WinScore's emulated engine and the comparison of
//! display lists against them.
//!
//! Fixtures live in `rust/fixtures/<case>/` (format: `rust/fixtures/README.md`):
//! `input.mus`, the engine's display list `engine.json` in page coordinates,
//! and `meta.json`. Typical use from an integration test of a renderer:
//!
//! ```no_run
//! use score_testkit::{assert_matches_fixture, Fixture};
//!
//! let fixture = Fixture::named("code08-default").unwrap();
//! let file = fixture.input().unwrap();
//! # let rendered = score_render::DisplayList::default();
//! // let rendered = score_render::render(&score_render::Document::new(&file));
//! assert_matches_fixture(&fixture, &rendered);
//! ```
//!
//! Use integration tests (`tests/*.rs`) from `score-render`: a unit test inside
//! the crate would see a second copy of its types through this crate.

pub mod compare;
pub mod fixture;
pub mod json;
pub mod layout;
pub mod svg;
pub mod triage;

pub use compare::{
    compare, is_staff_number, restrict, CompareOptions, Nearest, Report, Section, Unmatched,
    STAFF_NUMBER_COLOUR,
};
pub use fixture::{fixtures_dir, load_all, Fixture, FixtureError, Meta};
pub use json::{display_from_json, display_to_json};

use std::panic::{self, AssertUnwindSafe};

use score_render::{render, DisplayList, Document, ItemId};

/// The fixture's input rendered with `score_render`; a renderer panic becomes an error.
pub fn render_fixture(fixture: &Fixture) -> Result<DisplayList, String> {
    let file = fixture.input().map_err(|e| e.to_string())?;
    panic::catch_unwind(AssertUnwindSafe(|| render(&Document::new(&file)))).map_err(|payload| {
        let message = payload
            .downcast_ref::<&str>()
            .map(|s| s.to_string())
            .or_else(|| payload.downcast_ref::<String>().cloned())
            .unwrap_or_else(|| "panic without message".into());
        format!("render panicked: {message}")
    })
}

/// Panics with the comparison report unless `actual` matches the fixture within ±1 unit.
pub fn assert_matches_fixture(fixture: &Fixture, actual: &DisplayList) {
    assert_matches_fixture_with(fixture, actual, &CompareOptions::default());
}

pub fn assert_matches_fixture_with(
    fixture: &Fixture,
    actual: &DisplayList,
    options: &CompareOptions,
) {
    assert!(
        fixture.meta.valid,
        "fixture {} is marked invalid: {:?}",
        fixture.name, fixture.meta.invalid_reasons
    );
    let report = compare(&fixture.display, actual, options);
    assert!(
        report.is_match(),
        "{} ({}) does not match the engine:\n{report}",
        fixture.name,
        fixture.meta.description
    );
}

/// Like [`assert_matches_fixture`], but compares only what the items with the
/// given codes (P1) drew, on both sides. Elements need their `source` set.
pub fn assert_codes_match_fixture(fixture: &Fixture, actual: &DisplayList, codes: &[i32]) {
    let file = fixture.input().unwrap_or_else(|e| panic!("{e}"));
    let keep = |ItemId(i): ItemId| {
        file.items
            .get(i as usize)
            .is_some_and(|item| codes.contains(&item.code()))
    };
    let expected = restrict(&fixture.display, keep);
    assert!(
        !expected.shapes.is_empty() || !expected.texts.is_empty(),
        "fixture {} has no output from items with codes {codes:?}",
        fixture.name
    );
    let report = compare(
        &expected,
        &restrict(actual, keep),
        &CompareOptions::default(),
    );
    assert!(
        report.is_match(),
        "{} ({}), codes {codes:?}, does not match the engine:\n{report}",
        fixture.name,
        fixture.meta.description
    );
}
