//! Edit-mode words that rewrite the parameters of the item in edit mode.
//! The same word may mean different things for different codes (FLI flips a
//! note's stem but a slur's curve), so the table is keyed by word and code.

use crate::command::line::{self, End};
use crate::command::note::{self, Accidental, Rhythm, Spelling};
use crate::params::Draft;

const NOTE: i32 = 1;
const REST: i32 = 2;
const CLEF: i32 = 3;
const LINE: i32 = 4;
const SLUR: i32 = 5;
const BEAM: i32 = 6;
const TRILL: i32 = 7;

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
    SetParams(&'static [(usize, f32)]),
    /// P(n) = the number after the word, 0 without one (THK n on beams).
    ParamFromArg { n: usize },
    CopyParam { to: usize, from: usize },
    /// P(n) = value, or 0 if it already is (LAR: arrow on/off).
    Toggle { n: usize, value: f32 },
    /// P(n) = 0 if set, else value (LBR: bracket on/off).
    SetOrClear { n: usize, value: f32 },
    /// Adds `unit` (10, 100, 1000) to P(n), or takes it away if that digit is 1 (ACP, DUD).
    ToggleDigit { n: usize, unit: f32 },
    /// P(n), or `default` while unset, plus `delta` (WID+, DSHL-, MIDL).
    Nudge { n: usize, default: f32, delta: f32 },
    /// Takes `delta` off P(n) only if its fraction holds that much (SPD-, SPA-).
    ShrinkFraction { n: usize, delta: f32 },
    /// Clef type (P5) with its vertical placement (P4).
    Clef { level: f32, kind: f32 },
    FlipSlur,
    SpaceAccidental(f32),
    UnspaceAccidental,
    RemoveDots,
    RestDots(u32),
    Tremolo(Option<f32>),
    TupletRhythm(f32),
    OffsetEnd { end: End, delta: Option<f32> },
    Vertical,
    ToggleTriplet,
    MoveNumber { dx: f32, dy: f32 },
    BeamTremolo(f32),
    /// Code 7's right end offset: moved by the delta, or set to the typed number (ROFF n).
    TrillRight(Option<f32>),
    HairpinSpread(f32),
}

