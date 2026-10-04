# WScore.exe engine knowledge base

What the FORTRAN engine inside WScore.exe (WinScore 5.01) computes, with addresses, formulas and constants, for porting the renderer to Rust. Maintained by `disasm-expert`. Read at the main-checkout path: it changes while the team works.

## Confidence marks

- **verified**: confirmed by running the emulated engine (`oracle/`), usually with an experiment script in `experiments/`.
- **read**: read in the disassembly or decompilation, not yet confirmed by experiment.
- **inferred**: a plausible reading, not checked.

## Topics

| File | Contents |
|---|---|
| [catalog.md](catalog.md) | routines with names, roles, callers, confidence (generated from `names.tsv`) |
| [numerics.md](numerics.md) | truncation, f32 intermediates, x87 precision: needed for ±1 unit agreement |
| [coordinates.md](coordinates.md) | internal units, output transform (VIEW_DX, VIEW_DY), recto offset, page frame |
| [staves.md](staves.md) | code 8: staff positions, sizes, lines, staff numbers |
| [placement.md](placement.md) | how every item's P3/P4 become x/y; colour (P26) |
| [barlines.md](barlines.md) | code 14: types, spans, thick bars, repeat dots, brackets |
| [symbols.md](symbols.md) | library symbols: draw_symbol, draw_clef, text symbols |
| [notes.md](notes.md) | code 1: heads (and the head cache), stems, tails, dots, accidentals, ledger lines |
| [input.md](input.md) | the IN command: passes, spacing, minimum gap |
| [display.md](display.md) | how the C++ shell paints the engine output (pens, zoom, text) |
| [dispatch.md](dispatch.md) | draw loop, the per-code switch, item store layout |
| [emitters.md](emitters.md) | point buffer, vector stream writer, pens |
| [tools.md](tools.md) | `oracle/trace.py`, `experiments/lab.py`, the Ghidra scripts |

## Files

- `names.tsv`: our routine names (address, name, confidence, role). Read by `oracle/trace.py` and applied to the Ghidra project by `ghidra/ApplyNames.java`.
- `globals.tsv`: names and types of engine globals (COMMON-block variables). Applied the same way.
- `decompiled/<addr>_<name>.c`: Ghidra decompilations of the routines the topic notes rely on. The whole engine (878 routines) is decompiled at `/Users/nielspfeffer/Projects/winscore/tools/decompiled/` (not in git; `ghidra/ghidra.sh all` regenerates it). Constants are labelled by value (`f_150` is the f32 constant 150.0, `i_3` the int 3, `d_...` a double). Ghidra prints `ROUND(x)` for every `fistp`; in this engine nearly all of them run with the rounding control set to truncate (see numerics.md).
- `experiments/`: scripts that reproduce the verified statements.
- `ghidra/`: GhidraScripts and the runner `ghidra.sh`.
