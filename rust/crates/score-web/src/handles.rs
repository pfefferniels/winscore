//! Handles on a selected item: points of its picture that a drag sets
//! parameters with, beyond the move that P3 and P4 make. Each handle knows
//! what it changes (the ends of lines, slurs and beams, sizes, rotation, a
//! slur's curve, a hairpin's opening, a bracket's hook, a stem's length, a
//! staff's place, extent and size, a barline's reach, a text's spacing) and
//! how the cursor's travel turns into parameter values. A drag sets them
//! live through score-edit's adjustment and ends as one undo step.
//!
//! The handles of an item are worked out once, when a drag takes hold of
//! one; [`Handle::apply`] then maps the travel from the grab onto the
//! parameters as they were at that moment. Points are page coordinates
//! (engine units, origin at the paper's bottom-left corner, y up); turns
//! are degrees clockwise, as SCORE's rotations are.

use score_edit::Draft;
use score_format::MusFile;
use score_render::codes::{self, barline, beam, line, note, slur, staff as staff_code};
use score_render::geometry::turned;
use score_render::page::{self, page_offset, P3_UNIT};
use score_render::staff::Staff;
use score_render::units::Pos;
use score_render::{render_item, DisplayList, Document, ItemId, ItemRef};
use serde_json::{json, Value};
use wasm_bindgen::prelude::*;

use crate::editing::Outcome;
use crate::hit::{list_bounds, At};
use crate::Score;

/// What a handle does, which decides how the shell draws it.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Kind {
    /// An end of a line, slur, beam or staff, or the top of a barline.
    End,
    /// A corner or side of the item's frame: its size.
    Scale,
    /// Above the frame: its rotation.
    Rotate,
    /// A shape of the item's own: curvature, opening, hook, stem, place.
    Adjust,
}

impl Kind {
    fn name(self) -> &'static str {
        match self {
            Kind::End => "end",
            Kind::Scale => "scale",
            Kind::Rotate => "rotate",
            Kind::Adjust => "adjust",
        }
    }
}

/// Which way a handle moves, in the item's turned frame.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum Axis {
    Both,
    X,
    Y,
}

impl Axis {
    fn name(self) -> &'static str {
        match self {
            Axis::Both => "both",
            Axis::X => "x",
            Axis::Y => "y",
        }
    }
}

/// Size parameters scaled by a frame handle.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Sizes {
    /// The width (or only) size.
    x: usize,
    /// The height, 0 standing for "as the width".
    y: Option<usize>,
    /// The width's hundreds hold part-extraction flags and its sign mirrors (text, symbols).
    parts: bool,
    /// What a width of 0 stands for.
    zero: f32,
}

/// How a handle's travel becomes parameter values.
#[derive(Debug, Clone, PartialEq)]
enum Action {
    /// Moves a point of the item: P`x` by the travel across / 150 and the
    /// level P`y` by the travel up / `step`, the travel turned back through
    /// `turn` first. `cue`: P`y` keeps a hundred for cue size.
    Point { x: Option<usize>, y: Option<usize>, step: f64, turn: f64, cue: bool },
    /// Scales the sizes as the handle's distance from `anchor` along the
    /// frame's axes changes. The item grows about `reference`; when it may
    /// move (`step` set), it moves so that `anchor` stays where it is.
    Scale {
        anchor: At,
        reference: At,
        turn: f64,
        axis: Axis,
        free: bool,
        sizes: Sizes,
        step: Option<f64>,
        peers: Vec<f32>,
    },
    /// The angle of the cursor about `centre` turns parameter `param`.
    Rotate { centre: At, param: usize },
    /// A slur's curvature P7 across its chord and the peak's place P10 along it.
    Curve { along: At, length: f64, step: f64, centre: f64 },
    /// Parameter `param` by the travel up / `step` (a bracket's height).
    Lift { param: usize, step: f64 },
    /// A hairpin's opening P7.
    Opening { turn: f64, step: f64 },
    /// The bracket hook P11 or P12 at a line's end.
    Hook { param: usize, turn: f64, step: f64 },
    /// A note's stem length P8; `per_step` is how far the end moves up per step.
    Stem { per_step: f64 },
    /// A staff's vertical place P4.
    Place { step: f64 },
    /// A staff's size P5 (or P14, its height in cm) about its bottom line.
    StaffSize { bottom: f64, param: usize },
    /// A barline's span P4: the staff top nearest the cursor, `tops[i]` that of span i + 1.
    Reach { tops: Vec<f64>, to_highest: bool },
    /// A text's spacing P5; `width` is its length unspread.
    Spacing { turn: f64, width: f64 },
}

/// One handle of the selected item.
#[derive(Debug, Clone, PartialEq)]
pub struct Handle {
    pub kind: Kind,
    pub at: At,
    pub axis: Axis,
    /// The item's frame, degrees clockwise: for the shell's cursors.
    pub turn: f64,
    /// What it changes, for the tooltip.
    pub label: &'static str,
    /// Whether the handle follows the cursor, so that guides may snap it.
    pub follows: bool,
    action: Action,
}

/// The handles of an item and the frame its size handles sit on.
#[derive(Debug, Clone, PartialEq, Default)]
pub struct Handles {
    pub handles: Vec<Handle>,
    /// The corners of the item's frame, turned with it.
    pub frame: Option<[At; 4]>,
    /// Values every drag of these handles starts from: what the item's
    /// zeros stand for (a slur's right end, a staff's), written out.
    pub prepared: Vec<(usize, f32)>,
}

/// A drag of one handle: where it took hold, where the cursor is now.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Travel {
    pub from: At,
    pub to: At,
    /// Shift: one axis, proportional sizes, 15° steps.
    pub constrain: bool,
    /// How near (page units) a value must come to a default or a match to snap to it.
    pub tolerance: f64,
}

/// What a drag sets, and the words for it.
#[derive(Debug, Clone, PartialEq, Default)]
pub struct Adjusted {
    pub values: Vec<(usize, f32)>,
    pub readout: String,
}

// ---------------------------------------------------------------------------
// Small helpers

fn on_page(staff: i32, p: Pos) -> At {
    let offset = page_offset(staff);
    At::new(p.x + f64::from(offset.x), p.y + f64::from(offset.y))
}

fn sub(a: At, b: At) -> At {
    At::new(a.x - b.x, a.y - b.y)
}

fn add(a: At, b: At) -> At {
    At::new(a.x + b.x, a.y + b.y)
}

