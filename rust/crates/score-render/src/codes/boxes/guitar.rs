//! Guitar chord grids, code 12 with P5 < 0 (draw_box_negative 0x49EAE0).
//!
//! P5 -1 grid with a nut, -2 without, -3 the chord name only, -4 a chord
//! from the dictionary `scorlib/GUITAR.DAT` (P7 root, P8 type, P9 variant;
//! -5 dictionary name only, -6 dictionary grid without name). P6 size,
//! P13 frets per string (8 open, 9 muted), P14 `SF` strings and frets,
//! P12 `ABFF` barre from string A to B and a fret number FF, P16 font and
//! name size, P17 string spacing (negative: no nut), P18 finger numbers per
//! string (9 thumb), P19 name height; P7 root (`LA`: letter C..B = 1..7,
//! accidental 1 flat, 2 sharp), P8 chord type, P9–P11 additions.

use std::sync::OnceLock;

use crate::canvas::{Canvas, Pen};
use crate::codes::text::font_before;
use crate::document::{Document, ItemRef};
use crate::staff::Staff;
use crate::symbols::{draw_library_symbol, ItemContext, SymbolCall};
use crate::text::{self, draw_text, TextCall};
use crate::units::{amod, real, trunc, Pos};

use super::{draw_styled_box, BoxCall};

/// The item's parameters as draw_box_negative reads them, after the
/// dictionary lookup.
#[derive(Debug, Clone, Copy, PartialEq)]
struct Chord {
    kind: i32,
    /// IP7 after the lookup: a root `LA`, or minus a dictionary row.
    root: i32,
    /// P7 as given, for the name of a dictionary chord.
    given_root: i32,
    chord_type: i32,
    p9: i32,
    p10: i32,
    p11: i32,
    /// IP12: barre and fret number.
    barre: i32,
    p13: f32,
    p18: f32,
}

const DICTIONARY_KINDS: i32 = -3;
const NAME_ONLY: i32 = -3;
const DICTIONARY_NAME_ONLY: i32 = -5;
const DICTIONARY_NO_NAME: i32 = -6;
const WITH_NUT: i32 = -1;
const WITHOUT_NUT: i32 = -2;

impl Chord {
    fn of(item: ItemRef<'_>) -> Self {
        let ip = |n: usize| trunc(f64::from(item.p(n)));
        let chord = Self {
            kind: ip(5),
            root: ip(7),
            given_root: ip(7),
            chord_type: ip(8),
            p9: ip(9),
            p10: ip(10),
            p11: ip(11),
            barre: ip(12),
            p13: item.p(13),
            p18: item.p(18),
        };
        if chord.kind < DICTIONARY_KINDS {
            chord.looked_up()
        } else {
            chord
        }
    }

    /// The dictionary lookup (0x4A07B1): root row from P7, type P8, variant
    /// P9; the grid takes the entry's frets, barre and fingers.
    fn looked_up(self) -> Self {
        if self.chord_type >= 21 || !(1..73).contains(&self.root) {
            return self;
        }
        let kind = if self.kind == DICTIONARY_NAME_ONLY { self.kind } else { WITH_NUT };
        let chord_type = self.chord_type.max(1);
        let variant = if self.kind == DICTIONARY_NAME_ONLY || !(0..=4).contains(&self.p9) { 0 } else { self.p9 };
        let row = dictionary_row(self.root);
        let Some(entry) = dictionary().entry(row, chord_type, variant as usize) else {
            return Self { kind, root: -row, chord_type, ..self };
        };
        let kind = if entry.barre % 100 != 0 && kind != DICTIONARY_NAME_ONLY { WITHOUT_NUT } else { kind };
        Self {
            kind,
            root: if self.kind == DICTIONARY_NO_NAME { 0 } else { -row },
            chord_type,
            barre: entry.barre,
            p13: entry.frets as f32,
            p18: if self.p18 == 0.0 { entry.fingers as f32 } else { self.p18 },
            ..self
        }
    }
}

