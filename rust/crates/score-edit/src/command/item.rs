//! Edit-mode words that rewrite the parameters of the item in edit mode.
//! The same word may mean different things for different codes (FLI flips a
//! note's stem but a slur's curve), so the table is keyed by word and code.

use crate::command::note::{self, Accidental, Rhythm, Spelling};
use crate::params::Draft;

const NOTE: i32 = 1;
const REST: i32 = 2;
const CLEF: i32 = 3;
const SLUR: i32 = 5;

const MARK: usize = 11;
const MARK_X: usize = 13;
const MARK_Y: usize = 14;
const OFFSET: usize = 10;
const SLUR_CURVE: usize = 7;

/// One parameter rewrite.
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum Op {
    FlipStem,
    RemoveStem,
    StemLength(f32),
    NormalStem,
    Accidental(Accidental),
    Respell(Spelling),
    Mark(f32),
    FlipMark,
    MoveMark { dx: f32, dy: f32 },
    MarkHome { horizontal: bool },
    NoteRhythm(Rhythm),
    RestRhythm(Rhythm),
    Dots(u32),
    Tuplet { numerator: f32, denominator: f32 },
    AddTail,
    RemoveTails,
    Cue(bool),
    Grace,
    SetParam { n: usize, value: f32 },
    AddParam { n: usize, delta: f32 },
    /// Clef type (P5) with its vertical placement (P4).
    Clef { level: f32, kind: f32 },
    FlipSlur,
}

