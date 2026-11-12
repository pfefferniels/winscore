// No console window behind the app on Windows.
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

fn main() {
    // An MCP client started the executable as its server: a bridge to the running app, no window.
    if std::env::args().skip(1).any(|arg| arg == "--mcp-stdio") {
        std::process::exit(winscore_desktop::stdio::run());
    }
    winscore_desktop::run()
}
