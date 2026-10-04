// FUN_00582b96 @ 00582b96 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00582b96(int *param_1)

{
  int iVar1;
  
  if (((ITEM_I < 1) || (DAT_020527e8 == 0)) || (P1 == f_8)) {
    *param_1 = 1;
    DAT_009a9084 = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_009a9088 = (&ITEM_PTR0)[DAT_009a9084];
      if (((float)(&ITEM_P1)[DAT_009a9088] == f_8) &&
         ((float)*param_1 < (float)(&ITEM_P2)[DAT_009a9088])) {
        *param_1 = (int)ROUND((float)(&ITEM_P2)[DAT_009a9088]);
      }
      DAT_009a9084 = DAT_009a9084 + 1;
    }
    if ((P1 == f_8) && (0 < ITEM_I)) {
      *param_1 = *param_1 + 1;
    }
    if (*param_1 == 0) {
      *param_1 = 1;
    }
  }
  else {
    DAT_009a9088 = (&ITEM_PTR0)[DAT_020527e8];
    *param_1 = (int)ROUND((float)(&ITEM_P2)[DAT_009a9088]);
  }
  return;
}


