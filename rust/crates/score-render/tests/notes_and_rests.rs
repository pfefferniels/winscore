//! Codes 1 and 2 against their engine fixtures, comparing only what notes
//! and rests drew. Reports every case; `NOTES_DETAIL=<prefix>` prints the
//! differences of the cases whose names start with it, and `NOTES_JSON=<dir>`
//! writes the renderings for `score-compare --actual <dir>`.

use std::path::Path;

use score_format::MusFile;
use score_render::{render, Document, ItemId};
use score_testkit::{compare, display_to_json, fixtures_dir, load_all, restrict, CompareOptions, Fixture, Report};

const CODES: [i32; 2] = [1, 2];

fn report(fixture: &Fixture) -> Report {
    let file = fixture.input().expect("fixture input parses");
    let keep = |id: ItemId| is_ours(&file, id);
    let actual = render(&Document::new(&file));
    if let Ok(dir) = std::env::var("NOTES_JSON") {
        let path = Path::new(&dir).join(format!("{}.json", fixture.name));
        std::fs::write(&path, display_to_json(&actual)).expect("rendering written");
    }
    compare(&restrict(&fixture.display, keep), &restrict(&actual, keep), &CompareOptions::default())
}

fn is_ours(file: &MusFile, ItemId(i): ItemId) -> bool {
    file.items.get(i as usize).is_some_and(|item| CODES.contains(&item.code()))
}

#[test]
fn notes_and_rests_report() {
    let fixtures = load_all(&fixtures_dir()).expect("fixtures load");
    let samples = std::env::var("NOTES_SAMPLES").is_ok();
    let ours: Vec<&Fixture> = fixtures
        .iter()
        .filter(|f| f.meta.valid)
        .filter(|f| f.name.starts_with("code01-") || f.name.starts_with("code02-") || (samples && f.name.starts_with("sample-")))
        .collect();
    let detail = std::env::var("NOTES_DETAIL").ok();
    let results: Vec<(&Fixture, Report)> = ours.iter().map(|f| (*f, report(f))).collect();
    let open: Vec<&(&Fixture, Report)> = results.iter().filter(|(_, r)| !r.is_match()).collect();
    println!("{} of {} note and rest fixtures match", results.len() - open.len(), results.len());
    results.iter().filter(|(_, r)| r.is_match()).for_each(|(f, _)| println!("matches: {}", f.name));
    open.iter().for_each(|(f, r)| {
        println!("differs: {} (max deviation {})", f.name, r.max_deviation());
        if detail.as_deref().is_some_and(|d| f.name.starts_with(d)) {
            println!("{r}");
        }
    });
}
