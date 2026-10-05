# The command layer

How typed and menu commands change the score. Sources: Smith's help (`edit.txt`, `letters.txt`, `groupedit.txt`; cited as such), the interpreter 0x47EC50 and its handlers, and a catalogue run of every distinct command string that WinScore's menus and toolbars send (`analysis/data/command_map.tsv`, 1,298 strings) through the emulated engine: `experiments/command_catalog.py` → `data/commands.tsv`. Each command ran in a fresh engine on a small base score (`experiments/cmdlab.py`: staves 1–2, treble clef, a note `1 1 30 5 10 0 1` as item 4, a rest, a barline), once with nothing selected ("new") and once with the note selected (`I 4`, "note"), followed by `X`; the table records the items added, the note before → after, and the engine routines the interpreter called directly. A row of that file is **verified** behaviour for that context only.

## How a command reaches the engine

The shell copies the command word into COMMAND (0x7A0B7C) and the typed line into the line buffer (0x9AE2BC), then calls the interpreter (ARCHITECTURE.md). Menu entries send fixed strings, often with trailing blanks, which do not matter. Mouse actions use `~`, `~x`, `~v`, `~s`, `~t` with coordinates in globals (editing.md).

## Interpreter dispatch (read, partly verified)

1. **Three-letter item words** (table at 0x7911EC, 96 entries of 3 characters: `NOT RES CLE LIN SLU BEA BAR STA LIB NUM CRH DCH KSI MET END END 8VA 8BA 15M TRI ARP BOX CIR GUI TIE BRA PPP PP P MP MF F FF FFF DCR FP SF SFZ CRS DIM RIT PIZ ARC ACL WED ACN TEN STA WED ACN TEN DNB UPB HAR FER MEN PIU MOR INV HVW PLU ACT ATM MOL ESP GLI SUB RAL LOG TUR PED POC TRE BAS ALT PER CUT COM DAS USE POS AST WNO HNO ENO SNO WRE HRE ERE SRE OVA OBA OMA ACC CR- DC-`): the first three letters of the command are compared with this table, and a match goes to `create_by_mnemonic` 0x580B70, which appends an item with that word's defaults and puts it into edit mode (EDIT_ITEM = the new item). The words are documented in `letters.txt` (e.g. `ACN (x y z) = accent, Code 9, P5 = 22`).
2. **First letter A–Z**: a switch in the interpreter sends the remaining commands to per-letter handlers; examples: A → 0x40F003, B → 0x54AAF8, I → `cmd_I` 0x4AFB68 (I n, II, IN), L → LJ/LI via `cmd_lineup` 0x4B7AD8, O → 0x4F7808, S → 0x53EC10, V and X → 0x536ADC (X ends edit mode).
3. **Numbers** (verified): with nothing selected, a line of numbers creates an item with those numbers as P1, P2, P3, ... (`4` creates `4 0 0`, `1 200` creates `1 200 0`) and enters edit mode on it. With an item in edit mode, the numbers are pairs (next section).

## Edit mode (verified unless marked)

Entered with `I n` (item n), by creating an item, or by clicking (editing.md). While an item is in edit mode its parameters live in the edit buffer E(k) at 0x20B9440 + 4(k-1); the store is written when the item is left (`X`, `Enter` for the next item, another `I`). `DE` deletes the item (verified: the note disappeared); `AB` aborts the changes (help).

Parameter commands, handled by `edit_params` 0x46D088 (the forms are from `edit.txt`, the effects verified in the catalogue):

| Form | Effect | Example (on the note `1 1 30 5 10 0 1`) |
|---|---|---|
| `p v [p v ...]` | Pp = v | `5 20` → P5 = 20; `1 9 5 112 6 0 7 0 8 0 9 0` turns the note into symbol 112 (`9 1 30 5 112`) |
| `-p` | Pp = -Pp (help) | |
| `p00 d`, `/p d` | Pp += d | `/4 1` → P4 = 6; `/5 -10` → P5 = 0 |
| `p0000 q`, `//p q` | Pp = Pq (help) | |
| `p v/` | as `p v`; the trailing `/` does not change the result | `2 4/` → P2 = 4 |

Parameters beyond the item's length extend it (zeros in between): `/19 .5` on the 7-parameter note gives 19 parameters.

