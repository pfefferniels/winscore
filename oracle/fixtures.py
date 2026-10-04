"""Reference fixtures from the emulated engine.

    python fixtures.py [--out DIR] [--jobs N] [--list] [--no-zoom-check] [PATTERN ...]

For every case of fixtures_cases.py whose name matches a PATTERN (fnmatch, default
all) this writes <out>/<case>/input.mus, engine.json and meta.json. The format is
described in rust/fixtures/README.md.
"""
from __future__ import annotations

import argparse
import fnmatch
import json
import os
import re
import shutil
import struct
import sys
from collections import Counter
from concurrent.futures import ProcessPoolExecutor
from dataclasses import dataclass, field
from pathlib import Path

from callbacks import Event
from displaylist import POLYLINE, FILLED, Shape, TextRun, shapes, text_runs
from emu import Engine, EngineResult, ZOOM
from sandbox import make_sandbox

REPO = Path(__file__).resolve().parents[1]
FIXTURES = REPO / "rust" / "fixtures"
SANDBOXES = Path(__file__).resolve().parent / "sandbox" / "fixtures"
INPUT = "input.mus"
SANDBOX_NAME = "case.mus"   # "G I..." drops the I: the engine reads "G input.mus" as NPUT.MUS

TEXT_TOP_OFFSET = 96            # OnDraw (0x5E5910) draws strings at (x, y + 0x60)
TEXT_RUN_Y_OFFSETS = 0x1576570  # per-run y offset OnDraw adds after scaling
VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4   # emit_points: x_out = x + VIEW_DX, y_out = y - VIEW_DY
PAGE_FROM_INTERNAL = (2000, 26948)        # paper bottom-left at internal (-2000, -26947.7); analysis/engine/coordinates.md
DOCUMENTED_VECTOR_WORDS, DOCUMENTED_TEXT_BYTES = 100_000, 20_000   # ARCHITECTURE.md; carmen exceeds the first
INVALIDATING_EVENTS = {"message", "dialog", "prompt-unanswered"}
QUIET_EVENTS = {"service", "redraw", "document"}
BASE_ZOOM, CHECK_ZOOM = 0x40, 0x80


@dataclass(frozen=True)
class Case:
    name: str
    description: str
    mus: bytes
    commands: tuple[str, ...] = ()
    attachments: tuple[Path, ...] = ()

    @property
    def command_lines(self) -> tuple[str, ...]:
        return (f"G {SANDBOX_NAME}", *self.commands)


@dataclass(frozen=True)
class CommandOutcome:
    command: str
    status: int
    line: str
    vector_words: int
    text_bytes: int


@dataclass
class Run:
    """Everything one engine session produced for a case."""
    outcomes: list[CommandOutcome] = field(default_factory=list)
    events: list[Event] = field(default_factory=list)
    final: EngineResult | None = None
    text_run_y_offsets: list[int] = field(default_factory=list)
    view_dx: int = 0
    view_dy: int = 0
    error: str = ""

    @property
    def offset(self) -> tuple[int, int]:
        """view = page + offset, from the engine's view globals."""
        return self.view_dx - PAGE_FROM_INTERNAL[0], -self.view_dy - PAGE_FROM_INTERNAL[1]


def fresh_sandbox(root: Path, case: Case) -> None:
    """Remove what earlier runs wrote, so every case starts from the same disk state."""
    make_sandbox(root)
    for scratch in (root / "cwd", root / "c"):
        shutil.rmtree(scratch, ignore_errors=True)
    (root / "winscore" / "scorlib" / "!read!.tmp").unlink(missing_ok=True)
    make_sandbox(root)
    (root / "cwd" / SANDBOX_NAME).write_bytes(case.mus)
    for extra in case.attachments:
        shutil.copy2(extra, root / "cwd" / extra.name)


