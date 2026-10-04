// FUN_0058353a @ 0058353a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00583844) */
/* WARNING: Removing unreachable block (ram,0x0058388d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058353a(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  int local_74;
  int local_70;
  int local_6c;
  int local_3c;
  
  puVar4 = &stack0xfffffffc;
  thunk_FUN_0054cb15(&DAT_020b90a0,1,&DAT_009a90d8,&DAT_0076abe0);
  DAT_009a90d4 = 0;
  iVar1 = -DAT_009a90d8 / -1;
  for (iVar5 = DAT_009a90d8;
      (((0 < iVar1 && ((&DAT_020b909f)[iVar5] != '\\')) && ((&DAT_020b909f)[iVar5] != ' ')) &&
      ((&DAT_020b909f)[iVar5] != '=')); iVar5 = iVar5 + -1) {
    if ((DAT_009a90d4 == 0) && ((&DAT_020b909f)[iVar5] == '.')) {
      DAT_009a90d4 = iVar5;
    }
    iVar1 = iVar1 + -1;
  }
  if (DAT_009a90d4 != 0) {
    DAT_009a90d8 = DAT_009a90d4 + -1;
  }
  DAT_009a90cc = DAT_009a90d8 - iVar5;
  iVar1 = DAT_009a90cc;
  if (DAT_009a90cc < 0) {
    iVar1 = 0;
  }
  puVar6 = &stack0xffffff7c;
  for (uVar2 = iVar1 + 7U & 0xfffffff8; 0x1000 < (int)uVar2; uVar2 = uVar2 - 0x1000) {
    puVar6 = puVar6 + -0x1000;
  }
  for (local_74 = 1; local_6c = iVar5 + 1, local_74 <= iVar1; local_74 = local_74 + 1) {
    puVar6[(local_74 - uVar2) + -1] = (&DAT_020b90a0)[iVar5];
    iVar5 = local_6c;
  }
  local_70 = 1;
  for (local_74 = 1; local_74 <= iVar1; local_74 = local_74 + 1) {
    (&DAT_020b909f)[local_70] = puVar6[(local_74 - uVar2) + -1];
    local_70 = local_70 + 1;
  }
  iVar5 = DAT_009a90cc + 1;
  uVar2 = (DAT_009a90cc - iVar5) + 0x81;
  if ((int)uVar2 < 0) {
    uVar2 = 0;
  }
  uVar3 = 1;
  while( true ) {
    bVar9 = uVar3 < uVar2;
    bVar10 = uVar3 == uVar2;
    if (!bVar10 && (int)uVar2 <= (int)uVar3) break;
    (&DAT_020b909f)[iVar5] = 0x20;
    iVar5 = iVar5 + 1;
    uVar3 = uVar3 + 1;
  }
  local_3c = 0x80;
  DAT_009a90d0 = 1;
  do {
    iVar5 = 1;
    pbVar7 = &DAT_020b909f + DAT_009a90d0;
    pbVar8 = &DAT_0076abdc;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar9 = *pbVar7 < *pbVar8;
      bVar10 = *pbVar7 == *pbVar8;
      pbVar7 = pbVar7 + 1;
      pbVar8 = pbVar8 + 1;
    } while (bVar10);
    if (!bVar9) {
      iVar5 = 1;
      pbVar7 = &DAT_020b909f + DAT_009a90d0;
      pbVar8 = &DAT_0076abd8;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar9 = *pbVar7 < *pbVar8;
        bVar10 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar10);
      if (bVar9 || bVar10) {
        (&DAT_020b909f)[DAT_009a90d0] = (&DAT_020b909f)[DAT_009a90d0] + -0x20;
      }
    }
    DAT_009a90d0 = DAT_009a90d0 + 1;
    local_3c = local_3c + -1;
    bVar9 = false;
    bVar10 = local_3c == 0;
  } while (0 < local_3c);
  DAT_009a90d0 = 0xffffff9d;
  FUN_005f34d1(&stack0xfffffffc,0x583818);
  *(undefined4 *)(puVar4 + -0x34) = 0x30;
  DAT_009a90cc = 1;
  do {
    iVar5 = FUN_005f4660(0x20);
    if (iVar5 != 0) {
      *(undefined4 *)(puVar4 + -0x30) = 0;
      break;
    }
    FUN_005f46bc(puVar4,0x5838b1);
    FUN_005f34d1(puVar4,0x5838c7);
    DAT_009a90cc = DAT_009a90cc + 1;
    *(int *)(puVar4 + -0x34) = *(int *)(puVar4 + -0x34) + -1;
  } while (0 < *(int *)(puVar4 + -0x34));
  DAT_009a90d8 = DAT_009a90cc + -2;
  iVar5 = -DAT_009a90d8 / -1;
  *(int *)(puVar4 + -0x2c) = iVar5;
  while (0 < iVar5) {
    if ((&DAT_020b8e9f)[DAT_009a90d8] == '\\') {
      FUN_005f46bc(puVar4,0x58399b);
      FUN_005f34d1(puVar4,0x5839b1);
      *(undefined4 *)(puVar4 + -0x24) = 0;
      break;
    }
    *(undefined4 *)(puVar4 + -0x28) = 0;
    *(undefined4 *)(puVar4 + -0x20) = 0;
    DAT_009a90d8 = DAT_009a90d8 + -1;
    *(int *)(puVar4 + -0x2c) = *(int *)(puVar4 + -0x2c) + -1;
    iVar5 = *(int *)(puVar4 + -0x2c);
  }
  DAT_009a90d8 = DAT_009a90d4 + -2;
  iVar5 = -DAT_009a90d8 / -1;
  *(int *)(puVar4 + -0x1c) = iVar5;
  while (0 < iVar5) {
    if ((&DAT_020b909f)[DAT_009a90d8] == '\\') {
      FUN_005f46bc(puVar4,0x583a5f);
      FUN_005f34d1(puVar4,0x583a75);
      *(undefined4 *)(puVar4 + -0x14) = 0;
      break;
    }
    *(undefined4 *)(puVar4 + -0x18) = 0;
    *(undefined4 *)(puVar4 + -0x10) = 0;
    DAT_009a90d8 = DAT_009a90d8 + -1;
    *(int *)(puVar4 + -0x1c) = *(int *)(puVar4 + -0x1c) + -1;
    iVar5 = *(int *)(puVar4 + -0x1c);
  }
  if (_DAT_020b90a0 == DAT_020b8ea0) {
    iVar5 = FUN_005f4660(0x20);
    if (iVar5 == 0) {
      *(undefined4 *)(puVar4 + -8) = 0;
      goto LAB_00583b27;
    }
  }
  else {
    *(undefined4 *)(puVar4 + -0xc) = 0;
  }
  DAT_02052740 = 0;
  *(undefined4 *)(puVar4 + -0x60) = 0;
  FUN_005f7950(puVar4 + -0x60,5,0x784ff00,&DAT_0076abcc,0);
  draw_items();
LAB_00583b27:
  FUN_005f34d1(puVar4,0x583b44);
  FUN_005f34d1(puVar4,0x583b65);
  return;
}