fn dot(a: At, b: At) -> f64 {
    a.x * b.x + a.y * b.y
}

/// A vector turned clockwise by `degrees`.
fn turn_vector(v: At, degrees: f64) -> At {
    let p = turned(Pos::new(v.x, v.y), Pos::new(0.0, 0.0), degrees);
    At::new(p.x, p.y)
}

/// A point turned clockwise by `degrees` about `centre`.
fn turn_about(p: At, centre: At, degrees: f64) -> At {
    add(centre, turn_vector(sub(p, centre), degrees))
}

fn rounded(v: f64, unit: f64) -> f32 {
    ((v / unit).round() * unit) as f32
}

/// A number as the panel shows it: at most two decimals, no trailing zeros.
fn num(v: f64) -> String {
    let r = (v * 100.0).round() / 100.0;
    if r == 0.0 {
        "0".into()
    } else {
        format!("{r}")
    }
}

/// Signed with an explicit plus, for changes against a default.
fn signed(v: f64) -> String {
    if v > 0.0 {
        format!("+{}", num(v))
    } else {
        num(v)
    }
}

/// P4 of notes, rests, clefs and beams: a level, plus 100 (−100 below 0) for cue size.
fn level_of(p4: f32, cue: bool) -> f64 {
    let p4 = f64::from(p4);
    if cue {
        p4 - (p4 / 100.0).trunc() * 100.0
    } else {
        p4
    }
}

fn with_level(level: f32, start: f32, cue: bool) -> f32 {
    if cue && (start / 100.0).trunc() != 0.0 {
        level + if level < 0.0 { -100.0 } else { 100.0 }
    } else {
        level
    }
}

/// The hundreds of a text's or symbol's size: where the part extractor puts it.
fn parts_of(v: f32) -> f32 {
    (v.abs() / 100.0 + 1e-6).floor() * 100.0
}

// ---------------------------------------------------------------------------
// Which handles an item has

/// The handles of item `index` of `file`.
pub fn handles(file: &MusFile, index: usize) -> Handles {
    let doc = score_render::Document::new(file);
    let Some(item) = doc.item(ItemId(index as u32)) else { return Handles::default() };
    let staff = doc.staff_of(item);
    let mut found = Handles::default();
    match item.code() {
        codes::NOTE => stem(&doc, item, &mut found),
        codes::CLEF => {
            frame(&doc, item, FrameSpec::sized(6, Some(7), false, 1.0), &mut found);
        }
        codes::LINE => line_handles(&doc, item, &staff, &mut found),
        codes::SLUR => slur_handles(&doc, item, &staff, &mut found),
        codes::BEAM => beam_handles(&doc, item, &staff, &mut found),
        codes::TRILL => trill_handles(&doc, item, &mut found),
        codes::STAFF => staff_handles(&doc, item, &mut found),
        codes::SYMBOL => {
            frame(&doc, item, FrameSpec { rotation: Some(9), ..FrameSpec::sized(6, Some(7), true, 1.0) }, &mut found);
        }
        codes::NUMBER => {
            frame(&doc, item, FrameSpec { rotation: Some(19), ..FrameSpec::uniform(6) }, &mut found);
        }
        codes::BOX if [0.0, 1.0, 3.0].contains(&item.p(5)) => {
            let spec =
                FrameSpec { rotation: Some(9), free: true, moves: true, ..FrameSpec::sized(6, Some(7), false, 0.0) };
            frame(&doc, item, spec, &mut found);
        }
        codes::BARLINE => reach(&doc, item, &mut found),
        codes::TEXT => text_handles(&doc, item, &mut found),
        codes::METER => {
            frame(&doc, item, FrameSpec::uniform(7), &mut found);
        }
        _ => {}
    }
    found
}

/// Note stems: the end of the stem sets P8.
fn stem(doc: &Document<'_>, item: ItemRef<'_>, found: &mut Handles) {
    let Some((end, per_step)) = note::stem_end(doc, item) else { return };
    found.handles.push(Handle {
        kind: Kind::Adjust,
        at: on_page(item.staff(), end),
        axis: Axis::Y,
        turn: 0.0,
        label: "Stem",
        follows: true,
        action: Action::Stem { per_step },
    });
}

fn end(at: At, axis: Axis, label: &'static str, action: Action) -> Handle {
    Handle { kind: Kind::End, at, axis, turn: 0.0, label, follows: true, action }
}

fn line_handles(doc: &Document<'_>, item: ItemRef<'_>, staff: &Staff, found: &mut Handles) {
    let Some(shape) = line::shape(doc, item) else { return };
    let step = staff.scale_step();
    let turn = f64::from(shape.rotation);
    let pivot = on_page(item.staff(), shape.left);
    let place = |p: Pos| turn_about(on_page(item.staff(), p), pivot, turn);
    let right = place(shape.right);
    found.handles.push(Handle {
        turn,
        ..end(pivot, Axis::Both, "Start", Action::Point { x: Some(3), y: Some(4), step, turn: 0.0, cue: false })
    });
    let right_y = shape.right_level.then_some(5);
    let axis = if shape.right_level { Axis::Both } else { Axis::X };
    found.handles.push(Handle {
        turn,
        ..end(right, axis, "End", Action::Point { x: Some(6), y: right_y, step, turn, cue: false })
    });
    if let Some((half, opens_right)) = shape.hairpin {
        let open = if opens_right { shape.right } else { shape.left };
        found.handles.push(Handle {
            kind: Kind::Adjust,
            at: place(Pos::new(open.x, open.y + half)),
            axis: Axis::Y,
            turn,
            label: "Opening",
            follows: true,
            action: Action::Opening { turn, step },
        });
        return;
    }
    for (param, at, label) in [(11, shape.left, "Start hook"), (12, shape.right, "End hook")] {
        let Some(length) = hook_length(item.p(param)) else { continue };
        found.handles.push(Handle {
            kind: Kind::Adjust,
            at: place(Pos::new(at.x, at.y + length * step)),
            axis: Axis::Y,
            turn,
            label,
            follows: true,
            action: Action::Hook { param, turn, step },
        });
    }
}

/// The signed length in scale steps of a bracket at a line's end (P11, P12),
/// `None` for no mark or an arrow.
fn hook_length(v: f32) -> Option<f64> {
    let v = f64::from(v);
    match v {
        0.0 => None,
        v if v <= 100.0 => Some(v),
        v if v < 200.0 => None,
        v => Some(-(v - 200.0)),
    }
}

