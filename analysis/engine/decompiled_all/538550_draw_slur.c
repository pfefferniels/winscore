// draw_slur @ 00538550 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_slur(void)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined2 in_FPUControlWord;
  undefined2 uVar5;
  unkbyte10 in_ST0;
  unkbyte10 Var6;
  float10 fVar7;
  unkbyte10 in_ST1;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  unkbyte10 extraout_ST1_01;
  unkbyte10 extraout_ST1_02;
  unkbyte10 Var8;
  float10 extraout_ST1_03;
  float10 extraout_ST1_04;
  float10 extraout_ST1_05;
  float10 extraout_ST1_06;
  float10 extraout_ST1_07;
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
  float10 extraout_ST1_24;
  unkbyte10 extraout_ST1_25;
  unkbyte10 extraout_ST1_26;
  unkbyte10 extraout_ST1_27;
  unkbyte10 extraout_ST1_28;
  unkbyte10 in_ST2;
  unkbyte10 in_ST3;
  undefined1 *puVar9;
  
  puVar9 = &stack0xfffffffc;
  puVar1 = &stack0xfffffffc;
  if (P6 == f_0) {
    P6 = P3 + f_20;
    if (P7 == f_0) {
      P7 = ram0x00768b04;
    }
    for (iVar3 = 1; iVar3 < 0x201; iVar3 = iVar3 + 1) {
      (&DAT_020b8e9f)[iVar3] = 0;
    }
    FUN_005f33c9(&stack0xfffffffc,0x5385df);
    puVar1 = puVar9;
    Var6 = FUN_005f34d1(puVar9,0x5385fa);
    ffree(extraout_ST1);
    ffree(Var6);
    in_ST0 = thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
    in_ST1 = extraout_ST1_00;
  }
  _DAT_0099aa74 = 0;
  ffree(in_ST1);
  ffree(in_ST0);
  Var6 = push_words(&DAT_00768ae0,&P3);
  iVar4 = 1;
  for (iVar3 = 1; iVar3 < 0x7d1; iVar3 = iVar3 + 1) {
    *(undefined2 *)((int)&DAT_01fbb8dc + iVar4 * 2 + 2) = 0;
    iVar4 = iVar4 + 1;
  }
  Var8 = extraout_ST1_01;
  if (P16 == f_1) {
    ffree(extraout_ST1_01);
    ffree(Var6);
    Var6 = FUN_0053c1f1();
    Var8 = extraout_ST1_02;
  }
  DAT_0099aa70 = P10;
  if (P10 == f_0) {
    DAT_0099aa70 = f_0_5;
  }
  DAT_01c58660 = X_POS;
  DAT_0099aa6c = Y_POS;
  DAT_0099aa68 = STEP * P7 * f_7;
  ffree(Var8);
  ffree(Var6);
  fVar7 = (float10)staff_level_y(&P5);
  _DAT_01c58670 = (float)(fVar7 - (float10)DAT_0099aa6c);
  DAT_01c5865c = f_0;
  DAT_01c58640 = OUTPUT_MODE;
  if (IP16 < 1000) {
    *(undefined2 *)(puVar1 + -0x1cc) = in_FPUControlWord;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(P16);
    in_FPUControlWord = *(undefined2 *)(puVar1 + -0x1cc);
    DAT_0099aa64 = *(int *)(puVar1 + -0x1c8);
  }
  DAT_0099aa60 = IP8;
  fVar7 = extraout_ST1_03;
  if ((IP8 < 1) || (9 < IP8)) {
    *(undefined4 *)(puVar1 + -0x1a4) = 0;
    if ((IP8 == 0) && (P8 != f_0)) {
      DAT_01c58658 = P8 * f_36;
      DAT_01c5865c = f_18 - DAT_01c58658;
      *(undefined4 *)(puVar1 + -0x198) = 0;
    }
    else {
      *(undefined4 *)(puVar1 + -0x19c) = 0;
      DAT_01c585c8 = IP8;
      if (IP8 < 1) {
        DAT_01c585c8 = 10 - IP8;
      }
      DAT_01c585c8 = DAT_01c585c8 + -9;
      if (10 < DAT_01c585c8) {
        DAT_01c585c8 = 1;
      }
      if (0x61 < IP8) {
        DAT_01c585c8 = IP8 + -0x57;
      }
      if ((0xc < DAT_01c585c8) || (DAT_01c585c8 < 1)) {
        DAT_01c585c8 = 1;
      }
      DAT_01c58658 = *(float *)(&DAT_007973cc + DAT_01c585c8 * 4);
      DAT_01c5865c = *(float *)(&DAT_007973fc + DAT_01c585c8 * 4);
      if (P20 == f_0) {
        *(undefined4 *)(puVar1 + -0x194) = 0;
      }
      else {
        DAT_01c58658 = P20 * DAT_01c58658;
        DAT_01c5865c = P20 * DAT_01c5865c;
      }
    }
    _DAT_0099aa58 = STEP * DAT_01c58658 + DAT_01c58660;
    if (P6 < P3) {
      P6 = P3 + ram0x00768b04;
    }
    DAT_01c5865c = STEP * DAT_01c5865c;
    if (0 < IP12) {
      P14 = f_0;
      P15 = f_0;
    }
    DAT_0099aa5c = P6 * f_150 + DAT_01c5865c;
    _DAT_0099aa54 = P14;
    DAT_01c58644 = NPT;
    DAT_0099aa50 = NPT;
    _DAT_0099aa4c = DAT_0099aa5c - _DAT_0099aa58;
    DAT_01c585e0 = IP12;
    DAT_01c585c8 = 200;
    if (IP9 == 99) {
      DAT_01c585e0 = 0;
      _DAT_0099aa54 = f_0;
      P15 = f_0;
    }
    else {
      *(undefined4 *)(puVar1 + -400) = 0;
    }
    if (f_1 <= _DAT_0099aa54) {
      _DAT_0099aa54 = f_0;
    }
    DAT_01c58660 = _DAT_0099aa58;
    DAT_01c58668 = DAT_0099aa5c;
    DAT_01c5866c = _DAT_0099aa4c;
    if ((_DAT_0099aa54 == f_0) && (P15 == f_0)) {
      *(undefined4 *)(puVar1 + -0x18c) = 0;
      if (DAT_01c585e0 < 1) {
        *(undefined4 *)(puVar1 + -0x184) = 0;
      }
      else {
        if (DAT_01c585e0 == 1) {
          DAT_01c58668 = _DAT_0099aa4c + DAT_0099aa5c;
          P15 = f_0_5;
          *(undefined4 *)(puVar1 + -0x17c) = 0;
        }
        else {
          *(undefined4 *)(puVar1 + -0x180) = 0;
          DAT_01c58660 = _DAT_0099aa58 - _DAT_0099aa4c;
          _DAT_0099aa54 = f_0_5;
          DAT_0099aa6c = DAT_0099aa6c - _DAT_01c58670;
        }
        DAT_01c5866c = _DAT_0099aa4c * f_2;
        _DAT_01c58670 = _DAT_01c58670 * f_2;
      }
    }
    else {
      if (0 < DAT_01c585e0) {
        DAT_01c585e0 = 0;
      }
      *(undefined4 *)(puVar1 + -0x188) = 0;
    }
    if (P5 != P4) {
      ffree(in_ST2);
      ffree((float10)_DAT_01c58670 * (float10)_DAT_01c58670);
      fVar7 = (float10)FUN_005ff146(puVar1,0x538b83);
      DAT_01c5866c = (float)fVar7;
      fVar7 = extraout_ST1_04;
    }
    if (IP9 == 99) {
      DAT_01c585dc = 1;
      *(undefined2 *)(puVar1 + -0x1cc) = in_FPUControlWord;
      *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
      *(int *)(puVar1 + -0x1c8) = (int)ROUND(P13);
      IP13 = *(int *)(puVar1 + -0x1c8);
      *(undefined2 *)(puVar1 + -0x1cc) = *(undefined2 *)(puVar1 + -0x1cc);
      *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
      *(int *)(puVar1 + -0x1c8) = (int)ROUND(DAT_0099aa6c);
      uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
      DAT_0099aa48 = *(int *)(puVar1 + -0x1c8);
      if (IP13 == 0) {
        *(undefined4 *)(puVar1 + -0x174) = 0;
      }
      else {
        DAT_01c585dc = 0;
        if (DAT_01c58640 != -1) {
          *(undefined4 *)(puVar1 + -0x170) = 0;
        }
      }
      while( true ) {
        *(undefined2 *)((int)&DAT_01fbb8dc + DAT_01c58644 * 2 + 2) = 1;
        *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
        *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
        *(int *)(puVar1 + -0x1c8) = (int)ROUND(DAT_01c58660);
        uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
        (&PT_X0)[DAT_01c58644] = *(undefined4 *)(puVar1 + -0x1c8);
        *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
        *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
        *(int *)(puVar1 + -0x1c8) = (int)ROUND(DAT_01c5866c + DAT_01c58660);
        uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
        (&DAT_01fd3f84)[DAT_01c58644] = *(undefined4 *)(puVar1 + -0x1c8);
        *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
        *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
        *(int *)(puVar1 + -0x1c8) = (int)ROUND(DAT_0099aa70 * DAT_01c5866c + DAT_01c58660);
        uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
        (&DAT_01fd3f80)[DAT_01c58644] = *(undefined4 *)(puVar1 + -0x1c8);
        (&PT_Y0)[DAT_01c58644] = DAT_0099aa48;
        (&DAT_02004cc4)[DAT_01c58644] = DAT_0099aa48;
        *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
        *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
        *(int *)(puVar1 + -0x1c8) = (int)ROUND((float)DAT_0099aa48 + DAT_0099aa68);
        uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
        (&DAT_02004cc0)[DAT_01c58644] = *(undefined4 *)(puVar1 + -0x1c8);
        NPT = DAT_01c58644 + 3;
        if ((DAT_01c58640 < 0) || (IP13 < 1)) break;
        IP13 = IP13 + -1;
        DAT_01c58644 = DAT_01c58644 + 3;
        DAT_0099aa48 = DAT_0099aa48 + 7;
        *(undefined4 *)(puVar1 + -0x168) = 0;
      }
      *(undefined4 *)(puVar1 + -0x16c) = 0;
LAB_0053a118:
      if (f_0 < _DAT_0099aa54) {
        if (_DAT_0099aa54 <= f_0_94) {
          fVar7 = (float10)_DAT_0099aa54 * (float10)DAT_01c5866c + (float10)DAT_01c58660;
          *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
          *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
          *(int *)(puVar1 + -0x1c8) = (int)ROUND((float10)DAT_01c58674 / (float10)f_2 + fVar7);
          uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
          DAT_01c585c4 = *(int *)(puVar1 + -0x1c8);
          *(int *)(puVar1 + -0xd0) = NPT;
          DAT_01c585c0 = 1;
          iVar3 = NPT;
          while (0 < iVar3) {
            if ((int)(&PT_X0)[DAT_01c585c0] < DAT_01c585c4) {
              *(undefined4 *)(puVar1 + -0xcc) = 0;
            }
            else {
              if ((IP11 == 0) || (*(short *)((int)&DAT_01fbb8dc + DAT_01c585c0 * 2 + 2) != 0)) {
                DAT_0099aa14 = (&PT_X0)[DAT_01c585c0];
                DAT_01c585d0 = 0;
                iVar3 = (NPT - DAT_01c585c0) + 1;
                *(int *)(puVar1 + -0xc4) = iVar3;
                DAT_0099aa10 = DAT_01c585c0;
                goto joined_r0x0053a299;
              }
              *(undefined4 *)(puVar1 + -200) = 0;
            }
            *(undefined4 *)(puVar1 + -0xb8) = 0;
            DAT_01c585c0 = DAT_01c585c0 + 1;
            *(int *)(puVar1 + -0xd0) = *(int *)(puVar1 + -0xd0) + -1;
            iVar3 = *(int *)(puVar1 + -0xd0);
          }
          goto LAB_0053a36d;
        }
        NPT = 0;
        *(undefined4 *)(puVar1 + -0xd4) = 0;
      }
      else {
        *(undefined4 *)(puVar1 + -0xd8) = 0;
      }
      goto LAB_0053a3cf;
    }
    *(undefined4 *)(puVar1 + -0x178) = 0;
    if (DAT_0099aa64 < 1) {
      *(undefined4 *)(puVar1 + -0x164) = 0;
    }
    else {
      *(undefined2 *)(puVar1 + -0x1cc) = in_FPUControlWord;
      *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
      *(int *)(puVar1 + -0x1c8) = (int)ROUND(STEP * f_27);
      in_FPUControlWord = *(undefined2 *)(puVar1 + -0x1cc);
      DAT_01c58678 = *(int *)(puVar1 + -0x1c8);
      if (9 < DAT_0099aa64) {
        DAT_01c58678 = DAT_01c58678 / 2 + DAT_01c58678;
      }
    }
    _DAT_0099aa44 = DAT_0099aa6c;
    *(undefined2 *)(puVar1 + -0x1cc) = in_FPUControlWord;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(DAT_01c5866c);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    DAT_01c58658 = *(float *)(puVar1 + -0x1c8);
    if (IP11 != 0) {
      DAT_01c585c8 = 500;
    }
    DAT_01c585e8 = ((int)DAT_01c58658 / DAT_01c585c8) * 2;
    if (DAT_01c585e8 < 8) {
      DAT_01c585e8 = 8;
    }
    DAT_01c585c4 = 2;
    iVar3 = IP7;
    if (IP7 < 0) {
      iVar3 = -IP7;
    }
    DAT_01c585e8 = iVar3 * 2 + DAT_01c585e8;
    if (IP11 == 0) {
      *(undefined4 *)(puVar1 + -0x160) = 0;
    }
    else {
      if ((_DAT_01c58670 != f_0) && (0 < DAT_0099aa64)) {
        DAT_0099aa64 = -DAT_0099aa64;
      }
      if (IP11 < -3) {
        IP11 = IP11 / 2;
      }
      if (IP11 < 0) {
        IP11 = -IP11;
      }
      if (IP11 < 2) {
        *(undefined4 *)(puVar1 + -0x15c) = 0;
        DAT_01c585e8 = DAT_01c585e8 + -2;
        if (((DAT_01c585e8 < 9) || (f_0 < P11)) || (IP11 != 1)) {
          *(undefined4 *)(puVar1 + -0x154) = 0;
        }
        else {
          iVar3 = DAT_01c585e8 / 2;
          DAT_01c585e8 = iVar3 + -2;
          if (DAT_01c585e8 % 2 != 0) {
            DAT_01c585e8 = iVar3 + -3;
          }
          if (DAT_01c585e8 < 5) {
            DAT_01c585e8 = 6;
          }
        }
      }
      else {
        DAT_01c585e8 = IP11 * 2;
        if (0 < DAT_01c585e0) {
          DAT_01c585e8 = IP11 << 2;
        }
        *(undefined4 *)(puVar1 + -0x158) = 0;
      }
    }
    *(int *)(puVar1 + -0x1c8) = DAT_01c585e8 + -1;
    DAT_01c58674 = DAT_01c5866c / (float)*(int *)(puVar1 + -0x1c8);
    _DAT_0099aa40 = DAT_01c58660;
    _DAT_0099aa3c = DAT_0099aa70 + DAT_0099aa70;
    _DAT_0099aa38 = _DAT_0099aa3c * DAT_01c58674;
    DAT_01c585c8 = DAT_01c585e8 / 2;
    DAT_01c5864c = DAT_01c585c8 + DAT_01c58644 + -1;
    DAT_01c58650 = DAT_01c585e8 + DAT_01c58644 + -1;
    if (DAT_020b8e3c < DAT_01c58650) {
      *(undefined4 *)(puVar1 + -0x150) = 0;
      goto LAB_0053b4eb;
    }
    DAT_01c58648 = DAT_01c585e8 + DAT_01c58644;
    *(undefined2 *)((int)&DAT_01fbb8dc + DAT_01c58644 * 2 + 2) = 2;
    iVar3 = (DAT_01c58650 - DAT_01c58644) + 1;
    *(int *)(puVar1 + -0x14c) = iVar3;
    DAT_01c585c0 = DAT_01c58644;
    while (0 < iVar3) {
      *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
      *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
      *(int *)(puVar1 + -0x1c8) = (int)ROUND(_DAT_0099aa40);
      uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
      (&PT_X0)[DAT_01c585c0] = *(undefined4 *)(puVar1 + -0x1c8);
      _DAT_0099aa40 = _DAT_0099aa38 + _DAT_0099aa40;
      if (DAT_01c5864c == DAT_01c585c0) {
        _DAT_0099aa38 = (f_2 - _DAT_0099aa3c) * DAT_01c58674;
      }
      DAT_01c585c0 = DAT_01c585c0 + 1;
      *(int *)(puVar1 + -0x14c) = *(int *)(puVar1 + -0x14c) + -1;
      iVar3 = *(int *)(puVar1 + -0x14c);
    }
    _DAT_0099aa3c = P9 + f_2_5;
    if (_DAT_0099aa3c < f_0_1) {
      _DAT_0099aa3c = f_0_1;
    }
    ffree(in_ST2);
    FUN_006033ff(puVar1,0x53901c);
    DAT_01c585c0 = DAT_01c585e8 / 2 + -1;
    _DAT_0099aa38 = (float)DAT_01c585c0;
    DAT_01c585d8 = 0;
    DAT_01c585d0 = DAT_01c58644 + -1;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(DAT_0099aa68 + _DAT_0099aa44);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    DAT_0099aa48 = *(int *)(puVar1 + -0x1c8);
    iVar3 = (-1 - DAT_01c585c0) / -1;
    *(int *)(puVar1 + -0x148) = iVar3;
    _DAT_0099aa34 = DAT_0099aa68;
    DAT_01c585cc = DAT_01c585c0;
    DAT_01c585d4 = DAT_01c585c0;
    DAT_01c585c8 = DAT_01c58648;
    fVar7 = extraout_ST1_05;
    while (0 < iVar3) {
      DAT_01c585d0 = DAT_01c585d0 + 1;
      _DAT_0099aa30 = (float)DAT_01c585c0;
      *(float *)(puVar1 + -0x1c8) = (float)DAT_0099aa48;
      ffree(in_ST2);
      fVar7 = (float10)FUN_006033ff(puVar1,0x53914a);
      *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
      *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
      *(int *)(puVar1 + -0x1c8) =
           (int)ROUND((float10)*(float *)(puVar1 + -0x1c8) - fVar7 * (float10)DAT_0099aa68);
      uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
      DAT_0099aa2c = *(int *)(puVar1 + -0x1c8);
      (&PT_Y0)[DAT_01c585d0] = DAT_0099aa2c;
      DAT_01c585c8 = DAT_01c585c8 + -1;
      (&PT_Y0)[DAT_01c585c8] = DAT_0099aa2c;
      *(undefined4 *)(puVar1 + -0x144) = 0;
      DAT_01c585c0 = DAT_01c585c0 + -1;
      *(int *)(puVar1 + -0x148) = *(int *)(puVar1 + -0x148) + -1;
      fVar7 = extraout_ST1_06;
      iVar3 = *(int *)(puVar1 + -0x148);
    }
    if (P13 == f_0) {
      P13 = DAT_0078b48c;
    }
    if (P13 <= f_0) {
      P13 = f_1;
    }
    if ((int)DAT_01c58658 < 3000) {
      if ((int)DAT_01c58658 < 0x259) {
        *(undefined4 *)(puVar1 + -0x138) = 0;
        _DAT_0099aa30 = f_0_6;
      }
      else {
        *(undefined4 *)(puVar1 + -0x13c) = 0;
        *(int *)(puVar1 + -0x1c8) = 3000 - (int)DAT_01c58658;
        _DAT_0099aa30 = f_1 - ((float)*(int *)(puVar1 + -0x1c8) * f_0_4) / f_2400;
      }
      P13 = P13 * _DAT_0099aa30;
    }
    else {
      *(undefined4 *)(puVar1 + -0x140) = 0;
    }
    DAT_0099aa28 = P13 * STEP * f_3_5;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(DAT_0099aa28 + f_0_5);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    DAT_01c585d4 = *(int *)(puVar1 + -0x1c8);
    DAT_01c585d8 = 0;
    if (P19 == f_0) {
      P19 = f_0_85;
    }
    _DAT_0099aa30 = DAT_0099aa28 / (P19 * _DAT_0099aa38);
    DAT_01c585c8 = 1;
    if (IP7 < 0) {
      DAT_01c585c8 = -1;
    }
    DAT_01c58654 = DAT_01c585e8 + DAT_01c58650 + -1;
    DAT_01c585c0 = DAT_01c58644 + 1;
    DAT_0099aa18 = DAT_01c585cc + DAT_01c585c0;
    iVar3 = (DAT_01c58650 - DAT_01c585c0) + 1;
    *(int *)(puVar1 + -0x134) = iVar3;
    DAT_0099aa24 = DAT_01c58650;
    DAT_0099aa20 = DAT_01c58650;
    DAT_0099aa1c = DAT_01c585c0;
    DAT_01c58658 = f_0;
    while (0 < iVar3) {
      DAT_0099aa24 = DAT_0099aa24 + 1;
      DAT_0099aa20 = DAT_0099aa20 + -1;
      (&PT_X0)[DAT_0099aa24] = (&PT_X0)[DAT_0099aa20];
      if (DAT_0099aa18 < DAT_01c585c0) {
        *(undefined4 *)(puVar1 + -0x130) = 0;
      }
      else {
        if (DAT_01c585d8 < DAT_01c585d4) {
          DAT_01c58658 = _DAT_0099aa30 + DAT_01c58658;
          *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
          *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
          *(int *)(puVar1 + -0x1c8) = (int)ROUND(DAT_01c58658);
          uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
          DAT_01c585d8 = *(int *)(puVar1 + -0x1c8);
          DAT_01c585c4 = DAT_01c585c8 * DAT_01c585d8;
        }
        else {
          *(undefined4 *)(puVar1 + -300) = 0;
        }
        DAT_01c585e4 = (&PT_Y0)[DAT_0099aa20] + DAT_01c585c4;
        (&PT_Y0)[DAT_0099aa24] = DAT_01c585e4;
        DAT_01c58654 = DAT_01c58654 + -1;
        (&PT_Y0)[DAT_01c58654] = DAT_01c585e4;
      }
      *(undefined4 *)(puVar1 + -0x128) = 0;
      DAT_01c585c0 = DAT_01c585c0 + 1;
      *(int *)(puVar1 + -0x134) = *(int *)(puVar1 + -0x134) + -1;
      iVar3 = *(int *)(puVar1 + -0x134);
    }
    (&PT_Y0)[DAT_0099aa24] = (&PT_Y0)[DAT_01c58644];
    DAT_01c58648 = DAT_0099aa24 + 1;
    if (DAT_01c585e0 < 0) {
      *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
      *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
      *(int *)(puVar1 + -0x1c8) = (int)ROUND(_DAT_0099aa34 + DAT_0099aa6c);
      uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
      DAT_0099aa48 = *(int *)(puVar1 + -0x1c8);
      DAT_01c585c0 = DAT_01c5864c + 1;
      DAT_0099aa1c = DAT_01c58650 * 2 - DAT_01c585c0;
      iVar3 = (DAT_01c58650 - DAT_01c585c0) + 1;
      *(int *)(puVar1 + -0x120) = iVar3;
      DAT_01c5864c = DAT_01c585c0;
      while (0 < iVar3) {
        DAT_0099aa18 = (DAT_0099aa48 - (&PT_Y0)[DAT_01c585c0]) * 2;
        DAT_0099aa2c = DAT_0099aa18 + (&PT_Y0)[DAT_01c585c0];
        (&PT_Y0)[DAT_01c585c0] = DAT_0099aa2c;
        if (DAT_01c58650 == DAT_01c585c0) {
          *(undefined4 *)(puVar1 + -0x11c) = 0;
        }
        else {
          DAT_0099aa2c = (&PT_Y0)[DAT_0099aa1c] + DAT_0099aa18;
          (&PT_Y0)[DAT_0099aa1c] = DAT_0099aa2c;
          DAT_0099aa1c = DAT_0099aa1c + -1;
        }
        *(undefined4 *)(puVar1 + -0x118) = 0;
        DAT_01c585c0 = DAT_01c585c0 + 1;
        *(int *)(puVar1 + -0x120) = *(int *)(puVar1 + -0x120) + -1;
        iVar3 = *(int *)(puVar1 + -0x120);
      }
    }
    else {
      *(undefined4 *)(puVar1 + -0x124) = 0;
    }
    iVar3 = DAT_01c58648;
    if (IP11 == 0) {
      *(undefined4 *)(puVar1 + -0x114) = 0;
    }
    else if (P11 <= f_0) {
      DAT_01c585d0 = 0xc1c0;
      DAT_01c585c4 = 0xc1c1;
      if (NPT < 0xc1c1) {
        iVar3 = (DAT_01c58650 - DAT_01c58644) + 1;
        *(int *)(puVar1 + -0x108) = iVar3;
        DAT_01c585c0 = DAT_01c58644;
        while (0 < iVar3) {
          DAT_01c585d0 = DAT_01c585d0 + 1;
          (&PT_X0)[DAT_01c585d0] = (&PT_X0)[DAT_01c585c0];
          (&PT_Y0)[DAT_01c585d0] = (&PT_Y0)[DAT_01c585c0];
          DAT_01c585c0 = DAT_01c585c0 + 1;
          *(int *)(puVar1 + -0x108) = *(int *)(puVar1 + -0x108) + -1;
          iVar3 = *(int *)(puVar1 + -0x108);
        }
        DAT_01c58658 = STEP;
        if (f_0 < P13) {
          DAT_01c58658 = P13 * STEP;
        }
        DAT_01c58648 = DAT_01c58644 + -1;
        *(undefined4 *)(puVar1 + -0x104) = 0xb;
        DAT_01c585c0 = 1;
        do {
          iVar3 = DAT_01c585c0;
          ffree(in_ST2);
          ffree(fVar7);
          fVar7 = (float10)anint(puVar1,0x539892);
          *(int *)(puVar1 + -0x1c8) = (int)ROUND(fVar7);
          (&DAT_01caea3c)[iVar3] = *(undefined4 *)(puVar1 + -0x1c8);
          DAT_01c585c0 = DAT_01c585c0 + 1;
          *(int *)(puVar1 + -0x104) = *(int *)(puVar1 + -0x104) + -1;
          fVar7 = extraout_ST1_07;
        } while (0 < *(int *)(puVar1 + -0x104));
        iVar3 = (DAT_01c585d0 - DAT_01c585c4) + 1;
        *(int *)(puVar1 + -0x100) = iVar3;
        DAT_01c585c0 = DAT_01c585c4;
        while (0 < iVar3) {
          (&DAT_01fbb8e0)[DAT_01c58648] = 2;
          DAT_0099aa24 = (&PT_X0)[DAT_01c585c0];
          DAT_0099aa18 = (&PT_Y0)[DAT_01c585c0];
          *(undefined4 *)(puVar1 + -0xfc) = 9;
          DAT_01c585c8 = 1;
          do {
            DAT_01c58648 = DAT_01c58648 + 1;
            (&PT_X0)[DAT_01c58648] = (&DAT_01caea3c)[DAT_01c585c8] + DAT_0099aa24;
            (&PT_Y0)[DAT_01c58648] = (&DAT_01caea44)[DAT_01c585c8] + DAT_0099aa18;
            DAT_01c585c8 = DAT_01c585c8 + 1;
            *(int *)(puVar1 + -0xfc) = *(int *)(puVar1 + -0xfc) + -1;
          } while (0 < *(int *)(puVar1 + -0xfc));
          *(undefined4 *)(puVar1 + -0xf8) = 0;
          DAT_01c585c0 = DAT_01c585c0 + 1;
          *(int *)(puVar1 + -0x100) = *(int *)(puVar1 + -0x100) + -1;
          iVar3 = *(int *)(puVar1 + -0x100);
        }
        iVar3 = DAT_01c58648 + 1;
        DAT_01c58650 = DAT_01c58648;
      }
      else {
        *(undefined4 *)(puVar1 + -0x10c) = 0;
      }
    }
    else {
      *(undefined4 *)(puVar1 + -0x110) = 0;
    }
    DAT_01c58648 = iVar3;
    if (f_0 < P11) {
      ffree(in_ST2);
      ffree(fVar7);
      Var6 = thunk_FUN_0054c4c6(&DAT_01fd3f80,&DAT_01e99980,&DAT_01c58648);
      ffree(extraout_ST1_08);
      ffree(Var6);
      fVar7 = (float10)thunk_FUN_0054c4c6(&DAT_02004cc0,&DAT_01e99fc0,&DAT_01c58648);
      if (IP12 == 2) {
        *(undefined4 *)(puVar1 + -0xf0) = 0;
        DAT_0099aa14 = 1;
        DAT_01c585c0 = 1;
        DAT_01c585c4 = DAT_01c58648 + -1;
      }
      else {
        iVar3 = DAT_01c58648 + -1;
        DAT_01fd3f88 = *(undefined4 *)(&DAT_01fd3f78 + iVar3 * 4);
        DAT_01fd3f8c = (&PT_X0)[iVar3];
        DAT_02004cc8 = *(undefined4 *)(&DAT_02004cb8 + iVar3 * 4);
        DAT_02004ccc = (&PT_Y0)[iVar3];
        DAT_01c585c0 = 3;
        DAT_01c585c4 = DAT_01c58648 + -3;
        DAT_0099aa14 = 5;
        *(undefined4 *)(puVar1 + -0xec) = 0;
      }
      while( true ) {
        (&PT_X0)[DAT_0099aa14] = (&DAT_01e9997c)[DAT_01c585c0];
        (&DAT_01fd3f80)[DAT_0099aa14] = (&DAT_01e99980)[DAT_01c585c0];
        (&DAT_01fd3f84)[DAT_0099aa14] = (&DAT_01e99978)[DAT_01c585c4];
        (&DAT_01fd3f88)[DAT_0099aa14] = (&DAT_01e9997c)[DAT_01c585c4];
        (&DAT_01fd3f8c)[DAT_0099aa14] = (&PT_X0)[DAT_0099aa14];
        (&PT_Y0)[DAT_0099aa14] = *(undefined4 *)(&DAT_01e99fbc + DAT_01c585c0 * 4);
        (&DAT_02004cc0)[DAT_0099aa14] = (&DAT_01e99fc0)[DAT_01c585c0];
        (&DAT_02004cc4)[DAT_0099aa14] = *(undefined4 *)(&DAT_01e99fb8 + DAT_01c585c4 * 4);
        (&DAT_02004cc8)[DAT_0099aa14] = *(undefined4 *)(&DAT_01e99fbc + DAT_01c585c4 * 4);
        (&DAT_02004ccc)[DAT_0099aa14] = (&PT_Y0)[DAT_0099aa14];
        *(undefined2 *)((int)&DAT_01fbb8dc + DAT_0099aa14 * 2 + 2) = 2;
        iVar4 = DAT_01c585c0 + 2;
        iVar2 = DAT_01c585c4 + -2;
        iVar3 = DAT_0099aa14 + 5;
        if (DAT_01c585c4 + -3 <= DAT_01c585c0 + 3) break;
        *(undefined4 *)(puVar1 + -0xe8) = 0;
        DAT_0099aa14 = iVar3;
        DAT_01c585c0 = iVar4;
        DAT_01c585c4 = iVar2;
      }
      in_ST2 = extraout_ST1_09;
      if (IP12 == 1) {
        DAT_01c58648 = DAT_0099aa14 + 4;
        *(undefined4 *)(puVar1 + -0xe4) = 0;
        DAT_0099aa14 = iVar3;
        DAT_01c585c0 = iVar4;
        DAT_01c585c4 = iVar2;
      }
      else {
        DAT_0099aa14 = iVar3;
        DAT_01c585c0 = iVar4;
        DAT_01c585c4 = iVar2;
        (&PT_X0)[iVar3] = (&DAT_01e9997c)[iVar4];
        (&DAT_01fd3f80)[DAT_0099aa14] = (&DAT_01e99980)[DAT_01c585c0];
        (&DAT_01fd3f84)[DAT_0099aa14] = (&DAT_01e9997c)[DAT_01c585c4];
        (&DAT_01fd3f88)[DAT_0099aa14] = (&DAT_01e9997c)[DAT_01c585c0];
        (&PT_Y0)[DAT_0099aa14] = *(undefined4 *)(&DAT_01e99fbc + DAT_01c585c0 * 4);
        (&DAT_02004cc0)[DAT_0099aa14] = (&DAT_01e99fc0)[DAT_01c585c0];
        (&DAT_02004cc4)[DAT_0099aa14] = *(undefined4 *)(&DAT_01e99fbc + DAT_01c585c4 * 4);
        (&DAT_02004cc8)[DAT_0099aa14] = *(undefined4 *)(&DAT_01e99fbc + DAT_01c585c0 * 4);
        *(undefined2 *)((int)&DAT_01fbb8dc + DAT_0099aa14 * 2 + 2) = 2;
        DAT_01c58648 = DAT_0099aa14 + 4;
      }
    }
    else {
      *(undefined4 *)(puVar1 + -0xf4) = 0;
    }
    NPT = DAT_01c58648;
    DAT_01c58644 = DAT_0099aa50;
    if (((_DAT_0078b4b8 != f_0) || (0 < IP12)) || (P15 == f_0 && P14 == f_0)) {
      *(undefined4 *)(puVar1 + -0xe0) = 0;
      goto LAB_0053a118;
    }
    ffree(in_ST2);
    ffree(fVar7);
    fVar7 = (float10)FUN_0053b514();
    *(undefined4 *)(puVar1 + -0xdc) = 0;
    in_ST2 = extraout_ST1_10;
    goto LAB_0053a647;
  }
  DAT_0099aa64 = 0;
  *(undefined4 *)(puVar1 + -0x1a0) = 0;
