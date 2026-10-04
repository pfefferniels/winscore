"""Code 7 fixtures: trills, ottavas, harp and piano pedal symbols, pedal lines (analysis/docs/text/winscore/code7.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, staff


def mark(**named: float) -> list[float]:
    """A code-7 item on staff 1 at P3 20, P4 12 unless overridden."""
    base = {"p2": 1, "p3": 20, "p4": 12} | named
    return item(7, **base)


def trill(**named: float) -> list[float]:
    return mark(**named)


def ottava(p7: float, **named: float) -> list[float]:
    return mark(**({"p7": p7, "p4": 13} | named))


def pedal(**named: float) -> list[float]:
    return mark(**({"p4": -3} | named))


CASES: list[tuple[str, str, list[float]]] = [
    # trills
    ("p7-trill", "trill symbol, P7 0", trill()),
    ("p6-trill-wave", "trill with wavy extension to P6 70", trill(p6=70)),
    ("p9-trill-wave-size", "trill extension, P9 1.5", trill(p6=70, p9=1.5)),
    ("p9-trill-wave-small", "trill extension, P9 0.6", trill(p6=70, p9=0.6)),
    ("p11-trill-wave-up", "trill extension raised, P11 1", trill(p6=70, p11=1)),
    ("p11-trill-wave-down", "trill extension lowered, P11 -0.6", trill(p6=70, p11=-0.6)),
    ("p12-trill-arrow", "trill extension with arrow, P12 100", trill(p6=70, p12=100)),
    ("p8-trill-flat", "trill with flat, P8 1", trill(p8=1)),
    ("p8-trill-sharp", "trill with sharp, P8 2", trill(p8=2)),
    ("p8-trill-natural", "trill with natural, P8 3", trill(p8=3)),
    ("p8-trill-4", "trill with P8 4 (double flat)", trill(p8=4)),
    ("p8-trill-5", "trill with P8 5 (double sharp)", trill(p8=5)),
    ("p8-trill-6", "trill with P8 6 (no accidental)", trill(p8=6)),
    ("p8-trill-wave", "trill with sharp and extension", trill(p8=2, p6=70)),
    ("p5-trill-size-1.5", "trill, P5 1.5, with extension", trill(p5=1.5, p6=70)),
    ("p5-trill-size-0.7", "trill, P5 0.7, with flat", trill(p5=0.7, p8=1)),
    ("p10-trill-thick", "trill extension, P10 1", trill(p6=70, p10=1)),
    ("p13-trill-rotated", "trill extension, P13 5", trill(p6=70, p13=5)),
    ("p15-trill-offset", "trill, P15 3", trill(p6=70, p15=3)),
    ("p18-trill-right-offset", "trill, P18 -4 (P16 set by the engine)", trill(p6=70, p18=-4)),
    ("p16p18-trill-offsets", "trill, P16 1, P17 2, P18 5", trill(p6=70, p16=1, p17=2, p18=5)),
    ("p28-trill-pixels", "trill, P28 1", trill(p28=1)),
    ("p26-trill-colour", "trill with extension, P26 0.5", trill(p6=70, p26=0.5)),
    # ottavas
    ("p7-ottava", "8va symbol, P7 8", ottava(8)),
    ("p6-ottava-dashes", "8va with dashes to P6 80", ottava(8, p6=80)),
    ("p7-ottava-bassa", "8ba with dashes, P7 -8", ottava(-8, p4=-4, p6=80)),
    ("p7-quindicesima", "15ma with dashes, P7 15", ottava(15, p6=80)),
    ("p7-ottava-88", "ottava, dashes up, P7 88", ottava(88, p6=80)),
    ("p7-ottava-m88", "ottava, dashes down, P7 -88", ottava(-88, p4=-4, p6=80)),
    ("p7-quindicesima-155", "quindicesima, dashes up, P7 155", ottava(155, p6=80)),
    ("p8p9-ottava-dashes", "8va dashes P8 2, P9 1", ottava(8, p6=80, p8=2, p9=1)),
    ("p12-ottava-bracket", "8va with end bracket P12 -2", ottava(8, p6=80, p12=-2)),
    ("p12-ottava-88-bracket", "ottava 88 with end bracket P12 -1.5", ottava(88, p6=80, p12=-1.5)),
    ("p5-ottava-size", "8va, P5 1.5", ottava(8, p6=80, p5=1.5)),
    ("p10-ottava-thick", "8va dashes, P10 1", ottava(8, p6=80, p10=1)),
    ("p18-ottava-offset", "8va, P18 3", ottava(8, p6=80, p18=3)),
    # harp pedal symbols
    ("p7-harp", "harp pedal symbol, P8 012, P9 1201", mark(p7=1, p4=-4, p8=12, p9=1201)),
    ("p7-harp-flat", "harp pedals all up (000, 0000)", mark(p7=1, p4=-4)),
    ("p7-harp-down", "harp pedals all down (222, 2222)", mark(p7=1, p4=-4, p8=222, p9=2222)),
    ("p5-harp-size", "harp pedal symbol, P5 1.5", mark(p7=1, p4=-4, p8=102, p9=2010, p5=1.5)),
    ("p15-harp-offset", "harp pedal symbol, P15 4", mark(p7=1, p4=-4, p8=12, p9=1201, p15=4)),
    # graphic piano pedal symbols
    ("p7-piano-pedal", "piano pedal symbol, P5 101", pedal(p7=20, p5=101)),
    ("p5-piano-pedal-111", "piano pedal symbol, P5 111", pedal(p7=20, p5=111)),
    ("p5-piano-pedal-010", "piano pedal symbol, P5 10", pedal(p7=20, p5=10)),
    ("p5-piano-pedal-off", "piano pedal symbol, all pedals up", pedal(p7=20)),
    ("p9-piano-pedal-size", "piano pedal symbol, P9 1.5", pedal(p7=20, p5=1, p9=1.5)),
    ("p6-piano-pedal-line", "piano pedal symbol with line to P6 70", pedal(p7=20, p5=1, p6=70)),
    ("p8-piano-pedal-left", "piano pedal symbol, lines from P8 10 to P6 70", pedal(p7=20, p5=1, p3=30, p6=70, p8=10)),
    ("p11p12-piano-pedal-brackets", "piano pedal symbol line with brackets", pedal(p7=20, p5=1, p6=70, p8=10, p3=30, p11=1.5, p12=101)),
    # piano pedal lines
    ("p7-pedal-line", "pedal line, P7 21, to P6 80", pedal(p7=21, p6=80)),
    ("p7-pedal-line-22", "pedal line, P7 22, to P6 80", pedal(p7=22, p6=80)),
    ("p8-pedal-notch", "pedal line with notch at P8 50", pedal(p7=21, p6=80, p8=50)),
    ("p8-pedal-notch-22", "pedal line 22 with notch at P8 50", pedal(p7=22, p6=80, p8=50)),
    ("p9-pedal-notch-height", "pedal notch, P9 3", pedal(p7=21, p6=80, p8=50, p9=3)),
    ("p11-pedal-bracket", "pedal line, left bracket P11 2", pedal(p7=21, p6=80, p11=2)),
    ("p11-pedal-arrow", "pedal line, left arrow P11 101", pedal(p7=21, p6=80, p11=101)),
    ("p12-pedal-bracket", "pedal line, right bracket P12 2", pedal(p7=21, p6=80, p12=2)),
    ("p12-pedal-arrow", "pedal line, right arrow P12 101", pedal(p7=22, p6=80, p8=40, p12=101)),
    ("p12-pedal-updown", "pedal line, right P12 201", pedal(p7=21, p6=80, p12=201)),
    ("p15-pedal-offset", "pedal line, P15 2", pedal(p7=21, p6=80, p8=50, p15=2)),
    # other symbols
    ("p7-ped", "P7 23: Ped. symbol", pedal(p7=23)),
    ("p7-asterisk", "P7 24: asterisk", pedal(p7=24)),
    ("p7-25", "P7 25: symbol 120", pedal(p7=25)),
    ("p9-ped-size", "P7 23, P9 1.5", pedal(p7=23, p9=1.5)),
]


def sized(size: float, *items: list[float]) -> list[list[float]]:
    return [staff(p5=size), *items]


SIZED: list[tuple[str, str, list[list[float]]]] = [
    ("size-0.75-trill", "trill with flat and extension on a size 0.75 staff", sized(0.75, trill(p8=1, p6=70))),
    ("size-0.75-ottava", "8va with dashes on a size 0.75 staff", sized(0.75, ottava(8, p6=80))),
    ("size-0.75-pedal", "pedal line with notch on a size 0.75 staff", sized(0.75, pedal(p7=21, p6=80, p8=50))),
    ("size-0.75-harp", "harp pedal symbol on a size 0.75 staff", sized(0.75, mark(p7=1, p4=-4, p8=12, p9=1201))),
    ("recto", "trill with extension on the recto staff 201", [staff(p2=201), trill(p2=201, p6=70)]),
]


def cases() -> list[Case]:
    return ([built(f"code07-{name}", desc, [staff(), it]) for name, desc, it in CASES]
            + [built(f"code07-{name}", desc, items) for name, desc, items in SIZED])