Moves (`edit_letters` 0x45EF21 and `edit_params`): `R n`/`L n` add/subtract n to P3, `U n`/`D n` to P4 (verified for the note: `R1` → P3 + 1, `U1` → P4 + 1). For items with two ends the right end moves too (verified for code 4: `U1` → P4 and P5 + 1). The help adds: L or R alone repeats the last increment, a doubled letter moves by 0.5, a tripled one by 0.2, and `RI`, `RC`, `RP` (and U/D/L variants) move by inches, centimetres or points; editor-core found that one inch is 1/f32(0.00025) engine units computed in double (numerics.md).

## Creation defaults (verified)

With nothing selected, these words append one item (on staff 1, the lowest staff, in the base score) and enter edit mode on it:

| Command | Item | Command | Item |
|---|---|---|---|
| NOTE | `1 1 100 1 10 0 1` | REST | `2 1 100 0 0 0 1` |
| CLEF, TREB | `3 1 2` | BASS / ALTO / TENOR | `3 1 2 0 1` / `... 0 2` / `... 0 3` |
| BAR | `14 1 100 1` | BARD / BARH / BARL / BARR / BARRD | P5 = 1 / 2 / 3 / 4 / 5 |
| SLUR | `5 1 100 14 14 120 3 -1` | TIE | `5 1 100 14 14 120 3 -2` |
| BEAM | `6 1 100 8 8 120 11` | LINE | `4 1 100 0 0 120` |
| CRH (crescendo hairpin) | `4 1 100 -1 999 120` | DCH | `4 1 100 -1 999 120 -1` |
| TRILL | `7 1 100 15 0 120` | STAFF | `8 3 0` (the next free staff number) |
| METER | `18 1 100 0 4 4` | KSIG | `17 1 100 0 2` |
| NUMB | `10 1 100 13 1` | BOX / CIRCLE | `12 1 100 15 0 10` / `12 1 100 15 1 10` |
| GUIT | `12 1 100 16 -4 0 10` (then waits for input) | | |

The other item words and their help definitions are in `letters.txt`; every menu string's result is in `data/commands_summary.md`.

## Edit commands on a note (verified)

On the note `1 1 30 5 10 0 1` (P5 = 10: stem up, no accidental):

| Command | Result | Meaning |
|---|---|---|
| FL, SHP, NAT, DBF, DBS | P5 = 11, 12, 13, 14, 15 | accidental digit of P5 |
| FLI | P5 = 20 | flip the stem (tens digit of P5: 1 up, 2 down) |
| NST | P5 = 0 | no stem |
| ENH-1 / ENH+1 | P4 5 → 4 and P5 15 / P4 → 6 and P5 14 | enharmonic respelling one step down / up (double sharp / double flat) |
| STM / STP | P8 = -0.5 / +0.5 | shorter / longer stem |
| RHW, RHH, RHE, RHS, RH32, RH64 | P6/P7/P9 = (2, 4, -), (1, 2, -), (0, 0.5, 1), (0, 0.25, 2), (0, 0.125, 3), (0, 0.0625, 4) | rhythm: head type P6, duration P7, tails P9 |
| RHD | P6 = 3, P7 = 8 | double whole |
| RHG | P4 + 100, P7 = 65, P8 = 101, P9 = 1 | grace note (cue size, slashed stem) |
| DOT / DDT | P7 × 1.5 / × 1.75 with P9 = 10 / 20 | dots |
| TRP | P7 = 0.6667 | triplet value |
| CUE | P4 + 100 | cue size |
| SPD | P9 = 0.05 | dot offset |
| NOS | P13 = 0.5 | (see help) |
| SZ1 | P15 = 1 | size factor |
| U1 / D1 / L1 / R1 (also 10) | P4 ± 1 / P3 ± 1 | moves |
| DE | the item is deleted | |

Commands such as RHQ, CUX, STN, NAC change nothing on this note because it already has that state; group commands (C, CC, CX copy, M move, DE on a region) prompt for further input and do nothing in a single step.

## Handlers by first letter (verified from the traced calls)

