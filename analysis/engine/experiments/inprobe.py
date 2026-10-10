"""Staged input (IN) with the engine's intermediate state: each pass text as the parser 0x4AEFA0
receives it (after the key readers), the token list R that 0x4AF456 builds from it, the error
position the pass leaves, and the items saved at the end.

    python inprobe.py CORPUS [REGEX]

CORPUS is in the format of oracle/input_driver.py ("== name" blocks). At most four engines run
at once (team limit).
"""
from __future__ import annotations

import re
import struct
import sys
from concurrent.futures import ProcessPoolExecutor
from dataclasses import dataclass, field
from pathlib import Path

from unicorn import UC_HOOK_CODE

ORACLE = Path(__file__).resolve().parents[3] / "oracle"
sys.path.insert(0, str(ORACLE))

from input_driver import InputEngine, InputScript, corpus_cases, read_items, format_items  # noqa: E402
from sandbox import make_sandbox  # noqa: E402

INPUT_PASS = 0x4AEFA0
AFTER_TOKENS = 0x4AF2AF          # return address of the call to 0x4AF456
INPUT_PASS_RET = 0x4AF453
ITEM_ERROR = 0x5259E5            # the item parsers' rejection: marks the item, the reader then waits
PASS_NUMBER = 0x1FBB700
TEXT = 0x20B8EA0                 # character 1 of the pass text (the engine indexes 0x20B8E9F + i)
R_LIST = 0x1FB8CC0               # int count, then f32 values
ERROR = 0x2052754
PARALLEL_JOBS = 4


@dataclass
class PassRecord:
    number: int
    text: str
    tokens: list[float] = field(default_factory=list)
    error: int = 0

    def __str__(self):
        tokens = " ".join(f"{v:g}" for v in self.tokens)
        return f"  pass {self.number}: {self.text!r}\n    R = [{tokens}]  error {self.error}"


@dataclass
class ProbeEngine(InputEngine):
    passes: list[PassRecord] = field(default_factory=list)
    rejected: str = ""

    def __post_init__(self):
        super().__post_init__()
        for address, handler in ((INPUT_PASS, self._on_pass), (AFTER_TOKENS, self._on_tokens),
                                 (INPUT_PASS_RET, self._on_return), (ITEM_ERROR, self._on_error)):
            self.uc.hook_add(UC_HOOK_CODE, handler, begin=address, end=address)

    def _on_pass(self, uc, address, size, user):
        raw = bytes(uc.mem_read(TEXT, 0x200)).decode("latin-1")
        end = raw.find(";")
        self.passes.append(PassRecord(self.i32(PASS_NUMBER), raw[:end + 1] if end >= 0 else raw.rstrip()))

    def _on_tokens(self, uc, address, size, user):
        count = self.i32(R_LIST)
        values = struct.unpack(f"<{max(count, 0)}f", uc.mem_read(R_LIST + 4, 4 * max(count, 0))) if 0 < count < 400 else ()
        self.passes[-1].tokens = list(values)

    def _on_return(self, uc, address, size, user):
        self.passes[-1].error = self.i32(ERROR)

    def _on_error(self, uc, address, size, user):
        """Stop at the first rejected item: position (1-based) in the pass text and the text."""
        position = self.i32(self.arg(0))
        raw = bytes(uc.mem_read(TEXT, 0x200)).decode("latin-1")
        end = raw.find(";")
        self.rejected = f"pass {self.i32(PASS_NUMBER)} rejects at {position}: {raw[:end + 1] if end >= 0 else raw.rstrip()!r}"
        self._stop("input error")


def probe(name: str, body: str, root: Path) -> str:
    script = InputScript.parse(body)
    sandbox = make_sandbox(root)
    engine = ProbeEngine(sandbox)
    engine.initialize()
    target = sandbox / "cwd" / "RESULT.MUS"
    target.unlink(missing_ok=True)
    for step in script.steps:
        if isinstance(step, str):
            engine.command(step)
            continue
        engine.keys = step.keystrokes()
        engine.input_range = step.input_range
        try:
            engine.command(step.command)
        except RuntimeError:
            if not engine.rejected:
                raise
        if engine.rejected:
            return "\n".join([f"== {name}", *map(str, engine.passes), f"  REJECTED {engine.rejected}"])
    engine.command("SA result.mus")
    lines = [f"== {name}", *map(str, engine.passes)]
    if engine.keys:
        lines.append(f"  unused keystrokes: {bytes(engine.keys)!r}")
    lines.append(format_items(read_items(target.read_bytes())) if target.exists() else "  no result")
    return "\n".join(lines)


def probe_case(args: tuple[str, str]) -> str:
    import tempfile
    name, body = args
    with tempfile.TemporaryDirectory(prefix="wscore-probe-") as root:
        try:
            return probe(name, body, Path(root))
        except Exception as err:
            return f"== {name}\nFAILED: {err!r}"


def main(corpus: str, pattern: str = ""):
    cases = [(n, b) for n, b in corpus_cases(Path(corpus).read_text(encoding="latin-1")).items()
             if re.search(pattern, n)]
    with ProcessPoolExecutor(max_workers=PARALLEL_JOBS) as pool:
        for text in pool.map(probe_case, cases):
            print(text, flush=True)


if __name__ == "__main__":
    main(*sys.argv[1:])
