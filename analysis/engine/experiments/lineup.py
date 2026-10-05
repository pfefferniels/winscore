"""Reference model of SCORE's lineup (LI, and the first half of LJ), ported from WScore.exe
routine by routine with the engine's f32 stores, and its check against the oracle.

    python lineup.py [cases] [max_staves] [rich]   (default 100 cases, 1..3 staves, plain lines)

Items are lists of parameter values P1..Pn (f32) in file order. Item indices are 1-based
inside the model, as in the engine. layout.md describes the algorithm; each function names
the routine it ports. Comparisons are written as the engine evaluates them (extended
precision, no rounding of the compared expression).
"""
from __future__ import annotations

import random
import sys
from dataclasses import dataclass, field

from grace import GracePass
from staves import f32 as F, trunc

EXPONENT = F(0.5849624872207642)      # f32 at 0x7926DC: log2(1.5)
BARLINE, BARLINE_P12, CLEF, START_CLEF, KEY, METER = -14.0, -140.0, -3.0, -15.0, -17.0, -18.0
STAFF = [8, 1, 0, 0, 1]
LOOP_LIMIT = 100_000


class LineupError(Exception):
    """The engine gives up (unequal staff totals, unalignable rhythm); items may be partly changed."""


def nint(x: float) -> int:
    """ANINT 0x5FF381: x +- 0.5 in double, then truncate."""
    return trunc(x + 0.5) if x >= 0 else trunc(x - 0.5)


def code(it): return trunc(it[0])
def staff(it): return trunc(it[1])
def xpos(it): return it[2] if len(it) > 2 else 0.0
def par(it, k): return it[k - 1] if len(it) >= k else 0.0


def is_segment_code(c: int) -> bool:
    """Codes whose P3 is moved segment by segment: notes, rests, clefs, barlines, keys, meters."""
    return not (3 < c < 17 and c != 14)


# ---------------------------------------------------------------- sort 0x4F7808 (mode 'X')

def sort_items(items: list[list[float]]) -> list[list[float]]:
    """P3 rounded to 1/100; stable order by staff, P3, notes and rests before other codes, then P4."""
    for it in items:
        if len(it) > 2:
            it[2] = F(F(float(nint(it[2] * 100))) / 100)

    def key(it):
        primary = trunc(trunc(it[1]) * 1e6 + xpos(it) * 1000) + (1 if it[0] > 2 else 0)
        secondary = 0.0 if len(it) < 4 else F(it[3] + 5) if it[0] == 2 else it[3]
        if secondary >= 900:
            raise LineupError("P4 >= 900: the engine's selection sort would repeat the last item")
        return primary, secondary
    return sorted(items, key=key)


# ---------------------------------------------------------------- per-staff events 0x534C40

def shortest_open_value(values: list[float]) -> tuple[float, list[float]]:
    """0x53572C: an event lasts as long as its shortest open value; the others carry over, reduced by it."""
    if len(values) < 2:
        return values[0], []
    vals = list(values)
    least, at = vals[0], 0
    for k, v in enumerate(vals[1:], 1):
        if v <= least:
            least, at = v, k
    if at:
        vals[at], vals[0] = vals[0], least
    return least, [r for r in (F(v - least) for v in vals[1:]) if r > F(0.001)]


def p14_or_p15(it) -> bool:
    """0x5358E5"""
    n = len(it)
    return n >= 14 and (it[13] != 0 or (n >= 15 and it[14] != 0))


def meter_off_staff(it) -> bool:
    """0x535693: a meter shifted by more than 2 (P4 times P7) is no lineup event."""
    if code(it) != 18 or len(it) <= 3:
        return False
    scale = par(it, 7) if len(it) > 6 and par(it, 7) != 0 else 1.0
    return abs(scale * it[3]) > 2


@dataclass
class StaffEvents:
    positions: list[float]
    entries: list[float]          # durations (P7 units) > 0, markers -code < 0
    total: float
    saw_long: bool = False        # a note or rest with P7 >= 64, left to 0x4C5AD8


def first_event_item(items, start: int, s: int):
    """Phase 1 of 0x534C40: (first relevant item of staff s or 0, first item of the next staff, scan end)."""
    n = len(items)
    i, first, next_start = start - 1, 0, start
    if not i < n:
        return 0, next_start, i
    while True:
        i += 1
        it = items[i - 1]
        if first == 0:
            x = xpos(it)
            if not (x > F(200.05) or staff(it) < s):
                if abs(x) <= F(0.01):
                    if len(it) > 2:
                        it[2] = 0.0
                    x = 0.0
                c = code(it)
                if not ((3 < c < 17 and c != 14) or x < 0):
                    if staff(it) != s:
                        return 0, next_start, i
                    if not ((c == 14 and len(it) > 4 and 7 < trunc(it[4]) < 11)
                            or (c > 16 and ((meter_off_staff(it) and c == 18) or p14_or_p15(it)))):
                        first = i
            if first == 0:
                if i < n:
                    continue
                return 0, next_start, i
        elif s < staff(it):
            return first, i, i
        if n <= i:
            return first, next_start, i + 1


