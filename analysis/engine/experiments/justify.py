"""Reference model of SCORE's justify (J, the second half of LJ), ported from WScore.exe with
the engine's f32 stores, the drivers for LI, J and LJ (0x4B80B7), and the check against the oracle.

    python justify.py [cases] [max_staves] [command] [dense]   (default 50 cases, 1..3 staves, LJ, rich)

Items and conventions as in lineup.py. Justify keeps state in globals that persist from one
staff to the next; `JustifyState` holds them, starting from zero as in a fresh engine.
"""
from __future__ import annotations

import math
import random
import sys
from dataclasses import dataclass, field

from lineup import (F, LineupError, Lineup, code, staff, xpos, par, p14_or_p15, prepare,
                    staff_steps, trunc, rich_staff, rich_system)

# f32 table around 0x792554: [-3] 0, [-2] 2.833 (shifted head), [-1] 5.0 (wide head), [0] 4.5 (head),
# [1..18] accidental widths by P5 mod 10 (+9 above 100)
TABLE = {i - 5: F(v) for i, v in enumerate(
    (0, 0, 0, 2.833, 5.0, 4.5, 2.0, 2.4, 2.1, 4.0, 2.5, 2.0, 3.4, 2.0, 2.8, 4.1, 4.6, 4.1, 6.2, 4.5,
     0, 0, 0, 0))}
HEAD, WIDE_HEAD, SHIFTED_HEAD = TABLE[0], TABLE[-1], TABLE[-2]
AFTER_CLEF, AFTER_BARLINE, AFTER_KEY, AFTER_METER = F(1.8), F(1.5), F(2.8), F(0.9)   # 0x78B490..


def imod(a: int, b: int) -> int:
    """Fortran MOD on integers: the sign follows the dividend."""
    return a - b * trunc(a / b)


def amod(x: float, y: float) -> float:
    """0x54AABA, stored to f32 by every caller here."""
    return F(x - trunc(x / y) * y)


def fmod32(x: float, y: float) -> float:
    """Runtime AMOD 0x5FF874 (exact remainder)."""
    return F(math.fmod(x, y))


# ---------------------------------------------------------------- selection for J (0x49B1D8, mode 0)

@dataclass
class Selection:
    """Selected parameters as (item index, parameter number); None once consumed by 0x4B63CD."""
    refs: list[tuple[int, int] | None]


def select_box(items, lo: int, hi: int, x0: float, x1: float, right: float) -> Selection:
    lo_x, hi_x = F(x0 - F(0.001)), F((x1 if x1 != 0 else 200.0) + F(0.001))
    refs: list[tuple[int, int] | None] = []

    def maybe(i, it, k):
        if k <= len(it) and lo_x <= it[k - 1] <= hi_x:
            refs.append((i, k))

    for i, it in enumerate(items, 1):
        s, c = staff(it), code(it)
        if not lo <= s <= hi:
            continue
        maybe(i, it, 3)
        n = len(it)
        if not (n > 5 and 3 < c < 9):
            continue
        if c == 8 and it[5] == 0:
            it[5] = right
        if c == 4 and n >= 7 and it[6] < 0 and it[5] == 0:
            continue
        maybe(i, it, 6)
        if n <= 7:
            continue
        if c == 4:
            if it[6] == 100:
                maybe(i, it, 8)
                k = 10
                while k <= n:
                    maybe(i, it, k)
                    if k == 16:
                        break
                    k += 2
        elif c == 6:
            if n > 10:
                if it[10] > 0:
                    maybe(i, it, 11)
                if it[6] >= 0 and n > 11:
                    if it[11] > 0:
                        maybe(i, it, 12)
                    if n > 13 and it[12] != 0:
                        if it[13] > 0:
                            maybe(i, it, 14)
                        if n > 14 and it[14] > 0:
                            maybe(i, it, 15)
        elif c in (7, 8) and trunc(it[6]) > 19 and it[7] > 0:
            maybe(i, it, 8)
    return Selection(refs)