/// The dictionary row (semitone 1 = C … 12 = B) of a root `LA`.
fn dictionary_row(root: i32) -> i32 {
    let accidental = match root % 10 {
        a @ 1..=2 => a * 2 - 3,
        _ => 0,
    };
    let letter = root * 2 / 10;
    let natural = if letter - 1 > 6 { letter - 2 } else { letter - 1 };
    match accidental + natural {
        r if r < 1 => 12,
        r if r > 12 => 1,
        r => r,
    }
}

/// One fingering of the dictionary: frets per string, barre, fingers.
#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
struct Fingering {
    frets: i32,
    barre: i32,
    fingers: i32,
}

/// GUITAR.DAT as the loader 0x430EC0 reads it: per row and type a name of
/// up to 20 characters and five fingerings.
#[derive(Debug, Clone, PartialEq, Default)]
struct Dictionary {
    names: Vec<((i32, i32), Vec<u8>)>,
    fingerings: Vec<((i32, i32), [Fingering; 5])>,
}

const NAME_LENGTH: usize = 20;
const LINE_LENGTH: usize = 160;

impl Dictionary {
    fn parse(data: &[u8]) -> Self {
        let mut dictionary = Self::default();
        for raw in data.split(|&b| b == b'\n') {
            let mut line: Vec<u8> = raw.iter().copied().filter(|&b| b != b'\r').take(LINE_LENGTH).collect();
            line.resize(LINE_LENGTH, b' ');
            if line[0] == b' ' {
                continue;
            }
            if dictionary.read_line(&mut line).is_none() {
                break;
            }
        }
        dictionary
    }

    /// One line; `None` stops the loader, as malformed lines do in the engine.
    fn read_line(&mut self, line: &mut [u8]) -> Option<()> {
        let last = line.iter().rposition(|&b| b == b';')?;
        line[last] = b' ';
        let name_end = line.iter().position(|&b| b == b';')?;
        let (start, end) = token(line, name_end + 1)?;
        if end - start > 1 {
            return None;
        }
        let chord_type = line[start..=end].iter().fold(0, |n, &b| n * 10 + i32::from(b) - 48);
        if chord_type > 20 {
            return None;
        }
        let at = if line[0] == b'_' { 3 } else { 0 };
        let letter = i32::from(line[at]);
        let natural = match letter - 66 {
            l if l < 1 => letter - 59,
            l => l,
        };
        let semitone = if natural < 4 { natural * 2 - 1 } else { natural * 2 - 2 };
        let semitone = match (line[at + 1], line[at + 2]) {
            (b'?', b'1') => semitone - 1,
            (b'?', b'2') => semitone + 1,
            _ => semitone,
        };
        let row = match semitone {
            r if r > 12 => 1,
            0 => 12,
            r => r,
        };
        let mut name = line[..name_end.min(NAME_LENGTH)].to_vec();
        name.resize(NAME_LENGTH, b' ');
        self.names.push(((row, chord_type), name));
        let mut fingerings = [Fingering::default(); 5];
        let mut count = 0;
        let mut field = 0;
        let mut position = end + 1;
        while position < last {
            let Some((start, end)) = token(line, position + 1) else { break };
            position = end;
            let value = line[start..=end].iter().rev().enumerate().fold(0i32, |sum, (k, &b)| {
                let digit = match b {
                    b'x' => 9,
                    b'o' => 8,
                    b => i32::from(b) - 48,
                };
                sum.wrapping_add(10i32.wrapping_pow(k as u32).wrapping_mul(digit))
            });
            match field {
                0 => {
                    if count == 5 {
                        return None;
                    }
                    fingerings[count].frets = value;
                    count += 1;
                    field = 1;
                }
                1 => {
                    fingerings[count - 1].barre = value;
                    field = 2;
                }
                _ => {
                    fingerings[count - 1].fingers = value;
                    field = 0;
                    if count == 5 {
                        break;
                    }
                }
            }
        }
        self.fingerings.push(((row, chord_type), fingerings));
        Some(())
    }

    fn entry(&self, row: i32, chord_type: i32, variant: usize) -> Option<Fingering> {
        let (_, fingerings) = self.fingerings.iter().rev().find(|(key, _)| *key == (row, chord_type))?;
        Some(fingerings[variant])
    }

