"""Classify every fistp in the engine: truncating (RC forced by the preceding fldcw), NINT (after ANINT 0x5FF381), or raw default rounding.

    python conversions.py
"""
import csv, bisect, pefile, capstone
pe = pefile.PE("/Users/nielspfeffer/Projects/winscore/WINSCORE 5.01/winscore/WScore.exe")
img = pe.get_memory_mapped_image(); base = 0x400000
md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
rows = list(csv.DictReader(open("/Users/nielspfeffer/Projects/winscore/analysis/engine/decompiled_all/index.tsv"), delimiter="\t"))
starts = sorted((int(r["address"], 16), r["name"]) for r in rows)
keys = [s for s, _ in starts]
history, out = [], {}
for ins in md.disasm(img[0x40BC18 - base:0x58C7E3 - base], 0x40BC18):
    history = (history + [ins])[-40:]
    if ins.mnemonic in ("fistp", "fist"):
        rc = "default"
        for k in range(len(history) - 2, -1, -1):
            h = history[k]
            if h.mnemonic == "fldcw":
                forced = any(p.mnemonic == "or" and "0xc00" in p.op_str for p in history[max(0, k - 4):k])
                rc = "trunc" if forced else "default"
                break
            if h.mnemonic in ("ret", "call"):
                break
        if rc == "default":
            nint = any(h.mnemonic == "call" and "0x5ff381" in h.op_str for h in history[-6:-1])
            i = bisect.bisect_right(keys, ins.address) - 1
            out.setdefault(starts[i], []).append((ins.address, nint))
total = sum(len(v) for v in out.values())
raw = [(r, a) for r, v in out.items() for a, nint in v if not nint]
print(f"{total} non-truncating conversions in {len(out)} routines; {len(raw)} without ANINT:")
for (s, n), a in sorted(raw):
    print(f"  raw 0x{a:06X} in {n}")
for (s, n), sites in sorted(out.items()):
    print(f"| 0x{s:06X} | {n} | {' '.join(f'0x{a:06X}' for a, nint in sites if nint)} |")
