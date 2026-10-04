// FUN_0046f774 @ 0046f774 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046f774(float *param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)amod(&DAT_01f95c94,&f_100);
  DAT_01f95c90 = (float)fVar1;
  _DAT_00824e5c = DAT_01f95c90 + *param_1;
  if (f_0 <= DAT_01f95c94) {
    if (f_0 <= _DAT_00824e5c) {
      return;
    }
  }
  else if (_DAT_00824e5c < f_0) {
    return;
  }
  DAT_01f95c94 = (DAT_01f95c90 + DAT_01f95c90) - DAT_01f95c94;
  return;
}


