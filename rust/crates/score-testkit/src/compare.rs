//! Order-independent comparison of two display lists.
//!
//! Shapes match when kind, colour and the point count of every sub-path agree
//! and every coordinate lies within the tolerance. Text is compared per placed
//! string, so a renderer may group strings into runs differently from the
//! engine.

use std::collections::HashMap;
use std::fmt;

use score_render::{Colour, DisplayList, ItemId, PlacedText, Point, Shape, ShapeKind, TextRun};

/// Colour of the staff numbers WinScore shows at the left edge (screen aid).
pub const STAFF_NUMBER_COLOUR: Colour = Colour {
    r: 0,
    g: 0x73,
    b: 0x33,
};

pub fn is_staff_number(run: &TextRun) -> bool {
    run.font == "Helvetica-Narrow" && run.colour == STAFF_NUMBER_COLOUR
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct CompareOptions {
    /// Largest accepted difference per coordinate (and per text height and width), in engine units.
    pub tolerance: i32,
    /// Accept a closed path whose start point is rotated.
    pub rotate_closed_paths: bool,
    /// Leave staff-number texts out on both sides.
    pub ignore_staff_numbers: bool,
}

impl Default for CompareOptions {
    fn default() -> Self {
        Self {
            tolerance: 1,
            rotate_closed_paths: true,
            ignore_staff_numbers: false,
        }
    }
}

/// The closest element of the other list that has the same structure.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Nearest {
    pub index: usize,
    pub deviation: i32,
}

/// An element without a partner on the other side.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Unmatched {
    /// Index into `shapes`, or into [`placed_strings`] for text.
    pub index: usize,
    pub summary: String,
    pub nearest: Option<Nearest>,
}

#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct Section {
    pub expected: usize,
    pub actual: usize,
    pub matched: usize,
    /// Largest coordinate difference among matched elements.
    pub max_deviation: i32,
    /// Expected elements the actual list lacks.
    pub missing: Vec<Unmatched>,
    /// Actual elements the expected list lacks.
    pub extra: Vec<Unmatched>,
}

impl Section {
    pub fn is_match(&self) -> bool {
        self.missing.is_empty() && self.extra.is_empty()
    }
}

#[derive(Debug, Clone, Default, PartialEq, Eq)]
pub struct Report {
    pub shapes: Section,
    pub texts: Section,
}

impl Report {
    pub fn is_match(&self) -> bool {
        self.shapes.is_match() && self.texts.is_match()
    }

    pub fn max_deviation(&self) -> i32 {
        self.shapes.max_deviation.max(self.texts.max_deviation)
    }
}

/// The elements drawn by items for which `keep` holds; elements without a source are left out.
pub fn restrict(list: &DisplayList, keep: impl Fn(ItemId) -> bool) -> DisplayList {
    let kept = |source: Option<ItemId>| source.is_some_and(&keep);
    DisplayList {
        shapes: list
            .shapes
            .iter()
            .filter(|s| kept(s.source))
            .cloned()
            .collect(),
        texts: list
            .texts
            .iter()
            .filter(|t| kept(t.source))
            .cloned()
            .collect(),
    }
}

pub fn compare(expected: &DisplayList, actual: &DisplayList, options: &CompareOptions) -> Report {
    Report {
        shapes: compare_shapes(&expected.shapes, &actual.shapes, options),
        texts: compare_texts(
            &placed_strings(expected, options),
            &placed_strings(actual, options),
            options,
        ),
    }
}

// -- matching ------------------------------------------------------------------

/// Greedy one-to-one matching: every expected element takes the closest free
/// candidate within tolerance. `candidates(i)` lists the actual elements that
/// could match expected element `i`, `deviation` measures a pair.
fn match_elements(
    expected: usize,
    actual: usize,
    candidates: impl Fn(usize) -> Vec<usize>,
    deviation: impl Fn(usize, usize) -> Option<i32>,
    tolerance: i32,
) -> (Vec<Option<(usize, i32)>>, Vec<bool>) {
    let mut taken = vec![false; actual];
    let pairs = (0..expected)
        .map(|e| {
            let best = candidates(e)
                .into_iter()
                .filter(|&a| !taken[a])
                .filter_map(|a| deviation(e, a).map(|d| (a, d)))
                .filter(|&(_, d)| d <= tolerance)
                .min_by_key(|&(a, d)| (d, a));
            if let Some((a, _)) = best {
                taken[a] = true;
            }
            best
        })
        .collect();
    (pairs, taken)
}

