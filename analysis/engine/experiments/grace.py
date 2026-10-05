"""Grace notes in the lineup: a port of 0x4C5AD8 (with 0x4C78F8, 0x4C795B, 0x4C7374).

The lineup leaves notes and rests with P7 >= 64 out of its events. When there are any, this pass
places every group of them in front of the note it ornaments: it collects the item before the
group (the "before" anchor), the group, and the item at the next x (the "after" anchor), gives each
a left and a right width, shrinks the widths of a group that does not fit between its anchors, and
writes the grace notes' P3 from the after anchor leftwards.

Lists are 1-based as in the engine; index 0 holds the zero a fresh engine has there.
"""
from __future__ import annotations

from dataclasses import dataclass, field

from staves import f32 as F, trunc

ACCIDENTAL = [F(v) for v in (0.0, 1.0, 4.2, 4.6, 4.2, 5.7, 4.6, 0.0, 0.0, 0.0, 0.0, 0.0)]   # 0x792638
VIRTUAL = -99


def code(it): return trunc(it[0])
def staff(it): return trunc(it[1])
def xpos(it): return it[2] if len(it) > 2 else 0.0
def par(it, k): return it[k - 1] if len(it) >= k else 0.0


def amod(x: float, y: float) -> float:
    return F(x - trunc(x / y) * y)


def cmod(a: int, b: int) -> int:
    """C/Fortran remainder: the sign follows the dividend."""
    return a - b * trunc(a / b)


def is_grace(it) -> bool:
    return code(it) < 3 and par(it, 7) >= 64


def plain_meter(it) -> bool:
    n = len(it)
    return (n < 15 or it[14] == 0) and it[3] == 0 and (n < 14 or it[13] == 0)


def is_spacer(it) -> bool:
    """Items the scans pass over: codes 4..16 except barlines, and displaced meters."""
    c = code(it)
    return (3 < c < 17 and c != 14) or (c == 18 and not plain_meter(it))


@dataclass
class GraceSession:
    """The global 0x89FBF0, which survives from one lineup to the next (layout.md §12)."""
    fbf0: float = 0.0


@dataclass
class Entry:
    x: float
    item: int | None               # item whose P3 the entry stands for (None: virtual)
    staff: int
    mark: int                      # LOAD_I, later negated by the sort and set to 1 when done
    kind: int                      # > 0 grace note (its code), -code after anchor, -100-code before anchor
    left: float = 0.0
    right: float = 0.0


