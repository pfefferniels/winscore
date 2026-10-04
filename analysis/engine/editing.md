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

### Selecting by click (0x498BF0; read, selection verified)

With no item selected (EDIT_ITEM == 0), a click selects the item whose **anchor** is nearest to the mouse point; the rule is parametric, not a hit test on the drawn outline. For every item i (via `load_item_header`):

```
v  = P4 (amod(P4, 100) for codes 1, 2, 3, 6) + offset(code)
     offset: code 2 (rest): table 0x78DD8C[rest type] = 4, 4, 2, 2, 1, 1, 1;  codes 8 and 14: v = 3 (P4 ignored);
             code 6: 6 (and x + 2) if |P7| < 20, else -8;  others: table 0x78DDA8[code] = 1:-1, 3:0, 4:-1, 5:0, 7:-1,
             9:-1, 10..13:-1, 15:-1, 16:-1, 17:4, 18:3;  code 5: x + 1 if P8 == -1, x + 3 if P8 is -2 or -3
ax = trunc((P3 (+227 if staff > 200) + dx) * 150),  ay = trunc(STAFF_Y(staff) + v*7*STAFF_STEP(staff))
d  = trunc(sqrt((ax - (mx - VIEW_DX))^2 + (ay - (my + VIEW_DY))^2))
```

The smallest d wins (strictly smaller; the previously selected item and EDIT_ITEM are skipped; there is no distance limit, so a click always selects something). The x offset dx (int 0x78DD70) is only set by slurs and beams and is not reset per item (read).

### Dragging (0x48F663; verified with the oracle)

While the button is held the view sends `~v` (no modifier), `~s` (Shift) or `~t` (Ctrl) on every mouse move, with the current point in 0x1A14950/0x1A1494C. `0x48F663` updates the **edit buffer** E(k) at 0x20B9440 + 4(k-1) (the selected item's parameters; E(2) is the staff, E(8)... as P). The item store is written only when the item is left (X, next item, ...): click, `~v`, `~x`, `X` moved a note from P3 100, P4 6 to P3 103.4133, P4 12.

```
step = 7 * STAFF_STEP(E2)
P3'  = f32((mx - VIEW_DX) / 150)            # absolute: the item jumps to the cursor, no grab offset; - 226.66 for staves > 200
P4'  = f32(f32(my - (STAFF_Y(E2) - VIEW_DY)) / step + c)    c = 2, or -2 for codes 2, 3 and > 16
x parameters (list at 0x78D820, per code): index 3: E3 = P3'; others: + (P3' - E3) when moving the whole item
    (move mode int 0x78DC30 = 0), = P3' for mode 1 or 2 (left/right end; set by the "Move Left End", "Move Right End",
    "Move All" commands in the interpreter)
y parameters (list at 0x78D838): index 5: E5 += P4' - E4 (= P4' in mode 2); index 4: E4 = NINT(P4') for codes < 4 or > 16,
    else E4 = P4' (fractional)
code 4 with E7 == 100: the extra point pairs E8..E17 move along
```

Checked on nine item types (line, note, cue note, rest, clef, key, meter, symbol, number) at two cursor heights: all 18 results equal this formula **with the VIEW_DY of each score**. VIEW_DY depends on the drawn content (max y + 3000, coordinates.md), so the same cursor point gives different P4 in scores with different tops; there is no per-item vertical term. For notes the hundreds digit of P4 is lost: a cue note `P4 = 106` dragged becomes `14` (NINT of P4' replaces the whole value).

`~s`: the first move only records the point; the second decides horizontal or vertical (vertical if |dy| > |dx|); later moves apply only once the cursor has moved at least 50 units since the last applied move, and only along the chosen axis.

### Region selection

- 0x41B011: drag rectangle to an x range `P2 = (x_down - VIEW_DX)/150`, `P3 = (x_up - VIEW_DX)/150` (clamped to 0..200; 227 is subtracted beyond the recto offset 34000) and a staff range through STAFF_MID: a region selection.

## Creation words

Word table at 0x796648 (`NOTE REST CLEF LINE SLUR BEAM TRILLSTAFF...`) used by 0x510B90; clef names at 0x78F3B0 (`TRE BAS ALT ...`) used by 0x4359D0; the 112 three-letter mnemonics at 0x7911BC are used only by the interpreter 0x47EC50. Defaults measured by editor-core with the oracle (e.g. NOTE: `1 st 100 1 10 0 1`, SLUR: `5 st 100 14 14 120 3 -1`).
