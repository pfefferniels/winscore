//! Code 7: trills, ottavas, harp and piano pedal marks (draw_code7 0x55F340).
//!
//! P7 type: 0 trill (P8 1-5 an accidental above it, P9 wave size, P11 wave
//! level), 8/-8/15 the ottava symbols, 88/-88/155 ottava numbers with dashes
//! up or down, 1 harp pedal diagram (P8 XYZ, P9 ABCD pedal positions), 21/22
//! pedal lines (P8 notch, P9 notch height), 23/24/25 the symbols Ped., *
//! and 120 (P9 size); any other type draws the graphic piano pedal symbol
//! (P5 XYZ pedals down, P9 size). P5 size (0 = 1), P6 end of the extension
//! line, which draw_line draws as a wave, dashes or a line with the item's
//! P10-P13 and P16-P18 (P18 alone sets P16); P11/P12 brackets and arrows of
//! pedal lines; P15 left offset (applied by item_position).
//!
//! Not drawn yet: the numbers of types 88/-88/155 (code 10's draw_number),
//! and the 8va/8ba/15ma symbols 45-47, which the engine draws as text.

use crate::canvas::{Canvas, Pen};
use crate::codes::line::{self, end_mark, End, Params};
use crate::document::{Document, ItemRef};
use crate::page::P3_UNIT;
use crate::staff::{Staff, STEP_UNIT, UNITS_PER_SCALE_STEP};
use crate::symbols::{self, draw_library_symbol, ItemContext, SymbolCall};
use crate::units::{constant, real, trunc, Pos};

const TRILL: i32 = 0;
const HARP: i32 = 1;
const OTTAVA: i32 = 8;
const OTTAVA_BASSA: i32 = -8;
const QUINDICESIMA: i32 = 15;
const OTTAVA_UP: i32 = 88;
const OTTAVA_DOWN: i32 = -88;
const QUINDICESIMA_UP: i32 = 155;
const PEDAL_LINE: i32 = 21;
const PEDAL_LINE_WITHOUT_DIP: i32 = 22;
/// P7 23, 24, 25 draw these library symbols.
const PEDAL_SYMBOLS: [(i32, i32); 3] = [(23, 70), (24, 71), (25, 120)];

const TRILL_SYMBOL: i32 = 37;
const FIRST_ACCIDENTAL_SYMBOL: i32 = 5;
const PIANO_PEDAL_SYMBOL: i32 = 48;
const PIANO_PEDAL_FILLER: i32 = 49;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let step = doc.staff_of(item).step;
    draw(doc, canvas, ItemContext::of(item), doc.position(item), step, &Params::of(item));
}

/// draw_code7 with its globals given: the symbol context of the calling
/// item (IP2 names the staff whose levels apply; IP1 becomes 9), X_POS and
/// Y_POS `at`, STEP `step` and the P-array `params`. Notes draw their trill
/// marks through this.
pub fn draw(doc: &Document<'_>, canvas: &mut Canvas<'_>, context: ItemContext, at: Pos, step: f64, params: &Params) {
    let mark = Mark::new(doc, context, at, step, params);
    match mark.kind {
        TRILL => trill(&mark, canvas),
        HARP => harp(&mark, canvas),
        PEDAL_LINE | PEDAL_LINE_WITHOUT_DIP => pedal_line(&mark, canvas),
        OTTAVA | OTTAVA_BASSA | QUINDICESIMA => ottava_symbol(&mark, canvas),
        OTTAVA_UP | OTTAVA_DOWN | QUINDICESIMA_UP => ottava_number(&mark, canvas),
        kind => match PEDAL_SYMBOLS.iter().find(|&&(k, _)| k == kind) {
            Some(&(_, number)) => {
                let call = SymbolCall::sized(number, f64::from(mark.p(9)), 0.0);
                draw_library_symbol(doc, &mark.context, canvas, mark.at, mark.step(), &call);
            }
            None => piano_pedal(&mark, canvas),
        },
    }
}

/// draw_code7 sets IP1 = 9 before drawing its symbols.
const SYMBOL_CODE: i32 = 9;

/// The item as draw_code7 prepares it.
struct Mark<'a, 'd> {
    doc: &'a Document<'d>,
    /// The globals draw_clef and draw_symbol read, with the item's IP10 as pixel thickness.
    context: ItemContext,
    staff: Staff,
    /// STEP.
    step: f64,
    /// X_POS (with P15) and Y_POS.
    at: Pos,
    /// P1…P50, with P16 = 1 when P18 is set.
    params: Params,
    kind: i32,
    /// P5, 0 read as 1.
    size: f64,
}

