// FUN_0054c52c @ 0054c52c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c52c(int param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_3;
  DAT_009a236c = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined1 *)(param_2 + -1 + DAT_009a236c) = *(undefined1 *)(param_1 + -1 + DAT_009a236c);
    DAT_009a236c = DAT_009a236c + 1;
  }
  return;
}


