// FUN_004c795b @ 004c795b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c795b(int *param_1,float *param_2,int *param_3)

{
  int iVar1;
  
  *param_2 = f_0;
  _DAT_0089fc34 = *(float *)(&DAT_01ea3fe4 + *param_1 * 4);
  iVar1 = -(*param_1 + -1) / -1;
  *param_3 = *param_1 + -1;
  while ((0 < iVar1 && (-0x65 < (int)(&DAT_01e9997c)[*param_3]))) {
    if ((-1 < (int)(&DAT_01e9997c)[*param_3]) && ((float)(&DAT_01e9bfc4)[*param_3] != *param_2)) {
      *param_2 = (float)(&DAT_01e9bfc4)[*param_3];
      _DAT_0089fc34 =
           _DAT_0089fc34 + *(float *)(&DAT_01ea4f84 + *param_3 * 4) +
           *(float *)(&DAT_01ea3fe4 + *param_3 * 4);
    }
    *param_3 = *param_3 + -1;
    iVar1 = iVar1 + -1;
  }
  _DAT_0089fc34 = _DAT_0089fc34 + *(float *)(&DAT_01ea4f84 + *param_3 * 4);
  _DAT_0089fc30 = LOAD_P3 - (float)(&DAT_01e9bfc4)[*param_3];
  *param_2 = _DAT_0089fc30 / _DAT_0089fc34;
  if (f_1 < *param_2) {
    *param_2 = f_1;
  }
  return;
}


