"""Differential fuzzing of score_render against the emulated engine.

    python fuzz.py [--per-code N] [--pages N] [--codes 1,2,...] [--seed S] [--jobs J] [--shrink K]

Random items are built from the parameter values that the fixtures already use for each
code (Smith's documented value classes, one at a time) and recombined, with occasional
perturbations (fractions, signs, scaling). Each item is drawn alone on a staff; random
pages mix codes. Every case is drawn by the oracle (snapshot engines, one per worker)
and by score_render (score-compare --json). Mismatches are shrunk to the fewest items and
non-zero parameters that still differ, saved as fuzz-codeNN-* cases in fuzz_cases.json
(turned into fixtures by fixtures_code_fuzz.py) and summarised in rust/fixtures/FUZZ.md.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import random
import shutil
import subprocess
import sys
from collections import Counter, defaultdict
from concurrent.futures import ProcessPoolExecutor
from dataclasses import dataclass, field, replace
from pathlib import Path

from fixtures import FIXTURES, SANDBOXES, Case, use_snapshot_engine, worker_sandbox, write_fixture
from musbuild import param, read_items, text_item

ORACLE = Path(__file__).resolve().parent
CASES_FILE = ORACLE / "fuzz_cases.json"
ROUNDS_FILE = ORACLE / "fuzz_rounds.json"
REPORT = FIXTURES / "FUZZ.md"
COMPARE = Path("/Users/nielspfeffer/Projects/winscore/rust/target-verifier/release/score-compare")
SCRATCH = SANDBOXES / "fuzz"

CODES = (1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 14, 16, 17, 18)
OWNERS = {1: "impl-notes", 2: "impl-notes", 3: "impl-symbols", 4: "impl-lines", 5: "impl-beams", 6: "impl-beams",
          7: "impl-lines", 8: "render-core", 9: "impl-lines", 10: "impl-symbols", 11: "impl-symbols",
          12: "impl-symbols", 14: "render-core", 15: "impl-lines", 16: "impl-text", 17: "impl-symbols", 18: "impl-text"}
POSITIONED_PAIR = {4, 5, 6}
SHRINK_ATTEMPTS = 250                 # oracle runs per shrink; a page ends up small long before that           # P3 … P6 run from a left to a right position
# Parameters that are measures (positions, sizes, displacements, angles) rather than enumerated
# codes. Only these are perturbed; a type, font or mark number keeps one of its documented values.
MEASURES = {
    1: {4, 8, 13, 14, 15, 18, 19, 20, 29, 31}, 2: {4, 10, 11, 12, 15, 16}, 3: {6, 7, 15},
    4: {4, 6, 8, 9, 10, 13, 14, 15}, 5: {4, 5, 6, 7, 9, 10, 13, 14, 15, 17, 18, 19},
    6: {4, 5, 6, 11, 12, 14, 15, 16, 17, 18, 19}, 7: {4, 5, 6, 9, 11, 15, 18}, 8: {3, 4, 5, 6, 10, 14},
    9: {4, 6, 7, 9, 15}, 10: {4, 6, 9, 11, 12, 15}, 12: {4, 6, 7, 9, 10, 11, 15},
    14: {6, 7, 8, 9, 10, 11, 12, 13, 14, 18, 19}, 16: {4, 5, 6, 7, 9, 10, 11}, 17: {4, 7, 15},
    18: {4, 7, 10, 11, 15, 20},
}
TEXT_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789 .,;:!-()'/"


# -- items and cases -----------------------------------------------------------------

@dataclass(frozen=True)
class Item:
    params: tuple[float, ...]
    text: bytes = b""

    @property
    def code(self) -> int:
        return int(self.params[0])

    def p(self, n: int) -> float:
        return self.params[n - 1] if n <= len(self.params) else 0.0

    def with_param(self, n: int, value: float) -> "Item":
        params = list(self.params) + [0.0] * max(0, n - len(self.params))
        params[n - 1] = value
        least = 13 if self.text else 3
        while len(params) > least and params[-1] == 0:
            params.pop()
        return replace(self, params=tuple(params))

    def packed(self) -> bytes:
        return text_item(list(self.text_layout() if self.text else self.params), self.text)

    def text_layout(self) -> tuple[float, ...]:
        """The engine reads a text item's characters after P13, or after P16 when P14 = -1 (colour block)."""
        width = 16 if self.p(14) == -1 else 13
        return tuple(self.p(n) for n in range(1, width + 1))

    def nonzero(self) -> list[int]:
        params = self.text_layout() if self.text else self.params
        return [n for n in range(5, len(params) + 1) if params[n - 1] and not (self.text and n in (12, 13))]


