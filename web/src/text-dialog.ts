// Text items (code 16): a dialog that creates them, as SCORE's quick entry
// `"text" staff P3 P4` does, and an editor for the characters of an existing
// one, placed over the text on the page. A font from WinScore's font menu
// goes in front of the text as its `_NN` code.
import { fontCodes, fontPrefix } from './commands';
import type { Place } from './editor';

export interface NewText {
  text: string;
  /** P2, P3, P4. */
  params: number[];
}

export interface TextDialog {
  /** Asks for a new text at `place`; resolves with it, or null when cancelled. */
  create(place: Place): Promise<NewText | null>;
}

/** A leading font code `_NN`, as SCORE reads it. */
const FONT_CODE = /^_\d\d/;

/** `text` in font `code` (−1 leaves it as typed). */
export function withFont(text: string, code: number): string {
  return code < 0 ? text : fontPrefix(code) + text.replace(FONT_CODE, '');
}

/** Fills a font menu: "as typed" first, then WinScore's fonts by number. */
export function fillFontMenu(select: HTMLSelectElement, label = 'Font as typed') {
  select.replaceChildren(new Option(label, '-1'), ...fontCodes().map((f) => new Option(`${fontPrefix(f.code)} ${f.name}`, String(f.code))));
}

export function createTextDialog(dialog: HTMLDialogElement): TextDialog {
  const field = <T extends HTMLElement>(id: string) => dialog.querySelector<T>(`#${id}`)!;
  const text = field<HTMLInputElement>('text-value');
  const font = field<HTMLSelectElement>('text-font');
  const staff = field<HTMLInputElement>('text-staff');
  const p3 = field<HTMLInputElement>('text-p3');
  const p4 = field<HTMLInputElement>('text-p4');
  const insert = field<HTMLButtonElement>('text-insert');
  fillFontMenu(font);

  text.addEventListener('input', () => (insert.disabled = text.value.trim() === ''));

  return {
    create(place) {
      text.value = '';
      insert.disabled = true;
      staff.value = String(place.staff);
      p3.value = String(place.p3);
      p4.value = String(place.p4);
      dialog.returnValue = '';
      dialog.showModal();
      text.focus();
      return new Promise((resolve) => {
        dialog.addEventListener(
          'close',
          () => {
            const done = dialog.returnValue === 'insert' && text.value.trim() !== '';
            resolve(done ? { text: withFont(text.value, Number(font.value)), params: [staff, p3, p4].map((f) => Number(f.value)) } : null);
          },
          { once: true },
        );
      });
    },
  };
}

/**
 * Edits `value` in a text field laid over `rect` (client coordinates) on
 * `host`; resolves with the new text on Enter or blur, null on Escape.
 */
export function editInPlace(host: HTMLElement, rect: DOMRect, value: string): Promise<string | null> {
  const input = document.createElement('input');
  input.className = 'text-in-place';
  input.value = value;
  input.spellcheck = false;
  const origin = host.getBoundingClientRect();
  Object.assign(input.style, {
    left: `${rect.left - origin.left - 4}px`,
    top: `${rect.top - origin.top - 4}px`,
    minWidth: `${Math.max(rect.width + 8, 160)}px`,
    height: `${Math.max(rect.height + 8, 28)}px`,
  });
  host.append(input);
  input.focus();
  input.select();
  return new Promise((resolve) => {
    let done = false;
    const finish = (result: string | null) => {
      if (done) return;
      done = true;
      input.remove();
      resolve(result);
    };
    input.addEventListener('keydown', (e) => {
      e.stopPropagation();
      if (e.key === 'Enter') finish(input.value);
      if (e.key === 'Escape') finish(null);
    });
    input.addEventListener('blur', () => finish(input.value));
  });
}
