// WinScore's command table (analysis/data/command_map.tsv, generated into
// src/generated/commands.json): SCORE command and tooltip by menu id.
import table from './generated/commands.json';

export interface Command {
  command: string;
  tooltip: string;
}

const COMMANDS = table as Record<string, Command>;

export function commandById(id: number): Command | null {
  return COMMANDS[String(id)] ?? null;
}

export interface FontCode {
  /** The number of SCORE's font code `_NN`. */
  code: number;
  name: string;
}

/** The fonts of WinScore's font menu (commands FNT00 … FNT36), by number. */
export function fontCodes(): FontCode[] {
  const fonts = Object.values(COMMANDS)
    .map(({ command, tooltip }) => ({ match: /^FNT(\d\d)$/.exec(command), tooltip }))
    .filter((f): f is { match: RegExpExecArray; tooltip: string } => f.match !== null)
    .map(({ match, tooltip }) => ({ code: Number(match[1]), name: tooltip }));
  return [...new Map(fonts.map((f) => [f.code, f])).values()].sort((a, b) => a.code - b.code);
}

/** SCORE's font code for `code`, e.g. `_05`. */
export function fontPrefix(code: number): string {
  return `_${String(code).padStart(2, '0')}`;
}
