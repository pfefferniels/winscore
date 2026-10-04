// FUN_004dce58 @ 004dce58 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004dd089) */

void FUN_004dce58(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  int *piVar8;
  byte *pbVar9;
  int *piVar10;
  bool bVar11;
  bool bVar12;
  undefined2 in_FPUControlWord;
  undefined1 *puVar13;
  
  puVar13 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  DAT_00794834 = ITEM_WORDS;
  DAT_008a0630 = ITEM_WORDS;
  DAT_008a0628 = 1;
  if (DAT_00794830 == 0) {
    DAT_0079484c = 0;
    DAT_0078cae4 = 0;
    DAT_008a0624 = 4;
  }
  if (DAT_01ade7e8 == 0) {
    for (; ((DAT_01ade7c4 = *(byte *)((int)&DAT_01e62c80 + DAT_008a0628 + 3), DAT_01ade7c4 == 0x2f
            || (DAT_01ade7c4 == 0x3a)) ||
           ((DAT_01ade7c4 == 0x50 && ((&DAT_01e62c84)[DAT_008a0628] != 'R'))));
        DAT_008a0628 = DAT_008a0628 + 1) {
    }
    DAT_008a0620 = 0;
    DAT_008a061c = DAT_008a0628;
    for (iVar4 = 0xd - DAT_008a0628; 0 < iVar4; iVar4 = iVar4 + -1) {
      bVar11 = iVar4 == 0;
      bVar12 = false;
      iVar3 = 1;
      pbVar7 = (byte *)((int)&DAT_01e62c80 + DAT_008a061c + 3);
      pbVar9 = &DAT_007659b8;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar12 = *pbVar7 < *pbVar9;
        bVar11 = *pbVar7 == *pbVar9;
        pbVar7 = pbVar7 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar12) {
        iVar3 = 1;
        bVar12 = false;
        pbVar7 = (byte *)((int)&DAT_01e62c80 + DAT_008a061c + 3);
        pbVar9 = &DAT_007659b4;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar12 = *pbVar7 < *pbVar9;
          bVar11 = *pbVar7 == *pbVar9;
          pbVar7 = pbVar7 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar11);
        if (bVar12 || bVar11) {
          uVar5 = (uint)*(char *)((int)&DAT_01e62c80 + DAT_008a061c + 3);
          bVar12 = uVar5 < 0x30;
          DAT_008a0620 = uVar5 - 0x30;
          bVar11 = DAT_008a0620 == 0;
          iVar3 = 1;
          pbVar7 = (byte *)(&DAT_01e62c84 + DAT_008a061c);
          pbVar9 = &DAT_007659b8;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar12 = *pbVar7 < *pbVar9;
            bVar11 = *pbVar7 == *pbVar9;
            pbVar7 = pbVar7 + 1;
            pbVar9 = pbVar9 + 1;
          } while (bVar11);
          if (bVar12) break;
          iVar3 = 1;
          bVar12 = false;
          pbVar7 = (byte *)(&DAT_01e62c84 + DAT_008a061c);
          pbVar9 = &DAT_007659b4;
          do {
            if (iVar3 == 0) break;
            iVar3 = iVar3 + -1;
            bVar12 = *pbVar7 < *pbVar9;
            bVar11 = *pbVar7 == *pbVar9;
            pbVar7 = pbVar7 + 1;
            pbVar9 = pbVar9 + 1;
          } while (bVar11);
          if (!bVar12 && !bVar11) break;
          DAT_008a0620 = DAT_008a0620 * 10 + (int)(&DAT_01e62c84)[DAT_008a061c] + -0x30;
        }
      }
      DAT_008a061c = DAT_008a061c + 1;
    }
    FUN_005f46bc(&stack0xfffffffc,0x4dd0ad);
    puVar6 = puVar13;
    FUN_005f34d1(puVar13,0x4dd0c3);
    if ((((DAT_01ade7c4 == 0x54) || (DAT_008a062c == 0x4c41)) || (DAT_008a062c == 0x4142)) ||
       (DAT_008a062c == 0x5250)) {
      *(undefined4 *)(puVar6 + -100) = 0;
      DAT_008a0618 = f_5;
      DAT_008a0614 = f_3;
      *(undefined4 *)(puVar6 + -0x4c) = 5;
      DAT_008a061c = 0;
      do {
        if (*(short *)(s_TRBAALTEPR_00794784 + DAT_008a061c * 2) == DAT_008a062c) {
          DAT_0079484c = DAT_008a061c;
        }
        DAT_008a061c = DAT_008a061c + 1;
        *(int *)(puVar6 + -0x4c) = *(int *)(puVar6 + -0x4c) + -1;
      } while (0 < *(int *)(puVar6 + -0x4c));
      (&ITEM_P5)[DAT_00794834] = (float)DAT_0079484c;
      DAT_00794850 = DAT_0078cae8 + DAT_00794850;
      LOAD_P3 = DAT_00794850;
      (&ITEM_P4)[DAT_008a0630] = f_0;
      DAT_00794850 = DAT_00794850 + f_2;
      *(undefined4 *)(puVar6 + -0x48) = 0;
      goto LAB_004dda39;
    }
    bVar12 = DAT_01ade7c4 < 0x52;
    if (DAT_01ade7c4 == 0x52) {
      *(undefined4 *)(puVar6 + -0x60) = 0;
      DAT_008a0618 = f_5;
      DAT_008a0614 = f_2;
      (&ITEM_P4)[DAT_00794834] = f_0;
      iVar4 = DAT_00794834;
      *(int *)(puVar6 + -0xb0) = DAT_00794838 * -2 + 0x50;
      (&ITEM_P5)[iVar4] = (float)*(int *)(puVar6 + -0xb0);
      DAT_00794850 = DAT_0078cae8 + DAT_00794850;
      *(undefined4 *)(puVar6 + -0x40) = 0;
      goto LAB_004dd485;
    }
    iVar4 = 1;
    bVar11 = false;
    pbVar7 = &DAT_01ade7c4;
    pbVar9 = &DAT_007659a4;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar12 = *pbVar7 < *pbVar9;
      bVar11 = *pbVar7 == *pbVar9;
      pbVar7 = pbVar7 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar11);
    if (!bVar12) {
      iVar4 = 1;
      pbVar7 = &DAT_01ade7c4;
      pbVar9 = &DAT_007659a0;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar12 = *pbVar7 < *pbVar9;
        bVar11 = *pbVar7 == *pbVar9;
        pbVar7 = pbVar7 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (bVar12 || bVar11) {
        *(undefined4 *)(puVar6 + -0x5c) = 0;
        DAT_01ade7c4 = (&DAT_01e62c84)[DAT_008a0628];
        if (DAT_008a0620 != 0) {
          DAT_008a0624 = DAT_008a0620;
        }
        DAT_00794844 = 0;
        iVar4 = (int)*(char *)((int)&DAT_01e62c80 + DAT_008a0628 + 3);
        DAT_008a060c = iVar4 + -0x42;
        if (DAT_008a060c < 1) {
          DAT_008a060c = iVar4 + -0x3b;
        }
        if (*(byte *)((int)&DAT_01e62c80 + DAT_008a0628 + 3) == DAT_01ade7c4) {
          DAT_00794844 = 1;
          bVar12 = (byte)(&DAT_01e62c85)[DAT_008a0628] < DAT_01ade7c4;
          if ((&DAT_01e62c85)[DAT_008a0628] == DAT_01ade7c4) {
            DAT_00794844 = 2;
          }
          *(undefined4 *)(puVar6 + -0x1c) = 0;
        }
        else if (DAT_01ade7c4 == 0x46) {
          DAT_00794844 = 1;
          bVar12 = (byte)(&DAT_01e62c85)[DAT_008a0628] < 0x46;
          if ((&DAT_01e62c85)[DAT_008a0628] == 0x46) {
            DAT_00794844 = 4;
          }
          *(undefined4 *)(puVar6 + -0x18) = 0;
        }
        else {
          if (DAT_01ade7c4 == 0x4e) {
            DAT_00794844 = 3;
          }
          if (DAT_01ade7c4 == 0x53) {
            DAT_00794844 = 2;
          }
          bVar12 = (byte)(&DAT_01e62c85)[DAT_008a0628] < 0x53;
          if ((&DAT_01e62c85)[DAT_008a0628] == 0x53) {
            DAT_00794844 = 5;
          }
        }
        do {
          iVar4 = 1;
          pbVar7 = &DAT_01ade7c4;
          pbVar9 = &DAT_007659a4;
          do {
            if (iVar4 == 0) break;
            iVar4 = iVar4 + -1;
            bVar2 = *pbVar9;
            bVar1 = *pbVar7;
            bVar12 = bVar1 < bVar2;
            pbVar7 = pbVar7 + 1;
            pbVar9 = pbVar9 + 1;
          } while (bVar1 == bVar2);
          if (bVar12) goto LAB_004dd367;
          bVar12 = 0xfffffffe < DAT_008a0628;
          DAT_01ade7c4 = (&DAT_01e62c85)[DAT_008a0628];
          DAT_008a0628 = DAT_008a0628 + 1;
          *(undefined4 *)(puVar6 + -0x10) = 0;
        } while( true );
      }
    }
    if (DAT_01ade7c4 == 0x4b) {
      *(undefined4 *)(puVar6 + -0x58) = 0;
      DAT_008a0618 = f_6;
      DAT_008a0614 = f_17;
      DAT_008a0610 = DAT_008a0620;
      if ((char)DAT_01e62c88 == 'N') {
        DAT_008a0610 = DAT_008a0620 + 100;
      }
      if (DAT_01e62c87 == 'F') {
        DAT_008a0610 = -DAT_008a0610;
        DAT_008a0620 = -DAT_008a0620;
      }
      (&ITEM_P5)[DAT_00794834] = (float)DAT_008a0610;
      (&ITEM_P6)[DAT_00794834] = (float)DAT_0079484c;
      (&ITEM_P4)[DAT_008a0630] = f_0;
      DAT_00794850 = DAT_0078cae8 + DAT_00794850;
      iVar4 = DAT_008a0620;
      if (DAT_008a0620 < 0) {
        iVar4 = -DAT_008a0620;
      }
      LOAD_P3 = DAT_00794850;
      *(int *)(puVar6 + -0xb0) = iVar4 * 3;
      DAT_00794850 = ((float)*(int *)(puVar6 + -0xb0) + DAT_00794850) - f_5;
      *(undefined4 *)(puVar6 + -0x44) = 0;
      goto LAB_004dda39;
    }
    if (DAT_01ade7c4 == 0x4d) {
      *(undefined4 *)(puVar6 + -0x54) = 0;
      DAT_008a0618 = f_5;
      DAT_008a0614 = f_14;
      DAT_00794844 = 0;
      bVar12 = false;
      if (DAT_008a0620 != 0) {
        DAT_0078cae4 = DAT_008a0620;
      }
      do {
        DAT_01ade7c4 = (&DAT_01e62c84)[DAT_008a0628];
        iVar4 = 1;
        pbVar7 = &DAT_01ade7c4;
        pbVar9 = &DAT_00765980;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          bVar2 = *pbVar9;
          bVar1 = *pbVar7;
          bVar12 = bVar1 < bVar2;
          pbVar7 = pbVar7 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar1 == bVar2);
        if (bVar12) {
          *(undefined4 *)(puVar6 + -0x3c) = 0;
          goto LAB_004dd702;
        }
        if ((DAT_01ade7c4 != 0x44) || (DAT_00794844 = 1, (&DAT_01e62c85)[DAT_008a0628] != 'H'))
        goto LAB_004dd682;
        bVar12 = 0xfffffffe < DAT_008a0628;
        DAT_008a0628 = DAT_008a0628 + 1;
        *(undefined4 *)(puVar6 + -0x38) = 0;
      } while( true );
    }
    *(undefined4 *)(puVar6 + -0x50) = 0;
  }
  DAT_008a0618 = f_6;
  DAT_008a0614 = f_18;
  (&ITEM_P4)[DAT_00794834] = f_0;
  if (DAT_01e62c85 == 'C') {
    IP1 = 99;
    iVar4 = 3;
    bVar12 = true;
    piVar8 = (int *)&DAT_01e62c84;
    piVar10 = &DAT_00765968;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar12 = *piVar8 == *piVar10;
      piVar8 = piVar8 + 1;
      piVar10 = piVar10 + 1;
    } while (bVar12);
    if (bVar12) {
      IP1 = 0x62;
    }
    IP2 = 0;
    *(undefined4 *)(puVar6 + -0x2c) = 0;
  }
  else {
    *(undefined4 *)(puVar6 + -0x30) = 0;
    *(undefined4 *)(puVar6 + -0xac) = 0;
    *(undefined4 *)(puVar6 + -0xc0) = 2;
    *(char **)(puVar6 + -0xbc) = &DAT_01e62c85;
    *(int **)(puVar6 + -0xb8) = &IP1;
    FUN_005f9240(puVar6 + -0xac,0x784ff00,&DAT_00765974,puVar6 + -0xc0,&DAT_00794758);
    *(undefined4 *)(puVar6 + -0xac) = 0;
    *(undefined4 *)(puVar6 + -0xc0) = 2;
    *(undefined4 **)(puVar6 + -0xbc) = &DAT_01e62c88;
    *(int **)(puVar6 + -0xb8) = &IP2;
    FUN_005f9240(puVar6 + -0xac,0x784ff00,&DAT_00765974,puVar6 + -0xc0,&DAT_0079476c);
  }
  (&ITEM_P5)[DAT_00794834] = (float)IP1;
  (&ITEM_P6)[DAT_00794834] = (float)IP2;
  LOAD_P3 = DAT_0078cae8 + DAT_00794850;
  if ((9 < IP2) || (DAT_00794850 = LOAD_P3, 9 < IP1)) {
    DAT_00794850 = LOAD_P3 + f_2;
  }
  DAT_01ade7e8 = 0;
  *(undefined4 *)(puVar6 + -0x20) = 0;
  goto LAB_004dda39;
