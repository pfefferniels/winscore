# Corpus sources

Real SCORE files found on the public web, downloaded for comparing WinScore's engine (`oracle/`) with `score_render`. All were accessed on 2026-10-05; nothing was uploaded and no account was used. The files live in `corpus/files/<source>/` and are gitignored. Files whose terms clearly allow redistribution are copied to `corpus/free/` and committed (see the last section). Minimal cases (`oracle/fixtures_code_corpus.py`) are synthetic: they repeat a few parameter values of the corpus item they stand for.

Formats: *mus* = binary SCORE item file, *pag* = binary page file (same format, one whole page), *pmx* = SCORE's ASCII parameter listing, converted to binary by `corpus/pmx.py`. Sapp's 1999 listings have two decimals, so converted files are close to, not identical with, the binary originals. *ppmx* = several pages of PMX in one file, split into pages with `python corpus/pmx.py FILE.ppmx DIR`. A PMX listing next to its own binary file is not run twice.

All binary files parse with `score_format::MusFile::parse`; exceptions are noted. "Terms" quotes what the source states.

| source (directory) | where | terms | files |
|---|---|---|---|
| `sapp` | <https://ccrma.stanford.edu/~craig/score/> (`peach/`, `rose/`, `pac/`, `short/ex2`–`ex10`, `short2/ex6`–`ex15`) | READMEs of peach, rose, pac: "Copyright 1999, Craig Stuart Sapp, All Rights Reserved. Use freely for non-commercial purposes." | 40 mus, 6 pag (Joplin *Peacherine Rag*, MacDowell *To a Wild Rose*, Pachelbel Prelude and Fugue, 19 short excerpts); SCORE 3.11, 1998–99 |
| `sapp-ccrma-code-input` | same site, `code/` and `input/` | none stated there | code1.mus, code5.mus (Sapp's SCORE 3.11 parameter sheets for codes 1 and 5), input-ex1.mus, input-ex2-five6.pmx |
| `imslp-sapp` | PDFs of IMSLP user Craig (<https://imslp.org/wiki/User:Craig>) via vmirror.imslp.org; only the embedded attachments kept | IMSLP file records: chopin2804 (#319636), chopin2806 (#319260) "Creative Commons Attribution 4.0"; mazurka 24/1, 24/2 (#366041, #365221) "Creative Commons Attribution-NonCommercial 4.0" | chopin2804, chopin2806 (SCORE 4 PMX, 2014); mazurka 24/1 (ppmx, 2 pages); mazurka 24/2 (ppmx, same as the GitHub copy, not run) |
| `ccarh-wiki` | wiki.ccarh.org via the Wayback Machine (`/images/8/8b/Shortex2.mus`, `/images/e/e6/Shortex1.pmx`) | wiki footer: "Content is available under Creative Commons Attribution-NonCommercial-ShareAlike unless otherwise noted." | shortex2.mus, shortex1.pmx |
| `ccarh-music253` | www.ccarh.org/courses/253/ and 253.ccarh.org via Wayback | none stated | psheets-code6.mus (code-6 parameter sheet) |
| `github-craigsapp-scorelib` | <https://github.com/craigsapp/scorelib> (`data/`) | none stated (no licence file) | 9 mus (Bach chorale 5, Brahms op. 76/7 pp. 1–2, Chopin preludes 1–4, 6) with their PMX; densmore_sioux.ppmx (Densmore, *Teton Sioux Music*, 245 pages, 2 empty) |
| `scorelib-sapp-org-site` | craigsapp/scorelib, branch gh-pages (`_includes/examples/`, `img/`) | none stated | 19 PMX (Beethoven sonata 26, Ravel quartet, Wagner *Tristan*, courtesy-accidental and clef images); the `-markup` variants (SVG markup in font 99) were deleted |
| `score-sapp-org-examples` | score.sapp.org example pages via Wayback (PMX from the pages' data boxes) | none stated | 77 PMX (Sapp's SCORE tutorial examples) |
| `github-craigsapp-mus2pmx` | <https://github.com/craigsapp/mus2pmx> (`tests/`) | LICENSE: "Whatever" | ex1.mus, epsgraph.mus (needs MARY.EPS, not available: invalid) |
| `github-craigsapp-prettypmx` | <https://github.com/craigsapp/prettypmx> (`example/`) | LICENSE: "Whatever" | 6 PMX |
| `github-craigsapp-chopin-mazurka24-2` | <https://github.com/craigsapp/chopin-mazurka24-2> (`production_files/`) | none stated | mazurka24-2.ppmx, 4 pages (a SCORE command script: RS, SA page, items, SM) |
| `github-humdrum-old-website` | <https://github.com/humdrum-tools/old-website> (`source/humextra/*.rstd`) | none stated | 6 PMX; messy and nested2 use `SVG` macro lines and are not read |
| `github-polyrhythm-project` | <https://github.com/polyrhythm-project/polyrhythm-project-website> (`img/tempo/`) | none stated | 9 tiny mus (tempo marks), 1 further PMX |
| `github-mapped-measures-musedata-beethoven` | <https://github.com/MathiasMeuleman/mapped-measures-dataset> (`src/beethoven_symphonies/.../symN/distrib/score/NNN.pmx`) | repository LICENSE: CC BY 4.0; the files themselves: "created: 11/26/09 by W Hewlett ... Data converted from the MUSEDATA format ... (c) Copyright 2007 by CCARH" | 88 PMX: Beethoven Symphony 1 complete (70 pages), pages 2 and 50 of nos. 2–8, pages 2, 50, 250, 280 of no. 9 |
| `bol-sapp-org` | bol.sapp.org/data/pmx/ via Wayback (19 of 50 files; the archive stopped answering) | none stated | 19 PMX (tabla bol notation) |
| `mazurka-org-uk` | mazurka.org.uk/webern/notation/Aitken1961/ via Wayback | none stated | webern-op27-1-Aitken1961-sys01.pmx |
| `scoremid-shareware` | discmaster.textfiles.com: SCMID11E on PC_Musician_2000.iso, sc2mid on audio-11000.iso | README.TXT: "(c) Christoph Lübbe 1996. All rights reserved. ... SCOREMID is FREEWARE. You can copy theses files and pass it to other persons if you make no changes to any of the files." | KIRCH_02, KIRCH_03.PAG (Kirchner, Valse), RAC_28–31.PAG (Rachmaninov, Russian Rhapsody), sc2mid-rh170.mus |
| `brodhead-demos` | Wayback: home.att.net/~tom.brodhead/BEAMDEMO.ZIP, EDITDEMO.ZIP (Thomas Brodhead) | no licence; README: "While you may examine the test files any way that you wish, you *must not* save the files using SA or SM in Score" | 15 mus (BEAM test files, manual figures, EDIT demos) |
| `dekloe-sip` | Wayback: www.dekloe.be (Jan de Kloe, Sip utilities): xmlsco01–09.mus, "SipScoreToXML sample01.zip", "SipEps01 originals.zip" | none stated for the samples | 34 mus (24 Bach pages, 8 xmlsco test files, 2 samples) |
| `scorprev-311sp-samples` | discmaster: CD_ASCQ_22_0695.iso, `scorprev.zip`; README from <https://archive.org/download/scorprev/readme> | README: "(c)Copyright 1995 by San Andreas Press ... This program may be copied and used by anyone, with the stipulation that any commercial or for-profit use must be specifically licensed by San Andreas Press." | 12 .SCO files: SCORPREV's protected preview format, a different binary layout; `MusFile::parse` rejects them ("word count matches neither a 16- nor a 32-bit header"). Not run |

Leads that gave nothing (no need to check again): the IMSLP wiki itself (bot check; vmirror works), the Mendelssohn and Scarlatti PDFs of IMSLP user Craig (no attachment), archive.org (only the WinScore and SCORE 4 packages already in the repository), scoremus.com on Wayback (programs and DRW files only), the Acadia SCORE site (EPS and PDF only), tasso-scores, musedata.org, kern.ccarh.org, humdrum.org, the MuseData GitHub repositories (MuseData, not SCORE; their .mus files are Finale), Sapp's other repositories, bmt-systems.com, GitHub code search (binary .mus is not indexed), SCOREIO (C source only). wiki.ccarh.org and esf.ccarh.org were down; `esf.ccarh.org/score/test1.mus` is in the Wayback index but was not fetched.

## Committed: `corpus/free/`

Only files whose terms clearly allow redistribution:

- `chopin2804.pmx.txt`, `chopin2806.pmx.txt`: Chopin, Preludes op. 28 nos. 4 and 6, typeset by Craig Stuart Sapp (2014), attached to his IMSLP PDFs, Creative Commons Attribution 4.0.
- `mus2pmx-ex1.mus`: test file of Craig Sapp's mus2pmx, LICENSE "Whatever".
