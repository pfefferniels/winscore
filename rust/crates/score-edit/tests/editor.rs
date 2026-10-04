//! The editing API as the browser shell uses it: selection, actions, drags, undo.

use std::path::PathBuf;

use score_edit::{EditError, Editor, ItemId};

fn sample(name: &str) -> Vec<u8> {
    let root = PathBuf::from(env!("CARGO_MANIFEST_DIR")).join("../../..");
    std::fs::read(root.join("WINSCORE 5.01/winscore").join(name)).expect("sample score")
}

/// A staff and two quarter notes, as a .mus file.
fn small() -> Editor {
    let items: [&[f32]; 3] = [&[8.0, 1.0, 0.0], &[1.0, 1.0, 100.0, 6.0, 10.0, 0.0, 1.0], &[1.0, 1.0, 120.0, 7.0, 10.0, 0.0, 1.0]];
    let mut words: Vec<f32> = items.iter().flat_map(|i| std::iter::once(i.len() as f32).chain(i.iter().copied())).collect();
    words.extend([0.0, 0.0, 6.0, 0.0, 5.0, -9999.0]);
    let mut bytes = (words.len() as u16).to_le_bytes().to_vec();
    bytes.extend(words.iter().flat_map(|w| w.to_le_bytes()));
    Editor::open(&bytes).unwrap()
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
    e.drag_begin();
    e.drag_to(150.0, 0.0);
    e.drag_to(300.0, 175.0);
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
    e.drag_begin();
    e.drag_to(1500.0, 0.0);
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
