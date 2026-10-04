# Layout: lineup and justify (first notes, for a later phase)

Routine map **read** from the call graph, behaviour **verified** on one example; the algorithms themselves are not yet read in detail.

## Driving it

`LJ` (lineup and justify), `LI` (lineup only) and `J` (justify only) first ask for the system ("Enter Lowest Staff# of system and how many staves in system - or Draw Box."): the answer is the next command line, e.g. `1 2`, or a mouse box. Then the engine asks "Source Box O.K.?" through the yes/no dialog callback 0x595CD0 (C++ 0x595720). **The oracle's default answer 0 means No**, and the command then does nothing; any non-zero answer (1, 2, 6, 7 all behaved the same) lets it run. To reproduce WinScore's LJ in the oracle, answer that callback with 1.

| Address | Role (from callers/callees) |
|---|---|
| 0x4B7AD8 | LJ/LI/J command: sets up the prompt |
| 0x4B906D | takes the answer (staff numbers, or a box via 0x41AA88/0x41B011), asks 0x4A30BB "Source Box O.K.?", runs the work, redraws |
| 0x4B80B7 | the main lineup/justify pass (callees 0x4B6F4A, 0x4C9510, 0x4F7808, 0x5239C9, draw_items, load_item_header) |
| 0x4B8B97, 0x4B93F2 | further steps of the same command |

## Observed spacing (LI and LJ, one staff)

Staff 1 with a treble clef at P3 = 2, seven notes with P7 = 1, 0.5, 0.5, 2, 1, 1, 4 and a barline at 200. After `LI` (and identically after `LJ`, nothing needing justification) the notes sit at 12, 35.2578, 50.7628, 66.2681, 101.1547, 124.4125, 147.67:

- the first note starts 10 units after the clef;
- the space after a note is proportional to w(P7) with w(1) = 1, w(0.5) = 0.6667, w(2) = 1.5, w(4) = 2.25, i.e. **each doubling of the duration multiplies the space by 1.5** (w(d) = 1.5^log2(d) = d^0.585, the engravers' rule the help mentions: "a half note will not receive twice the space of a quarter note");
- the unit is (barline - first note) / sum of w: 188 / 8.0833 = 23.258.

`J` alone left this line unchanged. Accidentals, P10 offsets, multiple voices, other staves and the "robbing" of space described in `lj.txt` are not yet examined. Compare the IN command's own spacing (input.md), which is linear in duration.