LAB_0053abaa:
  DAT_01c58674 = DAT_0099aa6c + DAT_0099aa68;
  DAT_0099aa28 = P6;
  if (DAT_0099aa64 == 0) {
    DAT_01c58668 = P6 * f_150;
    if ((IP9 == -1) && (DAT_0099aa60 != 2)) {
      DAT_01c585c8 = 1;
      *(undefined4 *)(puVar1 + -100) = 0;
    }
    else {
      *(undefined4 *)(puVar1 + -0x68) = 0;
      if (0 < IP13) {
        P13 = f_0;
      }
      if ((IP13 == 1) || (IP13 == 3)) {
        DAT_01c585c8 = 1;
        *(undefined4 *)(puVar1 + -0x60) = 0;
      }
      else {
        ffree(in_ST2);
        ffree(fVar7);
        fVar7 = (float10)add_point(&DAT_01c58660,&DAT_0099aa6c,&DAT_00768a84);
        DAT_01c585c8 = 0;
        in_ST2 = extraout_ST1_14;
      }
    }
    ffree(in_ST2);
    ffree(fVar7);
    fVar7 = (float10)add_point(&DAT_01c58660,&DAT_01c58674,&DAT_01c585c8);
    DAT_01c585c8 = DAT_0099aa60;
    if (0 < IP9) {
      DAT_01c585c8 = IP9;
    }
    _DAT_0099a9f8 = STEP * f_13;
    if (9 < DAT_01c585c8) {
      _DAT_0099a9f8 = _DAT_0099a9f8 * f_1_5;
    }
    if (DAT_0099aa60 == 3) {
      if (P20 == f_0) {
        P20 = f_1;
      }
      DAT_01c58668 = STEP * f_17_5 * P20 + DAT_01c58668;
      DAT_01c5866c = DAT_01c58668 - DAT_01c58660;
      _DAT_0099a9ec = DAT_0099aa70;
      in_ST2 = extraout_ST1_15;
      if (IP9 < -1) {
        _DAT_0099a9f8 = -(P9 * f_75);
      }
      goto LAB_0053afaa;
    }
    *(undefined4 *)(puVar1 + -0x5c) = 0;
    ffree(extraout_ST1_15);
    ffree(fVar7);
    fVar7 = (float10)add_point(&DAT_01c58668,&DAT_01c58674,&DAT_00768a78);
    _DAT_0099aa38 = f_5;
    in_ST2 = extraout_ST1_16;
    if ((IP13 < 2) && (DAT_0099aa60 == 1)) {
      ffree(extraout_ST1_16);
      ffree(fVar7);
      fVar7 = (float10)add_point(&DAT_01c58668,&DAT_0099aa6c,&DAT_00768a78);
      in_ST2 = extraout_ST1_17;
    }
    if (IP9 < 0) {
      *(undefined4 *)(puVar1 + -0x2c) = 0;
      goto LAB_0053b4eb;
    }
    if (DAT_0099aa60 == 1) {
      _DAT_0099aa38 = f_2;
    }
    Y_POS = DAT_01c58674 - STEP * f_28;
    if (IP12 < 0) {
      *(undefined4 *)(puVar1 + -0x28) = 0;
    }
    else {
      _DAT_0099aa40 = f_14_5;
      _DAT_0099a9e8 = STEP * f_2;
      if (DAT_01c58640 == -1) {
        _DAT_0099aa40 = f_13_5;
      }
      _DAT_0099aa40 = STEP * _DAT_0099aa40;
      _DAT_0099a9ec = P13;
      if (P12 == f_0) {
        *(undefined4 *)(puVar1 + -0x24) = 0;
      }
      else {
        _DAT_0099a9ec = P13 - (P12 - f_1) * f_1_3;
        _DAT_0099a9e8 = _DAT_0099a9e8 * P12 * f_0_8;
      }
      _DAT_0099a9e4 = (_DAT_0099a9ec * f_3750) / STEP + _DAT_0099aa40;
      if (P12 == f_0) {
        P12 = f_1;
      }
      fVar7 = (float10)STEP * (float10)_DAT_0099aa38 +
              (float10)_DAT_0099a9e4 + (float10)DAT_01c58660;
      *(float *)(puVar1 + -0x1d0) = (float)fVar7;
      *(float *)(puVar1 + -0x1d8) = (float)((float10)_DAT_0099a9e8 + (float10)Y_POS);
      ffree((float10)_DAT_0099a9e8 + (float10)Y_POS);
      ffree(fVar7);
      fVar7 = (float10)draw_clef(puVar1 + -0x1d0,puVar1 + -0x1d8,&DAT_00768a58,&P12,&P12);
      in_ST2 = extraout_ST1_18;
    }
    P6 = f_1;
    IP7 = 0;
    *(undefined4 *)(puVar1 + -0x20) = 0;
  }
  else {
    *(undefined4 *)(puVar1 + -0x6c) = 0;
LAB_0053afaa:
    _DAT_0099aa40 = _DAT_0099a9ec * DAT_01c5866c;
    _DAT_0099aa38 = (_DAT_0099aa40 + DAT_01c58660) - _DAT_0099a9f8;
    _DAT_0099aa0c = STEP * P23 * f_6;
    if (_DAT_01c58670 == f_0) {
      *(undefined4 *)(puVar1 + -0x58) = 0;
      _DAT_0099a9ec = DAT_01c58674;
      if (DAT_0099aa64 == 0) {
        if (IP11 == 0) {
          *(float *)(puVar1 + -0x1d0) = _DAT_0099aa38 - _DAT_0099aa0c;
          ffree(in_ST2);
          ffree(fVar7);
          Var6 = add_point(puVar1 + -0x1d0,&DAT_01c58674,&DAT_00768a78);
          *(float *)(puVar1 + -0x1d0) =
               _DAT_0099aa0c + _DAT_0099aa38 + _DAT_0099a9f8 + _DAT_0099a9f8;
          ffree(extraout_ST1_19);
          ffree(Var6);
          fVar7 = (float10)add_point(puVar1 + -0x1d0,&DAT_01c58674,&DAT_00768a84);
          in_ST2 = extraout_ST1_20;
        }
        else {
          *(undefined4 *)(puVar1 + -0x48) = 0;
        }
LAB_0053b1cf:
        ffree(in_ST2);
        ffree(fVar7);
        fVar7 = (float10)add_point(&DAT_01c58668,&DAT_01c58674,&DAT_00768a78);
        if (P12 == f_0) {
          *(undefined4 *)(puVar1 + -0x44) = 0;
          in_ST2 = extraout_ST1_23;
        }
        else {
          fVar7 = (float10)P12;
          _DAT_0099aa0c = (float)ABS(fVar7);
          if (P7 < f_0) {
            fVar7 = (float10)_DAT_0099aa0c;
            _DAT_0099aa0c = (float)-fVar7;
          }
          *(float *)(puVar1 + -0x1d0) = P5 + _DAT_0099aa0c + P7;
          ffree(extraout_ST1_23);
          ffree(fVar7);
          in_ST2 = in_ST3;
          fVar7 = (float10)staff_level_y(puVar1 + -0x1d0);
          DAT_0099aa6c = (float)fVar7;
          fVar7 = extraout_ST1_24;
        }
        if (IP13 < 2) {
          ffree(in_ST2);
          ffree(fVar7);
          fVar7 = (float10)add_point(&DAT_01c58668,&DAT_0099aa6c,&DAT_00768a78);
          in_ST2 = extraout_ST1_25;
        }
        if (IP9 < -1) {
          *(undefined4 *)(puVar1 + -0x40) = 0;
          goto LAB_0053b4eb;
        }
      }
      else {
        *(undefined4 *)(puVar1 + -0x4c) = 0;
      }
    }
    else {
      DAT_0099aa6c = _DAT_01c58670 + DAT_0099aa6c;
      fVar7 = (float10)DAT_0099aa68 + (float10)DAT_0099aa6c;
      _DAT_0099a9ec =
           (float)(fVar7 - ((float10)f_1 - (float10)_DAT_0099a9ec) * (float10)_DAT_01c58670);
      if (DAT_0099aa64 == 0) {
        DAT_01c58658 = _DAT_01c58670 / DAT_01c5866c;
        if (IP11 == 0) {
          *(float *)(puVar1 + -0x1d0) = _DAT_0099aa0c + _DAT_0099aa38;
          ffree(in_ST2);
          ffree(fVar7);
          fVar7 = (float10)FUN_0053c14e(puVar1 + -0x1d0,&DAT_01c58658,&DAT_01c58674,&DAT_00768a78);
          in_ST2 = extraout_ST1_21;
        }
        _DAT_0099aa38 = _DAT_0099a9f8 + _DAT_0099aa38 + _DAT_0099a9f8;
        if (IP11 == 0) {
          *(float *)(puVar1 + -0x1d0) = _DAT_0099aa38 - _DAT_0099aa0c;
          ffree(in_ST2);
          ffree(fVar7);
          fVar7 = (float10)FUN_0053c14e(puVar1 + -0x1d0,&DAT_01c58658,&DAT_01c58674,&DAT_00768a84);
          in_ST2 = extraout_ST1_22;
        }
        DAT_01c58674 = _DAT_01c58670 + DAT_01c58674;
        *(undefined4 *)(puVar1 + -0x50) = 0;
        goto LAB_0053b1cf;
      }
      *(undefined4 *)(puVar1 + -0x54) = 0;
    }
    if (IP11 == 0) {
      *(undefined4 *)(puVar1 + -0x3c) = 0;
    }
    else {
      if (IP11 == 3) {
        *(undefined4 *)(puVar1 + -0x38) = 0;
        goto LAB_0053b4eb;
      }
      P6 = -(STEP * f_14);
      if (IP11 == 2) {
        IP7 = -IP7;
      }
      if (IP7 < 0) {
        fVar7 = (float10)P6;
        P6 = (float)-fVar7;
      }
      _DAT_0099a9ec = P6 + _DAT_0099a9ec;
    }
    Y_POS = _DAT_0099a9ec - STEP * f_9;
LAB_0053b421:
    P6 = f_0_875;
    if (P21 != f_0) {
      P6 = P21;
    }
    IP7 = 1;
    Y_POS = P18 * f_7 * STEP + Y_POS;
    DAT_01c58660 = P17 * f_6 * STEP + DAT_01c58660;
    IP17 = 0;
  }
  ffree(in_ST2);
  ffree(fVar7);
  fVar7 = (float10)FUN_0053bfc6(&DAT_01c585c8,&DAT_01c58660,&DAT_0099aa40);
  P6 = DAT_0099aa28;
  in_ST2 = extraout_ST1_27;
  if (DAT_0099aa64 == 0) {
    *(undefined4 *)(puVar1 + -0x30) = 0;
    goto LAB_0053b4eb;
  }
  *(undefined4 *)(puVar1 + -0x34) = 0;
