# Coordinates

## Internal coordinates (verified)

The drawing routines work in engine units of 1/4000 inch, y growing upward, in what this file calls **internal coordinates**:

- `x = 150 * P3`, so P3 = 0 is x = 0 and P3 = 200 is x = 30000 (7.5 in). Item-specific offsets are added on top (P15 for some codes, see placement.md).
- y is fixed by the staff tables (staves.md). With default staves, staff n has its bottom line at `(n+1)*3150 - 30300`: staff 1 at -24000, staff 2 at -20850.

Experiment: `experiments/staves.py`.

## Output transform (verified)

`emit_points` (0x54A69C) writes each point as

```
x_out = x + VIEW_DX (+ 34050 if the item's P2 > 199)
y_out = y - VIEW_DY
```

| Global | Address | Value |
|---|---|---|
| VIEW_DX | int 0x20527F0 | 2400 after loading a score (set by 0x4A6BAA and 0x494026) |
| VIEW_DY | int 0x20527F4 | depends on the score, see below; -15000 if still 0 when the first staff is drawn |

The recto offset 34050 (8.5125 in) applies to all items whose P2 (as float) exceeds 199. Staves 200–256 also reuse the vertical positions of staves 1–57 (staves.md), so staff 201 is drawn exactly like staff 1, shifted 34050 to the right. Help text: "staves 201 to 256 are reserved for an added page offset to the right (RECTO position)".

### How VIEW_DY is chosen (read; verified for simple cases)

`redraw` (0x494026) calls `fit_view` (0x54ED0E). `fit_view` first runs `draw_items` once without the page frame, then scans the vector output of every item (per-item word ranges at 0x20359FC/0x2035A00) for the bounding box, with special cases for some codes (text, library symbols, boxes). Finally

```
VIEW_DY = max_y + 3000        (max_y in internal coordinates; -1000 more for one command form)
```

and the caller redraws. So the topmost vector point of the score lands at y_out = -3000. Examples: one staff 1 gives VIEW_DY = -19600 (top line -22600); staves 1 and 2 give -16450.

For comparisons with the oracle, read the two globals after the command and convert the output back:

```python
x_internal = x_out - engine.i32(0x20527F0) - (34050 if item_p2 > 199 else 0)
y_internal = y_out + engine.i32(0x20527F4)
```

Caveat: a staff whose P10 refers to itself (staff 1 with P10 != 0) moves on every draw, so the trial draw in `fit_view` and the final draw disagree. The help says to leave P10 = 0 on staff 1.

## Page frame (verified for position, read for construction)

`draw_page_frame` (0x54CE39) draws the green page outline (COLORREF 0x00FD00) first in every redraw, as three nested rectangles 25 units apart, through `draw_item` as a code-12 box on staff 0 with P26 = 9900. The paper type is the int PAPER at 0x791638 (2 = Legal after start-up from the bundled PREF.DAT). Paper bottom-left is at internal (-2000, -26947.7) for every type: the left edge is 0.5 in left of P3 = 0, the bottom edge is 4.156 scale steps of staff 0 above STAFF_Y(0) = -27675.

| PAPER | Title | Size (in) | Frame x range | Frame y range |
|---|---|---|---|---|
| 0 | (none) | no frame | | |
| 1 | Letter | 8.5 x 11 | -1999 .. 31999 | -26947 .. 17052 |
| 2 | Legal | 8.5 x 14 | -1999 .. 31999 | -26947 .. 29051 |
| 3 | Ledger | 11 x 17 | -1999 .. 41999 | -26947 .. 41051 |
| 4 | Double | 17 x 11 (two pages) | -1999 .. 65999 | -26947 .. 17125 |
| 5 | A3 | 11.7 x 16.5 | -1999 .. 44799 | -26947 .. 39051 |
| 6 | A4 | 8.3 x 11.7 | -1999 .. 31199 | -26947 .. 19852 |
| 7 | B4 | 9.8 x 13.9 | -1999 .. 37199 | -26947 .. 28651 |
| 8 | Custom | from 0x791630/0x791634 (9 x 12 by default) | -1999 .. 33999 | -26947 .. 21052 |

The ranges are those of the innermost rectangle in internal coordinates (experiment `experiments/page_frame.py`). The frame is a screen aid; it is not part of the score. The exact vertex sequence follows from the code-12 box routine and will be documented with boxes.

## Units elsewhere

- P3 runs 0–200 across 7.5 in (150 units per P3 unit).
- One scale step of a staff of size s is 175·s units (7 × STEP, STEP = 25·s). Library symbol units are 25·s (FORMATS.md).
- P10 of a staff and P8 of a staff are in inches (4000 units; /2.54 with metric measurement, flag int 0x78B4E8).
