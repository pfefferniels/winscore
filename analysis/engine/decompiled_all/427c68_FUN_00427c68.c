// FUN_00427c68 @ 00427c68 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00427c68(void)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  char *pcVar7;
  byte *pbVar8;
  short *psVar9;
  undefined4 *puVar10;
  char *pcVar11;
  byte *pbVar12;
  short *psVar13;
  undefined4 *puVar14;
  bool bVar15;
  bool bVar16;
  
  puVar6 = &stack0xfffffffc;
  FUN_005f34d1(&stack0xfffffffc,0x427c91);
  DAT_01fb9630 = 1;
  **(undefined4 **)(puVar6 + 8) = 0;
  DAT_007d3288 = 1;
  DAT_00794834 = DAT_020b8e58;
  DAT_007d3284 = 0;
  DAT_00794830 = 0;
  DAT_007d3294 = DAT_0075fbf0;
  FUN_005f34d1(puVar6,0x427cfb);
  DAT_007d328c = DAT_0075fbf0;
  DAT_007d3280 = 0;
  _DAT_007d327c = 0;
  DAT_0171b230 = 1;
LAB_00427d2a:
  FUN_005f34d1(puVar6,0x427d47);
LAB_00427d4b:
  while( true ) {
    thunk_FUN_00549afb();
    bVar15 = CONCAT11(DAT_020b90a1,DAT_020b90a0) < 0x767e;
    bVar16 = CONCAT11(DAT_020b90a1,DAT_020b90a0) == 0x767e;
    if (!bVar16) break;
    *(undefined4 *)(puVar6 + -0x94) = 0;
  }
  iVar5 = 1;
  pbVar8 = (byte *)&DAT_020b90a0;
  pbVar12 = &DAT_0075fbec;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar15 = *pbVar8 < *pbVar12;
    bVar16 = *pbVar8 == *pbVar12;
    pbVar8 = pbVar8 + 1;
    pbVar12 = pbVar12 + 1;
  } while (bVar16);
  if (!bVar15) {
    iVar5 = 1;
    pbVar8 = (byte *)&DAT_020b90a0;
    pbVar12 = &DAT_0075fbe8;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar15 = *pbVar8 < *pbVar12;
      bVar16 = *pbVar8 == *pbVar12;
      pbVar8 = pbVar8 + 1;
      pbVar12 = pbVar12 + 1;
    } while (bVar16);
    if (bVar15 || bVar16) {
      DAT_020b90a0 = DAT_020b90a0 + -0x20;
    }
  }
  iVar5 = FUN_005f4660(0x20);
  if (iVar5 != 0) {
    thunk_FUN_004e5988();
    **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + -3;
    DAT_007d3278 = **(int **)(puVar6 + 8);
    if (DAT_007d3278 == 0) {
      DAT_007d3278 = 1;
    }
    FUN_005f46bc(puVar6,0x428b53);
    FUN_005f34d1(puVar6,0x428b69);
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_007d3278);
    *(undefined4 *)(puVar6 + -0x8c) = 0;
    goto LAB_00427d2a;
  }
  *(undefined4 *)(puVar6 + -0x90) = 0;
  if ((DAT_020b90a0 == 'x') || (DAT_020b90a0 == 'X')) {
    bVar15 = false;
    bVar16 = **(int **)(puVar6 + 8) == 0;
    if (0 < **(int **)(puVar6 + 8)) {
      bVar15 = (byte)(&DAT_007d3297)[**(int **)(puVar6 + 8)] < 0x2f;
      bVar16 = (&DAT_007d3297)[**(int **)(puVar6 + 8)] == 0x2f;
      if (!bVar16) {
        bVar15 = 0xfffffffe < **(uint **)(puVar6 + 8);
        iVar5 = **(uint **)(puVar6 + 8) + 1;
        bVar16 = iVar5 == 0;
        **(int **)(puVar6 + 8) = iVar5;
        (&DAT_007d3297)[**(int **)(puVar6 + 8)] = 0x2f;
      }
    }
    iVar5 = 1;
    pbVar8 = (byte *)&DAT_020b90a1;
    pbVar12 = (byte *)&DAT_0075fbf0;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar15 = *pbVar8 < *pbVar12;
      bVar16 = *pbVar8 == *pbVar12;
      pbVar8 = pbVar8 + 1;
      pbVar12 = pbVar12 + 1;
    } while (bVar16);
    if (bVar15 || bVar16) {
      DAT_007d3280 = 1;
      *(undefined4 *)(puVar6 + -0x88) = 0;
LAB_0042852b:
      **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 1;
      (&DAT_007d3297)[**(int **)(puVar6 + 8)] = DAT_020b90a0;
    }
    else {
      _DAT_007d327c = DAT_020b90a1 + -0x30;
      DAT_007d3280 = 2;
      **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 1;
      (&DAT_007d3297)[**(int **)(puVar6 + 8)] = DAT_020b90a0;
      **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 1;
      (&DAT_007d3297)[**(int **)(puVar6 + 8)] = DAT_020b90a1;
      *(undefined4 *)(puVar6 + -0x84) = 0;
    }
