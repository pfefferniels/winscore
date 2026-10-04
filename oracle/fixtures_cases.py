"""The fixture catalogue: the samples here, the per-code sweeps in fixtures_codeNN.py.

Case names: sample-<file>, codeNN-<parameter>-<value class>. See rust/fixtures/PLAN.md.
"""
from __future__ import annotations

import importlib
import struct
from pathlib import Path

from fixtures import Case
from musbuild import mus_bytes

REPO = Path(__file__).resolve().parents[1]
WINSCORE = REPO / "WINSCORE 5.01" / "winscore"
SCORE4 = REPO / "SCORE 4" / "SCORE"

Item = list[float]


def item(*leading: float, **named: float) -> Item:
    """item(8, 1, 0, 0, 1, p26=990000): P1, P2, ... in order, then Pn by name."""
    params = dict(enumerate(leading, start=1)) | {int(k[1:]): v for k, v in named.items()}
    return [float(params.get(n, 0.0)) for n in range(1, max(params) + 1)]


def staff(**named: float) -> Item:
    """Staff 1 at size 1 unless overridden (p2=..., p5=...)."""
    base = {"p2": 1, "p5": 1} | named
    return item(8, **base)


def built(name: str, description: str, items: list[Item], commands: tuple[str, ...] = ()) -> Case:
    return Case(name, description, mus_bytes(items), commands)


def label(value: float) -> str:
    """A value as it appears in a case name: 1.429 -> 1.429, -3 -> m3."""
    text = f"{value:g}"
    return text.replace("-", "m")


# -- samples -----------------------------------------------------------------

def sample_cases() -> list[Case]:
    winscore = [
        Case(f"sample-{p.stem.lower()}", f"WinScore sample {p.name}", p.read_bytes(),
             attachments=(WINSCORE / "logo-col.eps",) if p.stem == "000" else ())
        for p in sorted(WINSCORE.glob("*.mus"))
    ]
    score4 = [Case(f"sample-{p.stem.lower()}", f"SCORE 4 sample {p.name}", p.read_bytes())
              for p in (SCORE4 / "NEWLINE.MUS", SCORE4 / "NEWLIB.MUS")]
    return winscore + score4


TRAILER_WORDS = 6


def sample_items(path: Path) -> list[bytes]:
    """The items of a .mus file as packed words (parameters and characters), in file order."""
    data = path.read_bytes()
    short = int.from_bytes(data[:2], "little")
    words = data[2:] if 2 + 4 * short == len(data) else data[4:]
    items, pos = [], 0
    while pos < len(words) - 4 * TRAILER_WORDS:
        length = int(struct.unpack_from("<f", words, pos)[0])   # the engine truncates stray mantissa bits
        if length <= 0:
            break
        items.append(words[pos + 4:pos + 4 + 4 * length])
        pos += 4 + 4 * length
    return items


def item_code(packed: bytes) -> int:
    return int(struct.unpack_from("<f", packed)[0])


def item_staff(packed: bytes) -> int:
    return int(struct.unpack_from("<f", packed, 4)[0]) if len(packed) >= 8 else 0


def excerpt(path: Path, indices: list[int], staves: tuple[int, ...] = ()) -> list[bytes]:
    """The staff items (code 8) of the staves the chosen items hang on, plus `staves`, then the items."""
    items = sample_items(path)
    chosen = [items[i] for i in indices]
    wanted = {item_staff(p) for p in chosen} | set(staves)
    staff_items = [p for p in items if item_code(p) == 8 and item_staff(p) in wanted]
    return staff_items + [p for p in chosen if item_code(p) != 8]


def code_modules() -> list[str]:
    """Every oracle/fixtures_codeNN.py; each defines cases() and is owned by whoever implements that code."""
    return sorted(p.stem for p in Path(__file__).resolve().parent.glob("fixtures_code*.py"))


def all_cases() -> list[Case]:
    cases = sample_cases() + [c for name in code_modules() for c in importlib.import_module(name).cases()]
    names = [c.name for c in cases]
    duplicates = sorted({n for n in names if names.count(n) > 1})
    if duplicates:
        raise ValueError(f"duplicate case names: {duplicates}")
    return cases
