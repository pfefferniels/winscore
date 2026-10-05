"""CV, CNL and CNR on a slur in edit mode (0x42C9B0 with 0x42DAF8, 0x42D9F9, 0x42E11C, 0x42E437,
0x42C60E, 0x42D887, 0x42E94D, 0x42E6AB, 0x42E82D), and the check against the oracle.

    python slur_center.py [cases]

0x42C9B0 builds a list of (parameter, value) pairs in the globals P1..P8; after it the command
is turned into a parameter command and edit_params applies the pairs to the slur.
"""
from __future__ import annotations

import math
import random
import sys

from staves import f32 as F, trunc


def amod(x, y):
    return F(x - trunc(x / y) * y)


def cmod(a: int, b: int) -> int:
    return a - b * trunc(a / b)


def par(it, k):
    return it[k - 1] if len(it) >= k else 0.0


class SlurCommand:
    def __init__(self, items, edit: int, word: str, right: float = 200.0, step: float = 25.0):
        self.items = items
        self.edit = edit
        self.word = word
        self.right = right
        self.step = step
        self.E = [0.0] + list(items[edit - 1]) + [0.0] * 20
        self.staff = trunc(self.E[2])
        self.pairs: list[list[float]] = []          # slots (P1,P2), (P3,P4), ...
        self.b0 = 0                                   # next slot (0x1CAF6B0, counted in pairs)

    # --- 0x42DAF8 for a slur (code 5)
    def snap(self, k: int, mode: int) -> int | None:
        """Pair (k, x) for the item nearest to E(k); notes and rests, or barlines when P8 is 1 or 2."""
        E = self.E
        while True:
            best, found, count, first_count = 99999.0, None, 0, 0
            for i, it in enumerate(self.items, 1):
                if i == self.edit or trunc(it[1]) != self.staff:
                    continue
                c = trunc(it[0])
                if mode == 0:
                    if c > 2:
                        continue
                    count += 1
                elif c != 14:
                    continue
                d = abs(par(it, 3) - E[k])
                if d < best:
                    best, found = d, i
                    if first_count == 0:
                        first_count = count
            self.first_count = first_count
            if found is None:
                return None
            it = self.items[found - 1]
            index = self.b0
            value = par(it, 3) if len(it) > 2 else 0.0
            if mode == 0:
                self.put([float(k), value])
                return found
            if mode == 1:
                if index == 0:
                    if len(it) > 4 and it[4] == 3:
                        value = E[3]
                    self.put([float(k), value])
                    return found
                if value != 0:
                    value = F(value - F(F(2.3) * self.staff_step(it)) / 25)
                    self.put([float(k), value])
                    return found
            else:
                if index == 0:
                    if len(it) > 4 and it[4] == 3:
                        value = F(value - F(1.0 * self.staff_step(it)) / 25)
                    else:
                        value = E[3]
                    self.put([float(k), value])
                    return found
                if value - self.pairs[0][1] > 4:
                    self.put([float(k), value])
                    return found
            E[k] = F(E[k] + 2)
            if self.right < E[k]:
                value = E[6] if not self.right < E[6] else self.right
                self.put([float(k), value])
                return found

    def put(self, pair):
        if self.b0 < len(self.pairs):
            self.pairs[self.b0] = pair
        else:
            self.pairs.append(pair)
        self.b0 += 1

    def staff_step(self, it) -> float:
        return self.step

    # --- 0x42D9F9
    def same_note_again(self) -> bool:
        if self.b0 < 2:
            raise ValueError("CV found no end item: the engine compares unrelated memory (undefined)")
        last, prev = self.pairs[self.b0 - 1], self.pairs[self.b0 - 2]
        if last[1] == prev[1] and trunc(prev[0]) not in (6, 12):
            t = F(self.E[6] + 2)
            if self.right - F(0.5) <= t:
                last[1] = self.right
                return False
            self.E[6] = t
            self.b0 -= 1
            return True
        return False

    # --- 0x42E437 and 0x42E11C
    def note_level(self, it, below: bool) -> float:
        n = len(it)
        v = amod(it[3], 100) if n > 3 else 0.0
        stem = cmod(trunc(it[4]) if n > 4 else 0, 100)
        length = amod(it[7], 100) if n > 7 else 0.0
        if stem < 10:
            length = F(-6)
        if n > 8:
            flags = trunc(amod(it[8], 10)) - 1
            if flags > 0:
                length = F(float(flags * 2) + length)
        if below:
            if stem < 20:
                return F(F(-2) + v)
            off = F(F(-8.4) - length)
        else:
            if stem > 19:
                return F(F(2) + v)
            off = F(length + F(8.4))
        if abs(it[3]) >= 100:
            off = F(off * F(0.6))
        return F(off + v)

    def end_levels(self, n1: int, n2: int | None):
        below = self.E[7] < 0
        for index, n in ((4.0, n1), (5.0, n2)):
            if n is None:
                break
            it = self.items[n - 1]
            if it[0] == 1:
                level = self.note_level(it, below)
                x = par(it, 3) if len(it) >= 3 else 0.0
                for j, other in enumerate(self.items, 1):
                    ox = par(other, 3) if len(other) >= 3 else 0.0
                    if (x == ox and other[0] == 1 and trunc(self.E[2]) == trunc(other[1]) and j != n):
                        v = self.note_level(other, below)
                        level = min(level, v) if below else max(level, v)
                level = self.off_line(level, 20 if below else 10)
                self.put([index, level])
            if n == n2:
                break

    @staticmethod
    def off_line(level: float, side: int) -> float:
        """0x42C60E: an end exactly on an odd step inside the staff moves one step outwards."""
        if amod(level, 2) == 1:
            if side == 10:
                if trunc(level) < 12:
                    level = F(level + 1)
            elif 2 < trunc(level):
                level = F(level - 1)
        return level

    # --- the commands
    def cv(self):
        E = self.E
        mode = trunc(E[8]) if trunc(E[8]) in (1, 2) else 0
        n1 = self.snap(3, mode)
        if n1 is None:
            raise ValueError("CV found no start item (undefined)")
        x1 = self.pairs[0][1]
        n2 = None
        if self.first_count != 1 or x1 < E[6]:
            while True:
                n2 = self.snap(6, mode)
                if not self.same_note_again():
                    break
        else:
            # the end lies left of the start note: (6, x1) and (3, x1 - 4), the second pair being
            # overwritten by the level of the start note below; the end note is a stale reference
            self.pairs = [[6.0, x1], [3.0, F(F(x1 - 4) - (5 if E[8] <= -2 else 0))]]
        if n2 is not None and n2 == n1:
            v = F(F(math.fmod(self.items[n1 - 1][3], 100)) + (F(-1) if E[7] < 0 else F(1)))
            self.pairs[2:4] = [[4.0, v], [5.0, v]]
            return
        self.end_levels(n1, n2)
        if E[8] in (-2, -3):
            d = self.chord_step(n1)
            if cmod(d, 2) == 0:
                v = F(float(d) - F(0.45))
                if E[7] > 0:
                    v = F(v + F(0.9))
            else:
                v = float(d + 1 if E[7] > 0 else d - 1)
            if d > 10 and E[7] > 0:
                v = float(d + 1)
            if d < 4 and E[7] < 0:
                v = float(d - 1)
            for pair in self.pairs[2:4]:
                pair[1] = F(v)

    def chord_step(self, n1: int) -> int:
        """0x42D887: of the notes at the first end's x, the step nearest to the slur's P4."""
        it = self.items[n1 - 1]
        x, s = it[2], trunc(it[1])
        best, out = 99999.0, 0
        for other in self.items:
            if trunc(other[1]) == s and trunc(other[0]) == 1 and par(other, 3) == x:
                v = F(math.fmod(other[3], 100))
                d = abs(v - self.E[4])
                if d <= best:
                    best, out = d, trunc(v)
        return out

    def nearest_note(self, k: int) -> float | None:
        """0x42E82D: x of the note nearest to E(k) (the last of equal distances)."""
        best, out = 99999.0, 0.0
        for it in self.items:
            if trunc(it[0]) == 1 and trunc(it[1]) == self.staff:
                d = abs(self.E[k] - par(it, 3))
                if d <= best:
                    best, out = d, par(it, 3)
        return out if out != 0 else None

    def cnl(self):
        xs = [par(it, 3) for it in self.items if trunc(it[0]) == 1 and trunc(it[1]) == self.staff]
        if not xs:
            return
        d = F(self.step * F(0.2))
        if self.E[8] < -1:
            d = F(self.step * F(0.38))
            if d < 6:
                d = F(6)
        self.put([3.0, F(min(xs) - d)])
        x = self.nearest_note(6)
        if x is not None:
            self.put([6.0, x])

    def cnr(self):
        best = -90999.0
        for it in self.items:
            if trunc(it[0]) != 14:
                continue
            s = trunc(it[1])
            if (self.staff == s or (len(it) > 3 and s <= self.staff and self.staff <= s + it[3] - 1)) and best < it[2]:
                best = it[2]
        if best == -90999.0:
            return
        if self.E[8] == -1:
            best = F((best - F(0.6)) - self.step * F(0.056))
        self.put([6.0, best])
        x = self.nearest_note(3)
        if x is not None:
            self.put([3.0, x])

    def run(self):
        {"CV": self.cv, "CNL": self.cnl, "CNR": self.cnr}[self.word]()
        it = self.items[self.edit - 1]
        applied = [(trunc(k), v) for k, v in self.pairs if trunc(k) >= 1]
        for k, v in applied:
            if k > len(it):
                it.extend([0.0] * (k - len(it)))
            it[k - 1] = v
        while applied and it and it[-1] == 0:      # a changed item is stored up to its last non-zero parameter
            it.pop()


