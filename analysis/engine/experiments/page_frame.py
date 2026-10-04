"""Page frame per paper type: innermost rectangle in internal coordinates (coordinates.md).

    python page_frame.py
"""
from lab import Lab

PAPER, VIEW_DX, VIEW_DY = 0x791638, 0x20527F0, 0x20527F4
FRAME_COLOUR = 0x00FD00


def main():
    lab = Lab()
    engine = lab.engine
    for paper in range(9):
        engine.put32(PAPER, paper)
        result = lab.load([[8, 1, 0, 0, 1]])
        dx, dy = engine.i32(VIEW_DX), engine.i32(VIEW_DY)
        inner = [(x - dx, y + dy) for x, y, tag in result.vector if tag & 0xFFFFFF == FRAME_COLOUR][:5]
        title = next((e.detail for e in reversed(engine.shell.events) if e.kind == "document"), "")
        if inner:
            xs, ys = [p[0] for p in inner], [p[1] for p in inner]
            print(f"{paper}  x {min(xs)} .. {max(xs)}  y {min(ys)} .. {max(ys)}  {title.split()[-1]}")
        else:
            print(f"{paper}  no frame")


if __name__ == "__main__":
    main()
