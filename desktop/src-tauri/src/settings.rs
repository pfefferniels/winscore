//! The app's settings, kept in `settings.json` in its configuration folder
//! (on macOS `~/Library/Application Support/io.github.pfefferniels.winscore`).

use serde::{Deserialize, Serialize};
use tauri::{AppHandle, Manager, Runtime};

#[derive(Debug, Default, Serialize, Deserialize)]
#[serde(default, rename_all = "camelCase")]
pub struct Settings {
    /// The MCP endpoint was turned off.
    pub mcp_off: bool,
    /// WinScore has made itself the app that opens .mus files once already.
    pub default_app_set: bool,
}

fn path<R: Runtime>(app: &AppHandle<R>) -> Option<std::path::PathBuf> {
    app.path().app_config_dir().ok().map(|dir| dir.join("settings.json"))
}

pub fn load<R: Runtime>(app: &AppHandle<R>) -> Settings {
    path(app).and_then(|path| std::fs::read(path).ok()).and_then(|bytes| serde_json::from_slice(&bytes).ok()).unwrap_or_default()
}

/// Changes the settings and writes them; a failure to write leaves them as they were on disk.
pub fn update<R: Runtime>(app: &AppHandle<R>, change: impl FnOnce(&mut Settings)) {
    let mut settings = load(app);
    change(&mut settings);
    if let (Some(path), Ok(json)) = (path(app), serde_json::to_vec_pretty(&settings)) {
        if let Some(dir) = path.parent() {
            let _ = std::fs::create_dir_all(dir);
        }
        let _ = std::fs::write(path, json);
    }
}
