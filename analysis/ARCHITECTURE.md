# WScore.exe: how the program is put together

Notes from static analysis (Ghidra 12.1.4, capstone) and from running the engine under emulation (`oracle/`). Addresses are virtual addresses in `WScore.exe` (image base `0x400000`). Function names are ours. The original PDB (`C:\WS\Debug\WScore.pdb`) is not available.

## Build

- Linker 6.0, Rich header: Visual C++ 6.0 compiler build 12.00.8168, 112 C++ objects, 159 C objects, 47 MASM objects, 267 objects without a Microsoft tool stamp (probably the FORTRAN objects).
- PE timestamp 2013-11-01. The CodeView record dates from 2013-10-23. Version resource: "winscore MFC Application", 500,0,0,1, copyright 2011.
- The C++ shell is a **debug** build (0xCC stack fill, `__chkesp`), linked against the debug MFC DLLs (`MFC42D`, `MFCO42D`, `MFCN42D`). The bundled DLLs are Microsoft runtime only.
- The FORTRAN engine was compiled **with optimisation** by Digital Visual Fortran (runtime "DEC Fortran RTL V1.1-15, 18-Jun-1997"). Smith's own help page says WinScore is written in Visual C++ and 32-bit DEC Fortran, and that the DOS versions used Microsoft Fortran and macro assembler.
- The C runtime and the Fortran runtime are linked statically.

## Address map

| Range | Contents |
|---|---|
| `0x401000–0x406604` | 812 incremental-linking jump thunks |
| `0x40BC18–0x58C7E2` | FORTRAN engine, 878 routines, 1.14 MB |
| `0x58C980–0x5ED2A0` | C++/MFC shell, about 2,600 functions, 86 source files `C:\WS\*.cpp` |
| `0x5ED37C–0x646FD0` | static CRT, Fortran runtime (`E:\forrtl\build\for_*.c`), MFC import thunks |
| `.data` | 136 KB initialised, 26 MB zero-initialised: FORTRAN COMMON blocks and the shell's buffers |

## Control flow of one command

1. A menu or toolbar handler (one of 1,622 `WM_COMMAND` entries in the MFC message maps; at least 1,367 only send a string) calls `SendCommand(cmd, description)` at `0x5A53E0`. The full table is `data/command_map.tsv`.
2. `SendCommand` copies `cmd` to the engine's command buffer `0x7A0B7C`. In MIDI input mode (`[0x9A9490] == 1`) clicks are mapped to pitch codes instead.
3. Glue `0x5925B0` saves/restores the 512-byte line buffer `0x9AE2BC` and calls the interpreter.
4. **Interpreter** `0x47EC50`, stdcall, 5 arguments: `(vector*, &vector_words, text*, &text_bytes, &status)`. It is the largest engine routine (26 KB) and the only user of the 112-entry three-letter mnemonic table at `0x7911BC` (`NOT RES CLE LIN SLU BEA BAR STA ...`).
5. The engine fills two output buffers (below). C++ converts the vector stream into a GDI display list (`0x5A4570`, `0x5A4900`) and `CWScoreView::OnDraw` (`0x5E5910`) replays it with `PolyPolygon`, `Polyline` and `TextOut`.

Special command-buffer forms seen in the interpreter: line buffer `~~W` + path writes the current score to that path (`0x5E5360`); `~~R` opens the file dialog route.

Engine start-up: `CMainFrame::OnCreate` (`0x5A1DB0`) calls `0x4A6730(0)` (stdcall), which reads `scorlib\PREF.DAT`, `scorlib\WSCORE.DAT` and a symbol library.

## Engine output

**Vector stream** at `0x9C73D8`, up to 100,000 int32 words, count at `0x1576468`: triples `(x, y, tag)`.

- `tag >> 24`: `0x01` starts a polyline, `0x02` a filled object, `0x03` a further sub-path of the same object, `0x00` continues, `0xFF` marks an empty start (set by `0x5A4570` when two starts follow each other).
- `tag & 0xFFFFFF`: colour as a Windows COLORREF (`0xBBGGRR`).
- Coordinates are engine units of **1/4000 inch**, y growing upward. The view uses `MM_HIENGLISH` (0.001 in) and scales by `zoom/256` with rounding; zoom `0x40` is 100 %.

**Text stream** (20,000 bytes; `0x157E574`, copied to `0x15E9C34`), one record per font run:

| Offset after the font name's NUL | Type | Meaning |
|---|---|---|
| +1 | f32 | height h; `CreateFontA` height = `-(zoom·h/4)`, i.e. 64·h engine units |
| +5 | f32 | 2 × width |
| +9 | i32 | escapement |
| +13 | i32 | colour |
| +17 | i32 | weight |
| +21 | u8 | italic |
| +25 | u8 | underline |
| +29 | i32 | number of strings |
| +33 | | strings: `x i32, y i32, NUL-terminated text`; drawn with `TextOut` at `(x, y + 96)` |

So music symbols reach the screen as polygons computed by the engine. Only text uses Windows fonts.

## Callbacks from the engine into C++

83 C++ functions are called from FORTRAN. Most are modal dialogs (about 60). The others write to the command bar (`0x5963E0`), wait for typed input (`0x596CC0`, `0x597120`), show message boxes (`0x5960F0`), or request window services through `0x597D30`, which dispatches on the second letter of a short opcode string (`~za` client size, `~sc` cursor, `~po` scroll position, `~k.` zoom, `~na` document title, `~i.` modified flag, colour and font pickers).

## Other observations

- The FORTRAN runtime's portability library brings in `SetLocalTime`. Its two wrappers have no callers, so WinScore never sets the clock.
- Install paths are hard-coded: `C:\winscore`, `C:\Program Files\winscore`, `C:\Program Files (x86)\winscore`.
- A copy-protection prompt exists: "Type last 4 digits of Serial Number on disk." Not examined.
- The MIDI player window classes are named `MIDIPlyrMWnd`/`MIDIPlyrTWnd`, which suggests the playback code started from Microsoft's MIDI stream sample. Unverified.
- `0x5A3E80` is a debugging aid that loads a raw dump of the vector and text buffers into the view.
