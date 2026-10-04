// draw_rest @ 00519c38 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_rest(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  float10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 extraout_ST1_03;
  unkbyte10 extraout_ST1_04;
  float10 extraout_ST1_05;
  unkbyte10 extraout_ST1_06;
  float10 extraout_ST1_07;
  unkbyte10 extraout_ST1_08;
  float local_17c;
  uint local_178;
  int local_174;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 local_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_84;
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
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (IP17 != 0) {
    if (IP17 == 2) {
      CUR_STAFF = IP2 + -1;
    }
    else {
      CUR_STAFF = IP2 + 1;
    }
    ffree(in_ST0);
    in_ST0 = (float10)item_position();
    IP17 = 0;
  }
  iVar1 = IP5;
  if (IP5 < 0) {
    iVar1 = -IP5;
  }
  if (99 < iVar1) {
    IP5 = IP5 % 100;
  }
  DAT_0094e28c = (uint)(99 < iVar1);
  if ((IP6 == -1) && (OUTPUT_MODE != -1)) {
    if (0 < DAT_007924c0) {
      IP6 = 0;
    }
    P26 = f_0_6;
  }
  IP44 = 0;
  if (IP5 == -0x2c) {
    if (IP8 != 0) {
      P16 = -((STEP * f_3_2) / f_25);
    }
    IP44 = 1;
    IP5 = -4;
  }
  if (IP5 < -7) {
    if ((-0xb < IP5) || (IP5 < -0x13)) {
LAB_0051bb5d:
      ffree(in_ST0);
      return;
    }
    local_14c = 0;
  }
  else {
    local_150 = 0;
    if ((IP5 < -3) && (0 < IP6)) {
      IP6 = 0;
    }
  }
  _DAT_01f93f24 = Y_POS;
  if (P15 == f_0) {
    local_144 = 0;
  }
  else {
    STEP = P15 * STEP;
    IP4 = IP4 % 100;
  }
  _DAT_0094e288 = STEP;
  DAT_0094e284 = f_1;
  DAT_01f93f20 = X_POS;
  DAT_01f93ee4 = IP8;
  DAT_01f93ef4 = IP5;
  DAT_01f93ef0 = IP6;
  if ((4 < IP6) && (OUTPUT_MODE < 0)) {
    DAT_01f93ef0 = 0;
  }
  _DAT_01f93f18 = P4;
  iVar1 = IP4;
  if (IP4 < 0) {
    iVar1 = -IP4;
  }
  if (iVar1 < 100) {
    local_140 = 0;
  }
  else {
    DAT_0094e284 = f_0_7;
    _DAT_0094e288 = STEP * f_0_7;
    ffree(in_ST0);
    fVar2 = (float10)amod(&DAT_01f93f18,&DAT_00767948);
    _DAT_01f93f18 = (float)fVar2;
    in_ST0 = extraout_ST1;
  }
  DAT_01f93ee0 = DAT_01f93ef4 + 8;
  if (P10 == f_0) {
    local_13c = 0;
  }
  else {
    unique0x10000884 = (_DAT_0094e288 * P10) / f_25;
    DAT_01f93f20 = unique0x10000884 * f_150 + DAT_01f93f20;
    P3 = unique0x10000884 + P3;
    IP10 = 0;
  }
