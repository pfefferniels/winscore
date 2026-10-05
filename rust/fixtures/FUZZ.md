# Differential fuzzing

Written by `oracle/fuzz.py`. Random items per code are recombined from the parameter values the fixtures use (documented value classes), with measures perturbed; random pages mix codes. Each case is drawn by the emulated engine and by `score_render`; *mismatch* = any element differs beyond ±1 unit or the renderer panics. Combinations the owners list as deliberate deviations are counted apart. Cases the oracle rejects (dialogs, messages, coordinate overflow) are *invalid* and not compared.

## Round 2 (seed 105, 300 items per code, 100 pages, 200 layout systems)

| | cases | invalid (oracle) | match | known deviation | mismatch | mismatch rate |
|---|---|---|---|---|---|---|
| code 01 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 02 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 03 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 04 | 300 | 1 | 299 | 0 | 0 | 0.0 % |
| code 05 | 300 | 0 | 297 | 3 | 0 | 0.0 % |
| code 06 | 300 | 0 | 296 | 4 | 0 | 0.0 % |
| code 07 | 300 | 0 | 299 | 1 | 0 | 0.0 % |
| code 08 | 300 | 0 | 263 | 37 | 0 | 0.0 % |
| code 09 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 10 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 11 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 12 | 300 | 0 | 299 | 0 | 1 | 0.3 % |
| code 14 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 15 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 16 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 17 | 300 | 2 | 298 | 0 | 0 | 0.0 % |
| code 18 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| layout LI | 52 | 0 | 52 | 0 | 0 | 0.0 % |
| layout LJ | 96 | 0 | 96 | 0 | 0 | 0.0 % |
| layout LJA | 52 | 0 | 52 | 0 | 0 | 0.0 % |
| pages | 100 | 1 | 97 | 1 | 1 | 1.0 % |

Known deviations hit: staff 1 placed by its own P10 moves on every draw (engine; analysis/engine/coordinates.md) ×37; second partial with stale line (impl-beams) ×3; slur cut P14/P15 outside 0…1 finds no place and reads stale state (impl-beams) ×2; ending number with P12 < 0 placed from a stale x offset (impl-beams, stale state) ×1; beam number letter from P17 (impl-beams, by design) ×1; harp diagram boxes read P16 as the box cm flag (impl-lines, not imitated) ×1; tablature with P8 < 0 (impl-notes, by design) ×1.

New minimal cases: `fuzz-code12-p5-p10-b1ef17`, `fuzz-code05-p11-p16-41830b`.

## Round 1 (seed 104, 300 items per code, 100 pages)

| | cases | invalid (oracle) | match | known deviation | mismatch | mismatch rate |
|---|---|---|---|---|---|---|
| code 01 | 300 | 0 | 299 | 1 | 0 | 0.0 % |
| code 02 | 300 | 0 | 299 | 0 | 1 | 0.3 % |
| code 03 | 300 | 0 | 297 | 0 | 3 | 1.0 % |
| code 04 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 05 | 300 | 0 | 291 | 9 | 0 | 0.0 % |
| code 06 | 300 | 0 | 292 | 8 | 0 | 0.0 % |
| code 07 | 300 | 0 | 299 | 0 | 1 | 0.3 % |
| code 08 | 300 | 0 | 264 | 36 | 0 | 0.0 % |
| code 09 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 10 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 12 | 300 | 1 | 283 | 6 | 10 | 3.3 % |
| code 14 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| code 16 | 300 | 0 | 299 | 0 | 1 | 0.3 % |
| code 17 | 300 | 1 | 299 | 0 | 0 | 0.0 % |
| code 18 | 300 | 0 | 300 | 0 | 0 | 0.0 % |
| pages | 100 | 2 | 90 | 0 | 8 | 8.2 % |

Known deviations hit: staff 1 placed by its own P10 moves on every draw (engine; analysis/engine/coordinates.md) ×36; slur cut P14/P15 outside 0…1 finds no place and reads stale state (impl-beams) ×9; box P16 = 1 cm scaling (impl-lines, not imitated) ×6; beam number letter from P17 (impl-beams, by design) ×5; second partial with stale line (impl-beams) ×3; P13 = 99 mark position (impl-notes, by design) ×1.

New minimal cases: `fuzz-code01-p11-p14-5b0460`, `fuzz-code02-p8-p15-37bcaa`, `fuzz-code03-p5-p10-e6050f`, `fuzz-code07-p7-p16-1b6f6e`, `fuzz-code12-p5-ffbe10`, `fuzz-code16-p8-p9-b70d9e`.

## Saved minimal cases

Every case in `oracle/fuzz_cases.json` (fixtures `rust/fixtures/<name>/`), shrunk to the fewest items and non-zero parameters that still differ, with its status when this report was written.

