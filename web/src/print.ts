// Printing and SVG export of the page. Print puts the page, drawn for print
// as SVG by score_render::svg, into a container that a print stylesheet
// shows alone on paper of the score's size; the app's chrome is hidden.
// Lines, curves and text stay vectors at the printer's resolution, and a
// PDF saved from the print dialog has real paths and text.
import type { Box } from './display';
import { loadSvgFaces } from './svg-fonts';

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

/** Prints `svg`, the page as the score's exportSvg draws it, on paper `paper`. */
export async function printPage(svg: string, paper: Box) {
  const widthIn = (paper.x1 - paper.x0) / UNITS_PER_INCH;
  const heightIn = (paper.y1 - paper.y0) / UNITS_PER_INCH;
  const parsed = new DOMParser().parseFromString(svg, 'image/svg+xml');
  if (parsed.documentElement.localName !== 'svg' || parsed.querySelector('parsererror')) {
    throw new Error('The page could not be drawn for print');
  }
  // Inline in the document, its text takes the app's faces (fonts.css); the
  // container is hidden on screen, so nothing would load them before print.
  const page = document.importNode(parsed.documentElement, true);
  await loadSvgFaces(page);
  printRoot().replaceChildren(page);
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
