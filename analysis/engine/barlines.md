# Barlines, braces, brackets (code 14)

Routine `draw_barline` 0x4117B0 (`decompiled/4117b0_draw_barline.c`), called from `draw_item` between `push_words(13, &P3)` and `pop_words(13, &P3)`, so P3..P15 are restored afterwards. Types 0–6, the P6 thick bar and the repeat dots matched the engine on 1000 random barlines (`experiments/barlines.py`, varying P2, P3, P4 incl. 999, P5, P6, P7, P8, P10–P17). Types 7–10: positions checked on single examples (`experiments/barline_types.py`), construction read.

## Common set-up

```
if P7 != 0 and P15 == 0:  X_POS = f32(P7 * 150 + X_POS)    # X_POS = f32(150*P3), + 150*P15 from draw_item
xb = X_POS                                    # bar x (f32 0x1F95D58); the dots use X_POS
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
d13 = f32(W*6*P13);  d14 = f32(W*6*P14)                      # extra spacing (types 1-6)
```

With default staves and no P10/P11, a bar spanning staves a..b runs from the bottom line of a to the top line of b.

## Primitives

- **stroke(x)** (`barline_stroke` 0x412699): points (x, y_bot, pen 1), (x, y_top, pen 0). When printing (OUTPUT_MODE == -1) a second stroke at x + f32 0x78B480 follows (a device pixel; 0 on screen).
- **thick(a, b)** (block at 0x411FAD; a, b are the f32 globals 0x1F95D68, 0x1F95D6C), emitted exactly so:
  `(a, y_bot, 1) (b, y_top, 0) (b, y_top, 2) (b, y_bot, 0) (a, y_bot, 0) (a, y_top, 0) (b, y_top, 0)`,
  then one more `(b, y_top, 0)` if IP8 is 0 or 1. `barline_dots` sets IP8 = 0, so after repeat dots the extra point is always there. The first two points form a diagonal hairline polyline, the rest a filled rectangle. For types 2–6, a = f32(xb - 6W) and b = xb. Type 10 enters this block after the first three points (see below).
- **dots(f)** (`barline_dots` 0x412749): repeat dots at x = f32(W*f + X_POS) on every spanned staff, see below.

All x and y are truncated when added (add_point).

## Types

| t | Meaning (help: D, H, L, R, RD, BK, BC) | Construction |
|---|---|---|
| 0 | single bar | stroke(xb). If P6 != 0: thick(f32(xb - (P6+1)*px), xb) with px = f32 0x78B480 (0 on screen, so zero width). verified |
| 1 | double bar (D) | stroke(xb), stroke(f32((xb - W*7.5) - d13)). verified |
| 2 | final bar (H) | stroke(f32((xb - W*13.8) - d13)), thick(f32(xb - W*6), xb). verified |
| 3 | repeat, dots left (L) | X_POS = f32((X_POS - d13) - d14); dots(-25.5); stroke(f32((xb - W*13.8) - d13)); thick(xb - 6W, xb). verified |
| 4 | repeat, dots right (R) | stroke(f32(W*7.8 + xb + d13)); X_POS = f32(d13 + X_POS + d14); dots(19.5); thick(xb - 6W, xb). verified |
| 5 | double repeat | as 4 up to dots(19.5); then X_POS = f32((X_POS - d13) - d14) twice; dots(-25.5); stroke(f32((xb - W*13.8) - d13)); thick(xb - 6W, xb). verified |
| 6 | double repeat, two thick bars (RD) | X_POS = f32(X_POS - d14); dots(-18.36); X_POS = f32(d13 + X_POS + d14 + d14); dots(25.2); thick(xb - 6W, xb); xb = f32(W*13 + xb + d13); thick(xb - 6W, xb). verified |
| 7 | dashed | via `draw_line` (code 4) 0x439963 with P5 = (y_top - STAFF_Y)/(7*STEP) as end level, P6 = P3, IP7 = 1, IP10 = (OUTPUT_MODE != 0) or IP6, P8 dash (default 1), P9 space (default 2) |
| 8 | brace (BC) | `barline_brace` 0x412B93: the clef routine 0x431AE0 with IP1 = 3, IP5 = 5, height factor h = (y_top - y_bot)*0.0054945/STEP, width factor P6 or (h-1)/2 + 1, at Y_POS = y_bot - 21*STEP |
| 9 | bracket (BK) | `barline_bracket` 0x412A20 (unless IP8 == 3) draws the curved ends: per end a start point (X_POS - 12W, y_end - 33·0.15W·sign, pen 2) and 12 points (X_POS - 12W + 0.15W·tx[i], y_end + 0.15W·sign·ty[i]) from the f32 tables tx at 0x78B264.. and ty at 0x78B234..; IP8 = 0: top end then bottom end (sign + at the top, - at the bottom), 1: top only, 2: bottom only, 3: no ends. The routine leaves IP8 = 1, so the extra closing point of thick() is always present after drawn ends. Then thick(a = f32(xb - 9.6W), b = f32(a - 4.5W)). Default levels 1 and 13 |
| 10 | (not named in the help) | levels 7 and 7; b = f32(xb - 21W), a = f32(b - 15W); points (b, y, 1) (a, y, 0) if IP8 is 0 or 2, else (a, y, 1); then (a, y, 0), and (b, y, 0) twice if IP8 is 0 or 1. A horizontal stroke left of the bar on the middle line |

