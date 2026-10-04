"""Code 6 sweeps: beams (analysis/docs/text/winscore/code6.txt, score4/COD06-4.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import Item, built, item, label, staff


def beam(**named: float) -> Item:
    """A single beam over notes at P4 = 9 from P3 = 100 to 130, stems up, unless overridden."""
    base = {"p2": 1, "p3": 100, "p4": 9, "p5": 9, "p6": 130, "p7": 11} | named
    return item(6, **base)


def cases() -> list[Case]:
    one = [
        ("default", "single beam, stems up, horizontal", {}),
        *[(f"p5-right-{label(v)}", f"right end level P5 = {v}", {"p5": v}) for v in (11, 6.5)],
        *[(f"p4-left-{label(v)}", f"left end level P4 = {v}", {"p4": v}) for v in (4, 12.5)],
        ("p6-right-150", "right end P6 = 150", {"p6": 150}),
        *[(f"p7-up-{v % 10}", f"P7 = {v}: {v % 10} beams, stems up", {"p7": v}) for v in (12, 13, 14)],
        *[(f"p7-down-{v % 10}", f"P7 = {v}: {v % 10} beams, stems down", {"p7": v, "p4": 5, "p5": 6})
          for v in (21, 22, 23)],
        ("p7-zero", "P7 = 0", {"p7": 0}),
        *[(f"p9-{v}-up", f"main beam end offsets P9 = {v}, stems up", {"p9": v, "p7": 12}) for v in (100, 200, 300)],
        *[(f"p9-{v}-down", f"main beam end offsets P9 = {v}, stems down", {"p9": v, "p7": 22, "p4": 5, "p5": 5})
          for v in (100, 200, 300)],
        ("p10-partial-11", "one partial beam P10 = 11 from P11 = 110 to P12 = 120",
         {"p7": 11, "p10": 11, "p11": 110, "p12": 120}),
        ("p10-partial-12-slope", "two partials P10 = 12 under a sloped beam",
         {"p7": 11, "p5": 11, "p10": 12, "p11": 105, "p12": 125}),
        ("p10-partial-21", "partial displaced two spacings P10 = 21", {"p7": 11, "p10": 21, "p11": 110, "p12": 120}),
        ("p10-partial-negative", "partial above the main beam P10 = -11", {"p7": 11, "p10": -11, "p11": 110, "p12": 120}),
        ("p10-partial-down", "partial under stems-down beam", {"p7": 21, "p4": 5, "p5": 7, "p10": 11, "p11": 110, "p12": 130}),
        ("p11-main-end", "partial from the main beam's left end P11 = -1", {"p10": 11, "p11": -1, "p12": 115}),
        ("p12-main-end", "partial to the main beam's right end P12 = -1", {"p10": 11, "p11": 115, "p12": -1}),
        ("p11-free-left", "partial with free left end (P11 = 0)", {"p10": 11, "p12": 130}),
        ("p12-free-right", "partial with free right end (P12 = 0)", {"p10": 11, "p11": 100}),
        ("p9-partial-30", "partial end offsets P9 = 30", {"p10": 11, "p11": 110, "p12": 120, "p9": 30}),
        ("p13-second-group", "second partial group P13 = 21, P14 = 120, P15 = 130",
         {"p7": 11, "p10": 11, "p11": 100, "p12": 110, "p13": 21, "p14": 120, "p15": 130}),
        ("p13-second-group-p9", "second group with offsets P9 = 3",
         {"p7": 11, "p10": 11, "p11": 100, "p12": 110, "p13": 21, "p14": 120, "p15": 130, "p9": 3}),
        *[(f"p14-offset-{label(v)}", f"left end note offset P14 = {v} (P13 = 0)", {"p14": v}) for v in (10, 20, 1.5)],
        *[(f"p15-offset-{label(v)}", f"right end note offset P15 = {v} (P13 = 0)", {"p15": v}) for v in (10, -2)],
        *[(f"p17-thick-{label(v)}", f"thickness P17 = {v}", {"p17": v, "p7": 12}) for v in (0.5, 2)],
        *[(f"p18-size-{label(v)}", f"size P18 = {v}", {"p18": v, "p7": 12}) for v in (0.75, 1.3)],
        *[(f"p20-width-{label(v)}", f"note width P20 = {v}", {"p20": v}) for v in (1.5, 0.8)],
        *[(f"p21-space-{label(v)}", f"spacing P21 = {v}", {"p21": v, "p7": 13}) for v in (0.5, 1.5)],
        ("p4-cue", "cue-size beam P4 = 109", {"p4": 109, "p5": 9, "p7": 12}),
        ("p4-cue-p17", "cue-size beam P4 = 109 with P17 = 1.2", {"p4": 109, "p5": 9, "p7": 12, "p17": 1.2}),
        ("trem-across-stem", "tremolo P7 = -10, three beams across the stem at P3 (P11 = 0)",
         {"p7": -10, "p10": 3, "p5": 0, "p6": 0}),
        ("trem-across-stem-down", "tremolo P7 = -20 across a down stem", {"p7": -20, "p10": 2, "p4": 5, "p5": 0, "p6": 0}),
        ("trem-width", "tremolo across the stem, width P12 = 8", {"p7": -10, "p10": 2, "p12": 8, "p5": 0, "p6": 0}),
        ("trem-attached", "tremolo P7 = -10 at P11 = 115 along the beam line",
         {"p7": -10, "p10": 22, "p11": 115, "p5": 11}),
        ("trem-p11-main-end", "tremolo P7 = -10 with P11 = -1", {"p7": -10, "p10": 2, "p11": -1}),
        ("floating-10", "floating beams P7 = 10, P10 = 2", {"p7": 10, "p10": 2}),
        ("floating-20-p11-p12", "floating beams P7 = 20, P10 = 3, P11 = 2, P12 = -2",
         {"p7": 20, "p10": 3, "p11": 2, "p12": -2, "p4": 5, "p5": 5}),
        ("combined-12", "two full beams and floating beams P10 = 22 (P11 = P12 = 0)", {"p7": 12, "p10": 22}),
        ("p25-layer", "layer number P25 = 1", {"p25": 1}),
        *[(f"p26-{name}", f"P26 = {v}", {"p26": v}) for name, v in (("grey-0.5", 0.5), ("red", 990000))],
        *[(f"p8-number-{label(v)}", f"tuplet number P8 = {v}", {"p8": v}) for v in (3, 5, 12, 11)],
        ("p8-number-down", "tuplet number under stems-down beam", {"p8": 3, "p7": 21, "p4": 5, "p5": 7}),
        ("p8-font", "tuplet number in font 12, P8 = 12003", {"p8": 12003}),
        ("p8-font-34", "tuplet number in font 00 (P8 = 34003)", {"p8": 34003}),
        ("p16-number-left", "tuplet number at P16 = 0.3", {"p8": 3, "p16": 0.3}),
        ("p19-number-up", "tuplet number raised P19 = 2", {"p8": 3, "p19": 2}),
        ("p8-number-cue", "tuplet number on a cue beam", {"p8": 3, "p4": 109}),
    ]
    sweep = [built(f"code06-{name}", desc, [staff(), beam(**params)]) for name, desc, params in one]
    other = [
        ("staff-size-0.75", "beam on a staff of size 0.75", [staff(p5=0.75), beam(p7=12)]),
        ("staff-2", "beam on staff 2", [staff(), staff(p2=2), beam(p2=2, p7=22, p4=5, p5=7)]),
        ("recto-201", "beam on recto staff 201", [staff(p2=201), beam(p2=201, p7=12)]),
        ("two-beams", "two beams in one file", [staff(), beam(p7=12), beam(p3=140, p6=170, p7=21, p4=4, p5=5)]),
    ]
    return sweep + [built(f"code06-{name}", desc, items) for name, desc, items in other]
