// FUN_004b6593 @ 004b6593 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b6593(float *param_1)

{
  int iVar1;
  
  DAT_0089f498 = 1;
  for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_0089f494 = (&DAT_020492a4)[DAT_0089f498];
    if (DAT_0089f494 < 0) {
      DAT_0089f494 = -DAT_0089f494;
    }
    if ((DAT_0089f494 != 0) &&
       (_DAT_0089f490 = (float)(&ITEM_LEN)[DAT_0089f494], *param_1 <= _DAT_0089f490)) {
      (&ITEM_LEN)[DAT_0089f494] = _DAT_01b11764 + _DAT_0089f490;
    }
    DAT_0089f498 = DAT_0089f498 + 1;
  }
  return;
}