def staff_events(items, start: int, s: int) -> tuple[int, StaffEvents]:
    """0x534C40 for staff s, scanning from item `start`; returns the next staff's first item and the events."""
    first, next_start, i = first_event_item(items, start, s)
    none = StaffEvents([], [], 0.0)
    if first == 0:
        return next_start, none
    last = 0
    while first < i:
        i -= 1
        it = items[i - 1]
        c = code(it)
        if c > 16 or c < 3 or c == 14:
            last = i
            if abs(F(200) - xpos(it)) <= F(0.01):
                it[2] = 200.0
            break
    if last == 0:
        return next_start, none

    positions: list[float] = []
    durations: list[float] = []
    values: list[float] = []
    last_x, saw_long = -990.0, False

    def new_event(v, x):
        nonlocal values, last_x
        if positions:
            d, values = shortest_open_value(values)
            durations.append(d)
        if v == 99 and values:
            values = []
        positions.append(x)
        last_x = x

    for it in items[first - 1:last]:
        x = xpos(it)
        if x > F(200.05):
            continue
        c = code(it)
        if c < 3:
            if len(it) > 6 and it[6] > 0:
                v = it[6]
                if v >= 64:
                    saw_long = True
                    continue
                if abs(x - last_x) > F(0.1):
                    new_event(v, x)
                values.append(v)
        elif (c > 16 or c == 14 or c == 3) and last_x != x:
            if (c == 18 and meter_off_staff(it)) or (c >= 17 and p14_or_p15(it)):
                continue
            if c == 14 and len(it) > 11 and it[11] > 0:
                c = 140
            if c != 3 or len(it) < 5 or it[4] < 44:
                new_event(float(-c), x)
                values.append(float(-c))
    if positions:
        d, values = shortest_open_value(values)
        durations.append(d)

    acc, total = 0.0, 0.0
    for k, d in enumerate(durations):
        if d > 0:
            acc = F(d + acc)
            frac = F(acc - trunc(acc))
            rest = F(1 - frac)
            if frac != 0 and (frac <= F(0.005) or rest <= F(0.005)):
                if frac <= F(0.005):
                    acc, d = F(acc - frac), F(d - frac)
                else:
                    acc, d = F(rest + acc), F(rest + d)
                durations[k] = d
        if d > 0:
            total = F(d + total)
    if total == 0:
        return next_start, StaffEvents([], [], 0.0, saw_long)
    return next_start, StaffEvents(positions, durations, total, saw_long)


# ---------------------------------------------------------------- merging staves (0x4C9510)

def at(values: list[float], k: int) -> float:
    """1-based read; past the end the engine finds the zero it wrote after the list."""
    return values[k - 1] if 1 <= k <= len(values) else 0.0


def drop_repeated_barlines(entries):
    """0x4CB518"""
    out, prev = [], 0.0
    for e in entries:
        if e != BARLINE or e != prev:
            out.append(e)
            prev = e
    return out


