"""RIP: ripple bars from one system to another (0x51FFC0 with 0x521109, 0x521182, 0x521219,
0x52127B, the region select 0x49B1D8, LJ through 0x4B80B7 and the CW part of 0x443B70), and the
check against the oracle.

    python rip.py [cases] [plain|rich]

`RIP n1 n2 n3 [n4]`: systems of n1 staves, source bottom staff n2, destination bottom staff n3,
n4 bars (default 1). Staff numbers grow upwards, so the system with the higher numbers comes first
in the music: bars rippled to a higher system leave the start of the source and are appended to
the destination, bars rippled to a lower system leave the end of the source and are put in front
of the destination. Both systems are then lined up and justified.

Not modelled: rippling across the recto staves (one system below 200, the other above), and the
stale item pointers the engine keeps when a deleted courtesy meter precedes them in storage.
"""
from __future__ import annotations

import math
import random
import sys

from grace import GraceSession
from justify import LayoutPass, Selection, decorate, layout_pass, select_box, with_grace
from lineup import F, LineupError, code, nint, par, rich_staff, sort_items, staff, xpos


# The second LJ reads P1, P2 as the redraw after the first left them (in the oracle the code and
# staff of a note on the top staff); not modelled, so its clef nudge (a clef standing exactly at
# its staff item's x, P1 <= x < P2) never fires here.
AFTER_REDRAW = (math.inf, -math.inf)


def shift(items, sel: Selection, delta: float):
    """0x521109"""
    for i, k in sel.refs:
        items[i - 1][k - 1] = F(delta + items[i - 1][k - 1])


def scale(items, sel: Selection, factor: float, origin: float):
    """0x521182: v -> factor * v + (origin - factor * origin)."""
    offset = F(origin - factor * origin)
    for i, k in sel.refs:
        items[i - 1][k - 1] = F(factor * items[i - 1][k - 1] + offset)


def restaff(items, sel: Selection, delta: int):
    """0x4E7EEA: P2 += delta for the items whose P3 was selected."""
    for i, k in sel.refs:
        if k == 3:
            items[i - 1][1] = F(float(delta) + items[i - 1][1])


def stored_words(items, i: int) -> list[float]:
    """The storage from item i on: its length word, then its parameters, then the next item's."""
    return [w for it in items[i - 1:] for w in [float(len(it)), *it]]


