//! The MCP (Model Context Protocol) endpoint: AI assistants such as Claude
//! Code read and edit the score open in the window through it, over the
//! protocol's Streamable HTTP transport at `http://127.0.0.1:7341/mcp`
//! (`WINSCORE_MCP_PORT` sets another port).
//!
//! The app only carries the messages: each JSON-RPC message goes to the page
//! as an `mcp-request` event, and the page (`web/src/mcp.ts`) answers it with
//! the editor and sends the answer back with [`mcp_respond`]. The endpoint
//! answers on this computer only, and not to web pages: it listens on the
//! loopback address, takes only its own host names (against DNS rebinding),
//! no origin but local ones, and JSON bodies (which a page cannot send
//! across origins without asking first).

use std::collections::HashMap;
use std::io::Read;
use std::sync::atomic::{AtomicBool, AtomicU64, Ordering};
use std::sync::{mpsc, Arc, Mutex, MutexGuard};
use std::time::{Duration, Instant};

use serde::Serialize;
use serde_json::{json, Value};
use tauri::{AppHandle, Emitter, Manager, Runtime, State};
use tiny_http::{Header, Method, Request, Response, Server};

use crate::{settings, MAIN};

pub const DEFAULT_PORT: u16 = 7341;
const PATH: &str = "/mcp";
const MAX_BODY: u64 = 32 << 20;
/// How long a tool may take in the page (a large file opening, a page rendering).
const PAGE_TIMEOUT: Duration = Duration::from_secs(120);
/// How long a request waits for the page to start (the app started by the stdio bridge).
const STARTUP_WAIT: Duration = Duration::from_secs(30);

/// The port: `WINSCORE_MCP_PORT`, else [`DEFAULT_PORT`].
pub fn port() -> u16 {
    std::env::var("WINSCORE_MCP_PORT").ok().and_then(|port| port.parse().ok()).unwrap_or(DEFAULT_PORT)
}

pub fn url() -> String {
    format!("http://127.0.0.1:{}{PATH}", port())
}

fn lock<T>(mutex: &Mutex<T>) -> MutexGuard<'_, T> {
    mutex.lock().unwrap_or_else(|poisoned| poisoned.into_inner())
}

#[derive(Default)]
pub struct Mcp {
    server: Mutex<Option<Arc<Server>>>,
    /// Why the endpoint could not start.
    error: Mutex<Option<String>>,
    /// Requests the page has not answered yet, by the number they went with.
    pending: Mutex<HashMap<u64, mpsc::Sender<Value>>>,
    next: AtomicU64,
    page_ready: AtomicBool,
}

/// What the page's MCP dialog shows.
#[derive(Serialize)]
pub struct Status {
    enabled: bool,
    url: String,
    executable: String,
    error: Option<String>,
}

impl Mcp {
    fn status(&self) -> Status {
        let enabled = lock(&self.server).is_some();
        let executable = std::env::current_exe().map(|path| path.to_string_lossy().into_owned()).unwrap_or_default();
        Status { enabled, url: url(), executable, error: lock(&self.error).clone() }
    }

    /// The page listens for requests.
    pub fn page_ready(&self) {
        self.page_ready.store(true, Ordering::SeqCst);
    }
}

/// Starts listening, unless it already does; a failure (the port taken) is kept for the status.
pub fn start<R: Runtime>(app: &AppHandle<R>) {
    let mcp = app.state::<Mcp>();
    let mut running = lock(&mcp.server);
    if running.is_some() {
        return;
    }
    match Server::http(("127.0.0.1", port())) {
        Ok(server) => {
            let server = Arc::new(server);
            *running = Some(server.clone());
            *lock(&mcp.error) = None;
            let app = app.clone();
            std::thread::spawn(move || {
                for request in server.incoming_requests() {
                    let app = app.clone();
                    std::thread::spawn(move || answer(&app, request));
                }
            });
        }
        Err(err) => *lock(&mcp.error) = Some(format!("127.0.0.1:{} cannot be used ({err}); is another WinScore running?", port())),
    }
}

pub fn stop<R: Runtime>(app: &AppHandle<R>) {
    let mcp = app.state::<Mcp>();
    if let Some(server) = lock(&mcp.server).take() {
        server.unblock();
    }
    *lock(&mcp.error) = None;
}

/// This computer's own names for the endpoint, with or without the port.
fn host_allowed(host: Option<&str>) -> bool {
    let Some(host) = host else { return true };
    let name = match host.rsplit_once(':') {
        Some((name, port)) if port.chars().all(|c| c.is_ascii_digit()) && !name.ends_with(':') => name,
        _ => host,
    };
    matches!(name, "127.0.0.1" | "localhost" | "[::1]")
}

/// Origins of this computer: the app's own page and local tools; no web site.
fn origin_allowed(origin: &str) -> bool {
    let rest = origin.strip_prefix("http://").or_else(|| origin.strip_prefix("https://")).or_else(|| origin.strip_prefix("tauri://"));
    rest.is_some_and(|host| host_allowed(Some(host)))
}

fn error(id: Option<Value>, code: i64, message: &str) -> Value {
    json!({ "jsonrpc": "2.0", "id": id.unwrap_or(Value::Null), "error": { "code": code, "message": message } })
}

