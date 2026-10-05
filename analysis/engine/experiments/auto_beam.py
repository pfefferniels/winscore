"""Secondary beams of a beam in edit mode: AUTO, AUTOX, SPL1..SPL4, SPL222 (0x417738 with
0x419498 and 0x419328), and the check against the oracle.

    python auto_beam.py [cases]

The beam's notes get a beam count from their duration; the smallest count becomes the beam's
P7 units digit, the next level's first run goes into P10..P12, the one after into P13..P15, and
further runs into extra beam items inserted after it. SPLn inserts breaks after given notes.
Finally the stem pass of beam_stems.py runs (with opposite stems for AUTOX).
"""
from __future__ import annotations

import random
import sys

from beam_stems import adjust_beam
from staves import f32 as F, trunc


def amod(x, y):
    return F(x - trunc(x / y) * y)


def cmod(a: int, b: int) -> int:
    return a - b * trunc(a / b)


def par(it, k):
    return it[k - 1] if len(it) >= k else 0.0


def beam_count(d: float) -> int:
    for limit, n in ((0.0157, 6), (0.0313, 5), (0.0626, 4), (0.1251, 3), (0.2501, 2)):
        if d < F(limit):
            return n
    return 1


def split_points(n: int) -> tuple[int, int, int, int] | None:
    """SPL number -> rows after which a break is inserted (0x7D1470, 74, 78, 7C); None: no change."""
    if n < 100:
        return 0, 0, 0, n
    a = n // 1000
    t = cmod(n, 1000) // 100
    if t == 0:
        return None
    b = t + a + (1 if a > 0 else 0)
    t2 = cmod(n, 100) // 10
    if t2 == 0:
        return None
    c = t2 + b + 1
    if cmod(n, 10) == 0:
        return None
    return a, b, c, c + cmod(n, 10) + 1


