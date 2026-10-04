// text_parse @ 0042fa58 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void text_parse(char *param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  undefined2 in_FPUControlWord;
  float10 fVar8;
  
  puVar3 = &stack0xfffffffc;
  DAT_01cadd28 = 0;
  DAT_020b8e68 = *param_3;
  DAT_01cb1068 = 0;
  DAT_007f1428 = IP8;
  if ((0x62 < IP8) || (IP8 == 0x5e)) {
    DAT_0078b6a0 = IP8 % 1000;
    DAT_020b8e60 = DAT_0078b6a0 % 100;
    if (((int)DAT_020b8e60 < 99) && (DAT_020b8e60 != 0x5e)) {
      FUN_00430a61();
    }
  }
  _DAT_007f1424 = 0;
  _DAT_01cadcf4 = (STEP * P48) / f_25;
  _DAT_01cadd24 = P10 * _DAT_01cadcf4;
  _DAT_01cadcf4 = _DAT_01cadcf4 * _DAT_0078f024;
  P13 = (float)i_0;
  param_1[DAT_020b8e68] = ' ';
  DAT_020b8e60 = 0;
  if (((DAT_0078d8a0 < 0) && (puVar3 = &stack0xfffffffc, DAT_0078b6a0 < 0x5a)) &&
     (puVar3 = &stack0xfffffffc, *param_1 != '_')) {
    DAT_0078b6a0 = 0;
    load_font_metrics();
    puVar3 = &stack0xfffffffc;
  }
  do {
    DAT_020b8e60 = DAT_020b8e60 + 1;
    DAT_0078d858 = (float)i_0;
    DAT_007f1430 = *(byte *)(DAT_020b8e60 + *(int *)(puVar3 + 8) + -1);
    while (DAT_007f1420 = (int)*(short *)(&DAT_0078f164 + (uint)DAT_007f1430 * 2),
          *(byte *)(DAT_020b8e60 + *(int *)(puVar3 + 8)) == DAT_007f1430) {
      *(uint *)(puVar3 + -0x100) = DAT_020b8e60;
      FUN_005f33c9(puVar3,0x42fc4e);
      FUN_005f33c9(puVar3,0x42fc6b);
      FUN_005f33c9(puVar3,0x42fc8d);
      *(undefined4 *)(puVar3 + -0xfc) = 0;
      *(undefined4 *)(puVar3 + -0x110) = 3;
      *(undefined **)(puVar3 + -0x10c) = &DAT_007f142c;
      *(int **)(puVar3 + -0x108) = &DAT_007f141c;
      uVar1 = FUN_005f9240(puVar3 + -0xfc,0x784ff01,&DAT_0075ff60,puVar3 + -0x110,&DAT_0078efe0);
      *(undefined4 *)(puVar3 + -0xcc) = uVar1;
      if (*(int *)(puVar3 + -0xcc) != 0) {
LAB_0042ff60:
        if (DAT_007f1420 + -0x4e < 0) goto LAB_0043066d;
        if (DAT_007f1420 + -0x4e < 1) {
          DAT_007f1420 = 0x4d;
          if (99 < DAT_0078b6a0) {
            DAT_007f1420 = 0x6e;
          }
          *(undefined4 *)(puVar3 + -0xb0) = 0;
          goto LAB_0043043a;
        }
        if ((DAT_007f1420 < 0x55) || (DAT_007f1420 == 0x5e)) {
          *(undefined4 *)(puVar3 + -0xac) = 0;
          goto LAB_0043066d;
        }
        if (DAT_007f1420 < 0x57) {
          *(undefined4 *)(puVar3 + -0xa8) = 0;
          goto LAB_0043043a;
        }
        *(undefined4 *)(puVar3 + -0xa4) = 0;
        switch(DAT_007f1420) {
        case 0x84:
          DAT_007f1420 = 0x57;
          *(undefined4 *)(puVar3 + -0xa0) = 0;
          goto LAB_0043043a;
        case 0x85:
        case 0x87:
        case 0x88:
        case 0x89:
          goto LAB_00430070;
        case 0x86:
          DAT_007f1420 = 0x56;
          *(undefined4 *)(puVar3 + -0x98) = 0;
          goto LAB_0043043a;
        case 0x8a:
        case 0x8b:
          DAT_007f1420 = DAT_007f1420 + -0x37;
          *(undefined4 *)(puVar3 + -0x9c) = 0;
          goto LAB_0043043a;
        }
        if (DAT_007f1420 == 0x44c) {
          DAT_007f1414 = 100;
          DAT_020b8e60 = DAT_020b8e60 + 1;
          *(undefined4 *)(puVar3 + -0x90) = 0;
          goto LAB_00430472;
        }
        *(undefined4 *)(puVar3 + -0x94) = 0;
        goto LAB_00430070;
      }
      if ((DAT_007f141c < 0x81) || (DAT_007f1420 != 0x49)) {
        *(undefined4 *)(puVar3 + -200) = 0;
        goto LAB_0042ff60;
      }
      if (OUTPUT_MODE < 0) {
        thunk_FUN_0056edfd();
        *(undefined4 *)(puVar3 + -0xfc) = 0;
        *(undefined4 *)(puVar3 + -0x110) = 3;
        *(undefined **)(puVar3 + -0x10c) = &DAT_007f142c;
        *(int **)(puVar3 + -0x108) = &DAT_007f1420;
        uVar1 = FUN_005f9240(puVar3 + -0xfc,0x784ff01,&DAT_0075ff60,puVar3 + -0x110,&DAT_0078eff4);
        *(undefined4 *)(puVar3 + -0xc4) = uVar1;
        if (*(int *)(puVar3 + -0xc4) != 0) {
LAB_0042ff4a:
          *(undefined4 *)(puVar3 + -0xbc) = 0;
          goto LAB_0042ff60;
        }
        DAT_007f1420 = -DAT_007f1420;
        DAT_020b8e60 = DAT_020b8e60 + 4;
        DAT_0078d858 = f_1_1;
        *(undefined4 *)(puVar3 + -0xc0) = 0;
        goto LAB_0043084b;
      }
      *(uint *)(puVar3 + -0x100) = DAT_020b8e60;
      FUN_005f33c9(puVar3,0x42fd60);
      FUN_005f33c9(puVar3,0x42fd7d);
      FUN_005f33c9(puVar3,0x42fd9f);
      *(undefined4 *)(puVar3 + -0xfc) = 0;
      *(undefined4 *)(puVar3 + -0x110) = 3;
      *(undefined **)(puVar3 + -0x10c) = &DAT_007f142c;
      *(int **)(puVar3 + -0x108) = &DAT_007f1418;
      uVar1 = FUN_005f9240(puVar3 + -0xfc,0x784ff01,&DAT_0075ff60,puVar3 + -0x110,&DAT_0078f008);
      *(undefined4 *)(puVar3 + -0xb8) = uVar1;
      if (*(int *)(puVar3 + -0xb8) != 0) goto LAB_0042ff4a;
      if ((DAT_007f1418 < 0x20) || (0x7d < DAT_007f1418)) {
        DAT_007f1430 = DAT_0075ff58;
      }
      else {
        puVar3[-0xfd] = (undefined1)DAT_007f1418;
        DAT_007f1430 = puVar3[-0xfd];
        if (DAT_007f1430 == 0x5e) {
          DAT_007f1430 = DAT_0075ff5c;
        }
      }
      DAT_020b8e60 = DAT_020b8e60 + 4;
      *(undefined4 *)(puVar3 + -0xb4) = 0;
    }
    *(undefined4 *)(puVar3 + -0xd0) = 0;
LAB_00430070:
    if (DAT_007f1420 + -0x44 < 0) {
LAB_0043066d:
      if ((DAT_007f1420 < 0x53) || (0x57 < DAT_007f1420)) {
        *(undefined4 *)(puVar3 + -0x38) = 0;
        DAT_0078d860 = DAT_007f1420 + 1;
        if ((0 < OUTPUT_MODE) && (DAT_007f1420 == 0xa7)) {
          DAT_0078d860 = 0x7f;
        }
        if ((int)DAT_0078d860 < 0x51) {
          *(undefined4 *)(puVar3 + -0x30) = 0;
LAB_0043071d:
          if (0x59 < DAT_0078b6a0 % 100) {
LAB_00430771:
            if (DAT_0078d860 == 0x96) {
              DAT_0078d860 = 0x5e;
            }
            if ((DAT_0078d860 == 0x92) || (DAT_0078d860 == 0x94)) {
              DAT_0078d860 = (int)(DAT_0078d860 - 0x92) / 2 + 0x65;
            }
            if ((0x84 < (int)DAT_0078d860) && ((int)DAT_0078d860 < 0x8e)) {
              DAT_0078d860 = DAT_0078d860 - 0x24;
            }
            goto LAB_004307ec;
          }
          *(undefined4 *)(puVar3 + -0x1c) = 0;
          if (DAT_0078b6a0 == 99) {
            *(undefined4 *)(puVar3 + -0x14) = 0;
            goto LAB_00430771;
          }
          DAT_0078d858 = *(float *)(&DAT_01cac100 + DAT_00791440 * 0x288 + DAT_0078d860 * 4);
        }
        else {
          if ((int)DAT_0078d860 < 0x54) {
            *(undefined4 *)(puVar3 + -0x2c) = 0;
          }
          else {
            if (((int)DAT_0078d860 < 0x59) || (0x5d < (int)DAT_0078d860)) {
              if ((int)DAT_0078d860 < 0xa3) {
                *(undefined4 *)(puVar3 + -0x24) = 0;
                goto LAB_0043071d;
              }
              DAT_0078d858 = f_0_5;
              if (0xa3 < (int)DAT_0078d860) {
                DAT_0078d858 = f_0_8;
              }
              if (DAT_0078d860 == 0xa7) {
                DAT_0078d858 = f_0_95;
              }
              *(undefined4 *)(puVar3 + -0x20) = 0;
              goto LAB_0043084b;
            }
            *(undefined4 *)(puVar3 + -0x28) = 0;
          }
LAB_004307ec:
          DAT_0078d858 = *(float *)(&DAT_01c6da5c + DAT_0078d860 * 4);
          *(undefined4 *)(puVar3 + -0x18) = 0;
        }
LAB_0043084b:
        DAT_0078d858 = _DAT_01cadcf4 * DAT_0078d858;
        if (DAT_0078d860 == 0x5f) {
          DAT_01cadd28 = DAT_01cadd28 + 1;
          DAT_0078d858 = _DAT_01cadd24 + DAT_0078d858;
        }
        else {
          *(undefined4 *)(puVar3 + -0x10) = 0;
        }
        P13 = DAT_0078d858 + P13;
      }
      else {
        *(undefined4 *)(puVar3 + -0x34) = 0;
      }
LAB_004308a2:
      DAT_01cb1068 = DAT_01cb1068 + 1;
      if ((DAT_01cb1068 < 2) && (9999 < DAT_007f1420 || DAT_007f1420 < 1000)) {
        DAT_01caea40 = DAT_0078b6a0 + 1000;
        DAT_01cadd40 = i_0;
        DAT_01cb1068 = 2;
      }
      else {
        *(undefined4 *)(puVar3 + -0xc) = 0;
      }
LAB_0043091a:
      (&DAT_01caea3c)[DAT_01cb1068] = DAT_007f1420;
      *(float *)(&DAT_01cadd3c + DAT_01cb1068 * 4) = DAT_0078d858;
    }
    else {
      if (DAT_007f1420 + -0x44 < 1) {
        iVar2 = FUN_004309af(*(undefined4 *)(puVar3 + 8),1,&DAT_0078f0b4,&DAT_0075ff50);
        if (iVar2 == 0) {
          *(undefined4 *)(puVar3 + -0x8c) = 0;
        }
        else {
          DAT_007f1420 = *(int *)(&DAT_0078f03c + _DAT_020b8e64 * 4);
          *(undefined4 *)(puVar3 + -0x88) = 0;
LAB_0043043a:
          DAT_020b8e60 = DAT_020b8e60 + 1;
        }
        goto LAB_0043066d;
      }
      if (DAT_007f1420 == 0x45) {
        iVar2 = FUN_004309af(*(undefined4 *)(puVar3 + 8),1,&DAT_0078f128,&DAT_0075ff38);
        if (iVar2 != 0) {
          DAT_007f1420 = _DAT_020b8e64 + 100;
          if ((0 < OUTPUT_MODE) && (DAT_007f1420 == 0x7e)) {
            DAT_007f1420 = 0xa7;
          }
          *(undefined4 *)(puVar3 + -0x7c) = 0;
          goto LAB_0043043a;
        }
        *(undefined4 *)(puVar3 + -0x80) = 0;
        goto LAB_0043066d;
      }
      *(undefined4 *)(puVar3 + -0x84) = 0;
      if (999 < DAT_007f1420) {
        if (*(char *)(DAT_020b8e60 + *(int *)(puVar3 + 8)) != '/') {
          DAT_007f1414 = 0;
LAB_00430472:
          DAT_020b8e60 = DAT_020b8e60 + 2;
          if (DAT_007f1428 < 0x5a) {
            iVar2 = (uint)*(byte *)(DAT_020b8e60 + *(int *)(puVar3 + 8) + -1) +
                    (uint)*(byte *)(DAT_020b8e60 + *(int *)(puVar3 + 8) + -2) * 10;
            DAT_007f1420 = iVar2 + -0x210;
            if ((0x59 < DAT_007f1420) && (DAT_007f1420 < 0x5e)) {
              DAT_007f1420 = iVar2 + -0x252;
            }
            if (DAT_007f1420 == 0x62) {
              DAT_007f1420 = 0x1d;
            }
            if ((DAT_007f1420 < 0) || (99 < DAT_007f1420)) {
              if ((_DAT_020b90a0 == 0x6d72) || (_DAT_020b90a0 == 0x4d52)) {
                *(undefined4 *)(puVar3 + -100) = 0;
              }
              else {
                DAT_007f1420 = ITEM_I + 1;
                FUN_005f33c9(puVar3,0x430572);
                FUN_005f34d1(puVar3,0x43058d);
                thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_0075feec,&DAT_0075fef0,"(1i4)",5,
                                   &DAT_007f1420);
                thunk_FUN_0054da52(&DAT_020b90a0,0x200);
                thunk_FUN_0054d831(&DAT_020b90a0,0x3c);
                DAT_007f1420 = 0x1d;
              }
            }
            else {
              *(undefined4 *)(puVar3 + -0x68) = 0;
            }
            if ((0 < OUTPUT_MODE) && (DAT_007f1420 == 99)) {
              DAT_007f1420 = 4;
            }
            DAT_0078b6a0 = DAT_007f1414 + DAT_007f1420;
            if ((DAT_007f1420 < 99) && (DAT_007f1420 != 0x5e)) {
              FUN_00430a61();
            }
            DAT_007f1420 = DAT_0078b6a0 + 1000;
            *(undefined4 *)(puVar3 + -0x60) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x6c) = 0;
          }
          goto LAB_004308a2;
        }
        DAT_007f1418 = 100000;
        DAT_007f1420 = 1000000;
        _DAT_020b8e64 = DAT_020b8e60 + 2;
        iVar2 = (DAT_020b8e60 - _DAT_020b8e64) + 8;
        *(int *)(puVar3 + -0x74) = iVar2;
        while (0 < iVar2) {
          DAT_007f1420 = (*(byte *)(_DAT_020b8e64 + *(int *)(puVar3 + 8) + -1) - 0x30) *
                         DAT_007f1418 + DAT_007f1420;
          DAT_007f1418 = DAT_007f1418 / 10;
          _DAT_020b8e64 = _DAT_020b8e64 + 1;
          *(int *)(puVar3 + -0x74) = *(int *)(puVar3 + -0x74) + -1;
          iVar2 = *(int *)(puVar3 + -0x74);
        }
        DAT_01cb1068 = DAT_01cb1068 + 1;
        DAT_020b8e60 = DAT_020b8e60 + 7;
        *(undefined4 *)(puVar3 + -0x70) = 0;
        goto LAB_0043091a;
      }
      *(undefined4 *)(puVar3 + -0x78) = 0;
      if (DAT_007f1420 != 0x7e) {
        *(undefined4 *)(puVar3 + -0x44) = 0;
        goto LAB_0043066d;
      }
      iVar2 = FUN_004309af(*(undefined4 *)(puVar3 + 8),1,&DAT_0078f028,&DAT_0075ff4c);
      if (iVar2 != 0) {
        if (OUTPUT_MODE < 1) {
          DAT_007f1420 = _DAT_020b8e64 + 0x5e;
          goto LAB_0043043a;
        }
        *(undefined4 *)(puVar3 + -0x3c) = 0;
        goto LAB_004308a2;
      }
      *(undefined4 *)(puVar3 + -0x40) = 0;
      bVar6 = CARRY4(DAT_020b8e60,*(uint *)(puVar3 + 8));
      pbVar4 = (byte *)(DAT_020b8e60 + *(uint *)(puVar3 + 8));
      bVar7 = pbVar4 == (byte *)0x0;
      DAT_007f1430 = *pbVar4;
      iVar2 = 1;
      pbVar4 = &DAT_007f1430;
      pbVar5 = &DAT_0075ff48;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pbVar4 < *pbVar5;
        bVar7 = *pbVar4 == *pbVar5;
        pbVar4 = pbVar4 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (bVar6) {
LAB_004302bf:
        *(undefined4 *)(puVar3 + -0x5c) = 0;
        goto LAB_0043066d;
      }
      iVar2 = 1;
      bVar6 = false;
      pbVar4 = &DAT_007f1430;
      pbVar5 = &DAT_0075ff44;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        bVar6 = *pbVar4 < *pbVar5;
        bVar7 = *pbVar4 == *pbVar5;
        pbVar4 = pbVar4 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (!bVar6 && !bVar7) goto LAB_004302bf;
      DAT_0078d860 = DAT_020b8e60 + 1;
      iVar2 = (DAT_020b8e68 - DAT_0078d860) + 1;
      *(int *)(puVar3 + -0x58) = iVar2;
      while (0 < iVar2) {
        if (*(char *)(DAT_0078d860 + *(int *)(puVar3 + 8) + -1) == '~') {
          *(undefined4 *)(puVar3 + -0x54) = 0;
          DAT_007f1420 = (DAT_0078d860 - DAT_020b8e60) + -1;
          fVar8 = (float10)thunk_FUN_005194d5(DAT_020b8e60 + *(int *)(puVar3 + 8),1,&DAT_007f1420);
          *(undefined2 *)(puVar3 + -0x104) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x102) = (ushort)*(undefined4 *)(puVar3 + -0x104) | 0xc00;
          *(int *)(puVar3 + -0x100) = (int)ROUND(fVar8 * (float10)f_10 + (float10)f_10000);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x104);
          DAT_007f1420 = *(int *)(puVar3 + -0x100);
          DAT_020b8e60 = DAT_0078d860;
          if (DAT_0078f020 == 0) {
            DAT_0078f020 = 1;
            *(undefined4 *)(puVar3 + -0x48) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x4c) = 0;
          }
          goto LAB_004308a2;
        }
        DAT_0078d860 = DAT_0078d860 + 1;
        *(int *)(puVar3 + -0x58) = *(int *)(puVar3 + -0x58) + -1;
        iVar2 = *(int *)(puVar3 + -0x58);
      }
      *(undefined4 *)(puVar3 + -0x50) = 0;
    }
    if (DAT_020b8e68 <= (int)DAT_020b8e60) {
      P13 = P5 * P13;
      if ((int)(&DAT_01caea3c)[DAT_01cb1068] < 1000) {
        *(undefined4 *)(puVar3 + -4) = 0;
      }
      else {
        DAT_01cb1068 = DAT_01cb1068 + -1;
        IP12 = IP12 + -3;
      }
      return;
    }
    *(undefined4 *)(puVar3 + -8) = 0;
  } while( true );
}


