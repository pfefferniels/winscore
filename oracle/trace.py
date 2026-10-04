"""Trace the emulated engine: which routines run, and which call chain emits each output primitive.

    trace.py --mus score.mus                      report for "G score.mus"
    trace.py --mus score.mus --calls --top 40     call counts and callers
    trace.py --mus score.mus --emissions          vector runs and text strings with their call chains
    trace.py --cmd "G carmen.mus" --blocks out.tsv

Python API:

    with Tracer(engine) as t:
        result = engine.command("G score.mus")
    for run in t.vector_runs(result):
        print(run.first, run.count, t.chain_text(run.chain))

A shadow call stack is kept from a basic-block hook: a block entered right after a
block ending in CALL, with the fall-through address on top of the stack, is a call
entry; frames are dropped once ESP rises above their entry ESP or control reaches
their return address. Every write into the vector and text buffers is stamped with
the stack at that moment, the writing instruction, and the item last loaded by the
item loader 0x547C32.
"""
from __future__ import annotations

import argparse
import shutil
import struct
import sys
import tempfile
from collections import Counter
from dataclasses import dataclass, field
from itertools import groupby
from pathlib import Path

import capstone
from unicorn import UC_HOOK_BLOCK, UC_HOOK_MEM_WRITE
from unicorn.x86_const import UC_X86_REG_EIP, UC_X86_REG_ESP

from emu import RETURN_SENTINEL, TEXT_BUF_DIRECT, TEXT_OUT, VECTOR_BUF, Engine, EngineResult
from sandbox import make_sandbox

ROOT = Path(__file__).resolve().parents[1]
GHIDRA_FUNCTIONS = ROOT / "analysis" / "data" / "functions.tsv"
ENGINE_NAMES = ROOT / "analysis" / "engine" / "names.tsv"

IMAGE_CODE = range(0x401000, 0x647000)
THUNKS = range(0x401000, 0x406605)       # incremental-linking jumps
ENGINE_CODE = range(0x40BC18, 0x58C7E3)
VECTOR_BYTES = 4 * 100_000
TEXT_BYTES = 20_000

ITEM_LOADER = 0x547C32
ITEM_INDEX, ITEM_CODE, ITEM_STAFF = 0x2052780, 0x205278C, 0x2052790


@dataclass(frozen=True)
class Frame:
    entry: int
    return_address: int
    esp: int                       # ESP at entry, i.e. the address of the return address


Chain = tuple[Frame, ...]          # outermost call first


@dataclass(frozen=True)
class Item:
    index: int                     # 1-based position in the item list
    code: int
    staff: int


@dataclass(frozen=True)
class Write:
    chain: Chain
    pc: int                        # the writing instruction
    item: Item | None


@dataclass(frozen=True)
class WatchHit:
    """A write into a watched range: the bytes written and who wrote them."""
    address: int
    data: bytes
    write: Write

    @property
    def value(self) -> int:
        return int.from_bytes(self.data, "little", signed=True)

    @property
    def as_float(self) -> float | None:
        return struct.unpack("<f", self.data)[0] if len(self.data) == 4 else None


@dataclass(frozen=True)
class VectorRun:
    """Consecutive triples written by the same instruction under the same chain."""
    first: int                     # triple index
    triples: tuple[tuple[int, int, int], ...]
    write: Write

    @property
    def count(self) -> int:
        return len(self.triples)


@dataclass(frozen=True)
class TextString:
    offset: int                    # byte offset of the record's x field in the text stream
    font: str
    x: int
    y: int
    text: str
    write: Write


def load_names() -> dict[int, str]:
    """Ghidra's function names, overridden by ours from analysis/engine/names.tsv."""
    names: dict[int, str] = {}
    for path in (GHIDRA_FUNCTIONS, ENGINE_NAMES):
        if path.exists():
            rows = (line.split("\t") for line in path.read_text().splitlines()[1:] if line.strip())
            names.update((int(row[0], 16), row[1]) for row in rows if len(row) > 1)
    return names


def _image_bytes(engine: Engine, address: int, size: int) -> bytes:
    return bytes(engine.uc.mem_read(address, size))


