// FUN_004f8d48 @ 004f8d48 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f8d48(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  byte *pbVar10;
  int iVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  bool bVar14;
  undefined *puStack_c0;
  
  puVar8 = &stack0xfffffffc;
  DAT_01c4ef40 = 0;
  DAT_00900eb0 = PAPER;
  PAPER = 0;
  ITEM_WORDS = 1;
  ITEM_I = 0;
  thunk_FUN_00468df8(&DAT_00766914);
  iVar3 = VEC_STRIDE;
  iVar4 = VEC_BASE;
  iVar5 = DAT_01fbb7b4;
  if (DAT_01fbb7b4 < 0) {
    iVar5 = 0;
  }
  iVar6 = VEC_STRIDE * VEC_LBOUND;
  iVar7 = VEC_LBOUND;
  for (iVar11 = 1; iVar11 <= iVar5; iVar11 = iVar11 + 1) {
    *(undefined4 *)((iVar4 - iVar6) + iVar3 * iVar7) = 0;
    iVar7 = iVar7 + 1;
  }
  *DAT_01fbb844 = 0;
  DAT_0078d890 = 0;
  DAT_0078b690 = 0x73756d2e;
  VEC_N = 1;
  _DAT_01fbb820 = 0;
  puStack_c0 = (undefined *)0x4f8e4f;
  thunk_FUN_00549422();
  if ((undefined *)(_DAT_020b8ea0 & 0xffffff) == &DAT_0059414c) {
    puStack_c0 = (undefined *)0x18;
    thunk_FUN_0054946a("***** PAGE LAYOUT *****");
    DAT_01c58600 = 1;
    DAT_01c58610 = 1;
  }
  else {
    puStack_c0 = (undefined *)0x1c;
    thunk_FUN_0054946a("***** PART EXTRACTION *****");
    DAT_01c58600 = 2;
    DAT_01c58610 = 2;
  }
  puStack_c0 = (undefined *)0x80;
  DAT_01c4c834 = FUN_00601b80(&DAT_01ae2880);
  DAT_01c4c824 = 0;
  DAT_02052740 = 0;
  puStack_c0 = (undefined *)0x4f8efa;
  FUN_005f34d1();
  DAT_0205274c = 0;
  puStack_c0 = (undefined *)0x4f8f0b;
  FUN_004f96fb();
  DAT_01c4c788 = -1;
  if (DAT_01c58600 == 2) {
    *(undefined4 *)(puVar8 + -0x6c) = 0;
LAB_004f8f4a:
    puStack_c0 = (undefined *)0x4f8f68;
    FUN_005f33c9();
    puStack_c0 = (undefined *)0x4f8f83;
    FUN_005f34d1();
    DAT_00795028 = 1;
    if (-1 < DAT_00795024) {
      DAT_00795038 = DAT_00795024;
      puVar9 = &DAT_00900f54;
      puVar12 = &DAT_009ae2bc;
      for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar12 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar12 = puVar12 + 1;
      }
    }
    puStack_c0 = (undefined *)0x4f8fd8;
    FUN_005f33c9();
    puStack_c0 = (undefined *)0x4f8ff3;
    FUN_005f34d1();
    puStack_c0 = &DAT_00900ea8;
    DAT_01c4c828 = thunk_FUN_0059cb70(&DAT_00795028);
    if (DAT_01c4c828 != 1) {
      if (DAT_01c4c828 == 2) goto LAB_004f9678;
      if (DAT_01c4c828 == 3) {
        DAT_01c58600 = 3;
        goto LAB_004f9436;
      }
    }
    DAT_01c4c788 = -1;
    puStack_c0 = (undefined *)0x200;
    FUN_004f9e92(&DAT_009ae2bc);
    DAT_01c4c830 = DAT_00795028;
    DAT_01ba0d80 = DAT_0079502c;
    puStack_c0 = (undefined *)0x4f908e;
    FUN_005f33c9();
    puStack_c0 = (undefined *)0x4f90a9;
    FUN_005f34d1();
    puStack_c0 = (undefined *)0x4f90ca;
    FUN_005f34d1();
    puStack_c0 = (undefined *)0x4f90d3;
    thunk_FUN_00518448();
    if (P1 <= f_0) {
      *(undefined4 *)(puVar8 + -0x28) = 0;
      goto LAB_004f9678;
    }
    thunk_FUN_0054c590(&P1,&DAT_01b11800,&DAT_007668d0);
    bVar14 = (undefined1 *)0xfffffffb < &puStack_c0;
    puVar9 = &DAT_009ae2bc;
    puVar12 = (undefined4 *)&DAT_020b8ea0;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar12 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar12 = puVar12 + 1;
    }
    puVar9 = &DAT_009ae2bc;
    puVar12 = &DAT_00900f54;
    for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar12 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar12 = puVar12 + 1;
    }
    DAT_00795024 = DAT_00795038;
    iVar4 = 1;
    pbVar10 = (byte *)&DAT_020b8ea0;
    pbVar13 = (byte *)0x7668cc;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar2 = *pbVar13;
      bVar1 = *pbVar10;
      bVar14 = bVar1 < bVar2;
      pbVar10 = pbVar10 + 1;
      pbVar13 = pbVar13 + 1;
    } while (bVar1 == bVar2);
    if (bVar14) {
      puStack_c0 = (undefined *)0x4f9176;
      FUN_005f34d1();
    }
    thunk_FUN_005147b8(&DAT_00795038);
    if ((DAT_0078b4e0 != 0x2d) && (ITEM_WORDS != -1)) {
      DAT_01ba0d84 = 0;
      DAT_01c58600 = 0;
      *(undefined4 *)(puVar8 + -0x20) = 0;
      goto LAB_004f92c0;
    }
    puStack_c0 = (undefined *)0x4f91d8;
    FUN_005f33c9();
    puStack_c0 = (undefined *)0x4f91f3;
    FUN_005f34d1();
    DAT_01c58600 = 0;
    *(undefined4 *)(puVar8 + -0x24) = 0;
  }
  else {
    if (DAT_01c58600 == 1) {
LAB_004f920b:
      DAT_009ae2bc._0_1_ = 0;
      iVar4 = thunk_FUN_0059a520(&DAT_00795028);
      if (iVar4 == 2) {
        *(undefined4 *)(puVar8 + -0x68) = 0;
        goto LAB_004f9678;
      }
      DAT_01c4c848 = 0;
      if (DAT_0079502c != 0) {
        DAT_01c58600 = 3;
        *(undefined4 *)(puVar8 + -100) = 0;
        goto LAB_004f9436;
      }
      DAT_01c4c788 = 0;
      DAT_01c4c834 = DAT_00795028 + 1;
      puVar9 = &DAT_009ae2bc;
      puVar12 = (undefined4 *)&DAT_020b8ea0;
      for (iVar4 = 0x80; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar12 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar12 = puVar12 + 1;
      }
      puStack_c0 = (undefined *)0x200;
      FUN_004f9e92(&DAT_009ae2bc);
      thunk_FUN_00537938(&DAT_01c4c834);
      *(undefined4 *)(puVar8 + -0x60) = 0;
LAB_004f92c0:
      while (thunk_FUN_0050f5c8(&DAT_00900eac), DAT_00900eac != 1) {
        if (ITEM_WORDS < 0) {
          *(undefined4 *)(puVar8 + -0x4c) = 0;
          goto LAB_004f9678;
        }
        if (DAT_01c4c788 < 1) {
          *(undefined4 *)(puVar8 + -0x48) = 0;
          goto LAB_004f9436;
        }
        puStack_c0 = (undefined *)0x4f9317;
        FUN_005f33c9();
        puStack_c0 = (undefined *)0x4f9333;
        FUN_005f33c9();
        puStack_c0 = (undefined *)0x4f934e;
        FUN_005f34d1();
        *(int *)(puVar8 + -0x44) = DAT_01c4c848;
        DAT_01c4c828 = 1;
        iVar4 = DAT_01c4c848;
        while (0 < iVar4) {
          puVar9 = &DAT_01c4c7a0;
          puVar12 = (undefined4 *)(&DAT_01c4eec4 + DAT_01c4c828 * 0x80);
          for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar12 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar12 = puVar12 + 1;
          }
          DAT_01c4c7ac = DAT_01c4c7ac + '\x01';
          if (DAT_01c4c7ac < '[') {
            *(undefined4 *)(puVar8 + -0x40) = 0;
          }
          else {
            DAT_01c4c7ac = 'A';
            DAT_01c4c7ab = DAT_01c4c7ab + '\x01';
          }
          *(undefined4 *)(puVar8 + -0x3c) = 0;
          DAT_01c4c828 = DAT_01c4c828 + 1;
          *(int *)(puVar8 + -0x44) = *(int *)(puVar8 + -0x44) + -1;
          iVar4 = *(int *)(puVar8 + -0x44);
        }
        DAT_01c4c788 = -1;
        *(undefined4 *)(puVar8 + -0x38) = 0;
        DAT_01c4ef40 = DAT_01c4c848;
      }
      *(undefined4 *)(puVar8 + -0x50) = 0;
      goto LAB_004f9678;
    }
    if (DAT_01c58600 == 2) goto LAB_004f8f4a;
    if (DAT_01c58600 != 3) goto LAB_004f920b;
