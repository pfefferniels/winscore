"""Code 5 sweeps: slurs, ties, tuplet brackets, endings (analysis/docs/text/winscore/code5.txt, score4/COD05-4.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import Item, built, item, label, staff


def slur(**named: float) -> Item:
    """A slur over notes at P4 = 9 from P3 = 100 to 130, curving up three steps, unless overridden."""
    base = {"p2": 1, "p3": 100, "p4": 9, "p5": 9, "p6": 130, "p7": 3} | named
    return item(5, **base)


def cases() -> list[Case]:
    slurs = [
        ("default", "slur curving up three scale steps", {}),
        ("p7-down", "slur curving down, P7 = -3", {"p7": -3}),
        *[(f"p7-curve-{label(v)}", f"curvature P7 = {v}", {"p7": v}) for v in (0, 1.5, 6)],
        *[(f"p5-right-{label(v)}", f"right end level P5 = {v}", {"p5": v}) for v in (12, 5.5)],
        ("p6-zero", "P6 = 0 and P7 = 0: P3 + 20 and curvature 3", {"p6": 0, "p7": 0}),
        ("p6-before-p3", "P6 left of P3", {"p6": 95}),
        ("long", "long slur from P3 = 20 to 180", {"p3": 20, "p6": 180, "p7": 5}),
        ("short", "short slur over three P3 units", {"p6": 103, "p7": 1}),
        ("tie", "tie: P8 = -2, curvature 2", {"p8": -2, "p7": 2}),
        *[(f"p8-ends-{label(v)}", f"end placement P8 = {v}", {"p8": v})
          for v in (-1, -3, -4, -5, -6, -7, -8, -9, 11, 15, 0.3)],
        ("p20-width", "end placement P8 = -1 with note width P20 = 1.5", {"p8": -1, "p20": 1.5}),
        *[(f"p9-flatten-{label(v)}", f"flattening P9 = {v}", {"p9": v, "p7": 4}) for v in (2, -1)],
        ("p9-triangle", "triangle P9 = 99", {"p9": 99, "p7": 4}),
        ("p9-triangle-p10-p13", "triangle with peak at P10 = 0.3, P13 = 2 extra strokes", {"p9": 99, "p7": 4, "p10": 0.3, "p13": 2}),
        ("p9-triangle-line", "triangle with P7 = 0: a line", {"p9": 99, "p7": 0}),
        *[(f"p10-centre-{label(v)}", f"centre of curvature P10 = {v}", {"p10": v}) for v in (0.3, 0.75)],
        ("p11-dashes", "dashes P11 = 1", {"p11": 1, "p6": 160}),
        ("p11-dashes-5", "five dashes P11 = 5", {"p11": 5}),
        ("p11-dashes-sloped", "dashes on a sloped slur", {"p11": 1, "p6": 160, "p5": 12}),
        ("p11-dots", "dots P11 = -1", {"p11": -1, "p6": 160}),
        ("p11-dots-8", "eight dots P11 = -8", {"p11": -8}),
        *[(f"p12-half-{v}", f"half slur P12 = {v}", {"p12": v}) for v in (1, 2)],
        ("p12-half-sloped", "right half slur on a slope", {"p12": 2, "p5": 12}),
        ("p12-reverse", "change of direction P12 = -1", {"p12": -1, "p6": 150}),
        ("p12-half-dashes", "dashed left half slur", {"p12": 1, "p11": 3}),
        *[(f"p13-thick-{label(v)}", f"thickness P13 = {v}", {"p13": v}) for v in (0.5, 1.5)],
        ("p19-thicken", "thickness reached at P19 = 0.5", {"p19": 0.5, "p13": 1.5}),
        ("p14-start", "visible part from P14 = 0.3", {"p14": 0.3}),
        ("p14-start-negative", "P14 = -0.4", {"p14": -0.4}),
        ("p15-end", "visible part up to P15 = 0.7", {"p15": 0.7}),
        ("p14-p15", "visible part from P14 = 0.2 to P15 = 0.6", {"p14": 0.2, "p15": 0.6}),
        ("p14-sloped", "P14 = 0.4 on a sloped slur", {"p14": 0.4, "p5": 12}),
        ("p14-dashes", "dashes from P14 = 0.4", {"p14": 0.4, "p11": 1, "p6": 160}),
        ("p15-dashes", "dashes up to P15 = 0.6", {"p15": 0.6, "p11": 1, "p6": 160}),
        ("p16-offsets", "end offsets P16 = 1, P17 = 2, P18 = -1.5", {"p16": 1, "p17": 2, "p18": -1.5, "p8": -1}),
        ("p16-number", "number 3 in a broken slur, P16 = 3", {"p16": 3}),
        ("p16-number-12", "number 12 in a broken slur", {"p16": 12}),
        ("p16-number-below", "number under an unbroken slur, P16 = -3", {"p16": -3}),
        ("p16-number-sloped", "number in a sloped slur", {"p16": 3, "p5": 12}),
        ("p16-number-p17-p18", "number moved by P17 = 1, P18 = 1", {"p16": 3, "p17": 1, "p18": 1}),
        ("p27-slash", "slash P27 = 3", {"p27": 3}),
        ("p27-slash-p28-p29", "slash P27 = 2 raised P28 = 1 at P29 = 0.3", {"p27": 2, "p28": 1, "p29": 0.3}),
        ("p27-slash-sloped", "slash on a sloped slur", {"p27": 3, "p5": 12}),
        ("p25-layer", "layer number P25 = 1", {"p25": 1}),
        *[(f"p26-{name}", f"P26 = {v}", {"p26": v}) for name, v in (("grey-0.5", 0.5), ("red", 990000))],
    ]
    brackets = [
        ("tuplet", "tuplet bracket P8 = 3", {"p8": 3, "p7": 5}),
        ("tuplet-down", "tuplet bracket below, P7 = -4", {"p8": 3, "p7": -4}),
        ("tuplet-sloped", "sloped tuplet bracket, P5 = 12", {"p8": 3, "p7": 5, "p5": 12}),
        ("tuplet-p9-5", "tuplet bracket with 5, P9 = 5", {"p8": 3, "p7": 5, "p9": 5}),
        ("tuplet-p9-12", "tuplet bracket with 12, P9 = 12", {"p8": 3, "p7": 5, "p9": 12}),
        ("tuplet-p9-open", "tuplet bracket with open space P9 = -3", {"p8": 3, "p7": 5, "p9": -3}),
        ("tuplet-p10", "tuplet number at P10 = 0.3", {"p8": 3, "p7": 5, "p10": 0.3}),
        *[(f"tuplet-p11-{v}", f"tuplet bracket P11 = {v}", {"p8": 3, "p7": 5, "p11": v}) for v in (1, 2, 3)],
        ("tuplet-p12", "tuplet bracket right hook lengthened P12 = 2", {"p8": 3, "p7": 5, "p12": 2}),
        *[(f"tuplet-p13-{v}", f"tuplet bracket P13 = {v} (open ends)", {"p8": 3, "p7": 5, "p13": v}) for v in (1, 2, 3)],
        ("tuplet-p14-font", "tuplet number in font 12, P14 = 12", {"p8": 3, "p7": 5, "p14": 12}),
        ("tuplet-p20", "tuplet bracket with P20 = 1.5", {"p8": 3, "p7": 5, "p20": 1.5}),
        ("tuplet-p21", "tuplet number size P21 = 1.2", {"p8": 3, "p7": 5, "p21": 1.2}),
        ("tuplet-p23", "tuplet gap P23 = 2", {"p8": 3, "p7": 5, "p23": 2}),
        ("ending-1", "first ending P8 = 1", {"p8": 1, "p7": 5, "p4": 10, "p5": 10}),
        ("ending-2", "second ending P8 = 2", {"p8": 2, "p7": 5, "p4": 10, "p5": 10}),
        ("ending-1-continued", "first ending continued, P9 = -1", {"p8": 1, "p9": -1, "p7": 5, "p4": 10, "p5": 10}),
        ("ending-1-no-number", "first ending without number, P9 = -2", {"p8": 1, "p9": -2, "p7": 5, "p4": 10, "p5": 10}),
        ("ending-2-open", "second ending open, P9 = -1", {"p8": 2, "p9": -1, "p7": 5, "p4": 10, "p5": 10}),
        ("ending-4-p9-3", "third ending P8 = 4, P9 = 3", {"p8": 4, "p9": 3, "p7": 5, "p4": 10, "p5": 10}),
        *[(f"ending-p13-{label(v)}", f"first ending P13 = {v}", {"p8": 1, "p13": v, "p7": 5, "p4": 10, "p5": 10})
          for v in (1, 2, 3, 0.5)],
        ("ending-p12-size", "first ending stop size P12 = 1.5", {"p8": 1, "p12": 1.5, "p7": 5, "p4": 10, "p5": 10}),
    ]
    sweep = [built(f"code05-{name}", desc, [staff(), slur(**params)]) for name, desc, params in slurs + brackets]
    other = [
        ("staff-size-0.75", "slur on a staff of size 0.75", [staff(p5=0.75), slur()]),
        ("staff-2", "slur on staff 2", [staff(), staff(p2=2), slur(p2=2, p7=-3)]),
        ("recto-201", "slur on recto staff 201", [staff(p2=201), slur(p2=201)]),
        ("two-slurs", "two slurs in one file", [staff(), slur(), slur(p3=140, p6=170, p7=-2, p4=4, p5=6)]),
    ]
    return sweep + [built(f"code05-{name}", desc, items) for name, desc, items in other]
