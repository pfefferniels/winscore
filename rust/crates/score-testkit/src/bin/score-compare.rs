//! Compares display lists with the engine fixtures and writes the status
//! table (`--help` lists the options).
//!
//! Without `--actual` or `--against` every fixture is compared with itself,
//! which checks the fixtures and the pipeline until `score-render` can render
//! fixture inputs.

use std::collections::BTreeMap;
use std::fmt::Write as _;
use std::fs;
use std::path::{Path, PathBuf};
use std::process::{Command, ExitCode};

use score_render::DisplayList;
use score_testkit::svg::{triptych, Caption};
use score_testkit::{compare, display_from_json, fixtures_dir, load_all, CompareOptions, Fixture, Report};

const USAGE: &str = "\
score-compare [OPTIONS] [PATTERN ...]
  --fixtures DIR          fixture directory (default: rust/fixtures)
  --actual DIR            compare against DIR/<case>.json (engine.json format)
  --against CASE          compare every selected fixture against fixture CASE
  --status FILE           status table (default: <fixtures>/STATUS.md; \"-\" skips it)
  --images DIR            write engine | actual | diff pictures (PNG via resvg, else SVG)
  --width PX              picture width (default 2400)
  --ignore-staff-numbers  leave staff-number texts out of the comparison
  --verbose               print the report of every differing case
PATTERN selects cases by name; * matches any characters.";

#[derive(Debug, Clone, PartialEq, Eq)]
enum Source {
    SelfCheck,
    Directory(PathBuf),
    Fixture(String),
}

impl Source {
    fn label(&self) -> String {
        match self {
            Source::SelfCheck => "fixture itself (pipeline self-check)".into(),
            Source::Directory(dir) => format!("display lists in {}", dir.display()),
            Source::Fixture(name) => format!("fixture {name}"),
        }
    }
}

#[derive(Debug)]
struct Args {
    fixtures: PathBuf,
    source: Source,
    status: Option<PathBuf>,
    images: Option<PathBuf>,
    width: u32,
    options: CompareOptions,
    verbose: bool,
    patterns: Vec<String>,
}

fn parse_args() -> Result<Args, String> {
    let mut args = Args {
        fixtures: fixtures_dir(),
        source: Source::SelfCheck,
        status: None,
        images: None,
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
            "--actual" => args.source = Source::Directory(value("--actual")?.into()),
            "--against" => args.source = Source::Fixture(value("--against")?),
            "--status" => status = Some(value("--status")?),
            "--images" => args.images = Some(value("--images")?.into()),
            "--width" => args.width = value("--width")?.parse().map_err(|e| format!("--width: {e}"))?,
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

fn actual_for(source: &Source, fixture: &Fixture, fixtures: &[Fixture]) -> Result<Option<DisplayList>, String> {
    match source {
        Source::SelfCheck => Ok(Some(fixture.display.clone())),
        Source::Fixture(name) => fixtures
            .iter()
            .find(|f| &f.name == name)
            .map(|f| Some(f.display.clone()))
            .ok_or(format!("no fixture named {name}")),
        Source::Directory(dir) => {
            let path = dir.join(format!("{}.json", fixture.name));
            if !path.is_file() {
                return Ok(None);
            }
            let text = fs::read_to_string(&path).map_err(|e| format!("{}: {e}", path.display()))?;
            display_from_json(&text)
                .map(Some)
                .map_err(|e| format!("{}: {e}", path.display()))
        }
    }
}

#[derive(Debug)]
enum Outcome {
    Invalid(String),
    NoOutput,
    Compared(Report),
}

#[derive(Debug)]
struct Row<'a> {
    fixture: &'a Fixture,
    outcome: Outcome,
}

impl Row<'_> {
    fn result(&self) -> &'static str {
        match &self.outcome {
            Outcome::Invalid(_) => "invalid",
            Outcome::NoOutput => "no output",
            Outcome::Compared(r) if r.is_match() => "match",
            Outcome::Compared(_) => "differs",
        }
    }
}

fn group(name: &str) -> &str {
    name.split('-').next().unwrap_or(name)
}

fn cell(section: &score_testkit::Section) -> String {
    let extra = if section.extra.is_empty() {
        String::new()
    } else {
        format!(" +{}", section.extra.len())
    };
    format!("{}/{}{extra}", section.matched, section.expected)
}

fn table_line(row: &Row) -> String {
    let (shapes, texts, deviation) = match &row.outcome {
        Outcome::Compared(r) => (cell(&r.shapes), cell(&r.texts), r.max_deviation().to_string()),
        _ => ("".into(), "".into(), "".into()),
    };
    let note = match &row.outcome {
        Outcome::Invalid(reason) => reason.replace('|', "/"),
        _ => row.fixture.meta.description.replace('|', "/"),
    };
    format!(
        "| {} | {} | {shapes} | {texts} | {deviation} | {note} |",
        row.fixture.name,
        row.result()
    )
}