# ---------------------------------------------------------------- columns of one staff (0x4BCD68)

@dataclass
class JustifyState:
    """Globals of 0x4BCD68 that carry over between items and staves."""
    p: dict[int, float] = field(default_factory=dict)   # P array 0x1C58924.. (P3..P14)
    p_staff: int = 0
    start: int = 1                 # *param_1: items before it are ignored (except barlines)
    ledger_cur: int = 0            # 0x89F930
    small_clef: bool = False       # 0x89F8F0
    g938: float = 0.0              # 0x89F938, also read before it is set in one path
    chord_first: int = 0           # 0x89F900
    chord_scan: int = 0            # 0x89F940
    prev_p4m: float = 0.0          # 0x89F8F8
    prev_p5: float = 0.0           # 0x89F8FC
    prev_p9m: float = 0.0          # 0x89F8F4

    def load(self, it) -> int:
        """0x4B6CED: P3..P14 into the P array (zeros beyond the item); returns the item length."""
        self.p = {k: (it[k - 1] if k <= min(len(it), 14) else 0.0) for k in range(3, 15)}
        self.p_staff = staff(it)
        if self.p[6] <= -4 and it[0] == 1:
            self.p[5] = 0.0
            self.p[9] = 0.0
        return len(it)


def barline_widths(p, length: int, prev: int) -> tuple[float, float]:
    """0x4B6818; p[8] holds the size factor set by the caller."""
    right, left = F(2.5), F(1.0)
    kind = trunc(p[5])
    if length >= 5 and 1 <= kind <= 6:
        f, p13, p14 = p[8], p[13], p[14]
        if kind == 4:
            left, right = F(f * F(2)), F(f * F(6) + p13 + p14)
        elif kind == 5:
            left, right = F(f * F(5.4) + p13 + p14), F(f * F(6) + p13 + p14)
        elif kind == 6:
            left, right = F(f * F(4.3) + p14), F(f * F(7) + p13 + p14)
        else:
            left = {1: F(f * F(2.2)), 2: F(f * F(3.3)), 3: F(f * F(5.4) + p14)}[kind]
            left = F(p13 + left)
    if prev in (3, 17):
        left = F(left - 1)
    if p[7] != 0:
        left, right = F(left - p[7]), F(p[7] + right)
    return left, right


def rest_widths(it, p) -> tuple[float, float]:
    """0x4B6657 (its size factor is not used by the caller)."""
    left, right = 0.0, F(4.5)
    p5 = p[5]
    if abs(p5) >= 100:
        p5 = p[5] = fmod32(p5, 100)
        right = F(5)
    if p5 >= 0:
        if p5 > 1:
            right = F((p5 - 1) * F(0.5) + right)
    else:
        right = F(9.5) if p5 == -4 else F(6)
        if len(it) > 8 and it[8] != 0:
            right = F(1)
    if p[6] != 0:
        right = F(p[6] * F(1.75) + right)
    if len(it) > 9 and it[9] != 0:
        left = F(-it[9])
        right = F(it[9] + right)
    return left, right


def key_widths(p, prev: int) -> tuple[float, float]:
    """0x4B6C51"""
    left = F(2) if prev == 1 else 0.0
    count = F(abs(p[5] - trunc(p[5] / 100) * 100))
    right = F(5.5) if prev == 3 else F(4.5)
    scale = p[7] if p[7] != 0 else 1.0
    return left, F((count - 1) * F(2.8) * scale + right)


