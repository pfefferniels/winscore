"""Run command sequences through a fresh emulated engine each time and report what they did to the items.

    from cmdlab import CommandLab
    lab = CommandLab()
    run = lab.run(["4", "5 20", "X"])          # base score loaded first
    run.items, run.steps, run.handlers

A fresh Engine per sequence avoids edit-mode state leaking between experiments; the sandbox
(one copy of the install) is shared.
"""
from __future__ import annotations

import struct
import sys
import tempfile
from dataclasses import dataclass, field
from pathlib import Path

ORACLE = Path(__file__).resolve().parents[3] / "oracle"
sys.path.insert(0, str(ORACLE))

from emu import RETURN_SENTINEL, STACK_BASE, STACK_SIZE, Engine  # noqa: E402
from unicorn import UcError  # noqa: E402
from unicorn.x86_const import UC_X86_REG_EAX, UC_X86_REG_EIP, UC_X86_REG_ESP  # noqa: E402
from musbuild import mus_bytes  # noqa: E402
from sandbox import make_sandbox  # noqa: E402

BASE = [[8, 1, 0, 0, 1], [8, 2, 0, 0, 1], [3, 1, 2, 0, 0], [1, 1, 30, 5, 10, 0, 1], [2, 1, 50, 0, 0, 0, 1], [14, 1, 70, 1]]
INTERPRETER, EDIT_ITEM = 0x47EC50, 0x20527E0


@dataclass
class Step:
    command: str
    status: int | str
    edit_item: int
    message: str


@dataclass
class Run:
    steps: list[Step]
    items: list[list[float]]
    handlers: list[str] = field(default_factory=list)     # engine routines called directly by the interpreter


def item_list(engine: Engine) -> list[list[float]]:
    out = []
    for i in range(1, engine.i32(0x20B8E24) + 1):
        w = engine.i32(0x2091D1C + 4 * i)
        length = int(struct.unpack("<f", engine.uc.mem_read(0x205343C + 4 * w, 4))[0])
        out.append([round(v, 4) for v in struct.unpack(f"<{length}f", engine.uc.mem_read(0x2053440 + 4 * w, 4 * length))])
    return out


class TimedEngine(Engine):
    """Engine.call with a wall-clock limit, so a command that loops or waits forever is cut off."""
    timeout_us: int = 20_000_000

    def call(self, func, *args, limit=0):
        esp = STACK_BASE + STACK_SIZE - 0x100
        for a in reversed((RETURN_SENTINEL, *args)):
            esp -= 4
            self.put32(esp, a)
        self.uc.reg_write(UC_X86_REG_ESP, esp)
        self.trace.clear()
        try:
            self.uc.emu_start(func, RETURN_SENTINEL, timeout=self.timeout_us, count=limit)
        except UcError as err:
            self.trace.append(f"{err} at eip {self.reg(UC_X86_REG_EIP):#x}")
        finished = self.reg(UC_X86_REG_EIP) == RETURN_SENTINEL
        return finished, self.reg(UC_X86_REG_EAX)


class CommandLab:
    def __init__(self, base: list[list[float]] = BASE):
        self._tmp = tempfile.TemporaryDirectory(prefix="wscore-cmd-")
        self.root = make_sandbox(Path(self._tmp.name))
        (self.root / "cwd" / "base.mus").write_bytes(mus_bytes(base))

    def run(self, commands: list[str], trace: bool = False) -> Run:
        engine = TimedEngine(self.root)
        engine.initialize()
        engine.command("G base.mus")
        steps, handlers = [], []
        tracer = None
        if trace:
            from trace import Tracer
            tracer = Tracer(engine)
            tracer.__enter__()
        try:
            for command in commands:
                try:
                    r = engine.command(command)
                    steps.append(Step(command, r.status, engine.i32(EDIT_ITEM), r.message.strip()[:70]))
                except RuntimeError as err:
                    steps.append(Step(command, "stopped", engine.i32(EDIT_ITEM), str(err)[-70:]))
                    break
            if tracer:
                handlers = sorted({tracer.name(callee) for (caller, callee) in tracer.edges if caller == INTERPRETER})
        finally:
            if tracer:
                tracer.__exit__(None, None, None)
        return Run(steps, item_list(engine), handlers)