| Commands | Routine |
|---|---|
| number lines (new item) | 0x449B86 + `cmd_I` 0x4AFB68 |
| parameter pairs in edit mode | `edit_params` 0x46D088 (with `edit_letters` 0x45EF21 for `/p d`) |
| item words | 0x449B86 + `cmd_I` + `create_by_mnemonic` 0x580B70 |
| A..., edit-mode letters (AB, AC, ADJ, ...) | `edit_letters` 0x45EF21 |
| B... (BB, BK, BNUM, BRL, ...) | 0x54AAF8 |
| D... (D, D1, DBF, DBS, ...) | 0x45D278 |
| F... (FL, FLI, FILL, ...) | 0x493E10 |
| J, JR, JT, L... (LJ, LI, LBR, ...) | `cmd_lineup` 0x4B7AD8 |
| K1F/, K1S/, ... | 0x54B6C2 |
| M (group move), MD... (MIDI) | 0x4E7BA6, 0x4A1240 |
| N... (NAC, NAT, NOD, ...) | 0x4F3DB0 |
| P..., LAY, PATHX | 0x510B90 |
| R..., R1, R10 | 0x522BD8 |
| S..., SA, SC | 0x53EC10 |
| TRM1–12 | 0x55B1F8 |
| W..., WB1–9 | 0x54C15E |
| X | 0x536ADC |

## Catalogue

`data/commands.tsv`, one row per command and context: command, context (new / note), status returned by the interpreter, items added (P lists), note before → after, number of base items removed or replaced, and the engine routines the interpreter called directly. Routines called for every command (0x54943A, 0x549449, 0x54E2A1, the C++ callback 0x59D020, the Fortran runtime 0x5F33C9/0x5F34D1/0x5F4660, and 0x48ECFB/0x518448 for the parameter display and redraw) can be ignored. `data/commands_summary.md` (from `experiments/command_summary.py`) lists, for all 1,298 strings, the items created with nothing selected, the change to the selected note, the commands without visible effect, and the routines grouped by command family. 49 runs stopped because the command waited for further input (prompts, dialogs); those rows show the state up to that point.

Not covered: commands whose effect needs a selection of another item type (barline, slur, beam, text), group edits over regions, and file commands. `cmdlab.py` runs any such sequence in a few seconds.

## Command families for the port

Notes for editor-core, grouped so that a family can be ported at once. Each entry names the routines, says which parameters change and when nothing happens. Confidence as elsewhere: **verified** (oracle comparison, script named), **read** (decompilation, not compared).

### Beam stems: ADJ, ADX, ADF (verified, `experiments/beam_stems.py`, 90/90 bit for bit)

With a beam (code 6) in edit mode, words are matched by their first two letters against the table at 0x78F78C (`AD`, `AU`, `BE`, `SP`, `CU`, `LO`, `RO`, `BN`, `PB`, `TR`, `NL`, `NU`, `FL`, `TH`, `TM`) in the beam branch of 0x43D0B0. `AD...` calls 0x40CDE4, which recomputes the stems of the beam's notes with 0x40C1C0. Without an edit item, `ADJ` (0x40F003, second letter D) asks for an area and runs 0x40CDE4 on every beam of staves P2..P5 with P3 <= beam x <= P4 (P4 = 0 means RIGHT; **read**). AUTO and SPL (below) end in the same stem pass.

A note takes part when it is code 1 with at least 5 parameters, on the beam's staff, with P3 in [beam P3 - 0.1, beam P6 + 0.1], has a stem digit (tens of P5 mod 100 = 1 up, 2 down), P6 != 1, its stem direction equals the beam's (tens digit of P7) **or the word's third letter is X**, and trunc(P4/100) has the same absolute value as for the beam (cue notes go with cue beams). Beams with P7 < 0 are skipped. For each such note:

```
size  = 0.6 if abs(trunc(beam P4 / 100)) > 0 else 1         # cue beam
h     = f32(size * f32(2.83333) * STEP / 25)                 # head width; STEP of the staff
up stems: note x += h; if the beam points up (P7 tens = 1), both beam ends x += h
beams = P7 mod 10;  extra = f32((beams - 1) * 1.5)
L0 = f32(amod(beam P4, 100) - note P4m),  L1 = f32(beam P5 - note P4m)     # P4m = amod(note P4, 100)
down stems: L0, L1 = -L0, -L1
level = f32((x - x1) / (x2 - x1) * (L1 - L0) + L0)
same direction:     P8 = f32(add + level / size)
opposite (ADX):     P8 = f32(add + ((extra + level / size) - 14) + f17)      # f17 = beam P17 or 1, * 0.8 for cue beams
ADF (French), notes not within 0.1 of either end: P8 = f32((P8 - extra) - cut)
```

