// draw_box @ 00433530 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_box(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var4;
  float10 fVar5;
  float10 fVar6;
  unkbyte10 Var7;
  unkbyte10 in_ST1;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  unkbyte10 extraout_ST1_05;
  unkbyte10 extraout_ST1_06;
  unkbyte10 extraout_ST1_07;
  unkbyte10 extraout_ST1_08;
  unkbyte10 extraout_ST1_09;
  unkbyte10 extraout_ST1_10;
  float local_b4 [2];
  float local_ac;
  uint local_a8;
  int local_a4;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
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
  
  DAT_020b945c = P8;
  ffree(in_ST1);
  ffree(in_ST0);
  Var4 = push_words(&DAT_00760144,&P1);
  Var7 = extraout_ST1;
  if (IP26 == -1) {
    if (OUTPUT_MODE == -1) {
      local_80 = 0;
      goto LAB_00433ecc;
    }
    P26 = f_99;
    IP8 = 3;
    P8 = f_3;
  }
  DAT_01cadce4 = OUTPUT_MODE;
  DAT_01cadce0 = NPT;
  _DAT_01c58a08 = P6;
  DAT_01cadcec = P7;
  if (P7 == f_0) {
    DAT_01cadcec = P6;
  }
  if ((P16 == f_1) && (IP5 == 3 || (uint)IP5 < 2)) {
    _DAT_007f7500 = f_22_857;
    if (DAT_0078b4e8 != 0) {
      _DAT_007f7500 = f_8_999;
    }
    _DAT_01c58a08 = _DAT_007f7500 * P6;
    DAT_01cadcec = _DAT_007f7500 * DAT_01cadcec;
  }
  DAT_01f93e80 = 1;
  if (P13 != f_0) {
    DAT_01f93e80 = 2;
  }
  if (OUTPUT_MODE == -1) {
    if (IP12 < 0) {
      if (0 < IP8) {
        ffree(extraout_ST1);
        ffree(Var4);
        Var4 = thunk_FUN_004d4ed2(&IP8);
        Var7 = extraout_ST1_04;
      }
      local_74 = 0;
      goto LAB_00433a1a;
    }
    local_78 = 0;
    ffree(extraout_ST1);
    ffree(Var4);
    Var4 = thunk_FUN_0050e203();
    Var7 = extraout_ST1_00;
  }
  else {
    local_7c = 0;
  }
  if ((IP5 != 0) && (IP5 != 3)) {
    if (IP8 < 1) {
      local_6c = 0;
    }
    else {
      local_a8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      IP8 = (int)ROUND((_DAT_01c589f8 * STEP * P8) / f_25);
      _DAT_01cadcf0 = f_7_1429 / (_DAT_01c589f8 * STEP);
      local_a4 = IP8;
    }
LAB_00433a1a:
    if (IP10 < 0) {
      IP10 = IP10 + 0x168;
    }
    if (IP11 == 0) {
      IP11 = 0x168;
    }
    if (IP11 < IP10) {
      IP11 = IP11 + 0x168;
    }
    if (IP12 == 0) {
      IP12 = 1;
    }
    DAT_007f74fc = IP12;
    _DAT_0078d86c = STEP * f_0_035;
    DAT_0078d860 = IP10 * 2 + 1;
    DAT_007f74f8 = IP11 * 2 + 1;
    do {
      IP12 = DAT_007f74fc * 2;
      DAT_0078d870 = _DAT_0078d86c * _DAT_01c58a08;
      _DAT_01c58a04 = _DAT_0078d86c * DAT_01cadcec;
      _DAT_01cadcf8 = DAT_0078d860;
      DAT_0078d864 = DAT_007f74f8;
      if (DAT_01cadce4 == -1) {
        if ((IP12 < 0xb) && (-1 < IP12)) {
          ffree(Var7);
          ffree(Var4);
          Var4 = thunk_FUN_0050e352();
          Var7 = extraout_ST1_06;
          if (-1 < IP5) goto LAB_00433e3c;
          local_60 = 0;
          goto LAB_00433ecc;
        }
        local_64 = 0;
      }
      else {
        local_68 = 0;
      }
      DAT_007f74f4 = 0;
      if (IP12 < 1) {
        DAT_0078d864 = DAT_007f74f8 + -1;
        DAT_007f74f0 = DAT_007f74fc;
        for (; (int)(0xb4 % (longlong)DAT_007f74fc) != 0; DAT_007f74fc = DAT_007f74fc + 1) {
          DAT_007f74f0 = DAT_007f74f0 + -1;
          if ((int)(0xb4 % (longlong)DAT_007f74f0) == 0) {
            local_48 = 0;
            DAT_007f74fc = DAT_007f74f0;
            goto LAB_00433be7;
          }
          local_44 = 0;
        }
        local_4c = 0;
LAB_00433be7:
        DAT_007f74f0 = -DAT_007f74fc;
        DAT_007f74f4 = DAT_007f74f0 + 1;
        IP12 = 2;
      }
      else {
        local_50 = 0;
      }
      while( true ) {
        fVar5 = (float10)DAT_0078d870 * (float10)*(float *)(&DAT_01c58a1c + _DAT_01cadcf8 * 4) +
                (float10)X_POS;
        fVar6 = (float10)_DAT_01c58a04 * (float10)(float)(&DAT_01c58a20)[_DAT_01cadcf8] +
                (float10)Y_POS;
        local_ac = (float)fVar5;
        local_b4[0] = (float)fVar6;
        ffree(fVar6);
        ffree(fVar5);
        Var4 = add_point(&local_ac,local_b4,&DAT_01f93e80);
        DAT_01f93e80 = 0;
        iVar3 = IP12;
        if (DAT_007f74f4 == 0) {
          local_40 = 0;
        }
        else {
          DAT_007f74f4 = DAT_007f74f4 + -1;
          if (DAT_007f74f4 == 0) {
            DAT_007f74f4 = DAT_007f74f0 + 1;
            DAT_01f93e80 = 1;
            local_38 = 0;
            iVar3 = DAT_007f74f0 * 2;
          }
          else {
            local_3c = 0;
          }
        }
        _DAT_01cadcf8 = iVar3 + _DAT_01cadcf8;
        if (DAT_0078d864 < _DAT_01cadcf8) break;
        if (0x2d1 < _DAT_01cadcf8) {
          _DAT_01cadcf8 = 1;
          DAT_0078d864 = DAT_0078d864 + -0x2d2;
        }
      }
      local_34 = 0;
      Var7 = extraout_ST1_05;
      if (IP5 < 0) {
        local_30 = 0;
        goto LAB_00433ecc;
      }
      if (IP8 < 1) {
        local_2c = 0;
        goto LAB_00433e3c;
      }
      if (DAT_01cadce4 == 0) {
        _DAT_01cadcf0 = (float)IP8 * _DAT_01cadcf0;
        IP8 = 0;
      }
      else if (DAT_01cadce4 < 1) {
        if (DAT_007f74fc < 0) goto LAB_00433e35;
        local_24 = 0;
      }
      IP8 = IP8 + -1;
      _DAT_01c58a08 = _DAT_01cadcf0 + _DAT_01c58a08;
      DAT_01cadcec = _DAT_01cadcf0 + DAT_01cadcec;
      DAT_01f93e80 = 1;
      local_20 = 0;
    } while( true );
  }
  local_70 = 0;
  if (IP8 == 0) {
    local_1c = 0;
  }
  else if (DAT_01cadce4 == -1) {
    local_18 = 0;
    ffree(Var7);
    ffree(Var4);
    Var4 = thunk_FUN_004d4ed2(&IP8);
    Var7 = extraout_ST1_01;
  }
  else {
    local_a8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    IP8 = (int)ROUND((STEP * P8 * _DAT_01c589f8) / f_25);
    _DAT_01cadcf0 = _DAT_01c589f8 * f_25;
    local_14 = 0;
    local_a4 = IP8;
  }
  fVar1 = STEP * f_3_5 * _DAT_01c58a08;
  fVar2 = STEP * f_3_5 * DAT_01cadcec;
  _DAT_01f93e68 = fVar1 + X_POS;
  DAT_01f93e60 = X_POS - fVar1;
  DAT_01f93e74 = fVar2 + Y_POS;
  DAT_01f93e64 = Y_POS - fVar2;
  DAT_0078d870 = f_0;
  if (IP10 != 0) {
    DAT_0078d870 = STEP * f_7 * P10;
  }
  while( true ) {
    _DAT_01f93e70 = DAT_0078d870 + _DAT_01f93e68;
    DAT_01f93e78 = DAT_0078d870 + DAT_01f93e60;
    DAT_01f93e6c = DAT_01f93e64;
    _DAT_01f93e7c = DAT_01f93e74;
    if (IP5 == 3) {
      ffree(Var7);
      ffree(Var4);
      Var4 = FUN_00434b6d(&DAT_01cadce4);
      Var7 = extraout_ST1_02;
    }
    else {
      ffree(Var7);
      ffree(Var4);
      Var4 = box_outline();
      Var7 = extraout_ST1_03;
    }
    if ((DAT_01cadce4 == -1) || (IP8 < 1)) break;
    if (DAT_01cadce4 == 0) {
      _DAT_01cadcf0 = (float)IP8 * _DAT_01cadcf0;
      IP8 = 0;
    }
    else {
      local_c = 0;
    }
    IP8 = IP8 + -1;
    DAT_01f93e60 = DAT_01f93e60 - _DAT_01cadcf0;
    _DAT_01f93e68 = _DAT_01cadcf0 + _DAT_01f93e68;
    DAT_01f93e64 = DAT_01f93e64 - _DAT_01cadcf0;
    DAT_01f93e74 = _DAT_01cadcf0 + DAT_01f93e74;
    local_8 = 0;
  }
  local_10 = 0;
  goto LAB_00433e3c;
LAB_00433e35:
  local_28 = 0;
LAB_00433e3c:
  if (IP9 != 0) {
    ffree(Var7);
    ffree(Var4);
    Var4 = thunk_FUN_0042a5f4(&DAT_01cadce0,&X_POS,&Y_POS,&P9);
    Var7 = extraout_ST1_07;
  }
  if ((DAT_01cadce4 == -1) && (P8 != f_0)) {
    if (((DAT_007f74fc < 0) || (IP5 == 0)) || (9 < IP12)) {
      local_58 = 0;
      ffree(Var7);
      ffree(Var4);
      Var4 = thunk_FUN_004d4f3f();
      Var7 = extraout_ST1_09;
    }
    else {
      ffree(Var7);
      ffree(Var4);
      Var4 = thunk_FUN_004cf166();
      local_54 = 0;
      Var7 = extraout_ST1_08;
    }
  }
  else {
    local_5c = 0;
  }
LAB_00433ecc:
  ffree(Var7);
  ffree(Var4);
  Var7 = pop_words(&DAT_00760144,&P1);
  ffree(extraout_ST1_10);
  ffree(Var7);
  return;
}


