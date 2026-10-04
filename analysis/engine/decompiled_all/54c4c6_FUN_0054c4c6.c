// FUN_0054c4c6 @ 0054c4c6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c4c6(int param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_3;
  DAT_009a2368 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(param_2 + -4 + DAT_009a2368 * 4) =
         *(undefined4 *)(param_1 + -4 + DAT_009a2368 * 4);
    DAT_009a2368 = DAT_009a2368 + 1;
  }
  return;
}


