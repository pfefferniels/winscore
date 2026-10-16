//! A line of five-pass input shown while it is typed: the items it would add,
//! drawn against the score; the element the caret is on; and how far the
//! passes have got.
//!
//! The preview reads the passes as they would be inserted, with two
//! allowances for text still being typed. While the caret is in pass 1 or 2,
//! notes that pass 2 has not reached yet are shown as quarters (finished as
//! typed, they would become grace notes). And when a pass does not parse, the
//! preview cuts it back to before the failing item, so that what was typed
//! before it stays on the page.

use std::ops::Range;

use score_format::{Item, MusFile};
use score_input::notes::Clef;
use score_input::{count_rhythms, erased_items, run_outlined, ErrorKind, InputError, Motives, Options, Outline, Passes, RhythmCount, StaffArgs};
use score_render::{render_item, DisplayList, ItemId};
use wasm_bindgen::prelude::*;

use crate::input::{on_staff, options, pass_error, utf16_offset, InputLine, PassError, CLEF_CODE, STAFF_CODE};
use crate::{EncodedList, Score};

/// What [`preview`] shows for a line.
#[derive(Debug, Clone, PartialEq)]
pub struct Preview {
    /// The items the preview adds, drawn against the score with them appended.
    pub list: DisplayList,
    /// File index of the first of them in that score.
    pub first: usize,
    pub items: Vec<Item>,
    /// The line as typed: the number of items it adds, or its error.
    pub check: Result<usize, PassError>,
    /// That error stops at the end of an item that more typing could finish (`K2`, `C4:`, `X`).
    pub unfinished: bool,
    /// The preview had to cut a pass back to show something.
    pub partial: bool,
    /// Notes and chords in the preview, numbered in passes 3-5.
    pub notes: usize,
    /// Pass 2 as typed against pass 1 as typed, when both parse.
    pub rhythms: Option<RhythmCount>,
    /// File indices of the items of the elements at the caret.
    pub focus: Vec<usize>,
    /// Each of those elements in words, e.g. "F♯4, quarter".
    pub described: Vec<String>,
    /// Items of pass 1 that WinScore's reader erases (`Y`, `C0`), as UTF-16 ranges.
    pub erased: Vec<Range<usize>>,
}

/// The items of the line and of the staff item IN adds when the staff is missing.
struct Run {
    items: Vec<Item>,
    outline: Vec<Outline>,
}

/// One rhythm per note, chord or rest, all the same: the pass-1 runs that look for
/// the caret's element do not depend on pass 2.
const EVEN: &str = "4;";
/// Where the caret's element is looked for, at most this many elements in a pass-3 range.
const MAX_RANGE: usize = 200;

fn passes(texts: &[String; 5]) -> Passes<'_> {
    let [notes, rhythms, marks, beams, slurs] = texts.each_ref().map(String::as_str);
    Passes { notes, rhythms, marks, beams, slurs }
}

fn run_line(file: &MusFile, options: &Options, texts: &[String; 5], motives: &Motives) -> Result<Run, InputError> {
    let (items, mut outline) = run_outlined(&passes(texts), options, &mut motives.clone())?;
    let staff = (!file.items.iter().any(|item| on_staff(item, STAFF_CODE, options.staff)))
        .then(|| StaffArgs::on(options.staff).staff_item());
    let shift = usize::from(staff.is_some());
    for element in &mut outline {
        element.items = element.items.start + shift..element.items.end + shift;
    }
    Ok(Run { items: staff.into_iter().chain(items).collect(), outline })
}

/// Shortens a pass that fails at byte `at`: up to that point, without the separators
/// before it, else without its last item. False when there is nothing left to cut.
fn cut_back(text: &mut String, at: usize) -> bool {
    let at = (0..=at.min(text.len())).rev().find(|&b| text.is_char_boundary(b)).unwrap_or(0);
    let separators: &[char] = &['/', ',', ':', '\'', ' ', ';'];
    let kept = text[..at].trim_end_matches(separators);
    let mut cut = format!("{kept};");
    if cut == *text {
        let kept = kept.rfind(['/', ',']).map_or("", |i| kept[..i].trim_end_matches(separators));
        cut = format!("{kept};");
    }
    if cut == *text {
        return false;
    }
    *text = cut;
    true
}

