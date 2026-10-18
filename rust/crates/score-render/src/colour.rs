//! Item colour from P26 (WinScore help, "Color Control").
//!
//! P26 = 0 is black, 0 < P26 < 1 a grey level (0 black, 1 white), and larger
//! values a six-digit `aabbcc` of red, green and blue percentages. Colours
//! are drawn as SCORE's PostScript output sets them when printing:
//! `P26 setgray` for 0 < P26 ≤ 1, and for larger P26 `r g b setrgbcolor`
//! with each percentage over 100, from 0.989 on 1, so that 99 is 100 % as
//! the help says. (The engine's screen takes a grey g as the percentages 100·g and a percentage
//! p as the channel p · 2.56 truncated, so that 99 gives 253.)

use crate::display::Colour;
use crate::document::Medium;
use crate::units::trunc;

/// White is shown in light grey on the screen so that it can still be found.
const SCREEN_WHITE: Colour = Colour { r: 235, g: 235, b: 235 };

/// Invisible staves and barlines are shown in grey 0.8 on the screen.
pub const SCREEN_INVISIBLE: Colour = Colour { r: 204, g: 204, b: 204 };

/// The colour SCORE prints for P26: true greys, and colour
/// percentages with 99 read as 100. White stays light grey on the screen.
pub fn of(p26: f32, medium: Medium) -> Colour {
    match p26 {
        1.0 if medium == Medium::Screen => SCREEN_WHITE,
        grey if grey > 0.0 && grey <= 1.0 => {
            let v = level(f64::from(grey));
            Colour { r: v, g: v, b: v }
        }
        aabbcc if aabbcc > 1.0 => {
            let n = trunc(f64::from(aabbcc));
            let part = |percent: i32| {
                let fraction = percent as f32 / PERCENT;
                level(if fraction >= FULL { 1.0 } else { f64::from(fraction) })
            };
            Colour { r: part(n / 10000), g: part(n % 10000 / 100), b: part(n % 100) }
        }
        // 0, and negative values, for which the engine sets no colour.
        _ => Colour::BLACK,
    }
}

/// A percentage over 100 from this value on is 1 (REAL*4 0.989).
const FULL: f32 = 0.989;
const PERCENT: f32 = 100.0;

/// A PostScript colour level from 0 to 1 as an 8-bit channel.
fn level(value: f64) -> u8 {
    (value.clamp(0.0, 1.0) * 255.0).round() as u8
}

#[cfg(test)]
mod tests {
    use super::*;

    fn printed_rgb(p26: f32, medium: Medium) -> (u8, u8, u8) {
        let c = of(p26, medium);
        (c.r, c.g, c.b)
    }

    #[test]
    fn printed_greys_are_grey() {
        let cases = [(0.333, 85), (0.5, 128), (0.75, 191), (0.999, 255), (0.001, 0)];
        cases.iter().for_each(|&(p26, v)| assert_eq!(printed_rgb(p26, Medium::Print), (v, v, v), "P26 = {p26}"));
        assert_eq!(printed_rgb(1.0, Medium::Print), (255, 255, 255));
        assert_eq!(printed_rgb(1.0, Medium::Screen), (235, 235, 235));
        assert_eq!(printed_rgb(-0.5, Medium::Screen), (0, 0, 0));
    }

    #[test]
    fn printed_colours_read_99_as_full() {
        assert_eq!(printed_rgb(669975.0, Medium::Screen), (168, 255, 191));
        assert_eq!(printed_rgb(990000.0, Medium::Print), (255, 0, 0));
        assert_eq!(printed_rgb(980000.0, Medium::Print), (250, 0, 0));
        assert_eq!(printed_rgb(123456.0, Medium::Print), (31, 87, 143));
        assert_eq!(printed_rgb(2.0, Medium::Print), (0, 0, 5));
    }
}
