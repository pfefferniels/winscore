# Layout: lineup (LI), justify (J) and LJ

**Status.** The lineup is ported routine by routine in `experiments/lineup.py` and reproduces the engine's item list bit for bit (all parameters, f32) on 200 random plain systems of 1 to 4 staves, 30 richer ones (keys, meters, second voices, inner clefs, key changes, barlines with P12, lines, slurs, beams, numbers, unequal staff totals) and 12 targeted cases. Two parts are read but not yet modelled: the grace-note pass 0x4C5AD8 (runs only when a note or rest has P7 >= 64) and the whole of justify (J, the second half of LJ). Unless marked otherwise, statements below are **verified** by these comparisons; routine addresses name the code they come from.

Notation as in the other notes: P(k) the f32 parameters, f32(·) rounding to single precision, trunc(·) toward zero, "staff" = trunc(P2), "code" = trunc(P1). Durations are P7 in quarter notes.

## 1. Commands and the source box

`LJ`, `LI` and `J` prompt "Enter Lowest Staff# of system and how many staves in system - or Draw Box." (0x4B7AD8). The answer goes to `lineup_answer` 0x4B906D:

- a typed answer `lo count` selects staves lo .. lo+count-1 and the x range 0 .. RIGHT, where RIGHT is the page's right limit (f32 0x1FBB8B8: 200 for the default page; 0x488258 sets 194, 234, 266 or 285 for other page formats);
- a box selects the staves it touches and its own x range, clamped to 0 .. RIGHT.

Then the engine asks "Source Box O.K.?" through the yes/no callback 0x595CD0. The oracle answers 0 (No) by default, and the command then does nothing; `experiments/layoutlab.py` answers 1. The letters decide what runs (0x4B80B7): first letter L runs the lineup 0x4C9510, second letter J (or first letter J) runs justify 0x4B6F4A afterwards. A second letter T goes to 0x4B8B97 instead (not examined).

The upper staff is clamped to the staff of the last item in the file. For LI and LJ the x range of the answer does **not** limit the lineup: whole staves take part (every event with P3 <= 200.05). The x range is used by J, by the clef adjustment below and by the rest flag at the end.

## 2. Preparation (0x4B80B7)

1. **Sort** 0x4F7808 (mode 'X'). Every item's P3 becomes `f32(f32(nint(P3*100))/100)`, nint = round half away from zero. Items are then ordered stably by `trunc(staff*1e6 + P3*1000)` (+1 when P1 > 2, so notes and rests come before other codes at the same x), then by P4 (+5 for rests, 0 when the item has fewer than 4 parameters). The sort runs three times; it is idempotent.
2. A **code-4 line** with P7 < 0, P6 = 0 and at least 7 parameters whose P3 is within 0.1 of the immediately preceding note's P3 gets P3 = note x - 0.001, so that it sorts before the note.
3. **Clef at the staff start:** per staff, the first clef whose P3 equals the staff item's P3 (and lies in the x range of the answer) moves to staff P3 + 1.5.
4. **Right edge:** a note with |RIGHT - P3| < 1 gets P3 = RIGHT - 1; likewise P6 of beams (code 6) and of code-5 items with P8 = -1.

## 3. Events of one staff (0x534C40)

Per staff, the engine builds a list of *events*: an x position and an entry that is either a duration (> 0) or a marker (-code < 0).

**Which items count.** P3 <= 200.05 (a literal 200, independent of RIGHT). Notes and rests (codes 1, 2) with at least 7 parameters and P7 > 0; clefs (3), barlines (14), keys (17) and meters (18). Excluded: barlines with 8 <= trunc(P5) <= 10, clefs with P5 >= 44, keys and meters with P14 or P15 non-zero, meters with |P4 * P7| > 2 (P7 = 0 counts as 1). A P3 within 0.01 of 0 is set to 0, and the staff's last relevant item with P3 within 0.01 of 200 gets P3 = 200.

**Notes and rests with P7 >= 64** (grace notes have 64 or 65, help text code1/compkybd) are left out of the events. Their presence triggers the grace-note pass 0x4C5AD8 at the end of the lineup (read in outline, not modelled).

**Grouping.** A note or rest starts a new event when its P3 differs by more than 0.1 from the current event's x; otherwise its P7 joins the event (chords, notes of other voices within 0.1). A marker starts a new event whenever its P3 differs at all from the current event's x; at exactly the same x it is ignored. A barline with P12 > 0 is marked -140 (treated as -14 from §4 on).

