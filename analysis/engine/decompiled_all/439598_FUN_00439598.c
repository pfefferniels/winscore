// FUN_00439598 @ 00439598 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00439598(float *param_1,float *param_2,int *param_3,float *param_4)

{
  int iVar1;
  float10 fVar2;
  unkbyte10 Var3;
  int local_18;
  
  if (P8 <= f_0) {
    P8 = f_1;
  }
  DAT_01cf8ecc = DAT_01cf8ed4 * P8;
  DAT_01cf8ed0 = DAT_01cf8ed4 * P9;
  if (DAT_01cf8ed0 <= f_0) {
    DAT_01cf8ed0 = DAT_01cf8ecc;
  }
  _DAT_007f76c4 = f_1_1;
  fVar2 = (float10)*param_4;
  _DAT_007f76c0 = (float)ABS(fVar2);
  if ((*param_4 != f_0) && (*param_4 != f_m1)) {
    _DAT_007f76c4 = _DAT_007f76c0 / f_2;
  }
  local_18 = 2;
  DAT_007f76bc = 1;
  do {
    DAT_01cf8ec4 = 1;
    DAT_01cf8ed4 = *param_1;
    do {
      ffree(fVar2);
      Var3 = add_point(&DAT_01cf8ed4,&DAT_01cf8edc,&DAT_01cf8ec4);
      DAT_01cf8ec4 = 1;
      DAT_01cf8ed4 = DAT_01cf8ecc + DAT_01cf8ed4;
      _DAT_007f76b8 = 0;
      ffree(Var3);
      fVar2 = (float10)add_point(&DAT_01cf8ed4,&DAT_01cf8edc,&DAT_007f76b8);
      DAT_01cf8ed4 = DAT_01cf8ed0 + DAT_01cf8ed4;
    } while (DAT_01cf8ed4 < DAT_01cf8ec8);
    if (IP5 != 999) goto LAB_00439958;
    P5 = P4 - _DAT_007f76c4;
    ffree(fVar2);
    fVar2 = (float10)staff_level_y(&P5);
    *param_2 = (float)fVar2;
    _DAT_007f76b4 = (*param_2 - DAT_01cf8edc) / ((DAT_01cf8ed4 - DAT_01cf8ed0) - *param_1);
    DAT_01cf8ec4 = (&PT_X0)[*param_3];
    DAT_01cf8ec0 = *param_3 + 1;
    for (iVar1 = (NPT - DAT_01cf8ec0) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_007f76b0 = (&PT_X0)[DAT_01cf8ec0];
      if (-0x2f059 < DAT_007f76b0) {
        (&PT_Y0)[DAT_01cf8ec0] =
             (int)ROUND((float)(DAT_007f76b0 - DAT_01cf8ec4) * _DAT_007f76b4 +
                        (float)(int)(&PT_Y0)[DAT_01cf8ec0]);
      }
      DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
    }
    *param_3 = NPT;
    fVar2 = (float10)_DAT_007f76c4;
    _DAT_007f76c4 = (float)-fVar2;
    DAT_007f76bc = DAT_007f76bc + 1;
    local_18 = local_18 + -1;
  } while (0 < local_18);
  if (*param_4 < f_0) {
    DAT_007f76ac = NPT + -1;
    DAT_01cf8ec0 = NPT + -1;
    for (iVar1 = -DAT_01cf8ec0 / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_007f76ac = DAT_007f76ac + 1;
      (&PT_Y0)[DAT_007f76ac] = (&PT_Y0)[DAT_01cf8ec0];
      DAT_01cf8ec0 = DAT_01cf8ec0 + -1;
    }
    ffree(fVar2);
    fVar2 = (float10)thunk_FUN_0054c4c6(&PT_Y0 + NPT,&DAT_02004cc0,&NPT);
  }
LAB_00439958:
  ffree(fVar2);
  return;
}


