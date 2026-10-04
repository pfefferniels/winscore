//! Groups the differences between `score_render` and the engine by item code
//! and symptom, for whole pages (`--help` lists the options).

use std::collections::BTreeMap;
use std::fmt::Write as _;
use std::fs;
use std::panic;
use std::path::PathBuf;
use std::process::ExitCode;

use score_format::Item;
use score_render::{ItemId, Point};
use score_testkit::triage::{triage, Finding, Symptom};
use score_testkit::{
    compare, fixtures_dir, load_all, render_fixture, restrict, CompareOptions, Fixture, Report,
};

const USAGE: &str = "\
score-triage [OPTIONS] [PATTERN ...]
  --fixtures DIR   fixture directory (default: rust/fixtures)
  --out FILE       report (default: <fixtures>/TRIAGE.md; \"-\" prints it)
  --examples N     example items per group (default 6)
PATTERN selects cases by name, * matches any characters (default: sample-*).";

struct Args {
    fixtures: PathBuf,
    out: Option<PathBuf>,
    examples: usize,
    patterns: Vec<String>,
}

fn parse_args() -> Result<Args, String> {
    let mut args = Args {
        fixtures: fixtures_dir(),
        out: None,
        examples: 6,
        patterns: vec![],
    };
    let mut out: Option<String> = None;
    let mut it = std::env::args().skip(1);
    while let Some(arg) = it.next() {
        let mut value = |name: &str| it.next().ok_or(format!("{name} needs a value"));
        match arg.as_str() {
            "--fixtures" => args.fixtures = value("--fixtures")?.into(),
            "--out" => out = Some(value("--out")?),
            "--examples" => {
                args.examples = value("--examples")?
                    .parse()
                    .map_err(|e| format!("--examples: {e}"))?
            }
            "--help" | "-h" => return Err(String::new()),
            flag if flag.starts_with("--") => return Err(format!("unknown option {flag}")),
            pattern => args.patterns.push(pattern.to_string()),
        }
    }
    if args.patterns.is_empty() {
        args.patterns.push("sample-*".into());
    }
    args.out = match out.as_deref() {
        Some("-") => None,
        Some(path) => Some(path.into()),
        None => Some(args.fixtures.join("TRIAGE.md")),
    };
    Ok(args)
}

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

// -- describing items --------------------------------------------------------------

fn number(value: f32) -> String {
    let text = format!("{value:.3}");
    text.trim_end_matches('0').trim_end_matches('.').to_string()
}

/// P1 … Pn without trailing zeros, and the characters of a text item.
fn item_line(item: &Item) -> String {
    let params: Vec<f32> = item.params().iter().map(|w| w.as_f32()).collect();
    let used = params.iter().rposition(|&p| p != 0.0).map_or(0, |i| i + 1);
    let mut line = params[..used]
        .iter()
        .map(|&p| number(p))
        .collect::<Vec<_>>()
        .join(" ");
    if !item.text().is_empty() {
        let _ = write!(line, " {:?}", String::from_utf8_lossy(item.text()));
    }
    line
}

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
        .map_or("unattributed", |(_, name)| name)
}

// -- grouping ----------------------------------------------------------------------

/// The findings of one (code, symptom) pair.
#[derive(Default)]
struct Group<'a> {
    findings: Vec<&'a Finding>,
}

impl Group<'_> {
    fn items(&self) -> BTreeMap<Option<ItemId>, Vec<&Finding>> {
        let mut items: BTreeMap<Option<ItemId>, Vec<&Finding>> = BTreeMap::new();
        self.findings
            .iter()
            .for_each(|f| items.entry(f.item).or_default().push(f));
        items
    }

    /// The most frequent translations, as "(dx, dy) ×n".
    fn common_deltas(&self, shown: usize) -> String {
        let mut counts: BTreeMap<(i32, i32), usize> = BTreeMap::new();
        self.findings
            .iter()
            .filter_map(|f| f.delta)
            .for_each(|Point { x, y }| *counts.entry((x, y)).or_default() += 1);
        let mut ranked: Vec<_> = counts.into_iter().collect();
        ranked.sort_by_key(|&(delta, n)| (std::cmp::Reverse(n), delta));
        ranked
            .iter()
            .take(shown)
            .map(|((x, y), n)| format!("({x}, {y}) ×{n}"))
            .collect::<Vec<_>>()
            .join(", ")
    }
}