LAB_004f9436:
    _DAT_00900ea4 = f_0;
    puStack_c0 = (undefined *)0x4f9447;
    thunk_FUN_004fb990();
    if (DAT_0078b4e0 == 0x2d) {
      *(undefined4 *)(puVar8 + -0x1c) = 0;
      goto LAB_004f9678;
    }
  }
  *(undefined4 *)(puVar8 + -0x8c) = 0;
  *(undefined4 *)(puVar8 + -0xa8) = 9;
  *(char **)(puVar8 + -0xa4) = "files.tmp";
  *(undefined4 *)(puVar8 + -0xa0) = 7;
  *(char **)(puVar8 + -0x9c) = "unknown";
  *(undefined4 *)(puVar8 + -0x98) = 2;
  FUN_005f6540(puVar8 + -0x8c,0x1b,0x784ff00,&DAT_00766898,puVar8 + -0xa8);
  *(undefined4 *)(puVar8 + -0x8c) = 0;
  *(undefined4 *)(puVar8 + -0x98) = 6;
  *(char **)(puVar8 + -0x94) = "delete";
  FUN_005f7950(puVar8 + -0x8c,0x1b,0x784ff00,&DAT_00766888,puVar8 + -0x98);
  *(undefined4 *)(puVar8 + -0x8c) = 0;
  *(undefined4 *)(puVar8 + -0xa8) = 7;
  *(char **)(puVar8 + -0xa4) = "pts.tmp";
  *(undefined4 *)(puVar8 + -0xa0) = 7;
  *(char **)(puVar8 + -0x9c) = "unknown";
  *(undefined4 *)(puVar8 + -0x98) = 2;
  FUN_005f6540(puVar8 + -0x8c,0x1b,0x784ff00,&DAT_00766898,puVar8 + -0xa8);
  *(undefined4 *)(puVar8 + -0x8c) = 0;
  *(undefined4 *)(puVar8 + -0x98) = 6;
  *(char **)(puVar8 + -0x94) = "delete";
  FUN_005f7950(puVar8 + -0x8c,0x1b,0x784ff00,&DAT_00766888,puVar8 + -0x98);
  *(undefined4 *)(puVar8 + -0x8c) = 0;
  *(undefined4 *)(puVar8 + -0xa8) = 8;
  *(char **)(puVar8 + -0xa4) = "pts2.tmppts.tmp";
  *(undefined4 *)(puVar8 + -0xa0) = 7;
  *(char **)(puVar8 + -0x9c) = "unknown";
  *(undefined4 *)(puVar8 + -0x98) = 2;
  FUN_005f6540(puVar8 + -0x8c,0x1b,0x784ff00,&DAT_00766898,puVar8 + -0xa8);
  *(undefined4 *)(puVar8 + -0x8c) = 0;
  *(undefined4 *)(puVar8 + -0x98) = 6;
  *(char **)(puVar8 + -0x94) = "delete";
  FUN_005f7950(puVar8 + -0x8c,0x1b,0x784ff00,&DAT_00766888,puVar8 + -0x98);
LAB_004f9678:
  puStack_c0 = (undefined *)0x4f9696;
  FUN_005f33c9(puVar8);
  puStack_c0 = (undefined *)0x4f96b1;
  FUN_005f34d1(puVar8);
  puStack_c0 = (undefined *)0x4f96d2;
  FUN_005f34d1(puVar8);
  thunk_FUN_00468df8(&DAT_00766858);
  PAPER = DAT_00900eb0;
  return;
}


