# SCORE editor

An editor for scores in the file format of Leland Smith's music engraving program SCORE and its Windows version WinScore: a Rust library that reads, renders, edits and writes `.mus` files, and a browser app built on it (Rust via WebAssembly), published at https://pfefferniels.github.io/winscore/.

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
| `web/` | the browser app (`web/README.md`) |
| `assets/` | symbol libraries, font metrics and sample scores from the WinScore 5.01 package (`assets/README.md`) |

## Build and test

```sh
cd rust && cargo test --workspace
cd web && npm install && npm run dev
```

`.github/workflows/web.yml` runs the Rust tests, the web build and its smoke tests on every push and deploys `main` to GitHub Pages.
