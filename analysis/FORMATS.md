# SCORE / WinScore file formats

Sources: Smith's WinScore help (`docs/text/winscore/`, especially `save`, `structure` and `code1`–`code18`), the SCORE 4 help files (`docs/text/score4/`), and experiments with the emulated engine. Craig Stuart Sapp has documented the binary `.mus` format in his scorelib project. These notes have not yet been compared with his documentation line by line.

## `.mus` (implemented: `rust/crates/score-format/src/mus.rs`)

- Word count, 16-bit little-endian; above about 31,000 words a 32-bit count, which DOS SCORE cannot read. How the engine decides between the two when reading is not yet checked. The Rust reader picks whichever matches the file length.
- Items: a float length L, then L 32-bit words. P1 is the code (1 note, 2 rest, 3 clef, 4 lines and hairpins, 5 slurs, 6 beams, 7 trills, ottava, pedal, 8 staves, 9 library symbols, 10 numbers, 11 user symbols, 12 boxes and guitar grids, 14 barlines, 15 imported EPS, 16 text, 17 key signatures, 18 meters). Trailing zero parameters are omitted.
- Text items (code 16): P12 is the character count. The characters follow the parameters and are padded with blanks to whole words, so the number of parameters is `L - ceil(P12/4)`. WinScore text items may carry P14 and above before the characters.
- Length words can carry stray low mantissa bits (`carmen.mus` has 5.0000153). The engine truncates. The Rust reader keeps the bits so files round-trip exactly.
- Trailer: `[undefined, serial (integer bits), program version, measurement (0 inches, 1 metric), 5, -9999.0]`. Version is 3.0 in `carmen.mus` (1999) and 6.0 in WinScore 5 files. Observed serials: 4009999, 5009997, 5011111.
- Re-saving a file through the emulated engine reproduces every byte except the serial word and, for older files, the version word.

Coordinates in items: P3 runs 0–200 across 7.5 inches. P4 counts scale steps with 1 = middle C position on a treble staff. For code 14, P4 is the number of staves the barline spans.

## Symbol libraries `LBnnn0.DRW` (float variant implemented: `drw.rs`)

- 11 i16 offsets, 1-based point indices; symbol k uses points `off[k] ..< off[k+1]`, `off[0] = 0` read as 1, `off[10] - 1` = point count.
- 10 names of 24 characters. A blank name marks an unused slot whose offsets are leftovers.
- N x (f32), N y (f32), N pen codes (i16): 1 starts a stroked line, 2 a filled polygon, 0 continues.
- One library unit = 25 engine units (1/160 inch) at normal size. Checked: all 18 sub-paths of symbols 20–29 appear verbatim in the engine's output.
- `LB0020` holds tail, wedge, accent, tenuto, dot and their combinations, down-bow, up-bow. `lb5020.drw` holds animal pictures.

**Compact variant** (open): starts with the bytes `KH`, then 11 i16 offsets, 10 five-character names, then i16 records with integer coordinates and path markers such as `0x8148`, `0x8181`. Used by all SCORE 4 libraries (`BODN*`, `BODB*`, `MUSI*`: Bodoni text and music digit outlines) and by `FAULT.DRW`, `KBRHY.DRW` in WinScore.

## Not yet decoded

- `fontlib/FMnn.FMT` (708 bytes each), `FMFONTINIT.PSC`, SCORE 4 `LIB/FMnn.PSC`: font metrics and PostScript font set-up.
- `scorlib/PREF.DAT` (preferences; the engine has a table of 4-letter keywords `METR INCH BEAM BMTH REST DASH ...`), `WSCORE.DAT`, `CODE9.DAT`, `GUITAR.DAT`, `*.CHD` guitar chord files.
- `.pag` page-layout files.
- SCORE's text input language (e.g. `SCORE 4/SCORE/ADDA.MUS`: pitch, rhythm and beam lines such as `G3/G4/D4/B3;`), converted to items by the `IN` command.
