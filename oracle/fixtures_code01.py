"""Code 1 sweeps: notes (analysis/docs/text/winscore/code1.txt).

Every case is one note on staff 1 (size 1) unless it says otherwise; the base
note is a quarter at P3 = 20 on the second line (P4 = 5) with the stem up.
"""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import Item, built, item, label, staff
from fixtures_code16 import text

HEADS = {0: "black", 1: "half", 2: "whole", 3: "breve", 4: "white-diamond", 5: "black-diamond",
         6: "x", 7: "headless", 8: "diamond-x", 9: "oval-x"}
ACCIDENTALS = {1: "flat", 2: "sharp", 3: "natural", 4: "double-flat", 5: "double-sharp",
               6: "quarter-flat", 7: "three-quarter-flat", 8: "quarter-sharp", 9: "three-quarter-sharp"}


def note(**named: float) -> Item:
    base = {"p2": 1, "p3": 20, "p4": 5, "p5": 10, "p6": 0, "p7": 1} | named
    return item(1, **base)


def single(name: str, description: str, **named: float) -> Case:
    return built(f"code01-{name}", description, [staff(), note(**named)])


def stems(name: str, description: str, **named: float) -> list[Case]:
    """The same note with the stem up and down; a P5 given is the accidental digit."""
    accidental = named.pop("p5", 0)
    return [single(f"{name}-{d}", f"{description}, stem {d}", p5=accidental + p5, **named)
            for d, p5 in (("up", 10), ("down", 20))]


def positions() -> list[Case]:
    up = [single(f"p4-{label(v)}", f"P4 = {v}", p4=v) for v in (-4, -1, 0, 1, 2, 3, 6, 7, 11, 12, 13, 14, 15, 18)]
    down = [single(f"p4-{label(v)}-down", f"P4 = {v}, stem down", p4=v, p5=20) for v in (-4, 0, 7, 9, 15)]
    return up + down + [
        single("p4-5.5", "P4 = 5.5 (between levels)", p4=5.5),
        single("p3-20.3", "P3 = 20.3", p3=20.3),
        single("p5-no-stem", "P5 = 0, no stem", p5=0),
    ]


def accidentals() -> list[Case]:
    plain = [single(f"p5-{name}", f"P5 = {10 + a}: {name}", p5=10 + a) for a, name in ACCIDENTALS.items()]
    paren = [single(f"p5-paren-{ACCIDENTALS[a]}", f"P5 = {110 + a}: {ACCIDENTALS[a]} in parentheses", p5=110 + a)
             for a in (1, 2, 3, 4, 5, 6)]
    return plain + paren + [
        single("p5-no-stem-sharp", "P5 = 2: sharp, no stem", p5=2),
        single("p5-sharp-down", "P5 = 22: sharp, stem down", p5=22),
        single("p5-displace-left-2.5", "P5 = 12.25: sharp 2.5 steps left", p5=12.25),
        single("p5-displace-left-0.5", "P5 = 11.05: flat 0.5 steps left", p5=11.05),
        single("p5-displace-right-0.35", "P5 = 12.935: sharp 0.35 steps right", p5=12.935),
        single("p5-sharp-p10-10", "sharp with the head offset right (P10 = 10)", p5=12, p10=10),
        single("p5-sharp-p10-20", "sharp with the head offset left (P10 = 20)", p5=12, p10=20),
        single("p5-sharp-p10-110", "sharp moving with the head (P10 = 110)", p5=12, p10=110),
        single("p5-sharp-p10-2.5", "sharp with P10 = 2.5", p5=12, p10=2.5),
        single("p5-flat-ledger", "flat on a ledger note (P4 = -1)", p5=11, p4=-1),
    ]


