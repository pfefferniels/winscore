// A group command's question (WinScore's line-by-line dialogue of Move area,
// Copy to staves, Line up …) over the page while it waits for the answer.
// The mouse answers most of them: a box drawn for an area or a system, a
// click on a staff for a destination. Those that ask for numbers (staff
// numbers to copy to, the parameters Alter area changes) take them in the
// bar's field. Cancel, or Escape, ends the command without a change.

export interface QuestionHooks {
  /** Sends a typed answer, as WinScore's dialogue takes it. */
  answer(line: string): void;
  /** Ends the group command without a change. */
  cancel(): void;
  /** The keyboard goes back to the page. */
  left(): void;
}

export interface Question {
  /** Shows the question waiting (null: none), giving its field the keyboard with `focus`. */
  ask(question: string | null, focus: boolean): void;
  readonly open: boolean;
}

export function createQuestion(host: HTMLElement, hooks: QuestionHooks): Question {
  const text = Object.assign(document.createElement('span'), { className: 'question-text' });
  const input = Object.assign(document.createElement('input'), { className: 'question-answer', type: 'text', placeholder: 'Draw on the page, or type the answer', autocomplete: 'off', spellcheck: false });
  input.setAttribute('aria-label', 'Answer');
  const cancel = Object.assign(document.createElement('button'), { type: 'button', className: 'question-cancel', textContent: 'Cancel', title: 'End the command without a change (Esc)' });
  const bar = Object.assign(document.createElement('div'), { className: 'question', hidden: true });
  bar.setAttribute('role', 'dialog');
  bar.setAttribute('aria-label', 'Group command');
  bar.append(text, input, cancel);
  host.append(bar);
  let current: string | null = null;

  input.addEventListener('keydown', (e) => {
    e.stopPropagation();
    if (e.key === 'Enter' && input.value.trim()) {
      const line = input.value.trim();
      input.value = '';
      hooks.answer(line);
    } else if (e.key === 'Escape') {
      hooks.cancel();
      hooks.left();
    }
  });
  cancel.addEventListener('click', () => {
    hooks.cancel();
    hooks.left();
  });
  // Escape on the page ends it too.
  window.addEventListener('keydown', (e) => {
    if (current === null || e.key !== 'Escape' || document.querySelector('dialog[open]') || e.target === input) return;
    e.preventDefault();
    hooks.cancel();
  });

  return {
    ask(question, focus) {
      if (question === current) return;
      const had = current !== null;
      current = question;
      bar.hidden = question === null;
      text.textContent = question ?? '';
      if (question === null) {
        input.value = '';
        if (had && document.activeElement === input) hooks.left();
        return;
      }
      if (focus) input.focus();
    },
    get open() {
      return current !== null;
    },
  };
}
