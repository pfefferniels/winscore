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

from unicorn import UC_HOOK_MEM_WRITE

from callbacks import Event
from displaylist import POLYLINE, FILLED, Shape, TextRun, shapes, text_runs
from emu import LINE_BUF, TEXT_OUT, VECTOR_BUF, Engine, EngineResult, ZOOM
from musbuild import param, read_items
from sandbox import make_sandbox
from winapi import WinApi

REPO = Path(__file__).resolve().parents[1]
FIXTURES = REPO / "rust" / "fixtures"
SANDBOXES = Path(__file__).resolve().parent / "sandbox" / "fixtures"
INPUT = "input.mus"
RESULT = "result.mus"      # the score as the engine holds it after a case's commands
SANDBOX_NAME = "case.mus"   # "G I..." drops the I: the engine reads "G input.mus" as NPUT.MUS

TEXT_BASELINE_OFFSET = 96       # OnDraw (0x5E5910): the baseline of a string is at y + 0x60 (analysis/engine/display.md)
VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4   # emit_points: x_out = x + VIEW_DX, y_out = y - VIEW_DY
PAGE_FROM_INTERNAL = (2000, 26948)        # paper bottom-left at internal (-2000, -26947.7); analysis/engine/coordinates.md
ITEM_COUNT = 0x20B8E24          # number of items, and the 1-based loop index while drawing
ITEM_WORDS, ITEM_START = 0x205343C, 0x2091D1C   # item store: P_k of item i at ITEM_WORDS + 4 (start[i] + k); dispatch.md
# Pen-width records (tag = colour + pen << 24), print metadata that also reaches the screen (impl-notes):
# 0x4D4F3F writes (0, 0, pen -99) "reset width", 0x4D4ED2 writes (999, w, pen 99) "set width".
PEN_RESET_KIND, PEN_SET_KIND, PEN_SET_X = 0x9D, 0x63, 999


def is_pen_record(triple: tuple[int, int, int], view_dx: int, view_dy: int) -> bool:
    """The record's point passes through emit_points like any other, so it is checked in internal coordinates."""
    x, y, tag = triple[0] - view_dx, triple[1] + view_dy, triple[2]
    kind = (tag & 0xFFFFFFFF) >> 24
    return (kind == PEN_RESET_KIND and x == y == 0) or (kind == PEN_SET_KIND and x == PEN_SET_X)
YES_NO_QUESTION = 0x595CD0      # "Source Box O.K.?" (LJ, LI, J), "Add bar lines?" (IN); 0 means No (disasm-expert)
NOT_FOUND_DIALOG = 0x59B090     # "Not found": missing symbol library or instrument; changes no geometry
# The engine never checks its output buffers; these are the shell's room (disasm-expert).
SHELL_VECTOR_WORDS, SHELL_OBJECTS, SHELL_TEXT_BYTES = 1_000_000, 10_000, 440_000
INVALIDATING_EVENTS = {"message", "dialog", "prompt-unanswered"}
QUIET_EVENTS = {"service", "redraw", "document"}
BASE_ZOOM, CHECK_ZOOM = 0x40, 0x80
COMMAND_TIMEOUT_MS = 15_000     # the largest sample takes about 3 s; beyond this the engine is looping


@dataclass(frozen=True)
class Case:
    name: str
    description: str
    mus: bytes
    commands: tuple[str, ...] = ()
    attachments: tuple[Path, ...] = ()
    confirm: bool = True   # the answer to the engine's yes/no questions, as a user running the command would give

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
    vector_writers: dict[int, int] = field(default_factory=dict)
    text_writers: dict[int, int] = field(default_factory=dict)
    excluded: dict[int, str] = field(default_factory=dict)   # 0-based file item -> reason
    to_file: list[int | None] = field(default_factory=list)  # engine item (0-based) -> item of the drawn file
    result_mus: bytes | None = None
    view_dx: int = 0
    view_dy: int = 0
    error: str = ""

    def file_item(self, engine_item: int | None) -> int | None:
        if engine_item is None or engine_item >= len(self.to_file):
            return None
        return self.to_file[engine_item]

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