/// Pass 2 with a quarter for each note, chord or rest it has not reached.
fn padded(rhythms: &str, given: usize, needed: usize) -> String {
    let body = rhythms.split(';').next().unwrap_or("").trim_end();
    let missing = needed - given;
    if body.is_empty() {
        format!("4X{missing};")
    } else {
        format!("{body}/4X{missing};")
    }
}

/// The item of the pass text around byte `caret`: from after the separator before it
/// to the separator after it.
fn item_around(text: &str, caret: usize) -> Range<usize> {
    let caret = caret.min(text.split(';').next().unwrap_or("").len());
    let start = text[..caret].rfind(['/', ',']).map_or(0, |i| i + 1);
    let end = text[caret..].find(['/', ',', ';']).map_or(text.len(), |i| caret + i);
    start..end
}

fn closed(prefix: &str) -> String {
    format!("{};", prefix.trim_end_matches(['/', ',', ' ']))
}

/// The pass-1 elements the item at `caret` makes, found by reading the text up to the
/// item and up to its end.
fn elements_at_pass_one(file: &MusFile, options: &Options, notes: &str, caret: usize, motives: &Motives) -> Range<usize> {
    let item = item_around(notes, caret);
    let count = |prefix: &str| {
        let texts = [closed(prefix), EVEN.into(), ";".into(), ";".into(), ";".into()];
        run_line(file, options, &texts, motives).map(|run| run.outline.len()).ok()
    };
    match (count(&notes[..item.start]), count(&notes[..item.end])) {
        (Some(before), Some(through)) => before..through,
        _ => 0..0,
    }
}

/// The pass-2 values (from 1) the item at `caret` gives; the next one on an empty item,
/// and after the text (`past_end`).
fn slots_at_pass_two(options: &Options, notes: &str, rhythms: &str, caret: usize, past_end: bool, motives: &Motives) -> Range<usize> {
    let given = |text: String| {
        let texts = [notes.to_owned(), text, ";".into(), ";".into(), ";".into()];
        count_rhythms(&passes(&texts), options, motives).ok().map(|count| count.given)
    };
    let Some(all) = given(rhythms.to_owned()) else { return 0..0 };
    if past_end {
        let next = all.unwrap_or(1) + 1;
        return next..next + 1;
    }
    if all.is_none() {
        return 1..usize::MAX;
    }
    let item = item_around(rhythms, caret);
    // One value alone in the text so far counts as one, not as all.
    let before = given(closed(&rhythms[..item.start])).flatten().unwrap_or(1);
    let through = given(closed(&rhythms[..item.end])).flatten().unwrap_or(1);
    let through = through.max(before + 1);
    before + 1..through + 1
}

/// The numbers typed in an item of passes 3-5, as numbers or `a:b` ranges.
fn numbers(text: &str) -> Vec<(f32, Option<f32>)> {
    text.split_whitespace()
        .filter_map(|token| {
            let mut parts = token.splitn(2, [':', '\'']);
            let first = parts.next()?.trim_start_matches(['+', '=']).parse::<f32>().ok()?;
            let second = parts.next().and_then(|s| s.parse::<f32>().ok());
            Some((first, second))
        })
        .collect()
}

/// Marks drawn from one note to another (hairpins, octave lines, trill lines).
fn spans_notes(name: &str) -> bool {
    matches!(name, "C" | "C+" | "C-" | "DC" | "O" | "OB" | "TRW" | "TRFW" | "TRSW" | "TRNW" | "TRILLW")
}

