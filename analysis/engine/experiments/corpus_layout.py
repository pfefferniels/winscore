"""LI / J / LJ model against the engine on real SCORE files: every staff alone (first three)
and all staves of the page as one system.

    python corpus_layout.py DIR [LJ|LI|J] [max_files]

DIR is searched recursively for .mus and .pag files (for example the corpus agent's
corpus/files). Items are compared bit for bit, except P9 of centred rests (code 2, P5 <= -2):
the lineup sets it to -1 and the redraw after the command (draw_rest 0x519C38) replaces it by
the rest's centre, which belongs to rendering.
"""
from __future__ import annotations

import shutil
import struct
import sys
from pathlib import Path

from cmdlab import CommandLab, item_list
from justify import layout_items
from layoutlab import YesEngine
from lineup import LineupError, code, staff

_lab = CommandLab()


def bits(it) -> bytes:
    return b"".join(struct.pack("<f", v) for v in it)


def loaded(path: Path) -> YesEngine:
    shutil.copyfile(path, _lab.root / "cwd" / "real.mus")
    engine = YesEngine(_lab.root)
    engine.initialize()
    engine.command("G real.mus")
    return engine


def centred_rest_p9(model, engine) -> bool:
    return (len(model) == len(engine) >= 9 and model[0] == 2 and model[4] <= -2 and model[8] == -1
            and bits(model[:8]) == bits(engine[:8]) and bits(model[9:]) == bits(engine[9:]))


def check(path: Path, command: str, lo: int, count: int) -> str | None:
    engine = loaded(path)
    before = item_list(engine, None)
    try:
        model = layout_items(before, lo, lo + count - 1, command)
    except LineupError as err:
        model = getattr(err, "items", None)
    engine.command(command)
    engine.command(f"{lo} {count}")
    after = item_list(engine, None)
    if model is None:
        return "the model gave up without items"
    diff = [k for k, (a, b) in enumerate(zip(model, after))
            if bits(a) != bits(b) and not centred_rest_p9(a, b)]
    if not diff and len(model) == len(after):
        return None
    k = diff[0] if diff else min(len(model), len(after))
    return f"{len(diff)} of {len(after)} items differ, first {k}: model {model[k][:8]} engine {after[k][:8]}"


def main(folder: str, command: str = "LJ", max_files: int = 10_000):
    paths = sorted(p for p in Path(folder).rglob("*") if p.suffix.lower() in (".mus", ".pag"))[:max_files]
    good = total = 0
    for path in paths:
        items = item_list(loaded(path), None)
        staves = sorted({staff(it) for it in items if code(it) == 8 and staff(it) > 0})
        if not staves:
            continue
        for lo, count in [(s, 1) for s in staves[:3]] + [(staves[0], len(staves))]:
            total += 1
            problem = check(path, command, lo, count)
            if problem is None:
                good += 1
            else:
                print(f"{path.relative_to(folder)} {command} {lo} {count}: {problem}", flush=True)
    print(f"{good}/{total} runs identical after {command} ({len(paths)} files)", flush=True)


if __name__ == "__main__":
    main(sys.argv[1], *(sys.argv[2:3]), *(int(a) for a in sys.argv[3:4]))
