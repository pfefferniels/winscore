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
        *[(f"font-{n}", f"font _{n} (WinScore extension)", f"_{n}Hamburgefonstiv 123", {})
          for n in (35, 40, 45, 50, 51, 55, 57, 60, 61, 63)],
        ("outline", "outline font __05", "__05Outline", {}),
        ("p5-spacing-0.5", "character space factor P5 = 0.5", "_04one two three", {"p5": 0.5}),
        *[(f"p10-space-{label(v)}", f"space size P10 = {v}", "_00one two  three", {"p10": v}) for v in (0.5, -0.5)],
        ("p9-rotate-30-large", "rotation P9 = 30 at size 2", SAMPLE, {"p9": 30, "p6": 2}),
        ("p8-font-1004-tab", "font override P8 = 1004 with a font code and a tab", "_02A~60~B", {"p8": 1004}),
        # Symbol glyphs of a rotated text item turn about (P3·150, Y_POS) (rotate_points 0x42A5F4).
        ("p9-rotate-180-symbols", "rotation P9 = 180 with [ ] symbols", "_90Allegro [ = 120 ]", {"p9": 180, "p3": 40}),
        ("p9-rotate-90-font-94", "meter font P8 = 94 rotated by P9 = 90", "_051234", {"p8": 94, "p9": 90}),
        ("p9-rotate-30-p11", "symbols, rotation P9 = 30 and shift P11 = 5", "_00A[B]C", {"p9": 30, "p11": 5}),
        ("special-ascii", "# $ % & < > @", "_00A#B$C%D&E<F>G@H", {}),
        ("special-accents", "~n, ^e, %%o, ##c, <<e, >>a", "_00A~nB ^e S%%ohne ##c <<e >>a", {}),
        ("special-escapes", "?A ?E ?a ?s ?t !a !A !f", "_00?A ?E ?a ?s ?t !a !A !f", {}),
        ("special-octal", "octal escape \\\\351", "_00A\\\\351B", {}),
        ("special-braces", "{ } and | (symbols)", "_00A{B}C|D", {}),
        ("tabs", "several tab stops", "_00Works~55~Composers~105~Dates", {}),
        ("p3-negative", "P3 = -10", SAMPLE, {"p3": -10}),
        ("p3-fraction", "P3 = 55.37", SAMPLE, {"p3": 55.37}),
        ("p4-fraction", "P4 = 13.5", SAMPLE, {"p4": 13.5}),
    ]
    staves = [
        ("staff-small", "text on a staff of size 0.7", on_staff(text(), p5=0.7)),
        ("staff-large", "text on a staff of size 1.5", on_staff(text(), p5=1.5)),
        ("staff-recto", "text on recto staff 201", [staff(), staff(p2=201), text(p2=201)]),
        ("lines", "three lines of text", on_staff(*(text(f"_00line {n}", p4=12 - 4 * n) for n in range(3)))),
        ("staff-2", "text on staff 2", [staff(), staff(p2=2), text(p2=2)]),
        ("staff-200", "text on staff 200 (verso for text, recto for shapes)", [staff(), staff(p2=200), text(p2=200)]),
        ("staff-201-rotate-symbols", "rotated text with symbols on recto staff 201",
         [staff(), staff(p2=201), text("_00A[B]C", p2=201, p9=45)]),
        # The engine keeps the current font across items and drawing passes.
        ("font-after-staff", "text without a font code after a staff (Helvetica-Narrow)", on_staff(text("plain"))),
        ("font-after-text", "text without a font code after _02 text", on_staff(text("_02first"), text("second", p4=4))),
        ("font-wraps", "text without a font code before _05 text", on_staff(text("first", p4=4), text("_05second"))),
        ("font-no-staff", "text without a font code, no staff", [text("_02first", p4=4), text("second")]),
        # draw_item makes the font loaded last current (0x547358); numbers load theirs.
        ("font-after-number", "plain text after _02 text and a code-10 number (font 1000)",
         on_staff(text("_02first"), item(10, 1, 70, 5, 7), text("second", p4=4))),
        ("font-after-meter", "plain text after _02 text and a 3/4 meter (font 94, loads none)",
         on_staff(text("_02first"), item(18, 1, 70, 0, 3, 4), text("second", p4=4))),
        ("font-after-meter-p13", "plain text after _02 text and a meter in font P13 = 2 (Helvetica)",
         on_staff(text("_02first"), item(18, 1, 70, 0, 3, 4, p13=2), text("second", p4=4))),
        *[(f"font-after-{name}", f"plain text after _05 text and {desc}",
           on_staff(text("_05first"), other, text("second", p4=4)))
          for name, desc, other in (
              ("ottava", "an 8va (code 7)", item(7, 1, 70, 12, 0, 0, 8)),
              ("text-symbol", "pizz. (code 9, symbol 66)", item(9, 1, 70, 7, 66)),
              ("term", "a CODE9.DAT term (code 9, 3004)", item(9, 1, 70, 7, 3004)),
              ("tuplet", "a beam with tuplet number 3 (code 6)", item(6, 1, 100, 9, 9, 130, 11, 3)),
              ("two-bar-repeat", "a two-bar repeat with number 2 (code 14)", item(14, 1, 100, 1, -44, 0, 0, 2)),
              ("tuplet-bracket", "a tuplet bracket with 3 (code 5)", item(5, 1, 100, 9, 9, 130, 5, 3)),
              ("ending", "a first ending (code 5)", item(5, 1, 100, 10, 10, 130, 5, 1)),
          )],
        ("colour-then-plain", "a coloured text item before a plain one",
         on_staff(text(p14=-1, p16=990000), text("_02second", p4=4))),
    ]
    return ([built(f"code16-{name}", desc, on_staff(text(**params))) for name, desc, params in single]
            + [built(f"code16-{name}", desc, on_staff(text(string, **params))) for name, desc, string, params in strings]
            + [built(f"code16-{name}", desc, items) for name, desc, items in staves])
