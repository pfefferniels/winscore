//! Rests drawn after the editor writes a centred position back.

use score_render::codes::rest::centre;
use score_render::{render, Document};
use score_testkit::{fixtures_dir, load_all, Fixture};

/// Writing rest::centre into P9, as the engine's redraw does, leaves the
/// picture of every centred rest unchanged.
#[test]
fn centred_rest_write_back_keeps_the_picture() {
    let fixtures = load_all(&fixtures_dir()).expect("fixtures load");
    let centred: Vec<&Fixture> = fixtures.iter().filter(|f| f.name.starts_with("code02-p9-cw-")).collect();
    let written: Vec<&str> = centred
        .iter()
        .filter_map(|fixture| {
            let file = fixture.input().expect("fixture input parses");
            let doc = Document::new(&file);
            let (id, p9) = doc.items().find_map(|item| Some((item.id, centre(&doc, item)?)))?;
            let mut written = file.clone();
            written.items[id.0 as usize] = doc.item(id).expect("rest present").with_params(&[(9, p9)]);
            assert_eq!(render(&doc), render(&Document::new(&written)), "{}", fixture.name);
            Some(fixture.name.as_str())
        })
        .collect();
    assert!(written.len() >= 4, "whole, multi-bar, repeat and composite rests write back a centre: {written:?}");
}
