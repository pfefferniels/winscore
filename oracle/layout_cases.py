"""Random systems for checking score-layout's LI/LJ/J against the emulated engine.

    layout_cases.py make SEED COUNT CASES [KIND [COMMAND]]
                                                   append COUNT random cases to CASES; KIND is
                                                   plain, rich, crowded, dense or grace,
                                                   COMMAND LI, J, LJ or LJA
    layout_cases.py run CASES EXPECTED [REGEX]     run the cases through the engine (4 jobs)

CASES uses edit_driver.py's format ("== name", a "base:" line with the items, then the
command lines, e.g. "LI" and "1 2"); EXPECTED gets the saved items of each case, as
edit_driver.py writes them. The engine's "Source Box O.K.?" is answered yes.
"""
from __future__ import annotations

import random
import re
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

from edit_driver import blocks, parse_cases, report

PARALLEL_JOBS = 4                     # team limit for concurrent oracle runs
DURATIONS = [0.25, 0.5, 0.5, 1, 1, 1, 1.5, 2]


def split_measure(rng: random.Random, length: float = 4.0) -> list[float]:
    out, left = [], length
    while left > 0:
        d = min(left, rng.choice(DURATIONS))
        out.append(d)
        left -= d
    return out


def plain_staff(rng: random.Random, staff: int, measures: list[list[float]]) -> list[list[float]]:
    """Notes, rests and two-note chords in measures, barlines between them and at 200."""
    items = [[8, staff, 0, 0, 1], [3, staff, 2, 0, 0]]
    x = 10.0
    for m, durations in enumerate(measures):
        for d in durations:
            rest = rng.random() < 0.15
            items.append([2 if rest else 1, staff, round(x, 2), rng.randint(1, 10), 0 if rest else 10, 0, d])
            if not rest and rng.random() < 0.2:
                items.append([1, staff, round(x, 2), rng.randint(1, 10), 10, 0, d])
            x += rng.uniform(4, 12)
        if m < len(measures) - 1:
            items.append([14, staff, round(x, 2), 1])
            x += rng.uniform(3, 6)
    items.append([14, staff, 200, 1])
    return items


def rich_staff(rng: random.Random, staff: int, measures: int) -> list[list[float]]:
    """Keys, meters, a second voice, barlines with P12, key changes, clefs inside the line,
    and items placed between notes (hairpins, slurs, beams, code 10)."""
    items = [[8, staff, 0, 0, 1], [3, staff, 2, 0, 0]]
    if rng.random() < 0.6:
        items.append([17, staff, 6, 0, rng.choice([-3, -1, 1, 2, 4])])
    if rng.random() < 0.6:
        items.append([18, staff, 9, 0, 4, 4])
    x0, note_x = 13.0, []
    for m in range(measures):
        width = rng.uniform(30, 55)
        onsets: dict[float, float] = {}
        voices = [split_measure(rng)] + ([split_measure(rng)] if rng.random() < 0.4 else [])
        for v, durations in enumerate(voices):
            t = 0.0
            for d in durations:
                x = onsets.setdefault(t, round(x0 + t / 4 * width + rng.uniform(0, 0.3), 2))
                rest = rng.random() < 0.1
                if v == 0 and not rest and rng.random() < 0.08:
                    items.append([3, staff, round(x - 3, 2), 0, 0])
                items.append([2 if rest else 1, staff, x, rng.randint(1, 10) - 6 * v, 0 if rest else 10, 0, d])
                note_x.append(x)
                t += d
        x0 += width + rng.uniform(3, 6)
        if m < measures - 1:
            bar = round(x0 - 2, 2)
            items.append([14, staff, bar, 1] + ([0] * 7 + [1] if rng.random() < 0.2 else []))
            if rng.random() < 0.15:
                items.append([17, staff, round(bar + 2, 2), 0, rng.choice([-2, 0, 3])])
                x0 += 4
    items.append([14, staff, 200, 1])
    note_x.sort()
    for _ in range(rng.randint(0, 3)):
        a, b = sorted(rng.sample(note_x, 2)) if len(note_x) > 1 else (note_x[0], note_x[0])
        kind = rng.choice([4, 5, 6, 10])
        items.append([10, staff, a, 12, 3] if kind == 10 else [kind, staff, a, 12, 11, b])
    return items


def crowded_staff(rng: random.Random, staff: int, measures: int) -> list[list[float]]:
    """Many short notes with accidentals, flags, dots and seconds in chords: lines where
    justification has to find room."""
    items = [[8, staff, 0, 0, 1], [3, staff, 2, 0, 0]]
    x = 10.0
    for m in range(measures):
        for d in split_measure(rng, 4.0):
            if d >= 1 and rng.random() < 0.5:
                d = rng.choice([0.25, 0.5])
            level = rng.randint(-2, 12)
            accidental = rng.choice([0, 0, 0, 1, 2, 3])
            tails = {0.25: 2, 0.5: 1}.get(d, 0)
            dots = 10 if rng.random() < 0.15 else 0
            items.append([1, staff, round(x, 2), level, (20 if level > 6 else 10) + accidental, 0, d, 0, tails + dots])
            if rng.random() < 0.3:
                second = level + rng.choice([1, -1, 2])
                items.append([1, staff, round(x, 2), second, rng.choice([0, 0, 1, 3]), 0, d, 0, dots, 10])
            x += rng.uniform(2, 6)
        if m < measures - 1:
            items.append([14, staff, round(x, 2), 1])
            x += rng.uniform(2, 4)
    items.append([14, staff, 200, 1])
    return items


