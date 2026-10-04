"""Layout commands (LI, LJ, J): the engine moves and reorders items; result.mus holds its score afterwards.

LJ and LI first prompt for the lowest staff and the number of staves (answered by the
next command line), then ask "Source Box O.K.?", which the fixture engine answers yes.
Answered no, the engine waits for a box drawn with the mouse, which the oracle cannot give.
"""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import Item, item, staff
from musbuild import mus_bytes


def two_staff_system() -> list[Item]:
    """Two measures on two staves; the notes are unevenly spaced and do not line up across the staves."""
    upper = [item(1, 2, 10 + 12 * k, 5, 10, 0, 1) for k in range(4)] + [item(1, 2, 75 + 6 * k, 6, 10, 0, 0.5) for k in range(8)]
    lower = [item(1, 1, 12 + 14 * k, 0, 20, 1, 2) for k in range(2)] + [item(1, 1, 80 + 20 * k, 1, 20, 0, 1) for k in range(4)]
    bars = [item(14, 1, x, 2) for x in (0, 70, 130)]
    return [staff(), staff(p2=2), *bars, *upper, *lower]


def single_staff() -> list[Item]:
    notes = [item(1, 1, 8 + 9 * k, 4 + k % 3, 10, 0, 1) for k in range(8)]
    return [staff(), item(14, 1, 0, 1), *notes[:4], item(14, 1, 45, 1), *notes[4:], item(14, 1, 90, 1)]


def cases() -> list[Case]:
    system = mus_bytes(two_staff_system())
    return [
        Case("layout-lj-system", "LJ on a two-staff system (lowest staff 1, two staves)", system, ("LJ", "1 2")),
        Case("layout-li-system", "LI on a two-staff system (the engine gives the same result as LJ here)", system, ("LI", "1 2")),
        Case("layout-lja-single", "LJA on one staff with two measures", mus_bytes(single_staff()), ("LJA",)),
    ]
