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

## Creation defaults

Filled in from the catalogue run (section below once complete).

## Catalogue

`data/commands.tsv`, one row per command and context: command, context (new / note), status returned by the interpreter, items added (P lists), note before → after, number of base items removed or replaced, and the engine routines the interpreter called directly. Routines called for every command (0x54943A, 0x549449, 0x54E2A1, the C++ callback 0x59D020, the Fortran runtime 0x5F33C9/0x5F34D1/0x5F4660) can be ignored when reading the handler column.