/// The notes a pass-3 item puts its mark on.
fn notes_at_pass_three(item: &str) -> Vec<usize> {
    let item = item.trim_start().to_ascii_uppercase();
    let unsigned = item.trim_start_matches(['-', '+', '=']);
    let letters = unsigned.find(|c: char| !c.is_ascii_alphabetic()).unwrap_or(unsigned.len());
    // Digits right after the letters belong to the name (F1, S2, TM3).
    let mut named = unsigned[letters..].find(|c: char| !c.is_ascii_digit()).map_or(unsigned.len(), |i| letters + i);
    if &unsigned[..named] == "C" && unsigned[named..].starts_with(['+', '-']) {
        named += 1;
    }
    let (name, rest) = unsigned.split_at(named);
    let round = |n: f32| n.round().max(0.0) as usize;
    let found = numbers(rest);
    if spans_notes(name) {
        let ends: Vec<f32> = found.iter().flat_map(|(a, b)| std::iter::once(*a).chain(*b)).collect();
        return ends
            .chunks(2)
            .flat_map(|pair| match *pair {
                [a, b] => (a.trunc() as usize..=b.ceil().max(a) as usize).take(MAX_RANGE).collect::<Vec<_>>(),
                [a] => vec![a.trunc() as usize],
                _ => Vec::new(),
            })
            .collect();
    }
    found
        .into_iter()
        .flat_map(|(a, b)| match b {
            Some(b) => (round(a)..=round(b).max(round(a))).take(MAX_RANGE).collect::<Vec<_>>(),
            None => vec![round(a)],
        })
        .collect()
}

/// The notes a beam or slur item reaches from its first note to its last.
fn notes_at_connect(item: &str, pass: usize, last: usize) -> Vec<usize> {
    let item = item.trim().to_ascii_uppercase();
    if item.contains('@') || item.contains('[') || (pass == 4 && item.contains('B')) {
        return Vec::new();
    }
    let note = |n: f32| {
        let n = n.abs().trunc() as usize;
        if n >= 100 { n % 100 } else { n }
    };
    if let Some(groups) = item.strip_prefix('X') {
        let mut values = groups.split_whitespace().filter_map(|s| s.parse::<f32>().ok());
        let Some(size) = values.next() else { return Vec::new() };
        let size = (size.abs() as usize).clamp(1, 9);
        return values.flat_map(|start| (note(start)..note(start) + size).collect::<Vec<_>>()).collect();
    }
    let values: Vec<f32> = item
        .split(|c: char| c.is_whitespace())
        .filter_map(|s| s.trim_start_matches(['+', '=']).parse::<f32>().ok())
        .take(2)
        .collect();
    let (from, to) = match *values.as_slice() {
        [a, b] if pass == 5 && note(a) == 0 => (note(b), note(b)),
        [a, b] if pass == 5 && note(b) == 99 => (note(a), last),
        [a, b] if note(b) > note(a) => (note(a), note(b)),
        [a, ..] => (note(a), note(a) + 1),
        [] => return Vec::new(),
    };
    (from..=to).take(MAX_RANGE).collect()
}

/// Levels of notes are counted from the treble clef's: this many steps higher in the others.
fn clef_shift(clef: Clef) -> i32 {
    match clef {
        Clef::Bass => 12,
        Clef::Alto => 6,
        Clef::Tenor => 8,
        Clef::Treble | Clef::Percussion => 0,
    }
}

fn accidental(code: i32) -> &'static str {
    ["", "♭", "♯", "♮", "♭♭", "♯♯", "¼♭", "¾♭", "¼♯", "¾♯"].get(code as usize).copied().unwrap_or("")
}

/// A note item's level on the staff, without the 100 that marks grace and cue notes.
fn level(item: &Item) -> i32 {
    let p4 = item.param(4) as i32;
    if p4.abs() >= 100 { p4 - 100 * p4.signum() } else { p4 }
}

/// The name of a note item's pitch on a staff with `clef`, e.g. "F♯4".
fn pitch(item: &Item, clef: Clef) -> String {
    let step = level(item) - clef_shift(clef) + 27;
    let letter = ['C', 'D', 'E', 'F', 'G', 'A', 'B'][step.rem_euclid(7) as usize];
    let p5 = item.param(5).abs() as i32;
    let sign = accidental(p5 % 10);
    let sign = if p5 >= 100 && !sign.is_empty() { format!("({sign})") } else { sign.to_owned() };
    format!("{letter}{sign}{}", step.div_euclid(7))
}