`add` and `cut` are the secondary-beam corrections from P10/P13 (beam 2 and 3 levels, ranges P11..P12 and P14..P15, -1 meaning the beam's end), P14/P15 = 10 or 20 shift the ends by +h/-h, and the digits of P9 (hundreds: ends, tens: beam 2, units: beam 3) shift by -h for up beams and +h for down beams; `beam_stems.py` has the exact order. A cross-staff note (P12 != 0) converts its P4 to the beam's staff first (staff y difference / (7 * STEP)). Then P8 is divided by the note's P15 if non-zero, the note is extended to 8 parameters, and P9 loses its units digit (the flags of a beamed note). Example (editor-core's): beam `6 1 100 13 15 120 11`, down-stem note at 110 with P4 8 under ADX: x1 = 102.8333, level = -5.71667, P8 = -5.71667 - 14 + 1 = -18.71667.

### Other beam words in edit mode (read, 0x43D0B0)

| Prefix | Effect |
|---|---|
| `AU` (AUTO, AUTOX) | secondary beams from the notes' durations, see below |
| `SP` (SPL1..4, SPL222) | secondary beams with breaks, see below |
| `BE` | P8 = trunc(P8/10)*10 + (number or 1); `BE+` adds 1 |
| `CU`, `CUX` | P4 +- 100 (cue beam on/off) |
| `LO`, `RO` | P14 / P15 = 20 (M), 10 (P) or the number |
| `BN` | P9 = number, `BNP` adds 1 |
| `PB` | P10 or P13 from the digits of the given parameter |
| `TR`, `TM` | P8 = -10, P11 = number + 10 (tremolo) |
| `NL`, `NU` | P17 +- 0.02, P20 +- 0.2 (0 with a final 0) |
| `FL` (FLR11, FLR14) | P12 or P15 = 999 |
| `TH` | P18 = number, `THM` subtracts 0.05 |

### Secondary beams: AUTO, AUTOX, SPL1..4, SPL22, SPL222 (verified, `experiments/auto_beam.py`, 175/175 bit for bit)

On a beam in edit mode, 0x43D0B0 sets P2 = 99 (AUTO), 98 (AUTOX) or, for SPLn, P1 = 8 and P2 = -n (two-digit n becomes -(10n + 9)) and calls 0x417738:

1. **Notes**: code 1 on the beam's staff with P7 > 0, at least 7 parameters and P3 within the beam's ends +- 0.04, whose stem digit equals the beam's direction (any stem for AUTOX, or P12 != 0). The first note decides cue or normal size: the beam's P4 is moved into the same range (+-100), and notes of the other size are skipped. Durations: P7 (64 or more counts as 0.25), divided by 1.5 or 1.75 for one or two dots (tens digit of P9); the scan stops at the first note longer than 0.5001. Beam count per note: 1 down to 0.2501, 2 down to 0.1251, 3 down to 0.0626, then 4, 5, 6 (limits 0.0313, 0.0157). With fewer than two notes the beam flips direction once (P4, P5 +-13) and tries again; otherwise nothing changes.
2. **SPLn** inserts a pseudo-note with count 1 at 0.2 after the given notes, so that the inner beams break there: Rows are counted with the pseudo-notes already inserted: n < 100 breaks after row n; for n = [d]hte (`split_points`) after rows d, b = h + d (+1 if d > 0), c = b + t + 1 and c + e + 1, so SPL222 breaks after rows 2, 5 and 8, i.e. after every second note. A hundreds or tens digit 0 means no change. SPL does nothing when P13 = 0 and P14 or P15 is set, or when the beam equals the item before or after it in P1..P6 (a second-level beam item).
3. **Result**: notes sorted by x (the last of equal x first); P7 = direction*10 + smallest count, P3 and P6 = first and last note x. If all counts are equal, P8..P15 become 0. Otherwise the first run of the next count goes into P10 (code smallest*10 + next - smallest, e.g. 11), P11 and P12 (start and end x; 0 and -1 when the run is only the last note; start and end exchanged when the run begins after a note of lower count), the next run into P13..P15, and the item is cut to its last non-zero parameter. Further runs go into new beam items inserted after it (copies of the beam with their own P10..P15).
4. AUTOX then writes P9 = digits for the ends (hundreds), beam 2 (tens) and beam 3 (units) where a note with the opposite stem sits (1 start, 2 end, 3 both; 0x419498), into the last item written. Last, the stem pass of ADJ (ADX for AUTOX) runs with the edit buffer, which at that point holds the last item written.

### Slur ends: CV, CNL, CNR (verified, `experiments/slur_center.py`, 355/355 bit for bit)

