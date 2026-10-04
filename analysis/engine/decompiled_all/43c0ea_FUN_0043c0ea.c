// FUN_0043c0ea @ 0043c0ea (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 FUN_0043c0ea(float *param_1,float *param_2,float *param_3,float *param_4)

{
  ffree(ABS((float10)*param_4 - (float10)*param_1));
  return (float10)(float)(ABS((float10)*param_4 - (float10)*param_1) -
                         ABS((float10)*param_3 - (float10)*param_2));
}


