//! The engine's text routine, draw_text 0x569AF0: code-16 items, and the
//! strings that draw_number 0x4F65A8 formats for numbers, meters and staff
//! numbers.
//!
//! A string is read into glyphs, font changes and tab stops ([`scan`]), each
//! glyph advancing by its width from the font metric files. The x of a glyph
//! is NINT of a running REAL*4 x in internal units; every glyph of a string
//! shares NINT(Y_POS), and the text record stores it 100 units lower. Each
//! font change starts a text record (0x56CAF0). Glyphs from 80 up, and every
//! glyph of the meter font 94, are library symbols (0x56B529).
//!
//! The engine keeps the current font in a global across items and drawing
//! passes; [`TextCall::current_font`] carries it in.
//!
//! The refined style keeps every advance and position the engine computes
//! but draws what SCORE prints: the characters behind the screen's stand-ins
//! and behind bytes from 128 up, outline fonts as outlines in the text's
//! colour, symbols and every glyph turned with a rotated line, and tab stops
//! on the recto page.

mod fonts;
mod glyphs;
mod scan;

pub use fonts::{weight_and_italic, Font, FontLibrary};

use crate::canvas::{Canvas, TextString, TextStyle};
use crate::colour;
use crate::display::{Colour, Point};
use crate::document::{Document, ItemRef, Options, Style};
use crate::geometry::rotate_points;
use crate::page::RECTO_SHIFT;
use crate::symbols::{draw_library_symbol, ItemContext, SymbolCall};
use crate::units::{amod, nint, real, trunc, Pos};
use glyphs::SPACE;
use scan::{scan, Code, Entry, ScanSettings};

/// What draw_text reads from the item parameters and globals the caller
/// sets up. Sizes and angles are REAL*4 values as stored. End struct
/// literals with `..TextCall::default()` so that fields added later keep
/// their neutral values.
#[derive(Debug, Clone, PartialEq, Default)]
pub struct TextCall<'t> {
    pub text: &'t [u8],
    /// X_POS, Y_POS.
    pub origin: Pos,
    /// P3; below -140 nothing is drawn.
    pub p3: f32,
    /// P1 of the item being drawn: 16 for text items. Code-10 numbers draw
    /// the glyphs from 80 up as characters.
    pub item_code: i32,
    /// The engine's STEP if the caller changed it (rests, fingering);
    /// `None` is the step unit of the item's staff.
    pub step: Option<f64>,
    /// P2: above 200 the string moves to the recto page.
    pub staff: i32,
    /// P5, the spread factor (0 = 1).
    pub spread: f32,
    /// P6, the size (hundreds are part-extraction flags, 0 = 1).
    pub width: f32,
    /// P7, the vertical size (0 = P6).
    pub height: f32,
    /// IP8: 1000 + n draws everything in font n, 94 in the meter font.
    pub font_override: i32,
    /// P9, degrees clockwise.
    pub rotation: f32,
    /// P10, extra width of a space in units of the size.
    pub space: f32,
    /// P11, a shift in P3 units.
    pub shift: f32,
    /// P16 when P14 = -1: a colour as in P26.
    pub colour: Option<f32>,
    /// The engine's current font (0x78B6A0) before the call.
    pub current_font: Font,
}

/// draw_text 0x569AF0: the string's text records and symbol glyphs.
pub fn draw_text(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, call: &TextCall<'_>) {
    if call.p3 < HIDDEN_P3 {
        return;
    }
    let text = Text::new(doc, call);
    let mut placed = text.place();
    if text.rotated() {
        text.rotate(&mut placed);
    }
    text.emit(doc, item, canvas, &placed);
}

/// The width the engine leaves in P13 after drawing `call` (0x42FA58): the
/// string's length in P3 units, times the spread factor.
pub fn width(doc: &Document<'_>, call: &TextCall<'_>) -> f32 {
    Text::new(doc, call).length
}

