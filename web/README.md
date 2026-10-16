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

Frame times while dragging: `npm run build && npm run perf [FILE.mus …]` (default the largest sample); it fails if a frame during the drag takes more than 50 ms. Drags re-render only the moved items (`rust/crates/score-web/src/live.rs`); the full render follows on drop.

Screenshots of the built app: `npm run build && node scripts/screenshots.mjs OUT_DIR [name='sample=mozart.mus&mode=overlay&zoom=200' …]` (needs `npx playwright install chromium` once).

## Using it

- **Open** a `.mus` file with the button or by dropping it on the window; the bundled samples are in the drop-down (`WINSCORE 5.01/winscore/*.mus`, `SCORE 4/SCORE/NEWLINE.MUS`, `NEWLIB.MUS`). Dropping an `engine.json` loads it as the reference for the current score.
- **SVG** and **Print** render the page for print (no staff numbers or other screen aids). SVG uses `score_render::svg` and is paper-sized; Print paints the page on a 300 dpi canvas that a print stylesheet shows alone on paper of the score's size.
- **Rust / Engine / Overlay**: the Rust renderer's page, the original engine's display list (`rust/fixtures/sample-*/engine.json`, produced from WScore.exe under emulation), or both, engine in cyan and Rust in magenta, multiplied, so that matching elements come out dark.
- **Zoom**: −/+ buttons or the `+` and `_` keys, the percent list, Fit, or ctrl/⌘ + wheel (pinch) around the pointer.
- **Selection**: click an element or a row of the item list; Shift-click adds or removes; Escape clears. A click selects the item whose drawn outline is under the pointer (in the Engine view through the fixture's item attribution); where there is none, WinScore's own rule picks the item with the nearest reference point within 12 px (decision D8). The panel shows P1…Pn of the last selected item with the help's label for each; edit a value and press Enter to set it and re-render.
- **Editing**: drag selected items (Shift locks to one axis by WinScore's rule, Escape cancels), arrows move by one P3 space or scale step, Page Up/Down by 4 steps, Home/End by 10 spaces (WinScore's edit-mode keys), `[`/`]` one staff up/down, Enter / Shift+Enter to the next / previous item, Delete, ⌘Z/Ctrl+Z undo, ⇧⌘Z/Ctrl+Y redo. Ctrl/⌘-drag or the middle button pans. **Save** downloads the edited `.mus`. All editing runs in `score-edit` (editor-core's crate, checked against the engine): moves, deletes, commands, drags and the undo history. Drags send the cursor position and keep the grab offset (decision D9); score-edit computes P3/P4 as the engine does, with P4 in whole steps for notes, rests, clefs, keys and meters.
- **Command bar** (bottom left), as in WinScore: typing anywhere outside a form field goes into it, Enter runs the SCORE command on the selection (`R 5`, `600 5`, `FLI`, `NOTE`, `DE`, …), Up/Down recall earlier lines, Escape returns to the page. Next to it the status line shows what the last action did and the selected item's P1…Pn, as WinScore lists the item in edit mode.
- **Text**: the palette's Text button opens a dialog (text, font from WinScore's font menu as its `_NN` code, staff, P3, P4) and creates the items as SCORE's quick entry `"text" staff P3 P4` does. Double-click a text item to edit its characters where they stand, or edit them and pick a font in the panel.
- **Symbols**: the palette's Symbol button opens a searchable grid of every symbol in WinScore's bundled libraries, each drawn by the Rust renderer, with WinScore's names (`symblist.txt`).
- New items (text, symbols) go to the selected item's place, else to the last click on empty paper, else to the top staff at P3 100.
- **Group edit**: drag a box over empty paper to select the items inside. score-edit reads the box as WinScore reads a mouse-drawn area (`Editor::draw_box`): staves by their middle lines, P3 from x, a narrow box meaning the whole width. The Area buttons (Move, Copy, Delete, Alter, Copy to staves) start WinScore's line-by-line dialogue: its question appears before the command bar, and the answer is typed there or given with the mouse (a box for the area; for the destination a click keeps the area's position on that staff, a thin line moves its left edge, a box rescales it); Cancel ends it without a change. `IF … THEN …` conditional edits go through the command bar.
- **Layout** buttons send WinScore's LI (line up), J (justify), LJ, LJA (all systems) and TR (transpose); they are typeable on the command bar too (`LJ 1 2` answers at once). LI, J and LJ ask for the lowest staff and the number of staves of the system, typed or given by drawing a box. When the engine would give up (unequal beats, no notes), its message appears in the status line.
- **Palette** (below the toolbar): WinScore's Items menu, clefs, note and rest values, and edit-mode buttons, each sending the SCORE command from WinScore's command table (`analysis/data/command_map.tsv`) with its tooltip. Commands `score-edit` does not handle yet are struck through and disabled.
- **Input** (or `IN n` on the command bar) opens the music input: Smith's "Computer Keyboard Input", WinScore's five passes (notes, rhythms, marks, beams, slurs) on a staff (proposed one above the highest, or n) and an input range, typed at a cursor in the music. The line is drawn on the page in violet as `score-input` reads it, as it would be inserted (`Score.previewInput`, `rust/crates/score-web/src/preview.rs`), and a bubble at the cursor shows what is being typed and what it became (`F♯4, quarter`). The keys are SCORE's input language, item by item:
  - pass 1: a caret between items. Typing builds the item at the caret (`G`, `GS4`, `C4:E:G`, `M2`, `K2S`, `3 4` …), `/` ends it, ←/→ move between items, Backspace takes back one character (Ctrl/⌥+Backspace the whole item before the caret), Delete removes the item after it;
  - pass 2: the cursor stands on a note, chord or rest; a value typed there (`8`, `4.`, `T`, `G`) replaces its length, `/` moves on. Until pass 2 is left, notes without a value show as quarters;
  - passes 3–5: the cursor stands on a note, Shift+←/→ selects more. A mark (`S`, `A`, `-T`, `MF`, `C` for a hairpin …) or, in passes 4–5, nothing or `+`/`-`/a number for a beam or slur over the selection is placed with `/`; the note numbers come from the cursor (`S 4:6`, `C 4 6`, `-401 6`). `/` alone places the last one again, Backspace removes the last one on the cursor's note. Text with its own numbers (`S 2:5`, `X3 1 4 7`, `2B`) is taken as typed.
  
  Enter, Tab or ↓ go to the next pass, Shift+Enter or ↑ back; ⌘/Ctrl+Enter inserts; Escape drops what is being typed, then closes (the line is kept). A click on the input staff puts the cursor there (Shift-click extends the selection). Below the page the passes are shown as SCORE text, read only, beside help on the keys that can follow what is typed; an item cut short (`K2`, `C4:`) is noted as unfinished, a mistake is marked in its pass, and items WinScore's reader would erase (`Y`, `C0`) are named. A missing staff is created as the engine's `IN n` creates it (`score_input::StaffArgs`). Insert is one undo step; the passes are then cleared for the next staff.
