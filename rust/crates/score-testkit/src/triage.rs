//! Classifies the differences of a comparison by source item and symptom.
//!
//! Every unmatched element is attributed to the item that drew it (its
//! `source`) and paired, where possible, with an unmatched element of the same
//! item on the other side. The pairing tells a shifted element from one drawn
//! in the wrong colour, with distorted geometry, or not at all.

use std::collections::{BTreeMap, BTreeSet};
use std::fmt;

use score_render::{Colour, DisplayList, ItemId, Point, Shape, TextRun};

use crate::compare::{placed_strings, point_deviation, same_style, CompareOptions, Placed, Report};

#[derive(Debug, Clone, Copy, PartialEq, Eq, PartialOrd, Ord, Hash)]
pub enum Symptom {
    /// The renderer drew nothing at all for the item.
    Absent,
    /// The item is drawn, but this element has no counterpart.
    Missing,
    /// A counterpart of the same structure, translated as a whole.
    Offset,
    /// A counterpart at the same place in another colour.
    Colour,
    /// A counterpart of the same structure with different geometry.
    Distorted,
    /// The renderer drew this element and the engine did not.
    Extra,
    TextAbsent,
    TextMissing,
    TextOffset,
    /// Same string, different font, size or colour.
    TextStyle,
    TextExtra,
}

impl Symptom {
    pub const ALL: [Symptom; 11] = [
        Symptom::Absent,
        Symptom::Missing,
        Symptom::Offset,
        Symptom::Colour,
        Symptom::Distorted,
        Symptom::Extra,
        Symptom::TextAbsent,
        Symptom::TextMissing,
        Symptom::TextOffset,
        Symptom::TextStyle,
        Symptom::TextExtra,
    ];

    pub fn label(self) -> &'static str {
        match self {
            Symptom::Absent => "absent",
            Symptom::Missing => "missing",
            Symptom::Offset => "offset",
            Symptom::Colour => "colour",
            Symptom::Distorted => "distorted",
            Symptom::Extra => "extra",
            Symptom::TextAbsent => "text absent",
            Symptom::TextMissing => "text missing",
            Symptom::TextOffset => "text offset",
            Symptom::TextStyle => "text style",
            Symptom::TextExtra => "text extra",
        }
    }
}

impl fmt::Display for Symptom {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        f.write_str(self.label())
    }
}

/// One unmatched element.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct Finding {
    pub item: Option<ItemId>,
    pub symptom: Symptom,
    /// Translation from the engine's element to the renderer's, where paired.
    pub delta: Option<Point>,
    pub detail: String,
}

fn sources(list: &DisplayList) -> BTreeSet<ItemId> {
    let shapes = list.shapes.iter().filter_map(|s| s.source);
    shapes
        .chain(list.texts.iter().filter_map(|t| t.source))
        .collect()
}

fn same_structure(a: &Shape, b: &Shape) -> bool {
    a.kind == b.kind
        && a.paths.len() == b.paths.len()
        && a.paths
            .iter()
            .zip(&b.paths)
            .all(|(p, q)| p.len() == q.len())
}

fn first_point(shape: &Shape) -> Point {
    shape
        .paths
        .iter()
        .flatten()
        .next()
        .copied()
        .unwrap_or_default()
}

/// The translation from `e` to `a` and the largest deviation left after it.
fn translation(e: &Shape, a: &Shape) -> (Point, i32) {
    let (p, q) = (first_point(e), first_point(a));
    let delta = Point::new(q.x - p.x, q.y - p.y);
    let residual = e
        .paths
        .iter()
        .flatten()
        .zip(a.paths.iter().flatten())
        .map(|(p, q)| point_deviation(&Point::new(p.x + delta.x, p.y + delta.y), q))
        .max()
        .unwrap_or(0);
    (delta, residual)
}

fn hex(colour: Colour) -> String {
    format!("#{:02x}{:02x}{:02x}", colour.r, colour.g, colour.b)
}

fn magnitude(p: Point) -> i32 {
    p.x.abs().max(p.y.abs())
}

/// Unmatched indices per item, in index order.
fn by_item<T>(
    indices: impl Iterator<Item = usize>,
    source: impl Fn(usize) -> Option<T>,
) -> BTreeMap<Option<T>, Vec<usize>>
where
    T: Ord,
{
    let mut groups: BTreeMap<Option<T>, Vec<usize>> = BTreeMap::new();
    indices.for_each(|i| groups.entry(source(i)).or_default().push(i));
    groups
}

