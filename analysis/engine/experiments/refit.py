"""Reference model of 0x47C3E8, the re-input of one staff's notes through IN's passes that group
FLU/FLD/FLI/FLN and TR run, and its check against the oracle.

    python refit.py [cases] [FLU|FLD|FLI|FLN]

0x47C3E8 collects the notes, beams and slurs of a staff inside an x range, encodes the notes as
IN streams (pass 1 pitches with stem codes, pass 2 rhythms, pass 3 marks, pass 4 beams, pass 5
slurs), lets IN's own pass routines rebuild its work table, and writes the results back into the
items. This model covers everything except the five pass routines, which score-input ports: it
builds the streams the engine hands to them and applies the write-back to the work-table rows
they produce. The check compares the streams with the engine's at each pass entry and, feeding
the engine's rows into the write-back, the final items bit for bit.

Item indices are 1-based. A work-table row r holds P1..P15 of one entry (0x1F95D44 + 0x3C*r).
"""
from __future__ import annotations

import random
import struct
import sys
from dataclasses import dataclass, field

from beam_stems import adjust_beam
from staves import f32 as F, trunc

STEM_UP, STEM_DOWN, NORMAL_SIZE, CUE_SIZE = F(5010), F(5020), F(8000), F(8001)


class RefitAbort(Exception):
    """0x47C3E8 leaves the staff (items may already carry the beam-end snaps)."""


def amod(x, y):
    return F(x - trunc(x / y) * y)


def cmod(a: int, b: int) -> int:
    return a - b * trunc(a / b)


def par(it, k):
    return it[k - 1] if len(it) >= k else 0.0


def set_length(it: list[float], n: int):
    """0x5239C9: the item gets exactly n parameters (zeros added, or words cut)."""
    del it[n:]
    it.extend([0.0] * (n - len(it)))


@dataclass
class BeamRecord:
    item: int                       # negative: another beam at the same x as the record before
    params: list[float]             # copy of the beam's parameters when it was collected


@dataclass
class Collected:
    notes: list[int] = field(default_factory=list)
    beams: list[int] = field(default_factory=list)
    slurs: list[int] = field(default_factory=list)
    records: list[BeamRecord] = field(default_factory=list)


def collect(items, staff: int, x0: float, x1: float) -> Collected:
    """First loop of 0x47C3E8 (snaps beam ends to notes within 0.01, in place)."""
    item = lambda i: items[i - 1]
    out = Collected()
    prev_beam_x, same_x = 0.0, False
    for i, it in enumerate(items, 1):
        if not (trunc(it[1]) == staff and x0 <= par(it, 3) and trunc(it[0]) != 16):
            continue
        x = par(it, 3)
        if x1 < x:
            break
        c, n = trunc(it[0]), len(it)
        if c == 6:
            if n <= 6:
                continue
            if it[6] < 0 or x1 < it[5]:
                raise RefitAbort(f"beam item {i}: P7 < 0 or beyond the range")
            end_x = it[5]
            if prev_beam_x != x:
                same_x = False
            out.records.append(BeamRecord(-i if same_x else i, list(it)))
            same_x, prev_beam_x = True, x
            count = 0
            for j, other in enumerate(items, 1):
                if not (other[0] == 1 and trunc(other[1]) == trunc(it[1])):
                    continue
                nx = par(other, 3) if len(other) >= 3 else 0.0
                if abs(nx - it[2]) <= F(0.01):
                    if it[2] != nx:
                        it[2] = nx
                    if count < 51:
                        count += 1
                elif abs(nx - end_x) > F(0.01):
                    continue
                else:
                    if end_x != nx:
                        it[5] = nx
                    if count < 50:
                        count += 50
                d7 = par(other, 7) if len(other) >= 7 else 0.0
                if F(0.99) <= d7 < 64:
                    raise RefitAbort(f"beam item {i}: a note at its end has 0.99 <= P7 < 64")
                if count > 50:
                    break
            out.beams.append(i)
            continue
        if c == 5:
            if not (n < 7 or (n != 7 and trunc(it[7]) in (1, 2)) or it[6] == 0):
                out.slurs.append(i)
        if c == 1:
            if len(out.notes) > 99:
                raise RefitAbort("more than 99 notes")
            if n > 9 and amod(it[9], 10) != 0:
                continue
            out.notes.append(i)
    return out


@dataclass
class Streams:
    pitches: list[float]
    rhythms: list[float]
    marks: list[float]
    durations: list[float]          # per note slot (0 for chord members)
    dots: list[int]
    rhythmic: int                   # number of rhythmic notes + 1 (0x1BA0B98)


