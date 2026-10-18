//! Command-line front end of the SCORE renderer.

use std::path::PathBuf;
use std::process::ExitCode;

use score_format::MusFile;
use score_render::svg::{to_svg, SvgOptions, Viewport};
use score_render::{render, Colour, DisplayList, Document, Medium, Options, Point, ShapeKind};

const USAGE: &str = "usage: score-cli render <in.mus> [-o <out.svg>] [--fit] [--stroke <units>] [--print] [--no-staff-numbers]
       score-cli dump <in.mus> [-o <out.txt>] [--print] [--no-staff-numbers]

  render               draw the page as SVG (page coordinates, y flipped)
  dump                 list the display list, one shape or text run per line
  -o <path>            write here instead of standard output
  --fit                crop to the drawing instead of showing the whole paper
  --stroke <units>     width of the default pen in engine units (default: 1/150 inch)
  --print              leave out screen aids (staff numbers, invisible items)
  --no-staff-numbers   leave out the staff numbers only";

/// Margin around the drawing for `--fit`: an eighth of an inch.
const FIT_MARGIN: i32 = 500;

#[derive(Debug, Clone, Copy, PartialEq, Eq, Default)]
enum Command {
    #[default]
    Render,
    Dump,
}

#[derive(Debug)]
struct Args {
    command: Command,
    input: PathBuf,
    output: Option<PathBuf>,
    options: Options,
    fit: bool,
    stroke: Option<f64>,
}

fn parse(args: &[String]) -> Result<Args, String> {
    let (command, rest) = args.split_first().ok_or(USAGE)?;
    let mut parsed = Args {
        command: match command.as_str() {
            "render" => Command::Render,
            "dump" => Command::Dump,
            other => return Err(format!("unknown command {other:?}\n{USAGE}")),
        },
        input: PathBuf::new(),
        output: None,
        options: Options::default(),
        fit: false,
        stroke: None,
    };
    let mut input = None;
    let mut words = rest.iter();
    while let Some(word) = words.next() {
        match word.as_str() {
            "-o" => parsed.output = Some(words.next().ok_or("-o needs a path")?.into()),
            "--fit" => parsed.fit = true,
            "--stroke" => {
                let value = words.next().ok_or("--stroke needs a width")?;
                parsed.stroke = Some(value.parse().map_err(|_| format!("bad stroke width {value:?}"))?);
            }
            "--print" => parsed.options.medium = Medium::Print,
            "--no-staff-numbers" => parsed.options.staff_numbers = false,
            flag if flag.starts_with('-') => return Err(format!("unknown option {flag}\n{USAGE}")),
            path if input.is_none() => input = Some(PathBuf::from(path)),
            extra => return Err(format!("unexpected argument {extra:?}\n{USAGE}")),
        }
    }
    parsed.input = input.ok_or(USAGE)?;
    Ok(parsed)
}

fn svg(list: &DisplayList, doc: &Document<'_>, args: &Args) -> String {
    let paper = Viewport::paper(doc.page.paper);
    let view = if args.fit { Viewport::around(list, FIT_MARGIN).unwrap_or(paper) } else { paper };
    let mut options = SvgOptions::new(view);
    options.stroke_width = args.stroke.unwrap_or(options.stroke_width);
    to_svg(list, &options)
}

fn hex(colour: Colour) -> String {
    format!("#{:02x}{:02x}{:02x}", colour.r, colour.g, colour.b)
}

fn points(path: &[Point]) -> String {
    path.iter().map(|p| format!("{},{}", p.x, p.y)).collect::<Vec<_>>().join(" ")
}

fn item_label(source: Option<score_render::ItemId>) -> String {
    source.map_or_else(|| "-".to_string(), |id| id.0.to_string())
}

/// One line per shape (`S` stroke, `F` fill, sub-paths separated by `|`) and per text run (`T`).
fn dump(list: &DisplayList) -> String {
    let shapes = list.shapes.iter().map(|s| {
        let kind = match s.kind {
            ShapeKind::Stroke => 'S',
            ShapeKind::Fill => 'F',
        };
        let paths = s.paths.iter().map(|p| points(p)).collect::<Vec<_>>().join(" | ");
        let width = if s.width != 0.0 { format!(" w={}", s.width) } else { String::new() };
        format!("{kind} item={} {}{width} {paths}\n", item_label(s.source), hex(s.colour))
    });
    let texts = list.texts.iter().map(|t| {
        let strings = t.strings.iter().map(|s| format!("{},{} {:?}", s.origin.x, s.origin.y, s.text));
        format!(
            "T item={} {} {:?} h={} w={} esc={} weight={}{} {}\n",
            item_label(t.source),
            hex(t.colour),
            t.font,
            t.height,
            t.width,
            t.escapement,
            t.weight,
            if t.outline { " outline" } else { "" },
            strings.collect::<Vec<_>>().join(" ")
        )
    });
    shapes.chain(texts).collect()
}

fn run(args: &Args) -> Result<(), String> {
    let bytes = std::fs::read(&args.input).map_err(|e| format!("{}: {e}", args.input.display()))?;
    let file = MusFile::parse(&bytes).map_err(|e| format!("{}: {e}", args.input.display()))?;
    let doc = Document::with_options(&file, args.options);
    let list = render(&doc);
    let text = match args.command {
        Command::Render => svg(&list, &doc, args),
        Command::Dump => dump(&list),
    };
    match &args.output {
        Some(path) => std::fs::write(path, text).map_err(|e| format!("{}: {e}", path.display())),
        None => {
            print!("{text}");
            Ok(())
        }
    }
}

fn main() -> ExitCode {
    let args: Vec<String> = std::env::args().skip(1).collect();
    match parse(&args).and_then(|parsed| run(&parsed)) {
        Ok(()) => ExitCode::SUCCESS,
        Err(message) => {
            eprintln!("{message}");
            ExitCode::FAILURE
        }
    }
}