LAB_004285b5:
    puVar10 = &DAT_007d3298;
    puVar14 = (undefined4 *)&DAT_020b8ea0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar14 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar14 = puVar14 + 1;
    }
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,*(undefined4 *)(puVar6 + 8));
    if (DAT_020b90a0 == ';') {
      if ((&DAT_007d3296)[**(int **)(puVar6 + 8)] == '/') {
        (&DAT_007d3296)[**(int **)(puVar6 + 8)] = 0x20;
      }
      puVar10 = &DAT_007d3298;
      puVar14 = (undefined4 *)&DAT_020b8ea0;
      for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar14 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar14 = puVar14 + 1;
      }
      *(undefined4 *)(puVar6 + -0x24) = 0;
      goto LAB_00428cec;
    }
    *(undefined4 *)(puVar6 + -0x28) = 0;
    goto LAB_00427d4b;
  }
  if (DAT_007d3280 == 1) {
    iVar5 = 1;
    bVar15 = true;
    bVar16 = false;
    pbVar8 = (byte *)&DAT_020b90a0;
    pbVar12 = &DAT_0075fbe0;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar16 = *pbVar8 < *pbVar12;
      bVar15 = *pbVar8 == *pbVar12;
      pbVar8 = pbVar8 + 1;
      pbVar12 = pbVar12 + 1;
    } while (bVar15);
    if (!bVar16) {
      iVar5 = 1;
      pbVar8 = (byte *)&DAT_020b90a0;
      pbVar12 = &DAT_0075fbdc;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar16 = *pbVar8 < *pbVar12;
        bVar15 = *pbVar8 == *pbVar12;
        pbVar8 = pbVar8 + 1;
        pbVar12 = pbVar12 + 1;
      } while (bVar15);
      if (bVar16 || bVar15) {
        _DAT_007d327c = DAT_020b90a0 + -0x30;
        DAT_007d3280 = 2;
        *(undefined4 *)(puVar6 + -0x7c) = 0;
        goto LAB_0042852b;
      }
    }
    DAT_007d3280 = 0;
    (&DAT_020b8e9f)[**(int **)(puVar6 + 8)] = 0x20;
    (&DAT_007d3297)[**(int **)(puVar6 + 8)] = 0x20;
    **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + -1;
    *(undefined4 *)(puVar6 + -0x80) = 0;
    goto LAB_004285b5;
  }
  if ((DAT_007d3280 == 2) && (DAT_007d3284 = 0, DAT_020b90a0 == '/')) {
    DAT_007d3280 = 0;
  }
  if ((DAT_020b90a0 == '~') && (CONCAT11(DAT_020b90a1,0x7e) != 0x7e7e)) goto LAB_00428605;
  if ((DAT_009c48f4 == 8) || (CONCAT11(DAT_020b90a1,DAT_020b90a0) == 0x4b42)) goto LAB_00428437;
  if ((DAT_020b90a0 == '\x1b') || (DAT_020b90a0 == '^')) {
    DAT_020b8ea0._0_1_ = DAT_0075fba4;
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_0075fba0);
    *(undefined4 *)(puVar6 + -0x60) = 0;
    goto LAB_00428d0c;
  }
  if (CONCAT11(DAT_020b90a2,DAT_020b90a1) == 0x4b50) {
    DAT_007d3294 = DAT_020b90a0;
    *(undefined4 *)(puVar6 + -0x5c) = 0;
    goto LAB_00427d2a;
  }
  if (((DAT_009a9488 == 0x45b) || (DAT_009a9488 == 0x459)) || (DAT_009a9488 == 0x45a)) {
    if (DAT_01fbb700 == 5) {
      *(undefined4 *)(puVar6 + -0x58) = 0;
      goto LAB_00427d2a;
    }
    puVar6[-0xb5] = (char)DAT_009a9488 + -0x27;
    DAT_020b90a0 = puVar6[-0xb5];
    DAT_020b90a1 = (char)DAT_0075fba8;
    DAT_020b90a2 = (undefined1)((ushort)DAT_0075fba8 >> 8);
    *(undefined4 *)(puVar6 + -0x54) = 0;
  }
  else if (CONCAT11(DAT_020b90a2,DAT_020b90a1) != 0x3b42) {
    if (DAT_020b90a0 == 'G') {
      DAT_020b8ea0._0_1_ = DAT_0075fbac;
      *(undefined4 *)(puVar6 + -0x4c) = 0;
      goto LAB_00428d0c;
    }
    if (DAT_020b90a0 == '/') {
      if ((&DAT_007d3297)[**(int **)(puVar6 + 8)] == '/') {
        (&DAT_007d3297)[**(int **)(puVar6 + 8)] = 0x20;
      }
      DAT_007d3284 = 0;
LAB_004283ce:
      if ((DAT_020b90a0 == 'D') || (DAT_020b90a0 == 'd')) {
        DAT_020b90a0 = DAT_0075fbbc;
      }
      if ((DAT_020b90a0 == 'U') || (DAT_020b90a0 == 'u')) {
        DAT_020b90a0 = DAT_0075fbb8;
      }
      goto LAB_0042852b;
    }
    bVar15 = CONCAT11(DAT_020b90a2,DAT_020b90a1) < 0x3030;
    if (CONCAT11(DAT_020b90a2,DAT_020b90a1) == 0x3030) {
      _DAT_007d3290 = CONCAT11(DAT_020b90a1,DAT_020b90a0);
      *(undefined4 *)(puVar6 + -0x48) = 0;
      goto LAB_00427d2a;
    }
    iVar5 = 1;
    bVar16 = false;
    pbVar8 = (byte *)&DAT_020b90a0;
    pbVar12 = &DAT_0075fbd8;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar15 = *pbVar8 < *pbVar12;
      bVar16 = *pbVar8 == *pbVar12;
      pbVar8 = pbVar8 + 1;
      pbVar12 = pbVar12 + 1;
    } while (bVar16);
    if (!bVar15) {
      iVar5 = 1;
      pbVar8 = (byte *)&DAT_020b90a0;
      pbVar12 = &DAT_0075fbdc;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar15 = *pbVar8 < *pbVar12;
        bVar16 = *pbVar8 == *pbVar12;
        pbVar8 = pbVar8 + 1;
        pbVar12 = pbVar12 + 1;
      } while (bVar16);
      if (bVar15 || bVar16) {
        if (DAT_01fbb700 == 5) {
          iVar5 = 5;
          bVar15 = true;
          pcVar7 = &DAT_020b90a0;
          pcVar11 = "99 1/";
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar15 = *pcVar7 == *pcVar11;
            pcVar7 = pcVar7 + 1;
            pcVar11 = pcVar11 + 1;
          } while (bVar15);
          if (bVar15) {
            FUN_005f46bc(puVar6,0x4280ac);
            FUN_005f34d1(puVar6,0x4280c2);
            **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 5;
            *(undefined4 *)(puVar6 + -0x44) = 0;
          }
          else {
            if (CONCAT13(DAT_020b90a3,CONCAT12(DAT_020b90a2,CONCAT11(DAT_020b90a1,DAT_020b90a0))) !=
                0x2f312030) goto LAB_0042815e;
            FUN_005f46bc(puVar6,0x428123);
            FUN_005f34d1(puVar6,0x428139);
            **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 4;
          }
          DAT_007d3284 = 0;
          *(undefined4 *)(puVar6 + -0x40) = 0;
          goto LAB_004285b5;
        }
