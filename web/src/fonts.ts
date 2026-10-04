// Maps the font names of the engine's text stream (the family column of
// WinScore's fontlib/FM*.FMT) to bundled metric-compatible faces, see
// fonts/README.md.
import './fonts.css';
import type { TextRun } from './display';

export interface Face {
  family: string;
  /**
   * Average character width in em of the Windows face that GDI substitutes
   * for the engine's name (OS/2 xAvgCharWidth of Times New Roman, Arial,
   * Courier New). OnDraw passes the run's width to CreateFontA, and GDI
   * stretches the face until its average width matches; null where the
   * substitute is unknown, which leaves the glyphs unstretched.
   */
  windowsAverage: number | null;
}

const FACES: Record<string, Face> = {
  Times: { family: 'WS Termes', windowsAverage: 821 / 2048 },
  Helvetica: { family: 'WS Heros', windowsAverage: 904 / 2048 },
  'Helvetica-Narrow': { family: 'WS Heros Cn', windowsAverage: null },
  Courier: { family: 'WS Cursor', windowsAverage: 1229 / 2048 },
  Palatino: { family: 'WS Pagella', windowsAverage: null },
  AvantGarde: { family: 'WS Adventor', windowsAverage: null },
  Bookman: { family: 'WS Bonum', windowsAverage: null },
  NewCenturySchlbk: { family: 'WS Schola', windowsAverage: null },
  ZapfChancery: { family: 'WS Chorus', windowsAverage: null },
  Symbol: { family: 'WS Symbol', windowsAverage: null },
  ZapfDingbats: { family: 'WS Dingbats', windowsAverage: null },
};

const FALLBACK: Face = { family: 'serif', windowsAverage: null };

export function face(font: string): Face {
  return FACES[font] ?? FALLBACK;
}

/** Horizontal stretch GDI applies to `run`'s glyphs. */
export function stretch(run: TextRun): number {
  const average = face(run.font).windowsAverage;
  return average && run.width > 0 && run.height > 0 ? run.width / (average * run.height) : 1;
}

/** A CSS font shorthand for `run` at `size` pixels. */
export function cssFont(run: TextRun, size: number): string {
  const style = run.italic ? 'italic' : 'normal';
  const family = face(run.font).family;
  const quoted = family.includes(' ') ? `"${family}"` : family;
  return `${style} ${run.weight} ${size}px ${quoted}`;
}

/** Loads every face `runs` use; resolves when the canvas can draw them. */
export async function loadFaces(runs: TextRun[]): Promise<void> {
  const fonts = new Set(runs.map((run) => cssFont(run, 16)));
  await Promise.all([...fonts].map((font) => document.fonts.load(font)));
}
