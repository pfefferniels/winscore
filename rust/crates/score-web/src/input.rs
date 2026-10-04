//! The five-pass music input (WinScore's `IN` dialog) through `score-input`.

use score_format::{Item, MusFile};
use score_input::notes::Clef;
use score_input::{run_with_motives, InputError, Motives, Options, Passes, StaffArgs};
use wasm_bindgen::prelude::*;

use crate::Score;

const CLEF_CODE: i32 = 3;
const STAFF_CODE: i32 = 8;

/// A failed pass, with the error's range in UTF-16 code units of that pass's
/// text, as browser text fields count.
#[derive(Debug, Clone, PartialEq, Eq)]
pub struct PassError {
    /// 1 = notes … 5 = slurs.
    pub pass: usize,
    pub start: usize,
    pub end: usize,
    pub message: String,
}

fn utf16_offset(text: &str, byte: usize) -> usize {
    let byte = byte.min(text.len());
    let boundary = (0..=byte).rev().find(|&b| text.is_char_boundary(b)).unwrap_or(0);
    text[..boundary].encode_utf16().count()
}

fn pass_error(texts: &[&str; 5], err: &InputError) -> PassError {
    let text = texts[err.pass.number() - 1];
    PassError {
        pass: err.pass.number(),
        start: utf16_offset(text, err.span.start),
        end: utf16_offset(text, err.span.end),
        message: err.to_string(),
    }
}

fn on_staff(item: &Item, code: i32, staff: u8) -> bool {
    item.code() == code && item.param(2) == f32::from(staff)
}

/// What the engine takes from the score for a line of input (input-lang's
/// findings): the staff's size (P5, 0 = 1), its right end (P6) clipping the
/// range, and the clef of the last clef item on the staff.
fn options(file: &MusFile, line: &InputLine) -> Options {
    let staff = file.items.iter().find(|item| on_staff(item, STAFF_CODE, line.staff));
    let size = staff.map(|s| s.param(5)).filter(|&p5| p5 != 0.0).unwrap_or(1.0);
    let right_end = staff.map(|s| s.param(6)).filter(|&p6| p6 > 0.0);
    let clef = file
        .items
        .iter()
        .rev()
        .find(|item| on_staff(item, CLEF_CODE, line.staff))
        .map_or(Clef::Treble, |clef| Clef::from_code(clef.param(5) as i32));
    Options {
        staff: line.staff,
        size,
        begin: line.begin,
        end: right_end.map_or(line.end, |right| line.end.min(right)),
        clef,
    }
}

/// The items one line of input adds to `file`: the staff item `IN n` creates
/// when staff n has none yet, then the line itself. Motives defined in the
/// line are added to `motives`.
pub fn line_items(file: &MusFile, line: &InputLine, motives: &mut Motives) -> Result<Vec<Item>, PassError> {
    let texts = line.texts();
    let [notes, rhythms, marks, beams, slurs] = texts;
    let passes = Passes { notes, rhythms, marks, beams, slurs };
    let items = run_with_motives(&passes, &options(file, line), motives).map_err(|err| pass_error(&texts, &err))?;
    let has_staff = file.items.iter().any(|item| on_staff(item, STAFF_CODE, line.staff));
    let staff = (!has_staff).then(|| StaffArgs::on(line.staff).staff_item());
    Ok(staff.into_iter().chain(items).collect())
}

/// One line of WinScore's five-pass input: the texts of the passes (notes,
/// rhythms, marks, beams, slurs, each ending with `;`) and where it goes.
#[wasm_bindgen]
pub struct InputLine {
    passes: [String; 5],
    staff: u8,
    begin: f32,
    end: f32,
}

#[wasm_bindgen]
impl InputLine {
    /// `passes` must hold five strings.
    #[wasm_bindgen(constructor)]
    pub fn new(passes: Vec<String>, staff: u8, begin: f32, end: f32) -> Result<InputLine, JsError> {
        let passes: [String; 5] = passes.try_into().map_err(|_| JsError::new("five input passes expected"))?;
        Ok(InputLine { passes, staff, begin, end })
    }
}

