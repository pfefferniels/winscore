# Fixture status

Written by `score-compare` (crate `score-testkit`). Compared: the engine's `engine.json` against score_render::render of input.mus. Tolerance ±1 engine units. Counts are matched/expected; `+n` = elements only the Rust side has.

## By fixture group

| group | cases | valid | compared | matching | shapes | texts |
|---|---|---|---|---|---|---|
| code03 | 96 | 96 | 96 | 75 | 1132/1132 +3 | 100/124 |
| code04 | 113 | 113 | 113 | 113 | 1959/1959 | 116/116 |
| code06 | 71 | 71 | 71 | 61 | 488/488 | 74/86 |
| code08 | 59 | 59 | 59 | 59 | 419/419 | 92/92 |
| code14 | 93 | 93 | 93 | 81 | 2104/2410 | 359/359 |
| code16 | 91 | 91 | 91 | 0 | 460/502 | 94/1482 |
| code99 | 17 | 17 | 17 | 0 | 133/291 | 18/26 |
| sample | 6 | 6 | 6 | 0 | 1362/7965 | 111/2143 |

## By item code

Only the elements drawn by items of that code, over all compared fixtures; a fixture counts as fully matching when that code's elements all match.

| code | items | fixtures with output | fully matching | shapes | texts |
|---|---|---|---|---|---|
| 1 | notes | 22 | 0 | 0/4719 | 0/2 |
| 2 | rests | 6 | 0 | 0/761 | 0/0 |
| 3 | clefs | 105 | 84 | 988/988 +3 | 0/24 |
| 4 | lines, hairpins | 118 | 118 | 1482/1482 | 0/0 |
| 5 | slurs, brackets | 9 | 0 | 0/144 | 0/4 |
| 6 | beams | 81 | 70 | 548/548 | 0/13 |
| 7 | trills, ottava, pedal | 2 | 0 | 0/220 | 0/9 |
| 8 | staves | 543 | 543 | 4519/4519 | 964/964 |
| 9 | library symbols | 6 | 0 | 0/392 | 0/52 |
| 10 | numbers | 3 | 0 | 0/18 | 0/130 |
| 12 | boxes, grids | 1 | 0 | 0/110 | 0/21 |
| 14 | barlines | 103 | 91 | 520/826 | 0/0 |
| 15 | EPS | 1 | 0 | 0/4 | 0/0 |
| 16 | text | 98 | 0 | 0/71 | 0/3209 |
| 17 | key signatures | 4 | 0 | 0/191 | 0/0 |
| 18 | meters | 7 | 0 | 0/173 | 0/0 |

## Cases

