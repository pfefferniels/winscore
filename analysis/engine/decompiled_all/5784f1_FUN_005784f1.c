// FUN_005784f1 @ 005784f1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005784f1(int *param_1)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  uint local_64;
  int local_60;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  _DAT_009a8df8 = f_1;
  if (DAT_020b8ea2 == 'S') {
    _DAT_009a8df8 = f_1_5;
  }
  local_64 = DAT_020b9454;
  ffree(in_ST0);
  fVar2 = (float10)FUN_005ff874(&local_64,&f_100);
  _DAT_009a8df4 = (float)fVar2;
  if (_DAT_009a8df4 == f_0) {
    _DAT_009a8df4 = f_1;
  }
  _DAT_009a8df8 = _DAT_009a8df4 * _DAT_009a8df8;
  local_64 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_009a8de8 = (int)ROUND(DAT_020b9444);
  LOAD_I = 1;
  _DAT_009a8df0 = f_0;
  _DAT_009a8dec = f_0;
  local_60 = DAT_009a8de8;
  Var3 = extraout_ST1;
  for (iVar1 = ITEM_COUNT_SAVE; 0 < iVar1; iVar1 = iVar1 + -1) {
    ffree(Var3);
    Var3 = load_item_header();
    if ((LOAD_CODE == 8) && (DAT_009a8de8 == LOAD_STAFF)) {
      if (3 < LOAD_LEN) {
        _DAT_009a8df0 = (float)(&ITEM_P4)[LOAD_W];
      }
      if (4 < LOAD_LEN) {
        _DAT_009a8dec = (float)(&ITEM_P5)[LOAD_W];
      }
      local_38 = 0;
      if (_DAT_009a8dec == f_0) {
        _DAT_009a8dec = f_1;
      }
      DAT_009a8ddc = 0x100;
      if (*param_1 == 2) {
        DAT_009a8ddc = 0;
      }
      LOAD_I = 1;
      _DAT_009a8de4 = f_0;
      _DAT_009a8de0 = f_0;
      iVar1 = ITEM_COUNT_SAVE;
      goto joined_r0x005786de;
    }
    local_3c = 0;
    local_34 = 0;
    LOAD_I = LOAD_I + 1;
  }
LAB_00578944:
  ffree(Var3);
  return;
joined_r0x005786de:
  if (iVar1 < 1) goto LAB_005787d9;
  ffree(Var3);
  Var3 = load_item_header();
  if (LOAD_CODE == 8) {
    if (*param_1 == 2) {
      if (DAT_020b9444 <= (float)LOAD_STAFF) {
        local_20 = 0;
      }
      else {
        local_24 = 0;
LAB_0057875f:
        DAT_009a8ddc = LOAD_STAFF;
        if (3 < LOAD_LEN) {
          _DAT_009a8de4 = (float)(&ITEM_P4)[LOAD_W];
        }
        if (4 < LOAD_LEN) {
          _DAT_009a8de0 = (float)(&ITEM_P5)[LOAD_W];
        }
        local_14 = 0;
      }
    }
    else {
      local_28 = 0;
      if (DAT_020b9444 < (float)LOAD_STAFF) {
        if (LOAD_STAFF <= DAT_009a8ddc) goto LAB_0057875f;
        local_18 = 0;
      }
      else {
        local_1c = 0;
      }
    }
  }
  else {
    local_2c = 0;
  }
  local_10 = 0;
  LOAD_I = LOAD_I + 1;
  iVar1 = iVar1 + -1;
  goto joined_r0x005786de;
LAB_005787d9:
  if (_DAT_009a8de0 == f_0) {
    _DAT_009a8de0 = f_1;
  }
  if (*param_1 == 2) {
    local_c = 0;
    _DAT_009a8dd8 = _DAT_009a8de0 * f_1925 + (float)(int)(&STAFF_Y0)[DAT_009a8ddc];
    fVar2 = (float10)(int)(&STAFF_Y0)[DAT_009a8de8];
    _DAT_009a8dd4 = (float)((float10)_DAT_009a8dec * (float10)f_525 + fVar2);
    _DAT_009a8dd0 = (_DAT_009a8dd4 - _DAT_009a8dd8) / f_2;
    _DAT_009a8dcc = f_3 - _DAT_009a8dd0 / (_DAT_009a8dec * f_175);
  }
  else {
    _DAT_009a8dd8 = _DAT_009a8dec * f_1925 + (float)(int)(&STAFF_Y0)[DAT_009a8de8];
    fVar2 = (float10)(int)(&STAFF_Y0)[DAT_009a8ddc];
    _DAT_009a8dd4 = (float)((float10)_DAT_009a8de0 * (float10)f_525 + fVar2);
    _DAT_009a8dd0 = (_DAT_009a8dd4 - _DAT_009a8dd8) / f_2;
    _DAT_009a8dcc = _DAT_009a8dd0 / (_DAT_009a8dec * f_175) + f_11;
    local_8 = 0;
  }
  P4 = _DAT_009a8dcc - _DAT_009a8df8;
  ffree(fVar2);
  fVar2 = (float10)staff_level_y(&P4);
  Y_POS = (float)fVar2;
  Var3 = extraout_ST1_00;
  goto LAB_00578944;
}