/// What right-justification (JR, 0x471190) subtracts from P13 for the last
/// glyph, in P3 units: the PostScript width less the second width of the
/// metric file, over 638, times 3.2833 and the size (fonts from 90 on: a
/// tenth of the symbol width). `None` if the string has no glyph or ends in
/// font 99, which JR leaves alone.
pub fn right_bearing(doc: &Document<'_>, call: &TextCall<'_>) -> Option<f32> {
    let text = Text::new(doc, call);
    let placed = text.place();
    let last = placed.iter().rposition(|p| matches!(p.code, Code::Glyph(_)))?;
    let Code::Glyph(glyph) = placed[last].code else { return None };
    let font = placed[..last]
        .iter()
        .rev()
        .find_map(|p| match p.code {
            Code::Font(font) => Some(font.number()),
            _ => None,
        })
        .unwrap_or(text.scan_font.number());
    let index = glyph + 1;
    let units = match font {
        LEFT_ALONE_FONT => return None,
        f if f < SYMBOL_WIDTH_FONTS => {
            let metrics = text.fonts.metrics(f)?;
            let entry = usize::try_from(index - 1).ok()?;
            let printed = f64::from(metrics.width(entry)?) / f64::from(METRIC_UNITS);
            let second = f64::from(*metrics.screen_widths.get(entry)?) / f64::from(METRIC_UNITS);
            real(f64::from(printed as f32) - second)
        }
        _ => {
            let index = if matches!(index, 0x88 | 0x96) { glyph - 0x37 } else { index };
            real(f64::from(glyphs::symbol_width(index)) * f64::from(0.1_f32))
        }
    };
    let size = real(text.step * f64::from(text.width) / 25.0);
    Some(real(units * f64::from(ADVANCE_SCALE) * size) as f32)
}

/// Font 99 (PostScript commands) is not right-justified.
const LEFT_ALONE_FONT: i32 = 99;
/// Fonts from this number on take their widths from the symbol table.
const SYMBOL_WIDTH_FONTS: i32 = 90;
const METRIC_UNITS: f32 = 638.0;
const ADVANCE_SCALE: f32 = 3.2833;

/// The font whose metrics the string leaves loaded (0x791444), if it loads
/// one other than the font current before it. draw_item makes the loaded
/// font the current font of every item (0x547358), so this is what an item
/// drawing `call` hands on to the next. Only text record headers load a
/// font for good (0x56CAF0); the meter font 94 has none.
pub fn font_loaded(doc: &Document<'_>, call: &TextCall<'_>) -> Option<Font> {
    let probe = TextCall { current_font: NO_FONT, ..call.clone() };
    let text = Text::new(doc, &probe);
    text.place().iter().rev().find_map(|p| match p.code {
        Code::Font(font) if font != Font::METER && font != NO_FONT => Some(font),
        _ => None,
    })
}

/// Stands for the font current before a string while probing it.
const NO_FONT: Font = Font(-1);

const HIDDEN_P3: f32 = -140.0;
/// Text items (code 16) drop repeated font changes.
const TEXT_ITEM: i32 = 16;
/// Code-10 numbers.
const NUMBER_ITEM: i32 = 10;
/// The text record's y lies this far below the string's NINT(Y_POS) (0x532EC0).
const RECORD_DROP: i32 = 100;
/// Text above this staff is drawn on the recto page.
const LAST_VERSO_TEXT_STAFF: i32 = 200;
/// Library symbols count recto from this staff on (emit_points 0x54A69C).
const LAST_VERSO_STAFF: i32 = 199;
/// Internal units per P3 unit (REAL*4 150.0).
const P3_UNIT: f64 = 150.0;
/// A tab of n tenths moves x to 15·n.
const TAB_TENTH: f64 = 15.0;
/// draw_text quarters P6 and P7 before drawing (0x56A4FA).
const QUARTER: f32 = 0.25;
/// Header sizes (0x56CAF0): height and width from STEP·P/4.
const HEADER_SCALE: f32 = 1.937;
const SCREEN_WIDTH_FACTOR: f32 = 0.825;
/// Glyph symbols are drawn at P6, P7 times this (0x56B529).
const SYMBOL_SCALE: f32 = 3.5714;
/// Outline fonts appear in green on the screen.
const OUTLINE_COLOUR: Colour = Colour { r: 0x18, g: 0xE4, b: 0x03 };

/// IP8 from 90 to 999 other than 94 is ignored.
fn effective_override(font: i32) -> i32 {
    if font != Font::METER.0 && (90..1000).contains(&font) {
        0
    } else {
        font
    }
}

/// Where a scanned entry is drawn, as the engine marks it in its x array.
#[derive(Debug, Clone, Copy, PartialEq, Eq)]
enum Mark {
    /// x = 0: font changes, spaces after tabs, zero-width glyphs.
    Hidden,
    /// x = -1: an accent, drawn with the next glyph.
    Accent,
    At(Point),
}

