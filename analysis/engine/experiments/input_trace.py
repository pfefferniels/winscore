"""Trace the IN procedure: who writes which word of the input work table (15 f32 per entry at 0x1F95D40).

    python input_trace.py "C4/D/E/F;" "4/4/4/4;" [--range 2 200] [--param 3]

Prints every write to parameter P<k> (default P3) of a work-table entry, with value,
writing instruction and call chain, then the final items.
"""
from __future__ import annotations

import argparse
import struct
import sys
import tempfile
from pathlib import Path

ORACLE = Path(__file__).resolve().parents[3] / "oracle"
sys.path.insert(0, str(ORACLE))

from input_driver import InputEngine, InputJob, read_items, format_items  # noqa: E402
from sandbox import make_sandbox  # noqa: E402
from trace import Tracer  # noqa: E402

TABLE, ENTRY = 0x1F95D40, 0x3C          # entry j, parameter k at TABLE + ENTRY*j + 4*k


def main(argv=None):
    p = argparse.ArgumentParser()
    p.add_argument("passes", nargs="+", help="pass texts; missing passes are ';'")
    p.add_argument("--range", nargs=2, type=float, default=None)
    p.add_argument("--param", type=int, action="append", default=None)
    p.add_argument("--entries", type=int, default=40)
    args = p.parse_args(argv)
    params = set(args.param or [3])
    passes = tuple(args.passes) + (";",) * (5 - len(args.passes))
    job = InputJob("IN 1", passes, tuple(args.range) if args.range else None)
    with tempfile.TemporaryDirectory(prefix="wscore-intrace-") as tmp:
        root = make_sandbox(Path(tmp))
        engine = InputEngine(root, keys=job.keystrokes(), input_range=job.input_range)
        engine.initialize()
        table = range(TABLE, TABLE + ENTRY * (args.entries + 1))
        with Tracer(engine, watches=[table]) as t:
            engine.command(job.command)
        for hit in t.hits:
            j, rem = divmod(hit.address - TABLE, ENTRY)
            k = rem // 4
            if k in params and rem % 4 == 0 and len(hit.data) == 4:
                print(f"entry {j:2d} P{k} <- {hit.as_float:10.4f}  pc {hit.write.pc:06x}  {t.chain_text(hit.write.chain)}")
        engine.command("SA result.mus")
        print(format_items(read_items((root / "cwd" / "RESULT.MUS").read_bytes())))


if __name__ == "__main__":
    main()
