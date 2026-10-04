// FUN_0054c419 @ 0054c419 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c419(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  DAT_009a2360 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(param_1 + -4 + DAT_009a2360 * 4) = 0;
    DAT_009a2360 = DAT_009a2360 + 1;
  }
  return;
}