fn slur_handles(doc: &Document<'_>, item: ItemRef<'_>, staff: &Staff, found: &mut Handles) {
    if item.p(6) == 0.0 {
        // draw_slur's defaults for a missing right end, written out so the ends move from there.
        found.prepared.push((6, item.p(3) + 20.0));
        if item.p(7) == 0.0 {
            found.prepared.push((7, 3.0));
        }
    }
    let prepared = item.with_params(&found.prepared);
    let item = item.changed(&prepared);
    let shape = slur::shape(doc, item);
    let step = staff.scale_step();
    let (left, right, peak) =
        (on_page(item.staff(), shape.left), on_page(item.staff(), shape.right), on_page(item.staff(), shape.peak));
    found.handles.push(end(
        left,
        Axis::Both,
        "Start",
        Action::Point { x: Some(3), y: Some(4), step, turn: 0.0, cue: false },
    ));
    found.handles.push(end(
        right,
        Axis::Both,
        "End",
        Action::Point { x: Some(6), y: Some(5), step, turn: 0.0, cue: false },
    ));
    let chord = sub(right, left);
    let length = dot(chord, chord).sqrt();
    let bracket = (1..=9).contains(&(item.p(8) as i32));
    let (action, label) = if bracket || length < 1.0 {
        (Action::Lift { param: 7, step }, "Height")
    } else {
        let along = At::new(chord.x / length, chord.y / length);
        let centre = if item.p(10) == 0.0 { 0.5 } else { f64::from(item.p(10)) };
        (Action::Curve { along, length, step, centre }, "Curve")
    };
    let (turn, axis) = if bracket { (0.0, Axis::Y) } else { (-chord.y.atan2(chord.x).to_degrees(), Axis::Both) };
    found.handles.push(Handle { kind: Kind::Adjust, at: peak, axis, turn, label, follows: true, action });
}

/// Beams: the ends of the edge at the stems move up and down, P4 and P5.
fn beam_handles(doc: &Document<'_>, item: ItemRef<'_>, staff: &Staff, found: &mut Handles) {
    let (left, right) = beam::ends(doc, item);
    let step = staff.scale_step();
    let point = |y, cue| Action::Point { x: None, y: Some(y), step, turn: 0.0, cue };
    found.handles.push(end(on_page(item.staff(), left), Axis::Y, "Left end", point(4, true)));
    found.handles.push(end(on_page(item.staff(), right), Axis::Y, "Right end", point(5, false)));
}

/// Trills, ottavas and pedal marks: the end of the line after the sign, P6.
fn trill_handles(doc: &Document<'_>, item: ItemRef<'_>, found: &mut Handles) {
    if item.p(6) == 0.0 {
        return;
    }
    let y = doc.position(item).y;
    let at = on_page(item.staff(), Pos::new(page::x(item.p(6)), y));
    let step = doc.staff_of(item).scale_step();
    found.handles.push(end(
        at,
        Axis::X,
        "Line end",
        Action::Point { x: Some(6), y: None, step, turn: 0.0, cue: false },
    ));
}

/// Staves: the left and right ends, the vertical place and the size.
fn staff_handles(doc: &Document<'_>, item: ItemRef<'_>, found: &mut Handles) {
    let Some(staff) = doc.staves.staff_for(item) else { return };
    if item.p(6) == 0.0 {
        found.prepared.push((6, 200.0));
    }
    let (first, count) = staff_code::drawn_lines(item.p(7));
    let line_y = |line: i32| staff.bottom + f64::from(2 * line) * staff.scale_step();
    let top = line_y(first + count - 1);
    let mid = (line_y(first) + top) / 2.0;
    let left = page::x(item.p(3));
    let right = page::x(if item.p(6) == 0.0 { 200.0 } else { item.p(6) });
    let at = |x, y| on_page(staff.number, Pos::new(x, y));
    let step = staff.scale_step();
    let point = |x| Action::Point { x: Some(x), y: None, step, turn: 0.0, cue: false };
    found.handles.push(end(at(left, mid), Axis::X, "Left end", point(3)));
    found.handles.push(end(at(right, mid), Axis::X, "Right end", point(6)));
    if item.p(10) == 0.0 {
        found.handles.push(Handle {
            kind: Kind::Adjust,
            at: at(left, top),
            axis: Axis::Y,
            turn: 0.0,
            label: "Place",
            follows: true,
            action: Action::Place { step },
        });
    }
    let param = if item.p(14) != 0.0 { 14 } else { 5 };
    found.handles.push(Handle {
        kind: Kind::Scale,
        at: at(right, top),
        axis: Axis::Y,
        turn: 0.0,
        label: "Staff size",
        follows: true,
        action: Action::StaffSize { bottom: at(right, staff.bottom).y, param },
    });
}

/// Barlines: the top reaches up to a higher staff, P4.
fn reach(doc: &Document<'_>, item: ItemRef<'_>, found: &mut Handles) {
    let (_, top, span) = barline::reach(doc, item);
    let low = item.staff();
    let highest = doc.staves.highest().unwrap_or(low).max(low + span - 1);
    let tops = (1..=highest - low + 1)
        .map(|s| {
            let changed = item.with_params(&[(4, s as f32), (11, if item.ip(4) == 999 { 0.0 } else { item.p(11) })]);
            on_page(low, barline::reach(doc, item.changed(&changed)).1).y
        })
        .collect();
    found.handles.push(Handle {
        kind: Kind::End,
        at: on_page(low, top),
        axis: Axis::Y,
        turn: 0.0,
        label: "Reach",
        follows: false,
        action: Action::Reach { tops, to_highest: item.ip(4) == 999 },
    });
}

