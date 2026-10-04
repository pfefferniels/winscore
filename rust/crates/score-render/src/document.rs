//! A read-only view of a `.mus` file prepared for rendering.
//!
//! Items stay parametric: SCORE's model is the parameter list P1…Pn, and
//! modules read parameters by number. The document adds what every module
//! needs besides its own item: the page, the staff table and the options.

use score_format::{Item, MusFile, Word};

use crate::colour;
use crate::display::{Colour, ItemId};
use crate::page::{self, Page, P3_UNIT};
use crate::staff::{Staff, StaffTable};
use crate::symbols::SymbolLibrary;
use crate::units::{real, trunc, Pos};

/// Where the picture is going: the screen shows editing aids, print does not.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
pub enum Medium {
    #[default]
    Screen,
    Print,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Options {
    pub medium: Medium,
    /// Staff numbers at the left edge (screen only; WinScore's NMO toggles them).
    pub staff_numbers: bool,
}

impl Default for Options {
    fn default() -> Self {
        Self { medium: Medium::Screen, staff_numbers: true }
    }
}

/// Codes whose P15 moves them right (draw_item jump tables 0x769010, 0x768FD0).
const P15_SHIFTED_CODES: [i32; 8] = [3, 7, 9, 10, 12, 14, 17, 18];

/// Codes whose P4 keeps other information in its hundreds (item_position 0x5479AB).
const P4_MOD_100_CODES: [i32; 4] = [1, 2, 3, 6];

/// One item and its index in the file.
#[derive(Debug, Clone, Copy)]
pub struct ItemRef<'a> {
    pub id: ItemId,
    pub item: &'a Item,
}

impl ItemRef<'_> {
    /// P1.
    pub fn code(&self) -> i32 {
        self.item.code()
    }

    /// Parameter `n` (1-based) as stored; parameters not stored are zero.
    pub fn p(&self, n: usize) -> f32 {
        self.item.param(n)
    }

    /// P2, the staff the item hangs on.
    pub fn staff(&self) -> i32 {
        self.p(2) as i32
    }

    /// The colour P26 asks for on `medium`.
    pub fn colour(&self, medium: Medium) -> Colour {
        colour::from_p26(self.p(26), medium)
    }

    /// A copy of the item with parameters `(n, value)` replaced, for a
    /// routine that overwrites the engine's parameter globals before calling
    /// a shared routine. Borrow it with [`ItemRef::changed`].
    pub fn with_params(&self, changes: &[(usize, f32)]) -> Item {
        let len = changes.iter().map(|&(n, _)| n).max().unwrap_or(0).max(self.item.params().len());
        let mut params: Vec<Word> = self.item.params().to_vec();
        params.resize(len, Word::from_f32(0.0));
        changes.iter().filter(|&&(n, _)| n >= 1).for_each(|&(n, value)| params[n - 1] = Word::from_f32(value));
        let mut text = self.item.text().to_vec();
        text.resize(text.len().div_ceil(4) * 4, b' ');
        Item::with_text(params, text)
    }

    /// The same item id with other parameters (see [`ItemRef::with_params`]).
    pub fn changed<'b>(&self, item: &'b Item) -> ItemRef<'b> {
        ItemRef { id: self.id, item }
    }
}

#[derive(Debug, Clone)]
pub struct Document<'a> {
    items: &'a [Item],
    symbols: &'a SymbolLibrary,
    pub page: Page,
    pub staves: StaffTable,
    pub options: Options,
}

impl<'a> Document<'a> {
    pub fn new(file: &'a MusFile) -> Self {
        Self::with_options(file, Options::default())
    }

    pub fn with_options(file: &'a MusFile, options: Options) -> Self {
        let items = file.items.as_slice();
        let metric = file.trailer.measurement() == Some(1.0);
        let staves = StaffTable::from_items(refs(items), metric);
        Self { items, symbols: SymbolLibrary::bundled(), page: Page::default(), staves, options }
    }

    /// The same document drawn with other symbol libraries.
    pub fn with_symbols(self, symbols: &'a SymbolLibrary) -> Self {
        Self { symbols, ..self }
    }

    /// The symbol library (by default WinScore's bundled `LBnnnn.DRW` files).
    pub fn symbols(&self) -> &'a SymbolLibrary {
        self.symbols
    }

    pub fn items(&self) -> impl Iterator<Item = ItemRef<'a>> + '_ {
        refs(self.items)
    }

    pub fn item(&self, id: ItemId) -> Option<ItemRef<'a>> {
        self.items.get(id.0 as usize).map(|item| ItemRef { id, item })
    }

    /// The table entry of the staff an item hangs on.
    pub fn staff_of(&self, item: ItemRef<'_>) -> Staff {
        self.staves.get(item.staff())
    }

    pub fn screen(&self) -> bool {
        self.options.medium == Medium::Screen
    }

    /// The item's reference point from P3, P4 (and P15), in internal
    /// coordinates, as item_position 0x5479AB computes it for every code.
    pub fn position(&self, item: ItemRef<'_>) -> Pos {
        let code = item.code();
        let x = page::x(item.p(3));
        let x = match item.p(15) {
            p15 if p15 != 0.0 && P15_SHIFTED_CODES.contains(&code) => real(x + P3_UNIT * f64::from(p15)),
            _ => x,
        };
        let p4 = f64::from(item.p(4));
        let p4 = if P4_MOD_100_CODES.contains(&code) { p4 - f64::from(trunc(p4 / 100.0) * 100) } else { p4 };
        Pos::new(x, self.staff_of(item).y(p4))
    }
}

fn refs(items: &[Item]) -> impl Iterator<Item = ItemRef<'_>> {
    items.iter().enumerate().map(|(i, item)| ItemRef { id: ItemId(i as u32), item })
}
