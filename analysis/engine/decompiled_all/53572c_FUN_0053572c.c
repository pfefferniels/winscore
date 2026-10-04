// FUN_0053572c @ 0053572c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0053572c(int *param_1,float *param_2,float *param_3)

{
  int iVar1;
  
  DAT_0099a7e4 = *param_1;
  *param_1 = 0;
  if (DAT_0099a7e4 < 2) {
    *param_3 = *param_2;
  }
  else {
    DAT_0099a7e0 = 0;
    DAT_0099a7dc = *param_2;
    DAT_0099a7d8 = 2;
    iVar1 = DAT_0099a7e4;
    while (iVar1 = iVar1 + -1, 0 < iVar1) {
      if (param_2[DAT_0099a7d8 + -1] <= DAT_0099a7dc) {
        DAT_0099a7dc = param_2[DAT_0099a7d8 + -1];
        DAT_0099a7e0 = DAT_0099a7d8;
      }
      DAT_0099a7d8 = DAT_0099a7d8 + 1;
    }
    if (DAT_0099a7e0 != 0) {
      param_2[DAT_0099a7e0 + -1] = *param_2;
      *param_2 = DAT_0099a7dc;
    }
    DAT_0099a7d8 = 2;
    iVar1 = DAT_0099a7e4;
    while (iVar1 = iVar1 + -1, 0 < iVar1) {
      DAT_0099a7d4 = param_2[DAT_0099a7d8 + -1] - DAT_0099a7dc;
      if (f_0_001 < DAT_0099a7d4) {
        *param_1 = *param_1 + 1;
        param_2[*param_1 + -1] = DAT_0099a7d4;
      }
      DAT_0099a7d8 = DAT_0099a7d8 + 1;
    }
    *param_3 = DAT_0099a7dc;
  }
  return;
}


