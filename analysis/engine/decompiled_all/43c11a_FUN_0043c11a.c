// FUN_0043c11a @ 0043c11a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0043c11a(float *param_1,float *param_2,float *param_3,int *param_4)

{
  float10 in_ST0;
  unkbyte10 Var1;
  float local_54 [10];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_c;
  
  _DAT_007f7784 = STEP * f_7;
  _DAT_007f7780 = *param_3;
  if (_DAT_007f7780 <= f_100) {
    if (IP7 == -5) {
      local_54[0] = _DAT_007f7784 * _DAT_007f7780 + *param_1;
      ffree(in_ST0);
      Var1 = add_point(local_54,param_2,param_4);
    }
    else {
      local_28 = 0;
      local_54[0] = _DAT_007f7784 * _DAT_007f7780 + *param_2;
      ffree(in_ST0);
      Var1 = add_point(param_1,local_54,param_4);
    }
    *param_4 = 0;
  }
  else {
    local_2c = 0;
    if (f_200 <= _DAT_007f7780) {
      _DAT_007f7780 = _DAT_007f7780 - f_200;
      if (IP7 == -5) {
        local_54[0] = *param_1 - _DAT_007f7784 * _DAT_007f7780;
        ffree(in_ST0);
        Var1 = add_point(local_54,param_2,&DAT_007604f0);
        local_54[0] = _DAT_007f7784 * _DAT_007f7780 + *param_1;
        ffree(Var1);
        Var1 = add_point(local_54,param_2,&DAT_00760494);
      }
      else {
        local_18 = 0;
        local_54[0] = *param_2 - _DAT_007f7784 * _DAT_007f7780;
        ffree(in_ST0);
        Var1 = add_point(param_1,local_54,&DAT_007604f0);
        *param_4 = 0;
      }
    }
    else {
      local_1c = 0;
      _DAT_007f7784 = (_DAT_007f7780 - f_100) * _DAT_007f7784;
      if (*param_4 == 0) {
        in_ST0 = (float10)_DAT_007f7784;
        _DAT_007f7784 = (float)-in_ST0;
      }
      _DAT_007f7780 = _DAT_007f7784 * f_0_375;
      if (IP7 == -5) {
        _DAT_007f7784 = _DAT_007f7784 + *param_2;
        local_54[0] = *param_1 - _DAT_007f7780;
        ffree(in_ST0);
        Var1 = add_point(local_54,&DAT_007f7784,&DAT_007604f0);
        ffree(Var1);
        Var1 = add_point(param_1,param_2,&DAT_00760494);
        local_54[0] = _DAT_007f7780 + *param_1;
        ffree(Var1);
        Var1 = add_point(local_54,&DAT_007f7784,&DAT_00760494);
      }
      else {
        local_c = 0;
        _DAT_007f7784 = _DAT_007f7784 + *param_1;
        local_54[0] = _DAT_007f7780 + *param_2;
        ffree(in_ST0);
        Var1 = add_point(&DAT_007f7784,local_54,&DAT_007604f0);
        ffree(Var1);
        Var1 = add_point(param_1,param_2,&DAT_00760494);
        local_54[0] = *param_2 - _DAT_007f7780;
        ffree(Var1);
        Var1 = add_point(&DAT_007f7784,local_54,&DAT_00760494);
      }
    }
  }
  ffree(Var1);
  return;
}


