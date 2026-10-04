// FUN_0058a1b1 @ 0058a1b1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058a1b1(int *param_1,int param_2,undefined4 param_3,int *param_4)

{
  DAT_009a92f4 = *param_4;
  *param_1 = *param_1 + 1;
  *(undefined1 *)(*param_1 + param_2 + -1) = 0x20;
  if (99 < DAT_009a92f4) {
    DAT_009a92f4._0_1_ = (char)(DAT_009a92f4 / 100);
    *param_1 = *param_1 + 1;
    *(char *)(*param_1 + param_2 + -1) = (char)DAT_009a92f4 + '0';
    DAT_009a92f4 = *param_4 % 100;
  }
  if (9 < *param_4) {
    DAT_009a92f0 = DAT_009a92f4 / 10;
    *param_1 = *param_1 + 1;
    *(char *)(*param_1 + param_2 + -1) = (char)DAT_009a92f0 + '0';
    DAT_009a92f4 = *param_4 % 10;
  }
  *param_1 = *param_1 + 1;
  *(char *)(*param_1 + param_2 + -1) = (char)DAT_009a92f4 + '0';
  return;
}