def merge_markers(master: list[float], entries: list[float]) -> list[float]:
    """First merge of 0x4C9510: the markers of both lists in order, the master's durations kept."""
    M, S = master, entries
    cm, n = len(M), len(S)
    out: list[float] = []
    last = 0.0

    def emit(v):                                       # 0x4CB5F5
        nonlocal last
        if v != 0 and (v > 0 or last <= 0 or v == BARLINE):
            out.append(v)
            last = v

    i = j = 1
    for _ in range(LOOP_LIMIT):
        v, s = at(M, i), at(S, j)
        lookahead_emit = False
        if s == BARLINE and not (cm == i or v >= 0 or v == BARLINE):
            for k in range(i + 1, cm + 1):
                if at(M, k) >= 0:
                    break
                if at(M, k) == BARLINE:
                    last = 0.0
                    lookahead_emit = True
                    break
        if not lookahead_emit:
            if v == 0:
                v = s
            if v == KEY and i < cm and at(M, i + 1) == BARLINE:
                last = v
        if lookahead_emit or s == 0 or v == s:
            emit(v)
        elif v <= 0:
            take_staff = False
            if s <= 0:
                if v < s:
                    take_staff = not (s == BARLINE and last < 0)
                elif v == BARLINE and last < 0:
                    take_staff = True
            if take_staff:
                i -= 1
                v = s
            else:
                j -= 1
            emit(v)
        elif s < 0:
            i -= 1
            emit(s)
        else:
            accS, accM = F(s + 0.0), 0.0
            while True:
                accM = F(v + accM)
                emit(v)
                d = F(accM - accS)
                done = False
                while d > F(0.001):
                    while True:
                        j2 = j + 1
                        if n < j2:
                            return drop_repeated_barlines(out)
                        s = at(S, j2)
                        if s > 0:
                            break
                        if d <= F(0.02):
                            done = True
                            break
                        v, j = s, j2
                        emit(v)
                    if done:
                        break
                    accS, j = F(s + accS), j2
                    d = F(accM - accS)
                if done or F(-0.001) <= d:
                    break
                while True:
                    i2 = i + 1
                    if cm < i2:
                        return drop_repeated_barlines(out)
                    v = at(M, i2)
                    if v > 0:
                        break
                    if F(-0.02) <= d:
                        done = True
                        break
                    i = i2
                    emit(v)
                if done:
                    break
                i = i2
        if n <= j and cm <= i:
            return drop_repeated_barlines(out)
        if i < cm:
            i += 1
        if j < n:
            j += 1
    raise LineupError("marker merge does not terminate")


@dataclass
class DurationMerge:
    """0x4CB78B: split master durations wherever the new staff has an onset."""
    M: list[float]
    S: list[float]
    out: list[float] = field(default_factory=list)
    i: int = 0
    j: int = 0
    m: float = 0.0
    s: float = 0.0
    accM: float = 0.0
    accS: float = 0.0

    def next_master(self, stop: bool):               # 0x4CB6BF
        while True:
            self.i += 1
            self.m = at(self.M, self.i)
            if self.m > 0:
                self.accM = F(self.m + self.accM)
                return
            self.out.append(self.m)
            if stop:
                return

    def next_staff(self):                            # 0x4CB74B
        self.j += 1
        self.s = at(self.S, self.j)
        self.accS = F(self.s + self.accS)

    def apart(self, limit: float) -> bool:
        return abs(self.accM - self.accS) >= limit

    def run(self) -> list[float]:
        tol = F(0.004)
        for _ in range(LOOP_LIMIT):
            self.accM = self.accS = 0.0
            self.next_master(True)
            if self.m >= 0:
                self.next_staff()
                finished = False
                while abs(self.accM - self.accS) > F(0.01):
                    aligned = False
                    if self.s <= self.m:
                        while True:
                            self.out.append(self.s)
                            if not self.apart(F(0.01)):
                                finished = True
                                break
                            if self.accS <= self.accM:
                                self.next_staff()
                                if self.m <= self.s + tol:
                                    self.m = F(self.accM - self.accS + self.s)
                                    aligned = True
                                    break
                            if self.accS - tol <= self.accM:
                                continue
                            self.next_master(False)
                            if not self.s + tol < self.m:
                                break
                        if finished:
                            break
                        if not aligned:
                            self.i -= 1
                            self.m = F(((self.accM - self.m) - self.accS) + self.s)
                    else:
                        while True:
                            self.out.append(self.m)
                            if not self.apart(F(0.01)):
                                finished = True
                                break
                            if self.accM <= self.accS:
                                self.next_master(False)
                                if self.s <= self.m + tol:
                                    self.s = F(self.accS - self.accM + self.m)
                                    aligned = True
                                    break
                            if self.accM - tol <= self.accS:
                                continue
                            self.next_staff()
                            if not self.m + tol < self.s:
                                break
                        if finished:
                            break
                        if not aligned:
                            self.j -= 1
                            self.s = F(((self.accS - self.s) - self.accM) + self.m)
                    self.accS, self.accM = self.s, self.m
                if not finished:
                    self.out.append(self.m)
            if len(self.M) <= self.i:
                return self.out
        raise LineupError("duration merge does not terminate")


# ---------------------------------------------------------------- spacing 0x4CC470

def marker_width(e: float, following: float) -> float:
    """Fixed widths in staff-size units; `following` is the next entry (0 past the end)."""
    nxt = trunc(following)
    if e in (BARLINE, BARLINE_P12):
        if nxt < 0:
            return 1.5 if nxt in (-15, -17) else 1.0 if nxt == -18 else 3.5
        return 3.5
    if e == START_CLEF:
        if nxt < -16:
            return 6.0 if nxt == -18 else 8.0
        return 10.0
    if e == METER and nxt == -14:
        return 4.6
    return 3.5


