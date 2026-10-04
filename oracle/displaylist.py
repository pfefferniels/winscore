"""Decode the engine's vector and text streams the way WScore.exe's C++ shell does.

Mirrors 0x5A4570 (text runs, object-start cleanup) and 0x5A4900 (polygon
assembly). Coordinates stay in engine units; the shell scales them by zoom/256.
"""
from __future__ import annotations

import struct
from dataclasses import dataclass, field

TYPE_MASK = 0xFF000000
POLYLINE, FILLED, NEW_SUBPATH, SKIP = 0x01, 0x02, 0x03, 0xFF


@dataclass(frozen=True)
class Shape:
    kind: int                      # high byte of the first tag: 1 polyline, 2 filled, other
    colour: int                    # 0xBBGGRR as stored by the engine (Windows COLORREF)
    paths: tuple[tuple[tuple[int, int], ...], ...]


@dataclass(frozen=True)
class TextString:
    x: int
    y: int
    text: str


@dataclass(frozen=True)
class TextRun:
    font: str
    height: float                  # CreateFontA height = zoom * height / 4 (0.001 in at zoom 64)
    width: float                   # CreateFontA width  = zoom * width / 4
    escapement: int
    colour: int
    weight: int
    italic: bool
    underline: bool
    strings: tuple[TextString, ...]

    @property
    def engine_height(self) -> float:
        """Character height in engine units (1/4000 inch)."""
        return 64 * self.height


def mark_empty_starts(tags: list[int]) -> list[int]:
    """0x5A4570: an object start directly followed by another start is skipped."""
    marked = list(tags)
    for i in range(len(marked) - 1):
        if marked[i] & TYPE_MASK and marked[i + 1] & TYPE_MASK:
            marked[i] |= TYPE_MASK
    return marked


def shapes(vector: list[tuple[int, int, int]]) -> list[Shape]:
    """0x5A4900: split (x, y, tag) triples into objects and sub-paths."""
    tags = mark_empty_starts([t for _, _, t in vector])
    triples = [(x, y, t) for (x, y, _), t in zip(vector, tags)]
    out: list[Shape] = []
    i, n = 0, len(triples)
    while i < n:
        first_tag = triples[i][2]
        paths: list[list[tuple[int, int]]] = [[]]
        while i < n:
            while i < n and triples[i][2] >> 24 == SKIP:
                i += 1
            if i >= n:
                break
            x, y, _ = triples[i]
            paths[-1].append((x, y))
            i += 1
            if i >= n:
                break
            kind = triples[i][2] >> 24
            if kind == 0:
                continue
            if kind != NEW_SUBPATH:
                break
            paths.append([])
        out.append(Shape(first_tag >> 24, first_tag & 0xFFFFFF, tuple(tuple(p) for p in paths if p)))
    return out


def _cstring(buf: bytes, pos: int) -> tuple[str, int]:
    end = buf.index(b"\0", pos)
    return buf[pos:end].decode("cp1252"), end


def text_runs(buf: bytes) -> list[TextRun]:
    """0x5A4570: font header (33 bytes after the name's NUL) then (x, y, string) entries.

    OnDraw (0x5E5910) places each string with TextOut at (x, y + 96) engine units,
    i.e. by the top-left of its character cell.
    """
    runs, pos = [], 0
    while pos < len(buf):
        font, nul = _cstring(buf, pos)
        height, double_width, escapement, colour, weight = struct.unpack_from("<ffiii", buf, nul + 1)
        italic, underline = buf[nul + 0x15], buf[nul + 0x19]
        count = struct.unpack_from("<i", buf, nul + 0x1D)[0]
        pos = nul + 0x21
        strings = []
        for _ in range(count):
            x, y = struct.unpack_from("<ii", buf, pos)
            text, end = _cstring(buf, pos + 8)
            strings.append(TextString(x, y, text))
            pos = end + 1
        runs.append(TextRun(font, height, double_width / 2, escapement, colour, weight, bool(italic), bool(underline), tuple(strings)))
    return runs
