# WinScore for the Mac

The editor (`web/`) as a desktop app, built with [Tauri](https://tauri.app): the same page in the system's web view (WKWebView on macOS), with a menu bar, the system's file panels and alerts, and files read and written where they are. `src-tauri/src/lib.rs` is the app; `web/src/desktop.ts` is its side in the page, which in a browser does nothing.

## Download

Every push builds a disk image for Apple silicon and Intel Macs (`.github/workflows/mac.yml`): in the repository's Actions tab, open the latest run of **Mac app** and download the artifact **WinScore-macOS** (a zip holding `WinScore_<version>_universal.dmg`). A tag `v…` also attaches the disk image to a release. Open it and drag WinScore to Applications.

The app is signed ad hoc, not with an Apple Developer ID, so the first time macOS will not open it with a double click. Control-click it in Applications, choose Open, then Open again; on macOS 15 and later open it once, then click **Open Anyway** in System Settings ▸ Privacy & Security. Or, in Terminal:

```bash
xattr -dr com.apple.quarantine /Applications/WinScore.app
```

## What the app adds to the page

- **Menu bar**: File (New Score ⌘N, Open… ⌘O, Save ⌘S, Save As… ⇧⌘S, Export SVG… ⌘E, Print… ⌘P), Edit (Undo, Redo, Cut, Copy, Paste, Duplicate, Delete, Select All), View (Zoom In ⌘=, Zoom Out ⌘−, Actual Size ⌘0, Fit Width ⌘9, Side Panel ⌥⌘P, Full Screen), Window, Help (Commands, Keys and Gestures, F1). The commands go to the page as `menu` events; Cut, Copy, Paste and Select All are the system's, so text fields keep them.
- **Files**: Open and Save As use the system's panels; Save writes back to the file that was opened (a new score or a sample asks where). Export SVG asks where to put the page. The window's title is the file's name, with "Edited" while there are unsaved changes.
- **Opening from outside**: WinScore is the app for `.mus` files: the bundle declares the file type and claims it as its owner (`fileAssociations` in `tauri.conf.json`: an exported type `io.github.pfefferniels.winscore.mus`, rank Owner), and at its first start the app asks Launch Services to make it the default for them (`src-tauri/src/default_app.rs`). After that the Finder opens `.mus` files with it (double click, a drop on the Dock icon), unless another app is chosen in the Finder's Get Info ▸ Open With ▸ Change All; WinScore ▸ Open .mus Files with WinScore makes it the default again. A file dropped on the window opens too.
- **Unsaved changes**: closing the window, Quit (⌘Q), New and Open ask before they are thrown away, with the system's alert.
- **Print** opens the system's print panel for the page as printed (no staff numbers); its PDF button saves a PDF with real paths and text.
- **AI assistants (MCP)**: see below.

## AI assistants (MCP)

While WinScore runs, Claude Code and other assistants that speak the [Model Context Protocol](https://modelcontextprotocol.io) can read and edit the score open in its window. Help ▸ AI Assistants (MCP)… shows the address and the commands below, and a switch that turns it off (remembered in `settings.json` in the app's folder under `~/Library/Application Support`).

For Claude Code, once:

```bash
claude mcp add --transport http --scope user winscore http://127.0.0.1:7341/mcp
```

For assistants that start their servers themselves (Claude Desktop, and any client configured with a command), the app's executable with `--mcp-stdio` is a bridge from standard input and output to the running app, and starts WinScore if it is not running:

```bash
claude mcp add --scope user winscore -- /Applications/WinScore.app/Contents/MacOS/WinScore --mcp-stdio
```

```json
{ "mcpServers": { "winscore": { "command": "/Applications/WinScore.app/Contents/MacOS/WinScore", "args": ["--mcp-stdio"] } } }
```

The tools (`web/src/mcp.ts`): `get_document`, `list_items`, `get_items` (every parameter with the SCORE help's name for it, and the side panel's settings by name: Pitch, Value, Stem …), `render_page` (an image of the page or some staves, as the window draws it), `select`, `set_settings` (by those names, as the panel writes them), `set_parameters`, `add_notes` (by pitch name and duration), `insert_items` (from SCORE's creation words or raw parameters), `insert_text`, `set_text`, `move_items`, `delete_items`, `run_command` (SCORE's edit commands, and group and layout commands such as LJ with their answers), `undo`, `redo`, `describe_kind`, `list_words`, `list_commands`, `open_file`, `new_score`, `save`, `export_svg`. Items are named by an id that stays with them through edits and undo. Each call that changes the score is one undo step in the window, which shows it at once and says in the status line which assistant made it; an edit waits while something is being dragged.

The endpoint (`src-tauri/src/mcp.rs`) is the protocol's Streamable HTTP transport, answered with single JSON responses; the app passes each message to the page, which answers it with the editor. It listens on the loopback address only, takes only this computer's host names (against DNS rebinding), no origin of a web site and only JSON bodies, so web pages cannot reach it; any program on the computer can, as it can reach your files. `WINSCORE_MCP_PORT` sets another port than 7341 (for the bridge too).

## Build

On a Mac with Rust (`rustup target add wasm32-unknown-unknown aarch64-apple-darwin x86_64-apple-darwin`), the wasm-bindgen CLI 0.2.129 (`cargo install wasm-bindgen-cli --version 0.2.129 --locked`), Node 24 and the Xcode command line tools:

```bash
cd desktop
npm ci --prefix ../web
npm ci
```

```bash
npm run dmg
```

writes `src-tauri/target/universal-apple-darwin/release/bundle/dmg/WinScore_0.1.0_universal.dmg` (the web app is built first, `tauri.conf.json`'s `beforeBuildCommand`). `npx tauri build` builds the app and disk image for the Mac's own architecture only, and `npx tauri dev` runs the app on the web app's dev server, reloading as the page changes.

The app builds on Linux and Windows too (`npx tauri build`), with the system's web view there (WebKitGTK needs `libwebkit2gtk-4.1-dev`).

To sign with a Developer ID and notarize, give the build step Tauri's variables as repository secrets (`APPLE_CERTIFICATE`, `APPLE_CERTIFICATE_PASSWORD`, `APPLE_SIGNING_IDENTITY`, and `APPLE_ID`, `APPLE_PASSWORD`, `APPLE_TEAM_ID`; see Tauri's guide to macOS code signing); `APPLE_SIGNING_IDENTITY` replaces the ad hoc signature (`"signingIdentity": "-"`).

## Icon

`icon/icon.svg` is the app's mark on a macOS icon tile; `src-tauri/icons/` are made from a 1024 px rendering of it with `npx tauri icon icon/icon.png -o src-tauri/icons` (only the sizes `tauri.conf.json` names are kept).