def spacing(entries: list[float], size: float, left: float, right: float) -> list[float]:
    """Positions: durations get d**log2(1.5) of a common unit, markers fixed widths, the last entry none."""
    n = len(entries)
    widths, fixed, total = [], 0.0, 0.0
    for k, e in enumerate(entries):
        if e > 0:
            w = F(e ** EXPONENT)
            total = F(w + total)
        elif k == n - 1:
            w = 0.0
        else:
            w = marker_width(e, entries[k + 1])
            fixed = F(w + fixed)
        widths.append(w)
    unit = F((F(right - left) - size * fixed) / total)      # the difference is stored first (0x89FCDC)
    out, x = [], left
    for e, w in zip(entries, widths):
        out.append(x)
        x = F(F((size if e <= 0 else unit) * w) + x)
    out.append(x)
    return out


# ---------------------------------------------------------------- lineup 0x4C9510 and 0x4C8290

@dataclass
class Anchor:
    staff: int
    x: float
    code: int
    item: int | None              # None: the virtual anchor at the right limit


@dataclass
class Lineup:
    items: list[list[float]]
    lo: int
    hi: int
    right: float = 200.0
    steps: dict[int, float] = field(default_factory=dict)
    anchors: list[Anchor] = field(default_factory=list)
    saved_e: list[float] = field(default_factory=list)     # all staves' entries, as 0x1E9F4F4
    saved_x: list[float] = field(default_factory=list)     # and positions, as 0x1E9D5B4
    offset: dict[int, int] = field(default_factory=dict)   # staff -> 0-based start in saved_e
    master: list[float] = field(default_factory=list)
    new_x: list[float] = field(default_factory=list)
    x_left: float = 9999.0
    x_right: float = 200.0
    saw_long: bool = False

    def item(self, i):
        return self.items[i - 1]

    def step(self, s):
        return self.steps.get(s, 25.0)

    def collect_anchors(self):
        """Anchors for the codes moved by interpolation (0x4CB010), sorted by staff and x."""
        raw: list[Anchor] = []
        current = 0
        for i, it in enumerate(self.items, 1):
            s = staff(it)
            if s > self.hi:
                break
            c, x = code(it), xpos(it)
            if not (x <= self.right + F(0.05) and self.lo <= s and (c > 16 or c == 14 or c < 4)):
                continue
            if raw and s == raw[-1].staff and x == raw[-1].x:
                continue
            if s != current:
                if current and abs(raw[-1].x - self.right) >= F(0.01):
                    raw.append(Anchor(current, self.right, -14, None))
                current = s
            raw.append(Anchor(s, x, c, i))
            if c == 14 and len(it) > 3:
                raw += [Anchor(t, x, c, i) for t in range(s + 1, s + trunc(F(it[3] - 1)) + 1)]
        if raw and abs(raw[-1].x - self.right) >= F(0.01):
            raw.append(Anchor(current, self.right, -14, None))
        self.anchors = sorted(raw, key=lambda a: F(F(float(a.staff * 1000)) + a.x))

    def run(self):
        self.collect_anchors()
        for it in self.items:
            if code(it) == 8 and self.lo <= staff(it) <= self.hi and len(it) > 5 and it[5] > self.right:
                it[5] = self.right
        self.x_left, self.x_right = 9999.0, self.right
        start, total_before = 1, None
        for s in range(self.lo, self.hi + 1):
            start, ev = staff_events(self.items, start, s)
            self.saw_long |= ev.saw_long
            self.offset[s] = len(self.saved_x)
            if ev.total == 0:
                if s == self.lo:
                    self.lo += 1
                    if self.lo > self.hi:
                        raise LineupError("no staff with notes")
                continue
            entries, positions = self.normalize(ev)
            off = self.offset[s]
            self.saved_e[off:] = entries + [0.0]
            self.saved_x[off:] = positions
            if total_before is None:
                total_before = ev.total
                self.master = drop_repeated_barlines(entries)
                self.x_left, self.x_right = positions[0], positions[-1]
                continue
            self.x_left = min(self.x_left, positions[0])
            if entries[-1] == BARLINE and self.x_right < positions[-1]:
                self.x_right = positions[-1]
            if abs(ev.total - total_before) > F(0.007):
                raise LineupError(f"staff {s} has {ev.total:.3f} beats, the one before {total_before:.3f}")
            self.master = merge_markers(self.master, entries)
            self.master = DurationMerge(self.master, [e for e in entries if e > 0]).run()
        self.offset[self.hi + 1] = len(self.saved_x)
        self.new_x = spacing(self.master, F(self.step(self.lo) / 25), self.x_left, self.x_right)
        self.apply()
        if self.saw_long:
            GracePass(self.items, self.lo, self.hi, self.right, self.steps).run()
        self.interpolate_others()

    def normalize(self, ev: StaffEvents) -> tuple[list[float], list[float]]:
        """-140 to -14, a closing barline if missing, durations times 4, the first clef -15, later clefs dropped."""
        entries = [BARLINE if e == BARLINE_P12 else e for e in ev.entries]
        positions = list(ev.positions)
        if trunc(entries[-1]) != -14:
            end = self.x_right
            if entries[-1] < 0:
                staff_item = next((it for it in self.items if code(it) == 8 and staff(it) == self.lo), None)
                if staff_item is not None and len(staff_item) > 5:
                    end = staff_item[5]
                if staff_item is None or end == 0:
                    end = self.right
            entries.append(BARLINE)
            positions.append(end)
        out_e, out_x, seen = [], [], False
        for e, x in zip(entries, positions):
            if e > 0:
                e, seen = F(e * 4), True
            elif e == CLEF:
                if seen:
                    continue
                e, seen = START_CLEF, True
            elif e != BARLINE:
                seen = True
            out_e.append(e)
            out_x.append(x)
        return out_e, out_x

    def apply(self):
        """0x4C8290: map every staff onto the new positions, then place the clefs inside the line."""
        for it in self.items:
            if code(it) == 8 and self.lo <= staff(it) <= self.hi:
                it[1] = F(-it[1])
        threshold = next((F(xpos(it) - 2) if code(it) < 3 else F(xpos(it) + 2)
                          for it in self.items if self.lo <= staff(it) <= self.hi and code(it) <= 3), None)
        if threshold is None:
            return
        for s in range(self.lo, self.hi + 1):
            if self.offset.get(s) == self.offset.get(s + 1):
                continue
            if not self.map_staff(s):
                return
        self.place_clefs(threshold)

    def align(self, s: int):
        """0x4CC8A9: the staff's events against the master list; master markers it lacks get midpoints."""
        off, M = self.offset[s], self.master
        cm = len(M)
        s_at = lambda j: self.saved_e[off + j - 1] if 0 <= off + j - 1 < len(self.saved_e) else 0.0
        x_at = lambda j: self.saved_x[off + j - 1] if 0 <= off + j - 1 < len(self.saved_x) else 0.0
        first = s_at(1)
        start = next((k for k in range(1, cm + 1) if M[k - 1] > 0 or M[k - 1] == first), None)
        if start is None:
            return None
        out_e: list[float] = []
        out_x: list[float] = []
        mi, j = start - 1, 1
        s_cur = s_at(1)
        accM = accS = 0.0
        for _ in range(LOOP_LIMIT):
            if mi == cm:
                return start, out_e, out_x
            mi += 1
            m = M[mi - 1]
            if m >= 0:
                accM = F(m + accM)
                while True:
                    if s_cur > 0:
                        accS = F(s_cur + accS)
                        out_e.append(s_cur)
                        out_x.append(x_at(j))
                        d = F(accM - accS)
                        while not (abs(d) <= F(0.002) or d > 0):
                            while True:
                                if mi == cm:
                                    return start, out_e, out_x
                                mi += 1
                                m = M[mi - 1]
                                if not m < 0:
                                    break
                            accM = F(m + accM)
                            d = F(accM - accS)
                        if abs(d) <= F(0.002):
                            break
                    j += 1
                    s_cur = s_at(j)
                    if j > len(self.saved_e) + 2:
                        raise LineupError(f"staff {s}: events run out while aligning")
                accM = accS = 0.0
                j += 1
                s_cur = s_at(j)
            else:
                while s_cur != m and not (s_cur > 0 or s_cur != START_CLEF):
                    j += 1
                    s_cur = s_at(j)
                if s_cur == m:
                    out_e.append(s_cur)
                    out_x.append(x_at(j))
                    accM = accS = 0.0
                    j += 1
                    s_cur = s_at(j)
                else:
                    out_e.append(m)
                    out_x.append(F((x_at(j) - x_at(j - 1)) / 2 + x_at(j - 1)))
        raise LineupError("alignment does not terminate")

    def map_staff(self, s: int) -> bool:
        found = self.align(s)
        if found is None:
            return False
        ms, al_e, al_x = found
        M, X, cm = self.master, self.new_x, len(self.master)
        new_prev, master_prev = X[ms - 1], M[ms - 1]
        park = F(new_prev + 800)
        staff_prev, old_prev = al_e[0], al_x[0]
        proportional = False
        k = 1
        moved: set[int] = set()
        m_cur = new_master = 0.0
        while True:
            if not proportional:
                if cm < ms:
                    break
                ms += 1
                m_cur, new_master = at(M, ms), at(X, ms)
            if len(al_e) <= k:
                break
            k += 1
            s_cur, old_cur = al_e[k - 1], al_x[k - 1]
            equal = staff_prev == master_prev
            if not equal:
                d = F(master_prev - staff_prev)
                equal = abs(d) <= F(0.005)
                if not equal and d < 0:
                    while True:
                        while m_cur <= 0:
                            ms += 1
                            m_cur, new_master = at(M, ms), at(X, ms)
                        master_prev = F(m_cur + master_prev)
                        d = F(master_prev - staff_prev)
                        ms += 1
                        m_cur, new_master = at(M, ms), at(X, ms)
                        if abs(d) <= F(0.005):
                            equal = True
                            break
                        if m_cur <= 0:
                            raise LineupError(f"staff {s}: rhythm cannot be aligned")
                        if d >= 0:
                            break
                if not equal:
                    proportional = True
                    new_cur = F((new_master - new_prev) * staff_prev / master_prev + new_prev)
                    carry = d
            if equal:
                proportional = False
                new_cur, carry = new_master, m_cur
                if m_cur == s_cur:
                    pass
                elif s_cur in (BARLINE, BARLINE_P12):
                    new_cur = F((new_master - new_prev) / 2 + new_prev)
                    carry = s_cur
                    ms -= 1
                elif m_cur in (BARLINE, BARLINE_P12):
                    old_cur = F((old_cur - old_prev) / 2 + old_prev)
                    s_cur = m_cur
                    k -= 1
            if old_prev < old_cur:
                self.move_segment(s, old_prev, old_cur, new_prev, new_cur, moved)
                new_prev, master_prev, staff_prev, old_prev = new_cur, carry, s_cur, old_cur
        for i in moved:
            it = self.item(i)
            if it[2] >= park:
                it[2] = F(it[2] - 1000)
        return True

    def move_segment(self, s, old0, old1, new0, new1, moved: set[int]):
        """0x49B1D8 + 0x49BB13 (mode -1): P3 in [old0, old1] maps linearly onto [new0, new1], parked at +1000."""
        lo = F(old0 - F(0.001))
        hi = F((old1 if old1 != 0 else 200.0) + F(0.001))
        factor = F((new1 - new0) / (old1 - old0))
        offset = F(F(new0 + 1000) - factor * old0)
        for i, it in enumerate(self.items, 1):
            if staff(it) == s and is_segment_code(code(it)) and lo <= xpos(it) <= hi:
                v = F(factor * it[2] + offset)
                it[2] = 0.0 if abs(v) < F(0.005) else v
                moved.add(i)

    def place_clefs(self, threshold: float):
        """End of 0x4C8290: a clef after the start goes 0.3 staff steps before the next note or barline."""
        clefs, bars, last_bar = [], [], 0.0
        for i, it in enumerate(self.items, 1):
            if xpos(it) <= self.right + F(0.05) and self.lo <= staff(it) <= self.hi:
                if code(it) == 3 and threshold <= xpos(it):
                    clefs.append(i)
                elif code(it) == 14 and threshold <= xpos(it):
                    bars.append(xpos(it))
                    last_bar = max(last_bar, xpos(it))
            if staff(it) < 0:
                it[1] = F(-it[1])
        for i in clefs:
            it = self.item(i)
            gap = F(self.step(staff(it)) * F(0.3) + 1)
            target = self.clef_target(i, it[2], staff(it), bars, last_bar)
            k = i
            while True:
                k -= 1
                prev = self.item(k)[2]
                if target - prev > gap:
                    new = F(target - gap + 1)
                    break
                if not 2 < code(self.item(k)) < 17:
                    new = F((target - prev) / 2 + prev)
                    break
            it[2] = new

    def clef_target(self, i, x, s, bars, last_bar) -> float:
        k = i
        while True:
            k += 1
            if k > len(self.items) or staff(self.item(k)) != s:
                return last_bar
            nxt = self.item(k)
            if nxt[0] == 14:
                return nxt[2]
            if not nxt[0] > 2:
                break
        note_x = nxt[2]
        bar = next((b for b in bars if x <= b), None)
        return bar if bar is not None and bar <= note_x else note_x

    def interpolate_others(self):
        """0x4CB010: x parameters of codes 4-7, 9-13, 15, 16 follow their anchors proportionally."""
        for it in self.items:
            s, c = staff(it), code(it)
            if s > self.hi:
                break
            if not (3 < c < 17 and c not in (8, 14) and self.lo <= s):
                continue
            self.interpolate(it, 3)
            n = len(it)
            if c < 8 and n > 5 and (c != 6 or par(it, 7) >= 0):
                self.interpolate(it, 6)
            if c == 6 and n > 10:
                if it[10] > 0:
                    self.interpolate(it, 11)
                if n > 11 and it[6] > 0:
                    if it[11] > 0:
                        self.interpolate(it, 12)
                    if n > 13 and it[12] != 0:
                        if it[13] > 0:
                            self.interpolate(it, 14)
                        if n > 14 and it[14] > 0:
                            self.interpolate(it, 15)

    def interpolate(self, it, k: int):
        """0x4CB2EA"""
        x, s, A = it[k - 1], staff(it), self.anchors
        for j, a in enumerate(A[:-1]):
            if a.staff > s:
                break
            if a.staff != s:
                continue
            b = A[j + 1]
            if x < a.x:
                break
            if x <= b.x:
                part = F(x - a.x)
                if abs(part) < F(0.01):
                    part = 0.0
                span = F(b.x - a.x)
                if span >= F(0.01):
                    frac = F(part / span)
                    if abs(frac - 1) < F(0.01):
                        frac = 1.0
                    na = xpos(self.item(a.item)) if a.item else self.right
                    nb = xpos(self.item(b.item)) if b.code >= 0 and b.item else self.right
                    it[k - 1] = F((nb - na) * frac + na)