#[derive(Debug, Clone, Copy, PartialEq)]
struct Placed {
    code: Code,
    mark: Mark,
    /// The byte from 128 up the glyph was read from.
    byte: Option<u8>,
}

/// A string read and sized, ready to be placed.
struct Text<'c> {
    call: &'c TextCall<'c>,
    options: Options,
    entries: Vec<Entry>,
    /// The font after scanning, current until the first font change is drawn.
    scan_font: Font,
    /// P13 as the scan leaves it.
    length: f32,
    font_override: i32,
    fonts: &'static FontLibrary,
    /// STEP of the staff.
    step: f64,
    /// P6 after AMOD 100 (P48).
    width: f32,
    /// P6 and P7 as quartered for drawing.
    width_q: f32,
    height_q: f32,
    /// X_POS after the recto shift and P11.
    x: f32,
}

impl<'c> Text<'c> {
    fn new(doc: &Document<'_>, call: &'c TextCall<'c>) -> Self {
        let fonts = FontLibrary::bundled();
        let font_override = effective_override(call.font_override);
        let step = call.step.unwrap_or_else(|| doc.staves.get(call.staff).step);
        let spread = if call.spread == 0.0 { 1.0 } else { call.spread };
        let width = match real(amod(f64::from(call.width), 100.0)) as f32 {
            0.0 => 1.0,
            w => w,
        };
        let height = if call.height == 0.0 { width } else { call.height };
        let font = if font_override > 98 || font_override == Font::METER.0 {
            Font(font_override % 1000)
        } else {
            call.current_font
        };
        let settings = ScanSettings {
            fonts,
            font,
            font_override,
            size: real(step * f64::from(width) / 25.0) as f32,
            space: call.space,
            spread,
        };
        let scanned = scan(call.text, &settings);
        let mut entries = scanned.entries;
        if call.item_code == TEXT_ITEM {
            drop_repeated_fonts(&mut entries);
        }
        spread_advances(&mut entries, scanned.length, spread);
        Self {
            call,
            options: doc.options,
            entries,
            scan_font: scanned.font,
            length: scanned.length,
            font_override,
            fonts,
            step,
            width,
            width_q: real(f64::from(width) * f64::from(QUARTER)) as f32,
            height_q: real(f64::from(height) * f64::from(QUARTER)) as f32,
            x: start_x(call),
        }
    }

    fn rotated(&self) -> bool {
        self.call.rotation != 0.0
    }

    fn refined(&self) -> bool {
        self.options.style == Style::Refined
    }

    /// Positions (0x56A67E–0x56A9A9): NINT of the running x before each
    /// glyph's advance; tabs set x absolutely. The engine leaves the recto
    /// shift out of a tab's x, so that the text after it lands on the verso
    /// page; the refined style adds it.
    fn place(&self) -> Vec<Placed> {
        let y = nint(self.call.origin.y);
        let mut x = f64::from(self.x);
        let tab_shift = if self.refined() { recto_shift(self.call) } else { 0.0 };
        self.entries
            .iter()
            .map(|entry| {
                let placed = if entry.advance != 0.0 {
                    let at = Point::new(nint(x), y);
                    x = real(f64::from(entry.advance) * P3_UNIT + x);
                    Placed { code: entry.code, mark: Mark::At(at), byte: entry.byte }
                } else {
                    let code = match entry.code {
                        Code::Tab(tenths) => {
                            x = real(f64::from(tenths) * TAB_TENTH + tab_shift);
                            Code::Glyph(SPACE)
                        }
                        code => code,
                    };
                    let accent = matches!(code, Code::Glyph(g) if (83..127).contains(&g) && g != SPACE);
                    Placed { code, mark: if accent { Mark::Accent } else { Mark::Hidden }, byte: entry.byte }
                };
                self.overridden(placed)
            })
            .collect()
    }

    /// With a font override every hidden entry becomes the override.
    fn overridden(&self, placed: Placed) -> Placed {
        match (self.font_override, placed.mark) {
            (font, Mark::Hidden) if font > 89 => {
                let code = if font >= 1000 { Code::Font(Font(font % 1000)) } else { Code::Glyph(font) };
                Placed { code, ..placed }
            }
            _ => placed,
        }
    }

