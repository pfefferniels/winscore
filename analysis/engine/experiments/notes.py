"""Check the note model of notes.md (code 1: draw_note 0x4EFEC0 and its parts) against the engine.

    python notes.py [cases]     (default 300)

Random single notes on staff 1 (head types 0-2, stems, P8, tails, dots, accidentals,
ledger lines, P10, P15, P19, P20), then pairs of black notes for the head cache.
"""
from __future__ import annotations

import random
import sys

from lab import Lab
from staves import f32, staff_base, trunc
from symbols import emitted, symbol_points

VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4
HEAD_CACHE_SCALE = 0x78B6AC
STAFF = [8, 1, 0, 0, 1]
STAFF_STEP = 25.0
STAFF_Y = float(staff_base(1) - 525)

Point = tuple[int, int, int]


def amod(x: float, y: float) -> float:
    return x - trunc(x / y) * y


def c_div(a: int, b: int) -> int:
    """Fortran/C integer division, truncating toward zero."""
    return trunc(a / b)


def clef_symbol(x: float, y: float, number: int, xs: float, ys: float, step: float) -> list[Point]:
    """draw_clef (0x431AE0) for symbol numbers >= 6 drawn by a note (IP1 = 1, OUTPUT_MODE = 1)."""
    xs = xs or 1.0
    ys = ys or xs
    if number + 1 < 46:
        xs = f32(xs * 0.25) or 0.25
        ys = f32(ys * 0.25)
    return symbol_points(x, y, number, xs, ys, step)


class HeadCache:
    """note_head (0x4F14B0) keeps the integer offsets of the last black head drawn at a given scale."""

    def __init__(self):
        self.scale: float | None = None
        self.offsets: list[Point] = []

    def head(self, x: float, y: float, width: float, hs: float) -> list[Point]:
        scale = f32(width * hs)
        ix, iy = trunc(x), trunc(y)
        if scale == self.scale:
            return [(ix + dx, iy + dy, pen) for dx, dy, pen in self.offsets]
        self.scale = scale
        points = clef_symbol(x, y, 11, width, 1.0, hs)
        self.offsets = [(px - ix, py - iy, pen) for px, py, pen in points]
        return points


def note_points(p: list[float], cache: HeadCache) -> list[Point]:
    """Points of one note in emission order (ledger lines are flushed first by note_ledger_lines)."""
    P = [0.0] + p + [0.0] * (40 - len(p))
    ip = lambda k: trunc(P[k])
    step = STAFF_STEP
    step7 = f32(step * 7)
    cue = abs(ip(4)) // 100
    ip4 = ip(4) % 100 if cue else ip(4)
    width = P[20] if P[20] != 0 else 1.0
    if P[15] != 0:
        step = f32(P[15] * step)
        cue = 0
    hs = f32(step * 0.6) if cue == 1 else step
    head_type = ip(6)
    head_w = f32(hs * (19.0 if head_type % 1000 in (2, 3) else 17.0) * width)
    x = f32(P[3] * 150)
    y = f32(STAFF_Y + amod(P[4], 100) * 7 * STAFF_STEP)
    if P[10] != 0:
        dx = head_w if P[10] == 10 else f32(-head_w) if P[10] == 20 else f32(step * 6 * P[10])
        x = f32(dx + x)
    points: list[Point] = []
    if ip(30) != 0 or (ip(7) > -2 and (ip4 < 2 or ip4 > 12)):
        points += ledger_lines(x, y, ip4, hs, head_w, step7)
    points += cache.head(x, y, width, hs) if head_type == 0 else clef_symbol(x, y, head_type + 11, width, 1.0, hs)
    tails = ip(9) % 10
    stem = (ip(5) % 100) // 10
    if tails:
        points += note_tails(x, y, P, tails, stem, hs, head_w, width)
    if ip(5) % 10:
        points += accidental(x, y, P, hs, head_w)
    if stem:
        points += note_stem(x, y, P, tails, stem, hs, head_w)
    else:
        stem = 2 if ip4 > 6 else 1
    if ip(9) > 9:
        points += dots(x, y, P, ip4, tails, stem, hs, step7, width, cue)
    return points


def ledger_lines(x: float, y: float, ip4: int, hs: float, head_w: float, step7: float) -> list[Point]:
    x0, x1 = f32(x - f32(hs * 5)), f32(head_w + x + f32(hs * 5))
    d = f32(-step7 - step7)
    if ip4 < 2:
        first, inc, d = 1, -2, -d
    else:
        first, inc = 13, 2
    if ip4 % 2 == 0:
        y = f32(f32(d / 2) + y)
    out = []
    for _ in range(max(c_div(ip4 - first + inc, inc), 0)):
        out += [(trunc(x0), trunc(y), 1), (trunc(x1), trunc(y), 0)]
        y = f32(d + y)
    return out


def note_tails(x, y, P, tails, stem, hs, head_w, width) -> list[Point]:
    d, sign = f32(-(hs * 7)), 1.0
    if stem != 2:
        sign, x, d = -1.0, f32(x + head_w), f32(hs * 7)
    ty = f32(amod(P[8], 100) * d + y + d)
    if tails > 1:
        ty = f32(ty - d / 2)
    out = []
    for _ in range(tails):
        out += clef_symbol(x, ty, 20, width, sign, hs)
        ty = f32(d + ty + d)
    return out


