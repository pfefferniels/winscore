// FUN_004d6318 @ 004d6318 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d6318(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EDX;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar6;
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
  unkbyte10 extraout_ST0_16;
  unkbyte10 extraout_ST0_17;
  unkbyte10 extraout_ST0_18;
  unkbyte10 extraout_ST0_19;
  unkbyte10 extraout_ST0_20;
  unkbyte10 extraout_ST0_21;
  unkbyte10 extraout_ST0_22;
  unkbyte10 extraout_ST0_23;
  unkbyte10 extraout_ST0_24;
  unkbyte10 extraout_ST0_25;
  unkbyte10 extraout_ST0_26;
  unkbyte10 extraout_ST0_27;
  unkbyte10 extraout_ST0_28;
  unkbyte10 extraout_ST0_29;
  unkbyte10 extraout_ST0_30;
  unkbyte10 extraout_ST0_31;
  unkbyte10 extraout_ST0_32;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  
  puVar3 = &stack0xfffffffc;
  DAT_01c60caa = *(float *)(param_2 + 4);
  DAT_01c60cae = *(float *)(param_2 + 8);
  _DAT_008a0488 = *(undefined4 *)(param_1 + 8);
  DAT_0078b47c = *(int *)(param_1 + 0x20);
  _DAT_0078cb00 = *(int *)(param_1 + 0x24);
  DAT_0078cba6 = *(int *)(param_1 + 4);
  if (DAT_0078cba6 != 0) {
    puVar3 = &stack0xfffffffc;
    in_ST0 = FUN_005f33c9(&stack0xfffffffc,0x4d6393);
  }
  DAT_0078cbb2 = *(int *)(*(int *)(puVar3 + 8) + 0xc);
  puVar4 = &DAT_01a14984;
  puVar5 = &DAT_0078cb22;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  DAT_0078b6b0 = **(int **)(puVar3 + 8);
  DAT_0078cba2 = *(int *)(*(int *)(puVar3 + 8) + 0x1c);
  DAT_0078cbaa = *(int *)(*(int *)(puVar3 + 8) + 0x28);
  DAT_01aae2f0 = **(float **)(puVar3 + 0xc);
  _DAT_0078b480 = f_4000 / (float)DAT_0078b47c;
  _DAT_008a0484 = *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0xc);
  _DAT_008a0480 = *(undefined4 *)(*(int *)(puVar3 + 0xc) + 0x10);
  ffree(in_ST0);
  fVar6 = (float10)anint(puVar3,0x4d6429);
  *(int *)(puVar3 + -0x104) = (int)ROUND(fVar6);
  DAT_01aae2d0 = *(int *)(puVar3 + -0x104) + 0x318;
  ffree(extraout_ST1);
  fVar6 = (float10)anint(puVar3,0x4d6463);
  *(int *)(puVar3 + -0x104) = (int)ROUND(fVar6);
  DAT_01aae2d4 = *(int *)(puVar3 + -0x104) + 0xd;
  Var7 = extraout_ST1_00;
  if (DAT_0078cbb2 == 1) {
    ffree(extraout_ST1_00);
    Var7 = thunk_FUN_00571b78(&DAT_0078cb22,0x80,&DAT_00765790,3);
    ffree(Var7);
    Var7 = thunk_FUN_0049731a(&DAT_0078cb22,0x80,&DAT_008a047c);
  }
  if (DAT_008a047c == -2) {
    *(undefined4 *)(puVar3 + -0xe0) = 0;
    goto LAB_004d7dab;
  }
  _DAT_01c60cb2 = DAT_01aae2f0;
  _DAT_01aae2c4 = 1;
  FUN_005f33c9(puVar3,0x4d6514);
  Var7 = FUN_005f34d1(puVar3,0x4d652f);
  DAT_01aae360 = 0;
  DAT_01aae364 = 0;
  _DAT_01aae42c = 0;
  _DAT_01aae200 = 0;
  DAT_00791448 = 0;
  DAT_0078d8a0 = 0xffffffff;
  DAT_0078b484 = 1;
  _DAT_01aae320 = f_6_6667;
  DAT_008a0478 = 0;
  if (*(int *)(*(int *)(puVar3 + 8) + 0x10) == 0) {
    *(undefined4 *)(puVar3 + -0xdc) = 0;
LAB_004d65f2:
    DAT_008a0474 = 0;
    if (DAT_008a0478 != 0) goto LAB_004d6612;
    *(undefined4 *)(puVar3 + -0xd4) = 0;
LAB_004d66c2:
    *(undefined4 *)(puVar3 + -0xcc) = 0;
    DAT_01aae2f0 = _DAT_01c60cb2 * f_0_018;
    *(undefined2 *)(puVar3 + -0x108) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
    *(int *)(puVar3 + -0x104) = (int)ROUND((float)_DAT_0078cb00);
    _DAT_01c60ca6 = *(undefined4 *)(puVar3 + -0x104);
    _DAT_0078b480 = f_4000 / (float)DAT_0078b47c + f_0_01;
    _DAT_01aae320 = _DAT_0078b480 / _DAT_01c60cb2;
    DAT_01aae324 = _DAT_01aae320 * (float)_DAT_0078cb00;
    _DAT_01aae328 = 0;
    *(undefined2 *)(puVar3 + -0x108) = *(undefined2 *)(puVar3 + -0x108);
    *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
    *(int *)(puVar3 + -0x104) = (int)ROUND((DAT_01c60cae * f_4000) / _DAT_01c60cb2 + f_24000);
    DAT_01aae2f8 = *(int *)(puVar3 + -0x104);
    *(undefined2 *)(puVar3 + -0x108) = *(undefined2 *)(puVar3 + -0x108);
    *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
    *(int *)(puVar3 + -0x104) = (int)ROUND((DAT_01c60caa * f_4000) / _DAT_01c60cb2);
    in_FPUControlWord = *(undefined2 *)(puVar3 + -0x108);
    DAT_01aae2f4 = *(int *)(puVar3 + -0x104);
    if ((DAT_0078cbb2 != 0) && (DAT_0078cbb2 != 2)) {
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(Var7);
      Var7 = FUN_005f7950(puVar3 + -0x100,0x18,0x784ff00,&DAT_00765758,0);
      *(undefined4 *)(puVar3 + -0x100) = 0;
      *(undefined4 *)(puVar3 + -0x118) = 0x80;
      *(int **)(puVar3 + -0x114) = &DAT_0078cb22;
      *(undefined4 *)(puVar3 + -0x110) = 7;
      *(char **)(puVar3 + -0x10c) = "unknown";
      *(undefined4 *)(puVar3 + -0x108) = 0x200;
      *(undefined4 *)(puVar3 + -0x104) = 2;
      ffree(Var7);
      uVar1 = FUN_005f6540(puVar3 + -0x100,0x18,0x784ff01,&DAT_0076573c,puVar3 + -0x118);
      *(undefined4 *)(puVar3 + -0xc0) = uVar1;
      Var7 = extraout_ST0;
      if (*(int *)(puVar3 + -0xc0) != 0) goto LAB_004d7c14;
      DAT_0078dcb0 = 0;
      *(undefined4 *)(puVar3 + -0x100) = 0;
      *(undefined4 **)(puVar3 + -0x108) = &DAT_0078dc88;
      ffree(extraout_ST0);
      iVar2 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_00765738,puVar3 + -0x108,
                           &DAT_00793f20);
      *(int *)(puVar3 + -0xbc) = iVar2;
      Var7 = extraout_ST0_00;
      if (iVar2 == 0) {
        *(undefined4 *)(puVar3 + -0x108) = 0x80;
        *(undefined4 **)(puVar3 + -0x104) = &DAT_0078b510;
        ffree(extraout_ST0_00);
        uVar1 = FUN_005fc980(puVar3 + -0x100,&DAT_00765734,puVar3 + -0x108);
        *(undefined4 *)(puVar3 + -0xbc) = uVar1;
        Var7 = extraout_ST0_01;
      }
      if (*(int *)(puVar3 + -0xbc) != 0) goto LAB_004d7c14;
      FUN_005f33c9(puVar3,0x4d69ad);
      fVar6 = (float10)FUN_005f34d1(puVar3,0x4d69c8);
      if (_DAT_01c60cb2 != f_1) {
        *(int *)(puVar3 + -0x104) = DAT_01be6cac - DAT_01be6ca4;
        _DAT_008a0470 = (float)*(int *)(puVar3 + -0x104) * _DAT_01c60cb2;
        *(undefined2 *)(puVar3 + -0x108) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
        *(int *)(puVar3 + -0x104) = (int)ROUND((float)DAT_01be6ca4 + _DAT_008a0470);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x108);
        DAT_01be6cac = *(int *)(puVar3 + -0x104);
      }
      if (DAT_01c60caa != f_0_5) {
        _DAT_008a046c = (DAT_01c60caa - f_0_5) * f_4000;
        *(undefined2 *)(puVar3 + -0x108) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
        *(int *)(puVar3 + -0x104) = (int)ROUND((float)DAT_01be6ca4 + _DAT_008a046c);
        DAT_01be6ca4 = *(int *)(puVar3 + -0x104);
        *(undefined2 *)(puVar3 + -0x108) = *(undefined2 *)(puVar3 + -0x108);
        *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
        *(int *)(puVar3 + -0x104) = (int)ROUND((float)DAT_01be6cac + _DAT_008a046c);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x108);
        DAT_01be6cac = *(int *)(puVar3 + -0x104);
      }
      *(int *)(puVar3 + -0x104) = (DAT_01be6ca4 + DAT_01aae2f4) - VIEW_DX;
      _DAT_008a0468 = (float)*(int *)(puVar3 + -0x104) * f_0_018;
      *(int *)(puVar3 + -0x104) = DAT_01be6ca8 + DAT_01aae2f8;
      _DAT_008a0464 = (float)*(int *)(puVar3 + -0x104) * DAT_01aae2f0;
      *(int *)(puVar3 + -0x104) = (DAT_01be6cac + DAT_01aae2f4) - VIEW_DX;
      _DAT_008a0460 = (float)*(int *)(puVar3 + -0x104) * f_0_018;
      *(int *)(puVar3 + -0x104) = DAT_01be6cb0 + DAT_01aae2f8;
      _DAT_008a045c = (float)*(int *)(puVar3 + -0x104) * DAT_01aae2f0;
      *(undefined2 *)(puVar3 + -0x108) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
      *(int *)(puVar3 + -0x104) = (int)ROUND(_DAT_008a0468);
      DAT_008a0458 = *(int *)(puVar3 + -0x104);
      *(undefined2 *)(puVar3 + -0x108) = *(undefined2 *)(puVar3 + -0x108);
      *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
      *(int *)(puVar3 + -0x104) = (int)ROUND(_DAT_008a0464);
      DAT_008a0454 = *(int *)(puVar3 + -0x104);
      *(undefined2 *)(puVar3 + -0x108) = *(undefined2 *)(puVar3 + -0x108);
      *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
      *(int *)(puVar3 + -0x104) = (int)ROUND(_DAT_008a0460);
      DAT_008a0450 = *(int *)(puVar3 + -0x104);
      *(undefined2 *)(puVar3 + -0x108) = *(undefined2 *)(puVar3 + -0x108);
      *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
      *(int *)(puVar3 + -0x104) = (int)ROUND(_DAT_008a045c);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x108);
      DAT_008a044c = *(int *)(puVar3 + -0x104);
      if (DAT_008a0454 < 9) {
        fVar6 = -((float10)_DAT_008a0464 / (float10)f_72) * (float10)f_4000;
        *(undefined2 *)(puVar3 + -0x108) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
        *(int *)(puVar3 + -0x104) = (int)ROUND((float10)DAT_01aae2f8 + fVar6);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x108);
        DAT_01aae2f8 = *(int *)(puVar3 + -0x104);
        DAT_008a044c = (DAT_008a044c - DAT_008a0454) + 9;
        DAT_008a0454 = 9;
      }
      if (DAT_0078b6b0 != 0) {
        DAT_008a0448 = DAT_008a0458 + -6;
        DAT_008a0444 = (DAT_008a0450 + DAT_008a0448) - DAT_008a0458;
        DAT_008a0440 = 0x264 - DAT_008a0454;
        DAT_008a043c = DAT_008a0440 - (DAT_008a044c - DAT_008a0454);
        DAT_008a044c = DAT_008a0444;
        DAT_008a0450 = DAT_008a0440;
        DAT_008a0454 = DAT_008a0448;
        DAT_008a0458 = DAT_008a043c;
      }
      ffree(fVar6);
      Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_007656f8,&DAT_007656fc,"(1i5)",5,
                                &DAT_008a0458);
      ffree(Var7);
      Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_007656f0,&DAT_007656f4,"(1i5)",5,
                                &DAT_008a0454);
      ffree(Var7);
      Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_007656e8,&DAT_007656ec,"(1i5)",5,
                                &DAT_008a0450);
      ffree(Var7);
      Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_007656e0,&DAT_007656e4,"(1i5)",5,
                                &DAT_008a044c);
      *(undefined4 *)(puVar3 + -0x100) = 0;
      *(undefined4 *)(puVar3 + -0x108) = 0x2a;
      *(undefined2 **)(puVar3 + -0x104) = &DAT_020b8ea0;
      ffree(Var7);
      Var7 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff00,&DAT_00765734,puVar3 + -0x108,&DAT_00793fa4
                         );
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(Var7);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00793fb8);
      *(undefined4 *)(puVar3 + -0xb4) = uVar1;
      Var7 = extraout_ST0_02;
      if (*(int *)(puVar3 + -0xb4) != 0) goto LAB_004d7c14;
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(extraout_ST0_02);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00793fdc);
      *(undefined4 *)(puVar3 + -0xb0) = uVar1;
      Var7 = extraout_ST0_03;
      if (*(int *)(puVar3 + -0xb0) != 0) goto LAB_004d7c14;
      *(undefined4 *)(puVar3 + -0xac) = 0;
