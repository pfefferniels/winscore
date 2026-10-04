// FUN_00547ae0 @ 00547ae0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00547ae0(float *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  *param_3 = 1;
  DAT_0099f8f8 = 1;
  iVar1 = ITEM_I;
  while( true ) {
    if (iVar1 < 1) {
      return;
    }
    DAT_0099f8f4 = (&ITEM_PTR0)[DAT_0099f8f8];
    if (((float)(&ITEM_P1)[DAT_0099f8f4] == f_8) &&
       (DAT_01fb8c60 == (float)(&ITEM_P2)[DAT_0099f8f4])) break;
    DAT_0099f8f8 = DAT_0099f8f8 + 1;
    iVar1 = iVar1 + -1;
  }
  DAT_0099f8f0 = (int)ROUND((float)(&ITEM_LEN)[DAT_0099f8f4]);
  *param_1 = f_0;
  if (2 < DAT_0099f8f0) {
    *param_1 = (float)(&ITEM_P3)[DAT_0099f8f4];
  }
  *param_2 = DAT_01fbb8b8;
  if (DAT_0099f8f0 < 6) {
    return;
  }
  if ((float)(&ITEM_P6)[DAT_0099f8f4] == f_0) {
    return;
  }
  *param_2 = (&ITEM_P6)[DAT_0099f8f4];
  return;
}


