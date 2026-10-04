// FUN_0045da56 @ 0045da56 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0045da56(void)

{
  int iVar1;
  
  iVar1 = 0xb;
  DAT_008242ec = 0xc;
  while( true ) {
    if (*(char *)(DAT_008242ec + 0x1beabbf) == '\0') {
      *(undefined1 *)(DAT_008242ec + 0x1beabbf) = 0x20;
    }
    if (*(char *)(DAT_008242ec + 0x1beabbf) == '.') break;
    DAT_008242ec = DAT_008242ec + -1;
    iVar1 = iVar1 + -1;
    if (iVar1 < 1) {
      return;
    }
  }
  if (DAT_008242ec == 9) {
    return;
  }
  DAT_008242ec = DAT_008242ec + 3;
  iVar1 = 4;
  DAT_008242e8 = 0xc;
  do {
    *(undefined1 *)(DAT_008242e8 + 0x1beabbf) = *(undefined1 *)(DAT_008242ec + 0x1beabbf);
    *(undefined1 *)(DAT_008242ec + 0x1beabbf) = 0x20;
    DAT_008242ec = DAT_008242ec + -1;
    DAT_008242e8 = DAT_008242e8 + -1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