def heads() -> list[Case]:
    plain = [single(f"p6-{name}", f"P6 = {h}: {name} head", p6=h) for h, name in HEADS.items()]
    paren = [single(f"p6-paren-{HEADS[h]}", f"P6 = {10 + h}: {HEADS[h]} head in parentheses", p6=10 + h)
             for h in (0, 1, 2, 4, 6, 9)]
    return plain + paren + [
        *stems("p6-half", "half note", p6=1),
        single("p6-whole-down", "whole head with P5 = 20 (no stem)", p6=2, p5=20),
        single("p6-paren-flat", "parenthesised head with a flat", p6=10, p5=11),
        single("p6-paren-double-flat", "parenthesised head with a double flat", p6=10, p5=14),
        single("p6-paren-dot", "parenthesised head with a dot", p6=10, p9=10),
        single("p6-paren-two-dots", "parenthesised head with two dots", p6=10, p9=20),
        single("p6-paren-width", "parenthesised head, note width P20 = 1.4", p6=10, p20=1.4),
        single("p6-headless-m1", "P6 = -1: headless", p6=-1),
        single("p6-m3", "P6 = -3", p6=-3),
        *[single(f"p6-library-{v}", f"library symbol {v} as head", p6=v) for v in (30, 38, 95, 103, 139, 208)],
        single("p6-library-stem-down", "library symbol 30 as head, stem down", p6=30, p5=20),
        *[single(f"p6-alpha-{label(v)}", f"P6 = {v}: AlphaNote", p6=v) for v in (20, 21, 22, 23, 24, 25, -20, -23)],
        single("p6-alpha-m20-space", "P6 = -20: hollow AlphaNote in a space", p6=-20, p4=4),
        single("p6-alpha-down", "AlphaNote with the stem down", p6=20, p5=20),
        single("p6-alpha-p15", "AlphaNote at P15 = 0.8", p6=20, p15=0.8),
        single("p6-alpha-p21", "AlphaNote with P21 = 2, P22 = 1, P23 = 1, P24 = 1.5", p6=20, p21=2, p22=1, p23=1, p24=1.5),
        single("p6-tab-m6", "P6 = -6: six-string tablature", p6=-6, p4=3),
        *tablature(),
        single("p6-x-down", "X head, stem down", p6=6, p5=20),
        single("p6-diamond-down", "white diamond, stem down", p6=4, p5=20),
    ]


def tablature() -> list[Case]:
    """P6 = -n: a fret number for an n-string instrument (no help text beyond that)."""
    tab = {"p6": -6, "p5": 0}
    return [
        *[single(f"p6-tab-p4-{label(v)}", f"six-string tablature P4 = {v}", **tab, p4=v) for v in (-3, 0, 7, 10, 14, 21)],
        *[single(f"p6-tab-p5-{v}", f"six-string tablature P5 = {v}", **(tab | {"p5": v}), p4=5) for v in (1, 2, 11, 22)],
        *[single(f"p6-tab-strings-{label(v)}", f"tablature P6 = {v}", p6=v, p5=0, p4=5) for v in (-4, -5, -7, -8, -16, -14, -86, -96, -156, -46)],
        *[single(f"p6-tab-p8-{label(v)}", f"forced string P8 = {v}", **tab, p4=5, p8=v) for v in (2, 5, 102)],
        single("p6-tab-p9-m1", "dead note P9 = -1", **tab, p4=5, p9=-1),
        single("p6-tab-p10-999", "P10 = 999: nothing drawn", **tab, p4=5, p10=999),
        *[single(f"p6-tab-p12-{label(v)}", f"tablature P12 = {v}", **tab, p4=5, p12=v) for v in (100, 2, 102)],
        single("p6-tab-p12-tie", "tablature P12 = 100, P9 = 99 ('Tie')", **tab, p4=5, p12=100, p9=99),
        single("p6-tab-p13", "tablature rotated P13 = 30", **tab, p4=5, p13=30),
        single("p6-tab-p14", "tablature moved P14 = 1.5", **tab, p4=5, p14=1.5),
        single("p6-tab-p15", "tablature size P15 = 0.8", **tab, p4=5, p15=0.8),
        *[single(f"p6-tab-p{n}-{label(v)}", f"tuning change P{n} = {v}", **tab, p4=5, **{f"p{n}": v}) for n, v in ((16, 201), (17, 2), (18, 99), (19, 2), (19, 150))],
        single("p6-tab-p20", "tablature with a white box P20 = 1", **tab, p4=5, p20=1),
        single("p6-tab-p26", "tablature in red", **tab, p4=5, p26=990000),
        single("p6-tab-grace", "tablature P4 = 105", **tab, p4=105),
        single("p6-tab-two-digits-paren", "fret 12 in parentheses", **tab, p4=12, p12=100),
    ]


def rhythm() -> list[Case]:
    return [
        *[single(f"p7-{label(v)}", f"P7 = {v} on a ledger note (P4 = -2)", p7=v, p4=-2) for v in (-1, -2, -3)],
        single("p7-m2-high", "P7 = -2 on P4 = 15", p7=-2, p4=15),
    ]


def stem_lengths() -> list[Case]:
    return [
        *[single(f"p8-{label(v)}", f"stem length P8 = {v}", p8=v) for v in (1.5, -2, 0.5)],
        single("p8-m2-down", "P8 = -2, stem down", p8=-2, p5=20),
        single("p8-tail", "P8 = 1.5 with a tail", p8=1.5, p9=1),
        single("p8-tail-down", "P8 = 1.5 with a tail, stem down", p8=1.5, p9=1, p5=20),
        single("p8-slash-no-tail", "P8 = 101 without a tail (no slash)", p8=101),
    ]


