// FUN_00568573 @ 00568573 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00568573(float *param_1,float *param_2,int *param_3,int *param_4,float *param_5,
                 float *param_6,float *param_7,float *param_8,float *param_9,float *param_10,
                 float *param_11)

{
  int iVar1;
  float10 in_ST0;
  
  DAT_009a7ea0 = *param_3;
  if (*param_3 == 0) {
    if (*param_4 == 0) goto LAB_005689a3;
    DAT_009a7ea0 = *param_4;
  }
  _DAT_009a7e9c = (float)(&ITEM_P6)[DAT_009a7ea0];
  if (_DAT_009a7e9c == f_0) {
    _DAT_009a7e9c = f_1;
  }
  DAT_009a7e98 = (int)ROUND((float)(&ITEM_P2)[DAT_009a7ea0]);
  _DAT_009a7e94 = (float)(&STAFF_STEP0)[DAT_009a7e98] / f_25;
  _DAT_009a7e90 = _DAT_009a7e94 * _DAT_009a7e9c;
  DAT_009a7e8c = f_0;
  if (*param_3 != 0) {
    DAT_009a7e8c = (float)(&ITEM_P13)[DAT_009a7ea0] + *param_1;
  }
  _DAT_009a7e88 = DAT_009a7e8c;
  if (f_201 < *param_2) {
    *param_2 = f_201;
  }
  DAT_009a7e84 = *param_2 - _DAT_0078ded0 * _DAT_009a7e90;
  DAT_009a7e80 = (float)(&ITEM_P4)[DAT_009a7ea0];
  if (*param_6 == f_0) {
    *param_1 = DAT_009a7e84 - f_4;
    *param_2 = f_0;
    DAT_009a7e98 = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_009a7e7c = (&ITEM_PTR0)[DAT_009a7e98];
      if (((((float)(&ITEM_P1)[DAT_009a7e7c] == f_1) &&
           ((float)(&ITEM_P2)[DAT_009a7e7c] == *param_5)) &&
          (DAT_009a7e8c = (float)(&ITEM_P3)[DAT_009a7e7c], DAT_009a7e8c <= *param_1)) &&
         (*param_2 < DAT_009a7e8c)) {
        *param_2 = DAT_009a7e8c;
      }
      DAT_009a7e98 = DAT_009a7e98 + 1;
    }
    *param_2 = _DAT_009a7e94 * f_4 + *param_2;
    if ((*param_2 < DAT_009a7e84) && (_DAT_009a7e88 + f_2 < *param_2)) {
      DAT_009a7e84 = *param_2;
    }
  }
  else {
    *param_1 = (*param_2 - DAT_009a7e8c) - _DAT_009a7e90 * _DAT_0078ded0;
    *param_2 = (float)(int)ROUND(*param_1 / (_DAT_009a7e90 * f_25)) + f_1;
    if (DAT_0078b4a0 != 0) {
      *param_2 = f_1;
    }
    in_ST0 = (float10)*param_1 - (float10)_DAT_0078ded8 * (float10)*param_2 * (float10)_DAT_009a7e90
    ;
    *param_1 = (float)(in_ST0 / ((float10)*param_2 + (float10)f_1));
    _DAT_009a7e88 = DAT_009a7e8c + *param_1;
    DAT_009a7e84 = _DAT_009a7e94 * f_0_2 + DAT_009a7e84;
    *param_10 = _DAT_009a7e9c * _DAT_0078ded8 * _DAT_0078ded4;
    *param_11 = (_DAT_0078ded4 * *param_1) / _DAT_009a7e94;
    DAT_009a7e80 = _DAT_009a7e9c * f_0_8 + DAT_009a7e80;
  }
  *param_8 = DAT_009a7e80;
  *param_7 = _DAT_009a7e94 * f_1_5 + _DAT_009a7e88;
  *param_9 = _DAT_009a7e94 * f_0_1 + DAT_009a7e8c;
  if ((*param_6 != f_0) && (*param_7 < *param_9)) {
    *param_7 = *param_9;
  }
  if (DAT_009a7e84 - _DAT_009a7e88 < f_0_2) {
    DAT_009a7e84 = _DAT_009a7e88 + f_0_02;
  }
  *param_9 = DAT_009a7e84;
LAB_005689a3:
  ffree(in_ST0);
  return;
}


