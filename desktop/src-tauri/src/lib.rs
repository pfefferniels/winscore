//! The SCORE editor as a desktop app: the web app (`web/dist`) in the
//! system's web view (WKWebView on macOS), with a native menu bar, file
//! dialogs, files read and written where they are, files opened from the
//! Finder or dropped on the window, and a question before unsaved changes
//! are lost. The page finds these through `window.__TAURI__`
//! (`web/src/desktop.ts`). AI assistants reach the open score through an MCP
//! endpoint ([`mcp`]), or the executable run with `--mcp-stdio` ([`stdio`]).
//! WinScore opens `.mus` files ([`default_app`]).

pub mod default_app;
pub mod mcp;
pub mod settings;
pub mod stdio;

use std::sync::atomic::{AtomicBool, Ordering};
use std::sync::Mutex;

use tauri::ipc::{InvokeBody, Request, Response};
use tauri::menu::{AboutMetadata, Menu, MenuItem, PredefinedMenuItem, Submenu};
use tauri::{AppHandle, DragDropEvent, Emitter, Manager, RunEvent, Runtime, WebviewWindow, WindowEvent};
use tauri_plugin_dialog::{DialogExt, MessageDialogButtons, MessageDialogKind};

/// The label of the editor's window.
pub(crate) const MAIN: &str = "main";

/// Files the system asked the app to open (Finder, Open With, a drop) that
/// the page has not taken yet.
#[derive(Default)]
struct Opened(Mutex<Vec<String>>);

/// The page's part in closing: whether it listens (it asks about unsaved
/// changes first) and whether it has agreed.
#[derive(Default)]
struct Closing {
    page_listens: AtomicBool,
    agreed: AtomicBool,
}

impl Closing {
    /// Whether the window may close now, without asking the page.
    fn may_close(&self) -> bool {
        self.agreed.load(Ordering::SeqCst) || !self.page_listens.load(Ordering::SeqCst)
    }
}

fn path_string(path: std::path::PathBuf) -> String {
    path.to_string_lossy().into_owned()
}

/// A path from the page: `~/…` in the home folder; only absolute paths, the
/// app's own working folder meaning nothing to the person who gave it.
fn resolved(path: &str) -> Result<std::path::PathBuf, String> {
    let path = match path.strip_prefix("~/") {
        Some(rest) => std::path::Path::new(&std::env::var("HOME").map_err(|_| "no home folder to put ~ in")?).join(rest),
        None => std::path::PathBuf::from(path),
    };
    if path.is_absolute() {
        Ok(path)
    } else {
        Err(format!("{}: give the whole path (from /, or ~/…)", path.display()))
    }
}

/// Decodes the `%XX` escapes of `encodeURIComponent`.
fn percent_decoded(text: &str) -> String {
    let bytes = text.as_bytes();
    let mut out = Vec::with_capacity(bytes.len());
    let mut i = 0;
    while i < bytes.len() {
        let hex = |b: u8| (b as char).to_digit(16);
        match (bytes[i], bytes.get(i + 1).copied().and_then(hex), bytes.get(i + 2).copied().and_then(hex)) {
            (b'%', Some(high), Some(low)) => {
                out.push((high * 16 + low) as u8);
                i += 3;
            }
            (byte, _, _) => {
                out.push(byte);
                i += 1;
            }
        }
    }
    String::from_utf8_lossy(&out).into_owned()
}

/// The open panel for `.mus` files; the path chosen.
#[tauri::command]
async fn pick_open(app: AppHandle) -> Option<String> {
    let mut dialog = app.dialog().file().add_filter("SCORE files", &["mus", "MUS"]);
    if let Some(window) = app.get_webview_window(MAIN) {
        dialog = dialog.set_parent(&window);
    }
    dialog.blocking_pick_file().and_then(|file| file.into_path().ok()).map(path_string)
}

/// The save panel for a file `name` with `extension`, a `kind` of file; the path chosen.
#[tauri::command]
async fn pick_save(app: AppHandle, name: String, extension: String, kind: String) -> Option<String> {
    let mut dialog = app.dialog().file().set_file_name(name).add_filter(kind, &[extension.as_str()]);
    if let Some(window) = app.get_webview_window(MAIN) {
        dialog = dialog.set_parent(&window);
    }
    let path = dialog.blocking_save_file().and_then(|file| file.into_path().ok())?;
    // Not every save panel adds the extension to a name typed without one.
    Some(path_string(if path.extension().is_some() { path } else { path.with_extension(extension) }))
}

/// The bytes of the file at `path`, as an `ArrayBuffer` in the page.
#[tauri::command]
fn read_file(path: String) -> Result<Response, String> {
    std::fs::read(resolved(&path)?).map(Response::new).map_err(|err| format!("{path}: {err}"))
}