/// A duration in quarters (P7) in words.
fn duration(quarters: f32) -> String {
    const VALUES: [(f32, &str); 9] = [
        (8.0, "breve"),
        (4.0, "whole"),
        (2.0, "half"),
        (1.0, "quarter"),
        (0.5, "eighth"),
        (0.25, "16th"),
        (0.125, "32nd"),
        (0.0625, "64th"),
        (0.03125, "128th"),
    ];
    if quarters >= 64.0 {
        return "grace note".into();
    }
    let near = |a: f32, b: f32| (a - b).abs() < 0.002;
    for (value, name) in VALUES {
        for (factor, prefix) in [(1.0, ""), (1.5, "dotted "), (1.75, "double-dotted "), (2.0 / 3.0, "triplet "), (0.8, "quintuplet ")] {
            if near(quarters, value * factor) {
                return format!("{prefix}{name}");
            }
        }
    }
    format!("{} quarters", (quarters * 1000.0).round() / 1000.0)
}

fn clef_name(code: i32) -> &'static str {
    ["treble clef", "bass clef", "alto clef", "tenor clef", "percussion clef"].get(code as usize).copied().unwrap_or("clef")
}

/// One element of the line in words; `clef` is the clef in force on the staff.
fn describe(items: &[Item], clef: Clef) -> String {
    let Some(first) = items.first() else { return "key signature without accidentals".into() };
    let small = if first.param(4).abs() >= 100.0 && first.param(7) < 64.0 { " (cue size)" } else { "" };
    match first.code() {
        1 => {
            let mut heads: Vec<&Item> = items.iter().collect();
            heads.sort_by_key(|item| level(item));
            let pitches: Vec<String> = heads.iter().map(|item| pitch(item, clef)).collect();
            format!("{}, {}{small}", pitches.join(" "), duration(first.param(7)))
        }
        2 => {
            let value = duration(first.param(7));
            let measures = first.param(8);
            if first.param(6) == -1.0 {
                format!("invisible {value} rest")
            } else if measures == -1.0 {
                format!("{value} rest with fermata")
            } else if measures > 0.0 {
                format!("rest of {measures} measure{}", if measures == 1.0 { "" } else { "s" })
            } else {
                format!("{value} rest{small}")
            }
        }
        3 => format!("{}{}", if first.param(4) == 100.0 { "small " } else { "" }, clef_name(first.param(5) as i32)),
        8 => format!("new staff {}", first.param(2)),
        14 => {
            let staves = first.param(4);
            let kind = match first.param(5) as i32 {
                1 => "double barline",
                2 => "heavy barline",
                3 => "start-repeat barline",
                4 => "end-repeat barline",
                5 => "double repeat barline",
                7 => "dashed barline",
                _ if staves < 0.0 => "invisible barline",
                _ => "barline",
            };
            if staves.abs() > 1.0 { format!("{kind} over {} staves", staves.abs()) } else { kind.into() }
        }
        17 => {
            let p5 = first.param(5);
            let count = p5.abs() % 100.0;
            let sign = if p5 > 0.0 { "♯" } else { "♭" };
            let naturals = if p5.abs() >= 100.0 { " cancelled by naturals" } else { "" };
            format!("key signature {count}{sign}{naturals}")
        }
        18 => match (first.param(5), first.param(6)) {
            (99.0, 1.0) => "common time".into(),
            (98.0, 1.0) => "cut time".into(),
            (top, bottom) => format!("meter {top}/{bottom}"),
        },
        code => crate::code_name(code).unwrap_or("item").to_lowercase(),
    }
}

