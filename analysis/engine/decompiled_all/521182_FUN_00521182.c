// FUN_00521182 @ 00521182 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00521182(void)

{
  int iVar1;
  
  _DAT_01a1fea8 = DAT_01a1fea4 - DAT_01f95c88 * DAT_01a1fea4;
  DAT_01a1feac = 1;
  for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_01a1feb0 = (&DAT_020492a4)[DAT_01a1feac];
    if (DAT_01a1feb0 < 0) {
      DAT_01a1feb0 = -DAT_01a1feb0;
    }
    (&ITEM_LEN)[DAT_01a1feb0] = DAT_01f95c88 * (float)(&ITEM_LEN)[DAT_01a1feb0] + _DAT_01a1fea8;
    DAT_01a1feac = DAT_01a1feac + 1;
  }
  return;
}