@dataclass(frozen=True)
class FuzzCase:
    name: str
    items: tuple[Item, ...]
    target: int | None          # index of the fuzzed item; None for a page

    @property
    def code(self) -> int:
        return self.items[self.target].code if self.target is not None else 0

    def case(self) -> Case:
        from musbuild import mus_bytes
        return Case(self.name, f"fuzz {self.name}", mus_bytes([i.packed() for i in self.items]))

    def to_json(self) -> dict:
        return {"name": self.name, "target": self.target,
                "items": [{"params": list(i.params), "text": i.text.decode("latin-1")} for i in self.items]}

    @classmethod
    def from_json(cls, d: dict) -> "FuzzCase":
        items = tuple(Item(tuple(i["params"]), i["text"].encode("latin-1")) for i in d["items"])
        return cls(d["name"], items, d["target"])


# -- value pools ---------------------------------------------------------------------

def value_pools() -> dict[int, dict[int, list[float]]]:
    """Per code and parameter: the non-zero values the fixtures use (P1 and P2 excluded)."""
    pools: dict[int, dict[int, set[float]]] = defaultdict(lambda: defaultdict(set))
    texts: list[bytes] = []
    for path in sorted(FIXTURES.glob("code*/input.mus")):
        for packed in read_items(path.read_bytes()):
            code, count = int(param(packed, 1)), len(packed) // 4
            chars = int(param(packed, 12)) if code == 16 else 0
            last = count - (chars + 3) // 4          # a text item's characters follow its parameters
            for n in range(3, last + 1):
                value = round(param(packed, n), 4)
                if value and not (code == 16 and n in (12, 13)):
                    pools[code][n].add(value)
            if code == 16:
                texts.append(packed[4 * last:][:chars])
    result = {code: {n: sorted(v) for n, v in by_param.items()} for code, by_param in pools.items()}
    result[16][0] = sorted({t.decode("latin-1") for t in texts if b"~" not in t})   # strings, keyed 0
    return result


# -- generators ----------------------------------------------------------------------

def perturbed(rng: random.Random, value: float) -> float:
    """A nearby measure: shifted, scaled, a random fraction off, or (rarely) of the other sign."""
    choice = rng.random()
    if choice < 0.4:
        return round(value + rng.choice([-1, 1]) * rng.choice([0.1, 0.25, 0.5, 1, 2]), 3)
    if choice < 0.7:
        return round(value * rng.choice([0.5, 0.75, 1.5, 2]), 3)
    if choice < 0.9:
        return round(value + rng.uniform(-0.99, 0.99), 2)
    return -value


def random_text(rng: random.Random, pools: dict) -> bytes:
    if rng.random() < 0.4 and pools[16][0]:
        return rng.choice(pools[16][0]).encode("latin-1")
    font = rng.choice([f"_{n:02d}" for n in list(range(35)) + [90, 91, 92, 93, 94]])
    body = "".join(rng.choice(TEXT_CHARS) for _ in range(rng.randint(1, 18)))
    if rng.random() < 0.2:
        cut = rng.randint(0, len(body))
        body = body[:cut] + rng.choice(["_00", "_02", "_16", "_23"]) + body[cut:]
    return (font + body).encode("latin-1")