/// The clef in force at item `before` of the run: the staff's, then the line's clefs.
fn clef_at(run: &Run, before: usize, staff_clef: Clef) -> Clef {
    run.items[..before.min(run.items.len())]
        .iter()
        .rfind(|item| item.code() == CLEF_CODE)
        .map_or(staff_clef, |clef| Clef::from_code(clef.param(5) as i32))
}

/// Byte offset of UTF-16 offset `units` in `text`.
fn byte_offset(text: &str, units: usize) -> usize {
    let mut count = 0;
    for (byte, c) in text.char_indices() {
        if count >= units {
            return byte;
        }
        count += c.len_utf16();
    }
    text.len()
}

/// The preview of `line` on `file` with the caret in `pass` (1-5) at UTF-16 offset `caret`.
pub fn preview(file: &MusFile, line: &InputLine, motives: &Motives, pass: usize, caret: usize) -> Preview {
    let options = options(file, line);
    let typed: [String; 5] = line.passes.clone();
    let as_typed = run_line(file, &options, &typed, motives);
    let unfinished = as_typed.as_ref().err().is_some_and(|err| {
        let text = &typed[err.pass.number() - 1];
        let at = (0..=err.span.start.min(text.len())).rev().find(|&b| text.is_char_boundary(b)).unwrap_or(0);
        let ends_item = text[at..].trim_start().starts_with([';', '/', ',']) || text[at..].trim().is_empty();
        let short = matches!(&err.kind, ErrorKind::Unexpected(what) if what == "end of entry") || err.kind == ErrorKind::ExpectedNumber;
        short && ends_item
    });
    let check = as_typed.map(|run| run.items.len()).map_err(|err| pass_error(&line.texts(), &err));
    let rhythms = count_rhythms(&passes(&typed), &options, motives).ok();
    let mut texts = typed.clone();
    if pass <= 2 {
        if let Some(RhythmCount { given: Some(given), needed }) = rhythms {
            if given < needed {
                texts[1] = padded(&texts[1], given, needed);
            }
        }
    }
    let mut partial = false;
    let run = loop {
        match run_line(file, &options, &texts, motives) {
            Ok(run) => break run,
            Err(err) => {
                partial = true;
                if !cut_back(&mut texts[err.pass.number() - 1], err.span.start) {
                    let empty = [";", ";", ";", ";", ";"].map(String::from);
                    break run_line(file, &options, &empty, motives).unwrap_or(Run { items: Vec::new(), outline: Vec::new() });
                }
            }
        }
    };

    let typed_text = typed.get(pass.wrapping_sub(1)).map_or("", String::as_str);
    let caret = byte_offset(typed_text, caret);
    // A caret after the text stands on an item still to be typed.
    let past_end = caret > typed_text.split(';').next().unwrap_or("").len();
    let notes = run.outline.iter().filter_map(|o| o.note).count();
    let elements: Vec<usize> = match pass {
        _ if past_end && pass != 2 => Vec::new(),
        1 => elements_at_pass_one(file, &options, &typed[0], caret, motives).collect(),
        2 => {
            let slots = slots_at_pass_two(&options, &texts[0], &typed[1], caret, past_end, motives);
            (0..run.outline.len()).filter(|&e| run.outline[e].slot.is_some_and(|s| slots.contains(&s))).collect()
        }
        3..=5 => {
            let item = &typed_text[item_around(typed_text, caret)];
            let wanted = if pass == 3 { notes_at_pass_three(item) } else { notes_at_connect(item, pass, notes) };
            (0..run.outline.len()).filter(|&e| run.outline[e].note.is_some_and(|n| wanted.contains(&n))).collect()
        }
        _ => Vec::new(),
    };
    let elements: Vec<&Outline> = elements.iter().filter_map(|&e| run.outline.get(e)).collect();

    let mut combined = file.clone();
    let first = combined.items.len();
    combined.items.extend(run.items.iter().cloned());
    let doc = score_render::Document::new(&combined);
    let mut list = DisplayList::default();
    for index in first..combined.items.len() {
        if let Some(item) = doc.item(ItemId(index as u32)) {
            render_item(&doc, item, &mut list);
        }
    }

    let focus = elements.iter().flat_map(|o| o.items.clone()).map(|i| first + i).collect();
    let described = elements
        .iter()
        .map(|o| describe(&run.items[o.items.clone()], clef_at(&run, o.items.start, options.clef)))
        .collect();
    let notes_text = &typed[0];
    let erased = erased_items(notes_text)
        .into_iter()
        .map(|span| utf16_offset(notes_text, span.start)..utf16_offset(notes_text, span.end))
        .collect();
    Preview { list, first, items: run.items, check, unfinished, partial, notes, rhythms, focus, described, erased }
}

