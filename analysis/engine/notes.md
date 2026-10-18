# Notes (code 1)

Routine `draw_note` 0x4EFEC0 and its parts. The model in `experiments/notes.py` matched the engine on 1000 random cases (single notes and pairs of black notes): head types 0–2, stems up/down/none, P8, 1–4 tails, 1–2 dots with fractional offsets, accidentals 1–5 with fractional shifts, ledger lines above and below, P10 (10, 20, other), P15, P19, P20 (**verified** for these). Everything else below is **read**. Decompilations: `analysis/engine/decompiled_all/4efec0_draw_note.c` and the routines named there.

Symbols are drawn through `draw_clef` → `draw_symbol` (symbols.md). With OUTPUT_MODE = 1, `draw_clef(&x, &y, &n, &xs, &ys)` for 6 <= n < 45 draws LB symbol n at library-unit size STEP*0.25*xs (x) and STEP*0.25*ys (y), where STEP is whatever the note routine has set it to (the head step `hs` below).

## Set-up in draw_note

```
step   = STAFF_STEP(P2)                         # STEP on entry
step7  = f32(step * 7)                          # one scale step of the staff (used for dots, ledger spacing)
cue    = |IP4| / 100;  if cue != 0: IP4 = IP4 % 100          # P4 = 1xx: cue size
width  = P20 if P20 != 0 else 1                 # note-width factor
if P15 != 0:  STEP = f32(P15 * STEP), cue = 0   # note size factor
hs     = f32(STEP * 0.6) if cue == 1 else STEP  # head step (0x1F95CE0)
IP10 == 110: treated as P10 = 10 with a flag (the accidental then moves with the head)
IP6 < -2 (except -3 and -20..-39): 0x558A40 draws the whole note (special heads; not examined)
head_w = f32(hs * (19 if IP6 % 1000 in {2, 3} else 17) * width)     # 0x1F95CF0
X_POS  = f32(150 * P3);  Y_POS = f32(STAFF_Y + amod(P4, 100) * 7 * step)    # item_position
P10 != 0:  X_POS = f32(d + X_POS), d = head_w (P10 = 10), -head_w (P10 = 20), f32(STEP*6*P10) otherwise
IP12 = xyz with |IP12| > 99: IP16 = IP12/100, IP12 = |IP12 % 100|
IP12 > 0: the note is drawn on staff n' = IP2 - 2*IP12 + 3 (n' > 0): Y_POS += STAFF_Y(n') - STAFF_Y(IP2)
```

Then, in this order (each part appends to the point buffer, except the ledger lines, which flush at once):

1. ledger lines, if IP30 != 0, or IP7 > -2 and (IP4 < 2 or IP4 > 12 or IP16 != 0);
2. head, if IP6 >= -1 or IP6 < -19;
3. tails, if IP9 % 10 != 0;
4. accidental, if IP5 % 10 != 0;
5. stem, if (IP5 % 100) / 10 != 0 (1 up, 2 down); without a stem the direction for later parts is 2 if IP4 > 6, else 1;
6. dots, if IP9 > 9;
7. marks, if IP11 != 0 (`note_marks` 0x4F2279, with IP10 = IP28 when printing);

and `draw_items` flushes the rest with the note's P26 colour.

## Ledger lines (note_ledger_lines 0x4F0871; verified for P30 = 0, IP16 = 0)

```
if P30 < 0: none
x0 = f32(X_POS - f32(hs*5));  x1 = f32(head_w + X_POS + f32(hs*5))
d  = f32(-step7 - step7)                        # two staff steps, downward
IP4 < 2:   first = 1,  inc = -2, d = -d         # below the staff: lines at 1, -1, -3, ... down to IP4
else:      first = 13 (or 2*IP16 + 3), inc = 2  # above: 13, 15, ...; IP16 is then cleared
y = Y_POS, + f32(d/2) if IP4 is even            # start at the note's own line, or half a space toward the staff
count = (IP4 - first + inc) / inc               # integer division truncating toward zero; none if <= 0
repeat count: segment (x0, y) -> (x1, y);  y = f32(d + y)
```

So the lines are emitted from the note toward the staff. P30 = 1, 2, 3, 1x, 2x, 3x, 4x change the start and count (only lines through the note, above, below, ...; read, not tested).

**Colour and flush:** the ledger lines are written out immediately (before the head). If the note's P26 equals the staff's colour they go out with `emit_points` as they are; otherwise they are flushed with the staff's colour (MAX_STAFF table entry for IP2), unless IP27 != 0, in which case the note's own P26 applies. P27 is the documented "colour of ledger lines".

## Head (note_head 0x4F14B0; verified for IP6 = 0, 1, 2)

