# Fixture status

Written by `score-compare` (crate `score-testkit`). Compared: the engine's `engine.json` against score_render::render of input.mus. Tolerance ±1 engine units. Counts are matched/expected; `+n` = elements only the Rust side has.

## By fixture group

| group | cases | valid | compared | matching | shapes | texts |
|---|---|---|---|---|---|---|
| code01 | 345 | 345 | 345 | 343 | 3027/3029 +2 | 498/498 |
| code02 | 152 | 152 | 152 | 152 | 1328/1328 | 216/216 |
| code03 | 96 | 96 | 96 | 96 | 1132/1132 | 124/124 |
| code04 | 113 | 113 | 113 | 113 | 1959/1959 | 116/116 |
| code05 | 105 | 105 | 105 | 105 | 770/770 | 148/148 |
| code06 | 74 | 74 | 74 | 74 | 508/508 | 93/93 |
| code07 | 69 | 69 | 69 | 69 | 1277/1277 | 107/107 |
| code08 | 59 | 59 | 59 | 59 | 419/419 | 92/92 |
| code09 | 105 | 105 | 105 | 105 | 1560/1560 | 139/139 |
| code10 | 71 | 71 | 71 | 71 | 378/378 | 263/263 |
| code11 | 30 | 30 | 30 | 30 | 496/496 | 33/33 |
| code12 | 173 | 173 | 173 | 173 | 2259/2259 | 352/352 |
| code14 | 93 | 93 | 93 | 93 | 2410/2410 | 359/359 |
| code15 | 20 | 20 | 20 | 20 | 143/143 | 23/23 |
| code16 | 137 | 137 | 137 | 137 | 797/797 | 2112/2112 |
| code17 | 42 | 42 | 42 | 42 | 950/950 | 44/44 |
| code18 | 47 | 47 | 47 | 47 | 400/400 | 55/55 |
| code99 | 17 | 17 | 17 | 17 | 291/291 | 26/26 |
| corpus | 3 | 3 | 3 | 3 | 3777/3777 | 552/552 |
| fuzz | 16 | 16 | 16 | 13 | 154/154 | 44/48 +3 |
| layout | 3 | 3 | 3 | 3 | 134/134 | 5/5 |
| sample | 6 | 6 | 6 | 6 | 7952/7952 | 2143/2143 |

## By item code

Only the elements drawn by items of that code, over all compared fixtures; a fixture counts as fully matching when that code's elements all match.

| code | items | fixtures with output | fully matching | shapes | texts |
|---|---|---|---|---|---|
| 1 | notes | 373 | 371 | 8672/8674 +2 | 85/85 |
| 2 | rests | 161 | 161 | 1394/1394 | 26/26 |
| 3 | clefs | 110 | 110 | 1148/1148 | 27/27 |
| 4 | lines, hairpins | 121 | 121 | 1536/1536 | 0/0 |
| 5 | slurs, brackets | 121 | 119 | 469/469 | 50/53 +3 |
| 6 | beams | 89 | 88 | 747/747 | 21/22 |
| 7 | trills, ottava, pedal | 72 | 72 | 1152/1152 | 48/48 |
| 8 | staves | 1772 | 1772 | 10934/10934 | 2279/2279 |
| 9 | library symbols | 116 | 116 | 1455/1455 | 97/97 |
| 10 | numbers | 77 | 77 | 41/41 | 337/337 |
| 11 | user symbols | 29 | 29 | 341/341 | 0/0 |
| 12 | boxes, grids | 176 | 176 | 1520/1520 | 198/198 |
| 14 | barlines | 115 | 115 | 1043/1043 | 0/0 |
| 15 | EPS | 21 | 21 | 42/42 | 0/0 |
| 16 | text | 158 | 158 | 135/135 | 4368/4368 |
| 17 | key signatures | 49 | 49 | 1126/1126 | 0/0 |
| 18 | meters | 59 | 59 | 366/366 | 8/8 |

## Cases

