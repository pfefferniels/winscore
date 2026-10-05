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
  source: number | null;
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

/** Decodes score-web's flat encoding. Each getter of `encoded` copies out of wasm memory, so each is read once. */
export function decode(encoded: Encoded): DisplayList {
  const coords = encoded.coords;
  let point = 0;
  const take = (length: number) => {
    const path = coords.subarray(2 * point, 2 * (point + length));
    point += length;
    return path;
  };
  const source = (word: number) => (word === 0 ? null : word - 1);
  const shapes = Array.from(records(encoded.shapes), (r) => ({
    fill: (r.flags & FLAG_FILL) !== 0,
    colour: r.colour,
    source: source(r.source),
    paths: Array.from(r.lengths, take),
  }));
  const runs = (JSON.parse(encoded.texts) as { texts: (Omit<TextRun, 'source'> & { item?: number })[] }).texts;
  const texts = runs.map(({ item, ...run }) => ({ ...run, source: item ?? null }));
  return { shapes, texts };
}

/** The elements of `list` drawn for one item. */
export function elementsOf(list: DisplayList, item: number): DisplayList {
  return {
    shapes: list.shapes.filter((s) => s.source === item),
    texts: list.texts.filter((r) => r.source === item),
  };
}

export function union(a: Box | null, b: Box | null): Box | null {
  if (!a) return b;
  if (!b) return a;
  return { x0: Math.min(a.x0, b.x0), y0: Math.min(a.y0, b.y0), x1: Math.max(a.x1, b.x1), y1: Math.max(a.y1, b.y1) };
}

/** One pass over the x, y pairs; this runs over every point of a page, so it avoids intermediate arrays. */
function pathBounds(path: Int32Array): Box | null {
  if (path.length < 2) return null;
  const box = { x0: path[0]!, y0: path[1]!, x1: path[0]!, y1: path[1]! };
  for (let i = 2; i + 1 < path.length; i += 2) {
    const x = path[i]!;
    const y = path[i + 1]!;
    if (x < box.x0) box.x0 = x;
    else if (x > box.x1) box.x1 = x;
    if (y < box.y0) box.y0 = y;
    else if (y > box.y1) box.y1 = y;
  }
  return box;
}

/** Ascent and descent of a character cell in em (roughly Times New Roman), as score-web's hit test uses. */
const CELL_ASCENT = 0.8;
const CELL_DESCENT = 0.25;

/** Boxes around a run's strings, whose y is the baseline. */
function textBounds(run: TextRun): Box | null {
  const advance = run.width > 0 ? run.width : run.height / 2;
  return run.strings
    .map((s) => ({
      x0: s.x,
      y0: s.y - CELL_DESCENT * run.height,
      x1: s.x + advance * Math.max(1, s.text.length),
      y1: s.y + CELL_ASCENT * run.height,
    }))
    .reduce<Box | null>(union, null);
}

export function bounds(list: DisplayList): Box | null {
  const shapes = list.shapes.flatMap((s) => s.paths.map(pathBounds));
  const texts = list.texts.map(textBounds);
  return [...shapes, ...texts].reduce<Box | null>(union, null);
}
