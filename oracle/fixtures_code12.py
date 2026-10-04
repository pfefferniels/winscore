"""Code 12 sweeps: boxes, circles, guitar grids, accordion symbols (analysis/docs/text/winscore/code12.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, label, staff

KINDS = {0: "box", 1: "circle", 3: "dashed"}


def shape(**named: float):
    """Code-12 item on staff 1 at P3 = 50, P4 = 7 unless overridden."""
    return item(12, **({"p2": 1, "p3": 50, "p4": 7} | named))


def cases() -> list[Case]:
    one = [
        # Dashed boxes of size 0 or below draw only continuation points, which join the previous item's stroke.
        *[(f"p5-{name}", f"P5 = {k}, P6 = 0", {"p5": k}) for k, name in KINDS.items() if k != 3],
        *[(f"p6-{label(v)}-{name}", f"P6 = {v}, P5 = {k}", {"p5": k, "p6": v})
          for k, name in KINDS.items() for v in (2, 4.5, -3) if not (k == 3 and v < 0)],
        *[(f"p6-p7-{name}", f"P6 = 4, P7 = 2, P5 = {k}", {"p5": k, "p6": 4, "p7": 2}) for k, name in KINDS.items()],
        *[(f"p8-thick-{label(v)}-{name}", f"thickness P8 = {v}, P5 = {k}", {"p5": k, "p6": 3, "p8": v})
          for k, name in KINDS.items() for v in (1, 3, -1)],
        *[(f"p9-rotate-{label(v)}-{name}", f"rotation P9 = {v}, P5 = {k}", {"p5": k, "p6": 4, "p7": 2, "p9": v})
          for k, name in KINDS.items() for v in (30, -45, 0.5)],
        *[(f"p10-slant-{label(v)}", f"box slant P10 = {v}", {"p5": 0, "p6": 3, "p10": v}) for v in (1, -0.5)],
        *[(f"p10-dash-{label(v)}", f"dashed box dash P10 = {v}", {"p5": 3, "p6": 4, "p10": v}) for v in (0.5, 2)],
        *[(f"p10-p11-arc-{a}-{b}", f"circle arc P10 = {a}, P11 = {b}", {"p5": 1, "p6": 3, "p10": a, "p11": b})
          for a, b in ((0, 180), (90, 270), (-90, 90), (300, 60), (45, 0))],
        *[(f"p12-sides-{v}", f"circle P12 = {v}", {"p5": 1, "p6": 3, "p12": v}) for v in (60, 45, 7, -5, -7, -20)],
        ("p12-arc-dashes", "arc 0-180 with P12 = -10", {"p5": 1, "p6": 3, "p11": 180, "p12": -10}),
        *[(f"p13-fill-{name}", f"filled P5 = {k}", {"p5": k, "p6": 3, "p13": 1}) for k, name in KINDS.items()],
        ("p13-fill-thick-box", "filled box P8 = 2", {"p5": 0, "p6": 3, "p13": 1, "p8": 2}),
        ("p13-fill-thick-circle", "filled circle P8 = 2", {"p5": 1, "p6": 3, "p13": 1, "p8": 2}),
        *[(f"p15-offset-{label(v)}", f"offset P15 = {v}", {"p5": 0, "p15": v}) for v in (2, -1.5)],
        *[(f"p16-unit-{name}", f"P16 = 1, P5 = {k}, P6 = 0.2", {"p5": k, "p6": 0.2, "p16": 1}) for k, name in KINDS.items()],
        ("p26-grey", "P26 = 0.5", {"p5": 0, "p26": 0.5}),
        ("p26-marked", "P26 = -1", {"p5": 0, "p6": 3, "p26": -1}),
        ("p26-marked-circle", "P26 = -1 circle", {"p5": 1, "p6": 3, "p26": -1}),
        *[(f"p5-other-{label(k)}", f"P5 = {k}", {"p5": k, "p6": 3}) for k in (2, 4, 5, 10, -1, -2, -5, -10)],
        ("p5-arrow-p10-1", "P5 = 2, P10 = 1 (straight arrow)", {"p5": 2, "p6": 3, "p10": 1}),
    ]
    single = [built(f"code12-{name}", desc, [staff(), shape(**params)]) for name, desc, params in one]
    staves = [
        *[(f"staff-size-{label(s)}-{name}", f"staff size {s}, P5 = {k}", {"p5": s}, {"p5": k, "p6": 3})
          for s in (0.75, 1.4, -1) for k, name in KINDS.items() if not (k == 3 and s < 0)],
        ("staff-recto-201", "recto staff 201, circle", {"p2": 201}, {"p2": 201, "p5": 1}),
    ]
    on_staves = [built(f"code12-{name}", desc, [staff(**s), shape(**b)]) for name, desc, s, b in staves]
    return single + on_staves
