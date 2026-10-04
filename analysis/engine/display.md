# C++ display: how the shell paints the engine output

Scope: `CWScoreView::OnDraw` (0x5E5910), the display-list builders 0x5A4570 and 0x5A4900, the text-metrics pass 0x5A42E0, the zoom and colour handlers. Sources: capstone disassembly of `WScore.exe`, the CDC vtables of `MFC42D.DLL` from the install (to name the virtual slots), and the menu, toolbar and accelerator resources parsed with pefile.

Marks: **(read)** = seen in the code at the given address. **(inferred)** = follows from GDI/MFC semantics or from reasoning about the code, not observed at run time.

CDC virtual slots used by OnDraw, checked against the five vtables in `MFC42D.DLL` that contain `CDC::TextOutA` (read): +0x2C `SelectStockObject`, +0x34 `SetBkColor`, +0x3C `SetMapMode`, +0x40 `SetViewportOrg`, +0x64 `TextOutA(int x, int y, LPCSTR, int)` (ordinal 4998).

## 1. Pens, brushes and the fill flag

OnDraw has a screen path (not printing and not print preview) and a print/preview path. The screen path is described first.

### 1.1 Fill mode (`0xD97ECC != 0`), the normal case

- One pass over the display-list entries in stream order. Each entry is drawn immediately, so lines, polygons and the later text keep the engine's painter order (read, 0x5E5C3C–0x5E5E5A).
- Tag 1: `CreatePen(PS_SOLID, 1, c)` with `c = tag word & 0xFFFFFF`, then `Polyline(points, n)` (read, 0x5E5C86–0x5E5D17). `n` is the count of the entry's first sub-path, `0xDA2210[0x156C110[i]]`.
- Every other tag (2, and the 0xFF entries of 1.6): brush `CreateSolidBrush(c != 0 ? c : [0xD97EC4])`, pen `CreatePen(PS_SOLID, 1, c)`, then `PolyPolygon` with the sub-path counts (read, 0x5E5D1C–0x5E5E55). Fill mode is `ALTERNATE` (`SetPolyFillMode(1)`, 0x5E5AD7, read).
- So filled objects are also stroked, with a 1-unit solid pen in the object's raw colour. The pen is not substituted when `c = 0`: a colour-0 polygon is filled with `0xD97EC4` and outlined in black (read). GDI closes each sub-path of a polygon (inferred).
- Between objects the code selects the stock `BLACK_BRUSH` (`GetStockObject(4)`) and a pen in `0xD97EBC`. Nothing is drawn with them (read).

Pen width: the width argument is 1 logical unit, i.e. 0.001 in under `MM_HIENGLISH`. Zoom scales the coordinates, not the mapping, so the pen width does not change with zoom (read). On a screen one logical unit is far below one pixel (about 0.1 px), and GDI draws such a pen one device pixel wide (inferred). In practice every line and polygon outline is a 1-device-pixel hairline at all zoom levels.

### 1.2 Outline mode (`0xD97ECC == 0`)

- Tag 1: `Polyline` with pen `CreatePen(PS_SOLID, 1, [0xD97EBC])` (read, 0x5E5EAF–0x5E5F04). The count is `0xD97ED0[i]`, the count of the entry's last sub-path. It equals the first count unless the polyline contains tag-3 sub-paths.
- Tag 2: `PolyPolyline` with pen `CreatePen(PS_SOLID, 1, [0xD97EC4])` (read, 0x5E5F09–0x5E5F8E). No fill, and sub-paths are not closed.
- Other tags are skipped. Per-object colours are ignored (read).

### 1.3 The flag `0xD97ECC`

- `CMainFrame::OnCreate` sets it to 1 (0x5A1F19, read).
- `0x5A2970` then reads the profile string `Settings\ToolbarState` (18 integers, format at 0x7A0B44) plus two bar-layout strings. The app calls `SetRegistryKey("SanAndreasPress")` (0x5E34CA), so this is the registry under `HKCU\Software\SanAndreasPress\…` (read; the application subkey name is inferred to be the app title). If all three parse, `0x5A2DA0` copies the saved values, among them `0xD97ECC = [0x9C6B30]` (read). `0x5C0050` (frame close) saves them back (read).
- The only writer besides these is the view command 0x801A (32794), handler 0x5E82B0 (view message map entry at 0x7848D0). It toggles the flag, rebuilds via 0x5A4900 and checks menu item 0x801A when the flag is 1 (read).
- No menu item, toolbar button, accelerator or string resource carries id 32794, and no code posts it (read: resources parsed, `push 0x801A` occurs only inside 0x5E82B0). As far as I can see the toggle cannot be reached from the shipped UI, so the flag stays 1 (fill mode) unless the registry value was edited (inferred).

