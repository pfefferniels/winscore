//! Code 1: notes (draw_note 0x4EFEC0).
//!
//! A note is drawn in the engine's order: ledger lines (flushed on their own,
//! in the staff's colour), head, tails, accidental, stem, dots, mark. The parts
//! share what draw_note derives from the parameters first ([`Note`]): the
//! step unit (the staff's, times P15, or 0.6 for a grace note), the head
//! width, and the position after the P10 offset and the P12 staff change.

pub(crate) mod glyph;
mod head;
mod ledger;
mod mark;
mod tablature;

use crate::canvas::{Canvas, Pen};
use crate::display::print_pen;
use crate::document::{Document, ItemRef};
use crate::text::Font;
use crate::units::{constant, real, trunc, Pos};


/// trunc(Pn), the engine's IPn.
fn ip(item: ItemRef<'_>, n: usize) -> i32 {
    trunc(f64::from(item.p(n)))
}

/// P4, P5, P9 and P12 keep further numbers in their hundreds.
const HUNDREDS: i32 = 100;

/// Grace notes (P4 ± 100) are drawn at this fraction of the size.
const GRACE_SIZE: f32 = 0.6;

/// Head width in step units: 17, or 19 for whole notes and breves.
const HEAD_WIDTH: f32 = 17.0;
const WIDE_HEAD_WIDTH: f32 = 19.0;

/// Steps per scale step.
const STEPS: f32 = 7.0;

const WHOLE: i32 = 2;
const BREVE: i32 = 3;
const HEADLESS: i32 = 7;
/// P6 + 10 puts the head in parentheses.
const PARENTHESISED: std::ops::Range<i32> = 10..20;

const TAIL_SYMBOL: i32 = 20;
const DOT_SYMBOL: i32 = 24;
/// Accidental n (1–5) is symbol n + 5; quarter tones (6–9) and parenthesised
/// accidentals are 134 further on, in the library at 140.
const ACCIDENTAL_SYMBOLS: i32 = 5;
const SPECIAL_ACCIDENTALS: i32 = 134;

/// P10 = 10 and 20 move the head one head width right and left; 110 moves
/// the accidental along with it. Other values are in units of 6 steps.
const OFFSET_RIGHT: f32 = 10.0;
const OFFSET_LEFT: f32 = 20.0;
const OFFSET_RIGHT_WITH_ACCIDENTAL: i32 = 110;
const OFFSET_UNIT: f32 = 6.0;

/// One dot of SCORE's printer at its default 600 dpi, in units (0x78B480 =
/// 4000/dpi): print moves a thick stem inward by its extra width in dots.
const PRINT_DOT: f32 = 4000.0 / 600.0;

/// The stem direction from P5's tens digit. The engine tests for 2 (down)
/// and, in places, for exactly 1; any other digit draws an up stem.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Stem {
    None,
    Up,
    Down,
    /// A tens digit other than 0, 1, 2: drawn up, but not "1" where the engine asks.
    OtherUp,
}

impl Stem {
    fn from_digit(digit: i32) -> Self {
        match digit {
            0 => Stem::None,
            1 => Stem::Up,
            2 => Stem::Down,
            _ => Stem::OtherUp,
        }
    }

    fn is_down(self) -> bool {
        self == Stem::Down
    }
}

/// What draw_note derives from the parameters before drawing anything.
#[derive(Debug, Clone, Copy, PartialEq)]
pub(crate) struct Note {
    /// X_POS after the P10 offset, Y_POS after the P12 staff change.
    origin: Pos,
    /// trunc(P4) without the grace-note hundreds.
    level: i32,
    grace: bool,
    /// 7 × the staff's step: one scale step of the staff.
    scale_step: f64,
    /// The staff's step times P15: the engine's STEP while the note is drawn.
    step: f64,
    /// `step`, times 0.6 for a grace note.
    unit: f64,
    /// P20, the note width factor (0 read as 1).
    width: f64,
    head_width: f64,
    /// The P10 shift of the head, which an accidental does not follow.
    offset: f64,
    /// trunc(P6), with -3 read as 3.
    head: i32,
    stem: Stem,
    /// P5's units digit.
    accidental: i32,
    /// P9's units digit.
    tails: i32,
    /// The ledger lines above the staff start at level 2·n + 3 instead of 13 (P12's hundreds).
    ledger_start: i32,
    /// P12 without its hundreds: 1 shows the note on the staff above, 2 below.
    borrowed_staff: i32,
    /// An AlphaNote head (P6 ±20 … ±25).
    alpha: bool,
}

