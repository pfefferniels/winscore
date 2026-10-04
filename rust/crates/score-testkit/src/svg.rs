//! Side-by-side pictures: engine | renderer | overlay of the differences.
//!
//! Glyph shapes of text are only approximate (generic font families); the
//! positions are exact.

use std::collections::HashSet;
use std::fmt::Write;

use score_render::{Colour, DisplayList, Point, Shape, ShapeKind, TextRun};

use crate::compare::{placed_strings, CompareOptions, Placed, Report, Unmatched};

const MATCHED: &str = "#9ca3af";
const ENGINE_ONLY: &str = "#2563eb";
const ACTUAL_ONLY: &str = "#dc2626";
const MIN_EXTENT: i32 = 2400;

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
struct Bounds {
    x0: i32,
    y0: i32,
    x1: i32,
    y1: i32,
}

impl Bounds {
    fn of(points: impl Iterator<Item = Point>) -> Option<Bounds> {
        points.fold(None, |acc: Option<Bounds>, p| {
            Some(acc.map_or(
                Bounds {
                    x0: p.x,
                    y0: p.y,
                    x1: p.x,
                    y1: p.y,
                },
                |b| Bounds {
                    x0: b.x0.min(p.x),
                    y0: b.y0.min(p.y),
                    x1: b.x1.max(p.x),
                    y1: b.y1.max(p.y),
                },
            ))
        })
    }

    /// Padded by a tenth and widened to a legible minimum around the centre.
    fn framed(self) -> Bounds {
        let grow = |lo: i32, hi: i32| {
            let pad = (hi - lo) / 10 + 100;
            let (lo, hi) = (lo - pad, hi + pad);
            let short = (MIN_EXTENT - (hi - lo)).max(0);
            (lo - short / 2, hi + short - short / 2)
        };
        let (x0, x1) = grow(self.x0, self.x1);
        let (y0, y1) = grow(self.y0, self.y1);
        Bounds { x0, y0, x1, y1 }
    }

    fn width(&self) -> i32 {
        self.x1 - self.x0
    }

    fn height(&self) -> i32 {
        self.y1 - self.y0
    }
}

fn list_points(list: &DisplayList) -> Vec<Point> {
    let shape_points = list
        .shapes
        .iter()
        .flat_map(|s| s.paths.iter().flatten().copied());
    let text_points = placed_strings(list, &CompareOptions::default())
        .iter()
        .flat_map(string_points)
        .collect::<Vec<_>>();
    shape_points.chain(text_points).collect()
}

fn string_points(placed: &Placed) -> [Point; 2] {
    let height = placed.run.height;
    let advance = (placed.string.text.chars().count() as f32 * height * 0.5) as i32;
    let origin = placed.string.origin;
    [
        origin,
        Point::new(origin.x + advance, origin.y - height as i32),
    ]
}

/// The points of every element the report lists as missing or extra.
fn differing_points(
    expected: &DisplayList,
    actual: Option<&DisplayList>,
    report: &Report,
    options: &CompareOptions,
) -> Vec<Point> {
    let shape_points = |list: &DisplayList, unmatched: &[Unmatched]| -> Vec<Point> {
        unmatched
            .iter()
            .flat_map(|m| list.shapes[m.index].paths.iter().flatten().copied())
            .collect()
    };
    let text_points = |list: &DisplayList, unmatched: &[Unmatched]| -> Vec<Point> {
        let placed = placed_strings(list, options);
        unmatched
            .iter()
            .flat_map(|m| string_points(&placed[m.index]))
            .collect()
    };
    let mut points = shape_points(expected, &report.shapes.missing);
    points.extend(text_points(expected, &report.texts.missing));
    if let Some(actual) = actual {
        points.extend(shape_points(actual, &report.shapes.extra));
        points.extend(text_points(actual, &report.texts.extra));
    }
    points
}

/// Maps engine coordinates (y up) into one panel of the picture (y down).
#[derive(Debug, Clone, Copy)]
struct Panel {
    left: i32,
    top: i32,
    bounds: Bounds,
}

impl Panel {
    fn x(&self, x: i32) -> i32 {
        self.left + x - self.bounds.x0
    }

    fn y(&self, y: i32) -> i32 {
        self.top + self.bounds.y1 - y
    }
}

fn hex(colour: Colour) -> String {
    format!("#{:02x}{:02x}{:02x}", colour.r, colour.g, colour.b)
}

fn path_data(panel: &Panel, shape: &Shape) -> String {
    let close = shape.kind == ShapeKind::Fill;
    shape
        .paths
        .iter()
        .filter(|path| !path.is_empty())
        .map(|path| {
            let points: Vec<String> = path
                .iter()
                .map(|p| format!("{} {}", panel.x(p.x), panel.y(p.y)))
                .collect();
            format!("M{}{}", points.join("L"), if close { "Z" } else { "" })
        })
        .collect()
}

