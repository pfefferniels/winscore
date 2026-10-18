//! The editing API as the browser shell uses it: selection, actions, drags, undo.

use std::path::PathBuf;

use score_edit::clipboard::Placement;
use score_edit::group::{Region, TRANSPOSITION_PROMPT};
use score_edit::score_layout::{Command as LayoutCommand, Options, StaffRange};
use score_edit::transpose::Transposition;
use score_edit::{Change, EditError, Editor, ItemId};

fn sample(name: &str) -> Vec<u8> {
    let root = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../..");
    std::fs::read(root.join("WINSCORE 5.01/winscore").join(name)).expect("sample score")
}

fn editor_with(items: &[&[f32]]) -> Editor {
    let mut words: Vec<f32> = items.iter().flat_map(|i| std::iter::once(i.len() as f32).chain(i.iter().copied())).collect();
    words.extend([0.0, 0.0, 6.0, 0.0, 5.0, -9999.0]);
    let mut bytes = (words.len() as u16).to_le_bytes().to_vec();
    bytes.extend(words.iter().flat_map(|w| w.to_le_bytes()));
    Editor::open(&bytes).unwrap()
}

/// A staff and two quarter notes.
fn small() -> Editor {
    editor_with(&[&[8.0, 1.0, 0.0], &[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.0], &[1.0, 1.0, 120.0, 7.0, 10.0, 0.0, 1.0]])
}

#[test]
fn clicks_prefer_the_outline_hit_and_fall_back_to_the_nearest_reference_point() {
    let mut e = small();
    let (first, second) = (e.id_at(1).unwrap(), e.id_at(2).unwrap());
    assert_eq!(e.select_at(0.0, 0.0, Some(first), 300.0), Some(first));
    assert_eq!(e.selection(), [first]);
    assert_eq!(e.select_at(20000.0, 3473.0, None, 300.0), Some(second));
    assert_eq!(e.select_at(40000.0, 50000.0, None, 300.0), None);
    assert!(e.selection().is_empty());
}

#[test]
fn a_drag_keeps_its_grab_offset_and_snaps_notes() {
    let mut e = small();
    let note = e.id_at(1).unwrap();
    e.select(&[note]);
    e.drag_begin_at(5000.0, 5000.0);
    e.drag_to_point(5150.0, 5100.0, false);
    assert_eq!((p(&e, note, 3), p(&e, note, 4)), (101.0, 7.0));
    e.drag_end(true);
    assert_eq!(e.undo_label(), Some("Drag"));
}

#[test]
fn an_adjustment_sets_parameters_live_and_keeps_them_as_one_step() {
    let mut e = small();
    let note = e.id_at(1).unwrap();
    e.adjust_begin(note).unwrap();
    e.adjust_to(&[(8, 1.0)]);
    let change = e.adjust_to(&[(8, 2.5)]);
    assert_eq!(change.modified, [note]);
    assert_eq!(p(&e, note, 8), 2.5);
    assert_eq!(e.undo_label(), None);
    e.adjust_end(true, "Stem");
    assert_eq!(e.undo_label(), Some("Stem"));
    e.undo();
    assert_eq!(p(&e, note, 8), 0.0);

    e.adjust_begin(note).unwrap();
    e.adjust_to(&[(8, 4.0)]);
    e.adjust_end(false, "Stem");
    assert_eq!((p(&e, note, 8), e.undo_label()), (0.0, None));
    e.adjust_begin(note).unwrap();
    e.adjust_to(&[(8, 4.0)]);
    e.select(&[note]);
    assert_eq!(p(&e, note, 8), 0.0, "selecting ends an unfinished adjustment without a change");
}

#[test]
fn text_entry_and_new_characters_keep_count_and_length() {
    let mut e = small();
    let change = e.insert_text("_00Hello", &[1.0, 50.0, 10.0]).unwrap();
    let text = change.inserted[0];
    let item = e.item(text).unwrap();
    assert_eq!((item.text(), item.param(12), item.param(13)), (&b"_00Hello"[..], 8.0, 11.434_941));
    e.set_text(text, "Hello, world").unwrap();
    let item = e.item(text).unwrap();
    assert_eq!((item.text(), item.param(12)), (&b"_00Hello, world"[..], 15.0));
    assert!(item.param(13) > 11.434_941);
    assert_eq!(e.undo_label(), Some("Edit text"));
    e.undo();
    assert_eq!(e.item(text).unwrap().text(), b"_00Hello");
    assert!(matches!(e.set_text(e.id_at(1).unwrap(), "x"), Err(EditError::NotForCode { code: 1, .. })));
}

