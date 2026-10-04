//! New items from shortcut words (WinScore help, "How to Input a Single
//! Item" and "Index of Letter Commands"), with the default parameters the
//! engine gives them.
//!
//! `NOTE 8 20` puts a note on staff 8 at position 20: the numbers after a
//! word fill P2, P3, … and a zero keeps the default. P2 defaults to the staff
//! of the item last edited or entered, P3 to 100.

use crate::params::Draft;

pub const DEFAULT_P3: f32 = 100.0;

/// What a creation word asks for, before the staff is known.
#[derive(Debug, Clone, PartialEq)]
pub struct Template {
    /// P1, P3, P4, …; P2 is chosen when the item is placed.
    pub params: Vec<f32>,
    pub staff: StaffChoice,
    /// Clefs stay at their own P3 whatever position is typed.
    pub fixed_p3: bool,
}

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub enum StaffChoice {
    /// The staff of the item last edited or entered.
    Current,
    /// One above the highest staff number any item uses (new staff lines).
    AboveHighest,
}

impl Template {
    fn new(code: f32, rest: &[f32]) -> Self {
        let mut params = vec![code, 0.0];
        params.extend_from_slice(rest);
        Self { params, staff: StaffChoice::Current, fixed_p3: false }
    }

    /// The item on `staff`, with the typed numbers `args` (P2, P3, …) over the defaults.
    pub fn place(&self, staff: f32, args: &[f32]) -> Draft {
        let mut draft = Draft::new(&self.params);
        draft.set(2, staff);
        args.iter().enumerate().filter(|(_, &v)| v != 0.0).for_each(|(i, &v)| {
            let n = i + 2;
            if !(n == 3 && self.fixed_p3) {
                draft.set(n, v);
            }
        });
        draft
    }
}

/// Plain words with fixed defaults, as measured on the engine.
const PLAIN: &[(&str, f32, &[f32])] = &[
    ("REST", 2.0, &[100.0, 0.0, 0.0, 0.0, 1.0]),
    ("BAR", 14.0, &[100.0, 1.0]),
    ("BARD", 14.0, &[100.0, 1.0, 1.0]),
    ("BARH", 14.0, &[100.0, 1.0, 2.0]),
    ("BARL", 14.0, &[100.0, 1.0, 3.0]),
    ("BARR", 14.0, &[100.0, 1.0, 4.0]),
    ("BARRD", 14.0, &[100.0, 1.0, 5.0]),
    ("BARBC", 14.0, &[100.0, 1.0, 8.0]),
    ("BARBK", 14.0, &[100.0, 1.0, 9.0]),
    ("LINE", 4.0, &[100.0, 0.0, 0.0, 120.0]),
    ("LIN", 4.0, &[100.0, 0.0, 0.0, 120.0]),
    ("CRH", 4.0, &[100.0, -1.0, 999.0, 120.0]),
    ("DCH", 4.0, &[100.0, -1.0, 999.0, 120.0, -1.0]),
    ("CR-", 4.0, &[100.0, -1.0, 999.0, 120.0, 0.0, 0.0, 0.0, 0.0, 1.0]),
    ("DC-", 4.0, &[100.0, -1.0, 999.0, 120.0, -1.0, 0.0, 0.0, 0.0, 1.0]),
    ("DASH", 4.0, &[100.0, 0.0, 0.0, 120.0, 1.0, 1.0, 2.0]),
    ("ARP", 4.0, &[100.0, 0.0, 12.0, 0.0, -1.0]),
    ("SLUR", 5.0, &[100.0, 14.0, 14.0, 120.0, 3.0, -1.0]),
    ("SLURD", 5.0, &[100.0, 0.0, 0.0, 120.0, -3.0, -1.0]),
    ("TIE", 5.0, &[100.0, 14.0, 14.0, 120.0, 3.0, -2.0]),
    ("TIED", 5.0, &[100.0, 0.0, 0.0, 120.0, -3.0, -2.0]),
    ("END", 5.0, &[100.0, 15.0, 15.0, 120.0, 5.0, 1.0]),
    ("END1", 5.0, &[100.0, 15.0, 15.0, 120.0, 5.0, 1.0]),
    ("END2", 5.0, &[100.0, 15.0, 15.0, 120.0, 5.0, 2.0]),
    ("BEAM", 6.0, &[100.0, 8.0, 8.0, 120.0, 11.0]),
    ("BEAMD", 6.0, &[100.0, 6.0, 6.0, 120.0, 21.0]),
    ("TRILL", 7.0, &[100.0, 15.0, 0.0, 120.0]),
    ("TRI", 7.0, &[100.0, 15.0, 0.0, 120.0]),
    ("OVA", 7.0, &[100.0, 14.0, 0.0, 120.0, 8.0, 0.0, 0.0, 0.0, 0.0, -1.0]),
    ("OBA", 7.0, &[100.0, -2.0, 0.0, 120.0, -8.0, 0.0, 0.0, 0.0, 0.0, 1.0]),
    ("OMA", 7.0, &[100.0, 14.0, 0.0, 120.0, 15.0, 0.0, 0.0, 0.0, 0.0, -1.0]),
    ("PEDA", 7.0, &[100.0, -1.0, 0.0, 140.0, 20.0]),
    ("PEDB", 7.0, &[100.0, -1.0, 0.0, 140.0, 21.0]),
    ("PEDC", 7.0, &[100.0, -1.0, 0.0, 140.0, 22.0]),
    ("HARP", 7.0, &[100.0, -1.0, 0.0, 0.0, 1.0, 111.0, 1111.0]),
    ("NUMB", 10.0, &[100.0, 13.0, 1.0]),
    ("NUM", 10.0, &[100.0, 13.0, 1.0]),
    ("BOX", 12.0, &[100.0, 15.0, 0.0, 10.0]),
    ("CIRCLE", 12.0, &[100.0, 15.0, 1.0, 10.0]),
    ("CIR", 12.0, &[100.0, 15.0, 1.0, 10.0]),
    ("GUIT", 12.0, &[100.0, 16.0, -4.0, 0.0, 10.0]),
    ("KSIG", 17.0, &[100.0, 0.0, 2.0]),
    ("METER", 18.0, &[100.0, 0.0, 4.0, 4.0]),
    ("COMM", 18.0, &[100.0, 0.0, 99.0]),
    ("CUT", 18.0, &[100.0, 0.0, 98.0]),
    ("TREM", 6.0, &[100.0, 5.0, 0.0, 0.0, -10.0, 0.0, 0.0, 11.0]),
    ("TREMD", 6.0, &[100.0, 6.0, 0.0, 0.0, -20.0, 0.0, 0.0, 11.0]),
];

