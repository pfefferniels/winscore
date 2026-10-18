//! The bundled symbol libraries.

use std::path::{Path, PathBuf};

use score_format::drw::ENGINE_UNITS_PER_DRW_UNIT;
use score_format::{DrwLibrary, PathKind};

fn scorlib() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../assets/scorlib")
}

fn library(name: &str) -> DrwLibrary {
    DrwLibrary::parse(&std::fs::read(scorlib().join(name)).unwrap()).unwrap()
}

#[test]
fn lb0020_holds_the_articulation_marks() {
    let names: Vec<String> = library("LB0020.DRW").symbols.into_iter().map(|s| s.name).collect();
    assert_eq!(names, ["tail", "wedge", "accnt", "ten", "dot", "wdgdt", "accdt", "tendt", "dnbow", "upbow"]);
}

/// The wedge (code 9, P5 = 21): a stroke (17750,-4225)-(18350,-3025)
/// and a filled polygon starting (18350,-3025), (18950,-4225), (18700,-4225).
#[test]
fn wedge_geometry_up_to_translation() {
    let wedge = &library("LB0020.DRW").symbols[1];
    let kinds: Vec<PathKind> = wedge.paths.iter().map(|p| p.kind).collect();
    assert_eq!(kinds, [PathKind::Stroke, PathKind::Fill]);
    let scaled = |p: (f32, f32)| (p.0 * ENGINE_UNITS_PER_DRW_UNIT, p.1 * ENGINE_UNITS_PER_DRW_UNIT);
    let (sx, sy) = scaled(wedge.paths[0].points[0]);
    let relative = |p: (f32, f32)| {
        let (x, y) = scaled(p);
        ((x - sx) as i32, (y - sy) as i32)
    };
    let stroke: Vec<_> = wedge.paths[0].points.iter().copied().map(relative).collect();
    assert_eq!(stroke, [(0, 0), (600, 1200)]);
    let fill: Vec<_> = wedge.paths[1].points[..3].iter().copied().map(relative).collect();
    assert_eq!(fill, [(600, 1200), (1200, 0), (950, 0)]);
}

#[test]
fn every_bundled_library_parses() {
    let parsed = std::fs::read_dir(scorlib())
        .unwrap()
        .map(|e| e.unwrap().path())
        .filter(|p| p.extension().is_some_and(|x| x.eq_ignore_ascii_case("drw")))
        .map(|p| DrwLibrary::parse(&std::fs::read(&p).unwrap()))
        .collect::<Vec<_>>();
    assert_eq!(parsed.len(), 118);
    assert!(parsed.iter().all(Result::is_ok));
}

#[test]
fn compact_libraries() {
    let kbrhy = library("KBRHY.DRW");
    let names: Vec<&str> = kbrhy.symbols.iter().map(|s| s.name.as_str()).take(2).collect();
    assert_eq!(names, ["kbrhy", "kbrh1"]);
    assert_eq!(kbrhy.symbols[0].records.len(), 103);
    assert_eq!(kbrhy.symbols[1].records.len(), 177);
}
