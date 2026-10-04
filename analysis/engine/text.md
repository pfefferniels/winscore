# Text (code 16)

By impl-text, from the decompilation (`decompiled_all/569af0_draw_text.c` and the routines below); their Rust port matches 123/123 code-16 fixtures and the text items of the six sample scores. Folded in from their status report; the port is `rust/crates/score-render/src/text/`, the FMT reader `rust/crates/score-format/src/fmt.rs`.

Routines: draw_text 0x569AF0, parser 0x42FA58, per-character emitter 0x532EC0, record header 0x56CAF0, FMT loader 0x56B845, rotation 0x56F920, symbol glyphs 0x56B529. Positions use NINT (ANINT 0x5FF381, numerics.md); everything else truncates.

## FMT files (fontlib/FMnn.FMT)

708 bytes: PostScript name (28 bytes, blank/NUL padded), screen family (28 bytes), 163 i16 PostScript widths (1/1000 em), 163 i16 second widths (apparently screen fonts). Entry i belongs to glyph code i.

## How the engine sets text

- **Characters**: from the word after P13, or after P16 when P14 = -1, P12 of them, whatever the item stores in between. draw_items loads only P1–P12 (P1–P18 with P14 = -1); P13 and P26 of a text item play no part.
- **Parser 0x42FA58**: byte → code through the 256-entry i16 table 0x78F164 (codes 0–161 index the FMT tables; `_` = 1100). `_nn` font (90–93 → 24–27, 98 → 29, 99 → 4 on screen, non-digits → 29), `__nn` outline (+100); `?x` escapes (table 0x78F0B4/0x78F03C, 1-based), `!x` → 100 + position in "0123456789ADSZadefghijklmnpqsyz"; `~a ~A ~n ~N ~o ~O` tilde accent; `~n~` tab (code 10000 + 10n); doubled characters: `""` → 77 (110 outline), `^^`, `%%` (86 dieresis), `##` (87 cedilla), `<<` (83 acute), `>>` (84 grave); `\\nnn` octal when the three digits read ≥ 129 as decimal (out of 32–125 → `O`). A trailing font change or tab is dropped. Bytes ≥ 128 read past the table (é → glyph 0 → "0").
- **Advance** (P3 units, REAL*4): size = STEP·P6'/25 (P6' = AMOD(P6,100), 0 → 1); scale = size·3.2833 (0x78F024); W = i16/638 (0x56B845); advance = scale·W; the space (94) adds P10·size. Glyphs 80–82, 88–92 and all glyphs of fonts ≥ 90 take widths from table 0x1C6DA5C (copied into glyphs.rs). P13 = P5 · Σ advances.
- **Positions** (draw_text): X = X_POS (+34050 if staff > 200, then + 150·P11); per glyph x = NINT(X) (ANINT 0x5FF381, halves away from zero), then X = f32(150·advance + X); tab: X = 15·tenths (absolute, P3 not added). y = NINT(Y_POS) for all; the record stores y − 100 (0x532EC0), the shell draws at y + 96.
- **P5 ≠ 1**: extra = (P13 − P13/P5)/(n−1) added to every nonzero advance but the last (0 becomes 0.1).
- **P8**: 90–999 except 94 ignored; ≥ 1000: every font change (and tab) becomes font P8 % 1000; 94: meter font.
- **P9** (0x56F920): positions turn clockwise about (NINT X, NINT Y), then x += sin·4.583·150·size, y −= w·(sin(270°−P9)+1) with w = 3.95·175·size; escapement = trunc(10·P9). Constants REAL*4 (57.29578).
- **Record header** 0x56CAF0 per font change: family from the FMT, weight 700 for DEMI/BOLD, italic for OBLI/ITAL in the PostScript name (windows from the second letter on), height h = 1.937·STEP·P7/4, width field = 1.937·0.825·STEP·P6/4 (P7 = 0 → P6'); colour black, P14 = -1 → P16 (as P26, 1 → 0.92), outline fonts 0x03E418.
- **Glyph kinds at emission**: 95–161 and 167 → cp1252 via table 0x7970A4/0x79706B; accents 83–87/126 combine with the next glyph's character; glyphs > 79 (and every glyph of font 94) in fonts < 100 → library symbols code+2080 (80–92), code+2012 (≥ 162), code+2000 (font 94) at P6/4·3.5714 (0x56B529); code-10 numbers print them as text.
- **Current font**: a global (0x78B6A0) kept across items and across the several drawing passes of one command, so a text without `_nn` takes the font of the nearest earlier item that set one, else wraps around to the last one in the file. Text items set it (last font change drawn, or P8), staves set Helvetica-Narrow (8) through their screen staff number. Text items drop font changes to the current font.

## Not imitated or open

- Code-10 numbers in the font chain: an oracle run showed a code-10 number after `_02` text leaving Times; waits for impl-symbols' `codes::number::text_call` to check against fixtures.
- Print (`Medium::Print`): the engine writes PostScript instead (OUTPUT_MODE = -1), no display list; we draw the screen text.
- Not imitated: a glyph exactly at x = 0 is skipped by the rotation (sentinel collision, engine bug); the outline font with glyphs 80–92 prints a stale character; `_/nnnnnnn` 7-digit codes; the first text after start-up resets to font 0 only when no font was ever loaded (covered by the wrap-around rule in practice).
- Emulated engine crashes on an unclosed `~x` followed by certain characters (`A~B`, `~~`); avoided in fixtures.
