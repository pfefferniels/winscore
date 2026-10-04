# WinScore Web

Browser shell of the SCORE editor. The Rust crate `rust/crates/score-web` (WebAssembly, via wasm-bindgen) opens, renders, hit-tests, edits and saves `.mus` files. This TypeScript/Vite app paints its display lists on a canvas and handles input.

## Requirements

- Rust with the `wasm32-unknown-unknown` target (`rustup target add wasm32-unknown-unknown`)
- `wasm-bindgen` CLI of the same version as the crate: `cargo install wasm-bindgen-cli --version 0.2.129 --locked`
- Node 24 (`nvm use 24`)

## Run

```sh
cd web
npm install
npm run dev        # builds the wasm, copies samples and references, serves http://localhost:5173
```

`npm run build` writes a self-contained static site to `web/dist/` (relative paths; wasm, fonts, samples and engine references included). `npm run preview` serves it at http://localhost:4173.

Environment variables: `CARGO_TARGET_DIR` (default `rust/target`), `WASM_PROFILE` (default `release`), `REFERENCE_DIR` (default `rust/fixtures`).

Screenshots of the built app: `npm run build && node scripts/screenshots.mjs OUT_DIR [name='sample=mozart.mus&mode=overlay&zoom=200' …]` (needs `npx playwright install chromium` once).

## Using it

- **Open** a `.mus` file with the button or by dropping it on the window; the bundled samples are in the drop-down (`WINSCORE 5.01/winscore/*.mus`, `SCORE 4/SCORE/NEWLINE.MUS`, `NEWLIB.MUS`). Dropping an `engine.json` loads it as the reference for the current score.
- **Rust / Engine / Overlay**: the Rust renderer's page, the original engine's display list (`rust/fixtures/sample-*/engine.json`, produced from WScore.exe under emulation), or both, engine in cyan and Rust in magenta, multiplied, so that matching elements come out dark.
- **Zoom**: −/+, the percent list, Fit, or ctrl/⌘ + wheel (pinch) around the pointer.
- **Selection**: click an element or a row of the item list; Shift-click adds or removes; Escape clears. The Engine view selects through the fixture's item attribution. The panel shows P1…Pn of the last selected item with the help's label for each; edit a value and press Enter to set it and re-render.
- **Editing**: drag selected items (Shift keeps one axis, Escape cancels), arrows move by one P3 space or scale step, Page Up/Down by 4 steps, Home/End by 10 spaces (WinScore's edit-mode keys), `[`/`]` one staff up/down, Delete, ⌘Z/Ctrl+Z undo, ⇧⌘Z/Ctrl+Y redo, and the command bar takes SCORE edit commands. Dragging empty paper pans. **Save** downloads the edited `.mus`. All editing runs in `score-edit` (editor-core's crate, checked against the engine): moves, deletes, commands, drags and the undo history. Drag offsets are rounded to 0.01 P3 unit or scale step until the engine's own rounding is known.
- **Input…** opens WinScore's five-pass input dialog (Smith's "Computer Keyboard Input", `IN`): staff (proposed one above the highest), input range, and the notes, rhythms, marks, beams and slurs passes. `score-input` checks the passes as you type and marks the failing one; Enter moves to the next pass and inserts after the fifth. A missing staff is created as the engine's `IN n` creates it (`score_input::StaffArgs`). Insert is one undo step.
- URL parameters for direct links: `?sample=mozart.mus&mode=overlay&zoom=200&select=12`.

## Conventions

- Page coordinates are engine units of 1/4000 inch, origin at the paper's bottom-left corner, y up, as in `rust/fixtures/README.md`.
- **Zoom**: 100 % shows the page at physical size on a 96-dpi screen (one CSS pixel = 1/96 in ≈ 41.7 engine units). This matches WinScore's own 100 % (zoom 64 of 256 in an `MM_HIENGLISH` view) on a 96-dpi display. The preset list is WinScore's zoom bar (10 … 500 %) plus larger steps; − and + change the zoom by a quarter, as WinScore's Reduce and Zoom do.
- **Painting** follows `CWScoreView::OnDraw` (0x5E5910) as `disasm-expert` read it (`analysis/engine/display.md`): polylines with a pen one device pixel wide; filled objects with the even-odd rule and outlined with the same pen; text on its baseline at the engine's y + 96 (folded into the fixture coordinates), stretched horizontally to the run's average width as `CreateFontA` does; a white window with the engine's green page frame. Points are snapped to device pixels.
- **Fonts**: see `fonts/README.md`. The engine positions every character itself, so the substitute faces only change glyph shapes, not positions. The width stretch uses the average character width of the Windows face GDI would substitute (Times New Roman, Arial, Courier New); for the other families the glyphs are left unstretched. Rotated text turns about the cell's top-left corner (baseline plus the Windows face's ascent) and follows the clockwise line on which the engine places the characters; whether WinScore's glyphs turn the same way is not yet confirmed.

## Layout

| Path | What |
|---|---|
| `src/main.ts` | app state, file handling, controls |
| `src/editor.ts` | the editing operations the UI uses, backed by score-edit through score-web |
| `src/interaction.ts` | pointer and keyboard gestures → editor calls |
| `src/canvas.ts` | scrolling, zooming page view |
| `src/paint.ts` | display-list painter |
| `src/display.ts` | decoding of score-web's flat display-list encoding |
| `src/view.ts` | page ↔ device transform, zoom levels |
| `src/panel.ts` | item list and parameter panel |
| `src/fonts.ts`, `src/fonts.css` | engine font names → bundled faces |
| `scripts/` | wasm build, asset copy, screenshots |

The flat encoding (`Uint32Array` shape records, `Int32Array` coordinates, text runs as JSON) is documented in `rust/crates/score-web/src/encode.rs`.