| case | owner | status | symptoms | items | detail |
|---|---|---|---|---|---|
| fuzz-code01-p11-p14-5b0460 | impl-notes | fixed | distorted | `8 1 0; 1 1 159 9 0 0 0 0 0 0 -14 0 0 -1` | same structure, off by up to 337 after aligning |
| fuzz-code01-p6-p10-e9c174 | impl-notes | fixed | text offset | `8 2 0; 1 2 134 5.5 0 -14 0 0 0 110` | "2" shifted by (15000, 0) |
| fuzz-code02-p5-p15-275998 | impl-notes | fixed | distorted | `8 1 0; 2 1 47 103 101 0 0 0 0 0 0 0 0 0 1` | same structure, off by up to 342 after aligning |
| fuzz-code02-p6-p8-c48746 | impl-notes | fixed | text style | `8 1 0; 2 1 164.33 2.5 0 -1 0 -3` | "G": Times 813.5/335.6 #000000 w400 esc 0 instead of Times 813.5/335.6 #999999 w400 esc 0 |
| fuzz-code02-p8-p15-37bcaa | impl-notes | fixed | text style | `8 1 0; 2 1 138.05 6 0 0 0 -3 0 0 0 0 0 0 0.8` | "G": Times 813.5/335.6 #000000 w400 esc 0 instead of Times 650.8/268.5 #000000 w400 esc 0 |
| fuzz-code02-p8-p17-c92312 | impl-notes | fixed | text offset | `8 2 0; 2 2 43 4 0 0 0 -3 0 0 0 0 0 0 0 0 1` | "G" shifted by (0, -3150) |
| fuzz-code03-p5-p10-e6050f | impl-symbols | fixed | extra | `8 1 0; 3 1 88.48 0 0.1 0 0 0 0 1` | fill #000000, 1 path(s), 62 points from (15678, 4037) |
| fuzz-code03-p5-p10-e66eab | impl-symbols | fixed | extra | `8 1 0; 3 1 60.13 6 0.9 0 0 0 0 2` | fill #000000, 1 path(s), 62 points from (11425, 5087) |
| fuzz-code05-p11-p16-2701e0 | impl-beams | fixed, ratcheted | text offset | `8 1 0; 5 1 26.49 5 0 0 0 0 0 0 2 0 0 0 0 12` | "1" shifted by (98, 336) |
| fuzz-code05-p11-p16-41830b | impl-beams | new | text offset | `8 1 0; 8 2 0; 5 1 120.03 1.5 0 0 0 0 0 0 2 0 0 0 0 12` | "1" shifted by (30, 349) |
| fuzz-code05-p11-p16-cf241b | impl-beams | fixed, ratcheted | text offset | `8 1 0; 5 1 121.01 13 0 0 0 0 0 0 3 0 0 0 0 3` | "3" shifted by (211, 279) |
| fuzz-code06-p8-p17-f76ce8 | impl-beams | deviation (by design: the beam thickness P17 read as the number's letter, any non-zero trunc(P17)) | text missing | `8 1 0; 6 1 84.49 4.5 0 0 0 34003 0 0 0 0 0 0 0 0 -1` | "?" in Times 678.0/279.7 at (15334, 1369) |
| fuzz-code12-p5-ffbe10 | impl-symbols | fixed | absent | `8 1 0; 12 1 133.74 7 -2` | stroke #000000, 1 path(s), 2 points from (22061, 3648) |
| fuzz-code12-p5-p10-b1ef17 | impl-symbols | new | failed | `8 1 0; 12 1 153.46 7 1 0 0 0 0 3009` | render panicked: index out of bounds: the len is 361 but the index is 3009 |
| fuzz-code12-p5-p11-cbf4b8 | impl-symbols | fixed | absent | `8 1 0; 12 1 16.39 0.5 5 0 0 0 0 0 270` | stroke #000000, 1 path(s), 181 points from (5333, 2511) |
| fuzz-code12-p5-p11-ec0e0d | impl-symbols | fixed | absent | `8 1 0; 12 1 32.9 8 5 0 0 0 0 0 405` | stroke #000000, 1 path(s), 91 points from (7810, 3823) |
| fuzz-code16-p8-p9-b70d9e | impl-text | fixed | offset | `8 1 0; 16 1 139.97 8 0 0 0 94 90 0 0 15 0 "_05DS7960Ea:9-'"` | shifted by (688, 688), residual 0 |
| fuzz-code16-p9-862d87 | impl-text | fixed | offset | `8 1 0; 16 1 140.07 -6 0 0 0 0 180 0 0 20 0 '_90Allegro [ = 120 ]'` | shifted by (5576, 0), residual 0 |
