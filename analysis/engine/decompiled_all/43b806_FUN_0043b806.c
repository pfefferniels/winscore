// FUN_0043b806 @ 0043b806 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043b806(undefined4 param_1,undefined4 param_2,float *param_3,undefined4 param_4,
                 undefined4 param_5,float *param_6)

{
  float10 fVar1;
  unkbyte10 Var2;
  float local_54 [10];
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_18;
  undefined4 local_14;
  
  _DAT_007f7778 = f_0;
  _DAT_007f7774 = f_0;
  _DAT_007f7770 = f_0;
  DAT_007f776c = P6 * f_150;
  DAT_007f7768 = P3 * f_150;
  _DAT_007f7764 = DAT_007f776c - DAT_007f7768;
  fVar1 = (float10)P14;
  if ((float10)f_1 < ABS(fVar1)) {
    P14 = P14 / f_100;
  }
  if (P15 == f_0) {
    if (P14 < f_0) {
      fVar1 = (float10)P14;
      _DAT_007f7778 = (float)-fVar1;
      P14 = f_0;
    }
    _DAT_007f7760 = *param_6 + *param_3;
    _DAT_007f775c = *param_6 - *param_3;
    _DAT_007f7754 = *param_6;
    DAT_007f7758 = _DAT_007f7754;
    if (P14 == f_0) {
      _DAT_007f7750 = *param_6 - _DAT_007f7778 * *param_3;
      _DAT_007f774c = _DAT_007f7778 * *param_3 + *param_6;
      _DAT_007f7744 = DAT_007f776c;
      _DAT_007f7748 = DAT_007f7768;
    }
    else if (_DAT_007f7778 == f_0) {
      _DAT_007f7750 = *param_6 - P14 * *param_3;
      _DAT_007f774c = P14 * *param_3 + *param_6;
      _DAT_007f7770 = P14 * _DAT_007f7764 + DAT_007f7768;
      _DAT_007f7744 = P14 * _DAT_007f7764 + DAT_007f7768;
      _DAT_007f7748 = DAT_007f776c;
      if (P7 < f_0) {
        _DAT_007f7740 = (f_1 - P14) * *param_3;
        ffree(fVar1);
        Var2 = add_point(&DAT_007f7768,&DAT_007f7760,&DAT_007604f0);
        local_54[0] = _DAT_007f7740 + *param_6;
        ffree(Var2);
        Var2 = add_point(&DAT_007f7744,local_54,&DAT_00760494);
        ffree(Var2);
        Var2 = add_point(&DAT_007f7768,&DAT_007f775c,&DAT_007604f0);
        local_54[0] = *param_6 - _DAT_007f7740;
        ffree(Var2);
        Var2 = add_point(&DAT_007f7744,local_54,&DAT_00760494);
      }
      else {
        _DAT_007f7740 = P14 * *param_3;
        local_54[0] = *param_6 - _DAT_007f7740;
        ffree(fVar1);
        Var2 = add_point(&DAT_007f7770,local_54,&DAT_007604f0);
        ffree(Var2);
        Var2 = add_point(&DAT_007f7768,param_6,&DAT_00760494);
        local_54[0] = _DAT_007f7740 + *param_6;
        ffree(Var2);
        Var2 = add_point(&DAT_007f7744,local_54,&DAT_00760494);
      }
      goto LAB_0043c0df;
    }
    _DAT_007f7770 = _DAT_007f7778 * _DAT_007f7764 + DAT_007f7768;
    if (P14 == f_0) {
      if (f_0 <= P7) {
        ffree(fVar1);
        Var2 = add_point(&DAT_007f7770,&DAT_007f7750,&DAT_007604f0);
        ffree(Var2);
        Var2 = add_point(&DAT_007f7744,&DAT_007f775c,&DAT_00760494);
        ffree(Var2);
        Var2 = add_point(&DAT_007f7770,&DAT_007f774c,&DAT_007604f0);
        ffree(Var2);
        Var2 = add_point(&DAT_007f7744,&DAT_007f7760,&DAT_00760494);
      }
      else {
        local_24 = 0;
        _DAT_007f7740 = (f_1 - _DAT_007f7778) * *param_3;
        local_54[0] = *param_6 - _DAT_007f7740;
        ffree(fVar1);
        Var2 = add_point(&DAT_007f7770,local_54,&DAT_007604f0);
        ffree(Var2);
        Var2 = add_point(&DAT_007f776c,param_6,&DAT_00760494);
        local_54[0] = _DAT_007f7740 + *param_6;
        ffree(Var2);
        Var2 = add_point(&DAT_007f7770,local_54,&DAT_00760494);
      }
      goto LAB_0043c0df;
    }
  }
  else {
    local_2c = 0;
  }
  _DAT_007f773c = P14 * _DAT_007f7764 + DAT_007f7768;
  _DAT_007f7740 = -(P15 * f_75);
  _DAT_007f7738 = _DAT_007f773c - _DAT_007f7740;
  _DAT_007f777c = _DAT_007f7740 + _DAT_007f773c;
  _DAT_007f7734 = (_DAT_007f7738 - DAT_007f7768) / _DAT_007f7764;
  _DAT_007f7730 = (_DAT_007f777c - DAT_007f7768) / _DAT_007f7764;
  if (P15 <= f_0) {
    if (f_0 <= P7) {
      ffree(fVar1);
      Var2 = add_point(&DAT_007f7768,param_6,&DAT_007604f0);
      local_54[0] = _DAT_007f7734 * *param_3 + *param_6;
      ffree(Var2);
      Var2 = add_point(&DAT_007f7738,local_54,&DAT_00760494);
      ffree(Var2);
      Var2 = add_point(&DAT_007f7768,param_6,&DAT_007604f0);
      local_54[0] = *param_6 - _DAT_007f7734 * *param_3;
      ffree(Var2);
      Var2 = add_point(&DAT_007f7738,local_54,&DAT_00760494);
      local_54[0] = _DAT_007f7730 * *param_3 + *param_6;
      ffree(Var2);
      Var2 = add_point(&DAT_007f777c,local_54,&DAT_007604f0);
      local_54[0] = *param_6 + *param_3;
      ffree(Var2);
      Var2 = add_point(&DAT_007f776c,local_54,&DAT_00760494);
      local_54[0] = *param_6 - _DAT_007f7730 * *param_3;
      ffree(Var2);
      Var2 = add_point(&DAT_007f777c,local_54,&DAT_007604f0);
      local_54[0] = *param_6 - *param_3;
      ffree(Var2);
      Var2 = add_point(&DAT_007f776c,local_54,&DAT_00760494);
    }
    else {
      local_14 = 0;
      ffree(fVar1);
      Var2 = add_point(&DAT_007f776c,param_6,&DAT_007604f0);
      local_54[0] = _DAT_007f7734 * *param_3 + *param_6;
      ffree(Var2);
      Var2 = add_point(&DAT_007f777c,local_54,&DAT_00760494);
      ffree(Var2);
      Var2 = add_point(&DAT_007f776c,param_6,&DAT_007604f0);
      local_54[0] = *param_6 - _DAT_007f7734 * *param_3;
      ffree(Var2);
      Var2 = add_point(&DAT_007f777c,local_54,&DAT_00760494);
      local_54[0] = _DAT_007f7730 * *param_3 + *param_6;
      ffree(Var2);
      Var2 = add_point(&DAT_007f7738,local_54,&DAT_007604f0);
      local_54[0] = *param_6 + *param_3;
      ffree(Var2);
      Var2 = add_point(&DAT_007f7768,local_54,&DAT_00760494);
      local_54[0] = *param_6 - _DAT_007f7730 * *param_3;
      ffree(Var2);
      Var2 = add_point(&DAT_007f7738,local_54,&DAT_007604f0);
      local_54[0] = *param_6 - *param_3;
      ffree(Var2);
      Var2 = add_point(&DAT_007f7768,local_54,&DAT_00760494);
    }
  }
  else {
    local_18 = 0;
    _DAT_007f772c = _DAT_007f7734 * *param_3;
    _DAT_007f7728 = _DAT_007f7730 * *param_3;
    if (P7 < f_0) {
      ffree(fVar1);
      fVar1 = (float10)thunk_FUN_0054c669(&DAT_007f772c,&DAT_007f7728);
    }
    local_54[0] = _DAT_007f772c + *param_6;
    ffree(fVar1);
    Var2 = add_point(&DAT_007f7738,local_54,&DAT_007604f0);
    local_54[0] = _DAT_007f7728 + *param_6;
    ffree(Var2);
    Var2 = add_point(&DAT_007f777c,local_54,&DAT_00760494);
    local_54[0] = *param_6 - _DAT_007f772c;
    ffree(Var2);
    Var2 = add_point(&DAT_007f7738,local_54,&DAT_007604f0);
    local_54[0] = *param_6 - _DAT_007f7728;
    ffree(Var2);
    Var2 = add_point(&DAT_007f777c,local_54,&DAT_00760494);
  }
LAB_0043c0df:
  ffree(Var2);
  return;
}


