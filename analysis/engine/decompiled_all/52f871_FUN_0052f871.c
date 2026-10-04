// FUN_0052f871 @ 0052f871 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0052f871(float *param_1)

{
  int iVar1;
  
  DAT_0099a104 = (int)ROUND(*param_1);
  for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
    *(float *)(&P0 + iVar1 * 4) = f_0;
  }
  LOAD_I = 1;
  iVar1 = ITEM_I;
  while( true ) {
    if (iVar1 < 1) {
      return;
    }
    load_item_header();
    if ((LOAD_CODE == 8) && (DAT_0099a104 == LOAD_STAFF)) break;
    LOAD_I = LOAD_I + 1;
    iVar1 = iVar1 + -1;
  }
  DAT_0099a100 = 1;
  LOAD_CODE = 8;
  for (iVar1 = LOAD_LEN; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(&P0 + DAT_0099a100 * 4) = (&ITEM_LEN)[DAT_0099a100 + LOAD_W];
    DAT_0099a100 = DAT_0099a100 + 1;
  }
  return;
}