# ---------------------------------------------------------------- LI as a whole (0x4B80B7)

def staff_steps(items) -> dict[int, float]:
    out = {}
    for it in items:
        if code(it) == 8:
            size = F(par(it, 14) / F(0.889)) if par(it, 14) != 0 else par(it, 5)
            out[staff(it)] = F(25 * (size if size != 0 else 1.0))
    return out


def prepare(items, lo, hi, right, box):
    """The adjustments of 0x4B80B7 before 0x4C9510; returns the sorted items and the clamped hi."""
    items = sort_items(items)
    last_note = -9999.0
    for it in items:
        if lo <= staff(it) <= hi:
            if code(it) == 1:
                last_note = xpos(it)
                continue
            if (abs(last_note - xpos(it)) < F(0.1) and par(it, 7) < 0 and code(it) == 4
                    and len(it) > 6 and it[5] == 0):
                it[2] = F(last_note - F(0.001))
            last_note = -9999.0
    items = sort_items(items)
    top = staff(items[-1]) if items[-1] else 1
    if top < lo:
        return items, None
    hi = min(hi, top)
    start = 0
    for s in range(lo, hi + 1):
        staff_x, clef = -9999.0, None
        for k in range(start, len(items)):
            it = items[k]
            if staff(it) != s or code(it) not in (8, 3):
                continue
            if code(it) == 3:
                clef = it
                if staff_x == -9999.0:
                    continue
            else:
                staff_x = xpos(it)
                if clef is None:
                    continue
            if clef[2] < box[1] and staff_x == clef[2] and box[0] <= clef[2]:
                clef[2] = F(staff_x + F(1.5))
            start = k + 1
            break
    items = sort_items(items)
    for it in items:
        if lo <= staff(it) <= hi:
            c = code(it)
            if c == 1 and abs(right - xpos(it)) < 1:
                it[2] = F(right - 1)
            elif c == 6 and abs(right - par(it, 6)) < 1:
                it[5] = F(right - 1)
            elif c == 5 and par(it, 8) == -1 and abs(right - par(it, 6)) < 1:
                it[5] = F(right - 1)
    return items, hi


