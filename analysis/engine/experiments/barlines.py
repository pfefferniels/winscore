"""Check the barline model of barlines.md (types 0-6, P6 thick bars, repeat dots) against the engine.

    python barlines.py [cases]     (default 300)

Random barlines over four default staves; P3, P4 (span), P5, P6, P7, P8, P10, P11, P12, P13,
P14, P15, P16 and P17 vary.
"""
from __future__ import annotations

import random
import sys
from dataclasses import dataclass
from pathlib import Path

from lab import Lab
from staves import f32, staff_base, trunc

VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4
STAVES = [[8, n, 0, 0, 1] for n in (1, 2, 3, 4)]
MAX_STAFF = 256
STEP = 25.0                     # all test staves have size 1
TRIG = [tuple(float(v) for v in line.split("\t")[1:])
        for line in (Path(__file__).resolve().parents[1] / "data" / "trig.tsv").read_text().splitlines()[1:]]

Point = tuple[float, float, int]


def staff_y(staff: int) -> int:
    return staff_base(staff) - 525


def level_y(staff: int, v: float) -> float:
    """staff_level_y (0x547AA3): STAFF_Y + v*7*STEP, returned as f32."""
    return f32(float(staff_y(staff)) + v * 7 * STEP)


def ellipse(x: float, y: float, rx_factor: float, ry_factor: float, step: float, degrees: int, pen: int) -> list[Point]:
    """draw_box (0x433530) with IP5 = 1, IP10 = 0, IP11 = 360, IP12 = degrees."""
    k = f32(step * f32(0.035))
    rx, ry = f32(k * rx_factor), f32(k * ry_factor)
    points = []
    for a in range(0, 361, degrees):
        s, c = TRIG[a]
        points.append((f32(rx * s + x), f32(ry * c + y), pen))
        pen = 0
    return points