impl Note {
    /// None for tablature (P6 = -4 or below, outside -20 … -39).
    fn new(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Self> {
        let head = match ip(item, 6) {
            -3 => BREVE,
            h if h <= -3 && h / 20 != -1 => return None,
            h => h,
        };
        let staff = doc.staff_of(item);
        let p4 = ip(item, 4);
        let grace = (p4 / HUNDREDS).abs() == 1 && item.p(15) == 0.0;
        let width = match item.p(20) {
            0.0 => 1.0,
            p20 => f64::from(p20),
        };
        let step = match item.p(15) {
            0.0 => staff.step,
            p15 => real(f64::from(p15) * staff.step),
        };
        let unit = if grace { real(step * constant(GRACE_SIZE)) } else { step };
        let wide = matches!(head % 1000, WHOLE | BREVE);
        let head_width = real(unit * constant(if wide { WIDE_HEAD_WIDTH } else { HEAD_WIDTH }) * width);
        let offset = match item.p(10) {
            0.0 => 0.0,
            _ if ip(item, 10) == OFFSET_RIGHT_WITH_ACCIDENTAL => head_width,
            p10 if p10 == OFFSET_RIGHT => head_width,
            p10 if p10 == OFFSET_LEFT => -head_width,
            p10 => real(step * constant(OFFSET_UNIT) * f64::from(p10)),
        };
        let position = doc.position(item);
        let p12 = ip(item, 12);
        let (ledger_start, borrowed_staff) =
            if p12.abs() >= HUNDREDS { (p12 / HUNDREDS, (p12 % HUNDREDS).abs()) } else { (0, p12) };
        let y = match item.staff() - 2 * borrowed_staff + 3 {
            other if borrowed_staff > 0 && other > 0 => {
                real(f64::from(doc.staves.get(other).level0) + position.y - f64::from(staff.level0))
            }
            _ => position.y,
        };
        let p5 = ip(item, 5) % HUNDREDS;
        Some(Self {
            origin: Pos::new(if offset == 0.0 { position.x } else { real(offset + position.x) }, y),
            level: p4 % HUNDREDS,
            grace,
            scale_step: real(staff.step * constant(STEPS)),
            step,
            unit,
            width,
            head_width,
            offset,
            head,
            stem: Stem::from_digit(p5 / 10),
            accidental: p5 % 10,
            tails: ip(item, 9) % 10,
            ledger_start,
            borrowed_staff,
            alpha: head::is_alpha(ip(item, 6)),
        })
    }

    /// The head width the parts after the head use: the head routine sets
    /// it to 17.1 units for AlphaNotes (0x4F14B0).
    fn drawn_head_width(&self) -> f64 {
        if self.alpha {
            real(self.unit * constant(head::ALPHA_WIDTH))
        } else {
            self.head_width
        }
    }

    /// The stem direction dots and marks assume: a stemless note counts as
    /// stem up below the middle line and stem down from just above it.
    fn implied_stem(&self) -> Stem {
        match self.stem {
            Stem::None if self.level > 6 => Stem::Down,
            Stem::None => Stem::Up,
            stem => stem,
        }
    }
}

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let Some(note) = Note::new(doc, item) else {
        tablature::draw(doc, item, canvas);
        return;
    };
    if ledger::wanted(&note, item) {
        ledger::draw(doc, item, &note, canvas);
    }
    if head::drawn(&note) {
        head::draw(doc, item, &note, canvas);
    }
    if note.tails != 0 {
        tails(doc, item, &note, canvas);
    }
    if note.accidental != 0 {
        accidental(doc, item, &note, canvas);
    }
    let stem_length = match note.stem {
        // As for P14 >= 0, which the engine reads as a length of (about) 0.
        Stem::None if doc.refined() => 0.0,
        Stem::None => unwritten_stem_length(item),
        _ => stem(doc, item, &note, canvas),
    };
    if ip(item, 9) >= 10 {
        dots(doc, item, &note, canvas);
    }
    if ip(item, 11) != 0 {
        mark::draw(doc, item, &note, stem_length, canvas);
    }
}

