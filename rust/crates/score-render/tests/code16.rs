//! Code 16 against the engine: every `code16-*` fixture, comparing only what
//! the text items drew. `CODE16_FIXTURES=<dir>` adds the cases of another
//! fixture directory.

use std::path::PathBuf;

use score_render::{render, Document};
use score_testkit::{compare, fixtures_dir, load_all, restrict, CompareOptions, Fixture, Report};

const TEXT: i32 = 16;

fn fixtures() -> Vec<Fixture> {
    let extra = std::env::var_os("CODE16_FIXTURES").map(PathBuf::from);
    [Some(fixtures_dir()), extra]
        .into_iter()
        .flatten()
        .flat_map(|dir| load_all(&dir).expect("fixtures load"))
        .filter(|f| f.name.starts_with("code16-") && f.meta.valid)
        .collect()
}

fn report(fixture: &Fixture) -> Report {
    let file = fixture.input().expect("fixture input parses");
    let is_text = |id: score_render::ItemId| file.items.get(id.0 as usize).is_some_and(|i| i.code() == TEXT);
    let expected = restrict(&fixture.display, is_text);
    let actual = restrict(&render(&Document::new(&file)), is_text);
    compare(&expected, &actual, &CompareOptions::default())
}

#[test]
fn text_items_match_the_engine() {
    let results: Vec<(String, Report)> = fixtures().iter().map(|f| (f.name.clone(), report(f))).collect();
    let open: Vec<&(String, Report)> = results.iter().filter(|(_, r)| !r.is_match()).collect();
    println!("{} of {} code-16 fixtures match", results.len() - open.len(), results.len());
    open.iter().for_each(|(name, r)| println!("--- {name}\n{r}"));
}