    /// The text rotation (0x56F920): positions turn clockwise about the
    /// start, then shift so that the glyphs turn about a point below it.
    fn rotate(&self, placed: &mut [Placed]) {
        let degrees = f64::from(self.call.rotation);
        let radians = real(degrees / f64::from(DEGREE));
        let (sin, cos) = (real(radians.sin()), real(radians.cos()));
        let (dx, dy) = self.record_shift();
        let centre = Point::new(nint(f64::from(self.x)), nint(self.call.origin.y));
        placed.iter_mut().filter(|p| self.turns(p)).for_each(|p| {
            if let Mark::At(at) = p.mark {
                let (ox, oy) = (real(f64::from(at.x - centre.x)), real(f64::from(at.y - centre.y)));
                let x = centre.x + nint(cos * ox + sin * oy);
                let y = centre.y + nint(cos * oy - sin * ox);
                p.mark = Mark::At(Point::new(trunc(f64::from(x) + dx), trunc(f64::from(y) - dy)));
            }
        });
    }

    /// What the rotation adds to x and takes from y after the turn: the
    /// shell turns a record's glyphs about the top of their cell, which lies
    /// 4.583·150 units of size above the baseline.
    fn record_shift(&self) -> (f64, f64) {
        let degrees = f64::from(self.call.rotation);
        let sin = real(real(degrees / f64::from(DEGREE)).sin());
        let size = self.step * f64::from(self.width) / 25.0;
        let dx = real(sin * f64::from(4.583_f32) * real(size * 150.0));
        let lower = real((f64::from(270.0_f32) - degrees) / f64::from(DEGREE));
        let drop = real(size * 175.0) * f64::from(3.95_f32);
        let dy = real(real(drop) * real(lower.sin()) + real(drop));
        (dx, dy)
    }

    /// The rotation leaves font changes, hidden entries and glyphs 80–126
    /// alone, so that the symbols 80–92 and the characters 95–126 stay on
    /// the unturned line; the refined style turns every glyph.
    fn turns(&self, placed: &Placed) -> bool {
        matches!((placed.code, placed.mark), (Code::Glyph(g), Mark::At(_)) if self.refined() || !(80..=126).contains(&g))
    }

    /// The emission loop (0x56AA8A–0x56ACCC).
    fn emit(&self, doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, placed: &[Placed]) {
        let mut font = self.scan_font;
        let mut runs: Vec<(TextStyle, Colour, Vec<TextString>)> = Vec::new();
        let mut entries = placed.iter();
        while let Some(entry) = entries.next() {
            match (entry.code, entry.mark) {
                (Code::Font(f), _) => {
                    font = f;
                    if f != Font::METER {
                        runs.push((self.style(f), self.run_colour(f), Vec::new()));
                    }
                }
                (Code::Glyph(accent), Mark::Accent) => {
                    if let Some(&Placed { code: Code::Glyph(base), mark: Mark::At(at), byte }) = entries.next() {
                        let base = self.refined_byte(byte, font).unwrap_or_else(|| glyphs::glyph_char(base));
                        let accented = if self.refined() {
                            glyphs::printed_accented(accent, base)
                        } else {
                            glyphs::accented(accent, base)
                        };
                        push_string(&mut runs, at, cp1252_text(accented));
                    }
                }
                (Code::Glyph(g), Mark::At(at)) if g != SPACE => {
                    if let Some(byte) = self.refined_byte(entry.byte, font) {
                        push_string(&mut runs, at, cp1252_text(byte));
                    } else if (95..=161).contains(&g) || g == 167 {
                        push_string(&mut runs, at, self.glyph_text(g, glyphs::extended_char(g)));
                    } else if self.is_symbol(g, font) {
                        self.draw_symbol(doc, item, canvas, g, font, at);
                    } else {
                        push_string(&mut runs, at, self.glyph_text(g, glyphs::glyph_char(g)));
                    }
                }
                _ => {}
            }
        }
        let item_colour = canvas.colour;
        runs.into_iter().for_each(|(style, colour, strings)| {
            canvas.colour = colour;
            canvas.text(&style, strings);
        });
        canvas.colour = self.call.colour.map_or(item_colour, |p16| colour::of(p16, doc.options));
    }

    /// What a record shows for glyph `code`, whose screen character is
    /// `screen`: the refined style puts the printed characters in place of
    /// the screen's stand-ins.
    fn glyph_text(&self, code: i32, screen: u8) -> String {
        match glyphs::printed_char(code).filter(|_| self.refined()) {
            Some(char) => char.to_string(),
            None => cp1252_text(screen),
        }
    }