LAB_004d714b:
      Var7 = FUN_005f34d1(puVar3,0x4d7168);
      if (DAT_0078b6b0 == 1) {
        DAT_01c60ca0 = i_1635020658;
        DAT_01c60ca4 = _DAT_007656d0;
      }
      DAT_00791444 = 0xffffffff;
      if (DAT_0078cbb2 == 1) {
        *(undefined4 *)(puVar3 + -0x100) = 0;
        ffree(Var7);
        uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00794040);
        *(undefined4 *)(puVar3 + -0x8c) = uVar1;
        Var7 = extraout_ST0_07;
        if (*(int *)(puVar3 + -0x8c) != 0) goto LAB_004d7c14;
      }
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(Var7);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00794074);
      *(undefined4 *)(puVar3 + -0x88) = uVar1;
      Var7 = extraout_ST0_08;
      if (*(int *)(puVar3 + -0x88) != 0) goto LAB_004d7c14;
      if ((DAT_0078cbb2 == 0) || (DAT_0078cbb2 == 2)) {
        *(undefined4 *)(puVar3 + -0x100) = 0;
        ffree(extraout_ST0_08);
        uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00794088);
        *(undefined4 *)(puVar3 + -0x84) = uVar1;
        Var7 = extraout_ST0_09;
        if (*(int *)(puVar3 + -0x84) != 0) goto LAB_004d7c14;
      }
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(Var7);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_007940bc);
      *(undefined4 *)(puVar3 + -0x80) = uVar1;
      Var7 = extraout_ST0_10;
      if (*(int *)(puVar3 + -0x80) != 0) goto LAB_004d7c14;
      if (DAT_0078b484 != 0) {
        *(undefined4 *)(puVar3 + -0x100) = 0;
        ffree(extraout_ST0_10);
        uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_007940f0);
        *(undefined4 *)(puVar3 + -0x7c) = uVar1;
        Var7 = extraout_ST0_11;
        if (*(int *)(puVar3 + -0x7c) != 0) goto LAB_004d7c14;
      }
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(Var7);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00794234);
      *(undefined4 *)(puVar3 + -0x78) = uVar1;
      Var7 = extraout_ST0_12;
      if (*(int *)(puVar3 + -0x78) != 0) goto LAB_004d7c14;
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(extraout_ST0_12);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00794274);
      *(undefined4 *)(puVar3 + -0x74) = uVar1;
      Var7 = extraout_ST0_13;
      if (*(int *)(puVar3 + -0x74) != 0) goto LAB_004d7c14;
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(extraout_ST0_13);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_007942d4);
      *(undefined4 *)(puVar3 + -0x70) = uVar1;
      Var7 = extraout_ST0_14;
      if (*(int *)(puVar3 + -0x70) != 0) goto LAB_004d7c14;
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(extraout_ST0_14);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_0079430c);
      *(undefined4 *)(puVar3 + -0x6c) = uVar1;
      Var7 = extraout_ST0_15;
      if (*(int *)(puVar3 + -0x6c) != 0) goto LAB_004d7c14;
      if (DAT_0078cbaa == 2) {
        *(undefined4 *)(puVar3 + -0x68) = 0;
        *(undefined4 *)(puVar3 + -0x100) = 0;
        ffree(extraout_ST0_15);
        uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_007943b0);
        *(undefined4 *)(puVar3 + -0x48) = uVar1;
        Var7 = extraout_ST0_16;
        if (*(int *)(puVar3 + -0x48) != 0) goto LAB_004d7c14;
        goto LAB_004d7720;
      }
      if (DAT_0078cbaa == 3) {
        *(undefined4 *)(puVar3 + -100) = 0;
LAB_004d7543:
        DAT_008a0430 = 0x318;
        DAT_008a042c = 0x4c8;
        DAT_0078cbb6 = 1;
LAB_004d7634:
        if ((DAT_0078cbb2 == 0) || (DAT_0078cbb2 == 2)) {
          *(undefined4 *)(puVar3 + -0x100) = 0;
          *(int **)(puVar3 + -0x108) = &DAT_008a0430;
          ffree(extraout_ST0_15);
          iVar2 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_00765738,puVar3 + -0x108,
                               &DAT_0079434c);
          *(int *)(puVar3 + -0x50) = iVar2;
          Var7 = extraout_ST0_17;
          if (iVar2 == 0) {
            *(int **)(puVar3 + -0x108) = &DAT_008a042c;
            ffree(extraout_ST0_17);
            iVar2 = FUN_005fc980(puVar3 + -0x100,&DAT_00765738,puVar3 + -0x108);
            *(int *)(puVar3 + -0x50) = iVar2;
            Var7 = extraout_ST0_18;
            if (iVar2 == 0) {
              *(int **)(puVar3 + -0x108) = &DAT_0078cbb6;
              ffree(extraout_ST0_18);
              uVar1 = FUN_005fc980(puVar3 + -0x100,&DAT_007656bc,puVar3 + -0x108);
              *(undefined4 *)(puVar3 + -0x50) = uVar1;
              Var7 = extraout_ST0_19;
            }
          }
          if (*(int *)(puVar3 + -0x50) != 0) goto LAB_004d7c14;
        }
        *(undefined4 *)(puVar3 + -0x4c) = 0;
      }
      else if (((DAT_0078cbb6 == 0) || (_DAT_0078caf0 != f_8_5)) || (_DAT_0078caf4 != f_11)) {
        if ((f_0 <= _DAT_0078caf0) && (f_0 <= _DAT_0078caf4)) {
          *(undefined2 *)(puVar3 + -0x108) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
          *(int *)(puVar3 + -0x104) = (int)ROUND(_DAT_0078caf0 * f_72);
          DAT_008a0430 = *(int *)(puVar3 + -0x104);
          *(undefined2 *)(puVar3 + -0x108) = *(undefined2 *)(puVar3 + -0x108);
          *(ushort *)(puVar3 + -0x106) = (ushort)*(undefined4 *)(puVar3 + -0x108) | 0xc00;
          *(int *)(puVar3 + -0x104) = (int)ROUND(_DAT_0078caf4 * f_72);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x108);
          DAT_008a042c = *(int *)(puVar3 + -0x104);
          *(undefined4 *)(puVar3 + -0x58) = 0;
          goto LAB_004d7634;
        }
        *(undefined4 *)(puVar3 + -0x5c) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x60) = 0;
        DAT_0078b4e4 = 0;
        if ((DAT_0078b6b0 == 0) && (0x251 < DAT_008a0430 || 0x305 < DAT_008a042c))
        goto LAB_004d7543;
        *(undefined4 *)(puVar3 + -0x54) = 0;
      }
