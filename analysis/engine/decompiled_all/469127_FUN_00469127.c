// FUN_00469127 @ 00469127 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00469276) */
/* WARNING: Removing unreachable block (ram,0x00469331) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00469127(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int iVar7;
  undefined1 *puVar8;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  
  puVar8 = &stack0xfffffffc;
  uVar2 = (uint)DAT_008246c4 >> 8;
  _DAT_008246bc = 1;
  _DAT_008246c8 = 1;
  DAT_008246d0 = 1;
  DAT_008246d4 = 1;
  DAT_008246cc = 4;
  DAT_008246b8 = &DAT_00824690;
  _DAT_008246c0 = 0xffffffff;
  DAT_008246c4 = CONCAT31(((uint3)uVar2 | 0xff0000) ^ 0xfe0000,1);
  uVar2 = (uint)DAT_008246a4 >> 8;
  _DAT_0082469c = 4;
  _DAT_008246a8 = 1;
  DAT_008246b0 = 4;
  DAT_008246b4 = 1;
  DAT_008246ac = 0x100;
  DAT_00824698 = &DAT_008246d8;
  _DAT_008246a0 = 0xfffffffc;
  DAT_008246a4 = CONCAT31(((uint3)uVar2 | 0xff0000) ^ 0xfc0000,1);
  DAT_00824691 = 0x6f;
  DAT_00824692 = 0x6c;
  DAT_00824690 = 0x7e;
  DAT_008246d8 = (int)ROUND(_DAT_0082468c);
  puVar5 = &stack0xffffff94;
  iVar4 = 8;
  bVar1 = false;
  while (bVar1) {
    puVar5 = puVar5 + -0x1000;
    iVar4 = iVar4 + -0x1000;
    bVar1 = 0x1000 < iVar4;
  }
  iVar4 = (int)puVar5 - iVar4;
  local_44 = 1;
  for (local_48 = 1; local_48 < 5; local_48 = local_48 + 1) {
    *(undefined1 *)(local_48 + iVar4 + -1) = *(undefined1 *)(local_44 + 0x82468f);
    local_44 = local_44 + 1;
  }
  iVar6 = 0x400;
  bVar1 = false;
  iVar7 = iVar4;
  while (bVar1) {
    iVar7 = iVar7 + -0x1000;
    iVar6 = iVar6 + -0x1000;
    bVar1 = 0x1000 < iVar6;
  }
  iVar7 = iVar7 - iVar6;
  local_3c = 1;
  for (local_40 = 1; local_40 < 0x101; local_40 = local_40 + 1) {
    *(int *)(local_40 * 4 + iVar7 + -4) = (&DAT_008246d4)[local_3c];
    local_3c = local_3c + 1;
  }
  *(int *)(iVar7 + -4) = iVar7;
  *(int *)(iVar7 + -8) = iVar4;
  *(undefined4 *)(iVar7 + -0xc) = 0x4693ca;
  thunk_FUN_00597d30();
  puVar5 = DAT_008246b8;
  iVar6 = DAT_008246d0 * DAT_008246d4;
  local_44 = 1;
  for (local_48 = 1; puVar3 = DAT_00824698, local_48 < 5; local_48 = local_48 + 1) {
    puVar5[local_44 - iVar6] = *(undefined1 *)(local_48 + iVar4 + -1);
    local_44 = local_44 + 1;
  }
  iVar4 = DAT_008246b0 * DAT_008246b4;
  local_3c = 1;
  for (local_40 = 1; local_40 < 0x101; local_40 = local_40 + 1) {
    *(undefined4 *)((int)puVar3 + (local_3c * 4 - iVar4)) =
         *(undefined4 *)(local_40 * 4 + iVar7 + -4);
    local_3c = local_3c + 1;
  }
  COLOR = DAT_008246d8;
  if (-1 < DAT_008246d8) {
    _DAT_0082468c = (float)DAT_008246d8;
    DAT_00824688 = DAT_008246d8 / 0x10000;
    DAT_00824684 = (DAT_008246d8 % 0x10000) / 0x100;
    _DAT_00824680 = DAT_008246d8 - (DAT_00824684 * 0x100 + DAT_00824688 * 0x10000);
    DAT_00824678 = (int)ROUND((float)DAT_00824684 / f_2_56);
    _DAT_00824674 = (int)ROUND((float)DAT_00824688 / f_2_56);
    DAT_0082467c = (int)ROUND((float)_DAT_00824680 / f_2_56) * 10000 + DAT_00824678 * 100 +
                   _DAT_00824674;
    P2 = (float)DAT_0082467c;
    FUN_005f33c9(&stack0xfffffffc,0x4695d9);
    FUN_005f34d1(puVar8,0x4695f4);
    if (DAT_020b9440 == f_16) {
      DAT_009ae2bc._1_2_ = DAT_00761c98;
    }
    *(undefined4 *)(puVar8 + -0x28) = 0;
    *(undefined4 *)(puVar8 + -0x38) = 6;
    *(undefined4 *)(puVar8 + -0x34) = 0x9ae2c2;
    *(int **)(puVar8 + -0x30) = &DAT_0082467c;
    FUN_005f34f0(puVar8 + -0x28,0x784ff00,&DAT_00761c4c,puVar8 + -0x38,&DAT_00790a1c);
  }
  return;
}


