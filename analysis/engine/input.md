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
   - meter (18), not last: w = 7, or 9 if P6 >= 10 or P7 >= 10 (also true for C and alla breve, stored as 99/98: they are 9 wide, 7 when trailing; input-lang);
   - any other code, not last: w = 8 (9 for entries 1 and 2), plus (c' - 19) if the next entry's code c' > 16 (key: -2, meter: -1);
   - the last entry: w = 0;
   - then `w *= s`; `avail -= w`; w is kept in the entry's P15.
4. **Placement**, entries in order, `x = begin`:
   - non-note entry with width w: if it is the last entry, x = end. If it follows a note or rest and is not a barline, it moves left into the note's space: `x -= w/3`, `avail += w/3`. Then `P3 = x; x += w`.
   - note or rest: `P3 = x; x += (dur/total) * avail`. A following note marked as chord member (P15 slot of the current entry < 0) gets the same x and duration.
   Because `avail` changes at each mid-line clef, later notes get slightly wider spacing.
5. **Clefs after notes** (entries 2..N-1, code 3, previous entry not a barline): if `P3(j+1) - P3(j-1) >= 7s + 0.625`, then `P3(j) = P3(j+1) - 7s`.
6. **Unplaced entries** (P3 still < 0 at the end), scanning from the end: the last entry gets `end - 4`; any other gets `P3(j+1) - e` with `e = 3`, or half the distance from the previous placed entry to P3(j+1) if that distance is <= 4. If entry j+1 is followed by a chord member (P15 slot of j+1 < 0), e = 0 (read; not checked).

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

## Grace notes (verified by input-lang)

A grace note's work-table P3 is first set to -1 (0x51E157), then overwritten in the main loop like any note (P3 = x at 0x51E60B), with duration 0.1. So it advances x by (0.1/total)*avail: `4/G/G/4` in 2..200 has total 2.2, and each grace note takes 0.1/2.2*198 = 9 units.

## Grammar

How a pass text becomes items, derived from the parser routines and checked on the oracle with `experiments/inprobe.py` (it prints each pass text as 0x4AEFA0 receives it, the token list R and the saved items) on `oracle/input_corpus_grammar.txt` (blocks `== g-<pass>-<construct>`. The block name is given in the last column). The engine is the authority (D3). Where Craig Sapp's input page or Smith's help read differently, the engine's reading is given and the difference noted under each pass.

A pass text goes through four stages:

1. **Reader** (0x41C3B8 pass 1, 0x422D98 pass 2, 0x426950 pass 3, 0x427C68 passes 4/5) receives one key at a time and edits the text. The READ path (0x53174C) calls the same readers. The probes type each character with KEY_CODE set to the character (`oracle/input_driver.py`). Some characters share their code with a virtual key (`#` End, `$` Home, `%` Left, `'` Right, `-` Insert, `.` Delete), and how the GUI's key handlers (0x58FCD0, 0x5906C7) fill KEY_CODE for them was not traced, so their reader effects below hold for the driver and may differ when typed in the program.
2. **Tokenizer** 0x4AEFA0 → 0x4AF456 → 0x524C4A splits the text into items, gives each to the pass's item parser and appends what it returns to the token list R (f32 at 0x1FB8CC4 + 4i, count int 0x1FB8CC0).
3. **Item parser** (0x4E2CC8, 0x4D9EA0, 0x4DAEB2, 0x4DA9C3) reads one item and returns one token (f32 0x1ADE8E0), plus the flags for dyads (0x1FBB708) and repeats (0x1FBB70C count, 0x1FBB710 times).
4. **Builder** (0x4ECDF8, 0x51CF40, 0x4D8460, 0x413CA8, 0x53D1E0) turns R into work-table entries and items.

An item the parser rejects goes to 0x5259E5: the pass is not taken, the reader shows the text with the error position and waits for a correction. The probe stops there and prints `REJECTED pass n rejects at <position>`. The Rust port can report the same position.

### Tokenizer (all passes)

| Construct | Routine | Rule | Probe |
|---|---|---|---|
| `/` | 0x524C4A | item separator | |
| `,` | 0x524C4A | rewritten to `/` before the item is parsed (pass 1: see the item check, an item whose first two characters fail is erased first) | g-p1-comma-inside, g-p1-last-comma |
| `;` | 0x524C4A, 0x4AEFA0 | ends the pass. If the first 384 characters hold no `;`, the text is cut at the last `/` before that point and a `;` written there | |
| space | 0x526EC4 | skipped before and inside items (the number reader 0x5194D5 stops at a space, so `3 4` is two numbers) | g-p1-separators |
| leading `/` | 0x4AEFA0 | skipped | g-p1-leading-slash |
| empty item `//`, trailing `/;` | 0x524C4A, 0x4AF456 | repeats the previous item once (0x1FBB710 = -2, one more copy of the last 1 item). `C4/D/;` gives C4 D D. In pass 1 the reader removes the `/` of a final `M`, `M?` item first (see the reader) | g-p1-empty-item, g-p1-trailing-slash |
| `X` or `Z` anywhere in an item (passes 1, 2, 4, 5) | 0x524C4A | must be followed by `[` or a digit 1–9, else the item is rejected (`RX`, `S+X`, `X0`) | g-p1-erase-rest |
| `=` (passes 3–5) | 0x524C4A | read as `+` | |
| `:` or `'` (pass 1) | 0x524C4A | chord separator. The notes up to the next `/` form one chord (0x1FBB718: first note token positive, the others negative) | g-p1-chord |
| `name[`…`]` | 0x524C4A | macro definition. The name is the character before `[`. `[` restarts the item scan after it, `]` becomes a space. The content is read as ordinary items and also stored (by the reader, 0x41FAB5, as a motive file under `!tmp`) | g-p1-macro |
| `@name` | 0x524C4A → 0x420E60 | the stored text replaces the call, and the item restarts at the call: characters of the same item before `@` are dropped, the chord state stays (`C5:E5]@Z` with Z = `C4/…` gives C5 with C4 as its chord member, E5 is lost). A number after the name (P2, read by 0x420E60) is applied by 0x52789C in passes 1–2 and 0x4E5EA6 in passes 3–5 (per pass below) | g-p1-macro-transpose |

Repeats are applied by 0x4AF456 after the item's token was appended. `Xn` as item suffix: n copies in all of the last item. `Xn m` as an item (pass 1: also `REPn m`. `Zn m` keeps accidentals): the last n items so many times that there are m copies in all. With fewer than n items in R the pass fails (error code position − 2). Counting back, an entry is skipped when it is ≤ 0 and round(value/1000) is −1 or −7 (a chord member), so a chord counts once. Any other entry counts, including barlines, rests, clefs and the 5000/6000/8000 control tokens. Chord members whose token rounds to −2 or −8 (accidental double sharp or a quarter tone, or cautionary with these) are counted as items of their own, an engine quirk. In copies made by `X`, notes lose their accidental: v → sign(v)·(1000·t + |v| mod 100) with t = trunc(|v|/1000) ∈ {1, 7} (the cautionary 7000 stays). `Z` copies unchanged.

### Pass 1: notes

#### Reader (0x41C3B8)

The reader builds the text and draws each item as soon as it is closed by `/` (or `:`), with its own builder 0x4C04FB. Effects on the text (probes g-p1-case, sweep in g-p1-* and the blocks named):

- `a`–`z` are stored as `A`–`Z` (0x41D5xx, KEY_CODE − 0x20).
- `'` is stored as `:`.
- `.` and `=` are stored as `=` after `/`, `.` or `=`, otherwise as `+`: `C4.` = `C4=` = `C4+` (octave dyad), `/.` = `/=`, `/..` = `/==` (g-p1-equals, g-p1-dots-equals).
- `#`, `$`, `%` are not stored (they are also the key codes of End, Home and Left). `$` is kept right after `@` or `-`. `^` starts the special-key function 0x5956B0 and is not text.
- **Item check.** On `/` the item's first characters go through 0x4C2912 (called from 0x4C04FB). If it fails, "**** Input error ****" is shown, `****` is written to the key buffer (0x4C355C) and the reader cuts the text back to the previous `/` (0x41E4F6 → 0x41E551): the item is erased. The last item, closed by `;`, is not checked. c1 and c2 are the raw first characters of the item (buffer 0x1E62C84); only a leading CR is skipped, so `C4/ D/E` erases ` D` (g-p1-erase-leading-space). See the table below.
- `;` typed after a final `M/` or `M?/` (an `M` one or two characters before the `/`) replaces that `/`, so a final barline is not repeated: `C4/M/;` is `C4/M;`, but `C4/MRD/;` keeps the slash and repeats MRD (g-p1-trailing-slash-bar*).
- A leading `/` is not stored.
- `Xn m` with n too large: "Repeat source number too big." (0x421651), item erased (g-p1-repeat-too-long). For the live drawing, 0x421651 counts items of the score's item store backwards from the last one, on all staves, including the staff item and older content. Notes and rests at the x of the previously counted note or rest count once (chords), every other item counts one. The message comes when the store runs out before more than n items are counted. The parser later counts in R, differently (see the tokenizer).
- On `]` (0x41FAB5) every note of the macro definition without an octave digit gets one appended, computed by the octave rules, including O/P and the octave before the definition: `Z[C4/G/E]` → `Z[C4/G4/E4]`, `Z[PC4/B/E/G/C]` → `…B3/E4/G4/C5`, `C3/Z[E/G]` → `…E3/G3` (g-p1-macro-oct-*). A note with `U` or `J` and no digit instead gets the last digit character that stands before it in the definition, counting digits inserted for earlier notes (`Z[C4/AJ/BJ…` → `AJ4/BJ4`); the parser then reads that digit after the jump, so the jump is lost. The following notes do get the jumped octave, one jump per note (`Z[C4/AJ/B…` → `B3`, `AJJ/B` → `B3`). Engine bug, not grammar (D12, not ported): the text damage that follows. Let k be the number of such U/J notes without a digit. For k ≥ 1 the text after `]` is wrong: the last k − 1 characters of the definition are removed and the first key typed after `]` is lost, the following keys go on from there. So `Z[C4/AJ/B]/E` → `Z[C4/AJ4/B3]E` (k = 1), `Z[C4/AJ/BJ]/E` → `Z[C4/AJ4/BJ4E` (k = 2), `Z[C4/AJ/BJ/CJ]/E/F` → `…CJE/F` (k = 3), and `C5:E5]/@Z` with one J earlier → `C5:E5]@Z`. When the call falls inside the definition's last item this way, the tokenizer drops that item's text (see `@name`): g-p1-macro-octaves receives 'Z[C4/AJ4/PB3/E5/F5/C5:E5]@Z;', loses the final E5, and the recalled C4 becomes a chord member of C5. With k = 0 nothing is lost (`A[C4/D/E]/@A/@A`, g-p1-macro-names, g-p1-macro-loss-with-digit; probes g-p1-macro-loss-*). Give notes with U/J an octave digit inside definitions. The damage cases (this one, `]` followed directly by a letter, the lost `/` of `]/@`) are documented only to explain fixtures; they were not pursued further.

**Item check 0x4C2912 (pass 1).** c1, c2 are the first two characters of the item. A leading `-` followed by T, A or B and then R, E, L or A is skipped first (input clefs). `name[` checks that the name is A–Z and then the first item inside.

| c1 | item kept when c2 is |
|---|---|
| A | `L`, or as for D–G |
| B | `A`, or as for D–G |
| C | `U`, `O`, or as for D–G |
| D E F G | `'` `:` the same letter, `+ - U J N F S (`, a digit **1–8**, `. = ] X / ;` |
| K | a digit 1–7 |
| M | anything |
| O | A–G |
| P | `R`, A–G |
| Q | `0 + -` (`=` counts as `+`) |
| R | `F I W P`, a digit 1–9, `] D U / ; X` |
| S | `O U D 0 + -` |
| T | `R E` |
| X, Z | a digit 0–9 |
| `@` | A–Z, or `-`/`$` followed by A–Z |
| a digit, `=`, `.`, `]`, `/`, `;` | anything |
| H I J L N U V W Y, other characters | nothing (always erased) |

So these are erased unless they are the last item: octave 0 or 9 right after the letter (`C0`, `B9`. `CS0` passes), `K0S`, `K8S`, `K 2 S`, `T`, `T6 8`, `REP…`, `QX`, `R0`, `R 5`, `D F`, `OPC4`, `P OE`, `-X`, `D,E` (g-p1-erase-*, g-p1-last-*).

#### Items (0x4E2CC8)

The item parser dispatches on the first character: A–G (with the exceptions `BA`, `AL`, `C?M`, `C?T` checked first), then the table at 0x79490C `K M O P R S T X Z - . Q =`, then a digit (meter). Anything else is rejected. Tokens:

| Construct | Rule (0x4E2CC8 unless noted) | Token | Item | Probe |
|---|---|---|---|---|
| note `L[acc][oct][+|-][U|J…][Xn|Zn]` | letter step l: C=1 … B=7. Then the suffix loop below | ±(1000 + s + 100·a + 6000·c), s = octave·7 + l | code 1, P4 from s and the clef, P5 = 10·stem + a (+100 when cautionary) | g-p1-octaves |
| accidental `F S N`, `FF SS NN` | `F`=1, `S`=2, `N`=3. The same letter again adds 3: `FF`=4, `SS`=5, `NN`=6 (¼-tone flat). Only before the octave digit: `C4S` is rejected | a = 1…6 | P5 ones digit | g-p1-accidentals, g-p1-accidental-after-octave |
| repeated letter | each repetition of the note letter adds 1: `BB`=1, `CCC`=2, `EEEE`=3, … up to 10 letters = 9 (¾-tone sharp). After the letters, `F`/`S`/`N` set the accidental (`AAS` = sharp, `BBF` = flat, `AAF` = flat) and the same accidental letter again adds 3 (`GGFF` = 4). The note letter counts too: `FF` is F flat, `FFF` F sharp. Eleven or more letters overflow the token | | | g-p1-letter-accidentals(-long) |
| `(` | cautionary: before the accidental letter and the octave (`B(F4`, `CC(`, `E(` alone, `A((`. `CF(` is rejected) | +6000 | P5 + 100 (work-table P6 = a + 100). Pass 2's barline width tests amod(P6, 10) ≠ 0, so `(` without an accidental does not widen a barline before the note (3.5, with an accidental 4.5) | g-p1-cautionary, g-p1-cautionary-after-accidental, g-p1-cautionary-chord-bar |
| octave digit 0–9 | sets the octave: c0 = 7·digit (state 0x78DEC0). In proximity mode also the reference | | | |
| `+` / `-` after the note | octave dyad: 0x4AF456 appends a second, chord-member token −(|t| ± 7), accidental and cautionary kept. The typed note stays the previous note for the octave rules. Also inside a chord (`C4+:E` = C4, C5, E4) | t, −(|t|+7) | two notes at one x | g-p1-dyad |
| `U` / `J` (repeatable, before or after the digit) | U: if l ≤ l_prev then c0 += 7. J: if l_prev ≤ l then c0 −= 7 (l_prev = letter of the previous note, 0x78DECC, not reset by IN, 1 in a fresh engine). So the same letter jumps a full octave (`CU` after C4 = C5). The new c0 holds for the later notes. Disables the proximity step for this note only. `CUU` jumps twice. `C4U` is C5. `CU4` is C4 | | | g-p1-jump-up, g-p1-jump-down, g-p1-state-fresh-*, g-p1-state-carried-lprev |
| `O`, `P` before the letter | O: ordinary mode (0x78DEC4 = −1). P: proximity mode, the reference being the last note's step (0x78DEC8). That step is not reset by IN, so it carries from the previous line (fresh engine: 0, `PB` = B3; after D6, `PB` = B5). Only one prefix survives the item check | | | g-p1-ordinary, g-p1-proximity, g-p1-state-fresh-pb, g-p1-state-carried-proximity |
| `Xn`, `Zn` suffix | ends the note. Repeat (tokenizer) | | | g-p1-repeat-item |
| chord `N:N:N` | see tokenizer. Octaves carry from note to note inside the chord | | | g-p1-chord |
| `.` / `=` item (typed `.`) | repeat a chord, accidentals removed; `==` (typed `..`) keeps them. Counting back from the end of R, rests, barlines and control tokens are skipped; the last note or chord is passed over and the next one back is copied (a single note too). Nothing there: rejected. As the first item the reader makes `.` into `+` and the item check erases it | copies | | g-p1-chord-repeat, g-p1-chord-repeat-direct, g-p1-chord-repeat-nothing, g-p1-chord-repeat-first |
| `R` | rest | 2000 | code 2 | g-p1-rests |
| `RI`, `RW`, `RP`, `RD`, `RU`, `RF` | table 0x7948C4 | 2001 … 2006 | RI: P6 = −1. RW: P5 = −2, P9 = −1. RP: P5 = −4, P9 = −1. RD/RU: P4 = ∓6. RF: P8 = −1 | g-p1-rests |
| `RWD`, `RWU`, `RFD`, `RFU` | second letter after W or F | 2008, 2009, 9000, 9001 | RWD/RWU: the same item as RW (the builder's P4 = ∓6 does not survive). RFD/RFU: fermata with P4 = ∓6 | g-p1-rest-placement |
| `Rn` (number) | | −2000 − n | centred rest, P8 = n, P9 = −1, P5 = −2 for n ≤ 3 and −5 for n ≥ 4 (set in pass 2 by 0x51CF40, which also gives every rest with P5 ≤ −1 P4 = 0 and P9 = −1). `R0` as last item = RW | g-p1-rest-numbers, g-p1-last-rest-zero, g-p1-rest-number-threshold |
| `R…Xn` | rest repeated | | | g-p1-rest-repeat |
| `TR`, `BA`, `AL`, `TE`, `PR` | clefs | 3000 … 3004 | code 3, P5 = 0…4. P4 = 100 (small) unless it is the first entry, or it directly follows a barline and is the first clef of the line | g-p1-clefs, g-p1-clef-after-bar |
| `-TR`, `-BA`, `-AL`, `-TE` | input clef: only the second character counts (`B`→1, `A`→2, `T`+`E`→3, else 0. `-AA` = `-AL`) | −3000 − k | no item. The following notes are positioned as if the staff had clef k (`BA/-TR/C4` puts C4's treble position, E2, on the bass staff). The builder only sets the clef variable 0x1F95C90 and makes no work-table entry; a later key signature stores it in P6, a later real clef replaces it | g-p1-input-clef, g-p1-input-clef-alias |
| `KnS`, `KnF`, `KnSN`, `KnFN` | n read by 0x5194D5. After S or F only `N` may follow | ±(17000 + n), N: ±(17100 + n), − for F | code 17, P5 = ±n or ±(100 + n) (cancellation), n = 0 gives no item | g-p1-keys |
| `K` alone | key from the key-name global 0x78DE16 via 0x4E4432 (default unset). Always erased by the item check | | | g-p1-key-plain |
| `n m` (digit first) | meter. M = 0 or missing: n and m swapped, a single number | 20000 + 100·n + m | code 18, P5 = n, P6 = m (`2` gives 0 2) | g-p1-meters |
| `COM`, `CUT`, generally `C?M`, `C?T` | the third character decides (`C4M` is common time) | 29901, 29801 | P5/P6 = 99/1, 98/1 | g-p1-meter-c-letters |
| `T` (last item only) | repeats the last meter (0x78D918/0x78D91C, also set by COM/CUT. Global) | | | g-p1-last-meter-t |
| `Tn m` (last item only) | meter n m | | | g-p1-last-meter-t-numbers |
| `M[type][span]` | type letters: `D` or `M` = 1 (a second `D`/`M` after 1 gives 2, after another type 5), `H` 2, `L` 3, `R` 4, `S` 7, `I` 9. A digit is the span and ends the item (`M2D` = `M2`) | 4000 + 100·type + span | code 14, P4 = span, P5 = type. I: P4 = −span, no P5 | g-p1-bars, g-p1-bar-letters |
| bar span | remembered (0x78DD60, reset to 1 by each IN) | | | g-p1-bar-span, g-p1-state-carried |
| `SU`, `SD`, `SO` | stem mode up / down / automatic for the following notes. Later characters ignored | 5010, 5020, 5000 | P5 tens digit 1 / 2 / automatic | g-p1-stems |
| `S+`, `S-`, `S0` | staff placement of the following notes | 6001, 6002, 6000 | P12 = 1 / 2 / none | g-p1-staff-shift |
| `Q+`, `Q-`, `Q0` | cue size on / off. `Q` + anything but `+` is off | 8001, 8000 | P4 ± 100 (sign of P4) on notes and rests. Q+: if the stem mode is automatic it becomes up. Q-: the mode last set by SU/SD/SO (saved at 0x8D175C) is restored. A later S? command overrides Q+ | g-p1-cue, g-p1-cue-stems, g-p1-cue-high |
| `X n m`, `Z n m`, `REP n m` | group repeat (tokenizer) | | | g-p1-repeat-group(-z), g-p1-rep |

Suffix loop of a note (after the letter. The next non-space character c): end of item → finish. C = the current letter (or, after an accidental, that accidental letter) → see the accidental rows. `(` → cautionary. `F S N` → accidental. Then, in this order and each optional: a digit, `+`/`-`, `X`/`Z` (ends the note), `U`/`J` (loops back). Any other character rejects the item.

Finishing a note (0x4E33A4): if no U/J was given and proximity mode is on, d = step_prev − (l + c0). C0 += 7 if d > 3, c0 −= 7 if d < −3 (the nearest of the two candidates, no ties are possible). Then s = c0 + l. A step below 1 is possible (`DJJ` near the bottom) and gives a token below 1000 that the builder misreads as a meter (g-p1-jump-down).

**State.** Reset by each IN (0x52C6A0 and the reader): octave c0 = 28 (octave 4), ordinary mode, bar span 1. By the builder: stem mode automatic, cue off, staff placement 0, input clef = the staff's clef. Carried from earlier input: l_prev (for U/J), the last step (for P), the last meter (for `T`), the stored macros (files in `!tmp`). In a fresh engine l_prev = 1 (C), last step 0, last meter 4/4 (static data at 0x78DECC, 0x78DEC8, 0x78D918). Engine flaw, not grammar (D12, not ported): the final parse at `;` also starts with the octave mode 0x78DEC4 as the reader's live parse left it, the only pass-1 state the two share (c0, the last step, l_prev, the bar span and the last meter are written by 0x4E2CC8 alone). The live builder 0x4C04FB runs on every item closed by `/` or `:`; it sets the mode to −1 before the first item, to −1 for an item starting with `O` and to 1 for one starting with `P` (not `PR`). So after a live `P` item that no live `O` item follows, the final parse begins in proximity mode with reference step 1: `C4/A/PB/OC;` reads A3, `G/PB/OC;` reads G3, `C4/A/PB:D/E;` likewise, `C4/A/PB/OC/D;` reads A4 (g-p1-live-mode-*; found by input-lang in random batches). A `@` call in the reader resets the mode to −1, a macro definition (0x41FAB5) may leave 0 or −1, an erased item restores the saved mode (0x4C2711). A later item thus changes earlier notes, against the documented ordinary mode; the port starts each line in ordinary mode. The carry-over of l_prev and the last step from the previous line is grammar.

**Builder (0x4ECDF8)**, as far as the tokens above need it: P4 of a note = 7·octave + l − 28 + k with k = 0 (treble, percussion), 12 (bass), 6 (alto), 8 (tenor) for the staff's or input clef. Chord notes sorted by 0x54C590. Limit (read, not probed): more than 200 tokens in pass 1 is an error (0x4AEFA0 → 0x52E08D).

#### Macros in pass 1

`@name n` transposes the stored notes by n steps (accidentals kept, rests unchanged): `Y[A4/B/GS]/@Y-1/@Y2` gives A4 B4 GS4 G4 A4 FS4 C5 D5 BS4. Names are any letter A–Z, including note letters (`A[C4/D]/@A`). `@name-` with no number is the plain call (0x526F23 builds a retrograde copy in the key buffer, but it does not reach R, g-p1-macro-retrograde). (g-p1-macro, g-p1-macro-transpose, g-p1-macro-names, g-p1-macro-chords)

#### Differences from Sapp's page

- `KxSF` (cancellation in flat form) is rejected. The engine's form is `KxFN` (`-17100 − x`).
- `Rn` is a centred rest (P5 = −2) with the number n in P8.
- Octave numbers 0 and 9 (and `K0`, `K8`+) are erased by the item check except in the last item.
- `,` is a separator only after an item start that passes the item check.
- `.`/`..` are typed forms of `=`/`==`. After a note `.` means `+` (octave dyad).
- `Q-`, `Q0` and in fact `Q` + anything other than `+` end cue size. `QX` is erased by the item check.
- Sapp's `./..` "after a measure or rest": the engine repeats the chord before the previous item, whatever that item is (g-p1-chord-repeat-direct: `C4:E/D:F/.` repeats C4:E).
- Not on Sapp's page: `S+/S-/S0` (P12), `RWD/RWU/RFD/RFU`, `PR`, `-AL/-TE`, `T` (last item), letter accidentals beyond four letters, `REP`, `Zn` suffix, `@name n` transposition with chords and rests, `C4M` as common time.

### Pass 2: rhythms

One value per note, chord or rest of pass 1, in order. Barlines, clefs, keys and meters take none.

#### Reader (0x422D98)

- `a`–`z` are stored as `A`–`Z`. `'` as `:`.
- `T` followed by a number is rewritten to the letter form (also by 0x4AEFA0, table 0x792484): `T8` → `TE`, `T4` → `TQ`, `T2` → `TH`, `T16` → `TS`, `T32` → `TT` (g-p2-triplet-numbers, g-p2-mid-t-number). For `T1` and `T3` the character after the digit is replaced by a space whatever it is, so `T3/QTE` becomes the single item `TT QTE` (1/12 + 1 + 1/3); `T` before another digit stays a lone `T` (`T6` = 1/3 + 4/6 = 1 quarter) (input-marks, im2-*).
- Each closed item is applied at once (0x4C4148, `X` items by 0x425722, `@` by 0x424A9F). When as many values as notes have been typed, the reader ends the pass itself. Further keys go to pass 3 (g-p2-mid-zero).
- `;` after a single value with no `/` appends `X<number of notes>`: one value sets all notes (`4;` → `4X3 ;`, `8.;` → `8.X3;`, g-p2-fewer, g-p2-fill-*). Observed rule (input-marks): a body of one or two characters before `;` after the `T` rewrite, not starting with `@` and without `/` (0x422D98 tests characters 2 and 3 for `;` at 0x424753, but a `/` that has already closed an item takes the reader past that test). So `16.;` and `4/;` do not fill (`4/;` is 4 and an empty item that repeats it), `T16;` does. With two or more values and fewer than the notes, 0x51CF40 fills the missing R entries with 64, the value of `G`, so the notes left over become grace notes (loop at 0x51D2EC; g-p2-fewer2, g-p2-fill-with-x). Values beyond the number of notes are not used.
- No item check, no erasing: a bad item reaches the parser and is rejected there.

#### Items (0x4D9EA0)

The token is the duration in quarter notes, plus 1000 per dot. The parser dispatches on the first character: a digit or `.` (number), else the table at 0x794734 `G S T E Q H W D R X .`.

| Construct | Rule | Token | Probe |
|---|---|---|---|
| number n (0x5194D5, decimals allowed) | 4/n quarters: `1` 4, `2` 2, `3` 1.333 (triplet half), `4` 1, `6` 0.667, `8` 0.5, `128` 0.03125. `.5` = `0.5` = 8 (breve), `2.5` 1.6, `0` gives inf (treated as grace) | 4/n | g-p2-numbers, g-p2-numbers-odd, g-p2-decimals, g-p2-zero |
| `n:d` (or `n'd`) | d quarters divided into n | d/n | g-p2-ratio |
| `W H Q E S D` | 4, 2, 1, 0.5, 0.25, 8 (table 0x794710: 4/value) | | g-p2-letters |
| `T` + `S T E Q H W D` | triplet: 2/3 of the letter's value. `TT` = triplet 32nd (1/12) | | g-p2-triplet-letters |
| `T` alone | triplet eighth (1/3). Only at the start of an item: `4T` is rejected | 0.3333 | g-p2-t-after-value |
| `G` | grace note | 64 (type 0.0625) | g-p2-grace |
| dots `.` after a value | each adds half of the previous addition: `4.` 1.5, `4..` 1.75, `8...` 0.9375. Also after letters, `T`, `G` and ratios (`3:2.` = 1). A digit after the dot makes it a decimal point instead (`4.5` = 4/4.5). In a run of several values the trailing dots are blanked (loop at 0x4DA3DF) and go to the run's first value: `QE.` = Q. + E = 2, `4. 8` = 2; such a sum has no thousands digit (P9 without dots). `Q.E`, `8 ./4`, `QT` are rejected, `QTE` is accepted (input-marks) | 1000·dots + value | g-p2-dots, g-p2-letter-dots, g-p2-t-dot, g-p2-decimal-vs-dot, g-p2-ratio-dot |
| several values in one item | added: `QE` 1.5, `HQ` 3, `Q8` 1.5, `4 8` 1.5 (a space does not separate, a `/` or `,` does). `G4` is 65 quarters, not a grace note | sum | g-p2-concat, g-p2-letter-number-mix, g-p2-g-then-value |
| `Xn` suffix | n copies of the value | | g-p2-repeat-item, g-p2-repeat-letter |
| `X n m`, `R?P n m` (`REP`) | group repeat as in the tokenizer | | g-p2-repeat-group, g-p2-rep |
| `@name f` | macro, f multiplies the durations (`@Z2` doubles, `@Z.5` halves) | | g-p2-macro |
| other first characters | rejected (`Y/4` at 1) | | g-p2-junk-first, g-p2-erase-junk |

After a value, the item may continue with a letter `S T E Q H W D`, a digit or `.` (added), or `X` (repeat). Any other character ends the value. What follows it is then read again as an item, which gave an extra token in the probe (`4Y/4` → 1 1 1, `4G/4` likewise). A group repeat without its count (`X2`) uses a stale number (g-p2-x-group-no-count). These cases are better rejected by a port.

**Grace note before a centred rest** (0x51CF40, grace-chord loop at 0x51E0xx; found by input-marks): after a grace note, the loop takes every following entry whose P15 word is negative as a member of the grace chord. The pass-1 builder writes that marker (−1) for chord members and also for the centred rests RW, RP, RWD, RWU and Rn (0x4EDA75). So such a rest directly after a grace note or grace chord is merged into it: P7 = 64, P4 ± 100 when |P4| < 100, P4 and P5 swapped with the head's when the rest's P4 is not above it, head P5 + 10 and head P8 from 0x4EE442 (two members: 102.996), the rest's P10 = 10; the rest rule of pass 2 then works on the swapped P5. `C4/R5/E; G/2./4` gives `1 1 2 100 8 0 65 102.996 1` and `2 1 6.83 0 -5 0 3 5 -1 10`; `C4/RW/E; G/1/4` leaves the rest at P4 101, P5 0. Ordinary notes before such a rest, and `RD`/`RU`/`R`, are not affected. Engine flaw, not grammar (D12, not ported): a rest is never part of a grace chord in the port.

**Dots in chords with displaced heads** (0x51C824, run by pass 2): for a dotted chord containing a displaced head (work-table P10 ≠ 0), the dot offsets added to P9 (1000, 100) are walked from the top down when the chord's first entry has P5 < 20 and from the bottom up otherwise. The test reads the raw work-table P5 of that entry, accidental digit and cautionary +100 included, so a cautionary on the chord's first note sends a stem-up chord down the stem-down rule: `OBS:A:GJ:F(F` dotted gives P9 + 0, 1100, 100, 1100 from the bottom, `OBS:A:GJ:FF` gives 1100, 0, 1100, 0 (g-p2-chord-dots-cautionary, g-p2-chord-dots-plain; found by input-lang). Engine flaw, not grammar (D12, not ported): the port decides the walk by the stem direction.

#### Differences from Sapp's page

- `3` is a triplet half (4/3 quarters), not a triplet quarter. `6` is the triplet quarter.
- `T` alone is a triplet eighth. `TT` (triplet 32nd), `TW`, `TD`, the `T`+number forms and dotted triplets are not on the page.
- Values can be added inside one item (`QE`, `4 8`). `.5` is a breve like `D`.
- A single value fills all notes, and the pass ends by itself after the last note's value.

### Pass 3: marks

Each item is a mark name followed by note numbers. Notes are numbered from 1 in pass-1 order. A chord counts as one note, rests, barlines and other items are not numbered (g-p3-rest-marks, g-p3-numbering).

#### Reader (0x426950)

- `a`–`z` are stored as `A`–`Z`. `'` as `:`. `~` as a space.
- A letter (any character above `@`) typed after a digit, a space or `,` gets a `/` put before it, and so does `-` (the reverse-side prefix): a new mark always starts a new item. `S 1A 2` → `S 1/A 2`, `S 1-3` → `S 1/-3` (rejected), `8VA` → `8/VA` (rejected), a leading `-` gives `/-` (sweep, g-p3-minus, g-p3-long-8VA).
- `%`, `&`, `(` are not stored (view functions, 0x52FEF6). `^` and `@` start special input.
- `+` before a mark letter is followed by an inserted `/` (`+S 2` → `+/S 2`, rejected), so `+` works only as the sign of a number.

#### Items (0x4DAEB2)

On the first item of the pass, 0x4DAEB2 first rewrites some longer spellings in the whole text (loop at 0x4DAF60). Then each item: an optional `-` (or `+`, or `=` read as `+`) sets "reverse side" (array 0x1AADA3C). The mark letters select a mark number m (table below). The token is 10000·m (negative for `N`). The note numbers follow, each appended to R: digits, `.`, a sign. A number followed by `:` gets +1000 (range start), except for marks 95–98. A letter or other character among the numbers rejects the item. The last number is the item's token returned to 0x4AF456.

| Mark | m | Result (0x4D8460) | Probe |
|---|---|---|---|
| `W` | 4 | note P11 = 4 (wedge) | g-p3-mark-W |
| `A` | 5 | P11 = 5.05 (accent) | g-p3-mark-A |
| `T` | 6 | tenuto | g-p3-mark-T |
| `S` | 7 | staccato | g-p3-mark-S |
| `WS` (W + any letter) | 8 | wedge-staccato | g-p3-mark-WS |
| `AS` | 9 | accent-staccato | g-p3-mark-AS |
| `TS` | 10 | tenuto-staccato | g-p3-mark-TS |
| `D` | 11 | down bow | g-p3-mark-D |
| `U` (U + anything) | 12 | up bow | g-p3-mark-U |
| `H` | 13 | harmonic | g-p3-mark-H |
| `FE` | 14 | fermata | g-p3-mark-FE |
| `TH` | 16 | thesis | g-p3-mark-TH |
| `M`, `MO` (M + any letter but F, P) | 17 | mordent | g-p3-mark-M |
| `I`, `IM` (I + anything) | 18 | inverted mordent | g-p3-mark-I |
| `HW` (H + any letter) | 19 | heavy wedge | g-p3-mark-HW |
| `TR` | 20 | trill | g-p3-mark-TR |
| `TRF`, `TRS`, `TRN` (TR + other letter = F) | 21, 22, 23 | trill with flat, sharp, natural | g-p3-mark-TRF |
| `PL` (P + letter other than P, Z) | 24 | plus | g-p3-mark-PL |
| `ACT` | 25 | accent-tenuto | g-p3-mark-ACT |
| `S2`, `S3`, `S4` | 26, 27, 28 | P11 = 26–28 | g-p3-mark-S2 |
| `F0` … `F9` | 30 … 39 | fingering | g-p3-mark-F0 |
| `FIF`, `FIS`, `FIN` (FI + other = F) | 1, 2, 3 | musica ficta | g-p3-mark-FIF |
| `PPP`, `PP`, `P`, `MP`, `MF`, `F`, `FF`, `FFF`, `FP`, `SF`, `SFZ` | 51, 52, 53, 54, 55, 56, 57, 58, 60, 61, 62 | code-9 item (that symbol number) at the note's x, P4 below the note (−2…−4), P15 = −0.5 | g-p3-mark-F |
| `CR`, `DI`, `R`/`RI`, `AC` | 63, 64, 65, 68 | code-9 words cresc., dim., rit., accel., below | g-p3-mark-CR |
| `PZ`, `AO` (also `AR`, `PI`) | 66, 67 | code-9 pizz., arco, P4 = 14 (above) | g-p3-mark-PZ |
| `Nk` | −k | code-9 item with symbol k. For k ≤ 49 it is placed like a note mark (0x4D9475, test `0x31 < m` for the symbol path; read by input-marks): stem up level/10 − 0.4, stem down 1 − level/10, at most 0.9, m = 5 gets 0.05 inside the staff, no sign check and no P15; for larger k like the words | g-p3-mark-N45 |
| `TM` (T + any letter but S, H, R), `TMT` | 93 | code-6 tremolo, P10 = 13 (3 strokes) | g-p3-mark-TM |
| `TME`/`TM1`, `TMS`/`TM2`, `TM3`, `TM4` | 91, 92, 93, 94 | code 6, P10 = 10 + strokes | g-p3-mark-TME |
| `OB`, `O` | 95, 96 | code-7 octave line from the first to the second number: O P4 = 12.5, P7 = 8, P12 = −1. OB P4 = −4, P7 = −8, P12 = 1 | g-p3-span-O |
| `C`, `C+`, `C-` | 97, 97, 98 | code-4 hairpin from the first to the second number (P3, P6 = x, P5 = 999). C- adds P7 = −1. Pairs: `C 1 2 3 4` gives two | g-p3-span-C, g-p3-span-several |
| `TRW`, `TRFW`, `TRSW`, `TRNW` | 120 … 123 | code-7 trill line, P5 = 1, P6 = end x + 4.167. P8 = 1/2/3 for F/S/N | g-p3-span-TRW |
| other first letters (B E G J K L Q V X Y Z, digits) | | rejected | |

Rules of the numbers (0x4D8460):

- Several numbers put the mark on each note (`S 1 3 4`). `a:b` on every note from a to b (`S 1:3`, `F 1:3` gives three code-9 items, `TM 1:2` two tremolos). The two-point marks (95–98, 120–123) take numbers in pairs, `:` being only a separator there, and reject a single number (g-p3-span-one, g-p3-trill-one).
- A fractional number is rounded to the nearest note for P11 marks (`A 1.4` → note 1, `S 2.6` → note 3, `T 3.5` → note 4) but places code-9, code-4 and code-7 items between the notes by linear interpolation of x (`F 1.5` at x = 26.75 between 2 and 51.5) (g-p3-fraction-round, g-p3-word-fraction, g-p3-span-fraction).
- Numbers beyond the last note mean the last note for note marks (g-p3-beyond); a two-point mark whose end lies beyond the last note ends at the right end of the staff (`C 3 5` with 4 notes: P6 = 200 from 0x547AE0). Fractions interpolate from the truncated note number to the next note (input-marks).
- An empty item repeats the last R entry, i.e. the last note number: `F 2//S 3` gives two F items at note 2 (input-marks).
- Digits typed directly after a mark letter belong to the name: `S1 2` is SF on note 2 (S + any adjacent character but 2–4 = SF), `A2 3` is an accent on note 3 (input-marks).
- `-` before the mark: P11 negative (stem side) for note marks. Code-9 marks go above (P4 = 14) instead of below. No effect seen on tremolos (g-p3-minus, g-p3-word-minus, g-p3-tremolo-minus).
- A note has one P11: a later mark on the same note replaces the earlier (g-p3-same-note-twice). On a chord the mark goes to its first note (g-p3-chord-mark).
- `@name n`: the stored marks with their note numbers shifted so that note 1 of the motive is note n (`Z[S 1/A 2]/@Z2` adds S 2, A 3) (g-p3-macro).

**Longer spellings** (rewritten before parsing, 0x4DAF60, observed): `DC` = `C-`, `HA` = `H`, `HV` = `HW`, `PI` = `PZ`, `AR` = `AO` (so the arsis accent, m = 15, cannot be typed), `TREM` = `TM`, `TRILL` = `TR`, `TRILLW` = `TRW`, `RIT` = `R`, `DIM` = `DI`, `DN` = `D`, `UP` = `U`, `ACC` = `A`, `ACCS` = `AS`, `WES` = `W`, and `TE…` reads as a tremolo (`TEN` = `TM`, `TES` = `TMS`). Rejected: `ARCO`, `PIZZ`, `TENUTO`, `STACC(ATO)`, `WEDGE`, `FERM(ATA)`, `CRESC`, `DOWN`, `ACCENT`, `ACCEL`, `ACL`. `8VA`/`8VB`/`8BA` would read as `O`/`OB`, but the reader splits them (g-p3-long-*).

#### Differences from Sapp's page

- `AR` is arco, not the arsis accent. `C+` is the same as `C`. `IM`, `MO`, `RI` are accepted because only the first letter counts there.
- `TM` alone is a three-stroke tremolo (like `TMT`, `TM3`).
- Note numbers count notes and chords only. A fractional number is an offset only for code-9/4/7 marks.
- `-` reverses note marks (P11 < 0) and moves dynamics and words above the staff.
- Not on Sapp's page: `S2`–`S4`, `TH`, `TM4`, the long spellings, `@name n` with a note offset.

### Passes 4 and 5: beams and slurs

Both passes use the item parser 0x4DA9C3. The builders are 0x413CA8 (beams) and 0x53D1E0 (slurs). Notes are numbered as in pass 3: notes and chords, not rests (g-p4-chord-rest). The reader (0x427C68) upper-cases letters. `,` separates as `/` (g-p4-comma, g-p4-lower).

#### Items (0x4DA9C3)

| Construct | Rule | R | Result | Probe |
|---|---|---|---|---|
| `a b` | two numbers (0x5194D5). A third is ignored (g-p4-three-numbers) | a, b | pass 4: code-6 beam from note a to b (P3 x_a, P4/P5 the notes' P4, P6 x_b, P7 = 11 above / 21 below). Pass 5: code-5 slur | g-p4-pair, g-p5-pair |
| `b ≤ a`, a single number | the end is the next note: `1 1`, `4 1` (→ 4 5). A single number reads its partner past the `/`: it takes the first number of the next item (`1/-4 7` gives the pairs 1 −4 and −4 7, so a beam 1–4 below and 4–7 below; `1/5` gives 1–5 and 5–6), and only in the last item it gets 0, i.e. the next note (`1` → 1 2, `4 7/1` → 4–7 and 1–2). Same in pass 5 | 1, −4, −4, 7 | | g-p4-same, g-p4-reversed, g-p4-single, g-p4-single-then-pair, g-p4-single-then-single, g-p4-pair-then-single, g-p5-same, g-p5-single-then-pair |
| `+` before either number | 10000 added to a: beam above, slur arched up | a + 10000 | | g-p4-plus-*, g-p5-plus* |
| `-` before either number | the number is negative (sign of 0x5194D5): beam below (stems down), slur down | −a or −b | | g-p4-minus-*, g-p5-minus* |
| `k·100 + a` | pass 4: number k over the beam (P8 = k), on either number (`301 3`, `1 304`). Pass 5: tuplet bracket over a…b, P8 = 3, P9 = k, where k = (n div 100) mod 100 and a = n mod 100 | | `503 7` = quintuplet over 3–7 | g-p4-number, g-p5-tuplet-* |
| `0 b`, `a 99` (pass 5) | slur from the left edge (P3 = x_b − 8) / to the right edge (P6 = 198.5) | | | g-p5-from-left, g-p5-to-right |
| fractions | pass 4: truncated (`1.5 3` = `1 3`). Pass 5: the slur end is moved between the notes | | | g-p4-fraction, g-p5-fraction |
| `nB`, `nBp` (pass 4) | automatic beams over groups of n eighths, skipping p notes first. Found by scanning the first 10 characters of the pass for a digit followed later by `B` (not `B[` or `@…B`). The parse then ends (0x4DA9C3 returns 999). A sign before n is lost (`+2B` = `2B`). Anything after it in the pass, even `/1 2`, leaves no beams at all. A pair before it is read as the auto form (`1 2/4B` = `1B2`) | 9999, n, p | | g-p4-auto*, g-p4-auto-then-slash, g-p4-pairs-then-auto |
| `B` or `A` alone (pass 4, first character) | automatic beams by the last meter (0x78D918/0x78D91C): `2B` for x/4, common time or no meter. `4B` for x/2 and cut time. `8B` for x/1. For x/8: `2B` if x is 2, 4 or 8, `3B` if x is 3, 6, 9 or 12. Other meters: no beams | | | g-p4-auto-b, g-p4-auto-meter-* |
| `@name n` | motive with note numbers shifted so that note 1 is note n (0x4E620C) | | | g-p4-macro, g-p5-macro |
| `Xk n1 n2 …` | 0x4E4D40 turns it into the pairs (n, n + k − 1) for each n: `X3 1 4 7 10` beams 1–3, 4–6, 7–9, 10–12, `X2 1 4` beams 1–2, 4–5; it may follow other items (`1 2/X2 4 6`). The reader puts a `/` before a typed `X` and drops a typed `X1 ` altogether, so `X1 1 3` is the pair 1 3. Overlapping beams are all kept (`1 3/2 4`, `X3 1 2`) | | | g-p4-x, g-p4-x-first, g-p4-x-groups, g-p4-overlap |
| `1-2` | read as the number −12 (no beam) | | | g-p4-dash |
| centred rests under beams | Engine flaw, not grammar (D12, not ported): pass 2 stores duration 0 in the beam duration list 0x204929C for every entry with the chord-member marker, and the pass-1 builder gives that marker to RW, RP, RWD, RWU and Rn. Automatic beaming (0x410FD8) therefore does not count their time, and beams run across them as if they were chord members (rnd-4-24 `3B`: E–C across RI and RW; rnd-4-28, -37, -63; found by input-lang) | | | |
| notes with P12 (S+/S-) | 0x41A776, used by the beam builder 0x413CA8 and by the note lookup 0x41A4F9 of beams and slurs: the level gets the distance to the other staff added, (STAFF_Y0[s ± 1] − STAFF_Y0[s]) / (7·STEP) scale steps with s the IN staff (staves without a code-8 item at their default positions, staves.md). If that staff cannot exist (P12 = 2 on staff 1, P12 = 1 on staff 256) the note's P12 is set to 0 instead, so a beamed or slurred S- note on staff 1 loses its P12. In a beam whose stem direction is not given, a P12 note gets stems down for P12 = 1 and up for P12 = 2 (0x4156EC). For a chord, the beam builder and the lookup apply 0x41A776 to the chord's last entry only (they step over the following entries with duration 0), so a chord head keeps its P12 even where a single note would lose it. The stem fit (0x40CDE4 → 0x40C1C0) shifts the level of every item with P12 ≠ 0 by (STAFF_Y0[s ± 1] − STAFF_Y0[s]) / (7·STAFF_STEP0[s]), s = the item's staff, without the existence check: for S- on staff 1 it measures to the table entry of staff 0, which lengthens the stems of beamed chord heads that kept P12 = 2 (rnd-4-67: +23.25). S- on staff 1 and S+ on staff 256 have no staff to go to; the engine's handling of them is inconsistent | | | rnd-4-123 (input-lang) |
| note numbers beyond the last note | 0x41A14C clamps the end to the last note but not the start, which then reads the empty slot before note 1 (x 0, level 0.5); 0x53D1E0 sees the unclamped end and draws an edge tie (P6 = right end, P8 = −2). Invalid input, not grammar (D12) | | | g-p5-tuplet, g-p5-tuplet-12, g-p5-tuplet-sapp |

#### Differences from Sapp's page

- `+2B`/`-2B`: the sign is ignored. Automatic beaming must be the only item of the pass.
- Tuplet numbers are k·100 + start note: Sapp's `5013 17` gives a bracket numbered 50 from note 13. A quintuplet over 13–17 is `513 17`. Sapp's "X0Y" reading holds only for start notes below 10.
- Not on Sapp's page: `B`/`A` (beams by meter), numbers over beams (`k·100 + a`), the "next note" reading of `a a`, `b < a` and a single number.
