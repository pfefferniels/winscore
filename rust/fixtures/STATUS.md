# Fixture status

Written by `score-compare` (crate `score-testkit`). Compared against: fixture itself (pipeline self-check). Tolerance ±1 engine units.

## Coverage

| group | cases | valid | compared | matching |
|---|---|---|---|---|
| code08 | 59 | 59 | 59 | 59 |
| code14 | 93 | 93 | 93 | 93 |
| sample | 6 | 5 | 5 | 5 |

## Cases

Shapes and texts: matched/expected, `+n` = elements the actual list has in excess.

| case | result | shapes | texts | max dev | note |
|---|---|---|---|---|---|
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
| sample-000 | match | 550/550 | 175/175 | 0 | WinScore sample 000.mus |
| sample-carmen | match | 3300/3300 | 331/331 | 0 | WinScore sample carmen.mus |
| sample-mozart | match | 768/768 | 136/136 | 0 | WinScore sample mozart.mus |
| sample-newlib | invalid |  |  |  | dialog: 0x59b090 args=['0x7d3750', '0x7d36fc', '0x0']; dialog: 0x59b090 args=['0x7d3750', '0x7d36fc', '0x0']; dialog: 0x59b090 args=['0x7d3750', '0x7d36fc', '0x0']; dialog: 0x59b090 args=['0x7d3750', '0x7d36fc', '0x0']; dialog: 0x59b090 args=['0x7d3750', '0x7d36fc', '0x0']; dialog: 0x59b090 args=['0x7d3750', '0x7d36fc', '0x0']; dialog: 0x59b090 args=['0x7d3750', '0x7d36fc', '0x0']; dialog: 0x59b090 args=['0x7d3750', '0x7d36fc', '0x0'] |
| sample-newline | match | 165/165 | 960/960 | 0 | SCORE 4 sample NEWLINE.MUS |
| sample-sonlcs | match | 2987/2987 | 322/322 | 0 | WinScore sample sonlcs.mus |