#[test]
fn divided_text_makes_one_item_per_part() {
    let mut e = small();
    let change = e.execute("\"_04This/is/how\"").unwrap();
    assert_eq!(change.inserted.len(), 3);
    assert_eq!(change.selection, [change.inserted[2]]);
    assert_eq!(e.execute("\"unclosed 1 2"), Err(EditError::UnknownCommand("\"".into())));
}

#[test]
fn group_commands_ask_line_by_line_and_undo_in_one_step() {
    let mut e = small();
    assert_eq!(e.prompt(), None);
    e.execute("M").unwrap();
    assert!(e.prompt().unwrap().starts_with("Enter staff"));
    e.execute("1 90 130").unwrap();
    assert!(e.prompt().unwrap().starts_with("Enter destination"));
    let change = e.execute("1 5").unwrap();
    assert_eq!(e.prompt(), None);
    assert_eq!(change.modified.len(), 2);
    assert_eq!(p(&e, e.id_at(1).unwrap(), 3), 105.0);
    e.undo();
    assert_eq!(p(&e, e.id_at(1).unwrap(), 3), 100.0);
}

#[test]
fn a_box_selects_the_items_inside() {
    let mut e = small();
    e.select_region(&score_edit::group::Region::parse(&[1.0, 110.0, 130.0]).unwrap());
    assert_eq!(e.selection(), [e.id_at(2).unwrap()]);
    e.execute("U 1").unwrap();
    assert_eq!(p(&e, e.id_at(2).unwrap(), 4), 8.0);
}

#[test]
fn symbols_from_the_picker_are_code_9_items() {
    let mut e = small();
    let fermata = score_edit::symbols::library_symbols().into_iter().find(|s| s.name == "fermata").unwrap();
    let change = e.insert_symbol(fermata.number, 1.0, 80.0, 12.0).unwrap();
    let item = e.item(change.inserted[0]).unwrap();
    assert_eq!((item.code(), item.param(3), item.param(4), item.param(5)), (9, 80.0, 12.0, 31.0));
    assert_eq!(e.selection(), change.inserted);
}

#[test]
fn lft_drags_only_the_left_end() {
    let mut e = editor_with(&[&[8.0, 1.0, 0.0], &[4.0, 1.0, 50.0, 5.0, 10.0, 120.0]]);
    let line = e.id_at(1).unwrap();
    e.select(&[line]);
    e.execute("LFT").unwrap();
    e.drag_begin_at(0.0, 0.0);
    e.drag_to_point(150.0, 175.0, false);
    e.drag_end(true);
    assert_eq!((p(&e, line, 3), p(&e, line, 4), p(&e, line, 5), p(&e, line, 6)), (51.0, 6.0, 10.0, 120.0));
}

fn p(editor: &Editor, id: ItemId, n: usize) -> f32 {
    editor.item(id).unwrap().param(n)
}

#[test]
fn opening_and_saving_changes_nothing() {
    let bytes = sample("carmen.mus");
    assert_eq!(Editor::open(&bytes).unwrap().save(), bytes);
}

#[test]
fn commands_act_on_the_selection_and_undo_in_steps() {
    let mut e = small();
    let note = e.id_at(1).unwrap();
    e.select(&[note]);
    let change = e.execute("R 5").unwrap();
    assert_eq!(change.modified, [note]);
    e.execute("FLI").unwrap();
    assert_eq!((p(&e, note, 3), p(&e, note, 5)), (105.0, 20.0));
    assert_eq!(e.undo_label(), Some("FLI"));
    e.undo();
    assert_eq!((p(&e, note, 3), p(&e, note, 5)), (105.0, 10.0));
    e.undo();
    assert_eq!(p(&e, note, 3), 100.0);
    assert!(!e.can_undo());
    assert_eq!(e.redo().unwrap().modified, [note]);
    assert_eq!(p(&e, note, 3), 105.0);
    assert_eq!(e.redo_label(), Some("FLI"));
}