impl<'a, 'd> Mark<'a, 'd> {
    fn new(doc: &'a Document<'d>, context: ItemContext, at: Pos, step: f64, params: &Params) -> Self {
        let mut params = params.clone();
        if params.p(18) != 0.0 {
            params.set(16, 1.0);
        }
        Self {
            doc,
            context: ItemContext { code: SYMBOL_CODE, ..context },
            staff: doc.staves.get(context.staff),
            step,
            at,
            kind: trunc(f64::from(params.p(7))),
            size: match params.p(5) {
                0.0 => 1.0,
                p5 => f64::from(p5),
            },
            params,
        }
    }

    fn p(&self, n: usize) -> f32 {
        self.params.p(n)
    }

    fn ip(&self, n: usize) -> i32 {
        trunc(f64::from(self.p(n)))
    }

    fn step(&self) -> f64 {
        self.step
    }

    fn scale_step(&self) -> f64 {
        real(UNITS_PER_SCALE_STEP * self.step())
    }

    /// The symbol size factor P5 × 1.1.
    fn symbol_size(&self) -> f64 {
        real(self.size * constant(1.1))
    }

    /// `width` step units of the mark's size right of X_POS.
    fn after(&self, width: f32) -> f64 {
        real(self.size * f64::from(width) * self.step() + self.at.x)
    }

    /// P8 and P9 for ottava dashes: by default 1 and 1.5 scale steps of a size-1 mark.
    fn dash_lengths(&self) -> (f32, f32) {
        match self.p(8) {
            0.0 => {
                let dash = real(self.step() * self.size / STEP_UNIT);
                (dash as f32, real(dash * 1.5) as f32)
            }
            p8 => (p8, self.p(9)),
        }
    }

    /// The symbol context with IP10 set to `pixels`.
    fn with_pixels(&self, pixels: i32) -> ItemContext {
        ItemContext { pixels, ..self.context }
    }

    fn library_symbol(&self, canvas: &mut Canvas<'_>, context: &ItemContext, at: Pos, number: i32, size: f64) {
        draw_library_symbol(self.doc, context, canvas, at, self.step(), &SymbolCall::sized(number, size, size));
    }

    fn clef_symbol(&self, canvas: &mut Canvas<'_>, context: &ItemContext, at: Pos, number: i32, size: f64) {
        symbols::draw_clef(self.doc, context, canvas, at, self.step(), number, (size, size));
    }
}

/// draw_line's IP7 for the extension line.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Extension {
    Wave = -1,
    Line = 0,
    Dashes = 1,
}

/// The extension from `x` to P6 at `level` (draw_code7 0x560474): waves and
/// dashes 0.4 scale steps higher. `p8`, `p9` are draw_line's P8 and P9.
fn extend(mark: &Mark<'_, '_>, style: Extension, level: f64, x: f64, (p8, p9): (f32, f32), canvas: &mut Canvas<'_>) {
    if mark.ip(6) == 0 {
        return;
    }
    let level = match style {
        Extension::Line => level,
        _ => real(level + constant(0.4)),
    };
    let params = mark.params.clone().with(5, level as f32).with(7, style as i32 as f32).with(8, p8).with(9, p9);
    line::draw_with_step(&params, Pos::new(x, mark.staff.y(level)), &mark.staff, mark.step, canvas);
}

/// P7 = 0: the trill symbol a scale step above P4, an accidental for P8 1-5,
/// and a wave from 22.85 step units right of P3 to P6.
fn trill(mark: &Mark<'_, '_>, canvas: &mut Canvas<'_>) {
    let y = real(mark.scale_step() + mark.at.y);
    let context = mark.with_pixels(match mark.ip(28) {
        0 => -1,
        ip28 => ip28,
    });
    mark.clef_symbol(canvas, &context, Pos::new(mark.at.x, y), TRILL_SYMBOL, mark.symbol_size());
    let wave_size = match mark.p(9) {
        0.0 if mark.ip(6) != 0 => 1.0,
        p9 => f64::from(p9),
    };
    let accidental = mark.ip(8);
    if accidental != 0 && accidental <= 5 {
        trill_accidental(mark, &context, accidental, y, canvas);
    }
    let level = real(f64::from(mark.p(4)) + constant(2.2) + f64::from(mark.p(11)) - wave_size);
    let wave = (real(mark.size * wave_size) as f32, 0.0);
    extend(mark, Extension::Wave, level, mark.after(22.85), wave, canvas);
}

