// Maps the font names of the engine's text stream (the family field of
// WinScore's fontlib/FM*.FMT, list from impl-text) to bundled faces, see
// fonts/README.md.
import './fonts.css';
import type { TextRun } from './display';

/** Metrics of the Windows face GDI would use, in em. */
interface WindowsMetrics {
  /** OS/2 xAvgCharWidth: GDI stretches glyphs until this matches the run's width. */
  average: number;
  /** usWinAscent: GDI's tmAscent, the baseline's depth below the cell top. */
  ascent: number;
}

export interface Face {
  family: string;
  /** Times New Roman, Arial or Courier New where GDI substitutes them; null if unknown. */
  windows: WindowsMetrics | null;
}

const TIMES_NEW_ROMAN: WindowsMetrics = { average: 821 / 2048, ascent: 1825 / 2048 };
const ARIAL: WindowsMetrics = { average: 904 / 2048, ascent: 1854 / 2048 };
const COURIER_NEW: WindowsMetrics = { average: 1229 / 2048, ascent: 1705 / 2048 };

const face = (family: string, windows: WindowsMetrics | null): Face => ({ family, windows });
const TERMES = face('WS Termes', TIMES_NEW_ROMAN);

const FACES: Record<string, Face> = {
  Times: TERMES,
  Helvetica: face('WS Heros', ARIAL),
  'Helvetica-Narrow': face('WS Heros Cn', null),
  Courier: face('WS Cursor', COURIER_NEW),
  Palatino: face('WS Pagella', null),
  AvantGarde: face('WS Adventor', null),
  Bookman: face('WS Bonum', null),
  NewCenturySchlbk: face('WS Schola', null),
  ZapfChancery: face('WS Chorus', null),
  Symbol: face('WS Symbol', null),
  ZapfDingbats: face('WS Dingbats', null),
  // Adobe display faces of WinScore's fonts 35-71: no free metric-compatible
  // versions, so the nearest bundled face of the same kind stands in.
  ...Object.fromEntries(
    ['Americana', 'ACaslon', 'AGaramond', 'Adobe Garamond', 'Trajan', 'Carta', 'WoodtypeOrnaments'].map((name) => [name, face('WS Termes', null)]),
  ),
  ...Object.fromEntries(
    ['AntiqueOlive', 'Antique Olive', 'GillSans', 'Lithos', 'Tekton', 'Blackoak'].map((name) => [name, face('WS Heros', null)]),
  ),
  ...Object.fromEntries(['ParkAvenue', 'Park Avenue', 'Parisian', 'Kaufmann', 'Poetica'].map((name) => [name, face('WS Chorus', null)])),
};

/** The bundled face for an engine font name; unknown names get Times, as the engine's own fallback does. */
export function faceOf(font: string): Face {
  return FACES[font.replace(/\0/g, '').trim()] ?? TERMES;
}

/** Horizontal stretch GDI applies to `run`'s glyphs. */
export function stretch(run: TextRun): number {
  const average = faceOf(run.font).windows?.average;
  return average && run.width > 0 && run.height > 0 ? run.width / (average * run.height) : 1;
}

/** GDI's tmAscent of `run`'s font in engine units, the pivot depth for rotated text. */
export function ascent(run: TextRun): number {
  return (faceOf(run.font).windows?.ascent ?? TIMES_NEW_ROMAN.ascent) * run.height;
}

/** A CSS font shorthand for `run` at `size` pixels. */
export function cssFont(run: TextRun, size: number): string {
  const style = run.italic ? 'italic' : 'normal';
  return `${style} ${run.weight} ${size}px "${faceOf(run.font).family}"`;
}

/** Loads every face `runs` use; resolves when the canvas can draw them. */
export async function loadFaces(runs: TextRun[]): Promise<void> {
  const fonts = new Set(runs.map((run) => cssFont(run, 16)));
  await Promise.all([...fonts].map((font) => document.fonts.load(font)));
}
