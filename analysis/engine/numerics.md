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

A `fistp` without the control-word dance would use the default round-to-nearest-even. None has been found in the drawing code so far; any that turns up is noted in the topic file.

## f32 storage between statements (read, partly verified)

Engine variables are REAL*4. The optimiser keeps a value on the x87 stack within one statement and usually stores it to its f32 home at the end. The FPU runs with control word 0x27F (53-bit significand, the Windows default; the oracle sets the same). So a faithful port evaluates each statement in f64 and rounds to f32 wherever the Fortran assigns to a REAL variable.

Constants are f32 too. `2.56` is 2.5599999427795410 as f32, so `50 * 2.56` evaluates to 127.99999713897705 and truncates to 127: P26 = 0.5 gives grey 0x7F7F7F, not 0x808080 (verified).

Accumulations happen in f32: the staff routine adds the line spacing to an f32 y once per line, and each line's y is the truncation of that running f32 value (verified with P14 = 0.78: lines at -24000, -23692, -23385, -23078, -22771).

## AMOD

`amod(&x, &y)` (0x54AABA) = `x - INT(x/y)*y`, with the quotient truncated. The difference is computed on the x87 stack and returned in ST0 (not stored to f32 inside the routine).
