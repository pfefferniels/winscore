// FUN_0054c6b5 @ 0054c6b5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054c6b5(byte *param_1,undefined4 param_2,int *param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  
  FUN_0054c8e5(param_1,1,param_3);
  iVar2 = *param_3;
  DAT_009a2388 = 1;
  for (; 0 < iVar2; iVar2 = iVar2 + -1) {
    uVar1 = (uint)_DAT_009a2380 >> 8;
    _DAT_009a2380 = CONCAT31((int3)uVar1,param_1[DAT_009a2388 + -1]);
    FUN_0054c768(&DAT_009a2380);
    param_1[DAT_009a2388 + -1] = (byte)_DAT_009a2380;
    DAT_009a2388 = DAT_009a2388 + 1;
  }
  *param_4 = (uint)*param_1;
  *param_5 = (uint)param_1[1];
  return;
}


