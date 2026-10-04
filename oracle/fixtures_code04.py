"""Code 4 fixtures: lines, dashes, dots, wavy lines, hairpins, brackets, arrows, multipoint lines."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, staff


def line(**named: float) -> list[float]:
    """A line on staff 1 from (P3 20, P4 5) to (P6 80, P5 5) unless overridden."""
    base = {"p2": 1, "p3": 20, "p4": 5, "p5": 5, "p6": 80} | named
    return item(4, **base)


def vertical(**named: float) -> list[float]:
    """P6 = 0: vertical forms (wavy arpeggio, vertical line) from P4 2 to P5 12 at P3 50."""
    return line(**({"p3": 50, "p4": 2, "p5": 12, "p6": 0} | named))


def hairpin(**named: float) -> list[float]:
    return line(**({"p4": 7, "p5": 999} | named))


CASES: list[tuple[str, str, list[float]]] = [
    # plain lines
    ("p0-horizontal", "plain horizontal line", line()),
    ("p4p5-up", "tilted line, P4 3 to P5 9", line(p4=3, p5=9)),
    ("p4p5-down", "tilted line, P4 10 to P5 2", line(p4=10, p5=2)),
    ("p4p5-fraction", "tilted line, P4 4.3 to P5 6.7", line(p4=4.3, p5=6.7)),
    ("p6-vertical", "vertical line, P6 = P3", line(p3=50, p6=50, p4=2, p5=12)),
    ("p6-reversed", "P6 left of P3", line(p3=80, p6=20, p4=3, p5=8)),
    ("p3-fraction", "P3 20.3 to P6 77.7", line(p3=20.3, p6=77.7)),
    ("p5p6-missing", "P5 = P6 = 0: engine message, default length and thickness", line(p5=0, p6=0)),
    # thickness
    ("p10-thick-1", "horizontal, P10 1", line(p10=1)),
    ("p10-thick-3", "horizontal, P10 3", line(p10=3)),
    ("p10-thick-steep", "steep line, P10 1", line(p4=1, p5=12, p6=30)),
    ("p10-thick-negative", "horizontal, P10 -1", line(p10=-1)),
    ("p10-thick-vertical", "vertical line, P10 2", line(p3=50, p6=50, p4=2, p5=12, p10=2)),
    # brackets and arrows
    ("p11-bracket-up", "left bracket, P11 2", line(p11=2)),
    ("p11-bracket-down", "left bracket, P11 -2", line(p11=-2)),
    ("p12-bracket-up", "right bracket, P12 1.5", line(p12=1.5)),
    ("p12-bracket-down", "right bracket, P12 -3", line(p12=-3)),
    ("p11p12-brackets", "both brackets on a tilted line", line(p4=3, p5=7, p11=-2, p12=-2)),
    ("p11-arrow", "left arrow, P11 101", line(p11=101)),
    ("p12-arrow", "right arrow, P12 101", line(p12=101)),
    ("p12-arrow-wide", "right arrow, P12 102.5", line(p12=102.5)),
    ("p11p12-arrows", "arrows at both ends, tilted", line(p4=3, p5=9, p11=101, p12=101)),
    ("p11-updown", "left bracket up and down, P11 202", line(p11=202)),
    ("p12-updown", "right bracket up and down, P12 201", line(p12=201)),
    # rotation
    ("p13-rotation-30", "plain line, P13 30", line(p13=30)),
    ("p13-rotation-m45", "plain line, P13 -45", line(p13=-45)),
    ("p13-rotation-90", "plain line, P13 90", line(p13=90)),
    ("p13-rotation-arrow", "line with right arrow, P13 -20", line(p12=101, p13=-20)),
    ("p9-rotation", "plain line, P9 20 (SCORE 4 rotation)", line(p9=20)),
    # end offsets
    ("p16-offsets", "P16 1 with left offset P17 2, right offset P18 -3", line(p16=1, p17=2, p18=-3)),
    ("p16-offsets-zero", "P17/P18 set without P16", line(p17=2, p18=-3)),
    # dashes
    ("p7-dashes", "dashes, P7 1", line(p7=1)),
    ("p7-dashes-2", "P7 2 draws dashes too", line(p7=2)),
    ("p8-dash-length", "dashes, P8 2", line(p7=1, p8=2)),
    ("p8-dash-short", "dashes, P8 0.4", line(p7=1, p8=0.4)),
    ("p9-dash-space", "dashes, P8 1.5, P9 0.5", line(p7=1, p8=1.5, p9=0.5)),
    ("p7-dashes-tilted", "tilted dashes, P4 3 to P5 9", line(p7=1, p4=3, p5=9)),
    ("p7-dashes-same-ip", "dashes, P4 5, P5 5.6 (same integer level)", line(p7=1, p5=5.6)),
    ("p7-dashes-vertical", "vertical dashes, P6 = P3", line(p7=1, p3=50, p6=50, p4=2, p5=12)),
    ("p8p9-dashes-vertical", "vertical dashes, P8 2, P9 1", line(p7=1, p3=50, p6=50, p4=2, p5=12, p8=2, p9=1)),
    ("p7-dashes-rotated", "dashes, P13 30", line(p7=1, p13=30)),
    ("p7-dashes-bracket", "dashes with right bracket P12 2", line(p7=1, p12=2)),
    ("p7-dashes-thick", "dashes, P10 1", line(p7=1, p10=1)),
    # dots
    ("p7-dots", "dotted line, P7 -4", line(p7=-4)),
    ("p8-dot-size", "dotted line, P8 2", line(p7=-4, p8=2)),
    ("p9-dot-space", "dotted line, P9 1", line(p7=-4, p9=1)),
    ("p7-dots-rotated", "dotted line, P13 -30", line(p7=-4, p13=-30)),
    # wavy lines
    ("p7-wavy", "heavy wavy line, P7 -1", line(p7=-1)),
    ("p8-wavy-unit", "heavy wavy line, P8 2", line(p7=-1, p8=2)),
    ("p9-wavy-height", "heavy wavy line, P9 2", line(p7=-1, p9=2)),
    ("p12-wavy-arrow", "heavy wavy line with arrow, P12 100", line(p7=-1, p12=100)),
    ("p13-wavy-rotated", "heavy wavy line, P13 20", line(p7=-1, p13=20)),
    ("p10-wavy-thick", "heavy wavy line, P10 1 (ignored)", line(p7=-1, p10=1)),
    ("p7-wavy-vertical", "vertical heavy wavy line (arpeggio)", vertical(p7=-1)),
    ("p12-wavy-vertical-up", "arpeggio with arrow up, P12 100", vertical(p7=-1, p12=100)),
    ("p12-wavy-vertical-down", "arpeggio with arrow down, P12 -100", vertical(p7=-1, p12=-100)),
    ("p15-wavy-vertical", "arpeggio, P15 3", vertical(p7=-1, p15=3)),
    ("p8-wavy-vertical", "arpeggio, P8 1.5, P9 0.7", vertical(p7=-1, p8=1.5, p9=0.7)),
    ("p6eqp3-wavy-vertical", "arpeggio with P6 = P3", vertical(p7=-1, p6=50)),
    ("p7-thin", "thin wavy line, P7 -2", line(p7=-2)),
    ("p12-thin-arrow", "thin wavy line with arrow, P12 100", line(p7=-2, p12=100)),
    ("p8p9-thin", "thin wavy line, P8 2, P9 0.5", line(p7=-2, p8=2, p9=0.5)),
    ("p10-thin-thick", "thin wavy line, P10 1", line(p7=-2, p10=1)),
    ("p7-thin-vertical", "vertical thin wavy line", vertical(p7=-2)),
    ("p7-saw", "sawtooth line, P7 -3", line(p7=-3)),
    ("p8p9-saw", "sawtooth line, P8 1.5, P9 2", line(p7=-3, p8=1.5, p9=2)),
    ("p11-saw-thick", "sawtooth with thick down slopes, P11 0.5", line(p7=-3, p11=0.5)),
    ("p10-saw-thick", "sawtooth line, P10 1", line(p7=-3, p10=1)),
    # quick vertical lines
    ("p7-vertical", "vertical line, P7 -5", vertical(p7=-5)),
    ("p15-vertical", "vertical line, P7 -5, P15 2", vertical(p7=-5, p15=2)),
    ("p11p12-vertical-brackets", "vertical line with brackets P11 1, P12 -1", vertical(p7=-5, p11=1, p12=-1)),
    ("p12-vertical-arrow", "vertical line with arrow, P12 101", vertical(p7=-5, p12=101)),
    ("p11-vertical-updown", "vertical line, P11 201", vertical(p7=-5, p11=201)),
    ("p10-vertical-thick", "vertical line, P7 -5, P10 1", vertical(p7=-5, p10=1)),
    ("p13-vertical-rotated", "vertical line, P7 -5, P13 -60 (portamento)", vertical(p7=-5, p13=-60)),
    # hairpins
    ("p5-cresc", "crescendo hairpin, P5 999", hairpin()),
    ("p7-decresc", "decrescendo hairpin, P7 -1", hairpin(p7=-1)),
    ("p7-cresc-spread", "crescendo, P7 3.5", hairpin(p7=3.5)),
    ("p7-decresc-spread", "decrescendo, P7 -4", hairpin(p7=-4)),
    ("p10-cresc-thick", "crescendo, P10 1", hairpin(p10=1)),
    ("p13-cresc-rotated", "crescendo, P13 10", hairpin(p13=10)),
    ("p9-cresc-rotated", "crescendo, P9 -10 (SCORE 4 rotation)", hairpin(p9=-10)),
    ("p11-cresc-dashed", "dashed crescendo, P11 1", hairpin(p11=1)),
    ("p11-decresc-dashed", "dashed decrescendo, P11 1, P7 -1", hairpin(p11=1, p7=-1)),
    ("p11-cresc-dashed-spread", "dashed crescendo, P7 3, P8 0.5", hairpin(p11=1, p7=3, p8=0.5)),
    ("p11-cresc-dashed-thick", "dashed crescendo, P10 1", hairpin(p11=1, p10=1)),
    ("p14-cresc-partial", "crescendo, P14 0.5", hairpin(p14=0.5)),
    ("p14-cresc-negative", "crescendo, P14 -0.4", hairpin(p14=-0.4)),
    ("p14-cresc-percent", "crescendo, P14 48", hairpin(p14=48)),
    ("p15-cresc-partial", "crescendo, P15 0.6", hairpin(p15=0.6)),
    ("p14p15-cresc-inner", "crescendo, P14 0.3, P15 0.7", hairpin(p14=0.3, p15=0.7)),
    ("p14p15-cresc-gap", "crescendo gap, P14 0.455, P15 -3", hairpin(p14=0.455, p15=-3)),
    ("p14-decresc-partial", "decrescendo, P14 0.5", hairpin(p7=-1, p14=0.5)),
    ("p15-decresc-partial", "decrescendo, P15 0.6", hairpin(p7=-1, p15=0.6)),
    ("p14p15-decresc-inner", "decrescendo, P14 0.3, P15 0.7", hairpin(p7=-1, p14=0.3, p15=0.7)),
    # multipoint lines
    ("p7-multipoint", "multipoint line through two points", line(p7=100, p8=35, p9=9, p10=55, p11=2)),
    ("p7-multipoint-5", "multipoint line through five points",
     line(p7=100, p8=28, p9=8, p10=36, p11=10, p12=48, p13=9, p14=60, p15=6, p16=70, p17=4)),
    ("p18-multipoint-scale", "multipoint, P18 1.5", line(p7=100, p8=35, p9=9, p10=55, p11=2, p18=1.5)),
    ("p19-multipoint-scale", "multipoint, P18 0.8, P19 2", line(p7=100, p8=35, p9=9, p10=55, p11=2, p18=0.8, p19=2)),
    ("p20-multipoint-rotated", "multipoint, P20 15", line(p7=100, p8=35, p9=9, p10=55, p11=2, p20=15)),
    ("p21-multipoint-thick", "multipoint, P21 1", line(p7=100, p8=35, p9=9, p10=55, p11=2, p21=1)),
    # colour, layer
    ("p25-layer", "plain line, P25 2", line(p25=2)),
    ("p26-grey", "plain line, P26 0.5", line(p26=0.5)),
    ("p26-red-hairpin", "hairpin, P26 900000", hairpin(p26=900000)),
]


def sized(size: float, *items: list[float]) -> list[list[float]]:
    return [staff(p5=size), *items]


SIZED: list[tuple[str, str, list[list[float]]]] = [
    ("size-0.75-wavy", "heavy wavy line on a size 0.75 staff", sized(0.75, line(p7=-1))),
    ("size-0.75-cresc", "crescendo on a size 0.75 staff", sized(0.75, hairpin())),
    ("size-0.75-dashes", "dashes on a size 0.75 staff", sized(0.75, line(p7=1, p4=3, p5=8))),
    ("size-0.75-arrows", "arrows and brackets on a size 0.75 staff", sized(0.75, line(p11=-2, p12=101))),
    ("size-0.75-arpeggio", "arpeggio on a size 0.75 staff", sized(0.75, vertical(p7=-1, p12=100))),
    ("size-1.3-saw", "sawtooth on a size 1.3 staff", sized(1.3, line(p7=-3, p11=0.5))),
    ("staff-2", "line on staff 2", [staff(), staff(p2=2), line(p2=2, p4=3, p5=9)]),
    ("recto", "line on the recto staff 201", [staff(p2=201), line(p2=201, p11=101)]),
    ("several", "a line, a hairpin and a wavy line", [staff(), line(p4=10, p5=10), hairpin(p4=6), line(p7=-1, p4=0, p5=0)]),
]


def cases() -> list[Case]:
    return ([built(f"code04-{name}", desc, [staff(), it]) for name, desc, it in CASES]
            + [built(f"code04-{name}", desc, items) for name, desc, items in SIZED])