impl Op {
    /// Rewrites `draft`; `arg` is the number typed after the word, if any.
    pub fn apply(self, draft: &mut Draft, arg: Option<f32>) {
        match self {
            Op::ParamFromArg { n } => draft.set(n, arg.unwrap_or(0.0)),
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
            Op::SetParams(pairs) => pairs.iter().for_each(|&(n, v)| draft.set(n, v)),
            Op::CopyParam { to, from } => draft.set(to, draft.get(from)),
            Op::Toggle { n, value } => draft.set(n, if draft.get(n) == value { 0.0 } else { value }),
            Op::SetOrClear { n, value } => draft.set(n, if draft.get(n) != 0.0 { 0.0 } else { value }),
            Op::ToggleDigit { n, unit } => {
                let digit_is_set = (draft.get(n).abs() / unit) as u32 % 10 == 1;
                draft.add(n, if digit_is_set { -unit } else { unit });
            }
            Op::Nudge { n, default, delta } => {
                let current = draft.get(n);
                draft.set(n, if current == 0.0 { default } else { current } + delta);
            }
            Op::ShrinkFraction { n, delta } => {
                if draft.get(n).abs().fract() >= delta {
                    draft.add(n, -delta);
                }
            }
            Op::Clef { level, kind } => {
                draft.set(4, level);
                draft.set(5, kind);
            }
            Op::FlipSlur => draft.set(SLUR_CURVE, -draft.get(SLUR_CURVE)),
            Op::SpaceAccidental(delta) => note::space_accidental(draft, delta),
            Op::UnspaceAccidental => note::unspace_accidental(draft),
            Op::RemoveDots => note::remove_dots(draft),
            Op::RestDots(n) => note::set_rest_dots(draft, n),
            Op::Tremolo(beams) => note::tremolo(draft, beams),
            Op::TupletRhythm(per_whole) => note::set_tuplet_rhythm(draft, per_whole),
            Op::OffsetEnd { end, delta } => line::offset_end(draft, end, delta),
            Op::Vertical => line::make_vertical(draft),
            Op::ToggleTriplet => line::toggle_triplet(draft),
            Op::MoveNumber { dx, dy } => line::move_number(draft, dx, dy),
            Op::BeamTremolo(strokes) => line::beam_tremolo(draft, strokes),
            Op::TrillRight(delta) => {
                let to = delta.map_or(line::Offset::To(arg.unwrap_or(0.0)), line::Offset::By);
                line::offset_trill_right(draft, to);
            }
            Op::HairpinSpread(delta) => line::spread_hairpin(draft, delta),
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
const NR: &[i32] = &[NOTE, REST];
const C: &[i32] = &[CLEF];
const L: &[i32] = &[LINE];
const S: &[i32] = &[SLUR];
const LS: &[i32] = &[LINE, SLUR];
const B: &[i32] = &[BEAM];
const T: &[i32] = &[TRILL];

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
    entry("DOT", R, Op::RestDots(1), "Add dot (P6, P7)"),
    entry("DDT", R, Op::RestDots(2), "Double dot (P6, P7)"),
    entry("NOD", N, Op::RemoveDots, "No dot (P9, P19)"),
    entry("DUD", N, Op::ToggleDigit { n: 9, unit: 100.0 }, "Dot below or above the line (P9 ± 100)"),
    entry("SPD", N, Op::AddParam { n: 9, delta: 0.05 }, "Space dot to the right (P9 + .05)"),
    entry("SPD-", N, Op::ShrinkFraction { n: 9, delta: 0.05 }, "Space dot to the left (P9 - .05)"),
    entry("SPDN", N, Op::ToggleDigit { n: 9, unit: 1000.0 }, "Dot one note width to the right (P9 ± 1000)"),
    entry("TRP", N, Op::Tuplet { numerator: 2.0, denominator: 3.0 }, "Convert to triplet (P7)"),
    entry("RHU", N, Op::Tuplet { numerator: 4.0, denominator: 5.0 }, "Convert to quintuplet (P7)"),
    entry("ADT", N, Op::AddTail, "Add tail (P9)"),
    entry("NTA", N, Op::RemoveTails, "No tail (P9)"),
    entry("CUE", NR, Op::Cue(true), "Cue size (P4 + 100)"),
    entry("CUX", NR, Op::Cue(false), "Normal size (P4 - 100)"),
    entry("RHG", N, Op::Grace, "Grace note (P4, P7, P8, P9)"),
    entry("OFL", NR, Op::SetParam { n: OFFSET, value: 20.0 }, "Offset one note width left (P10 = 20)"),
    entry("OFR", NR, Op::SetParam { n: OFFSET, value: 10.0 }, "Offset one note width right (P10 = 10)"),
    entry("NOF", NR, Op::SetParam { n: OFFSET, value: 0.0 }, "No offset (P10 = 0)"),
    entry("NOFST", N, Op::SetParam { n: OFFSET, value: 0.0 }, "No offset (P10 = 0)"),
    entry("OFM", NR, Op::AddParam { n: OFFSET, delta: -0.5 }, ".5 left offset (P10)"),
    entry("OFP", NR, Op::AddParam { n: OFFSET, delta: 0.5 }, ".5 right offset (P10)"),
    entry("ACP", N, Op::ToggleDigit { n: 5, unit: 100.0 }, "Accidental in parentheses on/off (P5 ± 100)"),
    entry("SPA", N, Op::SpaceAccidental(0.02), "Accidental further left (P5 + .02)"),
    entry("SPA-", N, Op::ShrinkFraction { n: 5, delta: 0.02 }, "Accidental closer (P5 - .02)"),
    entry("NOS", N, Op::UnspaceAccidental, "Accidental at its normal place (P5)"),
    entry("PRN", N, Op::ToggleDigit { n: 6, unit: 10.0 }, "Note head in parentheses on/off (P6 ± 10)"),
    entry("TM1", N, Op::Tremolo(Some(1.0)), "1 tremolo stroke (P11 = 41)"),
    entry("TM+", N, Op::Tremolo(None), "Add a tremolo stroke (P11)"),
    entry("TRM1", N, Op::Tremolo(Some(1.0)), "1 tremolo stroke (P11 = 41)"),
    entry("TRM2", N, Op::Tremolo(Some(2.0)), "2 tremolo strokes (P11 = 42)"),
    entry("TRM3", N, Op::Tremolo(Some(3.0)), "3 tremolo strokes (P11 = 43)"),
    entry("TRM4", N, Op::Tremolo(Some(4.0)), "4 tremolo strokes (P11 = 44)"),
    entry("WID+", N, Op::Nudge { n: 20, default: 1.0, delta: 0.05 }, "Wider note (P20 + .05)"),
    entry("WID-", N, Op::Nudge { n: 20, default: 1.0, delta: -0.05 }, "Narrower note (P20 - .05)"),
    entry("WID0", N, Op::SetParam { n: 20, value: 0.0 }, "Default note width (P20 = 0)"),
    entry("RH1", N, Op::NoteRhythm(note::WHOLE), "Whole note"),
    entry("RH2", N, Op::NoteRhythm(note::HALF), "Half note"),
    entry("RH4", N, Op::NoteRhythm(note::QUARTER), "Quarter note"),
    entry("RH8", N, Op::NoteRhythm(note::EIGHTH), "Eighth note"),
    entry("RH16", N, Op::NoteRhythm(note::SIXTEENTH), "Sixteenth note"),
    entry("RH.5", N, Op::NoteRhythm(note::DOUBLE_WHOLE), "Double whole note"),
    entry("RH3", N, Op::TupletRhythm(3.0), "Triplet half (P7 = 4/3)"),
    entry("RH6", N, Op::TupletRhythm(6.0), "Triplet quarter (P7 = 2/3)"),
    entry("RH12", N, Op::TupletRhythm(12.0), "Triplet eighth (P7 = 1/3)"),
    entry("RH24", N, Op::TupletRhythm(24.0), "Triplet sixteenth (P7 = 1/6)"),
    entry("RH5", N, Op::TupletRhythm(5.0), "Quintuplet quarter (P7 = .8)"),
    entry("RH10", N, Op::TupletRhythm(10.0), "Quintuplet eighth (P7 = .4)"),
    entry("RH20", N, Op::TupletRhythm(20.0), "Quintuplet sixteenth (P7 = .2)"),
    entry("RINV", R, Op::Toggle { n: 6, value: -1.0 }, "Invisible rest on/off (P6 = -1)"),
    entry("RF", R, Op::Toggle { n: 8, value: -1.0 }, "Fermata on the rest on/off (P8 = -1)"),
    entry("RPR", R, Op::ToggleDigit { n: 5, unit: 100.0 }, "Rest in parentheses on/off (P5 ± 100)"),
    entry("CW", R, Op::Toggle { n: 9, value: -1.0 }, "Centre whole rest (P9 = -1)"),
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
    clef("TAB", 0.0, 66.0, "Tablature clef"),
    clef("TB4", 0.0, 44.0, "4-line tablature clef"),
    clef("TB5", 0.0, 55.0, "5-line tablature clef"),
];

const LINES: &[Entry] = &[
    entry("LAR", L, Op::Toggle { n: 11, value: 102.0 }, "Left arrow on/off (P11 = 102)"),
    entry("RAR", L, Op::Toggle { n: 12, value: 102.0 }, "Right arrow on/off (P12 = 102)"),
    entry("LBR", L, Op::SetOrClear { n: 11, value: 2.0 }, "Left bracket on/off (P11 = 2)"),
    entry("RBR", L, Op::SetOrClear { n: 12, value: 2.0 }, "Right bracket on/off (P12 = 2)"),
    entry("LBR+", L, Op::AddParam { n: 11, delta: 0.5 }, "Lengthen left bracket (P11 + .5)"),
    entry("LBR-", L, Op::AddParam { n: 11, delta: -0.5 }, "Shorten left bracket (P11 - .5)"),
    entry("RBR+", L, Op::AddParam { n: 12, delta: 0.5 }, "Lengthen right bracket (P12 + .5)"),
    entry("RBR-", L, Op::AddParam { n: 12, delta: -0.5 }, "Shorten right bracket (P12 - .5)"),
    entry("LBRD", L, Op::SetParam { n: 11, value: -2.0 }, "Left bracket down (P11 = -2)"),
    entry("RBRD", L, Op::SetParam { n: 12, value: -2.0 }, "Right bracket down (P12 = -2)"),
    entry("DSHL+", L, Op::Nudge { n: 8, default: 2.0, delta: 0.1 }, "Longer dashes (P8 + .1)"),
    entry("DSHL-", L, Op::Nudge { n: 8, default: 2.0, delta: -0.1 }, "Shorter dashes (P8 - .1)"),
    entry("DSHL0", L, Op::SetParam { n: 8, value: 0.0 }, "Default dash length (P8 = 0)"),
    entry("DSHS+", L, Op::Nudge { n: 9, default: 2.0, delta: 0.1 }, "Wider dash spaces (P9 + .1)"),
    entry("DSHS-", L, Op::Nudge { n: 9, default: 2.0, delta: -0.1 }, "Narrower dash spaces (P9 - .1)"),
    entry("DSHS0", L, Op::SetParam { n: 9, value: 0.0 }, "Default dash space (P9 = 0)"),
    entry("THK", L, Op::AddParam { n: 10, delta: 1.0 }, "Thicker line (P10 + 1)"),
    entry("THK0", L, Op::SetParam { n: 10, value: 0.0 }, "Default thickness (P10 = 0)"),
    entry("HORZ", L, Op::CopyParam { to: 5, from: 4 }, "Horizontal line (P5 = P4)"),
    entry("VERT", L, Op::Vertical, "Vertical line (P6 = P3, P5 = P4 + 10)"),
    entry("WIG", L, Op::SetParams(&[(7, -1.0), (12, 0.0)]), "Wiggle line (P7 = -1)"),
    entry("SAW", L, Op::SetParams(&[(7, -3.0), (11, 0.0)]), "Sawtooth (P7 = -3)"),
    entry("SAWX", L, Op::SetParams(&[(7, -3.0), (8, 2.0), (11, 0.8)]), "Heavy sawtooth (P7 = -3, P8, P11)"),
    entry("VIB", L, Op::SetParams(&[(7, -2.0), (10, 0.0), (11, 0.0)]), "Vibrato waves (P7 = -2)"),
    entry("DTS4", L, Op::SetParam { n: 7, value: -4.0 }, "Dotted line (P7 = -4)"),
    entry("SPD+1", L, Op::HairpinSpread(0.4), "Wider hairpin (P7 + .4)"),
    entry("SPD-", L, Op::HairpinSpread(-0.4), "Narrower hairpin (P7 - .4)"),
    entry("SPD0", L, Op::SetParam { n: 7, value: 0.0 }, "Default hairpin spread (P7 = 0)"),
    entry("CR-", L, Op::SetParams(&[(7, 0.0), (11, 1.0)]), "Crescendo dashes (P11 = 1)"),
    entry("DC-", L, Op::SetParams(&[(7, -1.0), (11, 1.0)]), "Decrescendo dashes (P7 = -1, P11 = 1)"),
    entry("LOFFP", LS, Op::OffsetEnd { end: End::Left, delta: Some(0.5) }, "Left end offset right (P16, P17 + .5)"),
    entry("LOFFM", LS, Op::OffsetEnd { end: End::Left, delta: Some(-0.5) }, "Left end offset left (P16, P17 - .5)"),
    entry("LOFF0", LS, Op::OffsetEnd { end: End::Left, delta: None }, "Zero left end offset (P17)"),
    entry("ROFFP", LS, Op::OffsetEnd { end: End::Right, delta: Some(0.5) }, "Right end offset right (P16, P18 + .5)"),
    entry("ROFFM", LS, Op::OffsetEnd { end: End::Right, delta: Some(-0.5) }, "Right end offset left (P16, P18 - .5)"),
    entry("ROFF0", LS, Op::OffsetEnd { end: End::Right, delta: None }, "Zero right end offset (P18)"),
    entry("XOFF", LS, Op::SetParams(&[(16, 0.0), (17, 0.0), (18, 0.0)]), "Zero end offsets (P16-18)"),
    entry("LOFFP", B, Op::SetParam { n: 14, value: 10.0 }, "Left end offset right (P14 = 10)"),
    entry("LOFFM", B, Op::SetParam { n: 14, value: 20.0 }, "Left end offset left (P14 = 20)"),
    entry("LOFF0", B, Op::SetParam { n: 14, value: 0.0 }, "Zero left end offset (P14 = 0)"),
    entry("ROFFP", B, Op::SetParam { n: 15, value: 10.0 }, "Right end offset right (P15 = 10)"),
    entry("ROFFM", B, Op::SetParam { n: 15, value: 20.0 }, "Right end offset left (P15 = 20)"),
    entry("ROFF0", B, Op::SetParam { n: 15, value: 0.0 }, "Zero right end offset (P15 = 0)"),
    entry("XOF", B, Op::SetParams(&[(14, 0.0), (15, 0.0)]), "Zero end offsets (P14, P15)"),
    entry("LOFFP", T, Op::AddParam { n: 15, delta: 0.5 }, "Left offset plus .5 (P15)"),
    entry("LOFFM", T, Op::AddParam { n: 15, delta: -0.5 }, "Left offset minus .5 (P15)"),
    entry("LOFF", T, Op::ParamFromArg { n: 15 }, "Left offset n steps (P15 = n)"),
    entry("LOFF0", T, Op::SetParam { n: 15, value: 0.0 }, "Zero left offset (P15 = 0)"),
    entry("ROFFP", T, Op::TrillRight(Some(0.5)), "Right offset plus .5 (P16 = 1, P18)"),
    entry("ROFFM", T, Op::TrillRight(Some(-0.5)), "Right offset minus .5 (P16 = 1, P18)"),
    entry("ROFF", T, Op::TrillRight(None), "Right offset n steps (P16 = 1, P18 = n)"),
    entry("ROFF0", T, Op::SetParams(&[(16, 0.0), (18, 0.0)]), "Zero right offset (P16, P18)"),
    entry("XOFF", T, Op::SetParams(&[(15, 0.0), (16, 0.0), (18, 0.0)]), "Zero offsets (P15, P16, P18)"),
    entry("LROFP", L, Op::OffsetEnd { end: End::Right, delta: Some(0.5) }, "Right end offset right (P16, P18 + .5)"),
    entry("LROFM", L, Op::OffsetEnd { end: End::Right, delta: Some(-0.5) }, "Right end offset left (P16, P18 - .5)"),
    entry("SLDSH", S, Op::SetParam { n: 11, value: 1.0 }, "Dashed slur (P11 = 1)"),
    entry("SLDTS", S, Op::SetParam { n: 11, value: -1.0 }, "Dotted slur (P11 = -1)"),
    entry("SLHL", S, Op::SetOrClear { n: 12, value: 1.0 }, "Half slur left on/off (P12 = 1)"),
    entry("SLHR", S, Op::SetOrClear { n: 12, value: 2.0 }, "Half slur right on/off (P12 = 2)"),
    entry("SUPDN", S, Op::SetOrClear { n: 12, value: -1.0 }, "Up/down slur on/off (P12 = -1)"),
    entry("SLTRIP", S, Op::ToggleTriplet, "Triplet number on/off (P16 = 3)"),
    entry("THM", S, Op::Nudge { n: 13, default: 1.0, delta: -0.05 }, "Thinner slur (P13 - .05)"),
    entry("THK", S, Op::SetParam { n: 13, value: 0.0 }, "Default slur thickness (P13 = 0)"),
    entry("CRVP", S, Op::AddParam { n: 7, delta: 0.2 }, "More curve (P7 + .2)"),
    entry("CRVM", S, Op::AddParam { n: 7, delta: -0.2 }, "Less curve (P7 - .2)"),
    entry("MID", S, Op::SetParam { n: 10, value: 0.0 }, "Midpoint at the centre (P10 = 0)"),
    entry("MID0", S, Op::SetParam { n: 10, value: 0.0 }, "Midpoint at the centre (P10 = 0)"),
    entry("MIDL", S, Op::Nudge { n: 10, default: 0.5, delta: -0.02 }, "Midpoint left (P10 - .02)"),
    entry("MIDR", S, Op::Nudge { n: 10, default: 0.5, delta: 0.02 }, "Midpoint right (P10 + .02)"),
    entry("NUML", S, Op::MoveNumber { dx: -0.1, dy: 0.0 }, "Number left (P17 - .1)"),
    entry("NUMR", S, Op::MoveNumber { dx: 0.1, dy: 0.0 }, "Number right (P17 + .1)"),
    entry("NUMU", S, Op::MoveNumber { dx: 0.0, dy: 0.1 }, "Number up (P18 + .1)"),
    entry("NUMD", S, Op::MoveNumber { dx: 0.0, dy: -0.1 }, "Number down (P18 - .1)"),
    entry("NUMH0", S, Op::SetParam { n: 17, value: 0.0 }, "Number horizontal default (P17 = 0)"),
    entry("NUMV0", S, Op::SetParam { n: 18, value: 0.0 }, "Number vertical default (P18 = 0)"),
    entry("SLUR3", S, Op::SetParams(&[(7, 2.0), (8, 3.0)]), "Triplet bracket (P7 = 2, P8 = 3)"),
    entry("TRP", S, Op::SetParams(&[(7, 2.0), (8, 3.0)]), "Triplet bracket (P7 = 2, P8 = 3)"),
    entry("BEAM+", B, Op::AddParam { n: 7, delta: 1.0 }, "Add a beam (P7 + 1)"),
    entry("BNUM0", B, Op::SetParam { n: 8, value: 0.0 }, "No number over the beam (P8 = 0)"),
    entry("BNUM3", B, Op::SetParam { n: 8, value: 3.0 }, "Number 3 over the beam (P8 = 3)"),
    entry("BNUM5", B, Op::SetParam { n: 8, value: 5.0 }, "Number 5 over the beam (P8 = 5)"),
    entry("BNUMP", B, Op::AddParam { n: 8, delta: 1.0 }, "Number over the beam plus one (P8 + 1)"),
    entry("TRM1", B, Op::BeamTremolo(1.0), "1 tremolo beam (P7, P10)"),
    entry("TRM2", B, Op::BeamTremolo(2.0), "2 tremolo beams (P7, P10)"),
    entry("TRM3", B, Op::BeamTremolo(3.0), "3 tremolo beams (P7, P10)"),
    entry("TRM4", B, Op::BeamTremolo(4.0), "4 tremolo beams (P7, P10)"),
    entry("THK", B, Op::ParamFromArg { n: 17 }, "Beam thickness n, default without n (P17)"),
    entry("THK0", B, Op::SetParam { n: 17, value: 0.0 }, "Default beam thickness (P17 = 0)"),
];

/// Every word, in lookup order.
pub fn entries() -> impl Iterator<Item = &'static Entry> {
    MARKS.iter().chain(RHYTHMS.iter().flatten()).chain(OTHERS).chain(LINES)
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