    fn name(&self, row: i32, chord_type: i32) -> Option<&[u8]> {
        self.names.iter().rev().find(|(key, _)| *key == (row, chord_type)).map(|(_, name)| name.as_slice())
    }
}

/// FUN_00431806: the blank-separated token from `from` (0-based), as
/// first and last index; `None` if only blanks remain.
fn token(line: &[u8], from: usize) -> Option<(usize, usize)> {
    let start = (from..line.len()).find(|&i| line[i] != b' ')?;
    let end = (start..line.len()).find(|&i| line[i] == b' ').unwrap_or(line.len()) - 1;
    Some((start, end))
}

const GUITAR_DAT: &[u8] = include_bytes!(concat!(env!("CARGO_MANIFEST_DIR"), "/../../../WINSCORE 5.01/winscore/scorlib/GUITAR.DAT"));

fn dictionary() -> &'static Dictionary {
    static DICTIONARY: OnceLock<Dictionary> = OnceLock::new();
    DICTIONARY.get_or_init(|| Dictionary::parse(GUITAR_DAT))
}

/// A REAL*4 constant of the routine.
fn c(value: f32) -> f64 {
    f64::from(value)
}

/// The engine's text buffer starts with a font code; draw_text sees it.
const FONT_PREFIX: &[u8] = b"_00";
/// Library symbol of the barre slur (LB0200 slot 9).
const BARRE_SYMBOL: i32 = 209;
/// The muted-string cross: two mirrored filled outlines (tables 0x791748, 0x791734).
const CROSS_X: [f32; 5] = [-55.0, 45.0, 55.0, -45.0, -55.0];
const CROSS_Y: [f32; 5] = [34.0, 135.0, 135.0, 34.0, 34.0];
const FRET: i32 = 160;

/// The grid's geometry in internal units (REAL*4 values).
struct Grid {
    staff: Staff,
    step: f64,
    /// Units per 1/160 of a fret: STEP × P6 × 0.075.
    unit: f64,
    string_gap: f64,
    /// Left string and bottom fret line.
    x0: f64,
    y0: f64,
    /// Gaps between strings (strings − 1) and frets.
    gaps: i32,
    frets: i32,
    /// Top of the grid, raised by the nut.
    top: f64,
    last_x: f64,
    /// Fret lines just below the top: for the barre.
    second: f64,
    third: f64,
    width_factor: f64,
}

pub(super) fn draw_guitar_grid(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, at: Pos, call: &BoxCall) {
    let chord = Chord::of(item);
    let p6 = if item.p(6) == 0.0 { 1.0 } else { f64::from(item.p(6)) };
    let scale = match real(amod(f64::from(item.p(16)), 10.0)) {
        0.0 => 1.0,
        s => s,
    };
    let (kind, width) = if item.p(17) < 0.0 { (WITHOUT_NUT, -f64::from(item.p(17))) } else { (chord.kind, f64::from(item.p(17))) };
    let chord = Chord { kind, ..chord };
    let small = real((1.0 - scale) / c(3.5) + scale);
    let staff = doc.staff_of(item);
    let step = staff.step;
    let has_grid = chord.kind != NAME_ONLY && chord.kind != DICTIONARY_NAME_ONLY;
    let mut grid = None;
    if has_grid {
        let mut g = grid_lines(doc, item, canvas, at, &staff, p6, width, small, &chord);
        if chord.kind == WITH_NUT {
            draw_nut(canvas, &mut g);
        }
        if chord.p13 != 0.0 {
            draw_fingering(doc, canvas, &g, call, p6, &chord);
        }
        grid = Some(g);
    }
    let mut text = FONT_PREFIX.to_vec();
    let text_unit = real(step * p6 / 25.0);
    let p3 = real(f64::from(item.p(15)) + f64::from(item.p(3)));
    let name_level = grid.as_ref().map(|g| real(f64::from(g.frets - 1) * c(1.72) * p6 + f64::from(item.p(4))));
    if chord.root != 0 || chord.barre != 0 {
        if let (Some(g), Some(level)) = (&grid, name_level) {
            if chord.barre > 0 && chord.barre % 100 != 0 {
                draw_fret_number(doc, item, canvas, g, &chord, (p3, level), (p6, text_unit, small));
            }
        }
        if !chord_name(&mut text, item, &chord) {
            return;
        }
    }
    if let Some(g) = &grid {
        draw_barre(doc, item, canvas, g, &chord, p6);
    }
    let named = chord.root >= 10 || (chord.root < 0 && text.len() > FONT_PREFIX.len());
    if named {
        let size = real(scale * p6) as f32;
        let mut call = text_call(doc, item, &text, size);
        if let (Some(g), Some(level)) = (&grid, name_level) {
            let p4 = real((f64::from(item.p(19)) + c(5.2)) * p6 + level);
            let width = f64::from(text::width(doc, &call));
            let x = real(f64::from(g.gaps) * text_unit * g.width_factor + p3 - width / 2.0);
            call.origin = Pos::new(real(150.0 * x), staff.y(p4));
            call.p3 = x as f32;
        }
        draw_text(doc, item, canvas, &call);
    }
}

