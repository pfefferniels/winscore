//! The `engine.json` format (see `rust/fixtures/README.md`) and its mapping to
//! [`DisplayList`].
//!
//! Fields are declared in alphabetical order so that serialisation matches the
//! sorted keys `oracle/fixtures.py` writes.

use score_render::{Colour, DisplayList, ItemId, PlacedText, Point, Shape, ShapeKind, TextRun};
use serde::{Deserialize, Serialize};

#[derive(Debug, Clone, Copy, PartialEq, Eq, Serialize, Deserialize)]
#[serde(rename_all = "lowercase")]
enum KindJson {
    Stroke,
    Fill,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
struct ShapeJson {
    colour: [u8; 3],
    #[serde(default, skip_serializing_if = "Option::is_none")]
    item: Option<u32>,
    kind: KindJson,
    paths: Vec<Vec<[i32; 2]>>,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    raw_kind: Option<u8>,
    /// The pen width of a refined rendering; absent in engine output.
    #[serde(default, skip_serializing_if = "is_zero")]
    width: f32,
}

fn is_zero(width: &f32) -> bool {
    *width == 0.0
}

#[derive(Debug, Clone, Serialize, Deserialize)]
struct StringJson {
    text: String,
    x: i32,
    y: i32,
}

#[derive(Debug, Clone, Serialize, Deserialize)]
struct TextJson {
    colour: [u8; 3],
    escapement: i32,
    font: String,
    height: f32,
    italic: bool,
    #[serde(default, skip_serializing_if = "Option::is_none")]
    item: Option<u32>,
    /// Outlined letters of a refined rendering; absent in engine output.
    #[serde(default, skip_serializing_if = "std::ops::Not::not")]
    outline: bool,
    strings: Vec<StringJson>,
    underline: bool,
    weight: i32,
    width: f32,
}

#[derive(Debug, Clone, Default, Serialize, Deserialize)]
struct DisplayJson {
    shapes: Vec<ShapeJson>,
    texts: Vec<TextJson>,
}

fn colour_of(rgb: [u8; 3]) -> Colour {
    Colour {
        r: rgb[0],
        g: rgb[1],
        b: rgb[2],
    }
}

fn rgb_of(colour: Colour) -> [u8; 3] {
    [colour.r, colour.g, colour.b]
}

impl From<ShapeJson> for Shape {
    fn from(s: ShapeJson) -> Self {
        Shape {
            kind: match s.kind {
                KindJson::Stroke => ShapeKind::Stroke,
                KindJson::Fill => ShapeKind::Fill,
            },
            colour: colour_of(s.colour),
            paths: s
                .paths
                .into_iter()
                .map(|path| path.into_iter().map(|[x, y]| Point::new(x, y)).collect())
                .collect(),
            width: s.width,
            source: s.item.map(ItemId),
        }
    }
}

impl From<&Shape> for ShapeJson {
    fn from(s: &Shape) -> Self {
        ShapeJson {
            colour: rgb_of(s.colour),
            item: s.source.map(|ItemId(i)| i),
            kind: match s.kind {
                ShapeKind::Stroke => KindJson::Stroke,
                ShapeKind::Fill => KindJson::Fill,
            },
            paths: s
                .paths
                .iter()
                .map(|path| path.iter().map(|p| [p.x, p.y]).collect())
                .collect(),
            raw_kind: None,
            width: s.width,
        }
    }
}

impl From<TextJson> for TextRun {
    fn from(t: TextJson) -> Self {
        TextRun {
            font: t.font,
            height: t.height,
            width: t.width,
            escapement: t.escapement,
            colour: colour_of(t.colour),
            weight: t.weight,
            italic: t.italic,
            underline: t.underline,
            outline: t.outline,
            strings: t
                .strings
                .into_iter()
                .map(|s| PlacedText {
                    origin: Point::new(s.x, s.y),
                    text: s.text,
                })
                .collect(),
            source: t.item.map(ItemId),
        }
    }
}

impl From<&TextRun> for TextJson {
    fn from(t: &TextRun) -> Self {
        TextJson {
            colour: rgb_of(t.colour),
            escapement: t.escapement,
            font: t.font.clone(),
            height: t.height,
            italic: t.italic,
            item: t.source.map(|ItemId(i)| i),
            outline: t.outline,
            strings: t
                .strings
                .iter()
                .map(|s| StringJson {
                    text: s.text.clone(),
                    x: s.origin.x,
                    y: s.origin.y,
                })
                .collect(),
            underline: t.underline,
            weight: t.weight,
            width: t.width,
        }
    }
}

/// Reads an `engine.json` document.
pub fn display_from_json(text: &str) -> serde_json::Result<DisplayList> {
    let doc: DisplayJson = serde_json::from_str(text)?;
    Ok(DisplayList {
        shapes: doc.shapes.into_iter().map(Shape::from).collect(),
        texts: doc.texts.into_iter().map(TextRun::from).collect(),
    })
}

/// Writes a display list in the `engine.json` layout: one element per line.
pub fn display_to_json(list: &DisplayList) -> String {
    fn section<T: Serialize>(name: &str, items: &[T]) -> String {
        let lines: Vec<String> = items
            .iter()
            .map(|item| serde_json::to_string(item).expect("display elements serialise"))
            .collect();
        if lines.is_empty() {
            format!("\"{name}\":[]")
        } else {
            format!("\"{name}\":[\n{}\n]", lines.join(",\n"))
        }
    }
    let shapes: Vec<ShapeJson> = list.shapes.iter().map(ShapeJson::from).collect();
    let texts: Vec<TextJson> = list.texts.iter().map(TextJson::from).collect();
    format!(
        "{{{},\n{}}}\n",
        section("shapes", &shapes),
        section("texts", &texts)
    )
}

#[cfg(test)]
mod tests {
    use super::*;

    const SAMPLE: &str = r#"{"shapes":[
{"colour":[0,0,0],"item":0,"kind":"stroke","paths":[[[2000,2948],[32000,2948]]]},
{"colour":[0,0,253],"kind":"fill","paths":[[[1,2],[3,4],[1,2]],[[5,6],[7,8],[5,6]]]}
],
"texts":[
{"colour":[0,115,51],"escapement":0,"font":"Helvetica-Narrow","height":774.8,"italic":false,"item":0,"strings":[{"text":"1","x":800,"y":3469}],"underline":false,"weight":400,"width":319.605}
]}
"#;

    #[test]
    fn reads_shapes_and_texts() {
        let list = display_from_json(SAMPLE).unwrap();
        assert_eq!(list.shapes.len(), 2);
        assert_eq!(list.shapes[0].kind, ShapeKind::Stroke);
        assert_eq!(list.shapes[0].source, Some(ItemId(0)));
        assert_eq!(list.shapes[1].source, None);
        assert_eq!(list.texts[0].source, Some(ItemId(0)));
        assert_eq!(list.shapes[1].colour, Colour { r: 0, g: 0, b: 253 });
        assert_eq!(list.shapes[1].paths[1][2], Point::new(5, 6));
        assert_eq!(list.texts[0].strings[0].origin, Point::new(800, 3469));
        assert_eq!(list.texts[0].height, 774.8);
    }

    #[test]
    fn writes_what_it_reads() {
        let list = display_from_json(SAMPLE).unwrap();
        assert_eq!(display_to_json(&list), SAMPLE);
    }
}
