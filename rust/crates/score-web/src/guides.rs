//! What the shell's guides line a dragged item up with: every item's
//! reference point and level, and where the staves and their lines lie.
//! Both cross into JavaScript as flat `Float32Array`s.

use score_format::MusFile;
use score_render::codes;
use score_render::codes::staff::drawn_lines;
use score_render::page::{self, page_offset};
use score_render::Document;
use wasm_bindgen::prelude::*;

use crate::Score;

/// Numbers per item in [`anchors`].
pub const ANCHOR_WORDS: usize = 6;
/// Numbers per staff in [`staves`].
pub const STAFF_WORDS: usize = 7;

/// A note head's half width in step units (draw_note's 17).
const HALF_HEAD: f64 = 8.5;

/// Per item, in file order: code, staff, the page x and y of its reference
/// point (P3, P4 and P15 as item_position places them), its level in scale
/// steps above its staff's P4 = 0, and the x its centre lines up by: a note
/// head's middle, else the reference x.
pub fn anchors(file: &MusFile) -> Vec<f32> {
    let doc = Document::new(file);
    doc.items()
        .flat_map(|item| {
            let staff = doc.staff_of(item);
            let at = doc.position(item);
            let offset = page_offset(item.staff());
            let (x, y) = (at.x + f64::from(offset.x), at.y + f64::from(offset.y));
            let level = (at.y - f64::from(staff.level0)) / staff.scale_step();
            let centre = if item.code() == codes::NOTE { x + HALF_HEAD * staff.step } else { x };
            [item.code() as f32, item.staff() as f32, x as f32, y as f32, level as f32, centre as f32]
        })
        .collect()
}

/// Per staff defined by a code-8 item, by number: number, the page x of
/// its left and right ends, the page y of its P4 = 0 level, its scale step,
/// the level of its lowest drawn line and how many lines it has (two scale
/// steps apart).
pub fn staves(file: &MusFile) -> Vec<f32> {
    let doc = Document::new(file);
    doc.staves
        .defined()
        .filter_map(|staff| {
            let item = doc.item(staff.source?)?;
            let offset = page_offset(staff.number);
            let right = if item.p(6) == 0.0 { 200.0 } else { item.p(6) };
            let (first, count) = drawn_lines(item.p(7));
            let bottom_line = (staff.bottom - f64::from(staff.level0)) / staff.scale_step();
            Some([
                staff.number as f32,
                (page::x(item.p(3)) + f64::from(offset.x)) as f32,
                (page::x(right) + f64::from(offset.x)) as f32,
                (f64::from(staff.level0) + f64::from(offset.y)) as f32,
                staff.scale_step() as f32,
                (bottom_line + f64::from(2 * first)) as f32,
                count as f32,
            ])
        })
        .flatten()
        .collect()
}

#[wasm_bindgen]
impl Score {
    /// [`anchors`]: six numbers per item (`Float32Array`).
    #[wasm_bindgen(js_name = guideAnchors)]
    pub fn guide_anchors(&self) -> Vec<f32> {
        anchors(self.0.file())
    }

    /// [`staves`]: seven numbers per defined staff (`Float32Array`).
    #[wasm_bindgen(js_name = staffGeometry)]
    pub fn staff_geometry(&self) -> Vec<f32> {
        staves(self.0.file())
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::path::PathBuf;

    fn mozart() -> MusFile {
        let path = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../assets/samples/mozart.mus");
        MusFile::parse(&std::fs::read(path).unwrap()).unwrap()
    }

    #[test]
    fn anchors_place_items_on_their_staves() {
        let file = mozart();
        let anchors = anchors(&file);
        assert_eq!(anchors.len(), file.items.len() * ANCHOR_WORDS);
        let note = file.items.iter().position(|i| i.code() == codes::NOTE).unwrap();
        let words = &anchors[note * ANCHOR_WORDS..(note + 1) * ANCHOR_WORDS];
        let item = &file.items[note];
        assert_eq!(words[0], 1.0);
        assert!((words[4] - item.param(4).rem_euclid(100.0)).abs() < 1e-3, "{words:?}");
        assert!(words[5] > words[2]);
        let doc = Document::new(&file);
        let staff = doc.staves.get(item.param(2) as i32);
        let y = staff.y(f64::from(words[4])) + f64::from(page_offset(staff.number).y);
        assert!((f64::from(words[3]) - y).abs() < 0.5);
    }

    #[test]
    fn staves_name_their_lines() {
        let file = mozart();
        let staves = staves(&file);
        assert_eq!(staves.len() % STAFF_WORDS, 0);
        let first = &staves[..STAFF_WORDS];
        // Level 0 is truncated to whole units, so the bottom line lies a hair below level 3.
        assert!(
            (first[5] - 3.0).abs() < 0.01 && first[6] == 5.0,
            "a normal staff's five lines from level 3: {first:?}"
        );
        assert!(first[2] > first[1]);
    }
}