### 1.4 Colour globals

`.data` raw data ends at 0x7AC000, so all globals below start as 0 (read). Every colour setter ends with a rebuild through 0x5A4900 (read).

| Global | Menu (id, handler) | Used in OnDraw for | Without saved settings | With saved settings |
|---|---|---|---|---|
| `0xD97EB8` background | Format > Colors > Background… (32840, 0x5EC110) | `SetBkColor` (0x5E596C) and a `FillRect` when `!= 0xFFFFFF` (section 4) | 0 | saved `0x9C6B1C` |
| `0xD97EBC` default colour | Format > Colors > Default Color… (32838, 0x5EC030) | outline-mode polyline pen, idle pen in fill mode | 0 | saved `0x9C6B20` |
| `0xD97EC0` text colour | Format > Colors > Text Color… (32836, 0x5EBF40) | `0xFFFFFF` means "use each run's own colour", any other value colours all text | 0 (OnCreate, 0x5A1F2D) | forced to `0xFFFFFF` by 0x5A2DA0, the saved value is ignored |
| `0xD97EC4` fill colour | Format > Colors > Fill Color… (32837, 0x5EBE60) | brush for colour-0 filled objects (fill mode), pen for filled objects (outline mode) | 0 | saved `0x9C6B28` |

- The text-colour handler stores the dialog result and immediately overwrites it with `0xFFFFFF` (0x5EBFAF, 0x5EBFB4, read). The user can switch from "all text in one colour" to "per-run colours", never to a chosen colour.
- `0xD97EC8` (selection colour, 32834, 0x5EBD80) is not used by OnDraw (read).
- At a first start without saved settings, text is therefore black regardless of the run colours. After any later start the run colours apply (read, consequence inferred).

### 1.5 Colour 0

For a filled entry, colour bits 0 select `0xD97EC4` for the brush only (0x5E5D35, read). With default settings that is 0, so the result is black fill with a black outline. For a polyline, colour 0 is plain black (read).

### 1.6 Display-list quirks that change what is painted (read, 0x5A4570 and 0x5A4900)

- 0x5A4570 marks a triple whose tag byte is nonzero and whose successor's tag byte is also nonzero by OR-ing `0xFF000000` into its tag (empty start). The colour bits stay.
- 0x5A4900 records an entry's tag word (`0x1561DD0[i]`) from the triple at the entry's start *before* skipping 0xFF triples (0x5A499A, then the skip loop at 0x5A49C1). After an empty start, the next object is therefore stored with tag `0xFF` and the colour of the empty start.
- Consequence in fill mode: that object is drawn as a filled `PolyPolygon` in the empty start's colour, even when it is a tag-1 polyline. In outline mode it is not drawn at all. Whether the engine ever emits a start directly followed by a tag-1 start was not checked.
- A tag-1 entry with tag-3 sub-paths: fill mode draws only the first sub-path, outline mode draws the first N points with N = the last sub-path's count.

## 2. Coordinate mapping

### 2.1 Rounding in 0x5A4900

Per coordinate (read, 0x5A49E2–0x5A4A71): `p = v * zoom` (32-bit `imul`), `r = (p sar 8) + ((p & 0x80) ? 1 : 0)`.

The low byte of a two's-complement `p` is `p mod 256`, so `r = floor(p / 256) + [p mod 256 >= 128] = floor((p + 128) / 256)`. This is round half up (toward +infinity) for negative values too: `p = -128` gives 0, `p = -129` gives -1 (arithmetic, from the read code). In JavaScript: `Math.floor((v * zoom + 128) / 256)`, equal to `(v * zoom + 128) >> 8` while the product fits in 32 bits.

y is not negated in 0x5A4570, 0x5A4900 or OnDraw (read). The engine's y-up convention matches `MM_HIENGLISH`, whose y axis also points up.

