//! A mutable copy of one item's parameters, the unit every edit command works on.

use score_format::{Item, Word};

/// P1 of text items, whose characters follow the parameters.
pub const TEXT_CODE: i32 = 16;

/// The engine keeps at least P1–P3 when it drops trailing zero parameters.
const MIN_STORED: usize = 3;
const TEXT_WORDS: usize = 13;
const TEXT_COLOUR_WORDS: usize = 16;
const TEXT_COLOUR_FLAG: usize = 14;

/// Highest parameter number an edit may set; the engine ignores `46 v` and above.
pub const MAX_PARAM: usize = 45;

/// The parameters P1…Pn of an item as floats, plus the characters of a text item.
#[derive(Debug, Clone, PartialEq, Default)]
pub struct Draft {
    params: Vec<f32>,
    text: Vec<u8>,
}

impl Draft {
    pub fn new(params: &[f32]) -> Self {
        Self { params: params.to_vec(), text: Vec::new() }
    }

    pub fn of(item: &Item) -> Self {
        Self { params: item.params().iter().map(|w| w.as_f32()).collect(), text: item.text().to_vec() }
    }

    /// P1.
    pub fn code(&self) -> i32 {
        self.get(1) as i32
    }

    /// Parameter `n` (1-based); parameters not stored are zero.
    pub fn get(&self, n: usize) -> f32 {
        n.checked_sub(1).and_then(|i| self.params.get(i)).copied().unwrap_or(0.0)
    }

    /// Sets parameter `n` (1-based, at most [`MAX_PARAM`]); missing parameters below it become zero.
    pub fn set(&mut self, n: usize, value: f32) {
        debug_assert!((1..=MAX_PARAM).contains(&n), "parameter P{n} out of range");
        if self.params.len() < n {
            self.params.resize(n, 0.0);
        }
        self.params[n - 1] = value;
    }

    pub fn add(&mut self, n: usize, delta: f32) {
        self.set(n, self.get(n) + delta);
    }

    /// Number of stored parameters, trailing zeros included.
    pub fn len(&self) -> usize {
        self.params.len()
    }

    pub fn is_empty(&self) -> bool {
        self.params.is_empty()
    }

    /// Zeroes parameters `from..=to`.
    pub fn zero(&mut self, from: usize, to: usize) {
        let end = to.min(self.params.len());
        if from <= end {
            self.params[from - 1..end].fill(0.0);
        }
    }

    /// The characters of a text item.
    pub fn text(&self) -> &[u8] {
        &self.text
    }

    pub fn set_text(&mut self, text: &[u8]) {
        self.text = text.to_vec();
    }

    /// Parameters that must be stored whatever their value: P1–P3, and for
    /// text items every word before the characters, which the engine reads
    /// from word 14 (word 17 when P14 = -1 adds a colour).
    fn min_stored(&self) -> usize {
        match self.code() {
            TEXT_CODE if self.get(TEXT_COLOUR_FLAG) == -1.0 => TEXT_COLOUR_WORDS,
            TEXT_CODE => TEXT_WORDS,
            _ => MIN_STORED,
        }
    }

    /// The item the engine would store: trailing zeros dropped, but never
    /// below the words that must be stored.
    pub fn to_item(&self) -> Item {
        let kept = self.params.iter().rposition(|&p| p != 0.0).map_or(0, |i| i + 1).max(self.min_stored());
        let mut params: Vec<Word> = self.params.iter().map(|&p| Word::from_f32(zero_signless(p))).collect();
        params.resize(kept, Word::from_f32(0.0));
        if self.code() == TEXT_CODE {
            Item::with_text(params, padded(&self.text))
        } else {
            Item::new(params)
        }
    }

    /// Whether `item` already holds these parameters, so storing the draft would change nothing.
    pub fn describes(&self, item: &Item) -> bool {
        Draft::of(item).normalized() == self.normalized()
    }

    fn normalized(&self) -> Draft {
        Draft::of(&self.to_item())
    }
}

/// -0.0 stored as 0.0, so negating an unset parameter leaves it unset.
fn zero_signless(value: f32) -> f32 {
    if value == 0.0 {
        0.0
    } else {
        value
    }
}

/// Text items store their characters blank-padded to whole words.
fn padded(text: &[u8]) -> Vec<u8> {
    let mut bytes = text.to_vec();
    bytes.resize(text.len().div_ceil(4) * 4, b' ');
    bytes
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn unset_parameters_read_as_zero() {
        let draft = Draft::new(&[1.0, 1.0, 100.0]);
        assert_eq!(draft.get(9), 0.0);
        assert_eq!(draft.code(), 1);
    }

    #[test]
    fn storing_drops_trailing_zeros_down_to_p3() {
        let mut draft = Draft::new(&[8.0, 1.0]);
        assert_eq!(draft.to_item().params().len(), 3);
        draft.set(9, 0.0);
        assert_eq!(draft.to_item().params().len(), 3);
        draft.set(7, 2.0);
        assert_eq!(draft.to_item().params().len(), 7);
    }

    #[test]
    fn negative_zero_is_stored_as_zero() {
        let mut draft = Draft::new(&[1.0, 1.0, 100.0, 6.0, 10.0]);
        draft.set(4, -0.0);
        assert_eq!(draft.to_item().params()[3].bits(), 0);
    }

    #[test]
    fn zero_clears_a_range_within_the_stored_parameters() {
        let mut draft = Draft::new(&[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.0]);
        draft.zero(5, 20);
        assert_eq!(draft.to_item().params().len(), 4);
    }

    #[test]
    fn text_survives_a_parameter_change() {
        let mut params = vec![Word::from_f32(0.0); 12];
        params[0] = Word::from_f32(16.0);
        params[11] = Word::from_f32(5.0);
        let item = Item::with_text(params, b"Hello   ".to_vec());
        let mut draft = Draft::of(&item);
        draft.set(4, 3.0);
        let stored = draft.to_item();
        assert_eq!(stored.text(), b"Hello");
        assert_eq!(stored.param(4), 3.0);
    }

    #[test]
    fn describes_ignores_trailing_zeros() {
        let item = Item::new([8.0, 1.0].map(Word::from_f32).to_vec());
        assert!(Draft::new(&[8.0, 1.0, 0.0, 0.0]).describes(&item));
        assert!(!Draft::new(&[8.0, 2.0]).describes(&item));
    }
}
