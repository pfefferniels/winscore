//! Pass 4: beams as code-6 items, and the stems of the beamed notes.
//!
//! Beam routine of the engine: 0x413CA8; stems of beamed notes: 0x40CDE4.

use crate::connect::{ConnectEntry, Connection, Side};
use crate::error::InputError;
use crate::line::{item, Line, Note, MIDDLE_LINE};

/// Lowest beam end (in note-level terms) for stems up, highest for stems down: the stems
/// must reach the middle line.
const UP_FLOOR: f32 = (MIDDLE_LINE - 7) as f32;
const DOWN_CEILING: f32 = (MIDDLE_LINE + 7) as f32;
/// Beams in a group that fit an octave stem; each further one lengthens the stems by a step.
const BEAMS_IN_OCTAVE_STEM: i32 = 2;

/// The notes of `xB`/`xBy` groups: after `pickup` notes, windows of `eighths` eighth notes,
/// each beaming its runs of two or more notes shorter than a quarter.
fn every_eighths(line: &Line, eighths: u32, pickup: u32) -> Vec<Connection> {
    #[derive(Clone, Copy)]
    struct Slot {
        number: usize,
        window: i64,
        beamable: bool,
    }
    let window = eighths as f32 * 0.5;
    let slots: Vec<Slot> = line
        .notes()
        .enumerate()
        .skip(pickup as usize)
        .scan(0.0f32, |time, (i, note)| {
            let window_index = (*time / window).floor() as i64;
            *time += note.rhythm.quarters();
            Some(Slot { number: i + 1, window: window_index, beamable: note.tails > 0 && !note.is_grace() })
        })
        .collect();
    slots
        .chunk_by(|a, b| a.window == b.window && a.beamable && b.beamable)
        .filter(|run| run.len() >= 2)
        .map(|run| Connection { first: run[0].number, last: run[run.len() - 1].number, side: None, tuplet: 0 })
        .collect()
}

fn reference(note: &Note, down: bool) -> f32 {
    if down {
        note.lowest() as f32
    } else {
        note.highest() as f32
    }
}

/// Secondary beam segments as (code, left x, right x); 0 marks the open side of a stub.
fn secondary_segments(notes: &[&Note], main: i32) -> Vec<(f32, f32, f32)> {
    let deepest = notes.iter().map(|n| n.tails).max().unwrap_or(main);
    let last = notes.len() - 1;
    (main + 1..=deepest)
        .flat_map(|level| {
            let runs = notes.iter().enumerate().fold(Vec::<(usize, usize)>::new(), |mut runs, (i, n)| {
                if n.tails >= level {
                    match runs.last_mut() {
                        Some((_, end)) if *end + 1 == i => *end = i,
                        _ => runs.push((i, i)),
                    }
                }
                runs
            });
            runs.into_iter().map(move |(a, b)| {
                let code = (10 + level - main) as f32;
                match (a == b, a) {
                    (false, _) => (code, notes[a].x, notes[b].x),
                    (true, 0) => (code, notes[a].x, 0.0),
                    (true, i) if i == last => (code, 0.0, notes[a].x),
                    (true, _) => (code, 0.0, notes[a].x),
                }
            })
        })
        .collect()
}

fn beam(line: &mut Line, group: Connection) -> Option<score_format::Item> {
    if group.first >= group.last || group.last > line.note_count() || group.first == 0 {
        return None;
    }
    let notes: Vec<&Note> = (group.first..=group.last).filter_map(|n| line.note(n)).collect();
    let lowest = notes.iter().map(|n| n.lowest()).min()?;
    let highest = notes.iter().map(|n| n.highest()).max()?;
    let down = match group.side {
        Some(Side::Above) => false,
        Some(Side::Below) => true,
        None => lowest + highest >= 2 * MIDDLE_LINE,
    };
    let main = notes.iter().map(|n| n.tails).min()?;
    let lengthen = (notes.iter().map(|n| n.tails).max()? - BEAMS_IN_OCTAVE_STEM).max(0) as f32;
    let (first, last) = (notes[0], notes[notes.len() - 1]);
    let clamp = |level: f32| if down { level.min(DOWN_CEILING) - lengthen } else { level.max(UP_FLOOR) + lengthen };
    let (x1, x2) = (first.x, last.x);
    let (y1, y2) = (clamp(reference(first, down)), clamp(reference(last, down)));
    let segments = secondary_segments(&notes, main);
    let staff = line.staff;

    let at = |x: f32| y1 + (y2 - y1) * (x - x1) / (x2 - x1);
    for number in group.first..=group.last {
        let note = line.note_mut(number)?;
        note.set_stem(down);
        let beam_level = at(note.x);
        note.extension = if down { note.highest() as f32 - beam_level } else { beam_level - note.lowest() as f32 };
        note.tails = 0;
    }

    let mut params = vec![6.0, staff, x1, y1, y2, x2, (if down { 20 } else { 10 } + main) as f32, group.tuplet as f32, 0.0];
    params.extend(segments.iter().take(2).flat_map(|(code, a, b)| [*code, *a, *b]));
    Some(item(&params))
}

pub(crate) fn apply(line: &mut Line, entries: &[ConnectEntry]) -> Result<(), InputError> {
    let groups: Vec<Connection> = entries
        .iter()
        .flat_map(|entry| match *entry {
            ConnectEntry::Pair(c) => vec![c],
            ConnectEntry::EveryEighths { eighths, pickup } => every_eighths(line, eighths, pickup),
        })
        .collect();
    for group in groups {
        if let Some(made) = beam(line, group) {
            line.attachments.push(made);
        }
    }
    Ok(())
}