LAB_004d7720:
      if (DAT_0078cba6 == 0) {
        *(undefined4 *)(puVar3 + -0x44) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x100) = 0;
        ffree(Var7);
        uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_007943d8);
        *(undefined4 *)(puVar3 + -0x40) = uVar1;
        Var7 = extraout_ST0_20;
        if (*(int *)(puVar3 + -0x40) != 0) goto LAB_004d7c14;
        ffree(extraout_ST0_20);
        Var7 = thunk_FUN_004cf214();
        if (DAT_0078b4e0 == 0x42) {
          *(undefined4 *)(puVar3 + -0x3c) = 0;
          goto LAB_004d7905;
        }
      }
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(Var7);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_007943fc);
      *(undefined4 *)(puVar3 + -0x38) = uVar1;
      Var7 = extraout_ST0_21;
      if (*(int *)(puVar3 + -0x38) != 0) goto LAB_004d7c14;
      if (DAT_0078b6b0 == 1) {
        *(undefined4 *)(puVar3 + -0x100) = 0;
        ffree(extraout_ST0_21);
        uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_0079441c);
        *(undefined4 *)(puVar3 + -0x34) = uVar1;
        Var7 = extraout_ST0_22;
        if (*(int *)(puVar3 + -0x34) != 0) goto LAB_004d7c14;
      }
      *(undefined4 *)(puVar3 + -0x100) = 0;
      *(float **)(puVar3 + -0x108) = &DAT_01aae2f0;
      ffree(Var7);
      iVar2 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656b8,puVar3 + -0x108,
                           &DAT_0079443c);
      *(int *)(puVar3 + -0x30) = iVar2;
      Var7 = extraout_ST0_23;
      if (iVar2 == 0) {
        *(float **)(puVar3 + -0x108) = &DAT_01aae324;
        ffree(extraout_ST0_23);
        uVar1 = FUN_005fc980(puVar3 + -0x100,&DAT_007656b4,puVar3 + -0x108);
        *(undefined4 *)(puVar3 + -0x30) = uVar1;
        Var7 = extraout_ST0_24;
      }
      if (*(int *)(puVar3 + -0x30) != 0) goto LAB_004d7c14;
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(Var7);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00794480);
      *(undefined4 *)(puVar3 + -0x2c) = uVar1;
      Var7 = extraout_ST0_25;
      if (*(int *)(puVar3 + -0x2c) != 0) goto LAB_004d7c14;
