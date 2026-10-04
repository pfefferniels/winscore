//! Item colour from P26 (WinScore help, "Color Control").
//!
//! P26 = 0 is black, 0 < P26 < 1 a grey level (0 black, 1 white), and larger
//! values a six-digit `aabbcc` of red, green and blue percentages. The engine
//! treats a grey g as the colour with all three percentages 100·g and turns a
//! percentage p into a channel as `p · 2.56` truncated (so 99 gives 253, not
//! 255). Rules fitted to oracle output for greys 0.1–0.99 and colours such as
//! 123456, 669975, 990099.

use crate::display::Colour;
use crate::document::Medium;

/// White is shown in light grey on the screen so that it can still be found.
const SCREEN_WHITE: Colour = Colour { r: 235, g: 235, b: 235 };

/// Invisible staves and barlines are shown in grey 0.8 on the screen.
pub const SCREEN_INVISIBLE: Colour = Colour { r: 204, g: 204, b: 204 };

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
}
