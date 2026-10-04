# Staged music input (IN)

The IN command and its five passes, as far as needed by `input-lang`. Call chains come from `oracle/trace.py` on `oracle/input_driver.py` runs (`experiments/input_trace.py`). Decompilations: `analysis/engine/decompiled_all/`.

## Routine map

| Address | Role | Confidence |
|---|---|---|
| 0x4AFB68 | IN command handler, calls the input main routine | verified (trace) |
| 0x52C6A0 | input main: range dialog, pass loop, writes the result | verified (trace) |
| 0x52F991 | range dialog wrapper (record IP1..IP8 at 0x2091C40, dialog 0x599FD0) | read |
| 0x52E0A3 | pass driver; readers 0x41C3B8 (pass 1), 0x422D98 (pass 2), 0x426950 (pass 3), 0x427C68 (passes 4/5), all reading keys through 0x549AFB and the C++ callback 0x597120 | verified (trace, input-lang) |
| 0x4AEFA0 (&first, &len) | processes one pass text: 0x4AF456 parses the tokens into the list R (f32 at 0x1FB8CC0 + 4i, count R[0]), then dispatches on the pass number (int 0x1FBB700): 1 → 0x4ECDF8, 2 → 0x51CF40, 3 → 0x4D8460, 4 → 0x413CA8, 5 → 0x53D1E0 | read; passes 1 and 2 verified (trace) |
| 0x4ECDF8 | pass 1: builds the work table from pitches (provisional, evenly spread x) | verified (trace) |
| 0x51CF40 | pass 2: rhythms and horizontal spacing (below) | read, examples verified |
| 0x51C64F (&dur, &type, &r, &dots, &tails) | decodes one rhythm value r of R | read |
| 0x51C5DB (&type) | 3 - trunc(type), 0 → 1, grace (type 0.0625) → -1 | read |
| 0x5253FD | writes the work table into the item store; pass 1: even spacing; pass 2: the minimum-gap pass 0x52FC56 | verified (trace) |
| 0x52FC56 (&n) | minimum-gap pass (below) | read, example verified |
| 0x4C04FB, 0x4C4148 (+0x4DDB6E) | pass-1 item builder, pass-2 rhythm application (P6/P7/P9) | trace by input-lang |

During pass 3 the pass number becomes 3, then 4, 5 and 6 in the main loop (writes at 0x52D5AC).

## Range dialog record (read, 0x52F991)

The dialog edits IP1..IP8 (ints at 0x2091C40). Only three fields are dialog fields:

| Field | Meaning |
|---|---|
| IP5 | begin of the range (P3), from and to the f32 at 0x796FD0 |
| IP6 | end of the range, f32 at 0x796FD4 (if end <= begin before the dialog: begin = f32 0x768438, end = 0x1FBB8B8) |
| IP7 | spacing staff, f32 at 0x1FB8C64. 0 in the dialog means none, stored as 999. Inferred from its use: a staff number <= 256 makes pass 2 align with that staff's notes and disables the minimum-gap pass |

The other fields are whatever IP1..IP8 held (99, 1, 0, 0 come from the last drawn item). A return value of 2 (IDCANCEL) aborts. The IN staff is the f32 at 0x1FB8C60.

## Work table (verified)

N entries (int 0x1FB8C80), 15 f32 each: parameter Pk of entry j at `0x1F95D40 + 0x3C*j + 4k`, k = 0..14. P1 is the code (1 note, 2 rest, 3 clef, 14 bar, 17 key, 18 meter, ...), P3 the x. The code addresses "P15" of entry j, which is the same word as P0 of entry j+1: pass 2 keeps an entry's width there, and a negative value marks the next note as a chord member. The same memory is reused by unrelated routines (e.g. the barline routine's locals at 0x1F95D20..0x1F95D6C).

## Pass 2 spacing, no spacing staff (0x51CF40; read, verified on examples)

Notation: `s` = STAFF_STEP(IN staff)/25 (staff size), `begin`, `end` = range (f32 0x1E67910/0x1E67914, copies of the dialog values), all variables f32.

