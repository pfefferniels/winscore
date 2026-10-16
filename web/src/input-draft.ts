// The line being typed in the music input, as SCORE's five passes hold it,
// with a cursor in it instead of a caret in five text fields.
//
// Each pass is a list of items, the texts between SCORE's `/` separators.
// What is being typed (`pending`) belongs to the cursor:
// - pass 1 (notes): the cursor stands between items, and the pending item is
//   inserted there;
// - pass 2 (rhythms): the cursor stands on a value, one per note, chord and
//   rest, and the pending value replaces it (at the end it is added);
// - passes 3-5 (marks, beams, slurs): the cursor stands on a note, with a
//   selection of notes from `anchor`, and the pending text is the mark (`S`,
//   `C-`) or the modifiers of a beam or slur (`+`, `-`, a number over it);
//   the note numbers come from the selection. A pending text with its own
//   numbers (`S 2:5`, `X3 1 4`, `2B`) is taken as typed.
// The pass texts sent to score-input are the items joined by `/`, with `;`.

export const PASS_COUNT = 5;

/** Marks drawn from one note to another, which take two note numbers. */
const SPANNING = new Set(['C', 'C+', 'C-', 'DC', 'O', 'OB', 'TRW', 'TRFW', 'TRSW', 'TRNW', 'TRILLW']);

/** The notes a pass-3, -4 or -5 item applies to (score-input's reading). */
export type ItemNotes = (pass: number, item: string) => number[];

export interface Selection {
  from: number;
  to: number;
}

export class Draft {
  /** 0 = notes … 4 = slurs. */
  pass = 0;
  readonly items: string[][] = Array.from({ length: PASS_COUNT }, () => []);
  /** Passes 1-2: item index; passes 3-5: note number (from 1). */
  readonly cursor: number[] = [0, 0, 1, 1, 1];
  /** Passes 3-5: the other end of the selection, if more than the cursor's note. */
  readonly anchor: (number | null)[] = [null, null, null, null, null];
  /** Passes 3-5: the last text placed with `/`, which `/` alone places again. */
  readonly repeat: string[] = ['', '', '', '', ''];
  pending = '';
  /** Notes and chords in the line, as the last preview counted them. */
  notes = 0;

  get empty(): boolean {
    return this.pending === '' && this.items.every((pass) => pass.length === 0);
  }

  /** The cursor of the current pass, kept inside its items or notes. */
  position(): number {
    const p = this.pass;
    const limit = p < 2 ? this.items[p]!.length : Math.max(1, this.notes);
    this.cursor[p] = Math.max(p < 2 ? 0 : 1, Math.min(limit, this.cursor[p]!));
    return this.cursor[p]!;
  }

  /** Passes 3-5: the selected notes. */
  selection(): Selection {
    const at = this.position();
    const other = this.anchor[this.pass] ?? at;
    return { from: Math.min(at, other), to: Math.max(at, other) };
  }

  /** The pending text as an item of the current pass, note numbers filled in. */
  pendingItem(): string {
    return this.itemFor(this.pending.trim());
  }

  /**
   * An item of the current pass from typed text and the selection. In passes 4 and 5
   * an empty text is a plain beam or slur over the selection.
   */
  itemFor(text: string): string {
    if (this.pass < 2 || (text === '' && this.pass === 2)) return text;
    const { from, to } = this.selection();
    if (this.pass === 2) {
      const m = /^([-+=]?)([A-Z]+\d*(?:[+-](?=$))?)$/.exec(text);
      if (!m || this.notes === 0) return text;
      return SPANNING.has(m[2]!) ? `${text} ${from} ${to > from ? to : from + 1}` : `${text} ${from === to ? from : `${from}:${to}`}`;
    }
    const m = /^([-+=]?)(\d*)$/.exec(text);
    if (!m || this.notes === 0) return text;
    const number = m[2] ? Number(m[2]) * 100 + from : from;
    return `${m[1]}${number} ${to > from ? to : from + 1}`;
  }

  /** Whether the current pass shows a pending item: text typed, or in passes 4-5 a selection. */
  showsPending(): boolean {
    return this.pending.trim() !== '' || (this.pass >= 3 && this.anchor[this.pass] !== null);
  }

  /** The items of a pass as they are sent: the pending item in its place. */
  shownItems(pass: number): string[] {
    const items = [...this.items[pass]!];
    if (pass !== this.pass || !this.showsPending()) return items;
    const at = this.position();
    if (pass === 0) items.splice(at, 0, this.pendingItem());
    else if (pass === 1) items.splice(at, at < items.length ? 1 : 0, this.pendingItem());
    else items.push(this.pendingItem());
    return items;
  }

  /** The five pass texts as score-input reads them. */
  texts(): string[] {
    return Array.from({ length: PASS_COUNT }, (_, p) => `${this.shownItems(p).join('/')};`);
  }

  /** A typed character: `/` and `,` end the item, `;` the pass; others go into the pending text. */
  type(key: string): 'item' | 'pass' | 'text' {
    if (key === '/' || key === ',') {
      this.commit(true);
      return 'item';
    }
    if (key === ';') {
      this.commit(false);
      return 'pass';
    }
    if (key === ' ' && this.pending === '') return 'text';
    this.pending += key.toUpperCase();
    return 'text';
  }