| case | result | shapes | texts | max dev | note |
|---|---|---|---|---|---|
| code01-corpus-mark-m29 | match | 9/9 | 1/1 | 0 | mark P11 = -29 on the stem side |
| code01-corpus-mark29 | match | 9/9 | 1/1 | 0 | mark P11 = 29 (as in Sapp's code-1 parameter sheet) |
| code01-corpus-mark29-down | match | 9/9 | 1/1 | 0 | mark P11 = 29, stem down |
| code01-corpus-mark29-p14 | match | 9/9 | 1/1 | 0 | mark P11 = 29 moved by P14 = -2 (as in Sapp's code-1 parameter sheet) |
| code01-font-after-alpha | match | 7/7 | 13/13 | 0 | plain text after _02 text and an AlphaNote (letter font 1005) |
| code01-font-after-alpha-p21 | match | 7/7 | 13/13 | 0 | plain text after _02 text and an AlphaNote with P21 = 3 |
| code01-font-after-fingering | match | 7/7 | 13/13 | 0 | plain text after _02 text and a fingering mark (font 1000) |
| code01-font-after-plain-note | match | 7/7 | 12/12 | 0 | plain text after _02 text and a plain note (loads none) |
| code01-font-after-tab | match | 5/5 | 13/13 | 0 | plain text after _02 text and a tablature number (font 1005) |
| code01-grace-down | match | 7/7 | 1/1 | 0 | grace note P4 = 105, stem down |
| code01-grace-ledger | match | 8/8 | 1/1 | 0 | grace note on P4 = 100 (ledger line) |
| code01-grace-mark | match | 8/8 | 1/1 | 0 | grace note with staccato |
| code01-grace-negative | match | 9/9 | 1/1 | 0 | grace note P4 = -102 |
| code01-grace-sharp-dot | match | 12/12 | 1/1 | 0 | grace note with sharp and dot |
| code01-grace-slash-down | match | 10/10 | 1/1 | 0 | grace eighth with a slash, stem down |
| code01-grace-slash-long | match | 10/10 | 1/1 | 0 | grace eighth with a slash, P8 = 102.5 |
| code01-grace-slash-short | match | 10/10 | 1/1 | 0 | grace eighth with a slash, P8 = -101 |
| code01-grace-slash-up | match | 10/10 | 1/1 | 0 | grace eighth with a slash (P8 = 101) |
| code01-grace-two-tails | match | 12/12 | 1/1 | 0 | grace sixteenth with a slash |
| code01-grace-up | match | 7/7 | 1/1 | 0 | grace note P4 = 105, stem up |
| code01-mixed-bar | match | 95/95 | 1/1 | 0 | fourteen notes of different kinds on one staff |
| code01-p10-0.5 | match | 7/7 | 1/1 | 0 | head offset P10 = 0.5 |
| code01-p10-10 | match | 7/7 | 1/1 | 0 | head offset P10 = 10 |
| code01-p10-10-dot | match | 8/8 | 1/1 | 0 | P10 = 10 with a dot |
| code01-p10-10-down | match | 7/7 | 1/1 | 0 | P10 = 10, stem down |
| code01-p10-110 | match | 7/7 | 1/1 | 0 | head offset P10 = 110 |
| code01-p10-2.5 | match | 7/7 | 1/1 | 0 | head offset P10 = 2.5 |
| code01-p10-20 | match | 7/7 | 1/1 | 0 | head offset P10 = 20 |
| code01-p10-20-ledger | match | 8/8 | 1/1 | 0 | P10 = 20 on a ledger note |
| code01-p10-m3 | match | 7/7 | 1/1 | 0 | head offset P10 = -3 |
| code01-p11-heavy-line | match | 8/8 | 1/1 | 0 | P11 = 99: heavy line |
| code01-p11-heavy-line-p13-p14 | match | 8/8 | 1/1 | 0 | P11 = 99, P13 = 3, P14 = 12 |
| code01-p11-mark-1 | match | 10/10 | 1/1 | 0 | mark P11 = 1 |
| code01-p11-mark-10 | match | 9/9 | 1/1 | 0 | mark P11 = 10 |
| code01-p11-mark-11 | match | 10/10 | 1/1 | 0 | mark P11 = 11 |
| code01-p11-mark-12 | match | 8/8 | 1/1 | 0 | mark P11 = 12 |
| code01-p11-mark-13 | match | 8/8 | 1/1 | 0 | mark P11 = 13 |
| code01-p11-mark-14 | match | 9/9 | 1/1 | 0 | mark P11 = 14 |
| code01-p11-mark-14-down | match | 9/9 | 1/1 | 0 | mark P11 = 14, stem down |
| code01-p11-mark-15 | match | 8/8 | 1/1 | 0 | mark P11 = 15 |
| code01-p11-mark-16 | match | 8/8 | 1/1 | 0 | mark P11 = 16 |
| code01-p11-mark-17 | match | 13/13 | 1/1 | 0 | mark P11 = 17 |
| code01-p11-mark-18 | match | 12/12 | 1/1 | 0 | mark P11 = 18 |
| code01-p11-mark-19 | match | 8/8 | 1/1 | 0 | mark P11 = 19 |
| code01-p11-mark-2 | match | 11/11 | 1/1 | 0 | mark P11 = 2 |
| code01-p11-mark-20 | match | 9/9 | 1/1 | 0 | mark P11 = 20 |
| code01-p11-mark-21 | match | 12/12 | 1/1 | 0 | mark P11 = 21 |
| code01-p11-mark-22 | match | 13/13 | 1/1 | 0 | mark P11 = 22 |
| code01-p11-mark-23 | match | 13/13 | 1/1 | 0 | mark P11 = 23 |
| code01-p11-mark-24 | match | 9/9 | 1/1 | 0 | mark P11 = 24 |
| code01-p11-mark-25 | match | 9/9 | 1/1 | 0 | mark P11 = 25 |
| code01-p11-mark-26 | match | 9/9 | 1/1 | 0 | mark P11 = 26 |
| code01-p11-mark-27 | match | 10/10 | 1/1 | 0 | mark P11 = 27 |
| code01-p11-mark-28 | match | 11/11 | 1/1 | 0 | mark P11 = 28 |
| code01-p11-mark-29 | match | 9/9 | 1/1 | 0 | mark P11 = 29 |
| code01-p11-mark-29-down | match | 9/9 | 1/1 | 0 | mark P11 = 29, stem down |
| code01-p11-mark-29-p14 | match | 9/9 | 1/1 | 0 | P11 = 29 moved by P14 = -2 |
| code01-p11-mark-29-tails | match | 13/13 | 1/1 | 0 | P11 = 29 on a note with two tails |
| code01-p11-mark-3 | match | 11/11 | 1/1 | 0 | mark P11 = 3 |
| code01-p11-mark-30 | match | 7/7 | 2/2 | 0 | mark P11 = 30 |
| code01-p11-mark-31 | match | 7/7 | 2/2 | 0 | mark P11 = 31 |
| code01-p11-mark-32 | match | 7/7 | 2/2 | 0 | mark P11 = 32 |
| code01-p11-mark-32-down | match | 7/7 | 2/2 | 0 | mark P11 = 32, stem down |
| code01-p11-mark-33 | match | 7/7 | 2/2 | 0 | mark P11 = 33 |
| code01-p11-mark-34 | match | 7/7 | 2/2 | 0 | mark P11 = 34 |
| code01-p11-mark-35 | match | 7/7 | 2/2 | 0 | mark P11 = 35 |
| code01-p11-mark-36 | match | 7/7 | 2/2 | 0 | mark P11 = 36 |
| code01-p11-mark-37 | match | 7/7 | 2/2 | 0 | mark P11 = 37 |
| code01-p11-mark-38 | match | 7/7 | 2/2 | 0 | mark P11 = 38 |
| code01-p11-mark-39 | match | 7/7 | 2/2 | 0 | mark P11 = 39 |
| code01-p11-mark-4 | match | 9/9 | 1/1 | 0 | mark P11 = 4 |
| code01-p11-mark-40 | match | 7/7 | 3/3 | 0 | mark P11 = 40 |
| code01-p11-mark-5 | match | 8/8 | 1/1 | 0 | mark P11 = 5 |
| code01-p11-mark-5-down | match | 8/8 | 1/1 | 0 | mark P11 = 5, stem down |
| code01-p11-mark-5-tails | match | 12/12 | 1/1 | 0 | accent with two tails |
| code01-p11-mark-5.13 | match | 8/8 | 1/1 | 0 | P11 = 5.13: accent pushed 1.3 steps |
| code01-p11-mark-6 | match | 8/8 | 1/1 | 0 | mark P11 = 6 |
| code01-p11-mark-7 | match | 8/8 | 1/1 | 0 | mark P11 = 7 |
| code01-p11-mark-7-down | match | 8/8 | 1/1 | 0 | mark P11 = 7, stem down |
| code01-p11-mark-7-half | match | 8/8 | 1/1 | 0 | staccato on a half note |
| code01-p11-mark-7-high | match | 8/8 | 1/1 | 0 | staccato on P4 = 12 |
| code01-p11-mark-7-low | match | 10/10 | 1/1 | 0 | staccato on P4 = -2 |
| code01-p11-mark-7-no-stem | match | 7/7 | 1/1 | 0 | staccato without a stem |
| code01-p11-mark-8 | match | 10/10 | 1/1 | 0 | mark P11 = 8 |
| code01-p11-mark-9 | match | 9/9 | 1/1 | 0 | mark P11 = 9 |
| code01-p11-mark-m14 | match | 9/9 | 1/1 | 0 | mark P11 = -14 on the stem side |
| code01-p11-mark-m29 | match | 9/9 | 1/1 | 0 | mark P11 = -29 on the stem side |
| code01-p11-mark-m32 | match | 7/7 | 2/2 | 0 | mark P11 = -32 on the stem side |
| code01-p11-mark-m32-down | match | 7/7 | 2/2 | 0 | P11 = -32, stem down |
| code01-p11-mark-m34.2-down | match | 7/7 | 2/2 | 0 | P11 = -34.2, stem down |
| code01-p11-mark-m5 | match | 8/8 | 1/1 | 0 | mark P11 = -5 on the stem side |
| code01-p11-mark-m7 | match | 8/8 | 1/1 | 0 | mark P11 = -7 on the stem side |
| code01-p11-tremolo-41 | match | 8/8 | 1/1 | 0 | P11 = 41: tremolo beams |
| code01-p11-tremolo-42 | match | 9/9 | 1/1 | 0 | P11 = 42: tremolo beams |
| code01-p11-tremolo-42-down | match | 9/9 | 1/1 | 0 | P11 = 42, stem down |
| code01-p11-tremolo-42-half | match | 9/9 | 1/1 | 0 | P11 = 42 on a half note |
| code01-p11-tremolo-42-p13-p14 | match | 9/9 | 1/1 | 0 | P11 = 42 with P13 = 1, P14 = 2 |
| code01-p11-tremolo-43 | match | 10/10 | 1/1 | 0 | P11 = 43: tremolo beams |
| code01-p11-tremolo-44 | match | 11/11 | 1/1 | 0 | P11 = 44: tremolo beams |
| code01-p12-1 | match | 17/17 | 3/3 | 0 | note on staff 2 with P12 = 1 |
| code01-p12-1-ledger | match | 18/18 | 3/3 | 0 | P12 = 1 on P4 = 0 |
| code01-p12-1-slash | match | 20/20 | 3/3 | 0 | P12 = 1, grace note with a slashed tail |
| code01-p12-100 | match | 18/18 | 3/3 | 0 | note on staff 2 with P12 = 100 |
| code01-p12-101 | match | 18/18 | 3/3 | 0 | note on staff 2 with P12 = 101 |
| code01-p12-2 | match | 17/17 | 3/3 | 0 | note on staff 2 with P12 = 2 |
| code01-p12-201 | match | 17/17 | 3/3 | 0 | note on staff 2 with P12 = 201 |
| code01-p13-2 | match | 8/8 | 1/1 | 0 | accent moved horizontally P13 = 2 |
| code01-p13-99 | differs | 7/8 +1 | 1/1 | 0 | staccato centred on the stem (P13 = 99) |
| code01-p13-99-down | differs | 7/8 +1 | 1/1 | 0 | staccato centred on the stem, stem down |
| code01-p13-m2 | match | 8/8 | 1/1 | 0 | accent moved horizontally P13 = -2 |
| code01-p14-2 | match | 8/8 | 1/1 | 0 | accent moved vertically P14 = 2 |
| code01-p14-m1 | match | 8/8 | 1/1 | 0 | accent moved vertically P14 = -1 |
| code01-p15-0.75 | match | 7/7 | 1/1 | 0 | note size P15 = 0.75 |
| code01-p15-1.3 | match | 7/7 | 1/1 | 0 | note size P15 = 1.3 |
| code01-p15-down | match | 9/9 | 1/1 | 0 | P15 = 0.75, stem down, tail |
| code01-p15-full | match | 18/18 | 1/1 | 0 | P15 = 0.75 with sharp, dot, two tails, ledger |
| code01-p15-grace | match | 7/7 | 1/1 | 0 | P15 = 0.8 on a grace note |
| code01-p15-mark | match | 8/8 | 1/1 | 0 | P15 = 0.75 with an accent |
| code01-p16-2 | match | 9/9 | 1/1 | 0 | ledger line thickness P16 = 2 |
| code01-p16-99 | match | 9/9 | 1/1 | 0 | ledger line thickness P16 = 99 |
| code01-p17-1.5 | match | 7/7 | 1/1 | 0 | stem source P17 = 1.5 |
| code01-p17-1.5-down | match | 7/7 | 1/1 | 0 | P17 = 1.5, stem down |
| code01-p17-100 | match | 7/7 | 1/1 | 0 | stem source P17 = 100 |
| code01-p17-101.5 | match | 7/7 | 1/1 | 0 | stem source P17 = 101.5 |
| code01-p17-200 | match | 7/7 | 1/1 | 0 | stem source P17 = 200 |
| code01-p17-m1 | match | 7/7 | 1/1 | 0 | stem source P17 = -1 |
| code01-p18-0.5 | match | 8/8 | 1/1 | 0 | accent size P18 = 0.5 |
| code01-p18-1.5 | match | 8/8 | 1/1 | 0 | accent size P18 = 1.5 |
| code01-p18-fingering-2 | match | 7/7 | 2/2 | 0 | fingering size P18 = 2 |
| code01-p18-staccato-1.5 | match | 8/8 | 1/1 | 0 | staccato size P18 = 1.5 |
| code01-p19-1 | match | 8/8 | 1/1 | 0 | dot moved P19 = 1 |
| code01-p19-m1.5 | match | 8/8 | 1/1 | 0 | dot moved P19 = -1.5 |
| code01-p20-0.8 | match | 7/7 | 1/1 | 0 | note width P20 = 0.8 |
| code01-p20-1.4 | match | 7/7 | 1/1 | 0 | note width P20 = 1.4 |
| code01-p20-down | match | 9/9 | 1/1 | 0 | P20 = 1.4, stem down, tail |
| code01-p20-full | match | 14/14 | 1/1 | 0 | P20 = 1.4 with dot, tail, flat, ledger |
| code01-p20-half | match | 7/7 | 1/1 | 0 | P20 = 1.4 on a half note |
| code01-p20-mark | match | 8/8 | 1/1 | 0 | P20 = 1.4 with staccato |
| code01-p25-layer | match | 7/7 | 1/1 | 0 | layer number P25 = 1 |
| code01-p26-grey | match | 7/7 | 1/1 | 0 | grey note P26 = 0.5 |
| code01-p26-red-ledger | match | 9/9 | 1/1 | 0 | red note on a ledger line |
| code01-p27-red-ledger | match | 9/9 | 1/1 | 0 | red note, ledger lines red too (P27 = 1) |
| code01-p28-3 | match | 11/11 | 1/1 | 0 | accidental pen width P28 = 3 |
| code01-p29-0.7 | match | 10/10 | 1/1 | 0 | accidental size P29 = 0.7 |
| code01-p29-1.5 | match | 10/10 | 1/1 | 0 | accidental size P29 = 1.5 |
| code01-p3-20.3 | match | 7/7 | 1/1 | 0 | P3 = 20.3 |
| code01-p30-1-p4-14 | match | 8/8 | 1/1 | 0 | ledger control P30 = 1 on P4 = 14 |
| code01-p30-1-p4-5 | match | 8/8 | 1/1 | 0 | ledger control P30 = 1 on P4 = 5 |
| code01-p30-14-p4-5 | match | 11/11 | 1/1 | 0 | ledger control P30 = 14 on P4 = 5 |
| code01-p30-2-p4-14 | match | 8/8 | 1/1 | 0 | ledger control P30 = 2 on P4 = 14 |
| code01-p30-2-p4-5 | match | 8/8 | 1/1 | 0 | ledger control P30 = 2 on P4 = 5 |
| code01-p30-24-p4-14 | match | 11/11 | 1/1 | 0 | ledger control P30 = 24 on P4 = 14 |
| code01-p30-24-p4-5 | match | 11/11 | 1/1 | 0 | ledger control P30 = 24 on P4 = 5 |
| code01-p30-3-p4-14 | match | 8/8 | 1/1 | 0 | ledger control P30 = 3 on P4 = 14 |
| code01-p30-3-p4-5 | match | 8/8 | 1/1 | 0 | ledger control P30 = 3 on P4 = 5 |
| code01-p30-34-p4-5 | match | 11/11 | 1/1 | 0 | ledger control P30 = 34 on P4 = 5 |
| code01-p30-4-p4-5 | match | 11/11 | 1/1 | 0 | ledger control P30 = 4 on P4 = 5 |
| code01-p30-44-p4-5 | match | 11/11 | 1/1 | 0 | ledger control P30 = 44 on P4 = 5 |
| code01-p30-m1 | match | 7/7 | 1/1 | 0 | P30 = -1 on P4 = -2 (no ledger lines) |
| code01-p31-0.7 | match | 9/9 | 1/1 | 0 | dot size P31 = 0.7 |
| code01-p31-1.5 | match | 9/9 | 1/1 | 0 | dot size P31 = 1.5 |
| code01-p4-0 | match | 8/8 | 1/1 | 0 | P4 = 0 |
| code01-p4-0-down | match | 8/8 | 1/1 | 0 | P4 = 0, stem down |
| code01-p4-1 | match | 8/8 | 1/1 | 0 | P4 = 1 |
| code01-p4-11 | match | 7/7 | 1/1 | 0 | P4 = 11 |
| code01-p4-12 | match | 7/7 | 1/1 | 0 | P4 = 12 |
| code01-p4-13 | match | 8/8 | 1/1 | 0 | P4 = 13 |
| code01-p4-14 | match | 8/8 | 1/1 | 0 | P4 = 14 |
| code01-p4-15 | match | 9/9 | 1/1 | 0 | P4 = 15 |
| code01-p4-15-down | match | 9/9 | 1/1 | 0 | P4 = 15, stem down |
| code01-p4-18 | match | 10/10 | 1/1 | 0 | P4 = 18 |
| code01-p4-2 | match | 7/7 | 1/1 | 0 | P4 = 2 |
| code01-p4-3 | match | 7/7 | 1/1 | 0 | P4 = 3 |
| code01-p4-5.5 | match | 7/7 | 1/1 | 0 | P4 = 5.5 (between levels) |
| code01-p4-6 | match | 7/7 | 1/1 | 0 | P4 = 6 |
| code01-p4-7 | match | 7/7 | 1/1 | 0 | P4 = 7 |
| code01-p4-7-down | match | 7/7 | 1/1 | 0 | P4 = 7, stem down |
| code01-p4-9-down | match | 7/7 | 1/1 | 0 | P4 = 9, stem down |
| code01-p4-m1 | match | 9/9 | 1/1 | 0 | P4 = -1 |
| code01-p4-m4 | match | 10/10 | 1/1 | 0 | P4 = -4 |
| code01-p4-m4-down | match | 10/10 | 1/1 | 0 | P4 = -4, stem down |
| code01-p5-displace-left-0.5 | match | 10/10 | 1/1 | 0 | P5 = 11.05: flat 0.5 steps left |
| code01-p5-displace-left-2.5 | match | 11/11 | 1/1 | 0 | P5 = 12.25: sharp 2.5 steps left |
| code01-p5-displace-right-0.35 | match | 11/11 | 1/1 | 0 | P5 = 12.935: sharp 0.35 steps right |
| code01-p5-double-flat | match | 13/13 | 1/1 | 0 | P5 = 14: double-flat |
| code01-p5-double-sharp | match | 8/8 | 1/1 | 0 | P5 = 15: double-sharp |
| code01-p5-flat | match | 10/10 | 1/1 | 0 | P5 = 11: flat |
| code01-p5-flat-ledger | match | 12/12 | 1/1 | 0 | flat on a ledger note (P4 = -1) |
| code01-p5-natural | match | 11/11 | 1/1 | 0 | P5 = 13: natural |
| code01-p5-no-stem | match | 6/6 | 1/1 | 0 | P5 = 0, no stem |
| code01-p5-no-stem-sharp | match | 10/10 | 1/1 | 0 | P5 = 2: sharp, no stem |
| code01-p5-paren-double-flat | match | 15/15 | 1/1 | 0 | P5 = 114: double-flat in parentheses |
| code01-p5-paren-double-sharp | match | 10/10 | 1/1 | 0 | P5 = 115: double-sharp in parentheses |
| code01-p5-paren-flat | match | 12/12 | 1/1 | 0 | P5 = 111: flat in parentheses |
| code01-p5-paren-natural | match | 13/13 | 1/1 | 0 | P5 = 113: natural in parentheses |
| code01-p5-paren-quarter-flat | match | 9/9 | 1/1 | 0 | P5 = 116: quarter-flat in parentheses |
| code01-p5-paren-sharp | match | 13/13 | 1/1 | 0 | P5 = 112: sharp in parentheses |
| code01-p5-quarter-flat | match | 9/9 | 1/1 | 0 | P5 = 16: quarter-flat |
| code01-p5-quarter-sharp | match | 10/10 | 1/1 | 0 | P5 = 18: quarter-sharp |
| code01-p5-sharp | match | 11/11 | 1/1 | 0 | P5 = 12: sharp |
| code01-p5-sharp-down | match | 11/11 | 1/1 | 0 | P5 = 22: sharp, stem down |
| code01-p5-sharp-p10-10 | match | 11/11 | 1/1 | 0 | sharp with the head offset right (P10 = 10) |
| code01-p5-sharp-p10-110 | match | 11/11 | 1/1 | 0 | sharp moving with the head (P10 = 110) |
| code01-p5-sharp-p10-2.5 | match | 11/11 | 1/1 | 0 | sharp with P10 = 2.5 |
| code01-p5-sharp-p10-20 | match | 11/11 | 1/1 | 0 | sharp with the head offset left (P10 = 20) |
| code01-p5-three-quarter-flat | match | 11/11 | 1/1 | 0 | P5 = 17: three-quarter-flat |
| code01-p5-three-quarter-sharp | match | 12/12 | 1/1 | 0 | P5 = 19: three-quarter-sharp |
| code01-p6-alpha-20 | match | 7/7 | 2/2 | 0 | P6 = 20: AlphaNote |
| code01-p6-alpha-21 | match | 7/7 | 2/2 | 0 | P6 = 21: AlphaNote |
| code01-p6-alpha-22 | match | 7/7 | 2/2 | 0 | P6 = 22: AlphaNote |
| code01-p6-alpha-23 | match | 7/7 | 2/2 | 0 | P6 = 23: AlphaNote |
| code01-p6-alpha-24 | match | 7/7 | 1/1 | 0 | P6 = 24: AlphaNote |
| code01-p6-alpha-25 | match | 7/7 | 1/1 | 0 | P6 = 25: AlphaNote |
| code01-p6-alpha-down | match | 7/7 | 2/2 | 0 | AlphaNote with the stem down |
| code01-p6-alpha-m20 | match | 8/8 | 2/2 | 0 | P6 = -20: AlphaNote |
| code01-p6-alpha-m20-space | match | 7/7 | 2/2 | 0 | P6 = -20: hollow AlphaNote in a space |
| code01-p6-alpha-m23 | match | 8/8 | 2/2 | 0 | P6 = -23: AlphaNote |
| code01-p6-alpha-p15 | match | 7/7 | 2/2 | 0 | AlphaNote at P15 = 0.8 |
| code01-p6-alpha-p21 | match | 7/7 | 2/2 | 0 | AlphaNote with P21 = 2, P22 = 1, P23 = 1, P24 = 1.5 |
| code01-p6-black | match | 7/7 | 1/1 | 0 | P6 = 0: black head |
| code01-p6-black-diamond | match | 9/9 | 1/1 | 0 | P6 = 5: black-diamond head |
| code01-p6-breve | match | 6/6 | 1/1 | 0 | P6 = 3: breve head |
| code01-p6-diamond-down | match | 10/10 | 1/1 | 0 | white diamond, stem down |
| code01-p6-diamond-x | match | 9/9 | 1/1 | 0 | P6 = 8: diamond-x head |
| code01-p6-half | match | 7/7 | 1/1 | 0 | P6 = 1: half head |
| code01-p6-half-down | match | 7/7 | 1/1 | 0 | half note, stem down |
| code01-p6-half-up | match | 7/7 | 1/1 | 0 | half note, stem up |
| code01-p6-headless | match | 6/6 | 1/1 | 0 | P6 = 7: headless head |
| code01-p6-headless-m1 | match | 6/6 | 1/1 | 0 | P6 = -1: headless |
| code01-p6-library-103 | match | 6/6 | 1/1 | 0 | library symbol 103 as head |
| code01-p6-library-139 | match | 8/8 | 1/1 | 0 | library symbol 139 as head |
| code01-p6-library-208 | match | 7/7 | 1/1 | 0 | library symbol 208 as head |
| code01-p6-library-30 | match | 7/7 | 1/1 | 0 | library symbol 30 as head |
| code01-p6-library-38 | match | 8/8 | 1/1 | 0 | library symbol 38 as head |
| code01-p6-library-95 | match | 9/9 | 1/1 | 0 | library symbol 95 as head |
| code01-p6-library-stem-down | match | 7/7 | 1/1 | 0 | library symbol 30 as head, stem down |
| code01-p6-m3 | match | 7/7 | 1/1 | 0 | P6 = -3 |
| code01-p6-oval-x | match | 8/8 | 1/1 | 0 | P6 = 9: oval-x head |
| code01-p6-paren-black | match | 9/9 | 1/1 | 0 | P6 = 10: black head in parentheses |
| code01-p6-paren-dot | match | 10/10 | 1/1 | 0 | parenthesised head with a dot |
| code01-p6-paren-double-flat | match | 15/15 | 1/1 | 0 | parenthesised head with a double flat |
| code01-p6-paren-flat | match | 12/12 | 1/1 | 0 | parenthesised head with a flat |
| code01-p6-paren-half | match | 9/9 | 1/1 | 0 | P6 = 11: half head in parentheses |
| code01-p6-paren-oval-x | match | 10/10 | 1/1 | 0 | P6 = 19: oval-x head in parentheses |
| code01-p6-paren-two-dots | match | 11/11 | 1/1 | 0 | parenthesised head with two dots |
| code01-p6-paren-white-diamond | match | 12/12 | 1/1 | 0 | P6 = 14: white-diamond head in parentheses |
| code01-p6-paren-whole | match | 8/8 | 1/1 | 0 | P6 = 12: whole head in parentheses |
| code01-p6-paren-width | match | 9/9 | 1/1 | 0 | parenthesised head, note width P20 = 1.4 |
| code01-p6-paren-x | match | 10/10 | 1/1 | 0 | P6 = 16: x head in parentheses |
| code01-p6-tab-grace | match | 5/5 | 2/2 | 0 | tablature P4 = 105 |
| code01-p6-tab-m6 | match | 5/5 | 2/2 | 0 | P6 = -6: six-string tablature |
| code01-p6-tab-p10-999 | match | 5/5 | 1/1 | 0 | P10 = 999: nothing drawn |
| code01-p6-tab-p12-100 | match | 5/5 | 4/4 | 0 | tablature P12 = 100 |
| code01-p6-tab-p12-102 | match | 5/5 | 4/4 | 0 | tablature P12 = 102 |
| code01-p6-tab-p12-2 | match | 5/5 | 2/2 | 0 | tablature P12 = 2 |
| code01-p6-tab-p12-tie | match | 5/5 | 4/4 | 0 | tablature P12 = 100, P9 = 99 ('Tie') |
| code01-p6-tab-p13 | match | 5/5 | 2/2 | 0 | tablature rotated P13 = 30 |
| code01-p6-tab-p14 | match | 5/5 | 2/2 | 0 | tablature moved P14 = 1.5 |
| code01-p6-tab-p15 | match | 5/5 | 2/2 | 0 | tablature size P15 = 0.8 |
| code01-p6-tab-p16-201 | match | 5/5 | 2/2 | 0 | tuning change P16 = 201 |
| code01-p6-tab-p17-2 | match | 5/5 | 2/2 | 0 | tuning change P17 = 2 |
| code01-p6-tab-p18-99 | match | 5/5 | 2/2 | 0 | tuning change P18 = 99 |
| code01-p6-tab-p19-150 | match | 5/5 | 2/2 | 0 | tuning change P19 = 150 |
| code01-p6-tab-p19-2 | match | 5/5 | 2/2 | 0 | tuning change P19 = 2 |
| code01-p6-tab-p20 | match | 6/6 | 2/2 | 0 | tablature with a white box P20 = 1 |
| code01-p6-tab-p26 | match | 5/5 | 2/2 | 0 | tablature in red |
| code01-p6-tab-p4-0 | match | 5/5 | 2/2 | 0 | six-string tablature P4 = 0 |
| code01-p6-tab-p4-10 | match | 5/5 | 2/2 | 0 | six-string tablature P4 = 10 |
| code01-p6-tab-p4-14 | match | 5/5 | 2/2 | 0 | six-string tablature P4 = 14 |
| code01-p6-tab-p4-21 | match | 5/5 | 3/3 | 0 | six-string tablature P4 = 21 |
| code01-p6-tab-p4-7 | match | 5/5 | 2/2 | 0 | six-string tablature P4 = 7 |
| code01-p6-tab-p4-m3 | match | 5/5 | 2/2 | 0 | six-string tablature P4 = -3 |
| code01-p6-tab-p5-1 | match | 5/5 | 2/2 | 0 | six-string tablature P5 = 1 |
| code01-p6-tab-p5-11 | match | 5/5 | 2/2 | 0 | six-string tablature P5 = 11 |
| code01-p6-tab-p5-2 | match | 5/5 | 2/2 | 0 | six-string tablature P5 = 2 |
| code01-p6-tab-p5-22 | match | 5/5 | 2/2 | 0 | six-string tablature P5 = 22 |
| code01-p6-tab-p8-102 | match | 5/5 | 2/2 | 0 | forced string P8 = 102 |
| code01-p6-tab-p8-2 | match | 5/5 | 2/2 | 0 | forced string P8 = 2 |
| code01-p6-tab-p8-5 | match | 5/5 | 3/3 | 0 | forced string P8 = 5 |
| code01-p6-tab-p9-m1 | match | 5/5 | 2/2 | 0 | dead note P9 = -1 |
| code01-p6-tab-strings-m14 | match | 5/5 | 2/2 | 0 | tablature P6 = -14 |
| code01-p6-tab-strings-m156 | match | 5/5 | 3/3 | 0 | tablature P6 = -156 |
| code01-p6-tab-strings-m16 | match | 5/5 | 2/2 | 0 | tablature P6 = -16 |
| code01-p6-tab-strings-m4 | match | 5/5 | 2/2 | 0 | tablature P6 = -4 |
| code01-p6-tab-strings-m46 | match | 5/5 | 1/1 | 0 | tablature P6 = -46 |
| code01-p6-tab-strings-m5 | match | 5/5 | 2/2 | 0 | tablature P6 = -5 |
| code01-p6-tab-strings-m7 | match | 5/5 | 2/2 | 0 | tablature P6 = -7 |
| code01-p6-tab-strings-m8 | match | 5/5 | 2/2 | 0 | tablature P6 = -8 |
| code01-p6-tab-strings-m86 | match | 5/5 | 2/2 | 0 | tablature P6 = -86 |
| code01-p6-tab-strings-m96 | match | 5/5 | 2/2 | 0 | tablature P6 = -96 |
| code01-p6-tab-two-digits-paren | match | 5/5 | 4/4 | 0 | fret 12 in parentheses |
| code01-p6-white-diamond | match | 10/10 | 1/1 | 0 | P6 = 4: white-diamond head |
| code01-p6-whole | match | 6/6 | 1/1 | 0 | P6 = 2: whole head |
| code01-p6-whole-down | match | 6/6 | 1/1 | 0 | whole head with P5 = 20 (no stem) |
| code01-p6-x | match | 8/8 | 1/1 | 0 | P6 = 6: x head |
| code01-p6-x-down | match | 8/8 | 1/1 | 0 | X head, stem down |
| code01-p7-m1 | match | 9/9 | 1/1 | 0 | P7 = -1 on a ledger note (P4 = -2) |
| code01-p7-m2 | match | 7/7 | 1/1 | 0 | P7 = -2 on a ledger note (P4 = -2) |
| code01-p7-m2-high | match | 7/7 | 1/1 | 0 | P7 = -2 on P4 = 15 |
| code01-p7-m3 | match | 7/7 | 1/1 | 0 | P7 = -3 on a ledger note (P4 = -2) |
| code01-p8-0.5 | match | 7/7 | 1/1 | 0 | stem length P8 = 0.5 |
| code01-p8-1.5 | match | 7/7 | 1/1 | 0 | stem length P8 = 1.5 |
| code01-p8-m2 | match | 7/7 | 1/1 | 0 | stem length P8 = -2 |
| code01-p8-m2-down | match | 7/7 | 1/1 | 0 | P8 = -2, stem down |
| code01-p8-slash-no-tail | match | 7/7 | 1/1 | 0 | P8 = 101 without a tail (no slash) |
| code01-p8-tail | match | 9/9 | 1/1 | 0 | P8 = 1.5 with a tail |
| code01-p8-tail-down | match | 9/9 | 1/1 | 0 | P8 = 1.5 with a tail, stem down |
| code01-p9-dot-below-110 | match | 8/8 | 1/1 | 0 | P9 = 110: dot below the line |
| code01-p9-dot-below-space | match | 8/8 | 1/1 | 0 | P9 = 110 on a space note |
| code01-p9-dot-down-line | match | 8/8 | 1/1 | 0 | dot on a line note, stem down |
| code01-p9-dot-headless | match | 7/7 | 1/1 | 0 | dot on a headless note, stem down |
| code01-p9-dot-headless-m1 | match | 7/7 | 1/1 | 0 | dot on a P6 = -1 note, stem down |
| code01-p9-dot-left-0.4 | match | 8/8 | 1/1 | 0 | P9 = 10.94: dot 0.4 left |
| code01-p9-dot-no-stem | match | 7/7 | 1/1 | 0 | dot without a stem (P5 = 0) |
| code01-p9-dot-no-stem-high | match | 7/7 | 1/1 | 0 | dot without a stem on P4 = 9 |
| code01-p9-dot-tail-down | match | 10/10 | 1/1 | 0 | dot and tail, stem down |
| code01-p9-dot-tail-p8 | match | 10/10 | 1/1 | 0 | dot and tail, stem up, P8 = 1 |
| code01-p9-dot-tail-up | match | 10/10 | 1/1 | 0 | dot and tail, stem up (P9 = 11) |
| code01-p9-dot-wide-1010 | match | 8/8 | 1/1 | 0 | P9 = 1010: dot one note width right |
| code01-p9-dot-wide-below-1110 | match | 8/8 | 1/1 | 0 | P9 = 1110 |
| code01-p9-dots-1-line | match | 8/8 | 1/1 | 0 | 1 dot(s) on a line note |
| code01-p9-dots-1-space | match | 8/8 | 1/1 | 0 | 1 dot(s) on a space note (P4 = 4) |
| code01-p9-dots-2-line | match | 9/9 | 1/1 | 0 | 2 dot(s) on a line note |
| code01-p9-dots-2-space | match | 9/9 | 1/1 | 0 | 2 dot(s) on a space note (P4 = 4) |
| code01-p9-dots-3-line | match | 10/10 | 1/1 | 0 | 3 dot(s) on a line note |
| code01-p9-dots-right-3.1 | match | 9/9 | 1/1 | 0 | P9 = 20.31: two dots 3.1 right |
| code01-p9-half-dot-tails | match | 13/13 | 1/1 | 0 | half head, two dots, two tails |
| code01-p9-tails-1-down | match | 9/9 | 1/1 | 0 | 1 tail(s), stem down |
| code01-p9-tails-1-up | match | 9/9 | 1/1 | 0 | 1 tail(s), stem up |
| code01-p9-tails-2-down | match | 11/11 | 1/1 | 0 | 2 tail(s), stem down |
| code01-p9-tails-2-up | match | 11/11 | 1/1 | 0 | 2 tail(s), stem up |
| code01-p9-tails-3-down | match | 13/13 | 1/1 | 0 | 3 tail(s), stem down |
| code01-p9-tails-3-up | match | 13/13 | 1/1 | 0 | 3 tail(s), stem up |
| code01-p9-tails-4-down | match | 15/15 | 1/1 | 0 | 4 tail(s), stem down |
| code01-p9-tails-4-up | match | 15/15 | 1/1 | 0 | 4 tail(s), stem up |
| code01-p9-whole-dot | match | 7/7 | 1/1 | 0 | dotted whole note |
| code01-sample-chord-flats | match | 14/14 | 1/1 | 0 | stemless note with displaced flat (P5 1.155) and stem-down note with flat at the same P3, staff size 0.85 (sonlcs.mus items 315, 316) |
| code01-staff-0.73-base | match | 7/7 | 1/1 | 0 | staff size 0.73: base note |
| code01-staff-0.73-down | match | 10/10 | 1/1 | 0 | staff size 0.73: stem down, tail, accent |
| code01-staff-0.73-full | match | 18/18 | 1/1 | 0 | staff size 0.73: sharp, dot, two tails, ledger line |
| code01-staff-1.3-base | match | 7/7 | 1/1 | 0 | staff size 1.3: base note |
| code01-staff-1.3-down | match | 10/10 | 1/1 | 0 | staff size 1.3: stem down, tail, accent |
| code01-staff-1.3-full | match | 18/18 | 1/1 | 0 | staff size 1.3: sharp, dot, two tails, ledger line |
| code01-staff-p4-offset | match | 8/8 | 1/1 | 0 | note on a staff moved up (P4 = 2.5) |
| code01-staff-recto | match | 7/7 | 3/3 | 0 | note on staff 201 (recto page) |
| code02-font-after-gp | match | 9/9 | 16/16 | 0 | plain text after _02 text and a G.P. rest (font 1000) |
| code02-font-after-gp-p14 | match | 9/9 | 16/16 | 0 | plain text after _02 text and a G.P. rest in font P14 = 4 |
| code02-font-after-number | match | 7/7 | 12/12 | 0 | plain text after _02 text and a rest number (meter font, loads none) |
| code02-font-after-number-p14 | match | 6/6 | 13/13 | 0 | plain text after _02 text and a rest number in font P14 = 2 |
| code02-grace-dot | match | 10/10 | 1/1 | 0 | grace quarter rest with a dot |
| code02-grace-eighth | match | 7/7 | 1/1 | 0 | grace-size eighth rest (P4 = 100) |
| code02-grace-fermata | match | 11/11 | 1/1 | 0 | grace quarter rest with a fermata |
| code02-grace-half | match | 6/6 | 1/1 | 0 | grace-size half rest (P4 = 100) |
| code02-grace-p4-103 | match | 9/9 | 1/1 | 0 | grace quarter rest P4 = 103 |
| code02-grace-quarter | match | 9/9 | 1/1 | 0 | grace-size quarter rest (P4 = 100) |
| code02-grace-sixteenth | match | 9/9 | 1/1 | 0 | grace-size sixteenth rest (P4 = 100) |
| code02-grace-whole | match | 6/6 | 1/1 | 0 | grace-size whole rest (P4 = 100) |
| code02-mixed-bar | match | 46/46 | 1/1 | 0 | twelve rests of different kinds on one staff |
| code02-p10-2 | match | 9/9 | 1/1 | 0 | offset P10 = 2 |
| code02-p10-m3 | match | 9/9 | 1/1 | 0 | offset P10 = -3 |
| code02-p10-whole | match | 6/6 | 1/1 | 0 | offset P10 = 2 on a whole rest |
| code02-p11-fermata-height | match | 11/11 | 1/1 | 0 | fermata height P11 = -2 |
| code02-p11-height-3 | match | 7/7 | 1/1 | 0 | number height P11 = 3 |
| code02-p12-fermata-size | match | 11/11 | 1/1 | 0 | fermata size P12 = 1.5 |
| code02-p12-size-1.5 | match | 7/7 | 1/1 | 0 | number size P12 = 1.5 |
| code02-p13-cue | match | 9/9 | 1/1 | 0 | cue instrument P13 = 3 |
| code02-p14-font-2 | match | 6/6 | 2/2 | 0 | number font P14 = 2 |
| code02-p15-0.75-quarter | match | 9/9 | 1/1 | 0 | rest size P15 = 0.75, quarter |
| code02-p15-0.75-sixteenth | match | 9/9 | 1/1 | 0 | rest size P15 = 0.75, sixteenth |
| code02-p15-0.75-whole | match | 6/6 | 1/1 | 0 | rest size P15 = 0.75, whole |
| code02-p15-1.3-quarter | match | 9/9 | 1/1 | 0 | rest size P15 = 1.3, quarter |
| code02-p15-1.3-sixteenth | match | 9/9 | 1/1 | 0 | rest size P15 = 1.3, sixteenth |
| code02-p15-1.3-whole | match | 6/6 | 1/1 | 0 | rest size P15 = 1.3, whole |
| code02-p15-dot-number | match | 12/12 | 1/1 | 0 | P15 = 0.75 with dot and fermata |
| code02-p16-fermata-move | match | 11/11 | 1/1 | 0 | fermata moved P16 = -1.5 |
| code02-p16-move-2 | match | 7/7 | 1/1 | 0 | number moved P16 = 2 |
| code02-p17-1 | match | 19/19 | 3/3 | 0 | rest on staff 2 shown on staff above (P17 = 1) |
| code02-p17-2 | match | 19/19 | 3/3 | 0 | rest on staff 2 shown on staff below (P17 = 2) |
| code02-p20-spread-1 | match | 8/8 | 1/1 | 0 | number digits spread P20 = 1 |
| code02-p26-grey | match | 9/9 | 1/1 | 0 | grey rest P26 = 0.5 |
| code02-p3-20.3 | match | 9/9 | 1/1 | 0 | P3 = 20.3 |
| code02-p30-m1-whole | match | 6/6 | 1/1 | 0 | whole rest P4 = 4 with P30 = -1 (no ledger line) |
| code02-p4-2-half | match | 6/6 | 1/1 | 0 | half rest P4 = 2 |
| code02-p4-2-whole | match | 6/6 | 1/1 | 0 | whole rest P4 = 2 |
| code02-p4-2.5-quarter | match | 9/9 | 1/1 | 0 | quarter rest P4 = 2.5 |
| code02-p4-3-quarter | match | 9/9 | 1/1 | 0 | quarter rest P4 = 3 |
| code02-p4-3-whole | match | 6/6 | 1/1 | 0 | whole rest P4 = 3 |
| code02-p4-4-eighth | match | 7/7 | 1/1 | 0 | eighth rest P4 = 4 |
| code02-p4-4-half | match | 6/6 | 1/1 | 0 | half rest P4 = 4 |
| code02-p4-4-whole | match | 7/7 | 1/1 | 0 | whole rest P4 = 4 |
| code02-p4-5-half | match | 7/7 | 1/1 | 0 | half rest P4 = 5 |
| code02-p4-6-whole | match | 7/7 | 1/1 | 0 | whole rest P4 = 6 |
| code02-p4-7-half | match | 7/7 | 1/1 | 0 | half rest P4 = 7 |
| code02-p4-m2-whole | match | 6/6 | 1/1 | 0 | whole rest P4 = -2 |
| code02-p4-m3-sixteenth | match | 9/9 | 1/1 | 0 | sixteenth rest P4 = -3 |
| code02-p4-m4-quarter | match | 9/9 | 1/1 | 0 | quarter rest P4 = -4 |
| code02-p4-m6-half | match | 7/7 | 1/1 | 0 | half rest P4 = -6 |
| code02-p4-m7-half | match | 7/7 | 1/1 | 0 | half rest P4 = -7 |
| code02-p4-m7-whole | match | 7/7 | 1/1 | 0 | whole rest P4 = -7 |
| code02-p4-m8-whole | match | 7/7 | 1/1 | 0 | whole rest P4 = -8 |
| code02-p5-128th | match | 15/15 | 1/1 | 0 | P5 = 5: 128th rest |
| code02-p5-256th | match | 17/17 | 1/1 | 0 | P5 = 6: 256th rest |
| code02-p5-32nd | match | 11/11 | 1/1 | 0 | P5 = 3: 32nd rest |
| code02-p5-64th | match | 13/13 | 1/1 | 0 | P5 = 4: 64th rest |
| code02-p5-composite-m11 | match | 6/6 | 1/1 | 0 | P5 = -11: composite rest |
| code02-p5-composite-m12 | match | 6/6 | 1/1 | 0 | P5 = -12: composite rest |
| code02-p5-composite-m13 | match | 7/7 | 1/1 | 0 | P5 = -13: composite rest |
| code02-p5-composite-m14 | match | 6/6 | 1/1 | 0 | P5 = -14: composite rest |
| code02-p5-composite-m15 | match | 7/7 | 1/1 | 0 | P5 = -15: composite rest |
| code02-p5-composite-m16 | match | 7/7 | 1/1 | 0 | P5 = -16: composite rest |
| code02-p5-composite-m17 | match | 8/8 | 1/1 | 0 | P5 = -17: composite rest |
| code02-p5-composite-m18 | match | 7/7 | 1/1 | 0 | P5 = -18: composite rest |
| code02-p5-composite-m19 | match | 8/8 | 1/1 | 0 | P5 = -19: composite rest |
| code02-p5-eighth | match | 7/7 | 1/1 | 0 | P5 = 1: eighth rest |
| code02-p5-four-bar | match | 6/6 | 1/1 | 0 | P5 = -7: four-bar rest |
| code02-p5-h-bar | match | 8/8 | 1/1 | 0 | P5 = -5: h-bar rest |
| code02-p5-h-bar-p9 | match | 8/8 | 1/1 | 0 | P5 = -5, right end P9 = 60 |
| code02-p5-h-bar-p9-number | match | 9/9 | 1/1 | 0 | P5 = -5, P9 = 60, number P8 = 8 |
| code02-p5-half | match | 6/6 | 1/1 | 0 | P5 = -1: half rest |
| code02-p5-hundreds-0 | match | 11/11 | 1/1 | 0 | P5 = 100: quarter rest, hundreds flag |
| code02-p5-hundreds-1 | match | 9/9 | 1/1 | 0 | P5 = 101: eighth rest, hundreds flag |
| code02-p5-hundreds-m1 | match | 8/8 | 1/1 | 0 | P5 = -101: half rest, hundreds flag |
| code02-p5-hundreds-m101-p9 | match | 8/8 | 1/1 | 0 | P5 = -101 with P9 = 30 |
| code02-p5-hundreds-m2 | match | 8/8 | 1/1 | 0 | P5 = -102: whole rest, hundreds flag |
| code02-p5-multi-bar | match | 6/6 | 1/1 | 0 | P5 = -3: multi-bar rest |
| code02-p5-quarter | match | 9/9 | 1/1 | 0 | P5 = 0: quarter rest |
| code02-p5-repeat | match | 8/8 | 1/1 | 0 | P5 = -4: repeat rest |
| code02-p5-sixteenth | match | 9/9 | 1/1 | 0 | P5 = 2: sixteenth rest |
| code02-p5-two-bar | match | 6/6 | 1/1 | 0 | P5 = -6: two-bar rest |
| code02-p5-two-bar-repeat | match | 9/9 | 1/1 | 0 | P5 = -44: two-bar repeat |
| code02-p5-two-bar-repeat-p8 | match | 10/10 | 1/1 | 0 | P5 = -44 with P8 = 2 |
| code02-p5-unused-m10 | match | 5/5 | 1/1 | 0 | P5 = -10 (not drawn) |
| code02-p5-unused-m20 | match | 5/5 | 1/1 | 0 | P5 = -20 (not drawn) |
| code02-p5-unused-m8 | match | 5/5 | 1/1 | 0 | P5 = -8 (not drawn) |
| code02-p5-unused-m9 | match | 5/5 | 1/1 | 0 | P5 = -9 (not drawn) |
| code02-p5-whole | match | 6/6 | 1/1 | 0 | P5 = -2: whole rest |
| code02-p6-composite-spacing | match | 7/7 | 1/1 | 0 | P6 = 1.5 on a composite rest |
| code02-p6-dot-p4 | match | 8/8 | 1/1 | 0 | dotted eighth rest P4 = 3 |
| code02-p6-dots-1-32nd | match | 12/12 | 1/1 | 0 | 1 dot(s) on a 32nd rest |
| code02-p6-dots-1-64th | match | 14/14 | 1/1 | 0 | 1 dot(s) on a 64th rest |
| code02-p6-dots-1-eighth | match | 8/8 | 1/1 | 0 | 1 dot(s) on a eighth rest |
| code02-p6-dots-1-half | match | 7/7 | 1/1 | 0 | 1 dot(s) on a half rest |
| code02-p6-dots-1-quarter | match | 10/10 | 1/1 | 0 | 1 dot(s) on a quarter rest |
| code02-p6-dots-1-sixteenth | match | 10/10 | 1/1 | 0 | 1 dot(s) on a sixteenth rest |
| code02-p6-dots-1-whole | match | 7/7 | 1/1 | 0 | 1 dot(s) on a whole rest |
| code02-p6-dots-1.5 | match | 10/10 | 1/1 | 0 | P6 = 1.5: dot moved right |
| code02-p6-dots-2-32nd | match | 13/13 | 1/1 | 0 | 2 dot(s) on a 32nd rest |
| code02-p6-dots-2-64th | match | 15/15 | 1/1 | 0 | 2 dot(s) on a 64th rest |
| code02-p6-dots-2-eighth | match | 9/9 | 1/1 | 0 | 2 dot(s) on a eighth rest |
| code02-p6-dots-2-half | match | 8/8 | 1/1 | 0 | 2 dot(s) on a half rest |
| code02-p6-dots-2-quarter | match | 11/11 | 1/1 | 0 | 2 dot(s) on a quarter rest |
| code02-p6-dots-2-sixteenth | match | 11/11 | 1/1 | 0 | 2 dot(s) on a sixteenth rest |
| code02-p6-dots-2-whole | match | 8/8 | 1/1 | 0 | 2 dot(s) on a whole rest |
| code02-p6-dots-3 | match | 12/12 | 1/1 | 0 | three dots on a quarter rest |
| code02-p6-invisible | match | 9/9 | 1/1 | 0 | P6 = -1: invisible rest |
| code02-p6-invisible-whole | match | 6/6 | 1/1 | 0 | P6 = -1: invisible whole rest |
| code02-p6-line-12-multi-bar | match | 7/7 | 1/1 | 0 | P6 = 12: centring line, multi-bar rest |
| code02-p6-line-12-quarter | match | 10/10 | 1/1 | 0 | P6 = 12: centring line, quarter rest |
| code02-p6-line-12-whole | match | 7/7 | 1/1 | 0 | P6 = 12: centring line, whole rest |
| code02-p6-line-6-multi-bar | match | 7/7 | 1/1 | 0 | P6 = 6: centring line, multi-bar rest |
| code02-p6-line-6-quarter | match | 10/10 | 1/1 | 0 | P6 = 6: centring line, quarter rest |
| code02-p6-line-6-whole | match | 7/7 | 1/1 | 0 | P6 = 6: centring line, whole rest |
| code02-p6-multi-bar-dots | match | 8/8 | 1/1 | 0 | P6 = 2 on a multi-bar rest (dots dropped) |
| code02-p8-fermata-eighth | match | 9/9 | 1/1 | 0 | P8 = -1: fermata over a eighth rest |
| code02-p8-fermata-half | match | 8/8 | 1/1 | 0 | P8 = -1: fermata over a half rest |
| code02-p8-fermata-quarter | match | 11/11 | 1/1 | 0 | P8 = -1: fermata over a quarter rest |
| code02-p8-fermata-whole | match | 8/8 | 1/1 | 0 | P8 = -1: fermata over a whole rest |
| code02-p8-inverted-fermata-eighth | match | 9/9 | 1/1 | 0 | P8 = -2: inverted-fermata over a eighth rest |
| code02-p8-inverted-fermata-half | match | 8/8 | 1/1 | 0 | P8 = -2: inverted-fermata over a half rest |
| code02-p8-inverted-fermata-quarter | match | 11/11 | 1/1 | 0 | P8 = -2: inverted-fermata over a quarter rest |
| code02-p8-inverted-fermata-whole | match | 8/8 | 1/1 | 0 | P8 = -2: inverted-fermata over a whole rest |
| code02-p8-m3 | match | 9/9 | 5/5 | 0 | P8 = -3 over a quarter rest |
| code02-p8-number-101 | match | 9/9 | 1/1 | 0 | number P8 = 101 over a multi-bar rest |
| code02-p8-number-111 | match | 9/9 | 1/1 | 0 | number P8 = 111 over a multi-bar rest |
| code02-p8-number-12 | match | 8/8 | 1/1 | 0 | number P8 = 12 over a multi-bar rest |
| code02-p8-number-123 | match | 9/9 | 1/1 | 0 | number P8 = 123 over a multi-bar rest |
| code02-p8-number-211 | match | 9/9 | 1/1 | 0 | number P8 = 211 over a multi-bar rest |
| code02-p8-number-3 | match | 7/7 | 1/1 | 0 | number P8 = 3 over a multi-bar rest |
| code02-p8-number-eighth | match | 9/9 | 1/1 | 0 | number P8 = 11 over an eighth rest |
| code02-p8-number-p4 | match | 7/7 | 1/1 | 0 | number over a multi-bar rest at P4 = 4 |
| code02-p8-number-quarter | match | 10/10 | 1/1 | 0 | number P8 = 5 over a quarter rest |
| code02-p8-number-whole | match | 7/7 | 1/1 | 0 | number P8 = 5 over a whole rest |
| code02-p9-30-multi-bar | match | 6/6 | 1/1 | 0 | multi-bar rest drawn at P9 = 30 |
| code02-p9-30-quarter | match | 9/9 | 1/1 | 0 | quarter rest with P9 = 30 |
| code02-p9-30-whole | match | 6/6 | 1/1 | 0 | whole rest drawn at P9 = 30 |
| code02-p9-cw-composite | match | 9/9 | 1/1 | 0 | composite rest centred between barlines |
| code02-p9-cw-h-bar | match | 10/10 | 1/1 | 0 | h-bar rest spread between barlines |
| code02-p9-cw-multi-bar | match | 8/8 | 1/1 | 0 | multi-bar rest centred between barlines |
| code02-p9-cw-repeat | match | 10/10 | 1/1 | 0 | repeat sign centred between barlines |
| code02-p9-cw-whole | match | 8/8 | 1/1 | 0 | whole rest centred between barlines (P9 = -1) |
| code02-staff-0.73-quarter | match | 9/9 | 1/1 | 0 | staff size 0.73: quarter rest |
| code02-staff-0.73-sixteenth-dot | match | 10/10 | 1/1 | 0 | staff size 0.73: dotted sixteenth |
| code02-staff-0.73-whole-number | match | 7/7 | 1/1 | 0 | staff size 0.73: whole rest with number 3 |
| code02-staff-1.3-quarter | match | 9/9 | 1/1 | 0 | staff size 1.3: quarter rest |
| code02-staff-1.3-sixteenth-dot | match | 10/10 | 1/1 | 0 | staff size 1.3: dotted sixteenth |
| code02-staff-1.3-whole-number | match | 7/7 | 1/1 | 0 | staff size 1.3: whole rest with number 3 |
| code02-staff-recto | match | 9/9 | 3/3 | 0 | rest on staff 201 (recto page) |
| code03-no-staff | match | 5/5 | 0/0 | 0 | treble clef without a staff |
| code03-p10-pixels-1-bass | match | 30/30 | 1/1 | 0 | pixel thickness P10 = 1, type 1 |
| code03-p10-pixels-1-treble | match | 30/30 | 1/1 | 0 | pixel thickness P10 = 1, type 0 |
| code03-p10-pixels-2-bass | match | 50/50 | 1/1 | 0 | pixel thickness P10 = 2, type 1 |
| code03-p10-pixels-2-treble | match | 50/50 | 1/1 | 0 | pixel thickness P10 = 2, type 0 |
| code03-p10-pixels-m1-bass | match | 10/10 | 1/1 | 0 | pixel thickness P10 = -1, type 1 |
| code03-p10-pixels-m1-treble | match | 10/10 | 1/1 | 0 | pixel thickness P10 = -1, type 0 |
| code03-p15-offset-0.5 | match | 10/10 | 1/1 | 0 | offset P15 = 0.5 |
| code03-p15-offset-0.5-treble-8va | match | 10/10 | 2/2 | 0 | offset P15 = 0.5, octave number |
| code03-p15-offset-3 | match | 10/10 | 1/1 | 0 | offset P15 = 3 |
| code03-p15-offset-m0.5 | match | 10/10 | 1/1 | 0 | offset P15 = -0.5 |
| code03-p15-offset-m2-treble-8va | match | 10/10 | 2/2 | 0 | offset P15 = -2, octave number |
| code03-p26-grey | match | 10/10 | 1/1 | 0 | P26 = 0.5 |
| code03-p26-red-treble-8va | match | 10/10 | 2/2 | 0 | P26 = 990000 with octave number |
| code03-p3-pos-0 | match | 10/10 | 1/1 | 0 | P3 = 0 |
| code03-p3-pos-0.3 | match | 10/10 | 1/1 | 0 | P3 = 0.3 |
| code03-p3-pos-150.7 | match | 10/10 | 1/1 | 0 | P3 = 150.7 |
| code03-p4-0.5-alto | match | 14/14 | 1/1 | 0 | P4 = 0.5, type 2 |
| code03-p4-0.5-treble | match | 10/10 | 1/1 | 0 | P4 = 0.5, type 0 |
| code03-p4-2-alto | match | 14/14 | 1/1 | 0 | P4 = 2, type 2 |
| code03-p4-2-treble | match | 10/10 | 1/1 | 0 | P4 = 2, type 0 |
| code03-p4-m2-alto | match | 14/14 | 1/1 | 0 | P4 = -2, type 2 |
| code03-p4-m2-treble | match | 10/10 | 1/1 | 0 | P4 = -2, type 0 |
| code03-p4-mini-100-alto | match | 14/14 | 1/1 | 0 | mini clef P4 = 100, type 2 |
| code03-p4-mini-100-bass | match | 10/10 | 1/1 | 0 | mini clef P4 = 100, type 1 |
| code03-p4-mini-100-bass-8vb | match | 10/10 | 2/2 | 0 | mini clef P4 = 100, type 1.8 |
| code03-p4-mini-100-percussion | match | 7/7 | 1/1 | 0 | mini clef P4 = 100, type 4 |
| code03-p4-mini-100-tab-4 | match | 8/8 | 1/1 | 0 | mini clef P4 = 100, type 44 |
| code03-p4-mini-100-tenor | match | 14/14 | 1/1 | 0 | mini clef P4 = 100, type 3 |
| code03-p4-mini-100-treble | match | 10/10 | 1/1 | 0 | mini clef P4 = 100, type 0 |
| code03-p4-mini-100-treble-8va | match | 10/10 | 2/2 | 0 | mini clef P4 = 100, type 0.88 |
| code03-p4-mini-100-treble-8vb | match | 10/10 | 2/2 | 0 | mini clef P4 = 100, type 0.8 |
| code03-p4-mini-102-treble | match | 10/10 | 1/1 | 0 | mini clef P4 = 102, type 0 |
| code03-p4-mini-m100-alto | match | 14/14 | 1/1 | 0 | mini clef P4 = -100, type 2 |
| code03-p4-mini-m100-bass | match | 10/10 | 1/1 | 0 | mini clef P4 = -100, type 1 |
| code03-p4-mini-m100-percussion | match | 7/7 | 1/1 | 0 | mini clef P4 = -100, type 4 |
| code03-p4-mini-m100-tenor | match | 14/14 | 1/1 | 0 | mini clef P4 = -100, type 3 |
| code03-p4-mini-m100-treble | match | 10/10 | 1/1 | 0 | mini clef P4 = -100, type 0 |
| code03-p5-alto | match | 14/14 | 1/1 | 0 | clef type P5 = 2 |
| code03-p5-bass | match | 10/10 | 1/1 | 0 | clef type P5 = 1 |
| code03-p5-bass-8vb | match | 10/10 | 2/2 | 0 | clef type P5 = 1.8 |
| code03-p5-brace | match | 6/6 | 1/1 | 0 | clef type P5 = 5 |
| code03-p5-flat | match | 8/8 | 1/1 | 0 | clef type P5 = 6 |
| code03-p5-negative | match | 10/10 | 1/1 | 0 | clef type P5 = -1 |
| code03-p5-percussion | match | 7/7 | 1/1 | 0 | clef type P5 = 4 |
| code03-p5-sharp | match | 9/9 | 1/1 | 0 | clef type P5 = 7 |
| code03-p5-symbol-45 | match | 5/5 | 4/4 | 0 | clef type P5 = 45 |
| code03-p5-tab-4 | match | 8/8 | 1/1 | 0 | clef type P5 = 44 |
| code03-p5-tab-5 | match | 8/8 | 1/1 | 0 | clef type P5 = 55 |
| code03-p5-tab-6 | match | 8/8 | 1/1 | 0 | clef type P5 = 66 |
| code03-p5-tenor | match | 14/14 | 1/1 | 0 | clef type P5 = 3 |
| code03-p5-treble | match | 10/10 | 1/1 | 0 | clef type P5 = 0 |
| code03-p5-treble-15ma | match | 10/10 | 3/3 | 0 | clef type P5 = 0.15 |
| code03-p5-treble-8va | match | 10/10 | 2/2 | 0 | clef type P5 = 0.88 |
| code03-p5-treble-8vb | match | 10/10 | 2/2 | 0 | clef type P5 = 0.8 |
| code03-p6-p7-0-1.5-tab-6 | match | 8/8 | 1/1 | 0 | P6 = 0, P7 = 1.5, type 66 |
| code03-p6-p7-0-1.5-tenor | match | 14/14 | 1/1 | 0 | P6 = 0, P7 = 1.5, type 3 |
| code03-p6-p7-0-1.5-treble | match | 10/10 | 1/1 | 0 | P6 = 0, P7 = 1.5, type 0 |
| code03-p6-p7-0-1.5-treble-8va | match | 10/10 | 2/2 | 0 | P6 = 0, P7 = 1.5, type 0.88 |
| code03-p6-p7-0.5-2-tab-6 | match | 8/8 | 1/1 | 0 | P6 = 0.5, P7 = 2, type 66 |
| code03-p6-p7-0.5-2-tenor | match | 14/14 | 1/1 | 0 | P6 = 0.5, P7 = 2, type 3 |
| code03-p6-p7-0.5-2-treble | match | 10/10 | 1/1 | 0 | P6 = 0.5, P7 = 2, type 0 |
| code03-p6-p7-0.5-2-treble-8va | match | 10/10 | 2/2 | 0 | P6 = 0.5, P7 = 2, type 0.88 |
| code03-p6-p7-1-m1-tab-6 | match | 8/8 | 1/1 | 0 | P6 = 1, P7 = -1, type 66 |
| code03-p6-p7-1-m1-tenor | match | 14/14 | 1/1 | 0 | P6 = 1, P7 = -1, type 3 |
| code03-p6-p7-1-m1-treble | match | 10/10 | 1/1 | 0 | P6 = 1, P7 = -1, type 0 |
| code03-p6-p7-1-m1-treble-8va | match | 10/10 | 2/2 | 0 | P6 = 1, P7 = -1, type 0.88 |
| code03-p6-size-0.5-bass | match | 10/10 | 1/1 | 0 | size P6 = 0.5, type 1 |
| code03-p6-size-0.5-treble | match | 10/10 | 1/1 | 0 | size P6 = 0.5, type 0 |
| code03-p6-size-0.5-treble-8vb | match | 10/10 | 2/2 | 0 | size P6 = 0.5, type 0.8 |
| code03-p6-size-1.5-bass | match | 10/10 | 1/1 | 0 | size P6 = 1.5, type 1 |
| code03-p6-size-1.5-treble | match | 10/10 | 1/1 | 0 | size P6 = 1.5, type 0 |
| code03-p6-size-1.5-treble-8vb | match | 10/10 | 2/2 | 0 | size P6 = 1.5, type 0.8 |
| code03-p6-size-m1-bass | match | 10/10 | 1/1 | 0 | size P6 = -1, type 1 |
| code03-p6-size-m1-treble | match | 10/10 | 1/1 | 0 | size P6 = -1, type 0 |
| code03-p6-size-m1-treble-8vb | match | 10/10 | 2/2 | 0 | size P6 = -1, type 0.8 |
| code03-staff-p4-offset | match | 10/10 | 1/1 | 0 | staff P4 = 2.5, treble |
| code03-staff-recto-201 | match | 10/10 | 4/4 | 0 | recto staff 201, treble 8va |
| code03-staff-size-0.75-alto | match | 14/14 | 1/1 | 0 | staff size 0.75, type 2 |
| code03-staff-size-0.75-bass | match | 10/10 | 1/1 | 0 | staff size 0.75, type 1 |
| code03-staff-size-0.75-mini-bass | match | 10/10 | 1/1 | 0 | staff size 0.75, mini clef type 1 |
| code03-staff-size-0.75-mini-treble | match | 10/10 | 1/1 | 0 | staff size 0.75, mini clef type 0 |
| code03-staff-size-0.75-tab-5 | match | 8/8 | 1/1 | 0 | staff size 0.75, type 55 |
| code03-staff-size-0.75-treble | match | 10/10 | 1/1 | 0 | staff size 0.75, type 0 |
| code03-staff-size-0.75-treble-8va | match | 10/10 | 2/2 | 0 | staff size 0.75, type 0.88 |
| code03-staff-size-1.4-alto | match | 14/14 | 1/1 | 0 | staff size 1.4, type 2 |
| code03-staff-size-1.4-bass | match | 10/10 | 1/1 | 0 | staff size 1.4, type 1 |
| code03-staff-size-1.4-tab-5 | match | 8/8 | 1/1 | 0 | staff size 1.4, type 55 |
| code03-staff-size-1.4-treble | match | 10/10 | 1/1 | 0 | staff size 1.4, type 0 |
| code03-staff-size-1.4-treble-8va | match | 10/10 | 2/2 | 0 | staff size 1.4, type 0.88 |
| code03-staff-size-m1-alto | match | 14/14 | 1/1 | 0 | staff size -1, type 2 |
| code03-staff-size-m1-bass | match | 10/10 | 1/1 | 0 | staff size -1, type 1 |
| code03-staff-size-m1-tab-5 | match | 8/8 | 1/1 | 0 | staff size -1, type 55 |
| code03-staff-size-m1-treble | match | 10/10 | 1/1 | 0 | staff size -1, type 0 |
| code03-staff-size-m1-treble-8va | match | 10/10 | 2/2 | 0 | staff size -1, type 0.88 |
| code03-system | match | 48/48 | 4/4 | 0 | four staves with treble, alto, tenor, bass |
| code04-p0-horizontal | match | 6/6 | 1/1 | 0 | plain horizontal line |
| code04-p10-cresc-thick | match | 8/8 | 1/1 | 0 | crescendo, P10 1 |
| code04-p10-saw-thick | match | 8/8 | 1/1 | 0 | sawtooth line, P10 1 |
| code04-p10-thick-1 | match | 8/8 | 1/1 | 0 | horizontal, P10 1 |
| code04-p10-thick-3 | match | 12/12 | 1/1 | 0 | horizontal, P10 3 |
| code04-p10-thick-negative | match | 6/6 | 1/1 | 0 | horizontal, P10 -1 |
| code04-p10-thick-steep | match | 6/6 | 1/1 | 0 | steep line, P10 1 |
| code04-p10-thick-vertical | match | 10/10 | 1/1 | 0 | vertical line, P10 2 |
| code04-p10-thin-thick | match | 8/8 | 1/1 | 0 | thin wavy line, P10 1 |
| code04-p10-vertical-thick | match | 8/8 | 1/1 | 0 | vertical line, P7 -5, P10 1 |
| code04-p10-wavy-thick | match | 35/35 | 1/1 | 0 | heavy wavy line, P10 1 (ignored) |
| code04-p11-arrow | match | 7/7 | 1/1 | 0 | left arrow, P11 101 |
| code04-p11-bracket-down | match | 6/6 | 1/1 | 0 | left bracket, P11 -2 |
| code04-p11-bracket-up | match | 6/6 | 1/1 | 0 | left bracket, P11 2 |
| code04-p11-cresc-dashed | match | 57/57 | 1/1 | 0 | dashed crescendo, P11 1 |
| code04-p11-cresc-dashed-spread | match | 109/109 | 1/1 | 0 | dashed crescendo, P7 3, P8 0.5 |
| code04-p11-cresc-dashed-thick | match | 161/161 | 1/1 | 0 | dashed crescendo, P10 1 |
| code04-p11-decresc-dashed | match | 57/57 | 1/1 | 0 | dashed decrescendo, P11 1, P7 -1 |
| code04-p11-saw-thick | match | 66/66 | 1/1 | 0 | sawtooth with thick down slopes, P11 0.5 |
| code04-p11-updown | match | 6/6 | 1/1 | 0 | left bracket up and down, P11 202 |
| code04-p11-vertical-updown | match | 7/7 | 1/1 | 0 | vertical line, P11 201 |
| code04-p11p12-arrows | match | 8/8 | 1/1 | 0 | arrows at both ends, tilted |
| code04-p11p12-brackets | match | 6/6 | 1/1 | 0 | both brackets on a tilted line |
| code04-p11p12-vertical-brackets | match | 6/6 | 1/1 | 0 | vertical line with brackets P11 1, P12 -1 |
| code04-p12-arrow | match | 7/7 | 1/1 | 0 | right arrow, P12 101 |
| code04-p12-arrow-wide | match | 7/7 | 1/1 | 0 | right arrow, P12 102.5 |
| code04-p12-bracket-down | match | 6/6 | 1/1 | 0 | right bracket, P12 -3 |
| code04-p12-bracket-up | match | 6/6 | 1/1 | 0 | right bracket, P12 1.5 |
| code04-p12-thin-arrow | match | 6/6 | 1/1 | 0 | thin wavy line with arrow, P12 100 |
| code04-p12-updown | match | 7/7 | 1/1 | 0 | right bracket up and down, P12 201 |
| code04-p12-vertical-arrow | match | 7/7 | 1/1 | 0 | vertical line with arrow, P12 101 |
| code04-p12-wavy-arrow | match | 36/36 | 1/1 | 0 | heavy wavy line with arrow, P12 100 |
| code04-p12-wavy-vertical-down | match | 12/12 | 1/1 | 0 | arpeggio with arrow down, P12 -100 |
| code04-p12-wavy-vertical-up | match | 12/12 | 1/1 | 0 | arpeggio with arrow up, P12 100 |
| code04-p13-cresc-rotated | match | 6/6 | 1/1 | 0 | crescendo, P13 10 |
| code04-p13-rotation-30 | match | 6/6 | 1/1 | 0 | plain line, P13 30 |
| code04-p13-rotation-90 | match | 6/6 | 1/1 | 0 | plain line, P13 90 |
| code04-p13-rotation-arrow | match | 7/7 | 1/1 | 0 | line with right arrow, P13 -20 |
| code04-p13-rotation-m45 | match | 6/6 | 1/1 | 0 | plain line, P13 -45 |
| code04-p13-vertical-rotated | match | 6/6 | 1/1 | 0 | vertical line, P7 -5, P13 -60 (portamento) |
| code04-p13-wavy-rotated | match | 35/35 | 1/1 | 0 | heavy wavy line, P13 20 |
| code04-p14-cresc-negative | match | 7/7 | 1/1 | 0 | crescendo, P14 -0.4 |
| code04-p14-cresc-partial | match | 7/7 | 1/1 | 0 | crescendo, P14 0.5 |
| code04-p14-cresc-percent | match | 7/7 | 1/1 | 0 | crescendo, P14 48 |
| code04-p14-decresc-partial | match | 6/6 | 1/1 | 0 | decrescendo, P14 0.5 |
| code04-p14p15-cresc-gap | match | 7/7 | 1/1 | 0 | crescendo gap, P14 0.455, P15 -3 |
| code04-p14p15-cresc-inner | match | 7/7 | 1/1 | 0 | crescendo, P14 0.3, P15 0.7 |
| code04-p14p15-decresc-inner | match | 7/7 | 1/1 | 0 | decrescendo, P14 0.3, P15 0.7 |
| code04-p15-cresc-partial | match | 6/6 | 1/1 | 0 | crescendo, P15 0.6 |
| code04-p15-decresc-partial | match | 7/7 | 1/1 | 0 | decrescendo, P15 0.6 |
| code04-p15-vertical | match | 6/6 | 1/1 | 0 | vertical line, P7 -5, P15 2 |
| code04-p15-wavy-vertical | match | 11/11 | 1/1 | 0 | arpeggio, P15 3 |
| code04-p16-offsets | match | 6/6 | 1/1 | 0 | P16 1 with left offset P17 2, right offset P18 -3 |
| code04-p16-offsets-zero | match | 6/6 | 1/1 | 0 | P17/P18 set without P16 |
| code04-p18-multipoint-scale | match | 6/6 | 1/1 | 0 | multipoint, P18 1.5 |
| code04-p19-multipoint-scale | match | 6/6 | 1/1 | 0 | multipoint, P18 0.8, P19 2 |
| code04-p20-multipoint-rotated | match | 6/6 | 1/1 | 0 | multipoint, P20 15 |
| code04-p21-multipoint-thick | match | 8/8 | 1/1 | 0 | multipoint, P21 1 |
| code04-p25-layer | match | 6/6 | 1/1 | 0 | plain line, P25 2 |
| code04-p26-grey | match | 6/6 | 1/1 | 0 | plain line, P26 0.5 |
| code04-p26-red-hairpin | match | 6/6 | 1/1 | 0 | hairpin, P26 900000 |
| code04-p3-fraction | match | 6/6 | 1/1 | 0 | P3 20.3 to P6 77.7 |
| code04-p4p5-down | match | 6/6 | 1/1 | 0 | tilted line, P4 10 to P5 2 |
| code04-p4p5-fraction | match | 6/6 | 1/1 | 0 | tilted line, P4 4.3 to P5 6.7 |
| code04-p4p5-up | match | 6/6 | 1/1 | 0 | tilted line, P4 3 to P5 9 |
| code04-p5-cresc | match | 6/6 | 1/1 | 0 | crescendo hairpin, P5 999 |
| code04-p5p6-missing | match | 14/14 | 1/1 | 0 | P5 = P6 = 0: engine message, default length and thickness |
| code04-p6-reversed | match | 6/6 | 1/1 | 0 | P6 left of P3 |
| code04-p6-vertical | match | 6/6 | 1/1 | 0 | vertical line, P6 = P3 |
| code04-p6eqp3-wavy-vertical | match | 11/11 | 1/1 | 0 | arpeggio with P6 = P3 |
| code04-p7-cresc-spread | match | 6/6 | 1/1 | 0 | crescendo, P7 3.5 |
| code04-p7-dashes | match | 31/31 | 1/1 | 0 | dashes, P7 1 |
| code04-p7-dashes-2 | match | 31/31 | 1/1 | 0 | P7 2 draws dashes too |
| code04-p7-dashes-bracket | match | 31/31 | 1/1 | 0 | dashes with right bracket P12 2 |
| code04-p7-dashes-rotated | match | 31/31 | 1/1 | 0 | dashes, P13 30 |
| code04-p7-dashes-same-ip | match | 31/31 | 1/1 | 0 | dashes, P4 5, P5 5.6 (same integer level) |
| code04-p7-dashes-thick | match | 83/83 | 1/1 | 0 | dashes, P10 1 |
| code04-p7-dashes-tilted | match | 31/31 | 1/1 | 0 | tilted dashes, P4 3 to P5 9 |
| code04-p7-dashes-vertical | match | 11/11 | 1/1 | 0 | vertical dashes, P6 = P3 |
| code04-p7-decresc | match | 6/6 | 1/1 | 0 | decrescendo hairpin, P7 -1 |
| code04-p7-decresc-spread | match | 6/6 | 1/1 | 0 | decrescendo, P7 -4 |
| code04-p7-dots | match | 31/31 | 1/1 | 0 | dotted line, P7 -4 |
| code04-p7-dots-rotated | match | 31/31 | 1/1 | 0 | dotted line, P13 -30 |
| code04-p7-multipoint | match | 6/6 | 1/1 | 0 | multipoint line through two points |
| code04-p7-multipoint-5 | match | 6/6 | 1/1 | 0 | multipoint line through five points |
| code04-p7-saw | match | 6/6 | 1/1 | 0 | sawtooth line, P7 -3 |
| code04-p7-thin | match | 6/6 | 1/1 | 0 | thin wavy line, P7 -2 |
| code04-p7-thin-vertical | match | 6/6 | 1/1 | 0 | vertical thin wavy line |
| code04-p7-vertical | match | 6/6 | 1/1 | 0 | vertical line, P7 -5 |
| code04-p7-wavy | match | 35/35 | 1/1 | 0 | heavy wavy line, P7 -1 |
| code04-p7-wavy-vertical | match | 11/11 | 1/1 | 0 | vertical heavy wavy line (arpeggio) |
| code04-p8-dash-length | match | 18/18 | 1/1 | 0 | dashes, P8 2 |
| code04-p8-dash-short | match | 70/70 | 1/1 | 0 | dashes, P8 0.4 |
| code04-p8-dot-size | match | 31/31 | 1/1 | 0 | dotted line, P8 2 |
| code04-p8-wavy-unit | match | 20/20 | 1/1 | 0 | heavy wavy line, P8 2 |
| code04-p8-wavy-vertical | match | 9/9 | 1/1 | 0 | arpeggio, P8 1.5, P9 0.7 |
| code04-p8p9-dashes-vertical | match | 9/9 | 1/1 | 0 | vertical dashes, P8 2, P9 1 |
| code04-p8p9-saw | match | 6/6 | 1/1 | 0 | sawtooth line, P8 1.5, P9 2 |
| code04-p8p9-thin | match | 6/6 | 1/1 | 0 | thin wavy line, P8 2, P9 0.5 |
| code04-p9-cresc-rotated | match | 6/6 | 1/1 | 0 | crescendo, P9 -10 (SCORE 4 rotation) |
| code04-p9-dash-space | match | 31/31 | 1/1 | 0 | dashes, P8 1.5, P9 0.5 |
| code04-p9-dot-space | match | 57/57 | 1/1 | 0 | dotted line, P9 1 |
| code04-p9-rotation | match | 6/6 | 1/1 | 0 | plain line, P9 20 (SCORE 4 rotation) |
| code04-p9-wavy-height | match | 35/35 | 1/1 | 0 | heavy wavy line, P9 2 |
| code04-recto | match | 7/7 | 3/3 | 0 | line on the recto staff 201 |
| code04-several | match | 37/37 | 1/1 | 0 | a line, a hairpin and a wavy line |
| code04-size-0.75-arpeggio | match | 12/12 | 1/1 | 0 | arpeggio on a size 0.75 staff |
| code04-size-0.75-arrows | match | 7/7 | 1/1 | 0 | arrows and brackets on a size 0.75 staff |
| code04-size-0.75-cresc | match | 6/6 | 1/1 | 0 | crescendo on a size 0.75 staff |
| code04-size-0.75-dashes | match | 40/40 | 1/1 | 0 | dashes on a size 0.75 staff |
| code04-size-0.75-wavy | match | 45/45 | 1/1 | 0 | heavy wavy line on a size 0.75 staff |
| code04-size-1.3-saw | match | 52/52 | 1/1 | 0 | sawtooth on a size 1.3 staff |
| code04-staff-2 | match | 11/11 | 2/2 | 0 | line on staff 2 |
| code05-default | match | 6/6 | 1/1 | 0 | slur curving up three scale steps |
| code05-ending-1 | match | 7/7 | 2/2 | 0 | first ending P8 = 1 |
| code05-ending-1-continued | match | 6/6 | 1/1 | 0 | first ending continued, P9 = -1 |
| code05-ending-1-no-number | match | 6/6 | 1/1 | 0 | first ending without number, P9 = -2 |
| code05-ending-2 | match | 7/7 | 2/2 | 0 | second ending P8 = 2 |
| code05-ending-2-open | match | 6/6 | 1/1 | 0 | second ending open, P9 = -1 |
| code05-ending-4-p9-3 | match | 7/7 | 2/2 | 0 | third ending P8 = 4, P9 = 3 |
| code05-ending-p12-size | match | 7/7 | 2/2 | 0 | first ending stop size P12 = 1.5 |
| code05-ending-p13-0.5 | match | 7/7 | 2/2 | 0 | first ending P13 = 0.5 |
| code05-ending-p13-1 | match | 7/7 | 2/2 | 0 | first ending P13 = 1 |
| code05-ending-p13-2 | match | 7/7 | 2/2 | 0 | first ending P13 = 2 |
| code05-ending-p13-3 | match | 7/7 | 2/2 | 0 | first ending P13 = 3 |
| code05-ending-p14-font | match | 7/7 | 2/2 | 0 | first ending number in font 12, P14 = 12 |
| code05-ending-p17-letter | match | 7/7 | 3/3 | 0 | first ending with letter P17 = 2 after the number |
| code05-long | match | 6/6 | 1/1 | 0 | long slur from P3 = 20 to 180 |
| code05-p10-centre-0.3 | match | 6/6 | 1/1 | 0 | centre of curvature P10 = 0.3 |
| code05-p10-centre-0.75 | match | 6/6 | 1/1 | 0 | centre of curvature P10 = 0.75 |
| code05-p11-dashes | match | 25/25 | 1/1 | 0 | dashes P11 = 1 |
| code05-p11-dashes-5 | match | 10/10 | 1/1 | 0 | five dashes P11 = 5 |
| code05-p11-dashes-sloped | match | 25/25 | 1/1 | 0 | dashes on a sloped slur |
| code05-p11-dots | match | 23/23 | 1/1 | 0 | dots P11 = -1 |
| code05-p11-dots-8 | match | 13/13 | 1/1 | 0 | eight dots P11 = -8 |
| code05-p12-half-1 | match | 6/6 | 1/1 | 0 | half slur P12 = 1 |
| code05-p12-half-2 | match | 6/6 | 1/1 | 0 | half slur P12 = 2 |
| code05-p12-half-dashes | match | 8/8 | 1/1 | 0 | dashed left half slur |
| code05-p12-half-sloped | match | 6/6 | 1/1 | 0 | right half slur on a slope |
| code05-p12-reverse | match | 6/6 | 1/1 | 0 | change of direction P12 = -1 |
| code05-p13-thick-0.5 | match | 6/6 | 1/1 | 0 | thickness P13 = 0.5 |
| code05-p13-thick-1.5 | match | 6/6 | 1/1 | 0 | thickness P13 = 1.5 |
| code05-p14-dashes | match | 16/16 | 1/1 | 0 | dashes from P14 = 0.4 |
| code05-p14-p15 | match | 6/6 | 1/1 | 0 | visible part from P14 = 0.2 to P15 = 0.6 |
| code05-p14-sloped | match | 6/6 | 1/1 | 0 | P14 = 0.4 on a sloped slur |
| code05-p14-start | match | 6/6 | 1/1 | 0 | visible part from P14 = 0.3 |
| code05-p14-start-negative | match | 6/6 | 1/1 | 0 | P14 = -0.4 |
| code05-p15-dashes | match | 17/17 | 1/1 | 0 | dashes up to P15 = 0.6 |
| code05-p15-end | match | 6/6 | 1/1 | 0 | visible part up to P15 = 0.7 |
| code05-p16-number | match | 7/7 | 2/2 | 0 | number 3 in a broken slur, P16 = 3 |
| code05-p16-number-12 | match | 7/7 | 3/3 | 0 | number 12 in a broken slur |
| code05-p16-number-below | match | 6/6 | 2/2 | 0 | number under an unbroken slur, P16 = -3 |
| code05-p16-number-below-down | match | 6/6 | 2/2 | 0 | number above a slur curving down, P16 = -5 |
| code05-p16-number-dashes-3 | match | 8/8 | 1/1 | 0 | three dashes and P16 = 3: no number |
| code05-p16-number-dots | match | 13/13 | 2/2 | 0 | number under a dotted slur, P11 = -8, P16 = -3 |
| code05-p16-number-half-sloped | match | 6/6 | 2/2 | 0 | number in a sloped right half slur |
| code05-p16-number-p17-p18 | match | 7/7 | 2/2 | 0 | number moved by P17 = 1, P18 = 1 |
| code05-p16-number-p19 | match | 7/7 | 2/2 | 0 | number in a slur with P19 = 0.5 (also its rotation) |
| code05-p16-number-sloped | match | 7/7 | 2/2 | 0 | number in a sloped slur |
| code05-p16-offsets | match | 6/6 | 1/1 | 0 | end offsets P16 = 1, P17 = 2, P18 = -1.5 |
| code05-p19-thicken | match | 6/6 | 1/1 | 0 | thickness reached at P19 = 0.5 |
| code05-p20-width | match | 6/6 | 1/1 | 0 | end placement P8 = -1 with note width P20 = 1.5 |
| code05-p25-layer | match | 6/6 | 1/1 | 0 | layer number P25 = 1 |
| code05-p26-grey-0.5 | match | 6/6 | 1/1 | 0 | P26 = 0.5 |
| code05-p26-red | match | 6/6 | 1/1 | 0 | P26 = 990000 |
| code05-p27-slash | match | 7/7 | 1/1 | 0 | slash P27 = 3 |
| code05-p27-slash-p28-p29 | match | 7/7 | 1/1 | 0 | slash P27 = 2 raised P28 = 1 at P29 = 0.3 |
| code05-p27-slash-sloped | match | 7/7 | 1/1 | 0 | slash on a sloped slur |
| code05-p5-right-12 | match | 6/6 | 1/1 | 0 | right end level P5 = 12 |
| code05-p5-right-5.5 | match | 6/6 | 1/1 | 0 | right end level P5 = 5.5 |
| code05-p6-before-p3 | match | 6/6 | 1/1 | 0 | P6 left of P3 |
| code05-p6-zero | match | 6/6 | 1/1 | 0 | P6 = 0 and P7 = 0: P3 + 20 and curvature 3 |
| code05-p7-curve-0 | match | 6/6 | 1/1 | 0 | curvature P7 = 0 |
| code05-p7-curve-1.5 | match | 6/6 | 1/1 | 0 | curvature P7 = 1.5 |
| code05-p7-curve-6 | match | 6/6 | 1/1 | 0 | curvature P7 = 6 |
| code05-p7-down | match | 6/6 | 1/1 | 0 | slur curving down, P7 = -3 |
| code05-p8-ends-0.3 | match | 6/6 | 1/1 | 0 | end placement P8 = 0.3 |
| code05-p8-ends-11 | match | 6/6 | 1/1 | 0 | end placement P8 = 11 |
| code05-p8-ends-15 | match | 6/6 | 1/1 | 0 | end placement P8 = 15 |
| code05-p8-ends-m1 | match | 6/6 | 1/1 | 0 | end placement P8 = -1 |
| code05-p8-ends-m3 | match | 6/6 | 1/1 | 0 | end placement P8 = -3 |
| code05-p8-ends-m4 | match | 6/6 | 1/1 | 0 | end placement P8 = -4 |
| code05-p8-ends-m5 | match | 6/6 | 1/1 | 0 | end placement P8 = -5 |
| code05-p8-ends-m6 | match | 6/6 | 1/1 | 0 | end placement P8 = -6 |
| code05-p8-ends-m7 | match | 6/6 | 1/1 | 0 | end placement P8 = -7 |
| code05-p8-ends-m8 | match | 6/6 | 1/1 | 0 | end placement P8 = -8 |
| code05-p8-ends-m9 | match | 6/6 | 1/1 | 0 | end placement P8 = -9 |
| code05-p9-flatten-2 | match | 6/6 | 1/1 | 0 | flattening P9 = 2 |
| code05-p9-flatten-m1 | match | 6/6 | 1/1 | 0 | flattening P9 = -1 |
| code05-p9-triangle | match | 6/6 | 1/1 | 0 | triangle P9 = 99 |
| code05-p9-triangle-line | match | 6/6 | 1/1 | 0 | triangle with P7 = 0: a line |
| code05-p9-triangle-p10-p13 | match | 8/8 | 1/1 | 0 | triangle with peak at P10 = 0.3, P13 = 2 extra strokes |
| code05-recto-201 | match | 6/6 | 3/3 | 0 | slur on recto staff 201 |
| code05-short | match | 6/6 | 1/1 | 0 | short slur over three P3 units |
| code05-staff-2 | match | 11/11 | 2/2 | 0 | slur on staff 2 |
| code05-staff-size-0.75 | match | 6/6 | 1/1 | 0 | slur on a staff of size 0.75 |
| code05-tie | match | 6/6 | 1/1 | 0 | tie: P8 = -2, curvature 2 |
| code05-tuplet | match | 7/7 | 2/2 | 0 | tuplet bracket P8 = 3 |
| code05-tuplet-down | match | 7/7 | 2/2 | 0 | tuplet bracket below, P7 = -4 |
| code05-tuplet-p10 | match | 7/7 | 2/2 | 0 | tuplet number at P10 = 0.3 |
| code05-tuplet-p11-1 | match | 6/6 | 2/2 | 0 | tuplet bracket P11 = 1 |
| code05-tuplet-p11-1-sloped | match | 6/6 | 2/2 | 0 | sloped continuous bracket, number inside, P11 = 1 |
| code05-tuplet-p11-2 | match | 6/6 | 2/2 | 0 | tuplet bracket P11 = 2 |
| code05-tuplet-p11-3 | match | 6/6 | 1/1 | 0 | tuplet bracket P11 = 3 |
| code05-tuplet-p12 | match | 7/7 | 2/2 | 0 | tuplet bracket right hook lengthened P12 = 2 |
| code05-tuplet-p13-1 | match | 7/7 | 2/2 | 0 | tuplet bracket P13 = 1 (open ends) |
| code05-tuplet-p13-2 | match | 7/7 | 2/2 | 0 | tuplet bracket P13 = 2 (open ends) |
| code05-tuplet-p13-3 | match | 7/7 | 2/2 | 0 | tuplet bracket P13 = 3 (open ends) |
| code05-tuplet-p14-font | match | 7/7 | 2/2 | 0 | tuplet number in font 12, P14 = 12 |
| code05-tuplet-p19 | match | 7/7 | 2/2 | 0 | tuplet number turned by P19 = 2 |
| code05-tuplet-p20 | match | 7/7 | 2/2 | 0 | tuplet bracket with P20 = 1.5 |
| code05-tuplet-p21 | match | 7/7 | 2/2 | 0 | tuplet number size P21 = 1.2 |
| code05-tuplet-p23 | match | 7/7 | 2/2 | 0 | tuplet gap P23 = 2 |
| code05-tuplet-p9-12 | match | 7/7 | 3/3 | 0 | tuplet bracket with 12, P9 = 12 |
| code05-tuplet-p9-5 | match | 7/7 | 2/2 | 0 | tuplet bracket with 5, P9 = 5 |
| code05-tuplet-p9-open | match | 7/7 | 1/1 | 0 | tuplet bracket with open space P9 = -3 |
| code05-tuplet-sloped | match | 7/7 | 2/2 | 0 | sloped tuplet bracket, P5 = 12 |
| code05-two-slurs | match | 7/7 | 1/1 | 0 | two slurs in one file |
| code06-combined-12 | match | 9/9 | 1/1 | 0 | two full beams and floating beams P10 = 22 (P11 = P12 = 0) |
| code06-default | match | 6/6 | 1/1 | 0 | single beam, stems up, horizontal |
| code06-floating-10 | match | 7/7 | 1/1 | 0 | floating beams P7 = 10, P10 = 2 |
| code06-floating-20-p11-p12 | match | 8/8 | 1/1 | 0 | floating beams P7 = 20, P10 = 3, P11 = 2, P12 = -2 |
| code06-p10-partial-11 | match | 7/7 | 1/1 | 0 | one partial beam P10 = 11 from P11 = 110 to P12 = 120 |
| code06-p10-partial-12-slope | match | 8/8 | 1/1 | 0 | two partials P10 = 12 under a sloped beam |
| code06-p10-partial-21 | match | 7/7 | 1/1 | 0 | partial displaced two spacings P10 = 21 |
| code06-p10-partial-down | match | 7/7 | 1/1 | 0 | partial under stems-down beam |
| code06-p10-partial-negative | match | 7/7 | 1/1 | 0 | partial above the main beam P10 = -11 |
| code06-p11-free-left | match | 7/7 | 1/1 | 0 | partial with free left end (P11 = 0) |
| code06-p11-main-end | match | 7/7 | 1/1 | 0 | partial from the main beam's left end P11 = -1 |
| code06-p12-free-right | match | 7/7 | 1/1 | 0 | partial with free right end (P12 = 0) |
| code06-p12-main-end | match | 7/7 | 1/1 | 0 | partial to the main beam's right end P12 = -1 |
| code06-p13-second-group | match | 8/8 | 1/1 | 0 | second partial group P13 = 21, P14 = 120, P15 = 130 |
| code06-p13-second-group-p9 | match | 8/8 | 1/1 | 0 | second group with offsets P9 = 3 |
| code06-p14-offset-1.5 | match | 6/6 | 1/1 | 0 | left end note offset P14 = 1.5 (P13 = 0) |
| code06-p14-offset-10 | match | 6/6 | 1/1 | 0 | left end note offset P14 = 10 (P13 = 0) |
| code06-p14-offset-20 | match | 6/6 | 1/1 | 0 | left end note offset P14 = 20 (P13 = 0) |
| code06-p15-offset-10 | match | 6/6 | 1/1 | 0 | right end note offset P15 = 10 (P13 = 0) |
| code06-p15-offset-m2 | match | 6/6 | 1/1 | 0 | right end note offset P15 = -2 (P13 = 0) |
| code06-p16-number-left | match | 6/6 | 2/2 | 0 | tuplet number at P16 = 0.3 |
| code06-p17-thick-0.5 | match | 7/7 | 1/1 | 0 | thickness P17 = 0.5 |
| code06-p17-thick-2 | match | 7/7 | 1/1 | 0 | thickness P17 = 2 |
| code06-p18-size-0.75 | match | 7/7 | 1/1 | 0 | size P18 = 0.75 |
| code06-p18-size-1.3 | match | 7/7 | 1/1 | 0 | size P18 = 1.3 |
| code06-p19-number-up | match | 6/6 | 2/2 | 0 | tuplet number raised P19 = 2 |
| code06-p20-width-0.8 | match | 6/6 | 1/1 | 0 | note width P20 = 0.8 |
| code06-p20-width-1.5 | match | 6/6 | 1/1 | 0 | note width P20 = 1.5 |
| code06-p21-space-0.5 | match | 8/8 | 1/1 | 0 | spacing P21 = 0.5 |
| code06-p21-space-1.5 | match | 8/8 | 1/1 | 0 | spacing P21 = 1.5 |
| code06-p25-layer | match | 6/6 | 1/1 | 0 | layer number P25 = 1 |
| code06-p26-grey-0.5 | match | 6/6 | 1/1 | 0 | P26 = 0.5 |
| code06-p26-red | match | 6/6 | 1/1 | 0 | P26 = 990000 |
| code06-p4-cue | match | 7/7 | 1/1 | 0 | cue-size beam P4 = 109 |
| code06-p4-cue-p17 | match | 7/7 | 1/1 | 0 | cue-size beam P4 = 109 with P17 = 1.2 |
| code06-p4-left-12.5 | match | 6/6 | 1/1 | 0 | left end level P4 = 12.5 |
| code06-p4-left-4 | match | 6/6 | 1/1 | 0 | left end level P4 = 4 |
| code06-p5-right-11 | match | 6/6 | 1/1 | 0 | right end level P5 = 11 |
| code06-p5-right-6.5 | match | 6/6 | 1/1 | 0 | right end level P5 = 6.5 |
| code06-p6-right-150 | match | 6/6 | 1/1 | 0 | right end P6 = 150 |
| code06-p7-down-1 | match | 6/6 | 1/1 | 0 | P7 = 21: 1 beams, stems down |
| code06-p7-down-2 | match | 7/7 | 1/1 | 0 | P7 = 22: 2 beams, stems down |
| code06-p7-down-3 | match | 8/8 | 1/1 | 0 | P7 = 23: 3 beams, stems down |
| code06-p7-up-2 | match | 7/7 | 1/1 | 0 | P7 = 12: 2 beams, stems up |
| code06-p7-up-3 | match | 8/8 | 1/1 | 0 | P7 = 13: 3 beams, stems up |
| code06-p7-up-4 | match | 9/9 | 1/1 | 0 | P7 = 14: 4 beams, stems up |
| code06-p7-zero | match | 6/6 | 1/1 | 0 | P7 = 0 |
| code06-p8-font | match | 6/6 | 2/2 | 0 | tuplet number in font 12, P8 = 12003 |
| code06-p8-font-34 | match | 6/6 | 2/2 | 0 | tuplet number in font 00 (P8 = 34003) |
| code06-p8-number-11 | match | 6/6 | 3/3 | 0 | tuplet number P8 = 11 |
| code06-p8-number-12 | match | 6/6 | 3/3 | 0 | tuplet number P8 = 12 |
| code06-p8-number-3 | match | 6/6 | 2/2 | 0 | tuplet number P8 = 3 |
| code06-p8-number-5 | match | 6/6 | 2/2 | 0 | tuplet number P8 = 5 |
| code06-p8-number-cue | match | 6/6 | 2/2 | 0 | tuplet number on a cue beam |
| code06-p8-number-down | match | 6/6 | 2/2 | 0 | tuplet number under stems-down beam |
| code06-p8-number-p18 | match | 7/7 | 2/2 | 0 | tuplet number on a beam of size P18 = 1.3 |
| code06-p8-number-p20 | match | 6/6 | 3/3 | 0 | tuplet number 12 with note width P20 = 1.5 |
| code06-p8-number-sloped | match | 7/7 | 2/2 | 0 | tuplet number on a sloped stems-down beam at P16 = 0.7 |
| code06-p9-100-down | match | 7/7 | 1/1 | 0 | main beam end offsets P9 = 100, stems down |
| code06-p9-100-up | match | 7/7 | 1/1 | 0 | main beam end offsets P9 = 100, stems up |
| code06-p9-200-down | match | 7/7 | 1/1 | 0 | main beam end offsets P9 = 200, stems down |
| code06-p9-200-up | match | 7/7 | 1/1 | 0 | main beam end offsets P9 = 200, stems up |
| code06-p9-300-down | match | 7/7 | 1/1 | 0 | main beam end offsets P9 = 300, stems down |
| code06-p9-300-up | match | 7/7 | 1/1 | 0 | main beam end offsets P9 = 300, stems up |
| code06-p9-partial-30 | match | 7/7 | 1/1 | 0 | partial end offsets P9 = 30 |
| code06-recto-201 | match | 7/7 | 3/3 | 0 | beam on recto staff 201 |
| code06-staff-2 | match | 12/12 | 2/2 | 0 | beam on staff 2 |
| code06-staff-size-0.75 | match | 7/7 | 1/1 | 0 | beam on a staff of size 0.75 |
| code06-trem-across-stem | match | 8/8 | 1/1 | 0 | tremolo P7 = -10, three beams across the stem at P3 (P11 = 0) |
| code06-trem-across-stem-down | match | 7/7 | 1/1 | 0 | tremolo P7 = -20 across a down stem |
| code06-trem-attached | match | 7/7 | 1/1 | 0 | tremolo P7 = -10 at P11 = 115 along the beam line |
| code06-trem-p11-main-end | match | 7/7 | 1/1 | 0 | tremolo P7 = -10 with P11 = -1 |
| code06-trem-width | match | 7/7 | 1/1 | 0 | tremolo across the stem, width P12 = 8 |
| code06-two-beams | match | 8/8 | 1/1 | 0 | two beams in one file |
| code07-p10-ottava-thick | match | 62/62 | 4/4 | 0 | 8va dashes, P10 1 |
| code07-p10-trill-thick | match | 31/31 | 1/1 | 0 | trill extension, P10 1 |
| code07-p11-pedal-arrow | match | 7/7 | 1/1 | 0 | pedal line, left arrow P11 101 |
| code07-p11-pedal-bracket | match | 6/6 | 1/1 | 0 | pedal line, left bracket P11 2 |
| code07-p11-trill-wave-down | match | 31/31 | 1/1 | 0 | trill extension lowered, P11 -0.6 |
| code07-p11-trill-wave-up | match | 31/31 | 1/1 | 0 | trill extension raised, P11 1 |
| code07-p11p12-piano-pedal-brackets | match | 14/14 | 1/1 | 0 | piano pedal symbol line with brackets |
| code07-p12-ottava-88-bracket | match | 25/25 | 2/2 | 0 | ottava 88 with end bracket P12 -1.5 |
| code07-p12-ottava-bracket | match | 24/24 | 4/4 | 0 | 8va with end bracket P12 -2 |
| code07-p12-pedal-arrow | match | 7/7 | 1/1 | 0 | pedal line, right arrow P12 101 |
| code07-p12-pedal-bracket | match | 6/6 | 1/1 | 0 | pedal line, right bracket P12 2 |
| code07-p12-pedal-updown | match | 7/7 | 1/1 | 0 | pedal line, right P12 201 |
| code07-p12-trill-arrow | match | 32/32 | 1/1 | 0 | trill extension with arrow, P12 100 |
| code07-p13-trill-rotated | match | 31/31 | 1/1 | 0 | trill extension, P13 5 |
| code07-p15-harp-offset | match | 18/18 | 1/1 | 0 | harp pedal symbol, P15 4 |
| code07-p15-pedal-offset | match | 6/6 | 1/1 | 0 | pedal line, P15 2 |
| code07-p15-trill-offset | match | 29/29 | 1/1 | 0 | trill, P15 3 |
| code07-p16p18-trill-offsets | match | 32/32 | 1/1 | 0 | trill, P16 1, P17 2, P18 5 |
| code07-p18-ottava-offset | match | 25/25 | 4/4 | 0 | 8va, P18 3 |
| code07-p18-trill-right-offset | match | 29/29 | 1/1 | 0 | trill, P18 -4 (P16 set by the engine) |
| code07-p26-trill-colour | match | 31/31 | 1/1 | 0 | trill with extension, P26 0.5 |
| code07-p28-trill-pixels | match | 15/15 | 1/1 | 0 | trill, P28 1 |
| code07-p5-harp-size | match | 18/18 | 1/1 | 0 | harp pedal symbol, P5 1.5 |
| code07-p5-ottava-size | match | 17/17 | 4/4 | 0 | 8va, P5 1.5 |
| code07-p5-piano-pedal-010 | match | 12/12 | 1/1 | 0 | piano pedal symbol, P5 10 |
| code07-p5-piano-pedal-111 | match | 18/18 | 1/1 | 0 | piano pedal symbol, P5 111 |
| code07-p5-piano-pedal-off | match | 9/9 | 1/1 | 0 | piano pedal symbol, all pedals up |
| code07-p5-trill-size-0.7 | match | 10/10 | 1/1 | 0 | trill, P5 0.7, with flat |
| code07-p5-trill-size-1.5 | match | 22/22 | 1/1 | 0 | trill, P5 1.5, with extension |
| code07-p6-ottava-dashes | match | 24/24 | 4/4 | 0 | 8va with dashes to P6 80 |
| code07-p6-piano-pedal-line | match | 13/13 | 1/1 | 0 | piano pedal symbol with line to P6 70 |
| code07-p6-trill-wave | match | 31/31 | 1/1 | 0 | trill with wavy extension to P6 70 |
| code07-p7-25 | match | 6/6 | 1/1 | 0 | P7 25: symbol 120 |
| code07-p7-asterisk | match | 6/6 | 1/1 | 0 | P7 24: asterisk |
| code07-p7-harp | match | 18/18 | 1/1 | 0 | harp pedal symbol, P8 012, P9 1201 |
| code07-p7-harp-down | match | 18/18 | 1/1 | 0 | harp pedals all down (222, 2222) |
| code07-p7-harp-flat | match | 18/18 | 1/1 | 0 | harp pedals all up (000, 0000) |
| code07-p7-ottava | match | 5/5 | 4/4 | 0 | 8va symbol, P7 8 |
| code07-p7-ottava-88 | match | 25/25 | 2/2 | 0 | ottava, dashes up, P7 88 |
| code07-p7-ottava-bassa | match | 24/24 | 4/4 | 0 | 8ba with dashes, P7 -8 |
| code07-p7-ottava-m88 | match | 25/25 | 2/2 | 0 | ottava, dashes down, P7 -88 |
| code07-p7-ped | match | 7/7 | 1/1 | 0 | P7 23: Ped. symbol |
| code07-p7-pedal-line | match | 6/6 | 1/1 | 0 | pedal line, P7 21, to P6 80 |
| code07-p7-pedal-line-22 | match | 6/6 | 1/1 | 0 | pedal line, P7 22, to P6 80 |
| code07-p7-piano-pedal | match | 15/15 | 1/1 | 0 | piano pedal symbol, P5 101 |
| code07-p7-quindicesima | match | 23/23 | 5/5 | 0 | 15ma with dashes, P7 15 |
| code07-p7-quindicesima-155 | match | 24/24 | 3/3 | 0 | quindicesima, dashes up, P7 155 |
| code07-p7-trill | match | 7/7 | 1/1 | 0 | trill symbol, P7 0 |
| code07-p8-pedal-notch | match | 6/6 | 1/1 | 0 | pedal line with notch at P8 50 |
| code07-p8-pedal-notch-22 | match | 6/6 | 1/1 | 0 | pedal line 22 with notch at P8 50 |
| code07-p8-piano-pedal-left | match | 13/13 | 1/1 | 0 | piano pedal symbol, lines from P8 10 to P6 70 |
| code07-p8-trill-4 | match | 13/13 | 1/1 | 0 | trill with P8 4 (double flat) |
| code07-p8-trill-5 | match | 8/8 | 1/1 | 0 | trill with P8 5 (double sharp) |
| code07-p8-trill-6 | match | 7/7 | 1/1 | 0 | trill with P8 6 (no accidental) |
| code07-p8-trill-flat | match | 10/10 | 1/1 | 0 | trill with flat, P8 1 |
| code07-p8-trill-natural | match | 11/11 | 1/1 | 0 | trill with natural, P8 3 |
| code07-p8-trill-sharp | match | 11/11 | 1/1 | 0 | trill with sharp, P8 2 |
| code07-p8-trill-wave | match | 35/35 | 1/1 | 0 | trill with sharp and extension |
| code07-p8p9-ottava-dashes | match | 21/21 | 4/4 | 0 | 8va dashes P8 2, P9 1 |
| code07-p9-ped-size | match | 7/7 | 1/1 | 0 | P7 23, P9 1.5 |
| code07-p9-pedal-notch-height | match | 6/6 | 1/1 | 0 | pedal notch, P9 3 |
| code07-p9-piano-pedal-size | match | 12/12 | 1/1 | 0 | piano pedal symbol, P9 1.5 |
| code07-p9-trill-wave-size | match | 23/23 | 1/1 | 0 | trill extension, P9 1.5 |
| code07-p9-trill-wave-small | match | 46/46 | 1/1 | 0 | trill extension, P9 0.6 |
| code07-recto | match | 31/31 | 3/3 | 0 | trill with extension on the recto staff 201 |
| code07-size-0.75-harp | match | 18/18 | 1/1 | 0 | harp pedal symbol on a size 0.75 staff |
| code07-size-0.75-ottava | match | 39/39 | 4/4 | 0 | 8va with dashes on a size 0.75 staff |
| code07-size-0.75-pedal | match | 6/6 | 1/1 | 0 | pedal line with notch on a size 0.75 staff |
| code07-size-0.75-trill | match | 42/42 | 1/1 | 0 | trill with flat and extension on a size 0.75 staff |
| code08-default | match | 5/5 | 1/1 | 0 | staff 1, size 1 |
| code08-p10-inches-1.5 | match | 5/5 | 1/1 | 0 | staff 2 placed 1.5 in above staff 1 with P10 (P4 = 4 ignored) |
| code08-p10-inches-3 | match | 5/5 | 1/1 | 0 | staff 2 placed 3 in above staff 1 with P10 (P4 = 4 ignored) |
| code08-p11-thickness-2 | match | 5/5 | 1/1 | 0 | PostScript line thickness P11 = 2 |
| code08-p11-thickness-99 | match | 5/5 | 1/1 | 0 | PostScript line thickness P11 = 99 |
| code08-p12-suppress-number | match | 5/5 | 0/0 | 0 | P12 = 1 hides the staff number |
| code08-p13-transpose | match | 5/5 | 1/1 | 0 | MIDI transposition P13 = -9 |
| code08-p14-cm-0.78 | match | 5/5 | 1/1 | 0 | staff height P14 = 0.78 cm |
| code08-p14-cm-1.2 | match | 5/5 | 1/1 | 0 | staff height P14 = 1.2 cm |
| code08-p2-staff-0 | match | 0/0 | 0/0 | 0 | single staff numbered 0 |
| code08-p2-staff-10 | match | 5/5 | 2/2 | 0 | single staff numbered 10 |
| code08-p2-staff-2 | match | 5/5 | 1/1 | 0 | single staff numbered 2 |
| code08-p2-staff-3 | match | 5/5 | 1/1 | 0 | single staff numbered 3 |
| code08-p25-layer | match | 5/5 | 1/1 | 0 | layer number P25 = 1 |
| code08-p26-green-009900 | match | 5/5 | 1/1 | 0 | P26 = 9900 |
| code08-p26-grey-0.5 | match | 5/5 | 1/1 | 0 | P26 = 0.5 |
| code08-p26-red | match | 5/5 | 1/1 | 0 | P26 = 990000 |
| code08-p26-rgb-336699 | match | 5/5 | 1/1 | 0 | P26 = 336699 |
| code08-p26-white | match | 5/5 | 1/1 | 0 | P26 = 1 |
| code08-p3-left-10 | match | 5/5 | 1/1 | 0 | left end P3 = 10 |
| code08-p3-left-55.5 | match | 5/5 | 1/1 | 0 | left end P3 = 55.5 |
| code08-p3-left-m20 | match | 5/5 | 1/1 | 0 | left end P3 = -20 |
| code08-p3-p6-short | match | 5/5 | 1/1 | 0 | P3 = 50, P6 = 120 |
| code08-p4-offset-2.5 | match | 5/5 | 1/1 | 0 | vertical offset P4 = 2.5 scale steps |
| code08-p4-offset-5 | match | 5/5 | 1/1 | 0 | vertical offset P4 = 5 scale steps |
| code08-p4-offset-m3 | match | 5/5 | 1/1 | 0 | vertical offset P4 = -3 scale steps |
| code08-p5-size-0.5 | match | 5/5 | 1/1 | 0 | staff size P5 = 0.5 |
| code08-p5-size-0.64 | match | 5/5 | 1/1 | 0 | staff size P5 = 0.64 |
| code08-p5-size-0.65 | match | 5/5 | 1/1 | 0 | staff size P5 = 0.65 |
| code08-p5-size-0.8 | match | 5/5 | 1/1 | 0 | staff size P5 = 0.8 |
| code08-p5-size-1.429 | match | 5/5 | 1/1 | 0 | staff size P5 = 1.429 |
| code08-p5-size-2 | match | 5/5 | 1/1 | 0 | staff size P5 = 2 |
| code08-p5-zero | match | 5/5 | 1/1 | 0 | P5 = 0 (engine default size) |
| code08-p6-right-150 | match | 5/5 | 1/1 | 0 | right end P6 = 150 |
| code08-p6-right-210 | match | 5/5 | 1/1 | 0 | right end P6 = 210 |
| code08-p6-right-220 | match | 5/5 | 1/1 | 0 | right end P6 = 220 |
| code08-p7-invisible | match | 5/5 | 1/1 | 0 | P7 = -1, invisible staff (light grey on screen) |
| code08-p7-lines-1 | match | 1/1 | 1/1 | 0 | 1 staff line(s) |
| code08-p7-lines-10 | match | 10/10 | 1/1 | 0 | 10 staff line(s) |
| code08-p7-lines-2 | match | 2/2 | 1/1 | 0 | 2 staff line(s) |
| code08-p7-lines-3 | match | 3/3 | 1/1 | 0 | 3 staff line(s) |
| code08-p7-lines-4 | match | 4/4 | 1/1 | 0 | 4 staff line(s) |
| code08-p7-lines-6 | match | 6/6 | 1/1 | 0 | 6 staff line(s) |
| code08-p7-lines-7 | match | 7/7 | 1/1 | 0 | 7 staff line(s) |
| code08-p7-xyz-106 | match | 6/6 | 1/1 | 0 | P7 = 106: bottom line of a normal staff, then count |
| code08-p7-xyz-203 | match | 3/3 | 1/1 | 0 | P7 = 203: bottom line of a normal staff, then count |
| code08-p7-xyz-302 | match | 2/2 | 1/1 | 0 | P7 = 302: bottom line of a normal staff, then count |
| code08-p7-xyz-401 | match | 1/1 | 1/1 | 0 | P7 = 401: bottom line of a normal staff, then count |
| code08-p9-instrument | match | 5/5 | 1/1 | 0 | instrument number P9 = 5 |
| code08-staves-12 | match | 60/60 | 15/15 | 0 | twelve staves at size 0.7 |
| code08-staves-2 | match | 10/10 | 2/2 | 0 | staves 1 and 2, size 1 |
| code08-staves-4 | match | 20/20 | 4/4 | 0 | staves 1-4, size 1 |
| code08-staves-ends | match | 15/15 | 3/3 | 0 | staves 1-3 with different P3/P6 |
| code08-staves-gaps | match | 15/15 | 3/3 | 0 | staves 1, 3 and 6 |
| code08-staves-lines | match | 9/9 | 3/3 | 0 | staves with 5, 1 and 3 lines |
| code08-staves-offsets | match | 15/15 | 3/3 | 0 | staves 1-3 with P4 = 0, 4, -2 |
| code08-staves-p10 | match | 15/15 | 3/3 | 0 | staves 1-3, staves 2 and 3 placed by P10 = 1.2 and 2.6 in |
| code08-staves-recto | match | 10/10 | 4/4 | 0 | staff 1 and recto staff 201 |
| code08-staves-sizes | match | 20/20 | 4/4 | 0 | staves 1-4 with sizes 1, 0.75, 1.2, 0.6 |
| code09-p10-pixels-1 | match | 15/15 | 1/1 | 0 | symbol 31, P10 1 |
| code09-p10-pixels-2 | match | 23/23 | 1/1 | 0 | symbol 31, P10 2 |
| code09-p10-pixels-m1 | match | 7/7 | 1/1 | 0 | symbol 31, P10 -1 |
| code09-p10-pixels-p8 | match | 11/11 | 1/1 | 0 | symbol 31, P10 2 with P8 1 (P8 wins) |
| code09-p10-pixels-small | match | 20/20 | 1/1 | 0 | symbol 53, P10 2 (one less for symbols from 45 on) |
| code09-p11-special | match | 85/85 | 1/1 | 0 | special symbol 1302 with P11 1 (hidden in print only) |
| code09-p15-offset-3 | match | 6/6 | 1/1 | 0 | symbol 24, P15 3 |
| code09-p15-offset-m2.5 | match | 6/6 | 1/1 | 0 | symbol 24, P15 -2.5 |
| code09-p25-layer | match | 7/7 | 1/1 | 0 | symbol 31, P25 2 |
| code09-p26-grey | match | 7/7 | 1/1 | 0 | symbol 31, P26 0.5 |
| code09-p26-rgb | match | 8/8 | 1/1 | 0 | symbol 53, P26 336699 |
| code09-p3-fraction | match | 6/6 | 1/1 | 0 | symbol 24, P3 30.37 |
| code09-p4-level-0 | match | 6/6 | 1/1 | 0 | symbol 24, P4 0 |
| code09-p4-level-14.5 | match | 6/6 | 1/1 | 0 | symbol 24, P4 14.5 |
| code09-p4-level-m3 | match | 6/6 | 1/1 | 0 | symbol 24, P4 -3 |
| code09-p5-missing | match | 8/8 | 1/1 | 0 | P5 3 (empty slot) |
| code09-p5-negative | match | 10/10 | 1/1 | 0 | P5 -3 draws symbol 0 |
| code09-p5-symbol-0 | match | 10/10 | 1/1 | 0 | library symbol 0 |
| code09-p5-symbol-1 | match | 10/10 | 1/1 | 0 | library symbol 1 |
| code09-p5-symbol-1000 | match | 7/7 | 1/1 | 0 | library symbol 1000 |
| code09-p5-symbol-103 | match | 6/6 | 1/1 | 0 | library symbol 103 |
| code09-p5-symbol-107 | match | 7/7 | 1/1 | 0 | library symbol 107 |
| code09-p5-symbol-11 | match | 6/6 | 1/1 | 0 | library symbol 11 |
| code09-p5-symbol-1110 | match | 79/79 | 1/1 | 0 | library symbol 1110 |
| code09-p5-symbol-115 | match | 9/9 | 1/1 | 0 | library symbol 115 |
| code09-p5-symbol-119 | match | 7/7 | 1/1 | 0 | library symbol 119 |
| code09-p5-symbol-123 | match | 7/7 | 1/1 | 0 | library symbol 123 |
| code09-p5-symbol-1300 | match | 79/79 | 1/1 | 0 | library symbol 1300 |
| code09-p5-symbol-1302 | match | 85/85 | 1/1 | 0 | library symbol 1302 |
| code09-p5-symbol-1304 | match | 105/105 | 1/1 | 0 | library symbol 1304 |
| code09-p5-symbol-1400 | match | 79/79 | 1/1 | 0 | library symbol 1400 |
| code09-p5-symbol-147 | match | 8/8 | 1/1 | 0 | library symbol 147 |
| code09-p5-symbol-151 | match | 16/16 | 1/1 | 0 | library symbol 151 |
| code09-p5-symbol-18 | match | 9/9 | 1/1 | 0 | library symbol 18 |
| code09-p5-symbol-1960 | match | 6/6 | 1/1 | 0 | library symbol 1960 |
| code09-p5-symbol-199 | match | 29/29 | 1/1 | 0 | library symbol 199 |
| code09-p5-symbol-207 | match | 8/8 | 1/1 | 0 | library symbol 207 |
| code09-p5-symbol-21 | match | 7/7 | 1/1 | 0 | library symbol 21 |
| code09-p5-symbol-219 | match | 6/6 | 1/1 | 0 | library symbol 219 |
| code09-p5-symbol-239 | match | 7/7 | 1/1 | 0 | library symbol 239 |
| code09-p5-symbol-24 | match | 6/6 | 1/1 | 0 | library symbol 24 |
| code09-p5-symbol-263 | match | 9/9 | 1/1 | 0 | library symbol 263 |
| code09-p5-symbol-283 | match | 12/12 | 1/1 | 0 | library symbol 283 |
| code09-p5-symbol-31 | match | 7/7 | 1/1 | 0 | library symbol 31 |
| code09-p5-symbol-34 | match | 11/11 | 1/1 | 0 | library symbol 34 |
| code09-p5-symbol-37 | match | 7/7 | 1/1 | 0 | library symbol 37 |
| code09-p5-symbol-39 | match | 8/8 | 1/1 | 0 | library symbol 39 |
| code09-p5-symbol-41 | match | 6/6 | 1/1 | 0 | library symbol 41 |
| code09-p5-symbol-44 | match | 7/7 | 1/1 | 0 | library symbol 44 |
| code09-p5-symbol-48 | match | 9/9 | 1/1 | 0 | library symbol 48 |
| code09-p5-symbol-49 | match | 8/8 | 1/1 | 0 | library symbol 49 |
| code09-p5-symbol-5 | match | 6/6 | 1/1 | 0 | library symbol 5 |
| code09-p5-symbol-50 | match | 17/17 | 1/1 | 0 | library symbol 50 |
| code09-p5-symbol-53 | match | 8/8 | 1/1 | 0 | library symbol 53 |
| code09-p5-symbol-55 | match | 9/9 | 1/1 | 0 | library symbol 55 |
| code09-p5-symbol-6 | match | 8/8 | 1/1 | 0 | library symbol 6 |
| code09-p5-symbol-600 | match | 11/11 | 1/1 | 0 | library symbol 600 |
| code09-p5-symbol-62 | match | 8/8 | 1/1 | 0 | library symbol 62 |
| code09-p5-symbol-652 | match | 9/9 | 1/1 | 0 | library symbol 652 |
| code09-p5-symbol-70 | match | 7/7 | 1/1 | 0 | library symbol 70 |
| code09-p5-symbol-71 | match | 6/6 | 1/1 | 0 | library symbol 71 |
| code09-p5-symbol-74 | match | 8/8 | 1/1 | 0 | library symbol 74 |
| code09-p5-symbol-75 | match | 6/6 | 1/1 | 0 | library symbol 75 |
| code09-p5-symbol-750 | match | 21/21 | 1/1 | 0 | library symbol 750 |
| code09-p5-symbol-83 | match | 6/6 | 1/1 | 0 | library symbol 83 |
| code09-p5-symbol-900 | match | 6/6 | 1/1 | 0 | library symbol 900 |
| code09-p5-symbol-91 | match | 7/7 | 1/1 | 0 | library symbol 91 |
| code09-p5-text-276 | match | 5/5 | 5/5 | 0 | symbol 276, drawn as text |
| code09-p5-text-3000 | match | 5/5 | 3/3 | 0 | symbol 3000, drawn as text |
| code09-p5-text-3004 | match | 5/5 | 6/6 | 0 | symbol 3004, drawn as text |
| code09-p5-text-45 | match | 5/5 | 4/4 | 0 | symbol 45, drawn as text |
| code09-p5-text-63 | match | 5/5 | 7/7 | 0 | symbol 63, drawn as text |
| code09-p5-text-66 | match | 5/5 | 6/6 | 0 | symbol 66, drawn as text |
| code09-p5-text-78 | match | 5/5 | 7/7 | 0 | symbol 78, drawn as text |
| code09-p6-size-0.5 | match | 7/7 | 1/1 | 0 | symbol 31, P6 0.5 |
| code09-p6-size-1.7 | match | 7/7 | 1/1 | 0 | symbol 31, P6 1.7 |
| code09-p6-size-101.5 | match | 7/7 | 1/1 | 0 | symbol 31, P6 101.5 |
| code09-p6-size-250 | match | 7/7 | 1/1 | 0 | symbol 31, P6 250 |
| code09-p6-size-300 | match | 7/7 | 1/1 | 0 | symbol 31, P6 300 |
| code09-p6-size-m1 | match | 7/7 | 1/1 | 0 | symbol 31, P6 -1 |
| code09-p6-size-small-0.6 | match | 8/8 | 1/1 | 0 | symbol 53, P6 0.6 |
| code09-p6-size-small-2 | match | 8/8 | 1/1 | 0 | symbol 53, P6 2 |
| code09-p7-only | match | 7/7 | 1/1 | 0 | symbol 31, P7 1.5 without P6 |
| code09-p7-vsize-0.5 | match | 7/7 | 1/1 | 0 | symbol 31, P6 1, P7 0.5 |
| code09-p7-vsize-2 | match | 7/7 | 1/1 | 0 | symbol 31, P6 1, P7 2 |
| code09-p7-vsize-m1 | match | 7/7 | 1/1 | 0 | symbol 31, P6 1, P7 -1 |
| code09-p8-thick-101 | match | 15/15 | 1/1 | 0 | symbol 31, P8 101 |
| code09-p8-thick-202 | match | 23/23 | 1/1 | 0 | symbol 31, P8 202 |
| code09-p8-thick-3 | match | 19/19 | 1/1 | 0 | symbol 31, P8 3 |
| code09-p8-thick-300 | match | 19/19 | 1/1 | 0 | symbol 31, P8 300 |
| code09-p8-thick-m1 | match | 7/7 | 1/1 | 0 | symbol 31, P8 -1 |
| code09-p8-thick-small | match | 20/20 | 1/1 | 0 | symbol 53, P8 101 |
| code09-p9-rotation-0.5 | match | 7/7 | 1/1 | 0 | symbol 37, P9 0.5 |
| code09-p9-rotation-1.5 | match | 7/7 | 1/1 | 0 | symbol 37, P9 1.5 |
| code09-p9-rotation-30 | match | 7/7 | 1/1 | 0 | symbol 37, P9 30 |
| code09-p9-rotation-90 | match | 7/7 | 1/1 | 0 | symbol 37, P9 90 |
| code09-p9-rotation-m45 | match | 7/7 | 1/1 | 0 | symbol 37, P9 -45 |
| code09-p9-rotation-small | match | 7/7 | 1/1 | 0 | symbol 70, P9 20 |
| code09-recto | match | 7/7 | 3/3 | 0 | symbol 31 on the recto staff 201 |
| code09-several | match | 23/23 | 1/1 | 0 | several symbols in a row |
| code09-size-0.75 | match | 10/10 | 1/1 | 0 | symbols 31 and 53 on a size 0.75 staff |
| code09-size-0.75-special | match | 85/85 | 1/1 | 0 | special symbol 1302 on a size 0.75 staff |
| code09-size-1.3 | match | 10/10 | 1/1 | 0 | symbols 31 and 53 on a size 1.3 staff |
| code09-staff-0-special | match | 85/85 | 1/1 | 0 | special symbol 1302 on staff 0 |
| code09-staff-2 | match | 12/12 | 2/2 | 0 | symbol 31 on staff 2 |
| code10-p10-thick-2-box | match | 6/6 | 5/5 | 0 | box P10 = 2 |
| code10-p10-thick-3-box | match | 6/6 | 5/5 | 0 | box P10 = 3 |
| code10-p11-circle | match | 7/7 | 5/5 | 0 | circle P11 = 4 |
| code10-p11-p12-box | match | 6/6 | 5/5 | 0 | box P11 = 3, P12 = 2 |
| code10-p12-circle | match | 7/7 | 5/5 | 0 | circle P12 = 3 |
| code10-p13-p14-box | match | 6/6 | 5/5 | 0 | box P13 = 1, P14 = 2 |
| code10-p15-offset-2 | match | 5/5 | 3/3 | 0 | offset P15 = 2 |
| code10-p15-offset-m1.5 | match | 5/5 | 3/3 | 0 | offset P15 = -1.5 |
| code10-p16-pixels-music | match | 7/7 | 1/1 | 0 | P16 = 1, music font |
| code10-p17-letter-1 | match | 5/5 | 4/4 | 0 | P5 = 23, P17 = 1 |
| code10-p17-letter-101 | match | 5/5 | 4/4 | 0 | P5 = 23, P17 = 101 |
| code10-p17-letter-126 | match | 5/5 | 4/4 | 0 | P5 = 23, P17 = 126 |
| code10-p17-letter-2 | match | 5/5 | 4/4 | 0 | P5 = 23, P17 = 2 |
| code10-p18-1234 | match | 5/5 | 5/5 | 0 | P18 = 1234 |
| code10-p18-9999 | match | 5/5 | 5/5 | 0 | P18 = 9999 |
| code10-p18-letter-100 | match | 5/5 | 3/3 | 0 | P5 = 1002, P18 = 100 |
| code10-p18-letter-12 | match | 5/5 | 4/4 | 0 | P5 = 1002, P18 = 12 |
| code10-p18-letter-2 | match | 5/5 | 3/3 | 0 | P5 = 1002, P18 = 2 |
| code10-p18-letter-226 | match | 5/5 | 4/4 | 0 | P5 = 1002, P18 = 226 |
| code10-p18-letter-m500 | match | 5/5 | 3/3 | 0 | P5 = 1002, P18 = -500 |
| code10-p18-m1500 | match | 5/5 | 6/6 | 0 | P18 = -1500 |
| code10-p19-rotate-30 | match | 5/5 | 3/3 | 0 | rotation P19 = 30 |
| code10-p19-rotate-m90 | match | 5/5 | 3/3 | 0 | rotation P19 = -90 |
| code10-p20-spread-1.15 | match | 5/5 | 4/4 | 0 | spread P20 = 1.15 |
| code10-p20-spread-2 | match | 5/5 | 4/4 | 0 | spread P20 = 2 |
| code10-p26-red | match | 5/5 | 3/3 | 0 | P26 = 990000 |
| code10-p26-red-box | match | 6/6 | 5/5 | 0 | P26 = 990000, box |
| code10-p5-0 | match | 5/5 | 2/2 | 0 | P5 = 0 |
| code10-p5-0.5 | match | 5/5 | 3/3 | 0 | P5 = 0.5 |
| code10-p5-1000 | match | 5/5 | 4/4 | 0 | P5 = 1000 |
| code10-p5-1001 | match | 5/5 | 2/2 | 0 | P5 = 1001 |
| code10-p5-1026 | match | 5/5 | 2/2 | 0 | P5 = 1026 |
| code10-p5-12 | match | 5/5 | 3/3 | 0 | P5 = 12 |
| code10-p5-12.5 | match | 5/5 | 5/5 | 0 | P5 = 12.5 |
| code10-p5-123 | match | 5/5 | 4/4 | 0 | P5 = 123 |
| code10-p5-2001 | match | 5/5 | 2/2 | 0 | P5 = 2001 |
| code10-p5-2003 | match | 5/5 | 2/2 | 0 | P5 = 2003 |
| code10-p5-3.125 | match | 5/5 | 6/6 | 0 | P5 = 3.125 |
| code10-p5-5 | match | 5/5 | 2/2 | 0 | P5 = 5 |
| code10-p5-7.001 | match | 5/5 | 6/6 | 0 | P5 = 7.001 |
| code10-p5-999 | match | 5/5 | 4/4 | 0 | P5 = 999 |
| code10-p5-m0.25 | match | 5/5 | 5/5 | 0 | P5 = -0.25 |
| code10-p5-m2.5 | match | 5/5 | 5/5 | 0 | P5 = -2.5 |
| code10-p5-m4 | match | 5/5 | 3/3 | 0 | P5 = -4 |
| code10-p6-size-0.5 | match | 5/5 | 3/3 | 0 | size P6 = 0.5 |
| code10-p6-size-101.5 | match | 5/5 | 3/3 | 0 | size P6 = 101.5 |
| code10-p6-size-2 | match | 5/5 | 3/3 | 0 | size P6 = 2 |
| code10-p7-font--1 | match | 5/5 | 3/3 | 0 | font P7 = -1 |
| code10-p7-font-1 | match | 5/5 | 3/3 | 0 | font P7 = 1 |
| code10-p7-font-10 | match | 5/5 | 3/3 | 0 | font P7 = 10 |
| code10-p7-font-1005 | match | 5/5 | 3/3 | 0 | font P7 = 1005 |
| code10-p7-font-11 | match | 5/5 | 3/3 | 0 | font P7 = 11 |
| code10-p7-font-2 | match | 5/5 | 3/3 | 0 | font P7 = 2 |
| code10-p7-font-3 | match | 5/5 | 3/3 | 0 | font P7 = 3 |
| code10-p7-font-4 | match | 5/5 | 3/3 | 0 | font P7 = 4 |
| code10-p7-font-5 | match | 5/5 | 3/3 | 0 | font P7 = 5 |
| code10-p7-font-6 | match | 7/7 | 1/1 | 0 | font P7 = 6 |
| code10-p7-font-7 | match | 5/5 | 3/3 | 0 | font P7 = 7 |
| code10-p7-font-8 | match | 5/5 | 3/3 | 0 | font P7 = 8 |
| code10-p7-font-9 | match | 5/5 | 3/3 | 0 | font P7 = 9 |
| code10-p8-box | match | 6/6 | 5/5 | 0 | P8 = 2 |
| code10-p8-box-letter | match | 6/6 | 3/3 | 0 | P8 = 2, P5 = 1001 |
| code10-p8-box-wide | match | 6/6 | 7/7 | 0 | P8 = 2, P5 = 123 |
| code10-p8-circle | match | 7/7 | 5/5 | 0 | P8 = 1 |
| code10-p8-circle-letter | match | 7/7 | 3/3 | 0 | P8 = 1, P5 = 1001 |
| code10-p8-circle-wide | match | 7/7 | 7/7 | 0 | P8 = 1, P5 = 123 |
| code10-staff-recto-201 | match | 5/5 | 5/5 | 0 | recto staff 201 |
| code10-staff-size-0.75 | match | 5/5 | 3/3 | 0 | staff size 0.75 |
| code10-staff-size-0.75-box | match | 6/6 | 5/5 | 0 | staff size 0.75, box |
| code10-staff-size-1.4 | match | 5/5 | 3/3 | 0 | staff size 1.4 |
| code10-staff-size-m1 | match | 5/5 | 3/3 | 0 | staff size -1 |
| code11-fault | match | 6/6 | 1/1 | 0 | FAULT symbol 0 |
| code11-name-lower-case | match | 23/23 | 1/1 | 0 | name kbrhy.drw |
| code11-name-no-extension | match | 36/36 | 1/1 | 0 | name KBRHY |
| code11-name-scorlib-path | match | 23/23 | 1/1 | 0 | name \WINSCORE\SCORLIB\KBRHY.DRW |
| code11-p10-pixels-1 | match | 10/10 | 1/1 | 0 | pixel thickness P10 = 1 |
| code11-p10-pixels-2 | match | 14/14 | 1/1 | 0 | pixel thickness P10 = 2 |
| code11-p15-offset | match | 23/23 | 1/1 | 0 | P15 = 5 (not applied to code 11) |
| code11-p26-grey | match | 6/6 | 1/1 | 0 | P26 = 0.5 |
| code11-p4-p3 | match | 6/6 | 1/1 | 0 | P3 = 120, P4 = 2 |
| code11-p5-0 | match | 23/23 | 1/1 | 0 | KBRHY symbol 0 |
| code11-p5-1 | match | 36/36 | 1/1 | 0 | KBRHY symbol 1 |
| code11-p5-2 | match | 5/5 | 1/1 | 0 | KBRHY symbol 2 |
| code11-p5-9 | match | 54/54 | 1/1 | 0 | KBRHY symbol 9 |
| code11-p6-p7 | match | 23/23 | 1/1 | 0 | P6 = 0.5, P7 = 1.5 |
| code11-p6-size-0.5 | match | 23/23 | 1/1 | 0 | size P6 = 0.5 |
| code11-p6-size-1.5 | match | 23/23 | 1/1 | 0 | size P6 = 1.5 |
| code11-p6-size-101 | match | 23/23 | 1/1 | 0 | size P6 = 101 |
| code11-p6-size-m1 | match | 23/23 | 1/1 | 0 | size P6 = -1 |
| code11-p8-thick-101 | match | 10/10 | 1/1 | 0 | thickness P8 = 101 |
| code11-p8-thick-2 | match | 10/10 | 1/1 | 0 | thickness P8 = 2 |
| code11-p8-thick-m1 | match | 6/6 | 1/1 | 0 | thickness P8 = -1 |
| code11-p9-rotate-0.5 | match | 6/6 | 1/1 | 0 | rotation P9 = 0.5 |
| code11-p9-rotate-30 | match | 6/6 | 1/1 | 0 | rotation P9 = 30 |
| code11-p9-rotate-m90 | match | 6/6 | 1/1 | 0 | rotation P9 = -90 |
| code11-staff-recto-201 | match | 6/6 | 3/3 | 0 | recto staff 201 |
| code11-staff-size-0.75 | match | 6/6 | 1/1 | 0 | staff size 0.75 |
| code11-staff-size-1.4 | match | 6/6 | 1/1 | 0 | staff size 1.4 |
| code11-staff-size-m1 | match | 6/6 | 1/1 | 0 | staff size -1 |
| code11-then-staff | match | 11/11 | 2/2 | 0 | a code-11 item, then a second staff |
| code11-two-files | match | 37/37 | 1/1 | 0 | KBRHY symbol 1 then FAULT symbol 0 |
| code12-arrow-arc-flipped | match | 7/7 | 1/1 | 0 | arc arrow, P6 = -2, P7 = -2 |
| code12-arrow-arc-head | match | 7/7 | 1/1 | 0 | arc arrow, P12 = 2, P13 = 3 |
| code12-arrow-arc-marked | match | 13/13 | 1/1 | 0 | arc arrow, P26 = -1 |
| code12-arrow-arc-no-head | match | 6/6 | 1/1 | 0 | arc arrow, P12 = -1 |
| code12-arrow-arc-p11-150 | match | 7/7 | 1/1 | 0 | arc arrow, P11 = 150 |
| code12-arrow-arc-p11-30 | match | 7/7 | 1/1 | 0 | arc arrow, P11 = 30 |
| code12-arrow-arc-p11-90 | match | 6/6 | 1/1 | 0 | arc arrow, P11 = 90 |
| code12-arrow-arc-p6-p7 | match | 7/7 | 1/1 | 0 | arc arrow, P6 = 3, P7 = 1.5 |
| code12-arrow-arc-rotated | match | 7/7 | 1/1 | 0 | arc arrow, P9 = 45 |
| code12-arrow-arc-rotated-0.5 | match | 7/7 | 1/1 | 0 | arc arrow, P9 = 0.5 |
| code12-arrow-arc-thick | match | 9/9 | 1/1 | 0 | arc arrow, P8 = 2 |
| code12-arrow-straight-default | match | 7/7 | 1/1 | 0 | straight arrow, P6 = 0 |
| code12-arrow-straight-head | match | 7/7 | 1/1 | 0 | straight arrow, P12 = 2, P13 = 3 |
| code12-arrow-straight-left | match | 7/7 | 1/1 | 0 | straight arrow, P6 = -2 |
| code12-arrow-straight-long | match | 7/7 | 1/1 | 0 | straight arrow, P6 = 2.5 |
| code12-arrow-straight-no-head | match | 6/6 | 1/1 | 0 | straight arrow, P12 = -1 |
| code12-arrow-straight-rotated | match | 7/7 | 1/1 | 0 | straight arrow, P9 = 30 |
| code12-arrow-straight-rotated-no-head | match | 6/6 | 1/1 | 0 | straight arrow, P9 = -60, P12 = -1 |
| code12-grid-barre | match | 24/24 | 4/4 | 0 | guitar grid, P13 = 133211, P12 = 1601 |
| code12-grid-barre-3 | match | 24/24 | 4/4 | 0 | guitar grid, P13 = 335553, P12 = 2603 |
| code12-grid-basic | match | 18/18 | 1/1 | 0 | guitar grid, P5 = -1 |
| code12-grid-dict-10-1-0 | match | 25/25 | 5/5 | 0 | guitar grid, dictionary P5 = -4, P7 = 10, P8 = 1, P9 = 0 |
| code12-grid-dict-10-2-0 | match | 26/26 | 7/7 | 0 | guitar grid, dictionary P5 = -4, P7 = 10, P8 = 2, P9 = 0 |
| code12-grid-dict-11-19-0 | match | 33/33 | 8/8 | 0 | guitar grid, dictionary P5 = -4, P7 = 11, P8 = 19, P9 = 0 |
| code12-grid-dict-12-7-2 | match | 28/28 | 12/12 | 0 | guitar grid, dictionary P5 = -4, P7 = 12, P8 = 7, P9 = 2 |
| code12-grid-dict-21-3-0 | match | 30/30 | 7/7 | 0 | guitar grid, dictionary P5 = -4, P7 = 21, P8 = 3, P9 = 0 |
| code12-grid-dict-41-11-4 | match | 29/29 | 8/8 | 0 | guitar grid, dictionary P5 = -4, P7 = 41, P8 = 11, P9 = 4 |
| code12-grid-dict-60-12-1 | match | 24/24 | 14/14 | 0 | guitar grid, dictionary P5 = -4, P7 = 60, P8 = 12, P9 = 1 |
| code12-grid-dict-72-20-3 | match | 32/32 | 5/5 | 0 | guitar grid, dictionary P5 = -4, P7 = 72, P8 = 20, P9 = 3 |
| code12-grid-dict-p5-5 | match | 5/5 | 2/2 | 0 | guitar grid, P5 = -5, P7 = 10 |
| code12-grid-dict-p5-6 | match | 26/26 | 5/5 | 0 | guitar grid, P5 = -6, P7 = 10, P8 = 7 |
| code12-grid-dots | match | 24/24 | 1/1 | 0 | guitar grid, P13 = 132211 |
| code12-grid-dots-4 | match | 20/20 | 1/1 | 0 | guitar grid, P14 = 54, P13 = 1234 |
| code12-grid-fingers | match | 24/24 | 7/7 | 0 | guitar grid, P13 = 132211, P18 = 132411 |
| code12-grid-fingers-thumb | match | 24/24 | 7/7 | 0 | guitar grid, P13 = 132211, P18 = 932811 |
| code12-grid-fret | match | 23/23 | 4/4 | 0 | guitar grid, P12 = 5, P13 = 133211 |
| code12-grid-fret-frac | match | 17/17 | 4/4 | 0 | guitar grid, P12 = 5.5 |
| code12-grid-name-only | match | 5/5 | 2/2 | 0 | guitar grid, P5 = -3, P7 = 10 |
| code12-grid-no-nut | match | 17/17 | 1/1 | 0 | guitar grid, P5 = -2 |
| code12-grid-open-muted | match | 25/25 | 1/1 | 0 | guitar grid, P13 = 932818 |
| code12-grid-p10-1000 | match | 18/18 | 5/5 | 0 | guitar grid, P7 = 10, P10 = 1000 |
| code12-grid-p10-109 | match | 21/21 | 3/3 | 0 | guitar grid, P7 = 10, P10 = 109 |
| code12-grid-p10-2000 | match | 18/18 | 5/5 | 0 | guitar grid, P7 = 10, P10 = 2000 |
| code12-grid-p10-3009 | match | 18/18 | 8/8 | 0 | guitar grid, P7 = 10, P10 = 3009 |
| code12-grid-p11-105 | match | 21/21 | 4/4 | 0 | guitar grid, P7 = 10, P11 = 105 |
| code12-grid-p11-5000 | match | 18/18 | 4/4 | 0 | guitar grid, P7 = 10, P11 = 5000 |
| code12-grid-p11-7011 | match | 18/18 | 6/6 | 0 | guitar grid, P7 = 10, P11 = 7011 |
| code12-grid-p14-45 | match | 16/16 | 1/1 | 0 | guitar grid, P5 = -1, P14 = 45 (4 strings? 5 frets) |
| code12-grid-p14-64 | match | 17/17 | 1/1 | 0 | guitar grid, P5 = -1, P14 = 64 |
| code12-grid-p16 | match | 18/18 | 2/2 | 0 | guitar grid, P16 = 1.5, P7 = 10 |
| code12-grid-p17-negative | match | 17/17 | 1/1 | 0 | guitar grid, P17 = -1 |
| code12-grid-p17-wide | match | 24/24 | 1/1 | 0 | guitar grid, P17 = 1.5 |
| code12-grid-p19-name | match | 18/18 | 2/2 | 0 | guitar grid, P19 = 2, P7 = 10 |
| code12-grid-p9-107 | match | 21/21 | 3/3 | 0 | guitar grid, P7 = 10, P9 = 107 |
| code12-grid-p9-409 | match | 18/18 | 4/4 | 0 | guitar grid, P7 = 10, P9 = 409 |
| code12-grid-p9-513 | match | 18/18 | 5/5 | 0 | guitar grid, P7 = 10, P9 = 513 |
| code12-grid-p9-607 | match | 19/19 | 3/3 | 0 | guitar grid, P7 = 10, P9 = 607 |
| code12-grid-root-10 | match | 18/18 | 2/2 | 0 | guitar grid, P7 = 10 |
| code12-grid-root-11 | match | 21/21 | 2/2 | 0 | guitar grid, P7 = 11 |
| code12-grid-root-12 | match | 22/22 | 2/2 | 0 | guitar grid, P7 = 12 |
| code12-grid-root-20 | match | 18/18 | 2/2 | 0 | guitar grid, P7 = 20 |
| code12-grid-root-32 | match | 22/22 | 2/2 | 0 | guitar grid, P7 = 32 |
| code12-grid-root-41 | match | 21/21 | 2/2 | 0 | guitar grid, P7 = 41 |
| code12-grid-root-52 | match | 22/22 | 2/2 | 0 | guitar grid, P7 = 52 |
| code12-grid-root-60 | match | 18/18 | 2/2 | 0 | guitar grid, P7 = 60 |
| code12-grid-root-70 | match | 18/18 | 2/2 | 0 | guitar grid, P7 = 70 |
| code12-grid-root-71 | match | 21/21 | 2/2 | 0 | guitar grid, P7 = 71 |
| code12-grid-rotated | match | 24/24 | 1/1 | 0 | guitar grid, P9 = 20 is a name code, not rotation; P13 dots |
| code12-grid-sample-000-a | match | 25/25 | 5/5 | 0 | guitar grid, 000.mus: P5 = -4, P6 = 1, P7 = 10 |
| code12-grid-sample-000-b | match | 25/25 | 5/5 | 0 | guitar grid, 000.mus: P5 = -4, P6 = 1, P7 = 60, P8 = 1 |
| code12-grid-sample-000-c | match | 29/29 | 10/10 | 0 | guitar grid, 000.mus: P5 = -4, P6 = 1, P7 = 12, P8 = 2 |
| code12-grid-size | match | 24/24 | 1/1 | 0 | guitar grid, P6 = 1.5, P13 = 132211 |
| code12-grid-type-1 | match | 18/18 | 5/5 | 0 | guitar grid, P7 = 10, P8 = 1 |
| code12-grid-type-2 | match | 18/18 | 3/3 | 0 | guitar grid, P7 = 10, P8 = 2 |
| code12-grid-type-3 | match | 19/19 | 2/2 | 0 | guitar grid, P7 = 10, P8 = 3 |
| code12-grid-type-4 | match | 20/20 | 2/2 | 0 | guitar grid, P7 = 10, P8 = 4 |
| code12-grid-type-5 | match | 18/18 | 3/3 | 0 | guitar grid, P7 = 10, P8 = 5 |
| code12-grid-type-6 | match | 18/18 | 5/5 | 0 | guitar grid, P7 = 10, P8 = 6 |
| code12-grid-type-7 | match | 18/18 | 5/5 | 0 | guitar grid, P7 = 10, P8 = 7 |
| code12-grid-type-8 | match | 19/19 | 2/2 | 0 | guitar grid, P7 = 10, P8 = 8 |
| code12-grid-type-9 | match | 18/18 | 3/3 | 0 | guitar grid, P7 = 10, P8 = 9 |
| code12-p10-dash-0.5 | match | 18/18 | 1/1 | 0 | dashed box dash P10 = 0.5 |
| code12-p10-dash-2 | match | 6/6 | 1/1 | 0 | dashed box dash P10 = 2 |
| code12-p10-p11-arc--90-90 | match | 6/6 | 1/1 | 0 | circle arc P10 = -90, P11 = 90 |
| code12-p10-p11-arc-0-180 | match | 6/6 | 1/1 | 0 | circle arc P10 = 0, P11 = 180 |
| code12-p10-p11-arc-300-60 | match | 6/6 | 1/1 | 0 | circle arc P10 = 300, P11 = 60 |
| code12-p10-p11-arc-45-0 | match | 6/6 | 1/1 | 0 | circle arc P10 = 45, P11 = 0 |
| code12-p10-p11-arc-90-270 | match | 6/6 | 1/1 | 0 | circle arc P10 = 90, P11 = 270 |
| code12-p10-slant-1 | match | 6/6 | 1/1 | 0 | box slant P10 = 1 |
| code12-p10-slant-m0.5 | match | 6/6 | 1/1 | 0 | box slant P10 = -0.5 |
| code12-p12-arc-dashes | match | 14/14 | 1/1 | 0 | arc 0-180 with P12 = -10 |
| code12-p12-sides--20 | match | 14/14 | 1/1 | 0 | circle P12 = -20 |
| code12-p12-sides--5 | match | 41/41 | 1/1 | 0 | circle P12 = -5 |
| code12-p12-sides--7 | match | 35/35 | 1/1 | 0 | circle P12 = -7 |
| code12-p12-sides-45 | match | 6/6 | 1/1 | 0 | circle P12 = 45 |
| code12-p12-sides-60 | match | 6/6 | 1/1 | 0 | circle P12 = 60 |
| code12-p12-sides-7 | match | 6/6 | 1/1 | 0 | circle P12 = 7 |
| code12-p13-fill-box | match | 6/6 | 1/1 | 0 | filled P5 = 0 |
| code12-p13-fill-circle | match | 6/6 | 1/1 | 0 | filled P5 = 1 |
| code12-p13-fill-dashed | match | 10/10 | 1/1 | 0 | filled P5 = 3 |
| code12-p13-fill-thick-box | match | 6/6 | 1/1 | 0 | filled box P8 = 2 |
| code12-p13-fill-thick-circle | match | 8/8 | 1/1 | 0 | filled circle P8 = 2 |
| code12-p15-offset-2 | match | 6/6 | 1/1 | 0 | offset P15 = 2 |
| code12-p15-offset-m1.5 | match | 6/6 | 1/1 | 0 | offset P15 = -1.5 |
| code12-p16-unit-box | match | 6/6 | 1/1 | 0 | P16 = 1, P5 = 0, P6 = 0.2 |
| code12-p16-unit-circle | match | 6/6 | 1/1 | 0 | P16 = 1, P5 = 1, P6 = 0.2 |
| code12-p16-unit-dashed | match | 14/14 | 1/1 | 0 | P16 = 1, P5 = 3, P6 = 0.2 |
| code12-p26-grey | match | 6/6 | 1/1 | 0 | P26 = 0.5 |
| code12-p26-marked | match | 6/6 | 1/1 | 0 | P26 = -1 |
| code12-p26-marked-circle | match | 9/9 | 1/1 | 0 | P26 = -1 circle |
| code12-p5-arrow-p10-1 | match | 7/7 | 1/1 | 0 | P5 = 2, P10 = 1 (straight arrow) |
| code12-p5-box | match | 6/6 | 1/1 | 0 | P5 = 0, default size |
| code12-p5-circle | match | 6/6 | 1/1 | 0 | P5 = 1, default size |
| code12-p5-other-10 | match | 9/9 | 1/1 | 0 | P5 = 10 |
| code12-p5-other-2 | match | 7/7 | 1/1 | 0 | P5 = 2 |
| code12-p5-other-4 | match | 7/7 | 1/1 | 0 | P5 = 4 |
| code12-p5-other-5 | match | 7/7 | 1/1 | 0 | P5 = 5 |
| code12-p5-other-m1 | match | 18/18 | 1/1 | 0 | P5 = -1 |
| code12-p5-other-m10 | match | 17/17 | 1/1 | 0 | P5 = -10 |
| code12-p5-other-m2 | match | 17/17 | 1/1 | 0 | P5 = -2 |
| code12-p5-other-m5 | match | 5/5 | 1/1 | 0 | P5 = -5 |
| code12-p6-2-box | match | 6/6 | 1/1 | 0 | P6 = 2, P5 = 0 |
| code12-p6-2-circle | match | 6/6 | 1/1 | 0 | P6 = 2, P5 = 1 |
| code12-p6-2-dashed | match | 6/6 | 1/1 | 0 | P6 = 2, P5 = 3 |
| code12-p6-4.5-box | match | 6/6 | 1/1 | 0 | P6 = 4.5, P5 = 0 |
| code12-p6-4.5-circle | match | 6/6 | 1/1 | 0 | P6 = 4.5, P5 = 1 |
| code12-p6-4.5-dashed | match | 10/10 | 1/1 | 0 | P6 = 4.5, P5 = 3 |
| code12-p6-m3-box | match | 6/6 | 1/1 | 0 | P6 = -3, P5 = 0 |
| code12-p6-m3-circle | match | 6/6 | 1/1 | 0 | P6 = -3, P5 = 1 |
| code12-p6-p7-box | match | 6/6 | 1/1 | 0 | P6 = 4, P7 = 2, P5 = 0 |
| code12-p6-p7-circle | match | 6/6 | 1/1 | 0 | P6 = 4, P7 = 2, P5 = 1 |
| code12-p6-p7-dashed | match | 8/8 | 1/1 | 0 | P6 = 4, P7 = 2, P5 = 3 |
| code12-p8-thick-1-box | match | 6/6 | 1/1 | 0 | thickness P8 = 1, P5 = 0 |
| code12-p8-thick-1-circle | match | 7/7 | 1/1 | 0 | thickness P8 = 1, P5 = 1 |
| code12-p8-thick-1-dashed | match | 15/15 | 1/1 | 0 | thickness P8 = 1, P5 = 3 |
| code12-p8-thick-3-box | match | 6/6 | 1/1 | 0 | thickness P8 = 3, P5 = 0 |
| code12-p8-thick-3-circle | match | 9/9 | 1/1 | 0 | thickness P8 = 3, P5 = 1 |
| code12-p8-thick-3-dashed | match | 15/15 | 1/1 | 0 | thickness P8 = 3, P5 = 3 |
| code12-p8-thick-m1-box | match | 6/6 | 1/1 | 0 | thickness P8 = -1, P5 = 0 |
| code12-p8-thick-m1-circle | match | 6/6 | 1/1 | 0 | thickness P8 = -1, P5 = 1 |
| code12-p8-thick-m1-dashed | match | 10/10 | 1/1 | 0 | thickness P8 = -1, P5 = 3 |
| code12-p9-rotate-0.5-box | match | 6/6 | 1/1 | 0 | rotation P9 = 0.5, P5 = 0 |
| code12-p9-rotate-0.5-circle | match | 6/6 | 1/1 | 0 | rotation P9 = 0.5, P5 = 1 |
| code12-p9-rotate-0.5-dashed | match | 8/8 | 1/1 | 0 | rotation P9 = 0.5, P5 = 3 |
| code12-p9-rotate-30-box | match | 6/6 | 1/1 | 0 | rotation P9 = 30, P5 = 0 |
| code12-p9-rotate-30-circle | match | 6/6 | 1/1 | 0 | rotation P9 = 30, P5 = 1 |
| code12-p9-rotate-30-dashed | match | 8/8 | 1/1 | 0 | rotation P9 = 30, P5 = 3 |
| code12-p9-rotate-m45-box | match | 6/6 | 1/1 | 0 | rotation P9 = -45, P5 = 0 |
| code12-p9-rotate-m45-circle | match | 6/6 | 1/1 | 0 | rotation P9 = -45, P5 = 1 |
| code12-p9-rotate-m45-dashed | match | 8/8 | 1/1 | 0 | rotation P9 = -45, P5 = 3 |
| code12-register-default | match | 9/9 | 1/1 | 0 | accordion register, P7 = 0 |
| code12-register-filled | match | 9/9 | 1/1 | 0 | accordion register, P13 = 1 |
| code12-register-offset | match | 10/10 | 1/1 | 0 | accordion register, P15 = 2, P8 = 1 |
| code12-register-polygon | match | 10/10 | 1/1 | 0 | accordion register, P12 = 30 |
| code12-register-rows2 | match | 10/10 | 1/1 | 0 | accordion register, P7 = 2, P8 = 11 |
| code12-register-rows2-below | match | 9/9 | 1/1 | 0 | accordion register, P7 = 2, P8 = 10 |
| code12-register-rows3-centre | match | 10/10 | 1/1 | 0 | accordion register, P8 = 10 |
| code12-register-rows3-dots | match | 14/14 | 1/1 | 0 | accordion register, P8 = 111, P9 = 101 |
| code12-register-rows3-p9-centre | match | 10/10 | 1/1 | 0 | accordion register, P9 = 10 |
| code12-register-rows4 | match | 12/12 | 1/1 | 0 | accordion register, P7 = 4, P8 = 1010 |
| code12-register-rows4-110 | match | 13/13 | 1/1 | 0 | accordion register, P7 = 4, P8 = 110, P9 = 1 |
| code12-register-rows4-all | match | 16/16 | 1/1 | 0 | accordion register, P7 = 4, P8 = 1111, P9 = 101 |
| code12-register-size | match | 11/11 | 1/1 | 0 | accordion register, P6 = 1.5, P8 = 101 |
| code12-register-thick | match | 12/12 | 1/1 | 0 | accordion register, P10 = 2 |
| code12-staff-recto-201 | match | 6/6 | 3/3 | 0 | recto staff 201, circle |
| code12-staff-size-0.75-box | match | 6/6 | 1/1 | 0 | staff size 0.75, P5 = 0 |
| code12-staff-size-0.75-circle | match | 6/6 | 1/1 | 0 | staff size 0.75, P5 = 1 |
| code12-staff-size-0.75-dashed | match | 6/6 | 1/1 | 0 | staff size 0.75, P5 = 3 |
| code12-staff-size-1.4-box | match | 6/6 | 1/1 | 0 | staff size 1.4, P5 = 0 |
| code12-staff-size-1.4-circle | match | 6/6 | 1/1 | 0 | staff size 1.4, P5 = 1 |
| code12-staff-size-1.4-dashed | match | 10/10 | 1/1 | 0 | staff size 1.4, P5 = 3 |
| code12-staff-size-m1-box | match | 6/6 | 1/1 | 0 | staff size -1, P5 = 0 |
| code12-staff-size-m1-circle | match | 6/6 | 1/1 | 0 | staff size -1, P5 = 1 |
| code14-lines-3 | match | 4/4 | 1/1 | 0 | barline on a three-line staff |
| code14-no-staff | match | 1/1 | 0/0 | 0 | barline without any staff |
| code14-p10-bottom-4 | match | 21/21 | 4/4 | 0 | partial bar, bottom origin P10 = 4 |
| code14-p10-bottom-m2 | match | 21/21 | 4/4 | 0 | partial bar, bottom origin P10 = -2 |
| code14-p10-p11-mensurstrich | match | 21/21 | 4/4 | 0 | bar between staves only: P10 = 8, P11 = -8 |
| code14-p11-top-3 | match | 21/21 | 4/4 | 0 | partial bar, top extent P11 = 3 |
| code14-p11-top-m4 | match | 21/21 | 4/4 | 0 | partial bar, top extent P11 = -4 |
| code14-p12-dots-0.5 | match | 32/32 | 4/4 | 0 | repeat-dot size P12 = 0.5 |
| code14-p12-dots-2 | match | 32/32 | 4/4 | 0 | repeat-dot size P12 = 2 |
| code14-p13-space-0.5-double | match | 22/22 | 4/4 | 0 | space between bars P13 = 0.5, type 1 |
| code14-p13-space-0.5-final | match | 23/23 | 4/4 | 0 | space between bars P13 = 0.5, type 2 |
| code14-p13-space-0.5-repeat-both | match | 32/32 | 4/4 | 0 | space between bars P13 = 0.5, type 5 |
| code14-p13-space-2-double | match | 22/22 | 4/4 | 0 | space between bars P13 = 2, type 1 |
| code14-p13-space-2-final | match | 23/23 | 4/4 | 0 | space between bars P13 = 2, type 2 |
| code14-p13-space-2-repeat-both | match | 32/32 | 4/4 | 0 | space between bars P13 = 2, type 5 |
| code14-p14-dot-gap-0.5 | match | 32/32 | 4/4 | 0 | dot-to-line space P14 = 0.5 |
| code14-p14-dot-gap-2 | match | 32/32 | 4/4 | 0 | dot-to-line space P14 = 2 |
| code14-p16-dots-12 | match | 27/27 | 4/4 | 0 | repeat-dot positions P16 = 12 |
| code14-p16-dots-307 | match | 27/27 | 4/4 | 0 | repeat-dot positions P16 = 307 |
| code14-p16-dots-410 | match | 27/27 | 4/4 | 0 | repeat-dot positions P16 = 410 |
| code14-p17-double-spacing | match | 19/19 | 3/3 | 0 | double bar on a size-0.7 staff with P17 = 1 |
| code14-p18-gap-40-double | match | 24/24 | 4/4 | 0 | gap centre P18 = 40 %, type 1 |
| code14-p18-gap-40-single | match | 22/22 | 4/4 | 0 | gap centre P18 = 40 %, type 0 |
| code14-p18-gap-57-double | match | 24/24 | 4/4 | 0 | gap centre P18 = 57 %, type 1 |
| code14-p18-gap-57-single | match | 22/22 | 4/4 | 0 | gap centre P18 = 57 %, type 0 |
| code14-p19-gap-size-2 | match | 22/22 | 4/4 | 0 | gap P18 = 50 % with size P19 = 2 steps |
| code14-p19-gap-size-6 | match | 22/22 | 4/4 | 0 | gap P18 = 50 % with size P19 = 6 steps |
| code14-p2-from-staff-2 | match | 21/21 | 4/4 | 0 | barline from staff 2 spanning 2 |
| code14-p2-top-staff | match | 21/21 | 4/4 | 0 | barline on staff 4 spanning 999 |
| code14-p25-layer | match | 21/21 | 4/4 | 0 | layer number P25 = 1 |
| code14-p26-grey-0.5 | match | 21/21 | 4/4 | 0 | P26 = 0.5 |
| code14-p26-red | match | 21/21 | 4/4 | 0 | P26 = 990000 |
| code14-p26-red-repeat | match | 32/32 | 4/4 | 0 | repeat bar P5 = 5 in red |
| code14-p3-pos-0 | match | 21/21 | 4/4 | 0 | horizontal position P3 = 0 |
| code14-p3-pos-10.5 | match | 21/21 | 4/4 | 0 | horizontal position P3 = 10.5 |
| code14-p3-pos-200 | match | 21/21 | 4/4 | 0 | horizontal position P3 = 200 |
| code14-p4-span-0 | match | 21/21 | 4/4 | 0 | P4 = 0 staves spanned |
| code14-p4-span-1 | match | 21/21 | 4/4 | 0 | P4 = 1 staves spanned |
| code14-p4-span-2 | match | 21/21 | 4/4 | 0 | P4 = 2 staves spanned |
| code14-p4-span-3 | match | 21/21 | 4/4 | 0 | P4 = 3 staves spanned |
| code14-p4-span-4 | match | 21/21 | 4/4 | 0 | P4 = 4 staves spanned |
| code14-p4-span-999 | match | 21/21 | 4/4 | 0 | P4 = 999 staves spanned |
| code14-p4-span-m1 | match | 35/35 | 4/4 | 0 | P4 = -1 staves spanned |
| code14-p4-span-m2 | match | 65/65 | 4/4 | 0 | P4 = -2 staves spanned |
| code14-p5-brace | match | 21/21 | 4/4 | 0 | type P5 = 8 (brace) |
| code14-p5-brace-span-1 | match | 21/21 | 4/4 | 0 | type P5 = 8 on one staff |
| code14-p5-brace-span-4 | match | 21/21 | 4/4 | 0 | type P5 = 8 spanning all four staves |
| code14-p5-bracket | match | 24/24 | 4/4 | 0 | type P5 = 9 (bracket) |
| code14-p5-bracket-span-1 | match | 24/24 | 4/4 | 0 | type P5 = 9 on one staff |
| code14-p5-bracket-span-4 | match | 24/24 | 4/4 | 0 | type P5 = 9 spanning all four staves |
| code14-p5-dashed | match | 47/47 | 4/4 | 0 | type P5 = 7 (dashed) |
| code14-p5-dashed-span-1 | match | 29/29 | 4/4 | 0 | type P5 = 7 on one staff |
| code14-p5-double | match | 22/22 | 4/4 | 0 | type P5 = 1 (double) |
| code14-p5-double-span-1 | match | 22/22 | 4/4 | 0 | type P5 = 1 on one staff |
| code14-p5-final | match | 23/23 | 4/4 | 0 | type P5 = 2 (final) |
| code14-p5-final-span-4 | match | 23/23 | 4/4 | 0 | type P5 = 2 spanning all four staves |
| code14-p5-negative | match | 22/22 | 4/4 | 0 | type P5 = -1 (negative) |
| code14-p5-repeat-both | match | 32/32 | 4/4 | 0 | type P5 = 5 (repeat-both) |
| code14-p5-repeat-both-span-4 | match | 40/40 | 4/4 | 0 | type P5 = 5 spanning all four staves |
| code14-p5-repeat-heavy | match | 32/32 | 4/4 | 0 | type P5 = 6 (repeat-heavy) |
| code14-p5-repeat-left | match | 27/27 | 4/4 | 0 | type P5 = 3 (repeat-left) |
| code14-p5-repeat-left-span-1 | match | 25/25 | 4/4 | 0 | type P5 = 3 on one staff |
| code14-p5-repeat-right | match | 27/27 | 4/4 | 0 | type P5 = 4 (repeat-right) |
| code14-p5-single | match | 21/21 | 4/4 | 0 | type P5 = 0 (single) |
| code14-p5-square-bracket | match | 21/21 | 4/4 | 0 | type P5 = 10 (square-bracket) |
| code14-p5-square-bracket-span-4 | match | 21/21 | 4/4 | 0 | type P5 = 10 spanning all four staves |
| code14-p5-two-bar-repeat | match | 25/25 | 4/4 | 0 | type P5 = -44 (two-bar-repeat) |
| code14-p5-type-11 | match | 53/53 | 4/4 | 0 | type P5 = 11 (type-11) |
| code14-p5-type-14 | match | 53/53 | 4/4 | 0 | type P5 = 14 (type-14) |
| code14-p6-thick-1-brace | match | 21/21 | 4/4 | 0 | thickness P6 = 1, type 8 |
| code14-p6-thick-1-final | match | 23/23 | 4/4 | 0 | thickness P6 = 1, type 2 |
| code14-p6-thick-1-single | match | 22/22 | 4/4 | 0 | thickness P6 = 1, type 0 |
| code14-p6-thick-3-brace | match | 21/21 | 4/4 | 0 | thickness P6 = 3, type 8 |
| code14-p6-thick-3-final | match | 23/23 | 4/4 | 0 | thickness P6 = 3, type 2 |
| code14-p6-thick-3-single | match | 22/22 | 4/4 | 0 | thickness P6 = 3, type 0 |
| code14-p7-displace-2-brace | match | 21/21 | 4/4 | 0 | horizontal displacement P7 = 2, type 8 |
| code14-p7-displace-2-bracket | match | 24/24 | 4/4 | 0 | horizontal displacement P7 = 2, type 9 |
| code14-p7-displace-2-single | match | 21/21 | 4/4 | 0 | horizontal displacement P7 = 2, type 0 |
| code14-p7-displace-m3-brace | match | 21/21 | 4/4 | 0 | horizontal displacement P7 = -3, type 8 |
| code14-p7-displace-m3-bracket | match | 24/24 | 4/4 | 0 | horizontal displacement P7 = -3, type 9 |
| code14-p7-displace-m3-single | match | 21/21 | 4/4 | 0 | horizontal displacement P7 = -3, type 0 |
| code14-p8-dash-0.5 | match | 53/53 | 4/4 | 0 | dashed bar, dash size P8 = 0.5 |
| code14-p8-dash-2 | match | 41/41 | 4/4 | 0 | dashed bar, dash size P8 = 2 |
| code14-p8-partial-bracket-1 | match | 23/23 | 4/4 | 0 | bracket with P8 = 1 (partial bracket) |
| code14-p8-partial-bracket-2 | match | 23/23 | 4/4 | 0 | bracket with P8 = 2 (partial bracket) |
| code14-p8-partial-bracket-m1 | match | 24/24 | 4/4 | 0 | bracket with P8 = -1 (partial bracket) |
| code14-p8-two-bar-number | match | 26/26 | 4/4 | 0 | two-bar repeat with number P8 = 2 |
| code14-p9-space-0.5 | match | 74/74 | 4/4 | 0 | dashed bar, space P9 = 0.5 |
| code14-p9-space-2 | match | 47/47 | 4/4 | 0 | dashed bar, space P9 = 2 |
| code14-sizes-repeat | match | 22/22 | 2/2 | 0 | repeat bar across staves of size 0.7 and 1 |
| code14-sizes-span-3 | match | 18/18 | 3/3 | 0 | staves of size 1, 0.7, 1.2; final bar spanning 3 |
| code14-staff-offset | match | 11/11 | 2/2 | 0 | barline spanning staves moved by P4 |
| code14-system | match | 30/30 | 4/4 | 0 | system: brace, bracket, start bar, middle and final bars |
| code15-default | match | 7/7 | 1/1 | 0 | logo-col.eps at size 0.2: bounding box with diagonals |
| code15-noname | match | 7/7 | 1/1 | 0 | no file name in P14… |
| code15-p11-unread | match | 6/6 | 1/1 | 0 | P11 0 (bounding box not read): placeholder square of P5 scale steps |
| code15-p11-unread-default | match | 6/6 | 1/1 | 0 | P11 0, P5 0: placeholder of 3 scale steps |
| code15-p11-unread-p6 | match | 6/6 | 1/1 | 0 | P11 0, P5 2, P6 1 |
| code15-p12-rotation-0.5 | match | 7/7 | 1/1 | 0 | P12 0.5 |
| code15-p12-rotation-30 | match | 7/7 | 1/1 | 0 | P12 30 |
| code15-p12-rotation-m135 | match | 7/7 | 1/1 | 0 | P12 -135 |
| code15-p26-grey | match | 7/7 | 1/1 | 0 | P26 0.5 |
| code15-p4-level | match | 7/7 | 1/1 | 0 | P4 -6.4, P3 55.3 |
| code15-p5-size-0 | match | 7/7 | 1/1 | 0 | P5 0 |
| code15-p5-size-0.07 | match | 7/7 | 1/1 | 0 | P5 0.07 |
| code15-p5-size-m0.2 | match | 7/7 | 1/1 | 0 | P5 -0.2 |
| code15-p6-vsize-0.5 | match | 7/7 | 1/1 | 0 | P5 0.2, P6 0.5 |
| code15-p6-vsize-m0.1 | match | 7/7 | 1/1 | 0 | P5 0.2, P6 -0.1 |
| code15-recto | match | 7/7 | 3/3 | 0 | on the recto staff 201 |
| code15-size-0.75 | match | 7/7 | 1/1 | 0 | on a size 0.75 staff |
| code15-size-0.75-unread | match | 6/6 | 1/1 | 0 | placeholder on a size 0.75 staff |
| code15-staff-2 | match | 12/12 | 2/2 | 0 | on staff 2 |
| code15-two | match | 9/9 | 1/1 | 0 | two EPS items after a staff |
| code16-colour-then-plain | match | 5/5 | 22/22 | 0 | a coloured text item before a plain one |
| code16-default | match | 5/5 | 16/16 | 0 | Times (_00) at size 1 |
| code16-font-00 | match | 5/5 | 16/16 | 0 | font _00 |
| code16-font-01 | match | 5/5 | 16/16 | 0 | font _01 |
| code16-font-02 | match | 5/5 | 16/16 | 0 | font _02 |
| code16-font-03 | match | 5/5 | 16/16 | 0 | font _03 |
| code16-font-04 | match | 5/5 | 16/16 | 0 | font _04 |
| code16-font-05 | match | 5/5 | 16/16 | 0 | font _05 |
| code16-font-06 | match | 5/5 | 16/16 | 0 | font _06 |
| code16-font-07 | match | 5/5 | 16/16 | 0 | font _07 |
| code16-font-08 | match | 5/5 | 16/16 | 0 | font _08 |
| code16-font-09 | match | 5/5 | 16/16 | 0 | font _09 |
| code16-font-10 | match | 5/5 | 16/16 | 0 | font _10 |
| code16-font-11 | match | 5/5 | 16/16 | 0 | font _11 |
| code16-font-12 | match | 5/5 | 16/16 | 0 | font _12 |
| code16-font-13 | match | 5/5 | 16/16 | 0 | font _13 |
| code16-font-14 | match | 5/5 | 16/16 | 0 | font _14 |
| code16-font-15 | match | 5/5 | 16/16 | 0 | font _15 |
| code16-font-16 | match | 5/5 | 16/16 | 0 | font _16 |
| code16-font-17 | match | 5/5 | 16/16 | 0 | font _17 |
| code16-font-18 | match | 5/5 | 16/16 | 0 | font _18 |
| code16-font-19 | match | 5/5 | 16/16 | 0 | font _19 |
| code16-font-20 | match | 5/5 | 16/16 | 0 | font _20 |
| code16-font-21 | match | 5/5 | 16/16 | 0 | font _21 |
| code16-font-22 | match | 5/5 | 16/16 | 0 | font _22 |
| code16-font-23 | match | 5/5 | 16/16 | 0 | font _23 |
| code16-font-24 | match | 5/5 | 16/16 | 0 | font _24 |
| code16-font-25 | match | 5/5 | 16/16 | 0 | font _25 |
| code16-font-26 | match | 5/5 | 16/16 | 0 | font _26 |
| code16-font-27 | match | 5/5 | 16/16 | 0 | font _27 |
| code16-font-28 | match | 5/5 | 16/16 | 0 | font _28 |
| code16-font-29 | match | 5/5 | 16/16 | 0 | font _29 |
| code16-font-30 | match | 5/5 | 16/16 | 0 | font _30 |
| code16-font-31 | match | 5/5 | 16/16 | 0 | font _31 |
| code16-font-32 | match | 5/5 | 16/16 | 0 | font _32 |
| code16-font-33 | match | 5/5 | 16/16 | 0 | font _33 |
| code16-font-34 | match | 5/5 | 16/16 | 0 | font _34 |
| code16-font-35 | match | 5/5 | 19/19 | 0 | font _35 (WinScore extension) |
| code16-font-40 | match | 5/5 | 19/19 | 0 | font _40 (WinScore extension) |
| code16-font-45 | match | 5/5 | 19/19 | 0 | font _45 (WinScore extension) |
| code16-font-50 | match | 5/5 | 19/19 | 0 | font _50 (WinScore extension) |
| code16-font-51 | match | 5/5 | 19/19 | 0 | font _51 (WinScore extension) |
| code16-font-55 | match | 5/5 | 19/19 | 0 | font _55 (WinScore extension) |
| code16-font-57 | match | 5/5 | 19/19 | 0 | font _57 (WinScore extension) |
| code16-font-60 | match | 5/5 | 19/19 | 0 | font _60 (WinScore extension) |
| code16-font-61 | match | 5/5 | 19/19 | 0 | font _61 (WinScore extension) |
| code16-font-63 | match | 5/5 | 19/19 | 0 | font _63 (WinScore extension) |
| code16-font-90 | match | 5/5 | 19/19 | 0 | font _90 |
| code16-font-91 | match | 5/5 | 19/19 | 0 | font _91 |
| code16-font-92 | match | 5/5 | 19/19 | 0 | font _92 |
| code16-font-93 | match | 5/5 | 19/19 | 0 | font _93 |
| code16-font-94 | match | 13/13 | 1/1 | 0 | meter font _94 |
| code16-font-98 | match | 5/5 | 19/19 | 0 | font _98 |
| code16-font-99-comment | match | 5/5 | 10/10 | 0 | non-printing comment _99% |
| code16-font-after-ending | match | 7/7 | 13/13 | 0 | plain text after _05 text and a first ending (code 5) |
| code16-font-after-meter | match | 7/7 | 12/12 | 0 | plain text after _02 text and a 3/4 meter (font 94, loads none) |
| code16-font-after-meter-p13 | match | 5/5 | 14/14 | 0 | plain text after _02 text and a meter in font P13 = 2 (Helvetica) |
| code16-font-after-number | match | 5/5 | 13/13 | 0 | plain text after _02 text and a code-10 number (font 1000) |
| code16-font-after-ottava | match | 5/5 | 15/15 | 0 | plain text after _05 text and an 8va (code 7) |
| code16-font-after-staff | match | 5/5 | 6/6 | 0 | text without a font code after a staff (Helvetica-Narrow) |
| code16-font-after-term | match | 5/5 | 17/17 | 0 | plain text after _05 text and a CODE9.DAT term (code 9, 3004) |
| code16-font-after-text | match | 5/5 | 12/12 | 0 | text without a font code after _02 text |
| code16-font-after-text-symbol | match | 5/5 | 17/17 | 0 | plain text after _05 text and pizz. (code 9, symbol 66) |
| code16-font-after-tuplet | match | 6/6 | 13/13 | 0 | plain text after _05 text and a beam with tuplet number 3 (code 6) |
| code16-font-after-tuplet-bracket | match | 7/7 | 13/13 | 0 | plain text after _05 text and a tuplet bracket with 3 (code 5) |
| code16-font-after-two-bar-repeat | match | 11/11 | 12/12 | 0 | plain text after _05 text and a two-bar repeat with number 2 (code 14) |
| code16-font-no-staff | match | 0/0 | 11/11 | 0 | text without a font code, no staff |
| code16-font-wraps | match | 5/5 | 12/12 | 0 | text without a font code before _05 text |
| code16-fonts-mixed | match | 5/5 | 24/24 | 0 | font changes inside the string |
| code16-latin1 | match | 5/5 | 12/12 | 0 | Latin-1 characters |
| code16-lines | match | 5/5 | 16/16 | 0 | three lines of text |
| code16-long | match | 5/5 | 109/109 | 0 | a long line |
| code16-one-char | match | 5/5 | 2/2 | 0 | a single character |
| code16-outline | match | 5/5 | 8/8 | 0 | outline font __05 |
| code16-p10-space-0.5 | match | 5/5 | 12/12 | 0 | space size P10 = 0.5 |
| code16-p10-space-2 | match | 5/5 | 12/12 | 0 | space size P10 = 2 |
| code16-p10-space-m0.5 | match | 5/5 | 12/12 | 0 | space size P10 = -0.5 |
| code16-p11-displace-10 | match | 5/5 | 16/16 | 0 | horizontal displacement P11 = 10 |
| code16-p11-displace-m5 | match | 5/5 | 16/16 | 0 | horizontal displacement P11 = -5 |
| code16-p14-colour-red | match | 5/5 | 16/16 | 0 | P14 = -1, P16 = 990000 |
| code16-p14-grey | match | 5/5 | 16/16 | 0 | P14 = -1, P16 = 0.5 |
| code16-p14-layer | match | 5/5 | 17/17 | 0 | P14 = -1, layer P15 = 1 |
| code16-p3-fraction | match | 5/5 | 16/16 | 0 | P3 = 55.37 |
| code16-p3-negative | match | 5/5 | 16/16 | 0 | P3 = -10 |
| code16-p3-right | match | 5/5 | 16/16 | 0 | near the right margin, P3 = 180 |
| code16-p4-fraction | match | 5/5 | 16/16 | 0 | P4 = 13.5 |
| code16-p4-low | match | 5/5 | 16/16 | 0 | below the staff, P4 = -6 |
| code16-p5-spacing-0.5 | match | 5/5 | 12/12 | 0 | character space factor P5 = 0.5 |
| code16-p5-spacing-0.8 | match | 5/5 | 16/16 | 0 | character space factor P5 = 0.8 |
| code16-p5-spacing-1.3 | match | 5/5 | 16/16 | 0 | character space factor P5 = 1.3 |
| code16-p6-parts-101 | match | 5/5 | 16/16 | 0 | part-extraction flag in P6 = 101 |
| code16-p6-parts-201 | match | 5/5 | 16/16 | 0 | part-extraction flag in P6 = 201 |
| code16-p6-parts-301 | match | 5/5 | 16/16 | 0 | part-extraction flag in P6 = 301 |
| code16-p6-size-0 | match | 5/5 | 16/16 | 0 | size P6 = 0 |
| code16-p6-size-0.5 | match | 5/5 | 16/16 | 0 | size P6 = 0.5 |
| code16-p6-size-2 | match | 5/5 | 16/16 | 0 | size P6 = 2 |
| code16-p7-vertical-2 | match | 5/5 | 16/16 | 0 | P6 = 1, vertical size P7 = 2 |
| code16-p7-vertical-half | match | 5/5 | 16/16 | 0 | P6 = 2, vertical size P7 = 0.5 |
| code16-p8-font-1000 | match | 5/5 | 16/16 | 0 | font override P8 = 1000 |
| code16-p8-font-1004 | match | 5/5 | 16/16 | 0 | font override P8 = 1004 |
| code16-p8-font-1004-tab | match | 5/5 | 3/3 | 0 | font override P8 = 1004 with a font code and a tab |
| code16-p8-font-1034 | match | 5/5 | 16/16 | 0 | font override P8 = 1034 |
| code16-p8-font-90 | match | 5/5 | 16/16 | 0 | font override P8 = 90 |
| code16-p8-font-91 | match | 5/5 | 16/16 | 0 | font override P8 = 91 |
| code16-p8-font-92 | match | 5/5 | 16/16 | 0 | font override P8 = 92 |
| code16-p8-font-93 | match | 5/5 | 16/16 | 0 | font override P8 = 93 |
| code16-p8-font-94 | match | 23/23 | 1/1 | 0 | font override P8 = 94 |
| code16-p8-font-98 | match | 5/5 | 16/16 | 0 | font override P8 = 98 |
| code16-p8-outline-1105 | match | 5/5 | 16/16 | 0 | outline font override P8 = 1105 |
| code16-p8-outline-193 | match | 5/5 | 16/16 | 0 | outline font override P8 = 193 |
| code16-p9-rotate-180 | match | 5/5 | 16/16 | 1 | rotation P9 = 180 degrees |
| code16-p9-rotate-180-symbols | match | 13/13 | 12/12 | 1 | rotation P9 = 180 with [ ] symbols |
| code16-p9-rotate-30 | match | 5/5 | 16/16 | 0 | rotation P9 = 30 degrees |
| code16-p9-rotate-30-large | match | 5/5 | 16/16 | 0 | rotation P9 = 30 at size 2 |
| code16-p9-rotate-30-p11 | match | 13/13 | 4/4 | 0 | symbols, rotation P9 = 30 and shift P11 = 5 |
| code16-p9-rotate-90 | match | 5/5 | 16/16 | 0 | rotation P9 = 90 degrees |
| code16-p9-rotate-90-font-94 | match | 9/9 | 1/1 | 0 | meter font P8 = 94 rotated by P9 = 90 |
| code16-p9-rotate-m45 | match | 5/5 | 16/16 | 0 | rotation P9 = -45 degrees |
| code16-punctuation | match | 13/13 | 13/13 | 0 | punctuation and digits |
| code16-spaces | match | 5/5 | 12/12 | 0 | words separated by spaces |
| code16-special-accents | match | 5/5 | 13/13 | 0 | ~n, ^e, %%o, ##c, <<e, >>a |
| code16-special-ascii | match | 5/5 | 16/16 | 0 | # $ % & < > @ |
| code16-special-braces | match | 19/19 | 5/5 | 0 | { } and / (symbols) |
| code16-special-brackets | match | 13/13 | 12/12 | 0 | [ and ] (note symbols in music text) |
| code16-special-copyright | match | 5/5 | 6/6 | 0 | ?c escape |
| code16-special-escapes | match | 5/5 | 9/9 | 0 | ?A ?E ?a ?s ?t !a !A !f |
| code16-special-octal | match | 5/5 | 4/4 | 0 | octal escape \\351 |
| code16-special-slash | match | 5/5 | 10/10 | 0 | backslash for a printable slash |
| code16-special-umlaut | match | 5/5 | 13/13 | 0 | %% escapes |
| code16-staff-2 | match | 10/10 | 17/17 | 0 | text on staff 2 |
| code16-staff-200 | match | 10/10 | 19/19 | 0 | text on staff 200 (verso for text, recto for shapes) |
| code16-staff-201-rotate-symbols | match | 18/18 | 7/7 | 0 | rotated text with symbols on recto staff 201 |
| code16-staff-large | match | 5/5 | 16/16 | 0 | text on a staff of size 1.5 |
| code16-staff-recto | match | 10/10 | 19/19 | 0 | text on recto staff 201 |
| code16-staff-small | match | 5/5 | 16/16 | 0 | text on a staff of size 0.7 |
| code16-tab | match | 5/5 | 10/10 | 0 | tab stops ~n~ |
| code16-tabs | match | 5/5 | 20/20 | 0 | several tab stops |
| code17-irregular-3 | match | 16/16 | 1/1 | 0 | irregular: flat at 7, sharp at 9, natural at 4 |
| code17-irregular-7 | match | 30/30 | 1/1 | 0 | irregular: seven accidentals through P16 |
| code17-irregular-cue | match | 12/12 | 1/1 | 0 | irregular with cue size |
| code17-irregular-gap | match | 13/13 | 1/1 | 0 | irregular: P8, P9, then P10 = 0 stops |
| code17-p10-pixels | match | 65/65 | 1/1 | 0 | P10 = 1 |
| code17-p15-offset-0.5 | match | 13/13 | 1/1 | 0 | offset P15 = 0.5 |
| code17-p15-offset-m1 | match | 13/13 | 1/1 | 0 | offset P15 = -1 |
| code17-p26-grey | match | 17/17 | 1/1 | 0 | P26 = 0.5 |
| code17-p4-offset | match | 13/13 | 1/1 | 0 | P4 = 2 |
| code17-p5-0 | match | 9/9 | 1/1 | 0 | P5 = 0 |
| code17-p5-1 | match | 9/9 | 1/1 | 0 | P5 = 1 |
| code17-p5-107 | match | 33/33 | 1/1 | 0 | P5 = 107 |
| code17-p5-3 | match | 17/17 | 1/1 | 0 | P5 = 3 |
| code17-p5-7-alto | match | 33/33 | 1/1 | 0 | P5 = 7, clef 2 |
| code17-p5-7-bass | match | 33/33 | 1/1 | 0 | P5 = 7, clef 1 |
| code17-p5-7-tenor | match | 33/33 | 1/1 | 0 | P5 = 7, clef 3 |
| code17-p5-7-treble | match | 33/33 | 1/1 | 0 | P5 = 7, clef 0 |
| code17-p5-8 | match | 37/37 | 1/1 | 0 | P5 = 8 |
| code17-p5-m1 | match | 8/8 | 1/1 | 0 | P5 = -1 |
| code17-p5-m103 | match | 17/17 | 1/1 | 0 | P5 = -103 |
| code17-p5-m4 | match | 17/17 | 1/1 | 0 | P5 = -4 |
| code17-p5-m7-alto | match | 26/26 | 1/1 | 0 | P5 = -7, clef 2 |
| code17-p5-m7-bass | match | 26/26 | 1/1 | 0 | P5 = -7, clef 1 |
| code17-p5-m7-tenor | match | 26/26 | 1/1 | 0 | P5 = -7, clef 3 |
| code17-p5-m7-treble | match | 26/26 | 1/1 | 0 | P5 = -7, clef 0 |
| code17-p5-m9 | match | 32/32 | 1/1 | 0 | P5 = -9 |
| code17-p6-cue-4 | match | 21/21 | 1/1 | 0 | cue size P6 = 100, P5 = 4 |
| code17-p6-cue-bass | match | 17/17 | 1/1 | 0 | cue size P6 = 101, P5 = 3 |
| code17-p6-cue-m4 | match | 17/17 | 1/1 | 0 | cue size P6 = 100, P5 = -4 |
| code17-p6-out-of-range | match | 17/17 | 1/1 | 0 | P6 = 5 (read as treble) |
| code17-p7-space-0.8 | match | 21/21 | 1/1 | 0 | spacing P7 = 0.8 |
| code17-p7-space-1.2 | match | 21/21 | 1/1 | 0 | spacing P7 = 1.2 |
| code17-p7-space-cue | match | 14/14 | 1/1 | 0 | spacing P7 = 1.5 with cue size |
| code17-p7-space-m1 | match | 21/21 | 1/1 | 0 | spacing P7 = -1 |
| code17-staff-recto-201 | match | 17/17 | 3/3 | 0 | recto staff 201, P5 = 3 |
| code17-staff-size-0.7-tenor | match | 33/33 | 1/1 | 0 | staff size 0.7, tenor sharps |
| code17-staff-size-0.75-5 | match | 25/25 | 1/1 | 0 | staff size 0.75, P5 = 5 |
| code17-staff-size-0.75-m6 | match | 23/23 | 1/1 | 0 | staff size 0.75, P5 = -6 |
| code17-staff-size-1.4-5 | match | 25/25 | 1/1 | 0 | staff size 1.4, P5 = 5 |
| code17-staff-size-1.4-m6 | match | 23/23 | 1/1 | 0 | staff size 1.4, P5 = -6 |
| code17-staff-size-m1-5 | match | 25/25 | 1/1 | 0 | staff size -1, P5 = 5 |
| code17-staff-size-m1-m6 | match | 23/23 | 1/1 | 0 | staff size -1, P5 = -6 |
| code18-p10-plus-1 | match | 11/11 | 1/1 | 0 | P10 = 1 |
| code18-p10-plus-m0.5 | match | 11/11 | 1/1 | 0 | P10 = -0.5 |
| code18-p11-space-1 | match | 11/11 | 1/1 | 0 | P11 = 1 |
| code18-p11-space-m1 | match | 11/11 | 1/1 | 0 | P11 = -1 |
| code18-p12-no-plus | match | 9/9 | 1/1 | 0 | P12 = 1 |
| code18-p13-font-1 | match | 5/5 | 3/3 | 0 | font P13 = 1 |
| code18-p13-font-2 | match | 5/5 | 3/3 | 0 | font P13 = 2 |
| code18-p13-font-9 | match | 5/5 | 3/3 | 0 | font P13 = 9 |
| code18-p15-offset-0.5 | match | 7/7 | 1/1 | 0 | offset P15 = 0.5 |
| code18-p15-offset-m1 | match | 7/7 | 1/1 | 0 | offset P15 = -1 |
| code18-p16-pixels | match | 7/7 | 1/1 | 0 | P16 = 1, 3/4 |
| code18-p16-pixels-symbol | match | 25/25 | 1/1 | 0 | P16 = 1, common time |
| code18-p20-spread-1.15 | match | 9/9 | 1/1 | 0 | spread P20 = 1.15, 12/16 |
| code18-p20-spread-2 | match | 9/9 | 1/1 | 0 | spread P20 = 2, 12/16 |
| code18-p26-grey | match | 7/7 | 1/1 | 0 | P26 = 0.5 |
| code18-p26-grey-symbol | match | 9/9 | 1/1 | 0 | P26 = 0.5, common time |
| code18-p4-offset | match | 7/7 | 1/1 | 0 | P4 = 3 |
| code18-p5-only-3 | match | 6/6 | 1/1 | 0 | P5 = 3, P6 = 0 |
| code18-p5-p6-1-1 | match | 7/7 | 1/1 | 0 | 1/1 |
| code18-p5-p6-12-8 | match | 8/8 | 1/1 | 0 | 12/8 |
| code18-p5-p6-2-2 | match | 7/7 | 1/1 | 0 | 2/2 |
| code18-p5-p6-3-4 | match | 7/7 | 1/1 | 0 | 3/4 |
| code18-p5-p6-4-4 | match | 7/7 | 1/1 | 0 | 4/4 |
| code18-p5-p6-5-16 | match | 8/8 | 1/1 | 0 | 5/16 |
| code18-p5-p6-6-8 | match | 7/7 | 1/1 | 0 | 6/8 |
| code18-p5-symbol-91 | match | 7/7 | 1/1 | 0 | P5 = 91 (symbol) |
| code18-p5-symbol-95 | match | 6/6 | 1/1 | 0 | P5 = 95 (symbol) |
| code18-p5-symbol-98 | match | 10/10 | 1/1 | 0 | P5 = 98 (symbol) |
| code18-p5-symbol-99 | match | 9/9 | 1/1 | 0 | P5 = 99 (symbol) |
| code18-p5-zero-p6-3 | match | 6/6 | 1/1 | 0 | P5 = 0, P6 = 3: single number |
| code18-p7-size-0.5 | match | 7/7 | 1/1 | 0 | size P7 = 0.5, 3/4 |
| code18-p7-size-0.5-symbol | match | 9/9 | 1/1 | 0 | size P7 = 0.5, common time |
| code18-p7-size-1.5 | match | 7/7 | 1/1 | 0 | size P7 = 1.5, 3/4 |
| code18-p7-size-2 | match | 7/7 | 1/1 | 0 | size P7 = 2, 3/4 |
| code18-p7-size-2-symbol | match | 9/9 | 1/1 | 0 | size P7 = 2, common time |
| code18-p8-p9-12-16 | match | 13/13 | 1/1 | 0 | 3/4 + 12/16 |
| code18-p8-p9-2-8 | match | 11/11 | 1/1 | 0 | 3/4 + 2/8 |
| code18-p8-p9-3-0 | match | 10/10 | 1/1 | 0 | 3/4 + 3/0 |
| code18-p8-p9-4-3-over-4 | match | 10/10 | 1/1 | 0 | 4+3/4 (P9 = 0) |
| code18-p8-p9-wide-first | match | 12/12 | 1/1 | 0 | 12/8 + 3/4 |
| code18-staff-recto-201 | match | 7/7 | 3/3 | 0 | recto staff 201, 6/8 |
| code18-staff-size-0.75-3-4 | match | 7/7 | 1/1 | 0 | staff size 0.75, 3-4 |
| code18-staff-size-0.75-common | match | 9/9 | 1/1 | 0 | staff size 0.75, common |
| code18-staff-size-1.4-3-4 | match | 7/7 | 1/1 | 0 | staff size 1.4, 3-4 |
| code18-staff-size-1.4-common | match | 9/9 | 1/1 | 0 | staff size 1.4, common |
| code18-staff-size-m1-3-4 | match | 7/7 | 1/1 | 0 | staff size -1, 3-4 |
| code18-staff-size-m1-common | match | 9/9 | 1/1 | 0 | staff size -1, common |
| code99-beam-double | match | 15/15 | 1/1 | 0 | four sixteenths, stems up, two beams |
| code99-beam-down | match | 14/14 | 1/1 | 0 | four eighths, stems down, one beam |
| code99-beam-partial | match | 12/12 | 1/1 | 0 | dotted eighth and sixteenth: full beam plus a partial |
| code99-beam-triplet | match | 12/12 | 2/2 | 0 | three eighths with a 3 over the beam |
| code99-beam-up | match | 14/14 | 1/1 | 0 | four eighths, stems up, one beam |
| code99-chord | match | 10/10 | 1/1 | 0 | C major triad with one stem |
| code99-chord-down | match | 19/19 | 1/1 | 0 | chord with stem down and accidentals |
| code99-chord-second | match | 9/9 | 1/1 | 0 | chord with a second: the upper note displaced right |
| code99-chord-tie | match | 13/13 | 1/1 | 0 | two tied chords |
| code99-dynamics | match | 27/27 | 8/8 | 0 | melody with p, hairpin, tempo text and final bar |
| code99-grace | match | 13/13 | 1/1 | 0 | grace note with slashed stem slurred to its main note |
| code99-measure-bass | match | 34/34 | 1/1 | 0 | bass clef, three flats, 6/8, notes with ledger lines and a rest |
| code99-measure-treble | match | 27/27 | 1/1 | 0 | treble clef, two sharps, 3/4, three quarter notes, barline |
| code99-rests | match | 20/20 | 1/1 | 0 | notes and rests in one measure, centred whole rest in the next |
| code99-slur | match | 14/14 | 1/1 | 0 | slur over four quarter notes |
| code99-system | match | 28/28 | 2/2 | 0 | two staves with brace, notes on both, barlines |
| code99-tie | match | 10/10 | 1/1 | 0 | two half notes tied |
| corpus-chopin2804 | match | 1603/1603 | 97/97 | 0 | corpus/free/chopin2804.pmx.txt (PMX converted) |
| corpus-chopin2806 | match | 1426/1426 | 100/100 | 0 | corpus/free/chopin2806.pmx.txt (PMX converted) |
| corpus-mus2pmx-ex1 | match | 748/748 | 355/355 | 0 | corpus/free/mus2pmx-ex1.mus |
| fuzz-code01-p11-p14-5b0460 | match | 8/8 | 1/1 | 0 | fuzz, impl-notes: distorted; same structure, off by up to 337 after aligning |
| fuzz-code01-p6-p10-e9c174 | match | 5/5 | 2/2 | 0 | fuzz, impl-notes: text offset; "2" shifted by (15000, 0) |
| fuzz-code02-p5-p15-275998 | match | 9/9 | 1/1 | 0 | fuzz, impl-notes: distorted; same structure, off by up to 342 after aligning |
| fuzz-code02-p6-p8-c48746 | match | 9/9 | 5/5 | 0 | fuzz, impl-notes: text style; "G": Times 813.5/335.6 #000000 w400 esc 0 instead of Times 813.5/335.6 #999999 w400 esc 0 |
| fuzz-code02-p8-p15-37bcaa | match | 9/9 | 5/5 | 0 | fuzz, impl-notes: text style; "G": Times 813.5/335.6 #000000 w400 esc 0 instead of Times 650.8/268.5 #000000 w400 esc 0 |
| fuzz-code02-p8-p17-c92312 | match | 9/9 | 5/5 | 0 | fuzz, impl-notes: text offset; "G" shifted by (0, -3150) |
| fuzz-code03-p5-p10-e6050f | match | 10/10 | 3/3 | 0 | fuzz, impl-symbols: extra; fill #000000, 1 path(s), 62 points from (15678, 4037) |
| fuzz-code03-p5-p10-e66eab | match | 10/10 | 2/2 | 0 | fuzz, impl-symbols: extra; fill #000000, 1 path(s), 62 points from (11425, 5087) |
| fuzz-code05-p11-p16-2701e0 | differs | 8/8 | 1/3 +2 | 0 | fuzz, impl-beams: text offset; "1" shifted by (98, 336) |
| fuzz-code05-p11-p16-cf241b | differs | 8/8 | 1/2 +1 | 0 | fuzz, impl-beams: text offset; "3" shifted by (211, 279) |
| fuzz-code06-p8-p17-f76ce8 | differs | 6/6 | 2/3 | 0 | fuzz, impl-beams: text missing; "?" in Times 678.0/279.7 at (15334, 1369) |
| fuzz-code12-p5-ffbe10 | match | 17/17 | 1/1 | 0 | fuzz, impl-symbols: absent; stroke #000000, 1 path(s), 2 points from (22061, 3648) |
| fuzz-code12-p5-p11-cbf4b8 | match | 7/7 | 1/1 | 0 | fuzz, impl-symbols: absent; stroke #000000, 1 path(s), 181 points from (5333, 2511) |
| fuzz-code12-p5-p11-ec0e0d | match | 7/7 | 1/1 | 0 | fuzz, impl-symbols: absent; stroke #000000, 1 path(s), 91 points from (7810, 3823) |
| fuzz-code16-p8-p9-b70d9e | match | 19/19 | 1/1 | 0 | fuzz, impl-text: offset; shifted by (688, 688), residual 0 |
| fuzz-code16-p9-862d87 | match | 13/13 | 12/12 | 1 | fuzz, impl-text: offset; shifted by (5576, 0), residual 0 |
| layout-li-system | match | 55/55 | 2/2 | 0 | LI on a two-staff system (the engine gives the same result as LJ here) |
| layout-lj-system | match | 55/55 | 2/2 | 0 | LJ on a two-staff system (lowest staff 1, two staves) |
| layout-lja-single | match | 24/24 | 1/1 | 0 | LJA on one staff with two measures |
| sample-000 | match | 550/550 | 175/175 | 0 | WinScore sample 000.mus |
| sample-carmen | match | 3300/3300 | 331/331 | 0 | WinScore sample carmen.mus |
| sample-mozart | match | 768/768 | 136/136 | 0 | WinScore sample mozart.mus |
| sample-newlib | match | 182/182 | 219/219 | 0 | SCORE 4 sample NEWLIB.MUS |
| sample-newline | match | 165/165 | 960/960 | 0 | SCORE 4 sample NEWLINE.MUS |
| sample-sonlcs | match | 2987/2987 | 322/322 | 0 | WinScore sample sonlcs.mus |