def other_widths(it, prev: int, rights: list[float]) -> tuple[float, float]:
    """0x4B6A52 (meters); may shorten the previous column's right need."""
    left, right = 0.0, F(7.5)
    if prev == 14:
        rights[-1] = F(rights[-1] - F(1.5))
        left = F(0.5)
    if prev == 1:
        left = F(2)
    if prev == 17:
        left = F(-1.5)
    P = lambda k: par(it, k)
    if (P(5) >= 10 or P(6) >= 10) and P(5) <= 90:
        right = F(right + F(2.5))
    last = len(it)
    while last > 0 and P(last) == 0:
        last -= 1
    if last > 7:
        extra = 0.0
        if last < 12 or P(12) == 0:
            extra = F(4.5)
            if last > 9 and P(10) != 0:
                extra = F(F(4.5) + P(10))
        if last > 10 and P(11) != 0:
            extra = F(extra + P(11))
        gap = F(6) if (P(8) > 10 or P(9) > 10) else F(3.5)
        right = F(extra + right + gap)
    return left, right




def item_words(items) -> list[int]:
    """Word offset W of each item in the item store (ITEM_PTR0), 1-based list with a dummy at 0."""
    words, w = [0], 1
    for it in items:
        words.append(w)
        w += len(it) + 1
    return words


@dataclass
class Columns:
    x: list[float]                 # x[0] is the box start
    need: list[float]              # need[k]: space wanted between x[k] and x[k+1], scaled