#[test]
fn actions_after_a_mark_combine_into_one_step_or_roll_back() {
    let mut e = small();
    let (first, second) = (e.id_at(1).unwrap(), e.id_at(2).unwrap());
    e.select(&[first]);
    e.execute("R 5").unwrap();
    let mark = e.mark();
    e.execute("FLI").unwrap();
    e.select(&[second]);
    e.delete_selection().unwrap();
    assert!(e.combine(mark, "flip and delete"));
    assert_eq!(e.undo_label(), Some("flip and delete"));
    e.undo();
    assert_eq!((p(&e, first, 5), e.index_of(second)), (10.0, Some(2)));
    assert_eq!(e.selection(), [first]);
    e.redo();
    assert_eq!(e.mark(), mark + 1);

    let change = e.rollback(mark);
    assert_eq!((p(&e, first, 5), e.index_of(second)), (10.0, Some(2)));
    assert_eq!((change.inserted, change.modified), (vec![second], vec![first]));
    assert_eq!(e.selection(), [first]);
    assert_eq!((e.undo_label(), e.redo_label()), (Some("R 5"), None));
    assert!(!e.combine(mark, "nothing"));
    assert_eq!(p(&e, first, 3), 105.0);
}

#[test]
fn ids_survive_deleting_earlier_items() {
    let mut e = small();
    let (first, second) = (e.id_at(1).unwrap(), e.id_at(2).unwrap());
    e.select(&[first]);
    let change = e.delete_selection().unwrap();
    assert_eq!(change.removed, [first]);
    assert!(e.selection().is_empty());
    assert_eq!(e.index_of(second), Some(1));
    e.undo();
    assert_eq!(e.index_of(first), Some(1));
    assert_eq!(e.selection(), [first]);
}

#[test]
fn failed_commands_change_nothing() {
    let mut e = small();
    let before = e.save();
    assert_eq!(e.execute("R 5"), Err(EditError::NoSelection("R".into())));
    assert_eq!(e.execute("FROB"), Err(EditError::UnknownCommand("FROB".into())));
    e.select(&[e.id_at(0).unwrap()]);
    assert!(matches!(e.execute("FLI"), Err(EditError::NotForCode { code: 8, .. })));
    assert_eq!(e.save(), before);
    assert!(!e.can_undo());
}

#[test]
fn new_items_are_selected() {
    let mut e = small();
    let change = e.execute("NOTE 1 50").unwrap();
    assert_eq!(change.inserted.len(), 1);
    assert_eq!(change.selection, change.inserted);
    let note = change.inserted[0];
    assert_eq!(e.index_of(note), Some(3));
    e.execute("U 2").unwrap();
    assert_eq!(p(&e, note, 4), 3.0);
}

#[test]
fn creating_while_editing_starts_a_new_item() {
    let mut e = small();
    e.select(&[e.id_at(1).unwrap()]);
    let change = e.execute("TREB").unwrap();
    assert_eq!(e.item(change.inserted[0]).unwrap().code(), 3);
}

#[test]
fn several_items_move_together() {
    let mut e = small();
    let (a, b) = (e.id_at(1).unwrap(), e.id_at(2).unwrap());
    e.select(&[a]);
    e.add_to_selection(b);
    let change = e.move_selection(2.0, -1.0).unwrap();
    assert_eq!(change.modified.len(), 2);
    assert_eq!((p(&e, a, 3), p(&e, a, 4), p(&e, b, 3), p(&e, b, 4)), (102.0, 5.0, 122.0, 6.0));
    e.move_staff(1).unwrap();
    assert_eq!((p(&e, a, 2), p(&e, b, 2)), (2.0, 2.0));
    assert_eq!(e.undo_label(), Some("Move to staff"));
}

#[test]
fn a_drag_is_one_undo_step() {
    let mut e = small();
    let note = e.id_at(1).unwrap();
    e.select(&[note]);
    e.drag_begin_at(0.0, 0.0);
    e.drag_to_point(150.0, 0.0, false);
    e.drag_to_point(300.0, 175.0, false);
    assert_eq!((p(&e, note, 3), p(&e, note, 4)), (102.0, 7.0));
    assert!(!e.can_undo());
    let change = e.drag_end(true);
    assert_eq!(change.modified, [note]);
    assert_eq!(e.undo_label(), Some("Drag"));
    e.undo();
    assert_eq!((p(&e, note, 3), p(&e, note, 4)), (100.0, 6.0));
}

#[test]
fn a_cancelled_drag_leaves_no_trace() {
    let mut e = small();
    let note = e.id_at(1).unwrap();
    e.select(&[note]);
    e.drag_begin_at(0.0, 0.0);
    e.drag_to_point(1500.0, 0.0, false);
    e.drag_end(false);
    assert_eq!(p(&e, note, 3), 100.0);
    assert!(!e.can_undo());
}

#[test]
fn copy_continue_reports_the_copy_and_selects_it() {
    let mut e = small();
    let note = e.id_at(1).unwrap();
    e.select(&[note]);
    e.execute("R 10").unwrap();
    let change = e.execute("CC").unwrap();
    assert_eq!(change.modified, [note]);
    assert_eq!(change.inserted.len(), 1);
    assert_eq!(change.selection, change.inserted);
    assert_eq!(p(&e, note, 3), 100.0);
    assert_eq!(p(&e, change.inserted[0], 3), 110.0);
}

