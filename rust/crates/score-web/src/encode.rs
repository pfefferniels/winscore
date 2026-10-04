//! A flat encoding of a display list that crosses into JavaScript as typed
//! arrays and one small JSON string.
//!
//! `shapes` (`Uint32Array`) holds one record per shape, in drawing order:
//!
//! | word | meaning |
//! |---|---|
//! | 0 | flags: bit 0 set = filled (even-odd), clear = polyline |
//! | 1 | colour as `0xRRGGBB` |
//! | 2 | source item index + 1; 0 = no source item |
//! | 3 | number of paths `n` |
//! | 4 … 3+n | number of points of each path |
//!
//! `coords` (`Int32Array`) holds `x, y` of every point of every path, in the
//! same order, in page coordinates (engine units, y up).
//!
//! `texts` is the `engine.json` document of the text runs alone
//! (`{"shapes":[],"texts":[…]}`, see `rust/fixtures/README.md`), and
//! `text_sources` (`Uint32Array`) gives each run's source item index + 1.

use score_render::{Colour, DisplayList, ItemId, Shape, ShapeKind};
use score_testkit::display_to_json;

pub const FLAG_FILL: u32 = 1;

#[derive(Debug, Clone, PartialEq, Eq, Default)]
pub struct Encoded {
    pub shapes: Vec<u32>,
    pub coords: Vec<i32>,
    pub texts: String,
    pub text_sources: Vec<u32>,
}

fn rgb(colour: Colour) -> u32 {
    u32::from(colour.r) << 16 | u32::from(colour.g) << 8 | u32::from(colour.b)
}

fn source_word(source: Option<ItemId>) -> u32 {
    source.map_or(0, |id| id.0 + 1)
}

fn header(shape: &Shape) -> impl Iterator<Item = u32> + '_ {
    let flags = match shape.kind {
        ShapeKind::Fill => FLAG_FILL,
        ShapeKind::Stroke => 0,
    };
    [flags, rgb(shape.colour), source_word(shape.source), shape.paths.len() as u32]
        .into_iter()
        .chain(shape.paths.iter().map(|path| path.len() as u32))
}

fn coords(shape: &Shape) -> impl Iterator<Item = i32> + '_ {
    shape.paths.iter().flatten().flat_map(|p| [p.x, p.y])
}

pub fn encode(list: &DisplayList) -> Encoded {
    let texts_only = DisplayList { shapes: Vec::new(), texts: list.texts.clone() };
    Encoded {
        shapes: list.shapes.iter().flat_map(header).collect(),
        coords: list.shapes.iter().flat_map(coords).collect(),
        texts: display_to_json(&texts_only),
        text_sources: list.texts.iter().map(|run| source_word(run.source)).collect(),
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use score_render::{PlacedText, Point, TextRun};

    #[test]
    fn encodes_records_in_order() {
        let list = DisplayList {
            shapes: vec![
                Shape {
                    kind: ShapeKind::Fill,
                    colour: Colour { r: 0x12, g: 0x34, b: 0x56 },
                    paths: vec![vec![Point::new(1, 2), Point::new(3, 4), Point::new(5, 6)], vec![Point::new(7, 8)]],
                    source: Some(ItemId(4)),
                },
                Shape {
                    kind: ShapeKind::Stroke,
                    colour: Colour::BLACK,
                    paths: vec![vec![Point::new(-1, -2), Point::new(9, 9)]],
                    source: None,
                },
            ],
            texts: vec![],
        };
        let encoded = encode(&list);
        assert_eq!(encoded.shapes, vec![1, 0x123456, 5, 2, 3, 1, 0, 0, 0, 1, 2]);
        assert_eq!(encoded.coords, vec![1, 2, 3, 4, 5, 6, 7, 8, -1, -2, 9, 9]);
        assert!(encoded.text_sources.is_empty());
    }

    #[test]
    fn text_sources_parallel_the_runs() {
        let run = |source| TextRun {
            font: "Times".into(),
            height: 487.2,
            width: 201.0,
            escapement: 0,
            colour: Colour::BLACK,
            weight: 400,
            italic: false,
            underline: false,
            strings: vec![PlacedText { origin: Point::new(10, 20), text: "A".into() }],
            source,
        };
        let list = DisplayList { shapes: vec![], texts: vec![run(Some(ItemId(2))), run(None)] };
        let encoded = encode(&list);
        assert_eq!(encoded.text_sources, vec![3, 0]);
        let back = score_testkit::display_from_json(&encoded.texts).unwrap();
        assert_eq!(back.texts.len(), 2);
        assert_eq!(back.texts[0].strings[0].origin, Point::new(10, 20));
    }
}