/// The font a note leaves loaded for the next item (draw_item 0x547358):
/// that of its last text, a fingering mark, an AlphaNote letter or a
/// tablature number.
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    match Note::new(doc, item) {
        None => tablature::font_loaded(doc, item),
        Some(note) => mark::font_loaded(doc, item, &note).or_else(|| head::font_loaded(doc, item, &note)),
    }
}

/// The stem length the marks read when no stem routine ran: the stem
/// routine keeps its f32 length in the IP14 slot, so without it the marks
/// read trunc(P14)'s bits as a float (0 for P14 = 0, NaN when negative,
/// which loses the mark; the refined style reads 0 throughout).
fn unwritten_stem_length(item: ItemRef<'_>) -> f64 {
    f64::from(f32::from_bits(ip(item, 14) as u32))
}

/// P8 without the 100 that asks for a grace-note slash.
fn stem_extension(item: ItemRef<'_>) -> f64 {
    let p8 = f64::from(item.p(8));
    match ip(item, 8) {
        p if p.abs() < HUNDREDS => p8,
        p if p < 0 => real(p8 + 100.0),
        _ => real(p8 - 100.0),
    }
}

/// Extra stem length, in scale steps, that makes room for three or more tails.
fn tail_room(note: &Note) -> f64 {
    if note.tails > 1 {
        real(f64::from(note.tails * 2 - 2) - constant(0.5))
    } else {
        0.0
    }
}

/// amod(P4, 100): the level with the grace-note hundreds removed.
fn level(item: ItemRef<'_>) -> f64 {
    let p4 = f64::from(item.p(4));
    p4 - f64::from(trunc(p4 / 100.0) * 100)
}

/// Tails (0x4F06BB): symbol 20 at the stem end, mirrored for stems up
/// (and for stemless notes), two scale steps apart.
fn tails(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let down = note.stem.is_down();
    let gap = real(-(note.unit * constant(STEPS)));
    let (x, gap, mirror) = if down { (note.origin.x, gap, 1.0) } else { (real(note.origin.x + note.drawn_head_width()), -gap, -1.0) };
    let p8 = f64::from(item.p(8));
    let amod = p8 - f64::from(trunc(p8 / 100.0) * 100);
    let first = real(amod * gap + note.origin.y + gap);
    let first = if note.tails > 1 { real(first - gap / 2.0) } else { first };
    (0..note.tails).fold(first, |y, _| {
        glyph::clef(doc, item, canvas, TAIL_SYMBOL, Pos::new(x, y), (note.width, mirror), note.unit);
        real(gap + y + gap)
    });
}

