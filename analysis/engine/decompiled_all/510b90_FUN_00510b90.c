// FUN_00510b90 @ 00510b90 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00510b90(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  char *pcVar8;
  undefined4 *puVar9;
  int *piVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  undefined2 in_FPUControlWord;
  undefined1 *puVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  undefined1 *puVar17;
  
  puVar14 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar15 = &stack0xfffffffc;
  puVar16 = &stack0xfffffffc;
  puVar17 = &stack0xfffffffc;
  if (((_DAT_020b8ea0 & 0xff) == 0x4c) || ((_DAT_020b8ea0 >> 8 & 0xff) == 0x54)) {
    if (0 < ITEM_I) {
      thunk_FUN_0054d831("Must do restart (RS) before using \"PAGE LAYOUT or PARTS.\"",0x3a);
      return;
    }
    DAT_0094195c = ITEM_I;
    thunk_FUN_004f8d48();
    FUN_005f34d1(&stack0xfffffffc,0x511e63);
    DAT_0078b4f0 = 0;
    *DAT_01fbb7c0 = 0;
    *DAT_01fbb844 = 0;
    if (-1 < ITEM_WORDS) {
      DAT_0078b4e4 = 0x53;
      DAT_020b90a3 = 0x20;
      DAT_01c58610 = 0;
      FUN_005f33c9(puVar17,0x511ed9);
      FUN_005f33c9(puVar17,0x511ef5);
      FUN_005f34d1(puVar17,0x511f10);
      thunk_FUN_00522bd8();
      thunk_FUN_00549422();
      *(undefined4 *)(puVar17 + -0xf8) = 0;
      return;
    }
    *(undefined4 *)(puVar17 + -0xfc) = 0;
    return;
  }
  bVar13 = false;
  if (((_DAT_020b8ea0 >> 8 & 0xff) == 0x47) &&
     (bVar11 = (_DAT_020b8ea0 >> 0x10 & 0xff) != 0x52,
     bVar12 = (_DAT_020b8ea0 >> 0x10 & 0xff) != 0x4c, bVar13 = bVar11 && bVar12, !bVar11 || !bVar12)
     ) {
    DAT_00941958 = 1;
    for (iVar7 = ITEM_I; 0 < iVar7; iVar7 = iVar7 + -1) {
      if (DAT_01fbb8b8 < (float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_00941958]]) {
        DAT_00941958 = 1;
        iVar7 = ITEM_I;
        goto joined_r0x00510ca8;
      }
      DAT_00941958 = DAT_00941958 + 1;
    }
    DAT_00941958 = 1;
    for (iVar7 = ITEM_I; 0 < iVar7; iVar7 = iVar7 + -1) {
      (&ITEM_P2)[(&ITEM_PTR0)[DAT_00941958]] =
           DAT_01fbb8b8 + (float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_00941958]];
      DAT_00941958 = DAT_00941958 + 1;
    }
    goto LAB_00510e06;
  }
  iVar7 = 7;
  pcVar4 = (char *)&DAT_020b8ea0;
  pcVar8 = "MAKEDIR";
  do {
    if (iVar7 == 0) break;
    iVar7 = iVar7 + -1;
    bVar13 = *pcVar4 == *pcVar8;
    pcVar4 = pcVar4 + 1;
    pcVar8 = pcVar8 + 1;
  } while (bVar13);
  if (bVar13) {
    puVar5 = (undefined4 *)&DAT_020b90a8;
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    goto LAB_00511aed;
  }
  if ((_DAT_020b8ea0 & 0xffffff) == 0x2a5350) {
    DAT_01be6d48 = (int)ROUND(P2);
    *(float *)(&DAT_01be6cdc + DAT_01be6d48 * 4) = P3;
    puVar5 = (undefined4 *)&DAT_020b90a0;
    puVar9 = &DAT_009ae2bc;
    for (iVar7 = 0x80; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    DAT_009ae2c8._2_1_ = s_saved_for_PGMAKEDIR_007675a4[0];
    DAT_009ae2c8._3_1_ = s_saved_for_PGMAKEDIR_007675a4[1];
    DAT_009ae2cc._0_1_ = s_saved_for_PGMAKEDIR_007675a4[2];
    DAT_009ae2cc._1_1_ = s_saved_for_PGMAKEDIR_007675a4[3];
    DAT_009ae2cc._2_1_ = s_saved_for_PGMAKEDIR_007675a4[4];
    DAT_009ae2cc._3_1_ = s_saved_for_PGMAKEDIR_007675a4[5];
    DAT_009ae2d0 = s_saved_for_PGMAKEDIR_007675a4[6];
    DAT_009ae2d1._0_1_ = s_saved_for_PGMAKEDIR_007675a4[7];
    DAT_009ae2d1._1_1_ = s_saved_for_PGMAKEDIR_007675a4[8];
    DAT_009ae2d1._2_1_ = s_saved_for_PGMAKEDIR_007675a4[9];
    DAT_009ae2d1._3_1_ = s_saved_for_PGMAKEDIR_007675a4[10];
    DAT_009ae2d5 = s_saved_for_PGMAKEDIR_007675a4[0xb];
    return;
  }
  if ((_DAT_020b8ea0 & 0xffffff) == 0x494f50) {
    DAT_0078b4e8 = 2;
    thunk_FUN_0054e9f2();
  }
  IP2 = (int)ROUND(P2);
  IP3 = (int)ROUND(P3);
  if (DAT_0078b4e4 == 0x4d) {
    FUN_0051210f(s_NOTE_REST_CLEF_LINE_SLUR_BEAM_TR_00796648,5);
    return;
  }
  if ((DAT_0078b4e4 == 0x52) || (DAT_0078b4e4 == 0x42)) {
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x45) {
      thunk_FUN_004a94ff();
      FUN_005f34d1(&stack0xfffffffc,0x511e0e);
      *(undefined4 *)(puVar16 + -0x1c) = 0;
      return;
    }
    while ((_DAT_020b8ea0 >> 8 & 0xff) != 0x42) {
      if (ITEM_I != 0) {
        DAT_0078b4e0 = 0;
        DAT_01aae214 = 0;
        _DAT_0078dc34 = ITEM_WORDS;
        thunk_FUN_004ccf20();
        for (iVar7 = 1; iVar7 < 0xb; iVar7 = iVar7 + 1) {
          *(undefined4 *)(iVar7 * 4 + 0x78d89c) = 0xffffffff;
        }
        if ((DAT_0078b4e0 != 0x42) && ((_DAT_020b8ea0 & 0xff) != 0x58)) {
          FUN_00512009();
        }
        FUN_005f34d1(&stack0xfffffffc,0x511d6e);
        for (iVar7 = 1; iVar7 < 0x41; iVar7 = iVar7 + 1) {
          *(float *)(&DAT_01a149a8 + iVar7 * 4) = f_0;
        }
        draw_items();
        *(undefined4 *)(puVar15 + -8) = 0;
        return;
      }
      DAT_020b8ea0 = CONCAT11(0x42,(undefined1)DAT_020b8ea0);
    }
    thunk_FUN_004ccf20();
    if ((_DAT_020b8ea0 & 0xff) != 0x2d) {
      draw_items();
      return;
    }
    _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007675b8);
    return;
  }
  if (DAT_0078b4e4 == 0x53) {
    thunk_FUN_005725fa();
    thunk_FUN_0044586d();
    thunk_FUN_00510430();
    return;
  }
  if (_DAT_020b8ea0 != 0x48544150) {
    if (DAT_0078b4e4 != 0x41) {
      thunk_FUN_00493e10();
      return;
    }
    return;
  }
  FUN_005f34d1(&stack0xfffffffc,0x51107f);
  *(undefined4 *)(puVar14 + -300) = DAT_0078b464;
  *(undefined4 *)(puVar14 + -0x128) = DAT_0078b468;
  *(undefined4 *)(puVar14 + -0x124) = 0;
  FUN_005f33c9(puVar14,0x5110bf);
  puVar3 = puVar14;
  FUN_005f33c9(puVar14,0x5110db);
  *(undefined1 **)(puVar3 + -0x13c) = puVar3 + -0x158;
  *(undefined4 *)(puVar3 + -0x140) = 0x11;
  *(undefined4 *)(puVar3 + -0x138) = 2;
  *(undefined4 *)(puVar3 + -0x134) = 4;
  uVar2 = FUN_005f6540(puVar3 + -0x124,0xc,0x784ff01,&DAT_00767584,puVar3 + -0x140);
  *(undefined4 *)(puVar3 + -0xac) = uVar2;
  if (*(int *)(puVar3 + -0xac) != 0) goto LAB_00511c4f;
  *(undefined4 *)(puVar3 + -0xa8) = 10;
  DAT_00941958 = 0;
  do {
    iVar7 = DAT_00941958 * 0x20;
    *(undefined4 *)(puVar3 + -0x124) = 0;
    *(undefined4 *)(puVar3 + -0x138) = 0x80;
    *(undefined4 **)(puVar3 + -0x134) = &DAT_009419e8 + iVar7;
    *(undefined4 *)(puVar3 + -0x130) = 0x80;
    uVar2 = FUN_005fdbd0(puVar3 + -0x124,0xc,0x784ff01,&DAT_00767580,puVar3 + -0x138,&DAT_00795fd0);
    *(undefined4 *)(puVar3 + -0xa4) = uVar2;
    if (*(int *)(puVar3 + -0xa4) != 0) goto LAB_00511278;
    FUN_00511f4c(&DAT_009419e8 + DAT_00941958 * 0x20,0x80);
    DAT_00941958 = DAT_00941958 + 1;
    *(int *)(puVar3 + -0xa8) = *(int *)(puVar3 + -0xa8) + -1;
  } while (0 < *(int *)(puVar3 + -0xa8));
  *(undefined4 *)(puVar3 + -0x124) = 0;
  FUN_005f7950(puVar3 + -0x124,0xc,0x784ff00,&DAT_0076757c,0);
  DAT_0094195c = FUN_00601b80(&DAT_009419e8,0x80);
  FUN_00511f4c(&DAT_009419e8,0x80);