/// Code 9 library symbols: word, P4, P5, P6.
const SYMBOLS: &[(&str, f32, f32, f32)] = &[
    ("ACL", -2.0, 68.0, 0.0),
    ("ACN", 13.0, 22.0, 0.25),
    ("ACT", 13.0, 119.0, 0.0),
    ("ARC", 13.0, 67.0, 0.0),
    ("ATM", -2.0, 78.0, 0.0),
    ("CRS", -2.0, 63.0, 0.0),
    ("DIM", -2.0, 64.0, 0.0),
    ("DNB", 13.0, 28.0, 0.25),
    ("ESP", -2.0, 79.0, 0.0),
    ("FER", 13.0, 31.0, 0.25),
    ("GLI", -2.0, 72.0, 0.0),
    ("HAR", 13.0, 30.0, 0.25),
    ("HVW", 13.0, 36.0, 0.25),
    ("INV", 13.0, 35.0, 0.25),
    ("MEN", -2.0, 80.0, 0.0),
    ("MOL", -2.0, 73.0, 0.0),
    ("MOR", 13.0, 34.0, 0.25),
    ("PED", -2.0, 70.0, 0.0),
    ("PIZ", 13.0, 66.0, 0.0),
    ("STAC", 13.0, 24.0, 0.25),
    ("SUB", -2.0, 85.0, 0.0),
    ("TENU", 13.0, 23.0, 0.25),
    ("TUR", 13.0, 75.0, 0.0),
    ("UPB", 13.0, 29.0, 0.25),
    ("WED", 13.0, 21.0, 0.25),
    ("WEDS", 13.0, 25.0, 0.25),
    ("P", -2.0, 53.0, 0.0),
    ("PP", -2.0, 52.0, 0.0),
    ("MP", -2.0, 54.0, 0.0),
    ("MF", -2.0, 55.0, 0.0),
    ("F", -2.0, 56.0, 0.0),
    ("FF", -2.0, 57.0, 0.0),
    ("SF", -2.0, 61.0, 0.0),
    ("SFZ", -2.0, 62.0, 0.0),
];

