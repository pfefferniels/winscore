//! The item list as the layout routines work on it: each item's parameters as f32, with
//! the index of the item it came from.

use score_format::{Item, Word};

use crate::num::trunc;

pub const NOTE: i32 = 1;
pub const REST: i32 = 2;
pub const CLEF: i32 = 3;
pub const BEAM: i32 = 6;
pub const STAFF: i32 = 8;
pub const BARLINE: i32 = 14;
pub const TEXT: i32 = 16;
pub const KEY: i32 = 17;
pub const METER: i32 = 18;

#[derive(Debug, Clone, PartialEq)]
pub struct Row {
    pub p: Vec<f32>,
    pub source: usize,
    /// Words of text after the parameters (text items).
    pub text_words: usize,
}

impl Row {
    pub fn of(item: &Item, source: usize) -> Self {
        Row { p: item.params().iter().map(|w| w.as_f32()).collect(), source, text_words: item.text().len().div_ceil(4) }
    }

    /// The words the item takes in the engine's item store, its length word included.
    pub fn store_words(&self) -> usize {
        self.p.len() + self.text_words + 1
    }

    pub fn len(&self) -> usize {
        self.p.len()
    }

    /// Parameter `k` (1-based); parameters not stored are zero.
    pub fn par(&self, k: usize) -> f32 {
        k.checked_sub(1).and_then(|i| self.p.get(i)).copied().unwrap_or(0.0)
    }

    /// Sets parameter `k`, storing the parameters before it as zeros if needed.
    pub fn set(&mut self, k: usize, value: f32) {
        if self.p.len() < k {
            self.p.resize(k, 0.0);
        }
        self.p[k - 1] = value;
    }

    pub fn code(&self) -> i32 {
        trunc(self.par(1))
    }

    pub fn staff(&self) -> i32 {
        trunc(self.par(2))
    }

    pub fn x(&self) -> f32 {
        self.par(3)
    }

    pub fn set_x(&mut self, x: f32) {
        self.set(3, x);
    }

    /// The item to store: the original when nothing changed, else the new parameters (a
    /// text item keeps its characters).
    pub fn to_item(&self, original: &Item) -> Item {
        let params: Vec<Word> = self.p.iter().copied().map(Word::from_f32).collect();
        if params == original.params() {
            original.clone()
        } else if original.code() == TEXT {
            Item::with_text(params, padded(original.text()))
        } else {
            Item::new(params)
        }
    }
}

fn padded(text: &[u8]) -> Vec<u8> {
    let mut bytes = text.to_vec();
    bytes.resize(text.len().div_ceil(4) * 4, b' ');
    bytes
}