LAB_004dd682:
  if (DAT_01ade7c4 == 0x48) {
    DAT_00794844 = 2;
  }
  if (DAT_01ade7c4 == 0x4c) {
    DAT_00794844 = 3;
  }
  if (DAT_01ade7c4 == 0x52) {
    DAT_00794844 = 4;
  }
  if ((&DAT_01e62c85)[DAT_008a0628] == 'R') {
    DAT_00794844 = 5;
    DAT_008a0628 = DAT_008a0628 + 1;
  }
LAB_004dd702:
  (&ITEM_P4)[DAT_00794834] = (float)DAT_0078cae4;
  (&ITEM_P5)[DAT_00794834] = (float)DAT_00794844;
  if (DAT_00794844 != 0) {
    DAT_00794850 = DAT_00794850 + f_2;
  }
  if ((DAT_00794844 == 3) || (DAT_00794844 == 5)) {
    DAT_00794850 = DAT_00794850 + f_2;
  }
  LOAD_P3 = DAT_0078cae8 + DAT_00794850;
  DAT_00794850 = LOAD_P3;
  if (DAT_00794844 < 4) {
    DAT_00794850 = LOAD_P3 - f_2;
  }
  DAT_00794848 = 0;
  DAT_00794844 = 0;
  *(undefined4 *)(puVar6 + -0x34) = 0;
  goto LAB_004dda39;