LAB_00511278:
  puVar5 = &DAT_009419e8;
  puVar9 = &DAT_019c656c;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941a68;
  puVar9 = &DAT_019c64ec;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941ae8;
  puVar9 = &DAT_019c646c;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941b68;
  puVar9 = &DAT_019c63ec;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941be8;
  puVar9 = &DAT_019c636c;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941c68;
  puVar9 = &DAT_019c62ec;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941ce8;
  puVar9 = &DAT_019c626c;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941d68;
  puVar9 = &DAT_019c61ec;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941de8;
  puVar9 = &DAT_019c616c;
  for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  puVar5 = &DAT_00941e68;
  puVar9 = &DAT_019c60ec;
  for (iVar7 = 0x20; fVar1 = P2, iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  if (DAT_020b8ea4 == 'X') {
    if (P2 == f_0) {
      *(undefined4 *)(puVar3 + -0x98) = 0;
      goto LAB_005115b7;
    }
    *(undefined2 *)(puVar3 + -300) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x12a) = (ushort)*(undefined4 *)(puVar3 + -300) | 0xc00;
    *(int *)(puVar3 + -0x128) = (int)ROUND(fVar1);
    IP2 = *(int *)(puVar3 + -0x128);
    iVar7 = FUN_005f4660(0x20);
    if (iVar7 != 0) {
      *(undefined4 *)(puVar3 + -0x94) = 0;
      return;
    }
    *(undefined4 *)(puVar3 + -0x90) = 0;
  }
  else {
    *(undefined4 *)(puVar3 + -0x9c) = 0;
    iVar7 = FUN_005f4660(0x20);
    if ((iVar7 == 0) && (DAT_020b8ea4 != 'X')) {
      FUN_005f33c9(puVar3,0x5113b3);
      DAT_0094195c = 1;
      while ((_DAT_020b8ea0 & 0xff) == 0x20) {
        DAT_0094195c = DAT_0094195c + 1;
        FUN_005f46bc(puVar3,0x511423);
        FUN_005f34d1(puVar3,0x511439);
        if (0x3c < DAT_0094195c) {
          *(undefined4 *)(puVar3 + -0x88) = 0;
          goto LAB_0051146b;
        }
        *(undefined4 *)(puVar3 + -0x84) = 0;
      }
      *(undefined4 *)(puVar3 + -0x8c) = 0;
LAB_0051146b:
      if ((_DAT_020b8ea0 & 0xff) == 0x5c) {
        *(undefined4 *)(puVar3 + -0x80) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x7c) = 0x7f;
        DAT_0094195c = 0x80;
        do {
          (&DAT_020b8e9f)[DAT_0094195c] = (&DAT_020b8e9e)[DAT_0094195c];
          DAT_0094195c = DAT_0094195c + -1;
          *(int *)(puVar3 + -0x7c) = *(int *)(puVar3 + -0x7c) + -1;
        } while (0 < *(int *)(puVar3 + -0x7c));
        _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_00767578);
      }
      *(undefined4 *)(puVar3 + -0x78) = 8;
      DAT_0094195c = 1;
      do {
        FUN_005f33c9(puVar3,0x511522);
        DAT_0094195c = DAT_0094195c + 1;
        *(int *)(puVar3 + -0x78) = *(int *)(puVar3 + -0x78) + -1;
      } while (0 < *(int *)(puVar3 + -0x78));
      puVar5 = (undefined4 *)&DAT_020b8ea0;
      puVar9 = &DAT_019c60ec;
      for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar9 = puVar9 + 1;
      }
      puVar5 = &DAT_019c60ec;
      puVar9 = &DAT_00941e68;
      for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar9 = puVar9 + 1;
      }
      IP2 = 9;
      *(undefined4 *)(puVar3 + -0x74) = 0;
      goto LAB_005117d3;
    }
    if (IP2 != 0) {
      *(undefined4 *)(puVar3 + -0x70) = 0;
      goto LAB_00511a3b;
    }
