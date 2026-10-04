// FUN_0058548e @ 0058548e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058548e(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  
  fVar1 = *param_4;
  fVar2 = *param_3;
  _DAT_009a9160 =
       (float)(((float10)fVar1 - (float10)fVar2) / ((float10)*param_2 - (float10)*param_1));
  _DAT_009a915c = (*param_3 - _DAT_009a9160 * *param_1) + f_0_001;
  DAT_009a9158 = 1;
  for (iVar3 = DAT_020492a4; 0 < iVar3; iVar3 = iVar3 + -1) {
    DAT_009a9154 = *(int *)(&DAT_02049a74 + DAT_009a9158 * 4);
    if (DAT_009a9154 < 0) {
      DAT_009a9154 = -DAT_009a9154;
    }
    (&ITEM_LEN)[DAT_009a9154] = _DAT_009a9160 * (float)(&ITEM_LEN)[DAT_009a9154] + _DAT_009a915c;
    DAT_009a9158 = DAT_009a9158 + 1;
  }
  ffree((float10)fVar1 - (float10)fVar2);
  return;
}