struct Page<'a> {
    fixture: &'a Fixture,
    items: Vec<Item>,
    report: Report,
    findings: Vec<Finding>,
}

impl Page<'_> {
    fn code(&self, item: Option<ItemId>) -> i32 {
        item.and_then(|ItemId(i)| self.items.get(i as usize))
            .map_or(0, Item::code)
    }

    fn groups(&self) -> BTreeMap<(i32, Symptom), Group<'_>> {
        let mut groups: BTreeMap<(i32, Symptom), Group> = BTreeMap::new();
        self.findings.iter().for_each(|f| {
            groups
                .entry((self.code(f.item), f.symptom))
                .or_default()
                .findings
                .push(f)
        });
        groups
    }
}

fn analyse<'a>(fixture: &'a Fixture, options: &CompareOptions) -> Result<Page<'a>, String> {
    let actual = render_fixture(fixture)?;
    let items = fixture.input().map_err(|e| e.to_string())?.items;
    let report = compare(&fixture.display, &actual, options);
    let findings = triage(&fixture.display, &actual, &report, options);
    Ok(Page {
        fixture,
        items,
        report,
        findings,
    })
}

// -- report ------------------------------------------------------------------------

/// Per item code: how many of its own fixtures (`codeNN-*`) match in that code's items.
type CodeStatus = BTreeMap<i32, (usize, usize)>;

fn fixture_code(fixture: &Fixture) -> Option<i32> {
    fixture.name.strip_prefix("code")?.get(..2)?.parse().ok()
}

fn code_status(fixtures: &[Fixture], options: &CompareOptions) -> CodeStatus {
    let mut status = CodeStatus::new();
    for (fixture, code) in fixtures
        .iter()
        .filter_map(|f| fixture_code(f).map(|c| (f, c)))
    {
        let (Ok(actual), Ok(file)) = (render_fixture(fixture), fixture.input()) else {
            continue;
        };
        let keep = |ItemId(i): ItemId| {
            file.items
                .get(i as usize)
                .is_some_and(|it| it.code() == code)
        };
        let report = compare(
            &restrict(&fixture.display, keep),
            &restrict(&actual, keep),
            options,
        );
        let entry = status.entry(code).or_default();
        *entry = (entry.0 + usize::from(report.is_match()), entry.1 + 1);
    }
    status
}

fn count_table(groups: &BTreeMap<(i32, Symptom), usize>, status: Option<&CodeStatus>) -> String {
    let codes: std::collections::BTreeSet<i32> = groups.keys().map(|&(c, _)| c).collect();
    let used: Vec<Symptom> = Symptom::ALL
        .iter()
        .copied()
        .filter(|s| groups.keys().any(|(_, g)| g == s))
        .collect();
    let labels: Vec<&str> = used.iter().map(|s| s.label()).collect();
    let (own_head, own_rule) = if status.is_some() {
        (" own fixtures matching |", "---|")
    } else {
        ("", "")
    };
    let mut out = format!(
        "| code | |{own_head} {} |\n|---|---|{own_rule}{}\n",
        labels.join(" | "),
        "---|".repeat(used.len())
    );
    codes.iter().for_each(|code| {
        let cells: Vec<String> = used
            .iter()
            .map(|s| {
                groups
                    .get(&(*code, *s))
                    .map_or(String::new(), |n| n.to_string())
            })
            .collect();
        let own = status.map_or(String::new(), |status| {
            let (matching, total) = status.get(code).copied().unwrap_or_default();
            format!(" {matching}/{total} |")
        });
        let _ = writeln!(
            out,
            "| {code} | {} |{own} {} |",
            code_name(*code),
            cells.join(" | ")
        );
    });
    out
}

