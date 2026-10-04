# Fixture plan

One case per documented parameter value class of every item code (Smith's help, `analysis/docs/text/winscore/codeN.txt`; the SCORE 4 help in `analysis/docs/text/score4/CODnn-4.txt` has the value tables that are images in the WinScore help), each item on a staff, plus combinations that interact. Names are `codeNN-<parameter>-<value class>`. Status per case: `STATUS.md`.

## Who writes which sweeps

Each code's cases live in `oracle/fixtures_codeNN.py` (a `cases()` function; `fixtures_cases.all_cases()` imports every such module), so the implementer of a code can add the cases they need without touching shared files.

| Codes | Module(s) | Written by |
|---|---|---|
| samples | `fixtures_cases.py` | verifier |
| 8, 14 | `fixtures_code08.py`, `fixtures_code14.py` | verifier |
| 1, 2 | `fixtures_code01.py`, `fixtures_code02.py` | impl-notes |
| 3, 9, 10, 11, 12, 15, 17, 18 | `fixtures_code03.py` etc. | impl-symbols |
| 4, 7 | `fixtures_code04.py`, `fixtures_code07.py` | impl-lines |
| 5, 6 | `fixtures_code05.py`, `fixtures_code06.py` | impl-beams |
| 16 | `fixtures_code16.py` | impl-text (first 91 cases drafted by verifier) |
| interactions across codes | `fixtures_code99.py` | verifier |

## Done

- **Samples**: the four WinScore samples (`000`, `carmen`, `mozart`, `sonlcs`) and SCORE 4's `NEWLINE.MUS`, `NEWLIB.MUS`. `G` shows the first page only. `000.mus` gets `logo-col.eps` next to it (code 15). `NEWLIB.MUS` asks for the SCORE 4 libraries `lb0990.drw` and `lb0710.drw`, which WinScore lacks; the engine then shows a "Not found" dialog (`0x59B090`) and draws nothing for those symbols, as real WinScore would (`meta.json`, `not_found`).
- **Code 8, staves** (59 cases): P2 (staff 0, 2, 3, 10), P3, P4, P5 (including the 0.65 line-thickness threshold), P6, P3+P6, P7 line counts 1–10, three-digit P7, P7 = -1, P9, P10 (with P4 set, which it overrides), P11, P12, P13, P14, P25, P26 (grey, white, red, rgb, green); systems of 2, 4, 12 staves, gaps, mixed sizes, P4 offsets, P10 placement, differing ends, line counts, recto staff 201.
- **Code 14, barlines** (93 cases) on four size-1 staves: P4 span (0–4, 999, negative), P2, P3; P5 types 0–11, 14, -1, -44 (types 11 and above draw the same as 11; negative types draw a heavy bar), several types over 1 and 4 staves; P6 for single, final and brace; P7 for single, brace, bracket; P8 dash size, partial bracket, two-bar-repeat number; P9; P10, P11 partial bars; P12, P13, P14, P16 repeat details; P18, P19 gaps; P25, P26; mixed staff sizes, P17, three-line staff, moved staves, a full system, a barline without staves.

Observed P5 types (from the engine output, not from the help text, whose type table is an image): 0 single, 1 double, 2 final (thin + heavy), 3 repeat with dots left, 4 dots right, 5 dots both sides, 6 heavy-heavy repeat, 7 dashed, 8 brace, 9 bracket, 10 square bracket.

## Oracle fidelity checks

- Zoom: the vector and text streams of `G` are identical at zoom `0x20`, `0x40`, `0x80` for the samples, and at `0x40`/`0x80` for every case (checked per case).
- View offset: `G` scrolls so that the highest visible staff's top line is at y = -3000; fixtures are normalised to page coordinates (README).
- Buffer limits: the engine never checks its output buffers (disasm-expert); the 100,000-word extent in ARCHITECTURE.md is only the declared Fortran extent. carmen (166,671 words) is complete; the shell holds about 1,000,000 words and 10,000 objects.
- Item attribution: every element carries the index of the item that drew it, taken from a write hook. The engine's own per-item ranges start one triple late after at least one text item (sonlcs item 466, a code 16 before a recto barline), so they are not used.
- `G input.mus` is read as `NPUT.MUS`: a leading `I` after `G ` is consumed. The sandbox file is called `case.mus`.

- **Code 16, text** (91 cases, drafted by verifier, continued by impl-text): P5, P6 (with part flags 101–301), P7, P8 font overrides (90–98, 1000–1034, outlines 193, 1105), P9 rotation, P10, P11, P14–P16 colour; fonts `_00`–`_34`, `_90`–`_94`, `_98`, `_99%`; font switches, spaces, tabs, `?c`, `%%`, `[ ]`, backslash, Latin-1; staff sizes, recto. The engine reads characters after P13 whatever the item length, so P13 is always stored; an unclosed `~` or `~~` crashes the emulated engine (impl-text).

- **Interactions** (`code99-*`, 17 cases): measures with clef, key signature and meter in treble and bass, beams up/down/double/triplet/partial with their notes, a tie, a slur, chords (with a second, stem down with accidentals, tied), a slashed grace note slurred to its note, notes and rests with a centred whole rest, a two-staff system with brace, a melody with dynamics, hairpin, tempo text and final bar.
- Codes 3, 4, 6 (cases written by impl-symbols, impl-lines, impl-beams) are in; codes 1, 2, 5, 7, 9–12, 15, 17, 18 follow from their owners' branches.

## Next (verifier)

- More interaction cases as implementers report gaps (cross-staff beams, notes on staves above/below with beams, multi-voice staves).
- Check whether the print-only set-width record `(999, w, 99)` ever reaches the screen; it would be a stray continuation point.
