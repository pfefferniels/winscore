// FUN_0045db4f @ 0045db4f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0045db4f(int param_1)

{
  int iVar1;
  
  iVar1 = 7;
  DAT_008242f4 = 2;
  do {
    if (*(char *)(DAT_008242f4 + param_1 + -1) == ' ') {
      iVar1 = 4;
      DAT_008242f0 = 9;
      do {
        *(undefined1 *)(DAT_008242f4 + param_1 + -1) = *(undefined1 *)(DAT_008242f0 + param_1 + -1);
        *(undefined1 *)(DAT_008242f0 + param_1 + -1) = 0x20;
        DAT_008242f4 = DAT_008242f4 + 1;
        DAT_008242f0 = DAT_008242f0 + 1;
        iVar1 = iVar1 + -1;
      } while (0 < iVar1);
      return;
    }
    DAT_008242f4 = DAT_008242f4 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