fn shape_element(out: &mut String, panel: &Panel, shape: &Shape, colour: &str, stroke_width: f32) {
    let d = path_data(panel, shape);
    let _ = match shape.kind {
        ShapeKind::Stroke => {
            writeln!(
                out,
                r#"<path d="{d}" fill="none" stroke="{colour}" stroke-width="{stroke_width:.1}"/>"#
            )
        }
        ShapeKind::Fill => writeln!(
            out,
            r#"<path d="{d}" fill="{colour}" fill-rule="evenodd"/>"#
        ),
    };
}

fn font_family(font: &str) -> &'static str {
    match font {
        f if f.starts_with("Helvetica-Narrow") => {
            "Arial Narrow, Helvetica Neue, Helvetica, Arial, sans-serif"
        }
        f if f.starts_with("Helvetica") || f.starts_with("AvantGarde") => {
            "Helvetica, Arial, sans-serif"
        }
        f if f.starts_with("Courier") => "Courier New, Courier, monospace",
        f if f.starts_with("ZapfChancery") => "Apple Chancery, URW Chancery L, cursive",
        _ => "Times New Roman, Times, serif",
    }
}

fn escape(text: &str) -> String {
    text.replace('&', "&amp;")
        .replace('<', "&lt;")
        .replace('>', "&gt;")
}

/// Strings are placed by the top-left of their cell; the baseline sits about 0.9 em lower.
fn text_element(
    out: &mut String,
    panel: &Panel,
    run: &TextRun,
    origin: Point,
    text: &str,
    colour: &str,
) {
    let baseline = origin.y - (0.9 * run.height) as i32;
    let style = format!(
        r#"font-family="{}" font-size="{:.0}"{}{}"#,
        font_family(&run.font),
        run.height,
        if run.italic {
            r#" font-style="italic""#
        } else {
            ""
        },
        if run.weight >= 600 {
            r#" font-weight="bold""#
        } else {
            ""
        },
    );
    let rotate = if run.escapement != 0 {
        format!(
            r#" transform="rotate({:.1} {} {})""#,
            -(run.escapement as f32) / 10.0,
            panel.x(origin.x),
            panel.y(origin.y)
        )
    } else {
        String::new()
    };
    let _ = writeln!(
        out,
        r#"<text x="{}" y="{}" {style} fill="{colour}"{rotate}>{}</text>"#,
        panel.x(origin.x),
        panel.y(baseline),
        escape(text)
    );
}

fn draw_list(out: &mut String, panel: &Panel, list: &DisplayList, stroke_width: f32) {
    list.shapes
        .iter()
        .for_each(|s| shape_element(out, panel, s, &hex(s.colour), stroke_width));
    list.texts.iter().for_each(|run| {
        run.strings
            .iter()
            .for_each(|s| text_element(out, panel, run, s.origin, &s.text, &hex(run.colour)))
    });
}

/// The overlay: matched elements grey, engine-only blue, renderer-only red.
fn draw_overlay(
    out: &mut String,
    panel: &Panel,
    expected: &DisplayList,
    actual: Option<&DisplayList>,
    report: Option<&Report>,
    options: &CompareOptions,
    stroke_width: f32,
) {
    let missing_shapes: HashSet<usize> = report.map_or_else(
        || (0..expected.shapes.len()).collect(),
        |r| r.shapes.missing.iter().map(|m| m.index).collect(),
    );
    let missing_texts: HashSet<usize> = report.map_or_else(
        || (0..placed_strings(expected, options).len()).collect(),
        |r| r.texts.missing.iter().map(|m| m.index).collect(),
    );
    let draw_texts = |out: &mut String,
                      placed: &[Placed],
                      highlighted: &HashSet<usize>,
                      colour: &str,
                      all: bool| {
        placed
            .iter()
            .enumerate()
            .filter(|(i, _)| all || highlighted.contains(i))
            .for_each(|(i, p)| {
                let c = if highlighted.contains(&i) {
                    colour
                } else {
                    MATCHED
                };
                text_element(out, panel, p.run, p.string.origin, &p.string.text, c)
            });
    };
    expected.shapes.iter().enumerate().for_each(|(i, s)| {
        let colour = if missing_shapes.contains(&i) {
            ENGINE_ONLY
        } else {
            MATCHED
        };
        shape_element(out, panel, s, colour, stroke_width)
    });
    draw_texts(
        out,
        &placed_strings(expected, options),
        &missing_texts,
        ENGINE_ONLY,
        true,
    );
    if let (Some(actual), Some(report)) = (actual, report) {
        let extra_shapes: HashSet<usize> = report.shapes.extra.iter().map(|m| m.index).collect();
        let extra_texts: HashSet<usize> = report.texts.extra.iter().map(|m| m.index).collect();
        actual
            .shapes
            .iter()
            .enumerate()
            .filter(|(i, _)| extra_shapes.contains(i))
            .for_each(|(_, s)| shape_element(out, panel, s, ACTUAL_ONLY, stroke_width));
        draw_texts(
            out,
            &placed_strings(actual, options),
            &extra_texts,
            ACTUAL_ONLY,
            false,
        );
    }
}

