//! Prints the items score-input makes from an input file, one item per line, and with a
//! second argument (an engine result .mus) the engine's items next to them where they differ.
//!
//!     cargo run -p score-input --example input_items -- CASE/input.txt [CASE/result.mus]

use std::fs;

use score_format::{Item, MusFile};
use score_input::InputFile;

fn format(item: Option<&Item>) -> String {
    item.map_or_else(String::new, |item| {
        item.params().iter().map(|w| format!("{}", w.as_f32())).collect::<Vec<_>>().join(" ")
    })
}

fn main() {
    let args: Vec<String> = std::env::args().skip(1).collect();
    let text = fs::read_to_string(&args[0]).expect("input file");
    let ours = InputFile::parse(&text).expect("input file layout").items().unwrap_or_else(|err| {
        eprintln!("{err}");
        Vec::new()
    });
    let engine = args.get(1).map(|path| MusFile::parse(&fs::read(path).expect("result file")).expect("mus").items);
    let rows = ours.len().max(engine.as_ref().map_or(0, Vec::len));
    for i in 0..rows {
        let mine = format(ours.get(i));
        match engine.as_ref().map(|e| format(e.get(i))) {
            Some(theirs) if theirs != mine => println!("{:3} ours   {mine}\n    engine {theirs}", i + 1),
            _ => println!("{:3}        {mine}", i + 1),
        }
    }
}
