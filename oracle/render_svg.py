"""Render a decoded display list to SVG (y axis flipped: engine y grows upward)."""
from __future__ import annotations

from html import escape

from displaylist import FILLED, POLYLINE, Shape, TextRun


def colour_hex(colorref: int) -> str:
    r, g, b = colorref & 0xFF, (colorref >> 8) & 0xFF, (colorref >> 16) & 0xFF
    return f"#{r:02x}{g:02x}{b:02x}"


def bounds(shapes: list[Shape]):
    pts = [p for s in shapes for path in s.paths for p in path]
    xs, ys = [p[0] for p in pts], [p[1] for p in pts]
    return min(xs), min(ys), max(xs), max(ys)


def path_data(shape: Shape, close: bool) -> str:
    parts = []
    for path in shape.paths:
        head, *rest = path
        parts.append(f"M{head[0]} {-head[1]}" + "".join(f"L{x} {-y}" for x, y in rest) + ("Z" if close else ""))
    return "".join(parts)


TEXT_TOP_OFFSET = 96      # OnDraw adds zoom * 0x60 / 256 logical units to y
ASCENT = 0.8              # rough cell-top to baseline ratio; real metrics depend on the font


def to_svg(shapes: list[Shape], runs: list[TextRun]) -> str:
    x0, y0, x1, y1 = bounds(shapes)
    pad = (x1 - x0) // 40
    view = f"{x0 - pad} {-y1 - pad} {x1 - x0 + 2 * pad} {y1 - y0 + 2 * pad}"
    body = []
    for s in shapes:
        colour = colour_hex(s.colour)
        if s.kind == POLYLINE:
            body.append(f'<path d="{path_data(s, False)}" fill="none" stroke="{colour}" stroke-width="{pad / 40:.1f}"/>')
        else:
            body.append(f'<path d="{path_data(s, True)}" fill="{colour}" fill-rule="evenodd"/>')
    for run in runs:
        size = run.engine_height
        style = f'font-family="{escape(run.font)}" font-size="{size:.1f}"' + (' font-style="italic"' if run.italic else "") \
            + (' font-weight="bold"' if run.weight >= 600 else "")
        for t in run.strings:
            baseline = -(t.y + TEXT_TOP_OFFSET) + ASCENT * size
            body.append(f'<text x="{t.x}" y="{baseline:.0f}" {style}>{escape(t.text)}</text>')
    return (f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="{view}" style="background:#fff">'
            + "".join(body) + "</svg>")
