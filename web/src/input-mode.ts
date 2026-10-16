// Music input as WinScore's IN command takes it (staff, input range and the
// five passes), typed at a cursor in the music: the line is drawn on the page
// as score-input reads it, a caret (pass 1) or a box over the notes (passes
// 2-5) shows where the keys go, and a bubble beside it shows what is being
// typed. The panel below the page shows the passes as SCORE text, for
// reference, and help on the keys that can follow.
import { InputLine, inputItemNotes, type Score } from './wasm/score_web.js';
import { decode, type Box, type DisplayList } from './display';
import { Draft, PASS_COUNT } from './input-draft';
import { cursorHelp, helpFor, type Help } from './input-help';
import type { Point } from './view';

/** What the page shows of the line being typed. */
export interface Shown {
  /** The new items, drawn as they would stand in the score. */
  list: DisplayList;
  /** Items drawn in the cursor's colour: what is being typed, or the notes it applies to. */
  focus: number[];
  /** A page box to scroll into view. */
  reveal: Box | null;
}

export interface InputHooks {
  score(): Score | null;
  /** Draws the line on the page, or removes it (null). */
  show(shown: Shown | null): void;
  /** Inserts the line; true when it was inserted. */
  insert(line: InputLine): boolean;
  /** Gives the keyboard back to the page. */
  focusPage(): void;
  /** Where a page box is on the screen. */
  clientRect(box: Box): DOMRect;
}

export interface InputMode {
  readonly isOpen: boolean;
  /** Opens the input, on `staff` if given; a line typed earlier is kept. */
  open(staff?: number): void;
  close(): void;
  /** The score changed (an edit, undo, another file): draws the line again. */
  refresh(): void;
  /** Places the caret and bubble again after the page moved. */
  layout(): void;
  /** A click at page point `at`: true when it fell on the input staff and moved the cursor. */
  click(at: Point, extend: boolean): boolean;
}

const PASS_NAMES = ['Notes', 'Rhythms', 'Marks', 'Beams', 'Slurs'];
const PROMPTS = ['type a note, rest, barline …', 'type a length', 'type a mark', 'beam: / or + - or a number', 'slur: / or + - or a number'];

/** One element of the line, as the preview lists them. */
interface Element {
  start: number;
  end: number;
  slot: number;
  note: number;
  x: number;
  description: string;
}

interface Layout {
  elements: Element[];
  boundaries: number[];
  bottom: number;
  top: number;
  begin: number;
  end: number;
  notes: number;
  needed: number;
  given: number;
}

/** score-input's message without the pass it names: "column 8: unexpected "S"". */
function brief(message: string): string {
  return message.replace(/^pass \d \(\w+\), /, '');
}

function isFormField(target: EventTarget | null): boolean {
  return target instanceof HTMLInputElement || target instanceof HTMLTextAreaElement || target instanceof HTMLSelectElement;
}

function readLayout(elements: Float64Array, descriptions: string[], boundaries: Int32Array, geometry: Float64Array, notes: number, needed: number, given: number): Layout {
  const list = Array.from({ length: elements.length / 5 }, (_, i) => {
    const [start = 0, end = 0, slot = 0, note = 0, x = 0] = elements.subarray(5 * i, 5 * i + 5);
    return { start, end, slot, note, x, description: descriptions[i] ?? '' };
  });
  const [bottom = 0, top = 0, begin = 0, end = 0] = geometry;
  return { elements: list, boundaries: Array.from(boundaries), bottom, top, begin, end, notes, needed, given };
}

/** Elements made before boundary `k`, from the nearest known boundary at or before it. */
function before(layout: Layout, k: number): number {
  for (let j = Math.min(k, layout.boundaries.length - 1); j >= 0; j--) {
    const count = layout.boundaries[j]!;
    if (count >= 0) return Math.min(count, layout.elements.length);
  }
  return 0;
}

