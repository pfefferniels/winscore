// FUN_0055cb57 @ 0055cb57 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055cb57(void)

{
  undefined4 *puVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  unkbyte10 Var7;
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
  unkbyte10 extraout_ST0_14;
  unkbyte10 extraout_ST0_15;
  float10 fVar8;
  unkbyte10 extraout_ST1;
  float10 extraout_ST1_00;
  undefined1 *puVar9;
  
  puVar9 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x55cb9f);
  FUN_005f33c9(puVar9,0x55cbbb);
  Var7 = FUN_005f33c9(puVar9,0x55cbdd);
  *(undefined1 **)(puVar9 + -0xec) = puVar9 + -0x108;
  *(undefined4 *)(puVar9 + -0xf0) = 0x12;
  *(undefined4 *)(puVar9 + -0xe8) = 2;
  *(undefined4 *)(puVar9 + -0xe4) = 4;
  ffree(Var7);
  FUN_005f6540(puVar9 + -0xd4,5,0x784ff00,&DAT_00769cbc,puVar9 + -0xf0);
  *(undefined4 *)(puVar9 + -0xdc) = DAT_0078b464;
  *(undefined4 *)(puVar9 + -0xd8) = DAT_0078b468;
  *(undefined4 *)(puVar9 + -0xd4) = 0;
  FUN_005f33c9(puVar9,0x55cc76);
  FUN_005f33c9(puVar9,0x55cc92);
  Var7 = FUN_005f33c9(puVar9,0x55ccb4);
  *(undefined1 **)(puVar9 + -0xec) = puVar9 + -0x108;
  *(undefined4 *)(puVar9 + -0xf0) = 0x12;
  *(undefined4 *)(puVar9 + -0xe8) = 2;
  *(undefined4 *)(puVar9 + -0xe4) = 4;
  ffree(Var7);
  Var7 = FUN_005f6540(puVar9 + -0xd4,6,0x784ff00,&DAT_00769cbc,puVar9 + -0xf0);
  *(undefined4 *)(puVar9 + -0xd4) = 0;
  *(undefined4 *)(puVar9 + -0xe0) = 0x50;
  *(undefined **)(puVar9 + -0xdc) = &DAT_009a6ea8;
  ffree(Var7);
  Var7 = FUN_005fdbd0(puVar9 + -0xd4,5,0x784ff00,&DAT_00769cf0,puVar9 + -0xe0,&DAT_0079f07c);
  *(undefined4 *)(puVar9 + -0xd4) = 0;
  *(undefined4 *)(puVar9 + -0xe0) = 0x25;
  *(undefined **)(puVar9 + -0xdc) = &DAT_009a6ea8;
  ffree(Var7);
  Var7 = FUN_005fdbd0(puVar9 + -0xd4,5,0x784ff00,&DAT_00769cec,puVar9 + -0xe0,&DAT_0079f090);
  *(undefined **)(puVar9 + -0xe0) = &DAT_009a4154;
  ffree(Var7);
  Var7 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769cac,puVar9 + -0xe0);
  *(undefined4 *)(puVar9 + -0xa4) = 200;
  DAT_009a4150 = 1;
  do {
    *(undefined4 *)(puVar9 + -0xd4) = 0;
    *(undefined **)(puVar9 + -0xe0) = &DAT_009a414c;
    ffree(Var7);
    iVar4 = FUN_005fdbd0(puVar9 + -0xd4,5,0x784ff01,&DAT_00769c90,puVar9 + -0xe0,&DAT_0079f0b0);
    *(int *)(puVar9 + -0xa0) = iVar4;
    Var7 = extraout_ST0;
    if (iVar4 == 0) {
      puVar1 = &DAT_009a6864 + DAT_009a4150;
      *(undefined4 *)(puVar9 + -0xe0) = 4;
      *(undefined4 **)(puVar9 + -0xdc) = puVar1;
      ffree(extraout_ST0);
      iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c94,puVar9 + -0xe0);
      *(int *)(puVar9 + -0xa0) = iVar4;
      Var7 = extraout_ST0_00;
      if (iVar4 == 0) {
        iVar4 = DAT_009a4150 * 4;
        *(undefined4 *)(puVar9 + -0xe0) = 4;
        *(undefined **)(puVar9 + -0xdc) = &DAT_009a6544 + iVar4;
        ffree(extraout_ST0_00);
        iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c98,puVar9 + -0xe0);
        *(int *)(puVar9 + -0xa0) = iVar4;
        Var7 = extraout_ST0_01;
        if (iVar4 == 0) {
          iVar4 = DAT_009a4150 * 4;
          *(undefined4 *)(puVar9 + -0xe0) = 4;
          *(undefined **)(puVar9 + -0xdc) = &DAT_009a6224 + iVar4;
          ffree(extraout_ST0_01);
          iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c98,puVar9 + -0xe0);
          *(int *)(puVar9 + -0xa0) = iVar4;
          Var7 = extraout_ST0_02;
          if (iVar4 == 0) {
            iVar4 = DAT_009a4150 * 4;
            *(undefined4 *)(puVar9 + -0xe0) = 4;
            *(int *)(puVar9 + -0xdc) = iVar4 + 0x9a55a4;
            ffree(extraout_ST0_02);
            uVar5 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769ce8,puVar9 + -0xe0);
            *(undefined4 *)(puVar9 + -0xa0) = uVar5;
            Var7 = extraout_ST0_03;
          }
        }
      }
    }
    if (*(int *)(puVar9 + -0xa0) != 0) break;
    DAT_009a4150 = DAT_009a4150 + 1;
    *(int *)(puVar9 + -0xa4) = *(int *)(puVar9 + -0xa4) + -1;
  } while (0 < *(int *)(puVar9 + -0xa4));
  *(undefined4 *)(puVar9 + -0x9c) = 100;
  DAT_009a4148 = 1;
  do {
    iVar4 = DAT_009a4148 * 4;
    *(undefined4 *)(puVar9 + -0xd4) = 0;
    *(undefined4 *)(puVar9 + -0xe0) = 4;
    *(int *)(puVar9 + -0xdc) = iVar4 + 0x9a6b84;
    ffree(Var7);
    iVar4 = FUN_005fdbd0(puVar9 + -0xd4,5,0x784ff01,&DAT_00769c98,puVar9 + -0xe0,&DAT_0079f100);
    *(int *)(puVar9 + -0x98) = iVar4;
    Var7 = extraout_ST0_04;
    if (iVar4 == 0) {
      puVar1 = &DAT_009a4f64 + DAT_009a4148;
      *(undefined4 *)(puVar9 + -0xe0) = 4;
      *(undefined4 **)(puVar9 + -0xdc) = puVar1;
      ffree(extraout_ST0_04);
      iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c94,puVar9 + -0xe0);
      *(int *)(puVar9 + -0x98) = iVar4;
      Var7 = extraout_ST0_05;
      if (iVar4 == 0) {
        iVar4 = DAT_009a4148 * 4;
        *(undefined4 *)(puVar9 + -0xe0) = 4;
        *(int *)(puVar9 + -0xdc) = iVar4 + 0x9a4c44;
        ffree(extraout_ST0_05);
        iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c94,puVar9 + -0xe0);
        *(int *)(puVar9 + -0x98) = iVar4;
        Var7 = extraout_ST0_06;
        if (iVar4 == 0) {
          iVar4 = DAT_009a4148 * 4;
          *(undefined4 *)(puVar9 + -0xe0) = 4;
          *(int *)(puVar9 + -0xdc) = iVar4 + 0x9a4ab4;
          ffree(extraout_ST0_06);
          iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c94,puVar9 + -0xe0);
          *(int *)(puVar9 + -0x98) = iVar4;
          Var7 = extraout_ST0_07;
          if (iVar4 == 0) {
            puVar1 = &DAT_009a4dd4 + DAT_009a4148;
            *(undefined4 *)(puVar9 + -0xe0) = 4;
            *(undefined4 **)(puVar9 + -0xdc) = puVar1;
            ffree(extraout_ST0_07);
            iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c94,puVar9 + -0xe0);
            *(int *)(puVar9 + -0x98) = iVar4;
            Var7 = extraout_ST0_08;
            if (iVar4 == 0) {
              iVar4 = DAT_009a4148 * 4;
              *(undefined4 *)(puVar9 + -0xe0) = 4;
              *(int *)(puVar9 + -0xdc) = iVar4 + 0x9a50f4;
              ffree(extraout_ST0_08);
              iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c94,puVar9 + -0xe0);
              *(int *)(puVar9 + -0x98) = iVar4;
              Var7 = extraout_ST0_09;
              if (iVar4 == 0) {
                iVar4 = DAT_009a4148 * 4;
                *(undefined4 *)(puVar9 + -0xe0) = 4;
                *(undefined **)(puVar9 + -0xdc) = &DAT_009a4154 + iVar4;
                ffree(extraout_ST0_09);
                uVar5 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769ce4,puVar9 + -0xe0);
                *(undefined4 *)(puVar9 + -0x98) = uVar5;
                Var7 = extraout_ST0_10;
              }
            }
          }
        }
      }
    }
    if (*(int *)(puVar9 + -0x98) != 0) break;
    DAT_009a4148 = DAT_009a4148 + 1;
    *(int *)(puVar9 + -0x9c) = *(int *)(puVar9 + -0x9c) + -1;
  } while (0 < *(int *)(puVar9 + -0x9c));
  *(undefined4 *)(puVar9 + -0xd4) = 0;
  ffree(Var7);
  Var7 = FUN_005f7950(puVar9 + -0xd4,5,0x784ff00,&DAT_00769c7c,0);
  DAT_009a4148 = DAT_009a4148 + -1;
  while (DAT_009a4150 = DAT_009a4150 + -1, (float)(&DAT_009a6864)[DAT_009a4150] == f_0) {
    *(undefined4 *)(puVar9 + -0x90) = 0;
  }
  *(undefined4 *)(puVar9 + -0xd4) = 0;
  *(undefined4 *)(puVar9 + -0xe0) = 0x50;
  *(undefined **)(puVar9 + -0xdc) = &DAT_009a6ea8;
  ffree(Var7);
  Var7 = FUN_005fdbd0(puVar9 + -0xd4,6,0x784ff00,&DAT_00769cf0,puVar9 + -0xe0,&DAT_0079f12c);
  *(undefined4 *)(puVar9 + -0xd4) = 0;
  *(undefined4 *)(puVar9 + -0xe0) = 0x25;
  *(undefined **)(puVar9 + -0xdc) = &DAT_009a6ea8;
  ffree(Var7);
  Var7 = FUN_005fdbd0(puVar9 + -0xd4,6,0x784ff00,&DAT_00769cec,puVar9 + -0xe0,&DAT_0079f140);
  *(undefined **)(puVar9 + -0xe0) = &DAT_009a4154;
  ffree(Var7);
  Var7 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769cac,puVar9 + -0xe0);
  *(undefined4 *)(puVar9 + -0x84) = 200;
  DAT_009a4144 = 1;
  do {
    *(undefined4 *)(puVar9 + -0xd4) = 0;
    *(undefined **)(puVar9 + -0xe0) = &DAT_009a414c;
    ffree(Var7);
    iVar4 = FUN_005fdbd0(puVar9 + -0xd4,6,0x784ff01,&DAT_00769c90,puVar9 + -0xe0,&DAT_0079f160);
    *(int *)(puVar9 + -0x80) = iVar4;
    Var7 = extraout_ST0_11;
    if (iVar4 == 0) {
      puVar1 = &DAT_009a6864 + DAT_009a4144;
      *(undefined4 *)(puVar9 + -0xe0) = 4;
      *(undefined4 **)(puVar9 + -0xdc) = puVar1;
      ffree(extraout_ST0_11);
      iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c94,puVar9 + -0xe0);
      *(int *)(puVar9 + -0x80) = iVar4;
      Var7 = extraout_ST0_12;
      if (iVar4 == 0) {
        iVar4 = DAT_009a4144 * 4;
        *(undefined4 *)(puVar9 + -0xe0) = 4;
        *(undefined **)(puVar9 + -0xdc) = &DAT_009a5be4 + iVar4;
        ffree(extraout_ST0_12);
        iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c98,puVar9 + -0xe0);
        *(int *)(puVar9 + -0x80) = iVar4;
        Var7 = extraout_ST0_13;
        if (iVar4 == 0) {
          iVar4 = DAT_009a4144 * 4;
          *(undefined4 *)(puVar9 + -0xe0) = 4;
          *(undefined **)(puVar9 + -0xdc) = &DAT_009a58c4 + iVar4;
          ffree(extraout_ST0_13);
          iVar4 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769c98,puVar9 + -0xe0);
          *(int *)(puVar9 + -0x80) = iVar4;
          Var7 = extraout_ST0_14;
          if (iVar4 == 0) {
            iVar4 = DAT_009a4144 * 4;
            *(undefined4 *)(puVar9 + -0xe0) = 4;
            *(undefined **)(puVar9 + -0xdc) = &DAT_009a5284 + iVar4;
            ffree(extraout_ST0_14);
            uVar5 = FUN_005fe110(puVar9 + -0xd4,&DAT_00769ce8,puVar9 + -0xe0);
            *(undefined4 *)(puVar9 + -0x80) = uVar5;
            Var7 = extraout_ST0_15;
          }
        }
      }
    }
    if (*(int *)(puVar9 + -0x80) != 0) break;
    DAT_009a4144 = DAT_009a4144 + 1;
    *(int *)(puVar9 + -0x84) = *(int *)(puVar9 + -0x84) + -1;
  } while (0 < *(int *)(puVar9 + -0x84));
  *(undefined4 *)(puVar9 + -0xd4) = 0;
  ffree(Var7);
  fVar8 = (float10)FUN_005f7950(puVar9 + -0xd4,6,0x784ff00,&DAT_00769c7c,0);
  while (iVar4 = DAT_009a4148, DAT_009a4144 = DAT_009a4144 + -1,
        (float)(&DAT_009a6864)[DAT_009a4144] == f_0) {
    *(undefined4 *)(puVar9 + -0x78) = 0;
  }
  *(int *)(puVar9 + -0x74) = DAT_009a4148;
  DAT_009a4140 = 1;
  do {
    if (iVar4 < 1) {
      ffree(fVar8);
      return;
    }
    *(int *)(puVar9 + -0x70) = DAT_009a4150;
    DAT_009a4138 = 1;
    fVar2 = f_999;
    iVar3 = DAT_009a4138;
    iVar6 = DAT_009a4130;
    iVar4 = DAT_009a4150;
    while (DAT_009a4130 = iVar3, 0 < iVar4) {
      _DAT_009a413c =
           ABS((float)(&DAT_009a4f64)[DAT_009a4140] - (float)(&DAT_009a6864)[DAT_009a4130]);
      DAT_009a4138 = DAT_009a4130;
      if (_DAT_009a413c < fVar2) {
        *(undefined4 *)(DAT_009a4140 * 4 + 0x9a6094) = (&DAT_009a6864)[DAT_009a4130];
        iVar6 = DAT_009a4130;
      }
      else {
        *(undefined4 *)(puVar9 + -0x6c) = 0;
        _DAT_009a413c = fVar2;
      }
      DAT_009a4130 = iVar6;
      *(undefined4 *)(puVar9 + -0x68) = 0;
      *(int *)(puVar9 + -0x70) = *(int *)(puVar9 + -0x70) + -1;
      fVar2 = _DAT_009a413c;
      iVar3 = DAT_009a4138 + 1;
      iVar6 = DAT_009a4130;
      iVar4 = *(int *)(puVar9 + -0x70);
    }
    *(int *)(puVar9 + -100) = DAT_009a4150;
    DAT_009a4138 = 1;
    _DAT_009a413c = f_999;
    DAT_009a4130 = iVar6;
    iVar4 = DAT_009a4150;
    while (0 < iVar4) {
      if (ABS((float)(&DAT_009a4dd4)[DAT_009a4140] - (float)(&DAT_009a6864)[DAT_009a4138]) <
          _DAT_009a413c) {
        DAT_009a412c = DAT_009a4138;
        _DAT_009a413c =
             ABS((float)(&DAT_009a4dd4)[DAT_009a4140] - (float)(&DAT_009a6864)[DAT_009a4138]);
        *(undefined4 *)(DAT_009a4140 * 4 + 0x9a5f04) = (&DAT_009a6864)[DAT_009a4138];
      }
      else {
        *(undefined4 *)(puVar9 + -0x60) = 0;
      }
      *(undefined4 *)(puVar9 + -0x5c) = 0;
      DAT_009a4138 = DAT_009a4138 + 1;
      *(int *)(puVar9 + -100) = *(int *)(puVar9 + -100) + -1;
      iVar4 = *(int *)(puVar9 + -100);
    }
    *(int *)(puVar9 + -0xd8) =
         *(int *)(&DAT_009a5be4 + DAT_009a4130 * 4) - *(int *)(&DAT_009a6544 + DAT_009a4130 * 4);
    *(float *)(DAT_009a4140 * 4 + 0x9a4604) = (float)*(int *)(puVar9 + -0xd8);
    *(int *)(puVar9 + -0xd8) =
         *(int *)(&DAT_009a5be4 + DAT_009a412c * 4) - *(int *)(&DAT_009a6544 + DAT_009a412c * 4);
    *(float *)(DAT_009a4140 * 4 + 0x9a4474) = (float)*(int *)(puVar9 + -0xd8);
    DAT_009a4128 = (&ITEM_PTR0)[*(int *)(DAT_009a4140 * 4 + 0x9a6b84)];
    DAT_009a4124 = *(float *)(DAT_009a4140 * 4 + 0x9a50f4);
    DAT_009a4120 = 0;
    if (((float)(&DAT_009a4dd4)[DAT_009a4140] == (float)(&DAT_009a4dd8)[DAT_009a4140] &&
         (float)(&DAT_009a4f64)[DAT_009a4140] == (float)(&DAT_009a4f68)[DAT_009a4140]) ||
       ((float)(&DAT_009a4dd4)[DAT_009a4140] == *(float *)(DAT_009a4140 * 4 + 0x9a4dd0) &&
        (float)(&DAT_009a4f64)[DAT_009a4140] == *(float *)(DAT_009a4140 * 4 + 0x9a4f60))) {
      *(undefined4 *)(puVar9 + -0x58) = 0;
      if ((float)(&ITEM_P4)[DAT_009a4128] != (float)(&ITEM_P5)[DAT_009a4128]) {
        *(undefined4 *)(puVar9 + -0x50) = 0;
        goto LAB_0055d8e1;
      }
      DAT_009a411c = *(int *)(&DAT_009a6544 + DAT_009a4130 * 4);
      _DAT_009a4118 = (float)(&DAT_009a6864)[DAT_009a4130];
      iVar6 = DAT_009a4130 + 1;
      iVar4 = 0xc9 - iVar6;
      *(int *)(puVar9 + -0x4c) = iVar4;
      while (0 < iVar4) {
        if (_DAT_009a4118 < (float)(&DAT_009a6864)[iVar6]) {
          *(undefined4 *)(puVar9 + -0x48) = 0;
          break;
        }
        if (*(int *)(&DAT_009a6544 + iVar6 * 4) < DAT_009a411c) {
          DAT_009a411c = *(int *)(&DAT_009a6544 + iVar6 * 4);
        }
        iVar6 = iVar6 + 1;
        *(int *)(puVar9 + -0x4c) = *(int *)(puVar9 + -0x4c) + -1;
        iVar4 = *(int *)(puVar9 + -0x4c);
      }
      DAT_009a4110 = *(int *)(&DAT_009a5be4 + DAT_009a4130 * 4);
      DAT_009a4114 = DAT_009a4130 + 1;
      iVar4 = 0xc9 - DAT_009a4114;
      *(int *)(puVar9 + -0x44) = iVar4;
      while (0 < iVar4) {
        if (_DAT_009a4118 < (float)(&DAT_009a6864)[DAT_009a4114]) {
          *(undefined4 *)(puVar9 + -0x40) = 0;
          break;
        }
        if (*(int *)(&DAT_009a5be4 + DAT_009a4114 * 4) < DAT_009a4110) {
          DAT_009a4110 = *(int *)(&DAT_009a5be4 + DAT_009a4114 * 4);
        }
        DAT_009a4114 = DAT_009a4114 + 1;
        *(int *)(puVar9 + -0x44) = *(int *)(puVar9 + -0x44) + -1;
        iVar4 = *(int *)(puVar9 + -0x44);
      }
      _DAT_009a4154 = DAT_009a4110 - DAT_009a411c;
      (&ITEM_P4)[DAT_009a4128] = (float)_DAT_009a4154 + (float)(&ITEM_P4)[DAT_009a4128];
      (&ITEM_P5)[DAT_009a4128] = (float)_DAT_009a4154 + (float)(&ITEM_P5)[DAT_009a4128];
      DAT_009a4120 = 1;
      *(undefined4 *)(puVar9 + -0x3c) = 0;
    }
    else {
      *(undefined4 *)(puVar9 + -0x54) = 0;
LAB_0055d8e1:
      _DAT_009a410c = f_2;
      if (((f_8 <= (float)(&ITEM_LEN)[DAT_009a4128]) &&
          ((float)(&ITEM_P4)[DAT_009a4128] == (float)(&ITEM_P5)[DAT_009a4128])) &&
         (*(float *)(&ITEM_P8 + DAT_009a4128 * 4) == f_m2 ||
          *(float *)(&ITEM_P8 + DAT_009a4128 * 4) == f_m3)) {
        _DAT_009a410c = f_0;
      }
      if ((*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) == 2) &&
         (*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) == 2)) {
        (&ITEM_P4)[DAT_009a4128] = (float)*(int *)(&DAT_009a5be4 + DAT_009a4130 * 4) + _DAT_009a410c
        ;
        (&ITEM_P5)[DAT_009a4128] = (float)*(int *)(&DAT_009a5be4 + DAT_009a412c * 4) + _DAT_009a410c
        ;
        if (f_0 <= DAT_009a4124) goto LAB_0055e2e3;
        *(undefined4 *)(puVar9 + -0x38) = 0;
      }
      else if ((*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) == 2) &&
              (*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) == 1)) {
        (&ITEM_P4)[DAT_009a4128] = (float)*(int *)(&DAT_009a5be4 + DAT_009a4130 * 4) + f_2;
        (&ITEM_P5)[DAT_009a4128] = *(float *)(&DAT_009a5284 + DAT_009a412c * 4) + f_1;
        if (f_0 <= DAT_009a4124) goto LAB_0055e2e3;
        *(undefined4 *)(puVar9 + -0x34) = 0;
      }
      else if ((*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) == 1) &&
              (*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) == 2)) {
        (&ITEM_P4)[DAT_009a4128] = *(float *)(&DAT_009a5284 + DAT_009a4130 * 4) + f_1;
        (&ITEM_P5)[DAT_009a4128] = (float)*(int *)(&DAT_009a5be4 + DAT_009a412c * 4) + f_2;
        if (f_0 <= DAT_009a4124) goto LAB_0055e2e3;
        *(undefined4 *)(puVar9 + -0x30) = 0;
      }
      else {
        if ((DAT_009a4124 <= f_0) ||
           ((((*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) != 2 ||
              (*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) !=
               *(int *)(&DAT_009a58c4 + DAT_009a412c * 4))) ||
             (*(int *)(&DAT_009a6224 + DAT_009a4130 * 4) != 1)) ||
            (*(int *)(&DAT_009a6224 + DAT_009a4130 * 4) !=
             *(int *)(&DAT_009a6224 + DAT_009a412c * 4))))) {
          if (((f_0 <= DAT_009a4124) || (*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) != 1)) ||
             ((*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) != 1 ||
              (*(int *)(&DAT_009a6224 + DAT_009a412c * 4) != 2 &&
               *(int *)(&DAT_009a6224 + DAT_009a4130 * 4) != 2)))) {
            if ((((DAT_009a4124 <= f_0) || (*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) != 2)) ||
                (*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) != 2)) ||
               (*(int *)(&DAT_009a6224 + DAT_009a412c * 4) != 1 &&
                *(int *)(&DAT_009a6224 + DAT_009a4130 * 4) != 1)) {
              if ((((DAT_009a4124 <= f_0) || (*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) != 1)) ||
                  (*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) != 1)) ||
                 (*(int *)(&DAT_009a6224 + DAT_009a412c * 4) != 2 &&
                  *(int *)(&DAT_009a6224 + DAT_009a4130 * 4) != 2)) {
                if (((f_0 <= DAT_009a4124) || (*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) != 2)) ||
                   ((*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) != 2 ||
                    (*(int *)(&DAT_009a6224 + DAT_009a4130 * 4) != 1 &&
                     *(int *)(&DAT_009a6224 + DAT_009a412c * 4) != 1)))) {
                  if (((f_0 <= DAT_009a4124) || (*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) != 1))
                     || (*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) != 2)) {
                    if (((f_0 <= DAT_009a4124) || (*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) != 2))
                       || (*(int *)(&DAT_009a58c4 + DAT_009a412c * 4) != 1)) {
                      if ((*(int *)(&DAT_009a6224 + DAT_009a4130 * 4) !=
                           *(int *)(&DAT_009a6224 + DAT_009a412c * 4)) ||
                         (*(int *)(&DAT_009a58c4 + DAT_009a4130 * 4) !=
                          *(int *)(&DAT_009a58c4 + DAT_009a412c * 4))) goto LAB_0055e2e3;
                      *(undefined4 *)(puVar9 + -0x18) = 0;
                      goto LAB_0055e099;
                    }
                    (&ITEM_P4)[DAT_009a4128] =
                         (float)*(int *)(&DAT_009a5be4 + DAT_009a4130 * 4) + f_2;
                    (&ITEM_P5)[DAT_009a4128] = *(float *)(&DAT_009a5284 + DAT_009a412c * 4) + f_1;
                    *(undefined4 *)(puVar9 + -0x1c) = 0;
                  }
                  else {
                    (&ITEM_P4)[DAT_009a4128] = *(float *)(&DAT_009a5284 + DAT_009a4130 * 4) + f_1;
                    (&ITEM_P5)[DAT_009a4128] =
                         (float)*(int *)(&DAT_009a5be4 + DAT_009a412c * 4) + f_2;
                  }
                }
                else {
                  DAT_009a4134 = f_2;
                  if ((f_8 <= (float)(&ITEM_LEN)[DAT_009a4128]) &&
                     (*(float *)(&ITEM_P8 + DAT_009a4128 * 4) == f_m2 ||
                      *(float *)(&ITEM_P8 + DAT_009a4128 * 4) == f_m3)) {
                    DAT_009a4134 = f_0;
                  }
                  (&ITEM_P4)[DAT_009a4128] =
                       (float)*(int *)(&DAT_009a5be4 + DAT_009a4130 * 4) + DAT_009a4134;
                  (&ITEM_P5)[DAT_009a4128] =
                       (float)*(int *)(&DAT_009a5be4 + DAT_009a412c * 4) + DAT_009a4134;
                  *(undefined4 *)(puVar9 + -0x20) = 0;
                }
              }
              else {
                DAT_009a4134 = f_2;
                if ((f_8 <= (float)(&ITEM_LEN)[DAT_009a4128]) &&
                   (*(float *)(&ITEM_P8 + DAT_009a4128 * 4) == f_m2 ||
                    *(float *)(&ITEM_P8 + DAT_009a4128 * 4) == f_m3)) {
                  DAT_009a4134 = f_0;
                }
                (&ITEM_P4)[DAT_009a4128] =
                     (float)*(int *)(&DAT_009a5be4 + DAT_009a4130 * 4) - DAT_009a4134;
                (&ITEM_P5)[DAT_009a4128] =
                     (float)*(int *)(&DAT_009a5be4 + DAT_009a412c * 4) - DAT_009a4134;
                *(undefined4 *)(puVar9 + -0x24) = 0;
              }
              goto LAB_0055e028;
            }
            *(undefined4 *)(puVar9 + -0x28) = 0;
          }
