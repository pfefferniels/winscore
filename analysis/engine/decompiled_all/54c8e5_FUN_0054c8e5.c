// FUN_0054c8e5 @ 0054c8e5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c8e5(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = 0x200;
  *param_3 = 0x200;
  do {
    DAT_009a239c = *(char *)(param_1 + -1 + *param_3);
    if (' ' < DAT_009a239c) {
      iVar1 = *param_3;
      DAT_009a2398 = 1;
      while( true ) {
        if (iVar1 < 1) {
          return;
        }
        if (*(char *)(param_1 + DAT_009a2398) == '\0') break;
        DAT_009a2398 = DAT_009a2398 + 1;
        iVar1 = iVar1 + -1;
      }
      *param_3 = DAT_009a2398;
      return;
    }
    *param_3 = *param_3 + -1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  *param_3 = 0;
  return;
}