**Durations** (0x53572C). Each event keeps a list of *open values*: the P7 of its items plus what is left over from earlier events. When the next event starts, the current one gets the smallest open value as its duration, and every other value minus that duration stays open if it exceeds 0.001. This is how a whole note under four quarters in another voice yields four quarter events. Markers enter the same list as -code, so a marker event's entry is its marker, and values still open at that moment grow by the marker code (a value r becomes r + 14 at a barline). With complete voices nothing is open at a barline and this does not matter; an inner clef while another voice sounds makes the staff total too large (observed: 13 beats against 12, and the lineup refuses, §4).

**Rounding of totals.** A running sum of the durations is kept; when its fractional part is within 0.005 of 0 or 1 (and not 0), the current duration is corrected so that the sum becomes integral. Three triplet eighths of P7 = 0.333 thus total exactly 1. The staff total is the sum of the durations.

## 4. Normalisation and merging (0x4C9510)

For each staff with events, in staff order:

- -140 becomes -14. If the last entry is no barline, a closing barline -14 is appended: at RIGHT for the first staff and at the current x_right for later ones, or, when the last entry is a marker, at P6 of the lowest staff's staff item (RIGHT if that is 0 or missing).
- Durations are multiplied by 4 (sixteenths). The first clef before any other entry except barlines becomes the *start clef* -15. **Clefs after it are dropped** from the list; they are placed afterwards (§6).
- A staff without events is skipped (if it is the lowest, the next one becomes the reference).
- **Equal totals.** Every staff's total must equal the first staff's within 0.007. Otherwise the engine reports the staff number and its total and stops before moving anything (the sort, the P3 rounding and the 0/200 snaps of §3 have already happened).
- The staff's list is merged into the system's *master list*: first the markers of both lists are interleaved in order with the master's durations kept (a first merge with special cases for a key just before a barline), then every master duration is split wherever this staff has an onset (0x4CB78B, tolerance 0.004 to 0.01). Repeated barlines collapse to one (0x4CB518).

x_left is the smallest first-event x over the staves, x_right the largest closing-barline x.

## 5. Spacing (0x4CC470)

The master list gets new positions from x_left to x_right:

```
size  = f32(STAFF_STEP(lo) / 25)             # 1 for a P5 = 1 staff
w(d)  = f32(d ** f32(0.5849624872207642))    # d in sixteenths; f32 at 0x7926DC = log2(1.5)
fixed = sum of marker widths (table below), the last entry gets none
unit  = f32(((x_right - x_left) - size*fixed) / sum of w)
x_1   = x_left,   x_{k+1} = f32(f32(width_k * (unit for durations | size for markers)) + x_k)
```