def dots_and_tails() -> list[Case]:
    return [
        *[c for t in (1, 2, 3, 4) for c in stems(f"p9-tails-{t}", f"{t} tail(s)", p9=t, p7=0.5)],
        *[single(f"p9-dots-{d}-line", f"{d} dot(s) on a line note", p9=10 * d) for d in (1, 2, 3)],
        *[single(f"p9-dots-{d}-space", f"{d} dot(s) on a space note (P4 = 4)", p9=10 * d, p4=4) for d in (1, 2)],
        single("p9-dot-down-line", "dot on a line note, stem down", p9=10, p5=20),
        single("p9-dot-tail-up", "dot and tail, stem up (P9 = 11)", p9=11),
        single("p9-dot-tail-down", "dot and tail, stem down", p9=11, p5=20),
        single("p9-dot-tail-p8", "dot and tail, stem up, P8 = 1", p9=11, p8=1),
        single("p9-dot-no-stem", "dot without a stem (P5 = 0)", p9=10, p5=0),
        single("p9-dot-no-stem-high", "dot without a stem on P4 = 9", p9=10, p5=0, p4=9),
        single("p9-dot-headless", "dot on a headless note, stem down", p9=10, p6=7, p5=20),
        single("p9-dot-headless-m1", "dot on a P6 = -1 note, stem down", p9=10, p6=-1, p5=20),
        single("p9-dots-right-3.1", "P9 = 20.31: two dots 3.1 right", p9=20.31),
        single("p9-dot-left-0.4", "P9 = 10.94: dot 0.4 left", p9=10.94),
        single("p9-dot-below-110", "P9 = 110: dot below the line", p9=110),
        single("p9-dot-below-space", "P9 = 110 on a space note", p9=110, p4=4),
        single("p9-dot-wide-1010", "P9 = 1010: dot one note width right", p9=1010),
        single("p9-dot-wide-below-1110", "P9 = 1110", p9=1110),
        single("p9-whole-dot", "dotted whole note", p6=2, p5=0, p9=10),
        single("p9-half-dot-tails", "half head, two dots, two tails", p6=1, p9=22),
    ]


def offsets() -> list[Case]:
    return [single(f"p10-{label(v)}", f"head offset P10 = {v}", p10=v) for v in (10, 20, 110, 2.5, -3, 0.5)] + [
        single("p10-10-down", "P10 = 10, stem down", p10=10, p5=20),
        single("p10-20-ledger", "P10 = 20 on a ledger note", p10=20, p4=0),
        single("p10-10-dot", "P10 = 10 with a dot", p10=10, p9=10),
    ]


def marks() -> list[Case]:
    numbers = [single(f"p11-mark-{m}", f"mark P11 = {m}", p11=m) for m in range(1, 37) if m != 29]
    return numbers + [
        *[single(f"p11-mark-{m}-down", f"mark P11 = {m}, stem down", p11=m, p5=20) for m in (5, 7, 14, 32)],
        *[single(f"p11-mark-{label(m)}", f"mark P11 = {m} on the stem side", p11=m) for m in (-5, -7, -14, -32)],
        single("p11-mark-m32-down", "P11 = -32, stem down", p11=-32, p5=20),
        single("p11-mark-5.13", "P11 = 5.13: accent pushed 1.3 steps", p11=5.13),
        single("p11-mark-m34.2-down", "P11 = -34.2, stem down", p11=-34.2, p5=20),
        single("p11-mark-7-high", "staccato on P4 = 12", p11=7, p4=12),
        single("p11-mark-7-low", "staccato on P4 = -2", p11=7, p4=-2),
        single("p11-mark-7-no-stem", "staccato without a stem", p11=7, p5=0),
        single("p11-mark-7-half", "staccato on a half note", p11=7, p6=1),
        single("p11-mark-5-tails", "accent with two tails", p11=5, p9=2),
        *[single(f"p11-tremolo-{m}", f"P11 = {m}: tremolo beams", p11=m) for m in (41, 42, 43, 44)],
        single("p11-tremolo-42-down", "P11 = 42, stem down", p11=42, p5=20),
        single("p11-tremolo-42-p13-p14", "P11 = 42 with P13 = 1, P14 = 2", p11=42, p13=1, p14=2),
        single("p11-tremolo-42-half", "P11 = 42 on a half note", p11=42, p6=1),
        single("p11-heavy-line", "P11 = 99: heavy line", p11=99),
        single("p11-heavy-line-p13-p14", "P11 = 99, P13 = 3, P14 = 12", p11=99, p13=3, p14=12),
        *[single(f"p13-{label(v)}", f"accent moved horizontally P13 = {v}", p11=5, p13=v) for v in (2, -2)],
        single("p13-99", "staccato centred on the stem (P13 = 99)", p11=7, p13=99),
        single("p13-99-down", "staccato centred on the stem, stem down", p11=7, p13=99, p5=20),
        *[single(f"p14-{label(v)}", f"accent moved vertically P14 = {v}", p11=5, p14=v) for v in (2, -1)],
        *[single(f"p18-{label(v)}", f"accent size P18 = {v}", p11=5, p18=v) for v in (1.5, 0.5)],
        single("p18-staccato-1.5", "staccato size P18 = 1.5", p11=7, p18=1.5),
        single("p18-fingering-2", "fingering size P18 = 2", p11=32, p18=2),
    ]