class Ripple:
    def __init__(self, items, n1: int, n2: int, n3: int, n4: int = 1, right: float = 200.0,
                 grace: GraceSession | None = None):
        self.items = [list(it) for it in items]
        self.n1, self.src, self.dst, self.bars = n1, n2, n3, n4 or 1
        self.right = right
        self.grace = grace or GraceSession()
        self.low, self.high = min(n2, n3), max(n2, n3)

    def select(self, lo: int, hi: int, x0: float, x1: float, mode: int = 0) -> Selection:
        return select_box(self.items, lo, hi, x0, x1, self.right, mode)

    def run(self) -> list[list[float]]:
        n1, src, dst, right = self.n1, self.src, self.dst, self.right
        if min(dst, src, n1, self.bars) < 1:
            return self.items
        if (src > 200) != (dst > 200):
            raise NotImplementedError("rippling across the recto staves is not modelled")
        top_src, top_dst = n1 - 1 + src, n1 - 1 + dst
        self.items = sort_items(self.items)
        found = self.find_bars()
        if found is None:
            return self.items
        dst_first, src_first, cut_bar = found
        self.drop_end_meters()
        cut = F(xpos(src_first) - 1) if cut_bar is None else F(xpos(cut_bar) + F(0.1))
        if dst < src:
            moved = F(right - cut)
            dest_x = F(xpos(dst_first) - 1)
            room = F(moved + 10)
            shift(self.items, self.select(dst, top_dst, dest_x, 210.0), room)
            self.move_source(cut, 210.0, 2, F(dest_x - cut))
            dest_room = F(right - dest_x)
            span = F(moved + dest_room + F(9.9))
            factor = F((dest_room - 1) / span)
            scale(self.items, self.select(dst, top_dst, dest_x, F(span + dest_x), -1), factor, dest_x)
            shift(self.items, self.select(dst, top_dst, 210.0, 1000.0), F(-room))
        else:
            dest_x = xpos(dst_first)
            start = F(xpos(src_first) - 1)
            moved = F(cut - start)
            room = F(210 - start)
            self.move_source(start, cut, 0, room)
            span = F(right + moved + 10)
            factor = F((right - dest_x) / (span - dest_x))
            scale(self.items, self.select(dst, top_dst, dest_x, span, 2), factor, dest_x)
            shift(self.items, self.select(src, top_src, 210.0, 1000.0), F(-room))
        if cut_bar is not None:
            cut_bar[2] = right
        self.box = (span, room)
        self.end_meters()
        source = self.layout(src, top_src, (float(dst - src), float(n1)))
        dest = self.layout(dst, top_dst, AFTER_REDRAW)
        self.match_clefs()
        if source.lo < dest.hi:
            self.mark_rests(source.lo, dest.hi)
        else:
            self.mark_rests(dest.lo, source.hi)
        return self.items

    def layout(self, lo: int, hi: int, clef_box: tuple[float, float]) -> LayoutPass:
        """LJ through 0x4B80B7 with the box (span, room); `clef_box` holds the globals P1, P2."""
        result = layout_pass(self.items, lo, hi, "LJ", self.right, self.box, self.grace, clef_box)
        self.items = result.items
        return result

    def find_bars(self):
        """The first note, rest or meter of the destination and the source, and the cut barline.

        Every staff from the lower to the higher bottom staff other than the destination's counts
        as source, and barlines count when their rounded x differs from the previous one counted.
        """
        dst_first = src_first = None
        bars: list[list[float]] = []
        last = -999
        for it in self.items:
            s, c = staff(it), code(it)
            if s < self.low:
                continue
            if s > self.high:
                break
            if s == self.dst:
                if dst_first is None and (c < 3 or c == 18):
                    dst_first = it
            elif c < 3 or c == 18:
                src_first = src_first or it
            elif c == 14 and src_first is not None and nint(xpos(it)) != last:
                bars.append(it)
                last = nint(xpos(it))
        if len(bars) < self.bars:
            return None
        which = self.bars if self.dst > self.src else len(bars) - self.bars
        return dst_first, src_first, bars[which - 1] if which else None

    def move_source(self, x0: float, x1: float, mode: int, delta: float):
        """0x521219: staff by staff, shift the source region and move it to the destination staves."""
        for s in range(self.src, self.src + self.n1):
            sel = self.select(s, s, x0, x1, mode)
            shift(self.items, sel, delta)
            restaff(self.items, sel, self.dst - self.src)

    def drop_end_meters(self):
        """On each staff of the earlier system the first meter at x >= 195 is deleted."""
        i = 0
        for s in range(self.high, self.high + self.n1):
            while i < len(self.items) and staff(self.items[i]) <= s:
                it = self.items[i]
                if staff(it) == s and it[0] == 18 and xpos(it) >= 195:
                    del self.items[i]
                    break
                i += 1

    def end_meters(self):
        """0x52127B: a meter opening the later system is repeated at x = 199 on the earlier one."""
        self.items = sort_items(self.items)
        opening = [it for it in self.items if staff(it) == self.low and (code(it) < 3 or code(it) == 18)]
        if not opening or code(opening[0]) != 18:
            return
        meter = opening[0]
        bar = next((it for it in self.items if xpos(it) >= 199 and code(it) == 14 and staff(it) == self.high), None)
        if bar is not None and par(bar, 5) != 2:
            bar[2] = F(198)
        self.items += [[18.0, float(self.high + k), 199.0, *meter[3:]] for k in range(self.n1)]
        self.items = sort_items(self.items)

    def match_clefs(self):
        """The later system's first clef takes P5 of the earlier system's last clef, with P4 = 0."""
        for k in range(self.n1):
            first = next((it for it in self.items if staff(it) == self.low + k and it[0] == 3), None)
            last = next((it for it in reversed(self.items) if staff(it) == self.high + k and it[0] == 3), None)
            if first is None or last is None:
                continue
            want = last[4] if len(last) >= 5 else 0.0
            if want == (first[4] if len(first) >= 5 else 0.0):
                continue
            if len(first) < 5:
                first.extend([0.0] * 2)
            first[3], first[4] = 0.0, want

    def mark_rests(self, lo: int, hi: int):
        """CW as RIP calls it (letter 'X', so without the P5 <= -2 condition): P9 = -1 on every rest.

        A rest shorter than 9 parameters grows in place: the new words keep what storage held there,
        the start of the next item, except that P8 is cleared when it is new.
        """
        sel = select_box(self.items, lo, hi, 0.0, 220.0, self.right, 0x44, codes=(2,))
        for i, _ in sel.refs:
            it = self.items[i - 1]
            n = len(it)
            if n < 9:
                after = stored_words(self.items, i + 1) if i < len(self.items) else []
                it.extend((after + [0.0] * 9)[:9 - n])
                if n < 8:
                    it[7] = 0.0
            it[8] = -1.0


