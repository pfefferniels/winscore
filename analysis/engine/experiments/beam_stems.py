"""Stem lengths of beamed notes: ADJ, ADX, ADF on a beam in edit mode (0x40CDE4, 0x40C1C0),
and the check against the oracle.

    python beam_stems.py [cases]

Leaving any beam command recomputes P8 (stem length) and P9 of the beam's notes this way; the
area form (ADJ after a box) runs the same per beam. commands.md describes the rule.
"""
from __future__ import annotations

import random
import sys

from staves import f32 as F, trunc

H_UNIT = F(2.83333)      # head offset in staff-size units (f32 0x... used as f_2_83333)


def amod(x, y):
    """0x54AABA (numerics.md)"""
    return F(x - trunc(x / y) * y)


def cmod(a, b):
    return a - b * trunc(a / b)


def par(it, k):
    return it[k - 1] if len(it) >= k else 0.0


def beam_stem(beam: list[float], note: list[float], stem: int, letter3: str, step: float,
              staff_y: dict[int, float] | None = None) -> float:
    """0x40C1C0: P8 of one note under the beam (before the division by P15)."""
    b = {k: par(beam, k) for k in range(1, 18)}
    n = {k: par(note, k) for k in range(1, 13)}
    ip7 = trunc(b[7])
    ip8 = ip7 // 10 if ip7 >= 0 else -((-ip7) // 10)
    ip4 = abs(trunc(b[4] / 100))
    n[4] = F(amod(n[4], 100))
    if n[12] != 0 and staff_y:
        s = trunc(n[2])
        other = s + trunc(3 - n[12] * 2)
        d = trunc(staff_y[s] - staff_y[other])
        n[4] = F(F(-(d / (step * 7))) + n[4])
    size = F(0.6) if ip4 > 0 else 1.0
    h = F(size * H_UNIT * step / 25)
    if stem == 1:
        n[3] = F(h + n[3])
    beams = cmod(ip7, 10)
    if b[17] == 0:
        b[17] = 1.0
    if ip4 > 0:
        b[17] = F(b[17] * F(0.8))
    ip10, ip13 = trunc(b[10]), trunc(b[13])
    extra = F((beams - 1) * F(1.5))
    if b[11] == -1:
        b[11] = b[3]
    if b[12] == -1:
        b[12] = b[6]
    if b[14] == -1:
        b[14] = b[3]
    if b[15] == -1:
        b[15] = b[6]
    if ip8 == 1:
        b[3], b[6] = F(h + b[3]), F(h + b[6])
    second = third = 0.0
    if ip10 != 0:
        if ip8 == 1:
            if b[11] != 0:
                b[11] = F(h + b[11])
            if b[12] != 0:
                b[12] = F(h + b[12])
        if ip10 < 0:
            if b[11] != 0 and b[12] != 0:
                second = F(-(float(trunc(ip10 / 10)) * F(1.5)))
        else:
            unit = cmod(ip10, 10) or 1
            second = F(float(trunc(ip10 / 10) + unit - beams) * F(1.5))
    shift = lambda v: h if v == 10 else (-h if v == 20 else v)
    if ip13 == 0:
        b[3] = F(shift(b[14]) + b[3])
        b[6] = F(shift(b[15]) + b[6])
    else:
        if ip8 == 1:
            if b[14] != 0:
                b[14] = F(h + b[14])
            if b[15] != 0:
                b[15] = F(h + b[15])
        if ip13 < 0:
            if b[14] != 0 and b[15] != 0:
                third = F(-(float(trunc(ip13 / 10)) * F(1.5)))
        else:
            unit = cmod(ip13, 10) or 1
            third = F(float(trunc(ip13 / 10) + unit - beams) * F(1.5))
    if n[10] != 0:
        n[3] = F(shift(n[10]) + n[3])
    if len(beam) > 8:
        ip9 = trunc(b[9])
        hh = -h if ip8 == 1 else h
        hundreds, tens, units = trunc(ip9 / 100), trunc(cmod(ip9, 100) / 10), cmod(ip9, 10)
        if hundreds in (1, 3):
            b[3] = F(hh + b[3])
        if hundreds in (2, 3):
            b[6] = F(hh + b[6])
        if tens in (1, 3):
            b[11] = F(hh + b[11])
        if tens in (2, 3):
            b[12] = F(hh + b[12])
        if units in (1, 3):
            b[14] = F(hh + b[14])
        if units in (2, 3):
            b[15] = F(hh + b[15])
    span = F(b[6] - b[3])
    left = F(amod(b[4], 100) - n[4])
    right = F(b[5] - n[4])
    if stem != 1:
        left, right = F(-left), F(-right)
    level = F(((n[3] - b[3]) / span) * (right - left) + left)
    x = n[3]
    if ip8 == stem:
        add = 0.0
        if x < b[12] + F(0.1) and ip10 < 0 and b[11] - F(0.1) < x:
            add = second
        if add < third and x < b[15] + F(0.1) and ip13 < 0 and b[14] - F(0.1) < x:
            add = third
        length = F(add + level / size)
    else:
        add = 0.0
        if x < b[12] + F(0.1) and ip10 > 0 and b[11] - F(0.1) < x:
            add = second
        if add < third and x < b[15] + F(0.1) and ip13 > 0 and b[14] - F(0.1) < x:
            add = third
        length = F(add + ((extra + level / size) - 14) + b[17])
    if letter3 == "F" and abs(b[3] - x) > F(0.1) and abs(b[6] - x) > F(0.1):
        cut = 0.0
        if b[12] != 0 and ip10 != 0 and b[11] != 0 and b[11] + F(0.1) <= x <= b[12] - F(0.1):
            cut = second
        if (b[15] != 0 and ip13 != 0 and b[14] != 0 and b[14] + F(0.1) <= x <= b[15] - F(0.1)
                and cut < third):
            cut = third
        length = F((length - extra) - cut)
    return length


