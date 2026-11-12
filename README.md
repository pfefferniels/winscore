# SCORE editor

An editor for scores in the file format of Leland Smith's music engraving program SCORE and its Windows version WinScore: a Rust library that reads, renders, edits and writes `.mus` files, and a graphical editor built on it (Rust via WebAssembly), in the browser at https://pfefferniels.github.io/winscore/ and as a Mac app (`desktop/README.md`). Items are put on the page with the mouse, in insertion modes chosen by key (N a note, S a slur, T a text …), and every parameter is set in the side panel.

## Layout

| Path | Contents |
|---|---|
| `rust/crates/score-format` | `.mus` read/write, `.DRW` symbol libraries, `.FMT` font metrics |
| `rust/crates/score-render` | items to display lists and SVG |
| `rust/crates/score-input` | the music input language (`IN`), converted to items |
| `rust/crates/score-layout` | layout commands: line up (`LI`), justify (`J`), both (`LJ`, `LJA`) |
| `rust/crates/score-edit` | editing model: item ids, selection, undo, edit commands |
| `rust/crates/score-web` | the WebAssembly API the browser app uses |
| `rust/crates/score-cli` | `score-cli render in.mus -o out.svg`, `score-cli dump in.mus` |
| `web/` | the editor, a web app (`web/README.md`) |
| `desktop/` | the editor as a desktop app for macOS, built with Tauri (`desktop/README.md`) |
| `assets/` | symbol libraries, font metrics and sample scores from the WinScore 5.01 package (`assets/README.md`) |

## Build and test

```sh
cd rust && cargo test --workspace
cd web && npm install && npm run dev
```

`.github/workflows/web.yml` runs the Rust tests, the web build and its smoke test on every push and deploys `main` to GitHub Pages. `.github/workflows/mac.yml` builds the Mac app's disk image on every push (the run's artifact **WinScore-macOS**) and attaches it to a release for a tag `v…`.