impl InputLine {
    pub fn texts(&self) -> [&str; 5] {
        self.passes.each_ref().map(String::as_str)
    }
}

/// The outcome of [`Score::check_input`]: the number of items the line
/// would add, or the failing pass with the error's UTF-16 range in its text.
#[wasm_bindgen(getter_with_clone)]
pub struct InputCheck {
    pub items: usize,
    /// 1 = notes … 5 = slurs; 0 = no error.
    pub pass: usize,
    pub start: usize,
    pub end: usize,
    pub message: String,
}

impl From<Result<usize, PassError>> for InputCheck {
    fn from(result: Result<usize, PassError>) -> Self {
        match result {
            Ok(items) => InputCheck { items, pass: 0, start: 0, end: 0, message: String::new() },
            Err(err) => InputCheck { items: 0, pass: err.pass, start: err.start, end: err.end, message: err.message },
        }
    }
}

#[wasm_bindgen]
impl Score {
    /// The highest staff number with a staff item; WinScore's Input box
    /// proposes the staff above it.
    #[wasm_bindgen(js_name = highestStaff)]
    pub fn highest_staff(&self) -> Option<i32> {
        score_render::Document::new(self.0.file()).staves.highest()
    }

    /// Checks one line of five-pass input against this score without
    /// changing it; see [`InputCheck`].
    #[wasm_bindgen(js_name = checkInput)]
    pub fn check_input(&self, line: &InputLine) -> InputCheck {
        let mut motives = self.0.motives().clone();
        InputCheck::from(line_items(self.0.file(), line, &mut motives).map(|items| items.len()))
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

    fn line(notes: &str, rhythms: &str) -> InputLine {
        let passes = [notes, rhythms, ";", ";", ";"].map(str::to_owned).to_vec();
        InputLine::new(passes, 1, 2.0, 200.0).unwrap_or_else(|_| panic!("five passes"))
    }

    fn notes(items: &[Item]) -> Vec<&Item> {
        items.iter().filter(|item| item.code() == 1).collect()
    }

    #[test]
    fn adds_a_staff_when_missing() {
        let items = line_items(&file(&[]), &line("C4/D/E/F;", "4/4/4/4;"), &mut Motives::new()).unwrap();
        assert_eq!(items[0].code(), 8);
        assert_eq!(items[0].param(2), 1.0);
        assert_eq!(items.len(), 5);
    }

    #[test]
    fn pitches_follow_the_clef_in_force() {
        let treble = file(&[&[8.0, 1.0]]);
        let bass = file(&[&[8.0, 1.0], &[3.0, 1.0, 2.0, 0.0, 1.0]]);
        let level = |f: &MusFile| line_items(f, &line("C4;", "4;"), &mut Motives::new()).unwrap()[0].param(4);
        assert_ne!(level(&treble), level(&bass));
    }

    #[test]
    fn the_staff_end_clips_the_range() {
        let short = file(&[&[8.0, 1.0, 0.0, 0.0, 0.0, 100.0]]);
        let items = line_items(&short, &line("C4/D/E/F;", "4/4/4/4;"), &mut Motives::new()).unwrap();
        assert!(notes(&items).iter().all(|note| note.param(3) <= 100.0));
    }

    #[test]
    fn motives_outlive_a_line() {
        let score = file(&[&[8.0, 1.0]]);
        let mut motives = Motives::new();
        line_items(&score, &line("C4/A[D/E];", "4/4/4;"), &mut motives).unwrap();
        let recalled = line_items(&score, &line("@A;", "4/4;"), &mut motives).unwrap();
        assert_eq!(notes(&recalled).len(), 2);
        assert!(line_items(&score, &line("@A;", "4/4;"), &mut Motives::new()).is_err());
    }

    #[test]
    fn reports_the_failing_pass_in_utf16() {
        let err = line_items(&file(&[]), &line("C4/D;", "4/4/4;"), &mut Motives::new()).unwrap_err();
        assert_eq!(err.pass, 2);
        assert!(err.message.contains("rhythm"), "{}", err.message);
        assert_eq!(utf16_offset("é/x", 3), 2);
    }
}
