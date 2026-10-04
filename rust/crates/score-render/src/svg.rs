//! SVG output for display lists.
//!
//! Engine coordinates are written unchanged except for the y flip. Filled
//! objects use the even-odd rule like GDI's ALTERNATE mode. Polylines stand
//! for GDI's one-pixel pen: by default they are one CSS pixel (1/96 inch)
//! wide at the SVG's natural size, which rasterisers without support for
//! `vector-effect` also draw. Text placement is approximate: the engine
//! positions the top-left of the character cell and the baseline below it
//! depends on the font's metrics.

use crate::display::{Colour, DisplayList, Point, Shape, ShapeKind, TextRun, UNITS_PER_INCH};
use crate::page::Paper;

/// Distance from the top of the character cell to the baseline, as a fraction of the height.
const ASCENT: f32 = 0.9;

/// One CSS pixel in engine units.
pub const PIXEL: f64 = UNITS_PER_INCH as f64 / 96.0;

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct SvgOptions {
    pub view: Viewport,
    /// Width of polylines in engine units.
    pub stroke_width: f64,
}

impl SvgOptions {
    pub fn new(view: Viewport) -> Self {
        Self { view, stroke_width: PIXEL }
    }
}

/// The page area an SVG shows, in engine units (y up).
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Viewport {
    pub x: i32,
    pub y: i32,
    pub width: i32,
    pub height: i32,
}

impl Viewport {
    pub fn paper(paper: Paper) -> Self {
        Self { x: 0, y: 0, width: paper.width.round() as i32, height: paper.height.round() as i32 }
    }

    /// The bounding box of all shapes and text origins, grown by `margin`.
    pub fn around(list: &DisplayList, margin: i32) -> Option<Self> {
        let shape_points = list.shapes.iter().flat_map(|s| s.paths.iter().flatten().copied());
        let text_points = list.texts.iter().flat_map(|t| t.strings.iter().map(|s| s.origin));
        let points: Vec<Point> = shape_points.chain(text_points).collect();
        let min_x = points.iter().map(|p| p.x).min()?;
        let max_x = points.iter().map(|p| p.x).max()?;
        let min_y = points.iter().map(|p| p.y).min()?;
        let max_y = points.iter().map(|p| p.y).max()?;
        Some(Self {
            x: min_x - margin,
            y: min_y - margin,
            width: max_x - min_x + 2 * margin,
            height: max_y - min_y + 2 * margin,
        })
    }
}

pub fn to_svg(list: &DisplayList, options: &SvgOptions) -> String {
    let view = &options.view;
    let inches = |units: i32| f64::from(units) / f64::from(UNITS_PER_INCH);
    let header = format!(
        "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"{} {} {} {}\" width=\"{}in\" height=\"{}in\">\n",
        view.x,
        -(view.y + view.height),
        view.width,
        view.height,
        inches(view.width),
        inches(view.height),
    );
    let background = format!(
        "<rect x=\"{}\" y=\"{}\" width=\"{}\" height=\"{}\" fill=\"#ffffff\"/>\n",
        view.x,
        -(view.y + view.height),
        view.width,
        view.height
    );
    let shapes: String = list.shapes.iter().map(|s| shape(s, options.stroke_width)).collect();
    let texts: String = list.texts.iter().map(text_run).collect();
    [header, background, shapes, texts, "</svg>\n".to_string()].concat()
}

fn hex(colour: Colour) -> String {
    format!("#{:02x}{:02x}{:02x}", colour.r, colour.g, colour.b)
}

fn source_attribute(source: Option<crate::display::ItemId>) -> String {
    source.map_or_else(String::new, |id| format!(" data-item=\"{}\"", id.0))
}

fn path_data(paths: &[Vec<Point>], close: bool) -> String {
    let path = |points: &Vec<Point>| -> String {
        let moves = points
            .iter()
            .enumerate()
            .map(|(i, p)| format!("{}{} {}", if i == 0 { 'M' } else { 'L' }, p.x, -p.y))
            .collect::<String>();
        if close {
            moves + "Z"
        } else {
            moves
        }
    };
    paths.iter().map(path).collect()
}

fn shape(shape: &Shape, stroke_width: f64) -> String {
    let source = source_attribute(shape.source);
    let colour = hex(shape.colour);
    match shape.kind {
        ShapeKind::Stroke => format!(
            "<path d=\"{}\" fill=\"none\" stroke=\"{colour}\" stroke-width=\"{stroke_width:.1}\"{source}/>\n",
            path_data(&shape.paths, false)
        ),
        ShapeKind::Fill => format!(
            "<path d=\"{}\" fill=\"{colour}\" fill-rule=\"evenodd\"{source}/>\n",
            path_data(&shape.paths, true)
        ),
    }
}

fn escape(text: &str) -> String {
    text.chars()
        .map(|c| match c {
            '&' => "&amp;".to_string(),
            '<' => "&lt;".to_string(),
            '>' => "&gt;".to_string(),
            '"' => "&quot;".to_string(),
            c => c.to_string(),
        })
        .collect()
}

fn text_run(run: &TextRun) -> String {
    let source = source_attribute(run.source);
    let style = format!(
        "font-family=\"{}, sans-serif\" font-size=\"{:.1}\" fill=\"{}\"{}{}{}",
        escape(&run.font),
        run.height,
        hex(run.colour),
        if run.italic { " font-style=\"italic\"" } else { "" },
        if run.weight >= 600 { " font-weight=\"bold\"" } else { "" },
        if run.underline { " text-decoration=\"underline\"" } else { "" },
    );
    let baseline_drop = ASCENT * run.height;
    run.strings
        .iter()
        .map(|s| {
            let (x, y) = (s.origin.x, -s.origin.y);
            let rotate = match run.escapement {
                0 => String::new(),
                e => format!(" transform=\"rotate({} {x} {y})\"", -f64::from(e) / 10.0),
            };
            format!(
                "<text x=\"{x}\" y=\"{:.0}\" {style}{rotate}{source}>{}</text>\n",
                y as f32 + baseline_drop,
                escape(&s.text)
            )
        })
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::display::ItemId;

    #[test]
    fn flips_y_and_tags_items() {
        let list = DisplayList {
            shapes: vec![Shape {
                kind: ShapeKind::Stroke,
                colour: Colour::BLACK,
                paths: vec![vec![Point::new(10, 20), Point::new(30, 20)]],
                source: Some(ItemId(3)),
            }],
            texts: vec![],
        };
        let svg = to_svg(&list, &SvgOptions::new(Viewport::paper(Paper::LETTER)));
        assert!(svg.contains("d=\"M10 -20L30 -20\""));
        assert!(svg.contains("data-item=\"3\""));
        assert!(svg.contains("viewBox=\"0 -44000 34000 44000\""));
    }
}