def staff_item(rng: random.Random, number: int = 1, varied: bool = False) -> Item:
    size = rng.choice([1, 1, 1, 0.7, 0.85, 1.2, 1.5, 0.6]) if varied else 1
    return Item((8.0, float(number), 0.0, 0.0, float(size)))


def random_item(rng: random.Random, code: int, pools: dict, staff: int = 1, x: float | None = None) -> Item:
    pool = pools.get(code, {})
    left = round(x if x is not None else rng.uniform(15, 175), 2)
    vertical = rng.choice(pool.get(4, [0.0]) + [0.0]) if rng.random() < 0.7 else round(rng.uniform(-6, 14) * 2) / 2
    item = Item((float(code), float(staff), left, vertical))
    if code in POSITIONED_PAIR:
        item = item.with_param(6, round(min(198, left + rng.uniform(5, 60)), 2))
        if code != 4 or rng.random() < 0.5:
            item = item.with_param(5, rng.choice(pool.get(5, [vertical])))
    extra = [n for n in pool if n >= 5 and n not in (6 if code in POSITIONED_PAIR else -1,)]
    if code == 16:
        extra = [n for n in extra if n not in (12, 13)]
    for n in rng.sample(extra, min(len(extra), rng.choice([1, 1, 2, 2, 3, 4, 5]))):
        value = rng.choice(pool[n])
        measure = n in MEASURES.get(code, set())
        item = item.with_param(n, perturbed(rng, value) if measure and rng.random() < 0.3 else value)
    if code == 16:
        # The text goes in first: with_param keeps 13 parameters only for an item that has characters,
        # and the engine reads the characters after P13 whatever the item length.
        text = random_text(rng, pools)
        item = replace(item, text=text).with_param(6, item.p(6) or 1).with_param(12, float(len(text))).with_param(13, 0.0)
        if item.p(15) or item.p(16):                 # layer and colour only count after P14 = -1
            item = item.with_param(14, -1.0)
    return item


def single_case(rng: random.Random, code: int, pools: dict, index: int) -> FuzzCase:
    if code == 8:
        staff = random_item(rng, 8, pools)
        staff = replace(staff, params=(8.0, float(rng.choice([1, 1, 2, 3])), *staff.params[2:]))
        return FuzzCase(f"code08-{index}", (staff,), 0)
    staves = [staff_item(rng, n + 1, varied=rng.random() < 0.3) for n in range(3 if code in (1, 14) else 1)]
    on = 2 if code == 1 and rng.random() < 0.3 else 1
    item = random_item(rng, code, pools, staff=on)
    return FuzzCase(f"code{code:02d}-{index}", (*staves, item), len(staves))


def page_case(rng: random.Random, pools: dict, index: int) -> FuzzCase:
    """Two staves with clef, key, meter, notes (some beamed), rests, a slur, barlines and some decoration."""
    items = [staff_item(rng, 1, True), staff_item(rng, 2, True)]
    items += [Item((14.0, 1.0, 0.0, 2.0))]
    for staff in (1, 2):
        items += [Item((3.0, float(staff), 2.0, 0.0, float(rng.choice([0, 1, 0, 2]))))]
        if rng.random() < 0.5:
            items += [Item((17.0, float(staff), 8.0, 0.0, float(rng.randint(-5, 5))))]
        if rng.random() < 0.7:
            items += [Item((18.0, float(staff), 16.0, 0.0, float(rng.choice([2, 3, 4, 6])), float(rng.choice([4, 8]))))]
        x = 25.0
        while x < 185:
            if rng.random() < 0.25:
                run = rng.randint(2, 4)
                up = rng.random() < 0.5
                pitches = [rng.randint(-1, 11) for _ in range(run)]
                stem = 10 if up else 20
                xs = [round(x + 6 * k, 2) for k in range(run)]
                items += [random_item(rng, 1, pools, staff, xs[k]) if rng.random() < 0.3 else
                          Item((1.0, float(staff), xs[k], float(pitches[k]), float(stem), 0.0, 0.5)) for k in range(run)]
                stem_end = [p + 7 if up else p - 7 for p in (pitches[0], pitches[-1])]
                items += [Item((6.0, float(staff), xs[0], float(stem_end[0]), float(stem_end[1]), xs[-1],
                                float(11 if up else 21)))]
                x = xs[-1] + 9
            elif rng.random() < 0.15:
                items += [random_item(rng, 2, pools, staff, x)]
                x += 9
            else:
                items += [random_item(rng, 1, pools, staff, x) if rng.random() < 0.4 else
                          Item((1.0, float(staff), x, float(rng.randint(-2, 12)), float(rng.choice([10, 20])), 0.0, 1.0))]
                x += 9
            if rng.random() < 0.12 and x < 185:
                items += [Item((14.0, 1.0, round(x, 2), 2.0))]
                x += 4
    for code in rng.sample([4, 5, 7, 9, 10, 12, 16], rng.randint(2, 4)):
        items += [random_item(rng, code, pools, rng.choice([1, 2]))]
    items += [Item((14.0, 1.0, 199.0, 2.0, float(rng.choice([0, 2]))))]
    return FuzzCase(f"page-{index}", tuple(items), None)


