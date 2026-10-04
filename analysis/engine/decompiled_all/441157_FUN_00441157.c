// FUN_00441157 @ 00441157 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


int FUN_00441157(int *param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (((float)(&ITEM_P1)[*param_1] != f_16) || (DAT_020b9444 != (float)(&ITEM_P2)[*param_1])) {
    iVar1 = 2;
  }
  if (DAT_020b9448 != (float)(&ITEM_P3)[*param_1]) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}


