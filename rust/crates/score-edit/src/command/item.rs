//! Edit-mode words that rewrite the parameters of the item in edit mode.
//! The same word may mean different things for different codes (FLI flips a
//! note's stem but a slur's curve), so the table is keyed by word and code.

use crate::command::line::{self, End};
use crate::command::note::{self, Accidental, Rhythm, Spelling};
use crate::command::signs;
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
    Negate(usize),
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
    /// 100 in or out of P(n), away from zero (cue size, KSCU/KSNO).
    Hundred { n: usize, on: bool },
    /// P(n) steps through `values`, starting over after the last.
    Cycle { n: usize, values: &'static [f32] },
    /// P(n) + delta, not below `min`.
    AddAtLeast { n: usize, delta: f32, min: f32 },
    PedalSize(f32),
    /// WB n, EU n: a whole-bar rest numbered n, centred (0x4359D0).
    WholeBarRest { european: bool },
    FlipSymbol,
    SymbolSize(f32),
    BoxWidth(f32),
    BoxHeight(f32),
    KeyFlat,
    KeySharp,
    KeyNaturals,
    Denominator(f32),
}

impl Op {
    /// Rewrites `draft`; `arg` is the number typed after the word, if any.
    pub fn apply(self, draft: &mut Draft, arg: Option<f32>) {
        match self {
            Op::ParamFromArg { n } => draft.set(n, arg.unwrap_or(0.0)),
            Op::Negate(n) => draft.set(n, -draft.get(n)),
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
            Op::Hundred { n, on } => note::set_hundred(draft, n, on),
            Op::Cycle { n, values } => {
                let next = values.iter().position(|&v| v == draft.get(n)).map_or(0, |i| (i + 1) % values.len());
                draft.set(n, values[next]);
            }
            Op::AddAtLeast { n, delta, min } => draft.set(n, (draft.get(n) + delta).max(min)),
            Op::PedalSize(delta) => signs::resize_pedal(draft, delta),
            Op::WholeBarRest { european } => note::whole_bar_rest(draft, european, arg.unwrap_or(0.0)),
            Op::FlipSymbol => signs::flip_symbol(draft),
            Op::SymbolSize(delta) => signs::resize_symbol(draft, delta),
            Op::BoxWidth(delta) => signs::resize_box_width(draft, delta),
            Op::BoxHeight(delta) => signs::resize_box_height(draft, delta),
            Op::KeyFlat => signs::add_flat(draft),
            Op::KeySharp => signs::add_sharp(draft),
            Op::KeyNaturals => signs::toggle_naturals(draft),
            Op::Denominator(factor) => signs::scale_denominator(draft, factor),
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
const ST: &[i32] = &[8];
const SY: &[i32] = &[9];
const NU: &[i32] = &[10];
const BX: &[i32] = &[12];
const SB: &[i32] = &[9, 12, 16];
const TX: &[i32] = &[16];
const BA: &[i32] = &[14];
const K: &[i32] = &[17];
const M: &[i32] = &[18];

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
    entry("TRM0", N, Op::Tremolo(None), "Add a tremolo stroke (P11)"),
    entry("TRM5", N, Op::Tremolo(Some(5.0)), "5 tremolo strokes (P11 = 45)"),
    entry("TRM6", N, Op::Tremolo(Some(6.0)), "6 tremolo strokes (P11 = 46)"),
    entry("TRM7", N, Op::Tremolo(Some(7.0)), "7 tremolo strokes (P11 = 47)"),
    entry("TRM8", N, Op::Tremolo(Some(8.0)), "8 tremolo strokes (P11 = 48)"),
    entry("TRM9", N, Op::Tremolo(Some(9.0)), "9 tremolo strokes (P11 = 49)"),
    entry("TRM10", N, Op::Tremolo(Some(10.0)), "10 tremolo strokes (P11 = 50)"),
    entry("TRM11", N, Op::Tremolo(Some(11.0)), "11 tremolo strokes (P11 = 51)"),
    entry("TRM12", N, Op::Tremolo(Some(12.0)), "12 tremolo strokes (P11 = 52)"),
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
    entry("RF-", R, Op::Toggle { n: 8, value: -2.0 }, "Inverted fermata below the rest on/off (P8 = -2)"),
    entry("RP", R, Op::SetParams(&[(5, -4.0), (9, -1.0)]), "Repeat-bar sign, centred (P5 = -4, P9 = -1)"),
    entry("WB", R, Op::WholeBarRest { european: false }, "Whole rest numbered n (P5 = -2, or -5 from 4; P8 = n, P9 = -1)"),
    entry("EU", R, Op::WholeBarRest { european: true }, "European bar rest numbered n (P5 = -10 - n, P8 = n, P9 = -1)"),
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

const SIGNS: &[Entry] = &[
    entry("SUD", N, Op::Cycle { n: 12, values: &[0.0, 1.0, 2.0] }, "Note on the staff above, below, its own (P12)"),
    entry("OVA", T, Op::SetParams(&[(7, 8.0), (12, -1.0)]), "8va (P7 = 8, P12 = -1)"),
    entry("OVAU", T, Op::SetParams(&[(7, 88.0), (12, -1.0)]), "8va dashes up (P7 = 88)"),
    entry("OVAD", T, Op::SetParams(&[(7, -88.0), (12, 1.0)]), "8va dashes down (P7 = -88)"),
    entry("OBA", T, Op::SetParams(&[(7, -8.0), (11, 0.0), (12, 1.0)]), "8va bassa (P7 = -8)"),
    entry("OMA", T, Op::SetParams(&[(7, 15.0), (12, -1.0)]), "15ma (P7 = 15)"),
    entry("OMAU", T, Op::SetParams(&[(7, 155.0), (12, -1.0)]), "15ma dashes up (P7 = 155)"),
    mark("TRFW", 21.0, "Trill with flat (P11 = 21)"),
    mark("TRSW", 22.0, "Trill with sharp (P11 = 22)"),
    mark("TRNW", 23.0, "Trill with natural (P11 = 23)"),
    entry("SZ.4", N, Op::SetParam { n: 15, value: 0.4 }, "Note size .4 (P15)"),
    entry("SZ.5", N, Op::SetParam { n: 15, value: 0.5 }, "Note size .5 (P15)"),
    entry("SZ.6", N, Op::SetParam { n: 15, value: 0.6 }, "Note size .6 (P15)"),
    entry("SZ.7", N, Op::SetParam { n: 15, value: 0.7 }, "Note size .7 (P15)"),
    entry("SZ.8", N, Op::SetParam { n: 15, value: 0.8 }, "Note size .8 (P15)"),
    entry("SZ.9", N, Op::SetParam { n: 15, value: 0.9 }, "Note size .9 (P15)"),
    entry("SZ1", N, Op::SetParam { n: 15, value: 1.0 }, "Note size 1 (P15)"),
    entry("TRF", T, Op::SetParam { n: 8, value: 1.0 }, "Trill with flat (P8 = 1)"),
    entry("TRS", T, Op::SetParam { n: 8, value: 2.0 }, "Trill with sharp (P8 = 2)"),
    entry("TRN", T, Op::SetParam { n: 8, value: 3.0 }, "Trill with natural (P8 = 3)"),
    entry("TRFW", T, Op::SetParam { n: 8, value: 1.0 }, "Trill flat (P8 = 1)"),
    entry("TRSW", T, Op::SetParam { n: 8, value: 2.0 }, "Trill sharp (P8 = 2)"),
    entry("TRNW", T, Op::SetParam { n: 8, value: 3.0 }, "Trill natural (P8 = 3)"),
    entry("TRZ", T, Op::SetParam { n: 8, value: 0.0 }, "No accidental on the trill (P8 = 0)"),
    entry("PDSZ+", T, Op::PedalSize(0.1), "Larger pedal (P9 + .1)"),
    entry("PDSZ-", T, Op::PedalSize(-0.1), "Smaller pedal (P9 - .1)"),
    entry("PDM+", T, Op::Nudge { n: 8, default: 50.0, delta: 1.0 }, "Pedal midpoint right (P8)"),
    entry("PDM-", T, Op::Nudge { n: 8, default: 50.0, delta: -1.0 }, "Pedal midpoint left (P8)"),
    entry("SZ.4", ST, Op::SetParam { n: 5, value: 0.4 }, "Staff size .4 (P5)"),
    entry("SZ.5", ST, Op::SetParam { n: 5, value: 0.5 }, "Staff size .5 (P5)"),
    entry("SZ.6", ST, Op::SetParam { n: 5, value: 0.6 }, "Staff size .6 (P5)"),
    entry("SZ.7", ST, Op::SetParam { n: 5, value: 0.7 }, "Staff size .7 (P5)"),
    entry("SZ.8", ST, Op::SetParam { n: 5, value: 0.8 }, "Staff size .8 (P5)"),
    entry("SZ.9", ST, Op::SetParam { n: 5, value: 0.9 }, "Staff size .9 (P5)"),
    entry("SZ1", ST, Op::SetParam { n: 5, value: 1.0 }, "Staff size 1 (P5)"),
    entry("SZ+", ST, Op::Nudge { n: 5, default: 1.0, delta: 0.01 }, "Staff size plus (P5 + .01)"),
    entry("SZ-", ST, Op::Nudge { n: 5, default: 1.0, delta: -0.01 }, "Staff size minus (P5 - .01)"),
    entry("NMO", ST, Op::Toggle { n: 12, value: 1.0 }, "Staff number off/on (P12)"),
    entry("SI", ST, Op::Toggle { n: 7, value: -1.0 }, "Invisible staff on/off (P7 = -1)"),
    entry("FLI", SY, Op::FlipSymbol, "Flip the symbol (P7)"),
    entry("SZ+", SY, Op::SymbolSize(signs::SYMBOL_GROWTH), "Larger symbol (P6 + .1)"),
    entry("SZ-", SY, Op::SymbolSize(-0.1), "Smaller symbol (P6 - .1)"),
    entry("CUE", SY, Op::Hundred { n: 4, on: true }, "Cue size (P4 + 100)"),
    entry("CUX", SY, Op::Hundred { n: 4, on: false }, "Normal size (P4 - 100)"),
    entry("ROT+", SB, Op::AddParam { n: 9, delta: 10.0 }, "Rotate clockwise (P9 + 10)"),
    entry("ROT-", SB, Op::AddParam { n: 9, delta: -10.0 }, "Rotate counter-clockwise (P9 - 10)"),
    entry("ROT0", SB, Op::SetParam { n: 9, value: 0.0 }, "No rotation (P9 = 0)"),
    entry("PLUS1", NU, Op::AddParam { n: 5, delta: 1.0 }, "Number plus 1 (P5)"),
    entry("PLUS10", NU, Op::AddParam { n: 5, delta: 10.0 }, "Number plus 10 (P5)"),
    entry("PLUS100", NU, Op::AddParam { n: 5, delta: 100.0 }, "Number plus 100 (P5)"),
    entry("MINUS1", NU, Op::AddParam { n: 5, delta: -1.0 }, "Number minus 1 (P5)"),
    entry("MINUS10", NU, Op::AddParam { n: 5, delta: -10.0 }, "Number minus 10 (P5)"),
    entry("MINUS100", NU, Op::AddParam { n: 5, delta: -100.0 }, "Number minus 100 (P5)"),
    entry("BXHP", BX, Op::BoxWidth(0.4), "Box wider (P6 + .4)"),
    entry("BXHM", BX, Op::BoxWidth(-0.4), "Box narrower (P6 - .4)"),
    entry("BXVP", BX, Op::BoxHeight(0.4), "Box taller (P7 + .4)"),
    entry("BXVM", BX, Op::BoxHeight(-0.4), "Box lower (P7 - .4)"),
    entry("FILL", BX, Op::SetParam { n: 13, value: 1.0 }, "Fill the box (P13 = 1)"),
    entry("CDSH", BX, Op::AddParam { n: 12, delta: -2.0 }, "Circle dashes (P12 - 2)"),
    entry("SKWL", BX, Op::AddParam { n: 10, delta: -2.0 }, "Skew left (P10 - 2)"),
    entry("SKWR", BX, Op::AddParam { n: 10, delta: 2.0 }, "Skew right (P10 + 2)"),
    entry("SKW0", BX, Op::SetParam { n: 10, value: 0.0 }, "No skew (P10 = 0)"),
    entry("BARD", BA, Op::SetParams(&[(5, 1.0), (16, 0.0)]), "Double bar (P5 = 1)"),
    entry("BARH", BA, Op::SetParams(&[(5, 2.0), (16, 0.0)]), "Heavy double bar (P5 = 2)"),
    entry("BARL", BA, Op::SetParams(&[(5, 3.0), (16, 0.0)]), "Repeat, dots left (P5 = 3)"),
    entry("BARR", BA, Op::SetParams(&[(5, 4.0), (16, 0.0)]), "Repeat, dots right (P5 = 4)"),
    entry("BARRD", BA, Op::SetParams(&[(5, 5.0), (16, 0.0)]), "Double repeat (P5 = 5)"),
    entry("BARBC", BA, Op::SetParams(&[(5, 8.0), (16, 0.0)]), "Brace (P5 = 8)"),
    entry("BARBK", BA, Op::SetParams(&[(5, 9.0), (16, 0.0)]), "Bracket (P5 = 9)"),
    entry("INV", BA, Op::Negate(4), "Invisible bar on/off (P4 negative)"),
    entry("END", BA, Op::SetParam { n: 3, value: 200.0 }, "Bar at the right end (P3 = 200)"),
    entry("DBRS+", BA, Op::AddParam { n: 13, delta: 0.2 }, "Double bar space plus (P13 + .2)"),
    entry("DBRS0", BA, Op::SetParam { n: 13, value: 0.0 }, "Double bar space default (P13 = 0)"),
    entry("DBRW+", BA, Op::Nudge { n: 17, default: 0.7, delta: 0.05 }, "Double bar width plus (P17 + .05)"),
    entry("DBRW0", BA, Op::SetParam { n: 17, value: 0.0 }, "Double bar width default (P17 = 0)"),
    entry("KSTR", K, Op::SetParam { n: 6, value: 0.0 }, "Key signature for treble clef (P6 = 0)"),
    entry("KSBA", K, Op::SetParam { n: 6, value: 1.0 }, "Key signature for bass clef (P6 = 1)"),
    entry("KSAL", K, Op::SetParam { n: 6, value: 2.0 }, "Key signature for alto clef (P6 = 2)"),
    entry("KSTN", K, Op::SetParam { n: 6, value: 3.0 }, "Key signature for tenor clef (P6 = 3)"),
    entry("KSCU", K, Op::Hundred { n: 6, on: true }, "Cue-size key signature (P6 + 100)"),
    entry("KSNO", K, Op::Hundred { n: 6, on: false }, "Normal-size key signature (P6 - 100)"),
    entry("KSFL", K, Op::KeyFlat, "One more flat (P5)"),
    entry("KSSH", K, Op::KeySharp, "One more sharp (P5)"),
    entry("KSNA", K, Op::KeyNaturals, "Naturals on/off (P5 ± 100)"),
    entry("KSJU", K, Op::SetParam { n: 14, value: 0.0 }, "Justify the key signature (P14 = 0)"),
    entry("KSNJ", K, Op::SetParam { n: 14, value: 1.0 }, "Do not justify the key signature (P14 = 1)"),
    entry("KSSM", K, Op::Nudge { n: 7, default: 1.0, delta: -0.05 }, "Narrower accidental spacing (P7 - .05)"),
    entry("KSSP", K, Op::Nudge { n: 7, default: 1.0, delta: 0.05 }, "Wider accidental spacing (P7 + .05)"),
    entry("KSSZ", K, Op::SetParam { n: 7, value: 0.0 }, "Default accidental spacing (P7 = 0)"),
    entry("KSZR", K, Op::SetParams(&[(8, 0.0), (9, 0.0), (10, 0.0), (11, 0.0), (12, 0.0), (13, 0.0)]), "Clear special accidentals (P8-13)"),
    entry("MTRM", M, Op::AddAtLeast { n: 8, delta: -1.0, min: 1.0 }, "Composite top right number minus (P8)"),
    entry("MTRP", M, Op::AddParam { n: 8, delta: 1.0 }, "Composite top right number plus (P8)"),
    entry("MBLM", M, Op::Denominator(0.5), "Bottom number halved (P6)"),
    entry("MBLP", M, Op::Denominator(2.0), "Bottom number doubled (P6)"),
    entry("MBRM", M, Op::AddAtLeast { n: 9, delta: -1.0, min: 0.0 }, "Composite bottom right number minus (P9)"),
    entry("MBRP", M, Op::AddParam { n: 9, delta: 1.0 }, "Composite bottom right number plus (P9)"),
    entry("MTRS", M, Op::SetParams(&[(5, 0.0), (6, 1.0)]), "Single number meter (P5 = 0)"),
    entry("MTRSP", M, Op::AddParam { n: 6, delta: 1.0 }, "Single meter number plus (P6)"),
];

const fn font(word: &'static str, number: f32, meaning: &'static str) -> Entry {
    entry(word, TX, Op::SetParam { n: 8, value: 1000.0 + number }, meaning)
}

const TEXTS: &[Entry] = &[
    entry("CHSP", TX, Op::Nudge { n: 5, default: 1.0, delta: 0.02 }, "Character space plus (P5 + .02)"),
    entry("CHSM", TX, Op::Nudge { n: 5, default: 1.0, delta: -0.02 }, "Character space minus (P5 - .02)"),
    entry("CHSD", TX, Op::SetParam { n: 5, value: 0.0 }, "Character space normal (P5 = 0)"),
    entry("SZ+", TX, Op::Nudge { n: 6, default: 1.0, delta: 0.1 }, "Larger text (P6 + .1)"),
    entry("SZ-", TX, Op::Nudge { n: 6, default: 1.0, delta: -0.1 }, "Smaller text (P6 - .1)"),
    font("FNT00", 0.0, "Times-Roman (P8 = 1000)"),
    font("FNT01", 1.0, "Times-Bold (P8 = 1001)"),
    font("FNT02", 2.0, "Times-Italic (P8 = 1002)"),
    font("FNT03", 3.0, "Times-BoldItalic (P8 = 1003)"),
    font("FNT04", 4.0, "Helvetica (P8 = 1004)"),
    font("FNT05", 5.0, "Helvetica-Bold (P8 = 1005)"),
    font("FNT06", 6.0, "Helvetica-Oblique (P8 = 1006)"),
    font("FNT07", 7.0, "Helvetica-BoldOblique (P8 = 1007)"),
    font("FNT08", 8.0, "Helvetica-Narrow (P8 = 1008)"),
    font("FNT09", 9.0, "Helvetica-Narrow-Bold (P8 = 1009)"),
    font("FNT10", 10.0, "Helvetica-Narrow-Oblique (P8 = 1010)"),
    font("FNT11", 11.0, "Helvetica-Narrow-BoldOblique (P8 = 1011)"),
    font("FNT12", 12.0, "Palatino-Roman (P8 = 1012)"),
    font("FNT13", 13.0, "Palatino-Bold (P8 = 1013)"),
    font("FNT14", 14.0, "Palatino-Italic (P8 = 1014)"),
    font("FNT15", 15.0, "Palatino-BoldItalic (P8 = 1015)"),
    font("FNT16", 16.0, "AvantGarde-Book (P8 = 1016)"),
    font("FNT17", 17.0, "AvantGarde-BookOblique (P8 = 1017)"),
    font("FNT18", 18.0, "AvantGarde-Demi (P8 = 1018)"),
    font("FNT19", 19.0, "AvantGarde-DemiOblique (P8 = 1019)"),
    font("FNT20", 20.0, "Bookman-Light (P8 = 1020)"),
    font("FNT21", 21.0, "Bookman-LightItalic (P8 = 1021)"),
    font("FNT22", 22.0, "Bookman-Demi (P8 = 1022)"),
    font("FNT23", 23.0, "Bookman-DemiItalic (P8 = 1023)"),
    font("FNT24", 24.0, "NewCenturySchlbk-Roman (P8 = 1024)"),
    font("FNT25", 25.0, "NewCenturySchlbk-Bold (P8 = 1025)"),
    font("FNT26", 26.0, "NewCenturySchlbk-Italic (P8 = 1026)"),
    font("FNT27", 27.0, "NewCenturySchlbk-BoldItalic (P8 = 1027)"),
    font("FNT28", 28.0, "ZapfChancery-MediumItalic (P8 = 1028)"),
    font("FNT29", 29.0, "Courier (P8 = 1029)"),
    font("FNT30", 30.0, "Courier-Bold (P8 = 1030)"),
    font("FNT31", 31.0, "Courier-Oblique (P8 = 1031)"),
    font("FNT32", 32.0, "Courier-BoldOblique (P8 = 1032)"),
    font("FNT33", 33.0, "Symbol (P8 = 1033)"),
    font("FNT34", 34.0, "ZapfDingbats (P8 = 1034)"),
    font("FNT35", 35.0, "Font 35 (P8 = 1035)"),
    font("FNT36", 36.0, "Font 36 (P8 = 1036)"),
    font("FNT94", 94.0, "Music font (P8 = 1094)"),
];

/// Every word, in lookup order.
pub fn entries() -> impl Iterator<Item = &'static Entry> {
    MARKS.iter().chain(RHYTHMS.iter().flatten()).chain(OTHERS).chain(LINES).chain(SIGNS).chain(TEXTS)
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