# -- running -------------------------------------------------------------------------

@dataclass
class Result:
    case: FuzzCase
    valid: bool
    outcome: str = ""                     # match, differs, failed, invalid
    findings: list[dict] = field(default_factory=list)
    reason: str = ""
    engine_points: dict[int, int] = field(default_factory=dict)   # file item -> points the engine drew for it

    def codes(self) -> set[int]:
        return {f["code"] for f in self.findings if f.get("code") is not None}


def compare_dir(directory: Path) -> dict[str, dict]:
    report = directory / "compare.json"
    subprocess.run([str(COMPARE), "--fixtures", str(directory), "--status", "-", "--json", str(report)],
                   capture_output=True, check=False)
    return {row["case"]: row for row in json.loads(report.read_text())} if report.is_file() else {}


def compare_one(directory: Path, name: str) -> dict[str, dict]:
    """Compare one case on its own, so that a fixture score-compare cannot load spoils nothing else."""
    alone = directory / "alone"
    shutil.rmtree(alone, ignore_errors=True)
    alone.mkdir()
    shutil.copytree(directory / name, alone / name)
    rows = compare_dir(alone)
    shutil.rmtree(alone, ignore_errors=True)
    return rows


def evaluate(cases: list[FuzzCase], directory: Path) -> list[Result]:
    """Run in a worker: oracle fixtures for the cases into `directory`, then score-compare over it."""
    shutil.rmtree(directory, ignore_errors=True)
    directory.mkdir(parents=True)
    written = {c.name: write_fixture(c.case(), directory, False) for c in cases}
    rows = compare_dir(directory)
    if len(rows) < len(cases):
        rows = {name: row for c in cases for name, row in compare_one(directory, c.name).items()}
    results = []
    for c in cases:
        w, row = written[c.name], rows.get(c.name, {})
        if not w.valid:
            results.append(Result(c, False, "invalid", reason="; ".join(w.reasons)))
            continue
        results.append(Result(c, True, row.get("result", "failed"), row.get("findings", []), row.get("reason", ""),
                              points_per_item(directory / c.name / "engine.json")))
    shutil.rmtree(directory, ignore_errors=True)
    return results


def points_per_item(engine_json: Path) -> dict[int, int]:
    counts: Counter = Counter()
    for shape in json.loads(engine_json.read_text())["shapes"]:
        if shape.get("item") is not None:
            counts[shape["item"]] += sum(len(path) for path in shape["paths"])
    return dict(counts)


def evaluate_batch(cases: list[FuzzCase]) -> list[Result]:
    return evaluate(cases, SCRATCH / f"batch-{os.getpid()}")


# -- known deviations ----------------------------------------------------------------

