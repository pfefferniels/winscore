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
//! meter font its digits are library symbols 2000–2009. Those digits are
//! set as the engine's screen sets them on every medium, and the numbers of
//! a meter are centred on one another ([`Layout::centred`]).

use crate::canvas::{Canvas, Stream};
use crate::codes;
use crate::codes::number::{draw_number, number_text, number_text_call, NumberCall};
use crate::display::Colour;
use crate::document::{Document, ItemRef};
use crate::symbols::{draw_clef, draw_library_symbol, ItemContext, SymbolCall};
use crate::text::{draw_text, font_loaded as text_font_loaded, Font};
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
    let layout = Layout::of(doc, item).centred(doc, item);
    layout.parts.iter().for_each(|part| match *part {
        Part::Number { value, at, .. } => draw_number(doc, item, canvas, at, &number_call(item, value, layout.size)),
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
        Part::Number { value, at, .. } => Some((value, at)),
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
    Number { value: i32, at: Pos, column: Column },
    /// The plus between two meters, as placed before draw_clef.
    Plus(Pos),
}

/// The numbers a number lines up with ([`Layout::centred`]).
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Column {
    /// The top and bottom number of the first (0) or the second meter (1).
    Meter(usize),
    /// The bottom number both meters share, as in 4+3/4.
    Shared,
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
    /// P4 after the small lift for the outline digits or a text font (REAL*4).
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

    /// The numbers of meter `meter` (0 or 1) at `x`; `centre` moves
    /// one-digit numbers right, `bottom_x` places a shared bottom number.
    fn numbers(&self, meter: usize, fraction: Fraction, x: f64, centre: bool, bottom_x: Option<f64>) -> Vec<Part> {
        let x_for = |n: i32| if centre && n < 10 { self.centred(x) } else { x };
        let top = Part::Number {
            value: fraction.top,
            at: Pos::new(x_for(fraction.top), self.top_y),
            column: Column::Meter(meter),
        };
        let bottom = (fraction.bottom >= 1).then(|| Part::Number {
            value: fraction.bottom,
            at: Pos::new(bottom_x.unwrap_or_else(|| x_for(fraction.bottom)), self.bottom_y),
            column: if bottom_x.is_some() { Column::Shared } else { Column::Meter(meter) },
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
        // The outline digits drawn here keep the setting the engine's screen
        // gives them on every medium. Text fonts take the one the engine
        // uses in print and for an explicit font, a little higher and
        // smaller, made for the meter font of SCORE's PostScript output.
        let (p4, factor, top_level) = if outline_digits(item) {
            (real(f64::from(item.p(4)) - c(0.23)), c(1.35), c(5.46))
        } else {
            (real(f64::from(item.p(4)) + c(0.1)), c(1.2), c(5.82))
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
        let mut parts = frame.numbers(0, first, x, second_bottom >= 0 && first.wide(), shared_bottom);
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
            parts.extend(frame.numbers(1, second, x2, second.bottom >= 0 && second.wide(), None));
        }
        Self { size, parts }
    }

    /// Lines the numbers of a meter up by their middles, as drawn (the
    /// engine starts them at one x, or moves a one-digit number a fixed
    /// step beside a two-digit one, so that in 3/4 the 3 sits 40 units left
    /// of the 4): the widest number of each meter stays where it is and the
    /// others move to its middle; a bottom number both meters share goes
    /// under the middle of both tops. Only the outline digits are measured,
    /// and only unrotated.
    fn centred(self, doc: &Document<'_>, item: ItemRef<'_>) -> Self {
        if !outline_digits(item) || item.p(19) != 0.0 {
            return self;
        }
        let mut numbers: Vec<Drawn> = self
            .parts
            .iter()
            .enumerate()
            .filter_map(|(part, p)| match *p {
                Part::Number { value, at, column } => {
                    let (left, right) = number_extent(doc, item, value, at, self.size)?;
                    Some(Drawn { part, column, left, right, shift: 0.0 })
                }
                Part::Plus(_) => None,
            })
            .collect();
        for meter in [Column::Meter(0), Column::Meter(1)] {
            let widest = numbers.iter().filter(|n| n.column == meter).max_by(|a, b| a.width().total_cmp(&b.width()));
            if let Some(centre) = widest.map(Drawn::middle) {
                numbers.iter_mut().filter(|n| n.column == meter).for_each(|n| n.move_to(centre));
            }
        }
        let tops = numbers.iter().filter(|n| n.column != Column::Shared);
        let left = tops.clone().map(|n| n.left).reduce(f64::min);
        let right = tops.map(|n| n.right).reduce(f64::max);
        if let (Some(left), Some(right)) = (left, right) {
            numbers.iter_mut().filter(|n| n.column == Column::Shared).for_each(|n| n.move_to((left + right) / 2.0));
        }
        let mut parts = self.parts;
        numbers.iter().for_each(|n| {
            if let Part::Number { at, .. } = &mut parts[n.part] {
                at.x = real(at.x + n.shift);
            }
        });
        Self { parts, ..self }
    }
}

/// A number of a meter and where it draws, for [`Layout::centred`].
struct Drawn {
    part: usize,
    column: Column,
    left: f64,
    right: f64,
    /// How far it has been moved.
    shift: f64,
}

impl Drawn {
    fn width(&self) -> f64 {
        self.right - self.left
    }

    fn middle(&self) -> f64 {
        (self.left + self.right) / 2.0
    }

    fn move_to(&mut self, middle: f64) {
        let dx = middle - self.middle();
        (self.left, self.right, self.shift) = (self.left + dx, self.right + dx, self.shift + dx);
    }
}

/// Whether the numbers are drawn in the meter font, as the outline digits
/// 2000–2009, rather than as text: for P13 = 0 and a P13 that selects font 94.
fn outline_digits(item: ItemRef<'_>) -> bool {
    let font = number_text_call(&number_call(item, 0, 1.0), Pos::default(), b"", Font::TIMES).font_override;
    font == Font::METER.0 || (font >= 1000 && font % 1000 == Font::METER.0)
}

/// The left and right end of what the number `value` of the meter draws
/// at `at`, in page units.
fn number_extent(doc: &Document<'_>, item: ItemRef<'_>, value: i32, at: Pos, size: f64) -> Option<(f64, f64)> {
    let mut stream = Stream::default();
    {
        let mut canvas = Canvas::new(&mut stream, item.id, item.staff(), Colour::BLACK);
        let call = number_call(item, value, size);
        let text = number_text(call.value, call.p5, call.p17, call.p18);
        // The meter font's digits do not depend on the current font.
        draw_text(doc, item, &mut canvas, &number_text_call(&call, at, &text, Font::TIMES));
        canvas.flush();
    }
    let xs = stream.list.shapes.iter().flat_map(|s| s.paths.iter().flatten()).map(|p| f64::from(p.x));
    xs.fold(None, |extent, x| Some(extent.map_or((x, x), |(left, right): (f64, f64)| (left.min(x), right.max(x)))))
}

#[cfg(test)]
mod tests {
    use crate::display::{DisplayList, ItemId, Point};
    use crate::document::{Document, Medium, Options};
    use score_format::{Item, MusFile, Word};

    /// The middle line of staff 1 on the page.
    const MIDDLE: i32 = 3648;

    fn render(meter: &[f32], medium: Medium) -> DisplayList {
        let words = |params: &[f32]| Item::new(params.iter().map(|&p| Word::from_f32(p)).collect());
        let mut file = MusFile::empty();
        file.items = vec![words(&[8.0, 1.0, 0.0, 0.0, 1.0]), words(meter)];
        crate::render(&Document::with_options(&file, Options { medium, ..Options::default() }))
    }

    /// The middles of the numbers above and below the middle line.
    fn middles(list: &DisplayList) -> (f64, f64) {
        let points = |above: bool| -> Vec<Point> {
            let shapes = list.shapes.iter().filter(|s| s.source == Some(ItemId(1)));
            let in_half = move |s: &&crate::display::Shape| {
                let ys: Vec<i32> = s.paths.iter().flatten().map(|p| p.y).collect();
                ((ys.iter().min().unwrap() + ys.iter().max().unwrap()) / 2 > MIDDLE) == above
            };
            shapes.filter(in_half).flat_map(|s| s.paths.iter().flatten().copied()).collect()
        };
        let middle = |points: Vec<Point>| {
            let (left, right) = (points.iter().map(|p| p.x).min().unwrap(), points.iter().map(|p| p.x).max().unwrap());
            f64::from(left + right) / 2.0
        };
        (middle(points(true)), middle(points(false)))
    }

    #[test]
    fn the_numbers_are_centred() {
        for meter in [[3.0, 4.0], [12.0, 8.0], [5.0, 16.0], [2.0, 2.0]] {
            let (top, bottom) = middles(&render(&[18.0, 1.0, 20.0, 0.0, meter[0], meter[1]], Medium::Screen));
            assert!((top - bottom).abs() <= 1.0, "{meter:?}: {top} {bottom}");
        }
    }

    #[test]
    fn meters_are_set_alike_on_every_medium() {
        let three_four = [18.0, 1.0, 20.0, 0.0, 3.0, 4.0];
        assert_eq!(render(&three_four, Medium::Screen).shapes, render(&three_four, Medium::Print).shapes);
        // A text font as well, in the setting made for SCORE's PostScript meter font.
        let times = [18.0, 1.0, 20.0, 0.0, 3.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0];
        let texts = |medium: Medium| {
            let list = render(&times, medium);
            list.texts.into_iter().filter(|t| t.source == Some(ItemId(1))).collect::<Vec<_>>()
        };
        assert_eq!(texts(Medium::Screen).len(), 2);
        assert_eq!(texts(Medium::Screen), texts(Medium::Print));
    }
}

