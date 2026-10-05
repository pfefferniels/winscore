//! Replays the command sequences of `engine_cases.txt` and compares the
//! resulting items with what WinScore's engine produced for them
//! (`engine_expected.txt`, written by `oracle/edit_driver.py`).

use std::collections::BTreeMap;

use score_edit::group::TRANSPOSITION_PROMPT;
use score_edit::{Draft, Editor};
use score_format::{CountWidth, Item, MusFile, Word};

const CASES: &str = include_str!("engine_cases.txt");
const EXPECTED: &str = include_str!("engine_expected.txt");
const DEFAULT_BASE: &str = "8 1; 1 1 100 6 10 0 1";

#[derive(Debug)]
struct Case {
    name: String,
    base: Vec<Item>,
    commands: Vec<String>,
}

/// One stored item, compared after dropping trailing zeros: parameters and text.
#[derive(Debug, Clone, PartialEq)]
struct Stored {
    params: Vec<f32>,
    text: String,
}

impl std::fmt::Display for Stored {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let params: Vec<String> = self.params.iter().map(|p| p.to_string()).collect();
        write!(f, "{}", params.join(" "))?;
        if !self.text.is_empty() {
            write!(f, " \"{}\"", self.text)?;
        }
        Ok(())
    }
}

fn trimmed(mut params: Vec<f32>) -> Vec<f32> {
    let kept = params.iter().rposition(|&p| p != 0.0).map_or(0, |i| i + 1);
    params.truncate(kept);
    params
}

fn parse_numbers(text: &str) -> Vec<f32> {
    text.split_whitespace().map(|v| v.parse().unwrap_or_else(|_| panic!("bad number {v:?}"))).collect()
}

/// `name -> lines` for every `== name` block, comment lines dropped.
fn blocks(text: &str) -> BTreeMap<String, Vec<String>> {
    text.split("\n== ")
        .map(|b| b.trim_start_matches("== "))
        .filter(|b| !b.trim().is_empty())
        .map(|block| {
            let mut lines = block.lines();
            let name = lines.next().unwrap_or_default().trim().to_owned();
            let body = lines.filter(|l| !l.starts_with('#') && !l.trim().is_empty()).map(str::to_owned).collect();
            (name, body)
        })
        .collect()
}

fn cases() -> Vec<Case> {
    let order: Vec<&str> =
        CASES.lines().filter_map(|l| l.strip_prefix("== ")).map(str::trim).collect();
    let blocks = blocks(CASES);
    order
        .into_iter()
        .map(|name| {
            let lines = &blocks[name];
            let base = lines.iter().find_map(|l| l.strip_prefix("base:")).unwrap_or(DEFAULT_BASE);
            Case {
                name: name.to_owned(),
                base: base.split(';').filter(|i| !i.trim().is_empty()).map(base_item).collect(),
                commands: lines.iter().filter(|l| !l.starts_with("base:")).cloned().collect(),
            }
        })
        .collect()
}

fn stored_line(line: &str) -> Stored {
    let (numbers, text) = match line.split_once(" \"") {
        Some((numbers, text)) => (numbers, text.trim_end_matches('"').to_owned()),
        None => (line, String::new()),
    };
    Stored { params: trimmed(parse_numbers(numbers)), text }
}

/// A base item: numbers, a text item's followed by its characters in double quotes.
fn base_item(text: &str) -> Item {
    let (numbers, characters) = match text.split_once('"') {
        Some((numbers, rest)) => (numbers, Some(rest.trim_end().trim_end_matches('"'))),
        None => (text, None),
    };
    let params = parse_numbers(numbers).into_iter().map(Word::from_f32).collect();
    match characters {
        Some(chars) => {
            let mut bytes: Vec<u8> = chars.chars().map(|c| c as u8).collect();
            bytes.resize(bytes.len().div_ceil(4) * 4, b' ');
            Item::with_text(params, bytes)
        }
        None => Item::new(params),
    }
}

fn mus_file(items: &[Item]) -> MusFile {
    let words: [f32; 6] = [0.0, 0.0, 6.0, 0.0, 5.0, -9999.0];
    let mut bytes = (words.len() as u16).to_le_bytes().to_vec();
    bytes.extend(words.iter().flat_map(|w| w.to_le_bytes()));
    let trailer = MusFile::parse(&bytes).expect("an empty .mus file").trailer;
    MusFile { width: CountWidth::Short, items: items.to_vec(), trailer }
}