def deviation(item: Item) -> str | None:
    """Combinations the owners deliberately do not imitate (their status files)."""
    c = item.code
    rules = [
        (c == 1 and item.p(13) == 99, "P13 = 99 mark position (impl-notes, by design)"),
        (c == 1 and -39 <= item.p(6) <= -26, "P6 -26…-39 (impl-notes, by design)"),
        (c == 1 and item.p(6) < 0 and item.p(8) < 0, "tablature with P8 < 0 (impl-notes, by design)"),
        (c == 2 and item.p(9) == -1, "rest CW centring P9 = -1 writes back (impl-notes, by design)"),
        (c == 5 and item.p(9) == 99 and item.p(16) != 0, "triangle with number uses stale spacing (impl-beams)"),
        (c == 5 and any(item.p(n) and not 0 < item.p(n) <= 1 for n in (14, 15)),
         "slur cut P14/P15 outside 0…1 finds no place and reads stale state (impl-beams)"),
        (c == 6 and item.p(10) == 0 and item.p(8) <= 0 and item.p(13) != 0, "second partial with stale line (impl-beams)"),
        (c == 6 and item.p(8) != 0 and int(item.p(17)) >= 1, "beam number letter from P17 (impl-beams, by design)"),
        (c == 12 and item.p(16) == 1, "box P16 = 1 cm scaling (impl-lines, not imitated)"),
        (c == 7 and item.p(7) == 1 and (item.p(16) == 1 or item.p(18) != 0),
         "harp diagram boxes read P16 as the box cm flag (impl-lines, not imitated)"),
        (c == 9 and item.p(5) in (949, 959, 1128), "library slot with start offset <= 0 (impl-symbols)"),
        (c == 8 and item.p(2) == 1 and item.p(10) != 0,
         "staff 1 placed by its own P10 moves on every draw (engine; analysis/engine/coordinates.md)"),
    ]
    return next((reason for applies, reason in rules if applies), None)


POINT_BUFFER = 50_000   # add_point has no bound; beyond this the engine overwrites earlier coordinates (impl-symbols)


TEXT_X_REENCODING = 20_000   # 0x56AC18: glyphs left of internal x ≈ -19000 land 20000 units further right (impl-text)


def is_reencoded_glyph(finding: dict) -> bool:
    delta = finding.get("delta")
    return (finding.get("symptom") == "text offset" and delta is not None
            and abs(delta[0] + TEXT_X_REENCODING) <= 1 and abs(delta[1]) <= 1)


def known_deviation(result: Result) -> str | None:
    codes = result.codes()
    if any(points > POINT_BUFFER for points in result.engine_points.values()):
        return "item with more than 50,000 points overflows the engine's point buffer (impl-symbols, not imitated)"
    if result.findings and all(map(is_reencoded_glyph, result.findings)):
        return "glyphs far left of the paper re-encoded 20000 units right (impl-text, engine bug not imitated)"
    return next((r for i in result.case.items if i.code in codes and (r := deviation(i))), None)


# -- shrinking -----------------------------------------------------------------------

def symptoms_for(result: Result, code: int) -> set[str]:
    return {f["symptom"] for f in result.findings if f.get("code") == code}


def still_fails(case: FuzzCase, code: int, symptoms: set[str], directory: Path) -> Result | None:
    (result,) = evaluate([case], directory)
    if result.valid and result.outcome in ("differs", "failed") and (result.outcome == "failed" or symptoms & symptoms_for(result, code)):
        return result if not known_deviation(result) else None
    return None


def simpler_values(value: float) -> list[float]:
    options = [0.0, float(int(value)), round(value, 1), round(value)]
    return [v for v in dict.fromkeys(options) if v != value]


def staves_used(item: Item) -> set[float]:
    """The staves an item draws on: its own, those a barline spans, the one a note moves to with P12."""
    staff = item.p(2)
    if item.code == 14 and item.p(4):
        span = 256 if abs(item.p(4)) >= 999 else int(abs(item.p(4)))
        return {staff + k for k in range(max(1, span))}
    if item.code == 1 and item.p(12) in (1, 2):
        return {staff, staff + 1 if item.p(12) == 1 else staff - 1}
    return {staff}