fn text_handles(doc: &Document<'_>, item: ItemRef<'_>, found: &mut Handles) {
    let spec = FrameSpec { rotation: Some(9), edges: false, ..FrameSpec::sized(6, Some(7), true, 1.0) };
    let Some(box_) = frame(doc, item, spec, found) else { return };
    // The top side sets the height alone; the right side the spacing.
    let turn = f64::from(item.p(9));
    let centre = on_page(item.staff(), doc.position(item));
    let local = |x, y| turn_about(At::new(x, y), centre, turn);
    let anchor = centre;
    let sizes = Sizes { x: 6, y: Some(7), parts: true, zero: 1.0 };
    if box_.max.y - anchor.y > 0.25 * (box_.max.y - box_.min.y) {
        found.handles.push(Handle {
            kind: Kind::Scale,
            at: local((box_.min.x + box_.max.x) / 2.0, box_.max.y),
            axis: Axis::Y,
            turn,
            label: "Height",
            follows: true,
            action: Action::Scale {
                anchor,
                reference: anchor,
                turn,
                axis: Axis::Y,
                free: false,
                sizes,
                step: None,
                peers: Vec::new(),
            },
        });
    }
    if item.p(12) >= 2.0 {
        let unspread = item.with_params(&[(5, 0.0), (9, 0.0)]);
        let width = drawn_box(doc, item.changed(&unspread)).map_or(0.0, |b| b.max.x - b.min.x);
        if width > 0.0 {
            found.handles.push(Handle {
                kind: Kind::Adjust,
                at: local(box_.max.x, (box_.min.y + box_.max.y) / 2.0),
                axis: Axis::X,
                turn,
                label: "Spacing",
                follows: true,
                action: Action::Spacing { turn, width },
            });
        }
    }
}

// ---------------------------------------------------------------------------
// Frames: size and rotation handles around what an item draws

#[derive(Debug, Clone, Copy, PartialEq)]
struct FrameSpec {
    sizes: Sizes,
    rotation: Option<usize>,
    /// Sides as well as corners.
    edges: bool,
    /// Corners change width and height apart (Shift keeps the proportions).
    free: bool,
    /// The item moves so that the side or corner opposite the handle stays (boxes, drawn about their centre).
    moves: bool,
}

impl FrameSpec {
    fn sized(x: usize, y: Option<usize>, parts: bool, zero: f32) -> Self {
        Self { sizes: Sizes { x, y, parts, zero }, rotation: None, edges: y.is_some(), free: false, moves: false }
    }

    fn uniform(x: usize) -> Self {
        Self { edges: false, ..Self::sized(x, None, false, 1.0) }
    }
}

/// The box around what `item` draws, as rendered alone.
fn drawn_box(doc: &Document<'_>, item: ItemRef<'_>) -> Option<crate::hit::Bounds> {
    let mut list = DisplayList::default();
    render_item(doc, item, &mut list);
    list_bounds(&list)
}

/// Corner and side handles on the frame of the item drawn unturned, turned
/// with it about its reference point, and the rotation handle above it.
/// Returns the unturned frame.
fn frame(doc: &Document<'_>, item: ItemRef<'_>, spec: FrameSpec, found: &mut Handles) -> Option<crate::hit::Bounds> {
    let turn = spec.rotation.map_or(0.0, |n| f64::from(item.p(n)));
    let unturned = spec.rotation.map(|n| item.with_params(&[(n, 0.0)]));
    let box_ = drawn_box(doc, unturned.as_ref().map_or(item, |i| item.changed(i)))?;
    let reference = on_page(item.staff(), doc.position(item));
    let place = |x, y| turn_about(At::new(x, y), reference, turn);
    let corners = [
        At::new(box_.min.x, box_.min.y),
        At::new(box_.max.x, box_.min.y),
        At::new(box_.max.x, box_.max.y),
        At::new(box_.min.x, box_.max.y),
    ];
    found.frame = Some(corners.map(|c| place(c.x, c.y)));
    let (w, h) = (box_.max.x - box_.min.x, box_.max.y - box_.min.y);
    let mid = At::new((box_.min.x + box_.max.x) / 2.0, (box_.min.y + box_.max.y) / 2.0);
    let peers = peer_sizes(doc, item, &spec.sizes);
    let candidates = [
        (box_.min.x, box_.min.y, Axis::Both),
        (box_.max.x, box_.min.y, Axis::Both),
        (box_.max.x, box_.max.y, Axis::Both),
        (box_.min.x, box_.max.y, Axis::Both),
        (mid.x, box_.max.y, Axis::Y),
        (mid.x, box_.min.y, Axis::Y),
        (box_.min.x, mid.y, Axis::X),
        (box_.max.x, mid.y, Axis::X),
    ];
    for (x, y, axis) in candidates {
        if axis != Axis::Both && !spec.edges {
            continue;
        }
        if axis == Axis::Y && spec.sizes.y.is_none() {
            continue;
        }
        let opposite = At::new(box_.min.x + box_.max.x - x, box_.min.y + box_.max.y - y);
        let anchor = if spec.moves { opposite } else { reference };
        // A side through the anchor has nothing to scale against.
        let far = |d: f64, extent: f64| extent > 0.0 && d.abs() >= 0.25 * extent;
        let usable = match axis {
            Axis::Both => far(x - anchor.x, w) && far(y - anchor.y, h),
            Axis::X => far(x - anchor.x, w),
            Axis::Y => far(y - anchor.y, h),
        };
        if !usable {
            continue;
        }
        let step = spec.moves.then(|| doc.staff_of(item).scale_step());
        found.handles.push(Handle {
            kind: Kind::Scale,
            at: place(x, y),
            axis,
            turn,
            label: match axis {
                Axis::X => "Width",
                Axis::Y => "Height",
                Axis::Both => "Size",
            },
            follows: true,
            action: Action::Scale {
                anchor: place(anchor.x, anchor.y),
                reference,
                turn,
                axis,
                free: spec.free,
                sizes: spec.sizes,
                step,
                peers: peers.clone(),
            },
        });
    }
    if let Some(param) = spec.rotation {
        found.handles.push(Handle {
            kind: Kind::Rotate,
            at: place(mid.x, box_.max.y),
            axis: Axis::Both,
            turn,
            label: "Rotation",
            follows: false,
            action: Action::Rotate { centre: reference, param },
        });
    }
    Some(box_)
}

/// The sizes other items of the same code have, besides the default:
/// what a size handle snaps to.
fn peer_sizes(doc: &Document<'_>, item: ItemRef<'_>, sizes: &Sizes) -> Vec<f32> {
    let mut found: Vec<f32> = doc
        .items()
        .filter(|other| other.code() == item.code() && other.id != item.id)
        .map(|other| width_of(other.p(sizes.x), sizes).1)
        .filter(|&s| s > 0.0)
        .collect();
    if sizes.zero > 0.0 {
        found.push(sizes.zero);
    }
    found.sort_by(f32::total_cmp);
    found.dedup();
    found
}

/// The sign, part flags and size that a width parameter holds.
fn width_of(v: f32, sizes: &Sizes) -> (f32, f32, f32) {
    let (sign, parts, size) = if sizes.parts {
        let parts = parts_of(v);
        (if v < 0.0 { -1.0 } else { 1.0 }, parts, v.abs() - parts)
    } else {
        (1.0, 0.0, v)
    };
    (sign, parts, if size == 0.0 { sizes.zero } else { size })
}

