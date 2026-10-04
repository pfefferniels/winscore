"""Code 11 sweeps: user symbols from SCORE 3/4 .DRW files (analysis/docs/text/winscore/code11.txt).

The file name follows P13 as 128 characters (P14-P45); a missing file and P13 = 99
make the engine show a message or dialog, so they have no cases. The compact libraries
shipped in scorlib are KBRHY.DRW (symbols 0, 1) and FAULT.DRW (symbol 0).
"""
from __future__ import annotations

import struct

from fixtures import Case
from fixtures_cases import built, label, staff

NAME_CHARACTERS = 128


def user_symbol(name: str = "KBRHY.DRW", **named: float) -> bytes:
    """Code 11 on staff 1 at P3 = 30, P4 = 7, P1-P13 then the file name."""
    params = {1: 11, 2: 1, 3: 30, 4: 7} | {int(k[1:]): v for k, v in named.items()}
    words = b"".join(struct.pack("<f", float(params.get(n, 0.0))) for n in range(1, 14))
    return words + name.encode("latin-1").ljust(NAME_CHARACTERS, b" ")


def cases() -> list[Case]:
    one = [
        *[(f"p5-{v}", f"KBRHY symbol {v}", "KBRHY.DRW", {"p5": v}) for v in (0, 1, 2, 9)],
        ("fault", "FAULT symbol 0", "FAULT.DRW", {}),
        ("name-no-extension", "name KBRHY", "KBRHY", {"p5": 1}),
        ("name-lower-case", "name kbrhy.drw", "kbrhy.drw", {}),
        ("name-scorlib-path", "name \\WINSCORE\\SCORLIB\\KBRHY.DRW", "\\WINSCORE\\SCORLIB\\KBRHY.DRW", {}),
        *[(f"p6-size-{label(v)}", f"size P6 = {v}", "KBRHY.DRW", {"p6": v}) for v in (0.5, 1.5, -1, 101)],
        ("p6-p7", "P6 = 0.5, P7 = 1.5", "KBRHY.DRW", {"p6": 0.5, "p7": 1.5}),
        *[(f"p8-thick-{label(v)}", f"thickness P8 = {v}", "FAULT.DRW", {"p8": v}) for v in (101, 2, -1)],
        *[(f"p9-rotate-{label(v)}", f"rotation P9 = {v}", "FAULT.DRW", {"p9": v}) for v in (30, -90, 0.5)],
        *[(f"p10-pixels-{v}", f"pixel thickness P10 = {v}", "FAULT.DRW", {"p10": v}) for v in (1, 2)],
        ("p15-offset", "P15 = 5 (not applied to code 11)", "KBRHY.DRW", {"p15": 5}),
        ("p26-grey", "P26 = 0.5", "FAULT.DRW", {"p26": 0.5}),
        ("p4-p3", "P3 = 120, P4 = 2", "FAULT.DRW", {"p3": 120, "p4": 2}),
    ]
    single = [built(f"code11-{name}", desc, [staff(), user_symbol(file, **params)]) for name, desc, file, params in one]
    staves = [
        *[(f"staff-size-{label(s)}", f"staff size {s}", {"p5": s}, {}) for s in (0.75, 1.4, -1)],
        ("staff-recto-201", "recto staff 201", {"p2": 201}, {"p2": 201}),
    ]
    on_staves = [built(f"code11-{name}", desc, [staff(**s), user_symbol("FAULT.DRW", **u)]) for name, desc, s, u in staves]
    several = [
        built("code11-two-files", "KBRHY symbol 1 then FAULT symbol 0",
              [staff(), user_symbol("KBRHY.DRW", p5=1), user_symbol("FAULT.DRW", p3=150)]),
        built("code11-then-staff", "a code-11 item, then a second staff",
              [staff(), user_symbol("FAULT.DRW"), staff(p2=2)]),
    ]
    return single + on_staves + several
