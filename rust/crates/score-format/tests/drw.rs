//! Symbol libraries, checked against geometry drawn by the emulated WScore.exe engine.

use std::path::{Path, PathBuf};

use score_format::drw::ENGINE_UNITS_PER_DRW_UNIT;
use score_format::{DrwError, DrwLibrary, PathKind};

fn scorlib() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../WINSCORE 5.01/winscore/scorlib")
}

fn library(name: &str) -> DrwLibrary {
    DrwLibrary::parse(&std::fs::read(scorlib().join(name)).unwrap()).unwrap()
}

#[test]
fn lb0020_holds_the_articulation_marks() {
    let names: Vec<String> = library("LB0020.DRW").symbols.into_iter().map(|s| s.name).collect();
    assert_eq!(names, ["tail", "wedge", "accnt", "ten", "dot", "wdgdt", "accdt", "tendt", "dnbow", "upbow"]);
}

/// Code 9, P5 = 21 drawn by the engine: a stroke (17750,-4225)-(18350,-3025)
/// and a filled polygon starting (18350,-3025), (18950,-4225), (18700,-4225).
#[test]
fn wedge_matches_engine_output_up_to_translation() {
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
fn float_variant_libraries_parse() {
    let parsed = std::fs::read_dir(scorlib())
        .unwrap()
        .map(|e| e.unwrap().path())
        .filter(|p| p.extension().is_some_and(|x| x.eq_ignore_ascii_case("drw")))
        .map(|p| DrwLibrary::parse(&std::fs::read(&p).unwrap()))
        .filter(|r| r != &Err(DrwError::CompactVariantUnsupported))
        .collect::<Vec<_>>();
    assert_eq!(parsed.len(), 116);
    assert!(parsed.iter().all(Result::is_ok));
}
