"""Code 14 sweeps: barlines, braces, brackets (analysis/docs/text/winscore/code14.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import Item, built, item, label, staff

BAR_TYPES = {
    0: "single", 1: "double", 2: "final", 3: "repeat-left", 4: "repeat-right", 5: "repeat-both",
    6: "repeat-heavy", 7: "dashed", 8: "brace", 9: "bracket", 10: "square-bracket", 11: "type-11",
    14: "type-14", -1: "negative", -44: "two-bar-repeat",
}


def four_staves(**named: float) -> list[Item]:
    return [staff(p2=n, **named) for n in range(1, 5)]


def bar(**named: float) -> Item:
    """Barline on staff 1 at P3 = 100 spanning two staves unless overridden."""
    base = {"p2": 1, "p3": 100, "p4": 2} | named
    return item(14, **base)


def cases() -> list[Case]:
    on_four = [
        *[(f"p4-span-{label(v)}", f"P4 = {v} staves spanned", {"p4": v}) for v in (0, 1, 2, 3, 4, 999, -1, -2)],
        ("p2-from-staff-2", "barline from staff 2 spanning 2", {"p2": 2}),
        ("p2-top-staff", "barline on staff 4 spanning 999", {"p2": 4, "p4": 999}),
        *[(f"p3-pos-{label(v)}", f"horizontal position P3 = {v}", {"p3": v}) for v in (0, 10.5, 200)],
        *[(f"p5-{name}", f"type P5 = {t} ({name})", {"p5": t}) for t, name in BAR_TYPES.items()],
        *[(f"p5-{BAR_TYPES[t]}-span-4", f"type P5 = {t} spanning all four staves", {"p5": t, "p4": 4}) for t in (2, 5, 8, 9, 10)],
        *[(f"p5-{BAR_TYPES[t]}-span-1", f"type P5 = {t} on one staff", {"p5": t, "p4": 1}) for t in (1, 3, 7, 8, 9)],
        *[(f"p6-thick-{label(v)}-{BAR_TYPES[t]}", f"thickness P6 = {v}, type {t}", {"p6": v, "p5": t})
          for t in (0, 2, 8) for v in (1, 3)],
        *[(f"p7-displace-{label(v)}-{BAR_TYPES[t]}", f"horizontal displacement P7 = {v}, type {t}", {"p7": v, "p5": t})
          for t in (0, 8, 9) for v in (-3, 2)],
        *[(f"p8-dash-{label(v)}", f"dashed bar, dash size P8 = {v}", {"p5": 7, "p8": v}) for v in (0.5, 2)],
        *[(f"p8-partial-bracket-{label(v)}", f"bracket with P8 = {v} (partial bracket)", {"p5": 9, "p8": v}) for v in (1, 2, -1)],
        ("p8-two-bar-number", "two-bar repeat with number P8 = 2", {"p5": -44, "p8": 2}),
        *[(f"p9-space-{label(v)}", f"dashed bar, space P9 = {v}", {"p5": 7, "p9": v}) for v in (0.5, 2)],
        *[(f"p10-bottom-{label(v)}", f"partial bar, bottom origin P10 = {v}", {"p10": v}) for v in (4, -2)],
        *[(f"p11-top-{label(v)}", f"partial bar, top extent P11 = {v}", {"p11": v}) for v in (-4, 3)],
        ("p10-p11-mensurstrich", "bar between staves only: P10 = 8, P11 = -8", {"p10": 8, "p11": -8}),
        *[(f"p12-dots-{label(v)}", f"repeat-dot size P12 = {v}", {"p5": 5, "p12": v}) for v in (0.5, 2)],
        *[(f"p13-space-{label(v)}-{BAR_TYPES[t]}", f"space between bars P13 = {v}, type {t}", {"p5": t, "p13": v})
          for t in (1, 2, 5) for v in (0.5, 2)],
        *[(f"p14-dot-gap-{label(v)}", f"dot-to-line space P14 = {v}", {"p5": 5, "p14": v}) for v in (0.5, 2)],
        *[(f"p16-dots-{v}", f"repeat-dot positions P16 = {v}", {"p5": 3, "p16": v}) for v in (410, 307, 12)],
        *[(f"p18-gap-{label(v)}-{BAR_TYPES[t]}", f"gap centre P18 = {v} %, type {t}", {"p5": t, "p18": v})
          for t in (0, 1) for v in (40, 57)],
        *[(f"p19-gap-size-{label(v)}", f"gap P18 = 50 % with size P19 = {v} steps", {"p18": 50, "p19": v}) for v in (2, 6)],
        ("p25-layer", "layer number P25 = 1", {"p25": 1}),
        *[(f"p26-{name}", f"P26 = {v}", {"p26": v}) for name, v in (("grey-0.5", 0.5), ("red", 990000))],
        ("p26-red-repeat", "repeat bar P5 = 5 in red", {"p5": 5, "p26": 990000}),
    ]
    sweep = [built(f"code14-{name}", desc, four_staves() + [bar(**params)]) for name, desc, params in on_four]
    mixed = [
        ("sizes-span-3", "staves of size 1, 0.7, 1.2; final bar spanning 3",
         [staff(), staff(p2=2, p5=0.7), staff(p2=3, p5=1.2), bar(p4=3, p5=2)]),
        ("sizes-repeat", "repeat bar across staves of size 0.7 and 1",
         [staff(p5=0.7), staff(p2=2), bar(p5=5)]),
        ("p17-double-spacing", "double bar on a size-0.7 staff with P17 = 1",
         [staff(), staff(p2=2), staff(p2=3, p5=0.7), bar(p2=3, p4=1, p5=1, p17=1), bar(p2=1, p4=2, p5=1)]),
        ("lines-3", "barline on a three-line staff", [staff(p7=3), bar(p4=1)]),
        ("staff-offset", "barline spanning staves moved by P4", [staff(), staff(p2=2, p4=4), bar()]),
        ("system", "system: brace, bracket, start bar, middle and final bars",
         four_staves() + [bar(p3=0, p4=2, p5=8, p7=-2), bar(p2=3, p3=0, p4=2, p5=9, p7=-2), bar(p3=0, p4=4),
                          bar(p3=100, p4=4), bar(p3=200, p4=4, p5=2)]),
        ("no-staff", "barline without any staff", [bar(p4=1)]),
    ]
    return sweep + [built(f"code14-{name}", desc, items) for name, desc, items in mixed]
