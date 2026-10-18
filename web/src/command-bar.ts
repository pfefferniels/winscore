// WinScore's command bar: typing anywhere outside a form field goes into it
// (or into a field that takes it instead, the one by the selection), Enter
// runs the line, Up and Down recall earlier lines, Escape hands the keyboard
// back to the page.

export interface CommandBarHooks {
  run(line: string): void;
  /** Where the keyboard goes after Escape. */
  page: HTMLElement;
  /** A field that takes what is typed on the page instead of the bar, while there is one. */
  typing?(): HTMLInputElement | null;
}

/** Keys the page keeps for itself even though they print a character ([ and ] move staves, + and _ zoom). */
const PAGE_KEYS = new Set(['[', ']', '+', '=', '_']);

function isFormField(target: EventTarget | null): boolean {
  return target instanceof HTMLInputElement || target instanceof HTMLTextAreaElement || target instanceof HTMLSelectElement;
}

function startsCommand(e: KeyboardEvent): boolean {
  return e.key.length === 1 && e.key !== ' ' && !PAGE_KEYS.has(e.key) && !e.ctrlKey && !e.metaKey && !e.altKey;
}

export function bindCommandBar(input: HTMLInputElement, hooks: CommandBarHooks) {
  const history: string[] = [];
  let recalled = 0;

  const recall = (step: -1 | 1) => {
    recalled = Math.min(history.length, Math.max(0, recalled + step));
    input.value = history[history.length - recalled] ?? '';
    input.setSelectionRange(input.value.length, input.value.length);
  };

  input.addEventListener('keydown', (e) => {
    if (e.key === 'Enter') {
      const line = input.value.trim();
      if (!line) return;
      if (history.at(-1) !== line) history.push(line);
      recalled = 0;
      hooks.run(line);
      input.select();
    } else if (e.key === 'ArrowUp' || e.key === 'ArrowDown') {
      e.preventDefault();
      recall(e.key === 'ArrowUp' ? 1 : -1);
    } else if (e.key === 'Escape') {
      input.value = '';
      hooks.page.focus();
    }
  });

  window.addEventListener('keydown', (e) => {
    if (input.disabled || isFormField(e.target) || document.querySelector('dialog[open]') || !startsCommand(e)) return;
    e.preventDefault();
    const field = hooks.typing?.() ?? input;
    field.focus();
    field.value = e.key;
    if (field === input) recalled = 0;
    else field.dispatchEvent(new Event('input'));
  });
}
