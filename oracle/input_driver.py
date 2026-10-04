"""Run SCORE's staged music input (the IN command and its five passes) through the emulated engine.

    input_driver.py CASE_DIR ...                 reads CASE_DIR/input.txt, writes result.mus and transcript.txt
    input_driver.py --corpus FILE OUT [REGEX]    writes every "== name" block of FILE to OUT/name/input.txt
                                                 and runs it (only names matching REGEX, if given)

input.txt uses the layout of SCORE's own input files (INPUT.TMP, READ files):

    IN 1                 the IN command line
    2 200                input range (begin, end); ";" or an empty line keeps the dialog default
    C4/D/E/F;            pass 1, notes
    4/4/4/4;             pass 2, rhythms
    ;                    pass 3, marks
    ;                    pass 4, beams
    ;                    pass 5, slurs

A pass ends at its first ";" and may span several lines, which are joined. Each pass is typed
key by key, as a user types into the view. (Enter is not typed: pass 1 ignores it, but in
pass 2 it submits the line.)

A case may hold several such blocks, run one after the other in the same score, and between
them lines starting with "!" that are sent as plain commands (e.g. "!SP 1" sets the spacing
staff).
"""
from __future__ import annotations

import functools
import re
import shutil
import struct
import sys
import tempfile
from concurrent.futures import ProcessPoolExecutor
from dataclasses import dataclass, field
from pathlib import Path

from callbacks import COMMAND, WaitingForInput
from emu import Engine
from sandbox import make_sandbox

READ_LINE = 0x597120          # C++: wait for a typed command string or a keystroke
RANGE_DIALOG = 0x599FD0       # C++: input range / spacing staff dialog, edits 8 ints at arg0
KEY_PRESSED, KEY_CODE, MOUSE_EVENT = 0x9C6C5D, 0x9C48F4, 0x9A9488
ENTER = 13
PASS_COUNT = 5
INSTRUCTION_LIMIT = 300_000_000       # a normal IN takes well under a tenth of this

# Fields of the range dialog's record (0x2091C40), as far as established.
RANGE_BEGIN, RANGE_END = 4, 5
IDOK = 1


@dataclass(frozen=True)
class InputJob:
    command: str
    passes: tuple[str, ...]
    input_range: tuple[float, float] | None = None

    @classmethod
    def parse(cls, text: str) -> "InputJob":
        command, range_line, rest = (text.replace("\r\n", "\n").split("\n", 2) + ["", ""])[:3]
        passes = tuple(p.strip("\n") + ";" for p in rest.split(";")[:PASS_COUNT])
        if len(passes) < PASS_COUNT:
            raise ValueError(f"expected {PASS_COUNT} passes ending in ';', found {len(passes)}")
        return cls(command.strip(), passes, parse_range(range_line))

    def keystrokes(self) -> list[int]:
        typed = "".join(self.passes).replace("\n", "")
        return [*typed.encode("latin-1"), ord("X")]


@dataclass(frozen=True)
class InputScript:
    """Input blocks and plain commands, in order."""
    steps: tuple[InputJob | str, ...]

    @classmethod
    def parse(cls, text: str) -> "InputScript":
        steps: list[InputJob | str] = []
        rest = text.replace("\r\n", "\n").strip("\n")
        while rest.strip():
            first, _, tail = rest.partition("\n")
            if first.startswith("!"):
                steps.append(first[1:].strip())
                rest = tail
                continue
            range_line, _, body = tail.partition("\n")
            pieces = body.split(";")
            if len(pieces) <= PASS_COUNT:
                raise ValueError(f"expected {PASS_COUNT} passes ending in ';' after {first!r}")
            passes = tuple(p.strip("\n") + ";" for p in pieces[:PASS_COUNT])
            steps.append(InputJob(first.strip(), passes, parse_range(range_line)))
            rest = ";".join(pieces[PASS_COUNT:]).lstrip("\n")
        return cls(tuple(steps))


def parse_range(line: str) -> tuple[float, float] | None:
    fields = line.replace(",", " ").split()
    if not fields or fields == [";"]:
        return None
    begin, end = (float(f) for f in fields[:2])
    return begin, end