fn stored(editor: &Editor) -> Vec<Stored> {
    editor
        .file()
        .items
        .iter()
        .map(|item| {
            let draft = Draft::of(item);
            let params = trimmed((1..=draft.len()).map(|n| draft.get(n)).collect());
            Stored { params, text: item.text().iter().map(|&b| char::from(b)).collect() }
        })
        .collect()
}

/// A mouse line of the cases: `~v x y` (move with the button held), `~s x y`
/// (with Shift), `~x x y` (button up), `~ x y` (click), in page coordinates.
/// `~x x0 y0 x1 y1`: a box drawn from mouse-down to mouse-up.
fn mouse(line: &str) -> Option<(&str, Vec<f64>)> {
    let mut parts = line.split_whitespace();
    let action = parts.next().filter(|a| matches!(*a, "~v" | "~s" | "~x" | "~"))?;
    let numbers: Vec<f64> = parts.map(str::parse).collect::<Result<_, _>>().ok()?;
    matches!(numbers.len(), 2 | 4).then_some((action, numbers))
}

/// Plays a mouse line the way the browser shell drives the editor. The engine
/// drags an item to the cursor; the cases start each drag at the item's own
/// reference point, where that and keeping the grab offset agree.
fn play_mouse(editor: &mut Editor, dragging: &mut bool, (action, numbers): (&str, Vec<f64>)) {
    if let [x0, y0, x1, y1] = numbers[..] {
        let _ = editor.draw_box(x0, y0, x1, y1);
        return;
    }
    let (x, y) = (numbers[0], numbers[1]);
    match action {
        "~v" | "~s" => {
            if !*dragging {
                editor.drag_begin_at(x, y);
                *dragging = true;
            }
            editor.drag_to_point(x, y, action == "~s");
        }
        "~x" => {
            editor.drag_end(true);
            *dragging = false;
        }
        _ if editor.selection().is_empty() => {
            let picked = editor.pick_at(x, y, None);
            editor.select(picked.as_slice());
        }
        _ => {}
    }
}

/// The values a `!transpose` line gives TR's dialog, in the syntax of
/// [`score_edit::transpose::Transposition::parse`].
fn dialog_values(line: &str) -> Option<&str> {
    line.strip_prefix("!transpose").map(str::trim)
}

fn replay(case: &Case) -> (Vec<Stored>, Vec<String>) {
    let mut editor = Editor::new(mus_file(&case.base));
    let mut dragging = false;
    let mut dialog = None;
    let errors = case
        .commands
        .iter()
        .filter_map(|c| {
            if let Some(values) = dialog_values(c) {
                dialog = Some(values);
                return None;
            }
            let error = match mouse(c) {
                Some(m) => {
                    play_mouse(&mut editor, &mut dragging, m);
                    None
                }
                None => editor.execute(c).err().map(|e| format!("[{c}] {e}")),
            };
            let answer = dialog.filter(|_| editor.prompt() == Some(TRANSPOSITION_PROMPT));
            let dialog_error = answer.and_then(|v| editor.execute(v).err().map(|e| format!("[dialog {v}] {e}")));
            error.or(dialog_error)
        })
        .collect();
    (stored(&editor), errors)
}

#[test]
fn edits_match_the_engine() {
    let expected = blocks(EXPECTED);
    let cases = cases();
    let failures: Vec<String> = cases
        .iter()
        .filter_map(|case| {
            let Some(lines) = expected.get(&case.name) else {
                return Some(format!("== {}: no engine result; run oracle/edit_driver.py", case.name));
            };
            let want: Vec<Stored> = lines.iter().map(|l| stored_line(l)).collect();
            let (got, errors) = replay(case);
            (got != want).then(|| {
                let show = |items: &[Stored]| items.iter().map(|i| format!("    {i}")).collect::<Vec<_>>().join("\n");
                format!("== {}\n  engine:\n{}\n  ours:\n{}\n  errors: {:?}", case.name, show(&want), show(&got), errors)
            })
        })
        .collect();
    assert!(failures.is_empty(), "{} of {} cases differ:\n{}", failures.len(), cases.len(), failures.join("\n"));
}
