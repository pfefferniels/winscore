// FUN_00577f17 @ 00577f17 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00577f17(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar2;
  float10 extraout_ST1;
  undefined4 local_74;
  uint local_70;
  int local_6c;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  _DAT_009a8dc8 = f_99;
  if (DAT_020b9440 == f_4) {
    _DAT_009a8dc8 = f_0;
  }
  if (DAT_020b9440 == f_9) {
    _DAT_009a8dc8 = f_1;
  }
  if (DAT_020b9440 == f_10) {
    _DAT_009a8dc8 = f_1_5;
  }
  if ((DAT_020b9440 == f_16) && (_DAT_009a8dc8 = f_1, DAT_020b8ea2 == 'S')) {
    _DAT_009a8dc8 = f_1_5;
  }
  if (DAT_020b9440 == f_18) {
    _DAT_009a8dc8 = f_7_14;
  }
  if (_DAT_009a8dc8 == f_99) goto LAB_005784e8;
  local_74 = DAT_020b9454;
  ffree(in_ST0);
  fVar2 = (float10)FUN_005ff874(&local_74,&f_100);
  _DAT_009a8dc4 = (float)fVar2;
  if (DAT_020b9440 == f_18) {
    _DAT_009a8dc4 = DAT_020b9458;
  }
  if (_DAT_009a8dc4 == f_0) {
    _DAT_009a8dc4 = f_1;
  }
  _DAT_009a8dc8 = _DAT_009a8dc4 * _DAT_009a8dc8;
  in_ST0 = extraout_ST1;
  if (DAT_020b8ea2 != 'S') {
    local_70 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    DAT_009a8db4 = (int)ROUND(DAT_020b9444);
    LOAD_I = 1;
    _DAT_009a8dbc = f_0;
    _DAT_009a8db8 = f_0;
    local_6c = DAT_009a8db4;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      ffree(in_ST0);
      in_ST0 = (float10)load_item_header();
      if ((LOAD_CODE == 8) && (DAT_009a8db4 == LOAD_STAFF)) {
        if (3 < LOAD_LEN) {
          _DAT_009a8dbc = (float)(&ITEM_P4)[LOAD_W];
        }
        if (4 < LOAD_LEN) {
          _DAT_009a8db8 = (float)(&ITEM_P5)[LOAD_W];
        }
        local_3c = 0;
        if (_DAT_009a8db8 == f_0) {
          _DAT_009a8db8 = f_1;
        }
        DAT_009a8da8 = 0x100;
        if (DAT_020b8ea2 == 'B') {
          DAT_009a8da8 = 0;
        }
        LOAD_I = 1;
        _DAT_009a8db0 = f_0;
        _DAT_009a8dac = f_0;
        iVar1 = ITEM_I;
        goto joined_r0x00578213;
      }
      local_40 = 0;
      local_38 = 0;
      LOAD_I = LOAD_I + 1;
    }
    goto LAB_005784e8;
  }
  _DAT_009a8dc0 = f_7;
  goto LAB_00578456;
joined_r0x00578213:
  if (iVar1 < 1) goto LAB_00578319;
  ffree(in_ST0);
  in_ST0 = (float10)load_item_header();
  if (LOAD_CODE == 8) {
    if (DAT_020b8ea2 == 'B') {
      if (DAT_020b9444 <= (float)LOAD_STAFF) {
        local_24 = 0;
      }
      else {
        local_28 = 0;
LAB_0057829f:
        DAT_009a8da8 = LOAD_STAFF;
        if (3 < LOAD_LEN) {
          _DAT_009a8db0 = (float)(&ITEM_P4)[LOAD_W];
        }
        if (4 < LOAD_LEN) {
          _DAT_009a8dac = (float)(&ITEM_P5)[LOAD_W];
        }
        local_18 = 0;
      }
    }
    else {
      local_2c = 0;
      if (DAT_020b9444 < (float)LOAD_STAFF) {
        if (LOAD_STAFF <= DAT_009a8da8) goto LAB_0057829f;
        local_1c = 0;
      }
      else {
        local_20 = 0;
      }
    }
  }
  else {
    local_30 = 0;
  }
  local_14 = 0;
  LOAD_I = LOAD_I + 1;
  iVar1 = iVar1 + -1;
  goto joined_r0x00578213;
LAB_00578319:
  if (_DAT_009a8dac == f_0) {
    _DAT_009a8dac = f_1;
  }
  if (DAT_020b8ea2 == 'B') {
    _DAT_009a8da4 = _DAT_009a8dac * f_1925 + (float)(int)(&STAFF_Y0)[DAT_009a8da8];
    in_ST0 = (float10)(int)(&STAFF_Y0)[DAT_009a8db4];
    _DAT_009a8da0 = (float)((float10)_DAT_009a8db8 * (float10)f_525 + in_ST0);
    _DAT_009a8d9c = (_DAT_009a8da0 - _DAT_009a8da4) / f_2;
    _DAT_009a8dc0 = f_3 - _DAT_009a8d9c / (_DAT_009a8db8 * f_175);
  }
  else {
    _DAT_009a8da4 = _DAT_009a8db8 * f_1925 + (float)(int)(&STAFF_Y0)[DAT_009a8db4];
    in_ST0 = (float10)(int)(&STAFF_Y0)[DAT_009a8da8];
    _DAT_009a8da0 = (float)((float10)_DAT_009a8dac * (float10)f_525 + in_ST0);
    _DAT_009a8d9c = (_DAT_009a8da0 - _DAT_009a8da4) / f_2;
    _DAT_009a8dc0 = _DAT_009a8d9c / (_DAT_009a8db8 * f_175) + f_11;
  }
LAB_00578456:
  P2 = _DAT_009a8dc0 - _DAT_009a8dc8;
  P1 = f_4;
  P3 = f_0;
  if ((DAT_020b9440 == f_4) && (DAT_020b9450 != f_999)) {
    P3 = f_5;
    P4 = (DAT_020b9450 + P2) - DAT_020b944c;
    P5 = f_0;
  }
LAB_005784e8:
  ffree(in_ST0);
  return;
}


