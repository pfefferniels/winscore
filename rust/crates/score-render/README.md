# score-render

Renders the items of a `.mus` file into a `DisplayList`. Items are placed where WinScore's engine places them, by its formulas and its REAL*4 numerics. How they are drawn follows SCORE's printed page instead of WinScore's screen: lines and the outlines of filled shapes with SCORE's PostScript pens and widths, smooth curves, and none of the screen's artefacts or engine bugs that only spoil the picture (see Drawing below). SCORE's house style (sizes, thickness defaults, stem lengths, spacing) is kept.

```rust
let file = score_format::MusFile::parse(&bytes)?;
let doc = score_render::Document::new(&file);      // or Document::with_options(&file, Options { .. })
let list = score_render::render(&doc);             // every Shape/TextRun has source: Some(ItemId(index))
```

`score-cli render in.mus -o out.svg` draws a file, `score-cli dump in.mus` prints the display list one shape per line.

## Coordinates and numbers

- **Display list**: page coordinates, 1/4000 inch, y up, origin at the bottom-left corner of the paper.
- **Modules** compute in the engine's **internal coordinates**: x = 150·P3 (P3 = 0 at x = 0), staff 1's bottom line at y = -24000. The canvas adds the page offset (`page::page_offset`, incl. +34050 for items on staves above 199).
- The engine evaluates in x87 double precision, stores every assignment to a REAL*4 variable, and truncates toward zero when a point is added. Write each statement as one f64 expression wrapped in `units::real(..)`; use REAL*4 constants as `units::constant(13.8)`, not `13.8`; let `Canvas::point` truncate. Text positions use `units::nint`; everything else truncates.

## Writing an item module

Each code has one file in `src/codes/` with

```rust
pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>)
```

The dispatch table in `codes/mod.rs` already lists every module, so a new code touches no shared file.

- `item.p(n)`: parameter n as stored (f32, 0 if absent); `item.ip(n)` = trunc(Pn), the engine's IPn; `item.code()`, `item.staff()`.
- `doc.position(item)`: the reference point from P3/P4 (and P15 for the codes that use it), as the engine computes it for every code.
- `doc.staff_of(item)` / `doc.staves.get(n)`: the staff table entry (`level0` = STAFF_Y, the y of P4 = 0; `step` = 25·size, one scale step is 7 steps; `y(p4)` the y of scale step P4).
- `doc.screen()`: screen output (editing aids, grey invisible items) versus print.
- `Canvas` is the engine's point buffer for this item: `point(pos, Pen)`, `segment(a, b)`, `stroke(points)`, `fill(paths)`, `text(style, strings)`, `set_width(w)` and `width()` (the pen of the shapes started next, see Drawing), and `buffer_mut()` for routines that rewrite buffered points. The buffer is flushed after `render` returns and decoded the way the C++ shell does, including the rule that a start point right after another start replaces it. `canvas.colour` starts as the item's P26 colour (`colour::of`).

### Shared primitives

Use these instead of writing local copies.

| Where | What |
|---|---|
| `units` | `real` (REAL*4 store), `constant` (REAL*4 constant), `trunc`, `nint`, `amod`, `Pos` |
| `geometry` | `rotate_points` (degrees clockwise), `rotate_points_radians` (radians counter-clockwise), `turned`, `outline_only` (filled parts as outlines, as P8 < 0 asks), `spline_through`; `print_width`, `PRINT_PIXEL`, `HAIRLINE` |
| `trig` | `CIRCLE`: the engine's table of 100·sin/100·cos per degree |
| `symbols` | `SymbolLibrary` (`doc.symbols()`), `draw_library_symbol`, `draw_scaled_symbol`, `draw_clef`, `draw_missing_symbol`, `ItemContext` (the item globals these read); outlines are smoothed once per symbol (`symbols::smooth`) |
| `codes::boxes` | `draw_box` with a `BoxCall`, with print widths |
| `codes::number` | `draw_number` with a `NumberCall` |
| `codes::line` | `draw` (the code-4 line) with a `Params` array |
| `codes::rest` | `draw` (a rest at an explicit X_POS) |
| `document` | `ItemRef::with_params` / `changed`: call a shared routine with parameters overwritten, as the engine's routines overwrite the parameter globals |
| `colour` | `of` (P26 as SCORE prints it), `SCREEN_INVISIBLE` |

## Drawing

Positions are the engine's; the drawing is not its screen's. Where something needs to know how it should look on paper, it follows SCORE's PostScript print output, which the engine writes when printing (OUTPUT_MODE == -1).

- Widths: outputs draw every polyline and every filled shape's outline with a pen, by default `PEN` (1/150 inch, the prologue's `wdl lw`). `canvas.set_width(w)` gives the shapes started after it a pen `w` engine units wide (0 is the default pen); set it back to 0 after the item's thick part, or restore the caller's (`canvas.width()`). SCORE's print routines set widths with a print-width marker `w` and reset them afterwards; `print_pen(w)` is the pen after such a marker, `geometry::print_width(w)` the same as a `set_width` argument. Use the `w` the print path passes, on every medium, where the engine's screen draws copies 14 units apart or rings. Widths in print pixels (barlines) count `geometry::PRINT_PIXEL`.
- Curves: library symbols are drawn as smoothed outlines of their stored polygons (`symbols::smooth`), slurs and ties along their curve sampled finely with the thickness along the normal, dots and repeat dots round.
- Engine bugs that only spoil the picture are not reproduced; each module says where it departs from the engine.
- `doc.screen()` keeps the editing aids of the screen: grey invisible items, white shown light grey, staff numbers, placeholders for missing symbols.

## Tests

Unit tests sit next to the code; some read the small scores in `tests/scores/`. `tests/rests.rs` checks that writing a rest's centre back into P9, as the engine's redraw does, leaves the picture of every centred rest in `tests/rests/` unchanged.
