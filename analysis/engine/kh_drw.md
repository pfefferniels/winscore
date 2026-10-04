# The compact "KH" symbol libraries

**Verified** by decoding every SCORE 4 library and comparing it with WinScore's float-variant file of the same number: `experiments/kh_drw.py`.

## Container: Microsoft FORTRAN unformatted sequential file

The "KH" files are not a separate drawing format. They are what Microsoft FORTRAN for DOS writes for an unformatted sequential file:

- byte 0: 0x4B ('K'), the file marker;
- then physical records of at most 128 data bytes, each framed by a length byte before and after the data;
- the length byte 0x81 (129) means "128 data bytes, and the logical record continues in the next physical record";
- any other length (1–128) ends the logical record;
- the byte 0x82 (130) in place of a length byte ends the file (some SCORE 4 files end without it).

The "H" of "KH" is simply the length byte 0x48 = 72 of the first record. The "path markers" 0x8148, 0x8181, 0x8260 noted in FORMATS.md are framing bytes: a closing length byte followed by the next opening one (0x81 every 130 bytes) or by the end byte 0x82.

## Content

Two logical records, the same information as the float variant with integer coordinates:

1. **Header** (72 bytes): 11 i16 offsets (1-based word indices into record 2; `off[k]` .. `off[k+1]-1` belong to symbol k; 0 reads as 1) and ten names of **5** characters (blank = unused slot).
2. **Points**: i16 triples (x, y, pen), so a symbol has (off[k+1] - off[k]) / 3 points. Pens as in the float variant (1 stroke start, 2 fill start, 3 sub-path, 0 continue, negatives as continuation).

Coordinates are the same library units as the float variant: for 45 library pairs (LIBRA–LIBRZ, LIBSC, LIBTI–LIBTQ, LIBUM–LIBUS against LB0000–LB0960) the decoded points equal WinScore's float points exactly, symbol for symbol. The other pairs differ only where WinScore revised or replaced symbols (e.g. LIBSB vs LB0270, LIBSE vs LB0300, one symbol of LIBRK vs LB0100).

## File names

SCORE 4 names library n `LIB<a><b>.DRW` with `a = chr(ord('R') + n / 26)`, `b = chr(ord('A') + n % 26)`: LIBRA = 0 (WinScore LB0000.DRW), LIBRK = 10, LIBSA = 26, LIBTI = 60, LIBUM = 90. The other SCORE 4 files in the same format (BODN*, BODB*, BODI*, BDIB*, BODO*, MUSI*: Bodoni text and music digits; HARP.DRW) follow the same container and record layout.

## In WinScore

`load_symbol_library` (0x42AD97) reads only the float variant (its READs expect f32 arrays), so WinScore cannot draw KH symbols: a KH file in scorlib behaves like a missing library (symbols.md). The two KH files shipped in WinScore's scorlib are `FAULT.DRW` (one symbol "fault", 27 points) and `KBRHY.DRW` ("kbrhy" 103 points, "kbrh1" 177 points); no engine routine was found that opens them by name.
