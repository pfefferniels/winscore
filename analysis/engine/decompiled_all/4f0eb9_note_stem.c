// note_stem @ 004f0eb9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void note_stem(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  float10 extraout_ST1_02;
  float local_64;
  float local_60;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  _DAT_008d19b8 = f_0;
  if (1 < DAT_01f95cf4) {
    local_60 = (float)(DAT_01f95cf4 * 2 + -2);
    _DAT_008d19b8 = (float)(int)local_60 - f_0_5;
  }
  DAT_020b945c = P8;
  _DAT_008d19b4 = P8;
  iVar1 = IP8;
  if (IP8 < 0) {
    iVar1 = -IP8;
  }
  if (iVar1 < 100) {
    local_3c = 0;
  }
  else {
    _DAT_008d19b0 = DAT_01f95ce0 * f_6;
    _DAT_008d19b4 = P8 - f_100;
    if (IP8 < 0) {
      _DAT_008d19b4 = P8 + f_100;
    }
    if (DAT_01f95cf4 == 0) {
      local_38 = 0;
    }
    else {
      _DAT_008d19ac = _DAT_008d19b8 + _DAT_008d19b4;
      if (DAT_01f95cec == 2) {
        local_34 = 0;
        _DAT_008d19a8 = f_m5_5;
        _DAT_008d19a4 = f_m2_8;
        _DAT_008d19a0 = f_m1_883;
        _DAT_008d199c = f_3_8;
        in_ST0 = (float10)_DAT_008d19ac;
        _DAT_008d19ac = (float)-in_ST0;
      }
      else {
        _DAT_008d19a8 = f_2_8;
        _DAT_008d19a4 = f_5_4;
        _DAT_008d19a0 = f_0_783;
        _DAT_008d199c = f_6_5;
        local_30 = 0;
      }
      _DAT_008d1998 = f_0_6;
      if (P15 != f_0) {
        _DAT_008d1998 = P15;
      }
      local_60 = _DAT_008d19ac * _DAT_008d1998;
      ffree(in_ST0);
      fVar2 = (float10)amod(&P4,&f_100);
      _DAT_008d1994 = (float)(fVar2 + (float10)local_60);
      DAT_008d1990 = (float)CUR_STAFF;
      if (IP12 != 0) {
        CUR_STAFF = CUR_STAFF + IP12 * -2 + 3;
      }
      local_64 = _DAT_008d1998 * _DAT_008d19a8 + _DAT_008d1994;
      ffree(extraout_ST1);
      fVar2 = (float10)staff_level_y(&local_64);
      _DAT_008d19a8 = (float)fVar2;
      local_64 = _DAT_008d1998 * _DAT_008d19a4 + _DAT_008d1994;
      ffree(extraout_ST1_00);
      fVar2 = (float10)staff_level_y(&local_64);
      _DAT_008d19a4 = (float)fVar2;
      CUR_STAFF = (int)DAT_008d1990;
      _DAT_008d19a0 = _DAT_008d19b0 * _DAT_008d19a0 + X_POS;
      _DAT_008d199c = _DAT_008d19b0 * _DAT_008d199c + X_POS;
      ffree(extraout_ST1_01);
      Var3 = add_point(&DAT_008d19a0,&DAT_008d19a8,&DAT_007664a8);
      ffree(Var3);
      in_ST0 = (float10)add_point(&DAT_008d199c,&DAT_008d19a4,&DAT_007664a4);
    }
  }
  IP14 = (int)((_DAT_008d19b8 + f_7 + _DAT_008d19b4) * DAT_01f95ce0 * f_7);
  if (IP6 < 2) {
    local_2c = 0;
  }
  else {
    if ((((IP6 == 2) || (IP6 == 3)) || (899 < IP6)) || (IP6 != 0x8b && (99 < IP6 && IP6 < 199))) {
      IP14 = (int)f_0;
      goto LAB_004f14a9;
    }
    local_24 = 0;
  }
  if (DAT_01f95cec == 2) {
    _DAT_008d1994 = X_POS;
    in_ST0 = (float10)(float)IP14;
    IP14 = (int)(float)-in_ST0;
    local_18 = 0;
  }
  else {
    local_1c = 0;
    _DAT_008d1994 = X_POS + DAT_01f95cf0;
  }
  _DAT_008d19ac = Y_POS;
  _DAT_008d198c = (float)IP14 + Y_POS;
  _DAT_008d19b8 = f_2_1;
  if (IP6 < 4) {
    local_14 = 0;
  }
  else {
    if (IP6 < 9) {
      _DAT_008d19b8 = f_0;
    }
    if (IP6 == 6) {
      _DAT_008d19b8 = f_7;
    }
  }
  if (P17 == f_0) {
    local_10 = 0;
  }
  else {
    local_64 = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
    local_60 = (float)(int)ROUND(P17 / f_100);
    if (local_60 == 0.0) {
      local_c = 0;
    }
    else {
      DAT_008d1990 = local_60;
      if (OUTPUT_MODE == -1) {
        if ((int)local_60 < 0) {
          DAT_008d1990 = (float)-(int)local_60;
        }
        ffree(in_ST0);
        in_ST0 = (float10)thunk_FUN_004d4ed2(&DAT_008d1990);
        _DAT_008d19b0 = (float)(int)DAT_008d1990 * _DAT_0078b480;
        if (DAT_01f95cec != 2) {
          in_ST0 = (float10)_DAT_008d19b0;
          _DAT_008d19b0 = (float)-in_ST0;
        }
        _DAT_008d1994 = _DAT_008d19b0 + _DAT_008d1994;
      }
      else {
        local_8 = 0;
      }
      ffree(in_ST0);
      fVar2 = (float10)amod(&P17,&f_100);
      P17 = (float)fVar2;
      in_ST0 = extraout_ST1_02;
    }
    if (P17 != f_0) {
      _DAT_008d19b8 = P17 * f_7;
    }
  }
  DAT_008d1990 = 0.0;
  if (DAT_01f95cec == 2) {
    in_ST0 = (float10)_DAT_008d19b8;
    _DAT_008d19b8 = (float)-in_ST0;
  }
  _DAT_008d19ac = DAT_01f95ce0 * _DAT_008d19b8 + _DAT_008d19ac;
  ffree(in_ST0);
  Var3 = add_point(&DAT_008d1994,&DAT_008d19ac,&DAT_007664a8);
  ffree(Var3);
  in_ST0 = (float10)add_point(&DAT_008d1994,&DAT_008d198c,&DAT_007664a4);
  if ((DAT_008d1990 != 0.0) || (IP28 != 0)) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_004d4f3f();
  }
LAB_004f14a9:
  ffree(in_ST0);
  return;
}


