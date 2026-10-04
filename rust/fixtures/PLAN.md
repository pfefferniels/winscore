# Fixture plan

One case per documented parameter value class of every item code (Smith's help, `analysis/docs/text/winscore/codeN.txt`), each item on a staff, plus combinations that interact. Cases are defined in `oracle/fixtures_cases.py`; names are `codeNN-<parameter>-<value class>`. Status per case: `STATUS.md`.

## Done

- **Samples**: the four WinScore samples (`000`, `carmen`, `mozart`, `sonlcs`) and SCORE 4's `NEWLINE.MUS`, `NEWLIB.MUS`. `G` shows the first page only. `000.mus` gets `logo-col.eps` next to it (code 15). `NEWLIB.MUS` is invalid for now: the engine calls the C++ callback `0x59B090` eight times (question to disasm-expert).
- **Code 8, staves** (59 cases): P2 (staff 0, 2, 3, 10), P3, P4, P5 (including the 0.65 line-thickness threshold), P6, P3+P6, P7 line counts 1–10, three-digit P7, P7 = -1, P9, P10 (with P4 set, which it overrides), P11, P12, P13, P14, P25, P26 (grey, white, red, rgb, green); systems of 2, 4, 12 staves, gaps, mixed sizes, P4 offsets, P10 placement, differing ends, line counts, recto staff 201.
- **Code 14, barlines** (93 cases) on four size-1 staves: P4 span (0–4, 999, negative), P2, P3; P5 types 0–11, 14, -1, -44 (types 11 and above draw the same as 11; negative types draw a heavy bar), several types over 1 and 4 staves; P6 for single, final and brace; P7 for single, brace, bracket; P8 dash size, partial bracket, two-bar-repeat number; P9; P10, P11 partial bars; P12, P13, P14, P16 repeat details; P18, P19 gaps; P25, P26; mixed staff sizes, P17, three-line staff, moved staves, a full system, a barline without staves.

Observed P5 types (from the engine output, not from the help text, whose type table is an image): 0 single, 1 double, 2 final (thin + heavy), 3 repeat with dots left, 4 dots right, 5 dots both sides, 6 heavy-heavy repeat, 7 dashed, 8 brace, 9 bracket, 10 square bracket.

## Oracle fidelity checks

- Zoom: the vector and text streams of `G` are identical at zoom `0x20`, `0x40`, `0x80` for the samples, and at `0x40`/`0x80` for every case (checked per case).
- View offset: `G` scrolls so that the highest visible staff's top line is at y = -3000; fixtures are normalised to page coordinates (README).
- Buffer limits: carmen (166,671 words) and sonlcs exceed the 100,000-word vector capacity stated in ARCHITECTURE.md, with complete-looking output. Real limit asked of disasm-expert.
- `G input.mus` is read as `NPUT.MUS`: a leading `I` after `G ` is consumed. The sandbox file is called `case.mus`.

## Next

Codes 1–7, 9–13, 15–18, in this order of dependence for the renderer team: clefs (3), key signatures (17), meters (18), notes (1), rests (2), beams (6), slurs and ties (5), lines and hairpins (4), trills/ottava/pedal (7), symbols (9), numbers (10), text (16), user symbols (11), boxes (12), EPS (15). The per-code case lists follow as they are written.