fn page_section(page: &Page, examples: usize) -> String {
    let mut out = String::new();
    let r = &page.report;
    let _ = writeln!(
        out,
        "## {}\n\n{}. Shapes {}/{} matched, {} extra; texts {}/{} matched, {} extra.\n",
        page.fixture.name,
        page.fixture.meta.description,
        r.shapes.matched,
        r.shapes.expected,
        r.shapes.extra.len(),
        r.texts.matched,
        r.texts.expected,
        r.texts.extra.len()
    );
    let groups = page.groups();
    if groups.is_empty() {
        out.push_str("No differences.\n\n");
        return out;
    }
    let counts = groups
        .iter()
        .map(|(&key, g)| (key, g.findings.len()))
        .collect();
    let _ = writeln!(
        out,
        "Unmatched elements by source code and symptom:\n\n{}",
        count_table(&counts, None)
    );
    for ((code, symptom), group) in &groups {
        let items = group.items();
        let deltas = group.common_deltas(4);
        let _ = writeln!(
            out,
            "**{code} {} – {symptom}**: {} element(s) of {} item(s){}",
            code_name(*code),
            group.findings.len(),
            items.len(),
            if deltas.is_empty() {
                String::new()
            } else {
                format!("; commonest shifts {deltas}")
            }
        );
        out.push('\n');
        items.iter().take(examples).for_each(|(item, findings)| {
            let line = item
                .and_then(|ItemId(i)| {
                    page.items
                        .get(i as usize)
                        .map(|it| format!("#{i} `{}`", item_line(it)))
                })
                .unwrap_or_else(|| "no item".into());
            let more = if findings.len() > 1 {
                format!(" (+{} more)", findings.len() - 1)
            } else {
                String::new()
            };
            let _ = writeln!(out, "- {line}: {}{more}", findings[0].detail);
        });
        if items.len() > examples {
            let _ = writeln!(out, "- … {} more item(s)", items.len() - examples);
        }
        out.push('\n');
    }
    out
}

fn run(args: &Args) -> Result<(), String> {
    let options = CompareOptions::default();
    let fixtures = load_all(&args.fixtures).map_err(|e| e.to_string())?;
    let selected: Vec<&Fixture> = fixtures
        .iter()
        .filter(|f| args.patterns.iter().any(|p| glob_match(p, &f.name)))
        .collect();
    let pages: Vec<Page> = selected
        .iter()
        .map(|f| analyse(f, &options))
        .collect::<Result<_, _>>()?;
    let mut totals: BTreeMap<(i32, Symptom), usize> = BTreeMap::new();
    pages
        .iter()
        .flat_map(|p| p.groups().into_iter().map(|(k, g)| (k, g.findings.len())))
        .for_each(|(k, n)| {
            *totals.entry(k).or_default() += n;
        });
    let mut out = String::from(
        "# Sample triage\n\nWritten by `score-triage` (crate `score-testkit`): every element the engine drew and \
         `score_render` did not (or the reverse), attributed to its source item and paired with an unmatched element \
         of the same item on the other side. Symptoms: *absent* = nothing drawn for the item; *missing* = item drawn, \
         element without counterpart; *offset* = same shape translated (shift = Rust minus engine, engine units, y up); \
         *colour* = same place, other colour; *distorted* = same structure, other geometry; *extra* = only in Rust. \
         Item lines give P1 … Pn.\n\n",
    );
    let notes = args.fixtures.join("triage-notes.md");
    if let Ok(text) = fs::read_to_string(&notes) {
        let _ = writeln!(out, "{}\n", text.trim_end());
    }
    let status = code_status(&fixtures, &options);
    let _ = writeln!(
        out,
        "## All selected pages\n\nUnmatched elements by source code and symptom. *Own fixtures matching*: \
         `codeNN-*` fixtures in which every element drawn by a code-NN item matches.\n\n{}",
        count_table(&totals, Some(&status))
    );
    pages
        .iter()
        .for_each(|page| out.push_str(&page_section(page, args.examples)));
    match &args.out {
        Some(path) => fs::write(path, out).map_err(|e| format!("{}: {e}", path.display()))?,
        None => print!("{out}"),
    }
    pages.iter().for_each(|p| {
        println!("{:24} {} finding(s)", p.fixture.name, p.findings.len());
    });
    Ok(())
}

fn main() -> ExitCode {
    let args = match parse_args() {
        Ok(args) => args,
        Err(message) => {
            eprintln!("{message}\n{USAGE}");
            return ExitCode::from(2);
        }
    };
    panic::set_hook(Box::new(|_| {}));
    match run(&args) {
        Ok(()) => ExitCode::SUCCESS,
        Err(message) => {
            eprintln!("score-triage: {message}");
            ExitCode::from(2)
        }
    }
}
