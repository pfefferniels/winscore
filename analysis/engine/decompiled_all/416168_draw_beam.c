// draw_beam @ 00416168 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_beam(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar4;
  unkbyte10 Var5;
  float10 extraout_ST1;
  float local_cc;
  int local_c8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
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
  undefined4 local_8;
  
  _DAT_01f93fc0 = f_1;
  if (P20 != f_0) {
    _DAT_01f93fc0 = P20;
  }
  DAT_01f93ee0 = OUTPUT_MODE;
  if (P18 == f_0) {
    local_a4 = 0;
  }
  else {
    STEP = P18 * STEP;
    IP4 = 0;
  }
  _DAT_01f93f10 = f_1;
  iVar3 = IP4;
  if (IP4 < 0) {
    iVar3 = -IP4;
  }
  if (iVar3 < 100) {
    local_a0 = 0;
  }
  else {
    _DAT_01f93f10 = f_0_6;
    if (P17 == f_0) {
      P17 = f_0_8;
    }
  }
  DAT_01f93f14 = _DAT_01f93f10 * STEP;
  DAT_007d140c = P3;
  DAT_007d1408 = P6;
  local_cc = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
  DAT_01f93f38 = (int)ROUND(P13);
  DAT_01f95ce0 = DAT_01f93f14;
  local_c8 = DAT_01f93f38;
  if (DAT_01f93f38 == 0) {
    if (P14 != f_0) {
      ffree(in_ST0);
      in_ST0 = FUN_00417221(&P14,&DAT_007d140c);
    }
    if (P15 != f_0) {
      ffree(in_ST0);
      FUN_00417221(&P15,&DAT_007d1408);
    }
    X_POS = DAT_007d140c * f_150;
  }
  else {
    local_9c = 0;
  }
  DAT_01f93f44 = X_POS;
  DAT_01f93f50 = DAT_007d1408 * f_150;
  DAT_01f93ef0 = IP7;
  if (IP7 < 0) {
    DAT_01f93ef0 = -IP7;
  }
  DAT_01f93ee8 = DAT_01f93ef0 / 10;
  DAT_01f93eec = DAT_01f93ef0 % 10;
  DAT_01f93ef8 = IP10;
  _DAT_01f93f18 = f_0;
  DAT_01f93f1c = DAT_01f93f14 * f_10_5;
  if (P21 != f_0) {
    DAT_01f93f1c = P21 * DAT_01f93f1c;
  }
  DAT_01f93f20 = DAT_01f93f14 * f_49;
  DAT_01f93ef4 = IP9;
  register0x00000000 = IP9 / 100;
  fVar1 = DAT_01f93f14 * _DAT_0078b34c * _DAT_01f93fc0;
  if (DAT_01f93ee8 == 1) {
    fVar4 = (float10)fVar1;
    _DAT_01f93f40 = (float)-fVar4;
    DAT_01f93f44 = fVar1 + X_POS;
    DAT_01f93f50 = fVar1 + DAT_01f93f50;
    local_94 = 0;
    DAT_01f93f34 = fVar1;
  }
  else {
    local_98 = 0;
    DAT_01f93f20 = -DAT_01f93f20;
    DAT_01f93f34 = f_0;
    fVar4 = (float10)DAT_01f93f1c;
    DAT_01f93f1c = (float)-fVar4;
    _DAT_01f93f40 = fVar1;
  }
  if (register0x00000000 == 0) {
    local_90 = 0;
  }
  else {
    if (register0x00000000 == 2) {
      local_8c = 0;
    }
    else {
      DAT_01f93f44 = _DAT_01f93f40 + DAT_01f93f44;
      if (register0x00000000 != 3) {
        local_88 = 0;
        goto LAB_00416513;
      }
    }
    DAT_01f93f50 = _DAT_01f93f40 + DAT_01f93f50;
  }
