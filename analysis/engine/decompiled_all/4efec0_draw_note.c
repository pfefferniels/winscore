// draw_note @ 004efec0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_note(void)

{
  uint uVar1;
  int iVar2;
  float10 in_ST0;
  float10 fVar3;
  float10 extraout_ST1;
  
  _DAT_008d196c = NPT;
  DAT_01a9f360 = STEP * f_7;
  DAT_008d1968 = IP4 / 100;
  if (DAT_008d1968 < 0) {
    DAT_008d1968 = -DAT_008d1968;
  }
  if (DAT_008d1968 != 0) {
    IP4 = IP4 % 100;
  }
  _DAT_01f93fc0 = f_1;
  if (P20 != f_0) {
    _DAT_01f93fc0 = P20;
  }
  if (P15 != f_0) {
    STEP = P15 * STEP;
    DAT_02091cfc = 0;
    DAT_008d1968 = 0;
  }
  DAT_01f95ce0 = STEP;
  if (DAT_008d1968 == 1) {
    DAT_01f95ce0 = STEP * f_0_6;
  }
  DAT_02091d04 = 0;
  if (IP10 == 0x6e) {
    DAT_02091d04 = 0x6e;
    IP10 = 10;
    P10 = f_10;
  }
  DAT_008d1964 = IP6;
  if ((IP6 < -2) && (IP6 / 0x14 != -1)) {
    if (IP6 != -3) {
      ffree(in_ST0);
      in_ST0 = (float10)note_special_head();
      goto LAB_004f06b3;
    }
    DAT_008d1964 = 3;
  }
  _DAT_008d1960 = f_0;
  DAT_01f95cf0 = f_17;
  DAT_008d195c = DAT_008d1964 % 1000;
  if ((DAT_008d195c == 2) || (DAT_008d195c == 3)) {
    DAT_01f95cf0 = f_19;
  }
  DAT_01f95cf0 = DAT_01f95ce0 * DAT_01f95cf0 * _DAT_01f93fc0;
  if (P10 != f_0) {
    _DAT_01c585f0 = DAT_01f95cf0;
    if (P10 != f_10) {
      if (P10 == f_20) {
        in_ST0 = (float10)DAT_01f95cf0;
        _DAT_01c585f0 = (float)-in_ST0;
      }
      else {
        _DAT_01c585f0 = STEP * f_6 * P10;
      }
    }
    X_POS = _DAT_01c585f0 + X_POS;
    IP10 = 0;
  }
  IP16 = 0;
  iVar2 = IP12;
  if (IP12 < 0) {
    iVar2 = -IP12;
  }
  if (99 < iVar2) {
    IP16 = IP12 / 100;
    IP12 = IP12 % 100;
    if (IP12 < 0) {
      IP12 = -IP12;
    }
  }
  if ((0 < IP12) && (DAT_008d1958 = IP2 + IP12 * -2 + 3, 0 < DAT_008d1958)) {
    in_ST0 = (float10)(int)(&STAFF_Y0)[DAT_008d1958] + (float10)Y_POS;
    Y_POS = (float)(in_ST0 - (float10)(int)(&STAFF_Y0)[IP2]);
  }
  if ((IP30 != 0) || (-2 < IP7 && ((IP4 < 2 || 0xc < IP4) || IP16 != 0))) {
    ffree(in_ST0);
    in_ST0 = (float10)note_ledger_lines();
  }
  if ((-1 < DAT_008d1964) || (DAT_008d1964 < -0x13)) {
    ffree(in_ST0);
    in_ST0 = (float10)note_head();
  }
  DAT_01f95cf4 = IP9 % 10;
  DAT_01a9f364 = IP5 % 100;
  DAT_01f95cec = DAT_01a9f364 / 10;
  DAT_020b945c = P8;
  if (DAT_01f95cf4 != 0) {
    ffree(in_ST0);
    in_ST0 = (float10)note_tails();
  }
  DAT_01a9f364 = DAT_01a9f364 % 10;
  if (DAT_01a9f364 != 0) {
    ffree(in_ST0);
    in_ST0 = (float10)note_accidental();
  }
  if (DAT_01f95cec == 0) {
    DAT_01f95cec = 1;
    if (6 < IP4) {
      DAT_01f95cec = 2;
    }
  }
  else {
    ffree(in_ST0);
    in_ST0 = (float10)note_stem();
  }
  DAT_008d1958 = IP9;
  if (9 < IP9) {
    _DAT_008d1948 = f_0;
    uVar1 = IP4 & 1;
    if ((uVar1 != 0) && (IP4 < 0)) {
      uVar1 = uVar1 - 2;
    }
    if ((int)uVar1 < 0) {
      uVar1 = -uVar1;
    }
    if (uVar1 == 1) {
      _DAT_008d1948 = DAT_01a9f360;
    }
    ffree(in_ST0);
    fVar3 = (float10)amod(&P9,&f_1);
    _DAT_008d1944 = (float)fVar3;
    if (f_0_9 < _DAT_008d1944) {
      _DAT_008d1944 = f_0_9 - _DAT_008d1944;
    }
    if (999 < DAT_008d1958) {
      _DAT_008d1944 = _DAT_008d1944 + f_0_284;
      DAT_008d1958 = DAT_008d1958 + -1000;
    }
    in_ST0 = extraout_ST1;
    if (99 < DAT_008d1958) {
      in_ST0 = (float10)_DAT_008d1948;
      _DAT_008d1948 = (float)-in_ST0;
      DAT_008d1958 = DAT_008d1958 + -100;
    }
    _DAT_008d1940 = f_18;
    if (((IP8 == 0) && (DAT_01f95cf4 != 0)) && (DAT_01f95cec == 1)) {
      _DAT_008d1940 = f_16_2;
    }
    _DAT_008d1940 = (_DAT_008d1944 * f_60 + _DAT_008d1940) * DAT_01f95ce0;
    if (((DAT_01f95cec != 1) && (DAT_01f95cf4 == 0)) && (DAT_008d1964 == 7 || DAT_008d1964 == -1)) {
      _DAT_008d1940 = _DAT_008d1940 / f_2;
    }
    _DAT_008d1940 = _DAT_01f93fc0 * _DAT_008d1940 + X_POS;
    if (P19 != f_0) {
      _DAT_008d1948 = DAT_01a9f360 * P19 + _DAT_008d1948;
    }
    _DAT_008d1948 = Y_POS + _DAT_008d1948;
    DAT_008d1958 = DAT_008d1958 / 10;
    _DAT_008d1944 = f_1;
    if (DAT_008d1968 == 1) {
      _DAT_008d1944 = f_0_6;
    }
    if (P31 != f_0) {
      _DAT_008d193c = f_238;
      _DAT_008d1940 = _DAT_008d1940 - ((P31 - f_1) * f_238 * DAT_01f95ce0) / f_25;
      _DAT_008d1944 = _DAT_008d1944 * P31;
    }
    while( true ) {
      ffree(in_ST0);
      in_ST0 = (float10)draw_clef(&DAT_008d1940,&DAT_008d1948,&DAT_00766454,&DAT_008d1944,
                                  &DAT_008d1944);
      DAT_008d1958 = DAT_008d1958 + -1;
      if (DAT_008d1958 < 1) break;
      _DAT_008d1940 = DAT_01f95ce0 * f_13 + _DAT_008d1940;
    }
  }
  if (IP11 != 0) {
    if (OUTPUT_MODE < 0) {
      IP10 = IP28;
    }
    ffree(in_ST0);
    in_ST0 = (float10)note_marks();
    IP10 = 0;
    IP1 = 1;
  }
LAB_004f06b3:
  ffree(in_ST0);
  return;
}


