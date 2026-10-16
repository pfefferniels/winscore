// Music input as WinScore's IN command takes it (staff, input range and the
// five passes), in a panel below the page instead of a dialog: as you type,
// score-input's reading of the line is drawn on the page, the note or other
// item at the caret is marked, and the help beside the passes says what the
// text means so far and which keys can follow.
import { InputLine, type Score } from './wasm/score_web.js';
import { decode, type DisplayList } from './display';
import { helpFor, type Help } from './input-help';

/** What the page shows of the line being typed. */
export interface Shown {
  /** The new items, drawn as they would stand in the score. */
  list: DisplayList;
  /** Item indices (in `list`'s sources) of the elements at the caret. */
  focus: number[];
  /** What the page should scroll into view: the whole line (on opening, a new staff), the caret's item (after typing), or nothing. */
  reveal: 'line' | 'caret' | null;
}

export interface InputHooks {
  score(): Score | null;
  /** Draws the line on the page, or removes it (null). */
  show(shown: Shown | null): void;
  /** Inserts the line; true when it was inserted. */
  insert(line: InputLine): boolean;
  /** After the panel closed: the keyboard goes back to the page. */
  closed(): void;
}

export interface InputMode {
  readonly isOpen: boolean;
  /** Opens the panel, on `staff` if given; a line typed earlier is kept. */
  open(staff?: number): void;
  close(): void;
  /** The score changed (an edit, undo, another file): draws the line again. */
  refresh(): void;
  /** A key typed on the page while the panel is open goes into the current pass. */
  type(key: string): void;
}

const PASSES = [1, 2, 3, 4, 5];

/** score-input's message without the pass it names: "column 8: unexpected "S"". */
function brief(message: string): string {
  return message.replace(/^pass \d \(\w+\), /, '');
}
const PASS_NAMES = ['Notes', 'Rhythms', 'Marks', 'Beams', 'Slurs'];

/**
 * A pass as it is inserted: typed text up to `;`, which is added when missing.
 * Without a typed `;` a trailing `/` is the start of an item not typed yet,
 * so it is left out (`/;` would repeat the item before it).
 */
export function finished(text: string): string {
  if (text.includes(';')) return text;
  return `${text.trimEnd().replace(/[/,]$/, '').trimEnd()};`;
}

