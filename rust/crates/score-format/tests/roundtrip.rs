//! Every sample file must parse and serialise back to identical bytes.

use std::path::{Path, PathBuf};

use score_format::MusFile;

fn project_root() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../../..")
}

fn samples() -> Vec<PathBuf> {
    [
        "carmen.mus",
        "mozart.mus",
        "sonlcs.mus",
        "000.mus",
        "NEWLINE.MUS",
        "NEWLIB.MUS",
    ]
    .iter()
    .map(|p| project_root().join("assets/samples").join(p))
    .collect()
}

#[test]
fn samples_roundtrip_byte_for_byte() {
    for path in samples() {
        let bytes = std::fs::read(&path).unwrap_or_else(|e| panic!("{}: {e}", path.display()));
        let file = MusFile::parse(&bytes).unwrap_or_else(|e| panic!("{}: {e}", path.display()));
        assert_eq!(file.to_bytes(), bytes, "{}", path.display());
    }
}

#[test]
fn carmen_item_count_and_trailer() {
    let bytes = std::fs::read(project_root().join("assets/samples/carmen.mus")).unwrap();
    let file = MusFile::parse(&bytes).unwrap();
    assert_eq!(file.items.len(), 1059);
    assert_eq!(file.trailer.version(), Some(3.0));
    assert_eq!(file.trailer.measurement(), Some(0.0));
    assert_eq!(file.trailer.serial(), Some(4_009_999));
}

#[test]
fn text_items_expose_their_characters() {
    let bytes = std::fs::read(project_root().join("assets/samples/carmen.mus")).unwrap();
    let file = MusFile::parse(&bytes).unwrap();
    let first = &file.items[0];
    assert_eq!(first.code(), 16);
    assert_eq!(first.text(), b"_00Contrebasses");
}

#[test]
fn smiths_documented_example_parses() {
    // The 25-word example file from the WinScore help page "Saved File Structure":
    // staff, treble clef, a note, and the trailer (serial shown as xxx there).
    let words: [f32; 25] = [
        6., 8., 1., 0., 0., 0., 60., 3., 3., 1., 2., 7., 1., 1., 14., 3., 11., 0., 1., 0., 0., 1., 0., 5., -9999.,
    ];
    let bytes: Vec<u8> = (25u16).to_le_bytes().into_iter().chain(words.iter().flat_map(|w| w.to_le_bytes())).collect();
    let file = MusFile::parse(&bytes).unwrap();
    let codes: Vec<i32> = file.items.iter().map(|i| i.code()).collect();
    assert_eq!(codes, [8, 3, 1]);
    assert_eq!(file.items[2].param(5), 11.0);
    assert_eq!(file.to_bytes(), bytes);
}

#[test]
fn empty_file_roundtrips() {
    let empty = MusFile::empty();
    let bytes = empty.to_bytes();
    assert_eq!(MusFile::parse(&bytes).unwrap(), empty);
    assert_eq!(bytes.len(), 26);
    assert!(empty.items.is_empty());
    assert_eq!(empty.trailer.version(), Some(6.0));
    assert_eq!(empty.trailer.measurement(), Some(0.0));
}
