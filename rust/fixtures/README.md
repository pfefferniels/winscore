# Engine fixtures

Reference output of WinScore's engine (WScore.exe under emulation, `oracle/`) for small `.mus` files. Written by `oracle/fixtures.py` from the case list in `oracle/fixtures_cases.py`; read by the crate `score-testkit`. The case plan is in `PLAN.md`, the current match table in `STATUS.md`.

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
- **Coordinates**: engine units of 1/4000 inch, y up, origin at the bottom-left corner of the paper. The engine's own stream is in view coordinates (`G` scrolls so that the top line of the highest visible staff is at y = -3000). The view draws the paper as a green (`0x00FD00`) polyline of three nested rectangles, the innermost one unit inside the paper edge; `oracle/fixtures.py` recognises it by that structure, removes it, and subtracts `view_offset` = (inner left - 1, inner bottom - 1) from every point. `meta.json` keeps `view_offset` and `page_frames`, so the raw stream can be reconstructed: view = page + view_offset.
- **Shapes**: `kind` is `"stroke"` when the first tag's high byte is 1 (polyline, one-unit pen) and `"fill"` otherwise (even-odd polygon set, as `OnDraw` treats it in colour mode). A high byte other than 1 or 2 would be kept in `raw_kind`; none has been seen. `colour` is `[r, g, b]` from the engine's COLORREF. `paths` are the sub-paths (tag `0x03` starts a new one), decoded as `oracle/displaylist.py` mirrors `0x5A4570`/`0x5A4900`.
- **Texts**: one entry per engine font run. `height` = 64 × the stored f32 (engine units; `CreateFontA` height at zoom 64 is -16h thousandths of an inch), `width` = 64 × (stored f32 / 2), 0 = font default; both written as the shortest decimal that reads back as the same f32. `x`, `y` are the top-left of the character cell as `TextOut` receives it, i.e. the stored y **plus 96**, then translated like the shapes. This matches `PlacedText::origin` in `score-render`. `OnDraw` also adds a per-run offset from `0x1576570`; it has been zero in every case so far, and `meta.json` warns if not.
- Staff numbers (a screen aid) are text runs in Helvetica-Narrow, colour `[0,115,51]`; `CompareOptions::ignore_staff_numbers` leaves them out.

## `meta.json`

`case`, `description`, `commands` (per command: status, the engine's line buffer afterwards, stream sizes), `items` and `paper` (from the document title the engine sets), `page_size` (from the frame), `page_frames`, `view_offset`, `events` (engine messages, dialogs, prompts, command-bar text), `valid`, `invalid_reasons`, `warnings`, `zoom_checked`.

A case is **invalid** when the engine shows a message box or calls a dialog (the oracle answers dialogs with defaults), waits for input, fails under emulation, emits no page frame, or produces different output at zoom `0x40` and `0x80`. Warnings mark doubts that do not invalidate it, e.g. a vector stream longer than the 100,000 words ARCHITECTURE.md mentions (carmen and sonlcs exceed it with plausible output; the real limit is being checked).
