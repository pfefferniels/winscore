//! Compares display lists with the engine fixtures and writes the status
//! table (`--help` lists the options).
//!
//! By default every fixture's `input.mus` is rendered with `score_render` and
//! compared with the engine's `engine.json`.

use std::collections::BTreeMap;
use std::fmt::Write as _;
use std::fs;
use std::panic;
use std::path::{Path, PathBuf};
use std::process::{Command, ExitCode};

use score_render::{DisplayList, ItemId};
use score_testkit::svg::{triptych, Caption};
use score_testkit::{
    compare, display_from_json, display_to_json, fixtures_dir, load_all, render_fixture, restrict,
    CompareOptions, Fixture, Report, Section,
};

const USAGE: &str = "\
score-compare [OPTIONS] [PATTERN ...]
  --fixtures DIR          fixture directory (default: rust/fixtures)
  --self                  compare every fixture with itself (pipeline check)
  --actual DIR            compare against DIR/<case>.json (engine.json format)
  --against CASE          compare every selected fixture against fixture CASE
  --status FILE           status table (default: <fixtures>/STATUS.md; \"-\" skips it)
  --images DIR            write engine | actual | diff pictures (PNG via resvg, else SVG)
  --dump DIR              write the compared lists as DIR/<case>.json (engine.json format)
  --width PX              picture width (default 2400)
  --ignore-staff-numbers  leave staff-number texts out of the comparison
  --verbose               print the report of every differing case
Without --self, --actual or --against, input.mus is rendered with score_render.
PATTERN selects cases by name; * matches any characters.";

#[derive(Debug, Clone, PartialEq, Eq)]
enum Source {
    Rust,
    SelfCheck,
    Directory(PathBuf),
    Fixture(String),
}

impl Source {
    fn label(&self) -> String {
        match self {
            Source::Rust => "score_render::render of input.mus".into(),
            Source::SelfCheck => "the fixture itself (pipeline check)".into(),
            Source::Directory(dir) => format!("display lists in {}", dir.display()),
            Source::Fixture(name) => format!("fixture {name}"),
        }
    }

    fn short(&self) -> &'static str {
        match self {
            Source::Rust => "rust",
            Source::SelfCheck => "fixture",
            Source::Directory(_) => "actual",
            Source::Fixture(_) => "other fixture",
        }
    }
}

#[derive(Debug)]
struct Args {
    fixtures: PathBuf,
    source: Source,
    status: Option<PathBuf>,
    images: Option<PathBuf>,
    dump: Option<PathBuf>,
    width: u32,
    options: CompareOptions,
    verbose: bool,
    patterns: Vec<String>,
}

fn parse_args() -> Result<Args, String> {
    let mut args = Args {
        fixtures: fixtures_dir(),
        source: Source::Rust,
        status: None,
        images: None,
        dump: None,
        width: 2400,
        options: CompareOptions::default(),
        verbose: false,
        patterns: vec![],
    };
    let mut status: Option<String> = None;
    let mut it = std::env::args().skip(1);
    while let Some(arg) = it.next() {
        let mut value = |name: &str| it.next().ok_or(format!("{name} needs a value"));
        match arg.as_str() {
            "--fixtures" => args.fixtures = value("--fixtures")?.into(),
            "--self" => args.source = Source::SelfCheck,
            "--actual" => args.source = Source::Directory(value("--actual")?.into()),
            "--against" => args.source = Source::Fixture(value("--against")?),
            "--status" => status = Some(value("--status")?),
            "--images" => args.images = Some(value("--images")?.into()),
            "--dump" => args.dump = Some(value("--dump")?.into()),
            "--width" => {
                args.width = value("--width")?
                    .parse()
                    .map_err(|e| format!("--width: {e}"))?
            }
            "--ignore-staff-numbers" => args.options.ignore_staff_numbers = true,
            "--verbose" | "-v" => args.verbose = true,
            "--help" | "-h" => return Err(String::new()),
            flag if flag.starts_with("--") => return Err(format!("unknown option {flag}")),
            pattern => args.patterns.push(pattern.to_string()),
        }
    }
    args.status = match status.as_deref() {
        Some("-") => None,
        Some(path) => Some(path.into()),
        None => Some(args.fixtures.join("STATUS.md")),
    };
    Ok(args)
}

/// `*` matches any run of characters, everything else itself.
fn glob_match(pattern: &str, name: &str) -> bool {
    match pattern.split_once('*') {
        None => pattern == name,
        Some((head, rest)) => {
            name.starts_with(head)
                && (0..=name.len() - head.len())
                    .filter(|&skip| name.is_char_boundary(head.len() + skip))
                    .any(|skip| glob_match(rest, &name[head.len() + skip..]))
        }
    }
}

// -- obtaining the list to compare -------------------------------------------