// ---------------------------------------------------------------------------
// From travel to values

/// The smallest size a handle leaves.
const MIN_SIZE: f64 = 0.05;
/// Hairpin openings P7 = 0 and -1 stand for.
const DEFAULT_OPENING: f64 = 2.3;

impl Handle {
    /// The parameters after the cursor travelled `travel` from the grab,
    /// computed from the item's parameters `start` at the grab.
    pub fn apply(&self, start: &Draft, travel: &Travel) -> Adjusted {
        let mut d = sub(travel.to, travel.from);
        if travel.constrain && self.axis == Axis::Both && matches!(self.action, Action::Point { .. }) {
            let local = turn_vector(d, -self.turn);
            let kept = if local.x.abs() >= local.y.abs() { At::new(local.x, 0.0) } else { At::new(0.0, local.y) };
            d = turn_vector(kept, self.turn);
        }
        match &self.action {
            Action::Point { x, y, step, turn, cue } => {
                let local = turn_vector(d, -turn);
                let mut values = Vec::new();
                let mut words = vec![self.label.to_owned()];
                if let Some(n) = *x {
                    let p = rounded(f64::from(start.get(n)) + local.x / P3_UNIT, 0.01);
                    values.push((n, p));
                    words.push(format!("P{n} {}", num(f64::from(p))));
                }
                if let Some(n) = *y {
                    let level = rounded(level_of(start.get(n), *cue) + local.y / step, 0.01);
                    values.push((n, with_level(level, start.get(n), *cue)));
                    words.push(format!("level {}", num(f64::from(level))));
                }
                Adjusted { values, readout: words.join(" · ") }
            }
            Action::Scale { anchor, reference, turn, axis, free, sizes, step, peers } => {
                self.scale(start, travel, *anchor, *reference, *turn, *axis, *free, sizes, *step, peers)
            }
            Action::Rotate { centre, param } => {
                let clockwise = |v: At| -v.y.atan2(v.x).to_degrees();
                let (from, to) = (sub(travel.from, *centre), sub(travel.to, *centre));
                let mut angle = f64::from(start.get(*param)) + clockwise(to) - clockwise(from);
                angle = (angle + 180.0).rem_euclid(360.0) - 180.0;
                if travel.constrain {
                    angle = (angle / 15.0).round() * 15.0;
                } else {
                    let radius = dot(to, to).sqrt().max(1.0);
                    let slack = (travel.tolerance / radius).to_degrees();
                    let square = (angle / 45.0).round() * 45.0;
                    if (angle - square).abs() <= slack {
                        angle = square;
                    }
                }
                let angle = if angle.round() == -180.0 { 180.0 } else { angle.round() };
                Adjusted { values: vec![(*param, angle as f32)], readout: format!("Rotation {}°", num(angle)) }
            }
            Action::Curve { along, length, step, centre } => {
                let across = At::new(-along.y, along.x);
                let p7 = rounded(f64::from(start.get(7)) + dot(d, across) / step, 0.1);
                let mut values = vec![(7, p7)];
                let mut peak = (centre + dot(d, *along) / length).clamp(0.1, 0.9);
                if travel.constrain || ((peak - 0.5) * length).abs() <= travel.tolerance {
                    peak = if travel.constrain { *centre } else { 0.5 };
                }
                let stored = if (peak - 0.5).abs() < 1e-9 { 0.0 } else { rounded(peak, 0.01) };
                if stored != start.get(10) {
                    values.push((10, stored));
                }
                let shape = if p7 < 0.0 { "steps, curving down" } else { "steps" };
                let readout = format!("Curvature {} {shape} · peak at {} %", num(f64::from(p7)), num(peak * 100.0));
                Adjusted { values, readout }
            }
            Action::Lift { param, step } => {
                let v = rounded(f64::from(start.get(*param)) + d.y / step, 0.1);
                Adjusted { values: vec![(*param, v)], readout: format!("Height {} steps", num(f64::from(v))) }
            }
            Action::Opening { turn, step } => {
                let p7 = f64::from(start.get(7));
                let crescendo = p7 >= 0.0;
                let current = if p7 == 0.0 || p7 == -1.0 { DEFAULT_OPENING } else { p7.abs() };
                let half = current * step / 2.0 + turn_vector(d, -turn).y;
                let opening = (2.0 * half / step).max(0.2);
                let near_default = ((opening - DEFAULT_OPENING) * step / 2.0).abs() <= travel.tolerance;
                let (stored, shown) = if near_default {
                    (if crescendo { 0.0 } else { -1.0 }, DEFAULT_OPENING)
                } else {
                    let v = rounded(opening, 0.1);
                    (if crescendo { v } else { -v }, f64::from(v))
                };
                Adjusted { values: vec![(7, stored)], readout: format!("Opening {} steps", num(shown)) }
            }
            Action::Hook { param, turn, step } => {
                let length = hook_length(start.get(*param)).unwrap_or(0.0) + turn_vector(d, -turn).y / step;
                let length = f64::from(rounded(length, 0.5));
                let length =
                    if length == 0.0 { 0.5_f64.copysign(turn_vector(d, -turn).y) } else { length.clamp(-100.0, 100.0) };
                let side = if length > 0.0 { "up" } else { "down" };
                Adjusted {
                    values: vec![(*param, length as f32)],
                    readout: format!("Hook {} steps {side}", num(length.abs())),
                }
            }
            Action::Stem { per_step } => {
                let p8 = start.get(8);
                let slashed = p8.abs() >= 100.0;
                let extension = if slashed { p8 - 100.0f32.copysign(p8) } else { p8 };
                let v = rounded(f64::from(extension) + d.y / per_step, 0.5);
                let stored = if slashed { v + 100.0f32.copysign(if v < 0.0 { -1.0 } else { 1.0 }) } else { v };
                let readout = if v == 0.0 {
                    "Stem normal length".to_owned()
                } else {
                    format!("Stem {} steps", signed(f64::from(v)))
                };
                Adjusted { values: vec![(8, stored)], readout }
            }
            Action::Place { step } => {
                let v = rounded(f64::from(start.get(4)) + d.y / step, 0.01);
                Adjusted { values: vec![(4, v)], readout: format!("Staff place P4 {}", num(f64::from(v))) }
            }
            Action::StaffSize { bottom, param } => {
                let from = travel.from.y - bottom;
                let factor = if from.abs() < 1.0 { 1.0 } else { (travel.to.y - bottom) / from };
                let size = match (start.get(*param), *param) {
                    (0.0, _) => 1.0,
                    (v, _) => f64::from(v),
                };
                let mut v = (size * factor).max(0.2);
                if *param == 5 && ((v - 1.0) * from.abs()).abs() <= travel.tolerance {
                    v = 1.0;
                }
                let v = rounded(v, 0.01);
                let unit = if *param == 14 { " cm" } else { "" };
                Adjusted { values: vec![(*param, v)], readout: format!("Staff size {}{unit}", num(f64::from(v))) }
            }
            Action::Reach { tops, to_highest } => {
                let y = self.at.y + travel.to.y - travel.from.y;
                let span = (1..=tops.len())
                    .min_by(|&a, &b| (tops[a - 1] - y).abs().total_cmp(&(tops[b - 1] - y).abs()))
                    .unwrap_or(1);
                let value = if *to_highest && span == tops.len() { 999.0 } else { span as f32 };
                let value = if start.get(4) < 0.0 { -value } else { value };
                let staves = if span == 1 { "its own staff".to_owned() } else { format!("{span} staves") };
                Adjusted { values: vec![(4, value)], readout: format!("Reaches {staves}") }
            }
            Action::Spacing { turn, width } => {
                let spread = match start.get(5) {
                    0.0 => 1.0,
                    v => f64::from(v),
                };
                let mut v = (spread + turn_vector(d, -turn).x / (2.0 * width)).max(0.3);
                if ((v - 1.0) * 2.0 * width).abs() <= travel.tolerance {
                    v = 1.0;
                }
                let stored = if v == 1.0 { 0.0 } else { rounded(v, 0.01) };
                let shown = if v == 1.0 { "normal".to_owned() } else { num(f64::from(stored)) };
                Adjusted { values: vec![(5, stored)], readout: format!("Spacing {shown}") }
            }
        }
    }