def without(case: FuzzCase, drop: set[int]) -> FuzzCase | None:
    """The case minus the items at `drop`; None if that removes the target or a staff a remaining item uses."""
    kept = [n for n in range(len(case.items)) if n not in drop]
    hanging = {s for n in kept if case.items[n].code != 8 for s in staves_used(case.items[n])}
    dropped_staves = {case.items[n].p(2) for n in drop if n < len(case.items) and case.items[n].code == 8}
    if case.target in drop or not kept or dropped_staves & hanging:
        return None
    target = kept.index(case.target) if case.target is not None else None
    return replace(case, items=tuple(case.items[n] for n in kept), target=target)


def shrink(result: Result, code: int) -> tuple[FuzzCase, Result]:
    """Run in a worker: drop items (halves, then smaller chunks), then zero and simplify parameters, while the mismatch stays."""
    directory = SCRATCH / f"shrink-{os.getpid()}"
    symptoms = symptoms_for(result, code) or {"failed"}
    case, best = result.case, result

    attempts = 0

    def attempt(candidate: FuzzCase) -> bool:
        nonlocal case, best, attempts
        attempts += 1
        if attempts > SHRINK_ATTEMPTS:
            return False
        found = still_fails(candidate, code, symptoms, directory)
        if found:
            case, best = candidate, found
        return found is not None

    size = len(case.items) // 2
    while size >= 1:
        start = 0
        while start < len(case.items):
            candidate = without(case, set(range(start, start + size)))
            if candidate is None or not attempt(candidate):
                start += size
        size //= 2
    for position in range(len(case.items)):
        for n in list(case.items[position].nonzero()):
            for value in simpler_values(case.items[position].p(n)):
                items = list(case.items)
                items[position] = items[position].with_param(n, value)
                if attempt(replace(case, items=tuple(items))):
                    break
    return case, best


# -- saving --------------------------------------------------------------------------

def signature(case: FuzzCase, code: int, symptoms: set[str]) -> str:
    items = [i for i in case.items if i.code == code] or list(case.items)
    params = sorted({n for i in items for n in i.nonzero()})
    return f"code{code:02d}-" + "-".join(f"p{n}" for n in params) + "|" + ",".join(sorted(symptoms))


def saved_name(case: FuzzCase, code: int, sig: str) -> str:
    params = sig.split("|")[0].split("-", 1)[1] if "-" in sig.split("|")[0] else "base"
    digest = hashlib.sha1(json.dumps(case.to_json()["items"]).encode()).hexdigest()[:6]
    return f"fuzz-code{code:02d}-{params or 'base'}-{digest}"[:72]


def load_saved() -> list[dict]:
    return json.loads(CASES_FILE.read_text()) if CASES_FILE.is_file() else []


# -- driver --------------------------------------------------------------------------

def chunks(items: list, size: int) -> list[list]:
    return [items[i:i + size] for i in range(0, len(items), size)]


def main(argv: list[str]) -> int:
    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("--per-code", type=int, default=200)
    parser.add_argument("--pages", type=int, default=50)
    parser.add_argument("--codes", default=",".join(map(str, CODES)))
    parser.add_argument("--seed", type=int, default=1)
    parser.add_argument("--jobs", type=int, default=4, help="workers; the machine is shared, keep it small")
    parser.add_argument("--shrink", type=int, default=3, help="mismatches shrunk per (code, symptoms, parameters) group")
    parser.add_argument("--report-only", action="store_true", help="re-run the saved cases and rewrite FUZZ.md")
    args = parser.parse_args(argv)

    saved_cases = [FuzzCase.from_json(entry) for entry in load_saved()]
    try:
        with ProcessPoolExecutor(max_workers=args.jobs, initializer=use_snapshot_engine) as pool:
            rechecked = {r.case.name: r for batch in pool.map(evaluate_batch, chunks(saved_cases, 25)) for r in batch}
            if not args.report_only:
                rounds = load_rounds() + [fuzz_round(args, pool)]
                ROUNDS_FILE.write_text(json.dumps(rounds, indent=1) + "\n")
    finally:
        shutil.rmtree(SANDBOXES, ignore_errors=True)
    prune_deviations(rechecked)
    REPORT.write_text(render_report(load_rounds(), {c["name"]: c for c in load_saved()}, rechecked))
    print(REPORT.read_text().split("\n## Saved")[0])
    return 0


