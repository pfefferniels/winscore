// FUN_0053de20 @ 0053de20 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 FUN_0053de20(int *param_1,int *param_2,float *param_3,int *param_4)

{
  float10 fVar1;
  float local_20;
  
  fVar1 = (float10)amod(&DAT_01f95d60 + *param_1 * 0xf,&f_100);
  DAT_0078cd30 = (float)(fVar1 + (float10)f_8);
  DAT_0078cd34 = (int)ROUND((float)(&DAT_01f95d54)[*param_1 * 0xf]) % 100;
  if ((int)ROUND((float)(&DAT_01f95d54)[*param_1 * 0xf]) % 100 < 10) {
    DAT_0078cd30 = f_2;
  }
  if (*param_4 < 0x14) {
    if (*param_2 == 0x14) {
      local_20 = *param_3 - f_2;
    }
    else {
      local_20 = DAT_0078cd30 + *param_3;
    }
  }
  else if (*param_2 == 0x14) {
    local_20 = *param_3 - DAT_0078cd30;
  }
  else {
    local_20 = *param_3 + f_2;
  }
  return (float10)local_20;
}


