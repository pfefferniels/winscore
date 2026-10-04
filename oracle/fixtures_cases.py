"""The fixture catalogue: WinScore samples and per-code parameter sweeps.

Case names: sample-<file>, codeNN-<parameter>-<value class>. See rust/fixtures/PLAN.md.
"""
from __future__ import annotations

from pathlib import Path

from fixtures import Case
from musbuild import mus_bytes

REPO = Path(__file__).resolve().parents[1]
WINSCORE = REPO / "WINSCORE 5.01" / "winscore"
SCORE4 = REPO / "SCORE 4" / "SCORE"

Item = list[float]


def item(*leading: float, **named: float) -> Item:
    """item(8, 1, 0, 0, 1, p26=990000): P1, P2, ... in order, then Pn by name."""
    params = dict(enumerate(leading, start=1)) | {int(k[1:]): v for k, v in named.items()}
    return [float(params.get(n, 0.0)) for n in range(1, max(params) + 1)]


def built(name: str, description: str, items: list[Item], commands: tuple[str, ...] = ()) -> Case:
    return Case(name, description, mus_bytes(items), commands)


def label(value: float) -> str:
    """A value as it appears in a case name: 1.429 -> 1.429, -3 -> m3."""
    text = f"{value:g}"
    return text.replace("-", "m")


# -- samples -----------------------------------------------------------------

def sample_cases() -> list[Case]:
    winscore = [
        Case(f"sample-{p.stem.lower()}", f"WinScore sample {p.name}", p.read_bytes(),
             attachments=(WINSCORE / "logo-col.eps",) if p.stem == "000" else ())
        for p in sorted(WINSCORE.glob("*.mus"))
    ]
    score4 = [Case(f"sample-{p.stem.lower()}", f"SCORE 4 sample {p.name}", p.read_bytes())
              for p in (SCORE4 / "NEWLINE.MUS", SCORE4 / "NEWLIB.MUS")]
    return winscore + score4


# -- code 8: staves ----------------------------------------------------------

def staff(**named: float) -> Item:
    """Staff 1 at size 1 unless overridden (p2=..., p5=...)."""
    base = {"p2": 1, "p5": 1} | named
    return item(8, **base)


def code08_cases() -> list[Case]:
    one = [
        ("default", "staff 1, size 1", {}),
        ("p5-zero", "P5 = 0 (engine default size)", {"p5": 0}),
        *[(f"p2-staff-{n}", f"single staff numbered {n}", {"p2": n}) for n in (0, 2, 3, 10)],
        *[(f"p3-left-{label(v)}", f"left end P3 = {v}", {"p3": v}) for v in (-20, 10, 55.5)],
        *[(f"p4-offset-{label(v)}", f"vertical offset P4 = {v} scale steps", {"p4": v}) for v in (-3, 2.5, 5)],
        *[(f"p5-size-{label(v)}", f"staff size P5 = {v}", {"p5": v}) for v in (0.5, 0.64, 0.65, 0.8, 1.429, 2)],
        *[(f"p6-right-{label(v)}", f"right end P6 = {v}", {"p6": v}) for v in (150, 210, 220)],
        ("p3-p6-short", "P3 = 50, P6 = 120", {"p3": 50, "p6": 120}),
        *[(f"p7-lines-{v}", f"{v} staff line(s)", {"p7": v}) for v in (1, 2, 3, 4, 6, 7, 10)],
        *[(f"p7-xyz-{v}", f"P7 = {v}: bottom line of a normal staff, then count", {"p7": v}) for v in (203, 302, 401, 106)],
        ("p7-invisible", "P7 = -1, invisible staff (light grey on screen)", {"p7": -1}),
        ("p9-instrument", "instrument number P9 = 5", {"p9": 5}),
        *[(f"p10-inches-{label(v)}", f"staff 2 placed {v} in above staff 1 with P10 (P4 = 4 ignored)", {"p2": 2, "p10": v, "p4": 4})
          for v in (1.5, 3)],
        *[(f"p11-thickness-{v}", f"PostScript line thickness P11 = {v}", {"p11": v}) for v in (2, 99)],
        ("p12-suppress-number", "P12 = 1 hides the staff number", {"p12": 1}),
        ("p13-transpose", "MIDI transposition P13 = -9", {"p13": -9}),
        *[(f"p14-cm-{label(v)}", f"staff height P14 = {v} cm", {"p14": v, "p5": 0}) for v in (0.78, 1.2)],
        ("p25-layer", "layer number P25 = 1", {"p25": 1}),
        *[(f"p26-{name}", f"P26 = {v}", {"p26": v}) for name, v in
          (("grey-0.5", 0.5), ("white", 1), ("red", 990000), ("rgb-336699", 336699), ("green-009900", 9900))],
    ]
    single = [built(f"code08-{name}", desc, [staff(**params)]) for name, desc, params in one]
    systems = [
        ("staves-2", "staves 1 and 2, size 1", [staff(), staff(p2=2)]),
        ("staves-4", "staves 1-4, size 1", [staff(p2=n) for n in range(1, 5)]),
        ("staves-gaps", "staves 1, 3 and 6", [staff(p2=n) for n in (1, 3, 6)]),
        ("staves-sizes", "staves 1-4 with sizes 1, 0.75, 1.2, 0.6",
         [staff(p2=n, p5=s) for n, s in zip(range(1, 5), (1, 0.75, 1.2, 0.6))]),
        ("staves-offsets", "staves 1-3 with P4 = 0, 4, -2", [staff(p2=n, p4=o) for n, o in zip(range(1, 4), (0, 4, -2))]),
        ("staves-p10", "staves 1-3, staves 2 and 3 placed by P10 = 1.2 and 2.6 in",
         [staff(), staff(p2=2, p10=1.2), staff(p2=3, p10=2.6)]),
        ("staves-ends", "staves 1-3 with different P3/P6", [staff(p3=0), staff(p2=2, p3=20, p6=180), staff(p2=3, p3=-10, p6=210)]),
        ("staves-lines", "staves with 5, 1 and 3 lines", [staff(), staff(p2=2, p7=1), staff(p2=3, p7=3)]),
        ("staves-recto", "staff 1 and recto staff 201", [staff(), staff(p2=201)]),
        ("staves-12", "twelve staves at size 0.7", [staff(p2=n, p5=0.7) for n in range(1, 13)]),
    ]
    return single + [built(f"code08-{name}", desc, items) for name, desc, items in systems]


# -- code 14: barlines, braces, brackets -------------------------------------

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


def code14_cases() -> list[Case]:
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


def all_cases() -> list[Case]:
    cases = sample_cases() + code08_cases() + code14_cases()
    names = [c.name for c in cases]
    duplicates = sorted({n for n in names if names.count(n) > 1})
    if duplicates:
        raise ValueError(f"duplicate case names: {duplicates}")
    return cases
