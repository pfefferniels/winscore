"""Read the compact "KH" symbol libraries and compare them with their float-variant WinScore equivalents.

    python kh_drw.py

Library number n is LIB<letter><letter> with letters chr(ord('R') + n // 26), chr(ord('A') + n % 26):
LIBRA = 0 (LB0000.DRW), LIBSA = 26, LIBTI = 60, LIBUM = 90.

A KH file is a Microsoft FORTRAN (DOS) unformatted sequential file: byte 0x4B ('K'), then
physical records of at most 128 bytes, each framed by a length byte before and after; the
length 0x81 (129) marks a full 128-byte block whose logical record continues in the next one;
the byte 0x82 ends the file. Logical record 1: 11 i16 offsets and ten 5-character names;
logical record 2: the points as i16 triples (x, y, pen).
"""
from __future__ import annotations

import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[3]
SC4 = ROOT / "SCORE 4" / "SCORE" / "LIB"
WS = ROOT / "WINSCORE 5.01" / "winscore" / "scorlib"
CONTINUED, END = 0x81, 0x82


def fortran_records(data: bytes) -> list[bytes]:
    if data[0] != 0x4B:
        raise ValueError("not a Microsoft FORTRAN unformatted file")
    records, current, pos = [], b"", 1
    while pos < len(data) and data[pos] != END:          # some SCORE 4 files lack the end byte
        length = data[pos]
        size = 128 if length == CONTINUED else length
        current += data[pos + 1:pos + 1 + size]
        if pos + 1 + size < len(data) and data[pos + 1 + size] != length:
            raise ValueError(f"record framing broken at byte {pos}")
        pos += size + 2
        if length != CONTINUED:
            records.append(current)
            current = b""
    return records + ([current] if current else [])


def read_kh(path: Path):
    """Ten symbols as lists of (x, y, pen) and their names."""
    header, points = fortran_records(path.read_bytes())[:2]
    offsets = [max(o, 1) for o in struct.unpack_from("<11h", header)]
    names = [header[22 + 5 * i:27 + 5 * i].decode("latin-1").strip() for i in range(10)]
    words = struct.unpack(f"<{len(points) // 2}h", points)
    symbols = [[tuple(words[j:j + 3]) for j in range(offsets[k] - 1, offsets[k + 1] - 1, 3)] if names[k] else []
               for k in range(10)]
    return names, symbols, offsets


def read_float(path: Path):
    data = path.read_bytes()
    offsets = [max(o, 1) for o in struct.unpack_from("<11h", data)]
    names = [data[22 + 24 * i:46 + 24 * i].decode("latin-1").strip() for i in range(10)]
    n = offsets[10] - 1
    xs = struct.unpack_from(f"<{n}f", data, 262)
    ys = struct.unpack_from(f"<{n}f", data, 262 + 4 * n)
    pens = struct.unpack_from(f"<{n}h", data, 262 + 8 * n)
    records = list(zip(xs, ys, pens))
    return names, [records[offsets[k] - 1:offsets[k + 1] - 1] if names[k] else [] for k in range(10)]


def main():
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for lib in range(0, 100):
        kh_path = SC4 / f"LIB{letters[17 + lib // 26] if lib < 234 else '?'}{letters[lib % 26]}.DRW"
        ws_path = WS / f"LB{lib:03d}0.DRW"
        if not (kh_path.exists() and ws_path.exists()) or ws_path.read_bytes()[:2] == b"KH":
            continue
        kn, ks, _ = read_kh(kh_path)
        fn, fs = read_float(ws_path)
        same = [k for k in range(10) if kn[k] and kn[k] == fn[k] and [(float(x), float(y), p) for x, y, p in ks[k]] == [(x, y, p) for x, y, p in fs[k]]]
        named = [k for k in range(10) if kn[k]]
        print(f"{kh_path.name} vs {ws_path.name}: {len(same)}/{len(named)} symbols identical", "" if len(same) == len(named) else f"names {kn} / {fn}")
    for extra in (WS / "FAULT.DRW", WS / "KBRHY.DRW"):
        names, symbols, offsets = read_kh(extra)
        print(extra.name, [(n, len(s)) for n, s in zip(names, symbols) if n])


if __name__ == "__main__":
    sys.exit(main())