class AutoBeam:
    """One run of 0x417738 on the beam in edit mode; `E` is the edit buffer (1-based)."""

    def __init__(self, items: list[list[float]], edit: int, word: str, number: int = 0):
        self.items = items
        self.edit = edit
        self.word = word
        self.E = [0.0] + list(items[edit - 1]) + [0.0] * (30 - len(items[edit - 1]))
        self.number = number

    def run(self):
        E = self.E
        splits = (0, 0, 0, 0)
        if self.word.startswith("SP"):
            p2 = -float(self.number if not 9 < self.number < 100 else self.number * 10 + 9)
            if not (E[13] != 0 or (E[14] == 0 and E[15] == 0)):
                return
            if self.same_as_neighbour():
                return
            n = trunc(-p2)
            p2 = 98.0 if len(self.word) > 2 and self.word[2] == "X" else p2
            found = split_points(n)
            if found is None:
                return
            splits = found
        else:
            p2 = 98.0 if self.word == "AUTOX" else 99.0
        self.p2 = p2
        all_stems = p2 == 98
        staff = trunc(E[2])
        start_dir = trunc(E[7] / 10)
        direction = start_dir
        while True:
            rows = self.collect(staff, direction, all_stems, splits)
            if rows is None:
                return
            if len(rows) >= 2:
                break
            if start_dir != direction:
                return
            step = F(13) if direction == 1 else F(-13)
            direction = 2 if direction == 1 else 1
            E[4], E[5] = F(step + E[4]), F(step + E[5])
        self.secondary(rows, direction, all_stems)

    def same_as_neighbour(self) -> bool:
        """The beam in edit mode equals the item before or after it in P1..P6 (a second-level beam item)."""
        E, items, i = self.E, self.items, self.edit
        return any(1 <= j <= len(items) and all(E[k] == par(items[j - 1], k) for k in range(1, 7))
                   for j in (i + 1, i - 1))

    def collect(self, staff, direction, all_stems, splits):
        E = self.E
        rows = []
        cue = False
        for it in self.items:
            n = len(it)
            if not (par(it, 7) > 0 and n > 6 and it[2] <= E[6] + F(0.04) and E[3] - F(0.04) <= it[2]
                    and trunc(it[0]) == 1 and trunc(it[1]) == staff):
                continue
            stem = trunc(cmod(trunc(it[4]), 100) / 10)
            if not (all_stems or direction == stem or (n > 11 and it[11] != 0)):
                continue
            a = abs(it[3])
            if not rows:
                b = abs(E[4])
                cue = a >= 100
                if not cue and b >= 100:
                    E[4] = amod(E[4], 100)
                    self.items[self.edit - 1][3] = E[4]
                elif cue and b < 100:
                    E[4] = F((F(-100) if E[4] < 0 else F(100)) + E[4])
                    self.items[self.edit - 1][3] = E[4]
            if cue != (a >= 100):
                continue
            d = it[6]
            if d >= 64:
                d = F(0.25)
            if n > 8:
                dots = cmod(trunc(it[8] / 10), 100)
                if dots == 1:
                    d = F(d / F(1.5))
                if dots == 2:
                    d = F(d / F(1.75))
            if d > F(0.5001):
                break
            row = (list(it[:10]) + [0.0] * 10)[:10]
            row[6] = float(beam_count(d))
            rows.append(row)
            if splits[3] != 0 and len(rows) in splits and row[2] < E[6]:
                extra = list(row)
                extra[2] = F(row[2] + F(0.2))
                extra[6] = 1.0
                rows.append(extra)
        return rows

    def secondary(self, rows, direction, all_stems):
        E = self.E
        S = [None] + [rows[k] for k in self.stable_last_min(rows)]
        count = len(rows)
        level = [0.0] + [S[k][6] for k in range(1, count + 1)]
        if abs(S[1][3]) >= 100:
            if abs(E[4]) < 100:
                E[4] = amod(E[4], 100)
        elif abs(E[4]) >= 100:
            E[4] = F((F(-100) if E[4] < 0 else F(100)) + E[4])
        differs = any(level[1] != level[k] for k in range(1, count + 1))
        least = min([99.0] + level[1:])
        for k in range(1, count + 1):
            if level[k] == least:
                level[k] = F(least + 100)
        E[7] = F(float(direction * 10) + least)
        E[6] = S[count][2]
        E[3] = S[1][2]
        target = self.edit
        if not differs:
            for k in range(8, 16):
                E[k] = 0.0
            self.store(target, length=None)
            self.finish(all_stems, target)
            return
        while True:
            self.levels(S, level, count, least)
            length = next((k for k in range(21, 0, -1) if E[k] != 0), 0)
            self.store(target, length)
            if not any(level[k] < 99 for k in range(1, count + 1)):
                break
            target = self.insert_copy(target)
        self.finish(all_stems, target)

    @staticmethod
    def stable_last_min(rows):
        """The selection sort of 0x417738: repeatedly the last row with the smallest P3."""
        left = list(range(len(rows)))
        out = []
        while left:
            best = min(rows[k][2] for k in left)
            pick = [k for k in left if rows[k][2] == best][-1]
            out.append(pick)
            left.remove(pick)
        return out

    def levels(self, S, level, count, least):
        """P10..P12 for the next level's first run, then P13..P15 for the one after."""
        E = self.E
        for k in range(10, 16):
            E[k] = 0.0
        slots = [(10, 11, 12), (13, 14, 15)]
        for code_slot, first_slot, last_slot in slots:
            nxt = min([99.0] + [v for v in level[1:] if v < 100])
            E[code_slot] = F(F(least * 10 + nxt) - least)
            end = self.run_bounds(S, level, count, nxt, first_slot, last_slot)
            self.mark_run(level, nxt, end)
            if code_slot == 13 or not any(v < 99 for v in level[1:]):
                return

    def run_bounds(self, S, level, count, nxt, a, b) -> int:
        E = self.E
        k = 1
        while k <= count:
            if level[k] >= 99:
                k += 1
                continue
            j = k
            found = False
            while j <= count:
                if level[j] == nxt:
                    found = True
                    break
                if level[j] >= 99:
                    break
                j += 1
            if not found and j <= count:
                k += 1
                continue
            end = k
            if count <= k:
                E[a], E[b] = 0.0, -1.0
                return end
            if (k > 1 and amod(level[k - 1], 100) < level[k]) or count == k:
                a, b = b, a
            E[b] = 0.0
            E[a] = S[k][2]
            if level[k + 1] >= 99:
                return end
            end = k + 1
            while end <= count and level[end] < 99:
                end += 1
            E[b] = S[end - 1][2]
            return end
        return 0

    @staticmethod
    def mark_run(level, nxt, end):
        k = 1
        while k <= min(end, len(level) - 1):
            if level[k] == nxt:
                j = k
                while j <= end and j < len(level) and level[j] == nxt:
                    level[j] = F(nxt + 100)
                    j += 1
                return
            k += 1

    def store(self, target: int, length: int | None):
        it = self.items[target - 1]
        n = len(it) if length is None else length
        it[:] = [self.E[k] for k in range(1, n + 1)]

    def insert_copy(self, after: int) -> int:
        it = self.items[after - 1]
        n = max(len(it) + 1, 13)
        copy = (list(it) + [0.0] * n)[: n - 1]
        self.items.insert(after, copy)
        return after + 1

    def finish(self, all_stems, target: int):
        """AUTOX's P9 and the stem pass, both from the edit buffer, which holds the last stored item."""
        E = self.E
        last = self.items[target - 1]
        length = len(last)
        if self.p2 == 98:
            p9 = self.stem_side_flags([E[k] for k in range(1, length + 1)])
            if p9 != 0:
                E[9] = p9
                if length < 9:
                    it = self.items[self.edit - 1]
                    if len(it) == 7:
                        it.append(0.0)
                    it.extend([0.0] * (9 - len(it)))
                    it[8] = p9
                    length = 9
                else:
                    last[8] = p9
        adjust_beam(self.items, [E[k] for k in range(1, length + 1)], "ADX" if all_stems else "AD ")

    def stem_side_flags(self, beam: list[float]) -> float:
        """0x419498: digits of P9 for the beam ends (hundreds), beam 2 (tens), beam 3 (units)
        where a note with the opposite stem sits: 1 start, 2 end, 3 both."""
        E = [0.0] + list(beam) + [0.0] * 20
        staff, beam_dir = trunc(E[2]), abs(trunc(trunc(E[7]) / 10))
        b2s = E[3] if E[11] == -1 else E[11]
        b2e = E[6] if E[12] == -1 else E[12]
        b3s = E[3] if E[14] == -1 else E[14]
        b3e = E[6] if E[15] == -1 else E[15]
        digits = {"h": 0, "t": 0, "u": 0}
        mark = lambda key, v: digits.__setitem__(key, 3 if digits[key] else v)
        last = -9999.0
        for note in self.items:
            if not (trunc(note[1]) == staff and trunc(note[0]) == 1 and par(note, 3) <= E[6]
                    and last != par(note, 3) and E[3] <= par(note, 3) and len(note) > 4):
                continue
            stem = trunc(cmod(trunc(note[4]), 100) / 10)
            if stem == 0 or stem == beam_dir:
                continue
            x = note[2]
            if E[3] == x:
                mark("h", 1)
            if b2s == x:
                mark("t", 1)
            if b3s == x:
                mark("u", 1)
            if E[6] == x:
                mark("h", 2)
            if b2e == x:
                mark("t", 2)
            if b3e == x:
                mark("u", 2)
            last = x
        return float(digits["h"] * 100 + digits["t"] * 10 + digits["u"])