def build_streams(items, col: Collected, mode: int, stem_code: float = STEM_DOWN) -> Streams:
    """Second loop of 0x47C3E8 and the rhythm/marks loops; may reorder col.notes (chord stems first)."""
    item = lambda i: items[i - 1]
    if mode == 3:
        stem_code = STEM_DOWN
    if mode == 4:
        stem_code = STEM_UP
    pitches: list[float] = []
    marks: list[tuple[float, int]] = []
    durations, dots_of = [0.0] * len(col.notes), [0] * len(col.notes)
    rhythmic, stem_seen, cue, prev_x = 1, False, -1, 0.0
    notes = col.notes
    for k in range(len(notes)):
        dots, dur = 0, 0.0
        while True:
            it = item(notes[k])
            n = len(it)
            x = it[2]
            if n < 5:
                acc = 0
                break
            base = 7028 if trunc(it[4]) > 100 else 1028
            stem = cmod(trunc(it[4]), 100)
            if stem > 9:
                if stem_seen and prev_x == x:
                    raise RefitAbort("two stemmed notes at one x")
                stem_seen = True
                if mode != 2:
                    if mode < 3 or mode > 4:
                        stem_code = STEM_UP if not stem < 20 else STEM_DOWN
                    pitches.append(stem_code)
                if n > 10 and trunc(it[10]) != 0:
                    a = trunc(it[10])
                    marks.append((F(float(abs(a) * 10000 + (1 if a < 1 else 0))), rhythmic))
                acc = cmod(stem, 10)
                break
            head = trunc(it[5]) if n > 5 else 0
            if prev_x == x or (n > 5 and head > 1 and (head < 4 or (head not in (95, 139) and head > 10))):
                if n > 10 and trunc(it[10]) != 0:
                    a = trunc(it[10])
                    marks.append((F(float(abs(a) * 10000 + (1 if a < 1 else 0))), rhythmic))
                acc = cmod(stem, 10)
                break
            m = k
            while True:
                m += 1
                if m >= len(notes) or item(notes[m])[2] != x:
                    raise RefitAbort("stemless note without a stemmed note at its x")
                if len(item(notes[m])) < 5:
                    continue
                if amod(item(notes[m])[4], 100) >= 10:
                    break
            notes[k], notes[m] = notes[m], notes[k]
            prev_x = 0.0
        if n > 6:
            dur = it[6]
        p4i = trunc(it[3])
        if dur < 64:
            if abs(p4i) < 100:
                if cue >= 0:
                    pitches.append(NORMAL_SIZE)
                    cue = -cue
            elif cue < 1:
                pitches.append(CUE_SIZE)
                cue = -cue
        code = F(float(acc * 100 + base + cmod(p4i, 100)))
        if prev_x == x:
            pitches.append(F(-code))
            dur = 0.0
        else:
            pitches.append(code)
            stem_seen = False
            if n > 8:
                dots = trunc(cmod(trunc(it[8]), 100) / 10)
            if dur == 0:
                raise RefitAbort("note without duration")
            rhythmic += 1
        durations[k], dots_of[k] = dur, dots
        prev_x = x
    rhythms = [F(F(float(d * 1000)) + min(du, 64.0)) for du, d in zip(durations, dots_of) if du != 0]
    flat_marks = [v for code, note in marks for v in (code, F(float(note)))]
    return Streams(pitches, rhythms, flat_marks, durations, dots_of, rhythmic)


def rhythmic_rows(streams: Streams) -> list[int]:
    """0x1F995BC as the pitch pass leaves it: [0, row of rhythmic note 1, row of note 2, ...]."""
    return [0] + [k for k, d in enumerate(streams.durations, 1) if d != 0]


def link_stream(items, notes: list[int], rhythmic: int, order: list[int], linked: list[int],
                pass_no: int) -> list[float]:
    """0x47DC96: (first note, last note) numbers of every beam (pass 4) or slur (pass 5).

    `order[m]` is the row of the m-th rhythmic note (0x1F995BC, built by the pitch pass); rows
    1..len(notes) hold the notes' P3, so a note is matched through trunc(P3) within 2.
    """
    item = lambda i: items[i - 1]
    row_x = [0.0] + [item(i)[2] for i in notes]
    out: list[float] = []
    prev_x1 = -1
    last = (-999, -999)
    for i in linked:
        it = item(i)
        x1 = trunc(it[2])
        if not (pass_no == 5 or x1 != prev_x1):
            continue
        x2 = trunc(par(it, 6))
        first, final = 0, rhythmic
        for m in range(1, rhythmic):
            xm = trunc(row_x[order[m]]) if order[m] < len(row_x) else 0
            if abs(x1 - xm) < 2:
                first = m
            elif abs(x2 - xm) < 2:
                final = m
        prev_x1 = x1
        if (first, final) == last:
            continue
        if pass_no == 4 and (first == 0 or final == rhythmic):
            continue                                   # the engine reports the beam's item number
        out += [F(float(first)), F(float(final))]
        last = (first, final)
    return out


