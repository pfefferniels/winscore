// WinScore's "Score input" dialog: staff, input range and the five passes
// of the IN procedure, checked as you type by score-input in Rust.
import { InputLine, type Score } from './wasm/score_web.js';

export interface InputDialog {
  /** Opens the dialog for `score`; resolves with the line to insert, or null when cancelled. */
  ask(score: Score): Promise<InputLine | null>;
}

const PASSES = [1, 2, 3, 4, 5];

export function createInputDialog(dialog: HTMLDialogElement): InputDialog {
  const field = <T extends HTMLElement>(id: string) => dialog.querySelector<T>(`#${id}`)!;
  const staff = field<HTMLInputElement>('input-staff');
  const begin = field<HTMLInputElement>('input-begin');
  const end = field<HTMLInputElement>('input-end');
  const passes = PASSES.map((n) => field<HTMLInputElement>(`pass-${n}`));
  const errors = PASSES.map((n) => field<HTMLElement>(`pass-error-${n}`));
  const status = field<HTMLElement>('input-status');
  const insert = field<HTMLButtonElement>('input-insert');
  let score: Score | null = null;
  let failure: { pass: number; start: number; end: number } | null = null;

  const line = () =>
    new InputLine(
      passes.map((p) => p.value),
      Number(staff.value),
      Number(begin.value),
      Number(end.value),
    );

  const check = () => {
    if (!score) return;
    const current = line();
    const result = score.checkInput(current);
    current.free();
    failure = result.pass > 0 ? { pass: result.pass, start: result.start, end: result.end } : null;
    passes.forEach((p, i) => p.classList.toggle('invalid', failure?.pass === i + 1));
    errors.forEach((e, i) => (e.textContent = failure?.pass === i + 1 ? result.message : ''));
    status.textContent = failure ? '' : `Adds ${result.items} item${result.items === 1 ? '' : 's'}`;
    insert.disabled = failure !== null || result.items === 0;
    result.free();
  };

  const showFailure = () => {
    if (!failure) return;
    const input = passes[failure.pass - 1]!;
    input.focus();
    input.setSelectionRange(failure.start, Math.max(failure.end, failure.start + 1));
  };

  [staff, begin, end, ...passes].forEach((input) => input.addEventListener('input', check));
  passes.forEach((input, i) =>
    input.addEventListener('keydown', (e) => {
      if (e.key !== 'Enter') return;
      e.preventDefault();
      const next = passes[i + 1];
      if (next) next.focus();
      else if (!insert.disabled) dialog.close('insert');
      else showFailure();
    }),
  );

  return {
    ask(target) {
      score = target;
      staff.value = String((target.highestStaff() ?? 0) + 1);
      check();
      dialog.returnValue = '';
      dialog.showModal();
      passes[0]!.focus();
      return new Promise((resolve) => {
        dialog.addEventListener(
          'close',
          () => {
            resolve(dialog.returnValue === 'insert' && !failure ? line() : null);
            score = null;
          },
          { once: true },
        );
      });
    },
  };
}
