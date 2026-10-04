"""Random input lines for differential tests of score-input against the emulated engine.

    input_random.py SEED COUNT OUT_FILE      writes COUNT cases ("== rnd-SEED-i" blocks) to OUT_FILE

The cases use the documented syntax only and are built so that the engine accepts them
(rhythm counts match, note numbers exist). Run them with
`input_driver.py --corpus OUT_FILE DIR` and compare with score-input's fixture test.
"""
from __future__ import annotations

import random
import sys
from dataclasses import dataclass

LETTERS = "CDEFGAB"
ACCIDENTALS = ["", "", "", "", "S", "F", "N"]
RHYTHMS = ["4", "8", "8", "16", "2", "4.", "8.", "12", "1", "Q", "E", "S", "H", "T", "24", "32"]
MARKS = ["A", "S", "T", "W", "WS", "AS", "TS", "ACT", "FE", "TR", "-A", "-S", "D", "U", "HW", "F2"]
CLEFS = ["TR", "BA", "AL", "TE"]


@dataclass
class Line:
    notes: list[str]
    rhythms: list[str]
    note_count: int
    tails: list[int]


def tails_of(rhythm: str) -> int:
    value = {"Q": 4, "E": 8, "S": 16, "H": 2, "T": 12}.get(rhythm.rstrip("."), None)
    if value is None:
        value = float(rhythm.rstrip("."))
    if value >= 8:
        import math
        return int(math.log2(value)) - 2
    return 0


def pitch(rng: random.Random, octave_given: bool) -> str:
    name = rng.choice(LETTERS) + rng.choice(ACCIDENTALS)
    return name + (str(rng.randint(3, 5)) if octave_given else "")


def make_line(rng: random.Random) -> Line:
    notes, rhythms, tails = [], [], []
    if rng.random() < 0.5:
        notes.append(rng.choice(CLEFS))
    if rng.random() < 0.4:
        notes.append(f"K{rng.randint(1, 5)}{rng.choice('SF')}")
    if rng.random() < 0.4:
        notes.append(rng.choice(["3 4", "4 4", "6 8", "COM", "2 2"]))
    count = rng.randint(3, 14)
    first = True
    for _ in range(count):
        if rng.random() < 0.12:
            notes.append(rng.choice(["R", "R", "RU", "RD"]))
            rhythms.append(rng.choice(["4", "8", "2"]))
            continue
        heads = [pitch(rng, first or rng.random() < 0.3)]
        first = False
        if rng.random() < 0.25:
            heads += [pitch(rng, False) for _ in range(rng.randint(1, 2))]
        notes.append(":".join(heads))
        rhythm = rng.choice(RHYTHMS)
        rhythms.append(rhythm)
        tails.append(tails_of(rhythm))
        if rng.random() < 0.15:
            notes.append("M")
    return Line(notes, rhythms, len(tails), tails)


def marks_for(rng: random.Random, line: Line) -> list[str]:
    n = line.note_count
    marks = []
    for _ in range(rng.randint(0, 3)):
        a = rng.randint(1, n)
        b = rng.randint(a, min(n, a + 3))
        marks.append(f"{rng.choice(MARKS)} {a}" + (f":{b}" if b > a else ""))
    return marks


def beams_for(rng: random.Random, line: Line) -> list[str]:
    n = line.note_count
    runs, i = [], 0
    while i < n:
        j = i
        while j + 1 < n and line.tails[j + 1] > 0 and line.tails[i] > 0:
            j += 1
        if j > i and rng.random() < 0.7:
            sign = rng.choice(["", "", "", "+", "-"])
            runs.append(f"{sign}{i + 1} {j + 1}")
        i = j + 1
    return runs


def slurs_for(rng: random.Random, line: Line) -> list[str]:
    n = line.note_count
    slurs = []
    for _ in range(rng.randint(0, 2)):
        if n < 2:
            break
        a = rng.randint(1, n - 1)
        b = rng.randint(a + 1, min(n, a + 5))
        sign = rng.choice(["", "", "", "+", "-"])
        slurs.append(f"{sign}{a} {b}")
    return slurs


def case(rng: random.Random, name: str) -> str:
    line = make_line(rng)
    marks, beams, slurs = marks_for(rng, line), beams_for(rng, line), slurs_for(rng, line)
    rng_range = rng.choice([";", ";", "10 190", "2 150", "30 200"])
    return "\n".join([
        f"== {name}", "IN 1", rng_range,
        "/".join(line.notes) + ";",
        "/".join(line.rhythms) + ";",
        "/".join(marks) + ";",
        "/".join(beams) + ";",
        "/".join(slurs) + ";",
    ]) + "\n"


if __name__ == "__main__":
    seed, count, out = int(sys.argv[1]), int(sys.argv[2]), sys.argv[3]
    rng = random.Random(seed)
    with open(out, "w") as f:
        f.write("".join(case(rng, f"rnd-{seed}-{i}") for i in range(count)))