function renderHelp(box: HTMLElement, help: Help, described: string[], status: { text: string; kind: 'error' | 'note' | '' }) {
  const parts: HTMLElement[] = [];
  if (described.length > 0) {
    const shown = document.createElement('p');
    shown.className = 'help-shown';
    const swatch = document.createElement('i');
    swatch.className = 'swatch focus';
    const more = described.length > 4 ? ` … (${described.length})` : '';
    shown.append(swatch, document.createTextNode(`${described.slice(0, 4).join(' · ')}${more}`));
    parts.push(shown);
  }
  parts.push(Object.assign(document.createElement('h3'), { textContent: help.title }));
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

export function createInputMode(panel: HTMLElement, hooks: InputHooks): InputMode {
  const field = <T extends HTMLElement>(id: string) => panel.querySelector<T>(`#${id}`)!;
  const staff = field<HTMLInputElement>('input-staff');
  const begin = field<HTMLInputElement>('input-begin');
  const end = field<HTMLInputElement>('input-end');
  const passes = PASSES.map((n) => field<HTMLInputElement>(`pass-${n}`));
  const rows = passes.map((p) => p.closest<HTMLElement>('.pass')!);
  const errors = PASSES.map((n) => field<HTMLElement>(`pass-error-${n}`));
  const status = field<HTMLElement>('input-status');
  const insertButton = field<HTMLButtonElement>('input-insert');
  const closeButton = field<HTMLButtonElement>('input-close');
  const help = field<HTMLElement>('input-help');
  let open = false;
  let active = 0;
  let frame = 0;
  let reveal: Shown['reveal'] = 'line';
  let failure: { pass: number; start: number; end: number } | null = null;

  const line = () =>
    new InputLine(
      passes.map((p) => finished(p.value)),
      Number(staff.value),
      Number(begin.value),
      Number(end.value),
    );

  const activate = (index: number) => {
    active = index;
    rows.forEach((row, i) => row.classList.toggle('active', i === index));
  };

  const update = () => {
    frame = 0;
    const score = hooks.score();
    if (!open || !score) return;
    const input = passes[active]!;
    const caret = input.selectionStart ?? input.value.length;
    const current = line();
    const preview = score.previewInput(current, active + 1, caret);
    current.free();
    try {
      failure = preview.pass > 0 ? { pass: preview.pass, start: preview.start, end: preview.end } : null;
      // An item cut short in the pass being typed is not finished yet rather than a mistake.
      const typing = failure !== null && failure.pass === active + 1 && preview.unfinished;
      passes.forEach((p, i) => p.classList.toggle('invalid', failure?.pass === i + 1 && !typing));
      errors.forEach((e, i) => (e.textContent = failure?.pass === i + 1 && !typing ? brief(preview.message) : ''));
      const items = preview.items;
      status.textContent = failure ? '' : items === 0 ? 'Nothing to insert yet' : `Adds ${items} item${items === 1 ? '' : 's'}`;
      insertButton.disabled = failure !== null || items === 0;

      const facts = { notes: preview.notes, needed: preview.needed, given: preview.given };
      let note: { text: string; kind: 'error' | 'note' | '' } = { text: '', kind: '' };
      if (failure && failure.pass !== active + 1) note = { text: `Pass ${failure.pass} (${PASS_NAMES[failure.pass - 1]}), ${brief(preview.message)}`, kind: 'error' };
      else if (typing) note = { text: 'Not finished yet.', kind: 'note' };
      else if (failure) note = { text: `Not valid: ${brief(preview.message)}`, kind: 'error' };
      else if (preview.erased.length > 0) {
        const erased = preview.erased;
        const names = Array.from({ length: erased.length / 2 }, (_, i) => passes[0]!.value.slice(erased[2 * i], erased[2 * i + 1]).replace(/[/,\s]+$/, ''));
        note = { text: `Not items, left out as WinScore erases them: ${names.join(', ')}`, kind: 'note' };
      } else if (facts.needed > 0 && facts.given >= 0 && facts.given < facts.needed) {
        const missing = facts.needed - facts.given;
        if (active === 0 && facts.given === 0) note = { text: 'Shown as quarters until pass 2 gives the lengths.', kind: '' };
        else if (active < 2) note = { text: `${missing} of ${facts.needed} without a length yet, shown as quarters.`, kind: '' };
        else note = { text: `Pass 2 gives ${facts.given} of ${facts.needed} lengths: the others become grace notes.`, kind: 'note' };
      }
      renderHelp(help, helpFor(active + 1, input.value, caret, facts), preview.described, note);
      const encoded = preview.list();
      try {
        hooks.show({ list: decode(encoded), focus: Array.from(preview.focus), reveal });
      } finally {
        encoded.free();
      }
      reveal = null;
    } finally {
      preview.free();
    }
  };

  const schedule = () => {
    if (frame === 0) frame = requestAnimationFrame(update);
  };

  const focusPass = (index: number) => {
    const input = passes[Math.max(0, Math.min(passes.length - 1, index))]!;
    input.focus();
    input.setSelectionRange(input.value.length, input.value.length);
  };

  const showFailure = () => {
    if (!failure) return;
    const input = passes[failure.pass - 1]!;
    input.focus();
    input.setSelectionRange(failure.start, Math.max(failure.end, failure.start + 1));
  };

  const insert = () => {
    // Check the text as it is now, not as the last frame saw it.
    if (frame !== 0) {
      cancelAnimationFrame(frame);
      update();
    }
    if (insertButton.disabled) {
      showFailure();
      return;
    }
    const current = line();
    let inserted = false;
    try {
      inserted = hooks.insert(current);
    } finally {
      current.free();
    }
    if (!inserted) return;
    passes.forEach((p) => (p.value = ''));
    staff.value = String((hooks.score()?.highestStaff() ?? 0) + 1);
    reveal = 'line';
    focusPass(0);
    schedule();
  };

  const close = () => {
    if (!open) return;
    open = false;
    panel.hidden = true;
    hooks.show(null);
    hooks.closed();
  };

  [staff, begin, end].forEach((input) =>
    input.addEventListener('input', () => {
      reveal = 'line';
      schedule();
    }),
  );
  passes.forEach((input, i) => {
    input.addEventListener('focus', () => {
      activate(i);
      schedule();
    });
    input.addEventListener('input', () => {
      reveal ??= 'caret';
      schedule();
    });
    ['keyup', 'click', 'select'].forEach((type) => input.addEventListener(type, schedule));
    input.addEventListener('keydown', (e) => {
      if (e.key === 'Enter' && (e.metaKey || e.ctrlKey)) {
        e.preventDefault();
        insert();
      } else if (e.key === 'Enter' && e.shiftKey) {
        e.preventDefault();
        focusPass(i - 1);
      } else if (e.key === 'Enter') {
        e.preventDefault();
        if (i < passes.length - 1) focusPass(i + 1);
        else insert();
      } else if (e.key === 'ArrowUp' || e.key === 'ArrowDown') {
        e.preventDefault();
        focusPass(i + (e.key === 'ArrowUp' ? -1 : 1));
      }
    });
  });
  panel.addEventListener('keydown', (e) => {
    if (e.defaultPrevented) return;
    if (e.key === 'Escape') {
      e.preventDefault();
      close();
    } else if (e.key === 'Enter' && (e.metaKey || e.ctrlKey) && !(e.target instanceof HTMLButtonElement)) {
      e.preventDefault();
      insert();
    }
  });
  if (!/Mac|iPhone|iPad/.test(navigator.platform)) {
    panel.querySelectorAll('kbd').forEach((k) => (k.textContent = k.textContent!.replace('⌘', 'Ctrl ')));
    insertButton.title = 'Insert the line (Ctrl+Enter)';
  }
  insertButton.addEventListener('click', insert);
  closeButton.addEventListener('click', close);
  activate(0);

  return {
    get isOpen() {
      return open;
    },
    open(target) {
      const score = hooks.score();
      if (!score) return;
      const fresh = passes.every((p) => p.value.trim() === '');
      if (target !== undefined) staff.value = String(target);
      else if (!open && fresh) staff.value = String((score.highestStaff() ?? 0) + 1);
      open = true;
      panel.hidden = false;
      reveal = 'line';
      focusPass(active);
      schedule();
    },
    close,
    refresh() {
      if (open) schedule();
    },
    type(key) {
      const input = passes[active]!;
      const at = input.selectionStart ?? input.value.length;
      input.setRangeText(key, at, input.selectionEnd ?? at, 'end');
      input.focus();
      input.dispatchEvent(new Event('input'));
    },
  };
}
