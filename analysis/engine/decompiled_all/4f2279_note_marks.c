// note_marks @ 004f2279 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void note_marks(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar4;
  unkbyte10 Var5;
  float10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  float local_ac;
  uint local_a8;
  int local_a4;
  undefined4 local_80;
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
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  DAT_01a9f304 = IP11;
  if (IP11 < 0) {
    DAT_01a9f304 = -IP11;
  }
  IP16 = 0;
  DAT_008d1a08 = DAT_01f95ce0;
  DAT_01a9f314 = P13 * f_150;
  if (DAT_01a9f304 == 99) {
    if (P13 == f_0) {
      DAT_01a9f314 = DAT_01f95ce0 * f_13_8;
    }
    DAT_01a9f314 = DAT_01a9f314 + X_POS;
    DAT_01a9f310 = P14;
    if (P14 == f_0) {
      DAT_01a9f310 = f_10;
    }
    DAT_01a9f31c = DAT_01a9f310 * f_150 + X_POS;
    DAT_01a9f320 = Y_POS - DAT_01f95ce0 * f_2_8;
    DAT_01a9f318 = DAT_01f95ce0 * f_2_8 + Y_POS;
    DAT_01f93e80 = 2;
    ffree(in_ST0);
    DAT_01f93e60 = DAT_01a9f314;
    DAT_01f93e64 = DAT_01a9f320;
    _DAT_01f93e68 = DAT_01a9f31c;
    DAT_01f93e6c = DAT_01a9f320;
    _DAT_01f93e70 = DAT_01a9f31c;
    DAT_01f93e74 = DAT_01a9f318;
    DAT_01f93e78 = DAT_01a9f314;
    _DAT_01f93e7c = DAT_01a9f318;
    in_ST0 = (float10)box_outline();
    goto LAB_004f2f29;
  }
  local_80 = 0;
  DAT_01a9f30c = 0;
  if (DAT_01a9f304 < 0x1a) {
    DAT_01a9f30c = *(int *)(&DAT_00794ea8 + DAT_01a9f304 * 4);
  }
  DAT_01a9f314 = DAT_01a9f314 + X_POS;
  DAT_01a9f31c = f_1;
  if ((DAT_01a9f304 == 7) || (0x19 < DAT_01a9f304 && DAT_01a9f304 < 0x1d)) {
    IP16 = DAT_01a9f304 + -0x19;
    DAT_01a9f318 = f_2;
    if (IP16 == 1) {
      DAT_01a9f318 = f_m2_3;
    }
    if (IP16 == 2) {
      DAT_01a9f318 = f_m6_6;
    }
    if (IP16 == 3) {
      DAT_01a9f318 = f_m10_9;
    }
    DAT_01a9f304 = 7;
    DAT_01a9f314 = DAT_01f95ce0 * DAT_01a9f318 + DAT_01a9f314;
    DAT_01a9f31c = f_0_72;
    if (P18 != f_0) {
      DAT_01a9f314 = DAT_01a9f314 - ((P18 - f_1) * f_180 * DAT_01f95ce0) / f_25;
    }
  }
  else {
    local_78 = 0;
  }
  if (P18 != f_0) {
    DAT_01a9f31c = P18 * DAT_01a9f31c;
  }
  DAT_01a9f320 = DAT_01a9f31c;
  DAT_01a9f318 = DAT_01a9f360 + DAT_01a9f360;
  if (DAT_01a9f30c == 1) {
    DAT_01a9f318 = DAT_01a9f360 + DAT_01a9f318;
    DAT_01a9f300 = CUR_STAFF;
    if (IP12 != 0) {
      DAT_01a9f300 = CUR_STAFF + IP12 * -2 + 3;
    }
    if (IP11 < 0) {
      local_70 = 0;
      DAT_01a9f318 = DAT_01a9f318 - DAT_01a9f360 * f_6;
      if (DAT_01f95cec == 2) {
        DAT_01a9f318 = (float)IP14 + DAT_01a9f318 + DAT_01a9f360;
      }
      DAT_01a9f310 = DAT_01a9f360 + ((float)(int)(&STAFF_Y0)[DAT_01a9f300] - Y_POS);
      DAT_01f95cec = 2;
      if (IP11 == -0xe) {
        in_ST0 = (float10)DAT_01a9f31c;
        DAT_01a9f320 = (float)-in_ST0;
      }
      if (DAT_01a9f318 <= DAT_01a9f310) {
        local_60 = 0;
      }
      else {
        local_64 = 0;
LAB_004f27a2:
        DAT_01a9f318 = DAT_01a9f310;
        local_68 = 0;
      }
    }
    else {
      if (DAT_01f95cec == 1) {
        DAT_01a9f318 = (DAT_01a9f318 + (float)IP14) - DAT_01a9f360;
      }
      DAT_01a9f310 = DAT_01a9f360 * f_13 + ((float)(int)(&STAFF_Y0)[DAT_01a9f300] - Y_POS);
      DAT_01f95cec = 1;
      if (DAT_01a9f318 < DAT_01a9f310) goto LAB_004f27a2;
      local_6c = 0;
    }
  }
  else {
    local_74 = 0;
    if (DAT_01f95cec == 1) {
      in_ST0 = (float10)DAT_01a9f318;
      DAT_01a9f318 = (float)-in_ST0;
    }
    if (IP11 < 1) {
      if (DAT_01a9f304 < 0x1e) {
        DAT_01a9f310 = (DAT_01a9f360 * f_0_5 * STEP) / DAT_01f95ce0;
        if (DAT_01f95cec == 1) {
          in_ST0 = (float10)DAT_01a9f310;
          DAT_01a9f310 = (float)-in_ST0;
        }
        DAT_01a9f318 = DAT_01a9f318 - DAT_01a9f310;
      }
      else {
        local_58 = 0;
      }
      DAT_01a9f318 = (float)IP14 - DAT_01a9f318;
    }
    else {
      local_5c = 0;
    }
    if (DAT_01a9f30c < 1) {
      if ((DAT_01f95cec == 1) && (0 < IP11)) {
        local_50 = 0;
      }
      else if ((DAT_01f95cec != 2) || (0 < IP11)) {
        local_4c = 0;
        goto LAB_004f2567;
      }
      in_ST0 = (float10)DAT_01a9f31c;
      DAT_01a9f320 = (float)-in_ST0;
    }
    else {
      local_54 = 0;
    }
LAB_004f2567:
    if (((DAT_01a9f304 == 0x19) || (DAT_01a9f304 == 7)) || (DAT_01a9f304 == 6)) {
      if (IP11 < 0) {
        local_44 = 0;
      }
      else {
        DAT_01a9f300 = IP4;
        DAT_01a9f310 = f_0;
        if ((IP4 < 10) && (DAT_01f95cec == 2)) {
          DAT_01a9f310 = DAT_01a9f360;
        }
        if ((4 < IP4) && (DAT_01f95cec == 1)) {
          in_ST0 = (float10)DAT_01a9f360;
          DAT_01a9f310 = (float)-in_ST0;
        }
        uVar1 = IP4;
        if (IP4 < 0) {
          uVar1 = -IP4;
        }
        uVar3 = uVar1 & 1;
        if ((uVar3 != 0) && ((int)uVar1 < 0)) {
          uVar3 = uVar3 - 2;
        }
        if (uVar3 == 1) {
          DAT_01a9f318 = DAT_01a9f310 + DAT_01a9f318;
        }
      }
    }
    else {
      local_48 = 0;
    }
  }
  if (P14 == f_0) {
    local_40 = 0;
    ffree(in_ST0);
    fVar4 = (float10)amod(&P11,&f_1);
    DAT_01a9f310 = (float)fVar4;
    in_ST0 = extraout_ST1;
    if (DAT_01a9f310 != f_0) {
      DAT_01a9f310 = DAT_01a9f310 * f_10;
      if (DAT_01f95cec == 1) {
        if (DAT_01a9f30c != 1) {
          in_ST0 = (float10)DAT_01a9f310;
          DAT_01a9f310 = (float)-in_ST0;
        }
      }
      else {
        local_34 = 0;
      }
      goto LAB_004f285e;
    }
    local_38 = 0;
  }
  else {
    DAT_01a9f310 = P14;
    local_3c = 0;
LAB_004f285e:
    DAT_01a9f318 = DAT_01a9f360 * DAT_01a9f310 + DAT_01a9f318;
  }
  DAT_01a9f318 = DAT_01a9f318 + Y_POS;
  if (DAT_01a9f304 < 0x14) {
    local_30 = 0;
LAB_004f28e1:
    if (DAT_01a9f304 < 4) {
      DAT_01a9f304 = DAT_01a9f304 + 5;
      DAT_01a9f314 = DAT_008d1a08 * f_18 + DAT_01a9f314;
      DAT_01a9f31c = DAT_01a9f31c * f_0_65;
      local_c = 0;
      DAT_01a9f320 = DAT_01a9f31c;
    }
    else {
      local_10 = 0;
      DAT_01a9f304 = DAT_01a9f304 + 0x11;
    }
LAB_004f29f6:
    DAT_01a9f310 = STEP;
    STEP = DAT_008d1a08;
    DAT_01a9f314 = (_DAT_01f93fc0 * f_8_5 - f_8_5) * DAT_01f95ce0 + DAT_01a9f314;
    while( true ) {
      ffree(in_ST0);
      in_ST0 = (float10)draw_clef(&DAT_01a9f314,&DAT_01a9f318,&DAT_01a9f304,&DAT_01a9f31c,
                                  &DAT_01a9f320);
      if (IP16 < 1) break;
      IP16 = IP16 + -1;
      DAT_01a9f314 = DAT_008d1a08 * f_8_6 + DAT_01a9f314;
    }
  }
  else {
    if (0x1d < DAT_01a9f304) {
      if ((DAT_01a9f304 < 0x29) || (0x2c < DAT_01a9f304)) {
        P6 = f_0_7;
        if (P18 != f_0) {
          P6 = P18 * f_0_7;
        }
        IP7 = 0;
        DAT_01a9f310 = DAT_01a9f360 * f_0_5;
        if (DAT_01f95cec == 1) {
          DAT_01a9f310 = DAT_01a9f360 + DAT_01a9f310;
        }
        Y_POS = DAT_01a9f318 - DAT_01a9f310;
        X_POS = DAT_008d1a08 * f_4 + DAT_01a9f314;
        IP8 = 0;
        P8 = f_0;
        DAT_008d19f0 = P5;
        local_a4 = DAT_01a9f304 + -0x1e;
        P5 = (float)local_a4;
        IP9 = 0;
        DAT_008d19ec = DAT_020b945c;
        local_ac = (float)(DAT_01a9f304 + -0x1e);
        ffree(in_ST0);
        in_ST0 = (float10)draw_number(&local_ac);
        DAT_020b945c = DAT_008d19ec;
        P5 = DAT_008d19f0;
      }
      else {
        _DAT_008d1a04 = P14 + P4;
        _DAT_008d1a00 = P5;
        _DAT_008d19fc = P13;
        DAT_008d19f8 = IP2;
        ffree(in_ST0);
        fVar4 = (float10)push_words(&DAT_00766578,&P1);
        for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
          *(float *)(&P0 + iVar2 * 4) = f_0;
        }
        for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
          *(undefined4 *)(&IP0 + iVar2 * 4) = 0;
        }
        P1 = f_6;
        IP7 = -10;
        _DAT_008d19f4 = f_5;
        P3 = X_POS / f_150 + _DAT_008d19fc;
        P17 = f_0_7;
        P12 = f_3;
        if (0x29 < DAT_01a9f304) {
          _DAT_008d19f4 = f_5 + f_1;
        }
        if (f_19 < _DAT_008d1a00) {
          fVar4 = (float10)_DAT_008d19f4;
          _DAT_008d19f4 = (float)-fVar4;
          IP7 = -0x14;
        }
        P4 = _DAT_008d19f4 + _DAT_008d1a04;
        local_a8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        IP4 = (int)ROUND(P4);
        IP1 = -999;
        ffree(fVar4);
        local_ac = P4;
        local_a4 = IP4;
        fVar4 = (float10)FUN_005ff874(&local_ac,&f_100);
        local_ac = (float)fVar4;
        ffree(extraout_ST1_00);
        fVar4 = (float10)staff_level_y(&local_ac);
        Y_POS = (float)fVar4;
        IP10 = DAT_01a9f304 + -0x1e;
        ffree(extraout_ST1_01);
        Var5 = draw_beam();
        ffree(Var5);
        in_ST0 = (float10)pop_words(&DAT_00766578,&P1);
        IP2 = DAT_008d19f8;
      }
      goto LAB_004f2f29;
    }
    local_2c = 0;
    if (DAT_01a9f304 == 0x19) {
      DAT_01a9f304 = 0x77;
      local_1c = 0;
      goto LAB_004f29f6;
    }
    local_20 = 0;
    if (DAT_01a9f304 == 0x18) {
      local_18 = 0;
      DAT_01a9f304 = 0x15;
      goto LAB_004f28e1;
    }
    IP8 = DAT_01a9f304 + -0x14;
    IP7 = 0;
    X_POS = DAT_01a9f314;
    Y_POS = DAT_01a9f318 - DAT_01a9f360;
    DAT_01a9f318 = P5;
    P5 = DAT_01a9f31c;
    IP6 = 0;
    DAT_01a9f310 = STEP;
    STEP = DAT_008d1a08;
    ffree(in_ST0);
    in_ST0 = (float10)draw_code7();
    P5 = DAT_01a9f318;
  }
  STEP = DAT_01a9f310;
LAB_004f2f29:
  ffree(in_ST0);
  return;
}