@dataclass
class Tracer:
    engine: Engine
    names: dict[int, str] = field(default_factory=load_names)
    code: range = IMAGE_CODE
    calls: Counter = field(default_factory=Counter)          # entry -> count
    edges: Counter = field(default_factory=Counter)          # (caller entry, callee entry) -> count
    sites: Counter = field(default_factory=Counter)          # (return address, callee entry) -> count
    blocks: Counter = field(default_factory=Counter)         # block address -> executions
    vector_writes: dict[int, Write] = field(default_factory=dict)   # byte offset -> last write
    text_writes: dict[int, Write] = field(default_factory=dict)
    watches: list[range] = field(default_factory=list)       # address ranges to log
    hits: list[WatchHit] = field(default_factory=list)

    def __post_init__(self):
        self._stack: list[Frame] = []
        self._previous_call_end = None
        self._ends_with_call: dict[tuple[int, int], bool] = {}
        self._thunk_targets: dict[int, int] = {}
        self._item: Item | None = None
        self._hooks: list[int] = []
        self._disasm = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)

    # -- hooks -------------------------------------------------------------
    def __enter__(self) -> "Tracer":
        uc = self.engine.uc
        self._hooks = [
            uc.hook_add(UC_HOOK_BLOCK, self._on_block, begin=self.code.start, end=self.code.stop - 1),
            uc.hook_add(UC_HOOK_MEM_WRITE, self._on_write(self.vector_writes, VECTOR_BUF),
                        begin=VECTOR_BUF, end=VECTOR_BUF + VECTOR_BYTES - 1),
            uc.hook_add(UC_HOOK_MEM_WRITE, self._on_write(self.text_writes, TEXT_OUT),
                        begin=TEXT_OUT, end=TEXT_OUT + TEXT_BYTES - 1),
            uc.hook_add(UC_HOOK_MEM_WRITE, self._on_write(self.text_writes, TEXT_BUF_DIRECT),
                        begin=TEXT_BUF_DIRECT, end=TEXT_BUF_DIRECT + TEXT_BYTES - 1),
            *(uc.hook_add(UC_HOOK_MEM_WRITE, self._on_watched, begin=r.start, end=r.stop - 1) for r in self.watches),
        ]
        return self

    def __exit__(self, *_exc):
        for hook in self._hooks:
            self.engine.uc.hook_del(hook)
        self._hooks = []
        self._stack.clear()

    def reset(self):
        """Forget everything recorded so far (hooks stay attached)."""
        for counter in (self.calls, self.edges, self.sites, self.blocks):
            counter.clear()
        self.vector_writes.clear()
        self.text_writes.clear()
        self.hits.clear()
        self._item = None

    def _block_ends_with_call(self, address: int, size: int) -> bool:
        key = (address, size)
        cached = self._ends_with_call.get(key)
        if cached is None:
            last = None
            for last in self._disasm.disasm(_image_bytes(self.engine, address, size), address):
                pass
            cached = last is not None and last.mnemonic == "call"
            self._ends_with_call[key] = cached
        return cached

    def _through_thunk(self, address: int) -> int:
        """The routine a call lands in: thunks in 0x401000-0x406604 are a single JMP."""
        if address not in THUNKS:
            return address
        target = self._thunk_targets.get(address)
        if target is None:
            opcode, displacement = struct.unpack("<Bi", _image_bytes(self.engine, address, 5))
            target = (address + 5 + displacement) & 0xFFFFFFFF if opcode == 0xE9 else address
            self._thunk_targets[address] = target
        return target

    def _unwind(self, esp: int, entering: bool):
        stack = self._stack
        while stack and (stack[-1].esp < esp or (entering and stack[-1].esp == esp)):
            stack.pop()

    def _on_block(self, uc, address, size, _user):
        self.blocks[address] += 1
        esp = uc.reg_read(UC_X86_REG_ESP)
        stack = self._stack
        while stack and stack[-1].return_address == address:
            stack.pop()
        expected_return = self._previous_call_end
        self._previous_call_end = address + size if self._block_ends_with_call(address, size) else None
        if not stack and expected_return is None:
            expected_return = RETURN_SENTINEL      # the routine Engine.call started
        if expected_return is not None and struct.unpack("<I", uc.mem_read(esp, 4))[0] == expected_return:
            self._unwind(esp, entering=True)
            entry = self._through_thunk(address)
            caller = stack[-1].entry if stack else 0
            stack.append(Frame(entry, expected_return, esp))
            self.calls[entry] += 1
            self.edges[caller, entry] += 1
            self.sites[expected_return, entry] += 1
            if entry == ITEM_LOADER:
                self._item = Item(self.engine.i32(ITEM_INDEX), *self._peek_item_after_load())
        else:
            self._unwind(esp, entering=False)

    def _peek_item_after_load(self) -> tuple[int, int]:
        """0x547C32 has not run yet: read code and staff from the item store the way it will."""
        index = self.engine.i32(ITEM_INDEX)
        word = self.engine.i32(0x2091D1C + 4 * index)
        p1, p2 = struct.unpack("<ff", self.engine.uc.mem_read(0x2053440 + 4 * word, 8))
        return int(p1), int(p2)

    def _current_write(self, uc) -> Write:
        self._unwind(uc.reg_read(UC_X86_REG_ESP), entering=False)
        return Write(tuple(self._stack), uc.reg_read(UC_X86_REG_EIP), self._item)

    def _on_watched(self, uc, _access, address, size, value, _user):
        data = (value & ((1 << 8 * size) - 1)).to_bytes(size, "little")
        self.hits.append(WatchHit(address, data, self._current_write(uc)))

    def _on_write(self, record: dict[int, Write], base: int):
        def hook(uc, _access, address, size, _value, _user):
            write = self._current_write(uc)
            for offset in range(address - base, address - base + size):
                record[offset] = write
        return hook

    # -- results -----------------------------------------------------------
    def name(self, address: int) -> str:
        return self.names.get(address, f"{address:06x}")

    def chain_text(self, chain: Chain, engine_only: bool = True) -> str:
        frames = [f for f in chain if not engine_only or f.entry in ENGINE_CODE]
        return " > ".join(f"{self.name(f.entry)}@{f.return_address:06x}" for f in frames)

    def vector_runs(self, result: EngineResult) -> list[VectorRun]:
        """Group the result's triples by the write that produced their tag word."""
        stamped = [(i, t, self.vector_writes.get(12 * i + 8)) for i, t in enumerate(result.vector)]
        runs = []
        for write, group in groupby(stamped, key=lambda s: s[2]):
            members = list(group)
            runs.append(VectorRun(members[0][0], tuple(t for _, t, _ in members), write))
        return runs

    def text_strings(self, result: EngineResult) -> list[TextString]:
        return [TextString(offset, font, x, y, text, self.text_writes.get(offset))
                for offset, font, x, y, text in text_records(result.text)]


