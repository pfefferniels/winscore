"""Code 16 sweeps: text (analysis/docs/text/winscore/code16.txt, score4/COD16-4.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, label, staff
from musbuild import text_item

SAMPLE = "_00Hamburgefonstiv"


def text(string: str = SAMPLE, **named: float) -> bytes:
    """Text on staff 1 at P3 = 50, P4 = 12, size 1 unless overridden; P12 is the character count.

    The engine reads the characters after P13 whatever the item length, so P13 is always stored.
    """
    encoded = string.encode("cp1252")
    params = item(16, **({"p2": 1, "p3": 50, "p4": 12, "p6": 1, "p13": 0} | named | {"p12": len(encoded)}))
    return text_item(params, encoded)


def on_staff(*texts: bytes, **staff_params: float) -> list:
    return [staff(**staff_params), *texts]


def cases() -> list[Case]:
    single = [
        ("default", "Times (_00) at size 1", {}),
        *[(f"p5-spacing-{label(v)}", f"character space factor P5 = {v}", {"p5": v}) for v in (0.8, 1.3)],
        *[(f"p6-size-{label(v)}", f"size P6 = {v}", {"p6": v}) for v in (0, 0.5, 2)],
        ("p7-vertical-2", "P6 = 1, vertical size P7 = 2", {"p7": 2}),
        ("p7-vertical-half", "P6 = 2, vertical size P7 = 0.5", {"p6": 2, "p7": 0.5}),
        *[(f"p6-parts-{v}", f"part-extraction flag in P6 = {v}", {"p6": v}) for v in (101, 201, 301)],
        *[(f"p8-font-{v}", f"font override P8 = {v}", {"p8": v}) for v in (90, 91, 92, 93, 94, 98, 1000, 1004, 1034)],
        *[(f"p8-outline-{v}", f"outline font override P8 = {v}", {"p8": v}) for v in (193, 1105)],
        *[(f"p9-rotate-{label(v)}", f"rotation P9 = {v} degrees", {"p9": v}) for v in (30, -45, 90, 180)],
        *[(f"p11-displace-{label(v)}", f"horizontal displacement P11 = {v}", {"p11": v}) for v in (-5, 10)],
        ("p14-colour-red", "P14 = -1, P16 = 990000", {"p14": -1, "p16": 990000}),
        ("p14-grey", "P14 = -1, P16 = 0.5", {"p14": -1, "p16": 0.5}),
        ("p14-layer", "P14 = -1, layer P15 = 1", {"p14": -1, "p15": 1}),
        ("p4-low", "below the staff, P4 = -6", {"p4": -6}),
        ("p3-right", "near the right margin, P3 = 180", {"p3": 180}),
    ]
    strings = [
        *[(f"font-{n:02d}", f"font _{n:02d}", f"_{n:02d}Hamburgefonstiv", {}) for n in range(35)],
        *[(f"font-{n}", f"font _{n}", f"_{n}Hamburgefonstiv 123", {}) for n in (90, 91, 92, 93, 98)],
        ("font-94", "meter font _94", "_9412345678", {}),
        ("font-99-comment", "non-printing comment _99%", "_99%a comment", {}),
        ("fonts-mixed", "font changes inside the string", "_00A stitch _02in time _16saves _23nine.", {}),
        ("spaces", "words separated by spaces", "_00one two  three", {}),
        ("p10-space-2", "space size P10 = 2", "_00one two  three", {"p10": 2}),
        ("tab", "tab stops ~n~", "_00left ~120~right", {}),
        ("special-copyright", "?c escape", "_00?c 1999", {}),
        ("special-umlaut", "%% escapes", "_00S%%ohne M%%adchen", {}),
        ("special-brackets", "[ and ] (note symbols in music text)", "_90Allegro [ = 120 ]", {}),
        ("special-slash", "backslash for a printable slash", "_00either\\or", {}),
        ("punctuation", "punctuation and digits", "_00(1), [2]; 3.4 - 5!", {}),
        ("latin1", "Latin-1 characters", "_00\u00e9tude \u00e7a \u00fcber", {}),
        ("one-char", "a single character", "_00X", {}),
        ("long", "a long line", "_00" + "The quick brown fox jumps over the lazy dog. " * 3, {}),
    ]
    staves = [
        ("staff-small", "text on a staff of size 0.7", on_staff(text(), p5=0.7)),
        ("staff-large", "text on a staff of size 1.5", on_staff(text(), p5=1.5)),
        ("staff-recto", "text on recto staff 201", [staff(), staff(p2=201), text(p2=201)]),
        ("lines", "three lines of text", on_staff(*(text(f"_00line {n}", p4=12 - 4 * n) for n in range(3)))),
    ]
    return ([built(f"code16-{name}", desc, on_staff(text(**params))) for name, desc, params in single]
            + [built(f"code16-{name}", desc, on_staff(text(string, **params))) for name, desc, string, params in strings]
            + [built(f"code16-{name}", desc, items) for name, desc, items in staves])