@dataclass
class StaffColumns:
    """0x4BCD68 for one staff."""
    items: list[list[float]]
    st: JustifyState
    words: list[int]
    lo: int
    step: float
    s: int
    x_left: float
    x_right: float
    xs: list[float] = field(default_factory=list)      # 1-based x of the collected items
    who: list[int] = field(default_factory=list)       # 1-based item indices
    n: int = 0
    scale: float = 1.0
    cols: list[float] = field(default_factory=list)
    rights: list[float] = field(default_factory=list)
    lefts: list[float] = field(default_factory=list)
    prev_code: int = 0
    prev_p12: float = 0.0
    ledger: int = 0

    def item(self, i):
        return self.items[i - 1]

    def item_at_word(self, w):
        return self.items[self.words.index(w) - 1]

    def collect(self):
        st, s = self.st, self.s
        x0, x1 = F(self.x_left - F(0.001)), F(self.x_right + F(0.001))
        picked: list[tuple[float, int]] = []
        for i, it in enumerate(self.items, 1):
            c = code(it)
            if not (c < 5 or c == 14 or (c == 10 and len(it) > 15 and it[15] != 0)
                    or (c > 16 and not p14_or_p15(it))):
                continue
            length = st.load(it)
            p = st.p
            if s < st.p_staff:
                break
            if not x0 <= p[3] <= x1:
                continue
            if c == 14:
                if self.lo <= st.p_staff and p[4] >= 0 and p[5] <= 7:
                    span = p[4] if p[4] != 0 else 1.0
                    if s < st.p_staff + span:
                        picked.append((p[3], i))
                continue
            if not (st.start <= i and s == st.p_staff):
                continue
            if c == 1 and p[7] < 0:
                continue
            if c == 2 and (p[6] < 0 or p[7] < 0):
                continue
            if c == 3 and p[5] > 5:
                continue
            if c == 4 and (par(it, 6) != 0 or length < 7 or par(it, 7) > -1):
                continue
            if c == 18 and abs((p[7] if p[7] != 0 else 1.0) * p[4]) > 2:
                continue
            picked.append((p[3], i))
        picked.sort(key=lambda e: e[0])
        self.n = len(picked)
        self.xs = [0.0] + [x for x, _ in picked] + [0.0]
        self.who = [0] + [i for _, i in picked] + [0]

    def w_of(self, j) -> int:
        return self.words[self.who[j]] if 0 < j <= self.n + 1 and self.who[j] else 0

    def run(self) -> Columns | None:
        self.collect()
        n, st = self.n, self.st
        if n <= 1:
            return None
        self.scale = F(self.step * F(0.04))
        self.cols, self.rights, self.lefts = [F(self.x_left - F(0.001))], [0.0], [0.0]
        self.prev_p12, self.ledger = 0.0, 0
        k = 0
        while True:
            k += 1
            k = self.one_item(k)
            if not k < n:
                break
        st.start = k
        rights = self.rights
        if len(self.cols) != 1:
            lefts = self.lefts + [0.0]
            rights = [F((r + l) * self.scale) for r, l in zip(rights, lefts[1:])]
        return Columns(list(self.cols), rights)

    def one_item(self, k: int) -> int:
        st = self.st
        w = self.who[k]
        it = self.item(w)
        c = trunc(it[0])
        length = st.load(it)
        left = right = 0.0
        p4m = amod(st.p[4], 100)
        if c < 2:
            found = self.note(k, w, it, length, p4m)
            if found is None:
                return k
            k, left, right = found
        else:
            self.ledger = 0
            left, right = self.other(k, it, c, length)
        self.add_to_column(c, left, right)
        return k

    def note(self, k, w, it, length, p4m):
        st, n = self.st, self.n
        p = st.p
        p6i = trunc(p[6])
        head = WIDE_HEAD if p6i < 20 and imod(p6i, 10) in (2, 3) else HEAD
        j = k
        if trunc(p[5]) > 100:
            p[5] = amod(p[5], 100)
        stem = trunc(p[5] / 10)
        broke = False
        while stem != 1:
            if stem != 0 or n <= j:
                broke = True
                break
            j += 1
            st.chord_scan = self.w_of(j)
            other = self.item(self.who[j])
            if other[0] != 1 or p[3] != xpos(other):
                broke = True
                break
            stem = trunc(imod(trunc(other[4]), 100) / 10)
        if not broke:
            if not j < n:
                return None
            head = self.flag_room(j, head)
        return self.chord(k, w, length, head, p4m, p6i)

    def flag_room(self, j, head) -> float:
        """Room for the flag of an up-stem note unless the next item at its x continues the chord."""
        st, n = self.st, self.n
        st.chord_scan = self.w_of(j + 1)
        other = self.item(self.who[j + 1])
        c2 = trunc(other[0])
        jump = c2 == 14
        if not jump:
            st.g938 = xpos(other)
            while c2 == 1:
                tail = imod(trunc(other[4]), 100)
                if tail > 19:
                    jump = True
                    break
                if tail > 9 or st.g938 != xpos(other) or n <= j:
                    break
                j += 1
                st.chord_scan = self.w_of(j)
                other = self.item(self.who[j])
                c2 = trunc(other[0])
            if not jump:
                return head
        while True:
            j += 1
            if n <= j:
                break
            st.chord_scan = self.w_of(j + 1)
            other = self.item(self.who[j + 1])
            if trunc(other[0]) != 1 or st.g938 != xpos(other):
                break
            if not imod(trunc(other[4]), 100) < 10:
                if not imod(trunc(other[4]), 100) > 19:
                    return head
                break
        st.g938 = F(0.5) if st.p[9] != 0 else F(1.5)
        return F(st.g938 + head)

    def chord(self, k, w, length, head, p4m, p6i):
        """LAB_004BDEB1: left and right needs of the chord that starts at collected item k."""
        st, n, xs = self.st, self.n, self.xs
        if self.ledger != st.ledger_cur:
            self.ledger = 0
        st.ledger_cur = 0
        m, count, first = k + 1, n - k + 1, k
        p5_first = st.p[5]
        while count > 0:
            k = m
            if not (m <= n and self.item(self.who[m])[0] == 1 and F(xs[m] - xs[m - 1]) < F(0.1)):
                break
            xs[m] = xs[m - 1]
            m += 1
            count -= 1
        k -= 1
        size = F(0.7) if abs(st.p[4]) >= 100 else 1.0
        if length > 14 and par(self.item(w), 15) != 0:
            size = F(size * self.item(w)[14])
        left_max = 0.0
        st.g938 = 0.0
        for m in range(first, k + 1):
            it = self.item(self.who[m])
            if it[0] != 1:
                continue
            left_acc, right_acc = self.note_extent(it, head, p4m, p6i, p5_first, size)
            left_max = max(left_max, left_acc)
            st.g938 = max(st.g938, right_acc)
        left = F(size * left_max)
        right = F((head + st.g938) * size)
        st.chord_first, st.chord_scan = first, k
        st.prev_p4m, st.prev_p5 = p4m, p5_first
        st.prev_p9m = amod(par(self.item(w), 9), 10) if length > 8 else 0.0
        self.prev_p12 = st.p[12]
        return k, left, right

    def note_extent(self, it, head, p4m, p6i, p5_first, size):
        st = self.st
        left_acc = right_acc = extra = 0.0
        n3 = st.load(it)
        p = st.p
        if n3 > 8 and p[9] != 0:
            dots = p[9]
            units = float(imod(trunc(dots), 10))
            tens = trunc(imod(trunc(dots), 100) / 10)
            if units != 0 and amod(p[5], 100) < 20:
                extra = F(size * F(2.3))
            frac = amod(dots, 1)
            if frac > F(0.9):
                frac = F(F(0.9) - frac)
            frac = F(frac * F(10) + tens * F(1.7))
            if extra < frac:
                extra = frac
        shift = 0.0
        if n3 > 9 and par(it, 10) != 0:
            shift = par(it, 10)
            if shift == 110:
                shift = F(10)
            t = shift
            if shift in (10, 20):
                t = HEAD if head == WIDE_HEAD else SHIFTED_HEAD
                if shift < 20:
                    right_acc = t
                else:
                    right_acc = -right_acc
                    self.ledger = 0
                    left_acc = t
            elif shift >= 0:
                n3 = -1
                right_acc = t
            else:
                left_acc = F(-shift)
        right_acc = F(extra + right_acc)
        p5i = trunc(p[5])
        acc = imod(p5i, 10)
        if acc != 0:
            self.ledger = 0
            if p5i > 100:
                acc += 9
            width = TABLE.get(acc, 0.0)
            skip = False
            if self.prev_code == 1 and st.chord_scan == st.chord_first:
                if self.prev_p12 != p[12]:
                    skip = True
                    if st.prev_p5 < 20 and p5_first < 20:
                        t = F(-1) if p[12] == 1 else p[12]
                        if self.prev_p12 == 1:
                            self.prev_p12 = F(-1)
                        skip = not t < self.prev_p12
                elif abs(st.prev_p4m - p4m) >= 4:
                    if st.prev_p5 < 20:
                        if p4m < st.prev_p4m:
                            width = F(width - F(1.5))
                    elif st.prev_p4m < p4m or st.prev_p9m == 0:
                        width = F(width - F(1.5))
            if not skip:
                frac = amod(p[5], 1)
                if frac > F(0.9):
                    frac = F(F(0.9) - frac)
                left_acc = F(frac * F(10) + (width + left_acc))
                if n3 < 0:
                    left_acc = F(left_acc - shift)
        p[4] = amod(p[4], 100)
        st.ledger_cur = 1 if p[4] > 12 else 0
        if p[4] < 2:
            st.ledger_cur = -1
        if st.ledger_cur == 0 or st.ledger_cur != self.ledger:
            self.ledger = st.ledger_cur
        elif left_acc < F(1.3):
            left_acc = F(1.3)
        if 9 < p6i < 20:
            left_acc = F(left_acc + F(1.7))
            right_acc = F(right_acc + F(1.8))
        return left_acc, right_acc

    def other(self, k, it, c, length):
        st, p, n = self.st, self.st.p, self.n
        left = right = 0.0
        if c == 14:
            p[8] = F(par(it, 17) / self.scale) if length > 16 else 1.0
            left, right = barline_widths(p, length, self.prev_code)
        elif c == 2:
            left, right = rest_widths(it, p)
        elif c == 3:
            right = F(6.5) if p[4] >= 100 else F(7.5)
            st.small_clef = p[4] >= 100
            if self.prev_code == 14:
                self.shorten_right()
            else:
                if self.prev_code == 1:
                    left = F(1)
                if n != k:
                    if len(self.cols) == 1:
                        self.shorten_right()
                    elif self.scale * right <= self.xs[k + 1] - p[3]:
                        t = self.rights[-1]
                        if p[3] - self.xs[k - 1] < t:
                            t = F(t + self.xs[k - 1])
                            if t < self.xs[k + 1] - F(0.2):
                                p[3] = t
                                self.item(self.who[k])[2] = t
        elif c == 4:
            left = F(0.2) if self.prev_code == 14 else F(1.3)
            if self.prev_code == 3 or self.prev_code > 16:
                left = 0.0
            right = F(1.8)
            if length >= 15:
                left, right = self.p15_shift(it, left, right)
        elif c == 10:
            left, right = F(0.2), (F(p[6] * F(4)) if p[6] != 0 else F(4))
            left, right = self.p15_shift(it, left, right)
        elif c == 17:
            left, right = key_widths(p, self.prev_code)
        else:
            left, right = other_widths(it, self.prev_code, self.rights)
            if n == k:
                right = F(right - F(2.5))
            else:
                f = F((1 - self.scale) / 2 + self.scale) if self.scale < 1 else self.scale
                if f < 1:
                    right = F(f * right)
        return left, right

    def shorten_right(self):
        t = self.rights[-1]
        if t >= 3:
            t = F(t - 1)
        if t < 3:
            t = F(2)
        self.rights[-1] = t

    def p15_shift(self, it, left, right):
        t = F(par(it, 15) / self.scale)
        return F(left - t), F(t + right)

    def add_to_column(self, c, left, right):
        """LAB_004BE9B2"""
        x = self.st.p[3]
        if abs(x - self.cols[-1]) >= F(0.03):
            self.cols.append(x)
            self.rights.append(0.0)
            self.lefts.append(0.0)
        if c == 18 or self.lefts[-1] < left:
            self.lefts[-1] = left
        if self.rights[-1] < right:
            self.rights[-1] = right
        if c < 3 or c == 4:
            extra = 0.0
            scale = self.scale
            if self.prev_code == 14:
                extra = F(AFTER_BARLINE / scale - F(2.5))
            if self.prev_code == 17:
                extra = F(AFTER_KEY / scale - F(2.8))
            if self.prev_code == 18:
                extra = F(AFTER_METER / scale - F(3.7))
            if self.prev_code == 3 and not self.st.small_clef:
                extra = F(AFTER_CLEF / scale - F(1.8))
            if extra > 0:
                self.lefts[-1] = F(extra + self.lefts[-1])
        self.prev_code = c


