// FUN_0050ddf0 @ 0050ddf0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0050ddf0(void)

{
  int iVar1;
  
  DAT_01a9f300 = (int)ROUND(P16);
  iVar1 = *(int *)(&DAT_01a9e21c + CUR_STAFF * 4);
  if (DAT_01a9f300 == 0) {
    if (iVar1 == 99) {
      DAT_01a9f310 = iVar1;
      return;
    }
    DAT_01a9f310 = iVar1 + 2;
    if (STEP != DAT_01f95ce0) {
      DAT_01a9f310 = iVar1 + 1;
    }
  }
  else {
    DAT_01a9f310 = DAT_01a9f300;
    if (DAT_01a9f300 == 99) {
      if (iVar1 == 99) {
        DAT_01a9f310 = iVar1;
        return;
      }
      DAT_01a9f310 = iVar1;
      if (iVar1 == 0) {
        return;
      }
    }
  }
  if (DAT_01a9f310 != 0) {
    thunk_FUN_004d4ed2(&DAT_01a9f310);
  }
  return;
}