    /// The byte from 128 up a glyph was read from, which the refined style
    /// draws as its cp1252 character in the glyph's place (the meter font
    /// has no characters). Bytes cp1252 leaves undefined show nothing.
    fn refined_byte(&self, byte: Option<u8>, font: Font) -> Option<u8> {
        let defined = |b: u8| if char_from_cp1252(b).is_control() { 0 } else { b };
        byte.filter(|_| self.refined() && font != Font::METER).map(defined)
    }

    fn is_symbol(&self, glyph: i32, font: Font) -> bool {
        let meter = font == Font::METER;
        font.0 < 100 && (glyph > 79 || meter) && (self.call.item_code != NUMBER_ITEM || meter)
    }

    /// A glyph drawn as a library symbol (0x56B529).
    fn draw_symbol(&self, doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, glyph: i32, font: Font, at: Point) {
        let scaled = |size: f32| real(f64::from(size) * f64::from(SYMBOL_SCALE));
        let (number, size_x, size_y) = match glyph {
            80..=92 => (glyph + 2080, scaled(self.width_q), scaled(self.height_q)),
            162.. => (glyph + 2012, scaled(self.width_q), scaled(self.height_q)),
            _ if font == Font::METER => (glyph + 2000, scaled(self.width_q), scaled(self.height_q)),
            _ => (glyph, f64::from(self.width_q), f64::from(self.height_q)),
        };
        let recto = if self.call.staff > LAST_VERSO_STAFF { RECTO_SHIFT } else { 0 };
        // 0x56B529 sets IP1 = 16; draw_text has cleared IP10.
        let context = ItemContext { code: TEXT_ITEM, pixels: 0, ..ItemContext::of(item) };
        let start = canvas.buffer_mut().len();
        if self.refined() && self.rotated() {
            // The refined style keeps the symbol on the turned line: where
            // the rotation put its position, less the shift meant for text
            // records, and turned about itself.
            let (dx, dy) = self.record_shift();
            let origin = Pos::new(f64::from(at.x - recto) - dx, f64::from(at.y) + dy);
            let call = SymbolCall { number, size_x, size_y, thickness: 0, rotation: 0.0 };
            draw_library_symbol(doc, &context, canvas, origin, self.step, &call);
            rotate_points(&mut canvas.buffer_mut()[start..], origin.to_point(), self.call.rotation);
            return;
        }
        let origin = Pos::new(f64::from(at.x - recto), self.call.origin.y);
        // rotate_points (0x42A5F4) turns the points of a code-16 item about
        // (P3·150, Y_POS) rather than about the symbol.
        let centre = (self.call.item_code == TEXT_ITEM)
            .then(|| Point::new(trunc(f64::from(self.call.p3) * P3_UNIT), trunc(self.call.origin.y)));
        let rotation = f64::from(self.call.rotation);
        let own_rotation = if centre.is_some() { 0.0 } else { rotation };
        let call = SymbolCall { number, size_x, size_y, thickness: 0, rotation: own_rotation };
        draw_library_symbol(doc, &context, canvas, origin, self.step, &call);
        if let Some(centre) = centre.filter(|_| trunc(rotation) != 0) {
            rotate_points(&mut canvas.buffer_mut()[start..], centre, self.call.rotation);
        }
    }

    /// The record header (0x56CAF0) for font `font`.
    fn style(&self, font: Font) -> TextStyle {
        let metrics = self.fonts.metrics(font.number());
        let (weight, italic) = metrics.map_or((400, false), |m| weight_and_italic(&m.postscript_name));
        let size = |q: f32| real(self.step * f64::from(q));
        let height = real(size(self.height_q) * f64::from(HEADER_SCALE));
        let width = real(real(size(self.width_q) * f64::from(SCREEN_WIDTH_FACTOR)) * f64::from(HEADER_SCALE));
        TextStyle {
            font: metrics.map(|m| m.family.clone()).unwrap_or_default(),
            height: 64.0 * height as f32,
            width: 32.0 * width as f32,
            escapement: trunc(f64::from(self.call.rotation) * 10.0),
            weight,
            italic,
            underline: false,
            outline: self.refined() && font.outline(),
        }
    }

    /// The record's colour; the refined style draws outline fonts in it
    /// as SCORE prints them (`false charpath lw stroke`), not in green.
    fn run_colour(&self, font: Font) -> Colour {
        if self.refined() {
            self.call.colour.map_or(Colour::BLACK, |p16| colour::printed(p16, self.options.medium))
        } else if font.outline() {
            OUTLINE_COLOUR
        } else {
            self.call.colour.map_or(Colour::BLACK, record_colour)
        }
    }
}

