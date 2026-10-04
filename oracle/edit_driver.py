"""Send SCORE edit commands to the emulated engine and record the items it ends up with.

    edit_driver.py CASES EXPECTED [REGEX]   run the cases of CASES (only names matching REGEX),
                                            write their results to EXPECTED (other blocks are kept)
    edit_driver.py --show CASES NAME        run one case, print every command's status and message

CASES (rust/crates/score-edit/tests/engine_cases.txt) holds blocks like

    == flip_stem_up
    base: 8 1; 1 1 100 6 10 0 1      the starting score, items separated by ';' (optional)
    I 2                              command lines, typed one after the other
    FLI
    X

Without a base line the score is a staff and a quarter note: "8 1; 1 1 100 6 10 0 1".
If the engine is still in edit mode after the last command, X is sent before saving.

EXPECTED gets one block per case: the items of the saved score, one per line. Values are
printed with 9 significant digits, so every f32 reads back exactly; text items end with
their characters in quotes. Lines starting with '#' carry the engine's messages and are
for the reader only.
"""
from __future__ import annotations

import re
import shutil
import struct
import sys
import tempfile
from concurrent.futures import ProcessPoolExecutor
from dataclasses import dataclass, field
from pathlib import Path

from emu import Engine
from musbuild import mus_bytes
from sandbox import INSTALL

DEFAULT_BASE = "8 1; 1 1 100 6 10 0 1"
ENGINE_DATA = ("scorlib", "fontlib")
EDIT_MODE = -1
TEXT_CODE, TEXT_LENGTH_PARAM = 16, 12
REPORTED_EVENTS = ("message", "prompt-unanswered", "dialog")


@dataclass(frozen=True)
class Case:
    name: str
    base: tuple[tuple[float, ...], ...]
    commands: tuple[str, ...]


@dataclass
class Outcome:
    items: list[str]
    transcript: list[str] = field(default_factory=list)


def parse_base(line: str) -> tuple[tuple[float, ...], ...]:
    return tuple(tuple(float(v) for v in item.split()) for item in line.split(";") if item.strip())


def parse_cases(text: str) -> list[Case]:
    cases = []
    for block in re.split(r"^== ", text, flags=re.M)[1:]:
        name, *lines = block.rstrip("\n").split("\n")
        base = next((line[5:] for line in lines if line.startswith("base:")), DEFAULT_BASE)
        commands = tuple(line for line in lines if not line.startswith(("base:", "#")) and line.strip())
        cases.append(Case(name.strip(), parse_base(base), commands))
    return cases


def lean_sandbox(root: Path) -> Path:
    """The engine's view of C:\\winscore needs only the data folders; the program runs from the original."""
    for folder in ENGINE_DATA:
        shutil.copytree(INSTALL / folder, root / "winscore" / folder)
    (root / "cwd").mkdir()
    (root / "c" / "!tmp").mkdir(parents=True)
    return root


def word_float(word: int) -> float:
    return struct.unpack("<f", struct.pack("<I", word))[0]


def item_words(mus: bytes) -> list[tuple[int, ...]]:
    """Each item's words as raw u32 bits (P1 first)."""
    (count,) = struct.unpack_from("<H", mus)
    offset = 2 if 2 + 4 * count == len(mus) else 4
    words = struct.unpack(f"<{(len(mus) - offset) // 4}I", mus[offset:])
    trailer = int(word_float(words[-2])) + 1
    body, items, i = words[:-trailer], [], 0
    while i < len(body):
        length = int(word_float(body[i]))
        items.append(body[i + 1:i + 1 + length])
        i += 1 + length
    return items


def format_item(words: tuple[int, ...]) -> str:
    floats = [word_float(w) for w in words]
    text = ""
    if floats and int(floats[0]) == TEXT_CODE and len(floats) >= TEXT_LENGTH_PARAM:
        chars = max(int(floats[TEXT_LENGTH_PARAM - 1]), 0)
        split = len(words) - (chars + 3) // 4
        raw = b"".join(struct.pack("<I", w) for w in words[split:])[:chars]
        floats, text = floats[:split], ' "' + raw.decode("latin-1") + '"'
    return " ".join(f"{v:.9g}" for v in floats) + text


def run_case(case: Case) -> Outcome:
    with tempfile.TemporaryDirectory(prefix="wscore-edit-") as tmp:
        root = lean_sandbox(Path(tmp))
        (root / "cwd" / "BASE.MUS").write_bytes(mus_bytes([list(item) for item in case.base]))
        engine = Engine(root)
        engine.initialize()
        engine.command("G base.mus")
        transcript, status = [], 0
        for command in case.commands:
            result = engine.command(command)
            status = result.status
            transcript.append(f"[{command}] status {status}: {result.message[:100]}")
        if status == EDIT_MODE:
            engine.command("X")
        engine.command("SA result.mus")
        saved = root / "cwd" / "RESULT.MUS"
        if not saved.exists():
            raise RuntimeError("the engine did not save the score")
        events = [f"{ev.kind}: {ev.detail.strip()[:120]}" for ev in engine.shell.events if ev.kind in REPORTED_EVENTS]
        return Outcome([format_item(words) for words in item_words(saved.read_bytes())], transcript + events)


def report(case: Case) -> str:
    try:
        outcome = run_case(case)
    except Exception as err:
        return f"== {case.name}\n# FAILED: {err!r}\n"
    notes = [f"# {line}" for line in outcome.transcript if not line.startswith("[")]
    return "\n".join([f"== {case.name}", *notes, *outcome.items]) + "\n"


def blocks(text: str) -> dict[str, str]:
    return {b.split("\n", 1)[0].strip(): "== " + b for b in re.split(r"^== ", text, flags=re.M)[1:]}


def update(cases_path: Path, expected_path: Path, pattern: str = "") -> None:
    cases = [c for c in parse_cases(cases_path.read_text(encoding="latin-1")) if re.search(pattern, c.name)]
    old = blocks(expected_path.read_text(encoding="latin-1")) if expected_path.exists() else {}
    with ProcessPoolExecutor() as pool:
        fresh = dict(zip((c.name for c in cases), pool.map(report, cases)))
    order = [c.name for c in parse_cases(cases_path.read_text(encoding="latin-1"))]
    merged = [fresh.get(name) or old.get(name) for name in order]
    expected_path.write_text("".join(b for b in merged if b), encoding="latin-1")
    failed = [name for name, block in fresh.items() if "# FAILED" in block]
    print(f"{len(fresh)} cases run, {len(failed)} failed {failed if failed else ''}".rstrip())


def show(cases_path: Path, name: str) -> None:
    case = next(c for c in parse_cases(cases_path.read_text(encoding="latin-1")) if c.name == name)
    outcome = run_case(case)
    print("\n".join(outcome.transcript + outcome.items))


if __name__ == "__main__":
    args = sys.argv[1:]
    if args[:1] == ["--show"]:
        show(Path(args[1]), args[2])
    else:
        update(Path(args[0]), Path(args[1]), *args[2:3])