fn header(name: &str, value: &str) -> Header {
    Header::from_bytes(name.as_bytes(), value.as_bytes()).expect("a valid header")
}

fn respond(request: Request, status: u16, body: Option<String>) {
    let response = match body {
        Some(body) => Response::from_string(body).with_header(header("Content-Type", "application/json")),
        None => Response::from_string(String::new()),
    };
    let _ = request.respond(response.with_status_code(status));
}

fn answer<R: Runtime>(app: &AppHandle<R>, mut request: Request) {
    fn read(request: &Request, name: &'static str) -> Option<String> {
        request.headers().iter().find(|h| h.field.equiv(name)).map(|h| h.value.as_str().to_owned())
    }
    let (host, origin, kind) = (read(&request, "Host"), read(&request, "Origin"), read(&request, "Content-Type"));
    if !host_allowed(host.as_deref()) || origin.as_deref().is_some_and(|origin| !origin_allowed(origin)) {
        return respond(request, 403, None);
    }
    if request.url().split('?').next() != Some(PATH) {
        return respond(request, 404, None);
    }
    if *request.method() != Method::Post {
        // No stream from the server and no sessions to end: POST only.
        let response = Response::from_string(String::new()).with_status_code(405).with_header(header("Allow", "POST"));
        let _ = request.respond(response);
        return;
    }
    if !kind.is_some_and(|kind| kind.to_ascii_lowercase().starts_with("application/json")) {
        return respond(request, 415, None);
    }
    let mut body = String::new();
    if request.as_reader().take(MAX_BODY).read_to_string(&mut body).is_err() {
        return respond(request, 400, None);
    }
    let parsed: Value = match serde_json::from_str(&body) {
        Ok(value) => value,
        Err(err) => return respond(request, 400, Some(error(None, -32700, &format!("Parse error: {err}")).to_string())),
    };
    let batch = parsed.is_array();
    let messages = match parsed {
        Value::Array(messages) => messages,
        message => vec![message],
    };
    let replies: Vec<Value> = messages.into_iter().filter_map(|message| forward(app, message)).collect();
    match (replies.len(), batch) {
        (0, _) => respond(request, 202, None),
        (_, true) => respond(request, 200, Some(Value::Array(replies).to_string())),
        (_, false) => respond(request, 200, replies.into_iter().next().map(|reply| reply.to_string())),
    }
}

/// Hands a message to the page; its answer to a request, none for a notification.
fn forward<R: Runtime>(app: &AppHandle<R>, message: Value) -> Option<Value> {
    // Without a method it is a client's answer to a request of ours: there are none.
    message.get("method")?;
    let id = message.get("id").filter(|id| !id.is_null()).cloned();
    let request = id.is_some();
    let mcp = app.state::<Mcp>();
    let started = Instant::now();
    while !mcp.page_ready.load(Ordering::SeqCst) {
        if started.elapsed() > STARTUP_WAIT {
            return request.then(|| error(id.clone(), -32000, "WinScore's window has not started"));
        }
        std::thread::sleep(Duration::from_millis(100));
    }
    let key = mcp.next.fetch_add(1, Ordering::SeqCst);
    let (sender, receiver) = mpsc::channel();
    if request {
        lock(&mcp.pending).insert(key, sender);
    }
    if app.emit_to(MAIN, "mcp-request", json!({ "id": key, "message": message })).is_err() {
        lock(&mcp.pending).remove(&key);
        return request.then(|| error(id.clone(), -32000, "WinScore's window cannot be reached"));
    }
    if !request {
        return None;
    }
    match receiver.recv_timeout(PAGE_TIMEOUT) {
        Ok(Value::Null) => Some(error(id, -32603, "No answer")),
        Ok(reply) => Some(reply),
        Err(_) => {
            lock(&mcp.pending).remove(&key);
            Some(error(id, -32000, "WinScore did not answer in time"))
        }
    }
}

/// The page's answer to request `id` (null for a notification).
#[tauri::command]
pub fn mcp_respond(mcp: State<'_, Mcp>, id: u64, response: Value) {
    if let Some(sender) = lock(&mcp.pending).remove(&id) {
        let _ = sender.send(response);
    }
}

#[tauri::command]
pub fn mcp_status(mcp: State<'_, Mcp>) -> Status {
    mcp.status()
}

/// Turns the endpoint on or off, for this and later launches.
#[tauri::command]
pub fn mcp_enable(app: AppHandle, on: bool) -> Status {
    if on {
        start(&app);
    } else {
        stop(&app);
    }
    settings::update(&app, |s| s.mcp_off = !on);
    app.state::<Mcp>().status()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn only_this_computer_s_names_and_origins_are_taken() {
        assert!(host_allowed(Some("127.0.0.1:7341")));
        assert!(host_allowed(Some("localhost:7341")));
        assert!(host_allowed(Some("[::1]:7341")));
        assert!(host_allowed(None));
        assert!(!host_allowed(Some("evil.example:7341")));
        assert!(!host_allowed(Some("127.0.0.1.evil.example")));
        assert!(origin_allowed("http://localhost:6274"));
        assert!(origin_allowed("tauri://localhost"));
        assert!(!origin_allowed("https://evil.example"));
        assert!(!origin_allowed("null"));
    }
}
