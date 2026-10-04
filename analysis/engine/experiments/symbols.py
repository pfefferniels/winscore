"""Check the library-symbol model of symbols.md (draw_symbol 0x4293F0) against the engine with code-9 items.

    python symbols.py [cases]     (default 300)

Random code-9 items over staff 1: symbol numbers from the float-variant libraries in
scorlib, P3, P4, P6, P7 and P15 vary; P8, P9, P10 stay 0 (outline thickening and fills
are separate routines).
"""
from __future__ import annotations

import random
import struct
import sys
from dataclasses import dataclass
from functools import cache
from pathlib import Path

from lab import Lab
from staves import f32, staff_base, trunc

SCORLIB = Path(__file__).resolve().parents[3] / "WINSCORE 5.01" / "winscore" / "scorlib"
VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4
STAFF = [8, 1, 0, 0, 1]
STEP = 25.0
# Symbol numbers drawn as text instead of outlines when OUTPUT_MODE != 0 (table at 0x78EAAC):
# pizz., arco, a tempo, 8va, 8ba, 15ma, cresc., dim., rit., accel., gliss., molto, espr., meno, piu, subito,
# poco, decresc., rall., mosso, G.P.
TEXT_SYMBOLS = (66, 67, 78, 45, 46, 47, 63, 64, 65, 68, 72, 73, 79, 80, 81, 85, 86, 111, 113, 114, 276)


@dataclass(frozen=True)
class Record:
    x: float
    y: float
    pen: int


@cache
def library(number: int) -> tuple[tuple[Record, ...], ...] | None:
    """Float-variant LBnnn0.DRW: ten symbols as point records, or None if missing or compact."""
    path = SCORLIB / f"LB{number:03d}0.DRW"
    if not path.exists():
        return None
    data = path.read_bytes()
    if data[:2] == b"KH":
        return None
    offsets = [max(o, 1) for o in struct.unpack_from("<11h", data)]
    names = [data[22 + 24 * i:46 + 24 * i] for i in range(10)]
    n = offsets[10] - 1
    base = 22 + 240
    xs = struct.unpack_from(f"<{n}f", data, base)
    ys = struct.unpack_from(f"<{n}f", data, base + 4 * n)
    pens = struct.unpack_from(f"<{n}h", data, base + 8 * n)
    records = [Record(*r) for r in zip(xs, ys, pens)]
    return tuple(tuple(records[offsets[k] - 1:offsets[k + 1] - 1]) if names[k].strip() else () for k in range(10))


def symbol(number: int) -> tuple[Record, ...]:
    lib = library(number // 10)
    return lib[number % 10] if lib else ()


def symbol_points(x0: float, y0: float, number: int, xs: float, ys: float, step: float = STEP) -> list[tuple[int, int, int]]:
    """draw_symbol's library path: scale, then x = f32(xs*X + x0), y = f32(ys*Y + y0), pen max(pen, 0)."""
    xs = f32(xs - trunc(xs / 100) * 100) or 1.0      # amod(xs, 100); 0 means 1
    ys = ys or xs
    if 49 < number < 5000:
        xs, ys = f32(xs * f32(0.3)), f32(ys * f32(0.3))
    xs, ys = f32(step * xs), f32(step * ys)
    return [(trunc(f32(xs * r.x + x0)), trunc(f32(ys * r.y + y0)), max(r.pen, 0)) for r in symbol(number)]


def emitted(points: list[tuple[int, int, int]], last_pen: int = 0) -> list[tuple[int, int, int]]:
    """emit_points (0x54A69C): a start point (pen != 0) right after another start replaces it."""
    out: list[tuple[int, int, int]] = []
    for point in points:
        if point[2] != 0 and last_pen != 0 and out:
            out.pop()
        out.append(point)
        last_pen = point[2]
    return out


def code9_points(p: list[float]) -> list[tuple[int, int, int]]:
    P = [0.0] + p + [0.0] * (27 - len(p))
    x = f32(P[3] * 150)
    if P[15] != 0:
        x = f32(P[15] * 150 + x)
    y = f32(float(staff_base(1) - 525) + P[4] * 7 * STEP)
    return emitted(symbol_points(x, y, trunc(P[5]), P[6], P[7]))


def engine_points(lab: Lab, item: list[float]) -> list[tuple[int, int, int]]:
    result = lab.load([STAFF, item])
    dx, dy = lab.engine.i32(VIEW_DX), lab.engine.i32(VIEW_DY)
    body = [t for t in result.vector if t[2] & 0xFFFFFF != 0x00FD00][10:]
    return [(x - dx, y + dy, tag >> 24) for x, y, tag in body]


def available_symbols() -> list[int]:
    return [10 * lib + k for lib in range(0, 100) if library(lib) for k in range(10) if symbol(10 * lib + k)]


def random_item(rng: random.Random, numbers: list[int]) -> list[float]:
    maybe = lambda value: value if rng.random() < 0.4 else 0
    p = [9, 1, rng.uniform(0, 190), rng.uniform(-8, 16), rng.choice(numbers), maybe(rng.uniform(0.3, 3)),
         maybe(rng.uniform(0.3, 3)), 0, 0, 0, 0, 0, 0, 0, maybe(rng.uniform(-3, 3))]
    return [f32(float(v)) for v in p]


def main(cases: int = 300):
    rng = random.Random(9)
    numbers = [n for n in available_symbols() if not 1299 < n < 1305 and n not in TEXT_SYMBOLS]
    lab = Lab()
    bad = 0
    for case in range(cases):
        item = random_item(rng, numbers)
        expected, got = code9_points(item), engine_points(lab, item)
        if got != expected:
            bad += 1
            print(f"case {case}: {item}\n  model  {expected[:12]}\n  engine {got[:12]}")
    print(f"{cases - bad}/{cases} symbols match ({len(numbers)} symbols available)")


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