LAB_0042815e:
        if (**(int **)(puVar6 + 8) == 0) {
          DAT_007d3284 = 1;
        }
        bVar15 = false;
        if (0 < **(int **)(puVar6 + 8)) {
          iVar5 = 1;
          pbVar8 = &DAT_007d3297 + **(int **)(puVar6 + 8);
          pbVar12 = &DAT_0075fbd8;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar2 = *pbVar12;
            bVar1 = *pbVar8;
            bVar15 = bVar1 < bVar2;
            pbVar8 = pbVar8 + 1;
            pbVar12 = pbVar12 + 1;
          } while (bVar1 == bVar2);
          bVar16 = bVar15 != 0;
          iVar5 = -(uint)bVar15;
          bVar15 = iVar5 == 0;
          *(int *)(puVar6 + -0xb8) = iVar5;
          iVar5 = 1;
          pbVar8 = &DAT_007d3297 + **(int **)(puVar6 + 8);
          pbVar12 = &DAT_0075fbdc;
          do {
            if (iVar5 == 0) break;
            iVar5 = iVar5 + -1;
            bVar16 = *pbVar8 < *pbVar12;
            bVar15 = *pbVar8 == *pbVar12;
            pbVar8 = pbVar8 + 1;
            pbVar12 = pbVar12 + 1;
          } while (bVar15);
          if (((-(uint)(!bVar16 && !bVar15) | *(uint *)(puVar6 + -0xb8)) & 1) != 0) {
            DAT_007d3284 = DAT_007d3284 + 1;
          }
        }
        goto LAB_004283ce;
      }
    }
    if (CONCAT11(DAT_020b90a1,DAT_020b90a0) == 0x2323) {
      if (DAT_007d3284 == 0) {
        *(undefined4 *)(puVar6 + -0x3c) = 0;
        goto LAB_00427d2a;
      }
      FUN_005f46bc(puVar6,0x428244);
      FUN_005f34d1(puVar6,0x42825a);
      **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 4;
      DAT_007d3284 = 0;
      *(undefined4 *)(puVar6 + -0x38) = 0;
      goto LAB_004285b5;
    }
    if (CONCAT11(DAT_020b90a1,DAT_020b90a0) == 0x2525) {
      DAT_007d3288 = DAT_01fb8c78 + -1;
      if (DAT_007d3288 < 10) {
        DAT_020b90a1 = ' ';
      }
      else {
        sVar3 = (short)DAT_007d3288 % 10;
        DAT_007d3270 = (int)sVar3;
        DAT_007d3288 = DAT_007d3288 / 10;
        DAT_020b90a1 = (char)sVar3 + '0';
      }
      DAT_020b90a0 = (char)DAT_007d3288 + '0';
      DAT_020b90a4._0_1_ = DAT_020b90a1;
      DAT_020b90a4._1_1_ = 0x2f;
      DAT_020b90a3 = DAT_020b90a0;
      FUN_005f46bc(puVar6,0x428367);
      FUN_005f34d1(puVar6,0x42837d);
      **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 6;
      *(undefined4 *)(puVar6 + -0x34) = 0;
      goto LAB_004285b5;
    }
    iVar5 = 3;
    bVar15 = false;
    psVar9 = (short *)&DAT_020b90a0;
    psVar13 = &DAT_0075fbc8;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar15 = *psVar9 == *psVar13;
      psVar9 = psVar9 + 1;
      psVar13 = psVar13 + 1;
    } while (bVar15);
    if (bVar15) {
      DAT_009c6ae0 = 1;
    }
    else {
      iVar5 = 3;
      bVar15 = false;
      psVar9 = (short *)&DAT_020b90a0;
      psVar13 = &DAT_0075fbc0;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar15 = *psVar9 == *psVar13;
        psVar9 = psVar9 + 1;
        psVar13 = psVar13 + 1;
      } while (bVar15);
      if (!bVar15) goto LAB_004283ce;
      DAT_009c6ae0 = 2;
      *(undefined4 *)(puVar6 + -0x2c) = 0;
    }
    puVar10 = (undefined4 *)&DAT_020b8ea0;
    puVar14 = &DAT_009ae2bc;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar14 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar14 = puVar14 + 1;
    }
    _DAT_007d326c = thunk_FUN_0052fef6();
    puVar10 = &DAT_009ae2bc;
    puVar14 = (undefined4 *)&DAT_020b8ea0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar14 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar14 = puVar14 + 1;
    }
    *(undefined4 *)(puVar6 + -0x30) = 0;
    goto LAB_00427d2a;
  }
  **(undefined4 **)(puVar6 + 8) = 3;
  puVar10 = (undefined4 *)&DAT_020b90a0;
  puVar14 = (undefined4 *)&DAT_020b8ea0;
  for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar14 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar14 = puVar14 + 1;
  }
  if (DAT_007d3294 != ' ') {
    DAT_020b8ea2 = DAT_007d3294;
    DAT_020b8ea3 = 0x3b;
    **(undefined4 **)(puVar6 + 8) = 4;
    DAT_007d3294 = DAT_0075fbf0;
  }
  *(undefined4 *)(puVar6 + -0x50) = 0;
  goto LAB_00428cec;
