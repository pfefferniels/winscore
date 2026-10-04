// FUN_00579770 @ 00579770 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0057edac) */
/* WARNING: Removing unreachable block (ram,0x00579ed5) */
/* WARNING: Removing unreachable block (ram,0x00579fcd) */
/* WARNING: Removing unreachable block (ram,0x0057a7b1) */
/* WARNING: Removing unreachable block (ram,0x0057a6b9) */
/* WARNING: Removing unreachable block (ram,0x0057bff4) */
/* WARNING: Removing unreachable block (ram,0x0057c0ec) */
/* WARNING: Removing unreachable block (ram,0x0057c7fc) */
/* WARNING: Removing unreachable block (ram,0x0057c8f4) */
/* WARNING: Removing unreachable block (ram,0x0057dd85) */
/* WARNING: Removing unreachable block (ram,0x0057de7b) */
/* WARNING: Removing unreachable block (ram,0x0057e67f) */
/* WARNING: Removing unreachable block (ram,0x0057e587) */
/* WARNING: Removing unreachable block (ram,0x0057d126) */
/* WARNING: Removing unreachable block (ram,0x0057d02e) */
/* WARNING: Removing unreachable block (ram,0x0057c4f0) */
/* WARNING: Removing unreachable block (ram,0x0057c3f8) */
/* WARNING: Removing unreachable block (ram,0x0057af75) */
/* WARNING: Removing unreachable block (ram,0x0057b06d) */
/* WARNING: Removing unreachable block (ram,0x0057a3b8) */
/* WARNING: Removing unreachable block (ram,0x0057a2c0) */
/* WARNING: Removing unreachable block (ram,0x00579aca) */
/* WARNING: Removing unreachable block (ram,0x00579bc2) */
/* WARNING: Removing unreachable block (ram,0x0057eea4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00579770(char *param_1,undefined4 param_2,int *param_3)

{
  bool bVar1;
  uint3 uVar2;
  uint3 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined1 *puVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  
  uVar2 = (uint3)((uint)DAT_009a8f1c >> 8);
  uVar3 = (uint3)((uint)DAT_009a8efc >> 8);
  if (*param_1 == 'b') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee5 = 0x62;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57ef74;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
    _DAT_00790b84 =
         *(undefined4 *)((int)DAT_009a8ef0 + (DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
    _DAT_00790b88 =
         *(undefined4 *)((int)DAT_009a8ef0 + (DAT_009a8f08 * 2 - DAT_009a8f08 * DAT_009a8f0c));
  }
  else if (*param_1 == 'c') {
    DAT_009a8ee0 = DAT_009a8ee0 + 1;
    if (0x12 < DAT_009a8ee0) {
      DAT_009a8ee0 = 0;
    }
    if (IP1 != 0) {
      DAT_009a8ee0 = IP1;
    }
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 99;
    DAT_009a8ee6 = 0x75;
    *param_3 = DAT_009a8ee0;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57eb86;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 's') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x73;
    DAT_009a8ee6 = 99;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57e74f;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'f') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x66;
    DAT_009a8ee6 = 0x6f;
    *param_3 = 0;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57e34b;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
    _DAT_009a8edc = *param_3;
  }
  else if (*param_1 == 'p') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x70;
    DAT_009a8ee6 = 0x6f;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57df4b;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'o') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x6f;
    DAT_009a8ee6 = 0x6c;
    DAT_009a8ed8 = 1;
    DAT_009a8ed4 = 0x100;
    _DAT_009a8ed0 = 0x10000;
    _DAT_009a8ecc = 0x80;
    DAT_009a8ec8 = 0;
    DAT_009a8ec4 = 0x800000;
    _DAT_009a8ec0 = 0x4b000080;
    *param_3 = (int)&DAT_00800080;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57daf1;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
    DAT_009a8ebc = *param_3;
    DAT_009a8ec4 = DAT_009a8ebc / 0x10000;
    DAT_009a8ec8 = (DAT_009a8ebc % 0x10000) / 0x100;
    _DAT_009a8ecc = DAT_009a8ebc - (DAT_009a8ec4 * 0x10000 + DAT_009a8ec8 * 0x100);
  }
  else if (*param_1 == 'v') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x76;
    DAT_009a8ee6 = 0x65;
    _DAT_009a8edc = 99;
    DAT_009a8eec = 0x3a;
    DAT_009a8ee8 = 0x6d;
    *param_3 = (int)&DAT_006d3a63;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57d62f;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'n') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x6e;
    DAT_009a8ee6 = 0x61;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57d1f6;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'h') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x68;
    DAT_009a8ee6 = 0x70;
    _DAT_009a8edc = 99;
    DAT_009a8eec = 0x3a;
    DAT_009a8ee8 = 0x6d;
    *param_3 = (int)&DAT_006d3a63;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57cdfd;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'm') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x6d;
    DAT_009a8ee6 = 0x6f;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57c9c4;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'i') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x69;
    DAT_009a8ee6 = 0x6d;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57c5c0;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
    _DAT_009a8edc = *param_3;
  }
  else if (*param_1 == 'd') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 100;
    DAT_009a8ee6 = 0x69;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57c1bc;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
    _DAT_009a8edc = *param_3;
  }
  else if (*param_1 == 'a') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x61;
    DAT_009a8ee6 = 0x73;
    _DAT_009a8edc = 99;
    DAT_009a8eec = 0x3a;
    DAT_009a8ee8 = 0x6d;
    *param_3 = (int)&DAT_006d3a63;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57bdc3;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'r') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x72;
    DAT_009a8ee6 = 0x69;
    *param_3 = 0;
    param_3[1] = 0;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57b98a;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'l') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x6c;
    DAT_009a8ee6 = 0x61;
    *param_3 = 0;
    param_3[1] = 0;
    _DAT_009a8edc = 0x61;
    DAT_009a8eec = 0x62;
    DAT_009a8ee8 = 99;
    param_3[2] = 0x636261;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57b586;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'z') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x7a;
    DAT_009a8ee6 = 0x61;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57b13d;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == '0') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x7a;
    DAT_009a8ee6 = 0x61;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57a881;
    thunk_FUN_00597d30();
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      DAT_009a8f10[local_cc - DAT_009a8f28 * DAT_009a8f2c] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)DAT_009a8ef0 + (local_c4 * 4 - DAT_009a8f08 * DAT_009a8f0c)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
    DAT_009a8eb8 = *param_3;
    DAT_009a8eb4 = param_3[1];
    _DAT_009a8eb0 = P1;
    _DAT_009a8eac = P2;
    DAT_009a8f1c._1_3_ = ((uint3)((uint)DAT_009a8f1c >> 8) | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = ((uint3)((uint)DAT_009a8efc >> 8) | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x73;
    DAT_009a8ee6 = 99;
    *param_3 = (int)ROUND(P1);
    param_3[1] = (int)ROUND(_DAT_009a8eac);
    param_3[2] = DAT_009a8eb8;
    param_3[3] = DAT_009a8eb4;
    param_3[4] = 0x14;
    param_3[5] = 0x14;
    iVar5 = DAT_009a8f2c;
    iVar7 = DAT_009a8f28;
    iVar12 = DAT_009a8f0c;
    iVar6 = DAT_009a8f08;
    iVar8 = DAT_009a8f24;
    if (DAT_009a8f24 < 0) {
      iVar8 = 0;
    }
    puVar11 = &stack0xffffff0c;
    for (uVar9 = iVar8 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      puVar11 = puVar11 + -0x1000;
    }
    iVar13 = (int)puVar11 - uVar9;
    local_cc = DAT_009a8f2c;
    for (local_d0 = 1; local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar13 + -1) =
           DAT_009a8f10[local_cc * DAT_009a8f28 - DAT_009a8f28 * DAT_009a8f2c];
      local_cc = local_cc + 1;
    }
    iVar10 = DAT_009a8f04;
    if (DAT_009a8f04 < 0) {
      iVar10 = 0;
    }
    iVar14 = iVar13;
    for (uVar9 = iVar10 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar9; uVar9 = uVar9 - 0x1000) {
      iVar14 = iVar14 + -0x1000;
    }
    iVar14 = iVar14 - uVar9;
    local_c4 = DAT_009a8f0c;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)(local_c8 * 4 + iVar14 + -4) =
           *(undefined4 *)
            ((int)DAT_009a8ef0 + (local_c4 * DAT_009a8f08 - DAT_009a8f08 * DAT_009a8f0c));
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar14 + -4) = iVar14;
    *(int *)(iVar14 + -8) = iVar13;
    *(undefined4 *)(iVar14 + -0xc) = 0x57ad44;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar15 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = iVar5;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 <= iVar8; local_d0 = local_d0 + 1) {
      puVar11[local_cc * iVar7 - iVar15] = *(undefined1 *)(local_d0 + iVar13 + -1);
      local_cc = local_cc + 1;
    }
    iVar7 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = iVar12;
    for (local_c8 = 1; local_c8 <= iVar10; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * iVar6 - iVar7)) =
           *(undefined4 *)(local_c8 * 4 + iVar14 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'g') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x67;
    DAT_009a8ee6 = 0x6f;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57a488;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'e') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x65;
    DAT_009a8ee6 = 0x65;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x579c92;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  else if (*param_1 == 'k') {
    DAT_009a8f1c._1_3_ = (uVar2 | 0xff0000) ^ 0xfe0000;
    _DAT_009a8f14 = 1;
    _DAT_009a8f20 = 1;
    DAT_009a8f28 = 1;
    DAT_009a8f2c = 1;
    DAT_009a8f24 = 4;
    DAT_009a8f10 = &DAT_009a8ee4;
    _DAT_009a8f18 = 0xffffffff;
    DAT_009a8f1c = CONCAT31(DAT_009a8f1c._1_3_,1);
    DAT_009a8efc._1_3_ = (uVar3 | 0xff0000) ^ 0xfc0000;
    _DAT_009a8ef4 = 4;
    _DAT_009a8f00 = 1;
    DAT_009a8f08 = 4;
    DAT_009a8f0c = 1;
    DAT_009a8f04 = 0x100;
    DAT_009a8ef0 = param_3;
    _DAT_009a8ef8 = 0xfffffffc;
    DAT_009a8efc = CONCAT31(DAT_009a8efc._1_3_,1);
    DAT_009a8ee4 = 0x7e;
    DAT_009a8ee5 = 0x6b;
    DAT_009a8ee6 = 0x6b;
    puVar11 = &stack0xffffff0c;
    iVar6 = 8;
    bVar1 = false;
    while (bVar1) {
      puVar11 = puVar11 + -0x1000;
      iVar6 = iVar6 + -0x1000;
      bVar1 = 0x1000 < iVar6;
    }
    iVar6 = (int)puVar11 - iVar6;
    local_cc = 1;
    for (local_d0 = 1; local_d0 < 5; local_d0 = local_d0 + 1) {
      *(undefined1 *)(local_d0 + iVar6 + -1) = *(undefined1 *)((int)&DAT_009a8ee0 + local_cc + 3);
      local_cc = local_cc + 1;
    }
    iVar7 = 0x400;
    bVar1 = false;
    iVar12 = iVar6;
    while (bVar1) {
      iVar12 = iVar12 + -0x1000;
      iVar7 = iVar7 + -0x1000;
      bVar1 = 0x1000 < iVar7;
    }
    iVar12 = iVar12 - iVar7;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(int *)(local_c8 * 4 + iVar12 + -4) = param_3[local_c4 + -1];
      local_c4 = local_c4 + 1;
    }
    *(int *)(iVar12 + -4) = iVar12;
    *(int *)(iVar12 + -8) = iVar6;
    *(undefined4 *)(iVar12 + -0xc) = 0x57a09d;
    thunk_FUN_00597d30();
    puVar11 = DAT_009a8f10;
    iVar7 = DAT_009a8f28 * DAT_009a8f2c;
    local_cc = 1;
    for (local_d0 = 1; piVar4 = DAT_009a8ef0, local_d0 < 5; local_d0 = local_d0 + 1) {
      puVar11[local_cc - iVar7] = *(undefined1 *)(local_d0 + iVar6 + -1);
      local_cc = local_cc + 1;
    }
    iVar6 = DAT_009a8f08 * DAT_009a8f0c;
    local_c4 = 1;
    for (local_c8 = 1; local_c8 < 0x101; local_c8 = local_c8 + 1) {
      *(undefined4 *)((int)piVar4 + (local_c4 * 4 - iVar6)) =
           *(undefined4 *)(local_c8 * 4 + iVar12 + -4);
      local_c4 = local_c4 + 1;
    }
  }
  return;
}