LAB_005115b7:
    DAT_00941954 = thunk_FUN_0059aa20(&IP2);
    if ((IP2 == 0) || (DAT_00941954 == 2)) {
      *(undefined4 *)(puVar3 + -0x6c) = 0;
      return;
    }
    puVar5 = &DAT_019c656c;
    puVar9 = &DAT_009419e8;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c64ec;
    puVar9 = &DAT_00941a68;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c646c;
    puVar9 = &DAT_00941ae8;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c63ec;
    puVar9 = &DAT_00941b68;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c636c;
    puVar9 = &DAT_00941be8;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c62ec;
    puVar9 = &DAT_00941c68;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c626c;
    puVar9 = &DAT_00941ce8;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c61ec;
    puVar9 = &DAT_00941d68;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c616c;
    puVar9 = &DAT_00941de8;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c60ec;
    puVar9 = &DAT_00941e68;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    if (IP2 == 0) {
      puVar5 = (undefined4 *)((int)&DAT_020b90a4 + 1);
      puVar9 = (undefined4 *)&DAT_020b8ea0;
      for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar9 = puVar9 + 1;
      }
      goto LAB_00511abb;
    }
  }
  if (IP2 == 9) {
    *(undefined4 *)(puVar3 + -0x68) = 0;
  }
  else {
    puVar5 = &DAT_009419e8 + IP2 * 0x20;
    puVar9 = &DAT_01b12ae0;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_019c60ec;
    puVar9 = &DAT_009419e8 + IP2 * 0x20;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_01b12ae0;
    puVar9 = &DAT_00941e68;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    puVar5 = &DAT_01b12ae0;
    puVar9 = &DAT_009419e8;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
  }