LAB_00428605:
  *(undefined4 *)(puVar6 + -0x78) = 0;
  thunk_FUN_004277c9(&DAT_007d3270,&DAT_01a14950);
  if (**(int **)(puVar6 + 8) == 0) {
    *(undefined4 *)(puVar6 + -0x20) = 0;
  }
  else {
    if (((((&DAT_020b8e9f)[**(int **)(puVar6 + 8)] != '-') &&
         ((&DAT_007d3297)[**(int **)(puVar6 + 8)] != '=')) &&
        ((&DAT_007d3297)[**(int **)(puVar6 + 8)] != ' ')) &&
       ((&DAT_007d3297)[**(int **)(puVar6 + 8)] != '+')) {
      **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 1;
    }
    bVar15 = DAT_007d3284 < 2;
    if ((DAT_007d3284 == 2) &&
       (bVar15 = (byte)(&DAT_007d3297)[**(int **)(puVar6 + 8)] < 0x20,
       (&DAT_007d3297)[**(int **)(puVar6 + 8)] == 0x20)) {
      (&DAT_007d3297)[**(int **)(puVar6 + 8)] = 0x2f;
      bVar15 = false;
      DAT_007d3284 = 0;
    }
    iVar5 = 1;
    pbVar8 = &DAT_007d3297 + **(int **)(puVar6 + 8);
    pbVar12 = (byte *)&DAT_0075fbf0;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar2 = *pbVar12;
      bVar1 = *pbVar8;
      bVar15 = bVar1 < bVar2;
      pbVar8 = pbVar8 + 1;
      pbVar12 = pbVar12 + 1;
    } while (bVar1 == bVar2);
    if (bVar15) {
      (&DAT_007d3297)[**(int **)(puVar6 + 8)] = 0x20;
    }
  }
  bVar15 = 0xfffffffe < **(uint **)(puVar6 + 8);
  **(int **)(puVar6 + 8) = **(uint **)(puVar6 + 8) + 1;
  iVar5 = 1;
  pbVar8 = &DAT_007d3297 + **(int **)(puVar6 + 8);
  pbVar12 = (byte *)&DAT_0075fbf0;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar2 = *pbVar12;
    bVar1 = *pbVar8;
    bVar15 = bVar1 < bVar2;
    pbVar8 = pbVar8 + 1;
    pbVar12 = pbVar12 + 1;
  } while (bVar1 == bVar2);
  if (bVar15) {
    (&DAT_007d3297)[**(int **)(puVar6 + 8)] = 0x20;
  }
  if (_DAT_007d3290 != 0x2020) {
    DAT_007d3270 = (uint)DAT_007d3290 * 100 + DAT_007d3270 + -0x12c0;
    FUN_005f34d1(puVar6,0x428771);
  }
  if ((&DAT_007d3297)[**(int **)(puVar6 + 8)] != ' ') {
    **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 1;
  }
  if (DAT_007d3270 < 10) {
    iVar5 = **(int **)(puVar6 + 8);
    puVar6[-0xb5] = (char)DAT_007d3270 + '0';
    (&DAT_007d3297)[iVar5] = puVar6[-0xb5];
  }
  else if (DAT_007d3270 < 100) {
    iVar5 = **(int **)(puVar6 + 8);
    iVar4 = (**(int **)(puVar6 + 8) - (iVar5 + -1)) + 1;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    *(undefined4 *)(puVar6 + -0xb4) = 0;
    *(int *)(puVar6 + -200) = iVar4;
    *(undefined **)(puVar6 + -0xc4) = &DAT_007d3297 + iVar5;
    *(int **)(puVar6 + -0xc0) = &DAT_007d3270;
    FUN_005f34f0(puVar6 + -0xb4,0x784ff00,&DAT_0075fbb0,puVar6 + -200,&DAT_0078e980);
    **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 1;
  }
  else if (DAT_007d3270 < 1000) {
    iVar5 = **(int **)(puVar6 + 8);
    iVar4 = (**(int **)(puVar6 + 8) - (iVar5 + -1)) + 2;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    *(undefined4 *)(puVar6 + -0xb4) = 0;
    *(int *)(puVar6 + -200) = iVar4;
    *(undefined **)(puVar6 + -0xc4) = &DAT_007d3297 + iVar5;
    *(int **)(puVar6 + -0xc0) = &DAT_007d3270;
    FUN_005f34f0(puVar6 + -0xb4,0x784ff00,&DAT_0075fbb0,puVar6 + -200,&DAT_0078e994);
    **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 2;
  }
  else {
    iVar5 = **(int **)(puVar6 + 8);
    iVar4 = (**(int **)(puVar6 + 8) - (iVar5 + -1)) + 3;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    *(undefined4 *)(puVar6 + -0xb4) = 0;
    *(int *)(puVar6 + -200) = iVar4;
    *(undefined **)(puVar6 + -0xc4) = &DAT_007d3297 + iVar5;
    *(int **)(puVar6 + -0xc0) = &DAT_007d3270;
    FUN_005f34f0(puVar6 + -0xb4,0x784ff00,&DAT_0075fbb0,puVar6 + -200,&DAT_0078e9a8);
    **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 3;
  }
  DAT_007d3284 = DAT_007d3284 + 1;
  if ((2 < (int)DAT_007d3284) && ((&DAT_007d3296)[**(int **)(puVar6 + 8)] == ' ')) {
    (&DAT_007d3296)[**(int **)(puVar6 + 8)] = 0x2f;
  }
  if ((int)DAT_007d3284 < 2) {
    *(undefined4 *)(puVar6 + -0x10) = 0;
  }
  else {
    **(int **)(puVar6 + 8) = **(int **)(puVar6 + 8) + 1;
    (&DAT_007d3297)[**(int **)(puVar6 + 8)] = 0x2f;
    DAT_007d3284 = 0;
  }
  if (DAT_020b90a0 == ';') {
    *(undefined4 *)(puVar6 + -0xc) = 0;
LAB_00428cec:
    DAT_01fb9630 = 0;
    *(undefined1 *)((int)&DAT_020b8ea0 + **(int **)(puVar6 + 8)) = 0xd;
    *(undefined1 *)((int)&DAT_020b8ea0 + **(int **)(puVar6 + 8) + 1) = 10;
LAB_00428d0c:
    DAT_0171b230 = 0xffffffff;
    FUN_005f34d1(puVar6,0x428d34);
    return;
  }
  puVar10 = &DAT_007d3298;
  puVar14 = (undefined4 *)&DAT_020b8ea0;
  for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar14 = *puVar10;
    puVar10 = puVar10 + 1;
    puVar14 = puVar14 + 1;
  }
  thunk_FUN_005494b2(&DAT_020b8ea0,0x200,*(undefined4 *)(puVar6 + 8));
  if (DAT_01fb9630 == 0) {
    *(undefined4 *)(puVar6 + -8) = 0;
    goto LAB_00428cec;
  }
  if (DAT_009c48f4 == 0xd) goto LAB_00428cec;
  *(undefined4 *)(puVar6 + -4) = 0;
  goto LAB_00427d2a;
LAB_00428437:
  if (**(int **)(puVar6 + 8) == 0) {
    *(undefined4 *)(puVar6 + -0x74) = 0;
  }
  else {
    DAT_007d3274 = **(int **)(puVar6 + 8) + -1;
    (&DAT_007d3297)[**(int **)(puVar6 + 8)] = 0x20;
    *(undefined4 *)(puVar6 + -0x70) = 0;
    **(int **)(puVar6 + 8) = DAT_007d3274;
    DAT_007d3284 = 0;
    puVar10 = &DAT_007d3298;
    puVar14 = (undefined4 *)&DAT_020b8ea0;
    for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar14 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar14 = puVar14 + 1;
    }
    thunk_FUN_0054943a();
    thunk_FUN_005494b2(&DAT_020b8ea0,0x200,*(undefined4 *)(puVar6 + 8));
    *(undefined4 *)(puVar6 + -100) = 0;
  }
  goto LAB_00427d4b;
}