def other_staves() -> list[Case]:
    three = [staff(), staff(p2=2), staff(p2=3)]
    on_two = [
        (f"p12-{v}", f"note on staff 2 with P12 = {v}", {"p12": v}) for v in (1, 2, 100, 101, 201)
    ] + [
        ("p12-1-ledger", "P12 = 1 on P4 = 0", {"p12": 1, "p4": 0}),
        ("p12-1-slash", "P12 = 1, grace note with a slashed tail", {"p12": 1, "p4": 105, "p8": 101, "p9": 1}),
    ]
    return [built(f"code01-{name}", desc, three + [note(p2=2, **params)]) for name, desc, params in on_two]


def sizes() -> list[Case]:
    return [
        *[single(f"p15-{label(v)}", f"note size P15 = {v}", p15=v) for v in (0.75, 1.3)],
        single("p15-full", "P15 = 0.75 with sharp, dot, two tails, ledger", p15=0.75, p5=12, p9=12, p4=-1),
        single("p15-down", "P15 = 0.75, stem down, tail", p15=0.75, p5=20, p9=1),
        single("p15-grace", "P15 = 0.8 on a grace note", p15=0.8, p4=105),
        single("p15-mark", "P15 = 0.75 with an accent", p15=0.75, p11=5),
        *[single(f"p16-{label(v)}", f"ledger line thickness P16 = {v}", p16=v, p4=-1) for v in (2, 99)],
        *[single(f"p17-{label(v)}", f"stem source P17 = {v}", p17=v) for v in (1.5, -1, 100, 200, 101.5)],
        single("p17-1.5-down", "P17 = 1.5, stem down", p17=1.5, p5=20),
        *[single(f"p19-{label(v)}", f"dot moved P19 = {v}", p9=10, p19=v) for v in (1, -1.5)],
        *[single(f"p20-{label(v)}", f"note width P20 = {v}", p20=v) for v in (1.4, 0.8)],
        single("p20-full", "P20 = 1.4 with dot, tail, flat, ledger", p20=1.4, p9=11, p5=11, p4=0),
        single("p20-down", "P20 = 1.4, stem down, tail", p20=1.4, p5=20, p9=1),
        single("p20-half", "P20 = 1.4 on a half note", p20=1.4, p6=1),
        single("p20-mark", "P20 = 1.4 with staccato", p20=1.4, p11=7),
        single("p28-3", "accidental pen width P28 = 3", p5=12, p28=3),
        *[single(f"p29-{label(v)}", f"accidental size P29 = {v}", p5=11, p29=v) for v in (0.7, 1.5)],
        *[single(f"p31-{label(v)}", f"dot size P31 = {v}", p9=20, p31=v) for v in (1.5, 0.7)],
    ]


def ledger_control() -> list[Case]:
    return [
        *[single(f"p30-{v}-p4-5", f"ledger control P30 = {v} on P4 = 5", p30=v) for v in (1, 2, 3, 4, 14, 24, 34, 44)],
        *[single(f"p30-{v}-p4-14", f"ledger control P30 = {v} on P4 = 14", p30=v, p4=14) for v in (1, 2, 3, 24)],
        single("p30-m1", "P30 = -1 on P4 = -2 (no ledger lines)", p30=-1, p4=-2),
    ]


def colour() -> list[Case]:
    return [
        single("p26-grey", "grey note P26 = 0.5", p26=0.5),
        single("p26-red-ledger", "red note on a ledger line", p26=990000, p4=-1),
        single("p27-red-ledger", "red note, ledger lines red too (P27 = 1)", p26=990000, p27=1, p4=-1),
        single("p25-layer", "layer number P25 = 1", p25=1),
    ]


