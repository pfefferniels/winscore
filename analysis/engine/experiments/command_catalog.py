"""Run every distinct command string of analysis/data/command_map.tsv through the engine and record its effect.

    python command_catalog.py [workers]      writes analysis/engine/data/commands.tsv (takes a while)

Two contexts per command, each in a fresh engine on cmdlab.BASE (staves 1-2, treble clef, a note
at P3 30 P4 5, a rest, a barline):
  new:  "<cmd>", "X"            what the command does with nothing selected (item creation etc.)
  note: "I 4", "<cmd>", "X"     what it does to the selected note (item 4)
Columns: command, context, status of the command, items added (P lists), item 4 before -> after,
items deleted (count), engine routines the interpreter called directly while running the command.
"""
from __future__ import annotations

import csv
import sys
from concurrent.futures import ProcessPoolExecutor
from pathlib import Path

from cmdlab import CommandLab

HERE = Path(__file__).resolve().parent
COMMAND_MAP = HERE.parents[1] / "data" / "command_map.tsv"
OUT = HERE.parents[0] / "data" / "commands.tsv"
CONTEXTS = {"new": [], "note": ["I 4"]}

_lab: CommandLab | None = None
_baselines: dict[str, list[list[float]]] = {}


def fmt(item: list[float]) -> str:
    return " ".join(f"{v:g}" for v in item)


def effect(command: str) -> list[list[str]]:
    global _lab
    if _lab is None:
        _lab = CommandLab()
    rows = []
    for context, prefix in CONTEXTS.items():
        try:
            if context not in _baselines:
                _baselines[context] = _lab.run(prefix + ["X"]).items
            base = _baselines[context]
            run = _lab.run(prefix + [command, "X"], traced=len(prefix))
        except Exception as err:          # an emulation failure is a result too
            rows.append([command, context, f"error {err!r}"[:80], "", "", "", ""])
            continue
        step = next((s for s in run.steps if s.command == command), None)
        added = [fmt(i) for i in run.items if i not in base]
        removed = sum(1 for i in base if i not in run.items)
        before = base[3] if len(base) > 3 else []
        after = run.items[3] if len(run.items) > 3 else []
        changed = f"{fmt(before)} -> {fmt(after)}" if context == "note" and before != after else ""
        rows.append([command, context, str(step.status) if step else "?", " | ".join(added), changed,
                     str(removed), " ".join(run.handlers)])
    return rows


def main(workers: int = 6):
    with COMMAND_MAP.open() as f:
        commands = sorted({row["score_command"] for row in csv.DictReader(f, delimiter="\t") if row["score_command"].strip()})
    with ProcessPoolExecutor(workers) as pool, OUT.open("w", newline="") as out:
        writer = csv.writer(out, delimiter="\t", lineterminator="\n")
        writer.writerow(["command", "context", "status", "added", "item4", "deleted", "handlers"])
        for rows in pool.map(effect, commands, chunksize=8):
            writer.writerows(rows)
            out.flush()


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