LAB_0055e099:
          if (_DAT_009a410c == f_2) {
            (&ITEM_P4)[DAT_009a4128] =
                 (float)(&ITEM_P4)[DAT_009a4128] + *(float *)(DAT_009a4140 * 4 + 0x9a4604);
            (&ITEM_P5)[DAT_009a4128] =
                 (float)(&ITEM_P5)[DAT_009a4128] + *(float *)(DAT_009a4140 * 4 + 0x9a4604);
          }
          else {
            (&ITEM_P4)[DAT_009a4128] = (float)*(int *)(&DAT_009a5be4 + DAT_009a4130 * 4);
            (&ITEM_P5)[DAT_009a4128] = (&ITEM_P4)[DAT_009a4128];
          }
          goto LAB_0055e2e3;
        }
        (&ITEM_P4)[DAT_009a4128] = *(float *)(&DAT_009a5284 + DAT_009a4130 * 4) - f_1;
        (&ITEM_P5)[DAT_009a4128] = *(float *)(&DAT_009a5284 + DAT_009a412c * 4) - f_1;
        *(undefined4 *)(puVar9 + -0x2c) = 0;
      }
LAB_0055e028:
      fVar8 = (float10)DAT_009a4124;
      DAT_009a4124 = (float)-fVar8;
      *(float *)(&ITEM_P7 + DAT_009a4128 * 4) = DAT_009a4124;
    }