LAB_0053b4db:
  *(undefined4 *)(puVar1 + -0x14) = 0;
LAB_0053b4eb:
  ffree(in_ST2);
  ffree(fVar7);
  Var6 = pop_words(&DAT_00768ae0,&P3);
  *(undefined4 *)(puVar1 + -0x10) = 0;
  ffree(extraout_ST1_28);
  ffree(Var6);
  return;
joined_r0x0053a299:
  if (iVar3 < 1) goto LAB_0053a363;
  DAT_01c585d0 = DAT_01c585d0 + 1;
  (&PT_X0)[DAT_01c585d0] = (&PT_X0)[DAT_0099aa10];
  (&PT_Y0)[DAT_01c585d0] = (&PT_Y0)[DAT_0099aa10];
  *(undefined2 *)((int)&DAT_01fbb8dc + DAT_01c585d0 * 2 + 2) =
       *(undefined2 *)((int)&DAT_01fbb8dc + DAT_0099aa10 * 2 + 2);
  if (((IP11 == 0) && (DAT_01c585c0 < DAT_0099aa10)) && (DAT_0099aa14 == (&PT_X0)[DAT_0099aa10])) {
    *(undefined4 *)(puVar1 + -0xc0) = 0;
    goto LAB_0053a36d;
  }
  DAT_0099aa10 = DAT_0099aa10 + 1;
  *(int *)(puVar1 + -0xc4) = *(int *)(puVar1 + -0xc4) + -1;
  iVar3 = *(int *)(puVar1 + -0xc4);
  goto joined_r0x0053a299;
