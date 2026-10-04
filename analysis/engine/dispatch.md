# Draw loop, item store, per-code dispatch

## Item store (verified)

Items live as f32 words in one array, 1-based in Fortran terms:

| Name | Address | Meaning |
|---|---|---|
| ITEM_LEN | 0x205343C | `(&ITEM_LEN)[w]` = length word L of the item starting at word w (number of parameters) |
| ITEM_Pk | 0x205343C + 4k | `(&ITEM_Pk)[w]` = Pk of that item, k = 1..L |
| ITEM_PTR0 | 0x2091D1C | `(&ITEM_PTR0)[i]` = word index w of item i (int) |
| ITEM_I | int 0x20B8E24 | number of items (also the loop index while drawing; the count is then kept in 0x79147C) |
| ITEM_WORDS | int 0x20B8E2C | words in use |

So item i's Pk is the f32 at `0x205343C + 4*(ITEM_PTR0[i] + k)`. `index_items` (0x548981) rebuilds ITEM_PTR0 by walking the length words from w = 1 (next item at w + L + 1) until a zero length word. This mirrors the .mus layout (FORMATS.md) without the word count and trailer.

`load_item_header` (0x547C32) reads item LOAD_I (int 0x2052780) into LOAD_W, LOAD_LEN, LOAD_CODE, LOAD_STAFF (ints, truncated) and LOAD_P3 (f32, 0 when L < 3) at 0x2052784..0x2052794. `oracle/trace.py` uses its entry to attribute output to items.

## draw_items (0x547FC8; read, behaviour verified)

Called by `redraw` (0x494026), by `fit_view` for its trial draw, and by many commands.

1. If there are items: COLOR = 0, VEC_LAST_PEN = 0, VEC_N = 1 (vector output restarts at word 1), then `draw_page_frame` (coordinates.md).
2. `index_items`, then for i = 1..count:
   - NPT = 1 (empty point buffer);
   - an item with P1 == 0 is changed to code 3 in the store;
   - n = trunc(L); for text (P1 == 16) n = 12, or 18 if its P14 == -1 (the characters after the parameters are not loaded);
   - P1..P50 = 0, then P(k) = ITEM_Pk for k = 1..n;
   - if P1 >= 19: the loop ends; unless P1 == 999 the item is reported ("item, P1, P2, P3" via an internal WRITE and message 0x54D831) and removed from the store by shifting the following words down;
   - screen mode (OUTPUT_MODE != -1): the per-item start word is recorded, `draw_item` runs, and `flush_points` writes the point buffer if NPT > 1. The end word is stored at 0x7978FC + 4i and the next start at 0x20359FC + 4(i+1): these ranges are what `fit_view` and hit-testing scan;
   - print mode (OUTPUT_MODE == -1) has its own colour handling (P26 >= 0 path, 0x4D4F89) and calls `draw_item` and 0x4D3E78 (PostScript emitter, not examined).
3. The item count is restored.

## draw_item (0x547210; verified)

1. Finds the last non-zero parameter among P1..P45 (minimum 3), then IP(k) = trunc(P(k)) for k = 1..45 (ints at 0x2091C40 + 4(k-1)).
2. Returns unless 1 <= IP1 <= 20 and 0 <= IP2 <= MAX_STAFF (256).
3. CUR_STAFF = IP2; `item_position` (placement.md).
4. Codes 1, 2 call their routines directly. Every other code goes through the second jump table after the P15 offset, except that the first table sends 4, 5, 6, 8, 11, 13, 15 and 16 straight to their routines.

| Code | Routine | Notes |
|---|---|---|
| 1 | `draw_note` 0x4EFEC0 | notes, stems, accidentals, dots, ledger lines |
| 2 | `draw_rest` 0x519C38 | |
| 3 | `draw_clef` 0x431AE0 (&X_POS, &Y_POS, &IP5, &P6, &P7) | +P15 |
| 4 | `draw_line` 0x439963 | lines, hairpins |
| 5 | `draw_slur` 0x538550 | |
| 6 | `draw_beam` 0x416168 | |
| 7 | `draw_code7` 0x55F340 | trills, ottava, pedal; +P15 |
| 8 | `draw_staff` 0x545140 | returns at once (no post-processing) |
| 9, 13 | `push_words(13, &P3)`; `draw_symbol` 0x4293F0 (&X_POS, &Y_POS, &IP5, &P6, &P7, &IP8, &P9, &IP9); `pop_words` | library symbols; +P15 for 9 only |
| 10 | `draw_number` 0x4F65A8 (&IP5) | +P15 |
| 11 | `draw_symbol` (same arguments), then a Fortran I/O call (0x5F34D1) | user symbols |
| 12 | IP5 == 10: 0x433EEE; IP5 < 0: 0x49EAE0; IP5 in {0, 1, 3}: `draw_box` 0x433530; else 0x432E80 | boxes, guitar grids; +P15 |
| 14 | `push_words(13, &P3)`; `draw_barline` 0x4117B0; `pop_words` | +P15. With IP4 == 0 and the command text at 0x20B90A0 starting "INV", the f32 at 0x20B944C is set to 13 first |
| 15 | 0x50A650 | imported EPS |
| 16 | `draw_text` 0x569AF0 | text; afterwards the f32 at 0x20B9470 = 0 when EDIT_ITEM == 0 |
| 17 | `draw_keysig` 0x4BF4F8 | +P15 |
| 18 | `draw_meter` 0x4BFA59 | +P15 |

After the switch, unless the command text starts with "c"/"C", EDIT_ITEM < 1 or int 0x791480 < 0: if P2 differs from the edited item's P2, 0x585D20 is called with trunc(f32 at 0x20B9470) (not examined).

`push_words`/`pop_words` (0x54DAF6/0x54DB88) save and restore n words on a private stack at 0x1A1B3A0, so the barline and symbol routines may scribble on P3..P15.
