"""Code 10 sweeps: numbers and rehearsal letters (analysis/docs/text/winscore/code10.txt, score4/COD10-4.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, label, staff


def number(**named: float):
    """Number on staff 1 at P3 = 50, P4 = 12 unless overridden."""
    return item(10, **({"p2": 1, "p3": 50, "p4": 12} | named))


def cases() -> list[Case]:
    one = [
        *[(f"p5-{label(v)}", f"P5 = {v}", {"p5": v})
          for v in (0, 5, 12, 123, 999, 1000, 12.5, 0.5, 3.125, 7.001, -4, -2.5, -0.25, 1001, 1026, 2001, 2003)],
        *[(f"p6-size-{label(v)}", f"size P6 = {v}", {"p5": 12, "p6": v}) for v in (0.5, 2, 101.5)],
        *[(f"p7-font-{v}", f"font P7 = {v}", {"p5": 34, "p7": v}) for v in (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 1005, -1)],
        *[(f"p8-{name}", f"P8 = {v}", {"p5": 12, "p8": v}) for v, name in ((1, "circle"), (2, "box"))],
        *[(f"p8-{name}-letter", f"P8 = {v}, P5 = 1001", {"p5": 1001, "p8": v}) for v, name in ((1, "circle"), (2, "box"))],
        *[(f"p8-{name}-wide", f"P8 = {v}, P5 = 123", {"p5": 123, "p8": v}) for v, name in ((1, "circle"), (2, "box"))],
        *[(f"p10-thick-{v}-box", f"box P10 = {v}", {"p5": 12, "p8": 2, "p10": v}) for v in (2, 3)],
        ("p11-p12-box", "box P11 = 3, P12 = 2", {"p5": 12, "p8": 2, "p11": 3, "p12": 2}),
        ("p11-circle", "circle P11 = 4", {"p5": 12, "p8": 1, "p11": 4}),
        ("p12-circle", "circle P12 = 3", {"p5": 12, "p8": 1, "p12": 3}),
        ("p13-p14-box", "box P13 = 1, P14 = 2", {"p5": 12, "p8": 2, "p13": 1, "p14": 2}),
        *[(f"p15-offset-{label(v)}", f"offset P15 = {v}", {"p5": 12, "p15": v}) for v in (2, -1.5)],
        *[(f"p17-letter-{v}", f"P5 = 23, P17 = {v}", {"p5": 23, "p17": v}) for v in (1, 2, 101, 126)],
        *[(f"p18-{label(v)}", f"P18 = {v}", {"p18": v}) for v in (1234, 9999, -1500)],
        *[(f"p18-letter-{label(v)}", f"P5 = 1002, P18 = {v}", {"p5": 1002, "p18": v}) for v in (2, 12, 100, 226, -500)],
        *[(f"p19-rotate-{label(v)}", f"rotation P19 = {v}", {"p5": 12, "p19": v}) for v in (30, -90)],
        *[(f"p20-spread-{label(v)}", f"spread P20 = {v}", {"p5": 123, "p20": v}) for v in (1.15, 2)],
        ("p26-red", "P26 = 990000", {"p5": 12, "p26": 990000}),
        ("p26-red-box", "P26 = 990000, box", {"p5": 12, "p26": 990000, "p8": 2}),
        ("p16-pixels-music", "P16 = 1, music font", {"p5": 34, "p7": 6, "p16": 1}),
    ]
    single = [built(f"code10-{name}", desc, [staff(), number(**params)]) for name, desc, params in one]
    staves = [
        *[(f"staff-size-{label(s)}", f"staff size {s}", {"p5": s}, {"p5": 12}) for s in (0.75, 1.4, -1)],
        ("staff-size-0.75-box", "staff size 0.75, box", {"p5": 0.75}, {"p5": 12, "p8": 2}),
        ("staff-recto-201", "recto staff 201", {"p2": 201}, {"p2": 201, "p5": 12}),
    ]
    on_staves = [built(f"code10-{name}", desc, [staff(**s), number(**n)]) for name, desc, s, n in staves]
    return single + on_staves