```
t = IP6;  10 <= t <= 19: t -= 10 (parenthesised, below);  t == 8: 95;  t == 9: 139
20 <= |t| <= 25: special tablature heads via 0x4F1BD4/0x4F1D5E (not examined)
t < 7:  draw_clef(&X_POS, &Y_POS, &(t + 11), &width, &1) with STEP = hs     # LB0010.DRW slots 1, 2, 3, ...
t == 7: no head
t > 7:  draw_symbol(&X_POS, &Y_POS, &t, &f_0_x, ...) (LB symbol t)
```

**Head cache (verified):** for t == 0 (black head) and OUTPUT_MODE != -1 the routine keeps the integer offsets of the last drawn black head, `PT - (trunc(X_POS), trunc(Y_POS))`, together with the f32 scale `width * hs`. When the next black head has the same scale, its points are `cached offset + (trunc(X_POS), trunc(Y_POS))`, written straight into the point buffer, instead of being recomputed. Because truncation depends on the fractional part of the position, heads drawn from the cache can differ by one unit from a fresh computation. The cache (scale at f32 0x78B6AC, offsets at 0x1A9E920/0x1A9ED08/0x1A9F0F0) survives between items, redraws and commands. In a fresh engine, `fit_view`'s trial draw runs first, so in the output every black head of a given scale uses the offsets of the first black head of that scale in item order.

Parenthesised heads (10–19): after the head, two parentheses (LB symbol at 0x7664F0) at x offsets -13.8 (−14.4 more with an accidental, −12.6 more for accidental 4) and +31.2 (39.2 with dots, 51.2 with IP9 % 100 > 19) head steps, scale 1.4 (read).

## Tails (note_tails 0x4F06BB; verified)

```
stem down (2):  x = X_POS,          d = f32(-(hs*7)), ys = 1
otherwise:      x = f32(X_POS + head_w), d = f32(hs*7), ys = -1      # mirrored symbol
y = f32(amod(P8, 100) * d + Y_POS + d);  if tails > 1: y = f32(y - d/2)
repeat IP9 % 10 times:  draw_clef(&x, &y, &20, &width, &ys) with STEP = hs;  y = f32(d + y + d)
```

Symbol 20 is LB0020.DRW slot 0 ("tail"). IP10 is -1 during the tails (no outline thickening).

## Accidental (note_accidental 0x4F2F31; verified for 1–5)

```
a = IP5 % 10;  if a > 5 or IP5/100 == 1: a += 134
s = amod(P5, 1);  if s != 0: (if s > 0.9: s = f32(0.9 - s));  s = f32(s * 60 * hs)
if P10 == 10 (and not from P10 = 110): s = f32(head_w + s)      # stays left of the original head position
size = P29 or 1
draw_clef(&f32(X_POS - s), &Y_POS, &(a + 5), &size, &size) with STEP = hs
```

Accidentals 1–5 are symbols 6–10 (LB0000 slots 6–9 and LB0010 slot 0). With a + 134 the symbol number is >= 140, so `draw_clef` does not apply 0.25 and `draw_symbol` applies 0.3 instead. P28 (pixel width) only acts when printing.

## Stem (note_stem 0x4F0EB9; verified for |IP8| < 100, IP6 <= 2, P17 = 0)

```
extra = (2*tails - 2) - 0.5 if tails > 1 else 0          # tails = IP9 % 10
p8 = P8, or P8 -/+ 100 if |IP8| >= 100 (then also slashes through the stem, see below)
len = f32((extra + 7 + p8) * hs * 7)                     # stored in the IP14 slot as a REAL
no stem for IP6 in {2, 3}, IP6 >= 900, and 100 <= IP6 <= 198 except 139
stem down: x = X_POS, len = -len;  up: x = f32(X_POS + head_w)
off = 2.1; IP6 4..8: 0; IP6 == 6: 7; if P17 != 0: off = 7*amod(P17, 100) (P17/100 = thickness, print only); down: -off
segment (x, f32(hs*off + Y_POS)) -> (x, f32(len + Y_POS))
```

For |IP8| >= 100 and tails != 0, a slash is drawn first: two points at x = f32(hs*6*a + X_POS), y = staff_level_y(amod(P4,100) + (extra + p8)*f + f*b) with (a, b) = (0.783, 2.8) and (6.5, 5.4) for stems up, (-1.883, -5.5) and (3.8, -2.8) for stems down, f = P15 or 0.6, on staff IP2 - 2*IP12 + 3 when IP12 != 0 (read, not tested).

## Dots (inline in draw_note; verified for IP9 < 100)