class FixtureEngine(Engine):
    """The oracle engine, recording which item writes each output word or byte, and the "Not found" notices.

    The item is the draw loop's index at the time of the write. The engine's own per-item
    word ranges (0x20359FC) are not used: after some text items they start one triple late.
    """

    def __post_init__(self):
        super().__post_init__()
        self.vector_writers: dict[int, int] = {}
        self.text_writers: dict[int, int] = {}
        self.missing_library: dict[int, str] = {}
        self.confirm = True
        self.uc.hook_add(UC_HOOK_MEM_WRITE, self._on_vector_write, begin=VECTOR_BUF, end=VECTOR_BUF + 4 * SHELL_VECTOR_WORDS)
        self.uc.hook_add(UC_HOOK_MEM_WRITE, self._on_text_write, begin=TEXT_OUT, end=TEXT_OUT + SHELL_TEXT_BYTES)

    def _on_vector_write(self, uc, access, address, size, value, _user):
        self.vector_writers[(address - VECTOR_BUF) // 4] = self.i32(ITEM_COUNT)

    def _on_text_write(self, uc, access, address, size, value, _user):
        item = self.i32(ITEM_COUNT)
        self.text_writers.update((a - TEXT_OUT, item) for a in range(address, address + size))

    def _on_cpp(self, uc, address, size, _user):
        if address == YES_NO_QUESTION:
            answer = "yes" if self.confirm else "no"
            self.shell.record("question", f"{self.cstr(self.arg(0), 200).strip()} -> {answer}")
            self.return_from_call(int(self.confirm), 0)
            return
        if address != NOT_FOUND_DIALOG:
            return super()._on_cpp(uc, address, size, _user)
        notice = self.cstr(LINE_BUF, 0x200).strip()
        self.shell.record("not-found", notice)
        if notice.lower().endswith(".drw"):
            self.missing_library[self.i32(ITEM_COUNT) - 1] = notice
        self.return_from_call(0, 0)

    def command(self, text: str) -> EngineResult:
        self.vector_writers.clear()
        self.text_writers.clear()
        return super().command(text)

    def item_store(self) -> list[tuple[float, float, float]]:
        """P1-P3 of the items the engine holds, in its order (it drops some on load, e.g. codes 0 and 13)."""
        def word(address: int) -> float:
            return struct.unpack("<f", bytes(self.uc.mem_read(address, 4)))[0]
        starts = [self.i32(ITEM_START + 4 * i) for i in range(1, self.i32(ITEM_COUNT) + 1)]
        return [tuple(word(ITEM_WORDS + 4 * (w + k)) for k in (1, 2, 3)) for w in starts]


def align(store: list[tuple[float, float, float]], items: list[bytes]) -> list[int | None]:
    """Each engine item's index in the file: the next file item with the same P1-P3, in order."""
    as_f32 = (lambda v: struct.unpack("<f", struct.pack("<f", v))[0])
    keys = [tuple(as_f32(param(packed, n)) for n in (1, 2, 3)) for packed in items]
    mapping, cursor = [], 0
    for key in store:
        found = next((j for j in range(cursor, len(keys)) if keys[j] == key), None)
        mapping.append(found)
        cursor = found + 1 if found is not None else cursor
    return mapping


def run_case(case: Case, root: Path, zoom: int = BASE_ZOOM) -> Run:
    """A case in a newly booted engine."""
    fresh_sandbox(root, case)
    engine = FixtureEngine(root)
    engine.initialize()
    return run_on(engine, case, root, zoom)


def run_on(engine: FixtureEngine, case: Case, root: Path, zoom: int = BASE_ZOOM) -> Run:
    """A case in an engine that is initialised and has run nothing else, with the case's sandbox in place."""
    engine.confirm = case.confirm
    engine.timeout_ms = COMMAND_TIMEOUT_MS
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
    run.vector_writers = dict(engine.vector_writers)
    run.text_writers = dict(engine.text_writers)
    store = engine.item_store() if not run.error else []
    if case.commands and not run.error:
        run.result_mus = saved_score(engine, root)
    drawn = read_items(run.result_mus) if run.result_mus else read_items(case.mus)
    run.to_file = align(store, drawn)
    missing = {f: notice for e, notice in engine.missing_library.items()
               if e < len(run.to_file) and (f := run.to_file[e]) is not None}
    run.excluded = stale_symbol_items(drawn, missing, drawn)
    if run.final is not None:
        try:
            text_runs(run.final.text)
        except (struct.error, ValueError) as err:
            run.error = f"text stream does not decode: {err}"
            run.final = None
    return run


def saved_score(engine: FixtureEngine, root: Path) -> bytes | None:
    """The engine's current score, saved with SA: commands such as LJ move and reorder items."""
    try:
        engine.command(f"SA {RESULT}")
    except RuntimeError:
        return None
    saved = WinApi.resolve_case(root / "cwd" / RESULT)
    return saved.read_bytes() if saved.is_file() else None


def stale_symbol_items(items: list[bytes], missing: dict[int, str], drawn: list[bytes]) -> dict[int, str]:
    """Items that draw a symbol from a library the engine could not load.

    The loader (0x42AD97) does not mark the failed load, so draw_symbol copies whatever the
    previous library left in its buffers and caches that for the session (disasm-expert,
    analysis/engine/symbols.md). The shape depends on the draw history, so these items are
    excluded. Later items asking for the same symbol get the cached result without a notice.
    """
    symbols = {(param(items[i], 1), param(items[i], 5)): notice for i, notice in missing.items() if i < len(items)}
    return {i: f"symbol library not found ({symbols[key]}); the engine draws stale buffers"
            for i, packed in enumerate(drawn) if (key := (param(packed, 1), param(packed, 5))) in symbols}


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
    """The engine output split into page content and the view's paper frames.

    `shape_items` and `text_items` give the 0-based index of the item that drew
    each element, or None where the attribution failed (see `warnings`).
    """
    content: list[Shape]
    shape_items: list[int | None]
    texts: list[TextRun]
    text_items: list[int | None]
    frames: list[PageFrame]
    offset: tuple[int, int]
    warnings: tuple[str, ...]

    @classmethod
    def of(cls, run: Run) -> "PageView":
        kept = [k for k, t in enumerate(run.final.vector) if not is_pen_record(t, run.view_dx, run.view_dy)]
        all_shapes = shapes([run.final.vector[k] for k in kept])
        frames = [PageFrame.of(s) for s in all_shapes if is_page_frame(s)]
        content = [(s, item) for s in all_shapes if not is_page_frame(s)
                   if (item := run.file_item(shape_writer(s, kept, run.vector_writers))) not in run.excluded]
        records = len(run.final.vector) - len(kept)
        # The shell would draw each record as a one-point object of its own kind.
        notes = [f"{records} pen-width record(s) left out"] if records else []
        if any(i is None for _, i in content):
            notes.append("shapes without a single writing item; not attributed")
        attributed = [(r, run.file_item(run_writer(r, run.text_writers))) for r in text_runs(run.final.text)]
        runs = [r for r, item in attributed if item not in run.excluded]
        text_items = [item for _, item in attributed if item not in run.excluded]
        if None in text_items:
            notes.append("text runs without a single writing item; not attributed")
        return cls([s for s, _ in content], [item for _, item in content], runs, text_items, frames, run.offset,
                   tuple(notes))

    @property
    def overflows(self) -> bool:
        """Some page coordinate does not fit an i32: the engine converted an out-of-range float."""
        dx, dy = self.offset
        shape_coordinates = (v for s in self.content for path in s.paths for x, y in path for v in (x - dx, y - dy))
        text_coordinates = (v for r in self.texts for t in r.strings for v in (t.x - dx, t.y + TEXT_BASELINE_OFFSET - dy))
        return any(not -2**31 < v < 2**31 for coordinates in (shape_coordinates, text_coordinates) for v in coordinates)

    @property
    def frame_agrees(self) -> bool:
        """The leftmost frame sits where the view globals put the paper."""
        return not self.frames or min(f.origin for f in self.frames) == self.offset


def single_writer(span, writers: dict[int, int]) -> int | None:
    """0-based index of the one item that wrote every word (or byte) of the span, else None."""
    items = {writers.get(i) for i in span}
    (item,) = items if len(items) == 1 else (None,)
    return item - 1 if item else None


def shape_writer(shape: Shape, kept: list[int], writers: dict[int, int]) -> int | None:
    """`kept` maps the decoded triples back to their positions in the engine's stream."""
    start, end = shape.span
    return single_writer([3 * kept[k] + w for k in range(start, end) for w in range(3)], writers)


def run_writer(run: TextRun, writers: dict[int, int]) -> int | None:
    return single_writer(range(*run.span), writers)


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
    """Height and width in engine units; string origins are the baseline start, y + 96."""
    return {
        "font": run.font,
        "height": as_f32(64 * run.height),
        "width": as_f32(64 * run.width),
        "escapement": run.escapement,
        "colour": rgb(run.colour),
        "weight": run.weight,
        "italic": run.italic,
        "underline": run.underline,
        "strings": [{"x": s.x - dx, "y": s.y + TEXT_BASELINE_OFFSET - dy, "text": s.text} for s in run.strings],
    }


def with_item(element: dict, item: int | None) -> dict:
    return element | {"item": item} if item is not None else element


def display_json(view: PageView) -> dict:
    dx, dy = view.offset
    return {
        "shapes": [with_item(shape_json(s, dx, dy), i) for s, i in zip(view.content, view.shape_items)],
        "texts": [with_item(text_json(r, dx, dy), i) for r, i in zip(view.texts, view.text_items)],
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
    if view is not None and view.overflows:
        reasons.append("engine coordinate overflow (a float too large for an int becomes 0x80000000)")
    if zoom_run is not None and zoom_run.final is not None and run.final is not None:
        if (zoom_run.final.vector, zoom_run.final.text) != (run.final.vector, run.final.text):
            reasons.append(f"output differs between zoom {BASE_ZOOM:#x} and {CHECK_ZOOM:#x}")
    return reasons


def warnings(run: Run, view: PageView | None) -> list[str]:
    """Doubts that do not invalidate a case."""
    if run.final is None or view is None:
        return []
    notes = list(view.warnings) + ([] if view.frames else ["no page frame in the output"])
    if 3 * len(run.final.vector) > SHELL_VECTOR_WORDS or len(view.content) > SHELL_OBJECTS:
        notes.append("more vector output than the shell's display list holds")
    if len(run.final.text) > SHELL_TEXT_BYTES:
        notes.append("more text than the engine's text buffer holds")
    return notes


def dropped_items(case: Case, run: Run) -> list[int]:
    """File items the engine did not keep on load (it drops codes 0 and 13, for instance)."""
    drawn = read_items(run.result_mus) if run.result_mus else read_items(case.mus)
    kept = set(run.to_file)
    return [n for n in range(len(drawn)) if n not in kept] if run.to_file else []


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
        "not_found": counted(e.detail for e in run.events if e.kind == "not-found"),
        "excluded_items": [{"item": i, "reason": reason} for i, reason in sorted(run.excluded.items())],
        "dropped_items": dropped_items(case, run),
        "zoom_checked": zoom_run is not None,
        "valid": not reasons,
        "invalid_reasons": reasons,
        "warnings": warnings(run, view),
        "coordinates": "page: origin at the bottom-left paper corner, y up; page = internal + (2000, 26948); view = page + view_offset",
        "text_origin": "start of the baseline: engine (x, y + 96), then translated",
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


_REUSABLE = None   # this worker's snapshot engine (snapshot.ReusableEngine), when enabled


def use_snapshot_engine() -> None:
    """Pool initialiser: boot once per worker and restore the post-init state for every case."""
    global _REUSABLE
    from snapshot import ReusableEngine
    _REUSABLE = ReusableEngine(worker_sandbox())


def run_in_worker(case: Case, zoom: int = BASE_ZOOM) -> Run:
    return _REUSABLE.run(case, zoom) if _REUSABLE is not None else run_case(case, worker_sandbox(), zoom)


def write_fixture(case: Case, out: Path, zoom_check: bool) -> Written:
    run = run_in_worker(case)
    zoom_run = run_in_worker(case, CHECK_ZOOM) if zoom_check else None
    target = out / case.name
    target.mkdir(parents=True, exist_ok=True)
    (target / INPUT).write_bytes(case.mus)
    (target / RESULT).unlink(missing_ok=True)
    if run.result_mus:
        (target / RESULT).write_bytes(run.result_mus)
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
    parser.add_argument("--boot-each", action="store_true", help="boot a new engine per case instead of restoring a snapshot")
    args = parser.parse_args(argv)

    cases = selected(all_cases(), args.patterns)
    if args.list:
        print("\n".join(f"{c.name}\t{c.description}" for c in cases))
        return 0
    try:
        initializer = None if args.boot_each else use_snapshot_engine
        with ProcessPoolExecutor(max_workers=args.jobs, initializer=initializer) as pool:
            written = list(pool.map(write_fixture, cases, [args.out] * len(cases), [not args.no_zoom_check] * len(cases)))
    finally:
        shutil.rmtree(SANDBOXES, ignore_errors=True)   # one copy of the install per worker process
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