LAB_004dd367:
  *(undefined4 *)(puVar6 + -0x14) = 0;
  iVar4 = DAT_00794834;
  DAT_008a0618 = f_5;
  DAT_008a0614 = f_1;
  *(int *)(puVar6 + -0xb0) =
       DAT_008a0624 * 7 + DAT_008a060c + *(int *)(&DAT_00794790 + DAT_0079484c * 4) + -0x1c;
  (&ITEM_P4)[iVar4] = (float)*(int *)(puVar6 + -0xb0);
  DAT_0079483c = f_10;
  if (f_6 < (float)(&ITEM_P4)[DAT_00794834]) {
    DAT_0079483c = f_20;
  }
  if (DAT_00794840 == 0) {
    *(undefined4 *)(puVar6 + -0xc) = 0;
  }
  else {
    if (DAT_00794840 < 0) {
      DAT_0079483c = f_20;
    }
    if (0 < DAT_00794840) {
      DAT_0079483c = f_10;
    }
  }
  (&ITEM_P5)[DAT_00794834] = (float)DAT_00794844 + DAT_0079483c;
  if (DAT_01e62c84 == ':') {
    *(undefined4 *)(puVar6 + -8) = 0;
  }
  else {
    if (DAT_00794844 == 4) {
      DAT_00794850 = DAT_00794850 + f_3;
    }
    DAT_00794850 = DAT_0078cae8 + DAT_00794850;
  }
