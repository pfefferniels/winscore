"""Code 8 sweeps: staves (analysis/docs/text/winscore/code8.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, label, staff


def cases() -> list[Case]:
    one = [
        ("default", "staff 1, size 1", {}),
        ("p5-zero", "P5 = 0 (engine default size)", {"p5": 0}),
        *[(f"p2-staff-{n}", f"single staff numbered {n}", {"p2": n}) for n in (0, 2, 3, 10)],
        *[(f"p3-left-{label(v)}", f"left end P3 = {v}", {"p3": v}) for v in (-20, 10, 55.5)],
        *[(f"p4-offset-{label(v)}", f"vertical offset P4 = {v} scale steps", {"p4": v}) for v in (-3, 2.5, 5)],
        *[(f"p5-size-{label(v)}", f"staff size P5 = {v}", {"p5": v}) for v in (0.5, 0.64, 0.65, 0.8, 1.429, 2)],
        *[(f"p6-right-{label(v)}", f"right end P6 = {v}", {"p6": v}) for v in (150, 210, 220)],
        ("p3-p6-short", "P3 = 50, P6 = 120", {"p3": 50, "p6": 120}),
        *[(f"p7-lines-{v}", f"{v} staff line(s)", {"p7": v}) for v in (1, 2, 3, 4, 6, 7, 10)],
        *[(f"p7-xyz-{v}", f"P7 = {v}: bottom line of a normal staff, then count", {"p7": v}) for v in (203, 302, 401, 106)],
        ("p7-invisible", "P7 = -1, invisible staff (light grey on screen)", {"p7": -1}),
        ("p9-instrument", "instrument number P9 = 5", {"p9": 5}),
        *[(f"p10-inches-{label(v)}", f"staff 2 placed {v} in above staff 1 with P10 (P4 = 4 ignored)", {"p2": 2, "p10": v, "p4": 4})
          for v in (1.5, 3)],
        *[(f"p11-thickness-{v}", f"PostScript line thickness P11 = {v}", {"p11": v}) for v in (2, 99)],
        ("p12-suppress-number", "P12 = 1 hides the staff number", {"p12": 1}),
        ("p13-transpose", "MIDI transposition P13 = -9", {"p13": -9}),
        *[(f"p14-cm-{label(v)}", f"staff height P14 = {v} cm", {"p14": v, "p5": 0}) for v in (0.78, 1.2)],
        ("p25-layer", "layer number P25 = 1", {"p25": 1}),
        *[(f"p26-{name}", f"P26 = {v}", {"p26": v}) for name, v in
          (("grey-0.5", 0.5), ("white", 1), ("red", 990000), ("rgb-336699", 336699), ("green-009900", 9900))],
    ]
    single = [built(f"code08-{name}", desc, [staff(**params)]) for name, desc, params in one]
    systems = [
        ("staves-2", "staves 1 and 2, size 1", [staff(), staff(p2=2)]),
        ("staves-4", "staves 1-4, size 1", [staff(p2=n) for n in range(1, 5)]),
        ("staves-gaps", "staves 1, 3 and 6", [staff(p2=n) for n in (1, 3, 6)]),
        ("staves-sizes", "staves 1-4 with sizes 1, 0.75, 1.2, 0.6",
         [staff(p2=n, p5=s) for n, s in zip(range(1, 5), (1, 0.75, 1.2, 0.6))]),
        ("staves-offsets", "staves 1-3 with P4 = 0, 4, -2", [staff(p2=n, p4=o) for n, o in zip(range(1, 4), (0, 4, -2))]),
        ("staves-p10", "staves 1-3, staves 2 and 3 placed by P10 = 1.2 and 2.6 in",
         [staff(), staff(p2=2, p10=1.2), staff(p2=3, p10=2.6)]),
        ("staves-ends", "staves 1-3 with different P3/P6", [staff(p3=0), staff(p2=2, p3=20, p6=180), staff(p2=3, p3=-10, p6=210)]),
        ("staves-lines", "staves with 5, 1 and 3 lines", [staff(), staff(p2=2, p7=1), staff(p2=3, p7=3)]),
        ("staves-recto", "staff 1 and recto staff 201", [staff(), staff(p2=201)]),
        ("staves-12", "twelve staves at size 0.7", [staff(p2=n, p5=0.7) for n in range(1, 13)]),
    ]
    return single + [built(f"code08-{name}", desc, items) for name, desc, items in systems]