fn section(
    pairs: &[Option<(usize, i32)>],
    taken: &[bool],
    expected_summary: impl Fn(usize) -> String,
    actual_summary: impl Fn(usize) -> String,
    nearest: impl Fn(usize) -> Option<Nearest>,
) -> Section {
    Section {
        expected: pairs.len(),
        actual: taken.len(),
        matched: pairs.iter().flatten().count(),
        max_deviation: pairs.iter().flatten().map(|&(_, d)| d).max().unwrap_or(0),
        missing: pairs
            .iter()
            .enumerate()
            .filter(|(_, pair)| pair.is_none())
            .map(|(e, _)| Unmatched {
                index: e,
                summary: expected_summary(e),
                nearest: nearest(e),
            })
            .collect(),
        extra: taken
            .iter()
            .enumerate()
            .filter(|(_, &t)| !t)
            .map(|(a, _)| Unmatched {
                index: a,
                summary: actual_summary(a),
                nearest: None,
            })
            .collect(),
    }
}

// -- shapes ----------------------------------------------------------------------

pub(crate) fn point_deviation(a: &Point, b: &Point) -> i32 {
    (a.x - b.x).abs().max((a.y - b.y).abs())
}

fn sequence_deviation<'a>(
    a: impl Iterator<Item = &'a Point>,
    b: impl Iterator<Item = &'a Point>,
) -> i32 {
    a.zip(b)
        .map(|(p, q)| point_deviation(p, q))
        .max()
        .unwrap_or(0)
}

fn is_closed(path: &[Point]) -> bool {
    path.len() >= 3 && path.first() == path.last()
}

/// Smallest deviation over the start-point rotations of two closed paths.
fn rotated_deviation(expected: &[Point], actual: &[Point]) -> Option<i32> {
    let (cycle_e, cycle_a) = (&expected[..expected.len() - 1], &actual[..actual.len() - 1]);
    (1..cycle_a.len())
        .map(|k| sequence_deviation(cycle_e.iter(), cycle_a.iter().cycle().skip(k)))
        .min()
}

fn path_deviation(expected: &[Point], actual: &[Point], options: &CompareOptions) -> Option<i32> {
    if expected.len() != actual.len() {
        return None;
    }
    let direct = sequence_deviation(expected.iter(), actual.iter());
    let may_rotate = options.rotate_closed_paths && is_closed(expected) && is_closed(actual);
    if direct <= options.tolerance || !may_rotate {
        return Some(direct);
    }
    Some(rotated_deviation(expected, actual).map_or(direct, |r| r.min(direct)))
}

fn shape_deviation(expected: &Shape, actual: &Shape, options: &CompareOptions) -> Option<i32> {
    if expected.kind != actual.kind
        || expected.colour != actual.colour
        || expected.paths.len() != actual.paths.len()
    {
        return None;
    }
    expected
        .paths
        .iter()
        .zip(&actual.paths)
        .map(|(e, a)| path_deviation(e, a, options))
        .try_fold(0, |worst, d| d.map(|d| worst.max(d)))
}

#[derive(Debug, Clone, PartialEq, Eq, Hash)]
struct ShapeKey {
    kind: ShapeKind,
    colour: Colour,
    lengths: Vec<usize>,
}

impl ShapeKey {
    fn of(shape: &Shape) -> Self {
        ShapeKey {
            kind: shape.kind,
            colour: shape.colour,
            lengths: shape.paths.iter().map(Vec::len).collect(),
        }
    }
}

fn min_x(shape: &Shape) -> i32 {
    shape.paths.iter().flatten().map(|p| p.x).min().unwrap_or(0)
}