LAB_004d7905:
      do {
        DAT_01eae1b0 = 0;
        DAT_0078b6bc = 0;
        _DAT_01eae1b4 = f_0;
        if (DAT_0078b4e0 == 0x42) {
          OUTPUT_MODE = 0;
          DAT_020b8ea0._0_1_ = s_PSFNAMES_TMPX_007656a4[0xc];
          *(undefined4 *)(puVar3 + -0x28) = 0;
          goto LAB_004d7d99;
        }
        if (DAT_0078cbb2 == 1) {
          *(undefined4 *)(puVar3 + -0x108) = DAT_0078b464;
          *(undefined4 *)(puVar3 + -0x104) = DAT_0078b468;
          *(undefined4 *)(puVar3 + -0x100) = 0;
          FUN_005f33c9(puVar3,0x4d799d);
          Var7 = FUN_005f33c9(puVar3,0x4d79b9);
          *(undefined1 **)(puVar3 + -0x11c) = puVar3 + -0x138;
          *(undefined4 *)(puVar3 + -0x120) = 0x14;
          *(undefined4 *)(puVar3 + -0x118) = 7;
          *(undefined4 *)(puVar3 + -0x114) = extraout_EDX;
          *(undefined4 *)(puVar3 + -0x110) = 0x200;
          *(undefined4 *)(puVar3 + -0x10c) = 2;
          ffree(Var7);
          uVar1 = FUN_005f6540(puVar3 + -0x100,0x1a,0x784ff01,&DAT_0076573c,puVar3 + -0x120);
          *(undefined4 *)(puVar3 + -0x24) = uVar1;
          Var7 = extraout_ST0_26;
          if (*(int *)(puVar3 + -0x24) == 0) goto LAB_004d7a4a;
          ffree(extraout_ST0_26);
          Var7 = thunk_FUN_0054d831("Error opening temp. font name file.",0x23);
        }
        else {
LAB_004d7a4a:
          *(undefined4 *)(puVar3 + -0x20) = 0;
        }
        OUTPUT_MODE = -1;
        *(undefined4 *)(puVar3 + -0x100) = 0;
        *(int **)(puVar3 + -0x108) = &DAT_01aae2f4;
        ffree(Var7);
        iVar2 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_00765738,puVar3 + -0x108,
                             &DAT_007944b4);
        *(int *)(puVar3 + -0x1c) = iVar2;
        Var7 = extraout_ST0_27;
        if (iVar2 == 0) {
          *(int **)(puVar3 + -0x108) = &DAT_01aae2f8;
          ffree(extraout_ST0_27);
          uVar1 = FUN_005fc980(puVar3 + -0x100,&DAT_007656bc,puVar3 + -0x108);
          *(undefined4 *)(puVar3 + -0x1c) = uVar1;
          Var7 = extraout_ST0_28;
        }
        if (*(int *)(puVar3 + -0x1c) == 0) {
          *(undefined4 *)(puVar3 + -0x100) = 0;
          ffree(Var7);
          uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_007944f8);
          *(undefined4 *)(puVar3 + -0x18) = uVar1;
          Var7 = extraout_ST0_29;
          if (*(int *)(puVar3 + -0x18) == 0) {
            *(undefined4 *)(puVar3 + -0x100) = 0;
            ffree(extraout_ST0_29);
            uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00794518);
            *(undefined4 *)(puVar3 + -0x14) = uVar1;
            Var7 = extraout_ST0_30;
            if (*(int *)(puVar3 + -0x14) == 0) {
              if (DAT_0078cba2 != 0) {
                *(undefined4 *)(puVar3 + -0x100) = 0;
                ffree(extraout_ST0_30);
                uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_0079452c);
                *(undefined4 *)(puVar3 + -0x10) = uVar1;
                Var7 = extraout_ST0_31;
                if (*(int *)(puVar3 + -0x10) != 0) goto LAB_004d7c14;
              }
              if (DAT_0078cbae == 0) goto LAB_004d7c2a;
              *(undefined4 *)(puVar3 + -0x100) = 0;
              ffree(Var7);
              uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00794550);
              *(undefined4 *)(puVar3 + -0xc) = uVar1;
              Var7 = extraout_ST0_32;
              if (*(int *)(puVar3 + -0xc) == 0) goto LAB_004d7c2a;
            }
          }
        }
