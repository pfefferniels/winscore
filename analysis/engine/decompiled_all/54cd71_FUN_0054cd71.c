// FUN_0054cd71 @ 0054cd71 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054cd71(int param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  
  DAT_009a23b8 = *param_3;
  iVar1 = -*param_3 / -1;
  *param_4 = *param_3;
  while( true ) {
    if (iVar1 < 1) {
      *param_4 = *param_3;
      return;
    }
    DAT_009a23bc = (uint)*(byte *)(*param_4 + param_1 + -1);
    if ((DAT_009a23bc < 0x20) || (0x7d < DAT_009a23bc)) {
      *(undefined1 *)(*param_4 + param_1 + -1) = 0x20;
    }
    if ((0x20 < (int)DAT_009a23bc) && ((int)DAT_009a23bc < 0x7e)) break;
    *param_4 = *param_4 + -1;
    iVar1 = iVar1 + -1;
  }
  *(undefined1 *)(*param_4 + param_1) = 0;
  return;
}


