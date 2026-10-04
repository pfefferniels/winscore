"""Interactions across codes: small but realistic measures (clef, key, meter, notes, beams, ties, ...)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import Item, built, item, staff
from musbuild import text_item

UP, DOWN = 10, 20
STEM = 7   # a normal stem is one octave of scale steps


def note(x: float, y: float, stem: int = UP, rhythm: float = 1, head: int = 0, **named: float) -> Item:
    return item(1, 1, x, y, stem, head, rhythm, **named)


def eighths(xs: list[float], ys: list[float], stem: int = UP) -> list[Item]:
    return [note(x, y, stem, 0.5) for x, y in zip(xs, ys)]


def beam(x1: float, y1: float, x2: float, y2: float, kind: float, **named: float) -> Item:
    return item(6, 1, x1, y1, y2, x2, kind, **named)


def tie(x1: float, y1: float, x2: float, y2: float, curve: float = -1.5, **named: float) -> Item:
    return item(5, 1, x1, y1, y2, x2, curve, -2, **named)


def text(string: str, x: float, y: float) -> bytes:
    encoded = string.encode("cp1252")
    return text_item(item(16, 1, x, y, 0, 1, p12=len(encoded), p13=0), encoded)


def opening(clef: float = 0, key: float = 0, top: float = 4, bottom: float = 4) -> list[Item]:
    """Clef, key signature and meter at the start of staff 1."""
    signature = [item(17, 1, 8, 0, key, {0: 0, 1: 1}.get(clef, 0))] if key else []
    return [item(3, 1, 2, 0, clef), *signature, item(18, 1, 14 + abs(key) * 2, 0, top, bottom)]


def cases() -> list[Case]:
    xs = [60, 75, 90, 105]
    up_ys = [5, 6, 7, 8]
    down_ys = [9, 8, 7, 6]
    measures = [
        ("measure-treble", "treble clef, two sharps, 3/4, three quarter notes, barline",
         [staff(), *opening(0, 2, 3, 4), note(40, 5), note(60, 7), note(80, 9, DOWN), item(14, 1, 100, 1)]),
        ("measure-bass", "bass clef, three flats, 6/8, notes with ledger lines and a rest",
         [staff(), *opening(1, -3, 6, 8), note(45, -2, UP, 1.5, p9=10), item(2, 1, 65, 0, 1, 0, 0.5),
          note(80, -4, UP, 1), item(14, 1, 100, 1)]),
        ("beam-up", "four eighths, stems up, one beam",
         [staff(), *eighths(xs, up_ys), beam(60, 5 + STEM, 105, 8 + STEM, 11)]),
        ("beam-down", "four eighths, stems down, one beam",
         [staff(), *eighths(xs, down_ys, DOWN), beam(60, 9 - STEM, 105, 6 - STEM, 21)]),
        ("beam-double", "four sixteenths, stems up, two beams",
         [staff(), *[note(x, y, UP, 0.25) for x, y in zip(xs, up_ys)], beam(60, 5 + STEM, 105, 8 + STEM, 12)]),
        ("beam-triplet", "three eighths with a 3 over the beam",
         [staff(), *eighths(xs[:3], up_ys[:3]), beam(60, 5 + STEM, 90, 7 + STEM, 11, p8=3)]),
        ("beam-partial", "dotted eighth and sixteenth: full beam plus a partial",
         [staff(), note(60, 5, UP, 0.75, p9=10), note(90, 6, UP, 0.25),
          beam(60, 5 + STEM, 90, 6 + STEM, 11, p10=11, p11=80, p12=-1)]),
        ("tie", "two half notes tied", [staff(), note(50, 4, UP, 2, 1), note(110, 4, UP, 2, 1), tie(50, 4, 110, 4)]),
        ("slur", "slur over four quarter notes",
         [staff(), *[note(x, y) for x, y in zip(xs, up_ys)], item(5, 1, 60, 3, 6, 105, -3, -1)]),
        ("chord", "C major triad with one stem", [staff(), note(80, 1), note(80, 3, 0), note(80, 5, 0)]),
        ("chord-second", "chord with a second: the upper note displaced right",
         [staff(), note(80, 4), note(80, 5, 0, p10=10), note(80, 7, 0)]),
        ("chord-down", "chord with stem down and accidentals",
         [staff(), note(80, 9, DOWN + 1), note(80, 7, 2), note(80, 5, 1)]),
        ("chord-tie", "two tied chords",
         [staff(), note(50, 3, UP, 2, 1), note(50, 5, 0, 2, 1), note(110, 3, UP, 2, 1), note(110, 5, 0, 2, 1),
          tie(50, 3, 110, 3), tie(50, 5, 110, 5, 1.5)]),
        ("grace", "grace note with slashed stem slurred to its main note",
         [staff(), note(70, 106, UP, 0, p8=100, p9=1), note(80, 5), item(5, 1, 70, 104, 4, 80, -1, -1)]),
        ("rests", "notes and rests in one measure, centred whole rest in the next",
         [staff(), note(20, 5), item(2, 1, 35, 0, 0, 0, 1), note(50, 6, UP, 0.5, p9=1), item(2, 1, 60, 0, 1, 0, 0.5),
          item(14, 1, 70, 1), item(2, 1, 72, 0, -2, 0, 4, 0, -1), item(14, 1, 120, 1)]),
        ("system", "two staves with brace, notes on both, barlines",
         [staff(), staff(p2=2), item(14, 1, 0, 2, 8, 0, -2), item(14, 1, 0, 2), item(3, 2, 2, 0, 0), item(3, 1, 2, 0, 1),
          item(1, 2, 40, 5, UP, 0, 2, 0, 0, p9=0), item(1, 1, 40, 0, DOWN, 1, 2), item(14, 1, 100, 2)]),
        ("dynamics", "melody with p, hairpin, tempo text and final bar",
         [staff(), *opening(0, 0, 4, 4), note(30, 5), note(50, 6), note(70, 7), note(90, 8, DOWN),
          item(9, 1, 30, -4, 53), item(4, 1, 45, -4, 999, 85), text("_02Andante", 20, 13),
          item(14, 1, 110, 1, 2)]),
    ]
    return [built(f"code99-{name}", desc, items) for name, desc, items in measures]