    #[allow(clippy::too_many_arguments)]
    fn scale(
        &self,
        start: &Draft,
        travel: &Travel,
        anchor: At,
        reference: At,
        turn: f64,
        axis: Axis,
        free: bool,
        sizes: &Sizes,
        step: Option<f64>,
        peers: &[f32],
    ) -> Adjusted {
        let grab = turn_vector(sub(travel.from, anchor), -turn);
        let now = turn_vector(sub(travel.to, anchor), -turn);
        let ratio = |a: f64, b: f64| if b.abs() < 1e-6 { 1.0 } else { a / b };
        let uniform = || ratio(dot(now, grab), dot(grab, grab));
        let (mut fx, mut fy) = match axis {
            Axis::X => (ratio(now.x, grab.x), 1.0),
            Axis::Y => (1.0, ratio(now.y, grab.y)),
            Axis::Both if free && !travel.constrain => (ratio(now.x, grab.x), ratio(now.y, grab.y)),
            Axis::Both => (uniform(), uniform()),
        };
        let (sign, parts, width) = width_of(start.get(sizes.x), sizes);
        let height_stored = sizes.y.map(|n| start.get(n)).unwrap_or(0.0);
        let height = if height_stored == 0.0 { width } else { height_stored };
        let (width, height) = (f64::from(width), f64::from(height));
        let proportional = axis == Axis::Both && (!free || travel.constrain);
        if proportional && width > 0.0 {
            // A size another item of this code has, or the default, is hard to miss.
            let reach = dot(grab, grab).sqrt();
            let size = width * fx;
            if let Some(&peer) =
                peers.iter().min_by(|a, b| (f64::from(**a) - size).abs().total_cmp(&(f64::from(**b) - size).abs()))
            {
                if (f64::from(peer) - size).abs() / size.max(1e-6) * reach <= travel.tolerance {
                    fx = f64::from(peer) / width;
                    fy = fx;
                }
            }
        }
        let floor = |base: f64, f: f64| if base > 0.0 { f.max(MIN_SIZE / base) } else { f.max(0.0) };
        fx = floor(width, fx);
        fy = floor(height, fy);
        let new_width = rounded(width * fx, 0.01);
        let new_height = rounded(height * fy, 0.01);
        let mut values = Vec::new();
        let mut words = Vec::new();
        if axis != Axis::Y {
            values.push((sizes.x, sign * (parts + new_width)));
        }
        if let Some(n) = sizes.y {
            match axis {
                Axis::X if height_stored == 0.0 => values.push((n, height as f32)),
                Axis::X => {}
                _ if proportional && height_stored == 0.0 => {}
                _ => values.push((n, new_height)),
            }
        }
        let shown_height = values.iter().find(|(n, _)| Some(*n) == sizes.y).map(|&(_, v)| v);
        match (axis, shown_height) {
            (Axis::Y, Some(h)) => words.push(format!("Height {}", num(f64::from(h)))),
            (_, Some(h)) if proportional => {
                words.push(format!("Size {} × {}", num(f64::from(new_width)), num(f64::from(h))))
            }
            (_, Some(h)) => words.push(format!("Width {} · height {}", num(f64::from(new_width)), num(f64::from(h)))),
            (Axis::X, None) => words.push(format!("Width {}", num(f64::from(new_width)))),
            _ => words.push(format!("Size {}", num(f64::from(new_width)))),
        }
        if proportional && peers.contains(&new_width) && f64::from(new_width) != width {
            words.push(if new_width == sizes.zero { "default".into() } else { "as another".into() });
        }
        if let Some(step) = step {
            // The reference moves so that the anchor stays.
            let offset = turn_vector(sub(reference, anchor), -turn);
            let gx = if width > 0.0 { f64::from(new_width) / width } else { fx };
            let gy = if height > 0.0 { f64::from(shown_height.unwrap_or(new_height)) / height } else { fy };
            let gy = if axis == Axis::X { 1.0 } else { gy };
            let gx = if axis == Axis::Y { 1.0 } else { gx };
            let moved = turn_vector(At::new(offset.x * (gx - 1.0), offset.y * (gy - 1.0)), turn);
            values.push((3, rounded(f64::from(start.get(3)) + moved.x / P3_UNIT, 0.01)));
            values.push((4, rounded(f64::from(start.get(4)) + moved.y / step, 0.01)));
        }
        Adjusted { values, readout: words.join(" · ") }
    }
}

