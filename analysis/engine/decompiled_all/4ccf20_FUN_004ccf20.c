// FUN_004ccf20 @ 004ccf20 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x004cd9d4) */
/* WARNING: Removing unreachable block (ram,0x004cd70f) */
/* WARNING: Removing unreachable block (ram,0x004cd74e) */
/* WARNING: Removing unreachable block (ram,0x004cda13) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ccf20(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_EDX;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var7;
  float10 fVar8;
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
  unkbyte10 extraout_ST0_33;
  unkbyte10 extraout_ST0_34;
  unkbyte10 extraout_ST0_35;
  unkbyte10 extraout_ST0_36;
  unkbyte10 extraout_ST0_37;
  unkbyte10 extraout_ST0_38;
  unkbyte10 extraout_ST0_39;
  unkbyte10 extraout_ST0_40;
  
  puVar4 = &stack0xfffffffc;
  DAT_0089fd90 = VIEW_DX;
  VIEW_DX = 0x960;
  DAT_01aae360 = 0;
  DAT_01aae364 = 0;
  _DAT_01aae42c = 0;
  _DAT_01aae350 = 0;
  DAT_00791448 = 0;
  DAT_0078d8a0 = 0xffffffff;
  ffree(in_ST0);
  Var7 = thunk_FUN_004d0bf5(&DAT_0089fd8c);
  if ((char)DAT_020b8ea0 != 'X') {
    if ((DAT_0089fd8c != 0) || (_DAT_020b8ea2 == 0x5350)) {
      DAT_0089fd88 = DAT_0078b4e0;
      DAT_0078b484 = 1;
      _DAT_01aae320 = f_6_6667;
      DAT_01aae360 = 0;
      DAT_0078cbb2 = 1;
      DAT_01aae300 = 0;
      if (DAT_020b8ea0._1_1_ == 'B') {
        DAT_01aae300 = 1;
        if (DAT_020b8ea2 == 'F') {
          DAT_01aae300 = 2;
        }
        ffree(Var7);
        Var7 = thunk_FUN_00537938(&DAT_01aae300);
        if ((DAT_01aae300 == 0) || ((char)DAT_020b8ea0 == '-')) goto LAB_004ceff4;
      }
      DAT_0089fd84 = 0;
      puVar1 = &stack0xfffffffc;
      if (DAT_01aae300 != 0) {
        _DAT_0089fd80 = DAT_01aae300;
        goto LAB_004cd0c3;
      }
      do {
        puVar4 = puVar1;
        DAT_0078b4e0 = DAT_0089fd88;
        if (DAT_0089fd88 != 0x42) {
          DAT_01aae2f0 = _DAT_01c60cb2 * f_0_018;
          *(undefined2 *)(puVar4 + -0x154) = in_FPUControlWord;
          *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
          *(int *)(puVar4 + -0x150) = (int)ROUND((float)_DAT_0078cb00);
          _DAT_01c60ca6 = *(undefined4 *)(puVar4 + -0x150);
          _DAT_0078b480 = f_4000 / (float)DAT_0078b47c + f_0_01;
          _DAT_01aae320 = _DAT_0078b480 / _DAT_01c60cb2;
          DAT_01aae324 = _DAT_01aae320 * (float)_DAT_0078cb00;
          _DAT_01aae328 = 0;
          *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
          *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
          *(int *)(puVar4 + -0x150) = (int)ROUND((DAT_01c60cae * f_4000) / _DAT_01c60cb2 + f_24000);
          iVar3 = *(int *)(puVar4 + -0x150);
          *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
          *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
          *(int *)(puVar4 + -0x150) = (int)ROUND((DAT_01c60caa * f_4000) / _DAT_01c60cb2);
          *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
          *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
          *(int *)(puVar4 + -0x150) =
               (int)ROUND(f_100 / _DAT_01c60cb2 + (float)*(int *)(puVar4 + -0x150));
          DAT_01aae2f4 = *(undefined4 *)(puVar4 + -0x150);
          fVar8 = (float10)iVar3;
          *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
          *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
          *(int *)(puVar4 + -0x150) = (int)ROUND((float10)f_250 / (float10)_DAT_01c60cb2 + fVar8);
          in_FPUControlWord = *(undefined2 *)(puVar4 + -0x154);
          DAT_01aae2f8 = *(undefined4 *)(puVar4 + -0x150);
          if (DAT_0078cbb2 != 0) {
            if ((DAT_0089fd84 < 2) || (DAT_01aae304 != 1)) {
              if (DAT_01aae304 == 0) {
                puVar5 = (undefined4 *)(&DAT_01c4eec4 + DAT_0089fd84 * 0x80);
                puVar6 = &DAT_0078cb22;
                for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
                  *puVar6 = *puVar5;
                  puVar5 = puVar5 + 1;
                  puVar6 = puVar6 + 1;
                }
                *(undefined4 *)(puVar4 + -0x108) = 0x80;
                DAT_01aae2c0 = 1;
                do {
                  iVar3 = FUN_00601a30(0x20);
                  if ((iVar3 != 0) || (iVar3 = FUN_005f4660(0x20), iVar3 != 0)) {
                    *(undefined4 *)(puVar4 + -0x104) = 0;
                    break;
                  }
                  DAT_01aae2c0 = DAT_01aae2c0 + 1;
                  *(int *)(puVar4 + -0x108) = *(int *)(puVar4 + -0x108) + -1;
                } while (0 < *(int *)(puVar4 + -0x108));
                FUN_005f46bc(puVar4,0x4cd7e9);
                fVar8 = (float10)FUN_005f34d1(puVar4,0x4cd7ff);
              }
              *(undefined4 *)(puVar4 + -0x14c) = 0;
              ffree(fVar8);
              Var7 = FUN_005f7950(puVar4 + -0x14c,0x18,0x784ff00,&DAT_00765194,0);
              *(undefined4 *)(puVar4 + -0x14c) = 0;
              *(undefined4 *)(puVar4 + -0x168) = 0x80;
              *(undefined4 **)(puVar4 + -0x164) = &DAT_0078cb22;
              *(undefined4 *)(puVar4 + -0x160) = 7;
              *(char **)(puVar4 + -0x15c) = "unknown";
              *(undefined4 *)(puVar4 + -0x158) = 0x200;
              *(undefined4 *)(puVar4 + -0x154) = 2;
              ffree(Var7);
              uVar2 = FUN_005f6540(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c8,puVar4 + -0x168);
              *(undefined4 *)(puVar4 + -0xfc) = uVar2;
              Var7 = extraout_ST0_02;
              if (*(int *)(puVar4 + -0xfc) == 0) {
                if (9999999 < DAT_0078dc88) {
                  DAT_0078dc88 = 0;
                }
                DAT_0078dcb0 = 0;
                goto LAB_004cd8e1;
              }
            }
            else {
              *(undefined4 *)(puVar4 + -0x10c) = 0;
LAB_004cd8e1:
              *(undefined4 *)(puVar4 + -0xf8) = 0x80;
              DAT_0089fd68 = 1;
              do {
                if (*(char *)(DAT_0089fd68 + 0x78b50f) < ' ') {
                  *(undefined1 *)(DAT_0089fd68 + 0x78b50f) = 0;
                  FUN_005f46bc(puVar4,0x4cd985);
                  FUN_005f34d1(puVar4,0x4cd99b);
                  *(undefined4 *)(puVar4 + -0xf0) = 0;
                  break;
                }
                *(undefined4 *)(puVar4 + -0xf4) = 0;
                *(undefined4 *)(puVar4 + -0xec) = 0;
                DAT_0089fd68 = DAT_0089fd68 + 1;
                *(int *)(puVar4 + -0xf8) = *(int *)(puVar4 + -0xf8) + -1;
              } while (0 < *(int *)(puVar4 + -0xf8));
              *(undefined4 *)(puVar4 + -0xe8) = 0x80;
              DAT_01aae334 = 1;
              do {
                iVar3 = FUN_005f4660(0x20);
                Var7 = extraout_ST0_03;
                if (iVar3 != 0) {
                  FUN_005f46bc(puVar4,0x4cda37);
                  Var7 = FUN_005f34d1(puVar4,0x4cda4d);
                }
                DAT_01aae334 = DAT_01aae334 + 1;
                *(int *)(puVar4 + -0xe8) = *(int *)(puVar4 + -0xe8) + -1;
              } while (0 < *(int *)(puVar4 + -0xe8));
              if (DAT_0089fd84 == 0) {
                *(undefined4 *)(puVar4 + -0x14c) = 0;
                *(int **)(puVar4 + -0x158) = &DAT_0078dc88;
                ffree(Var7);
                iVar3 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_00765184,puVar4 + -0x158,
                                     &DAT_007926e8);
                *(int *)(puVar4 + -0xe4) = iVar3;
                Var7 = extraout_ST0_04;
                if (iVar3 == 0) {
                  *(undefined4 *)(puVar4 + -0x158) = 0x80;
                  *(undefined4 **)(puVar4 + -0x154) = &DAT_0078b510;
                  ffree(extraout_ST0_04);
                  uVar2 = FUN_005fc980(puVar4 + -0x14c,&DAT_00765180,puVar4 + -0x158);
                  *(undefined4 *)(puVar4 + -0xe4) = uVar2;
                  Var7 = extraout_ST0_05;
                }
                iVar3 = *(int *)(puVar4 + -0xe4);
              }
              else {
                *(undefined4 *)(puVar4 + -0x14c) = 0;
                *(int **)(puVar4 + -0x158) = &DAT_0078dc88;
                ffree(Var7);
                iVar3 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_00765184,puVar4 + -0x158,
                                     &DAT_0079276c);
                *(int *)(puVar4 + -0xe0) = iVar3;
                Var7 = extraout_ST0_06;
                if (iVar3 == 0) {
                  *(undefined4 *)(puVar4 + -0x158) = 0x80;
                  *(undefined4 **)(puVar4 + -0x154) = &DAT_0078b510;
                  ffree(extraout_ST0_06);
                  uVar2 = FUN_005fc980(puVar4 + -0x14c,&DAT_00765180,puVar4 + -0x158);
                  *(undefined4 *)(puVar4 + -0xe0) = uVar2;
                  Var7 = extraout_ST0_07;
                }
                iVar3 = *(int *)(puVar4 + -0xe0);
              }
              if (iVar3 == 0) {
                if (((DAT_01aae304 != 0) && (0 < DAT_01aae300)) && (DAT_0078cbb2 == 1)) {
                  FUN_005f33c9(puVar4,0x4cdc17);
                  Var7 = FUN_005f34d1(puVar4,0x4cdc32);
                  ffree(Var7);
                  Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00765164,&DAT_00765168,"(1i3)",
                                            5,&DAT_0089fd80);
                  DAT_020b8eac._0_1_ = 0;
                  *(undefined4 *)(puVar4 + -0x14c) = 0;
                  *(undefined4 *)(puVar4 + -0x158) = 0xc;
                  *(undefined2 **)(puVar4 + -0x154) = &DAT_020b8ea0;
                  ffree(Var7);
                  FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff00,&DAT_00765180,puVar4 + -0x158,
                               &DAT_007927f0);
                }
                FUN_005f33c9(puVar4,0x4cdce4);
                Var7 = FUN_005f34d1(puVar4,0x4cdcff);
                DAT_00791448 = 0;
                if (VIEW_DX == 0x960) {
                  *(undefined4 *)(puVar4 + -0xd8) = 0;
                }
                else {
                  DAT_01be6cac = (DAT_01be6cac - VIEW_DX) + 0x960;
                  DAT_01be6ca4 = (DAT_01be6ca4 - VIEW_DX) + 0x960;
                }
                DAT_01be6cac = DAT_01be6cac + -200;
                DAT_01be6ca4 = DAT_01be6ca4 + -300;
                if (_DAT_01c60cb2 != f_1) {
                  *(int *)(puVar4 + -0x150) = DAT_01be6cac - DAT_01be6ca4;
                  _DAT_0089fd64 = (float)*(int *)(puVar4 + -0x150) * _DAT_01c60cb2;
                  *(undefined2 *)(puVar4 + -0x154) = in_FPUControlWord;
                  *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                  *(int *)(puVar4 + -0x150) = (int)ROUND((float)DAT_01be6ca4 + _DAT_0089fd64);
                  in_FPUControlWord = *(undefined2 *)(puVar4 + -0x154);
                  DAT_01be6cac = *(int *)(puVar4 + -0x150);
                }
                _DAT_0089fd7c = DAT_01aae2a0 * f_4000 + f_100;
                *(undefined2 *)(puVar4 + -0x154) = in_FPUControlWord;
                *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                *(int *)(puVar4 + -0x150) =
                     (int)ROUND((float)DAT_01be6ca4 + (_DAT_0089fd7c - f_2100));
                iVar3 = *(int *)(puVar4 + -0x150);
                *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
                *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                *(int *)(puVar4 + -0x150) =
                     (int)ROUND((float)DAT_01be6cac + (_DAT_0089fd7c - f_2100));
                *(int *)(puVar4 + -0x150) = *(int *)(puVar4 + -0x150) - iVar3;
                _DAT_0089fd60 =
                     (float)*(int *)(puVar4 + -0x150) +
                     ((float)iVar3 - _DAT_0089fd7c) * _DAT_01c60cb2 + _DAT_0089fd7c;
                _DAT_0089fd54 = DAT_01aae2a0;
                _DAT_0089fd4c = DAT_01aae2a4;
                _DAT_0089fd50 = DAT_01aae2a8;
                _DAT_0089fd48 = DAT_01aae2ac;
                *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
                *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                *(int *)(puVar4 + -0x150) = (int)ROUND(DAT_01aae2a0 - f_1);
                _DAT_0089fd5c = *(undefined4 *)(puVar4 + -0x150);
                *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
                *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                *(int *)(puVar4 + -0x150) = (int)ROUND(DAT_01aae2a4);
                _DAT_0089fd44 = *(undefined4 *)(puVar4 + -0x150);
                *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
                *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                *(int *)(puVar4 + -0x150) = (int)ROUND(DAT_01aae2a8 + f_4);
                DAT_0089fd58 = *(undefined4 *)(puVar4 + -0x150);
                *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
                *(ushort *)(puVar4 + -0x152) = (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                *(int *)(puVar4 + -0x150) = (int)ROUND(DAT_01aae2ac + f_4);
                in_FPUControlWord = *(undefined2 *)(puVar4 + -0x154);
                _DAT_0089fd40 = *(undefined4 *)(puVar4 + -0x150);
                ffree(Var7);
                Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00765124,&DAT_00765128,"(1i5)",5,
                                          &DAT_0089fd5c);
                ffree(Var7);
                Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_0076511c,&DAT_00765120,"(1i5)",5,
                                          &DAT_0089fd44);
                ffree(Var7);
                Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_00765114,&DAT_00765118,"(1i5)",5,
                                          &DAT_0089fd58);
                ffree(Var7);
                Var7 = thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_0076510c,&DAT_00765110,"(1i5)",5,
                                          &DAT_0089fd40);
                *(undefined4 *)(puVar4 + -0x14c) = 0;
                *(undefined4 *)(puVar4 + -0x158) = 0x2a;
                *(undefined2 **)(puVar4 + -0x154) = &DAT_020b8ea0;
                ffree(Var7);
                Var7 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff00,&DAT_00765180,puVar4 + -0x158,
                                    &DAT_00792804);
                *(undefined4 *)(puVar4 + -0x14c) = 0;
                ffree(Var7);
                uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792818);
                *(undefined4 *)(puVar4 + -0xd0) = uVar2;
                Var7 = extraout_ST0_08;
                if (*(int *)(puVar4 + -0xd0) == 0) {
                  *(undefined4 *)(puVar4 + -0x14c) = 0;
                  ffree(extraout_ST0_08);
                  uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_0079283c)
                  ;
                  *(undefined4 *)(puVar4 + -0xcc) = uVar2;
                  Var7 = extraout_ST0_09;
                  if (*(int *)(puVar4 + -0xcc) == 0) {
                    if (((DAT_01aae304 != 0) && (DAT_01aae300 != 0)) && (DAT_0078cbb2 == 1)) {
                      *(undefined4 *)(puVar4 + -0x14c) = 0;
                      *(int **)(puVar4 + -0x158) = &DAT_0089fd84;
                      ffree(extraout_ST0_09);
                      Var7 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff00,&DAT_00765184,
                                          puVar4 + -0x158,&DAT_00792858);
                      *(int **)(puVar4 + -0x158) = &DAT_0089fd84;
                      ffree(Var7);
                      FUN_005fc980(puVar4 + -0x14c,&DAT_00765108,puVar4 + -0x158);
                    }
                    *(undefined4 *)(puVar4 + -0xc4) = 0;
                    goto LAB_004ce2b8;
                  }
                }
              }
            }
            goto LAB_004cefa4;
          }
          *(undefined4 *)(puVar4 + -0x110) = 0;
          DAT_0078dcb0 = 1;
          DAT_0078dcb4 = 1;
          puVar4[-0x14d] = 0x31;
          DAT_00793360 = CONCAT13(puVar4[-0x14d],(undefined3)DAT_00793360);
          DAT_0078dcc8 = DAT_00793360;
          *(undefined4 *)(puVar4 + -0xbc) = 0;
          *(undefined4 *)(puVar4 + -0x14c) = 0;
          *(undefined4 *)(puVar4 + -0x168) = 4;
          *(undefined4 **)(puVar4 + -0x164) = &DAT_0078dcc8;
          *(undefined4 *)(puVar4 + -0x160) = 3;
          *(undefined **)(puVar4 + -0x15c) = &DAT_007651dc;
          *(undefined4 *)(puVar4 + -0x158) = 0x100;
          *(undefined4 *)(puVar4 + -0x154) = 2;
          ffree(fVar8);
          uVar2 = FUN_005f6540(puVar4 + -0x14c,0x18,0x784ff03,&DAT_007651c8,puVar4 + -0x168);
          *(undefined4 *)(puVar4 + -0xb8) = uVar2;
          _DAT_0089fd3c = *(undefined4 *)(puVar4 + -0xb8);
          if (*(int *)(puVar4 + -0xb8) == 0) {
            *(undefined4 *)(puVar4 + -0x14c) = 0;
            ffree(extraout_ST0);
            uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792878);
            *(undefined4 *)(puVar4 + -0xb4) = uVar2;
            if (*(int *)(puVar4 + -0xb4) != 0) goto LAB_004cd62a;
            DAT_0078b4e0 = DAT_0089fd88;
            *(undefined4 *)(puVar4 + -0x14c) = 0;
            ffree(extraout_ST0_00);
            uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_0079289c);
            *(undefined4 *)(puVar4 + -0xb0) = uVar2;
            Var7 = extraout_ST0_01;
            if (*(int *)(puVar4 + -0xb0) != 0) goto LAB_004cefa4;
            *(undefined4 *)(puVar4 + -0xac) = 0;
LAB_004ce2b8:
            Var7 = FUN_005f34d1(puVar4,0x4ce2d5);
            if (DAT_0078b6b0 == 1) {
              DAT_01c60ca0 = i_1635020658;
              DAT_01c60ca4 = _DAT_00765100;
            }
            DAT_00791444 = 0xffffffff;
            if (DAT_0078cbb2 != 0) {
              *(undefined4 *)(puVar4 + -0x14c) = 0;
              ffree(Var7);
              uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_007928c0);
              *(undefined4 *)(puVar4 + -0xa4) = uVar2;
              Var7 = extraout_ST0_10;
              if (*(int *)(puVar4 + -0xa4) != 0) goto LAB_004cefa4;
            }
            *(undefined4 *)(puVar4 + -0x14c) = 0;
            ffree(Var7);
            uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_007928f4);
            *(undefined4 *)(puVar4 + -0xa0) = uVar2;
            Var7 = extraout_ST0_11;
            if (*(int *)(puVar4 + -0xa0) == 0) {
              if (DAT_0078cbb2 == 0) {
                *(undefined4 *)(puVar4 + -0x14c) = 0;
                ffree(extraout_ST0_11);
                uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792908);
                *(undefined4 *)(puVar4 + -0x9c) = uVar2;
                Var7 = extraout_ST0_12;
                if (*(int *)(puVar4 + -0x9c) != 0) goto LAB_004cefa4;
              }
              *(undefined4 *)(puVar4 + -0x14c) = 0;
              ffree(Var7);
              uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_0079293c);
              *(undefined4 *)(puVar4 + -0x98) = uVar2;
              Var7 = extraout_ST0_13;
              if (*(int *)(puVar4 + -0x98) == 0) {
                if (DAT_0078b484 != 0) {
                  *(undefined4 *)(puVar4 + -0x14c) = 0;
                  ffree(extraout_ST0_13);
                  uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792970)
                  ;
                  *(undefined4 *)(puVar4 + -0x94) = uVar2;
                  Var7 = extraout_ST0_14;
                  if (*(int *)(puVar4 + -0x94) != 0) goto LAB_004cefa4;
                }
                *(undefined4 *)(puVar4 + -0x14c) = 0;
                ffree(Var7);
                uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792ab4);
                *(undefined4 *)(puVar4 + -0x90) = uVar2;
                Var7 = extraout_ST0_15;
                if (*(int *)(puVar4 + -0x90) == 0) {
                  *(undefined4 *)(puVar4 + -0x14c) = 0;
                  ffree(extraout_ST0_15);
                  uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792af4)
                  ;
                  *(undefined4 *)(puVar4 + -0x8c) = uVar2;
                  Var7 = extraout_ST0_16;
                  if (*(int *)(puVar4 + -0x8c) == 0) {
                    *(undefined4 *)(puVar4 + -0x14c) = 0;
                    ffree(extraout_ST0_16);
                    uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                         &DAT_00792b54);
                    *(undefined4 *)(puVar4 + -0x88) = uVar2;
                    Var7 = extraout_ST0_17;
                    if (*(int *)(puVar4 + -0x88) == 0) {
                      *(undefined4 *)(puVar4 + -0x14c) = 0;
                      ffree(extraout_ST0_17);
                      uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                           &DAT_00792b8c);
                      *(undefined4 *)(puVar4 + -0x84) = uVar2;
                      Var7 = extraout_ST0_18;
                      if (*(int *)(puVar4 + -0x84) == 0) {
                        switch(DAT_0078cbaa) {
                        case 2:
code_r0x004ce815:
                          *(undefined4 *)(puVar4 + -0x14c) = 0;
                          ffree(extraout_ST0_18);
                          uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                               &DAT_00792bcc);
                          *(undefined4 *)(puVar4 + -0x70) = uVar2;
                          Var7 = extraout_ST0_24;
                          if (*(int *)(puVar4 + -0x70) != 0) goto LAB_004cefa4;
                          *(undefined4 *)(puVar4 + -0x6c) = 0;
                          break;
                        case 3:
                          *(undefined4 *)(puVar4 + -0x14c) = 0;
                          ffree(extraout_ST0_18);
                          uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                               0x792bf4);
                          *(undefined4 *)(puVar4 + -0x68) = uVar2;
                          Var7 = extraout_ST0_19;
                          if (*(int *)(puVar4 + -0x68) != 0) goto LAB_004cefa4;
                          *(undefined4 *)(puVar4 + -100) = 0;
                          break;
                        case 4:
                          *(undefined4 *)(puVar4 + -0x14c) = 0;
                          ffree(extraout_ST0_18);
                          uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                               0x792c1c);
                          *(undefined4 *)(puVar4 + -0x60) = uVar2;
                          Var7 = extraout_ST0_20;
                          if (*(int *)(puVar4 + -0x60) != 0) goto LAB_004cefa4;
                          *(undefined4 *)(puVar4 + -0x5c) = 0;
                          break;
                        case 5:
                          *(undefined4 *)(puVar4 + -0x14c) = 0;
                          ffree(extraout_ST0_18);
                          uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                               0x792c44);
                          *(undefined4 *)(puVar4 + -0x58) = uVar2;
                          Var7 = extraout_ST0_21;
                          if (*(int *)(puVar4 + -0x58) != 0) goto LAB_004cefa4;
                          *(undefined4 *)(puVar4 + -0x54) = 0;
                          break;
                        case 6:
                          *(undefined4 *)(puVar4 + -0x14c) = 0;
                          *(undefined **)(puVar4 + -0x158) = &DAT_01aae290;
                          ffree(extraout_ST0_18);
                          iVar3 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_00765184,
                                               puVar4 + -0x158,0x792c98);
                          *(int *)(puVar4 + -0x50) = iVar3;
                          Var7 = extraout_ST0_22;
                          if (iVar3 == 0) {
                            *(undefined **)(puVar4 + -0x158) = &DAT_01aae294;
                            ffree(extraout_ST0_22);
                            uVar2 = FUN_005fc980(puVar4 + -0x14c,&DAT_00765108,puVar4 + -0x158);
                            *(undefined4 *)(puVar4 + -0x50) = uVar2;
                            Var7 = extraout_ST0_23;
                          }
                          if (*(int *)(puVar4 + -0x50) != 0) goto LAB_004cefa4;
                          *(undefined4 *)(puVar4 + -0x4c) = 0;
                          break;
                        default:
                          if (((DAT_0078cbb6 == 0) || (_DAT_0078caf0 != f_8_5)) ||
                             (_DAT_0078caf4 != f_11)) {
                            if ((_DAT_0078caf0 < f_0) || (_DAT_0078caf4 < f_0)) {
                              *(undefined4 *)(puVar4 + -0x7c) = 0;
                            }
                            else {
                              *(undefined2 *)(puVar4 + -0x154) = in_FPUControlWord;
                              *(ushort *)(puVar4 + -0x152) =
                                   (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                              *(int *)(puVar4 + -0x150) = (int)ROUND(_DAT_0078caf0 * f_72);
                              DAT_0089fd38 = *(int *)(puVar4 + -0x150);
                              *(undefined2 *)(puVar4 + -0x154) = *(undefined2 *)(puVar4 + -0x154);
                              *(ushort *)(puVar4 + -0x152) =
                                   (ushort)*(undefined4 *)(puVar4 + -0x154) | 0xc00;
                              *(int *)(puVar4 + -0x150) = (int)ROUND(_DAT_0078caf4 * f_72);
                              in_FPUControlWord = *(undefined2 *)(puVar4 + -0x154);
                              DAT_0089fd34 = *(int *)(puVar4 + -0x150);
                              *(undefined4 *)(puVar4 + -0x78) = 0;
                              if (DAT_0078cbb2 == 0) {
                                *(undefined4 *)(puVar4 + -0x14c) = 0;
                                *(int **)(puVar4 + -0x158) = &DAT_0089fd38;
                                ffree(extraout_ST0_18);
                                iVar3 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_00765184,
                                                     puVar4 + -0x158,&DAT_00792cf4);
                                *(int *)(puVar4 + -0x48) = iVar3;
                                Var7 = extraout_ST0_25;
                                if (iVar3 == 0) {
                                  *(int **)(puVar4 + -0x158) = &DAT_0089fd34;
                                  ffree(extraout_ST0_25);
                                  iVar3 = FUN_005fc980(puVar4 + -0x14c,&DAT_00765184,puVar4 + -0x158
                                                      );
                                  *(int *)(puVar4 + -0x48) = iVar3;
                                  Var7 = extraout_ST0_26;
                                  if (iVar3 == 0) {
                                    *(int **)(puVar4 + -0x158) = &DAT_0078cbb6;
                                    ffree(extraout_ST0_26);
                                    uVar2 = FUN_005fc980(puVar4 + -0x14c,&DAT_00765108,
                                                         puVar4 + -0x158);
                                    *(undefined4 *)(puVar4 + -0x48) = uVar2;
                                    Var7 = extraout_ST0_27;
                                  }
                                }
                                if (*(int *)(puVar4 + -0x48) != 0) goto LAB_004cefa4;
                              }
                            }
                          }
                          else {
                            *(undefined4 *)(puVar4 + -0x80) = 0;
                            DAT_0078b4e4 = 0;
                            if ((DAT_0078b6b0 == 0) &&
                               (0x251 < DAT_0089fd38 || 0x305 < DAT_0089fd34))
                            goto code_r0x004ce815;
                            *(undefined4 *)(puVar4 + -0x74) = 0;
                          }
                        }
                        if (DAT_0078cba6 == 0) {
                          *(undefined4 *)(puVar4 + -0x44) = 0;
                        }
                        else {
                          *(undefined4 *)(puVar4 + -0x14c) = 0;
                          ffree(Var7);
                          uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                               &DAT_00792d58);
                          *(undefined4 *)(puVar4 + -0x40) = uVar2;
                          Var7 = extraout_ST0_28;
                          if (*(int *)(puVar4 + -0x40) != 0) goto LAB_004cefa4;
                          ffree(extraout_ST0_28);
                          Var7 = FUN_004cf214();
                          if (DAT_0078b4e0 == 0x42) {
                            *(undefined4 *)(puVar4 + -0x3c) = 0;
                            goto LAB_004cebf5;
                          }
                        }
                        *(undefined4 *)(puVar4 + -0x14c) = 0;
                        ffree(Var7);
                        uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                             &DAT_00792d7c);
                        *(undefined4 *)(puVar4 + -0x38) = uVar2;
                        Var7 = extraout_ST0_29;
                        if (*(int *)(puVar4 + -0x38) == 0) {
                          if (DAT_0078b6b0 == 1) {
                            *(undefined4 *)(puVar4 + -0x14c) = 0;
                            ffree(extraout_ST0_29);
                            uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                                 &DAT_00792d9c);
                            *(undefined4 *)(puVar4 + -0x34) = uVar2;
                            Var7 = extraout_ST0_30;
                            if (*(int *)(puVar4 + -0x34) != 0) goto LAB_004cefa4;
                          }
                          *(undefined4 *)(puVar4 + -0x14c) = 0;
                          *(float **)(puVar4 + -0x158) = &DAT_01aae2f0;
                          ffree(Var7);
                          iVar3 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007650e8,
                                               puVar4 + -0x158,&DAT_00792dbc);
                          *(int *)(puVar4 + -0x30) = iVar3;
                          Var7 = extraout_ST0_31;
                          if (iVar3 == 0) {
                            *(float **)(puVar4 + -0x158) = &DAT_01aae324;
                            ffree(extraout_ST0_31);
                            uVar2 = FUN_005fc980(puVar4 + -0x14c,&DAT_007650e4,puVar4 + -0x158);
                            *(undefined4 *)(puVar4 + -0x30) = uVar2;
                            Var7 = extraout_ST0_32;
                          }
                          if (*(int *)(puVar4 + -0x30) == 0) {
                            *(undefined4 *)(puVar4 + -0x14c) = 0;
                            ffree(Var7);
                            uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,
                                                 &DAT_00792e00);
                            *(undefined4 *)(puVar4 + -0x2c) = uVar2;
                            Var7 = extraout_ST0_33;
                            if (*(int *)(puVar4 + -0x2c) == 0) goto LAB_004cebf5;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
LAB_004cefa4:
            ffree(Var7);
            Var7 = FUN_004cf1c2();
            DAT_020b8ea0._0_1_ = s_PSFNAMES_TMPX_007650d4[0xc];
            for (iVar3 = 1; iVar3 < 0xb; iVar3 = iVar3 + 1) {
              *(undefined4 *)(iVar3 * 4 + 0x78d89c) = 0xffffffff;
            }
            *(undefined4 *)(puVar4 + -0xc0) = 0;
          }
          else {
LAB_004cd62a:
            FUN_005f33c9(puVar4,0x4cd648);
            Var7 = FUN_005f34d1(puVar4,0x4cd663);
            DAT_020b8ebc = DAT_0078dcc8;
            ffree(Var7);
            Var7 = thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
            *(undefined4 *)(puVar4 + -0xa8) = 0;
          }
          goto LAB_004ceff4;
        }
        *(undefined4 *)(puVar4 + -0x114) = 0;
LAB_004cebf5:
        DAT_01eae1b0 = 0;
        DAT_0078b6bc = 0;
        _DAT_01eae1b4 = f_0;
        if (DAT_0078b4e0 == 0x42) {
          OUTPUT_MODE = 0;
          DAT_020b8ea0._0_1_ = s_PSFNAMES_TMPX_007650d4[0xc];
          *(undefined4 *)(puVar4 + -0x28) = 0;
          goto LAB_004ceff4;
        }
        if (DAT_0078cbb2 == 1) {
          *(undefined4 *)(puVar4 + -0x154) = DAT_0078b464;
          *(undefined4 *)(puVar4 + -0x150) = DAT_0078b468;
          *(undefined4 *)(puVar4 + -0x14c) = 0;
          FUN_005f33c9(puVar4,0x4cec8d);
          Var7 = FUN_005f33c9(puVar4,0x4ceca9);
          *(undefined1 **)(puVar4 + -0x16c) = puVar4 + -0x188;
          *(undefined4 *)(puVar4 + -0x170) = 0x14;
          *(undefined4 *)(puVar4 + -0x168) = 7;
          *(undefined4 *)(puVar4 + -0x164) = extraout_EDX;
          *(undefined4 *)(puVar4 + -0x160) = 0x200;
          *(undefined4 *)(puVar4 + -0x15c) = 2;
          ffree(Var7);
          uVar2 = FUN_005f6540(puVar4 + -0x14c,0x1a,0x784ff01,&DAT_007651c8,puVar4 + -0x170);
          *(undefined4 *)(puVar4 + -0x24) = uVar2;
          Var7 = extraout_ST0_34;
          if (*(int *)(puVar4 + -0x24) == 0) goto LAB_004ced3a;
          ffree(extraout_ST0_34);
          Var7 = thunk_FUN_0054d831("Error opening temp. font name file.",0x23);
        }
        else {
LAB_004ced3a:
          *(undefined4 *)(puVar4 + -0x20) = 0;
        }
        OUTPUT_MODE = -1;
        *(undefined4 *)(puVar4 + -0x14c) = 0;
        *(undefined4 **)(puVar4 + -0x158) = &DAT_01aae2f4;
        ffree(Var7);
        iVar3 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_00765184,puVar4 + -0x158,
                             &DAT_00792e34);
        *(int *)(puVar4 + -0x1c) = iVar3;
        Var7 = extraout_ST0_35;
        if (iVar3 == 0) {
          *(undefined4 **)(puVar4 + -0x158) = &DAT_01aae2f8;
          ffree(extraout_ST0_35);
          uVar2 = FUN_005fc980(puVar4 + -0x14c,&DAT_00765108,puVar4 + -0x158);
          *(undefined4 *)(puVar4 + -0x1c) = uVar2;
          Var7 = extraout_ST0_36;
        }
        if (*(int *)(puVar4 + -0x1c) != 0) goto LAB_004cefa4;
        *(undefined4 *)(puVar4 + -0x14c) = 0;
        ffree(Var7);
        uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792e78);
        *(undefined4 *)(puVar4 + -0x18) = uVar2;
        Var7 = extraout_ST0_37;
        if (*(int *)(puVar4 + -0x18) != 0) goto LAB_004cefa4;
        *(undefined4 *)(puVar4 + -0x14c) = 0;
        ffree(extraout_ST0_37);
        uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792e98);
        *(undefined4 *)(puVar4 + -0x14) = uVar2;
        Var7 = extraout_ST0_38;
        if (*(int *)(puVar4 + -0x14) != 0) goto LAB_004cefa4;
        if (DAT_0078cba2 != 0) {
          *(undefined4 *)(puVar4 + -0x14c) = 0;
          ffree(extraout_ST0_38);
          uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792eac);
          *(undefined4 *)(puVar4 + -0x10) = uVar2;
          Var7 = extraout_ST0_39;
          if (*(int *)(puVar4 + -0x10) != 0) goto LAB_004cefa4;
        }
        if (DAT_0078cbae != 0) {
          *(undefined4 *)(puVar4 + -0x14c) = 0;
          ffree(Var7);
          uVar2 = FUN_005fc330(puVar4 + -0x14c,0x18,0x784ff01,&DAT_007651c4,0,&DAT_00792ed0);
          *(undefined4 *)(puVar4 + -0xc) = uVar2;
          Var7 = extraout_ST0_40;
          if (*(int *)(puVar4 + -0xc) != 0) goto LAB_004cefa4;
        }
        ffree(Var7);
        Var7 = thunk_FUN_00533a88();
        _DAT_020b8e40 = 0;
        _DAT_0078dd5c = 1;
        ffree(Var7);
        Var7 = draw_items();
        _DAT_0078dd5c = 0;
        ffree(Var7);
        Var7 = thunk_FUN_0054946a(&DAT_01c4cb60,0x80);
        if (DAT_01aae300 == 0) {
          *(undefined4 *)(puVar4 + -8) = 0;
          goto LAB_004ceff4;
        }
        DAT_01aae300 = DAT_01aae300 + -1;
        ffree(Var7);
        Var7 = thunk_FUN_00512009();
        if (DAT_01aae300 < 1) {
          ffree(Var7);
          Var7 = thunk_FUN_00495d4f(&DAT_01c4cb60,0x80);
          ffree(Var7);
          Var7 = thunk_FUN_00549422();
          goto LAB_004ceff4;
        }
        *(undefined4 *)(puVar4 + -4) = 0;
LAB_004cd0c3:
        DAT_0089fd84 = DAT_0089fd84 + 1;
        puVar5 = (undefined4 *)(&DAT_01c4eec4 + DAT_0089fd84 * 0x80);
        puVar6 = &DAT_01c4cb60;
        for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        DAT_0078b4e4 = 0x1a0a;
        ITEM_WORDS = 0;
        ffree(Var7);
        Var7 = load_score();
        if (ITEM_WORDS == 0) goto code_r0x004cd112;
        ffree(Var7);
        Var7 = draw_items();
        ffree(Var7);
        Var7 = fit_view(&DAT_007651fc,&DAT_01be6cb0,&DAT_01be6ca8,&DAT_01be6ca4,&DAT_01be6cac);
        _DAT_0089fd7c = (DAT_01c60cae - f_0_75) * f_4000;
        *(int *)(puVar4 + -0x150) = DAT_01be6ca4 + -400;
        _DAT_0089fd78 = (float)*(int *)(puVar4 + -0x150) / f_4000;
        *(int *)(puVar4 + -0x150) = DAT_01be6ca8 + 0x69aa;
        _DAT_0089fd74 = ((float)*(int *)(puVar4 + -0x150) + _DAT_0089fd7c) / f_4000;
        *(int *)(puVar4 + -0x150) = DAT_01be6cac + -400;
        _DAT_0089fd70 = (float)*(int *)(puVar4 + -0x150) / f_4000;
        *(int *)(puVar4 + -0x150) = DAT_01be6cb0 + 0x69aa;
        _DAT_0089fd6c = ((float)*(int *)(puVar4 + -0x150) + _DAT_0089fd7c) / f_4000;
        ffree(Var7);
        Var7 = thunk_FUN_004d31bb(&DAT_01c60caa,&DAT_01c60cae,&DAT_0089fd78,&DAT_0089fd74,
                                  &DAT_0089fd70,&DAT_0089fd6c,&DAT_0078b6b0);
        puVar1 = puVar4;
      } while( true );
    }
    DAT_0078b4e0 = 0x42;
  }
  goto LAB_004ceff4;
code_r0x004cd112:
  ffree(Var7);
  Var7 = thunk_FUN_0054946a("Leaving Batch Printing.",0x18);
  *(undefined4 *)(puVar4 + -0x118) = 0;
LAB_004ceff4:
  DAT_00791448 = 1;
  VIEW_DX = DAT_0089fd90;
  ffree(Var7);
  return;
}


