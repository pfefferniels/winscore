//! What WinScore's redraw after every command writes back into the items:
//! the measured length of text items (P13) and the position of centred
//! whole-bar rests (P9, draw_rest 0x519C38). A rest in edit mode gets the
//! values draw_rest writes into the edit buffer (which leaving edit mode
//! stores); while no item is in edit mode, every centred rest gets its centre.

use score_format::Item;
use score_render::codes::rest;
use score_render::{Document as RenderDocument, ItemRef};

use crate::command::Run;
use crate::document::ItemId;
use crate::params::Draft;

const REST: i32 = 2;
const SPACING: usize = 6;
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
        if self.session.in_edit_mode() {
            self.place_rests(|render, item, draft| {
                let p9 = rest::edit_p9(render, item);
                let p6 = rest::edit_spacing(render, item);
                p9.iter().for_each(|&v| draft.set(CENTRE, v));
                p6.iter().for_each(|&v| draft.set(SPACING, v));
                p9.is_some() || p6.is_some()
            });
        } else {
            self.place_rests(|render, item, draft| {
                rest::centre(render, item).map(|v| draft.set(CENTRE, v)).is_some()
            });
        }
    }

    /// Rewrites the rests `place` changes: those in edit mode while there
    /// is one, otherwise all.
    fn place_rests(&mut self, place: impl Fn(&RenderDocument<'_>, ItemRef<'_>, &mut Draft) -> bool) {
        let doc = self.tx.doc();
        let render = RenderDocument::new(doc.file());
        let selected = self.session.selection();
        let placed: Vec<(ItemId, Item)> = render
            .items()
            .filter(|item| item.code() == REST)
            .filter_map(|item| {
                let id = doc.id_at(item.id.0 as usize)?;
                let mut draft = Draft::of(item.item);
                let in_reach = selected.is_empty() || selected.contains(&id);
                (in_reach && place(&render, item, &mut draft)).then(|| (id, draft.to_item()))
            })
            .filter(|(id, item)| doc.item(*id) != Some(item))
            .collect();
        placed.into_iter().for_each(|(id, item)| {
            self.tx.replace(id, item);
        });
    }
}