#[test]
fn copies_paste_beside_or_at_a_place_in_one_step() {
    let mut e = small();
    let (a, b) = (e.id_at(1).unwrap(), e.id_at(2).unwrap());
    e.select(&[b, a]);
    let copied = e.copy_selection();
    assert_eq!(copied.iter().map(|item| item.param(3)).collect::<Vec<_>>(), [100.0, 120.0]);
    assert!(!e.can_undo());
    let x = |e: &Editor, change: &Change| change.inserted.iter().map(|&id| p(e, id, 3)).collect::<Vec<_>>();
    let beside = e.paste(&copied, Placement::InPlace).unwrap();
    assert_eq!(e.undo_label(), Some("Paste"));
    assert_eq!(e.selection(), beside.inserted);
    assert_eq!(x(&e, &beside), [110.0, 130.0]);
    let further = e.paste(&copied, Placement::InPlace).unwrap();
    assert_eq!(x(&e, &further), [120.0, 140.0]);
    let at = e.paste(&copied, Placement::At { staff: 2.0, p3: 50.0 }).unwrap();
    let placed: Vec<[f32; 3]> = at.inserted.iter().map(|&id| [p(&e, id, 2), p(&e, id, 3), p(&e, id, 4)]).collect();
    assert_eq!(placed, [[2.0, 50.0, 6.0], [2.0, 70.0, 7.0]]);
    (0..3).for_each(|_| assert!(e.undo().is_some()));
    assert_eq!(e.document().len(), 3);
    assert!(e.paste(&[], Placement::InPlace).unwrap().is_empty());
    let mut other = editor_with(&[&[8.0, 1.0, 0.0]]);
    let into_other = other.paste(&copied, Placement::InPlace).unwrap();
    assert_eq!(x(&other, &into_other), [100.0, 120.0]);
}

#[test]
fn cut_deletes_and_pst_pastes_what_was_cut() {
    let mut e = small();
    e.select(&[e.id_at(2).unwrap()]);
    e.cut_selection().unwrap();
    assert_eq!(e.undo_label(), Some("Cut"));
    assert_eq!(e.document().len(), 2);
    assert!(e.selection().is_empty());
    let change = e.execute("PST").unwrap();
    assert_eq!(p(&e, change.inserted[0], 3), 120.0);
}

#[test]
fn duplicates_go_beside_and_leave_the_clipboard_alone() {
    let mut e = small();
    e.select(&[e.id_at(1).unwrap()]);
    let change = e.duplicate_selection().unwrap();
    assert_eq!(e.undo_label(), Some("Duplicate"));
    assert_eq!(e.selection(), change.inserted);
    assert_eq!(p(&e, change.inserted[0], 3), 110.0);
    let again = e.duplicate_selection().unwrap();
    assert_eq!(p(&e, again.inserted[0], 3), 120.0);
    e.clear_selection();
    assert!(e.duplicate_selection().unwrap().is_empty());
    assert!(e.execute("PST").unwrap().is_empty());
}

#[test]
fn undelete_brings_back_what_was_deleted() {
    let mut e = small();
    let note = e.id_at(1).unwrap();
    e.select(&[note]);
    e.delete_selection().unwrap();
    let change = e.execute("UND").unwrap();
    assert_eq!(change.inserted, [note]);
    assert_eq!(e.index_of(note), Some(1));
    assert_eq!(e.execute("UND"), Err(EditError::InEditMode("UND".into())));
    e.clear_selection();
    assert_eq!(e.execute("UND"), Err(EditError::NothingToUndelete));
}

#[test]
fn set_param_works_without_selection() {
    let mut e = small();
    let note = e.id_at(2).unwrap();
    e.set_param(note, 11, 7.0).unwrap();
    assert_eq!(p(&e, note, 11), 7.0);
    assert_eq!(e.undo_label(), Some("Set P11"));
    assert_eq!(e.set_param(note, 0, 1.0), Err(EditError::NoSuchParam(0.0)));
}

#[test]
fn set_params_is_one_undo_step() {
    let mut e = small();
    let note = e.id_at(2).unwrap();
    e.set_params(note, &[(6, 0.0), (7, 0.5), (9, 1.0)]).unwrap();
    assert_eq!([p(&e, note, 7), p(&e, note, 9)], [0.5, 1.0]);
    assert_eq!(e.undo_label(), Some("Set P6, P7, P9"));
    e.undo();
    assert_eq!([p(&e, note, 7), p(&e, note, 9)], [1.0, 0.0]);
    assert_eq!(e.set_params(note, &[(5, 20.0), (46, 1.0)]), Err(EditError::NoSuchParam(46.0)));
    assert_eq!(p(&e, note, 5), 10.0);
}

