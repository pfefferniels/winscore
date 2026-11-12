//! `--mcp-stdio`: the app's executable as an MCP server that a client starts
//! itself (Claude Desktop, and any client configured with a command). It
//! reads JSON-RPC messages, one per line, from standard input, hands each to
//! the running app's endpoint ([`crate::mcp`]) and writes the answers to
//! standard output, one per line. When the app is not running it starts it
//! and waits for it.

use std::io::{self, BufRead, Read, Write};
use std::net::TcpStream;
use std::time::{Duration, Instant};

use serde_json::{json, Value};

use crate::mcp;

/// The bundle identifier of tauri.conf.json, which macOS starts the app by.
#[cfg(target_os = "macos")]
const IDENTIFIER: &str = "io.github.pfefferniels.winscore";
const LAUNCH_WAIT: Duration = Duration::from_secs(40);

/// Posts one message; the answer's body, or none (202, a notification).
fn post(port: u16, body: &str) -> io::Result<Option<String>> {
    let mut stream = TcpStream::connect(("127.0.0.1", port))?;
    stream.set_read_timeout(Some(Duration::from_secs(180)))?;
    write!(
        stream,
        "POST /mcp HTTP/1.1\r\nHost: 127.0.0.1:{port}\r\nContent-Type: application/json\r\nAccept: application/json, text/event-stream\r\nContent-Length: {}\r\nConnection: close\r\n\r\n{body}",
        body.len()
    )?;
    let mut response = Vec::new();
    stream.read_to_end(&mut response)?;
    let text = String::from_utf8_lossy(&response);
    let (head, body) = text.split_once("\r\n\r\n").ok_or_else(|| io::Error::other("an answer without a body"))?;
    let status: u16 = head.split_whitespace().nth(1).and_then(|code| code.parse().ok()).ok_or_else(|| io::Error::other("an answer without a status"))?;
    match status {
        200 => Ok(Some(body.trim().to_owned())),
        202 => Ok(None),
        _ => Err(io::Error::other(format!("WinScore answered HTTP {status}"))),
    }
}

/// Starts the app, through Launch Services on macOS so that it is not this process's child.
fn launch() {
    #[cfg(target_os = "macos")]
    let started = std::process::Command::new("open").args(["-g", "-b", IDENTIFIER]).status().is_ok_and(|status| status.success());
    #[cfg(not(target_os = "macos"))]
    let started = false;
    if !started {
        if let Ok(exe) = std::env::current_exe() {
            let _ = std::process::Command::new(exe)
                .stdin(std::process::Stdio::null())
                .stdout(std::process::Stdio::null())
                .stderr(std::process::Stdio::null())
                .spawn();
        }
    }
}

/// Posts a message, starting the app first if nothing listens.
fn deliver(port: u16, body: &str) -> io::Result<Option<String>> {
    match post(port, body) {
        Err(err) if err.kind() == io::ErrorKind::ConnectionRefused => {
            launch();
            let started = Instant::now();
            loop {
                std::thread::sleep(Duration::from_millis(250));
                match post(port, body) {
                    Err(err) if err.kind() == io::ErrorKind::ConnectionRefused && started.elapsed() < LAUNCH_WAIT => continue,
                    other => return other,
                }
            }
        }
        other => other,
    }
}

/// Runs the bridge until standard input ends; the process's exit code.
pub fn run() -> i32 {
    let port = mcp::port();
    let mut out = io::stdout().lock();
    for line in io::stdin().lock().lines() {
        let Ok(line) = line else { break };
        if line.trim().is_empty() {
            continue;
        }
        let answer = match deliver(port, &line) {
            Ok(answer) => answer,
            Err(err) => {
                // A request still gets its answer: what went wrong.
                let id = serde_json::from_str::<Value>(&line).ok().and_then(|m| m.get("method").and(m.get("id")).cloned());
                id.map(|id| json!({ "jsonrpc": "2.0", "id": id, "error": { "code": -32000, "message": format!("WinScore: {err}") } }).to_string())
            }
        };
        if let Some(answer) = answer {
            if writeln!(out, "{answer}").and_then(|()| out.flush()).is_err() {
                break;
            }
        }
    }
    0
}