LAB_00519f2b:
  if ((IP9 == 0) || (6 < DAT_01f93ee0)) {
    local_138 = 0;
  }
  else {
    if (IP9 == -1) {
      in_ST0 = (float10)f_9999;
      _DAT_01f93efc = (float)-in_ST0;
      DAT_0094e280 = ITEM_I;
      if (EDIT_ITEM == 0) {
        DAT_0094e280 = ITEM_COUNT_SAVE;
      }
      DAT_01f93ee8 = 1;
      unique0x100010dd = f_9999;
      for (iVar1 = DAT_0094e280; 0 < iVar1; iVar1 = iVar1 + -1) {
        DAT_01f93eec = (&ITEM_PTR0)[DAT_01f93ee8];
        DAT_0094e27c = (int)ROUND((float)(&ITEM_P2)[DAT_01f93eec]);
        local_178 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        IP2 = (int)ROUND(P2);
        local_174 = IP2;
        if (IP2 < DAT_0094e27c) {
          local_130 = 0;
        }
        else {
          if ((((IP2 != DAT_0094e27c) || ((float)(&ITEM_P1)[DAT_01f93eec] != f_3)) || (f_m4 <= P5))
             || ((float)(&ITEM_P3)[DAT_01f93eec] <= P3)) {
            if ((float)(&ITEM_P1)[DAT_01f93eec] != f_14) {
              local_128 = 0;
              goto LAB_0051a348;
            }
          }
          else {
            local_12c = 0;
          }
          local_178 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          DAT_0094e278 = (int)ROUND((float)(&ITEM_LEN)[DAT_01f93eec]);
          DAT_01f93ef8 = f_0;
          if (2 < DAT_0094e278) {
            DAT_01f93ef8 = (float)(&ITEM_P3)[DAT_01f93eec];
          }
          _DAT_0094e274 = f_1;
          if ((((float)(&ITEM_P4)[DAT_01f93eec] != f_0) && (3 < DAT_0094e278)) &&
             ((float)(&ITEM_P1)[DAT_01f93eec] == f_14)) {
            _DAT_0094e274 = ABS((float)(&ITEM_P4)[DAT_01f93eec]);
          }
          in_ST0 = (float10)DAT_0094e27c + (float10)_DAT_0094e274;
          if ((float10)IP2 < in_ST0) {
            local_174 = DAT_0094e278;
            if ((DAT_01f93ef8 < unique0x10000dbb) && (P3 < DAT_01f93ef8)) {
              ram0x01f93f00 = DAT_01f93ef8;
              DAT_0094e270 = 0;
              if (4 < DAT_0094e278) {
                local_178 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                DAT_0094e270 = (int)ROUND((float)(&ITEM_P5)[DAT_01f93eec]);
                local_174 = DAT_0094e270;
              }
              if (6 < DAT_0094e270) {
                DAT_0094e270 = 0;
              }
              _DAT_0094e26c = (float)(&ITEM_P1)[DAT_01f93eec];
            }
            if ((_DAT_01f93efc < DAT_01f93ef8) && (DAT_01f93ef8 < P3)) {
              _DAT_01f93efc = DAT_01f93ef8;
              DAT_0094e268 = 0;
              if (4 < DAT_0094e278) {
                local_178 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
                DAT_0094e268 = (int)ROUND((float)(&ITEM_P5)[DAT_01f93eec]);
                local_174 = DAT_0094e268;
              }
              if (6 < DAT_0094e268) {
                DAT_0094e268 = 0;
              }
            }
          }
          else {
            local_124 = 0;
            local_174 = DAT_0094e278;
          }
        }
LAB_0051a348:
        local_120 = 0;
        DAT_01f93ee8 = DAT_01f93ee8 + 1;
      }
      if (unique0x10000dbb == f_9999) {
        local_11c = 0;
        goto LAB_0051a655;
      }
      DAT_01f93ef8 = _DAT_0094e288 / f_25;
      in_ST0 = (float10)P3 - (float10)_DAT_01f93efc;
      if ((float10)DAT_01f93ef8 * (float10)f_7 < in_ST0) {
        _DAT_01f93efc = P3 - DAT_01f93ef8 * f_4_5;
        DAT_0094e268 = 0;
      }
      if (DAT_01f93ee0 == 3) {
        if (_DAT_0094e26c == f_14) {
          if (DAT_0094e270 != 0) {
            unique0x100009af =
                 unique0x10000dbb - DAT_01f93ef8 * *(float *)(&DAT_00796a1c + DAT_0094e270 * 4);
          }
          if (DAT_0094e268 != 0) {
            _DAT_01f93efc = DAT_01f93ef8 * (float)(&DAT_00796a04)[DAT_0094e268] + _DAT_01f93efc;
          }
        }
        DAT_01f93f1c = (ram0x01f93f00 - P3) + _DAT_01f93efc;
        _DAT_0094e264 = f_3;
        unique0x100009ec = DAT_01f93ef8 * f_3 + f_0_5;
        if (unique0x100009ec < ram0x01f93f00 - DAT_01f93f1c) {
          DAT_01f93f1c = ram0x01f93f00 - unique0x100009ec;
        }
        if (EDIT_ITEM != 0) {
          local_114 = 0;
          DAT_020b9460 = DAT_01f93f1c;
          goto LAB_0051a916;
        }
        P9 = DAT_01f93f1c;
        local_110 = 0;
        goto LAB_0051a916;
      }
      local_118 = 0;
      DAT_01f93ef8 = f_0_056;
      if (DAT_01f93ee0 == 4) {
        DAT_01f93ef8 = f_0_137;
      }
      unique0x10000962 = unique0x10000dbb - _DAT_01f93efc;
      in_ST0 = (float10)unique0x10000962 * (float10)f_0_5 + (float10)_DAT_01f93efc;
      P9 = (float)(in_ST0 - (float10)_DAT_0094e288 * (float10)DAT_01f93ef8);
      if (EDIT_ITEM == 0) {
        DAT_0094e260 = (&ITEM_PTR0)[ITEM_I];
        if ((f_8 < (float)(&ITEM_LEN)[DAT_0094e260]) && ((float)(&ITEM_P1)[DAT_0094e260] == f_2)) {
          *(float *)(&ITEM_P9 + DAT_0094e260 * 4) = P9;
        }
      }
      else {
        DAT_020b9460 = P9;
        DAT_0205274c = 1;
      }
      DAT_01f93ef4 = 0;
      if ((DAT_01f93ee0 < -4) && (DAT_01f93ee0 != -6)) {
        P6 = (ram0x01f93f00 * f_1_04167) / STEP;
        if (EDIT_ITEM != 0) {
          DAT_020b9454 = P6;
        }
      }
      else {
        local_104 = 0;
      }
    }
    else {
      local_134 = 0;
    }
    DAT_01f93f20 = P9 * f_150;
  }