def adjust_beam(items: list[list[float]], beam: list[float], command: str, step: float = 25.0):
    """0x40CDE4 for one beam in edit mode: P8 (and P9) of its notes; changes `items` in place."""
    letter3 = command[2] if len(command) > 2 else " "
    take_opposite = letter3 == "X" or (len(command) > 3 and command[3] == "X")
    if par(beam, 7) < 0:
        return
    ip7 = trunc(beam[6])
    beam_dir = ip7 // 10
    for it in items:
        if not (len(it) > 4 and trunc(it[0]) == 1 and trunc(it[1]) == trunc(beam[1])):
            continue
        if not (beam[2] - F(0.1) <= it[2] <= beam[5] + F(0.1)):
            continue
        stem = trunc(amod(it[4], 100) / 10)
        if stem == 0 or par(it, 6) == 1:
            continue
        if not (beam_dir == stem or take_opposite):
            continue
        if abs(trunc(par(beam, 4) / 100)) != abs(trunc(it[3] / 100)):
            continue
        length = beam_stem(beam, it, stem, letter3, step)
        if len(it) < 8:
            it.extend([0.0] * (8 - len(it)))
        if len(it) > 14 and it[14] != 0:
            length = F(length / it[14])
        it[7] = length
        if len(it) > 8 and it[8] != 0:
            it[8] = F(it[8] - float(trunc(amod(it[8], 10))))


def random_case(rng: random.Random):
    x1 = round(rng.uniform(40, 80), 1)
    count = rng.randint(2, 5)
    xs = [round(x1 + k * rng.uniform(6, 12), 2) for k in range(count)]
    up = rng.random() < 0.5
    beams = rng.choice([1, 1, 2, 3])
    level = rng.uniform(10, 16) if up else rng.uniform(-6, 0)
    beam = [6, 1, x1, round(level, 1), round(level + rng.uniform(-3, 3), 1), xs[-1], (10 if up else 20) + beams]
    if rng.random() < 0.3:
        beam += [0, 0, rng.choice([11, 12, -10, 21]), rng.choice([0, -1, xs[1]]), rng.choice([0, -1, xs[-1]])]
    notes = []
    for x in xs:
        stem = rng.choice([1, 1, 2]) if up else rng.choice([2, 2, 1])
        notes.append([1, 1, x, rng.randint(-2, 10), stem * 10 + rng.choice([0, 0, 1, 3]), 0, 0.25, 0,
                      rng.choice([1, 2, 0])])
    items = [[8, 1, 0, 0, 1], [3, 1, 2, 0, 0]] + notes + [beam, [14, 1, 200, 1]]
    return [[F(float(v)) for v in it] for it in items]


def main(cases: int = 40):
    from cmdlab import CommandLab
    rng = random.Random(3)
    good = total = 0
    for case in range(cases):
        items = random_case(rng)
        lab = CommandLab(items)
        k = next(i for i, it in enumerate(items, 1) if it[0] == 6)
        for command in ("ADJ", "ADX", "ADF"):
            model = [list(it) for it in items]
            adjust_beam(model, model[k - 1], command)
            run = lab.run([f"I {k}", command, "X"], digits=None)
            engine = run.items
            notes_m = [it[:9] for it in model if it[0] == 1]
            notes_e = [it[:9] for it in engine if it[0] == 1]
            total += 1
            if notes_m == notes_e:
                good += 1
            else:
                print(f"case {case} {command}: beam {items[k - 1]}")
                for a, b in zip(notes_m, notes_e):
                    if a != b:
                        print("   model", a, "\n   engine", b)
    print(f"{good}/{total} beam adjustments identical")


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
