// FUN_00473228 @ 00473228 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00473228(int *param_1)

{
  int iVar1;
  
  for (iVar1 = 1; iVar1 < 0x101; iVar1 = iVar1 + 1) {
    *(float *)(&DAT_01be1320 + iVar1 * 4) = f_0;
  }
  _DAT_01be1320 = *param_1;
  DAT_00824fd4 = (&ITEM_PTR0)[*param_1];
  DAT_00824fd0 = (int)ROUND((float)(&ITEM_LEN)[DAT_00824fd4]);
  DAT_00824fcc = 1;
  for (iVar1 = DAT_00824fd0 + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(&DAT_01be1320 + DAT_00824fcc * 4) = (&ITEM_LEN)[DAT_00824fd4];
    DAT_00824fd4 = DAT_00824fd4 + 1;
    DAT_00824fcc = DAT_00824fcc + 1;
  }
  return;
}


