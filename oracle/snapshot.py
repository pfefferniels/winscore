"""An engine that is booted and initialised once, then reset to that state before every case.

Booting the CRT and running the engine's init take most of a small case's time. After
initialize() the writable state is copied: the image's writable sections, the stack, the
thread block, the used part of the emulated heap, the CPU context and the Python-side
state of WinApi and Shell. Restoring writes it back; the code sections are never touched,
so Unicorn keeps its translations. No file is open at the snapshot (checked).
"""
from __future__ import annotations

import copy
from dataclasses import dataclass
from pathlib import Path

from callbacks import Shell
from emu import GDT_BASE, STACK_BASE, STACK_SIZE, TIB_BASE
from fixtures import BASE_ZOOM, Case, FixtureEngine, Run, fresh_sandbox, run_on
from winapi import HEAP_BASE

IMAGE_BASE = 0x400000
WRITABLE = 0x80000000


@dataclass
class Snapshot:
    memory: list[tuple[int, bytes]]
    heap_next: int
    heap_sizes: dict[int, int]
    context: object
    next_handle: int
    shell_events: list


class ReusableEngine:
    """One engine per worker: `run(case)` gives the same result as `fixtures.run_case(case)`."""

    def __init__(self, root: Path):
        self.root = root
        fresh_sandbox(root, Case("boot", "", b""))
        self.engine = FixtureEngine(root)
        self.engine.initialize()
        if self.engine.api.files:
            raise RuntimeError("files open after initialisation; the snapshot would not restore them")
        self.snapshot = self._take()

    def _regions(self) -> list[tuple[int, int]]:
        sections = [(IMAGE_BASE + s.VirtualAddress, s.Misc_VirtualSize)
                    for s in self.engine.pe.sections if s.Characteristics & WRITABLE]
        return sections + [(STACK_BASE, STACK_SIZE), (TIB_BASE, 0x2000), (GDT_BASE, 0x1000)]

    def _take(self) -> Snapshot:
        e = self.engine
        heap = e.api.heap
        memory = [(addr, bytes(e.uc.mem_read(addr, size))) for addr, size in self._regions()]
        memory.append((HEAP_BASE, bytes(e.uc.mem_read(HEAP_BASE, heap.next - HEAP_BASE))))
        return Snapshot(memory, heap.next, dict(heap.sizes), e.uc.context_save(), e.api.next_handle,
                        copy.deepcopy(e.shell.events))

    def _restore(self) -> None:
        e, snap = self.engine, self.snapshot
        for handle in list(e.api.files):
            e.api.files.pop(handle).stream.close()
        used_since = e.api.heap.next - snap.heap_next
        if used_since > 0:
            e.uc.mem_write(snap.heap_next, b"\0" * used_since)
        for addr, data in snap.memory:
            e.uc.mem_write(addr, data)
        e.uc.context_restore(snap.context)
        e.api.heap.next, e.api.heap.sizes = snap.heap_next, dict(snap.heap_sizes)
        e.api.next_handle, e.api.last_error = snap.next_handle, 0
        e.api.log.clear()
        if hasattr(e.api, "searches"):
            e.api.searches.clear()
        e.shell = Shell(events=copy.deepcopy(snap.shell_events))
        e.trace.clear()
        e.vector_writers.clear()
        e.text_writers.clear()
        e.missing_library.clear()

    def run(self, case: Case, zoom: int = BASE_ZOOM) -> Run:
        fresh_sandbox(self.root, case)
        self._restore()
        return run_on(self.engine, case, self.root, zoom)
