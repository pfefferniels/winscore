# Library symbols (code 9, and every symbol drawn through draw_clef)

Most music symbols reach the output as outlines from the symbol libraries `scorlib/LBnnn0.DRW` (format: FORMATS.md, `rust/crates/score-format/src/drw.rs`). Two routines do it:

- `draw_symbol(&x, &y, &number, &xs, &ys, &p8, &p9, &p10)` (0x4293F0): the library path. Code 9 and 13 items call it directly from `draw_item` with (X_POS, Y_POS, IP5, P6, P7, IP8, P9, IP9), between `push_words(13, &P3)`/`pop_words`.
- `draw_clef(&x, &y, &type, &xs, &ys)` (0x431AE0): code 3, and the entry point the note, rest and other routines use for their symbols (note heads, tails, dots, accidentals, braces). It adjusts position and scale, then calls `draw_symbol`.

The library path below matched the engine on 1000 random code-9 items (442 symbols from every float-variant library in scorlib, random P3, P4, P6, P7, P15): `experiments/symbols.py` (**verified**). The `draw_clef` adjustments are **read**, and the dot of a note was checked by hand.

## draw_symbol, library path (verified)

```
if 1299 < number < 1305:                        # special symbols
    skip entirely if IP1 == 1, or IP11 != 0 and OUTPUT_MODE < 1
    if IP2 != 0: xs = 25 / STAFF_STEP(IP2)      # same size on every staff
xs = amod(xs, 100);  if xs == 0: xs = 1         # f32
ys = ys if ys != 0 else xs
number < 0 becomes 0
library = number / 10, slot = number % 10       # file LB{library:03d}0.DRW, symbol slot (0-based)
if 49 < number < 5000:  xs = f32(xs * 0.3f), ys = f32(ys * 0.3f)
xs = f32(STEP * xs), ys = f32(STEP * ys)        # STEP = 25 * size of CUR_STAFF
for each record (X, Y, pen) of the symbol, in file order:
    add_point(f32(xs*X + x), f32(ys*Y + y), max(pen, 0))
```

So a library unit is 25 engine units for symbols 0–49 at scale 1 and 7.5 units (0.3 x 25) for symbols 50–4999. Negative pens (-1, -2, -3 in some files) become 0, i.e. continuation points. The emitter's start-after-start rule (emitters.md) then drops a start point immediately followed by another start, which happens in some symbols.

Not drawn as outlines:

- **Text symbols**: when OUTPUT_MODE != 0 (normal display), the 21 numbers 66, 67, 78, 45, 46, 47, 63, 64, 65, 68, 72, 73, 79, 80, 81, 85, 86, 111, 113, 114, 276 (table at 0x78EAAC) are drawn as text through `draw_text` with the words "pizz.", "arco", "a tempo", "8va", "8ba", "15ma", "cresc.", "dim.", "rit.", "accel.", "gliss.", "molto", "espr.", "meno", "più", "subito", "poco", "decresc.", "rall.", "mosso", "G.P." (in that order; strings at 0x78EA10, start offsets at 0x78EC90). Size P6 = 1.05*xs, P7 = 1.05*ys; for 276 extra placement rules. Details with code 16.
- **3000–3099**: text read once from a file opened at 0x4295B7 (unit 3) and cached; drawn with `draw_text` (not examined).
- Symbols in a missing or compact ("KH") library: `load_symbol_library` 0x42AD97 shows the dialog "Not found" (once a user suppresses it, not again) and returns **without** marking the load as failed. `draw_symbol` then copies slot n%10 with the offset table of the last library actually read and the point arrays (0x1DC41FC, 0x1E123FC, 0x1D9D0FE) as left by the last drawn symbol, and caches that mixture under the symbol number for the rest of the session (verified: symbol 710 drew the same 52 points after symbols 20, 31 or 12). This depends on the session's draw history and is an engine artefact; a port should draw nothing and fixtures should mark such items.

Ported and matched against fixtures by impl-symbols (reported by them, not re-checked here): the rotation 0x42A5F4 (angle divisor f32 57.2957764; sin 0x5FF110, cos 0x5FF0F5, ANINT 0x5FF381), the thickening 0x42A8AE (2X vertical copies at ±14, ±28, ... then 2Y horizontal; negative values outline; a positive IP10 on screen means thickness 101 x pixels, one less from symbol 45 on), the clef routine including the small-clef lift table at 0x78F30C (0.35, 8.75, 5.6, 5.6, 5.6, 0.35), and `draw_box` with the circle table.

Not yet modelled here (all zero in the tests):