def grace() -> list[Case]:
    return [
        *stems("grace", "grace note P4 = 105", p4=105),
        single("grace-negative", "grace note P4 = -102", p4=-102),
        single("grace-slash-up", "grace eighth with a slash (P8 = 101)", p4=105, p8=101, p9=1, p7=0.5),
        single("grace-slash-down", "grace eighth with a slash, stem down", p4=105, p8=101, p9=1, p5=20),
        single("grace-slash-short", "grace eighth with a slash, P8 = -101", p4=105, p8=-101, p9=1),
        single("grace-slash-long", "grace eighth with a slash, P8 = 102.5", p4=105, p8=102.5, p9=1),
        single("grace-two-tails", "grace sixteenth with a slash", p4=105, p8=101, p9=2),
        single("grace-sharp-dot", "grace note with sharp and dot", p4=105, p5=12, p9=10),
        single("grace-ledger", "grace note on P4 = 100 (ledger line)", p4=100),
        single("grace-mark", "grace note with staccato", p4=105, p11=7),
    ]


def staves() -> list[Case]:
    return [
        built(f"code01-staff-{label(s)}-{name}", f"staff size {s}: {desc}", [staff(p5=s), note(**params)])
        for s in (0.73, 1.3)
        for name, desc, params in (
            ("base", "base note", {}),
            ("full", "sharp, dot, two tails, ledger line", {"p5": 12, "p9": 12, "p4": -1}),
            ("down", "stem down, tail, accent", {"p5": 20, "p9": 1, "p11": 5}),
        )
    ] + [
        built("code01-staff-recto", "note on staff 201 (recto page)", [staff(p2=201), note(p2=201)]),
        built("code01-staff-p4-offset", "note on a staff moved up (P4 = 2.5)", [staff(p4=2.5), note(p4=0)]),
    ]


def mixed() -> list[Case]:
    """Several notes on one staff, for pictures and to check items do not disturb each other."""
    notes = [
        note(p3=12, p4=-2, p5=11, p6=1, p7=2),
        note(p3=24, p4=3, p5=12, p7=1.5, p9=10),
        note(p3=36, p4=105, p5=10, p7=0.5, p8=101, p9=1),
        note(p3=44, p4=6, p5=13, p7=0.5, p9=1),
        note(p3=56, p4=9, p5=20, p7=0.25, p9=2),
        note(p3=68, p4=14, p5=24, p7=0.25, p9=2),
        note(p3=80, p4=8, p5=0, p6=2, p7=4),
        note(p3=96, p4=5, p5=15, p6=11, p7=2, p9=10),
        note(p3=110, p4=10, p5=20, p6=6, p7=1),
        note(p3=122, p4=4, p5=10, p6=4, p7=1),
        note(p3=134, p4=7, p5=10, p7=0.75, p9=13, p15=0.8),
        note(p3=150, p4=0, p5=16, p6=3, p7=8),
        note(p3=166, p4=12, p5=22.25, p7=1, p10=20),
        note(p3=178, p4=12, p5=20, p7=1, p9=4),
    ]
    return [built("code01-mixed-bar", "fourteen notes of different kinds on one staff", [staff()] + notes)]


def font_chain() -> list[Case]:
    """draw_item makes the font a note loads last current for the next text item (0x547358)."""
    first, second = text("_02first", p3=5, p4=14), text("second", p3=60, p4=14)
    notes = [
        ("font-after-fingering", "plain text after _02 text and a fingering mark (font 1000)", note(p3=35, p11=32)),
        ("font-after-alpha", "plain text after _02 text and an AlphaNote (letter font 1005)", note(p3=35, p6=20)),
        ("font-after-alpha-p21", "plain text after _02 text and an AlphaNote with P21 = 3", note(p3=35, p6=20, p21=3)),
        ("font-after-tab", "plain text after _02 text and a tablature number (font 1005)", note(p3=35, p6=-6, p5=0)),
        ("font-after-plain-note", "plain text after _02 text and a plain note (loads none)", note(p3=35)),
    ]
    return [built(f"code01-{name}", desc, [staff(), first, n, second]) for name, desc, n in notes]


def cases() -> list[Case]:
    return (positions() + accidentals() + heads() + rhythm() + stem_lengths() + dots_and_tails() + offsets()
            + marks() + other_staves() + sizes() + ledger_control() + colour() + grace() + staves() + font_chain()
            + mixed())