#[test]
fn params_of_several_items_are_one_undo_step() {
    let mut e = small();
    let (first, second) = (e.id_at(1).unwrap(), e.id_at(2).unwrap());
    e.select(&[first, second]);
    e.set_params_of(&[(first, vec![(4, 8.0), (7, 0.5)]), (second, vec![(4, 9.0), (9, 1.0)])]).unwrap();
    assert_eq!([p(&e, first, 4), p(&e, first, 7), p(&e, second, 4), p(&e, second, 9)], [8.0, 0.5, 9.0, 1.0]);
    assert_eq!(e.undo_label(), Some("Set P4, P7, P9 of 2 items"));
    assert_eq!(e.selection(), [first, second]);
    e.undo();
    assert_eq!([p(&e, first, 4), p(&e, second, 4), p(&e, second, 9)], [6.0, 7.0, 0.0]);
    let wrong = e.set_params_of(&[(first, vec![(4, 3.0)]), (second, vec![(0, 1.0)])]);
    assert_eq!(wrong, Err(EditError::NoSuchParam(0.0)));
    assert_eq!(p(&e, first, 4), 6.0);
}

#[test]
fn inserted_items_append_and_select() {
    let mut e = small();
    let note = e.item(e.id_at(1).unwrap()).unwrap().clone();
    let change = e.insert_items(vec![note.clone(), note]).unwrap();
    assert_eq!(change.inserted.len(), 2);
    assert_eq!(e.selection(), change.inserted);
    assert_eq!(e.file().items.len(), 5);
    e.undo();
    assert_eq!(e.file().items.len(), 3);
}

#[test]
fn transposition_keeps_ids_and_undoes_in_one_step() {
    let mut e = editor_with(&[&[8.0, 1.0, 0.0], &[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.0], &[17.0, 1.0, 10.0, 0.0, 1.0]]);
    let (note, key) = (e.id_at(1).unwrap(), e.id_at(2).unwrap());
    let area = Region::parse(&[1.0]).unwrap();
    let up_a_tone = Transposition { half_steps: 2, ..Transposition::default() };
    let change = e.transpose(&area, &up_a_tone).unwrap();
    assert_eq!((e.index_of(key), e.index_of(note)), (Some(1), Some(2)));
    assert_eq!((p(&e, key, 5), p(&e, note, 4)), (3.0, 7.0));
    assert_eq!(change.modified.len(), 2);
    assert_eq!(e.undo_label(), Some("Transpose"));
    e.undo();
    assert_eq!((e.index_of(note), p(&e, note, 4), p(&e, key, 5)), (Some(1), 6.0, 1.0));
    let enharmonic = Transposition { half_steps: 99, ..up_a_tone };
    assert!(matches!(e.transpose(&area, &enharmonic), Err(EditError::NotImplemented(_))));
}

#[test]
fn tr_asks_for_its_area_and_then_the_dialog_values() {
    let mut e = small();
    e.execute("TR").unwrap();
    e.execute("1 0 0 0").unwrap();
    assert_eq!(e.prompt(), Some(TRANSPOSITION_PROMPT));
    e.execute("half=-1").unwrap();
    assert_eq!(e.prompt(), None);
    assert_eq!(p(&e, e.id_at(1).unwrap(), 4), 5.0);
}

#[test]
fn layout_commands_report_where_the_engine_gives_up() {
    let mut e = editor_with(&[
        &[8.0, 1.0, 0.0],
        &[8.0, 2.0, 0.0, 0.0, 0.0, 200.0],
        &[1.0, 1.0, 20.0, 6.0, 10.0, 0.0, 2.0],
        &[1.0, 2.0, 20.0, 6.0, 10.0, 0.0, 1.0],
    ]);
    let system = StaffRange::from_answer(1, 2);
    let change = e.lay_out(LayoutCommand::LineUp, system, &Options::default()).unwrap();
    assert!(change.message.is_some_and(|m| m.contains("beats")));
    let mut e = small();
    e.execute("LJ").unwrap();
    assert!(e.prompt().is_some_and(|p| p.starts_with("Enter Lowest Staff#")));
    e.execute("1 1").unwrap();
    assert_eq!(e.undo_label(), Some("LJ 1 1"));
}
