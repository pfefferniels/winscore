// draw_box_negative @ 0049eae0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_box_negative(void)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  unkbyte10 in_ST0;
  unkbyte10 Var8;
  float10 fVar9;
  float10 extraout_ST0;
  float10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  int local_b0;
  int local_ac;
  
  puVar6 = &stack0xfffffffc;
  if (P6 == f_0) {
    P6 = f_1;
  }
  DAT_00838a60 = IP7;
  ffree(in_ST0);
  Var8 = push_words(&DAT_007635dc,&P1);
  ffree(Var8);
  Var8 = push_words(&DAT_007635dc,&DAT_020b9440);
  DAT_01cadce4 = OUTPUT_MODE;
  IP14 = (int)ROUND(P14);
  if (IP5 < -3) {
    ffree(Var8);
    Var8 = FUN_004a07b1();
  }
  _DAT_020b8ea0 = i_540029023;
  _DAT_020b8ea4 = DAT_007635d8;
  DAT_020b8f38 = IP7;
  P5 = f_1;
  IP7 = 0;
  P7 = f_0;
  DAT_020b8f3c = IP8;
  IP8 = 0;
  P8 = f_0;
  DAT_00838a5c = IP9;
  P9 = f_0;
  DAT_00838a58 = IP10;
  DAT_00838a54 = IP11;
  DAT_00838a50 = IP12;
  IP10 = 0;
  P10 = f_0;
  P11 = f_0;
  _DAT_00838a4c = P14;
  ffree(Var8);
  fVar9 = (float10)amod(&P16,&f_10);
  DAT_01c58654 = (float)fVar9;
  DAT_01c58658 = P17;
  fVar9 = extraout_ST1;
  if (P17 < f_0) {
    IP5 = -2;
    fVar9 = (float10)P17;
    DAT_01c58658 = (float)-fVar9;
  }
  if (DAT_01c58654 == f_0) {
    DAT_01c58654 = f_1;
  }
  _DAT_00838a48 = (f_1 - DAT_01c58654) / f_3_5 + DAT_01c58654;
  DAT_020b8f28 = P6;
  if ((IP5 != -3) && (IP5 != -5)) {
    DAT_020b8f40 = STEP * P6 * f_0_075;
    DAT_0078cd30 = DAT_01c58658;
    if (P17 == f_0) {
      DAT_0078cd30 = f_1;
    }
    _DAT_01f93e70 = DAT_020b8f40 * DAT_0078cd30;
    DAT_0078d868 = _DAT_01f93e70 * f_160;
    DAT_020b8f20 = X_POS;
    P49 = X_POS;
    _DAT_020b8f24 = Y_POS;
    DAT_020b8f44 = IP14 / 10 + -1;
    if ((DAT_020b8f44 < 1) || (8 < DAT_020b8f44)) {
      DAT_020b8f44 = 5;
    }
    DAT_0078d85c = DAT_020b8f44 * 0xa0;
    DAT_020b8f48 = IP14 % 10;
    if (DAT_020b8f48 < 1) {
      DAT_020b8f48 = 5;
    }
    _DAT_020b8f2c = (float)(DAT_020b8f48 + -1);
    DAT_020b8f30 = DAT_020b8f48 * 0xa0;
    P47 = (float)DAT_020b8f30 * DAT_020b8f40 + Y_POS;
    ffree(fVar9);
    Var8 = push_words(&DAT_007635dc,&P1);
    DAT_00838a44 = 0;
    if (f_0 < P18) {
      ffree(Var8);
      Var8 = thunk_FUN_0054c4c6(&IP7,&DAT_01c58640,&DAT_007635c0);
      DAT_00838a40 = IP5;
      DAT_00838a3c = (int)ROUND(P18);
      DAT_00838a44 = 100000;
      fVar4 = _DAT_00838a48 * P6;
      P4 = P4 - fVar4 * f_2_6;
      P6 = fVar4 * f_0_6;
      DAT_01f93e64 = STEP * f_0_032 * fVar4;
    }
    DAT_00838a38 = 0;
    for (iVar5 = (DAT_0078d85c + 0xa0) / 0xa0; 0 < iVar5; iVar5 = iVar5 + -1) {
      DAT_01f93e78 = (float)DAT_00838a38 * _DAT_01f93e70 + DAT_020b8f20;
      if (DAT_00838a44 != 0) {
        DAT_020b8f34 = DAT_00838a3c / DAT_00838a44;
        DAT_00838a3c = DAT_00838a3c % DAT_00838a44;
        DAT_00838a44 = DAT_00838a44 / 10;
        if ((DAT_020b8f34 < 5) || (7 < DAT_020b8f34)) {
          if (DAT_020b8f34 == 8) {
            DAT_020b8f34 = 0;
          }
          if (DAT_020b8f34 == 9) {
            DAT_020b8f34 = 0x24;
          }
          _DAT_020b8ea0 = CONCAT13((char)DAT_020b8f34 + '0',_DAT_020b8ea0);
          DAT_01cb1068 = 4;
          P3 = DAT_01f93e78 / f_150 - DAT_01f93e64;
          ffree(Var8);
          Var8 = item_position();
          DAT_00838a34 = P14;
          DAT_00838a30 = P16;
          if (P26 != f_0) {
            P14 = f_m1;
            P16 = P26;
          }
          ffree(Var8);
          Var8 = draw_text();
          P14 = DAT_00838a34;
          P16 = DAT_00838a30;
        }
      }
      ffree(Var8);
      Var8 = add_segment(&DAT_01f93e78,&DAT_020b8f24,&DAT_01f93e78,&P47);
      DAT_00838a38 = DAT_00838a38 + 0xa0;
    }
    if (f_0 < P18) {
      ffree(Var8);
      Var8 = thunk_FUN_0054c4c6(&DAT_01c58640,&IP7,&DAT_007635c0);
      IP5 = DAT_00838a40;
    }
    ffree(Var8);
    fVar9 = (float10)pop_words(&DAT_007635dc,&P1);
    DAT_020b8f34 = DAT_020b8f48 + 1;
    _DAT_01cadcf8 = 0;
    fVar4 = DAT_01f93e64;
    for (iVar5 = (DAT_020b8f30 + 0xa0) / 0xa0; 0 < iVar5; iVar5 = iVar5 + -1) {
      DAT_01f93e64 = (float)_DAT_01cadcf8 * DAT_020b8f40 + _DAT_020b8f24;
      if (DAT_020b8f34 == 2) {
        DAT_0078cd34 = DAT_01f93e64;
      }
      if (DAT_020b8f34 == 3) {
        DAT_0078cd38 = DAT_01f93e64;
      }
      DAT_020b8f34 = DAT_020b8f34 + -1;
      ffree(fVar9);
      fVar9 = (float10)add_segment(&DAT_020b8f20,&DAT_01f93e64,&DAT_01f93e78,&DAT_01f93e64);
      _DAT_01cadcf8 = _DAT_01cadcf8 + 0xa0;
      fVar4 = DAT_01f93e64;
    }
    if (99 < DAT_00838a50) {
      DAT_00838a38 = DAT_00838a50 / 1000;
      if (DAT_00838a38 == 0) {
        DAT_00838a38 = 1;
      }
      DAT_00838a2c = (DAT_00838a50 % 1000) / 100;
      if (DAT_00838a2c == 0) {
        DAT_00838a2c = 6;
      }
    }
    DAT_01f93e64 = fVar4;
    if (IP5 == -1) {
      DAT_01f93e64 = DAT_020b8f40 * f_60 + fVar4;
      DAT_01f93e80 = 2;
      ffree(fVar9);
      DAT_01f93e60 = DAT_020b8f20;
      _DAT_01f93e68 = DAT_020b8f20;
      DAT_01f93e6c = fVar4;
      _DAT_01f93e70 = DAT_01f93e78;
      DAT_01f93e74 = fVar4;
      _DAT_01f93e7c = DAT_01f93e64;
      fVar9 = (float10)box_outline();
      P47 = DAT_020b8f40 * f_60 + P47;
    }
    IP9 = 0;
    fVar4 = X_POS;
    if (P13 != f_0) {
      DAT_00838a3c = (int)ROUND(P13);
      DAT_00838a44 = 100000;
      if (DAT_020b8f44 < 5) {
        ffree(fVar9);
        DAT_00838a44 = FUN_005ff9b0(10,DAT_020b8f44);
        fVar9 = extraout_ST0;
      }
      DAT_01f93e60 = f_1_3;
      if (P6 != f_0) {
        DAT_01f93e60 = P6 * f_1_3;
      }
      DAT_020b8f34 = DAT_020b8f44 + 1;
      if (6 < DAT_020b8f34) {
        DAT_020b8f34 = 6;
      }
      DAT_0078cd3c = 99;
      DAT_00838a40 = 0;
      DAT_020b8f30 = 1;
      fVar4 = X_POS;
      X_POS = DAT_020b8f20;
      for (iVar5 = DAT_020b8f34; DAT_020b8f20 = X_POS, 0 < iVar5; iVar5 = iVar5 + -1) {
        DAT_0078d85c = DAT_00838a3c / DAT_00838a44;
        if (DAT_0078d85c != 0) {
          fVar1 = f_95;
          if ((DAT_0078d85c == 8) || (fVar1 = f_10, 0 < DAT_0078d85c + -8)) {
            DAT_01f93e74 = DAT_020b8f40 * fVar1 + P47;
            DAT_00838a40 = DAT_020b8f30;
          }
          else {
            DAT_0078d860 = (DAT_020b8f48 - DAT_0078d85c) * 0xa0 + 0x50;
            _DAT_01c58a04 = (float)DAT_0078d860;
            DAT_01f93e74 = _DAT_01c58a04 * DAT_020b8f40 + _DAT_020b8f24;
            if (DAT_00838a38 == DAT_020b8f30) {
              if (DAT_0078d85c < DAT_0078cd3c) {
                DAT_0078cd3c = DAT_0078d85c;
              }
            }
            else if ((DAT_00838a2c == DAT_020b8f30) && (DAT_0078d85c < DAT_0078cd3c)) {
              DAT_0078cd3c = DAT_0078d85c;
            }
          }
          if (DAT_0078d85c == 9) {
            local_b0 = 2;
            DAT_0078d858 = 1;
            _DAT_01cadcf0 = DAT_020b8f40;
            do {
              X_POS = fVar4;
              DAT_01f93e80 = 2;
              local_ac = 5;
              DAT_0078d860 = 1;
              do {
                _DAT_01c58a04 =
                     _DAT_01cadcf0 * *(float *)(DAT_0078d860 * 4 + 0x791744) + DAT_020b8f20;
                _DAT_01f93e68 =
                     DAT_020b8f40 * *(float *)(DAT_0078d860 * 4 + 0x791730) + DAT_01f93e74;
                ffree(fVar9);
                fVar9 = (float10)add_point(&DAT_01c58a04,&DAT_01f93e68,&DAT_01f93e80);
                DAT_01f93e80 = 0;
                DAT_0078d860 = DAT_0078d860 + 1;
                local_ac = local_ac + -1;
              } while (0 < local_ac);
              DAT_01f93e80 = 2;
              fVar9 = (float10)_DAT_01cadcf0;
              _DAT_01cadcf0 = (float)-fVar9;
              DAT_0078d858 = DAT_0078d858 + 1;
              local_b0 = local_b0 + -1;
              fVar4 = X_POS;
            } while (0 < local_b0);
          }
          else {
            P6 = DAT_01f93e60;
            P13 = f_1;
            if (DAT_0078d85c == 8) {
              P6 = DAT_01f93e60 * f_0_8;
              P13 = f_0;
            }
            IP10 = 0;
            IP11 = 0x168;
            IP12 = 0x14;
            if (DAT_01cadce4 != 0) {
              IP12 = 10;
            }
            if ((DAT_01cadce4 == -1) && (P18 == f_0)) {
              IP12 = 1;
            }
            Y_POS = DAT_01f93e74;
            ffree(fVar9);
            fVar9 = (float10)draw_box();
            fVar4 = X_POS;
          }
        }
        X_POS = fVar4;
        DAT_00838a3c = DAT_00838a3c % DAT_00838a44;
        DAT_00838a44 = DAT_00838a44 / 10;
        DAT_020b8f30 = DAT_020b8f30 + 1;
        fVar4 = X_POS;
        X_POS = DAT_0078d868 + DAT_020b8f20;
      }
    }
    X_POS = fVar4;
    if ((DAT_020b8f38 != 0) || (puVar7 = &stack0xfffffffc, DAT_00838a50 != 0)) {
      P6 = DAT_020b8f28;
      DAT_01f93e74 = (STEP * DAT_020b8f28) / f_25;
      goto LAB_0049f8d7;
    }
    goto LAB_004a0350;
  }
