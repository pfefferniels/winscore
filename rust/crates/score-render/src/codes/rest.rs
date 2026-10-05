//! Code 2: rests (draw_rest 0x519C38).
//!
//! P5 is the rest type: 0 quarter, 1–6 eighth to 256th (stacks of the
//! eighth-rest symbol), -1 half, -2 whole, -3 multi-bar (breve) rest, -4
//! repeat sign, -5 a bar rest spread to P9, -6/-7 the two- and four-bar
//! symbols, -11 … -19 composite rests of 1–9 bars; -44 a two-bar repeat;
//! +100 puts the rest in parentheses. P4 moves it from its default level,
//! P6 adds dots (or, from 5, a centring line on the screen; -1 makes it
//! invisible, grey on the screen), P8 a fermata (-1, -2) or a number above,
//! P9 the drawn position of whole and longer rests, P10 a shift, P15 a size
//! factor, P17 moves it to the staff above (1) or below (2).

use crate::canvas::Canvas;
use crate::codes::note::glyph;
use crate::codes::number::{draw_number, number_text, number_text_call, NumberCall};
use crate::text::{font_loaded as text_font_loaded, Font};
use crate::symbols::text_symbol::{draw_text_symbol, text_symbol_font_loaded, TextSymbolCall};
use crate::colour;
use crate::document::{Document, ItemRef};
use crate::page::{self, P3_UNIT};
use crate::staff::Staff;
use crate::units::{amod, constant, real, trunc, Pos};

/// trunc(Pn), the engine's IPn.
fn ip(item: ItemRef<'_>, n: usize) -> i32 {
    trunc(f64::from(item.p(n)))
}

const H_BAR: i32 = -5;
const REPEAT: i32 = -4;
const TWO_BAR_REPEAT: i32 = -44;
/// The rest index t = P5 + 8 of these types.
const T_WHOLE: i32 = 6;
const T_HALF: i32 = 7;
const T_EIGHTH: i32 = 9;
const T_H_BAR: i32 = 3;
const T_REPEAT: i32 = 4;

/// Level of the rest symbol's origin above P4 = 0, by t = P5 + 8 (table 0x7969A8).
const LEVELS: [f32; 13] = [0.0, 8.0, 8.0, 0.0, 0.0, 8.0, 9.0, 7.0, 8.0, 8.0, 6.0, 6.0, 4.0];
/// Whole and half rests at or beyond these levels (P4 mod 100) get a ledger
/// line (tables 0x7969C0, 0x7969C8, by t).
const LEDGER_FROM_ABOVE: [i32; 2] = [4, 5];
const LEDGER_FROM_BELOW: [i32; 2] = [-7, -6];
/// Distance of the first dot from the rest in units, by P5 + 4 (table 0x7969E4).
const DOT_GAPS: [f32; 9] = [0.0, 19.0, 19.0, 19.0, 13.0, 15.5, 18.4, 22.3, 26.2];
/// Parentheses around a rest (P5 ± 100), by P5 + 4: left offset (units/25
/// in P3), level of both, right offset (tables 0x79698C, 0x796954, 0x796970).
const PAREN_LEFT: [f32; 8] = [6.17, 2.13, 2.13, 2.14, 2.33, 1.93, 2.33, 2.63];
const PAREN_LEVEL: [f32; 8] = [0.0, 8.0, 8.9, 7.66, 7.26, 7.26, 6.76, 7.26];
const PAREN_RIGHT: [f32; 8] = [7.26, 4.97, 4.97, 4.96, 3.97, 4.57, 4.97, 6.17];

const GRACE_SIZE: f32 = 0.7;
const BAR_SYMBOL_SIZE: f32 = 0.83;

const FIRST_REST_SYMBOL: i32 = 35;
const DOT_SYMBOL: i32 = 24;
const FERMATA_SYMBOL: i32 = 31;
/// P8 = -3: "G.P.", a symbol draw_symbol writes as text.
const GENERAL_PAUSE_SYMBOL: i32 = 276;
/// The P8 that asks for it.
const GENERAL_PAUSE: i32 = -3;
const TWO_BAR_REPEAT_SYMBOL: i32 = 115;
/// Symbol 118 - t for t = 1, 2: the four- and two-bar rests.
const BAR_SYMBOLS: i32 = 118;
const PARENTHESIS_SYMBOL: i32 = 208;

/// Screen grey of invisible rests (P26 = 0.6).
const INVISIBLE_GREY: f32 = 0.6;

