// The symbol picker: every symbol of WinScore's bundled libraries, drawn by
// the Rust renderer as a code-9 item draws it, searchable by number or name.
import { librarySymbols, symbolPreview } from './wasm/score_web.js';
import { bounds, decode } from './display';
import { paintThumbnail } from './paint';

export interface SymbolDialog {
  /** Resolves with the chosen symbol number, or null when cancelled. */
  choose(): Promise<number | null>;
}

interface LibrarySymbol {
  number: number;
  name: string;
}

const CELL_PX = 56;

function paintPreview(canvas: HTMLCanvasElement, symbol: number) {
  const encoded = symbolPreview(symbol);
  const list = decode(encoded);
  encoded.free();
  const box = bounds(list);
  const ctx = canvas.getContext('2d');
  if (box && ctx) paintThumbnail(ctx, list, box);
}

function cell(symbol: LibrarySymbol, pick: (n: number) => void): HTMLButtonElement {
  const button = document.createElement('button');
  button.type = 'button';
  button.className = 'symbol-cell';
  button.title = `${symbol.number} ${symbol.name}`;
  button.dataset.number = String(symbol.number);
  const canvas = document.createElement('canvas');
  const ratio = window.devicePixelRatio || 1;
  canvas.width = Math.round(CELL_PX * ratio);
  canvas.height = Math.round(CELL_PX * ratio);
  canvas.style.width = `${CELL_PX}px`;
  canvas.style.height = `${CELL_PX}px`;
  const label = document.createElement('span');
  label.textContent = String(symbol.number);
  button.append(canvas, label);
  button.addEventListener('click', () => pick(symbol.number));
  return button;
}

export function createSymbolDialog(dialog: HTMLDialogElement): SymbolDialog {
  const search = dialog.querySelector<HTMLInputElement>('#symbol-search')!;
  const grid = dialog.querySelector<HTMLElement>('#symbol-grid')!;
  const count = dialog.querySelector<HTMLElement>('#symbol-count')!;
  let symbols: LibrarySymbol[] | null = null;
  let chosen: number | null = null;

  // Previews are painted when a cell first scrolls into view.
  const painter = new IntersectionObserver(
    (entries) =>
      entries
        .filter((entry) => entry.isIntersecting)
        .forEach((entry) => {
          const button = entry.target as HTMLButtonElement;
          painter.unobserve(button);
          paintPreview(button.querySelector('canvas')!, Number(button.dataset.number));
        }),
    { root: grid },
  );

  const pick = (number: number) => {
    chosen = number;
    dialog.close('insert');
  };

  const load = () => {
    symbols ??= (JSON.parse(librarySymbols()) as [number, string][]).map(([number, name]) => ({ number, name }));
    const cells = symbols.map((symbol) => cell(symbol, pick));
    grid.replaceChildren(...cells);
    cells.forEach((c) => painter.observe(c));
  };

  const filter = () => {
    const query = search.value.trim().toLowerCase();
    const shown = Array.from(grid.children as HTMLCollectionOf<HTMLButtonElement>).filter((button) => {
      const match = !query || button.title.toLowerCase().includes(query);
      button.hidden = !match;
      return match;
    });
    count.textContent = `${shown.length} symbols`;
  };

  search.addEventListener('input', filter);
  search.addEventListener('keydown', (e) => {
    if (e.key !== 'Enter') return;
    e.preventDefault();
    const first = Array.from(grid.children as HTMLCollectionOf<HTMLButtonElement>).find((b) => !b.hidden);
    if (first) pick(Number(first.dataset.number));
  });

  return {
    choose() {
      if (!symbols) load();
      chosen = null;
      filter();
      dialog.returnValue = '';
      dialog.showModal();
      search.select();
      return new Promise((resolve) => {
        dialog.addEventListener('close', () => resolve(dialog.returnValue === 'insert' ? chosen : null), { once: true });
      });
    },
  };
}