# ---------------------------------------------------------------- merge and distribute (0x4B6F4A, 0x4B5DB0)

def split_gap(out_x, out_w, cut, other, widths, idx, least):
    """0x4B7468: the part of a gap's need up to `cut`, proportional, at least `least`."""
    prev = out_x[-1]
    part = F(((cut - prev) * widths[idx]) / (other - prev))
    if part < least:
        part = least
    out_w.append(part)
    widths[idx] = F(widths[idx] - part)
    out_x.append(cut)


def merge_columns(mx, mw, cx, cw, x_left, x_right):
    """The two-pointer merge of 0x4B6F4A; mx/cx 0-based with the box start at index 0."""
    out_x, out_w = [x_left], []
    stop = F(x_right - F(0.2))
    i = j = 0
    while True:
        ac = cx[i + 1]
        advanced_staff = False
        while True:
            a8 = mx[j + 1]
            if not abs(ac - a8) > F(0.1):
                break
            if ac < a8:
                split_gap(out_x, out_w, ac, a8, mw, j, cw[i])
                advanced_staff = True
                break
            split_gap(out_x, out_w, a8, ac, cw, i, mw[j])
            j += 1
        if not advanced_staff:
            if a8 < ac:
                ac = a8
            w = mw[j] if not mw[j] < cw[i] else cw[i]
            out_w.append(w)
            out_x.append(ac)
            if stop <= ac:
                return out_x, out_w
            j += 1
        i += 1


