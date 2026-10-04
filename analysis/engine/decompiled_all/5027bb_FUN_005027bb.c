// FUN_005027bb @ 005027bb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_005027bb(float *param_1,float *param_2,undefined4 *param_3)

{
  int iVar1;
  
  *param_3 = 1;
  DAT_009029e0 = 1;
  iVar1 = ITEM_I;
  while( true ) {
    if (iVar1 < 1) {
      return;
    }
    DAT_009029dc = (&ITEM_PTR0)[DAT_009029e0];
    if (((float)(&ITEM_P1)[DAT_009029dc] == f_8) &&
       (DAT_01fb8c60 == (float)(&ITEM_P2)[DAT_009029dc])) break;
    DAT_009029e0 = DAT_009029e0 + 1;
    iVar1 = iVar1 + -1;
  }
  DAT_009029d8 = (int)ROUND((float)(&ITEM_LEN)[DAT_009029dc]);
  *param_1 = f_0;
  if (2 < DAT_009029d8) {
    *param_1 = (float)(&ITEM_P3)[DAT_009029dc];
  }
  *param_2 = f_200;
  if (DAT_009029d8 < 6) {
    return;
  }
  if ((float)(&ITEM_P6)[DAT_009029dc] == f_0) {
    return;
  }
  *param_2 = (float)(&ITEM_P6)[DAT_009029dc];
  return;
}


