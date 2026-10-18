//! SVG output for display lists.
//!
//! Engine coordinates are written unchanged except for the y flip. The page
//! is drawn as SCORE's PostScript print output draws it, which Smith
//! designed for paper, not as WinScore paints the screen: polylines and the
//! outlines of filled objects with the shape's pen, by default [`PEN`]
//! (1/150 inch, `wdl lw`), round joins (`1 setlinejoin`) and butt caps;
//! filled objects with the even-odd rule and outlined with the pen as well
//! (`gsave eofill grestore stroke`). Viewers draw the pen as thin as it is
//! on paper, under one CSS pixel at the SVG's natural size.
//!
//! Text strings start at their baseline origin. Each run names a font stack
//! that starts with the face the web app bundles for the engine's family,
//! under the app's name (`web/src/fonts.ts`; an `@font-face` the app embeds
//! in exported files, or its own style sheet, defines it), then the same
//! face, its URW original and the Windows and PostScript faces by their
//! installed names, and a generic family. The engine places every
//! character, so the face only changes glyph shapes. Unrotated characters
//! on one baseline share a `<text>` element with an x per character, so
//! viewers select and copy them as words.

use crate::display::{Colour, DisplayList, ItemId, PlacedText, Point, Shape, ShapeKind, TextRun, PEN, UNITS_PER_INCH};
use crate::page::Paper;

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct SvgOptions {
    pub view: Viewport,
    /// Width in engine units of the default pen: the pen of polylines and
    /// fill outlines whose own width is 0, and of outlined letters.
    pub stroke_width: f64,
}

