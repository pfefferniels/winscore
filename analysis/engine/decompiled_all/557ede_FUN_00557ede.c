// FUN_00557ede @ 00557ede (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00557ede(int *param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  if (*param_1 < DAT_01e99984) {
    *param_1 = *param_1 + 1;
    DAT_009a3c54 = (&ITEM_PTR0)[(&DAT_01e9a928)[*param_1]];
    *param_4 = (float)(&ITEM_P6)[DAT_009a3c54] - f_3;
    *param_5 = *param_4 + f_6;
    *param_2 = (float)(&ITEM_P3)[DAT_009a3c54] - f_3;
    *param_3 = *param_2 + f_6;
  }
  else {
    DAT_01e99984 = 0;
  }
  return;
}


