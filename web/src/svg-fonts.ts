// Fonts of the page's SVG (score_render::svg). Each text run names a font
// stack that starts with the face the app bundles for its family, under the
// app's name ("WS Termes", see fonts.css). In the app's document, for print,
// the app's own @font-face rules supply these faces; an exported file
// carries the ones it uses as WOFF2 data, so it shows them wherever it is
// opened. Without them a viewer takes the next family in the stack.

/** A face as a text run of the SVG asks for it. */
interface Wanted {
  family: string;
  italic: boolean;
  weight: number;
}

/** One of the app's @font-face rules. */
interface FaceRule {
  family: string;
  /** The font-style and font-weight descriptors as written. */
  style: string;
  weight: string;
  /** The font-weight range the rule covers. */
  weights: [number, number];
  /** The WOFF2 file, resolved against its style sheet. */
  url: string;
}

/** The first family of a CSS font-family list, unquoted. */
function firstFamily(stack: string): string {
  return (stack.split(',')[0] ?? '').trim().replace(/^(['"])(.*)\1$/, '$2');
}

function weightOf(value: string): number {
  if (value === 'bold') return 700;
  return Number(value) || 400;
}

/** The faces the text runs under `root` ask for first, one of each. */
function wantedFaces(root: ParentNode): Wanted[] {
  const faces = new Map<string, Wanted>();
  root.querySelectorAll('[font-family]').forEach((element) => {
    const family = firstFamily(element.getAttribute('font-family') ?? '');
    const weight = weightOf(element.getAttribute('font-weight') ?? '400');
    const italic = element.getAttribute('font-style') === 'italic';
    faces.set(`${family}/${weight}/${italic}`, { family, italic, weight });
  });
  return [...faces.values()];
}

/** The document's @font-face rules (the app's fonts.css), wherever the build put the files. */
function faceRules(): FaceRule[] {
  const rules: FaceRule[] = [];
  for (const sheet of Array.from(document.styleSheets)) {
    let list: CSSRuleList;
    try {
      list = sheet.cssRules;
    } catch {
      continue; // a style sheet of another origin
    }
    for (const rule of Array.from(list)) {
      if (!(rule instanceof CSSFontFaceRule)) continue;
      const get = (name: string) => rule.style.getPropertyValue(name).trim();
      const src = /url\((['"]?)(.+?)\1\)/.exec(get('src'))?.[2];
      if (!src) continue;
      const weight = get('font-weight') || '400';
      const [low = 400, high = low] = weight.split(/\s+/).map(weightOf);
      rules.push({
        family: firstFamily(get('font-family')),
        style: get('font-style') || 'normal',
        weight,
        weights: [low, high],
        url: new URL(src, sheet.href ?? document.baseURI).href,
      });
    }
  }
  return rules;
}

function matches(rule: FaceRule, face: Wanted): boolean {
  const [low, high] = rule.weights;
  return rule.family === face.family && (rule.style === 'italic') === face.italic && low <= face.weight && face.weight <= high;
}

async function dataUrl(url: string): Promise<string> {
  const response = await fetch(url);
  if (!response.ok) throw new Error(`${url}: ${response.status} ${response.statusText}`);
  const bytes = new Uint8Array(await response.arrayBuffer());
  let binary = '';
  for (let at = 0; at < bytes.length; at += 0x8000) binary += String.fromCharCode(...bytes.subarray(at, at + 0x8000));
  return `data:font/woff2;base64,${btoa(binary)}`;
}

/**
 * `svg` with the app's faces its text uses embedded as @font-face rules, only
 * the styles and weights it uses. A face that cannot be fetched is left
 * out, and the viewer falls back along the font stack.
 */
export async function embedFonts(svg: string): Promise<string> {
  const start = /^<svg\b[^>]*>\n?/.exec(svg);
  if (!start) return svg;
  const rules = faceRules();
  const wanted = wantedFaces(new DOMParser().parseFromString(svg, 'image/svg+xml'));
  const used = new Set(wanted.map((face) => rules.find((rule) => matches(rule, face))).filter((rule) => rule !== undefined));
  const faces = await Promise.allSettled(
    [...used].map(
      async (rule) =>
        `@font-face { font-family: "${rule.family}"; font-style: ${rule.style}; font-weight: ${rule.weight}; ` +
        `src: url(${await dataUrl(rule.url)}) format("woff2"); }`,
    ),
  );
  const css = faces.flatMap((face) => (face.status === 'fulfilled' ? [face.value] : []));
  if (css.length === 0) return svg;
  const at = start[0].length;
  return `${svg.slice(0, at)}<defs><style>\n${css.join('\n')}\n</style></defs>\n${svg.slice(at)}`;
}

/** Loads the app's faces that the text under `root` asks for; resolves when the page can show them. */
export async function loadSvgFaces(root: ParentNode): Promise<void> {
  const fonts = wantedFaces(root).map((face) => `${face.italic ? 'italic' : 'normal'} ${face.weight} 16px "${face.family}"`);
  await Promise.all(fonts.map((font) => document.fonts.load(font)));
}
