// FUN_0054cd13 @ 0054cd13 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054cd13(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  DAT_009a23b4 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(float *)(param_1 + -4 + DAT_009a23b4 * 4) = f_0;
    DAT_009a23b4 = DAT_009a23b4 + 1;
  }
  return;
}


