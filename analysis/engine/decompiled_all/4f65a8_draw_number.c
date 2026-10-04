// draw_number @ 004f65a8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_number(int *param_1)

{
  undefined1 *puVar1;
  float fVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined2 in_FPUControlWord;
  undefined2 uVar7;
  unkbyte10 in_ST0;
  unkbyte10 Var8;
  float10 fVar9;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  
  puVar4 = &stack0xfffffffc;
  if (400 < *param_1) {
    _DAT_008d2038 = 0;
  }
  ffree(in_ST0);
  Var8 = push_words(&DAT_00766774,&DAT_020b9440);
  ffree(Var8);
  push_words(&DAT_00766774,&P1);
  DAT_008d2034 = *param_1;
  _DAT_008d202c = P5;
  if (P5 < f_0) {
    DAT_008d2034 = -DAT_008d2034;
    _DAT_008d202c = -P5;
  }
  DAT_008d2030 = (uint)(P5 < f_0);
  DAT_008d2028 = (_DAT_008d202c - (float)DAT_008d2034) + f_3_0Em4;
  DAT_008d2024 = (int)ROUND(DAT_008d2028 * f_1000);
  DAT_008d2020 = IP8;
  if (0 < IP9) {
    IP9 = 0;
  }
  IP8 = IP9;
  P9 = P19;
  fVar9 = (float10)FUN_005f34d1(&stack0xfffffffc,0x4f6709);
  fVar2 = P18;
  DAT_008d201c = DAT_008d2034;
  if (DAT_008d2034 < 0x3e9) {
    fVar9 = (float10)P18;
    if ((float10)f_1000 <= ABS(fVar9)) {
      *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
      *(int *)(puVar4 + -0xac) = (int)ROUND(fVar2);
      uVar7 = *(undefined2 *)(puVar4 + -0xb0);
      DAT_008d201c = *(int *)(puVar4 + -0xac);
      P5 = f_0;
      ffree(fVar9);
      fVar9 = (float10)thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00766740,&DAT_00766730,"(1i4)",5,
                                          &DAT_008d201c);
      if (DAT_008d201c < 0) {
        ffree(fVar9);
        fVar9 = (float10)thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00766740,&DAT_00766724,"(1i5)",
                                            5,&DAT_008d201c);
      }
      _DAT_008d202c = P18;
      if (P18 < f_0) {
        DAT_008d201c = -DAT_008d201c;
        fVar9 = (float10)P18;
        _DAT_008d202c = (float)-fVar9;
      }
      DAT_008d2030 = (uint)(P18 < f_0);
      DAT_008d2028 = (_DAT_008d202c - (float)DAT_008d201c) + f_3_0Em4;
      fVar2 = DAT_008d2028 * f_1000;
      *(undefined2 *)(puVar4 + -0xb0) = uVar7;
      *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
      *(int *)(puVar4 + -0xac) = (int)ROUND(fVar2);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
      DAT_008d2024 = *(int *)(puVar4 + -0xac);
      *(undefined4 *)(puVar4 + -0x80) = 0;
    }
    else {
      *(undefined4 *)(puVar4 + -0x84) = 0;
      if (DAT_008d201c < 100) {
        if (DAT_008d201c < 10) {
          DAT_008d2018 = 2;
          DAT_020b8ea0._0_1_ = (char)DAT_008d201c + '0';
        }
        else {
          DAT_008d2018 = 3;
          ffree(fVar9);
          fVar9 = (float10)thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00766740,&DAT_00766758,
                                              "(1i2)",5,&DAT_008d201c);
        }
      }
      else {
        DAT_008d2018 = 4;
        ffree(fVar9);
        fVar9 = (float10)thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00766740,&DAT_0076674c,"(1i3)",
                                            5,&DAT_008d201c);
      }
      iVar3 = DAT_008d2018;
      if (IP17 != 0) {
        _DAT_008d2014 = IP17 + 0x40;
        if (100 < IP17) {
          _DAT_008d2014 = IP17 + -4;
        }
        puVar4[-0xa9] = DAT_008d2014;
        (&DAT_020b8e9f)[iVar3] = puVar4[-0xa9];
      }
      if (DAT_008d2030 == 0) {
        *(undefined4 *)(puVar4 + -0x7c) = 0;
      }
      else {
        fVar9 = (float10)FUN_005f33c9(puVar4,0x4f6a7f);
        DAT_020b8ea0._0_1_ = DAT_0076673c;
        *(undefined4 *)(puVar4 + -0x78) = 0;
      }
    }
  }
  else {
    *(undefined4 *)(puVar4 + -0x88) = 0;
    fVar2 = P18;
    if (2000 < DAT_008d201c) {
      DAT_008d201c = DAT_008d201c + -0x3c8;
    }
    DAT_020b8ea0._0_1_ = (char)DAT_008d201c + 'X';
    DAT_01cb1068 = 1;
    if (P18 == f_0) {
      *(undefined4 *)(puVar4 + -0x74) = 0;
    }
    else {
      *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
      *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
      *(int *)(puVar4 + -0xac) = (int)ROUND(fVar2);
      in_FPUControlWord = *(undefined2 *)(puVar4 + -0xb0);
      DAT_008d201c = *(int *)(puVar4 + -0xac);
      iVar3 = DAT_008d201c;
      if (DAT_008d201c < 0) {
        iVar3 = -DAT_008d201c;
      }
      if (iVar3 < 100) {
        DAT_008d201c = DAT_008d201c % 100;
        if (DAT_008d201c < 10) {
          ffree(fVar9);
          fVar9 = (float10)thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00766758,&DAT_00766758,
                                              "(1i1)",5,&DAT_008d201c);
        }
        else {
          ffree(fVar9);
          fVar9 = (float10)thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00766758,&DAT_0076674c,
                                              "(1i2)",5,&DAT_008d201c);
        }
        *(undefined4 *)(puVar4 + -0x6c) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -0x70) = 0;
        _DAT_008d2010 = 0x40;
        if (DAT_008d201c < 0) {
          DAT_008d201c = -DAT_008d201c;
          _DAT_008d2010 = 0x60;
        }
        DAT_020b8ea0._1_1_ = (char)(DAT_008d201c / 100) + (char)_DAT_008d2010;
        if (DAT_008d201c % 100 != 0) {
          DAT_020b8ea2 = (char)(DAT_008d201c % 100) + (char)_DAT_008d2010;
        }
      }
    }
  }
  if (IP7 < 0) {
    IP7 = 0;
  }
  if (IP7 < 0x5a) {
    if (10 < IP7) {
      IP7 = IP7 + -1;
    }
    if (10 < IP7) {
      IP7 = 0;
    }
    IP7 = (int)(short)(&DAT_00794ff4)[IP7];
  }
  else {
    *(undefined4 *)(puVar4 + -0x68) = 0;
  }
  IP8 = IP7;
  DAT_008d200c = 0;
  if (0x59 < IP7 % 100) {
    DAT_008d200c = 2;
  }
  IP7 = 0;
  DAT_008d2008 = X_POS;
  P5 = P20;
  _DAT_008d2004 = P13;
  _DAT_008d2000 = P14;
  P7 = f_0;
  IP12 = 0;
  P10 = f_0;
  DAT_008d1ffc = IP10;
  IP10 = 0;
  ffree(fVar9);
  fVar9 = (float10)amod(&P6,&DAT_00766720);
  DAT_008d1ff8 = (float)fVar9;
  if (DAT_008d1ff8 == f_0) {
    DAT_008d1ff8 = f_1;
  }
  P6 = DAT_008d1ff8;
  IP1 = 99;
  DAT_008d1ff4 = DAT_0078b6a0;
  DAT_008d1ff0 = P11;
  P11 = f_0;
  *(undefined2 *)(puVar4 + -0xb0) = in_FPUControlWord;
  *(ushort *)(puVar4 + -0xae) = (ushort)*(undefined4 *)(puVar4 + -0xb0) | 0xc00;
  *(int *)(puVar4 + -0xac) = (int)ROUND(P16);
  IP16 = *(int *)(puVar4 + -0xac);
  puVar5 = (undefined4 *)&DAT_020b8ea0;
  puVar6 = (undefined4 *)(puVar4 + -0x2b0);
  for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  ffree(extraout_ST1);
  DAT_01cb1068 = FUN_005ff950(puVar4 + -0x2b0,0x200);
  if (DAT_008d2024 == 0) {
    *(undefined4 *)(puVar4 + -100) = 0;
    Var8 = extraout_ST0;
  }
  else {
    ffree(extraout_ST0);
    Var8 = thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_00766740,&DAT_0076674c,"(1i3.3)",7,
                              &DAT_008d2024);
    if ((char)DAT_020b8ea0 == '0') {
      FUN_005f46bc(puVar4,0x4f6ea4);
      Var8 = FUN_005f34d1(puVar4,0x4f6eba);
      DAT_01cb1068 = DAT_01cb1068 + -1;
    }
    else if (((char)DAT_020b8ea0 == '-') && (DAT_020b8ea0._1_1_ == '0')) {
      FUN_005f46bc(puVar4,0x4f6f3c);
      Var8 = FUN_005f34d1(puVar4,0x4f6f52);
      DAT_01cb1068 = DAT_01cb1068 + -1;
    }
    puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
    DAT_01cb1068 = DAT_01cb1068 + 1;
    *puVar1 = 0x2e;
    *(undefined4 *)(puVar4 + -0x60) = 3;
    DAT_008d2018 = 1;
    do {
      puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_01cb1068);
      DAT_01cb1068 = DAT_01cb1068 + 1;
      *puVar1 = (&DAT_020b909f)[DAT_008d2018];
      DAT_008d2018 = DAT_008d2018 + 1;
      *(int *)(puVar4 + -0x60) = *(int *)(puVar4 + -0x60) + -1;
    } while (0 < *(int *)(puVar4 + -0x60));
  }
  while ((DAT_008d2024 != 0 && ((&DAT_020b8e9f)[DAT_01cb1068] == '0'))) {
    DAT_01cb1068 = DAT_01cb1068 + -1;
    *(undefined4 *)(puVar4 + -0x58) = 0;
  }
  *(undefined4 *)(puVar4 + -0x5c) = 0;
  if ((P26 != f_0) && (IP8 != 0x5e)) {
    P14 = f_m1;
    P16 = P26;
  }
  DAT_008d1fec = DAT_020b9470;
  DAT_008d1fe8 = DAT_01cb1068;
  ffree(Var8);
  Var8 = draw_text();
  DAT_020b9470 = DAT_008d1fec;
  DAT_01cb1068 = DAT_008d1fe8;
  DAT_0078b6a0 = DAT_008d1ff4;
  if (DAT_008d2020 == 0) {
    DAT_020b9468 = f_0;
    DAT_020b946c = f_0;
    *(undefined4 *)(puVar4 + -0x54) = 0;
    goto LAB_004f741a;
  }
  DAT_008d2028 = _DAT_008d2000 + P13;
  X_POS = DAT_008d2008;
  ffree(Var8);
  Var8 = push_words(&DAT_00766774,&P1);
  ffree(Var8);
  Var8 = push_words(&DAT_00766774,&IP1);
  _DAT_008d1fe4 = DAT_008d1ffc;
  _DAT_008d1fe0 = X_POS;
  _DAT_008d1fdc = DAT_008d1ff0;
  DAT_008d1fd8 = Y_POS;
  X_POS = DAT_008d2028 * f_75 + DAT_008d2008;
  if (DAT_008d200c != 0) {
    X_POS = X_POS - STEP * f_1_2 * DAT_008d1ff8;
  }
  if (DAT_008d1ffc == 0) {
    DAT_008d1ffc = 1;
  }
  P8 = (float)DAT_008d1ffc;
  IP8 = DAT_008d1ffc;
  IP5 = 2 - DAT_008d2020;
  P4 = P6 * f_1_55 + P4 + _DAT_008d2004;
  ffree(Var8);
  fVar9 = (float10)staff_level_y(&P4);
  Y_POS = (float)fVar9;
  if (IP11 == 0) {
    *(undefined4 *)(puVar4 + -0x50) = 0;
    DAT_008d2028 = f_5;
    if (1 < DAT_01cb1068) {
      *(int *)(puVar4 + -0xac) = DAT_01cb1068 * 2 + 2;
      DAT_008d2028 = (float)*(int *)(puVar4 + -0xac);
      if (f_1000 < P5) {
        DAT_008d2028 = DAT_008d2028 + f_1_5;
      }
    }
    _DAT_008d1fd4 = DAT_008d2028;
    if (IP8 == 2) {
      _DAT_008d1fd4 = f_6;
    }
    if (P12 != f_0) {
      _DAT_008d1fd4 = P12;
    }
    *(undefined4 *)(puVar4 + -0x44) = 0;
    if (IP5 == 0) {
      *(undefined4 *)(puVar4 + -0x34) = 0;
      P7 = P6 * f_5;
      P6 = DAT_008d2028 * P6;
    }
    else {
      P6 = P6 * _DAT_008d1fd4;
      P7 = f_0;
LAB_004f7361:
      IP12 = 0xc;
      if (OUTPUT_MODE != 0) {
        IP12 = 4;
      }
      if (OUTPUT_MODE == -1) {
        IP12 = 2;
      }
      *(undefined4 *)(puVar4 + -0x30) = 0;
    }
  }
  else {
    if (P12 == f_0) {
      P12 = DAT_008d1ff0;
    }
    P6 = DAT_008d1ff8 * DAT_008d1ff0;
    P7 = DAT_008d1ff8 * P12;
    if (IP5 != 0) {
      *(undefined4 *)(puVar4 + -0x48) = 0;
      goto LAB_004f7361;
    }
    *(undefined4 *)(puVar4 + -0x4c) = 0;
  }
  IP11 = 0;
  IP9 = 0;
  P13 = f_0;
  *(undefined4 *)(puVar4 + -0x2c) = 0;
  P16 = f_0;
  ffree(extraout_ST1_00);
  Var8 = draw_box();
  ffree(Var8);
  Var8 = pop_words(&DAT_00766774,&IP1);
  ffree(Var8);
  Var8 = pop_words(&DAT_00766774,&P1);
  X_POS = DAT_008d2008;
  Y_POS = DAT_008d1fd8;
  ffree(Var8);
  Var8 = draw_text();
LAB_004f741a:
  ffree(Var8);
  Var8 = pop_words(&DAT_00766774,&P1);
  ffree(Var8);
  Var8 = pop_words(&DAT_00766774,&DAT_020b9440);
  DAT_020b945c = P8;
  ffree(Var8);
  return;
}