/// The handles as JSON for the shell: `{"frame": [[x, y] ×4] | null,
/// "handles": [{"kind", "x", "y", "axis", "turn", "label", "follows"}]}`.
pub fn to_json(found: &Handles) -> String {
    let point = |p: At| json!([p.x, p.y]);
    let handles: Vec<Value> = found
        .handles
        .iter()
        .map(|h| {
            json!({
                "kind": h.kind.name(),
                "x": h.at.x,
                "y": h.at.y,
                "axis": h.axis.name(),
                "turn": h.turn,
                "label": h.label,
                "follows": h.follows,
            })
        })
        .collect();
    json!({ "frame": found.frame.map(|f| f.map(point).to_vec()), "handles": handles }).to_string()
}

// ---------------------------------------------------------------------------
// The shell's side

/// A drag of one handle: the item, the handle as it was worked out when
/// the drag took hold, the item's parameters then, and the grab point.
#[derive(Debug, Clone, PartialEq)]
pub struct Grab {
    handle: Handle,
    start: Draft,
    prepared: Vec<(usize, f32)>,
    from: At,
}

#[wasm_bindgen]
impl Score {
    /// The handles of item `index` as JSON (see [`to_json`]); their order
    /// numbers them for [`Score::handle_begin`].
    pub fn handles(&self, index: u32) -> String {
        to_json(&handles(self.0.file(), index as usize))
    }

    /// Takes hold of handle `handle` of item `index` at page point (`x`,
    /// `y`); false if the item has no such handle.
    #[wasm_bindgen(js_name = handleBegin)]
    pub fn handle_begin(&mut self, index: u32, handle: u32, x: f64, y: f64) -> Result<bool, JsError> {
        let found = handles(self.0.file(), index as usize);
        let Some(chosen) = found.handles.get(handle as usize).cloned() else { return Ok(false) };
        let id = self.0.id(ItemId(index))?;
        self.0.editor_mut().adjust_begin(id)?;
        let mut start =
            Draft::of(self.0.editor().adjust_start().map(|(_, item)| item).ok_or_else(|| JsError::new("no item"))?);
        found.prepared.iter().for_each(|&(n, v)| start.set(n, v));
        self.0.grab = Some(Grab { handle: chosen, start, prepared: found.prepared, from: At::new(x, y) });
        Ok(true)
    }

    /// Drags the held handle to page point (`x`, `y`) and sets what it
    /// changes, without an undo step. `constrain` is Shift (one axis,
    /// proportions, 15° steps); `tolerance` (page units) is how near a
    /// default or a matching value pulls. Returns the words for the values.
    #[wasm_bindgen(js_name = handleTo)]
    pub fn handle_to(&mut self, x: f64, y: f64, constrain: bool, tolerance: f64) -> String {
        let Some(grab) = &self.0.grab else { return String::new() };
        let travel = Travel { from: grab.from, to: At::new(x, y), constrain, tolerance };
        let adjusted = grab.handle.apply(&grab.start, &travel);
        let values: Vec<(usize, f32)> = grab.prepared.iter().copied().chain(adjusted.values).collect();
        self.0.editor_mut().adjust_to(&values);
        adjusted.readout
    }

    /// Ends a handle drag; `commit` keeps the values as one undo step named
    /// after the handle ("Size", "Rotation", "Curve" …).
    #[wasm_bindgen(js_name = handleEnd)]
    pub fn handle_end(&mut self, commit: bool) -> Outcome {
        let Some(grab) = self.0.grab.take() else { return Outcome::default() };
        let change = self.0.editor_mut().adjust_end(commit, grab.handle.label);
        if commit {
            Outcome { label: self.0.label(&change).unwrap_or_default(), message: change.message.clone() }
        } else {
            Outcome::default()
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use score_format::{Item, Word};

    /// One scale step on a size-1 staff.
    const STEP: f64 = 175.0;

    fn file_with(items: &[&[f32]]) -> MusFile {
        let mut file = MusFile::empty();
        file.items = items.iter().map(|p| Item::new(p.iter().map(|&v| Word::from_f32(v)).collect())).collect();
        file
    }

    fn handle<'a>(found: &'a Handles, label: &str) -> &'a Handle {
        found
            .handles
            .iter()
            .find(|h| h.label == label)
            .unwrap_or_else(|| panic!("a {label} handle in {:?}", found.handles))
    }

    fn drag(file: &MusFile, index: usize, h: &Handle, by: (f64, f64)) -> Vec<(usize, f32)> {
        let found = handles(file, index);
        let mut start = Draft::of(&file.items[index]);
        found.prepared.iter().for_each(|&(n, v)| start.set(n, v));
        let travel = Travel { from: h.at, to: At::new(h.at.x + by.0, h.at.y + by.1), constrain: false, tolerance: 1.0 };
        h.apply(&start, &travel).values
    }

    fn value(values: &[(usize, f32)], n: usize) -> f32 {
        values.iter().rev().find(|(m, _)| *m == n).unwrap_or_else(|| panic!("P{n} in {values:?}")).1
    }

    const STAFF: &[f32] = &[8.0, 1.0, 0.0];

    #[test]
    fn a_box_grows_from_the_side_opposite_the_handle() {
        let file = file_with(&[STAFF, &[12.0, 1.0, 50.0, 10.0, 0.0, 2.0, 1.0]]);
        let found = handles(&file, 1);
        assert!(found.frame.is_some());
        assert_eq!(found.handles.iter().filter(|h| h.kind == Kind::Scale).count(), 8);
        let right = found.handles.iter().find(|h| h.label == "Width" && h.at.x > 2000.0 + 50.0 * 150.0).unwrap();
        let [a, b, ..] = found.frame.unwrap();
        let width = b.x - a.x;
        let values = drag(&file, 1, right, (width, 0.0));
        assert!((value(&values, 6) - 4.0).abs() < 0.2, "{values:?}");
        assert!((f64::from(value(&values, 3)) - (50.0 + width / 2.0 / 150.0)).abs() < 0.05, "{values:?}");
        assert!((value(&values, 4) - 10.0).abs() < 0.01);
    }

    #[test]
    fn the_rotation_handle_turns_clockwise_and_rests_on_right_angles() {
        let file = file_with(&[STAFF, &[12.0, 1.0, 50.0, 10.0, 0.0, 2.0, 1.0]]);
        let found = handles(&file, 1);
        let h = handle(&found, "Rotation");
        let Action::Rotate { centre, .. } = h.action else { panic!() };
        let r = h.at.y - centre.y;
        let values = drag(&file, 1, h, (r + 3.0, -r));
        assert_eq!(value(&values, 9), 90.0);
        let values = drag(&file, 1, h, (r * 0.5, -r * 0.2));
        assert_ne!(value(&values, 9) % 45.0, 0.0);
    }