impl Op {
    pub fn apply(self, draft: &mut Draft) {
        match self {
            Op::FlipStem => note::flip_stem(draft),
            Op::RemoveStem => note::remove_stem(draft),
            Op::StemLength(steps) => note::lengthen_stem(draft, steps),
            Op::NormalStem => note::normal_stem(draft),
            Op::Accidental(a) => note::set_accidental(draft, a),
            Op::Respell(s) => note::respell(draft, s),
            Op::Mark(value) => draft.set(MARK, value),
            Op::FlipMark => draft.set(MARK, -draft.get(MARK)),
            Op::MoveMark { dx, dy } => {
                draft.add(MARK_X, dx);
                draft.add(MARK_Y, dy);
            }
            Op::MarkHome { horizontal } => draft.set(if horizontal { MARK_X } else { MARK_Y }, 0.0),
            Op::NoteRhythm(r) => note::set_note_rhythm(draft, r),
            Op::RestRhythm(r) => note::set_rest_rhythm(draft, r),
            Op::Dots(n) => note::set_dots(draft, n),
            Op::Tuplet { numerator, denominator } => note::tuplet(draft, numerator, denominator),
            Op::AddTail => note::add_tail(draft),
            Op::RemoveTails => note::remove_tails(draft),
            Op::Cue(cue) => note::set_cue(draft, cue),
            Op::Grace => note::make_grace(draft),
            Op::SetParam { n, value } => draft.set(n, value),
            Op::AddParam { n, delta } => draft.add(n, delta),
            Op::Clef { level, kind } => {
                draft.set(4, level);
                draft.set(5, kind);
            }
            Op::FlipSlur => draft.set(SLUR_CURVE, -draft.get(SLUR_CURVE)),
        }
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
pub struct Entry {
    pub word: &'static str,
    pub codes: &'static [i32],
    pub op: Op,
    pub meaning: &'static str,
}

const fn entry(word: &'static str, codes: &'static [i32], op: Op, meaning: &'static str) -> Entry {
    Entry { word, codes, op, meaning }
}

const N: &[i32] = &[NOTE];
const R: &[i32] = &[REST];
const C: &[i32] = &[CLEF];
const S: &[i32] = &[SLUR];

const fn mark(word: &'static str, value: f32, meaning: &'static str) -> Entry {
    entry(word, N, Op::Mark(value), meaning)
}

const fn rhythm(word: &'static str, r: Rhythm, meaning: &'static str) -> [Entry; 2] {
    [entry(word, N, Op::NoteRhythm(r), meaning), entry(word, R, Op::RestRhythm(r), meaning)]
}

const fn clef(word: &'static str, level: f32, kind: f32, meaning: &'static str) -> Entry {
    entry(word, C, Op::Clef { level, kind }, meaning)
}

/// Marks in P11 follow the order of the engine's table at 0x78F418.
const MARKS: &[Entry] = &[
    mark("FCF", 1.0, "Ficta flat (P11 = 1)"),
    mark("FCS", 2.0, "Ficta sharp (P11 = 2)"),
    mark("FCN", 3.0, "Ficta natural (P11 = 3)"),
    mark("W", 4.0, "Wedge (P11 = 4)"),
    mark("AC", 5.0, "Accent (P11 = 5)"),
    mark("TN", 6.0, "Tenuto (P11 = 6)"),
    mark("STA", 7.0, "Staccato (P11 = 7)"),
    mark("WST", 8.0, "Wedge staccato (P11 = 8)"),
    mark("AST", 9.0, "Accent staccato (P11 = 9)"),
    mark("TNS", 10.0, "Tenuto staccato (P11 = 10)"),
    mark("DNB", 11.0, "Down bow (P11 = 11)"),
    mark("UPB", 12.0, "Up bow (P11 = 12)"),
    mark("HAR", 13.0, "Harmonic (P11 = 13)"),
    mark("FE", 14.0, "Fermata (P11 = 14)"),
    mark("ARS", 15.0, "Arsis (P11 = 15)"),
    mark("THE", 16.0, "Thesis (P11 = 16)"),
    mark("MO", 17.0, "Mordent (P11 = 17)"),
    mark("IMO", 18.0, "Inverted mordent (P11 = 18)"),
    mark("HW", 19.0, "Heavy wedge (P11 = 19)"),
    mark("TR", 20.0, "Trill (P11 = 20)"),
    mark("TRF", 21.0, "Trill with flat (P11 = 21)"),
    mark("TRS", 22.0, "Trill with sharp (P11 = 22)"),
    mark("TRN", 23.0, "Trill with natural (P11 = 23)"),
    mark("PLU", 24.0, "Plus sign (P11 = 24)"),
    mark("ACT", 25.0, "Accent tenuto (P11 = 25)"),
];

const RHYTHMS: &[[Entry; 2]] = &[
    rhythm("RHD", note::DOUBLE_WHOLE, "Double whole note/rest"),
    rhythm("RHW", note::WHOLE, "Whole note/rest"),
    rhythm("RHH", note::HALF, "Half note/rest"),
    rhythm("RHQ", note::QUARTER, "Quarter note/rest"),
    rhythm("RHE", note::EIGHTH, "Eighth note/rest"),
    rhythm("RHS", note::SIXTEENTH, "Sixteenth note/rest"),
    rhythm("RH32", note::THIRTY_SECOND, "Thirty-second note/rest"),
    rhythm("RH64", note::SIXTY_FOURTH, "Sixty-fourth note/rest"),
];

const OTHERS: &[Entry] = &[
    entry("FLI", N, Op::FlipStem, "Flip the stem (P5)"),
    entry("FLI", S, Op::FlipSlur, "Flip the curve (P7)"),
    entry("NST", N, Op::RemoveStem, "No stem (P5)"),
    entry("STM", N, Op::StemLength(-0.5), "Shorten stem by half a step (P8)"),
    entry("STP", N, Op::StemLength(0.5), "Lengthen stem by half a step (P8)"),
    entry("STN", N, Op::NormalStem, "Normal stem length (P8 = 0)"),
    entry("FL", N, Op::Accidental(Accidental::Flat), "Flat (P5)"),
    entry("FLT", N, Op::Accidental(Accidental::Flat), "Flat (P5)"),
    entry("SHP", N, Op::Accidental(Accidental::Sharp), "Sharp (P5)"),
    entry("NAT", N, Op::Accidental(Accidental::Natural), "Natural (P5)"),
    entry("DBF", N, Op::Accidental(Accidental::DoubleFlat), "Double flat (P5)"),
    entry("DBS", N, Op::Accidental(Accidental::DoubleSharp), "Double sharp (P5)"),
    entry("NAC", N, Op::Accidental(Accidental::None), "No accidental (P5)"),
    entry("ENH", N, Op::Respell(Spelling::Logical), "Enharmonic change (P4, P5)"),
    entry("ENHU", N, Op::Respell(Spelling::Up), "Enharmonic up (P4, P5)"),
    entry("ENH+1", N, Op::Respell(Spelling::Up), "Enharmonic up (P4, P5)"),
    entry("ENHD", N, Op::Respell(Spelling::Down), "Enharmonic down (P4, P5)"),
    entry("ENH-1", N, Op::Respell(Spelling::Down), "Enharmonic down (P4, P5)"),
    entry("NOM", N, Op::Mark(0.0), "No mark (P11 = 0)"),
    entry("FLM", N, Op::FlipMark, "Flip mark to the other side (P11)"),
    entry("MKL", N, Op::MoveMark { dx: -0.5, dy: 0.0 }, "Mark left (P13 -.5)"),
    entry("MKR", N, Op::MoveMark { dx: 0.5, dy: 0.0 }, "Mark right (P13 +.5)"),
    entry("MKU", N, Op::MoveMark { dx: 0.0, dy: 0.5 }, "Mark up (P14 +.5)"),
    entry("MKD", N, Op::MoveMark { dx: 0.0, dy: -0.5 }, "Mark down (P14 -.5)"),
    entry("MKH", N, Op::MarkHome { horizontal: true }, "Mark horizontal default (P13 = 0)"),
    entry("MKV", N, Op::MarkHome { horizontal: false }, "Mark vertical default (P14 = 0)"),
    entry("DOT", N, Op::Dots(1), "Add dot (P7, P9)"),
    entry("DDT", N, Op::Dots(2), "Double dot (P7, P9)"),
    entry("TRP", N, Op::Tuplet { numerator: 2.0, denominator: 3.0 }, "Convert to triplet (P7)"),
    entry("RHU", N, Op::Tuplet { numerator: 4.0, denominator: 5.0 }, "Convert to quintuplet (P7)"),
    entry("ADT", N, Op::AddTail, "Add tail (P9)"),
    entry("NTA", N, Op::RemoveTails, "No tail (P9)"),
    entry("CUE", N, Op::Cue(true), "Cue size (P4 + 100)"),
    entry("CUX", N, Op::Cue(false), "Normal size (P4 - 100)"),
    entry("RHG", N, Op::Grace, "Grace note (P4, P7, P8, P9)"),
    entry("OFL", N, Op::SetParam { n: OFFSET, value: 20.0 }, "Offset one note width left (P10 = 20)"),
    entry("OFR", N, Op::SetParam { n: OFFSET, value: 10.0 }, "Offset one note width right (P10 = 10)"),
    entry("NOF", N, Op::SetParam { n: OFFSET, value: 0.0 }, "No offset (P10 = 0)"),
    entry("OFM", N, Op::AddParam { n: OFFSET, delta: -0.5 }, ".5 left offset (P10)"),
    entry("OFP", N, Op::AddParam { n: OFFSET, delta: 0.5 }, ".5 right offset (P10)"),
    clef("TREB", 0.0, 0.0, "Treble clef"),
    clef("TRE", 0.0, 0.0, "Treble clef"),
    clef("BASS", 0.0, 1.0, "Bass clef"),
    clef("BAS", 0.0, 1.0, "Bass clef"),
    clef("ALTO", 0.0, 2.0, "Alto clef"),
    clef("ALT", 0.0, 2.0, "Alto clef"),
    clef("TENOR", 0.0, 3.0, "Tenor clef"),
    clef("TEN", 0.0, 3.0, "Tenor clef"),
    clef("PERC", 0.0, 4.0, "Percussion clef"),
    clef("PER", 0.0, 4.0, "Percussion clef"),
    clef("BAR", -2.0, 1.0, "Baritone clef"),
    clef("SOP", -4.0, 2.0, "Soprano clef"),
    clef("MEZ", -2.0, 2.0, "Mezzo-soprano clef"),
    entry("MINI", C, Op::Clef { level: 100.0, kind: 0.0 }, "Mini clef"),
];

/// Every word, in lookup order.
pub fn entries() -> impl Iterator<Item = &'static Entry> {
    MARKS.iter().chain(RHYTHMS.iter().flatten()).chain(OTHERS)
}

/// The rewrite `word` stands for on an item of `code`.
pub fn lookup(word: &str, code: i32) -> Option<&'static Entry> {
    entries().find(|e| e.word == word && e.codes.contains(&code))
}

/// Whether `word` is an edit word for any code.
pub fn is_edit_word(word: &str) -> bool {
    entries().any(|e| e.word == word)
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn words_resolve_by_code() {
        assert_eq!(lookup("FLI", NOTE).unwrap().op, Op::FlipStem);
        assert_eq!(lookup("FLI", SLUR).unwrap().op, Op::FlipSlur);
        assert!(lookup("FLI", REST).is_none());
        assert_eq!(lookup("RHH", REST).unwrap().op, Op::RestRhythm(note::HALF));
    }

    #[test]
    fn no_word_is_listed_twice_for_a_code() {
        let all: Vec<_> = entries().collect();
        let duplicate = all.iter().enumerate().find(|(i, a)| {
            all[..*i].iter().any(|b| b.word == a.word && b.codes.iter().any(|c| a.codes.contains(c)))
        });
        assert_eq!(duplicate.map(|(_, e)| e.word), None);
    }
}