1. **Trailing key signatures and meters** (scan from entry N backwards while the code is 17 or 18): `end -= s*w` and P3 = end, with w = 4 for a meter (7 if P6 >= 10 or P7 >= 10), w = |amod(P6, 100)|*2.8 + 0.5 for a key signature.
2. **Durations**: for every rhythm value r of R, 0x51C64F gives `dur = amod(r, 1000)` (in quarter notes as entered, e.g. 4 → 1 quarter after the conversion of pass 2's parser; dots via the hundreds digit), `type = 4/dur`, the number of tails, and grace notes (type 0.0625). Grace notes get dur = 0.1. `total` = sum of dur.
3. **Widths of non-note entries** (codes >= 3), `avail = end - begin` minus each width:
   - key signature (17): `w = |amod(P6,100)|*2.8 + 2`, -0.3 if the next entry is a meter; if the previous entry is also a non-note, its width grows by s;
   - barline (14), not last: w = 3.5; w = 1.5 if the next entry is a clef (3) or code > 16; w = 4.5 if the next is a note whose P6 has an accidental (amod(P6,10) != 0);
   - meter (18), not last: w = 7, or 9 if P6 >= 10 or P7 >= 10;
   - any other code, not last: w = 8 (9 for entries 1 and 2), plus (c' - 19) if the next entry's code c' > 16 (key: -2, meter: -1);
   - the last entry: w = 0;
   - then `w *= s`; `avail -= w`; w is kept in the entry's P15.
4. **Placement**, entries in order, `x = begin`:
   - non-note entry with width w: if it is the last entry, x = end. If it follows a note or rest and is not a barline, it moves left into the note's space: `x -= w/3`, `avail += w/3`. Then `P3 = x; x += w`.
   - note or rest: `P3 = x; x += (dur/total) * avail`. A following note marked as chord member (P15 slot of the current entry < 0) gets the same x and duration.
   Because `avail` changes at each mid-line clef, later notes get slightly wider spacing.
5. **Clefs after notes** (entries 2..N-1, code 3, previous entry not a barline): if `P3(j+1) - P3(j-1) >= 7s + 0.625`, then `P3(j) = P3(j+1) - 7s`.
6. **Unplaced entries** (P3 < 0, e.g. grace notes), scanning from the end: the last entry gets `end - 4`; any other gets `P3(j+1) - e` with `e = 3`, or half the distance from the previous placed entry to P3(j+1) if that distance is <= 4. If entry j+1 is followed by a chord member (P15 slot of j+1 < 0), e = 0 (read; not checked).

Checked: 4 quarters in 2..200 give 2, 51.5, 101, 150.5. With a mid-line clef (C4/C/BA/C/C), w = 8, avail = 190: notes 2 and 49.5; the clef is first placed at 97 - 8/3 = 94.333 (avail becomes 192.667); the next note at 102.333; the last at 102.333 + 192.667/4 = 150.5; step 5 moves the clef to 102.333 - 7 = 95.333. These match the engine (input-lang's numbers).

With a spacing staff (int 0x1FB8C74 > 0 entries in the time and position lists at 0x1F99BFC and 0x1F998DC), x is interpolated piecewise linearly between the spacing staff's (time, x) pairs instead: `x = (x_hi - x_lo)*(t - t_lo)/(t_hi - t_lo) + x_lo`. Not yet examined in detail.

## Minimum-gap pass (0x52FC56; read, verified on one example)

Run by 0x5253FD after pass 2 when the spacing-staff value is > 256 (i.e. none) and another pass has run since the last pass 2. On the N entries' P3 (x_j):

```
gaps g_j = x_j - x_(j-1), j = 2..N
ok      = sum of g_j with g_j >= 3 or g_j == 0
deficit = sum of (3 - g_j) over the other gaps
if deficit != 0 and f = (ok - deficit)/ok > 0:
    X_1 = begin
    X_j = X_(j-1) + (f*g_j if g_j >= 3.6 else 0 if g_j == 0 else 3)     # note 3.6, not 3
    x_j = X_j for j = 2 .. N-1                                          # the last entry is NOT moved
```

Gaps between 3 and 3.6 count as "ok" in f but are then set to exactly 3. Because the copy loop runs N-2 times, the last entry keeps its old x, so the gap before it can stay below 3. That explains why the minimum shows on the 16th and 32nd but not on the final 64th in input-lang's example: 1/2/4/8/16/32/64/.5 in 2..200 gives 2, 49.7996, 73.6994, 85.6493, 91.6243, 94.6243, 97.6243 and an unchanged 100.6118 (verified).