LAB_0055e2e3:
    DAT_009a4134 = f_1;
    if (DAT_009a4124 < f_0) {
      DAT_009a4134 = f_m1;
    }
    if (DAT_009a4120 == 0) {
      *(undefined4 *)(puVar9 + -0x14) = 0;
    }
    else if (((f_8 <= (float)(&ITEM_LEN)[DAT_009a4128]) &&
             ((float)(&ITEM_P4)[DAT_009a4128] == (float)(&ITEM_P5)[DAT_009a4128])) &&
            (*(float *)(&ITEM_P8 + DAT_009a4128 * 4) == f_m3 ||
             *(float *)(&ITEM_P8 + DAT_009a4128 * 4) == f_m2)) {
      fVar8 = (float10)DAT_009a4134;
      DAT_009a4134 = (float)-fVar8;
    }
    ffree(fVar8);
    fVar8 = (float10)anint(puVar9,0x55e3de);
    *(int *)(puVar9 + -0xd8) = (int)ROUND(fVar8);
    DAT_009a4108 = *(int *)(puVar9 + -0xd8);
    if (((DAT_009a4108 % 2 == 0) || (DAT_009a4108 < 3)) || (0xb < DAT_009a4108)) {
      *(undefined4 *)(puVar9 + -0x10) = 0;
    }
    else {
      (&ITEM_P4)[DAT_009a4128] = DAT_009a4134 + (float)(&ITEM_P4)[DAT_009a4128];
    }
    ffree(extraout_ST1);
    fVar8 = (float10)anint(puVar9,0x55e465);
    *(int *)(puVar9 + -0xd8) = (int)ROUND(fVar8);
    DAT_009a4108 = *(int *)(puVar9 + -0xd8);
    if (((DAT_009a4108 % 2 == 0) || (DAT_009a4108 < 3)) || (0xb < DAT_009a4108)) {
      *(undefined4 *)(puVar9 + -0xc) = 0;
    }
    else {
      (&ITEM_P5)[DAT_009a4128] = DAT_009a4134 + (float)(&ITEM_P5)[DAT_009a4128];
    }
    *(undefined4 *)(puVar9 + -8) = 0;
    *(undefined4 *)(puVar9 + -4) = 0;
    DAT_009a4140 = DAT_009a4140 + 1;
    *(int *)(puVar9 + -0x74) = *(int *)(puVar9 + -0x74) + -1;
    iVar4 = *(int *)(puVar9 + -0x74);
    fVar8 = extraout_ST1_00;
  } while( true );
}