/// Writes the request's body to the path in its `path` header (URI-encoded).
#[tauri::command]
fn write_file(request: Request<'_>) -> Result<(), String> {
    let path = request
        .headers()
        .get("path")
        .and_then(|value| value.to_str().ok())
        .map(percent_decoded)
        .ok_or("no path to write to")?;
    let InvokeBody::Raw(bytes) = request.body() else {
        return Err("the contents to write must be bytes".into());
    };
    std::fs::write(resolved(&path)?, bytes).map_err(|err| format!("{path}: {err}"))
}

/// The system's alert with `message`, the button `ok` and Cancel; whether `ok` was chosen.
#[tauri::command]
async fn confirm(app: AppHandle, message: String, ok: String) -> bool {
    let mut dialog = app
        .dialog()
        .message(message)
        .title("WinScore")
        .kind(MessageDialogKind::Warning)
        .buttons(MessageDialogButtons::OkCancelCustom(ok, "Cancel".into()));
    if let Some(window) = app.get_webview_window(MAIN) {
        dialog = dialog.parent(&window);
    }
    dialog.blocking_show()
}

#[tauri::command]
fn set_title(window: WebviewWindow, title: String) {
    let _ = window.set_title(&title);
}

/// The files opened from outside the page since it last asked.
#[tauri::command]
fn opened_files(opened: tauri::State<'_, Opened>) -> Vec<String> {
    std::mem::take(&mut *opened.0.lock().unwrap_or_else(|poisoned| poisoned.into_inner()))
}

/// The page listens for `close-requested` (and asks about unsaved changes)
/// and for MCP requests.
#[tauri::command]
fn page_ready(closing: tauri::State<'_, Closing>, mcp: tauri::State<'_, mcp::Mcp>) {
    closing.page_listens.store(true, Ordering::SeqCst);
    mcp.page_ready();
}

/// Makes WinScore the app that opens .mus files; what happened, in words.
#[tauri::command]
fn make_default(app: AppHandle) -> Result<String, String> {
    default_app::set_default(&app.config().identifier)?;
    settings::update(&app, |s| s.default_app_set = true);
    Ok("WinScore now opens .mus files".into())
}

/// The page agreed to close: the app quits.
#[tauri::command]
fn close_window(app: AppHandle) {
    app.state::<Closing>().agreed.store(true, Ordering::SeqCst);
    app.exit(0);
}

/// Keeps `paths` (the `.mus` files among them) for the page and tells it.
fn open_paths<R: Runtime>(app: &AppHandle<R>, paths: impl IntoIterator<Item = std::path::PathBuf>) {
    let scores: Vec<String> = paths
        .into_iter()
        .filter(|path| path.extension().is_some_and(|ext| ext.eq_ignore_ascii_case("mus")))
        .map(path_string)
        .collect();
    if scores.is_empty() {
        return;
    }
    app.state::<Opened>().0.lock().unwrap_or_else(|poisoned| poisoned.into_inner()).extend(scores);
    let _ = app.emit_to(MAIN, "opened", ());
    if let Some(window) = app.get_webview_window(MAIN) {
        let _ = window.set_focus();
    }
}

/// The menu bar: the app's commands go to the page as `menu` events by id;
/// the Edit menu's clipboard items are the system's, for text fields.
fn menu<R: Runtime>(app: &AppHandle<R>) -> tauri::Result<Menu<R>> {
    let item = |id: &str, text: &str, keys: Option<&str>| MenuItem::with_id(app, id, text, true, keys);
    let separator = || PredefinedMenuItem::separator(app);
    let about = AboutMetadata {
        name: Some("WinScore".into()),
        comments: Some("An editor for scores in Leland Smith's SCORE format".into()),
        ..Default::default()
    };
    let app_menu = Submenu::with_items(
        app,
        "WinScore",
        true,
        &[
            &PredefinedMenuItem::about(app, Some("About WinScore"), Some(about))?,
            &separator()?,
            &item("default-app", "Open .mus Files with WinScore", None)?,
            &separator()?,
            &PredefinedMenuItem::services(app, None)?,
            &separator()?,
            &PredefinedMenuItem::hide(app, None)?,
            &PredefinedMenuItem::hide_others(app, None)?,
            &PredefinedMenuItem::show_all(app, None)?,
            &separator()?,
            // The app's own Quit: the system's ends the app before the page can ask about unsaved changes.
            &item("quit", "Quit WinScore", Some("CmdOrCtrl+Q"))?,
        ],
    )?;
    let file = Submenu::with_items(
        app,
        "File",
        true,
        &[
            &item("new", "New Score", Some("CmdOrCtrl+N"))?,
            &item("open", "Open…", Some("CmdOrCtrl+O"))?,
            &separator()?,
            &item("save", "Save", Some("CmdOrCtrl+S"))?,
            &item("save-as", "Save As…", Some("CmdOrCtrl+Shift+S"))?,
            &item("export-svg", "Export SVG…", Some("CmdOrCtrl+E"))?,
            &separator()?,
            &item("print", "Print…", Some("CmdOrCtrl+P"))?,
            &separator()?,
            &PredefinedMenuItem::close_window(app, None)?,
        ],
    )?;
    let edit = Submenu::with_items(
        app,
        "Edit",
        true,
        &[
            &item("undo", "Undo", Some("CmdOrCtrl+Z"))?,
            &item("redo", "Redo", Some("CmdOrCtrl+Shift+Z"))?,
            &separator()?,
            &PredefinedMenuItem::cut(app, None)?,
            &PredefinedMenuItem::copy(app, None)?,
            &PredefinedMenuItem::paste(app, None)?,
            &item("duplicate", "Duplicate", Some("CmdOrCtrl+D"))?,
            &item("delete", "Delete", None)?,
            &PredefinedMenuItem::select_all(app, None)?,
        ],
    )?;
    let view = Submenu::with_items(
        app,
        "View",
        true,
        &[
            &item("zoom-in", "Zoom In", Some("CmdOrCtrl+="))?,
            &item("zoom-out", "Zoom Out", Some("CmdOrCtrl+-"))?,
            &item("actual-size", "Actual Size", Some("CmdOrCtrl+0"))?,
            &item("fit", "Fit Width", Some("CmdOrCtrl+9"))?,
            &separator()?,
            &item("panel", "Side Panel", Some("CmdOrCtrl+Alt+P"))?,
            &separator()?,
            &PredefinedMenuItem::fullscreen(app, None)?,
        ],
    )?;
    let window = Submenu::with_items(
        app,
        "Window",
        true,
        &[&PredefinedMenuItem::minimize(app, None)?, &PredefinedMenuItem::maximize(app, None)?],
    )?;
    let help = Submenu::with_items(
        app,
        "Help",
        true,
        &[&item("shortcuts", "Commands, Keys and Gestures", Some("F1"))?, &item("mcp", "AI Assistants (MCP)…", None)?],
    )?;
    Menu::with_items(app, &[&app_menu, &file, &edit, &view, &window, &help])
}