/// What draw_rest derives from the parameters before drawing.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Rest {
    /// The staff drawn on (P17 moves to a neighbour) and its number (CUR_STAFF).
    staff: Staff,
    staff_number: i32,
    /// X_POS of the item, before P10 and P9.
    x: f64,
    /// P5 without the parentheses' hundreds; -44 read as -4.
    kind: i32,
    parenthesised: bool,
    two_bar_repeat: bool,
    dots: i32,
    /// P8: a number above, -1 a fermata, -2 an inverted one.
    number: i32,
    /// The staff's step times P15: the engine's STEP while the rest is drawn.
    step: f64,
    /// `step`, times 0.7 for a grace-size rest.
    unit: f64,
    /// 1, or 0.7 for a grace-size rest.
    size: f64,
    /// P4 without the grace-size hundreds.
    level: f64,
    /// P16, moved for the two-bar repeat's number.
    number_shift: f64,
}

impl Rest {
    /// None for the types the engine does not draw.
    fn new(doc: &Document<'_>, item: ItemRef<'_>, x_pos: f64) -> Option<Self> {
        let p5 = ip(item, 5);
        let parenthesised = p5.abs() >= 100;
        let kind = if parenthesised { p5 % 100 } else { p5 };
        let two_bar_repeat = kind == TWO_BAR_REPEAT;
        let kind = if two_bar_repeat { REPEAT } else { kind };
        if kind < -7 && !(-19..=-11).contains(&kind) {
            return None;
        }
        let staff_number = match ip(item, 17) {
            0 => item.staff(),
            2 => item.staff() - 1,
            _ => item.staff() + 1,
        };
        let staff = if staff_number == item.staff() { doc.staff_of(item) } else { doc.staves.get(staff_number) };
        let number_shift = if two_bar_repeat && ip(item, 8) != 0 {
            real(-(staff.step * constant(3.2) / 25.0))
        } else {
            f64::from(item.p(16))
        };
        let dots = match ip(item, 6) {
            -1 if doc.screen() => 0,
            d if d > 0 && (-7..-3).contains(&kind) => 0,
            d => d,
        };
        let step = match item.p(15) {
            0.0 => staff.step,
            p15 => real(f64::from(p15) * staff.step),
        };
        let p4 = ip(item, 4);
        let p4 = if item.p(15) != 0.0 { p4 % 100 } else { p4 };
        let grace = p4.abs() >= 100;
        let level = f64::from(item.p(4));
        let (unit, size, level) =
            if grace { (real(step * constant(GRACE_SIZE)), constant(GRACE_SIZE), real(amod(level, 100.0))) } else { (step, 1.0, level) };
        Some(Self {
            staff,
            staff_number,
            x: if ip(item, 17) == 0 { x_pos } else { page::x(item.p(3)) },
            kind,
            parenthesised,
            two_bar_repeat,
            dots,
            number: ip(item, 8),
            step,
            unit,
            size,
            level,
            number_shift,
        })
    }

    /// y of a level relative to P4 = 0 of the rest's staff.
    fn y(&self, level: f64) -> f64 {
        self.staff.y(real(level))
    }
}

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    draw(doc, item, page::x(item.p(3)), canvas);
}

/// draw_rest with the X_POS global given: a barline's two-bar repeat sign
/// starts from the barline's X_POS (with its P7 or P15). P17 recomputes it
/// from P3; CW centring and the parentheses work from P3 too.
pub fn draw(doc: &Document<'_>, item: ItemRef<'_>, x_pos: f64, canvas: &mut Canvas<'_>) {
    let Some(rest) = Rest::new(doc, item, x_pos) else { return };
    if invisible_on_screen(doc, item) {
        canvas.colour = colour::from_p26(INVISIBLE_GREY, doc.options.medium);
    }
    let t = rest.kind + 8;
    let shift = p10_shift(item, &rest);
    let x = if shift == 0.0 { rest.x } else { real(shift * P3_UNIT + rest.x) };
    let cw = Centring::of(doc, item);
    let h_bar = match &cw {
        Some(cw) if t == T_H_BAR => (x, real(cw.bars.h_bar_end(cw.p3, rest.unit) * P3_UNIT)),
        _ => (rest.x, real(f64::from(item.p(9)) * P3_UNIT)),
    };
    // The engine stores the centre in P9, so every later redraw uses it.
    let p9 = match &cw {
        Some(cw) if t != T_H_BAR => cw.bars.centre(rest.unit, t),
        _ => f64::from(item.p(9)),
    };
    let x = if trunc(p9) != 0 && trunc(p9) != -1 && t <= T_WHOLE { real(p9 * P3_UNIT) } else { x };
    Drawing { doc, item, rest: &rest, h_bar, canvas }.from(t, x, rest.size, rest.dots, rest.number);
}