#[derive(Debug)]
enum Actual {
    List(DisplayList),
    Missing,
    Failed(String),
}

fn read_list(path: &Path) -> Actual {
    if !path.is_file() {
        return Actual::Missing;
    }
    let parsed = fs::read_to_string(path)
        .map_err(|e| e.to_string())
        .and_then(|text| display_from_json(&text).map_err(|e| e.to_string()));
    match parsed {
        Ok(list) => Actual::List(list),
        Err(err) => Actual::Failed(format!("{}: {err}", path.display())),
    }
}

fn actual_for(source: &Source, fixture: &Fixture, fixtures: &[Fixture]) -> Actual {
    match source {
        Source::Rust => render_fixture(fixture).map_or_else(Actual::Failed, Actual::List),
        Source::SelfCheck => Actual::List(fixture.display.clone()),
        Source::Directory(dir) => read_list(&dir.join(format!("{}.json", fixture.name))),
        Source::Fixture(name) => fixtures.iter().find(|f| &f.name == name).map_or_else(
            || Actual::Failed(format!("no fixture named {name}")),
            |f| Actual::List(f.display.clone()),
        ),
    }
}

// -- outcomes ------------------------------------------------------------------

#[derive(Debug)]
enum Outcome {
    Invalid(String),
    NoOutput,
    Failed(String),
    Compared(Report),
}

/// Elements of the items of one code within one fixture.
#[derive(Debug, Clone, Copy, Default)]
struct Tally {
    fixtures: usize,
    matching: usize,
    shapes: [usize; 3],
    texts: [usize; 3],
}

impl Tally {
    fn of(report: &Report) -> Tally {
        let counts = |s: &Section| [s.matched, s.expected, s.extra.len()];
        Tally {
            fixtures: 1,
            matching: usize::from(report.is_match()),
            shapes: counts(&report.shapes),
            texts: counts(&report.texts),
        }
    }

    fn add(self, other: Tally) -> Tally {
        let sum = |a: [usize; 3], b: [usize; 3]| [a[0] + b[0], a[1] + b[1], a[2] + b[2]];
        Tally {
            fixtures: self.fixtures + other.fixtures,
            matching: self.matching + other.matching,
            shapes: sum(self.shapes, other.shapes),
            texts: sum(self.texts, other.texts),
        }
    }
}

#[derive(Debug)]
struct Row<'a> {
    fixture: &'a Fixture,
    outcome: Outcome,
    /// Per item code: the comparison restricted to that code's items.
    by_code: BTreeMap<i32, Tally>,
}

impl Row<'_> {
    fn result(&self) -> &'static str {
        match &self.outcome {
            Outcome::Invalid(_) => "invalid",
            Outcome::NoOutput => "no output",
            Outcome::Failed(_) => "failed",
            Outcome::Compared(r) if r.is_match() => "match",
            Outcome::Compared(_) => "differs",
        }
    }
}

fn codes_of(fixture: &Fixture) -> BTreeMap<u32, i32> {
    fixture
        .input()
        .map(|file| {
            file.items
                .iter()
                .enumerate()
                .map(|(i, item)| (i as u32, item.code()))
                .collect()
        })
        .unwrap_or_default()
}

fn by_code(
    fixture: &Fixture,
    actual: &DisplayList,
    options: &CompareOptions,
) -> BTreeMap<i32, Tally> {
    let codes = codes_of(fixture);
    let present: std::collections::BTreeSet<i32> = codes.values().copied().collect();
    present
        .into_iter()
        .map(|code| {
            let keep = |ItemId(i): ItemId| codes.get(&i) == Some(&code);
            let report = compare(
                &restrict(&fixture.display, keep),
                &restrict(actual, keep),
                options,
            );
            (code, Tally::of(&report))
        })
        .filter(|(_, tally)| {
            tally.shapes[1] + tally.texts[1] + tally.shapes[2] + tally.texts[2] > 0
        })
        .collect()
}

fn evaluate<'a>(fixture: &'a Fixture, actual: &Actual, options: &CompareOptions) -> Row<'a> {
    let (outcome, by_code) = match actual {
        _ if !fixture.meta.valid => (
            Outcome::Invalid(fixture.meta.invalid_reasons.join("; ")),
            BTreeMap::new(),
        ),
        Actual::Missing => (Outcome::NoOutput, BTreeMap::new()),
        Actual::Failed(err) => (Outcome::Failed(err.clone()), BTreeMap::new()),
        Actual::List(list) => (
            Outcome::Compared(compare(&fixture.display, list, options)),
            by_code(fixture, list, options),
        ),
    };
    Row {
        fixture,
        outcome,
        by_code,
    }
}

// -- status table ----------------------------------------------------------------

