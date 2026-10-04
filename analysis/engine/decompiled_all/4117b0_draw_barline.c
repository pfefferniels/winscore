// draw_barline @ 004117b0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_barline(void)

{
  bool bVar1;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  float local_94;
  int local_90;
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
  
  if (IP4 == 999) {
    ffree(in_ST0);
    in_ST0 = thunk_FUN_0054e546(&DAT_01f95d58,&DAT_007d12dc);
    P4 = (DAT_01f95d58 - P2) + f_1;
    local_94 = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
    IP4 = (int)ROUND(P4);
    P10 = f_0;
    DAT_020b9464 = f_0;
    P11 = f_0;
    DAT_020b9468 = f_0;
    DAT_020b944c = P4;
    local_90 = IP4;
  }
  bVar1 = IP5 == -0x2c;
  if (bVar1) {
    IP5 = 0;
    P5 = f_0;
  }
  IP44 = (int)bVar1;
  if ((P7 != f_0) && (P15 == f_0)) {
    X_POS = P7 * f_150 + X_POS;
  }
  DAT_01f95d58 = X_POS;
  DAT_01f95d20 = IP4;
  DAT_01f95d24 = IP5;
  DAT_01f95d48 = P6;
  if (IP4 < 0) {
    if ((OUTPUT_MODE < 0) || (DAT_007924c0 < 0)) {
      local_68 = 0;
      goto LAB_00412293;
    }
    DAT_01f95d20 = -IP4;
    P5 = f_7;
    DAT_01f95d24 = 7;
    P8 = f_0_3;
    P9 = f_1_5;
  }
  else {
    local_6c = 0;
  }
  DAT_01f95d28 = NPT;
  if (MAX_STAFF < DAT_01f95d20 + CUR_STAFF + -1) {
    DAT_01f95d20 = (MAX_STAFF - CUR_STAFF) + 1;
  }
  if (P10 == f_0) {
    DAT_01f95d38 = f_3;
    if (DAT_01f95d24 < 9) {
      local_60 = 0;
    }
    else {
      DAT_01f95d38 = f_1;
      if (DAT_01f95d24 == 10) {
        DAT_01f95d38 = f_7;
      }
      local_5c = 0;
    }
  }
  else {
    local_64 = 0;
    DAT_01f95d38 = P10;
  }
  ffree(in_ST0);
  fVar2 = (float10)staff_level_y(&DAT_01f95d38);
  DAT_01f95d44 = (float)fVar2;
  if (DAT_01f95d20 == 0) {
    DAT_01f95d20 = 1;
  }
  DAT_01f95d2c = CUR_STAFF;
  CUR_STAFF = CUR_STAFF + DAT_01f95d20 + -1;
  if (P11 == f_0) {
    DAT_01f95d38 = f_11;
    if (DAT_01f95d24 < 9) {
      local_54 = 0;
    }
    else {
      DAT_01f95d38 = f_13;
      if (DAT_01f95d24 == 10) {
        DAT_01f95d38 = f_7;
      }
      local_50 = 0;
    }
  }
  else {
    local_58 = 0;
    DAT_01f95d38 = P11;
  }
  ffree(extraout_ST1);
  fVar2 = (float10)staff_level_y(&DAT_01f95d38);
  DAT_01f95d3c = (float)fVar2;
  CUR_STAFF = DAT_01f95d2c;
  in_ST0 = extraout_ST1_00;
  if (DAT_01f95d24 == 0) {
    if (DAT_01f95d48 != f_0) {
      local_48 = 0;
      _DAT_01f95d68 = DAT_01f95d58 - (P6 + f_1) * _DAT_0078b480;
      _DAT_01f95d6c = DAT_01f95d58;
      local_3c = 0;
      goto LAB_00411fad;
    }
    ffree(extraout_ST1_00);
    in_ST0 = barline_stroke();
    if (IP44 == 0) {
      local_44 = 0;
    }
    else {
      P4 = f_0;
      IP5 = -0x2c;
      ffree(in_ST0);
      in_ST0 = draw_rest();
      local_40 = 0;
    }
    goto LAB_00412293;
  }
  local_4c = 0;
  _DAT_02052c08 = STEP;
  if (P17 != f_0) {
    _DAT_02052c08 = P17 * f_25;
  }
  if (6 < DAT_01f95d24) {
    local_38 = 0;
    if (DAT_01f95d24 == 8) {
      ffree(extraout_ST1_00);
      in_ST0 = barline_brace();
    }
    else {
      if (DAT_01f95d24 == 9) {
        if (IP8 != 3) {
          ffree(extraout_ST1_00);
          in_ST0 = barline_bracket();
        }
        _DAT_01f95d68 = DAT_01f95d58 - _DAT_02052c08 * f_9_6;
        _DAT_01f95d6c = _DAT_01f95d68 - _DAT_02052c08 * f_4_5;
        goto LAB_00411fad;
      }
      if (DAT_01f95d24 == 10) {
        _DAT_01f95d6c = DAT_01f95d58 - _DAT_02052c08 * f_21;
        _DAT_01f95d68 = _DAT_01f95d6c - _DAT_02052c08 * f_15;
        _DAT_01f95d5c = 1;
        Var3 = extraout_ST1_00;
        goto LAB_00412022;
      }
      DAT_01f95d38 = P5;
      P5 = (float)(((float10)DAT_01f95d3c - (float10)(int)(&STAFF_Y0)[DAT_01f95d2c]) /
                  ((float10)STEP * (float10)f_7));
      P6 = P3;
      Y_POS = DAT_01f95d44;
      IP7 = 1;
      IP10 = (int)(OUTPUT_MODE != 0);
      if (IP6 != 0) {
        IP10 = IP6;
      }
      if (P8 == f_0) {
        P8 = f_1;
      }
      if (P9 == f_0) {
        P9 = f_2;
      }
      ffree((float10)DAT_01f95d3c - (float10)(int)(&STAFF_Y0)[DAT_01f95d2c]);
      in_ST0 = draw_line();
      P5 = DAT_01f95d38;
      P6 = DAT_01f95d48;
      local_1c = 0;
    }
    goto LAB_00412293;
  }
  DAT_01f95d48 = f_0;
  _DAT_007d12d4 = _DAT_02052c08 * f_6 * P13;
  _DAT_007d12d8 = _DAT_02052c08 * f_6 * P14;
  if (DAT_01f95d24 < 4) {
    if (DAT_01f95d24 == 1) {
      ffree(extraout_ST1_00);
      Var3 = barline_stroke();
      DAT_01f95d58 = (DAT_01f95d58 - _DAT_02052c08 * f_7_5) - _DAT_007d12d4;
      ffree(Var3);
      in_ST0 = barline_stroke();
      local_30 = 0;
      goto LAB_00412293;
    }
    Var3 = extraout_ST1_00;
    if (DAT_01f95d24 != 2) {
      if (DAT_01f95d24 != 3) goto LAB_00411f52;
LAB_00411e5e:
      X_POS = (X_POS - _DAT_007d12d4) - _DAT_007d12d8;
      local_94 = f_m25_5;
      ffree(in_ST0);
      Var3 = barline_dots(&local_94,&DAT_01f95d20);
      local_28 = 0;
    }
    DAT_01f95d4c = DAT_01f95d58;
    DAT_01f95d58 = (DAT_01f95d58 - _DAT_02052c08 * f_13_8) - _DAT_007d12d4;
    ffree(Var3);
    in_ST0 = barline_stroke();
    DAT_01f95d58 = DAT_01f95d4c;
  }
  else if (DAT_01f95d24 < 7) {
    if (DAT_01f95d24 == 6) {
      X_POS = X_POS - _DAT_007d12d8;
      local_94 = f_m18_36;
      ffree(extraout_ST1_00);
      Var3 = barline_dots(&local_94,&DAT_01f95d20);
      X_POS = _DAT_007d12d4 + X_POS + _DAT_007d12d8 + _DAT_007d12d8;
      ffree(Var3);
      in_ST0 = barline_dots(&DAT_0075f3c4,&DAT_01f95d20);
      local_24 = 0;
    }
    else {
      DAT_01f95d4c = DAT_01f95d58;
      DAT_01f95d58 = _DAT_02052c08 * f_7_8 + DAT_01f95d58 + _DAT_007d12d4;
      ffree(extraout_ST1_00);
      Var3 = barline_stroke();
      DAT_01f95d58 = DAT_01f95d4c;
      X_POS = _DAT_007d12d4 + X_POS + _DAT_007d12d8;
      ffree(Var3);
      in_ST0 = barline_dots(&DAT_0075f3d4,&DAT_01f95d20);
      if (DAT_01f95d24 == 5) {
        X_POS = (X_POS - _DAT_007d12d4) - _DAT_007d12d8;
        goto LAB_00411e5e;
      }
      local_2c = 0;
    }
  }
  else {
LAB_00411f52:
    local_34 = 0;
  }
  while( true ) {
    _DAT_01f95d6c = DAT_01f95d58;
    _DAT_01f95d68 = DAT_01f95d58 - _DAT_02052c08 * f_6;
    local_20 = 0;
LAB_00411fad:
    ffree(in_ST0);
    Var3 = add_point(&DAT_01f95d68,&DAT_01f95d44,&DAT_0075f3c0);
    ffree(Var3);
    Var3 = add_point(&DAT_01f95d6c,&DAT_01f95d3c,&DAT_0075f3bc);
    ffree(Var3);
    Var3 = add_point(&DAT_01f95d6c,&DAT_01f95d3c,&DAT_0075f3b8);
    _DAT_01f95d5c = 0;
    local_18 = 0;
LAB_00412022:
    if (IP5 == 10) {
      if ((IP8 == 0) || (IP8 == 2)) {
        ffree(Var3);
        Var3 = add_point(&DAT_01f95d6c,&DAT_01f95d44,&DAT_01f95d5c);
        ffree(Var3);
        Var3 = add_point(&DAT_01f95d68,&DAT_01f95d44,&DAT_0075f3bc);
      }
      else {
        ffree(Var3);
        Var3 = add_point(&DAT_01f95d68,&DAT_01f95d44,&DAT_01f95d5c);
      }
      ffree(Var3);
      in_ST0 = add_point(&DAT_01f95d68,&DAT_01f95d3c,&DAT_0075f3bc);
      if ((IP8 == 0) || (IP8 == 1)) {
        ffree(in_ST0);
        in_ST0 = add_point(&DAT_01f95d6c,&DAT_01f95d3c,&DAT_0075f3bc);
      }
      local_10 = 0;
    }
    else {
      local_14 = 0;
      ffree(Var3);
      Var3 = add_point(&DAT_01f95d6c,&DAT_01f95d44,&DAT_01f95d5c);
      ffree(Var3);
      Var3 = add_point(&DAT_01f95d68,&DAT_01f95d44,&DAT_0075f3bc);
      ffree(Var3);
      Var3 = add_point(&DAT_01f95d68,&DAT_01f95d3c,&DAT_0075f3bc);
      ffree(Var3);
      in_ST0 = add_point(&DAT_01f95d6c,&DAT_01f95d3c,&DAT_0075f3bc);
    }
    if ((IP8 == 0) || (IP8 == 1)) {
      ffree(in_ST0);
      in_ST0 = add_point(&DAT_01f95d6c,&DAT_01f95d3c,&DAT_0075f3bc);
    }
    if (DAT_01f95d24 != 6) break;
    DAT_01f95d24 = 0;
    DAT_01f95d58 = _DAT_02052c08 * f_13 + DAT_01f95d58 + _DAT_007d12d4;
    local_8 = 0;
  }
  local_c = 0;
LAB_00412293:
  if ((P18 != f_0) && (P5 < f_2)) {
    ffree(in_ST0);
    in_ST0 = barline_gap();
  }
  ffree(in_ST0);
  return;
}