def accidental(x, y, P, hs, head_w) -> list[Point]:
    acc = trunc(P[5]) % 10
    if acc > 5 or trunc(P[5]) // 100 == 1:
        acc += 134
    shift = amod(P[5], 1)
    if shift != 0:
        if shift > f32(0.9):
            shift = f32(f32(0.9) - shift)
        shift = f32(shift * 60 * hs)
    if P[10] == 10:                      # the head moved right by its width; the accidental stays
        shift = f32(head_w + shift)
    size = P[29] or 1.0
    return clef_symbol(f32(x - shift), y, acc + 5, size, size, hs)


def note_stem(x, y, P, tails, stem, hs, head_w) -> list[Point]:
    extra = f32(float(trunc(float(tails * 2 - 2))) - 0.5) if tails > 1 else 0.0
    p8 = P[8]
    length = f32((extra + 7 + p8) * hs * 7)
    if trunc(P[6]) >= 2 and (trunc(P[6]) in (2, 3) or trunc(P[6]) > 899 or (trunc(P[6]) != 139 and 99 < trunc(P[6]) < 199)):
        return []
    if stem == 2:
        sx, length = x, f32(-length)
    else:
        sx = f32(x + head_w)
    y1 = f32(length + y)
    off = 2.1 if trunc(P[6]) < 4 else (7.0 if trunc(P[6]) == 6 else 0.0 if trunc(P[6]) < 9 else 2.1)
    if stem == 2:
        off = -off
    y0 = f32(hs * f32(off) + y)
    return [(trunc(sx), trunc(y0), 1), (trunc(sx), trunc(y1), 0)]


def dots(x, y, P, ip4, tails, stem, hs, step7, width, cue) -> list[Point]:
    count = trunc(P[9])
    yoff = step7 if ip4 % 2 else 0.0
    frac = f32(amod(P[9], 1))
    if frac > f32(0.9):
        frac = f32(f32(0.9) - frac)
    if count > 999:
        frac = f32(frac + f32(0.284))
        count -= 1000
    if count > 99:
        yoff, count = -yoff, count - 100
    xoff = f32(16.2) if trunc(P[8]) == 0 and tails and stem == 1 else 18.0
    xoff = f32((frac * 60 + xoff) * hs)
    if stem != 1 and tails == 0 and trunc(P[6]) in (7, -1):
        xoff = f32(xoff / 2)
    dx = f32(width * xoff + x)
    if P[19] != 0:
        yoff = f32(step7 * P[19] + yoff)
    dy = f32(y + yoff)
    size = f32(0.6) if cue == 1 else 1.0
    out = []
    for _ in range(count // 10):
        out += clef_symbol(dx, dy, 24, size, size, hs)
        dx = f32(hs * 13 + dx)
    return out


def engine_points(lab: Lab, notes: list[list[float]]) -> list[Point]:
    lab.engine.put32(HEAD_CACHE_SCALE, 0)
    result = lab.load([STAFF] + notes)
    dx, dy = lab.engine.i32(VIEW_DX), lab.engine.i32(VIEW_DY)
    body = [t for t in result.vector if t[2] & 0xFFFFFF != 0x00FD00][10:]
    return [(x - dx, y + dy, tag >> 24) for x, y, tag in body]


def model_points(notes: list[list[float]]) -> list[Point]:
    """fit_view's trial draw fills the head cache before the drawing that is output."""
    cache = HeadCache()
    for note in notes:
        note_points(note, cache)
    return emitted([pt for note in notes for pt in note_points(note, cache)])


def random_note(rng: random.Random) -> list[float]:
    maybe = lambda value, chance=0.3: value if rng.random() < chance else 0
    stem = rng.choice([0, 1, 2])
    p5 = stem * 10 + maybe(rng.randint(1, 5), 0.4) + maybe(rng.choice([0.2, 0.5, 0.95]), 0.2)
    p9 = maybe(rng.randint(1, 2), 0.4) * 10 + maybe(rng.randint(1, 4), 0.5)
    p = [1, 1, rng.uniform(5, 190), rng.choice([rng.uniform(-6, 18), float(rng.randint(-6, 18))]), p5,
         rng.choice([0, 0, 1, 2]), 1, maybe(rng.uniform(-3, 3)), p9, maybe(rng.choice([10, 20, 1.5])),
         0, 0, 0, 0, maybe(rng.uniform(0.6, 1.5), 0.2), 0, 0, 0, maybe(rng.uniform(-1, 1), 0.2),
         maybe(rng.uniform(0.7, 1.4), 0.2)]
    return [f32(float(v)) for v in p]


def main(cases: int = 300):
    rng = random.Random(1)
    lab = Lab()
    bad = 0
    for case in range(cases):
        notes = [random_note(rng)] if case % 3 else [random_note(rng), random_note(rng)]
        if len(notes) == 2:
            for note in notes:
                note[5] = 0.0                     # black heads, the cached case
        expected, got = model_points(notes), engine_points(lab, notes)
        if got != expected:
            bad += 1
            first = next((i for i, (a, b) in enumerate(zip(expected, got)) if a != b), min(len(expected), len(got)))
            print(f"case {case}: {notes}\n  lengths {len(expected)} {len(got)}, first difference at {first}:"
                  f"\n  model  {expected[max(first - 2, 0):first + 4]}\n  engine {got[max(first - 2, 0):first + 4]}")
    print(f"{cases - bad}/{cases} note cases match")


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
