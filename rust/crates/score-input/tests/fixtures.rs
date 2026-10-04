//! Compares score-input with the emulated engine on every case in rust/fixtures/input.
//!
//! Each case directory holds `input.txt` (SCORE input-file layout) and `result.mus` (what the
//! engine saved after the input was typed; see oracle/input_driver.py). Cases named in
//! `known-mismatches.txt` (one name per line, `#` comments) may differ; every other case must
//! give the same items with parameters equal within 1e-4.

use std::fs;
use std::path::{Path, PathBuf};

use score_format::{Item, MusFile};
use score_input::InputFile;

const TOLERANCE: f32 = 1e-4;

fn fixture_root() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../../fixtures/input")
}

fn cases() -> Vec<PathBuf> {
    let mut dirs: Vec<PathBuf> = fs::read_dir(fixture_root())
        .map(|entries| entries.filter_map(|e| e.ok().map(|e| e.path())).filter(|p| p.join("result.mus").exists()).collect())
        .unwrap_or_default();
    dirs.sort();
    dirs
}

fn known_mismatches() -> Vec<String> {
    fs::read_to_string(fixture_root().join("known-mismatches.txt"))
        .unwrap_or_default()
        .lines()
        .map(|l| l.split('#').next().unwrap_or("").trim().to_string())
        .filter(|l| !l.is_empty())
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

/// None if the items agree, else a description of the first difference.
fn compare(dir: &Path) -> Option<String> {
    let input = fs::read_to_string(dir.join("input.txt")).ok()?;
    let file = match InputFile::parse(&input) {
        Ok(file) => file,
        Err(err) => return Some(format!("input.txt: {err}")),
    };
    let ours = match file.items() {
        Ok(items) => items,
        Err(err) => return Some(format!("error: {err}")),
    };
    let engine = MusFile::parse(&fs::read(dir.join("result.mus")).ok()?).ok()?.items;
    let differing = ours.iter().zip(&engine).position(|(a, b)| !same(&params(a), &params(b)));
    match differing {
        Some(i) => Some(format!("item {}: ours [{}] engine [{}]", i + 1, format(&params(&ours[i])), format(&params(&engine[i])))),
        None if ours.len() != engine.len() => Some(format!("{} items, engine {}", ours.len(), engine.len())),
        None => None,
    }
}

#[test]
fn input_fixtures_match_the_engine() {
    let known = known_mismatches();
    let results: Vec<(String, Option<String>)> = cases()
        .iter()
        .map(|dir| (dir.file_name().unwrap().to_string_lossy().into_owned(), compare(dir)))
        .collect();
    let matching = results.iter().filter(|(_, r)| r.is_none()).count();
    eprintln!("{matching} of {} input fixtures match the engine", results.len());
    for (name, result) in &results {
        match (result, known.contains(name)) {
            (Some(diff), _) => eprintln!("  {name}: {diff}"),
            (None, true) => eprintln!("  {name}: matches now; remove it from known-mismatches.txt"),
            (None, false) => {}
        }
    }
    let unexpected: Vec<&String> =
        results.iter().filter(|(name, r)| r.is_some() && !known.contains(name)).map(|(name, _)| name).collect();
    assert!(unexpected.is_empty(), "unexpected mismatches: {unexpected:?}");
}
