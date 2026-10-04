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