/// draw_text for a string of the grid at the item's position, size `size`, in the item's colour.
fn text_call<'t>(doc: &Document<'_>, item: ItemRef<'_>, text: &'t [u8], size: f32) -> TextCall<'t> {
    TextCall {
        text,
        origin: doc.position(item),
        p3: item.p(3),
        item_code: item.code(),
        staff: item.staff(),
        spread: 1.0,
        width: size,
        // Text records take their colour from P26 (sample 000, item 94).
        colour: (item.p(26) != 0.0).then_some(item.p(26)),
        current_font: font_before(doc, item),
        ..TextCall::default()
    }
}

/// Strings (with finger numbers above them, P18) and fret lines.
#[allow(clippy::too_many_arguments)]
fn grid_lines(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    at: Pos,
    staff: &Staff,
    p6: f64,
    width: f64,
    small: f64,
    chord: &Chord,
) -> Grid {
    let step = staff.step;
    let unit = real(step * p6 * c(0.075));
    let width_factor = if item.p(17) == 0.0 { 1.0 } else { width };
    let string_gap = real(unit * width_factor);
    let p14 = trunc(f64::from(item.p(14)));
    let gaps = match p14 / 10 - 1 {
        g if (1..=8).contains(&g) => g,
        _ => 5,
    };
    let frets = match p14 % 10 {
        f if f < 1 => 5,
        f => f,
    };
    let top = real(f64::from(frets * FRET) * unit + at.y);
    let numbers = (chord.p18 > 0.0).then(|| FingerNumbers::new(item, staff, p6, small, chord.p18));
    let string_x = |s: i32| real(f64::from(s * FRET) * string_gap + at.x);
    let mut divisor = 100_000;
    let mut digits = numbers.as_ref().map_or(0, |n| n.digits);
    (0..=gaps).for_each(|s| {
        let x = string_x(s);
        if let (Some(numbers), true) = (&numbers, divisor != 0) {
            let digit = digits / divisor;
            digits %= divisor;
            divisor /= 10;
            numbers.draw(doc, item, canvas, x, digit);
        }
        canvas.segment(Pos::new(x, at.y), Pos::new(x, top));
    });
    let last_x = string_x(gaps);
    let fret_y = |j: i32| real(f64::from(j * FRET) * unit + at.y);
    (0..=frets).for_each(|j| canvas.segment(Pos::new(at.x, fret_y(j)), Pos::new(last_x, fret_y(j))));
    Grid {
        staff: *staff,
        step,
        unit,
        string_gap,
        x0: at.x,
        y0: at.y,
        gaps,
        frets,
        top,
        last_x,
        second: fret_y(frets - 1),
        third: fret_y(frets - 2),
        width_factor,
    }
}

/// Finger numbers above the strings (P18, one digit per string from the
/// left, 9 the thumb `T`; 5–7 are not drawn).
struct FingerNumbers {
    digits: i32,
    level: f64,
    size: f32,
    shift: f64,
}

