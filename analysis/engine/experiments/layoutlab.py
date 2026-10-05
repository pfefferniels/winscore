"""Run LJ / LI / J through the engine (answering "Source Box O.K.?" with yes) and return the items.

    from layoutlab import run_layout
    items_after, engine = run_layout(items, ["LJ", "1 2"])
"""
from __future__ import annotations

from cmdlab import CommandLab, TimedEngine, item_list
from musbuild import mus_bytes

YES_NO = 0x595CD0


class YesEngine(TimedEngine):
    """Answers the engine's yes/no question (0x595CD0) with yes and records the question."""

    def _on_cpp(self, uc, address, size, user):
        if address == YES_NO:
            self.shell.record("question", self.cstr(self.arg(0), 80))
            self.return_from_call(1, 0)
            return
        return super()._on_cpp(uc, address, size, user)


_lab: CommandLab | None = None


def engine_with(items: list[list[float]]) -> YesEngine:
    global _lab
    _lab = _lab or CommandLab()
    (_lab.root / "cwd" / "layout.mus").write_bytes(mus_bytes(items))
    engine = YesEngine(_lab.root)
    engine.initialize()
    engine.command("G layout.mus")
    return engine


def run_layout(items: list[list[float]], commands: list[str], digits: int | None = 4):
    engine = engine_with(items)
    for command in commands:
        engine.command(command)
    return item_list(engine, digits), engine