/// Actual shapes grouped by structure and sorted by their leftmost x, for range queries.
struct ShapeIndex {
    buckets: HashMap<ShapeKey, Vec<(i32, usize)>>,
}

impl ShapeIndex {
    fn new(shapes: &[Shape]) -> Self {
        let mut buckets: HashMap<ShapeKey, Vec<(i32, usize)>> = HashMap::new();
        shapes.iter().enumerate().for_each(|(i, s)| {
            buckets
                .entry(ShapeKey::of(s))
                .or_default()
                .push((min_x(s), i))
        });
        buckets
            .values_mut()
            .for_each(|bucket| bucket.sort_unstable());
        ShapeIndex { buckets }
    }

    fn same_structure(&self, shape: &Shape) -> &[(i32, usize)] {
        self.buckets
            .get(&ShapeKey::of(shape))
            .map_or(&[], Vec::as_slice)
    }

    fn near(&self, shape: &Shape, tolerance: i32) -> Vec<usize> {
        let bucket = self.same_structure(shape);
        let x = min_x(shape);
        let start = bucket.partition_point(|&(bx, _)| bx < x - tolerance);
        bucket[start..]
            .iter()
            .take_while(|&&(bx, _)| bx <= x + tolerance)
            .map(|&(_, i)| i)
            .collect()
    }
}

pub(crate) fn shape_summary(shape: &Shape) -> String {
    let kind = match shape.kind {
        ShapeKind::Stroke => "stroke",
        ShapeKind::Fill => "fill",
    };
    let Colour { r, g, b } = shape.colour;
    let points: usize = shape.paths.iter().map(Vec::len).sum();
    let start = shape
        .paths
        .first()
        .and_then(|p| p.first())
        .map_or(String::new(), |p| format!(" from ({}, {})", p.x, p.y));
    format!(
        "{kind} #{r:02x}{g:02x}{b:02x}, {} path(s), {points} points{start}",
        shape.paths.len()
    )
}

fn compare_shapes(expected: &[Shape], actual: &[Shape], options: &CompareOptions) -> Section {
    let index = ShapeIndex::new(actual);
    let deviation = |e: usize, a: usize| shape_deviation(&expected[e], &actual[a], options);
    let (pairs, taken) = match_elements(
        expected.len(),
        actual.len(),
        |e| index.near(&expected[e], options.tolerance),
        deviation,
        options.tolerance,
    );
    let nearest = |e: usize| {
        index
            .same_structure(&expected[e])
            .iter()
            .filter(|&&(_, a)| !taken[a])
            .filter_map(|&(_, a)| {
                deviation(e, a).map(|d| Nearest {
                    index: a,
                    deviation: d,
                })
            })
            .min_by_key(|n| (n.deviation, n.index))
    };
    section(
        &pairs,
        &taken,
        |e| shape_summary(&expected[e]),
        |a| shape_summary(&actual[a]),
        nearest,
    )
}

// -- texts -----------------------------------------------------------------------

/// One string with the run it belongs to.
#[derive(Debug, Clone, Copy)]
pub struct Placed<'a> {
    pub run: &'a TextRun,
    pub string: &'a PlacedText,
}

/// The strings of a display list in order, the indexing [`Unmatched`] uses for text.
pub fn placed_strings<'a>(list: &'a DisplayList, options: &CompareOptions) -> Vec<Placed<'a>> {
    list.texts
        .iter()
        .filter(|run| !(options.ignore_staff_numbers && is_staff_number(run)))
        .flat_map(|run| run.strings.iter().map(move |string| Placed { run, string }))
        .collect()
}

pub(crate) fn same_style(a: &TextRun, b: &TextRun, tolerance: f32) -> bool {
    a.font == b.font
        && a.colour == b.colour
        && a.escapement == b.escapement
        && a.weight == b.weight
        && a.italic == b.italic
        && a.underline == b.underline
        && (a.height - b.height).abs() <= tolerance
        && (a.width - b.width).abs() <= tolerance
}

