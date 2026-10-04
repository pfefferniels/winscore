"""Code 9 fixtures: library symbols (analysis/docs/text/winscore/code9.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, label, staff


def symbol(p5: float, **named: float) -> list[float]:
    """Symbol P5 on staff 1 at P3 30, P4 7 unless overridden."""
    base = {"p2": 1, "p3": 30, "p4": 7, "p5": p5} | named
    return item(9, **base)


# One or two symbols from each kind of library: small symbols (0-49, 25 units per library unit),
# 0.3-size symbols (50-4999), percussion, lute, special 1300s.
NUMBERS = (0, 1, 5, 6, 11, 18, 21, 24, 31, 34, 37, 39, 41, 44, 48, 49, 50, 53, 55, 62, 70, 71, 74, 75, 83, 91, 103,
           107, 115, 119, 123, 147, 151, 199, 207, 219, 239, 263, 283, 600, 652, 750, 900, 1000, 1110, 1300, 1302, 1304,
           1400, 1960)
# Drawn as text by the engine (table 0x78EAAC) and the CODE9.DAT terms.
TEXT_NUMBERS = (45, 63, 66, 78, 276, 3000, 3004)

CASES: list[tuple[str, str, list[float]]] = [
    *[(f"p5-symbol-{n}", f"library symbol {n}", symbol(n)) for n in NUMBERS],
    *[(f"p5-text-{n}", f"symbol {n}, drawn as text", symbol(n)) for n in TEXT_NUMBERS],
    ("p5-negative", "P5 -3 draws symbol 0", symbol(-3)),
    ("p5-missing", "P5 3 (empty slot)", symbol(3)),
    *[(f"p6-size-{label(v)}", f"symbol 31, P6 {v}", symbol(31, p6=v)) for v in (0.5, 1.7, -1, 101.5, 250, 300)],
    *[(f"p6-size-small-{label(v)}", f"symbol 53, P6 {v}", symbol(53, p6=v)) for v in (0.6, 2)],
    *[(f"p7-vsize-{label(v)}", f"symbol 31, P6 1, P7 {v}", symbol(31, p6=1, p7=v)) for v in (2, -1, 0.5)],
    ("p7-only", "symbol 31, P7 1.5 without P6", symbol(31, p7=1.5)),
    *[(f"p8-thick-{label(v)}", f"symbol 31, P8 {v}", symbol(31, p8=v)) for v in (101, 202, 3, 300, -1)],
    ("p8-thick-small", "symbol 53, P8 101", symbol(53, p8=101)),
    *[(f"p9-rotation-{label(v)}", f"symbol 37, P9 {v}", symbol(37, p9=v)) for v in (30, -45, 90, 0.5, 1.5)],
    ("p9-rotation-small", "symbol 70, P9 20", symbol(70, p9=20)),
    *[(f"p10-pixels-{label(v)}", f"symbol 31, P10 {v}", symbol(31, p10=v)) for v in (1, 2, -1)],
    ("p10-pixels-small", "symbol 53, P10 2 (one less for symbols from 45 on)", symbol(53, p10=2)),
    ("p10-pixels-p8", "symbol 31, P10 2 with P8 1 (P8 wins)", symbol(31, p10=2, p8=1)),
    *[(f"p15-offset-{label(v)}", f"symbol 24, P15 {v}", symbol(24, p15=v)) for v in (3, -2.5)],
    *[(f"p4-level-{label(v)}", f"symbol 24, P4 {v}", symbol(24, p4=v)) for v in (-3, 0, 14.5)],
    ("p3-fraction", "symbol 24, P3 30.37", symbol(24, p3=30.37)),
    ("p11-special", "special symbol 1302 with P11 1 (hidden in print only)", symbol(1302, p11=1)),
    ("p26-grey", "symbol 31, P26 0.5", symbol(31, p26=0.5)),
    ("p26-rgb", "symbol 53, P26 336699", symbol(53, p26=336699)),
    ("p25-layer", "symbol 31, P25 2", symbol(31, p25=2)),
]


def sized(size: float, *items: list[float]) -> list[list[float]]:
    return [staff(p5=size), *items]


SIZED: list[tuple[str, str, list[list[float]]]] = [
    ("size-0.75", "symbols 31 and 53 on a size 0.75 staff", sized(0.75, symbol(31), symbol(53, p3=60))),
    ("size-1.3", "symbols 31 and 53 on a size 1.3 staff", sized(1.3, symbol(31), symbol(53, p3=60))),
    ("size-0.75-special", "special symbol 1302 on a size 0.75 staff", sized(0.75, symbol(1302))),
    ("staff-0-special", "special symbol 1302 on staff 0", [staff(), symbol(1302, p2=0)]),
    ("staff-2", "symbol 31 on staff 2", [staff(), staff(p2=2), symbol(31, p2=2)]),
    ("recto", "symbol 31 on the recto staff 201", [staff(p2=201), symbol(31, p2=201, p9=10)]),
    ("several", "several symbols in a row", [staff(), *[symbol(n, p3=20 + 15 * i) for i, n in enumerate((6, 7, 8, 24, 53, 74))]]),
]


def cases() -> list[Case]:
    return ([built(f"code09-{name}", desc, [staff(), it]) for name, desc, it in CASES]
            + [built(f"code09-{name}", desc, items) for name, desc, items in SIZED])