/// The P9 a redraw writes into a centred rest (CW, P9 = -1, draw_rest
/// 0x519C38): the middle between the barlines around it, in P3 units, for
/// whole rests and longer (P5 <= -2). None when the rest is not centred,
/// no barline follows it, or for the bar rest P5 = -5, which is spread
/// between the barlines on every draw and keeps P9 = -1.
pub fn centre(doc: &Document<'_>, item: ItemRef<'_>) -> Option<f32> {
    let cw = Centring::of(doc, item)?;
    (cw.t != T_H_BAR).then(|| cw.bars.centre(cw.rest.unit, cw.t) as f32)
}

/// The P9 a draw writes into the edit buffer while the rest is being
/// edited, which leaving edit mode stores: the centre as [`centre`], or
/// for the bar rest P5 = -5 its right end. In edit mode the engine looks
/// for barlines only among the items up to the edited one (ITEM_I); this
/// scans the whole document.
pub fn edit_p9(doc: &Document<'_>, item: ItemRef<'_>) -> Option<f32> {
    let cw = Centring::of(doc, item)?;
    Some(match cw.t {
        T_H_BAR => cw.bars.h_bar_end(cw.p3, cw.rest.unit) as f32,
        t => cw.bars.centre(cw.rest.unit, t) as f32,
    })
}

/// The spacing P6 a draw writes into the edit buffer for a centred
/// composite rest P5 = -13 or -15 … -19: the bar's width × 1.04167 / STEP.
/// draw_rest's test (t < -4, t != -6) leaves out -11, -12 and -14.
pub fn edit_spacing(doc: &Document<'_>, item: ItemRef<'_>) -> Option<f32> {
    let cw = Centring::of(doc, item)?;
    let spaced = cw.t < -4 && cw.t != -6;
    spaced.then(|| {
        let width = real(cw.bars.right - cw.bars.left);
        // One x87 expression: rounded to f32 only when stored.
        real(width * constant(1.04167) / cw.rest.step) as f32
    })
}

/// A rest CW centres (P9 = -1, whole rest or longer) and the barlines
/// around it; None without a barline to its right.
struct Centring {
    rest: Rest,
    t: i32,
    /// P3 with the P10 shift.
    p3: f64,
    bars: Bars,
}

