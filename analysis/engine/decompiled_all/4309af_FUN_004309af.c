// FUN_004309af @ 004309af (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall
FUN_004309af(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
            int *param_6)

{
  int iVar1;
  undefined4 local_14;
  
  DAT_007f1434 = *param_6;
  DAT_020b8e6c = (uint)*(byte *)(DAT_020b8e60 + param_3);
  iVar1 = *param_6;
  _DAT_020b8e64 = 1;
  do {
    if (iVar1 < 1) {
      local_14 = 0;
LAB_00430a55:
      return CONCAT44(param_2,local_14);
    }
    if ((uint)*(byte *)(DAT_020b8e60 + param_3) == *(uint *)(param_5 + -4 + _DAT_020b8e64 * 4)) {
      local_14 = 1;
      goto LAB_00430a55;
    }
    param_2 = 0;
    _DAT_020b8e64 = _DAT_020b8e64 + 1;
    iVar1 = iVar1 + -1;
  } while( true );
}