/// What a picture shows besides the two lists.
#[derive(Debug, Clone, Copy)]
pub struct Caption<'a> {
    pub case: &'a str,
    pub description: &'a str,
    pub actual_label: &'a str,
}

/// An SVG of three panels; `pixel_width` is the width it will be rasterised at,
/// so that one-unit strokes stay visible.
pub fn triptych(
    caption: &Caption,
    expected: &DisplayList,
    actual: Option<&DisplayList>,
    report: Option<&Report>,
    options: &CompareOptions,
    pixel_width: u32,
) -> String {
    let differing = report
        .map(|r| differing_points(expected, actual, r, options))
        .unwrap_or_default();
    let zoomed = !differing.is_empty();
    let points = if zoomed {
        differing
    } else {
        list_points(expected)
            .into_iter()
            .chain(actual.map(list_points).unwrap_or_default())
            .collect()
    };
    let bounds = Bounds::of(points.into_iter())
        .unwrap_or(Bounds {
            x0: 0,
            y0: 0,
            x1: MIN_EXTENT,
            y1: MIN_EXTENT,
        })
        .framed();
    let gap = bounds.width() / 20;
    let total_width = 3 * bounds.width() + 2 * gap;
    let header = total_width / 14;
    let total_height = bounds.height() + header;
    let unit = total_width as f32 / pixel_width as f32;
    let stroke_width = (1.2 * unit).max(1.0);
    let panels: Vec<Panel> = (0..3)
        .map(|i| Panel {
            left: i * (bounds.width() + gap),
            top: header,
            bounds,
        })
        .collect();

    let mut out = String::new();
    let _ = writeln!(
        out,
        r#"<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 {total_width} {total_height}" width="{pixel_width}" height="{}">"#,
        (pixel_width as f32 * total_height as f32 / total_width as f32).round()
    );
    let _ = writeln!(
        out,
        r##"<rect x="0" y="0" width="{total_width}" height="{total_height}" fill="#ffffff"/>"##
    );
    let label_size = header as f32 / 3.6;
    let summary = report.map_or(String::from("no renderer output"), |r| {
        format!(
            "shapes {}/{}, texts {}/{}, max deviation {}",
            r.shapes.matched,
            r.shapes.expected,
            r.texts.matched,
            r.texts.expected,
            r.max_deviation()
        )
    });
    let _ = writeln!(
        out,
        r##"<text x="0" y="{:.0}" font-family="Helvetica, Arial, sans-serif" font-size="{label_size:.0}" fill="#111827">{} – {}</text>"##,
        label_size,
        escape(caption.case),
        escape(caption.description)
    );
    let zoom_note = if zoomed { " (zoomed)" } else { "" };
    let titles = [
        "engine".to_string(),
        caption.actual_label.to_string(),
        format!("diff: {summary}{zoom_note}"),
    ];
    panels.iter().zip(&titles).for_each(|(panel, title)| {
        let _ = writeln!(
            out,
            r##"<text x="{}" y="{:.0}" font-family="Helvetica, Arial, sans-serif" font-size="{:.0}" fill="#4b5563">{}</text>"##,
            panel.left,
            2.6 * label_size,
            label_size * 0.75,
            escape(title)
        );
        let _ = writeln!(
            out,
            r##"<rect x="{}" y="{}" width="{}" height="{}" fill="none" stroke="#e5e7eb" stroke-width="{stroke_width:.1}"/>"##,
            panel.left,
            panel.top,
            bounds.width(),
            bounds.height()
        );
    });
    let clipped = |out: &mut String, i: usize, draw: &dyn Fn(&mut String, &Panel)| {
        let panel = &panels[i];
        let _ = writeln!(
            out,
            r#"<clipPath id="panel{i}"><rect x="{}" y="{}" width="{}" height="{}"/></clipPath><g clip-path="url(#panel{i})">"#,
            panel.left,
            panel.top,
            bounds.width(),
            bounds.height()
        );
        draw(out, panel);
        out.push_str("</g>\n");
    };
    clipped(&mut out, 0, &|out, panel| {
        draw_list(out, panel, expected, stroke_width)
    });
    if let Some(actual) = actual {
        clipped(&mut out, 1, &|out, panel| {
            draw_list(out, panel, actual, stroke_width)
        });
    }
    clipped(&mut out, 2, &|out, panel| {
        draw_overlay(out, panel, expected, actual, report, options, stroke_width)
    });
    out.push_str("</svg>\n");
    out
}
