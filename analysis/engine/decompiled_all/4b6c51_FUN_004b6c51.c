// FUN_004b6c51 @ 004b6c51 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b6c51(float *param_1,float *param_2,undefined4 param_3,float *param_4,int *param_5)

{
  float10 fVar1;
  
  *param_1 = f_0;
  if (*param_5 == 1) {
    *param_1 = f_2;
  }
  fVar1 = (float10)amod(param_3,&f_100);
  DAT_01c585d0 = (float)ABS(fVar1);
  *param_2 = f_4_5;
  if (*param_5 == 3) {
    *param_2 = f_5_5;
  }
  DAT_01c585d4 = *param_4;
  if (DAT_01c585d4 == 0.0) {
    DAT_01c585d4 = f_1;
  }
  *param_2 = (DAT_01c585d0 - f_1) * f_2_8 * DAT_01c585d4 + *param_2;
  return;
}


