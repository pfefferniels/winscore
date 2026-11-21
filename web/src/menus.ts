// The editor's commands, as menus of entries (menu.ts), listed by the `?`
// dialog. Entries that send SCORE commands take the command and its tooltip
// from WinScore's command table by menu id, as WinScore's own menus and
// toolbars send them, and show the command beside them. Commands score-edit
// does not handle are left out. Insert lists the insertion modes of the
// toolbar, with their keys.
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
  /** Save As, in the desktop app. */
  saveAs?: () => void;
  /** Saves every page with unsaved changes. */
  saveAll(): void;
  /** The open pages (pages.ts), in their order. */
  pages(): { name: string; modified: boolean; current: boolean; show(): void }[];
  /** An empty page after the one shown. */
  newPage(): void;
  /** .mus files as pages after the one shown. */
  addPages(): void;
  closePage(): void;
  /** The previous (−1) or next (+1) page. */
  stepPage(step: 1 | -1): void;
  /** Whether this is the desktop app, which saves to files rather than downloading them. */
  desktop: boolean;
  exportSvg(): void;
  print(): void;
  undo(): void;
  redo(): void;
  cut(): void;
  copy(): void;
  paste(): void;
  /** Whether something was copied to paste. */
  canPaste(): boolean;
  duplicate(): void;
  selectAll(): void;
  undoLabel(): string | null;
  redoLabel(): string | null;
  zoomIn(): void;
  zoomOut(): void;
  fitWidth(): void;
  actualSize(): void;
  panelShown(): boolean;
  togglePanel(): void;
  shortcuts(): void;
  /** How AI assistants reach the desktop app (MCP). */
  mcp?: () => void;
  /** The toolbar's insertion modes. */
  tools(): { id: string; key: string; label: string; title: string }[];
  /** The mode in force; null while selecting. */
  tool(): string | null;
  chooseTool(id: string | null): void;
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

export function appMenus(hooks: MenuHooks): Menu[] {
  const scored = () => hooks.hasScore();
  const selected = () => hooks.hasScore() && hooks.hasSelection();
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
        { label: 'Open…', hint: `${MOD}O`, title: 'Open .mus files: several chosen together are the pages of one score (or drop them on the window)', id: 'open', run: hooks.open },
        { heading: 'Samples' },
        ...hooks.samples().map((s): Action => ({ label: s.title, id: `sample:${s.title}`, run: s.open })),
        'separator',
        { label: 'Save', hint: `${MOD}S`, title: hooks.desktop ? 'Save the page shown to its file' : 'Download the page shown as a .mus file', id: 'save', run: hooks.save, enabled: scored },
        hooks.saveAs ? { label: 'Save as…', hint: `⇧${MOD}S`, title: 'Save the page shown to another file', id: 'save-as', run: hooks.saveAs, enabled: scored } : null,
        {
          label: 'Save all pages',
          hint: MOD === '⌘' ? '⌥⌘S' : 'Ctrl+Alt+S',
          title: hooks.desktop ? 'Save every page with unsaved changes, each to its file' : 'Download every page with unsaved changes, each as a .mus file',
          id: 'save-all',
          run: hooks.saveAll,
          enabled: () => scored() && hooks.pages().some((p) => p.modified),
        },
        { label: 'Export SVG', title: 'The page shown as printed, without staff numbers', id: 'export-svg', run: hooks.exportSvg, enabled: scored },
        { label: 'Print…', hint: `${MOD}P`, title: 'Print every page (without staff numbers)', id: 'print', run: hooks.print, enabled: scored },
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
        { label: 'Cut', hint: `${MOD}X`, title: 'Copy the selected items and delete them', id: 'cut', run: hooks.cut, enabled: selected },
        { label: 'Copy', hint: `${MOD}C`, title: 'Copy the selected items, to paste them here or into another score', id: 'copy', run: hooks.copy, enabled: selected },
        {
          label: 'Paste',
          hint: `${MOD}V`,
          title: 'Paste the copied items where you clicked last, else where they were copied (beside them if they are still there)',
          id: 'paste',
          run: hooks.paste,
          enabled: () => scored() && hooks.canPaste(),
        },
        { label: 'Duplicate', hint: `${MOD}D`, title: 'Copies of the selected items, ten spaces to the right', id: 'duplicate', run: hooks.duplicate, enabled: selected },
        { label: 'Select all', hint: `${MOD}A`, title: 'Select every item of the score', id: 'select-all', run: hooks.selectAll, enabled: scored },
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
        { heading: 'Modes: a click puts one on the page' },
        {
          label: 'Select',
          hint: 'V',
          title: 'Select and edit items; Esc in a mode comes back here',
          id: 'tool:select',
          run: () => hooks.chooseTool(null),
          checked: () => hooks.tool() === null,
          enabled: scored,
        },
        ...hooks.tools().map(
          (t): Action => ({
            label: t.label,
            hint: t.key.toUpperCase(),
            title: t.title,
            id: `tool:${t.id}`,
            run: () => hooks.chooseTool(t.id),
            checked: () => hooks.tool() === t.id,
            enabled: scored,
          }),
        ),
        'separator',
        { heading: 'By numbers' },
        dialog('text', 'Text…', 'Text in one of WinScore’s fonts, at a staff and position typed in'),
        dialog('symbol', 'Symbol…', 'A symbol from WinScore’s libraries, at the selection'),
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

  const pages: Menu = {
    id: 'pages',
    label: 'Pages',
    entries: () => {
      const open = hooks.pages();
      const shown = () => hooks.pages().findIndex((p) => p.current);
      return tidy([
        { label: 'New page', title: 'An empty page after this one, a file of its own named by the next number', id: 'new-page', run: hooks.newPage, enabled: scored },
        { label: 'Add pages…', title: 'Open .mus files as pages after this one', id: 'add-pages', run: hooks.addPages, enabled: scored },
        { label: 'Close page', title: 'Close the page shown (its file stays as it is)', id: 'close-page', run: hooks.closePage, enabled: scored },
        'separator',
        { label: 'Previous page', hint: 'F2', title: 'Show the page before this one (SCORE’s NB)', id: 'previous-page', run: () => hooks.stepPage(-1), enabled: () => shown() > 0 },
        { label: 'Next page', hint: 'F3', title: 'Show the page after this one (SCORE’s NX)', id: 'next-page', run: () => hooks.stepPage(1), enabled: () => shown() >= 0 && shown() < hooks.pages().length - 1 },
        ...(open.length > 1 ? [{ heading: 'Open pages' } as Entry] : []),
        ...(open.length > 1
          ? open.map(
              (page, index): Action => ({
                label: `${index + 1}  ${page.name}${page.modified ? ' •' : ''}`,
                title: page.modified ? `${page.name}: unsaved changes` : page.name,
                id: `page:${index + 1}`,
                run: page.show,
                checked: () => hooks.pages()[index]?.current ?? false,
              }),
            )
          : []),
      ]);
    },
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
      { label: 'Commands, keys and gestures', hint: 'F1', id: 'shortcuts', run: hooks.shortcuts },
      ...(hooks.mcp ? [{ label: 'AI assistants (MCP)…', title: 'Let Claude Code and other assistants read and edit the open score', id: 'mcp', run: hooks.mcp }] : []),
    ],
  };

  return [file, pages, edit, insert, layout, view];
}