const CODE_NAMES: [(i32, &str); 17] = [
    (1, "notes"),
    (2, "rests"),
    (3, "clefs"),
    (4, "lines, hairpins"),
    (5, "slurs, brackets"),
    (6, "beams"),
    (7, "trills, ottava, pedal"),
    (8, "staves"),
    (9, "library symbols"),
    (10, "numbers"),
    (11, "user symbols"),
    (12, "boxes, grids"),
    (14, "barlines"),
    (15, "EPS"),
    (16, "text"),
    (17, "key signatures"),
    (18, "meters"),
];

fn code_name(code: i32) -> &'static str {
    CODE_NAMES
        .iter()
        .find(|(c, _)| *c == code)
        .map_or("", |(_, name)| name)
}

fn group(name: &str) -> &str {
    name.split('-').next().unwrap_or(name)
}

fn ratio([matched, expected, extra]: [usize; 3]) -> String {
    let extra = if extra == 0 {
        String::new()
    } else {
        format!(" +{extra}")
    };
    format!("{matched}/{expected}{extra}")
}

fn cell(section: &Section) -> String {
    ratio([section.matched, section.expected, section.extra.len()])
}

fn escape_cell(text: &str) -> String {
    text.replace('|', "/").replace('\n', " ")
}

fn table_line(row: &Row) -> String {
    let (shapes, texts, deviation) = match &row.outcome {
        Outcome::Compared(r) => (
            cell(&r.shapes),
            cell(&r.texts),
            r.max_deviation().to_string(),
        ),
        _ => (String::new(), String::new(), String::new()),
    };
    let note = match &row.outcome {
        Outcome::Invalid(reason) | Outcome::Failed(reason) => reason.chars().take(160).collect(),
        _ => row.fixture.meta.description.clone(),
    };
    format!(
        "| {} | {} | {shapes} | {texts} | {deviation} | {} |",
        row.fixture.name,
        row.result(),
        escape_cell(&note)
    )
}

fn group_section(rows: &[Row]) -> String {
    #[derive(Default)]
    struct GroupTally {
        cases: usize,
        valid: usize,
        compared: usize,
        matching: usize,
        shapes: [usize; 3],
        texts: [usize; 3],
    }
    let mut groups: BTreeMap<&str, GroupTally> = BTreeMap::new();
    rows.iter().for_each(|row| {
        let g = groups.entry(group(&row.fixture.name)).or_default();
        g.cases += 1;
        g.valid += usize::from(row.fixture.meta.valid);
        g.matching += usize::from(row.result() == "match");
        if let Outcome::Compared(r) = &row.outcome {
            g.compared += 1;
            let add = |a: [usize; 3], s: &Section| {
                [a[0] + s.matched, a[1] + s.expected, a[2] + s.extra.len()]
            };
            g.shapes = add(g.shapes, &r.shapes);
            g.texts = add(g.texts, &r.texts);
        }
    });
    let mut out =
        String::from("| group | cases | valid | compared | matching | shapes | texts |\n|---|---|---|---|---|---|---|\n");
    groups.iter().for_each(|(name, g)| {
        let _ = writeln!(
            out,
            "| {name} | {} | {} | {} | {} | {} | {} |",
            g.cases,
            g.valid,
            g.compared,
            g.matching,
            ratio(g.shapes),
            ratio(g.texts)
        );
    });
    out
}

fn code_section(rows: &[Row]) -> String {
    let mut codes: BTreeMap<i32, Tally> = BTreeMap::new();
    rows.iter()
        .flat_map(|row| row.by_code.iter())
        .for_each(|(&code, &tally)| {
            let entry = codes.entry(code).or_default();
            *entry = entry.add(tally);
        });
    let mut out = String::from(
        "| code | items | fixtures with output | fully matching | shapes | texts |\n|---|---|---|---|---|---|\n",
    );
    codes.iter().for_each(|(code, t)| {
        let _ = writeln!(
            out,
            "| {code} | {} | {} | {} | {} | {} |",
            code_name(*code),
            t.fixtures,
            t.matching,
            ratio(t.shapes),
            ratio(t.texts)
        );
    });
    out
}

fn status_markdown(rows: &[Row], source: &Source, options: &CompareOptions) -> String {
    let mut out = String::new();
    let _ = writeln!(out, "# Fixture status\n");
    let _ = writeln!(
        out,
        "Written by `score-compare` (crate `score-testkit`). Compared: the engine's `engine.json` against {}. \
         Tolerance ±{} engine units{}. Counts are matched/expected; `+n` = elements only the Rust side has.\n",
        source.label(),
        options.tolerance,
        if options.ignore_staff_numbers { ", staff numbers ignored" } else { "" }
    );
    let _ = writeln!(out, "## By fixture group\n\n{}", group_section(rows));
    let _ = writeln!(
        out,
        "## By item code\n\nOnly the elements drawn by items of that code, over all compared fixtures; \
         a fixture counts as fully matching when that code's elements all match.\n\n{}",
        code_section(rows)
    );
    let _ = writeln!(
        out,
        "## Cases\n\n| case | result | shapes | texts | max dev | note |\n|---|---|---|---|---|---|"
    );
    rows.iter().for_each(|row| {
        let _ = writeln!(out, "{}", table_line(row));
    });
    out
}

