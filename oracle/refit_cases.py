"""Random staves for checking score-input's refit (0x47C3E8, run by FLI/FLN/FLU/FLD and by TR's
stem option) against the emulated engine.

    refit_cases.py make SEED COUNT CASES [COMMAND]   append COUNT random cases to CASES
    refit_cases.py run CASES EXPECTED [REGEX]       run them through the engine (4 jobs)

A staff has notes and two-note chords with stems, accidentals, dots and marks, beams over
eighths and sixteenths, and slurs. A case types the group command and the area answer
"staff left right"; "Source Box O.K.?" is answered yes.
"""
from __future__ import annotations

import random
import sys
from pathlib import Path

from layout_cases import run

COMMANDS = ("FLI", "FLN", "FLU", "FLD")
MARKS = [0, 0, 0, 0, 5, 6, 7, 4, 10, -7, -5]


def value(v: float) -> str:
    return f"{v:g}"


def note(rng: random.Random, x: float, level: int, duration: float, tails: int, dots: int) -> list[float]:
    accidental = rng.choice([0, 0, 0, 0, 1, 2, 3])
    stem = 20 if level >= 7 else 10
    mark = rng.choice(MARKS)
    item = [1, 1, round(x, 2), level, stem + accidental, 0, duration, 0, dots * 10 + tails, 0, mark]
    while len(item) > 7 and item[-1] == 0:
        item.pop()
    return item


def staff(rng: random.Random) -> tuple[list[list[float]], float]:
    items = [[8, 1, 0, 0, 1], [3, 1, 2, 0, 0]]
    x, notes = 10.0, []
    run_start = None
    for _ in range(rng.randint(4, 12)):
        kind = rng.random()
        if kind < 0.5:
            duration, tails, dots = rng.choice([(0.5, 1, 0), (0.25, 2, 0), (0.75, 1, 1), (0.5, 1, 0)])
        else:
            duration, tails, dots = rng.choice([(1, 0, 0), (2, 0, 0), (1.5, 0, 1)])
        level = rng.randint(-1, 13)
        head = note(rng, x, level, duration, tails, dots)
        items.append(head)
        if rng.random() < 0.25:
            second = level + rng.choice([2, 3, 4, -2, -3])
            items.append([1, 1, round(x, 2), second, rng.choice([0, 0, 1, 3]), 0, duration, 0, dots * 10])
        notes.append((x, tails))
        x += rng.uniform(8, 16)
    end = round(x, 2)
    items.append([14, 1, min(end + 5, 200), 1])
    beams, slurs = [], []
    k = 0
    while k < len(notes) - 1:
        if notes[k][1] and notes[k + 1][1] and rng.random() < 0.6:
            j = k + 1
            while j + 1 < len(notes) and notes[j + 1][1] and rng.random() < 0.5:
                j += 1
            beams.append([6, 1, round(notes[k][0], 2), 8, 9, round(notes[j][0], 2), 11])
            k = j + 1
        else:
            k += 1
    for _ in range(rng.randint(0, 2)):
        a = rng.randrange(len(notes) - 1)
        b = rng.randint(a + 1, min(len(notes) - 1, a + 3))
        slurs.append([5, 1, round(notes[a][0], 2), 12, 12, round(notes[b][0], 2), 2, -1])
    return items + beams + slurs, end


def make(seed: int, count: int, cases_path: Path, command: str) -> None:
    rng = random.Random(seed)
    out = []
    for i in range(count):
        items, end = staff(rng)
        base = "; ".join(" ".join(value(v) for v in it) for it in items)
        cmd = command if command != "any" else rng.choice(COMMANDS)
        out.append(f"== {cmd.lower()}-{seed}-{i}\nbase: {base}\n{cmd}\n1 0 {value(min(end + 1, 200))}\n")
    with cases_path.open("a", encoding="latin-1") as f:
        f.write("".join(out))


if __name__ == "__main__":
    args = sys.argv[1:]
    if args[0] == "make":
        make(int(args[1]), int(args[2]), Path(args[3]), args[4] if len(args) > 4 else "any")
    else:
        run(Path(args[1]), Path(args[2]), *args[3:4])
