# Item placement and colour

## Position of every item (verified)

`draw_item` (0x547210) calls `item_position` (0x5479AB) for every code before dispatching:

```
CUR_STAFF = IP2
STEP  = STAFF_STEP(IP2)
X_POS = f32(150 * P3)
P4'   = amod(P4, 100) for codes 1, 2, 3, 6  (P4 - trunc(P4/100)*100; the hundreds carry flags)
      = P4             otherwise
Y_POS = f32(STAFF_Y(IP2) + P4' * 7 * STEP)
```

so `Y_POS = bottom line + (P4' - 3) * 175 * s`: P4 = 1 is middle C on a treble staff (one ledger line below), 3 the bottom line, 7 the middle line, 11 the top line. IP3 is replaced by trunc(X_POS). Items with IP2 > MAX_STAFF (256), IP2 < 0, or a code outside 1–20 are not drawn.

Then, before the code switch, for codes 3, 7, 9, 10, 12, 14, 17 and 18 only:

```
if P15 != 0:  X_POS = f32(P15 * 150 + X_POS)
```

Codes 1, 2, 4, 5, 6, 8, 11, 13, 15, 16 do not get this offset (read from the jump tables at 0x769010 and 0x768FD0; verified for code 14).

`item_position` also checks `X_POS > RIGHT_LIMIT + 12100` (RIGHT_LIMIT int 0x1FBB8BC = 30000) unless int 0x1F9A6F4 == 1, and then calls 0x54A967 and 0x59D020 (probably a warning). Not examined.

`staff_level_y(&v)` (0x547AA3) is the same formula for an arbitrary level v on CUR_STAFF, returned as f32: `f32(STAFF_Y(CUR_STAFF) + v * 7 * STAFF_STEP(CUR_STAFF))`.

## Colour, P26 (verified)

`flush_points` (0x54A497) sets COLOR (int 0x791478) before writing an item's points:

```
if P1 == 16 and P14 == -1:  P26 = P16          # text items with P14 = -1 carry the colour in P16
if P26 != 0:
    if P26 == 1:  P26 = 0.92
    if P26 < 1:   P26 = f32(P26*1e6 + (P26*1e4 + P26*100))     # grey: 0.8 -> 808080
    n = trunc(P26)
    R = trunc((n / 10000) * 2.56f)      # integer division first
    G = trunc(((n % 10000) / 100) * 2.56f)
    B = trunc((n % 100) * 2.56f)
    COLOR = R | G << 8 | B << 16        # COLORREF; the result is cached for the rest of the item
```

P26 is thus RRGGBB in percent. 2.56f is the f32 constant 2.5599999427795410, so 50 % gives 127, not 128. Checked: 0.5 gives 0x7F7F7F, 203040 gives 0x664C33, 0.8 gives 0xCCCCCC.

If P26 == 0, `emit_points` sets COLOR = 0 (black), or 0x0000FF (red) when EDIT_ITEM (int 0x20527E0) != 0 or int 0x1E66CB0 != 0: the item being edited is shown in red. When EDIT_ITEM < 0 and P26 == 0, COLOR keeps whatever value it had (read; an edge case).

The page frame uses P26 = 9900 (COLORREF 0x00FD00), invisible staves 0.8, staff numbers 4520 (0x003373).
