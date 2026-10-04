// FUN_00441091 @ 00441091 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00441091(int param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  _DAT_007f7d34 = 0xd;
  if (*(float *)(&ITEM_P14 + *param_3 * 4) == f_m1) {
    _DAT_007f7d34 = 0x10;
  }
  DAT_007f7d30 = (*param_3 + _DAT_007f7d34) * 4 + 1;
  iVar2 = *param_4 + 1;
  iVar3 = (*param_4 - iVar2) + 4;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  for (iVar1 = 1; iVar1 <= iVar3; iVar1 = iVar1 + 1) {
    *(undefined1 *)(param_1 + -1 + iVar2) = 0x20;
    iVar2 = iVar2 + 1;
  }
  thunk_FUN_0054c5f8(param_1,1,DAT_007f7d30 + 0x205343f,1,param_4);
  return;
}