impl Centring {
    fn of(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Self> {
        let rest = Rest::new(doc, item, page::x(item.p(3)))?;
        let t = rest.kind + 8;
        if !centred(item, t) {
            return None;
        }
        let p3 = real(p10_shift(item, &rest) + f64::from(item.p(3)));
        let bars = neighbouring_bars(doc, item, p3, rest.unit)?;
        Some(Self { rest, t, p3, bars })
    }
}

/// CW: P9 = -1 on a whole rest or longer (t = P5 + 8 <= 6).
fn centred(item: ItemRef<'_>, t: i32) -> bool {
    ip(item, 9) == -1 && t <= T_WHOLE
}

/// P10 in P3 units: P10/25 of the rest's step unit.
fn p10_shift(item: ItemRef<'_>, rest: &Rest) -> f64 {
    match item.p(10) {
        0.0 => 0.0,
        p10 => real(rest.unit * f64::from(p10) / 25.0),
    }
}

/// The barlines (or a clef, for composite rests) either side of a rest on
/// its staff, in P3 units, as CW (P9 = -1) finds them (in draw_rest).
#[derive(Debug, Clone, Copy, PartialEq)]
struct Bars {
    left: f64,
    right: f64,
    /// Barline types (P5, 0 above 6) at either end.
    left_type: i32,
    right_type: i32,
    right_is_barline: bool,
}

/// Inner edges of barline types 1–6 for the bar rest, in units (tables
/// 0x796A04 left, 0x796A1C right).
const BAR_LEFT_EDGE: [f32; 7] = [0.0, 0.0, 0.0, 0.0, 3.6, 3.4, 4.0];
const BAR_RIGHT_EDGE: [f32; 7] = [0.0, 1.2, 2.2, 4.4, 1.0, 4.4, 3.0];
const NO_BAR: f32 = 9999.0;

fn neighbouring_bars(doc: &Document<'_>, item: ItemRef<'_>, p3: f64, unit: f64) -> Option<Bars> {
    let staff = item.staff();
    let composite = item.p(5) < -4.0;
    let mut bars =
        Bars { left: -constant(NO_BAR), right: constant(NO_BAR), left_type: 0, right_type: 0, right_is_barline: false };
    doc.items().for_each(|other| {
        let other_staff = other.staff();
        let code = other.code();
        let clef_after = other_staff == staff && code == super::CLEF && composite && f64::from(other.p(3)) > p3;
        if staff < other_staff || !(clef_after || code == super::BARLINE) {
            return;
        }
        let len = other.item.params().len();
        let at = if len > 2 { f64::from(other.p(3)) } else { 0.0 };
        let span = if other.p(4) != 0.0 && len > 3 && code == super::BARLINE { other.p(4).abs() } else { 1.0 };
        if f64::from(staff) >= f64::from(other_staff) + f64::from(span) {
            return;
        }
        let bar_type = || match if len > 4 { trunc(f64::from(other.p(5))) } else { 0 } {
            t if t > 6 => 0,
            t => t,
        };
        if at < bars.right && p3 < at {
            bars.right = at;
            bars.right_type = bar_type();
            bars.right_is_barline = code == super::BARLINE;
        }
        if bars.left < at && at < p3 {
            bars.left = at;
            bars.left_type = bar_type();
        }
    });
    if bars.right == constant(NO_BAR) {
        return None;
    }
    let u = real(unit / 25.0);
    if u * 7.0 < p3 - bars.left {
        bars.left = real(p3 - u * constant(4.5));
        bars.left_type = 0;
    }
    Some(bars)
}

impl Bars {
    /// P9 for a whole rest, multi-bar rest, repeat sign or composite: the
    /// middle of the bar, less a little.
    fn centre(&self, unit: f64, t: i32) -> f64 {
        let width = real(self.right - self.left);
        let less = if t == T_REPEAT { constant(0.137) } else { constant(0.056) };
        real(width * 0.5 + self.left - unit * less)
    }

    /// The right end of the bar rest (P5 = -5) in P3 units.
    fn h_bar_end(&self, p3: f64, unit: f64) -> f64 {
        let u = real(unit / 25.0);
        let (mut left, mut right) = (self.left, self.right);
        if self.right_is_barline {
            if self.right_type != 0 {
                right = real(right - u * constant(BAR_RIGHT_EDGE[self.right_type.clamp(0, 6) as usize]));
            }
            if self.left_type != 0 {
                left = real(u * constant(BAR_LEFT_EDGE[self.left_type.clamp(0, 6) as usize]) + left);
            }
        }
        let end = real(right - p3 + left);
        let margin = real(u * 3.0 + 0.5);
        if margin < right - end {
            real(right - margin)
        } else {
            end
        }
    }
}

/// P6 = -1 on the screen: draw_rest shows the rest in grey (P26 = 0.6).
fn invisible_on_screen(doc: &Document<'_>, item: ItemRef<'_>) -> bool {
    ip(item, 6) == -1 && doc.screen()
}

/// draw_number's font 6 (the meter font), which rest numbers default to.
const DEFAULT_NUMBER_FONT: i32 = 6;

/// The width draw_rest allows for a number, in units of 6 steps (0x51AEFA):
/// narrower for the digit 1.
fn digits_width(number: i32) -> f32 {
    let (units, tens, hundreds) = (number % 10, number % 100 / 10, number / 100);
    match number {
        1 => 1.255,
        n if n < 10 => 1.55,
        11 => 2.65,
        n if n < 100 => match (tens, units) {
            (1, _) => 3.05,
            (_, 1) => 2.95,
            _ => 3.25,
        },
        _ => match (hundreds, tens, units) {
            (1, 1, 1) => 4.3,
            (1, 1, _) => 4.55,
            (1, _, 1) | (_, 1, 1) => 4.45,
            (1, _, _) => 4.55,
            (_, 1, _) => 4.7,
            (_, _, 1) => 4.6,
            _ => 4.9,
        },
    }
}

/// P12, the size of a number or fermata above the rest (0 read as 1).
fn number_scale(item: ItemRef<'_>) -> f64 {
    match item.p(12) {
        0.0 => 1.0,
        p12 => f64::from(p12),
    }
}

/// What draw_rest hands draw_number for the number above: size P12 × 1.2
/// (× 0.7 grace), font IP7 = P14 with P14 cleared, or font 6 with P14 =
/// 1.05; P8, P9, IP17 cleared.
fn number_call(doc: &Document<'_>, item: ItemRef<'_>, rest: &Rest, number: i32, size: f64) -> NumberCall {
    let (font, p14) = match item.p(14) {
        0.0 => (DEFAULT_NUMBER_FONT, constant(1.05)),
        p14 => (trunc(f64::from(p14)), 0.0),
    };
    NumberCall {
        value: number,
        p5: number as f32,
        size: real(number_scale(item) * constant(1.2) * size) as f32,
        font,
        frame: 0,
        frame_thickness: 0,
        p14: p14 as f32,
        p17: 0,
        p26: if invisible_on_screen(doc, item) { INVISIBLE_GREY } else { item.p(26) },
        step: Some(rest.step),
        ..NumberCall::of(item)
    }
}

/// The font a rest leaves loaded for the next item (draw_item 0x547358):
/// that of its number. The number's position does not matter for it.
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    let rest = Rest::new(doc, item, page::x(item.p(3)))?;
    if rest.dots < 0 || rest.kind == H_BAR {
        return None;
    }
    match rest.number {
        GENERAL_PAUSE => text_symbol_font_loaded(doc, &general_pause_call(doc, item, &rest, rest.size)),
        n if n > 0 => {
            let call = number_call(doc, item, &rest, n, rest.size);
            let text = number_text(call.value, call.p5, call.p17, call.p18);
            text_font_loaded(doc, &number_text_call(&call, Pos::default(), &text, Font::TIMES))
        }
        _ => None,
    }
}