@dataclass
class Distributor:
    """0x4B5DB0 with 0x4B63CD (stretch inside a gap), 0x4B6593 (shift from x) and 0x4B6365."""
    items: list[list[float]]
    sel: Selection
    right_limit: float
    floor: float = -9999.0
    amount: float = 0.0

    def value(self, ref):
        i, k = ref
        return self.items[i - 1][k - 1]

    def put(self, ref, v):
        i, k = ref
        self.items[i - 1][k - 1] = v

    def stretch(self, a: float, b: float):
        span = F(b - a)
        if span == 0:
            return
        factor = F(F(self.amount + span) / span)
        if factor <= F(0.2):
            factor = 1.0
        for n, ref in enumerate(self.sel.refs):
            if ref is not None and a <= self.value(ref) <= b:
                v = F((self.value(ref) - a) * factor + a)
                self.put(ref, max(v, self.floor) if v < self.floor else v)
                self.sel.refs[n] = None
        self.floor = F(a + F(0.2))

    def shift_from(self, x: float):
        for ref in self.sel.refs:
            if ref is not None and x <= self.value(ref):
                self.put(ref, F(self.amount + self.value(ref)))

    def run(self, n: int, x_left: float, x_right: float, X: list[float], W: list[float]):
        gaps = n - 1
        need = 0.0
        for w in W[:gaps]:
            need = F(need + w)
        avail = F(x_right - x_left)
        if avail < need:
            cut = F((need - avail) / float(gaps))
            W[:gaps] = [F(w - cut) for w in W[:gaps]]
        free = [F((X[k + 1] - X[k]) - W[k]) for k in range(gaps)]
        plus = minus = 0.0
        for f in free:
            if f >= 0:
                plus = F(f + plus)
            else:
                minus = F(minus - f)
        if minus == 0 or plus == 0:
            return
        ratio = F(minus / plus)
        self.floor = -9999.0
        for i in range(1, n):
            amount = F(-free[i - 1])
            if amount < 0:
                amount = F(ratio * amount)
            self.amount = amount
            if amount == 0:
                continue
            if amount < 0:
                self.stretch(X[i - 1], X[i])
                self.shift_from(X[i])
                X[i:n] = [F(amount + x) for x in X[i:n]]
            else:
                old = X[i]
                self.shift_from(old)
                X[i:n] = [F(amount + x) for x in X[i:n]]
                self.stretch(X[i - 1], old)
        for it in self.items:
            if len(it) >= 3:
                if abs(it[2]) < F(0.01):
                    it[2] = 0.0
                if abs(self.right_limit - it[2]) < F(0.01):
                    it[2] = self.right_limit