LAB_00416513:
  ffree(fVar4);
  fVar4 = (float10)staff_level_y(&P5);
  DAT_01f93f4c = (float)(fVar4 + (float10)DAT_01f93f20);
  DAT_01f93f48 = Y_POS;
  if (IP1 != -999) {
    DAT_01f93f48 = DAT_01f93f20 + Y_POS;
  }
  fVar4 = extraout_ST1;
  if (DAT_01f93ee0 == 0) {
    local_84 = 0;
  }
  else {
    DAT_01f93f20 = DAT_01f93f14 * f_7;
    if (P17 != f_0) {
      DAT_01f93f20 = P17 * DAT_01f93f20;
    }
    if ((DAT_0078b478 != 0) && (DAT_01f93ee0 == -1)) {
      ffree(extraout_ST1);
      fVar4 = (float10)thunk_FUN_004d4ed2(&DAT_0078b478);
    }
    if (DAT_01f93ee8 == 1) {
      fVar4 = (float10)DAT_01f93f20;
      DAT_01f93f20 = (float)-fVar4;
    }
  }
  if (IP7 < 1) {
    DAT_01f93f68 = P12 * f_0_5;
    if (DAT_01f93f68 == f_0) {
      DAT_01f93f68 = f_2;
    }
    fVar1 = (DAT_01f93f14 * DAT_01f93f68) / f_25;
    _DAT_01f93f64 = P11;
    _DAT_01f93efc = IP11;
    if (IP11 == 0) {
      local_7c = 0;
      _DAT_01f93efc = 9999;
      _DAT_01f93f64 = DAT_007d140c;
      fVar2 = DAT_01f93f14 * f_2_9166 * DAT_01f93f68;
      DAT_01f93f4c = fVar2 + DAT_01f93f48;
      DAT_01f93f48 = DAT_01f93f48 - fVar2;
LAB_00416709:
      DAT_01f93f50 = _DAT_01f93f10 * f_1000 + DAT_01f93f44;
    }
    else {
      if (DAT_01f93f44 == DAT_01f93f50) {
        local_78 = 0;
        goto LAB_00416709;
      }
      local_74 = 0;
    }
    unique0x10000523 = _DAT_01f93f64 - fVar1;
    DAT_01f93f68 = fVar1 + _DAT_01f93f64;
    ram0x01f93f00 = 1;
    ram0x01f93f08 = 0;
    _DAT_01f93f64 = unique0x10000523;
    if (ram0x01f93f04 == 0) {
      local_70 = 0;
    }
    else {
      ram0x01f93f04 = 1;
      ram0x01f93f08 = 1;
      local_6c = 0;
    }
  }
  else {
    local_80 = 0;
    if ((DAT_01f93ef8 == 0) && (IP8 < 1)) {
      local_68 = 0;
      goto LAB_0041699a;
    }
  }
  DAT_01f93f54 = DAT_01f93f44;
  _DAT_01f93f58 = DAT_01f93f48;
  _DAT_01f93f5c = DAT_01f93f4c;
  DAT_01f93f60 = DAT_01f93f50;
  _DAT_01f93f24 = DAT_01f93f50 - DAT_01f93f44;
  DAT_01f93f28 = DAT_01f93f4c - DAT_01f93f48;
  if (_DAT_01f93f24 == f_0) {
    _DAT_01f93f24 = f_100;
  }
  DAT_01f93f2c = DAT_01f93f28 / _DAT_01f93f24;
  _DAT_01f93f30 = DAT_01f93f48 - DAT_01f93f44 * DAT_01f93f2c;
  if (IP7 < 0) {
    local_64 = 0;
    goto LAB_00416fda;
  }
  if (DAT_01f93ef8 == 0) {
    local_60 = 0;
  }
  else {
    _DAT_01f93efc = 0;
    ram0x01f93f00 = 0;
    if (DAT_01f93eec == 0) {
      local_5c = 0;
      fVar4 = ((float10)P11 + (float10)DAT_007d140c) - (float10)(DAT_01f93f34 / f_150);
      _DAT_01f93f64 = (float)((float10)DAT_01f93f14 * (float10)f_0_11333 + fVar4);
      DAT_01f93f68 = (P12 + DAT_007d1408) - DAT_01f93f34 / f_150;
    }
    else {
      if ((P11 != f_0) || (P12 != f_0)) {
        local_58 = 0;
        goto LAB_0041699a;
      }
      local_54 = 0;
    }
    unique0x100005ad = DAT_01f93f14 * f_0_14;
    if (P11 == f_0) {
      _DAT_01f93f64 = unique0x100005ad + DAT_007d140c;
    }
    if (P12 == f_0) {
      DAT_01f93f68 = DAT_007d1408 - unique0x100005ad;
    }
    _DAT_01f93efc = 1;
    ram0x01f93f00 = -2;
    if (DAT_01f93eec == 0) {
      local_50 = 0;
      goto LAB_00416fab;
    }
  }