fn shape_findings(
    expected: &DisplayList,
    actual: &DisplayList,
    report: &Report,
    drawn: &BTreeSet<ItemId>,
    options: &CompareOptions,
) -> Vec<Finding> {
    let missing = by_item(report.shapes.missing.iter().map(|m| m.index), |i| {
        expected.shapes[i].source
    });
    let mut extra = by_item(report.shapes.extra.iter().map(|m| m.index), |i| {
        actual.shapes[i].source
    });
    let mut findings = Vec::new();
    for (item, indices) in missing {
        let mut free = extra.remove(&item).unwrap_or_default();
        for e in indices.into_iter().map(|i| &expected.shapes[i]) {
            let partner = free
                .iter()
                .enumerate()
                .filter(|(_, &a)| same_structure(e, &actual.shapes[a]))
                .map(|(k, &a)| (k, translation(e, &actual.shapes[a])))
                .min_by_key(|(_, (delta, residual))| (*residual, magnitude(*delta)));
            let finding = match partner {
                Some((k, (delta, residual))) => {
                    let a = &actual.shapes[free.remove(k)];
                    let recoloured = a.colour != e.colour;
                    let (symptom, detail) = if residual > options.tolerance {
                        (
                            Symptom::Distorted,
                            format!("same structure, off by up to {residual} after aligning"),
                        )
                    } else if recoloured && magnitude(delta) <= options.tolerance {
                        (
                            Symptom::Colour,
                            format!("colour {} instead of {}", hex(a.colour), hex(e.colour)),
                        )
                    } else {
                        (
                            Symptom::Offset,
                            format!(
                                "shifted by ({}, {}), residual {residual}{}",
                                delta.x,
                                delta.y,
                                if recoloured { ", other colour" } else { "" }
                            ),
                        )
                    };
                    Finding {
                        item,
                        symptom,
                        delta: Some(delta),
                        detail,
                    }
                }
                None => {
                    let absent = item.is_some_and(|i| !drawn.contains(&i));
                    let symptom = if absent {
                        Symptom::Absent
                    } else {
                        Symptom::Missing
                    };
                    Finding {
                        item,
                        symptom,
                        delta: None,
                        detail: crate::compare::shape_summary(e),
                    }
                }
            };
            findings.push(finding);
        }
        if !free.is_empty() {
            extra.insert(item, free);
        }
    }
    findings.extend(extra.into_iter().flat_map(|(item, indices)| {
        indices.into_iter().map(move |a| Finding {
            item,
            symptom: Symptom::Extra,
            delta: None,
            detail: crate::compare::shape_summary(&actual.shapes[a]),
        })
    }));
    findings
}

