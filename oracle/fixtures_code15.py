"""Code 15 fixtures: imported EPS files as the screen shows them (analysis/docs/text/winscore/code15.txt).

Every case but `noname` names logo-col.eps, attached next to the score; the engine draws
nothing for an EPS file it cannot find.
"""
from __future__ import annotations

import struct

from fixtures import Case
from fixtures_cases import WINSCORE, item, label, staff
from musbuild import mus_bytes

EPS = WINSCORE / "logo-col.eps"
BOUNDING_BOX = {"p7": 61, "p8": 249, "p9": 490, "p10": 458}
BOUNDING_BOX_READ = -9999


def name_words(name: str) -> dict[str, float]:
    """P14… holding a file name, four characters per word."""
    raw = name.encode().ljust(36, b"\0")
    return {f"p{14 + i // 4}": struct.unpack("<f", raw[i:i + 4])[0] for i in range(0, 36, 4)}


def eps(name: str = "logo-col.eps", **named: float) -> list[float]:
    """logo-col.eps on staff 1 at P3 20, P4 3, size 0.2, with its bounding box read."""
    base = {"p2": 1, "p3": 20, "p4": 3, "p5": 0.2, **BOUNDING_BOX, "p11": BOUNDING_BOX_READ} | name_words(name) | named
    return item(15, **base)


def case(name: str, description: str, items: list[list[float]]) -> Case:
    return Case(f"code15-{name}", description, mus_bytes(items), attachments=(EPS,))


CASES: list[tuple[str, str, list[float]]] = [
    ("default", "logo-col.eps at size 0.2: bounding box with diagonals", eps()),
    *[(f"p5-size-{label(v)}", f"P5 {v}", eps(p5=v)) for v in (0, 0.07, -0.2)],
    *[(f"p6-vsize-{label(v)}", f"P5 0.2, P6 {v}", eps(p6=v)) for v in (0.5, -0.1)],
    *[(f"p12-rotation-{label(v)}", f"P12 {v}", eps(p12=v)) for v in (30, -135, 0.5)],
    ("p11-unread", "P11 0 (bounding box not read): placeholder square of P5 scale steps", eps(p11=0)),
    ("p11-unread-default", "P11 0, P5 0: placeholder of 3 scale steps", eps(p11=0, p5=0)),
    ("p11-unread-p6", "P11 0, P5 2, P6 1", eps(p11=0, p5=2, p6=1)),
    ("p4-level", "P4 -6.4, P3 55.3", eps(p4=-6.4, p3=55.3)),
    ("noname", "no file name in P14…", item(15, p2=1, p3=20, p4=3, p5=0.2, **BOUNDING_BOX, p11=BOUNDING_BOX_READ)),
    ("p26-grey", "P26 0.5", eps(p26=0.5)),
]

SIZED: list[tuple[str, str, list[list[float]]]] = [
    ("size-0.75", "on a size 0.75 staff", [staff(p5=0.75), eps()]),
    ("size-0.75-unread", "placeholder on a size 0.75 staff", [staff(p5=0.75), eps(p11=0)]),
    ("staff-2", "on staff 2", [staff(), staff(p2=2), eps(p2=2, p12=10)]),
    ("recto", "on the recto staff 201", [staff(p2=201), eps(p2=201)]),
    ("two", "two EPS items after a staff", [staff(), eps(), eps(p3=80, p5=0.1, p6=0.14)]),
]


def cases() -> list[Case]:
    return ([case(name, desc, [staff(), it]) for name, desc, it in CASES]
            + [case(name, desc, items) for name, desc, items in SIZED])