LAB_0049f8d7:
  IP11 = 0;
  P3 = P15 + P3;
  DAT_020b8f28 = P6;
  if ((((IP5 != -3) && (IP5 != -5)) &&
      (_DAT_020b8f2c = _DAT_020b8f2c * f_1_72 * P6 + P4, DAT_01f93e64 = P3, 0 < DAT_00838a50)) &&
     (DAT_01f93e80 = DAT_00838a50 % 100, DAT_01f93e80 != 0)) {
    DAT_01cb1068 = 3;
    ffree(fVar9);
    Var8 = FUN_004a0729();
    puVar7 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
    DAT_01cb1068 = DAT_01cb1068 + 1;
    *puVar7 = 0x20;
    DAT_01cadcfc = 0x66;
    DAT_01c58a00 = 0x72;
    ffree(Var8);
    Var8 = FUN_004a06ea();
    P3 = ((float)(DAT_020b8f44 * 2) * DAT_0078cd30 + f_1_2) * DAT_01f93e74 + P3;
    fVar4 = DAT_020b8f28 * f_0_2 + _DAT_020b8f2c;
    ffree(Var8);
    P4 = fVar4;
    fVar9 = (float10)amod(&P12,&f_1);
    P4 = (float)((float10)fVar4 - fVar9 * (float10)f_17_2 * (float10)P6);
    P6 = _DAT_00838a48 * P6 * f_0_6;
    P10 = f_m0_65;
    ffree(extraout_ST1_00);
    Var8 = item_position();
    DAT_00838a34 = P14;
    DAT_00838a30 = P16;
    ffree(Var8);
    fVar9 = (float10)draw_text();
    P14 = DAT_00838a34;
    P16 = DAT_00838a30;
    P10 = f_0;
  }
  iVar5 = _DAT_020b8ea0;
  DAT_020b8ea3 = SUB41(iVar5,3);
  _DAT_020b8ea0 =
       CONCAT12((char)(((int)ROUND(P16) % 100) / 10) + '0',
                CONCAT11((char)((int)ROUND(P16) / 100) + '0',(undefined1)DAT_020b8ea0));
  DAT_01cadcfc = DAT_020b8f38;
  if (DAT_020b8f38 < 0) {
    DAT_01cadcfc = DAT_00838a60;
  }
  puVar7 = &stack0xfffffffc;
  if (DAT_01cadcfc < 10) goto LAB_004a0350;
  DAT_01c58a00 = DAT_01cadcfc / 10;
  _DAT_01cadcf8 = DAT_01c58a00 + 0x42;
  if (0x49 < _DAT_01cadcf8) goto LAB_004a05da;
  if (0x47 < _DAT_01cadcf8) {
    _DAT_01cadcf8 = DAT_01c58a00 + 0x3b;
  }
  DAT_01f93e80 = DAT_01cadcfc % 10;
  if (2 < DAT_01f93e80) {
    DAT_01f93e80 = 0;
  }
  _DAT_020b8ea0 = CONCAT13(DAT_01cadcf8,_DAT_020b8ea0);
  DAT_01cb1068 = 4;
  if (DAT_01f93e80 != 0) {
    _DAT_020b8ea4 = CONCAT11((char)DAT_01f93e80 + '0',0x3f);
    DAT_01cb1068 = 6;
  }
  if (DAT_020b8f38 < 1) {
    FUN_005f33c9(&stack0xfffffffc,0x4a0171);
    fVar9 = (float10)FUN_005f34d1(puVar6,0x4a018c);
    if (DAT_020b8ea6 == '_') {
      _DAT_020b8ea0 = CONCAT12((undefined1)DAT_020b8ea8,_DAT_020b8ea6);
      fVar9 = (float10)FUN_005f33c9(puVar6,0x4a01d8);
    }
    else {
      *(undefined4 *)(puVar6 + -0x78) = 0;
    }
    DAT_01cadcfc = 7;
    if (DAT_020b8ea4 == '?') {
      if ((DAT_020b8ea5 == '2') && (DAT_020b8ea3 == 'B' || DAT_020b8ea3 == 'E')) {
        *(undefined4 *)(puVar6 + -0x70) = 0;
      }
      else if ((DAT_020b8ea5 == '1') && (DAT_020b8ea3 == 'C' || DAT_020b8ea3 == 'F')) {
        *(undefined4 *)(puVar6 + -0x6c) = 0;
      }
      else {
        DAT_01cadcfc = 9;
      }
    }
    else {
      *(undefined4 *)(puVar6 + -0x74) = 0;
    }
    DAT_01c58a00 = DAT_01cb1068 + 1;
    iVar5 = (DAT_01cb1068 - DAT_01c58a00) + 0x15;
    *(int *)(puVar6 + -0x68) = iVar5;
    DAT_01c58a0c = DAT_01cb1068;
    iVar2 = DAT_01cadcfc;
    while (0 < iVar5) {
      DAT_01cadcfc = iVar2 + 1;
      uVar3 = (uint)DAT_01f93e80 >> 8;
      DAT_01f93e80 = CONCAT31((int3)uVar3,*(char *)((int)&DAT_020b8ea0 + iVar2));
      if (s_______09___InchesMetricParallel_P_0078da40[0] != *(char *)((int)&DAT_020b8ea0 + iVar2))
      {
        DAT_01cb1068 = DAT_01c58a00;
      }
      *(char *)((int)&DAT_020b8ea0 + iVar2) = s_______09___InchesMetricParallel_P_0078da40[0];
      (&DAT_020b8e9f)[DAT_01c58a00] = (char)DAT_01f93e80;
      DAT_01c58a00 = DAT_01c58a00 + 1;
      *(int *)(puVar6 + -0x68) = *(int *)(puVar6 + -0x68) + -1;
      iVar2 = DAT_01cadcfc;
      iVar5 = *(int *)(puVar6 + -0x68);
    }
    DAT_020b8f38 = 10;
    *(undefined4 *)(puVar6 + -100) = 0;
    puVar7 = puVar6;
    DAT_01cadcfc = iVar2;
    goto LAB_004a0350;
  }
  switch(DAT_020b8f3c) {
  case 1:
    _DAT_01cadcf8 = 0x6d;
    DAT_01cadcfc = 0x61;
    DAT_01c58a00 = 0x6a;
    goto LAB_0049fd76;
  case 2:
    _DAT_01cadcf8 = 0x6d;
    goto LAB_0049fd1b;
  case 3:
    DAT_01c58a00 = 0x30;
    break;
  case 4:
    DAT_01c58a00 = 0x39;
    break;
  case 5:
    _DAT_01cadcf8 = 0x2b;
LAB_0049fd1b:
    ffree(fVar9);
    fVar9 = (float10)FUN_004a0a2f();
    goto LAB_0049fd8d;
  case 6:
    _DAT_01cadcf8 = 100;
    DAT_01cadcfc = 0x69;
    DAT_01c58a00 = 0x6d;
    goto LAB_0049fd76;
  case 7:
    _DAT_01cadcf8 = 0x61;
    DAT_01cadcfc = 0x75;
    DAT_01c58a00 = 0x67;
LAB_0049fd76:
    ffree(fVar9);
    fVar9 = (float10)FUN_004a0a2f();
    goto LAB_0049fd7d;
  case 8:
    DAT_01c58a00 = 0x38;
    break;
  case 9:
    DAT_01c58a00 = 0x2d;
    break;
  default:
    goto LAB_0049fd8d;
  }
  DAT_01cadcfc = 0x3f;
