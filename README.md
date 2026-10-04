# WINSCORE / SCORE: analysis and Rust port

Material for understanding Leland Smith's music engraving program SCORE and its Windows version WINSCORE, with the long-term aim of a Rust reimplementation.

## Sources

- `WINSCORE 5.01/`: archive.org item `winscore-5.01`, assembled after Smith's death from files left online (see its `readme.txt`).
- `SCORE 4/`: archive.org item `score_202308`, SCORE 4 for DOS, described by the uploader as a hybrid of 4.0 and 3.x files. The item's description calls SCORE a PASCAL program. The executables contain the Microsoft FORTRAN run-time library, and Smith's own WinScore help says the DOS versions were written in Microsoft Fortran and macro assembler.

## Layout

| Path | Contents |
|---|---|
| `analysis/ARCHITECTURE.md` | how `WScore.exe` works: FORTRAN engine, C++ shell, command flow, output format |
| `analysis/FORMATS.md` | `.mus`, `.DRW` and what is still undecoded |
| `analysis/docs/text/` | WinScore help (CHM) and SCORE 4 help files as plain text |
| `analysis/data/` | Ghidra exports: functions, call graph, strings, data references, GUI command table |
| `analysis/decompiled/` | decompiled excerpts (dispatcher, services, drawing) |
| `analysis/scripts/`, `analysis/ghidra_scripts/` | the scripts that produced the above |
| `oracle/` | the original engine running under emulation, as a test reference |
| `rust/` | the port; so far `score-format` (`.mus` read/write, `.DRW` float variant) |

## Status

- `.mus`: all seven sample files round-trip byte for byte; item counts agree with the original engine.
- `.DRW` float variant: 116 of 118 WinScore libraries parse; symbol geometry matches the engine's output.
- Oracle: loads and renders the sample scores (`analysis/figures/carmen_p3_emulated.svg`).

## Possible order of work for the port

1. Shared output types (engine display list, text runs) and an SVG writer in Rust.
2. Item rendering, one code at a time (staves, barlines, clefs, notes, rests, beams, slurs, key and time signatures, symbols, text, ...), each checked against oracle output for parameter sweeps built with `oracle/musbuild.py`.
3. PostScript/PDF output, using the engine's EPS writer as reference.
4. Layout commands (justification, spacing), the text input language, editing commands.
5. An interactive editor.