def justify(items, lo: int, hi: int, x_left: float, x_right: float, right: float = 200.0):
    """0x4B6F4A"""
    sel = select_box(items, lo, hi, x_left, x_right, right)
    st = JustifyState()
    words = item_words(items)
    steps = staff_steps(items)
    mx: list[float] = []
    mw: list[float] = []
    for s in range(lo, hi + 1):
        cols = StaffColumns(items, st, words, lo, steps.get(s, 25.0), s, x_left, x_right).run()
        if cols is None:
            continue
        cx, cw = cols.x, cols.need
        if F(0.1) < x_right - cx[-1]:
            cx.append(x_right)
            cw.append(0.0)
        if not mx:
            mx, mw = list(cx), list(cw)
        else:
            mx, mw = merge_columns(mx, mw, cx, cw, x_left, x_right)
    if not mx:
        return
    start = 1 if len(mx) > 1 and mx[1] - mx[0] <= F(0.1) else 0
    X, W = mx[start:], mw[start:]
    Distributor(items, sel, right).run(len(X), x_left, x_right, X, W)


# ---------------------------------------------------------------- LI, J, LJ (0x4B80B7)

def layout_items(items, lo: int, hi: int, command: str = "LJ", right: float = 200.0,
                 box: tuple[float, float] = (0.0, 200.0)) -> list[list[float]]:
    """The whole command after the answer 'lo count' and yes to "Source Box O.K.?"."""
    items, hi = prepare([list(it) for it in items], lo, hi, right, box)
    if hi is None:
        return items
    x_left, x_right = box
    if command[0] == "L":
        run = Lineup(items, lo, hi, right, staff_steps(items))
        try:
            run.run()
        except LineupError as err:
            err.items = items
            raise
        x_left, x_right, lo = run.x_left, run.x_right, run.lo
    if command in ("LJ", "J"):
        justify(items, lo, hi, x_left, x_right, right)
    for it in items:
        if lo <= staff(it) <= hi and code(it) == 2 and par(it, 5) <= -2 and x_left <= xpos(it) <= box[1]:
            it.extend([0.0] * (9 - len(it)))
            it[8] = -1.0
    return items


