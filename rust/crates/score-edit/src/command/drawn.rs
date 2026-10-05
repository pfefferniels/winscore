//! What WinScore's redraw after every command writes back into the items:
//! the measured length of text items (P13) and, while no item is in edit
//! mode, the centre of centred whole-bar rests (P9, draw_rest 0x519C38).

use score_format::Item;
use score_render::codes::rest;
use score_render::Document as RenderDocument;

use crate::command::Run;
use crate::document::ItemId;
use crate::params::Draft;

const REST: i32 = 2;
const CENTRE: usize = 9;
/// P9 asking the redraw to centre a rest (CW).
const CENTRED: f32 = -1.0;
/// Rests from the whole-bar rest down in P5: whole, multi-bar, repeat sign, bar rest.
const WHOLE_BAR: f32 = -2.0;

/// Which staves `CW n` / `CWA` (typed with no item in edit mode) centre the
/// whole-bar rests of; `None` for any other word.
pub fn centred_staves(word: &str, args: &[f32]) -> Option<Option<f32>> {
    match word {
        "CWA" => Some(None),
        "CW" => args.first().map(|&staff| Some(staff)),
        _ => word.strip_prefix("CW")?.parse::<f32>().ok().map(Some),
    }
}

impl Run<'_, '_> {
    /// CW n, CWA: every whole-bar rest (P5 <= -2) of staff n, or of all
    /// staves, gets P9 = -1, which the redraw turns into its centre.
    pub fn centre_whole_rests(&mut self, staff: Option<f32>) {
        let marked: Vec<(ItemId, Item)> = self
            .tx
            .doc()
            .entries()
            .map(|(id, item)| (id, Draft::of(item)))
            .filter(|(_, d)| d.code() == REST && d.get(5) <= WHOLE_BAR && staff.is_none_or(|s| d.get(2) == s))
            .filter(|(_, d)| d.get(CENTRE) != CENTRED)
            .map(|(id, mut d)| {
                d.set(CENTRE, CENTRED);
                (id, d.to_item())
            })
            .collect();
        marked.into_iter().for_each(|(id, item)| {
            self.tx.replace(id, item);
        });
    }

    /// Brings the items up to date with what drawing them would store.
    pub fn refresh_drawn(&mut self) {
        self.refresh_text_lengths();
        if !self.session.in_edit_mode() {
            self.centre_rests();
        }
    }

    fn centre_rests(&mut self) {
        let doc = self.tx.doc();
        let render = RenderDocument::new(doc.file());
        let centred: Vec<(ItemId, Item)> = render
            .items()
            .filter(|item| item.code() == REST)
            .filter_map(|item| {
                let centre = rest::centre(&render, item)?;
                let id = doc.id_at(item.id.0 as usize)?;
                let mut draft = Draft::of(item.item);
                draft.set(CENTRE, centre);
                Some((id, draft.to_item()))
            })
            .filter(|(id, item)| doc.item(*id) != Some(item))
            .collect();
        centred.into_iter().for_each(|(id, item)| {
            self.tx.replace(id, item);
        });
    }
}
