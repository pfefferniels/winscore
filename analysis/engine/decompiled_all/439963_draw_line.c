// draw_line @ 00439963 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_line(void)

{
  undefined1 *puVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var3;
  unkbyte10 Var4;
  float10 fVar5;
  float10 fVar6;
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
  float10 extraout_ST1_15;
  unkbyte10 extraout_ST1_16;
  unkbyte10 extraout_ST1_17;
  unkbyte10 extraout_ST1_18;
  unkbyte10 extraout_ST1_19;
  unkbyte10 extraout_ST1_20;
  unkbyte10 extraout_ST1_21;
  unkbyte10 extraout_ST1_22;
  float10 extraout_ST1_23;
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
  unkbyte10 extraout_ST1_36;
  unkbyte10 extraout_ST1_37;
  unkbyte10 extraout_ST1_38;
  unkbyte10 extraout_ST1_39;
  unkbyte10 extraout_ST1_40;
  unkbyte10 extraout_ST1_41;
  unkbyte10 extraout_ST1_42;
  unkbyte10 extraout_ST1_43;
  unkbyte10 extraout_ST1_44;
  unkbyte10 extraout_ST1_45;
  unkbyte10 extraout_ST1_46;
  unkbyte10 extraout_ST1_47;
  unkbyte10 extraout_ST1_48;
  float10 extraout_ST1_49;
  unkbyte10 extraout_ST1_50;
  unkbyte10 extraout_ST1_51;
  unkbyte10 extraout_ST1_52;
  unkbyte10 extraout_ST1_53;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  unkbyte10 in_ST4;
  unkbyte10 in_ST5;
  unkbyte10 Var7;
  unkbyte10 in_ST6;
  unkbyte10 Var8;
  undefined1 *puVar9;
  
  puVar9 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  if ((P5 == f_0) && (puVar1 = &stack0xfffffffc, P6 == f_0)) {
    P6 = P3 + f_20;
    IP10 = 4;
    for (iVar2 = 1; iVar2 < 0x201; iVar2 = iVar2 + 1) {
      (&DAT_020b8e9f)[iVar2] = 0;
    }
    FUN_005f33c9(&stack0xfffffffc,0x4399f7);
    puVar1 = puVar9;
    Var3 = FUN_005f34d1(puVar9,0x439a12);
    ffree(extraout_ST1);
    ffree(Var3);
    in_ST0 = thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
    in_ST1 = extraout_ST1_00;
  }
  if ((IP7 == 100) && (P22 != f_0)) {
    _DAT_007f7724 = ITEM_WORDS;
    ffree(in_ST1);
    ffree(in_ST0);
    in_ST0 = thunk_FUN_004575c8(&DAT_007f7724,&DAT_007604f0,&DAT_007604f4);
    DAT_01cf8ec0 = 0;
    in_ST1 = extraout_ST1_01;
  }
  ffree(in_ST1);
  ffree(in_ST0);
  Var4 = push_words(&DAT_007604ec,&P3);
  Var3 = extraout_ST1_02;
  if (P16 == f_1) {
    ffree(extraout_ST1_02);
    ffree(Var4);
    Var4 = thunk_FUN_0053c1f1();
    Var3 = extraout_ST1_03;
  }
  _DAT_007f7720 = P7;
  DAT_007f771c = X_POS;
  _DAT_007f7718 = 0;
  DAT_01cf8edc = Y_POS;
  if (f_100 <= P7) {
    if ((P18 != f_0) && (P18 != f_1)) {
      P6 = (P6 - P3) * P18 + P3;
    }
    if (P19 == f_0) {
      P19 = P18;
    }
    if ((P19 != f_0) && (P19 != f_1)) {
      P5 = (P5 - P4) * P19 + P4;
    }
  }
  DAT_01cf8ec8 = P6 * f_150;
  DAT_007f7714 = OUTPUT_MODE;
  if ((IP7 == -1) && (IP5 != 999)) {
    IP10 = 0;
  }
  Var7 = in_ST6;
  if (((IP7 < 100) && (IP10 != 0)) && (OUTPUT_MODE == -1)) {
    *(int *)(puVar1 + -0x160) = IP10 * 2;
    ffree(Var3);
    ffree(Var4);
    Var4 = thunk_FUN_004d4ed2(puVar1 + -0x160);
    Var3 = extraout_ST1_04;
  }
  DAT_007f7710 = NPT;
  if (IP5 < 999) {
    ffree(Var3);
    ffree(Var4);
    Var3 = in_ST2;
    fVar5 = (float10)staff_level_y(&P5);
    DAT_007f770c = (float)fVar5;
    if (IP7 == 0) {
LAB_0043b616:
      DAT_01cf8ec4 = 1;
      fVar5 = extraout_ST1_15;
      if (P11 != f_0) {
        ffree(Var3);
        ffree(extraout_ST1_15);
        fVar5 = (float10)FUN_0043c11a(&DAT_007f771c,&DAT_01cf8edc,&P11,&DAT_01cf8ec4);
        Var3 = extraout_ST1_45;
      }
      ffree(Var3);
      ffree(fVar5);
      Var3 = add_point(&DAT_007f771c,&DAT_01cf8edc,&DAT_01cf8ec4);
      _DAT_007f7708 = 0;
      ffree(extraout_ST1_46);
      ffree(Var3);
      fVar5 = (float10)add_point(&DAT_01cf8ec8,&DAT_007f770c,&DAT_007f7708);
      Var3 = extraout_ST1_47;
      if (P12 != f_0) {
        ffree(extraout_ST1_47);
        ffree(fVar5);
        fVar5 = (float10)FUN_0043c11a(&DAT_01cf8ec8,&DAT_007f770c,&P12,&DAT_007f7708);
        Var3 = extraout_ST1_48;
      }
      IP12 = 0;
      if ((IP10 != 0) && (DAT_007f7714 != -1)) {
        ffree(Var3);
        ffree(fVar5);
        Var3 = in_ST3;
        fVar5 = (float10)FUN_0043c0ea(&DAT_007f771c,&DAT_01cf8edc,&DAT_007f770c,&DAT_01cf8ec8);
        if ((float10)f_0 <= fVar5) {
          IP10 = IP10 * 100;
        }
        *(undefined4 *)(puVar1 + -0x128) = 0;
        fVar5 = extraout_ST1_49;
        goto LAB_0043b74f;
      }
      *(undefined4 *)(puVar1 + -300) = 0;
      goto LAB_0043b772;
    }
    *(undefined4 *)(puVar1 + -0x130) = 0;
    fVar5 = extraout_ST1_15;
    if (IP7 == -5) {
      *(undefined4 *)(puVar1 + -0xd0) = 0;
LAB_0043a49f:
      if (P15 != f_0) {
        DAT_007f771c = P15 * f_150 + DAT_007f771c;
      }
      if (IP7 != -5) {
        *(undefined4 *)(puVar1 + -0x6c) = 0;
        if ((DAT_007f7714 == 0) || (IP7 < -1)) {
          *(undefined4 *)(puVar1 + -100) = 0;
        }
        else {
          DAT_01cf8ed4 = STEP * f_0_9 + DAT_01cf8ed4;
          DAT_01cf8edc = DAT_01cf8edc - STEP * f_0_8;
        }
        P13 = f_m90;
        _DAT_007f76f0 = P5 - P4;
        if (IP12 < 0) {
          fVar5 = (float10)_DAT_007f76f0;
          _DAT_007f76f0 = (float)-fVar5;
          ffree(Var3);
          ffree(fVar5);
          Var3 = in_ST3;
          fVar5 = (float10)staff_level_y(&P5);
          DAT_01cf8edc = (float)((float10)STEP * (float10)f_14 + fVar5);
        }
        else {
          *(undefined4 *)(puVar1 + -0x60) = 0;
        }
        DAT_01cf8ec8 = _DAT_007f76f0 * f_7 * STEP;
        if (DAT_01cf8ec8 <= f_0) {
          P13 = -P13;
          fVar5 = (float10)DAT_01cf8ec8;
          DAT_01cf8ec8 = (float)-fVar5;
        }
        else {
          *(undefined4 *)(puVar1 + -0x5c) = 0;
        }
        DAT_01cf8ec8 = DAT_007f771c + DAT_01cf8ec8;
LAB_0043a601:
        if (DAT_01cf8ec8 <= DAT_007f771c) {
          *(undefined4 *)(puVar1 + -0x58) = 0;
          goto LAB_0043b7e4;
        }
        if ((DAT_007f7714 == 0) || (IP7 < -1)) {
          *(undefined4 *)(puVar1 + -0x54) = 0;
          DAT_01cf8ed4 = DAT_007f771c;
          DAT_007f76d8 = 1;
          DAT_007f76dc = 9;
          DAT_01cf8ec4 = 1;
          if (IP7 == -3) {
            DAT_007f76c8 = DAT_007f771c;
            if (P11 == f_0) {
              *(undefined4 *)(puVar1 + -0x28) = 0;
            }
            else {
              _DAT_007f76f0 = STEP / f_25;
              _DAT_007f76d4 = P11 * f_50 * _DAT_007f76f0;
              ffree(Var3);
              ffree(fVar5);
              fVar5 = (float10)FUN_005ff206(puVar1,0x43aa90);
              _DAT_007f76d0 = (float)fVar5;
              ffree(Var3);
              ffree(extraout_ST1_20);
              fVar5 = (float10)FUN_005ff206(puVar1,0x43aaba);
              _DAT_007f76d0 = (float)fVar5;
              ffree(Var3);
              ffree(extraout_ST1_21);
              fVar5 = (float10)FUN_005ff110(puVar1,0x43aade);
              DAT_01cf8ed4 = (float)((float10)_DAT_007f76d4 / fVar5);
              ffree(Var3);
              ffree(extraout_ST1_22);
              fVar5 = (float10)FUN_005ff12b(puVar1,0x43ab08);
              DAT_007f76fc = (float)((fVar5 * (float10)DAT_01cf8ed4 * (float10)f_7) / (float10)f_6);
              fVar5 = extraout_ST1_23;
            }
            DAT_01cf8ecc = DAT_01cf8ecc * f_72;
            DAT_01cf8ed0 = DAT_01cf8ed0 * f_84;
            do {
              _DAT_007f76f0 = DAT_01cf8edc;
              while( true ) {
                while( true ) {
                  ffree(Var3);
                  ffree(fVar5);
                  fVar5 = (float10)add_point(&DAT_007f76c8,&DAT_007f76f0,&DAT_01cf8ec4);
                  Var3 = extraout_ST1_24;
                  if (DAT_01cf8ec8 <= DAT_007f76c8) {
                    *(undefined4 *)(puVar1 + -0x24) = 0;
                    goto LAB_0043ad7d;
                  }
                  DAT_01cf8ec4 = 0;
                  DAT_007f76c8 = DAT_01cf8ecc + DAT_007f76c8;
                  if (DAT_01cf8edc != _DAT_007f76f0) break;
                  _DAT_007f76f0 = DAT_01cf8ed0 + _DAT_007f76f0;
                  *(undefined4 *)(puVar1 + -0x14) = 0;
                }
                if (P11 == f_0) break;
                _DAT_01cf8ed8 = DAT_007f76c8 - DAT_01cf8ed4;
                ffree(extraout_ST1_24);
                ffree(fVar5);
                Var3 = add_point(&DAT_007f76c8,&DAT_01cf8edc,&DAT_00760498);
                *(float *)(puVar1 + -0x160) = DAT_01cf8edc - DAT_007f76fc;
                ffree(extraout_ST1_25);
                ffree(Var3);
                add_point(&DAT_01cf8ed8,puVar1 + -0x160,&DAT_00760494);
                *(float *)(puVar1 + -0x160) =
                     (float)((float10)_DAT_01cf8ed8 - (float10)DAT_01cf8ecc);
                *(float *)(puVar1 + -0x168) =
                     (float)((float10)_DAT_007f76f0 - (float10)DAT_007f76fc);
                ffree((float10)_DAT_007f76f0 - (float10)DAT_007f76fc);
                ffree((float10)_DAT_01cf8ed8 - (float10)DAT_01cf8ecc);
                Var3 = add_point(puVar1 + -0x160,puVar1 + -0x168,&DAT_00760494);
                *(float *)(puVar1 + -0x160) = DAT_007f76c8 - DAT_01cf8ecc;
                ffree(extraout_ST1_26);
                ffree(Var3);
                Var3 = add_point(puVar1 + -0x160,&DAT_007f76f0,&DAT_00760494);
                ffree(extraout_ST1_27);
                ffree(Var3);
                Var3 = add_point(&DAT_007f76c8,&DAT_01cf8edc,&DAT_00760494);
                ffree(extraout_ST1_28);
                ffree(Var3);
                fVar5 = (float10)add_point(&DAT_007f76c8,&DAT_01cf8edc,&DAT_007604f0);
                if (DAT_01cf8ec8 <= DAT_007f76c8) {
                  *(undefined4 *)(puVar1 + -0x1c) = 0;
                  Var3 = extraout_ST1_29;
                  goto LAB_0043ad7d;
                }
                DAT_007f76c8 = DAT_01cf8ecc + DAT_007f76c8;
                *(undefined4 *)(puVar1 + -0x18) = 0;
                Var3 = extraout_ST1_29;
              }
              *(undefined4 *)(puVar1 + -0x20) = 0;
            } while( true );
          }
          *(undefined4 *)(puVar1 + -0x2c) = 0;
          while( true ) {
            _DAT_01cf8ed8 = DAT_01cf8ecc * f_160 * f_0_9125;
            iVar2 = (DAT_007f76dc - DAT_007f76d8) + 1;
            *(int *)(puVar1 + -0x10) = iVar2;
            DAT_01cf8ec0 = DAT_007f76d8;
            while (0 < iVar2) {
              DAT_007f76c8 = DAT_01cf8ecc * *(float *)(DAT_01cf8ec0 * 4 + 0x78f5b0) + DAT_01cf8ed4;
              _DAT_007f76f0 = DAT_01cf8ed0 * *(float *)(DAT_01cf8ec0 * 4 + 0x78f4b8) + DAT_01cf8edc;
              ffree(Var3);
              ffree(fVar5);
              fVar5 = (float10)add_point(&DAT_007f76c8,&DAT_007f76f0,&DAT_01cf8ec4);
              DAT_01cf8ec4 = 0;
              DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
              *(int *)(puVar1 + -0x10) = *(int *)(puVar1 + -0x10) + -1;
              Var3 = extraout_ST1_19;
              iVar2 = *(int *)(puVar1 + -0x10);
            }
            DAT_01cf8ed4 = _DAT_01cf8ed8 + DAT_01cf8ed4;
            DAT_007f76d8 = 2;
            if (DAT_01cf8ec8 <= DAT_01cf8ed4) break;
            if (DAT_01cf8ec8 <= _DAT_01cf8ed8 + DAT_01cf8ed4) {
              DAT_007f76dc = 10;
              if (IP12 != 0) {
                DAT_007f76dc = 0xe;
              }
              *(undefined4 *)(puVar1 + -4) = 0;
            }
            else {
              *(undefined4 *)(puVar1 + -8) = 0;
            }
          }
          *(undefined4 *)(puVar1 + -0xc) = 0;
LAB_0043ad7d:
          if (DAT_007f7714 != -1) {
            IP10 = IP10 * 100;
          }
          if ((IP10 != 0) && (DAT_007f7714 != -1)) {
            ffree(Var3);
            ffree(fVar5);
            fVar5 = (float10)thunk_FUN_0042a8ae(&IP10,&DAT_007f7710);
            Var3 = extraout_ST1_30;
          }
        }
        else {
          DAT_01cf8ed4 = DAT_007f771c;
          _DAT_01cf8ed8 = DAT_01cf8ecc * f_146;
          DAT_007f76c8 = 0.0;
          if (((P13 != f_0) || (DAT_007f7714 != -1)) || (P6 == P3)) {
            *(undefined4 *)(puVar1 + -0x50) = 0;
            DAT_007f76dc = 0x31;
            DAT_007f76d8 = 0xf;
            goto LAB_0043a6da;
          }
          ffree(Var3);
          ffree(fVar5);
          fVar5 = (float10)thunk_FUN_0050defa(&DAT_0078f5b4,&DAT_0078f4bc);
          DAT_007f76c8 = 1.4013e-45;
          *(undefined4 *)(puVar1 + -0x4c) = 0;
          Var3 = extraout_ST1_16;
          while (IP12 != 0) {
            *(undefined4 *)(puVar1 + -0x3c) = 0;
            DAT_01cf8ed4 = DAT_01cf8ed4 - _DAT_01cf8ed8;
            DAT_007f76d8 = 0x32;
            DAT_007f76dc = 0x3e;
            IP12 = 0;
            DAT_01cf8ec8 = f_0;
            if (DAT_007f76c8 == 0.0) {
              *(undefined4 *)(puVar1 + -0x30) = 0;
            }
            else {
              *(undefined4 *)(puVar1 + -0x34) = 0;
LAB_0043a6da:
              if (DAT_007f7714 == -1) {
                ffree(Var3);
                ffree(fVar5);
                fVar5 = (float10)thunk_FUN_004d4ed2(&DAT_007604b4);
                IP10 = 1;
                Var3 = extraout_ST1_17;
              }
              else {
                *(undefined4 *)(puVar1 + -0x48) = 0;
              }
            }
            while( true ) {
              DAT_01cf8ec4 = 2;
              iVar2 = (DAT_007f76dc - DAT_007f76d8) + 1;
              *(int *)(puVar1 + -0x44) = iVar2;
              DAT_01cf8ec0 = DAT_007f76d8;
              while (0 < iVar2) {
                fVar5 = (float10)DAT_01cf8ecc * (float10)*(float *)(DAT_01cf8ec0 * 4 + 0x78f5b0) +
                        (float10)DAT_01cf8ed4;
                fVar6 = (float10)DAT_01cf8ed0 * (float10)*(float *)(DAT_01cf8ec0 * 4 + 0x78f4b8) +
                        (float10)DAT_01cf8edc;
                *(float *)(puVar1 + -0x160) = (float)fVar5;
                *(float *)(puVar1 + -0x168) = (float)fVar6;
                ffree(fVar6);
                ffree(fVar5);
                fVar5 = (float10)add_point(puVar1 + -0x160,puVar1 + -0x168,&DAT_01cf8ec4);
                DAT_01cf8ec4 = 0;
                DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
                *(int *)(puVar1 + -0x44) = *(int *)(puVar1 + -0x44) + -1;
                Var3 = extraout_ST1_18;
                iVar2 = *(int *)(puVar1 + -0x44);
              }
              DAT_01cf8ed4 = _DAT_01cf8ed8 + DAT_01cf8ed4;
              if (DAT_01cf8ec8 <= DAT_01cf8ed4) break;
              *(undefined4 *)(puVar1 + -0x40) = 0;
            }
          }
          *(undefined4 *)(puVar1 + -0x38) = 0;
        }
        goto LAB_0043b791;
      }
      DAT_01cf8ec8 = DAT_007f771c;
      *(undefined4 *)(puVar1 + -0x68) = 0;
      goto LAB_0043b616;
    }
    DAT_01cf8ed4 = STEP * f_7;
    if (IP7 < 100) {
      *(undefined4 *)(puVar1 + -0xcc) = 0;
      if (-1 < IP7) {
        if ((P6 == f_0) || (P6 == P3)) {
          *(undefined4 *)(puVar1 + -0xa8) = 0;
          if (P8 <= f_0) {
            P8 = f_1;
          }
          DAT_01cf8ecc = DAT_01cf8ed4 * P8;
          DAT_01cf8ed0 = DAT_01cf8ed4 * P9;
          if (DAT_01cf8ed0 <= f_0) {
            DAT_01cf8ed0 = DAT_01cf8ecc;
          }
          _DAT_007f76f0 = DAT_007f770c - DAT_01cf8edc;
          DAT_01cf8ed4 = DAT_01cf8ed0 + DAT_01cf8ecc;
          DAT_007f76c8 = _DAT_007f76f0 / DAT_01cf8ed4;
          *(undefined2 *)(puVar1 + -0x15c) = in_FPUControlWord;
          *(ushort *)(puVar1 + -0x15a) = (ushort)*(undefined4 *)(puVar1 + -0x15c) | 0xc00;
          *(int *)(puVar1 + -0x158) = (int)ROUND(DAT_007f76c8);
          DAT_01cf8ec4 = *(int *)(puVar1 + -0x158);
          if (DAT_01cf8ec4 < 1) {
            *(undefined4 *)(puVar1 + -0x90) = 0;
          }
          else {
            DAT_007f76c8 = (float)DAT_01cf8ec4;
            _DAT_007f76e4 = ((DAT_007f76c8 + f_1) * DAT_01cf8ecc) / DAT_01cf8ed0;
            fVar5 = (float10)_DAT_007f76e4 * (float10)_DAT_007f76f0;
            _DAT_007f76e0 = (float)(fVar5 / ((float10)DAT_01cf8ec4 + (float10)_DAT_007f76e4));
            DAT_01cf8ecc = _DAT_007f76e0 / (DAT_007f76c8 + f_1);
            DAT_01cf8ed0 = (_DAT_007f76f0 - _DAT_007f76e0) / DAT_007f76c8;
            DAT_01cf8ed4 = DAT_01cf8edc;
            while( true ) {
              _DAT_007f7708 = 1;
              ffree(Var3);
              ffree(fVar5);
              Var3 = add_point(&DAT_007f771c,&DAT_01cf8ed4,&DAT_007f7708);
              DAT_01cf8ed4 = DAT_01cf8ecc + DAT_01cf8ed4;
              _DAT_007f7708 = 0;
              ffree(extraout_ST1_35);
              ffree(Var3);
              fVar5 = (float10)add_point(&DAT_007f771c,&DAT_01cf8ed4,&DAT_007f7708);
              DAT_01cf8ed4 = DAT_01cf8ed0 + DAT_01cf8ed4;
              Var3 = extraout_ST1_36;
              if (DAT_007f770c <= DAT_01cf8ed4) break;
              *(undefined4 *)(puVar1 + -0x8c) = 0;
            }
            if (IP10 == 0) {
              *(undefined4 *)(puVar1 + -0x88) = 0;
              goto LAB_0043b7e4;
            }
            if (DAT_007f7714 != -1) {
              ffree(extraout_ST1_36);
              ffree(fVar5);
              fVar5 = (float10)thunk_FUN_0042a8ae(&IP10,&DAT_007f7710);
              *(undefined4 *)(puVar1 + -0x80) = 0;
              Var3 = extraout_ST1_37;
              goto LAB_0043b7e4;
            }
            *(undefined4 *)(puVar1 + -0x84) = 0;
          }
        }
        else {
          ffree(Var3);
          ffree(extraout_ST1_15);
          fVar5 = (float10)FUN_00439598(&DAT_007f771c,&DAT_007f770c,&DAT_007f7710,&DAT_007f7720);
          _DAT_007f7708 = 0;
          Var3 = extraout_ST1_32;
          if (P12 != f_0) {
            *(float *)(puVar1 + -0x160) = DAT_01cf8ed4 - DAT_01cf8ed0;
            ffree(extraout_ST1_32);
            ffree(fVar5);
            fVar5 = (float10)FUN_0043c11a(puVar1 + -0x160,&DAT_01cf8edc,&P12,&DAT_007f7708);
            Var3 = extraout_ST1_33;
          }
          if ((IP10 != 0) && (DAT_007f7714 != -1)) {
            *(int *)(puVar1 + -0x160) = IP10 * 100;
            ffree(Var3);
            ffree(fVar5);
            fVar5 = (float10)thunk_FUN_0042a8ae(puVar1 + -0x160,&DAT_007f7710);
            Var3 = extraout_ST1_34;
          }
          if (P13 != f_0) {
            *(undefined4 *)(puVar1 + -0xa0) = 0;
            goto LAB_0043b791;
          }
          *(undefined4 *)(puVar1 + -0xa4) = 0;
          if (IP5 == IP4) {
            *(undefined4 *)(puVar1 + -0x9c) = 0;
          }
          else {
            fVar5 = (float10)DAT_007f770c - (float10)DAT_01cf8edc;
            _DAT_007f76f0 =
                 (float)(fVar5 / (((float10)DAT_01cf8ed4 - (float10)DAT_01cf8ed0) -
                                 (float10)DAT_007f771c));
            DAT_01cf8ec4 = (&PT_X0)[DAT_007f7710];
            DAT_01cf8ec0 = DAT_007f7710 + 1;
            iVar2 = (NPT - DAT_01cf8ec0) + 1;
            *(int *)(puVar1 + -0x98) = iVar2;
            while (0 < iVar2) {
              DAT_01cf8ed4 = (float)(&PT_X0)[DAT_01cf8ec0];
              if (-0x2f059 < (int)DAT_01cf8ed4) {
                fVar5 = (float10)(int)(&PT_Y0)[DAT_01cf8ec0];
                *(int *)(puVar1 + -0x158) = (int)DAT_01cf8ed4 - DAT_01cf8ec4;
                *(undefined2 *)(puVar1 + -0x15c) = in_FPUControlWord;
                *(ushort *)(puVar1 + -0x15a) = (ushort)*(undefined4 *)(puVar1 + -0x15c) | 0xc00;
                *(int *)(puVar1 + -0x158) =
                     (int)ROUND((float10)*(int *)(puVar1 + -0x158) * (float10)_DAT_007f76f0 + fVar5)
                ;
                in_FPUControlWord = *(undefined2 *)(puVar1 + -0x15c);
                (&PT_Y0)[DAT_01cf8ec0] = *(undefined4 *)(puVar1 + -0x158);
              }
              DAT_01cf8ec0 = DAT_01cf8ec0 + 1;
              *(int *)(puVar1 + -0x98) = *(int *)(puVar1 + -0x98) + -1;
              iVar2 = *(int *)(puVar1 + -0x98);
            }
            *(undefined4 *)(puVar1 + -0x94) = 0;
          }
        }
        goto LAB_0043b7c9;
      }
      *(undefined4 *)(puVar1 + -0xac) = 0;
      DAT_01cf8ecc = P8;
      DAT_01cf8ed0 = P9;
      if (P8 <= f_0) {
        DAT_01cf8ecc = f_1;
      }
      if (IP7 != -4) {
        *(undefined4 *)(puVar1 + -0x7c) = 0;
        if (P9 == f_0) {
          DAT_01cf8ed0 = DAT_01cf8ecc;
        }
        _DAT_007f76f0 = STEP * f_0_0825;
        DAT_01cf8ecc = _DAT_007f76f0 * DAT_01cf8ecc;
        DAT_01cf8ed0 = _DAT_007f76f0 * DAT_01cf8ed0;
        if ((P6 == f_0) || (P6 == P3)) goto LAB_0043a49f;
        *(undefined4 *)(puVar1 + -0x70) = 0;
        goto LAB_0043a601;
      }
      DAT_01cf8ecc = DAT_01cf8ecc / f_2;
      if (P9 == f_0) {
        DAT_01cf8ed0 = f_2;
      }
      DAT_01cf8ed0 = DAT_01cf8ed4 * DAT_01cf8ed0;
      _DAT_007f76f0 = DAT_007f771c;
      while( true ) {
        ffree(Var3);
        ffree(fVar5);
        fVar5 = (float10)FUN_0043c415(&DAT_007f76f0,&DAT_01cf8edc,&DAT_01cf8ecc);
        _DAT_007f76f0 = DAT_01cf8ed0 + _DAT_007f76f0;
        Var3 = extraout_ST1_31;
        if (DAT_01cf8ec8 < _DAT_007f76f0) break;
        *(undefined4 *)(puVar1 + -0x78) = 0;
      }
      *(undefined4 *)(puVar1 + -0x74) = 0;
      goto LAB_0043b791;
    }
    _DAT_007f7708 = 1;
    ffree(Var3);
    ffree(extraout_ST1_15);
    Var3 = add_point(&DAT_007f771c,&DAT_01cf8edc,&DAT_007f7708);
    DAT_01cf8ec4 = 8;
    DAT_007f76ec = P18;
    if (P18 == f_0) {
      DAT_007f76ec = f_1;
    }
    _DAT_007f76e8 = P19;
    Var4 = extraout_ST1_38;
    if (P19 == f_0) {
      _DAT_007f76e8 = DAT_007f76ec;
    }
    while (*(float *)(&P0 + DAT_01cf8ec4 * 4) != f_0) {
      DAT_007f76fc = ((*(float *)(&P0 + DAT_01cf8ec4 * 4) - P3) * DAT_007f76ec + P3) * f_150;
      *(float *)(puVar1 + -0x160) = ((&P1)[DAT_01cf8ec4] - P4) * _DAT_007f76e8 + P4;
      ffree(Var4);
      ffree(Var3);
      Var8 = Var7;
      fVar5 = (float10)staff_level_y(puVar1 + -0x160);
      _DAT_007f76f0 = (float)fVar5;
      _DAT_007f7708 = 0;
      ffree(in_ST3);
      ffree(extraout_ST1_39);
      Var3 = add_point(&DAT_007f76fc,&DAT_007f76f0,&DAT_007f7708);
      DAT_01cf8ec4 = DAT_01cf8ec4 + 2;
      Var4 = extraout_ST1_40;
      if (0x10 < DAT_01cf8ec4) goto LAB_0043b4d2;
      *(undefined4 *)(puVar1 + -0xc4) = 0;
      in_ST3 = in_ST4;
      in_ST4 = in_ST5;
      in_ST5 = in_ST6;
      in_ST6 = Var7;
      Var7 = Var8;
    }
    *(undefined4 *)(puVar1 + -200) = 0;
LAB_0043b4d2:
    _DAT_007f7708 = 0;
    ffree(Var4);
    ffree(Var3);
    fVar5 = (float10)add_point(&DAT_01cf8ec8,&DAT_007f770c,&DAT_007f7708);
    if (P21 == f_0) {
      *(undefined4 *)(puVar1 + -0xc0) = 0;
      Var3 = extraout_ST1_41;
    }
    else {
      *(undefined2 *)(puVar1 + -0x15c) = in_FPUControlWord;
      *(ushort *)(puVar1 + -0x15a) = (ushort)*(undefined4 *)(puVar1 + -0x15c) | 0xc00;
      *(int *)(puVar1 + -0x158) = (int)ROUND(P21);
      IP21 = *(int *)(puVar1 + -0x158);
      if (DAT_007f7714 == -1) {
        ffree(extraout_ST1_41);
        ffree(fVar5);
        fVar5 = (float10)thunk_FUN_004d4ed2(&IP21);
        *(undefined4 *)(puVar1 + -0xbc) = 0;
        Var3 = extraout_ST1_42;
      }
      else {
        ffree(extraout_ST1_41);
        ffree(fVar5);
        fVar5 = (float10)thunk_FUN_0042a8ae(&IP21,&DAT_007f7710);
        Var3 = extraout_ST1_43;
      }
    }
    if (P20 == f_0) {
      *(undefined4 *)(puVar1 + -0xb8) = 0;
    }
    else {
      ffree(Var3);
      ffree(fVar5);
      fVar5 = (float10)thunk_FUN_0042a5f4(&DAT_007f7710,&DAT_007f771c,&DAT_01cf8edc,&P20);
      Var3 = extraout_ST1_44;
    }
    if (P2 == f_100) {
      *(undefined4 *)(puVar1 + -0xb4) = 0;
    }
    else {
      *(undefined4 *)(puVar1 + -0xb0) = 0;
    }
  }
  else {
    *(undefined4 *)(puVar1 + -0x134) = 0;
    if (P7 == f_0) {
      P7 = f_2_3;
    }
    if (P7 == f_m1) {
      P7 = f_m2_3;
    }
    fVar5 = (float10)P7;
    DAT_007f76c8 = (float)(ABS(fVar5) * (float10)STEP * (float10)f_3_5);
    DAT_007f7704 = DAT_01c589f0;
    DAT_007f7700 = DAT_007f771c;
    DAT_007f76fc = DAT_01cf8ec8;
    if (P7 <= f_0) {
      DAT_007f76fc = DAT_007f771c;
      DAT_007f7700 = DAT_01cf8ec8;
    }
    else {
      *(undefined4 *)(puVar1 + -0x124) = 0;
    }
    while (P11 != f_1) {
      DAT_007f76f8 = 0;
      if ((P14 == f_0) && (P15 == f_0)) {
        *(undefined4 *)(puVar1 + -0x11c) = 0;
      }
      else {
        if (_DAT_0078b4b8 == f_0) {
          ffree(Var3);
          ffree(fVar5);
          fVar5 = (float10)FUN_0043b806(&DAT_007f76fc,&DAT_007f7700,&DAT_007f76c8,&DAT_007f76f4,
                                        &DAT_007f770c,&DAT_01cf8edc);
          *(undefined4 *)(puVar1 + -0x118) = 0;
          Var3 = extraout_ST1_14;
          goto LAB_0043a30f;
        }
        DAT_01cf8ed4 = f_0;
        _DAT_007f76f0 = f_0;
        if (P14 == f_0) {
          *(undefined4 *)(puVar1 + -0x114) = 0;
        }
        else {
          _DAT_007f76f0 = (DAT_007f7700 - DAT_007f76fc) * P14;
          DAT_007f76f4 = P14 * DAT_007f76c8;
        }
        if (P15 == f_0) {
          *(undefined4 *)(puVar1 + -0x110) = 0;
        }
        else {
          DAT_01cf8ed4 = (DAT_007f7700 - DAT_007f76fc) * P15;
          DAT_007f770c = P15 * DAT_007f76c8;
        }
        if (f_0 <= P7) {
          if (P14 != f_0) {
            _DAT_007f7708 = 1;
            *(float *)(puVar1 + -0x160) = (float)((float10)DAT_007f7700 - (float10)_DAT_007f76f0);
            *(float *)(puVar1 + -0x168) = (float)((float10)DAT_007f76f4 + (float10)DAT_01cf8edc);
            ffree((float10)DAT_007f76f4 + (float10)DAT_01cf8edc);
            ffree((float10)DAT_007f7700 - (float10)_DAT_007f76f0);
            Var3 = add_point(puVar1 + -0x160,puVar1 + -0x168,&DAT_007f7708);
            if (P15 == f_0) {
              *(undefined4 *)(puVar1 + -0x104) = 0;
              P47 = DAT_007f76fc;
              P49 = DAT_007f76c8;
              *(undefined4 *)(puVar1 + -0xfc) = 0;
            }
            else {
              P47 = DAT_007f7700 - DAT_01cf8ed4;
              P49 = DAT_007f770c;
            }
            P48 = DAT_007f7700 - _DAT_007f76f0;
            P50 = DAT_007f76f4;
            Var4 = extraout_ST1_06;
            goto LAB_0043a085;
          }
          *(undefined4 *)(puVar1 + -0x108) = 0;
          DAT_007f76fc = DAT_007f7700 - DAT_01cf8ed4;
          DAT_007f76c8 = DAT_007f770c;
          *(undefined4 *)(puVar1 + -0xe8) = 0;
        }
        else {
          *(undefined4 *)(puVar1 + -0x10c) = 0;
          if (P15 != f_0) {
            _DAT_007f7708 = 1;
            fVar5 = ((float10)DAT_007f76c8 + (float10)DAT_01cf8edc) - (float10)DAT_007f770c;
            *(float *)(puVar1 + -0x160) = (float)((float10)DAT_01cf8ed4 + (float10)DAT_007f76fc);
            *(float *)(puVar1 + -0x168) = (float)fVar5;
            ffree(fVar5);
            ffree((float10)DAT_01cf8ed4 + (float10)DAT_007f76fc);
            Var3 = add_point(puVar1 + -0x160,puVar1 + -0x168,&DAT_007f7708);
            if (P14 == f_0) {
              *(undefined4 *)(puVar1 + -0xf4) = 0;
              P47 = DAT_007f76fc;
              P49 = DAT_007f76c8;
              *(undefined4 *)(puVar1 + -0xec) = 0;
            }
            else {
              P47 = _DAT_007f76f0 + DAT_007f76fc;
              P49 = DAT_007f76c8 - DAT_007f76f4;
            }
            P48 = DAT_01cf8ed4 + DAT_007f76fc;
            P50 = DAT_007f76c8 - DAT_007f770c;
            *(undefined4 *)(puVar1 + -0xf0) = 0;
            Var4 = extraout_ST1_05;
LAB_0043a085:
            _DAT_007f7708 = 0;
            *(float *)(puVar1 + -0x160) = P49 + Y_POS;
            ffree(Var4);
            ffree(Var3);
            Var3 = add_point(&P47,puVar1 + -0x160,&DAT_007f7708);
            _DAT_007f7708 = 1;
            *(float *)(puVar1 + -0x160) = Y_POS - P50;
            ffree(extraout_ST1_07);
            ffree(Var3);
            Var3 = add_point(&P48,puVar1 + -0x160,&DAT_007f7708);
            _DAT_007f7708 = 0;
            *(float *)(puVar1 + -0x160) = Y_POS - P49;
            ffree(extraout_ST1_08);
            ffree(Var3);
            fVar5 = (float10)add_point(&P47,puVar1 + -0x160,&DAT_007f7708);
            *(undefined4 *)(puVar1 + -0x100) = 0;
            Var3 = extraout_ST1_09;
            goto LAB_0043a14c;
          }
          *(undefined4 *)(puVar1 + -0xf8) = 0;
          DAT_007f76fc = _DAT_007f76f0 + DAT_007f76fc;
          DAT_007f76c8 = DAT_007f76c8 - DAT_007f76f4;
        }
      }
      while( true ) {
        DAT_007f76f8 = DAT_007f76f8 + 1;
        _DAT_007f7708 = 1;
        *(float *)(puVar1 + -0x160) = DAT_007f76c8 + DAT_01cf8edc;
        ffree(Var3);
        ffree(fVar5);
        Var3 = add_point(&DAT_007f76fc,puVar1 + -0x160,&DAT_007f7708);
        _DAT_007f7708 = 0;
        ffree(extraout_ST1_10);
        ffree(Var3);
        Var3 = add_point(&DAT_007f7700,&DAT_01cf8edc,&DAT_007f7708);
        *(float *)(puVar1 + -0x160) = DAT_01cf8edc - DAT_007f76c8;
        ffree(extraout_ST1_11);
        ffree(Var3);
        fVar5 = (float10)add_point(&DAT_007f76fc,puVar1 + -0x160,&DAT_007f7708);
        Var3 = extraout_ST1_12;
LAB_0043a14c:
        if (-1 < DAT_007f7704) {
          *(undefined4 *)(puVar1 + -0xe4) = 0;
          goto LAB_0043a30f;
        }
        DAT_007f7704 = 0;
        DAT_01cf8edc = _DAT_01c589f8 * f_50 + DAT_01cf8edc;
        if (DAT_007f76f8 == 0) break;
        *(undefined4 *)(puVar1 + -0xe0) = 0;
      }
      *(undefined4 *)(puVar1 + -0xdc) = 0;
    }
    P11 = f_0;
    DAT_01cf8ed4 = STEP * f_7;
    ffree(Var3);
    ffree(fVar5);
    fVar5 = (float10)FUN_00439598(&DAT_007f771c,&DAT_007f770c,&DAT_007f7710,&DAT_007f7720);
    DAT_007f7710 = 1;
    P9 = f_0;
    IP9 = 0;
    *(undefined4 *)(puVar1 + -0x120) = 0;
    Var3 = extraout_ST1_13;
LAB_0043a30f:
    if ((IP10 == 0) || (DAT_007f7714 == -1)) {
      *(undefined4 *)(puVar1 + -0xd8) = 0;
    }
    else {
      IP10 = IP10 * 100;
LAB_0043b74f:
      ffree(Var3);
      ffree(fVar5);
      fVar5 = (float10)thunk_FUN_0042a8ae(&IP10,&DAT_007f7710);
      Var3 = extraout_ST1_50;
    }
LAB_0043b772:
    if (IP9 != 0) {
      P13 = P9;
    }
    *(undefined4 *)(puVar1 + -0xd4) = 0;
LAB_0043b791:
    if (P13 != f_0) {
      ffree(Var3);
      ffree(fVar5);
      fVar5 = (float10)thunk_FUN_0042a5f4(&DAT_007f7710,&DAT_007f771c,&DAT_01cf8edc,&P13);
      Var3 = extraout_ST1_51;
    }
  }
LAB_0043b7c9:
  if ((IP10 != 0) && (DAT_007f7714 == -1)) {
    ffree(Var3);
    ffree(fVar5);
    fVar5 = (float10)thunk_FUN_004d4f3f();
    Var3 = extraout_ST1_52;
  }
LAB_0043b7e4:
  ffree(Var3);
  ffree(fVar5);
  Var3 = pop_words(&DAT_007604ec,&P3);
  ffree(extraout_ST1_53);
  ffree(Var3);
  return;
}


