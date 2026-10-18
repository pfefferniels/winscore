# Assets

Files of the WinScore 5.01 package (archive.org item `winscore-5.01`, assembled after Leland Smith's death from files he left online) and of SCORE 4 for DOS (archive.org item `score_202308`) that the editor uses.

| Path | Contents | Used by |
|---|---|---|
| `scorlib/LB*.DRW` | symbol libraries, embedded with the `bundled-symbols` feature | `score-render` (`build.rs`) |
| `scorlib/KBRHY.DRW`, `scorlib/FAULT.DRW` | compact libraries that code-11 user symbols name | `score-render` |
| `scorlib/CODE9.DAT` | the terms of code-9 symbols 3000–3099 | `score-render` |
| `scorlib/GUITAR.DAT` | the chord dictionary of guitar chord grids (code 12) | `score-render` |
| `scorlib/symblist.txt` | names of the library symbols, for the symbol picker | `score-edit` |
| `fontlib/FM*.FMT` | text font metrics by font number | `score-render`, `score-format` tests |
| `samples/*.mus` | sample scores: `000`, `carmen`, `mozart`, `sonlcs` (WinScore), `NEWLINE`, `NEWLIB` (SCORE 4) | the web app's start screen, tests |
