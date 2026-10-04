# Numerics

The engine was compiled by Digital Visual Fortran 5 with optimisation. Matching its output to ±1 unit needs its rounding behaviour, not only its formulas.

## Float to integer: truncation toward zero (verified)

Fortran `INT()` and the implicit REAL-to-INTEGER assignment compile to

```
fnstcw [t]; or ax, 0xC00; fldcw [t']; fistp [i]; fldcw [t]
```

i.e. `fistp` with the rounding control set to truncate. Ghidra renders this as `(int)ROUND(x)`. Every such site checked so far truncates: `add_point` 0x44B820, `draw_item` 0x547210 (IP(k) = INT(P(k))), `amod` 0x54AABA, `load_item_header` 0x547C32, `fit_view` 0x54ED0E.

Consequences:

- Negative coordinates round toward zero: -23692.9 becomes -23692 (checked with staff lines at P14 = 0.78).
- `add_point` truncates x and y when a point enters the point buffer, so every emitted coordinate is `trunc(f32 value)`.

## NINT: round half away from zero (read)

A scan of every `fistp` in the engine (`experiments/conversions.py`) finds 1,392 truncating conversions and 67 others. All 67 are Fortran `NINT`: a call to the runtime ANINT 0x5FF381 followed by `fistp` of the already integral value. ANINT adds or subtracts the double 0.5 (0x7A2708) according to the sign, in x87 precision (53 bits), and truncates with `frndint` under RC = chop. So

```
NINT(x) = trunc(x + 0.5) for x > 0,  trunc(x - 0.5) for x < 0,  0 for x == 0       (the sum in f64)
```

No raw default-rounding `fistp` (round half to even) occurs. The NINT sites, by routine (everything else truncates):

| Routine | Name | NINT sites |
|---|---|---|
| 0x41C3B8 | FUN_0041c3b8 | 0x41CA7F |
| 0x424A9F | FUN_00424a9f | 0x4253B5 |
| 0x431AE0 | draw_clef | 0x431DDA |
| 0x445143 | FUN_00445143 | 0x445260 |
| 0x452648 | FUN_00452648 | 0x45481B 0x454890 0x454960 0x454A1B |
| 0x455FEF | FUN_00455fef | 0x456111 0x456168 |
| 0x4588E0 | FUN_004588e0 | 0x4589B4 0x4589E1 0x458A32 0x458A5F |
| 0x458C2A | FUN_00458c2a | 0x459AD5 0x459B2F |
| 0x459C07 | FUN_00459c07 | 0x459D86 0x45A240 0x45A26E 0x45A476 0x45A4AB |
| 0x45A8D7 | FUN_0045a8d7 | 0x45AC96 0x45ACBC |
| 0x48F663 | FUN_0048f663 | 0x48FB65 |
| 0x48FD5C | FUN_0048fd5c | 0x490108 0x490207 0x490691 |
| 0x498BF0 | FUN_00498bf0 | 0x498D8E |
| 0x4A5CB5 | FUN_004a5cb5 | 0x4A5CEE |
| 0x4D0BF5 | FUN_004d0bf5 | 0x4D1541 0x4D1573 |
| 0x4D5FE1 | FUN_004d5fe1 | 0x4D601D |
| 0x4D6318 | FUN_004d6318 | 0x4D6430 0x4D646A |
| 0x4D8460 | FUN_004d8460 | 0x4D88C7 |
| 0x4E4432 | FUN_004e4432 | 0x4E46AA |
| 0x4F7808 | FUN_004f7808 | 0x4F79A2 0x4F7AC7 |
| 0x504835 | FUN_00504835 | 0x5048D9 |
| 0x50571E | FUN_0050571e | 0x505B30 0x505B7E |
| 0x5073EB | FUN_005073eb | 0x507560 |
| 0x5077A2 | FUN_005077a2 | 0x507C21 0x508366 |
| 0x51FFC0 | FUN_0051ffc0 | 0x5205EF |
| 0x52789C | FUN_0052789c | 0x527CD4 |
| 0x538550 | draw_slur | 0x539899 |
| 0x552D80 | FUN_00552d80 | 0x55356F 0x5535A1 |
| 0x555488 | FUN_00555488 | 0x556976 |
| 0x55CB57 | FUN_0055cb57 | 0x55E3E5 0x55E46C |
| 0x5644B8 | FUN_005644b8 | 0x564809 0x564854 |
| 0x569AF0 | draw_text | 0x56A757 0x56A7DD |
| 0x56F689 | FUN_0056f689 | 0x56F75C 0x56F784 0x56F83C 0x56F8C1 |
| 0x56F920 | FUN_0056f920 | 0x56FA57 0x56FA7F 0x56FB82 0x56FBFB |
| 0x5704F8 | FUN_005704f8 | 0x570C51 0x570CDB |
| 0x58ABF6 | FUN_0058abf6 | 0x58AD90 |

Among the drawing routines this covers the text path (`draw_text` 0x569AF0 and 0x56F689/0x56F920, which explains impl-text's and render-core's NINT fits for text positions), one site in `draw_slur`, and the clef-number path of `draw_clef` (0x431DDA).

## f32 storage between statements (read, partly verified)

Engine variables are REAL*4. The optimiser keeps a value on the x87 stack within one statement and usually stores it to its f32 home at the end. The FPU runs with control word 0x27F (53-bit significand, the Windows default; the oracle sets the same). So a faithful port evaluates each statement in f64 and rounds to f32 wherever the Fortran assigns to a REAL variable.

Constants are f32 too. `2.56` is 2.5599999427795410 as f32, so `50 * 2.56` evaluates to 127.99999713897705 and truncates to 127: P26 = 0.5 gives grey 0x7F7F7F, not 0x808080 (verified).

Accumulations happen in f32: the staff routine adds the line spacing to an f32 y once per line, and each line's y is the truncation of that running f32 value (verified with P14 = 0.78: lines at -24000, -23692, -23385, -23078, -22771).

## AMOD

`amod(&x, &y)` (0x54AABA) = `x - INT(x/y)*y`, with the quotient truncated. The difference is computed on the x87 stack and returned in ST0 (not stored to f32 inside the routine).

## Inches

editor-core found that inch values typed in commands ("UI 1", "DC 1") match the engine bit-exactly only with engine units per inch = 1/f32(0.00025) evaluated in double (3999.99981...), rounded to f32 once at the end; an exact 4000 is one ulp off. The engine evidently stores the factor as the f32 constant 0.00025 and divides by it.
