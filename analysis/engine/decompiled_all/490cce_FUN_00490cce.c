// FUN_00490cce @ 00490cce (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00491231) */
/* WARNING: Removing unreachable block (ram,0x00490df5) */
/* WARNING: Removing unreachable block (ram,0x00491569) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490cce(float *param_1,float *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined1 *puVar8;
  int iVar9;
  int iVar10;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  DAT_008298fc._1_3_ = ((uint3)((uint)DAT_008298fc >> 8) | 0xff0000) ^ 0xfe0000;
  _DAT_008298f4 = 1;
  _DAT_00829900 = 1;
  DAT_00829908 = 1;
  DAT_0082990c = 1;
  DAT_00829904 = 4;
  DAT_008298f0 = &DAT_008298cc;
  _DAT_008298f8 = 0xffffffff;
  DAT_008298fc = CONCAT31(DAT_008298fc._1_3_,1);
  DAT_008298dc._1_3_ = ((uint3)((uint)DAT_008298dc >> 8) | 0xff0000) ^ 0xfc0000;
  _DAT_008298d4 = 4;
  _DAT_008298e0 = 1;
  DAT_008298e8 = 4;
  DAT_008298ec = 1;
  DAT_008298e4 = 0x100;
  DAT_008298d0 = &DAT_00829910;
  _DAT_008298d8 = 0xfffffffc;
  DAT_008298dc = CONCAT31(DAT_008298dc._1_3_,1);
  DAT_008298cc = 0x7e;
  DAT_008298cd = 0x7a;
  DAT_008298ce = 0x61;
  puVar8 = &stack0xffffff9c;
  iVar5 = 8;
  bVar1 = false;
  while (bVar1) {
    puVar8 = puVar8 + -0x1000;
    iVar5 = iVar5 + -0x1000;
    bVar1 = 0x1000 < iVar5;
  }
  iVar5 = (int)puVar8 - iVar5;
  local_3c = 1;
  for (local_40 = 1; iVar4 = DAT_008298ec, iVar3 = DAT_008298e8, puVar2 = DAT_008298d0, local_40 < 5
      ; local_40 = local_40 + 1) {
    *(undefined1 *)(local_40 + iVar5 + -1) = *(undefined1 *)((int)&DAT_008298c8 + local_3c + 3);
    local_3c = local_3c + 1;
  }
  iVar9 = DAT_008298e4;
  if (DAT_008298e4 < 0) {
    iVar9 = 0;
  }
  iVar7 = DAT_008298e8 * DAT_008298ec;
  iVar10 = iVar5;
  for (uVar6 = iVar9 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar6; uVar6 = uVar6 - 0x1000) {
    iVar10 = iVar10 + -0x1000;
  }
  iVar10 = iVar10 - uVar6;
  local_34 = DAT_008298ec;
  for (local_38 = 1; local_38 <= iVar9; local_38 = local_38 + 1) {
    *(undefined4 *)(local_38 * 4 + iVar10 + -4) =
         *(undefined4 *)((int)puVar2 + (local_34 * iVar3 - iVar7));
    local_34 = local_34 + 1;
  }
  *(int *)(iVar10 + -4) = iVar10;
  *(int *)(iVar10 + -8) = iVar5;
  *(undefined4 *)(iVar10 + -0xc) = 0x490f49;
  thunk_FUN_00597d30();
  local_3c = 1;
  for (local_40 = 1; local_40 < 5; local_40 = local_40 + 1) {
    DAT_008298f0[local_3c - DAT_00829908 * DAT_0082990c] = *(undefined1 *)(local_40 + iVar5 + -1);
    local_3c = local_3c + 1;
  }
  local_34 = iVar4;
  for (local_38 = 1; local_38 <= iVar9; local_38 = local_38 + 1) {
    *(undefined4 *)((int)DAT_008298d0 + (local_34 * iVar3 - DAT_008298e8 * DAT_008298ec)) =
         *(undefined4 *)(local_38 * 4 + iVar10 + -4);
    local_34 = local_34 + 1;
  }
  DAT_008298c8 = DAT_00829910;
  DAT_008298c4 = DAT_00829914;
  DAT_008298c0 = *param_1;
  DAT_008298bc = *param_2;
  if (DAT_008298c0 == f_0) {
    DAT_008298c0 = DAT_008298b8;
  }
  if (DAT_008298bc == f_0) {
    DAT_008298bc = DAT_008298b4;
  }
  _DAT_008298b0 = *param_1;
  _DAT_008298ac = *param_2;
  DAT_008298b8 = DAT_008298c0;
  DAT_008298b4 = DAT_008298bc;
  DAT_008298fc._1_3_ = ((uint3)((uint)DAT_008298fc >> 8) | 0xff0000) ^ 0xfe0000;
  _DAT_008298f4 = 1;
  _DAT_00829900 = 1;
  DAT_00829908 = 1;
  DAT_0082990c = 1;
  DAT_00829904 = 4;
  DAT_008298f0 = &DAT_008298cc;
  _DAT_008298f8 = 0xffffffff;
  DAT_008298fc = CONCAT31(DAT_008298fc._1_3_,1);
  DAT_008298dc._1_3_ = ((uint3)((uint)DAT_008298dc >> 8) | 0xff0000) ^ 0xfc0000;
  _DAT_008298d4 = 4;
  _DAT_008298e0 = 1;
  DAT_008298e8 = 4;
  DAT_008298ec = 1;
  DAT_008298e4 = 0x100;
  DAT_008298d0 = &DAT_00829910;
  _DAT_008298d8 = 0xfffffffc;
  DAT_008298dc = CONCAT31(DAT_008298dc._1_3_,1);
  DAT_008298cc = 0x7e;
  DAT_008298cd = 0x73;
  DAT_008298ce = 99;
  _DAT_00829918 = DAT_00829910;
  _DAT_0082991c = DAT_00829914;
  _DAT_00829920 = 200;
  _DAT_00829924 = 200;
  puVar8 = &stack0xffffff9c;
  iVar5 = 8;
  bVar1 = false;
  while (bVar1) {
    puVar8 = puVar8 + -0x1000;
    iVar5 = iVar5 + -0x1000;
    bVar1 = 0x1000 < iVar5;
  }
  iVar5 = (int)puVar8 - iVar5;
  local_38 = 1;
  DAT_00829910 = (int)ROUND(_DAT_008298b0);
  DAT_00829914 = (int)ROUND(_DAT_008298ac);
  for (local_3c = 1; iVar4 = DAT_008298ec, iVar3 = DAT_008298e8, puVar2 = DAT_008298d0, local_3c < 5
      ; local_3c = local_3c + 1) {
    *(undefined1 *)(local_3c + iVar5 + -1) = *(undefined1 *)((int)&DAT_008298c8 + local_38 + 3);
    local_38 = local_38 + 1;
  }
  iVar9 = DAT_008298e4;
  if (DAT_008298e4 < 0) {
    iVar9 = 0;
  }
  iVar7 = DAT_008298e8 * DAT_008298ec;
  iVar10 = iVar5;
  for (uVar6 = iVar9 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar6; uVar6 = uVar6 - 0x1000) {
    iVar10 = iVar10 + -0x1000;
  }
  iVar10 = iVar10 - uVar6;
  local_30 = DAT_008298ec;
  for (local_34 = 1; local_34 <= iVar9; local_34 = local_34 + 1) {
    *(undefined4 *)(local_34 * 4 + iVar10 + -4) =
         *(undefined4 *)((int)puVar2 + (local_30 * iVar3 - iVar7));
    local_30 = local_30 + 1;
  }
  *(int *)(iVar10 + -4) = iVar10;
  *(int *)(iVar10 + -8) = iVar5;
  *(undefined4 *)(iVar10 + -0xc) = 0x491385;
  thunk_FUN_00597d30();
  local_38 = 1;
  for (local_3c = 1; local_3c < 5; local_3c = local_3c + 1) {
    DAT_008298f0[local_38 - DAT_00829908 * DAT_0082990c] = *(undefined1 *)(local_3c + iVar5 + -1);
    local_38 = local_38 + 1;
  }
  local_30 = iVar4;
  for (local_34 = 1; local_34 <= iVar9; local_34 = local_34 + 1) {
    *(undefined4 *)((int)DAT_008298d0 + (local_30 * iVar3 - DAT_008298e8 * DAT_008298ec)) =
         *(undefined4 *)(local_34 * 4 + iVar10 + -4);
    local_30 = local_30 + 1;
  }
  DAT_008298fc._1_3_ = ((uint3)((uint)DAT_008298fc >> 8) | 0xff0000) ^ 0xfe0000;
  _DAT_008298f4 = 1;
  _DAT_00829900 = 1;
  DAT_00829908 = 1;
  DAT_0082990c = 1;
  DAT_00829904 = 4;
  DAT_008298f0 = &DAT_008298cc;
  _DAT_008298f8 = 0xffffffff;
  DAT_008298fc = CONCAT31(DAT_008298fc._1_3_,1);
  DAT_008298dc._1_3_ = ((uint3)((uint)DAT_008298dc >> 8) | 0xff0000) ^ 0xfc0000;
  _DAT_008298d4 = 4;
  _DAT_008298e0 = 1;
  DAT_008298e8 = 4;
  DAT_008298ec = 1;
  DAT_008298e4 = 0x100;
  DAT_008298d0 = &DAT_00829910;
  _DAT_008298d8 = 0xfffffffc;
  DAT_008298dc = CONCAT31(DAT_008298dc._1_3_,1);
  DAT_008298cc = 0x7e;
  DAT_008298cd = 0x70;
  DAT_008298ce = 0x6f;
  DAT_00829910 = 0xfffff6a0;
  DAT_00829914 = 10000;
  puVar8 = &stack0xffffff9c;
  iVar5 = 8;
  bVar1 = false;
  while (bVar1) {
    puVar8 = puVar8 + -0x1000;
    iVar5 = iVar5 + -0x1000;
    bVar1 = 0x1000 < iVar5;
  }
  iVar5 = (int)puVar8 - iVar5;
  local_38 = 1;
  for (local_3c = 1; iVar4 = DAT_008298ec, iVar3 = DAT_008298e8, puVar2 = DAT_008298d0, local_3c < 5
      ; local_3c = local_3c + 1) {
    *(undefined1 *)(local_3c + iVar5 + -1) = *(undefined1 *)((int)&DAT_008298c8 + local_38 + 3);
    local_38 = local_38 + 1;
  }
  iVar9 = DAT_008298e4;
  if (DAT_008298e4 < 0) {
    iVar9 = 0;
  }
  iVar7 = DAT_008298e8 * DAT_008298ec;
  iVar10 = iVar5;
  for (uVar6 = iVar9 * 4 + 7U & 0xfffffff8; 0x1000 < (int)uVar6; uVar6 = uVar6 - 0x1000) {
    iVar10 = iVar10 + -0x1000;
  }
  iVar10 = iVar10 - uVar6;
  local_30 = DAT_008298ec;
  for (local_34 = 1; local_34 <= iVar9; local_34 = local_34 + 1) {
    *(undefined4 *)(local_34 * 4 + iVar10 + -4) =
         *(undefined4 *)((int)puVar2 + (local_30 * iVar3 - iVar7));
    local_30 = local_30 + 1;
  }
  *(int *)(iVar10 + -4) = iVar10;
  *(int *)(iVar10 + -8) = iVar5;
  *(undefined4 *)(iVar10 + -0xc) = 0x4916bf;
  thunk_FUN_00597d30();
  puVar8 = DAT_008298f0;
  iVar7 = DAT_00829908 * DAT_0082990c;
  local_38 = 1;
  for (local_3c = 1; puVar2 = DAT_008298d0, local_3c < 5; local_3c = local_3c + 1) {
    puVar8[local_38 - iVar7] = *(undefined1 *)(local_3c + iVar5 + -1);
    local_38 = local_38 + 1;
  }
  iVar5 = DAT_008298e8 * DAT_008298ec;
  local_30 = iVar4;
  for (local_34 = 1; local_34 <= iVar9; local_34 = local_34 + 1) {
    *(undefined4 *)((int)puVar2 + (local_30 * iVar3 - iVar5)) =
         *(undefined4 *)(local_34 * 4 + iVar10 + -4);
    local_30 = local_30 + 1;
  }
  return;
}