LAB_004dd485:
  LOAD_P3 = DAT_00794850;
LAB_004dda39:
  (&ITEM_LEN)[DAT_008a0630] = DAT_008a0618;
  (&ITEM_P1)[DAT_008a0630] = DAT_008a0614;
  (&ITEM_P2)[DAT_008a0630] = DAT_01fb8c60;
  (&ITEM_P3)[DAT_008a0630] = LOAD_P3;
  *(undefined2 *)(puVar6 + -0xb4) = in_FPUControlWord;
  *(ushort *)(puVar6 + -0xb2) = (ushort)*(undefined4 *)(puVar6 + -0xb4) | 0xc00;
  *(int *)(puVar6 + -0xb0) = (int)ROUND((float)DAT_00794834 + DAT_008a0618 + f_1);
  DAT_00794834 = *(int *)(puVar6 + -0xb0);
  *(undefined2 *)(puVar6 + -0xb4) = *(undefined2 *)(puVar6 + -0xb4);
  *(ushort *)(puVar6 + -0xb2) = (ushort)*(undefined4 *)(puVar6 + -0xb4) | 0xc00;
  *(int *)(puVar6 + -0xb0) = (int)ROUND((float)DAT_00794834 + DAT_008a0618 + f_1);
  ITEM_WORDS = *(int *)(puVar6 + -0xb0);
  ITEM_I = ITEM_I + 1;
  (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
  DAT_008a061c = ITEM_I;
  FUN_004ddb6e(&DAT_008a061c);
  thunk_FUN_00549422();
  *(undefined4 *)(puVar6 + -4) = 0;
  return;
}