impl FingerNumbers {
    fn new(item: ItemRef<'_>, staff: &Staff, p6: f64, small: f64, p18: f32) -> Self {
        let factor = real(small * p6);
        Self {
            digits: trunc(f64::from(p18)),
            level: real(f64::from(item.p(4)) - factor * c(2.6)),
            size: real(factor * c(0.6)) as f32,
            shift: real(staff.step * c(0.032) * factor),
        }
    }

    fn draw(&self, doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, x: f64, digit: i32) {
        let glyph = match digit {
            5..=7 => return,
            8 => b'0',
            9 => b'T',
            d => b'0' + d as u8,
        };
        let text = [FONT_PREFIX, &[glyph]].concat();
        let p3 = real(x / 150.0 - self.shift);
        let mut call = text_call(doc, item, &text, self.size);
        call.origin = Pos::new(real(150.0 * p3), doc.staff_of(item).y(self.level));
        call.p3 = p3 as f32;
        draw_text(doc, item, canvas, &call);
    }
}

/// The nut: a filled bar 60/160 of a fret high on top of the grid.
fn draw_nut(canvas: &mut Canvas<'_>, grid: &mut Grid) {
    let bar = real(grid.unit * 60.0 + grid.top);
    canvas.point(Pos::new(grid.x0, bar), Pen::Fill);
    [(grid.x0, grid.top), (grid.last_x, grid.top), (grid.last_x, bar), (grid.x0, bar)]
        .into_iter()
        .for_each(|(x, y)| canvas.point(Pos::new(x, y), Pen::Continue));
    grid.top = bar;
}

/// The frets of P13 (one digit per string): a filled dot in the fret, an
/// open circle (8) or a cross (9) above the nut. The screen draws them with
/// 10 degrees per side; print, and so the refined style, draws them round
/// unless there are finger numbers (P18).
fn draw_fingering(doc: &Document<'_>, canvas: &mut Canvas<'_>, grid: &Grid, call: &BoxCall, p6: f64, chord: &Chord) {
    let mut digits = trunc(f64::from(chord.p13));
    let mut divisor = if grid.gaps < 5 { 10i32.pow(grid.gaps as u32) } else { 100_000 };
    let dot_size = if p6 != 0.0 { real(p6 * c(1.3)) } else { c(1.3) };
    let string_step = real(grid.string_gap * 160.0);
    let mut x = grid.x0;
    (1..=(grid.gaps + 1).min(6)).for_each(|_| {
        let fret = digits / divisor;
        if fret != 0 {
            let y = match fret {
                8 => real(grid.unit * 95.0 + grid.top),
                f if f > 8 => real(grid.unit * 10.0 + grid.top),
                f => real(f64::from((grid.frets - f) * FRET + FRET / 2) * grid.unit + grid.y0),
            };
            if fret == 9 {
                draw_cross(canvas, grid, x, y);
            } else {
                let open = fret == 8;
                let dot = BoxCall {
                    kind: chord.kind,
                    width: if open { real(dot_size * c(0.8)) } else { dot_size },
                    height: 0.0,
                    p8: 0.0,
                    ip8: 0,
                    ip9: 0,
                    ip10: 0,
                    ip11: 360,
                    ip12: if doc.refined() && chord.p18 == 0.0 { 1 } else { 10 },
                    fill: !open,
                    ..*call
                };
                draw_styled_box(doc, canvas, Pos::new(x, y), grid.step, &dot);
            }
        }
        digits %= divisor;
        divisor /= 10;
        x = real(string_step + x);
    });
}

fn draw_cross(canvas: &mut Canvas<'_>, grid: &Grid, x: f64, y: f64) {
    [grid.unit, -grid.unit].into_iter().for_each(|reach| {
        CROSS_X.iter().zip(CROSS_Y).enumerate().for_each(|(k, (&dx, dy))| {
            let at = Pos::new(real(reach * f64::from(dx) + x), real(grid.unit * f64::from(dy) + y));
            canvas.point(at, if k == 0 { Pen::Fill } else { Pen::Continue });
        });
    });
}

