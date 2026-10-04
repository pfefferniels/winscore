"""Extract ordinal -> symbol maps from COFF short-import libraries (.LIB)."""
import struct, sys, json
from dataclasses import dataclass

@dataclass(frozen=True)
class OrdinalImport:
    dll: str
    ordinal: int
    symbol: str

def archive_members(blob):
    pos = 8
    while pos + 60 <= len(blob):
        size = int(blob[pos+48:pos+58].decode().strip())
        yield blob[pos+60:pos+60+size]
        pos += 60 + size + (size & 1)

def short_import(member):
    sig1, sig2, _ver, _mach, _ts, _size, ord_hint, flags = struct.unpack_from("<HHHHIIHH", member)
    if (sig1, sig2) != (0, 0xFFFF) or (flags >> 2) & 7 != 0:
        return None
    symbol, dll = member[20:].split(b"\0")[:2]
    return OrdinalImport(dll.decode().upper(), ord_hint, symbol.decode())

def ordinal_imports(path):
    blob = open(path, "rb").read()
    return [imp for imp in map(short_import, archive_members(blob)) if imp]

if __name__ == "__main__":
    found = [i for p in sys.argv[1:] for i in ordinal_imports(p)]
    json.dump([i.__dict__ for i in found], sys.stdout)