So each doubling of a duration multiplies its space by 1.5 (the help's "a half note will not receive twice the space of a quarter note"), and all sums are f32.

| Marker | followed by | width (x size) |
|---|---|---|
| barline -14 | start clef -15 or key -17 | 1.5 |
| barline -14 | meter -18 | 1.0 |
| barline -14 | anything else | 3.5 |
| start clef -15 | key -17 (or another code below -16) | 8 |
| start clef -15 | meter -18 | 6 |
| start clef -15 | anything else | 10 |
| meter -18 | barline | 4.6 |
| key -17, meter -18, other | anything else | 3.5 |

The lineup has **no minimum gap** and does **not** look at accidentals, dots, flags, chord seconds or P10 offsets; making room for them is the job of J.

## 6. Applying the positions (0x4C8290)

Staff items (code 8) of the system are excluded for the duration (P2 negated, restored afterwards). Then, per staff:

1. **Alignment** (0x4CC8A9). The staff's own events are walked against the master list. A master marker that the staff lacks gets a virtual event at the midpoint of the staff's neighbouring old positions; a start clef the master lacks is skipped.
2. **Segments.** Consecutive staff events give old intervals [old_i, old_{i+1}]; the matching master positions give new ones. When a staff event spans several master events, its end is placed proportionally to the durations (`new = (next_master_x - new_prev) * staff_duration / master_duration_sum + new_prev`); a staff barline that meets a master duration goes to the midpoint, and vice versa. A rhythm that cannot be matched stops the lineup with items partly moved.
3. **Moving** (0x49B1D8 select, 0x49BB13 move). In each segment, P3 of every note, rest, clef, barline, key and meter of the staff (all codes outside 4..16 except 14) with old P3 in [old_i - 0.001, old_{i+1} + 0.001] is mapped linearly and **parked 1000 units to the right** so that later segments skip it:

   ```
   factor = f32((new_{i+1} - new_i) / (old_{i+1} - old_i))
   offset = f32(f32(new_i + 1000) - factor * old_i)
   P3     = f32(factor * P3 + offset)        # results within 0.005 of 0 become 0
   ```

   At the end of the staff every parked P3 (>= first new x + 800) gets `f32(P3 - 1000)`. The detour through 1000 limits the final positions to steps of about 1.2e-4, which is why they never equal the spacing's values exactly.

Chord notes a little to the right of their event, and items between events, therefore keep their relative place inside the segment. Items before the staff's first event or after its last are not moved.

**Clefs inside the line.** Afterwards every clef at or beyond a threshold (the first note's x - 2, or the first clef's x + 2, whichever item comes first in the file) is placed again. Its target is found by walking forward on its own staff: a barline met before any note or rest is the target; at the next note or rest, the first barline of the system (any staff) at or after the clef is the target if it lies before that note, otherwise the note is; with neither, the system's last barline. The clef goes to `f32(target - gap + 1)` with gap = f32(STAFF_STEP*0.3 + 1), i.e. 0.3 staff steps (7.5 units for P5 = 1) before the target, if the previous item is more than gap away. Otherwise it goes to the midpoint between the target and the previous note, rest, key or meter (other codes are skipped when looking back).

## 7. Other items (0x4CB010, 0x4CB2EA)

Before the merge, 0x4C9510 records *anchors*: per staff in the system, every note, rest, clef, barline, key and meter with P3 <= RIGHT + 0.05 (distinct staff and x), a barline with P4 = n also on the n-1 staves above its own, and a virtual anchor at RIGHT closing each staff. After the moves, x parameters of the following codes are interpolated between the anchors around their old value:

| Code | parameters |
|---|---|
| 4, 5, 7 | P3, and P6 when present |
| 6 (beams) | P3; P6 unless P7 < 0; P11 if > 0; P12 if > 0 and P7 > 0; P14, P15 if > 0 and P13 != 0 |
| 9 to 13, 15, 16 | P3 |

```
part = f32(x - old_a)  (0 when |part| < 0.01),   span = f32(old_b - old_a)   (skipped when < 0.01)
frac = f32(part / span)  (1 when |frac - 1| < 0.01)
x'   = f32((new_b - new_a) * frac + new_a)       # new_b = RIGHT for the virtual anchor
```

So slurs, ties, beams, lines, text, numbers and library symbols follow the notes proportionally. **Left alone:** staff items (code 8), every item on staves outside the system, x values outside all anchor intervals of their staff, the second x parameters of codes not listed (for example P6 of code 9 to 16), and all vertical parameters.

## 8. After the lineup

Rests (code 2) with P5 <= -2 between x_left and the right end of the answer's x range get P9 = -1 (the item is extended to 9 parameters). Then the page is redrawn.

## 9. Justify (J) – read in outline

0x4B6F4A selects the items in the box (0x49B1D8; a side effect sets P6 = RIGHT on staff items with 6 or more parameters and P6 = 0), then per staff 0x4BCD68 collects the columns of the box (notes, rests, clefs, lines with P7 < 0, keys, meters, barlines, numbers with P16) and their left and right space needs: accidental widths from the tables at 0x792554/0x79254C, P10 shifts of chord notes (P10 = 10/20/110), dots, flags (0x4B6818), rests (0x4B6657), keys (0x4B6C51), other codes (0x4B6A52), with factors such as 1.3, 1.7, 1.8, 2.3, scaled by 0.04 * STAFF_STEP. The staves' column lists are merged (0x4B7468) and 0x4B5DB0 takes the needed space proportionally from the free space of the line, as the help describes ("Justify subtracts proportionally from all the extra space on the line"). Port and verification are the next step.

## 10. Quirks worth keeping

- Values open across a marker grow by the marker code (§3).
- Markers at exactly the x of the current event are ignored; notes within 0.1 after a barline join the barline's event and their P7 is carried as P7 + 14.
- The literal 200.05 / 200 in §3 ignores other page widths.
- If no note, rest or clef lies in the system, 0x4C8290 returns early and the staff items keep their negated P2.
- In 0x4C9510 the virtual anchors take their item reference from whatever the previous run left in the table; the model assumes a fresh engine, as in the oracle.

## Verification

`python experiments/lineup.py [cases] [max_staves] [rich]` compares `lineup_items` with the oracle after `LI` and `lo count` (yes to the source box), item by item and bit for bit, including the engine's partly changed items when it gives up. Results: 200/200 plain, 30/30 rich, plus the targeted cases (triplets, notes 0.05 apart, keys and meters, staff size 0.75, staff P6 = 150, no closing barline, closing clef, barline with P12, slurs/beams/lines/numbers, a two-staff barline with P4 = 2).