/// [`Score::preview_input`]'s result.
#[wasm_bindgen]
pub struct InputPreview(Preview);

#[wasm_bindgen]
impl InputPreview {
    /// The new items, drawn as they would stand in the score.
    pub fn list(&self) -> EncodedList {
        EncodedList::from(&self.0.list)
    }

    /// Index of the first new item: its elements' sources start here.
    #[wasm_bindgen(getter)]
    pub fn first(&self) -> u32 {
        self.0.first as u32
    }

    /// Items in the preview, a staff item IN would add included.
    #[wasm_bindgen(getter)]
    pub fn count(&self) -> usize {
        self.0.items.len()
    }

    /// Items the line as typed adds (0 when it fails).
    #[wasm_bindgen(getter)]
    pub fn items(&self) -> usize {
        *self.0.check.as_ref().unwrap_or(&0)
    }

    /// The failing pass of the line as typed (1-5), 0 when it parses.
    #[wasm_bindgen(getter)]
    pub fn pass(&self) -> usize {
        self.0.check.as_ref().err().map_or(0, |e| e.pass)
    }

    /// The error's range in that pass, in UTF-16 code units.
    #[wasm_bindgen(getter)]
    pub fn start(&self) -> usize {
        self.0.check.as_ref().err().map_or(0, |e| e.start)
    }

    #[wasm_bindgen(getter)]
    pub fn end(&self) -> usize {
        self.0.check.as_ref().err().map_or(0, |e| e.end)
    }

    #[wasm_bindgen(getter)]
    pub fn message(&self) -> String {
        self.0.check.as_ref().err().map(|e| e.message.clone()).unwrap_or_default()
    }

    /// The error is an item cut short, which more typing could finish.
    #[wasm_bindgen(getter)]
    pub fn unfinished(&self) -> bool {
        self.0.unfinished
    }

    /// The preview shows less than was typed: a pass was cut back to before its error.
    #[wasm_bindgen(getter)]
    pub fn partial(&self) -> bool {
        self.0.partial
    }

    /// Notes and chords, as passes 3-5 number them.
    #[wasm_bindgen(getter)]
    pub fn notes(&self) -> usize {
        self.0.notes
    }

    /// Notes, chords and rests that take a value in pass 2 (-1 when the passes do not parse).
    #[wasm_bindgen(getter)]
    pub fn needed(&self) -> i32 {
        self.0.rhythms.map_or(-1, |r| r.needed as i32)
    }

    /// Values pass 2 gives: -1 when one value sets them all, -2 when the passes do not parse.
    #[wasm_bindgen(getter)]
    pub fn given(&self) -> i32 {
        match self.0.rhythms {
            Some(RhythmCount { given: Some(given), .. }) => given as i32,
            Some(RhythmCount { given: None, .. }) => -1,
            None => -2,
        }
    }

    /// Item indices of the elements at the caret (`Uint32Array`).
    #[wasm_bindgen(getter)]
    pub fn focus(&self) -> Vec<u32> {
        self.0.focus.iter().map(|&i| i as u32).collect()
    }

    /// Those elements in words.
    #[wasm_bindgen(getter)]
    pub fn described(&self) -> Vec<String> {
        self.0.described.clone()
    }