def run_case(case: Case, root: Path, zoom: int = BASE_ZOOM) -> Run:
    fresh_sandbox(root, case)
    engine = Engine(root)
    engine.initialize()
    engine.put32(ZOOM, zoom)
    run = Run()
    try:
        for command in case.command_lines:
            result = engine.command(command)
            run.outcomes.append(CommandOutcome(command, result.status, result.message, 3 * len(result.vector), len(result.text)))
            run.final = result
    except RuntimeError as err:
        run.error = str(err)
    run.events = list(engine.shell.events)
    run.view_dx, run.view_dy = engine.i32(VIEW_DX), engine.i32(VIEW_DY)
    if run.final is not None:
        runs = len(text_runs(run.final.text))
        run.text_run_y_offsets = [engine.i32(TEXT_RUN_Y_OFFSETS + 4 * i) for i in range(runs)]
    return run


# -- page frame and coordinates ----------------------------------------------

FRAME_COLOUR = 0x00FD00
FRAME_RECTANGLES, FRAME_STEP = 3, 25


def is_closed_rectangle(points) -> bool:
    (x0, y0), (x1, y1), (x2, y2), (x3, y3), end = points
    return end == (x0, y0) and y0 == y1 and x1 == x2 and y2 == y3 and x3 == x0


def is_page_frame(shape: Shape) -> bool:
    """The view draws the paper as three nested rectangles, 25 units apart, in one polyline."""
    if shape.kind != POLYLINE or shape.colour != FRAME_COLOUR or len(shape.paths) != 1:
        return False
    path = shape.paths[0]
    if len(path) != 5 * FRAME_RECTANGLES:
        return False
    rectangles = [path[5 * i:5 * i + 5] for i in range(FRAME_RECTANGLES)]
    corners = [r[0] for r in rectangles]
    return all(map(is_closed_rectangle, rectangles)) and all(
        (x - FRAME_STEP, y - FRAME_STEP) == nxt for (x, y), nxt in zip(corners, corners[1:]))


@dataclass(frozen=True)
class PageFrame:
    left: int
    bottom: int
    right: int
    top: int

    @classmethod
    def of(cls, shape: Shape) -> "PageFrame":
        inner = shape.paths[0][:5]
        xs, ys = [p[0] for p in inner], [p[1] for p in inner]
        return cls(min(xs), min(ys), max(xs), max(ys))

    @property
    def origin(self) -> tuple[int, int]:
        """Bottom-left paper corner in view coordinates: the inner frame is drawn one unit inside."""
        return self.left - 1, self.bottom - 1

    @property
    def size(self) -> tuple[int, int]:
        return self.right - self.left + 2, self.top - self.bottom + 2


@dataclass(frozen=True)
class PageView:
    """The engine output split into page content and the view's paper frames."""
    content: list[Shape]
    texts: list[TextRun]
    frames: list[PageFrame]
    offset: tuple[int, int]

    @classmethod
    def of(cls, run: Run) -> "PageView":
        all_shapes = shapes(run.final.vector)
        frames = [PageFrame.of(s) for s in all_shapes if is_page_frame(s)]
        content = [s for s in all_shapes if not is_page_frame(s)]
        return cls(content, text_runs(run.final.text), frames, run.offset)

    @property
    def frame_agrees(self) -> bool:
        """The leftmost frame sits where the view globals put the paper."""
        return not self.frames or min(f.origin for f in self.frames) == self.offset


# -- engine.json -------------------------------------------------------------

def rgb(colorref: int) -> list[int]:
    return [colorref & 0xFF, (colorref >> 8) & 0xFF, (colorref >> 16) & 0xFF]


def shape_json(shape: Shape, dx: int, dy: int) -> dict:
    out = {
        "kind": "stroke" if shape.kind == POLYLINE else "fill",
        "colour": rgb(shape.colour),
        "paths": [[[x - dx, y - dy] for x, y in path] for path in shape.paths],
    }
    if shape.kind not in (POLYLINE, FILLED):
        out["raw_kind"] = shape.kind
    return out


def to_f32(value: float) -> float:
    return struct.unpack("<f", struct.pack("<f", value))[0]


