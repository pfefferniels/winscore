// FUN_0054c590 @ 0054c590 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c590(int param_1,int param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = *param_3;
  DAT_009a2370 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined4 *)(param_2 + -4 + DAT_009a2370 * 4) =
         *(undefined4 *)(param_1 + -4 + DAT_009a2370 * 4);
    DAT_009a2370 = DAT_009a2370 + 1;
  }
  return;
}


