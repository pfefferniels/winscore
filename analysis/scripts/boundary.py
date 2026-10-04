"""Calls that cross from the C++ shell into the FORTRAN engine, and the engine's own call graph."""
import csv, sys, pefile
from collections import Counter, defaultdict
from capstone import Cs, CS_ARCH_X86, CS_MODE_32
INV = sys.argv[1]
EXE = "/Users/nielspfeffer/Projects/winscore/WINSCORE 5.01/winscore/WScore.exe"
FORTRAN = range(0x40b000, 0x58c900)
GUI = range(0x58c900, 0x5ed300)
pe = pefile.PE(EXE, fast_load=True)
image, base = pe.get_memory_mapped_image(), pe.OPTIONAL_HEADER.ImageBase
md = Cs(CS_ARCH_X86, CS_MODE_32)

def resolve(addr):
    ins = next(md.disasm(image[addr - base: addr - base + 5], addr), None)
    return int(ins.op_str, 16) if ins and ins.mnemonic == "jmp" and ins.op_str.startswith("0x") else addr

def stack_cleanup(entry):
    """Bytes popped by the callee's ret (stdcall), or 0 for cdecl."""
    for ins in md.disasm(image[entry - base: entry - base + 0x20000], entry):
        if ins.mnemonic == "ret":
            return int(ins.op_str, 16) if ins.op_str else 0
    return None

sizes = {}
with open(f"{INV}/functions.tsv") as fh:
    for r in csv.DictReader(fh, delimiter="\t"):
        sizes[int(r["entry"], 16)] = int(r["size"])
edges = set()
with open(f"{INV}/calls.tsv") as fh:
    for a, b in csv.reader(fh, delimiter="\t"):
        if b.startswith("EXTERNAL"): continue
        edges.add((int(a, 16), resolve(int(b, 16))))

crossing = Counter(callee for caller, callee in edges if caller in GUI and callee in FORTRAN)
print(f"{len(crossing)} FORTRAN routines are called directly from C++ ({sum(crossing.values())} caller functions)")
print("most-called (entry, C++ callers, size, ret N):")
for callee, n in crossing.most_common(12):
    print(f"  {callee:#x} {n:4} {sizes.get(callee, 0):7}  ret {stack_cleanup(callee)}")

fortran_funcs = [e for e in sizes if e in FORTRAN]
inner = defaultdict(set)
for a, b in edges:
    if a in FORTRAN and b in FORTRAN: inner[a].add(b)
called = {b for v in inner.values() for b in v}
print(f"\nengine: {len(fortran_funcs)} routines, {sum(map(len, inner.values()))} internal call edges")
print("never called from inside the engine:", len([e for e in fortran_funcs if e not in called]))
rets = Counter(stack_cleanup(e) is not None and stack_cleanup(e) > 0 for e in fortran_funcs[:400])
print("stdcall share in first 400 engine routines:", rets)
print("largest routines:", [(hex(e), sizes[e]) for e in sorted(fortran_funcs, key=sizes.get, reverse=True)[:8]])

back = Counter(callee for caller, callee in edges if caller in FORTRAN and callee in GUI)
print(f"\n{len(back)} C++ functions are called back from FORTRAN ({sum(back.values())} engine callers)")
for callee, n in back.most_common(25):
    print(f"  {callee:#x} {n:4} {sizes.get(callee, 0):6}  ret {stack_cleanup(callee)}")
rt = Counter(callee for caller, callee in edges if caller in FORTRAN and callee >= 0x5ed300)
print(f"\nengine -> runtime/library targets: {len(rt)}")
for callee, n in rt.most_common(15):
    print(f"  {callee:#x} {n:4}")
