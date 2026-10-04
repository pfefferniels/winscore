# Engine fixtures

Reference output of WinScore's engine (WScore.exe under emulation, `oracle/`) for small `.mus` files. Written by `oracle/fixtures.py` from the case lists in `oracle/fixtures_cases.py` (samples, shared helpers) and `oracle/fixtures_codeNN.py` (one module per item code, each with `cases()`, found automatically); read by the crate `score-testkit`. The case plan is in `PLAN.md`, the current match table in `STATUS.md`.

```sh
cd oracle && /Users/nielspfeffer/Projects/winscore/oracle/.venv/bin/python fixtures.py 'code14-*'   # regenerate
cd rust && cargo run -p score-testkit --bin score-compare -- --help                                 # compare
```

## One case: `<case>/`

| File | Contents |
|---|---|
| `input.mus` | the score given to the engine |
| `engine.json` | the engine's display list, page coordinates |
| `meta.json` | commands, engine messages, item count, paper, view offset, validity |

A case is produced by a fresh engine: `initialize()`, then `G case.mus` (the file is renamed in the sandbox because the engine reads `G input.mus` as `NPUT.MUS`), then the case's extra commands. The display list after the last command is stored.

## `engine.json`

```json
{"shapes":[
{"colour":[0,0,0],"kind":"stroke","paths":[[[2000,2948],[32000,2948]]]}
],
"texts":[
{"colour":[0,115,51],"escapement":0,"font":"Helvetica-Narrow","height":774.8,"italic":false,"strings":[{"text":"1","x":800,"y":3469}],"underline":false,"weight":400,"width":319.605}
]}
```

- Keys sorted, one element per line, shapes and text runs in the order the engine emitted them.
- **Coordinates**: engine units of 1/4000 inch, y up, origin at the bottom-left corner of the paper: page = internal + (2000, 26948), where internal coordinates are those of the drawing routines (x = 150·P3, staff 1's bottom line at y = -24000; `analysis/engine/coordinates.md`). The engine's own stream is in view coordinates: `emit_points` writes x + VIEW_DX, y - VIEW_DY (ints at `0x20527F0`, `0x20527F4`), and `G` chooses VIEW_DY so that the topmost point lands at y = -3000. `oracle/fixtures.py` reads both globals after the last command and subtracts `view_offset` = (VIEW_DX - 2000, -VIEW_DY - 26948) from every point. The view also draws the paper as a green (`0x00FD00`) polyline of three nested rectangles, the innermost one unit inside the paper edge; it is removed from `engine.json`, and a case is invalid if its position disagrees with the globals (it has agreed in every case so far). `meta.json` keeps `view_offset`, `view_globals` and `page_frames`, so the raw stream can be reconstructed: view = page + view_offset. Items on staves above 199 are drawn 34050 units further right (the recto page).
- **Shapes**: `kind` is `"stroke"` when the first tag's high byte is 1 (polyline, one-unit pen) and `"fill"` otherwise (even-odd polygon set, as `OnDraw` treats it in colour mode). A high byte other than 1 or 2 would be kept in `raw_kind`. Pen-width records are left out before decoding and counted in the warnings: tag = colour + pen << 24, `0x4D4F3F` writes internal point (0, 0) with pen -99 ("reset width", high byte 0x9D, e.g. for notes with P28) and `0x4D4ED2` writes (999, w) with pen 99 ("set width", 0x63). They are print metadata; the shell would draw each as a one-point object, which the fixtures do not reproduce. `colour` is `[r, g, b]` from the engine's COLORREF. `paths` are the sub-paths (tag `0x03` starts a new one), decoded as `oracle/displaylist.py` mirrors `0x5A4570`/`0x5A4900`.
- **Texts**: one entry per engine font run. `height` = 64 × the stored f32 (engine units; `CreateFontA` height at zoom 64 is -16h thousandths of an inch), `width` = 64 × (stored f32 / 2), 0 = font default; both written as the shortest decimal that reads back as the same f32. `x`, `y` are the start of the **baseline**: the stored y **plus 96**, then translated like the shapes. `OnDraw` passes `TextOut` (alignment `TA_TOP`, y up) the cell top, which is this point plus the font's `tmAscent` (measured by the shell from the realised Windows font; `analysis/engine/display.md`), so the baseline is the font-independent quantity. Rotated runs (`escapement` in tenths of a degree, counter-clockwise) turn about the cell top, not the baseline origin (display.md).
- **`item`** (shapes and text runs): the 0-based index in `input.mus` of the item that drew the element, i.e. `ItemId` in `score-render`. It is the engine's draw-loop index at the moment the element's words (bytes) were written, captured with a memory-write hook. The engine's own per-item word ranges (`0x20359FC`) are not used: after some text items they start one triple late. Missing only if an element was written by several items (`meta.json` then warns). `score_testkit::restrict` and `assert_codes_match_fixture` compare only the elements of chosen items or codes.
- Staff numbers (a screen aid) are text runs in Helvetica-Narrow, colour `[0,115,51]`; `CompareOptions::ignore_staff_numbers` leaves them out.

## `meta.json`

`case`, `description`, `commands` (per command: status, the engine's line buffer afterwards, stream sizes), `items` and `paper` (from the document title the engine sets), `page_size` (from the frame), `page_frames`, `view_offset`, `view_globals`, `events` (engine messages, dialogs, prompts, command-bar text), `not_found` (symbol libraries the engine looked for and did not find; WinScore then shows a "Not found" dialog and draws nothing for that symbol, so the case stays valid), `valid`, `invalid_reasons`, `warnings`, `zoom_checked`.

A case is **invalid** when the engine shows a message box or calls a dialog (the oracle answers dialogs with defaults), waits for input, fails under emulation, draws the page frame elsewhere than the view globals predict, or produces different output at zoom `0x40` and `0x80`. Warnings mark doubts that do not invalidate it. The engine never checks its output buffers (disasm-expert); a warning appears only beyond what the shell can hold (about 1,000,000 vector words, 10,000 objects, 440,000 text bytes).