def lineup_items(items: list[list[float]], lo: int, hi: int, right: float = 200.0,
                 box: tuple[float, float] = (0.0, 200.0)) -> list[list[float]]:
    """LI on staves lo..hi, as after the answer 'lo count' and yes to "Source Box O.K.?"."""
    items, hi = prepare([list(it) for it in items], lo, hi, right, box)
    if hi is None:
        return items
    run = Lineup(items, lo, hi, right, staff_steps(items))
    try:
        run.run()
    except LineupError as err:
        err.items = items
        raise
    for it in items:
        if lo <= staff(it) <= hi and code(it) == 2 and par(it, 5) <= -2 and run.x_left <= xpos(it) <= box[1]:
            it.extend([0.0] * (9 - len(it)))
            it[8] = -1.0
    return items


# ---------------------------------------------------------------- check against the engine

def split_measure(rng: random.Random, length: float) -> list[float]:
    out, left = [], length
    while left > 0:
        d = min(left, rng.choice([0.25, 0.5, 0.5, 1, 1, 1, 1.5, 2]))
        out.append(d)
        left -= d
    return out


def random_staff(rng: random.Random, s: int, measures: list[list[float]]) -> list[list[float]]:
    items = [[8, s, 0, 0, 1], [3, s, 2, 0, 0]]
    x = 10.0
    for m, durations in enumerate(measures):
        for d in durations:
            rest = rng.random() < 0.15
            items.append([2 if rest else 1, s, round(x, 2), rng.randint(1, 10), 0 if rest else 10, 0, d])
            if not rest and rng.random() < 0.2:
                items.append([1, s, round(x, 2), rng.randint(1, 10), 10, 0, d])
            x += rng.uniform(4, 12)
        if m < len(measures) - 1:
            items.append([14, s, round(x, 2), 1])
            x += rng.uniform(3, 6)
    items.append([14, s, 200, 1])
    return items