All constants (7.5, 7.8, 13, 13.8, 6, -25.5, 19.5, -18.36, 25.2) are f32. Pen sequences for types 7–10 have only been compared on single examples (`experiments/barline_types.py`). The brace and bracket outlines depend on the code-3 clef routine and two tables; the dashed types on the code-4 line routine.

### Repeat dots (verified)

`barline_dots(&f, &k)` (0x412749) saves X_POS, sets IP8 = 0, IP5 = 1, and for each staff m = IP2 .. min(IP2+k-1, 256):

```
P16 == 0:  lower7 = 42 (level 6),  gap = 0 (upper dot 2 steps higher, level 8)
P16 = xyz: lower7 = 7*x,           gap = yz - x                      # 410: levels 4 and 10
size  = f32(0.58), or f32(P12 * 0.58f) if P12 != 0;  if P16 == 1: size = f32(22.857f * size)  (draw_box's inch flag)
x     = f32(W*f + X_POS)
y     = f32(STAFF_Y(m) + STAFF_STEP(m) * lower7)
two dots:  ellipse(x, y, size, STAFF_STEP(m));  y = f32(STAFF_STEP(m) * (14 if gap == 0 else 7*gap) + y)
```

then restores X_POS. Each dot is `draw_box` (0x433530) with IP5 = 1 (ellipse), P6 = P7 = size, P13 = 1 (filled), IP10 = IP11 = 0 (0 to 360 degrees) and IP12 = 60 degrees on screen:

```
k  = f32(STEP * 0.035f);  rx = f32(k * P6);  ry = f32(k * P7)
for a = IP10, IP10 + IP12, ... <= IP11:   point (f32(rx*S(a) + X), f32(ry*C(a) + Y)), pen 2 for the first point, 0 after
```

S(a), C(a) are the engine's circle table (about 100·sin a, 100·cos a; read from WSCORE.DAT, exported to `data/trig.tsv`; ten entries differ from correctly rounded values, so use the table). Angles run clockwise from twelve o'clock. A screen dot is a 7-point polygon (the last point repeats the first), about 88 x 101 units at size 1.

### P18/P19: gap in the bar (read)

`barline_gap` 0x412353, only when P18 != 0 and P5 < 2: the stroke points already in the buffer are replaced by two strokes per line, bottom..gap_lo and gap_hi..top, with

```
f   = P18 if P18 <= 1 else P18/100              # fraction of the height from the bottom
c   = f*(y_top - y_bot) + y_bot
g   = STEP * P19 * 7                            # gap size in scale steps
gap_lo = c - g/2,  gap_hi = gap_lo + g
```

Two lines for type 1, doubled again when printing.