LAB_005117d3:
  DAT_00941950 = 1;
  do {
    *(undefined4 *)(puVar3 + -100) = 8;
    DAT_00941958 = 2;
    do {
      bVar13 = DAT_00941950 == DAT_00941958;
      if (bVar13) {
        *(undefined4 *)(puVar3 + -0x60) = 0;
      }
      else {
        iVar7 = 0x20;
        piVar6 = &DAT_009419e8 + DAT_00941950 * 0x20;
        piVar10 = &DAT_009419e8 + DAT_00941958 * 0x20;
        do {
          if (iVar7 == 0) break;
          iVar7 = iVar7 + -1;
          bVar13 = *piVar6 == *piVar10;
          piVar6 = piVar6 + 1;
          piVar10 = piVar10 + 1;
        } while (bVar13);
        if (bVar13) {
          FUN_005f34d1(puVar3,0x511860);
        }
        else {
          *(undefined4 *)(puVar3 + -0x5c) = 0;
        }
      }
      *(undefined4 *)(puVar3 + -0x58) = 0;
      DAT_00941958 = DAT_00941958 + 1;
      *(int *)(puVar3 + -100) = *(int *)(puVar3 + -100) + -1;
    } while (0 < *(int *)(puVar3 + -100));
    DAT_00941950 = DAT_00941950 + 1;
    if (8 < DAT_00941950) goto LAB_005118b3;
    *(undefined4 *)(puVar3 + -0x54) = 0;
  } while( true );
joined_r0x00510ca8:
  if (iVar7 < 1) goto LAB_00510d14;
  if ((float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_00941958]] < DAT_01fbb8b8) {
    thunk_FUN_0054d831("Some items already on other page.",0x21);
    goto LAB_00510e1a;
  }
  DAT_00941958 = DAT_00941958 + 1;
  iVar7 = iVar7 + -1;
  goto joined_r0x00510ca8;
LAB_00510d14:
  DAT_00941958 = 1;
  for (iVar7 = ITEM_I; 0 < iVar7; iVar7 = iVar7 + -1) {
    (&ITEM_P2)[(&ITEM_PTR0)[DAT_00941958]] =
         (float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_00941958]] - DAT_01fbb8b8;
    DAT_00941958 = DAT_00941958 + 1;
  }