    /// Items of pass 1 the reader erases, as start and end pairs in UTF-16 units (`Uint32Array`).
    #[wasm_bindgen(getter)]
    pub fn erased(&self) -> Vec<u32> {
        self.0.erased.iter().flat_map(|r| [r.start as u32, r.end as u32]).collect()
    }
}

#[wasm_bindgen]
impl Score {
    /// Shows a line of input while it is typed, without changing the score: the
    /// items it would add, the elements at the caret (in `pass` 1-5, at UTF-16
    /// offset `caret` of that pass's text) and how far the passes have got.
    #[wasm_bindgen(js_name = previewInput)]
    pub fn preview_input(&self, line: &InputLine, pass: usize, caret: usize) -> InputPreview {
        InputPreview(preview(self.0.file(), line, self.0.motives(), pass, caret))
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use score_format::Word;

    fn file(items: &[&[f32]]) -> MusFile {
        let empty = [&5u16.to_le_bytes()[..], &[0u8; 4 * 3], &4.0f32.to_le_bytes(), &(-9999.0f32).to_le_bytes()].concat();
        let mut file = MusFile::parse(&empty).unwrap();
        file.items = items.iter().map(|params| Item::new(params.iter().copied().map(Word::from).collect())).collect();
        file
    }

    fn line(passes: [&str; 5]) -> InputLine {
        InputLine::new(passes.map(str::to_owned).to_vec(), 1, 2.0, 200.0).unwrap_or_else(|_| panic!("five passes"))
    }

    fn show(passes: [&str; 5], pass: usize, caret: usize) -> Preview {
        preview(&file(&[&[8.0, 1.0]]), &line(passes), &Motives::new(), pass, caret)
    }

    #[test]
    fn notes_without_a_rhythm_show_as_quarters_while_pass_two_is_open() {
        let typed = show(["G/A;", ";", ";", ";", ";"], 1, 1);
        assert!(typed.items.iter().all(|item| item.param(7) == 1.0));
        assert_eq!(typed.rhythms, Some(RhythmCount { given: Some(0), needed: 2 }));
        let later = show(["G/A;", ";", ";", ";", ";"], 3, 0);
        assert!(later.items.iter().all(|item| item.param(7) == 65.0), "finished as typed: grace notes");
        let some = show(["G/A/B;", "8/8;", ";", ";", ";"], 2, 3);
        let values: Vec<f32> = some.items.iter().map(|item| item.param(7)).collect();
        assert_eq!(values, [0.5, 0.5, 1.0]);
    }

    #[test]
    fn the_caret_finds_its_note_in_every_pass() {
        let passes = ["C4/D/R/E:G;", "4/8/8/4;", "S 3;", "2 4;", "1 2;"];
        let at = |pass, caret| show(passes, pass, caret);
        assert_eq!(at(1, 4).focus, [2], "the score's staff item is item 0");
        assert_eq!(at(1, 4).described, ["D4, eighth"]);
        assert_eq!(at(1, 9).focus, [4, 5]);
        assert_eq!(at(1, 9).described, ["E4 G4, quarter"]);
        assert_eq!(at(2, 5).focus, [3]);
        assert_eq!(at(2, 5).described, ["eighth rest"]);
        assert_eq!(at(3, 3).focus, [4, 5]);
        assert_eq!(at(4, 2).focus, [2, 4, 5]);
        assert_eq!(at(5, 0).focus, [1, 2]);
    }

    #[test]
    fn a_single_value_marks_every_note() {
        let one = show(["C4/D/E;", "8;", ";", ";", ";"], 2, 1);
        assert_eq!(one.focus, [1, 2, 3]);
        let first_of_two = show(["C4/D/E;", "8/4;", ";", ";", ";"], 2, 1);
        assert_eq!(first_of_two.focus, [1]);
        let next = show(["C4/D/E;", "8/;", ";", ";", ";"], 2, 2);
        assert_eq!(next.focus, [2]);
    }

    #[test]
    fn a_failing_item_is_left_out_of_the_preview() {
        let chord = show(["C4/E:;", ";", ";", ";", ";"], 1, 5);
        assert!(chord.partial);
        assert_eq!(chord.check.as_ref().unwrap_err().pass, 1);
        assert_eq!(chord.items.len(), 2);
        assert!(chord.unfinished);
        let key = show(["C4/K2;", ";", ";", ";", ";"], 1, 5);
        assert_eq!(key.items.len(), 1);
        assert!(key.unfinished);
        let rhythm = show(["C4/D;", "4/Y;", ";", ";", ";"], 2, 3);
        assert_eq!(rhythm.items.len(), 2);
        assert_eq!(rhythm.check.as_ref().unwrap_err().pass, 2);
        assert!(!rhythm.unfinished, "Y is a mistake, not an unfinished value");
    }

    #[test]
    fn items_the_reader_erases_are_reported() {
        let shown = show(["C4/Y/D/E;", ";", ";", ";", ";"], 1, 0);
        assert_eq!(shown.erased.len(), 1);
        let range = shown.erased[0].clone();
        assert_eq!(&"C4/Y/D/E;"[range], "Y/");
        assert_eq!(shown.items.len(), 3);
    }

    #[test]
    fn a_missing_staff_comes_first() {
        let new = preview(&file(&[]), &line(["C4;", "4;", ";", ";", ";"]), &Motives::new(), 1, 1);
        assert_eq!(new.items[0].code(), 8);
        assert_eq!(new.focus, [1]);
        assert_eq!(new.described, ["C4, quarter"]);
        assert_eq!(new.first, 0);
        assert!(!new.list.shapes.is_empty());
    }

    #[test]
    fn descriptions_follow_the_clef() {
        let bass = file(&[&[8.0, 1.0], &[3.0, 1.0, 2.0, 0.0, 1.0]]);
        let shown = preview(&bass, &line(["C4/FS2/TR/C4;", "4;", ";", ";", ";"]), &Motives::new(), 1, 4);
        assert_eq!(shown.described, ["F♯2, quarter"]);
        let after = preview(&bass, &line(["C4/FS2/TR/C4;", "4;", ";", ";", ";"]), &Motives::new(), 1, 12);
        assert_eq!(after.described, ["C4, quarter"]);
    }

    #[test]
    fn mark_and_connect_items_name_their_notes() {
        assert_eq!(notes_at_pass_three("S 1:3 5"), [1, 2, 3, 5]);
        assert_eq!(notes_at_pass_three("-A 2.6"), [3]);
        assert_eq!(notes_at_pass_three("F1 4"), [4]);
        assert_eq!(notes_at_pass_three("C 2 4"), [2, 3, 4]);
        assert_eq!(notes_at_pass_three("C- 2 4"), [2, 3, 4]);
        assert_eq!(notes_at_connect("-1 304", 4, 9), [1, 2, 3, 4]);
        assert_eq!(notes_at_connect("4", 4, 9), [4, 5]);
        assert_eq!(notes_at_connect("X3 1 7", 4, 9), [1, 2, 3, 7, 8, 9]);
        assert_eq!(notes_at_connect("2B", 4, 9), Vec::<usize>::new());
        assert_eq!(notes_at_connect("6 99", 5, 9), [6, 7, 8, 9]);
    }

    #[test]
    fn cutting_back_keeps_what_parsed() {
        let mut text = "C4/E:;".to_owned();
        assert!(cut_back(&mut text, 5));
        assert_eq!(text, "C4/E;");
        let mut text = "C4/YY/D;".to_owned();
        assert!(cut_back(&mut text, 3));
        assert_eq!(text, "C4;");
        let mut text = "C4;".to_owned();
        assert!(cut_back(&mut text, 0));
        assert_eq!(text, ";");
        assert!(!cut_back(&mut text, 0));
    }

    #[test]
    fn durations_in_words() {
        assert_eq!(duration(1.5), "dotted quarter");
        assert_eq!(duration(1.0 / 3.0), "triplet eighth");
        assert_eq!(duration(65.0), "grace note");
        assert_eq!(duration(0.2), "quintuplet 16th");
    }
}
