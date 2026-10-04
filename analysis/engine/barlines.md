# Barlines, braces, brackets (code 14)

Routine `draw_barline` 0x4117B0 (`decompiled/4117b0_draw_barline.c`), called from `draw_item` between `push_words(13, &P3)` and `pop_words(13, &P3)`, so P3..P15 are restored afterwards. Types 0, 1, 2 and the P6 thick bar matched the engine on 1000 random barlines (`experiments/barlines.py`, varying P2, P3, P4 incl. 999, P6, P7, P8, P10, P11, P13, P15, P17). Other types: positions verified on single examples (`experiments/barline_types.py`), construction read.

## Common set-up

```
xb = X_POS                                    # f32(150*P3), plus f32(150*P15 + ...) if P15 != 0
if P7 != 0 and P15 == 0:  xb = f32(P7 * 150 + xb)
k  = IP4                                      # staves spanned
if k == 999:  k = highest staff number with a code-8 item - IP2 + 1, and P10 = P11 = 0   (0x54E546)
t  = IP5;  if t == -44:  t = 0, P5 = 0, and a two-bar repeat sign is drawn after the bar (draw_rest with IP5 = -44)
if k < 0:  invisible: skipped when printing (OUTPUT_MODE < 0 or INVIS toggle int 0x7924C0 < 0);
           on screen k = -k and the bar becomes type 7 (dashed) with P8 = 0.3, P9 = 1.5
k = min(k, 256 - IP2 + 1);  if k == 0: k = 1
v_bot = P10 if P10 != 0 else (3 if t < 9 else 7 if t == 10 else 1)
v_top = P11 if P11 != 0 else (11 if t < 9 else 7 if t == 10 else 13)
y_bot = staff_level_y(v_bot) on staff IP2                     # f32(STAFF_Y + v*7*STAFF_STEP)
y_top = staff_level_y(v_top) on staff IP2 + k - 1
W = STEP (of staff IP2), or f32(25 * P17) if P17 != 0        # int 0x2052C08, the spacing unit
d13 = f32(f32(W*6) * P13);  d14 = f32(f32(W*6) * P14)        # extra spacing (types 1-6)
```

With default staves and no P10/P11, a bar spanning staves a..b runs from the bottom line of a to the top line of b.

## Primitives

- **stroke(x)** (`barline_stroke` 0x412699): points (x, y_bot, pen 1), (x, y_top, pen 0). When printing (OUTPUT_MODE == -1) a second stroke at x + f32 0x78B480 follows (a device pixel; 0 on screen).
- **thick(a, b)** (block at 0x411FAD; a, b are the f32 globals 0x1F95D68, 0x1F95D6C), emitted exactly so:
  `(a, y_bot, 1) (b, y_top, 0) (b, y_top, 2) (b, y_bot, 0) (a, y_bot, 0) (a, y_top, 0) (b, y_top, 0)`,
  then one more `(b, y_top, 0)` if IP8 is 0 or 1. The first two points form a diagonal hairline polyline, the rest a filled rectangle. For types 2–6, a = f32(xb - 6W) and b = xb. Type 10 enters this block after the first three points (see below).
- **dots(f)** (`barline_dots` 0x412749): repeat dots at x = f32(W*f + X_POS) on every spanned staff, see below.

All x and y are truncated when added (add_point).

## Types

