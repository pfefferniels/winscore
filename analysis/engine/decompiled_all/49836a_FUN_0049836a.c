// FUN_0049836a @ 0049836a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0049836a(int param_1,undefined4 *param_2,int *param_3,int *param_4,int *param_5)

{
  int *piVar1;
  
  DAT_0082a6b0 = 1;
  DAT_0082a6ac = 1;
  *param_3 = *param_5;
  DAT_0082a6a8 = *param_5 + -1;
  *param_2 = 1;
  do {
    DAT_0082a6a4 = (int)ROUND(*(float *)(param_1 + -4 + DAT_0082a6b0 * 4));
    DAT_0082a6b0 = DAT_0082a6a4 + DAT_0082a6b0 + 1;
    piVar1 = param_2 + DAT_0082a6ac;
    DAT_0082a6ac = DAT_0082a6ac + 1;
    *piVar1 = DAT_0082a6b0;
  } while (DAT_0082a6b0 < DAT_0082a6a8);
  *param_4 = DAT_0082a6ac + -1;
  if (*param_3 != param_2[DAT_0082a6ac + -1]) {
    *param_3 = param_2[DAT_0082a6ac + -1];
  }
  return;
}