def random_case(rng: random.Random):
    notes, x = [], 30.0
    for _ in range(rng.randint(2, 6)):
        stem = rng.choice([0, 1, 2])
        p4 = rng.randint(-3, 14)
        note = [1, 1, round(x, 2), p4 + (100 if rng.random() < 0.08 else 0), stem * 10 + rng.choice([0, 0, 1]), 0, 1]
        if rng.random() < 0.3:
            note += [rng.choice([0, 7, -7]), rng.choice([0, 1, 2])]
        notes.append(note)
        if rng.random() < 0.25:
            notes.append([1, 1, round(x, 2), p4 + rng.choice([2, 4, -2]), 0, 0, 1])
        x += rng.uniform(8, 22)
    a, b = sorted(rng.sample(range(len(notes)), 2))
    slur = [5, 1, round(notes[a][2] + rng.uniform(-4, 4), 2), rng.randint(8, 16), rng.randint(8, 16),
            round(notes[b][2] + rng.uniform(-4, 4), 2), rng.choice([3, 2, -3, -2])]
    if rng.random() < 0.3:
        slur.append(rng.choice([0, 1, 2, -2, -3, -1]))
    items = [[8, 1, 0, 0, 1], [3, 1, 2, 0, 0]] + notes + [slur]
    if rng.random() < 0.7:
        items.append([14, 1, rng.choice([150, 200]), 1])
    return [[F(float(v)) for v in it] for it in items]


def main(cases: int = 40):
    from cmdlab import CommandLab
    from lineup import sort_items
    rng = random.Random(13)
    good = total = 0
    for case in range(cases):
        items = random_case(rng)
        lab = CommandLab(items)
        base = lab.run([], digits=None).items
        k = next(i for i, it in enumerate(base, 1) if it[0] == 5)
        for word in ("CV", "CNL", "CNR"):
            model = [list(it) for it in base]
            try:
                SlurCommand(model, k, word).run()
            except ValueError:
                continue
            engine = lab.run([f"I {k}", word, "X"], digits=None).items
            total += 1
            if model == engine:
                good += 1
            else:
                print(f"case {case} {word}: slur {base[k - 1]}")
                print("   model ", model[k - 1], "\n   engine", engine[k - 1])
    print(f"{good}/{total} identical")


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
