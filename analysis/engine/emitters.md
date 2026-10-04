# Emitters: point buffer and vector stream

## Point buffer (verified)

Drawing routines never write the output directly. They append points:

| Name | Address | Type |
|---|---|---|
| PT_X(k) | 0x1FD3F7C + 4k | int |
| PT_Y(k) | 0x2004CBC + 4k | int |
| PT_PEN(k) | 0x1FBB8DE + 2k | int16 |
| NPT | 0x2049280 | next free k; 1 = empty |

- `add_point(&x, &y, &pen)` (0x44B820): PT_X = trunc(x), PT_Y = trunc(y), PT_PEN = pen, NPT += 1. x, y are f32 variables.
- `add_segment(&x0, &y0, &x1, &y1)` (0x44B8B1): add_point with pen 1 (int16 constant at 0x760CB4), then with pen 0 (0x760CB0).

Print-mode markers: `0x4D4ED2(&w)` appends the point (999, BMTH-scaled width, pen 99) and `0x4D4F3F` appends (0, 0, pen -99) to set and reset the PostScript line width. They are called around thick lines when OUTPUT_MODE == -1 (and from a few text paths). None appears in the screen output of the four sample scores (no tag bytes other than 0, 1, 2, 3).

Pens: 1 starts a stroked polyline, 2 starts a filled polygon, 3 starts a further sub-path of the same polygon, 0 continues (meanings as decoded by the C++ shell, ARCHITECTURE.md). The engine also writes the buffer directly in a few places (e.g. `barline_gap`).

## Flush (verified)

`flush_points` (0x54A497) sets COLOR from P26 (placement.md) and calls `emit_points` (0x54A69C), which for k = 1..NPT-1 writes three int words at the vector index VEC_N (int 0x1FBB848, through the Fortran array descriptor at 0x1FBB7A0/0x1FBB7B8/0x1FBB7BC that points at the shell buffer 0x9C73D8):

```
x_out = PT_X(k) + VIEW_DX (+ 34050 if P2 > 199)
y_out = PT_Y(k) - VIEW_DY
tag   = COLOR + PT_PEN(k) << 24
if PT_PEN(k) != 0 and VEC_LAST_PEN != 0:  VEC_N -= 3      # a start right after a start replaces it
VEC_N += 3;  VEC_LAST_PEN = PT_PEN(k) << 24
```

then NPT = 1. VEC_LAST_PEN (int 0x1FBB7C4) is reset only at the start of `draw_items`, so the replacement rule also works across item boundaries. When EDIT_ITEM != 0 the routine also tracks the output bounding box (0x1A1C360..0x1A1C374).

`draw_items` calls `flush_points` once per item (after `draw_item`, when NPT > 1). Long routines flush themselves in between (the page frame does, via `draw_item`).

The word count reported to the shell (int 0x1576468) is set by the interpreter at the end of the command.

## Text stream

Text records (format in ARCHITECTURE.md) are written by the text routines: for the staff number the chain is `draw_staff_number` > `draw_number` 0x4F65A8 > `draw_text` 0x569AF0 > 0x532EC0. To be documented with codes 10 and 16.