LAB_0049fd7d:
  ffree(fVar9);
  fVar9 = (float10)FUN_004a06ea();
LAB_0049fd8d:
  if (DAT_00838a5c != 0) {
    _DAT_01cadcf8 = DAT_00838a5c / 100 + 0x30;
    DAT_00838a5c = DAT_00838a5c % 100;
    if (_DAT_01cadcf8 != 0x30) {
      if (_DAT_01cadcf8 == 0x34) {
        _DAT_01cadcf8 = 0x2b;
        DAT_01cb1068 = DAT_01cb1068 + 1;
      }
      else {
        if (_DAT_01cadcf8 == 0x35) {
          _DAT_01cadcf8 = 0x2d;
        }
        if (_DAT_01cadcf8 == 0x36) {
          _DAT_01cadcf8 = 0x38;
        }
        puVar6 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
        DAT_01cb1068 = DAT_01cb1068 + 1;
        *puVar6 = 0x3f;
        DAT_01cb1068 = DAT_01cb1068 + 1;
      }
      (&DAT_020b8e9f)[DAT_01cb1068] = DAT_01cadcf8;
    }
    DAT_01f93e80 = DAT_00838a5c % 100;
    if (DAT_01f93e80 != 0) {
      ffree(fVar9);
      fVar9 = (float10)FUN_004a0729();
    }
  }
  if (DAT_00838a58 != 0) {
    DAT_01c58a0c = 0;
    DAT_01f93e80 = DAT_00838a58 / 1000;
    if (DAT_01f93e80 == 1) {
      _DAT_01cadcf8 = 0x73;
      DAT_01c58a00 = 0x73;
      DAT_01cadcfc = 0x75;
LAB_0049ff5a:
      ffree(fVar9);
      Var8 = FUN_004a0a2f();
      ffree(Var8);
      fVar9 = (float10)FUN_004a06ea();
    }
    else {
      if (DAT_01f93e80 == 2) {
LAB_0049ff0d:
        _DAT_01cadcf8 = 0x61;
        DAT_01cadcfc = 100;
        DAT_01c58a00 = 100;
        goto LAB_0049ff5a;
      }
      if (DAT_01f93e80 == 3) {
        puVar6 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
        DAT_01cb1068 = DAT_01cb1068 + 1;
        *puVar6 = 0x28;
        DAT_01c58a0c = 1;
        goto LAB_0049ff0d;
      }
    }
    DAT_00838a58 = DAT_00838a58 % 1000;
    DAT_01f93e80 = DAT_00838a58 / 100;
    if (DAT_01f93e80 != 0) {
      DAT_01cadcfc = 0x3f;
      DAT_01c58a00 = DAT_01f93e80 + 0x30;
      ffree(fVar9);
      fVar9 = (float10)FUN_004a06ea();
    }
    DAT_01f93e80 = DAT_00838a58 % 100;
    if (DAT_01f93e80 != 0) {
      ffree(fVar9);
      fVar9 = (float10)FUN_004a0729();
    }
    if (DAT_01c58a0c != 0) {
      puVar6 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
      DAT_01cb1068 = DAT_01cb1068 + 1;
      *puVar6 = 0x29;
    }
  }
  puVar7 = &stack0xfffffffc;
  if (DAT_00838a54 != 0) {
    puVar6 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
    DAT_01cb1068 = DAT_01cb1068 + 1;
    *puVar6 = 0x2f;
    iVar5 = DAT_00838a54 / 1000;
    if (iVar5 == 0) {
      _DAT_01cadcf8 = 0;
    }
    else {
      _DAT_01cadcf8 = iVar5 + 0x42;
      if (0x47 < _DAT_01cadcf8) {
        _DAT_01cadcf8 = iVar5 + 0x3b;
      }
      puVar6 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
      DAT_01cb1068 = DAT_01cb1068 + 1;
      *puVar6 = DAT_01cadcf8;
    }
    DAT_00838a54 = DAT_00838a54 % 1000;
    DAT_01c58a00 = DAT_00838a54 / 100 + 0x30;
    if (DAT_01c58a00 != 0x30) {
      DAT_01cadcfc = 0x3f;
      ffree(fVar9);
      fVar9 = (float10)FUN_004a06ea();
    }
    DAT_01f93e80 = DAT_00838a54 % 100;
    puVar7 = &stack0xfffffffc;
    if (DAT_01f93e80 != 0) {
      ffree(fVar9);
      fVar9 = (float10)FUN_004a0729();
      puVar7 = &stack0xfffffffc;
    }
  }
