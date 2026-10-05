// A palette of WinScore's toolbar commands, sent to score-edit as SCORE
// command lines; the symbol and text buttons open the shell's dialogs, as
// WinScore's open its own. Command strings and tooltips come from WinScore's
// command table, looked up by menu id.
import { commandById } from './commands';

interface Entry {
  /** WinScore's menu/toolbar id. */
  id: number;
  label: string;
  /** Opens a dialog of the shell instead of sending the command (WinScore opens one too). */
  dialog?: DialogKind;
}

export type DialogKind = 'symbol' | 'text';

interface Group {
  name: string;
  /** Whether the commands act on the item in edit mode (the selection). */
  needsSelection: boolean;
  /** Group-edit commands, which ask for an area outside edit mode. */
  area?: boolean;
  entries: Entry[];
}

/** WinScore's Items menu (codes 1-18), clefs, durations, and edit-mode buttons. */
const GROUPS: Group[] = [
  {
    name: 'Items',
    needsSelection: false,
    entries: [
      { id: 32855, label: 'Note' },
      { id: 32702, label: 'Rest' },
      { id: 32700, label: 'Clef' },
      { id: 32797, label: 'Line' },
      { id: 32856, label: 'Slur' },
      { id: 32698, label: 'Beam' },
      { id: 32696, label: 'Trill' },
      { id: 32857, label: 'Staff' },
      { id: 32694, label: 'Symbol', dialog: 'symbol' },
      { id: 32692, label: 'Number' },
      { id: 32690, label: 'Box' },
      { id: 32688, label: 'Circle' },
      { id: 32858, label: 'Guitar' },
      { id: 32686, label: 'Bar' },
      { id: 32860, label: 'Text', dialog: 'text' },
      { id: 32859, label: 'Key' },
      { id: 32682, label: 'Meter' },
    ],
  },
  {
    name: 'Clefs',
    needsSelection: false,
    entries: [
      { id: 32871, label: 'Treble' },
      { id: 32868, label: 'Bass' },
      { id: 32870, label: 'Alto' },
      { id: 32869, label: 'Tenor' },
      { id: 32875, label: 'Perc.' },
    ],
  },
  {
    name: 'Notes',
    needsSelection: false,
    entries: [
      { id: 32920, label: 'Whole' },
      { id: 32921, label: 'Half' },
      { id: 32922, label: '8th' },
      { id: 32924, label: '16th' },
      { id: 32925, label: 'W rest' },
      { id: 32926, label: 'H rest' },
      { id: 32927, label: '8 rest' },
      { id: 32928, label: '16 rest' },
    ],
  },
  {
    name: 'Edit',
    needsSelection: true,
    entries: [
      { id: 32716, label: 'L1' },
      { id: 32717, label: 'R1' },
      { id: 32721, label: 'U1' },
      { id: 32722, label: 'D1' },
      { id: 32864, label: 'Flip' },
      { id: 32865, label: 'Center' },
      { id: 32745, label: 'C' },
      { id: 32746, label: 'CC' },
      { id: 32737, label: 'Abort' },
      { id: 32704, label: 'Delete' },
      { id: 32779, label: 'Undelete' },
      { id: 32786, label: 'Prev' },
      { id: 32787, label: 'Next' },
    ],
  },
  {
    name: 'Layout',
    needsSelection: false,
    area: true,
    entries: [
      { id: 33751, label: 'Line up' },
      { id: 33752, label: 'Justify' },
      { id: 33319, label: 'LJ' },
      { id: 34126, label: 'LJ all' },
      { id: 33762, label: 'Transpose' },
    ],
  },
  {
    name: 'Area',
    needsSelection: false,
    area: true,
    entries: [
      { id: 33094, label: 'Move area' },
      { id: 33096, label: 'Copy area' },
      { id: 33098, label: 'Delete area' },
      { id: 34237, label: 'Alter area' },
      { id: 34125, label: 'Copy to staves' },
    ],
  },
];

export interface PaletteHandlers {
  run(command: string): void;
  /** Group edits leave edit mode first; the area may come from a drawn box. */
  runArea(command: string): void;
  open(dialog: DialogKind): void;
  supported(command: string): boolean;
}

export interface Palette {
  /** Enables the buttons that apply with or without a selection. */
  refresh(hasSelection: boolean): void;
}

interface Button {
  element: HTMLButtonElement;
  /** The SCORE command, or null for a shell dialog. */
  command: string | null;
  needsSelection: boolean;
}

function button(entry: Entry, group: Group, handlers: PaletteHandlers): Button | null {
  const found = commandById(entry.id);
  if (!found) return null;
  const element = document.createElement('button');
  element.type = 'button';
  element.textContent = entry.label;
  element.title = `${found.tooltip || found.command} — ${found.command}`;
  const { dialog } = entry;
  const act = dialog
    ? () => handlers.open(dialog)
    : group.area
      ? () => handlers.runArea(found.command)
      : () => handlers.run(found.command);
  element.addEventListener('click', act);
  return { element, command: dialog ? null : found.command, needsSelection: group.needsSelection };
}

export function createPalette(container: HTMLElement, handlers: PaletteHandlers): Palette {
  const buttons: Button[] = [];
  container.replaceChildren(
    ...GROUPS.map((group) => {
      const section = document.createElement('div');
      section.className = 'palette-group';
      section.setAttribute('role', 'group');
      section.setAttribute('aria-label', group.name);
      const made = group.entries.map((entry) => button(entry, group, handlers)).filter((b): b is Button => b !== null);
      buttons.push(...made);
      section.append(...made.map((b) => b.element));
      return section;
    }),
  );
  return {
    refresh(hasSelection) {
      buttons.forEach((b) => {
        const supported = b.command === null || handlers.supported(b.command);
        b.element.disabled = !supported || (b.needsSelection && !hasSelection);
        b.element.classList.toggle('unsupported', !supported);
      });
    },
  };
}
