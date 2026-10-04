// FUN_00502498 @ 00502498 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00502498(byte *param_1,undefined4 param_2,int *param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  
  thunk_FUN_0054c8e5(param_1,1,param_3);
  iVar1 = *param_3;
  DAT_009029cc = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    FUN_00502525(param_1 + DAT_009029cc + -1,1);
    DAT_009029cc = DAT_009029cc + 1;
  }
  *param_4 = (uint)*param_1;
  *param_5 = (uint)param_1[1];
  return;
}


