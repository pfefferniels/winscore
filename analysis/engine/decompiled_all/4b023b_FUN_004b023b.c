// FUN_004b023b @ 004b023b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b023b(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = 0x18;
  *param_3 = 0x18;
  do {
    DAT_0089f1e4 = *(char *)(param_1 + -1 + *param_3);
    if (' ' < DAT_0089f1e4) {
      return;
    }
    *param_3 = *param_3 + -1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  *param_3 = 0;
  return;
}


