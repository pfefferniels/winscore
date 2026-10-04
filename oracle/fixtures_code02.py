"""Code 2 sweeps: rests (analysis/docs/text/winscore/code2.txt).

Every case is one rest on staff 1 (size 1) unless it says otherwise; the base
rest is a quarter rest at P3 = 20 in its default position (P4 = 0).
"""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import Item, built, item, label, staff

TYPES = {0: "quarter", 1: "eighth", 2: "sixteenth", 3: "32nd", 4: "64th", 5: "128th", 6: "256th",
         -1: "half", -2: "whole", -3: "multi-bar", -4: "repeat", -5: "h-bar", -6: "two-bar", -7: "four-bar"}


def rest(**named: float) -> Item:
    base = {"p2": 1, "p3": 20, "p4": 0, "p5": 0, "p6": 0, "p7": 1} | named
    return item(2, **base)


def single(name: str, description: str, **named: float) -> Case:
    return built(f"code02-{name}", description, [staff(), rest(**named)])


def types() -> list[Case]:
    plain = [single(f"p5-{name}", f"P5 = {t}: {name} rest", p5=t) for t, name in TYPES.items()]
    european = [single(f"p5-composite-{label(t)}", f"P5 = {t}: composite rest", p5=t) for t in range(-11, -20, -1)]
    return plain + european + [
        *[single(f"p5-unused-{label(t)}", f"P5 = {t} (not drawn)", p5=t) for t in (-8, -9, -10, -20)],
        single("p5-hundreds-0", "P5 = 100: quarter rest, hundreds flag", p5=100),
        single("p5-hundreds-m2", "P5 = -102: whole rest, hundreds flag", p5=-102),
        single("p5-hundreds-m1", "P5 = -101: half rest, hundreds flag", p5=-101),
        single("p5-hundreds-1", "P5 = 101: eighth rest, hundreds flag", p5=101),
        single("p5-hundreds-m101-p9", "P5 = -101 with P9 = 30", p5=-101, p9=30),
        single("p5-two-bar-repeat", "P5 = -44: two-bar repeat", p5=-44),
        single("p5-two-bar-repeat-p8", "P5 = -44 with P8 = 2", p5=-44, p8=2),
        single("p5-h-bar-p9", "P5 = -5, right end P9 = 60", p5=-5, p9=60),
        single("p5-h-bar-p9-number", "P5 = -5, P9 = 60, number P8 = 8", p5=-5, p9=60, p8=8),
    ]


def positions() -> list[Case]:
    return [
        *[single(f"p4-{label(v)}-quarter", f"quarter rest P4 = {v}", p4=v) for v in (-4, 3, 2.5)],
        *[single(f"p4-{label(v)}-whole", f"whole rest P4 = {v}", p4=v, p5=-2) for v in (-8, -7, -2, 2, 3, 4, 6)],
        *[single(f"p4-{label(v)}-half", f"half rest P4 = {v}", p4=v, p5=-1) for v in (-7, -6, 2, 4, 5, 7)],
        single("p4-4-eighth", "eighth rest P4 = 4", p4=4, p5=1),
        single("p4-m3-sixteenth", "sixteenth rest P4 = -3", p4=-3, p5=2),
        single("p3-20.3", "P3 = 20.3", p3=20.3),
        single("p30-m1-whole", "whole rest P4 = 4 with P30 = -1 (no ledger line)", p4=4, p5=-2, p30=-1),
    ]


def dots() -> list[Case]:
    return [
        *[single(f"p6-dots-{d}-{TYPES[t]}", f"{d} dot(s) on a {TYPES[t]} rest", p5=t, p6=d)
          for t in (0, 1, 2, 3, 4, -1, -2) for d in (1, 2)],
        single("p6-dots-3", "three dots on a quarter rest", p6=3),
        single("p6-dots-1.5", "P6 = 1.5: dot moved right", p6=1.5),
        single("p6-dot-p4", "dotted eighth rest P4 = 3", p5=1, p6=1, p4=3),
        single("p6-invisible", "P6 = -1: invisible rest", p6=-1),
        single("p6-invisible-whole", "P6 = -1: invisible whole rest", p6=-1, p5=-2),
        *[single(f"p6-line-{v}-{TYPES[t]}", f"P6 = {v}: centring line, {TYPES[t]} rest", p6=v, p5=t)
          for t in (0, -2, -3) for v in (6, 12)],
        single("p6-multi-bar-dots", "P6 = 2 on a multi-bar rest (dots dropped)", p5=-3, p6=2),
        single("p6-composite-spacing", "P6 = 1.5 on a composite rest", p5=-15, p6=1.5),
    ]