LAB_0053a363:
  *(undefined4 *)(puVar1 + -0xbc) = 0;
LAB_0053a36d:
  NPT = DAT_01c585d0;
  if (IP11 == 0) {
    NPT = DAT_01c585d0 + 1;
    (&PT_X0)[NPT] = DAT_01fd3f80;
    (&PT_Y0)[NPT] = DAT_02004cc0;
    DAT_01fbb8e0 = 2;
  }
  else {
    *(undefined4 *)(puVar1 + -0xb4) = 0;
  }
LAB_0053a3cf:
  if (P15 == f_0) {
    *(undefined4 *)(puVar1 + -0xb0) = 0;
  }
  else {
    fVar7 = (float10)P15 * (float10)DAT_01c5866c + (float10)DAT_01c58660;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(fVar7 - (float10)DAT_01c58674 / (float10)f_2);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    DAT_01c585c4 = *(int *)(puVar1 + -0x1c8);
    *(int *)(puVar1 + -0xac) = NPT;
    DAT_01c585c0 = 1;
    iVar3 = NPT;
    while (0 < iVar3) {
      if (((int)(&PT_X0)[DAT_01c585c0] < DAT_01c585c4) ||
         (*(short *)((int)&DAT_01fbb8dc + DAT_01c585c0 * 2 + 2) == 0 && IP11 != 0)) {
        *(undefined4 *)(puVar1 + -0xa8) = 0;
      }
      else {
        DAT_01c585d0 = DAT_01c585c0 + -1;
        if (IP11 != 0) {
          *(undefined4 *)(puVar1 + -0xa4) = 0;
          goto LAB_0053a63b;
        }
        DAT_0099aa14 = (&PT_X0)[DAT_01c585d0];
        DAT_0099aa10 = DAT_01c585c0 + 1;
        iVar3 = (NPT - DAT_0099aa10) + 1;
        *(int *)(puVar1 + -0xa0) = iVar3;
        while (0 < iVar3) {
          if (DAT_0099aa14 == (&PT_X0)[DAT_0099aa10]) {
            *(undefined4 *)(puVar1 + -0x9c) = 0;
            goto LAB_0053a5ab;
          }
          DAT_0099aa10 = DAT_0099aa10 + 1;
          *(int *)(puVar1 + -0xa0) = *(int *)(puVar1 + -0xa0) + -1;
          iVar3 = *(int *)(puVar1 + -0xa0);
        }
      }
      *(undefined4 *)(puVar1 + -0x98) = 0;
      DAT_01c585c0 = DAT_01c585c0 + 1;
      *(int *)(puVar1 + -0xac) = *(int *)(puVar1 + -0xac) + -1;
      iVar3 = *(int *)(puVar1 + -0xac);
    }
LAB_0053a5ab:
    iVar3 = (NPT - DAT_0099aa10) + 1;
    *(int *)(puVar1 + -0x94) = iVar3;
    DAT_01c585c0 = DAT_0099aa10;
    while (0 < iVar3) {
      DAT_01c585d0 = DAT_01c585d0 + 1;
      (&PT_X0)[DAT_01c585d0] = (&PT_X0)[DAT_01c585c0];
      (&PT_Y0)[DAT_01c585d0] = (&PT_Y0)[DAT_01c585c0];
      DAT_01c585c0 = DAT_01c585c0 + 1;
      *(int *)(puVar1 + -0x94) = *(int *)(puVar1 + -0x94) + -1;
      iVar3 = *(int *)(puVar1 + -0x94);
    }
LAB_0053a63b:
    NPT = DAT_01c585d0;
  }