def text_records(buf: bytes):
    """(offset, font, x, y, text) for every string in a text stream; layout in displaylist.text_runs."""
    pos = 0
    while pos < len(buf):
        nul = buf.index(b"\0", pos)
        font = buf[pos:nul].decode("cp1252")
        count = struct.unpack_from("<i", buf, nul + 0x1D)[0]
        pos = nul + 0x21
        for _ in range(count):
            x, y = struct.unpack_from("<ii", buf, pos)
            end = buf.index(b"\0", pos + 8)
            yield pos, font, x, y, buf[pos + 8:end].decode("cp1252")
            pos = end + 1


# -- command line ----------------------------------------------------------
def describe_item(item: Item | None) -> str:
    return f"item {item.index} (code {item.code}, staff {item.staff})" if item else "no item"


def print_calls(t: Tracer, top: int):
    print(f"{'calls':>7}  routine                      callers (count)")
    engine_calls = [(e, n) for e, n in t.calls.most_common() if e in ENGINE_CODE]
    for entry, count in engine_calls[:top]:
        callers = Counter({caller: n for (caller, callee), n in t.edges.items() if callee == entry})
        listed = ", ".join(f"{t.name(c) if c else 'top'} ({n})" for c, n in callers.most_common(4))
        print(f"{count:7d}  {t.name(entry):28s} {listed}")
    print(f"{len(engine_calls)} engine routines ran, {sum(n for _, n in engine_calls)} calls")


