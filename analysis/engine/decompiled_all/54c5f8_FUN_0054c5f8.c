// FUN_0054c5f8 @ 0054c5f8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c5f8(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  
  iVar1 = *param_5;
  DAT_009a2374 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(undefined1 *)(param_3 + -1 + DAT_009a2374) = *(undefined1 *)(param_1 + -1 + DAT_009a2374);
    DAT_009a2374 = DAT_009a2374 + 1;
  }
  return;
}


