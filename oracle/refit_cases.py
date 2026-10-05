"""Random staves for checking score-input's refit (0x47C3E8, run by FLI/FLN/FLU/FLD and by TR's
stem option) against the emulated engine.

    refit_cases.py make SEED COUNT CASES [COMMAND [KIND]]
                                                    append COUNT random cases to CASES; COMMAND
                                                    FLI/FLN/FLU/FLD or any, KIND plain/cue/two
    refit_cases.py fixtures SEED COUNT CASES DIR    append cases on the staves of COUNT IN
                                                    fixtures in DIR (rust/fixtures/input)
    refit_cases.py run CASES EXPECTED [REGEX]       run them through the engine (4 jobs)

A staff has notes and two-note chords with stems, accidentals, dots and marks, beams over
eighths and sixteenths, and slurs. A case types the group command and the area answer
"staff left right"; "Source Box O.K.?" is answered yes.
"""
from __future__ import annotations

import random
import sys
from pathlib import Path

from input_driver import read_items
from layout_cases import run

COMMANDS = ("FLI", "FLN", "FLU", "FLD")
MARKS = [0, 0, 0, 0, 5, 6, 7, 4, 10, -7, -5]


def value(v: float) -> str:
    return f"{v:g}"


def note(rng: random.Random, number: int, x: float, level: int, duration: float, tails: int, dots: int) -> list[float]:
    accidental = rng.choice([0, 0, 0, 0, 1, 2, 3])
    stem = 20 if level % 100 >= 7 else 10
    mark = rng.choice(MARKS)
    head = 2 if duration >= 4 else 1 if duration >= 2 else 0
    item = [1, number, round(x, 2), level, stem + accidental, head, duration, 0, dots * 10 + tails, 0, mark]
    while len(item) > 7 and item[-1] == 0:
        item.pop()
    return item


def staff(rng: random.Random, number: int = 1, cue: float = 0.0) -> tuple[list[list[float]], float]:
    """A staff of notes and chords (some whole-note chords, some cue-size runs when `cue`),
    with beams over flagged runs and slurs."""
    items = [[8, number, 0, 0, 1], [3, number, 2, 0, 0]]
    x, notes = 10.0, []
    small = False
    for _ in range(rng.randint(4, 12)):
        kind = rng.random()
        if kind < 0.5:
            duration, tails, dots = rng.choice([(0.5, 1, 0), (0.25, 2, 0), (0.75, 1, 1), (0.5, 1, 0)])
        elif kind < 0.9:
            duration, tails, dots = rng.choice([(1, 0, 0), (2, 0, 0), (1.5, 0, 1)])
        else:
            duration, tails, dots = 4, 0, 0
        if rng.random() < cue:
            small = not small
        level = rng.randint(-1, 13)
        offset = (100 if level >= 0 else -100) if small else 0
        head = note(rng, number, x, level + offset, duration, tails, dots)
        items.append(head)
        if rng.random() < 0.25:
            second = level + rng.choice([2, 3, 4, -2, -3])
            second += (100 if second >= 0 else -100) if small else 0
            items.append([1, number, round(x, 2), second, rng.choice([0, 0, 1, 3]), head[5], duration, 0, dots * 10])
        notes.append((x, tails))
        x += rng.uniform(8, 16)
    end = round(x, 2)
    items.append([14, number, min(end + 5, 200), 1])
    beams, slurs = [], []
    k = 0
    while k < len(notes) - 1:
        if notes[k][1] and notes[k + 1][1] and rng.random() < 0.6:
            j = k + 1
            while j + 1 < len(notes) and notes[j + 1][1] and rng.random() < 0.5:
                j += 1
            beams.append([6, number, round(notes[k][0], 2), 8, 9, round(notes[j][0], 2), 11])
            k = j + 1
        else:
            k += 1
    for _ in range(rng.randint(0, 2)):
        a = rng.randrange(len(notes) - 1)
        b = rng.randint(a + 1, min(len(notes) - 1, a + 3))
        slurs.append([5, number, round(notes[a][0], 2), 12, 12, round(notes[b][0], 2), 2, -1])
    return items + beams + slurs, end


def from_fixtures(seed: int, count: int, cases_path: Path, fixtures: Path) -> None:
    """Cases on the staves IN made for score-input's fixtures (beams with secondary items,
    chords, grace notes, ties, tremolos), each with a random command and area."""
    rng = random.Random(seed)
    dirs = sorted(d for d in fixtures.iterdir() if (d / "result.mus").exists())
    out = []
    for case in rng.sample(dirs, min(count, len(dirs))):
        items = read_items((case / "result.mus").read_bytes())
        if not items or any(int(it[0]) == 16 for it in items):
            continue
        base = "; ".join(" ".join(f"{v:.9g}" for v in it) for it in items)
        cmd = rng.choice(COMMANDS)
        area = "1 0 200" if rng.random() < 0.7 else f"1 {rng.randint(0, 60)} {rng.randint(100, 200)}"
        out.append(f"== {cmd.lower()}-{seed}-{case.name}\nbase: {base}\n{cmd}\n{area}\n")
    with cases_path.open("a", encoding="latin-1") as f:
        f.write("".join(out))


def make(seed: int, count: int, cases_path: Path, command: str, kind: str = "plain") -> None:
    """KIND plain: one staff; cue: one staff with cue-size runs; two: two staves in one area."""
    rng = random.Random(seed)
    out = []
    for i in range(count):
        if kind == "two":
            (first, end1), (second, end2) = staff(rng, 1), staff(rng, 2)
            items, end, area = first + second, max(end1, end2), "1 0 {} 2"
        else:
            items, end = staff(rng, 1, 0.3 if kind == "cue" else 0.0)
            area = "1 0 {}"
        base = "; ".join(" ".join(value(v) for v in it) for it in items)
        cmd = command if command != "any" else rng.choice(COMMANDS)
        answer = area.format(value(min(end + 1, 200)))
        out.append(f"== {cmd.lower()}-{kind}-{seed}-{i}\nbase: {base}\n{cmd}\n{answer}\n")
    with cases_path.open("a", encoding="latin-1") as f:
        f.write("".join(out))


if __name__ == "__main__":
    args = sys.argv[1:]
    if args[0] == "make":
        make(int(args[1]), int(args[2]), Path(args[3]), args[4] if len(args) > 4 else "any", args[5] if len(args) > 5 else "plain")
    elif args[0] == "fixtures":
        from_fixtures(int(args[1]), int(args[2]), Path(args[3]), Path(args[4]))
    else:
        run(Path(args[1]), Path(args[2]), *args[3:4])