```
count = IP9
yoff  = step7 if IP4 is odd else 0                       # dots sit in a space
f = amod(P9, 1);  if f > 0.9: f = f32(0.9 - f)
count > 999:  f = f32(f + 0.284), count -= 1000
count > 99:   yoff = -yoff, count -= 100
xoff = 16.2 if IP8 == 0 and tails != 0 and stem up else 18
xoff = f32((f*60 + xoff) * hs)
if stem down and tails == 0 and IP6 in {7, -1}: xoff = f32(xoff/2)
x = f32(width * xoff + X_POS)
if P19 != 0: yoff = f32(step7 * P19 + yoff)
y = f32(Y_POS + yoff)
size = 0.6 for cue notes, else 1;  if P31 != 0: x -= ((P31-1)*238*hs)/25, size *= P31
repeat count/10 times:  draw_clef(&x, &y, &24, &size, &size) with STEP = hs;  x = f32(hs*13 + x)
```

Symbol 24 is LB0020.DRW slot 4 ("dot"), an octagon 13 library units across about (38.5, 0.5): corners 6.96 units from the centre, sides 6.36 (diagonal) and 6.5 (straight).

## Print widths (read)

When printing (OUTPUT_MODE = -1) the note routines set PostScript line widths with the print-width marker `0x4D4ED2(&w)` (emitters.md; w in 1/600 inch on top of the default 1/150-inch pen) and reset them with `0x4D4F3F`:

- **Stem** (0x4F0EB9): h = trunc(P17/100). If h != 0: marker(|h|), and the stem moves |h| printer dots (0x78B480 = 4000/dpi units; the print dialog's default is 600 dpi, pen 4 dots) towards the head: right for a stem down, left for a stem up. On every medium P17 then becomes amod(P17, 100). The flag that should trigger the reset is cleared at 0x4F13D2, before the test, so the reset after the stem happens only when IP28 != 0: otherwise the thick pen stays on for the dots, the marks and what is printed next.
- **Ledger lines** (0x50DDF0, called by 0x4F0871): w = trunc(P16); P16 = 0: the staff's thickness + 2 (+ 1 when STEP != the head step, i.e. a grace note); P16 = 99: the staff's thickness; no marker for w = 0, or when the staff's thickness is 99 and P16 is 0 or 99. The staff's thickness is its IP11, or -1 for P11 = 0 on a staff smaller than 0.65 (STAFF_THICK, written by draw_staff 0x545140 at 0x1A9E220 + 4n), but 0x50DDF0 reads 0x1A9E21C + 4n, the entry of staff n - 1 (0 for staff 1).
- **Accidental** (0x4F2F31): marker(trunc(P28)) around the symbol when P28 != 0.
- **Marks**: draw_note sets IP10 = IP28 for `note_marks`, so draw_symbol's own marker (IP10, one less from symbol 45 on) applies to them.
- **Beams** (draw_beam 0x416168, also for tremolo marks): marker(BMTH) around the beams (BMTH = -2 from PREF.DAT: half the default pen), reset before the tuplet number. Each beam is a filled quadrilateral, which the PostScript output fills and strokes with the current pen.
- draw_rest calls no marker: its ledger lines and the bar rest print with the default pen.

Print draws every black head afresh: the head cache is screen-only.

## What the port draws differently

score-render keeps every position, size and thickness convention of the engine (dot gaps, stem lengths including the 16th-note extension, beam thickness, head designs) and changes only how notes, rests and beams are drawn:

- the print widths above on every medium, each on its own shapes only; thick stems move inward as in print at 600 dpi (the move equals the extra width) and `note::stem_end` follows them; ledger widths come from the note's own staff;
- full beams, whose ends stand on stems, are drawn (1/150 - 1/300)/2 inch longer at either end along their slope, so that they reach the outer edges of default stems instead of letting the stems poke past them; `beam::ends` stays at the stems' centres;
- symbol 24 (rhythm dots of notes and rests, staccato) is a 32-sided circle about the octagon's centre with its mean radius, 6.6 library units;
- the marks of a stemless note read a stem length of 0 (the engine reads trunc(P14)'s bits, NaN for P14 <= -1, which loses the mark);
- black heads are drawn directly, without the screen's cache;
- the masks behind hollow AlphaNotes and tablature numbers are white, not 0xFDFDFD.

With the default pen a half note's stem foot stays some 13 units clear of the head's hole; from P17 = 200 the moved, thicker stem reaches a few units into it, as in print.

## Not yet examined

Marks (P11, `note_marks` 0x4F2279, with P13/P14/P18), AlphaNotes (P21–P24), special heads (IP6 < -2, 20–25, 95, 139 and other symbol heads).
