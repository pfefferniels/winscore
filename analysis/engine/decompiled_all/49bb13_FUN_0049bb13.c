// FUN_0049bb13 @ 0049bb13 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049bb13(int *param_1,float *param_2,float *param_3,float *param_4)

{
  int iVar1;
  
  DAT_0083891c = *param_1;
  if (DAT_0083891c == 3) {
    DAT_0083891c = -3;
  }
  if (DAT_0083891c < 0) {
    _DAT_00838918 = *param_3 - *param_4 * *param_2;
  }
  DAT_00838914 = 1;
  for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_00838910 = (&DAT_020492a4)[DAT_00838914];
    if (DAT_00838910 < 0) {
      DAT_00838910 = -DAT_00838910;
    }
    if (DAT_0083891c < 0) {
      DAT_0083890c = *param_4 * (float)(&ITEM_LEN)[DAT_00838910] + _DAT_00838918;
      if (ABS(f_0 - DAT_0083890c) < f_0_005) {
        DAT_0083890c = f_0;
      }
      if (ABS(DAT_00838908 - DAT_0083890c) < f_0_005) {
        DAT_0083890c = DAT_00838908;
      }
      (&ITEM_LEN)[DAT_00838910] = DAT_0083890c;
    }
    else {
      (&ITEM_LEN)[DAT_00838910] = (float)(&ITEM_LEN)[DAT_00838910] + *param_4;
    }
    DAT_00838914 = DAT_00838914 + 1;
  }
  return;
}