def write_links(items, rows, start: int, linked: list[int]):
    """0x47E0A9: P4, P5, P7 of beams or slurs from the rows the pass appended after row `start`."""
    item = lambda i: items[i - 1]
    r = start
    for i in linked:
        if rows[r][0] == 0:
            break
        it = item(i)
        if it[2] != rows[r + 1][2]:
            continue
        r += 1
        row = rows[r]
        it[4] = row[4]
        p4 = row[3]
        c = trunc(it[0])
        if c == 1 and len(it) >= 8 and abs(it[3]) >= 100:
            it[7] = F(amod(it[7], 100) * F(1.6666) + 101)
            p4 = F((F(-100) if p4 < 0 else F(100)) + p4)
        it[3] = p4
        if c != 1:
            v = row[6]
            if c == 6:
                v = F(amod(it[6], 10) + trunc(v / 10) * 10)
            it[6] = v


def restore_beams(items, records: list[BeamRecord]):
    """The tail of 0x47C3E8: a beam followed by second-level beams at its x is restored from the
    copy taken at collection (undoing the end snaps) with its new P4, P5 and direction; the
    second-level beams get the same P4, P5 and direction. Records past the end read as 0."""
    rec = [None] + records
    count = len(records)
    signed = lambda e: rec[e].item if 1 <= e <= count else 0
    item = lambda e: items[abs(rec[e].item) - 1]
    level4 = level5 = 0.0
    e = 0
    while True:
        e += 1
        if not e < count:
            return
        while signed(e + 1) < 1:
            it = item(e)
            d = trunc(it[6] / 10)
            target = None
            if d >= 0:
                level4, level5 = it[3], it[4]
                target = e
            while True:
                if target is not None and len(rec[target].params) > 6:
                    it = item(target)
                    it[:] = list(rec[target].params)
                    it[6] = F(float(cmod(trunc(it[6]), 10) + d * 10))
                    it[3], it[4] = level4, level5
                e += 1
                if e > count:
                    return
                if signed(e) > 0:
                    break
                target = e


def write_notes(items, notes: list[int], rows):
    """P4, P5, P8, P9, P10, P11 of every note from its row; notes are extended to 11 parameters."""
    for k, i in enumerate(notes, 1):
        it = items[i - 1]
        if len(it) < 11:
            set_length(it, 11)
        row = rows[k]
        it[7], it[3], it[4], it[9], it[10], it[8] = row[7], row[3], row[4], row[9], row[10], row[8]


def stem_pass(items, staff: int, word: str, right: float = 200.0):
    """0x40CDE4 with P2 = P5 = staff, P3 = 1, P4 = RIGHT: the stems of every beam of the staff."""
    for it in items:
        if trunc(it[0]) == 6 and len(it) >= 7 and trunc(it[1]) == staff and 1 <= it[2] <= right:
            adjust_beam(items, it, word)


# ---------------------------------------------------------------- check against the engine

PASSES = {"pitches": 0x4ECDF8, "rhythms": 0x51CF40, "marks": 0x4D8460, "beams": 0x413CA8,
          "slurs": 0x53D1E0, "links": 0x47E0A9, "stems": 0x40CDE4}


def capture(items, word: str, area: str):
    """Run the group command in the oracle and record the streams, rows and items at each stage."""
    from cmdlab import item_list
    from layoutlab import engine_with
    from unicorn import UC_HOOK_CODE
    engine = engine_with(items)
    f = lambda a: struct.unpack("<f", engine.uc.mem_read(a, 4))[0]
    i32 = lambda a: struct.unpack("<i", engine.uc.mem_read(a, 4))[0]
    seen: dict[str, list] = {}

    def rows(count=120):
        return [[f(0x1F95D44 + 0x3C * r + 4 * k) for k in range(15)] for r in range(count)]

    def hook(name):
        def on(uc, address, size, user):
            n = i32(0x1FB8CC0)
            entry = {"stream": [f(0x1FB8CC0 + 4 * k) for k in range(1, n + 1)] if 0 <= n < 2000 else []}
            if name in ("beams", "slurs"):
                entry["order"] = [i32(0x1F995BC + 4 * m) for m in range(0, 120)]
            if name in ("links", "stems"):
                entry["rows"] = rows()
                entry["items"] = item_list(engine, None)
            seen.setdefault(name, []).append(entry)
        return on
    for name, address in PASSES.items():
        engine.uc.hook_add(UC_HOOK_CODE, hook(name), begin=address, end=address)
    engine.command(word)
    engine.command(area)
    return seen, item_list(engine, None)


