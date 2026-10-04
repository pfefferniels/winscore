"""Attribute C++ functions to source modules via the THIS_FILE strings of the debug build."""
import csv, re, sys, pefile
from collections import defaultdict
INV = sys.argv[1]
EXE = "/Users/nielspfeffer/Projects/winscore/WINSCORE 5.01/winscore/WScore.exe"
pe = pefile.PE(EXE, fast_load=True)
image, base = pe.get_memory_mapped_image(), pe.OPTIONAL_HEADER.ImageBase
source_at = {base + m.start(): m.group(1).decode()
             for m in re.finditer(rb"C:\\WS\\([\w.]+\.cpp)\0", image)}
spans = defaultdict(set)
with open(f"{INV}/datarefs.tsv") as fh:
    for entry, _site, target in csv.reader(fh, delimiter="\t"):
        name = source_at.get(int(target, 16))
        if name: spans[name].add(int(entry, 16))
with open(f"{INV}/strings.tsv") as fh:
    for entry, addr, _text in csv.reader(fh, delimiter="\t", quoting=csv.QUOTE_NONE):
        name = source_at.get(int(addr, 16))
        if name: spans[name].add(int(entry, 16))
in_gui = lambda e: 0x58c000 <= e < 0x5ee000
rows = sorted((min(filter(in_gui, v)), max(filter(in_gui, v)), len(v), k)
              for k, v in spans.items() if any(map(in_gui, v)))
for lo, hi, n, name in rows:
    print(f"{lo:#x}-{hi:#x} {n:3}  {name}")
print(len(rows), "of", len(source_at), "modules located")
