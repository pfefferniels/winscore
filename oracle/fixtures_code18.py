"""Code 18 sweeps: meters (analysis/docs/text/winscore/code18.txt, score4/COD18-4.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, label, staff


def meter(**named: float):
    """Meter on staff 1 at P3 = 20 unless overridden."""
    return item(18, **({"p2": 1, "p3": 20} | named))


def cases() -> list[Case]:
    one = [
        *[(f"p5-p6-{a}-{b}", f"{a}/{b}", {"p5": a, "p6": b}) for a, b in ((4, 4), (3, 4), (6, 8), (2, 2), (12, 8), (5, 16), (1, 1))],
        *[(f"p5-symbol-{v}", f"P5 = {v} (symbol)", {"p5": v}) for v in (99, 98, 91, 95)],
        ("p5-zero-p6-3", "P5 = 0, P6 = 3: single number", {"p6": 3}),
        ("p5-only-3", "P5 = 3, P6 = 0", {"p5": 3}),
        *[(f"p7-size-{label(v)}", f"size P7 = {v}, 3/4", {"p5": 3, "p6": 4, "p7": v}) for v in (0.5, 1.5, 2)],
        *[(f"p7-size-{label(v)}-symbol", f"size P7 = {v}, common time", {"p5": 99, "p7": v}) for v in (0.5, 2)],
        *[(f"p8-p9-{a}-{b}", f"3/4 + {a}/{b}", {"p5": 3, "p6": 4, "p8": a, "p9": b}) for a, b in ((2, 8), (3, 0), (12, 16))],
        ("p8-p9-wide-first", "12/8 + 3/4", {"p5": 12, "p6": 8, "p8": 3, "p9": 4}),
        ("p8-p9-4-3-over-4", "4+3/4 (P9 = 0)", {"p5": 4, "p6": 4, "p8": 3}),
        *[(f"p10-plus-{label(v)}", f"P10 = {v}", {"p5": 3, "p6": 4, "p8": 2, "p9": 8, "p10": v}) for v in (1, -0.5)],
        *[(f"p11-space-{label(v)}", f"P11 = {v}", {"p5": 3, "p6": 4, "p8": 2, "p9": 8, "p11": v}) for v in (1, -1)],
        ("p12-no-plus", "P12 = 1", {"p5": 3, "p6": 4, "p8": 2, "p9": 8, "p12": 1}),
        *[(f"p13-font-{v}", f"font P13 = {v}", {"p5": 3, "p6": 4, "p13": v}) for v in (1, 2, 9)],
        ("p4-offset", "P4 = 3", {"p5": 3, "p6": 4, "p4": 3}),
        *[(f"p15-offset-{label(v)}", f"offset P15 = {v}", {"p5": 3, "p6": 4, "p15": v}) for v in (0.5, -1)],
        ("p16-pixels-symbol", "P16 = 1, common time", {"p5": 99, "p16": 1}),
        ("p16-pixels", "P16 = 1, 3/4", {"p5": 3, "p6": 4, "p16": 1}),
        *[(f"p20-spread-{label(v)}", f"spread P20 = {v}, 12/16", {"p5": 12, "p6": 16, "p20": v}) for v in (1.15, 2)],
        ("p26-grey", "P26 = 0.5", {"p5": 3, "p6": 4, "p26": 0.5}),
        ("p26-grey-symbol", "P26 = 0.5, common time", {"p5": 99, "p26": 0.5}),
    ]
    single = [built(f"code18-{name}", desc, [staff(), meter(**params)]) for name, desc, params in one]
    staves = [
        *[(f"staff-size-{label(s)}-{name}", f"staff size {s}, {name}", {"p5": s}, params)
          for s in (0.75, 1.4, -1) for name, params in (("3-4", {"p5": 3, "p6": 4}), ("common", {"p5": 99}))],
        ("staff-recto-201", "recto staff 201, 6/8", {"p2": 201}, {"p2": 201, "p5": 6, "p6": 8}),
    ]
    on_staves = [built(f"code18-{name}", desc, [staff(**s), meter(**m)]) for name, desc, s, m in staves]
    return single + on_staves