    #[test]
    fn slur_ends_and_curve_follow_the_cursor() {
        let file = file_with(&[STAFF, &[5.0, 1.0, 10.0, 9.0, 9.0, 40.0, 3.0]]);
        let found = handles(&file, 1);
        let values = drag(&file, 1, handle(&found, "Start"), (150.0, 2.0 * STEP));
        assert_eq!((value(&values, 3), value(&values, 4)), (11.0, 11.0));
        let values = drag(&file, 1, handle(&found, "End"), (-300.0, -STEP));
        assert_eq!((value(&values, 6), value(&values, 5)), (38.0, 8.0));
        let values = drag(&file, 1, handle(&found, "Curve"), (0.5, STEP));
        assert_eq!(value(&values, 7), 4.0);
        assert!(values.iter().all(|(n, _)| *n != 10), "a small sideways slip keeps the peak centred: {values:?}");
        let values = drag(&file, 1, handle(&found, "Curve"), (30.0 * 150.0 * 0.2, 0.0));
        assert!((value(&values, 10) - 0.7).abs() < 0.011, "{values:?}");
    }

    #[test]
    fn a_slur_without_a_right_end_gets_draw_slurs_defaults_first() {
        let file = file_with(&[STAFF, &[5.0, 1.0, 10.0, 9.0, 9.0]]);
        let found = handles(&file, 1);
        assert_eq!(found.prepared, [(6, 30.0), (7, 3.0)]);
        let values = drag(&file, 1, handle(&found, "End"), (150.0, 0.0));
        assert_eq!(value(&values, 6), 31.0);
    }

    #[test]
    fn a_stem_grows_by_scale_steps() {
        let file = file_with(&[STAFF, &[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.0]]);
        let found = handles(&file, 1);
        let values = drag(&file, 1, handle(&found, "Stem"), (0.0, 2.0 * STEP));
        assert_eq!(value(&values, 8), 2.0);
        let down = file_with(&[STAFF, &[1.0, 1.0, 100.0, 9.0, 20.0, 0.0, 1.0]]);
        let found = handles(&down, 1);
        let values = drag(&down, 1, handle(&found, "Stem"), (0.0, 2.0 * STEP));
        assert_eq!(value(&values, 8), -2.0);
    }

    #[test]
    fn a_hairpin_opens_from_its_open_end() {
        let file = file_with(&[STAFF, &[4.0, 1.0, 50.0, -3.0, 999.0, 80.0, 0.0]]);
        let found = handles(&file, 1);
        assert_eq!(handle(&found, "End").axis, Axis::X);
        let opening = handle(&found, "Opening");
        assert!(opening.at.x > 2000.0 + 70.0 * 150.0, "a crescendo opens at its right end");
        let values = drag(&file, 1, opening, (0.0, STEP / 2.0));
        assert!((value(&values, 7) - 3.3).abs() < 1e-5, "{values:?}");
        let values = drag(&file, 1, opening, (0.0, 0.3));
        assert_eq!(value(&values, 7), 0.0, "near the default opening it stays the default");
    }

    #[test]
    fn a_barline_reaches_the_staff_top_nearest_the_cursor() {
        let file = file_with(&[STAFF, &[8.0, 2.0, 0.0], &[8.0, 3.0, 0.0], &[14.0, 1.0, 100.0, 1.0]]);
        let found = handles(&file, 3);
        let reach = handle(&found, "Reach");
        let values = drag(&file, 3, reach, (0.0, 2.0 * 3150.0 + 100.0));
        assert_eq!(value(&values, 4), 3.0);
        let values = drag(&file, 3, reach, (0.0, -5000.0));
        assert_eq!(value(&values, 4), 1.0);
    }

    #[test]
    fn a_staff_moves_and_scales_about_its_bottom_line() {
        let file = file_with(&[&[8.0, 1.0, 0.0, 0.0]]);
        let found = handles(&file, 0);
        assert_eq!(found.prepared, [(6, 200.0)]);
        let values = drag(&file, 0, handle(&found, "Place"), (0.0, 2.0 * STEP));
        assert_eq!(value(&values, 4), 2.0);
        let size = handle(&found, "Staff size");
        let values = drag(&file, 0, size, (0.0, -4.0 * STEP));
        assert_eq!(value(&values, 5), 0.5);
        let values = drag(&file, 0, handle(&found, "Right end"), (-150.0 * 20.0, 0.0));
        assert_eq!(value(&values, 6), 180.0);
    }

    /// Every handle of every item of the bundled samples sits on finite
    /// coordinates and gives finite values for a drag in any direction.
    #[test]
    fn every_sample_item_has_sound_handles() {
        let root = std::path::PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../assets/samples");
        let mut kinds = std::collections::BTreeSet::new();
        for name in ["mozart.mus", "carmen.mus", "sonlcs.mus", "000.mus"] {
            let file = MusFile::parse(&std::fs::read(root.join(name)).unwrap()).unwrap();
            for index in 0..file.items.len() {
                let found = handles(&file, index);
                for h in &found.handles {
                    assert!(h.at.x.is_finite() && h.at.y.is_finite(), "{name} item {index}: {h:?}");
                    kinds.insert((file.items[index].code(), h.label));
                    for by in [(400.0, 300.0), (-250.0, -500.0), (0.0, 0.0)] {
                        for (n, v) in drag(&file, index, h, by) {
                            assert!(
                                v.is_finite() && (1..=45).contains(&n),
                                "{name} item {index} {}: P{n} = {v}",
                                h.label
                            );
                        }
                    }
                }
            }
        }
        for expected in [(1, "Stem"), (5, "Curve"), (6, "Left end"), (8, "Place"), (14, "Reach"), (16, "Rotation")] {
            assert!(kinds.contains(&expected), "{expected:?} among {kinds:?}");
        }
    }

    #[test]
    fn handles_cross_as_json() {
        let file = file_with(&[STAFF, &[5.0, 1.0, 10.0, 9.0, 9.0, 40.0, 3.0]]);
        let json: Value = serde_json::from_str(&to_json(&handles(&file, 1))).unwrap();
        assert_eq!(json["handles"][0]["kind"], "end");
        assert_eq!(json["handles"][2]["label"], "Curve");
        assert!(json["frame"].is_null());
    }
}