def random_system(rng: random.Random, max_staves: int) -> tuple[list[list[float]], int]:
    staves = rng.randint(1, max_staves)
    count = rng.randint(1, 3)
    items = []
    for s in range(1, staves + 1):
        items += random_staff(rng, s, [split_measure(rng, 4.0) for _ in range(count)])
    return [[F(float(v)) for v in it] for it in items], staves


def rich_staff(rng: random.Random, s: int, measures: int) -> list[list[float]]:
    """A staff with key, meter, two voices, barlines (some with P12), key changes, inner clefs, lines and slurs."""
    items = [[8, s, 0, 0, 1], [3, s, 2, 0, 0]]
    if rng.random() < 0.6:
        items.append([17, s, 6, 0, rng.choice([-3, -1, 1, 2, 4])])
    if rng.random() < 0.6:
        items.append([18, s, 9, 0, 4, 4])
    x0, note_x = 13.0, []
    for m in range(measures):
        width = rng.uniform(30, 55)
        at_time: dict[float, float] = {}
        place = lambda t: at_time.setdefault(t, round(x0 + t / 4 * width + rng.uniform(0, 0.3), 2))
        voices = [split_measure(rng, 4.0)] + ([split_measure(rng, 4.0)] if rng.random() < 0.4 else [])
        for v, durations in enumerate(voices):
            t = 0.0
            for d in durations:
                x = place(t)
                rest = rng.random() < 0.1
                if v == 0 and not rest and rng.random() < 0.08:
                    items.append([3, s, round(x - 3, 2), 0, 0])
                items.append([2 if rest else 1, s, x, rng.randint(1, 10) - 6 * v, 0 if rest else 10, 0, d])
                note_x.append(x)
                t += d
        x0 += width + rng.uniform(3, 6)
        if m < measures - 1:
            bar = round(x0 - 2, 2)
            items.append([14, s, bar, 1] + ([0] * 7 + [1] if rng.random() < 0.2 else []))
            if rng.random() < 0.15:
                items.append([17, s, round(bar + 2, 2), 0, rng.choice([-2, 0, 3])])
                x0 += 4
    items.append([14, s, 200, 1])
    note_x.sort()
    for _ in range(rng.randint(0, 3)):
        a, b = sorted(rng.sample(note_x, 2)) if len(note_x) > 1 else (note_x[0], note_x[0])
        kind = rng.choice([4, 5, 6, 10])
        items.append([10, s, a, 12, 3] if kind == 10 else [kind, s, a, 12, 11, b])
    return items


