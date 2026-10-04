# Editing: how the view hands mouse actions to the engine

**Read** in the C++ shell and the engine; not yet driven through the oracle.

## Mouse protocol

`OnLButtonUp` (0x5EAEC0) converts the mouse-down and mouse-up points with `DPtoLP` (MM_HIENGLISH) and then `(p << 8) / zoom` into the engine's output coordinates, i.e. the space of the vector stream including VIEW_DX and VIEW_DY. It stores four ints that the engine reads directly from the image:

| Address | Meaning |
|---|---|
| 0x1A14950 | mouse-down x |
| 0x1A1494C | mouse-down y |
| 0x1A14948 | mouse-up x |
| 0x1A14944 | mouse-up y |

A drag sends command `~x` with the line buffer `|\0`; a click sends command `~` with line buffer `~` (both through `0x5925B0`). The service callback `0x597D30` (`~sc` etc.) answers further queries.

Engine routines that read the four globals: 0x41AA88, 0x41B011, 0x41B6C4, 0x41BAA2, 0x41BC5A, 0x44E255, 0x44E609, 0x498BF0, 0x49177A, 0x48F663, 0x48FD5C, 0x4A3172, 0x4E7380, 0x45623F, and the interpreter.

- 0x41B011: drag rectangle to an x range `P2 = (x_down - VIEW_DX)/150`, `P3 = (x_up - VIEW_DX)/150` (clamped to 0..200; 227 is subtracted beyond the recto offset 34000) and a staff range through STAFF_MID: a region selection.

## Creation words

Word table at 0x796648 (`NOTE REST CLEF LINE SLUR BEAM TRILLSTAFF...`) used by 0x510B90; clef names at 0x78F3B0 (`TRE BAS ALT ...`) used by 0x4359D0; the 112 three-letter mnemonics at 0x7911BC are used only by the interpreter 0x47EC50. Defaults measured by editor-core with the oracle (e.g. NOTE: `1 st 100 1 10 0 1`, SLUR: `5 st 100 14 14 120 3 -1`).
