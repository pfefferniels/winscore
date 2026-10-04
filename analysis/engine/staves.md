# Staves (code 8)

Routine `draw_staff` 0x545140, called from `draw_item` for code 8 (no P15 offset). Decompilation: `decompiled/545140_draw_staff.c`. The model below matched the engine on 1000 random staves (P2 including recto staves, fractional P3/P4/P5/P6, P7 variants, P8, P14): `experiments/staves.py`. **verified** unless marked.

Notation: P(k) floats of the item, IP(k) = trunc(P(k)), f32(·) = round to single precision (numerics.md), trunc(·) toward zero. All y are internal coordinates (coordinates.md).

## Size

```
if P14 != 0:  P5 = f32(P14 / f32(0.889))      # staff height in cm; 0.889 cm = 0.35 in; P5 is overwritten
s    = P5 if P5 != 0 else 1
STEP = f32(25 * s)                             # stored as STAFF_STEP(n); one scale step = 7*STEP = 175*s
```

## Vertical position

```
base(n) = (n + 1) * 3150 - 30300     for n <= 199
        = (n - 199) * 3150 - 30300   for n >= 200       # staff 201 sits where staff 1 does
```

Staff 1 is at -24000, and staff numbers are 3150 units (18 size-1 scale steps: 8 for the staff plus the 10-step gap the help mentions) apart, independent of P5.

- **P10 == 0:** `bottom = f32(base(n) + P4 * 7 * STEP)`. P4 is in scale steps of this staff's own size. P4 >= 1000 does not draw: 0x546910 formats an error message instead.
- **P10 != 0** (P4 ignored): reference staff `r = IP10 / 100` (integer division, 0 becomes 1), inches `d = amod(P10, 100)`, and
  `bottom = f32(STAFF_Y(r) + STAFF_STEP(r)*21 + d*4000)` (d*4000/2.54 in metric mode). So P10 = 1.5 and 101.5 both mean 1.5 in above staff 1's bottom line, and 201.5 means 1.5 in above staff 2. Checked for these three values.

Tables written for later items:

| Table | Address | Value |
|---|---|---|
| STAFF_Y(n) | int 0x2052C24 + 4n | trunc(bottom - 21*STEP): the level of P4 = 0, three steps below the bottom line |
| STAFF_MID(n) | int 0x2053028 + 4n | trunc(STAFF_Y(n) + 1225*s): the middle line (P4 = 7) |
| STAFF_STEP(n) | f32 0x2052804 + 4n | STEP |
| colour | f32 0x78D898 + 4n | P26 (index 0 holds MAX_STAFF = 256) |
| thickness | int 0x1A9E220 + 4n | IP11, or -1 when IP11 = 0 and s < 0.65 |

**Staves without a code-8 item** keep the defaults filled at start-up: STAFF_Y(n) = base(n) - 525, STEP = 25 (read from memory with only staves 1 and 2 in the file: STAFF_Y(3) = -18225). Items on such staves are placed as on a size-1 staff at its default position.

## Lines

```
x0 = f32(150 * P3)                         # X_POS from item_position
x1 = f32(150 * P6) if P6 != 0 else 30000
spacing = f32(STEP * 14)                   # two scale steps
L = IP7 if IP7 > 0 else 5
if L > 99:
    if L // 100 > 1:  bottom' = f32((L // 100 - 1) * spacing + bottom)   # "XYZ": line X of a normal staff becomes the bottom line
    L = L % 100
y = bottom'
repeat L times:
    segment (trunc(x0), trunc(y)) -> (trunc(x1), trunc(y))
    y = f32(spacing + y)
```

Each segment becomes two points with pens 1 and 0 (emitters.md). Lines are emitted bottom to top.

- **P8 != 0** (not in the help text): before the lines, one extra segment from x0 to 30000 (P6 is not applied) at `y = f32(4000*P8 + bottom)` (1574.8*P8 in metric mode). Only when OUTPUT_MODE >= 0. P8 is in inches.
- **P7 < 0** (invisible): drawn only when OUTPUT_MODE != -1 and the INVIS toggle (int 0x7924C0) is >= 0, with P26 forced to 0.8, i.e. COLORREF 0xCCCCCC, and 5 lines (verified for P7 = -1).
- **P11, thickness:** only used when OUTPUT_MODE == -1 (print), through 0x4D4ED2/0x4D4F3F around the lines. On screen there is no thickness: each line is a 2-point polyline. P11 = 99 is cleared. (read)
- **P26:** colour of the lines, see placement.md.

## Staff number (screen only)

If IP12 == 0 and OUTPUT_MODE >= 0, `draw_staff_number` 0x545DE0 writes the staff number as text, through the code-10 number routine `draw_number` 0x4F65A8:

- x_internal = -1200 (-1700 for n >= 100) when X_POS >= 0, else X_POS - 1200;
- reference y = staff_level_y(6.0), i.e. STAFF_Y(n) + 6*7*STEP;
- P5 = n, P6 = 1/s, P26 = 4520 (COLORREF 0x003373), IP7 = 1008, P8 = 0, P14–P24 cleared.

Observed text record: font "Helvetica-Narrow", height 12.10625 (f32 in the record), staff 1 at y_internal = reference - 100. Exact text placement belongs to code 10 and will be documented there.

## Order of emission per staff item

P8 line (if any), the L lines, then the staff-number text record. The page frame and every other item are separate flushes (dispatch.md).