/// Clef words: kind (P5) for TREB, BASS, …; an M at the end makes a mini clef.
const CLEFS: &[(&str, f32)] = &[
    ("TREB", 0.0),
    ("TRE", 0.0),
    ("CLEF", 0.0),
    ("CLE", 0.0),
    ("BASS", 1.0),
    ("BAS", 1.0),
    ("ALTO", 2.0),
    ("ALT", 2.0),
    ("TENOR", 3.0),
    ("TEN", 3.0),
    ("PERC", 4.0),
    ("PER", 4.0),
    ("CLEFTA", 66.0),
];
const CLEF_P3: f32 = 2.0;
const MINI_CLEF: f32 = 100.0;

/// NOTE with optional D (stem down) and F, S or N (accidental): NOTEDS.
fn note(word: &str) -> Option<Template> {
    let rest = word.strip_prefix("NOTE").or_else(|| (word == "NOT").then_some(""))?;
    let (down, accidental) = match rest.strip_prefix('D') {
        Some(acc) => (true, acc),
        None => (false, rest),
    };
    let accidental = match accidental {
        "" => 0.0,
        "F" => 1.0,
        "S" => 2.0,
        "N" => 3.0,
        _ => return None,
    };
    let (level, stem) = if down { (13.0, 20.0) } else { (1.0, 10.0) };
    Some(Template::new(1.0, &[DEFAULT_P3, level, stem + accidental, 0.0, 1.0]))
}

/// Clefs that take the mini suffix; TREM is a tremolo, not a mini TRE.
const MINI_CAPABLE: [&str; 6] = ["TREB", "CLEF", "BASS", "ALTO", "TENOR", "PERC"];

fn clef(word: &str) -> Option<Template> {
    let (base, mini) = match word.strip_suffix('M') {
        Some(base) if MINI_CAPABLE.contains(&base) => (base, true),
        _ => (word, false),
    };
    let &(_, kind) = CLEFS.iter().find(|(w, _)| *w == base)?;
    let level = if mini { MINI_CLEF } else { 0.0 };
    Some(Template { fixed_p3: true, ..Template::new(3.0, &[CLEF_P3, level, kind]) })
}

/// A word followed by digits, like BAR2 or METER34.
fn numbered<'a>(word: &'a str, prefix: &str) -> Option<&'a str> {
    word.strip_prefix(prefix).filter(|d| !d.is_empty() && d.chars().all(|c| c.is_ascii_digit()))
}

fn digit_value(digits: &str) -> f32 {
    digits.parse::<u32>().map_or(0.0, |n| n as f32)
}

/// METER34 is 3/4, METER128 12/8, METER316 3/16, METER1216 12/16.
fn meter(word: &str) -> Option<Template> {
    let digits = numbered(word, "METER")?;
    let long_denominator = ["16", "32", "64"].iter().any(|d| digits.len() > 2 && digits.ends_with(d));
    let split = digits.len() - if long_denominator || digits.len() == 4 { 2 } else { 1 };
    let (top, bottom) = digits.split_at(split);
    Some(Template::new(18.0, &[DEFAULT_P3, 0.0, digit_value(top), digit_value(bottom)]))
}

/// KSIG+2, KSIG-3B: number of sharps or flats, then B, A or T for the clef.
fn key_signature(word: &str) -> Option<Template> {
    let rest = word.strip_prefix("KSIG")?;
    if rest.is_empty() {
        return None;
    }
    let (count, clef) = rest.split_at(rest.trim_end_matches(['B', 'A', 'T']).len());
    let clef = match clef {
        "" => 0.0,
        "B" => 1.0,
        "A" => 2.0,
        "T" => 3.0,
        _ => return None,
    };
    let count: f32 = count.parse().ok()?;
    Some(Template::new(17.0, &[DEFAULT_P3, 0.0, count, clef]))
}