- URL parameters for direct links: `?sample=mozart.mus&mode=overlay&zoom=200&select=12`.

## Conventions

- Page coordinates are engine units of 1/4000 inch, origin at the paper's bottom-left corner, y up, as in `rust/fixtures/README.md`.
- **Zoom**: 100 % shows the page at physical size on a 96-dpi screen (one CSS pixel = 1/96 in ≈ 41.7 engine units). This matches WinScore's own 100 % (zoom 64 of 256 in an `MM_HIENGLISH` view) on a 96-dpi display. The preset list is WinScore's zoom bar (10 … 500 %) plus larger steps; − and + change the zoom by a quarter, as WinScore's Reduce and Zoom do.
- **Painting** follows `CWScoreView::OnDraw` (0x5E5910) as `disasm-expert` read it (`analysis/engine/display.md`): polylines with a pen one device pixel wide; filled objects with the even-odd rule and outlined with the same pen; text on its baseline at the engine's y + 96 (folded into the fixture coordinates), stretched horizontally to the run's average width as `CreateFontA` does; a white window with the engine's green page frame. Points are snapped to device pixels.
- **Fonts**: see `fonts/README.md`. The engine positions every character itself, so the substitute faces only change glyph shapes, not positions. The width stretch uses the average character width of the Windows face GDI would substitute (Times New Roman, Arial, Courier New); for the other families the glyphs are left unstretched. Rotated text turns about the cell's top-left corner (baseline plus the Windows face's ascent) and turns clockwise, following the line on which the engine places the characters (display.md §3.4; inferred from the binary, not observed on Windows).

## Layout

| Path | What |
|---|---|
| `src/main.ts` | app state, file handling, controls |
| `src/editor.ts` | the editing operations the UI uses, backed by score-edit through score-web |
| `src/interaction.ts` | pointer and keyboard gestures → editor calls |
| `src/command-bar.ts` | command bar: typing capture, history |
| `src/input-mode.ts`, `src/input-draft.ts`, `src/input-help.ts` | music input at a cursor in the music: keys, caret and bubble over the page, the passes as items with a cursor, contextual help |
| `src/palette.ts` | toolbar palette of SCORE commands |
| `src/commands.ts` | WinScore's command table and font menu |
| `src/text-dialog.ts`, `src/symbol-dialog.ts` | text and symbol dialogs, in-place text editing |
| `src/canvas.ts` | scrolling, zooming page view |
| `src/paint.ts` | display-list painter |
| `src/display.ts` | decoding of score-web's flat display-list encoding |
| `src/view.ts` | page ↔ device transform, zoom levels |
| `src/panel.ts` | item list and parameter panel |
| `src/fonts.ts`, `src/fonts.css` | engine font names → bundled faces |
| `scripts/` | wasm build, asset copy, screenshots |

The flat encoding (`Uint32Array` shape records, `Int32Array` coordinates, text runs as JSON) is documented in `rust/crates/score-web/src/encode.rs`.