### 2.2 Mapping mode and origins

- Screen path: `SetMapMode(MM_HIENGLISH = 5)` (0x5E59CB), `SetScrollSizes(5, total, page, line)` (0x5E5A44), `GetDeviceScrollPosition` into `(sx, sy)` (0x5E5A53), `SetViewportOrg(-sx, -sy)` (0x5E5ACD) (all read). The window origin is never set and stays (0, 0) (read).
- The view does not override `OnPrepareDC`: its vtable slot at 0x784C9C holds the `CScrollView::OnPrepareDC` import (read). That function sets the same mode and origin before OnDraw (inferred, MFC source). OnDraw's own calls override it in any case.
- Print and print preview (`IsPrinting`, or `0x1A14C15` set by Print Preview 0x5EC2B0): `MM_HIENGLISH`, no `SetScrollSizes`, viewport origin (0, 0) (read).
- Result for the screen: with `X, Y` the rounded logical values, `device_x = -sx + k * X`, `device_y = -sy - k * Y`, where `k` is device pixels per 0.001 in as GDI derives it for the display (0.096 for a 96-dpi logical inch) (inferred). Engine content with y <= 0 is on screen, and positive y lies above the scrollable area. At zoom 64 one logical unit is 4 engine units.
- OnDraw also calls `CWnd::BeginPaint`/`EndPaint` on the view itself (0x5E5987, end of function). It does not use that DC (read). Since `CView::OnPaint` has already validated the region, this is harmless as far as I can see (inferred).

### 2.3 Scroll sizes (`0x9C6E88`–`0x9C6E9C`)

- `OnCreate`: total (16000, 16000), page (1024, 1024), line (128, `0x9C6E9C` = 0) (read). For a zero line size MFC substitutes page/10 in device units (inferred, MFC source). The total is 16 x 16 in at any zoom.
- `0x5C1AA0` sets all six from a caller-supplied array: total and page as `v * zoom >> 8` (truncating), line unscaled (read). Its callers were not resolved (no direct call or thunk reference).
- The zoom-bar, PATHX and `~k.` paths (0x5C12E0, 0x5C2FE0, 0x5C3B00, 0x5C3F80, 0x598481) rescale all six by new/old zoom with `__ftol` and scroll to keep the client centre. Zoom, Reduce, Zoom plus and Zoom minus do not rescale them (read).

### 2.4 Zoom values (`0x7A0A80`, 64 = 100 %)

| Source | Effect on zoom | Ref |
|---|---|---|
| start | static value 64 in `.data`. 0x5A2DA0 resets it to 64 when settings load, and the saved value `0x9C6B34` is never read back | read |
| "Mine it! / Zoom" 32771 | `zoom += max(1, zoom / 4)` | 0x5A30D0, read |
| "Dig it! / Reduce" 32772 | `zoom -= max(1, zoom / 4)`, 0 becomes 1 | 0x5A3160, read |
| Zoom plus 32776 | `zoom += 8`, and toggles the zoom-rectangle mode `0x9C6C38` | 0x5A5EE0, read |
| Zoom minus 32777 | `zoom -= 8`, no lower bound | 0x5A6090, read |
| command 34340 | `zoom += 8` (`0x7A0BFC`, static 8) | 0x5C2FE0, read |
| PATHX 2 / PATHX 3 (34347, 34349), only when `0x1A14BB4 != 0` | toggle 64 and 128, resp. 64 and 192 (otherwise the string is sent to the engine) | 0x5C3B00, 0x5C3F80, read |
| right button up, when `0x1A14BB4 == 0` | toggle 64 and 128 around the click point | 0x5E9530, read |
| left button up in zoom-rectangle mode | `zoom = trunc(zoom * client width / drag width)` | 0x5EB4BB–0x5EB514, read |
| zoom bar combo 0x410, CBN_SELCHANGE | `zoom = pct * 64 / 100` for pct in {10, 25, 50, 75, 100, 125, 150, 200, 250, 300, 400, 500}: 6, 16, 32, 48, 64, 80, 96, 128, 160, 192, 256, 320 | 0x5C12E0, read |
| zoom bar combo 0x410, CBN_EDITCHANGE (flag `0x166CE74`) | parses the typed number and, if 1..599, sets `zoom = zoom * 64 / 100` from the *old* zoom, not from the number | 0x5C1731–0x5C174B, read (looks like a bug) |
| Z$ (32748), sent to the engine | engine 0x58C344 steps by the zoom at command start: <64 → 64, <128 → 128, <192 → 192, <256 → 256, <320 → 320, else 64 | read |
| Z2 (34283) and other `Z n` | `zoom = trunc(n * 64 + 0.5)`, n = 0 toggles 64 and 128 | 0x58C344, read (that n is the parsed command number is inferred) |
| engine hand-over | the engine writes `0x9A9498`. 0x5925B0 copies it to `0x7A0A80` after each command, 0x5977C0 copies `-0x9A9498` when negative | read |
| window service `~k.` | value from the engine, where 0 means 64 (or 128 if already 64) | 0x598481, read |

