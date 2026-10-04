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
- The engine evaluates in x87 double precision, stores every assignment to a REAL*4 variable, and truncates toward zero when a point is added. Port each Fortran statement as one f64 expression wrapped in `units::real(..)`; use REAL*4 constants as `f64::from(13.8_f32)`, not `13.8`; let `Canvas::point` truncate. Text positions use `units::nint`. See `analysis/engine/numerics.md`.

## Writing an item module

Each code has one file in `src/codes/` with

```rust
pub fn render(doc: &Document<'_>, item: ItemRef<'_>, canvas: &mut Canvas<'_>)
```

The dispatch table in `codes/mod.rs` already lists every module, so a new code touches no shared file.

- `item.p(n)`: parameter n as stored (f32, 0 if absent); `item.code()`, `item.staff()`.
- `doc.position(item)`: the reference point from P3/P4 (and P15 for the codes that use it), as item_position 0x5479AB computes it for every code.
- `doc.staff_of(item)` / `doc.staves.get(n)`: the staff table entry (`level0` = STAFF_Y, the y of P4 = 0; `step` = 25·size, one scale step is 7 steps; `y(p4)` = staff_level_y 0x547AA3).
- `doc.screen()`: screen output (editing aids, grey invisible items) versus print.
- `Canvas` is the engine's point buffer for this item: `point(pos, Pen)` (add_point), `segment(a, b)` (add_segment), `stroke(points)`, `fill(paths)`, `text(style, strings)`, and `buffer_mut()` for routines that rewrite buffered points. The buffer is flushed after `render` returns and decoded the way the C++ shell does, including the rule that a start point right after another start replaces it. `canvas.colour` starts as the item's P26 colour (`colour::from_p26`).
- Cite the engine routine a formula comes from in a short comment (`// barline_dots 0x412749`).

Shared primitives (library symbols, thick lines, curves, polygons) belong in modules outside `codes/`; ask render-core for them rather than copying code between item modules.

## Tests

`tests/fixtures.rs` compares every valid fixture with the rendering. It is a ratchet: the cases listed in `tests/expected_matching.txt` must match, all others are reported (`cargo test -p score-render --test fixtures -- --nocapture`). When your code makes a case match, add it to the list in the same commit.