  /** Ends the pending item. With `slash` (a typed `/`) an empty one repeats as SCORE's `//` does. */
  commit(slash = false) {
    const p = this.pass;
    const at = this.position();
    const text = this.pending.trim();
    const items = this.items[p]!;
    if (p === 0) {
      if (text === '' && !slash) return;
      items.splice(at, 0, text);
      this.cursor[0] = at + 1;
    } else if (p === 1) {
      if (text !== '') {
        items.splice(at, at < items.length ? 1 : 0, text);
        this.cursor[1] = at + 1;
      } else if (slash) {
        if (at === items.length) items.push('');
        this.cursor[1] = at + 1;
      }
    } else {
      // `/` alone places what was placed last again; in passes 4-5 a plain beam or slur.
      const template = text !== '' ? text : slash ? this.repeat[p]! : null;
      if (template === null || (template === '' && p === 2)) return;
      const item = this.itemFor(template);
      items.push(item);
      this.repeat[p] = template;
      // Numbers from the selection: on to the note after it.
      if (item !== template) {
        this.cursor[p] = Math.min(Math.max(1, this.notes), this.selection().to + 1);
        this.anchor[p] = null;
      }
    }
    this.pending = '';
  }

  /** ← and →: to the next item or note; with `extend` (Shift) the selection grows in passes 3-5. */
  move(step: number, extend = false) {
    const p = this.pass;
    const editing = this.position();
    const typed = this.pending.trim() !== '';
    if (p < 2) this.commit();
    // A value just typed in pass 2 counts from its own note.
    const at = p === 1 && typed ? editing : this.position();
    if (p >= 2) this.anchor[p] = extend ? (this.anchor[p] ?? at) : null;
    this.cursor[p] = at + step;
    this.position();
    if (p >= 2 && this.anchor[p] === this.cursor[p]) this.anchor[p] = null;
  }

  /** Home and End. */
  moveTo(end: boolean, extend = false) {
    const p = this.pass;
    this.move(end ? Number.MAX_SAFE_INTEGER / 2 : -Number.MAX_SAFE_INTEGER / 2, extend);
    if (p >= 2) this.position();
  }

  /** Puts the cursor at an item (passes 1-2) or a note (passes 3-5). */
  place(position: number, extend = false) {
    const p = this.pass;
    if (p < 2) this.commit();
    if (p >= 2) this.anchor[p] = extend ? (this.anchor[p] ?? this.position()) : null;
    this.cursor[p] = position;
    this.position();
    if (p >= 2 && this.anchor[p] === this.cursor[p]) this.anchor[p] = null;
  }

  /**
   * Backspace: the last pending character; else, in pass 1 the last character of the
   * item before the cursor (`whole`: all of it), in pass 2 the value at the end or a step
   * back, in passes 3-5 the last item on the cursor's note.
   */
  erase(itemNotes: ItemNotes, whole = false) {
    if (this.pending !== '') {
      this.pending = whole ? '' : this.pending.slice(0, -1);
      return;
    }
    const p = this.pass;
    const at = this.position();
    const items = this.items[p]!;
    if (p === 0) {
      if (at === 0) return;
      const [item] = items.splice(at - 1, 1);
      this.cursor[0] = at - 1;
      if (!whole) this.pending = item!.slice(0, -1);
    } else if (p === 1) {
      if (at === 0) return;
      if (at === items.length) items.pop();
      this.cursor[1] = at - 1;
    } else {
      const notes = new Set(this.noteRange());
      for (let i = items.length - 1; i >= 0; i--) {
        if (itemNotes(p + 1, items[i]!).some((n) => notes.has(n))) {
          items.splice(i, 1);
          break;
        }
      }
    }
  }

  /** Delete: the item after the cursor (passes 1-2), or every item on the selected notes. */
  remove(itemNotes: ItemNotes) {
    const p = this.pass;
    const at = this.position();
    const items = this.items[p]!;
    if (p < 2) {
      if (at < items.length) items.splice(at, 1);
      return;
    }
    const notes = new Set(this.noteRange());
    const kept = items.filter((item) => !itemNotes(p + 1, item).some((n) => notes.has(n)));
    items.splice(0, items.length, ...kept);
  }

  /** Passes 3-5: the selected note numbers. */
  noteRange(): number[] {
    const { from, to } = this.selection();
    return Array.from({ length: to - from + 1 }, (_, i) => from + i);
  }

  /** Changes pass, ending the pending item first. */
  goto(pass: number) {
    this.commit();
    this.pending = '';
    this.pass = Math.max(0, Math.min(PASS_COUNT - 1, pass));
    // Rhythms are typed from where they end.
    if (this.pass === 1 && this.cursor[1] === 0) this.cursor[1] = this.items[1]!.length;
  }

  clear() {
    this.items.forEach((items) => (items.length = 0));
    this.cursor.splice(0, PASS_COUNT, 0, 0, 1, 1, 1);
    this.anchor.fill(null);
    this.repeat.fill('');
    this.pending = '';
    this.pass = 0;
  }
}
