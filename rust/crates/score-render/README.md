# score-render

Renders the items of a `.mus` file into a `DisplayList`. Items are placed exactly where WinScore's engine places them: the formulas come from `analysis/engine/` (disasm-expert) and were checked against the emulated engine to ±1 unit through the fixtures in `rust/fixtures/`. How they are drawn follows SCORE's printed page instead of WinScore's screen: lines and the outlines of filled shapes with SCORE's PostScript pens and widths, smooth curves, and none of the screen's artefacts or engine bugs that only spoil the picture (see Drawing below). SCORE's house style (sizes, thickness defaults, stem lengths, spacing) is kept.

```rust
let file = score_format::MusFile::parse(&bytes)?;
let doc = score_render::Document::new(&file);      // or Document::with_options(&file, Options { .. })
let list = score_render::render(&doc);             // every Shape/TextRun has source: Some(ItemId(index))
```

`score-cli render in.mus -o out.svg` draws a file, `score-cli dump in.mus` prints the display list one shape per line.

## Coordinates and numbers

- **Display list**: page coordinates, 1/4000 inch, y up, origin at the bottom-left corner of the paper (the fixtures use the same frame).
- **Modules** compute in the engine's **internal coordinates**: x = 150·P3 (P3 = 0 at x = 0), staff 1's bottom line at y = -24000. The canvas adds the page offset (`page::page_offset`, incl. +34050 for items on staves above 199).
- The engine evaluates in x87 double precision, stores every assignment to a REAL*4 variable, and truncates toward zero when a point is added. Port each Fortran statement as one f64 expression wrapped in `units::real(..)`; use REAL*4 constants as `units::constant(13.8)`, not `13.8`; let `Canvas::point` truncate. Text positions use `units::nint` (the engine's 67 NINT sites; everything else truncates). See `analysis/engine/numerics.md`.

## Writing an item module

Each code has one file in `src/codes/` with

```rust
pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>)
```

The dispatch table in `codes/mod.rs` already lists every module, so a new code touches no shared file.

- `item.p(n)`: parameter n as stored (f32, 0 if absent); `item.ip(n)` = trunc(Pn), the engine's IPn; `item.code()`, `item.staff()`.
- `doc.position(item)`: the reference point from P3/P4 (and P15 for the codes that use it), as item_position 0x5479AB computes it for every code.
- `doc.staff_of(item)` / `doc.staves.get(n)`: the staff table entry (`level0` = STAFF_Y, the y of P4 = 0; `step` = 25·size, one scale step is 7 steps; `y(p4)` = staff_level_y 0x547AA3).
- `doc.screen()`: screen output (editing aids, grey invisible items) versus print.
- `Canvas` is the engine's point buffer for this item: `point(pos, Pen)` (add_point), `segment(a, b)` (add_segment), `stroke(points)`, `fill(paths)`, `text(style, strings)`, `set_width(w)` and `width()` (the pen of the shapes started next, see Drawing), and `buffer_mut()` for routines that rewrite buffered points. The buffer is flushed after `render` returns and decoded the way the C++ shell does, including the rule that a start point right after another start replaces it. `canvas.colour` starts as the item's P26 colour (`colour::of`).
- Cite the engine routine a formula comes from in a short comment (`// barline_dots 0x412749`).

### Shared primitives

Use these instead of writing local copies; ask render-core for anything else that more than one code needs.

| Where | What |
|---|---|
| `units` | `real` (REAL*4 store), `constant` (REAL*4 constant), `trunc`, `nint`, `amod` (0x54AABA), `Pos` |
| `geometry` | `rotate_points` (0x42A5F4, degrees clockwise), `rotate_points_radians` (its k0 <= 0 entry, radians counter-clockwise), `turned`, `outline_only` (thicken 0x42A8AE with n <= 0), `spline_through`; `print_width`, `PRINT_PIXEL`, `HAIRLINE` |
| `trig` | `CIRCLE`: the engine's table of 100·sin/100·cos per degree |
| `symbols` | `SymbolLibrary` (`doc.symbols()`), `draw_library_symbol` (draw_symbol 0x4293F0), `draw_scaled_symbol`, `draw_clef` (0x431AE0), `draw_missing_symbol`, `ItemContext` (the item globals these read); outlines are smoothed once per symbol (`symbols::smooth`) |
| `codes::boxes` | `draw_box` (0x433530) with a `BoxCall`, with print widths |
| `codes::number` | `draw_number` (0x4F65A8) with a `NumberCall` |
| `codes::line` | `draw` (draw_line 0x439963) with a `Params` array |
| `codes::rest` | `draw` (draw_rest at an explicit X_POS) |
| `document` | `ItemRef::with_params` / `changed`: call a shared routine with parameters overwritten, as the engine's routines overwrite the parameter globals |
| `colour` | `of` (P26 as SCORE prints it), `SCREEN_INVISIBLE` |

## Drawing

Positions are the engine's; the drawing is not its screen's. Where something needs to know how it should look on paper, it follows SCORE's PostScript print output, which the engine writes when printing (OUTPUT_MODE == -1).

- Widths: outputs draw every polyline and every filled shape's outline with a pen, by default `PEN` (1/150 inch, the prologue's `wdl lw`). `canvas.set_width(w)` gives the shapes started after it a pen `w` engine units wide (0 is the default pen); set it back to 0 after the item's thick part, or restore the caller's (`canvas.width()`). SCORE's print routines set widths with the marker 0x4D4ED2(&w) (`thunk_FUN_004d4ed2` in `analysis/engine/decompiled_all/`) and reset them with 0x4D4F3F; `print_pen(w)` is the pen after such a marker, `geometry::print_width(w)` the same as a `set_width` argument. Use the `w` the print path passes, on every medium, where the engine's screen draws copies 14 units apart (thicken 0x42A8AE) or rings. Widths in print pixels (barlines, 0x4CF0D3 called directly) count `geometry::PRINT_PIXEL`.
- Curves: library symbols are drawn as smoothed outlines of their stored polygons (`symbols::smooth`), slurs and ties along their curve sampled finely with the thickness along the normal, dots and repeat dots round.
- Engine bugs that only spoil the picture are not reproduced; each module says where it departs from the engine (and `analysis/engine/*.md` under "What the port draws differently").
- `doc.screen()` keeps the editing aids of the screen: grey invisible items, white shown light grey, staff numbers, placeholders for missing symbols.

## Tests

Unit tests sit next to the code. `tests/rests.rs` checks that writing a rest's centre back into P9, as the engine's redraw does, leaves its picture unchanged. The fixtures in `rust/fixtures/` are WinScore's own output; the drawing no longer matches it, but `score-testkit`'s `score-compare` and `score-triage` still show how far a rendering is from it, and an item placed wrongly shows up there as a large difference.
