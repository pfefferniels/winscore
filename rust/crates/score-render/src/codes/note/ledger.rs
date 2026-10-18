//! Ledger lines (0x4F0871).
//!
//! Lines run from 5 units left of the head to 5 units beyond its right edge,
//! one scale step of the staff apart in pairs (every second level), from the
//! line nearest the note towards the staff. P30 overrides where they start
//! and which way they go. They are flushed on their own, in the staff's
//! colour unless P27 asks for the note's, and drawn thicker than the staff
//! lines (P16), as SCORE prints them.

use super::Note;
use crate::canvas::{Canvas, Pen};
use crate::colour;
use crate::display::print_pen;
use crate::document::{Document, ItemRef};
use crate::units::{constant, real, trunc, Pos};

/// Ledger lines extend this many units beyond the head on each side.
const OVERHANG: f32 = 5.0;

/// P16 = 99 (and a staff's P11 = 99): the staff lines' own pen.
const STAFF_PEN: i32 = 99;
/// Staves smaller than this with P11 = 0 print their lines one step thinner.
const SMALL_STAFF: f32 = 0.65;

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
    let width = print_width(doc, item, note);
    if width != 0 {
        // Until the flush below.
        canvas.set_width(print_pen(width as f32));
    }
    (0..run.count()).fold(run.y, |y, _| {
        canvas.point(Pos::new(left, y), Pen::Stroke);
        canvas.point(Pos::new(right, y), Pen::Continue);
        real(run.dy + y)
    });
    flush_in_staff_colour(doc, item, canvas);
}

/// The print-width marker SCORE prints ledger lines with (0x50DDF0, from
/// 0x4F0871 when printing), in 1/600 inch beyond the default pen: trunc(P16),
/// or with P16 = 0 two more than the staff lines (one more for a grace
/// note), P16 = 99 as much as they; 0 for no marker. The staff lines' value
/// is the staff's P11, or -1 for P11 = 0 on a staff smaller than 0.65
/// (draw_staff 0x545140). The engine reads it one entry too low, from the
/// staff numbered one less; this takes the note's own staff.
fn print_width(doc: &Document<'_>, item: ItemRef<'_>, note: &Note) -> i32 {
    let staff = doc.staff_of(item);
    let p11 = staff.source.and_then(|id| doc.item(id)).map_or(0, |staff| trunc(f64::from(staff.p(11))));
    let staff_lines = if p11 == 0 && staff.size < constant(SMALL_STAFF) { -1 } else { p11 };
    match trunc(f64::from(item.p(16))) {
        0 | STAFF_PEN if staff_lines == STAFF_PEN => 0,
        0 if note.unit != note.step => staff_lines + 1,
        0 => staff_lines + 2,
        STAFF_PEN => staff_lines,
        p16 => p16,
    }
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
    canvas.colour = colour::of(staff_p26, doc.options.medium);
    canvas.flush();
    canvas.colour = own;
}