def as_f32(value: float) -> float:
    """The shortest decimal that reads back as the same f32, so 774.8 rather than 774.7999877929688."""
    exact = to_f32(value)
    return next(float(s) for s in (f"{exact:.{p}g}" for p in range(1, 10)) if to_f32(float(s)) == exact)


def text_json(run: TextRun, dx: int, dy: int) -> dict:
    """Height and width in engine units; string origins are TextOut's top-left, y + 96."""
    return {
        "font": run.font,
        "height": as_f32(64 * run.height),
        "width": as_f32(64 * run.width),
        "escapement": run.escapement,
        "colour": rgb(run.colour),
        "weight": run.weight,
        "italic": run.italic,
        "underline": run.underline,
        "strings": [{"x": s.x - dx, "y": s.y + TEXT_TOP_OFFSET - dy, "text": s.text} for s in run.strings],
    }


def display_json(view: PageView) -> dict:
    dx, dy = view.offset
    return {
        "shapes": [shape_json(s, dx, dy) for s in view.content],
        "texts": [text_json(r, dx, dy) for r in view.texts],
    }


def compact(value) -> str:
    return json.dumps(value, sort_keys=True, separators=(",", ":"), ensure_ascii=False)


def dump_by_line(document: dict) -> str:
    """Sorted keys, one list element per line: valid JSON whose diffs stay readable."""
    sections = []
    for key in sorted(document):
        items = document[key]
        body = ",\n".join(compact(item) for item in items)
        sections.append(f"{compact(key)}:[\n{body}\n]" if items else f"{compact(key)}:[]")
    return "{" + ",\n".join(sections) + "}\n"


# -- meta.json ---------------------------------------------------------------

TITLE_ITEMS = re.compile(r"(\d+)\s+Items")
TITLE_PAPER = re.compile(r"<([^>]*)>\s*$")


def document_title(events: list[Event]) -> str:
    titles = [e.detail[3:] for e in events if e.kind == "document" and e.detail.startswith("n:")]
    return titles[-1].strip() if titles else ""


def counted(lines) -> list[str]:
    """Distinct lines in first-seen order, repeated ones marked with their count."""
    counts = Counter(lines)
    return [line if n == 1 else f"{line} (x{n})" for line, n in counts.items()]


def invalid_reasons(run: Run, zoom_run: Run | None, view: PageView | None) -> list[str]:
    reasons = [f"emulation: {run.error}"] if run.error else []
    reasons += counted(f"{e.kind}: {e.detail}" for e in run.events if e.kind in INVALIDATING_EVENTS)
    if view is not None and not view.frame_agrees:
        reasons.append(f"page frame at {[f.origin for f in view.frames]}, view globals say {view.offset}")
    if zoom_run is not None and zoom_run.final is not None and run.final is not None:
        if (zoom_run.final.vector, zoom_run.final.text) != (run.final.vector, run.final.text):
            reasons.append(f"output differs between zoom {BASE_ZOOM:#x} and {CHECK_ZOOM:#x}")
    return reasons


def warnings(run: Run, view: PageView | None) -> list[str]:
    """Doubts that do not invalidate a case; the engine's real buffer limits are unconfirmed."""
    if run.final is None:
        return []
    notes = [] if view is None or view.frames else ["no page frame in the output"]
    if 3 * len(run.final.vector) > DOCUMENTED_VECTOR_WORDS:
        notes.append(f"vector stream longer than the documented {DOCUMENTED_VECTOR_WORDS} words")
    if len(run.final.text) > DOCUMENTED_TEXT_BYTES - 64:
        notes.append(f"text stream near the documented {DOCUMENTED_TEXT_BYTES} bytes")
    if any(run.text_run_y_offsets):
        notes.append(f"OnDraw per-run y offsets are nonzero: {run.text_run_y_offsets}")
    return notes


