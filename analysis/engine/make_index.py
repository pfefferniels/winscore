"""Write decompiled_all/index.tsv: every engine routine with size, callers, callees and the item codes it serves.

    python make_index.py [--trace]

Callers and callees come from Ghidra's call graph (through the incremental-linking thunks) and
dynamic_calls.tsv. "codes" are the item codes being drawn whenever the routine was called while
tracing G of the four sample scores; --trace reruns those traces (about two minutes) and
rewrites dynamic_calls.tsv and dynamic_codes.tsv.
"""
from __future__ import annotations

import csv
import sys
from collections import Counter, defaultdict
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parents[1]
SAMPLES = ROOT / "WINSCORE 5.01" / "winscore"
ENGINE = range(0x40BC18, 0x58C7E3)
sys.path.insert(0, str(ROOT / "oracle"))

from make_catalog import read_tsv, static_callers  # noqa: E402


def trace_samples():
    from trace import run_traced
    edges, codes = Counter(), defaultdict(set)
    for name in ("carmen.mus", "mozart.mus", "sonlcs.mus", "000.mus"):
        tracer, _ = run_traced([f"G {name}"], [SAMPLES / name])
        edges.update(tracer.edges)
        for entry, seen in tracer.codes.items():
            codes[entry] |= seen
    (HERE / "dynamic_calls.tsv").write_text(
        "caller\tcallee\tcount\n" + "".join(f"{a:08x}\t{b:08x}\t{n}\n" for (a, b), n in sorted(edges.items())))
    (HERE / "dynamic_codes.tsv").write_text(
        "routine\tcodes\n" + "".join(f"{e:08x}\t{','.join(map(str, sorted(c)))}\n" for e, c in sorted(codes.items())))


def main(argv):
    if "--trace" in argv:
        trace_samples()
    callers = static_callers()
    for row in read_tsv(HERE / "dynamic_calls.tsv"):
        callers[int(row["callee"], 16)].add(int(row["caller"], 16))
    callees = defaultdict(set)
    for callee, found in callers.items():
        for caller in found:
            callees[caller].add(callee)
    codes = {int(r["routine"], 16): r["codes"] for r in read_tsv(HERE / "dynamic_codes.tsv")}
    sizes = {int(f["entry"], 16): f["size"] for f in read_tsv(ROOT / "analysis" / "data" / "functions.tsv")}
    files = sorted((HERE / "decompiled_all").glob("*.c"), key=lambda f: int(f.name.split("_", 1)[0], 16))
    rows = [{"address": f.name.split("_", 1)[0], "name": f.stem.split("_", 1)[1], "file": f.name,
             "bytes": sizes.get(int(f.name.split("_", 1)[0], 16), "")} for f in files]
    name = {int(r["address"], 16): r["name"] for r in rows}
    label = lambda a: name.get(a, f"{a:06x}")
    listed = lambda found: " ".join(sorted(label(a) for a in found if a in ENGINE or a in name))
    with (HERE / "decompiled_all" / "index.tsv").open("w") as out:
        out.write("address\tname\tbytes\tcallers\tcallees\tcodes\tfile\n")
        for r in rows:
            a = int(r["address"], 16)
            out.write(f"{a:08x}\t{r['name']}\t{r['bytes']}\t{listed(callers.get(a, set()) - {0})}\t"
                      f"{listed(callees.get(a, ()))}\t{codes.get(a, '')}\t{r['file']}\n")


if __name__ == "__main__":
    main(sys.argv[1:])