LAB_0051a655:
  DAT_01f93ef8 = f_0;
  if (0 < DAT_01f93ee0) {
    DAT_01f93ef8 = *(float *)(DAT_01f93ee0 * 4 + 0x7969a4);
  }
  if (0xc < DAT_01f93ee0) {
    DAT_01f93ef8 = f_4;
  }
  _DAT_01f93f10 = f_2;
  if (P15 != f_0) {
    _DAT_01f93f10 = P15 * f_2;
  }
  if (DAT_0094e284 == f_1) {
    local_100 = 0;
LAB_0051a748:
    do {
      if (DAT_01f93ef0 == 0) {
        local_f4 = 0;
LAB_0051a77b:
        if ((IP5 == -5) && (DAT_01f93ee4 == 0)) {
          DAT_01f93ee4 = -1;
        }
        if (DAT_01f93ee4 == 0) goto LAB_0051b2f6;
        local_ec = 0;
      }
      else {
        if ((DAT_01f93ee0 < 1) || (DAT_01f93ee0 == 4)) goto LAB_0051a77b;
        local_f0 = 0;
      }
      if (DAT_01f93ef0 < 0) goto LAB_0051bb5d;
      if (DAT_01f93ee0 == 3) {
        DAT_01f93f1c = P9;
        DAT_01f93f20 = X_POS;
        local_70 = 0;
LAB_0051a916:
        DAT_01f93f1c = DAT_01f93f1c * f_150;
        local_17c = _DAT_01f93f18 + f_5;
        ffree(in_ST0);
        fVar2 = (float10)staff_level_y(&local_17c);
        DAT_01f93ef8 = (float)fVar2;
        local_17c = _DAT_01f93f18 + f_9;
        ffree(extraout_ST1_00);
        fVar2 = (float10)staff_level_y(&local_17c);
        ram0x01f93f04 = (float)fVar2;
        ffree(extraout_ST1_01);
        Var3 = add_point(&DAT_01f93f20,&DAT_01f93ef8,&DAT_007678fc);
        ffree(Var3);
        Var3 = add_point(&DAT_01f93f20,0x1f93f04,&DAT_007678f8);
        ffree(Var3);
        Var3 = add_point(&DAT_01f93f1c,&DAT_01f93ef8,&DAT_007678fc);
        ffree(Var3);
        Var3 = add_point(&DAT_01f93f1c,0x1f93f04,&DAT_007678f8);
        local_17c = _DAT_01f93f18 + f_7_75;
        ffree(Var3);
        fVar2 = (float10)staff_level_y(&local_17c);
        DAT_01f93ef8 = (float)fVar2;
        local_17c = _DAT_01f93f18 + f_6_25;
        ffree(extraout_ST1_02);
        fVar2 = (float10)staff_level_y(&local_17c);
        ram0x01f93f04 = (float)fVar2;
        ffree(extraout_ST1_03);
        Var3 = add_point(&DAT_01f93f20,&DAT_01f93ef8,&DAT_007678e4);
        ffree(Var3);
        Var3 = add_point(&DAT_01f93f1c,&DAT_01f93ef8,&DAT_007678f8);
        ffree(Var3);
        Var3 = add_point(&DAT_01f93f1c,0x1f93f04,&DAT_007678f8);
        ffree(Var3);
        in_ST0 = (float10)add_point(&DAT_01f93f20,0x1f93f04,&DAT_007678f8);
        if (DAT_01f93ee4 < 1) goto LAB_0051bb5d;
        in_ST0 = ((float10)DAT_01f93f1c - (float10)DAT_01f93f20) * (float10)f_0_5 +
                 (float10)DAT_01f93f20;
        DAT_01f93f20 = (float)(in_ST0 - (float10)_DAT_0094e288 * (float10)f_8);
        local_108 = 0;
      }
      else {
        local_74 = 0;
        if (OUTPUT_MODE < 0) {
          local_6c = 0;
        }
        else {
          _DAT_01f93efc = f_16_8;
          if (DAT_01f93ee0 == 4) {
            _DAT_01f93efc = f_40_8;
          }
          _DAT_01f93efc = _DAT_0094e288 * _DAT_01f93efc;
          if ((DAT_01f93ef0 < 5) || (DAT_01f93ee0 < -2)) {
            local_68 = 0;
          }
          else {
            DAT_01f93f14 = STEP * f_42 + _DAT_01f93f24;
            unique0x10000a76 = P6 * f_150;
            local_17c = DAT_01f93f20 - unique0x10000a76;
            ffree(in_ST0);
            Var3 = add_point(&local_17c,&DAT_01f93f14,&DAT_007678fc);
            local_17c = _DAT_01f93efc + DAT_01f93f20 + ram0x01f93f00;
            ffree(Var3);
            in_ST0 = (float10)add_point(&local_17c,&DAT_01f93f14,&DAT_007678f8);
            DAT_01f93ef0 = 0;
            if (DAT_01f93ee4 == 0) {
              local_64 = 0;
              goto LAB_0051b2f6;
            }
          }
        }
      }
      if (DAT_01f93ee4 == 0) goto code_r0x0051ab3a;
      ffree(in_ST0);
      Var3 = thunk_FUN_0054c590(&P1,&DAT_0094e290,&DAT_007678d0);
      ram0x01f93f04 = f_1;
      if (P12 != f_0) {
        ram0x01f93f04 = P12;
      }
      if (DAT_01f93ee4 < 0) {
        local_5c = 0;
        ram0x01f93f00 = f_13;
        if (IP5 < 0) {
          _DAT_01f93efc = f_1_42;
        }
        else if (IP5 < 1) {
          _DAT_01f93efc = f_0_95;
          local_18 = 0;
        }
        else {
          _DAT_01f93efc = f_1_35;
          if (1 < IP5) {
            _DAT_01f93efc = f_1_15;
          }
          local_14 = 0;
        }
        _DAT_0094e248 = DAT_0094e284;
        if ((P15 != f_0) && (DAT_0094e284 == f_1)) {
          _DAT_0094e248 = P15;
        }
        _DAT_0094e244 = _DAT_0094e288 * f_6;
        fVar2 = ((float10)(_DAT_0094e244 * _DAT_01f93efc) + (float10)DAT_01f93f20) -
                (float10)(ram0x01f93f04 * f_1_69 * _DAT_0094e244);
        _DAT_01f93efc = (float)((float10)P16 * (float10)f_150 + fVar2);
        unique0x10000b6f = DAT_0094e284 * ram0x01f93f04;
        if (DAT_01f93ee4 == -2) {
          fVar2 = (float10)unique0x10000b6f;
          ram0x01f93f04 = (float)-fVar2;
          ram0x01f93f00 = f_1;
        }
        else {
          local_10 = 0;
          unique0x1000109d = unique0x10000b6f;
        }
        if (f_0 < P4) {
          unique0x10000b84 = _DAT_01f93f18 + ram0x01f93f00;
        }
        local_17c = P11 + ram0x01f93f00;
        ffree(fVar2);
        fVar2 = (float10)staff_level_y(&local_17c);
        ram0x01f93f00 = (float)fVar2;
        DAT_01f93ee4 = 0x1f;
        if (IP8 == -3) {
          DAT_01f93ee4 = 0x114;
        }
        ffree(extraout_ST1_06);
        Var3 = draw_clef(&DAT_01f93efc,0x1f93f00,&DAT_01f93ee4,0x1f93f08,0x1f93f04);
        local_c = 0;
      }
      else {
        DAT_01f93eec = DAT_01f93ee4;
        if (DAT_01f93ee4 < 10) {
          _DAT_01f93efc = f_1_255;
          if (DAT_01f93ee4 != 1) {
            _DAT_01f93efc = f_1_55;
          }
          local_54 = 0;
        }
        else {
          local_58 = 0;
          DAT_01f93ee8 = DAT_01f93ee4 % 10;
          iVar1 = (DAT_01f93ee4 % 100) / 10;
          if (DAT_01f93ee4 < 100) {
            _DAT_01f93efc = f_3_25;
            if (DAT_01f93ee4 == 0xb) {
              _DAT_01f93efc = f_2_65;
              local_48 = 0;
            }
            else {
              local_4c = 0;
              if (DAT_01f93ee8 == 1) {
                _DAT_01f93efc = f_2_95;
              }
              if (iVar1 == 1) {
                _DAT_01f93efc = f_3_05;
              }
              local_44 = 0;
            }
          }
          else {
            local_50 = 0;
            if (DAT_01f93ee4 / 100 == 1) {
              local_40 = 0;
              if (iVar1 == 1) {
                local_34 = 0;
                _DAT_01f93efc = f_4_55;
                if (DAT_01f93ee8 == 1) {
                  _DAT_01f93efc = f_4_3;
                }
              }
              else {
                _DAT_01f93efc = f_4_55;
                local_30 = 0;
LAB_0051aff1:
                if (DAT_01f93ee8 == 1) {
                  _DAT_01f93efc = f_4_45;
                }
                local_2c = 0;
              }
            }
            else {
              if (iVar1 == 1) {
                local_3c = 0;
                _DAT_01f93efc = f_4_7;
                goto LAB_0051aff1;
              }
              _DAT_01f93efc = f_4_9;
              if (DAT_01f93ee8 == 1) {
                _DAT_01f93efc = f_4_6;
              }
              local_38 = 0;
            }
          }
        }
        ram0x01f93f00 = f_1_42;
        if (DAT_01f93ee0 == 4) {
          ram0x01f93f00 = f_3_4;
        }
        _DAT_01f93efc =
             (ram0x01f93f00 - ram0x01f93f04 * _DAT_01f93efc) * _DAT_0094e288 * f_6 * DAT_0094e284;
        IP8 = 0;
        P8 = f_0;
        P9 = f_0;
        P6 = ram0x01f93f04 * f_1_2 * DAT_0094e284;
        if (P14 == f_0) {
          P14 = f_1_05;
          IP7 = DAT_0078b474;
          IP9 = -1;
          local_24 = 0;
        }
        else {
          local_28 = 0;
          local_178 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          IP7 = (int)ROUND(P14);
          P14 = f_0;
          IP9 = 0;
          local_174 = IP7;
        }
        local_17c = _DAT_01f93f18 + f_12 + P11;
        ffree(Var3);
        fVar2 = (float10)staff_level_y(&local_17c);
        Y_POS = (float)fVar2;
        X_POS = (float)((float10)P16 * (float10)f_150 +
                       (float10)_DAT_01f93efc + (float10)DAT_01f93f20);
        DAT_01f93ee8 = IP1;
        DAT_0094e24c = P5;
        P5 = (float)DAT_01f93eec;
        IP17 = 0;
        ffree((float10)_DAT_01f93efc + (float10)DAT_01f93f20);
        Var3 = draw_number(&DAT_01f93eec);
        DAT_020b945c = (float)DAT_01f93eec;
        P5 = DAT_0094e24c;
        IP1 = DAT_01f93ee8;
      }
      ffree(Var3);
      in_ST0 = (float10)thunk_FUN_0054c590(&DAT_0094e290,&P1,&DAT_007678d0);
      if (DAT_01f93ee0 == 3) goto LAB_0051bb5d;
      DAT_01f93ee4 = 0;
      local_1c = 0;
    } while( true );
  }
  if (-1 < DAT_01f93ee0) {
    _DAT_01f93f10 = f_1_4;
    if (DAT_01f93ee0 < 10) {
      local_f8 = 0;
    }
    else {
      DAT_01f93ef8 = DAT_01f93ef8 + f_0_7;
      if (8 < DAT_01f93ee0) {
        DAT_01f93ef8 = DAT_01f93ef8 + f_0_7;
      }
    }
    goto LAB_0051a748;
  }
  local_fc = 0;
  goto LAB_0051b349;
