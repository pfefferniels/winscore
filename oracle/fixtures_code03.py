"""Code 3 sweeps: clefs (analysis/docs/text/winscore/code3.txt, score4/COD03-4.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, label, staff

TYPES = {
    0: "treble", 1: "bass", 2: "alto", 3: "tenor", 4: "percussion", 5: "brace", 6: "flat", 7: "sharp",
    0.8: "treble-8vb", 0.88: "treble-8va", 0.15: "treble-15ma", 1.8: "bass-8vb",
    44: "tab-4", 55: "tab-5", 66: "tab-6", 45: "symbol-45", -1: "negative",
}


def clef(**named: float):
    """Clef on staff 1 at P3 = 20 unless overridden."""
    return item(3, **({"p2": 1, "p3": 20} | named))


def cases() -> list[Case]:
    one = [
        *[(f"p5-{name}", f"clef type P5 = {v}", {"p5": v}) for v, name in TYPES.items()],
        *[(f"p4-{label(v)}-{TYPES[t]}", f"P4 = {v}, type {t}", {"p4": v, "p5": t})
          for t in (0, 2) for v in (2, -2, 0.5)],
        *[(f"p4-mini-{label(v)}-{TYPES[t]}", f"mini clef P4 = {v}, type {t}", {"p4": v, "p5": t})
          for v in (100, -100) for t in (0, 1, 2, 3, 4)],
        *[(f"p4-mini-{label(v)}-{TYPES[t]}", f"mini clef P4 = {v}, type {t}", {"p4": v, "p5": t})
          for v, t in ((102, 0), (100, 0.8), (100, 0.88), (100, 1.8), (100, 44))],
        *[(f"p6-size-{label(v)}-{TYPES[t]}", f"size P6 = {v}, type {t}", {"p6": v, "p5": t})
          for t in (0, 1, 0.8) for v in (0.5, 1.5, -1)],
        *[(f"p6-p7-{label(a)}-{label(b)}-{TYPES[t]}", f"P6 = {a}, P7 = {b}, type {t}", {"p6": a, "p7": b, "p5": t})
          for t in (0, 3, 66, 0.88) for a, b in ((0.5, 2), (0, 1.5), (1, -1))],
        *[(f"p10-pixels-{label(v)}-{TYPES[t]}", f"pixel thickness P10 = {v}, type {t}", {"p10": v, "p5": t})
          for t in (0, 1) for v in (-1, 1, 2)],
        *[(f"p15-offset-{label(v)}", f"offset P15 = {v}", {"p15": v}) for v in (0.5, -0.5, 3)],
        *[(f"p15-offset-{label(v)}-treble-8va", f"offset P15 = {v}, octave number", {"p15": v, "p5": 0.88})
          for v in (0.5, -2)],
        *[(f"p3-pos-{label(v)}", f"P3 = {v}", {"p3": v}) for v in (0, 0.3, 150.7)],
        ("p26-grey", "P26 = 0.5", {"p26": 0.5}),
        ("p26-red-treble-8va", "P26 = 990000 with octave number", {"p26": 990000, "p5": 0.88}),
    ]
    single = [built(f"code03-{name}", desc, [staff(), clef(**params)]) for name, desc, params in one]
    staves = [
        *[(f"staff-size-{label(s)}-{TYPES[t]}", f"staff size {s}, type {t}", {"p5": s}, {"p5": t})
          for s in (0.75, 1.4, -1) for t in (0, 1, 2, 0.88, 55)],
        *[(f"staff-size-{label(s)}-mini-{TYPES[t]}", f"staff size {s}, mini clef type {t}", {"p5": s}, {"p5": t, "p4": 100})
          for s in (0.75,) for t in (0, 1)],
        ("staff-p4-offset", "staff P4 = 2.5, treble", {"p4": 2.5}, {"p5": 0}),
        ("staff-recto-201", "recto staff 201, treble 8va", {"p2": 201}, {"p2": 201, "p5": 0.88}),
    ]
    on_staves = [built(f"code03-{name}", desc, [staff(**s), clef(**c)]) for name, desc, s, c in staves]
    several = [
        built("code03-system", "four staves with treble, alto, tenor, bass",
              [*[staff(p2=n) for n in range(1, 5)], *[clef(p2=n, p5=t) for n, t in zip(range(1, 5), (1, 3, 2, 0))]]),
        built("code03-no-staff", "treble clef without a staff", [clef(p5=0)]),
    ]
    return single + on_staves + several