def meta_json(case: Case, run: Run, zoom_run: Run | None, view: PageView | None) -> dict:
    title = document_title(run.events)
    items = TITLE_ITEMS.search(title)
    paper = TITLE_PAPER.search(title)
    reasons = invalid_reasons(run, zoom_run, view)
    frames = view.frames if view is not None else []
    return {
        "case": case.name,
        "description": case.description,
        "commands": [
            {"command": o.command, "status": o.status, "line": o.line, "vector_words": o.vector_words, "text_bytes": o.text_bytes}
            for o in run.outcomes
        ],
        "items": int(items.group(1)) if items else None,
        "paper": paper.group(1) if paper else None,
        "page_size": list(frames[0].size) if frames else None,
        "page_frames": [[f.left, f.bottom, f.right, f.top] for f in frames],
        "view_offset": list(view.offset) if view is not None else None,
        "view_globals": [run.view_dx, run.view_dy],
        "title": title,
        "events": [{"kind": e.kind, "detail": e.detail} for e in run.events if e.kind not in QUIET_EVENTS],
        "zoom_checked": zoom_run is not None,
        "valid": not reasons,
        "invalid_reasons": reasons,
        "warnings": warnings(run, view),
        "coordinates": "page: origin at the bottom-left paper corner, y up; page = internal + (2000, 26948); view = page + view_offset",
        "text_origin": "top-left of the character cell: engine (x, y + 96), then translated",
    }


# -- driver ------------------------------------------------------------------

@dataclass(frozen=True)
class Written:
    name: str
    valid: bool
    reasons: tuple[str, ...]
    shapes: int
    texts: int


def worker_sandbox() -> Path:
    return SANDBOXES / f"worker-{os.getpid()}"


def write_fixture(case: Case, out: Path, zoom_check: bool) -> Written:
    root = worker_sandbox()
    run = run_case(case, root)
    zoom_run = run_case(case, root, CHECK_ZOOM) if zoom_check else None
    target = out / case.name
    target.mkdir(parents=True, exist_ok=True)
    (target / INPUT).write_bytes(case.mus)
    view = PageView.of(run) if run.final is not None else None
    meta = meta_json(case, run, zoom_run, view)
    (target / "meta.json").write_text(json.dumps(meta, sort_keys=True, indent=1, ensure_ascii=False) + "\n")
    display = display_json(view) if view is not None else {"shapes": [], "texts": []}
    (target / "engine.json").write_text(dump_by_line(display))
    return Written(case.name, meta["valid"], tuple(meta["invalid_reasons"]),
                   len(display["shapes"]), sum(len(t["strings"]) for t in display["texts"]))


def selected(cases: list[Case], patterns: list[str]) -> list[Case]:
    if not patterns:
        return cases
    return [c for c in cases if any(fnmatch.fnmatchcase(c.name, p) for p in patterns)]


def main(argv: list[str]) -> int:
    from fixtures_cases import all_cases

    parser = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    parser.add_argument("patterns", nargs="*")
    parser.add_argument("--out", type=Path, default=FIXTURES)
    parser.add_argument("--jobs", type=int, default=max(1, (os.cpu_count() or 2) - 2))
    parser.add_argument("--list", action="store_true")
    parser.add_argument("--no-zoom-check", action="store_true")
    args = parser.parse_args(argv)

    cases = selected(all_cases(), args.patterns)
    if args.list:
        print("\n".join(f"{c.name}\t{c.description}" for c in cases))
        return 0
    with ProcessPoolExecutor(max_workers=args.jobs) as pool:
        written = list(pool.map(write_fixture, cases, [args.out] * len(cases), [not args.no_zoom_check] * len(cases)))
    for w in written:
        state = "ok" if w.valid else "INVALID " + "; ".join(w.reasons)
        print(f"{w.name:40} shapes={w.shapes:5} strings={w.texts:4} {state}")
    known = {c.name for c in all_cases()}
    stale = sorted(p.name for p in args.out.iterdir() if (p / "engine.json").is_file() and p.name not in known)
    if stale:
        print("directories without a case:", ", ".join(stale))
    return 0 if all(w.valid for w in written) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