LAB_0041699a:
  do {
    while( true ) {
      if (DAT_01f93ee0 == 0) {
        local_4c = 0;
        DAT_007d1404 = 0x23;
        if (DAT_01f93ee8 == 1) {
          DAT_007d1404 = -0x23;
        }
        ffree(fVar4);
        Var5 = add_point(&DAT_01f93f44,&DAT_01f93f48,&DAT_0075f540);
        ffree(Var5);
        fVar4 = (float10)add_point(&DAT_01f93f50,&DAT_01f93f4c,&DAT_0075f53c);
        DAT_01f93ee4 = NPT;
        if ((*(int *)(&DAT_02004cb8 + NPT * 4) < 0x2f059) &&
           (*(int *)(&DAT_02004cb4 + NPT * 4) < 0x2f059)) {
          (&PT_X0)[NPT] = *(undefined4 *)(&DAT_01fd3f78 + NPT * 4);
          (&PT_Y0)[DAT_01f93ee4] = *(int *)(&DAT_02004cb8 + DAT_01f93ee4 * 4) + DAT_007d1404;
          (&DAT_01fd3f80)[DAT_01f93ee4] = *(undefined4 *)(&DAT_01fd3f74 + DAT_01f93ee4 * 4);
          (&DAT_02004cc0)[DAT_01f93ee4] = *(int *)(&DAT_02004cb4 + DAT_01f93ee4 * 4) + DAT_007d1404;
          (&DAT_01fd3f84)[DAT_01f93ee4] = (&DAT_01fd3f80)[DAT_01f93ee4];
          (&DAT_02004cc4)[DAT_01f93ee4] = (&DAT_02004cc0)[DAT_01f93ee4] + DAT_007d1404;
          (&DAT_01fd3f88)[DAT_01f93ee4] = (&PT_X0)[DAT_01f93ee4];
          (&DAT_02004cc8)[DAT_01f93ee4] = (&PT_Y0)[DAT_01f93ee4] + DAT_007d1404;
          NPT = DAT_01f93ee4 + 4;
          ram0x01f93f0c = DAT_01fbb8b8;
          if (DAT_01f93ee8 == 1) {
            fVar4 = (float10)DAT_01fbb8b8;
            ram0x01f93f0c = (float)-fVar4;
          }
          unique0x100005e6 = DAT_01f93f4c + ram0x01f93f0c;
          ffree(fVar4);
          fVar4 = (float10)add_point(&DAT_01f93f50,0x1f93f0c,&DAT_0075f53c);
        }
      }
      else {
        DAT_01f93e60 = DAT_01f93f50;
        DAT_01f93e64 = DAT_01f93f20 + DAT_01f93f4c;
        _DAT_01f93e68 = DAT_01f93f50;
        DAT_01f93e6c = DAT_01f93f4c;
        _DAT_01f93e70 = DAT_01f93f44;
        DAT_01f93e74 = DAT_01f93f48;
        DAT_01f93e78 = DAT_01f93f44;
        _DAT_01f93e7c = DAT_01f93f20 + DAT_01f93f48;
        DAT_01f93e80 = 2;
        ffree(fVar4);
        fVar4 = (float10)box_outline();
        local_48 = 0;
      }
      if (DAT_01f93eec < 2) break;
      DAT_01f93eec = DAT_01f93eec + -1;
      DAT_01f93f48 = DAT_01f93f48 - DAT_01f93f1c;
      DAT_01f93f4c = DAT_01f93f4c - DAT_01f93f1c;
    }
    local_44 = 0;
    if (DAT_01f93ef8 == 0) {
      local_40 = 0;
      if (DAT_01f93f38 == 0) {
        local_14 = 0;
        if ((DAT_0078b478 != 0) && (DAT_01f93ee0 == -1)) {
          ffree(fVar4);
          fVar4 = (float10)thunk_FUN_004d4f3f();
        }
        if (0 < IP8) {
          DAT_01f93f48 = f_m24_5;
          if (DAT_01f93ee8 == 1) {
            DAT_01f93f48 = f_6_5;
          }
          DAT_01f93f48 = P19 * f_7 + DAT_01f93f48;
          P19 = f_0;
          ram0x01f93f0c = P16;
          if (P16 == f_0) {
            ram0x01f93f0c = f_0_5;
          }
          DAT_01f93f50 = P6;
          P6 = f_0_875;
          iVar3 = IP4;
          if (IP4 < 0) {
            iVar3 = -IP4;
          }
          if (iVar3 < 100) {
            local_8 = 0;
          }
          else {
            DAT_01f93f48 = DAT_01f93f48 * f_0_7;
            P6 = f_0_6;
          }
          fVar4 = (float10)STEP * (float10)DAT_01f93f48 + (float10)_DAT_01f93f58;
          Y_POS = (float)((float10)ram0x01f93f0c * (float10)DAT_01f93f28 + fVar4);
          IP7 = 1;
          DAT_01f93eec = IP8;
          if (999 < IP8) {
            DAT_01f93eec = IP8 % 1000;
            IP7 = IP8 / 1000 + 1000;
            if (IP7 == 0x40a) {
              IP7 = 1000;
            }
          }
          IP14 = 0;
          P14 = f_0;
          local_cc = _DAT_01f93f24 * ram0x01f93f0c;
          ffree(fVar4);
          fVar4 = (float10)thunk_FUN_0053bfc6(&DAT_01f93eec,&DAT_01f93f54,&local_cc);
          P6 = DAT_01f93f50;
        }
        ffree(fVar4);
        return;
      }
      DAT_01f93f44 = DAT_01f93f54;
      DAT_01f93f50 = DAT_01f93f60;
      DAT_01f93ef8 = DAT_01f93f38;
      DAT_01f93f38 = 0;
      _DAT_01f93f64 = P14;
      DAT_01f93f68 = P15;
      _DAT_01f93efc = (int)ROUND(P14);
      local_cc = (float)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
      unique0x0000a300 = (int)ROUND(P15);
      register0x00000008 = DAT_01f93ef4 % 10;
      local_10 = 0;
    }
    else {
      if (ram0x01f93f00 < 0) {
        local_3c = 0;
      }
      else {
        DAT_01f93f68 = P12;
        _DAT_01f93f64 = P11;
        _DAT_01f93efc = IP11;
        ram0x01f93f00 = IP12;
      }
LAB_00416fab:
      ram0x01f93f04 = 0;
      if (DAT_01f93ef4 != 0) {
        register0x00000000 = (DAT_01f93ef4 % 100) / 10;
      }
    }
LAB_00416fda:
    DAT_01f93eec = DAT_01f93ef8 % 10;
    local_c8 = DAT_01f93ef8 / 10;
    if (DAT_01f93eec < 0) {
      DAT_01f93eec = -DAT_01f93eec;
    }
    _DAT_01f93f18 = (float)local_c8 * DAT_01f93f1c;
    if (_DAT_01f93efc == -1) {
      _DAT_01f93efc = 1;
      _DAT_01f93f64 = DAT_007d140c;
    }
    else {
      local_38 = 0;
    }
    if (ram0x01f93f00 == -1) {
      ram0x01f93f00 = 1;
      DAT_01f93f68 = DAT_007d1408;
    }
    else {
      local_34 = 0;
    }
    if (_DAT_01f93efc != 0) {
      DAT_01f93f44 = _DAT_01f93f64 * f_150 + DAT_01f93f34;
    }
    if (ram0x01f93f00 != 0) {
      DAT_01f93f50 = DAT_01f93f68 * f_150 + DAT_01f93f34;
    }
    if (ram0x01f93f04 == 0) {
      local_30 = 0;
    }
    else {
      if (ram0x01f93f04 == 2) {
        local_2c = 0;
      }
      else {
        DAT_01f93f44 = _DAT_01f93f40 + DAT_01f93f44;
        if (ram0x01f93f04 != 3) {
          local_28 = 0;
          goto LAB_00417127;
        }
      }
      DAT_01f93f50 = _DAT_01f93f40 + DAT_01f93f50;
    }
LAB_00417127:
    unique0x100006c9 = DAT_01f93f14 * f_16_2;
    if (ram0x01f93f00 == 0) {
      DAT_01f93f50 = unique0x100006c9 + DAT_01f93f44;
    }
    if (_DAT_01f93efc == 0) {
      DAT_01f93f44 = DAT_01f93f50 - unique0x100006c9;
    }
    DAT_01f93ef8 = 0;
    if (DAT_01f93f4c == DAT_01f93f48) {
      local_24 = 0;
      DAT_01f93f48 = _DAT_01f93f58 - _DAT_01f93f18;
      DAT_01f93f4c = _DAT_01f93f5c - _DAT_01f93f18;
      local_18 = 0;
    }
    else if (_DAT_01f93efc == 9999) {
      local_20 = 0;
    }
    else {
      DAT_01f93f48 = (DAT_01f93f44 * DAT_01f93f2c + _DAT_01f93f30) - _DAT_01f93f18;
      DAT_01f93f4c = (DAT_01f93f50 * DAT_01f93f2c + _DAT_01f93f30) - _DAT_01f93f18;
      local_1c = 0;
    }
  } while( true );
}