code_r0x0051ab3a:
  local_60 = 0;
  ram0x01f93f00 = f_8;
  if (2 < DAT_01f93ef4) {
    ram0x01f93f00 = f_10;
  }
  unique0x10000ae1 = _DAT_01f93f18 + ram0x01f93f00;
  ffree(in_ST0);
  fVar2 = (float10)staff_level_y(0x1f93f00);
  ram0x01f93f04 = (float)fVar2;
  DAT_01f93ee8 = DAT_01f93ef4 + 4;
  if (8 < DAT_01f93ee8) {
    DAT_01f93ee8 = 8;
  }
  unique0x00017200 = (float)(&DAT_007969e4)[DAT_01f93ee8];
  _DAT_01f93efc = DAT_01f93f20;
  ffree(extraout_ST1_04);
  fVar2 = (float10)amod(&P6,&f_1);
  ram0x01f93f08 = (float)fVar2;
  in_ST0 = extraout_ST1_05;
  if (ram0x01f93f08 != f_0) {
    _DAT_01f93efc = ram0x01f93f08 * f_60 * _DAT_0094e288 + _DAT_01f93efc;
  }
  do {
    _DAT_01f93efc = _DAT_0094e288 * ram0x01f93f00 + _DAT_01f93efc;
    ffree(in_ST0);
    in_ST0 = (float10)draw_clef(&DAT_01f93efc,0x1f93f04,&DAT_007678d8,&DAT_0094e284,&DAT_0094e284);
    register0x00000000 = f_13;
    DAT_01f93ef0 = DAT_01f93ef0 + -1;
  } while (0 < DAT_01f93ef0);
  local_8 = 0;
