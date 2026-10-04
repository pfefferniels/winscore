// FUN_00488a8d @ 00488a8d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0048e06b) */
/* WARNING: Removing unreachable block (ram,0x00488e62) */
/* WARNING: Removing unreachable block (ram,0x00488f5c) */
/* WARNING: Removing unreachable block (ram,0x00489919) */
/* WARNING: Removing unreachable block (ram,0x0048981f) */
/* WARNING: Removing unreachable block (ram,0x0048a039) */
/* WARNING: Removing unreachable block (ram,0x0048a133) */
/* WARNING: Removing unreachable block (ram,0x0048ae52) */
/* WARNING: Removing unreachable block (ram,0x0048ad58) */
/* WARNING: Removing unreachable block (ram,0x0048b5bb) */
/* WARNING: Removing unreachable block (ram,0x0048b6b5) */
/* WARNING: Removing unreachable block (ram,0x0048c462) */
/* WARNING: Removing unreachable block (ram,0x0048c368) */
/* WARNING: Removing unreachable block (ram,0x0048cc52) */
/* WARNING: Removing unreachable block (ram,0x0048cd4c) */
/* WARNING: Removing unreachable block (ram,0x0048d722) */
/* WARNING: Removing unreachable block (ram,0x0048d628) */
/* WARNING: Removing unreachable block (ram,0x0048dc43) */
/* WARNING: Removing unreachable block (ram,0x0048dd3f) */
/* WARNING: Removing unreachable block (ram,0x0048d15e) */
/* WARNING: Removing unreachable block (ram,0x0048d064) */
/* WARNING: Removing unreachable block (ram,0x0048c850) */
/* WARNING: Removing unreachable block (ram,0x0048c94a) */
/* WARNING: Removing unreachable block (ram,0x0048bac2) */
/* WARNING: Removing unreachable block (ram,0x0048b9c8) */
/* WARNING: Removing unreachable block (ram,0x0048b15a) */
/* WARNING: Removing unreachable block (ram,0x0048b254) */
/* WARNING: Removing unreachable block (ram,0x0048a5c1) */
/* WARNING: Removing unreachable block (ram,0x0048a4c7) */
/* WARNING: Removing unreachable block (ram,0x00489c2f) */
/* WARNING: Removing unreachable block (ram,0x00489d29) */
/* WARNING: Removing unreachable block (ram,0x00489519) */
/* WARNING: Removing unreachable block (ram,0x0048941f) */
/* WARNING: Removing unreachable block (ram,0x0048ea1e) */
/* WARNING: Removing unreachable block (ram,0x0048eb14) */
/* WARNING: Removing unreachable block (ram,0x0048e165) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00488a8d(void)

{
  bool bVar1;
  uint3 uVar2;
  uint3 uVar3;
  float fVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined2 in_FPUControlWord;
  undefined1 *puVar12;
  int local_dc;
  int local_d8;
  int local_d4;
  undefined4 *local_d0;
  undefined *local_cc;
  uint local_c8;
  int local_c4;
  undefined4 local_c0 [35];
  undefined4 uStack_34;
  
  puVar11 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  puVar12 = &stack0xfffffffc;
  if (DAT_020b90a2 == '\\') {
    FUN_00490cce(&P2,&P3);
  }
  else {
    if (DAT_020b90a2 < 'a') {
      DAT_020b90a2 = DAT_020b90a2 + ' ';
    }
    if (DAT_020b90a2 == 'x') {
      DAT_0082901c = thunk_FUN_00595680("000.mus",DAT_0082902c,&ITEM_P1);
    }
    else if (DAT_020b90a3 == 'x') {
      local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      VIEW_DX = (int)ROUND((float)VIEW_DX + P2);
      local_c4 = VIEW_DX;
      thunk_FUN_0055036f(&DAT_00829018,&DAT_00829014,&DAT_00829010,&DAT_0082900c);
      _DAT_00829008 = (int)ROUND(_DAT_00829018 - _DAT_00829014);
      local_c8 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      _DAT_00829004 = (int)ROUND(_DAT_0082900c - _DAT_00829010);
      local_c0[0] = 0;
      local_d4 = 0x200;
      local_d0 = &DAT_009ae2bc;
      local_cc = &DAT_00829004;
      local_c4 = _DAT_00829004;
      FUN_005f34f0(local_c0,0x784ff00,&DAT_00762c1c,&local_d4,&DAT_00791540);
      local_cc = &DAT_00829008;
      FUN_005f3960(local_c0,&DAT_00762c18,&local_cc);
      for (iVar7 = 1; iVar7 < 0x33; iVar7 = iVar7 + 1) {
        *(undefined4 *)(iVar7 * 4 + 0x82963c) = *(undefined4 *)(&P0 + iVar7 * 4);
      }
      draw_items();
      for (iVar7 = 1; iVar7 < 0x33; iVar7 = iVar7 + 1) {
        *(undefined4 *)(&P0 + iVar7 * 4) = *(undefined4 *)(iVar7 * 4 + 0x82963c);
      }
    }
    else {
      DAT_00829024 = DAT_020b90a2;
      uVar2 = (uint3)((uint)DAT_00829084 >> 8);
      uVar3 = (uint3)((uint)DAT_00829064 >> 8);
      switch(DAT_020b90a2) {
      default:
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x61;
        DAT_00829022 = 0x73;
        _DAT_00829028 = (undefined *)0x63;
        DAT_00829030 = 0x3a;
        DAT_0082902c = 0x6d;
        DAT_00829110 = &DAT_006d3a63;
        puVar10 = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d4 = 1;
        for (local_d8 = 1; local_d8 < 5; local_d8 = local_d8 + 1) {
          *(undefined1 *)(local_d8 + local_c8 + -1) =
               *(undefined1 *)((int)&DAT_0082901c + local_d4 + 3);
          local_d4 = local_d4 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        local_c4 = local_c8;
        while (bVar1) {
          local_c4 = local_c4 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c4 = local_c4 - iVar7;
        local_cc = (undefined *)0x1;
        for (local_d0 = (undefined4 *)0x1; (int)local_d0 < 0x101;
            local_d0 = (undefined4 *)((int)local_d0 + 1)) {
          *(undefined4 *)((int)local_d0 * 4 + local_c4 + -4) =
               *(undefined4 *)((int)local_cc * 4 + 0x82910c);
          local_cc = local_cc + 1;
        }
        *(int *)(local_c4 + -4) = local_c4;
        *(uint *)(local_c4 + -8) = local_c8;
        *(undefined4 *)(local_c4 + -0xc) = 0x48ebe4;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d4 = 1;
        for (local_d8 = 1; puVar5 = DAT_00829058, local_d8 < 5; local_d8 = local_d8 + 1) {
          puVar10[local_d4 - iVar7] = *(undefined1 *)(local_d8 + local_c8 + -1);
          local_d4 = local_d4 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_cc = (undefined *)0x1;
        for (local_d0 = (undefined4 *)0x1; (int)local_d0 < 0x101;
            local_d0 = (undefined4 *)((int)local_d0 + 1)) {
          *(undefined4 *)((int)puVar5 + ((int)local_cc * 4 - iVar7)) =
               *(undefined4 *)((int)local_d0 * 4 + local_c4 + -4);
          local_cc = local_cc + 1;
        }
        break;
      case 'b':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829021 = 0x62;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x489030;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        _DAT_00790b84 =
             *(undefined4 *)((int)DAT_00829058 + (DAT_00829070 - DAT_00829070 * DAT_00829074));
        _DAT_00790b88 =
             *(undefined4 *)((int)DAT_00829058 + (DAT_00829070 * 2 - DAT_00829070 * DAT_00829074));
        FUN_005f34d1(&stack0xfffffffc,&LAB_00489196);
        iVar7 = DAT_00829070;
        iVar9 = (int)DAT_00829058 + (DAT_00829070 - DAT_00829070 * DAT_00829074);
        DAT_0082902c = 7;
        *(undefined4 *)(puVar11 + -0xbc) = 0;
        *(undefined4 *)(puVar11 + -0xe0) = 0x200;
        *(undefined4 **)(puVar11 + -0xdc) = &DAT_009ae2bc;
        *(undefined4 *)(puVar11 + -0xd8) = 1;
        *(int *)(puVar11 + -0xd4) = iVar9;
        *(undefined4 *)(puVar11 + -0xd0) = 1;
        *(undefined4 *)(puVar11 + -0xcc) = 6;
        *(int *)(puVar11 + -200) = iVar7;
        FUN_005f34f0(puVar11 + -0xbc,0x784ff00,&DAT_00762c10,puVar11 + -0xe0,&DAT_00791554);
        *(undefined4 *)(puVar11 + -0x84) = 0;
        break;
      case 'c':
        DAT_00829000 = DAT_00829000 + 1;
        if (0x12 < (int)DAT_00829000) {
          DAT_00829000 = (undefined *)0x0;
        }
        if (IP1 != 0) {
          DAT_00829000 = (undefined *)0xa;
        }
        if (P2 != f_0) {
          DAT_00829000 = (undefined *)(int)ROUND(P2);
        }
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 99;
        DAT_00829022 = 0x75;
        DAT_00829110 = DAT_00829000;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x4895eb;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'd':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 100;
        DAT_00829022 = 0x69;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x4899ed;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        _DAT_00829028 = DAT_00829110;
        break;
      case 'e':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x65;
        DAT_00829022 = 0x65;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x489dfd;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'f':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x66;
        DAT_00829022 = 0x6f;
        DAT_00829110 = (undefined *)0x0;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48a207;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        _DAT_00829028 = DAT_00829110;
        break;
      case 'g':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x67;
        DAT_00829022 = 0x6f;
        DAT_00829110 = (undefined *)(int)ROUND(P2);
        DAT_00829114 = (int)ROUND(P3);
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48a695;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'h':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x68;
        DAT_00829022 = 0x70;
        FUN_005f33c9(&stack0xfffffffc,&LAB_0048a8ac);
        FUN_005f34d1(puVar8,&LAB_0048a8c7);
        *(undefined4 *)(puVar8 + -0x6c) = 0x19;
        DAT_0082902c = 1;
        do {
          *(undefined4 *)(DAT_0082902c * 4 + 0x82910c) =
               *(undefined4 *)(DAT_0082902c * 4 + 0x8290a4);
          DAT_0082902c = DAT_0082902c + 1;
          *(int *)(puVar8 + -0x6c) = *(int *)(puVar8 + -0x6c) + -1;
        } while (0 < *(int *)(puVar8 + -0x6c));
        *(undefined1 **)(puVar8 + -0xc0) = &stack0xfffffefc;
        puVar10 = DAT_00829078;
        *(int *)(puVar8 + -0xdc) = DAT_00829090;
        *(int *)(puVar8 + -0xe0) = DAT_00829094;
        iVar7 = (DAT_0082908c + DAT_00829094) - *(int *)(puVar8 + -0xe0);
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        *(int *)(puVar8 + -0xe4) = iVar7;
        iVar7 = DAT_00829090 * DAT_00829094;
        puVar11 = puVar8 + -0x100;
        for (uVar6 = *(int *)(puVar8 + -0xe4) + 7U & 0xfffffff8; 0x1000 < (int)uVar6;
            uVar6 = uVar6 - 0x1000) {
          puVar11 = puVar11 + -0x1000;
        }
        iVar9 = (int)puVar11 - uVar6;
        *(int *)(puVar8 + -200) = iVar9;
        *(int *)(puVar8 + -0xc0) = iVar9;
        *(undefined4 *)(puVar8 + -0xd4) = *(undefined4 *)(puVar8 + -0xe0);
        *(undefined4 *)(puVar8 + -0xd8) = 1;
        while (puVar5 = DAT_00829058, *(int *)(puVar8 + -0xd8) <= *(int *)(puVar8 + -0xe4)) {
          *(undefined1 *)(*(int *)(puVar8 + -0xd8) + *(int *)(puVar8 + -200) + -1) =
               puVar10[*(int *)(puVar8 + -0xd4) * *(int *)(puVar8 + -0xdc) - iVar7];
          *(int *)(puVar8 + -0xd4) = *(int *)(puVar8 + -0xd4) + 1;
          *(int *)(puVar8 + -0xd8) = *(int *)(puVar8 + -0xd8) + 1;
        }
        *(int *)(puVar8 + -0xe8) = DAT_00829070;
        *(int *)(puVar8 + -0xec) = DAT_00829074;
        iVar7 = (DAT_0082906c + DAT_00829074) - *(int *)(puVar8 + -0xec);
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        *(int *)(puVar8 + -0xf0) = iVar7;
        iVar7 = DAT_00829070 * DAT_00829074;
        for (uVar6 = *(int *)(puVar8 + -0xf0) * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar6;
            uVar6 = uVar6 - 0x1000) {
          iVar9 = iVar9 + -0x1000;
        }
        iVar9 = iVar9 - uVar6;
        *(int *)(puVar8 + -0xc4) = iVar9;
        *(int *)(puVar8 + -0xc0) = iVar9;
        *(undefined4 *)(puVar8 + -0xcc) = *(undefined4 *)(puVar8 + -0xec);
        *(undefined4 *)(puVar8 + -0xd0) = 1;
        while (*(int *)(puVar8 + -0xd0) <= *(int *)(puVar8 + -0xf0)) {
          *(undefined4 *)(*(int *)(puVar8 + -0xd0) * 4 + *(int *)(puVar8 + -0xc4) + -4) =
               *(undefined4 *)
                ((int)puVar5 + (*(int *)(puVar8 + -0xcc) * *(int *)(puVar8 + -0xe8) - iVar7));
          *(int *)(puVar8 + -0xcc) = *(int *)(puVar8 + -0xcc) + 1;
          *(int *)(puVar8 + -0xd0) = *(int *)(puVar8 + -0xd0) + 1;
        }
        *(undefined4 *)(iVar9 + -4) = *(undefined4 *)(puVar8 + -0xc4);
        *(undefined4 *)(iVar9 + -8) = *(undefined4 *)(puVar8 + -200);
        *(undefined4 *)(iVar9 + -0xc) = 0x48ab24;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        *(undefined4 *)(puVar8 + -0xd4) = *(undefined4 *)(puVar8 + -0xe0);
        *(undefined4 *)(puVar8 + -0xd8) = 1;
        while (puVar5 = DAT_00829058, *(int *)(puVar8 + -0xd8) <= *(int *)(puVar8 + -0xe4)) {
          puVar10[*(int *)(puVar8 + -0xd4) * *(int *)(puVar8 + -0xdc) - iVar7] =
               *(undefined1 *)(*(int *)(puVar8 + -0xd8) + *(int *)(puVar8 + -200) + -1);
          *(int *)(puVar8 + -0xd4) = *(int *)(puVar8 + -0xd4) + 1;
          *(int *)(puVar8 + -0xd8) = *(int *)(puVar8 + -0xd8) + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        *(undefined4 *)(puVar8 + -0xcc) = *(undefined4 *)(puVar8 + -0xec);
        *(undefined4 *)(puVar8 + -0xd0) = 1;
        while (*(int *)(puVar8 + -0xd0) <= *(int *)(puVar8 + -0xf0)) {
          *(undefined4 *)
           ((int)puVar5 + (*(int *)(puVar8 + -0xcc) * *(int *)(puVar8 + -0xe8) - iVar7)) =
               *(undefined4 *)(*(int *)(puVar8 + -0xd0) * 4 + *(int *)(puVar8 + -0xc4) + -4);
          *(int *)(puVar8 + -0xcc) = *(int *)(puVar8 + -0xcc) + 1;
          *(int *)(puVar8 + -0xd0) = *(int *)(puVar8 + -0xd0) + 1;
        }
        *(undefined4 *)(puVar8 + -0x68) = 0;
        break;
      case 'i':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x69;
        DAT_00829022 = 0x6d;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48af26;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        _DAT_00829028 = DAT_00829110;
        break;
      case 'j':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829021 = 0x6a;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48b328;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'k':
        break;
      case 'l':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x6c;
        DAT_00829022 = 0x61;
        DAT_00829110 = (undefined *)0x0;
        DAT_00829114 = 0;
        _DAT_00829028 = (undefined *)0x61;
        DAT_00829030 = 0x62;
        DAT_0082902c = 99;
        _DAT_00829118 = (undefined *)0x636261;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48b789;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'm':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x6d;
        DAT_00829022 = 0x6f;
        DAT_00829110 = (undefined *)0xffffffff;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48bb96;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'n':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x6e;
        DAT_00829022 = 0x61;
        FUN_005f33c9(&stack0xfffffffc,&LAB_0048bdad);
        FUN_005f34d1(puVar10,&LAB_0048bdc8);
        thunk_FUN_0054c8e5(&DAT_020b90a0,1,&DAT_00828ffc);
        iVar7 = DAT_00828ffc / 4 + 1;
        *(int *)(puVar10 + -0x50) = iVar7;
        DAT_0082902c = 1;
        while (0 < iVar7) {
          DAT_0082901c = DAT_0082901c + 1;
          *(undefined4 *)(DAT_0082902c * 4 + 0x82910c) =
               *(undefined4 *)(&DAT_020b909c + DAT_0082902c * 4);
          DAT_0082902c = DAT_0082902c + 1;
          *(int *)(puVar10 + -0x50) = *(int *)(puVar10 + -0x50) + -1;
          iVar7 = *(int *)(puVar10 + -0x50);
        }
        *(undefined1 **)(puVar10 + -0xc0) = &stack0xfffffefc;
        puVar8 = DAT_00829078;
        *(int *)(puVar10 + -0xdc) = DAT_00829090;
        *(int *)(puVar10 + -0xe0) = DAT_00829094;
        iVar7 = (DAT_0082908c + DAT_00829094) - *(int *)(puVar10 + -0xe0);
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        *(int *)(puVar10 + -0xe4) = iVar7;
        iVar7 = DAT_00829090 * DAT_00829094;
        puVar11 = puVar10 + -0x100;
        for (uVar6 = *(int *)(puVar10 + -0xe4) + 7U & 0xfffffff8; 0x1000 < (int)uVar6;
            uVar6 = uVar6 - 0x1000) {
          puVar11 = puVar11 + -0x1000;
        }
        iVar9 = (int)puVar11 - uVar6;
        *(int *)(puVar10 + -200) = iVar9;
        *(int *)(puVar10 + -0xc0) = iVar9;
        *(undefined4 *)(puVar10 + -0xd4) = *(undefined4 *)(puVar10 + -0xe0);
        *(undefined4 *)(puVar10 + -0xd8) = 1;
        while (puVar5 = DAT_00829058, *(int *)(puVar10 + -0xd8) <= *(int *)(puVar10 + -0xe4)) {
          *(undefined1 *)(*(int *)(puVar10 + -0xd8) + *(int *)(puVar10 + -200) + -1) =
               puVar8[*(int *)(puVar10 + -0xd4) * *(int *)(puVar10 + -0xdc) - iVar7];
          *(int *)(puVar10 + -0xd4) = *(int *)(puVar10 + -0xd4) + 1;
          *(int *)(puVar10 + -0xd8) = *(int *)(puVar10 + -0xd8) + 1;
        }
        *(int *)(puVar10 + -0xe8) = DAT_00829070;
        *(int *)(puVar10 + -0xec) = DAT_00829074;
        iVar7 = (DAT_0082906c + DAT_00829074) - *(int *)(puVar10 + -0xec);
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        *(int *)(puVar10 + -0xf0) = iVar7;
        iVar7 = DAT_00829070 * DAT_00829074;
        for (uVar6 = *(int *)(puVar10 + -0xf0) * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar6;
            uVar6 = uVar6 - 0x1000) {
          iVar9 = iVar9 + -0x1000;
        }
        iVar9 = iVar9 - uVar6;
        *(int *)(puVar10 + -0xc4) = iVar9;
        *(int *)(puVar10 + -0xc0) = iVar9;
        *(undefined4 *)(puVar10 + -0xcc) = *(undefined4 *)(puVar10 + -0xec);
        *(undefined4 *)(puVar10 + -0xd0) = 1;
        while (*(int *)(puVar10 + -0xd0) <= *(int *)(puVar10 + -0xf0)) {
          *(undefined4 *)(*(int *)(puVar10 + -0xd0) * 4 + *(int *)(puVar10 + -0xc4) + -4) =
               *(undefined4 *)
                ((int)puVar5 + (*(int *)(puVar10 + -0xcc) * *(int *)(puVar10 + -0xe8) - iVar7));
          *(int *)(puVar10 + -0xcc) = *(int *)(puVar10 + -0xcc) + 1;
          *(int *)(puVar10 + -0xd0) = *(int *)(puVar10 + -0xd0) + 1;
        }
        *(undefined4 *)(iVar9 + -4) = *(undefined4 *)(puVar10 + -0xc4);
        *(undefined4 *)(iVar9 + -8) = *(undefined4 *)(puVar10 + -200);
        *(undefined4 *)(iVar9 + -0xc) = 0x48c068;
        thunk_FUN_00597d30();
        puVar8 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        *(undefined4 *)(puVar10 + -0xd4) = *(undefined4 *)(puVar10 + -0xe0);
        *(undefined4 *)(puVar10 + -0xd8) = 1;
        while (puVar5 = DAT_00829058, *(int *)(puVar10 + -0xd8) <= *(int *)(puVar10 + -0xe4)) {
          puVar8[*(int *)(puVar10 + -0xd4) * *(int *)(puVar10 + -0xdc) - iVar7] =
               *(undefined1 *)(*(int *)(puVar10 + -0xd8) + *(int *)(puVar10 + -200) + -1);
          *(int *)(puVar10 + -0xd4) = *(int *)(puVar10 + -0xd4) + 1;
          *(int *)(puVar10 + -0xd8) = *(int *)(puVar10 + -0xd8) + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        *(undefined4 *)(puVar10 + -0xcc) = *(undefined4 *)(puVar10 + -0xec);
        *(undefined4 *)(puVar10 + -0xd0) = 1;
        while (*(int *)(puVar10 + -0xd0) <= *(int *)(puVar10 + -0xf0)) {
          *(undefined4 *)
           ((int)puVar5 + (*(int *)(puVar10 + -0xcc) * *(int *)(puVar10 + -0xe8) - iVar7)) =
               *(undefined4 *)(*(int *)(puVar10 + -0xd0) * 4 + *(int *)(puVar10 + -0xc4) + -4);
          *(int *)(puVar10 + -0xcc) = *(int *)(puVar10 + -0xcc) + 1;
          *(int *)(puVar10 + -0xd0) = *(int *)(puVar10 + -0xd0) + 1;
        }
        *(undefined4 *)(puVar10 + -0x4c) = 0;
        break;
      case 'o':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x6f;
        DAT_00829022 = 0x6c;
        DAT_00828ff8 = 1;
        DAT_00828ff4 = 0x100;
        _DAT_00828ff0 = 0x10000;
        _DAT_00828fec = 0x80;
        DAT_00828fe8 = 0;
        DAT_00828fe4 = 0x800000;
        _DAT_00828fe0 = 0x4b000080;
        DAT_00829110 = &DAT_00800080;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48c536;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        DAT_00828fdc = DAT_00829110;
        DAT_00828fe4 = (int)DAT_00829110 / 0x10000;
        DAT_00828fe8 = ((int)DAT_00829110 % 0x10000) / 0x100;
        _DAT_00828fec = (int)DAT_00829110 - (DAT_00828fe4 * 0x10000 + DAT_00828fe8 * 0x100);
        break;
      case 'p':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x70;
        DAT_00829022 = 0x6f;
        DAT_00829110 = (undefined *)(int)ROUND(P2);
        DAT_00829114 = (int)ROUND(P3);
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48ca1e;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'q':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x71;
        DAT_00829022 = 0x71;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48ce20;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'r':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x72;
        DAT_00829022 = 0x69;
        DAT_00829110 = (undefined *)0x0;
        DAT_00829114 = 0;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48d232;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 's':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x73;
        DAT_00829022 = 99;
        DAT_00828fd8 = (undefined *)(int)ROUND(P2);
        DAT_00828fd4 = (int)ROUND(P3);
        DAT_00828fd0 = (undefined *)(int)ROUND(P4);
        DAT_00828fcc = (int)ROUND(P5);
        DAT_00828fc8 = (int)ROUND(P6);
        DAT_00828fc4 = (int)ROUND(P7);
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48d7f6;
        DAT_00829110 = DAT_00828fd8;
        DAT_00829114 = DAT_00828fd4;
        _DAT_00829118 = DAT_00828fd0;
        _DAT_0082911c = DAT_00828fcc;
        _DAT_00829120 = DAT_00828fc8;
        _DAT_00829124 = DAT_00828fc4;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 't':
        break;
      case 'u':
        _DAT_00828fc0 = thunk_FUN_0059cfa0();
        thunk_FUN_005c6a00();
        iVar7 = 1;
        for (iVar9 = 1; iVar9 < 0x9d; iVar9 = iVar9 + 1) {
          *(undefined1 *)((int)&DAT_0082901c + iVar7 + 3) = 0;
          iVar7 = iVar7 + 1;
        }
        DAT_00829020 = 6;
        _DAT_00829060 = 0xff000000;
        DAT_00829064 = 0;
        _DAT_00829068 = 0x81004046;
        DAT_0082906c = 0;
        DAT_00829070 = -0x7fffc000;
        DAT_00829074 = 0x60;
        DAT_00829078 = (undefined1 *)0x81004846;
        _DAT_0082907c = 0;
        _DAT_00829080 = 0x8000484d;
        DAT_00829084 = 0x60;
        _DAT_00829088 = 0x80004800;
        DAT_0082908c = 0xc4;
        _DAT_00828fbc = 0x1c;
        uStack_34 = 0;
        thunk_FUN_005c69a0(&DAT_00828fbc,&DAT_00829020);
        break;
      case 'v':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x76;
        DAT_00829022 = 0x65;
        _DAT_00829028 = (undefined *)0x63;
        DAT_00829030 = 0x3a;
        DAT_0082902c = 0x6d;
        DAT_00829110 = &DAT_006d3a63;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48de13;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        break;
      case 'w':
        break;
      case 'x':
        break;
      case 'y':
        break;
      case 'z':
        DAT_00829084._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x7a;
        DAT_00829022 = 0x61;
        local_cc = &stack0xfffffefc;
        iVar7 = 8;
        bVar1 = false;
        while (bVar1) {
          local_cc = local_cc + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_cc = local_cc + -iVar7;
        local_d8 = 1;
        for (local_dc = 1; local_dc < 5; local_dc = local_dc + 1) {
          local_cc[local_dc + -1] = *(undefined1 *)((int)&DAT_0082901c + local_d8 + 3);
          local_d8 = local_d8 + 1;
        }
        iVar7 = 0x400;
        bVar1 = false;
        puVar10 = local_cc;
        while (bVar1) {
          puVar10 = puVar10 + -0x1000;
          iVar7 = iVar7 + -0x1000;
          bVar1 = 0x1000 < iVar7;
        }
        local_c8 = (int)puVar10 - iVar7;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)(local_d4 * 4 + local_c8 + -4) =
               *(undefined4 *)((int)local_d0 * 4 + 0x82910c);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        *(uint *)(local_c8 + -4) = local_c8;
        *(undefined **)(local_c8 + -8) = local_cc;
        *(undefined4 *)(local_c8 + -0xc) = 0x48e239;
        local_c4 = local_c8;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        local_d8 = 1;
        for (local_dc = 1; puVar5 = DAT_00829058, local_dc < 5; local_dc = local_dc + 1) {
          puVar10[local_d8 - iVar7] = local_cc[local_dc + -1];
          local_d8 = local_d8 + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        local_d0 = (undefined4 *)0x1;
        for (local_d4 = 1; local_d4 < 0x101; local_d4 = local_d4 + 1) {
          *(undefined4 *)((int)puVar5 + ((int)local_d0 * 4 - iVar7)) =
               *(undefined4 *)(local_d4 * 4 + local_c8 + -4);
          local_d0 = (undefined4 *)((int)local_d0 + 1);
        }
        DAT_00828fb8 = DAT_00829110;
        DAT_00828fb4 = DAT_00829114;
        _DAT_00828fb0 = f_35000;
        _DAT_00828fac = f_44000;
        FUN_005f34d1(&stack0xfffffffc,&LAB_0048e386);
        *(undefined4 *)(puVar12 + -0xbc) = 0;
        *(undefined4 *)(puVar12 + -0xd0) = 0x200;
        *(undefined4 **)(puVar12 + -0xcc) = &DAT_009ae2bc;
        *(undefined ***)(puVar12 + -200) = &DAT_00828fb8;
        FUN_005f34f0(puVar12 + -0xbc,0x784ff00,&DAT_00762c1c,puVar12 + -0xd0,&DAT_00791568);
        *(int **)(puVar12 + -200) = &DAT_00828fb4;
        FUN_005f3960(puVar12 + -0xbc,&DAT_00762c18,puVar12 + -200);
        fVar4 = _DAT_00828fb0;
        DAT_00829084._1_3_ = ((uint3)((uint)DAT_00829084 >> 8) | 0xff0000) ^ 0xfe0000;
        _DAT_0082907c = 1;
        _DAT_00829088 = 1;
        DAT_00829090 = 1;
        DAT_00829094 = 1;
        DAT_0082908c = 4;
        DAT_00829078 = &DAT_00829020;
        _DAT_00829080 = 0xffffffff;
        DAT_00829084 = CONCAT31(DAT_00829084._1_3_,1);
        DAT_00829064._1_3_ = ((uint3)((uint)DAT_00829064 >> 8) | 0xff0000) ^ 0xfc0000;
        _DAT_0082905c = 4;
        _DAT_00829068 = 1;
        DAT_00829070 = 4;
        DAT_00829074 = 1;
        DAT_0082906c = 0x100;
        DAT_00829058 = &DAT_00829110;
        _DAT_00829060 = 0xfffffffc;
        DAT_00829064 = CONCAT31(DAT_00829064._1_3_,1);
        DAT_00829020 = 0x7e;
        DAT_00829021 = 0x73;
        DAT_00829022 = 99;
        *(undefined2 *)(puVar12 + -0xc4) = in_FPUControlWord;
        *(ushort *)(puVar12 + -0xc2) = (ushort)*(undefined4 *)(puVar12 + -0xc4) | 0xc00;
        *(int *)(puVar12 + -0xc0) = (int)ROUND(fVar4);
        fVar4 = _DAT_00828fac;
        DAT_00829110 = *(undefined **)(puVar12 + -0xc0);
        *(undefined2 *)(puVar12 + -0xc4) = *(undefined2 *)(puVar12 + -0xc4);
        *(ushort *)(puVar12 + -0xc2) = (ushort)*(undefined4 *)(puVar12 + -0xc4) | 0xc00;
        *(int *)(puVar12 + -0xc0) = (int)ROUND(fVar4);
        puVar10 = DAT_00829078;
        DAT_00829114 = *(int *)(puVar12 + -0xc0);
        _DAT_00829118 = DAT_00828fb8;
        _DAT_0082911c = DAT_00828fb4;
        _DAT_00829120 = 0x14;
        _DAT_00829124 = 0x14;
        *(int *)(puVar12 + -0xd8) = DAT_00829090;
        *(int *)(puVar12 + -0xdc) = DAT_00829094;
        iVar7 = (DAT_0082908c + DAT_00829094) - *(int *)(puVar12 + -0xdc);
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        *(int *)(puVar12 + -0xe0) = iVar7;
        iVar7 = DAT_00829090 * DAT_00829094;
        puVar8 = puVar12 + -0x100;
        for (uVar6 = *(int *)(puVar12 + -0xe0) + 7U & 0xfffffff8; 0x1000 < (int)uVar6;
            uVar6 = uVar6 - 0x1000) {
          puVar8 = puVar8 + -0x1000;
        }
        iVar9 = (int)puVar8 - uVar6;
        *(int *)(puVar12 + -0xc4) = iVar9;
        *(undefined4 *)(puVar12 + -0xd0) = *(undefined4 *)(puVar12 + -0xdc);
        *(undefined4 *)(puVar12 + -0xd4) = 1;
        while (puVar5 = DAT_00829058, *(int *)(puVar12 + -0xd4) <= *(int *)(puVar12 + -0xe0)) {
          *(undefined1 *)(*(int *)(puVar12 + -0xd4) + *(int *)(puVar12 + -0xc4) + -1) =
               puVar10[*(int *)(puVar12 + -0xd0) * *(int *)(puVar12 + -0xd8) - iVar7];
          *(int *)(puVar12 + -0xd0) = *(int *)(puVar12 + -0xd0) + 1;
          *(int *)(puVar12 + -0xd4) = *(int *)(puVar12 + -0xd4) + 1;
        }
        *(int *)(puVar12 + -0xe4) = DAT_00829070;
        *(int *)(puVar12 + -0xe8) = DAT_00829074;
        iVar7 = (DAT_0082906c + DAT_00829074) - *(int *)(puVar12 + -0xe8);
        if (iVar7 < 0) {
          iVar7 = 0;
        }
        *(int *)(puVar12 + -0xec) = iVar7;
        iVar7 = DAT_00829070 * DAT_00829074;
        for (uVar6 = *(int *)(puVar12 + -0xec) * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar6;
            uVar6 = uVar6 - 0x1000) {
          iVar9 = iVar9 + -0x1000;
        }
        iVar9 = iVar9 - uVar6;
        *(int *)(puVar12 + -0xc0) = iVar9;
        *(undefined4 *)(puVar12 + -200) = *(undefined4 *)(puVar12 + -0xe8);
        *(undefined4 *)(puVar12 + -0xcc) = 1;
        while (*(int *)(puVar12 + -0xcc) <= *(int *)(puVar12 + -0xec)) {
          *(undefined4 *)(*(int *)(puVar12 + -0xcc) * 4 + *(int *)(puVar12 + -0xc0) + -4) =
               *(undefined4 *)
                ((int)puVar5 + (*(int *)(puVar12 + -200) * *(int *)(puVar12 + -0xe4) - iVar7));
          *(int *)(puVar12 + -200) = *(int *)(puVar12 + -200) + 1;
          *(int *)(puVar12 + -0xcc) = *(int *)(puVar12 + -0xcc) + 1;
        }
        *(undefined4 *)(iVar9 + -4) = *(undefined4 *)(puVar12 + -0xc0);
        *(undefined4 *)(iVar9 + -8) = *(undefined4 *)(puVar12 + -0xc4);
        *(undefined4 *)(iVar9 + -0xc) = 0x48e7a7;
        thunk_FUN_00597d30();
        puVar10 = DAT_00829078;
        iVar7 = DAT_00829090 * DAT_00829094;
        *(undefined4 *)(puVar12 + -0xd0) = *(undefined4 *)(puVar12 + -0xdc);
        *(undefined4 *)(puVar12 + -0xd4) = 1;
        while (puVar5 = DAT_00829058, *(int *)(puVar12 + -0xd4) <= *(int *)(puVar12 + -0xe0)) {
          puVar10[*(int *)(puVar12 + -0xd0) * *(int *)(puVar12 + -0xd8) - iVar7] =
               *(undefined1 *)(*(int *)(puVar12 + -0xd4) + *(int *)(puVar12 + -0xc4) + -1);
          *(int *)(puVar12 + -0xd0) = *(int *)(puVar12 + -0xd0) + 1;
          *(int *)(puVar12 + -0xd4) = *(int *)(puVar12 + -0xd4) + 1;
        }
        iVar7 = DAT_00829070 * DAT_00829074;
        *(undefined4 *)(puVar12 + -200) = *(undefined4 *)(puVar12 + -0xe8);
        *(undefined4 *)(puVar12 + -0xcc) = 1;
        while (*(int *)(puVar12 + -0xcc) <= *(int *)(puVar12 + -0xec)) {
          *(undefined4 *)
           ((int)puVar5 + (*(int *)(puVar12 + -200) * *(int *)(puVar12 + -0xe4) - iVar7)) =
               *(undefined4 *)(*(int *)(puVar12 + -0xcc) * 4 + *(int *)(puVar12 + -0xc0) + -4);
          *(int *)(puVar12 + -200) = *(int *)(puVar12 + -200) + 1;
          *(int *)(puVar12 + -0xcc) = *(int *)(puVar12 + -0xcc) + 1;
        }
        *(undefined4 *)(puVar12 + -0x14) = 0;
      }
    }
  }
  return;
}


