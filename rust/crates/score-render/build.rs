//! Embeds WinScore's symbol libraries (`scorlib/LBnnnn.DRW`) for `symbols::SymbolLibrary::bundled`.

use std::path::{Path, PathBuf};
use std::{env, fs};

/// The file's first symbol number, from a name like `LB0010.DRW`.
fn first_symbol(path: &Path) -> Option<i32> {
    let name = path.file_name()?.to_str()?.to_ascii_uppercase();
    let digits = name.strip_prefix("LB")?.strip_suffix(".DRW")?;
    digits.parse().ok()
}

fn library_files(scorlib: &Path) -> Vec<(i32, PathBuf)> {
    let mut files: Vec<(i32, PathBuf)> = fs::read_dir(scorlib)
        .unwrap_or_else(|e| panic!("{}: {e}", scorlib.display()))
        .filter_map(Result::ok)
        .map(|entry| entry.path())
        .filter_map(|path| Some((first_symbol(&path)?, fs::canonicalize(&path).ok()?)))
        .collect();
    files.sort();
    files
}

fn main() {
    let scorlib = Path::new(env!("CARGO_MANIFEST_DIR")).join("../../../assets/scorlib");
    println!("cargo:rerun-if-changed={}", scorlib.display());
    let files = if env::var_os("CARGO_FEATURE_BUNDLED_SYMBOLS").is_some() { library_files(&scorlib) } else { Vec::new() };
    let entries: String = files
        .iter()
        .map(|(number, path)| format!("    ({number}, include_bytes!({:?})),\n", path.display().to_string()))
        .collect();
    let code = format!("/// (first symbol number, file contents) of every bundled library.\npub(crate) const BUNDLED: &[(i32, &[u8])] = &[\n{entries}];\n");
    let out = PathBuf::from(env::var("OUT_DIR").expect("cargo sets OUT_DIR")).join("bundled_symbols.rs");
    fs::write(&out, code).unwrap_or_else(|e| panic!("{}: {e}", out.display()));
}
