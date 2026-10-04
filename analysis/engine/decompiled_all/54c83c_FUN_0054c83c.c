// FUN_0054c83c @ 0054c83c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c83c(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  DAT_009a2390 = *param_3;
  iVar1 = *param_3;
  DAT_009a2394 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    if ((0x60 < *(byte *)(param_1 + -1 + DAT_009a2394)) &&
       (*(byte *)(param_1 + -1 + DAT_009a2394) < 0x7b)) {
      *(char *)(param_1 + -1 + DAT_009a2394) = *(char *)(param_1 + -1 + DAT_009a2394) + -0x20;
    }
    DAT_009a2394 = DAT_009a2394 + 1;
  }
  return;
}