LAB_00510e06:
  draw_items();
  draw_items();
LAB_00510e1a:
  thunk_FUN_00468df8(&DAT_007675bc);
  _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007675b8);
  return;
LAB_005118b3:
  *(undefined4 *)(puVar3 + -300) = DAT_0078b464;
  *(undefined4 *)(puVar3 + -0x128) = DAT_0078b468;
  *(undefined4 *)(puVar3 + -0x124) = 0;
  FUN_005f33c9(puVar3,0x5118ef);
  FUN_005f33c9(puVar3,0x51190b);
  *(undefined1 **)(puVar3 + -0x13c) = puVar3 + -0x158;
  *(undefined4 *)(puVar3 + -0x140) = 0x11;
  *(undefined4 *)(puVar3 + -0x138) = 2;
  *(undefined4 *)(puVar3 + -0x134) = 4;
  uVar2 = FUN_005f6540(puVar3 + -0x124,0xc,0x784ff01,&DAT_00767584,puVar3 + -0x140);
  *(undefined4 *)(puVar3 + -0x50) = uVar2;
  if (*(int *)(puVar3 + -0x50) != 0) {
LAB_00511c4f:
    *(undefined4 *)(puVar3 + -0x34) = 0;
    return;
  }
  *(undefined4 *)(puVar3 + -0x4c) = 10;
  DAT_00941958 = 0;
  do {
    *(undefined4 *)(puVar3 + -0x124) = 0;
    *(undefined4 *)(puVar3 + -0x138) = 0x80;
    *(undefined4 **)(puVar3 + -0x134) = &DAT_009419e8 + DAT_00941958 * 0x20;
    *(undefined4 *)(puVar3 + -0x130) = 0x80;
    FUN_005fc330(puVar3 + -0x124,0xc,0x784ff00,&DAT_00767580,puVar3 + -0x138,&DAT_00795fe4);
    DAT_00941958 = DAT_00941958 + 1;
    *(int *)(puVar3 + -0x4c) = *(int *)(puVar3 + -0x4c) + -1;
  } while (0 < *(int *)(puVar3 + -0x4c));
  *(undefined4 *)(puVar3 + -0x124) = 0;
  FUN_005f7950(puVar3 + -0x124,0xc,0x784ff00,&DAT_0076757c,0);
LAB_00511a3b:
  if (IP2 < 1) {
    iVar7 = FUN_005f4660(0x20);
    if (iVar7 != 0) {
      *(undefined4 *)(puVar3 + -0x3c) = 0;
      return;
    }
    puVar5 = &DAT_009ae2bc;
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    DAT_020b8f20._0_1_ = 0;
    *(undefined4 *)(puVar3 + -0x38) = 0;
  }
  else {
    *(undefined4 *)(puVar3 + -0x40) = 0;
    puVar5 = &DAT_00941e68;
    puVar9 = (undefined4 *)&DAT_020b8ea0;
    for (iVar7 = 0x20; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar9 = puVar9 + 1;
    }
    *(undefined4 *)(puVar3 + -0x30) = 0;
  }
LAB_00511abb:
  iVar7 = FUN_005f4660(0x20);
  if (iVar7 != 0) {
    FUN_005f33c9(puVar3,0x511c0d);
    FUN_005f34d1(puVar3,0x511c28);
    DAT_0094195c = FUN_00601b80(0x9ae2c3,0x80);
    *(undefined4 *)(puVar3 + -0x28) = 0;
    return;
  }
  *(undefined4 *)(puVar3 + -0x2c) = 0;
LAB_00511aed:
  FUN_005f33c9(puVar3,0x511b0b);
  FUN_005f34d1(puVar3,0x511b26);
  if (DAT_0078b4e0 == 0x4d) {
    DAT_0094195c = FUN_00601cd0(&DAT_020b8ea0,0x80);
  }
  DAT_0094195c = FUN_00601c70(&DAT_020b8ea0,0x80);
  FUN_005f33c9(puVar3,0x511b7f);
  FUN_005f34d1(puVar3,0x511b9a);
  DAT_009ae33c = 0;
  thunk_FUN_0054cd71(&DAT_020b8ea0,0x200,&DAT_0076756c,&DAT_00941958);
  thunk_FUN_00579770(&DAT_00767568,1,&DAT_020b8ea0);
  *(undefined4 *)(puVar3 + -0x24) = 0;
  return;
}