/// REAL*4 57.29578, degrees per radian in the text rotation.
const DEGREE: f32 = 57.29578;

fn push_string(runs: &mut [(TextStyle, Colour, Vec<TextString>)], at: Point, text: String) {
    if let Some((_, _, strings)) = runs.last_mut() {
        strings.push(TextString { at: Point::new(at.x, at.y - RECORD_DROP), text });
    }
}

/// A cp1252 character as the record's string; 0 is none.
fn cp1252_text(byte: u8) -> String {
    if byte == 0 {
        String::new()
    } else {
        char_from_cp1252(byte).to_string()
    }
}

/// The recto shift of text above staff 200, as [`start_x`] adds it.
fn recto_shift(call: &TextCall<'_>) -> f64 {
    if call.staff > LAST_VERSO_TEXT_STAFF {
        f64::from(RECTO_SHIFT)
    } else {
        0.0
    }
}

/// The text record's colour for P14 = -1 (0x56CAF0): P16 as in P26, with
/// white (1) shown as grey 0.92 on every medium. The refined style takes
/// [`colour::printed`] instead.
fn record_colour(p16: f32) -> Colour {
    let p16 = match p16 {
        1.0 => 0.92_f32,
        p => p,
    };
    let value = if p16 < 1.0 {
        let p = f64::from(p16);
        real(p * 1_000_000.0 + (p * 10_000.0 + p * 100.0))
    } else {
        f64::from(p16)
    };
    let n = trunc(value);
    let channel = |percent: i32| (f64::from(percent) * f64::from(2.56_f32)) as i32 as u8;
    Colour { r: channel(n / 10_000), g: channel(n % 10_000 / 100), b: channel(n % 100) }
}

/// X_POS for the string: recto pages above staff 200, then P11 (0x569AF0).
fn start_x(call: &TextCall<'_>) -> f32 {
    let x = call.origin.x;
    let x = if call.staff > LAST_VERSO_TEXT_STAFF { real(x + f64::from(RECTO_SHIFT)) } else { x };
    let x = if call.shift != 0.0 { real(f64::from(call.shift) * P3_UNIT + x) } else { x };
    x as f32
}

/// Text items drop a font change to the font already current (0x56A0FF).
fn drop_repeated_fonts(entries: &mut Vec<Entry>) {
    let mut current = None;
    entries.retain(|e| match e.code {
        Code::Font(font) if current == Some(font) => false,
        Code::Font(font) => {
            current = Some(font);
            true
        }
        _ => true,
    });
}

/// P5 ≠ 1 (0x56A2D3): every advance but the last changes by the same amount
/// so that the string's length L (P13, already times P5) becomes L(2 - 1/P5).
fn spread_advances(entries: &mut [Entry], length: f32, spread: f32) {
    if spread == 1.0 {
        return;
    }
    let advancing = entries.iter().filter(|e| e.advance != 0.0).count() as i32 - 1;
    if advancing < 1 {
        return;
    }
    let length = f64::from(length);
    let extra = real((length - length / f64::from(spread)) / f64::from(advancing));
    let last = entries.len().saturating_sub(1);
    entries[..last].iter_mut().filter(|e| e.advance != 0.0).for_each(|e| {
        let advance = real(extra + f64::from(e.advance));
        e.advance = if advance == 0.0 { 0.1 } else { advance as f32 };
    });
}