/// P8 = -3: "G.P.", which draw_symbol writes as text from the rest's
/// globals: P3 with the P10 shift, P16 as draw_rest moved it, at the
/// fermata's size P12 (× 0.7 grace).
fn general_pause_call(doc: &Document<'_>, item: ItemRef<'_>, rest: &Rest, size: f64) -> TextSymbolCall {
    let shift = p10_shift(item, rest);
    let sx = real(size * number_scale(item));
    TextSymbolCall {
        size_x: sx,
        size_y: sx,
        staff: rest.staff_number,
        p3: real(shift + f64::from(item.p(3))) as f32,
        p16: rest.number_shift as f32,
        p26: if invisible_on_screen(doc, item) { INVISIBLE_GREY } else { item.p(26) },
        step: Some(rest.step),
        ..TextSymbolCall::of(doc, item, GENERAL_PAUSE_SYMBOL)
    }
}

/// The drawing state draw_rest carries between its stages.
struct Drawing<'d, 'a, 'c> {
    doc: &'d Document<'a>,
    item: ItemRef<'a>,
    rest: &'d Rest,
    /// Left and right end of a bar rest (P5 = -5).
    h_bar: (f64, f64),
    canvas: &'d mut Canvas<'c>,
}

impl Drawing<'_, '_, '_> {
    /// From label 0x51A655: the level table, then marks, number, dots and the rest.
    fn from(&mut self, t: i32, x: f64, size: f64, dots: i32, number: i32) {
        let rest = *self.rest;
        let mut level = match t {
            t if t > 12 => 4.0,
            t if t > 0 => constant(LEVELS[t as usize]),
            _ => 0.0,
        };
        let mut flag_step = match self.item.p(15) {
            0.0 => 2.0,
            p15 => real(f64::from(p15) * 2.0),
        };
        if size != 1.0 {
            if t < 0 {
                self.symbol_stack(t, x, level, flag_step, size, number);
                return;
            }
            flag_step = constant(1.4);
            if t >= 10 {
                level = real(real(level + constant(0.7)) + constant(0.7));
            }
        }
        let mut dots = dots;
        let mut number = number;
        loop {
            let skips_dots = dots == 0 || t < 1 || t == T_REPEAT;
            if skips_dots {
                if self.item.p(5) as i32 % 100 == H_BAR && number == 0 {
                    number = -1;
                }
                if number == 0 {
                    break;
                }
            }
            if dots < 0 {
                return;
            }
            let mut x = x;
            if t == T_H_BAR {
                let Some(centre) = self.h_bar(number) else { return };
                x = centre;
            } else if self.doc.screen() {
                let reach = real(rest.unit * if t == T_REPEAT { constant(40.8) } else { constant(16.8) });
                if dots >= 5 && t >= -2 {
                    self.centring_line(x, reach);
                    dots = 0;
                    if number == 0 {
                        break;
                    }
                }
            }
            if number == 0 {
                self.dots(x, dots, size);
                break;
            }
            self.above(t, x, number, size);
            if t == T_H_BAR {
                return;
            }
            number = 0;
        }
        let level = real(rest.level + level);
        let (t, x) = if t > T_EIGHTH { (T_EIGHTH, real(x - rest.unit * 3.0)) } else { (t, x) };
        self.symbol_stack(t, x, level, flag_step, size, 0);
    }

    /// The bar rest of type -5: two vertical strokes and a thick bar from
    /// the item's position to P9. Returns where a number above goes.
    fn h_bar(&mut self, number: i32) -> Option<f64> {
        let rest = *self.rest;
        let (left, right) = self.h_bar;
        let (low, high) = (rest.y(rest.level + 5.0), rest.y(rest.level + 9.0));
        [left, right].into_iter().for_each(|x| self.canvas.segment(Pos::new(x, low), Pos::new(x, high)));
        let (top, bottom) = (rest.y(rest.level + constant(7.75)), rest.y(rest.level + constant(6.25)));
        self.canvas.fill([[Pos::new(left, top), Pos::new(right, top), Pos::new(right, bottom), Pos::new(left, bottom)]]);
        if number <= 0 {
            return None;
        }
        Some(real((right - left) * 0.5 + left - rest.unit * 8.0))
    }

    /// P6 >= 5 on the screen: a line of P6 P3 units either side, 6 scale steps up.
    fn centring_line(&mut self, x: f64, reach: f64) {
        let y = real(self.rest.step * 42.0 + self.item_y());
        let half = real(f64::from(self.item.p(6)) * P3_UNIT);
        self.canvas.segment(Pos::new(real(x - half), y), Pos::new(real(reach + x + half), y));
    }

    /// Y_POS as item_position left it for the rest's staff.
    fn item_y(&self) -> f64 {
        self.rest.staff.y(amod(f64::from(self.item.p(4)), 100.0))
    }

    /// Augmentation dots: symbol 24 level with the rest's upper part.
    fn dots(&mut self, x: f64, dots: i32, size: f64) {
        let rest = *self.rest;
        let kind = rest.kind;
        let level = if kind > 2 { 10.0 } else { 8.0 };
        let y = rest.y(rest.level + level);
        let gap = constant(DOT_GAPS[(kind + 4).clamp(0, 8) as usize]);
        let p6 = f64::from(self.item.p(6));
        let shift = real(amod(p6, 1.0));
        let x = if shift != 0.0 { real(shift * 60.0 * rest.unit + x) } else { x };
        let first = real(rest.unit * gap + x);
        (0..dots.max(1)).fold(first, |x, _| {
            glyph::clef(self.doc, self.item, self.canvas, DOT_SYMBOL, Pos::new(x, y), (size, size), rest.step);
            real(rest.unit * 13.0 + x)
        });
    }

    /// A fermata (P8 < 0) or a number (P8 > 0) above the rest.
    fn above(&mut self, t: i32, x: f64, number: i32, size: f64) {
        if number < 0 {
            self.fermata(x, number, size);
        } else {
            self.number(t, x, number, size);
        }
    }

    /// The number above (0x51AEFA): centred by a width read off its digits,
    /// at P12 × 1.2 (× 0.7 grace) size, 12 scale steps above P4 (+ P11),
    /// in the P14 font (IP7) or font 6 at P14 = 1.05.
    fn number(&mut self, t: i32, x: f64, number: i32, size: f64) {
        let rest = *self.rest;
        let item = self.item;
        let width = real(number_scale(item) * constant(digits_width(number)));
        let base = if t == T_REPEAT { constant(3.4) } else { constant(1.42) };
        let dx = real((base - width) * rest.unit * 6.0 * size);
        let y = rest.y(real(rest.level + 12.0 + f64::from(item.p(11))));
        let at = Pos::new(real(rest.number_shift * P3_UNIT + (dx + x)), y);
        let own = self.canvas.colour;
        draw_number(self.doc, item, self.canvas, at, &number_call(self.doc, item, &rest, number, size));
        self.canvas.colour = own;
    }

    fn fermata(&mut self, x: f64, number: i32, size: f64) {
        let rest = *self.rest;
        let item = self.item;
        let scale = number_scale(item);
        let offset = constant(match rest.kind {
            k if k < 0 => 1.42,
            0 => 0.95,
            1 => 1.35,
            _ => 1.15,
        });
        let six = real(rest.unit * 6.0);
        let offset = real(six * offset);
        let narrow = real(scale * constant(1.69) * six);
        let x = real(rest.number_shift * P3_UNIT + (offset + x - narrow));
        let sx = real(size * scale);
        let (sy, level) = if number == -2 { (-sx, 1.0) } else { (sx, 13.0) };
        let level = if item.p(4) > 0.0 { real(rest.level + level) } else { level };
        let y = rest.y(real(f64::from(item.p(11)) + level));
        if ip(item, 8) == GENERAL_PAUSE {
            draw_text_symbol(self.doc, item, self.canvas, &general_pause_call(self.doc, item, &rest, size));
            return;
        }
        glyph::clef(self.doc, self.item, self.canvas, FERMATA_SYMBOL, Pos::new(x, y), (sx, sy), rest.step);
    }

    /// From label 0x51B349: the rest symbol, repeated two scale steps up and
    /// 4.5 units right for each further flag, then parentheses and ledger line.
    /// `number` is P8 when the number stage was skipped (grace-size composites).
    fn symbol_stack(&mut self, t: i32, x: f64, level: f64, flag_step: f64, size: f64, number: i32) {
        let rest = *self.rest;
        let (mut x, mut level, mut kind) = (x, level, rest.kind);
        loop {
            let level_used = if t < 0 { real(rest.level + 8.0) } else { level };
            let y = rest.y(level_used);
            let (t, size) = if rest.two_bar_repeat {
                (TWO_BAR_REPEAT_SYMBOL - FIRST_REST_SYMBOL, real(size * constant(BAR_SYMBOL_SIZE)))
            } else {
                (t, size)
            };
            if t < 3 {
                self.bar_rests(t, x, y, size, number);
                return;
            }
            glyph::clef(self.doc, self.item, self.canvas, t + FIRST_REST_SYMBOL, Pos::new(x, y), (size, size), rest.step);
            if kind < 2 {
                self.tail(t, x, y);
                return;
            }
            kind -= 1;
            level = real(flag_step + level);
            x = real(rest.unit * 4.5 + x);
        }
    }

    /// Two- and four-bar symbols (t = 2, 1), and the composite rests of
    /// P5 = -11 … -19 built from them and a whole rest.
    fn bar_rests(&mut self, t: i32, x: f64, y: f64, size: f64, number: i32) {
        let rest = *self.rest;
        let small = real(size * constant(BAR_SYMBOL_SIZE));
        let draw = |canvas: &mut Canvas<'_>, t: i32, x: f64| {
            glyph::library(self.doc, self.item, canvas, BAR_SYMBOLS - t, Pos::new(x, y), (small, small), rest.step);
        };
        if t >= 0 {
            draw(self.canvas, t, x);
            return;
        }
        let spacing = match self.item.p(6) {
            0.0 => 1.0,
            p6 => f64::from(p6),
        };
        let spacing = real(rest.step * spacing);
        let at = |units: f32| real(spacing * constant(units) + x);
        let back = |units: f32| real(x - spacing * constant(units));
        // Pieces of 4 (t = 1) and 2 (t = 2) bars, then maybe a whole rest.
        let (pieces, whole): (Vec<(i32, f64)>, Option<f64>) = match -t - 2 {
            1 => (vec![], Some(x)),
            2 => (vec![(2, x)], None),
            3 => (vec![(2, back(24.0))], Some(at(24.0))),
            4 => (vec![(1, x)], None),
            5 => (vec![(1, back(24.0))], Some(at(24.0))),
            6 => (vec![(1, back(24.0)), (2, at(24.0))], None),
            7 => (vec![(1, back(36.0)), (2, x)], Some(at(36.0))),
            8 => (vec![(1, back(24.0)), (1, at(24.0))], None),
            9 => (vec![(1, back(36.0)), (1, x)], Some(at(36.0))),
            _ => (vec![], None),
        };
        pieces.iter().for_each(|&(t, x)| draw(self.canvas, t, x));
        if let Some(x) = whole {
            self.from(T_WHOLE, x, size, 0, number);
        }
    }

    /// After the last symbol: parentheses (P5 ± 100) and the ledger line of
    /// a whole or half rest outside the staff.
    fn tail(&mut self, t: i32, x: f64, y: f64) {
        let rest = *self.rest;
        if rest.parenthesised {
            self.parentheses();
        }
        if !(T_WHOLE..=T_HALF).contains(&t) || self.item.p(30) < 0.0 {
            return;
        }
        let level = ip(self.item, 4) % 100;
        let i = (t - T_WHOLE) as usize;
        if level < LEDGER_FROM_ABOVE[i] && level > LEDGER_FROM_BELOW[i] {
            return;
        }
        let left = real(x - real(rest.unit * 8.0));
        let right = real(real(rest.unit * 25.0) + x);
        self.canvas.segment(Pos::new(left, y), Pos::new(right, y));
    }

    /// Symbol 208 either side, placed through P3/P4 as item_position would.
    fn parentheses(&mut self) {
        let rest = *self.rest;
        let item = self.item;
        let k = (rest.kind + 4).clamp(0, 7) as usize;
        let unit = real(rest.unit / 25.0);
        let p3 = real(p10_shift(item, &rest) + f64::from(item.p(3)));
        let p3 = if item.p(5) < -101.0 && item.p(9) > 0.0 { f64::from(item.p(9)) } else { p3 };
        let mut p4 = real(amod(f64::from(item.p(4)), 100.0) + constant(PAREN_LEVEL[k]));
        if k > 5 && rest.step != rest.unit {
            p4 = real(p4 + 1.0);
        }
        let size = if k < 4 { 1.0 } else { constant(1.9) };
        let size = if rest.size != 1.0 { real(size * constant(GRACE_SIZE)) } else { size };
        let y = rest.staff.y(amod(p4, 100.0));
        let left = real(real(p3 - unit * constant(PAREN_LEFT[k])) * P3_UNIT);
        glyph::library(self.doc, self.item, self.canvas, PARENTHESIS_SYMBOL, Pos::new(left, y), (size, size), rest.staff.step);
        let right_units = if ip(item, 6) == 1 { real(constant(PAREN_RIGHT[k]) + constant(1.9)) } else { constant(PAREN_RIGHT[k]) };
        let right = real(real(unit * right_units + p3) * P3_UNIT);
        glyph::library(self.doc, self.item, self.canvas, PARENTHESIS_SYMBOL, Pos::new(right, y), (-size, size), rest.staff.step);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::display::ItemId;
    use score_format::{Item, MusFile, Word};

    /// A size-1 staff 1 with barlines at P3 = 60 and 120, and `rest`.
    fn file(rest: &[f32]) -> MusFile {
        let trailer = [0.0_f32, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = (trailer.len() as u16).to_le_bytes().to_vec();
        bytes.extend(trailer.iter().flat_map(|w| w.to_le_bytes()));
        let mut file = MusFile::parse(&bytes).expect("an empty file parses");
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        file.items =
            vec![words(&[8.0, 1.0, 0.0, 0.0, 1.0]), words(&[14.0, 1.0, 60.0]), words(&[14.0, 1.0, 120.0]), words(rest)];
        file
    }

    fn rest<'a>(doc: &Document<'a>) -> ItemRef<'a> {
        doc.item(ItemId(3)).expect("the rest")
    }

    /// Engine results editor-core recorded for WB4 and EU9 on leaving edit mode.
    #[test]
    fn edit_mode_writes_back_bar_end_and_spacing() {
        let bar_rest = file(&[2.0, 1.0, 80.0, 0.0, -5.0, 0.0, 1.0, 4.0, -1.0]);
        let doc = Document::new(&bar_rest);
        assert_eq!(edit_p9(&doc, rest(&doc)), Some(116.5));
        assert_eq!(centre(&doc, rest(&doc)), None);
        let composite = file(&[2.0, 1.0, 80.0, 0.0, -19.0, 1.0, 4.0, 0.0, -1.0]);
        let doc = Document::new(&composite);
        assert_eq!(edit_spacing(&doc, rest(&doc)), Some(1.854_172_6));
        assert_eq!(edit_p9(&doc, rest(&doc)), centre(&doc, rest(&doc)));
    }

    #[test]
    fn only_some_composites_get_a_spacing() {
        let spaced = |p5: f32| {
            let f = file(&[2.0, 1.0, 80.0, 0.0, p5, 0.0, 1.0, 0.0, -1.0]);
            let doc = Document::new(&f);
            edit_spacing(&doc, rest(&doc)).is_some()
        };
        let with: Vec<i32> = (11..=19).filter(|&n| spaced(-(n as f32))).collect();
        assert_eq!(with, vec![13, 15, 16, 17, 18, 19]);
        assert!(!spaced(-2.0));
    }
}
