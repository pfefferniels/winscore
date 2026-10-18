//! Text commands: quick text entry, new characters, and the words that
//! size, centre and justify text items (WinScore help, code 16).

use score_format::Item;
use score_render::Document as RenderDocument;

use crate::command::parse;
use crate::command::Run;
use crate::document::ItemId;
use crate::error::EditError;
use crate::params::{Draft, TEXT_CODE};
use crate::text::{self, CENTRED, DIVIDED_GAP, LENGTH};

/// `PT n` makes the text n points high: P6 = n / (13.56 × staff size).
const POINTS_PER_SIZE: f32 = 13.56;
/// CT alone centres on this position until CT is given one.
const DEFAULT_CENTRE: f32 = 100.0;
/// JR alone justifies to this position until JR is given one.
const DEFAULT_RIGHT: f32 = 200.0;
/// CTN and CTX centre text this far right of the note's P3 (half a note head).
const NOTE_CENTRE: f32 = 1.6;
const SHIFT: usize = 11;
const SPACE: usize = 10;
/// Quick entry fills P2–P11 from the numbers after the text.
const LAST_ENTERED_PARAM: usize = 11;

impl Run<'_, '_> {
    /// Quick text entry: `"text" p2 p3 …`. Each part between `/` becomes an
    /// item, the next starting 2 units after the last; P3 + 1000 centres every
    /// part on P3. P2 defaults to 1, P3 to 100, P5 and P6 to 1.
    pub fn enter_text(&mut self, text: &[u8], rest: &str) -> Result<(), EditError> {
        let numbers: Vec<f32> = parse::tokens(rest)
            .iter()
            .map(|t| t.number().ok_or_else(|| EditError::UnknownCommand(format!("{t:?}"))))
            .collect::<Result<_, _>>()?;
        let parts = text::divided(text, self.session.text_font);
        let Some(last) = parts.last() else { return Ok(()) };
        self.session.text_font = text::last_font_code(last).unwrap_or(self.session.text_font);
        let template = entered_params(&numbers);
        let typed_p3 = template.get(3);
        let mut next_p3 = typed_p3;
        let ids: Vec<ItemId> = parts
            .iter()
            .map(|part| {
                let mut draft = template.clone();
                text::set_characters(&mut draft, part);
                let id = self.tx.append(draft.to_item());
                let index = self.tx.doc().len() - 1;
                let length = text::measured_length(self.tx.doc().file(), index);
                draft.set(LENGTH, length);
                let p3 = if typed_p3 >= CENTRED { typed_p3 - CENTRED - length / 2.0 } else { next_p3 };
                draft.set(3, p3);
                next_p3 = p3 + length + DIVIDED_GAP;
                self.tx.replace(id, draft.to_item());
                id
            })
            .collect();
        self.session.select(self.tx.doc(), &ids[ids.len() - 1..]);
        Ok(())
    }

    /// New characters for a text item; without a font code of their own they
    /// keep the item's font. P12 and P13 follow.
    pub fn set_text(&mut self, id: ItemId, characters: &[u8]) -> Result<(), EditError> {
        let item = self.tx.doc().item(id).ok_or(EditError::NoSuchId(id))?;
        if item.code() != TEXT_CODE {
            return Err(EditError::NotForCode { command: "set text".into(), code: item.code() });
        }
        let font = text::font_code(item.text()).unwrap_or(self.session.text_font);
        let mut draft = Draft::of(item);
        text::set_characters(&mut draft, &text::with_font_code(characters, font));
        self.tx.replace(id, draft.to_item());
        Ok(())
    }

    /// Gives every text item the length the engine measures for it (P13);
    /// the engine does so each time it draws the page, so a change to one
    /// item can change the length of a later text that inherits its font.
    pub fn refresh_text_lengths(&mut self) {
        let doc = self.tx.doc();
        let stale: Vec<(ItemId, Item)> = text::measured_lengths(doc.file())
            .into_iter()
            .filter_map(|(index, length)| {
                let item = &doc.file().items[index];
                let id = doc.id_at(index).filter(|_| item.param(LENGTH) != length)?;
                Some((id, text::with_length(item, length)))
            })
            .collect();
        stale.into_iter().for_each(|(id, item)| {
            self.tx.replace(id, item);
        });
    }

    fn selected_texts(&self) -> Vec<(ItemId, usize, Draft)> {
        let doc = self.tx.doc();
        self.session
            .selection()
            .iter()
            .filter_map(|&id| Some((id, doc.index_of(id)?, Draft::of(doc.item(id)?))))
            .filter(|(_, _, draft)| draft.code() == TEXT_CODE)
            .collect()
    }