@dataclass
class Bar:
    P: list[float]
    staff: int
    span: int
    x_item: float                # X_POS: 150*P3, + 150*P15, or + 150*P7 if P15 == 0
    xb: float                    # bar x, a copy of X_POS
    yb: float
    yt: float
    w: float
    d13: float
    d14: float
    ip8: int

    def stroke(self, x: float) -> list[Point]:
        return [(x, self.yb, 1), (x, self.yt, 0)]

    def thick(self, a: float, b: float) -> list[Point]:
        """The sequence at 0x411FAD (P5 != 10); IP8 is 0 once barline_dots has run."""
        yb, yt = self.yb, self.yt
        pts = [(a, yb, 1), (b, yt, 0), (b, yt, 2), (b, yb, 0), (a, yb, 0), (a, yt, 0), (b, yt, 0)]
        return pts + ([(b, yt, 0)] if self.ip8 in (0, 1) else [])

    def thick_at(self, x: float) -> list[Point]:
        return self.thick(f32(x - self.w * 6), x)

    def dots(self, x_item: float, factor: float) -> list[Point]:
        """barline_dots (0x412749): two dots per spanned staff; leaves IP8 = 0."""
        P = self.P
        self.ip8 = 0
        p16 = trunc(P[16])
        lower7, gap = (42.0, 0) if P[16] == 0 else (float(p16 // 100 * 7), p16 % 100 - p16 // 100)
        size = f32(0.58) if P[12] == 0 else f32(P[12] * f32(0.58))
        if P[16] == 1:
            size = f32(f32(22.857) * size)
        x = f32(self.w * f32(factor) + x_item)
        points = []
        for m in range(self.staff, min(self.staff + self.span - 1, MAX_STAFF) + 1):
            y = f32(float(staff_y(m)) + STEP * lower7)
            for _ in range(2):
                points += ellipse(x, y, size, size, STEP, 60, 2)
                y = f32(STEP * (14.0 if gap == 0 else float(gap * 7)) + y)
        return points


def make_bar(p: list[float]) -> Bar:
    P = [0.0] + p + [0.0] * (27 - len(p))
    staff, span = int(P[2]), trunc(P[4])
    x_item = f32(P[3] * 150)
    if P[15] != 0:
        x_item = f32(P[15] * 150 + x_item)
    if P[7] != 0 and P[15] == 0:
        x_item = f32(P[7] * 150 + x_item)
    xb = x_item
    if span == 999:
        span = max(s[1] for s in STAVES) - staff + 1
        P[10] = P[11] = 0.0
    span = max(min(span, MAX_STAFF - staff + 1), 1)
    w = f32(P[17] * 25) if P[17] != 0 else STEP
    return Bar(P, staff, span, x_item, xb, level_y(staff, P[10] if P[10] != 0 else 3),
               level_y(staff + span - 1, P[11] if P[11] != 0 else 11), w,
               f32(w * 6 * P[13]), f32(w * 6 * P[14]), trunc(P[8]))


def barline_points(p: list[float]) -> list[tuple[int, int, int]]:
    """Points (x, y, pen) in internal coordinates for a barline of type 0..6."""
    bar = make_bar(p)
    t, xb, x, d13, d14, w = trunc(bar.P[5]), bar.xb, bar.x_item, bar.d13, bar.d14, bar.w
    left_thin = bar.stroke(f32((xb - w * f32(13.8)) - d13))
    if t == 0:
        pts = bar.thick(f32(xb - (bar.P[6] + 1) * 0.0), xb) if bar.P[6] != 0 else bar.stroke(xb)
    elif t == 1:
        pts = bar.stroke(xb) + bar.stroke(f32((xb - w * 7.5) - d13))
    elif t == 2:
        pts = left_thin + bar.thick_at(xb)
    elif t == 3:
        pts = bar.dots(f32((x - d13) - d14), -25.5) + left_thin + bar.thick_at(xb)
    elif t == 4:
        pts = bar.stroke(f32(w * f32(7.8) + xb + d13)) + bar.dots(f32(d13 + x + d14), 19.5) + bar.thick_at(xb)
    elif t == 5:
        right = f32(d13 + x + d14)
        left = f32((f32((right - d13) - d14) - d13) - d14)
        pts = (bar.stroke(f32(w * f32(7.8) + xb + d13)) + bar.dots(right, 19.5)
               + bar.dots(left, -25.5) + left_thin + bar.thick_at(xb))
    else:
        left = f32(x - d14)
        right = f32(d13 + left + d14 + d14)
        second = f32(w * 13 + xb + d13)
        pts = bar.dots(left, -18.36) + bar.dots(right, 25.2) + bar.thick_at(xb) + bar.thick_at(second)
    return [(trunc(px), trunc(py), pen) for px, py, pen in pts]


def engine_points(lab: Lab, bar: list[float]) -> list[tuple[int, int, int]]:
    result = lab.load(STAVES + [bar])
    dx, dy = lab.engine.i32(VIEW_DX), lab.engine.i32(VIEW_DY)
    body = [t for t in result.vector if t[2] & 0xFFFFFF != 0x00FD00][10 * len(STAVES):]
    return [(x - dx, y + dy, tag >> 24) for x, y, tag in body]


def random_bar(rng: random.Random) -> list[float]:
    maybe = lambda value, chance=0.3: value if rng.random() < chance else 0
    p = [14, rng.choice([1, 2, 3]), rng.uniform(-10, 200), rng.choice([1, 2, 3, 999, 7]), rng.randint(0, 6),
         maybe(rng.choice([1, 2.5])), maybe(rng.uniform(-3, 3)), rng.choice([0, 0, 1, 2, 3]), 0,
         maybe(rng.uniform(-4, 6)), maybe(rng.uniform(6, 16)), maybe(rng.uniform(0.5, 2)),
         maybe(rng.uniform(0.2, 2)), maybe(rng.uniform(0.2, 2)), maybe(rng.uniform(-2, 2)),
         maybe(rng.choice([410, 208, 1, 507])), maybe(rng.uniform(0.5, 1.5))]
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