There is no global minimum or maximum. Only Reduce clamps (at 1), and Zoom minus can reach 0 or negative values (read). A painter should accept any positive integer. The zoom bar shows `zoom * 100 >> 6` percent (read).

## 3. Text

### 3.1 `CreateFontA` in the screen path

OnDraw 0x5E6069–0x5E617F, with identical arguments in 0x5A42E0 (0x5A4355–0x5A443D) (read). Record offsets are relative to the font name's NUL. `zf = (float)zoom` is computed once with `fild`/`fstp dword`.

| Argument | Value |
|---|---|
| nHeight | `-trunc(zf * h / 4.0)`, h = f32 at +0x01; x87 `fld zf; fmul dword h; fdiv qword [0x778DB8] (= 4.0); __ftol` |
| nWidth | `trunc(zf * w / 4.0)`, w = (f32 at +0x05) / 2.0, divided in 0x5A4570 (`fdiv qword [0x76D9A0]` = 2.0) and stored as f32 at `0x165D174[i]` |
| nEscapement, nOrientation | both the i32 at +0x09 (tenths of a degree) |
| fnWeight | i32 at +0x11 |
| fdwItalic, fdwUnderline, fdwStrikeOut | byte +0x15, byte +0x19, 0 |
| fdwCharSet | 3 (not one of the defined `*_CHARSET` constants) |
| out / clip precision | 3 `OUT_STROKE_PRECIS`, 2 `CLIP_STROKE_PRECIS` |
| quality | 1 `DRAFT_QUALITY` |
| pitch and family | 0x50 `FF_DECORATIVE \| DEFAULT_PITCH` |
| face | the record's name |

- `__ftol` (0x5ED9B8) sets rounding control to chop and stores with `fistp qword`, so both values are truncated toward zero (read).
- `SetMapperFlags(0)` precedes the font loop (read).
- A negative nHeight requests an em height (character height without internal leading) of `|nHeight|` logical units (inferred, GDI). At zoom 64 this is 16 h thousandths of an inch, matching ARCHITECTURE.md.
- A nonzero nWidth requests that average character width. TrueType glyphs are then stretched or compressed horizontally (inferred). nWidth is 0, i.e. natural proportions, only when the +0x05 field gives `zf * w / 4 < 1`.
- The print/preview path uses width 0 and charset 3, with precision, quality and pitch all 0 (read).

### 3.2 DC state for text

- `SetBkMode(TRANSPARENT)` at the start of OnDraw (0x5E597B, read).
- Neither GDI32 `SetTextAlign` nor `CDC::SetTextAlign` is imported (read), so the alignment is the GDI default `TA_TOP | TA_LEFT | TA_NOUPDATECP` (inferred).
- Colour per run: `[0xD97EC0]`, or the run's colour (+0x0D, `0x16E37F8[i]`) when `0xD97EC0 == 0xFFFFFF` (0x5E61AC–0x5E61E6, read).
- Each string is drawn with `CDC::TextOutA(X, Y, s, lstrlenA(s))` via vtable +0x64 (0x5E6414, read). MFC forwards it to `::TextOutA` (inferred). The run is skipped if `SelectObject` of the font returns NULL (read).

### 3.3 Position

For each string (read, 0x5E623A–0x5E6384):

```
X = floor((x * zoom + 128) / 256)
Y = floor((y * zoom + 96 * zoom + 128) / 256) + A[i]
```

