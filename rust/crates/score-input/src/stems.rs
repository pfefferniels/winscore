//! The stem fitting, run on the stored items after IN and after a refit: every note
//! under a beam of the staff whose stem goes the beam's way gets the stem length (P8) that
//! reaches the beam, and loses its flags (the units digit of P9).

use score_format::{Item, Word};

use crate::num::{amod, par, trunc};
use crate::staves::Neighbours;

const NOTE: i32 = 1;
const BEAM: i32 = 6;
/// Head width in staff steps; up stems stand this far right of the note's P3.
const HEAD_WIDTH: f32 = 2.83333;
/// Stems of grace and cue notes are drawn at this fraction of the normal length.
const SMALL_STEM: f32 = 0.6;
/// The x range the stem fitting takes beams from (P3), as the input routines call it.
const BEAMS_FROM: f32 = 1.0;
const BEAMS_TO: f32 = 200.0;
/// A note this far outside a beam's ends still counts as under it.
const REACH: f32 = 0.1;

/// The stems on `staff` (staff step `step`, staves around it `neighbours`) fitted to the
/// staff's beams, on items.
pub(crate) fn fit_items(items: &[Item], staff: i32, step: f32, neighbours: Neighbours) -> Vec<Item> {
    let mut rows: Vec<Vec<f32>> = items.iter().map(|it| it.params().iter().map(|w| w.as_f32()).collect()).collect();
    fit(&mut rows, staff, step, neighbours);
    items
        .iter()
        .zip(rows)
        .map(|(item, row)| {
            let params: Vec<Word> = row.into_iter().map(Word::from_f32).collect();
            if params == item.params() {
                item.clone()
            } else {
                Item::new(params)
            }
        })
        .collect()
}

/// The stem fitting on parameter rows: the beams of `staff` with P3 in 1..200, in item order,
/// each fitting the notes in its x range.
pub(crate) fn fit(rows: &mut [Vec<f32>], staff: i32, step: f32, neighbours: Neighbours) {
    let beams: Vec<Vec<f32>> = rows
        .iter()
        .filter(|r| trunc(par(r, 1)) == BEAM && r.len() >= 7 && trunc(par(r, 2)) == staff)
        .filter(|r| (BEAMS_FROM..=BEAMS_TO).contains(&par(r, 3)))
        .cloned()
        .collect();
    for beam in &beams {
        for note in rows.iter_mut() {
            if let Some(length) = under_beam(beam, note, step, neighbours) {
                fit_note(note, length);
            }
        }
    }
}

/// The stem length a note gets from `beam`, if it is one the beam fits.
fn under_beam(beam: &[f32], note: &[f32], step: f32, neighbours: Neighbours) -> Option<f32> {
    if note.len() <= 4 || trunc(par(note, 1)) != NOTE || trunc(par(note, 2)) != trunc(par(beam, 2)) {
        return None;
    }
    let x = f64::from(par(note, 3));
    if !(f64::from(par(beam, 3)) - f64::from(REACH) <= x && x <= f64::from(par(beam, 6)) + f64::from(REACH)) {
        return None;
    }
    let direction = trunc(amod(par(note, 5), 100.0) / 10.0);
    let small = |p4: f32| trunc(p4 / 100.0).abs();
    let same_way = direction != 0 && par(note, 6) != 1.0 && trunc(par(beam, 7)) / 10 == direction;
    if !same_way || small(par(beam, 4)) != small(par(note, 4)) {
        return None;
    }
    // A note moved to another staff (P12) is measured from that staff; a staff that
    // cannot exist counts as none.
    let placement = match trunc(par(note, 12)) {
        1 => neighbours.above,
        2 => neighbours.below,
        _ => None,
    };
    let mut moved = note.to_vec();
    moved[3] = amod(par(note, 4), 100.0) + placement.unwrap_or(0.0);
    Some(stem_length(beam, &moved, direction == 1, step))
}

