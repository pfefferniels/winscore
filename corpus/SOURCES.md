# Corpus sources

Real SCORE files found on the public web, downloaded for comparing WinScore's engine (`oracle/`) with `score_render`. The files live in `corpus/files/<source>/` and are gitignored. None of them is committed: no source so far states terms that clearly allow redistribution. Minimal cases cut from them (`oracle/fixtures_corpus.py`) keep only a few items' parameter values; the note at each source says why that seems acceptable.

Formats: *mus* = binary SCORE item file, *pag* = binary page file (same format, one whole page), *pmx* = SCORE's ASCII parameter listing, converted to binary by `corpus/pmx.py` (two decimals, so converted files are close to, not identical with, the binary originals; P13 of text items is 0).

All files parse with `score_format::MusFile::parse` unless noted.

## sapp – Craig Stuart Sapp's SCORE examples (CCRMA, Stanford)

- URL: <https://ccrma.stanford.edu/~craig/score/> (subdirectories `peach/`, `rose/`, `pac/`, `short/ex2`–`ex10`, `short2/ex6`–`ex15`)
- Accessed: 2026-10-05
- Terms, stated in `peach/README`, `rose/README`, `pac/README`: "Copyright 1999, Craig Stuart Sapp, All Rights Reserved. Use freely for non-commercial purposes." The short examples carry no statement of their own.
- Typeset in SCORE 3.11 (1998–1999); trailer version 3.0.
- Files (46): Joplin, *Peacherine Rag*: systems `peacha`–`peachi.mus`, pages `page1`–`page4.pag`; MacDowell, *To a Wild Rose*: systems `rose1`–`rose7.mus`, pages `page1`–`page2.pag`; Pachelbel, Prelude and Fugue in E minor: `prel1.mus`, `fugue1`–`fugue4.mus`; short excerpts `five2`–`five10.mus` and `bux`, `rz4e`, `chopin`, `greg`, `grieg`, `liszt`, `patoc`, `camp`, `schon`, `strauss.mus`.
- Redistribution: not clearly allowed ("All Rights Reserved"), so not committed. Minimal cases copy the parameter values of a handful of items, which falls under non-commercial use in a private research repository.
