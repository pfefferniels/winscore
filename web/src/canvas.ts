// The scrolling page view: a viewport-sized canvas behind a scroll container
// whose content div has the size of the zoomed page. Scrolling and zooming
// repaint the canvas; nothing is drawn outside the visible area.
import type { Box } from './display';
import { paint, type Highlight, type Layer } from './paint';
import { contentSize, cssPerUnit, toPage, transform, type Point, type Transform } from './view';

export interface Scene {
  layers: Layer[];
  paper: Box;
  extent: Box;
  highlights: Highlight[];
}

export interface Elements {
  stage: HTMLElement;
  viewport: HTMLElement;
  content: HTMLElement;
  canvas: HTMLCanvasElement;
}

export interface PageView {
  readonly zoom: number;
  setScene(scene: Scene): void;
  /** Zooms keeping the page point under (`clientX`, `clientY`) in place; default the viewport centre. */
  setZoom(zoom: number, anchor?: { clientX: number; clientY: number }): void;
  fitWidth(): void;
  /** Scrolls so that page y `top` is at the top of the viewport. */
  scrollToTop(top: number): void;
  /** Scrolls `box` (page coordinates) into the middle of the view unless it is fully visible. */
  reveal(box: Box): void;
  /** Page coordinates under a client (mouse) position. */
  pageAt(clientX: number, clientY: number): Point;
  /** Engine units spanned by `px` CSS pixels at the current zoom. */
  unitsPerCss(px: number): number;
  repaint(): void;
}

const EMPTY_BOX: Box = { x0: 0, y0: 0, x1: 34000, y1: 56000 };

export function createPageView(el: Elements, onZoom: (zoom: number) => void): PageView {
  const ctx = el.canvas.getContext('2d', { alpha: false });
  if (!ctx) throw new Error('Canvas 2D is not available');
  let scene: Scene = { layers: [], paper: EMPTY_BOX, extent: EMPTY_BOX, highlights: [] };
  let zoom = 100;
  let frame = 0;

  const dpr = () => window.devicePixelRatio || 1;

  /** Centering offsets when the page is smaller than the viewport. */
  const offsets = () => {
    const size = contentSize(zoom, scene.extent);
    return {
      left: Math.max(0, (el.viewport.clientWidth - size.width) / 2),
      top: Math.max(0, (el.viewport.clientHeight - size.height) / 2),
    };
  };

  const currentTransform = (): Transform =>
    transform({
      zoom,
      extent: scene.extent,
      ...offsets(),
      scrollLeft: el.viewport.scrollLeft,
      scrollTop: el.viewport.scrollTop,
      dpr: dpr(),
    });

  const layout = () => {
    const size = contentSize(zoom, scene.extent);
    el.content.style.width = `${size.width}px`;
    el.content.style.height = `${size.height}px`;
  };

  const draw = () => {
    frame = 0;
    const width = el.viewport.clientWidth;
    const height = el.viewport.clientHeight;
    const ratio = dpr();
    const deviceWidth = Math.round(width * ratio);
    const deviceHeight = Math.round(height * ratio);
    if (el.canvas.width !== deviceWidth || el.canvas.height !== deviceHeight) {
      el.canvas.width = deviceWidth;
      el.canvas.height = deviceHeight;
      el.canvas.style.width = `${width}px`;
      el.canvas.style.height = `${height}px`;
    }
    paint(ctx, {
      transform: currentTransform(),
      paper: scene.paper,
      layers: scene.layers,
      highlights: scene.highlights,
    });
  };

  const repaint = () => {
    if (frame === 0) frame = requestAnimationFrame(draw);
  };

  const clientToViewport = (clientX: number, clientY: number) => {
    const rect = el.viewport.getBoundingClientRect();
    return { x: clientX - rect.left, y: clientY - rect.top };
  };

  const pageAt = (clientX: number, clientY: number): Point => {
    const p = clientToViewport(clientX, clientY);
    const ratio = dpr();
    return toPage(currentTransform(), p.x * ratio, p.y * ratio);
  };

  const setZoom = (next: number, anchor?: { clientX: number; clientY: number }) => {
    const rect = el.viewport.getBoundingClientRect();
    const client = anchor ?? { clientX: rect.left + el.viewport.clientWidth / 2, clientY: rect.top + el.viewport.clientHeight / 2 };
    const fixed = pageAt(client.clientX, client.clientY);
    zoom = Math.min(3200, Math.max(5, next));
    layout();
    const { left, top } = offsets();
    const s = cssPerUnit(zoom);
    const local = clientToViewport(client.clientX, client.clientY);
    el.viewport.scrollLeft = left + (fixed.x - scene.extent.x0) * s - local.x;
    el.viewport.scrollTop = top + (scene.extent.y1 - fixed.y) * s - local.y;
    onZoom(zoom);
    repaint();
  };

  const fitWidth = () => {
    const width = el.viewport.clientWidth - 2;
    const extentInches = (scene.extent.x1 - scene.extent.x0) / 4000;
    setZoom(Math.floor((width / (extentInches * 96)) * 100));
    el.viewport.scrollTop = 0;
  };

  el.viewport.addEventListener('scroll', repaint, { passive: true });
  new ResizeObserver(repaint).observe(el.stage);
  el.viewport.addEventListener(
    'wheel',
    (e) => {
      if (!e.ctrlKey && !e.metaKey) return;
      e.preventDefault();
      setZoom(zoom * Math.exp(-e.deltaY * 0.01), e);
    },
    { passive: false },
  );

  return {
    get zoom() {
      return zoom;
    },
    setScene(next: Scene) {
      scene = next;
      layout();
      repaint();
    },
    setZoom,
    fitWidth,
    scrollToTop(top: number) {
      el.viewport.scrollTop = offsets().top + (scene.extent.y1 - top) * cssPerUnit(zoom);
      repaint();
    },
    reveal(box: Box) {
      const s = cssPerUnit(zoom);
      const { left, top } = offsets();
      const x0 = left + (box.x0 - scene.extent.x0) * s;
      const x1 = left + (box.x1 - scene.extent.x0) * s;
      const y0 = top + (scene.extent.y1 - box.y1) * s;
      const y1 = top + (scene.extent.y1 - box.y0) * s;
      const { scrollLeft, scrollTop, clientWidth, clientHeight } = el.viewport;
      const visible = x0 >= scrollLeft && x1 <= scrollLeft + clientWidth && y0 >= scrollTop && y1 <= scrollTop + clientHeight;
      if (visible) return;
      el.viewport.scrollLeft = (x0 + x1) / 2 - clientWidth / 2;
      el.viewport.scrollTop = (y0 + y1) / 2 - clientHeight / 2;
      repaint();
    },
    pageAt,
    unitsPerCss: (px: number) => px / cssPerUnit(zoom),
    repaint,
  };
}