fn fit_note(note: &mut Vec<f32>, length: f32) {
    if note.len() < 8 {
        note.resize(8, 0.0);
    }
    let length = if note.len() > 14 && note[14] != 0.0 { length / note[14] } else { length };
    note[7] = length;
    if note.len() > 8 && note[8] != 0.0 {
        let tails = trunc(amod(note[8], 10.0));
        note[8] -= tails as f32;
    }
}

/// For a note whose stem goes the beam's way (`up` for both): the length from the
/// note's head to the beam, with the head-width moves the engine makes before it
/// interpolates (they show in the last bits).
fn stem_length(beam: &[f32], note: &[f32], up: bool, step: f32) -> f32 {
    let b = |k: usize| par(beam, k);
    let scale = if trunc(b(4) / 100.0).abs() > 0 { SMALL_STEM } else { 1.0 };
    let width = ((f64::from(scale) * f64::from(HEAD_WIDTH) * f64::from(step)) / 25.0) as f32;
    let side = |v: f32| match v {
        10.0 => width,
        20.0 => -width,
        other => other,
    };
    let unset = |v: f32, x: f32| if v == -1.0 { x } else { v };
    let (ip10, ip13) = (trunc(b(10)), trunc(b(13)));
    let (mut x1, mut x2) = (b(3), b(6));
    let (mut p11, mut p12, mut p14, mut p15) = (unset(b(11), x1), unset(b(12), x2), unset(b(14), x1), unset(b(15), x2));
    let shift = |v: &mut f32| {
        if *v != 0.0 {
            *v += width;
        }
    };
    if up {
        x1 += width;
        x2 += width;
    }
    let mut lower_first = 0.0f32;
    if ip10 != 0 {
        if up {
            shift(&mut p11);
            shift(&mut p12);
        }
        if ip10 < 0 && p11 != 0.0 && p12 != 0.0 {
            lower_first = -((ip10 / 10) as f32) * 1.5;
        }
    }
    let mut lower_second = 0.0f32;
    if ip13 == 0 {
        x1 += side(p14);
        x2 += side(p15);
    } else {
        if up {
            shift(&mut p14);
            shift(&mut p15);
        }
        if ip13 < 0 && p14 != 0.0 && p15 != 0.0 {
            lower_second = -((ip13 / 10) as f32) * 1.5;
        }
    }
    let mut x = par(note, 3);
    if up {
        x += width;
    }
    if par(note, 10) != 0.0 {
        x += side(par(note, 10));
    }
    if beam.len() > 8 {
        let digits = trunc(b(9));
        let moved = if up { -width } else { width };
        let apply = |digit: i32, first: &mut f32, second: &mut f32| {
            if digit == 1 || digit == 3 {
                *first += moved;
            }
            if digit == 2 || digit == 3 {
                *second += moved;
            }
        };
        apply(digits / 100, &mut x1, &mut x2);
        apply(digits % 100 / 10, &mut p11, &mut p12);
        apply(digits % 10, &mut p14, &mut p15);
    }
    let span = x2 - x1;
    let level = amod(par(note, 4), 100.0);
    let (mut start, mut end) = (amod(b(4), 100.0) - level, b(5) - level);
    if !up {
        start = -start;
        end = -end;
    }
    let from = x - x1;
    let reach = ((f64::from(from) / f64::from(span)) * (f64::from(end) - f64::from(start)) + f64::from(start)) as f32;
    let within = |x: f32, a: f32, b: f32| f64::from(x) < f64::from(b) + f64::from(REACH) && f64::from(a) - f64::from(REACH) < f64::from(x);
    let mut lowered = 0.0f32;
    if ip10 < 0 && within(x, p11, p12) {
        lowered = lower_first;
    }
    if lowered < lower_second && ip13 < 0 && within(x, p14, p15) {
        lowered = lower_second;
    }
    (f64::from(lowered) + f64::from(reach) / f64::from(scale)) as f32
}
