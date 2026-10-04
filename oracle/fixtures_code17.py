"""Code 17 sweeps: key signatures (analysis/docs/text/winscore/code17.txt)."""
from __future__ import annotations

from fixtures import Case
from fixtures_cases import built, item, label, staff

CLEFS = {0: "treble", 1: "bass", 2: "alto", 3: "tenor"}


def key(**named: float):
    """Key signature on staff 1 at P3 = 20 unless overridden."""
    return item(17, **({"p2": 1, "p3": 20} | named))


def cases() -> list[Case]:
    one = [
        *[(f"p5-{label(n)}-{CLEFS[c]}", f"P5 = {n}, clef {c}", {"p5": n, "p6": c})
          for c in CLEFS for n in (7, -7)],
        *[(f"p5-{label(n)}", f"P5 = {n}", {"p5": n}) for n in (0, 1, 3, -1, -4, 107, -103, 8, -9)],
        *[(f"p6-cue-{label(n)}", f"cue size P6 = 100, P5 = {n}", {"p5": n, "p6": 100}) for n in (4, -4)],
        ("p6-cue-bass", "cue size P6 = 101, P5 = 3", {"p5": 3, "p6": 101}),
        ("p6-out-of-range", "P6 = 5 (read as treble)", {"p5": 3, "p6": 5}),
        *[(f"p7-space-{label(v)}", f"spacing P7 = {v}", {"p5": 4, "p7": v}) for v in (0.8, 1.2, -1)],
        ("p7-space-cue", "spacing P7 = 1.5 with cue size", {"p5": -3, "p7": 1.5, "p6": 100}),
        ("p4-offset", "P4 = 2", {"p5": 2, "p4": 2}),
        *[(f"p15-offset-{label(v)}", f"offset P15 = {v}", {"p5": 2, "p15": v}) for v in (0.5, -1)],
        ("irregular-3", "irregular: flat at 7, sharp at 9, natural at 4", {"p8": 107, "p9": 209, "p10": 304}),
        ("irregular-7", "irregular: seven accidentals through P16",
         {"p8": 111, "p9": 210, "p10": 309, "p11": 108, "p12": 207, "p13": 306, "p16": 105}),
        ("irregular-gap", "irregular: P8, P9, then P10 = 0 stops", {"p8": 205, "p9": 206, "p11": 207}),
        ("irregular-cue", "irregular with cue size", {"p8": 107, "p9": 209, "p6": 100}),
        ("p26-grey", "P26 = 0.5", {"p5": 3, "p26": 0.5}),
        ("p10-pixels", "P10 = 1", {"p5": 3, "p10": 1}),
    ]
    single = [built(f"code17-{name}", desc, [staff(), key(**params)]) for name, desc, params in one]
    staves = [
        *[(f"staff-size-{label(s)}-{label(n)}", f"staff size {s}, P5 = {n}", {"p5": s}, {"p5": n})
          for s in (0.75, 1.4, -1) for n in (5, -6)],
        ("staff-size-0.7-tenor", "staff size 0.7, tenor sharps", {"p5": 0.7}, {"p5": 7, "p6": 3}),
        ("staff-recto-201", "recto staff 201, P5 = 3", {"p2": 201}, {"p2": 201, "p5": 3}),
    ]
    on_staves = [built(f"code17-{name}", desc, [staff(**s), key(**k)]) for name, desc, s, k in staves]
    return single + on_staves
