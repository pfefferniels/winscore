//! The five-pass music input (WinScore's `IN` dialog) through `score-input`.

use score_format::{Item, MusFile, Word};
use score_input::{run, InputError, Options, Passes};

const STAFF_CODE: f32 = 8.0;

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
    file.items.iter().any(|item| item.code() == STAFF_CODE as i32 && item.param(2) == f32::from(staff))
}

/// The items one line of input adds to `file`: a staff item first when the
/// target staff has none yet, then the line itself.
pub fn line_items(file: &MusFile, texts: &[&str; 5], options: &Options) -> Result<Vec<Item>, PassError> {
    let [notes, rhythms, marks, beams, slurs] = *texts;
    let passes = Passes { notes, rhythms, marks, beams, slurs };
    let line = run(&passes, options).map_err(|err| pass_error(texts, &err))?;
    // What the engine stores for a plain `IN n`: 8 n 0 0 0 0 (zeros mean defaults).
    // To be replaced by score_input::StaffArgs once that is on main.
    let staff_params = [STAFF_CODE, f32::from(options.staff), 0.0, 0.0, 0.0, 0.0];
    let staff = (!has_staff(file, options.staff)).then(|| Item::new(staff_params.map(Word::from).to_vec()));
    Ok(staff.into_iter().chain(line).collect())
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
        assert_eq!(items[0].params().len(), 6);
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