def print_emissions(t: Tracer, result: EngineResult):
    print(f"vector: {len(result.vector)} triples")
    for run in t.vector_runs(result):
        x, y, tag = run.triples[0]
        where = f"pc {run.write.pc:06x} {describe_item(run.write.item)}" if run.write else "not written in this command"
        print(f"  [{run.first:5d} +{run.count:<4d}] first ({x}, {y}, {tag >> 24:02x}:{tag & 0xFFFFFF:06x})  {where}")
        if run.write:
            print(f"      {t.chain_text(run.write.chain)}")
    strings = t.text_strings(result)
    print(f"text: {len(strings)} strings")
    for s in strings:
        where = f"{describe_item(s.write.item)}\n      {t.chain_text(s.write.chain)}" if s.write else "not written"
        print(f"  {s.font} ({s.x}, {s.y}) {s.text!r}  {where}")


def print_hits(t: Tracer):
    for hit in t.hits:
        number = f"{hit.value} / {hit.as_float:g}" if hit.as_float is not None else str(hit.value)
        print(f"  [{hit.address:08x}] <- {number}  pc {hit.write.pc:06x} {describe_item(hit.write.item)}")
        print(f"      {t.chain_text(hit.write.chain)}")


def parse_range(text: str) -> range:
    """ADDR or ADDR:SIZE, hexadecimal address, decimal size (default 4)."""
    address, _, size = text.partition(":")
    start = int(address, 16)
    return range(start, start + int(size or 4))


def write_blocks(t: Tracer, path: Path):
    rows = (f"{a:08x}\t{n}" for a, n in sorted(t.blocks.items()))
    path.write_text("block\tcount\n" + "\n".join(rows) + "\n")


def run_traced(commands: list[str], scores: list[Path], watches: list[range] = ()):
    """Run commands in a fresh temporary sandbox; return the tracer (holding what the last command did) and its result."""
    with tempfile.TemporaryDirectory(prefix="wscore-trace-") as tmp:
        root = make_sandbox(Path(tmp))
        for score in scores:
            shutil.copy2(score, root / "cwd" / score.name)
        engine = Engine(root)
        engine.initialize()
        tracer = Tracer(engine, watches=list(watches))
        result = None
        with tracer:
            for command in commands:
                tracer.reset()
                result = engine.command(command)
        return tracer, result


def main(argv=None):
    p = argparse.ArgumentParser(description=__doc__.split("\n\n")[0])
    p.add_argument("--mus", type=Path, action="append", default=[], help="score to load (copied into the sandbox)")
    p.add_argument("--cmd", action="append", default=[], help="command to run (default: G <first --mus>)")
    p.add_argument("--calls", action="store_true", help="print call counts and callers")
    p.add_argument("--emissions", action="store_true", help="print vector runs and text strings with chains")
    p.add_argument("--top", type=int, default=60)
    p.add_argument("--blocks", type=Path, help="write basic-block execution counts (TSV)")
    p.add_argument("--watch", type=parse_range, action="append", default=[], metavar="ADDR[:SIZE]",
                   help="log every write into this range with its call chain")
    args = p.parse_args(argv)
    commands = args.cmd or [f"G {args.mus[0].name}"]
    tracer, result = run_traced(commands, args.mus, args.watch)
    print(f"[{commands[-1]}] status={result.status} triples={len(result.vector)} text bytes={len(result.text)}")
    everything = not (args.calls or args.emissions or args.watch)
    if args.calls or everything:
        print_calls(tracer, args.top)
    if args.emissions or everything:
        print_emissions(tracer, result)
    if args.watch:
        print_hits(tracer)
    if args.blocks:
        write_blocks(tracer, args.blocks)


if __name__ == "__main__":
    sys.exit(main())