def fuzz_round(args, pool) -> dict:
    rng = random.Random(args.seed)
    pools = value_pools()
    codes = [int(c) for c in args.codes.split(",") if c]
    cases = [single_case(rng, code, pools, i) for code in codes for i in range(args.per_code)]
    cases += [page_case(rng, pools, i) for i in range(args.pages)]
    print(f"{len(cases)} cases", flush=True)
    results = []
    for done, batch in enumerate(pool.map(evaluate_batch, chunks(cases, 25)), start=1):
        results += batch
        if done % 20 == 0:
            print(f"{len(results)} of {len(cases)} evaluated", flush=True)
    per_code, deviations, new = analyse(results, args, pool)
    return {"seed": args.seed, "per_code": args.per_code, "pages": args.pages,
            "counts": {label: dict(c) for label, c in sorted(per_code.items())},
            "deviations": dict(deviations.most_common()), "new_cases": new}


def prune_deviations(rechecked: dict[str, "Result"]) -> None:
    """Saved cases that a deviation rule now covers are no longer open bugs: drop them and their fixtures."""
    keep = []
    for entry in load_saved():
        result = rechecked.get(entry["name"])
        reason = known_deviation(result) if result is not None and result.outcome != "match" else None
        if reason:
            print(f"dropped {entry['name']}: {reason}")
            shutil.rmtree(FIXTURES / entry["name"], ignore_errors=True)
        else:
            keep.append(entry)
    CASES_FILE.write_text(json.dumps(keep, indent=1) + "\n")


def load_rounds() -> list[dict]:
    return json.loads(ROUNDS_FILE.read_text()) if ROUNDS_FILE.is_file() else []


def group_key(result: Result, code: int) -> str:
    return signature(result.case, code, symptoms_for(result, code) or {result.outcome})


def analyse(results: list[Result], args, pool) -> tuple[dict[str, Counter], Counter, list[str]]:
    """Counts per code, known deviations hit, and the names of the minimal cases saved from this round."""
    per_code: dict[str, Counter] = defaultdict(Counter)
    to_shrink: dict[str, list[tuple[Result, int]]] = defaultdict(list)
    deviations: Counter = Counter()
    for r in results:
        label = f"code {r.case.code:02d}" if r.case.target is not None else "pages"
        per_code[label]["cases"] += 1
        if not r.valid:
            per_code[label]["invalid (oracle)"] += 1
            continue
        if r.outcome == "match":
            per_code[label]["match"] += 1
            continue
        if (reason := known_deviation(r)):
            per_code[label]["known deviation"] += 1
            deviations[reason] += 1
            continue
        per_code[label]["mismatch"] += 1
        for code in (r.codes() or {r.case.code}):
            key = group_key(r, code)
            if len(to_shrink[key]) < args.shrink:
                to_shrink[key].append((r, code))
    jobs = [(r, code) for group in to_shrink.values() for r, code in group]
    shrunk = list(pool.map(shrink_job, jobs)) if jobs else []
    minimal: dict[str, tuple[FuzzCase, Result, int]] = {}
    for (case, best), (original, code) in zip(shrunk, jobs):
        if case.target is None and original.case.target is None:
            code_items = [n for n, i in enumerate(case.items) if i.code == code]
            case = replace(case, target=code_items[0] if code_items else None)
        sig = signature(case, code, symptoms_for(best, code) or {best.outcome})
        if sig not in minimal or len(case.items) < len(minimal[sig][0].items):
            minimal[sig] = (case, best, code)
    by_items: dict[str, str] = {}
    for sig in sorted(minimal, key=lambda s: minimal[s][2] != minimal[s][0].code):
        items = json.dumps(minimal[sig][0].to_json()["items"])
        if items in by_items:
            del minimal[sig]
        else:
            by_items[items] = sig
    return per_code, deviations, save_minimal(minimal)


