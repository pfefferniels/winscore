//! Which item lies under a point of the page.
//!
//! Every display-list element that remembers its source item is a candidate:
//! filled shapes by the even-odd rule or nearness to their outline,
//! polylines by distance, text by the box of its character cells. Among
//! candidates within the tolerance the nearest wins, and on a tie the one
//! with the smaller bounding box, so a note head beats the staff under it.

use score_render::{DisplayList, ItemId, Point, Shape, ShapeKind, TextRun};

/// A point of the page in engine units, unrounded.
#[derive(Debug, Clone, Copy, PartialEq, Default)]
pub struct At {
    pub x: f64,
    pub y: f64,
}

impl At {
    pub const fn new(x: f64, y: f64) -> Self {
        Self { x, y }
    }
}

impl From<Point> for At {
    fn from(p: Point) -> Self {
        Self::new(f64::from(p.x), f64::from(p.y))
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
struct Bounds {
    min: At,
    max: At,
}

impl Bounds {
    fn of(points: impl IntoIterator<Item = At>) -> Option<Self> {
        points.into_iter().fold(None, |bounds, p| {
            Some(match bounds {
                None => Bounds { min: p, max: p },
                Some(b) => Bounds {
                    min: At::new(b.min.x.min(p.x), b.min.y.min(p.y)),
                    max: At::new(b.max.x.max(p.x), b.max.y.max(p.y)),
                },
            })
        })
    }

    fn area(&self) -> f64 {
        (self.max.x - self.min.x) * (self.max.y - self.min.y)
    }

    fn distance(&self, p: At) -> f64 {
        let dx = (self.min.x - p.x).max(p.x - self.max.x).max(0.0);
        let dy = (self.min.y - p.y).max(p.y - self.max.y).max(0.0);
        dx.hypot(dy)
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
struct Candidate {
    item: ItemId,
    distance: f64,
    area: f64,
}

fn segment_distance(p: At, a: At, b: At) -> f64 {
    let (dx, dy) = (b.x - a.x, b.y - a.y);
    let length_sq = dx * dx + dy * dy;
    let t = if length_sq == 0.0 { 0.0 } else { (((p.x - a.x) * dx + (p.y - a.y) * dy) / length_sq).clamp(0.0, 1.0) };
    (p.x - (a.x + t * dx)).hypot(p.y - (a.y + t * dy))
}

/// Consecutive point pairs of a path. Closed paths include the closing edge;
/// a single point is a degenerate edge.
fn edges(path: &[Point], closed: bool) -> impl Iterator<Item = (At, At)> + '_ {
    let closing = (closed || path.len() == 1).then(|| path.last().copied().zip(path.first().copied())).flatten();
    path.windows(2)
        .map(|w| (w[0], w[1]))
        .chain(closing)
        .map(|(a, b)| (At::from(a), At::from(b)))
}

fn outline_distance(p: At, shape: &Shape) -> f64 {
    let closed = shape.kind == ShapeKind::Fill;
    shape
        .paths
        .iter()
        .flat_map(|path| edges(path, closed))
        .map(|(a, b)| segment_distance(p, a, b))
        .fold(f64::INFINITY, f64::min)
}

/// Even-odd rule over all paths of a filled shape (GDI ALTERNATE).
fn inside(p: At, shape: &Shape) -> bool {
    let crossings = shape
        .paths
        .iter()
        .flat_map(|path| edges(path, true))
        .filter(|(a, b)| (a.y > p.y) != (b.y > p.y) && p.x < a.x + (p.y - a.y) * (b.x - a.x) / (b.y - a.y))
        .count();
    crossings % 2 == 1
}

fn shape_candidate(p: At, shape: &Shape) -> Option<Candidate> {
    let item = shape.source?;
    let bounds = Bounds::of(shape.paths.iter().flatten().copied().map(At::from))?;
    let distance = if shape.kind == ShapeKind::Fill && inside(p, shape) { 0.0 } else { outline_distance(p, shape) };
    Some(Candidate { item, distance, area: bounds.area() })
}

/// Ascent and descent of a character cell in em, roughly those of Times New
/// Roman, for boxes around text.
const CELL_ASCENT: f64 = 0.8;
const CELL_DESCENT: f64 = 0.25;

/// The box of a placed string: from its origin on the baseline (the engine's
/// y + 96, analysis/engine/display.md), one cell ascent up, one descent down,
/// and one average width per character across. Rotation is ignored.
fn text_bounds(run: &TextRun, origin: Point, text: &str) -> Bounds {
    let height = f64::from(run.height);
    let advance = if run.width > 0.0 { f64::from(run.width) } else { height / 2.0 };
    let baseline = At::from(origin);
    let width = advance * text.chars().count().max(1) as f64;
    Bounds {
        min: At::new(baseline.x, baseline.y - CELL_DESCENT * height),
        max: At::new(baseline.x + width, baseline.y + CELL_ASCENT * height),
    }
}

fn text_candidates(p: At, run: &TextRun) -> impl Iterator<Item = Candidate> + '_ {
    run.source.into_iter().flat_map(move |item| {
        run.strings.iter().map(move |s| {
            let bounds = text_bounds(run, s.origin, &s.text);
            Candidate { item, distance: bounds.distance(p), area: bounds.area() }
        })
    })
}

/// The item drawn nearest to `p`, if any element lies within `tolerance` units.
pub fn hit_test(list: &DisplayList, p: At, tolerance: f64) -> Option<ItemId> {
    let shapes = list.shapes.iter().filter_map(|shape| shape_candidate(p, shape));
    let texts = list.texts.iter().flat_map(|run| text_candidates(p, run));
    shapes
        .chain(texts)
        .filter(|c| c.distance <= tolerance)
        .min_by(|a, b| a.distance.total_cmp(&b.distance).then(a.area.total_cmp(&b.area)))
        .map(|c| c.item)
}

#[cfg(test)]
mod tests {
    use super::*;
    use score_render::{Colour, PlacedText};

    fn rect(x0: i32, y0: i32, x1: i32, y1: i32) -> Vec<Point> {
        vec![Point::new(x0, y0), Point::new(x1, y0), Point::new(x1, y1), Point::new(x0, y1)]
    }

    fn fill(paths: Vec<Vec<Point>>, item: u32) -> Shape {
        Shape { kind: ShapeKind::Fill, colour: Colour::BLACK, paths, source: Some(ItemId(item)) }
    }

    fn stroke(path: Vec<Point>, item: u32) -> Shape {
        Shape { kind: ShapeKind::Stroke, colour: Colour::BLACK, paths: vec![path], source: Some(ItemId(item)) }
    }

    #[test]
    fn even_odd_hole_is_outside() {
        let ring = fill(vec![rect(0, 0, 100, 100), rect(25, 25, 75, 75)], 1);
        assert!(inside(At::new(10.0, 10.0), &ring));
        assert!(!inside(At::new(50.0, 50.0), &ring));
        assert!(!inside(At::new(150.0, 50.0), &ring));
    }

    #[test]
    fn smaller_item_wins_over_staff() {
        let list = DisplayList {
            shapes: vec![fill(vec![rect(0, 0, 1000, 10)], 0), fill(vec![rect(420, -30, 480, 30)], 1)],
            texts: vec![],
        };
        assert_eq!(hit_test(&list, At::new(450.0, 5.0), 20.0), Some(ItemId(1)));
        assert_eq!(hit_test(&list, At::new(100.0, 5.0), 20.0), Some(ItemId(0)));
        assert_eq!(hit_test(&list, At::new(100.0, 200.0), 20.0), None);
    }

    #[test]
    fn polyline_by_distance() {
        let list = DisplayList { shapes: vec![stroke(vec![Point::new(0, 0), Point::new(100, 0)], 3)], texts: vec![] };
        assert_eq!(hit_test(&list, At::new(50.0, 8.0), 10.0), Some(ItemId(3)));
        assert_eq!(hit_test(&list, At::new(50.0, 12.0), 10.0), None);
    }

    #[test]
    fn text_by_cell_box() {
        let run = TextRun {
            font: "Times".into(),
            height: 400.0,
            width: 160.0,
            escapement: 0,
            colour: Colour::BLACK,
            weight: 400,
            italic: false,
            underline: false,
            strings: vec![PlacedText { origin: Point::new(1000, 2000), text: "abc".into() }],
            source: Some(ItemId(9)),
        };
        let list = DisplayList { shapes: vec![], texts: vec![run] };
        assert_eq!(hit_test(&list, At::new(1400.0, 2200.0), 0.0), Some(ItemId(9)));
        assert_eq!(hit_test(&list, At::new(1400.0, 1800.0), 0.0), None);
        assert_eq!(hit_test(&list, At::new(1600.0, 2200.0), 0.0), None);
    }

    #[test]
    fn elements_without_source_are_ignored() {
        let mut shape = fill(vec![rect(0, 0, 10, 10)], 0);
        shape.source = None;
        let list = DisplayList { shapes: vec![shape], texts: vec![] };
        assert_eq!(hit_test(&list, At::new(5.0, 5.0), 1.0), None);
    }
}