function renderHelp(box: HTMLElement, help: Help, status: { text: string; kind: 'error' | 'note' | '' }) {
  const parts: HTMLElement[] = [Object.assign(document.createElement('h3'), { textContent: help.title })];
  if (help.detail) parts.push(Object.assign(document.createElement('p'), { className: 'help-detail', textContent: help.detail }));
  if (status.text) parts.push(Object.assign(document.createElement('p'), { className: `help-status ${status.kind}`, textContent: status.text }));
  if (help.hints.length > 0) {
    const list = document.createElement('dl');
    list.className = 'help-keys';
    help.hints.forEach((h) => {
      const keys = document.createElement('dt');
      h.keys.forEach((k) => keys.append(k === '…' ? document.createTextNode('…') : Object.assign(document.createElement('kbd'), { textContent: k })));
      list.append(keys, Object.assign(document.createElement('dd'), { textContent: h.text }));
    });
    parts.push(list);
  }
  box.replaceChildren(...parts);
}

export function createInputMode(panel: HTMLElement, overlay: HTMLElement, hooks: InputHooks): InputMode {
  const field = <T extends HTMLElement>(id: string) => panel.querySelector<T>(`#${id}`)!;
  const staff = field<HTMLInputElement>('input-staff');
  const begin = field<HTMLInputElement>('input-begin');
  const end = field<HTMLInputElement>('input-end');
  const rows = Array.from({ length: PASS_COUNT }, (_, n) => field<HTMLElement>(`pass-${n + 1}`));
  const codes = Array.from({ length: PASS_COUNT }, (_, n) => field<HTMLElement>(`pass-code-${n + 1}`));
  const errors = Array.from({ length: PASS_COUNT }, (_, n) => field<HTMLElement>(`pass-error-${n + 1}`));
  const status = field<HTMLElement>('input-status');
  const insertButton = field<HTMLButtonElement>('input-insert');
  const closeButton = field<HTMLButtonElement>('input-close');
  const help = field<HTMLElement>('input-help');

  const caret = Object.assign(document.createElement('div'), { className: 'input-caret', hidden: true });
  const bubble = Object.assign(document.createElement('div'), { className: 'input-bubble', hidden: true });
  overlay.append(caret, bubble);

  const draft = new Draft();
  let open = false;
  let frame = 0;
  let reveal = true;
  let layout: Layout | null = null;
  /** The caret (a thin box, pass 1) or the box over the notes at the cursor, in page units. */
  let cursorBox: Box | null = null;
  let barCaret = true;
  let failure: { pass: number; start: number; end: number } | null = null;

  const itemNotes = (pass: number, item: string) => Array.from(inputItemNotes(pass, item, draft.notes));

  const line = (texts: string[]) => new InputLine(texts, Number(staff.value), Number(begin.value), Number(end.value));

  /** The staff's line spacing and a note head's width, in page units. */
  const spacing = (l: Layout) => Math.max(1, (l.top - l.bottom) / 4);

  /** x of the caret before boundary `k` of pass 1. */
  const caretX = (l: Layout, k: number) => {
    const space = spacing(l);
    const head = 1.3 * space;
    const count = before(l, k);
    const previous = l.elements[count - 1];
    const next = l.elements[count];
    if (previous && next) return (previous.x + head + next.x) / 2;
    if (previous) return previous.x + head + space;
    if (next) return next.x - space;
    return l.begin;
  };

  /** The box over elements, the height of the staff with room above and below. */
  const boxOver = (l: Layout, chosen: Element[]): Box => {
    const space = spacing(l);
    const xs = chosen.map((e) => e.x);
    return { x0: Math.min(...xs) - 0.6 * space, x1: Math.max(...xs) + 1.9 * space, y0: l.bottom - 2.5 * space, y1: l.top + 2.5 * space };
  };

  const barAt = (l: Layout, x: number): Box => {
    const space = spacing(l);
    return { x0: x - space / 8, x1: x + space / 8, y0: l.bottom - 2.5 * space, y1: l.top + 2.5 * space };
  };

  /** The elements the cursor is on, and the box or caret that shows it. */
  const locate = (l: Layout): { chosen: Element[]; box: Box; bar: boolean } => {
    const p = draft.pass;
    const at = draft.position();
    const typing = draft.pending.trim() !== '';
    if (p === 0) {
      const chosen = typing ? l.elements.slice(before(l, at), before(l, at + 1)) : [];
      return { chosen, box: barAt(l, caretX(l, typing ? at + 1 : at)), bar: true };
    }
    if (p === 1) {
      const all = l.given === -1 && at === 0 && draft.items[1]!.length <= 1;
      const shown = draft.shownItems(1).length;
      const first = before(l, at) + 1;
      const last = at < shown ? Math.max(first, before(l, at + 1)) : first;
      const chosen = l.elements.filter((e) => e.slot > 0 && (all || (e.slot >= first && e.slot <= last)));
      if (chosen.length > 0) return { chosen, box: boxOver(l, chosen), bar: false };
      const lastElement = l.elements.at(-1);
      return { chosen, box: barAt(l, lastElement ? lastElement.x + 2.3 * spacing(l) : l.begin), bar: true };
    }
    const { from, to } = draft.selection();
    const chosen = l.elements.filter((e) => e.note >= from && e.note <= to);
    if (chosen.length > 0) return { chosen, box: boxOver(l, chosen), bar: false };
    return { chosen, box: barAt(l, l.begin), bar: true };
  };

  const renderCodes = () => {
    for (let p = 0; p < PASS_COUNT; p++) {
      const items = draft.shownItems(p);
      const active = p === draft.pass;
      const at = draft.position();
      const typing = active && draft.showsPending();
      const marked = !active ? -1 : p === 0 ? (typing ? at : -1) : p === 1 ? at : typing ? items.length - 1 : -1;
      const parts: Node[] = [];
      const caretMark = () => Object.assign(document.createElement('span'), { className: 'code-caret' });
      items.forEach((item, i) => {
        if (i > 0) parts.push(document.createTextNode('/'));
        if (active && p === 0 && !typing && i === at) parts.push(caretMark());
        const span = Object.assign(document.createElement('span'), { textContent: item });
        if (i === marked) span.className = typing ? 'code-pending' : 'code-current';
        parts.push(span);
        if (active && p === 0 && typing && i === at) parts.push(caretMark());
      });
      if (active && p === 0 && !typing && at >= items.length) parts.push(caretMark());
      if (active && p === 1 && at >= items.length) parts.push(...(items.length ? [document.createTextNode('/')] : []), caretMark());
      parts.push(document.createTextNode(';'));
      codes[p]!.replaceChildren(...parts);
      rows[p]!.classList.toggle('active', active);
    }
  };

  const update = () => {
    frame = 0;
    const score = hooks.score();
    if (!open || !score) return;
    const current = line(draft.texts());
    const preview = score.previewInput(current, draft.pass + 1);
    current.free();
    let shownList: DisplayList;
    try {
      layout = readLayout(preview.elements, preview.descriptions, preview.boundaries, preview.geometry, preview.notes, preview.needed, preview.given);
      draft.notes = preview.notes;
      failure = preview.pass > 0 ? { pass: preview.pass, start: preview.start, end: preview.end } : null;
      // An item cut short in the pass being typed is not finished yet rather than a mistake.
      const typing = failure !== null && failure.pass === draft.pass + 1 && preview.unfinished;
      rows.forEach((row, i) => row.classList.toggle('invalid', failure?.pass === i + 1 && !typing));
      errors.forEach((e, i) => (e.textContent = failure?.pass === i + 1 && !typing ? brief(preview.message) : ''));
      const items = preview.items;
      status.textContent = failure ? '' : items === 0 ? 'Nothing to insert yet' : `Adds ${items} item${items === 1 ? '' : 's'}`;
      insertButton.disabled = failure !== null || items === 0;

      let note: { text: string; kind: 'error' | 'note' | '' } = { text: '', kind: '' };
      if (failure && failure.pass !== draft.pass + 1) note = { text: `Pass ${failure.pass} (${PASS_NAMES[failure.pass - 1]}), ${brief(preview.message)}`, kind: 'error' };
      else if (typing) note = { text: 'Not finished yet.', kind: 'note' };
      else if (failure) note = { text: `Not valid: ${brief(preview.message)}`, kind: 'error' };
      else if (preview.erased.length > 0) {
        const erased = preview.erased;
        const notesText = draft.texts()[0]!;
        const names = Array.from({ length: erased.length / 2 }, (_, i) => notesText.slice(erased[2 * i], erased[2 * i + 1]).replace(/[/,;\s]+$/, ''));
        note = { text: `Not items, left out as WinScore erases them: ${names.join(', ')}`, kind: 'note' };
      } else if (layout.needed > 0 && layout.given >= 0 && layout.given < layout.needed) {
        const missing = layout.needed - layout.given;
        if (draft.pass === 0 && layout.given === 0) note = { text: 'Shown as quarters until pass 2 gives the lengths.', kind: '' };
        else if (draft.pass < 2) note = { text: `${missing} of ${layout.needed} without a length yet, shown as quarters.`, kind: '' };
        else note = { text: `Pass 2 gives ${layout.given} of ${layout.needed} lengths: the others become grace notes.`, kind: 'note' };
      }

      const facts = { notes: layout.notes, needed: layout.needed, given: layout.given };
      const at = draft.position();
      const sel = draft.selection();
      // Passes 1 and 2 read like text: the help sees the pass up to the cursor.
      const upToCursor = [...draft.items[draft.pass]!.slice(0, at), draft.pending].join('/');
      const helpText =
        draft.pass < 2
          ? helpFor(draft.pass + 1, upToCursor, upToCursor.length, facts)
          : cursorHelp(draft.pass + 1, draft.pending, { ...sel, repeat: draft.repeat[draft.pass]! }, facts);
      renderHelp(help, helpText, note);
      renderCodes();

      const { chosen, box, bar } = locate(layout);
      cursorBox = box;
      barCaret = bar;
      renderBubble(chosen);
      const encoded = preview.list();
      try {
        shownList = decode(encoded);
      } finally {
        encoded.free();
      }
      hooks.show({ list: shownList, focus: chosen.flatMap((e) => Array.from({ length: e.end - e.start }, (_, i) => e.start + i)), reveal: reveal ? box : null });
      reveal = false;
    } finally {
      preview.free();
    }
    place();
  };

  const renderBubble = (chosen: Element[]) => {
    const p = draft.pass;
    const pass = Object.assign(document.createElement('span'), { className: 'bubble-pass', textContent: `${p + 1} ${PASS_NAMES[p]}` });
    const text = document.createElement('code');
    text.className = 'bubble-text';
    if (draft.pending) text.textContent = draft.pending;
    else text.append(Object.assign(document.createElement('span'), { className: 'bubble-prompt', textContent: PROMPTS[p]! }));
    text.append(Object.assign(document.createElement('i'), { className: 'bubble-caret' }));
    const head = Object.assign(document.createElement('div'), { className: 'bubble-line' });
    head.append(pass, text);
    const said = chosen.map((e) => e.description).filter(Boolean);
    const words =
      said.length > 0
        ? `${said.slice(0, 3).join(' · ')}${said.length > 3 ? ` … (${said.length})` : ''}`
        : p === 0 && layout
          ? (() => {
              const previous = layout.elements[before(layout, draft.position()) - 1];
              return previous ? `after ${previous.description}` : 'at the start of the line';
            })()
          : '';
    const shown = Object.assign(document.createElement('div'), { className: 'bubble-shown', textContent: words });
    bubble.replaceChildren(head, ...(words ? [shown] : []));
  };

  /** Puts the caret and bubble over the page where the cursor is. */
  const place = () => {
    const visible = open && cursorBox !== null;
    caret.hidden = !visible;
    bubble.hidden = !visible;
    if (!visible || !cursorBox) return;
    const origin = overlay.getBoundingClientRect();
    const r = hooks.clientRect(cursorBox);
    caret.classList.toggle('bar', barCaret);
    Object.assign(caret.style, {
      left: `${r.left - origin.left}px`,
      top: `${r.top - origin.top}px`,
      width: `${Math.max(2, r.width)}px`,
      height: `${r.height}px`,
    });
    const width = bubble.offsetWidth;
    const height = bubble.offsetHeight;
    const left = Math.max(4, Math.min(origin.width - width - 4, r.left - origin.left));
    const above = r.top - origin.top - height - 6;
    const top = above >= 4 ? above : r.bottom - origin.top + 6;
    Object.assign(bubble.style, { left: `${left}px`, top: `${top}px` });
  };

  const schedule = () => {
    if (frame === 0) frame = requestAnimationFrame(update);
  };

  /** Reads the line now rather than at the next frame. */
  const updateNow = () => {
    if (frame !== 0) cancelAnimationFrame(frame);
    update();
  };

  const insert = () => {
    draft.commit();
    updateNow();
    if (insertButton.disabled) return;
    const current = line(draft.texts());
    let inserted = false;
    try {
      inserted = hooks.insert(current);
    } finally {
      current.free();
    }
    if (!inserted) return;
    draft.clear();
    staff.value = String((hooks.score()?.highestStaff() ?? 0) + 1);
    reveal = true;
    schedule();
  };

  const close = () => {
    if (!open) return;
    open = false;
    panel.hidden = true;
    place();
    hooks.show(null);
    hooks.focusPage();
  };

  const onKey = (e: KeyboardEvent) => {
    if (!open || isFormField(e.target) || document.querySelector('dialog[open]')) return;
    const command = e.metaKey || e.ctrlKey;
    switch (e.key) {
      case 'Enter':
        if (command) insert();
        else draft.goto(draft.pass + (e.shiftKey ? -1 : 1));
        break;
      case 'Tab':
        draft.goto(draft.pass + (e.shiftKey ? -1 : 1));
        break;
      case 'ArrowUp':
      case 'ArrowDown':
        draft.goto(draft.pass + (e.key === 'ArrowUp' ? -1 : 1));
        break;
      case 'ArrowLeft':
      case 'ArrowRight':
        draft.move(e.key === 'ArrowLeft' ? -1 : 1, e.shiftKey);
        break;
      case 'Home':
      case 'End':
        draft.moveTo(e.key === 'End', e.shiftKey);
        break;
      case 'Backspace':
        draft.erase(itemNotes, command || e.altKey);
        break;
      case 'Delete':
        draft.remove(itemNotes);
        break;
      case 'Escape':
        if (draft.pending) draft.pending = '';
        else close();
        break;
      default:
        if (e.key.length !== 1 || command || e.altKey) return;
        if (draft.type(e.key) === 'pass') draft.goto(draft.pass + 1);
    }
    e.preventDefault();
    e.stopImmediatePropagation();
    reveal = true;
    schedule();
  };
  window.addEventListener('keydown', onKey, true);

  [staff, begin, end].forEach((input) => {
    input.addEventListener('input', () => {
      reveal = true;
      schedule();
    });
    input.addEventListener('keydown', (e) => {
      if (e.key === 'Enter' || e.key === 'Escape') {
        e.preventDefault();
        hooks.focusPage();
      }
    });
  });
  rows.forEach((row, p) =>
    row.addEventListener('click', () => {
      draft.goto(p);
      hooks.focusPage();
      reveal = true;
      schedule();
    }),
  );
  if (!/Mac|iPhone|iPad/.test(navigator.platform)) {
    panel.querySelectorAll('kbd').forEach((k) => (k.textContent = k.textContent!.replace('⌘', 'Ctrl ')));
    insertButton.title = 'Insert the line (Ctrl+Enter)';
  }
  insertButton.addEventListener('click', () => {
    insert();
    hooks.focusPage();
  });
  closeButton.addEventListener('click', close);

  return {
    get isOpen() {
      return open;
    },
    open(target) {
      const score = hooks.score();
      if (!score) return;
      if (target !== undefined) staff.value = String(target);
      else if (!open && draft.empty) staff.value = String((score.highestStaff() ?? 0) + 1);
      open = true;
      panel.hidden = false;
      reveal = true;
      hooks.focusPage();
      schedule();
    },
    close,
    refresh() {
      if (open) schedule();
    },
    layout: place,
    click(at, extend) {
      const l = layout;
      if (!open || !l) return false;
      const space = spacing(l);
      if (at.y < l.bottom - 4 * space || at.y > l.top + 4 * space || at.x < l.begin - 6 * space || at.x > l.end + 6 * space) return false;
      const nearest = (candidates: Element[]) =>
        candidates.reduce<Element | null>((best, e) => (!best || Math.abs(e.x + 0.6 * space - at.x) < Math.abs(best.x + 0.6 * space - at.x) ? e : best), null);
      const p = draft.pass;
      if (p === 0) {
        const count = draft.shownItems(0).length;
        let best = 0;
        for (let k = 1; k <= count; k++) if (Math.abs(caretX(l, k) - at.x) < Math.abs(caretX(l, best) - at.x)) best = k;
        draft.place(best);
      } else if (p === 1) {
        const target = nearest(l.elements.filter((e) => e.slot > 0));
        if (target) {
          const shown = draft.shownItems(1).length;
          let k = 0;
          while (k < shown && before(l, k + 1) < target.slot) k++;
          draft.place(k);
        }
      } else {
        const target = nearest(l.elements.filter((e) => e.note > 0));
        if (target) draft.place(target.note, extend);
      }
      hooks.focusPage();
      schedule();
      return true;
    },
  };
}