/// Accidental `kind` (1 flat … 5 double sharp) above and right of the trill.
fn trill_accidental(mark: &Mark<'_, '_>, context: &ItemContext, kind: i32, y: f64, canvas: &mut Canvas<'_>) {
    let size = real(mark.size * constant(0.65));
    let dx = real(mark.size * 23.0 * mark.step());
    let dx = match kind {
        4 => real(dx * constant(1.3)),
        5 => real(dx * constant(1.11)),
        _ => dx,
    };
    let lift = if kind == 2 || kind == 3 { constant(3.6) } else { 3.0 };
    let lift = real(mark.scale_step() * mark.size * lift);
    let at = Pos::new(real(dx + mark.at.x), real(lift + y));
    mark.clef_symbol(canvas, context, at, FIRST_ACCIDENTAL_SYMBOL + kind, size);
}

/// P7 = 8, -8, 15: the 8va, 8ba or 15ma symbol and dashes to P6.
fn ottava_symbol(mark: &Mark<'_, '_>, canvas: &mut Canvas<'_>) {
    let dashes = mark.dash_lengths();
    let (number, width) = match mark.kind {
        OTTAVA => (45, 43.0),
        OTTAVA_BASSA => (46, 43.0),
        _ => (47, 62.0),
    };
    let size = real(mark.symbol_size() * constant(0.75));
    mark.library_symbol(canvas, &mark.with_pixels(0), mark.at, number, size);
    extend(mark, Extension::Dashes, f64::from(mark.p(4)), mark.after(width), dashes, canvas);
}

/// P7 = 88, -88, 155: the number 8 or 15 and dashes to P6, raised by 1.5
/// symbol sizes except for -88.
fn ottava_number(mark: &Mark<'_, '_>, canvas: &mut Canvas<'_>) {
    let dashes = mark.dash_lengths();
    let width = if mark.kind.abs() == OTTAVA_UP { 18.0 } else { 29.0 };
    let level = f64::from(mark.p(4));
    let level = match mark.kind {
        OTTAVA_DOWN => level,
        _ => real(mark.symbol_size() * 1.5 + level),
    };
    extend(mark, Extension::Dashes, level, mark.after(width), dashes, canvas);
}

/// The graphic piano pedal symbol (P7 = 20): P5 XYZ fills the left, middle
/// and right pedal; P9 is the size (0.4 per unit); a line runs at P4 from
/// P8 (or the symbol) to P6.
fn piano_pedal(mark: &Mark<'_, '_>, canvas: &mut Canvas<'_>) {
    let size = match real(f64::from(mark.p(9)) * constant(0.4)) {
        0.0 => constant(0.4),
        s => s,
    };
    let pedals = mark.ip(5);
    if pedals != 0 {
        let gap = real(size * 53.0 * mark.step());
        let x = mark.at.x;
        let down = [(pedals / 100 != 0, x), (pedals % 100 / 10 != 0, real(gap + x)), (pedals % 10 != 0, real(gap + x + gap))];
        down.into_iter().filter(|&(on, _)| on).for_each(|(_, x)| {
            mark.library_symbol(canvas, &mark.context, Pos::new(x, mark.at.y), PIANO_PEDAL_FILLER, size);
        });
    }
    mark.library_symbol(canvas, &mark.with_pixels(0), mark.at, PIANO_PEDAL_SYMBOL, size);
    let x = match mark.p(8) {
        0.0 => mark.at.x,
        p8 => real(f64::from(p8) * P3_UNIT),
    };
    extend(mark, Extension::Line, f64::from(mark.p(4)), x, (mark.p(8), 0.0), canvas);
}

/// P7 = 21, 22: a pedal line at P4 from P3 to P6 with a notch at P8 (or at
/// P3) rising P9 scale steps (default 2) and, for 21, dipping half as far
/// below; P11/P12 under 100 are brackets to that level, above it arrows.
fn pedal_line(mark: &Mark<'_, '_>, canvas: &mut Canvas<'_>) {
    let level = f64::from(mark.p(4));
    let height = match mark.p(9) {
        0.0 => 2.0,
        p9 => f64::from(p9),
    };
    let unit = real(mark.step() * 6.0);
    let scale_step = mark.scale_step();
    let y = mark.at.y;
    let at_level = |x: f64, v: f64| Pos::new(x, mark.staff.y(real(v + level)));
    let start = mark.at;
    let pen = match mark.p(11) {
        0.0 => Pen::Stroke,
        p11 if p11 >= 100.0 => end_mark(canvas, start, p11, End::Start, false, scale_step),
        p11 => {
            canvas.point(at_level(start.x, f64::from(p11)), Pen::Stroke);
            Pen::Continue
        }
    };
    canvas.point(start, pen);
    let notch = match mark.p(8) {
        0.0 => start.x,
        p8 => {
            let x = real(f64::from(p8) * P3_UNIT);
            canvas.point(Pos::new(x, y), Pen::Continue);
            x
        }
    };
    let peak = real(unit + notch);
    canvas.point(Pos::new(peak, mark.staff.y(real(height + level))), Pen::Continue);
    let mut back = real(unit + peak);
    if mark.kind != PEDAL_LINE_WITHOUT_DIP {
        canvas.point(Pos::new(back, mark.staff.y(real(level - height / 2.0))), Pen::Continue);
        back = real(unit + back);
    }
    canvas.point(Pos::new(back, y), Pen::Continue);
    let end = Pos::new(real(f64::from(mark.p(6)) * P3_UNIT), y);
    canvas.point(end, Pen::Continue);
    match mark.p(12) {
        0.0 => {}
        p12 if p12 >= 100.0 => {
            end_mark(canvas, end, p12, End::Finish, false, scale_step);
        }
        p12 => canvas.point(at_level(end.x, f64::from(p12)), Pen::Continue),
    }
}

