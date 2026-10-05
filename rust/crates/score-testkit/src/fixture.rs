//! Loading the reference fixtures that `oracle/fixtures.py` writes to
//! `rust/fixtures/<case>/`.

use std::fmt;
use std::fs;
use std::io;
use std::path::{Path, PathBuf};

use score_format::{MusError, MusFile};
use score_render::DisplayList;
use serde::Deserialize;

use crate::json::display_from_json;

/// The fixture directory of this repository.
pub fn fixtures_dir() -> PathBuf {
    Path::new(env!("CARGO_MANIFEST_DIR")).join("../../fixtures")
}

#[derive(Debug, Clone, Deserialize)]
pub struct CommandMeta {
    pub command: String,
    pub status: i32,
    pub line: String,
    pub vector_words: usize,
    pub text_bytes: usize,
}

/// `meta.json`: how the reference was produced and whether it can be trusted.
#[derive(Debug, Clone, Deserialize)]
pub struct Meta {
    pub case: String,
    pub description: String,
    pub commands: Vec<CommandMeta>,
    pub items: Option<u32>,
    pub paper: Option<String>,
    /// Paper size in engine units.
    pub page_size: Option<[i32; 2]>,
    /// The engine's view coordinates are page coordinates plus this offset.
    pub view_offset: Option<[i32; 2]>,
    pub valid: bool,
    #[serde(default)]
    pub invalid_reasons: Vec<String>,
    #[serde(default)]
    pub warnings: Vec<String>,
    /// Items of the drawn file that the engine did not keep on load (codes 0 and 13, for instance).
    #[serde(default)]
    pub dropped_items: Vec<u32>,
}

#[derive(Debug)]
pub enum FixtureError {
    Io(PathBuf, io::Error),
    Json(PathBuf, serde_json::Error),
    Mus(PathBuf, MusError),
}

impl fmt::Display for FixtureError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        match self {
            FixtureError::Io(path, err) => write!(f, "{}: {err}", path.display()),
            FixtureError::Json(path, err) => write!(f, "{}: {err}", path.display()),
            FixtureError::Mus(path, err) => write!(f, "{}: {err}", path.display()),
        }
    }
}

impl std::error::Error for FixtureError {}

fn read(path: &Path) -> Result<String, FixtureError> {
    fs::read_to_string(path).map_err(|e| FixtureError::Io(path.to_owned(), e))
}

/// One case: the input score, the engine's display list and how it was made.
#[derive(Debug, Clone)]
pub struct Fixture {
    pub name: String,
    pub dir: PathBuf,
    /// The engine's output in page coordinates (origin at the bottom-left paper corner).
    pub display: DisplayList,
    pub meta: Meta,
}

impl Fixture {
    pub fn load(dir: &Path) -> Result<Fixture, FixtureError> {
        let engine = dir.join("engine.json");
        let meta = dir.join("meta.json");
        let display =
            display_from_json(&read(&engine)?).map_err(|e| FixtureError::Json(engine, e))?;
        let meta: Meta =
            serde_json::from_str(&read(&meta)?).map_err(|e| FixtureError::Json(meta, e))?;
        let name = dir
            .file_name()
            .map(|n| n.to_string_lossy().into_owned())
            .unwrap_or_default();
        Ok(Fixture {
            name,
            dir: dir.to_owned(),
            display,
            meta,
        })
    }

    /// A case of this repository's fixture directory by name.
    pub fn named(name: &str) -> Result<Fixture, FixtureError> {
        Fixture::load(&fixtures_dir().join(name))
    }

    pub fn input_path(&self) -> PathBuf {
        self.dir.join("input.mus")
    }

    /// The score the engine drew: `result.mus` when the case ran commands that
    /// change items (layout), else `input.mus`. Item indices in `display` refer to it.
    pub fn drawn_path(&self) -> PathBuf {
        let result = self.dir.join("result.mus");
        if result.is_file() {
            result
        } else {
            self.input_path()
        }
    }

    /// The score the engine drew, see [`Fixture::drawn_path`].
    pub fn input(&self) -> Result<MusFile, FixtureError> {
        let path = self.drawn_path();
        let bytes = fs::read(&path).map_err(|e| FixtureError::Io(path.clone(), e))?;
        MusFile::parse(&bytes).map_err(|e| FixtureError::Mus(path, e))
    }
}

/// Every fixture below `root`, sorted by name.
pub fn load_all(root: &Path) -> Result<Vec<Fixture>, FixtureError> {
    let entries = fs::read_dir(root).map_err(|e| FixtureError::Io(root.to_owned(), e))?;
    let mut dirs: Vec<PathBuf> = entries
        .filter_map(Result::ok)
        .map(|entry| entry.path())
        .filter(|path| path.join("engine.json").is_file())
        .collect();
    dirs.sort();
    dirs.iter().map(|dir| Fixture::load(dir)).collect()
}
