"""Send SCORE edit commands to the emulated engine and record the items it ends up with.

    edit_driver.py CASES EXPECTED [REGEX]   run the cases of CASES (only names matching REGEX),
                                            write their results to EXPECTED (other blocks are kept)
    edit_driver.py --show CASES NAME        run one case, print every command's status and message

CASES (rust/crates/score-edit/tests/engine_cases.txt) holds blocks like

    == flip_stem_up
    base: 8 1; 1 1 100 6 10 0 1      the starting score, items separated by ';' (optional); a text
                                     item ends with its characters: 16 1 50 10 1 1 0 0 0 0 0 5 9 "_00Hi"
    I 2                              command lines, typed one after the other
    FLI
    X

Without a base line the score is a staff and a quarter note: "8 1; 1 1 100 6 10 0 1".
If the engine is still in edit mode after the last command, X is sent before saving.

Mouse actions are lines "~v X Y" (move with the button held), "~s X Y" (the same with
Shift), "~x X Y" (button up after a drag) and "~ X Y" (click), with X, Y in page
coordinates: engine units from the paper's bottom-left corner, y up, as score-render draws.
They are sent as the view does (analysis/engine/editing.md): the point goes to the engine's
mouse globals, converted with the engine's current VIEW_DX/VIEW_DY.

Lines starting with '!' are for the driver. "!transpose half=2 stems=1 clef=1 key=1 cue=1"
gives the values the Transpose Setup dialog returns when TR next opens it (half steps;
normalize stems; clef change, -1 none (the default), 0 treble, 1 bass, 2 alto, 3 tenor;
add a key signature; transpose cue notes). "!skip-lineup" makes the lineup pass of
LJ/LI/J, which TR runs at its end, return at once, so the rest can be checked on its own.

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

from unicorn import UC_HOOK_CODE

from emu import COMMAND, ENGINE_ZOOM, FLAG_9A9498, LINE_BUF, MESSAGE_BUF, TEXT_OUT, ZOOM, Engine, EngineResult
from musbuild import mus_bytes, text_item
from sandbox import INSTALL

DEFAULT_BASE = "8 1; 1 1 100 6 10 0 1"
MOUSE_X, MOUSE_Y = 0x1A14950, 0x1A1494C
MOUSE_UP_X, MOUSE_UP_Y = 0x1A14948, 0x1A14944
VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4
# score-render's page frame: internal coordinates plus the paper origin's offset.
PAGE_FROM_INTERNAL = (2000, 26948)
# Command and line buffer the view sends for each mouse action.
MOUSE_ACTIONS = {"~v": ("~v", "~v"), "~s": ("~s", "~s"), "~x": ("~x", "|"), "~": ("~", "~")}
ENGINE_DATA = ("scorlib", "fontlib")
EDIT_MODE = -1
TEXT_CODE, TEXT_LENGTH_PARAM = 16, 12
REPORTED_EVENTS = ("message", "prompt-unanswered", "dialog", "question")
# "Source Box O.K.?" and similar yes/no questions of group edits (disasm-expert): answered yes.
YES_NO_QUESTION = 0x595CD0
YES = 1


# The Transpose Setup dialog (0x599E90) edits 19 ints at its first argument; the fields
# found by experiment and in TR (0x55B1F8), as "!transpose half=2 clef=1" lines name them.
# A clef of -1 is the dialog's "No Clef Change".
TRANSPOSE_DIALOG = 0x599E90
TRANSPOSE_FIELDS = {"half": 10, "stems": 11, "clef": 13, "key": 14, "cue": 15}
TRANSPOSE_DEFAULTS = {"clef": -1}
# LJ/LI/J's pass (ret 0x10); TR ends with it on every staff.
LINEUP_PASS, LINEUP_ARG_BYTES = 0x4B80B7, 16


@dataclass
class EditEngine(Engine):
    """The emulated engine, answering yes to the questions group edits ask, filling
    the transpose dialog with the values of the last "!transpose" line and, after
    "!skip-lineup", returning at once from the lineup pass."""
    transpose: dict[int, int] = field(default_factory=dict)
    skip_lineup: bool = False

    def __post_init__(self):
        super().__post_init__()
        self.uc.hook_add(UC_HOOK_CODE, self._on_lineup, begin=LINEUP_PASS, end=LINEUP_PASS)

    def _on_lineup(self, uc, address, size, user):
        if self.skip_lineup:
            self.shell.record("dialog", "lineup pass skipped")
            self.return_from_call(0, LINEUP_ARG_BYTES)

    def _on_cpp(self, uc, address, size, user):
        if address == YES_NO_QUESTION:
            self.shell.record("question", f"{self.cstr(self.arg(0), 200).strip()} -> yes")
            self.return_from_call(YES, 0)
        elif address == TRANSPOSE_DIALOG:
            record = self.arg(0)
            for index, value in self.transpose.items():
                self.uc.mem_write(record + 4 * index, struct.pack("<i", value))
            self.shell.record("dialog", f"transpose {self.transpose}")
            self.return_from_call(YES, 0)
        else:
            super()._on_cpp(uc, address, size, user)


def directive(engine: EditEngine, line: str) -> bool:
    """A line for the driver rather than the engine: "!transpose half=2 clef=1" sets the
    values of the next transpose dialog, "!skip-lineup" turns the lineup pass off."""
    word, *rest = line.split() or [""]
    if word == "!transpose":
        values = TRANSPOSE_DEFAULTS | dict(pair.split("=") for pair in rest)
        engine.transpose = {TRANSPOSE_FIELDS[name]: int(value) for name, value in values.items()}
    elif word == "!skip-lineup":
        engine.skip_lineup = True
    else:
        return False
    return True


@dataclass(frozen=True)
class Case:
    name: str
    base: tuple[tuple[float, ...] | bytes, ...]
    commands: tuple[str, ...]


@dataclass
class Outcome:
    items: list[str]
    transcript: list[str] = field(default_factory=list)


def parse_item(text: str) -> tuple[float, ...] | bytes:
    """Numbers, or a text item's numbers followed by its characters in double quotes."""
    numbers, quote, characters = text.partition('"')
    params = tuple(float(v) for v in numbers.split())
    return text_item(list(params), characters.rstrip().removesuffix('"').encode("latin-1")) if quote else params


