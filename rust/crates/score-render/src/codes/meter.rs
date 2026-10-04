//! Code 18: meters (draw_meter 0x4BFA59).
//!
//! P5/P6 top and bottom number, P7 size, P8/P9 a second meter joined by a
//! plus (P9 = 0 shares the first meter's bottom number, as in 4+3/4; P10
//! moves the plus and the second meter, P11 the second meter alone, P12
//! suppresses the plus), P13 font (0: the meter font 94), P15 offset,
//! P19 rotation, P20 spread. P5 from 91 on draws library symbol 117 − P5
//! (99 common time, 98 alla breve) at 0.75 × P7.
//!
//! Every number goes through draw_number 0x4F65A8 and draw_text; in the
//! meter font its digits are library symbols 2000–2009.

use crate::canvas::Canvas;
use crate::codes;
use crate::codes::number::{draw_number, number_text, number_text_call, NumberCall};
use crate::document::{Document, ItemRef};
use crate::symbols::{draw_clef, draw_library_symbol, ItemContext, SymbolCall};
use crate::text::{font_loaded as text_font_loaded, Font};
use crate::units::{real, trunc, Pos};

/// P5 from this value on selects a symbol instead of a number.
const FIRST_SYMBOL_P5: i32 = 91;
const SYMBOL_BASE: i32 = 117;
const SYMBOL_SIZE: f32 = 0.75;
/// The plus between two meters is clef symbol 38 (0x764BE8).
const PLUS_SYMBOL: i32 = 38;
/// draw_meter's IP7 without P13: the meter font.
const METER_FONT_P13: i32 = 6;

pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>) {
    let p5 = trunc(f64::from(item.p(5)));
    if p5 >= FIRST_SYMBOL_P5 {
        draw_meter_symbol(doc, item, canvas, p5);
        return;
    }
    let layout = Layout::of(doc, item);
    layout.parts.iter().for_each(|part| match *part {
        Part::Number { value, at } => draw_number(doc, item, canvas, at, &number_call(item, value, layout.size)),
        Part::Plus(at) => {
            let context = ItemContext { code: codes::CLEF, ..ItemContext::of(item) };
            draw_clef(doc, &context, canvas, at, doc.staff_of(item).step, PLUS_SYMBOL, (layout.size, layout.size));
        }
    });
}

/// The font a numeric meter leaves loaded: none in the meter font.
pub fn font_loaded(doc: &Document<'_>, item: ItemRef<'_>) -> Option<Font> {
    let p5 = trunc(f64::from(item.p(5)));
    if p5 >= FIRST_SYMBOL_P5 {
        return None;
    }
    let layout = Layout::of(doc, item);
    let (value, at) = layout.parts.iter().find_map(|part| match *part {
        Part::Number { value, at } => Some((value, at)),
        Part::Plus(_) => None,
    })?;
    let call = number_call(item, value, layout.size);
    let text = number_text(call.value, call.p5, call.p17, call.p18);
    text_font_loaded(doc, &number_text_call(&call, at, &text, Font::TIMES))
}

/// What draw_meter hands draw_number for one number (0x4BFC4C): P5 = the
/// number, P6 = the size, IP8 = 0, IP7 from P13.
fn number_call(item: ItemRef<'_>, value: i32, size: f64) -> NumberCall {
    let font = match trunc(f64::from(item.p(13))) {
        0 => METER_FONT_P13,
        p13 => p13,
    };
    NumberCall { value, p5: value as f32, size: size as f32, font, frame: 0, ..NumberCall::of(item) }
}

fn draw_meter_symbol(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, p5: i32) {
    let size = real(p7(item) * f64::from(SYMBOL_SIZE));
    let call = SymbolCall::sized(SYMBOL_BASE - p5, size, size);
    let context = ItemContext { code: codes::CLEF, ..ItemContext::of(item) };
    draw_library_symbol(doc, &context, canvas, doc.position(item), doc.staff_of(item).step, &call);
}

/// P7, 0 read as 1.
fn p7(item: ItemRef<'_>) -> f64 {
    match item.p(7) {
        0.0 => 1.0,
        p7 => f64::from(p7),
    }
}

#[derive(Debug, Clone, Copy, PartialEq)]
enum Part {
    /// One number of a meter, at draw_number's X_POS, Y_POS.
    Number { value: i32, at: Pos },
    /// The plus between two meters, as placed before draw_clef.
    Plus(Pos),
}

/// The numbers and the plus of a numeric meter, in drawing order, and the
/// size they are drawn at.
#[derive(Debug, Clone, PartialEq)]
struct Layout {
    size: f64,
    parts: Vec<Part>,
}

/// REAL*4 constants of draw_meter.
fn c(value: f32) -> f64 {
    f64::from(value)
}

