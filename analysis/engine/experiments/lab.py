"""Shared helpers for engine experiments: render items through the emulated engine.

    from lab import Lab
    lab = Lab()
    shapes, runs = lab.render([[8, 1, 0, 0, 1]])
"""
from __future__ import annotations

import sys
import tempfile
from pathlib import Path

ORACLE = Path(__file__).resolve().parents[3] / "oracle"
sys.path.insert(0, str(ORACLE))

from displaylist import shapes as decode_shapes, text_runs  # noqa: E402
from emu import Engine, EngineResult  # noqa: E402
from musbuild import mus_bytes  # noqa: E402
from sandbox import make_sandbox  # noqa: E402


class Lab:
    """One engine in a private temporary sandbox; each render loads a fresh score file."""

    def __init__(self):
        self._tmp = tempfile.TemporaryDirectory(prefix="wscore-lab-")
        self.root = make_sandbox(Path(self._tmp.name))
        self.engine = Engine(self.root)
        self.engine.initialize()
        self._serial = 0

    def load(self, items: list[list[float]], commands: tuple[str, ...] = ()) -> EngineResult:
        self._serial += 1
        name = f"lab{self._serial}.mus"
        (self.root / "cwd" / name).write_bytes(mus_bytes(items))
        result = self.engine.command(f"G {name}")
        for command in commands:
            result = self.engine.command(command)
        return result

    def render(self, items: list[list[float]], commands: tuple[str, ...] = ()):
        result = self.load(items, commands)
        return decode_shapes(result.vector), text_runs(result.text)
