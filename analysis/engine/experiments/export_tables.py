"""Dump tables the engine reads at start-up into analysis/engine/data/ (TSV, exact f32 values as decimal).

    python export_tables.py

trig.tsv: the circle table read from WSCORE.DAT by 0x4A7440 (Fortran READ at 0x4A7B13): for each
whole degree a = 0..360, S(a) at 0x1C58A20 + 8a and C(a) at 0x1C58A24 + 8a, about 100*sin(a) and
100*cos(a) rounded to three decimals (ten entries differ from correctly rounded values in the last digit).
"""
from __future__ import annotations

import struct
from pathlib import Path

from lab import Lab

DATA = Path(__file__).resolve().parents[1] / "data"
TRIG = 0x1C58A20


def f32_at(lab: Lab, address: int) -> float:
    return struct.unpack("<f", lab.engine.uc.mem_read(address, 4))[0]


def main():
    lab = Lab()
    DATA.mkdir(exist_ok=True)
    rows = (f"{a}\t{f32_at(lab, TRIG + 8 * a)!r}\t{f32_at(lab, TRIG + 8 * a + 4)!r}" for a in range(361))
    (DATA / "trig.tsv").write_text("degree\tS\tC\n" + "\n".join(rows) + "\n")


if __name__ == "__main__":
    main()
