//! Re-rendering only some items of a page, for previews while dragging.
//!
//! A full render draws the items in file order, so each item's shapes and
//! text runs form one contiguous stretch of the display list. Replacing the
//! stretches of the moved items gives the page as a full render would, except
//! that the engine's pen state carried from one item to the next is not
//! replayed. That only matters where an item starts with an object start
//! right after another start, so the preview may differ in rare cases; the
//! full render after the drag is exact.

use std::ops::Range;

use score_format::MusFile;
use score_render::{render_item, DisplayList, ItemId};

/// Where one item's elements lie in a display list.
#[derive(Debug, Clone, PartialEq, Eq, Default)]
struct Stretch {
    shapes: Range<usize>,
    texts: Range<usize>,
}

/// For each item index below `items`, the range of `sources` it occupies;
/// an item without elements gets an empty range where its elements would go.
/// An element without a source goes with the element before it.
fn ranges(sources: impl Iterator<Item = Option<ItemId>>, items: usize) -> Vec<Range<usize>> {
    let owners: Vec<usize> = sources
        .scan(0, |last, source| {
            *last = source.map_or(*last, |id| id.0 as usize);
            Some(*last)
        })
        .collect();
    (0..items).map(|i| owners.partition_point(|&o| o < i)..owners.partition_point(|&o| o <= i)).collect()
}

fn stretches(list: &DisplayList, items: usize) -> Vec<Stretch> {
    let shapes = ranges(list.shapes.iter().map(|s| s.source), items);
    let texts = ranges(list.texts.iter().map(|t| t.source), items);
    shapes.into_iter().zip(texts).map(|(shapes, texts)| Stretch { shapes, texts }).collect()
}

/// Draws the items at `indices` of `file` again in `page`, a full rendering
/// of an earlier state of `file` with the same items.
pub fn rerender(page: &mut DisplayList, file: &MusFile, indices: &[usize]) {
    let doc = crate::drawn(file);
    let spans = stretches(page, file.items.len());
    let mut descending: Vec<usize> = indices.iter().copied().filter(|&i| i < spans.len()).collect();
    descending.sort_unstable_by(|a, b| b.cmp(a));
    descending.dedup();
    for index in descending {
        let Some(item) = doc.item(ItemId(index as u32)) else { continue };
        let mut fresh = DisplayList::default();
        render_item(&doc, item, &mut fresh);
        let span = &spans[index];
        page.shapes.splice(span.shapes.clone(), fresh.shapes);
        page.texts.splice(span.texts.clone(), fresh.texts);
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use score_format::Word;
    use score_render::render;
    use std::path::PathBuf;

    fn mozart() -> MusFile {
        let path = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../../WINSCORE 5.01/winscore/mozart.mus");
        MusFile::parse(&std::fs::read(path).unwrap()).unwrap()
    }

    #[test]
    fn ranges_cover_items_in_order() {
        let sources = [Some(ItemId(0)), Some(ItemId(0)), Some(ItemId(2)), None, Some(ItemId(3))];
        assert_eq!(ranges(sources.into_iter(), 4), vec![0..2, 2..2, 2..4, 4..5]);
    }

    #[test]
    fn rerendering_moved_notes_matches_a_full_render() {
        let mut file = mozart();
        let mut page = render(&crate::drawn(&file));
        let moved: Vec<usize> = file.items.iter().enumerate().filter(|(_, item)| item.code() == 1).map(|(i, _)| i).take(3).collect();
        for &index in &moved {
            let mut params = file.items[index].params().to_vec();
            params[2] = Word::from_f32(params[2].as_f32() + 7.5);
            params[3] = Word::from_f32(params[3].as_f32() + 2.0);
            file.items[index] = score_format::Item::new(params);
        }
        rerender(&mut page, &file, &moved);
        assert_eq!(page, render(&crate::drawn(&file)));
    }
}
