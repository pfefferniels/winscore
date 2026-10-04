// FUN_004d9413 @ 004d9413 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


int FUN_004d9413(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (-1 < *param_2) {
    iVar1 = 6;
    iVar2 = 1;
    do {
      if (*param_1 == *(int *)(iVar2 * 4 + 0x7946e0)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (0 < iVar1);
  }
  return 0;
}


