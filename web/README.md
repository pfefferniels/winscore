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
npm run dev        # builds the wasm, copies the samples, serves http://localhost:5173
```

**Published** at https://pfefferniels.github.io/winscore/: `.github/workflows/web.yml` runs the Rust tests, the build and the smoke test on every push and deploys `dist/` from `main` to GitHub Pages.

`npm run build` writes a self-contained static site to `web/dist/` (relative paths; wasm, fonts and samples included). `npm run preview` serves it at http://localhost:4173.

Environment variables: `CARGO_TARGET_DIR` (default `rust/target`), `WASM_PROFILE` (default `release`).

Frame times while dragging: `npm run build && npm run perf [FILE.mus …]` (default the largest sample); it fails if a frame during the drag takes more than 50 ms. Drags re-render only the moved items (`rust/crates/score-web/src/live.rs`); the full render follows on drop.

Screenshots of the built app: `npm run build && node scripts/screenshots.mjs OUT_DIR [name='sample=mozart.mus&zoom=200' …]` (needs `npx playwright install chromium` once).

## Using it

The page is drawn by the Rust renderer alone. The app bar holds the menus (File, Edit, Insert, Layout, View), Undo and Redo, **Input music**, the score's name (with "Unsaved changes" after an edit), zoom, the side panel switch and the keyboard shortcuts (the `?` button or F1). Menu entries that send a SCORE command show it on the right, so it can be typed on the command bar next time; they can be used with the mouse or the keyboard (↓ on a title opens, arrows move, Enter runs, Escape closes).

- **Start**: without a score the page shows a start screen: **New score** (an empty page, `MusFile::empty`), **Open…**, and the bundled samples (`WINSCORE 5.01/winscore/*.mus`, `SCORE 4/SCORE/NEWLINE.MUS`, `NEWLIB.MUS`), which are also in the File menu. An empty score offers the music input, which creates its first staff as `IN 1` does. New and Open ask before unsaved changes are discarded.
- **Open** a `.mus` file from File ▸ Open (⌘O / Ctrl+O) or by dropping it on the window. **Save** (⌘S / Ctrl+S) downloads it.
- **Export SVG** and **Print** (⌘P / Ctrl+P) render the page for print (no staff numbers or other screen aids). SVG uses `score_render::svg` and is paper-sized; Print paints the page on a 300 dpi canvas that a print stylesheet shows alone on paper of the score's size.
- **Zoom**: −/+ buttons or the `+` and `_` keys, the percent list, Fit width (↔), View ▸ Actual size, or ctrl/⌘ + wheel (pinch) around the pointer.
- **Selection**: click an element or a row of the item list; Shift-click adds or removes; Escape clears. A click selects the item whose drawn outline is under the pointer; where there is none, WinScore's own rule picks the item with the nearest reference point within 12 px (decision D8). The side panel shows the last selected item: buttons for WinScore's edit-mode commands (← → ↑ ↓ for L1 R1 U1 D1, Flip, Center, Delete, previous and next item), then its settings in groups (`src/item-fields.ts`), each with a control that fits what it holds, read from and written into SCORE's packed parameters: for a note its pitch in the clef in force (type `F#4`, `Bb3`, or a letter for the nearest one; ↑/↓ step it), accidental, stem up or down, value, dots and tuplet, mark, offset; for a rest its symbol and value; clef types, key signatures by key, meters, barline types, hairpins and line types, slur, bracket and ending types, beams, staves, symbols (Choose… opens the symbol grid), numbers, boxes, text sizes. A list's choice, a button or a box applies at once; a typed value on Enter or when the field is left, ↑/↓ step it (Shift: by ten); every setting is one undo step. Below them **All parameters** (closed by default, remembered in the browser) lists P1…Pn with the help's label for each, including those the help describes but the item does not store, and sets any other parameter by number. Below it the item list, filtered by kind (`note`) or by number (a code or an index). The panel can be hidden (View ▸ Side panel); the choice is remembered in the browser.
- **Editing**: drag selected items (Shift locks to one axis by WinScore's rule, Escape cancels), arrows move by one P3 space or scale step, Page Up/Down by 4 steps, Home/End by 10 spaces (WinScore's edit-mode keys), `[`/`]` one staff up/down, Enter / Shift+Enter to the next / previous item, Delete, ⌘Z/Ctrl+Z undo, ⇧⌘Z/Ctrl+Y redo. Ctrl/⌘-drag or the middle button pans. **Save** downloads the edited `.mus`. All editing runs in `score-edit` (editor-core's crate, checked against the engine): moves, deletes, commands, drags and the undo history. Drags send the cursor position and keep the grab offset (decision D9); score-edit computes P3/P4 as the engine does, with P4 in whole steps for notes, rests, clefs, keys and meters.
- **Copy and paste**: ⌘C / Ctrl+C copies the selected items, ⌘X cuts them (one undo step), ⌘V pastes copies as one undo step, selected so they can be dragged or nudged at once; on a touch screen Edit ▸ Cut, Copy and Paste do the same. The copies keep their arrangement and their pitches (P4). After a click or tap on the page since the copy, their lowest staff goes to the clicked staff and their left edge to the click; otherwise they go where they were copied from. Where they would lie exactly on the same items (the originals, or an earlier paste), they move 10 spaces to the right, WinScore's End step, as often as needed, so Home puts one back over its original. ⌘D (Edit ▸ Duplicate) makes such copies of the selection beside it without touching the clipboard. Copied items travel as a `.mus` file of their own (`Score.copySelection`): on the system clipboard as base64 text, so ⌘V in another tab pastes them into that score, and kept in the page for the menu's Paste, which pastes what was copied in this tab and outlasts opening another score. A copy is also what `PST` pastes from the command bar. Fields, dialogs and selected text keep the browser's own copy and paste (`src/clipboard.ts`, `score_edit::clipboard`).
- **Command bar** (bottom left), as in WinScore: typing anywhere outside a form field goes into it, Enter runs the SCORE command on the selection (`R 5`, `600 5`, `FLI`, `NOTE`, `DE`, …), Up/Down recall earlier lines, Escape returns to the page. Next to it the status line shows what the last action did and the selected item's P1…Pn, as WinScore lists the item in edit mode.
- **Text**: Insert ▸ Text opens a dialog (text, font from WinScore's font menu as its `_NN` code, staff, P3, P4) and creates the items as SCORE's quick entry `"text" staff P3 P4` does. Double-click a text item to edit its characters where they stand, or edit them and pick a font in the panel.
- **Symbols**: Insert ▸ Symbol opens a searchable grid of every symbol in WinScore's bundled libraries, each drawn by the Rust renderer, with WinScore's names (`symblist.txt`).
- New items (text, symbols) go to the selected item's place, else to the last click on empty paper, else to the top staff at P3 100.
- **Group edit**: drag a box over empty paper to select the items inside. score-edit reads the box as WinScore reads a mouse-drawn area (`Editor::draw_box`): staves by their middle lines, P3 from x, a narrow box meaning the whole width. The Area entries of the Edit menu (Move, Copy, Delete, Alter, Copy to staves) start WinScore's line-by-line dialogue: its question appears before the command bar, and the answer is typed there or given with the mouse (a box for the area; for the destination a click keeps the area's position on that staff, a thin line moves its left edge, a box rescales it); Cancel ends it without a change. `IF … THEN …` conditional edits go through the command bar.
- The **Layout** menu sends WinScore's LI (line up), J (justify), LJ, LJA (all systems) and TR (transpose); they are typeable on the command bar too (`LJ 1 2` answers at once). LI, J and LJ ask for the lowest staff and the number of staves of the system, typed or given by drawing a box. When the engine would give up (unequal beats, no notes), its message appears in the status line.
- **Menus**: Insert holds WinScore's Items menu (codes 1–18), note and rest values and clefs; Edit its edit-mode and group-edit commands. Each sends the SCORE command from WinScore's command table (`analysis/data/command_map.tsv`) with its tooltip; commands `score-edit` does not handle are left out. New items go to the selected item's staff and position.
- **Input music** (Insert ▸ Music input, or `IN n` on the command bar) opens the music input: Smith's "Computer Keyboard Input", WinScore's five passes (notes, rhythms, marks, beams, slurs) on a staff (proposed one above the highest, or n) and an input range, typed at a cursor in the music. The line is drawn on the page in violet as `score-input` reads it, as it would be inserted (`Score.previewInput`, `rust/crates/score-web/src/preview.rs`), and a bubble at the cursor shows what is being typed and what it became (`F♯4, quarter`). The keys are SCORE's input language, item by item:
  - pass 1: a caret between items. Typing builds the item at the caret (`G`, `GS4`, `C4:E:G`, `M2`, `K2S`, `3 4` …), `/` ends it, ←/→ move between items, Backspace takes back one character (Ctrl/⌥+Backspace the whole item before the caret), Delete removes the item after it;
  - pass 2: the cursor stands on a note, chord or rest; a value typed there (`8`, `4.`, `T`, `G`) replaces its length, `/` moves on. Until pass 2 is left, notes without a value show as quarters;
  - passes 3–5: the cursor stands on a note, Shift+←/→ selects more. A mark (`S`, `A`, `-T`, `MF`, `C` for a hairpin …) or, in passes 4–5, nothing or `+`/`-`/a number for a beam or slur over the selection is placed with `/`; the note numbers come from the cursor (`S 4:6`, `C 4 6`, `-401 6`). `/` alone places the last one again, Backspace removes the last one on the cursor's note. Text with its own numbers (`S 2:5`, `X3 1 4 7`, `2B`) is taken as typed.
  
  Enter, Tab or ↓ go to the next pass, Shift+Enter or ↑ back; ⌘/Ctrl+Enter inserts; Escape drops what is being typed, then closes (the line is kept). A click on the input staff puts the cursor there (Shift-click extends the selection). Below the page the passes are shown as SCORE text, read only, beside help on the keys that can follow what is typed; an item cut short (`K2`, `C4:`) is noted as unfinished, a mistake is marked in its pass, and items WinScore's reader would erase (`Y`, `C0`) are named. A missing staff is created as the engine's `IN n` creates it (`score_input::StaffArgs`). Insert is one undo step; the passes are then cleared for the next staff.
- **Phones and tablets**: below 640 px wide the menus open from one Menu button (☰), across the screen with their titles as tabs; zoom is by pinching or the View menu; the side panel lies under the page, starts hidden, and its grip sets its height; the command bar shares a line with the status. On a touch screen (`pointer: coarse`) targets are larger and text fields are 16 px, which iOS does not zoom into. The page takes its own gestures (`touch-action: none`, `src/interaction.ts`): a tap selects (a finger picks within 24 px rather than 12), a drag pans and glides on, a drag from a selected item moves it, two fingers pinch the zoom around the point between them, a long press adds or removes an item and a long press with a drag draws a box, a double tap edits a text where it stands; while a group command waits for its area, one finger draws the box and a tap answers it. A group command's question does not focus the command bar there, so no keyboard covers the page. Music input takes the on-screen keyboard's text through a typing field under the keyboard button, and a row of keys gives what it lacks (⇧, ← →, `/`, ⌫, ↵ for the next pass, with ⇧ the previous); it replaces the command bar on a phone. Where an on-screen keyboard covers the page without resizing it (iOS), the app follows the visual viewport. View ▸ Keys and gestures lists the gestures.
- URL parameters for direct links: `?sample=mozart.mus&zoom=200&select=12`, or `?new` for an empty score.

## Conventions

- Page coordinates are engine units of 1/4000 inch, origin at the paper's bottom-left corner, y up, as in `rust/fixtures/README.md`.
- **Zoom**: 100 % shows the page at physical size on a 96-dpi screen (one CSS pixel = 1/96 in ≈ 41.7 engine units). This matches WinScore's own 100 % (zoom 64 of 256 in an `MM_HIENGLISH` view) on a 96-dpi display. The preset list is WinScore's zoom bar (10 … 500 %) plus larger steps; − and + change the zoom by a quarter, as WinScore's Reduce and Zoom do.
- **Painting** follows `CWScoreView::OnDraw` (0x5E5910) as `disasm-expert` read it (`analysis/engine/display.md`): polylines with a pen one device pixel wide; filled objects with the even-odd rule and outlined with the same pen; text on its baseline at the engine's y + 96 (folded into the fixture coordinates), stretched horizontally to the run's average width as `CreateFontA` does; a white window with the engine's green page frame. Horizontal and vertical paths are snapped to device pixels, so staff lines, stems and barlines stay crisp; curved and slanted outlines (noteheads, dots, slurs, beams) keep their exact positions and are antialiased instead of stepping on the pixel grid as GDI draws them.
- **Fonts**: see `fonts/README.md`. The engine positions every character itself, so the substitute faces only change glyph shapes, not positions. The width stretch uses the average character width of the Windows face GDI would substitute (Times New Roman, Arial, Courier New); for the other families the glyphs are left unstretched. Rotated text turns about the cell's top-left corner (baseline plus the Windows face's ascent) and turns clockwise, following the line on which the engine places the characters (display.md §3.4; inferred from the binary, not observed on Windows).

## Layout

| Path | What |
|---|---|
| `src/main.ts` | app state, file handling, controls |
| `src/editor.ts` | the editing operations the UI uses, backed by score-edit through score-web |
| `src/interaction.ts` | pointer, touch and keyboard gestures → editor calls |
| `src/command-bar.ts` | command bar: typing capture, history |
| `src/clipboard.ts` | copy, cut, paste and duplicate: keys, the page's and the system clipboard |
| `src/input-mode.ts`, `src/input-draft.ts`, `src/input-help.ts` | music input at a cursor in the music: keys, caret and bubble over the page, the passes as items with a cursor, contextual help |
| `src/menu.ts` | menu bar widget: drop-down menus, rows of buttons, keyboard navigation, one Menu button on a narrow screen |
| `src/menus.ts` | the app's menus and the SCORE commands they send |
| `src/commands.ts` | WinScore's command table and font menu |
| `src/text-dialog.ts`, `src/symbol-dialog.ts` | text and symbol dialogs, in-place text editing |
| `src/canvas.ts` | scrolling, zooming page view |
| `src/paint.ts` | display-list painter |
| `src/display.ts` | decoding of score-web's flat display-list encoding |
| `src/view.ts` | page ↔ device transform, zoom levels |
| `src/panel.ts` | side panel: the selected item's actions, settings and parameters, the item list, the grip that sizes it under the page |
| `src/item-fields.ts` | the settings of each item code: labels, controls, and how they read and write the parameters |
| `src/fonts.ts`, `src/fonts.css` | engine font names → bundled faces |
| `scripts/` | wasm build, asset copy, screenshots |

The flat encoding (`Uint32Array` shape records, `Int32Array` coordinates, text runs as JSON) is documented in `rust/crates/score-web/src/encode.rs`.