def parse_base(line: str) -> tuple[tuple[float, ...] | bytes, ...]:
    return tuple(parse_item(item) for item in line.split(";") if item.strip())


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


def engine_point(engine: Engine, page_x: float, page_y: float) -> tuple[int, int]:
    """A page point in the engine's output coordinates, as the view hands mouse points over."""
    return (round(page_x - PAGE_FROM_INTERNAL[0] + engine.i32(VIEW_DX)),
            round(page_y - PAGE_FROM_INTERNAL[1] - engine.i32(VIEW_DY)))


def mouse(engine: Engine, line: str) -> EngineResult | None:
    """A mouse line ("~v 17000 2773"; "~x X0 Y0 X1 Y1" for a box from mouse-down to mouse-up),
    sent like the view's mouse handlers; None for other lines."""
    action, *point = line.split()
    if action not in MOUSE_ACTIONS or len(point) not in (2, 4):
        return None
    numbers = [float(v) for v in point]
    x, y = engine_point(engine, *numbers[:2])
    engine.put32(MOUSE_X, x)
    engine.put32(MOUSE_Y, y)
    if len(numbers) == 4:
        up_x, up_y = engine_point(engine, *numbers[2:])
        engine.put32(MOUSE_UP_X, up_x)
        engine.put32(MOUSE_UP_Y, up_y)
    command, line_buffer = MOUSE_ACTIONS[action]
    engine.uc.mem_write(COMMAND, command.encode() + b"\0")
    engine.uc.mem_write(LINE_BUF, line_buffer.encode() + b"\0")
    engine.uc.mem_write(MESSAGE_BUF, b" " * 0x200)
    engine.put32(FLAG_9A9498, 0)
    engine.put32(ENGINE_ZOOM, engine.u32(ZOOM))
    return engine._interpret(TEXT_OUT)


def run_case(case: Case) -> Outcome:
    with tempfile.TemporaryDirectory(prefix="wscore-edit-") as tmp:
        root = lean_sandbox(Path(tmp))
        (root / "cwd" / "BASE.MUS").write_bytes(mus_bytes(list(case.base)))
        engine = EditEngine(root)
        engine.initialize()
        engine.command("G base.mus")
        transcript, status = [], 0
        for command in case.commands:
            if directive(engine, command):
                continue
            result = mouse(engine, command) or engine.command(command)
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
