"""Recover WM_COMMAND handlers from MFC message maps and the command words they send."""
import struct, re, sys, pefile
from dataclasses import dataclass
from capstone import Cs, CS_ARCH_X86, CS_MODE_32

EXE = "/Users/nielspfeffer/Projects/winscore/WINSCORE 5.01/winscore/WScore.exe"
WM_COMMAND = 0x111
SEND_COMMAND = 0x5a53e0          # dispatcher reached through the ILT thunk at 0x4043db

pe = pefile.PE(EXE)
image, base = pe.get_memory_mapped_image(), pe.OPTIONAL_HEADER.ImageBase
md = Cs(CS_ARCH_X86, CS_MODE_32)
text = next(s for s in pe.sections if s.Name.startswith(b".text"))
text_lo, text_hi = base + text.VirtualAddress, base + text.VirtualAddress + text.Misc_VirtualSize
rdata = next(s for s in pe.sections if s.Name.startswith(b".rdata"))

@dataclass(frozen=True)
class CommandEntry:
    command_id: int
    handler: int

def message_map_entries():
    lo = rdata.VirtualAddress
    blob = image[lo: lo + rdata.Misc_VirtualSize]
    for off in range(0, len(blob) - 24, 4):
        msg, code, cid, last, sig, pfn = struct.unpack_from("<6I", blob, off)
        if msg == WM_COMMAND and code == 0 and cid == last and 100 <= cid < 0xF000 \
                and sig < 64 and text_lo <= pfn < text_hi:
            yield CommandEntry(cid, pfn)

def resolve_thunk(addr):
    ins = next(md.disasm(image[addr - base: addr - base + 5], addr), None)
    return int(ins.op_str, 16) if ins and ins.mnemonic == "jmp" else addr

def cstring(va):
    raw = image[va - base: va - base + 200]
    return raw.split(b"\0")[0].decode("latin-1")

def sent_commands(handler):
    """Return (command, description) pairs pushed before calls to SendCommand."""
    start = resolve_thunk(handler)
    pushes, found = [], []
    for ins in md.disasm(image[start - base: start - base + 0x400], start):
        if ins.mnemonic == "push" and ins.op_str.startswith("0x"):
            pushes.append(int(ins.op_str, 16))
        elif ins.mnemonic == "call":
            target = resolve_thunk(int(ins.op_str, 16)) if ins.op_str.startswith("0x") else None
            if target == SEND_COMMAND and len(pushes) >= 2:
                found.append((cstring(pushes[-1]), cstring(pushes[-2])))
            pushes = []
        elif ins.mnemonic == "ret":
            break
    return found

def tooltips():
    t = next(e for e in pe.DIRECTORY_ENTRY_RESOURCE.entries if e.id == pefile.RESOURCE_TYPE["RT_STRING"])
    table = {}
    for block in t.directory.entries:
        leaf = block.directory.entries[0].data.struct
        blob, pos = pe.get_data(leaf.OffsetToData, leaf.Size), 0
        for i in range(16):
            n = struct.unpack_from("<H", blob, pos)[0]; pos += 2
            if n: table[(block.id - 1) * 16 + i] = blob[pos: pos + 2 * n].decode("utf-16le")
            pos += 2 * n
    return table

if __name__ == "__main__":
    tips = tooltips()
    entries = sorted(set(message_map_entries()), key=lambda e: e.command_id)
    with_cmd = 0
    rows = []
    for e in entries:
        sent = sent_commands(e.handler)
        with_cmd += bool(sent)
        tip = tips.get(e.command_id, "").split("\n")[-1]
        rows.append((e.command_id, resolve_thunk(e.handler), "; ".join(c for c, _ in sent), tip))
    print(f"{len(entries)} command handlers, {with_cmd} send a SCORE command string")
    with open(sys.argv[1] if len(sys.argv) > 1 else "command_map.tsv", "w") as out:
        out.write("id\thandler\tscore_command\ttooltip\n")
        for cid, h, cmd, tip in rows:
            out.write(f"{cid}\t{h:#x}\t{cmd}\t{tip}\n")
    for cid, h, cmd, tip in rows[::25]:
        print(f"{cid:6} {h:#x}  {cmd!r:24} {tip}")
