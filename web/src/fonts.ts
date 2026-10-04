// Maps the font names of the engine's text stream (the family column of
// WinScore's fontlib/FM*.FMT) to bundled metric-compatible faces, see
// fonts/README.md.
import './fonts.css';
import type { TextRun } from './display';

export interface Face {
  family: string;
  /**
   * Cell top to baseline, in em. WinScore draws text from the top-left of
   * the character cell, which Windows takes from the face's ascent. The
   * values are those of the faces Windows substitutes (Times New Roman,
   * Arial, Courier New, Symbol); the others are assumed until checked.
   */
  ascent: number;
}

const ASSUMED_ASCENT = 0.9;

const FACES: Record<string, Face> = {
  Times: { family: 'WS Termes', ascent: 0.891 },
  Helvetica: { family: 'WS Heros', ascent: 0.905 },
  'Helvetica-Narrow': { family: 'WS Heros Cn', ascent: 0.905 },
  Courier: { family: 'WS Cursor', ascent: 0.833 },
  Palatino: { family: 'WS Pagella', ascent: ASSUMED_ASCENT },
  AvantGarde: { family: 'WS Adventor', ascent: ASSUMED_ASCENT },
  Bookman: { family: 'WS Bonum', ascent: ASSUMED_ASCENT },
  NewCenturySchlbk: { family: 'WS Schola', ascent: ASSUMED_ASCENT },
  ZapfChancery: { family: 'WS Chorus', ascent: ASSUMED_ASCENT },
  Symbol: { family: 'WS Symbol', ascent: 1.005 },
  ZapfDingbats: { family: 'WS Dingbats', ascent: ASSUMED_ASCENT },
};

const FALLBACK: Face = { family: 'serif', ascent: ASSUMED_ASCENT };

export function face(font: string): Face {
  return FACES[font] ?? FALLBACK;
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