// -- pictures --------------------------------------------------------------------

fn write_picture(
    dir: &Path,
    row: &Row,
    actual: Option<&DisplayList>,
    args: &Args,
) -> Result<PathBuf, String> {
    let report = match &row.outcome {
        Outcome::Compared(r) => Some(r),
        _ => None,
    };
    let caption = Caption {
        case: &row.fixture.name,
        description: &row.fixture.meta.description,
        actual_label: args.source.short(),
    };
    let svg = triptych(
        &caption,
        &row.fixture.display,
        actual,
        report,
        &args.options,
        args.width,
    );
    let svg_path = dir.join(format!("{}.svg", row.fixture.name));
    fs::write(&svg_path, svg).map_err(|e| format!("{}: {e}", svg_path.display()))?;
    let png_path = svg_path.with_extension("png");
    let converted = Command::new("resvg")
        .arg(&svg_path)
        .arg(&png_path)
        .status()
        .is_ok_and(|s| s.success());
    if !converted {
        return Ok(svg_path);
    }
    fs::remove_file(&svg_path).map_err(|e| format!("{}: {e}", svg_path.display()))?;
    Ok(png_path)
}

// -- driver ----------------------------------------------------------------------

fn summary(row: &Row) -> String {
    match &row.outcome {
        Outcome::Compared(r) => format!(
            "shapes {} texts {} max dev {}",
            cell(&r.shapes),
            cell(&r.texts),
            r.max_deviation()
        ),
        Outcome::Invalid(reason) | Outcome::Failed(reason) => reason.chars().take(100).collect(),
        Outcome::NoOutput => String::new(),
    }
}

fn run(args: &Args) -> Result<bool, String> {
    let fixtures = load_all(&args.fixtures).map_err(|e| e.to_string())?;
    let selected: Vec<&Fixture> = fixtures
        .iter()
        .filter(|f| {
            args.patterns.is_empty() || args.patterns.iter().any(|p| glob_match(p, &f.name))
        })
        .collect();
    for dir in args.images.iter().chain(&args.dump) {
        fs::create_dir_all(dir).map_err(|e| format!("{}: {e}", dir.display()))?;
    }
    let mut rows = Vec::with_capacity(selected.len());
    for fixture in selected {
        let actual = actual_for(&args.source, fixture, &fixtures);
        let row = evaluate(fixture, &actual, &args.options);
        println!("{:44} {:9} {}", fixture.name, row.result(), summary(&row));
        if let (true, Outcome::Compared(report)) = (args.verbose, &row.outcome) {
            if !report.is_match() {
                print!("{report}");
            }
        }
        let list = match &actual {
            Actual::List(list) => Some(list),
            _ => None,
        };
        if let Some(dir) = &args.images {
            write_picture(dir, &row, list, args)?;
        }
        if let (Some(dir), Some(list)) = (&args.dump, list) {
            let path = dir.join(format!("{}.json", fixture.name));
            fs::write(&path, display_to_json(list))
                .map_err(|e| format!("{}: {e}", path.display()))?;
        }
        rows.push(row);
    }
    if let Some(path) = &args.status {
        fs::write(path, status_markdown(&rows, &args.source, &args.options))
            .map_err(|e| format!("{}: {e}", path.display()))?;
    }
    Ok(rows
        .iter()
        .all(|row| matches!(row.result(), "match" | "invalid")))
}

fn main() -> ExitCode {
    let args = match parse_args() {
        Ok(args) => args,
        Err(message) => {
            eprintln!("{message}\n{USAGE}");
            return ExitCode::from(2);
        }
    };
    // Renderer panics are reported per case; the default hook would print each one.
    panic::set_hook(Box::new(|_| {}));
    match run(&args) {
        Ok(true) => ExitCode::SUCCESS,
        Ok(false) => ExitCode::from(1),
        Err(message) => {
            eprintln!("score-compare: {message}");
            ExitCode::from(2)
        }
    }
}

#[cfg(test)]
mod tests {
    use super::glob_match;

    #[test]
    fn globs() {
        assert!(glob_match("code08-*", "code08-default"));
        assert!(glob_match("*", "anything"));
        assert!(glob_match("code1?", "code1?"));
        assert!(glob_match("*-p5-*", "code14-p5-final"));
        assert!(!glob_match("code08-*", "code14-p5"));
        assert!(!glob_match("code08", "code08-default"));
    }
}
