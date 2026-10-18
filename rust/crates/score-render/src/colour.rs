//! Item colour from P26 (WinScore help, "Color Control").
//!
//! P26 = 0 is black, 0 < P26 < 1 a grey level (0 black, 1 white), and larger
//! values a six-digit `aabbcc` of red, green and blue percentages. The engine
//! treats a grey g as the colour with all three percentages 100·g and turns a
//! percentage p into a channel as `p · 2.56` truncated (so 99 gives 253, not
//! 255). Rules fitted to oracle output for greys 0.1–0.99 and colours such as
//! 123456, 669975, 990099.
//!
//! SCORE's PostScript output sets the colour of an item differently
//! (0x4D4F89, called by draw_items 0x547FC8 when printing): `P26 setgray`
//! for 0 < P26 ≤ 1, and for larger P26 `r g b setrgbcolor` with each
//! percentage over 100, from 0.989 on 1 (0x4F0D31), so that 99 is 100 % as
//! the help says. The refined style takes these colours ([`printed`]).

use crate::display::Colour;
use crate::document::{Medium, Options, Style};
use crate::units::trunc;

/// White is shown in light grey on the screen so that it can still be found.
const SCREEN_WHITE: Colour = Colour { r: 235, g: 235, b: 235 };

/// Invisible staves and barlines are shown in grey 0.8 on the screen.
pub const SCREEN_INVISIBLE: Colour = Colour { r: 204, g: 204, b: 204 };

/// The colour P26 asks for with `options`: [`from_p26`] in the engine
/// style, [`printed`] in the refined one.
pub fn of(p26: f32, options: Options) -> Colour {
    match options.style {
        Style::Engine => from_p26(p26, options.medium),
        Style::Refined => printed(p26, options.medium),
    }
}

/// The engine's screen colour for P26 on `medium`.
pub fn from_p26(p26: f32, medium: Medium) -> Colour {
    match p26 {
        0.0 => Colour::BLACK,
        1.0 if medium == Medium::Screen => SCREEN_WHITE,
        1.0 => Colour { r: 255, g: 255, b: 255 },
        grey if grey < 1.0 => from_aabbcc(f64::from(grey * 100.0 * 10101.0)),
        aabbcc => from_aabbcc(f64::from(aabbcc)),
    }
}

/// Splits `aabbcc` into percentages the way FORTRAN's MOD and INT do.
fn from_aabbcc(value: f64) -> Colour {
    let red = (value / 10000.0).trunc();
    let green = ((value % 10000.0) / 100.0).trunc();
    let blue = (value % 100.0).trunc();
    Colour { r: channel(red), g: channel(green), b: channel(blue) }
}

/// The factor is a REAL*4 constant, the product kept at x87 double precision:
/// 75 % gives 191.99999…, truncated to 191.
fn channel(percent: f64) -> u8 {
    ((percent * f64::from(2.56_f32)) as i32).min(255) as u8
}

/// The colour SCORE prints for P26 (0x4D4F89): true greys, and colour
/// percentages with 99 read as 100. White stays light grey on the screen.
pub fn printed(p26: f32, medium: Medium) -> Colour {
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
        // 0, and negative values, for which draw_items sets no colour.
        _ => Colour::BLACK,
    }
}

/// 0x4F0D31: a percentage over 100 from this value on is 1 (REAL*4 0.989).
const FULL: f32 = 0.989;
const PERCENT: f32 = 100.0;

/// A PostScript colour level from 0 to 1 as an 8-bit channel.
fn level(value: f64) -> u8 {
    (value.clamp(0.0, 1.0) * 255.0).round() as u8
}

#[cfg(test)]
mod tests {
    use super::*;

    fn rgb(p26: f32) -> (u8, u8, u8) {
        let c = from_p26(p26, Medium::Screen);
        (c.r, c.g, c.b)
    }

    #[test]
    fn greys_match_the_engine() {
        let cases = [
            (0.1, 25),
            (0.25, 63),
            (0.3, 76),
            (0.5, 127),
            (0.7, 179),
            (0.9, 230),
            (0.92, 235),
            (0.95, 243),
            (0.99, 253),
        ];
        cases.iter().for_each(|&(p26, v)| assert_eq!(rgb(p26), (v, v, v), "P26 = {p26}"));
    }

    #[test]
    fn colours_match_the_engine() {
        assert_eq!(rgb(123456.0), (30, 87, 143));
        assert_eq!(rgb(669975.0), (168, 253, 191));
        assert_eq!(rgb(990000.0), (253, 0, 0));
        assert_eq!(rgb(1000000.0), (255, 0, 0));
        assert_eq!(rgb(2.0), (0, 0, 5));
        assert_eq!(rgb(1.5), (0, 0, 2));
    }

    #[test]
    fn odd_greys_follow_the_same_arithmetic() {
        assert_eq!(rgb(0.999), (255, 230, 227));
        assert_eq!(rgb(0.001), (0, 25, 25));
        assert_eq!(rgb(-0.5), (129, 129, 129));
    }

    #[test]
    fn white_is_light_grey_on_screen() {
        assert_eq!(rgb(1.0), (235, 235, 235));
        assert_eq!(from_p26(1.0, Medium::Print), Colour { r: 255, g: 255, b: 255 });
    }

    fn printed_rgb(p26: f32, medium: Medium) -> (u8, u8, u8) {
        let c = printed(p26, medium);
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

    #[test]
    fn the_style_picks_the_rule() {
        let refined = Options { medium: Medium::Print, ..Options::REFINED };
        assert_eq!(of(0.333, Options::ENGINE), from_p26(0.333, Medium::Screen));
        assert_eq!(of(0.333, refined), Colour { r: 85, g: 85, b: 85 });
    }
}