fn text_deviation(expected: &Placed, actual: &Placed, options: &CompareOptions) -> Option<i32> {
    (expected.string.text == actual.string.text
        && same_style(expected.run, actual.run, options.tolerance as f32))
    .then(|| point_deviation(&expected.string.origin, &actual.string.origin))
}

pub(crate) fn text_summary(placed: &Placed) -> String {
    let Placed { run, string } = placed;
    format!(
        "{:?} in {} {:.1}/{:.1} at ({}, {})",
        string.text, run.font, run.height, run.width, string.origin.x, string.origin.y
    )
}

fn compare_texts(expected: &[Placed], actual: &[Placed], options: &CompareOptions) -> Section {
    let mut by_text: HashMap<&str, Vec<usize>> = HashMap::new();
    actual
        .iter()
        .enumerate()
        .for_each(|(i, p)| by_text.entry(p.string.text.as_str()).or_default().push(i));
    let candidates = |e: usize| {
        by_text
            .get(expected[e].string.text.as_str())
            .cloned()
            .unwrap_or_default()
    };
    let deviation = |e: usize, a: usize| text_deviation(&expected[e], &actual[a], options);
    let (pairs, taken) = match_elements(
        expected.len(),
        actual.len(),
        candidates,
        deviation,
        options.tolerance,
    );
    let nearest = |e: usize| {
        candidates(e)
            .into_iter()
            .filter(|&a| !taken[a])
            .filter_map(|a| {
                deviation(e, a).map(|d| Nearest {
                    index: a,
                    deviation: d,
                })
            })
            .min_by_key(|n| (n.deviation, n.index))
    };
    section(
        &pairs,
        &taken,
        |e| text_summary(&expected[e]),
        |a| text_summary(&actual[a]),
        nearest,
    )
}

// -- report ----------------------------------------------------------------------

const LISTED: usize = 20;

fn write_section(f: &mut fmt::Formatter<'_>, name: &str, s: &Section) -> fmt::Result {
    writeln!(
        f,
        "{name}: {} of {} matched ({} actual), max deviation {}",
        s.matched, s.expected, s.actual, s.max_deviation
    )?;
    for m in s.missing.iter().take(LISTED) {
        let nearest = m
            .nearest
            .map_or(String::from("no candidate with the same structure"), |n| {
                format!("nearest actual #{} off by {}", n.index, n.deviation)
            });
        writeln!(f, "  missing #{}: {}; {nearest}", m.index, m.summary)?;
    }
    if s.missing.len() > LISTED {
        writeln!(f, "  ... {} more missing", s.missing.len() - LISTED)?;
    }
    for m in s.extra.iter().take(LISTED) {
        writeln!(f, "  extra #{}: {}", m.index, m.summary)?;
    }
    if s.extra.len() > LISTED {
        writeln!(f, "  ... {} more extra", s.extra.len() - LISTED)?;
    }
    Ok(())
}

impl fmt::Display for Report {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write_section(f, "shapes", &self.shapes)?;
        write_section(f, "texts", &self.texts)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn stroke(points: &[(i32, i32)]) -> Shape {
        Shape {
            kind: ShapeKind::Stroke,
            colour: Colour::BLACK,
            paths: vec![points.iter().map(|&(x, y)| Point::new(x, y)).collect()],
            width: 0.0,
            source: None,
        }
    }

    fn fill(points: &[(i32, i32)]) -> Shape {
        Shape {
            kind: ShapeKind::Fill,
            ..stroke(points)
        }
    }

    fn list(shapes: Vec<Shape>) -> DisplayList {
        DisplayList {
            shapes,
            texts: vec![],
        }
    }

    fn text(s: &str, x: i32, y: i32) -> TextRun {
        TextRun {
            font: "Times".into(),
            height: 800.0,
            width: 0.0,
            escapement: 0,
            colour: Colour::BLACK,
            weight: 400,
            italic: false,
            underline: false,
            outline: false,
            strings: vec![PlacedText {
                origin: Point::new(x, y),
                text: s.into(),
            }],
            source: None,
        }
    }