@dataclass
class GracePass:
    items: list[list[float]]
    lo: int
    hi: int
    right_limit: float
    steps: dict[int, float]
    e: list[Entry] = field(default_factory=list)
    bars: list[tuple[float, int]] = field(default_factory=list)
    session: GraceSession = field(default_factory=GraceSession)

    def item(self, i):
        return self.items[i - 1]

    def add(self, i: int | None, kind: int, x: float | None = None, s: int | None = None):
        it = self.item(i) if i else None
        self.e.append(Entry(xpos(it) if x is None else x, i, staff(it) if s is None else s,
                            i if i else 1, kind))

    def run(self):
        self.e = [Entry(0.0, None, 0, 0, 0)]
        self.collect_bars()
        self.collect_groups()
        self.snap()
        self.provisional()
        self.barlines_between()
        self.widths()
        order = self.sort()
        self.group_widths(order)
        self.join_before_anchors(order)
        self.shrink_groups()
        self.place()

    def collect_bars(self):
        for i, it in enumerate(self.items, 1):
            if self.lo <= staff(it) <= self.hi and code(it) == 14:
                if not any(abs(xpos(it) - b) < F(0.005) for b, _ in self.bars):
                    self.bars.append((xpos(it), i))

    def collect_groups(self):
        n, i = len(self.items), 1
        while i <= n:
            it = self.item(i)
            if staff(it) > self.hi:
                return
            if staff(it) < self.lo or not is_grace(it):
                i += 1
                continue
            i = self.group(i)
            if i is None:
                return

    def group(self, i: int) -> int | None:
        """One grace group starting at item i; returns the next item to look at (None: done)."""
        n = len(self.items)
        s = staff(self.item(i))
        j = i - 1
        while j > 0 and staff(self.item(j)) == s and is_spacer(self.item(j)):
            j -= 1
        if j == 0 or staff(self.item(j)) != s:
            self.add(None, VIRTUAL, 0.0, s)
        else:
            while True:
                self.add(j, -100 - code(self.item(j)))
                if code(self.item(j)) > 2:
                    break
                j -= 1
                if j < 1:
                    break
                prev = self.item(j)
                if staff(prev) != s or xpos(prev) != self.e[-1].x or code(prev) > 2:
                    break
        self.add(i, code(self.item(i)))
        while True:
            i += 1
            if i > n or staff(self.item(i)) != s:
                self.add(None, VIRTUAL, self.right_limit, s)
                return i + 1
            it = self.item(i)
            if is_grace(it):
                self.add(i, code(it))
                continue
            if not is_spacer(it):
                break
        anchor_x = xpos(self.item(i))
        while True:
            self.add(i, -code(self.item(i)))
            while True:
                i += 1
                if i > n:
                    return None
                it = self.item(i)
                if staff(it) != s or xpos(it) != anchor_x:
                    return i
                if code(it) < 3:
                    break

    def snap(self):
        e = self.e
        for k in range(1, len(e) - 1):
            v = e[k].x
            for m in range(k + 1, len(e)):
                if abs(e[m].x - v) < F(0.01):
                    e[m].x = v

    def provisional(self):
        """Grace notes provisionally 0.11 apart in front of their after anchor."""
        e = self.e
        c = len(e) - 1
        prev, cur = 0.0, e[c].x
        while True:
            c -= 1
            if c == 0:
                return
            if e[c].kind < 0:
                prev, cur = 0.0, e[c].x
                continue
            if prev != e[c].x:
                cur = F(cur - F(0.11))
            prev = e[c].x
            e[c].x = cur

    def barlines_between(self):
        e, n = self.e, len(self.e) - 1
        for c in range(2, n):
            if e[c].kind < 0 or e[c - 1].kind == -14:
                continue
            hit = [(b, w) for b, w in self.bars if b <= e[c].x and e[c - 1].x <= b]
            if hit:
                b, w = hit[-1]
                e[c - 1].x, e[c - 1].item, e[c - 1].kind, e[c - 1].mark = b, w, -114, 1
        for c in range(n - 1, 1, -1):
            if e[c].kind < 0 or e[c + 1].kind == -14:
                continue
            hit = [(b, w) for b, w in self.bars if e[c].x <= b <= e[c + 1].x]
            if hit:
                b, w = hit[-1]
                e[c + 1].x, e[c + 1].item, e[c + 1].kind, e[c + 1].mark = b, w, -14, 1

    def widths(self):
        for en in self.e[1:]:
            k = cmod(en.kind, 100)
            if not (k in (-18, -17, -14) or k > -4):
                continue
            left, right = self.entry_widths(abs(k), self.item(en.item) if en.item else [])
            size = F(self.steps.get(en.staff, 25.0) / F(25))
            if en.kind > 0:
                size = F(size * F(0.6))
            en.right = F(size * right)
            en.left = F(size * left)

    def entry_widths(self, k: int, it) -> tuple[float, float]:
        """0x4C7374"""
        n = len(it)
        left, right = F(1.2), self.session.fbf0
        if k == 1:
            least = 1.0
            right = F(4.6) if n > 5 and it[5] == 2 else F(4.1)
            if n > 9 and it[9] != 0:
                shift = it[9]
                if abs(shift) < 10:
                    right = F(shift + right)
                if shift == 10:
                    right = F(right + right)
                if shift == 20:
                    least = F(least + right)
            ledger = 0.0
            pitch = amod(it[3], 100)
            if pitch >= 13 or pitch <= 0:
                right = F(right + F(0.5))
                ledger = 1.0
            left = amod(it[4], 10) if n > 4 else 0.0
            width = ACCIDENTAL[trunc(left + 1)]
            left = F(amod(left, 1) * 10 + width)
            if left <= 1:
                least = F(ledger + least)
            if left < least:
                left = least
            if n > 8:
                dots = F(float(trunc(it[8] / 10)))
                dots = F(amod(it[8], 1) * 10 + dots)
                least_dots = F(1.6) if it[4] < 20 and amod(it[8], 10) >= 1 else 0.0
                if dots < least_dots:
                    dots = least_dots
                right = F(dots + right)
        elif k == 2:
            right = F(3.1)
        elif k == 3:
            right = F(5.6) if n > 3 and it[3] >= 100 else F(7)
        elif k == 14:
            right, left = F(1.5), F(2.4)
            if n > 4:
                kind = it[4]
                left = {1: F(2.7), 2: F(3.7), 3: F(6)}.get(kind, left)
                if kind >= 4:
                    right = F(4.9)
                if kind > 5:
                    left = F(5)
        elif k != 17:
            right = F(8.1) if (par(it, 5) > 9 or (par(it, 6) > 9 and par(it, 5) < 90)) else F(5.6)
        self.session.fbf0 = right
        return left, right

    def sort(self) -> list[int]:
        """Entry indices by x (the last of equal minima first), marks negated."""
        e = self.e
        order = []
        while True:
            best, at = F(9999), 0
            for c in range(1, len(e)):
                if not (e[c].mark < 0 or best < e[c].x):
                    best, at = e[c].x, c
            if at == 0:
                return order
            order.append(at)
            e[at].mark = -e[at].mark

    def group_widths(self, order):
        e, n = self.e, len(order)
        c = 0
        while c < n - 1:
            if e[order[c]].x == e[order[c + 1]].x:
                x = self.session.fbf0 = e[order[c]].x
                m = c
                lmax = rmax = F(-99)
                while m < n and not x < e[order[m]].x:
                    lmax = max(lmax, e[order[m]].left)
                    rmax = max(rmax, e[order[m]].right)
                    m += 1
                for o in order[c:m]:
                    e[o].left, e[o].right = lmax, rmax
                c = m - 1
            c += 1

    def join_before_anchors(self, order):
        e = self.e
        for c in range(len(order) - 1):
            a, b = e[order[c]], e[order[c + 1]]
            if a.staff == b.staff or a.x == b.x:
                continue
            if a.kind < -99 and b.kind < -99:
                a.x, a.item, a.kind, a.mark, a.left, a.right = b.x, b.item, b.kind, b.mark, b.left, b.right
                order[c] = order[c + 1]

    def fit(self, c: int) -> tuple[float, int]:
        """0x4C795B: how much of its width the group before entry c may keep (<= 1), and its before anchor."""
        e = self.e
        ratio, total = 0.0, e[c].left
        j = c - 1
        while j > 0 and e[j].kind > -101:
            if e[j].kind >= 0 and e[j].x != ratio:
                ratio = e[j].x
                total = F(total + e[j].right + e[j].left)
            j -= 1
        total = F(total + e[j].right)
        room = F(e[c].x - e[j].x)
        ratio = F(room / total)
        return (1.0 if ratio > 1 else ratio), j

    def shrink_groups(self):
        e = self.e
        for c in range(len(e) - 1, 1, -1):
            if not (-100 < e[c].kind < 0 and e[c].mark < 1):
                continue
            x = e[c].x
            e[c].mark = 1
            ratio, j = self.fit(c)
            while True:
                m = next((m for m in range(j - 1, 0, -1) if e[m].x == x), None)
                if m is None:
                    break
                r, j = self.fit(m)
                e[m].mark = 1
                ratio = min(ratio, r)
            self.session.fbf0 = ratio
            if ratio == 1 or ratio <= 0:
                continue
            m = len(e) - 1
            while m >= 3:
                if e[m].x == x:
                    k = m
                    while k > 0:
                        e[k].left = F(ratio * e[k].left)
                        e[k].right = F(ratio * e[k].right)
                        if e[k].kind < -100:
                            break
                        k -= 1
                    m = k
                m -= 1

    def place(self):
        e, n = self.e, len(self.e) - 1
        dist = [0.0] * (n + 2)
        for c in range(1, n):
            if e[c].kind < 0:
                continue
            dist[c] = F(e[c - 1].right + e[c].left)
            carry = e[c].right
            for d in range(c + 1, n + 1):
                dist[d] = F(carry + e[d].left)
                if e[d].x != e[d - 1].x:
                    carry = e[d].right
                if e[d].kind < 0:
                    break
        c = n
        while True:
            cur, prev = e[c].x, 0.0
            while True:
                c -= 1
                if c < 2:
                    return
                if e[c].kind < 0:
                    break
                if prev != e[c].x:
                    cur = F(cur - dist[c + 1])
                prev = e[c].x
                if e[c - 1].kind < 0 and cur < e[c - 1].x + F(0.1):
                    cur = F(e[c - 1].x + F(0.1))
                e[c].x = cur
                self.item(e[c].item)[2] = cur