fn text_findings(
    expected: &DisplayList,
    actual: &DisplayList,
    report: &Report,
    drawn: &BTreeSet<ItemId>,
    options: &CompareOptions,
) -> Vec<Finding> {
    let (exp, act) = (
        placed_strings(expected, options),
        placed_strings(actual, options),
    );
    let missing = by_item(report.texts.missing.iter().map(|m| m.index), |i| {
        exp[i].run.source
    });
    let mut extra = by_item(report.texts.extra.iter().map(|m| m.index), |i| {
        act[i].run.source
    });
    let mut findings = Vec::new();
    for (item, indices) in missing {
        let mut free = extra.remove(&item).unwrap_or_default();
        for e in indices.into_iter().map(|i| &exp[i]) {
            let same_text = |a: &Placed| a.string.text == e.string.text;
            let partner = free
                .iter()
                .enumerate()
                .filter(|(_, &a)| same_text(&act[a]))
                .min_by_key(|(_, &a)| point_deviation(&e.string.origin, &act[a].string.origin))
                .map(|(k, _)| k);
            let finding = match partner {
                Some(k) => {
                    let a = &act[free.remove(k)];
                    let delta = Point::new(
                        a.string.origin.x - e.string.origin.x,
                        a.string.origin.y - e.string.origin.y,
                    );
                    if same_style(e.run, a.run, options.tolerance as f32) {
                        let detail =
                            format!("{:?} shifted by ({}, {})", e.string.text, delta.x, delta.y);
                        Finding {
                            item,
                            symptom: Symptom::TextOffset,
                            delta: Some(delta),
                            detail,
                        }
                    } else {
                        let style = |r: &TextRun| {
                            format!(
                                "{} {:.1}/{:.1} {} w{}{}{} esc {}",
                                r.font,
                                r.height,
                                r.width,
                                hex(r.colour),
                                r.weight,
                                if r.italic { " italic" } else { "" },
                                if r.underline { " underlined" } else { "" },
                                r.escapement
                            )
                        };
                        let detail = format!(
                            "{:?}: {} instead of {}",
                            e.string.text,
                            style(a.run),
                            style(e.run)
                        );
                        Finding {
                            item,
                            symptom: Symptom::TextStyle,
                            delta: Some(delta),
                            detail,
                        }
                    }
                }
                None => {
                    let absent = item.is_some_and(|i| !drawn.contains(&i));
                    let symptom = if absent {
                        Symptom::TextAbsent
                    } else {
                        Symptom::TextMissing
                    };
                    Finding {
                        item,
                        symptom,
                        delta: None,
                        detail: crate::compare::text_summary(e),
                    }
                }
            };
            findings.push(finding);
        }
        if !free.is_empty() {
            extra.insert(item, free);
        }
    }
    findings.extend(extra.into_iter().flat_map(|(item, indices)| {
        let act = &act;
        indices.into_iter().map(move |a| Finding {
            item,
            symptom: Symptom::TextExtra,
            delta: None,
            detail: crate::compare::text_summary(&act[a]),
        })
    }));
    findings
}

/// Every unmatched element of `report`, classified.
pub fn triage(
    expected: &DisplayList,
    actual: &DisplayList,
    report: &Report,
    options: &CompareOptions,
) -> Vec<Finding> {
    let drawn = sources(actual);
    let mut findings = shape_findings(expected, actual, report, &drawn, options);
    findings.extend(text_findings(expected, actual, report, &drawn, options));
    findings
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::compare::compare;
    use score_render::ShapeKind;

    /// Each item draws in its own stretch of the page.
    fn shape(item: u32, points: &[(i32, i32)], colour: Colour) -> Shape {
        let left = 1000 * item as i32;
        Shape {
            kind: ShapeKind::Fill,
            colour,
            paths: vec![points
                .iter()
                .map(|&(x, y)| Point::new(left + x, y))
                .collect()],
            source: Some(ItemId(item)),
        }
    }

    fn list(shapes: Vec<Shape>) -> DisplayList {
        DisplayList {
            shapes,
            texts: vec![],
        }
    }

    fn symptoms(expected: &DisplayList, actual: &DisplayList) -> Vec<(Option<u32>, Symptom)> {
        let options = CompareOptions::default();
        let report = compare(expected, actual, &options);
        let mut out: Vec<_> = triage(expected, actual, &report, &options)
            .into_iter()
            .map(|f| (f.item.map(|ItemId(i)| i), f.symptom))
            .collect();
        out.sort();
        out
    }

    #[test]
    fn classifies_by_item() {
        let black = Colour::BLACK;
        let red = Colour { r: 253, g: 0, b: 0 };
        let square = [(0, 0), (10, 0), (10, 10), (0, 0)];
        let shifted = [(0, 100), (10, 100), (10, 110), (0, 100)];
        let bent = [(0, 0), (10, 0), (10, 30), (0, 0)];
        let expected = list(vec![
            shape(0, &square, black),
            shape(1, &square, black),
            shape(2, &square, black),
            shape(3, &square, black),
            shape(4, &square, black),
            shape(4, &shifted, black),
        ]);
        let actual = list(vec![
            shape(1, &shifted, black),
            shape(2, &square, red),
            shape(3, &bent, black),
            shape(4, &square, black),
            shape(5, &square, black),
        ]);
        assert_eq!(
            symptoms(&expected, &actual),
            vec![
                (Some(0), Symptom::Absent),
                (Some(1), Symptom::Offset),
                (Some(2), Symptom::Colour),
                (Some(3), Symptom::Distorted),
                (Some(4), Symptom::Missing),
                (Some(5), Symptom::Extra),
            ]
        );
    }
}
