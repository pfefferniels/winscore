// FUN_0054e546 @ 0054e546 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054e546(float *param_1,float *param_2)

{
  int iVar1;
  
  *param_1 = f_0;
  *param_2 = f_999;
  DAT_009a2aec = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_009a2ae8 = (&ITEM_PTR0)[DAT_009a2aec];
    if ((float)(&ITEM_P1)[DAT_009a2ae8] == f_8) {
      if (*param_1 < (float)(&ITEM_P2)[DAT_009a2ae8]) {
        *param_1 = (float)(&ITEM_P2)[DAT_009a2ae8];
      }
      if ((float)(&ITEM_P2)[DAT_009a2ae8] < *param_2) {
        *param_2 = (float)(&ITEM_P2)[DAT_009a2ae8];
      }
    }
    DAT_009a2aec = DAT_009a2aec + 1;
  }
  return;
}


