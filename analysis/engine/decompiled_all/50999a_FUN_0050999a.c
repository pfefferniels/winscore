// FUN_0050999a @ 0050999a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0050999a(int param_1)

{
  int iVar1;
  
  iVar1 = 0x1f;
  DAT_0094042c = 1;
  while (((*(char *)(param_1 + -1 + DAT_0094042c) != '0' ||
          (*(char *)(param_1 + -2 + DAT_0094042c) != ' ')) ||
         (*(char *)(param_1 + DAT_0094042c) != ' '))) {
    DAT_0094042c = DAT_0094042c + 1;
    iVar1 = iVar1 + -1;
    if (iVar1 < 1) {
      return;
    }
  }
  *(undefined1 *)(param_1 + -1 + DAT_0094042c) = 0;
  return;
}