| case | result | shapes | texts | max dev | note |
|---|---|---|---|---|---|
| code03-no-staff | match | 5/5 | 0/0 | 0 | treble clef without a staff |
| code03-p10-pixels-1-bass | match | 30/30 | 1/1 | 0 | pixel thickness P10 = 1, type 1 |
| code03-p10-pixels-1-treble | match | 30/30 | 1/1 | 0 | pixel thickness P10 = 1, type 0 |
| code03-p10-pixels-2-bass | match | 50/50 | 1/1 | 0 | pixel thickness P10 = 2, type 1 |
| code03-p10-pixels-2-treble | match | 50/50 | 1/1 | 0 | pixel thickness P10 = 2, type 0 |
| code03-p10-pixels-m1-bass | match | 10/10 | 1/1 | 0 | pixel thickness P10 = -1, type 1 |
| code03-p10-pixels-m1-treble | match | 10/10 | 1/1 | 0 | pixel thickness P10 = -1, type 0 |
| code03-p15-offset-0.5 | match | 10/10 | 1/1 | 0 | offset P15 = 0.5 |
| code03-p15-offset-0.5-treble-8va | differs | 10/10 | 1/2 | 0 | offset P15 = 0.5, octave number |
| code03-p15-offset-3 | match | 10/10 | 1/1 | 0 | offset P15 = 3 |
| code03-p15-offset-m0.5 | match | 10/10 | 1/1 | 0 | offset P15 = -0.5 |
| code03-p15-offset-m2-treble-8va | differs | 10/10 | 1/2 | 0 | offset P15 = -2, octave number |
| code03-p26-grey | match | 10/10 | 1/1 | 0 | P26 = 0.5 |
| code03-p26-red-treble-8va | differs | 10/10 | 1/2 | 0 | P26 = 990000 with octave number |
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
| code03-p4-mini-100-bass-8vb | differs | 10/10 | 1/2 | 0 | mini clef P4 = 100, type 1.8 |
| code03-p4-mini-100-percussion | match | 7/7 | 1/1 | 0 | mini clef P4 = 100, type 4 |
| code03-p4-mini-100-tab-4 | match | 8/8 | 1/1 | 0 | mini clef P4 = 100, type 44 |
| code03-p4-mini-100-tenor | match | 14/14 | 1/1 | 0 | mini clef P4 = 100, type 3 |
| code03-p4-mini-100-treble | match | 10/10 | 1/1 | 0 | mini clef P4 = 100, type 0 |
| code03-p4-mini-100-treble-8va | differs | 10/10 | 1/2 | 0 | mini clef P4 = 100, type 0.88 |
| code03-p4-mini-100-treble-8vb | differs | 10/10 | 1/2 | 0 | mini clef P4 = 100, type 0.8 |
| code03-p4-mini-102-treble | match | 10/10 | 1/1 | 0 | mini clef P4 = 102, type 0 |
| code03-p4-mini-m100-alto | match | 14/14 | 1/1 | 0 | mini clef P4 = -100, type 2 |
| code03-p4-mini-m100-bass | match | 10/10 | 1/1 | 0 | mini clef P4 = -100, type 1 |
| code03-p4-mini-m100-percussion | match | 7/7 | 1/1 | 0 | mini clef P4 = -100, type 4 |
| code03-p4-mini-m100-tenor | match | 14/14 | 1/1 | 0 | mini clef P4 = -100, type 3 |
| code03-p4-mini-m100-treble | match | 10/10 | 1/1 | 0 | mini clef P4 = -100, type 0 |
| code03-p5-alto | match | 14/14 | 1/1 | 0 | clef type P5 = 2 |
| code03-p5-bass | match | 10/10 | 1/1 | 0 | clef type P5 = 1 |
| code03-p5-bass-8vb | differs | 10/10 | 1/2 | 0 | clef type P5 = 1.8 |
| code03-p5-brace | match | 6/6 | 1/1 | 0 | clef type P5 = 5 |
| code03-p5-flat | match | 8/8 | 1/1 | 0 | clef type P5 = 6 |
| code03-p5-negative | match | 10/10 | 1/1 | 0 | clef type P5 = -1 |
| code03-p5-percussion | match | 7/7 | 1/1 | 0 | clef type P5 = 4 |
| code03-p5-sharp | match | 9/9 | 1/1 | 0 | clef type P5 = 7 |
| code03-p5-symbol-45 | differs | 5/5 +3 | 1/4 | 0 | clef type P5 = 45 |
| code03-p5-tab-4 | match | 8/8 | 1/1 | 0 | clef type P5 = 44 |
| code03-p5-tab-5 | match | 8/8 | 1/1 | 0 | clef type P5 = 55 |
| code03-p5-tab-6 | match | 8/8 | 1/1 | 0 | clef type P5 = 66 |
| code03-p5-tenor | match | 14/14 | 1/1 | 0 | clef type P5 = 3 |
| code03-p5-treble | match | 10/10 | 1/1 | 0 | clef type P5 = 0 |
| code03-p5-treble-15ma | differs | 10/10 | 1/3 | 0 | clef type P5 = 0.15 |
| code03-p5-treble-8va | differs | 10/10 | 1/2 | 0 | clef type P5 = 0.88 |
| code03-p5-treble-8vb | differs | 10/10 | 1/2 | 0 | clef type P5 = 0.8 |
| code03-p6-p7-0-1.5-tab-6 | match | 8/8 | 1/1 | 0 | P6 = 0, P7 = 1.5, type 66 |
| code03-p6-p7-0-1.5-tenor | match | 14/14 | 1/1 | 0 | P6 = 0, P7 = 1.5, type 3 |
| code03-p6-p7-0-1.5-treble | match | 10/10 | 1/1 | 0 | P6 = 0, P7 = 1.5, type 0 |
| code03-p6-p7-0-1.5-treble-8va | differs | 10/10 | 1/2 | 0 | P6 = 0, P7 = 1.5, type 0.88 |
| code03-p6-p7-0.5-2-tab-6 | match | 8/8 | 1/1 | 0 | P6 = 0.5, P7 = 2, type 66 |
| code03-p6-p7-0.5-2-tenor | match | 14/14 | 1/1 | 0 | P6 = 0.5, P7 = 2, type 3 |
| code03-p6-p7-0.5-2-treble | match | 10/10 | 1/1 | 0 | P6 = 0.5, P7 = 2, type 0 |
| code03-p6-p7-0.5-2-treble-8va | differs | 10/10 | 1/2 | 0 | P6 = 0.5, P7 = 2, type 0.88 |
| code03-p6-p7-1-m1-tab-6 | match | 8/8 | 1/1 | 0 | P6 = 1, P7 = -1, type 66 |
| code03-p6-p7-1-m1-tenor | match | 14/14 | 1/1 | 0 | P6 = 1, P7 = -1, type 3 |
| code03-p6-p7-1-m1-treble | match | 10/10 | 1/1 | 0 | P6 = 1, P7 = -1, type 0 |
| code03-p6-p7-1-m1-treble-8va | differs | 10/10 | 1/2 | 0 | P6 = 1, P7 = -1, type 0.88 |
| code03-p6-size-0.5-bass | match | 10/10 | 1/1 | 0 | size P6 = 0.5, type 1 |
| code03-p6-size-0.5-treble | match | 10/10 | 1/1 | 0 | size P6 = 0.5, type 0 |
| code03-p6-size-0.5-treble-8vb | differs | 10/10 | 1/2 | 0 | size P6 = 0.5, type 0.8 |
| code03-p6-size-1.5-bass | match | 10/10 | 1/1 | 0 | size P6 = 1.5, type 1 |
| code03-p6-size-1.5-treble | match | 10/10 | 1/1 | 0 | size P6 = 1.5, type 0 |
| code03-p6-size-1.5-treble-8vb | differs | 10/10 | 1/2 | 0 | size P6 = 1.5, type 0.8 |
| code03-p6-size-m1-bass | match | 10/10 | 1/1 | 0 | size P6 = -1, type 1 |
| code03-p6-size-m1-treble | match | 10/10 | 1/1 | 0 | size P6 = -1, type 0 |
| code03-p6-size-m1-treble-8vb | differs | 10/10 | 1/2 | 0 | size P6 = -1, type 0.8 |
| code03-staff-p4-offset | match | 10/10 | 1/1 | 0 | staff P4 = 2.5, treble |
| code03-staff-recto-201 | differs | 10/10 | 3/4 | 0 | recto staff 201, treble 8va |
| code03-staff-size-0.75-alto | match | 14/14 | 1/1 | 0 | staff size 0.75, type 2 |
| code03-staff-size-0.75-bass | match | 10/10 | 1/1 | 0 | staff size 0.75, type 1 |
| code03-staff-size-0.75-mini-bass | match | 10/10 | 1/1 | 0 | staff size 0.75, mini clef type 1 |
| code03-staff-size-0.75-mini-treble | match | 10/10 | 1/1 | 0 | staff size 0.75, mini clef type 0 |
| code03-staff-size-0.75-tab-5 | match | 8/8 | 1/1 | 0 | staff size 0.75, type 55 |
| code03-staff-size-0.75-treble | match | 10/10 | 1/1 | 0 | staff size 0.75, type 0 |
| code03-staff-size-0.75-treble-8va | differs | 10/10 | 1/2 | 0 | staff size 0.75, type 0.88 |
| code03-staff-size-1.4-alto | match | 14/14 | 1/1 | 0 | staff size 1.4, type 2 |
| code03-staff-size-1.4-bass | match | 10/10 | 1/1 | 0 | staff size 1.4, type 1 |
| code03-staff-size-1.4-tab-5 | match | 8/8 | 1/1 | 0 | staff size 1.4, type 55 |
| code03-staff-size-1.4-treble | match | 10/10 | 1/1 | 0 | staff size 1.4, type 0 |
| code03-staff-size-1.4-treble-8va | differs | 10/10 | 1/2 | 0 | staff size 1.4, type 0.88 |
| code03-staff-size-m1-alto | match | 14/14 | 1/1 | 0 | staff size -1, type 2 |
| code03-staff-size-m1-bass | match | 10/10 | 1/1 | 0 | staff size -1, type 1 |
| code03-staff-size-m1-tab-5 | match | 8/8 | 1/1 | 0 | staff size -1, type 55 |
| code03-staff-size-m1-treble | match | 10/10 | 1/1 | 0 | staff size -1, type 0 |
| code03-staff-size-m1-treble-8va | differs | 10/10 | 1/2 | 0 | staff size -1, type 0.88 |
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
| code04-p12-wavy-vertical-down | match | 12/12 | 1/1 | 1 | arpeggio with arrow down, P12 -100 |
| code04-p12-wavy-vertical-up | match | 12/12 | 1/1 | 1 | arpeggio with arrow up, P12 100 |
| code04-p13-cresc-rotated | match | 6/6 | 1/1 | 0 | crescendo, P13 10 |
| code04-p13-rotation-30 | match | 6/6 | 1/1 | 1 | plain line, P13 30 |
| code04-p13-rotation-90 | match | 6/6 | 1/1 | 1 | plain line, P13 90 |
| code04-p13-rotation-arrow | match | 7/7 | 1/1 | 0 | line with right arrow, P13 -20 |
| code04-p13-rotation-m45 | match | 6/6 | 1/1 | 0 | plain line, P13 -45 |
| code04-p13-vertical-rotated | match | 6/6 | 1/1 | 1 | vertical line, P7 -5, P13 -60 (portamento) |
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
| code04-p15-wavy-vertical | match | 11/11 | 1/1 | 1 | arpeggio, P15 3 |
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
| code04-p6eqp3-wavy-vertical | match | 11/11 | 1/1 | 1 | arpeggio with P6 = P3 |
| code04-p7-cresc-spread | match | 6/6 | 1/1 | 0 | crescendo, P7 3.5 |
| code04-p7-dashes | match | 31/31 | 1/1 | 0 | dashes, P7 1 |
| code04-p7-dashes-2 | match | 31/31 | 1/1 | 0 | P7 2 draws dashes too |
| code04-p7-dashes-bracket | match | 31/31 | 1/1 | 0 | dashes with right bracket P12 2 |
| code04-p7-dashes-rotated | match | 31/31 | 1/1 | 1 | dashes, P13 30 |
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
| code04-p7-thin-vertical | match | 6/6 | 1/1 | 1 | vertical thin wavy line |
| code04-p7-vertical | match | 6/6 | 1/1 | 0 | vertical line, P7 -5 |
| code04-p7-wavy | match | 35/35 | 1/1 | 0 | heavy wavy line, P7 -1 |
| code04-p7-wavy-vertical | match | 11/11 | 1/1 | 1 | vertical heavy wavy line (arpeggio) |
| code04-p8-dash-length | match | 18/18 | 1/1 | 0 | dashes, P8 2 |
| code04-p8-dash-short | match | 70/70 | 1/1 | 0 | dashes, P8 0.4 |
| code04-p8-dot-size | match | 31/31 | 1/1 | 0 | dotted line, P8 2 |
| code04-p8-wavy-unit | match | 20/20 | 1/1 | 0 | heavy wavy line, P8 2 |
| code04-p8-wavy-vertical | match | 9/9 | 1/1 | 1 | arpeggio, P8 1.5, P9 0.7 |
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
| code04-size-0.75-arpeggio | match | 12/12 | 1/1 | 1 | arpeggio on a size 0.75 staff |
| code04-size-0.75-arrows | match | 7/7 | 1/1 | 0 | arrows and brackets on a size 0.75 staff |
| code04-size-0.75-cresc | match | 6/6 | 1/1 | 0 | crescendo on a size 0.75 staff |
| code04-size-0.75-dashes | match | 40/40 | 1/1 | 0 | dashes on a size 0.75 staff |
| code04-size-0.75-wavy | match | 45/45 | 1/1 | 0 | heavy wavy line on a size 0.75 staff |
| code04-size-1.3-saw | match | 52/52 | 1/1 | 0 | sawtooth on a size 1.3 staff |
| code04-staff-2 | match | 11/11 | 2/2 | 0 | line on staff 2 |
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
| code06-p16-number-left | differs | 6/6 | 1/2 | 0 | tuplet number at P16 = 0.3 |
| code06-p17-thick-0.5 | match | 7/7 | 1/1 | 0 | thickness P17 = 0.5 |
| code06-p17-thick-2 | match | 7/7 | 1/1 | 0 | thickness P17 = 2 |
| code06-p18-size-0.75 | match | 7/7 | 1/1 | 0 | size P18 = 0.75 |
| code06-p18-size-1.3 | match | 7/7 | 1/1 | 0 | size P18 = 1.3 |
| code06-p19-number-up | differs | 6/6 | 1/2 | 0 | tuplet number raised P19 = 2 |
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
| code06-p8-font | differs | 6/6 | 1/2 | 0 | tuplet number in font 12, P8 = 12003 |
| code06-p8-font-34 | differs | 6/6 | 1/2 | 0 | tuplet number in font 00 (P8 = 34003) |
| code06-p8-number-11 | differs | 6/6 | 1/3 | 0 | tuplet number P8 = 11 |
| code06-p8-number-12 | differs | 6/6 | 1/3 | 0 | tuplet number P8 = 12 |
| code06-p8-number-3 | differs | 6/6 | 1/2 | 0 | tuplet number P8 = 3 |
| code06-p8-number-5 | differs | 6/6 | 1/2 | 0 | tuplet number P8 = 5 |
| code06-p8-number-cue | differs | 6/6 | 1/2 | 0 | tuplet number on a cue beam |
| code06-p8-number-down | differs | 6/6 | 1/2 | 0 | tuplet number under stems-down beam |
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
| code14-p4-span-m1 | differs | 20/35 | 4/4 | 0 | P4 = -1 staves spanned |
| code14-p4-span-m2 | differs | 20/65 | 4/4 | 0 | P4 = -2 staves spanned |
| code14-p5-brace | match | 21/21 | 4/4 | 0 | type P5 = 8 (brace) |
| code14-p5-brace-span-1 | match | 21/21 | 4/4 | 0 | type P5 = 8 on one staff |
| code14-p5-brace-span-4 | match | 21/21 | 4/4 | 0 | type P5 = 8 spanning all four staves |
| code14-p5-bracket | match | 24/24 | 4/4 | 0 | type P5 = 9 (bracket) |
| code14-p5-bracket-span-1 | match | 24/24 | 4/4 | 0 | type P5 = 9 on one staff |
| code14-p5-bracket-span-4 | match | 24/24 | 4/4 | 0 | type P5 = 9 spanning all four staves |
| code14-p5-dashed | differs | 20/47 | 4/4 | 0 | type P5 = 7 (dashed) |
| code14-p5-dashed-span-1 | differs | 20/29 | 4/4 | 0 | type P5 = 7 on one staff |
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
| code14-p5-two-bar-repeat | differs | 21/25 | 4/4 | 0 | type P5 = -44 (two-bar-repeat) |
| code14-p5-type-11 | differs | 20/53 | 4/4 | 0 | type P5 = 11 (type-11) |
| code14-p5-type-14 | differs | 20/53 | 4/4 | 0 | type P5 = 14 (type-14) |
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
| code14-p8-dash-0.5 | differs | 20/53 | 4/4 | 0 | dashed bar, dash size P8 = 0.5 |
| code14-p8-dash-2 | differs | 20/41 | 4/4 | 0 | dashed bar, dash size P8 = 2 |
| code14-p8-partial-bracket-1 | match | 23/23 | 4/4 | 0 | bracket with P8 = 1 (partial bracket) |
| code14-p8-partial-bracket-2 | match | 23/23 | 4/4 | 0 | bracket with P8 = 2 (partial bracket) |
| code14-p8-partial-bracket-m1 | match | 24/24 | 4/4 | 0 | bracket with P8 = -1 (partial bracket) |
| code14-p8-two-bar-number | differs | 21/26 | 4/4 | 0 | two-bar repeat with number P8 = 2 |
| code14-p9-space-0.5 | differs | 20/74 | 4/4 | 0 | dashed bar, space P9 = 0.5 |
| code14-p9-space-2 | differs | 20/47 | 4/4 | 0 | dashed bar, space P9 = 2 |
| code14-sizes-repeat | match | 22/22 | 2/2 | 0 | repeat bar across staves of size 0.7 and 1 |
| code14-sizes-span-3 | match | 18/18 | 3/3 | 0 | staves of size 1, 0.7, 1.2; final bar spanning 3 |
| code14-staff-offset | match | 11/11 | 2/2 | 0 | barline spanning staves moved by P4 |
| code14-system | match | 30/30 | 4/4 | 0 | system: brace, bracket, start bar, middle and final bars |
| code16-default | differs | 5/5 | 1/16 | 0 | Times (_00) at size 1 |
| code16-font-00 | differs | 5/5 | 1/16 | 0 | font _00 |
| code16-font-01 | differs | 5/5 | 1/16 | 0 | font _01 |
| code16-font-02 | differs | 5/5 | 1/16 | 0 | font _02 |
| code16-font-03 | differs | 5/5 | 1/16 | 0 | font _03 |
| code16-font-04 | differs | 5/5 | 1/16 | 0 | font _04 |
| code16-font-05 | differs | 5/5 | 1/16 | 0 | font _05 |
| code16-font-06 | differs | 5/5 | 1/16 | 0 | font _06 |
| code16-font-07 | differs | 5/5 | 1/16 | 0 | font _07 |
| code16-font-08 | differs | 5/5 | 1/16 | 0 | font _08 |
| code16-font-09 | differs | 5/5 | 1/16 | 0 | font _09 |
| code16-font-10 | differs | 5/5 | 1/16 | 0 | font _10 |
| code16-font-11 | differs | 5/5 | 1/16 | 0 | font _11 |
| code16-font-12 | differs | 5/5 | 1/16 | 0 | font _12 |
| code16-font-13 | differs | 5/5 | 1/16 | 0 | font _13 |
| code16-font-14 | differs | 5/5 | 1/16 | 0 | font _14 |
| code16-font-15 | differs | 5/5 | 1/16 | 0 | font _15 |
| code16-font-16 | differs | 5/5 | 1/16 | 0 | font _16 |
| code16-font-17 | differs | 5/5 | 1/16 | 0 | font _17 |
| code16-font-18 | differs | 5/5 | 1/16 | 0 | font _18 |
| code16-font-19 | differs | 5/5 | 1/16 | 0 | font _19 |
| code16-font-20 | differs | 5/5 | 1/16 | 0 | font _20 |
| code16-font-21 | differs | 5/5 | 1/16 | 0 | font _21 |
| code16-font-22 | differs | 5/5 | 1/16 | 0 | font _22 |
| code16-font-23 | differs | 5/5 | 1/16 | 0 | font _23 |
| code16-font-24 | differs | 5/5 | 1/16 | 0 | font _24 |
| code16-font-25 | differs | 5/5 | 1/16 | 0 | font _25 |
| code16-font-26 | differs | 5/5 | 1/16 | 0 | font _26 |
| code16-font-27 | differs | 5/5 | 1/16 | 0 | font _27 |
| code16-font-28 | differs | 5/5 | 1/16 | 0 | font _28 |
| code16-font-29 | differs | 5/5 | 1/16 | 0 | font _29 |
| code16-font-30 | differs | 5/5 | 1/16 | 0 | font _30 |
| code16-font-31 | differs | 5/5 | 1/16 | 0 | font _31 |
| code16-font-32 | differs | 5/5 | 1/16 | 0 | font _32 |
| code16-font-33 | differs | 5/5 | 1/16 | 0 | font _33 |
| code16-font-34 | differs | 5/5 | 1/16 | 0 | font _34 |
| code16-font-90 | differs | 5/5 | 1/19 | 0 | font _90 |
| code16-font-91 | differs | 5/5 | 1/19 | 0 | font _91 |
| code16-font-92 | differs | 5/5 | 1/19 | 0 | font _92 |
| code16-font-93 | differs | 5/5 | 1/19 | 0 | font _93 |
| code16-font-94 | differs | 5/13 | 1/1 | 0 | meter font _94 |
| code16-font-98 | differs | 5/5 | 1/19 | 0 | font _98 |
| code16-font-99-comment | differs | 5/5 | 1/10 | 0 | non-printing comment _99% |
| code16-fonts-mixed | differs | 5/5 | 1/24 | 0 | font changes inside the string |
| code16-latin1 | differs | 5/5 | 1/12 | 0 | Latin-1 characters |
| code16-lines | differs | 5/5 | 1/16 | 0 | three lines of text |
| code16-long | differs | 5/5 | 1/109 | 0 | a long line |
| code16-one-char | differs | 5/5 | 1/2 | 0 | a single character |
| code16-p10-space-2 | differs | 5/5 | 1/12 | 0 | space size P10 = 2 |
| code16-p11-displace-10 | differs | 5/5 | 1/16 | 0 | horizontal displacement P11 = 10 |
| code16-p11-displace-m5 | differs | 5/5 | 1/16 | 0 | horizontal displacement P11 = -5 |
| code16-p14-colour-red | differs | 5/5 | 1/16 | 0 | P14 = -1, P16 = 990000 |
| code16-p14-grey | differs | 5/5 | 1/16 | 0 | P14 = -1, P16 = 0.5 |
| code16-p14-layer | differs | 5/5 | 1/17 | 0 | P14 = -1, layer P15 = 1 |
| code16-p3-right | differs | 5/5 | 1/16 | 0 | near the right margin, P3 = 180 |
| code16-p4-low | differs | 5/5 | 1/16 | 0 | below the staff, P4 = -6 |
| code16-p5-spacing-0.8 | differs | 5/5 | 1/16 | 0 | character space factor P5 = 0.8 |
| code16-p5-spacing-1.3 | differs | 5/5 | 1/16 | 0 | character space factor P5 = 1.3 |
| code16-p6-parts-101 | differs | 5/5 | 1/16 | 0 | part-extraction flag in P6 = 101 |
| code16-p6-parts-201 | differs | 5/5 | 1/16 | 0 | part-extraction flag in P6 = 201 |
| code16-p6-parts-301 | differs | 5/5 | 1/16 | 0 | part-extraction flag in P6 = 301 |
| code16-p6-size-0 | differs | 5/5 | 1/16 | 0 | size P6 = 0 |
| code16-p6-size-0.5 | differs | 5/5 | 1/16 | 0 | size P6 = 0.5 |
| code16-p6-size-2 | differs | 5/5 | 1/16 | 0 | size P6 = 2 |
| code16-p7-vertical-2 | differs | 5/5 | 1/16 | 0 | P6 = 1, vertical size P7 = 2 |
| code16-p7-vertical-half | differs | 5/5 | 1/16 | 0 | P6 = 2, vertical size P7 = 0.5 |
| code16-p8-font-1000 | differs | 5/5 | 1/16 | 0 | font override P8 = 1000 |
| code16-p8-font-1004 | differs | 5/5 | 1/16 | 0 | font override P8 = 1004 |
| code16-p8-font-1034 | differs | 5/5 | 1/16 | 0 | font override P8 = 1034 |
| code16-p8-font-90 | differs | 5/5 | 1/16 | 0 | font override P8 = 90 |
| code16-p8-font-91 | differs | 5/5 | 1/16 | 0 | font override P8 = 91 |
| code16-p8-font-92 | differs | 5/5 | 1/16 | 0 | font override P8 = 92 |
| code16-p8-font-93 | differs | 5/5 | 1/16 | 0 | font override P8 = 93 |
| code16-p8-font-94 | differs | 5/23 | 1/1 | 0 | font override P8 = 94 |
| code16-p8-font-98 | differs | 5/5 | 1/16 | 0 | font override P8 = 98 |
| code16-p8-outline-1105 | differs | 5/5 | 1/16 | 0 | outline font override P8 = 1105 |
| code16-p8-outline-193 | differs | 5/5 | 1/16 | 0 | outline font override P8 = 193 |
| code16-p9-rotate-180 | differs | 5/5 | 1/16 | 0 | rotation P9 = 180 degrees |
| code16-p9-rotate-30 | differs | 5/5 | 1/16 | 0 | rotation P9 = 30 degrees |
| code16-p9-rotate-90 | differs | 5/5 | 1/16 | 0 | rotation P9 = 90 degrees |
| code16-p9-rotate-m45 | differs | 5/5 | 1/16 | 0 | rotation P9 = -45 degrees |
| code16-punctuation | differs | 5/13 | 1/13 | 0 | punctuation and digits |
| code16-spaces | differs | 5/5 | 1/12 | 0 | words separated by spaces |
| code16-special-brackets | differs | 5/13 | 1/12 | 0 | [ and ] (note symbols in music text) |
| code16-special-copyright | differs | 5/5 | 1/6 | 0 | ?c escape |
| code16-special-slash | differs | 5/5 | 1/10 | 0 | backslash for a printable slash |
| code16-special-umlaut | differs | 5/5 | 1/13 | 0 | %% escapes |
| code16-staff-large | differs | 5/5 | 1/16 | 0 | text on a staff of size 1.5 |
| code16-staff-recto | differs | 10/10 | 4/19 | 0 | text on recto staff 201 |
| code16-staff-small | differs | 5/5 | 1/16 | 0 | text on a staff of size 0.7 |
| code16-tab | differs | 5/5 | 1/10 | 0 | tab stops ~n~ |
| code99-beam-double | differs | 7/15 | 1/1 | 0 | four sixteenths, stems up, two beams |
| code99-beam-down | differs | 6/14 | 1/1 | 0 | four eighths, stems down, one beam |
| code99-beam-partial | differs | 7/12 | 1/1 | 0 | dotted eighth and sixteenth: full beam plus a partial |
| code99-beam-triplet | differs | 6/12 | 1/2 | 0 | three eighths with a 3 over the beam |
| code99-beam-up | differs | 6/14 | 1/1 | 0 | four eighths, stems up, one beam |
| code99-chord | differs | 5/10 | 1/1 | 0 | C major triad with one stem |
| code99-chord-down | differs | 5/19 | 1/1 | 0 | chord with stem down and accidentals |
| code99-chord-second | differs | 5/9 | 1/1 | 0 | chord with a second: the upper note displaced right |
| code99-chord-tie | differs | 5/13 | 1/1 | 0 | two tied chords |
| code99-dynamics | differs | 14/27 | 1/8 | 0 | melody with p, hairpin, tempo text and final bar |
| code99-grace | differs | 5/13 | 1/1 | 0 | grace note with slashed stem slurred to its main note |
| code99-measure-bass | differs | 11/34 | 1/1 | 0 | bass clef, three flats, 6/8, notes with ledger lines and a rest |
| code99-measure-treble | differs | 11/27 | 1/1 | 0 | treble clef, two sharps, 3/4, three quarter notes, barline |
| code99-rests | differs | 7/20 | 1/1 | 0 | notes and rests in one measure, centred whole rest in the next |
| code99-slur | differs | 5/14 | 1/1 | 0 | slur over four quarter notes |
| code99-system | differs | 23/28 | 2/2 | 0 | two staves with brace, notes on both, barlines |
| code99-tie | differs | 5/10 | 1/1 | 0 | two half notes tied |
| sample-000 | differs | 123/550 | 4/175 | 0 | WinScore sample 000.mus |
| sample-carmen | differs | 448/3300 | 35/331 | 0 | WinScore sample carmen.mus |
| sample-mozart | differs | 194/768 | 8/136 | 0 | WinScore sample mozart.mus |
| sample-newlib | differs | 20/195 | 4/219 | 0 | SCORE 4 sample NEWLIB.MUS |
| sample-newline | differs | 89/165 | 13/960 | 1 | SCORE 4 sample NEWLINE.MUS |
| sample-sonlcs | differs | 488/2987 | 47/322 | 0 | WinScore sample sonlcs.mus |
