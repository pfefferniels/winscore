// The app's menus. Entries that send SCORE commands take the command and
// its tooltip from WinScore's command table by menu id, as WinScore's own
// menus and toolbars send them, and show the command so it can be typed on
// the command bar next time. Commands score-edit does not handle are left out.
import { commandById } from './commands';
import { MOD, type Action, type Entry, type Menu } from './menu';

export type DialogKind = 'symbol' | 'text';

export interface MenuHooks {
  hasScore(): boolean;
  hasSelection(): boolean;
  /** Runs a SCORE command line on the selection. */
  run(command: string): void;
  /** Runs a command outside edit mode: group edits, which ask for an area a drawn box may give. */
  runArea(command: string): void;
  supported(command: string): boolean;
  openDialog(kind: DialogKind): void;
  newScore(): void;
  open(): void;
  samples(): { title: string; open(): void }[];
  save(): void;
  exportSvg(): void;
  print(): void;
  undo(): void;
  redo(): void;
  undoLabel(): string | null;
  redoLabel(): string | null;
  input(): void;
  zoomIn(): void;
  zoomOut(): void;
  fitWidth(): void;
  actualSize(): void;
  panelShown(): boolean;
  togglePanel(): void;
  shortcuts(): void;
}

/** How an entry sends its command. */
type Send = 'selection' | 'area' | 'any';

/** The entry for WinScore's menu id `id`, or null when score-edit cannot run its command. */
function scoreCommand(hooks: MenuHooks, id: number, label: string, send: Send = 'any', hint?: string): Action | null {
  const found = commandById(id);
  if (!found || !hooks.supported(found.command)) return null;
  return {
    label,
    hint: hint ?? found.command,
    title: `${found.tooltip || found.command} (${found.command})`,
    id: found.command,
    run: () => (send === 'area' ? hooks.runArea(found.command) : hooks.run(found.command)),
    enabled: () => hooks.hasScore() && (send !== 'selection' || hooks.hasSelection()),
  };
}

/** Entries, separators and headings without the commands that were left out, and without separators left dangling. */
function tidy(entries: (Entry | null)[]): Entry[] {
  const kept = entries.filter((e): e is Entry => e !== null && !(typeof e === 'object' && 'row' in e && e.actions.length === 0));
  return kept.filter((e, i) => {
    if (e !== 'separator' && !(typeof e === 'object' && 'heading' in e)) return true;
    const next = kept[i + 1];
    return i > 0 && next !== undefined && next !== 'separator';
  });
}

function row(label: string, actions: (Action | null)[]): Entry {
  return { row: label, actions: actions.filter((a): a is Action => a !== null) };
}

