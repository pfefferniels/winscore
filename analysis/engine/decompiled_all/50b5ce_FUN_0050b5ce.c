// FUN_0050b5ce @ 0050b5ce (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050b5ce(void)

{
  int iVar1;
  unkbyte10 in_ST0;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  unkbyte10 extraout_ST0_02;
  unkbyte10 extraout_ST0_03;
  unkbyte10 extraout_ST0_04;
  unkbyte10 extraout_ST0_05;
  unkbyte10 extraout_ST0_06;
  unkbyte10 extraout_ST0_07;
  unkbyte10 extraout_ST0_08;
  unkbyte10 extraout_ST0_09;
  unkbyte10 extraout_ST0_10;
  unkbyte10 extraout_ST0_11;
  unkbyte10 extraout_ST0_12;
  unkbyte10 extraout_ST0_13;
  unkbyte10 Var2;
  float10 fVar3;
  unkbyte10 extraout_ST0_14;
  unkbyte10 extraout_ST0_15;
  unkbyte10 extraout_ST0_16;
  unkbyte10 extraout_ST0_17;
  unkbyte10 extraout_ST0_18;
  unkbyte10 extraout_ST0_19;
  unkbyte10 extraout_ST0_20;
  unkbyte10 extraout_ST0_21;
  unkbyte10 extraout_ST0_22;
  float *local_74;
  undefined4 *local_70;
  undefined4 local_6c [8];
  int local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  DAT_00791444 = 0xffffffff;
  local_6c[0] = 0;
  ffree(in_ST0);
  local_4c = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670f0,0,&DAT_007957fc);
  Var2 = extraout_ST0;
  if (local_4c == 0) {
    local_6c[0] = 0;
    ffree(extraout_ST0);
    local_48 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670f0,0,&DAT_00795834);
    Var2 = extraout_ST0_00;
    if (local_48 == 0) {
      _DAT_00940bd4 = DAT_01aae2f0 / f_0_018;
      _DAT_00940bd0 = STEP / f_25;
      if (IP11 == -9999) {
        local_44 = 0;
LAB_0050bb20:
        ffree(Var2);
        Var2 = thunk_FUN_0054c590(&P1,&DAT_020b9440,&DAT_007670cc);
        if (IP11 == -9999) {
          if (P5 == f_0) {
            P5 = f_1;
          }
          if (P6 == f_0) {
            P6 = P5;
          }
          P5 = _DAT_00940bd0 * P5;
          P6 = _DAT_00940bd0 * P6;
          if (200 < IP2) {
            X_POS = X_POS + f_34050;
          }
          _DAT_00940bc8 = ((float)DAT_01aae2f4 + X_POS) * DAT_01aae2f0;
          fVar3 = (float10)(int)(&STAFF_Y0)[CUR_STAFF] +
                  (float10)P4 * (float10)f_175 * (float10)_DAT_00940bd0;
          DAT_00940bc0 = (float)(((float10)DAT_01aae2f8 + fVar3) * (float10)DAT_01aae2f0);
          local_6c[0] = 0;
          local_74 = (float *)&DAT_00940bc8;
          ffree(fVar3);
          local_20 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670e4,&local_74,&DAT_00795a28);
          Var2 = extraout_ST0_14;
          if (local_20 == 0) {
            local_74 = &DAT_00940bc0;
            ffree(extraout_ST0_14);
            local_20 = FUN_005fc980(local_6c,&DAT_007670e0,&local_74);
            Var2 = extraout_ST0_15;
          }
          if (local_20 == 0) {
            if (IP12 != 0) {
              local_6c[0] = 0;
              local_74 = (float *)(float)-(float10)P12;
              ffree((float10)P12);
              local_1c = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670c4,&local_74,&DAT_00795a44)
              ;
              Var2 = extraout_ST0_16;
              if (local_1c != 0) goto LAB_0050be93;
            }
            local_74 = (float *)(_DAT_00940bd4 * P5);
            local_6c[0] = 0;
            ffree(Var2);
            local_18 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670c0,&local_74,&DAT_00795a64);
            Var2 = extraout_ST0_17;
            if (local_18 == 0) {
              local_74 = (float *)(_DAT_00940bd4 * P6);
              ffree(extraout_ST0_17);
              local_18 = FUN_005fc980(local_6c,&DAT_007670c4,&local_74);
              Var2 = extraout_ST0_18;
            }
            if (local_18 == 0) {
              local_6c[0] = 0;
              local_74 = (float *)(float)-(float10)P7;
              ffree((float10)P7);
              local_14 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670c0,&local_74,&DAT_00795a84)
              ;
              Var2 = extraout_ST0_19;
              if (local_14 == 0) {
                local_74 = (float *)(float)-(float10)P8;
                ffree((float10)P8);
                local_14 = FUN_005fc980(local_6c,&DAT_007670c4,&local_74);
                Var2 = extraout_ST0_20;
              }
              if (local_14 == 0) goto LAB_0050be07;
            }
          }
        }
        else {
          local_24 = 0;
LAB_0050be07:
          ffree(Var2);
          Var2 = FUN_0050bea3();
          local_6c[0] = 0;
          ffree(Var2);
          local_10 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670f0,0,&DAT_00795aa0);
          Var2 = extraout_ST0_21;
          if (local_10 == 0) {
            local_6c[0] = 0;
            ffree(extraout_ST0_21);
            local_c = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670f0,0,&DAT_00795ac4);
            Var2 = extraout_ST0_22;
            if (local_c == 0) goto LAB_0050be9a;
          }
        }
      }
      else {
        _DAT_00940bc8 = DAT_01aae2f0 * DAT_01aae324;
        local_6c[0] = 0;
        local_74 = (float *)&DAT_00940bd4;
        ffree(extraout_ST0_00);
        local_40 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670e4,&local_74,&DAT_0079586c);
        Var2 = extraout_ST0_01;
        if (local_40 == 0) {
          local_74 = (float *)&DAT_00940bc8;
          ffree(extraout_ST0_01);
          local_40 = FUN_005fc980(local_6c,&DAT_007670e0,&local_74);
          Var2 = extraout_ST0_02;
        }
        if (local_40 == 0) {
          _DAT_00940bc8 = (float)DAT_01aae2f4 * DAT_01aae2f0;
          DAT_00940bc0 = (float)DAT_01aae2f8 * DAT_01aae2f0;
          local_6c[0] = 0;
          local_74 = (float *)&DAT_00940bc8;
          ffree(Var2);
          local_3c = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670e4,&local_74,&DAT_007958b4);
          Var2 = extraout_ST0_03;
          if (local_3c == 0) {
            local_74 = &DAT_00940bc0;
            ffree(extraout_ST0_03);
            local_3c = FUN_005fc980(local_6c,&DAT_007670e0,&local_74);
            Var2 = extraout_ST0_04;
          }
          if (local_3c == 0) {
            _DAT_00940bc8 = (float)((&STAFF_Y0)[CUR_STAFF] + DAT_01aae2f8) * f_0_018;
            local_70 = &STAFF_Y0 + CUR_STAFF;
            local_6c[0] = 0;
            local_74 = (float *)0x4;
            ffree(Var2);
            local_38 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670dc,&local_74,&DAT_007958f8);
            Var2 = extraout_ST0_05;
            if (local_38 == 0) {
              local_74 = (float *)&DAT_00940bc8;
              ffree(extraout_ST0_05);
              local_38 = FUN_005fc980(local_6c,&DAT_007670e0,&local_74);
              Var2 = extraout_ST0_06;
            }
            if (local_38 == 0) {
              iVar1 = 7;
              DAT_00940bc0 = 4.2039e-45;
              do {
                local_6c[0] = 0;
                local_74 = &DAT_00940bc0;
                ffree(Var2);
                local_34 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670d8,&local_74,
                                        &DAT_007957cc);
                Var2 = extraout_ST0_07;
                if (local_34 == 0) {
                  local_70 = (undefined4 *)(&P0 + (int)DAT_00940bc0 * 4);
                  local_74 = (float *)0x4;
                  ffree(extraout_ST0_07);
                  local_34 = FUN_005fc980(local_6c,&DAT_007670d4,&local_74);
                  Var2 = extraout_ST0_08;
                }
                if (local_34 != 0) goto LAB_0050be93;
                DAT_00940bc0 = (float)((int)DAT_00940bc0 + 1);
                iVar1 = iVar1 + -1;
              } while (0 < iVar1);
              iVar1 = 3;
              DAT_00940bc0 = 1.4013e-44;
              do {
                local_6c[0] = 0;
                local_74 = &DAT_00940bc0;
                ffree(Var2);
                local_30 = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670d8,&local_74,
                                        &DAT_00795948);
                Var2 = extraout_ST0_09;
                if (local_30 == 0) {
                  local_70 = (undefined4 *)(&P0 + (int)DAT_00940bc0 * 4);
                  local_74 = (float *)0x4;
                  ffree(extraout_ST0_09);
                  local_30 = FUN_005fc980(local_6c,&DAT_007670d4,&local_74);
                  Var2 = extraout_ST0_10;
                }
                if (local_30 != 0) goto LAB_0050be93;
                DAT_00940bc0 = (float)((int)DAT_00940bc0 + 1);
                iVar1 = iVar1 + -1;
              } while (0 < iVar1);
              local_6c[0] = 0;
              local_74 = (float *)&DAT_00940bd0;
              ffree(Var2);
              local_2c = FUN_005fc330(local_6c,0x18,0x784ff01,&DAT_007670e4,&local_74,&DAT_00795978)
              ;
              Var2 = extraout_ST0_11;
              if (local_2c == 0) {
                local_74 = &X_POS;
                ffree(extraout_ST0_11);
                local_2c = FUN_005fc980(local_6c,&DAT_007670e4,&local_74);
                Var2 = extraout_ST0_12;
                if (local_2c == 0) {
                  local_74 = &Y_POS;
                  ffree(extraout_ST0_12);
                  local_2c = FUN_005fc980(local_6c,&DAT_007670e0,&local_74);
                  Var2 = extraout_ST0_13;
                }
              }
              if (local_2c == 0) {
                _DAT_00940bc8 = _DAT_00940bd0 * f_175 * P5;
                DAT_00940bc0 = _DAT_00940bd0 * f_175 * P6;
                local_6c[0] = 0;
                local_74 = (float *)&DAT_00940bc8;
                ffree(Var2);
                Var2 = FUN_005fc330(local_6c,0x18,0x784ff00,&DAT_007670e4,&local_74,&DAT_007959e4);
                local_74 = &DAT_00940bc0;
                ffree(Var2);
                Var2 = FUN_005fc980(local_6c,&DAT_007670e0,&local_74);
                goto LAB_0050bb20;
              }
            }
          }
        }
      }
    }
  }
LAB_0050be93:
  ffree(Var2);
  Var2 = thunk_FUN_004cf1c2();
LAB_0050be9a:
  ffree(Var2);
  return;
}


