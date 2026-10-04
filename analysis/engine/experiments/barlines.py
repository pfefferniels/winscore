"""Check the barline model of barlines.md (types 0, 1, 2 and P6 thick bars) against the engine.

    python barlines.py [cases]     (default 300)

Random barlines over four default staves; P3, P4 (span), P6, P7, P10, P11, P13, P15
and P17 vary. Repeat dots (types 3-6) come from the code-12 box routine and are not
modelled here.
"""
from __future__ import annotations

import random
import sys

from lab import Lab
from staves import f32, staff_base, trunc

VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4
STAVES = [[8, n, 0, 0, 1] for n in (1, 2, 3, 4)]
MAX_STAFF = 256


def level_y(staff: int, v: float, step: float = 25.0) -> float:
    """staff_level_y (0x547AA3) on a default staff: STAFF_Y + v*7*STEP, returned as f32."""
    return f32(float(staff_base(staff) - 525) + v * 7 * step)


def thick(xl: float, xr: float, yb: float, yt: float, p5: int, p8: int) -> list[tuple[float, float, int]]:
    """The thick-bar point sequence at 0x411FAD (p5 != 10)."""
    pts = [(xl, yb, 1), (xr, yt, 0), (xr, yt, 2), (xr, yb, 0), (xl, yb, 0), (xl, yt, 0), (xr, yt, 0)]
    return pts + ([(xr, yt, 0)] if p8 in (0, 1) else [])


def barline_points(p: list[float]) -> list[tuple[int, int, int]]:
    """Points (x, y, pen) in internal coordinates for a barline of type 0, 1 or 2."""
    P = [0.0] + p + [0.0] * (27 - len(p))
    staff, span, p5, p8 = int(P[2]), trunc(P[4]), trunc(P[5]), trunc(P[8])
    x = f32(P[3] * 150)
    if P[15] != 0:
        x = f32(P[15] * 150 + x)
    elif P[7] != 0:
        x = f32(P[7] * 150 + x)
    if span == 999:
        span = max(s[1] for s in STAVES) - staff + 1
        P[10] = P[11] = 0.0
    span = max(min(span, MAX_STAFF - staff + 1), 1)
    yb = level_y(staff, P[10] if P[10] != 0 else 3)
    yt = level_y(staff + span - 1, P[11] if P[11] != 0 else 11)
    w = f32(P[17] * 25) if P[17] != 0 else 25.0
    d13 = f32(f32(w * 6) * P[13]) if P[13] != 0 else 0.0
    stroke = lambda xb: [(xb, yb, 1), (xb, yt, 0)]
    if p5 == 0:
        pts = thick(f32(x - (P[6] + 1) * 0.0), x, yb, yt, p5, p8) if P[6] != 0 else stroke(x)
    elif p5 == 1:
        pts = stroke(x) + stroke(f32((x - w * 7.5) - d13))
    else:
        pts = stroke(f32((x - w * f32(13.8)) - d13)) + thick(f32(x - w * 6), x, yb, yt, p5, p8)
    return [(trunc(px), trunc(py), pen) for px, py, pen in pts]


def engine_points(lab: Lab, bar: list[float]) -> list[tuple[int, int, int]]:
    result = lab.load(STAVES + [bar])
    dx, dy = lab.engine.i32(VIEW_DX), lab.engine.i32(VIEW_DY)
    body = [t for t in result.vector if t[2] & 0xFFFFFF != 0x00FD00][10 * len(STAVES):]
    return [(x - dx, y + dy, tag >> 24) for x, y, tag in body]


def random_bar(rng: random.Random) -> list[float]:
    p = [14, rng.choice([1, 2, 3]), rng.uniform(-10, 200), rng.choice([1, 2, 3, 999, 7]), rng.choice([0, 1, 2]),
         rng.choice([0, 0, 1, 2.5]), rng.choice([0, 0, rng.uniform(-3, 3)]), rng.choice([0, 0, 1, 2, 3]), 0,
         rng.choice([0, 0, rng.uniform(-4, 6)]), rng.choice([0, 0, rng.uniform(6, 16)]), 0,
         rng.choice([0, 0, rng.uniform(0.2, 2)]), 0, rng.choice([0, 0, rng.uniform(-2, 2)]), 0,
         rng.choice([0, 0, rng.uniform(0.5, 1.5)])]
    return [f32(float(v)) for v in p]


def main(cases: int = 300):
    rng = random.Random(14)
    lab = Lab()
    bad = 0
    for case in range(cases):
        bar = random_bar(rng)
        expected, got = barline_points(bar), engine_points(lab, bar)
        if got != expected:
            bad += 1
            print(f"case {case}: {bar}\n  model  {expected}\n  engine {got}")
    print(f"{cases - bad}/{cases} barlines match")


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
