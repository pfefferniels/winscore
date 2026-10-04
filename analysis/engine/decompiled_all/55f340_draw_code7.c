// draw_code7 @ 0055f340 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void draw_code7(void)

{
  int iVar1;
  unkbyte10 in_ST0;
  unkbyte10 Var2;
  float10 fVar3;
  unkbyte10 Var4;
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
  unkbyte10 extraout_ST1_11;
  unkbyte10 extraout_ST1_12;
  unkbyte10 extraout_ST1_13;
  unkbyte10 extraout_ST1_14;
  unkbyte10 extraout_ST1_15;
  unkbyte10 extraout_ST1_16;
  unkbyte10 extraout_ST1_17;
  unkbyte10 extraout_ST1_18;
  unkbyte10 extraout_ST1_19;
  unkbyte10 extraout_ST1_20;
  unkbyte10 extraout_ST1_21;
  unkbyte10 extraout_ST1_22;
  unkbyte10 extraout_ST1_23;
  unkbyte10 extraout_ST1_24;
  unkbyte10 extraout_ST1_25;
  unkbyte10 extraout_ST1_26;
  unkbyte10 extraout_ST1_27;
  unkbyte10 extraout_ST1_28;
  unkbyte10 extraout_ST1_29;
  unkbyte10 extraout_ST1_30;
  unkbyte10 extraout_ST1_31;
  unkbyte10 extraout_ST1_32;
  unkbyte10 extraout_ST1_33;
  unkbyte10 extraout_ST1_34;
  unkbyte10 extraout_ST1_35;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  unkbyte10 in_ST4;
  unkbyte10 in_ST5;
  int local_d4 [2];
  float local_cc [2];
  float local_c4 [2];
  int local_bc;
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
  
  ffree(in_ST1);
  ffree(in_ST0);
  Var2 = thunk_FUN_0054c590(&P1,&DAT_01a1ad80,&DAT_00769df0);
  if (P18 != f_0) {
    P16 = f_1;
  }
  DAT_009a7a08 = P5;
  if (P5 == f_0) {
    DAT_009a7a08 = f_1;
  }
  DAT_009a7a04 = DAT_009a7a08 * f_1_1;
  DAT_009a79c0 = STEP * f_7;
  DAT_009a7a00 = Y_POS;
  DAT_009a79fc = P4;
  IP1 = 9;
  DAT_009a79f8 = IP8;
  DAT_009a79f4 = P8;
  DAT_009a79f0 = IP10;
  DAT_009a79ec = P9;
  DAT_009a79e8 = IP7;
  if (IP7 == 0) {
    DAT_009a7a00 = DAT_009a79c0 + Y_POS;
    DAT_009a79e4 = 0x25;
    if (IP6 == 0) {
      local_94 = 0;
    }
    else {
      DAT_009a79e0 = -1;
      if (P9 == f_0) {
        DAT_009a79ec = f_1;
      }
      P8 = DAT_009a7a08 * DAT_009a79ec;
      P9 = f_0;
      DAT_009a79dc = f_22_85;
    }
    IP10 = -1;
    if (IP28 != 0) {
      IP10 = IP28;
    }
    ffree(extraout_ST1);
    ffree(Var2);
    Var2 = draw_clef(&X_POS,&DAT_009a7a00,&DAT_009a79e4,&DAT_009a7a04,&DAT_009a7a04);
    DAT_009a79fc = (DAT_009a79fc + f_2_2 + P11) - DAT_009a79ec;
    if ((DAT_009a79f8 == 0) || (5 < DAT_009a79f8)) {
      local_90 = 0;
      Var4 = extraout_ST1_31;
    }
    else {
      DAT_009a7a04 = DAT_009a7a08 * f_0_65;
      DAT_009a79d8 = DAT_009a7a08 * f_23 * STEP;
      if (DAT_009a79f8 == 4) {
        DAT_009a79d8 = DAT_009a79d8 * f_1_3;
      }
      if (DAT_009a79f8 == 5) {
        DAT_009a79d8 = DAT_009a79d8 * f_1_11;
      }
      DAT_009a79b8 = f_3;
      if ((DAT_009a79f8 == 2) || (DAT_009a79f8 == 3)) {
        DAT_009a79b8 = f_3_6;
      }
      DAT_009a79b8 = DAT_009a79c0 * DAT_009a7a08 * DAT_009a79b8;
      local_d4[0] = DAT_009a79f8 + 5;
      local_c4[0] = (float)((float10)DAT_009a79d8 + (float10)X_POS);
      local_cc[0] = (float)((float10)DAT_009a79b8 + (float10)DAT_009a7a00);
      ffree((float10)DAT_009a79b8 + (float10)DAT_009a7a00);
      ffree((float10)DAT_009a79d8 + (float10)X_POS);
      Var2 = draw_clef(local_c4,local_cc,local_d4,&DAT_009a7a04,&DAT_009a7a04);
      local_8c = 0;
      Var4 = extraout_ST1_32;
    }
LAB_00560474:
    if (IP6 == 0) {
      local_10 = 0;
    }
    else {
      if (DAT_009a79e0 != 0) {
        DAT_009a79fc = DAT_009a79fc + f_0_4;
      }
      P5 = DAT_009a79fc;
      ffree(Var4);
      ffree(Var2);
      fVar3 = (float10)staff_level_y(&P5);
      Y_POS = (float)fVar3;
      if (DAT_009a79e0 == 0) {
        if (DAT_009a79f4 != f_0) {
          X_POS = DAT_009a79f4 * f_150;
        }
        local_8 = 0;
      }
      else {
        local_c = 0;
        X_POS = DAT_009a7a08 * DAT_009a79dc * STEP + X_POS;
      }
      IP7 = DAT_009a79e0;
      IP9 = 0;
      IP10 = DAT_009a79f0;
      ffree(in_ST2);
      ffree(extraout_ST1_33);
      Var2 = draw_line();
      P5 = DAT_009a7a08;
      P8 = DAT_009a79f4;
      P9 = DAT_009a79ec;
      Var4 = extraout_ST1_34;
    }
  }
  else {
    local_98 = 0;
    if (IP7 == 1) {
      DAT_009a79e4 = IP8;
      DAT_009a79e0 = IP9;
      DAT_009a79dc = P15 + P3;
      DAT_009a7a00 = P4;
      DAT_009a7a04 = (STEP * DAT_009a7a08) / f_25;
      IP10 = 1;
      IP7 = 0;
      IP5 = 0;
      IP8 = 0;
      P8 = f_0;
      IP9 = 0;
      DAT_009a79c0 = DAT_009a7a08 * f_4;
      DAT_009a79b8 = Y_POS;
      local_c4[0] = P4 - DAT_009a79c0;
      ffree(extraout_ST1);
      ffree(Var2);
      P6 = DAT_009a79dc;
      fVar3 = (float10)staff_level_y(local_c4);
      Y_POS = (float)fVar3;
      P5 = DAT_009a79c0 + DAT_009a7a00;
      P17 = f_0;
      P18 = f_0;
      ffree(in_ST2);
      ffree(extraout_ST1_26);
      Var2 = draw_line();
      Y_POS = DAT_009a79b8;
      P5 = DAT_009a7a00;
      X_POS = (DAT_009a79dc - DAT_009a7a04 * f_9_5) * f_150;
      P6 = DAT_009a7a04 * f_12 + DAT_009a79dc;
      P3 = DAT_009a79dc;
      ffree(extraout_ST1_27);
      ffree(Var2);
      Var2 = draw_line();
      P6 = DAT_009a7a08;
      P7 = DAT_009a7a08 * f_3;
      X_POS = (DAT_009a79dc - DAT_009a7a04 * f_7_5) * f_150;
      DAT_009a79ec = DAT_009a7a04 * f_375;
      P13 = f_1;
      DAT_009a79e8 = 1;
      DAT_009a79d4 = 1.4013e-43;
      local_c4[0] = DAT_009a7a08 * f_2_5 + DAT_009a7a00;
      ffree(extraout_ST1_28);
      ffree(Var2);
      fVar3 = (float10)staff_level_y(local_c4);
      DAT_009a7a08 = (float)(fVar3 - (float10)Y_POS);
      DAT_009a7a00 = Y_POS - DAT_009a7a08 * f_2;
      Var2 = extraout_ST1_29;
      while( true ) {
        local_bc = DAT_009a79e4 / (int)DAT_009a79d4;
        while( true ) {
          DAT_009a79c0 = (float)local_bc;
          Y_POS = DAT_009a7a08 * DAT_009a79c0 + DAT_009a7a00;
          ffree(in_ST3);
          ffree(Var2);
          Var2 = draw_box();
          in_ST3 = extraout_ST1_30;
          if (DAT_009a79d4 == 1.4013e-45) break;
          DAT_009a79b8 = (float)((int)DAT_009a79d4 / 10);
          local_bc = (DAT_009a79e4 % (int)DAT_009a79d4) / (int)DAT_009a79b8;
          X_POS = DAT_009a79ec + X_POS;
          DAT_009a79d4 = DAT_009a79b8;
        }
        local_84 = 0;
        if (DAT_009a79e8 == 0) break;
        DAT_009a79e8 = DAT_009a79e8 + -1;
        X_POS = (DAT_009a7a04 * f_2_5 + DAT_009a79dc) * f_150;
        DAT_009a79d4 = 1.4013e-42;
        DAT_009a79e4 = DAT_009a79e0;
      }
      local_80 = 0;
      Var4 = extraout_ST1_30;
    }
    else {
      local_88 = 0;
      if ((IP7 < 0x15) || (0x16 < IP7)) {
        local_7c = 0;
        if ((IP7 < 0x1a) && (0x16 < IP7)) {
          if (IP7 == 0x18) {
            ffree(extraout_ST1);
            ffree(Var2);
            Var4 = draw_symbol(&X_POS,&DAT_009a7a00,&DAT_00769dc0,&P9,&f_0,&DAT_00769dc8,&f_0,
                               &DAT_00769dc8);
            Var2 = extraout_ST1_15;
          }
          else if (IP7 + -0x18 < 1) {
            ffree(extraout_ST1);
            ffree(Var2);
            Var4 = draw_symbol(&X_POS,&DAT_009a7a00,&DAT_00769dc4,&P9,&f_0,&DAT_00769dc8,&f_0,
                               &DAT_00769dc8);
            Var2 = extraout_ST1_14;
          }
          else {
            ffree(extraout_ST1);
            ffree(Var2);
            Var4 = draw_symbol(&X_POS,&DAT_009a7a00,&DAT_00769dbc,&P9,&f_0,&DAT_00769dc8,&f_0,
                               &DAT_00769dc8);
            Var2 = extraout_ST1_16;
          }
          goto LAB_00560599;
        }
        local_54 = 0;
        DAT_009a79e0 = 1;
        DAT_009a79dc = f_43;
        if (P8 == f_0) {
          P8 = (STEP * DAT_009a7a08) / f_25;
          P9 = P8 * f_1_5;
        }
        else {
          local_44 = 0;
        }
        ffree(extraout_ST1);
        ffree(Var2);
        Var4 = thunk_FUN_0054c590(&P4,&DAT_01c58640,&DAT_00769dac);
        Var2 = extraout_ST1_17;
        if (DAT_009a79e8 == 8) {
          DAT_009a79e4 = 0x2d;
          local_3c = 0;
LAB_0055fdaa:
          if (OUTPUT_MODE == -2) {
            DAT_009a7a04 = DAT_009a7a08 * f_0_25;
            local_14 = 0;
          }
          else {
            local_18 = 0;
            DAT_009a7a04 = DAT_009a7a04 * f_0_75;
          }
        }
        else {
          local_40 = 0;
          if (DAT_009a79e8 == -8) {
            DAT_009a79e4 = 0x2e;
            local_34 = 0;
            goto LAB_0055fdaa;
          }
          local_38 = 0;
          if (DAT_009a79e8 == 0xf) {
            DAT_009a79e4 = 0x2f;
            DAT_009a79dc = f_62;
            local_2c = 0;
            goto LAB_0055fdaa;
          }
          local_30 = 0;
          if (((DAT_009a79e8 == 0x9b) || (DAT_009a79e8 == -0x58)) || (DAT_009a79e8 == 0x58)) {
            IP7 = 1;
            P6 = DAT_009a7a04 * f_0_75;
            IP8 = 0;
            P8 = f_0;
            IP10 = 0;
            DAT_009a79d0 = X_POS;
            DAT_009a79cc = P5;
            P9 = f_0;
            DAT_009a79c8 = DAT_020b945c;
            iVar1 = DAT_009a79e8;
            if (DAT_009a79e8 < 0) {
              iVar1 = -DAT_009a79e8;
            }
            if (iVar1 == 0x58) {
              P5 = f_8;
              ffree(extraout_ST1_17);
              ffree(Var4);
              Var4 = draw_number(&DAT_00769d90);
              DAT_009a79dc = f_18;
              Var2 = extraout_ST1_21;
            }
            else {
              P5 = f_15;
              ffree(extraout_ST1_17);
              ffree(Var4);
              Var4 = draw_number(&DAT_00769d84);
              DAT_009a79dc = f_29;
              Var2 = extraout_ST1_22;
            }
            DAT_020b945c = DAT_009a79c8;
            P5 = DAT_009a79cc;
            X_POS = DAT_009a79d0;
            if (DAT_009a79e8 != -0x58) {
              DAT_009a79fc = DAT_009a7a04 * f_1_5 + DAT_009a79fc;
            }
            ffree(Var2);
            ffree(Var4);
            Var2 = thunk_FUN_0054c590(&DAT_01c58640,&P4,&DAT_00769dac);
            local_24 = 0;
            Var4 = extraout_ST1_23;
            goto LAB_00560474;
          }
          local_28 = 0;
          DAT_009a79d4 = (float)IP5;
          DAT_009a79e4 = 0x30;
          DAT_009a79dc = f_51;
          DAT_009a7a04 = DAT_009a79ec * f_0_4;
          if (DAT_009a7a04 == f_0) {
            DAT_009a7a04 = f_0_4;
          }
          DAT_009a79e0 = 0;
          if (IP5 == 0) {
            local_20 = 0;
          }
          else {
            if (IP5 / 100 != 0) {
              ffree(extraout_ST1_17);
              ffree(Var4);
              Var4 = draw_symbol(&X_POS,&DAT_009a7a00,&DAT_00769da0,&DAT_009a7a04,&DAT_009a7a04,
                                 &DAT_00769dc8,&f_0,&DAT_00769dc8);
              Var2 = extraout_ST1_18;
            }
            DAT_009a79d8 = DAT_009a7a04 * f_53 * STEP;
            if (((int)DAT_009a79d4 % 100) / 10 != 0) {
              local_c4[0] = DAT_009a79d8 + X_POS;
              ffree(Var2);
              ffree(Var4);
              Var4 = draw_symbol(local_c4,&DAT_009a7a00,&DAT_00769da0,&DAT_009a7a04,&DAT_009a7a04,
                                 &DAT_00769dc8,&f_0,&DAT_00769dc8);
              Var2 = extraout_ST1_19;
            }
            if ((int)DAT_009a79d4 % 10 != 0) {
              local_c4[0] = DAT_009a79d8 + X_POS + DAT_009a79d8;
              ffree(Var2);
              ffree(Var4);
              Var4 = draw_symbol(local_c4,&DAT_009a7a00,&DAT_00769da0,&DAT_009a7a04,&DAT_009a7a04,
                                 &DAT_00769dc8,&f_0,&DAT_00769dc8);
              Var2 = extraout_ST1_20;
            }
            local_1c = 0;
          }
        }
        P5 = f_0;
        P6 = DAT_009a7a04;
        P7 = DAT_009a7a04;
        IP10 = 0;
        IP11 = 0;
        IP12 = 0;
        IP8 = 0;
        P8 = f_0;
        P9 = f_0;
        DAT_009a79b8 = DAT_020b9470;
        DAT_009a79d8 = X_POS;
        DAT_009a79c0 = DAT_020b9468;
        ffree(Var2);
        ffree(Var4);
        Var2 = draw_symbol(&DAT_009a79d8,&DAT_009a7a00,&DAT_009a79e4,&DAT_009a7a04,&DAT_009a7a04,
                           &DAT_00769dc8,&f_0,&DAT_00769dc8);
        ffree(extraout_ST1_24);
        ffree(Var2);
        Var2 = thunk_FUN_0054c590(&DAT_01c58640,&P4,&DAT_00769dac);
        DAT_020b9468 = DAT_009a79c0;
        DAT_020b9470 = DAT_009a79b8;
        X_POS = DAT_009a79d8;
        Var4 = extraout_ST1_25;
        goto LAB_00560474;
      }
      DAT_009a79c0 = P9;
      if (P9 == f_0) {
        DAT_009a79c0 = f_2;
      }
      DAT_009a7a04 = STEP * f_6;
      DAT_009a79dc = X_POS;
      DAT_009a79d8 = Y_POS;
      DAT_009a79e0 = 1;
      if (P11 == f_0) {
        local_78 = 0;
        Var4 = extraout_ST1;
      }
      else if (f_100 <= P11) {
        ffree(extraout_ST1);
        ffree(Var2);
        Var2 = thunk_FUN_0043c11a(&DAT_009a79dc,&DAT_009a79d8,&P11,&DAT_00769dd0);
        local_70 = 0;
        Var4 = extraout_ST1_02;
      }
      else {
        local_74 = 0;
        local_c4[0] = P4 + P11;
        ffree(extraout_ST1);
        ffree(Var2);
        fVar3 = (float10)staff_level_y(local_c4);
        DAT_009a79b8 = (float)fVar3;
        ffree(in_ST2);
        ffree(extraout_ST1_00);
        Var2 = add_point(&DAT_009a79dc,&DAT_009a79b8,&DAT_00769dd0);
        DAT_009a79e0 = 0;
        Var4 = extraout_ST1_01;
        in_ST2 = in_ST3;
        in_ST3 = in_ST4;
        in_ST4 = in_ST5;
      }
      ffree(Var4);
      ffree(Var2);
      Var2 = add_point(&DAT_009a79dc,&DAT_009a79d8,&DAT_009a79e0);
      if (DAT_009a79f4 == f_0) {
        local_6c = 0;
        Var4 = extraout_ST1_03;
      }
      else {
        DAT_009a79dc = DAT_009a79f4 * f_150;
        ffree(extraout_ST1_03);
        ffree(Var2);
        Var2 = add_point(&DAT_009a79dc,&DAT_009a79d8,&DAT_00769dc8);
        Var4 = extraout_ST1_04;
      }
      DAT_009a79dc = DAT_009a7a04 + DAT_009a79dc;
      local_c4[0] = DAT_009a79c0 + DAT_009a79fc;
      ffree(Var4);
      ffree(Var2);
      fVar3 = (float10)staff_level_y(local_c4);
      DAT_009a79b8 = (float)fVar3;
      ffree(in_ST2);
      ffree(extraout_ST1_05);
      Var2 = add_point(&DAT_009a79dc,&DAT_009a79b8,&DAT_00769dc8);
      DAT_009a79dc = DAT_009a7a04 + DAT_009a79dc;
      if (DAT_009a79e8 == 0x16) {
        local_68 = 0;
        Var4 = extraout_ST1_06;
        in_ST4 = in_ST3;
      }
      else {
        local_c4[0] = DAT_009a79fc - DAT_009a79c0 / f_2;
        ffree(extraout_ST1_06);
        ffree(Var2);
        fVar3 = (float10)staff_level_y(local_c4);
        DAT_009a7a00 = (float)fVar3;
        ffree(in_ST3);
        ffree(extraout_ST1_07);
        Var2 = add_point(&DAT_009a79dc,&DAT_009a7a00,&DAT_00769dc8);
        DAT_009a79dc = DAT_009a7a04 + DAT_009a79dc;
        Var4 = extraout_ST1_08;
      }
      ffree(Var4);
      ffree(Var2);
      Var2 = add_point(&DAT_009a79dc,&DAT_009a79d8,&DAT_00769dc8);
      DAT_009a79dc = P6 * f_150;
      ffree(extraout_ST1_09);
      ffree(Var2);
      Var2 = add_point(&DAT_009a79dc,&DAT_009a79d8,&DAT_00769dc8);
      if (P12 == f_0) {
        local_64 = 0;
        Var4 = extraout_ST1_10;
      }
      else if (f_100 <= P12) {
        ffree(extraout_ST1_10);
        ffree(Var2);
        Var2 = thunk_FUN_0043c11a(&DAT_009a79dc,&DAT_009a79d8,&P12,&DAT_00769dc8);
        local_5c = 0;
        Var4 = extraout_ST1_13;
      }
      else {
        local_60 = 0;
        local_c4[0] = P12 + DAT_009a79fc;
        ffree(extraout_ST1_10);
        ffree(Var2);
        fVar3 = (float10)staff_level_y(local_c4);
        DAT_009a79b8 = (float)fVar3;
        ffree(in_ST4);
        ffree(extraout_ST1_11);
        Var2 = add_point(&DAT_009a79dc,&DAT_009a79b8,&DAT_00769dc8);
        local_58 = 0;
        Var4 = extraout_ST1_12;
      }
    }
  }
  ffree(Var4);
  ffree(Var2);
  Var4 = thunk_FUN_0054c590(&DAT_01a1ad80,&P1,&DAT_00769df0);
  Var2 = extraout_ST1_35;
LAB_00560599:
  ffree(Var2);
  ffree(Var4);
  return;
}


