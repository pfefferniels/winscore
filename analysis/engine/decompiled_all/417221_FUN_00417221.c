// FUN_00417221 @ 00417221 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00417221(float *param_1,float *param_2)

{
  float fVar1;
  float10 in_ST0;
  
  fVar1 = *param_1;
  if ((fVar1 == f_10) || (fVar1 == f_20)) {
    _DAT_007d1410 = (DAT_01f95ce0 * _DAT_01f93fc0 * f_2_8333333) / f_25;
    if (*param_1 == f_20) {
      in_ST0 = (float10)_DAT_007d1410;
      _DAT_007d1410 = (float)-in_ST0;
    }
  }
  else {
    _DAT_007d1410 = DAT_01f95ce0 * fVar1 * f_0_04;
  }
  *param_2 = _DAT_007d1410 + *param_2;
  ffree(in_ST0);
  return;
}