impl SvgOptions {
    pub fn new(view: Viewport) -> Self {
        Self { view, stroke_width: f64::from(PEN) }
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
    let top = -(view.y + view.height);
    let pen = num(options.stroke_width);
    // xml:space keeps every character, so each takes the x given for it.
    let header = format!(
        "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"{} {top} {} {}\" width=\"{}in\" height=\"{}in\" \
         xml:space=\"preserve\">\n",
        view.x,
        view.width,
        view.height,
        inches(view.width),
        inches(view.height),
    );
    let background = format!(
        "<rect x=\"{}\" y=\"{top}\" width=\"{}\" height=\"{}\" fill=\"#ffffff\" stroke=\"none\"/>\n",
        view.x, view.width, view.height
    );
    // Shapes inherit black, the pen and its joins. Text is not stroked but
    // for outlined letters, which say so, and forms no ligatures: the
    // engine sets every character on its own.
    let shapes = format!(
        "<g fill=\"none\" fill-rule=\"evenodd\" stroke=\"{}\" stroke-width=\"{pen}\" stroke-linejoin=\"round\" \
         stroke-linecap=\"butt\">\n{}</g>\n",
        hex(Colour::BLACK),
        list.shapes.iter().map(shape).collect::<String>()
    );
    let texts = format!(
        "<g stroke=\"none\" style=\"font-variant-ligatures: none\">\n{}</g>\n",
        list.texts.iter().map(|run| text_run(run, &pen)).collect::<String>()
    );
    [header, background, shapes, texts, "</svg>\n".to_string()].concat()
}

/// `value` with at most `places` decimals and no trailing zeros.
fn fixed(value: f64, places: usize) -> String {
    let text = format!("{value:.places$}");
    let text = if text.contains('.') { text.trim_end_matches('0').trim_end_matches('.') } else { &text };
    if text == "-0" {
        "0".to_string()
    } else {
        text.to_string()
    }
}

/// A coordinate or width: a hundredth of an engine unit is plenty.
fn num(value: f64) -> String {
    fixed(value, 2)
}

fn hex(colour: Colour) -> String {
    format!("#{:02x}{:02x}{:02x}", colour.r, colour.g, colour.b)
}

fn source_attribute(source: Option<ItemId>) -> String {
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

/// A shape inside the shapes' group, which supplies the default pen and black.
fn shape(shape: &Shape) -> String {
    let source = source_attribute(shape.source);
    let stroke = match shape.colour {
        Colour::BLACK => String::new(),
        colour => format!(" stroke=\"{}\"", hex(colour)),
    };
    let width = match shape.width {
        w if w > 0.0 => format!(" stroke-width=\"{}\"", num(f64::from(w))),
        _ => String::new(),
    };
    match shape.kind {
        ShapeKind::Stroke => format!("<path d=\"{}\"{stroke}{width}{source}/>\n", path_data(&shape.paths, false)),
        ShapeKind::Fill => format!(
            "<path d=\"{}\" fill=\"{}\"{stroke}{width}{source}/>\n",
            path_data(&shape.paths, true),
            hex(shape.colour)
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

/// The engine's family name without the padding of the metric files.
fn family(font: &str) -> String {
    font.replace('\0', "").trim().to_string()
}

/// The font stack for an engine family, as a `font-family` value: the
/// bundled face of `web/src/fonts.ts` (FACES) by the app's name and by its
/// own, its URW base-35 original, the Windows face of the same or a similar
/// design and the PostScript one, then a generic family. The Adobe display
/// faces of fonts 35–71 have no free versions and get the stand-ins of
/// `web/fonts/README.md`; unknown names get Times, as in the engine.
fn font_stack(font: &str) -> &'static str {
    match family(font).as_str() {
        "Helvetica" | "AntiqueOlive" | "Antique Olive" | "GillSans" | "Lithos" | "Tekton" | "Blackoak" => {
            "'WS Heros', 'TeX Gyre Heros', 'Nimbus Sans', 'Arial', 'Helvetica', sans-serif"
        }
        "Helvetica-Narrow" => {
            "'WS Heros Cn', 'TeX Gyre Heros Cn', 'Nimbus Sans Narrow', 'Arial Narrow', 'Helvetica Narrow', sans-serif"
        }
        "Courier" => "'WS Cursor', 'TeX Gyre Cursor', 'Nimbus Mono PS', 'Courier New', 'Courier', monospace",
        "Palatino" => "'WS Pagella', 'TeX Gyre Pagella', 'P052', 'Palatino Linotype', 'Palatino', serif",
        "AvantGarde" => {
            "'WS Adventor', 'TeX Gyre Adventor', 'URW Gothic', 'Century Gothic', 'ITC Avant Garde Gothic', sans-serif"
        }
        "Bookman" => "'WS Bonum', 'TeX Gyre Bonum', 'URW Bookman', 'Bookman Old Style', 'ITC Bookman', serif",
        "NewCenturySchlbk" => {
            "'WS Schola', 'TeX Gyre Schola', 'C059', 'Century Schoolbook', 'New Century Schoolbook', serif"
        }
        "ZapfChancery" | "ParkAvenue" | "Park Avenue" | "Parisian" | "Kaufmann" | "Poetica" => {
            "'WS Chorus', 'TeX Gyre Chorus', 'Z003', 'Monotype Corsiva', 'ITC Zapf Chancery', cursive"
        }
        // These faces draw the byte codes of the engine's strings as
        // symbols (a is alpha); no generic family does.
        "Symbol" => "'WS Symbol', 'Standard Symbols PS', 'Symbol'",
        "ZapfDingbats" => "'WS Dingbats', 'D050000L', 'ITC Zapf Dingbats', 'Zapf Dingbats'",
        _ => "'WS Termes', 'TeX Gyre Termes', 'Nimbus Roman', 'Times New Roman', 'Times', serif",
    }
}

/// GDI's tmAscent for `font` in em, the depth of the baseline below the top
/// of the character cell that rotated text turns about: usWinAscent over
/// unitsPerEm of the Windows face GDI substitutes, Arial for Helvetica,
/// Courier New for Courier and Times New Roman for every other family. The
/// numbers are those of `ascent()` in `web/src/fonts.ts`; keep them in step.
fn ascent(font: &str) -> f64 {
    match family(font).as_str() {
        "Helvetica" => 1854.0 / 2048.0,
        "Courier" => 1705.0 / 2048.0,
        _ => 1825.0 / 2048.0,
    }
}

/// The run's header width over its height when P6 = P7: 32·0.825 / 64
/// (`style()` in `text/mod.rs`).
const WIDTH_PER_HEIGHT: f64 = 0.4125;

/// How much wider than its height SCORE sets a run's letters: 1 for
/// ordinary text, P6/P7 for text of a separate width.
fn horizontal_scale(run: &TextRun) -> f64 {
    if run.width <= 0.0 || run.height <= 0.0 {
        return 1.0;
    }
    let scale = f64::from(run.width) / (WIDTH_PER_HEIGHT * f64::from(run.height));
    // The header's REAL*4 rounding leaves ordinary text a hair off 1.
    if (scale - 1.0).abs() < 1e-4 {
        1.0
    } else {
        scale
    }
}

/// A run as a group with its font and paint, holding its strings' `<text>`
/// elements. Outlined letters are stroked with the default pen `pen`.
fn text_run(run: &TextRun, pen: &str) -> String {
    let body = strings(run);
    if body.is_empty() {
        return String::new();
    }
    let colour = hex(run.colour);
    let paint = if run.outline {
        format!("fill=\"none\" stroke=\"{colour}\" stroke-width=\"{pen}\" stroke-linejoin=\"round\"")
    } else {
        format!("fill=\"{colour}\"")
    };
    format!(
        "<g font-family=\"{}\" font-size=\"{}\"{}{} {paint}{}>\n{body}</g>\n",
        font_stack(&run.font),
        num(f64::from(run.height)),
        if run.weight != 400 { format!(" font-weight=\"{}\"", run.weight) } else { String::new() },
        if run.italic { " font-style=\"italic\"" } else { "" },
        source_attribute(run.source),
    )
}

/// The `<text>` elements of a run. An unrotated run's consecutive
/// one-character strings on one baseline share an element; rotated strings
/// each turn about their own cell, so they stand alone. Empty strings draw
/// nothing and are left out.
fn strings(run: &TextRun) -> String {
    let (scale, underline) = (horizontal_scale(run), run.underline);
    let text = |strings: &[&PlacedText], turn: Option<&str>| text(strings, scale, turn, underline);
    let shown = run.strings.iter().filter(|s| !s.text.is_empty());
    if run.escapement != 0 {
        // Clockwise, along the line the engine sets the characters on, about
        // the top-left corner of the cell as GDI turns text (paint.ts).
        let angle = f64::from(run.escapement) / 10.0;
        let drop = ascent(&run.font) * f64::from(run.height);
        return shown
            .map(|s| {
                let (x, y) = (s.origin.x, -s.origin.y);
                let turn = format!("rotate({} {x} {})", num(angle), num(f64::from(y) - drop));
                text(&[s], Some(&turn))
            })
            .collect();
    }
    let single = |t: &PlacedText| t.text.chars().count() == 1;
    let joins = |line: &[&PlacedText], s: &PlacedText| {
        single(s) && line.last().is_some_and(|l| single(l) && l.origin.y == s.origin.y)
    };
    let mut lines: Vec<Vec<&PlacedText>> = Vec::new();
    for s in shown {
        match lines.last_mut() {
            Some(line) if joins(line, s) => line.push(s),
            _ => lines.push(vec![s]),
        }
    }
    lines.iter().map(|line| text(line, None)).collect()
}

/// One `<text>` element for `strings` on one baseline, each character of a
/// one-character string at its own x, widened by `scale` about the first
/// origin and then transformed by `turn`. Underlines go on the element:
/// not every viewer carries them over from the run's group.
fn text(strings: &[&PlacedText], scale: f64, turn: Option<&str>, underline: bool) -> String {
    let first = strings[0].origin;
    let y = -first.y;
    let x = |at: Point| num(f64::from(first.x) + f64::from(at.x - first.x) / scale);
    let xs = strings.iter().map(|s| x(s.origin)).collect::<Vec<_>>().join(" ");
    let widen = (scale != 1.0)
        .then(|| format!("matrix({} 0 0 1 {} 0)", fixed(scale, 4), num(f64::from(first.x) * (1.0 - scale))));
    let transforms: Vec<String> = turn.map(str::to_string).into_iter().chain(widen).collect();
    let transform =
        if transforms.is_empty() { String::new() } else { format!(" transform=\"{}\"", transforms.join(" ")) };
    let decoration = if underline { " text-decoration=\"underline\"" } else { "" };
    let content: String = strings.iter().map(|s| escape(&s.text)).collect();
    format!("<text x=\"{xs}\" y=\"{y}\"{transform}{decoration}>{content}</text>\n")
}

#[cfg(test)]
mod tests {
    use super::*;

    fn stroke(width: f32) -> Shape {
        Shape {
            kind: ShapeKind::Stroke,
            colour: Colour::BLACK,
            paths: vec![vec![Point::new(10, 20), Point::new(30, 20)]],
            width,
            source: Some(ItemId(3)),
        }
    }

    fn run(font: &str, strings: &[(i32, i32, &str)]) -> TextRun {
        TextRun {
            font: font.to_string(),
            height: 697.32,
            width: 287.6445,
            escapement: 0,
            colour: Colour::BLACK,
            weight: 400,
            italic: false,
            underline: false,
            outline: false,
            strings: strings
                .iter()
                .map(|&(x, y, text)| PlacedText { origin: Point::new(x, y), text: text.to_string() })
                .collect(),
            source: Some(ItemId(7)),
        }
    }

    fn svg(list: &DisplayList) -> String {
        to_svg(list, &SvgOptions::new(Viewport::paper(Paper::LETTER)))
    }

    fn texts(runs: Vec<TextRun>) -> String {
        svg(&DisplayList { shapes: vec![], texts: runs })
    }

    #[test]
    fn flips_y_and_tags_items() {
        let svg = svg(&DisplayList { shapes: vec![stroke(0.0)], texts: vec![] });
        assert!(svg.contains("d=\"M10 -20L30 -20\""));
        assert!(svg.contains("data-item=\"3\""));
        assert!(svg.contains("viewBox=\"0 -44000 34000 44000\""));
    }

    #[test]
    fn shapes_take_scores_pen_with_round_joins() {
        let svg = svg(&DisplayList { shapes: vec![stroke(0.0), stroke(40.0)], texts: vec![] });
        assert!(
            svg.contains("<g fill=\"none\" fill-rule=\"evenodd\" stroke=\"#000000\" stroke-width=\"26.67\" stroke-linejoin=\"round\" stroke-linecap=\"butt\">"),
            "{svg}"
        );
        assert!(svg.contains("<path d=\"M10 -20L30 -20\" data-item=\"3\"/>"), "{svg}");
        assert!(svg.contains("<path d=\"M10 -20L30 -20\" stroke-width=\"40\" data-item=\"3\"/>"), "{svg}");
    }

    #[test]
    fn the_default_pen_can_be_set() {
        let list = DisplayList { shapes: vec![stroke(0.0)], texts: vec![] };
        let options = SvgOptions { stroke_width: 4.0, ..SvgOptions::new(Viewport::paper(Paper::LETTER)) };
        assert!(to_svg(&list, &options).contains(" stroke-width=\"4\" "));
    }

    #[test]
    fn fills_are_outlined_in_their_colour() {
        let red = Colour { r: 255, g: 0, b: 0 };
        let fill = |colour, width| Shape { kind: ShapeKind::Fill, colour, width, ..stroke(0.0) };
        let svg = svg(&DisplayList { shapes: vec![fill(Colour::BLACK, 0.0), fill(red, 13.5)], texts: vec![] });
        // The group's stroke outlines black fills with the default pen.
        assert!(svg.contains("<path d=\"M10 -20L30 -20Z\" fill=\"#000000\" data-item=\"3\"/>"), "{svg}");
        assert!(svg.contains("<path d=\"M10 -20L30 -20Z\" fill=\"#ff0000\" stroke=\"#ff0000\" stroke-width=\"13.5\" data-item=\"3\"/>"), "{svg}");
    }

    #[test]
    fn runs_name_the_bundled_face_and_its_fallbacks() {
        let svg = texts(vec![run("Times", &[(0, 0, "A")]), run("Symbol\0\0", &[(0, 0, "a")]), run("Americana", &[(0, 0, "A")])]);
        assert!(svg.contains("font-family=\"'WS Termes', 'TeX Gyre Termes', 'Nimbus Roman', 'Times New Roman', 'Times', serif\""));
        assert!(svg.contains("font-family=\"'WS Symbol', 'Standard Symbols PS', 'Symbol'\""));
        assert_eq!(svg.matches("'WS Termes'").count(), 2, "Americana's stand-in is Termes");
    }

    #[test]
    fn single_characters_on_a_baseline_share_a_text() {
        let svg = texts(vec![run("Times", &[(100, 50, "S"), (486, 50, "a"), (795, 50, "n"), (900, 50, ""), (1316, 50, "A"), (100, 0, "x"), (300, 0, "12"), (500, 0, "y")])]);
        assert!(svg.contains("<text x=\"100 486 795 1316\" y=\"-50\">SanA</text>"), "{svg}");
        assert!(svg.contains("<text x=\"100\" y=\"0\">x</text>"), "{svg}");
        assert!(svg.contains("<text x=\"300\" y=\"0\">12</text>"), "{svg}");
        assert!(svg.contains("<text x=\"500\" y=\"0\">y</text>"), "{svg}");
        assert!(svg.contains("xml:space=\"preserve\""));
    }

    #[test]
    fn rotated_letters_turn_clockwise_about_their_cell() {
        let mut turned = run("Times", &[(10187, 4334, "H"), (11153, 3776, "a")]);
        turned.escapement = 300;
        let svg = texts(vec![turned]);
        // The pivot is one Times New Roman ascent (1825/2048 em) above the baseline.
        let drop = 1825.0 / 2048.0 * 697.32;
        let pivot = num(-4334.0 - drop);
        assert!(svg.contains(&format!("<text x=\"10187\" y=\"-4334\" transform=\"rotate(30 10187 {pivot})\">H</text>")), "{svg}");
        assert!(svg.contains("<text x=\"11153\" y=\"-3776\" transform=\"rotate(30 11153 "), "{svg}");
    }

    #[test]
    fn letters_of_a_separate_width_are_scaled_about_their_origin() {
        let mut wide = run("Times", &[(1000, 0, "a"), (1400, 0, "b")]);
        wide.width *= 1.5;
        let svg = texts(vec![wide]);
        // b's origin, 1000 + 400 / 1.5 scaled by 1.5 about 1000, stays at 1400.
        assert!(svg.contains("<text x=\"1000 1266.67\" y=\"0\" transform=\"matrix(1.5 0 0 1 -500 0)\">ab</text>"), "{svg}");
        let plain = texts(vec![run("Times", &[(1000, 0, "a")])]);
        assert!(!plain.contains("transform"), "{plain}");
    }

    #[test]
    fn outlined_letters_are_stroked_with_the_pen() {
        let mut outline = run("Helvetica", &[(0, 0, "O")]);
        outline.outline = true;
        outline.weight = 700;
        let svg = texts(vec![outline]);
        assert!(svg.contains(" font-weight=\"700\" fill=\"none\" stroke=\"#000000\" stroke-width=\"26.67\" stroke-linejoin=\"round\" data-item=\"7\">"), "{svg}");
    }

    #[test]
    fn underlines_go_on_each_text() {
        let mut underlined = run("Times", &[(0, 0, "a"), (300, 0, "b"), (0, -900, "c")]);
        underlined.underline = true;
        let svg = texts(vec![underlined]);
        assert!(svg.contains("<text x=\"0 300\" y=\"0\" text-decoration=\"underline\">ab</text>"), "{svg}");
        assert!(svg.contains("<text x=\"0\" y=\"900\" text-decoration=\"underline\">c</text>"), "{svg}");
    }

    #[test]
    fn text_escapes_markup() {
        let svg = texts(vec![run("Times", &[(0, 0, "<"), (10, 0, "&")])]);
        assert!(svg.contains(">&lt;&amp;</text>"), "{svg}");
    }
}
