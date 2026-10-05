//! The verifier's layout fixtures (rust/fixtures/layout-*): input.mus, the engine's
//! result.mus after the command, compared item by item.

use std::fs;
use std::path::Path;

use score_format::MusFile;
use score_layout::{line_up, Options, StaffRange};

fn mus(case: &str, file: &str) -> MusFile {
    let path = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../fixtures").join(case).join(file);
    MusFile::parse(&fs::read(&path).expect("fixture file")).expect("mus")
}

fn assert_lines_up(case: &str, range: StaffRange) {
    let input = mus(case, "input.mus");
    let engine = mus(case, "result.mus");
    let ours = line_up(&input.items, range, &Options::default()).expect("line-up");
    assert_eq!(ours.items.len(), engine.items.len());
    for (i, (a, b)) in ours.items.iter().zip(&engine.items).enumerate() {
        let (pa, pb): (Vec<f32>, Vec<f32>) = (a.params().iter().map(|w| w.as_f32()).collect(), b.params().iter().map(|w| w.as_f32()).collect());
        let n = pa.len().max(pb.len());
        let get = |v: &[f32], k: usize| v.get(k).copied().unwrap_or(0.0);
        assert!((0..n).all(|k| (get(&pa, k) - get(&pb, k)).abs() <= 1e-4), "{case} item {}: ours {pa:?} engine {pb:?}", i + 1);
    }
}

#[test]
fn li_on_a_two_staff_system() {
    assert_lines_up("layout-li-system", StaffRange::from_answer(1, 2));
}

#[test]
fn lj_without_crowding_is_li() {
    assert_lines_up("layout-lj-system", StaffRange::from_answer(1, 2));
}

#[test]
fn lja_on_one_staff() {
    assert_lines_up("layout-lja-single", StaffRange::from_answer(1, 1));
}