/// cp1252 to Unicode for the characters the engine emits.
fn char_from_cp1252(byte: u8) -> char {
    const HIGH: [char; 32] = [
        '€', '\u{81}', '‚', 'ƒ', '„', '…', '†', '‡', 'ˆ', '‰', 'Š', '‹', 'Œ', '\u{8d}', 'Ž', '\u{8f}', '\u{90}', '‘',
        '’', '“', '”', '•', '–', '—', '˜', '™', 'š', '›', 'œ', '\u{9d}', 'ž', 'Ÿ',
    ];
    match byte {
        0x80..=0x9F => HIGH[usize::from(byte - 0x80)],
        _ => char::from(byte),
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use crate::display::{DisplayList, ItemId};
    use crate::document::Medium;
    use crate::render;
    use score_format::{Item, MusFile, Word};

    /// A file without items: every staff is a size-1 staff.
    fn empty_file() -> MusFile {
        let trailer = [0.0_f32, 0.0, 6.0, 0.0, 5.0, -9999.0];
        let mut bytes = (trailer.len() as u16).to_le_bytes().to_vec();
        bytes.extend(trailer.iter().flat_map(|w| w.to_le_bytes()));
        MusFile::parse(&bytes).expect("an empty file parses")
    }

    /// JR offsets measured in the emulated engine by editor-core (Times, P3 units).
    #[test]
    fn right_bearings_match_the_engine() {
        let file = empty_file();
        let doc = Document::new(&file);
        let bearing = |text: &[u8], width: f32| {
            let call = TextCall { text, staff: 1, width, ..TextCall::default() };
            right_bearing(&doc, &call).expect("a glyph")
        };
        let close = |a: f32, b: f32| (a - b).abs() < 5e-5;
        assert!(close(bearing(b"_00Halo", 1.0), 0.15439));
        assert!(close(bearing(b"_00Hold", 1.0), 0.04631));
        assert!(close(bearing(b"_00HALA", 1.0), 0.08234));
        assert!(close(bearing(b"_00Halo", 2.0), 2.0 * 0.15439));
        assert_eq!(right_bearing(&doc, &TextCall { text: b"_00", staff: 1, ..TextCall::default() }), None);
    }

    #[test]
    fn record_colours_match_the_engine() {
        let rgb = |p16: f32| {
            let c = record_colour(p16);
            (c.r, c.g, c.b)
        };
        assert_eq!(rgb(0.5), (127, 127, 127));
        assert_eq!(rgb(990000.0), (253, 0, 0));
        assert_eq!(rgb(1.0), (235, 235, 235));
    }

    #[test]
    fn override_range() {
        assert_eq!([0, 4, 90, 94, 999, 1004].map(effective_override), [0, 4, 0, 94, 0, 1004]);
    }

    /// Staff 1 and a text item on `staff` at P3 = 50 with `text` and the
    /// parameters `changes` (P14 = -1 needs P16).
    fn text_file(staff: f32, text: &[u8], changes: &[(usize, f32)]) -> MusFile {
        let mut file = empty_file();
        let words = |params: &[f32]| params.iter().map(|&p| Word::from_f32(p)).collect::<Vec<_>>();
        let mut params = vec![16.0, staff, 50.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, text.len() as f32, 0.0];
        changes.iter().for_each(|&(n, v)| {
            params.resize(params.len().max(n), 0.0);
            params[n - 1] = v;
        });
        let mut padded = text.to_vec();
        padded.resize(text.len().div_ceil(4) * 4, b' ');
        file.items = vec![Item::new(words(&[8.0, 1.0, 0.0, 0.0, 1.0])), Item::with_text(words(&params), padded)];
        file
    }

    fn drawn(file: &MusFile, options: Options) -> DisplayList {
        let list = render(&Document::with_options(file, Options { staff_numbers: false, ..options }));
        let of_text = |source: Option<ItemId>| source == Some(ItemId(1));
        DisplayList {
            shapes: list.shapes.into_iter().filter(|s| of_text(s.source)).collect(),
            texts: list.texts.into_iter().filter(|t| of_text(t.source)).collect(),
        }
    }

    fn strings(list: &DisplayList) -> Vec<(String, Point)> {
        list.texts.iter().flat_map(|t| t.strings.iter().map(|s| (s.text.clone(), s.origin))).collect()
    }

    const PRINT: Options = Options { medium: Medium::Print, ..Options::REFINED };

    #[test]
    fn refined_bytes_from_128_up_draw_their_characters_in_place() {
        let file = text_file(1.0, b"_00\xe9t\xe7a \xfc", &[]);
        let (engine, refined) = (strings(&drawn(&file, Options::ENGINE)), strings(&drawn(&file, Options::REFINED)));
        let text = |s: &[(String, Point)]| s.iter().map(|(t, _)| t.as_str()).collect::<String>();
        assert_eq!((text(&engine), text(&refined)), ("0t0a0".to_string(), "étçaü".to_string()));
        assert!(engine.iter().zip(&refined).all(|(e, r)| e.1 == r.1));
    }

    #[test]
    fn refined_stand_ins_are_the_printed_characters() {
        let file = text_file(1.0, b"_00!5?L?o!0!n'", &[]);
        let text = |options| strings(&drawn(&file, options)).into_iter().map(|(t, _)| t).collect::<String>();
        assert_eq!((text(Options::ENGINE), text(Options::REFINED)), ("LLxXX'".to_string(), "£Łø•–’".to_string()));
    }

    #[test]
    fn refined_outline_fonts_are_outlines_in_the_text_colour() {
        let file = text_file(1.0, b"__05Outline", &[]);
        let run = |options| drawn(&file, options).texts.remove(0);
        let (engine, refined) = (run(Options::ENGINE), run(PRINT));
        assert_eq!((engine.outline, engine.colour), (false, OUTLINE_COLOUR));
        assert_eq!((refined.outline, refined.colour), (true, Colour::BLACK));
    }

    #[test]
    fn refined_white_text_prints_white() {
        let file = text_file(1.0, b"_00White", &[(14, -1.0), (16, 1.0)]);
        let colour = |options| drawn(&file, options).texts[0].colour;
        let (grey, white) = (Colour { r: 235, g: 235, b: 235 }, Colour { r: 255, g: 255, b: 255 });
        let engine_print = Options { medium: Medium::Print, ..Options::ENGINE };
        assert_eq!([colour(engine_print), colour(Options::REFINED), colour(PRINT)], [grey, grey, white]);
    }

    #[test]
    fn refined_tabs_stay_on_the_recto_page() {
        let file = text_file(201.0, b"_00A~60~B", &[]);
        let xs = |options| strings(&drawn(&file, options)).iter().map(|(_, at)| at.x).collect::<Vec<_>>();
        let (engine, refined) = (xs(Options::ENGINE), xs(Options::REFINED));
        assert_eq!(engine[0], refined[0]);
        assert_eq!(refined[1] - engine[1], RECTO_SHIFT);
        assert!(engine[1] < engine[0] && refined[1] > refined[0]);
    }

    /// Distance of `p` from the line through `a` and `b`.
    fn off_line(p: Point, a: Point, b: Point) -> f64 {
        let (dx, dy) = (f64::from(b.x - a.x), f64::from(b.y - a.y));
        (dx * f64::from(p.y - a.y) - dy * f64::from(p.x - a.x)).abs() / dx.hypot(dy)
    }

    #[test]
    fn refined_rotation_turns_every_character() {
        let file = text_file(1.0, b"_00AB!5CD", &[(9, 30.0)]);
        let on_line = |options| {
            let s = strings(&drawn(&file, options));
            off_line(s[2].1, s[0].1, s[4].1)
        };
        assert!(on_line(Options::ENGINE) > 300.0);
        assert!(on_line(Options::REFINED) < 2.0);
    }

    /// How far the symbols of `A[B]C` shifted by P11 = 5 and turned by 30°
    /// lie from the unturned ones turned about the text start, at most.
    fn symbols_off_the_turned_line(options: Options) -> f64 {
        let points = |degrees: f32| {
            let file = text_file(1.0, b"_00A[B]C", &[(9, degrees), (11, 5.0)]);
            let list = drawn(&file, options);
            list.shapes.iter().flat_map(|s| s.paths.iter().flatten().copied()).collect::<Vec<Point>>()
        };
        let (flat, turned) = (points(0.0), points(30.0));
        assert!(!flat.is_empty() && flat.len() == turned.len());
        // X_POS = 150·P3 plus 150·P11, on the page.
        let file = text_file(1.0, b"", &[]);
        let doc = Document::new(&file);
        let start = doc.position(doc.item(ItemId(1)).expect("the text")).to_point();
        let start = start.shifted(750 - crate::page::PAPER_ORIGIN.x, -crate::page::PAPER_ORIGIN.y);
        let (sin, cos) = 30_f64.to_radians().sin_cos();
        flat.iter()
            .zip(&turned)
            .map(|(p, q)| {
                let (dx, dy) = (f64::from(p.x - start.x), f64::from(p.y - start.y));
                let want = (f64::from(start.x) + cos * dx + sin * dy, f64::from(start.y) + cos * dy - sin * dx);
                (want.0 - f64::from(q.x)).hypot(want.1 - f64::from(q.y))
            })
            .fold(0.0, f64::max)
    }

    /// The engine turns the notes about (150·P3, Y_POS), the refined style
    /// about the text start as the characters.
    #[test]
    fn refined_rotation_turns_symbols_about_the_text_start() {
        assert!(symbols_off_the_turned_line(Options::ENGINE) > 350.0);
        assert!(symbols_off_the_turned_line(Options::REFINED) < 4.0);
    }
}