LAB_0053a647:
  if (((IP11 == 0) && (0 < DAT_0099aa64)) && ((_DAT_0099aa54 <= f_0 && (P15 == f_0)))) {
    ffree(in_ST2);
    ffree(fVar7);
    fVar7 = (float10)FUN_0053be1d();
    in_ST2 = extraout_ST1_11;
  }
  if (P27 == f_0) {
    *(undefined4 *)(puVar1 + -0x90) = 0;
  }
  else {
    if (P29 == f_0) {
      P29 = f_0_5;
    }
    _DAT_0099aa0c = P29 * DAT_01c5866c + DAT_01c58660;
    _DAT_0099aa08 = P27 * f_7 * STEP;
    _DAT_0099aa04 = f_35;
    if (P7 < f_0) {
      _DAT_0099aa04 = -f_35;
    }
    fVar7 = (float10)DAT_02004cc0 + (float10)DAT_0099aa68;
    _DAT_0099aa00 =
         (float)((fVar7 - (float10)_DAT_0099aa08 / (float10)f_2) + (float10)_DAT_0099aa04);
    if (P28 != f_0) {
      _DAT_0099aa00 = P28 * f_7 * STEP + _DAT_0099aa00;
    }
    DAT_01c585c0 = NPT;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(_DAT_0099aa0c);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    DAT_0099a9fc = *(int *)(puVar1 + -0x1c8);
    DAT_0099aa14 = 0x18;
    *(undefined2 *)((int)&DAT_01fbb8dc + NPT * 2 + 2) = 2;
    (&PT_X0)[DAT_01c585c0] = DAT_0099a9fc - DAT_0099aa14;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(_DAT_0099aa00);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    (&PT_Y0)[DAT_01c585c0] = *(undefined4 *)(puVar1 + -0x1c8);
    (&DAT_01fd3f80)[DAT_01c585c0] = DAT_0099a9fc - DAT_0099aa14;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(_DAT_0099aa08 + _DAT_0099aa00);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    (&DAT_02004cc0)[DAT_01c585c0] = *(undefined4 *)(puVar1 + -0x1c8);
    (&DAT_01fd3f84)[DAT_01c585c0] = DAT_0099aa14 + DAT_0099a9fc;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(_DAT_0099aa08 + _DAT_0099aa00);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    (&DAT_02004cc4)[DAT_01c585c0] = *(undefined4 *)(puVar1 + -0x1c8);
    (&DAT_01fd3f88)[DAT_01c585c0] = DAT_0099aa14 + DAT_0099a9fc;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(_DAT_0099aa00);
    uVar5 = *(undefined2 *)(puVar1 + -0x1cc);
    (&DAT_02004cc8)[DAT_01c585c0] = *(undefined4 *)(puVar1 + -0x1c8);
    (&DAT_01fd3f8c)[DAT_01c585c0] = DAT_0099a9fc - DAT_0099aa14;
    *(undefined2 *)(puVar1 + -0x1cc) = uVar5;
    *(ushort *)(puVar1 + -0x1ca) = (ushort)*(undefined4 *)(puVar1 + -0x1cc) | 0xc00;
    *(int *)(puVar1 + -0x1c8) = (int)ROUND(_DAT_0099aa00);
    (&DAT_02004ccc)[DAT_01c585c0] = *(undefined4 *)(puVar1 + -0x1c8);
    NPT = DAT_01c585c0 + 5;
  }
  if (_DAT_01c58670 == f_0) {
    *(undefined4 *)(puVar1 + -0x8c) = 0;
  }
  else {
    ffree(in_ST2);
    fVar7 = (float10)FUN_005ff221(puVar1,0x53aa1e);
    _DAT_0099a9f8 = (float)fVar7;
    DAT_01c585c4 = -1;
    ffree(in_ST2);
    ffree(extraout_ST1_12);
    fVar7 = (float10)thunk_FUN_0042a5f4(&DAT_01c585c4,&DAT_01c58660,&DAT_0099aa6c,&DAT_0099a9f8);
    in_ST2 = extraout_ST1_13;
  }
  if (DAT_0099aa64 != 0) {
    DAT_01c585c8 = DAT_0099aa64;
    if (DAT_0099aa64 < 0) {
      DAT_01c585c8 = -DAT_0099aa64;
    }
    if (DAT_0099aa64 < 0) {
      *(undefined4 *)(puVar1 + -0x84) = 0;
      if (_DAT_01c58670 == f_0) {
        DAT_0099aa28 = f_14;
        if (P7 < f_0) {
          DAT_0099aa28 = f_m14;
        }
        *(undefined4 *)(puVar1 + -0x78) = 0;
      }
      else {
        *(undefined4 *)(puVar1 + -0x7c) = 0;
        DAT_0099aa28 = f_23;
        if (P7 < f_0) {
          DAT_0099aa28 = f_m5;
        }
      }
    }
    else {
      DAT_0099aa28 = f_0;
      if (_DAT_01c58670 != f_0) {
        DAT_0099aa28 = f_0 + f_9;
      }
      *(undefined4 *)(puVar1 + -0x80) = 0;
    }
    DAT_0099aa68 = DAT_0099aa68 - STEP * DAT_0099aa28;
    if (_DAT_01c58670 == f_0) {
      *(undefined4 *)(puVar1 + -0x74) = 0;
      _DAT_0099a9ec = DAT_0099aa70;
      DAT_01c58668 = DAT_0099aa5c;
      _DAT_0099a9f8 = f_0;
      goto LAB_0053abaa;
    }
    ffree(in_ST2);
    ffree(fVar7);
    fVar7 = (float10)FUN_005ff110(puVar1,0x53b36f);
    _DAT_0099a9f4 = (float)fVar7;
    ffree(in_ST2);
    ffree(extraout_ST1_26);
    fVar7 = (float10)FUN_005ff0f5(puVar1,0x53b393);
    _DAT_0099a9f0 = (float)fVar7;
    _DAT_0099a9f8 = _DAT_0099aa4c * f_0_5;
    DAT_01c58660 = (_DAT_0099a9f0 * _DAT_0099a9f8 - _DAT_0099a9f4 * DAT_0099aa68) + DAT_01c58660;
    fVar7 = (float10)_DAT_0099a9f0 * (float10)DAT_0099aa68;
    Y_POS = (float)((float10)_DAT_0099a9f4 * (float10)_DAT_0099a9f8 + fVar7 + (float10)DAT_0099aa6c)
    ;
    DAT_0099aa28 = P6;
    _DAT_0099aa40 = f_0;
    *(undefined4 *)(puVar1 + -0x70) = 0;
    goto LAB_0053b421;
  }
  *(undefined4 *)(puVar1 + -0x88) = 0;
  goto LAB_0053b4db;
}


