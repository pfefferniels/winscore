//! The library symbols draw_symbol 0x4293F0 writes as text on the screen
//! (8va, cresc., G.P., …: [`library::symbol_text`]). Unlike the outline
//! symbols they are drawn by draw_text from the engine's current-item
//! globals (X_POS, Y_POS, P3, P6, P7, P9, P26), not from draw_symbol's
//! position arguments; [`TextSymbolCall`] carries those values.

use crate::canvas::Canvas;
use crate::codes;
use crate::codes::text::font_before;
use crate::document::{Document, ItemRef};
use crate::page;
use crate::symbols::library::symbol_text;
use crate::text::{self, draw_text, Font, TextCall};
use crate::units::{amod, real, Pos};

/// What the text path of draw_symbol reads: its size arguments and the
/// current-item globals. [`TextSymbolCall::of`] gives an item's own values.
#[derive(Debug, Clone, Copy, PartialEq)]
pub struct TextSymbolCall {
    pub number: i32,
    /// draw_symbol's size arguments (P6, P7 style).
    pub size_x: f64,
    pub size_y: f64,
    /// X_POS, Y_POS.
    pub origin: Pos,
    /// P1 and P2 (CUR_STAFF).
    pub item_code: i32,
    pub staff: i32,
    pub p3: f32,
    pub p6: f32,
    pub p7: f32,
    pub p9: f32,
    pub p11: f32,
    pub p12: f32,
    pub p14: f32,
    pub p16: f32,
    pub p26: f32,
}

impl TextSymbolCall {
    /// Symbol `number` for `item` with the item's own parameters, as code 9
    /// draws it.
    pub fn of(doc: &Document<'_>, item: ItemRef<'_>, number: i32) -> Self {
        let p = |n: usize| item.p(n);
        Self {
            number,
            size_x: f64::from(p(6)),
            size_y: f64::from(p(7)),
            origin: doc.position(item),
            item_code: item.code(),
            staff: item.staff(),
            p3: p(3),
            p6: p(6),
            p7: p(7),
            p9: p(9),
            p11: p(11),
            p12: p(12),
            p14: p(14),
            p16: p(16),
            p26: p(26),
        }
    }
}

/// The first three text symbols (pizz., arco, a tempo) are upright, the
/// rest italic (font codes for draw_text).
const UPRIGHT_FONT: i32 = 1000;
const ITALIC_FONT: i32 = 1002;
const UPRIGHT_SYMBOLS: [i32; 3] = [66, 67, 78];
/// Symbols from 50 on are spread and sized from draw_symbol's arguments;
/// the ottava marks below take P6, P7 and a wider space.
const FIRST_SPREAD_SYMBOL: i32 = 50;
const SPREAD: f32 = 1.05;
const OTTAVA_SPACE: f32 = 0.6;
/// G.P. sits on rests and is placed from P16 and P12 (0x429F5C).
const GENERAL_PAUSE: i32 = 276;
const GP_FONT_BASE: i32 = 1000;
const GP_REST_LEVEL: f32 = 12.0;
const GP_INDENT: f32 = 3.15;
const SIZE_FLAGS: f64 = 100.0;

/// draw_symbol's text path (0x429E8B–0x42A16A) for a symbol in the text table.
pub fn draw_text_symbol(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, call: &TextSymbolCall) {
    if let Some(text_call) = text_symbol_call(doc, call, font_before(doc, item)) {
        draw_text(doc, item, canvas, &text_call);
    }
}

/// The font a text symbol leaves loaded (see [`text::font_loaded`]).
pub fn text_symbol_font_loaded(doc: &Document<'_>, call: &TextSymbolCall) -> Option<Font> {
    text::font_loaded(doc, &text_symbol_call(doc, call, Font::TIMES)?)
}

/// The draw_text call of the text path, given the font current before it;
/// `None` for symbols outside the text table.
pub fn text_symbol_call(doc: &Document<'_>, call: &TextSymbolCall, current_font: Font) -> Option<TextCall<'static>> {
    let text = symbol_text(call.number)?;
    let size_x = match real(amod(call.size_x, SIZE_FLAGS)) {
        0.0 => 1.0,
        s => s,
    };
    let size_y = if call.size_y == 0.0 { size_x } else { call.size_y };
    let font = if UPRIGHT_SYMBOLS.contains(&call.number) { UPRIGHT_FONT } else { ITALIC_FONT };
    let spread_size = |s: f64| real(s * f64::from(SPREAD)) as f32;
    let base = TextCall {
        text: text.as_bytes(),
        origin: call.origin,
        p3: call.p3,
        item_code: call.item_code,
        staff: call.staff,
        spread: SPREAD,
        width: spread_size(size_x),
        height: spread_size(size_y),
        font_override: font,
        rotation: call.p9,
        colour: (call.p26 != 0.0).then_some(call.p26),
        current_font,
        ..TextCall::default()
    };
    Some(match call.number {
        n if n < FIRST_SPREAD_SYMBOL => {
            TextCall { spread: 0.0, width: call.p6, height: call.p7, space: OTTAVA_SPACE, ..base }
        }
        GENERAL_PAUSE => general_pause(doc, call, base),
        _ => base,
    })
}

/// G.P.: font 1000 + IP14, x from P16 and P3 (P9 when positive on a rest)
/// less 3.15 × the size (STEP/25 × P12), on a rest 12 steps above P11 and
/// unrotated.
fn general_pause<'t>(doc: &Document<'_>, call: &TextSymbolCall, base: TextCall<'t>) -> TextCall<'t> {
    let staff = doc.staves.get(call.staff);
    let rest = call.item_code == codes::REST;
    let (p3, rotation, y) = if rest {
        let p3 = if call.p9 > 0.0 { call.p9 } else { call.p3 };
        let level = (f64::from(call.p11) + f64::from(GP_REST_LEVEL)) * 7.0 * staff.step;
        (p3, 0.0, real(f64::from(staff.level0) + level))
    } else {
        (call.p3, call.p9, call.origin.y)
    };
    let unit = real(staff.step / 25.0);
    let unit = if call.p12 != 0.0 { real(f64::from(call.p12) * unit) } else { unit };
    let indent = real(unit * f64::from(GP_INDENT));
    let x = real(((f64::from(call.p16) + f64::from(p3)) - indent) * page::P3_UNIT);
    TextCall {
        origin: Pos::new(x, y),
        font_override: GP_FONT_BASE + call.p14 as i32,
        spread: 0.0,
        rotation,
        ..base
    }
}
