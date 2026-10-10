"""Random input lines for differential tests of score-input against the emulated engine.

    input_random.py SEED COUNT OUT_FILE      writes COUNT cases ("== rnd-SEED-i" blocks) to OUT_FILE

The cases use the syntax of the engine's grammar (analysis/engine/input.md) and are built so
that the engine accepts them (rhythm counts match, note numbers exist). Run them with
`input_driver.py --corpus OUT_FILE DIR` and compare with score-input's fixture test
(`INPUT_FIXTURES=DIR cargo test -p score-input --test fixtures`).
"""
from __future__ import annotations

import math
import random
import sys
from dataclasses import dataclass, field

LETTERS = "CDEFGAB"
ACCIDENTALS = ["", "", "", "", "S", "F", "N"]
RHYTHMS = ["4", "8", "8", "16", "2", "4.", "8.", "12", "1", "Q", "E", "S", "H", "T", "24", "32", "8..", "G"]
HEAD_MARKS = ["A", "S", "T", "W", "WS", "AS", "TS", "ACT", "FE", "TR", "-A", "-S", "D", "U", "HW", "F2", "M", "PL"]
OTHER_MARKS = ["AO", "PZ", "RI", "CR", "TM", "TME", "-AO"]
LINE_MARKS = ["TRW", "C", "C-", "O", "OB"]
CLEFS = ["TR", "BA", "AL", "TE"]
BARS = ["M", "M", "M", "MD", "MH", "ML", "MR", "MRD", "MS", "MI"]
RESTS = ["R", "R", "RU", "RD", "RI", "RF"]
MEASURE_RESTS = ["RW", "RP", "R2", "R3", "R5", "R12"]
METERS = ["3 4", "4 4", "6 8", "COM", "CUT", "2 2", "12 8"]


@dataclass
class Line:
    notes: list[str] = field(default_factory=list)
    rhythms: list[str] = field(default_factory=list)
    tails: list[int] = field(default_factory=list)       # per note (chord), 0 for grace notes

    @property
    def note_count(self) -> int:
        return len(self.tails)


def tails_of(rhythm: str) -> int:
    if rhythm == "G":
        return 0
    value = {"Q": 4, "E": 8, "S": 16, "H": 2, "T": 12}.get(rhythm.rstrip("."))
    value = value if value is not None else float(rhythm.rstrip("."))
    return int(math.log2(value)) - 2 if value >= 8 else 0


def accidental(rng: random.Random, letter: str) -> str:
    roll = rng.random()
    if roll < 0.08:
        return "(" + rng.choice(["S", "F", "N", "SS", "FF"])
    if roll < 0.14:
        return letter * rng.randint(1, 3)
    return rng.choice(ACCIDENTALS)


def pitch(rng: random.Random, with_octave: bool, dyad: bool = False) -> str:
    letter = rng.choice(LETTERS)
    name = letter + accidental(rng, letter)
    if with_octave:
        name += str(rng.randint(3, 5))
    elif rng.random() < 0.15:
        name += rng.choice("UJ")
    if dyad and rng.random() < 0.08:
        name += rng.choice("+-")
    return name


def make_line(rng: random.Random) -> Line:
    line = Line()
    if rng.random() < 0.5:
        line.notes.append(rng.choice(CLEFS))
    if rng.random() < 0.4:
        line.notes.append(f"K{rng.randint(1, 6)}{rng.choice('SF')}" + ("N" if rng.random() < 0.1 else ""))
    if rng.random() < 0.4:
        line.notes.append(rng.choice(METERS))
    if rng.random() < 0.1:
        line.notes.append("-" + rng.choice(CLEFS))
    first = True
    previous = None
    for _ in range(rng.randint(3, 16)):
        roll = rng.random()
        if roll < 0.10:
            line.notes.append(rng.choice(RESTS))
            line.rhythms.append(rng.choice(["4", "8", "2", "16", "4."]))
            continue
        if roll < 0.12:
            line.notes.append(rng.choice(MEASURE_RESTS))
            line.rhythms.append(rng.choice(["1", "2.", "W"]))
            continue
        if roll < 0.16:
            line.notes.append(rng.choice(["SU", "SD", "SO", "Q+", "Q-", "Q0", "S+", "S-", "S0"]))
            continue
        if roll < 0.19 and not first:
            line.notes.append(("-" if rng.random() < 0.2 else "") + rng.choice(CLEFS))
            continue
        rhythm = rng.choice(RHYTHMS)
        if previous and rng.random() < 0.12:
            heads = previous                     # same notes again: a tie candidate
            line.notes.append(rng.choice([":".join(heads), ".", ".."]) if rhythm != "G" else ":".join(heads))
        else:
            mode = rng.choice(["", "", "", "", "O", "P"])
            # The engine never returns from a grace chord with two heads on one letter.
            heads = [mode + pitch(rng, first or rng.random() < 0.3, dyad=rhythm != "G")]
            if rng.random() < 0.25:
                heads += [pitch(rng, False, dyad=rhythm != "G") for _ in range(rng.randint(1, 3))]
            if rhythm == "G":
                heads = list({h.lstrip("OP")[0]: h for h in heads}.values())
            line.notes.append(":".join(heads))
        first = False
        previous = heads
        line.rhythms.append(rhythm)
        line.tails.append(tails_of(rhythm))
        if rng.random() < 0.12:
            line.notes.append(rng.choice(BARS) + ("2" if rng.random() < 0.15 else ""))
    if line.note_count == 0:
        line.notes.append("C4")
        line.rhythms.append("4")
        line.tails.append(0)
    return line


def marks_for(rng: random.Random, line: Line) -> list[str]:
    n = line.note_count
    marks = []
    for _ in range(rng.randint(0, 4)):
        a = rng.randint(1, n)
        roll = rng.random()
        if roll < 0.6:
            b = rng.randint(a, min(n, a + 3))
            marks.append(f"{rng.choice(HEAD_MARKS)} {a}" + (f":{b}" if b > a else ""))
        elif roll < 0.85:
            marks.append(f"{rng.choice(OTHER_MARKS)} {a}")
        elif n >= 2:
            b = rng.randint(a, n)
            frac = rng.choice(["", "", ".5", ".25"])
            marks.append(f"{rng.choice(LINE_MARKS)} {a}{frac if a < n else ''} {b}")
    return marks


def beams_for(rng: random.Random, line: Line) -> list[str]:
    n = line.note_count
    if rng.random() < 0.15:
        return [f"{rng.choice([2, 3, 4])}B" + (str(rng.randint(1, 2)) if rng.random() < 0.2 else "")]
    runs, i = [], 0
    while i < n:
        j = i
        while j + 1 < n and line.tails[j + 1] > 0 and line.tails[i] > 0:
            j += 1
        if j > i and rng.random() < 0.7:
            sign = rng.choice(["", "", "", "+", "-"])
            tuplet = "3" if rng.random() < 0.1 else ""
            runs.append(f"{sign}{tuplet}{i + 1:0{2 if tuplet else 1}d} {j + 1}")
        i = j + 1
    return runs


def slurs_for(rng: random.Random, line: Line) -> list[str]:
    n = line.note_count
    slurs = []
    for _ in range(rng.randint(0, 3)):
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
    command = rng.choice(["IN 1", "IN 1", "IN 1", "IN 1 0 0 .8", "IN 1 0 0 1.2", "IN 1 0 0 0 180"])
    rng_range = rng.choice([";", ";", "10 190", "2 150", "30 200"])
    return "\n".join([
        f"== {name}", command, rng_range,
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