fn numbered_variant(word: &str) -> Option<Template> {
    if let Some(d) = numbered(word, "BAR") {
        return Some(Template::new(14.0, &[DEFAULT_P3, digit_value(d)]));
    }
    if let Some(d) = numbered(word, "BEAM") {
        return Some(Template::new(6.0, &[DEFAULT_P3, 8.0, 8.0, 120.0, 10.0 + digit_value(d)]));
    }
    if let Some(d) = numbered(word, "SLURD") {
        return Some(Template::new(5.0, &[DEFAULT_P3, 0.0, 0.0, 120.0, -2.0, digit_value(d)]));
    }
    if let Some(d) = numbered(word, "SLUR") {
        return Some(Template::new(5.0, &[DEFAULT_P3, 14.0, 14.0, 120.0, 2.0, digit_value(d)]));
    }
    if let Some(d) = numbered(word, "TREMD") {
        return Some(Template::new(6.0, &[DEFAULT_P3, 6.0, 0.0, 0.0, -20.0, 0.0, 0.0, 10.0 + digit_value(d)]));
    }
    if let Some(d) = numbered(word, "TREM") {
        return Some(Template::new(6.0, &[DEFAULT_P3, 5.0, 0.0, 0.0, -10.0, 0.0, 0.0, 10.0 + digit_value(d)]));
    }
    None
}

fn staff(word: &str) -> Option<Template> {
    matches!(word, "STAFF" | "STA").then(|| Template { staff: StaffChoice::AboveHighest, ..Template::new(8.0, &[0.0]) })
}

fn plain(word: &str) -> Option<Template> {
    let &(_, code, rest) = PLAIN.iter().find(|(w, _, _)| *w == word)?;
    Some(Template::new(code, rest))
}

fn symbol(word: &str) -> Option<Template> {
    let &(_, level, symbol, size) = SYMBOLS.iter().find(|(w, ..)| *w == word)?;
    Some(Template::new(9.0, &[DEFAULT_P3, level, symbol, size]))
}

/// The template a creation word stands for (words are upper case).
pub fn template(word: &str) -> Option<Template> {
    note(word)
        .or_else(|| clef(word))
        .or_else(|| staff(word))
        .or_else(|| plain(word))
        .or_else(|| symbol(word))
        .or_else(|| meter(word))
        .or_else(|| key_signature(word))
        .or_else(|| numbered_variant(word))
}

#[cfg(test)]
mod tests {
    use super::*;

    fn made(word: &str, staff: f32, args: &[f32]) -> Vec<f32> {
        let draft = template(word).unwrap().place(staff, args);
        (1..=draft.len()).map(|n| draft.get(n)).collect()
    }

    #[test]
    fn notes_with_stem_and_accidental() {
        assert_eq!(made("NOTE", 1.0, &[]), [1.0, 1.0, 100.0, 1.0, 10.0, 0.0, 1.0]);
        assert_eq!(made("NOTEDS", 2.0, &[]), [1.0, 2.0, 100.0, 13.0, 22.0, 0.0, 1.0]);
        assert!(template("NOTEX").is_none());
    }

    #[test]
    fn typed_numbers_fill_p2_on_and_zero_keeps_the_default() {
        assert_eq!(made("NOTE", 1.0, &[2.0, 30.0]), [1.0, 2.0, 30.0, 1.0, 10.0, 0.0, 1.0]);
        assert_eq!(made("NOTE", 2.0, &[0.0, 0.0, 5.0]), [1.0, 2.0, 100.0, 5.0, 10.0, 0.0, 1.0]);
    }

    #[test]
    fn clefs_keep_their_position() {
        assert_eq!(made("BASS", 1.0, &[2.0, 30.0]), [3.0, 2.0, 2.0, 0.0, 1.0]);
        assert_eq!(made("ALTOM", 1.0, &[]), [3.0, 1.0, 2.0, 100.0, 2.0]);
    }

    #[test]
    fn meters_split_their_digits() {
        let meter = |w| made(w, 1.0, &[])[4..].to_vec();
        assert_eq!(meter("METER34"), [3.0, 4.0]);
        assert_eq!(meter("METER128"), [12.0, 8.0]);
        assert_eq!(meter("METER316"), [3.0, 16.0]);
        assert_eq!(meter("METER1216"), [12.0, 16.0]);
    }

    #[test]
    fn key_signatures_and_numbered_words() {
        assert_eq!(made("KSIG-3B", 1.0, &[]), [17.0, 1.0, 100.0, 0.0, -3.0, 1.0]);
        assert_eq!(made("BAR2", 1.0, &[]), [14.0, 1.0, 100.0, 2.0]);
        assert_eq!(made("SLURD3", 1.0, &[]), [5.0, 1.0, 100.0, 0.0, 0.0, 120.0, -2.0, 3.0]);
    }
}