def numbers() -> list[Case]:
    return [
        *[single(f"p8-number-{v}", f"number P8 = {v} over a multi-bar rest", p5=-3, p8=v) for v in (3, 12, 123)],
        single("p8-number-whole", "number P8 = 5 over a whole rest", p5=-2, p8=5),
        single("p8-number-quarter", "number P8 = 5 over a quarter rest", p8=5),
        single("p8-number-eighth", "number P8 = 11 over an eighth rest", p5=1, p8=11),
        single("p8-number-101", "number P8 = 101 over a multi-bar rest", p5=-3, p8=101),
        single("p8-number-111", "number P8 = 111 over a multi-bar rest", p5=-3, p8=111),
        single("p8-number-211", "number P8 = 211 over a multi-bar rest", p5=-3, p8=211),
        *[single(f"p8-{name}-{TYPES[t]}", f"P8 = {v}: {name} over a {TYPES[t]} rest", p8=v, p5=t)
          for v, name in ((-1, "fermata"), (-2, "inverted-fermata")) for t in (0, 1, -1, -2)],
        single("p8-m3", "P8 = -3 over a quarter rest", p8=-3),
        single("p11-height-3", "number height P11 = 3", p5=-3, p8=4, p11=3),
        single("p11-fermata-height", "fermata height P11 = -2", p8=-1, p11=-2),
        single("p12-size-1.5", "number size P12 = 1.5", p5=-3, p8=4, p12=1.5),
        single("p12-fermata-size", "fermata size P12 = 1.5", p8=-1, p12=1.5),
        single("p14-font-2", "number font P14 = 2", p5=-3, p8=4, p14=2),
        single("p16-move-2", "number moved P16 = 2", p5=-3, p8=4, p16=2),
        single("p16-fermata-move", "fermata moved P16 = -1.5", p8=-1, p16=-1.5),
        single("p20-spread-1", "number digits spread P20 = 1", p5=-3, p8=24, p20=1),
        single("p8-number-p4", "number over a multi-bar rest at P4 = 4", p5=-3, p8=4, p4=4),
    ]


def centring() -> list[Case]:
    bars = [item(14, 1, 10, 1), item(14, 1, 60, 1)]
    with_bars = [
        ("p9-cw-whole", "whole rest centred between barlines (P9 = -1)", {"p5": -2, "p9": -1}),
        ("p9-cw-multi-bar", "multi-bar rest centred between barlines", {"p5": -3, "p9": -1}),
        ("p9-cw-repeat", "repeat sign centred between barlines", {"p5": -4, "p9": -1}),
        ("p9-cw-h-bar", "h-bar rest spread between barlines", {"p5": -5, "p9": -1}),
        ("p9-cw-composite", "composite rest centred between barlines", {"p5": -15, "p9": -1}),
    ]
    return [
        *[built(f"code02-{name}", desc, [staff(), *bars, rest(**params)]) for name, desc, params in with_bars],
        single("p9-30-whole", "whole rest drawn at P9 = 30", p5=-2, p9=30),
        single("p9-30-multi-bar", "multi-bar rest drawn at P9 = 30", p5=-3, p9=30),
        single("p9-30-quarter", "quarter rest with P9 = 30", p9=30),
    ]


def others() -> list[Case]:
    three = [staff(), staff(p2=2), staff(p2=3)]
    return [
        *[single(f"p10-{label(v)}", f"offset P10 = {v}", p10=v) for v in (2, -3)],
        single("p10-whole", "offset P10 = 2 on a whole rest", p10=2, p5=-2),
        *[single(f"p15-{label(v)}-{TYPES[t]}", f"rest size P15 = {v}, {TYPES[t]}", p15=v, p5=t)
          for v in (0.75, 1.3) for t in (0, 2, -2)],
        single("p15-dot-number", "P15 = 0.75 with dot and fermata", p15=0.75, p6=1, p8=-1),
        *[built(f"code02-p17-{v}", f"rest on staff 2 shown on staff {'above' if v == 1 else 'below'} (P17 = {v})",
                three + [rest(p2=2, p17=v)]) for v in (1, 2)],
        *[single(f"grace-{TYPES[t]}", f"grace-size {TYPES[t]} rest (P4 = 100)", p4=100, p5=t) for t in (0, 1, 2, -1, -2)],
        single("grace-p4-103", "grace quarter rest P4 = 103", p4=103),
        single("grace-dot", "grace quarter rest with a dot", p4=100, p6=1),
        single("grace-fermata", "grace quarter rest with a fermata", p4=100, p8=-1),
        single("p26-grey", "grey rest P26 = 0.5", p26=0.5),
        single("p13-cue", "cue instrument P13 = 3", p13=3),
        *[built(f"code02-staff-{label(s)}-{name}", f"staff size {s}: {desc}", [staff(p5=s), rest(**params)])
          for s in (0.73, 1.3)
          for name, desc, params in (("quarter", "quarter rest", {}), ("sixteenth-dot", "dotted sixteenth", {"p5": 2, "p6": 1}),
                                     ("whole-number", "whole rest with number 3", {"p5": -2, "p8": 3}))],
        built("code02-staff-recto", "rest on staff 201 (recto page)", [staff(p2=201), rest(p2=201)]),
    ]


def mixed() -> list[Case]:
    rests = [rest(p3=12 + 14 * i, p5=t) for i, t in enumerate((0, 1, 2, 3, 4, -1, -2, -3, -4))]
    rests += [rest(p3=150, p5=1, p6=1), rest(p3=165, p5=-2, p4=4), rest(p3=180, p8=-1)]
    return [built("code02-mixed-bar", "twelve rests of different kinds on one staff", [staff()] + rests)]


def cases() -> list[Case]:
    return types() + positions() + dots() + numbers() + centring() + others() + mixed()