# ---------------------------------------------------------------- check against the engine

def staff_of_bars(rng: random.Random, s: int, bars: int, meter: bool) -> list[list[float]]:
    items = [[8, s, 0, 0, 1], [3, s, 2, 0, rng.choice([0, 0, 1])]]
    if meter:
        items.append([18, s, 6, 4, 4])
    x = 12.0
    for _ in range(bars):
        for d in (1, 1, 1, 1) if rng.random() < 0.6 else (2, 1, 1):
            if rng.random() < 0.1:
                rest = [2, s, round(x, 2), 0, rng.choice([0, 0, -2]), 0, d]
                items.append(rest[:rng.choice([7, 7, 5, 6])])
            else:
                items.append([1, s, round(x, 2), rng.randint(1, 10), 10, 0, d])
            x += rng.uniform(5, 10) * d
        items.append([14, s, round(x, 2), 1])
        x += rng.uniform(3, 5)
    if meter and rng.random() < 0.5:
        items.append([18, s, 199, 3, 4])
    return items


def plain_systems(rng: random.Random, n1: int) -> list[list[float]]:
    meter = rng.random() < 0.4
    items = []
    for system in range(2):
        bars = rng.randint(1, 4)
        items += [it for s in range(1 + system * n1, 1 + (system + 1) * n1)
                  for it in staff_of_bars(rng, s, bars, meter)]
    return items


def rich_systems(rng: random.Random, n1: int) -> list[list[float]]:
    """Two systems of rich_staff staves (decorated, some with grace notes), with clef changes
    between the systems, clefs at the staff item's x and courtesy meters at the end."""
    items = []
    for system in range(2):
        measures = rng.randint(1, 4)
        grace = rng.random() < 0.3
        for s in range(1 + system * n1, 1 + (system + 1) * n1):
            staff_items = [decorate(rng, it) for it in rich_staff(rng, s, measures)]
            if grace:
                staff_items = with_grace(rng, staff_items)
            clef = staff_items[1]
            clef[4] = rng.choice([0, 0, 1, 2])
            if rng.random() < 0.2:
                clef[2] = 0
            if system == 1 and rng.random() < 0.3:
                staff_items.append([18, s, 199, 0, 3, 4])
            items += staff_items
    return items


def random_case(rng: random.Random, kind: str = "plain"):
    n1 = rng.choice([1, 1, 2, 3])
    items = (rich_systems if kind == "rich" else plain_systems)(rng, n1)
    src, dst = rng.choice([(1, 1 + n1), (1 + n1, 1)])
    return [[F(float(v)) for v in it] for it in items], n1, src, dst, rng.choice([1, 1, 2, 3])


def same(model, engine) -> bool:
    from corpus_layout import centred_rest_p9
    return len(model) == len(engine) and all(a == b or centred_rest_p9(a, b) for a, b in zip(model, engine))


def main(cases: int = 30, kind: str = "plain"):
    from layoutlab import run_layout
    rng = random.Random(17)
    good = total = 0
    for case in range(cases):
        items, n1, src, dst, bars = random_case(rng, kind)
        word = f"RIP {n1} {src} {dst} {bars}"
        try:
            model = Ripple(items, n1, src, dst, bars).run()
        except (LineupError, NotImplementedError) as err:
            print(f"case {case} {word}: skipped, {err}")
            continue
        engine, _ = run_layout(items, [word], digits=None)
        total += 1
        if same(model, engine):
            good += 1
            continue
        print(f"case {case} {word}: model {len(model)} items, engine {len(engine)}")
        a, b = next(((a, b) for a, b in zip(model, engine) if not same([a], [b])), (None, None))
        if a is not None:
            print("   model ", [round(v, 4) for v in a], "\n   engine", [round(v, 4) for v in b])
    print(f"{good}/{total} identical")


if __name__ == "__main__":
    main(*(int(a) if a.isdigit() else a for a in sys.argv[1:]))