/// One meter. A bottom number below 1 is not drawn; -1 marks the second
/// meter of `4+3/4`, whose bottom number the first meter draws.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Fraction {
    top: i32,
    bottom: i32,
}

impl Fraction {
    fn wide(self) -> bool {
        self.top > 9 || self.bottom > 9
    }
}

/// The vertical and size settings every number of the meter shares.
struct Frame<'d> {
    staff: crate::staff::Staff,
    item: ItemRef<'d>,
    /// P4 after the small lift for screen or print (REAL*4).
    p4: f64,
    size: f64,
    top_y: f64,
    bottom_y: f64,
}

impl Frame<'_> {
    fn level_y(&self, level: f64) -> f64 {
        self.staff.y(real(level * self.size + self.p4))
    }

    /// x of a one-digit number beside a two-digit one: further right.
    fn centred(&self, x: f64) -> f64 {
        real(self.staff.step * c(7.6) * self.size + x)
    }

    /// The numbers of one meter at `x`; `centre` moves one-digit numbers
    /// right, `bottom_x` overrides the bottom number's x.
    fn numbers(&self, fraction: Fraction, x: f64, centre: bool, bottom_x: Option<f64>) -> Vec<Part> {
        let x_for = |n: i32| if centre && n < 10 { self.centred(x) } else { x };
        let top = Part::Number { value: fraction.top, at: Pos::new(x_for(fraction.top), self.top_y) };
        let bottom = (fraction.bottom >= 1).then(|| Part::Number {
            value: fraction.bottom,
            at: Pos::new(bottom_x.unwrap_or_else(|| x_for(fraction.bottom)), self.bottom_y),
        });
        std::iter::once(top).chain(bottom).collect()
    }

    /// x of a bottom number shared by both meters (0x4BFD3B).
    fn shared_bottom_x(&self, x: f64, bottom: i32, first_top: i32) -> f64 {
        let offset = if bottom > 9 { c(2.4) } else { c(3.8) };
        let offset = if first_top > 9 { real(offset + c(3.4)) } else { offset };
        real((f64::from(self.item.p(10)) + offset) * c(4.8) * self.staff.step * self.size + x)
    }
}

impl Layout {
    fn of(doc: &Document<'_>, item: ItemRef<'_>) -> Self {
        let ip = |n: usize| trunc(f64::from(item.p(n)));
        let staff = doc.staff_of(item);
        let x = doc.position(item).x;
        // Print and an explicit font set the numbers a little higher and smaller.
        let set_as_print = !doc.screen() || ip(13) != 0;
        let (p4, factor, top_level) = if set_as_print {
            (real(f64::from(item.p(4)) + c(0.1)), c(1.2), c(5.82))
        } else {
            (real(f64::from(item.p(4)) - c(0.23)), c(1.35), c(5.46))
        };
        let size = real(p7(item) * factor);
        let (first, top_level) = match (ip(5), ip(6)) {
            (0, single) => (Fraction { top: single, bottom: 0 }, c(4.08)),
            (top, bottom) => (Fraction { top, bottom }, top_level),
        };
        let second = (ip(8) != 0).then(|| Fraction { top: ip(8), bottom: if ip(9) == 0 { -1 } else { ip(9) } });
        // Without a second meter draw_meter still tests P9 here.
        let second_bottom = second.map_or(ip(9), |s| s.bottom);
        let mut frame = Frame { staff, item, p4, size, top_y: 0.0, bottom_y: 0.0 };
        frame.top_y = frame.level_y(top_level);
        frame.bottom_y = frame.level_y(c(2.48));

        let shared_bottom = (second_bottom < 0 && second.is_some())
            .then(|| frame.shared_bottom_x(x, first.bottom, ip(5)));
        let mut parts = frame.numbers(first, x, second_bottom >= 0 && first.wide(), shared_bottom);
        if let Some(second) = second {
            let unit = real(staff.step * 6.0 * p7(item));
            let suppressed = ip(12) != 0;
            let plus_x = if suppressed {
                x
            } else {
                let wide = ip(5) > 9 || (ip(6) > 9 && second_bottom > 0);
                let offset = if wide { c(6.6) } else { c(3.5) };
                real((f64::from(item.p(10)) + offset) * unit + x)
            };
            if !suppressed {
                let level = if second.bottom < 1 { c(6.6) } else { c(4.72) };
                parts.push(Part::Plus(Pos::new(plus_x, frame.level_y(level))));
            }
            let x2 = real(real((f64::from(item.p(11)) + c(4.2)) * unit) + plus_x);
            parts.extend(frame.numbers(second, x2, second.bottom >= 0 && second.wide(), None));
        }
        Self { size, parts }
    }
}