def rich_system(rng: random.Random, max_staves: int) -> tuple[list[list[float]], int]:
    staves = rng.randint(1, max_staves)
    measures = rng.randint(1, 3)
    items = [it for s in range(1, staves + 1) for it in rich_staff(rng, s, measures)]
    return [[F(float(v)) for v in it] for it in items], staves


def compare(items, staves) -> str | None:
    from layoutlab import run_layout
    error = None
    try:
        model = lineup_items(items, 1, staves)
    except LineupError as err:
        model, error = getattr(err, "items", None), err
    except NotImplementedError as err:
        return f"skipped: {err}"
    engine, _ = run_layout(items, ["LI", f"1 {staves}"], digits=None)
    if model == engine:
        return None
    if model is None:
        return f"error: {error}"
    diff = [(a, b) for a, b in zip(model, engine) if a != b]
    return f"{len(diff)} items differ, first {diff[:2]}"


def main(cases: int = 100, max_staves: int = 3, rich: int = 0):
    rng = random.Random(7 + rich)
    good = 0
    for case in range(cases):
        items, staves = (rich_system if rich else random_system)(rng, max_staves)
        problem = compare(items, staves)
        if problem is None:
            good += 1
        else:
            print(f"case {case} ({staves} staves): {problem}")
    print(f"{good}/{cases} systems identical")


if __name__ == "__main__":
    main(*(int(a) for a in sys.argv[1:]))
