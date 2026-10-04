//! Commands that fit notes to the beams and chords around them (WinScore
//! help, code1.txt "Stems", code6.txt "Stem Adjustments").

use crate::command::Run;
use crate::document::ItemId;
use crate::error::EditError;
use crate::params::Draft;

const NOTE: i32 = 1;
const BEAM: i32 = 6;
const STEM: usize = 5;
const DURATION: usize = 7;
const STEM_LENGTH: usize = 8;
const DOTS_TAILS: usize = 9;
const CUE: f32 = 100.0;

/// A beam's main line: from (P3, P4) to (P6, P5), and whether the stems go up.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Beam {
    staff: f32,
    left: (f32, f32),
    right: (f32, f32),
    stems_up: bool,
}

impl Beam {
    fn of(draft: &Draft) -> Option<Self> {
        (draft.code() == BEAM).then(|| Self {
            staff: draft.get(2),
            left: (draft.get(3), draft.get(4)),
            right: (draft.get(6), draft.get(5)),
            stems_up: (draft.get(DURATION).abs() as u32 / 10) % 10 != 2,
        })
    }

    fn spans(&self, staff: f32, x: f32) -> bool {
        staff == self.staff && (self.left.0..=self.right.0).contains(&x)
    }

    /// The beam's level at `x`, on the straight line between its ends
    /// (unrounded: the engine rounds only the stem length it stores).
    fn level_at(&self, x: f32) -> f64 {
        let (x0, y0) = (f64::from(self.left.0), f64::from(self.left.1));
        let (x1, y1) = (f64::from(self.right.0), f64::from(self.right.1));
        let t = if x1 == x0 { 0.0 } else { (f64::from(x) - x0) / (x1 - x0) };
        y0 + (y1 - y0) * t
    }
}

/// The stem direction digit of a note's P5: 1 up, 2 down, 0 none.
fn stem(draft: &Draft) -> u32 {
    draft.get(STEM).abs() as u32 / 10 % 10
}

/// P4 without the hundreds of cue size.
fn level(draft: &Draft) -> f32 {
    let p4 = draft.get(4);
    p4 - (p4 / CUE).trunc() * CUE
}

/// A note stemmed towards `beam` reaches it: P8 is the distance from the note
/// to the beam in steps, and the tails give way to the beam.
fn fit_to(note: &mut Draft, beam: &Beam) -> bool {
    let wanted = if beam.stems_up { 1 } else { 2 };
    if note.code() != NOTE || stem(note) != wanted {
        return false;
    }
    let to_beam = beam.level_at(note.get(3)) - f64::from(level(note));
    note.set(STEM_LENGTH, (if beam.stems_up { to_beam } else { -to_beam }) as f32);
    let tails = note.get(DOTS_TAILS).abs() as u32 % 10;
    note.add(DOTS_TAILS, -(tails as f32));
    true
}

impl Run<'_, '_> {
    fn drafts(&self) -> Vec<(ItemId, Draft)> {
        self.tx.doc().entries().map(|(id, item)| (id, Draft::of(item))).collect()
    }

    /// ADJ: the stems of the notes under each selected beam, or of each
    /// selected note under its beam, made to reach the beam.
    pub fn adjust_stems(&mut self) -> Result<(), EditError> {
        let all = self.drafts();
        let beams: Vec<Beam> = all.iter().filter_map(|(_, d)| Beam::of(d)).collect();
        let selected: Vec<&(ItemId, Draft)> =
            self.session.selection().iter().filter_map(|id| all.iter().find(|(i, _)| i == id)).collect();
        let pairs: Vec<(ItemId, Beam)> = selected
            .iter()
            .flat_map(|(id, chosen)| -> Vec<(ItemId, Beam)> {
                match Beam::of(chosen) {
                    Some(beam) => {
                        all.iter().filter(|(_, d)| beam.spans(d.get(2), d.get(3))).map(|(i, _)| (*i, beam)).collect()
                    }
                    None => beams.iter().filter(|b| b.spans(chosen.get(2), chosen.get(3))).take(1).map(|&b| (*id, b)).collect(),
                }
            })
            .collect();
        pairs.into_iter().for_each(|(id, beam)| {
            let Some(mut note) = all.iter().find(|(i, _)| *i == id).map(|(_, d)| d.clone()) else { return };
            if fit_to(&mut note, &beam) {
                self.tx.replace(id, note.to_item());
            }
        });
        Ok(())
    }

    /// CH [value]: on a stemmed note, every note of its chord (same staff and
    /// P3) takes its duration, or `value`. Stemless chord notes do nothing.
    pub fn chord_rhythm(&mut self, value: Option<f32>) -> Result<(), EditError> {
        let all = self.drafts();
        let chosen: Vec<Draft> = self
            .session
            .selection()
            .iter()
            .filter_map(|id| all.iter().find(|(i, _)| i == id).map(|(_, d)| d.clone()))
            .filter(|d| d.code() == NOTE && stem(d) != 0)
            .collect();
        let durations: Vec<(ItemId, f32)> = chosen
            .iter()
            .flat_map(|note| {
                let duration = value.unwrap_or(note.get(DURATION));
                all.iter()
                    .filter(|(_, d)| d.code() == NOTE && d.get(2) == note.get(2) && d.get(3) == note.get(3))
                    .map(move |(id, _)| (*id, duration))
            })
            .collect();
        durations.into_iter().for_each(|(id, duration)| {
            let Some(item) = self.tx.doc().item(id) else { return };
            let mut note = Draft::of(item);
            note.set(DURATION, duration);
            self.tx.replace(id, note.to_item());
        });
        Ok(())
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn stems_reach_the_beam_line() {
        let beam = Beam::of(&Draft::new(&[6.0, 1.0, 100.0, 13.0, 15.0, 130.0, 11.0])).unwrap();
        let mut note = Draft::new(&[1.0, 1.0, 110.0, 8.0, 10.0, 0.0, 0.5, 0.0, 11.0]);
        assert!(fit_to(&mut note, &beam));
        assert_eq!((note.get(8), note.get(9)), (5.666_666_5, 10.0));
        let mut down = Draft::new(&[1.0, 1.0, 110.0, 8.0, 20.0, 0.0, 0.5, 0.0, 1.0]);
        assert!(!fit_to(&mut down, &beam));
    }
}
