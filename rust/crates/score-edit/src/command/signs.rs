//! Edit-mode transformations of pedals (code 7), symbols (code 9), boxes
//! (code 12), key signatures (code 17) and meters (code 18), after the
//! WinScore help.

use crate::params::Draft;

/// What SZ+ adds to a symbol's size: one ulp above f32 0.1, as measured
/// (0.25 becomes 0.350000024); SZ- takes off 0.1 itself.
pub const SYMBOL_GROWTH: f32 = 0.100_000_024;

/// Code 7's P7 for the graphic piano pedal PEDA.
const GRAPHIC_PEDAL: f32 = 20.0;

/// PDSZ+, PDSZ-: size (unset = 1) in P9 for the graphic pedal, in P5 for other code 7 items.
pub fn resize_pedal(draft: &mut Draft, delta: f32) {
    let n = if draft.get(7) == GRAPHIC_PEDAL { 9 } else { 5 };
    let size = draft.get(n);
    draft.set(n, if size == 0.0 { 1.0 } else { size } + delta);
}

/// FLI on a symbol: its vertical size (P7, or P6 while P7 is unset) changes sign.
pub fn flip_symbol(draft: &mut Draft) {
    let height = [draft.get(7), draft.get(6), 1.0].into_iter().find(|&v| v != 0.0).unwrap_or(1.0);
    draft.set(7, -height);
}

/// SZ+, SZ- on a symbol: P6 (unset = 1) by `delta`, a set P7 in proportion.
pub fn resize_symbol(draft: &mut Draft, delta: f32) {
    let width = draft.get(6);
    let resized = if width == 0.0 { 1.0 } else { width } + delta;
    let height = draft.get(7);
    if height != 0.0 && width != 0.0 {
        draft.set(7, height * resized / width);
    }
    draft.set(6, resized);
}

/// BXHP, BXHM: box width in P6; an unset height (P7) keeps the old width.
pub fn resize_box_width(draft: &mut Draft, delta: f32) {
    let width = draft.get(6);
    if draft.get(7) == 0.0 {
        draft.set(7, width);
    }
    draft.set(6, width + delta);
}

/// BXVP, BXVM: box height in P7, unset meaning the width (P6).
pub fn resize_box_height(draft: &mut Draft, delta: f32) {
    let height = draft.get(7);
    draft.set(7, if height == 0.0 { draft.get(6) } else { height } + delta);
}

/// KSFL: one more flat, from sharps straight to one flat.
pub fn add_flat(draft: &mut Draft) {
    let count = draft.get(5);
    draft.set(5, if count > 0.0 { -1.0 } else { count - 1.0 });
}

/// KSSH: one more sharp, from flats straight to one sharp.
pub fn add_sharp(draft: &mut Draft) {
    let count = draft.get(5);
    draft.set(5, if count < 0.0 { 1.0 } else { count + 1.0 });
}

/// KSNA: naturals on/off, 100 more or less in P5 away from zero.
pub fn toggle_naturals(draft: &mut Draft) {
    let count = draft.get(5);
    let naturals = count.abs() >= 100.0;
    let magnitude = if naturals { count.abs() - 100.0 } else { count.abs() + 100.0 };
    draft.set(5, magnitude.copysign(count));
}

/// MBLM, MBLP: the bottom number halved (not below 1) or doubled.
pub fn scale_denominator(draft: &mut Draft, factor: f32) {
    draft.set(6, (draft.get(6) * factor).max(1.0));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn symbols_flip_and_resize_like_the_engine() {
        let mut sym = Draft::new(&[9.0, 1.0, 100.0, 13.0, 22.0, 0.25]);
        flip_symbol(&mut sym);
        assert_eq!(sym.get(7), -0.25);
        flip_symbol(&mut sym);
        assert_eq!(sym.get(7), 0.25);
        let mut tall = Draft::new(&[9.0, 1.0, 100.0, 13.0, 22.0, 0.25, 1.0]);
        resize_symbol(&mut tall, SYMBOL_GROWTH);
        assert_eq!((tall.get(6), tall.get(7)), (0.350_000_02, 1.400_000_1));
    }

    #[test]
    fn key_signature_accidentals() {
        let mut key = Draft::new(&[17.0, 1.0, 100.0, 0.0, 2.0]);
        add_flat(&mut key);
        assert_eq!(key.get(5), -1.0);
        add_sharp(&mut key);
        assert_eq!(key.get(5), 1.0);
        toggle_naturals(&mut key);
        assert_eq!(key.get(5), 101.0);
        let mut flats = Draft::new(&[17.0, 1.0, 100.0, 0.0, -3.0]);
        toggle_naturals(&mut flats);
        assert_eq!(flats.get(5), -103.0);
    }
}
