"""Classify WScore.exe functions by the compiler that produced them."""
import csv, pefile, re, sys
from collections import Counter
from dataclasses import dataclass
from itertools import groupby

EXE = "/Users/nielspfeffer/Projects/winscore/WINSCORE 5.01/winscore/WScore.exe"
INV = sys.argv[1]

@dataclass(frozen=True)
class Func:
    entry: int
    name: str
    size: int
    callers: int

def load_functions():
    with open(f"{INV}/functions.tsv") as fh:
        return [Func(int(r["entry"], 16), r["name"], int(r["size"]), int(r["callers"]))
                for r in csv.DictReader(fh, delimiter="\t")]

def load_strings():
    refs = {}
    with open(f"{INV}/strings.tsv") as fh:
        for entry, _addr, text in csv.reader(fh, delimiter="\t", quoting=csv.QUOTE_NONE):
            refs.setdefault(int(entry, 16), []).append(text)
    return refs

pe = pefile.PE(EXE, fast_load=True)
image = pe.get_memory_mapped_image()
BASE = pe.OPTIONAL_HEADER.ImageBase
STACK_FILL = re.compile(rb"\xb8\xcc\xcc\xcc\xcc\xf3\xab")   # mov eax,0CCCCCCCCh / rep stosd

def code(f):
    return image[f.entry - BASE: f.entry - BASE + max(f.size, 1)]

def kind(f, strings):
    body = code(f)
    texts = strings.get(f.entry, [])
    if f.size == 5 and body[:1] == b"\xe9": return "ilt-thunk"
    if f.name.startswith(("FUN_", "thunk_FUN_")) is False and "::" in f.name: return "mfc-import"
    if any("forrtl" in t for t in texts): return "fortran-rtl"
    if STACK_FILL.search(body[:64]): return "c++-debug"
    return "other"

if __name__ == "__main__":
    funcs = load_functions()
    strings = load_strings()
    kinds = [(f, kind(f, strings)) for f in funcs]
    print(Counter(k for _, k in kinds))
    print("\naddress runs (kind, first, last, count, bytes):")
    for k, run in groupby(kinds, key=lambda fk: fk[1]):
        run = list(run)
        if len(run) >= 15:
            print(f"  {k:12} {run[0][0].entry:#x}-{run[-1][0].entry:#x} {len(run):5} {sum(f.size for f, _ in run):8}")