/// The accidental (0x4F2F31), left of the head's original position: P5's
/// decimals move it left in units of 6 steps (.9x: right), P29 scales it.
/// Print outlines it with the pen of a print-width marker of trunc(P28),
/// which the refined style draws on every medium.
fn accidental(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let p5 = ip(item, 5);
    let digit = note.accidental;
    let symbol = if digit > 5 || p5 / HUNDREDS == 1 { digit + SPECIAL_ACCIDENTALS } else { digit } + ACCIDENTAL_SYMBOLS;
    let shift = real(f64::from(item.p(5)) - f64::from(p5));
    let shift = match shift {
        0.0 => 0.0,
        s if s > constant(0.9) => real(real(constant(0.9) - s) * 60.0 * note.unit),
        s => real(s * 60.0 * note.unit),
    };
    let follows_head = ip(item, 10) == OFFSET_RIGHT_WITH_ACCIDENTAL;
    let shift = if item.p(10) == OFFSET_RIGHT && !follows_head { real(note.offset + shift) } else { shift };
    let size = match item.p(29) {
        0.0 => 1.0,
        p29 => f64::from(p29),
    };
    let at = Pos::new(real(note.origin.x - shift), note.origin.y);
    let pixels = ip(item, 28);
    let widened = doc.refined() && pixels != 0;
    if widened {
        canvas.set_width(print_pen(pixels as f32));
    }
    glyph::clef(doc, item, canvas, symbol, at, (size, size), note.unit);
    if widened {
        canvas.set_width(0.0);
    }
}

/// The stem (0x4F0EB9): from 0.3 scale steps beyond the head's centre (P17
/// moves it) to an octave (+ P8) beyond, at the head's right edge when up.
/// A grace note with P8 ± 100 and a tail gets a slash first. Returns the
/// signed length (0 for heads without a stem), which marks build on.
fn stem(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) -> f64 {
    let extension = stem_extension(item);
    if ip(item, 8).abs() >= HUNDREDS && note.tails != 0 {
        slash(doc, item, note, extension, canvas);
    }
    let length = real((tail_room(note) + constant(STEPS) + extension) * note.unit * constant(STEPS));
    let head_type = head::unparenthesised(ip(item, 6));
    if !has_stem(head_type) {
        return 0.0;
    }
    let down = note.stem.is_down();
    let length = if down { -length } else { length };
    let x = stem_x(doc, item, note);
    let end = real(length + note.origin.y);
    let source = stem_source(item, note, head_type);
    let source = if down { -source } else { source };
    let start = real(note.unit * source + note.origin.y);
    let thickness = stem_thickness(doc, item, note);
    if thickness != 0 {
        canvas.set_width(print_pen(thickness as f32));
    }
    canvas.point(Pos::new(x, start), Pen::Stroke);
    canvas.point(Pos::new(x, end), Pen::Continue);
    if thickness != 0 {
        // The engine leaves the marker set for whatever it prints next,
        // unless P28 is set; only the stem is meant.
        canvas.set_width(0.0);
    }
    length
}

/// P17's hundreds, as |trunc(P17/100)|: in print, the stem's width in
/// 1/600 inch beyond the default pen (a print-width marker, 0x4D4ED2),
/// which the refined style draws on every medium; 0 in the engine style
/// and for AlphaNotes, whose P17 the head routine has set to ±0.1.
fn stem_thickness(doc: &Document<'_>, item: ItemRef<'_>, note: &Note) -> i32 {
    if !doc.refined() || note.alpha {
        return 0;
    }
    trunc(f64::from(item.p(17)) / 100.0).abs()
}

/// The stem's x: the head's left edge for a stem down, its right edge for
/// a stem up. Print moves a thick stem inward by its extra width (in
/// printer dots), so that it stays within the head; so does the refined
/// style.
fn stem_x(doc: &Document<'_>, item: ItemRef<'_>, note: &Note) -> f64 {
    let down = note.stem.is_down();
    let x = if down { note.origin.x } else { real(note.origin.x + note.drawn_head_width()) };
    match stem_thickness(doc, item, note) {
        0 => x,
        thickness => {
            let inward = real(f64::from(thickness) * constant(PRINT_DOT));
            if down {
                real(inward + x)
            } else {
                real(x - inward)
            }
        }
    }
}