/// The fret number right of the grid (`5 fr` for P12 = xx05), lowered by
/// the fractional part of P12.
fn draw_fret_number(
    doc: &Document<'_>,
    item: ItemRef<'_>,
    canvas: &mut Canvas<'_>,
    grid: &Grid,
    chord: &Chord,
    (p3, level): (f64, f64),
    (p6, text_unit, small): (f64, f64, f64),
) {
    let fret = chord.barre % 100;
    let text = [FONT_PREFIX, fret.to_string().as_bytes(), b" fr"].concat();
    let x = real((f64::from(grid.gaps * 2) * grid.width_factor + c(1.2)) * text_unit + p3);
    let y = real(p6 * c(0.2) + level);
    let y = real(y - amod(f64::from(item.p(12)), 1.0) * c(17.2) * p6);
    let mut call = text_call(doc, item, &text, real(small * p6 * c(0.6)) as f32);
    call.origin = Pos::new(real(150.0 * x), grid.staff.y(y));
    call.p3 = x as f32;
    call.space = -0.65_f32;
    draw_text(doc, item, canvas, &call);
}

/// The barre slur over strings A..B of P12 = `ABFF` (library symbol 209).
fn draw_barre(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>, grid: &Grid, chord: &Chord, p6: f64) {
    if chord.barre < 100 {
        return;
    }
    let from = match chord.barre / 1000 {
        0 => 1,
        f => f,
    };
    let to = match (chord.barre % 1000) / 100 {
        0 => 6,
        t => t,
    };
    let span = to - from;
    if span < 1 {
        return;
    }
    let (lowest, open) = barre_frets(grid, chord, from, to);
    let size_x = real(f64::from(span) * c(0.2) * p6 * grid.width_factor);
    let size_y = real((f64::from(span) * c(0.05) + c(0.55)) * p6);
    let lift = real(p6 * 4.0 * grid.step);
    let lift = if open.is_some_and(|s| (from..=to).contains(&s)) { real(lift * 2.0) } else { lift };
    let y = real(grid.top + lift);
    let y = if lowest > 1 { real(grid.second - (grid.second - grid.third) * f64::from(lowest - 2)) } else { y };
    let x = real(f64::from(from - 1) * real(grid.string_gap * 160.0) + grid.x0);
    let context = ItemContext { code: crate::codes::SYMBOL, pixels: 0, ..ItemContext::of(item) };
    let call = SymbolCall::sized(BARRE_SYMBOL, size_x, size_y);
    draw_library_symbol(doc, &context, canvas, Pos::new(x, y), grid.step, &call);
}

/// The lowest fret on the barre's end strings and the last open or muted
/// string, as the fingering loop records them.
fn barre_frets(grid: &Grid, chord: &Chord, from: i32, to: i32) -> (i32, Option<i32>) {
    let mut digits = trunc(f64::from(chord.p13));
    if digits == 0 {
        return (99, None);
    }
    let mut divisor = if grid.gaps < 5 { 10i32.pow(grid.gaps as u32) } else { 100_000 };
    let mut lowest = 99;
    let mut open = None;
    (1..=(grid.gaps + 1).min(6)).for_each(|string| {
        let fret = digits / divisor;
        if fret >= 8 {
            open = Some(string);
        } else if fret != 0 && (string == from || string == to) && fret < lowest {
            lowest = fret;
        }
        digits %= divisor;
        divisor /= 10;
    });
    (lowest, open)
}

/// Builds the chord name after the font prefix: root letter and accidental,
/// then the dictionary's name or P8's type and P9–P11. `false` when the
/// root letter is out of range, which ends the drawing.
fn chord_name(text: &mut Vec<u8>, item: ItemRef<'_>, chord: &Chord) -> bool {
    let font = trunc(f64::from(item.p(16)));
    text[1] = b'0' + (font / 100) as u8;
    text[2] = b'0' + ((font % 100) / 10) as u8;
    let root = if chord.root < 0 { chord.given_root } else { chord.root };
    if root < 10 {
        return true;
    }
    let letter = match root / 10 + 66 {
        l if l > 73 => return false,
        l if l > 71 => root / 10 + 59,
        l => l,
    };
    text.push(letter as u8);
    let accidental = match root % 10 {
        a @ 1..=2 => Some(a),
        _ => None,
    };
    if let Some(a) = accidental {
        text.extend([b'?', b'0' + a as u8]);
    }
    if chord.root < 1 {
        dictionary_suffix(text, -chord.root, chord.chord_type);
    } else {
        type_suffix(text, chord);
    }
    true
}

