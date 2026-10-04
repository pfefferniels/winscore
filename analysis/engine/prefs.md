# Preferences (scorlib/PREF.DAT)

PREF.DAT is a text file of keyword lines, read at start-up by 0x4A830B (called from 0x4A7440 under `engine_init`). Only the first four letters of a keyword count; the table at 0x7921C0 holds `METR INCH BEAM BMTH REST DASH MIDK PROC SETS TIES DYNA SLUR AFTC AFTB AFTK AFTM XDAS SYMB FONT VER PAPE IDSC ADOB ARRO FULL PRNT TXTD EDPT NSLR`. 0x4AAC7D and 0x4ABC64 hand the values to and from the preferences dialog.

Values with the bundled file, traced during start-up (**verified**: the write and its value); the role column is **inferred** from the help or the use unless stated:

| Line in PREF.DAT | Global | Value | Role |
|---|---|---|---|
| `INCHES` (METR / INCH) | int 0x78B4E8 | 0 | metric flag: staff P10, P8 and box sizes divide by 2.54 when 1 (read in draw_staff, draw_box) |
| `BEAM 10.00` | f32 0x78B470 | 0.1 | BEAM/100 (read in 0x4A830B) |
| `BMTH -2` | int 0x78B478 | -2 | beam thickness; draw_beam passes it to the print pen routine 0x4D4ED2 when printing |
| `REST 6` | int 0x78B474 | 6 | |
| `TIES 0` | int 0x78B4A4 | 0 | |
| `SLUR 0.75` | f32 0x78B48C | 0.75 | default slur thickness: draw_slur uses it when P13 == 0 (then P13 <= 0 becomes 1) (read) |
| `MIDK C2` | int 0x78B4A8 | 36 | MIDI key number of C2 |
| `DYNAMICS -0.50` | f32 0x78B488 | -0.5 | |
| `AFTC 1.80`, `AFTB 1.50`, `AFTK 2.80`, `AFTM 0.90` | f32 0x78B490, 0x78B494, 0x78B498, 0x78B49C | 1.8, 1.5, 2.8, 0.9 | space after clef, bar, key signature, meter (by name) |
| `XDASH 0` | int 0x78B4A0 | 0 | used by 0x42BD1F/0x42C1ED (limits a dash length when != 0 and no item is being edited) |
| `VER 5.00` | f32 0x78DC80 | 5.0 | |
| `PAPER 2` | int 0x791638 | 2 | PAPER of the page frame (coordinates.md) |
| `IDSC 2061532` | int 0x78B4E4 | 2061532 | |
| `NSLR 1` | f32 0x78B4B8 | 1.0 | "new slur" flag: draw_slur takes a different branch when != 0 (read) |
| `FULL 1` | int 0x78DF04 | 1 | (inferred from the order of the writes) |
| `DASH 1.29` | | | not located yet |

The values are global state for every draw, so a port must take them from the same file (or use these defaults) to match the oracle.
