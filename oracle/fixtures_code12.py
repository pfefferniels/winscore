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
        *[(f"arrow-straight-{name}", f"straight arrow, {desc}", {"p5": 2, "p10": 1} | params) for name, desc, params in (
            ("default", "P6 = 0", {}),
            ("long", "P6 = 2.5", {"p6": 2.5}),
            ("left", "P6 = -2", {"p6": -2}),
            ("head", "P12 = 2, P13 = 3", {"p6": 2, "p12": 2, "p13": 3}),
            ("no-head", "P12 = -1", {"p6": 2, "p12": -1}),
            ("rotated", "P9 = 30", {"p6": 2, "p9": 30}),
            ("rotated-no-head", "P9 = -60, P12 = -1", {"p6": 2, "p9": -60, "p12": -1}),
        )],
        *[(f"register-{name}", f"accordion register, {desc}", {"p5": 10} | params) for name, desc, params in (
            ("default", "P7 = 0", {}),
            ("rows3-dots", "P8 = 111, P9 = 101", {"p8": 111, "p9": 101}),
            ("rows3-centre", "P8 = 10", {"p8": 10}),
            ("rows3-p9-centre", "P9 = 10", {"p9": 10}),
            ("rows4", "P7 = 4, P8 = 1010", {"p7": 4, "p8": 1010}),
            ("rows4-all", "P7 = 4, P8 = 1111, P9 = 101", {"p7": 4, "p8": 1111, "p9": 101}),
            ("rows4-110", "P7 = 4, P8 = 110, P9 = 1", {"p7": 4, "p8": 110, "p9": 1}),
            ("rows2", "P7 = 2, P8 = 11", {"p7": 2, "p8": 11}),
            ("rows2-below", "P7 = 2, P8 = 10", {"p7": 2, "p8": 10}),
            ("size", "P6 = 1.5, P8 = 101", {"p6": 1.5, "p8": 101}),
            ("thick", "P10 = 2", {"p10": 2, "p8": 1}),
            ("filled", "P13 = 1", {"p13": 1}),
            ("polygon", "P12 = 30", {"p12": 30, "p8": 100}),
            ("offset", "P15 = 2, P8 = 1", {"p15": 2, "p8": 1}),
        )],
        *[(f"grid-{name}", f"guitar grid, {desc}", params) for name, desc, params in (
            ("basic", "P5 = -1", {"p5": -1}),
            ("no-nut", "P5 = -2", {"p5": -2}),
            ("name-only", "P5 = -3, P7 = 10", {"p5": -3, "p7": 10}),
            ("p14-45", "P5 = -1, P14 = 45 (4 strings? 5 frets)", {"p5": -1, "p14": 45}),
            ("p14-64", "P5 = -1, P14 = 64", {"p5": -1, "p14": 64}),
            ("dots", "P13 = 132211", {"p5": -1, "p13": 132211}),
            ("open-muted", "P13 = 932818", {"p5": -1, "p13": 932818}),
            ("dots-4", "P14 = 54, P13 = 1234", {"p5": -1, "p14": 54, "p13": 1234}),
            ("fingers", "P13 = 132211, P18 = 132411", {"p5": -1, "p13": 132211, "p18": 132411}),
            ("fingers-thumb", "P13 = 132211, P18 = 932811", {"p5": -1, "p13": 132211, "p18": 932811}),
            ("barre", "P13 = 133211, P12 = 1601", {"p5": -2, "p13": 133211, "p12": 1601}),
            ("barre-3", "P13 = 335553, P12 = 2603", {"p5": -2, "p13": 335553, "p12": 2603}),
            ("fret", "P12 = 5, P13 = 133211", {"p5": -2, "p13": 133211, "p12": 5}),
            ("fret-frac", "P12 = 5.5", {"p5": -2, "p12": 5.5}),
            ("size", "P6 = 1.5, P13 = 132211", {"p5": -1, "p6": 1.5, "p13": 132211}),
            ("p16", "P16 = 1.5, P7 = 10", {"p5": -1, "p16": 1.5, "p7": 10}),
            ("p17-wide", "P17 = 1.5", {"p5": -1, "p17": 1.5, "p13": 132211}),
            ("p17-negative", "P17 = -1", {"p5": -1, "p17": -1}),
            ("p19-name", "P19 = 2, P7 = 10", {"p5": -1, "p19": 2, "p7": 10}),
            *[(f"root-{r}", f"P7 = {r}", {"p5": -1, "p7": r}) for r in (10, 11, 12, 20, 32, 41, 52, 60, 70, 71)],
            *[(f"type-{t}", f"P7 = 10, P8 = {t}", {"p5": -1, "p7": 10, "p8": t}) for t in range(1, 10)],
            *[(f"p9-{v}", f"P7 = 10, P9 = {v}", {"p5": -1, "p7": 10, "p9": v}) for v in (107, 409, 513, 607)],
            *[(f"p10-{v}", f"P7 = 10, P10 = {v}", {"p5": -1, "p7": 10, "p10": v}) for v in (1000, 2000, 3009, 109)],
            *[(f"p11-{v}", f"P7 = 10, P11 = {v}", {"p5": -1, "p7": 10, "p11": v}) for v in (5000, 7011, 105)],
            *[(f"dict-{r}-{t}-{v}", f"dictionary P5 = -4, P7 = {r}, P8 = {t}, P9 = {v}", {"p5": -4, "p7": r, "p8": t, "p9": v})
              for r, t, v in ((10, 1, 0), (10, 2, 0), (60, 12, 1), (12, 7, 2), (21, 3, 0), (41, 11, 4), (72, 20, 3), (11, 19, 0))],
            ("dict-p5-5", "P5 = -5, P7 = 10", {"p5": -5, "p7": 10}),
            ("dict-p5-6", "P5 = -6, P7 = 10, P8 = 7", {"p5": -6, "p7": 10, "p8": 7}),
            ("sample-000-a", "000.mus: P5 = -4, P6 = 1, P7 = 10", {"p5": -4, "p6": 1, "p7": 10}),
            ("sample-000-b", "000.mus: P5 = -4, P6 = 1, P7 = 60, P8 = 1", {"p5": -4, "p6": 1, "p7": 60, "p8": 1}),
            ("sample-000-c", "000.mus: P5 = -4, P6 = 1, P7 = 12, P8 = 2", {"p5": -4, "p6": 1, "p7": 12, "p8": 2}),
            ("rotated", "P9 = 20 is a name code, not rotation; P13 dots", {"p5": -1, "p13": 132211, "p26": 990000}),
        )],
        *[(f"arrow-arc-{name}", f"arc arrow, {desc}", {"p5": 2} | params) for name, desc, params in (
            ("p11-90", "P11 = 90", {"p6": 2, "p11": 90}),
            ("p11-30", "P11 = 30", {"p6": 2, "p11": 30}),
            ("p11-150", "P11 = 150", {"p6": 2, "p11": 150}),
            ("p6-p7", "P6 = 3, P7 = 1.5", {"p6": 3, "p7": 1.5}),
            ("flipped", "P6 = -2, P7 = -2", {"p6": -2, "p7": -2}),
            ("head", "P12 = 2, P13 = 3", {"p6": 2, "p12": 2, "p13": 3}),
            ("no-head", "P12 = -1", {"p6": 2, "p12": -1}),
            ("rotated", "P9 = 45", {"p6": 2, "p9": 45}),
            ("rotated-0.5", "P9 = 0.5", {"p6": 2, "p9": 0.5}),
            ("thick", "P8 = 2", {"p6": 2, "p8": 2}),
            ("marked", "P26 = -1", {"p6": 2, "p26": -1}),
        )],
    ]
    single = [built(f"code12-{name}", desc, [staff(), shape(**params)]) for name, desc, params in one]
    staves = [
        *[(f"staff-size-{label(s)}-{name}", f"staff size {s}, P5 = {k}", {"p5": s}, {"p5": k, "p6": 3})
          for s in (0.75, 1.4, -1) for k, name in KINDS.items() if not (k == 3 and s < 0)],
        ("staff-recto-201", "recto staff 201, circle", {"p2": 201}, {"p2": 201, "p5": 1}),
    ]
    on_staves = [built(f"code12-{name}", desc, [staff(**s), shape(**b)]) for name, desc, s, b in staves]
    return single + on_staves
