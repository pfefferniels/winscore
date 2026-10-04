//! Font metric files shipped with WinScore 5.01.

use std::path::{Path, PathBuf};

use score_format::FontMetrics;

fn fontlib() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../WINSCORE 5.01/winscore/fontlib")
}

fn metrics(name: &str) -> FontMetrics {
    FontMetrics::parse(&std::fs::read(fontlib().join(name)).unwrap()).unwrap()
}

#[test]
fn every_shipped_file_parses() {
    let parsed = std::fs::read_dir(fontlib())
        .unwrap()
        .map(|e| e.unwrap().path())
        .filter(|p| p.extension().is_some_and(|x| x.eq_ignore_ascii_case("fmt")))
        .map(|p| FontMetrics::parse(&std::fs::read(&p).unwrap()).map_err(|e| (p, e)))
        .collect::<Result<Vec<_>, _>>()
        .unwrap();
    assert!(parsed.len() > 60);
}

/// Adobe's Times-Roman AFM: zero 500, A 722, M 889, period 250, a 444, space 250.
#[test]
fn times_roman_has_the_adobe_widths() {
    let times = metrics("FM00.FMT");
    assert_eq!((times.postscript_name.as_str(), times.family.as_str()), ("Times-Roman", "Times"));
    assert_eq!([0, 10, 22, 36, 40, 94].map(|i| times.width(i).unwrap()), [500, 722, 889, 250, 444, 250]);
}

#[test]
fn long_names_fill_their_fields() {
    let narrow = metrics("FM11.FMT");
    assert_eq!(narrow.postscript_name, "Helvetica-Narrow-BoldOblique");
    assert_eq!(narrow.family, "Helvetica-Narrow");
    assert_eq!(metrics("FM35.FMT").family, "Americana");
}