LAB_0051b2f6:
  DAT_01f93ef8 = _DAT_01f93f18 + DAT_01f93ef8;
  if (DAT_01f93ee0 < 10) {
    local_e8 = 0;
  }
  else {
    if (9 < DAT_01f93ee0) {
      DAT_01f93f20 = DAT_01f93f20 - _DAT_0094e288 * f_3;
    }
    DAT_01f93ee0 = 9;
  }
LAB_0051b349:
  while( true ) {
    if (DAT_01f93ee0 < 0) {
      DAT_01f93ef8 = _DAT_01f93f18 + f_8;
    }
    ffree(in_ST0);
    fVar2 = (float10)staff_level_y(&DAT_01f93ef8);
    _DAT_01f93f24 = (float)fVar2;
    if (IP44 != 0) {
      DAT_01f93ee0 = 0x50;
      DAT_0094e284 = DAT_0094e284 * f_0_83;
    }
    if (DAT_01f93ee0 < 3) break;
    local_e4 = 0;
    local_17c = (float)(DAT_01f93ee0 + 0x23);
    ffree(extraout_ST1_07);
    in_ST0 = (float10)draw_clef(&DAT_01f93f20,&DAT_01f93f24,&local_17c,&DAT_0094e284,&DAT_0094e284);
    if (DAT_01f93ef4 < 2) {
      local_98 = 0;
      if (DAT_0094e28c != 0) {
        _DAT_0094e25c = _DAT_0094e288 / f_25;
        _DAT_0094e264 = P3;
        DAT_01f93ee8 = IP5 + 4;
        local_17c = P4;
        ffree(in_ST0);
        fVar2 = (float10)FUN_005ff874(&local_17c,&DAT_00767948);
        _DAT_0094e258 = (float)fVar2;
        if ((P5 < f_m101) && (f_0 < P9)) {
          _DAT_0094e264 = P9;
        }
        P3 = _DAT_0094e264 - _DAT_0094e25c * (float)(&DAT_00796988)[DAT_01f93ee8];
        P4 = _DAT_0094e258 + (float)(&DAT_00796950)[DAT_01f93ee8];
        if ((5 < DAT_01f93ee8) && (STEP != _DAT_0094e288)) {
          P4 = P4 + f_1;
        }
        _DAT_0094e254 = f_1_9;
        if (DAT_01f93ee8 < 4) {
          _DAT_0094e254 = f_1;
        }
        ffree(extraout_ST1_08);
        Var3 = item_position();
        iVar1 = IP4;
        if (IP4 < 0) {
          iVar1 = -IP4;
        }
        if (99 < iVar1) {
          _DAT_0094e254 = _DAT_0094e254 * f_0_7;
        }
        ffree(Var3);
        Var3 = draw_symbol(&X_POS,&Y_POS,&DAT_00767860,&DAT_0094e254,&DAT_0094e254,&DAT_007678f8,
                           &DAT_007678f8,&DAT_007678f8);
        _DAT_0094e250 = (float)(&DAT_0079696c)[DAT_01f93ee8];
        if (IP6 == 1) {
          _DAT_0094e250 = _DAT_0094e250 + f_1_9;
        }
        P3 = _DAT_0094e25c * _DAT_0094e250 + _DAT_0094e264;
        ffree(Var3);
        item_position();
        local_17c = (float)-(float10)_DAT_0094e254;
        ffree((float10)_DAT_0094e254);
        in_ST0 = (float10)draw_symbol(&X_POS,&Y_POS,&DAT_00767860,&local_17c,&DAT_0094e254,
                                      &DAT_007678f8,&DAT_007678f8,&DAT_007678f8);
      }
      if (((7 < DAT_01f93ee0) || (DAT_01f93ee0 < 6)) || (DAT_01f93ee8 = IP4 % 100, P30 < f_0))
      goto LAB_0051bb5d;
      if (DAT_01f93ee8 < *(int *)(DAT_01f93ee0 * 4 + 0x7969c0)) {
        if (*(int *)(DAT_01f93ee0 * 4 + 0x7969c8) < DAT_01f93ee8) goto LAB_0051bb5d;
      }
      else {
        local_84 = 0;
      }
      _DAT_01f93efc = _DAT_0094e288 * f_8;
      unique0x10000d9b = _DAT_0094e288 * f_25;
      local_17c = DAT_01f93f20 - _DAT_01f93efc;
      ffree(in_ST0);
      Var3 = add_point(&local_17c,&DAT_01f93f24,&DAT_007678fc);
      local_17c = ram0x01f93f00 + DAT_01f93f20;
      ffree(Var3);
      in_ST0 = (float10)add_point(&local_17c,&DAT_01f93f24,&DAT_007678f8);
      goto LAB_0051bb5d;
    }
    DAT_01f93ef4 = DAT_01f93ef4 + -1;
    DAT_01f93ef8 = _DAT_01f93f10 + DAT_01f93ef8;
    DAT_01f93f20 = _DAT_0094e288 * f_4_5 + DAT_01f93f20;
    local_94 = 0;
  }
  DAT_01f93f28 = DAT_0094e284;
  DAT_0094e284 = DAT_0094e284 * f_0_83;
  DAT_01f93f2c = 0;
  ram0x01f93f08 = P6;
  in_ST0 = extraout_ST1_07;
  if (-1 < DAT_01f93ee0) {
LAB_0051b601:
    while( true ) {
      while( true ) {
        local_17c = (float)(0x76 - DAT_01f93ee0);
        ffree(in_ST0);
        in_ST0 = (float10)draw_symbol(&DAT_01f93f20,&DAT_01f93f24,&local_17c,&DAT_0094e284,
                                      &DAT_0094e284,&DAT_007678f8,&DAT_007678f8,&DAT_007678f8);
        if (DAT_01f93f2c < 1) goto LAB_0051bb5d;
        if (3 < DAT_01f93f2c) break;
        DAT_01f93f20 = ram0x01f93f08 * f_24 + DAT_01f93f14;
        if (DAT_01f93f2c == 1) {
          local_d8 = 0;
          goto LAB_0051b71b;
        }
        if (DAT_01f93f2c == 3) {
          local_d4 = 0;
          DAT_01f93f2c = 0;
          local_cc = 0;
code_r0x0051b76e:
          DAT_01f93ee0 = 1;
          local_b0 = 0;
        }
        else {
          DAT_01f93f2c = 0;
          local_d0 = 0;
code_r0x0051b79a:
          DAT_01f93ee0 = 2;
          local_b8 = 0;
        }
      }
      if (6 < DAT_01f93f2c) goto LAB_0051bb5d;
      if (DAT_01f93f2c == 6) break;
      DAT_01f93f20 = DAT_01f93f14;
      DAT_01f93ee0 = 2;
      if (DAT_01f93f2c == 5) {
        DAT_01f93ee0 = 1;
      }
      DAT_01f93f2c = 6;
      local_c8 = 0;
    }
    DAT_01f93f20 = ram0x01f93f08 * f_36 + DAT_01f93f14;
    DAT_01f93f2c = 0;
    local_c4 = 0;
    goto LAB_0051b71b;
  }
  local_e0 = 0;
  if (P6 == f_0) {
    ram0x01f93f08 = f_1;
  }
  unique0x10000c8b = STEP * ram0x01f93f08;
  DAT_01f93f14 = DAT_01f93f20;
  iVar1 = -DAT_01f93ee0;
  DAT_01f93ee0 = iVar1 + -2;
  switch(iVar1) {
  case 3:
LAB_0051b71b:
    DAT_01f93ee0 = 6;
    DAT_0094e284 = DAT_01f93f28;
    DAT_01f93ef0 = 0;
    local_bc = 0;
    goto LAB_0051a655;
  case 4:
    goto LAB_0051b601;
  case 5:
    goto code_r0x0051b50c;
  case 6:
    goto code_r0x0051b76e;
  case 7:
    DAT_01f93f2c = 1;
    uStack_ac = 0;
    break;
  case 8:
    DAT_01f93f2c = 2;
    uStack_a8 = 0;
    break;
  case 9:
    DAT_01f93f2c = 4;
    goto code_r0x0051b5c0;
  case 10:
    DAT_01f93f2c = 3;
    uStack_a0 = 0;
    break;
  case 0xb:
    DAT_01f93f2c = 5;
    uStack_9c = 0;
code_r0x0051b5c0:
    DAT_01f93f20 = DAT_01f93f20 - unique0x10000c8b * f_36;
    uStack_a4 = 0;
    goto code_r0x0051b76e;
  default:
    goto LAB_0051b5e7;
  }
  DAT_01f93f20 = DAT_01f93f20 - unique0x10000c8b * f_24;
  goto code_r0x0051b76e;
LAB_0051b5e7:
  DAT_01f93ee0 = 8;
  local_c0 = 0;
  goto LAB_00519f2b;
code_r0x0051b50c:
  DAT_01f93f2c = 1;
  uStack_b4 = 0;
  DAT_01f93f20 = DAT_01f93f20 - unique0x10000c8b * f_24;
  goto code_r0x0051b79a;
}


