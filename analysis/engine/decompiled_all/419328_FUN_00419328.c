// FUN_00419328 @ 00419328 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00419328(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  DAT_007d149c = *param_2 - *param_1;
  if (DAT_007d149c != 0) {
    if (DAT_007d149c < 1) {
      DAT_007d1498 = *param_3;
      for (iVar1 = (ITEM_WORDS - DAT_007d1498) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_LEN)[DAT_007d149c + DAT_007d1498] = (&ITEM_LEN)[DAT_007d1498];
        DAT_007d1498 = DAT_007d1498 + 1;
      }
    }
    else {
      DAT_007d1498 = ITEM_WORDS;
      for (iVar1 = ((*param_3 - ITEM_WORDS) + -1) / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
        (&ITEM_LEN)[DAT_007d149c + DAT_007d1498] = (&ITEM_LEN)[DAT_007d1498];
        DAT_007d1498 = DAT_007d1498 + -1;
      }
    }
    DAT_007d1498 = *param_4;
    for (iVar1 = (ITEM_I - DAT_007d1498) + 2; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&ITEM_PTR0)[DAT_007d1498] = (&ITEM_PTR0)[DAT_007d1498] + DAT_007d149c;
      DAT_007d1498 = DAT_007d1498 + 1;
    }
    ITEM_WORDS = DAT_007d149c + ITEM_WORDS;
  }
  return;
}