    fn rewrite_texts(&mut self, word: &str, mut change: impl FnMut(&mut Self, usize, &mut Draft)) -> Result<(), EditError> {
        let texts = self.selected_texts();
        if texts.is_empty() {
            return Err(EditError::NotForCode { command: word.into(), code: self.first_selected_code() });
        }
        texts.into_iter().for_each(|(id, index, mut draft)| {
            change(self, index, &mut draft);
            self.tx.replace(id, draft.to_item());
        });
        Ok(())
    }

    /// PT n: text n points high on its staff (P6, with P7 = 0).
    pub fn point_size(&mut self, points: Option<f32>) -> Result<(), EditError> {
        let Some(points) = points else { return Ok(()) };
        let staves = RenderDocument::new(self.tx.doc().file()).staves;
        self.rewrite_texts("PT", |_, _, draft| {
            let size = staves.get(draft.get(2) as i32).size as f32;
            draft.set(6, points / (POINTS_PER_SIZE * size));
            draft.set(7, 0.0);
        })
    }

    /// CT x: the text centred on x (CT alone: on the position given last, 100 at first).
    pub fn centre_text(&mut self, at: Option<f32>) -> Result<(), EditError> {
        let at = at.or(self.session.centre_at).unwrap_or(DEFAULT_CENTRE);
        self.session.centre_at = Some(at);
        self.rewrite_texts("CT", |_, _, draft| draft.set(3, at - draft.get(LENGTH) / 2.0))
    }

    /// JR x: the text's right end at x, its last glyph's bearing left out (JR
    /// alone: the position given last, 200 at first).
    pub fn justify_right(&mut self, at: Option<f32>) -> Result<(), EditError> {
        let at = at.or(self.session.right_at).unwrap_or(DEFAULT_RIGHT);
        self.session.right_at = Some(at);
        self.rewrite_texts("JR", |run, index, draft| {
            if let Some(bearing) = text::right_bearing(run.tx.doc().file(), index) {
                draft.set(3, at - (draft.get(LENGTH) - bearing));
            }
        })
    }

    /// J left right: the text from `left` to `right`, its spaces widened (P10)
    /// to fill the line; J alone reuses the positions given last.
    pub fn justify(&mut self, left: Option<f32>, right: Option<f32>) -> Result<(), EditError> {
        let Some((left, right)) = left.zip(right).or(self.session.justify_between) else {
            return Err(EditError::BadArgument("J".into()));
        };
        self.session.justify_between = Some((left, right));
        self.rewrite_texts("J", |run, index, draft| {
            let spaces = draft.text().iter().filter(|&&b| b == b' ').count();
            let Some(bearing) = text::right_bearing(run.tx.doc().file(), index).filter(|_| spaces > 0) else { return };
            let factor = |n: usize| f64::from(if draft.get(n) == 0.0 { 1.0 } else { draft.get(n) });
            let missing = f64::from(right) + f64::from(bearing) - f64::from(left) - f64::from(draft.get(LENGTH));
            let widened = f64::from(draft.get(SPACE)) + missing / spaces as f64 / (factor(5) * factor(6));
            draft.set(SPACE, widened as f32);
            draft.set(3, left);
        })
    }

    /// CTN, CTX [staff]: the text centred on the nearest note or rest, through
    /// P3 = the note's P3 and the shift P11; CTX leaves out punctuation at either end.
    pub fn centre_text_on_note(&mut self, word: &str, staff: Option<f32>, skip_punctuation: bool) -> Result<(), EditError> {
        self.rewrite_texts(word, |run, index, draft| {
            let on = staff.unwrap_or(draft.get(2));
            let Some(note) = run.nearest_note(on, draft.get(3)) else { return };
            let file = run.tx.doc().file();
            let (lead, through_core) = if skip_punctuation {
                let (before, core) = text::core(draft.text());
                (text::length_with(file, index, &before), text::length_with(file, index, &core))
            } else {
                (0.0, draft.get(LENGTH))
            };
            draft.set(3, note);
            draft.set(SHIFT, NOTE_CENTRE - (lead + through_core) / 2.0);
        })
    }
}

/// The parameters quick entry gives a text item from the numbers typed after it.
fn entered_params(numbers: &[f32]) -> Draft {
    let mut draft = text::new_item(1.0, b"");
    numbers.iter().take(LAST_ENTERED_PARAM - 1).enumerate().filter(|(_, &v)| v != 0.0).for_each(|(i, &v)| {
        draft.set(i + 2, v);
    });
    draft
}

/// Whether a line is quick text entry; the error is for an unclosed quote.
pub fn quick_entry(line: &str) -> Option<Result<(Vec<u8>, &str), EditError>> {
    parse::quoted(line).map(|found| {
        found.map(|(text, rest)| (text::encode(text), rest)).ok_or_else(|| EditError::UnknownCommand("\"".into()))
    })
}