/// Where a note's stem ends (internal coordinates) and how far the end
/// moves up for one more scale step of P8 (negative for a stem down), for
/// an editor's handle on it; `None` without a stem.
pub fn stem_end(doc: &Document<'_>, item: ItemRef<'_>) -> Option<(Pos, f64)> {
    let note = Note::new(doc, item)?;
    if note.stem == Stem::None || !has_stem(head::unparenthesised(ip(item, 6))) {
        return None;
    }
    let per_step = real(note.unit * constant(STEPS));
    let length = real((tail_room(&note) + constant(STEPS) + stem_extension(item)) * per_step);
    let x = stem_x(doc, item, &note);
    Some(if note.stem.is_down() {
        (Pos::new(x, note.origin.y - length), -per_step)
    } else {
        (Pos::new(x, note.origin.y + length), per_step)
    })
}

/// Whole notes, breves and library heads 100–198 (but 139) have no stem.
fn has_stem(head_type: i32) -> bool {
    match head_type {
        h if h < WHOLE => true,
        WHOLE | BREVE => false,
        h if h >= 900 => false,
        h => !(100..=198).contains(&h) || h == 139,
    }
}

/// Where the stem starts, in steps from the head's centre: 2.1, 0 for the
/// diamonds and X heads, 7 for the X head; P17 (without its hundreds,
/// which thicken the stem in print) in scale steps. The head routine sets
/// P17 to ±0.1 for AlphaNotes.
fn stem_source(item: ItemRef<'_>, note: &Note, head_type: i32) -> f64 {
    let p17 = match (note.alpha, item.p(5) < 20.0) {
        (true, true) => constant(-0.1),
        (true, false) => constant(0.1),
        (false, _) => f64::from(item.p(17)),
    };
    let p17 = if trunc(p17 / 100.0) != 0 { real(p17 - f64::from(trunc(p17 / 100.0) * 100)) } else { p17 };
    if p17 != 0.0 {
        return real(p17 * constant(STEPS));
    }
    match head_type {
        6 => constant(STEPS),
        4..=8 => 0.0,
        _ => constant(2.1),
    }
}

/// The grace-note slash across the stem near its end (in 0x4F0EB9).
fn slash(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, extension: f64, canvas: &mut Canvas<'_>) {
    let reach = real(note.unit * constant(OFFSET_UNIT));
    let length = real(tail_room(note) + extension);
    let down = note.stem.is_down();
    let (length, levels, columns) = if down {
        (-length, [constant(-5.5), constant(-2.8)], [constant(-1.883), constant(3.8)])
    } else {
        (length, [constant(2.8), constant(5.4)], [constant(0.783), constant(6.5)])
    };
    let size = match item.p(15) {
        0.0 => constant(GRACE_SIZE),
        p15 => f64::from(p15),
    };
    let from = real(level(item) + real(length * size));
    let staff = match note.borrowed_staff {
        0 => item.staff(),
        p12 => item.staff() - 2 * p12 + 3,
    };
    let staff = doc.staves.get(staff);
    let point = |column: f64, step: f64| {
        Pos::new(real(reach * column + note.origin.x), staff.y(real(size * step + from)))
    };
    canvas.point(point(columns[0], levels[0]), Pen::Stroke);
    canvas.point(point(columns[1], levels[1]), Pen::Continue);
}

