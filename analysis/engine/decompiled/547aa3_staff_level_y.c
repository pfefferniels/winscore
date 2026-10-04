// staff_level_y @ 00547aa3 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


float10 staff_level_y(float *param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)*param_1 * (float10)f_7 * (float10)(float)(&STAFF_STEP0)[CUR_STAFF];
  ffree(fVar1);
  return (float10)(float)((float10)(int)(&STAFF_Y0)[CUR_STAFF] + fVar1);
}