def run_model(items, word: str, seen: dict) -> tuple[list[list[float]], list[str]]:
    """The model on one staff, with the engine's pass outputs; returns items and stage mismatches."""
    mode = {"I": 1, "N": 2, "D": 3, "U": 4}[word[2]]
    from lineup import sort_items
    model = sort_items([list(it) for it in items])
    problems: list[str] = []
    try:
        col = collect(model, 1, 0.0, 200.0)
        if not col.notes:
            return model, problems
        streams = build_streams(model, col, mode)
    except RefitAbort:
        if "pitches" in seen:
            problems.append("the model gives up, the engine does not")
        return model, problems
    for name, mine in (("pitches", streams.pitches), ("rhythms", streams.rhythms), ("marks", streams.marks)):
        if name in seen and seen[name][0]["stream"] != mine:
            problems.append(f"{name}: model {mine} engine {seen[name][0]['stream']}")
    order = rhythmic_rows(streams)
    captured = seen["beams"][0]["order"] if "beams" in seen else seen.get("slurs", [{}])[0].get("order", [])
    if captured and captured[1:len(order)] != order[1:]:
        problems.append(f"rows of rhythmic notes: model {order[1:]} engine {captured[1:len(order)]}")
    if col.beams and "beams" in seen:
        mine = link_stream(model, col.notes, streams.rhythmic, order, col.beams, 4)
        if seen["beams"][0]["stream"] != mine:
            problems.append(f"beam links: model {mine} engine {seen['beams'][0]['stream']}")
    links = list(seen.get("links", []))
    added = 0
    if col.beams and links:
        rows = links.pop(0)["rows"]
        write_links(model, rows, len(col.notes), col.beams)
        added = sum(1 for r in rows[len(col.notes) + 1:] if r[0] != 0)
    if col.slurs and mode != 2 and links:
        mine = link_stream(model, col.notes, streams.rhythmic, order, col.slurs, 5)
        if seen["slurs"][0]["stream"] != mine:
            problems.append(f"slur links: model {mine} engine {seen['slurs'][0]['stream']}")
        write_links(model, links.pop(0)["rows"], len(col.notes) + added, col.slurs)
    if "stems" in seen:
        write_notes(model, col.notes, seen["stems"][0]["rows"])
        if col.beams:
            restore_beams(model, col.records)
        stem_pass(model, 1, word)
    return model, problems


def random_staff(rng: random.Random) -> list[list[float]]:
    items = [[8, 1, 0, 0, 1], [3, 1, 2, 0, 0]]
    x = 20.0
    while x < 170:
        group = rng.choice([1, 2, 2, 3, 4])
        dur = rng.choice([0.5, 0.25]) if group > 1 else rng.choice([1, 0.5, 2])
        xs = [round(x + g * 9, 2) for g in range(group)]
        stem = rng.choice([1, 2])
        for gx in xs:
            p4 = rng.randint(-2, 11) + (100 if rng.random() < 0.08 else 0)
            dots = 10 if rng.random() < 0.1 else 0
            note = [1, 1, gx, p4, stem * 10 + rng.choice([0, 0, 1, 2, 3]), 0, dur, 0, dots + (1 if dur == 0.5 else 2)]
            if rng.random() < 0.15:
                note += [0, rng.choice([10000, 20000, -30000])]
            items.append(note)
            if rng.random() < 0.2:
                items.append([1, 1, gx, p4 + rng.choice([-2, 2, 3]), rng.choice([0, 1]), 0, dur])
            if rng.random() < 0.02:
                items.append([1, 1, round(gx + 4, 2), rng.randint(0, 8), 0, 0, dur])
        if group > 1:
            lvl = 13 if stem == 1 else -2
            items.append([6, 1, xs[0], lvl, lvl + rng.choice([-1, 0, 1]), xs[-1], stem * 10 + (1 if dur == 0.5 else 2)])
            if dur == 0.25 and rng.random() < 0.3:
                items.append([6, 1, xs[0], lvl, lvl, xs[-1], stem * 10 + 1])
        if group > 1 and rng.random() < 0.4:
            items.append([5, 1, xs[0], 8, 9, xs[-1], rng.choice([2, 3, -2])])
        x = xs[-1] + rng.uniform(10, 16)
    items.append([14, 1, 200, 1])
    return [[F(float(v)) for v in it] for it in items]


def main(cases: int = 20, word: str = "FLU"):
    rng = random.Random(5)
    good = 0
    for case in range(cases):
        items = random_staff(rng)
        seen, engine = capture(items, word, "1 0 0 0")
        model, problems = run_model(items, word, seen)
        if model == engine and not problems:
            good += 1
            continue
        print(f"case {case} {word}:")
        for p in problems:
            print("  ", p)
        for a, b in zip(model, engine):
            if a != b:
                print("   model ", a, "\n   engine", b)
                break
    print(f"{good}/{cases} staves identical after {word}")


if __name__ == "__main__":
    main(*(int(a) if a.isdigit() else a for a in sys.argv[1:]))
