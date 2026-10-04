// FUN_00574370 @ 00574370 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00574370(void)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var4;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
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
  unkbyte10 Var5;
  unkbyte10 extraout_ST1_12;
  unkbyte10 extraout_ST1_13;
  unkbyte10 extraout_ST1_14;
  int local_4c;
  
  puVar3 = &stack0xfffffffc;
  ffree(in_ST1);
  ffree(in_ST0);
  Var4 = thunk_FUN_0054e546(&DAT_009a88f8,&DAT_01c585d4);
  if (DAT_01c585d4 == _DAT_009a88f8) {
    ffree(extraout_ST1);
    ffree(Var4);
    Var4 = thunk_FUN_0054d831("Multiple staves not found. Cannot do VJ.",0x29);
    Var5 = extraout_ST1_00;
  }
  else {
    DAT_009a88f4 = DAT_02052740;
    DAT_02052740 = 0;
    if (P2 == f_0) {
      ffree(extraout_ST1);
      ffree(Var4);
      DAT_01caea44 = thunk_FUN_0059ac20(&DAT_009a88fc);
      Var4 = extraout_ST0;
      Var5 = extraout_ST1_01;
      if (DAT_01caea44 == 2) goto LAB_00574d41;
      _DAT_01caee5c = DAT_009a88fc;
      DAT_01caf3b4 = DAT_009a8900;
      _DAT_009a88f0 = (float)_DAT_009a8904;
      DAT_009a88ec = (float)_DAT_009a8908;
      DAT_009a88e8 = (float)_DAT_009a890c;
    }
    else {
      _DAT_01caee5c = (int)ROUND(P2);
      DAT_01caf3b4 = (int)ROUND(P3);
      if (DAT_01caf3b4 == 0) {
        DAT_01caf3b4 = 4;
      }
      _DAT_009a88f0 = P4;
      if (P4 == f_0) {
        _DAT_009a88f0 = f_12;
      }
      DAT_009a88ec = P5;
      if (P5 == f_0) {
        DAT_009a88ec = f_1;
      }
      DAT_009a88e8 = P6;
      Var5 = extraout_ST1;
      if (P6 == f_0) {
        DAT_009a88e8 = f_200;
      }
    }
    OUTPUT_MODE = 2;
    ffree(Var5);
    ffree(Var4);
    Var4 = draw_items();
    OUTPUT_MODE = 1;
    P1 = DAT_009a88ec;
    P2 = DAT_009a88e8;
    if (DAT_0078b4e0 == 0x49) {
      P2 = f_0;
      DAT_0078b4e0 = 0;
    }
    DAT_01c585e0 = (int)ROUND(DAT_009a88ec);
    DAT_01c585e4 = (int)ROUND(P2);
    if ((DAT_01c585e0 < 1) || (MAX_STAFF < DAT_01c585e0)) {
      DAT_01c585e0 = 1;
    }
    if (DAT_01c585e4 < 1) {
      DAT_01c585e4 = MAX_STAFF;
    }
    DAT_01c585e4 = DAT_01c585e4 + DAT_01c585e0 + -1;
    DAT_01caee58 = 300;
    DAT_01caea50 = 0x96;
    local_4c = 0x100;
    DAT_01c585d8 = 1;
    do {
      (&DAT_01caea54)[DAT_01c585d8] = 0;
      DAT_01c585d8 = DAT_01c585d8 + 1;
      local_4c = local_4c + -1;
    } while (0 < local_4c);
    DAT_01caf3bc = 0;
    DAT_01caf3b8 = 999;
    LOAD_I = 0;
    Var5 = extraout_ST1_02;
    do {
      ffree(Var5);
      ffree(Var4);
      iVar2 = FUN_0057513b();
      Var4 = extraout_ST0_00;
      Var5 = extraout_ST1_03;
      if (((iVar2 == 0) && (LOAD_CODE != 0xe)) &&
         ((LOAD_LEN < 0xc ||
          (((LOAD_CODE != 1 || (*(float *)(&ITEM_P12 + LOAD_W * 4) == f_0)) &&
           ((LOAD_CODE != 0x10 ||
            (DAT_01c585d0 = *(float *)(&ITEM_P14 + LOAD_W * 4),
            ((uint)DAT_01c585d0 & 0xffffff) != 0x39395f)))))))) {
        ffree(extraout_ST1_03);
        ffree(extraout_ST0_00);
        Var4 = FUN_00575198(&DAT_01e997ec + LOAD_STAFF * 0x194,&DAT_01eb2bec + LOAD_STAFF * 0x194);
        Var5 = extraout_ST1_04;
      }
    } while (LOAD_I < ITEM_I);
    if (DAT_01caf3bc < DAT_01c585e4) {
      DAT_01c585e4 = DAT_01caf3bc;
    }
    if (DAT_01c585e0 < DAT_01caf3b8) {
      DAT_01c585e0 = DAT_01caf3b8;
    }
    if (DAT_01c585e4 < DAT_01caf3bc) {
      DAT_01caf3bc = DAT_01c585e4;
    }
    if (DAT_01caf3b8 < DAT_01c585e0) {
      DAT_01caf3b8 = DAT_01c585e0;
    }
    if (DAT_01caf3b8 != DAT_01caf3bc) {
      DAT_0078b4f0 = 1;
      DAT_01c585d0 = f_0;
      DAT_01caea44 = DAT_01c585e0;
      LOAD_I = 0;
      ffree(Var5);
      ffree(Var4);
      Var4 = thunk_FUN_0054946a(&DAT_0076a694,0xf);
      DAT_01c585d8 = DAT_01c585e0 + 1;
      iVar2 = (DAT_01c585e4 - DAT_01c585d8) + 1;
      Var5 = extraout_ST1_05;
      while (0 < iVar2) {
        if ((&DAT_01caea54)[DAT_01c585d8] == 0) {
          *(undefined4 *)(puVar3 + -0x20) = 0;
        }
        else {
          fVar1 = (float)(&STAFF_STEP0)[DAT_01c585d8];
          DAT_01c585d4 = fVar1;
          if ((float)(&STAFF_STEP0)[DAT_01caea44] < fVar1) {
            DAT_01c585d4 = (float)(&STAFF_STEP0)[DAT_01caea44];
          }
          P6 = fVar1 * f_7;
          P2 = DAT_01c585d4 * f_7;
          *(undefined2 *)(puVar3 + -0x84) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x82) = (ushort)*(undefined4 *)(puVar3 + -0x84) | 0xc00;
          *(int *)(puVar3 + -0x80) = (int)ROUND((float)_DAT_01caee5c * P2);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x84);
          _DAT_009a88e4 = *(int *)(puVar3 + -0x80);
          ffree(Var5);
          ffree(Var4);
          DAT_01a1acb4 = _DAT_009a88e4;
          FUN_0057579a(&DAT_01e997ec + DAT_01caea44 * 0x194,&DAT_01eb2bec + DAT_01c585d8 * 0x194);
          if (DAT_01a1acb0 == 99999) {
            *(undefined4 *)(puVar3 + -0x1c) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x80) = (&STAFF_Y0)[DAT_01c585d8] - (&STAFF_Y0)[DAT_01caea44];
            *(undefined2 *)(puVar3 + -0x84) = in_FPUControlWord;
            *(ushort *)(puVar3 + -0x82) = (ushort)*(undefined4 *)(puVar3 + -0x84) | 0xc00;
            *(int *)(puVar3 + -0x80) =
                 (int)ROUND(P2 * _DAT_009a88f0 - ((float)*(int *)(puVar3 + -0x80) - P2 * f_8));
            in_FPUControlWord = *(undefined2 *)(puVar3 + -0x84);
            DAT_01a1acb4 = DAT_01a1acb4 - DAT_01a1acb0;
            if (DAT_01a1acb4 < *(int *)(puVar3 + -0x80)) {
              DAT_01a1acb4 = *(int *)(puVar3 + -0x80);
            }
            DAT_01c585d0 = DAT_01c585d0 + (float)DAT_01a1acb4;
            DAT_01caea44 = DAT_01c585d8;
          }
          P2 = DAT_01c585d0 / P6;
          if (ABS(P2) < f_0_2) {
            P2 = f_0;
          }
          *(float *)(&DAT_01caee5c + DAT_01c585d8 * 4) = P2;
          FUN_005f33c9(puVar3,0x574b39);
          Var4 = FUN_005f34d1(puVar3,0x574b54);
          *(undefined4 *)(puVar3 + -0x7c) = 0;
          *(undefined4 *)(puVar3 + -0x90) = 0xc;
          *(undefined1 **)(puVar3 + -0x8c) = &DAT_020b8ea5;
          *(int **)(puVar3 + -0x88) = &DAT_01c585d8;
          ffree(extraout_ST1_06);
          ffree(Var4);
          Var4 = FUN_005f34f0(puVar3 + -0x7c,0x784ff00,&DAT_0076a66c,puVar3 + -0x90,&DAT_007a02f0);
          *(float **)(puVar3 + -0x88) = &P2;
          ffree(extraout_ST1_07);
          ffree(Var4);
          Var4 = FUN_005f3960(puVar3 + -0x7c,&DAT_0076a668,puVar3 + -0x88);
          ffree(extraout_ST1_08);
          ffree(Var4);
          Var4 = thunk_FUN_0054946a(&DAT_020b8ea0,0x200);
          Var5 = extraout_ST1_09;
        }
        *(undefined4 *)(puVar3 + -0x14) = 0;
        DAT_01c585d8 = DAT_01c585d8 + 1;
        *(int *)(puVar3 + -0x24) = *(int *)(puVar3 + -0x24) + -1;
        iVar2 = *(int *)(puVar3 + -0x24);
      }
      LOAD_I = 0;
      while( true ) {
        ffree(Var5);
        ffree(Var4);
        iVar2 = FUN_0057513b();
        Var4 = extraout_ST0_01;
        Var5 = extraout_ST1_10;
        if (iVar2 == 0) {
          if ((LOAD_CODE == 8) && (DAT_01c585e0 < LOAD_STAFF)) {
            P6 = *(float *)(&DAT_01caee5c + LOAD_STAFF * 4);
            if (P6 == f_0) {
              *(undefined4 *)(puVar3 + -8) = 0;
            }
            else {
              if (LOAD_LEN < 4) {
                ffree(extraout_ST1_10);
                ffree(extraout_ST0_01);
                Var4 = thunk_FUN_005239c9(&LOAD_I,&DAT_0076a664);
                Var5 = extraout_ST1_11;
              }
              (&ITEM_P4)[LOAD_W] = P6 + (float)(&ITEM_P4)[LOAD_W];
            }
          }
          else {
            *(undefined4 *)(puVar3 + -0xc) = 0;
          }
        }
        else {
          *(undefined4 *)(puVar3 + -0x10) = 0;
        }
        if (ITEM_I <= LOAD_I) break;
        *(undefined4 *)(puVar3 + -4) = 0;
      }
      ffree(Var5);
      ffree(Var4);
      Var4 = thunk_FUN_00545752(&DAT_0076a660);
      P2 = f_0;
      P3 = f_0;
      P4 = f_0;
      ffree(extraout_ST1_12);
      ffree(Var4);
      Var4 = draw_items();
      ffree(extraout_ST1_13);
      ffree(Var4);
      Var4 = thunk_FUN_00549422();
      DAT_02052740 = DAT_009a88f4;
      Var5 = extraout_ST1_14;
    }
  }
LAB_00574d41:
  ffree(Var5);
  ffree(Var4);
  return;
}