def decorate(rng: random.Random, it: list[float]) -> list[float]:
    """Accidentals, dots, shifted heads and cue size on notes, P10 on rests, barline types."""
    it = list(it)
    if it[0] == 1:
        it = (it + [0.0] * 10)[:10]
        it[4] = rng.choice([1, 2]) * 10 + rng.choice([0, 0, 0, 1, 2, 3, 4, 5, 9])
        if rng.random() < 0.15:
            it[5] = rng.choice([1, 2, 3, 12])
        if rng.random() < 0.2:
            it[8] = rng.choice([1, 2, 11, 1.3])
        if rng.random() < 0.15:
            it[9] = rng.choice([10, 20, 110, -3, 4])
        if rng.random() < 0.05:
            it[3] += 100 if it[3] >= 0 else -100
        while it[-1] == 0 and len(it) > 7:
            it.pop()
    elif it[0] == 2 and rng.random() < 0.2:
        it = (it + [0.0] * 10)[:10]
        it[9] = rng.choice([2, -2])
    elif it[0] == 14 and it[2] < 200 and rng.random() < 0.2:
        it = (it + [0.0] * 5)[:5]
        it[4] = rng.choice([1, 2, 3, 4, 5, 6])
    return it


def dense_staff(rng: random.Random, staff: int, measures: int) -> list[list[float]]:
    items = [decorate(rng, it) for it in rich_staff(rng, staff, measures)]
    if rng.random() < 0.3:
        items.append([10, staff, round(rng.uniform(20, 180), 2), 12, 3] + [0] * 10 + [1])
    return items


def grace_staff(rng: random.Random, staff: int, measures: list[list[float]]) -> list[list[float]]:
    """plain_staff with groups of one to three grace notes (P7 65, P4 + 100, P8 101) before
    some notes."""
    items = []
    for it in plain_staff(rng, staff, measures):
        if it[0] == 1 and it[2] > 12 and rng.random() < 0.3 and not (items and items[-1][2] == it[2]):
            count = rng.randint(1, 3)
            items += [[1, staff, round(it[2] - 0.5 * (count - k), 2), rng.randint(1, 10) + 100, 10, 0, 65, 101] for k in range(count)]
        items.append(it)
    return items


KINDS = ("plain", "rich", "crowded", "dense", "grace")


def system(rng: random.Random, kind: str) -> tuple[list[list[float]], int]:
    staves = rng.randint(1, 3)
    measures = rng.randint(1, 3)
    if kind == "rich":
        items = [it for s in range(1, staves + 1) for it in rich_staff(rng, s, measures)]
    elif kind == "crowded":
        items = [it for s in range(1, staves + 1) for it in crowded_staff(rng, s, measures + 1)]
    elif kind == "dense":
        items = [it for s in range(1, staves + 1) for it in dense_staff(rng, s, measures + 2)]
    elif kind == "grace":
        shapes = [[split_measure(rng) for _ in range(measures)] for _ in range(staves)]
        items = [it for s in range(1, staves + 1) for it in grace_staff(rng, s, shapes[s - 1])]
    else:
        shapes = [[split_measure(rng) for _ in range(measures)] for _ in range(staves)]
        items = [it for s in range(1, staves + 1) for it in plain_staff(rng, s, shapes[s - 1])]
    return items, staves


def value(v: float) -> str:
    return f"{v:g}"


def make(seed: int, count: int, cases_path: Path, kind: str, command: str) -> None:
    rng = random.Random(seed)
    out = []
    for i in range(count):
        items, staves = system(rng, kind)
        base = "; ".join(" ".join(value(v) for v in it) for it in items)
        answer = "" if command == "LJA" else f"1 {staves}\n"
        out.append(f"== {command.lower()}-{kind}-{seed}-{i}\nbase: {base}\n{command}\n{answer}")
    with cases_path.open("a", encoding="latin-1") as f:
        f.write("".join(out))


def run(cases_path: Path, expected_path: Path, pattern: str = "") -> None:
    every = parse_cases(cases_path.read_text(encoding="latin-1"))
    cases = [c for c in every if re.search(pattern, c.name)]
    old = blocks(expected_path.read_text(encoding="latin-1")) if expected_path.exists() else {}
    with ProcessPoolExecutor(max_workers=PARALLEL_JOBS) as pool:
        fresh = dict(zip((c.name for c in cases), pool.map(report, cases)))
    merged = [fresh.get(c.name) or old.get(c.name) for c in every]
    expected_path.write_text("".join(b for b in merged if b), encoding="latin-1")
    failed = [name for name, block in fresh.items() if "# FAILED" in block]
    print(f"{len(fresh)} cases run, {len(failed)} failed {failed if failed else ''}".rstrip())


if __name__ == "__main__":
    args = sys.argv[1:]
    if args[0] == "make":
        kind = args[4] if len(args) > 4 else "plain"
        command = args[5] if len(args) > 5 else "LI"
        assert kind in KINDS and command in ("LI", "J", "LJ", "LJA"), f"kind: {'|'.join(KINDS)}, command: LI|J|LJ|LJA"
        make(int(args[1]), int(args[2]), Path(args[3]), kind, command)
    else:
        run(Path(args[1]), Path(args[2]), *args[3:4])