def decorate(rng: random.Random, it: list[float]) -> list[float]:
    """Give a note or rest of rich_staff the parameters justify looks at."""
    if it[0] == 1:
        it = (it + [0.0] * 10)[:10]
        it[4] = rng.choice([1, 2]) * 10 + rng.choice([0, 0, 0, 1, 2, 3, 4, 5, 9])
        if rng.random() < 0.15:
            it[5] = rng.choice([1, 2, 3, 12])
        if rng.random() < 0.2:
            it[8] = rng.choice([1, 2, 11, 1.3])
        if rng.random() < 0.15:
            it[9] = rng.choice([10, 20, 110, -3, 4])
        if rng.random() < 0.05:
            it[3] = it[3] + (100 if it[3] >= 0 else -100)
        while it[-1] == 0 and len(it) > 7:
            it.pop()
    elif it[0] == 2 and rng.random() < 0.2:
        it = (it + [0.0] * 10)[:10]
        it[9] = rng.choice([2, -2])
    elif it[0] == 14 and rng.random() < 0.2:
        it = (it + [0.0] * 5)[:5]
        it[4] = rng.choice([1, 2, 3, 4, 5, 6])
    return it


def dense_system(rng: random.Random, max_staves: int) -> tuple[list[list[float]], int]:
    """Rich staves with accidentals, dots, shifted heads, cue notes, barline types, and up to 6 measures."""
    staves = rng.randint(1, max_staves)
    measures = rng.randint(2, 6)
    keep_clefs = rng.random() < 0.3
    items = [decorate(rng, it) for s in range(1, staves + 1) for it in rich_staff(rng, s, measures)
             if keep_clefs or not (it[0] == 3 and it[2] > 3)]
    for s in range(1, staves + 1):
        if rng.random() < 0.3:
            items.append([10, s, rng.uniform(20, 180), 12, 3] + [0.0] * 10 + [1.0])
    return [[F(float(v)) for v in it] for it in items], staves


def compare(items, staves, command: str) -> str | None:
    from layoutlab import run_layout
    error = None
    try:
        model = layout_items(items, 1, staves, command)
    except LineupError as err:
        model, error = getattr(err, "items", None), err
    except NotImplementedError as err:
        return f"skipped: {err}"
    engine, _ = run_layout(items, [command, f"1 {staves}"], digits=None)
    if model == engine:
        return None
    if model is None:
        return f"error: {error}"
    diff = [(k, a, b) for k, (a, b) in enumerate(zip(model, engine)) if a != b]
    return f"{len(diff)} items differ, first {diff[:2]}"


def main(cases: int = 50, max_staves: int = 3, command: str = "LJ", dense: int = 0):
    rng = random.Random(11 + dense)
    good = 0
    for case in range(cases):
        items, staves = (dense_system if dense else rich_system)(rng, max_staves)
        problem = compare(items, staves, command)
        if problem is None:
            good += 1
        else:
            print(f"case {case} ({staves} staves): {problem}")
    print(f"{good}/{cases} systems identical after {command}")


if __name__ == "__main__":
    main(*(int(a) if a.isdigit() else a for a in sys.argv[1:]))
