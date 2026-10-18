# score-render

Renders the items of a `.mus` file into a `DisplayList` that should match the output of WinScore's engine (`analysis/ARCHITECTURE.md`, "Engine output") to ±1 unit. The formulas come from `analysis/engine/` (disasm-expert) and are checked against the emulated engine through the fixtures in `rust/fixtures/`.

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
- `Canvas` is the engine's point buffer for this item: `point(pos, Pen)` (add_point), `segment(a, b)` (add_segment), `stroke(points)`, `fill(paths)`, `text(style, strings)`, and `buffer_mut()` for routines that rewrite buffered points. The buffer is flushed after `render` returns and decoded the way the C++ shell does, including the rule that a start point right after another start replaces it. `canvas.colour` starts as the item's P26 colour (`colour::from_p26`).
- Cite the engine routine a formula comes from in a short comment (`// barline_dots 0x412749`).

### Shared primitives

Use these instead of writing local copies; ask render-core for anything else that more than one code needs.

| Where | What |
|---|---|
| `units` | `real` (REAL*4 store), `constant` (REAL*4 constant), `trunc`, `nint`, `amod` (0x54AABA), `Pos` |
| `geometry` | `rotate_points` (0x42A5F4, degrees clockwise), `rotate_points_radians` (its k0 <= 0 entry, radians counter-clockwise), `thicken` (0x42A8AE); `print_width`, `PRINT_PIXEL`, `HAIRLINE` for the refined style |
| `trig` | `CIRCLE`: the engine's table of 100·sin/100·cos per degree |
| `symbols` | `SymbolLibrary` (`doc.symbols()`), `draw_symbol` (core), `draw_library_symbol` (draw_symbol 0x4293F0), `draw_clef` (0x431AE0), `ItemContext` (the item globals these read) |
| `codes::boxes` | `draw_box` (0x433530) with a `BoxCall` |
| `codes::number` | `draw_number` (0x4F65A8) with a `NumberCall` |
| `codes::line` | `draw` (draw_line 0x439963) with a `Params` array, in the document's style |
| `codes::rest` | `draw` (draw_rest at an explicit X_POS) |
| `document` | `ItemRef::with_params` / `changed`: call a shared routine with parameters overwritten, as the engine's routines overwrite the parameter globals |
| `colour` | `from_p26` |

## Refined style

`Options::style` chooses between `Style::Engine`, the engine's display list to ±1 unit with its artefacts, and `Style::Refined` (score-web and score-cli draw it; `score-cli --engine` for the other), which keeps every item where the engine puts it but draws it better: lines with real widths instead of shifted copies, smooth curves. It keeps SCORE's house style (thickness defaults and profiles, curve heights, dash lengths, line positions); where it needs to know how something should look on paper, it follows SCORE's PostScript print output.

- Put every change to drawn output behind `doc.refined()`. Engine output stays byte-identical: the fixtures (`cargo test --workspace`) run in Engine style.
- Widths: `canvas.set_width(w)` gives the shapes started after it a pen `w` engine units wide (0 is the default pen, `PEN` = 1/150 inch); set it back to 0 after the item's thick part. SCORE's print routines set widths with the marker 0x4D4ED2(&w) (`thunk_FUN_004d4ed2` in `analysis/engine/decompiled_all/`, called when OUTPUT_MODE == -1) and reset them with 0x4D4F3F; `print_pen(w)` is the pen after such a marker, `geometry::print_width(w)` the same as a `set_width` argument. Use the `w` the print path passes, on every medium, instead of the screen's copies (`geometry::thicken`, 14 units apart) or rings. Widths in print pixels (barlines, 0x4CF0D3 called directly) count `geometry::PRINT_PIXEL`.

## Tests

`tests/fixtures.rs` compares every valid fixture with the rendering. It is a ratchet: the cases listed in `tests/expected_matching/*.txt` must match, all others are reported (`cargo test -p score-render --test fixtures -- --nocapture`). There is one list per code (`code06.txt`, …), owned by that code's implementer; when your code makes a case match, add it to your list in the same commit (create the file if it does not exist yet).