def save_minimal(minimal: dict[str, tuple[FuzzCase, "Result", int]]) -> list[str]:
    saved = {c["name"]: c for c in load_saved()}
    names = []
    for sig, (case, best, code) in minimal.items():
        name = saved_name(case, code, sig)
        saved[name] = {**replace(case, name=name).to_json(), "code": code, "signature": sig,
                       "owner": OWNERS.get(code, "?"), "symptoms": sorted(symptoms_for(best, code) or {best.outcome}),
                       "detail": next((f["detail"] for f in best.findings if f.get("code") == code), best.reason)}
        names.append(name)
    CASES_FILE.write_text(json.dumps(sorted(saved.values(), key=lambda c: c["name"]), indent=1) + "\n")
    return names


def shrink_job(job: tuple[Result, int]) -> tuple[FuzzCase, Result]:
    result, code = job
    return shrink(result, code)


def items_text(entry: dict) -> str:
    return "; ".join(" ".join(f"{p:g}" for p in i["params"]) + (f" {i['text']!r}" if i["text"] else "") for i in entry["items"])


def render_report(rounds: list[dict], saved: dict[str, dict], rechecked: dict[str, Result]) -> str:
    lines = ["# Differential fuzzing", "",
             "Written by `oracle/fuzz.py`. Random items per code are recombined from the parameter values the fixtures "
             "use (documented value classes), with measures perturbed; random pages mix codes. Each case is drawn by the "
             "emulated engine and by `score_render`; *mismatch* = any element differs beyond ±1 unit or the renderer "
             "panics. Combinations the owners list as deliberate deviations are counted apart. Cases the oracle rejects "
             "(dialogs, messages, coordinate overflow) are *invalid* and not compared.", ""]
    for number, rnd in reversed(list(enumerate(rounds, start=1))):
        lines += [f"## Round {number} (seed {rnd['seed']}, {rnd['per_code']} items per code, {rnd['pages']} pages)", "",
                  "| | cases | invalid (oracle) | match | known deviation | mismatch | mismatch rate |",
                  "|---|---|---|---|---|---|---|"]
        for label, c in rnd["counts"].items():
            get = lambda k: c.get(k, 0)  # noqa: E731
            compared = get("match") + get("mismatch") + get("known deviation")
            rate = f"{100 * get('mismatch') / compared:.1f} %" if compared else ""
            lines.append(f"| {label} | {get('cases')} | {get('invalid (oracle)')} | {get('match')} | "
                         f"{get('known deviation')} | {get('mismatch')} | {rate} |")
        if rnd["deviations"]:
            lines += ["", "Known deviations hit: " + "; ".join(f"{r} ×{n}" for r, n in rnd["deviations"].items()) + "."]
        if rnd["new_cases"]:
            lines += ["", "New minimal cases: " + ", ".join(f"`{n}`" for n in rnd["new_cases"]) + "."]
        lines.append("")
    lines += ["## Saved minimal cases", "",
              "Every case in `oracle/fuzz_cases.json` (fixtures `rust/fixtures/<name>/`), shrunk to the fewest items and "
              "non-zero parameters that still differ, with its status when this report was written.", "",
              "| case | owner | status | symptoms | items | detail |", "|---|---|---|---|---|---|"]
    for name, entry in sorted(saved.items()):
        r = rechecked.get(name)
        status = "new" if r is None else ("fixed" if r.outcome == "match" else "open" if r.outcome == "differs" else r.outcome)
        detail = str(entry["detail"])[:140].replace("|", "/")
        lines.append(f"| {name} | {entry['owner']} | {status} | {', '.join(entry['symptoms'])} | `{items_text(entry)}` | {detail} |")
    return "\n".join(lines) + "\n"


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