/// A dictionary chord's name with its own root left out (0x4A013C).
fn dictionary_suffix(text: &mut Vec<u8>, row: i32, chord_type: i32) {
    let name = dictionary().name(row, chord_type).map_or_else(|| vec![b' '; NAME_LENGTH], <[u8]>::to_vec);
    let name = match name.first() {
        Some(b'_') => {
            text[..3].copy_from_slice(&name[..3]);
            name[3..].to_vec()
        }
        _ => name,
    };
    let spelled_differently = text.get(4) == Some(&b'?')
        && !matches!((text.get(5), text.get(3)), (Some(b'2'), Some(b'B' | b'E')) | (Some(b'1'), Some(b'C' | b'F')));
    let skip = if spelled_differently { 3 } else { 1 };
    let rest: Vec<u8> = name.iter().skip(skip).copied().collect();
    let length = rest.iter().rposition(|&b| b != b' ').map_or(0, |i| i + 1);
    text.extend_from_slice(&rest[..length]);
}

/// P8's chord type and P9–P11's additions (0x49FC9D–0x4A0137).
fn type_suffix(text: &mut Vec<u8>, chord: &Chord) {
    let suffix: &[u8] = match chord.chord_type {
        1 => b"maj",
        2 => b"m",
        3 => b"?0",
        4 => b"?9",
        5 => b"+",
        6 => b"dim",
        7 => b"aug",
        8 => b"?8",
        9 => b"?-",
        _ => b"",
    };
    text.extend_from_slice(suffix);
    if chord.p9 != 0 {
        let sign = chord.p9 / 100;
        match sign {
            0 => {}
            4 => text.push(b'+'),
            s => text.extend([
                b'?',
                match s {
                    5 => b'-',
                    6 => b'8',
                    s => b'0' + s as u8,
                },
            ]),
        }
        push_degree(text, chord.p9 % 100);
    }
    if chord.p10 != 0 {
        let parenthesis = chord.p10 / 1000 == 3;
        match chord.p10 / 1000 {
            1 => text.extend_from_slice(b"sus"),
            2 => text.extend_from_slice(b"add"),
            3 => text.extend_from_slice(b"(add"),
            _ => {}
        }
        let rest = chord.p10 % 1000;
        if rest / 100 != 0 {
            text.extend([b'?', b'0' + (rest / 100) as u8]);
        }
        push_degree(text, rest % 100);
        if parenthesis {
            text.push(b')');
        }
    }
    if chord.p11 != 0 {
        text.push(b'/');
        let letter = chord.p11 / 1000;
        if letter != 0 {
            let l = if letter + 66 > 71 { letter + 59 } else { letter + 66 };
            text.push(l as u8);
        }
        let rest = chord.p11 % 1000;
        if rest / 100 != 0 {
            text.extend([b'?', b'0' + (rest / 100) as u8]);
        }
        push_degree(text, rest % 100);
    }
}

/// FUN_004A0729: one or two digits.
fn push_degree(text: &mut Vec<u8>, degree: i32) {
    if degree == 0 {
        return;
    }
    if degree > 9 {
        text.push(b'0' + (degree / 10) as u8);
    }
    text.push(b'0' + (degree % 10) as u8);
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn dictionary_reads_guitar_dat() {
        let c_major = dictionary().entry(1, 1, 0).expect("C major");
        assert_eq!(c_major, Fingering { frets: 932818, barre: 0, fingers: 732717 });
        assert_eq!(dictionary().entry(1, 1, 1).map(|f| f.barre), Some(3500));
        assert_eq!(&dictionary().name(2, 2).unwrap()[..4], b"D?1m");
    }

    #[test]
    fn rows_from_roots() {
        assert_eq!(dictionary_row(10), 1);
        assert_eq!(dictionary_row(12), 2);
        assert_eq!(dictionary_row(40), 6);
        assert_eq!(dictionary_row(60), 10);
        assert_eq!(dictionary_row(71), 11);
    }
}
