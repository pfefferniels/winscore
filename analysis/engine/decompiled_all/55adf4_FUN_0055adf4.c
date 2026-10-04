// FUN_0055adf4 @ 0055adf4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055adf4(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6)

{
  float fVar1;
  float fVar2;
  
  fVar1 = *param_5;
  fVar2 = *param_4;
  _DAT_009a3cc0 =
       (float)(((float10)fVar1 - (float10)fVar2) / ((float10)*param_2 - (float10)*param_1));
  *param_6 = (*param_3 - *param_1) * _DAT_009a3cc0 + *param_4;
  ffree((float10)fVar1 - (float10)fVar2);
  return;
}