LAB_004d7c14:
        ffree(Var7);
        Var7 = thunk_FUN_004cf1c2();
        *(undefined4 *)(puVar3 + -0xa8) = 0;
      } while( true );
    }
    *(undefined4 *)(puVar3 + -200) = 0;
    DAT_008a0438 = DAT_0078b4e0;
    DAT_0078dcb0 = 1;
    DAT_0078dcb4 = 1;
    puVar3[-0x101] = 0x31;
    DAT_00794588 = CONCAT13(puVar3[-0x101],(undefined3)DAT_00794588);
    DAT_0078dcc8 = DAT_00794588;
    *(undefined4 *)(puVar3 + -0xa4) = 0;
    *(undefined4 *)(puVar3 + -0x100) = 0;
    *(undefined4 *)(puVar3 + -0x118) = 4;
    *(undefined4 **)(puVar3 + -0x114) = &DAT_0078dcc8;
    *(undefined4 *)(puVar3 + -0x110) = 3;
    *(undefined **)(puVar3 + -0x10c) = &DAT_007656d8;
    *(undefined4 *)(puVar3 + -0x108) = 0x100;
    *(undefined4 *)(puVar3 + -0x104) = 2;
    ffree(Var7);
    uVar1 = FUN_005f6540(puVar3 + -0x100,0x18,0x784ff03,&DAT_0076573c,puVar3 + -0x118);
    *(undefined4 *)(puVar3 + -0xa0) = uVar1;
    _DAT_008a0434 = *(undefined4 *)(puVar3 + -0xa0);
    if (*(int *)(puVar3 + -0xa0) == 0) {
      *(undefined4 *)(puVar3 + -0x100) = 0;
      ffree(extraout_ST0_04);
      uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_00793ff8);
      *(undefined4 *)(puVar3 + -0x9c) = uVar1;
      if (*(int *)(puVar3 + -0x9c) == 0) {
        DAT_0078b4e0 = DAT_008a0438;
        *(undefined4 *)(puVar3 + -0x100) = 0;
        ffree(extraout_ST0_05);
        uVar1 = FUN_005fc330(puVar3 + -0x100,0x18,0x784ff01,&DAT_007656dc,0,&DAT_0079401c);
        *(undefined4 *)(puVar3 + -0x98) = uVar1;
        Var7 = extraout_ST0_06;
        if (*(int *)(puVar3 + -0x98) != 0) goto LAB_004d7c14;
        *(undefined4 *)(puVar3 + -0x94) = 0;
        goto LAB_004d714b;
      }
    }
    FUN_005f33c9(puVar3,0x4d7d4d);
    Var7 = FUN_005f34d1(puVar3,0x4d7d68);
    DAT_020b8ebc = DAT_0078dcc8;
    ffree(Var7);
    Var7 = thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
    *(undefined4 *)(puVar3 + -0x90) = 0;
    goto LAB_004d7d99;
  }
  DAT_008a0478 = *(int *)(*(int *)(puVar3 + 8) + 0x10);
  ffree(Var7);
  Var7 = thunk_FUN_00537938(&DAT_008a0478);
  if (DAT_008a0478 != 0) {
    ffree(Var7);
    Var7 = thunk_FUN_0054c83c(&DAT_0078cb22,0x80,&DAT_00765784);
    goto LAB_004d65f2;
  }
  *(undefined4 *)(puVar3 + -0xd8) = 0;
