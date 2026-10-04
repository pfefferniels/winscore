//! Ledger lines (0x4F0871).
//!
//! Lines run from 5 units left of the head to 5 units beyond its right edge,
//! one scale step of the staff apart in pairs (every second level), from the
//! line nearest the note towards the staff. P30 overrides where they start
//! and which way they go. They are flushed on their own, in the staff's
//! colour unless P27 asks for the note's.

use super::Note;
use crate::canvas::{Canvas, Pen};
use crate::colour;
use crate::document::{Document, ItemRef};
use crate::units::{constant, real, trunc, Pos};

/// Ledger lines extend this many units beyond the head on each side.
const OVERHANG: f32 = 5.0;

/// The lowest and the highest level that never needs a ledger line.
const BELOW_STAFF: i32 = 1;
const ABOVE_STAFF: i32 = 13;

/// Which levels get a line: `first`, `first + step`, … up to the note's level.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Run {
    first: i32,
    step: i32,
    last: i32,
    /// y of the first line drawn and the distance to the next.
    y: f64,
    dy: f64,
}

impl Run {
    fn count(&self) -> i32 {
        (self.last - self.first + self.step) / self.step
    }
}

/// Whether draw_note calls the ledger routine at all.
pub fn wanted(note: &Note, item: ItemRef<'_>) -> bool {
    let p30 = trunc(f64::from(item.p(30)));
    let suppressed = trunc(f64::from(item.p(7))) <= -2;
    p30 != 0 || (!suppressed && (note.level <= BELOW_STAFF || note.level >= ABOVE_STAFF || note.ledger_start != 0))
}

pub fn draw(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let Some(run) = run(note, trunc(f64::from(item.p(30)))) else { return };
    let overhang = real(note.unit * constant(OVERHANG));
    let left = real(note.origin.x - overhang);
    let right = real(note.head_width + note.origin.x + overhang);
    (0..run.count()).fold(run.y, |y, _| {
        canvas.point(Pos::new(left, y), Pen::Stroke);
        canvas.point(Pos::new(right, y), Pen::Continue);
        real(run.dy + y)
    });
    flush_in_staff_colour(doc, item, canvas);
}

/// The lines for P30 = `p30` (0: by the note's level), or None for P30 < 0.
fn run(note: &Note, p30: i32) -> Option<Run> {
    if p30 < 0 {
        return None;
    }
    let pair = real(-note.scale_step - note.scale_step);
    let level = note.level;
    let y = note.origin.y;
    let (first, step, pair) = if level <= BELOW_STAFF {
        (BELOW_STAFF, -2, -pair)
    } else if note.ledger_start != 0 {
        (note.ledger_start * 2 + 3, 2, pair)
    } else {
        (ABOVE_STAFF, 2, pair)
    };
    if p30 == 0 {
        let on_space = level % 2 == 0;
        let offset = if on_space { real(pair / 2.0) } else { 0.0 };
        return Some(Run { first, step, last: level, y: real(offset + y), dy: pair });
    }
    let scale_step = real(note.step * 7.0);
    let up = real(scale_step + y);
    let down = real(y - scale_step);
    let run = |first, step, y, dy| Some(Run { first, step, last: level, y, dy });
    match p30 {
        1 => run(level, step, y, pair),
        2 => run(level, step, up, pair),
        3 => run(level, step, down, pair),
        _ => {
            let count = p30 % 10;
            let lines = |y, dy| Some(Run { first: 1, step: 1, last: count, y, dy });
            match p30 / 10 {
                1 => lines(y, pair.abs()),
                2 => lines(up, pair.abs()),
                _ if p30 >= 40 => lines(y, -pair.abs()),
                _ => lines(down, -pair.abs()),
            }
        }
    }
}

/// Ledger lines go out before the rest of the note, in the staff's colour
/// when the note has its own and P27 is 0.
fn flush_in_staff_colour(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let staff_p26 = doc.staff_of(item).source.and_then(|id| doc.item(id)).map_or(0.0, |staff| staff.p(26));
    if item.p(26) == staff_p26 || trunc(f64::from(item.p(27))) != 0 {
        canvas.flush();
        return;
    }
    let own = canvas.colour;
    canvas.colour = colour::from_p26(staff_p26, doc.options.medium);
    canvas.flush();
    canvas.colour = own;
}
