// Display lists as the painter sees them, decoded from score-web's flat
// encoding (rust/crates/score-web/src/encode.rs). Page coordinates in engine
// units: 1/4000 inch, origin at the paper's bottom-left corner, y up.

export interface Shape {
  fill: boolean;
  /** 0xRRGGBB */
  colour: number;
  /** Index of the source item, or null for screen aids and reference lists. */
  source: number | null;
  /** x, y pairs; views into one shared coordinate array. */
  paths: Int32Array[];
}

export interface PlacedString {
  text: string;
  x: number;
  /** Top of the character cell. */
  y: number;
}

export interface TextRun {
  colour: [number, number, number];
  escapement: number;
  font: string;
  /** Character height (em size) in engine units. */
  height: number;
  italic: boolean;
  strings: PlacedString[];
  underline: boolean;
  weight: number;
  /** Average character width in engine units, 0 = font default. */
  width: number;
  source?: number;
}

export interface DisplayList {
  shapes: Shape[];
  texts: TextRun[];
}

export interface Box {
  x0: number;
  y0: number;
  x1: number;
  y1: number;
}

export interface Encoded {
  readonly shapes: Uint32Array;
  readonly coords: Int32Array;
  readonly texts: string;
}

const FLAG_FILL = 1;
const HEADER_WORDS = 4;

export const EMPTY: DisplayList = { shapes: [], texts: [] };

interface Record {
  flags: number;
  colour: number;
  source: number;
  lengths: Uint32Array;
}

/** The variable-length shape records of the header array. */
function* records(header: Uint32Array): Generator<Record> {
  for (let at = 0; at < header.length; ) {
    const [flags = 0, colour = 0, source = 0, count = 0] = header.subarray(at, at + HEADER_WORDS);
    const lengths = header.subarray(at + HEADER_WORDS, at + HEADER_WORDS + count);
    yield { flags, colour, source, lengths };
    at += HEADER_WORDS + count;
  }
}

export function decode(encoded: Encoded): DisplayList {
  let point = 0;
  const take = (length: number) => {
    const path = encoded.coords.subarray(2 * point, 2 * (point + length));
    point += length;
    return path;
  };
  const shapes = Array.from(records(encoded.shapes), (r) => ({
    fill: (r.flags & FLAG_FILL) !== 0,
    colour: r.colour,
    source: r.source === 0 ? null : r.source - 1,
    paths: Array.from(r.lengths, take),
  }));
  return { shapes, texts: JSON.parse(encoded.texts) as TextRun[] };
}

export function union(a: Box | null, b: Box | null): Box | null {
  if (!a) return b;
  if (!b) return a;
  return { x0: Math.min(a.x0, b.x0), y0: Math.min(a.y0, b.y0), x1: Math.max(a.x1, b.x1), y1: Math.max(a.y1, b.y1) };
}

function pathBounds(path: Int32Array): Box | null {
  const xs = path.filter((_, i) => i % 2 === 0);
  const ys = path.filter((_, i) => i % 2 === 1);
  if (xs.length === 0) return null;
  return { x0: Math.min(...xs), y0: Math.min(...ys), x1: Math.max(...xs), y1: Math.max(...ys) };
}

function textBounds(run: TextRun): Box | null {
  return run.strings
    .map((s) => ({ x0: s.x, y0: s.y - run.height, x1: s.x + run.height * s.text.length, y1: s.y }))
    .reduce<Box | null>(union, null);
}

export function bounds(list: DisplayList): Box | null {
  const shapes = list.shapes.flatMap((s) => s.paths.map(pathBounds));
  const texts = list.texts.map(textBounds);
  return [...shapes, ...texts].reduce<Box | null>(union, null);
}