@dataclass
class InputEngine(Engine):
    """The emulated engine with a keyboard that types a job's passes and fills its range dialog."""
    keys: list[int] = field(default_factory=list)
    input_range: tuple[float, float] | None = None
    range_record: tuple[int, ...] = ()

    def call(self, func, *args, limit=0):
        """As Engine.call, but an input the engine loops on fails instead of hanging."""
        return super().call(func, *args, limit=limit or INSTRUCTION_LIMIT)

    def _on_cpp(self, uc, address, size, user):
        handler = {READ_LINE: self._read_line, RANGE_DIALOG: self._range_dialog}.get(address)
        if handler is None:
            return super()._on_cpp(uc, address, size, user)
        self.current_callback = address
        try:
            result = handler()
        except WaitingForInput as wait:
            self._stop(f"engine waits for input: {wait}")
            return
        self.return_from_call(result, 0)

    def _read_line(self) -> int:
        """0x597120 for a keystroke: the character goes to arg0[0] and to KEY_CODE; returns arg2."""
        if not self.keys:
            self.shell.record("prompt-unanswered", self.shell.window_text[-80:])
            raise WaitingForInput("keystroke")
        key = self.keys.pop(0)
        self.put32(MOUSE_EVENT, 0)
        self.uc.mem_write(self.arg(0), bytes([key]))
        self.uc.mem_write(KEY_PRESSED, bytes([key]))
        self.put32(KEY_CODE, key)
        return self.arg(2)

    def _range_dialog(self) -> int:
        record = self.arg(0)
        values = list(struct.unpack("<8i", self.uc.mem_read(record, 32)))
        self.shell.record("range-dialog", f"record {values}")
        self.range_record = tuple(values)
        if self.input_range is None:
            return IDOK
        values[RANGE_BEGIN], values[RANGE_END] = (round(v) for v in self.input_range)
        self.uc.mem_write(record, struct.pack("<8i", *values))
        return IDOK


@dataclass
class InputResult:
    mus: bytes
    transcript: list[str]


@functools.cache
def process_sandbox() -> tempfile.TemporaryDirectory:
    """One sandbox per process, reused by its jobs: a copy of the install is 26 MB."""
    return tempfile.TemporaryDirectory(prefix="wscore-input-")


def run_job(job: InputJob, root: Path | None = None) -> InputResult:
    """Type the job into a fresh engine, save the score, and return the saved file."""
    return run_script(InputScript((job,)), root)


def run_script(script: InputScript, root: Path | None = None) -> InputResult:
    """Run the script's blocks and commands in a fresh engine, save the score, return the file."""
    sandbox = make_sandbox(root or Path(process_sandbox().name))
    engine = InputEngine(sandbox)
    engine.initialize()
    target = sandbox / "cwd" / "RESULT.MUS"
    target.unlink(missing_ok=True)
    shutil.rmtree(sandbox / "cwd" / "!tmp", ignore_errors=True)      # motives of earlier jobs
    for step in script.steps:
        if isinstance(step, str):
            engine.command(step)
            continue
        engine.keys = step.keystrokes()
        engine.input_range = step.input_range
        engine.command(step.command)
    engine.command("SA result.mus")
    quiet = ("service", "redraw", "text")       # text events echo every keystroke
    transcript = [f"{ev.kind}: {ev.detail}" for ev in engine.shell.events if ev.kind not in quiet]
    if engine.keys:
        transcript.append(f"unused keystrokes: {bytes(engine.keys)!r}")
    return InputResult(target.read_bytes(), transcript)


def read_items(mus: bytes) -> list[list[float]]:
    """Item parameter lists of a .mus file (P1 first); text characters are not decoded."""
    (count,) = struct.unpack_from("<H", mus)
    offset = 2 if 2 + 4 * count == len(mus) else 4
    words = mus[offset:]
    floats = struct.unpack(f"<{len(words) // 4}f", words)
    trailer = int(floats[-2]) + 1
    body, items, i = floats[:-trailer], [], 0
    while i < len(body):
        length = int(body[i])
        items.append(list(body[i + 1:i + 1 + length]))
        i += 1 + length
    return items


def run_case(case_dir: Path) -> InputResult:
    script = InputScript.parse((case_dir / "input.txt").read_text(encoding="latin-1"))
    result = run_script(script)
    (case_dir / "result.mus").write_bytes(result.mus)
    (case_dir / "transcript.txt").write_text("\n".join(result.transcript) + "\n", encoding="latin-1")
    return result


def format_items(items: list[list[float]]) -> str:
    return "\n".join(" ".join(f"{p:g}" for p in item) for item in items)


def corpus_cases(text: str) -> dict[str, str]:
    """The "== name" blocks of a corpus file, each an input.txt body."""
    blocks = re.split(r"^== ", text, flags=re.M)[1:]
    return {name.strip(): body.strip("\n") + "\n" for name, _, body in (b.partition("\n") for b in blocks)}


def write_corpus(corpus: Path, out: Path, pattern: str = "") -> list[Path]:
    cases = {n: body for n, body in corpus_cases(corpus.read_text(encoding="latin-1")).items() if re.search(pattern, n)}
    dirs = []
    for name, body in cases.items():
        case_dir = out / name
        case_dir.mkdir(parents=True, exist_ok=True)
        (case_dir / "input.txt").write_text(body, encoding="latin-1")
        dirs.append(case_dir)
    return dirs


def report(case_dir: Path) -> str:
    try:
        return f"== {case_dir.name}\n{format_items(read_items(run_case(case_dir).mus))}"
    except Exception as err:
        return f"== {case_dir.name}\nFAILED: {err!r}"


if __name__ == "__main__":
    args = sys.argv[1:]
    dirs = write_corpus(Path(args[1]), Path(args[2]), *args[3:4]) if args[:1] == ["--corpus"] else [Path(a) for a in args]
    with ProcessPoolExecutor(max_workers=6) as pool:
        for text in pool.map(report, dirs):
            print(text)