On a slur (code 5) in edit mode these words reach 0x42C9B0 (second letter V or N), which writes (parameter, value) pairs into the globals P1..P8; the word is then turned into a parameter command and edit_params applies the pairs. A changed item is stored up to its last non-zero parameter (so a trailing P8 = 0 disappears); an item without pairs is left as it was.

- **CV**: P3 moves to the x of the nearest note or rest of the slur's staff (0x42DAF8; the slur itself excluded, the first of equal distances), then P6 likewise; if both land on the same note, P6 is moved 2 to the right and searched again (up to RIGHT - 0.5, where P6 becomes RIGHT). The levels P4 and P5 come from the end notes (0x42E11C/0x42E437), the highest of each end's chord for slurs above (P7 >= 0), the lowest for slurs below: `v = P4 mod 100`; above: `v + 2` if the note's stem points down, else `v + 8.4 + len`; below: `v - 2` if the stem points up or there is none, else `v - 8.4 - len`; `len` = P8 mod 100 of the note (-6 without stem) plus 2 per flag beyond the first (P9 mod 10 - 1); the 8.4 term times 0.6 for cue notes. A level that is an odd integer inside the staff (below 12 above, above 2 below) moves one step outwards (0x42C60E). If both ends are the same note: P4 = P5 = (note P4 mod 100) +- 1. With P8 = -2 or -3 both levels become a value derived from the chord step nearest to P4 (0x42D887). If the nearest note lies right of the slur's end (the end left of the start), the pairs are (6, start note x) and the start note's level for P4 (P3 is kept).
- **P8 = 1 or 2** makes CV look for barlines instead of notes, with ends at the barline (minus 2.3 or 1 staff steps) or the old P3. With no barline on the staff the engine runs off its pair list and walks P6 rightwards until unrelated memory stops it; the result is not defined, and a port should leave the slur unchanged.
- **CNL**: P3 = first note x of the staff - 0.2 * STEP (0.38 * STEP, at least 6, when P8 < -1); P6 = x of the note nearest to P6 (the last of equal distances; 0x42E82D).
- **CNR**: P6 = x of the last barline of the staff (or of a barline spanning it with P4), minus 0.6 + 0.056 * STEP when P8 = -1; P3 = x of the note nearest to P3. Without a barline nothing happens (editor-core's observation).

### Rests with numbers: WB, EU (verified in the oracle, read in 0x4359D0)

On a rest in edit mode: `WBn` sets P5 = -2 (-5 when n >= 4), `EUn` sets P5 = -10 - n; both set P8 = n, P9 = -1 and P6 = 0. `...M n` / `...P n` subtract or add n to P8, `NON` sets P8 = 0. The values that then appear in P9 (and P6 for European rests other than -6) are written by the redraw (draw_rest 0x519C38, layout.md §8); score-render already computes them (`codes/rest.rs`: `centre`, `edit_p9`, and the edit-buffer P6).

### ASP and the spacing words on a note (read in 0x4359D0, checked in the oracle)

0x4359D0 matches note and rest words by their first two letters (table at 0x78F3DE: PR WI EN MK RH TR DO DD CU SP AS NO ST FL SH NA DB AC AD NT DU LO RO NS CH OF TM FC) and a set of three-letter words (0x78F415: FCF FCS FCN W AC TN STA WST AST TNS DNB UPB HAR FE ARS THE MO IMO HW TR TRF TRS TRN PLU ACT SO2 SO3 SO4 FNG FG1..FG6), most of which set the mark code P11. `ASP` (prefix AS): if the note has an accidental (P5 mod 10 != 0), P5 = trunc(P5) + 0.22 (0.26 for a flat, P5 mod 10 = 2), i.e. the accidental moves 2.2 (2.6) steps left; without an accidental P13 += 0.5. Observed: chord `1 1 30 5 13 0 1` + `1 1 30 7 1 0 1`, ASP on the first gives P5 = 13.22; a single `1 1 30 5 10 0 1` gives P13 = 0.5.

### Group re-input: FLU, FLD, FLI, FLN, FLA, FLV (read; modes checked in the oracle)

`FL?` without an edit item goes 0x493E10 -> 0x494302: area answer, sort, then for every staff P1..P4 of the area 0x47C3E8(mode) on the x range P2..P3 (P3 = 0 means 200). Third letter: `I` 1 (invert every stemmed note), `N` 2 (no stem codes: automatic stems; the slur pass is skipped), `D` 3 (all stems down, pass-1 code 5020), `U` 4 (all up, 5010), `A` 5 (only the stem pass 0x40CDE4 with P2..P5 = the answer), `V` 6 (0x443B70, the CV routine). TR uses mode 2.

0x47C3E8 feeds the staff's notes back through IN's passes: pitches (input_pitches, with the stem codes, cue toggles 8000/8001 and pitch codes acc*100 + 1028 (7028 above P5 = 100) + P4 mod 100, negative for chord members), rhythm (dots*1000 + min(P7, 64)), marks 0x4D8460 (from P11), beams 0x413CA8 (via 0x47DC96/0x47E0A9), slurs 0x53D1E0 (not in mode 2), then writes P4, P5, P8, P9, P10, P11 of every note back from the work table and runs the stem pass 0x40CDE4 over the staff. It changes nothing when a beam has P7 < 0 or reaches beyond the range (message with its item number), a beamed note has 0.99 <= P7 < 64, there are more than 99 notes, two stemmed notes share an x, or a stemless note (P5 mod 100 < 10, P6 not 2, 3 or > 10) has no stemmed note at its x. Notes with P10 mod 10 != 0 are left out.

**Reference model** (verified, `experiments/refit.py`): everything of 0x47C3E8 except the five IN pass routines, checked against the oracle with FLU, FLD, FLI and FLN on random staves (beams, second-level beams, slurs, chords needing the stem swap, cue notes, dots, marks, aborts): 60/60 identical, streams compared at every pass entry and final items bit for bit with the engine's work-table rows fed into the write-back. Details the model settles:

- The streams are f32 values in 0x1FB8CC0 (count as an int in word 0): stem code 5010 (up) or 5020 (down) before the note, 8000/8001 when the note size changes (cue = abs(P4) >= 100; grace notes, P7 >= 64, do not toggle), pitch code acc*100 + 1028 (7028 when P5 > 100) + P4 mod 100, negated for chord members. FLI writes the opposite of each note's stem, FLN none. A stemless note (P5 mod 100 < 10, not a chord member, P6 not 2, 3 or > 10 except 95, 139) is swapped with the next stemmed note at its x.
- During the pitch pass 0x1BE12E0 = 1, so input_pitches uses clef offset 0 instead of the staff's clef: the code decodes back to P4 exactly (P4 mod 100 >= 72 overflows into the accidental digit). The pass number 0x1FBB700 is 0 for pitches, rhythms and marks, 4 for beams and 5 for slurs, which selects the IN pass 4/5 branches of the shared routines.
- Rhythms: f32(dots*1000) + min(P7, 64) per rhythmic note, dots = tens digit of P9. Marks: pairs (abs(P11)*10000 + (1 if P11 < 0), note number), the first value rounded to f32 (200000001 becomes 200000000).
- Beam and slur links (0x47DC96): rows 1..n get the notes' P3; for each beam or slur the first and last rhythmic note whose trunc(P3) is within 2 of trunc(P3) or trunc(P6) of the beam/slur (the last match wins). In pass 4 a beam at the same trunc(P3) as the previous one is skipped (second-level beams), a repeated pair is skipped, and a beam whose ends are not found gets a message and is skipped.
- Write-back (0x47E0A9): rows after the notes, matched to beams/slurs by equal P3, give P5, P4 and P7; beams keep their units digit (number of beams) and take the direction digit of the row; slurs take the row's P7 (0x42C51C reads the edit buffer and writes the P1..P3 globals, so it does not change the slur). Then every note, extended to 11 parameters, takes P4, P5, P8, P9, P10, P11 from its row. A beam followed by second-level beams at its x is restored from the copy taken at collection (undoing the end snaps) with the new P4, P5 and direction, and its second-level beams get the same P4, P5 and direction. Last, the stem pass 0x40CDE4 over the staff (P3 = 1, P4 = RIGHT) recomputes P8/P9 of all beamed notes (`beam_stems.py`).

### TR helpers (read)

- 0x4EC885 adds a key signature when TR needs one: on the current staff it looks at items 1..ITEM_I-1 (the last item is never examined); at the first clef, x = f32((P3 of the next item in file order - clef P3) / 2 + clef P3) (the clef's P3 if that item has fewer than 3 parameters); without a clef, the smallest P3 of the staff's items + 1. It appends `17 staff x 0 n p6` (n = new number of accidentals).
- Code 13 is TR's deletion mark: 0x5611DA sets P1 = 13 on every clef of the staff after the first, 0x561B90 on keys left without accidentals, and 0x55E50B removes every item whose P1 is exactly 13 (on all staves, including any that were in the file before) at the end of TR.
