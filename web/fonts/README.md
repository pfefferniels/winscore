# Fonts

WinScore's engine names text fonts by the family column of its font-metric files (`WINSCORE 5.01/winscore/fontlib/FM*.FMT`): Times, Helvetica, Helvetica-Narrow, Palatino, AvantGarde, Bookman, NewCenturySchlbk, ZapfChancery, Courier, Symbol, ZapfDingbats, plus weight and italic flags. These are the PostScript base-35 families. The browser draws them with free faces designed to the same metrics, converted to WOFF2 without other changes (fontTools `woff2.compress`).

| Engine family | Face | Files |
|---|---|---|
| Times | TeX Gyre Termes | `texgyretermes-*.woff2` |
| Helvetica | TeX Gyre Heros | `texgyreheros-*.woff2` |
| Helvetica-Narrow | TeX Gyre Heros Condensed | `texgyreheroscn-*.woff2` |
| Palatino | TeX Gyre Pagella | `texgyrepagella-*.woff2` |
| AvantGarde | TeX Gyre Adventor | `texgyreadventor-*.woff2` |
| Bookman | TeX Gyre Bonum | `texgyrebonum-*.woff2` |
| NewCenturySchlbk | TeX Gyre Schola | `texgyreschola-*.woff2` |
| ZapfChancery | TeX Gyre Chorus | `texgyrechorus-mediumitalic.woff2` |
| Courier | TeX Gyre Cursor | `texgyrecursor-*.woff2` |
| Symbol | URW Standard Symbols PS | `standardsymbolsps.woff2` |
| ZapfDingbats | URW D050000L | `d050000l.woff2` |

The URW symbol faces map the Symbol and Dingbats byte codes directly (e.g. `a` → alpha), so engine strings need no re-encoding. The families of `FM35`–`FM60` (Americana, AntiqueOlive, AGaramond, GillSans, Poetica) have no free metric-compatible face here and fall back to the browser's serif.

## Sources and licences

- **TeX Gyre** 2.004/2.005 (GUST e-foundry, B. Jackowski, J. M. Nowacki, P. Strzelczyk), from CTAN `fonts/tex-gyre.zip` (https://mirrors.ctan.org/fonts/tex-gyre.zip), OpenType files. Licence: GUST Font License, an instance of the LaTeX Project Public License (`GUST-FONT-LICENSE.txt`). The faces derive from URW++'s base-35 fonts.
- **URW base35** (URW++ Design & Development, release by Artifex), `StandardSymbolsPS.otf` and `D050000L.otf` from https://github.com/ArtifexSoftware/urw-base35-fonts (`fonts/`, version 2.00). Licence: GNU AGPL v3 with a font exception for embedding in PostScript/PDF documents (`URW-LICENSE.txt`, `URW-COPYING.txt`). Serving them on a public page distributes them under the AGPL; their sources are these font files themselves.