def auto_beam(items, edit: int, word: str):
    number = 0
    if word.startswith("SPL"):
        number = int(word[3:])
    AutoBeam(items, edit, word, number).run()


def random_case(rng: random.Random):
    x = round(rng.uniform(40, 70), 1)
    durs = []
    for _ in range(rng.randint(2, 6)):
        durs.append(rng.choice([0.5, 0.25, 0.25, 0.125, 0.375, 0.1875, 0.0625]))
    up = rng.random() < 0.5
    notes = []
    for k, d in enumerate(durs):
        stem = (1 if up else 2) if rng.random() < 0.85 else (2 if up else 1)
        dots = 10 if d in (0.375, 0.1875) else 0
        notes.append([1, 1, round(x + 10 * k, 2), rng.randint(0, 9), stem * 10, 0, d, 0, dots])
    cue = rng.random() < 0.15
    if cue:
        for note in notes:
            note[3] += 100
    lvl = 13 if up else -2
    beam = [6, 1, notes[0][2], lvl + (100 if cue and rng.random() < 0.5 else 0), lvl + rng.choice([-1, 0, 1]),
            notes[-1][2], (10 if up else 20) + 1]
    items = [[8, 1, 0, 0, 1], [3, 1, 2, 0, 0]] + notes + [beam, [14, 1, 200, 1]]
    return [[F(float(v)) for v in it] for it in items]


def main(cases: int = 30):
    from cmdlab import CommandLab
    rng = random.Random(9)
    good = total = 0
    for case in range(cases):
        items = random_case(rng)
        lab = CommandLab(items)
        k = next(i for i, it in enumerate(items, 1) if it[0] == 6)
        for word in ("AUTO", "AUTOX", "SPL1", "SPL2", "SPL3", "SPL22", "SPL222"):
            model = [list(it) for it in items]
            auto_beam(model, k, word)
            engine = lab.run([f"I {k}", word, "X"], digits=None).items
            total += 1
            if model == engine:
                good += 1
            else:
                print(f"case {case} {word}: notes {[(it[2], it[6]) for it in items if it[0] == 1]}")
                for a, b in zip(model, engine):
                    if a != b:
                        print("   model ", a, "\n   engine", b)
                if len(model) != len(engine):
                    print("   lengths", len(model), len(engine), engine[len(model):] or model[len(engine):])
    print(f"{good}/{total} identical")


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
