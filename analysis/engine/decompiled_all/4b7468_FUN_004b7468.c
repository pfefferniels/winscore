// FUN_004b7468 @ 004b7468 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b7468(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 int param_6,int *param_7)

{
  float10 fVar1;
  
  _DAT_0089f4d8 = *(float *)(param_1 + -4 + *param_7 * 4);
  fVar1 = ((float10)*param_2 - (float10)_DAT_0089f4d8) * (float10)*param_4;
  DAT_0089f4d4 = (float)(fVar1 / ((float10)*param_3 - (float10)_DAT_0089f4d8));
  if (DAT_0089f4d4 < *param_5) {
    DAT_0089f4d4 = *param_5;
  }
  *(float *)(param_6 + -4 + *param_7 * 4) = DAT_0089f4d4;
  *param_4 = *param_4 - DAT_0089f4d4;
  *param_7 = *param_7 + 1;
  *(float *)(param_1 + -4 + *param_7 * 4) = *param_2;
  ffree(fVar1);
  return;
}