pub fn run() {
    let app = tauri::Builder::default()
        .plugin(tauri_plugin_dialog::init())
        .manage(Opened::default())
        .manage(Closing::default())
        .manage(mcp::Mcp::default())
        .menu(menu)
        .setup(|app| {
            let handle = app.handle();
            let settings = settings::load(handle);
            if !settings.mcp_off {
                mcp::start(handle);
            }
            // Once: the app that opens .mus files from now on, unless the person chooses another one later.
            if cfg!(target_os = "macos") && !settings.default_app_set && default_app::set_default(&handle.config().identifier).is_ok() {
                settings::update(handle, |s| s.default_app_set = true);
            }
            Ok(())
        })
        .on_menu_event(|app, event| match event.id().as_ref() {
            "quit" if app.state::<Closing>().may_close() => app.exit(0),
            "quit" => {
                let _ = app.emit_to(MAIN, "close-requested", ());
            }
            id => {
                let _ = app.emit_to(MAIN, "menu", id);
            }
        })
        .on_window_event(|window, event| match event {
            WindowEvent::CloseRequested { api, .. } => {
                if !window.state::<Closing>().may_close() {
                    api.prevent_close();
                    let _ = window.emit("close-requested", ());
                }
            }
            WindowEvent::DragDrop(drop) => match drop {
                DragDropEvent::Enter { .. } => {
                    let _ = window.emit("dragging", true);
                }
                DragDropEvent::Leave => {
                    let _ = window.emit("dragging", false);
                }
                DragDropEvent::Drop { paths, .. } => {
                    let _ = window.emit("dragging", false);
                    open_paths(window.app_handle(), paths.clone());
                }
                _ => {}
            },
            _ => {}
        })
        .invoke_handler(tauri::generate_handler![
            pick_open,
            pick_save,
            read_file,
            write_file,
            confirm,
            set_title,
            opened_files,
            page_ready,
            close_window,
            make_default,
            mcp::mcp_respond,
            mcp::mcp_status,
            mcp::mcp_enable,
        ])
        .build(tauri::generate_context!())
        .expect("the app starts");
    app.run(|app, event| match event {
        // Quitting (⌘Q) asks the page about unsaved changes, as closing the window does.
        RunEvent::ExitRequested { code: None, api, .. } if !app.state::<Closing>().may_close() => {
            api.prevent_exit();
            let _ = app.emit_to(MAIN, "close-requested", ());
        }
        #[cfg(any(target_os = "macos", target_os = "ios"))]
        RunEvent::Opened { urls } => open_paths(app, urls.into_iter().filter_map(|url| url.to_file_path().ok())),
        _ => {}
    });
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn paths_come_back_from_the_page_as_they_were() {
        assert_eq!(percent_decoded("%2FUsers%2Fn%2FNoten%2FM%C3%BCller%20Sonate.mus"), "/Users/n/Noten/Müller Sonate.mus");
        assert_eq!(percent_decoded("plain.mus"), "plain.mus");
        assert_eq!(percent_decoded("100%"), "100%");
    }
}