- p8 (IP8 for code 9) and p10 (IP10, or trunc(P16) for codes 10 and 18, minus 1 for numbers > 44): on screen, when p10 > 0 and p8 == 0, p8 = 101*p10; a non-zero p8 calls 0x42A8AE on the symbol's points (outline thickening, inferred).
- p9 non-zero (IP9 for code 9) calls 0x42A5F4 (fill or pattern, inferred).
- Code 11 (user symbols) uses its own tables at 0x1CB0E90/0x1DC41FC.

Library cache: up to 100 symbols and 10,000 points are kept in memory (0x7E21C4..), keyed by symbol number. It does not change the output.

## draw_clef (read)

```
xs = xs or 1;  ys = ys or xs
i = type + 1
if i < 7:                                       # clef types 0..5
    i = max(i, 1);  dx = 21
    if |IP4| > 99:  xs = ys = 0.8*xs,  dx = 21 + table_78F308[i]      # small clef
    if i == 4:  dx += 14,  i = 3,  type = 2
    x += STEP * dx
if IP1 == 3 and the clef has a number (P5 digits): draws it with draw_number (see code 3)
if IP1 == 3 and i in {67, 45, 56}: scale 0.1 (0.06 and level P4 + 1.2 for 45, 0.083 and P4 + 0.35 for 56), type = 3
elif i < 46:
    if OUTPUT_MODE == 0:  built-in outlines from tables at 0x1C5963C (x), 0x1C59DA8 (y), 0x1C5A5CC (pens),
                          ranges at 0x1C5A514/0x1C5A518, scale STEP*xs: a fallback set loaded at start-up
    else:                 xs = 0.25*xs (0 becomes 0.25), ys = 0.25*ys
draw_symbol(&x, &y, &type, &xs, &ys, &0, &0, &0)
```

With OUTPUT_MODE = 1 (after loading a score, the case of every oracle run so far), a symbol 0–45 drawn through `draw_clef` therefore has library units of 25 x 0.25 = 6.25 engine units at scale 1. Example: the rhythm dot of a note is `draw_clef(&x, &y, &24, &s, &s)`, i.e. LB0020.DRW slot 4 ("dot") at 6.25*s units per library unit.

When OUTPUT_MODE is 0 (right after start-up, before a score is loaded), symbols 0–45 come from the built-in tables instead. Whether the real program ever paints in that state was not checked.

## What the port draws differently

The port keeps every symbol where the engine puts it, at its size, but draws it as SCORE's PostScript print output would, on every medium (`rust/crates/score-render/src/symbols/library.rs`, `smooth.rs`):

- **Thickness is a pen, not copies.** When printing (OUTPUT_MODE = -1) draw_symbol does not thicken by IP10; it passes the pixel count to the print-width marker 0x4D4ED2 and resets the pen with 0x4D4F3F after the symbol (read): library symbols at 0x42A1E3 with the count already lowered by one from symbol 45 on (so a symbol from 45 on with IP10 = 0 prints with the marker -1, i.e. 1/600 inch thinner than the default pen), user symbols (code 11) at 0x42A382 with IP10 itself. The count is IP10, or trunc(P16) when P1 is 10 or 18. Only on the screen (OUTPUT_MODE >= 0) does a positive count become P8 = 101 x count. An explicit P8 = 100v + h > 0 thickens on both media (0x42A8AE doubles the counts whenever OUTPUT_MODE != 0), by copies 14v units up and down and 14h sideways. The port outlines the symbol once with `print_pen(count)`, widened for P8 > 0 by the copies' reach averaged over all directions, 14 x (2/pi) x sqrt(v^2 + h^2) on each side (a round pen cannot be anisotropic). P8 <= 0 still turns filled parts into outlines.
- **Smooth outlines.** Library paths are polygons on an integer grid; the port draws each as cubic curves through its points, keeping corners and straight runs and moving no point more than 0.4 library units (`smooth.rs` has the rules).
- **Missing symbols** (a library file or user-symbol file that is not there) draw nothing in the engine. The port shows a light grey box with the symbol number on the screen, for code 9, 11 and 3 items; nothing in print.
- **Codes built from symbols.** Key signatures (code 17) draw no accidental for P5 = 0 or +-100 (the engine always draws the first one). Meters (code 18) in the outline digits 2000-2009 keep the screen's placement (P4 - 0.23, size 1.35, top level 5.46) in print too, where the engine uses the one made for SCORE's PostScript meter font (P4 + 0.1, 1.2, 5.82; the port uses it for text fonts), and the numbers of each meter are centred on the widest one as drawn, a shared bottom number under both tops. EPS items (code 15) show their box on the screen only.