/// Rhythm dots (in draw_note): symbol 24, 18 units right of the head, half
/// a scale step above a note on a line. P9's decimals move them right in
/// units of 60 (.9x: left), +100 puts them below the line, +1000 one head
/// width further right; P19 moves them in scale steps, P31 scales them.
fn dots(doc: &Document<'_>, item: ItemRef<'_>, note: &Note, canvas: &mut Canvas<'_>) {
    let p9 = f64::from(item.p(9));
    let on_line = note.level % 2 != 0;
    let lift = if on_line { note.scale_step } else { 0.0 };
    let shift = real(p9 - f64::from(trunc(p9)));
    let shift = if shift > constant(0.9) { real(constant(0.9) - shift) } else { shift };
    let code = ip(item, 9);
    let (shift, code) = if code >= 1000 { (real(shift + constant(0.284)), code - 1000) } else { (shift, code) };
    let (lift, code) = if code >= HUNDREDS { (-lift, code - HUNDREDS) } else { (lift, code) };
    let stem = note.implied_stem();
    let gap = if ip(item, 8) == 0 && note.tails != 0 && stem == Stem::Up { constant(16.2) } else { constant(18.0) };
    let dx = real((shift * 60.0 + gap) * note.unit);
    let headless = note.head == HEADLESS || note.head == -1;
    let dx = if stem != Stem::Up && note.tails == 0 && headless { real(dx / 2.0) } else { dx };
    let x = real(note.width * dx + note.origin.x);
    let lift = match item.p(19) {
        0.0 => lift,
        p19 => real(note.scale_step * f64::from(p19) + lift),
    };
    let y = real(note.origin.y + lift);
    let size = if note.grace { constant(GRACE_SIZE) } else { 1.0 };
    let (x, size) = match item.p(31) {
        0.0 => (x, size),
        p31 => {
            let p31 = f64::from(p31);
            (real(x - (p31 - 1.0) * 238.0 * note.unit / 25.0), real(size * p31))
        }
    };
    let count = (code / 10).max(1);
    (0..count).fold(x, |x, _| {
        glyph::clef(doc, item, canvas, DOT_SYMBOL, Pos::new(x, y), (size, size), note.step);
        real(note.unit * 13.0 + x)
    });
}

/// Test files for notes, rests and beams.
#[cfg(test)]
pub(crate) mod tests {
    use super::*;
    use crate::display::{ItemId, Point, Shape, PEN};
    use crate::document::Options;
    use score_format::{Item, MusFile, Word};

    /// A size-1 staff 1, then `items`.
    pub(crate) fn file(items: &[&[f32]]) -> MusFile {
        let trailer = [0.0_f32, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = (trailer.len() as u16).to_le_bytes().to_vec();
        bytes.extend(trailer.iter().flat_map(|w| w.to_le_bytes()));
        let mut file = MusFile::parse(&bytes).expect("an empty file parses");
        let staff: &[f32] = &[8.0, 1.0, 0.0, 0.0, 1.0];
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        file.items = std::iter::once(staff).chain(items.iter().copied()).map(words).collect();
        file
    }

    /// The shapes item `n` draws.
    pub(crate) fn shapes(file: &MusFile, options: Options, n: u32) -> Vec<Shape> {
        let list = crate::render(&Document::with_options(file, options));
        list.shapes.into_iter().filter(|s| s.source == Some(ItemId(n))).collect()
    }

    pub(crate) fn points(shape: &Shape) -> impl Iterator<Item = Point> + '_ {
        shape.paths.iter().flatten().copied()
    }

    /// The middle of a shape's bounding box.
    pub(crate) fn centre(shape: &Shape) -> (i32, i32) {
        let (xs, ys): (Vec<i32>, Vec<i32>) = points(shape).map(|p| (p.x, p.y)).unzip();
        let mid = |v: &[i32]| (v.iter().min().unwrap() + v.iter().max().unwrap()) / 2;
        (mid(&xs), mid(&ys))
    }

    /// A stemless note with a staccato dot on the stem side (P11 = -7).
    fn stemless_staccato(p14: f32) -> MusFile {
        file(&[&[1.0, 1.0, 20.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -7.0, 0.0, 0.0, p14]])
    }

    #[test]
    fn marks_of_stemless_notes_survive_a_negative_p14() {
        let lowest = |options| shapes(&stemless_staccato(-1.0), options, 1).iter().flat_map(points).map(|p| p.y).min();
        assert!(lowest(Options::ENGINE) < Some(-1_000_000), "the engine loses the mark");
        let [_, moved] = &shapes(&stemless_staccato(-1.0), Options::REFINED, 1)[..] else { panic!("head and mark") };
        let [_, unmoved] = &shapes(&stemless_staccato(0.0), Options::REFINED, 1)[..] else { panic!("head and mark") };
        let (moved, unmoved) = (centre(moved), centre(unmoved));
        assert_eq!(moved.0, unmoved.0);
        assert!((unmoved.1 - moved.1 - 175).abs() <= 1, "P14 = -1 lowers the mark a scale step: {moved:?} {unmoved:?}");
    }

