// FUN_0055ad81 @ 0055ad81 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


int FUN_0055ad81(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = *param_2;
  DAT_009a3cbc = 1;
  for (; 0 < iVar2; iVar2 = iVar2 + -1) {
    if (*(float *)(&DAT_01f942fc + DAT_009a3cbc * 4) == *param_1) {
      iVar1 = iVar1 + 1;
    }
    DAT_009a3cbc = DAT_009a3cbc + 1;
  }
  return iVar1;
}


