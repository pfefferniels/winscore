"""Check the staff model of staves.md against the emulated engine on random code-8 items.

    python staves.py [cases]     (default 300; prints mismatches and a summary)

The model mirrors draw_staff (0x545140) and item_position (0x5479AB): f32 stores
between statements, f64 evaluation within them, truncation toward zero in add_point.
"""
from __future__ import annotations

import math
import random
import struct
import sys

from lab import Lab

VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4
STAFF_LINE = 0x01000000


def f32(x: float) -> float:
    return struct.unpack("<f", struct.pack("<f", x))[0]


def trunc(x: float) -> int:
    return int(math.trunc(x))


def staff_base(n: int) -> int:
    return ((n + 1) if n <= 199 else (n - 199)) * 3150 - 30300


def staff_segments(p: list[float]) -> list[tuple[int, int, int, int]]:
    """Segments (x0, y, x1, y) in internal coordinates for a staff item with P10 = 0, in emission order."""
    P = [0.0] + p + [0.0] * (27 - len(p))          # P[k] is Pk
    n, p3, p4, p5, p6, p7, p8, p14 = int(P[2]), P[3], P[4], P[5], P[6], P[7], P[8], P[14]
    if p14 != 0:
        p5 = f32(p14 / f32(0.889))
    size = p5 if p5 != 0 else 1.0
    step = f32(size * 25)
    x0 = f32(p3 * 150)
    y = f32(float(staff_base(n)) + p4 * 7 * step)
    segments = []
    if p8 != 0:
        y8 = f32(4000 * p8 + y)
        segments.append((trunc(x0), trunc(y8), 30000, trunc(y8)))
    x1 = f32(p6 * 150) if p6 != 0 else 30000.0
    spacing = f32(step * 14)
    lines = trunc(p7) if trunc(p7) > 0 else 5
    if lines > 99:
        if lines // 100 > 1:
            y = f32((lines // 100 - 1) * spacing + y)
        lines %= 100
    for _ in range(lines):
        segments.append((trunc(x0), trunc(y), trunc(x1), trunc(y)))
        y = f32(spacing + y)
    return segments


def engine_segments(lab: Lab, items: list[list[float]], staff_item: int) -> list[tuple[int, int, int, int]]:
    """Segments the engine emitted for one item, in internal coordinates (the page frame is skipped)."""
    result = lab.load(items)
    dx, dy = lab.engine.i32(VIEW_DX), lab.engine.i32(VIEW_DY)
    body = [t for t in result.vector if t[2] & 0xFFFFFF != 0x00FD00]
    others = sum(len(staff_segments(it)) for k, it in enumerate(items) if k != staff_item and it[0] == 8)
    mine = body[2 * others:] if staff_item == len(items) - 1 else body[:len(body) - 2 * others]
    recto = 34050 if items[staff_item][1] > 199 else 0
    pairs = zip(mine[0::2], mine[1::2])
    return [(a[0] - dx - recto, a[1] + dy, b[0] - dx - recto, b[1] + dy) for a, b in pairs]


def random_staff(rng: random.Random) -> list[float]:
    p = [8.0, float(rng.choice([1, 2, 3, 7, 12, 99, 150, 201, 230])), rng.choice([0.0, rng.uniform(-20, 100)]),
         rng.choice([0.0, rng.uniform(-12, 12), float(rng.randint(-6, 6))]), rng.choice([0.0, 1.0, rng.uniform(0.4, 2.2)]),
         rng.choice([0.0, rng.uniform(110, 220)]), rng.choice([0.0, 1, 3, 4, 6, 7, 102, 203, 305, 410])]
    if rng.random() < 0.15:
        p += [rng.choice([0.0, 0.5, 1.0])]
    if rng.random() < 0.2:
        p += [0.0] * (14 - len(p)) + [rng.uniform(0.4, 1.4)]
    return [f32(v) for v in p]          # .mus words are f32


def main(cases: int = 300):
    rng = random.Random(8)
    lab = Lab()
    bad = 0
    for case in range(cases):
        staff = random_staff(rng)
        items = [[8, 1, 0, 0, 1], [i for i in staff]] if staff[1] != 1 else [staff]
        expected = staff_segments(staff)
        got = engine_segments(lab, items, len(items) - 1)
        if got != expected:
            bad += 1
            print(f"case {case}: {staff}\n  model  {expected}\n  engine {got}")
    print(f"{cases - bad}/{cases} staves match")


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
