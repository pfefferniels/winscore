// Printing and SVG export of the page. Print paints the page, rendered for
// print, onto a 300 dpi canvas that a print stylesheet shows alone on paper
// of the score's size; the app's chrome is hidden.
import type { Box, DisplayList } from './display';
import { loadFaces } from './fonts';
import { paintPrint } from './paint';

const PRINT_DPI = 300;
const UNITS_PER_INCH = 4000;

/** The page container outside the app root, which the host page may wrap. */
function printRoot(): HTMLElement {
  const existing = document.getElementById('print-page');
  if (existing) return existing;
  const root = document.createElement('div');
  root.id = 'print-page';
  root.className = 'print-page';
  document.body.append(root);
  return root;
}

/** `@page` must name the paper size, which only the score knows. */
function setPageSize(widthIn: number, heightIn: number) {
  const id = 'print-page-size';
  const style = document.getElementById(id) ?? document.head.appendChild(Object.assign(document.createElement('style'), { id }));
  style.textContent = `@page { size: ${widthIn}in ${heightIn}in; margin: 0; }`;
}

export async function printPage(list: DisplayList, paper: Box) {
  const widthIn = (paper.x1 - paper.x0) / UNITS_PER_INCH;
  const heightIn = (paper.y1 - paper.y0) / UNITS_PER_INCH;
  await loadFaces(list.texts);
  const canvas = document.createElement('canvas');
  canvas.width = Math.round(widthIn * PRINT_DPI);
  canvas.height = Math.round(heightIn * PRINT_DPI);
  canvas.style.width = `${widthIn}in`;
  canvas.style.height = `${heightIn}in`;
  const ctx = canvas.getContext('2d', { alpha: false });
  if (!ctx) throw new Error('Canvas 2D is not available');
  paintPrint(ctx, list, paper);
  printRoot().replaceChildren(canvas);
  setPageSize(widthIn, heightIn);
  window.print();
}

/** Offers `text` as a file download. */
export function download(text: string | Uint8Array<ArrayBuffer>, name: string, type: string) {
  const url = URL.createObjectURL(new Blob([text], { type }));
  const link = Object.assign(document.createElement('a'), { href: url, download: name });
  link.click();
  URL.revokeObjectURL(url);
}
