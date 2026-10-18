// Maps the font names of the engine's text stream (the family field of
// WinScore's fontlib/FM*.FMT, list from impl-text) to bundled faces, see
// fonts/README.md.
import './fonts.css';
import type { TextRun } from './display';

export interface Face {
  family: string;
  /**
   * usWinAscent in em of the Windows face GDI substitutes (Times New Roman,
   * Arial, Courier New), GDI's tmAscent: the baseline's depth below the cell
   * top, about which GDI turns rotated text; null if unknown.
   */
  ascent: number | null;
}

const TIMES_NEW_ROMAN = 1825 / 2048;
const ARIAL = 1854 / 2048;
const COURIER_NEW = 1705 / 2048;

const face = (family: string, ascent: number | null): Face => ({ family, ascent });
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

/**
 * Average character width per em of ordinary text (P6 = P7): the record
 * header's width over its height, 32 · 0.825 / 64 (`Text::style` in
 * score-render's text/mod.rs, analysis/engine/text.md).
 */
const ORDINARY_WIDTH = 0.4125;

/**
 * Horizontal scale of `run`'s glyphs: 1 for ordinary text, P6/P7 where the
 * text sets its width apart from its height, whatever the face. GDI instead
 * fitted the Windows face's average character width to the run's (squeezing
 * Courier to 69 %), a property of the face that SCORE's own spacing ignores.
 */
export function stretch(run: TextRun): number {
  return run.width > 0 && run.height > 0 ? run.width / (ORDINARY_WIDTH * run.height) : 1;
}

/** GDI's tmAscent of `run`'s font in engine units, the pivot depth for rotated text. */
export function ascent(run: TextRun): number {
  return (faceOf(run.font).ascent ?? TIMES_NEW_ROMAN) * run.height;
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
