//! Rests drawn after the editor writes a centred position back.

use std::path::Path;

use score_format::MusFile;
use score_render::codes::rest::centre;
use score_render::{render, Document};

/// Writing rest::centre into P9, as a redraw does, leaves the picture of
/// every centred rest in `tests/rests/` unchanged.
#[test]
fn centred_rest_write_back_keeps_the_picture() {
    let dir = Path::new(env!("CARGO_MANIFEST_DIR")).join("tests/rests");
    let mut paths: Vec<_> = std::fs::read_dir(&dir).expect("tests/rests").map(|e| e.expect("entry").path()).collect();
    paths.sort();
    let written: Vec<String> = paths
        .iter()
        .filter_map(|path| {
            let name = path.file_stem()?.to_string_lossy().into_owned();
            let file = MusFile::parse(&std::fs::read(path).expect("score")).expect("score parses");
            let doc = Document::new(&file);
            let (id, p9) = doc.items().find_map(|item| Some((item.id, centre(&doc, item)?)))?;
            let mut written = file.clone();
            written.items[id.0 as usize] = doc.item(id).expect("rest present").with_params(&[(9, p9)]);
            assert_eq!(render(&doc), render(&Document::new(&written)), "{name}");
            Some(name)
        })
        .collect();
    assert!(written.len() >= 4, "whole, multi-bar, repeat and composite rests write back a centre: {written:?}");
}