export function appMenus(hooks: MenuHooks): Menu[] {
  const scored = () => hooks.hasScore();
  const cmd = (id: number, label: string, send?: Send, hint?: string) => scoreCommand(hooks, id, label, send, hint);
  const dialog = (kind: DialogKind, label: string, title: string): Action => ({
    label,
    title,
    id: kind,
    run: () => hooks.openDialog(kind),
    enabled: scored,
  });

  const file: Menu = {
    id: 'file',
    label: 'File',
    entries: () =>
      tidy([
        { label: 'New score', title: 'Start from an empty page', id: 'new', run: hooks.newScore },
        { label: 'Open…', hint: `${MOD}O`, title: 'Open a .mus file (or drop one on the window)', id: 'open', run: hooks.open },
        { heading: 'Samples' },
        ...hooks.samples().map((s): Action => ({ label: s.title, id: `sample:${s.title}`, run: s.open })),
        'separator',
        { label: 'Save', hint: `${MOD}S`, title: 'Download the score as a .mus file', id: 'save', run: hooks.save, enabled: scored },
        { label: 'Export SVG', title: 'The page as printed, without staff numbers', id: 'export-svg', run: hooks.exportSvg, enabled: scored },
        { label: 'Print…', hint: `${MOD}P`, title: 'Print the page (without staff numbers)', id: 'print', run: hooks.print, enabled: scored },
      ]),
  };

  const edit: Menu = {
    id: 'edit',
    label: 'Edit',
    entries: () =>
      tidy([
        {
          label: () => (hooks.undoLabel() ? `Undo ${hooks.undoLabel()}` : 'Undo'),
          hint: `${MOD}Z`,
          id: 'undo',
          run: hooks.undo,
          enabled: () => hooks.undoLabel() !== null,
        },
        {
          label: () => (hooks.redoLabel() ? `Redo ${hooks.redoLabel()}` : 'Redo'),
          hint: MOD === '⌘' ? '⇧⌘Z' : 'Ctrl+Y',
          id: 'redo',
          run: hooks.redo,
          enabled: () => hooks.redoLabel() !== null,
        },
        'separator',
        cmd(32704, 'Delete', 'selection', 'Del'),
        cmd(32779, 'Undelete', 'area'),
        'separator',
        { heading: 'Selected item' },
        cmd(32864, 'Flip', 'selection'),
        cmd(32865, 'Center on note', 'selection'),
        cmd(32745, 'Keep a copy here', 'selection'),
        cmd(32746, 'Keep a copy, edit it', 'selection'),
        cmd(32737, 'Revert changes', 'selection'),
        cmd(32786, 'Previous item', 'selection', '⇧↵'),
        cmd(32787, 'Next item', 'selection', '↵'),
        'separator',
        { heading: 'Area (draw a box or type)' },
        cmd(33094, 'Move area…', 'area'),
        cmd(33096, 'Copy area…', 'area'),
        cmd(33098, 'Delete area…', 'area'),
        cmd(34237, 'Alter area…', 'area'),
        cmd(34125, 'Copy to staves…', 'area'),
      ]),
  };

  const insert: Menu = {
    id: 'insert',
    label: 'Insert',
    entries: () =>
      tidy([
        { label: 'Music input…', hint: 'IN', title: "Type a line of music in SCORE's five passes", id: 'input', run: hooks.input, enabled: scored },
        dialog('text', 'Text…', 'Text in one of WinScore’s fonts'),
        dialog('symbol', 'Symbol…', 'A symbol from WinScore’s libraries'),
        'separator',
        row('Note', [cmd(32920, 'Whole'), cmd(32921, 'Half'), cmd(32855, 'Quarter'), cmd(32922, '8th'), cmd(32924, '16th')]),
        row('Rest', [cmd(32925, 'Whole'), cmd(32926, 'Half'), cmd(32702, 'Quarter'), cmd(32927, '8th'), cmd(32928, '16th')]),
        row('Clef', [cmd(32871, 'Treble'), cmd(32868, 'Bass'), cmd(32870, 'Alto'), cmd(32869, 'Tenor'), cmd(32875, 'Perc.')]),
        'separator',
        cmd(32857, 'Staff'),
        cmd(32686, 'Bar line'),
        cmd(32859, 'Key signature'),
        cmd(32682, 'Meter'),
        'separator',
        cmd(32856, 'Slur'),
        cmd(32698, 'Beam'),
        cmd(32797, 'Line'),
        cmd(32696, 'Trill'),
        cmd(32692, 'Number'),
        cmd(32690, 'Box'),
        cmd(32688, 'Circle'),
        cmd(32858, 'Guitar grid'),
      ]),
  };

  const layout: Menu = {
    id: 'layout',
    label: 'Layout',
    entries: () =>
      tidy([
        cmd(33751, 'Line up…', 'area'),
        cmd(33752, 'Justify…', 'area'),
        cmd(33319, 'Line up and justify…', 'area'),
        cmd(34126, 'Line up and justify all', 'area'),
        'separator',
        cmd(33762, 'Transpose…', 'area'),
      ]),
  };

  const view: Menu = {
    id: 'view',
    label: 'View',
    entries: () => [
      { label: 'Zoom in', hint: '+', id: 'zoom-in', run: hooks.zoomIn, enabled: scored },
      { label: 'Zoom out', hint: '_', id: 'zoom-out', run: hooks.zoomOut, enabled: scored },
      { label: 'Fit width', id: 'fit', run: hooks.fitWidth, enabled: scored },
      { label: 'Actual size', id: 'actual-size', run: hooks.actualSize, enabled: scored },
      'separator',
      { label: 'Side panel', id: 'panel', run: hooks.togglePanel, checked: hooks.panelShown, enabled: scored },
      'separator',
      { label: 'Keys and gestures', hint: 'F1', id: 'shortcuts', run: hooks.shortcuts },
    ],
  };

  return [file, edit, insert, layout, view];
}
