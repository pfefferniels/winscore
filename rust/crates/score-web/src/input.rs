//! The five-pass music input (WinScore's `IN` dialog) through `score-input`.

use score_format::{Item, MusFile};
use score_input::{run, InputError, Options, Passes, StaffArgs};
use wasm_bindgen::prelude::*;

use crate::Score;

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

fn has_staff(file: &MusFile, staff: u8) -> bool {
    file.items.iter().any(|item| item.code() == STAFF_CODE && item.param(2) == f32::from(staff))
}

/// The items one line of input adds to `file`: the staff item `IN n` creates
/// when staff n has none yet, then the line itself.
pub fn line_items(file: &MusFile, texts: &[&str; 5], options: &Options) -> Result<Vec<Item>, PassError> {
    let [notes, rhythms, marks, beams, slurs] = *texts;
    let passes = Passes { notes, rhythms, marks, beams, slurs };
    let line = run(&passes, options).map_err(|err| pass_error(texts, &err))?;
    let staff = (!has_staff(file, options.staff)).then(|| StaffArgs::on(options.staff).staff_item());
    Ok(staff.into_iter().chain(line).collect())
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

    pub fn options(&self) -> Options {
        Options { staff: self.staff, begin: self.begin, end: self.end, ..Options::default() }
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
        InputCheck::from(line_items(self.0.file(), &line.texts(), &line.options()).map(|items| items.len()))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn empty_file() -> MusFile {
        let bytes = [&5u16.to_le_bytes()[..], &[0u8; 4 * 3], &4.0f32.to_le_bytes(), &(-9999.0f32).to_le_bytes()].concat();
        MusFile::parse(&bytes).unwrap()
    }

    #[test]
    fn adds_a_staff_when_missing() {
        let file = empty_file();
        let texts = ["C4/D/E/F;", "4/4/4/4;", ";", ";", ";"];
        let items = line_items(&file, &texts, &Options::default()).unwrap();
        assert_eq!(items[0].code(), 8);
        assert_eq!(items[0].param(2), 1.0);
        assert_eq!(items.len(), 5);
        assert_eq!(items[1].code(), 1);
    }

    #[test]
    fn reports_the_failing_pass_in_utf16() {
        let file = empty_file();
        let texts = ["C4/D;", "4/4/4;", ";", ";", ";"];
        let err = line_items(&file, &texts, &Options::default()).unwrap_err();
        assert_eq!(err.pass, 2);
        assert!(err.message.contains("rhythm"), "{}", err.message);
        assert_eq!(utf16_offset("é/x", 3), 2);
    }
}
