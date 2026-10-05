"""SCORE PMX, the text form of a .mus file: one item per line, P1, P2, ... as decimals.

A code-16 item starts with "t" in place of 16 and lists P2 to P11; its characters follow
on the next line. P12 is their count. Some listings (Sapp's 1999 files) stop at P11, so
P13, the string length SCORE computes, stays 0; others (Sapp's "SCORE 4 PMX" of 2014) also
list P12 and P13. A text item without characters, or with nothing but font codes, is left
out: the engine deletes it (as an unknown code, or with "No text found"). Lines starting with "#" or with code 99 are comments, lines starting with
"@" are scorelib's named parameters, and two-letter SCORE commands (RS, SM) are skipped,
as are "T" items with their following line (SVG markup).
Trailing zero parameters are dropped as SCORE does when saving.
"""
from __future__ import annotations

import re
import sys
from itertools import takewhile
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "oracle"))

from musbuild import mus_bytes, text_item  # noqa: E402

TEXT_CODE = 16
TEXT = "t"
MARKUP_TEXT = "T"     # Sapp's SVG markup in a text item (font _99), not SCORE content
COMMENT_CODE = "99"   # a line of free text; the engine deletes a code-99 item as unknown
FONT_CODES_ONLY = re.compile(r"(?:_+\d\d)*\s*")   # "No text found": the engine deletes the item


def numbers(line: str) -> list[float] | None:
    try:
        return [float(word) for word in line.split()]
    except ValueError:
        return None


def without_trailing_zeros(params: list[float]) -> list[float]:
    zeros = sum(1 for _ in takewhile(lambda v: v == 0, reversed(params[1:])))
    return params[:len(params) - zeros]


def text_params(head: list[float], text: bytes) -> list[float]:
    """The parameters of a text item. head is P2 to P11, optionally followed by P12, P13, ...;
    P12 is set to the character count either way. P13 is always stored: the engine deletes
    a text item with fewer than 13 parameters as an unknown code."""
    padded = (head + [0.0] * 10)[:10]
    return [TEXT_CODE, *padded, float(len(text)), *(head[11:] or [0.0])]


def is_command(word: str) -> bool:
    """A SCORE command such as RS or SM in a command script around the listing."""
    return len(word) == 2 and word.isalpha() and word.isupper()


def is_item_code(value: float) -> bool:
    return value == int(value) and 1 <= value <= 99


def is_skipped(code: str) -> bool:
    return not code or code.startswith(("#", "@")) or is_command(code) or code.rstrip(".") == COMMENT_CODE


def pmx_items(source: str) -> list | None:
    """The items as parameter lists or packed text items, or None if this is not SCORE PMX.
    Lines that are not items may follow the listing (bol.sapp.org files end with three)."""
    items, ended = [], False
    lines = iter(source.splitlines())
    for line in lines:
        code, _, rest = line.strip().partition(" ")
        if is_skipped(code):
            continue
        if code in (TEXT, MARKUP_TEXT):
            head, text = numbers(rest), next(lines, None)
            if head is None or text is None or ended:
                return None
            if code == TEXT and not FONT_CODES_ONLY.fullmatch(text):
                items.append(text_item(text_params(head, text.encode("latin-1")), text.encode("latin-1")))
            continue
        params = numbers(line)
        if not params or not is_item_code(params[0]):
            ended = True
        elif ended:
            return None
        else:
            items.append(without_trailing_zeros(params))
    return items or None


def pmx_to_mus(source: str) -> bytes | None:
    items = pmx_items(source)
    return mus_bytes(items) if items is not None else None


PAGE_MARK = re.compile(r"^(?:###ScorePage:|SA )", re.M)


def pages(source: str) -> dict[str, str]:
    """The pages of a multi-page PMX file (Sapp's .ppmx), by the name after each "###ScorePage:"
    or after each SCORE command "SA <name>" (save as) of a command script."""
    chunks = PAGE_MARK.split(source)[1:]
    return {name.strip(): body for name, _, body in (chunk.partition("\n") for chunk in chunks)}


def split(path: Path, out: Path) -> list[Path]:
    """Write each page of a .ppmx file as out/<page>.pmx."""
    out.mkdir(parents=True, exist_ok=True)
    targets = {out / f"{name}.pmx": body for name, body in pages(path.read_text(encoding="latin-1")).items()}
    for target, body in targets.items():
        target.write_text(body, encoding="latin-1")
    return list(targets)


if __name__ == "__main__":
    # python corpus/pmx.py FILE.ppmx OUTDIR
    print("\n".join(map(str, split(Path(sys.argv[1]), Path(sys.argv[2])))))
