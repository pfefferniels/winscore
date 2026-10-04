// FUN_0054c473 @ 0054c473 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c473(int param_1)

{
  int iVar1;
  
  iVar1 = 0xa0;
  DAT_009a2364 = 1;
  do {
    *(undefined1 *)(param_1 + -1 + DAT_009a2364) = 0x20;
    DAT_009a2364 = DAT_009a2364 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


