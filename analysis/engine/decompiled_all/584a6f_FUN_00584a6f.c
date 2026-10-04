// FUN_00584a6f @ 00584a6f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00584a6f(int *param_1,int *param_2,int *param_3,undefined4 *param_4,int param_5,int param_6
                 ,int *param_7,int *param_8)

{
  int iVar1;
  
  DAT_009a9110 = *param_1 + 1;
  DAT_009a9108 = *param_3 + *param_8;
  for (iVar1 = ((*(int *)(DAT_009a9110 * 4 + param_6 + -4) - DAT_009a9108) + -1) / -1; 0 < iVar1;
      iVar1 = iVar1 + -1) {
    *(undefined4 *)(param_5 + -4 + DAT_009a9108 * 4) =
         *(undefined4 *)(param_5 + -4 + (DAT_009a9108 - *param_3) * 4);
    DAT_009a9108 = DAT_009a9108 + -1;
  }
  DAT_009a910c = DAT_009a9110;
  for (iVar1 = (*param_7 - DAT_009a9110) + 2; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(int *)(DAT_009a910c * 4 + param_6 + -4) = *param_3 + *(int *)(param_6 + -4 + DAT_009a910c * 4)
    ;
    DAT_009a910c = DAT_009a910c + 1;
  }
  *param_8 = *param_3 + *param_8;
  DAT_009a9110 = (int)ROUND(*(float *)(param_5 + -4 + *param_2 * 4));
  DAT_009a910c = DAT_009a9110 + 1;
  for (iVar1 = ((*param_3 + DAT_009a9110) - DAT_009a910c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(float *)(param_5 + -4 + (*param_2 + DAT_009a910c) * 4) = f_0;
    DAT_009a910c = DAT_009a910c + 1;
  }
  *(undefined4 *)(param_5 + -4 + *param_2 * 4) = *param_4;
  return;
}