    /// The polylines among item 1's shapes: its stem or ledger lines.
    fn strokes(file: &MusFile, options: Options) -> Vec<Shape> {
        shapes(file, options, 1).into_iter().filter(|s| s.kind == crate::display::ShapeKind::Stroke).collect()
    }

    #[test]
    fn p17_hundreds_widen_stems_and_move_them_inward() {
        // A black note at P3 = 20 (x = 5000, head 425 wide), P17 = ±200 and ±300.
        let note = |p5: f32, p17: f32| file(&[&[1.0, 1.0, 20.0, 5.0, p5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, p17]]);
        let stem = |file: &MusFile, options| {
            let [stem] = &strokes(file, options)[..] else { panic!("one stem") };
            (stem.width, stem.paths[0][0].x)
        };
        assert_eq!(stem(&note(10.0, 200.0), Options::ENGINE), (0.0, 5425));
        assert_eq!(stem(&note(10.0, 200.0), Options::REFINED), (print_pen(2.0), 5411));
        assert_eq!(stem(&note(10.0, -200.0), Options::REFINED), (print_pen(2.0), 5411));
        assert_eq!(stem(&note(20.0, 300.0), Options::REFINED), (print_pen(3.0), 5020));
        assert_eq!(stem(&note(10.0, 0.0), Options::REFINED), (0.0, 5425));
        let up = note(10.0, 200.0);
        let end = |options| {
            let doc = Document::with_options(&up, options);
            stem_end(&doc, doc.item(ItemId(1)).expect("the note")).expect("a stem").0
        };
        let (engine, refined) = (end(Options::ENGINE), end(Options::REFINED));
        assert_eq!(refined.y, engine.y);
        assert!((engine.x - refined.x - 13.333).abs() < 0.01, "the handle moves with the stem: {engine:?} {refined:?}");
    }

    #[test]
    fn ledger_lines_take_their_print_width() {
        // P4 = 13: one ledger line above the staff; P15 = 0.
        let note = |p4: f32, p16: f32| file(&[&[1.0, 1.0, 20.0, p4, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, p16]]);
        let width = |file: &MusFile, options| {
            let [line] = &strokes(file, options)[..] else { panic!("one ledger line") };
            line.width
        };
        assert_eq!(width(&note(13.0, 0.0), Options::ENGINE), 0.0);
        assert_eq!(width(&note(13.0, 0.0), Options::REFINED), print_pen(2.0), "two steps heavier than the staff");
        assert_eq!(width(&note(113.0, 0.0), Options::REFINED), print_pen(1.0), "one for a grace note");
        assert_eq!(width(&note(13.0, 5.0), Options::REFINED), print_pen(5.0));
        assert_eq!(width(&note(13.0, 99.0), Options::REFINED), 0.0, "as the staff lines");
    }

    #[test]
    fn p28_widens_the_accidental_pen() {
        let note = |p28: f32| {
            let mut params = [0.0_f32; 28];
            params[..6].copy_from_slice(&[1.0, 1.0, 20.0, 5.0, 2.0, 0.0]);
            params[27] = p28;
            file(&[&params])
        };
        // The head, then the sharp's four parts.
        let widths = |file: &MusFile, options| shapes(file, options, 1).iter().map(|s| s.width).collect::<Vec<_>>();
        let sharp = print_pen(3.0);
        assert_eq!(widths(&note(3.0), Options::REFINED), [0.0, sharp, sharp, sharp, sharp]);
        assert_eq!(widths(&note(3.0), Options::ENGINE), [0.0; 5]);
        assert_eq!(widths(&note(0.0), Options::REFINED), [0.0; 5]);
        assert!(sharp > PEN);
    }
}