LAB_004d7d99:
  DAT_00791448 = 1;
  ffree(Var7);
  Var7 = thunk_FUN_00512009();
LAB_004d7dab:
  ffree(Var7);
  return;
LAB_004d7c2a:
  ffree(Var7);
  Var7 = thunk_FUN_00533a88();
  _DAT_020b8e40 = 0;
  _DAT_0078dd5c = 1;
  ffree(Var7);
  Var7 = draw_items();
  _DAT_0078dd5c = 0;
  if (DAT_0078cb22 == 0x3154504c) {
    ffree(Var7);
    Var7 = thunk_FUN_0054946a("Printing to LPT1.",0x12);
  }
  else {
    FUN_005f33c9(puVar3,0x4d7c82);
    Var7 = FUN_005f34d1(puVar3,0x4d7c9d);
    puVar4 = &DAT_0078cb22;
    puVar5 = &DAT_020b90b3;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    ffree(Var7);
    Var7 = thunk_FUN_0054946a(&DAT_020b90a0,0x200);
  }
  if (DAT_008a0478 == 0) {
    *(undefined4 *)(puVar3 + -8) = 0;
    goto LAB_004d7d99;
  }
  DAT_008a0478 = DAT_008a0478 + -1;
  ffree(Var7);
  Var7 = thunk_FUN_00512009();
  ffree(Var7);
  Var7 = thunk_FUN_004cfb85(&DAT_0078cb22,0x80);
  if (DAT_008a0478 < 1) goto LAB_004d7d99;
  *(undefined4 *)(puVar3 + -4) = 0;
LAB_004d6612:
  DAT_008a0474 = DAT_008a0474 + 1;
  puVar4 = (undefined4 *)(&DAT_01c4eec4 + DAT_008a0474 * 0x80);
  puVar5 = &DAT_01c4cb60;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  DAT_0078b4e4 = 0x1a0a;
  ITEM_WORDS = 0;
  DAT_01c58600 = 0;
  ffree(Var7);
  Var7 = load_score();
  if (ITEM_WORDS == 0) goto code_r0x004d6669;
  ffree(Var7);
  Var7 = draw_items();
  ffree(Var7);
  Var7 = fit_view(&DAT_00765768,&DAT_01be6cb0,&DAT_01be6ca8,&DAT_01be6ca4,&DAT_01be6cac);
  goto LAB_004d66c2;
code_r0x004d6669:
  ffree(Var7);
  Var7 = thunk_FUN_0054946a("Leaving Batch Printing.",0x18);
  *(undefined4 *)(puVar3 + -0xd0) = 0;
  goto LAB_004d7d99;
}


