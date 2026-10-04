//! The JSON form of a display list, as `verifier` writes it to
//! `rust/fixtures/<case>/engine.json`: page coordinates in engine units
//! (origin at the paper's bottom-left corner, y up), text origins at the
//! top-left of the character cell (the engine's y + 96 folded in).
//!
//! Text runs leave the wasm API in the same form, with the source item added.

use score_render::{Colour, DisplayList, ItemId, PlacedText, Point, Shape, ShapeKind, TextRun};
use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "lowercase")]
enum Kind {
    Stroke,
    Fill,
}

#[derive(Debug, Clone, PartialEq, Serialize, Deserialize)]
struct ShapeJson {
    colour: [u8; 3],
    kind: Kind,
    paths: Vec<Vec<[i32; 2]>>,
}

#[derive(Debug, Clone, PartialEq, Serialize, Deserialize)]
struct StringJson {
    text: String,
    x: i32,
    y: i32,
}

#[derive(Debug, Clone, PartialEq, Serialize, Deserialize)]
pub struct TextRunJson {
    colour: [u8; 3],
    escapement: i32,
    font: String,
    height: f32,
    italic: bool,
    strings: Vec<StringJson>,
    underline: bool,
    weight: i32,
    width: f32,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    source: Option<u32>,
}

#[derive(Debug, Clone, PartialEq, Serialize, Deserialize)]
struct DisplayListJson {
    shapes: Vec<ShapeJson>,
    texts: Vec<TextRunJson>,
}

fn rgb(colour: Colour) -> [u8; 3] {
    [colour.r, colour.g, colour.b]
}

fn colour([r, g, b]: [u8; 3]) -> Colour {
    Colour { r, g, b }
}

impl From<ShapeJson> for Shape {
    fn from(shape: ShapeJson) -> Self {
        let kind = match shape.kind {
            Kind::Stroke => ShapeKind::Stroke,
            Kind::Fill => ShapeKind::Fill,
        };
        let paths = shape
            .paths
            .into_iter()
            .map(|path| path.into_iter().map(|[x, y]| Point::new(x, y)).collect())
            .collect();
        Shape { kind, colour: colour(shape.colour), paths, source: None }
    }
}

impl From<TextRunJson> for TextRun {
    fn from(run: TextRunJson) -> Self {
        let strings = run
            .strings
            .into_iter()
            .map(|s| PlacedText { origin: Point::new(s.x, s.y), text: s.text })
            .collect();
        TextRun {
            font: run.font,
            height: run.height,
            width: run.width,
            escapement: run.escapement,
            colour: colour(run.colour),
            weight: run.weight,
            italic: run.italic,
            underline: run.underline,
            strings,
            source: run.source.map(ItemId),
        }
    }
}

impl From<&TextRun> for TextRunJson {
    fn from(run: &TextRun) -> Self {
        let strings = run
            .strings
            .iter()
            .map(|s| StringJson { text: s.text.clone(), x: s.origin.x, y: s.origin.y })
            .collect();
        TextRunJson {
            colour: rgb(run.colour),
            escapement: run.escapement,
            font: run.font.clone(),
            height: run.height,
            italic: run.italic,
            strings,
            underline: run.underline,
            weight: run.weight,
            width: run.width,
            source: run.source.map(|id| id.0),
        }
    }
}

/// Reads an `engine.json` display list. Its elements carry no source items.
pub fn parse_display_list(json: &str) -> Result<DisplayList, serde_json::Error> {
    let list: DisplayListJson = serde_json::from_str(json)?;
    Ok(DisplayList {
        shapes: list.shapes.into_iter().map(Shape::from).collect(),
        texts: list.texts.into_iter().map(TextRun::from).collect(),
    })
}

/// The text runs of a display list as a JSON array.
pub fn texts_to_json(texts: &[TextRun]) -> String {
    let runs: Vec<TextRunJson> = texts.iter().map(TextRunJson::from).collect();
    serde_json::to_string(&runs).expect("text runs always serialise")
}

#[cfg(test)]
mod tests {
    use super::*;

    const SAMPLE: &str = r#"{"shapes":[{"colour":[0,0,0],"kind":"fill","paths":[[[0,0],[10,0],[10,10]],[[2,2],[3,2],[3,3]]]},
        {"colour":[255,0,0],"kind":"stroke","paths":[[[5,5],[6,7]]]}],
        "texts":[{"colour":[0,115,51],"escapement":0,"font":"Helvetica-Narrow","height":774.8,"italic":false,
        "strings":[{"text":"1","x":800,"y":3100}],"underline":false,"weight":400,"width":159.8}]}"#;

    #[test]
    fn reads_engine_json() {
        let list = parse_display_list(SAMPLE).unwrap();
        assert_eq!(list.shapes.len(), 2);
        assert_eq!(list.shapes[0].kind, ShapeKind::Fill);
        assert_eq!(list.shapes[0].paths[1][2], Point::new(3, 3));
        assert_eq!(list.shapes[1].colour, Colour { r: 255, g: 0, b: 0 });
        let run = &list.texts[0];
        assert_eq!(run.font, "Helvetica-Narrow");
        assert_eq!(run.strings[0].origin, Point::new(800, 3100));
        assert_eq!(run.source, None);
    }

    #[test]
    fn text_runs_round_trip() {
        let list = parse_display_list(SAMPLE).unwrap();
        let mut run = list.texts[0].clone();
        run.source = Some(ItemId(7));
        let json = texts_to_json(std::slice::from_ref(&run));
        let back: Vec<TextRunJson> = serde_json::from_str(&json).unwrap();
        assert_eq!(TextRun::from(back[0].clone()), run);
    }
}