LAB_004a0350:
  if (((IP5 == -5) || (DAT_00838a50 < 100)) || (IP5 == -3)) {
    *(undefined4 *)(puVar7 + -0x10) = 0;
  }
  else {
    DAT_01f93e80 = DAT_00838a2c - DAT_00838a38;
    if (DAT_01f93e80 < 1) {
      *(undefined4 *)(puVar7 + -0xc) = 0;
    }
    else {
      P6 = (float)DAT_01f93e80 * f_0_2 * DAT_020b8f28 * DAT_0078cd30;
      _DAT_01c58a04 = ((float)DAT_01f93e80 * f_0_05 + f_0_55) * DAT_020b8f28;
      P4 = DAT_020b8f28 * f_4 * STEP;
      if ((DAT_00838a38 <= DAT_00838a40) && (DAT_00838a40 <= DAT_00838a2c)) {
        P4 = P4 * f_2;
      }
      P4 = P47 + P4;
      if (1 < DAT_0078cd3c) {
        *(int *)(puVar7 + -0x11c) = DAT_0078cd3c + -2;
        fVar9 = (float10)*(int *)(puVar7 + -0x11c);
        P4 = (float)((float10)DAT_0078cd34 - ((float10)DAT_0078cd34 - (float10)DAT_0078cd38) * fVar9
                    );
      }
      *(int *)(puVar7 + -0x11c) = DAT_00838a38 + -1;
      DAT_020b8f20 = (float)*(int *)(puVar7 + -0x11c) * DAT_0078d868 + P49;
      IP1 = 9;
      ffree(fVar9);
      fVar9 = (float10)draw_symbol(&DAT_020b8f20,&P4,&DAT_0076356c,&P6,&DAT_01c58a04,&DAT_00763570,
                                   &f_0,&DAT_00763570);
    }
  }
  if (DAT_020b8f38 < 10) {
    *(undefined4 *)(puVar7 + -8) = 0;
  }
  else {
    P6 = DAT_01c58654 * DAT_020b8f28;
    if ((IP5 == -3) || (IP5 == -5)) {
      *(undefined4 *)(puVar7 + -4) = 0;
    }
    else {
      P4 = (P19 + f_5_2) * DAT_020b8f28 + _DAT_020b8f2c;
      DAT_020b8f34 = DAT_01cb1068;
      ffree(fVar9);
      P48 = P6;
      text_parse(&DAT_020b8ea0,1,&DAT_01cb1068);
      DAT_01cb1068 = DAT_020b8f34;
      fVar9 = (float10)DAT_020b8f44 * (float10)DAT_01f93e74 * (float10)DAT_0078cd30 +
              (float10)DAT_01f93e64;
      P3 = (float)(fVar9 - (float10)P13 / (float10)f_2);
      ffree(fVar9);
      fVar9 = (float10)item_position();
    }
    ffree(fVar9);
    fVar9 = (float10)draw_text();
  }
LAB_004a05da:
  ffree(fVar9);
  Var8 = pop_words(&DAT_007635dc,&DAT_020b9440);
  ffree(Var8);
  Var8 = pop_words(&DAT_007635dc,&P1);
  ffree(Var8);
  return;
}


