// FUN_005833a0 @ 005833a0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_005833a0(int *param_1)

{
  int iVar1;
  int local_10;
  
  if (*param_1 == 8) {
    *param_1 = 1;
    while (DAT_009a90c8 = 1, iVar1 = ITEM_I, 0 < ITEM_I) {
      while ((DAT_009a90b8 = (&ITEM_PTR0)[DAT_009a90c8] + 1, (float)(&ITEM_LEN)[DAT_009a90b8] != f_8
             || ((float)*param_1 != (float)(&ITEM_P1)[DAT_009a90b8]))) {
        DAT_009a90c8 = DAT_009a90c8 + 1;
        iVar1 = iVar1 + -1;
        if (iVar1 < 1) {
          return;
        }
      }
      *param_1 = *param_1 + 1;
    }
  }
  else {
    DAT_009a90c4 = 500000;
    *param_1 = 1;
    local_10 = 0x20;
    DAT_009a90c8 = 1;
    do {
      DAT_009a90b8 = (&STAFF_Y0)[DAT_009a90c8];
      DAT_009a90c0 = (DAT_01be6c44 - DAT_009a90b8 / DAT_01be6c4c) + -0x1ae;
      if (DAT_009a90c0 < 0) {
        DAT_009a90c0 = -DAT_009a90c0;
      }
      if (DAT_009a90c0 < DAT_009a90c4) {
        DAT_009a90c4 = DAT_009a90c0;
        *param_1 = DAT_009a90c8;
      }
      DAT_009a90c8 = DAT_009a90c8 + 1;
      local_10 = local_10 + -1;
    } while (0 < local_10);
  }
  return;
}