    #[test]
    fn identical_lists_match_in_any_order() {
        let a = list(vec![
            stroke(&[(0, 0), (10, 0)]),
            fill(&[(0, 0), (5, 5), (0, 5), (0, 0)]),
        ]);
        let b = list(a.shapes.iter().rev().cloned().collect());
        let report = compare(&a, &b, &CompareOptions::default());
        assert!(report.is_match(), "{report}");
        assert_eq!(report.shapes.matched, 2);
        assert_eq!(report.max_deviation(), 0);
    }

    #[test]
    fn one_unit_is_tolerated_two_are_not() {
        let a = list(vec![stroke(&[(0, 0), (10, 0)])]);
        let off_by_one = list(vec![stroke(&[(1, 0), (10, -1)])]);
        let off_by_two = list(vec![stroke(&[(2, 0), (10, 0)])]);
        let options = CompareOptions::default();
        assert_eq!(compare(&a, &off_by_one, &options).max_deviation(), 1);
        let report = compare(&a, &off_by_two, &options);
        assert!(!report.is_match());
        assert_eq!(
            report.shapes.missing[0].nearest,
            Some(Nearest {
                index: 0,
                deviation: 2
            })
        );
        assert_eq!(report.shapes.extra.len(), 1);
    }

    #[test]
    fn closed_fill_may_start_elsewhere() {
        let a = list(vec![fill(&[(0, 0), (10, 0), (10, 10), (0, 10), (0, 0)])]);
        let b = list(vec![fill(&[(10, 10), (0, 10), (0, 0), (10, 0), (10, 10)])]);
        assert!(compare(&a, &b, &CompareOptions::default()).is_match());
        let strict = CompareOptions {
            rotate_closed_paths: false,
            ..CompareOptions::default()
        };
        assert!(!compare(&a, &b, &strict).is_match());
    }

    #[test]
    fn kind_and_colour_must_agree() {
        let a = list(vec![stroke(&[(0, 0), (10, 0)])]);
        let red = list(vec![Shape {
            colour: Colour { r: 253, g: 0, b: 0 },
            ..a.shapes[0].clone()
        }]);
        let as_fill = list(vec![fill(&[(0, 0), (10, 0)])]);
        let options = CompareOptions::default();
        assert!(!compare(&a, &red, &options).is_match());
        assert!(!compare(&a, &as_fill, &options).is_match());
    }

    #[test]
    fn duplicates_pair_one_to_one() {
        let a = list(vec![stroke(&[(0, 0), (10, 0)]), stroke(&[(0, 0), (10, 0)])]);
        let b = list(vec![stroke(&[(0, 0), (10, 0)])]);
        let report = compare(&a, &b, &CompareOptions::default());
        assert_eq!((report.shapes.matched, report.shapes.missing.len()), (1, 1));
    }

    #[test]
    fn strings_match_across_run_grouping() {
        let mut grouped = text("a", 0, 0);
        grouped.strings.push(PlacedText {
            origin: Point::new(100, 1),
            text: "b".into(),
        });
        let expected = DisplayList {
            shapes: vec![],
            texts: vec![grouped],
        };
        let actual = DisplayList {
            shapes: vec![],
            texts: vec![text("b", 100, 0), text("a", 1, 0)],
        };
        let report = compare(&expected, &actual, &CompareOptions::default());
        assert!(report.is_match(), "{report}");
        assert_eq!(report.texts.max_deviation, 1);
    }

    #[test]
    fn staff_numbers_can_be_ignored() {
        let number = TextRun {
            font: "Helvetica-Narrow".into(),
            colour: STAFF_NUMBER_COLOUR,
            ..text("1", 800, 3469)
        };
        let expected = DisplayList {
            shapes: vec![],
            texts: vec![number],
        };
        let options = CompareOptions {
            ignore_staff_numbers: true,
            ..CompareOptions::default()
        };
        assert!(compare(&expected, &DisplayList::default(), &options).is_match());
        assert!(!compare(
            &expected,
            &DisplayList::default(),
            &CompareOptions::default()
        )
        .is_match());
    }
}