/// P7 = 1: the harp pedal diagram, a vertical bar of 8 sizes at P3 + P15,
/// a horizontal bar through P4, and a box per pedal (P8: D C B, P9: E F G A)
/// up (0), on (1) or below (2) the bar.
fn harp(mark: &Mark<'_, '_>, canvas: &mut Canvas<'_>) {
    let centre = real(f64::from(mark.p(15)) + f64::from(mark.p(3)));
    let unit = real(mark.step() * mark.size / STEP_UNIT);
    let half_bar = real(mark.size * 4.0);
    let p4 = f64::from(mark.p(4));
    let bars = mark.params.clone().with(7, 0.0).with(8, 0.0).with(9, 0.0).with(10, 1.0).with(17, 0.0).with(18, 0.0);
    let upright = bars.clone().with(6, centre as f32).with(5, real(half_bar + p4) as f32);
    line::draw_with_step(&upright, Pos::new(mark.at.x, mark.staff.y(real(p4 - half_bar))), &mark.staff, mark.step, canvas);
    let across = bars.with(5, p4 as f32).with(6, real(unit * 12.0 + centre) as f32).with(3, centre as f32);
    let left = real((centre - unit * 9.5) * P3_UNIT);
    line::draw_with_step(&across, Pos::new(left, mark.at.y), &mark.staff, mark.step, canvas);

    let rise = real(mark.staff.y(real(mark.size * 2.5 + p4)) - mark.at.y);
    let top = real(mark.at.y - rise * 2.0);
    let spacing = real(unit * 375.0);
    let pedal_box = PedalBox::new(mark);
    let sides = [(real((centre - unit * 7.5) * P3_UNIT), mark.ip(8), 3), (real((unit * 2.5 + centre) * P3_UNIT), mark.ip(9), 4)];
    sides.into_iter().for_each(|(first_x, positions, count)| {
        let xs = std::iter::successors(Some(first_x), |&x| Some(real(spacing + x)));
        digits(positions, count).zip(xs).for_each(|(position, x)| {
            pedal_box.draw(canvas, Pos::new(x, real(rise * f64::from(position) + top)));
        });
    });
}

/// The `count` decimal digits of `value` from the left, the first taking
/// whatever lies above them.
fn digits(value: i32, count: u32) -> impl Iterator<Item = i32> {
    (0..count).map(move |i| {
        let place = 10_i32.pow(count - 1 - i);
        if i == 0 {
            value / place
        } else {
            value % (place * 10) / place
        }
    })
}

/// A harp pedal: draw_box 0x433530 type 0, filled (P13 = 1), one size wide
/// and three high, its top slanted by P10 scale steps.
struct PedalBox {
    half_width: f64,
    half_height: f64,
    slant: f64,
}

impl PedalBox {
    fn new(mark: &Mark<'_, '_>) -> Self {
        let step = mark.step();
        let height = real(mark.size * 3.0);
        Self {
            half_width: real(step * 3.5 * mark.size),
            half_height: real(step * 3.5 * height),
            slant: real(step * 7.0 * f64::from(mark.p(10))),
        }
    }

    fn draw(&self, canvas: &mut Canvas<'_>, at: Pos) {
        let (left, right) = (real(at.x - self.half_width), real(self.half_width + at.x));
        let (bottom, top) = (real(at.y - self.half_height), real(self.half_height + at.y));
        canvas.fill([[
            Pos::new(left, bottom),
            Pos::new(right, bottom),
            Pos::new(real(self.slant + right), top),
            Pos::new(real(self.slant + left), top),
            Pos::new(left, bottom),
        ]]);
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn digits_from_the_left() {
        assert_eq!(digits(12, 3).collect::<Vec<_>>(), vec![0, 1, 2]);
        assert_eq!(digits(1201, 4).collect::<Vec<_>>(), vec![1, 2, 0, 1]);
        assert_eq!(digits(2222, 3).collect::<Vec<_>>(), vec![22, 2, 2]);
    }
}
