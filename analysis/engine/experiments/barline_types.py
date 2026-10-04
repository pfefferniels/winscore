"""Print the points of every barline type (and a few variants) over staves 1 and 2, in internal coordinates.

    python barline_types.py
"""
from lab import Lab

VIEW_DX, VIEW_DY = 0x20527F0, 0x20527F4
STAVES = [[8, 1, 0, 0, 1], [8, 2, 0, 0, 1]]
CASES = [([14, 1, 100, 1, t], f"type {t}") for t in range(11)] + [
    ([14, 1, 100, 2, 1], "type 1 over two staves"),
    ([14, 1, 100, -1, 0], "invisible (P4 = -1)"),
    ([14, 1, 100, 1, -44], "type -44 (bar with two-bar repeat sign)"),
    ([14, 1, 100, 1, 9, 0, 0, 1], "bracket, P8 = 1"),
    ([14, 1, 100, 1, 9, 0, 0, 2], "bracket, P8 = 2"),
    ([14, 1, 100, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40, 2], "gap P18 = 40, P19 = 2"),
]


def main():
    lab = Lab()
    background = len(lab.load(STAVES).vector)
    for item, label in CASES:
        result = lab.load(STAVES + [item])
        dx, dy = lab.engine.i32(VIEW_DX), lab.engine.i32(VIEW_DY)
        print(f"== {label}: {item}")
        for x, y, tag in result.vector[background:]:
            print(f"   {x - dx:6d} {y + dy:7d}  pen {tag >> 24}  colour {tag & 0xFFFFFF:06x}")


if __name__ == "__main__":
    main()