fn status_markdown(rows: &[Row], source: &Source, options: &CompareOptions) -> String {
    let mut groups: BTreeMap<&str, [usize; 4]> = BTreeMap::new();
    rows.iter().for_each(|row| {
        let counts = groups.entry(group(&row.fixture.name)).or_default();
        counts[0] += 1;
        counts[1] += usize::from(row.fixture.meta.valid);
        counts[2] += usize::from(matches!(row.outcome, Outcome::Compared(_)));
        counts[3] += usize::from(row.result() == "match");
    });
    let mut out = String::new();
    let _ = writeln!(out, "# Fixture status\n");
    let _ = writeln!(
        out,
        "Written by `score-compare` (crate `score-testkit`). Compared against: {}. Tolerance ±{} engine units{}.\n",
        source.label(),
        options.tolerance,
        if options.ignore_staff_numbers {
            ", staff numbers ignored"
        } else {
            ""
        }
    );
    let _ = writeln!(
        out,
        "## Coverage\n\n| group | cases | valid | compared | matching |\n|---|---|---|---|---|"
    );
    groups.iter().for_each(|(name, [cases, valid, compared, matching])| {
        let _ = writeln!(out, "| {name} | {cases} | {valid} | {compared} | {matching} |");
    });
    let _ = writeln!(
        out,
        "\n## Cases\n\nShapes and texts: matched/expected, `+n` = elements the actual list has in excess.\n"
    );
    let _ = writeln!(
        out,
        "| case | result | shapes | texts | max dev | note |\n|---|---|---|---|---|---|"
    );
    rows.iter().for_each(|row| {
        let _ = writeln!(out, "{}", table_line(row));
    });
    out
}

fn write_picture(dir: &Path, row: &Row, actual: Option<&DisplayList>, args: &Args) -> Result<PathBuf, String> {
    let report = match &row.outcome {
        Outcome::Compared(r) => Some(r),
        _ => None,
    };
    let caption = Caption {
        case: &row.fixture.name,
        description: &row.fixture.meta.description,
        actual_label: "rust",
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
    if converted {
        fs::remove_file(&svg_path).map_err(|e| format!("{}: {e}", svg_path.display()))?;
        Ok(png_path)
    } else {
        Ok(svg_path)
    }
}

fn run(args: &Args) -> Result<bool, String> {
    let fixtures = load_all(&args.fixtures).map_err(|e| e.to_string())?;
    let selected: Vec<&Fixture> = fixtures
        .iter()
        .filter(|f| args.patterns.is_empty() || args.patterns.iter().any(|p| glob_match(p, &f.name)))
        .collect();
    if let Some(dir) = &args.images {
        fs::create_dir_all(dir).map_err(|e| format!("{}: {e}", dir.display()))?;
    }
    let mut rows = Vec::with_capacity(selected.len());
    for fixture in selected {
        let actual = actual_for(&args.source, fixture, &fixtures)?;
        let outcome = match &actual {
            _ if !fixture.meta.valid => Outcome::Invalid(fixture.meta.invalid_reasons.join("; ")),
            None => Outcome::NoOutput,
            Some(list) => Outcome::Compared(compare(&fixture.display, list, &args.options)),
        };
        let row = Row { fixture, outcome };
        println!("{:44} {:9} {}", fixture.name, row.result(), summary(&row));
        if let (true, Outcome::Compared(report)) = (args.verbose, &row.outcome) {
            if !report.is_match() {
                print!("{report}");
            }
        }
        if let Some(dir) = &args.images {
            write_picture(dir, &row, actual.as_ref(), args)?;
        }
        rows.push(row);
    }
    if let Some(path) = &args.status {
        fs::write(path, status_markdown(&rows, &args.source, &args.options))
            .map_err(|e| format!("{}: {e}", path.display()))?;
    }
    Ok(rows.iter().all(|row| matches!(row.result(), "match" | "invalid")))
}

fn summary(row: &Row) -> String {
    match &row.outcome {
        Outcome::Compared(r) => format!(
            "shapes {} texts {} max dev {}",
            cell(&r.shapes),
            cell(&r.texts),
            r.max_deviation()
        ),
        Outcome::Invalid(reason) => reason.chars().take(80).collect(),
        Outcome::NoOutput => String::new(),
    }
}

fn main() -> ExitCode {
    let args = match parse_args() {
        Ok(args) => args,
        Err(message) => {
            eprintln!("{message}\n{USAGE}");
            return ExitCode::from(2);
        }
    };
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
