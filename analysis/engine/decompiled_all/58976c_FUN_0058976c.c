// FUN_0058976c @ 0058976c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058976c(undefined1 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = 0x180;
  DAT_009a92cc = 0x180;
  while( true ) {
    if (param_1[DAT_009a92cc + -1] == ';') {
      return;
    }
    if (param_1[DAT_009a92cc + -1] == '/') break;
    param_1[DAT_009a92cc + -1] = 0x20;
    DAT_009a92cc = DAT_009a92cc + -1;
    iVar1 = iVar1 + -1;
    if (iVar1 < 1) {
      *param_1 = 0x3b;
      *param_3 = 1;
      return;
    }
  }
  param_1[DAT_009a92cc + -1] = 0x3b;
  *param_3 = DAT_009a92cc;
  return;
}