| t | Meaning (help: D, H, L, R, RD, BK, BC) | Construction |
|---|---|---|
| 0 | single bar | stroke(xb). If P6 != 0: thick(f32(xb - (P6+1)*px), xb) with px = f32 0x78B480 (0 on screen, so zero width). verified |
| 1 | double bar (D) | stroke(xb), stroke(f32((xb - W*7.5) - d13)). verified |
| 2 | final bar (H) | stroke(f32((xb - W*13.8) - d13)), thick(f32(xb - W*6), xb). verified |
| 3 | repeat, dots left (L) | X_POS -= d13 + d14; dots(-25.5); then as type 2 |
| 4 | repeat, dots right (R) | stroke(f32(W*7.8 + xb + d13)); X_POS += d13 + d14; dots(19.5); thick(xb - 6W, xb) |
| 5 | double repeat | as 4, then X_POS -= d13 + d14 and as 3 (dots(-25.5), thin, thick) |
| 6 | double repeat, two thick bars (RD) | X_POS -= d14; dots(-18.36); X_POS += d13 + 2*d14; dots(25.2); thick(xb - 6W, xb); xb = f32(W*13 + xb + d13); thick(xb - 6W, xb) |
| 7 | dashed | via `draw_line` (code 4) 0x439963 with P5 = (y_top - STAFF_Y)/(7*STEP) as end level, P6 = P3, IP7 = 1, IP10 = (OUTPUT_MODE != 0) or IP6, P8 dash (default 1), P9 space (default 2) |
| 8 | brace (BC) | `barline_brace` 0x412B93: the clef routine 0x431AE0 with IP1 = 3, IP5 = 5, height factor h = (y_top - y_bot)*0.0054945/STEP, width factor P6 or (h-1)/2 + 1, at Y_POS = y_bot - 21*STEP |
| 9 | bracket (BK) | `barline_bracket` 0x412A20 (unless IP8 == 3) draws the curved ends: per end a start point (X_POS - 12W, y_end - 33·0.15W·sign, pen 2) and 12 points (X_POS - 12W + 0.15W·tx[i], y_end + 0.15W·sign·ty[i]) from the f32 tables tx at 0x78B264.. and ty at 0x78B234..; IP8 = 0: top end then bottom end (sign + at the top, - at the bottom), 1: top only, 2: bottom only, 3: no ends. The routine leaves IP8 = 1, so the extra closing point of thick() is always present after drawn ends. Then thick(a = f32(xb - 9.6W), b = f32(a - 4.5W)). Default levels 1 and 13 |
| 10 | (not named in the help) | levels 7 and 7; b = f32(xb - 21W), a = f32(b - 15W); points (b, y, 1) (a, y, 0) if IP8 is 0 or 2, else (a, y, 1); then (a, y, 0), and (b, y, 0) twice if IP8 is 0 or 1. A horizontal stroke left of the bar on the middle line |

Pen sequences for types 3–10 have only been compared on single examples (`experiments/barline_types.py`). The repeat-dot shape and the brace and bracket outlines depend on the code-12 box, code-3 clef and code-4 line routines; they will be specified with those codes.

### Repeat dots (read, positions verified)

`barline_dots(&f, &k)`: for each staff m = IP2 .. min(IP2+k-1, 256):

```
lower level  = 6        (P16 = 0)      upper level = lower + 2
P16 = xyz:  lower = x,  upper = yz                  # e.g. 410: levels 4 and 10
dot size     P6 = 0.58 * (P12 if P12 != 0 else 1)
y of a dot   = STAFF_Y(m) + level*7*STAFF_STEP(m)
x            = f32(W*f + X_POS)
```

Each dot is drawn by `draw_box` (0x433530) as a code-12 box with IP5 = 1 and P6 = P7 = dot size, IP12 = 60 on screen. On screen a dot at size 1 comes out as a 6-gon of about 88 x 101 units (e.g. centre (16762, -23474.5) internal for type 3 at P3 = 100).

### P18/P19: gap in the bar (read)

`barline_gap` 0x412353, only when P18 != 0 and P5 < 2: the stroke points already in the buffer are replaced by two strokes per line, bottom..gap_lo and gap_hi..top, with

```
f   = P18 if P18 <= 1 else P18/100              # fraction of the height from the bottom
c   = f*(y_top - y_bot) + y_bot
g   = STEP * P19 * 7                            # gap size in scale steps
gap_lo = c - g/2,  gap_hi = gap_lo + g
```

Two lines for type 1, doubled again when printing.