The rounding rule is the one of 2.1, applied to `y + 96` as one product sum. `A[i] = 0x1576570[i]` is `tmAscent`, the `TEXTMETRIC` field at offset 4 (0x5A4490–0x5A44A5, read). 0x5A42E0 measures it with the identical font on `GetDC(view)` after `SetMapMode(MM_HIENGLISH)`, called at the end of every 0x5A4900 rebuild (zoom change, colour change, new stream), so it is in logical units at the current zoom (read). 0x5E77D0 also calls 0x5A42E0 (not examined).

With `TA_TOP` and y up, the cell top is at Y and the baseline at `Y - A[i] = round((y + 96) * zoom / 256)`. The engine's text y plus 96 units (0.024 in) is the baseline, and X is the left edge of the first character cell (inferred). A browser can draw with `textBaseline = 'alphabetic'` at that baseline. GDI derives `tmAscent` from the font realised in device pixels, so differences of about one pixel are to be expected (inferred).

### 3.4 Escapement

GDI rotates the string counterclockwise by e/10 degrees about the reference point, here the top-left cell corner (X, Y) (inferred, GDI). `A[i]` is not adjusted for rotation (read). For e != 0 the browser should rotate about (X, Y) and draw with a top baseline, not rotate about the baseline origin. In y-up logical coordinates the baseline origin then lies at `(X + A sin t, Y - A cos t)`.

## 4. View background and other output

- `FillRect` (0x5E5AE1–0x5E5BD8, read): only if `0xD97EB8 != 0xFFFFFF`, with a solid brush in that colour. The rectangle is `GetClientRect` shifted by `(+sx, +sy)` and is passed after `SetMapMode` and `SetViewportOrg`, i.e. as logical coordinates. That shift would be correct under `MM_TEXT`. Under `MM_HIENGLISH` the rectangle `[sx, sx+W] x [sy, sy+H]` maps to device y <= 0, above the client area, so nothing visible is painted (inferred). The same holds for the print path.
- What the user sees as background is the window-class background. The view has no `WM_ERASEBKGND` handler (message map 0x784840–0x784AF8, read), and MFC's view class uses `COLOR_WINDOW`, white by default (inferred). `SetClassLongA` is used only for cursors (`GCL_HCURSOR`, read).
- `SetBkColor([0xD97EB8])` has no visible effect with `TRANSPARENT` and solid pens and brushes (inferred).
- C++ draws no paper rectangle and makes no inside/outside-paper distinction (read). A paper outline appears only if the engine emits one, e.g. "Paper size outline (PA)" (engine side not checked here).
- `0x9C6C34 != 0` branch (0x5E644A–0x5E6557, read): `0x9C6C34` is -1 while the "Code 16 Text" mode (32795, 0x5A51C0) is on, and it is cleared when that mode is toggled off or by Zoom plus. `OnLButtonDown` (0x5EAD10) stores the click in client pixels at `0xD97D30`/`0xD97D2C`, shows a caret and clears the buffer `0xD97D34`. OnDraw then creates a font from the `LOGFONT` at `0xD97CF0` (set by "Choose a font", 57696, 0x5E5010; all zero otherwise), copies `"Font Test"` (0x784814) into `0xD97D34` and calls `TextOutA(x = [0xD97D30], y = [0xD97D2C])`. The pixel coordinates are used as `MM_HIENGLISH` logical coordinates, so the string lands above the visible area and is normally not seen (inferred). This looks like leftover test code and can be ignored.
- Outside OnDraw, C++ only draws transient feedback: `DrawDragRect` for the rubber band (0x5E9D60, `WM_MOUSEMOVE`), the text caret, and a "Font Test" sample in 0x5E5010 (read for the call sites). None of it is part of the persistent picture.
- Print/preview path, for completeness (read): fill mode creates the two pens but never selects them, and polygons get `SelectStockObject(BLACK_BRUSH)`, so printed output ignores object colours. Outline mode there reuses pen handles deleted after the last screen paint.

## Open points

- The callers of 0x5C1AA0 (engine-supplied scroll sizes) were not resolved.
- Whether the engine emits an empty start before a tag-1 object (1.6) was not checked.
- The display scale `k` of `MM_HIENGLISH` on the systems WinScore ran on was not measured.
- 0x5E77D0, the second caller of 0x5A42E0, was not examined.
