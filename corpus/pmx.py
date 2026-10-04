"""SCORE PMX, the text form of a .mus file: one item per line, P1, P2, ... as decimals.

A code-16 item starts with "t" in place of 16 and lists P2 to P11; its characters follow
on the next line. P12 is their count. P13, the string length SCORE computes, is not in
the text form and stays 0. Trailing zero parameters are dropped as SCORE does when saving.
"""
from __future__ import annotations

import sys
from itertools import takewhile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "oracle"))

from musbuild import mus_bytes, text_item  # noqa: E402

TEXT_CODE = 16


def numbers(line: str) -> list[float] | None:
    try:
        return [float(word) for word in line.split()]
    except ValueError:
        return None


def without_trailing_zeros(params: list[float]) -> list[float]:
    zeros = sum(1 for _ in takewhile(lambda v: v == 0, reversed(params[1:])))
    return params[:len(params) - zeros]


def text_params(head: list[float], text: bytes) -> list[float]:
    """P1 to P12 of a text item; head is P2 to P11."""
    padded = (head + [0.0] * 10)[:10]
    return [TEXT_CODE, *padded, float(len(text))]


def is_item_code(value: float) -> bool:
    return value == int(value) and 1 <= value <= 99


def pmx_items(source: str) -> list | None:
    """The items as parameter lists or packed text items, or None if this is not SCORE PMX."""
    items = []
    lines = iter(source.splitlines())
    for line in lines:
        code, _, rest = line.strip().partition(" ")
        if not code:
            continue
        if code == "t":
            head, text = numbers(rest), next(lines, None)
            if head is None or text is None:
                return None
            items.append(text_item(text_params(head, text.encode("latin-1")), text.encode("latin-1")))
            continue
        params = numbers(line)
        if not params or not is_item_code(params[0]):
            return None
        items.append(without_trailing_zeros(params))
    return items or None


def pmx_to_mus(source: str) -> bytes | None:
    items = pmx_items(source)
    return mus_bytes(items) if items is not None else None
