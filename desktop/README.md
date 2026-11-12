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
- **Opening from outside**: WinScore registers `.mus` files, so the Finder opens them with it (double click, Open With, a drop on the Dock icon); a file dropped on the window opens too.
- **Unsaved changes**: closing the window, Quit (⌘Q), New and Open ask before they are thrown away, with the system's alert.
- **Print** opens the system's print panel for the page as printed (no staff numbers); its PDF button saves a PDF with real paths and text.

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
